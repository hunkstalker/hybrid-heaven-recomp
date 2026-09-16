#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_8013085c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013085C: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x80130860: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80130864: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80130868: lwc1        $f0, -0x7C5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7C5C);
    // 0x8013086C: jr          $ra
    // 0x80130870: nop

    return;
    // 0x80130870: nop

;}
RECOMP_FUNC void M7_FUN_80130874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130874: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80130878: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x8013087C: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80130880: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80130884: slti        $at, $a0, 0x200
    ctx->r1 = SIGNED(ctx->r4) < 0X200 ? 1 : 0;
    // 0x80130888: beq         $at, $zero, L_801308C8
    if (ctx->r1 == 0) {
            // 0x8013088C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    LOOKUP_FUNC(0x801308C8)(rdram, ctx);
    return;
    }
    // 0x8013088C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80130890: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80130894: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80130898: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8013089C: addiu       $v1, $v1, 0x63A0
    ctx->r3 = ADD32(ctx->r3, 0X63A0);
    // 0x801308A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801308A4: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x801308A8: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x801308AC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x801308B0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801308B4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x801308B8: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x801308BC: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x801308C0: jr          $ra
    // 0x801308C4: lwc1        $f0, 0x0($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X0);
    return;
    // 0x801308C4: lwc1        $f0, 0x0($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801308c8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801308c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801308C8: slti        $at, $v0, 0x400
    ctx->r1 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // 0x801308CC: beq         $at, $zero, L_80130910
    if (ctx->r1 == 0) {
            // 0x801308D0: addiu       $t0, $zero, 0x401
    ctx->r8 = ADD32(0, 0X401);
    LOOKUP_FUNC(0x80130910)(rdram, ctx);
    return;
    }
    // 0x801308D0: addiu       $t0, $zero, 0x401
    ctx->r8 = ADD32(0, 0X401);
    // 0x801308D4: subu        $a0, $t0, $v0
    ctx->r4 = SUB32(ctx->r8, ctx->r2);
    // 0x801308D8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801308DC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801308E0: addiu       $v1, $v1, 0x63A0
    ctx->r3 = ADD32(ctx->r3, 0X63A0);
    // 0x801308E4: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x801308E8: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x801308EC: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801308F0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x801308F4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801308F8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x801308FC: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80130900: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x80130904: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80130908: jr          $ra
    // 0x8013090C: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    return;
    // 0x8013090C: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80130910(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80130910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130910: slti        $at, $v0, 0x600
    ctx->r1 = SIGNED(ctx->r2) < 0X600 ? 1 : 0;
    // 0x80130914: beq         $at, $zero, L_80130958
    if (ctx->r1 == 0) {
            // 0x80130918: addiu       $a0, $v0, -0x3FF
    ctx->r4 = ADD32(ctx->r2, -0X3FF);
    LOOKUP_FUNC(0x80130958)(rdram, ctx);
    return;
    }
    // 0x80130918: addiu       $a0, $v0, -0x3FF
    ctx->r4 = ADD32(ctx->r2, -0X3FF);
    // 0x8013091C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80130920: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80130924: addiu       $v1, $v1, 0x63A0
    ctx->r3 = ADD32(ctx->r3, 0X63A0);
    // 0x80130928: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8013092C: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x80130930: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80130934: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80130938: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8013093C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80130940: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80130944: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80130948: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8013094C: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80130950: jr          $ra
    // 0x80130954: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x80130954: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80130958(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80130958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130958: addiu       $t9, $zero, 0x801
    ctx->r25 = ADD32(0, 0X801);
    // 0x8013095C: subu        $a0, $t9, $v0
    ctx->r4 = SUB32(ctx->r25, ctx->r2);
    // 0x80130960: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80130964: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80130968: addiu       $v1, $v1, 0x63A0
    ctx->r3 = ADD32(ctx->r3, 0X63A0);
    // 0x8013096C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80130970: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x80130974: lwc1        $f18, 0x0($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80130978: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8013097C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80130980: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80130984: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x80130988: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x8013098C: lwc1        $f0, 0x0($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80130990: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80130994: jr          $ra
    // 0x80130998: nop

    return;
    // 0x80130998: nop

;}
RECOMP_FUNC void M7_FUN_8013099c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013099C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801309A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801309A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801309A8: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x801309AC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801309B0: jal         0x80130874
    // 0x801309B4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80130874)(rdram, ctx);
        goto after_0;
    // 0x801309B4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x801309B8: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801309BC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801309C0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x801309C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801309C8: c.eq.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl == ctx->f14.fl;
    // 0x801309CC: nop

    // 0x801309D0: bc1fl       L_801309E4
    if (!c1cs) {
        // 0x801309D4: div.s       $f0, $f2, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
            goto L_801309E4;
    }
    goto skip_0;
    // 0x801309D4: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    skip_0:
    // 0x801309D8: b           L_801309E4
    // 0x801309DC: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_801309E4;
    // 0x801309DC: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x801309E0: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
L_801309E4:
    // 0x801309E4: jr          $ra
    // 0x801309E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801309E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801309ec(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801309ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801309EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801309F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801309F4: jal         0x801303D8
    // 0x801309F8: nop

    LOOKUP_FUNC(0x801303D8)(rdram, ctx);
        goto after_0;
    // 0x801309F8: nop

    after_0:
    // 0x801309FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80130A00: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80130A04: sra         $v0, $v0, 6
    ctx->r2 = S32(SIGNED(ctx->r2) >> 6);
    // 0x80130A08: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x80130A0C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80130A10: jr          $ra
    // 0x80130A14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80130A14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80130a18(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80130a18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130A18: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80130A1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80130A20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80130a24(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80130a24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80130A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80130A2C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x80130A30: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x80130A34: jal         0x8002FC20
    // 0x80130A38: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80130A38: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x80130A3C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80130A40: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80130A44: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80130A48: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80130A4C: c.eq.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d == ctx->f2.d;
    // 0x80130A50: nop

    // 0x80130A54: bc1tl       L_80130A70
    if (c1cs) {
        // 0x80130A58: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80130A70;
    }
    goto skip_0;
    // 0x80130A58: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80130A5C: jal         0x80014798
    // 0x80130A60: cvt.s.d     $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f14.fl = CVT_S_D(ctx->f2.d);
    LOOKUP_FUNC(0x80014798)(rdram, ctx);
        goto after_1;
    // 0x80130A60: cvt.s.d     $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f14.fl = CVT_S_D(ctx->f2.d);
    after_1:
    // 0x80130A64: b           L_80130A94
    // 0x80130A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80130A94;
    // 0x80130A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80130A6C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80130A70:
    // 0x80130A70: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80130A74: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80130A78: nop

    // 0x80130A7C: bc1fl       L_80130A90
    if (!c1cs) {
        // 0x80130A80: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80130A90;
    }
    goto skip_1;
    // 0x80130A80: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_1:
    // 0x80130A84: b           L_80130A90
    // 0x80130A88: lwc1        $f0, -0x2968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2968);
        goto L_80130A90;
    // 0x80130A88: lwc1        $f0, -0x2968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2968);
    // 0x80130A8C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80130A90:
    // 0x80130A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80130A94:
    // 0x80130A94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80130A98: jr          $ra
    // 0x80130A9C: nop

    return;
    // 0x80130A9C: nop

;}
RECOMP_FUNC void M7_FUN_80130aa0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130AA0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80130AA4: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80130AA8: lh          $a0, 0x72($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X72);
    // 0x80130AAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80130AB0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80130AB4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80130AB8: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80130ABC: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x80130AC0: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x80130AC4: jal         0x8001EAD0
    // 0x80130AC8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80130AC8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x80130ACC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80130AD0: jal         0x8001EB64
    // 0x80130AD4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80130AD4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x80130AD8: lh          $a0, 0x76($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X76);
    // 0x80130ADC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80130AE0: jal         0x8001EAD0
    // 0x80130AE4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x80130AE4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_2:
    // 0x80130AE8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80130AEC: jal         0x8001EB64
    // 0x80130AF0: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x80130AF0: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80130AF4: lh          $a0, 0x7A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X7A);
    // 0x80130AF8: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80130AFC: jal         0x8001EAD0
    // 0x80130B00: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x80130B00: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_4:
    // 0x80130B04: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80130B08: jal         0x8001EB64
    // 0x80130B0C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x80130B0C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80130B10: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80130B14: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80130B18: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80130B1C: mul.s       $f14, $f22, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x80130B20: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x80130B24: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80130B28: mul.s       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80130B2C: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x80130B30: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80130B34: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80130B38: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x80130B3C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80130B40: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80130B44: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80130B48: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80130B4C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80130B50: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80130B54: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80130B58: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80130B5C: nop

    // 0x80130B60: mul.s       $f8, $f22, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80130B64: sub.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80130B68: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80130B6C: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80130B70: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80130B74: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80130B78: nop

    // 0x80130B7C: mul.s       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80130B80: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80130B84: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80130B88: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80130B8C: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80130B90: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80130B94: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80130B98: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x80130B9C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80130BA0: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80130BA4: nop

    // 0x80130BA8: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80130BAC: nop

    // 0x80130BB0: mul.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80130BB4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80130BB8: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80130BBC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80130BC0: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80130BC4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80130BC8: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80130BCC: nop

    // 0x80130BD0: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80130BD4: sub.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80130BD8: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80130BDC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80130BE0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80130BE4: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x80130BE8: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80130BEC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80130BF0: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80130BF4: nop

    // 0x80130BF8: mul.s       $f6, $f20, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x80130BFC: nop

    // 0x80130C00: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80130C04: nop

    // 0x80130C08: mul.s       $f10, $f22, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x80130C0C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80130C10: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80130C14: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80130C18: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80130C1C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80130C20: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80130C24: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80130C28: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80130C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80130C30: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80130C34: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80130C38: jr          $ra
    // 0x80130C3C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80130C3C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80130c40(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80130c40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130C40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80130C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80130C48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80130C4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80130C50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80130C54: jal         0x8001EAD0
    // 0x80130C58: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80130C58: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x80130C5C: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    // 0x80130C60: jal         0x8001EB64
    // 0x80130C64: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80130C64: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80130C68: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80130C6C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80130C70: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80130C74: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80130C78: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80130C7C: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x80130C80: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80130C84: nop

    // 0x80130C88: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80130C8C: nop

    // 0x80130C90: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80130C94: nop

    // 0x80130C98: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80130C9C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80130CA0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80130CA4: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80130CA8: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80130CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80130CB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80130CB4: jr          $ra
    // 0x80130CB8: nop

    return;
    // 0x80130CB8: nop

;}
RECOMP_FUNC void M7_FUN_80130cbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130CBC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80130CC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80130CC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80130CC8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80130CCC: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80130CD0: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80130CD4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80130CD8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80130CDC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80130CE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80130CE4: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80130CE8: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80130CEC: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80130CF0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80130CF4: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x80130CF8: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80130CFC: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80130D00: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80130D04: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80130D08: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80130D0C: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80130D10: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80130D14: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x80130D18: lwc1        $f18, 0x34($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80130D1C: sub.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80130D20: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80130D24: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80130D28: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80130D2C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80130D30: jal         0x80130F74
    // 0x80130D34: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80130F74)(rdram, ctx);
        goto after_0;
    // 0x80130D34: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80130D38: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80130D3C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80130D40: jal         0x80131074
    // 0x80130D44: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    LOOKUP_FUNC(0x80131074)(rdram, ctx);
        goto after_1;
    // 0x80130D44: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x80130D48: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80130D4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80130D50: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80130D54: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80130D58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80130D5C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80130D60: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80130D64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80130D68: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80130D6C: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80130D70: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80130D74: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80130D78: nop

    // 0x80130D7C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80130D80: jal         0x8001EB64
    // 0x80130D84: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x80130D84: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x80130D88: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80130D8C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80130D90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80130D94: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80130D98: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80130D9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80130DA0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80130DA4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80130DA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80130DAC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80130DB0: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80130DB4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80130DB8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80130DBC: nop

    // 0x80130DC0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80130DC4: jal         0x8001EAD0
    // 0x80130DC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x80130DC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x80130DCC: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80130DD0: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80130DD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80130DD8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80130DDC: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80130DE0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80130DE4: div.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80130DE8: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80130DEC: nop

    // 0x80130DF0: bc1fl       L_80130E04
    if (!c1cs) {
        // 0x80130DF4: div.s       $f8, $f6, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
            goto L_80130E04;
    }
    goto skip_0;
    // 0x80130DF4: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    skip_0:
    // 0x80130DF8: b           L_80130E20
    // 0x80130DFC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80130E20;
    // 0x80130DFC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80130E00: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
L_80130E04:
    // 0x80130E04: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80130E08: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80130E0C: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x80130E10: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80130E14: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80130E18: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80130E1C: swc1        $f16, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f16.u32l;
L_80130E20:
    // 0x80130E20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80130E24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80130E28: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80130E2C: jr          $ra
    // 0x80130E30: nop

    return;
    // 0x80130E30: nop

;}
RECOMP_FUNC void M7_FUN_80130e34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130E34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80130E38: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80130E3C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80130E40: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80130E44: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80130E48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80130E4C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80130E50: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80130E54: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80130E58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80130E5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80130E60: jal         0x80130CBC
    // 0x80130E64: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80130CBC)(rdram, ctx);
        goto after_0;
    // 0x80130E64: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80130E68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80130E6C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80130E70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80130E74: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80130E78: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80130E7C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80130E80: bc1fl       L_80130E94
    if (!c1cs) {
        // 0x80130E84: lh          $t8, 0x8($a0)
        ctx->r24 = MEM_H(ctx->r4, 0X8);
            goto L_80130E94;
    }
    goto skip_0;
    // 0x80130E84: lh          $t8, 0x8($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8);
    skip_0:
    // 0x80130E88: b           L_80130F68
    // 0x80130E8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80130F68;
    // 0x80130E8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80130E90: lh          $t8, 0x8($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8);
L_80130E94:
    // 0x80130E94: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80130E98: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80130E9C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80130EA0: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80130EA4: lh          $t9, 0x10($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X10);
    // 0x80130EA8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80130EAC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80130EB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80130EB4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80130EB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80130EBC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80130EC0: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80130EC4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80130EC8: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80130ECC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80130ED0: mul.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x80130ED4: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x80130ED8: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x80130EDC: lh          $t0, 0xA($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XA);
    // 0x80130EE0: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80130EE4: lh          $t1, 0x12($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X12);
    // 0x80130EE8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80130EEC: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x80130EF0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80130EF4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80130EF8: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80130EFC: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80130F00: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80130F04: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80130F08: mul.d       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80130F0C: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x80130F10: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80130F14: jal         0x80001060
    // 0x80130F18: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_1;
    // 0x80130F18: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80130F1C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80130F20: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80130F24: beq         $v0, $zero, L_80130F60
    if (ctx->r2 == 0) {
        // 0x80130F28: lwc1        $f2, 0x20($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80130F60;
    }
    // 0x80130F28: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80130F2C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80130F30: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80130F34: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80130F38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80130F3C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x80130F40: mul.d       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80130F44: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80130F48: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80130F4C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80130F50: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80130F54: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80130F58: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x80130F5C: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_80130F60:
    // 0x80130F60: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80130F64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80130F68:
    // 0x80130F68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80130F6C: jr          $ra
    // 0x80130F70: nop

    return;
    // 0x80130F70: nop

;}
RECOMP_FUNC void M7_FUN_80130f74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80130F74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80130F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80130F7C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80130F80: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80130F84: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80130F88: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80130F8C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80130F90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80130F94: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80130F98: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80130F9C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80130FA0: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80130FA4: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x80130FA8: nop

    // 0x80130FAC: bc1tl       L_8013104C
    if (c1cs) {
        // 0x80130FB0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8013104C;
    }
    goto skip_0;
    // 0x80130FB0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x80130FB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80130FB8: nop

    // 0x80130FBC: c.eq.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl == ctx->f18.fl;
    // 0x80130FC0: nop

    // 0x80130FC4: bc1tl       L_8013104C
    if (c1cs) {
        // 0x80130FC8: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8013104C;
    }
    goto skip_1;
    // 0x80130FC8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
    // 0x80130FCC: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x80130FD0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80130FD4: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80130FD8: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80130FDC: nop

    // 0x80130FE0: bc1fl       L_80131004
    if (!c1cs) {
        // 0x80130FE4: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_80131004;
    }
    goto skip_2;
    // 0x80130FE4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_2:
    // 0x80130FE8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80130FEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80130FF0: jal         0x8002FC20
    // 0x80130FF4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80130FF4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80130FF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80130FFC: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80131000: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_80131004:
    // 0x80131004: jal         0x8002FC20
    // 0x80131008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x80131008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8013100C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131010: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131014: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80131018: div.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8013101C: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80131020: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80131024: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80131028: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8013102C: nop

    // 0x80131030: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80131034: nop

    // 0x80131038: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8013103C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80131040: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80131044: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x80131048: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8013104C:
    // 0x8013104C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80131054: c.eq.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl == ctx->f10.fl;
    // 0x80131058: nop

    // 0x8013105C: bc1f        L_8013106C
    if (!c1cs) {
        // 0x80131060: nop
    
            goto L_8013106C;
    }
    // 0x80131060: nop

    // 0x80131064: b           L_8013106C
    // 0x80131068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013106C;
    // 0x80131068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013106C:
    // 0x8013106C: jr          $ra
    // 0x80131070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80131070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80131074(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80131074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131074: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013107C: lwc1        $f0, 0x8($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80131080: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80131084: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80131088: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8013108C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80131090: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80131094: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80131098: jal         0x8002FC20
    // 0x8013109C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x8013109C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x801310A0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801310A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801310A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801310AC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801310B0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801310B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801310B8: bc1fl       L_801310CC
    if (!c1cs) {
        // 0x801310BC: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_801310CC;
    }
    goto skip_0;
    // 0x801310BC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x801310C0: b           L_801310CC
    // 0x801310C4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_801310CC;
    // 0x801310C4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x801310C8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_801310CC:
    // 0x801310CC: ldc1        $f10, -0x2950($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2950);
    // 0x801310D0: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x801310D4: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x801310D8: nop

    // 0x801310DC: bc1fl       L_8013113C
    if (!c1cs) {
        // 0x801310E0: lwc1        $f4, 0x0($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
            goto L_8013113C;
    }
    goto skip_1;
    // 0x801310E0: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x801310E4: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801310E8: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x801310EC: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801310F0: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x801310F4: nop

    // 0x801310F8: bc1fl       L_80131120
    if (!c1cs) {
        // 0x801310FC: lwc1        $f10, 0x8($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
            goto L_80131120;
    }
    goto skip_2;
    // 0x801310FC: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    skip_2:
    // 0x80131100: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80131104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131108: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8013110C: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x80131110: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80131114: b           L_801311E8
    // 0x80131118: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
        goto L_801311E8;
    // 0x80131118: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x8013111C: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
