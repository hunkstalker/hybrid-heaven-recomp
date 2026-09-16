#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M8_FUN_801c3b88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3B88: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C3B8C: jr          $ra
    // 0x801C3B90: lw          $v0, -0x4268($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4268);
    return;
    // 0x801C3B90: lw          $v0, -0x4268($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4268);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3b94(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3b94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3B94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C3B98: jr          $ra
    // 0x801C3B9C: sw          $a0, -0x4264($at)
    MEM_W(-0X4264, ctx->r1) = ctx->r4;
    return;
    // 0x801C3B9C: sw          $a0, -0x4264($at)
    MEM_W(-0X4264, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3ba0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3ba0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3BA0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C3BA4: jr          $ra
    // 0x801C3BA8: lw          $v0, -0x4264($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4264);
    return;
    // 0x801C3BA8: lw          $v0, -0x4264($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4264);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3bac(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3bac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3BAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C3BB0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C3BB4: jr          $ra
    // 0x801C3BB8: sh          $a0, -0x425E($at)
    MEM_H(-0X425E, ctx->r1) = ctx->r4;
    return;
    // 0x801C3BB8: sh          $a0, -0x425E($at)
    MEM_H(-0X425E, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3bbc(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3bbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3BBC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C3BC0: jr          $ra
    // 0x801C3BC4: lhu         $v0, -0x425E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X425E);
    return;
    // 0x801C3BC4: lhu         $v0, -0x425E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X425E);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3bc8(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3bc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3BC8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C3BCC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C3BD0: lw          $t6, 0x1E4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1E4);
    // 0x801C3BD4: bne         $t6, $zero, L_801C3BE8
    if (ctx->r14 != 0) {
        // 0x801C3BD8: nop
    
            goto L_801C3BE8;
    }
    // 0x801C3BD8: nop

    // 0x801C3BDC: lw          $t7, 0xDC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XDC);
    // 0x801C3BE0: lw          $t8, 0x54($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X54);
    // 0x801C3BE4: sw          $t8, 0x1E4($v0)
    MEM_W(0X1E4, ctx->r2) = ctx->r24;
L_801C3BE8:
    // 0x801C3BE8: jr          $ra
    // 0x801C3BEC: nop

    return;
    // 0x801C3BEC: nop

;}
RECOMP_FUNC void M8_FUN_801c3bf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3BF0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C3BF4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C3BF8: lw          $v0, 0x1E4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1E4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3bfc(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3bfc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3BFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C3C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3C04: beql        $v0, $zero, L_801C3C30
    if (ctx->r2 == 0) {
        // 0x801C3C08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C3C30;
    }
    goto skip_0;
    // 0x801C3C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801C3C0C: lw          $t6, 0xDC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XDC);
    // 0x801C3C10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C3C14: sw          $v0, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->r2;
    // 0x801C3C18: jal         0x801C4A5C
    // 0x801C3C1C: lw          $a0, 0xDC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XDC);
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_0;
    // 0x801C3C1C: lw          $a0, 0xDC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XDC);
    after_0:
    // 0x801C3C20: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C3C24: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C3C28: sw          $zero, 0x1E4($v1)
    MEM_W(0X1E4, ctx->r3) = 0;
    // 0x801C3C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C3C30:
    // 0x801C3C30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3C34: jr          $ra
    // 0x801C3C38: nop

    return;
    // 0x801C3C38: nop

;}
RECOMP_FUNC void M8_FUN_801c3c3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3C3C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C3C40: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C3C44: lw          $t6, 0x1E4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1E4);
    // 0x801C3C48: beq         $t6, $zero, L_801C3C58
    if (ctx->r14 == 0) {
        // 0x801C3C4C: nop
    
            goto L_801C3C58;
    }
    // 0x801C3C4C: nop

    // 0x801C3C50: lw          $t7, 0xDC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XDC);
    // 0x801C3C54: sw          $a0, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->r4;
L_801C3C58:
    // 0x801C3C58: jr          $ra
    // 0x801C3C5C: nop

    return;
    // 0x801C3C5C: nop

;}
RECOMP_FUNC void M8_FUN_801c3c60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3C60: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C3C64: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C3C68: lwc1        $f2, 0x438($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X438);
    // 0x801C3C6C: lwc1        $f14, 0x43C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X43C);
    // 0x801C3C70: lwc1        $f16, 0x440($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X440);
    // 0x801C3C74: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3c78(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3c78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3C78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C3C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3C80: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C3C84: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C3C88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C3C8C: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801C3C90: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801C3C94: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x801C3C98: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801C3C9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801C3CA0: jal         0x8002FC20
    // 0x801C3CA4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x801C3CA4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x801C3CA8: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C3CAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801C3CB0: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C3CB4: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x801C3CB8: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C3CBC: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C3CC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C3CC4: bc1f        L_801C3D10
    if (!c1cs) {
        // 0x801C3CC8: nop
    
            goto L_801C3D10;
    }
    // 0x801C3CC8: nop

    // 0x801C3CCC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C3CD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C3CD4: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801C3CD8: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C3CDC: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x801C3CE0: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x801C3CE4: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801C3CE8: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801C3CEC: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C3CF0: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x801C3CF4: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x801C3CF8: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x801C3CFC: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801C3D00: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C3D04: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x801C3D08: b           L_801C3D10
    // 0x801C3D0C: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
        goto L_801C3D10;
    // 0x801C3D0C: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
L_801C3D10:
    // 0x801C3D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3D14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C3D18: jr          $ra
    // 0x801C3D1C: nop

    return;
    // 0x801C3D1C: nop

;}
RECOMP_FUNC void M8_FUN_801c3d20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C3D24: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801C3D28: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x801C3D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3D30: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C3D34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C3D38: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C3D3C: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C3D40: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801C3D44: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801C3D48: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C3D4C: sub.s       $f2, $f8, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x801C3D50: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C3D54: nop

    // 0x801C3D58: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C3D5C: jal         0x8002FC20
    // 0x801C3D60: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x801C3D60: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_0:
    // 0x801C3D64: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C3D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C3D70: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x801C3D74: nop

    // 0x801C3D78: bc1f        L_801C3D88
    if (!c1cs) {
        // 0x801C3D7C: nop
    
            goto L_801C3D88;
    }
    // 0x801C3D7C: nop

    // 0x801C3D80: b           L_801C3D88
    // 0x801C3D84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C3D88;
    // 0x801C3D84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C3D88:
    // 0x801C3D88: jr          $ra
    // 0x801C3D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801C3D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c3d90(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c3d90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3D90: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C3D94: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C3D98: lw          $t6, 0xE0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE0);
    // 0x801C3D9C: beql        $t6, $zero, L_801C3DC0
    if (ctx->r14 == 0) {
        // 0x801C3DA0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C3DC0;
    }
    goto skip_0;
    // 0x801C3DA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801C3DA4: lw          $t7, 0xDC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XDC);
    // 0x801C3DA8: lbu         $t8, 0x63($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X63);
    // 0x801C3DAC: beql        $t8, $zero, L_801C3DC0
    if (ctx->r24 == 0) {
        // 0x801C3DB0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C3DC0;
    }
    goto skip_1;
    // 0x801C3DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801C3DB4: jr          $ra
    // 0x801C3DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C3DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C3DBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C3DC0:
    // 0x801C3DC0: jr          $ra
    // 0x801C3DC4: nop

    return;
    // 0x801C3DC4: nop

;}
RECOMP_FUNC void M8_FUN_801c3dc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3DC8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801C3DCC: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x801C3DD0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801C3DD4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801C3DD8: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x801C3DDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C3DE0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801C3DE4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x801C3DE8: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x801C3DEC: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x801C3DF0: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x801C3DF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C3DF8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x801C3DFC: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801C3E00: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801C3E04: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801C3E08: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C3E0C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C3E10: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801C3E14: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801C3E18: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801C3E1C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C3E20: addiu       $a0, $a0, 0x2B3C
    ctx->r4 = ADD32(ctx->r4, 0X2B3C);
    // 0x801C3E24: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801C3E28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C3E2C: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x801C3E30: addiu       $a1, $zero, 0x18C
    ctx->r5 = ADD32(0, 0X18C);
    // 0x801C3E34: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x801C3E38: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801C3E3C: lwc1        $f2, 0x34($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C3E40: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x801C3E44: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801C3E48: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801C3E4C: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x801C3E50: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801C3E54: lwc1        $f14, 0x38($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801C3E58: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x801C3E5C: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x801C3E60: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801C3E64: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801C3E68: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x801C3E6C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801C3E70: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C3E74: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x801C3E78: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801C3E7C: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801C3E80: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x801C3E84: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801C3E88: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C3E8C: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x801C3E90: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801C3E94: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801C3E98: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801C3E9C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x801C3EA0: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C3EA4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801C3EA8: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801C3EAC: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x801C3EB0: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801C3EB4: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x801C3EB8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C3EBC: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x801C3EC0: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801C3EC4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801C3EC8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801C3ECC: jal         0x8011AAF4
    // 0x801C3ED0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x801C3ED0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801C3ED4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801C3ED8: lw          $t0, -0x4328($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4328);
    // 0x801C3EDC: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801C3EE0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801C3EE4: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801C3EE8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801C3EEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C3EF0: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C3EF4: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801C3EF8: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801C3EFC: sub.s       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x801C3F00: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801C3F04: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801C3F08: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C3F0C: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x801C3F10: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x801C3F14: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x801C3F18: nop

    // 0x801C3F1C: bnel        $t2, $zero, L_801C4044
    if (ctx->r10 != 0) {
        // 0x801C3F20: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801C4044;
    }
    goto skip_0;
    // 0x801C3F20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801C3F24: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C3F28: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x801C3F2C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801C3F30: mul.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x801C3F34: trunc.w.d   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x801C3F38: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x801C3F3C: nop

    // 0x801C3F40: bnel        $t4, $zero, L_801C4044
    if (ctx->r12 != 0) {
        // 0x801C3F44: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801C4044;
    }
    goto skip_1;
    // 0x801C3F44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x801C3F48: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801C3F4C: sub.s       $f10, $f14, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x801C3F50: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C3F54: mul.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x801C3F58: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x801C3F5C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x801C3F60: nop

    // 0x801C3F64: bnel        $t6, $zero, L_801C4044
    if (ctx->r14 != 0) {
        // 0x801C3F68: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801C4044;
    }
    goto skip_2;
    // 0x801C3F68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x801C3F6C: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C3F70: sub.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x801C3F74: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801C3F78: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x801C3F7C: trunc.w.d   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x801C3F80: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x801C3F84: nop

    // 0x801C3F88: bnel        $t8, $zero, L_801C4044
    if (ctx->r24 != 0) {
        // 0x801C3F8C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801C4044;
    }
    goto skip_3;
    // 0x801C3F8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x801C3F90: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C3F94: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x801C3F98: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C3F9C: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801C3FA0: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x801C3FA4: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x801C3FA8: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x801C3FAC: nop

    // 0x801C3FB0: bnel        $t0, $zero, L_801C4044
    if (ctx->r8 != 0) {
        // 0x801C3FB4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801C4044;
    }
    goto skip_4;
    // 0x801C3FB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x801C3FB8: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C3FBC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C3FC0: addiu       $a0, $a0, 0x2B80
    ctx->r4 = ADD32(ctx->r4, 0X2B80);
    // 0x801C3FC4: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C3FC8: addiu       $a1, $zero, 0x194
    ctx->r5 = ADD32(0, 0X194);
    // 0x801C3FCC: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x801C3FD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C3FD4: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C3FD8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C3FDC: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x801C3FE0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801C3FE4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801C3FE8: trunc.w.d   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x801C3FEC: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x801C3FF0: nop

    // 0x801C3FF4: bnel        $t2, $zero, L_801C4044
    if (ctx->r10 != 0) {
        // 0x801C3FF8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801C4044;
    }
    goto skip_5;
    // 0x801C3FF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_5:
    // 0x801C3FFC: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801C4000: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801C4004: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x801C4008: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x801C400C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x801C4010: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x801C4014: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x801C4018: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801C401C: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x801C4020: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x801C4024: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x801C4028: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x801C402C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x801C4030: jal         0x8011AAF4
    // 0x801C4034: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x801C4034: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x801C4038: b           L_801C4044
    // 0x801C403C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C4044;
    // 0x801C403C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C4040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C4044:
    // 0x801C4044: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801C4048: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x801C404C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801C4050: jr          $ra
    // 0x801C4054: nop

    return;
    // 0x801C4054: nop

;}
RECOMP_FUNC void M8_FUN_801c4058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4058: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801C405C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801C4060: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x801C4064: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801C4068: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x801C406C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x801C4070: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x801C4074: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x801C4078: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C407C: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C4080: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C4084: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801C4088: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C408C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C4090: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C4094: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x801C4098: jal         0x8001EF38
    // 0x801C409C: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801C409C: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x801C40A0: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801C40A4: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801C40A8: lh          $t7, 0x86($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X86);
    // 0x801C40AC: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C40B0: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x801C40B4: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C40B8: andi        $t1, $t0, 0x1FFF
    ctx->r9 = ctx->r8 & 0X1FFF;
    // 0x801C40BC: sh          $t1, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r9;
    // 0x801C40C0: jal         0x8002FC20
    // 0x801C40C4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x801C40C4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_1:
    // 0x801C40C8: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801C40CC: lh          $a0, 0x76($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X76);
    // 0x801C40D0: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x801C40D4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801C40D8: jal         0x8001EAD0
    // 0x801C40DC: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x801C40DC: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801C40E0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x801C40E4: jal         0x8001EB64
    // 0x801C40E8: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801C40E8: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x801C40EC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801C40F0: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801C40F4: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801C40F8: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801C40FC: lw          $t3, -0x4328($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4328);
    // 0x801C4100: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C4104: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801C4108: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C410C: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801C4110: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801C4114: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801C4118: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801C411C: lwc1        $f2, 0x3C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C4120: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C4124: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801C4128: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x801C412C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801C4130: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801C4134: addiu       $a0, $a0, 0x2BC4
    ctx->r4 = ADD32(ctx->r4, 0X2BC4);
    // 0x801C4138: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801C413C: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C4140: addiu       $a1, $zero, 0x1B6
    ctx->r5 = ADD32(0, 0X1B6);
    // 0x801C4144: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x801C4148: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801C414C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C4150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C4154: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801C4158: lwc1        $f12, 0x44($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C415C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801C4160: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x801C4164: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x801C4168: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801C416C: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C4170: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x801C4174: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x801C4178: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x801C417C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801C4180: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801C4184: jal         0x8011AAF4
    // 0x801C4188: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_4;
    // 0x801C4188: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801C418C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801C4190: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x801C4194: jr          $ra
    // 0x801C4198: nop

    return;
    // 0x801C4198: nop

;}
RECOMP_FUNC void M8_FUN_801c419c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C419C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801C41A0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801C41A4: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x801C41A8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801C41AC: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x801C41B0: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x801C41B4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x801C41B8: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x801C41BC: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C41C0: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C41C4: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C41C8: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801C41CC: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C41D0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C41D4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C41D8: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x801C41DC: jal         0x8001EF38
    // 0x801C41E0: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801C41E0: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x801C41E4: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801C41E8: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801C41EC: lh          $t7, 0x86($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X86);
    // 0x801C41F0: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C41F4: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x801C41F8: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C41FC: andi        $t1, $t0, 0x1FFF
    ctx->r9 = ctx->r8 & 0X1FFF;
    // 0x801C4200: sh          $t1, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r9;
    // 0x801C4204: jal         0x8002FC20
    // 0x801C4208: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x801C4208: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_1:
    // 0x801C420C: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801C4210: lh          $a0, 0x76($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X76);
    // 0x801C4214: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x801C4218: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801C421C: jal         0x8001EAD0
    // 0x801C4220: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x801C4220: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801C4224: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x801C4228: jal         0x8001EB64
    // 0x801C422C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801C422C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x801C4230: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801C4234: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801C4238: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801C423C: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801C4240: lw          $t3, -0x4328($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4328);
    // 0x801C4244: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C4248: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801C424C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C4250: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801C4254: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801C4258: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801C425C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C4260: lwc1        $f2, 0x3C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C4264: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801C4268: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801C426C: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x801C4270: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801C4274: addiu       $a0, $a0, 0x2C08
    ctx->r4 = ADD32(ctx->r4, 0X2C08);
    // 0x801C4278: addiu       $a1, $zero, 0x1D5
    ctx->r5 = ADD32(0, 0X1D5);
    // 0x801C427C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801C4280: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C4284: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x801C4288: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C428C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801C4290: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801C4294: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801C4298: lwc1        $f12, 0x44($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C429C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801C42A0: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x801C42A4: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x801C42A8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801C42AC: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C42B0: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x801C42B4: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x801C42B8: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x801C42BC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801C42C0: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801C42C4: jal         0x8011AAF4
    // 0x801C42C8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_4;
    // 0x801C42C8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801C42CC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801C42D0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x801C42D4: jr          $ra
    // 0x801C42D8: nop

    return;
    // 0x801C42D8: nop

;}
RECOMP_FUNC void M8_FUN_801c42dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C42DC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801C42E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C42E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C42E8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x801C42EC: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801C42F0: lbu         $s1, 0xAF($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0XAF);
    // 0x801C42F4: lbu         $a1, 0x5B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X5B);
    // 0x801C42F8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801C42FC: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801C4300: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C4304: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x801C4308: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x801C430C: lbu         $a0, 0xF20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF20);
    // 0x801C4310: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C4314: jal         0x801C4700
    // 0x801C4318: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_0;
    // 0x801C4318: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C431C: lbu         $a1, 0x5F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X5F);
    // 0x801C4320: sb          $v0, 0xF20($s0)
    MEM_B(0XF20, ctx->r16) = ctx->r2;
    // 0x801C4324: lbu         $a0, 0xF21($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF21);
    // 0x801C4328: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C432C: jal         0x801C4700
    // 0x801C4330: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_1;
    // 0x801C4330: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    after_1:
    // 0x801C4334: lbu         $a1, 0x63($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X63);
    // 0x801C4338: sb          $v0, 0xF21($s0)
    MEM_B(0XF21, ctx->r16) = ctx->r2;
    // 0x801C433C: lbu         $a0, 0xF22($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF22);
    // 0x801C4340: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C4344: jal         0x801C4700
    // 0x801C4348: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_2;
    // 0x801C4348: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_2:
    // 0x801C434C: lbu         $a1, 0x67($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X67);
    // 0x801C4350: sb          $v0, 0xF22($s0)
    MEM_B(0XF22, ctx->r16) = ctx->r2;
    // 0x801C4354: lbu         $a0, 0xF23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF23);
    // 0x801C4358: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C435C: jal         0x801C4700
    // 0x801C4360: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_3;
    // 0x801C4360: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_3:
    // 0x801C4364: lbu         $a1, 0x6B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6B);
    // 0x801C4368: sb          $v0, 0xF23($s0)
    MEM_B(0XF23, ctx->r16) = ctx->r2;
    // 0x801C436C: lbu         $a0, 0xF24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF24);
    // 0x801C4370: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C4374: jal         0x801C4700
    // 0x801C4378: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_4;
    // 0x801C4378: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_4:
    // 0x801C437C: lbu         $a1, 0x6F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6F);
    // 0x801C4380: sb          $v0, 0xF24($s0)
    MEM_B(0XF24, ctx->r16) = ctx->r2;
    // 0x801C4384: lbu         $a0, 0xF25($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF25);
    // 0x801C4388: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C438C: jal         0x801C4700
    // 0x801C4390: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_5;
    // 0x801C4390: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_5:
    // 0x801C4394: sb          $v0, 0xF25($s0)
    MEM_B(0XF25, ctx->r16) = ctx->r2;
    // 0x801C4398: lb          $a0, 0xF26($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XF26);
    // 0x801C439C: lb          $a1, 0x73($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X73);
    // 0x801C43A0: jal         0x801C4700
    // 0x801C43A4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_6;
    // 0x801C43A4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_6:
    // 0x801C43A8: sb          $v0, 0xF26($s0)
    MEM_B(0XF26, ctx->r16) = ctx->r2;
    // 0x801C43AC: lb          $a0, 0xF27($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XF27);
    // 0x801C43B0: lb          $a1, 0x77($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X77);
    // 0x801C43B4: jal         0x801C4700
    // 0x801C43B8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_7;
    // 0x801C43B8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_7:
    // 0x801C43BC: sb          $v0, 0xF27($s0)
    MEM_B(0XF27, ctx->r16) = ctx->r2;
    // 0x801C43C0: lb          $a0, 0xF28($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XF28);
    // 0x801C43C4: lb          $a1, 0x7B($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X7B);
    // 0x801C43C8: jal         0x801C4700
    // 0x801C43CC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_8;
    // 0x801C43CC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_8:
    // 0x801C43D0: lbu         $a1, 0x7F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X7F);
    // 0x801C43D4: sb          $v0, 0xF28($s0)
    MEM_B(0XF28, ctx->r16) = ctx->r2;
    // 0x801C43D8: lbu         $a0, 0xF29($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF29);
    // 0x801C43DC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C43E0: jal         0x801C4700
    // 0x801C43E4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_9;
    // 0x801C43E4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_9:
    // 0x801C43E8: lbu         $a1, 0x83($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X83);
    // 0x801C43EC: sb          $v0, 0xF29($s0)
    MEM_B(0XF29, ctx->r16) = ctx->r2;
    // 0x801C43F0: lbu         $a0, 0xF2A($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF2A);
    // 0x801C43F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C43F8: jal         0x801C4700
    // 0x801C43FC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_10;
    // 0x801C43FC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_10:
    // 0x801C4400: lbu         $a1, 0x87($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X87);
    // 0x801C4404: sb          $v0, 0xF2A($s0)
    MEM_B(0XF2A, ctx->r16) = ctx->r2;
    // 0x801C4408: lbu         $a0, 0xF2B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF2B);
    // 0x801C440C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C4410: jal         0x801C4700
    // 0x801C4414: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_11;
    // 0x801C4414: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_11:
    // 0x801C4418: sb          $v0, 0xF2B($s0)
    MEM_B(0XF2B, ctx->r16) = ctx->r2;
    // 0x801C441C: lb          $a0, 0xF2C($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XF2C);
    // 0x801C4420: lb          $a1, 0x8B($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X8B);
    // 0x801C4424: jal         0x801C4700
    // 0x801C4428: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_12;
    // 0x801C4428: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_12:
    // 0x801C442C: sb          $v0, 0xF2C($s0)
    MEM_B(0XF2C, ctx->r16) = ctx->r2;
    // 0x801C4430: lb          $a0, 0xF2D($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XF2D);
    // 0x801C4434: lb          $a1, 0x8F($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X8F);
    // 0x801C4438: jal         0x801C4700
    // 0x801C443C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_13;
    // 0x801C443C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_13:
    // 0x801C4440: sb          $v0, 0xF2D($s0)
    MEM_B(0XF2D, ctx->r16) = ctx->r2;
    // 0x801C4444: lb          $a0, 0xF2E($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XF2E);
    // 0x801C4448: lb          $a1, 0x93($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X93);
    // 0x801C444C: jal         0x801C4700
    // 0x801C4450: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_14;
    // 0x801C4450: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_14:
    // 0x801C4454: lbu         $a1, 0x97($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X97);
    // 0x801C4458: sb          $v0, 0xF2E($s0)
    MEM_B(0XF2E, ctx->r16) = ctx->r2;
    // 0x801C445C: lbu         $a0, 0xF32($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF32);
    // 0x801C4460: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C4464: jal         0x801C4700
    // 0x801C4468: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_15;
    // 0x801C4468: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_15:
    // 0x801C446C: lbu         $a1, 0x9B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X9B);
    // 0x801C4470: sb          $v0, 0xF32($s0)
    MEM_B(0XF32, ctx->r16) = ctx->r2;
    // 0x801C4474: lbu         $a0, 0xF33($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF33);
    // 0x801C4478: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C447C: jal         0x801C4700
    // 0x801C4480: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_16;
    // 0x801C4480: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_16:
    // 0x801C4484: lbu         $a1, 0x9F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X9F);
    // 0x801C4488: sb          $v0, 0xF33($s0)
    MEM_B(0XF33, ctx->r16) = ctx->r2;
    // 0x801C448C: lbu         $a0, 0xF34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF34);
    // 0x801C4490: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C4494: jal         0x801C4700
    // 0x801C4498: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_17;
    // 0x801C4498: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_17:
    // 0x801C449C: lbu         $a1, 0xA3($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XA3);
    // 0x801C44A0: sb          $v0, 0xF34($s0)
    MEM_B(0XF34, ctx->r16) = ctx->r2;
    // 0x801C44A4: lbu         $a0, 0xF35($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XF35);
    // 0x801C44A8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801C44AC: jal         0x801C4700
    // 0x801C44B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C4700)(rdram, ctx);
        goto after_18;
    // 0x801C44B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_18:
    // 0x801C44B4: sb          $v0, 0xF35($s0)
    MEM_B(0XF35, ctx->r16) = ctx->r2;
    // 0x801C44B8: lwc1        $f12, 0x29C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X29C);
    // 0x801C44BC: lwc1        $f14, 0xA4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x801C44C0: jal         0x801C4750
    // 0x801C44C4: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    LOOKUP_FUNC(0x801C4750)(rdram, ctx);
        goto after_19;
    // 0x801C44C4: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    after_19:
    // 0x801C44C8: swc1        $f0, 0x29C($s0)
    MEM_W(0X29C, ctx->r16) = ctx->f0.u32l;
    // 0x801C44CC: lwc1        $f12, 0x2A0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
    // 0x801C44D0: lwc1        $f14, 0xA8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C44D4: jal         0x801C4750
    // 0x801C44D8: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    LOOKUP_FUNC(0x801C4750)(rdram, ctx);
        goto after_20;
    // 0x801C44D8: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    after_20:
    // 0x801C44DC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x801C44E0: lbu         $t7, 0xF20($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XF20);
    // 0x801C44E4: swc1        $f0, 0x2A0($s0)
    MEM_W(0X2A0, ctx->r16) = ctx->f0.u32l;
    // 0x801C44E8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x801C44EC: xor         $v0, $t6, $t7
    ctx->r2 = ctx->r14 ^ ctx->r15;
    // 0x801C44F0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C44F4: beq         $v0, $zero, L_801C46F0
    if (ctx->r2 == 0) {
        // 0x801C44F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801C46F0;
    }
    // 0x801C44F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C44FC: lbu         $t9, 0xF21($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XF21);
    // 0x801C4500: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x801C4504: xor         $v0, $t8, $t9
    ctx->r2 = ctx->r24 ^ ctx->r25;
    // 0x801C4508: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C450C: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4510: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_0;
    // 0x801C4510: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801C4514: lbu         $t1, 0xF22($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XF22);
    // 0x801C4518: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x801C451C: xor         $v0, $t0, $t1
    ctx->r2 = ctx->r8 ^ ctx->r9;
    // 0x801C4520: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C4524: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4528: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_1;
    // 0x801C4528: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801C452C: lbu         $t3, 0xF23($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XF23);
    // 0x801C4530: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x801C4534: xor         $v0, $t2, $t3
    ctx->r2 = ctx->r10 ^ ctx->r11;
    // 0x801C4538: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C453C: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4540: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_2;
    // 0x801C4540: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801C4544: lbu         $t5, 0xF24($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XF24);
    // 0x801C4548: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801C454C: xor         $v0, $t4, $t5
    ctx->r2 = ctx->r12 ^ ctx->r13;
    // 0x801C4550: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C4554: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4558: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_3;
    // 0x801C4558: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x801C455C: lbu         $t7, 0xF25($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XF25);
    // 0x801C4560: lb          $t8, 0x73($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X73);
    // 0x801C4564: xor         $v0, $t6, $t7
    ctx->r2 = ctx->r14 ^ ctx->r15;
    // 0x801C4568: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C456C: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4570: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_4;
    // 0x801C4570: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x801C4574: lb          $t9, 0xF26($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XF26);
    // 0x801C4578: lb          $t0, 0x77($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X77);
    // 0x801C457C: xor         $v0, $t8, $t9
    ctx->r2 = ctx->r24 ^ ctx->r25;
    // 0x801C4580: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C4584: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4588: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_5;
    // 0x801C4588: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x801C458C: lb          $t1, 0xF27($s0)
    ctx->r9 = MEM_B(ctx->r16, 0XF27);
    // 0x801C4590: lb          $t2, 0x7B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X7B);
    // 0x801C4594: xor         $v0, $t0, $t1
    ctx->r2 = ctx->r8 ^ ctx->r9;
    // 0x801C4598: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C459C: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C45A0: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_6;
    // 0x801C45A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x801C45A4: lb          $t3, 0xF28($s0)
    ctx->r11 = MEM_B(ctx->r16, 0XF28);
    // 0x801C45A8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x801C45AC: xor         $v0, $t2, $t3
    ctx->r2 = ctx->r10 ^ ctx->r11;
    // 0x801C45B0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C45B4: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C45B8: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_7;
    // 0x801C45B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x801C45BC: lbu         $t5, 0xF29($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XF29);
    // 0x801C45C0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x801C45C4: xor         $v0, $t4, $t5
    ctx->r2 = ctx->r12 ^ ctx->r13;
    // 0x801C45C8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C45CC: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C45D0: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_8;
    // 0x801C45D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x801C45D4: lbu         $t7, 0xF2A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XF2A);
    // 0x801C45D8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801C45DC: xor         $v0, $t6, $t7
    ctx->r2 = ctx->r14 ^ ctx->r15;
    // 0x801C45E0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C45E4: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C45E8: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_9;
    // 0x801C45E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x801C45EC: lbu         $t9, 0xF2B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XF2B);
    // 0x801C45F0: lb          $t0, 0x8B($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X8B);
    // 0x801C45F4: xor         $v0, $t8, $t9
    ctx->r2 = ctx->r24 ^ ctx->r25;
    // 0x801C45F8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C45FC: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4600: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_10;
    // 0x801C4600: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x801C4604: lb          $t1, 0xF2C($s0)
    ctx->r9 = MEM_B(ctx->r16, 0XF2C);
    // 0x801C4608: lb          $t2, 0x8F($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X8F);
    // 0x801C460C: xor         $v0, $t0, $t1
    ctx->r2 = ctx->r8 ^ ctx->r9;
    // 0x801C4610: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C4614: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4618: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_11;
    // 0x801C4618: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x801C461C: lb          $t3, 0xF2D($s0)
    ctx->r11 = MEM_B(ctx->r16, 0XF2D);
    // 0x801C4620: lb          $t4, 0x93($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X93);
    // 0x801C4624: xor         $v0, $t2, $t3
    ctx->r2 = ctx->r10 ^ ctx->r11;
    // 0x801C4628: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C462C: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4630: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_12;
    // 0x801C4630: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_12:
    // 0x801C4634: lb          $t5, 0xF2E($s0)
    ctx->r13 = MEM_B(ctx->r16, 0XF2E);
    // 0x801C4638: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801C463C: xor         $v0, $t4, $t5
    ctx->r2 = ctx->r12 ^ ctx->r13;
    // 0x801C4640: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C4644: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4648: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_13;
    // 0x801C4648: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_13:
    // 0x801C464C: lbu         $t7, 0xF32($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XF32);
    // 0x801C4650: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x801C4654: xor         $v0, $t6, $t7
    ctx->r2 = ctx->r14 ^ ctx->r15;
    // 0x801C4658: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C465C: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4660: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_14;
    // 0x801C4660: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_14:
    // 0x801C4664: lbu         $t9, 0xF33($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XF33);
    // 0x801C4668: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x801C466C: xor         $v0, $t8, $t9
    ctx->r2 = ctx->r24 ^ ctx->r25;
    // 0x801C4670: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C4674: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4678: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_15;
    // 0x801C4678: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_15:
    // 0x801C467C: lbu         $t1, 0xF34($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XF34);
    // 0x801C4680: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x801C4684: xor         $v0, $t0, $t1
    ctx->r2 = ctx->r8 ^ ctx->r9;
    // 0x801C4688: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C468C: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C4690: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_16;
    // 0x801C4690: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_16:
    // 0x801C4694: lbu         $t3, 0xF35($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XF35);
    // 0x801C4698: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x801C469C: xor         $v0, $t2, $t3
    ctx->r2 = ctx->r10 ^ ctx->r11;
    // 0x801C46A0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C46A4: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C46A8: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_17;
    // 0x801C46A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_17:
    // 0x801C46AC: lwc1        $f6, 0x29C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X29C);
    // 0x801C46B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C46B4: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C46B8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x801C46BC: nop

    // 0x801C46C0: bc1f        L_801C46CC
    if (!c1cs) {
        // 0x801C46C4: nop
    
            goto L_801C46CC;
    }
    // 0x801C46C4: nop

    // 0x801C46C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C46CC:
    // 0x801C46CC: beql        $v0, $zero, L_801C46F4
    if (ctx->r2 == 0) {
        // 0x801C46D0: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_801C46F4;
    }
    goto skip_18;
    // 0x801C46D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_18:
    // 0x801C46D4: lwc1        $f10, 0x2A0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2A0);
    // 0x801C46D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C46DC: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x801C46E0: nop

    // 0x801C46E4: bc1f        L_801C46F0
    if (!c1cs) {
        // 0x801C46E8: nop
    
            goto L_801C46F0;
    }
    // 0x801C46E8: nop

    // 0x801C46EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C46F0:
    // 0x801C46F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
L_801C46F4:
    // 0x801C46F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C46F8: jr          $ra
    // 0x801C46FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801C46FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c4700(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c4700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4700: bne         $a0, $a1, L_801C4710
    if (ctx->r4 != ctx->r5) {
            // 0x801C4704: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    LOOKUP_FUNC(0x801C4710)(rdram, ctx);
    return;
    }
    // 0x801C4704: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801C4708: jr          $ra
    // 0x801C470C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x801C470C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c4710(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c4710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4710: beql        $at, $zero, L_801C4734
    if (ctx->r1 == 0) {
        // 0x801C4714: subu        $a0, $a0, $a2
        ctx->r4 = SUB32(ctx->r4, ctx->r6);
            goto L_801C4734;
    }
    goto skip_0;
    // 0x801C4714: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    skip_0:
    // 0x801C4718: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x801C471C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801C4720: bnel        $at, $zero, L_801C4748
    if (ctx->r1 != 0) {
        // 0x801C4724: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_801C4748;
    }
    goto skip_1;
    // 0x801C4724: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_1:
    // 0x801C4728: b           L_801C4744
    // 0x801C472C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
        goto L_801C4744;
    // 0x801C472C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801C4730: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
L_801C4734:
    // 0x801C4734: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x801C4738: bnel        $at, $zero, L_801C4748
    if (ctx->r1 != 0) {
        // 0x801C473C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_801C4748;
    }
    goto skip_2;
    // 0x801C473C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_2:
    // 0x801C4740: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_801C4744:
    // 0x801C4744: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_801C4748:
    // 0x801C4748: jr          $ra
    // 0x801C474C: nop

    return;
    // 0x801C474C: nop

;}
RECOMP_FUNC void M8_FUN_801c4750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4750: c.eq.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl == ctx->f14.fl;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c4754(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c4754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4754: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x801C4758: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x801C475C: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x801C4760: bc1fl       L_801C4774
    if (!c1cs) {
        // 0x801C4764: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_801C4774;
    }
    goto skip_0;
    // 0x801C4764: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x801C4768: b           L_801C47D4
    // 0x801C476C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_801C47D4;
    // 0x801C476C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x801C4770: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_801C4774:
    // 0x801C4774: nop

    // 0x801C4778: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x801C477C: nop

    // 0x801C4780: bc1fl       L_801C4790
    if (!c1cs) {
        // 0x801C4784: c.lt.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
            goto L_801C4790;
    }
    goto skip_1;
    // 0x801C4784: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    skip_1:
    // 0x801C4788: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x801C478C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_801C4790:
    // 0x801C4790: nop

    // 0x801C4794: bc1fl       L_801C47BC
    if (!c1cs) {
        // 0x801C4798: sub.s       $f12, $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f20.fl;
            goto L_801C47BC;
    }
    goto skip_2;
    // 0x801C4798: sub.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f20.fl;
    skip_2:
    // 0x801C479C: add.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x801C47A0: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x801C47A4: nop

    // 0x801C47A8: bc1fl       L_801C47D4
    if (!c1cs) {
        // 0x801C47AC: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_801C47D4;
    }
    goto skip_3;
    // 0x801C47AC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_3:
    // 0x801C47B0: b           L_801C47D0
    // 0x801C47B4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_801C47D0;
    // 0x801C47B4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x801C47B8: sub.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f20.fl;
L_801C47BC:
    // 0x801C47BC: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
    // 0x801C47C0: nop

    // 0x801C47C4: bc1fl       L_801C47D4
    if (!c1cs) {
        // 0x801C47C8: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_801C47D4;
    }
    goto skip_4;
    // 0x801C47C8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_4:
    // 0x801C47CC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_801C47D0:
    // 0x801C47D0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_801C47D4:
    // 0x801C47D4: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x801C47D8: jr          $ra
    // 0x801C47DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x801C47DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c47e0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c47e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C47E0: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801C47E4: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x801C47E8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C47EC: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x801C47F0: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801C47F4: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C47F8: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C47FC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801C4800: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C4804: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801C4808: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C480C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C4810: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C4814: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C4818: nop

    // 0x801C481C: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x801C4820: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801C4824: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C4828: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801C482C: nop

    // 0x801C4830: bc1f        L_801C4840
    if (!c1cs) {
            // 0x801C4834: nop

    LOOKUP_FUNC(0x801C4840)(rdram, ctx);
    return;
    }
    // 0x801C4834: nop

    // 0x801C4838: jr          $ra
    // 0x801C483C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C483C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c4840(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c4840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4840: jr          $ra
    // 0x801C4844: nop

    return;
    // 0x801C4844: nop

;}
RECOMP_FUNC void M8_FUN_801c4848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C484C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C4850: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801C4854: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x801C4858: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801C485C: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C4860: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801C4864: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801C4868: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801C486C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C4870: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C4874: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C4878: jal         0x8001EF38
    // 0x801C487C: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801C487C: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x801C4880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4884: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C4888: jr          $ra
    // 0x801C488C: nop

    return;
    // 0x801C488C: nop

