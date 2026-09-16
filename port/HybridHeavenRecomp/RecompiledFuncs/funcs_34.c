#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_8014fee0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FEE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014FEE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014FEE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014FEEC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8014FEF0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014FEF4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014FEF8: sw          $t6, -0xE80($at)
    MEM_W(-0XE80, ctx->r1) = ctx->r14;
    // 0x8014FEFC: jal         0x800058DC
    // 0x8014FF00: addiu       $a1, $a1, -0xEC
    ctx->r5 = ADD32(ctx->r5, -0XEC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x8014FF00: addiu       $a1, $a1, -0xEC
    ctx->r5 = ADD32(ctx->r5, -0XEC);
    after_0:
    // 0x8014FF04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014FF08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014FF0C: jr          $ra
    // 0x8014FF10: nop

    return;
    // 0x8014FF10: nop

;}
RECOMP_FUNC void M7_FUN_8014ff14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FF14: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014FF18: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8014FF1C: lwc1        $f2, 0x1E8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1E8);
    // 0x8014FF20: lwc1        $f4, 0x334($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X334);
    // 0x8014FF24: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8014FF28: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8014FF2C: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8014FF30: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014FF34: ldc1        $f10, 0x6D0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X6D0);
    // 0x8014FF38: lwc1        $f12, 0x1EC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X1EC);
    // 0x8014FF3C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8014FF40: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8014FF44: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8014FF48: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014FF4C: lwc1        $f14, 0x1F0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1F0);
    // 0x8014FF50: lwc1        $f16, 0x1F4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1F4);
    // 0x8014FF54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014FF58: lwc1        $f18, 0x1F8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1F8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014ff5c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014ff5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FF5C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8014FF60: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8014FF64: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x8014FF68: lwc1        $f6, 0x338($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X338);
    // 0x8014FF6C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8014FF70: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8014FF74: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8014FF78: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8014FF7C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8014FF80: sub.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8014FF84: swc1        $f10, 0x1E8($v0)
    MEM_W(0X1E8, ctx->r2) = ctx->f10.u32l;
    // 0x8014FF88: ldc1        $f10, 0x6D8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X6D8);
    // 0x8014FF8C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014FF90: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8014FF94: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x8014FF98: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8014FF9C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8014FFA0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8014FFA4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8014FFA8: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8014FFAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8014FFB0: addiu       $a0, $a0, 0x4E8
    ctx->r4 = ADD32(ctx->r4, 0X4E8);
    // 0x8014FFB4: addiu       $a1, $zero, 0x88B
    ctx->r5 = ADD32(0, 0X88B);
    // 0x8014FFB8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8014FFBC: lwc1        $f4, 0x33C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X33C);
    // 0x8014FFC0: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8014FFC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8014FFC8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8014FFCC: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8014FFD0: swc1        $f10, 0x1EC($v0)
    MEM_W(0X1EC, ctx->r2) = ctx->f10.u32l;
    // 0x8014FFD4: ldc1        $f10, 0x6E0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X6E0);
    // 0x8014FFD8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8014FFDC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8014FFE0: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x8014FFE4: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8014FFE8: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x8014FFEC: lwc1        $f4, 0x340($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X340);
    // 0x8014FFF0: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8014FFF4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8014FFF8: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8014FFFC: swc1        $f10, 0x1F0($v0)
    MEM_W(0X1F0, ctx->r2) = ctx->f10.u32l;
    // 0x80150000: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80150004: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80150008: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x8015000C: lwc1        $f4, 0x344($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X344);
    // 0x80150010: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80150014: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80150018: sub.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8015001C: swc1        $f10, 0x1F4($v0)
    MEM_W(0X1F4, ctx->r2) = ctx->f10.u32l;
    // 0x80150020: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80150024: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80150028: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x8015002C: lwc1        $f6, 0x1FC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1FC);
    // 0x80150030: lwc1        $f4, 0x348($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X348);
    // 0x80150034: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80150038: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x8015003C: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80150040: swc1        $f10, 0x1F8($v0)
    MEM_W(0X1F8, ctx->r2) = ctx->f10.u32l;
    // 0x80150044: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80150048: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8015004C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80150050: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80150054: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x80150058: lwc1        $f4, 0x1E8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1E8);
    // 0x8015005C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80150060: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80150064: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80150068: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8015006C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80150070: swc1        $f8, 0x1FC($v0)
    MEM_W(0X1FC, ctx->r2) = ctx->f8.u32l;
    // 0x80150074: lwc1        $f8, 0x1F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1F0);
    // 0x80150078: lwc1        $f4, 0x1F4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1F4);
    // 0x8015007C: lwc1        $f6, 0x1EC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1EC);
    // 0x80150080: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80150084: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80150088: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8015008C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80150090: lwc1        $f6, 0x1F8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1F8);
    // 0x80150094: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80150098: lwc1        $f8, 0x1FC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1FC);
    // 0x8015009C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801500A0: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801500A4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801500A8: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x801500AC: jal         0x8011AAF4
    // 0x801500B0: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x801500B0: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801500B4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801500B8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801500BC: lwc1        $f2, 0x1E8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1E8);
    // 0x801500C0: lwc1        $f0, 0x334($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X334);
    // 0x801500C4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801500C8: nop

    // 0x801500CC: bc1fl       L_801500E4
    if (!c1cs) {
        // 0x801500D0: sub.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_801500E4;
    }
    goto skip_0;
    // 0x801500D0: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    skip_0:
    // 0x801500D4: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x801500D8: b           L_801500E4
    // 0x801500DC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_801500E4;
    // 0x801500DC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x801500E0: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
L_801500E4:
    // 0x801500E4: trunc.w.s   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x801500E8: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x801500EC: nop

    // 0x801500F0: bnel        $t0, $zero, L_8015018C
    if (ctx->r8 != 0) {
        // 0x801500F4: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8015018C;
    }
    goto skip_1;
    // 0x801500F4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x801500F8: lwc1        $f12, 0x1EC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X1EC);
    // 0x801500FC: lwc1        $f0, 0x338($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X338);
    // 0x80150100: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80150104: nop

    // 0x80150108: bc1fl       L_80150120
    if (!c1cs) {
        // 0x8015010C: sub.s       $f2, $f12, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_80150120;
    }
    goto skip_2;
    // 0x8015010C: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    skip_2:
    // 0x80150110: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80150114: b           L_80150120
    // 0x80150118: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_80150120;
    // 0x80150118: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8015011C: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
L_80150120:
    // 0x80150120: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80150124: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80150128: nop

    // 0x8015012C: bnel        $t2, $zero, L_8015018C
    if (ctx->r10 != 0) {
        // 0x80150130: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8015018C;
    }
    goto skip_3;
    // 0x80150130: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_3:
    // 0x80150134: lwc1        $f14, 0x1F0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1F0);
    // 0x80150138: lwc1        $f0, 0x33C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X33C);
    // 0x8015013C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80150140: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80150144: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80150148: nop

    // 0x8015014C: bc1fl       L_80150164
    if (!c1cs) {
        // 0x80150150: sub.s       $f2, $f14, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f0.fl;
            goto L_80150164;
    }
    goto skip_4;
    // 0x80150150: sub.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f0.fl;
    skip_4:
    // 0x80150154: sub.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80150158: b           L_80150164
    // 0x8015015C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_80150164;
    // 0x8015015C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80150160: sub.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f0.fl;
L_80150164:
    // 0x80150164: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80150168: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8015016C: nop

    // 0x80150170: bnel        $t4, $zero, L_8015018C
    if (ctx->r12 != 0) {
        // 0x80150174: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8015018C;
    }
    goto skip_5;
    // 0x80150174: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_5:
    // 0x80150178: sb          $t5, 0x2AC($v0)
    MEM_B(0X2AC, ctx->r2) = ctx->r13;
    // 0x8015017C: sw          $zero, -0xE80($at)
    MEM_W(-0XE80, ctx->r1) = 0;
    // 0x80150180: jal         0x80005700
    // 0x80150184: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80150184: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x80150188: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8015018C:
    // 0x8015018C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80150190: jr          $ra
    // 0x80150194: nop

    return;
    // 0x80150194: nop