L_80131120:
    // 0x80131120: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x80131124: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80131128: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8013112C: swc1        $f18, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f18.u32l;
    // 0x80131130: b           L_801311E8
    // 0x80131134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801311E8;
    // 0x80131134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131138: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
L_8013113C:
    // 0x8013113C: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80131140: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80131144: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80131148: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8013114C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80131150: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80131154: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80131158: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8013115C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80131160: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80131164: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80131168: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8013116C: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80131170: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80131174: nop

    // 0x80131178: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8013117C: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80131180: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80131184: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80131188: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8013118C: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80131190: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80131194: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80131198: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8013119C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801311A0: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801311A4: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801311A8: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801311AC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801311B0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801311B4: nop

    // 0x801311B8: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801311BC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801311C0: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801311C4: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801311C8: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801311CC: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x801311D0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x801311D4: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x801311D8: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801311DC: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x801311E0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801311E4: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
L_801311E8:
    // 0x801311E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801311EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801311F0: jr          $ra
    // 0x801311F4: nop

    return;
    // 0x801311F4: nop

;}
RECOMP_FUNC void M7_FUN_801311f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801311F8: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x801311FC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80131200: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x80131204: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x80131208: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x8013120C: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x80131210: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80131214: sw          $a2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r6;
    // 0x80131218: sw          $a3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r7;
    // 0x8013121C: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80131220: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80131224: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80131228: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8013122C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80131230: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80131234: jal         0x8002FC20
    // 0x80131238: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80131238: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8013123C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80131240: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80131244: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80131248: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8013124C: c.le.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl <= ctx->f8.fl;
    // 0x80131250: nop

    // 0x80131254: bc1fl       L_80131270
    if (!c1cs) {
        // 0x80131258: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80131270;
    }
    goto skip_0;
    // 0x80131258: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x8013125C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131260: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131264: b           L_80131278
    // 0x80131268: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
        goto L_80131278;
    // 0x80131268: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x8013126C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80131270:
    // 0x80131270: nop

    // 0x80131274: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
L_80131278:
    // 0x80131278: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
    // 0x8013127C: addiu       $t9, $zero, 0x200
    ctx->r25 = ADD32(0, 0X200);
    // 0x80131280: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    // 0x80131284: sh          $t6, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r14;
    // 0x80131288: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x8013128C: sh          $t7, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r15;
    // 0x80131290: lhu         $t8, 0x4($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X4);
    // 0x80131294: sh          $t8, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r24;
    // 0x80131298: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x8013129C: jal         0x80130874
    // 0x801312A0: lhu         $a0, 0xD2($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0XD2);
    LOOKUP_FUNC(0x80130874)(rdram, ctx);
        goto after_1;
    // 0x801312A0: lhu         $a0, 0xD2($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0XD2);
    after_1:
    // 0x801312A4: swc1        $f0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f0.u32l;
    // 0x801312A8: lhu         $a0, 0xD6($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0XD6);
    // 0x801312AC: jal         0x80130874
    // 0x801312B0: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    LOOKUP_FUNC(0x80130874)(rdram, ctx);
        goto after_2;
    // 0x801312B0: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    after_2:
    // 0x801312B4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801312B8: lhu         $a0, 0xDA($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0XDA);
    // 0x801312BC: jal         0x80130874
    // 0x801312C0: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    LOOKUP_FUNC(0x80130874)(rdram, ctx);
        goto after_3;
    // 0x801312C0: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    after_3:
    // 0x801312C4: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x801312C8: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    // 0x801312CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801312D0: bc1fl       L_801312E4
    if (!c1cs) {
        // 0x801312D4: mov.s       $f2, $f24
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    ctx->f2.fl = ctx->f24.fl;
            goto L_801312E4;
    }
    goto skip_1;
    // 0x801312D4: mov.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    ctx->f2.fl = ctx->f24.fl;
    skip_1:
    // 0x801312D8: b           L_801312E4
    // 0x801312DC: neg.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = -ctx->f24.fl;
        goto L_801312E4;
    // 0x801312DC: neg.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = -ctx->f24.fl;
    // 0x801312E0: mov.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    ctx->f2.fl = ctx->f24.fl;
L_801312E4:
    // 0x801312E4: ldc1        $f8, -0x2948($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2948);
    // 0x801312E8: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x801312EC: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x801312F0: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801312F4: bc1f        L_80131458
    if (!c1cs) {
        // 0x801312F8: nop
    
            goto L_80131458;
    }
    // 0x801312F8: nop

    // 0x801312FC: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80131300: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80131304: lwc1        $f2, 0xB0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80131308: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    // 0x8013130C: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80131310: bc1fl       L_801313BC
    if (!c1cs) {
        // 0x80131314: neg.s       $f8, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
            goto L_801313BC;
    }
    goto skip_2;
    // 0x80131314: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    skip_2:
    // 0x80131318: lwc1        $f2, 0xB0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8013131C: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80131320: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80131324: nop

    // 0x80131328: mul.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8013132C: nop

    // 0x80131330: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80131334: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x80131338: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8013133C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80131340: jal         0x8002FC20
    // 0x80131344: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_4;
    // 0x80131344: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_4:
    // 0x80131348: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8013134C: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80131350: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80131354: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80131358: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8013135C: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80131360: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131364: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80131368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013136C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x80131370: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80131374: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80131378: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8013137C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80131380: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80131384: jal         0x801315A8
    // 0x80131388: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801315A8)(rdram, ctx);
        goto after_5;
    // 0x80131388: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8013138C: lhu         $t0, 0x76($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X76);
    // 0x80131390: lhu         $t1, 0x78($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X78);
    // 0x80131394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131398: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // 0x8013139C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x801313A0: lhu         $a3, 0x74($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X74);
    // 0x801313A4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801313A8: jal         0x80131B24
    // 0x801313AC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80131B24)(rdram, ctx);
        goto after_6;
    // 0x801313AC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_6:
    // 0x801313B0: b           L_8013158C
    // 0x801313B4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8013158C;
    // 0x801313B4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801313B8: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
L_801313BC:
    // 0x801313BC: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801313C0: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801313C4: neg.s       $f24, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = -ctx->f22.fl;
    // 0x801313C8: mul.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x801313CC: nop

    // 0x801313D0: mul.s       $f8, $f24, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x801313D4: swc1        $f4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f4.u32l;
    // 0x801313D8: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801313DC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801313E0: jal         0x8002FC20
    // 0x801313E4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_7;
    // 0x801313E4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_7:
    // 0x801313E8: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801313EC: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801313F0: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801313F4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801313F8: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801313FC: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80131400: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131404: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80131408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013140C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x80131410: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80131414: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80131418: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8013141C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80131420: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80131424: jal         0x8013173C
    // 0x80131428: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8013173C)(rdram, ctx);
        goto after_8;
    // 0x80131428: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x8013142C: lhu         $t2, 0x76($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X76);
    // 0x80131430: lhu         $t3, 0x78($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X78);
    // 0x80131434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131438: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // 0x8013143C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80131440: lhu         $a3, 0x74($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X74);
    // 0x80131444: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80131448: jal         0x80131B24
    // 0x8013144C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80131B24)(rdram, ctx);
        goto after_9;
    // 0x8013144C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_9:
    // 0x80131450: b           L_8013158C
    // 0x80131454: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8013158C;
    // 0x80131454: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80131458:
    // 0x80131458: mul.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8013145C: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80131460: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80131464: mul.s       $f8, $f22, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x80131468: nop

    // 0x8013146C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80131470: nop

    // 0x80131474: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80131478: sub.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8013147C: mul.s       $f18, $f22, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x80131480: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x80131484: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80131488: swc1        $f4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f4.u32l;
    // 0x8013148C: lwc1        $f14, 0x4($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80131490: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80131494: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80131498: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8013149C: mul.s       $f4, $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x801314A0: nop

    // 0x801314A4: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x801314A8: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801314AC: div.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f24.fl);
    // 0x801314B0: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801314B4: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x801314B8: mul.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801314BC: nop

    // 0x801314C0: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801314C4: add.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x801314C8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801314CC: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x801314D0: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x801314D4: nop

    // 0x801314D8: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801314DC: nop

    // 0x801314E0: mul.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x801314E4: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801314E8: div.s       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f24.fl);
    // 0x801314EC: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801314F0: nop

    // 0x801314F4: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x801314F8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801314FC: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80131500: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x80131504: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80131508: jal         0x8002FC20
    // 0x8013150C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_10;
    // 0x8013150C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_10:
    // 0x80131510: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80131514: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80131518: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8013151C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80131520: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80131524: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80131528: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8013152C: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80131530: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131538: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x8013153C: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    // 0x80131540: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80131544: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80131548: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8013154C: swc1        $f24, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f24.u32l;
    // 0x80131550: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80131554: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80131558: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8013155C: jal         0x801318D8
    // 0x80131560: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801318D8)(rdram, ctx);
        goto after_11;
    // 0x80131560: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x80131564: lhu         $t4, 0x76($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X76);
    // 0x80131568: lhu         $t5, 0x78($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X78);
    // 0x8013156C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131570: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // 0x80131574: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80131578: lhu         $a3, 0x74($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X74);
    // 0x8013157C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80131580: jal         0x80131B24
    // 0x80131584: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80131B24)(rdram, ctx);
        goto after_12;
    // 0x80131584: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_12:
    // 0x80131588: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8013158C:
    // 0x8013158C: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80131590: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80131594: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x80131598: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x8013159C: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x801315A0: jr          $ra
    // 0x801315A4: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x801315A4: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801315a8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801315a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801315A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801315AC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801315B0: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x801315B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801315B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801315BC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801315C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801315C4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801315C8: jal         0x801309EC
    // 0x801315CC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_0;
    // 0x801315CC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_0:
    // 0x801315D0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801315D4: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x801315D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801315DC: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x801315E0: nop

    // 0x801315E4: bc1fl       L_801315F8
    if (!c1cs) {
        // 0x801315E8: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_801315F8;
    }
    goto skip_0;
    // 0x801315E8: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    skip_0:
    // 0x801315EC: b           L_801315F8
    // 0x801315F0: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
        goto L_801315F8;
    // 0x801315F0: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
    // 0x801315F4: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_801315F8:
    // 0x801315F8: ldc1        $f6, -0x2940($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2940);
    // 0x801315FC: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80131600: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80131604: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80131608: nop

    // 0x8013160C: bc1fl       L_801316CC
    if (!c1cs) {
        // 0x80131610: lwc1        $f2, 0x44($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
            goto L_801316CC;
    }
    goto skip_1;
    // 0x80131610: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x80131614: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x80131618: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8013161C: bc1tl       L_80131648
    if (c1cs) {
        // 0x80131620: lwc1        $f2, 0x44($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
            goto L_80131648;
    }
    goto skip_2;
    // 0x80131620: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x80131624: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    // 0x80131628: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8013162C: bc1fl       L_80131684
    if (!c1cs) {
        // 0x80131630: lwc1        $f0, 0x3C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_80131684;
    }
    goto skip_3;
    // 0x80131630: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x80131634: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
    // 0x80131638: andi        $t7, $t6, 0x200
    ctx->r15 = ctx->r14 & 0X200;
    // 0x8013163C: beql        $t7, $zero, L_80131684
    if (ctx->r15 == 0) {
        // 0x80131640: lwc1        $f0, 0x3C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_80131684;
    }
    goto skip_4;
    // 0x80131640: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    skip_4:
    // 0x80131644: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
L_80131648:
    // 0x80131648: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8013164C: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80131650: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80131654: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80131658: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8013165C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80131660: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80131664: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80131668: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8013166C: mul.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80131670: jal         0x801309EC
    // 0x80131674: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_1;
    // 0x80131674: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    after_1:
    // 0x80131678: b           L_80131728
    // 0x8013167C: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
        goto L_80131728;
    // 0x8013167C: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80131680: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
L_80131684:
    // 0x80131684: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80131688: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8013168C: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80131690: addiu       $t8, $zero, 0x200
    ctx->r24 = ADD32(0, 0X200);
    // 0x80131694: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x80131698: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8013169C: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801316A0: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x801316A4: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x801316A8: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801316AC: mul.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x801316B0: sub.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x801316B4: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x801316B8: jal         0x801309EC
    // 0x801316BC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_2;
    // 0x801316BC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_2:
    // 0x801316C0: b           L_80131728
    // 0x801316C4: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
        goto L_80131728;
    // 0x801316C4: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x801316C8: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
L_801316CC:
    // 0x801316CC: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801316D0: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801316D4: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x801316D8: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801316DC: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801316E0: nop

    // 0x801316E4: mul.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x801316E8: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801316EC: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x801316F0: div.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x801316F4: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801316F8: nop

    // 0x801316FC: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80131700: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80131704: jal         0x801309EC
    // 0x80131708: div.s       $f14, $f10, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_3;
    // 0x80131708: div.s       $f14, $f10, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    after_3:
    // 0x8013170C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80131710: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80131714: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80131718: div.s       $f14, $f8, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8013171C: jal         0x801309EC
    // 0x80131720: div.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_4;
    // 0x80131720: div.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    after_4:
    // 0x80131724: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
L_80131728:
    // 0x80131728: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013172C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80131730: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131734: jr          $ra
    // 0x80131738: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131738: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013173c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013173c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013173C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131740: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80131744: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80131748: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013174C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131750: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80131754: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80131758: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8013175C: jal         0x801309EC
    // 0x80131760: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_0;
    // 0x80131760: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_0:
    // 0x80131764: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80131768: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8013176C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80131770: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80131774: nop

    // 0x80131778: bc1fl       L_8013178C
    if (!c1cs) {
        // 0x8013177C: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_8013178C;
    }
    goto skip_0;
    // 0x8013177C: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    skip_0:
    // 0x80131780: b           L_8013178C
    // 0x80131784: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
        goto L_8013178C;
    // 0x80131784: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
    // 0x80131788: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_8013178C:
    // 0x8013178C: ldc1        $f6, -0x2938($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2938);
    // 0x80131790: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80131794: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80131798: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8013179C: nop

    // 0x801317A0: bc1fl       L_8013185C
    if (!c1cs) {
        // 0x801317A4: lwc1        $f2, 0x44($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
            goto L_8013185C;
    }
    goto skip_1;
    // 0x801317A4: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x801317A8: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x801317AC: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801317B0: bc1tl       L_801317DC
    if (c1cs) {
        // 0x801317B4: lwc1        $f2, 0x44($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
            goto L_801317DC;
    }
    goto skip_2;
    // 0x801317B4: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x801317B8: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    // 0x801317BC: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801317C0: bc1fl       L_80131818
    if (!c1cs) {
        // 0x801317C4: lwc1        $f0, 0x3C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_80131818;
    }
    goto skip_3;
    // 0x801317C4: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x801317C8: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
    // 0x801317CC: andi        $t7, $t6, 0x200
    ctx->r15 = ctx->r14 & 0X200;
    // 0x801317D0: beql        $t7, $zero, L_80131818
    if (ctx->r15 == 0) {
        // 0x801317D4: lwc1        $f0, 0x3C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_80131818;
    }
    goto skip_4;
    // 0x801317D4: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    skip_4:
    // 0x801317D8: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
L_801317DC:
    // 0x801317DC: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801317E0: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801317E4: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x801317E8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x801317EC: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801317F0: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801317F4: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801317F8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801317FC: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80131800: mul.s       $f14, $f0, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80131804: jal         0x801309EC
    // 0x80131808: nop

    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_1;
    // 0x80131808: nop

    after_1:
    // 0x8013180C: b           L_801318C4
    // 0x80131810: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
        goto L_801318C4;
    // 0x80131810: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80131814: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
L_80131818:
    // 0x80131818: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8013181C: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80131820: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80131824: addiu       $t8, $zero, 0x200
    ctx->r24 = ADD32(0, 0X200);
    // 0x80131828: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x8013182C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80131830: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80131834: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80131838: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8013183C: sub.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80131840: mul.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80131844: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80131848: jal         0x801309EC
    // 0x8013184C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_2;
    // 0x8013184C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_2:
    // 0x80131850: b           L_801318C4
    // 0x80131854: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
        goto L_801318C4;
    // 0x80131854: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80131858: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