;}
RECOMP_FUNC void M8_FUN_801c4890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4890: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C4894: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C4898: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C489C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C48A0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801C48A4: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801C48A8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C48AC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C48B0: lh          $v0, 0x12($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X12);
    // 0x801C48B4: subu        $a3, $v0, $a1
    ctx->r7 = SUB32(ctx->r2, ctx->r5);
    // 0x801C48B8: bgez        $a3, L_801C48C8
    if (SIGNED(ctx->r7) >= 0) {
        // 0x801C48BC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801C48C8;
    }
    // 0x801C48BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801C48C0: b           L_801C48C8
    // 0x801C48C4: negu        $a0, $a3
    ctx->r4 = SUB32(0, ctx->r7);
        goto L_801C48C8;
    // 0x801C48C4: negu        $a0, $a3
    ctx->r4 = SUB32(0, ctx->r7);
L_801C48C8:
    // 0x801C48C8: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x801C48CC: bne         $at, $zero, L_801C48E0
    if (ctx->r1 != 0) {
            // 0x801C48D0: subu        $t7, $a1, $v0
    ctx->r15 = SUB32(ctx->r5, ctx->r2);
    LOOKUP_FUNC(0x801C48E0)(rdram, ctx);
    return;
    }
    // 0x801C48D0: subu        $t7, $a1, $v0
    ctx->r15 = SUB32(ctx->r5, ctx->r2);
    // 0x801C48D4: sh          $a1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r5;
    // 0x801C48D8: jr          $ra
    // 0x801C48DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C48DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c48e0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c48e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C48E0: slti        $at, $t7, 0x1000
    ctx->r1 = SIGNED(ctx->r15) < 0X1000 ? 1 : 0;
    // 0x801C48E4: bne         $at, $zero, L_801C48F8
    if (ctx->r1 != 0) {
        // 0x801C48E8: addu        $t9, $v0, $a2
        ctx->r25 = ADD32(ctx->r2, ctx->r6);
            goto L_801C48F8;
    }
    // 0x801C48E8: addu        $t9, $v0, $a2
    ctx->r25 = ADD32(ctx->r2, ctx->r6);
    // 0x801C48EC: subu        $t8, $v0, $a2
    ctx->r24 = SUB32(ctx->r2, ctx->r6);
    // 0x801C48F0: b           L_801C48FC
    // 0x801C48F4: sh          $t8, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r24;
        goto L_801C48FC;
    // 0x801C48F4: sh          $t8, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r24;
L_801C48F8:
    // 0x801C48F8: sh          $t9, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r25;
L_801C48FC:
    // 0x801C48FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C4900: jr          $ra
    // 0x801C4904: nop

    return;
    // 0x801C4904: nop

;}
RECOMP_FUNC void M8_FUN_801c4908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C490C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C4910: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C4914: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C4918: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C491C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C4920: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C4924: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C4928: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C492C: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801C4930: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C4934: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C4938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C493C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C4940: jal         0x8001EF38
    // 0x801C4944: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801C4944: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x801C4948: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801C494C: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x801C4950: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x801C4954: lw          $t7, 0x24($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X24);
    // 0x801C4958: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x801C495C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x801C4960: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801C4964: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x801C4968: lh          $a2, 0x12($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X12);
    // 0x801C496C: subu        $a0, $v0, $a2
    ctx->r4 = SUB32(ctx->r2, ctx->r6);
    // 0x801C4970: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C4974: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801C4978: andi        $t8, $a0, 0x1000
    ctx->r24 = ctx->r4 & 0X1000;
    // 0x801C497C: beql        $t8, $zero, L_801C499C
    if (ctx->r24 == 0) {
        // 0x801C4980: andi        $a0, $a0, 0x1FFF
        ctx->r4 = ctx->r4 & 0X1FFF;
            goto L_801C499C;
    }
    goto skip_0;
    // 0x801C4980: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    skip_0:
    // 0x801C4984: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x801C4988: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
    // 0x801C498C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C4990: b           L_801C49A4
    // 0x801C4994: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_801C49A4;
    // 0x801C4994: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801C4998: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
L_801C499C:
    // 0x801C499C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C49A0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_801C49A4:
    // 0x801C49A4: bgez        $a0, L_801C49B4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801C49A8: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_801C49B4;
    }
    // 0x801C49A8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801C49AC: b           L_801C49B4
    // 0x801C49B0: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
        goto L_801C49B4;
    // 0x801C49B0: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_801C49B4:
    // 0x801C49B4: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x801C49B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C49BC: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801C49C0: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x801C49C4: nop

    // 0x801C49C8: bc1f        L_801C49D8
    if (!c1cs) {
        // 0x801C49CC: nop
    
            goto L_801C49D8;
    }
    // 0x801C49CC: nop

    // 0x801C49D0: b           L_801C4A4C
    // 0x801C49D4: sh          $a3, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r7;
        goto L_801C4A4C;
    // 0x801C49D4: sh          $a3, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r7;
L_801C49D8:
    // 0x801C49D8: bltzl       $a0, L_801C4A1C
    if (SIGNED(ctx->r4) < 0) {
        // 0x801C49DC: mtc1        $a2, $f18
        ctx->f18.u32l = ctx->r6;
            goto L_801C4A1C;
    }
    goto skip_1;
    // 0x801C49DC: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
    skip_1:
    // 0x801C49E0: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x801C49E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C49E8: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x801C49EC: add.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d + ctx->f0.d;
    // 0x801C49F0: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x801C49F4: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x801C49F8: nop

    // 0x801C49FC: sh          $t1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r9;
    // 0x801C4A00: lw          $t2, 0x24($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X24);
    // 0x801C4A04: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x801C4A08: lh          $t3, 0x12($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X12);
    // 0x801C4A0C: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x801C4A10: b           L_801C4A4C
    // 0x801C4A14: sh          $t4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r12;
        goto L_801C4A4C;
    // 0x801C4A14: sh          $t4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r12;
    // 0x801C4A18: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
L_801C4A1C:
    // 0x801C4A1C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801C4A20: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801C4A24: sub.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d - ctx->f0.d;
    // 0x801C4A28: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x801C4A2C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x801C4A30: nop

    // 0x801C4A34: sh          $t6, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r14;
    // 0x801C4A38: lw          $t7, 0x24($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X24);
    // 0x801C4A3C: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801C4A40: lh          $t8, 0x12($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X12);
    // 0x801C4A44: andi        $t9, $t8, 0x1FFF
    ctx->r25 = ctx->r24 & 0X1FFF;
    // 0x801C4A48: sh          $t9, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r25;
L_801C4A4C:
    // 0x801C4A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C4A54: jr          $ra
    // 0x801C4A58: nop

    return;
    // 0x801C4A58: nop

;}
RECOMP_FUNC void M8_FUN_801c4a5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4A5C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x801C4A60: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x801C4A64: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801C4A68: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x801C4A6C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801C4A70: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801C4A74: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801C4A78: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801C4A7C: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x801C4A80: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801C4A84: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801C4A88: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C4A8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C4A90: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801C4A94: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801C4A98: addiu       $t0, $t0, 0xB30
    ctx->r8 = ADD32(ctx->r8, 0XB30);
    // 0x801C4A9C: bne         $a1, $at, L_801C4C60
    if (ctx->r5 != ctx->r1) {
        // 0x801C4AA0: sw          $t6, 0xEC0($s0)
        MEM_W(0XEC0, ctx->r16) = ctx->r14;
            goto L_801C4C60;
    }
    // 0x801C4AA0: sw          $t6, 0xEC0($s0)
    MEM_W(0XEC0, ctx->r16) = ctx->r14;
    // 0x801C4AA4: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801C4AA8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C4AAC: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801C4AB0: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C4AB4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C4AB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4ABC: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801C4AC0: swc1        $f4, 0xD40($s0)
    MEM_W(0XD40, ctx->r16) = ctx->f4.u32l;
    // 0x801C4AC4: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801C4AC8: lbu         $t7, 0x4D($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4D);
    // 0x801C4ACC: lw          $t6, 0x2C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X2C);
    // 0x801C4AD0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801C4AD4: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x801C4AD8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C4ADC: bgez        $t7, L_801C4AF0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C4AE0: cvt.d.s     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
            goto L_801C4AF0;
    }
    // 0x801C4AE0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C4AE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C4AE8: nop

    // 0x801C4AEC: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801C4AF0:
    // 0x801C4AF0: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801C4AF4: lb          $t8, 0x4F($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X4F);
    // 0x801C4AF8: mul.d       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801C4AFC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x801C4B00: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x801C4B04: add.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f8.d + ctx->f6.d;
    // 0x801C4B08: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C4B0C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801C4B10: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x801C4B14: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x801C4B18: swc1        $f8, 0xD80($s0)
    MEM_W(0XD80, ctx->r16) = ctx->f8.u32l;
    // 0x801C4B1C: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x801C4B20: lw          $t6, 0x2C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X2C);
    // 0x801C4B24: lwc1        $f6, 0xC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC);
    // 0x801C4B28: swc1        $f6, 0xDC0($s0)
    MEM_W(0XDC0, ctx->r16) = ctx->f6.u32l;
L_801C4B2C:
    // 0x801C4B2C: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x801C4B30: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801C4B34: addu        $v1, $s0, $t7
    ctx->r3 = ADD32(ctx->r16, ctx->r15);
    // 0x801C4B38: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C4B3C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4B40: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x801C4B44: swc1        $f4, 0xD40($v1)
    MEM_W(0XD40, ctx->r3) = ctx->f4.u32l;
    // 0x801C4B48: lw          $t6, 0x24($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X24);
    // 0x801C4B4C: lbu         $t8, 0x4D($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C4B50: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C4B54: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801C4B58: lwc1        $f10, 0x8($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801C4B5C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C4B60: bgez        $t8, L_801C4B74
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C4B64: cvt.d.s     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
            goto L_801C4B74;
    }
    // 0x801C4B64: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C4B68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C4B6C: nop

    // 0x801C4B70: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_801C4B74:
    // 0x801C4B74: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C4B78: lb          $t9, 0x4F($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X4F);
    // 0x801C4B7C: mul.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x801C4B80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801C4B84: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801C4B88: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x801C4B8C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x801C4B90: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x801C4B94: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x801C4B98: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C4B9C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C4BA0: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801C4BA4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C4BA8: swc1        $f8, 0xD80($v1)
    MEM_W(0XD80, ctx->r3) = ctx->f8.u32l;
    // 0x801C4BAC: lw          $t6, 0x24($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X24);
    // 0x801C4BB0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C4BB4: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x801C4BB8: bne         $at, $zero, L_801C4B2C
    if (ctx->r1 != 0) {
        // 0x801C4BBC: swc1        $f10, 0xDC0($v1)
        MEM_W(0XDC0, ctx->r3) = ctx->f10.u32l;
            goto L_801C4B2C;
    }
    // 0x801C4BBC: swc1        $f10, 0xDC0($v1)
    MEM_W(0XDC0, ctx->r3) = ctx->f10.u32l;
    // 0x801C4BC0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801C4BC4:
    // 0x801C4BC4: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x801C4BC8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x801C4BCC: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x801C4BD0: lw          $t6, 0x2C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X2C);
    // 0x801C4BD4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4BD8: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x801C4BDC: swc1        $f4, 0xD40($v1)
    MEM_W(0XD40, ctx->r3) = ctx->f4.u32l;
    // 0x801C4BE0: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x801C4BE4: lbu         $t9, 0x4D($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C4BE8: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C4BEC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801C4BF0: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801C4BF4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C4BF8: bgez        $t9, L_801C4C0C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C4BFC: cvt.d.s     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
            goto L_801C4C0C;
    }
    // 0x801C4BFC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C4C00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C4C04: nop

    // 0x801C4C08: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801C4C0C:
    // 0x801C4C0C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801C4C10: lb          $t6, 0x4F($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X4F);
    // 0x801C4C14: mul.d       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801C4C18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801C4C1C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801C4C20: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x801C4C24: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x801C4C28: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x801C4C2C: add.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f8.d + ctx->f6.d;
    // 0x801C4C30: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C4C34: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801C4C38: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x801C4C3C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x801C4C40: swc1        $f8, 0xD80($v1)
    MEM_W(0XD80, ctx->r3) = ctx->f8.u32l;
    // 0x801C4C44: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x801C4C48: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C4C4C: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x801C4C50: bne         $at, $zero, L_801C4BC4
    if (ctx->r1 != 0) {
        // 0x801C4C54: swc1        $f6, 0xDC0($v1)
        MEM_W(0XDC0, ctx->r3) = ctx->f6.u32l;
            goto L_801C4BC4;
    }
    // 0x801C4C54: swc1        $f6, 0xDC0($v1)
    MEM_W(0XDC0, ctx->r3) = ctx->f6.u32l;
    // 0x801C4C58: b           L_801C59FC
    // 0x801C4C5C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801C59FC;
    // 0x801C4C5C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801C4C60:
    // 0x801C4C60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C4C64: bne         $s1, $at, L_801C4C8C
    if (ctx->r17 != ctx->r1) {
        // 0x801C4C68: lui         $t4, 0x801C
        ctx->r12 = S32(0X801C << 16);
            goto L_801C4C8C;
    }
    // 0x801C4C68: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801C4C6C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801C4C70: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801C4C74: lui         $ra, 0x801C
    ctx->r31 = S32(0X801C << 16);
    // 0x801C4C78: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C4C7C: addiu       $t4, $t4, -0x3610
    ctx->r12 = ADD32(ctx->r12, -0X3610);
    // 0x801C4C80: addiu       $t5, $t5, -0x35D0
    ctx->r13 = ADD32(ctx->r13, -0X35D0);
    // 0x801C4C84: b           L_801C4D6C
    // 0x801C4C88: addiu       $ra, $ra, -0x3590
    ctx->r31 = ADD32(ctx->r31, -0X3590);
        goto L_801C4D6C;
    // 0x801C4C88: addiu       $ra, $ra, -0x3590
    ctx->r31 = ADD32(ctx->r31, -0X3590);
L_801C4C8C:
    // 0x801C4C8C: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x801C4C90: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801C4C94: lui         $ra, 0x801C
    ctx->r31 = S32(0X801C << 16);
    // 0x801C4C98: addiu       $t4, $t4, -0x36D0
    ctx->r12 = ADD32(ctx->r12, -0X36D0);
    // 0x801C4C9C: addiu       $t5, $t5, -0x3690
    ctx->r13 = ADD32(ctx->r13, -0X3690);
    // 0x801C4CA0: beq         $t9, $zero, L_801C4D34
    if (ctx->r25 == 0) {
        // 0x801C4CA4: addiu       $ra, $ra, -0x3650
        ctx->r31 = ADD32(ctx->r31, -0X3650);
            goto L_801C4D34;
    }
    // 0x801C4CA4: addiu       $ra, $ra, -0x3650
    ctx->r31 = ADD32(ctx->r31, -0X3650);
    // 0x801C4CA8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C4CAC: addiu       $v1, $v1, 0xB74
    ctx->r3 = ADD32(ctx->r3, 0XB74);
    // 0x801C4CB0: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x801C4CB4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C4CB8: addiu       $v0, $v0, 0x4020
    ctx->r2 = ADD32(ctx->r2, 0X4020);
    // 0x801C4CBC: beql        $t6, $zero, L_801C4D10
    if (ctx->r14 == 0) {
        // 0x801C4CC0: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_801C4D10;
    }
    goto skip_0;
    // 0x801C4CC0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_0:
    // 0x801C4CC4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801C4CC8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801C4CCC: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C4CD0: lw          $v1, 0xE0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XE0);
    // 0x801C4CD4: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x801C4CD8: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x801C4CDC: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x801C4CE0: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x801C4CE4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C4CE8: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x801C4CEC: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x801C4CF0: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
    // 0x801C4CF4: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801C4CF8: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x801C4CFC: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x801C4D00: lwc1        $f10, 0xC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC);
    // 0x801C4D04: b           L_801C4D6C
    // 0x801C4D08: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
        goto L_801C4D6C;
    // 0x801C4D08: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x801C4D0C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_801C4D10:
    // 0x801C4D10: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C4D14: addiu       $v0, $v0, 0x4020
    ctx->r2 = ADD32(ctx->r2, 0X4020);
    // 0x801C4D18: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x801C4D1C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C4D20: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C4D24: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x801C4D28: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x801C4D2C: b           L_801C4D6C
    // 0x801C4D30: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_801C4D6C;
    // 0x801C4D30: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_801C4D34:
    // 0x801C4D34: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C4D38: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C4D3C: addiu       $v0, $v0, 0x4020
    ctx->r2 = ADD32(ctx->r2, 0X4020);
    // 0x801C4D40: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x801C4D44: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C4D48: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x801C4D4C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C4D50: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x801C4D54: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801C4D58: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x801C4D5C: addiu       $v1, $v1, 0xB74
    ctx->r3 = ADD32(ctx->r3, 0XB74);
    // 0x801C4D60: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x801C4D64: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x801C4D68: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
L_801C4D6C:
    // 0x801C4D6C: lw          $v1, 0x24($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X24);
    // 0x801C4D70: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801C4D74: beql        $v1, $zero, L_801C59FC
    if (ctx->r3 == 0) {
        // 0x801C4D78: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801C59FC;
    }
    goto skip_1;
    // 0x801C4D78: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x801C4D7C: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x801C4D80: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C4D84: beq         $v0, $zero, L_801C4DA0
    if (ctx->r2 == 0) {
        // 0x801C4D88: addiu       $t1, $v0, 0x4
        ctx->r9 = ADD32(ctx->r2, 0X4);
            goto L_801C4DA0;
    }
    // 0x801C4D88: addiu       $t1, $v0, 0x4
    ctx->r9 = ADD32(ctx->r2, 0X4);
    // 0x801C4D8C: addiu       $t7, $v0, 0x12
    ctx->r15 = ADD32(ctx->r2, 0X12);
    // 0x801C4D90: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801C4D94: addiu       $t3, $v0, 0xC
    ctx->r11 = ADD32(ctx->r2, 0XC);
    // 0x801C4D98: b           L_801C4DB8
    // 0x801C4D9C: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
        goto L_801C4DB8;
    // 0x801C4D9C: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
L_801C4DA0:
    // 0x801C4DA0: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x801C4DA4: addiu       $t8, $v0, 0x12
    ctx->r24 = ADD32(ctx->r2, 0X12);
    // 0x801C4DA8: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x801C4DAC: addiu       $t1, $v0, 0x4
    ctx->r9 = ADD32(ctx->r2, 0X4);
    // 0x801C4DB0: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801C4DB4: addiu       $t3, $v0, 0xC
    ctx->r11 = ADD32(ctx->r2, 0XC);
L_801C4DB8:
    // 0x801C4DB8: lhu         $t9, 0xB30($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XB30);
    // 0x801C4DBC: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801C4DC0: beql        $t9, $zero, L_801C59FC
    if (ctx->r25 == 0) {
        // 0x801C4DC4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801C59FC;
    }
    goto skip_2;
    // 0x801C4DC4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x801C4DC8: ldc1        $f26, 0x2DC8($at)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r1, 0X2DC8);
    // 0x801C4DCC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801C4DD0: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x801C4DD4: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x801C4DD8: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x801C4DDC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C4DE0: ldc1        $f20, 0x2DD0($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X2DD0);
    // 0x801C4DE4: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x801C4DE8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801C4DEC: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C4DF0: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x801C4DF4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C4DF8: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801C4DFC: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801C4E00: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801C4E04: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801C4E08: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801C4E0C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C4E10: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
    // 0x801C4E14: lw          $t6, 0xEC0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XEC0);
L_801C4E18:
    // 0x801C4E18: slti        $at, $v1, 0x401
    ctx->r1 = SIGNED(ctx->r3) < 0X401 ? 1 : 0;
    // 0x801C4E1C: and         $t7, $v1, $t6
    ctx->r15 = ctx->r3 & ctx->r14;
    // 0x801C4E20: beql        $t7, $zero, L_801C59E8
    if (ctx->r15 == 0) {
        // 0x801C4E24: lhu         $v1, 0x4($t0)
        ctx->r3 = MEM_HU(ctx->r8, 0X4);
            goto L_801C59E8;
    }
    goto skip_3;
    // 0x801C4E24: lhu         $v1, 0x4($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X4);
    skip_3:
    // 0x801C4E28: bne         $at, $zero, L_801C4E64
    if (ctx->r1 != 0) {
        // 0x801C4E2C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801C4E64;
    }
    // 0x801C4E2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801C4E30: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x801C4E34: beq         $v1, $at, L_801C543C
    if (ctx->r3 == ctx->r1) {
        // 0x801C4E38: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_801C543C;
    }
    // 0x801C4E38: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x801C4E3C: beq         $v1, $at, L_801C5554
    if (ctx->r3 == ctx->r1) {
        // 0x801C4E40: addiu       $at, $zero, 0x2000
        ctx->r1 = ADD32(0, 0X2000);
            goto L_801C5554;
    }
    // 0x801C4E40: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x801C4E44: beq         $v1, $at, L_801C55D8
    if (ctx->r3 == ctx->r1) {
        // 0x801C4E48: addiu       $at, $zero, 0x4000
        ctx->r1 = ADD32(0, 0X4000);
            goto L_801C55D8;
    }
    // 0x801C4E48: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x801C4E4C: beq         $v1, $at, L_801C5658
    if (ctx->r3 == ctx->r1) {
        // 0x801C4E50: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_801C5658;
    }
    // 0x801C4E50: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x801C4E54: beql        $v1, $at, L_801C56EC
    if (ctx->r3 == ctx->r1) {
        // 0x801C4E58: lbu         $t9, 0x4C($a3)
        ctx->r25 = MEM_BU(ctx->r7, 0X4C);
            goto L_801C56EC;
    }
    goto skip_4;
    // 0x801C4E58: lbu         $t9, 0x4C($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4C);
    skip_4:
    // 0x801C4E5C: b           L_801C5774
    // 0x801C4E60: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
        goto L_801C5774;
    // 0x801C4E60: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
L_801C4E64:
    // 0x801C4E64: slti        $at, $v0, 0x81
    ctx->r1 = SIGNED(ctx->r2) < 0X81 ? 1 : 0;
    // 0x801C4E68: bne         $at, $zero, L_801C4E90
    if (ctx->r1 != 0) {
        // 0x801C4E6C: addiu       $at, $zero, 0x100
        ctx->r1 = ADD32(0, 0X100);
            goto L_801C4E90;
    }
    // 0x801C4E6C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x801C4E70: beq         $v0, $at, L_801C5248
    if (ctx->r2 == ctx->r1) {
        // 0x801C4E74: addiu       $at, $zero, 0x200
        ctx->r1 = ADD32(0, 0X200);
            goto L_801C5248;
    }
    // 0x801C4E74: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x801C4E78: beq         $v0, $at, L_801C52A8
    if (ctx->r2 == ctx->r1) {
        // 0x801C4E7C: addiu       $at, $zero, 0x400
        ctx->r1 = ADD32(0, 0X400);
            goto L_801C52A8;
    }
    // 0x801C4E7C: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x801C4E80: beq         $v0, $at, L_801C531C
    if (ctx->r2 == ctx->r1) {
        // 0x801C4E84: nop
    
            goto L_801C531C;
    }
    // 0x801C4E84: nop

    // 0x801C4E88: b           L_801C5774
    // 0x801C4E8C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
        goto L_801C5774;
    // 0x801C4E8C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
L_801C4E90:
    // 0x801C4E90: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x801C4E94: bne         $at, $zero, L_801C4EAC
    if (ctx->r1 != 0) {
        // 0x801C4E98: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_801C4EAC;
    }
    // 0x801C4E98: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x801C4E9C: beql        $v0, $at, L_801C51F8
    if (ctx->r2 == ctx->r1) {
        // 0x801C4EA0: swc1        $f18, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
            goto L_801C51F8;
    }
    goto skip_5;
    // 0x801C4EA0: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    skip_5:
    // 0x801C4EA4: b           L_801C5774
    // 0x801C4EA8: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
        goto L_801C5774;
    // 0x801C4EA8: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
L_801C4EAC:
    // 0x801C4EAC: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x801C4EB0: bne         $at, $zero, L_801C4ECC
    if (ctx->r1 != 0) {
        // 0x801C4EB4: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_801C4ECC;
    }
    // 0x801C4EB4: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x801C4EB8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x801C4EBC: beql        $v0, $at, L_801C5180
    if (ctx->r2 == ctx->r1) {
        // 0x801C4EC0: swc1        $f18, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
            goto L_801C5180;
    }
    goto skip_6;
    // 0x801C4EC0: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    skip_6:
    // 0x801C4EC4: b           L_801C5774
    // 0x801C4EC8: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
        goto L_801C5774;
    // 0x801C4EC8: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
L_801C4ECC:
    // 0x801C4ECC: sltiu       $at, $t8, 0x20
    ctx->r1 = ctx->r24 < 0X20 ? 1 : 0;
    // 0x801C4ED0: beq         $at, $zero, L_801C5770
    if (ctx->r1 == 0) {
        // 0x801C4ED4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_801C5770;
    }
    // 0x801C4ED4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801C4ED8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C4EDC: addu        $at, $at, $t8
    gpr jr_addend_801C4EE4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801C4EE0: lw          $t8, 0x2DD8($at)
    ctx->r24 = ADD32(ctx->r1, 0X2DD8);
    // 0x801C4EE4: jr          $t8
    // 0x801C4EE8: nop

    switch (jr_addend_801C4EE4 >> 2) {
        case 0: goto L_801C4EEC; break;
        case 1: goto L_801C4F04; break;
        case 2: goto L_801C5770; break;
        case 3: goto L_801C4FE0; break;
        case 4: goto L_801C5770; break;
        case 5: goto L_801C5770; break;
        case 6: goto L_801C5770; break;
        case 7: goto L_801C5058; break;
        case 8: goto L_801C5770; break;
        case 9: goto L_801C5770; break;
        case 10: goto L_801C5770; break;
        case 11: goto L_801C5770; break;
        case 12: goto L_801C5770; break;
        case 13: goto L_801C5770; break;
        case 14: goto L_801C5770; break;
        case 15: goto L_801C50CC; break;
        case 16: goto L_801C5770; break;
        case 17: goto L_801C5770; break;
        case 18: goto L_801C5770; break;
        case 19: goto L_801C5770; break;
        case 20: goto L_801C5770; break;
        case 21: goto L_801C5770; break;
        case 22: goto L_801C5770; break;
        case 23: goto L_801C5770; break;
        case 24: goto L_801C5770; break;
        case 25: goto L_801C5770; break;
        case 26: goto L_801C5770; break;
        case 27: goto L_801C5770; break;
        case 28: goto L_801C5770; break;
        case 29: goto L_801C5770; break;
        case 30: goto L_801C5770; break;
        case 31: goto L_801C5140; break;
        default: switch_error(__func__, 0x801C4EE4, 0x801E2DD8);
    }
    // 0x801C4EE8: nop

L_801C4EEC:
    // 0x801C4EEC: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x801C4EF0: lb          $t9, 0x4F($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X4F);
    // 0x801C4EF4: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x801C4EF8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801C4EFC: b           L_801C5770
    // 0x801C4F00: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
        goto L_801C5770;
    // 0x801C4F00: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
L_801C4F04:
    // 0x801C4F04: lhu         $t6, 0xEF0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C4F08: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x801C4F0C: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x801C4F10: beql        $t7, $zero, L_801C4F68
    if (ctx->r15 == 0) {
        // 0x801C4F14: lbu         $t6, 0x4D($a3)
        ctx->r14 = MEM_BU(ctx->r7, 0X4D);
            goto L_801C4F68;
    }
    goto skip_7;
    // 0x801C4F14: lbu         $t6, 0x4D($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X4D);
    skip_7:
    // 0x801C4F18: lb          $t8, 0x4F($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X4F);
    // 0x801C4F1C: lbu         $t9, 0x4D($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C4F20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4F24: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801C4F28: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801C4F2C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C4F30: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C4F34: bgez        $t9, L_801C4F48
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C4F38: cvt.d.s     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
            goto L_801C4F48;
    }
    // 0x801C4F38: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801C4F3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C4F40: nop

    // 0x801C4F44: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_801C4F48:
    // 0x801C4F48: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C4F4C: mul.d       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x801C4F50: nop

    // 0x801C4F54: mul.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801C4F58: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x801C4F5C: b           L_801C4FB8
    // 0x801C4F60: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
        goto L_801C4FB8;
    // 0x801C4F60: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801C4F64: lbu         $t6, 0x4D($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X4D);
L_801C4F68:
    // 0x801C4F68: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4F6C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C4F70: bgez        $t6, L_801C4F84
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C4F74: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C4F84;
    }
    // 0x801C4F74: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C4F78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C4F7C: nop

    // 0x801C4F80: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_801C4F84:
    // 0x801C4F84: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801C4F88: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C4F8C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C4F90: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C4F94: lb          $t7, 0x4F($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X4F);
    // 0x801C4F98: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x801C4F9C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801C4FA0: nop

    // 0x801C4FA4: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C4FA8: mul.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x801C4FAC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C4FB0: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x801C4FB4: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
L_801C4FB8:
    // 0x801C4FB8: lbu         $t8, 0x4E($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4E);
    // 0x801C4FBC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4FC0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801C4FC4: bgez        $t8, L_801C4FD8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C4FC8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C4FD8;
    }
    // 0x801C4FC8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C4FCC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C4FD0: nop

    // 0x801C4FD4: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_801C4FD8:
    // 0x801C4FD8: b           L_801C5770
    // 0x801C4FDC: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
        goto L_801C5770;
    // 0x801C4FDC: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
L_801C4FE0:
    // 0x801C4FE0: lbu         $t9, 0x4C($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4C);
    // 0x801C4FE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4FE8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801C4FEC: bgez        $t9, L_801C5000
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C4FF0: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801C5000;
    }
    // 0x801C4FF0: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C4FF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C4FF8: nop

    // 0x801C4FFC: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_801C5000:
    // 0x801C5000: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x801C5004: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5008: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x801C500C: lb          $t6, 0x4F($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X4F);
    // 0x801C5010: lbu         $t7, 0x4D($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C5014: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x801C5018: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801C501C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C5020: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C5024: bgez        $t7, L_801C5038
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C5028: cvt.d.s     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
            goto L_801C5038;
    }
    // 0x801C5028: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801C502C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C5030: nop

    // 0x801C5034: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801C5038:
    // 0x801C5038: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801C503C: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x801C5040: mul.d       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x801C5044: nop

    // 0x801C5048: mul.d       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801C504C: add.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d + ctx->f8.d;
    // 0x801C5050: b           L_801C5770
    // 0x801C5054: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
        goto L_801C5770;
    // 0x801C5054: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
L_801C5058:
    // 0x801C5058: lbu         $t8, 0x4C($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4C);
    // 0x801C505C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5060: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x801C5064: bgez        $t8, L_801C5078
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C5068: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C5078;
    }
    // 0x801C5068: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C506C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C5070: nop

    // 0x801C5074: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_801C5078:
    // 0x801C5078: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x801C507C: lb          $t9, 0x4F($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X4F);
    // 0x801C5080: lbu         $t6, 0x4D($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C5084: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5088: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801C508C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C5090: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C5094: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C5098: bgez        $t6, L_801C50AC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C509C: cvt.d.s     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
            goto L_801C50AC;
    }
    // 0x801C509C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C50A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C50A4: nop

    // 0x801C50A8: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_801C50AC:
    // 0x801C50AC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801C50B0: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x801C50B4: mul.d       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x801C50B8: nop

    // 0x801C50BC: mul.d       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801C50C0: add.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f8.d + ctx->f6.d;
    // 0x801C50C4: b           L_801C5770
    // 0x801C50C8: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
        goto L_801C5770;
    // 0x801C50C8: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
L_801C50CC:
    // 0x801C50CC: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x801C50D0: lb          $t7, 0x4F($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X4F);
    // 0x801C50D4: lbu         $t8, 0x4D($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C50D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C50DC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801C50E0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801C50E4: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C50E8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C50EC: bgez        $t8, L_801C5100
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C50F0: cvt.d.s     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
            goto L_801C5100;
    }
    // 0x801C50F0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801C50F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C50F8: nop

    // 0x801C50FC: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_801C5100:
    // 0x801C5100: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801C5104: lbu         $t9, 0x4E($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4E);
    // 0x801C5108: mul.d       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x801C510C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5110: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x801C5114: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801C5118: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x801C511C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C5120: bgez        $t9, L_801C5134
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C5124: cvt.s.d     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
            goto L_801C5134;
    }
    // 0x801C5124: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x801C5128: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C512C: nop

    // 0x801C5130: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_801C5134:
    // 0x801C5134: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x801C5138: b           L_801C5770
    // 0x801C513C: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
        goto L_801C5770;
    // 0x801C513C: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
L_801C5140:
    // 0x801C5140: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x801C5144: lbu         $t7, 0x4D($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C5148: lb          $t6, 0x4F($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X4F);
    // 0x801C514C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5150: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801C5154: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x801C5158: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C515C: bgez        $t7, L_801C5170
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C5160: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801C5170;
    }
    // 0x801C5160: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C5164: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C5168: nop

    // 0x801C516C: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_801C5170:
    // 0x801C5170: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801C5174: b           L_801C5770
    // 0x801C5178: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
        goto L_801C5770;
    // 0x801C5178: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x801C517C: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
L_801C5180:
    // 0x801C5180: lbu         $t8, 0x4D($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C5184: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5188: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801C518C: bgez        $t8, L_801C51A0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C5190: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801C51A0;
    }
    // 0x801C5190: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C5194: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C5198: nop

    // 0x801C519C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801C51A0:
    // 0x801C51A0: lb          $t9, 0x4F($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X4F);
    // 0x801C51A4: lui         $at, 0x3F90
    ctx->r1 = S32(0X3F90 << 16);
    // 0x801C51A8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C51AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C51B0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801C51B4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801C51B8: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801C51BC: lbu         $t6, 0x4E($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X4E);
    // 0x801C51C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C51C4: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C51C8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C51CC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C51D0: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x801C51D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C51D8: bgez        $t6, L_801C51EC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C51DC: cvt.s.d     $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
            goto L_801C51EC;
    }
    // 0x801C51DC: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801C51E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C51E4: nop

    // 0x801C51E8: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_801C51EC:
    // 0x801C51EC: b           L_801C5770
    // 0x801C51F0: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
        goto L_801C5770;
    // 0x801C51F0: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x801C51F4: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
L_801C51F8:
    // 0x801C51F8: lbu         $t7, 0x4D($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C51FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5200: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801C5204: bgez        $t7, L_801C5218
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C5208: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801C5218;
    }
    // 0x801C5208: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C520C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C5210: nop

    // 0x801C5214: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_801C5218:
    // 0x801C5218: lb          $t8, 0x4F($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X4F);
    // 0x801C521C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x801C5220: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801C5224: mul.d       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x801C5228: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C522C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C5230: mul.d       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f24.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f24.d);
    // 0x801C5234: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801C5238: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x801C523C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C5240: b           L_801C5770
    // 0x801C5244: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
        goto L_801C5770;
    // 0x801C5244: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
L_801C5248:
    // 0x801C5248: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x801C524C: lbu         $t9, 0x4D($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C5250: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5254: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801C5258: bgez        $t9, L_801C526C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C525C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C526C;
    }
    // 0x801C525C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C5260: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C5264: nop

    // 0x801C5268: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_801C526C:
    // 0x801C526C: lb          $t6, 0x4F($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X4F);
    // 0x801C5270: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C5274: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x801C5278: nop

    // 0x801C527C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C5280: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x801C5284: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x801C5288: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801C528C: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x801C5290: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801C5294: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x801C5298: mul.d       $f8, $f4, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f24.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f24.d);
    // 0x801C529C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C52A0: b           L_801C5770
    // 0x801C52A4: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
        goto L_801C5770;
    // 0x801C52A4: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
L_801C52A8:
    // 0x801C52A8: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x801C52AC: lbu         $t7, 0x4D($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C52B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C52B4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801C52B8: bgez        $t7, L_801C52CC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C52BC: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801C52CC;
    }
    // 0x801C52BC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C52C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C52C4: nop

    // 0x801C52C8: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_801C52CC:
    // 0x801C52CC: lb          $t8, 0x4F($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X4F);
    // 0x801C52D0: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x801C52D4: lbu         $t9, 0x4E($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4E);
    // 0x801C52D8: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x801C52DC: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x801C52E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C52E4: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C52E8: mul.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801C52EC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801C52F0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C52F4: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x801C52F8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C52FC: bgez        $t9, L_801C5310
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C5300: cvt.s.d     $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
            goto L_801C5310;
    }
    // 0x801C5300: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x801C5304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C5308: nop

    // 0x801C530C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801C5310:
    // 0x801C5310: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x801C5314: b           L_801C5770
    // 0x801C5318: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
        goto L_801C5770;
    // 0x801C5318: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
L_801C531C:
    // 0x801C531C: beql        $s1, $zero, L_801C53C8
    if (ctx->r17 == 0) {
        // 0x801C5320: lbu         $t6, 0x4C($a3)
        ctx->r14 = MEM_BU(ctx->r7, 0X4C);
            goto L_801C53C8;
    }
    goto skip_8;
    // 0x801C5320: lbu         $t6, 0x4C($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X4C);
    skip_8:
    // 0x801C5324: lbu         $t6, 0x4C($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X4C);
    // 0x801C5328: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C532C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C5330: bgez        $t6, L_801C5344
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C5334: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C5344;
    }
    // 0x801C5334: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C5338: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C533C: nop

    // 0x801C5340: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_801C5344:
    // 0x801C5344: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x801C5348: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C534C: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x801C5350: lb          $t7, 0x4F($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X4F);
    // 0x801C5354: lbu         $t8, 0x4D($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C5358: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801C535C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801C5360: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C5364: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C5368: bgez        $t8, L_801C537C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C536C: cvt.d.s     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
            goto L_801C537C;
    }
    // 0x801C536C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C5370: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C5374: nop

    // 0x801C5378: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_801C537C:
    // 0x801C537C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C5380: lbu         $t9, 0x4E($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4E);
    // 0x801C5384: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x801C5388: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C538C: mul.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x801C5390: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801C5394: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801C5398: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C539C: bgez        $t9, L_801C53B0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C53A0: cvt.s.d     $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
            goto L_801C53B0;
    }
    // 0x801C53A0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x801C53A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C53A8: nop

    // 0x801C53AC: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_801C53B0:
    // 0x801C53B0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801C53B4: mul.d       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f26.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f26.d);
    // 0x801C53B8: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801C53BC: b           L_801C5770
    // 0x801C53C0: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
        goto L_801C5770;
    // 0x801C53C0: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x801C53C4: lbu         $t6, 0x4C($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X4C);