;}
RECOMP_FUNC void M7_FUN_80150198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015019C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801501A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801501A4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801501A8: jal         0x800058DC
    // 0x801501AC: addiu       $a1, $a1, 0x1C0
    ctx->r5 = ADD32(ctx->r5, 0X1C0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801501AC: addiu       $a1, $a1, 0x1C0
    ctx->r5 = ADD32(ctx->r5, 0X1C0);
    after_0:
    // 0x801501B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801501B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801501B8: jr          $ra
    // 0x801501BC: nop

    return;
    // 0x801501BC: nop

;}
RECOMP_FUNC void M7_FUN_801501c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801501C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801501C4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801501C8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801501CC: lwc1        $f4, 0x334($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X334);
    // 0x801501D0: lwc1        $f0, 0x200($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X200);
    // 0x801501D4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801501D8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801501DC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801501E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801501E4: lwc1        $f6, 0x338($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X338);
    // 0x801501E8: lwc1        $f8, 0x33C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X33C);
    // 0x801501EC: lwc1        $f10, 0x340($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X340);
    // 0x801501F0: lwc1        $f16, 0x344($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X344);
    // 0x801501F4: lwc1        $f18, 0x348($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X348);
    // 0x801501F8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801501FC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80150200: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80150204: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80150208: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8015020C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80150210: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80150214: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80150218: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8015021C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80150220: addiu       $a0, $a0, 0x548
    ctx->r4 = ADD32(ctx->r4, 0X548);
    // 0x80150224: addiu       $a1, $zero, 0x8AF
    ctx->r5 = ADD32(0, 0X8AF);
    // 0x80150228: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8015022C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80150230: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80150234: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80150238: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x8015023C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80150240: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80150244: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80150248: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8015024C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80150250: jal         0x8011AAF4
    // 0x80150254: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x80150254: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80150258: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8015025C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80150260: bne         $v0, $zero, L_80150304
    if (ctx->r2 != 0) {
        // 0x80150264: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_80150304;
    }
    // 0x80150264: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80150268: lwc1        $f0, 0x334($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X334);
    // 0x8015026C: lwc1        $f2, 0x338($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X338);
    // 0x80150270: lwc1        $f12, 0x33C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X33C);
    // 0x80150274: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80150278: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8015027C: lwc1        $f6, 0x340($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X340);
    // 0x80150280: lwc1        $f8, 0x344($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X344);
    // 0x80150284: lwc1        $f10, 0x348($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X348);
    // 0x80150288: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8015028C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80150290: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80150294: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80150298: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8015029C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x801502A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801502A4: addiu       $a0, $a0, 0x580
    ctx->r4 = ADD32(ctx->r4, 0X580);
    // 0x801502A8: addiu       $a1, $zero, 0x8B8
    ctx->r5 = ADD32(0, 0X8B8);
    // 0x801502AC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x801502B0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801502B4: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801502B8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801502BC: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x801502C0: swc1        $f0, 0x1E8($v1)
    MEM_W(0X1E8, ctx->r3) = ctx->f0.u32l;
    // 0x801502C4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801502C8: swc1        $f2, 0x1EC($v1)
    MEM_W(0X1EC, ctx->r3) = ctx->f2.u32l;
    // 0x801502CC: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x801502D0: swc1        $f12, 0x1F0($v1)
    MEM_W(0X1F0, ctx->r3) = ctx->f12.u32l;
    // 0x801502D4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x801502D8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x801502DC: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x801502E0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801502E4: jal         0x8011AAF4
    // 0x801502E8: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x801502E8: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801502EC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801502F0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801502F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801502F8: sb          $t2, 0x2AC($v1)
    MEM_B(0X2AC, ctx->r3) = ctx->r10;
    // 0x801502FC: jal         0x80005700
    // 0x80150300: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x80150300: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_2:
L_80150304:
    // 0x80150304: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80150308: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8015030C: jr          $ra
    // 0x80150310: nop

    return;
    // 0x80150310: nop

;}
RECOMP_FUNC void M7_FUN_80150314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150314: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80150318: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8015031C: sb          $a1, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r5;
    // 0x80150320: sb          $zero, 0x93($a0)
    MEM_B(0X93, ctx->r4) = 0;
    // 0x80150324: jr          $ra
    // 0x80150328: swc1        $f4, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80150328: swc1        $f4, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8015032c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8015032c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015032C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80150330: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80150334: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80150338: addiu       $s5, $s5, -0x4410
    ctx->r21 = ADD32(ctx->r21, -0X4410);
    // 0x8015033C: lhu         $t6, 0x3B8($s5)
    ctx->r14 = MEM_HU(ctx->r21, 0X3B8);
    // 0x80150340: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80150344: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x80150348: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8015034C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80150350: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80150354: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80150358: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8015035C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80150360: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80150364: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x80150368: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x8015036C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80150370: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80150374: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80150378: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8015037C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80150380: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80150384: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
    // 0x80150388: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8015038C: lwc1        $f28, 0x6E8($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X6E8);
    // 0x80150390: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80150394: blez        $t6, L_8015050C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80150398: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8015050C;
    }
    // 0x80150398: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8015039C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801503A0: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801503A4: lui         $at, 0x4032
    ctx->r1 = S32(0X4032 << 16);
    // 0x801503A8: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x801503AC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801503B0: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x801503B4: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801503B8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801503BC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801503C0: addiu       $s2, $s2, -0x4410
    ctx->r18 = ADD32(ctx->r18, -0X4410);
    // 0x801503C4: lw          $s1, 0x3BC($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3BC);
L_801503C8:
    // 0x801503C8: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x801503CC: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801503D0: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801503D4: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x801503D8: nop

    // 0x801503DC: bc1fl       L_801503F4
    if (!c1cs) {
        // 0x801503E0: sub.s       $f14, $f22, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f22.fl - ctx->f0.fl;
            goto L_801503F4;
    }
    goto skip_0;
    // 0x801503E0: sub.s       $f14, $f22, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f22.fl - ctx->f0.fl;
    skip_0:
    // 0x801503E4: sub.s       $f14, $f22, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x801503E8: b           L_801503F4
    // 0x801503EC: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
        goto L_801503F4;
    // 0x801503EC: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x801503F0: sub.s       $f14, $f22, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f22.fl - ctx->f0.fl;
L_801503F4:
    // 0x801503F4: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801503F8: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801503FC: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x80150400: nop

    // 0x80150404: bc1fl       L_8015041C
    if (!c1cs) {
        // 0x80150408: sub.s       $f2, $f24, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f0.fl;
            goto L_8015041C;
    }
    goto skip_1;
    // 0x80150408: sub.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f0.fl;
    skip_1:
    // 0x8015040C: sub.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x80150410: b           L_8015041C
    // 0x80150414: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_8015041C;
    // 0x80150414: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80150418: sub.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f0.fl;
L_8015041C:
    // 0x8015041C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80150420: jal         0x8002FC20
    // 0x80150424: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80150424: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80150428: c.le.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl <= ctx->f30.fl;
    // 0x8015042C: nop

    // 0x80150430: bc1fl       L_801504F8
    if (!c1cs) {
        // 0x80150434: lhu         $t2, 0x3B8($s5)
        ctx->r10 = MEM_HU(ctx->r21, 0X3B8);
            goto L_801504F8;
    }
    goto skip_2;
    // 0x80150434: lhu         $t2, 0x3B8($s5)
    ctx->r10 = MEM_HU(ctx->r21, 0X3B8);
    skip_2:
    // 0x80150438: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x8015043C: nop

    // 0x80150440: bc1fl       L_801504F8
    if (!c1cs) {
        // 0x80150444: lhu         $t2, 0x3B8($s5)
        ctx->r10 = MEM_HU(ctx->r21, 0X3B8);
            goto L_801504F8;
    }
    goto skip_3;
    // 0x80150444: lhu         $t2, 0x3B8($s5)
    ctx->r10 = MEM_HU(ctx->r21, 0X3B8);
    skip_3:
    // 0x80150448: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8015044C: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80150450: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x80150454: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x80150458: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8015045C: nop

    // 0x80150460: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80150464: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80150468: div.d       $f2, $f18, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x8015046C: c.le.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d <= ctx->f12.d;
    // 0x80150470: nop

    // 0x80150474: bc1fl       L_801504F8
    if (!c1cs) {
        // 0x80150478: lhu         $t2, 0x3B8($s5)
        ctx->r10 = MEM_HU(ctx->r21, 0X3B8);
            goto L_801504F8;
    }
    goto skip_4;
    // 0x80150478: lhu         $t2, 0x3B8($s5)
    ctx->r10 = MEM_HU(ctx->r21, 0X3B8);
    skip_4:
    // 0x8015047C: add.d       $f4, $f2, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f26.d); 
    ctx->f4.d = ctx->f2.d + ctx->f26.d;
    // 0x80150480: c.le.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d <= ctx->f4.d;
    // 0x80150484: nop

    // 0x80150488: bc1fl       L_801504F8
    if (!c1cs) {
        // 0x8015048C: lhu         $t2, 0x3B8($s5)
        ctx->r10 = MEM_HU(ctx->r21, 0X3B8);
            goto L_801504F8;
    }
    goto skip_5;
    // 0x8015048C: lhu         $t2, 0x3B8($s5)
    ctx->r10 = MEM_HU(ctx->r21, 0X3B8);
    skip_5:
    // 0x80150490: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x80150494: cvt.s.d     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f4.fl = CVT_S_D(ctx->f2.d);
    // 0x80150498: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x8015049C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801504A0: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x801504A4: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x801504A8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801504AC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x801504B0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801504B4: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x801504B8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801504BC: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    // 0x801504C0: lh          $t0, 0xA($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XA);
    // 0x801504C4: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x801504C8: nop

    // 0x801504CC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801504D0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801504D4: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x801504D8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801504DC: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x801504E0: lh          $t1, 0xC($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XC);
    // 0x801504E4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x801504E8: nop

    // 0x801504EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801504F0: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x801504F4: lhu         $t2, 0x3B8($s5)
    ctx->r10 = MEM_HU(ctx->r21, 0X3B8);