L_8013185C:
    // 0x8013185C: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80131860: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80131864: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80131868: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8013186C: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80131870: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80131874: nop

    // 0x80131878: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8013187C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80131880: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80131884: div.s       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80131888: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8013188C: nop

    // 0x80131890: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80131894: nop

    // 0x80131898: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8013189C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801318A0: jal         0x801309EC
    // 0x801318A4: div.s       $f14, $f6, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_3;
    // 0x801318A4: div.s       $f14, $f6, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    after_3:
    // 0x801318A8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x801318AC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801318B0: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801318B4: div.s       $f14, $f10, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x801318B8: jal         0x801309EC
    // 0x801318BC: div.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_4;
    // 0x801318BC: div.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    after_4:
    // 0x801318C0: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
L_801318C4:
    // 0x801318C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801318C8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801318CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801318D0: jr          $ra
    // 0x801318D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801318D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801318d8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801318d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801318D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801318DC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801318E0: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x801318E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801318E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801318EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801318F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801318F4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x801318F8: jal         0x801309EC
    // 0x801318FC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_0;
    // 0x801318FC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_0:
    // 0x80131900: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80131904: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x80131908: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8013190C: c.lt.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl < ctx->f8.fl;
    // 0x80131910: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80131914: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80131918: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8013191C: bc1f        L_8013192C
    if (!c1cs) {
        // 0x80131920: lwc1        $f2, 0x54($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
            goto L_8013192C;
    }
    // 0x80131920: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80131924: b           L_80131930
    // 0x80131928: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
        goto L_80131930;
    // 0x80131928: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
L_8013192C:
    // 0x8013192C: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_80131930:
    // 0x80131930: ldc1        $f10, -0x2930($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2930);
    // 0x80131934: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80131938: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8013193C: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80131940: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80131944: bc1f        L_80131A54
    if (!c1cs) {
        // 0x80131948: nop
    
            goto L_80131A54;
    }
    // 0x80131948: nop

    // 0x8013194C: mul.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80131950: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80131954: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80131958: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8013195C: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80131960: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80131964: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80131968: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8013196C: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80131970: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80131974: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80131978: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8013197C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80131980: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80131984: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80131988: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8013198C: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80131990: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80131994: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80131998: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8013199C: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801319A0: nop

    // 0x801319A4: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801319A8: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x801319AC: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801319B0: div.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801319B4: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801319B8: nop

    // 0x801319BC: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x801319C0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801319C4: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x801319C8: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x801319CC: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801319D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801319D4: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x801319D8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x801319DC: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801319E0: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801319E4: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801319E8: nop

    // 0x801319EC: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x801319F0: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801319F4: bc1t        L_80131A1C
    if (c1cs) {
        // 0x801319F8: swc1        $f6, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
            goto L_80131A1C;
    }
    // 0x801319F8: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x801319FC: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x80131A00: addiu       $t1, $zero, 0x200
    ctx->r9 = ADD32(0, 0X200);
    // 0x80131A04: bc1fl       L_80131A38
    if (!c1cs) {
        // 0x80131A08: sh          $t1, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r9;
            goto L_80131A38;
    }
    goto skip_0;
    // 0x80131A08: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    skip_0:
    // 0x80131A0C: lhu         $t9, 0x0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X0);
    // 0x80131A10: andi        $t0, $t9, 0x200
    ctx->r8 = ctx->r25 & 0X200;
    // 0x80131A14: beql        $t0, $zero, L_80131A38
    if (ctx->r8 == 0) {
        // 0x80131A18: sh          $t1, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r9;
            goto L_80131A38;
    }
    goto skip_1;
    // 0x80131A18: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    skip_1:
L_80131A1C:
    // 0x80131A1C: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80131A20: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80131A24: jal         0x801309EC
    // 0x80131A28: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_1;
    // 0x80131A28: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x80131A2C: b           L_80131B10
    // 0x80131A30: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
        goto L_80131B10;
    // 0x80131A30: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80131A34: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
L_80131A38:
    // 0x80131A38: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80131A3C: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80131A40: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80131A44: jal         0x801309EC
    // 0x80131A48: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_2;
    // 0x80131A48: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_2:
    // 0x80131A4C: b           L_80131B10
    // 0x80131A50: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
        goto L_80131B10;
    // 0x80131A50: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
L_80131A54:
    // 0x80131A54: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80131A58: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80131A5C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80131A60: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80131A64: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80131A68: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80131A6C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80131A70: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80131A74: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80131A78: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80131A7C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80131A80: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80131A84: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80131A88: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80131A8C: mul.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80131A90: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80131A94: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80131A98: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80131A9C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80131AA0: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80131AA4: nop

    // 0x80131AA8: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80131AAC: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80131AB0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80131AB4: mul.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80131AB8: nop

    // 0x80131ABC: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80131AC0: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80131AC4: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80131AC8: sub.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80131ACC: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80131AD0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80131AD4: mul.s       $f4, $f12, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80131AD8: div.s       $f12, $f16, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80131ADC: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80131AE0: nop

    // 0x80131AE4: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80131AE8: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80131AEC: jal         0x801309EC
    // 0x80131AF0: div.s       $f14, $f18, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_3;
    // 0x80131AF0: div.s       $f14, $f18, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    after_3:
    // 0x80131AF4: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80131AF8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80131AFC: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80131B00: div.s       $f14, $f8, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80131B04: jal         0x801309EC
    // 0x80131B08: div.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    LOOKUP_FUNC(0x801309EC)(rdram, ctx);
        goto after_4;
    // 0x80131B08: div.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    after_4:
    // 0x80131B0C: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
L_80131B10:
    // 0x80131B10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131B14: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80131B18: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131B1C: jr          $ra
    // 0x80131B20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80131B20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80131b24(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80131b24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80131B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B2C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80131B30: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80131B34: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80131B38: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80131B3C: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    // 0x80131B40: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x80131B44: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x80131B48: subu        $t0, $t3, $a3
    ctx->r8 = SUB32(ctx->r11, ctx->r7);
    // 0x80131B4C: andi        $t7, $t0, 0x200
    ctx->r15 = ctx->r8 & 0X200;
    // 0x80131B50: beq         $t7, $zero, L_80131B60
    if (ctx->r15 == 0) {
        // 0x80131B54: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80131B60;
    }
    // 0x80131B54: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80131B58: b           L_80131B64
    // 0x80131B5C: subu        $v0, $a3, $v1
    ctx->r2 = SUB32(ctx->r7, ctx->r3);
        goto L_80131B64;
    // 0x80131B5C: subu        $v0, $a3, $v1
    ctx->r2 = SUB32(ctx->r7, ctx->r3);
L_80131B60:
    // 0x80131B60: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80131B64:
    // 0x80131B64: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80131B68: lhu         $a3, 0x52($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X52);
    // 0x80131B6C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80131B70: lhu         $v1, 0x0($t8)
    ctx->r3 = MEM_HU(ctx->r24, 0X0);
    // 0x80131B74: andi        $t2, $t2, 0x3FF
    ctx->r10 = ctx->r10 & 0X3FF;
    // 0x80131B78: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80131B7C: subu        $a0, $v1, $a3
    ctx->r4 = SUB32(ctx->r3, ctx->r7);
    // 0x80131B80: andi        $t9, $a0, 0x200
    ctx->r25 = ctx->r4 & 0X200;
    // 0x80131B84: beq         $t9, $zero, L_80131B94
    if (ctx->r25 == 0) {
        // 0x80131B88: lhu         $t0, 0x56($sp)
        ctx->r8 = MEM_HU(ctx->r29, 0X56);
            goto L_80131B94;
    }
    // 0x80131B88: lhu         $t0, 0x56($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X56);
    // 0x80131B8C: b           L_80131B98
    // 0x80131B90: subu        $v0, $a3, $v1
    ctx->r2 = SUB32(ctx->r7, ctx->r3);
        goto L_80131B98;
    // 0x80131B90: subu        $v0, $a3, $v1
    ctx->r2 = SUB32(ctx->r7, ctx->r3);
L_80131B94:
    // 0x80131B94: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80131B98:
    // 0x80131B98: lhu         $v1, 0x0($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X0);
    // 0x80131B9C: andi        $t5, $v0, 0x3FF
    ctx->r13 = ctx->r2 & 0X3FF;
    // 0x80131BA0: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x80131BA4: subu        $a0, $v1, $t0
    ctx->r4 = SUB32(ctx->r3, ctx->r8);
    // 0x80131BA8: andi        $t7, $a0, 0x200
    ctx->r15 = ctx->r4 & 0X200;
    // 0x80131BAC: beq         $t7, $zero, L_80131BBC
    if (ctx->r15 == 0) {
        // 0x80131BB0: andi        $t2, $t2, 0xFFFF
        ctx->r10 = ctx->r10 & 0XFFFF;
            goto L_80131BBC;
    }
    // 0x80131BB0: andi        $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 & 0XFFFF;
    // 0x80131BB4: b           L_80131BC0
    // 0x80131BB8: subu        $v0, $t0, $v1
    ctx->r2 = SUB32(ctx->r8, ctx->r3);
        goto L_80131BC0;
    // 0x80131BB8: subu        $v0, $t0, $v1
    ctx->r2 = SUB32(ctx->r8, ctx->r3);
L_80131BBC:
    // 0x80131BBC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80131BC0:
    // 0x80131BC0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80131BC4: sh          $t3, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r11;
    // 0x80131BC8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80131BCC: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80131BD0: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x80131BD4: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80131BD8: sh          $t5, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r13;
    // 0x80131BDC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80131BE0: sh          $t2, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r10;
    // 0x80131BE4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80131BE8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80131BEC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80131BF0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80131BF4: addiu       $a1, $sp, 0x36
    ctx->r5 = ADD32(ctx->r29, 0X36);
    // 0x80131BF8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80131BFC: jal         0x80131CC4
    // 0x80131C00: sh          $t7, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80131CC4)(rdram, ctx);
        goto after_0;
    // 0x80131C00: sh          $t7, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r15;
    after_0:
    // 0x80131C04: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80131C08: lhu         $v1, 0x38($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X38);
    // 0x80131C0C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80131C10: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80131C14: subu        $a0, $v1, $t1
    ctx->r4 = SUB32(ctx->r3, ctx->r9);
    // 0x80131C18: andi        $t8, $a0, 0x200
    ctx->r24 = ctx->r4 & 0X200;
    // 0x80131C1C: beq         $t8, $zero, L_80131C2C
    if (ctx->r24 == 0) {
        // 0x80131C20: lhu         $t2, 0x3E($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X3E);
            goto L_80131C2C;
    }
    // 0x80131C20: lhu         $t2, 0x3E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X3E);
    // 0x80131C24: b           L_80131C30
    // 0x80131C28: subu        $v0, $t1, $v1
    ctx->r2 = SUB32(ctx->r9, ctx->r3);
        goto L_80131C30;
    // 0x80131C28: subu        $v0, $t1, $v1
    ctx->r2 = SUB32(ctx->r9, ctx->r3);
L_80131C2C:
    // 0x80131C2C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80131C30:
    // 0x80131C30: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    // 0x80131C34: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80131C38: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x80131C3C: subu        $a1, $a0, $a3
    ctx->r5 = SUB32(ctx->r4, ctx->r7);
    // 0x80131C40: andi        $t9, $a1, 0x200
    ctx->r25 = ctx->r5 & 0X200;
    // 0x80131C44: beq         $t9, $zero, L_80131C54
    if (ctx->r25 == 0) {
        // 0x80131C48: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80131C54;
    }
    // 0x80131C48: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80131C4C: b           L_80131C54
    // 0x80131C50: subu        $v0, $a3, $a0
    ctx->r2 = SUB32(ctx->r7, ctx->r4);
        goto L_80131C54;
    // 0x80131C50: subu        $v0, $a3, $a0
    ctx->r2 = SUB32(ctx->r7, ctx->r4);
L_80131C54:
    // 0x80131C54: lhu         $a0, 0x34($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X34);
    // 0x80131C58: andi        $t5, $v0, 0x3FF
    ctx->r13 = ctx->r2 & 0X3FF;
    // 0x80131C5C: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
    // 0x80131C60: subu        $a1, $a0, $t0
    ctx->r5 = SUB32(ctx->r4, ctx->r8);
    // 0x80131C64: andi        $t6, $a1, 0x200
    ctx->r14 = ctx->r5 & 0X200;
    // 0x80131C68: beq         $t6, $zero, L_80131C78
    if (ctx->r14 == 0) {
        // 0x80131C6C: andi        $v1, $v1, 0xFFFF
        ctx->r3 = ctx->r3 & 0XFFFF;
            goto L_80131C78;
    }
    // 0x80131C6C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80131C70: b           L_80131C7C
    // 0x80131C74: subu        $v0, $t0, $a0
    ctx->r2 = SUB32(ctx->r8, ctx->r4);
        goto L_80131C7C;
    // 0x80131C74: subu        $v0, $t0, $a0
    ctx->r2 = SUB32(ctx->r8, ctx->r4);
L_80131C78:
    // 0x80131C78: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80131C7C:
    // 0x80131C7C: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x80131C80: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80131C84: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80131C88: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80131C8C: bne         $at, $zero, L_80131CB4
    if (ctx->r1 != 0) {
        // 0x80131C90: lhu         $t9, 0x38($sp)
        ctx->r25 = MEM_HU(ctx->r29, 0X38);
            goto L_80131CB4;
    }
    // 0x80131C90: lhu         $t9, 0x38($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X38);
    // 0x80131C94: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80131C98: sh          $t9, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r25;
    // 0x80131C9C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80131CA0: lhu         $t5, 0x36($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X36);
    // 0x80131CA4: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x80131CA8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80131CAC: lhu         $t7, 0x34($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X34);
    // 0x80131CB0: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_80131CB4:
    // 0x80131CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131CB8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80131CBC: jr          $ra
    // 0x80131CC0: nop

    return;
    // 0x80131CC0: nop

;}
RECOMP_FUNC void M7_FUN_80131cc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CC4: lhu         $t6, 0x0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X0);
    // 0x80131CC8: addiu       $t7, $zero, 0x200
    ctx->r15 = ADD32(0, 0X200);
    // 0x80131CCC: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80131CD0: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x80131CD4: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x80131CD8: lhu         $t0, 0x0($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X0);
    // 0x80131CDC: addiu       $t1, $t0, 0x200
    ctx->r9 = ADD32(ctx->r8, 0X200);
    // 0x80131CE0: andi        $t2, $t1, 0x3FF
    ctx->r10 = ctx->r9 & 0X3FF;
    // 0x80131CE4: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // 0x80131CE8: lhu         $t3, 0x0($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X0);
    // 0x80131CEC: addiu       $t4, $t3, 0x200
    ctx->r12 = ADD32(ctx->r11, 0X200);
    // 0x80131CF0: andi        $t5, $t4, 0x3FF
    ctx->r13 = ctx->r12 & 0X3FF;
    // 0x80131CF4: jr          $ra
    // 0x80131CF8: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    return;
    // 0x80131CF8: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80131cfc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80131cfc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CFC: nop

    // 0x80131D00: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80131D04: lhu         $t6, -0x43E0($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X43E0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80131d08(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80131d08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131D0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131D10: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x80131D14: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80131D18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80131D1C: beq         $t8, $zero, L_80131D44
    if (ctx->r24 == 0) {
        // 0x80131D20: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80131D44;
    }
    // 0x80131D20: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80131D24: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80131D28: addiu       $a3, $a3, -0x2920
    ctx->r7 = ADD32(ctx->r7, -0X2920);
    // 0x80131D2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D30: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80131D34: jal         0x8001B204
    // 0x80131D38: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x80131D38: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_0:
    // 0x80131D3C: b           L_80131D5C
    // 0x80131D40: nop

        goto L_80131D5C;
    // 0x80131D40: nop

L_80131D44:
    // 0x80131D44: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80131D48: addiu       $a3, $a3, -0x2918
    ctx->r7 = ADD32(ctx->r7, -0X2918);
    // 0x80131D4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D50: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80131D54: jal         0x8001B204
    // 0x80131D58: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x80131D58: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_1:
L_80131D5C:
    // 0x80131D5C: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80131D60: lhu         $t9, -0x6B88($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X6B88);
    // 0x80131D64: addiu       $t1, $zero, 0x73
    ctx->r9 = ADD32(0, 0X73);
    // 0x80131D68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80131D6C: andi        $t0, $t9, 0xF000
    ctx->r8 = ctx->r25 & 0XF000;
    // 0x80131D70: beq         $t0, $zero, L_80131D90
    if (ctx->r8 == 0) {
        // 0x80131D74: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80131D90;
    }
    // 0x80131D74: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80131D78: sh          $t1, -0x440C($at)
    MEM_H(-0X440C, ctx->r1) = ctx->r9;
    // 0x80131D7C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x80131D80: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131D84: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80131D88: jal         0x8012FE50
    // 0x80131D8C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_2;
    // 0x80131D8C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