L_801C53C8:
    // 0x801C53C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C53CC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801C53D0: bgez        $t6, L_801C53E4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C53D4: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C53E4;
    }
    // 0x801C53D4: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C53D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C53DC: nop

    // 0x801C53E0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C53E4:
    // 0x801C53E4: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x801C53E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C53EC: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x801C53F0: lb          $t7, 0x4F($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X4F);
    // 0x801C53F4: lbu         $t8, 0x4D($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C53F8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801C53FC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801C5400: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C5404: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C5408: bgez        $t8, L_801C541C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C540C: cvt.d.s     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
            goto L_801C541C;
    }
    // 0x801C540C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801C5410: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C5414: nop

    // 0x801C5418: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_801C541C:
    // 0x801C541C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801C5420: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x801C5424: mul.d       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x801C5428: nop

    // 0x801C542C: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x801C5430: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x801C5434: b           L_801C5770
    // 0x801C5438: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
        goto L_801C5770;
    // 0x801C5438: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
L_801C543C:
    // 0x801C543C: beql        $s1, $zero, L_801C54E4
    if (ctx->r17 == 0) {
        // 0x801C5440: lbu         $t9, 0x4C($a3)
        ctx->r25 = MEM_BU(ctx->r7, 0X4C);
            goto L_801C54E4;
    }
    goto skip_9;
    // 0x801C5440: lbu         $t9, 0x4C($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4C);
    skip_9:
    // 0x801C5444: lbu         $t9, 0x4C($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4C);
    // 0x801C5448: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C544C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801C5450: bgez        $t9, L_801C5464
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C5454: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801C5464;
    }
    // 0x801C5454: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C5458: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C545C: nop

    // 0x801C5460: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_801C5464:
    // 0x801C5464: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x801C5468: lb          $t6, 0x4F($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X4F);
    // 0x801C546C: lbu         $t7, 0x4D($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C5470: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5474: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C5478: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801C547C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C5480: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C5484: bgez        $t7, L_801C5498
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C5488: cvt.d.s     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
            goto L_801C5498;
    }
    // 0x801C5488: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C548C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C5490: nop

    // 0x801C5494: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_801C5498:
    // 0x801C5498: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C549C: lbu         $t8, 0x4E($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4E);
    // 0x801C54A0: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x801C54A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C54A8: mul.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x801C54AC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801C54B0: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801C54B4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C54B8: bgez        $t8, L_801C54CC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C54BC: cvt.s.d     $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
            goto L_801C54CC;
    }
    // 0x801C54BC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x801C54C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C54C4: nop

    // 0x801C54C8: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_801C54CC:
    // 0x801C54CC: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801C54D0: mul.d       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f26.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f26.d);
    // 0x801C54D4: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801C54D8: b           L_801C5770
    // 0x801C54DC: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
        goto L_801C5770;
    // 0x801C54DC: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x801C54E0: lbu         $t9, 0x4C($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4C);
L_801C54E4:
    // 0x801C54E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C54E8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801C54EC: bgez        $t9, L_801C5500
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C54F0: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C5500;
    }
    // 0x801C54F0: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C54F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C54F8: nop

    // 0x801C54FC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C5500:
    // 0x801C5500: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x801C5504: lb          $t6, 0x4F($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X4F);
    // 0x801C5508: lbu         $t7, 0x4D($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C550C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5510: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C5514: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801C5518: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C551C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C5520: bgez        $t7, L_801C5534
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C5524: cvt.d.s     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
            goto L_801C5534;
    }
    // 0x801C5524: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C5528: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C552C: nop

    // 0x801C5530: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_801C5534:
    // 0x801C5534: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C5538: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x801C553C: mul.d       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x801C5540: nop

    // 0x801C5544: mul.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801C5548: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x801C554C: b           L_801C5770
    // 0x801C5550: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
        goto L_801C5770;
    // 0x801C5550: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
L_801C5554:
    // 0x801C5554: lbu         $t8, 0x4C($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4C);
    // 0x801C5558: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C555C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x801C5560: bgez        $t8, L_801C5574
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C5564: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C5574;
    }
    // 0x801C5564: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C5568: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C556C: nop

    // 0x801C5570: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_801C5574:
    // 0x801C5574: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x801C5578: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C557C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801C5580: mul.d       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x801C5584: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801C5588: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x801C558C: lbu         $t9, 0x4D($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C5590: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801C5594: bgez        $t9, L_801C55A8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C5598: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801C55A8;
    }
    // 0x801C5598: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C559C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C55A0: nop

    // 0x801C55A4: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_801C55A8:
    // 0x801C55A8: lb          $t6, 0x4F($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X4F);
    // 0x801C55AC: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x801C55B0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x801C55B4: mul.d       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x801C55B8: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C55BC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801C55C0: mul.d       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f22.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f22.d);
    // 0x801C55C4: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x801C55C8: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801C55CC: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801C55D0: b           L_801C5770
    // 0x801C55D4: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
        goto L_801C5770;
    // 0x801C55D4: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
L_801C55D8:
    // 0x801C55D8: lbu         $t7, 0x4C($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X4C);
    // 0x801C55DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C55E0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801C55E4: bgez        $t7, L_801C55F8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C55E8: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C55F8;
    }
    // 0x801C55E8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C55EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C55F0: nop

    // 0x801C55F4: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_801C55F8:
    // 0x801C55F8: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801C55FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5600: mul.d       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x801C5604: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x801C5608: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x801C560C: lbu         $t8, 0x4D($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C5610: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801C5614: bgez        $t8, L_801C5628
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C5618: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801C5628;
    }
    // 0x801C5618: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C561C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C5620: nop

    // 0x801C5624: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_801C5628:
    // 0x801C5628: lb          $t9, 0x4F($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X4F);
    // 0x801C562C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x801C5630: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801C5634: mul.d       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x801C5638: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C563C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C5640: mul.d       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f22.d);
    // 0x801C5644: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801C5648: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x801C564C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801C5650: b           L_801C5770
    // 0x801C5654: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
        goto L_801C5770;
    // 0x801C5654: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
L_801C5658:
    // 0x801C5658: lbu         $t6, 0x4C($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X4C);
    // 0x801C565C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5660: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C5664: bgez        $t6, L_801C5678
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C5668: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C5678;
    }
    // 0x801C5668: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C566C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C5670: nop

    // 0x801C5674: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C5678:
    // 0x801C5678: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x801C567C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5680: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801C5684: mul.d       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x801C5688: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801C568C: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x801C5690: lbu         $t7, 0x4D($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C5694: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801C5698: bgez        $t7, L_801C56AC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C569C: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C56AC;
    }
    // 0x801C569C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C56A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C56A4: nop

    // 0x801C56A8: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_801C56AC:
    // 0x801C56AC: lb          $t8, 0x4F($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X4F);
    // 0x801C56B0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C56B4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801C56B8: nop

    // 0x801C56BC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C56C0: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x801C56C4: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x801C56C8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801C56CC: add.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d + ctx->f8.d;
    // 0x801C56D0: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801C56D4: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x801C56D8: mul.d       $f8, $f10, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f22.d);
    // 0x801C56DC: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801C56E0: b           L_801C5770
    // 0x801C56E4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
        goto L_801C5770;
    // 0x801C56E4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x801C56E8: lbu         $t9, 0x4C($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4C);
L_801C56EC:
    // 0x801C56EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C56F0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801C56F4: bgez        $t9, L_801C5708
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C56F8: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C5708;
    }
    // 0x801C56F8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C56FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C5700: nop

    // 0x801C5704: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_801C5708:
    // 0x801C5708: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801C570C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5710: mul.d       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x801C5714: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801C5718: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x801C571C: lbu         $t6, 0x4D($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C5720: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801C5724: bgez        $t6, L_801C5738
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C5728: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C5738;
    }
    // 0x801C5728: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C572C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C5730: nop

    // 0x801C5734: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_801C5738:
    // 0x801C5738: lb          $t7, 0x4F($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X4F);
    // 0x801C573C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C5740: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801C5744: nop

    // 0x801C5748: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C574C: mul.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x801C5750: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x801C5754: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801C5758: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x801C575C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801C5760: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801C5764: mul.d       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f22.d);
    // 0x801C5768: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801C576C: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
L_801C5770:
    // 0x801C5770: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
L_801C5774:
    // 0x801C5774: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x801C5778: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x801C577C: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    // 0x801C5780: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801C5784: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    // 0x801C5788: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x801C578C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C5790: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801C5794: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x801C5798: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x801C579C: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x801C57A0: sw          $t2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r10;
    // 0x801C57A4: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x801C57A8: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x801C57AC: jal         0x80130C40
    // 0x801C57B0: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80130C40)(rdram, ctx);
        goto after_0;
    // 0x801C57B0: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    after_0:
    // 0x801C57B4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C57B8: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801C57BC: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C57C0: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x801C57C4: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x801C57C8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801C57CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C57D0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801C57D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801C57D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C57DC: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x801C57E0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x801C57E4: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x801C57E8: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x801C57EC: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x801C57F0: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x801C57F4: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x801C57F8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801C57FC: beq         $s1, $zero, L_801C5858
    if (ctx->r17 == 0) {
        // 0x801C5800: lwc1        $f12, 0x6C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
            goto L_801C5858;
    }
    // 0x801C5800: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801C5804: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801C5808: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801C580C: lhu         $t9, 0x2($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X2);
    // 0x801C5810: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x801C5814: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801C5818: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x801C581C: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x801C5820: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801C5824: lhu         $t8, 0x2($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X2);
    // 0x801C5828: add.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x801C582C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C5830: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x801C5834: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x801C5838: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801C583C: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801C5840: lhu         $t7, 0x2($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X2);
    // 0x801C5844: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801C5848: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801C584C: addu        $t9, $ra, $t8
    ctx->r25 = ADD32(ctx->r31, ctx->r24);
    // 0x801C5850: b           L_801C59E4
    // 0x801C5854: swc1        $f8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f8.u32l;
        goto L_801C59E4;
    // 0x801C5854: swc1        $f8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f8.u32l;
L_801C5858:
    // 0x801C5858: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x801C585C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C5860: beq         $v0, $at, L_801C5894
    if (ctx->r2 == ctx->r1) {
        // 0x801C5864: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_801C5894;
    }
    // 0x801C5864: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x801C5868: beq         $v0, $at, L_801C5894
    if (ctx->r2 == ctx->r1) {
        // 0x801C586C: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_801C5894;
    }
    // 0x801C586C: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x801C5870: beq         $v0, $at, L_801C5958
    if (ctx->r2 == ctx->r1) {
        // 0x801C5874: addiu       $at, $zero, 0x400
        ctx->r1 = ADD32(0, 0X400);
            goto L_801C5958;
    }
    // 0x801C5874: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x801C5878: beq         $v0, $at, L_801C5908
    if (ctx->r2 == ctx->r1) {
        // 0x801C587C: lwc1        $f6, 0x70($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
            goto L_801C5908;
    }
    // 0x801C587C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801C5880: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x801C5884: beql        $v0, $at, L_801C590C
    if (ctx->r2 == ctx->r1) {
        // 0x801C5888: lwc1        $f4, 0x0($t1)
        ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
            goto L_801C590C;
    }
    goto skip_10;
    // 0x801C5888: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    skip_10:
    // 0x801C588C: b           L_801C59A8
    // 0x801C5890: lhu         $t6, 0x2($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X2);
        goto L_801C59A8;
    // 0x801C5890: lhu         $t6, 0x2($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X2);
L_801C5894:
    // 0x801C5894: lhu         $t6, 0x2($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X2);
    // 0x801C5898: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801C589C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C58A0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C58A4: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x801C58A8: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x801C58AC: lbu         $t9, 0x4D($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C58B0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801C58B4: bgez        $t9, L_801C58C8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C58B8: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C58C8;
    }
    // 0x801C58B8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C58BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C58C0: nop

    // 0x801C58C4: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_801C58C8:
    // 0x801C58C8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C58CC: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801C58D0: mul.d       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f24.d);
    // 0x801C58D4: lhu         $t6, 0x2($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X2);
    // 0x801C58D8: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801C58DC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C58E0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x801C58E4: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801C58E8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C58EC: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x801C58F0: lhu         $t9, 0x2($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X2);
    // 0x801C58F4: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801C58F8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801C58FC: addu        $t7, $ra, $t6
    ctx->r15 = ADD32(ctx->r31, ctx->r14);
    // 0x801C5900: b           L_801C59E4
    // 0x801C5904: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
        goto L_801C59E4;
    // 0x801C5904: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
L_801C5908:
    // 0x801C5908: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
L_801C590C:
    // 0x801C590C: lhu         $t8, 0x2($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X2);
    // 0x801C5910: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801C5914: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C5918: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x801C591C: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x801C5920: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801C5924: lhu         $t7, 0x2($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X2);
    // 0x801C5928: add.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x801C592C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801C5930: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x801C5934: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x801C5938: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801C593C: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801C5940: lhu         $t6, 0x2($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X2);
    // 0x801C5944: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801C5948: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C594C: addu        $t8, $ra, $t7
    ctx->r24 = ADD32(ctx->r31, ctx->r15);
    // 0x801C5950: b           L_801C59E4
    // 0x801C5954: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
        goto L_801C59E4;
    // 0x801C5954: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
L_801C5958:
    // 0x801C5958: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801C595C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5960: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x801C5964: lbu         $t9, 0x4D($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4D);
    // 0x801C5968: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801C596C: bgez        $t9, L_801C5980
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801C5970: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801C5980;
    }
    // 0x801C5970: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C5974: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C5978: nop

    // 0x801C597C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801C5980:
    // 0x801C5980: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801C5984: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801C5988: mul.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801C598C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C5990: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x801C5994: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801C5998: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x801C599C: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801C59A0: swc1        $f6, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f6.u32l;
    // 0x801C59A4: lhu         $t6, 0x2($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X2);
L_801C59A8:
    // 0x801C59A8: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801C59AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C59B0: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x801C59B4: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x801C59B8: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801C59BC: lhu         $t9, 0x2($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X2);
    // 0x801C59C0: add.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x801C59C4: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801C59C8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x801C59CC: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x801C59D0: lhu         $t8, 0x2($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X2);
    // 0x801C59D4: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801C59D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C59DC: addu        $t6, $ra, $t9
    ctx->r14 = ADD32(ctx->r31, ctx->r25);
    // 0x801C59E0: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
L_801C59E4:
    // 0x801C59E4: lhu         $v1, 0x4($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X4);
L_801C59E8:
    // 0x801C59E8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x801C59EC: bnel        $v1, $zero, L_801C4E18
    if (ctx->r3 != 0) {
        // 0x801C59F0: lw          $t6, 0xEC0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0XEC0);
            goto L_801C4E18;
    }
    goto skip_11;
    // 0x801C59F0: lw          $t6, 0xEC0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XEC0);
    skip_11:
    // 0x801C59F4: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    // 0x801C59F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801C59FC:
    // 0x801C59FC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801C5A00: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801C5A04: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801C5A08: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801C5A0C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x801C5A10: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x801C5A14: jr          $ra
    // 0x801C5A18: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x801C5A18: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c5a1c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c5a1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5A1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C5A20: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C5A24: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801C5A28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C5A2C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801C5A30: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801C5A34: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801C5A38: jal         0x80108480
    // 0x801C5A3C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80108480)(rdram, ctx);
        goto after_0;
    // 0x801C5A3C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801C5A40: beq         $v0, $zero, L_801C5A50
    if (ctx->r2 == 0) {
        // 0x801C5A44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801C5A50;
    }
    // 0x801C5A44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C5A48: b           L_801C5A54
    // 0x801C5A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C5A54;
    // 0x801C5A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C5A50:
    // 0x801C5A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C5A54:
    // 0x801C5A54: jr          $ra
    // 0x801C5A58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C5A58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c5a5c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c5a5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5A5C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x801C5A60: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801C5A64: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801C5A68: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801C5A6C: lw          $t6, 0xDC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XDC);
    // 0x801C5A70: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x801C5A74: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801C5A78: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x801C5A7C: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x801C5A80: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x801C5A84: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x801C5A88: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x801C5A8C: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x801C5A90: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x801C5A94: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x801C5A98: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x801C5A9C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801C5AA0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801C5AA4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801C5AA8: lw          $s6, 0x5C($t6)
    ctx->r22 = MEM_W(ctx->r14, 0X5C);
    // 0x801C5AAC: sw          $zero, 0xEC4($s0)
    MEM_W(0XEC4, ctx->r16) = 0;
    // 0x801C5AB0: swc1        $f26, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f26.u32l;
    // 0x801C5AB4: swc1        $f26, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f26.u32l;
    // 0x801C5AB8: swc1        $f26, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f26.u32l;
    // 0x801C5ABC: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x801C5AC0: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x801C5AC4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801C5AC8: addiu       $s2, $s2, 0xB30
    ctx->r18 = ADD32(ctx->r18, 0XB30);
    // 0x801C5ACC: mov.s       $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    ctx->f28.fl = ctx->f26.fl;
    // 0x801C5AD0: beq         $v1, $zero, L_801C777C
    if (ctx->r3 == 0) {
        // 0x801C5AD4: mov.s       $f30, $f26
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    ctx->f30.fl = ctx->f26.fl;
            goto L_801C777C;
    }
    // 0x801C5AD4: mov.s       $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    ctx->f30.fl = ctx->f26.fl;
    // 0x801C5AD8: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x801C5ADC: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801C5AE0: addiu       $s5, $zero, 0x21
    ctx->r21 = ADD32(0, 0X21);
    // 0x801C5AE4: beq         $v0, $zero, L_801C5B04
    if (ctx->r2 == 0) {
        // 0x801C5AE8: addiu       $t7, $v0, 0x4
        ctx->r15 = ADD32(ctx->r2, 0X4);
            goto L_801C5B04;
    }
    // 0x801C5AE8: addiu       $t7, $v0, 0x4
    ctx->r15 = ADD32(ctx->r2, 0X4);
    // 0x801C5AEC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801C5AF0: addiu       $t9, $v0, 0xC
    ctx->r25 = ADD32(ctx->r2, 0XC);
    // 0x801C5AF4: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x801C5AF8: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x801C5AFC: b           L_801C5B20
    // 0x801C5B00: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
        goto L_801C5B20;
    // 0x801C5B00: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
L_801C5B04:
    // 0x801C5B04: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x801C5B08: addiu       $t0, $v0, 0x4
    ctx->r8 = ADD32(ctx->r2, 0X4);
    // 0x801C5B0C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x801C5B10: addiu       $t2, $v0, 0xC
    ctx->r10 = ADD32(ctx->r2, 0XC);
    // 0x801C5B14: sw          $t0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r8;
    // 0x801C5B18: sw          $t1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r9;
    // 0x801C5B1C: sw          $t2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r10;
L_801C5B20:
    // 0x801C5B20: lhu         $t3, 0xB30($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XB30);
    // 0x801C5B24: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
    // 0x801C5B28: beql        $t3, $zero, L_801C7780
    if (ctx->r11 == 0) {
        // 0x801C5B2C: lw          $v0, 0xEC4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XEC4);
            goto L_801C7780;
    }
    goto skip_0;
    // 0x801C5B2C: lw          $v0, 0xEC4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XEC4);
    skip_0:
    // 0x801C5B30: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x801C5B34: lw          $t4, 0xEC0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XEC0);
L_801C5B38:
    // 0x801C5B38: slti        $at, $v1, 0x401
    ctx->r1 = SIGNED(ctx->r3) < 0X401 ? 1 : 0;
    // 0x801C5B3C: and         $t5, $v1, $t4
    ctx->r13 = ctx->r3 & ctx->r12;
    // 0x801C5B40: beql        $t5, $zero, L_801C7770
    if (ctx->r13 == 0) {
        // 0x801C5B44: lhu         $v1, 0x4($s2)
        ctx->r3 = MEM_HU(ctx->r18, 0X4);
            goto L_801C7770;
    }
    goto skip_1;
    // 0x801C5B44: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    skip_1:
    // 0x801C5B48: bne         $at, $zero, L_801C5B84
    if (ctx->r1 != 0) {
        // 0x801C5B4C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801C5B84;
    }
    // 0x801C5B4C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801C5B50: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x801C5B54: beq         $v1, $at, L_801C7184
    if (ctx->r3 == ctx->r1) {
        // 0x801C5B58: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_801C7184;
    }
    // 0x801C5B58: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x801C5B5C: beq         $v1, $at, L_801C6D44
    if (ctx->r3 == ctx->r1) {
        // 0x801C5B60: addiu       $at, $zero, 0x2000
        ctx->r1 = ADD32(0, 0X2000);
            goto L_801C6D44;
    }
    // 0x801C5B60: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x801C5B64: beq         $v1, $at, L_801C6D44
    if (ctx->r3 == ctx->r1) {
        // 0x801C5B68: addiu       $at, $zero, 0x4000
        ctx->r1 = ADD32(0, 0X4000);
            goto L_801C6D44;
    }
    // 0x801C5B68: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x801C5B6C: beq         $v1, $at, L_801C6D44
    if (ctx->r3 == ctx->r1) {
        // 0x801C5B70: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_801C6D44;
    }
    // 0x801C5B70: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x801C5B74: beql        $v1, $at, L_801C6D48
    if (ctx->r3 == ctx->r1) {
        // 0x801C5B78: lhu         $t4, 0xEF0($s0)
        ctx->r12 = MEM_HU(ctx->r16, 0XEF0);
            goto L_801C6D48;
    }
    goto skip_2;
    // 0x801C5B78: lhu         $t4, 0xEF0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XEF0);
    skip_2:
    // 0x801C5B7C: b           L_801C7770
    // 0x801C5B80: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C5B80: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C5B84:
    // 0x801C5B84: slti        $at, $v0, 0x81
    ctx->r1 = SIGNED(ctx->r2) < 0X81 ? 1 : 0;
    // 0x801C5B88: bne         $at, $zero, L_801C5BB0
    if (ctx->r1 != 0) {
        // 0x801C5B8C: addiu       $at, $zero, 0x100
        ctx->r1 = ADD32(0, 0X100);
            goto L_801C5BB0;
    }
    // 0x801C5B8C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x801C5B90: beq         $v0, $at, L_801C6D44
    if (ctx->r2 == ctx->r1) {
        // 0x801C5B94: addiu       $at, $zero, 0x200
        ctx->r1 = ADD32(0, 0X200);
            goto L_801C6D44;
    }
    // 0x801C5B94: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x801C5B98: beq         $v0, $at, L_801C6D44
    if (ctx->r2 == ctx->r1) {
        // 0x801C5B9C: addiu       $at, $zero, 0x400
        ctx->r1 = ADD32(0, 0X400);
            goto L_801C6D44;
    }
    // 0x801C5B9C: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x801C5BA0: beql        $v0, $at, L_801C6F64
    if (ctx->r2 == ctx->r1) {
        // 0x801C5BA4: lhu         $t6, 0x2($s2)
        ctx->r14 = MEM_HU(ctx->r18, 0X2);
            goto L_801C6F64;
    }
    goto skip_3;
    // 0x801C5BA4: lhu         $t6, 0x2($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X2);
    skip_3:
    // 0x801C5BA8: b           L_801C7770
    // 0x801C5BAC: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C5BAC: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C5BB0:
    // 0x801C5BB0: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x801C5BB4: bne         $at, $zero, L_801C5BCC
    if (ctx->r1 != 0) {
        // 0x801C5BB8: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_801C5BCC;
    }
    // 0x801C5BB8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x801C5BBC: beql        $v0, $at, L_801C6D48
    if (ctx->r2 == ctx->r1) {
        // 0x801C5BC0: lhu         $t4, 0xEF0($s0)
        ctx->r12 = MEM_HU(ctx->r16, 0XEF0);
            goto L_801C6D48;
    }
    goto skip_4;
    // 0x801C5BC0: lhu         $t4, 0xEF0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XEF0);
    skip_4:
    // 0x801C5BC4: b           L_801C7770
    // 0x801C5BC8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C5BC8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C5BCC:
    // 0x801C5BCC: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x801C5BD0: bne         $at, $zero, L_801C5BEC
    if (ctx->r1 != 0) {
        // 0x801C5BD4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_801C5BEC;
    }
    // 0x801C5BD4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801C5BD8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x801C5BDC: beql        $v0, $at, L_801C7480
    if (ctx->r2 == ctx->r1) {
        // 0x801C5BE0: lhu         $t3, 0x2($s2)
        ctx->r11 = MEM_HU(ctx->r18, 0X2);
            goto L_801C7480;
    }
    goto skip_5;
    // 0x801C5BE0: lhu         $t3, 0x2($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X2);
    skip_5:
    // 0x801C5BE4: b           L_801C7770
    // 0x801C5BE8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C5BE8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C5BEC:
    // 0x801C5BEC: sltiu       $at, $t6, 0x20
    ctx->r1 = ctx->r14 < 0X20 ? 1 : 0;
    // 0x801C5BF0: beq         $at, $zero, L_801C776C
    if (ctx->r1 == 0) {
        // 0x801C5BF4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801C776C;
    }
    // 0x801C5BF4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801C5BF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C5BFC: addu        $at, $at, $t6
    gpr jr_addend_801C5C04 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801C5C00: lw          $t6, 0x2E58($at)
    ctx->r14 = ADD32(ctx->r1, 0X2E58);
    // 0x801C5C04: jr          $t6
    // 0x801C5C08: nop

    switch (jr_addend_801C5C04 >> 2) {
        case 0: goto L_801C5C0C; break;
        case 1: goto L_801C60BC; break;
        case 2: goto L_801C776C; break;
        case 3: goto L_801C6D44; break;
        case 4: goto L_801C776C; break;
        case 5: goto L_801C776C; break;
        case 6: goto L_801C776C; break;
        case 7: goto L_801C6D44; break;
        case 8: goto L_801C776C; break;
        case 9: goto L_801C776C; break;
        case 10: goto L_801C776C; break;
        case 11: goto L_801C776C; break;
        case 12: goto L_801C776C; break;
        case 13: goto L_801C776C; break;
        case 14: goto L_801C776C; break;
        case 15: goto L_801C6D44; break;
        case 16: goto L_801C776C; break;
        case 17: goto L_801C776C; break;
        case 18: goto L_801C776C; break;
        case 19: goto L_801C776C; break;
        case 20: goto L_801C776C; break;
        case 21: goto L_801C776C; break;
        case 22: goto L_801C776C; break;
        case 23: goto L_801C776C; break;
        case 24: goto L_801C776C; break;
        case 25: goto L_801C776C; break;
        case 26: goto L_801C776C; break;
        case 27: goto L_801C776C; break;
        case 28: goto L_801C776C; break;
        case 29: goto L_801C776C; break;
        case 30: goto L_801C776C; break;
        case 31: goto L_801C73F0; break;
        default: switch_error(__func__, 0x801C5C04, 0x801E2E58);
    }
    // 0x801C5C08: nop

L_801C5C0C:
    // 0x801C5C0C: lhu         $t7, 0x2($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X2);
    // 0x801C5C10: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801C5C14: addu        $v0, $s0, $t8
    ctx->r2 = ADD32(ctx->r16, ctx->r24);
    // 0x801C5C18: lwc1        $f4, 0xE40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C5C1C: lwc1        $f6, 0xE80($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XE80);
    // 0x801C5C20: lwc1        $f12, 0xD40($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XD40);
    // 0x801C5C24: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C5C28: lw          $a2, 0xDC0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XDC0);
    // 0x801C5C2C: lw          $a3, 0xE00($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE00);
    // 0x801C5C30: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801C5C34: jal         0x801C5A1C
    // 0x801C5C38: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_0;
    // 0x801C5C38: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801C5C3C: beql        $v0, $zero, L_801C5E18
    if (ctx->r2 == 0) {
        // 0x801C5C40: lhu         $t2, 0x2($s2)
        ctx->r10 = MEM_HU(ctx->r18, 0X2);
            goto L_801C5E18;
    }
    goto skip_6;
    // 0x801C5C40: lhu         $t2, 0x2($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X2);
    skip_6:
    // 0x801C5C44: lbu         $v1, 0x35A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C5C48: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801C5C4C: bne         $v1, $at, L_801C5CC0
    if (ctx->r3 != ctx->r1) {
        // 0x801C5C50: nop
    
            goto L_801C5CC0;
    }
    // 0x801C5C50: nop

    // 0x801C5C54: lhu         $v0, 0xEF0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C5C58: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801C5C5C: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x801C5C60: bne         $t9, $zero, L_801C5CC0
    if (ctx->r25 != 0) {
        // 0x801C5C64: nop
    
            goto L_801C5CC0;
    }
    // 0x801C5C64: nop

    // 0x801C5C68: lhu         $t0, -0x23BE($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X23BE);
    // 0x801C5C6C: ori         $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 | 0X8000;
    // 0x801C5C70: blezl       $t0, L_801C5CC0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x801C5C74: sh          $t3, 0xEF0($s0)
        MEM_H(0XEF0, ctx->r16) = ctx->r11;
            goto L_801C5CC0;
    }
    goto skip_7;
    // 0x801C5C74: sh          $t3, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r11;
    skip_7:
    // 0x801C5C78: lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1C);
    // 0x801C5C7C: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C5C80: ori         $at, $at, 0x12
    ctx->r1 = ctx->r1 | 0X12;
    // 0x801C5C84: beq         $v0, $at, L_801C5CC0
    if (ctx->r2 == ctx->r1) {
        // 0x801C5C88: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C5CC0;
    }
    // 0x801C5C88: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C5C8C: ori         $at, $at, 0x13
    ctx->r1 = ctx->r1 | 0X13;
    // 0x801C5C90: beq         $v0, $at, L_801C5CC0
    if (ctx->r2 == ctx->r1) {
        // 0x801C5C94: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C5CC0;
    }
    // 0x801C5C94: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C5C98: ori         $at, $at, 0x14
    ctx->r1 = ctx->r1 | 0X14;
    // 0x801C5C9C: beq         $v0, $at, L_801C5CC0
    if (ctx->r2 == ctx->r1) {
        // 0x801C5CA0: nop
    
            goto L_801C5CC0;
    }
    // 0x801C5CA0: nop

    // 0x801C5CA4: jal         0x801C3B7C
    // 0x801C5CA8: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_1;
    // 0x801C5CA8: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    after_1:
    // 0x801C5CAC: lhu         $t1, 0xEF0($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C5CB0: ori         $t2, $t1, 0x200
    ctx->r10 = ctx->r9 | 0X200;
    // 0x801C5CB4: b           L_801C776C
    // 0x801C5CB8: sh          $t2, 0xEF2($s0)
    MEM_H(0XEF2, ctx->r16) = ctx->r10;
        goto L_801C776C;
    // 0x801C5CB8: sh          $t2, 0xEF2($s0)
    MEM_H(0XEF2, ctx->r16) = ctx->r10;
    // 0x801C5CBC: sh          $t3, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r11;
L_801C5CC0:
    // 0x801C5CC0: beql        $s4, $v1, L_801C5E18
    if (ctx->r20 == ctx->r3) {
        // 0x801C5CC4: lhu         $t2, 0x2($s2)
        ctx->r10 = MEM_HU(ctx->r18, 0X2);
            goto L_801C5E18;
    }
    goto skip_8;
    // 0x801C5CC4: lhu         $t2, 0x2($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X2);
    skip_8:
    // 0x801C5CC8: beql        $s5, $v1, L_801C5E18
    if (ctx->r21 == ctx->r3) {
        // 0x801C5CCC: lhu         $t2, 0x2($s2)
        ctx->r10 = MEM_HU(ctx->r18, 0X2);
            goto L_801C5E18;
    }
    goto skip_9;
    // 0x801C5CCC: lhu         $t2, 0x2($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X2);
    skip_9:
    // 0x801C5CD0: lwc1        $f10, 0x35C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X35C);
    // 0x801C5CD4: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x801C5CD8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C5CDC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801C5CE0: c.eq.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d == ctx->f16.d;
    // 0x801C5CE4: nop

    // 0x801C5CE8: bc1fl       L_801C5D14
    if (!c1cs) {
        // 0x801C5CEC: lhu         $t4, 0x2($s2)
        ctx->r12 = MEM_HU(ctx->r18, 0X2);
            goto L_801C5D14;
    }
    goto skip_10;
    // 0x801C5CEC: lhu         $t4, 0x2($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X2);
    skip_10:
    // 0x801C5CF0: lwc1        $f4, 0x364($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X364);
    // 0x801C5CF4: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x801C5CF8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C5CFC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C5D00: c.eq.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d == ctx->f6.d;
    // 0x801C5D04: nop

    // 0x801C5D08: bc1tl       L_801C5D4C
    if (c1cs) {
        // 0x801C5D0C: lwc1        $f12, 0x368($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
            goto L_801C5D4C;
    }
    goto skip_11;
    // 0x801C5D0C: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
    skip_11:
    // 0x801C5D10: lhu         $t4, 0x2($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X2);
L_801C5D14:
    // 0x801C5D14: lwc1        $f10, 0x380($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X380);
    // 0x801C5D18: lhu         $t7, 0x2($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X2);
    // 0x801C5D1C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801C5D20: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x801C5D24: lwc1        $f8, 0xE00($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XE00);
    // 0x801C5D28: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801C5D2C: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x801C5D30: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x801C5D34: lwc1        $f4, 0x388($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X388);
    // 0x801C5D38: swc1        $f16, 0x368($s0)
    MEM_W(0X368, ctx->r16) = ctx->f16.u32l;
    // 0x801C5D3C: lwc1        $f18, 0xE80($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XE80);
    // 0x801C5D40: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x801C5D44: swc1        $f6, 0x370($s0)
    MEM_W(0X370, ctx->r16) = ctx->f6.u32l;
    // 0x801C5D48: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
L_801C5D4C:
    // 0x801C5D4C: c.lt.s      $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f12.fl < ctx->f26.fl;
    // 0x801C5D50: nop

    // 0x801C5D54: bc1fl       L_801C5D68
    if (!c1cs) {
        // 0x801C5D58: mov.s       $f24, $f12
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
            goto L_801C5D68;
    }
    goto skip_12;
    // 0x801C5D58: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    skip_12:
    // 0x801C5D5C: b           L_801C5D68
    // 0x801C5D60: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
        goto L_801C5D68;
    // 0x801C5D60: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
    // 0x801C5D64: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
L_801C5D68:
    // 0x801C5D68: c.lt.s      $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f30.fl < ctx->f26.fl;
    // 0x801C5D6C: nop

    // 0x801C5D70: bc1fl       L_801C5D84
    if (!c1cs) {
        // 0x801C5D74: mov.s       $f0, $f30
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
            goto L_801C5D84;
    }
    goto skip_13;
    // 0x801C5D74: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
    skip_13:
    // 0x801C5D78: b           L_801C5D84
    // 0x801C5D7C: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
        goto L_801C5D84;
    // 0x801C5D7C: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
    // 0x801C5D80: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
L_801C5D84:
    // 0x801C5D84: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C5D88: nop

    // 0x801C5D8C: bc1fl       L_801C5D9C
    if (!c1cs) {
        // 0x801C5D90: lwc1        $f2, 0x370($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
            goto L_801C5D9C;
    }
    goto skip_14;
    // 0x801C5D90: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
    skip_14:
    // 0x801C5D94: mov.s       $f30, $f12
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    ctx->f30.fl = ctx->f12.fl;
    // 0x801C5D98: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
L_801C5D9C:
    // 0x801C5D9C: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
    // 0x801C5DA0: nop

    // 0x801C5DA4: bc1fl       L_801C5DB8
    if (!c1cs) {
        // 0x801C5DA8: mov.s       $f24, $f2
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
            goto L_801C5DB8;
    }
    goto skip_15;
    // 0x801C5DA8: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
    skip_15:
    // 0x801C5DAC: b           L_801C5DB8
    // 0x801C5DB0: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
        goto L_801C5DB8;
    // 0x801C5DB0: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
    // 0x801C5DB4: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_801C5DB8:
    // 0x801C5DB8: c.lt.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl < ctx->f26.fl;
    // 0x801C5DBC: nop

    // 0x801C5DC0: bc1fl       L_801C5DD4
    if (!c1cs) {
        // 0x801C5DC4: mov.s       $f0, $f28
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
            goto L_801C5DD4;
    }
    goto skip_16;
    // 0x801C5DC4: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
    skip_16:
    // 0x801C5DC8: b           L_801C5DD4
    // 0x801C5DCC: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
        goto L_801C5DD4;
    // 0x801C5DCC: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
    // 0x801C5DD0: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_801C5DD4:
    // 0x801C5DD4: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C5DD8: nop

    // 0x801C5DDC: bc1fl       L_801C5DEC
    if (!c1cs) {
        // 0x801C5DE0: c.eq.s      $f26, $f12
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
            goto L_801C5DEC;
    }
    goto skip_17;
    // 0x801C5DE0: c.eq.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
    skip_17:
    // 0x801C5DE4: mov.s       $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
    // 0x801C5DE8: c.eq.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
L_801C5DEC:
    // 0x801C5DEC: nop

    // 0x801C5DF0: bc1fl       L_801C5E0C
    if (!c1cs) {
        // 0x801C5DF4: lw          $t0, 0xEC4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0XEC4);
            goto L_801C5E0C;
    }
    goto skip_18;
    // 0x801C5DF4: lw          $t0, 0xEC4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XEC4);
    skip_18:
    // 0x801C5DF8: c.eq.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl == ctx->f2.fl;
    // 0x801C5DFC: nop

    // 0x801C5E00: bc1tl       L_801C5E18
    if (c1cs) {
        // 0x801C5E04: lhu         $t2, 0x2($s2)
        ctx->r10 = MEM_HU(ctx->r18, 0X2);
            goto L_801C5E18;
    }
    goto skip_19;
    // 0x801C5E04: lhu         $t2, 0x2($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X2);
    skip_19:
    // 0x801C5E08: lw          $t0, 0xEC4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XEC4);
L_801C5E0C:
    // 0x801C5E0C: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x801C5E10: sw          $t1, 0xEC4($s0)
    MEM_W(0XEC4, ctx->r16) = ctx->r9;
    // 0x801C5E14: lhu         $t2, 0x2($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X2);