L_801504F8:
    // 0x801504F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801504FC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80150500: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80150504: bnel        $at, $zero, L_801503C8
    if (ctx->r1 != 0) {
        // 0x80150508: lw          $s1, 0x3BC($s2)
        ctx->r17 = MEM_W(ctx->r18, 0X3BC);
            goto L_801503C8;
    }
    goto skip_6;
    // 0x80150508: lw          $s1, 0x3BC($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3BC);
    skip_6:
L_8015050C:
    // 0x8015050C: beq         $s3, $zero, L_80150544
    if (ctx->r19 == 0) {
        // 0x80150510: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_80150544;
    }
    // 0x80150510: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80150514: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80150518: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    // 0x8015051C: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80150520: swc1        $f10, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f10.u32l;
    // 0x80150524: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80150528: swc1        $f16, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f16.u32l;
    // 0x8015052C: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80150530: sh          $s4, 0xE($s6)
    MEM_H(0XE, ctx->r22) = ctx->r20;
    // 0x80150534: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80150538: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8015053C: nop

    // 0x80150540: sh          $t4, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r12;
L_80150544:
    // 0x80150544: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80150548: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8015054C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80150550: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80150554: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80150558: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8015055C: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80150560: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80150564: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80150568: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8015056C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80150570: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80150574: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80150578: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8015057C: jr          $ra
    // 0x80150580: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80150580: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80150584(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80150584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150584: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80150588: lbu         $t6, -0x3FDB($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3FDB);
    // 0x8015058C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80150590: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80150594: beq         $t7, $zero, L_801505A4
    if (ctx->r15 == 0) {
            // 0x80150598: nop

    LOOKUP_FUNC(0x801505A4)(rdram, ctx);
    return;
    }
    // 0x80150598: nop

    // 0x8015059C: jr          $ra
    // 0x801505A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801505A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801505a4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801505a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801505A4: jr          $ra
    // 0x801505A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801505A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801505ac(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801505ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801505AC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801505B0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801505B4: lhu         $t6, 0x3B8($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X3B8);
    // 0x801505B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801505BC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801505C0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801505C4: beq         $at, $zero, L_801505D8
    if (ctx->r1 == 0) {
            // 0x801505C8: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    LOOKUP_FUNC(0x801505D8)(rdram, ctx);
    return;
    }
    // 0x801505C8: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801505CC: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x801505D0: jr          $ra
    // 0x801505D4: lw          $v0, 0x3BC($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X3BC);
    return;
    // 0x801505D4: lw          $v0, 0x3BC($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X3BC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801505d8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801505d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801505D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801505DC: jr          $ra
    // 0x801505E0: nop

    return;
    // 0x801505E0: nop

;}
RECOMP_FUNC void M7_FUN_801505e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801505E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801505E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801505EC: jal         0x80150584
    // 0x801505F0: nop

    LOOKUP_FUNC(0x80150584)(rdram, ctx);
        goto after_0;
    // 0x801505F0: nop

    after_0:
    // 0x801505F4: beq         $v0, $zero, L_80150608
    if (ctx->r2 == 0) {
        // 0x801505F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80150608;
    }
    // 0x801505F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801505FC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80150600: b           L_8015060C
    // 0x80150604: lhu         $v0, -0x4260($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4260);
        goto L_8015060C;
    // 0x80150604: lhu         $v0, -0x4260($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4260);
L_80150608:
    // 0x80150608: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8015060C:
    // 0x8015060C: jr          $ra
    // 0x80150610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80150610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80150614(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80150614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80150618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015061C: jal         0x80150584
    // 0x80150620: nop

    LOOKUP_FUNC(0x80150584)(rdram, ctx);
        goto after_0;
    // 0x80150620: nop

    after_0:
    // 0x80150624: beql        $v0, $zero, L_8015066C
    if (ctx->r2 == 0) {
        // 0x80150628: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015066C;
    }
    goto skip_0;
    // 0x80150628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8015062C: jal         0x801505E4
    // 0x80150630: nop

    LOOKUP_FUNC(0x801505E4)(rdram, ctx);
        goto after_1;
    // 0x80150630: nop

    after_1:
    // 0x80150634: jal         0x801505AC
    // 0x80150638: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x801505AC)(rdram, ctx);
        goto after_2;
    // 0x80150638: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x8015063C: lbu         $v1, 0x92($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X92);
    // 0x80150640: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80150644: bnel        $v1, $at, L_80150658
    if (ctx->r3 != ctx->r1) {
        // 0x80150648: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80150658;
    }
    goto skip_1;
    // 0x80150648: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x8015064C: b           L_8015066C
    // 0x80150650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8015066C;
    // 0x80150650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80150654: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80150658:
    // 0x80150658: bnel        $v1, $at, L_8015066C
    if (ctx->r3 != ctx->r1) {
        // 0x8015065C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015066C;
    }
    goto skip_2;
    // 0x8015065C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80150660: b           L_8015066C
    // 0x80150664: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8015066C;
    // 0x80150664: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80150668: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015066C:
    // 0x8015066C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80150674: jr          $ra
    // 0x80150678: nop

    return;
    // 0x80150678: nop

;}
RECOMP_FUNC void M7_FUN_8015067c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015067C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80150680: lhu         $t6, -0x4058($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4058);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80150684(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80150684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80150688: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015068C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80150690: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80150694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150698: beq         $at, $zero, L_801506D8
    if (ctx->r1 == 0) {
        // 0x8015069C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801506D8;
    }
    // 0x8015069C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801506A0: jal         0x801505AC
    // 0x801506A4: nop

    LOOKUP_FUNC(0x801505AC)(rdram, ctx);
        goto after_0;
    // 0x801506A4: nop

    after_0:
    // 0x801506A8: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    // 0x801506AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801506B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801506B4: bnel        $a0, $at, L_801506C8
    if (ctx->r4 != ctx->r1) {
        // 0x801506B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801506C8;
    }
    goto skip_0;
    // 0x801506B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x801506BC: b           L_801506DC
    // 0x801506C0: lhu         $v0, 0xA0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XA0);
        goto L_801506DC;
    // 0x801506C0: lhu         $v0, 0xA0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XA0);
    // 0x801506C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_801506C8:
    // 0x801506C8: bnel        $a0, $at, L_801506DC
    if (ctx->r4 != ctx->r1) {
        // 0x801506CC: lui         $v0, 0xFFFF
        ctx->r2 = S32(0XFFFF << 16);
            goto L_801506DC;
    }
    goto skip_1;
    // 0x801506CC: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    skip_1:
    // 0x801506D0: b           L_801506DC
    // 0x801506D4: lhu         $v0, 0xA2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XA2);
        goto L_801506DC;
    // 0x801506D4: lhu         $v0, 0xA2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XA2);
L_801506D8:
    // 0x801506D8: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
L_801506DC:
    // 0x801506DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801506E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801506E4: jr          $ra
    // 0x801506E8: nop

    return;
    // 0x801506E8: nop

;}
RECOMP_FUNC void M7_FUN_801506ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801506EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801506F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801506F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801506F8: jal         0x8014F400
    // 0x801506FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8014F400)(rdram, ctx);
        goto after_0;
    // 0x801506FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80150700: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80150704: jal         0x800179B0
    // 0x80150708: addiu       $a0, $a0, 0x26E0
    ctx->r4 = ADD32(ctx->r4, 0X26E0);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_1;
    // 0x80150708: addiu       $a0, $a0, 0x26E0
    ctx->r4 = ADD32(ctx->r4, 0X26E0);
    after_1:
    // 0x8015070C: jal         0x8012FFC0
    // 0x80150710: nop

    LOOKUP_FUNC(0x8012FFC0)(rdram, ctx);
        goto after_2;
    // 0x80150710: nop

    after_2:
    // 0x80150714: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80150718: addiu       $a1, $a1, 0x734
    ctx->r5 = ADD32(ctx->r5, 0X734);
    // 0x8015071C: jal         0x800058DC
    // 0x80150720: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80150720: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80150724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015072C: jr          $ra
    // 0x80150730: nop

    return;
    // 0x80150730: nop