L_80131D90:
    // 0x80131D90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80131D94: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80131D98: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80131D9C: slti        $at, $v0, 0x1771
    ctx->r1 = SIGNED(ctx->r2) < 0X1771 ? 1 : 0;
    // 0x80131DA0: bnel        $at, $zero, L_80131DBC
    if (ctx->r1 != 0) {
        // 0x80131DA4: addiu       $t3, $v0, 0x1
        ctx->r11 = ADD32(ctx->r2, 0X1);
            goto L_80131DBC;
    }
    goto skip_0;
    // 0x80131DA4: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80131DA8: jal         0x800057DC
    // 0x80131DAC: addiu       $a1, $a1, 0x2FC0
    ctx->r5 = ADD32(ctx->r5, 0X2FC0);
    LOOKUP_FUNC(0x800057DC)(rdram, ctx);
        goto after_3;
    // 0x80131DAC: addiu       $a1, $a1, 0x2FC0
    ctx->r5 = ADD32(ctx->r5, 0X2FC0);
    after_3:
    // 0x80131DB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80131DB4: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80131DB8: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
L_80131DBC:
    // 0x80131DBC: sh          $t3, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r11;
    // 0x80131DC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131DC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80131DC8: jr          $ra
    // 0x80131DCC: nop

    return;
    // 0x80131DCC: nop

;}
RECOMP_FUNC void M7_FUN_80131dd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131DD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131DD4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80131DD8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80131DDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80131DE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131DE4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80131DE8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80131DEC: sh          $t6, 0x168($v0)
    MEM_H(0X168, ctx->r2) = ctx->r14;
    // 0x80131DF0: lh          $t7, 0x98($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X98);
    // 0x80131DF4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80131DF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80131DFC: bne         $t7, $at, L_80131E2C
    if (ctx->r15 != ctx->r1) {
        // 0x80131E00: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80131E2C;
    }
    // 0x80131E00: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80131E04: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80131E08: addiu       $a1, $a1, -0x736C
    ctx->r5 = ADD32(ctx->r5, -0X736C);
    // 0x80131E0C: jal         0x80005E44
    // 0x80131E10: lw          $a0, 0x54($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X54);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80131E10: lw          $a0, 0x54($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X54);
    after_0:
    // 0x80131E14: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131E18: addiu       $a1, $a1, 0x234C
    ctx->r5 = ADD32(ctx->r5, 0X234C);
    // 0x80131E1C: jal         0x800058DC
    // 0x80131E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80131E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80131E24: b           L_8013221C
    // 0x80131E28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013221C;
    // 0x80131E28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80131E2C:
    // 0x80131E2C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80131E30: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x80131E34: jal         0x80005E44
    // 0x80131E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x80131E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80131E3C: beql        $v0, $zero, L_8013221C
    if (ctx->r2 == 0) {
        // 0x80131E40: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013221C;
    }
    goto skip_0;
    // 0x80131E40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80131E44: jal         0x80006214
    // 0x80131E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x80131E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80131E4C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80131E50: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80131E54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80131E58: sh          $v1, 0x28($t8)
    MEM_H(0X28, ctx->r24) = ctx->r3;
    // 0x80131E5C: sb          $v1, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = ctx->r3;
    // 0x80131E60: lh          $t9, 0x92($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X92);
    // 0x80131E64: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80131E68: addiu       $t1, $zero, 0x90
    ctx->r9 = ADD32(0, 0X90);
    // 0x80131E6C: beq         $t9, $zero, L_80131E80
    if (ctx->r25 == 0) {
        // 0x80131E70: addiu       $t2, $zero, -0x4
        ctx->r10 = ADD32(0, -0X4);
            goto L_80131E80;
    }
    // 0x80131E70: addiu       $t2, $zero, -0x4
    ctx->r10 = ADD32(0, -0X4);
    // 0x80131E74: sh          $zero, 0x94($s0)
    MEM_H(0X94, ctx->r16) = 0;
    // 0x80131E78: b           L_80131E88
    // 0x80131E7C: sh          $t0, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r8;
        goto L_80131E88;
    // 0x80131E7C: sh          $t0, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r8;
L_80131E80:
    // 0x80131E80: sh          $t1, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r9;
    // 0x80131E84: sh          $t2, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r10;
L_80131E88:
    // 0x80131E88: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x80131E8C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80131E90: lwc1        $f0, -0x28AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X28AC);
    // 0x80131E94: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x80131E98: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
    // 0x80131E9C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80131EA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131EA4: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80131EA8: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x80131EAC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80131EB0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80131EB4: swc1        $f0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f0.u32l;
    // 0x80131EB8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80131EBC: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80131EC0: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
    // 0x80131EC4: lh          $v0, 0x98($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X98);
    // 0x80131EC8: beql        $v0, $zero, L_80131EF8
    if (ctx->r2 == 0) {
        // 0x80131ECC: lw          $t1, 0x0($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X0);
            goto L_80131EF8;
    }
    goto skip_1;
    // 0x80131ECC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80131ED0: beq         $v0, $at, L_80131FD8
    if (ctx->r2 == ctx->r1) {
        // 0x80131ED4: lui         $t6, 0x8000
        ctx->r14 = S32(0X8000 << 16);
            goto L_80131FD8;
    }
    // 0x80131ED4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80131ED8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80131EDC: beq         $v0, $at, L_80132084
    if (ctx->r2 == ctx->r1) {
        // 0x80131EE0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80132084;
    }
    // 0x80131EE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80131EE4: beq         $v0, $at, L_8013216C
    if (ctx->r2 == ctx->r1) {
        // 0x80131EE8: lui         $t8, 0x8000
        ctx->r24 = S32(0X8000 << 16);
            goto L_8013216C;
    }
    // 0x80131EE8: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80131EEC: b           L_8013221C
    // 0x80131EF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013221C;
    // 0x80131EF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131EF4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
L_80131EF8:
    // 0x80131EF8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80131EFC: lwc1        $f0, -0x28A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X28A8);
    // 0x80131F00: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80131F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131F0C: swc1        $f0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f0.u32l;
    // 0x80131F10: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80131F14: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80131F18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80131F1C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80131F20: swc1        $f0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f0.u32l;
    // 0x80131F24: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80131F28: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80131F2C: jal         0x8012C89C
    // 0x80131F30: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x80131F30: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    after_4:
    // 0x80131F34: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80131F38: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80131F3C: addiu       $t7, $t7, -0x4D60
    ctx->r15 = ADD32(ctx->r15, -0X4D60);
    // 0x80131F40: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80131F44: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131F48: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80131F4C: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x80131F50: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80131F54: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80131F58: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80131F5C: sw          $t1, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r9;
    // 0x80131F60: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80131F64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131F68: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80131F6C: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80131F70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131F74: addiu       $t3, $zero, 0x1000
    ctx->r11 = ADD32(0, 0X1000);
    // 0x80131F78: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x80131F7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131F80: addiu       $a1, $a1, 0x222C
    ctx->r5 = ADD32(ctx->r5, 0X222C);
    // 0x80131F84: ori         $t5, $t4, 0x1000
    ctx->r13 = ctx->r12 | 0X1000;
    // 0x80131F88: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x80131F8C: lh          $t6, 0x94($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X94);
    // 0x80131F90: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80131F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F98: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80131F9C: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80131FA0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80131FA4: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x80131FA8: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80131FAC: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x80131FB0: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x80131FB4: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80131FB8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80131FBC: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    // 0x80131FC0: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x80131FC4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80131FC8: jal         0x800058DC
    // 0x80131FCC: sh          $t3, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80131FCC: sh          $t3, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r11;
    after_5:
    // 0x80131FD0: b           L_8013221C
    // 0x80131FD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013221C;
    // 0x80131FD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80131FD8:
    // 0x80131FD8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80131FDC: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80131FE0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80131FE4: sw          $t6, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r14;
    // 0x80131FE8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80131FEC: addiu       $t9, $t9, -0x51A8
    ctx->r25 = ADD32(ctx->r25, -0X51A8);
    // 0x80131FF0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131FF4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80131FF8: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80131FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132000: sw          $t8, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r24;
    // 0x80132004: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80132008: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013200C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80132010: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x80132014: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80132018: jal         0x8012C89C
    // 0x8013201C: sw          $zero, 0x24($t4)
    MEM_W(0X24, ctx->r12) = 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_6;
    // 0x8013201C: sw          $zero, 0x24($t4)
    MEM_W(0X24, ctx->r12) = 0;
    after_6:
    // 0x80132020: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132024: addiu       $a1, $a1, 0x222C
    ctx->r5 = ADD32(ctx->r5, 0X222C);
    // 0x80132028: jal         0x800058DC
    // 0x8013202C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x8013202C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80132030: lh          $t3, 0x94($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X94);
    // 0x80132034: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x80132038: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8013203C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80132040: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80132044: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132048: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013204C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80132050: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132054: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x80132058: swc1        $f18, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f18.u32l;
    // 0x8013205C: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80132060: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80132064: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x80132068: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x8013206C: lw          $t8, 0x30($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X30);
    // 0x80132070: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x80132074: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80132078: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x8013207C: b           L_80132218
    // 0x80132080: sh          $t1, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r9;
        goto L_80132218;
    // 0x80132080: sh          $t1, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r9;
L_80132084:
    // 0x80132084: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80132088: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013208C: lwc1        $f0, -0x28A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X28A4);
    // 0x80132090: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80132094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013209C: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x801320A0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801320A4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x801320A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801320AC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801320B0: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x801320B4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801320B8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801320BC: jal         0x8012C89C
    // 0x801320C0: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_8;
    // 0x801320C0: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
    after_8:
    // 0x801320C4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801320C8: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x801320CC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x801320D0: sw          $t8, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r24;
    // 0x801320D4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801320D8: addiu       $t1, $t1, -0x4D60
    ctx->r9 = ADD32(ctx->r9, -0X4D60);
    // 0x801320DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801320E0: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801320E4: or          $t4, $t1, $at
    ctx->r12 = ctx->r9 | ctx->r1;
    // 0x801320E8: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x801320EC: sw          $t4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r12;
    // 0x801320F0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801320F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801320F8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801320FC: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80132100: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80132104: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132108: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x8013210C: addiu       $a1, $a1, 0x222C
    ctx->r5 = ADD32(ctx->r5, 0X222C);
    // 0x80132110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132114: ori         $t9, $t7, 0x1000
    ctx->r25 = ctx->r15 | 0X1000;
    // 0x80132118: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x8013211C: lh          $t0, 0x94($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X94);
    // 0x80132120: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80132124: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x80132128: negu        $t8, $t0
    ctx->r24 = SUB32(0, ctx->r8);
    // 0x8013212C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80132130: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80132134: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132138: swc1        $f10, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f10.u32l;
    // 0x8013213C: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x80132140: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80132144: swc1        $f16, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f16.u32l;
    // 0x80132148: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8013214C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80132150: swc1        $f18, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f18.u32l;
    // 0x80132154: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80132158: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8013215C: jal         0x800058DC
    // 0x80132160: sh          $t7, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x80132160: sh          $t7, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r15;
    after_9:
    // 0x80132164: b           L_8013221C
    // 0x80132168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013221C;
    // 0x80132168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013216C:
    // 0x8013216C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80132170: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80132174: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80132178: sw          $t8, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r24;
    // 0x8013217C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80132180: addiu       $t1, $t1, -0x51A8
    ctx->r9 = ADD32(ctx->r9, -0X51A8);
    // 0x80132184: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80132188: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8013218C: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x80132190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132194: sw          $t3, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r11;
    // 0x80132198: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8013219C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801321A0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x801321A4: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x801321A8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x801321AC: jal         0x8012C89C
    // 0x801321B0: sw          $zero, 0x24($t9)
    MEM_W(0X24, ctx->r25) = 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_10;
    // 0x801321B0: sw          $zero, 0x24($t9)
    MEM_W(0X24, ctx->r25) = 0;
    after_10:
    // 0x801321B4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801321B8: addiu       $a1, $a1, 0x222C
    ctx->r5 = ADD32(ctx->r5, 0X222C);
    // 0x801321BC: jal         0x800058DC
    // 0x801321C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x801321C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x801321C4: lh          $t7, 0x94($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X94);
    // 0x801321C8: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801321CC: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x801321D0: negu        $t0, $t7
    ctx->r8 = SUB32(0, ctx->r15);
    // 0x801321D4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801321D8: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x801321DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801321E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801321E4: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x801321E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801321EC: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x801321F0: swc1        $f6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f6.u32l;
    // 0x801321F4: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801321F8: lw          $t4, 0x30($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X30);
    // 0x801321FC: swc1        $f8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f8.u32l;
    // 0x80132200: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x80132204: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80132208: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
    // 0x8013220C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80132210: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x80132214: sh          $t6, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r14;
L_80132218:
    // 0x80132218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013221C:
    // 0x8013221C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80132220: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80132224: jr          $ra
    // 0x80132228: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80132228: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013222c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013222c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013222C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132230: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80132234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132238: addiu       $t6, $zero, 0x23
    ctx->r14 = ADD32(0, 0X23);
    // 0x8013223C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132240: sh          $t6, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r14;
    // 0x80132244: jal         0x800058DC
    // 0x80132248: addiu       $a1, $a1, 0x225C
    ctx->r5 = ADD32(ctx->r5, 0X225C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80132248: addiu       $a1, $a1, 0x225C
    ctx->r5 = ADD32(ctx->r5, 0X225C);
    after_0:
    // 0x8013224C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132254: jr          $ra
    // 0x80132258: nop

    return;
    // 0x80132258: nop

;}
RECOMP_FUNC void M7_FUN_8013225c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013225C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132264: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80132268: lh          $v0, 0x98($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X98);
    // 0x8013226C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132270: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132274: beql        $v0, $zero, L_801322A0
    if (ctx->r2 == 0) {
        // 0x80132278: lh          $t7, 0x96($a0)
        ctx->r15 = MEM_H(ctx->r4, 0X96);
            goto L_801322A0;
    }
    goto skip_0;
    // 0x80132278: lh          $t7, 0x96($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X96);
    skip_0:
    // 0x8013227C: beq         $v0, $at, L_8013229C
    if (ctx->r2 == ctx->r1) {
        // 0x80132280: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8013229C;
    }
    // 0x80132280: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132284: beq         $v0, $at, L_801322C0
    if (ctx->r2 == ctx->r1) {
        // 0x80132288: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801322C0;
    }
    // 0x80132288: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8013228C: beql        $v0, $at, L_801322C4
    if (ctx->r2 == ctx->r1) {
        // 0x80132290: lh          $t9, 0x96($a0)
        ctx->r25 = MEM_H(ctx->r4, 0X96);
            goto L_801322C4;
    }
    goto skip_1;
    // 0x80132290: lh          $t9, 0x96($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X96);
    skip_1:
    // 0x80132294: b           L_801322E4
    // 0x80132298: lh          $v1, 0x90($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X90);
        goto L_801322E4;
    // 0x80132298: lh          $v1, 0x90($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X90);
L_8013229C:
    // 0x8013229C: lh          $t7, 0x96($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X96);
L_801322A0:
    // 0x801322A0: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801322A4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801322A8: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x801322AC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801322B0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801322B4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801322B8: b           L_801322E0
    // 0x801322BC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
        goto L_801322E0;
    // 0x801322BC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
L_801322C0:
    // 0x801322C0: lh          $t9, 0x96($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X96);
L_801322C4:
    // 0x801322C4: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x801322C8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801322CC: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801322D0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801322D4: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801322D8: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x801322DC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_801322E0:
    // 0x801322E0: lh          $v1, 0x90($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X90);
L_801322E4:
    // 0x801322E4: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x801322E8: bne         $v1, $zero, L_801322F8
    if (ctx->r3 != 0) {
        // 0x801322EC: sh          $t0, 0x90($a0)
        MEM_H(0X90, ctx->r4) = ctx->r8;
            goto L_801322F8;
    }
    // 0x801322EC: sh          $t0, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r8;
    // 0x801322F0: jal         0x800058DC
    // 0x801322F4: addiu       $a1, $a1, 0x2308
    ctx->r5 = ADD32(ctx->r5, 0X2308);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801322F4: addiu       $a1, $a1, 0x2308
    ctx->r5 = ADD32(ctx->r5, 0X2308);
    after_0:
L_801322F8:
    // 0x801322F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801322FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132300: jr          $ra
    // 0x80132304: nop

    return;
    // 0x80132304: nop

;}
RECOMP_FUNC void M7_FUN_80132308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013230C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80132310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132314: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80132318: sb          $zero, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = 0;
    // 0x8013231C: lh          $t6, 0x92($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X92);
    // 0x80132320: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80132324: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80132328: bne         $t6, $zero, L_80132334
    if (ctx->r14 != 0) {
        // 0x8013232C: nop
    
            goto L_80132334;
    }
    // 0x8013232C: nop

    // 0x80132330: sh          $t7, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = ctx->r15;
L_80132334:
    // 0x80132334: jal         0x80005700
    // 0x80132338: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80132338: nop

    after_0:
    // 0x8013233C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132344: jr          $ra
    // 0x80132348: nop

    return;
    // 0x80132348: nop