L_801C5E18:
    // 0x801C5E18: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801C5E1C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C5E20: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801C5E24: addu        $v0, $s0, $t3
    ctx->r2 = ADD32(ctx->r16, ctx->r11);
    // 0x801C5E28: lwc1        $f16, 0xE40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C5E2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C5E30: lwc1        $f10, 0xE00($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE00);
    // 0x801C5E34: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801C5E38: lwc1        $f8, 0xE80($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XE80);
    // 0x801C5E3C: sub.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d - ctx->f18.d;
    // 0x801C5E40: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C5E44: add.s       $f12, $f10, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x801C5E48: add.s       $f0, $f8, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x801C5E4C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801C5E50: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801C5E54: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801C5E58: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801C5E5C: jal         0x801C5A1C
    // 0x801C5E60: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_2;
    // 0x801C5E60: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801C5E64: beql        $v0, $zero, L_801C60B4
    if (ctx->r2 == 0) {
        // 0x801C5E68: sb          $zero, 0xEF6($s0)
        MEM_B(0XEF6, ctx->r16) = 0;
            goto L_801C60B4;
    }
    goto skip_20;
    // 0x801C5E68: sb          $zero, 0xEF6($s0)
    MEM_B(0XEF6, ctx->r16) = 0;
    skip_20:
    // 0x801C5E6C: lbu         $v1, 0x35A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C5E70: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801C5E74: bne         $v1, $at, L_801C5EF4
    if (ctx->r3 != ctx->r1) {
        // 0x801C5E78: sb          $v1, 0xEF6($s0)
        MEM_B(0XEF6, ctx->r16) = ctx->r3;
            goto L_801C5EF4;
    }
    // 0x801C5E78: sb          $v1, 0xEF6($s0)
    MEM_B(0XEF6, ctx->r16) = ctx->r3;
    // 0x801C5E7C: lhu         $v0, 0xEF0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C5E80: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x801C5E84: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    // 0x801C5E88: bnel        $t4, $zero, L_801C5EF8
    if (ctx->r12 != 0) {
        // 0x801C5E8C: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_801C5EF8;
    }
    goto skip_21;
    // 0x801C5E8C: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    skip_21:
    // 0x801C5E90: lhu         $t5, -0x23BE($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X23BE);
    // 0x801C5E94: ori         $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 | 0X8000;
    // 0x801C5E98: blez        $t5, L_801C5EEC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x801C5E9C: nop
    
            goto L_801C5EEC;
    }
    // 0x801C5E9C: nop

    // 0x801C5EA0: lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1C);
    // 0x801C5EA4: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C5EA8: ori         $at, $at, 0x12
    ctx->r1 = ctx->r1 | 0X12;
    // 0x801C5EAC: beq         $v0, $at, L_801C5F44
    if (ctx->r2 == ctx->r1) {
        // 0x801C5EB0: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C5F44;
    }
    // 0x801C5EB0: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C5EB4: ori         $at, $at, 0x13
    ctx->r1 = ctx->r1 | 0X13;
    // 0x801C5EB8: beq         $v0, $at, L_801C5F44
    if (ctx->r2 == ctx->r1) {
        // 0x801C5EBC: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C5F44;
    }
    // 0x801C5EBC: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C5EC0: ori         $at, $at, 0x14
    ctx->r1 = ctx->r1 | 0X14;
    // 0x801C5EC4: beql        $v0, $at, L_801C5F48
    if (ctx->r2 == ctx->r1) {
        // 0x801C5EC8: lbu         $t1, 0x35A($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X35A);
            goto L_801C5F48;
    }
    goto skip_22;
    // 0x801C5EC8: lbu         $t1, 0x35A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X35A);
    skip_22:
    // 0x801C5ECC: jal         0x801C3B7C
    // 0x801C5ED0: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_3;
    // 0x801C5ED0: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    after_3:
    // 0x801C5ED4: lhu         $v0, 0xEF0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C5ED8: ori         $t6, $v0, 0x200
    ctx->r14 = ctx->r2 | 0X200;
    // 0x801C5EDC: ori         $t7, $v0, 0x1
    ctx->r15 = ctx->r2 | 0X1;
    // 0x801C5EE0: sh          $t6, 0xEF2($s0)
    MEM_H(0XEF2, ctx->r16) = ctx->r14;
    // 0x801C5EE4: b           L_801C776C
    // 0x801C5EE8: sh          $t7, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r15;
        goto L_801C776C;
    // 0x801C5EE8: sh          $t7, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r15;
L_801C5EEC:
    // 0x801C5EEC: b           L_801C5F44
    // 0x801C5EF0: sh          $t8, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r24;
        goto L_801C5F44;
    // 0x801C5EF0: sh          $t8, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r24;
L_801C5EF4:
    // 0x801C5EF4: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
L_801C5EF8:
    // 0x801C5EF8: bnel        $v1, $at, L_801C5F14
    if (ctx->r3 != ctx->r1) {
        // 0x801C5EFC: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_801C5F14;
    }
    goto skip_23;
    // 0x801C5EFC: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    skip_23:
    // 0x801C5F00: lhu         $t9, 0xEF0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C5F04: ori         $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 | 0X8000;
    // 0x801C5F08: b           L_801C776C
    // 0x801C5F0C: sh          $t0, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r8;
        goto L_801C776C;
    // 0x801C5F0C: sh          $t0, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r8;
    // 0x801C5F10: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
L_801C5F14:
    // 0x801C5F14: bnel        $v1, $at, L_801C5F48
    if (ctx->r3 != ctx->r1) {
        // 0x801C5F18: lbu         $t1, 0x35A($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X35A);
            goto L_801C5F48;
    }
    goto skip_24;
    // 0x801C5F18: lbu         $t1, 0x35A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X35A);
    skip_24:
    // 0x801C5F1C: jal         0x801C3B20
    // 0x801C5F20: nop

    LOOKUP_FUNC(0x801C3B20)(rdram, ctx);
        goto after_4;
    // 0x801C5F20: nop

    after_4:
    // 0x801C5F24: bnel        $v0, $zero, L_801C5F48
    if (ctx->r2 != 0) {
        // 0x801C5F28: lbu         $t1, 0x35A($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X35A);
            goto L_801C5F48;
    }
    goto skip_25;
    // 0x801C5F28: lbu         $t1, 0x35A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X35A);
    skip_25:
    // 0x801C5F2C: jal         0x801C3B48
    // 0x801C5F30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801C3B48)(rdram, ctx);
        goto after_5;
    // 0x801C5F30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x801C5F34: jal         0x801C3B7C
    // 0x801C5F38: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_6;
    // 0x801C5F38: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    after_6:
    // 0x801C5F3C: swc1        $f26, 0x40($s3)
    MEM_W(0X40, ctx->r19) = ctx->f26.u32l;
    // 0x801C5F40: swc1        $f26, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->f26.u32l;
L_801C5F44:
    // 0x801C5F44: lbu         $t1, 0x35A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X35A);
L_801C5F48:
    // 0x801C5F48: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801C5F4C: beq         $t1, $at, L_801C60B4
    if (ctx->r9 == ctx->r1) {
        // 0x801C5F50: nop
    
            goto L_801C60B4;
    }
    // 0x801C5F50: nop

    // 0x801C5F54: lwc1        $f0, 0x35C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X35C);
    // 0x801C5F58: lwc1        $f14, 0x360($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X360);
    // 0x801C5F5C: lwc1        $f2, 0x364($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X364);
    // 0x801C5F60: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C5F64: nop

    // 0x801C5F68: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C5F6C: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801C5F70: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C5F74: jal         0x8002FC20
    // 0x801C5F78: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_7;
    // 0x801C5F78: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    after_7:
    // 0x801C5F7C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801C5F80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C5F84: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801C5F88: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801C5F8C: c.eq.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d == ctx->f10.d;
    // 0x801C5F90: nop

    // 0x801C5F94: bc1tl       L_801C5FB8
    if (c1cs) {
        // 0x801C5F98: lwc1        $f18, 0x36C($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X36C);
            goto L_801C5FB8;
    }
    goto skip_26;
    // 0x801C5F98: lwc1        $f18, 0x36C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X36C);
    skip_26:
    // 0x801C5F9C: lwc1        $f8, 0x35C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X35C);
    // 0x801C5FA0: lwc1        $f16, 0x360($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X360);
    // 0x801C5FA4: lwc1        $f4, 0x364($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X364);
    // 0x801C5FA8: swc1        $f8, 0xED8($s0)
    MEM_W(0XED8, ctx->r16) = ctx->f8.u32l;
    // 0x801C5FAC: swc1        $f16, 0xEDC($s0)
    MEM_W(0XEDC, ctx->r16) = ctx->f16.u32l;
    // 0x801C5FB0: swc1        $f4, 0xEE0($s0)
    MEM_W(0XEE0, ctx->r16) = ctx->f4.u32l;
    // 0x801C5FB4: lwc1        $f18, 0x36C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X36C);
L_801C5FB8:
    // 0x801C5FB8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C5FBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C5FC0: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801C5FC4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801C5FC8: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801C5FCC: nop

    // 0x801C5FD0: bc1fl       L_801C6010
    if (!c1cs) {
        // 0x801C5FD4: lwc1        $f6, 0x360($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X360);
            goto L_801C6010;
    }
    goto skip_27;
    // 0x801C5FD4: lwc1        $f6, 0x360($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X360);
    skip_27:
    // 0x801C5FD8: lhu         $t2, 0x2($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X2);
    // 0x801C5FDC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C5FE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C5FE4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801C5FE8: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x801C5FEC: lwc1        $f8, 0xE40($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XE40);
    // 0x801C5FF0: lwc1        $f6, 0x384($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X384);
    // 0x801C5FF4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801C5FF8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801C5FFC: sub.d       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f16.d - ctx->f4.d;
    // 0x801C6000: sub.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d - ctx->f18.d;
    // 0x801C6004: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801C6008: swc1        $f16, 0x36C($s0)
    MEM_W(0X36C, ctx->r16) = ctx->f16.u32l;
    // 0x801C600C: lwc1        $f6, 0x360($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X360);
L_801C6010:
    // 0x801C6010: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x801C6014: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C6018: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801C601C: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C6020: c.eq.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d == ctx->f10.d;
    // 0x801C6024: nop

    // 0x801C6028: bc1tl       L_801C606C
    if (c1cs) {
        // 0x801C602C: lbu         $t8, 0x35A($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X35A);
            goto L_801C606C;
    }
    goto skip_28;
    // 0x801C602C: lbu         $t8, 0x35A($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X35A);
    skip_28:
    // 0x801C6030: lwc1        $f0, 0x36C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X36C);
    // 0x801C6034: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x801C6038: nop

    // 0x801C603C: bc1fl       L_801C604C
    if (!c1cs) {
        // 0x801C6040: c.eq.s      $f26, $f0
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl == ctx->f0.fl;
            goto L_801C604C;
    }
    goto skip_29;
    // 0x801C6040: c.eq.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl == ctx->f0.fl;
    skip_29:
    // 0x801C6044: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x801C6048: c.eq.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl == ctx->f0.fl;
L_801C604C:
    // 0x801C604C: nop

    // 0x801C6050: bc1tl       L_801C606C
    if (c1cs) {
        // 0x801C6054: lbu         $t8, 0x35A($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X35A);
            goto L_801C606C;
    }
    goto skip_30;
    // 0x801C6054: lbu         $t8, 0x35A($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X35A);
    skip_30:
    // 0x801C6058: lw          $t5, 0xEC4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XEC4);
    // 0x801C605C: lhu         $t6, 0x0($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X0);
    // 0x801C6060: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x801C6064: sw          $t7, 0xEC4($s0)
    MEM_W(0XEC4, ctx->r16) = ctx->r15;
    // 0x801C6068: lbu         $t8, 0x35A($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X35A);
L_801C606C:
    // 0x801C606C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801C6070: bnel        $t8, $at, L_801C60A0
    if (ctx->r24 != ctx->r1) {
        // 0x801C6074: lbu         $t2, 0xEF5($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0XEF5);
            goto L_801C60A0;
    }
    goto skip_31;
    // 0x801C6074: lbu         $t2, 0xEF5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XEF5);
    skip_31:
    // 0x801C6078: lbu         $t9, 0xEF5($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XEF5);
    // 0x801C607C: bnel        $t9, $zero, L_801C60A0
    if (ctx->r25 != 0) {
        // 0x801C6080: lbu         $t2, 0xEF5($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0XEF5);
            goto L_801C60A0;
    }
    goto skip_32;
    // 0x801C6080: lbu         $t2, 0xEF5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XEF5);
    skip_32:
    // 0x801C6084: lbu         $t0, 0x28($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X28);
    // 0x801C6088: bnel        $t0, $zero, L_801C60A0
    if (ctx->r8 != 0) {
        // 0x801C608C: lbu         $t2, 0xEF5($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0XEF5);
            goto L_801C60A0;
    }
    goto skip_33;
    // 0x801C608C: lbu         $t2, 0xEF5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XEF5);
    skip_33:
    // 0x801C6090: lw          $t1, 0x38C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38C);
    // 0x801C6094: b           L_801C776C
    // 0x801C6098: sw          $t1, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = ctx->r9;
        goto L_801C776C;
    // 0x801C6098: sw          $t1, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = ctx->r9;
    // 0x801C609C: lbu         $t2, 0xEF5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XEF5);
L_801C60A0:
    // 0x801C60A0: bne         $t2, $zero, L_801C60B4
    if (ctx->r10 != 0) {
        // 0x801C60A4: nop
    
            goto L_801C60B4;
    }
    // 0x801C60A4: nop

    // 0x801C60A8: b           L_801C776C
    // 0x801C60AC: sw          $zero, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = 0;
        goto L_801C776C;
    // 0x801C60AC: sw          $zero, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = 0;
    // 0x801C60B0: sb          $zero, 0xEF6($s0)
    MEM_B(0XEF6, ctx->r16) = 0;
L_801C60B4:
    // 0x801C60B4: b           L_801C7770
    // 0x801C60B8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C60B8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C60BC:
    // 0x801C60BC: lhu         $t3, 0xEF0($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C60C0: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x801C60C4: bnel        $t4, $zero, L_801C7770
    if (ctx->r12 != 0) {
        // 0x801C60C8: lhu         $v1, 0x4($s2)
        ctx->r3 = MEM_HU(ctx->r18, 0X4);
            goto L_801C7770;
    }
    goto skip_34;
    // 0x801C60C8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    skip_34:
    // 0x801C60CC: lhu         $t5, 0x2($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X2);
    // 0x801C60D0: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C60D4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801C60D8: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x801C60DC: lwc1        $f8, 0xE40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C60E0: lwc1        $f4, 0xE80($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XE80);
    // 0x801C60E4: lwc1        $f12, 0xD40($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XD40);
    // 0x801C60E8: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801C60EC: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C60F0: lw          $a2, 0xDC0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XDC0);
    // 0x801C60F4: lw          $a3, 0xE00($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE00);
    // 0x801C60F8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801C60FC: jal         0x801C5A1C
    // 0x801C6100: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_8;
    // 0x801C6100: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x801C6104: beql        $v0, $zero, L_801C6D3C
    if (ctx->r2 == 0) {
        // 0x801C6108: sb          $zero, 0xEF7($s0)
        MEM_B(0XEF7, ctx->r16) = 0;
            goto L_801C6D3C;
    }
    goto skip_35;
    // 0x801C6108: sb          $zero, 0xEF7($s0)
    MEM_B(0XEF7, ctx->r16) = 0;
    skip_35:
    // 0x801C610C: lbu         $v1, 0x35A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C6110: bne         $s4, $v1, L_801C6120
    if (ctx->r20 != ctx->r3) {
        // 0x801C6114: sb          $v1, 0xEF7($s0)
        MEM_B(0XEF7, ctx->r16) = ctx->r3;
            goto L_801C6120;
    }
    // 0x801C6114: sb          $v1, 0xEF7($s0)
    MEM_B(0XEF7, ctx->r16) = ctx->r3;
    // 0x801C6118: b           L_801C7770
    // 0x801C611C: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C611C: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C6120:
    // 0x801C6120: bnel        $s5, $v1, L_801C6134
    if (ctx->r21 != ctx->r3) {
        // 0x801C6124: lwc1        $f0, 0x35C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X35C);
            goto L_801C6134;
    }
    goto skip_36;
    // 0x801C6124: lwc1        $f0, 0x35C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X35C);
    skip_36:
    // 0x801C6128: b           L_801C7770
    // 0x801C612C: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C612C: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    // 0x801C6130: lwc1        $f0, 0x35C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X35C);
L_801C6134:
    // 0x801C6134: lwc1        $f14, 0x360($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X360);
    // 0x801C6138: lwc1        $f2, 0x364($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X364);
    // 0x801C613C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C6140: nop

    // 0x801C6144: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C6148: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801C614C: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C6150: jal         0x8002FC20
    // 0x801C6154: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_9;
    // 0x801C6154: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    after_9:
    // 0x801C6158: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801C615C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C6160: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C6164: c.eq.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d == ctx->f4.d;
    // 0x801C6168: nop

    // 0x801C616C: bc1tl       L_801C6190
    if (c1cs) {
        // 0x801C6170: lwc1        $f12, 0x368($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
            goto L_801C6190;
    }
    goto skip_37;
    // 0x801C6170: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
    skip_37:
    // 0x801C6174: lwc1        $f10, 0x35C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X35C);
    // 0x801C6178: lwc1        $f18, 0x360($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X360);
    // 0x801C617C: lwc1        $f8, 0x364($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X364);
    // 0x801C6180: swc1        $f10, 0xEE4($s0)
    MEM_W(0XEE4, ctx->r16) = ctx->f10.u32l;
    // 0x801C6184: swc1        $f18, 0xEE8($s0)
    MEM_W(0XEE8, ctx->r16) = ctx->f18.u32l;
    // 0x801C6188: swc1        $f8, 0xEEC($s0)
    MEM_W(0XEEC, ctx->r16) = ctx->f8.u32l;
    // 0x801C618C: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
L_801C6190:
    // 0x801C6190: c.lt.s      $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f12.fl < ctx->f26.fl;
    // 0x801C6194: nop

    // 0x801C6198: bc1fl       L_801C61AC
    if (!c1cs) {
        // 0x801C619C: mov.s       $f24, $f12
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
            goto L_801C61AC;
    }
    goto skip_38;
    // 0x801C619C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    skip_38:
    // 0x801C61A0: b           L_801C61AC
    // 0x801C61A4: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
        goto L_801C61AC;
    // 0x801C61A4: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
    // 0x801C61A8: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
L_801C61AC:
    // 0x801C61AC: c.lt.s      $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f30.fl < ctx->f26.fl;
    // 0x801C61B0: nop

    // 0x801C61B4: bc1fl       L_801C61C8
    if (!c1cs) {
        // 0x801C61B8: mov.s       $f0, $f30
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
            goto L_801C61C8;
    }
    goto skip_39;
    // 0x801C61B8: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
    skip_39:
    // 0x801C61BC: b           L_801C61C8
    // 0x801C61C0: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
        goto L_801C61C8;
    // 0x801C61C0: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
    // 0x801C61C4: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
L_801C61C8:
    // 0x801C61C8: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C61CC: nop

    // 0x801C61D0: bc1fl       L_801C61E0
    if (!c1cs) {
        // 0x801C61D4: lwc1        $f2, 0x370($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
            goto L_801C61E0;
    }
    goto skip_40;
    // 0x801C61D4: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
    skip_40:
    // 0x801C61D8: mov.s       $f30, $f12
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    ctx->f30.fl = ctx->f12.fl;
    // 0x801C61DC: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
L_801C61E0:
    // 0x801C61E0: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
    // 0x801C61E4: nop

    // 0x801C61E8: bc1fl       L_801C61FC
    if (!c1cs) {
        // 0x801C61EC: mov.s       $f24, $f2
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
            goto L_801C61FC;
    }
    goto skip_41;
    // 0x801C61EC: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
    skip_41:
    // 0x801C61F0: b           L_801C61FC
    // 0x801C61F4: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
        goto L_801C61FC;
    // 0x801C61F4: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
    // 0x801C61F8: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_801C61FC:
    // 0x801C61FC: c.lt.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl < ctx->f26.fl;
    // 0x801C6200: nop

    // 0x801C6204: bc1fl       L_801C6218
    if (!c1cs) {
        // 0x801C6208: mov.s       $f0, $f28
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
            goto L_801C6218;
    }
    goto skip_42;
    // 0x801C6208: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
    skip_42:
    // 0x801C620C: b           L_801C6218
    // 0x801C6210: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
        goto L_801C6218;
    // 0x801C6210: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
    // 0x801C6214: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_801C6218:
    // 0x801C6218: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C621C: nop

    // 0x801C6220: bc1fl       L_801C6230
    if (!c1cs) {
        // 0x801C6224: c.eq.s      $f26, $f12
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
            goto L_801C6230;
    }
    goto skip_43;
    // 0x801C6224: c.eq.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
    skip_43:
    // 0x801C6228: mov.s       $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
    // 0x801C622C: c.eq.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
L_801C6230:
    // 0x801C6230: nop

    // 0x801C6234: bc1fl       L_801C6250
    if (!c1cs) {
        // 0x801C6238: lw          $t7, 0xEC4($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XEC4);
            goto L_801C6250;
    }
    goto skip_44;
    // 0x801C6238: lw          $t7, 0xEC4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XEC4);
    skip_44:
    // 0x801C623C: c.eq.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl == ctx->f2.fl;
    // 0x801C6240: nop

    // 0x801C6244: bc1tl       L_801C6260
    if (c1cs) {
        // 0x801C6248: lhu         $t0, 0xEF0($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0XEF0);
            goto L_801C6260;
    }
    goto skip_45;
    // 0x801C6248: lhu         $t0, 0xEF0($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XEF0);
    skip_45:
    // 0x801C624C: lw          $t7, 0xEC4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XEC4);
L_801C6250:
    // 0x801C6250: lhu         $t8, 0x0($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X0);
    // 0x801C6254: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x801C6258: sw          $t9, 0xEC4($s0)
    MEM_W(0XEC4, ctx->r16) = ctx->r25;
    // 0x801C625C: lhu         $t0, 0xEF0($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XEF0);
L_801C6260:
    // 0x801C6260: andi        $t1, $t0, 0x1000
    ctx->r9 = ctx->r8 & 0X1000;
    // 0x801C6264: bne         $t1, $zero, L_801C6D3C
    if (ctx->r9 != 0) {
        // 0x801C6268: nop
    
            goto L_801C6D3C;
    }
    // 0x801C6268: nop

    // 0x801C626C: lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1C);
    // 0x801C6270: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C6274: ori         $at, $at, 0x4C
    ctx->r1 = ctx->r1 | 0X4C;
    // 0x801C6278: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C627C: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C6D3C;
    }
    // 0x801C627C: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C6280: ori         $at, $at, 0x4F
    ctx->r1 = ctx->r1 | 0X4F;
    // 0x801C6284: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C6288: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C6D3C;
    }
    // 0x801C6288: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C628C: ori         $at, $at, 0x50
    ctx->r1 = ctx->r1 | 0X50;
    // 0x801C6290: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C6294: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C6D3C;
    }
    // 0x801C6294: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C6298: ori         $at, $at, 0x2A
    ctx->r1 = ctx->r1 | 0X2A;
    // 0x801C629C: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C62A0: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C6D3C;
    }
    // 0x801C62A0: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C62A4: ori         $at, $at, 0x53
    ctx->r1 = ctx->r1 | 0X53;
    // 0x801C62A8: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C62AC: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C6D3C;
    }
    // 0x801C62AC: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C62B0: ori         $at, $at, 0x3A
    ctx->r1 = ctx->r1 | 0X3A;
    // 0x801C62B4: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C62B8: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C6D3C;
    }
    // 0x801C62B8: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C62BC: ori         $at, $at, 0x3B
    ctx->r1 = ctx->r1 | 0X3B;
    // 0x801C62C0: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C62C4: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C6D3C;
    }
    // 0x801C62C4: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C62C8: ori         $at, $at, 0x51
    ctx->r1 = ctx->r1 | 0X51;
    // 0x801C62CC: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C62D0: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C6D3C;
    }
    // 0x801C62D0: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C62D4: ori         $at, $at, 0x52
    ctx->r1 = ctx->r1 | 0X52;
    // 0x801C62D8: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C62DC: nop
    
            goto L_801C6D3C;
    }
    // 0x801C62DC: nop

    // 0x801C62E0: lw          $t2, 0xEF8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XEF8);
    // 0x801C62E4: bne         $t2, $zero, L_801C6D3C
    if (ctx->r10 != 0) {
        // 0x801C62E8: nop
    
            goto L_801C6D3C;
    }
    // 0x801C62E8: nop

    // 0x801C62EC: jal         0x80126944
    // 0x801C62F0: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_10;
    // 0x801C62F0: nop

    after_10:
    // 0x801C62F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C62F8: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C62FC: nop
    
            goto L_801C6D3C;
    }
    // 0x801C62FC: nop

    // 0x801C6300: lhu         $v0, 0xEF0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C6304: andi        $t3, $v0, 0x1000
    ctx->r11 = ctx->r2 & 0X1000;
    // 0x801C6308: bne         $t3, $zero, L_801C6384
    if (ctx->r11 != 0) {
        // 0x801C630C: andi        $t4, $v0, 0x8000
        ctx->r12 = ctx->r2 & 0X8000;
            goto L_801C6384;
    }
    // 0x801C630C: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    // 0x801C6310: bnel        $t4, $zero, L_801C6388
    if (ctx->r12 != 0) {
        // 0x801C6314: lbu         $v0, 0x35A($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X35A);
            goto L_801C6388;
    }
    goto skip_46;
    // 0x801C6314: lbu         $v0, 0x35A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35A);
    skip_46:
    // 0x801C6318: lbu         $t5, 0x35A($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C631C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801C6320: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801C6324: bnel        $t5, $at, L_801C6388
    if (ctx->r13 != ctx->r1) {
        // 0x801C6328: lbu         $v0, 0x35A($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X35A);
            goto L_801C6388;
    }
    goto skip_47;
    // 0x801C6328: lbu         $v0, 0x35A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35A);
    skip_47:
    // 0x801C632C: lhu         $t6, -0x23BE($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X23BE);
    // 0x801C6330: ori         $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 | 0X8000;
    // 0x801C6334: blez        $t6, L_801C637C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801C6338: nop
    
            goto L_801C637C;
    }
    // 0x801C6338: nop

    // 0x801C633C: lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1C);
    // 0x801C6340: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C6344: ori         $at, $at, 0x12
    ctx->r1 = ctx->r1 | 0X12;
    // 0x801C6348: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C634C: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C6D3C;
    }
    // 0x801C634C: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C6350: ori         $at, $at, 0x13
    ctx->r1 = ctx->r1 | 0X13;
    // 0x801C6354: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C6358: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C6D3C;
    }
    // 0x801C6358: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C635C: ori         $at, $at, 0x14
    ctx->r1 = ctx->r1 | 0X14;
    // 0x801C6360: beq         $v0, $at, L_801C6D3C
    if (ctx->r2 == ctx->r1) {
        // 0x801C6364: nop
    
            goto L_801C6D3C;
    }
    // 0x801C6364: nop

    // 0x801C6368: jal         0x801C3B7C
    // 0x801C636C: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_11;
    // 0x801C636C: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    after_11:
    // 0x801C6370: lhu         $t7, 0xEF0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C6374: b           L_801C776C
    // 0x801C6378: sh          $t7, 0xEF2($s0)
    MEM_H(0XEF2, ctx->r16) = ctx->r15;
        goto L_801C776C;
    // 0x801C6378: sh          $t7, 0xEF2($s0)
    MEM_H(0XEF2, ctx->r16) = ctx->r15;
L_801C637C:
    // 0x801C637C: b           L_801C776C
    // 0x801C6380: sh          $t8, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r24;
        goto L_801C776C;
    // 0x801C6380: sh          $t8, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r24;
L_801C6384:
    // 0x801C6384: lbu         $v0, 0x35A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35A);
L_801C6388:
    // 0x801C6388: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x801C638C: bne         $v0, $at, L_801C639C
    if (ctx->r2 != ctx->r1) {
        // 0x801C6390: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C639C;
    }
    // 0x801C6390: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C6394: b           L_801C7770
    // 0x801C6398: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C6398: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C639C:
    // 0x801C639C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801C63A0: bnel        $v1, $at, L_801C6680
    if (ctx->r3 != ctx->r1) {
        // 0x801C63A4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_801C6680;
    }
    goto skip_48;
    // 0x801C63A4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    skip_48:
    // 0x801C63A8: lw          $t9, 0xEC4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XEC4);
    // 0x801C63AC: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x801C63B0: beql        $t0, $zero, L_801C6680
    if (ctx->r8 == 0) {
        // 0x801C63B4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_801C6680;
    }
    goto skip_49;
    // 0x801C63B4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    skip_49:
    // 0x801C63B8: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x801C63BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C63C0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801C63C4: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    // 0x801C63C8: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C63CC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C63D0: jal         0x8001EAD0
    // 0x801C63D4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_12;
    // 0x801C63D4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_12:
    // 0x801C63D8: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C63DC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C63E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C63E4: lhu         $t3, 0x2($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X2);
    // 0x801C63E8: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x801C63EC: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801C63F0: mul.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x801C63F4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801C63F8: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x801C63FC: lwc1        $f10, 0xD40($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XD40);
    // 0x801C6400: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C6404: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    // 0x801C6408: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x801C640C: add.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f4.d + ctx->f18.d;
    // 0x801C6410: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C6414: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C6418: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801C641C: jal         0x8001EB64
    // 0x801C6420: cvt.s.d     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f22.fl = CVT_S_D(ctx->f8.d);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_13;
    // 0x801C6420: cvt.s.d     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f22.fl = CVT_S_D(ctx->f8.d);
    after_13:
    // 0x801C6424: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C6428: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C642C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C6430: lhu         $t8, 0x2($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6434: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x801C6438: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x801C643C: mul.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x801C6440: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C6444: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x801C6448: lwc1        $f4, 0xDC0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XDC0);
    // 0x801C644C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801C6450: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x801C6454: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    // 0x801C6458: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x801C645C: jal         0x8001EAD0
    // 0x801C6460: cvt.s.d     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f20.fl = CVT_S_D(ctx->f8.d);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_14;
    // 0x801C6460: cvt.s.d     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f20.fl = CVT_S_D(ctx->f8.d);
    after_14:
    // 0x801C6464: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801C6468: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801C646C: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801C6470: jal         0x8001EB64
    // 0x801C6474: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_15;
    // 0x801C6474: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_15:
    // 0x801C6478: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x801C647C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801C6480: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C6484: cvt.d.s     $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f16.d = CVT_D_S(ctx->f24.fl);
    // 0x801C6488: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x801C648C: mul.d       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f2.d);
    // 0x801C6490: lhu         $t5, 0x2($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6494: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C6498: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801C649C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801C64A0: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x801C64A4: lwc1        $f8, 0xE40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C64A8: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C64AC: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x801C64B0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x801C64B4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C64B8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x801C64BC: mul.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801C64C0: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801C64C4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801C64C8: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x801C64CC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801C64D0: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x801C64D4: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801C64D8: jal         0x801C5A1C
    // 0x801C64DC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_16;
    // 0x801C64DC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x801C64E0: beql        $v0, $zero, L_801C6500
    if (ctx->r2 == 0) {
        // 0x801C64E4: lw          $t8, 0xE0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XE0);
            goto L_801C6500;
    }
    goto skip_50;
    // 0x801C64E4: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    skip_50:
    // 0x801C64E8: lbu         $t7, 0x35A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C64EC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801C64F0: bnel        $t7, $at, L_801C6500
    if (ctx->r15 != ctx->r1) {
        // 0x801C64F4: lw          $t8, 0xE0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XE0);
            goto L_801C6500;
    }
    goto skip_51;
    // 0x801C64F4: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    skip_51:
    // 0x801C64F8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801C64FC: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
L_801C6500:
    // 0x801C6500: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C6504: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    // 0x801C6508: addiu       $a0, $a0, 0x1800
    ctx->r4 = ADD32(ctx->r4, 0X1800);
    // 0x801C650C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C6510: jal         0x8001EAD0
    // 0x801C6514: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_17;
    // 0x801C6514: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_17:
    // 0x801C6518: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C651C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C6520: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C6524: lhu         $t0, 0x2($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6528: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C652C: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801C6530: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x801C6534: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801C6538: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x801C653C: lwc1        $f18, 0xD40($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XD40);
    // 0x801C6540: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801C6544: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    // 0x801C6548: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x801C654C: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x801C6550: addiu       $a0, $a0, 0x1800
    ctx->r4 = ADD32(ctx->r4, 0X1800);
    // 0x801C6554: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C6558: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801C655C: jal         0x8001EB64
    // 0x801C6560: cvt.s.d     $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f22.fl = CVT_S_D(ctx->f16.d);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_18;
    // 0x801C6560: cvt.s.d     $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f22.fl = CVT_S_D(ctx->f16.d);
    after_18:
    // 0x801C6564: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C6568: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C656C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C6570: lhu         $t5, 0x2($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6574: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C6578: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801C657C: mul.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x801C6580: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801C6584: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x801C6588: lwc1        $f10, 0xDC0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XDC0);
    // 0x801C658C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C6590: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C6594: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    // 0x801C6598: add.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f18.d + ctx->f8.d;
    // 0x801C659C: jal         0x8001EAD0
    // 0x801C65A0: cvt.s.d     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f20.fl = CVT_S_D(ctx->f16.d);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_19;
    // 0x801C65A0: cvt.s.d     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f20.fl = CVT_S_D(ctx->f16.d);
    after_19:
    // 0x801C65A4: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x801C65A8: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801C65AC: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C65B0: jal         0x8001EB64
    // 0x801C65B4: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_20;
    // 0x801C65B4: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_20:
    // 0x801C65B8: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x801C65BC: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801C65C0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C65C4: cvt.d.s     $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f6.d = CVT_D_S(ctx->f24.fl);
    // 0x801C65C8: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x801C65CC: mul.d       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x801C65D0: lhu         $t2, 0x2($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X2);
    // 0x801C65D4: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C65D8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801C65DC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801C65E0: addu        $v0, $s0, $t3
    ctx->r2 = ADD32(ctx->r16, ctx->r11);
    // 0x801C65E4: lwc1        $f16, 0xE40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C65E8: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C65EC: add.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f4.d + ctx->f10.d;
    // 0x801C65F0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x801C65F4: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801C65F8: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x801C65FC: mul.d       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801C6600: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x801C6604: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801C6608: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x801C660C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801C6610: add.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f18.d + ctx->f8.d;
    // 0x801C6614: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x801C6618: jal         0x801C5A1C
    // 0x801C661C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_21;
    // 0x801C661C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_21:
    // 0x801C6620: beql        $v0, $zero, L_801C6644
    if (ctx->r2 == 0) {
        // 0x801C6624: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801C6644;
    }
    goto skip_52;
    // 0x801C6624: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_52:
    // 0x801C6628: lbu         $t4, 0x35A($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C662C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801C6630: bnel        $t4, $at, L_801C6644
    if (ctx->r12 != ctx->r1) {
        // 0x801C6634: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801C6644;
    }
    goto skip_53;
    // 0x801C6634: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_53:
    // 0x801C6638: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x801C663C: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C6640: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801C6644:
    // 0x801C6644: beq         $s1, $at, L_801C6D3C
    if (ctx->r17 == ctx->r1) {
        // 0x801C6648: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801C6D3C;
    }
    // 0x801C6648: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C664C: beq         $s1, $at, L_801C6D3C
    if (ctx->r17 == ctx->r1) {
        // 0x801C6650: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801C6D3C;
    }
    // 0x801C6650: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C6654: bne         $s1, $at, L_801C6D3C
    if (ctx->r17 != ctx->r1) {
        // 0x801C6658: nop
    
            goto L_801C6D3C;
    }
    // 0x801C6658: nop

    // 0x801C665C: lbu         $t5, 0xEF5($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XEF5);
    // 0x801C6660: addiu       $t7, $s1, 0x27
    ctx->r15 = ADD32(ctx->r17, 0X27);
    // 0x801C6664: bne         $t5, $zero, L_801C6D3C
    if (ctx->r13 != 0) {
        // 0x801C6668: nop
    
            goto L_801C6D3C;
    }
    // 0x801C6668: nop

    // 0x801C666C: lw          $t6, 0x38C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38C);
    // 0x801C6670: sb          $t7, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r15;
    // 0x801C6674: b           L_801C776C
    // 0x801C6678: sw          $t6, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = ctx->r14;
        goto L_801C776C;
    // 0x801C6678: sw          $t6, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = ctx->r14;
    // 0x801C667C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