;}
RECOMP_FUNC void M7_FUN_80150734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80150738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015073C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80150740: jal         0x800178E8
    // 0x80150744: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x80150744: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80150748: beql        $v0, $zero, L_80150788
    if (ctx->r2 == 0) {
        // 0x8015074C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80150788;
    }
    goto skip_0;
    // 0x8015074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80150750: jal         0x8012FFC0
    // 0x80150754: nop

    LOOKUP_FUNC(0x8012FFC0)(rdram, ctx);
        goto after_1;
    // 0x80150754: nop

    after_1:
    // 0x80150758: bne         $v0, $zero, L_80150778
    if (ctx->r2 != 0) {
        // 0x8015075C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80150778;
    }
    // 0x8015075C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80150760: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80150764: addiu       $a1, $a1, 0xBAC
    ctx->r5 = ADD32(ctx->r5, 0XBAC);
    // 0x80150768: jal         0x800058DC
    // 0x8015076C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8015076C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80150770: b           L_80150788
    // 0x80150774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80150788;
    // 0x80150774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80150778:
    // 0x80150778: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8015077C: jal         0x800058DC
    // 0x80150780: addiu       $a1, $a1, 0x794
    ctx->r5 = ADD32(ctx->r5, 0X794);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80150780: addiu       $a1, $a1, 0x794
    ctx->r5 = ADD32(ctx->r5, 0X794);
    after_3:
    // 0x80150784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80150788:
    // 0x80150788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015078C: jr          $ra
    // 0x80150790: nop

    return;
    // 0x80150790: nop

;}
RECOMP_FUNC void M7_FUN_80150794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150794: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80150798: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015079C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801507A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801507A4: jal         0x800178E8
    // 0x801507A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x801507A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801507AC: beql        $v0, $zero, L_80150960
    if (ctx->r2 == 0) {
        // 0x801507B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80150960;
    }
    goto skip_0;
    // 0x801507B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801507B4: lbu         $t6, 0x92($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X92);
    // 0x801507B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801507BC: bnel        $t6, $at, L_801507D8
    if (ctx->r14 != ctx->r1) {
        // 0x801507C0: lw          $t9, 0x24($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X24);
            goto L_801507D8;
    }
    goto skip_1;
    // 0x801507C0: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    skip_1:
    // 0x801507C4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801507C8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801507CC: b           L_801507F8
    // 0x801507D0: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
        goto L_801507F8;
    // 0x801507D0: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    // 0x801507D4: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
L_801507D8:
    // 0x801507D8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801507DC: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    // 0x801507E0: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x801507E4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801507E8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801507EC: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x801507F0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801507F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_801507F8:
    // 0x801507F8: jal         0x8001EAD0
    // 0x801507FC: sh          $a0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801507FC: sh          $a0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r4;
    after_1:
    // 0x80150800: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    // 0x80150804: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80150808: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8015080C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80150810: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80150814: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80150818: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8015081C: lhu         $t3, 0x2958($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X2958);
    // 0x80150820: lh          $a0, 0x26($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X26);
    // 0x80150824: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80150828: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8015082C: bgez        $t3, L_80150840
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80150830: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80150840;
    }
    // 0x80150830: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80150834: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80150838: nop

    // 0x8015083C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80150840:
    // 0x80150840: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80150844: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80150848: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8015084C: lui         $at, 0x4004
    ctx->r1 = S32(0X4004 << 16);
    // 0x80150850: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80150854: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80150858: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015085C: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x80150860: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80150864: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80150868: add.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d + ctx->f4.d;
    // 0x8015086C: lwc1        $f16, 0x4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80150870: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x80150874: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80150878: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8015087C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80150880: jal         0x8001EB64
    // 0x80150884: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x80150884: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80150888: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x8015088C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80150890: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80150894: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80150898: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8015089C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801508A0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801508A4: lhu         $t8, 0x2958($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X2958);
    // 0x801508A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801508AC: addiu       $t1, $zero, 0x1100
    ctx->r9 = ADD32(0, 0X1100);
    // 0x801508B0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801508B4: bgez        $t8, L_801508C8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801508B8: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801508C8;
    }
    // 0x801508B8: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801508BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801508C0: nop

    // 0x801508C4: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_801508C8:
    // 0x801508C8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801508CC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801508D0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801508D4: lui         $at, 0x4004
    ctx->r1 = S32(0X4004 << 16);
    // 0x801508D8: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x801508DC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801508E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801508E4: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801508E8: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x801508EC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801508F0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801508F4: lui         $t2, 0x168
    ctx->r10 = S32(0X168 << 16);
    // 0x801508F8: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x801508FC: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80150900: ori         $t2, $t2, 0x3
    ctx->r10 = ctx->r10 | 0X3;
    // 0x80150904: addiu       $t3, $zero, 0x5A
    ctx->r11 = ADD32(0, 0X5A);
    // 0x80150908: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8015090C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80150910: lwc1        $f16, 0x6EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6EC);
    // 0x80150914: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80150918: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015091C: sh          $t1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r9;
    // 0x80150920: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80150924: sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    // 0x80150928: add.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f18.d + ctx->f8.d;
    // 0x8015092C: sh          $t3, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r11;
    // 0x80150930: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80150934: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80150938: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8015093C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80150940: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80150944: jal         0x801C2F0C
    // 0x80150948: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_3;
    // 0x80150948: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8015094C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80150950: addiu       $a1, $a1, 0x970
    ctx->r5 = ADD32(ctx->r5, 0X970);
    // 0x80150954: jal         0x800058DC
    // 0x80150958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80150958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8015095C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80150960:
    // 0x80150960: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80150964: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80150968: jr          $ra
    // 0x8015096C: nop

    return;
    // 0x8015096C: nop

;}
RECOMP_FUNC void M7_FUN_80150970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150970: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80150974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150978: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8015097C: jal         0x801C3044
    // 0x80150980: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C3044)(rdram, ctx);
        goto after_0;
    // 0x80150980: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80150984: bne         $v0, $zero, L_801509C8
    if (ctx->r2 != 0) {
        // 0x80150988: lui         $t6, 0x168
        ctx->r14 = S32(0X168 << 16);
            goto L_801509C8;
    }
    // 0x80150988: lui         $t6, 0x168
    ctx->r14 = S32(0X168 << 16);
    // 0x8015098C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80150990: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80150994: ori         $t6, $t6, 0x2D
    ctx->r14 = ctx->r14 | 0X2D;
    // 0x80150998: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8015099C: sh          $zero, 0x18($sp)
    MEM_H(0X18, ctx->r29) = 0;
    // 0x801509A0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x801509A4: sh          $t7, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r15;
    // 0x801509A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801509AC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801509B0: jal         0x801C2F0C
    // 0x801509B4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_1;
    // 0x801509B4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801509B8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801509BC: addiu       $a1, $a1, 0x9D8
    ctx->r5 = ADD32(ctx->r5, 0X9D8);
    // 0x801509C0: jal         0x800058DC
    // 0x801509C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801509C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
L_801509C8:
    // 0x801509C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801509CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801509D0: jr          $ra
    // 0x801509D4: nop

    return;
    // 0x801509D4: nop

;}
RECOMP_FUNC void M7_FUN_801509d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801509D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801509DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801509E0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801509E4: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801509E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801509EC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801509F0: bne         $t6, $at, L_80150A20
    if (ctx->r14 != ctx->r1) {
        // 0x801509F4: lui         $t1, 0x801C
        ctx->r9 = S32(0X801C << 16);
            goto L_80150A20;
    }
    // 0x801509F4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801509F8: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801509FC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80150A00: lh          $a1, 0x12($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X12);
    // 0x80150A04: addiu       $a1, $a1, 0x1000
    ctx->r5 = ADD32(ctx->r5, 0X1000);
    // 0x80150A08: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80150A0C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80150A10: andi        $a1, $a1, 0x1FFF
    ctx->r5 = ctx->r5 & 0X1FFF;
    // 0x80150A14: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80150A18: b           L_80150A2C
    // 0x80150A1C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
        goto L_80150A2C;
    // 0x80150A1C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_80150A20:
    // 0x80150A20: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x80150A24: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80150A28: lh          $a1, 0x12($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X12);