;}
RECOMP_FUNC void M7_FUN_8013234c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013234C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80132350: jr          $ra
    // 0x80132354: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80132354: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80132358(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80132358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132358: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x8013235C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132360: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80132364: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80132368: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8013236C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80132370: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80132374: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80132378: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8013237C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80132380: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80132384: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x80132388: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013238C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80132390: bne         $t6, $at, L_801323B8
    if (ctx->r14 != ctx->r1) {
        // 0x80132394: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_801323B8;
    }
    // 0x80132394: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80132398: jal         0x80116E80
    // 0x8013239C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_0;
    // 0x8013239C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x801323A0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801323A4: addiu       $a1, $a1, 0x234C
    ctx->r5 = ADD32(ctx->r5, 0X234C);
    // 0x801323A8: jal         0x800058DC
    // 0x801323AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801323AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801323B0: b           L_80132CFC
    // 0x801323B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80132CFC;
    // 0x801323B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801323B8:
    // 0x801323B8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x801323BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801323C0: sb          $s2, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = ctx->r18;
    // 0x801323C4: lbu         $v0, 0x90($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X90);
    // 0x801323C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801323CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801323D0: beq         $v0, $zero, L_801323E8
    if (ctx->r2 == 0) {
        // 0x801323D4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_801323E8;
    }
    // 0x801323D4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801323D8: beq         $v0, $at, L_80132CEC
    if (ctx->r2 == ctx->r1) {
        // 0x801323DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80132CEC;
    }
    // 0x801323DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801323E0: b           L_80132CFC
    // 0x801323E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80132CFC;
    // 0x801323E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801323E8:
    // 0x801323E8: jal         0x80005E44
    // 0x801323EC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x801323EC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_2:
    // 0x801323F0: beql        $v0, $zero, L_80132CFC
    if (ctx->r2 == 0) {
        // 0x801323F4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80132CFC;
    }
    goto skip_0;
    // 0x801323F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x801323F8: jal         0x80006214
    // 0x801323FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801323FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80132400: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80132404: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80132408: sh          $t7, 0x28($t8)
    MEM_H(0X28, ctx->r24) = ctx->r15;
    // 0x8013240C: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80132410: ori         $t6, $t9, 0x20
    ctx->r14 = ctx->r25 | 0X20;
    // 0x80132414: jal         0x80001060
    // 0x80132418: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_4;
    // 0x80132418: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    after_4:
    // 0x8013241C: beq         $v0, $zero, L_80132434
    if (ctx->r2 == 0) {
        // 0x80132420: nop
    
            goto L_80132434;
    }
    // 0x80132420: nop

    // 0x80132424: jal         0x8001F430
    // 0x80132428: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_5;
    // 0x80132428: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_5:
    // 0x8013242C: b           L_80132440
    // 0x80132430: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80132440;
    // 0x80132430: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80132434:
    // 0x80132434: jal         0x8001F430
    // 0x80132438: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_6;
    // 0x80132438: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    after_6:
    // 0x8013243C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80132440:
    // 0x80132440: sw          $v1, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r3;
    // 0x80132444: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80132448: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013244C: addiu       $a1, $a1, 0x2D74
    ctx->r5 = ADD32(ctx->r5, 0X2D74);
    // 0x80132450: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80132454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132458: sw          $v1, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r3;
    // 0x8013245C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80132460: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80132464: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80132468: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x8013246C: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x80132470: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80132474: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80132478: ori         $t6, $t6, 0x600
    ctx->r14 = ctx->r14 | 0X600;
    // 0x8013247C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80132480: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x80132484: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80132488: sw          $t6, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r14;
    // 0x8013248C: jal         0x800058DC
    // 0x80132490: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x80132490: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    after_7:
    // 0x80132494: lw          $v0, 0xF4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XF4);
    // 0x80132498: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8013249C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801324A0: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801324A4: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x801324A8: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
    // 0x801324AC: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801324B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801324B4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801324B8: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x801324BC: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x801324C0: lui         $s1, 0xE300
    ctx->r17 = S32(0XE300 << 16);
    // 0x801324C4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801324C8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x801324CC: ori         $s1, $s1, 0xC00
    ctx->r17 = ctx->r17 | 0XC00;
    // 0x801324D0: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x801324D4: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x801324D8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x801324DC: sw          $s1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r17;
    // 0x801324E0: lui         $t7, 0xD9F1
    ctx->r15 = S32(0XD9F1 << 16);
    // 0x801324E4: ori         $t7, $t7, 0xFBFF
    ctx->r15 = ctx->r15 | 0XFBFF;
    // 0x801324E8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801324EC: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801324F0: addiu       $v1, $a2, 0x8
    ctx->r3 = ADD32(ctx->r6, 0X8);
    // 0x801324F4: jal         0x80001060
    // 0x801324F8: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_8;
    // 0x801324F8: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    after_8:
    // 0x801324FC: beq         $v0, $zero, L_80132524
    if (ctx->r2 == 0) {
        // 0x80132500: lw          $v1, 0xF4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XF4);
            goto L_80132524;
    }
    // 0x80132500: lw          $v1, 0xF4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XF4);
    // 0x80132504: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80132508: lui         $t9, 0x9F
    ctx->r25 = S32(0X9F << 16);
    // 0x8013250C: ori         $t9, $t9, 0xC77C
    ctx->r25 = ctx->r25 | 0XC77C;
    // 0x80132510: lui         $t8, 0xED00
    ctx->r24 = S32(0XED00 << 16);
    // 0x80132514: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132518: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8013251C: b           L_80132540
    // 0x80132520: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80132540;
    // 0x80132520: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80132524:
    // 0x80132524: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80132528: lui         $t7, 0x4F
    ctx->r15 = S32(0X4F << 16);
    // 0x8013252C: ori         $t7, $t7, 0xC3BC
    ctx->r15 = ctx->r15 | 0XC3BC;
    // 0x80132530: lui         $t6, 0xED00
    ctx->r14 = S32(0XED00 << 16);
    // 0x80132534: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80132538: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8013253C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80132540:
    // 0x80132540: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80132544: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80132548: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x8013254C: ori         $t9, $t9, 0x4340
    ctx->r25 = ctx->r25 | 0X4340;
    // 0x80132550: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80132554: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132558: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8013255C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132560: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x80132564: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80132568: lui         $t7, 0xFFFC
    ctx->r15 = S32(0XFFFC << 16);
    // 0x8013256C: ori         $t7, $t7, 0xF67B
    ctx->r15 = ctx->r15 | 0XF67B;
    // 0x80132570: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80132574: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x80132578: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8013257C: lui         $t8, 0xD700
    ctx->r24 = S32(0XD700 << 16);
    // 0x80132580: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x80132584: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80132588: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8013258C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80132590: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x80132594: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80132598: ori         $t6, $t6, 0xF00
    ctx->r14 = ctx->r14 | 0XF00;
    // 0x8013259C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801325A0: addiu       $a3, $v1, 0x8
    ctx->r7 = ADD32(ctx->r3, 0X8);
    // 0x801325A4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801325A8: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x801325AC: ori         $t7, $t7, 0x1E01
    ctx->r15 = ctx->r15 | 0X1E01;
    // 0x801325B0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x801325B4: addiu       $v0, $a3, 0x8
    ctx->r2 = ADD32(ctx->r7, 0X8);
    // 0x801325B8: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x801325BC: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x801325C0: lui         $t8, 0xF900
    ctx->r24 = S32(0XF900 << 16);
    // 0x801325C4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801325C8: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x801325CC: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801325D0: ori         $t9, $t9, 0x1201
    ctx->r25 = ctx->r25 | 0X1201;
    // 0x801325D4: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x801325D8: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x801325DC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x801325E0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801325E4: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x801325E8: ori         $t7, $t7, 0x1001
    ctx->r15 = ctx->r15 | 0X1001;
    // 0x801325EC: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x801325F0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x801325F4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x801325F8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801325FC: sw          $s1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r17;
    // 0x80132600: addiu       $v1, $a2, 0x8
    ctx->r3 = ADD32(ctx->r6, 0X8);
    // 0x80132604: jal         0x80001060
    // 0x80132608: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_9;
    // 0x80132608: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    after_9:
    // 0x8013260C: beq         $v0, $zero, L_80132974
    if (ctx->r2 == 0) {
        // 0x80132610: lw          $v1, 0xF4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XF4);
            goto L_80132974;
    }
    // 0x80132610: lw          $v1, 0xF4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XF4);
    // 0x80132614: lui         $s1, 0x8040
    ctx->r17 = S32(0X8040 << 16);
    // 0x80132618: addiu       $s1, $s1, 0x0
    ctx->r17 = ADD32(ctx->r17, 0X0);
    // 0x8013261C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80132620: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x80132624: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x80132628: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8013262C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80132630: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132634: lui         $s2, 0xFD10
    ctx->r18 = S32(0XFD10 << 16);
    // 0x80132638: lui         $t9, 0x709
    ctx->r25 = S32(0X709 << 16);
    // 0x8013263C: ori         $t9, $t9, 0x82A0
    ctx->r25 = ctx->r25 | 0X82A0;
    // 0x80132640: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80132644: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132648: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8013264C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80132650: lui         $s3, 0xF510
    ctx->r19 = S32(0XF510 << 16);
    // 0x80132654: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x80132658: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8013265C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80132660: lui         $s4, 0xE600
    ctx->r20 = S32(0XE600 << 16);
    // 0x80132664: lui         $t6, 0x777
    ctx->r14 = S32(0X777 << 16);
    // 0x80132668: ori         $t6, $t6, 0xF00D
    ctx->r14 = ctx->r14 | 0XF00D;
    // 0x8013266C: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x80132670: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132674: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80132678: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8013267C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80132680: lui         $s5, 0xF300
    ctx->r21 = S32(0XF300 << 16);
    // 0x80132684: sw          $s5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r21;
    // 0x80132688: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8013268C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80132690: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80132694: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80132698: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8013269C: lui         $t9, 0x9
    ctx->r25 = S32(0X9 << 16);
    // 0x801326A0: lui         $t8, 0xF511
    ctx->r24 = S32(0XF511 << 16);
    // 0x801326A4: ori         $t8, $t8, 0x4000
    ctx->r24 = ctx->r24 | 0X4000;
    // 0x801326A8: ori         $t9, $t9, 0x82A0
    ctx->r25 = ctx->r25 | 0X82A0;
    // 0x801326AC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801326B0: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x801326B4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801326B8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x801326BC: lui         $t6, 0x9F
    ctx->r14 = S32(0X9F << 16);
    // 0x801326C0: ori         $t6, $t6, 0xC008
    ctx->r14 = ctx->r14 | 0XC008;
    // 0x801326C4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801326C8: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x801326CC: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x801326D0: lui         $t7, 0xE4A0
    ctx->r15 = S32(0XE4A0 << 16);
    // 0x801326D4: lui         $s6, 0xF200
    ctx->r22 = S32(0XF200 << 16);
    // 0x801326D8: sw          $s6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r22;
    // 0x801326DC: ori         $t7, $t7, 0xC
    ctx->r15 = ctx->r15 | 0XC;
    // 0x801326E0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801326E4: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x801326E8: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x801326EC: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x801326F0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801326F4: lui         $s7, 0xE100
    ctx->r23 = S32(0XE100 << 16);
    // 0x801326F8: sw          $s7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r23;
    // 0x801326FC: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x80132700: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80132704: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80132708: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x8013270C: lui         $fp, 0xF100
    ctx->r30 = S32(0XF100 << 16);
    // 0x80132710: sw          $fp, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r30;
    // 0x80132714: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80132718: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8013271C: addiu       $t7, $zero, 0x1E00
    ctx->r15 = ADD32(0, 0X1E00);
    // 0x80132720: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80132724: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80132728: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x8013272C: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80132730: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80132734: lui         $s1, 0xE4A0
    ctx->r17 = S32(0XE4A0 << 16);
    // 0x80132738: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8013273C: addiu       $t5, $zero, 0xF00
    ctx->r13 = ADD32(0, 0XF00);
    // 0x80132740: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_80132744:
    // 0x80132744: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80132748: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8013274C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80132750: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x80132754: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132758: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x8013275C: addu        $t6, $t9, $at
    ctx->r14 = ADD32(ctx->r25, ctx->r1);
    // 0x80132760: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80132764: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80132768: lui         $t7, 0x709
    ctx->r15 = S32(0X709 << 16);
    // 0x8013276C: ori         $t7, $t7, 0x82A0
    ctx->r15 = ctx->r15 | 0X82A0;
    // 0x80132770: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132774: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80132778: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8013277C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132780: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x80132784: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80132788: lui         $t8, 0x777
    ctx->r24 = S32(0X777 << 16);
    // 0x8013278C: ori         $t8, $t8, 0xF00D
    ctx->r24 = ctx->r24 | 0XF00D;
    // 0x80132790: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132794: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80132798: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x8013279C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x801327A0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x801327A4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801327A8: sw          $s5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r21;
    // 0x801327AC: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x801327B0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x801327B4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x801327B8: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x801327BC: lui         $t7, 0x9
    ctx->r15 = S32(0X9 << 16);
    // 0x801327C0: lui         $t6, 0xF511
    ctx->r14 = S32(0XF511 << 16);
    // 0x801327C4: ori         $t6, $t6, 0x4000
    ctx->r14 = ctx->r14 | 0X4000;
    // 0x801327C8: ori         $t7, $t7, 0x82A0
    ctx->r15 = ctx->r15 | 0X82A0;
    // 0x801327CC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801327D0: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x801327D4: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x801327D8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801327DC: lui         $t8, 0x9F
    ctx->r24 = S32(0X9F << 16);
    // 0x801327E0: ori         $t8, $t8, 0xC008
    ctx->r24 = ctx->r24 | 0XC008;
    // 0x801327E4: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x801327E8: sw          $s6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r22;
    // 0x801327EC: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x801327F0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801327F4: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x801327F8: sll         $ra, $ra, 2
    ctx->r31 = S32(ctx->r31 << 2);
    // 0x801327FC: andi        $t9, $ra, 0xFFF
    ctx->r25 = ctx->r31 & 0XFFF;
    // 0x80132800: or          $t6, $t9, $s1
    ctx->r14 = ctx->r25 | ctx->r17;
    // 0x80132804: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80132808: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8013280C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132810: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x80132814: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80132818: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8013281C: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80132820: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132824: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x80132828: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8013282C: sw          $s7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r23;
    // 0x80132830: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x80132834: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x80132838: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8013283C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80132840: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80132844: sw          $fp, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r30;
    // 0x80132848: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8013284C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80132850: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80132854: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132858: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8013285C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80132860: addu        $t6, $t9, $at
    ctx->r14 = ADD32(ctx->r25, ctx->r1);
    // 0x80132864: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80132868: lui         $t7, 0x709
    ctx->r15 = S32(0X709 << 16);
    // 0x8013286C: ori         $t7, $t7, 0x82A0
    ctx->r15 = ctx->r15 | 0X82A0;
    // 0x80132870: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132874: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80132878: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8013287C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132880: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x80132884: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80132888: lui         $t8, 0x777
    ctx->r24 = S32(0X777 << 16);
    // 0x8013288C: ori         $t8, $t8, 0xF00D
    ctx->r24 = ctx->r24 | 0XF00D;
    // 0x80132890: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132894: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80132898: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x8013289C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x801328A0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x801328A4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801328A8: sw          $s5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r21;
    // 0x801328AC: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x801328B0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x801328B4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x801328B8: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x801328BC: lui         $t7, 0x9
    ctx->r15 = S32(0X9 << 16);
    // 0x801328C0: lui         $t6, 0xF511
    ctx->r14 = S32(0XF511 << 16);
    // 0x801328C4: ori         $t6, $t6, 0x4000
    ctx->r14 = ctx->r14 | 0X4000;
    // 0x801328C8: ori         $t7, $t7, 0x82A0
    ctx->r15 = ctx->r15 | 0X82A0;
    // 0x801328CC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801328D0: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x801328D4: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x801328D8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801328DC: lui         $t8, 0x9F
    ctx->r24 = S32(0X9F << 16);
    // 0x801328E0: ori         $t8, $t8, 0xC008
    ctx->r24 = ctx->r24 | 0XC008;
    // 0x801328E4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801328E8: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x801328EC: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x801328F0: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x801328F4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x801328F8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801328FC: sw          $s6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r22;
    // 0x80132900: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x80132904: or          $t7, $t6, $s1
    ctx->r15 = ctx->r14 | ctx->r17;
    // 0x80132908: andi        $t8, $ra, 0xFFF
    ctx->r24 = ctx->r31 & 0XFFF;
    // 0x8013290C: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x80132910: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80132914: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132918: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x8013291C: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80132920: sw          $s7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r23;
    // 0x80132924: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80132928: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x8013292C: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x80132930: sw          $fp, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r30;
    // 0x80132934: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80132938: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8013293C: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80132940: addiu       $t7, $t6, 0x6
    ctx->r15 = ADD32(ctx->r14, 0X6);
    // 0x80132944: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80132948: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8013294C: addiu       $at, $zero, 0x1D1
    ctx->r1 = ADD32(0, 0X1D1);
    // 0x80132950: addiu       $t9, $t8, 0x6
    ctx->r25 = ADD32(ctx->r24, 0X6);
    // 0x80132954: addiu       $t7, $t6, 0x1E00
    ctx->r15 = ADD32(ctx->r14, 0X1E00);
    // 0x80132958: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8013295C: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80132960: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132964: bne         $s0, $at, L_80132744
    if (ctx->r16 != ctx->r1) {
        // 0x80132968: addiu       $t5, $t5, 0x1E00
        ctx->r13 = ADD32(ctx->r13, 0X1E00);
            goto L_80132744;
    }
    // 0x80132968: addiu       $t5, $t5, 0x1E00
    ctx->r13 = ADD32(ctx->r13, 0X1E00);
    // 0x8013296C: b           L_80132CC4
    // 0x80132970: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80132CC4;
    // 0x80132970: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132974:
    // 0x80132974: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x80132978: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8013297C: ori         $at, $at, 0xB000
    ctx->r1 = ctx->r1 | 0XB000;
    // 0x80132980: addiu       $s0, $s0, -0x800
    ctx->r16 = ADD32(ctx->r16, -0X800);
    // 0x80132984: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80132988: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8013298C: addu        $t8, $s0, $at
    ctx->r24 = ADD32(ctx->r16, ctx->r1);
    // 0x80132990: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132994: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80132998: lui         $s2, 0xFD10
    ctx->r18 = S32(0XFD10 << 16);
    // 0x8013299C: lui         $t9, 0x709
    ctx->r25 = S32(0X709 << 16);
    // 0x801329A0: ori         $t9, $t9, 0x8290
    ctx->r25 = ctx->r25 | 0X8290;
    // 0x801329A4: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x801329A8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801329AC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801329B0: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x801329B4: lui         $s3, 0xF510
    ctx->r19 = S32(0XF510 << 16);
    // 0x801329B8: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x801329BC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801329C0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x801329C4: lui         $s4, 0xE600
    ctx->r20 = S32(0XE600 << 16);
    // 0x801329C8: lui         $t6, 0x777
    ctx->r14 = S32(0X777 << 16);
    // 0x801329CC: ori         $t6, $t6, 0xF01A
    ctx->r14 = ctx->r14 | 0XF01A;
    // 0x801329D0: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x801329D4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801329D8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x801329DC: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x801329E0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x801329E4: lui         $s5, 0xF300
    ctx->r21 = S32(0XF300 << 16);
    // 0x801329E8: sw          $s5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r21;
    // 0x801329EC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801329F0: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x801329F4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801329F8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x801329FC: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80132A00: lui         $t9, 0x9
    ctx->r25 = S32(0X9 << 16);
    // 0x80132A04: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x80132A08: ori         $t8, $t8, 0xA000
    ctx->r24 = ctx->r24 | 0XA000;
    // 0x80132A0C: ori         $t9, $t9, 0x8290
    ctx->r25 = ctx->r25 | 0X8290;
    // 0x80132A10: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132A14: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80132A18: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80132A1C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80132A20: lui         $t6, 0x4F
    ctx->r14 = S32(0X4F << 16);
    // 0x80132A24: ori         $t6, $t6, 0xC014
    ctx->r14 = ctx->r14 | 0XC014;
    // 0x80132A28: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132A2C: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x80132A30: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80132A34: lui         $s6, 0xF200
    ctx->r22 = S32(0XF200 << 16);
    // 0x80132A38: sw          $s6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r22;
    // 0x80132A3C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132A40: lui         $t7, 0xE450
    ctx->r15 = S32(0XE450 << 16);
    // 0x80132A44: ori         $t7, $t7, 0x18
    ctx->r15 = ctx->r15 | 0X18;
    // 0x80132A48: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x80132A4C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80132A50: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80132A54: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132A58: lui         $s7, 0xE100
    ctx->r23 = S32(0XE100 << 16);
    // 0x80132A5C: sw          $s7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r23;
    // 0x80132A60: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x80132A64: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80132A68: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80132A6C: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80132A70: lui         $fp, 0xF100
    ctx->r30 = S32(0XF100 << 16);
    // 0x80132A74: sw          $fp, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r30;
    // 0x80132A78: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80132A7C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80132A80: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80132A84: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x80132A88: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80132A8C: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x80132A90: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132A94: addiu       $t5, $zero, 0xF00
    ctx->r13 = ADD32(0, 0XF00);
    // 0x80132A98: addiu       $s1, $zero, 0x12
    ctx->r17 = ADD32(0, 0X12);