L_801C6680:
    // 0x801C6680: bnel        $v1, $at, L_801C6960
    if (ctx->r3 != ctx->r1) {
        // 0x801C6684: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_801C6960;
    }
    goto skip_54;
    // 0x801C6684: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    skip_54:
    // 0x801C6688: lw          $t8, 0xEC4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XEC4);
    // 0x801C668C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x801C6690: beql        $t9, $zero, L_801C6960
    if (ctx->r25 == 0) {
        // 0x801C6694: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_801C6960;
    }
    goto skip_55;
    // 0x801C6694: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    skip_55:
    // 0x801C6698: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x801C669C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C66A0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C66A4: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    // 0x801C66A8: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C66AC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C66B0: jal         0x8001EAD0
    // 0x801C66B4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_22;
    // 0x801C66B4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_22:
    // 0x801C66B8: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C66BC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C66C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C66C4: lhu         $t2, 0x2($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X2);
    // 0x801C66C8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C66CC: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
    // 0x801C66D0: mul.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x801C66D4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801C66D8: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x801C66DC: lwc1        $f8, 0xD40($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XD40);
    // 0x801C66E0: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801C66E4: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    // 0x801C66E8: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801C66EC: add.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f18.d + ctx->f16.d;
    // 0x801C66F0: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C66F4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C66F8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801C66FC: jal         0x8001EB64
    // 0x801C6700: cvt.s.d     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f22.fl = CVT_S_D(ctx->f6.d);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_23;
    // 0x801C6700: cvt.s.d     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f22.fl = CVT_S_D(ctx->f6.d);
    after_23:
    // 0x801C6704: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C6708: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C670C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C6710: lhu         $t7, 0x2($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6714: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C6718: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x801C671C: mul.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x801C6720: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801C6724: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x801C6728: lwc1        $f18, 0xDC0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XDC0);
    // 0x801C672C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C6730: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x801C6734: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    // 0x801C6738: add.d       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f8.d + ctx->f16.d;
    // 0x801C673C: jal         0x8001EAD0
    // 0x801C6740: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_24;
    // 0x801C6740: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    after_24:
    // 0x801C6744: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801C6748: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801C674C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C6750: jal         0x8001EB64
    // 0x801C6754: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_25;
    // 0x801C6754: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_25:
    // 0x801C6758: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x801C675C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801C6760: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C6764: cvt.d.s     $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f4.d = CVT_D_S(ctx->f24.fl);
    // 0x801C6768: cvt.d.s     $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f18.d = CVT_D_S(ctx->f22.fl);
    // 0x801C676C: mul.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801C6770: lhu         $t4, 0x2($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6774: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C6778: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801C677C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801C6780: addu        $v0, $s0, $t5
    ctx->r2 = ADD32(ctx->r16, ctx->r13);
    // 0x801C6784: lwc1        $f6, 0xE40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C6788: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C678C: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x801C6790: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x801C6794: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801C6798: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801C679C: mul.d       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x801C67A0: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801C67A4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801C67A8: cvt.d.s     $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f16.d = CVT_D_S(ctx->f20.fl);
    // 0x801C67AC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801C67B0: add.d       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f8.d + ctx->f16.d;
    // 0x801C67B4: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801C67B8: jal         0x801C5A1C
    // 0x801C67BC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_26;
    // 0x801C67BC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_26:
    // 0x801C67C0: beql        $v0, $zero, L_801C67E0
    if (ctx->r2 == 0) {
        // 0x801C67C4: lw          $t7, 0xE0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XE0);
            goto L_801C67E0;
    }
    goto skip_56;
    // 0x801C67C4: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    skip_56:
    // 0x801C67C8: lbu         $t6, 0x35A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C67CC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x801C67D0: bnel        $t6, $at, L_801C67E0
    if (ctx->r14 != ctx->r1) {
        // 0x801C67D4: lw          $t7, 0xE0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XE0);
            goto L_801C67E0;
    }
    goto skip_57;
    // 0x801C67D4: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    skip_57:
    // 0x801C67D8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801C67DC: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
L_801C67E0:
    // 0x801C67E0: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C67E4: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    // 0x801C67E8: addiu       $a0, $a0, 0x1800
    ctx->r4 = ADD32(ctx->r4, 0X1800);
    // 0x801C67EC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C67F0: jal         0x8001EAD0
    // 0x801C67F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_27;
    // 0x801C67F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_27:
    // 0x801C67F8: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C67FC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C6800: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C6804: lhu         $t9, 0x2($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6808: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801C680C: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801C6810: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801C6814: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801C6818: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x801C681C: lwc1        $f16, 0xD40($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XD40);
    // 0x801C6820: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C6824: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    // 0x801C6828: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x801C682C: add.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f8.d + ctx->f6.d;
    // 0x801C6830: addiu       $a0, $a0, 0x1800
    ctx->r4 = ADD32(ctx->r4, 0X1800);
    // 0x801C6834: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C6838: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801C683C: jal         0x8001EB64
    // 0x801C6840: cvt.s.d     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f22.fl = CVT_S_D(ctx->f4.d);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_28;
    // 0x801C6840: cvt.s.d     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f22.fl = CVT_S_D(ctx->f4.d);
    after_28:
    // 0x801C6844: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C6848: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C684C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C6850: lhu         $t4, 0x2($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6854: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801C6858: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801C685C: mul.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801C6860: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801C6864: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x801C6868: lwc1        $f8, 0xDC0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XDC0);
    // 0x801C686C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C6870: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801C6874: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    // 0x801C6878: add.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f16.d + ctx->f6.d;
    // 0x801C687C: jal         0x8001EAD0
    // 0x801C6880: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_29;
    // 0x801C6880: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
    after_29:
    // 0x801C6884: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x801C6888: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801C688C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801C6890: jal         0x8001EB64
    // 0x801C6894: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_30;
    // 0x801C6894: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_30:
    // 0x801C6898: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x801C689C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801C68A0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C68A4: cvt.d.s     $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f10.d = CVT_D_S(ctx->f24.fl);
    // 0x801C68A8: cvt.d.s     $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f8.d = CVT_D_S(ctx->f22.fl);
    // 0x801C68AC: mul.d       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801C68B0: lhu         $t1, 0x2($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X2);
    // 0x801C68B4: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C68B8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801C68BC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801C68C0: addu        $v0, $s0, $t2
    ctx->r2 = ADD32(ctx->r16, ctx->r10);
    // 0x801C68C4: lwc1        $f4, 0xE40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C68C8: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C68CC: add.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f18.d + ctx->f8.d;
    // 0x801C68D0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x801C68D4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801C68D8: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x801C68DC: mul.d       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x801C68E0: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801C68E4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801C68E8: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x801C68EC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801C68F0: add.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f16.d + ctx->f6.d;
    // 0x801C68F4: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801C68F8: jal         0x801C5A1C
    // 0x801C68FC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_31;
    // 0x801C68FC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_31:
    // 0x801C6900: beql        $v0, $zero, L_801C6924
    if (ctx->r2 == 0) {
        // 0x801C6904: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801C6924;
    }
    goto skip_58;
    // 0x801C6904: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_58:
    // 0x801C6908: lbu         $t3, 0x35A($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C690C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x801C6910: bnel        $t3, $at, L_801C6924
    if (ctx->r11 != ctx->r1) {
        // 0x801C6914: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801C6924;
    }
    goto skip_59;
    // 0x801C6914: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_59:
    // 0x801C6918: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x801C691C: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C6920: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801C6924:
    // 0x801C6924: beq         $s1, $at, L_801C6D3C
    if (ctx->r17 == ctx->r1) {
        // 0x801C6928: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801C6D3C;
    }
    // 0x801C6928: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C692C: beq         $s1, $at, L_801C6D3C
    if (ctx->r17 == ctx->r1) {
        // 0x801C6930: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801C6D3C;
    }
    // 0x801C6930: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C6934: bne         $s1, $at, L_801C6D3C
    if (ctx->r17 != ctx->r1) {
        // 0x801C6938: nop
    
            goto L_801C6D3C;
    }
    // 0x801C6938: nop

    // 0x801C693C: lbu         $t4, 0xEF5($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XEF5);
    // 0x801C6940: addiu       $t6, $s1, 0x2A
    ctx->r14 = ADD32(ctx->r17, 0X2A);
    // 0x801C6944: bne         $t4, $zero, L_801C6D3C
    if (ctx->r12 != 0) {
        // 0x801C6948: nop
    
            goto L_801C6D3C;
    }
    // 0x801C6948: nop

    // 0x801C694C: lw          $t5, 0x38C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38C);
    // 0x801C6950: sb          $t6, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r14;
    // 0x801C6954: b           L_801C776C
    // 0x801C6958: sw          $t5, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = ctx->r13;
        goto L_801C776C;
    // 0x801C6958: sw          $t5, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = ctx->r13;
    // 0x801C695C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
L_801C6960:
    // 0x801C6960: bnel        $v1, $at, L_801C698C
    if (ctx->r3 != ctx->r1) {
        // 0x801C6964: addiu       $at, $zero, 0x1C
        ctx->r1 = ADD32(0, 0X1C);
            goto L_801C698C;
    }
    goto skip_60;
    // 0x801C6964: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    skip_60:
    // 0x801C6968: lbu         $t7, 0xEF5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XEF5);
    // 0x801C696C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x801C6970: bne         $t7, $zero, L_801C6D3C
    if (ctx->r15 != 0) {
        // 0x801C6974: nop
    
            goto L_801C6D3C;
    }
    // 0x801C6974: nop

    // 0x801C6978: lw          $t8, 0x38C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38C);
    // 0x801C697C: sb          $t9, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r25;
    // 0x801C6980: b           L_801C776C
    // 0x801C6984: sw          $t8, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = ctx->r24;
        goto L_801C776C;
    // 0x801C6984: sw          $t8, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = ctx->r24;
    // 0x801C6988: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
L_801C698C:
    // 0x801C698C: beq         $v1, $at, L_801C699C
    if (ctx->r3 == ctx->r1) {
        // 0x801C6990: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_801C699C;
    }
    // 0x801C6990: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x801C6994: bnel        $v1, $at, L_801C6C7C
    if (ctx->r3 != ctx->r1) {
        // 0x801C6998: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_801C6C7C;
    }
    goto skip_61;
    // 0x801C6998: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_61:
L_801C699C:
    // 0x801C699C: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x801C69A0: sb          $v0, 0x93($sp)
    MEM_B(0X93, ctx->r29) = ctx->r2;
    // 0x801C69A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C69A8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C69AC: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    // 0x801C69B0: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C69B4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C69B8: jal         0x8001EAD0
    // 0x801C69BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_32;
    // 0x801C69BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_32:
    // 0x801C69C0: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C69C4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C69C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C69CC: lhu         $t2, 0x2($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X2);
    // 0x801C69D0: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801C69D4: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
    // 0x801C69D8: mul.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x801C69DC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801C69E0: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x801C69E4: lwc1        $f6, 0xD40($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XD40);
    // 0x801C69E8: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801C69EC: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    // 0x801C69F0: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801C69F4: add.d       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f16.d + ctx->f4.d;
    // 0x801C69F8: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C69FC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C6A00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801C6A04: jal         0x8001EB64
    // 0x801C6A08: cvt.s.d     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f22.fl = CVT_S_D(ctx->f10.d);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_33;
    // 0x801C6A08: cvt.s.d     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f22.fl = CVT_S_D(ctx->f10.d);
    after_33:
    // 0x801C6A0C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C6A10: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C6A14: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C6A18: lhu         $t7, 0x2($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6A1C: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801C6A20: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x801C6A24: mul.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x801C6A28: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801C6A2C: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x801C6A30: lwc1        $f16, 0xDC0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XDC0);
    // 0x801C6A34: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C6A38: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801C6A3C: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    // 0x801C6A40: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x801C6A44: jal         0x8001EAD0
    // 0x801C6A48: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_34;
    // 0x801C6A48: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    after_34:
    // 0x801C6A4C: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801C6A50: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801C6A54: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C6A58: jal         0x8001EB64
    // 0x801C6A5C: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_35;
    // 0x801C6A5C: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_35:
    // 0x801C6A60: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x801C6A64: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C6A68: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C6A6C: cvt.d.s     $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f18.d = CVT_D_S(ctx->f24.fl);
    // 0x801C6A70: cvt.d.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.d = CVT_D_S(ctx->f22.fl);
    // 0x801C6A74: mul.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x801C6A78: lhu         $t4, 0x2($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6A7C: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C6A80: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801C6A84: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801C6A88: addu        $v0, $s0, $t5
    ctx->r2 = ADD32(ctx->r16, ctx->r13);
    // 0x801C6A8C: lwc1        $f18, 0xE40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C6A90: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C6A94: add.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f16.d + ctx->f6.d;
    // 0x801C6A98: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x801C6A9C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C6AA0: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801C6AA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C6AA8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C6AAC: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801C6AB0: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801C6AB4: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x801C6AB8: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x801C6ABC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801C6AC0: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x801C6AC4: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801C6AC8: jal         0x801C5A1C
    // 0x801C6ACC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_36;
    // 0x801C6ACC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_36:
    // 0x801C6AD0: beq         $v0, $zero, L_801C6AE8
    if (ctx->r2 == 0) {
        // 0x801C6AD4: lbu         $t6, 0x93($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X93);
            goto L_801C6AE8;
    }
    // 0x801C6AD4: lbu         $t6, 0x93($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X93);
    // 0x801C6AD8: lbu         $t7, 0x35A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C6ADC: bnel        $t6, $t7, L_801C6AEC
    if (ctx->r14 != ctx->r15) {
        // 0x801C6AE0: lw          $t8, 0xE0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XE0);
            goto L_801C6AEC;
    }
    goto skip_62;
    // 0x801C6AE0: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    skip_62:
    // 0x801C6AE4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_801C6AE8:
    // 0x801C6AE8: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
L_801C6AEC:
    // 0x801C6AEC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C6AF0: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    // 0x801C6AF4: addiu       $a0, $a0, 0x1800
    ctx->r4 = ADD32(ctx->r4, 0X1800);
    // 0x801C6AF8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C6AFC: jal         0x8001EAD0
    // 0x801C6B00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_37;
    // 0x801C6B00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_37:
    // 0x801C6B04: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C6B08: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C6B0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C6B10: lhu         $t0, 0x2($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6B14: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C6B18: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    // 0x801C6B1C: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x801C6B20: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801C6B24: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x801C6B28: lwc1        $f18, 0xD40($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XD40);
    // 0x801C6B2C: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801C6B30: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    // 0x801C6B34: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x801C6B38: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x801C6B3C: addiu       $a0, $a0, 0x1800
    ctx->r4 = ADD32(ctx->r4, 0X1800);
    // 0x801C6B40: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C6B44: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801C6B48: jal         0x8001EB64
    // 0x801C6B4C: cvt.s.d     $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f22.fl = CVT_S_D(ctx->f16.d);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_38;
    // 0x801C6B4C: cvt.s.d     $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f22.fl = CVT_S_D(ctx->f16.d);
    after_38:
    // 0x801C6B50: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801C6B54: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C6B58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C6B5C: lhu         $t5, 0x2($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6B60: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C6B64: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801C6B68: mul.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x801C6B6C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801C6B70: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x801C6B74: lwc1        $f10, 0xDC0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XDC0);
    // 0x801C6B78: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C6B7C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C6B80: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    // 0x801C6B84: add.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f18.d + ctx->f8.d;
    // 0x801C6B88: jal         0x8001EAD0
    // 0x801C6B8C: cvt.s.d     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f20.fl = CVT_S_D(ctx->f16.d);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_39;
    // 0x801C6B8C: cvt.s.d     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f20.fl = CVT_S_D(ctx->f16.d);
    after_39:
    // 0x801C6B90: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x801C6B94: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801C6B98: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801C6B9C: jal         0x8001EB64
    // 0x801C6BA0: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_40;
    // 0x801C6BA0: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_40:
    // 0x801C6BA4: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x801C6BA8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C6BAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C6BB0: cvt.d.s     $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f6.d = CVT_D_S(ctx->f24.fl);
    // 0x801C6BB4: cvt.d.s     $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f18.d = CVT_D_S(ctx->f22.fl);
    // 0x801C6BB8: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x801C6BBC: lhu         $t2, 0x2($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6BC0: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C6BC4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801C6BC8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801C6BCC: addu        $v0, $s0, $t3
    ctx->r2 = ADD32(ctx->r16, ctx->r11);
    // 0x801C6BD0: lwc1        $f6, 0xE40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C6BD4: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C6BD8: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x801C6BDC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x801C6BE0: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801C6BE4: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801C6BE8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C6BEC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C6BF0: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801C6BF4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801C6BF8: mul.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x801C6BFC: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x801C6C00: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801C6C04: add.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f16.d + ctx->f6.d;
    // 0x801C6C08: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801C6C0C: jal         0x801C5A1C
    // 0x801C6C10: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_41;
    // 0x801C6C10: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_41:
    // 0x801C6C14: beq         $v0, $zero, L_801C6C34
    if (ctx->r2 == 0) {
        // 0x801C6C18: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801C6C34;
    }
    // 0x801C6C18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C6C1C: lbu         $t4, 0x93($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X93);
    // 0x801C6C20: lbu         $t5, 0x35A($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C6C24: bne         $t4, $t5, L_801C6C34
    if (ctx->r12 != ctx->r13) {
        // 0x801C6C28: nop
    
            goto L_801C6C34;
    }
    // 0x801C6C28: nop

    // 0x801C6C2C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x801C6C30: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
L_801C6C34:
    // 0x801C6C34: beq         $s1, $at, L_801C6D3C
    if (ctx->r17 == ctx->r1) {
        // 0x801C6C38: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801C6D3C;
    }
    // 0x801C6C38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C6C3C: beq         $s1, $at, L_801C6D3C
    if (ctx->r17 == ctx->r1) {
        // 0x801C6C40: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801C6D3C;
    }
    // 0x801C6C40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C6C44: bne         $s1, $at, L_801C6D3C
    if (ctx->r17 != ctx->r1) {
        // 0x801C6C48: nop
    
            goto L_801C6D3C;
    }
    // 0x801C6C48: nop

    // 0x801C6C4C: lbu         $t6, 0xEF5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XEF5);
    // 0x801C6C50: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x801C6C54: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    // 0x801C6C58: bne         $t6, $zero, L_801C6C70
    if (ctx->r14 != 0) {
        // 0x801C6C5C: nop
    
            goto L_801C6C70;
    }
    // 0x801C6C5C: nop

    // 0x801C6C60: lw          $t7, 0x38C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38C);
    // 0x801C6C64: sb          $t8, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r24;
    // 0x801C6C68: b           L_801C776C
    // 0x801C6C6C: sw          $t7, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = ctx->r15;
        goto L_801C776C;
    // 0x801C6C6C: sw          $t7, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = ctx->r15;
L_801C6C70:
    // 0x801C6C70: b           L_801C776C
    // 0x801C6C74: sb          $t9, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r25;
        goto L_801C776C;
    // 0x801C6C74: sb          $t9, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r25;
    // 0x801C6C78: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_801C6C7C:
    // 0x801C6C7C: bnel        $v1, $at, L_801C6CA8
    if (ctx->r3 != ctx->r1) {
        // 0x801C6C80: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_801C6CA8;
    }
    goto skip_63;
    // 0x801C6C80: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_63:
    // 0x801C6C84: lbu         $t0, 0xEF5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XEF5);
    // 0x801C6C88: addiu       $t2, $zero, 0xB
    ctx->r10 = ADD32(0, 0XB);
    // 0x801C6C8C: bne         $t0, $zero, L_801C6D3C
    if (ctx->r8 != 0) {
        // 0x801C6C90: nop
    
            goto L_801C6D3C;
    }
    // 0x801C6C90: nop

    // 0x801C6C94: lw          $t1, 0x38C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38C);
    // 0x801C6C98: sb          $t2, 0xEF5($s0)
    MEM_B(0XEF5, ctx->r16) = ctx->r10;
    // 0x801C6C9C: b           L_801C776C
    // 0x801C6CA0: sw          $t1, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = ctx->r9;
        goto L_801C776C;
    // 0x801C6CA0: sw          $t1, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = ctx->r9;
    // 0x801C6CA4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_801C6CA8:
    // 0x801C6CA8: bnel        $v1, $at, L_801C6CEC
    if (ctx->r3 != ctx->r1) {
        // 0x801C6CAC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_801C6CEC;
    }
    goto skip_64;
    // 0x801C6CAC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_64:
    // 0x801C6CB0: lbu         $t3, 0xEF5($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XEF5);
    // 0x801C6CB4: bnel        $t3, $zero, L_801C6CEC
    if (ctx->r11 != 0) {
        // 0x801C6CB8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_801C6CEC;
    }
    goto skip_65;
    // 0x801C6CB8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_65:
    // 0x801C6CBC: jal         0x801C3B20
    // 0x801C6CC0: nop

    LOOKUP_FUNC(0x801C3B20)(rdram, ctx);
        goto after_42;
    // 0x801C6CC0: nop

    after_42:
    // 0x801C6CC4: bne         $v0, $zero, L_801C6D3C
    if (ctx->r2 != 0) {
        // 0x801C6CC8: nop
    
            goto L_801C6D3C;
    }
    // 0x801C6CC8: nop

    // 0x801C6CCC: jal         0x801C3B48
    // 0x801C6CD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801C3B48)(rdram, ctx);
        goto after_43;
    // 0x801C6CD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_43:
    // 0x801C6CD4: jal         0x801C3B7C
    // 0x801C6CD8: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_44;
    // 0x801C6CD8: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    after_44:
    // 0x801C6CDC: swc1        $f26, 0x40($s3)
    MEM_W(0X40, ctx->r19) = ctx->f26.u32l;
    // 0x801C6CE0: b           L_801C776C
    // 0x801C6CE4: swc1        $f26, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->f26.u32l;
        goto L_801C776C;
    // 0x801C6CE4: swc1        $f26, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->f26.u32l;
    // 0x801C6CE8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_801C6CEC:
    // 0x801C6CEC: bne         $v1, $at, L_801C6D28
    if (ctx->r3 != ctx->r1) {
        // 0x801C6CF0: lbu         $v0, 0xEF5($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0XEF5);
            goto L_801C6D28;
    }
    // 0x801C6CF0: lbu         $v0, 0xEF5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XEF5);
    // 0x801C6CF4: bne         $v0, $zero, L_801C6D28
    if (ctx->r2 != 0) {
        // 0x801C6CF8: nop
    
            goto L_801C6D28;
    }
    // 0x801C6CF8: nop

    // 0x801C6CFC: jal         0x801C3B20
    // 0x801C6D00: nop

    LOOKUP_FUNC(0x801C3B20)(rdram, ctx);
        goto after_45;
    // 0x801C6D00: nop

    after_45:
    // 0x801C6D04: bne         $v0, $zero, L_801C6D3C
    if (ctx->r2 != 0) {
        // 0x801C6D08: nop
    
            goto L_801C6D3C;
    }
    // 0x801C6D08: nop

    // 0x801C6D0C: jal         0x801C3B48
    // 0x801C6D10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801C3B48)(rdram, ctx);
        goto after_46;
    // 0x801C6D10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_46:
    // 0x801C6D14: jal         0x801C3B7C
    // 0x801C6D18: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_47;
    // 0x801C6D18: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    after_47:
    // 0x801C6D1C: swc1        $f26, 0x40($s3)
    MEM_W(0X40, ctx->r19) = ctx->f26.u32l;
    // 0x801C6D20: b           L_801C776C
    // 0x801C6D24: swc1        $f26, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->f26.u32l;
        goto L_801C776C;
    // 0x801C6D24: swc1        $f26, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->f26.u32l;
L_801C6D28:
    // 0x801C6D28: bne         $v0, $zero, L_801C6D3C
    if (ctx->r2 != 0) {
        // 0x801C6D2C: nop
    
            goto L_801C6D3C;
    }
    // 0x801C6D2C: nop

    // 0x801C6D30: b           L_801C776C
    // 0x801C6D34: sw          $zero, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = 0;
        goto L_801C776C;
    // 0x801C6D34: sw          $zero, 0xEF8($s0)
    MEM_W(0XEF8, ctx->r16) = 0;
    // 0x801C6D38: sb          $zero, 0xEF7($s0)
    MEM_B(0XEF7, ctx->r16) = 0;
L_801C6D3C:
    // 0x801C6D3C: b           L_801C7770
    // 0x801C6D40: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C6D40: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C6D44:
    // 0x801C6D44: lhu         $t4, 0xEF0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XEF0);
L_801C6D48:
    // 0x801C6D48: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x801C6D4C: bnel        $t5, $zero, L_801C7770
    if (ctx->r13 != 0) {
        // 0x801C6D50: lhu         $v1, 0x4($s2)
        ctx->r3 = MEM_HU(ctx->r18, 0X4);
            goto L_801C7770;
    }
    goto skip_66;
    // 0x801C6D50: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    skip_66:
    // 0x801C6D54: lhu         $t6, 0x2($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X2);
    // 0x801C6D58: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C6D5C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C6D60: addu        $v0, $s0, $t7
    ctx->r2 = ADD32(ctx->r16, ctx->r15);
    // 0x801C6D64: lwc1        $f18, 0xE40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C6D68: lwc1        $f6, 0xE80($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XE80);
    // 0x801C6D6C: lwc1        $f12, 0xD40($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XD40);
    // 0x801C6D70: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801C6D74: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C6D78: lw          $a2, 0xDC0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XDC0);
    // 0x801C6D7C: lw          $a3, 0xE00($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE00);
    // 0x801C6D80: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801C6D84: jal         0x801C5A1C
    // 0x801C6D88: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_48;
    // 0x801C6D88: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_48:
    // 0x801C6D8C: beq         $v0, $zero, L_801C6F58
    if (ctx->r2 == 0) {
        // 0x801C6D90: nop
    
            goto L_801C6F58;
    }
    // 0x801C6D90: nop

    // 0x801C6D94: lbu         $v1, 0x35A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C6D98: bne         $s4, $v1, L_801C6DA8
    if (ctx->r20 != ctx->r3) {
        // 0x801C6D9C: nop
    
            goto L_801C6DA8;
    }
    // 0x801C6D9C: nop

    // 0x801C6DA0: b           L_801C7770
    // 0x801C6DA4: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C6DA4: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C6DA8:
    // 0x801C6DA8: bnel        $s5, $v1, L_801C6DBC
    if (ctx->r21 != ctx->r3) {
        // 0x801C6DAC: lhu         $v0, 0xEF0($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0XEF0);
            goto L_801C6DBC;
    }
    goto skip_67;
    // 0x801C6DAC: lhu         $v0, 0xEF0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XEF0);
    skip_67:
    // 0x801C6DB0: b           L_801C7770
    // 0x801C6DB4: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C6DB4: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    // 0x801C6DB8: lhu         $v0, 0xEF0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XEF0);
L_801C6DBC:
    // 0x801C6DBC: andi        $t8, $v0, 0x1000
    ctx->r24 = ctx->r2 & 0X1000;
    // 0x801C6DC0: bne         $t8, $zero, L_801C6E2C
    if (ctx->r24 != 0) {
        // 0x801C6DC4: andi        $t9, $v0, 0x8000
        ctx->r25 = ctx->r2 & 0X8000;
            goto L_801C6E2C;
    }
    // 0x801C6DC4: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x801C6DC8: bne         $t9, $zero, L_801C6E2C
    if (ctx->r25 != 0) {
        // 0x801C6DCC: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_801C6E2C;
    }
    // 0x801C6DCC: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801C6DD0: bne         $v1, $at, L_801C6E2C
    if (ctx->r3 != ctx->r1) {
        // 0x801C6DD4: lui         $t0, 0x8018
        ctx->r8 = S32(0X8018 << 16);
            goto L_801C6E2C;
    }
    // 0x801C6DD4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801C6DD8: lhu         $t0, -0x23BE($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X23BE);
    // 0x801C6DDC: ori         $t2, $v0, 0x8000
    ctx->r10 = ctx->r2 | 0X8000;
    // 0x801C6DE0: blezl       $t0, L_801C6E2C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x801C6DE4: sh          $t2, 0xEF0($s0)
        MEM_H(0XEF0, ctx->r16) = ctx->r10;
            goto L_801C6E2C;
    }
    goto skip_68;
    // 0x801C6DE4: sh          $t2, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r10;
    skip_68:
    // 0x801C6DE8: lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1C);
    // 0x801C6DEC: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C6DF0: ori         $at, $at, 0x12
    ctx->r1 = ctx->r1 | 0X12;
    // 0x801C6DF4: beq         $v0, $at, L_801C6E2C
    if (ctx->r2 == ctx->r1) {
        // 0x801C6DF8: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C6E2C;
    }
    // 0x801C6DF8: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C6DFC: ori         $at, $at, 0x13
    ctx->r1 = ctx->r1 | 0X13;
    // 0x801C6E00: beq         $v0, $at, L_801C6E2C
    if (ctx->r2 == ctx->r1) {
        // 0x801C6E04: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C6E2C;
    }
    // 0x801C6E04: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C6E08: ori         $at, $at, 0x14
    ctx->r1 = ctx->r1 | 0X14;
    // 0x801C6E0C: beql        $v0, $at, L_801C6E30
    if (ctx->r2 == ctx->r1) {
        // 0x801C6E10: lwc1        $f0, 0x35C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X35C);
            goto L_801C6E30;
    }
    goto skip_69;
    // 0x801C6E10: lwc1        $f0, 0x35C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X35C);
    skip_69:
    // 0x801C6E14: jal         0x801C3B7C
    // 0x801C6E18: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_49;
    // 0x801C6E18: lw          $a0, 0x38C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38C);
    after_49:
    // 0x801C6E1C: lhu         $t1, 0xEF0($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XEF0);
    // 0x801C6E20: b           L_801C776C
    // 0x801C6E24: sh          $t1, 0xEF2($s0)
    MEM_H(0XEF2, ctx->r16) = ctx->r9;
        goto L_801C776C;
    // 0x801C6E24: sh          $t1, 0xEF2($s0)
    MEM_H(0XEF2, ctx->r16) = ctx->r9;
    // 0x801C6E28: sh          $t2, 0xEF0($s0)
    MEM_H(0XEF0, ctx->r16) = ctx->r10;
L_801C6E2C:
    // 0x801C6E2C: lwc1        $f0, 0x35C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X35C);
L_801C6E30:
    // 0x801C6E30: lwc1        $f14, 0x360($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X360);
    // 0x801C6E34: lwc1        $f2, 0x364($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X364);
    // 0x801C6E38: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C6E3C: nop

    // 0x801C6E40: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C6E44: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801C6E48: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C6E4C: jal         0x8002FC20
    // 0x801C6E50: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_50;
    // 0x801C6E50: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_50:
    // 0x801C6E54: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x801C6E58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801C6E5C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801C6E60: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x801C6E64: nop

    // 0x801C6E68: bc1tl       L_801C6E8C
    if (c1cs) {
        // 0x801C6E6C: lwc1        $f12, 0x368($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
            goto L_801C6E8C;
    }
    goto skip_70;
    // 0x801C6E6C: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
    skip_70:
    // 0x801C6E70: lwc1        $f4, 0x35C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X35C);
    // 0x801C6E74: lwc1        $f10, 0x360($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X360);
    // 0x801C6E78: lwc1        $f18, 0x364($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X364);
    // 0x801C6E7C: swc1        $f4, 0xEE4($s0)
    MEM_W(0XEE4, ctx->r16) = ctx->f4.u32l;
    // 0x801C6E80: swc1        $f10, 0xEE8($s0)
    MEM_W(0XEE8, ctx->r16) = ctx->f10.u32l;
    // 0x801C6E84: swc1        $f18, 0xEEC($s0)
    MEM_W(0XEEC, ctx->r16) = ctx->f18.u32l;
    // 0x801C6E88: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
L_801C6E8C:
    // 0x801C6E8C: c.lt.s      $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f12.fl < ctx->f26.fl;
    // 0x801C6E90: nop

    // 0x801C6E94: bc1fl       L_801C6EA8
    if (!c1cs) {
        // 0x801C6E98: mov.s       $f24, $f12
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
            goto L_801C6EA8;
    }
    goto skip_71;
    // 0x801C6E98: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    skip_71:
    // 0x801C6E9C: b           L_801C6EA8
    // 0x801C6EA0: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
        goto L_801C6EA8;
    // 0x801C6EA0: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
    // 0x801C6EA4: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
L_801C6EA8:
    // 0x801C6EA8: c.lt.s      $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f30.fl < ctx->f26.fl;
    // 0x801C6EAC: nop

    // 0x801C6EB0: bc1fl       L_801C6EC4
    if (!c1cs) {
        // 0x801C6EB4: mov.s       $f0, $f30
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
            goto L_801C6EC4;
    }
    goto skip_72;
    // 0x801C6EB4: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
    skip_72:
    // 0x801C6EB8: b           L_801C6EC4
    // 0x801C6EBC: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
        goto L_801C6EC4;
    // 0x801C6EBC: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
    // 0x801C6EC0: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
L_801C6EC4:
    // 0x801C6EC4: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C6EC8: nop

    // 0x801C6ECC: bc1fl       L_801C6EDC
    if (!c1cs) {
        // 0x801C6ED0: lwc1        $f2, 0x370($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
            goto L_801C6EDC;
    }
    goto skip_73;
    // 0x801C6ED0: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
    skip_73:
    // 0x801C6ED4: mov.s       $f30, $f12
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    ctx->f30.fl = ctx->f12.fl;
    // 0x801C6ED8: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
L_801C6EDC:
    // 0x801C6EDC: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
    // 0x801C6EE0: nop

    // 0x801C6EE4: bc1fl       L_801C6EF8
    if (!c1cs) {
        // 0x801C6EE8: mov.s       $f24, $f2
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
            goto L_801C6EF8;
    }
    goto skip_74;
    // 0x801C6EE8: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
    skip_74:
    // 0x801C6EEC: b           L_801C6EF8
    // 0x801C6EF0: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
        goto L_801C6EF8;
    // 0x801C6EF0: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
    // 0x801C6EF4: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_801C6EF8:
    // 0x801C6EF8: c.lt.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl < ctx->f26.fl;
    // 0x801C6EFC: nop

    // 0x801C6F00: bc1fl       L_801C6F14
    if (!c1cs) {
        // 0x801C6F04: mov.s       $f0, $f28
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
            goto L_801C6F14;
    }
    goto skip_75;
    // 0x801C6F04: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
    skip_75:
    // 0x801C6F08: b           L_801C6F14
    // 0x801C6F0C: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
        goto L_801C6F14;
    // 0x801C6F0C: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
    // 0x801C6F10: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_801C6F14:
    // 0x801C6F14: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C6F18: nop

    // 0x801C6F1C: bc1fl       L_801C6F2C
    if (!c1cs) {
        // 0x801C6F20: c.eq.s      $f26, $f12
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
            goto L_801C6F2C;
    }
    goto skip_76;
    // 0x801C6F20: c.eq.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
    skip_76:
    // 0x801C6F24: mov.s       $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
    // 0x801C6F28: c.eq.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
L_801C6F2C:
    // 0x801C6F2C: nop

    // 0x801C6F30: bc1fl       L_801C6F4C
    if (!c1cs) {
        // 0x801C6F34: lw          $t3, 0xEC4($s0)
        ctx->r11 = MEM_W(ctx->r16, 0XEC4);
            goto L_801C6F4C;
    }
    goto skip_77;
    // 0x801C6F34: lw          $t3, 0xEC4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XEC4);
    skip_77:
    // 0x801C6F38: c.eq.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl == ctx->f2.fl;
    // 0x801C6F3C: nop

    // 0x801C6F40: bc1t        L_801C6F58
    if (c1cs) {
        // 0x801C6F44: nop
    
            goto L_801C6F58;
    }
    // 0x801C6F44: nop

    // 0x801C6F48: lw          $t3, 0xEC4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XEC4);
L_801C6F4C:
    // 0x801C6F4C: lhu         $t4, 0x0($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X0);
    // 0x801C6F50: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x801C6F54: sw          $t5, 0xEC4($s0)
    MEM_W(0XEC4, ctx->r16) = ctx->r13;
L_801C6F58:
    // 0x801C6F58: b           L_801C7770
    // 0x801C6F5C: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C6F5C: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    // 0x801C6F60: lhu         $t6, 0x2($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X2);
L_801C6F64:
    // 0x801C6F64: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C6F68: swc1        $f30, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f30.u32l;
    // 0x801C6F6C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C6F70: addu        $v0, $s0, $t7
    ctx->r2 = ADD32(ctx->r16, ctx->r15);
    // 0x801C6F74: lwc1        $f8, 0xE40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C6F78: lwc1        $f4, 0xE80($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XE80);
    // 0x801C6F7C: swc1        $f28, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f28.u32l;
    // 0x801C6F80: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801C6F84: lwc1        $f12, 0xD40($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XD40);
    // 0x801C6F88: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C6F8C: lw          $a2, 0xDC0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XDC0);
    // 0x801C6F90: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801C6F94: lw          $a3, 0xE00($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE00);
    // 0x801C6F98: jal         0x801C5A1C
    // 0x801C6F9C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_51;
    // 0x801C6F9C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_51:
    // 0x801C6FA0: beq         $v0, $zero, L_801C717C
    if (ctx->r2 == 0) {
        // 0x801C6FA4: nop
    
            goto L_801C717C;
    }
    // 0x801C6FA4: nop

    // 0x801C6FA8: lbu         $v1, 0x35A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C6FAC: bne         $s4, $v1, L_801C6FBC
    if (ctx->r20 != ctx->r3) {
        // 0x801C6FB0: nop
    
            goto L_801C6FBC;
    }
    // 0x801C6FB0: nop

    // 0x801C6FB4: b           L_801C7770
    // 0x801C6FB8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C6FB8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C6FBC:
    // 0x801C6FBC: bne         $s5, $v1, L_801C6FCC
    if (ctx->r21 != ctx->r3) {
        // 0x801C6FC0: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_801C6FCC;
    }
    // 0x801C6FC0: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801C6FC4: b           L_801C7770
    // 0x801C6FC8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C6FC8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C6FCC:
    // 0x801C6FCC: bnel        $v1, $at, L_801C6FE0
    if (ctx->r3 != ctx->r1) {
        // 0x801C6FD0: lwc1        $f12, 0x368($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
            goto L_801C6FE0;
    }
    goto skip_78;
    // 0x801C6FD0: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
    skip_78:
    // 0x801C6FD4: b           L_801C7770
    // 0x801C6FD8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C6FD8: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    // 0x801C6FDC: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
L_801C6FE0:
    // 0x801C6FE0: c.lt.s      $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f12.fl < ctx->f26.fl;
    // 0x801C6FE4: nop

    // 0x801C6FE8: bc1fl       L_801C6FFC
    if (!c1cs) {
        // 0x801C6FEC: mov.s       $f24, $f12
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
            goto L_801C6FFC;
    }
    goto skip_79;
    // 0x801C6FEC: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    skip_79:
    // 0x801C6FF0: b           L_801C6FFC
    // 0x801C6FF4: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
        goto L_801C6FFC;
    // 0x801C6FF4: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
    // 0x801C6FF8: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
L_801C6FFC:
    // 0x801C6FFC: c.lt.s      $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f30.fl < ctx->f26.fl;
    // 0x801C7000: nop

    // 0x801C7004: bc1fl       L_801C7018
    if (!c1cs) {
        // 0x801C7008: mov.s       $f0, $f30
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
            goto L_801C7018;
    }
    goto skip_80;
    // 0x801C7008: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
    skip_80:
    // 0x801C700C: b           L_801C7018
    // 0x801C7010: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
        goto L_801C7018;
    // 0x801C7010: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
    // 0x801C7014: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
L_801C7018:
    // 0x801C7018: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C701C: nop

    // 0x801C7020: bc1fl       L_801C7030
    if (!c1cs) {
        // 0x801C7024: lwc1        $f2, 0x370($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
            goto L_801C7030;
    }
    goto skip_81;
    // 0x801C7024: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
    skip_81:
    // 0x801C7028: swc1        $f12, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f12.u32l;
    // 0x801C702C: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