L_80150A2C:
    // 0x80150A2C: lw          $t1, -0x4330($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4330);
    // 0x80150A30: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80150A34: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80150A38: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x80150A3C: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    // 0x80150A40: jal         0x801FD284
    // 0x80150A44: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801FD284)(rdram, ctx);
        goto after_0;
    // 0x80150A44: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_0:
    // 0x80150A48: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80150A4C: lw          $t3, -0x4330($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4330);
    // 0x80150A50: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x80150A54: jal         0x801C3044
    // 0x80150A58: sh          $v0, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r2;
    LOOKUP_FUNC(0x801C3044)(rdram, ctx);
        goto after_1;
    // 0x80150A58: sh          $v0, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r2;
    after_1:
    // 0x80150A5C: bne         $v0, $zero, L_80150AA4
    if (ctx->r2 != 0) {
        // 0x80150A60: lw          $a3, 0x40($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X40);
            goto L_80150AA4;
    }
    // 0x80150A60: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80150A64: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80150A68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80150A6C: lui         $t6, 0x168
    ctx->r14 = S32(0X168 << 16);
    // 0x80150A70: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x80150A74: ori         $t6, $t6, 0x2D
    ctx->r14 = ctx->r14 | 0X2D;
    // 0x80150A78: sh          $t5, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r13;
    // 0x80150A7C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80150A80: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80150A84: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80150A88: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80150A8C: jal         0x801C2F0C
    // 0x80150A90: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_2;
    // 0x80150A90: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80150A94: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80150A98: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80150A9C: jal         0x800058DC
    // 0x80150AA0: addiu       $a1, $a1, 0xAB4
    ctx->r5 = ADD32(ctx->r5, 0XAB4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80150AA0: addiu       $a1, $a1, 0xAB4
    ctx->r5 = ADD32(ctx->r5, 0XAB4);
    after_3:
L_80150AA4:
    // 0x80150AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150AA8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80150AAC: jr          $ra
    // 0x80150AB0: nop

    return;
    // 0x80150AB0: nop

;}
RECOMP_FUNC void M7_FUN_80150ab4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150AB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80150AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150ABC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80150AC0: jal         0x801C3044
    // 0x80150AC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C3044)(rdram, ctx);
        goto after_0;
    // 0x80150AC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80150AC8: bnel        $v0, $zero, L_80150B24
    if (ctx->r2 != 0) {
        // 0x80150ACC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80150B24;
    }
    goto skip_0;
    // 0x80150ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80150AD0: jal         0x80020718
    // 0x80150AD4: addiu       $a0, $zero, 0x3DE
    ctx->r4 = ADD32(0, 0X3DE);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_1;
    // 0x80150AD4: addiu       $a0, $zero, 0x3DE
    ctx->r4 = ADD32(0, 0X3DE);
    after_1:
    // 0x80150AD8: jal         0x8012FFC0
    // 0x80150ADC: nop

    LOOKUP_FUNC(0x8012FFC0)(rdram, ctx);
        goto after_2;
    // 0x80150ADC: nop

    after_2:
    // 0x80150AE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80150AE4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80150AE8: lbu         $t6, 0xA6($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XA6);
    // 0x80150AEC: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80150AF0: bne         $at, $zero, L_80150B18
    if (ctx->r1 != 0) {
        // 0x80150AF4: nop
    
            goto L_80150B18;
    }
    // 0x80150AF4: nop

    // 0x80150AF8: jal         0x801C3B5C
    // 0x80150AFC: nop

    LOOKUP_FUNC(0x801C3B5C)(rdram, ctx);
        goto after_3;
    // 0x80150AFC: nop

    after_3:
    // 0x80150B00: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80150B04: addiu       $a1, $a1, -0x3260
    ctx->r5 = ADD32(ctx->r5, -0X3260);
    // 0x80150B08: jal         0x800058DC
    // 0x80150B0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80150B0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80150B10: b           L_80150B24
    // 0x80150B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80150B24;
    // 0x80150B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80150B18:
    // 0x80150B18: jal         0x800058DC
    // 0x80150B1C: addiu       $a1, $a1, 0xB30
    ctx->r5 = ADD32(ctx->r5, 0XB30);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80150B1C: addiu       $a1, $a1, 0xB30
    ctx->r5 = ADD32(ctx->r5, 0XB30);
    after_5:
    // 0x80150B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80150B24:
    // 0x80150B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80150B28: jr          $ra
    // 0x80150B2C: nop

    return;
    // 0x80150B2C: nop

;}
RECOMP_FUNC void M7_FUN_80150b30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80150B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150B38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80150B3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80150B40: jal         0x80020718
    // 0x80150B44: addiu       $a0, $zero, 0x3DD
    ctx->r4 = ADD32(0, 0X3DD);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x80150B44: addiu       $a0, $zero, 0x3DD
    ctx->r4 = ADD32(0, 0X3DD);
    after_0:
    // 0x80150B48: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80150B4C: jal         0x800179B0
    // 0x80150B50: addiu       $a0, $a0, 0x2734
    ctx->r4 = ADD32(ctx->r4, 0X2734);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_1;
    // 0x80150B50: addiu       $a0, $a0, 0x2734
    ctx->r4 = ADD32(ctx->r4, 0X2734);
    after_1:
    // 0x80150B54: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80150B58: addiu       $a1, $a1, 0xB74
    ctx->r5 = ADD32(ctx->r5, 0XB74);
    // 0x80150B5C: jal         0x800058DC
    // 0x80150B60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80150B60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80150B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150B68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80150B6C: jr          $ra
    // 0x80150B70: nop

    return;
    // 0x80150B70: nop

;}
RECOMP_FUNC void M7_FUN_80150b74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150B74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80150B78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150B7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80150B80: jal         0x800178E8
    // 0x80150B84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x80150B84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80150B88: beq         $v0, $zero, L_80150B9C
    if (ctx->r2 == 0) {
        // 0x80150B8C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80150B9C;
    }
    // 0x80150B8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80150B90: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80150B94: jal         0x800058DC
    // 0x80150B98: addiu       $a1, $a1, 0xBAC
    ctx->r5 = ADD32(ctx->r5, 0XBAC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80150B98: addiu       $a1, $a1, 0xBAC
    ctx->r5 = ADD32(ctx->r5, 0XBAC);
    after_1:
L_80150B9C:
    // 0x80150B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150BA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80150BA4: jr          $ra
    // 0x80150BA8: nop

    return;
    // 0x80150BA8: nop

;}
RECOMP_FUNC void M7_FUN_80150bac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150BAC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80150BB0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80150BB4: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x80150BB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150BBC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80150BC0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80150BC4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80150BC8: jal         0x8001EAD0
    // 0x80150BCC: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80150BCC: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_0:
    // 0x80150BD0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80150BD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80150BD8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80150BDC: lw          $v0, -0x4330($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4330);
    // 0x80150BE0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80150BE4: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x80150BE8: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80150BEC: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80150BF0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80150BF4: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x80150BF8: jal         0x8001EB64
    // 0x80150BFC: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80150BFC: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_1:
    // 0x80150C00: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80150C04: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80150C08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80150C0C: lw          $t0, -0x4330($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4330);
    // 0x80150C10: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80150C14: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80150C18: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80150C1C: lwc1        $f8, 0x6F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6F0);
    // 0x80150C20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80150C24: lwc1        $f16, 0xC($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80150C28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80150C2C: lui         $t3, 0x168
    ctx->r11 = S32(0X168 << 16);
    // 0x80150C30: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80150C34: addiu       $t2, $zero, 0x1102
    ctx->r10 = ADD32(0, 0X1102);
    // 0x80150C38: ori         $t3, $t3, 0x3
    ctx->r11 = ctx->r11 | 0X3;
    // 0x80150C3C: addiu       $t4, $zero, 0x1000
    ctx->r12 = ADD32(0, 0X1000);
    // 0x80150C40: addiu       $t5, $zero, 0x5A
    ctx->r13 = ADD32(0, 0X5A);
    // 0x80150C44: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80150C48: sh          $t2, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r10;
    // 0x80150C4C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80150C50: sh          $t4, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r12;
    // 0x80150C54: sh          $t5, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r13;
    // 0x80150C58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80150C5C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80150C60: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80150C64: jal         0x801C2F0C
    // 0x80150C68: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_2;
    // 0x80150C68: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80150C6C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80150C70: addiu       $a1, $a1, 0xC8C
    ctx->r5 = ADD32(ctx->r5, 0XC8C);
    // 0x80150C74: jal         0x800058DC
    // 0x80150C78: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80150C78: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x80150C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150C80: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80150C84: jr          $ra
    // 0x80150C88: nop

    return;
    // 0x80150C88: nop

;}
RECOMP_FUNC void M7_FUN_80150c8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150C8C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80150C90: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80150C94: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80150C98: jal         0x801C3044
    // 0x80150C9C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C3044)(rdram, ctx);
        goto after_0;
    // 0x80150C9C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x80150CA0: bne         $v0, $zero, L_80150D5C
    if (ctx->r2 != 0) {
        // 0x80150CA4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80150D5C;
    }
    // 0x80150CA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80150CA8: jal         0x801C2F0C
    // 0x80150CAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_1;
    // 0x80150CAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80150CB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80150CB4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80150CB8: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x80150CBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80150CC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80150CC4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80150CC8: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x80150CCC: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80150CD0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80150CD4: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80150CD8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80150CDC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80150CE0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80150CE4: lwc1        $f6, 0x34($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80150CE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80150CEC: addiu       $a0, $a0, 0x634
    ctx->r4 = ADD32(ctx->r4, 0X634);
    // 0x80150CF0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80150CF4: lwc1        $f8, 0x38($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80150CF8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80150CFC: addiu       $a1, $zero, 0xA20
    ctx->r5 = ADD32(0, 0XA20);
    // 0x80150D00: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80150D04: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80150D08: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80150D0C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80150D10: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80150D14: lwc1        $f16, 0x40($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80150D18: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80150D1C: lwc1        $f18, 0x44($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80150D20: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80150D24: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80150D28: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80150D2C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80150D30: jal         0x8011AAF4
    // 0x80150D34: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_2;
    // 0x80150D34: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80150D38: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80150D3C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80150D40: lbu         $t0, 0x435($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X435);
    // 0x80150D44: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80150D48: addiu       $a1, $a1, -0x38D4
    ctx->r5 = ADD32(ctx->r5, -0X38D4);
    // 0x80150D4C: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x80150D50: sb          $t1, 0x435($v1)
    MEM_B(0X435, ctx->r3) = ctx->r9;
    // 0x80150D54: jal         0x800058DC
    // 0x80150D58: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80150D58: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_3:
L_80150D5C:
    // 0x80150D5C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80150D60: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80150D64: jr          $ra
    // 0x80150D68: nop

    return;
    // 0x80150D68: nop

;}
RECOMP_FUNC void M7_FUN_80150d6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150D6C: nop

;}
RECOMP_FUNC void M7_FUN_80150d70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150D70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80150D74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80150D78: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80150D7C: jal         0x8001F74C
    // 0x80150D80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_0;
    // 0x80150D80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80150D84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80150D88: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80150D8C: addiu       $t6, $t6, 0xDB4
    ctx->r14 = ADD32(ctx->r14, 0XDB4);
    // 0x80150D90: lhu         $a1, 0x92($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X92);
    // 0x80150D94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80150D98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80150D9C: jal         0x8013B570
    // 0x80150DA0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_1;
    // 0x80150DA0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80150DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80150DA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80150DAC: jr          $ra
    // 0x80150DB0: nop

    return;
    // 0x80150DB0: nop

;}
RECOMP_FUNC void M7_FUN_80150db4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150DB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80150DB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150DBC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80150DC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80150DC4: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x80150DC8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80150DCC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80150DD0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80150DD4: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x80150DD8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80150DDC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80150DE0: swc1        $f0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f0.u32l;
    // 0x80150DE4: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80150DE8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80150DEC: swc1        $f0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f0.u32l;
    // 0x80150DF0: sb          $zero, 0x90($a0)
    MEM_B(0X90, ctx->r4) = 0;
    // 0x80150DF4: sb          $zero, 0x91($a0)
    MEM_B(0X91, ctx->r4) = 0;
    // 0x80150DF8: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x80150DFC: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x80150E00: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x80150E04: lhu         $t2, 0xC($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0XC);
    // 0x80150E08: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80150E0C: blez        $t2, L_80150E40
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80150E10: nop
    
            goto L_80150E40;
    }
    // 0x80150E10: nop

    // 0x80150E14: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
L_80150E18:
    // 0x80150E18: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80150E1C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80150E20: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x80150E24: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x80150E28: ori         $t5, $t4, 0x100
    ctx->r13 = ctx->r12 | 0X100;
    // 0x80150E2C: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x80150E30: lhu         $t6, 0xC($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0XC);
    // 0x80150E34: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80150E38: bnel        $at, $zero, L_80150E18
    if (ctx->r1 != 0) {
        // 0x80150E3C: lw          $t3, 0x0($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X0);
            goto L_80150E18;
    }
    goto skip_0;
    // 0x80150E3C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    skip_0:
L_80150E40:
    // 0x80150E40: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80150E44: addiu       $a1, $a1, 0xE60
    ctx->r5 = ADD32(ctx->r5, 0XE60);
    // 0x80150E48: jal         0x800058DC
    // 0x80150E4C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80150E4C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80150E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150E54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80150E58: jr          $ra
    // 0x80150E5C: nop

    return;
    // 0x80150E5C: nop

;}
RECOMP_FUNC void M7_FUN_80150e60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80150E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150E68: lbu         $t6, 0x91($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X91);
    // 0x80150E6C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80150E70: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80150E74: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80150E78: lw          $v0, 0x32F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X32F0);
    // 0x80150E7C: beql        $v0, $zero, L_80150E9C
    if (ctx->r2 == 0) {
        // 0x80150E80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80150E9C;
    }
    goto skip_0;
    // 0x80150E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80150E84: jalr        $v0
    // 0x80150E88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80150E88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80150E8C: bne         $v0, $zero, L_80150E98
    if (ctx->r2 != 0) {
        // 0x80150E90: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80150E98;
    }
    // 0x80150E90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80150E94: sb          $zero, 0x91($a0)
    MEM_B(0X91, ctx->r4) = 0;
L_80150E98:
    // 0x80150E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80150E9C:
    // 0x80150E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80150EA0: jr          $ra
    // 0x80150EA4: nop

    return;
    // 0x80150EA4: nop

;}
RECOMP_FUNC void M7_FUN_80150ea8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150EA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80150EAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150EB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80150EB4: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80150EB8: slti        $v1, $v0, 0x1E
    ctx->r3 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x80150EBC: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80150EC0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80150EC4: beq         $v1, $zero, L_80150ED4
    if (ctx->r3 == 0) {
        // 0x80150EC8: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_80150ED4;
    }
    // 0x80150EC8: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80150ECC: jal         0x80005700
    // 0x80150ED0: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80150ED0: nop

    after_0:
L_80150ED4:
    // 0x80150ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150ED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80150EDC: jr          $ra
    // 0x80150EE0: nop

    return;
    // 0x80150EE0: nop

;}
RECOMP_FUNC void M7_FUN_80150ee4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150EE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80150EE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80150EEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80150EF0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80150EF4: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x80150EF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80150EFC: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80150F00: beql        $t7, $zero, L_80150F48
    if (ctx->r15 == 0) {
        // 0x80150F04: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80150F48;
    }
    goto skip_0;
    // 0x80150F04: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80150F08: lw          $t9, 0x98($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X98);
    // 0x80150F0C: lui         $t0, 0xFF
    ctx->r8 = S32(0XFF << 16);
    // 0x80150F10: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x80150F14: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80150F18: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x80150F1C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80150F20: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80150F24: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80150F28: lw          $a3, 0xA0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XA0);
    // 0x80150F2C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80150F30: jal         0x8013A1B4
    // 0x80150F34: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_0;
    // 0x80150F34: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x80150F38: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    // 0x80150F3C: andi        $t2, $t1, 0xFFFD
    ctx->r10 = ctx->r9 & 0XFFFD;
    // 0x80150F40: sb          $t2, 0x90($s0)
    MEM_B(0X90, ctx->r16) = ctx->r10;
    // 0x80150F44: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80150F48:
    // 0x80150F48: jal         0x80010550
    // 0x80150F4C: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x80150F4C: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_1:
    // 0x80150F50: beql        $v0, $zero, L_80150F68
    if (ctx->r2 == 0) {
        // 0x80150F54: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80150F68;
    }
    goto skip_1;
    // 0x80150F54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80150F58: sb          $zero, 0x91($s0)
    MEM_B(0X91, ctx->r16) = 0;
    // 0x80150F5C: b           L_80150F68
    // 0x80150F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80150F68;
    // 0x80150F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80150F64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80150F68:
    // 0x80150F68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80150F6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80150F70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80150F74: jr          $ra
    // 0x80150F78: nop

    return;
    // 0x80150F78: nop

;}
RECOMP_FUNC void M7_FUN_80150f7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150F7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80150F80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80150F84: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80150F88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80150F8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80150F90: lw          $t8, 0x98($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X98);
    // 0x80150F94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80150F98: lw          $a1, 0x5C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X5C);
    // 0x80150F9C: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x80150FA0: lw          $a3, 0x9C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X9C);
    // 0x80150FA4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80150FA8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80150FAC: lw          $t8, 0xA0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XA0);
    // 0x80150FB0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80150FB4: lhu         $t9, 0x94($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X94);
    // 0x80150FB8: jal         0x80011140
    // 0x80150FBC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x80150FBC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x80150FC0: beq         $v0, $zero, L_80150FD4
    if (ctx->r2 == 0) {
        // 0x80150FC4: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_80150FD4;
    }
    // 0x80150FC4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80150FC8: sb          $zero, 0x91($t0)
    MEM_B(0X91, ctx->r8) = 0;
    // 0x80150FCC: b           L_80150FD8
    // 0x80150FD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80150FD8;
    // 0x80150FD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80150FD4:
    // 0x80150FD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80150FD8:
    // 0x80150FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80150FDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80150FE0: jr          $ra
    // 0x80150FE4: nop

    return;
    // 0x80150FE4: nop