L_80132A9C:
    // 0x80132A9C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80132AA0: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80132AA4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80132AA8: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80132AAC: ori         $at, $at, 0xB000
    ctx->r1 = ctx->r1 | 0XB000;
    // 0x80132AB0: addu        $ra, $t7, $t5
    ctx->r31 = ADD32(ctx->r15, ctx->r13);
    // 0x80132AB4: addu        $t8, $ra, $at
    ctx->r24 = ADD32(ctx->r31, ctx->r1);
    // 0x80132AB8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132ABC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80132AC0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132AC4: lui         $t9, 0x709
    ctx->r25 = S32(0X709 << 16);
    // 0x80132AC8: ori         $t9, $t9, 0x8290
    ctx->r25 = ctx->r25 | 0X8290;
    // 0x80132ACC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132AD0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80132AD4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80132AD8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132ADC: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x80132AE0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80132AE4: lui         $t6, 0x777
    ctx->r14 = S32(0X777 << 16);
    // 0x80132AE8: ori         $t6, $t6, 0xF01A
    ctx->r14 = ctx->r14 | 0XF01A;
    // 0x80132AEC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132AF0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80132AF4: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x80132AF8: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80132AFC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80132B00: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132B04: sw          $s5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r21;
    // 0x80132B08: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80132B0C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80132B10: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80132B14: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80132B18: lui         $t9, 0x9
    ctx->r25 = S32(0X9 << 16);
    // 0x80132B1C: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x80132B20: ori         $t8, $t8, 0xA000
    ctx->r24 = ctx->r24 | 0XA000;
    // 0x80132B24: ori         $t9, $t9, 0x8290
    ctx->r25 = ctx->r25 | 0X8290;
    // 0x80132B28: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132B2C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80132B30: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80132B34: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80132B38: lui         $t6, 0x4F
    ctx->r14 = S32(0X4F << 16);
    // 0x80132B3C: ori         $t6, $t6, 0xC014
    ctx->r14 = ctx->r14 | 0XC014;
    // 0x80132B40: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80132B44: sw          $s6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r22;
    // 0x80132B48: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80132B4C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132B50: lui         $at, 0xE450
    ctx->r1 = S32(0XE450 << 16);
    // 0x80132B54: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80132B58: andi        $t7, $s0, 0xFFF
    ctx->r15 = ctx->r16 & 0XFFF;
    // 0x80132B5C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80132B60: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x80132B64: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80132B68: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80132B6C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132B70: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x80132B74: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80132B78: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80132B7C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80132B80: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132B84: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x80132B88: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80132B8C: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80132B90: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80132B94: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132B98: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80132B9C: sw          $s7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r23;
    // 0x80132BA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80132BA4: ori         $at, $at, 0xBF00
    ctx->r1 = ctx->r1 | 0XBF00;
    // 0x80132BA8: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80132BAC: addu        $t9, $ra, $at
    ctx->r25 = ADD32(ctx->r31, ctx->r1);
    // 0x80132BB0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132BB4: sw          $fp, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r30;
    // 0x80132BB8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132BBC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80132BC0: lui         $t6, 0x709
    ctx->r14 = S32(0X709 << 16);
    // 0x80132BC4: ori         $t6, $t6, 0x8290
    ctx->r14 = ctx->r14 | 0X8290;
    // 0x80132BC8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132BCC: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80132BD0: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80132BD4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80132BD8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132BDC: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x80132BE0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80132BE4: lui         $t7, 0x777
    ctx->r15 = S32(0X777 << 16);
    // 0x80132BE8: ori         $t7, $t7, 0xF01A
    ctx->r15 = ctx->r15 | 0XF01A;
    // 0x80132BEC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132BF0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80132BF4: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x80132BF8: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80132BFC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80132C00: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132C04: sw          $s5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r21;
    // 0x80132C08: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80132C0C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80132C10: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80132C14: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80132C18: lui         $t6, 0x9
    ctx->r14 = S32(0X9 << 16);
    // 0x80132C1C: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x80132C20: ori         $t9, $t9, 0xA000
    ctx->r25 = ctx->r25 | 0XA000;
    // 0x80132C24: ori         $t6, $t6, 0x8290
    ctx->r14 = ctx->r14 | 0X8290;
    // 0x80132C28: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132C2C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80132C30: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80132C34: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80132C38: lui         $t7, 0x4F
    ctx->r15 = S32(0X4F << 16);
    // 0x80132C3C: ori         $t7, $t7, 0xC014
    ctx->r15 = ctx->r15 | 0XC014;
    // 0x80132C40: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132C44: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x80132C48: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x80132C4C: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80132C50: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80132C54: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132C58: sw          $s6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r22;
    // 0x80132C5C: lui         $at, 0xE450
    ctx->r1 = S32(0XE450 << 16);
    // 0x80132C60: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80132C64: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x80132C68: andi        $t7, $s0, 0xFFF
    ctx->r15 = ctx->r16 & 0XFFF;
    // 0x80132C6C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80132C70: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80132C74: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132C78: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x80132C7C: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80132C80: sw          $s7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r23;
    // 0x80132C84: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80132C88: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80132C8C: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80132C90: sw          $fp, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r30;
    // 0x80132C94: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80132C98: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80132C9C: addiu       $at, $zero, 0xF6
    ctx->r1 = ADD32(0, 0XF6);
    // 0x80132CA0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80132CA4: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x80132CA8: addiu       $t6, $t9, 0xC
    ctx->r14 = ADD32(ctx->r25, 0XC);
    // 0x80132CAC: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x80132CB0: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80132CB4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132CB8: bne         $s1, $at, L_80132A9C
    if (ctx->r17 != ctx->r1) {
        // 0x80132CBC: addiu       $t5, $t5, 0x1E00
        ctx->r13 = ADD32(ctx->r13, 0X1E00);
            goto L_80132A9C;
    }
    // 0x80132CBC: addiu       $t5, $t5, 0x1E00
    ctx->r13 = ADD32(ctx->r13, 0X1E00);
    // 0x80132CC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132CC4:
    // 0x80132CC4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80132CC8: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x80132CCC: lui         $t9, 0xD700
    ctx->r25 = S32(0XD700 << 16);
    // 0x80132CD0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132CD4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80132CD8: lui         $t7, 0xDF00
    ctx->r15 = S32(0XDF00 << 16);
    // 0x80132CDC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132CE0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132CE4: b           L_80132CF8
    // 0x80132CE8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
        goto L_80132CF8;
    // 0x80132CE8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_80132CEC:
    // 0x80132CEC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132CF0: jal         0x800058DC
    // 0x80132CF4: addiu       $a1, $a1, 0x2D28
    ctx->r5 = ADD32(ctx->r5, 0X2D28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x80132CF4: addiu       $a1, $a1, 0x2D28
    ctx->r5 = ADD32(ctx->r5, 0X2D28);
    after_10:
L_80132CF8:
    // 0x80132CF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80132CFC:
    // 0x80132CFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80132D00: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80132D04: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80132D08: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80132D0C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80132D10: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80132D14: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80132D18: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80132D1C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80132D20: jr          $ra
    // 0x80132D24: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x80132D24: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80132d28(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80132d28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D28: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80132D2C: lw          $t6, -0x32B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X32B8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80132d30(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80132d30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132D38: bne         $t6, $zero, L_80132D64
    if (ctx->r14 != 0) {
        // 0x80132D3C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80132D64;
    }
    // 0x80132D3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80132D40: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80132D44: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x80132D48: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132D4C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80132D50: sh          $t7, 0xA6($v0)
    MEM_H(0XA6, ctx->r2) = ctx->r15;
    // 0x80132D54: sh          $t8, 0xA4($v0)
    MEM_H(0XA4, ctx->r2) = ctx->r24;
    // 0x80132D58: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80132D5C: jal         0x80005700
    // 0x80132D60: sb          $zero, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80132D60: sb          $zero, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = 0;
    after_0:
L_80132D64:
    // 0x80132D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132D6C: jr          $ra
    // 0x80132D70: nop

    return;
    // 0x80132D70: nop

;}
RECOMP_FUNC void M7_FUN_80132d74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132D78: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80132D7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80132D80: sb          $zero, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = 0;
    // 0x80132D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132D88: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80132D8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80132D90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132D94: sh          $t6, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = ctx->r14;
    // 0x80132D98: jal         0x800058DC
    // 0x80132D9C: addiu       $a1, $a1, 0x2DB0
    ctx->r5 = ADD32(ctx->r5, 0X2DB0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80132D9C: addiu       $a1, $a1, 0x2DB0
    ctx->r5 = ADD32(ctx->r5, 0X2DB0);
    after_0:
    // 0x80132DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132DA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132DA8: jr          $ra
    // 0x80132DAC: nop

    return;
    // 0x80132DAC: nop

;}
RECOMP_FUNC void M7_FUN_80132db0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132DB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132DB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80132DBC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80132DC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132DC4: lwc1        $f4, 0x94($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X94);
    // 0x80132DC8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132DCC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80132DD0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80132DD4: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80132DD8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132DDC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80132DE0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80132DE4: nop

    // 0x80132DE8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80132DEC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80132DF0: nop

    // 0x80132DF4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80132DF8: beql        $t7, $zero, L_80132E48
    if (ctx->r15 == 0) {
        // 0x80132DFC: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_80132E48;
    }
    goto skip_0;
    // 0x80132DFC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x80132E00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132E04: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132E08: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80132E0C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80132E10: nop

    // 0x80132E14: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80132E18: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80132E1C: nop

    // 0x80132E20: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80132E24: bne         $t7, $zero, L_80132E3C
    if (ctx->r15 != 0) {
        // 0x80132E28: nop
    
            goto L_80132E3C;
    }
    // 0x80132E28: nop

    // 0x80132E2C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80132E30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132E34: b           L_80132E54
    // 0x80132E38: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80132E54;
    // 0x80132E38: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80132E3C:
    // 0x80132E3C: b           L_80132E54
    // 0x80132E40: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80132E54;
    // 0x80132E40: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80132E44: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_80132E48:
    // 0x80132E48: nop

    // 0x80132E4C: bltz        $t7, L_80132E3C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80132E50: nop
    
            goto L_80132E3C;
    }
    // 0x80132E50: nop

L_80132E54:
    // 0x80132E54: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80132E58: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80132E5C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80132E60: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80132E64: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80132E68: sb          $t7, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r15;
    // 0x80132E6C: lwc1        $f16, 0x94($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X94);
    // 0x80132E70: ldc1        $f4, -0x28A0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X28A0);
    // 0x80132E74: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80132E78: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80132E7C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80132E80: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x80132E84: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80132E88: swc1        $f8, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f8.u32l;
    // 0x80132E8C: lwc1        $f16, 0x94($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X94);
    // 0x80132E90: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80132E94: c.le.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d <= ctx->f10.d;
    // 0x80132E98: nop

    // 0x80132E9C: bc1fl       L_80132EC4
    if (!c1cs) {
        // 0x80132EA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132EC4;
    }
    goto skip_1;
    // 0x80132EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80132EA4: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x80132EA8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80132EAC: addiu       $a1, $a1, 0x2ED0
    ctx->r5 = ADD32(ctx->r5, 0X2ED0);
    // 0x80132EB0: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
    // 0x80132EB4: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    // 0x80132EB8: jal         0x800058DC
    // 0x80132EBC: sh          $t1, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r9;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80132EBC: sh          $t1, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r9;
    after_0:
    // 0x80132EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132EC4:
    // 0x80132EC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132EC8: jr          $ra
    // 0x80132ECC: nop

    return;
    // 0x80132ECC: nop

;}
RECOMP_FUNC void M7_FUN_80132ed0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132ED8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132EDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80132EE0: lhu         $v0, 0x90($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X90);
    // 0x80132EE4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80132EE8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80132EEC: bne         $v0, $zero, L_80132F08
    if (ctx->r2 != 0) {
        // 0x80132EF0: sh          $t6, 0x90($a0)
        MEM_H(0X90, ctx->r4) = ctx->r14;
            goto L_80132F08;
    }
    // 0x80132EF0: sh          $t6, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r14;
    // 0x80132EF4: lw          $a0, 0x98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X98);
    // 0x80132EF8: jal         0x8001F540
    // 0x80132EFC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_0;
    // 0x80132EFC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80132F00: jal         0x80005700
    // 0x80132F04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80132F04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80132F08:
    // 0x80132F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132F0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132F10: jr          $ra
    // 0x80132F14: nop

    return;
    // 0x80132F14: nop

;}
RECOMP_FUNC void M7_FUN_80132f18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132F18: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80132F1C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80132F20: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80132F24: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80132F28: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80132F2C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80132F30: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80132F34: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80132F38: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80132F3C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80132F40: jal         0x80001060
    // 0x80132F44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x80132F44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80132F48: beq         $v0, $zero, L_80132F5C
    if (ctx->r2 == 0) {
        // 0x80132F4C: addiu       $t7, $zero, 0x26
        ctx->r15 = ADD32(0, 0X26);
            goto L_80132F5C;
    }
    // 0x80132F4C: addiu       $t7, $zero, 0x26
    ctx->r15 = ADD32(0, 0X26);
    // 0x80132F50: addiu       $t6, $zero, 0x4D
    ctx->r14 = ADD32(0, 0X4D);
    // 0x80132F54: b           L_80132F60
    // 0x80132F58: sb          $t6, 0x91($s5)
    MEM_B(0X91, ctx->r21) = ctx->r14;
        goto L_80132F60;
    // 0x80132F58: sb          $t6, 0x91($s5)
    MEM_B(0X91, ctx->r21) = ctx->r14;
L_80132F5C:
    // 0x80132F5C: sb          $t7, 0x91($s5)
    MEM_B(0X91, ctx->r21) = ctx->r15;