L_801C7030:
    // 0x801C7030: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
    // 0x801C7034: nop

    // 0x801C7038: bc1fl       L_801C704C
    if (!c1cs) {
        // 0x801C703C: mov.s       $f24, $f2
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
            goto L_801C704C;
    }
    goto skip_82;
    // 0x801C703C: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
    skip_82:
    // 0x801C7040: b           L_801C704C
    // 0x801C7044: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
        goto L_801C704C;
    // 0x801C7044: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
    // 0x801C7048: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_801C704C:
    // 0x801C704C: c.lt.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl < ctx->f26.fl;
    // 0x801C7050: nop

    // 0x801C7054: bc1fl       L_801C7068
    if (!c1cs) {
        // 0x801C7058: mov.s       $f0, $f28
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
            goto L_801C7068;
    }
    goto skip_83;
    // 0x801C7058: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
    skip_83:
    // 0x801C705C: b           L_801C7068
    // 0x801C7060: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
        goto L_801C7068;
    // 0x801C7060: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
    // 0x801C7064: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_801C7068:
    // 0x801C7068: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C706C: nop

    // 0x801C7070: bc1fl       L_801C7080
    if (!c1cs) {
        // 0x801C7074: lhu         $t8, 0x2($s2)
        ctx->r24 = MEM_HU(ctx->r18, 0X2);
            goto L_801C7080;
    }
    goto skip_84;
    // 0x801C7074: lhu         $t8, 0x2($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X2);
    skip_84:
    // 0x801C7078: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    // 0x801C707C: lhu         $t8, 0x2($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X2);
L_801C7080:
    // 0x801C7080: lwc1        $f10, 0x380($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X380);
    // 0x801C7084: lhu         $t1, 0x2($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X2);
    // 0x801C7088: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C708C: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x801C7090: lwc1        $f18, 0xE00($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XE00);
    // 0x801C7094: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801C7098: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x801C709C: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801C70A0: lwc1        $f16, 0x388($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X388);
    // 0x801C70A4: swc1        $f8, 0x368($s0)
    MEM_W(0X368, ctx->r16) = ctx->f8.u32l;
    // 0x801C70A8: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
    // 0x801C70AC: lwc1        $f6, 0xE80($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XE80);
    // 0x801C70B0: c.lt.s      $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f12.fl < ctx->f26.fl;
    // 0x801C70B4: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x801C70B8: bc1f        L_801C70C8
    if (!c1cs) {
        // 0x801C70BC: swc1        $f4, 0x370($s0)
        MEM_W(0X370, ctx->r16) = ctx->f4.u32l;
            goto L_801C70C8;
    }
    // 0x801C70BC: swc1        $f4, 0x370($s0)
    MEM_W(0X370, ctx->r16) = ctx->f4.u32l;
    // 0x801C70C0: b           L_801C70CC
    // 0x801C70C4: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
        goto L_801C70CC;
    // 0x801C70C4: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
L_801C70C8:
    // 0x801C70C8: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
L_801C70CC:
    // 0x801C70CC: c.lt.s      $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f30.fl < ctx->f26.fl;
    // 0x801C70D0: nop

    // 0x801C70D4: bc1fl       L_801C70E8
    if (!c1cs) {
        // 0x801C70D8: mov.s       $f0, $f30
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
            goto L_801C70E8;
    }
    goto skip_85;
    // 0x801C70D8: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
    skip_85:
    // 0x801C70DC: b           L_801C70E8
    // 0x801C70E0: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
        goto L_801C70E8;
    // 0x801C70E0: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
    // 0x801C70E4: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
L_801C70E8:
    // 0x801C70E8: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C70EC: nop

    // 0x801C70F0: bc1fl       L_801C7100
    if (!c1cs) {
        // 0x801C70F4: lwc1        $f2, 0x370($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
            goto L_801C7100;
    }
    goto skip_86;
    // 0x801C70F4: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
    skip_86:
    // 0x801C70F8: mov.s       $f30, $f12
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    ctx->f30.fl = ctx->f12.fl;
    // 0x801C70FC: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
L_801C7100:
    // 0x801C7100: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
    // 0x801C7104: nop

    // 0x801C7108: bc1fl       L_801C711C
    if (!c1cs) {
        // 0x801C710C: mov.s       $f24, $f2
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
            goto L_801C711C;
    }
    goto skip_87;
    // 0x801C710C: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
    skip_87:
    // 0x801C7110: b           L_801C711C
    // 0x801C7114: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
        goto L_801C711C;
    // 0x801C7114: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
    // 0x801C7118: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_801C711C:
    // 0x801C711C: c.lt.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl < ctx->f26.fl;
    // 0x801C7120: nop

    // 0x801C7124: bc1fl       L_801C7138
    if (!c1cs) {
        // 0x801C7128: mov.s       $f0, $f28
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
            goto L_801C7138;
    }
    goto skip_88;
    // 0x801C7128: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
    skip_88:
    // 0x801C712C: b           L_801C7138
    // 0x801C7130: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
        goto L_801C7138;
    // 0x801C7130: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
    // 0x801C7134: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_801C7138:
    // 0x801C7138: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C713C: nop

    // 0x801C7140: bc1fl       L_801C7150
    if (!c1cs) {
        // 0x801C7144: c.eq.s      $f26, $f12
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
            goto L_801C7150;
    }
    goto skip_89;
    // 0x801C7144: c.eq.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
    skip_89:
    // 0x801C7148: mov.s       $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
    // 0x801C714C: c.eq.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
L_801C7150:
    // 0x801C7150: nop

    // 0x801C7154: bc1fl       L_801C7170
    if (!c1cs) {
        // 0x801C7158: lw          $t4, 0xEC4($s0)
        ctx->r12 = MEM_W(ctx->r16, 0XEC4);
            goto L_801C7170;
    }
    goto skip_90;
    // 0x801C7158: lw          $t4, 0xEC4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XEC4);
    skip_90:
    // 0x801C715C: c.eq.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl == ctx->f2.fl;
    // 0x801C7160: nop

    // 0x801C7164: bc1t        L_801C717C
    if (c1cs) {
        // 0x801C7168: nop
    
            goto L_801C717C;
    }
    // 0x801C7168: nop

    // 0x801C716C: lw          $t4, 0xEC4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XEC4);
L_801C7170:
    // 0x801C7170: lhu         $t5, 0x0($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X0);
    // 0x801C7174: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x801C7178: sw          $t6, 0xEC4($s0)
    MEM_W(0XEC4, ctx->r16) = ctx->r14;
L_801C717C:
    // 0x801C717C: b           L_801C7770
    // 0x801C7180: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C7180: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C7184:
    // 0x801C7184: lhu         $t7, 0x2($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X2);
    // 0x801C7188: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C718C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801C7190: addu        $v0, $s0, $t8
    ctx->r2 = ADD32(ctx->r16, ctx->r24);
    // 0x801C7194: lwc1        $f10, 0xE40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C7198: lwc1        $f16, 0xE80($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XE80);
    // 0x801C719C: lwc1        $f12, 0xD40($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XD40);
    // 0x801C71A0: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801C71A4: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C71A8: lw          $a2, 0xDC0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XDC0);
    // 0x801C71AC: lw          $a3, 0xE00($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE00);
    // 0x801C71B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801C71B4: jal         0x801C5A1C
    // 0x801C71B8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_52;
    // 0x801C71B8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_52:
    // 0x801C71BC: beq         $v0, $zero, L_801C7314
    if (ctx->r2 == 0) {
        // 0x801C71C0: lwc1        $f6, 0x80($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
            goto L_801C7314;
    }
    // 0x801C71C0: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801C71C4: lbu         $v1, 0x35A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C71C8: bne         $s4, $v1, L_801C71D8
    if (ctx->r20 != ctx->r3) {
        // 0x801C71CC: nop
    
            goto L_801C71D8;
    }
    // 0x801C71CC: nop

    // 0x801C71D0: b           L_801C7770
    // 0x801C71D4: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C71D4: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C71D8:
    // 0x801C71D8: bne         $s5, $v1, L_801C71E8
    if (ctx->r21 != ctx->r3) {
        // 0x801C71DC: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_801C71E8;
    }
    // 0x801C71DC: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801C71E0: b           L_801C7770
    // 0x801C71E4: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C71E4: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C71E8:
    // 0x801C71E8: bnel        $v1, $at, L_801C71FC
    if (ctx->r3 != ctx->r1) {
        // 0x801C71EC: lw          $v0, 0xEC4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XEC4);
            goto L_801C71FC;
    }
    goto skip_91;
    // 0x801C71EC: lw          $v0, 0xEC4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XEC4);
    skip_91:
    // 0x801C71F0: b           L_801C7770
    // 0x801C71F4: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C71F4: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    // 0x801C71F8: lw          $v0, 0xEC4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XEC4);
L_801C71FC:
    // 0x801C71FC: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x801C7200: beql        $t9, $zero, L_801C7244
    if (ctx->r25 == 0) {
        // 0x801C7204: lwc1        $f12, 0x368($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
            goto L_801C7244;
    }
    goto skip_92;
    // 0x801C7204: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
    skip_92:
    // 0x801C7208: lhu         $t0, 0x2($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X2);
    // 0x801C720C: lwc1        $f6, 0x380($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X380);
    // 0x801C7210: lhu         $t3, 0x2($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X2);
    // 0x801C7214: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801C7218: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x801C721C: lwc1        $f4, 0xE00($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XE00);
    // 0x801C7220: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801C7224: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x801C7228: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x801C722C: lwc1        $f18, 0x388($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X388);
    // 0x801C7230: swc1        $f10, 0x368($s0)
    MEM_W(0X368, ctx->r16) = ctx->f10.u32l;
    // 0x801C7234: lwc1        $f8, 0xE80($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XE80);
    // 0x801C7238: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x801C723C: swc1        $f16, 0x370($s0)
    MEM_W(0X370, ctx->r16) = ctx->f16.u32l;
    // 0x801C7240: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
L_801C7244:
    // 0x801C7244: c.lt.s      $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f12.fl < ctx->f26.fl;
    // 0x801C7248: nop

    // 0x801C724C: bc1fl       L_801C7260
    if (!c1cs) {
        // 0x801C7250: mov.s       $f24, $f12
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
            goto L_801C7260;
    }
    goto skip_93;
    // 0x801C7250: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    skip_93:
    // 0x801C7254: b           L_801C7260
    // 0x801C7258: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
        goto L_801C7260;
    // 0x801C7258: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
    // 0x801C725C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
L_801C7260:
    // 0x801C7260: c.lt.s      $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f30.fl < ctx->f26.fl;
    // 0x801C7264: nop

    // 0x801C7268: bc1fl       L_801C727C
    if (!c1cs) {
        // 0x801C726C: mov.s       $f0, $f30
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
            goto L_801C727C;
    }
    goto skip_94;
    // 0x801C726C: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
    skip_94:
    // 0x801C7270: b           L_801C727C
    // 0x801C7274: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
        goto L_801C727C;
    // 0x801C7274: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
    // 0x801C7278: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
L_801C727C:
    // 0x801C727C: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C7280: nop

    // 0x801C7284: bc1fl       L_801C7294
    if (!c1cs) {
        // 0x801C7288: lwc1        $f2, 0x370($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
            goto L_801C7294;
    }
    goto skip_95;
    // 0x801C7288: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
    skip_95:
    // 0x801C728C: mov.s       $f30, $f12
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    ctx->f30.fl = ctx->f12.fl;
    // 0x801C7290: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
L_801C7294:
    // 0x801C7294: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
    // 0x801C7298: nop

    // 0x801C729C: bc1fl       L_801C72B0
    if (!c1cs) {
        // 0x801C72A0: mov.s       $f24, $f2
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
            goto L_801C72B0;
    }
    goto skip_96;
    // 0x801C72A0: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
    skip_96:
    // 0x801C72A4: b           L_801C72B0
    // 0x801C72A8: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
        goto L_801C72B0;
    // 0x801C72A8: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
    // 0x801C72AC: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_801C72B0:
    // 0x801C72B0: c.lt.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl < ctx->f26.fl;
    // 0x801C72B4: nop

    // 0x801C72B8: bc1fl       L_801C72CC
    if (!c1cs) {
        // 0x801C72BC: mov.s       $f0, $f28
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
            goto L_801C72CC;
    }
    goto skip_97;
    // 0x801C72BC: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
    skip_97:
    // 0x801C72C0: b           L_801C72CC
    // 0x801C72C4: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
        goto L_801C72CC;
    // 0x801C72C4: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
    // 0x801C72C8: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_801C72CC:
    // 0x801C72CC: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C72D0: nop

    // 0x801C72D4: bc1fl       L_801C72E4
    if (!c1cs) {
        // 0x801C72D8: c.eq.s      $f26, $f12
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
            goto L_801C72E4;
    }
    goto skip_98;
    // 0x801C72D8: c.eq.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
    skip_98:
    // 0x801C72DC: mov.s       $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
    // 0x801C72E0: c.eq.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
L_801C72E4:
    // 0x801C72E4: nop

    // 0x801C72E8: bc1fl       L_801C7304
    if (!c1cs) {
        // 0x801C72EC: lhu         $t6, 0x0($s2)
        ctx->r14 = MEM_HU(ctx->r18, 0X0);
            goto L_801C7304;
    }
    goto skip_99;
    // 0x801C72EC: lhu         $t6, 0x0($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X0);
    skip_99:
    // 0x801C72F0: c.eq.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl == ctx->f2.fl;
    // 0x801C72F4: nop

    // 0x801C72F8: bc1t        L_801C730C
    if (c1cs) {
        // 0x801C72FC: nop
    
            goto L_801C730C;
    }
    // 0x801C72FC: nop

    // 0x801C7300: lhu         $t6, 0x0($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X0);
L_801C7304:
    // 0x801C7304: or          $t7, $v0, $t6
    ctx->r15 = ctx->r2 | ctx->r14;
    // 0x801C7308: sw          $t7, 0xEC4($s0)
    MEM_W(0XEC4, ctx->r16) = ctx->r15;
L_801C730C:
    // 0x801C730C: b           L_801C7770
    // 0x801C7310: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C7310: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C7314:
    // 0x801C7314: c.lt.s      $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f6.fl < ctx->f26.fl;
    // 0x801C7318: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x801C731C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C7320: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801C7324: bc1f        L_801C7334
    if (!c1cs) {
        // 0x801C7328: lwc1        $f10, 0x7C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
            goto L_801C7334;
    }
    // 0x801C7328: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801C732C: b           L_801C7334
    // 0x801C7330: neg.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = -ctx->f6.fl;
        goto L_801C7334;
    // 0x801C7330: neg.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = -ctx->f6.fl;
L_801C7334:
    // 0x801C7334: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C7338: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801C733C: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x801C7340: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801C7344: bc1tl       L_801C737C
    if (c1cs) {
        // 0x801C7348: c.lt.s      $f8, $f26
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f8.fl < ctx->f26.fl;
            goto L_801C737C;
    }
    goto skip_100;
    // 0x801C7348: c.lt.s      $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f8.fl < ctx->f26.fl;
    skip_100:
    // 0x801C734C: c.lt.s      $f10, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f10.fl < ctx->f26.fl;
    // 0x801C7350: lwc1        $f24, 0x7C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801C7354: bc1f        L_801C7364
    if (!c1cs) {
        // 0x801C7358: nop
    
            goto L_801C7364;
    }
    // 0x801C7358: nop

    // 0x801C735C: b           L_801C7364
    // 0x801C7360: neg.s       $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = -ctx->f10.fl;
        goto L_801C7364;
    // 0x801C7360: neg.s       $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = -ctx->f10.fl;
L_801C7364:
    // 0x801C7364: cvt.d.s     $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f18.d = CVT_D_S(ctx->f24.fl);
    // 0x801C7368: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x801C736C: nop

    // 0x801C7370: bc1fl       L_801C7770
    if (!c1cs) {
        // 0x801C7374: lhu         $v1, 0x4($s2)
        ctx->r3 = MEM_HU(ctx->r18, 0X4);
            goto L_801C7770;
    }
    goto skip_101;
    // 0x801C7374: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    skip_101:
    // 0x801C7378: c.lt.s      $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f8.fl < ctx->f26.fl;
L_801C737C:
    // 0x801C737C: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801C7380: lwc1        $f30, 0x78($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801C7384: bc1f        L_801C7394
    if (!c1cs) {
        // 0x801C7388: nop
    
            goto L_801C7394;
    }
    // 0x801C7388: nop

    // 0x801C738C: b           L_801C7394
    // 0x801C7390: neg.s       $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = -ctx->f8.fl;
        goto L_801C7394;
    // 0x801C7390: neg.s       $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = -ctx->f8.fl;
L_801C7394:
    // 0x801C7394: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x801C7398: lwc1        $f0, 0x7C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801C739C: c.lt.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d < ctx->f16.d;
    // 0x801C73A0: nop

    // 0x801C73A4: bc1f        L_801C73B4
    if (!c1cs) {
        // 0x801C73A8: nop
    
            goto L_801C73B4;
    }
    // 0x801C73A8: nop

    // 0x801C73AC: b           L_801C73B4
    // 0x801C73B0: lwc1        $f30, 0x80($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X80);
        goto L_801C73B4;
    // 0x801C73B0: lwc1        $f30, 0x80($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X80);
L_801C73B4:
    // 0x801C73B4: c.lt.s      $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f6.fl < ctx->f26.fl;
    // 0x801C73B8: nop

    // 0x801C73BC: bc1f        L_801C73CC
    if (!c1cs) {
        // 0x801C73C0: nop
    
            goto L_801C73CC;
    }
    // 0x801C73C0: nop

    // 0x801C73C4: b           L_801C73CC
    // 0x801C73C8: neg.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = -ctx->f6.fl;
        goto L_801C73CC;
    // 0x801C73C8: neg.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = -ctx->f6.fl;
L_801C73CC:
    // 0x801C73CC: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801C73D0: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x801C73D4: nop

    // 0x801C73D8: bc1f        L_801C73E8
    if (!c1cs) {
        // 0x801C73DC: nop
    
            goto L_801C73E8;
    }
    // 0x801C73DC: nop

    // 0x801C73E0: b           L_801C776C
    // 0x801C73E4: lwc1        $f28, 0x7C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X7C);
        goto L_801C776C;
    // 0x801C73E4: lwc1        $f28, 0x7C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X7C);
L_801C73E8:
    // 0x801C73E8: b           L_801C776C
    // 0x801C73EC: lwc1        $f28, 0x74($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X74);
        goto L_801C776C;
    // 0x801C73EC: lwc1        $f28, 0x74($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X74);
L_801C73F0:
    // 0x801C73F0: lhu         $t8, 0x2($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X2);
    // 0x801C73F4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801C73F8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C73FC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C7400: addu        $v0, $s0, $t9
    ctx->r2 = ADD32(ctx->r16, ctx->r25);
    // 0x801C7404: lwc1        $f10, 0xE40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C7408: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C740C: lwc1        $f4, 0xE80($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XE80);
    // 0x801C7410: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x801C7414: lwc1        $f12, 0xD40($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XD40);
    // 0x801C7418: add.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f18.d + ctx->f8.d;
    // 0x801C741C: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C7420: lw          $a2, 0xDC0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XDC0);
    // 0x801C7424: lw          $a3, 0xE00($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE00);
    // 0x801C7428: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x801C742C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801C7430: jal         0x801C5A1C
    // 0x801C7434: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_53;
    // 0x801C7434: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_53:
    // 0x801C7438: lwc1        $f0, 0x36C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X36C);
    // 0x801C743C: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C7440: c.eq.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl == ctx->f0.fl;
    // 0x801C7444: nop

    // 0x801C7448: bc1t        L_801C7474
    if (c1cs) {
        // 0x801C744C: nop
    
            goto L_801C7474;
    }
    // 0x801C744C: nop

    // 0x801C7450: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x801C7454: nop

    // 0x801C7458: bc1fl       L_801C7468
    if (!c1cs) {
        // 0x801C745C: lw          $t0, 0xEC4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0XEC4);
            goto L_801C7468;
    }
    goto skip_102;
    // 0x801C745C: lw          $t0, 0xEC4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XEC4);
    skip_102:
    // 0x801C7460: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x801C7464: lw          $t0, 0xEC4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XEC4);
L_801C7468:
    // 0x801C7468: lhu         $t1, 0x0($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X0);
    // 0x801C746C: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x801C7470: sw          $t2, 0xEC4($s0)
    MEM_W(0XEC4, ctx->r16) = ctx->r10;
L_801C7474:
    // 0x801C7474: b           L_801C7770
    // 0x801C7478: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
        goto L_801C7770;
    // 0x801C7478: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
    // 0x801C747C: lhu         $t3, 0x2($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X2);
L_801C7480:
    // 0x801C7480: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C7484: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801C7488: addu        $v0, $s0, $t4
    ctx->r2 = ADD32(ctx->r16, ctx->r12);
    // 0x801C748C: lwc1        $f18, 0xE40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C7490: lwc1        $f6, 0xE80($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XE80);
    // 0x801C7494: lwc1        $f12, 0xD40($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XD40);
    // 0x801C7498: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801C749C: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C74A0: lw          $a2, 0xDC0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XDC0);
    // 0x801C74A4: lw          $a3, 0xE00($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE00);
    // 0x801C74A8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801C74AC: jal         0x801C5A1C
    // 0x801C74B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_54;
    // 0x801C74B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_54:
    // 0x801C74B4: beql        $v0, $zero, L_801C7654
    if (ctx->r2 == 0) {
        // 0x801C74B8: lhu         $t4, 0x2($s2)
        ctx->r12 = MEM_HU(ctx->r18, 0X2);
            goto L_801C7654;
    }
    goto skip_103;
    // 0x801C74B8: lhu         $t4, 0x2($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X2);
    skip_103:
    // 0x801C74BC: lbu         $v1, 0x35A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C74C0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801C74C4: bne         $v1, $at, L_801C74F8
    if (ctx->r3 != ctx->r1) {
        // 0x801C74C8: nop
    
            goto L_801C74F8;
    }
    // 0x801C74C8: nop

    // 0x801C74CC: lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1C);
    // 0x801C74D0: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C74D4: ori         $at, $at, 0x3F
    ctx->r1 = ctx->r1 | 0X3F;
    // 0x801C74D8: beq         $v0, $at, L_801C74E8
    if (ctx->r2 == ctx->r1) {
        // 0x801C74DC: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_801C74E8;
    }
    // 0x801C74DC: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801C74E0: ori         $at, $at, 0x40
    ctx->r1 = ctx->r1 | 0X40;
    // 0x801C74E4: bne         $v0, $at, L_801C74F8
    if (ctx->r2 != ctx->r1) {
        // 0x801C74E8: lui         $at, 0x4020
        ctx->r1 = S32(0X4020 << 16);
            goto L_801C74F8;
    }
L_801C74E8:
    // 0x801C74E8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801C74EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C74F0: b           L_801C776C
    // 0x801C74F4: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
        goto L_801C776C;
    // 0x801C74F4: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
L_801C74F8:
    // 0x801C74F8: beql        $s4, $v1, L_801C7654
    if (ctx->r20 == ctx->r3) {
        // 0x801C74FC: lhu         $t4, 0x2($s2)
        ctx->r12 = MEM_HU(ctx->r18, 0X2);
            goto L_801C7654;
    }
    goto skip_104;
    // 0x801C74FC: lhu         $t4, 0x2($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X2);
    skip_104:
    // 0x801C7500: beql        $s5, $v1, L_801C7654
    if (ctx->r21 == ctx->r3) {
        // 0x801C7504: lhu         $t4, 0x2($s2)
        ctx->r12 = MEM_HU(ctx->r18, 0X2);
            goto L_801C7654;
    }
    goto skip_105;
    // 0x801C7504: lhu         $t4, 0x2($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X2);
    skip_105:
    // 0x801C7508: lwc1        $f18, 0x35C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X35C);
    // 0x801C750C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x801C7510: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C7514: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x801C7518: c.eq.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d == ctx->f8.d;
    // 0x801C751C: nop

    // 0x801C7520: bc1fl       L_801C754C
    if (!c1cs) {
        // 0x801C7524: lhu         $t5, 0x2($s2)
        ctx->r13 = MEM_HU(ctx->r18, 0X2);
            goto L_801C754C;
    }
    goto skip_106;
    // 0x801C7524: lhu         $t5, 0x2($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X2);
    skip_106:
    // 0x801C7528: lwc1        $f6, 0x364($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X364);
    // 0x801C752C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x801C7530: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801C7534: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801C7538: c.eq.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d == ctx->f4.d;
    // 0x801C753C: nop

    // 0x801C7540: bc1tl       L_801C7584
    if (c1cs) {
        // 0x801C7544: lwc1        $f12, 0x368($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
            goto L_801C7584;
    }
    goto skip_107;
    // 0x801C7544: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
    skip_107:
    // 0x801C7548: lhu         $t5, 0x2($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X2);
L_801C754C:
    // 0x801C754C: lwc1        $f18, 0x380($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X380);
    // 0x801C7550: lhu         $t8, 0x2($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X2);
    // 0x801C7554: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801C7558: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x801C755C: lwc1        $f10, 0xE00($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XE00);
    // 0x801C7560: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C7564: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x801C7568: sub.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x801C756C: lwc1        $f6, 0x388($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X388);
    // 0x801C7570: swc1        $f8, 0x368($s0)
    MEM_W(0X368, ctx->r16) = ctx->f8.u32l;
    // 0x801C7574: lwc1        $f16, 0xE80($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XE80);
    // 0x801C7578: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x801C757C: swc1        $f4, 0x370($s0)
    MEM_W(0X370, ctx->r16) = ctx->f4.u32l;
    // 0x801C7580: lwc1        $f12, 0x368($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X368);
L_801C7584:
    // 0x801C7584: c.lt.s      $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f12.fl < ctx->f26.fl;
    // 0x801C7588: nop

    // 0x801C758C: bc1fl       L_801C75A0
    if (!c1cs) {
        // 0x801C7590: mov.s       $f24, $f12
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
            goto L_801C75A0;
    }
    goto skip_108;
    // 0x801C7590: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    skip_108:
    // 0x801C7594: b           L_801C75A0
    // 0x801C7598: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
        goto L_801C75A0;
    // 0x801C7598: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
    // 0x801C759C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
L_801C75A0:
    // 0x801C75A0: c.lt.s      $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f30.fl < ctx->f26.fl;
    // 0x801C75A4: nop

    // 0x801C75A8: bc1fl       L_801C75BC
    if (!c1cs) {
        // 0x801C75AC: mov.s       $f0, $f30
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
            goto L_801C75BC;
    }
    goto skip_109;
    // 0x801C75AC: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
    skip_109:
    // 0x801C75B0: b           L_801C75BC
    // 0x801C75B4: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
        goto L_801C75BC;
    // 0x801C75B4: neg.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = -ctx->f30.fl;
    // 0x801C75B8: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
L_801C75BC:
    // 0x801C75BC: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C75C0: nop

    // 0x801C75C4: bc1fl       L_801C75D4
    if (!c1cs) {
        // 0x801C75C8: lwc1        $f2, 0x370($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
            goto L_801C75D4;
    }
    goto skip_110;
    // 0x801C75C8: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
    skip_110:
    // 0x801C75CC: mov.s       $f30, $f12
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    ctx->f30.fl = ctx->f12.fl;
    // 0x801C75D0: lwc1        $f2, 0x370($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X370);
L_801C75D4:
    // 0x801C75D4: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
    // 0x801C75D8: nop

    // 0x801C75DC: bc1fl       L_801C75F0
    if (!c1cs) {
        // 0x801C75E0: mov.s       $f24, $f2
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
            goto L_801C75F0;
    }
    goto skip_111;
    // 0x801C75E0: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
    skip_111:
    // 0x801C75E4: b           L_801C75F0
    // 0x801C75E8: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
        goto L_801C75F0;
    // 0x801C75E8: neg.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = -ctx->f2.fl;
    // 0x801C75EC: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_801C75F0:
    // 0x801C75F0: c.lt.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl < ctx->f26.fl;
    // 0x801C75F4: nop

    // 0x801C75F8: bc1fl       L_801C760C
    if (!c1cs) {
        // 0x801C75FC: mov.s       $f0, $f28
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
            goto L_801C760C;
    }
    goto skip_112;
    // 0x801C75FC: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
    skip_112:
    // 0x801C7600: b           L_801C760C
    // 0x801C7604: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
        goto L_801C760C;
    // 0x801C7604: neg.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = -ctx->f28.fl;
    // 0x801C7608: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_801C760C:
    // 0x801C760C: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x801C7610: nop

    // 0x801C7614: bc1fl       L_801C7624
    if (!c1cs) {
        // 0x801C7618: c.eq.s      $f26, $f12
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
            goto L_801C7624;
    }
    goto skip_113;
    // 0x801C7618: c.eq.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
    skip_113:
    // 0x801C761C: mov.s       $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
    // 0x801C7620: c.eq.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl == ctx->f12.fl;
L_801C7624:
    // 0x801C7624: nop

    // 0x801C7628: bc1fl       L_801C7644
    if (!c1cs) {
        // 0x801C762C: lw          $t1, 0xEC4($s0)
        ctx->r9 = MEM_W(ctx->r16, 0XEC4);
            goto L_801C7644;
    }
    goto skip_114;
    // 0x801C762C: lw          $t1, 0xEC4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XEC4);
    skip_114:
    // 0x801C7630: c.eq.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl == ctx->f2.fl;
    // 0x801C7634: nop

    // 0x801C7638: bc1tl       L_801C7654
    if (c1cs) {
        // 0x801C763C: lhu         $t4, 0x2($s2)
        ctx->r12 = MEM_HU(ctx->r18, 0X2);
            goto L_801C7654;
    }
    goto skip_115;
    // 0x801C763C: lhu         $t4, 0x2($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X2);
    skip_115:
    // 0x801C7640: lw          $t1, 0xEC4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XEC4);
L_801C7644:
    // 0x801C7644: lhu         $t2, 0x0($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X0);
    // 0x801C7648: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x801C764C: sw          $t3, 0xEC4($s0)
    MEM_W(0XEC4, ctx->r16) = ctx->r11;
    // 0x801C7650: lhu         $t4, 0x2($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X2);
L_801C7654:
    // 0x801C7654: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801C7658: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801C765C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801C7660: addu        $v0, $s0, $t5
    ctx->r2 = ADD32(ctx->r16, ctx->r13);
    // 0x801C7664: lwc1        $f8, 0xE40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XE40);
    // 0x801C7668: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801C766C: lwc1        $f18, 0xE00($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XE00);
    // 0x801C7670: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801C7674: lwc1        $f10, 0xE80($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE80);
    // 0x801C7678: sub.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f6.d - ctx->f16.d;
    // 0x801C767C: lwc1        $f14, 0xD80($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x801C7680: add.s       $f12, $f18, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f30.fl;
    // 0x801C7684: add.s       $f0, $f10, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x801C7688: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801C768C: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x801C7690: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801C7694: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801C7698: jal         0x801C5A1C
    // 0x801C769C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_55;
    // 0x801C769C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_55:
    // 0x801C76A0: beq         $v0, $zero, L_801C776C
    if (ctx->r2 == 0) {
        // 0x801C76A4: nop
    
            goto L_801C776C;
    }
    // 0x801C76A4: nop

    // 0x801C76A8: lbu         $t6, 0x35A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X35A);
    // 0x801C76AC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801C76B0: beq         $t6, $at, L_801C776C
    if (ctx->r14 == ctx->r1) {
        // 0x801C76B4: nop
    
            goto L_801C776C;
    }
    // 0x801C76B4: nop

    // 0x801C76B8: lwc1        $f10, 0x36C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X36C);
    // 0x801C76BC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801C76C0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C76C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C76C8: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801C76CC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801C76D0: c.le.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d <= ctx->f8.d;
    // 0x801C76D4: nop

    // 0x801C76D8: bc1fl       L_801C7718
    if (!c1cs) {
        // 0x801C76DC: lwc1        $f8, 0x360($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X360);
            goto L_801C7718;
    }
    goto skip_116;
    // 0x801C76DC: lwc1        $f8, 0x360($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X360);
    skip_116:
    // 0x801C76E0: lhu         $t7, 0x2($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X2);
    // 0x801C76E4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801C76E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C76EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801C76F0: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x801C76F4: lwc1        $f16, 0xE40($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XE40);
    // 0x801C76F8: lwc1        $f8, 0x384($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X384);
    // 0x801C76FC: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801C7700: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801C7704: sub.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f4.d - ctx->f18.d;
    // 0x801C7708: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x801C770C: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x801C7710: swc1        $f4, 0x36C($s0)
    MEM_W(0X36C, ctx->r16) = ctx->f4.u32l;
    // 0x801C7714: lwc1        $f8, 0x360($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X360);
L_801C7718:
    // 0x801C7718: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x801C771C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C7720: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801C7724: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C7728: c.eq.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d == ctx->f6.d;
    // 0x801C772C: nop

    // 0x801C7730: bc1t        L_801C776C
    if (c1cs) {
        // 0x801C7734: nop
    
            goto L_801C776C;
    }
    // 0x801C7734: nop

    // 0x801C7738: lwc1        $f0, 0x36C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X36C);
    // 0x801C773C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x801C7740: nop

    // 0x801C7744: bc1fl       L_801C7754
    if (!c1cs) {
        // 0x801C7748: c.eq.s      $f26, $f0
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl == ctx->f0.fl;
            goto L_801C7754;
    }
    goto skip_117;
    // 0x801C7748: c.eq.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl == ctx->f0.fl;
    skip_117:
    // 0x801C774C: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x801C7750: c.eq.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl == ctx->f0.fl;
L_801C7754:
    // 0x801C7754: nop

    // 0x801C7758: bc1t        L_801C776C
    if (c1cs) {
        // 0x801C775C: nop
    
            goto L_801C776C;
    }
    // 0x801C775C: nop

    // 0x801C7760: lw          $t0, 0xEC4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XEC4);
    // 0x801C7764: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x801C7768: sw          $t1, 0xEC4($s0)
    MEM_W(0XEC4, ctx->r16) = ctx->r9;
L_801C776C:
    // 0x801C776C: lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X4);
L_801C7770:
    // 0x801C7770: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x801C7774: bnel        $v1, $zero, L_801C5B38
    if (ctx->r3 != 0) {
        // 0x801C7778: lw          $t4, 0xEC0($s0)
        ctx->r12 = MEM_W(ctx->r16, 0XEC0);
            goto L_801C5B38;
    }
    goto skip_118;
    // 0x801C7778: lw          $t4, 0xEC0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XEC0);
    skip_118:
L_801C777C:
    // 0x801C777C: lw          $v0, 0xEC4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XEC4);
L_801C7780:
    // 0x801C7780: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x801C7784: beq         $t2, $zero, L_801C77D0
    if (ctx->r10 == 0) {
        // 0x801C7788: andi        $t3, $v0, 0x20
        ctx->r11 = ctx->r2 & 0X20;
            goto L_801C77D0;
    }
    // 0x801C7788: andi        $t3, $v0, 0x20
    ctx->r11 = ctx->r2 & 0X20;
    // 0x801C778C: beq         $t3, $zero, L_801C77D0
    if (ctx->r11 == 0) {
        // 0x801C7790: lui         $v1, 0x801E
        ctx->r3 = S32(0X801E << 16);
            goto L_801C77D0;
    }
    // 0x801C7790: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C7794: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x801C7798: addiu       $v1, $v1, 0x4020
    ctx->r3 = ADD32(ctx->r3, 0X4020);
    // 0x801C779C: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C77A0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801C77A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C77A8: swc1        $f16, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f16.u32l;
    // 0x801C77AC: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801C77B0: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x801C77B4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C77B8: swc1        $f4, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f4.u32l;
    // 0x801C77BC: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801C77C0: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x801C77C4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C77C8: b           L_801C783C
    // 0x801C77CC: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
        goto L_801C783C;
    // 0x801C77CC: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
L_801C77D0:
    // 0x801C77D0: lw          $t0, 0x2C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X2C);
    // 0x801C77D4: andi        $t1, $t0, 0x200
    ctx->r9 = ctx->r8 & 0X200;
    // 0x801C77D8: beql        $t1, $zero, L_801C783C
    if (ctx->r9 == 0) {
        // 0x801C77DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C783C;
    }
    goto skip_119;
    // 0x801C77DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_119:
    // 0x801C77E0: lbu         $v0, 0xEF6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XEF6);
    // 0x801C77E4: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x801C77E8: beq         $v0, $at, L_801C77F8
    if (ctx->r2 == ctx->r1) {
        // 0x801C77EC: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_801C77F8;
    }
    // 0x801C77EC: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801C77F0: bnel        $v0, $at, L_801C7800
    if (ctx->r2 != ctx->r1) {
        // 0x801C77F4: lw          $t2, 0x9C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X9C);
            goto L_801C7800;
    }
    goto skip_120;
    // 0x801C77F4: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    skip_120:
L_801C77F8:
    // 0x801C77F8: swc1        $f26, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f26.u32l;
    // 0x801C77FC: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
L_801C7800:
    // 0x801C7800: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801C7804: add.s       $f6, $f18, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f30.fl;
    // 0x801C7808: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x801C780C: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x801C7810: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801C7814: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801C7818: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801C781C: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x801C7820: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x801C7824: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801C7828: add.s       $f18, $f8, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x801C782C: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x801C7830: b           L_801C783C
    // 0x801C7834: lhu         $v0, 0xEC6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XEC6);
        goto L_801C783C;
    // 0x801C7834: lhu         $v0, 0xEC6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XEC6);
    // 0x801C7838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C783C:
    // 0x801C783C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x801C7840: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801C7844: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801C7848: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801C784C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x801C7850: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x801C7854: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x801C7858: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801C785C: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x801C7860: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x801C7864: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x801C7868: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x801C786C: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x801C7870: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x801C7874: jr          $ra
    // 0x801C7878: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x801C7878: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c787c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c787c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C787C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801C7880: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C7884: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801C7888: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x801C788C: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x801C7890: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x801C7894: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x801C7898: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801C789C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801C78A0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801C78A4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801C78A8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801C78AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801C78B0: addiu       $t6, $t6, 0xB78
    ctx->r14 = ADD32(ctx->r14, 0XB78);
    // 0x801C78B4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801C78B8: addiu       $s5, $sp, 0x58
    ctx->r21 = ADD32(ctx->r29, 0X58);
    // 0x801C78BC: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x801C78C0: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x801C78C4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801C78C8: sw          $t7, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r15;
    // 0x801C78CC: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x801C78D0: andi        $t0, $t9, 0x100
    ctx->r8 = ctx->r25 & 0X100;
    // 0x801C78D4: beql        $t0, $zero, L_801C7AE8
    if (ctx->r8 == 0) {
        // 0x801C78D8: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801C7AE8;
    }
    goto skip_0;
    // 0x801C78D8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x801C78DC: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x801C78E0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x801C78E4: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x801C78E8: beq         $t1, $zero, L_801C78FC
    if (ctx->r9 == 0) {
        // 0x801C78EC: and         $t3, $v0, $at
        ctx->r11 = ctx->r2 & ctx->r1;
            goto L_801C78FC;
    }
    // 0x801C78EC: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x801C78F0: ori         $t2, $v0, 0x2
    ctx->r10 = ctx->r2 | 0X2;
    // 0x801C78F4: b           L_801C7900
    // 0x801C78F8: sw          $t2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r10;
        goto L_801C7900;
    // 0x801C78F8: sw          $t2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r10;