;}
RECOMP_FUNC void M7_FUN_80150fe8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150FE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80150FEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80150FF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80150FF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80150FF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80150FFC: lw          $t7, 0x98($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X98);
    // 0x80151000: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80151004: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x80151008: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8015100C: lw          $a3, 0x9C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X9C);
    // 0x80151010: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80151014: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80151018: lw          $t7, 0xA0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XA0);
    // 0x8015101C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80151020: lhu         $t8, 0x94($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X94);
    // 0x80151024: jal         0x80011140
    // 0x80151028: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x80151028: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x8015102C: beql        $v0, $zero, L_8015104C
    if (ctx->r2 == 0) {
        // 0x80151030: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8015104C;
    }
    goto skip_0;
    // 0x80151030: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80151034: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x80151038: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8015103C: sb          $t1, 0x91($s0)
    MEM_B(0X91, ctx->r16) = ctx->r9;
    // 0x80151040: ori         $t0, $t9, 0x2
    ctx->r8 = ctx->r25 | 0X2;
    // 0x80151044: sb          $t0, 0x90($s0)
    MEM_B(0X90, ctx->r16) = ctx->r8;
    // 0x80151048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8015104C:
    // 0x8015104C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80151050: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80151054: jr          $ra
    // 0x80151058: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80151058: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8015105c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8015105c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015105C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80151060: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80151064: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80151068: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8015106C: addiu       $t6, $t6, 0x3300
    ctx->r14 = ADD32(ctx->r14, 0X3300);
    // 0x80151070: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80151074: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80151078: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8015107C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80151080: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80151084: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80151088: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x8015108C: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80151090: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80151094: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80151098: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x8015109C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801510A0: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801510A4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801510A8: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801510AC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801510B0: jal         0x8012C4D0
    // 0x801510B4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x801510B4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x801510B8: beq         $v0, $zero, L_80151100
    if (ctx->r2 == 0) {
        // 0x801510BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80151100;
    }
    // 0x801510BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801510C0: jal         0x8001F790
    // 0x801510C4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001F790)(rdram, ctx);
        goto after_1;
    // 0x801510C4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x801510C8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x801510CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801510D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801510D4: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x801510D8: sb          $t2, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r10;
    // 0x801510DC: sb          $zero, 0x91($v0)
    MEM_B(0X91, ctx->r2) = 0;
    // 0x801510E0: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x801510E4: sw          $t1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r9;
    // 0x801510E8: lhu         $t3, 0x32($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X32);
    // 0x801510EC: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x801510F0: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x801510F4: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x801510F8: b           L_80151104
    // 0x801510FC: sh          $t3, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r11;
        goto L_80151104;
    // 0x801510FC: sh          $t3, 0x92($v0)
    MEM_H(0X92, ctx->r2) = ctx->r11;
L_80151100:
    // 0x80151100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151104:
    // 0x80151104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80151108: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8015110C: jr          $ra
    // 0x80151110: nop

    return;
    // 0x80151110: nop

;}
RECOMP_FUNC void M7_FUN_80151114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151118: beq         $a0, $zero, L_80151148
    if (ctx->r4 == 0) {
        // 0x8015111C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80151148;
    }
    // 0x8015111C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151120: jal         0x8001F7B0
    // 0x80151124: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001F7B0)(rdram, ctx);
        goto after_0;
    // 0x80151124: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151128: beq         $v0, $zero, L_80151148
    if (ctx->r2 == 0) {
        // 0x8015112C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80151148;
    }
    // 0x8015112C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80151130: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80151134: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    // 0x80151138: jal         0x800058DC
    // 0x8015113C: addiu       $a1, $a1, 0xEA8
    ctx->r5 = ADD32(ctx->r5, 0XEA8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8015113C: addiu       $a1, $a1, 0xEA8
    ctx->r5 = ADD32(ctx->r5, 0XEA8);
    after_1:
    // 0x80151140: b           L_8015114C
    // 0x80151144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8015114C;
    // 0x80151144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80151148:
    // 0x80151148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015114C:
    // 0x8015114C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151154: jr          $ra
    // 0x80151158: nop

    return;
    // 0x80151158: nop

;}
RECOMP_FUNC void M7_FUN_8015115c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015115C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151164: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80151168: jal         0x801517CC
    // 0x8015116C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x8015116C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151170: beq         $v0, $zero, L_801511B0
    if (ctx->r2 == 0) {
        // 0x80151174: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801511B0;
    }
    // 0x80151174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80151178: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x8015117C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80151180: sb          $t8, 0x91($a0)
    MEM_B(0X91, ctx->r4) = ctx->r24;
    // 0x80151184: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80151188: sb          $t7, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r15;
    // 0x8015118C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80151190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80151194: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80151198: sw          $t1, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->r9;
    // 0x8015119C: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801511A0: sw          $t0, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->r8;
    // 0x801511A4: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801511A8: b           L_801511B4
    // 0x801511AC: sw          $t1, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->r9;
        goto L_801511B4;
    // 0x801511AC: sw          $t1, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->r9;
L_801511B0:
    // 0x801511B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801511B4:
    // 0x801511B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801511B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801511BC: jr          $ra
    // 0x801511C0: nop

    return;
    // 0x801511C0: nop

;}
RECOMP_FUNC void M7_FUN_801511c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801511C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801511C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801511CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801511D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801511D4: jal         0x801517CC
    // 0x801511D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x801511D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801511DC: beq         $v0, $zero, L_80151218
    if (ctx->r2 == 0) {
        // 0x801511E0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80151218;
    }
    // 0x801511E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801511E4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801511E8: sb          $t6, 0x91($a0)
    MEM_B(0X91, ctx->r4) = ctx->r14;
    // 0x801511EC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801511F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801511F4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801511F8: sw          $t9, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->r25;
    // 0x801511FC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80151200: sw          $t8, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->r24;
    // 0x80151204: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80151208: sw          $t9, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->r25;
    // 0x8015120C: lhu         $t0, 0x22($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X22);
    // 0x80151210: b           L_8015121C
    // 0x80151214: sh          $t0, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r8;
        goto L_8015121C;
    // 0x80151214: sh          $t0, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r8;
L_80151218:
    // 0x80151218: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015121C:
    // 0x8015121C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151224: jr          $ra
    // 0x80151228: nop

    return;
    // 0x80151228: nop

;}
RECOMP_FUNC void M7_FUN_8015122c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015122C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151234: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80151238: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8015123C: jal         0x801517CC
    // 0x80151240: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x80151240: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151244: beq         $v0, $zero, L_80151280
    if (ctx->r2 == 0) {
        // 0x80151248: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80151280;
    }
    // 0x80151248: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8015124C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80151250: sb          $t6, 0x91($a0)
    MEM_B(0X91, ctx->r4) = ctx->r14;
    // 0x80151254: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80151258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8015125C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80151260: sw          $t9, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->r25;
    // 0x80151264: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80151268: sw          $t8, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->r24;
    // 0x8015126C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80151270: sw          $t9, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->r25;
    // 0x80151274: lhu         $t0, 0x22($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X22);
    // 0x80151278: b           L_80151284
    // 0x8015127C: sh          $t0, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r8;
        goto L_80151284;
    // 0x8015127C: sh          $t0, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r8;
L_80151280:
    // 0x80151280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151284:
    // 0x80151284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015128C: jr          $ra
    // 0x80151290: nop

    return;
    // 0x80151290: nop

;}
RECOMP_FUNC void M7_FUN_80151294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015129C: jal         0x801517CC
    // 0x801512A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x801512A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801512A4: beq         $v0, $zero, L_801512B8
    if (ctx->r2 == 0) {
        // 0x801512A8: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_801512B8;
    }
    // 0x801512A8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801512AC: sb          $zero, 0x91($t6)
    MEM_B(0X91, ctx->r14) = 0;
    // 0x801512B0: b           L_801512BC
    // 0x801512B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801512BC;
    // 0x801512B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801512B8:
    // 0x801512B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801512BC:
    // 0x801512BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801512C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801512C4: jr          $ra
    // 0x801512C8: nop

    return;
    // 0x801512C8: nop

;}
RECOMP_FUNC void M7_FUN_801512cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801512CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801512D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801512D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801512D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801512DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801512E0: jal         0x801517CC
    // 0x801512E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x801512E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801512E8: beq         $v0, $zero, L_80151328
    if (ctx->r2 == 0) {
        // 0x801512EC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80151328;
    }
    // 0x801512EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801512F0: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801512F4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801512F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801512FC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80151300: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x80151304: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80151308: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8015130C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80151310: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x80151314: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x80151318: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8015131C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80151320: b           L_8015132C
    // 0x80151324: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
        goto L_8015132C;
    // 0x80151324: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
L_80151328:
    // 0x80151328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015132C:
    // 0x8015132C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151330: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151334: jr          $ra
    // 0x80151338: nop

    return;
    // 0x80151338: nop

;}
RECOMP_FUNC void M7_FUN_8015133c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015133C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151340: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80151348: jal         0x801517CC
    // 0x8015134C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x8015134C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80151350: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80151354: beq         $v0, $zero, L_80151394
    if (ctx->r2 == 0) {
        // 0x80151358: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80151394;
    }
    // 0x80151358: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8015135C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80151360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80151364: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80151368: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8015136C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80151370: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80151374: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80151378: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8015137C: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x80151380: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x80151384: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80151388: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8015138C: b           L_80151398
    // 0x80151390: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
        goto L_80151398;
    // 0x80151390: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