L_80132F60:
    // 0x80132F60: lbu         $t8, 0x90($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X90);
    // 0x80132F64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132F68: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80132F6C: bne         $t8, $at, L_80132F98
    if (ctx->r24 != ctx->r1) {
        // 0x80132F70: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80132F98;
    }
    // 0x80132F70: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132F74: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80132F78: jal         0x80005E44
    // 0x80132F7C: addiu       $a1, $a1, -0x735C
    ctx->r5 = ADD32(ctx->r5, -0X735C);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x80132F7C: addiu       $a1, $a1, -0x735C
    ctx->r5 = ADD32(ctx->r5, -0X735C);
    after_1:
    // 0x80132F80: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132F84: addiu       $a1, $a1, 0x3730
    ctx->r5 = ADD32(ctx->r5, 0X3730);
    // 0x80132F88: jal         0x800058DC
    // 0x80132F8C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80132F8C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x80132F90: b           L_801333F8
    // 0x80132F94: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_801333F8;
    // 0x80132F94: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80132F98:
    // 0x80132F98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80132F9C: sb          $t9, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = ctx->r25;
    // 0x80132FA0: lbu         $v0, 0x90($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X90);
    // 0x80132FA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132FA8: beql        $v0, $zero, L_80132FC4
    if (ctx->r2 == 0) {
        // 0x80132FAC: lw          $t6, 0x2C($s5)
        ctx->r14 = MEM_W(ctx->r21, 0X2C);
            goto L_80132FC4;
    }
    goto skip_0;
    // 0x80132FAC: lw          $t6, 0x2C($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X2C);
    skip_0:
    // 0x80132FB0: beq         $v0, $at, L_801333E8
    if (ctx->r2 == ctx->r1) {
        // 0x80132FB4: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_801333E8;
    }
    // 0x80132FB4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80132FB8: b           L_801333F8
    // 0x80132FBC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_801333F8;
    // 0x80132FBC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80132FC0: lw          $t6, 0x2C($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X2C);
L_80132FC4:
    // 0x80132FC4: lbu         $t8, 0x91($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X91);
    // 0x80132FC8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80132FCC: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x80132FD0: bltz        $t8, L_80133008
    if (SIGNED(ctx->r24) < 0) {
        // 0x80132FD4: sw          $t7, 0x2C($s5)
        MEM_W(0X2C, ctx->r21) = ctx->r15;
            goto L_80133008;
    }
    // 0x80132FD4: sw          $t7, 0x2C($s5)
    MEM_W(0X2C, ctx->r21) = ctx->r15;
L_80132FD8:
    // 0x80132FD8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80132FDC: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x80132FE0: jal         0x80005E44
    // 0x80132FE4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_3;
    // 0x80132FE4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x80132FE8: beql        $v0, $zero, L_801333F8
    if (ctx->r2 == 0) {
        // 0x80132FEC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801333F8;
    }
    goto skip_1;
    // 0x80132FEC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80132FF0: lbu         $t9, 0x91($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X91);
    // 0x80132FF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80132FF8: slt         $at, $t9, $s0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80132FFC: beq         $at, $zero, L_80132FD8
    if (ctx->r1 == 0) {
        // 0x80133000: nop
    
            goto L_80132FD8;
    }
    // 0x80133000: nop

    // 0x80133004: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80133008:
    // 0x80133008: jal         0x80006214
    // 0x8013300C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x8013300C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x80133010: jal         0x80001060
    // 0x80133014: nop

    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_5;
    // 0x80133014: nop

    after_5:
    // 0x80133018: beq         $v0, $zero, L_80133030
    if (ctx->r2 == 0) {
        // 0x8013301C: nop
    
            goto L_80133030;
    }
    // 0x8013301C: nop

    // 0x80133020: jal         0x8001F430
    // 0x80133024: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_6;
    // 0x80133024: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_6:
    // 0x80133028: b           L_8013303C
    // 0x8013302C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8013303C;
    // 0x8013302C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80133030:
    // 0x80133030: jal         0x8001F430
    // 0x80133034: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    LOOKUP_FUNC(0x8001F430)(rdram, ctx);
        goto after_7;
    // 0x80133034: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    after_7:
    // 0x80133038: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8013303C:
    // 0x8013303C: lbu         $t6, 0x91($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X91);
    // 0x80133040: sw          $v0, 0x98($s5)
    MEM_W(0X98, ctx->r21) = ctx->r2;
    // 0x80133044: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80133048: bltz        $t6, L_801333CC
    if (SIGNED(ctx->r14) < 0) {
        // 0x8013304C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801333CC;
    }
    // 0x8013304C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133050: lui         $s6, 0x8018
    ctx->r22 = S32(0X8018 << 16);
    // 0x80133054: addiu       $s6, $s6, -0x7320
    ctx->r22 = ADD32(ctx->r22, -0X7320);
    // 0x80133058: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8013305C: or          $s6, $s6, $at
    ctx->r22 = ctx->r22 | ctx->r1;
    // 0x80133060: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80133064: lui         $s4, 0x100
    ctx->r20 = S32(0X100 << 16);
    // 0x80133068: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013306C: ori         $s4, $s4, 0x4008
    ctx->r20 = ctx->r20 | 0X4008;
    // 0x80133070: lwc1        $f2, -0x2898($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2898);
    // 0x80133074: lui         $s3, 0xF200
    ctx->r19 = S32(0XF200 << 16);
    // 0x80133078: lui         $s2, 0xE700
    ctx->r18 = S32(0XE700 << 16);
    // 0x8013307C: lui         $s1, 0xF300
    ctx->r17 = S32(0XF300 << 16);
L_80133080:
    // 0x80133080: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80133084: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80133088: sh          $t7, 0x28($t8)
    MEM_H(0X28, ctx->r24) = ctx->r15;
    // 0x8013308C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80133090: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x80133094: sw          $s6, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r22;
    // 0x80133098: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8013309C: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801330A0: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x801330A4: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x801330A8: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x801330AC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801330B0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801330B4: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x801330B8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801330BC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801330C0: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x801330C4: swc1        $f2, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f2.u32l;
    // 0x801330C8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801330CC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801330D0: swc1        $f0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f0.u32l;
    // 0x801330D4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x801330D8: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x801330DC: ori         $t7, $t7, 0x600
    ctx->r15 = ctx->r15 | 0X600;
    // 0x801330E0: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x801330E4: sh          $t8, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r24;
    // 0x801330E8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x801330EC: sw          $t7, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r15;
    // 0x801330F0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801330F4: lw          $t6, 0x30($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X30);
    // 0x801330F8: sw          $v1, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r3;
    // 0x801330FC: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80133100: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80133104: jal         0x80001060
    // 0x80133108: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_8;
    // 0x80133108: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    after_8:
    // 0x8013310C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80133110: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80133114: lwc1        $f2, -0x2894($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2894);
    // 0x80133118: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x8013311C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80133120: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80133124: lui         $t4, 0xFD10
    ctx->r12 = S32(0XFD10 << 16);
    // 0x80133128: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x8013312C: beq         $v0, $zero, L_80133258
    if (ctx->r2 == 0) {
        // 0x80133130: lui         $ra, 0xE600
        ctx->r31 = S32(0XE600 << 16);
            goto L_80133258;
    }
    // 0x80133130: lui         $ra, 0xE600
    ctx->r31 = S32(0XE600 << 16);
    // 0x80133134: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80133138: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013313C: lwc1        $f4, -0x2890($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2890);
    // 0x80133140: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80133144: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80133148: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8013314C: swc1        $f4, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f4.u32l;
    // 0x80133150: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80133154: lwc1        $f6, -0x288C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X288C);
    // 0x80133158: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013315C: lw          $t6, 0x30($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X30);
    // 0x80133160: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80133164: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80133168: swc1        $f6, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f6.u32l;
    // 0x8013316C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80133170: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80133174: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80133178: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x8013317C: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x80133180: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80133184: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
    // 0x80133188: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8013318C: lwc1        $f8, -0x2888($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2888);
    // 0x80133190: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x80133194: lw          $t6, 0x30($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X30);
    // 0x80133198: lui         $t8, 0x8040
    ctx->r24 = S32(0X8040 << 16);
    // 0x8013319C: sll         $t7, $t7, 9
    ctx->r15 = S32(ctx->r15 << 9);
    // 0x801331A0: addu        $t9, $t7, $at
    ctx->r25 = ADD32(ctx->r15, ctx->r1);
    // 0x801331A4: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x801331A8: swc1        $f8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f8.u32l;
    // 0x801331AC: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x801331B0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801331B4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801331B8: lui         $t7, 0x709
    ctx->r15 = S32(0X709 << 16);
    // 0x801331BC: ori         $t7, $t7, 0x82A0
    ctx->r15 = ctx->r15 | 0X82A0;
    // 0x801331C0: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x801331C4: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x801331C8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801331CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801331D0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801331D4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x801331D8: sw          $ra, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r31;
    // 0x801331DC: lui         $t6, 0x777
    ctx->r14 = S32(0X777 << 16);
    // 0x801331E0: ori         $t6, $t6, 0xF00D
    ctx->r14 = ctx->r14 | 0XF00D;
    // 0x801331E4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801331E8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801331EC: addiu       $t8, $t8, -0x68F8
    ctx->r24 = ADD32(ctx->r24, -0X68F8);
    // 0x801331F0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801331F4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801331F8: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x801331FC: sll         $t9, $t2, 4
    ctx->r25 = S32(ctx->r10 << 4);
    // 0x80133200: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x80133204: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80133208: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8013320C: lui         $t9, 0x9
    ctx->r25 = S32(0X9 << 16);
    // 0x80133210: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80133214: sw          $s2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r18;
    // 0x80133218: lui         $t7, 0xF511
    ctx->r15 = S32(0XF511 << 16);
    // 0x8013321C: ori         $t7, $t7, 0x4000
    ctx->r15 = ctx->r15 | 0X4000;
    // 0x80133220: ori         $t9, $t9, 0x82A0
    ctx->r25 = ctx->r25 | 0X82A0;
    // 0x80133224: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80133228: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8013322C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80133230: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80133234: lui         $t8, 0x9F
    ctx->r24 = S32(0X9F << 16);
    // 0x80133238: ori         $t8, $t8, 0xC008
    ctx->r24 = ctx->r24 | 0XC008;
    // 0x8013323C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80133240: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80133244: sw          $s3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r19;
    // 0x80133248: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8013324C: sw          $s4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r20;
    // 0x80133250: b           L_80133364
    // 0x80133254: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80133364;
    // 0x80133254: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80133258:
    // 0x80133258: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8013325C: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80133260: ori         $at, $at, 0xB000
    ctx->r1 = ctx->r1 | 0XB000;
    // 0x80133264: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80133268: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8013326C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80133270: swc1        $f2, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f2.u32l;
    // 0x80133274: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80133278: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8013327C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80133280: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80133284: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80133288: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8013328C: swc1        $f2, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f2.u32l;
    // 0x80133290: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80133294: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80133298: sll         $t6, $s0, 4
    ctx->r14 = S32(ctx->r16 << 4);
    // 0x8013329C: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x801332A0: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x801332A4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x801332A8: sll         $t6, $t6, 8
    ctx->r14 = S32(ctx->r14 << 8);
    // 0x801332AC: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x801332B0: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801332B4: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x801332B8: addiu       $t9, $t9, -0x800
    ctx->r25 = ADD32(ctx->r25, -0X800);
    // 0x801332BC: swc1        $f0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f0.u32l;
    // 0x801332C0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x801332C4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801332C8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801332CC: lui         $t6, 0x709
    ctx->r14 = S32(0X709 << 16);
    // 0x801332D0: ori         $t6, $t6, 0x8290
    ctx->r14 = ctx->r14 | 0X8290;
    // 0x801332D4: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x801332D8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x801332DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801332E0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801332E4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x801332E8: sw          $ra, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r31;
    // 0x801332EC: lui         $t8, 0x777
    ctx->r24 = S32(0X777 << 16);
    // 0x801332F0: ori         $t8, $t8, 0xF01A
    ctx->r24 = ctx->r24 | 0XF01A;
    // 0x801332F4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801332F8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x801332FC: addiu       $t9, $t9, -0x72B8
    ctx->r25 = ADD32(ctx->r25, -0X72B8);
    // 0x80133300: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80133304: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80133308: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x8013330C: sll         $t7, $t2, 4
    ctx->r15 = S32(ctx->r10 << 4);
    // 0x80133310: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x80133314: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80133318: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8013331C: lui         $t7, 0x9
    ctx->r15 = S32(0X9 << 16);
    // 0x80133320: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80133324: sw          $s2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r18;
    // 0x80133328: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x8013332C: ori         $t6, $t6, 0xA000
    ctx->r14 = ctx->r14 | 0XA000;
    // 0x80133330: ori         $t7, $t7, 0x8290
    ctx->r15 = ctx->r15 | 0X8290;
    // 0x80133334: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80133338: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8013333C: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80133340: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80133344: lui         $t9, 0x4F
    ctx->r25 = S32(0X4F << 16);
    // 0x80133348: ori         $t9, $t9, 0xC014
    ctx->r25 = ctx->r25 | 0XC014;
    // 0x8013334C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80133350: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x80133354: sw          $s3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r19;
    // 0x80133358: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8013335C: sw          $s4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r20;
    // 0x80133360: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80133364:
    // 0x80133364: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80133368: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8013336C: ori         $t8, $t8, 0x204
    ctx->r24 = ctx->r24 | 0X204;
    // 0x80133370: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80133374: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x80133378: ori         $t6, $t6, 0x604
    ctx->r14 = ctx->r14 | 0X604;
    // 0x8013337C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80133380: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80133384: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80133388: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8013338C: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x80133390: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80133394: lui         $t7, 0xD700
    ctx->r15 = S32(0XD700 << 16);
    // 0x80133398: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8013339C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x801333A0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x801333A4: lui         $t8, 0xDF00
    ctx->r24 = S32(0XDF00 << 16);
    // 0x801333A8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801333AC: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801333B0: lbu         $t6, 0x91($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X91);
    // 0x801333B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801333B8: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x801333BC: slt         $at, $t6, $s0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x801333C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801333C4: beq         $at, $zero, L_80133080
    if (ctx->r1 == 0) {
        // 0x801333C8: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80133080;
    }
    // 0x801333C8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_801333CC:
    // 0x801333CC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801333D0: addiu       $a1, $a1, 0x341C
    ctx->r5 = ADD32(ctx->r5, 0X341C);
    // 0x801333D4: jal         0x800058DC
    // 0x801333D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x801333D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_9:
    // 0x801333DC: addiu       $t7, $zero, 0x7E
    ctx->r15 = ADD32(0, 0X7E);
    // 0x801333E0: b           L_801333F4
    // 0x801333E4: sh          $t7, 0x94($s5)
    MEM_H(0X94, ctx->r21) = ctx->r15;
        goto L_801333F4;
    // 0x801333E4: sh          $t7, 0x94($s5)
    MEM_H(0X94, ctx->r21) = ctx->r15;
L_801333E8:
    // 0x801333E8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801333EC: jal         0x800058DC
    // 0x801333F0: addiu       $a1, $a1, 0x3458
    ctx->r5 = ADD32(ctx->r5, 0X3458);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x801333F0: addiu       $a1, $a1, 0x3458
    ctx->r5 = ADD32(ctx->r5, 0X3458);
    after_10:
L_801333F4:
    // 0x801333F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801333F8:
    // 0x801333F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801333FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80133400: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80133404: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80133408: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8013340C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80133410: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80133414: jr          $ra
    // 0x80133418: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80133418: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013341c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013341c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013341C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133420: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80133424: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80133428: sb          $zero, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = 0;
    // 0x8013342C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133430: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80133434: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80133438: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013343C: sh          $t6, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = ctx->r14;
    // 0x80133440: jal         0x800058DC
    // 0x80133444: addiu       $a1, $a1, 0x34A4
    ctx->r5 = ADD32(ctx->r5, 0X34A4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80133444: addiu       $a1, $a1, 0x34A4
    ctx->r5 = ADD32(ctx->r5, 0X34A4);
    after_0:
    // 0x80133448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013344C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133450: jr          $ra
    // 0x80133454: nop

    return;
    // 0x80133454: nop

;}
RECOMP_FUNC void M7_FUN_80133458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133458: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8013345C: lw          $t6, -0x32B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X32B8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80133460(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80133460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133468: bne         $t6, $zero, L_80133494
    if (ctx->r14 != 0) {
        // 0x8013346C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80133494;
    }
    // 0x8013346C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80133470: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80133474: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x80133478: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8013347C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80133480: sh          $t7, 0xA6($v0)
    MEM_H(0XA6, ctx->r2) = ctx->r15;
    // 0x80133484: sh          $t8, 0xA4($v0)
    MEM_H(0XA4, ctx->r2) = ctx->r24;
    // 0x80133488: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013348C: jal         0x80005700
    // 0x80133490: sb          $zero, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80133490: sb          $zero, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = 0;
    after_0:
L_80133494:
    // 0x80133494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013349C: jr          $ra
    // 0x801334A0: nop

    return;
    // 0x801334A0: nop

;}
RECOMP_FUNC void M7_FUN_801334a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801334A4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801334A8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801334AC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801334B0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801334B4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801334B8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801334BC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801334C0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801334C4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801334C8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x801334CC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801334D0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801334D4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801334D8: lh          $t6, 0x96($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X96);
    // 0x801334DC: lbu         $t8, 0x91($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X91);
    // 0x801334E0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x801334E4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801334E8: sh          $t7, 0x96($a0)
    MEM_H(0X96, ctx->r4) = ctx->r15;
    // 0x801334EC: blez        $t8, L_801336D0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801334F0: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_801336D0;
    }
    // 0x801334F0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x801334F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801334F8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801334FC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80133500: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x80133504: lui         $at, 0x4260
    ctx->r1 = S32(0X4260 << 16);
    // 0x80133508: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8013350C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80133510: addiu       $s1, $a1, 0x4
    ctx->r17 = ADD32(ctx->r5, 0X4);
    // 0x80133514: addiu       $s4, $zero, 0x2000
    ctx->r20 = ADD32(0, 0X2000);
    // 0x80133518: addiu       $s6, $zero, 0x26
    ctx->r22 = ADD32(0, 0X26);