L_801C78FC:
    // 0x801C78FC: sw          $t3, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r11;
L_801C7900:
    // 0x801C7900: lw          $t4, 0x30($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X30);
    // 0x801C7904: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x801C7908: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x801C790C: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x801C7910: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x801C7914: sw          $t5, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r13;
    // 0x801C7918: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x801C791C: jal         0x801C5A5C
    // 0x801C7920: sw          $t7, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r15;
    LOOKUP_FUNC(0x801C5A5C)(rdram, ctx);
        goto after_0;
    // 0x801C7920: sw          $t7, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r15;
    after_0:
    // 0x801C7924: lui         $s7, 0x801C
    ctx->r23 = S32(0X801C << 16);
    // 0x801C7928: addiu       $s7, $s7, -0x4410
    ctx->r23 = ADD32(ctx->r23, -0X4410);
    // 0x801C792C: lw          $t8, 0xEC4($s7)
    ctx->r24 = MEM_W(ctx->r23, 0XEC4);
    // 0x801C7930: sh          $v0, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r2;
    // 0x801C7934: beq         $v0, $zero, L_801C7AE4
    if (ctx->r2 == 0) {
        // 0x801C7938: sw          $t8, 0x58($s6)
        MEM_W(0X58, ctx->r22) = ctx->r24;
            goto L_801C7AE4;
    }
    // 0x801C7938: sw          $t8, 0x58($s6)
    MEM_W(0X58, ctx->r22) = ctx->r24;
    // 0x801C793C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801C7940: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801C7944: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x801C7948: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801C794C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C7950: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x801C7954: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
L_801C7958:
    // 0x801C7958: multu       $s2, $s4
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C795C: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x801C7960: addu        $s1, $s5, $t9
    ctx->r17 = ADD32(ctx->r21, ctx->r25);
    // 0x801C7964: mflo        $v1
    ctx->r3 = lo;
    // 0x801C7968: addu        $v0, $s7, $v1
    ctx->r2 = ADD32(ctx->r23, ctx->r3);
    // 0x801C796C: lwc1        $f0, 0xED8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XED8);
    // 0x801C7970: lwc1        $f2, 0xEDC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XEDC);
    // 0x801C7974: lwc1        $f14, 0xEE0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XEE0);
    // 0x801C7978: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C797C: addu        $s0, $s3, $v1
    ctx->r16 = ADD32(ctx->r19, ctx->r3);
    // 0x801C7980: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x801C7984: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C7988: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x801C798C: swc1        $f14, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f14.u32l;
    // 0x801C7990: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C7994: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801C7998: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801C799C: jal         0x8002FC20
    // 0x801C79A0: swc1        $f12, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f12.u32l;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x801C79A0: swc1        $f12, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f12.u32l;
    after_1:
    // 0x801C79A4: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x801C79A8: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x801C79AC: c.eq.d      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.d == ctx->f16.d;
    // 0x801C79B0: nop

    // 0x801C79B4: bc1tl       L_801C79D4
    if (c1cs) {
        // 0x801C79B8: swc1        $f22, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->f22.u32l;
            goto L_801C79D4;
    }
    goto skip_1;
    // 0x801C79B8: swc1        $f22, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f22.u32l;
    skip_1:
    // 0x801C79BC: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C79C0: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801C79C4: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801C79C8: b           L_801C79D4
    // 0x801C79CC: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
        goto L_801C79D4;
    // 0x801C79CC: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x801C79D0: swc1        $f22, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f22.u32l;
L_801C79D4:
    // 0x801C79D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C79D8: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801C79DC: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x801C79E0: bne         $at, $zero, L_801C7958
    if (ctx->r1 != 0) {
        // 0x801C79E4: lhu         $v1, 0x54($sp)
        ctx->r3 = MEM_HU(ctx->r29, 0X54);
            goto L_801C7958;
    }
    // 0x801C79E4: lhu         $v1, 0x54($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X54);
    // 0x801C79E8: andi        $t0, $v1, 0x1
    ctx->r8 = ctx->r3 & 0X1;
    // 0x801C79EC: beq         $t0, $zero, L_801C7A24
    if (ctx->r8 == 0) {
        // 0x801C79F0: andi        $t3, $v1, 0x20
        ctx->r11 = ctx->r3 & 0X20;
            goto L_801C7A24;
    }
    // 0x801C79F0: andi        $t3, $v1, 0x20
    ctx->r11 = ctx->r3 & 0X20;
    // 0x801C79F4: lbu         $v0, 0xEF6($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0XEF6);
    // 0x801C79F8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x801C79FC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x801C7A00: beql        $a0, $v0, L_801C7A28
    if (ctx->r4 == ctx->r2) {
        // 0x801C7A04: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_801C7A28;
    }
    goto skip_2;
    // 0x801C7A04: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_2:
    // 0x801C7A08: beql        $a1, $v0, L_801C7A28
    if (ctx->r5 == ctx->r2) {
        // 0x801C7A0C: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_801C7A28;
    }
    goto skip_3;
    // 0x801C7A0C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_3:
    // 0x801C7A10: lw          $t1, 0x30($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X30);
    // 0x801C7A14: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801C7A18: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x801C7A1C: sw          $t2, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r10;
    // 0x801C7A20: swc1        $f12, 0x44($s6)
    MEM_W(0X44, ctx->r22) = ctx->f12.u32l;
L_801C7A24:
    // 0x801C7A24: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_801C7A28:
    // 0x801C7A28: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x801C7A2C: beq         $t3, $zero, L_801C7A4C
    if (ctx->r11 == 0) {
        // 0x801C7A30: addiu       $a1, $zero, 0x1A
        ctx->r5 = ADD32(0, 0X1A);
            goto L_801C7A4C;
    }
    // 0x801C7A30: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x801C7A34: lbu         $v0, 0xEF6($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0XEF6);
    // 0x801C7A38: beql        $a0, $v0, L_801C7A50
    if (ctx->r4 == ctx->r2) {
        // 0x801C7A3C: andi        $t4, $v1, 0xFDE
        ctx->r12 = ctx->r3 & 0XFDE;
            goto L_801C7A50;
    }
    goto skip_4;
    // 0x801C7A3C: andi        $t4, $v1, 0xFDE
    ctx->r12 = ctx->r3 & 0XFDE;
    skip_4:
    // 0x801C7A40: beql        $a1, $v0, L_801C7A50
    if (ctx->r5 == ctx->r2) {
        // 0x801C7A44: andi        $t4, $v1, 0xFDE
        ctx->r12 = ctx->r3 & 0XFDE;
            goto L_801C7A50;
    }
    goto skip_5;
    // 0x801C7A44: andi        $t4, $v1, 0xFDE
    ctx->r12 = ctx->r3 & 0XFDE;
    skip_5:
    // 0x801C7A48: swc1        $f12, 0x44($s6)
    MEM_W(0X44, ctx->r22) = ctx->f12.u32l;
L_801C7A4C:
    // 0x801C7A4C: andi        $t4, $v1, 0xFDE
    ctx->r12 = ctx->r3 & 0XFDE;
L_801C7A50:
    // 0x801C7A50: beq         $t4, $zero, L_801C7AE4
    if (ctx->r12 == 0) {
        // 0x801C7A54: lwc1        $f0, 0x70($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
            goto L_801C7AE4;
    }
    // 0x801C7A54: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801C7A58: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801C7A5C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C7A60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C7A64: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801C7A68: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C7A6C: c.eq.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d == ctx->f8.d;
    // 0x801C7A70: nop

    // 0x801C7A74: bc1tl       L_801C7AE8
    if (c1cs) {
        // 0x801C7A78: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801C7AE8;
    }
    goto skip_6;
    // 0x801C7A78: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_6:
    // 0x801C7A7C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801C7A80: nop

    // 0x801C7A84: bc1fl       L_801C7A98
    if (!c1cs) {
        // 0x801C7A88: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_801C7A98;
    }
    goto skip_7;
    // 0x801C7A88: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_7:
    // 0x801C7A8C: b           L_801C7A98
    // 0x801C7A90: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_801C7A98;
    // 0x801C7A90: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x801C7A94: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_801C7A98:
    // 0x801C7A98: ldc1        $f18, 0x2ED8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X2ED8);
    // 0x801C7A9C: cvt.d.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.d = CVT_D_S(ctx->f2.fl);
    // 0x801C7AA0: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x801C7AA4: nop

    // 0x801C7AA8: bc1fl       L_801C7AC4
    if (!c1cs) {
        // 0x801C7AAC: lbu         $v0, 0xEF6($s7)
        ctx->r2 = MEM_BU(ctx->r23, 0XEF6);
            goto L_801C7AC4;
    }
    goto skip_8;
    // 0x801C7AAC: lbu         $v0, 0xEF6($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0XEF6);
    skip_8:
    // 0x801C7AB0: lw          $t5, 0x30($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X30);
    // 0x801C7AB4: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x801C7AB8: b           L_801C7AE4
    // 0x801C7ABC: sw          $t6, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r14;
        goto L_801C7AE4;
    // 0x801C7ABC: sw          $t6, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r14;
    // 0x801C7AC0: lbu         $v0, 0xEF6($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0XEF6);
L_801C7AC4:
    // 0x801C7AC4: beql        $a0, $v0, L_801C7AE8
    if (ctx->r4 == ctx->r2) {
        // 0x801C7AC8: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801C7AE8;
    }
    goto skip_9;
    // 0x801C7AC8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_9:
    // 0x801C7ACC: beql        $a1, $v0, L_801C7AE8
    if (ctx->r5 == ctx->r2) {
        // 0x801C7AD0: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801C7AE8;
    }
    goto skip_10;
    // 0x801C7AD0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_10:
    // 0x801C7AD4: lw          $t7, 0x30($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X30);
    // 0x801C7AD8: swc1        $f12, 0x44($s6)
    MEM_W(0X44, ctx->r22) = ctx->f12.u32l;
    // 0x801C7ADC: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x801C7AE0: sw          $t8, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r24;
L_801C7AE4:
    // 0x801C7AE4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801C7AE8:
    // 0x801C7AE8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801C7AEC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801C7AF0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801C7AF4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801C7AF8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801C7AFC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801C7B00: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x801C7B04: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x801C7B08: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x801C7B0C: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x801C7B10: jr          $ra
    // 0x801C7B14: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x801C7B14: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c7b18(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c7b18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7B18: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801C7B1C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801C7B20: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801C7B24: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801C7B28: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801C7B2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801C7B30: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801C7B34: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801C7B38: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C7B3C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C7B40: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C7B44: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801C7B48: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C7B4C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C7B50: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x801C7B54: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C7B58: sub.d       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f0.d - ctx->f10.d;
    // 0x801C7B5C: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C7B60: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C7B64: add.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d + ctx->f6.d;
    // 0x801C7B68: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801C7B6C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801C7B70: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801C7B74: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801C7B78: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x801C7B7C: jal         0x801C5A1C
    // 0x801C7B80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_0;
    // 0x801C7B80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801C7B84: beq         $v0, $zero, L_801C7BD8
    if (ctx->r2 == 0) {
        // 0x801C7B88: nop
    
            goto L_801C7BD8;
    }
    // 0x801C7B88: nop

    // 0x801C7B8C: lwc1        $f0, 0x35C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X35C);
    // 0x801C7B90: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x801C7B94: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801C7B98: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801C7B9C: lwc1        $f6, 0x360($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X360);
    // 0x801C7BA0: c.eq.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d == ctx->f8.d;
    // 0x801C7BA4: lwc1        $f12, 0x364($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X364);
    // 0x801C7BA8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x801C7BAC: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x801C7BB0: bc1f        L_801C7BD0
    if (!c1cs) {
        // 0x801C7BB4: nop
    
            goto L_801C7BD0;
    }
    // 0x801C7BB4: nop

    // 0x801C7BB8: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x801C7BBC: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    // 0x801C7BC0: c.eq.d      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.d == ctx->f10.d;
    // 0x801C7BC4: nop

    // 0x801C7BC8: bc1tl       L_801C7BE4
    if (c1cs) {
        // 0x801C7BCC: lw          $v0, 0xDC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XDC);
            goto L_801C7BE4;
    }
    goto skip_0;
    // 0x801C7BCC: lw          $v0, 0xDC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDC);
    skip_0:
L_801C7BD0:
    // 0x801C7BD0: b           L_801C7FD8
    // 0x801C7BD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C7FD8;
    // 0x801C7BD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C7BD8:
    // 0x801C7BD8: b           L_801C7FD8
    // 0x801C7BDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C7FD8;
    // 0x801C7BDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C7BE0: lw          $v0, 0xDC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDC);
L_801C7BE4:
    // 0x801C7BE4: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801C7BE8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C7BEC: lbu         $t8, 0x4D($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4D);
    // 0x801C7BF0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C7BF4: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801C7BF8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x801C7BFC: bgez        $t8, L_801C7C10
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C7C00: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801C7C10;
    }
    // 0x801C7C00: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801C7C04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C7C08: nop

    // 0x801C7C0C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801C7C10:
    // 0x801C7C10: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x801C7C14: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C7C18: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801C7C1C: lb          $t9, 0x4F($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X4F);
    // 0x801C7C20: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801C7C24: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801C7C28: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801C7C2C: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x801C7C30: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801C7C34: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C7C38: add.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f4.d + ctx->f18.d;
    // 0x801C7C3C: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801C7C40: add.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f4.d + ctx->f8.d;
    // 0x801C7C44: jal         0x8001EAD0
    // 0x801C7C48: cvt.s.d     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f20.fl = CVT_S_D(ctx->f18.d);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801C7C48: cvt.s.d     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f20.fl = CVT_S_D(ctx->f18.d);
    after_1:
    // 0x801C7C4C: lw          $t0, 0xDC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XDC);
    // 0x801C7C50: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C7C54: lbu         $t1, 0x4D($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4D);
    // 0x801C7C58: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801C7C5C: bgez        $t1, L_801C7C70
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801C7C60: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C7C70;
    }
    // 0x801C7C60: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C7C64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C7C68: nop

    // 0x801C7C6C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_801C7C70:
    // 0x801C7C70: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801C7C74: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801C7C78: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x801C7C7C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C7C80: jal         0x8001EB64
    // 0x801C7C84: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801C7C84: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_2:
    // 0x801C7C88: lw          $t4, 0xDC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XDC);
    // 0x801C7C8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C7C90: lbu         $t5, 0x4D($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X4D);
    // 0x801C7C94: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x801C7C98: bgez        $t5, L_801C7CAC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801C7C9C: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801C7CAC;
    }
    // 0x801C7C9C: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801C7CA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C7CA4: nop

    // 0x801C7CA8: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_801C7CAC:
    // 0x801C7CAC: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801C7CB0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C7CB4: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801C7CB8: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801C7CBC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x801C7CC0: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C7CC4: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C7CC8: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x801C7CCC: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x801C7CD0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801C7CD4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801C7CD8: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x801C7CDC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801C7CE0: jal         0x801C5A1C
    // 0x801C7CE4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_3;
    // 0x801C7CE4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x801C7CE8: lwc1        $f4, 0x380($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X380);
    // 0x801C7CEC: lwc1        $f10, 0x384($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X384);
    // 0x801C7CF0: lwc1        $f6, 0x388($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X388);
    // 0x801C7CF4: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801C7CF8: sb          $v0, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r2;
    // 0x801C7CFC: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x801C7D00: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x801C7D04: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x801C7D08: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801C7D0C: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801C7D10: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801C7D14: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C7D18: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C7D1C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801C7D20: sub.s       $f18, $f12, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x801C7D24: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801C7D28: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x801C7D2C: sub.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x801C7D30: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801C7D34: jal         0x801C5A1C
    // 0x801C7D38: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_4;
    // 0x801C7D38: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x801C7D3C: lbu         $t8, 0x53($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X53);
    // 0x801C7D40: lwc1        $f10, 0x380($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X380);
    // 0x801C7D44: lwc1        $f6, 0x384($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X384);
    // 0x801C7D48: lwc1        $f8, 0x388($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X388);
    // 0x801C7D4C: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x801C7D50: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x801C7D54: beq         $t8, $zero, L_801C7DE4
    if (ctx->r24 == 0) {
        // 0x801C7D58: swc1        $f8, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
            goto L_801C7DE4;
    }
    // 0x801C7D58: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x801C7D5C: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x801C7D60: beq         $t9, $zero, L_801C7DE4
    if (ctx->r25 == 0) {
        // 0x801C7D64: addiu       $t0, $sp, 0x6C
        ctx->r8 = ADD32(ctx->r29, 0X6C);
            goto L_801C7DE4;
    }
    // 0x801C7D64: addiu       $t0, $sp, 0x6C
    ctx->r8 = ADD32(ctx->r29, 0X6C);
    // 0x801C7D68: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801C7D6C: addiu       $t3, $sp, 0x60
    ctx->r11 = ADD32(ctx->r29, 0X60);
    // 0x801C7D70: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x801C7D74: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x801C7D78: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801C7D7C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C7D80: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x801C7D84: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C7D88: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801C7D8C: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x801C7D90: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801C7D94: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801C7D98: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C7D9C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801C7DA0: jal         0x800075B4
    // 0x801C7DA4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x800075B4)(rdram, ctx);
        goto after_5;
    // 0x801C7DA4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_5:
    // 0x801C7DA8: lw          $t6, 0xDC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XDC);
    // 0x801C7DAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C7DB0: lbu         $t7, 0x4D($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4D);
    // 0x801C7DB4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x801C7DB8: bgez        $t7, L_801C7DCC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C7DBC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801C7DCC;
    }
    // 0x801C7DBC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801C7DC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C7DC4: nop

    // 0x801C7DC8: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_801C7DCC:
    // 0x801C7DCC: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x801C7DD0: nop

    // 0x801C7DD4: bc1fl       L_801C7DE8
    if (!c1cs) {
        // 0x801C7DD8: lw          $t8, 0xE0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XE0);
            goto L_801C7DE8;
    }
    goto skip_1;
    // 0x801C7DD8: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    skip_1:
    // 0x801C7DDC: b           L_801C7FD8
    // 0x801C7DE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C7FD8;
    // 0x801C7DE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C7DE4:
    // 0x801C7DE4: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
L_801C7DE8:
    // 0x801C7DE8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801C7DEC: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    // 0x801C7DF0: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C7DF4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C7DF8: jal         0x8001EAD0
    // 0x801C7DFC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x801C7DFC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_6:
    // 0x801C7E00: lw          $t0, 0xDC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XDC);
    // 0x801C7E04: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C7E08: lbu         $t1, 0x4C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4C);
    // 0x801C7E0C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x801C7E10: bgez        $t1, L_801C7E24
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801C7E14: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801C7E24;
    }
    // 0x801C7E14: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C7E18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C7E1C: nop

    // 0x801C7E20: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_801C7E24:
    // 0x801C7E24: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801C7E28: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x801C7E2C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801C7E30: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801C7E34: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801C7E38: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801C7E3C: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801C7E40: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x801C7E44: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x801C7E48: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C7E4C: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    // 0x801C7E50: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x801C7E54: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801C7E58: jal         0x8001EB64
    // 0x801C7E5C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_7;
    // 0x801C7E5C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_7:
    // 0x801C7E60: lw          $t4, 0xDC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XDC);
    // 0x801C7E64: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C7E68: lbu         $t5, 0x4C($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X4C);
    // 0x801C7E6C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801C7E70: bgez        $t5, L_801C7E84
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801C7E74: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C7E84;
    }
    // 0x801C7E74: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C7E78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C7E7C: nop

    // 0x801C7E80: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801C7E84:
    // 0x801C7E84: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801C7E88: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x801C7E8C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C7E90: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C7E94: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801C7E98: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801C7E9C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x801C7EA0: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x801C7EA4: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801C7EA8: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801C7EAC: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C7EB0: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C7EB4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801C7EB8: add.s       $f18, $f12, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x801C7EBC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801C7EC0: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x801C7EC4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801C7EC8: add.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x801C7ECC: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x801C7ED0: jal         0x801C5A1C
    // 0x801C7ED4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_8;
    // 0x801C7ED4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x801C7ED8: lwc1        $f10, 0x380($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X380);
    // 0x801C7EDC: lwc1        $f6, 0x384($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X384);
    // 0x801C7EE0: lwc1        $f4, 0x388($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X388);
    // 0x801C7EE4: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801C7EE8: sb          $v0, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r2;
    // 0x801C7EEC: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x801C7EF0: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x801C7EF4: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x801C7EF8: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801C7EFC: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801C7F00: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801C7F04: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801C7F08: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801C7F0C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801C7F10: sub.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x801C7F14: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801C7F18: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x801C7F1C: sub.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x801C7F20: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801C7F24: jal         0x801C5A1C
    // 0x801C7F28: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_9;
    // 0x801C7F28: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x801C7F2C: lbu         $t8, 0x53($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X53);
    // 0x801C7F30: lwc1        $f6, 0x380($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X380);
    // 0x801C7F34: lwc1        $f4, 0x384($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X384);
    // 0x801C7F38: lwc1        $f18, 0x388($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X388);
    // 0x801C7F3C: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x801C7F40: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x801C7F44: beq         $t8, $zero, L_801C7FD4
    if (ctx->r24 == 0) {
        // 0x801C7F48: swc1        $f18, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
            goto L_801C7FD4;
    }
    // 0x801C7F48: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x801C7F4C: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x801C7F50: beq         $t9, $zero, L_801C7FD4
    if (ctx->r25 == 0) {
        // 0x801C7F54: addiu       $t0, $sp, 0x6C
        ctx->r8 = ADD32(ctx->r29, 0X6C);
            goto L_801C7FD4;
    }
    // 0x801C7F54: addiu       $t0, $sp, 0x6C
    ctx->r8 = ADD32(ctx->r29, 0X6C);
    // 0x801C7F58: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801C7F5C: addiu       $t3, $sp, 0x60
    ctx->r11 = ADD32(ctx->r29, 0X60);
    // 0x801C7F60: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x801C7F64: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x801C7F68: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801C7F6C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C7F70: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x801C7F74: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C7F78: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801C7F7C: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x801C7F80: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801C7F84: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801C7F88: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C7F8C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801C7F90: jal         0x800075B4
    // 0x801C7F94: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x800075B4)(rdram, ctx);
        goto after_10;
    // 0x801C7F94: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_10:
    // 0x801C7F98: lw          $t6, 0xDC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XDC);
    // 0x801C7F9C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C7FA0: lbu         $t7, 0x4D($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4D);
    // 0x801C7FA4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801C7FA8: bgez        $t7, L_801C7FBC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C7FAC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801C7FBC;
    }
    // 0x801C7FAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C7FB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C7FB4: nop

    // 0x801C7FB8: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_801C7FBC:
    // 0x801C7FBC: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x801C7FC0: nop

    // 0x801C7FC4: bc1fl       L_801C7FD8
    if (!c1cs) {
        // 0x801C7FC8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801C7FD8;
    }
    goto skip_2;
    // 0x801C7FC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x801C7FCC: b           L_801C7FD8
    // 0x801C7FD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C7FD8;
    // 0x801C7FD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C7FD4:
    // 0x801C7FD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C7FD8:
    // 0x801C7FD8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801C7FDC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801C7FE0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801C7FE4: jr          $ra
    // 0x801C7FE8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x801C7FE8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c7fec(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c7fec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7FEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C7FF0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x801C7FF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C7FF8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801C7FFC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801C8000: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x801C8004: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801C8008: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    // 0x801C800C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801C8010: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x801C8014: jal         0x8010843C
    // 0x801C8018: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_0;
    // 0x801C8018: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801C801C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C8020: bne         $v0, $at, L_801C8050
    if (ctx->r2 != ctx->r1) {
        // 0x801C8024: lw          $t9, 0x2C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X2C);
            goto L_801C8050;
    }
    // 0x801C8024: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x801C8028: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C802C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801C8030: lwc1        $f8, 0x374($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X374);
    // 0x801C8034: swc1        $f8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f8.u32l;
    // 0x801C8038: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801C803C: lwc1        $f10, 0x378($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X378);
    // 0x801C8040: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x801C8044: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x801C8048: lwc1        $f16, 0x37C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X37C);
    // 0x801C804C: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
L_801C8050:
    // 0x801C8050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C8054: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C8058: jr          $ra
    // 0x801C805C: nop

    return;
    // 0x801C805C: nop

;}
RECOMP_FUNC void M8_FUN_801c8060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8060: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C8064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C8068: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801C806C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801C8070: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C8074: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C8078: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801C807C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C8080: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C8084: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C8088: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x801C808C: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801C8090: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801C8094: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C8098: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801C809C: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x801C80A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801C80A4: addiu       $t9, $v0, 0xC
    ctx->r25 = ADD32(ctx->r2, 0XC);
    // 0x801C80A8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801C80AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C80B0: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    // 0x801C80B4: jal         0x801C7FEC
    // 0x801C80B8: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    LOOKUP_FUNC(0x801C7FEC)(rdram, ctx);
        goto after_0;
    // 0x801C80B8: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    after_0:
    // 0x801C80BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C80C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C80C4: jr          $ra
    // 0x801C80C8: nop

    return;
    // 0x801C80C8: nop

;}
RECOMP_FUNC void M8_FUN_801c80cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C80CC: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x801C80D0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801C80D4: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x801C80D8: addiu       $s4, $s4, -0x4410
    ctx->r20 = ADD32(ctx->r20, -0X4410);
    // 0x801C80DC: lw          $v0, 0xDC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XDC);
    // 0x801C80E0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801C80E4: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801C80E8: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801C80EC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801C80F0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801C80F4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801C80F8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801C80FC: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801C8100: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801C8104: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801C8108: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x801C810C: lbu         $t6, 0x4D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4D);
    // 0x801C8110: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x801C8114: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801C8118: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C811C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801C8120: bgez        $t6, L_801C813C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C8124: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801C813C;
    }
    // 0x801C8124: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801C8128: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801C812C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801C8130: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801C8134: nop

    // 0x801C8138: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801C813C:
    // 0x801C813C: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x801C8140: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801C8144: nop

    // 0x801C8148: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801C814C: bne         $v0, $zero, L_801C815C
    if (ctx->r2 != 0) {
        // 0x801C8150: cvt.s.d     $f24, $f16
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f24.fl = CVT_S_D(ctx->f16.d);
            goto L_801C815C;
    }
    // 0x801C8150: cvt.s.d     $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f24.fl = CVT_S_D(ctx->f16.d);
    // 0x801C8154: b           L_801C838C
    // 0x801C8158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C838C;
    // 0x801C8158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C815C:
    // 0x801C815C: lhu         $v0, 0xEF0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0XEF0);
    // 0x801C8160: andi        $t7, $v0, 0x3050
    ctx->r15 = ctx->r2 & 0X3050;
    // 0x801C8164: beql        $t7, $zero, L_801C8178
    if (ctx->r15 == 0) {
        // 0x801C8168: lhu         $t8, 0x18E($s4)
        ctx->r24 = MEM_HU(ctx->r20, 0X18E);
            goto L_801C8178;
    }
    goto skip_0;
    // 0x801C8168: lhu         $t8, 0x18E($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X18E);
    skip_0:
    // 0x801C816C: b           L_801C838C
    // 0x801C8170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C838C;
    // 0x801C8170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C8174: lhu         $t8, 0x18E($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X18E);
L_801C8178:
    // 0x801C8178: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x801C817C: beql        $t8, $zero, L_801C8190
    if (ctx->r24 == 0) {
        // 0x801C8180: swc1        $f12, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
            goto L_801C8190;
    }
    goto skip_1;
    // 0x801C8180: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    skip_1:
    // 0x801C8184: b           L_801C838C
    // 0x801C8188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C838C;
    // 0x801C8188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C818C: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
L_801C8190:
    // 0x801C8190: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    // 0x801C8194: bne         $v0, $at, L_801C8258
    if (ctx->r2 != ctx->r1) {
        // 0x801C8198: swc1        $f20, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->f20.u32l;
            goto L_801C8258;
    }
    // 0x801C8198: swc1        $f20, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f20.u32l;
    // 0x801C819C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801C81A0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801C81A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C81A8: cvt.d.s     $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f18.d = CVT_D_S(ctx->f24.fl);
    // 0x801C81AC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C81B0: mul.d       $f22, $f18, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f22.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x801C81B4: lw          $s1, 0xE0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0XE0);
    // 0x801C81B8: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x801C81BC: addiu       $s5, $sp, 0x80
    ctx->r21 = ADD32(ctx->r29, 0X80);
L_801C81C0:
    // 0x801C81C0: lw          $t9, 0x2C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X2C);
    // 0x801C81C4: jal         0x8001EAD0
    // 0x801C81C8: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x801C81C8: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_0:
    // 0x801C81CC: addiu       $t1, $s2, -0x1
    ctx->r9 = ADD32(ctx->r18, -0X1);
    // 0x801C81D0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801C81D4: lw          $s1, 0xE0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0XE0);
    // 0x801C81D8: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C81DC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C81E0: lw          $t2, 0x2C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X2C);
    // 0x801C81E4: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x801C81E8: mul.s       $f20, $f6, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x801C81EC: mflo        $t0
    ctx->r8 = lo;
    // 0x801C81F0: addu        $s0, $s5, $t0
    ctx->r16 = ADD32(ctx->r21, ctx->r8);
    // 0x801C81F4: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801C81F8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801C81FC: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x801C8200: lw          $t3, 0x2C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X2C);
    // 0x801C8204: lwc1        $f4, 0x8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X8);
    // 0x801C8208: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801C820C: add.d       $f6, $f8, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f22.d); 
    ctx->f6.d = ctx->f8.d + ctx->f22.d;
    // 0x801C8210: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801C8214: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x801C8218: lw          $t4, 0x2C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X2C);
    // 0x801C821C: jal         0x8001EB64
    // 0x801C8220: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801C8220: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_1:
    // 0x801C8224: lw          $s1, 0xE0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0XE0);
    // 0x801C8228: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801C822C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C8230: lw          $t5, 0x2C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X2C);
    // 0x801C8234: sll         $s2, $s2, 24
    ctx->r18 = S32(ctx->r18 << 24);
    // 0x801C8238: sra         $s2, $s2, 24
    ctx->r18 = S32(SIGNED(ctx->r18) >> 24);
    // 0x801C823C: lwc1        $f18, 0xC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XC);
    // 0x801C8240: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x801C8244: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801C8248: bne         $at, $zero, L_801C81C0
    if (ctx->r1 != 0) {
        // 0x801C824C: swc1        $f4, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
            goto L_801C81C0;
    }
    // 0x801C824C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801C8250: b           L_801C82C4
    // 0x801C8254: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
        goto L_801C82C4;
    // 0x801C8254: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
L_801C8258:
    // 0x801C8258: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801C825C: lw          $s1, -0x4330($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X4330);
    // 0x801C8260: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C8264: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x801C8268: addiu       $s5, $sp, 0x80
    ctx->r21 = ADD32(ctx->r29, 0X80);
L_801C826C:
    // 0x801C826C: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C8270: addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
    // 0x801C8274: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x801C8278: lw          $t7, 0x2C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X2C);
    // 0x801C827C: sll         $s2, $v0, 24
    ctx->r18 = S32(ctx->r2 << 24);
    // 0x801C8280: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C8284: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x801C8288: sra         $s2, $s2, 24
    ctx->r18 = S32(SIGNED(ctx->r18) >> 24);
    // 0x801C828C: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x801C8290: mflo        $t6
    ctx->r14 = lo;
    // 0x801C8294: addu        $s0, $s5, $t6
    ctx->r16 = ADD32(ctx->r21, ctx->r14);
    // 0x801C8298: mul.s       $f18, $f24, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f24.fl, ctx->f16.fl);
    // 0x801C829C: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x801C82A0: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
    // 0x801C82A4: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801C82A8: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x801C82AC: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801C82B0: lw          $t9, 0x2C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X2C);
    // 0x801C82B4: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x801C82B8: bne         $at, $zero, L_801C826C
    if (ctx->r1 != 0) {
        // 0x801C82BC: swc1        $f8, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
            goto L_801C826C;
    }
    // 0x801C82BC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x801C82C0: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
L_801C82C4:
    // 0x801C82C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C82C8: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x801C82CC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801C82D0: addiu       $s0, $sp, 0x74
    ctx->r16 = ADD32(ctx->r29, 0X74);
    // 0x801C82D4: add.s       $f20, $f24, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f24.fl + ctx->f10.fl;
L_801C82D8:
    // 0x801C82D8: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C82DC: mflo        $t0
    ctx->r8 = lo;
    // 0x801C82E0: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x801C82E4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801C82E8: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x801C82EC: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    // 0x801C82F0: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801C82F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C82F8: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x801C82FC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C8300: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C8304: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x801C8308: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x801C830C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801C8310: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C8314: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x801C8318: jal         0x800075B4
    // 0x801C831C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x800075B4)(rdram, ctx);
        goto after_2;
    // 0x801C831C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_2:
    // 0x801C8320: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x801C8324: nop

    // 0x801C8328: bc1fl       L_801C8374
    if (!c1cs) {
        // 0x801C832C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_801C8374;
    }
    goto skip_2;
    // 0x801C832C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x801C8330: beql        $s2, $zero, L_801C8354
    if (ctx->r18 == 0) {
        // 0x801C8334: ori         $s3, $s3, 0x1
        ctx->r19 = ctx->r19 | 0X1;
            goto L_801C8354;
    }
    goto skip_3;
    // 0x801C8334: ori         $s3, $s3, 0x1
    ctx->r19 = ctx->r19 | 0X1;
    skip_3:
    // 0x801C8338: beql        $s2, $s1, L_801C8360
    if (ctx->r18 == ctx->r17) {
        // 0x801C833C: ori         $s3, $s3, 0x2
        ctx->r19 = ctx->r19 | 0X2;
            goto L_801C8360;
    }
    goto skip_4;
    // 0x801C833C: ori         $s3, $s3, 0x2
    ctx->r19 = ctx->r19 | 0X2;
    skip_4:
    // 0x801C8340: beql        $s2, $s4, L_801C836C
    if (ctx->r18 == ctx->r20) {
        // 0x801C8344: ori         $s3, $s3, 0x4
        ctx->r19 = ctx->r19 | 0X4;
            goto L_801C836C;
    }
    goto skip_5;
    // 0x801C8344: ori         $s3, $s3, 0x4
    ctx->r19 = ctx->r19 | 0X4;
    skip_5:
    // 0x801C8348: b           L_801C8374
    // 0x801C834C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_801C8374;
    // 0x801C834C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C8350: ori         $s3, $s3, 0x1
    ctx->r19 = ctx->r19 | 0X1;
L_801C8354:
    // 0x801C8354: b           L_801C8370
    // 0x801C8358: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
        goto L_801C8370;
    // 0x801C8358: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801C835C: ori         $s3, $s3, 0x2
    ctx->r19 = ctx->r19 | 0X2;
L_801C8360:
    // 0x801C8360: b           L_801C8370
    // 0x801C8364: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
        goto L_801C8370;
    // 0x801C8364: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // 0x801C8368: ori         $s3, $s3, 0x4
    ctx->r19 = ctx->r19 | 0X4;
L_801C836C:
    // 0x801C836C: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
L_801C8370:
    // 0x801C8370: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_801C8374:
    // 0x801C8374: sll         $s2, $s2, 24
    ctx->r18 = S32(ctx->r18 << 24);
    // 0x801C8378: sra         $s2, $s2, 24
    ctx->r18 = S32(SIGNED(ctx->r18) >> 24);
    // 0x801C837C: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x801C8380: bne         $at, $zero, L_801C82D8
    if (ctx->r1 != 0) {
        // 0x801C8384: nop
    
            goto L_801C82D8;
    }
    // 0x801C8384: nop

    // 0x801C8388: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_801C838C:
    // 0x801C838C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801C8390: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801C8394: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801C8398: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801C839C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801C83A0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801C83A4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801C83A8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801C83AC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801C83B0: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x801C83B4: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x801C83B8: jr          $ra
    // 0x801C83BC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x801C83BC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c83c0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c83c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C83C0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801C83C4: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x801C83C8: lhu         $t6, 0x104($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X104);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c83cc(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c83cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C83CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C83D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C83D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C83D8: sb          $t6, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r14;
    // 0x801C83DC: lhu         $t7, 0x104($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X104);
    // 0x801C83E0: lbu         $v1, 0xF7($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XF7);
    // 0x801C83E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C83E8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801C83EC: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x801C83F0: bne         $at, $zero, L_801C8400
    if (ctx->r1 != 0) {
        // 0x801C83F4: sh          $t8, 0x104($a2)
        MEM_H(0X104, ctx->r6) = ctx->r24;
            goto L_801C8400;
    }
    // 0x801C83F4: sh          $t8, 0x104($a2)
    MEM_H(0X104, ctx->r6) = ctx->r24;
    // 0x801C83F8: sb          $zero, 0xF7($a2)
    MEM_B(0XF7, ctx->r6) = 0;
    // 0x801C83FC: andi        $v1, $zero, 0xFF
    ctx->r3 = 0 & 0XFF;
L_801C8400:
    // 0x801C8400: beq         $v1, $zero, L_801C8428
    if (ctx->r3 == 0) {
        // 0x801C8404: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801C8428;
    }
    // 0x801C8404: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C8408: beq         $v1, $at, L_801C844C
    if (ctx->r3 == ctx->r1) {
        // 0x801C840C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801C844C;
    }
    // 0x801C840C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C8410: beq         $v1, $at, L_801C8470
    if (ctx->r3 == ctx->r1) {
        // 0x801C8414: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801C8470;
    }
    // 0x801C8414: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C8418: beql        $v1, $at, L_801C8498
    if (ctx->r3 == ctx->r1) {
        // 0x801C841C: lbu         $t8, 0xF4($a2)
        ctx->r24 = MEM_BU(ctx->r6, 0XF4);
            goto L_801C8498;
    }
    goto skip_0;
    // 0x801C841C: lbu         $t8, 0xF4($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XF4);
    skip_0:
    // 0x801C8420: b           L_801C84B4
    // 0x801C8424: nop

        goto L_801C84B4;
    // 0x801C8424: nop