L_80151394:
    // 0x80151394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151398:
    // 0x80151398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015139C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801513A0: jr          $ra
    // 0x801513A4: nop

    return;
    // 0x801513A4: nop

;}
RECOMP_FUNC void M7_FUN_801513a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801513A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801513AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801513B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801513B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801513B8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801513BC: jal         0x801517CC
    // 0x801513C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x801513C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801513C4: beq         $v0, $zero, L_8015141C
    if (ctx->r2 == 0) {
        // 0x801513C8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8015141C;
    }
    // 0x801513C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801513CC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801513D0: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801513D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801513D8: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801513DC: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801513E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801513E4: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x801513E8: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801513EC: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801513F0: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801513F4: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801513F8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801513FC: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x80151400: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80151404: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80151408: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x8015140C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80151410: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80151414: b           L_80151420
    // 0x80151418: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
        goto L_80151420;
    // 0x80151418: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
L_8015141C:
    // 0x8015141C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151420:
    // 0x80151420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151428: jr          $ra
    // 0x8015142C: nop

    return;
    // 0x8015142C: nop

;}
RECOMP_FUNC void M7_FUN_80151430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151438: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015143C: jal         0x801517CC
    // 0x80151440: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x80151440: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80151444: beq         $v0, $zero, L_80151464
    if (ctx->r2 == 0) {
        // 0x80151448: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80151464;
    }
    // 0x80151448: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8015144C: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80151450: lhu         $t6, 0x1E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1E);
    // 0x80151454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80151458: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8015145C: b           L_80151468
    // 0x80151460: sh          $t6, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r14;
        goto L_80151468;
    // 0x80151460: sh          $t6, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r14;
L_80151464:
    // 0x80151464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151468:
    // 0x80151468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015146C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151470: jr          $ra
    // 0x80151474: nop

    return;
    // 0x80151474: nop

;}
RECOMP_FUNC void M7_FUN_80151478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015147C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151480: jal         0x801517CC
    // 0x80151484: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x80151484: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151488: beq         $v0, $zero, L_801514A4
    if (ctx->r2 == 0) {
        // 0x8015148C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801514A4;
    }
    // 0x8015148C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151490: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80151494: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80151498: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8015149C: b           L_801514A8
    // 0x801514A0: lhu         $v0, 0x12($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X12);
        goto L_801514A8;
    // 0x801514A0: lhu         $v0, 0x12($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X12);
L_801514A4:
    // 0x801514A4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_801514A8:
    // 0x801514A8: jr          $ra
    // 0x801514AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801514AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801514b0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801514b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801514B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801514B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801514B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801514BC: jal         0x801517CC
    // 0x801514C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x801514C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801514C4: beq         $v0, $zero, L_801514F0
    if (ctx->r2 == 0) {
        // 0x801514C8: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_801514F0;
    }
    // 0x801514C8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801514CC: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801514D0: lh          $t9, 0x1E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X1E);
    // 0x801514D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801514D8: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801514DC: lh          $t8, 0x12($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X12);
    // 0x801514E0: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x801514E4: andi        $t3, $t2, 0x1FFF
    ctx->r11 = ctx->r10 & 0X1FFF;
    // 0x801514E8: b           L_801514F4
    // 0x801514EC: sh          $t3, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r11;
        goto L_801514F4;
    // 0x801514EC: sh          $t3, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r11;
L_801514F0:
    // 0x801514F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801514F4:
    // 0x801514F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801514F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801514FC: jr          $ra
    // 0x80151500: nop

    return;
    // 0x80151500: nop

;}
RECOMP_FUNC void M7_FUN_80151504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015150C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80151510: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80151514: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80151518: jal         0x801517CC
    // 0x8015151C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x8015151C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151520: beq         $v0, $zero, L_80151548
    if (ctx->r2 == 0) {
        // 0x80151524: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80151548;
    }
    // 0x80151524: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80151528: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8015152C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80151530: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x80151534: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80151538: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
    // 0x8015153C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80151540: b           L_8015154C
    // 0x80151544: swc1        $f8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f8.u32l;
        goto L_8015154C;
    // 0x80151544: swc1        $f8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f8.u32l;
L_80151548:
    // 0x80151548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015154C:
    // 0x8015154C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151550: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151554: jr          $ra
    // 0x80151558: nop

    return;
    // 0x80151558: nop

;}
RECOMP_FUNC void M7_FUN_8015155c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015155C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80151568: jal         0x801517CC
    // 0x8015156C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x8015156C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80151570: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80151574: beq         $v0, $zero, L_8015159C
    if (ctx->r2 == 0) {
        // 0x80151578: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8015159C;
    }
    // 0x80151578: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8015157C: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80151580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80151584: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80151588: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8015158C: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x80151590: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80151594: b           L_801515A0
    // 0x80151598: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
        goto L_801515A0;
    // 0x80151598: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
L_8015159C:
    // 0x8015159C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801515A0:
    // 0x801515A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801515A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801515A8: jr          $ra
    // 0x801515AC: nop

    return;
    // 0x801515AC: nop

;}
RECOMP_FUNC void M7_FUN_801515b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801515B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801515B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801515B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801515BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801515C0: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801515C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801515C8: jal         0x801517CC
    // 0x801515CC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x801515CC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801515D0: beq         $v0, $zero, L_8015162C
    if (ctx->r2 == 0) {
        // 0x801515D4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8015162C;
    }
    // 0x801515D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801515D8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x801515DC: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x801515E0: lhu         $t9, 0xC($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XC);
    // 0x801515E4: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801515E8: beql        $at, $zero, L_80151630
    if (ctx->r1 == 0) {
        // 0x801515EC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80151630;
    }
    goto skip_0;
    // 0x801515EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801515F0: jal         0x80006214
    // 0x801515F4: nop

    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801515F4: nop

    after_1:
    // 0x801515F8: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x801515FC: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80151600: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
    // 0x80151604: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80151608: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8015160C: lw          $t3, -0x2578($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2578);
    // 0x80151610: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80151614: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x80151618: sb          $t0, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r8;
    // 0x8015161C: jal         0x80006214
    // 0x80151620: lw          $a0, -0x2A2C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A2C);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x80151620: lw          $a0, -0x2A2C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A2C);
    after_2:
    // 0x80151624: b           L_80151630
    // 0x80151628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80151630;
    // 0x80151628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8015162C:
    // 0x8015162C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151630:
    // 0x80151630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151638: jr          $ra
    // 0x8015163C: nop

    return;
    // 0x8015163C: nop

;}
RECOMP_FUNC void M7_FUN_80151640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151640: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151648: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8015164C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80151650: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151654: jal         0x801517CC
    // 0x80151658: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x80151658: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015165C: beq         $v0, $zero, L_801516B8
    if (ctx->r2 == 0) {
        // 0x80151660: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801516B8;
    }
    // 0x80151660: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80151664: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80151668: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x8015166C: lhu         $t9, 0xC($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XC);
    // 0x80151670: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80151674: beql        $at, $zero, L_801516BC
    if (ctx->r1 == 0) {
        // 0x80151678: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_801516BC;
    }
    goto skip_0;
    // 0x80151678: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    skip_0:
    // 0x8015167C: jal         0x80006214
    // 0x80151680: nop

    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80151680: nop

    after_1:
    // 0x80151684: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x80151688: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8015168C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80151690: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80151694: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80151698: lw          $t2, -0x2578($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2578);
    // 0x8015169C: lw          $a0, -0x2A2C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A2C);
    // 0x801516A0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801516A4: lbu         $t4, 0x4B($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X4B);
    // 0x801516A8: jal         0x80006214
    // 0x801516AC: sb          $t4, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801516AC: sb          $t4, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r12;
    after_2:
    // 0x801516B0: b           L_801516BC
    // 0x801516B4: lbu         $v0, 0x1B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1B);
        goto L_801516BC;
    // 0x801516B4: lbu         $v0, 0x1B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1B);
L_801516B8:
    // 0x801516B8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_801516BC:
    // 0x801516BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801516C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801516C4: jr          $ra
    // 0x801516C8: nop

    return;
    // 0x801516C8: nop

;}
RECOMP_FUNC void M7_FUN_801516cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801516CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801516D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801516D4: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801516D8: jal         0x801517CC
    // 0x801516DC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801517CC)(rdram, ctx);
        goto after_0;
    // 0x801516DC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801516E0: beq         $v0, $zero, L_801516F4
    if (ctx->r2 == 0) {
        // 0x801516E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801516F4;
    }
    // 0x801516E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801516E8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801516EC: b           L_801516F8
    // 0x801516F0: lhu         $v0, 0xC($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0XC);
        goto L_801516F8;
    // 0x801516F0: lhu         $v0, 0xC($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0XC);
L_801516F4:
    // 0x801516F4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_801516F8:
    // 0x801516F8: jr          $ra
    // 0x801516FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801516FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80151700(rdram, ctx);
;}