L_8013351C:
    // 0x8013351C: div         $zero, $s4, $s6
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r22)));
    // 0x80133520: mflo        $t3
    ctx->r11 = lo;
    // 0x80133524: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80133528: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8013352C: lh          $t9, 0x94($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X94);
    // 0x80133530: cvt.d.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.d = CVT_D_W(ctx->f4.u32l);
    // 0x80133534: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80133538: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8013353C: sb          $t0, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r8;
    // 0x80133540: add.d       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = ctx->f20.d + ctx->f20.d;
    // 0x80133544: bne         $s6, $zero, L_80133550
    if (ctx->r22 != 0) {
        // 0x80133548: nop
    
            goto L_80133550;
    }
    // 0x80133548: nop

    // 0x8013354C: break       7
    do_break(2148742476);
L_80133550:
    // 0x80133550: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133554: bne         $s6, $at, L_80133568
    if (ctx->r22 != ctx->r1) {
        // 0x80133558: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80133568;
    }
    // 0x80133558: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013355C: bne         $s4, $at, L_80133568
    if (ctx->r20 != ctx->r1) {
        // 0x80133560: nop
    
            goto L_80133568;
    }
    // 0x80133560: nop

    // 0x80133564: break       6
    do_break(2148742500);
L_80133568:
    // 0x80133568: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8013356C: mfc1        $s2, $f8
    ctx->r18 = (int32_t)ctx->f8.u32l;
    // 0x80133570: nop

    // 0x80133574: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80133578: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8013357C: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x80133580: jal         0x8001EAD0
    // 0x80133584: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80133584: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x80133588: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8013358C: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80133590: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x80133594: lw          $s0, 0x30($t5)
    ctx->r16 = MEM_W(ctx->r13, 0X30);
    // 0x80133598: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8013359C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801335A0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801335A4: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801335A8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801335AC: jal         0x8001EB64
    // 0x801335B0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801335B0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x801335B4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801335B8: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x801335BC: lw          $s0, 0x30($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X30);
    // 0x801335C0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801335C4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801335C8: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801335CC: mul.d       $f10, $f20, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = MUL_D(ctx->f20.d, ctx->f24.d);
    // 0x801335D0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801335D4: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x801335D8: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801335DC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801335E0: mfc1        $s2, $f16
    ctx->r18 = (int32_t)ctx->f16.u32l;
    // 0x801335E4: lw          $s0, 0x30($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X30);
    // 0x801335E8: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x801335EC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801335F0: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x801335F4: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x801335F8: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x801335FC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80133600: jal         0x8001EAD0
    // 0x80133604: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x80133604: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x80133608: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8013360C: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80133610: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x80133614: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    // 0x80133618: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8013361C: lh          $t1, 0x10($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X10);
    // 0x80133620: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80133624: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80133628: nop

    // 0x8013362C: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80133630: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80133634: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80133638: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8013363C: jal         0x8001EB64
    // 0x80133640: sh          $t2, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r10;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x80133640: sh          $t2, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r10;
    after_3:
    // 0x80133644: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80133648: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8013364C: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x80133650: lw          $s0, 0x30($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X30);
    // 0x80133654: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80133658: lh          $t4, 0x12($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X12);
    // 0x8013365C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80133660: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80133664: nop

    // 0x80133668: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x8013366C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80133670: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80133674: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80133678: jal         0x8001EB64
    // 0x8013367C: sh          $t6, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r14;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x8013367C: sh          $t6, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r14;
    after_4:
    // 0x80133680: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80133684: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80133688: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8013368C: lw          $s0, 0x30($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X30);
    // 0x80133690: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80133694: addiu       $s4, $s4, 0x2000
    ctx->r20 = ADD32(ctx->r20, 0X2000);
    // 0x80133698: lh          $t8, 0x14($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X14);
    // 0x8013369C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801336A0: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x801336A4: nop

    // 0x801336A8: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801336AC: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x801336B0: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x801336B4: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x801336B8: nop

    // 0x801336BC: sh          $t1, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r9;
    // 0x801336C0: lbu         $t0, 0x91($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X91);
    // 0x801336C4: slt         $at, $t0, $s3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x801336C8: beq         $at, $zero, L_8013351C
    if (ctx->r1 == 0) {
        // 0x801336CC: nop
    
            goto L_8013351C;
    }
    // 0x801336CC: nop

L_801336D0:
    // 0x801336D0: lh          $t2, 0x94($s5)
    ctx->r10 = MEM_H(ctx->r21, 0X94);
    // 0x801336D4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801336D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x801336DC: addiu       $t3, $t2, -0x2
    ctx->r11 = ADD32(ctx->r10, -0X2);
    // 0x801336E0: sh          $t3, 0x94($s5)
    MEM_H(0X94, ctx->r21) = ctx->r11;
    // 0x801336E4: lh          $t4, 0x94($s5)
    ctx->r12 = MEM_H(ctx->r21, 0X94);
    // 0x801336E8: bnel        $t4, $zero, L_801336FC
    if (ctx->r12 != 0) {
        // 0x801336EC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801336FC;
    }
    goto skip_0;
    // 0x801336EC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801336F0: jal         0x80005700
    // 0x801336F4: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_5;
    // 0x801336F4: sh          $zero, -0x6CAA($at)
    MEM_H(-0X6CAA, ctx->r1) = 0;
    after_5:
    // 0x801336F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801336FC:
    // 0x801336FC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80133700: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80133704: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80133708: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8013370C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80133710: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80133714: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80133718: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8013371C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80133720: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80133724: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80133728: jr          $ra
    // 0x8013372C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8013372C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80133730(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80133730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133730: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80133734: jr          $ra
    // 0x80133738: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80133738: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013373c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013373c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013373C: nop

    // 0x80133740: bgez        $a0, L_80133750
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80133744: sra         $t6, $a0, 3
        ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
            goto L_80133750;
    }
    // 0x80133744: sra         $t6, $a0, 3
    ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80133748: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x8013374C: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_80133750:
    // 0x80133750: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80133754: addiu       $t8, $t8, -0x3270
    ctx->r24 = ADD32(ctx->r24, -0X3270);
    // 0x80133758: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8013375C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80133760: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80133764: bgez        $a0, L_80133778
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80133768: andi        $t0, $a0, 0x7
        ctx->r8 = ctx->r4 & 0X7;
            goto L_80133778;
    }
    // 0x80133768: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x8013376C: beq         $t0, $zero, L_80133778
    if (ctx->r8 == 0) {
        // 0x80133770: nop
    
            goto L_80133778;
    }
    // 0x80133770: nop

    // 0x80133774: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_80133778:
    // 0x80133778: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8013377C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133780: sllv        $t4, $t2, $t1
    ctx->r12 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80133784: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x80133788: jr          $ra
    // 0x8013378C: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    return;
    // 0x8013378C: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80133790(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80133790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133790: bgez        $a0, L_801337A0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80133794: sra         $t6, $a0, 3
        ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
            goto L_801337A0;
    }
    // 0x80133794: sra         $t6, $a0, 3
    ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80133798: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x8013379C: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_801337A0:
    // 0x801337A0: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801337A4: addiu       $t8, $t8, -0x3270
    ctx->r24 = ADD32(ctx->r24, -0X3270);
    // 0x801337A8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801337AC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801337B0: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x801337B4: bgez        $a0, L_801337C8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801337B8: andi        $t0, $a0, 0x7
        ctx->r8 = ctx->r4 & 0X7;
            goto L_801337C8;
    }
    // 0x801337B8: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x801337BC: beq         $t0, $zero, L_801337C8
    if (ctx->r8 == 0) {
        // 0x801337C0: nop
    
            goto L_801337C8;
    }
    // 0x801337C0: nop

    // 0x801337C4: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_801337C8:
    // 0x801337C8: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x801337CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801337D0: sllv        $t4, $t2, $t1
    ctx->r12 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x801337D4: nor         $t5, $t4, $zero
    ctx->r13 = ~(ctx->r12 | 0);
    // 0x801337D8: and         $t6, $t9, $t5
    ctx->r14 = ctx->r25 & ctx->r13;
    // 0x801337DC: jr          $ra
    // 0x801337E0: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    return;
    // 0x801337E0: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801337e4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801337e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801337E4: bgez        $a0, L_801337F4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801337E8: sra         $t6, $a0, 3
        ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
            goto L_801337F4;
    }
    // 0x801337E8: sra         $t6, $a0, 3
    ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
    // 0x801337EC: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x801337F0: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_801337F4:
    // 0x801337F4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801337F8: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801337FC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80133800: lbu         $t8, -0x3270($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X3270);
    // 0x80133804: bgez        $a0, L_80133818
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80133808: andi        $t9, $a0, 0x7
        ctx->r25 = ctx->r4 & 0X7;
            goto L_80133818;
    }
    // 0x80133808: andi        $t9, $a0, 0x7
    ctx->r25 = ctx->r4 & 0X7;
    // 0x8013380C: beq         $t9, $zero, L_80133818
    if (ctx->r25 == 0) {
        // 0x80133810: nop
    
            goto L_80133818;
    }
    // 0x80133810: nop

    // 0x80133814: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
L_80133818:
    // 0x80133818: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8013381C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133820: sllv        $t3, $t1, $t0
    ctx->r11 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x80133824: and         $v0, $t8, $t3
    ctx->r2 = ctx->r24 & ctx->r11;
    // 0x80133828: jr          $ra
    // 0x8013382C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    return;
    // 0x8013382C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80133830(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80133830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133830: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80133834: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80133838: addiu       $v0, $v0, -0x320C
    ctx->r2 = ADD32(ctx->r2, -0X320C);
    // 0x8013383C: addiu       $v1, $v1, -0x3270
    ctx->r3 = ADD32(ctx->r3, -0X3270);
L_80133840:
    // 0x80133840: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80133844: sb          $zero, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = 0;
    // 0x80133848: sb          $zero, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = 0;
    // 0x8013384C: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
    // 0x80133850: bne         $v1, $v0, L_80133840
    if (ctx->r3 != ctx->r2) {
        // 0x80133854: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_80133840;
    }
    // 0x80133854: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x80133858: jr          $ra
    // 0x8013385C: nop

    return;
    // 0x8013385C: nop

;}
RECOMP_FUNC void M7_FUN_80133860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133860: bgez        $a0, L_80133870
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80133864: sra         $t6, $a0, 3
        ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
            goto L_80133870;
    }
    // 0x80133864: sra         $t6, $a0, 3
    ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80133868: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x8013386C: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_80133870:
    // 0x80133870: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80133874: addiu       $t8, $t8, -0x3208
    ctx->r24 = ADD32(ctx->r24, -0X3208);
    // 0x80133878: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8013387C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80133880: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80133884: bgez        $a0, L_80133898
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80133888: andi        $t0, $a0, 0x7
        ctx->r8 = ctx->r4 & 0X7;
            goto L_80133898;
    }
    // 0x80133888: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x8013388C: beq         $t0, $zero, L_80133898
    if (ctx->r8 == 0) {
        // 0x80133890: nop
    
            goto L_80133898;
    }
    // 0x80133890: nop

    // 0x80133894: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_80133898:
    // 0x80133898: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8013389C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801338A0: sllv        $t4, $t2, $t1
    ctx->r12 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x801338A4: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x801338A8: jr          $ra
    // 0x801338AC: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    return;
    // 0x801338AC: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801338b0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801338b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801338B0: bgez        $a0, L_801338C0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801338B4: sra         $t6, $a0, 3
        ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
            goto L_801338C0;
    }
    // 0x801338B4: sra         $t6, $a0, 3
    ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
    // 0x801338B8: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x801338BC: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_801338C0:
    // 0x801338C0: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801338C4: addiu       $t8, $t8, -0x3208
    ctx->r24 = ADD32(ctx->r24, -0X3208);
    // 0x801338C8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801338CC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801338D0: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x801338D4: bgez        $a0, L_801338E8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801338D8: andi        $t0, $a0, 0x7
        ctx->r8 = ctx->r4 & 0X7;
            goto L_801338E8;
    }
    // 0x801338D8: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x801338DC: beq         $t0, $zero, L_801338E8
    if (ctx->r8 == 0) {
        // 0x801338E0: nop
    
            goto L_801338E8;
    }
    // 0x801338E0: nop

    // 0x801338E4: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_801338E8:
    // 0x801338E8: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x801338EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801338F0: sllv        $t4, $t2, $t1
    ctx->r12 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x801338F4: nor         $t5, $t4, $zero
    ctx->r13 = ~(ctx->r12 | 0);
    // 0x801338F8: and         $t6, $t9, $t5
    ctx->r14 = ctx->r25 & ctx->r13;
    // 0x801338FC: jr          $ra
    // 0x80133900: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    return;
    // 0x80133900: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80133904(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80133904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133904: bgez        $a0, L_80133914
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80133908: sra         $t6, $a0, 3
        ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
            goto L_80133914;
    }
    // 0x80133908: sra         $t6, $a0, 3
    ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8013390C: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x80133910: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_80133914:
    // 0x80133914: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80133918: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8013391C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80133920: lbu         $t8, -0x3208($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X3208);
    // 0x80133924: bgez        $a0, L_80133938
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80133928: andi        $t9, $a0, 0x7
        ctx->r25 = ctx->r4 & 0X7;
            goto L_80133938;
    }
    // 0x80133928: andi        $t9, $a0, 0x7
    ctx->r25 = ctx->r4 & 0X7;
    // 0x8013392C: beq         $t9, $zero, L_80133938
    if (ctx->r25 == 0) {
        // 0x80133930: nop
    
            goto L_80133938;
    }
    // 0x80133930: nop

    // 0x80133934: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
L_80133938:
    // 0x80133938: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8013393C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133940: sllv        $t3, $t1, $t0
    ctx->r11 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x80133944: and         $v0, $t8, $t3
    ctx->r2 = ctx->r24 & ctx->r11;
    // 0x80133948: jr          $ra
    // 0x8013394C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    return;
    // 0x8013394C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80133950(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80133950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133950: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80133954: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80133958: addiu       $v0, $v0, -0x31A4
    ctx->r2 = ADD32(ctx->r2, -0X31A4);
    // 0x8013395C: addiu       $v1, $v1, -0x3208
    ctx->r3 = ADD32(ctx->r3, -0X3208);
L_80133960:
    // 0x80133960: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80133964: sb          $zero, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = 0;
    // 0x80133968: sb          $zero, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = 0;
    // 0x8013396C: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
    // 0x80133970: bne         $v1, $v0, L_80133960
    if (ctx->r3 != ctx->r2) {
        // 0x80133974: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_80133960;
    }
    // 0x80133974: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x80133978: jr          $ra
    // 0x8013397C: nop

    return;
    // 0x8013397C: nop

;}
RECOMP_FUNC void M7_FUN_80133980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133980: bgez        $a0, L_80133990
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80133984: sra         $t6, $a0, 3
        ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
            goto L_80133990;
    }
    // 0x80133984: sra         $t6, $a0, 3
    ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80133988: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x8013398C: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_80133990:
    // 0x80133990: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80133994: addiu       $t8, $t8, -0x23E0
    ctx->r24 = ADD32(ctx->r24, -0X23E0);
    // 0x80133998: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8013399C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801339A0: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x801339A4: bgez        $a0, L_801339B8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801339A8: andi        $t0, $a0, 0x7
        ctx->r8 = ctx->r4 & 0X7;
            goto L_801339B8;
    }
    // 0x801339A8: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x801339AC: beq         $t0, $zero, L_801339B8
    if (ctx->r8 == 0) {
        // 0x801339B0: nop
    
            goto L_801339B8;
    }
    // 0x801339B0: nop

    // 0x801339B4: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_801339B8:
    // 0x801339B8: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x801339BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801339C0: sllv        $t4, $t2, $t1
    ctx->r12 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x801339C4: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x801339C8: jr          $ra
    // 0x801339CC: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    return;
    // 0x801339CC: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801339d0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801339d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801339D0: bgez        $a0, L_801339E0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801339D4: sra         $t6, $a0, 3
        ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
            goto L_801339E0;
    }
    // 0x801339D4: sra         $t6, $a0, 3
    ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
    // 0x801339D8: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x801339DC: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_801339E0:
    // 0x801339E0: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x801339E4: addiu       $t8, $t8, -0x23E0
    ctx->r24 = ADD32(ctx->r24, -0X23E0);
    // 0x801339E8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801339EC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801339F0: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x801339F4: bgez        $a0, L_80133A08
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801339F8: andi        $t0, $a0, 0x7
        ctx->r8 = ctx->r4 & 0X7;
            goto L_80133A08;
    }
    // 0x801339F8: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x801339FC: beq         $t0, $zero, L_80133A08
    if (ctx->r8 == 0) {
        // 0x80133A00: nop
    
            goto L_80133A08;
    }
    // 0x80133A00: nop

    // 0x80133A04: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_80133A08:
    // 0x80133A08: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80133A0C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133A10: sllv        $t4, $t2, $t1
    ctx->r12 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80133A14: nor         $t5, $t4, $zero
    ctx->r13 = ~(ctx->r12 | 0);
    // 0x80133A18: and         $t6, $t9, $t5
    ctx->r14 = ctx->r25 & ctx->r13;
    // 0x80133A1C: jr          $ra
    // 0x80133A20: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    return;
    // 0x80133A20: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80133a24(rdram, ctx);
;}