L_801C8428:
    // 0x801C8428: lbu         $t9, 0xF4($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XF4);
    // 0x801C842C: addiu       $t1, $zero, 0x29
    ctx->r9 = ADD32(0, 0X29);
    // 0x801C8430: addiu       $t0, $zero, 0x11C
    ctx->r8 = ADD32(0, 0X11C);
    // 0x801C8434: beq         $t9, $zero, L_801C8444
    if (ctx->r25 == 0) {
        // 0x801C8438: nop
    
            goto L_801C8444;
    }
    // 0x801C8438: nop

    // 0x801C843C: b           L_801C84B4
    // 0x801C8440: sh          $t0, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r8;
        goto L_801C84B4;
    // 0x801C8440: sh          $t0, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r8;
L_801C8444:
    // 0x801C8444: b           L_801C84B4
    // 0x801C8448: sh          $t1, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r9;
        goto L_801C84B4;
    // 0x801C8448: sh          $t1, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r9;
L_801C844C:
    // 0x801C844C: lbu         $t2, 0xF4($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XF4);
    // 0x801C8450: addiu       $t4, $zero, 0x2C
    ctx->r12 = ADD32(0, 0X2C);
    // 0x801C8454: addiu       $t3, $zero, 0x11B
    ctx->r11 = ADD32(0, 0X11B);
    // 0x801C8458: beq         $t2, $zero, L_801C8468
    if (ctx->r10 == 0) {
        // 0x801C845C: nop
    
            goto L_801C8468;
    }
    // 0x801C845C: nop

    // 0x801C8460: b           L_801C84B4
    // 0x801C8464: sh          $t3, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r11;
        goto L_801C84B4;
    // 0x801C8464: sh          $t3, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r11;
L_801C8468:
    // 0x801C8468: b           L_801C84B4
    // 0x801C846C: sh          $t4, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r12;
        goto L_801C84B4;
    // 0x801C846C: sh          $t4, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r12;
L_801C8470:
    // 0x801C8470: lbu         $t5, 0xF4($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0XF4);
    // 0x801C8474: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x801C8478: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x801C847C: beq         $t5, $zero, L_801C848C
    if (ctx->r13 == 0) {
        // 0x801C8480: nop
    
            goto L_801C848C;
    }
    // 0x801C8480: nop

    // 0x801C8484: b           L_801C84B4
    // 0x801C8488: sh          $t6, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r14;
        goto L_801C84B4;
    // 0x801C8488: sh          $t6, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r14;
L_801C848C:
    // 0x801C848C: b           L_801C84B4
    // 0x801C8490: sh          $t7, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r15;
        goto L_801C84B4;
    // 0x801C8490: sh          $t7, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r15;
    // 0x801C8494: lbu         $t8, 0xF4($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XF4);
L_801C8498:
    // 0x801C8498: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x801C849C: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x801C84A0: beql        $t8, $zero, L_801C84B4
    if (ctx->r24 == 0) {
        // 0x801C84A4: sh          $t0, 0x36($a0)
        MEM_H(0X36, ctx->r4) = ctx->r8;
            goto L_801C84B4;
    }
    goto skip_1;
    // 0x801C84A4: sh          $t0, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r8;
    skip_1:
    // 0x801C84A8: b           L_801C84B4
    // 0x801C84AC: sh          $t9, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r25;
        goto L_801C84B4;
    // 0x801C84AC: sh          $t9, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r25;
    // 0x801C84B0: sh          $t0, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r8;
L_801C84B4:
    // 0x801C84B4: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801C84B8: addiu       $t1, $t1, -0x7B04
    ctx->r9 = ADD32(ctx->r9, -0X7B04);
    // 0x801C84BC: lhu         $a1, 0x36($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X36);
    // 0x801C84C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C84C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C84C8: jal         0x8013B570
    // 0x801C84CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801C84CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801C84D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C84D4: jal         0x801C86C4
    // 0x801C84D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x801C86C4)(rdram, ctx);
        goto after_1;
    // 0x801C84D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x801C84DC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C84E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C84E4: jal         0x80005670
    // 0x801C84E8: addiu       $a1, $a1, 0x960
    ctx->r5 = ADD32(ctx->r5, 0X960);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x801C84E8: addiu       $a1, $a1, 0x960
    ctx->r5 = ADD32(ctx->r5, 0X960);
    after_2:
    // 0x801C84EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C84F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C84F4: jr          $ra
    // 0x801C84F8: nop

    return;
    // 0x801C84F8: nop

;}
RECOMP_FUNC void M8_FUN_801c84fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C84FC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C8500: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C8504: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c8508(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c8508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8508: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C850C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C8510: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x801C8514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C8518: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C851C: beq         $v0, $at, L_801C8534
    if (ctx->r2 == ctx->r1) {
        // 0x801C8520: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801C8534;
    }
    // 0x801C8520: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C8524: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x801C8528: beq         $v0, $at, L_801C8534
    if (ctx->r2 == ctx->r1) {
        // 0x801C852C: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_801C8534;
    }
    // 0x801C852C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x801C8530: bne         $v0, $at, L_801C854C
    if (ctx->r2 != ctx->r1) {
        // 0x801C8534: lui         $a1, 0x801E
        ctx->r5 = S32(0X801E << 16);
            goto L_801C854C;
    }
L_801C8534:
    // 0x801C8534: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C8538: addiu       $a1, $a1, 0xBD0
    ctx->r5 = ADD32(ctx->r5, 0XBD0);
    // 0x801C853C: jal         0x80005670
    // 0x801C8540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C8540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801C8544: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C8548: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
L_801C854C:
    // 0x801C854C: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x801C8550: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801C8554: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x801C8558: addiu       $t9, $zero, 0x12
    ctx->r25 = ADD32(0, 0X12);
    // 0x801C855C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C8560: ori         $t8, $t7, 0x3E0
    ctx->r24 = ctx->r15 | 0X3E0;
    // 0x801C8564: sb          $t6, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r14;
    // 0x801C8568: sb          $zero, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = 0;
    // 0x801C856C: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x801C8570: sb          $v0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r2;
    // 0x801C8574: sb          $t9, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = ctx->r25;
    // 0x801C8578: sb          $v0, 0x4E($s0)
    MEM_B(0X4E, ctx->r16) = ctx->r2;
    // 0x801C857C: sb          $t0, 0x4F($s0)
    MEM_B(0X4F, ctx->r16) = ctx->r8;
    // 0x801C8580: lhu         $t2, 0xEF0($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XEF0);
    // 0x801C8584: addiu       $t1, $zero, 0xE7F
    ctx->r9 = ADD32(0, 0XE7F);
    // 0x801C8588: sw          $t1, 0xEFC($v1)
    MEM_W(0XEFC, ctx->r3) = ctx->r9;
    // 0x801C858C: andi        $t3, $t2, 0x100
    ctx->r11 = ctx->r10 & 0X100;
    // 0x801C8590: beq         $t3, $zero, L_801C85A4
    if (ctx->r11 == 0) {
        // 0x801C8594: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801C85A4;
    }
    // 0x801C8594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C8598: ori         $t4, $zero, 0xF181
    ctx->r12 = 0 | 0XF181;
    // 0x801C859C: b           L_801C85AC
    // 0x801C85A0: sw          $t4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r12;
        goto L_801C85AC;
    // 0x801C85A0: sw          $t4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r12;
L_801C85A4:
    // 0x801C85A4: lw          $t5, 0xEFC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XEFC);
    // 0x801C85A8: sw          $t5, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r13;
L_801C85AC:
    // 0x801C85AC: jal         0x801C4A5C
    // 0x801C85B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_1;
    // 0x801C85B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x801C85B4: jal         0x8001F74C
    // 0x801C85B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_2;
    // 0x801C85B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801C85BC: jal         0x8012FF4C
    // 0x801C85C0: nop

    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_3;
    // 0x801C85C0: nop

    after_3:
    // 0x801C85C4: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x801C85C8: bne         $v0, $at, L_801C85E8
    if (ctx->r2 != ctx->r1) {
        // 0x801C85CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801C85E8;
    }
    // 0x801C85CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C85D0: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x801C85D4: addiu       $a1, $a1, 0x71E8
    ctx->r5 = ADD32(ctx->r5, 0X71E8);
    // 0x801C85D8: jal         0x800058DC
    // 0x801C85DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C85DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801C85E0: b           L_801C85F8
    // 0x801C85E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C85F8;
    // 0x801C85E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C85E8:
    // 0x801C85E8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C85EC: jal         0x800058DC
    // 0x801C85F0: addiu       $a1, $a1, -0x79F8
    ctx->r5 = ADD32(ctx->r5, -0X79F8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C85F0: addiu       $a1, $a1, -0x79F8
    ctx->r5 = ADD32(ctx->r5, -0X79F8);
    after_5:
    // 0x801C85F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C85F8:
    // 0x801C85F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C85FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C8600: jr          $ra
    // 0x801C8604: nop

    return;
    // 0x801C8604: nop

;}
RECOMP_FUNC void M8_FUN_801c8608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C860C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C8610: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C8614: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x801C8618: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x801C861C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801C8620: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x801C8624: andi        $v0, $v0, 0x3000
    ctx->r2 = ctx->r2 & 0X3000;
    // 0x801C8628: beq         $v0, $zero, L_801C8654
    if (ctx->r2 == 0) {
        // 0x801C862C: nop
    
            goto L_801C8654;
    }
    // 0x801C862C: nop

    // 0x801C8630: beq         $v0, $at, L_801C868C
    if (ctx->r2 == ctx->r1) {
        // 0x801C8634: lui         $a1, 0x8022
        ctx->r5 = S32(0X8022 << 16);
            goto L_801C868C;
    }
    // 0x801C8634: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x801C8638: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x801C863C: beq         $v0, $at, L_801C86B4
    if (ctx->r2 == ctx->r1) {
        // 0x801C8640: addiu       $at, $zero, 0x3000
        ctx->r1 = ADD32(0, 0X3000);
            goto L_801C86B4;
    }
    // 0x801C8640: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x801C8644: beq         $v0, $at, L_801C869C
    if (ctx->r2 == ctx->r1) {
        // 0x801C8648: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_801C869C;
    }
    // 0x801C8648: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C864C: b           L_801C86AC
    // 0x801C8650: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
        goto L_801C86AC;
    // 0x801C8650: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
L_801C8654:
    // 0x801C8654: lhu         $t6, -0x3520($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3520);
    // 0x801C8658: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C865C: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x801C8660: beq         $t7, $zero, L_801C867C
    if (ctx->r15 == 0) {
        // 0x801C8664: nop
    
            goto L_801C867C;
    }
    // 0x801C8664: nop

    // 0x801C8668: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801C866C: jal         0x800058DC
    // 0x801C8670: addiu       $a1, $a1, -0x414
    ctx->r5 = ADD32(ctx->r5, -0X414);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C8670: addiu       $a1, $a1, -0x414
    ctx->r5 = ADD32(ctx->r5, -0X414);
    after_0:
    // 0x801C8674: b           L_801C86B8
    // 0x801C8678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C86B8;
    // 0x801C8678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C867C:
    // 0x801C867C: jal         0x800058DC
    // 0x801C8680: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C8680: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    after_1:
    // 0x801C8684: b           L_801C86B8
    // 0x801C8688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C86B8;
    // 0x801C8688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C868C:
    // 0x801C868C: jal         0x800058DC
    // 0x801C8690: addiu       $a1, $a1, -0x2730
    ctx->r5 = ADD32(ctx->r5, -0X2730);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C8690: addiu       $a1, $a1, -0x2730
    ctx->r5 = ADD32(ctx->r5, -0X2730);
    after_2:
    // 0x801C8694: b           L_801C86B8
    // 0x801C8698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C86B8;
    // 0x801C8698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C869C:
    // 0x801C869C: jal         0x800058DC
    // 0x801C86A0: addiu       $a1, $a1, 0x1970
    ctx->r5 = ADD32(ctx->r5, 0X1970);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C86A0: addiu       $a1, $a1, 0x1970
    ctx->r5 = ADD32(ctx->r5, 0X1970);
    after_3:
    // 0x801C86A4: b           L_801C86B8
    // 0x801C86A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C86B8;
    // 0x801C86A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C86AC:
    // 0x801C86AC: jal         0x800058DC
    // 0x801C86B0: addiu       $a1, $a1, -0x522C
    ctx->r5 = ADD32(ctx->r5, -0X522C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C86B0: addiu       $a1, $a1, -0x522C
    ctx->r5 = ADD32(ctx->r5, -0X522C);
    after_4:
L_801C86B4:
    // 0x801C86B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C86B8:
    // 0x801C86B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C86BC: jr          $ra
    // 0x801C86C0: nop

    return;
    // 0x801C86C0: nop

;}
RECOMP_FUNC void M8_FUN_801c86c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C86C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C86C8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C86CC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C86D0: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x801C86D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C86D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C86DC: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801C86E0: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x801C86E4: bne         $v0, $at, L_801C86F8
    if (ctx->r2 != ctx->r1) {
        // 0x801C86E8: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_801C86F8;
    }
    // 0x801C86E8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x801C86EC: lhu         $t7, 0xEF2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0XEF2);
    // 0x801C86F0: ori         $t8, $t7, 0x200
    ctx->r24 = ctx->r15 | 0X200;
    // 0x801C86F4: sh          $t8, 0xEF2($v1)
    MEM_H(0XEF2, ctx->r3) = ctx->r24;
L_801C86F8:
    // 0x801C86F8: bne         $v0, $zero, L_801C8718
    if (ctx->r2 != 0) {
        // 0x801C86FC: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_801C8718;
    }
    // 0x801C86FC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x801C8700: jal         0x8013D4A0
    // 0x801C8704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8013D4A0)(rdram, ctx);
        goto after_0;
    // 0x801C8704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x801C8708: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C870C: beq         $v0, $zero, L_801C875C
    if (ctx->r2 == 0) {
        // 0x801C8710: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_801C875C;
    }
    // 0x801C8710: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C8714: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
L_801C8718:
    // 0x801C8718: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801C871C: bnel        $v0, $at, L_801C8740
    if (ctx->r2 != ctx->r1) {
        // 0x801C8720: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_801C8740;
    }
    goto skip_0;
    // 0x801C8720: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    skip_0:
    // 0x801C8724: jal         0x80133A24
    // 0x801C8728: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_1;
    // 0x801C8728: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    after_1:
    // 0x801C872C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C8730: beq         $v0, $zero, L_801C875C
    if (ctx->r2 == 0) {
        // 0x801C8734: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_801C875C;
    }
    // 0x801C8734: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C8738: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x801C873C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
L_801C8740:
    // 0x801C8740: bnel        $v0, $at, L_801C87A8
    if (ctx->r2 != ctx->r1) {
        // 0x801C8744: lhu         $v0, 0xEF2($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0XEF2);
            goto L_801C87A8;
    }
    goto skip_1;
    // 0x801C8744: lhu         $v0, 0xEF2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XEF2);
    skip_1:
    // 0x801C8748: jal         0x80133A24
    // 0x801C874C: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_2;
    // 0x801C874C: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    after_2:
    // 0x801C8750: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C8754: bne         $v0, $zero, L_801C87A4
    if (ctx->r2 != 0) {
        // 0x801C8758: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_801C87A4;
    }
    // 0x801C8758: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
L_801C875C:
    // 0x801C875C: jal         0x801BF1A0
    // 0x801C8760: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_3;
    // 0x801C8760: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x801C8764: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C8768: addiu       $t0, $t0, 0xC18
    ctx->r8 = ADD32(ctx->r8, 0XC18);
    // 0x801C876C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801C8770: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801C8774: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C8778: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C877C: sw          $t2, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r10;
    // 0x801C8780: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x801C8784: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x801C8788: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x801C878C: sw          $t1, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r9;
    // 0x801C8790: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801C8794: sw          $t2, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r10;
    // 0x801C8798: sh          $t3, 0xEF2($v1)
    MEM_H(0XEF2, ctx->r3) = ctx->r11;
    // 0x801C879C: b           L_801C88AC
    // 0x801C87A0: sh          $t4, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r12;
        goto L_801C88AC;
    // 0x801C87A0: sh          $t4, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r12;
L_801C87A4:
    // 0x801C87A4: lhu         $v0, 0xEF2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XEF2);
L_801C87A8:
    // 0x801C87A8: andi        $t5, $v0, 0x100
    ctx->r13 = ctx->r2 & 0X100;
    // 0x801C87AC: beq         $t5, $zero, L_801C882C
    if (ctx->r13 == 0) {
        // 0x801C87B0: andi        $t3, $v0, 0x200
        ctx->r11 = ctx->r2 & 0X200;
            goto L_801C882C;
    }
    // 0x801C87B0: andi        $t3, $v0, 0x200
    ctx->r11 = ctx->r2 & 0X200;
    // 0x801C87B4: lhu         $t6, 0x4($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X4);
    // 0x801C87B8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x801C87BC: bne         $t6, $at, L_801C87D4
    if (ctx->r14 != ctx->r1) {
        // 0x801C87C0: nop
    
            goto L_801C87D4;
    }
    // 0x801C87C0: nop

    // 0x801C87C4: lbu         $t7, 0x3A6($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3A6);
    // 0x801C87C8: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x801C87CC: beq         $t7, $at, L_801C87E8
    if (ctx->r15 == ctx->r1) {
        // 0x801C87D0: nop
    
            goto L_801C87E8;
    }
    // 0x801C87D0: nop

L_801C87D4:
    // 0x801C87D4: jal         0x801BF1A0
    // 0x801C87D8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_4;
    // 0x801C87D8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_4:
    // 0x801C87DC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C87E0: b           L_801C87F8
    // 0x801C87E4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
        goto L_801C87F8;
    // 0x801C87E4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
L_801C87E8:
    // 0x801C87E8: jal         0x801BF1A0
    // 0x801C87EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_5;
    // 0x801C87EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x801C87F0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C87F4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
L_801C87F8:
    // 0x801C87F8: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801C87FC: addiu       $t9, $t9, 0xC00
    ctx->r25 = ADD32(ctx->r25, 0XC00);
    // 0x801C8800: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801C8804: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x801C8808: addiu       $t2, $zero, 0x100
    ctx->r10 = ADD32(0, 0X100);
    // 0x801C880C: sw          $t1, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r9;
    // 0x801C8810: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801C8814: sw          $t0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r8;
    // 0x801C8818: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801C881C: sw          $t1, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r9;
    // 0x801C8820: sh          $zero, 0xEF2($v1)
    MEM_H(0XEF2, ctx->r3) = 0;
    // 0x801C8824: b           L_801C88AC
    // 0x801C8828: sh          $t2, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r10;
        goto L_801C88AC;
    // 0x801C8828: sh          $t2, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r10;
L_801C882C:
    // 0x801C882C: beq         $t3, $zero, L_801C8870
    if (ctx->r11 == 0) {
        // 0x801C8830: lw          $t4, 0x1C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X1C);
            goto L_801C8870;
    }
    // 0x801C8830: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x801C8834: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801C8838: addiu       $t5, $t5, 0xC0C
    ctx->r13 = ADD32(ctx->r13, 0XC0C);
    // 0x801C883C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801C8840: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801C8844: sw          $t7, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r15;
    // 0x801C8848: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801C884C: sw          $t6, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r14;
    // 0x801C8850: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x801C8854: sw          $t7, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r15;
    // 0x801C8858: sh          $zero, 0x6BFC($at)
    MEM_H(0X6BFC, ctx->r1) = 0;
    // 0x801C885C: lhu         $t8, 0xEF0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XEF0);
    // 0x801C8860: sh          $zero, 0xEF2($v1)
    MEM_H(0XEF2, ctx->r3) = 0;
    // 0x801C8864: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x801C8868: b           L_801C88AC
    // 0x801C886C: sh          $t9, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r25;
        goto L_801C88AC;
    // 0x801C886C: sh          $t9, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r25;
L_801C8870:
    // 0x801C8870: jal         0x801BF1A0
    // 0x801C8874: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_6;
    // 0x801C8874: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x801C8878: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801C887C: addiu       $t1, $t1, 0xBF4
    ctx->r9 = ADD32(ctx->r9, 0XBF4);
    // 0x801C8880: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801C8884: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801C8888: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C888C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C8890: sw          $t3, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r11;
    // 0x801C8894: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801C8898: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801C889C: sw          $t2, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r10;
    // 0x801C88A0: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801C88A4: sw          $t3, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r11;
    // 0x801C88A8: sh          $t4, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r12;
L_801C88AC:
    // 0x801C88AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C88B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C88B4: jr          $ra
    // 0x801C88B8: nop

    return;
    // 0x801C88B8: nop

;}
RECOMP_FUNC void M8_FUN_801c88bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C88BC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801C88C0: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801C88C4: lw          $v1, 0xDC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XDC);
    // 0x801C88C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C88CC: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C88D0: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x801C88D4: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801C88D8: addiu       $t8, $t8, 0x4048
    ctx->r24 = ADD32(ctx->r24, 0X4048);
    // 0x801C88DC: sw          $t6, 0x4058($at)
    MEM_W(0X4058, ctx->r1) = ctx->r14;
    // 0x801C88E0: lhu         $t7, 0xEF0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XEF0);
    // 0x801C88E4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C88E8: sh          $t7, 0x4040($at)
    MEM_H(0X4040, ctx->r1) = ctx->r15;
    // 0x801C88EC: lw          $t0, 0x1C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1C);
    // 0x801C88F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C88F4: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x801C88F8: lw          $t9, 0x20($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X20);
    // 0x801C88FC: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x801C8900: lw          $t0, 0x24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X24);
    // 0x801C8904: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x801C8908: lw          $t1, 0x54($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X54);
    // 0x801C890C: jr          $ra
    // 0x801C8910: sw          $t1, 0x4054($at)
    MEM_W(0X4054, ctx->r1) = ctx->r9;
    return;
    // 0x801C8910: sw          $t1, 0x4054($at)
    MEM_W(0X4054, ctx->r1) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c8914(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c8914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8914: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801C8918: lw          $a0, -0x4334($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4334);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c891c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c891c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C891C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C8920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C8924: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801C8928: jal         0x80006214
    // 0x801C892C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801C892C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801C8930: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C8934: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C8938: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C893C: lw          $t7, 0x4058($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4058);
    // 0x801C8940: lw          $t8, 0xDC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XDC);
    // 0x801C8944: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801C8948: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C894C: sw          $t7, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r15;
    // 0x801C8950: lhu         $t9, 0x4040($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X4040);
    // 0x801C8954: addiu       $t0, $t0, 0x4048
    ctx->r8 = ADD32(ctx->r8, 0X4048);
    // 0x801C8958: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801C895C: sh          $t9, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r25;
    // 0x801C8960: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801C8964: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801C8968: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801C896C: sw          $t2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r10;
    // 0x801C8970: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x801C8974: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x801C8978: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x801C897C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801C8980: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801C8984: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x801C8988: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x801C898C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801C8990: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801C8994: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C8998: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x801C899C: jal         0x8013A28C
    // 0x801C89A0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_1;
    // 0x801C89A0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x801C89A4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C89A8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C89AC: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801C89B0: lw          $t5, 0x4054($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4054);
    // 0x801C89B4: lw          $t6, 0xDC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XDC);
    // 0x801C89B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C89BC: sw          $t5, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->r13;
    // 0x801C89C0: jal         0x801C4A5C
    // 0x801C89C4: lw          $a0, 0xDC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XDC);
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_2;
    // 0x801C89C4: lw          $a0, 0xDC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XDC);
    after_2:
    // 0x801C89C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C89CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C89D0: jr          $ra
    // 0x801C89D4: nop

    return;
    // 0x801C89D4: nop

;}
RECOMP_FUNC void M8_FUN_801c89d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C89D8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C89DC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C89E0: lw          $a0, 0xDC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XDC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c89e4(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c89e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C89E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C89E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C89EC: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801C89F0: jal         0x80006214
    // 0x801C89F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801C89F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801C89F8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C89FC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C8A00: lw          $t8, 0xDC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XDC);
    // 0x801C8A04: addiu       $t7, $zero, 0x3E0
    ctx->r15 = ADD32(0, 0X3E0);
    // 0x801C8A08: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x801C8A0C: sw          $t7, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r15;
    // 0x801C8A10: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C8A14: sh          $t9, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r25;
    // 0x801C8A18: addiu       $t0, $t0, 0xBF4
    ctx->r8 = ADD32(ctx->r8, 0XBF4);
    // 0x801C8A1C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801C8A20: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801C8A24: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801C8A28: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801C8A2C: sw          $t2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r10;
    // 0x801C8A30: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x801C8A34: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x801C8A38: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x801C8A3C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801C8A40: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801C8A44: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x801C8A48: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x801C8A4C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801C8A50: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801C8A54: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C8A58: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x801C8A5C: jal         0x8013A28C
    // 0x801C8A60: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_1;
    // 0x801C8A60: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x801C8A64: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C8A68: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C8A6C: lw          $t5, 0xEFC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XEFC);
    // 0x801C8A70: lw          $t6, 0xDC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XDC);
    // 0x801C8A74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C8A78: sw          $t5, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->r13;
    // 0x801C8A7C: jal         0x801C4A5C
    // 0x801C8A80: lw          $a0, 0xDC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XDC);
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_2;
    // 0x801C8A80: lw          $a0, 0xDC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XDC);
    after_2:
    // 0x801C8A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C8A88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C8A8C: jr          $ra
    // 0x801C8A90: nop

    return;
    // 0x801C8A90: nop

;}
RECOMP_FUNC void M8_FUN_801c8a94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8A94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C8A98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801C8A9C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801C8AA0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801C8AA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C8AA8: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x801C8AAC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C8AB0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801C8AB4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801C8AB8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801C8ABC: addiu       $s2, $s2, 0xBE4
    ctx->r18 = ADD32(ctx->r18, 0XBE4);
    // 0x801C8AC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C8AC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_801C8AC8:
    // 0x801C8AC8: jal         0x80005E44
    // 0x801C8ACC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C8ACC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x801C8AD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C8AD4: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x801C8AD8: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x801C8ADC: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x801C8AE0: bnel        $at, $zero, L_801C8AC8
    if (ctx->r1 != 0) {
        // 0x801C8AE4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801C8AC8;
    }
    goto skip_0;
    // 0x801C8AE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x801C8AE8: jal         0x80006214
    // 0x801C8AEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C8AEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C8AF0: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x801C8AF4: addiu       $s2, $s2, 0xC24
    ctx->r18 = ADD32(ctx->r18, 0XC24);
    // 0x801C8AF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C8AFC: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_801C8B00:
    // 0x801C8B00: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C8B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C8B08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801C8B0C: mflo        $t6
    ctx->r14 = lo;
    // 0x801C8B10: addu        $v0, $s2, $t6
    ctx->r2 = ADD32(ctx->r18, ctx->r14);
    // 0x801C8B14: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x801C8B18: jal         0x8012C89C
    // 0x801C8B1C: lhu         $a3, 0x2($v0)
    ctx->r7 = MEM_HU(ctx->r2, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C8B1C: lhu         $a3, 0x2($v0)
    ctx->r7 = MEM_HU(ctx->r2, 0X2);
    after_2:
    // 0x801C8B20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C8B24: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x801C8B28: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x801C8B2C: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x801C8B30: bne         $at, $zero, L_801C8B00
    if (ctx->r1 != 0) {
        // 0x801C8B34: nop
    
            goto L_801C8B00;
    }
    // 0x801C8B34: nop

    // 0x801C8B38: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C8B3C: lwc1        $f0, 0x3020($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3020);
    // 0x801C8B40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801C8B44:
    // 0x801C8B44: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x801C8B48: addu        $v0, $s4, $t7
    ctx->r2 = ADD32(ctx->r20, ctx->r15);
    // 0x801C8B4C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C8B50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C8B54: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x801C8B58: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C8B5C: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x801C8B60: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x801C8B64: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x801C8B68: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801C8B6C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C8B70: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x801C8B74: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801C8B78: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C8B7C: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
    // 0x801C8B80: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801C8B84: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C8B88: bne         $at, $zero, L_801C8B44
    if (ctx->r1 != 0) {
        // 0x801C8B8C: sh          $zero, 0x12($t5)
        MEM_H(0X12, ctx->r13) = 0;
            goto L_801C8B44;
    }
    // 0x801C8B8C: sh          $zero, 0x12($t5)
    MEM_H(0X12, ctx->r13) = 0;
    // 0x801C8B90: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C8B94: addiu       $a1, $a1, -0x7440
    ctx->r5 = ADD32(ctx->r5, -0X7440);
    // 0x801C8B98: jal         0x800058DC
    // 0x801C8B9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C8B9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x801C8BA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801C8BA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C8BA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801C8BAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801C8BB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801C8BB4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801C8BB8: jr          $ra
    // 0x801C8BBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C8BBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c8bc0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c8bc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8BC0: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801C8BC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C8BC8: addiu       $a3, $a3, -0x4410
    ctx->r7 = ADD32(ctx->r7, -0X4410);
    // 0x801C8BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C8BD0:
    // 0x801C8BD0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x801C8BD4: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
    // 0x801C8BD8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801C8BDC: addu        $a2, $a3, $v1
    ctx->r6 = ADD32(ctx->r7, ctx->r3);
    // 0x801C8BE0: lwc1        $f4, 0xE00($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XE00);
    // 0x801C8BE4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C8BE8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801C8BEC: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x801C8BF0: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801C8BF4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801C8BF8: lwc1        $f6, 0xE40($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XE40);
    // 0x801C8BFC: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x801C8C00: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C8C04: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x801C8C08: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x801C8C0C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x801C8C10: lwc1        $f8, 0xE80($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XE80);
    // 0x801C8C14: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C8C18: bne         $at, $zero, L_801C8BD0
    if (ctx->r1 != 0) {
        // 0x801C8C1C: swc1        $f8, 0xC($t1)
        MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
            goto L_801C8BD0;
    }
    // 0x801C8C1C: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801C8C20: jr          $ra
    // 0x801C8C24: nop

    return;
    // 0x801C8C24: nop

;}
RECOMP_FUNC void M8_FUN_801c8c28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8C28: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801C8C2C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801C8C30: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x801C8C34: addiu       $s3, $s3, -0x4410
    ctx->r19 = ADD32(ctx->r19, -0X4410);
    // 0x801C8C38: lw          $v0, 0xDC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XDC);
    // 0x801C8C3C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801C8C40: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801C8C44: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801C8C48: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801C8C4C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801C8C50: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801C8C54: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801C8C58: beq         $v0, $zero, L_801C8E24
    if (ctx->r2 == 0) {
        // 0x801C8C5C: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_801C8E24;
    }
    // 0x801C8C5C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801C8C60: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x801C8C64: beql        $t6, $zero, L_801C8E28
    if (ctx->r14 == 0) {
        // 0x801C8C68: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801C8E28;
    }
    goto skip_0;
    // 0x801C8C68: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x801C8C6C: lbu         $t7, 0xF5($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0XF5);
    // 0x801C8C70: beql        $t7, $zero, L_801C8E28
    if (ctx->r15 == 0) {
        // 0x801C8C74: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801C8E28;
    }
    goto skip_1;
    // 0x801C8C74: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x801C8C78: lhu         $t8, 0x2C($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0X2C);
    // 0x801C8C7C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801C8C80: bne         $t8, $at, L_801C8E1C
    if (ctx->r24 != ctx->r1) {
        // 0x801C8C84: nop
    
            goto L_801C8E1C;
    }
    // 0x801C8C84: nop

    // 0x801C8C88: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x801C8C8C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801C8C90: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801C8C94: lh          $t9, 0x26($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X26);
    // 0x801C8C98: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801C8C9C: mtc1        $zero, $f23
    ctx->f_odd[(23 - 1) * 2] = 0;
    // 0x801C8CA0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801C8CA4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801C8CA8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801C8CAC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C8CB0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801C8CB4: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x801C8CB8: c.eq.d      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.d == ctx->f10.d;
    // 0x801C8CBC: nop

    // 0x801C8CC0: bc1t        L_801C8E1C
    if (c1cs) {
        // 0x801C8CC4: nop
    
            goto L_801C8E1C;
    }
    // 0x801C8CC4: nop

    // 0x801C8CC8: lh          $t0, 0x26($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X26);
    // 0x801C8CCC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x801C8CD0: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x801C8CD4: nop

    // 0x801C8CD8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801C8CDC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801C8CE0: div.d       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f0.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x801C8CE4: cvt.s.d     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f8.fl = CVT_S_D(ctx->f0.d);
L_801C8CE8:
    // 0x801C8CE8: lw          $t7, 0xE0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XE0);
    // 0x801C8CEC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801C8CF0: lw          $t1, 0x38($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X38);
    // 0x801C8CF4: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x801C8CF8: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x801C8CFC: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x801C8D00: nop

    // 0x801C8D04: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C8D08: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801C8D0C: div.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x801C8D10: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C8D14: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x801C8D18: lw          $t4, 0x38($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X38);
    // 0x801C8D1C: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x801C8D20: lh          $t6, 0xA($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XA);
    // 0x801C8D24: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801C8D28: nop

    // 0x801C8D2C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C8D30: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801C8D34: div.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x801C8D38: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801C8D3C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801C8D40: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x801C8D44: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801C8D48: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801C8D4C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801C8D50: sub.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x801C8D54: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C8D58: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C8D5C: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x801C8D60: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C8D64: nop

    // 0x801C8D68: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801C8D6C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801C8D70: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C8D74: jal         0x8002FC20
    // 0x801C8D78: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x801C8D78: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_0:
    // 0x801C8D7C: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x801C8D80: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C8D84: sll         $s1, $s1, 24
    ctx->r17 = S32(ctx->r17 << 24);
    // 0x801C8D88: addu        $v1, $v0, $s0
    ctx->r3 = ADD32(ctx->r2, ctx->r16);
    // 0x801C8D8C: lh          $t8, 0xC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XC);
    // 0x801C8D90: sra         $s1, $s1, 24
    ctx->r17 = S32(SIGNED(ctx->r17) >> 24);
    // 0x801C8D94: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801C8D98: nop

    // 0x801C8D9C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C8DA0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x801C8DA4: nop

    // 0x801C8DA8: bc1f        L_801C8DEC
    if (!c1cs) {
        // 0x801C8DAC: lui         $t9, 0x801E
        ctx->r25 = S32(0X801E << 16);
            goto L_801C8DEC;
    }
    // 0x801C8DAC: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801C8DB0: lbu         $t9, 0xC84($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0XC84);
    // 0x801C8DB4: bnel        $t9, $zero, L_801C8E28
    if (ctx->r25 != 0) {
        // 0x801C8DB8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801C8E28;
    }
    goto skip_2;
    // 0x801C8DB8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x801C8DBC: jal         0x80020DAC
    // 0x801C8DC0: lhu         $a0, 0x12($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X12);
    LOOKUP_FUNC(0x80020DAC)(rdram, ctx);
        goto after_1;
    // 0x801C8DC0: lhu         $a0, 0x12($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X12);
    after_1:
    // 0x801C8DC4: bnel        $v0, $zero, L_801C8E28
    if (ctx->r2 != 0) {
        // 0x801C8DC8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801C8E28;
    }
    goto skip_3;
    // 0x801C8DC8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x801C8DCC: lw          $t0, 0x38($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X38);
    // 0x801C8DD0: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x801C8DD4: jal         0x800208C4
    // 0x801C8DD8: lhu         $a0, 0x12($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X12);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_2;
    // 0x801C8DD8: lhu         $a0, 0x12($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X12);
    after_2:
    // 0x801C8DDC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C8DE0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C8DE4: b           L_801C8E24
    // 0x801C8DE8: sb          $t2, 0xC84($at)
    MEM_B(0XC84, ctx->r1) = ctx->r10;
        goto L_801C8E24;
    // 0x801C8DE8: sb          $t2, 0xC84($at)
    MEM_B(0XC84, ctx->r1) = ctx->r10;
L_801C8DEC:
    // 0x801C8DEC: sll         $s0, $s1, 5
    ctx->r16 = S32(ctx->r17 << 5);
    // 0x801C8DF0: addu        $t3, $v0, $s0
    ctx->r11 = ADD32(ctx->r2, ctx->r16);
    // 0x801C8DF4: lh          $t4, 0x6($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6);
    // 0x801C8DF8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x801C8DFC: nop

    // 0x801C8E00: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C8E04: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801C8E08: div.d       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f0.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x801C8E0C: c.eq.d      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.d == ctx->f0.d;
    // 0x801C8E10: nop

    // 0x801C8E14: bc1fl       L_801C8CE8
    if (!c1cs) {
        // 0x801C8E18: cvt.s.d     $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f8.fl = CVT_S_D(ctx->f0.d);
            goto L_801C8CE8;
    }
    goto skip_4;
    // 0x801C8E18: cvt.s.d     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f8.fl = CVT_S_D(ctx->f0.d);
    skip_4:
L_801C8E1C:
    // 0x801C8E1C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C8E20: sb          $zero, 0xC84($at)
    MEM_B(0XC84, ctx->r1) = 0;
L_801C8E24:
    // 0x801C8E24: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801C8E28:
    // 0x801C8E28: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801C8E2C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801C8E30: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801C8E34: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801C8E38: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801C8E3C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801C8E40: jr          $ra
    // 0x801C8E44: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801C8E44: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801c8e48(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801c8e48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8E48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C8E4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C8E50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C8E54: jal         0x801E0294
    // 0x801C8E58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801E0294)(rdram, ctx);
        goto after_0;
    // 0x801C8E58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C8E5C: jal         0x8001F74C
    // 0x801C8E60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_1;
    // 0x801C8E60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801C8E64: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C8E68: addiu       $a1, $a1, -0x717C
    ctx->r5 = ADD32(ctx->r5, -0X717C);
    // 0x801C8E6C: jal         0x800058DC
    // 0x801C8E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C8E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801C8E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C8E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C8E7C: jr          $ra
    // 0x801C8E80: nop

    return;
    // 0x801C8E80: nop

;}
