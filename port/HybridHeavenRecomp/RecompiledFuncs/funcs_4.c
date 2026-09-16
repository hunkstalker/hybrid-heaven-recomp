#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_8000ff80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FF80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000FF84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FF88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000FF8C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000FF90: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000FF94: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
    // 0x8000FF98: addiu       $a1, $zero, 0x240
    ctx->r5 = ADD32(0, 0X240);
    // 0x8000FF9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8000FFA0: jal         0x800279F0
    // 0x8000FFA4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_0;
    // 0x8000FFA4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000FFA8: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8000FFAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000FFB0: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8000FFB4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8000FFB8: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_8000FFBC:
    // 0x8000FFBC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000FFC0: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x8000FFC4: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x8000FFC8: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // 0x8000FFCC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8000FFD0: bne         $a0, $a1, L_8000FFBC
    if (ctx->r4 != ctx->r5) {
        // 0x8000FFD4: sh          $v0, -0x8($v1)
        MEM_H(-0X8, ctx->r3) = ctx->r2;
            goto L_8000FFBC;
    }
    // 0x8000FFD4: sh          $v0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r2;
    // 0x8000FFD8: addiu       $a0, $sp, 0x32
    ctx->r4 = ADD32(ctx->r29, 0X32);
    // 0x8000FFDC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8000FFE0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8000FFE4: jal         0x8000FCD0
    // 0x8000FFE8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8000FCD0)(rdram, ctx);
        goto after_1;
    // 0x8000FFE8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_1:
    // 0x8000FFEC: lhu         $a1, 0x3E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X3E);
    // 0x8000FFF0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8000FFF4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000FFF8: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x8000FFFC: bne         $at, $zero, L_80010054
    if (ctx->r1 != 0) {
        // 0x80010000: addiu       $a2, $a1, -0x1
        ctx->r6 = ADD32(ctx->r5, -0X1);
            goto L_80010054;
    }
    // 0x80010000: addiu       $a2, $a1, -0x1
    ctx->r6 = ADD32(ctx->r5, -0X1);
    // 0x80010004: andi        $a2, $a2, 0x3
    ctx->r6 = ctx->r6 & 0X3;
    // 0x80010008: beq         $a2, $zero, L_8001002C
    if (ctx->r6 == 0) {
        // 0x8001000C: addiu       $a0, $a2, 0x1
        ctx->r4 = ADD32(ctx->r6, 0X1);
            goto L_8001002C;
    }
    // 0x8001000C: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    // 0x80010010: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80010014: addu        $v0, $a3, $t6
    ctx->r2 = ADD32(ctx->r7, ctx->r14);
L_80010018:
    // 0x80010018: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001001C: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80010020: bne         $a0, $v1, L_80010018
    if (ctx->r4 != ctx->r3) {
        // 0x80010024: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_80010018;
    }
    // 0x80010024: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80010028: beq         $v1, $a1, L_80010054
    if (ctx->r3 == ctx->r5) {
        // 0x8001002C: sll         $t7, $v1, 1
        ctx->r15 = S32(ctx->r3 << 1);
            goto L_80010054;
    }
L_8001002C:
    // 0x8001002C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80010030: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x80010034: addu        $a0, $t8, $a3
    ctx->r4 = ADD32(ctx->r24, ctx->r7);
    // 0x80010038: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
L_8001003C:
    // 0x8001003C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80010040: sh          $zero, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = 0;
    // 0x80010044: sh          $zero, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = 0;
    // 0x80010048: sh          $zero, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = 0;
    // 0x8001004C: bne         $v0, $a0, L_8001003C
    if (ctx->r2 != ctx->r4) {
        // 0x80010050: sh          $zero, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = 0;
            goto L_8001003C;
    }
    // 0x80010050: sh          $zero, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = 0;
L_80010054:
    // 0x80010054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010058: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001005C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80010060: jr          $ra
    // 0x80010064: nop

    return;
    // 0x80010064: nop

;}
RECOMP_FUNC void FUN_80010068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010068: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001006C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80010070: lhu         $t6, 0x5A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X5A);
    // 0x80010074: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80010078: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001007C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80010080: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80010084: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80010088: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8001008C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80010090: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80010094: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80010098: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8001009C: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x800100A0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800100A4: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x800100A8: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x800100AC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800100B0: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x800100B4: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x800100B8: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
    // 0x800100BC: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x800100C0: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x800100C4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800100C8: jal         0x8000E748
    // 0x800100CC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8000E748)(rdram, ctx);
        goto after_0;
    // 0x800100CC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_0:
    // 0x800100D0: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800100D4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800100D8: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x800100DC: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800100E0: addiu       $t5, $sp, 0x48
    ctx->r13 = ADD32(ctx->r29, 0X48);
    // 0x800100E4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800100E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800100EC: bc1fl       L_80010100
    if (!c1cs) {
        // 0x800100F0: cfc1        $t9, $FpcCsr
        ctx->r25 = get_cop1_cs();
            goto L_80010100;
    }
    goto skip_0;
    // 0x800100F0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    skip_0:
    // 0x800100F4: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x800100F8: sh          $t4, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r12;
    // 0x800100FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_80010100:
    // 0x80010100: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80010104: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80010108: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001010C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80010110: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80010114: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80010118: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8001011C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80010120: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80010124: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80010128: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8001012C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80010130: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80010134: beq         $t0, $zero, L_80010180
    if (ctx->r8 == 0) {
        // 0x80010138: sw          $t7, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r15;
            goto L_80010180;
    }
    // 0x80010138: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8001013C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80010140: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80010144: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80010148: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8001014C: nop

    // 0x80010150: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80010154: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80010158: nop

    // 0x8001015C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80010160: bne         $t0, $zero, L_80010178
    if (ctx->r8 != 0) {
        // 0x80010164: nop
    
            goto L_80010178;
    }
    // 0x80010164: nop

    // 0x80010168: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8001016C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010170: b           L_80010190
    // 0x80010174: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80010190;
    // 0x80010174: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80010178:
    // 0x80010178: b           L_80010190
    // 0x8001017C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80010190;
    // 0x8001017C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_80010180:
    // 0x80010180: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80010184: nop

    // 0x80010188: bltz        $t0, L_80010178
    if (SIGNED(ctx->r8) < 0) {
        // 0x8001018C: nop
    
            goto L_80010178;
    }
    // 0x8001018C: nop

L_80010190:
    // 0x80010190: lhu         $t1, 0x62($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X62);
    // 0x80010194: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80010198: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8001019C: lhu         $t4, 0x5A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X5A);
    // 0x800101A0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800101A4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800101A8: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x800101AC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x800101B0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x800101B4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800101B8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800101BC: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800101C0: jal         0x8000EC9C
    // 0x800101C4: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8000EC9C)(rdram, ctx);
        goto after_1;
    // 0x800101C4: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    after_1:
    // 0x800101C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800101CC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800101D0: jr          $ra
    // 0x800101D4: nop

    return;
    // 0x800101D4: nop

;}
RECOMP_FUNC void FUN_800101d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800101D8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800101DC: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800101E0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800101E4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800101E8: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x800101EC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800101F0: addiu       $v0, $v0, 0x31F0
    ctx->r2 = ADD32(ctx->r2, 0X31F0);
    // 0x800101F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800101F8: addu        $t1, $v0, $t6
    ctx->r9 = ADD32(ctx->r2, ctx->r14);
    // 0x800101FC: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80010200: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80010204: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80010208: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8001020C: addiu       $t7, $sp, 0x60
    ctx->r15 = ADD32(ctx->r29, 0X60);
    // 0x80010210: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80010214: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
    // 0x80010218: lui         $t3, 0x8006
    ctx->r11 = S32(0X8006 << 16);
    // 0x8001021C: addiu       $t3, $t3, 0x3670
    ctx->r11 = ADD32(ctx->r11, 0X3670);
    // 0x80010220: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x80010224: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x80010228: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x8001022C: addiu       $t5, $sp, 0x52
    ctx->r13 = ADD32(ctx->r29, 0X52);
    // 0x80010230: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x80010234: lhu         $t4, 0x66($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X66);
    // 0x80010238: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8001023C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80010240: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80010244: addiu       $a3, $a3, 0x3DF0
    ctx->r7 = ADD32(ctx->r7, 0X3DF0);
    // 0x80010248: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
    // 0x8001024C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80010250: sh          $a0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r4;
    // 0x80010254: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80010258: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8001025C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80010260: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80010264: jal         0x80010068
    // 0x80010268: sh          $t4, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x80010068)(rdram, ctx);
        goto after_0;
    // 0x80010268: sh          $t4, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r12;
    after_0:
    // 0x8001026C: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    // 0x80010270: lui         $t3, 0x8006
    ctx->r11 = S32(0X8006 << 16);
    // 0x80010274: addiu       $t3, $t3, 0x3670
    ctx->r11 = ADD32(ctx->r11, 0X3670);
    // 0x80010278: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    // 0x8001027C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80010280: lhu         $t2, 0x4C($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X4C);
    // 0x80010284: beq         $t7, $zero, L_800102C0
    if (ctx->r15 == 0) {
        // 0x80010288: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_800102C0;
    }
    // 0x80010288: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x8001028C: lhu         $t8, 0x4($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X4);
    // 0x80010290: lhu         $t9, 0x50($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X50);
    // 0x80010294: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80010298: bnel        $at, $zero, L_80010398
    if (ctx->r1 != 0) {
        // 0x8001029C: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80010398;
    }
    goto skip_0;
    // 0x8001029C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    skip_0:
    // 0x800102A0: lhu         $t4, 0x52($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X52);
    // 0x800102A4: sh          $t9, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r25;
    // 0x800102A8: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x800102AC: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x800102B0: beql        $t5, $zero, L_80010398
    if (ctx->r13 == 0) {
        // 0x800102B4: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80010398;
    }
    goto skip_1;
    // 0x800102B4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    skip_1:
    // 0x800102B8: b           L_80010394
    // 0x800102BC: sh          $t7, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r15;
        goto L_80010394;
    // 0x800102BC: sh          $t7, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r15;
L_800102C0:
    // 0x800102C0: andi        $t8, $a0, 0x2
    ctx->r24 = ctx->r4 & 0X2;
    // 0x800102C4: beq         $t8, $zero, L_80010330
    if (ctx->r24 == 0) {
        // 0x800102C8: lhu         $t7, 0x50($sp)
        ctx->r15 = MEM_HU(ctx->r29, 0X50);
            goto L_80010330;
    }
    // 0x800102C8: lhu         $t7, 0x50($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X50);
    // 0x800102CC: lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X4);
    // 0x800102D0: andi        $t9, $a0, 0x300
    ctx->r25 = ctx->r4 & 0X300;
    // 0x800102D4: bgtz        $v1, L_80010328
    if (SIGNED(ctx->r3) > 0) {
        // 0x800102D8: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80010328;
    }
    // 0x800102D8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x800102DC: beql        $t9, $zero, L_80010320
    if (ctx->r25 == 0) {
        // 0x800102E0: sh          $zero, 0x4($t1)
        MEM_H(0X4, ctx->r9) = 0;
            goto L_80010320;
    }
    goto skip_2;
    // 0x800102E0: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
    skip_2:
    // 0x800102E4: lhu         $t5, 0x52($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X52);
    // 0x800102E8: lhu         $t4, 0x50($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X50);
    // 0x800102EC: andi        $t9, $a0, 0x200
    ctx->r25 = ctx->r4 & 0X200;
    // 0x800102F0: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x800102F4: beq         $t6, $zero, L_80010304
    if (ctx->r14 == 0) {
        // 0x800102F8: sh          $t4, 0x4($t1)
        MEM_H(0X4, ctx->r9) = ctx->r12;
            goto L_80010304;
    }
    // 0x800102F8: sh          $t4, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r12;
    // 0x800102FC: addiu       $t8, $t4, -0x1
    ctx->r24 = ADD32(ctx->r12, -0X1);
    // 0x80010300: sh          $t8, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r24;
L_80010304:
    // 0x80010304: beql        $t9, $zero, L_80010398
    if (ctx->r25 == 0) {
        // 0x80010308: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80010398;
    }
    goto skip_3;
    // 0x80010308: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    skip_3:
    // 0x8001030C: lhu         $t4, 0x6($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X6);
    // 0x80010310: xori        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 ^ 0X10;
    // 0x80010314: b           L_80010394
    // 0x80010318: sh          $t5, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r13;
        goto L_80010394;
    // 0x80010318: sh          $t5, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r13;
    // 0x8001031C: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
L_80010320:
    // 0x80010320: b           L_80010394
    // 0x80010324: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80010394;
    // 0x80010324: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80010328:
    // 0x80010328: b           L_80010394
    // 0x8001032C: sh          $t6, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r14;
        goto L_80010394;
    // 0x8001032C: sh          $t6, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r14;
L_80010330:
    // 0x80010330: lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X4);
    // 0x80010334: andi        $t8, $a0, 0x300
    ctx->r24 = ctx->r4 & 0X300;
    // 0x80010338: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001033C: bne         $at, $zero, L_80010390
    if (ctx->r1 != 0) {
        // 0x80010340: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_80010390;
    }
    // 0x80010340: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x80010344: beq         $t8, $zero, L_80010388
    if (ctx->r24 == 0) {
        // 0x80010348: sh          $t7, 0x4($t1)
        MEM_H(0X4, ctx->r9) = ctx->r15;
            goto L_80010388;
    }
    // 0x80010348: sh          $t7, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r15;
    // 0x8001034C: lhu         $t9, 0x52($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X52);
    // 0x80010350: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80010354: andi        $t6, $a0, 0x200
    ctx->r14 = ctx->r4 & 0X200;
    // 0x80010358: andi        $t4, $t9, 0x8000
    ctx->r12 = ctx->r25 & 0X8000;
    // 0x8001035C: beql        $t4, $zero, L_80010370
    if (ctx->r12 == 0) {
        // 0x80010360: sh          $zero, 0x4($t1)
        MEM_H(0X4, ctx->r9) = 0;
            goto L_80010370;
    }
    goto skip_4;
    // 0x80010360: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
    skip_4:
    // 0x80010364: b           L_80010370
    // 0x80010368: sh          $t5, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r13;
        goto L_80010370;
    // 0x80010368: sh          $t5, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r13;
    // 0x8001036C: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
L_80010370:
    // 0x80010370: beql        $t6, $zero, L_80010398
    if (ctx->r14 == 0) {
        // 0x80010374: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80010398;
    }
    goto skip_5;
    // 0x80010374: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    skip_5:
    // 0x80010378: lhu         $t7, 0x6($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X6);
    // 0x8001037C: xori        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 ^ 0X10;
    // 0x80010380: b           L_80010394
    // 0x80010384: sh          $t8, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r24;
        goto L_80010394;
    // 0x80010384: sh          $t8, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r24;
L_80010388:
    // 0x80010388: b           L_80010394
    // 0x8001038C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80010394;
    // 0x8001038C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80010390:
    // 0x80010390: sh          $t9, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r25;
L_80010394:
    // 0x80010394: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80010398:
    // 0x80010398: bne         $at, $zero, L_80010440
    if (ctx->r1 != 0) {
        // 0x8001039C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80010440;
    }
    // 0x8001039C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800103A0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800103A4: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x800103A8: addiu       $a1, $a1, 0x3DF2
    ctx->r5 = ADD32(ctx->r5, 0X3DF2);
    // 0x800103AC: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800103B0: lhu         $a3, 0x72($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X72);
L_800103B4:
    // 0x800103B4: lhu         $t4, 0x0($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0X0);
    // 0x800103B8: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x800103BC: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800103C0: bnel        $a3, $t4, L_80010438
    if (ctx->r7 != ctx->r12) {
        // 0x800103C4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80010438;
    }
    goto skip_6;
    // 0x800103C4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_6:
    // 0x800103C8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800103CC: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x800103D0: lw          $t8, 0x28($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X28);
    // 0x800103D4: beql        $t8, $zero, L_80010438
    if (ctx->r24 == 0) {
        // 0x800103D8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80010438;
    }
    goto skip_7;
    // 0x800103D8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_7:
    // 0x800103DC: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800103E0: mflo        $t9
    ctx->r25 = lo;
    // 0x800103E4: addu        $v0, $t3, $t9
    ctx->r2 = ADD32(ctx->r11, ctx->r25);
    // 0x800103E8: lh          $t4, -0x14($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X14);
    // 0x800103EC: sh          $t4, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r12;
    // 0x800103F0: lh          $t5, -0x12($v0)
    ctx->r13 = MEM_H(ctx->r2, -0X12);
    // 0x800103F4: sh          $t5, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r13;
    // 0x800103F8: lh          $t6, -0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, -0X10);
    // 0x800103FC: sh          $t6, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r14;
    // 0x80010400: lwc1        $f4, -0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0XC);
    // 0x80010404: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x80010408: lwc1        $f6, -0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X8);
    // 0x8001040C: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    // 0x80010410: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80010414: swc1        $f8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f8.u32l;
    // 0x80010418: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001041C: sw          $t8, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r24;
    // 0x80010420: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80010424: sw          $t7, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r15;
    // 0x80010428: lw          $t8, 0x8($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X8);
    // 0x8001042C: sb          $t2, 0x6A($v1)
    MEM_B(0X6A, ctx->r3) = ctx->r10;
    // 0x80010430: sw          $t8, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r24;
    // 0x80010434: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80010438:
    // 0x80010438: bne         $a0, $a2, L_800103B4
    if (ctx->r4 != ctx->r6) {
        // 0x8001043C: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_800103B4;
    }
    // 0x8001043C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_80010440:
    // 0x80010440: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80010444: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80010448: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8001044C: jr          $ra
    // 0x80010450: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x80010450: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80010454(rdram, ctx);
;}
RECOMP_FUNC void FUN_80010454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010454: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80010458: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8001045C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80010460: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80010464: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80010468: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001046C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80010470: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80010474: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80010478: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001047C: lhu         $a1, 0xC($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0XC);
    // 0x80010480: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80010484: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80010488: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8001048C: addiu       $a3, $a3, 0x3DF0
    ctx->r7 = ADD32(ctx->r7, 0X3DF0);
    // 0x80010490: addiu       $a2, $a2, 0x31F0
    ctx->r6 = ADD32(ctx->r6, 0X31F0);
    // 0x80010494: jal         0x8000FD0C
    // 0x80010498: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8000FD0C)(rdram, ctx);
        goto after_0;
    // 0x80010498: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8001049C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800104A0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800104A4: bne         $v0, $at, L_800104B4
    if (ctx->r2 != ctx->r1) {
        // 0x800104A8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800104B4;
    }
    // 0x800104A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800104AC: b           L_80010530
    // 0x800104B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80010530;
    // 0x800104B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800104B4:
    // 0x800104B4: blez        $v1, L_800104F0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800104B8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800104F0;
    }
    // 0x800104B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800104BC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800104C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800104C4:
    // 0x800104C4: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x800104C8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800104CC: jal         0x800101D8
    // 0x800104D0: lhu         $a2, 0xC($s3)
    ctx->r6 = MEM_HU(ctx->r19, 0XC);
    LOOKUP_FUNC(0x800101D8)(rdram, ctx);
        goto after_1;
    // 0x800104D0: lhu         $a2, 0xC($s3)
    ctx->r6 = MEM_HU(ctx->r19, 0XC);
    after_1:
    // 0x800104D4: bne         $s0, $zero, L_800104E0
    if (ctx->r16 != 0) {
        // 0x800104D8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800104E0;
    }
    // 0x800104D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800104DC: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
L_800104E0:
    // 0x800104E0: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x800104E4: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800104E8: bne         $at, $zero, L_800104C4
    if (ctx->r1 != 0) {
        // 0x800104EC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800104C4;
    }
    // 0x800104EC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800104F0:
    // 0x800104F0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800104F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800104F8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800104FC: beql        $t8, $zero, L_80010530
    if (ctx->r24 == 0) {
        // 0x80010500: lhu         $v0, 0x3A($sp)
        ctx->r2 = MEM_HU(ctx->r29, 0X3A);
            goto L_80010530;
    }
    goto skip_0;
    // 0x80010500: lhu         $v0, 0x3A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X3A);
    skip_0:
    // 0x80010504: jal         0x8000F458
    // 0x80010508: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    LOOKUP_FUNC(0x8000F458)(rdram, ctx);
        goto after_2;
    // 0x80010508: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x8001050C: lw          $t1, 0x44($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X44);
    // 0x80010510: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80010514: addiu       $t9, $t9, -0x3FD8
    ctx->r25 = ADD32(ctx->r25, -0X3FD8);
    // 0x80010518: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8001051C: lw          $t0, 0x48($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X48);
    // 0x80010520: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x80010524: lw          $t1, 0x4C($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4C);
    // 0x80010528: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
    // 0x8001052C: lhu         $v0, 0x3A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X3A);
L_80010530:
    // 0x80010530: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80010534: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80010538: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001053C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80010540: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80010544: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80010548: jr          $ra
    // 0x8001054C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001054C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80010550(rdram, ctx);
;}
RECOMP_FUNC void FUN_80010550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010550: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80010554: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80010558: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8001055C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80010560: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80010564: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80010568: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001056C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80010570: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80010574: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80010578: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001057C: addiu       $a3, $a3, 0x3DF0
    ctx->r7 = ADD32(ctx->r7, 0X3DF0);
    // 0x80010580: addiu       $a2, $a2, 0x31F0
    ctx->r6 = ADD32(ctx->r6, 0X31F0);
    // 0x80010584: jal         0x8000FE48
    // 0x80010588: lhu         $a1, 0xC($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0XC);
    LOOKUP_FUNC(0x8000FE48)(rdram, ctx);
        goto after_0;
    // 0x80010588: lhu         $a1, 0xC($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0XC);
    after_0:
    // 0x8001058C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80010590: blez        $v0, L_800105CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80010594: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800105CC;
    }
    // 0x80010594: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80010598: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001059C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
L_800105A0:
    // 0x800105A0: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x800105A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800105A8: jal         0x800101D8
    // 0x800105AC: lhu         $a2, 0xC($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0XC);
    LOOKUP_FUNC(0x800101D8)(rdram, ctx);
        goto after_1;
    // 0x800105AC: lhu         $a2, 0xC($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0XC);
    after_1:
    // 0x800105B0: bne         $s0, $zero, L_800105BC
    if (ctx->r16 != 0) {
        // 0x800105B4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800105BC;
    }
    // 0x800105B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800105B8: sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
L_800105BC:
    // 0x800105BC: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x800105C0: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800105C4: bne         $at, $zero, L_800105A0
    if (ctx->r1 != 0) {
        // 0x800105C8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800105A0;
    }
    // 0x800105C8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800105CC:
    // 0x800105CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800105D0: jal         0x8000F458
    // 0x800105D4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    LOOKUP_FUNC(0x8000F458)(rdram, ctx);
        goto after_2;
    // 0x800105D4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x800105D8: lw          $t8, 0x44($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X44);
    // 0x800105DC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x800105E0: addiu       $t6, $t6, -0x3FD8
    ctx->r14 = ADD32(ctx->r14, -0X3FD8);
    // 0x800105E4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800105E8: lw          $t7, 0x48($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X48);
    // 0x800105EC: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800105F0: lw          $t8, 0x4C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X4C);
    // 0x800105F4: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x800105F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800105FC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80010600: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80010604: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80010608: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001060C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80010610: lhu         $v0, 0x32($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X32);
    // 0x80010614: jr          $ra
    // 0x80010618: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80010618: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001061c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001061c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001061C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80010620: lhu         $at, 0x5A($sp)
    ctx->r1 = MEM_HU(ctx->r29, 0X5A);
    // 0x80010624: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80010628: addiu       $t7, $t7, 0x3670
    ctx->r15 = ADD32(ctx->r15, 0X3670);
    // 0x8001062C: sll         $v0, $at, 2
    ctx->r2 = S32(ctx->r1 << 2);
    // 0x80010630: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
    // 0x80010634: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80010638: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8001063C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80010640: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80010644: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80010648: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8001064C: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80010650: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x80010654: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x80010658: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8001065C: addiu       $t2, $t2, 0x3A30
    ctx->r10 = ADD32(ctx->r10, 0X3A30);
    // 0x80010660: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80010664: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80010668: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8001066C: addiu       $t1, $sp, 0x18
    ctx->r9 = ADD32(ctx->r29, 0X18);
    // 0x80010670: sw          $t0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r8;
    // 0x80010674: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80010678: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x8001067C: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x80010680: sw          $t0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r8;
    // 0x80010684: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80010688: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x8001068C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80010690: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x80010694: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80010698: sw          $t5, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r13;
    // 0x8001069C: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x800106A0: sw          $t4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r12;
    // 0x800106A4: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x800106A8: sw          $t5, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r13;
    // 0x800106AC: lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X2C);
    // 0x800106B0: lh          $t6, 0x2C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2C);
    // 0x800106B4: lw          $t7, 0x28($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X28);
    // 0x800106B8: beq         $t7, $zero, L_8001087C
    if (ctx->r15 == 0) {
        // 0x800106BC: nop
    
            goto L_8001087C;
    }
    // 0x800106BC: nop

    // 0x800106C0: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800106C4: sh          $t6, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r14;
    // 0x800106C8: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x800106CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800106D0: sh          $t8, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r24;
    // 0x800106D4: lh          $t9, 0x30($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X30);
    // 0x800106D8: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800106DC: sh          $t9, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r25;
    // 0x800106E0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800106E4: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x800106E8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800106EC: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    // 0x800106F0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800106F4: bc1t        L_80010828
    if (c1cs) {
        // 0x800106F8: swc1        $f8, 0x20($v1)
        MEM_W(0X20, ctx->r3) = ctx->f8.u32l;
            goto L_80010828;
    }
    // 0x800106F8: swc1        $f8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f8.u32l;
    // 0x800106FC: lh          $v0, 0x10($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X10);
    // 0x80010700: lh          $t0, 0x18($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X18);
    // 0x80010704: subu        $a0, $t0, $v0
    ctx->r4 = SUB32(ctx->r8, ctx->r2);
    // 0x80010708: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001070C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80010710: andi        $t2, $a0, 0x1000
    ctx->r10 = ctx->r4 & 0X1000;
    // 0x80010714: beq         $t2, $zero, L_80010728
    if (ctx->r10 == 0) {
        // 0x80010718: andi        $a1, $a0, 0x1FFF
        ctx->r5 = ctx->r4 & 0X1FFF;
            goto L_80010728;
    }
    // 0x80010718: andi        $a1, $a0, 0x1FFF
    ctx->r5 = ctx->r4 & 0X1FFF;
    // 0x8001071C: andi        $a1, $a0, 0x1FFF
    ctx->r5 = ctx->r4 & 0X1FFF;
    // 0x80010720: b           L_80010728
    // 0x80010724: addiu       $a1, $a1, -0x2000
    ctx->r5 = ADD32(ctx->r5, -0X2000);
        goto L_80010728;
    // 0x80010724: addiu       $a1, $a1, -0x2000
    ctx->r5 = ADD32(ctx->r5, -0X2000);
L_80010728:
    // 0x80010728: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x8001072C: lh          $a0, 0x12($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X12);
    // 0x80010730: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80010734: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80010738: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8001073C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80010740: nop

    // 0x80010744: addu        $t7, $v0, $t5
    ctx->r15 = ADD32(ctx->r2, ctx->r13);
    // 0x80010748: sh          $t7, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r15;
    // 0x8001074C: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x80010750: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    // 0x80010754: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80010758: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001075C: andi        $t8, $a2, 0x1000
    ctx->r24 = ctx->r6 & 0X1000;
    // 0x80010760: beq         $t8, $zero, L_80010774
    if (ctx->r24 == 0) {
        // 0x80010764: andi        $a1, $a2, 0x1FFF
        ctx->r5 = ctx->r6 & 0X1FFF;
            goto L_80010774;
    }
    // 0x80010764: andi        $a1, $a2, 0x1FFF
    ctx->r5 = ctx->r6 & 0X1FFF;
    // 0x80010768: andi        $a1, $a2, 0x1FFF
    ctx->r5 = ctx->r6 & 0X1FFF;
    // 0x8001076C: b           L_80010774
    // 0x80010770: addiu       $a1, $a1, -0x2000
    ctx->r5 = ADD32(ctx->r5, -0X2000);
        goto L_80010774;
    // 0x80010770: addiu       $a1, $a1, -0x2000
    ctx->r5 = ADD32(ctx->r5, -0X2000);
L_80010774:
    // 0x80010774: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x80010778: lh          $v0, 0x14($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X14);
    // 0x8001077C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80010780: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80010784: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80010788: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8001078C: nop

    // 0x80010790: addu        $t3, $a0, $t1
    ctx->r11 = ADD32(ctx->r4, ctx->r9);
    // 0x80010794: sh          $t3, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r11;
    // 0x80010798: lh          $t4, 0x1C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X1C);
    // 0x8001079C: subu        $a2, $t4, $v0
    ctx->r6 = SUB32(ctx->r12, ctx->r2);
    // 0x800107A0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800107A4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800107A8: andi        $t5, $a2, 0x1000
    ctx->r13 = ctx->r6 & 0X1000;
    // 0x800107AC: beq         $t5, $zero, L_800107C0
    if (ctx->r13 == 0) {
        // 0x800107B0: andi        $a1, $a2, 0x1FFF
        ctx->r5 = ctx->r6 & 0X1FFF;
            goto L_800107C0;
    }
    // 0x800107B0: andi        $a1, $a2, 0x1FFF
    ctx->r5 = ctx->r6 & 0X1FFF;
    // 0x800107B4: andi        $a1, $a2, 0x1FFF
    ctx->r5 = ctx->r6 & 0X1FFF;
    // 0x800107B8: b           L_800107C0
    // 0x800107BC: addiu       $a1, $a1, -0x2000
    ctx->r5 = ADD32(ctx->r5, -0X2000);
        goto L_800107C0;
    // 0x800107BC: addiu       $a1, $a1, -0x2000
    ctx->r5 = ADD32(ctx->r5, -0X2000);
L_800107C0:
    // 0x800107C0: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800107C4: lwc1        $f2, 0x18($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X18);
    // 0x800107C8: lwc1        $f12, 0x1C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800107CC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800107D0: lwc1        $f14, 0x20($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X20);
    // 0x800107D4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800107D8: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800107DC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800107E0: nop

    // 0x800107E4: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800107E8: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
    // 0x800107EC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800107F0: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800107F4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800107F8: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800107FC: swc1        $f10, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f10.u32l;
    // 0x80010800: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80010804: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x80010808: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001080C: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80010810: swc1        $f8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f8.u32l;
    // 0x80010814: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80010818: sub.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8001081C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80010820: add.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x80010824: swc1        $f6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f6.u32l;
L_80010828:
    // 0x80010828: lhu         $t2, 0x5E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X5E);
    // 0x8001082C: addiu       $t1, $sp, 0x44
    ctx->r9 = ADD32(ctx->r29, 0X44);
    // 0x80010830: lhu         $t5, 0x62($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X62);
    // 0x80010834: beql        $t2, $zero, L_80010860
    if (ctx->r10 == 0) {
        // 0x80010838: mtc1        $t5, $f8
        ctx->f8.u32l = ctx->r13;
            goto L_80010860;
    }
    goto skip_0;
    // 0x80010838: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    skip_0:
    // 0x8001083C: swc1        $f16, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f16.u32l;
    // 0x80010840: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80010844: sw          $t4, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r12;
    // 0x80010848: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8001084C: sw          $t3, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r11;
    // 0x80010850: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x80010854: b           L_8001087C
    // 0x80010858: sw          $t4, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r12;
        goto L_8001087C;
    // 0x80010858: sw          $t4, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r12;
    // 0x8001085C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
L_80010860:
    // 0x80010860: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80010864: bgez        $t5, L_80010878
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80010868: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80010878;
    }
    // 0x80010868: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001086C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80010870: nop

    // 0x80010874: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_80010878:
    // 0x80010878: swc1        $f10, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f10.u32l;
L_8001087C:
    // 0x8001087C: jr          $ra
    // 0x80010880: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80010880: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80010884(rdram, ctx);
;}
RECOMP_FUNC void FUN_80010884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010884: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80010888: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x8001088C: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x80010890: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80010894: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80010898: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8001089C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800108A0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800108A4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800108A8: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800108AC: lhu         $a2, 0xBE($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0XBE);
    // 0x800108B0: lhu         $t8, 0x22($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X22);
    // 0x800108B4: lhu         $t9, 0xB6($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0XB6);
    // 0x800108B8: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x800108BC: lw          $s1, 0x2C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X2C);
    // 0x800108C0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800108C4: sh          $t8, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r24;
    // 0x800108C8: bgtz        $a2, L_800108DC
    if (SIGNED(ctx->r6) > 0) {
        // 0x800108CC: sh          $t9, 0x5C($sp)
        MEM_H(0X5C, ctx->r29) = ctx->r25;
            goto L_800108DC;
    }
    // 0x800108CC: sh          $t9, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r25;
    // 0x800108D0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800108D4: b           L_8001094C
    // 0x800108D8: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
        goto L_8001094C;
    // 0x800108D8: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
L_800108DC:
    // 0x800108DC: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x800108E0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800108E4: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800108E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800108EC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800108F0: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
    // 0x800108F4: add.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d + ctx->f0.d;
    // 0x800108F8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800108FC: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80010900: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80010904: bgez        $a2, L_8001091C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80010908: cvt.d.s     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
            goto L_8001091C;
    }
    // 0x80010908: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8001090C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80010910: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80010914: nop

    // 0x80010918: add.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f4.d + ctx->f6.d;
L_8001091C:
    // 0x8001091C: add.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f4.d + ctx->f0.d;
    // 0x80010920: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010924: div.d       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f8.d);
    // 0x80010928: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x8001092C: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x80010930: c.le.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d <= ctx->f18.d;
    // 0x80010934: nop

    // 0x80010938: bc1fl       L_8001094C
    if (!c1cs) {
        // 0x8001093C: lw          $a0, 0xB0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XB0);
            goto L_8001094C;
    }
    goto skip_0;
    // 0x8001093C: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    skip_0:
    // 0x80010940: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80010944: nop

    // 0x80010948: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
L_8001094C:
    // 0x8001094C: jal         0x8000E58C
    // 0x80010950: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8000E58C)(rdram, ctx);
        goto after_0;
    // 0x80010950: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    after_0:
    // 0x80010954: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x80010958: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x8001095C: sw          $v1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r3;
    // 0x80010960: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80010964: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x80010968: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8001096C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x80010970: jal         0x8000E748
    // 0x80010974: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    LOOKUP_FUNC(0x8000E748)(rdram, ctx);
        goto after_1;
    // 0x80010974: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x80010978: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8001097C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80010980: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80010984: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80010988: lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // 0x8001098C: addiu       $s0, $s0, 0x31B0
    ctx->r16 = ADD32(ctx->r16, 0X31B0);
    // 0x80010990: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80010994: lui         $t5, 0x8006
    ctx->r13 = S32(0X8006 << 16);
    // 0x80010998: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8001099C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800109A0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800109A4: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x800109A8: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800109AC: beql        $t2, $zero, L_800109FC
    if (ctx->r10 == 0) {
        // 0x800109B0: mfc1        $t2, $f4
        ctx->r10 = (int32_t)ctx->f4.u32l;
            goto L_800109FC;
    }
    goto skip_1;
    // 0x800109B0: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x800109B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800109B8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800109BC: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800109C0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800109C4: nop

    // 0x800109C8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800109CC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800109D0: nop

    // 0x800109D4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800109D8: bne         $t2, $zero, L_800109F0
    if (ctx->r10 != 0) {
        // 0x800109DC: nop
    
            goto L_800109F0;
    }
    // 0x800109DC: nop

    // 0x800109E0: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800109E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800109E8: b           L_80010A08
    // 0x800109EC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80010A08;
    // 0x800109EC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_800109F0:
    // 0x800109F0: b           L_80010A08
    // 0x800109F4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80010A08;
    // 0x800109F4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800109F8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
L_800109FC:
    // 0x800109FC: nop

    // 0x80010A00: bltz        $t2, L_800109F0
    if (SIGNED(ctx->r10) < 0) {
        // 0x80010A04: nop
    
            goto L_800109F0;
    }
    // 0x80010A04: nop

L_80010A08:
    // 0x80010A08: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x80010A0C: lw          $t5, 0x31E4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X31E4);
    // 0x80010A10: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80010A14: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80010A18: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80010A1C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80010A20: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x80010A24: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80010A28: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80010A2C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80010A30: and         $t1, $t6, $at
    ctx->r9 = ctx->r14 & ctx->r1;
    // 0x80010A34: jal         0x8000DDB0
    // 0x80010A38: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    LOOKUP_FUNC(0x8000DDB0)(rdram, ctx);
        goto after_2;
    // 0x80010A38: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    after_2:
    // 0x80010A3C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80010A40: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80010A44: addiu       $t7, $t7, 0x31C8
    ctx->r15 = ADD32(ctx->r15, 0X31C8);
    // 0x80010A48: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80010A4C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80010A50: lui         $t0, 0x8006
    ctx->r8 = S32(0X8006 << 16);
    // 0x80010A54: addiu       $t0, $t0, 0x31BC
    ctx->r8 = ADD32(ctx->r8, 0X31BC);
    // 0x80010A58: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80010A5C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80010A60: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x80010A64: addiu       $t9, $t9, 0x31D4
    ctx->r25 = ADD32(ctx->r25, 0X31D4);
    // 0x80010A68: sw          $t8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r24;
    // 0x80010A6C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80010A70: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80010A74: addiu       $v0, $s2, 0x1C
    ctx->r2 = ADD32(ctx->r18, 0X1C);
    // 0x80010A78: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x80010A7C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80010A80: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80010A84: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80010A88: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
    // 0x80010A8C: lhu         $t3, 0x5C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X5C);
    // 0x80010A90: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x80010A94: beql        $t4, $zero, L_80010AC4
    if (ctx->r12 == 0) {
        // 0x80010A98: lw          $a0, 0x0($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X0);
            goto L_80010AC4;
    }
    goto skip_2;
    // 0x80010A98: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x80010A9C: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80010AA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80010AA4: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80010AA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80010AAC: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80010AB0: nop

    // 0x80010AB4: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80010AB8: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x80010ABC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80010AC0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
L_80010AC4:
    // 0x80010AC4: jal         0x8000E58C
    // 0x80010AC8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8000E58C)(rdram, ctx);
        goto after_3;
    // 0x80010AC8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80010ACC: addiu       $t5, $sp, 0x5A
    ctx->r13 = ADD32(ctx->r29, 0X5A);
    // 0x80010AD0: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x80010AD4: sw          $v1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r3;
    // 0x80010AD8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80010ADC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80010AE0: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80010AE4: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x80010AE8: jal         0x8000E748
    // 0x80010AEC: addiu       $a3, $sp, 0x56
    ctx->r7 = ADD32(ctx->r29, 0X56);
    LOOKUP_FUNC(0x8000E748)(rdram, ctx);
        goto after_4;
    // 0x80010AEC: addiu       $a3, $sp, 0x56
    ctx->r7 = ADD32(ctx->r29, 0X56);
    after_4:
    // 0x80010AF0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80010AF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80010AF8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80010AFC: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80010B00: lui         $t0, 0x8006
    ctx->r8 = S32(0X8006 << 16);
    // 0x80010B04: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80010B08: cvt.w.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80010B0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80010B10: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80010B14: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80010B18: nop

    // 0x80010B1C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80010B20: beql        $t6, $zero, L_80010B70
    if (ctx->r14 == 0) {
        // 0x80010B24: mfc1        $t6, $f8
        ctx->r14 = (int32_t)ctx->f8.u32l;
            goto L_80010B70;
    }
    goto skip_3;
    // 0x80010B24: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    skip_3:
    // 0x80010B28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80010B2C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80010B30: sub.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80010B34: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80010B38: nop

    // 0x80010B3C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80010B40: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80010B44: nop

    // 0x80010B48: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80010B4C: bne         $t6, $zero, L_80010B64
    if (ctx->r14 != 0) {
        // 0x80010B50: nop
    
            goto L_80010B64;
    }
    // 0x80010B50: nop

    // 0x80010B54: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80010B58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010B5C: b           L_80010B7C
    // 0x80010B60: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80010B7C;
    // 0x80010B60: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80010B64:
    // 0x80010B64: b           L_80010B7C
    // 0x80010B68: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80010B7C;
    // 0x80010B68: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80010B6C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
L_80010B70:
    // 0x80010B70: nop

    // 0x80010B74: bltz        $t6, L_80010B64
    if (SIGNED(ctx->r14) < 0) {
        // 0x80010B78: nop
    
            goto L_80010B64;
    }
    // 0x80010B78: nop

L_80010B7C:
    // 0x80010B7C: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80010B80: lw          $t0, 0x31E4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X31E4);
    // 0x80010B84: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80010B88: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80010B8C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80010B90: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80010B94: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80010B98: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x80010B9C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80010BA0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80010BA4: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x80010BA8: jal         0x8000DDB0
    // 0x80010BAC: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    LOOKUP_FUNC(0x8000DDB0)(rdram, ctx);
        goto after_5;
    // 0x80010BAC: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    after_5:
    // 0x80010BB0: lhu         $t0, 0x5E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X5E);
    // 0x80010BB4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80010BB8: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x80010BBC: beql        $t1, $zero, L_80010BE8
    if (ctx->r9 == 0) {
        // 0x80010BC0: lwc1        $f16, 0xC($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80010BE8;
    }
    goto skip_4;
    // 0x80010BC0: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    skip_4:
    // 0x80010BC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80010BC8: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80010BCC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80010BD0: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80010BD4: nop

    // 0x80010BD8: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80010BDC: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x80010BE0: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80010BE4: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
L_80010BE8:
    // 0x80010BE8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80010BEC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80010BF0: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80010BF4: c.eq.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
    // 0x80010BF8: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80010BFC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80010C00: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80010C04: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80010C08: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
    // 0x80010C0C: bc1t        L_80010C64
    if (c1cs) {
        // 0x80010C10: lwc1        $f12, 0x10($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
            goto L_80010C64;
    }
    // 0x80010C10: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80010C14: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80010C18: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80010C1C: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80010C20: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80010C24: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80010C28: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80010C2C: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80010C30: add.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80010C34: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x80010C38: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80010C3C: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80010C40: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80010C44: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80010C48: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80010C4C: add.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80010C50: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
    // 0x80010C54: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80010C58: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80010C5C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80010C60: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_80010C64:
    // 0x80010C64: lwc1        $f18, 0x34($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X34);
    // 0x80010C68: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80010C6C: ldc1        $f16, -0x37F8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X37F8);
    // 0x80010C70: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80010C74: lw          $v1, 0xA4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA4);
    // 0x80010C78: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80010C7C: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80010C80: div.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f16.d);
    // 0x80010C84: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80010C88: swc1        $f10, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f10.u32l;
    // 0x80010C8C: swc1        $f14, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f14.u32l;
    // 0x80010C90: swc1        $f14, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f14.u32l;
    // 0x80010C94: swc1        $f14, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f14.u32l;
    // 0x80010C98: lw          $t3, 0x5C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X5C);
    // 0x80010C9C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80010CA0: lw          $t2, 0x60($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X60);
    // 0x80010CA4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80010CA8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80010CAC: lw          $t3, 0x64($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X64);
    // 0x80010CB0: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x80010CB4: sw          $t5, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r13;
    // 0x80010CB8: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80010CBC: sw          $t4, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r12;
    // 0x80010CC0: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x80010CC4: sw          $t5, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r13;
    // 0x80010CC8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80010CCC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80010CD0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80010CD4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80010CD8: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80010CDC: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80010CE0: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x80010CE4: lwc1        $f18, 0x50($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X50);
    // 0x80010CE8: swc1        $f18, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f18.u32l;
    // 0x80010CEC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80010CF0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80010CF4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80010CF8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80010CFC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80010D00: jr          $ra
    // 0x80010D04: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80010D04: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80010d08(rdram, ctx);
;}
RECOMP_FUNC void FUN_80010d08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010D08: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80010D0C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80010D10: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80010D14: lui         $s3, 0x8006
    ctx->r19 = S32(0X8006 << 16);
    // 0x80010D18: lui         $s4, 0x8006
    ctx->r20 = S32(0X8006 << 16);
    // 0x80010D1C: addiu       $s4, $s4, 0x3DF0
    ctx->r20 = ADD32(ctx->r20, 0X3DF0);
    // 0x80010D20: addiu       $s3, $s3, 0x31F0
    ctx->r19 = ADD32(ctx->r19, 0X31F0);
    // 0x80010D24: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80010D28: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80010D2C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80010D30: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80010D34: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80010D38: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80010D3C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80010D40: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80010D44: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x80010D48: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80010D4C: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80010D50: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x80010D54: sh          $zero, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = 0;
    // 0x80010D58: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80010D5C: lw          $s1, 0xA0($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA0);
    // 0x80010D60: lhu         $a1, 0xC($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0XC);
    // 0x80010D64: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80010D68: jal         0x8000FE48
    // 0x80010D6C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    LOOKUP_FUNC(0x8000FE48)(rdram, ctx);
        goto after_0;
    // 0x80010D6C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_0:
    // 0x80010D70: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80010D74: blez        $v0, L_80010DCC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80010D78: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80010DCC;
    }
    // 0x80010D78: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80010D7C: lui         $s5, 0x8006
    ctx->r21 = S32(0X8006 << 16);
    // 0x80010D80: addiu       $s5, $s5, 0x3670
    ctx->r21 = ADD32(ctx->r21, 0X3670);
    // 0x80010D84: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x80010D88: addiu       $s7, $sp, 0x74
    ctx->r23 = ADD32(ctx->r29, 0X74);
    // 0x80010D8C: addiu       $s6, $sp, 0x76
    ctx->r22 = ADD32(ctx->r29, 0X76);
    // 0x80010D90: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
L_80010D94:
    // 0x80010D94: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x80010D98: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80010D9C: lhu         $a2, 0xC($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0XC);
    // 0x80010DA0: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // 0x80010DA4: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x80010DA8: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80010DAC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80010DB0: jal         0x80010068
    // 0x80010DB4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80010068)(rdram, ctx);
        goto after_1;
    // 0x80010DB4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_1:
    // 0x80010DB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80010DBC: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80010DC0: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80010DC4: bnel        $at, $zero, L_80010D94
    if (ctx->r1 != 0) {
        // 0x80010DC8: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_80010D94;
    }
    goto skip_0;
    // 0x80010DC8: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    skip_0:
L_80010DCC:
    // 0x80010DCC: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80010DD0: addiu       $s5, $sp, 0x90
    ctx->r21 = ADD32(ctx->r29, 0X90);
    // 0x80010DD4: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x80010DD8: lhu         $a1, 0xC($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0XC);
    // 0x80010DDC: lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // 0x80010DE0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80010DE4: lw          $t9, 0x4($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X4);
    // 0x80010DE8: lui         $s2, 0x8006
    ctx->r18 = S32(0X8006 << 16);
    // 0x80010DEC: addiu       $s2, $s2, 0x3E50
    ctx->r18 = ADD32(ctx->r18, 0X3E50);
    // 0x80010DF0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80010DF4: lw          $t0, 0x8($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X8);
    // 0x80010DF8: addiu       $s0, $s0, 0x3430
    ctx->r16 = ADD32(ctx->r16, 0X3430);
    // 0x80010DFC: addiu       $s6, $sp, 0x76
    ctx->r22 = ADD32(ctx->r29, 0X76);
    // 0x80010E00: addiu       $s7, $sp, 0x74
    ctx->r23 = ADD32(ctx->r29, 0X74);
    // 0x80010E04: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80010E08: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80010E0C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80010E10: jal         0x8000FF80
    // 0x80010E14: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8000FF80)(rdram, ctx);
        goto after_2;
    // 0x80010E14: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_2:
    // 0x80010E18: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x80010E1C: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x80010E20: addiu       $t2, $t2, 0x3A30
    ctx->r10 = ADD32(ctx->r10, 0X3A30);
    // 0x80010E24: lhu         $a2, 0xC($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0XC);
    // 0x80010E28: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // 0x80010E2C: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x80010E30: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80010E34: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80010E38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80010E3C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80010E40: jal         0x80010068
    // 0x80010E44: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80010068)(rdram, ctx);
        goto after_3;
    // 0x80010E44: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_3:
    // 0x80010E48: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80010E4C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80010E50: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80010E54: bne         $at, $zero, L_80010E8C
    if (ctx->r1 != 0) {
        // 0x80010E58: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80010E8C;
    }
    // 0x80010E58: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80010E5C: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x80010E60: andi        $t3, $a1, 0x1
    ctx->r11 = ctx->r5 & 0X1;
    // 0x80010E64: bnel        $t3, $zero, L_80010E90
    if (ctx->r11 != 0) {
        // 0x80010E68: sll         $t5, $s0, 2
        ctx->r13 = S32(ctx->r16 << 2);
            goto L_80010E90;
    }
    goto skip_1;
    // 0x80010E68: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    skip_1:
    // 0x80010E6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80010E70:
    // 0x80010E70: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80010E74: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80010E78: beq         $at, $zero, L_80010E8C
    if (ctx->r1 == 0) {
        // 0x80010E7C: srl         $s1, $s1, 1
        ctx->r17 = S32(U32(ctx->r17) >> 1);
            goto L_80010E8C;
    }
    // 0x80010E7C: srl         $s1, $s1, 1
    ctx->r17 = S32(U32(ctx->r17) >> 1);
    // 0x80010E80: andi        $t4, $s1, 0x1
    ctx->r12 = ctx->r17 & 0X1;
    // 0x80010E84: beql        $t4, $zero, L_80010E70
    if (ctx->r12 == 0) {
        // 0x80010E88: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80010E70;
    }
    goto skip_2;
    // 0x80010E88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
L_80010E8C:
    // 0x80010E8C: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
L_80010E90:
    // 0x80010E90: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x80010E94: lhu         $s4, 0x9E($sp)
    ctx->r20 = MEM_HU(ctx->r29, 0X9E);
    // 0x80010E98: addu        $t6, $fp, $t5
    ctx->r14 = ADD32(ctx->r30, ctx->r13);
    // 0x80010E9C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80010EA0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80010EA4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80010EA8: andi        $s6, $a1, 0x1
    ctx->r22 = ctx->r5 & 0X1;
    // 0x80010EAC: bgtz        $s4, L_80010EC4
    if (SIGNED(ctx->r20) > 0) {
        // 0x80010EB0: lw          $s3, 0x2C($t7)
        ctx->r19 = MEM_W(ctx->r15, 0X2C);
            goto L_80010EC4;
    }
    // 0x80010EB0: lw          $s3, 0x2C($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X2C);
    // 0x80010EB4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80010EB8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80010EBC: b           L_80010F34
    // 0x80010EC0: sh          $t8, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r24;
        goto L_80010F34;
    // 0x80010EC0: sh          $t8, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r24;
L_80010EC4:
    // 0x80010EC4: lwc1        $f4, 0x50($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X50);
    // 0x80010EC8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80010ECC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80010ED0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80010ED4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80010ED8: mtc1        $s4, $f18
    ctx->f18.u32l = ctx->r20;
    // 0x80010EDC: add.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d + ctx->f0.d;
    // 0x80010EE0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80010EE4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80010EE8: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80010EEC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80010EF0: bgez        $s4, L_80010F08
    if (SIGNED(ctx->r20) >= 0) {
        // 0x80010EF4: cvt.d.s     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
            goto L_80010F08;
    }
    // 0x80010EF4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80010EF8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80010EFC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80010F00: nop

    // 0x80010F04: add.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f4.d + ctx->f6.d;
L_80010F08:
    // 0x80010F08: add.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f4.d + ctx->f0.d;
    // 0x80010F0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010F10: div.d       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f8.d);
    // 0x80010F14: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x80010F18: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x80010F1C: c.le.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d <= ctx->f18.d;
    // 0x80010F20: nop

    // 0x80010F24: bc1fl       L_80010F38
    if (!c1cs) {
        // 0x80010F28: lhu         $t0, 0x62($s3)
        ctx->r8 = MEM_HU(ctx->r19, 0X62);
            goto L_80010F38;
    }
    goto skip_3;
    // 0x80010F28: lhu         $t0, 0x62($s3)
    ctx->r8 = MEM_HU(ctx->r19, 0X62);
    skip_3:
    // 0x80010F2C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80010F30: sh          $t9, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r25;
L_80010F34:
    // 0x80010F34: lhu         $t0, 0x62($s3)
    ctx->r8 = MEM_HU(ctx->r19, 0X62);
L_80010F38:
    // 0x80010F38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010F3C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80010F40: bnel        $t1, $zero, L_80010F94
    if (ctx->r9 != 0) {
        // 0x80010F44: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80010F94;
    }
    goto skip_4;
    // 0x80010F44: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    skip_4:
    // 0x80010F48: lwc1        $f6, 0x50($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X50);
    // 0x80010F4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80010F50: mtc1        $s4, $f10
    ctx->f10.u32l = ctx->r20;
    // 0x80010F54: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80010F58: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80010F5C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80010F60: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80010F64: swc1        $f16, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f16.u32l;
    // 0x80010F68: bgez        $s4, L_80010F7C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x80010F6C: lwc1        $f8, 0x50($s3)
        ctx->f8.u32l = MEM_W(ctx->r19, 0X50);
            goto L_80010F7C;
    }
    // 0x80010F6C: lwc1        $f8, 0x50($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X50);
    // 0x80010F70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80010F74: nop

    // 0x80010F78: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_80010F7C:
    // 0x80010F7C: c.le.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x80010F80: nop

    // 0x80010F84: bc1fl       L_80010F94
    if (!c1cs) {
        // 0x80010F88: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80010F94;
    }
    goto skip_5;
    // 0x80010F88: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    skip_5:
    // 0x80010F8C: sh          $t2, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r10;
    // 0x80010F90: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
L_80010F94:
    // 0x80010F94: bne         $at, $zero, L_8001109C
    if (ctx->r1 != 0) {
        // 0x80010F98: nop
    
            goto L_8001109C;
    }
    // 0x80010F98: nop

    // 0x80010F9C: beq         $a1, $zero, L_8001109C
    if (ctx->r5 == 0) {
        // 0x80010FA0: or          $s2, $a0, $zero
        ctx->r18 = ctx->r4 | 0;
            goto L_8001109C;
    }
    // 0x80010FA0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80010FA4: andi        $t3, $s1, 0x1
    ctx->r11 = ctx->r17 & 0X1;
L_80010FA8:
    // 0x80010FA8: beq         $t3, $zero, L_80011080
    if (ctx->r11 == 0) {
        // 0x80010FAC: sll         $t4, $s0, 2
        ctx->r12 = S32(ctx->r16 << 2);
            goto L_80011080;
    }
    // 0x80010FAC: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80010FB0: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80010FB4: addu        $t5, $fp, $t4
    ctx->r13 = ADD32(ctx->r30, ctx->r12);
    // 0x80010FB8: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80010FBC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80010FC0: lw          $t6, 0x4($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X4);
    // 0x80010FC4: lhu         $t9, 0x7A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X7A);
    // 0x80010FC8: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x80010FCC: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x80010FD0: lw          $t7, 0x8($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X8);
    // 0x80010FD4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80010FD8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80010FDC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80010FE0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80010FE4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80010FE8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80010FEC: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x80010FF0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80010FF4: lwc1        $f4, 0x50($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X50);
    // 0x80010FF8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80010FFC: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80011000: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80011004: nop

    // 0x80011008: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8001100C: beql        $t1, $zero, L_8001105C
    if (ctx->r9 == 0) {
        // 0x80011010: mfc1        $t1, $f16
        ctx->r9 = (int32_t)ctx->f16.u32l;
            goto L_8001105C;
    }
    goto skip_6;
    // 0x80011010: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    skip_6:
    // 0x80011014: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80011018: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001101C: sub.s       $f16, $f4, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80011020: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80011024: nop

    // 0x80011028: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8001102C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80011030: nop

    // 0x80011034: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80011038: bne         $t1, $zero, L_80011050
    if (ctx->r9 != 0) {
        // 0x8001103C: nop
    
            goto L_80011050;
    }
    // 0x8001103C: nop

    // 0x80011040: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80011044: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80011048: b           L_80011068
    // 0x8001104C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80011068;
    // 0x8001104C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80011050:
    // 0x80011050: b           L_80011068
    // 0x80011054: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80011068;
    // 0x80011054: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80011058: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
L_8001105C:
    // 0x8001105C: nop

    // 0x80011060: bltz        $t1, L_80011050
    if (SIGNED(ctx->r9) < 0) {
        // 0x80011064: nop
    
            goto L_80011050;
    }
    // 0x80011064: nop

L_80011068:
    // 0x80011068: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8001106C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80011070: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80011074: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80011078: jal         0x8001061C
    // 0x8001107C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x8001061C)(rdram, ctx);
        goto after_4;
    // 0x8001107C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
L_80011080:
    // 0x80011080: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80011084: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80011088: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8001108C: beq         $at, $zero, L_8001109C
    if (ctx->r1 == 0) {
        // 0x80011090: srl         $s1, $s1, 1
        ctx->r17 = S32(U32(ctx->r17) >> 1);
            goto L_8001109C;
    }
    // 0x80011090: srl         $s1, $s1, 1
    ctx->r17 = S32(U32(ctx->r17) >> 1);
    // 0x80011094: bnel        $s1, $zero, L_80010FA8
    if (ctx->r17 != 0) {
        // 0x80011098: andi        $t3, $s1, 0x1
        ctx->r11 = ctx->r17 & 0X1;
            goto L_80010FA8;
    }
    goto skip_7;
    // 0x80011098: andi        $t3, $s1, 0x1
    ctx->r11 = ctx->r17 & 0X1;
    skip_7:
L_8001109C:
    // 0x8001109C: beql        $s6, $zero, L_8001110C
    if (ctx->r22 == 0) {
        // 0x800110A0: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_8001110C;
    }
    goto skip_8;
    // 0x800110A0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_8:
    // 0x800110A4: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x800110A8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800110AC: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800110B0: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800110B4: lw          $a3, 0x4($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X4);
    // 0x800110B8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x800110BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800110C0: lw          $t3, 0x8($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X8);
    // 0x800110C4: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800110C8: jal         0x80010884
    // 0x800110CC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80010884)(rdram, ctx);
        goto after_5;
    // 0x800110CC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_5:
    // 0x800110D0: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x800110D4: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x800110D8: addiu       $t4, $t4, -0x3FD8
    ctx->r12 = ADD32(ctx->r12, -0X3FD8);
    // 0x800110DC: lw          $t7, 0x44($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X44);
    // 0x800110E0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x800110E4: lw          $t6, 0x48($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X48);
    // 0x800110E8: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800110EC: lw          $t7, 0x4C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4C);
    // 0x800110F0: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x800110F4: lhu         $t8, 0x7A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X7A);
    // 0x800110F8: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x800110FC: beq         $t8, $zero, L_80011108
    if (ctx->r24 == 0) {
        // 0x80011100: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80011108;
    }
    // 0x80011100: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80011104: sb          $t9, 0x76($t0)
    MEM_B(0X76, ctx->r8) = ctx->r25;
L_80011108:
    // 0x80011108: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8001110C:
    // 0x8001110C: lhu         $v0, 0x7A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X7A);
    // 0x80011110: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80011114: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80011118: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8001111C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80011120: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80011124: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80011128: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8001112C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80011130: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80011134: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80011138: jr          $ra
    // 0x8001113C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8001113C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80011140(rdram, ctx);
;}
RECOMP_FUNC void FUN_80011140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011140: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80011144: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80011148: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001114C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80011150: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80011154: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80011158: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x8001115C: lui         $t0, 0xFF
    ctx->r8 = S32(0XFF << 16);
    // 0x80011160: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x80011164: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x80011168: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x8001116C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80011170: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80011174: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80011178: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8001117C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80011180: jal         0x80010D08
    // 0x80011184: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80010D08)(rdram, ctx);
        goto after_0;
    // 0x80011184: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x80011188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001118C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80011190: jr          $ra
    // 0x80011194: nop

    return;
    // 0x80011194: nop

;}
RECOMP_FUNC void FUN_80011198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011198: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8001119C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800111A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800111A4: blez        $t6, L_800111D8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800111A8: nop
    
            goto L_800111D8;
    }
    // 0x800111A8: nop

    // 0x800111AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800111B0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800111B4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_800111B8:
    // 0x800111B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800111BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800111C0: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x800111C4: swc1        $f0, 0x50($t8)
    MEM_W(0X50, ctx->r24) = ctx->f0.u32l;
    // 0x800111C8: lhu         $t9, 0xC($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XC);
    // 0x800111CC: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800111D0: bnel        $at, $zero, L_800111B8
    if (ctx->r1 != 0) {
        // 0x800111D4: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_800111B8;
    }
    goto skip_0;
    // 0x800111D4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_0:
L_800111D8:
    // 0x800111D8: jr          $ra
    // 0x800111DC: sb          $t0, 0x76($a1)
    MEM_B(0X76, ctx->r5) = ctx->r8;
    return;
    // 0x800111DC: sb          $t0, 0x76($a1)
    MEM_B(0X76, ctx->r5) = ctx->r8;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800111e0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800111e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800111E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800111E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800111E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800111EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800111F0: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800111F4: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x800111F8: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x800111FC: beq         $t7, $at, L_80011248
    if (ctx->r15 == ctx->r1) {
        // 0x80011200: andi        $t8, $v0, 0xFDFF
        ctx->r24 = ctx->r2 & 0XFDFF;
            goto L_80011248;
    }
    // 0x80011200: andi        $t8, $v0, 0xFDFF
    ctx->r24 = ctx->r2 & 0XFDFF;
    // 0x80011204: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80011208: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8001120C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x80011210: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80011214: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80011218: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001121C: ori         $t1, $t0, 0x100
    ctx->r9 = ctx->r8 | 0X100;
    // 0x80011220: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
    // 0x80011224: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80011228: jal         0x8000F2B8
    // 0x8001122C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_0;
    // 0x8001122C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_0:
    // 0x80011230: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80011234: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x80011238: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001123C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80011240: jal         0x8000F2B8
    // 0x80011244: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_1;
    // 0x80011244: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_1:
L_80011248:
    // 0x80011248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001124C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011250: jr          $ra
    // 0x80011254: nop

    return;
    // 0x80011254: nop

;}
RECOMP_FUNC void FUN_80011258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001125C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011260: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80011264: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80011268: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001126C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80011270: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80011274: andi        $t7, $v0, 0x300
    ctx->r15 = ctx->r2 & 0X300;
    // 0x80011278: beq         $t7, $zero, L_8001129C
    if (ctx->r15 == 0) {
        // 0x8001127C: andi        $t8, $v0, 0xFCFF
        ctx->r24 = ctx->r2 & 0XFCFF;
            goto L_8001129C;
    }
    // 0x8001127C: andi        $t8, $v0, 0xFCFF
    ctx->r24 = ctx->r2 & 0XFCFF;
    // 0x80011280: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80011284: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80011288: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    // 0x8001128C: jal         0x8000F2B8
    // 0x80011290: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_0;
    // 0x80011290: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
    // 0x80011294: b           L_800112A0
    // 0x80011298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800112A0;
    // 0x80011298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001129C:
    // 0x8001129C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800112A0:
    // 0x800112A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800112A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800112A8: jr          $ra
    // 0x800112AC: nop

    return;
    // 0x800112AC: nop

;}
RECOMP_FUNC void FUN_800112b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800112B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800112B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800112B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800112BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800112C0: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800112C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800112C8: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x800112CC: beq         $t7, $at, L_80011318
    if (ctx->r15 == ctx->r1) {
        // 0x800112D0: andi        $t8, $v0, 0xFDFF
        ctx->r24 = ctx->r2 & 0XFDFF;
            goto L_80011318;
    }
    // 0x800112D0: andi        $t8, $v0, 0xFDFF
    ctx->r24 = ctx->r2 & 0XFDFF;
    // 0x800112D4: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800112D8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800112DC: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x800112E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800112E4: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800112E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800112EC: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x800112F0: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
    // 0x800112F4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800112F8: jal         0x8000F2B8
    // 0x800112FC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_0;
    // 0x800112FC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_0:
    // 0x80011300: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80011304: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80011308: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001130C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80011310: jal         0x8000F2B8
    // 0x80011314: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_1;
    // 0x80011314: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_1:
L_80011318:
    // 0x80011318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001131C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011320: jr          $ra
    // 0x80011324: nop

    return;
    // 0x80011324: nop

;}
RECOMP_FUNC void FUN_80011328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001132C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011330: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80011334: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80011338: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001133C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80011340: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80011344: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x80011348: beq         $t7, $zero, L_8001136C
    if (ctx->r15 == 0) {
        // 0x8001134C: andi        $t8, $v0, 0xFFFD
        ctx->r24 = ctx->r2 & 0XFFFD;
            goto L_8001136C;
    }
    // 0x8001134C: andi        $t8, $v0, 0xFFFD
    ctx->r24 = ctx->r2 & 0XFFFD;
    // 0x80011350: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80011354: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80011358: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001135C: jal         0x8000F2B8
    // 0x80011360: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_0;
    // 0x80011360: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
    // 0x80011364: b           L_80011370
    // 0x80011368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80011370;
    // 0x80011368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001136C:
    // 0x8001136C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011370:
    // 0x80011370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011378: jr          $ra
    // 0x8001137C: nop

    return;
    // 0x8001137C: nop

;}
RECOMP_FUNC void FUN_80011380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001138C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80011390: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80011394: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80011398: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001139C: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800113A0: beq         $t7, $at, L_800113C0
    if (ctx->r15 == ctx->r1) {
        // 0x800113A4: ori         $t8, $v0, 0x1
        ctx->r24 = ctx->r2 | 0X1;
            goto L_800113C0;
    }
    // 0x800113A4: ori         $t8, $v0, 0x1
    ctx->r24 = ctx->r2 | 0X1;
    // 0x800113A8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800113AC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800113B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800113B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800113B8: jal         0x8000F2B8
    // 0x800113BC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_0;
    // 0x800113BC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
L_800113C0:
    // 0x800113C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800113C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800113C8: jr          $ra
    // 0x800113CC: nop

    return;
    // 0x800113CC: nop

;}
RECOMP_FUNC void FUN_800113d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800113D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800113D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800113D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800113DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800113E0: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800113E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800113E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800113EC: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800113F0: beq         $t7, $zero, L_80011414
    if (ctx->r15 == 0) {
        // 0x800113F4: andi        $t8, $v0, 0xFFFE
        ctx->r24 = ctx->r2 & 0XFFFE;
            goto L_80011414;
    }
    // 0x800113F4: andi        $t8, $v0, 0xFFFE
    ctx->r24 = ctx->r2 & 0XFFFE;
    // 0x800113F8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800113FC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80011400: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80011404: jal         0x8000F2B8
    // 0x80011408: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_0;
    // 0x80011408: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
    // 0x8001140C: b           L_80011418
    // 0x80011410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80011418;
    // 0x80011410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80011414:
    // 0x80011414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011418:
    // 0x80011418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001141C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011420: jr          $ra
    // 0x80011424: nop

    return;
    // 0x80011424: nop

;}
RECOMP_FUNC void FUN_80011428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001142C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80011434: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80011438: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001143C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80011440: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80011444: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
    // 0x80011448: beq         $t7, $at, L_80011468
    if (ctx->r15 == ctx->r1) {
        // 0x8001144C: ori         $t8, $v0, 0x10
        ctx->r24 = ctx->r2 | 0X10;
            goto L_80011468;
    }
    // 0x8001144C: ori         $t8, $v0, 0x10
    ctx->r24 = ctx->r2 | 0X10;
    // 0x80011450: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80011454: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80011458: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8001145C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80011460: jal         0x8000F2B8
    // 0x80011464: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_0;
    // 0x80011464: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
L_80011468:
    // 0x80011468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001146C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011470: jr          $ra
    // 0x80011474: nop

    return;
    // 0x80011474: nop

;}
RECOMP_FUNC void FUN_80011478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001147C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011480: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80011484: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80011488: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8001148C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80011490: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80011494: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
    // 0x80011498: beq         $t7, $zero, L_800114BC
    if (ctx->r15 == 0) {
        // 0x8001149C: andi        $t8, $v0, 0xFFEF
        ctx->r24 = ctx->r2 & 0XFFEF;
            goto L_800114BC;
    }
    // 0x8001149C: andi        $t8, $v0, 0xFFEF
    ctx->r24 = ctx->r2 & 0XFFEF;
    // 0x800114A0: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800114A4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800114A8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800114AC: jal         0x8000F2B8
    // 0x800114B0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_0;
    // 0x800114B0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
    // 0x800114B4: b           L_800114C0
    // 0x800114B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800114C0;
    // 0x800114B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800114BC:
    // 0x800114BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800114C0:
    // 0x800114C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800114C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800114C8: jr          $ra
    // 0x800114CC: nop

    return;
    // 0x800114CC: nop

    // 0x800114D0: lhu         $t6, 0x4($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X4);
    // 0x800114D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800114D8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800114DC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800114E0: bgez        $t6, L_800114F8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800114E4: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_800114F8;
    }
    // 0x800114E4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800114E8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800114EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800114F0: nop

    // 0x800114F4: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_800114F8:
    // 0x800114F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800114FC: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80011500: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80011504: cvt.w.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_D(ctx->f6.d);
    // 0x80011508: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8001150C: nop

    // 0x80011510: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80011514: beql        $v0, $zero, L_80011578
    if (ctx->r2 == 0) {
        // 0x80011518: mfc1        $v0, $f10
        ctx->r2 = (int32_t)ctx->f10.u32l;
            goto L_80011578;
    }
    goto skip_0;
    // 0x80011518: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x8001151C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80011520: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80011524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011528: sub.d       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f6.d - ctx->f10.d;
    // 0x8001152C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80011530: nop

    // 0x80011534: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x80011538: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8001153C: nop

    // 0x80011540: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80011544: bnel        $v0, $zero, L_80011568
    if (ctx->r2 != 0) {
        // 0x80011548: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80011568;
    }
    goto skip_1;
    // 0x80011548: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x8001154C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80011550: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80011554: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80011558: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x8001155C: jr          $ra
    // 0x80011560: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x80011560: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80011564: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011568:
    // 0x80011568: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8001156C: jr          $ra
    // 0x80011570: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x80011570: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80011574: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
L_80011578:
    // 0x80011578: nop

    // 0x8001157C: bltzl       $v0, L_80011568
    if (SIGNED(ctx->r2) < 0) {
        // 0x80011580: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80011568;
    }
    goto skip_2;
    // 0x80011580: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_2:
    // 0x80011584: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80011588: jr          $ra
    // 0x8001158C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x8001158C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80011590(rdram, ctx);
;}
RECOMP_FUNC void FUN_80011590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011590: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80011594: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80011598: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8001159C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800115A0: bgez        $a0, L_800115BC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800115A4: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_800115BC;
    }
    // 0x800115A4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800115A8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800115AC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800115B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800115B4: nop

    // 0x800115B8: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_800115BC:
    // 0x800115BC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800115C0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800115C4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800115C8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800115CC: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800115D0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800115D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800115D8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800115DC: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800115E0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800115E4: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800115E8: nop

    // 0x800115EC: cvt.w.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_D(ctx->f4.d);
    // 0x800115F0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800115F4: nop

    // 0x800115F8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800115FC: beql        $v0, $zero, L_80011660
    if (ctx->r2 == 0) {
        // 0x80011600: mfc1        $v0, $f8
        ctx->r2 = (int32_t)ctx->f8.u32l;
            goto L_80011660;
    }
    goto skip_0;
    // 0x80011600: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80011604: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80011608: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001160C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011610: sub.d       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f4.d - ctx->f8.d;
    // 0x80011614: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80011618: nop

    // 0x8001161C: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x80011620: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80011624: nop

    // 0x80011628: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8001162C: bnel        $v0, $zero, L_80011650
    if (ctx->r2 != 0) {
        // 0x80011630: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80011650;
    }
    goto skip_1;
    // 0x80011630: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x80011634: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80011638: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001163C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80011640: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x80011644: jr          $ra
    // 0x80011648: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x80011648: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8001164C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011650:
    // 0x80011650: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80011654: jr          $ra
    // 0x80011658: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x80011658: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8001165C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
L_80011660:
    // 0x80011660: nop

    // 0x80011664: bltzl       $v0, L_80011650
    if (SIGNED(ctx->r2) < 0) {
        // 0x80011668: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80011650;
    }
    goto skip_2;
    // 0x80011668: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_2:
    // 0x8001166C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80011670: jr          $ra
    // 0x80011674: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x80011674: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80011678(rdram, ctx);
;}
RECOMP_FUNC void FUN_80011678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001167C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011680: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80011684: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80011688: lhu         $a0, 0x2($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X2);
    // 0x8001168C: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x80011690: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80011694: jal         0x8000522C
    // 0x80011698: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_0;
    // 0x80011698: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001169C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800116A0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800116A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800116A8: lw          $t1, 0x2C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X2C);
    // 0x800116AC: lw          $t6, 0x58($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X58);
    // 0x800116B0: beql        $v0, $t6, L_800116D4
    if (ctx->r2 == ctx->r14) {
        // 0x800116B4: lhu         $v1, 0x0($t3)
        ctx->r3 = MEM_HU(ctx->r11, 0X0);
            goto L_800116D4;
    }
    goto skip_0;
    // 0x800116B4: lhu         $v1, 0x0($t3)
    ctx->r3 = MEM_HU(ctx->r11, 0X0);
    skip_0:
    // 0x800116B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800116BC: nop

    // 0x800116C0: swc1        $f16, 0x54($t1)
    MEM_W(0X54, ctx->r9) = ctx->f16.u32l;
    // 0x800116C4: lw          $t7, 0x2C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X2C);
    // 0x800116C8: sw          $v0, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->r2;
    // 0x800116CC: lw          $t1, 0x2C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X2C);
    // 0x800116D0: lhu         $v1, 0x0($t3)
    ctx->r3 = MEM_HU(ctx->r11, 0X0);
L_800116D4:
    // 0x800116D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800116D8: andi        $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 & 0X7FFF;
    // 0x800116DC: beql        $v1, $zero, L_80011704
    if (ctx->r3 == 0) {
        // 0x800116E0: lwc1        $f10, 0x0($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
            goto L_80011704;
    }
    goto skip_1;
    // 0x800116E0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x800116E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800116E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800116EC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800116F0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800116F4: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800116F8: b           L_80011714
    // 0x800116FC: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
        goto L_80011714;
    // 0x800116FC: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80011700: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
L_80011704:
    // 0x80011704: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80011708: nop

    // 0x8001170C: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80011710: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
L_80011714:
    // 0x80011714: div.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80011718: lwc1        $f6, 0x54($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X54);
    // 0x8001171C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80011720: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80011724: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80011728: nop

    // 0x8001172C: bc1fl       L_8001173C
    if (!c1cs) {
        // 0x80011730: trunc.w.s   $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_8001173C;
    }
    goto skip_2;
    // 0x80011730: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_2:
    // 0x80011734: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80011738: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
L_8001173C:
    // 0x8001173C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80011740: nop

    // 0x80011744: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x80011748: sll         $t9, $a3, 3
    ctx->r25 = S32(ctx->r7 << 3);
    // 0x8001174C: subu        $t9, $t9, $a3
    ctx->r25 = SUB32(ctx->r25, ctx->r7);
    // 0x80011750: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80011754: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80011758: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8001175C: addiu       $a1, $t0, 0x4
    ctx->r5 = ADD32(ctx->r8, 0X4);
    // 0x80011760: addiu       $t2, $t0, 0x20
    ctx->r10 = ADD32(ctx->r8, 0X20);
    // 0x80011764: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x80011768: sub.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8001176C: bc1tl       L_80011844
    if (c1cs) {
        // 0x80011770: lwc1        $f8, 0x0($a1)
        ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
            goto L_80011844;
    }
    goto skip_3;
    // 0x80011770: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    skip_3:
    // 0x80011774: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80011778: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8001177C: addiu       $v1, $a1, 0x18
    ctx->r3 = ADD32(ctx->r5, 0X18);
    // 0x80011780: addiu       $a0, $t2, 0x18
    ctx->r4 = ADD32(ctx->r10, 0X18);
    // 0x80011784: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x80011788: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001178C: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80011790: swc1        $f8, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f8.u32l;
    // 0x80011794: lwc1        $f10, 0x4($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80011798: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001179C: lw          $t4, 0x2C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X2C);
    // 0x800117A0: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800117A4: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800117A8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800117AC: swc1        $f6, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f6.u32l;
    // 0x800117B0: lwc1        $f8, 0x8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X8);
    // 0x800117B4: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800117B8: lw          $t5, 0x2C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X2C);
    // 0x800117BC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800117C0: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800117C4: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x800117C8: swc1        $f4, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->f4.u32l;
    // 0x800117CC: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800117D0: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800117D4: lw          $t6, 0x2C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X2C);
    // 0x800117D8: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800117DC: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800117E0: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800117E4: swc1        $f18, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f18.u32l;
    // 0x800117E8: lwc1        $f4, 0x10($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X10);
    // 0x800117EC: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800117F0: lw          $t7, 0x2C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X2C);
    // 0x800117F4: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800117F8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800117FC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80011800: swc1        $f10, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f10.u32l;
    // 0x80011804: lwc1        $f18, 0x14($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80011808: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8001180C: lw          $t8, 0x2C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X2C);
    // 0x80011810: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80011814: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80011818: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8001181C: swc1        $f8, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f8.u32l;
    // 0x80011820: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80011824: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80011828: lw          $t9, 0x2C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X2C);
    // 0x8001182C: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80011830: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80011834: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80011838: b           L_80011890
    // 0x8001183C: swc1        $f6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f6.u32l;
        goto L_80011890;
    // 0x8001183C: swc1        $f6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f6.u32l;
    // 0x80011840: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
L_80011844:
    // 0x80011844: swc1        $f8, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f8.u32l;
    // 0x80011848: lw          $t4, 0x2C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X2C);
    // 0x8001184C: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80011850: swc1        $f10, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f10.u32l;
    // 0x80011854: lw          $t5, 0x2C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X2C);
    // 0x80011858: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001185C: swc1        $f18, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->f18.u32l;
    // 0x80011860: lw          $t6, 0x2C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X2C);
    // 0x80011864: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80011868: swc1        $f4, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f4.u32l;
    // 0x8001186C: lw          $t7, 0x2C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X2C);
    // 0x80011870: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80011874: swc1        $f6, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f6.u32l;
    // 0x80011878: lw          $t8, 0x2C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X2C);
    // 0x8001187C: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80011880: swc1        $f8, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f8.u32l;
    // 0x80011884: lw          $t9, 0x2C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X2C);
    // 0x80011888: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8001188C: swc1        $f10, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f10.u32l;
L_80011890:
    // 0x80011890: lw          $t1, 0x2C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X2C);
    // 0x80011894: lwc1        $f0, 0x54($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X54);
    // 0x80011898: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x8001189C: nop

    // 0x800118A0: bc1fl       L_800118DC
    if (!c1cs) {
        // 0x800118A4: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_800118DC;
    }
    goto skip_4;
    // 0x800118A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_4:
    // 0x800118A8: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x800118AC: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x800118B0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800118B4: nop

    // 0x800118B8: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800118BC: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x800118C0: nop

    // 0x800118C4: bc1t        L_800118D0
    if (c1cs) {
        // 0x800118C8: nop
    
            goto L_800118D0;
    }
    // 0x800118C8: nop

    // 0x800118CC: swc1        $f16, 0x54($t1)
    MEM_W(0X54, ctx->r9) = ctx->f16.u32l;
L_800118D0:
    // 0x800118D0: b           L_800118E8
    // 0x800118D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800118E8;
    // 0x800118D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800118D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_800118DC:
    // 0x800118DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800118E0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800118E4: swc1        $f6, 0x54($t1)
    MEM_W(0X54, ctx->r9) = ctx->f6.u32l;
L_800118E8:
    // 0x800118E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800118EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800118F0: jr          $ra
    // 0x800118F4: nop

    return;
    // 0x800118F4: nop

    // 0x800118F8: nop

    // 0x800118FC: nop

;}
RECOMP_FUNC void FUN_80011900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011908: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001190C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80011910: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80011914: sb          $t6, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r14;
    // 0x80011918: lw          $a1, 0x30($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X30);
    // 0x8001191C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80011920: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80011924: jal         0x800317D0
    // 0x80011928: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    LOOKUP_FUNC(0x800317D0)(rdram, ctx);
        goto after_0;
    // 0x80011928: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_0:
    // 0x8001192C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80011930: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80011934: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80011938: lw          $t7, 0x30($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X30);
    // 0x8001193C: swc1        $f0, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f0.u32l;
    // 0x80011940: lw          $t8, 0x30($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X30);
    // 0x80011944: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x80011948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001194C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011950: jr          $ra
    // 0x80011954: nop

    return;
    // 0x80011954: nop

;}
RECOMP_FUNC void FUN_80011958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011958: addiu       $sp, $sp, -0x250
    ctx->r29 = ADD32(ctx->r29, -0X250);
    // 0x8001195C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011960: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x80011964: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80011968: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8001196C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80011970: addiu       $t6, $sp, 0x214
    ctx->r14 = ADD32(ctx->r29, 0X214);
    // 0x80011974: addiu       $at, $t7, 0x3C
    ctx->r1 = ADD32(ctx->r15, 0X3C);
L_80011978:
    // 0x80011978: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001197C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80011980: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80011984: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80011988: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8001198C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80011990: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80011994: bne         $t7, $at, L_80011978
    if (ctx->r15 != ctx->r1) {
        // 0x80011998: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80011978;
    }
    // 0x80011998: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8001199C: lh          $t7, 0x218($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X218);
    // 0x800119A0: lwc1        $f4, 0x248($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X248);
    // 0x800119A4: lh          $t9, 0x21A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X21A);
    // 0x800119A8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800119AC: swc1        $f4, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = ctx->f4.u32l;
    // 0x800119B0: lwc1        $f6, 0x24C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24C);
    // 0x800119B4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800119B8: swc1        $f6, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->f6.u32l;
    // 0x800119BC: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800119C0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800119C4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800119C8: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800119CC: add.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f18.d + ctx->f0.d;
    // 0x800119D0: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800119D4: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x800119D8: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800119DC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800119E0: add.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d + ctx->f0.d;
    // 0x800119E4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800119E8: sra         $t7, $t9, 16
    ctx->r15 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800119EC: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800119F0: sh          $t8, 0x218($sp)
    MEM_H(0X218, ctx->r29) = ctx->r24;
    // 0x800119F4: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x800119F8: beq         $t7, $zero, L_80013720
    if (ctx->r15 == 0) {
        // 0x800119FC: sh          $t6, 0x21A($sp)
        MEM_H(0X21A, ctx->r29) = ctx->r14;
            goto L_80013720;
    }
    // 0x800119FC: sh          $t6, 0x21A($sp)
    MEM_H(0X21A, ctx->r29) = ctx->r14;
    // 0x80011A00: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80011A04: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80011A08: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80011A0C: beq         $a0, $zero, L_80013720
    if (ctx->r4 == 0) {
        // 0x80011A10: lh          $v0, 0x214($sp)
        ctx->r2 = MEM_H(ctx->r29, 0X214);
            goto L_80013720;
    }
    // 0x80011A10: lh          $v0, 0x214($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X214);
    // 0x80011A14: lh          $v1, 0x216($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X216);
    // 0x80011A18: lh          $t8, 0x218($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X218);
    // 0x80011A1C: sh          $v0, 0x212($sp)
    MEM_H(0X212, ctx->r29) = ctx->r2;
    // 0x80011A20: addu        $t7, $v1, $a0
    ctx->r15 = ADD32(ctx->r3, ctx->r4);
    // 0x80011A24: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80011A28: sh          $t9, 0x20E($sp)
    MEM_H(0X20E, ctx->r29) = ctx->r25;
    // 0x80011A2C: sh          $t7, 0x20C($sp)
    MEM_H(0X20C, ctx->r29) = ctx->r15;
    // 0x80011A30: jal         0x80001060
    // 0x80011A34: sh          $v1, 0x210($sp)
    MEM_H(0X210, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x80011A34: sh          $v1, 0x210($sp)
    MEM_H(0X210, ctx->r29) = ctx->r3;
    after_0:
    // 0x80011A38: beq         $v0, $zero, L_80011AA0
    if (ctx->r2 == 0) {
        // 0x80011A3C: lh          $t6, 0x212($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X212);
            goto L_80011AA0;
    }
    // 0x80011A3C: lh          $t6, 0x212($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X212);
    // 0x80011A40: lh          $t9, 0x20E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X20E);
    // 0x80011A44: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80011A48: lh          $t6, 0x210($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X210);
    // 0x80011A4C: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80011A50: sh          $t7, 0x20E($sp)
    MEM_H(0X20E, ctx->r29) = ctx->r15;
    // 0x80011A54: lh          $t7, 0x20C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X20C);
    // 0x80011A58: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x80011A5C: sh          $t8, 0x212($sp)
    MEM_H(0X212, ctx->r29) = ctx->r24;
    // 0x80011A60: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x80011A64: sh          $t6, 0x20C($sp)
    MEM_H(0X20C, ctx->r29) = ctx->r14;
    // 0x80011A68: addiu       $t7, $zero, 0x200
    ctx->r15 = ADD32(0, 0X200);
    // 0x80011A6C: sh          $t7, 0x1D6($sp)
    MEM_H(0X1D6, ctx->r29) = ctx->r15;
    // 0x80011A70: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80011A74: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80011A78: slti        $at, $t7, 0x280
    ctx->r1 = SIGNED(ctx->r15) < 0X280 ? 1 : 0;
    // 0x80011A7C: beq         $at, $zero, L_80013720
    if (ctx->r1 == 0) {
        // 0x80011A80: sh          $t9, 0x210($sp)
        MEM_H(0X210, ctx->r29) = ctx->r25;
            goto L_80013720;
    }
    // 0x80011A80: sh          $t9, 0x210($sp)
    MEM_H(0X210, ctx->r29) = ctx->r25;
    // 0x80011A84: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80011A88: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80011A8C: slti        $at, $t6, 0x1E0
    ctx->r1 = SIGNED(ctx->r14) < 0X1E0 ? 1 : 0;
    // 0x80011A90: bnel        $at, $zero, L_80011AC8
    if (ctx->r1 != 0) {
        // 0x80011A94: lhu         $a1, 0x224($sp)
        ctx->r5 = MEM_HU(ctx->r29, 0X224);
            goto L_80011AC8;
    }
    goto skip_0;
    // 0x80011A94: lhu         $a1, 0x224($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X224);
    skip_0:
    // 0x80011A98: b           L_80013724
    // 0x80011A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80013724;
    // 0x80011A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011AA0:
    // 0x80011AA0: lh          $t9, 0x212($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X212);
    // 0x80011AA4: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x80011AA8: sh          $t7, 0x1D6($sp)
    MEM_H(0X1D6, ctx->r29) = ctx->r15;
    // 0x80011AAC: slti        $at, $t9, 0x140
    ctx->r1 = SIGNED(ctx->r25) < 0X140 ? 1 : 0;
    // 0x80011AB0: beq         $at, $zero, L_80013720
    if (ctx->r1 == 0) {
        // 0x80011AB4: lh          $t8, 0x210($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X210);
            goto L_80013720;
    }
    // 0x80011AB4: lh          $t8, 0x210($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X210);
    // 0x80011AB8: slti        $at, $t8, 0xF0
    ctx->r1 = SIGNED(ctx->r24) < 0XF0 ? 1 : 0;
    // 0x80011ABC: beql        $at, $zero, L_80013724
    if (ctx->r1 == 0) {
        // 0x80011AC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80013724;
    }
    goto skip_1;
    // 0x80011AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80011AC4: lhu         $a1, 0x224($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X224);
L_80011AC8:
    // 0x80011AC8: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x80011ACC: andi        $t6, $a1, 0x4
    ctx->r14 = ctx->r5 & 0X4;
    // 0x80011AD0: beql        $t6, $zero, L_800130C4
    if (ctx->r14 == 0) {
        // 0x80011AD4: andi        $t6, $a1, 0x2
        ctx->r14 = ctx->r5 & 0X2;
            goto L_800130C4;
    }
    goto skip_2;
    // 0x80011AD4: andi        $t6, $a1, 0x2
    ctx->r14 = ctx->r5 & 0X2;
    skip_2:
    // 0x80011AD8: beq         $t7, $zero, L_800130C0
    if (ctx->r15 == 0) {
        // 0x80011ADC: lhu         $t9, 0x23E($sp)
        ctx->r25 = MEM_HU(ctx->r29, 0X23E);
            goto L_800130C0;
    }
    // 0x80011ADC: lhu         $t9, 0x23E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23E);
    // 0x80011AE0: beq         $t9, $zero, L_800130C0
    if (ctx->r25 == 0) {
        // 0x80011AE4: andi        $t8, $a1, 0x2000
        ctx->r24 = ctx->r5 & 0X2000;
            goto L_800130C0;
    }
    // 0x80011AE4: andi        $t8, $a1, 0x2000
    ctx->r24 = ctx->r5 & 0X2000;
    // 0x80011AE8: beq         $t8, $zero, L_80011B18
    if (ctx->r24 == 0) {
        // 0x80011AEC: lui         $t0, 0x8009
        ctx->r8 = S32(0X8009 << 16);
            goto L_80011B18;
    }
    // 0x80011AEC: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80011AF0: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x80011AF4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011AF8: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80011AFC: addiu       $t9, $t9, 0x37E0
    ctx->r25 = ADD32(ctx->r25, 0X37E0);
    // 0x80011B00: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80011B04: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80011B08: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80011B0C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80011B10: b           L_80011B40
    // 0x80011B14: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80011B40;
    // 0x80011B14: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80011B18:
    // 0x80011B18: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80011B1C: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x80011B20: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011B24: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80011B28: addiu       $t7, $t7, 0x3790
    ctx->r15 = ADD32(ctx->r15, 0X3790);
    // 0x80011B2C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80011B30: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80011B34: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x80011B38: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80011B3C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80011B40:
    // 0x80011B40: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011B44: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80011B48: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80011B4C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80011B50: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80011B54: lbu         $t7, 0x21C($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X21C);
    // 0x80011B58: lbu         $t6, 0x21D($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X21D);
    // 0x80011B5C: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x80011B60: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80011B64: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80011B68: lbu         $t9, 0x21E($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X21E);
    // 0x80011B6C: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x80011B70: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80011B74: lbu         $t8, 0x21F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X21F);
    // 0x80011B78: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80011B7C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80011B80: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011B84: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x80011B88: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80011B8C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80011B90: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80011B94: lbu         $t7, 0x220($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X220);
    // 0x80011B98: lbu         $t8, 0x221($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X221);
    // 0x80011B9C: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x80011BA0: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80011BA4: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80011BA8: lbu         $t9, 0x222($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X222);
    // 0x80011BAC: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x80011BB0: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80011BB4: lbu         $t6, 0x223($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X223);
    // 0x80011BB8: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80011BBC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80011BC0: lhu         $a1, 0x224($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X224);
    // 0x80011BC4: andi        $t9, $a1, 0x2000
    ctx->r25 = ctx->r5 & 0X2000;
    // 0x80011BC8: beq         $t9, $zero, L_80011C4C
    if (ctx->r25 == 0) {
        // 0x80011BCC: andi        $t7, $a1, 0x2
        ctx->r15 = ctx->r5 & 0X2;
            goto L_80011C4C;
    }
    // 0x80011BCC: andi        $t7, $a1, 0x2
    ctx->r15 = ctx->r5 & 0X2;
    // 0x80011BD0: andi        $t8, $a1, 0x2
    ctx->r24 = ctx->r5 & 0X2;
    // 0x80011BD4: bne         $t8, $zero, L_80011C04
    if (ctx->r24 != 0) {
        // 0x80011BD8: lui         $t6, 0xE200
        ctx->r14 = S32(0XE200 << 16);
            goto L_80011C04;
    }
    // 0x80011BD8: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x80011BDC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011BE0: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80011BE4: lui         $t9, 0xF0A
    ctx->r25 = S32(0XF0A << 16);
    // 0x80011BE8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80011BEC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80011BF0: ori         $t9, $t9, 0x7008
    ctx->r25 = ctx->r25 | 0X7008;
    // 0x80011BF4: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80011BF8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80011BFC: b           L_80011C24
    // 0x80011C00: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80011C24;
    // 0x80011C00: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80011C04:
    // 0x80011C04: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011C08: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x80011C0C: ori         $t7, $t7, 0x4240
    ctx->r15 = ctx->r15 | 0X4240;
    // 0x80011C10: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80011C14: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80011C18: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x80011C1C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80011C20: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80011C24:
    // 0x80011C24: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011C28: lui         $t8, 0xFC25
    ctx->r24 = S32(0XFC25 << 16);
    // 0x80011C2C: lui         $t6, 0x1FFC
    ctx->r14 = S32(0X1FFC << 16);
    // 0x80011C30: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80011C34: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80011C38: ori         $t6, $t6, 0x9238
    ctx->r14 = ctx->r14 | 0X9238;
    // 0x80011C3C: ori         $t8, $t8, 0x27FF
    ctx->r24 = ctx->r24 | 0X27FF;
    // 0x80011C40: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80011C44: b           L_80011D18
    // 0x80011C48: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
        goto L_80011D18;
    // 0x80011C48: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80011C4C:
    // 0x80011C4C: bne         $t7, $zero, L_80011CA0
    if (ctx->r15 != 0) {
        // 0x80011C50: lui         $t9, 0x50
        ctx->r25 = S32(0X50 << 16);
            goto L_80011CA0;
    }
    // 0x80011C50: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80011C54: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011C58: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80011C5C: lui         $t6, 0xF0A
    ctx->r14 = S32(0XF0A << 16);
    // 0x80011C60: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80011C64: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80011C68: ori         $t6, $t6, 0x7008
    ctx->r14 = ctx->r14 | 0X7008;
    // 0x80011C6C: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80011C70: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80011C74: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80011C78: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011C7C: lui         $t8, 0xFFFC
    ctx->r24 = S32(0XFFFC << 16);
    // 0x80011C80: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80011C84: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80011C88: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80011C8C: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80011C90: ori         $t8, $t8, 0xF279
    ctx->r24 = ctx->r24 | 0XF279;
    // 0x80011C94: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80011C98: b           L_80011D18
    // 0x80011C9C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_80011D18;
    // 0x80011C9C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80011CA0:
    // 0x80011CA0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011CA4: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80011CA8: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80011CAC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80011CB0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80011CB4: ori         $t9, $t9, 0x4240
    ctx->r25 = ctx->r25 | 0X4240;
    // 0x80011CB8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80011CBC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80011CC0: lhu         $t8, 0x224($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X224);
    // 0x80011CC4: lui         $t7, 0xFC30
    ctx->r15 = S32(0XFC30 << 16);
    // 0x80011CC8: lui         $t9, 0xFC30
    ctx->r25 = S32(0XFC30 << 16);
    // 0x80011CCC: andi        $t6, $t8, 0x40
    ctx->r14 = ctx->r24 & 0X40;
    // 0x80011CD0: beq         $t6, $zero, L_80011CFC
    if (ctx->r14 == 0) {
        // 0x80011CD4: ori         $t7, $t7, 0xB261
        ctx->r15 = ctx->r15 | 0XB261;
            goto L_80011CFC;
    }
    // 0x80011CD4: ori         $t7, $t7, 0xB261
    ctx->r15 = ctx->r15 | 0XB261;
    // 0x80011CD8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011CDC: lui         $t8, 0x5566
    ctx->r24 = S32(0X5566 << 16);
    // 0x80011CE0: ori         $t8, $t8, 0xFF7F
    ctx->r24 = ctx->r24 | 0XFF7F;
    // 0x80011CE4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80011CE8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80011CEC: ori         $t9, $t9, 0xB261
    ctx->r25 = ctx->r25 | 0XB261;
    // 0x80011CF0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80011CF4: b           L_80011D18
    // 0x80011CF8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
        goto L_80011D18;
    // 0x80011CF8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_80011CFC:
    // 0x80011CFC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011D00: lui         $t9, 0xFF67
    ctx->r25 = S32(0XFF67 << 16);
    // 0x80011D04: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80011D08: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80011D0C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80011D10: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80011D14: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80011D18:
    // 0x80011D18: lhu         $a1, 0x224($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X224);
    // 0x80011D1C: andi        $t8, $a1, 0x2000
    ctx->r24 = ctx->r5 & 0X2000;
    // 0x80011D20: beq         $t8, $zero, L_800122C8
    if (ctx->r24 == 0) {
        // 0x80011D24: andi        $t6, $a1, 0x20
        ctx->r14 = ctx->r5 & 0X20;
            goto L_800122C8;
    }
    // 0x80011D24: andi        $t6, $a1, 0x20
    ctx->r14 = ctx->r5 & 0X20;
    // 0x80011D28: beql        $t6, $zero, L_80011FF8
    if (ctx->r14 == 0) {
        // 0x80011D2C: lw          $v1, 0x0($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X0);
            goto L_80011FF8;
    }
    goto skip_3;
    // 0x80011D2C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    skip_3:
    // 0x80011D30: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011D34: lhu         $t9, 0x23C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23C);
    // 0x80011D38: lui         $at, 0xFD68
    ctx->r1 = S32(0XFD68 << 16);
    // 0x80011D3C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80011D40: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80011D44: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80011D48: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80011D4C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80011D50: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80011D54: lw          $a1, 0x230($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X230);
    // 0x80011D58: lhu         $a0, 0x22C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22C);
    // 0x80011D5C: jal         0x8000522C
    // 0x80011D60: sw          $v1, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_1;
    // 0x80011D60: sw          $v1, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r3;
    after_1:
    // 0x80011D64: lw          $t3, 0x1A0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A0);
    // 0x80011D68: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80011D6C: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x80011D70: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x80011D74: lhu         $t8, 0x23C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X23C);
    // 0x80011D78: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011D7C: lui         $ra, 0xF568
    ctx->r31 = S32(0XF568 << 16);
    // 0x80011D80: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x80011D84: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80011D88: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80011D8C: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80011D90: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x80011D94: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x80011D98: or          $t6, $t8, $ra
    ctx->r14 = ctx->r24 | ctx->r31;
    // 0x80011D9C: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x80011DA0: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80011DA4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80011DA8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011DAC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80011DB0: lui         $t6, 0xF400
    ctx->r14 = S32(0XF400 << 16);
    // 0x80011DB4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80011DB8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80011DBC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80011DC0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80011DC4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011DC8: lui         $at, 0xFD68
    ctx->r1 = S32(0XFD68 << 16);
    // 0x80011DCC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80011DD0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80011DD4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80011DD8: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x80011DDC: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80011DE0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80011DE4: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80011DE8: lhu         $t8, 0x23E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X23E);
    // 0x80011DEC: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80011DF0: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x80011DF4: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80011DF8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80011DFC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80011E00: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80011E04: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80011E08: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011E0C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80011E10: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80011E14: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80011E18: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80011E1C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80011E20: lhu         $t6, 0x23C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23C);
    // 0x80011E24: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011E28: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x80011E2C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80011E30: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80011E34: sra         $t9, $t7, 3
    ctx->r25 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80011E38: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x80011E3C: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x80011E40: or          $t7, $t6, $ra
    ctx->r15 = ctx->r14 | ctx->r31;
    // 0x80011E44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80011E48: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80011E4C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011E50: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80011E54: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80011E58: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80011E5C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80011E60: lhu         $t6, 0x23C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23C);
    // 0x80011E64: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80011E68: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80011E6C: lhu         $t7, 0x23E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23E);
    // 0x80011E70: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80011E74: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80011E78: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80011E7C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80011E80: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80011E84: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80011E88: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80011E8C: lhu         $t6, 0x23C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23C);
    // 0x80011E90: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011E94: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80011E98: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80011E9C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80011EA0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80011EA4: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80011EA8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80011EAC: lw          $a1, 0x238($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X238);
    // 0x80011EB0: lhu         $a0, 0x234($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X234);
    // 0x80011EB4: jal         0x8000522C
    // 0x80011EB8: sw          $v1, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_2;
    // 0x80011EB8: sw          $v1, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r3;
    after_2:
    // 0x80011EBC: lw          $t3, 0x184($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X184);
    // 0x80011EC0: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80011EC4: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x80011EC8: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x80011ECC: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x80011ED0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011ED4: lui         $ra, 0xF568
    ctx->r31 = S32(0XF568 << 16);
    // 0x80011ED8: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x80011EDC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80011EE0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80011EE4: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80011EE8: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x80011EEC: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x80011EF0: or          $t9, $t7, $ra
    ctx->r25 = ctx->r15 | ctx->r31;
    // 0x80011EF4: ori         $t8, $t9, 0x100
    ctx->r24 = ctx->r25 | 0X100;
    // 0x80011EF8: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x80011EFC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80011F00: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80011F04: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011F08: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80011F0C: lui         $t8, 0xF400
    ctx->r24 = S32(0XF400 << 16);
    // 0x80011F10: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80011F14: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80011F18: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80011F1C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80011F20: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011F24: lui         $t4, 0x100
    ctx->r12 = S32(0X100 << 16);
    // 0x80011F28: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80011F2C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80011F30: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80011F34: lhu         $t6, 0x23C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23C);
    // 0x80011F38: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80011F3C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80011F40: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80011F44: lhu         $t9, 0x23E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23E);
    // 0x80011F48: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80011F4C: or          $t7, $t6, $t5
    ctx->r15 = ctx->r14 | ctx->r13;
    // 0x80011F50: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80011F54: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80011F58: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80011F5C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80011F60: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80011F64: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011F68: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80011F6C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80011F70: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80011F74: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80011F78: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80011F7C: lhu         $t8, 0x23C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X23C);
    // 0x80011F80: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011F84: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x80011F88: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80011F8C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80011F90: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80011F94: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x80011F98: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x80011F9C: or          $t6, $t8, $ra
    ctx->r14 = ctx->r24 | ctx->r31;
    // 0x80011FA0: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x80011FA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80011FA8: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80011FAC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80011FB0: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80011FB4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80011FB8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80011FBC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80011FC0: lhu         $t6, 0x23C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23C);
    // 0x80011FC4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80011FC8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80011FCC: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80011FD0: lhu         $t9, 0x23E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23E);
    // 0x80011FD4: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80011FD8: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x80011FDC: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80011FE0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80011FE4: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80011FE8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80011FEC: b           L_80012D48
    // 0x80011FF0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
        goto L_80012D48;
    // 0x80011FF0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80011FF4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
L_80011FF8:
    // 0x80011FF8: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x80011FFC: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x80012000: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80012004: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80012008: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8001200C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80012010: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80012014: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80012018: lw          $a1, 0x230($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X230);
    // 0x8001201C: lhu         $a0, 0x22C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22C);
    // 0x80012020: jal         0x8000522C
    // 0x80012024: sw          $v1, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_3;
    // 0x80012024: sw          $v1, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r3;
    after_3:
    // 0x80012028: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x8001202C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80012030: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x80012034: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x80012038: lhu         $t9, 0x23C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23C);
    // 0x8001203C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012040: lui         $t4, 0xF510
    ctx->r12 = S32(0XF510 << 16);
    // 0x80012044: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x80012048: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8001204C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80012050: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x80012054: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80012058: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x8001205C: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x80012060: or          $t6, $t8, $t4
    ctx->r14 = ctx->r24 | ctx->r12;
    // 0x80012064: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x80012068: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8001206C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80012070: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012074: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80012078: lui         $t6, 0xF400
    ctx->r14 = S32(0XF400 << 16);
    // 0x8001207C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80012080: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80012084: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80012088: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8001208C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012090: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x80012094: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80012098: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8001209C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800120A0: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x800120A4: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x800120A8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800120AC: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x800120B0: lhu         $t8, 0x23E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X23E);
    // 0x800120B4: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800120B8: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x800120BC: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800120C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800120C4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800120C8: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800120CC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800120D0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800120D4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800120D8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800120DC: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800120E0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800120E4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800120E8: lhu         $t6, 0x23C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23C);
    // 0x800120EC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800120F0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800120F4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800120F8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800120FC: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x80012100: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80012104: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x80012108: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x8001210C: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x80012110: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80012114: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012118: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001211C: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80012120: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80012124: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80012128: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001212C: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012130: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80012134: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80012138: lhu         $t9, 0x23E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23E);
    // 0x8001213C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80012140: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80012144: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80012148: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8001214C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80012150: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80012154: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80012158: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x8001215C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012160: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80012164: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80012168: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8001216C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80012170: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80012174: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80012178: lw          $a1, 0x238($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X238);
    // 0x8001217C: lhu         $a0, 0x234($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X234);
    // 0x80012180: jal         0x8000522C
    // 0x80012184: sw          $v1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_4;
    // 0x80012184: sw          $v1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r3;
    after_4:
    // 0x80012188: lw          $t3, 0x14C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14C);
    // 0x8001218C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80012190: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x80012194: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x80012198: lhu         $t9, 0x23C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23C);
    // 0x8001219C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800121A0: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x800121A4: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800121A8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800121AC: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800121B0: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x800121B4: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800121B8: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x800121BC: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x800121C0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800121C4: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x800121C8: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
    // 0x800121CC: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x800121D0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800121D4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800121D8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800121DC: lui         $t7, 0xF400
    ctx->r15 = S32(0XF400 << 16);
    // 0x800121E0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800121E4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800121E8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800121EC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800121F0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800121F4: lui         $t4, 0x100
    ctx->r12 = S32(0X100 << 16);
    // 0x800121F8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800121FC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80012200: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80012204: lhu         $t9, 0x23C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012208: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x8001220C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80012210: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80012214: lhu         $t6, 0x23E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23E);
    // 0x80012218: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8001221C: or          $t8, $t9, $ra
    ctx->r24 = ctx->r25 | ctx->r31;
    // 0x80012220: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80012224: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80012228: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8001222C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80012230: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80012234: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012238: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8001223C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80012240: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80012244: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012248: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001224C: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012250: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012254: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80012258: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8001225C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80012260: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x80012264: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80012268: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8001226C: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x80012270: or          $t8, $t9, $t5
    ctx->r24 = ctx->r25 | ctx->r13;
    // 0x80012274: ori         $t6, $t8, 0x100
    ctx->r14 = ctx->r24 | 0X100;
    // 0x80012278: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001227C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80012280: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012284: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80012288: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8001228C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80012290: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80012294: lhu         $t8, 0x23C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012298: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x8001229C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800122A0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800122A4: lhu         $t7, 0x23E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23E);
    // 0x800122A8: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800122AC: or          $t6, $t8, $t4
    ctx->r14 = ctx->r24 | ctx->r12;
    // 0x800122B0: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x800122B4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800122B8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x800122BC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800122C0: b           L_80012D48
    // 0x800122C4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80012D48;
    // 0x800122C4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_800122C8:
    // 0x800122C8: andi        $t8, $a1, 0x10
    ctx->r24 = ctx->r5 & 0X10;
    // 0x800122CC: beq         $t8, $zero, L_8001272C
    if (ctx->r24 == 0) {
        // 0x800122D0: lhu         $t7, 0x23C($sp)
        ctx->r15 = MEM_HU(ctx->r29, 0X23C);
            goto L_8001272C;
    }
    // 0x800122D0: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x800122D4: sll         $v0, $t7, 16
    ctx->r2 = S32(ctx->r15 << 16);
    // 0x800122D8: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x800122DC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800122E0: bne         $t9, $zero, L_80012304
    if (ctx->r25 != 0) {
        // 0x800122E4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80012304;
    }
    // 0x800122E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800122E8:
    // 0x800122E8: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800122EC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800122F0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800122F4: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800122F8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800122FC: beq         $t8, $zero, L_800122E8
    if (ctx->r24 == 0) {
        // 0x80012300: andi        $a3, $a3, 0xFFFF
        ctx->r7 = ctx->r7 & 0XFFFF;
            goto L_800122E8;
    }
    // 0x80012300: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
L_80012304:
    // 0x80012304: lhu         $t7, 0x23E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23E);
    // 0x80012308: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001230C: andi        $t6, $a1, 0x20
    ctx->r14 = ctx->r5 & 0X20;
    // 0x80012310: sll         $v0, $t7, 16
    ctx->r2 = S32(ctx->r15 << 16);
    // 0x80012314: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x80012318: bne         $t9, $zero, L_8001233C
    if (ctx->r25 != 0) {
        // 0x8001231C: sra         $v0, $v0, 16
        ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
            goto L_8001233C;
    }
    // 0x8001231C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80012320:
    // 0x80012320: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80012324: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80012328: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001232C: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80012330: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80012334: beq         $t8, $zero, L_80012320
    if (ctx->r24 == 0) {
        // 0x80012338: andi        $a2, $a2, 0xFFFF
        ctx->r6 = ctx->r6 & 0XFFFF;
            goto L_80012320;
    }
    // 0x80012338: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
L_8001233C:
    // 0x8001233C: beql        $t6, $zero, L_80012540
    if (ctx->r14 == 0) {
        // 0x80012340: lw          $v1, 0x0($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X0);
            goto L_80012540;
    }
    goto skip_4;
    // 0x80012340: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    skip_4:
    // 0x80012344: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012348: lui         $t9, 0xFD70
    ctx->r25 = S32(0XFD70 << 16);
    // 0x8001234C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80012350: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80012354: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80012358: sh          $a3, 0x1DE($sp)
    MEM_H(0X1DE, ctx->r29) = ctx->r7;
    // 0x8001235C: sh          $a2, 0x1DC($sp)
    MEM_H(0X1DC, ctx->r29) = ctx->r6;
    // 0x80012360: lw          $a1, 0x230($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X230);
    // 0x80012364: lhu         $a0, 0x22C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22C);
    // 0x80012368: jal         0x8000522C
    // 0x8001236C: sw          $v1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_5;
    // 0x8001236C: sw          $v1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r3;
    after_5:
    // 0x80012370: lw          $t3, 0x130($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X130);
    // 0x80012374: lhu         $a2, 0x1DC($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1DC);
    // 0x80012378: lhu         $a3, 0x1DE($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X1DE);
    // 0x8001237C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80012380: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x80012384: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x80012388: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8001238C: andi        $t4, $a2, 0xF
    ctx->r12 = ctx->r6 & 0XF;
    // 0x80012390: sll         $t4, $t4, 14
    ctx->r12 = S32(ctx->r12 << 14);
    // 0x80012394: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80012398: andi        $t5, $a3, 0xF
    ctx->r13 = ctx->r7 & 0XF;
    // 0x8001239C: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x800123A0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800123A4: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800123A8: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x800123AC: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x800123B0: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x800123B4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800123B8: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800123BC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800123C0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800123C4: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x800123C8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800123CC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800123D0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800123D4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800123D8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800123DC: lui         $ra, 0xF568
    ctx->r31 = S32(0XF568 << 16);
    // 0x800123E0: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x800123E4: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x800123E8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800123EC: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x800123F0: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x800123F4: lhu         $t6, 0x23E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23E);
    // 0x800123F8: lhu         $a0, 0x23C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X23C);
    // 0x800123FC: multu       $a0, $t6
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80012400: mflo        $t2
    ctx->r10 = lo;
    // 0x80012404: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80012408: sra         $t2, $t2, 1
    ctx->r10 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8001240C: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80012410: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x80012414: beq         $at, $zero, L_80012424
    if (ctx->r1 == 0) {
        // 0x80012418: nop
    
            goto L_80012424;
    }
    // 0x80012418: nop

    // 0x8001241C: b           L_80012424
    // 0x80012420: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_80012424;
    // 0x80012420: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_80012424:
    // 0x80012424: bgez        $a0, L_80012434
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80012428: sra         $v1, $a0, 3
        ctx->r3 = S32(SIGNED(ctx->r4) >> 3);
            goto L_80012434;
    }
    // 0x80012428: sra         $v1, $a0, 3
    ctx->r3 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8001242C: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x80012430: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_80012434:
    // 0x80012434: bgtz        $v1, L_80012444
    if (SIGNED(ctx->r3) > 0) {
        // 0x80012438: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80012444;
    }
    // 0x80012438: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8001243C: b           L_80012444
    // 0x80012440: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80012444;
    // 0x80012440: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80012444:
    // 0x80012444: bgtz        $v1, L_80012454
    if (SIGNED(ctx->r3) > 0) {
        // 0x80012448: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_80012454;
    }
    // 0x80012448: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x8001244C: b           L_80012458
    // 0x80012450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80012458;
    // 0x80012450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80012454:
    // 0x80012454: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80012458:
    // 0x80012458: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x8001245C: bne         $v0, $zero, L_80012468
    if (ctx->r2 != 0) {
        // 0x80012460: nop
    
            goto L_80012468;
    }
    // 0x80012460: nop

    // 0x80012464: break       7
    do_break(2147558500);
L_80012468:
    // 0x80012468: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001246C: bne         $v0, $at, L_80012480
    if (ctx->r2 != ctx->r1) {
        // 0x80012470: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80012480;
    }
    // 0x80012470: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80012474: bne         $t7, $at, L_80012480
    if (ctx->r15 != ctx->r1) {
        // 0x80012478: nop
    
            goto L_80012480;
    }
    // 0x80012478: nop

    // 0x8001247C: break       6
    do_break(2147558524);
L_80012480:
    // 0x80012480: mflo        $t9
    ctx->r25 = lo;
    // 0x80012484: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80012488: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x8001248C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80012490: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x80012494: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80012498: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8001249C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800124A0: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x800124A4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800124A8: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800124AC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800124B0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800124B4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800124B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800124BC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800124C0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800124C4: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x800124C8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800124CC: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x800124D0: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800124D4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800124D8: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x800124DC: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x800124E0: or          $t6, $t7, $ra
    ctx->r14 = ctx->r15 | ctx->r31;
    // 0x800124E4: or          $t9, $t4, $t5
    ctx->r25 = ctx->r12 | ctx->r13;
    // 0x800124E8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800124EC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800124F0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800124F4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800124F8: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800124FC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80012500: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80012504: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80012508: lhu         $t6, 0x23C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23C);
    // 0x8001250C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80012510: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80012514: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80012518: lhu         $t9, 0x23E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23E);
    // 0x8001251C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80012520: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x80012524: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80012528: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001252C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80012530: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80012534: b           L_80012D48
    // 0x80012538: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
        goto L_80012D48;
    // 0x80012538: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8001253C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
L_80012540:
    // 0x80012540: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x80012544: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80012548: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8001254C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80012550: sh          $a3, 0x1DE($sp)
    MEM_H(0X1DE, ctx->r29) = ctx->r7;
    // 0x80012554: sh          $a2, 0x1DC($sp)
    MEM_H(0X1DC, ctx->r29) = ctx->r6;
    // 0x80012558: lw          $a1, 0x230($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X230);
    // 0x8001255C: lhu         $a0, 0x22C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22C);
    // 0x80012560: jal         0x8000522C
    // 0x80012564: sw          $v1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_6;
    // 0x80012564: sw          $v1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r3;
    after_6:
    // 0x80012568: lw          $t3, 0x114($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X114);
    // 0x8001256C: lhu         $a2, 0x1DC($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1DC);
    // 0x80012570: lhu         $a3, 0x1DE($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X1DE);
    // 0x80012574: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80012578: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x8001257C: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x80012580: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80012584: andi        $t4, $a2, 0xF
    ctx->r12 = ctx->r6 & 0XF;
    // 0x80012588: sll         $t4, $t4, 14
    ctx->r12 = S32(ctx->r12 << 14);
    // 0x8001258C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80012590: andi        $t5, $a3, 0xF
    ctx->r13 = ctx->r7 & 0XF;
    // 0x80012594: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x80012598: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8001259C: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800125A0: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x800125A4: or          $t6, $t7, $t5
    ctx->r14 = ctx->r15 | ctx->r13;
    // 0x800125A8: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x800125AC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800125B0: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800125B4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800125B8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800125BC: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800125C0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800125C4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800125C8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800125CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800125D0: lw          $ra, 0x0($t0)
    ctx->r31 = MEM_W(ctx->r8, 0X0);
    // 0x800125D4: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x800125D8: addiu       $t7, $ra, 0x8
    ctx->r15 = ADD32(ctx->r31, 0X8);
    // 0x800125DC: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800125E0: sw          $t6, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r14;
    // 0x800125E4: lhu         $t9, 0x23E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23E);
    // 0x800125E8: lhu         $a0, 0x23C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X23C);
    // 0x800125EC: multu       $a0, $t9
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800125F0: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x800125F4: mflo        $t2
    ctx->r10 = lo;
    // 0x800125F8: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800125FC: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x80012600: beq         $at, $zero, L_80012610
    if (ctx->r1 == 0) {
        // 0x80012604: nop
    
            goto L_80012610;
    }
    // 0x80012604: nop

    // 0x80012608: b           L_80012610
    // 0x8001260C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_80012610;
    // 0x8001260C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_80012610:
    // 0x80012610: bgez        $v1, L_8001261C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80012614: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_8001261C;
    }
    // 0x80012614: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x80012618: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
L_8001261C:
    // 0x8001261C: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
    // 0x80012620: bgtz        $v1, L_80012630
    if (SIGNED(ctx->r3) > 0) {
        // 0x80012624: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80012630;
    }
    // 0x80012624: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80012628: b           L_80012630
    // 0x8001262C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80012630;
    // 0x8001262C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80012630:
    // 0x80012630: bgtz        $v1, L_80012640
    if (SIGNED(ctx->r3) > 0) {
        // 0x80012634: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_80012640;
    }
    // 0x80012634: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x80012638: b           L_80012644
    // 0x8001263C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80012644;
    // 0x8001263C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80012640:
    // 0x80012640: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80012644:
    // 0x80012644: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x80012648: bne         $v0, $zero, L_80012654
    if (ctx->r2 != 0) {
        // 0x8001264C: nop
    
            goto L_80012654;
    }
    // 0x8001264C: nop

    // 0x80012650: break       7
    do_break(2147558992);
L_80012654:
    // 0x80012654: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80012658: bne         $v0, $at, L_8001266C
    if (ctx->r2 != ctx->r1) {
        // 0x8001265C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001266C;
    }
    // 0x8001265C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80012660: bne         $t8, $at, L_8001266C
    if (ctx->r24 != ctx->r1) {
        // 0x80012664: nop
    
            goto L_8001266C;
    }
    // 0x80012664: nop

    // 0x80012668: break       6
    do_break(2147559016);
L_8001266C:
    // 0x8001266C: mflo        $t7
    ctx->r15 = lo;
    // 0x80012670: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80012674: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80012678: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x8001267C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80012680: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80012684: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80012688: sw          $t6, 0x4($ra)
    MEM_W(0X4, ctx->r31) = ctx->r14;
    // 0x8001268C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012690: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80012694: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80012698: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8001269C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800126A0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800126A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800126A8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800126AC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800126B0: lhu         $t6, 0x23C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23C);
    // 0x800126B4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800126B8: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800126BC: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800126C0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800126C4: sra         $t7, $t9, 3
    ctx->r15 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800126C8: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x800126CC: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x800126D0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800126D4: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x800126D8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800126DC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800126E0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800126E4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800126E8: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800126EC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800126F0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800126F4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800126F8: lhu         $t9, 0x23C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23C);
    // 0x800126FC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80012700: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x80012704: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80012708: lhu         $t7, 0x23E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23E);
    // 0x8001270C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80012710: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80012714: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x80012718: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8001271C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80012720: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80012724: b           L_80012D48
    // 0x80012728: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
        goto L_80012D48;
    // 0x80012728: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_8001272C:
    // 0x8001272C: andi        $t8, $a1, 0x20
    ctx->r24 = ctx->r5 & 0X20;
    // 0x80012730: beq         $t8, $zero, L_80012B7C
    if (ctx->r24 == 0) {
        // 0x80012734: andi        $t9, $a1, 0x80
        ctx->r25 = ctx->r5 & 0X80;
            goto L_80012B7C;
    }
    // 0x80012734: andi        $t9, $a1, 0x80
    ctx->r25 = ctx->r5 & 0X80;
    // 0x80012738: beq         $t9, $zero, L_800129AC
    if (ctx->r25 == 0) {
        // 0x8001273C: lhu         $t6, 0x23C($sp)
        ctx->r14 = MEM_HU(ctx->r29, 0X23C);
            goto L_800129AC;
    }
    // 0x8001273C: lhu         $t6, 0x23C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012740: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x80012744: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x80012748: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001274C: bne         $t8, $zero, L_80012770
    if (ctx->r24 != 0) {
        // 0x80012750: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80012770;
    }
    // 0x80012750: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80012754:
    // 0x80012754: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80012758: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001275C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80012760: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80012764: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80012768: beq         $t9, $zero, L_80012754
    if (ctx->r25 == 0) {
        // 0x8001276C: andi        $a3, $a3, 0xFFFF
        ctx->r7 = ctx->r7 & 0XFFFF;
            goto L_80012754;
    }
    // 0x8001276C: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
L_80012770:
    // 0x80012770: lhu         $t6, 0x23E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23E);
    // 0x80012774: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80012778: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x8001277C: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x80012780: bne         $t8, $zero, L_800127A4
    if (ctx->r24 != 0) {
        // 0x80012784: sra         $v0, $v0, 16
        ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800127A4;
    }
    // 0x80012784: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80012788:
    // 0x80012788: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001278C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80012790: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80012794: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80012798: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001279C: beq         $t9, $zero, L_80012788
    if (ctx->r25 == 0) {
        // 0x800127A0: andi        $a2, $a2, 0xFFFF
        ctx->r6 = ctx->r6 & 0XFFFF;
            goto L_80012788;
    }
    // 0x800127A0: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
L_800127A4:
    // 0x800127A4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800127A8: lui         $t6, 0xFD70
    ctx->r14 = S32(0XFD70 << 16);
    // 0x800127AC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800127B0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800127B4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800127B8: sh          $a3, 0x1DE($sp)
    MEM_H(0X1DE, ctx->r29) = ctx->r7;
    // 0x800127BC: sh          $a2, 0x1DC($sp)
    MEM_H(0X1DC, ctx->r29) = ctx->r6;
    // 0x800127C0: lw          $a1, 0x230($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X230);
    // 0x800127C4: lhu         $a0, 0x22C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22C);
    // 0x800127C8: jal         0x8000522C
    // 0x800127CC: sw          $v1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_7;
    // 0x800127CC: sw          $v1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r3;
    after_7:
    // 0x800127D0: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x800127D4: lhu         $a2, 0x1DC($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1DC);
    // 0x800127D8: lhu         $a3, 0x1DE($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X1DE);
    // 0x800127DC: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800127E0: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x800127E4: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x800127E8: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800127EC: andi        $t4, $a2, 0xF
    ctx->r12 = ctx->r6 & 0XF;
    // 0x800127F0: sll         $t4, $t4, 14
    ctx->r12 = S32(ctx->r12 << 14);
    // 0x800127F4: lui         $at, 0x704
    ctx->r1 = S32(0X704 << 16);
    // 0x800127F8: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x800127FC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80012800: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x80012804: andi        $t5, $a3, 0xF
    ctx->r13 = ctx->r7 & 0XF;
    // 0x80012808: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8001280C: ori         $t6, $t7, 0x100
    ctx->r14 = ctx->r15 | 0X100;
    // 0x80012810: or          $t8, $t6, $t5
    ctx->r24 = ctx->r14 | ctx->r13;
    // 0x80012814: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x80012818: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8001281C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80012820: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012824: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80012828: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8001282C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80012830: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80012834: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012838: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001283C: lw          $ra, 0x0($t0)
    ctx->r31 = MEM_W(ctx->r8, 0X0);
    // 0x80012840: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x80012844: addiu       $t6, $ra, 0x8
    ctx->r14 = ADD32(ctx->r31, 0X8);
    // 0x80012848: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8001284C: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
    // 0x80012850: lhu         $t9, 0x23E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23E);
    // 0x80012854: lhu         $a0, 0x23C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012858: multu       $a0, $t9
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001285C: mflo        $t2
    ctx->r10 = lo;
    // 0x80012860: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80012864: sra         $t2, $t2, 1
    ctx->r10 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80012868: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x8001286C: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x80012870: beq         $at, $zero, L_80012880
    if (ctx->r1 == 0) {
        // 0x80012874: nop
    
            goto L_80012880;
    }
    // 0x80012874: nop

    // 0x80012878: b           L_80012880
    // 0x8001287C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_80012880;
    // 0x8001287C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_80012880:
    // 0x80012880: bgez        $a0, L_80012890
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80012884: sra         $v1, $a0, 3
        ctx->r3 = S32(SIGNED(ctx->r4) >> 3);
            goto L_80012890;
    }
    // 0x80012884: sra         $v1, $a0, 3
    ctx->r3 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80012888: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x8001288C: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_80012890:
    // 0x80012890: bgtz        $v1, L_800128A0
    if (SIGNED(ctx->r3) > 0) {
        // 0x80012894: sw          $ra, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r31;
            goto L_800128A0;
    }
    // 0x80012894: sw          $ra, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r31;
    // 0x80012898: b           L_800128A4
    // 0x8001289C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800128A4;
    // 0x8001289C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800128A0:
    // 0x800128A0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_800128A4:
    // 0x800128A4: bgtz        $v1, L_800128B4
    if (SIGNED(ctx->r3) > 0) {
        // 0x800128A8: lui         $ra, 0xF568
        ctx->r31 = S32(0XF568 << 16);
            goto L_800128B4;
    }
    // 0x800128A8: lui         $ra, 0xF568
    ctx->r31 = S32(0XF568 << 16);
    // 0x800128AC: b           L_800128B8
    // 0x800128B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800128B8;
    // 0x800128B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800128B4:
    // 0x800128B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800128B8:
    // 0x800128B8: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x800128BC: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x800128C0: bne         $v0, $zero, L_800128CC
    if (ctx->r2 != 0) {
        // 0x800128C4: nop
    
            goto L_800128CC;
    }
    // 0x800128C4: nop

    // 0x800128C8: break       7
    do_break(2147559624);
L_800128CC:
    // 0x800128CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800128D0: bne         $v0, $at, L_800128E4
    if (ctx->r2 != ctx->r1) {
        // 0x800128D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800128E4;
    }
    // 0x800128D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800128D8: bne         $t7, $at, L_800128E4
    if (ctx->r15 != ctx->r1) {
        // 0x800128DC: nop
    
            goto L_800128E4;
    }
    // 0x800128DC: nop

    // 0x800128E0: break       6
    do_break(2147559648);
L_800128E4:
    // 0x800128E4: mflo        $t6
    ctx->r14 = lo;
    // 0x800128E8: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800128EC: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x800128F0: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x800128F4: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x800128F8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800128FC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80012900: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80012904: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x80012908: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001290C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80012910: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80012914: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80012918: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8001291C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012920: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80012924: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80012928: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001292C: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012930: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80012934: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x80012938: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8001293C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80012940: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x80012944: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x80012948: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x8001294C: ori         $t8, $t6, 0x100
    ctx->r24 = ctx->r14 | 0X100;
    // 0x80012950: or          $t9, $t7, $ra
    ctx->r25 = ctx->r15 | ctx->r31;
    // 0x80012954: or          $t7, $t8, $t5
    ctx->r15 = ctx->r24 | ctx->r13;
    // 0x80012958: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8001295C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80012960: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80012964: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012968: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8001296C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80012970: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80012974: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80012978: lhu         $t8, 0x23C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X23C);
    // 0x8001297C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80012980: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80012984: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80012988: lhu         $t7, 0x23E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23E);
    // 0x8001298C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80012990: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80012994: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80012998: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001299C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800129A0: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800129A4: b           L_80012D48
    // 0x800129A8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80012D48;
    // 0x800129A8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_800129AC:
    // 0x800129AC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800129B0: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x800129B4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800129B8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800129BC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800129C0: lw          $a1, 0x230($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X230);
    // 0x800129C4: lhu         $a0, 0x22C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22C);
    // 0x800129C8: jal         0x8000522C
    // 0x800129CC: sw          $v1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_8;
    // 0x800129CC: sw          $v1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r3;
    after_8:
    // 0x800129D0: lw          $a3, 0xDC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XDC);
    // 0x800129D4: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800129D8: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x800129DC: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x800129E0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800129E4: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x800129E8: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800129EC: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x800129F0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800129F4: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x800129F8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800129FC: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80012A00: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80012A04: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80012A08: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80012A0C: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x80012A10: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80012A14: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80012A18: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80012A1C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80012A20: lui         $ra, 0xF568
    ctx->r31 = S32(0XF568 << 16);
    // 0x80012A24: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x80012A28: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x80012A2C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80012A30: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80012A34: lhu         $t8, 0x23E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X23E);
    // 0x80012A38: lhu         $a0, 0x23C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012A3C: multu       $a0, $t8
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80012A40: mflo        $t2
    ctx->r10 = lo;
    // 0x80012A44: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80012A48: sra         $t2, $t2, 1
    ctx->r10 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80012A4C: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80012A50: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x80012A54: beq         $at, $zero, L_80012A64
    if (ctx->r1 == 0) {
        // 0x80012A58: nop
    
            goto L_80012A64;
    }
    // 0x80012A58: nop

    // 0x80012A5C: b           L_80012A64
    // 0x80012A60: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_80012A64;
    // 0x80012A60: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_80012A64:
    // 0x80012A64: bgez        $a0, L_80012A74
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80012A68: sra         $v1, $a0, 3
        ctx->r3 = S32(SIGNED(ctx->r4) >> 3);
            goto L_80012A74;
    }
    // 0x80012A68: sra         $v1, $a0, 3
    ctx->r3 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80012A6C: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x80012A70: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_80012A74:
    // 0x80012A74: bgtz        $v1, L_80012A84
    if (SIGNED(ctx->r3) > 0) {
        // 0x80012A78: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80012A84;
    }
    // 0x80012A78: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80012A7C: b           L_80012A84
    // 0x80012A80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80012A84;
    // 0x80012A80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80012A84:
    // 0x80012A84: bgtz        $v1, L_80012A94
    if (SIGNED(ctx->r3) > 0) {
        // 0x80012A88: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_80012A94;
    }
    // 0x80012A88: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x80012A8C: b           L_80012A98
    // 0x80012A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80012A98;
    // 0x80012A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80012A94:
    // 0x80012A94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80012A98:
    // 0x80012A98: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x80012A9C: bne         $v0, $zero, L_80012AA8
    if (ctx->r2 != 0) {
        // 0x80012AA0: nop
    
            goto L_80012AA8;
    }
    // 0x80012AA0: nop

    // 0x80012AA4: break       7
    do_break(2147560100);
L_80012AA8:
    // 0x80012AA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80012AAC: bne         $v0, $at, L_80012AC0
    if (ctx->r2 != ctx->r1) {
        // 0x80012AB0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80012AC0;
    }
    // 0x80012AB0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80012AB4: bne         $t7, $at, L_80012AC0
    if (ctx->r15 != ctx->r1) {
        // 0x80012AB8: nop
    
            goto L_80012AC0;
    }
    // 0x80012AB8: nop

    // 0x80012ABC: break       6
    do_break(2147560124);
L_80012AC0:
    // 0x80012AC0: mflo        $t9
    ctx->r25 = lo;
    // 0x80012AC4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80012AC8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80012ACC: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x80012AD0: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80012AD4: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80012AD8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80012ADC: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80012AE0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012AE4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80012AE8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80012AEC: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80012AF0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012AF4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80012AF8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80012AFC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012B00: lhu         $t6, 0x23C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012B04: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80012B08: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x80012B0C: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80012B10: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80012B14: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80012B18: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x80012B1C: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x80012B20: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80012B24: or          $t7, $t6, $ra
    ctx->r15 = ctx->r14 | ctx->r31;
    // 0x80012B28: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80012B2C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80012B30: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80012B34: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012B38: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80012B3C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80012B40: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80012B44: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80012B48: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012B4C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80012B50: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80012B54: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80012B58: lhu         $t8, 0x23E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X23E);
    // 0x80012B5C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80012B60: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80012B64: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80012B68: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80012B6C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80012B70: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80012B74: b           L_80012D48
    // 0x80012B78: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80012D48;
    // 0x80012B78: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80012B7C:
    // 0x80012B7C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012B80: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80012B84: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80012B88: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80012B8C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80012B90: lw          $a1, 0x230($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X230);
    // 0x80012B94: lhu         $a0, 0x22C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22C);
    // 0x80012B98: jal         0x8000522C
    // 0x80012B9C: sw          $v1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_9;
    // 0x80012B9C: sw          $v1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r3;
    after_9:
    // 0x80012BA0: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
    // 0x80012BA4: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80012BA8: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x80012BAC: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x80012BB0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80012BB4: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x80012BB8: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80012BBC: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80012BC0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80012BC4: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x80012BC8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80012BCC: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80012BD0: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80012BD4: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80012BD8: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80012BDC: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x80012BE0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80012BE4: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80012BE8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80012BEC: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80012BF0: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x80012BF4: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x80012BF8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80012BFC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80012C00: lhu         $t7, 0x23E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23E);
    // 0x80012C04: lhu         $a0, 0x23C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012C08: multu       $a0, $t7
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80012C0C: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x80012C10: mflo        $t2
    ctx->r10 = lo;
    // 0x80012C14: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80012C18: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x80012C1C: beq         $at, $zero, L_80012C2C
    if (ctx->r1 == 0) {
        // 0x80012C20: nop
    
            goto L_80012C2C;
    }
    // 0x80012C20: nop

    // 0x80012C24: b           L_80012C2C
    // 0x80012C28: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_80012C2C;
    // 0x80012C28: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
L_80012C2C:
    // 0x80012C2C: bgez        $v1, L_80012C38
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80012C30: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_80012C38;
    }
    // 0x80012C30: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x80012C34: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
L_80012C38:
    // 0x80012C38: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
    // 0x80012C3C: bgtz        $v1, L_80012C4C
    if (SIGNED(ctx->r3) > 0) {
        // 0x80012C40: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80012C4C;
    }
    // 0x80012C40: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80012C44: b           L_80012C4C
    // 0x80012C48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80012C4C;
    // 0x80012C48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80012C4C:
    // 0x80012C4C: bgtz        $v1, L_80012C5C
    if (SIGNED(ctx->r3) > 0) {
        // 0x80012C50: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_80012C5C;
    }
    // 0x80012C50: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x80012C54: b           L_80012C60
    // 0x80012C58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80012C60;
    // 0x80012C58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80012C5C:
    // 0x80012C5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80012C60:
    // 0x80012C60: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x80012C64: bne         $v0, $zero, L_80012C70
    if (ctx->r2 != 0) {
        // 0x80012C68: nop
    
            goto L_80012C70;
    }
    // 0x80012C68: nop

    // 0x80012C6C: break       7
    do_break(2147560556);
L_80012C70:
    // 0x80012C70: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80012C74: bne         $v0, $at, L_80012C88
    if (ctx->r2 != ctx->r1) {
        // 0x80012C78: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80012C88;
    }
    // 0x80012C78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80012C7C: bne         $t8, $at, L_80012C88
    if (ctx->r24 != ctx->r1) {
        // 0x80012C80: nop
    
            goto L_80012C88;
    }
    // 0x80012C80: nop

    // 0x80012C84: break       6
    do_break(2147560580);
L_80012C88:
    // 0x80012C88: mflo        $t9
    ctx->r25 = lo;
    // 0x80012C8C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80012C90: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80012C94: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x80012C98: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80012C9C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80012CA0: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80012CA4: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80012CA8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012CAC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80012CB0: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80012CB4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80012CB8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80012CBC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012CC0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80012CC4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80012CC8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012CCC: lhu         $t6, 0x23C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012CD0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80012CD4: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80012CD8: addiu       $t7, $t8, 0x7
    ctx->r15 = ADD32(ctx->r24, 0X7);
    // 0x80012CDC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80012CE0: sra         $t9, $t7, 3
    ctx->r25 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80012CE4: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x80012CE8: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x80012CEC: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80012CF0: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80012CF4: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80012CF8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80012CFC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80012D00: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80012D04: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80012D08: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80012D0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80012D10: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80012D14: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80012D18: lhu         $t7, 0x23C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X23C);
    // 0x80012D1C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80012D20: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80012D24: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80012D28: lhu         $t9, 0x23E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X23E);
    // 0x80012D2C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80012D30: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80012D34: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80012D38: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80012D3C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80012D40: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80012D44: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80012D48:
    // 0x80012D48: lh          $v0, 0x20E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X20E);
    // 0x80012D4C: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80012D50: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80012D54: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80012D58: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80012D5C: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x80012D60: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80012D64: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80012D68: blez        $v0, L_80012D78
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80012D6C: lh          $v1, 0x20C($sp)
        ctx->r3 = MEM_H(ctx->r29, 0X20C);
            goto L_80012D78;
    }
    // 0x80012D6C: lh          $v1, 0x20C($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X20C);
    // 0x80012D70: b           L_80012D7C
    // 0x80012D74: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_80012D7C;
    // 0x80012D74: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_80012D78:
    // 0x80012D78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80012D7C:
    // 0x80012D7C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80012D80: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80012D84: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80012D88: blez        $v1, L_80012D98
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80012D8C: andi        $t6, $a3, 0xFFF
        ctx->r14 = ctx->r7 & 0XFFF;
            goto L_80012D98;
    }
    // 0x80012D8C: andi        $t6, $a3, 0xFFF
    ctx->r14 = ctx->r7 & 0XFFF;
    // 0x80012D90: b           L_80012D9C
    // 0x80012D94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80012D9C;
    // 0x80012D94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80012D98:
    // 0x80012D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80012D9C:
    // 0x80012D9C: andi        $t7, $v0, 0xFFF
    ctx->r15 = ctx->r2 & 0XFFF;
    // 0x80012DA0: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80012DA4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80012DA8: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80012DAC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80012DB0: lh          $a0, 0x212($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X212);
    // 0x80012DB4: lh          $t1, 0x210($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X210);
    // 0x80012DB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80012DBC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80012DC0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80012DC4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80012DC8: blez        $a0, L_80012DD8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80012DCC: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80012DD8;
    }
    // 0x80012DCC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80012DD0: b           L_80012DD8
    // 0x80012DD4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
        goto L_80012DD8;
    // 0x80012DD4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_80012DD8:
    // 0x80012DD8: sll         $a1, $t1, 16
    ctx->r5 = S32(ctx->r9 << 16);
    // 0x80012DDC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80012DE0: blez        $a1, L_80012DF0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80012DE4: andi        $t9, $a3, 0xFFF
        ctx->r25 = ctx->r7 & 0XFFF;
            goto L_80012DF0;
    }
    // 0x80012DE4: andi        $t9, $a3, 0xFFF
    ctx->r25 = ctx->r7 & 0XFFF;
    // 0x80012DE8: b           L_80012DF4
    // 0x80012DEC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80012DF4;
    // 0x80012DEC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80012DF0:
    // 0x80012DF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80012DF4:
    // 0x80012DF4: andi        $t6, $v0, 0xFFF
    ctx->r14 = ctx->r2 & 0XFFF;
    // 0x80012DF8: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80012DFC: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80012E00: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80012E04: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80012E08: lui         $t6, 0xE100
    ctx->r14 = S32(0XE100 << 16);
    // 0x80012E0C: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x80012E10: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80012E14: bgez        $a0, L_80012EB4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80012E18: sw          $t6, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r14;
            goto L_80012EB4;
    }
    // 0x80012E18: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80012E1C: lhu         $t8, 0x1D6($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1D6);
    // 0x80012E20: lwc1        $f18, 0x1EC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1EC);
    // 0x80012E24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80012E28: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80012E2C: bgez        $t8, L_80012E40
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80012E30: cvt.s.w     $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80012E40;
    }
    // 0x80012E30: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80012E34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012E38: nop

    // 0x80012E3C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80012E40:
    // 0x80012E40: div.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80012E44: trunc.w.s   $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80012E48: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80012E4C: nop

    // 0x80012E50: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80012E54: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80012E58: bgez        $v1, L_80012E88
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80012E5C: nop
    
            goto L_80012E88;
    }
    // 0x80012E5C: nop

    // 0x80012E60: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80012E64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80012E68: mflo        $v0
    ctx->r2 = lo;
    // 0x80012E6C: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80012E70: blez        $v0, L_80012E80
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80012E74: nop
    
            goto L_80012E80;
    }
    // 0x80012E74: nop

    // 0x80012E78: b           L_80012EE0
    // 0x80012E7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80012EE0;
    // 0x80012E7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80012E80:
    // 0x80012E80: b           L_80012EE0
    // 0x80012E84: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_80012EE0;
    // 0x80012E84: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_80012E88:
    // 0x80012E88: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80012E8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80012E90: mflo        $v0
    ctx->r2 = lo;
    // 0x80012E94: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80012E98: bgez        $v0, L_80012EA8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80012E9C: nop
    
            goto L_80012EA8;
    }
    // 0x80012E9C: nop

    // 0x80012EA0: b           L_80012EA8
    // 0x80012EA4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80012EA8;
    // 0x80012EA4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80012EA8:
    // 0x80012EA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80012EAC: b           L_80012EE0
    // 0x80012EB0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80012EE0;
    // 0x80012EB0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80012EB4:
    // 0x80012EB4: lhu         $t9, 0x1D6($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X1D6);
    // 0x80012EB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80012EBC: lwc1        $f16, 0x1EC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1EC);
    // 0x80012EC0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80012EC4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80012EC8: bgez        $t9, L_80012EDC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80012ECC: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80012EDC;
    }
    // 0x80012ECC: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80012ED0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80012ED4: nop

    // 0x80012ED8: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_80012EDC:
    // 0x80012EDC: div.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
L_80012EE0:
    // 0x80012EE0: bgez        $t1, L_80012F60
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80012EE4: lhu         $t8, 0x240($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X240);
            goto L_80012F60;
    }
    // 0x80012EE4: lhu         $t8, 0x240($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X240);
    // 0x80012EE8: lwc1        $f6, 0x1E8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1E8);
    // 0x80012EEC: div.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80012EF0: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80012EF4: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80012EF8: nop

    // 0x80012EFC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80012F00: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80012F04: bgez        $v1, L_80012F34
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80012F08: nop
    
            goto L_80012F34;
    }
    // 0x80012F08: nop

    // 0x80012F0C: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80012F10: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80012F14: mflo        $v0
    ctx->r2 = lo;
    // 0x80012F18: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80012F1C: blez        $v0, L_80012F2C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80012F20: nop
    
            goto L_80012F2C;
    }
    // 0x80012F20: nop

    // 0x80012F24: b           L_80012F70
    // 0x80012F28: lhu         $t9, 0x242($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X242);
        goto L_80012F70;
    // 0x80012F28: lhu         $t9, 0x242($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X242);
L_80012F2C:
    // 0x80012F2C: b           L_80012F6C
    // 0x80012F30: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_80012F6C;
    // 0x80012F30: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80012F34:
    // 0x80012F34: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80012F38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80012F3C: mflo        $v0
    ctx->r2 = lo;
    // 0x80012F40: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80012F44: bgez        $v0, L_80012F54
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80012F48: nop
    
            goto L_80012F54;
    }
    // 0x80012F48: nop

    // 0x80012F4C: b           L_80012F54
    // 0x80012F50: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80012F54;
    // 0x80012F50: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80012F54:
    // 0x80012F54: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80012F58: b           L_80012F6C
    // 0x80012F5C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_80012F6C;
    // 0x80012F5C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80012F60:
    // 0x80012F60: lwc1        $f8, 0x1E8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1E8);
    // 0x80012F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012F68: div.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
L_80012F6C:
    // 0x80012F6C: lhu         $t9, 0x242($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X242);
L_80012F70:
    // 0x80012F70: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x80012F74: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x80012F78: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x80012F7C: sll         $t8, $t9, 5
    ctx->r24 = S32(ctx->r25 << 5);
    // 0x80012F80: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x80012F84: subu        $t8, $t9, $a2
    ctx->r24 = SUB32(ctx->r25, ctx->r6);
    // 0x80012F88: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80012F8C: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80012F90: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x80012F94: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80012F98: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80012F9C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80012FA0: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80012FA4: lui         $t7, 0xF100
    ctx->r15 = S32(0XF100 << 16);
    // 0x80012FA8: cvt.w.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80012FAC: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80012FB0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80012FB4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80012FB8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80012FBC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80012FC0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80012FC4: beql        $t6, $zero, L_80013014
    if (ctx->r14 == 0) {
        // 0x80012FC8: mfc1        $t6, $f10
        ctx->r14 = (int32_t)ctx->f10.u32l;
            goto L_80013014;
    }
    goto skip_5;
    // 0x80012FC8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    skip_5:
    // 0x80012FCC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80012FD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80012FD4: sub.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80012FD8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80012FDC: nop

    // 0x80012FE0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80012FE4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80012FE8: nop

    // 0x80012FEC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80012FF0: bne         $t6, $zero, L_80013008
    if (ctx->r14 != 0) {
        // 0x80012FF4: nop
    
            goto L_80013008;
    }
    // 0x80012FF4: nop

    // 0x80012FF8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80012FFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013000: b           L_80013020
    // 0x80013004: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80013020;
    // 0x80013004: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80013008:
    // 0x80013008: b           L_80013020
    // 0x8001300C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80013020;
    // 0x8001300C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80013010: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
L_80013014:
    // 0x80013014: nop

    // 0x80013018: bltz        $t6, L_80013008
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001301C: nop
    
            goto L_80013008;
    }
    // 0x8001301C: nop

L_80013020:
    // 0x80013020: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80013024: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x80013028: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001302C: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80013030: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80013034: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80013038: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8001303C: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80013040: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80013044: nop

    // 0x80013048: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8001304C: beql        $t6, $zero, L_8001309C
    if (ctx->r14 == 0) {
        // 0x80013050: mfc1        $t6, $f4
        ctx->r14 = (int32_t)ctx->f4.u32l;
            goto L_8001309C;
    }
    goto skip_6;
    // 0x80013050: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    skip_6:
    // 0x80013054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80013058: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001305C: sub.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80013060: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80013064: nop

    // 0x80013068: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001306C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80013070: nop

    // 0x80013074: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80013078: bne         $t6, $zero, L_80013090
    if (ctx->r14 != 0) {
        // 0x8001307C: nop
    
            goto L_80013090;
    }
    // 0x8001307C: nop

    // 0x80013080: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80013084: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013088: b           L_800130A8
    // 0x8001308C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800130A8;
    // 0x8001308C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80013090:
    // 0x80013090: b           L_800130A8
    // 0x80013094: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800130A8;
    // 0x80013094: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80013098: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
L_8001309C:
    // 0x8001309C: nop

    // 0x800130A0: bltz        $t6, L_80013090
    if (SIGNED(ctx->r14) < 0) {
        // 0x800130A4: nop
    
            goto L_80013090;
    }
    // 0x800130A4: nop

L_800130A8:
    // 0x800130A8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800130AC: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800130B0: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800130B4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800130B8: b           L_80013364
    // 0x800130BC: lhu         $a1, 0x224($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X224);
        goto L_80013364;
    // 0x800130BC: lhu         $a1, 0x224($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X224);
L_800130C0:
    // 0x800130C0: andi        $t6, $a1, 0x2
    ctx->r14 = ctx->r5 & 0X2;
L_800130C4:
    // 0x800130C4: bne         $t6, $zero, L_800131F8
    if (ctx->r14 != 0) {
        // 0x800130C8: lui         $t0, 0x8009
        ctx->r8 = S32(0X8009 << 16);
            goto L_800131F8;
    }
    // 0x800130C8: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800130CC: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x800130D0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800130D4: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x800130D8: lui         $t9, 0xFFFD
    ctx->r25 = S32(0XFFFD << 16);
    // 0x800130DC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800130E0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800130E4: ori         $t9, $t9, 0xF6FB
    ctx->r25 = ctx->r25 | 0XF6FB;
    // 0x800130E8: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x800130EC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800130F0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800130F4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800130F8: lui         $t8, 0xF0A
    ctx->r24 = S32(0XF0A << 16);
    // 0x800130FC: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80013100: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80013104: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80013108: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x8001310C: ori         $t8, $t8, 0x4000
    ctx->r24 = ctx->r24 | 0X4000;
    // 0x80013110: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80013114: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80013118: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001311C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80013120: lui         $t5, 0xF600
    ctx->r13 = S32(0XF600 << 16);
    // 0x80013124: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80013128: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8001312C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80013130: lbu         $t8, 0x21C($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X21C);
    // 0x80013134: lbu         $t7, 0x21D($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X21D);
    // 0x80013138: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001313C: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80013140: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80013144: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80013148: lbu         $t9, 0x21E($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X21E);
    // 0x8001314C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013150: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x80013154: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80013158: lbu         $t6, 0x21F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X21F);
    // 0x8001315C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80013160: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80013164: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80013168: lh          $t7, 0x20E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X20E);
    // 0x8001316C: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x80013170: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80013174: blez        $t7, L_80013184
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80013178: lh          $t6, 0x20C($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X20C);
            goto L_80013184;
    }
    // 0x80013178: lh          $t6, 0x20C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X20C);
    // 0x8001317C: b           L_80013184
    // 0x80013180: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
        goto L_80013184;
    // 0x80013180: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
L_80013184:
    // 0x80013184: blez        $t6, L_80013194
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80013188: nop
    
            goto L_80013194;
    }
    // 0x80013188: nop

    // 0x8001318C: b           L_80013194
    // 0x80013190: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80013194;
    // 0x80013190: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80013194:
    // 0x80013194: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x80013198: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001319C: andi        $t6, $a3, 0x3FF
    ctx->r14 = ctx->r7 & 0X3FF;
    // 0x800131A0: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x800131A4: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800131A8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800131AC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800131B0: lh          $t6, 0x212($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X212);
    // 0x800131B4: lh          $t7, 0x210($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X210);
    // 0x800131B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800131BC: blez        $t6, L_800131CC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800131C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800131CC;
    }
    // 0x800131C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800131C4: b           L_800131CC
    // 0x800131C8: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
        goto L_800131CC;
    // 0x800131C8: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_800131CC:
    // 0x800131CC: blez        $t7, L_800131DC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800131D0: andi        $t6, $a3, 0x3FF
        ctx->r14 = ctx->r7 & 0X3FF;
            goto L_800131DC;
    }
    // 0x800131D0: andi        $t6, $a3, 0x3FF
    ctx->r14 = ctx->r7 & 0X3FF;
    // 0x800131D4: b           L_800131DC
    // 0x800131D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800131DC;
    // 0x800131D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800131DC:
    // 0x800131DC: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x800131E0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800131E4: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x800131E8: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800131EC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800131F0: b           L_80013364
    // 0x800131F4: lhu         $a1, 0x224($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X224);
        goto L_80013364;
    // 0x800131F4: lhu         $a1, 0x224($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X224);
L_800131F8:
    // 0x800131F8: lbu         $t6, 0x21F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X21F);
    // 0x800131FC: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80013200: bne         $at, $zero, L_80013364
    if (ctx->r1 != 0) {
        // 0x80013204: lui         $t0, 0x8009
        ctx->r8 = S32(0X8009 << 16);
            goto L_80013364;
    }
    // 0x80013204: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80013208: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x8001320C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80013210: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x80013214: lui         $t8, 0xFFFD
    ctx->r24 = S32(0XFFFD << 16);
    // 0x80013218: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8001321C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80013220: ori         $t8, $t8, 0xF6FB
    ctx->r24 = ctx->r24 | 0XF6FB;
    // 0x80013224: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80013228: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001322C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80013230: lhu         $t6, 0x224($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X224);
    // 0x80013234: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80013238: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x8001323C: andi        $t9, $t6, 0x1000
    ctx->r25 = ctx->r14 & 0X1000;
    // 0x80013240: beq         $t9, $zero, L_80013270
    if (ctx->r25 == 0) {
        // 0x80013244: lui         $t5, 0xF600
        ctx->r13 = S32(0XF600 << 16);
            goto L_80013270;
    }
    // 0x80013244: lui         $t5, 0xF600
    ctx->r13 = S32(0XF600 << 16);
    // 0x80013248: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001324C: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80013250: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x80013254: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80013258: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8001325C: ori         $t6, $t6, 0x4340
    ctx->r14 = ctx->r14 | 0X4340;
    // 0x80013260: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80013264: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80013268: b           L_8001328C
    // 0x8001326C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
        goto L_8001328C;
    // 0x8001326C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80013270:
    // 0x80013270: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80013274: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80013278: ori         $t8, $t8, 0x4240
    ctx->r24 = ctx->r24 | 0X4240;
    // 0x8001327C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80013280: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80013284: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80013288: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8001328C:
    // 0x8001328C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80013290: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80013294: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80013298: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8001329C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800132A0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800132A4: lbu         $t8, 0x21C($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X21C);
    // 0x800132A8: lbu         $t7, 0x21D($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X21D);
    // 0x800132AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800132B0: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x800132B4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800132B8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800132BC: lbu         $t6, 0x21E($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X21E);
    // 0x800132C0: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800132C4: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x800132C8: lbu         $t9, 0x21F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X21F);
    // 0x800132CC: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800132D0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800132D4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800132D8: lh          $t7, 0x20E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X20E);
    // 0x800132DC: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x800132E0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800132E4: blez        $t7, L_800132F4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800132E8: lh          $t9, 0x20C($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X20C);
            goto L_800132F4;
    }
    // 0x800132E8: lh          $t9, 0x20C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X20C);
    // 0x800132EC: b           L_800132F4
    // 0x800132F0: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
        goto L_800132F4;
    // 0x800132F0: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
L_800132F4:
    // 0x800132F4: blez        $t9, L_80013304
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800132F8: nop
    
            goto L_80013304;
    }
    // 0x800132F8: nop

    // 0x800132FC: b           L_80013304
    // 0x80013300: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80013304;
    // 0x80013300: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80013304:
    // 0x80013304: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x80013308: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8001330C: andi        $t9, $a3, 0x3FF
    ctx->r25 = ctx->r7 & 0X3FF;
    // 0x80013310: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x80013314: or          $t7, $t6, $t5
    ctx->r15 = ctx->r14 | ctx->r13;
    // 0x80013318: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8001331C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80013320: lh          $t9, 0x212($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X212);
    // 0x80013324: lh          $t7, 0x210($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X210);
    // 0x80013328: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001332C: blez        $t9, L_8001333C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80013330: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001333C;
    }
    // 0x80013330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013334: b           L_8001333C
    // 0x80013338: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
        goto L_8001333C;
    // 0x80013338: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
L_8001333C:
    // 0x8001333C: blez        $t7, L_8001334C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80013340: andi        $t9, $a3, 0x3FF
        ctx->r25 = ctx->r7 & 0X3FF;
            goto L_8001334C;
    }
    // 0x80013340: andi        $t9, $a3, 0x3FF
    ctx->r25 = ctx->r7 & 0X3FF;
    // 0x80013344: b           L_8001334C
    // 0x80013348: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8001334C;
    // 0x80013348: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8001334C:
    // 0x8001334C: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x80013350: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80013354: sll         $t7, $t9, 14
    ctx->r15 = S32(ctx->r25 << 14);
    // 0x80013358: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8001335C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80013360: lhu         $a1, 0x224($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X224);
L_80013364:
    // 0x80013364: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80013368: andi        $t9, $a1, 0x1
    ctx->r25 = ctx->r5 & 0X1;
    // 0x8001336C: addiu       $t0, $t0, -0x2A44
    ctx->r8 = ADD32(ctx->r8, -0X2A44);
    // 0x80013370: beq         $t9, $zero, L_80013708
    if (ctx->r25 == 0) {
        // 0x80013374: lui         $t5, 0xF600
        ctx->r13 = S32(0XF600 << 16);
            goto L_80013708;
    }
    // 0x80013374: lui         $t5, 0xF600
    ctx->r13 = S32(0XF600 << 16);
    // 0x80013378: lhu         $t6, 0x226($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X226);
    // 0x8001337C: andi        $t7, $a1, 0x8
    ctx->r15 = ctx->r5 & 0X8;
    // 0x80013380: blezl       $t6, L_8001370C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80013384: lw          $v1, 0x0($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X0);
            goto L_8001370C;
    }
    goto skip_7;
    // 0x80013384: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    skip_7:
    // 0x80013388: beql        $t7, $zero, L_800133BC
    if (ctx->r15 == 0) {
        // 0x8001338C: lw          $v1, 0x0($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X0);
            goto L_800133BC;
    }
    goto skip_8;
    // 0x8001338C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    skip_8:
    // 0x80013390: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80013394: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80013398: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x8001339C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800133A0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800133A4: ori         $t6, $t6, 0x4240
    ctx->r14 = ctx->r14 | 0X4240;
    // 0x800133A8: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800133AC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800133B0: b           L_800133DC
    // 0x800133B4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
        goto L_800133DC;
    // 0x800133B4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800133B8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
L_800133BC:
    // 0x800133BC: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x800133C0: lui         $t9, 0xF0A
    ctx->r25 = S32(0XF0A << 16);
    // 0x800133C4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800133C8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800133CC: ori         $t9, $t9, 0x4000
    ctx->r25 = ctx->r25 | 0X4000;
    // 0x800133D0: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x800133D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800133D8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_800133DC:
    // 0x800133DC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800133E0: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x800133E4: lui         $t8, 0xFFFD
    ctx->r24 = S32(0XFFFD << 16);
    // 0x800133E8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800133EC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800133F0: ori         $t8, $t8, 0xF6FB
    ctx->r24 = ctx->r24 | 0XF6FB;
    // 0x800133F4: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800133F8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800133FC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80013400: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80013404: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80013408: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8001340C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80013410: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80013414: lbu         $t8, 0x228($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X228);
    // 0x80013418: lbu         $t7, 0x229($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X229);
    // 0x8001341C: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80013420: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80013424: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80013428: lbu         $t9, 0x22A($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X22A);
    // 0x8001342C: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x80013430: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80013434: lbu         $t6, 0x22B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X22B);
    // 0x80013438: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8001343C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80013440: lh          $t9, 0x212($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X212);
    // 0x80013444: lhu         $a2, 0x226($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X226);
    // 0x80013448: lh          $t7, 0x20E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X20E);
    // 0x8001344C: lh          $ra, 0x210($sp)
    ctx->r31 = MEM_H(ctx->r29, 0X210);
    // 0x80013450: addu        $a1, $t9, $a2
    ctx->r5 = ADD32(ctx->r25, ctx->r6);
    // 0x80013454: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80013458: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001345C: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x80013460: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80013464: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80013468: beq         $at, $zero, L_80013474
    if (ctx->r1 == 0) {
        // 0x8001346C: lh          $t9, 0x20E($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X20E);
            goto L_80013474;
    }
    // 0x8001346C: lh          $t9, 0x20E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X20E);
    // 0x80013470: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
L_80013474:
    // 0x80013474: lh          $t7, 0x212($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X212);
    // 0x80013478: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x8001347C: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80013480: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80013484: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x80013488: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001348C: beq         $at, $zero, L_80013498
    if (ctx->r1 == 0) {
        // 0x80013490: sra         $t1, $t1, 16
        ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
            goto L_80013498;
    }
    // 0x80013490: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80013494: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
L_80013498:
    // 0x80013498: lh          $t9, 0x20C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X20C);
    // 0x8001349C: addu        $v0, $ra, $a2
    ctx->r2 = ADD32(ctx->r31, ctx->r6);
    // 0x800134A0: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800134A4: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800134A8: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x800134AC: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800134B0: beq         $at, $zero, L_800134BC
    if (ctx->r1 == 0) {
        // 0x800134B4: sra         $t3, $t3, 16
        ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
            goto L_800134BC;
    }
    // 0x800134B4: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800134B8: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
L_800134BC:
    // 0x800134BC: lh          $t7, 0x20C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X20C);
    // 0x800134C0: subu        $v0, $t7, $a2
    ctx->r2 = SUB32(ctx->r15, ctx->r6);
    // 0x800134C4: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800134C8: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800134CC: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x800134D0: slt         $at, $t8, $ra
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x800134D4: beq         $at, $zero, L_800134E4
    if (ctx->r1 == 0) {
        // 0x800134D8: sra         $t4, $t4, 16
        ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
            goto L_800134E4;
    }
    // 0x800134D8: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800134DC: sll         $t4, $ra, 16
    ctx->r12 = S32(ctx->r31 << 16);
    // 0x800134E0: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
L_800134E4:
    // 0x800134E4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800134E8: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x800134EC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800134F0: blez        $t2, L_80013500
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800134F4: lh          $t7, 0x20C($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X20C);
            goto L_80013500;
    }
    // 0x800134F4: lh          $t7, 0x20C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X20C);
    // 0x800134F8: b           L_80013504
    // 0x800134FC: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
        goto L_80013504;
    // 0x800134FC: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
L_80013500:
    // 0x80013500: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80013504:
    // 0x80013504: blezl       $t7, L_80013518
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80013508: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80013518;
    }
    goto skip_9;
    // 0x80013508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_9:
    // 0x8001350C: b           L_80013518
    // 0x80013510: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80013518;
    // 0x80013510: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80013514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80013518:
    // 0x80013518: andi        $t6, $v0, 0x3FF
    ctx->r14 = ctx->r2 & 0X3FF;
    // 0x8001351C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80013520: andi        $t7, $a3, 0x3FF
    ctx->r15 = ctx->r7 & 0X3FF;
    // 0x80013524: sll         $t6, $t7, 14
    ctx->r14 = S32(ctx->r15 << 14);
    // 0x80013528: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x8001352C: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80013530: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80013534: lh          $t7, 0x212($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X212);
    // 0x80013538: blezl       $t7, L_8001354C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001353C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001354C;
    }
    goto skip_10;
    // 0x8001353C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    skip_10:
    // 0x80013540: b           L_8001354C
    // 0x80013544: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
        goto L_8001354C;
    // 0x80013544: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80013548: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8001354C:
    // 0x8001354C: blez        $ra, L_8001355C
    if (SIGNED(ctx->r31) <= 0) {
        // 0x80013550: andi        $t8, $a3, 0x3FF
        ctx->r24 = ctx->r7 & 0X3FF;
            goto L_8001355C;
    }
    // 0x80013550: andi        $t8, $a3, 0x3FF
    ctx->r24 = ctx->r7 & 0X3FF;
    // 0x80013554: b           L_80013560
    // 0x80013558: or          $v0, $ra, $zero
    ctx->r2 = ctx->r31 | 0;
        goto L_80013560;
    // 0x80013558: or          $v0, $ra, $zero
    ctx->r2 = ctx->r31 | 0;
L_8001355C:
    // 0x8001355C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80013560:
    // 0x80013560: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x80013564: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80013568: sll         $t7, $t8, 14
    ctx->r15 = S32(ctx->r24 << 14);
    // 0x8001356C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80013570: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80013574: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80013578: lh          $t6, 0x20E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X20E);
    // 0x8001357C: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80013580: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80013584: blez        $t6, L_80013594
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80013588: lh          $t7, 0x20C($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X20C);
            goto L_80013594;
    }
    // 0x80013588: lh          $t7, 0x20C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X20C);
    // 0x8001358C: b           L_80013598
    // 0x80013590: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
        goto L_80013598;
    // 0x80013590: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_80013594:
    // 0x80013594: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80013598:
    // 0x80013598: blezl       $t7, L_800135AC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001359C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800135AC;
    }
    goto skip_11;
    // 0x8001359C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_11:
    // 0x800135A0: b           L_800135AC
    // 0x800135A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800135AC;
    // 0x800135A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800135A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800135AC:
    // 0x800135AC: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x800135B0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800135B4: andi        $t7, $a3, 0x3FF
    ctx->r15 = ctx->r7 & 0X3FF;
    // 0x800135B8: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x800135BC: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800135C0: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800135C4: blez        $t1, L_800135D4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800135C8: sw          $t8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r24;
            goto L_800135D4;
    }
    // 0x800135C8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800135CC: b           L_800135D8
    // 0x800135D0: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
        goto L_800135D8;
    // 0x800135D0: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
L_800135D4:
    // 0x800135D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800135D8:
    // 0x800135D8: blez        $ra, L_800135E8
    if (SIGNED(ctx->r31) <= 0) {
        // 0x800135DC: andi        $t9, $a3, 0x3FF
        ctx->r25 = ctx->r7 & 0X3FF;
            goto L_800135E8;
    }
    // 0x800135DC: andi        $t9, $a3, 0x3FF
    ctx->r25 = ctx->r7 & 0X3FF;
    // 0x800135E0: b           L_800135EC
    // 0x800135E4: or          $v0, $ra, $zero
    ctx->r2 = ctx->r31 | 0;
        goto L_800135EC;
    // 0x800135E4: or          $v0, $ra, $zero
    ctx->r2 = ctx->r31 | 0;
L_800135E8:
    // 0x800135E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800135EC:
    // 0x800135EC: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x800135F0: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800135F4: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x800135F8: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800135FC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80013600: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80013604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013608: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001360C: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80013610: blez        $t1, L_80013620
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80013614: sw          $t9, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r25;
            goto L_80013620;
    }
    // 0x80013614: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80013618: b           L_80013620
    // 0x8001361C: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
        goto L_80013620;
    // 0x8001361C: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
L_80013620:
    // 0x80013620: blez        $t3, L_80013630
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80013624: andi        $t9, $a3, 0x3FF
        ctx->r25 = ctx->r7 & 0X3FF;
            goto L_80013630;
    }
    // 0x80013624: andi        $t9, $a3, 0x3FF
    ctx->r25 = ctx->r7 & 0X3FF;
    // 0x80013628: b           L_80013630
    // 0x8001362C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_80013630;
    // 0x8001362C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80013630:
    // 0x80013630: andi        $t6, $v0, 0x3FF
    ctx->r14 = ctx->r2 & 0X3FF;
    // 0x80013634: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80013638: or          $t7, $t8, $t5
    ctx->r15 = ctx->r24 | ctx->r13;
    // 0x8001363C: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x80013640: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80013644: blez        $t2, L_80013654
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80013648: sw          $t8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r24;
            goto L_80013654;
    }
    // 0x80013648: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001364C: b           L_80013658
    // 0x80013650: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
        goto L_80013658;
    // 0x80013650: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
L_80013654:
    // 0x80013654: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80013658:
    // 0x80013658: blez        $ra, L_80013668
    if (SIGNED(ctx->r31) <= 0) {
        // 0x8001365C: andi        $t6, $a3, 0x3FF
        ctx->r14 = ctx->r7 & 0X3FF;
            goto L_80013668;
    }
    // 0x8001365C: andi        $t6, $a3, 0x3FF
    ctx->r14 = ctx->r7 & 0X3FF;
    // 0x80013660: b           L_8001366C
    // 0x80013664: or          $v0, $ra, $zero
    ctx->r2 = ctx->r31 | 0;
        goto L_8001366C;
    // 0x80013664: or          $v0, $ra, $zero
    ctx->r2 = ctx->r31 | 0;
L_80013668:
    // 0x80013668: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001366C:
    // 0x8001366C: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x80013670: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80013674: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80013678: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8001367C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80013680: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80013684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013688: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001368C: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80013690: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80013694: blez        $t1, L_800136A4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80013698: lh          $t7, 0x20C($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X20C);
            goto L_800136A4;
    }
    // 0x80013698: lh          $t7, 0x20C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X20C);
    // 0x8001369C: b           L_800136A4
    // 0x800136A0: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
        goto L_800136A4;
    // 0x800136A0: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
L_800136A4:
    // 0x800136A4: blez        $t7, L_800136B4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800136A8: nop
    
            goto L_800136B4;
    }
    // 0x800136A8: nop

    // 0x800136AC: b           L_800136B4
    // 0x800136B0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800136B4;
    // 0x800136B0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800136B4:
    // 0x800136B4: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x800136B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800136BC: andi        $t7, $a3, 0x3FF
    ctx->r15 = ctx->r7 & 0X3FF;
    // 0x800136C0: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x800136C4: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x800136C8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800136CC: blez        $t2, L_800136DC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800136D0: sw          $t9, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r25;
            goto L_800136DC;
    }
    // 0x800136D0: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800136D4: b           L_800136E0
    // 0x800136D8: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
        goto L_800136E0;
    // 0x800136D8: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
L_800136DC:
    // 0x800136DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800136E0:
    // 0x800136E0: blez        $t4, L_800136F0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800136E4: andi        $t8, $a3, 0x3FF
        ctx->r24 = ctx->r7 & 0X3FF;
            goto L_800136F0;
    }
    // 0x800136E4: andi        $t8, $a3, 0x3FF
    ctx->r24 = ctx->r7 & 0X3FF;
    // 0x800136E8: b           L_800136F4
    // 0x800136EC: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_800136F4;
    // 0x800136EC: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_800136F0:
    // 0x800136F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800136F4:
    // 0x800136F4: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x800136F8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800136FC: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x80013700: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80013704: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
L_80013708:
    // 0x80013708: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
L_8001370C:
    // 0x8001370C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80013710: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80013714: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80013718: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8001371C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80013720:
    // 0x80013720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80013724:
    // 0x80013724: addiu       $sp, $sp, 0x250
    ctx->r29 = ADD32(ctx->r29, 0X250);
    // 0x80013728: jr          $ra
    // 0x8001372C: nop

    return;
    // 0x8001372C: nop

;}
RECOMP_FUNC void FUN_80013730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013730: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80013734: sb          $t6, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r14;
    // 0x80013738: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8001373C: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80013740: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80013744: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80013748: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8001374C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013750: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x80013754: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x80013758: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x8001375C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80013760: nop

    // 0x80013764: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80013768: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
    // 0x8001376C: lw          $t1, 0x2C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X2C);
    // 0x80013770: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x80013774: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80013778: swc1        $f0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f0.u32l;
    // 0x8001377C: lw          $t3, 0x2C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X2C);
    // 0x80013780: sh          $zero, 0x10($t3)
    MEM_H(0X10, ctx->r11) = 0;
    // 0x80013784: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80013788: sh          $zero, 0x12($t4)
    MEM_H(0X12, ctx->r12) = 0;
    // 0x8001378C: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80013790: lbu         $t5, 0x4($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X4);
    // 0x80013794: sb          $t5, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r13;
    // 0x80013798: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x8001379C: lbu         $t7, 0x5($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X5);
    // 0x800137A0: sb          $t7, 0x15($t8)
    MEM_B(0X15, ctx->r24) = ctx->r15;
    // 0x800137A4: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x800137A8: lbu         $t9, 0x6($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X6);
    // 0x800137AC: sb          $t9, 0x16($t0)
    MEM_B(0X16, ctx->r8) = ctx->r25;
    // 0x800137B0: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x800137B4: lbu         $t1, 0x7($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X7);
    // 0x800137B8: sb          $t1, 0x17($t2)
    MEM_B(0X17, ctx->r10) = ctx->r9;
    // 0x800137BC: lw          $t3, 0x2C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X2C);
    // 0x800137C0: sb          $v0, 0x18($t3)
    MEM_B(0X18, ctx->r11) = ctx->r2;
    // 0x800137C4: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x800137C8: sb          $v0, 0x19($t4)
    MEM_B(0X19, ctx->r12) = ctx->r2;
    // 0x800137CC: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x800137D0: sb          $v0, 0x1A($t5)
    MEM_B(0X1A, ctx->r13) = ctx->r2;
    // 0x800137D4: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800137D8: sb          $v0, 0x1B($t6)
    MEM_B(0X1B, ctx->r14) = ctx->r2;
    // 0x800137DC: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x800137E0: lhu         $t7, 0x8($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X8);
    // 0x800137E4: sh          $t7, 0x1C($t8)
    MEM_H(0X1C, ctx->r24) = ctx->r15;
    // 0x800137E8: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x800137EC: lhu         $t9, 0xA($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XA);
    // 0x800137F0: sh          $t9, 0x1E($t0)
    MEM_H(0X1E, ctx->r8) = ctx->r25;
    // 0x800137F4: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x800137F8: lw          $t1, 0xC($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XC);
    // 0x800137FC: sw          $t1, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r9;
    // 0x80013800: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80013804: lw          $t3, 0x10($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X10);
    // 0x80013808: sw          $t3, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r11;
    // 0x8001380C: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80013810: lw          $t5, 0x14($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X14);
    // 0x80013814: sw          $t5, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r13;
    // 0x80013818: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x8001381C: lw          $t7, 0x18($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X18);
    // 0x80013820: jr          $ra
    // 0x80013824: sw          $t7, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r15;
    return;
    // 0x80013824: sw          $t7, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80013828(rdram, ctx);
;}
RECOMP_FUNC void FUN_80013828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013828: addiu       $sp, $sp, -0x218
    ctx->r29 = ADD32(ctx->r29, -0X218);
    // 0x8001382C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80013830: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80013834: addiu       $s2, $s2, -0x2A44
    ctx->r18 = ADD32(ctx->r18, -0X2A44);
    // 0x80013838: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8001383C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80013840: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80013844: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80013848: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001384C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80013850: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80013854: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80013858: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001385C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80013860: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80013864: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80013868: lui         $s7, 0xE700
    ctx->r23 = S32(0XE700 << 16);
    // 0x8001386C: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80013870: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80013874: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80013878: lui         $t8, 0xDB06
    ctx->r24 = S32(0XDB06 << 16);
    // 0x8001387C: ori         $t8, $t8, 0xC
    ctx->r24 = ctx->r24 | 0XC;
    // 0x80013880: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80013884: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80013888: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001388C: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x80013890: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80013894: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80013898: jal         0x80005204
    // 0x8001389C: lhu         $a0, 0x1E($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X1E);
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_0;
    // 0x8001389C: lhu         $a0, 0x1E($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X1E);
    after_0:
    // 0x800138A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800138A4: addu        $t6, $v0, $at
    ctx->r14 = ADD32(ctx->r2, ctx->r1);
    // 0x800138A8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800138AC: lw          $t7, 0x2C($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X2C);
    // 0x800138B0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800138B4: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x800138B8: lbu         $t8, 0x1B($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1B);
    // 0x800138BC: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x800138C0: bnel        $t8, $at, L_800138EC
    if (ctx->r24 != ctx->r1) {
        // 0x800138C4: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_800138EC;
    }
    goto skip_0;
    // 0x800138C4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x800138C8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800138CC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800138D0: addiu       $t7, $t7, 0x3830
    ctx->r15 = ADD32(ctx->r15, 0X3830);
    // 0x800138D4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800138D8: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800138DC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800138E0: b           L_80013948
    // 0x800138E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80013948;
    // 0x800138E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800138E8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_800138EC:
    // 0x800138EC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800138F0: addiu       $t6, $t6, 0x3848
    ctx->r14 = ADD32(ctx->r14, 0X3848);
    // 0x800138F4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800138F8: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800138FC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80013900: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80013904: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80013908: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8001390C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80013910: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80013914: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80013918: lw          $s0, 0x2C($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X2C);
    // 0x8001391C: lbu         $t6, 0x18($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18);
    // 0x80013920: lbu         $t9, 0x19($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X19);
    // 0x80013924: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80013928: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8001392C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80013930: lbu         $t7, 0x1A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1A);
    // 0x80013934: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x80013938: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8001393C: lbu         $t8, 0x1B($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1B);
    // 0x80013940: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80013944: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80013948:
    // 0x80013948: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8001394C: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x80013950: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80013954: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80013958: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001395C: lw          $t8, 0x2C($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X2C);
    // 0x80013960: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x80013964: lw          $t6, 0x2C($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X2C);
    // 0x80013968: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8001396C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80013970: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80013974: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80013978: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x8001397C: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80013980: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80013984: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80013988: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8001398C: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80013990: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80013994: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80013998: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8001399C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800139A0: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800139A4: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800139A8: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x800139AC: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x800139B0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800139B4: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800139B8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800139BC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800139C0: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x800139C4: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x800139C8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800139CC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800139D0: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800139D4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800139D8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800139DC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800139E0: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800139E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800139E8: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x800139EC: lw          $s0, 0x2C($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X2C);
    // 0x800139F0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800139F4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800139F8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800139FC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80013A00: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80013A04: mfc1        $s3, $f6
    ctx->r19 = (int32_t)ctx->f6.u32l;
    // 0x80013A08: nop

    // 0x80013A0C: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x80013A10: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80013A14: mfc1        $s4, $f10
    ctx->r20 = (int32_t)ctx->f10.u32l;
    // 0x80013A18: nop

    // 0x80013A1C: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x80013A20: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80013A24: bgez        $s3, L_80013A38
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80013A28: andi        $t1, $s3, 0x1F
        ctx->r9 = ctx->r19 & 0X1F;
            goto L_80013A38;
    }
    // 0x80013A28: andi        $t1, $s3, 0x1F
    ctx->r9 = ctx->r19 & 0X1F;
    // 0x80013A2C: beq         $t1, $zero, L_80013A38
    if (ctx->r9 == 0) {
        // 0x80013A30: nop
    
            goto L_80013A38;
    }
    // 0x80013A30: nop

    // 0x80013A34: addiu       $t1, $t1, -0x20
    ctx->r9 = ADD32(ctx->r9, -0X20);
L_80013A38:
    // 0x80013A38: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
    // 0x80013A3C: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80013A40: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80013A44: blez        $t2, L_80013A54
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80013A48: sh          $t1, 0x20E($sp)
        MEM_H(0X20E, ctx->r29) = ctx->r9;
            goto L_80013A54;
    }
    // 0x80013A48: sh          $t1, 0x20E($sp)
    MEM_H(0X20E, ctx->r29) = ctx->r9;
    // 0x80013A4C: addiu       $t9, $t2, -0x20
    ctx->r25 = ADD32(ctx->r10, -0X20);
    // 0x80013A50: sh          $t9, 0x20E($sp)
    MEM_H(0X20E, ctx->r29) = ctx->r25;
L_80013A54:
    // 0x80013A54: bgez        $s4, L_80013A68
    if (SIGNED(ctx->r20) >= 0) {
        // 0x80013A58: andi        $v0, $s4, 0x1F
        ctx->r2 = ctx->r20 & 0X1F;
            goto L_80013A68;
    }
    // 0x80013A58: andi        $v0, $s4, 0x1F
    ctx->r2 = ctx->r20 & 0X1F;
    // 0x80013A5C: beq         $v0, $zero, L_80013A68
    if (ctx->r2 == 0) {
        // 0x80013A60: nop
    
            goto L_80013A68;
    }
    // 0x80013A60: nop

    // 0x80013A64: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
L_80013A68:
    // 0x80013A68: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80013A6C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80013A70: sll         $s6, $v0, 16
    ctx->r22 = S32(ctx->r2 << 16);
    // 0x80013A74: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80013A78: blez        $v1, L_80013A8C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80013A7C: sra         $s6, $s6, 16
        ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
            goto L_80013A8C;
    }
    // 0x80013A7C: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x80013A80: addiu       $s6, $v1, -0x20
    ctx->r22 = ADD32(ctx->r3, -0X20);
    // 0x80013A84: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x80013A88: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
L_80013A8C:
    // 0x80013A8C: lbu         $t6, 0x14($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X14);
    // 0x80013A90: lbu         $t7, 0x16($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X16);
    // 0x80013A94: lh          $t8, 0x20E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X20E);
    // 0x80013A98: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013A9C: addu        $s3, $s3, $t8
    ctx->r19 = ADD32(ctx->r19, ctx->r24);
    // 0x80013AA0: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x80013AA4: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80013AA8: mflo        $v0
    ctx->r2 = lo;
    // 0x80013AAC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80013AB0: nop

    // 0x80013AB4: div         $zero, $s3, $v0
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r2)));
    // 0x80013AB8: bne         $v0, $zero, L_80013AC4
    if (ctx->r2 != 0) {
        // 0x80013ABC: nop
    
            goto L_80013AC4;
    }
    // 0x80013ABC: nop

    // 0x80013AC0: break       7
    do_break(2147564224);
L_80013AC4:
    // 0x80013AC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013AC8: bne         $v0, $at, L_80013ADC
    if (ctx->r2 != ctx->r1) {
        // 0x80013ACC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80013ADC;
    }
    // 0x80013ACC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013AD0: bne         $s3, $at, L_80013ADC
    if (ctx->r19 != ctx->r1) {
        // 0x80013AD4: nop
    
            goto L_80013ADC;
    }
    // 0x80013AD4: nop

    // 0x80013AD8: break       6
    do_break(2147564248);
L_80013ADC:
    // 0x80013ADC: mfhi        $s3
    ctx->r19 = hi;
    // 0x80013AE0: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x80013AE4: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80013AE8: bgezl       $s3, L_80013B00
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80013AEC: lbu         $t9, 0x15($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X15);
            goto L_80013B00;
    }
    goto skip_1;
    // 0x80013AEC: lbu         $t9, 0x15($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15);
    skip_1:
    // 0x80013AF0: addu        $s3, $v0, $s3
    ctx->r19 = ADD32(ctx->r2, ctx->r19);
    // 0x80013AF4: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x80013AF8: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80013AFC: lbu         $t9, 0x15($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15);
L_80013B00:
    // 0x80013B00: lbu         $t8, 0x17($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X17);
    // 0x80013B04: addu        $s4, $s4, $s6
    ctx->r20 = ADD32(ctx->r20, ctx->r22);
    // 0x80013B08: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x80013B0C: multu       $t9, $t8
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013B10: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80013B14: mflo        $v0
    ctx->r2 = lo;
    // 0x80013B18: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80013B1C: nop

    // 0x80013B20: div         $zero, $s4, $v0
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r2)));
    // 0x80013B24: bne         $v0, $zero, L_80013B30
    if (ctx->r2 != 0) {
        // 0x80013B28: nop
    
            goto L_80013B30;
    }
    // 0x80013B28: nop

    // 0x80013B2C: break       7
    do_break(2147564332);
L_80013B30:
    // 0x80013B30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013B34: bne         $v0, $at, L_80013B48
    if (ctx->r2 != ctx->r1) {
        // 0x80013B38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80013B48;
    }
    // 0x80013B38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013B3C: bne         $s4, $at, L_80013B48
    if (ctx->r20 != ctx->r1) {
        // 0x80013B40: nop
    
            goto L_80013B48;
    }
    // 0x80013B40: nop

    // 0x80013B44: break       6
    do_break(2147564356);
L_80013B48:
    // 0x80013B48: mfhi        $s4
    ctx->r20 = hi;
    // 0x80013B4C: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x80013B50: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80013B54: bgezl       $s4, L_80013B6C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x80013B58: lhu         $a0, 0x1E($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X1E);
            goto L_80013B6C;
    }
    goto skip_2;
    // 0x80013B58: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
    skip_2:
    // 0x80013B5C: addu        $s4, $v0, $s4
    ctx->r20 = ADD32(ctx->r2, ctx->r20);
    // 0x80013B60: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x80013B64: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80013B68: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
L_80013B6C:
    // 0x80013B6C: jal         0x8000522C
    // 0x80013B70: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_1;
    // 0x80013B70: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    after_1:
    // 0x80013B74: lw          $s0, 0x2C($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X2C);
    // 0x80013B78: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80013B7C: lhu         $a0, 0x1E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1E);
    // 0x80013B80: jal         0x8000522C
    // 0x80013B84: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_2;
    // 0x80013B84: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    after_2:
    // 0x80013B88: lw          $s0, 0x2C($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X2C);
    // 0x80013B8C: bgez        $s4, L_80013B9C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x80013B90: sra         $t0, $s4, 5
        ctx->r8 = S32(SIGNED(ctx->r20) >> 5);
            goto L_80013B9C;
    }
    // 0x80013B90: sra         $t0, $s4, 5
    ctx->r8 = S32(SIGNED(ctx->r20) >> 5);
    // 0x80013B94: addiu       $at, $s4, 0x1F
    ctx->r1 = ADD32(ctx->r20, 0X1F);
    // 0x80013B98: sra         $t0, $at, 5
    ctx->r8 = S32(SIGNED(ctx->r1) >> 5);
L_80013B9C:
    // 0x80013B9C: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x80013BA0: lbu         $a3, 0x14($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X14);
    // 0x80013BA4: lbu         $a1, 0x16($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X16);
    // 0x80013BA8: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80013BAC: sw          $s5, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r21;
    // 0x80013BB0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80013BB4: bgez        $s3, L_80013BC4
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80013BB8: sra         $t4, $s3, 5
        ctx->r12 = S32(SIGNED(ctx->r19) >> 5);
            goto L_80013BC4;
    }
    // 0x80013BB8: sra         $t4, $s3, 5
    ctx->r12 = S32(SIGNED(ctx->r19) >> 5);
    // 0x80013BBC: addiu       $at, $s3, 0x1F
    ctx->r1 = ADD32(ctx->r19, 0X1F);
    // 0x80013BC0: sra         $t4, $at, 5
    ctx->r12 = S32(SIGNED(ctx->r1) >> 5);
L_80013BC4:
    // 0x80013BC4: or          $t2, $s5, $zero
    ctx->r10 = ctx->r21 | 0;
L_80013BC8:
    // 0x80013BC8: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80013BCC: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80013BD0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80013BD4: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80013BD8: sll         $a0, $t4, 16
    ctx->r4 = S32(ctx->r12 << 16);
    // 0x80013BDC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80013BE0: addiu       $t9, $sp, 0x138
    ctx->r25 = ADD32(ctx->r29, 0X138);
    // 0x80013BE4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80013BE8: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x80013BEC: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80013BF0:
    // 0x80013BF0: div         $zero, $a0, $a1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r5)));
    // 0x80013BF4: mflo        $t8
    ctx->r24 = lo;
    // 0x80013BF8: lbu         $v1, 0x17($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X17);
    // 0x80013BFC: addu        $t6, $t8, $s1
    ctx->r14 = ADD32(ctx->r24, ctx->r17);
    // 0x80013C00: bne         $a1, $zero, L_80013C0C
    if (ctx->r5 != 0) {
        // 0x80013C04: nop
    
            goto L_80013C0C;
    }
    // 0x80013C04: nop

    // 0x80013C08: break       7
    do_break(2147564552);
L_80013C0C:
    // 0x80013C0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013C10: bne         $a1, $at, L_80013C24
    if (ctx->r5 != ctx->r1) {
        // 0x80013C14: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80013C24;
    }
    // 0x80013C14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013C18: bne         $a0, $at, L_80013C24
    if (ctx->r4 != ctx->r1) {
        // 0x80013C1C: nop
    
            goto L_80013C24;
    }
    // 0x80013C1C: nop

    // 0x80013C20: break       6
    do_break(2147564576);
L_80013C24:
    // 0x80013C24: div         $zero, $t0, $v1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r3)));
    // 0x80013C28: mflo        $t7
    ctx->r15 = lo;
    // 0x80013C2C: bne         $v1, $zero, L_80013C38
    if (ctx->r3 != 0) {
        // 0x80013C30: nop
    
            goto L_80013C38;
    }
    // 0x80013C30: nop

    // 0x80013C34: break       7
    do_break(2147564596);
L_80013C38:
    // 0x80013C38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013C3C: bne         $v1, $at, L_80013C50
    if (ctx->r3 != ctx->r1) {
        // 0x80013C40: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80013C50;
    }
    // 0x80013C40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013C44: bne         $t0, $at, L_80013C50
    if (ctx->r8 != ctx->r1) {
        // 0x80013C48: nop
    
            goto L_80013C50;
    }
    // 0x80013C48: nop

    // 0x80013C4C: break       6
    do_break(2147564620);
L_80013C50:
    // 0x80013C50: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013C54: mflo        $t9
    ctx->r25 = lo;
    // 0x80013C58: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80013C5C: lbu         $a2, 0x0($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X0);
    // 0x80013C60: multu       $a2, $a1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013C64: mflo        $t7
    ctx->r15 = lo;
    // 0x80013C68: nop

    // 0x80013C6C: nop

    // 0x80013C70: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013C74: mflo        $t6
    ctx->r14 = lo;
    // 0x80013C78: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x80013C7C: addu        $t8, $v0, $t9
    ctx->r24 = ADD32(ctx->r2, ctx->r25);
    // 0x80013C80: div         $zero, $a0, $a1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r5)));
    // 0x80013C84: mfhi        $t7
    ctx->r15 = hi;
    // 0x80013C88: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x80013C8C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80013C90: div         $zero, $t0, $v1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r3)));
    // 0x80013C94: mfhi        $t7
    ctx->r15 = hi;
    // 0x80013C98: bne         $a1, $zero, L_80013CA4
    if (ctx->r5 != 0) {
        // 0x80013C9C: nop
    
            goto L_80013CA4;
    }
    // 0x80013C9C: nop

    // 0x80013CA0: break       7
    do_break(2147564704);
L_80013CA4:
    // 0x80013CA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013CA8: bne         $a1, $at, L_80013CBC
    if (ctx->r5 != ctx->r1) {
        // 0x80013CAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80013CBC;
    }
    // 0x80013CAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013CB0: bne         $a0, $at, L_80013CBC
    if (ctx->r4 != ctx->r1) {
        // 0x80013CB4: nop
    
            goto L_80013CBC;
    }
    // 0x80013CB4: nop

    // 0x80013CB8: break       6
    do_break(2147564728);
L_80013CBC:
    // 0x80013CBC: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013CC0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80013CC4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80013CC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80013CCC: bne         $v1, $zero, L_80013CD8
    if (ctx->r3 != 0) {
        // 0x80013CD0: nop
    
            goto L_80013CD8;
    }
    // 0x80013CD0: nop

    // 0x80013CD4: break       7
    do_break(2147564756);
L_80013CD8:
    // 0x80013CD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013CDC: bne         $v1, $at, L_80013CF0
    if (ctx->r3 != ctx->r1) {
        // 0x80013CE0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80013CF0;
    }
    // 0x80013CE0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013CE4: bne         $t0, $at, L_80013CF0
    if (ctx->r8 != ctx->r1) {
        // 0x80013CE8: nop
    
            goto L_80013CF0;
    }
    // 0x80013CE8: nop

    // 0x80013CEC: break       6
    do_break(2147564780);
L_80013CF0:
    // 0x80013CF0: mflo        $t8
    ctx->r24 = lo;
    // 0x80013CF4: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x80013CF8: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80013CFC: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80013D00: sll         $t9, $s7, 1
    ctx->r25 = S32(ctx->r23 << 1);
    // 0x80013D04: addu        $t6, $t1, $t9
    ctx->r14 = ADD32(ctx->r9, ctx->r25);
    // 0x80013D08: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x80013D0C: lw          $s0, 0x2C($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X2C);
    // 0x80013D10: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80013D14: sll         $s7, $s7, 16
    ctx->r23 = S32(ctx->r23 << 16);
    // 0x80013D18: lbu         $a3, 0x14($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X14);
    // 0x80013D1C: lbu         $a1, 0x16($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X16);
    // 0x80013D20: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x80013D24: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013D28: mflo        $t7
    ctx->r15 = lo;
    // 0x80013D2C: nop

    // 0x80013D30: nop

    // 0x80013D34: div         $zero, $a0, $t7
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r15)));
    // 0x80013D38: bne         $t7, $zero, L_80013D44
    if (ctx->r15 != 0) {
        // 0x80013D3C: nop
    
            goto L_80013D44;
    }
    // 0x80013D3C: nop

    // 0x80013D40: break       7
    do_break(2147564864);
L_80013D44:
    // 0x80013D44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013D48: bne         $t7, $at, L_80013D5C
    if (ctx->r15 != ctx->r1) {
        // 0x80013D4C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80013D5C;
    }
    // 0x80013D4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013D50: bne         $a0, $at, L_80013D5C
    if (ctx->r4 != ctx->r1) {
        // 0x80013D54: nop
    
            goto L_80013D5C;
    }
    // 0x80013D54: nop

    // 0x80013D58: break       6
    do_break(2147564888);
L_80013D5C:
    // 0x80013D5C: mfhi        $a0
    ctx->r4 = hi;
    // 0x80013D60: slti        $at, $s7, 0xB
    ctx->r1 = SIGNED(ctx->r23) < 0XB ? 1 : 0;
    // 0x80013D64: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80013D68: bne         $at, $zero, L_80013BF0
    if (ctx->r1 != 0) {
        // 0x80013D6C: sra         $a0, $a0, 16
        ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
            goto L_80013BF0;
    }
    // 0x80013D6C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80013D70: lbu         $t9, 0x15($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15);
    // 0x80013D74: lbu         $t8, 0x17($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X17);
    // 0x80013D78: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80013D7C: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x80013D80: multu       $t9, $t8
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013D84: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80013D88: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80013D8C: sll         $t3, $t3, 16
    ctx->r11 = S32(ctx->r11 << 16);
    // 0x80013D90: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80013D94: mflo        $t6
    ctx->r14 = lo;
    // 0x80013D98: nop

    // 0x80013D9C: nop

    // 0x80013DA0: div         $zero, $t0, $t6
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r14)));
    // 0x80013DA4: bne         $t6, $zero, L_80013DB0
    if (ctx->r14 != 0) {
        // 0x80013DA8: nop
    
            goto L_80013DB0;
    }
    // 0x80013DA8: nop

    // 0x80013DAC: break       7
    do_break(2147564972);
L_80013DB0:
    // 0x80013DB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013DB4: bne         $t6, $at, L_80013DC8
    if (ctx->r14 != ctx->r1) {
        // 0x80013DB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80013DC8;
    }
    // 0x80013DB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013DBC: bne         $t0, $at, L_80013DC8
    if (ctx->r8 != ctx->r1) {
        // 0x80013DC0: nop
    
            goto L_80013DC8;
    }
    // 0x80013DC0: nop

    // 0x80013DC4: break       6
    do_break(2147564996);
L_80013DC8:
    // 0x80013DC8: mfhi        $t0
    ctx->r8 = hi;
    // 0x80013DCC: slti        $at, $t3, 0x9
    ctx->r1 = SIGNED(ctx->r11) < 0X9 ? 1 : 0;
    // 0x80013DD0: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x80013DD4: bne         $at, $zero, L_80013BC8
    if (ctx->r1 != 0) {
        // 0x80013DD8: sra         $t0, $t0, 16
        ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
            goto L_80013BC8;
    }
    // 0x80013DD8: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80013DDC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_80013DE0:
    // 0x80013DE0: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x80013DE4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80013DE8: sll         $t3, $t3, 16
    ctx->r11 = S32(ctx->r11 << 16);
    // 0x80013DEC: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80013DF0: slti        $at, $t3, 0x9
    ctx->r1 = SIGNED(ctx->r11) < 0X9 ? 1 : 0;
    // 0x80013DF4: addu        $t9, $sp, $t7
    ctx->r25 = ADD32(ctx->r29, ctx->r15);
    // 0x80013DF8: bne         $at, $zero, L_80013DE0
    if (ctx->r1 != 0) {
        // 0x80013DFC: sh          $zero, 0x124($t9)
        MEM_H(0X124, ctx->r25) = 0;
            goto L_80013DE0;
    }
    // 0x80013DFC: sh          $zero, 0x124($t9)
    MEM_H(0X124, ctx->r25) = 0;
    // 0x80013E00: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80013E04: addiu       $a0, $a0, -0x6D50
    ctx->r4 = ADD32(ctx->r4, -0X6D50);
    // 0x80013E08: sh          $zero, 0x202($sp)
    MEM_H(0X202, ctx->r29) = 0;
    // 0x80013E0C: sh          $s6, 0x20A($sp)
    MEM_H(0X20A, ctx->r29) = ctx->r22;
L_80013E10:
    // 0x80013E10: lh          $t6, 0x202($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X202);
    // 0x80013E14: lh          $t8, 0x20A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X20A);
    // 0x80013E18: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80013E1C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80013E20: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80013E24: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80013E28: addiu       $t7, $sp, 0x124
    ctx->r15 = ADD32(ctx->r29, 0X124);
    // 0x80013E2C: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80013E30: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80013E34: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x80013E38: sh          $zero, 0x206($sp)
    MEM_H(0X206, ctx->r29) = 0;
L_80013E3C:
    // 0x80013E3C: lh          $t8, 0x206($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X206);
    // 0x80013E40: lh          $t6, 0x20E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X20E);
    // 0x80013E44: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
    // 0x80013E48: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x80013E4C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80013E50: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80013E54: lh          $t9, 0x66($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X66);
    // 0x80013E58: sll         $s4, $v0, 16
    ctx->r20 = S32(ctx->r2 << 16);
    // 0x80013E5C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80013E60: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80013E64: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x80013E68: and         $t7, $t7, $s0
    ctx->r15 = ctx->r15 & ctx->r16;
    // 0x80013E6C: bnel        $t7, $zero, L_80014624
    if (ctx->r15 != 0) {
        // 0x80013E70: lh          $t7, 0x206($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X206);
            goto L_80014624;
    }
    goto skip_3;
    // 0x80013E70: lh          $t7, 0x206($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X206);
    skip_3:
    // 0x80013E74: lh          $t6, 0x1B8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1B8);
    // 0x80013E78: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80013E7C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80013E80: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80013E84: bnel        $at, $zero, L_80014624
    if (ctx->r1 != 0) {
        // 0x80013E88: lh          $t7, 0x206($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X206);
            goto L_80014624;
    }
    goto skip_4;
    // 0x80013E88: lh          $t7, 0x206($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X206);
    skip_4:
    // 0x80013E8C: lh          $t7, 0x1B4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1B4);
    // 0x80013E90: addiu       $t6, $v1, 0x20
    ctx->r14 = ADD32(ctx->r3, 0X20);
    // 0x80013E94: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80013E98: bnel        $at, $zero, L_80014624
    if (ctx->r1 != 0) {
        // 0x80013E9C: lh          $t7, 0x206($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X206);
            goto L_80014624;
    }
    goto skip_5;
    // 0x80013E9C: lh          $t7, 0x206($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X206);
    skip_5:
    // 0x80013EA0: lh          $t7, 0x1BA($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1BA);
    // 0x80013EA4: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80013EA8: bnel        $at, $zero, L_80014624
    if (ctx->r1 != 0) {
        // 0x80013EAC: lh          $t7, 0x206($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X206);
            goto L_80014624;
    }
    goto skip_6;
    // 0x80013EAC: lh          $t7, 0x206($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X206);
    skip_6:
    // 0x80013EB0: lh          $t6, 0x1B6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1B6);
    // 0x80013EB4: lh          $t7, 0x202($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X202);
    // 0x80013EB8: addiu       $t9, $t9, 0x20
    ctx->r25 = ADD32(ctx->r25, 0X20);
    // 0x80013EBC: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80013EC0: bne         $at, $zero, L_80014620
    if (ctx->r1 != 0) {
        // 0x80013EC4: sll         $t6, $t7, 2
        ctx->r14 = S32(ctx->r15 << 2);
            goto L_80014620;
    }
    // 0x80013EC4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80013EC8: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80013ECC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80013ED0: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80013ED4: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x80013ED8: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x80013EDC: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80013EE0: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80013EE4: lhu         $t9, 0x138($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X138);
    // 0x80013EE8: lw          $t8, 0x218($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X218);
    // 0x80013EEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80013EF0: andi        $t6, $t9, 0xF3FF
    ctx->r14 = ctx->r25 & 0XF3FF;
    // 0x80013EF4: sh          $t6, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r14;
    // 0x80013EF8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80013EFC: lhu         $v1, 0x1C($t9)
    ctx->r3 = MEM_HU(ctx->r25, 0X1C);
    // 0x80013F00: sh          $t7, 0x200($sp)
    MEM_H(0X200, ctx->r29) = ctx->r15;
    // 0x80013F04: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x80013F08: beq         $v1, $at, L_80013F20
    if (ctx->r3 == ctx->r1) {
        // 0x80013F0C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80013F20;
    }
    // 0x80013F0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80013F10: beql        $v1, $at, L_8001402C
    if (ctx->r3 == ctx->r1) {
        // 0x80013F14: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_8001402C;
    }
    goto skip_7;
    // 0x80013F14: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_7:
    // 0x80013F18: b           L_80014114
    // 0x80013F1C: lh          $t8, 0x202($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X202);
        goto L_80014114;
    // 0x80013F1C: lh          $t8, 0x202($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X202);
L_80013F20:
    // 0x80013F20: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80013F24: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x80013F28: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80013F2C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80013F30: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80013F34: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80013F38: lw          $t9, 0x218($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X218);
    // 0x80013F3C: lhu         $t2, 0x136($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X136);
    // 0x80013F40: lw          $t7, 0x2C($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X2C);
    // 0x80013F44: andi        $t8, $t2, 0x3FF
    ctx->r24 = ctx->r10 & 0X3FF;
    // 0x80013F48: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x80013F4C: lw          $t6, 0x28($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X28);
    // 0x80013F50: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80013F54: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80013F58: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80013F5C: lui         $t9, 0x705
    ctx->r25 = S32(0X705 << 16);
    // 0x80013F60: ori         $t9, $t9, 0xC170
    ctx->r25 = ctx->r25 | 0XC170;
    // 0x80013F64: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80013F68: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80013F6C: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x80013F70: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80013F74: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80013F78: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80013F7C: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80013F80: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80013F84: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80013F88: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80013F8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80013F90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80013F94: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80013F98: lui         $t7, 0x70F
    ctx->r15 = S32(0X70F << 16);
    // 0x80013F9C: ori         $t7, $t7, 0xF400
    ctx->r15 = ctx->r15 | 0XF400;
    // 0x80013FA0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80013FA4: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80013FA8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80013FAC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80013FB0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80013FB4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80013FB8: lui         $t7, 0xF540
    ctx->r15 = S32(0XF540 << 16);
    // 0x80013FBC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80013FC0: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80013FC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80013FC8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80013FCC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80013FD0: sra         $t8, $t2, 12
    ctx->r24 = S32(SIGNED(ctx->r10) >> 12);
    // 0x80013FD4: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x80013FD8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80013FDC: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80013FE0: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80013FE4: sll         $t9, $t6, 20
    ctx->r25 = S32(ctx->r14 << 20);
    // 0x80013FE8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80013FEC: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80013FF0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80013FF4: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80013FF8: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x80013FFC: ori         $t9, $t6, 0x170
    ctx->r25 = ctx->r14 | 0X170;
    // 0x80014000: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80014004: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80014008: lui         $t6, 0x7
    ctx->r14 = S32(0X7 << 16);
    // 0x8001400C: ori         $t6, $t6, 0xC07C
    ctx->r14 = ctx->r14 | 0XC07C;
    // 0x80014010: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80014014: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80014018: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8001401C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80014020: b           L_80014110
    // 0x80014024: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_80014110;
    // 0x80014024: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80014028: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_8001402C:
    // 0x8001402C: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x80014030: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80014034: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80014038: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001403C: lw          $t8, 0x218($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X218);
    // 0x80014040: lhu         $t7, 0x136($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X136);
    // 0x80014044: lw          $t6, 0x2C($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X2C);
    // 0x80014048: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8001404C: lw          $t9, 0x28($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X28);
    // 0x80014050: sll         $t6, $t8, 10
    ctx->r14 = S32(ctx->r24 << 10);
    // 0x80014054: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80014058: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001405C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80014060: lui         $t6, 0x705
    ctx->r14 = S32(0X705 << 16);
    // 0x80014064: ori         $t6, $t6, 0xC170
    ctx->r14 = ctx->r14 | 0XC170;
    // 0x80014068: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001406C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80014070: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x80014074: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80014078: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001407C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80014080: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80014084: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80014088: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001408C: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80014090: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80014094: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80014098: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8001409C: lui         $t7, 0x71F
    ctx->r15 = S32(0X71F << 16);
    // 0x800140A0: ori         $t7, $t7, 0xF200
    ctx->r15 = ctx->r15 | 0XF200;
    // 0x800140A4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800140A8: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800140AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800140B0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800140B4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800140B8: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800140BC: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x800140C0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800140C4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800140C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800140CC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800140D0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800140D4: lui         $t8, 0x5
    ctx->r24 = S32(0X5 << 16);
    // 0x800140D8: ori         $t8, $t8, 0xC170
    ctx->r24 = ctx->r24 | 0XC170;
    // 0x800140DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800140E0: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800140E4: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x800140E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800140EC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800140F0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800140F4: lui         $t7, 0x7
    ctx->r15 = S32(0X7 << 16);
    // 0x800140F8: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x800140FC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80014100: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80014104: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80014108: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001410C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80014110:
    // 0x80014110: lh          $t8, 0x202($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X202);
L_80014114:
    // 0x80014114: lh          $s7, 0x206($sp)
    ctx->r23 = MEM_H(ctx->r29, 0X206);
    // 0x80014118: andi        $fp, $s0, 0xFFFF
    ctx->r30 = ctx->r16 & 0XFFFF;
    // 0x8001411C: slti        $at, $t8, 0x9
    ctx->r1 = SIGNED(ctx->r24) < 0X9 ? 1 : 0;
    // 0x80014120: beq         $at, $zero, L_80014620
    if (ctx->r1 == 0) {
        // 0x80014124: slti        $at, $s7, 0xB
        ctx->r1 = SIGNED(ctx->r23) < 0XB ? 1 : 0;
            goto L_80014620;
    }
L_80014124:
    // 0x80014124: slti        $at, $s7, 0xB
    ctx->r1 = SIGNED(ctx->r23) < 0XB ? 1 : 0;
    // 0x80014128: beq         $at, $zero, L_800145EC
    if (ctx->r1 == 0) {
        // 0x8001412C: lh          $t9, 0x200($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X200);
            goto L_800145EC;
    }
    // 0x8001412C: lh          $t9, 0x200($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X200);
    // 0x80014130: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80014134: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80014138: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001413C: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80014140: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80014144: lhu         $t6, 0x136($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X136);
    // 0x80014148: addiu       $t8, $sp, 0x138
    ctx->r24 = ADD32(ctx->r29, 0X138);
    // 0x8001414C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80014150: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x80014154: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
L_80014158:
    // 0x80014158: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8001415C: sll         $t8, $s7, 1
    ctx->r24 = S32(ctx->r23 << 1);
    // 0x80014160: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80014164: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80014168: lhu         $v1, 0x0($t9)
    ctx->r3 = MEM_HU(ctx->r25, 0X0);
    // 0x8001416C: lh          $t8, 0x200($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X200);
    // 0x80014170: andi        $t7, $v1, 0xF3FF
    ctx->r15 = ctx->r3 & 0XF3FF;
    // 0x80014174: bne         $t6, $t7, L_800145C4
    if (ctx->r14 != ctx->r15) {
        // 0x80014178: sll         $t9, $t8, 1
        ctx->r25 = S32(ctx->r24 << 1);
            goto L_800145C4;
    }
    // 0x80014178: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8001417C: addiu       $t6, $sp, 0x124
    ctx->r14 = ADD32(ctx->r29, 0X124);
    // 0x80014180: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x80014184: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x80014188: andi        $t9, $v1, 0x800
    ctx->r25 = ctx->r3 & 0X800;
    // 0x8001418C: addiu       $s0, $t3, 0x20
    ctx->r16 = ADD32(ctx->r11, 0X20);
    // 0x80014190: or          $t8, $t7, $fp
    ctx->r24 = ctx->r15 | ctx->r30;
    // 0x80014194: beq         $t9, $zero, L_800141A8
    if (ctx->r25 == 0) {
        // 0x80014198: sh          $t8, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r24;
            goto L_800141A8;
    }
    // 0x80014198: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8001419C: addiu       $s1, $zero, -0x400
    ctx->r17 = ADD32(0, -0X400);
    // 0x800141A0: b           L_800141B0
    // 0x800141A4: addiu       $s5, $zero, 0x3E0
    ctx->r21 = ADD32(0, 0X3E0);
        goto L_800141B0;
    // 0x800141A4: addiu       $s5, $zero, 0x3E0
    ctx->r21 = ADD32(0, 0X3E0);
L_800141A8:
    // 0x800141A8: addiu       $s1, $zero, 0x400
    ctx->r17 = ADD32(0, 0X400);
    // 0x800141AC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_800141B0:
    // 0x800141B0: andi        $t6, $v1, 0x400
    ctx->r14 = ctx->r3 & 0X400;
    // 0x800141B4: beq         $t6, $zero, L_800141C8
    if (ctx->r14 == 0) {
        // 0x800141B8: addiu       $s3, $zero, 0x400
        ctx->r19 = ADD32(0, 0X400);
            goto L_800141C8;
    }
    // 0x800141B8: addiu       $s3, $zero, 0x400
    ctx->r19 = ADD32(0, 0X400);
    // 0x800141BC: addiu       $s3, $zero, -0x400
    ctx->r19 = ADD32(0, -0X400);
    // 0x800141C0: b           L_800141CC
    // 0x800141C4: addiu       $s6, $zero, 0x3E0
    ctx->r22 = ADD32(0, 0X3E0);
        goto L_800141CC;
    // 0x800141C4: addiu       $s6, $zero, 0x3E0
    ctx->r22 = ADD32(0, 0X3E0);
L_800141C8:
    // 0x800141C8: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_800141CC:
    // 0x800141CC: jal         0x80001060
    // 0x800141D0: sh          $t3, 0x208($sp)
    MEM_H(0X208, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_3;
    // 0x800141D0: sh          $t3, 0x208($sp)
    MEM_H(0X208, ctx->r29) = ctx->r11;
    after_3:
    // 0x800141D4: lh          $t3, 0x208($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X208);
    // 0x800141D8: lui         $t4, 0xE400
    ctx->r12 = S32(0XE400 << 16);
    // 0x800141DC: lui         $t5, 0xE100
    ctx->r13 = S32(0XE100 << 16);
    // 0x800141E0: beq         $v0, $zero, L_800143F8
    if (ctx->r2 == 0) {
        // 0x800141E4: lui         $ra, 0xF100
        ctx->r31 = S32(0XF100 << 16);
            goto L_800143F8;
    }
    // 0x800141E4: lui         $ra, 0xF100
    ctx->r31 = S32(0XF100 << 16);
    // 0x800141E8: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800141EC: addiu       $v1, $s4, 0x20
    ctx->r3 = ADD32(ctx->r20, 0X20);
    // 0x800141F0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800141F4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800141F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800141FC: sll         $t1, $t3, 3
    ctx->r9 = S32(ctx->r11 << 3);
    // 0x80014200: sll         $a3, $t1, 16
    ctx->r7 = S32(ctx->r9 << 16);
    // 0x80014204: sll         $a1, $a1, 19
    ctx->r5 = S32(ctx->r5 << 19);
    // 0x80014208: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001420C: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x80014210: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80014214: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80014218: blez        $v1, L_80014228
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001421C: sra         $a3, $a3, 16
        ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
            goto L_80014228;
    }
    // 0x8001421C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80014220: b           L_8001422C
    // 0x80014224: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_8001422C;
    // 0x80014224: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80014228:
    // 0x80014228: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001422C:
    // 0x8001422C: blez        $a1, L_8001423C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80014230: andi        $t6, $a0, 0xFFF
        ctx->r14 = ctx->r4 & 0XFFF;
            goto L_8001423C;
    }
    // 0x80014230: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x80014234: b           L_80014240
    // 0x80014238: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_80014240;
    // 0x80014238: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8001423C:
    // 0x8001423C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80014240:
    // 0x80014240: andi        $t8, $v1, 0xFFF
    ctx->r24 = ctx->r3 & 0XFFF;
    // 0x80014244: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80014248: sll         $a1, $a1, 19
    ctx->r5 = S32(ctx->r5 << 19);
    // 0x8001424C: or          $t9, $t8, $t4
    ctx->r25 = ctx->r24 | ctx->r12;
    // 0x80014250: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80014254: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80014258: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001425C: blez        $a1, L_8001426C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80014260: sw          $t8, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r24;
            goto L_8001426C;
    }
    // 0x80014260: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80014264: b           L_80014270
    // 0x80014268: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
        goto L_80014270;
    // 0x80014268: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8001426C:
    // 0x8001426C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80014270:
    // 0x80014270: blez        $a3, L_80014280
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80014274: andi        $t9, $a0, 0xFFF
        ctx->r25 = ctx->r4 & 0XFFF;
            goto L_80014280;
    }
    // 0x80014274: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x80014278: b           L_80014284
    // 0x8001427C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
        goto L_80014284;
    // 0x8001427C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_80014280:
    // 0x80014280: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80014284:
    // 0x80014284: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x80014288: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8001428C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80014290: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x80014294: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80014298: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001429C: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x800142A0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800142A4: bgez        $a1, L_80014320
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800142A8: sw          $t5, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r13;
            goto L_80014320;
    }
    // 0x800142A8: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x800142AC: bgez        $s1, L_800142BC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800142B0: sra         $t0, $s1, 1
        ctx->r8 = S32(SIGNED(ctx->r17) >> 1);
            goto L_800142BC;
    }
    // 0x800142B0: sra         $t0, $s1, 1
    ctx->r8 = S32(SIGNED(ctx->r17) >> 1);
    // 0x800142B4: addiu       $at, $s1, 0x1
    ctx->r1 = ADD32(ctx->r17, 0X1);
    // 0x800142B8: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_800142BC:
    // 0x800142BC: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x800142C0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800142C4: bgez        $v1, L_800142F4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800142C8: nop
    
            goto L_800142F4;
    }
    // 0x800142C8: nop

    // 0x800142CC: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800142D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800142D4: mflo        $v0
    ctx->r2 = lo;
    // 0x800142D8: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800142DC: blez        $v0, L_800142EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800142E0: nop
    
            goto L_800142EC;
    }
    // 0x800142E0: nop

    // 0x800142E4: b           L_80014330
    // 0x800142E8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80014330;
    // 0x800142E8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800142EC:
    // 0x800142EC: b           L_80014330
    // 0x800142F0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_80014330;
    // 0x800142F0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800142F4:
    // 0x800142F4: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800142F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800142FC: mflo        $v0
    ctx->r2 = lo;
    // 0x80014300: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80014304: bgez        $v0, L_80014314
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80014308: nop
    
            goto L_80014314;
    }
    // 0x80014308: nop

    // 0x8001430C: b           L_80014314
    // 0x80014310: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80014314;
    // 0x80014310: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80014314:
    // 0x80014314: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80014318: b           L_80014330
    // 0x8001431C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80014330;
    // 0x8001431C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80014320:
    // 0x80014320: bgez        $s1, L_80014330
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80014324: sra         $t0, $s1, 1
        ctx->r8 = S32(SIGNED(ctx->r17) >> 1);
            goto L_80014330;
    }
    // 0x80014324: sra         $t0, $s1, 1
    ctx->r8 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80014328: addiu       $at, $s1, 0x1
    ctx->r1 = ADD32(ctx->r17, 0X1);
    // 0x8001432C: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_80014330:
    // 0x80014330: bgez        $t1, L_800143AC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80014334: subu        $t9, $s5, $a2
        ctx->r25 = SUB32(ctx->r21, ctx->r6);
            goto L_800143AC;
    }
    // 0x80014334: subu        $t9, $s5, $a2
    ctx->r25 = SUB32(ctx->r21, ctx->r6);
    // 0x80014338: bgez        $s3, L_80014348
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8001433C: sra         $a1, $s3, 1
        ctx->r5 = S32(SIGNED(ctx->r19) >> 1);
            goto L_80014348;
    }
    // 0x8001433C: sra         $a1, $s3, 1
    ctx->r5 = S32(SIGNED(ctx->r19) >> 1);
    // 0x80014340: addiu       $at, $s3, 0x1
    ctx->r1 = ADD32(ctx->r19, 0X1);
    // 0x80014344: sra         $a1, $at, 1
    ctx->r5 = S32(SIGNED(ctx->r1) >> 1);
L_80014348:
    // 0x80014348: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x8001434C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80014350: bgez        $v1, L_80014380
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80014354: nop
    
            goto L_80014380;
    }
    // 0x80014354: nop

    // 0x80014358: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001435C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80014360: mflo        $v0
    ctx->r2 = lo;
    // 0x80014364: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80014368: blez        $v0, L_80014378
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001436C: nop
    
            goto L_80014378;
    }
    // 0x8001436C: nop

    // 0x80014370: b           L_800143C0
    // 0x80014374: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800143C0;
    // 0x80014374: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80014378:
    // 0x80014378: b           L_800143C4
    // 0x8001437C: subu        $t6, $s6, $v1
    ctx->r14 = SUB32(ctx->r22, ctx->r3);
        goto L_800143C4;
    // 0x8001437C: subu        $t6, $s6, $v1
    ctx->r14 = SUB32(ctx->r22, ctx->r3);
L_80014380:
    // 0x80014380: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80014384: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80014388: mflo        $v0
    ctx->r2 = lo;
    // 0x8001438C: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80014390: bgez        $v0, L_800143A0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80014394: nop
    
            goto L_800143A0;
    }
    // 0x80014394: nop

    // 0x80014398: b           L_800143A0
    // 0x8001439C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800143A0;
    // 0x8001439C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800143A0:
    // 0x800143A0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800143A4: b           L_800143C0
    // 0x800143A8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_800143C0;
    // 0x800143A8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800143AC:
    // 0x800143AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800143B0: bgez        $s3, L_800143C0
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800143B4: sra         $a1, $s3, 1
        ctx->r5 = S32(SIGNED(ctx->r19) >> 1);
            goto L_800143C0;
    }
    // 0x800143B4: sra         $a1, $s3, 1
    ctx->r5 = S32(SIGNED(ctx->r19) >> 1);
    // 0x800143B8: addiu       $at, $s3, 0x1
    ctx->r1 = ADD32(ctx->r19, 0X1);
    // 0x800143BC: sra         $a1, $at, 1
    ctx->r5 = S32(SIGNED(ctx->r1) >> 1);
L_800143C0:
    // 0x800143C0: subu        $t6, $s6, $v1
    ctx->r14 = SUB32(ctx->r22, ctx->r3);
L_800143C4:
    // 0x800143C4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800143C8: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800143CC: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800143D0: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x800143D4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800143D8: andi        $t8, $a1, 0xFFFF
    ctx->r24 = ctx->r5 & 0XFFFF;
    // 0x800143DC: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x800143E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800143E4: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800143E8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800143EC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800143F0: b           L_800145C4
    // 0x800143F4: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
        goto L_800145C4;
    // 0x800143F4: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
L_800143F8:
    // 0x800143F8: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800143FC: addiu       $v1, $s4, 0x20
    ctx->r3 = ADD32(ctx->r20, 0X20);
    // 0x80014400: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80014404: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80014408: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001440C: sll         $t0, $t3, 2
    ctx->r8 = S32(ctx->r11 << 2);
    // 0x80014410: sll         $a3, $t0, 16
    ctx->r7 = S32(ctx->r8 << 16);
    // 0x80014414: sll         $a1, $a1, 18
    ctx->r5 = S32(ctx->r5 << 18);
    // 0x80014418: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001441C: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x80014420: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80014424: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80014428: blez        $v1, L_80014438
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001442C: sra         $a3, $a3, 16
        ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
            goto L_80014438;
    }
    // 0x8001442C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80014430: b           L_8001443C
    // 0x80014434: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_8001443C;
    // 0x80014434: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80014438:
    // 0x80014438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001443C:
    // 0x8001443C: blez        $a1, L_8001444C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80014440: andi        $t9, $a0, 0xFFF
        ctx->r25 = ctx->r4 & 0XFFF;
            goto L_8001444C;
    }
    // 0x80014440: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x80014444: b           L_80014450
    // 0x80014448: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_80014450;
    // 0x80014448: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8001444C:
    // 0x8001444C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80014450:
    // 0x80014450: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x80014454: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80014458: sll         $a1, $a1, 18
    ctx->r5 = S32(ctx->r5 << 18);
    // 0x8001445C: or          $t8, $t6, $t4
    ctx->r24 = ctx->r14 | ctx->r12;
    // 0x80014460: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80014464: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80014468: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001446C: blez        $a1, L_8001447C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80014470: sw          $t6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r14;
            goto L_8001447C;
    }
    // 0x80014470: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80014474: b           L_80014480
    // 0x80014478: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
        goto L_80014480;
    // 0x80014478: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8001447C:
    // 0x8001447C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80014480:
    // 0x80014480: blez        $a3, L_80014490
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80014484: andi        $t8, $a0, 0xFFF
        ctx->r24 = ctx->r4 & 0XFFF;
            goto L_80014490;
    }
    // 0x80014484: andi        $t8, $a0, 0xFFF
    ctx->r24 = ctx->r4 & 0XFFF;
    // 0x80014488: b           L_80014494
    // 0x8001448C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
        goto L_80014494;
    // 0x8001448C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_80014490:
    // 0x80014490: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80014494:
    // 0x80014494: andi        $t9, $v1, 0xFFF
    ctx->r25 = ctx->r3 & 0XFFF;
    // 0x80014498: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8001449C: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x800144A0: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800144A4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800144A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800144AC: sll         $v1, $s1, 16
    ctx->r3 = S32(ctx->r17 << 16);
    // 0x800144B0: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x800144B4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800144B8: bgez        $a1, L_80014520
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800144BC: sw          $t5, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r13;
            goto L_80014520;
    }
    // 0x800144BC: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800144C0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800144C4: bgez        $v1, L_800144F4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800144C8: nop
    
            goto L_800144F4;
    }
    // 0x800144C8: nop

    // 0x800144CC: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800144D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800144D4: mflo        $v0
    ctx->r2 = lo;
    // 0x800144D8: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800144DC: blez        $v0, L_800144EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800144E0: nop
    
            goto L_800144EC;
    }
    // 0x800144E0: nop

    // 0x800144E4: b           L_80014520
    // 0x800144E8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80014520;
    // 0x800144E8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800144EC:
    // 0x800144EC: b           L_80014520
    // 0x800144F0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_80014520;
    // 0x800144F0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800144F4:
    // 0x800144F4: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800144F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800144FC: mflo        $v0
    ctx->r2 = lo;
    // 0x80014500: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80014504: bgez        $v0, L_80014514
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80014508: nop
    
            goto L_80014514;
    }
    // 0x80014508: nop

    // 0x8001450C: b           L_80014514
    // 0x80014510: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80014514;
    // 0x80014510: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80014514:
    // 0x80014514: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80014518: b           L_80014520
    // 0x8001451C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80014520;
    // 0x8001451C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80014520:
    // 0x80014520: bgez        $t0, L_8001458C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80014524: subu        $t8, $s5, $a2
        ctx->r24 = SUB32(ctx->r21, ctx->r6);
            goto L_8001458C;
    }
    // 0x80014524: subu        $t8, $s5, $a2
    ctx->r24 = SUB32(ctx->r21, ctx->r6);
    // 0x80014528: sll         $v1, $s3, 16
    ctx->r3 = S32(ctx->r19 << 16);
    // 0x8001452C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80014530: bgez        $v1, L_80014560
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80014534: nop
    
            goto L_80014560;
    }
    // 0x80014534: nop

    // 0x80014538: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001453C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80014540: mflo        $v0
    ctx->r2 = lo;
    // 0x80014544: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80014548: blez        $v0, L_80014558
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001454C: nop
    
            goto L_80014558;
    }
    // 0x8001454C: nop

    // 0x80014550: b           L_80014590
    // 0x80014554: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80014590;
    // 0x80014554: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80014558:
    // 0x80014558: b           L_80014594
    // 0x8001455C: subu        $t9, $s6, $v1
    ctx->r25 = SUB32(ctx->r22, ctx->r3);
        goto L_80014594;
    // 0x8001455C: subu        $t9, $s6, $v1
    ctx->r25 = SUB32(ctx->r22, ctx->r3);
L_80014560:
    // 0x80014560: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80014564: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80014568: mflo        $v0
    ctx->r2 = lo;
    // 0x8001456C: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80014570: bgez        $v0, L_80014580
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80014574: nop
    
            goto L_80014580;
    }
    // 0x80014574: nop

    // 0x80014578: b           L_80014580
    // 0x8001457C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80014580;
    // 0x8001457C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80014580:
    // 0x80014580: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80014584: b           L_80014590
    // 0x80014588: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_80014590;
    // 0x80014588: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8001458C:
    // 0x8001458C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80014590:
    // 0x80014590: subu        $t9, $s6, $v1
    ctx->r25 = SUB32(ctx->r22, ctx->r3);
L_80014594:
    // 0x80014594: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x80014598: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8001459C: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800145A0: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x800145A4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800145A8: andi        $t6, $s3, 0xFFFF
    ctx->r14 = ctx->r19 & 0XFFFF;
    // 0x800145AC: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x800145B0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800145B4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800145B8: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800145BC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800145C0: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
L_800145C4:
    // 0x800145C4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800145C8: sll         $s7, $s7, 16
    ctx->r23 = S32(ctx->r23 << 16);
    // 0x800145CC: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x800145D0: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x800145D4: slti        $at, $s7, 0xB
    ctx->r1 = SIGNED(ctx->r23) < 0XB ? 1 : 0;
    // 0x800145D8: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x800145DC: sll         $fp, $fp, 1
    ctx->r30 = S32(ctx->r30 << 1);
    // 0x800145E0: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x800145E4: bne         $at, $zero, L_80014158
    if (ctx->r1 != 0) {
        // 0x800145E8: andi        $fp, $fp, 0xFFFF
        ctx->r30 = ctx->r30 & 0XFFFF;
            goto L_80014158;
    }
    // 0x800145E8: andi        $fp, $fp, 0xFFFF
    ctx->r30 = ctx->r30 & 0XFFFF;
L_800145EC:
    // 0x800145EC: lh          $t7, 0x200($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X200);
    // 0x800145F0: addiu       $t3, $t3, 0x20
    ctx->r11 = ADD32(ctx->r11, 0X20);
    // 0x800145F4: sll         $t3, $t3, 16
    ctx->r11 = S32(ctx->r11 << 16);
    // 0x800145F8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800145FC: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80014600: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80014604: slti        $at, $t8, 0x9
    ctx->r1 = SIGNED(ctx->r24) < 0X9 ? 1 : 0;
    // 0x80014608: sh          $t9, 0x200($sp)
    MEM_H(0X200, ctx->r29) = ctx->r25;
    // 0x8001460C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80014610: lh          $s4, 0x20E($sp)
    ctx->r20 = MEM_H(ctx->r29, 0X20E);
    // 0x80014614: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80014618: bne         $at, $zero, L_80014124
    if (ctx->r1 != 0) {
        // 0x8001461C: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_80014124;
    }
    // 0x8001461C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_80014620:
    // 0x80014620: lh          $t7, 0x206($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X206);
L_80014624:
    // 0x80014624: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x80014628: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001462C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80014630: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80014634: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80014638: slti        $at, $t8, 0xB
    ctx->r1 = SIGNED(ctx->r24) < 0XB ? 1 : 0;
    // 0x8001463C: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80014640: sh          $t9, 0x206($sp)
    MEM_H(0X206, ctx->r29) = ctx->r25;
    // 0x80014644: addiu       $a0, $a0, -0x6D50
    ctx->r4 = ADD32(ctx->r4, -0X6D50);
    // 0x80014648: bne         $at, $zero, L_80013E3C
    if (ctx->r1 != 0) {
        // 0x8001464C: andi        $s0, $s0, 0xFFFF
        ctx->r16 = ctx->r16 & 0XFFFF;
            goto L_80013E3C;
    }
    // 0x8001464C: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80014650: lh          $t7, 0x202($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X202);
    // 0x80014654: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80014658: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001465C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80014660: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80014664: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80014668: slti        $at, $t8, 0x9
    ctx->r1 = SIGNED(ctx->r24) < 0X9 ? 1 : 0;
    // 0x8001466C: bne         $at, $zero, L_80013E10
    if (ctx->r1 != 0) {
        // 0x80014670: sh          $t9, 0x202($sp)
        MEM_H(0X202, ctx->r29) = ctx->r25;
            goto L_80013E10;
    }
    // 0x80014670: sh          $t9, 0x202($sp)
    MEM_H(0X202, ctx->r29) = ctx->r25;
    // 0x80014674: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80014678: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001467C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80014680: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80014684: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80014688: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001468C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80014690: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80014694: jr          $ra
    // 0x80014698: addiu       $sp, $sp, 0x218
    ctx->r29 = ADD32(ctx->r29, 0X218);
    return;
    // 0x80014698: addiu       $sp, $sp, 0x218
    ctx->r29 = ADD32(ctx->r29, 0X218);
    // 0x8001469C: nop

    // 0x800146A0: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x800146A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800146A8: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800146AC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800146B0: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x800146B4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800146B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800146BC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800146C0: bc1f        L_800146D0
    if (!c1cs) {
        // 0x800146C4: lui         $at, 0x4033
        ctx->r1 = S32(0X4033 << 16);
            goto L_800146D0;
    }
    // 0x800146C4: lui         $at, 0x4033
    ctx->r1 = S32(0X4033 << 16);
    // 0x800146C8: b           L_800146D4
    // 0x800146CC: neg.d       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = -ctx->f2.d;
        goto L_800146D4;
    // 0x800146CC: neg.d       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = -ctx->f2.d;
L_800146D0:
    // 0x800146D0: mov.d       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.d = ctx->f2.d;
L_800146D4:
    // 0x800146D4: c.le.d      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.d <= ctx->f16.d;
    // 0x800146D8: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x800146DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800146E0: bc1fl       L_800146F4
    if (!c1cs) {
        // 0x800146E4: div.d       $f12, $f16, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = DIV_D(ctx->f16.d, ctx->f2.d);
            goto L_800146F4;
    }
    goto skip_8;
    // 0x800146E4: div.d       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = DIV_D(ctx->f16.d, ctx->f2.d);
    skip_8:
    // 0x800146E8: b           L_800146F4
    // 0x800146EC: mov.d       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.d = ctx->f2.d;
        goto L_800146F4;
    // 0x800146EC: mov.d       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.d = ctx->f2.d;
    // 0x800146F0: div.d       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = DIV_D(ctx->f16.d, ctx->f2.d);
L_800146F4:
    // 0x800146F4: c.le.d      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.d <= ctx->f14.d;
    // 0x800146F8: nop

    // 0x800146FC: bc1fl       L_8001473C
    if (!c1cs) {
        // 0x80014700: c.lt.d      $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
            goto L_8001473C;
    }
    goto skip_9;
    // 0x80014700: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    skip_9:
    // 0x80014704: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80014708: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001470C: nop

L_80014710:
    // 0x80014710: mul.d       $f6, $f18, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f14.d);
    // 0x80014714: add.d       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f16.d + ctx->f0.d;
    // 0x80014718: mul.d       $f10, $f14, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = MUL_D(ctx->f14.d, ctx->f12.d);
    // 0x8001471C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80014720: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x80014724: sub.d       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f14.d - ctx->f16.d;
    // 0x80014728: c.le.d      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.d <= ctx->f14.d;
    // 0x8001472C: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x80014730: bc1t        L_80014710
    if (c1cs) {
        // 0x80014734: div.d       $f0, $f6, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f0.d = DIV_D(ctx->f6.d, ctx->f8.d);
            goto L_80014710;
    }
    // 0x80014734: div.d       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f0.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80014738: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
L_8001473C:
    // 0x8001473C: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x80014740: add.d       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f16.d + ctx->f0.d;
    // 0x80014744: bc1f        L_80014760
    if (!c1cs) {
        // 0x80014748: div.d       $f12, $f12, $f10
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f10.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f10.d);
            goto L_80014760;
    }
    // 0x80014748: div.d       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f10.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f10.d);
    // 0x8001474C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80014750: ldc1        $f4, -0x37F0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X37F0);
    // 0x80014754: sub.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f4.d - ctx->f12.d;
    // 0x80014758: jr          $ra
    // 0x8001475C: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    return;
    // 0x8001475C: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80014760:
    // 0x80014760: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80014764: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80014768: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001476C: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x80014770: nop

    // 0x80014774: bc1fl       L_80014790
    if (!c1cs) {
        // 0x80014778: cvt.s.d     $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.fl = CVT_S_D(ctx->f12.d);
            goto L_80014790;
    }
    goto skip_10;
    // 0x80014778: cvt.s.d     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.fl = CVT_S_D(ctx->f12.d);
    skip_10:
    // 0x8001477C: ldc1        $f10, -0x37E8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X37E8);
    // 0x80014780: sub.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f10.d - ctx->f12.d;
    // 0x80014784: jr          $ra
    // 0x80014788: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x80014788: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8001478C: cvt.s.d     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.fl = CVT_S_D(ctx->f12.d);
L_80014790:
    // 0x80014790: jr          $ra
    // 0x80014794: nop

    return;
    // 0x80014794: nop

;}
RECOMP_FUNC void FUN_80014798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014798: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001479C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800147A0: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x800147A4: nop

    // 0x800147A8: bc1fl       L_800147BC
    if (!c1cs) {
        // 0x800147AC: mov.s       $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
            goto L_800147BC;
    }
    goto skip_0;
    // 0x800147AC: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    skip_0:
    // 0x800147B0: b           L_800147BC
    // 0x800147B4: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
        goto L_800147BC;
    // 0x800147B4: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
    // 0x800147B8: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_800147BC:
    // 0x800147BC: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x800147C0: nop

    // 0x800147C4: bc1fl       L_800147D8
    if (!c1cs) {
        // 0x800147C8: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_800147D8;
    }
    goto skip_1;
    // 0x800147C8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    skip_1:
    // 0x800147CC: b           L_800147D8
    // 0x800147D0: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
        goto L_800147D8;
    // 0x800147D0: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x800147D4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800147D8:
    // 0x800147D8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800147DC: nop

    // 0x800147E0: bc1fl       L_80014850
    if (!c1cs) {
        // 0x800147E4: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80014850;
    }
    goto skip_2;
    // 0x800147E4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_2:
    // 0x800147E8: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x800147EC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800147F0: bc1fl       L_80014804
    if (!c1cs) {
        // 0x800147F4: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_80014804;
    }
    goto skip_3;
    // 0x800147F4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_3:
    // 0x800147F8: b           L_80014988
    // 0x800147FC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_80014988;
    // 0x800147FC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x80014800: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_80014804:
    // 0x80014804: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80014808: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8001480C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80014810: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80014814: div.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80014818: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x8001481C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80014820: nop

    // 0x80014824: sltiu       $at, $v0, 0x201
    ctx->r1 = ctx->r2 < 0X201 ? 1 : 0;
    // 0x80014828: bnel        $at, $zero, L_80014838
    if (ctx->r1 != 0) {
        // 0x8001482C: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80014838;
    }
    goto skip_4;
    // 0x8001482C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    skip_4:
    // 0x80014830: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x80014834: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
L_80014838:
    // 0x80014838: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001483C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80014840: lwc1        $f2, 0x3860($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X3860);
    // 0x80014844: b           L_800148EC
    // 0x80014848: swc1        $f2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f2.u32l;
        goto L_800148EC;
    // 0x80014848: swc1        $f2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f2.u32l;
    // 0x8001484C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80014850:
    // 0x80014850: nop

    // 0x80014854: bc1fl       L_800148D8
    if (!c1cs) {
        // 0x80014858: c.eq.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
            goto L_800148D8;
    }
    goto skip_5;
    // 0x80014858: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    skip_5:
    // 0x8001485C: c.eq.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl == ctx->f16.fl;
    // 0x80014860: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80014864: bc1fl       L_80014878
    if (!c1cs) {
        // 0x80014868: mtc1        $at, $f9
        ctx->f_odd[(9 - 1) * 2] = ctx->r1;
            goto L_80014878;
    }
    goto skip_6;
    // 0x80014868: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    skip_6:
    // 0x8001486C: b           L_80014988
    // 0x80014870: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_80014988;
    // 0x80014870: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x80014874: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
L_80014878:
    // 0x80014878: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001487C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80014880: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x80014884: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80014888: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x8001488C: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x80014890: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80014894: nop

    // 0x80014898: sltiu       $at, $v0, 0x201
    ctx->r1 = ctx->r2 < 0X201 ? 1 : 0;
    // 0x8001489C: bne         $at, $zero, L_800148A8
    if (ctx->r1 != 0) {
        // 0x800148A0: nop
    
            goto L_800148A8;
    }
    // 0x800148A0: nop

    // 0x800148A4: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
L_800148A8:
    // 0x800148A8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800148AC: ldc1        $f8, -0x37E0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X37E0);
    // 0x800148B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800148B4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800148B8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800148BC: lwc1        $f10, 0x3860($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3860);
    // 0x800148C0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800148C4: sub.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f8.d - ctx->f18.d;
    // 0x800148C8: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x800148CC: b           L_800148EC
    // 0x800148D0: swc1        $f2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f2.u32l;
        goto L_800148EC;
    // 0x800148D0: swc1        $f2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f2.u32l;
    // 0x800148D4: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
L_800148D8:
    // 0x800148D8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800148DC: bc1fl       L_800148F0
    if (!c1cs) {
        // 0x800148E0: c.lt.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
            goto L_800148F0;
    }
    goto skip_7;
    // 0x800148E0: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    skip_7:
    // 0x800148E4: lwc1        $f2, -0x37D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X37D8);
    // 0x800148E8: swc1        $f2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f2.u32l;
L_800148EC:
    // 0x800148EC: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
L_800148F0:
    // 0x800148F0: lwc1        $f2, 0x0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800148F4: bc1fl       L_80014924
    if (!c1cs) {
        // 0x800148F8: c.lt.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
            goto L_80014924;
    }
    goto skip_8;
    // 0x800148F8: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    skip_8:
    // 0x800148FC: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x80014900: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80014904: bc1fl       L_80014924
    if (!c1cs) {
        // 0x80014908: c.lt.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
            goto L_80014924;
    }
    goto skip_9;
    // 0x80014908: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    skip_9:
    // 0x8001490C: ldc1        $f6, -0x37D0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X37D0);
    // 0x80014910: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80014914: sub.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d - ctx->f10.d;
    // 0x80014918: b           L_80014984
    // 0x8001491C: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
        goto L_80014984;
    // 0x8001491C: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80014920: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
L_80014924:
    // 0x80014924: nop

    // 0x80014928: bc1fl       L_80014958
    if (!c1cs) {
        // 0x8001492C: c.le.s      $f16, $f14
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
            goto L_80014958;
    }
    goto skip_10;
    // 0x8001492C: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
    skip_10:
    // 0x80014930: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80014934: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80014938: bc1fl       L_80014958
    if (!c1cs) {
        // 0x8001493C: c.le.s      $f16, $f14
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
            goto L_80014958;
    }
    goto skip_11;
    // 0x8001493C: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
    skip_11:
    // 0x80014940: ldc1        $f4, -0x37C8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X37C8);
    // 0x80014944: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x80014948: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x8001494C: b           L_80014984
    // 0x80014950: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
        goto L_80014984;
    // 0x80014950: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x80014954: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
L_80014958:
    // 0x80014958: nop

    // 0x8001495C: bc1fl       L_80014988
    if (!c1cs) {
        // 0x80014960: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80014988;
    }
    goto skip_12;
    // 0x80014960: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_12:
    // 0x80014964: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80014968: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001496C: bc1fl       L_80014988
    if (!c1cs) {
        // 0x80014970: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80014988;
    }
    goto skip_13;
    // 0x80014970: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_13:
    // 0x80014974: ldc1        $f10, -0x37C0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X37C0);
    // 0x80014978: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8001497C: sub.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f10.d - ctx->f8.d;
    // 0x80014980: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
L_80014984:
    // 0x80014984: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80014988:
    // 0x80014988: jr          $ra
    // 0x8001498C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8001498C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80014990(rdram, ctx);
;}
RECOMP_FUNC void FUN_80014990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014990: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80014994: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80014998: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001499C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800149A0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800149A4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800149A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800149AC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800149B0: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800149B4: jal         0x8001EAD0
    // 0x800149B8: lh          $a0, 0x5A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5A);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x800149B8: lh          $a0, 0x5A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5A);
    after_0:
    // 0x800149BC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800149C0: jal         0x8001EB64
    // 0x800149C4: lh          $a0, 0x5A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5A);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x800149C4: lh          $a0, 0x5A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5A);
    after_1:
    // 0x800149C8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800149CC: jal         0x8001EAD0
    // 0x800149D0: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x800149D0: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    after_2:
    // 0x800149D4: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    // 0x800149D8: jal         0x8001EB64
    // 0x800149DC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x800149DC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800149E0: lh          $a0, 0x62($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X62);
    // 0x800149E4: jal         0x8001EAD0
    // 0x800149E8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x800149E8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800149EC: lh          $a0, 0x62($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X62);
    // 0x800149F0: jal         0x8001EB64
    // 0x800149F4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x800149F4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800149F8: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800149FC: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80014A00: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80014A04: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80014A08: neg.s       $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = -ctx->f22.fl;
    // 0x80014A0C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80014A10: mul.s       $f6, $f22, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80014A14: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    // 0x80014A18: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x80014A1C: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x80014A20: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80014A24: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x80014A28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80014A2C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80014A30: neg.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = -ctx->f20.fl;
    // 0x80014A34: mul.s       $f10, $f20, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x80014A38: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80014A3C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80014A40: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80014A44: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80014A48: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
    // 0x80014A4C: mul.s       $f4, $f22, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x80014A50: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80014A54: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80014A58: nop

    // 0x80014A5C: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80014A60: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80014A64: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80014A68: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80014A6C: nop

    // 0x80014A70: mul.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80014A74: nop

    // 0x80014A78: mul.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80014A7C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80014A80: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80014A84: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80014A88: mul.s       $f8, $f22, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80014A8C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80014A90: mul.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80014A94: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80014A98: mul.s       $f6, $f20, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x80014A9C: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x80014AA0: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80014AA4: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80014AA8: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80014AAC: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80014AB0: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80014AB4: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80014AB8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80014ABC: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80014AC0: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80014AC4: mul.s       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80014AC8: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80014ACC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80014AD0: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x80014AD4: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80014AD8: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    // 0x80014ADC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80014AE0: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80014AE4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80014AE8: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80014AEC: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80014AF0: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80014AF4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80014AF8: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80014AFC: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80014B00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80014B04: nop

    // 0x80014B08: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x80014B0C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80014B10: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x80014B14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80014B18: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80014B1C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80014B20: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80014B24: jr          $ra
    // 0x80014B28: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80014B28: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80014b2c(rdram, ctx);
;}
RECOMP_FUNC void FUN_80014b2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014B2C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80014B30: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80014B34: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80014B38: lh          $t6, 0x7A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X7A);
    // 0x80014B3C: lh          $t7, 0x7E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X7E);
    // 0x80014B40: lh          $t8, 0x82($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X82);
    // 0x80014B44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80014B48: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80014B4C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80014B50: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80014B54: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80014B58: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80014B5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80014B60: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80014B64: jal         0x80014990
    // 0x80014B68: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80014990)(rdram, ctx);
        goto after_0;
    // 0x80014B68: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x80014B6C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80014B70: jal         0x80029D30
    // 0x80014B74: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    LOOKUP_FUNC(0x80029D30)(rdram, ctx);
        goto after_1;
    // 0x80014B74: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x80014B78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80014B7C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80014B80: jr          $ra
    // 0x80014B84: nop

    return;
    // 0x80014B84: nop

;}
RECOMP_FUNC void FUN_80014b88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014B88: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80014B8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80014B90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80014B94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80014B98: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80014B9C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80014BA0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80014BA4: jal         0x8001EAD0
    // 0x80014BA8: lh          $a0, 0x6E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X6E);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80014BA8: lh          $a0, 0x6E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X6E);
    after_0:
    // 0x80014BAC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80014BB0: jal         0x8001EB64
    // 0x80014BB4: lh          $a0, 0x6E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X6E);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80014BB4: lh          $a0, 0x6E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X6E);
    after_1:
    // 0x80014BB8: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80014BBC: jal         0x8001EAD0
    // 0x80014BC0: lh          $a0, 0x72($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X72);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x80014BC0: lh          $a0, 0x72($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X72);
    after_2:
    // 0x80014BC4: lh          $a0, 0x72($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X72);
    // 0x80014BC8: jal         0x8001EB64
    // 0x80014BCC: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x80014BCC: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80014BD0: lh          $a0, 0x76($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X76);
    // 0x80014BD4: jal         0x8001EAD0
    // 0x80014BD8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x80014BD8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80014BDC: lh          $a0, 0x76($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X76);
    // 0x80014BE0: jal         0x8001EB64
    // 0x80014BE4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x80014BE4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80014BE8: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80014BEC: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80014BF0: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80014BF4: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80014BF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80014BFC: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x80014C00: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80014C04: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80014C08: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80014C0C: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80014C10: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80014C14: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80014C18: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80014C1C: nop

    // 0x80014C20: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80014C24: nop

    // 0x80014C28: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80014C2C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80014C30: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80014C34: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80014C38: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80014C3C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80014C40: mul.s       $f16, $f4, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80014C44: nop

    // 0x80014C48: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80014C4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80014C50: mul.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80014C54: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80014C58: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80014C5C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x80014C60: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80014C64: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80014C68: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x80014C6C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80014C70: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80014C74: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80014C78: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x80014C7C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80014C80: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80014C84: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80014C88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80014C8C: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80014C90: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80014C94: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80014C98: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80014C9C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80014CA0: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80014CA4: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80014CA8: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80014CAC: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80014CB0: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x80014CB4: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x80014CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80014CBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80014CC0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80014CC4: jr          $ra
    // 0x80014CC8: nop

    return;
    // 0x80014CC8: nop

;}
RECOMP_FUNC void FUN_80014ccc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014CCC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80014CD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80014CD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80014CD8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80014CDC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80014CE0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80014CE4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80014CE8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80014CEC: jal         0x8001EAD0
    // 0x80014CF0: lh          $a0, 0x46($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X46);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x80014CF0: lh          $a0, 0x46($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X46);
    after_0:
    // 0x80014CF4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80014CF8: jal         0x8001EB64
    // 0x80014CFC: lh          $a0, 0x46($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X46);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80014CFC: lh          $a0, 0x46($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X46);
    after_1:
    // 0x80014D00: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80014D04: jal         0x8001EAD0
    // 0x80014D08: lh          $a0, 0x4A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4A);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x80014D08: lh          $a0, 0x4A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4A);
    after_2:
    // 0x80014D0C: lh          $a0, 0x4A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4A);
    // 0x80014D10: jal         0x8001EB64
    // 0x80014D14: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x80014D14: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80014D18: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80014D1C: jal         0x8001EAD0
    // 0x80014D20: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x80014D20: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    after_4:
    // 0x80014D24: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80014D28: jal         0x8001EB64
    // 0x80014D2C: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x80014D2C: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    after_5:
    // 0x80014D30: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80014D34: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80014D38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80014D3C: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80014D40: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80014D44: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80014D48: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80014D4C: mul.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80014D50: nop

    // 0x80014D54: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80014D58: nop

    // 0x80014D5C: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80014D60: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80014D64: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80014D68: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80014D6C: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80014D70: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80014D74: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80014D78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80014D7C: mul.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80014D80: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x80014D84: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80014D88: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80014D8C: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80014D90: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80014D94: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80014D98: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
    // 0x80014D9C: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    // 0x80014DA0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80014DA4: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80014DA8: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80014DAC: nop

    // 0x80014DB0: mul.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80014DB4: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80014DB8: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x80014DBC: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80014DC0: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x80014DC4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80014DC8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80014DCC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80014DD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80014DD4: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80014DD8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80014DDC: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80014DE0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80014DE4: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80014DE8: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80014DEC: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80014DF0: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80014DF4: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80014DF8: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x80014DFC: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80014E00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80014E04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80014E08: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80014E0C: jr          $ra
    // 0x80014E10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80014E10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80014e14(rdram, ctx);
;}
RECOMP_FUNC void FUN_80014e14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014E14: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80014E18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80014E1C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80014E20: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80014E24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80014E28: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80014E2C: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80014E30: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80014E34: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80014E38: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80014E3C: beql        $v0, $a0, L_80014EB4
    if (ctx->r2 == ctx->r4) {
        // 0x80014E40: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_80014EB4;
    }
    goto skip_0;
    // 0x80014E40: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_0:
    // 0x80014E44: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80014E48:
    // 0x80014E48: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80014E4C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80014E50: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80014E54: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80014E58: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80014E5C: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80014E60: lwc1        $f16, 0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80014E64: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80014E68: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
    // 0x80014E6C: lwc1        $f16, 0x28($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X28);
    // 0x80014E70: swc1        $f16, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f16.u32l;
    // 0x80014E74: lwc1        $f16, -0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X4);
    // 0x80014E78: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80014E7C: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80014E80: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014E84: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80014E88: swc1        $f16, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f16.u32l;
    // 0x80014E8C: lwc1        $f16, 0x1C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80014E90: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80014E94: swc1        $f16, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f16.u32l;
    // 0x80014E98: lwc1        $f16, 0x2C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x80014E9C: swc1        $f16, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f16.u32l;
    // 0x80014EA0: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80014EA4: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80014EA8: bnel        $v0, $a0, L_80014E48
    if (ctx->r2 != ctx->r4) {
        // 0x80014EAC: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_80014E48;
    }
    goto skip_1;
    // 0x80014EAC: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_1:
    // 0x80014EB0: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80014EB4:
    // 0x80014EB4: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80014EB8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80014EBC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80014EC0: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80014EC4: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80014EC8: lwc1        $f16, 0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80014ECC: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80014ED0: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
    // 0x80014ED4: lwc1        $f16, 0x28($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X28);
    // 0x80014ED8: swc1        $f16, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f16.u32l;
    // 0x80014EDC: lwc1        $f16, -0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X4);
    // 0x80014EE0: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80014EE4: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80014EE8: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014EEC: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80014EF0: swc1        $f16, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f16.u32l;
    // 0x80014EF4: lwc1        $f16, 0x1C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80014EF8: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80014EFC: swc1        $f16, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f16.u32l;
    // 0x80014F00: lwc1        $f16, 0x2C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x80014F04: swc1        $f16, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f16.u32l;
    // 0x80014F08: jr          $ra
    // 0x80014F0C: nop

    return;
    // 0x80014F0C: nop

    // 0x80014F10: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80014F14: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80014F18: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80014F1C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80014F20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80014F24: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80014F28: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80014F2C: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80014F30: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80014F34: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80014F38: beql        $v0, $a0, L_80014FB0
    if (ctx->r2 == ctx->r4) {
        // 0x80014F3C: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_80014FB0;
    }
    goto skip_2;
    // 0x80014F3C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_2:
    // 0x80014F40: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80014F44:
    // 0x80014F44: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80014F48: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80014F4C: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80014F50: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80014F54: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x80014F58: swc1        $f16, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->f16.u32l;
    // 0x80014F5C: lwc1        $f16, -0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X18);
    // 0x80014F60: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80014F64: swc1        $f16, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->f16.u32l;
    // 0x80014F68: lwc1        $f16, -0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X14);
    // 0x80014F6C: swc1        $f16, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->f16.u32l;
    // 0x80014F70: lwc1        $f16, -0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X10);
    // 0x80014F74: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80014F78: swc1        $f16, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f16.u32l;
    // 0x80014F7C: lwc1        $f16, -0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0XC);
    // 0x80014F80: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80014F84: swc1        $f16, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f16.u32l;
    // 0x80014F88: lwc1        $f16, -0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X8);
    // 0x80014F8C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80014F90: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80014F94: lwc1        $f16, -0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X4);
    // 0x80014F98: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80014F9C: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80014FA0: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80014FA4: bnel        $v0, $a0, L_80014F44
    if (ctx->r2 != ctx->r4) {
        // 0x80014FA8: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_80014F44;
    }
    goto skip_3;
    // 0x80014FA8: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_3:
    // 0x80014FAC: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80014FB0:
    // 0x80014FB0: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80014FB4: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80014FB8: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x80014FBC: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80014FC0: swc1        $f16, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->f16.u32l;
    // 0x80014FC4: lwc1        $f16, -0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X18);
    // 0x80014FC8: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80014FCC: swc1        $f16, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->f16.u32l;
    // 0x80014FD0: lwc1        $f16, -0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X14);
    // 0x80014FD4: swc1        $f16, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->f16.u32l;
    // 0x80014FD8: lwc1        $f16, -0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X10);
    // 0x80014FDC: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80014FE0: swc1        $f16, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f16.u32l;
    // 0x80014FE4: lwc1        $f16, -0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0XC);
    // 0x80014FE8: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80014FEC: swc1        $f16, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f16.u32l;
    // 0x80014FF0: lwc1        $f16, -0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X8);
    // 0x80014FF4: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80014FF8: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80014FFC: lwc1        $f16, -0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X4);
    // 0x80015000: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80015004: jr          $ra
    // 0x80015008: nop

    return;
    // 0x80015008: nop

;}
RECOMP_FUNC void FUN_8001500c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001500C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80015010: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80015014: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80015018: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001501C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80015020: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80015024: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80015028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001502C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80015030: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80015034: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80015038: jal         0x80014B88
    // 0x8001503C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80014B88)(rdram, ctx);
        goto after_0;
    // 0x8001503C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80015040: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80015044: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80015048: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001504C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80015050: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80015054: jal         0x80014E14
    // 0x80015058: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80014E14)(rdram, ctx);
        goto after_1;
    // 0x80015058: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8001505C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80015060: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80015064: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x80015068: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8001506C: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x80015070: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80015074: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x80015078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001507C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80015080: jr          $ra
    // 0x80015084: nop

    return;
    // 0x80015084: nop

;}
RECOMP_FUNC void FUN_80015088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015088: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001508C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80015090: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80015094: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80015098: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8001509C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800150A0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800150A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800150A8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800150AC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800150B0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800150B4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800150B8: jal         0x80014B88
    // 0x800150BC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80014B88)(rdram, ctx);
        goto after_0;
    // 0x800150BC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800150C0: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800150C4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800150C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800150CC: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x800150D0: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x800150D4: jal         0x80014E14
    // 0x800150D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80014E14)(rdram, ctx);
        goto after_1;
    // 0x800150D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800150DC: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800150E0: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800150E4: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800150E8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800150EC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800150F0: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x800150F4: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800150F8: jal         0x80029D30
    // 0x800150FC: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80029D30)(rdram, ctx);
        goto after_2;
    // 0x800150FC: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80015100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80015104: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80015108: jr          $ra
    // 0x8001510C: nop

    return;
    // 0x8001510C: nop

;}
RECOMP_FUNC void FUN_80015110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015110: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80015114: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80015118: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001511C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80015120: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80015124: lh          $a2, 0x12($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X12);
    // 0x80015128: lh          $a3, 0x14($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X14);
    // 0x8001512C: lh          $a1, 0x10($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X10);
    // 0x80015130: jal         0x80014B88
    // 0x80015134: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80014B88)(rdram, ctx);
        goto after_0;
    // 0x80015134: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80015138: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8001513C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80015140: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    // 0x80015144: lw          $a3, 0x1C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1C);
    // 0x80015148: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001514C: jal         0x80014E14
    // 0x80015150: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80014E14)(rdram, ctx);
        goto after_1;
    // 0x80015150: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80015154: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80015158: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001515C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80015160: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80015164: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80015168: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8001516C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80015170: jal         0x80029D30
    // 0x80015174: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80029D30)(rdram, ctx);
        goto after_2;
    // 0x80015174: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80015178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001517C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80015180: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80015184: jr          $ra
    // 0x80015188: nop

    return;
    // 0x80015188: nop

;}
RECOMP_FUNC void FUN_8001518c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001518C: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x80015190: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80015194: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x80015198: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001519C: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x800151A0: nop

    // 0x800151A4: bc1t        L_800151BC
    if (c1cs) {
        // 0x800151A8: nop
    
            goto L_800151BC;
    }
    // 0x800151A8: nop

    // 0x800151AC: ldc1        $f14, -0x37B8($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X37B8);
    // 0x800151B0: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800151B4: nop

    // 0x800151B8: bc1f        L_8001520C
    if (!c1cs) {
        // 0x800151BC: lui         $at, 0x8005
        ctx->r1 = S32(0X8005 << 16);
            goto L_8001520C;
    }
L_800151BC:
    // 0x800151BC: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800151C0: ldc1        $f14, -0x37B0($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X37B0);
    // 0x800151C4: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x800151C8: div.d       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f14.d);
    // 0x800151CC: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x800151D0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800151D4: nop

    // 0x800151D8: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800151DC: bc1f        L_800151F4
    if (!c1cs) {
        // 0x800151E0: sra         $v0, $v0, 16
        ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800151F4;
    }
    // 0x800151E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800151E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800151E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800151EC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800151F0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_800151F4:
    // 0x800151F4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800151F8: nop

    // 0x800151FC: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80015200: mul.d       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x80015204: sub.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d - ctx->f16.d;
    // 0x80015208: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
L_8001520C:
    // 0x8001520C: jr          $ra
    // 0x80015210: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80015210: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80015214(rdram, ctx);
;}
RECOMP_FUNC void FUN_80015214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015214: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80015218: ldc1        $f4, -0x37A8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X37A8);
    // 0x8001521C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80015220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80015224: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x80015228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001522C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80015230: bc1tl       L_80015250
    if (c1cs) {
        // 0x80015234: mtc1        $zero, $f9
        ctx->f_odd[(9 - 1) * 2] = 0;
            goto L_80015250;
    }
    goto skip_0;
    // 0x80015234: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    skip_0:
    // 0x80015238: ldc1        $f6, -0x37A0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X37A0);
    // 0x8001523C: c.le.d      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.d <= ctx->f2.d;
    // 0x80015240: nop

    // 0x80015244: bc1fl       L_800152B8
    if (!c1cs) {
        // 0x80015248: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800152B8;
    }
    goto skip_1;
    // 0x80015248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8001524C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
L_80015250:
    // 0x80015250: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80015254: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80015258: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8001525C: nop

    // 0x80015260: bc1t        L_8001527C
    if (c1cs) {
        // 0x80015264: nop
    
            goto L_8001527C;
    }
    // 0x80015264: nop

    // 0x80015268: ldc1        $f10, -0x3798($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3798);
    // 0x8001526C: c.le.d      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.d <= ctx->f2.d;
    // 0x80015270: nop

    // 0x80015274: bc1f        L_8001528C
    if (!c1cs) {
        // 0x80015278: nop
    
            goto L_8001528C;
    }
    // 0x80015278: nop

L_8001527C:
    // 0x8001527C: jal         0x8001518C
    // 0x80015280: nop

    LOOKUP_FUNC(0x8001518C)(rdram, ctx);
        goto after_0;
    // 0x80015280: nop

    after_0:
    // 0x80015284: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80015288: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
L_8001528C:
    // 0x8001528C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80015290: ldc1        $f16, -0x3790($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3790);
    // 0x80015294: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80015298: c.le.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d <= ctx->f2.d;
    // 0x8001529C: nop

    // 0x800152A0: bc1fl       L_800152B8
    if (!c1cs) {
        // 0x800152A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800152B8;
    }
    goto skip_2;
    // 0x800152A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800152A8: ldc1        $f18, -0x3788($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3788);
    // 0x800152AC: sub.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d - ctx->f18.d;
    // 0x800152B0: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x800152B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800152B8:
    // 0x800152B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800152BC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800152C0: jr          $ra
    // 0x800152C4: nop

    return;
    // 0x800152C4: nop

;}
RECOMP_FUNC void FUN_800152c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800152C8: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800152CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800152D0: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x800152D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800152D8: c.lt.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d < ctx->f4.d;
    // 0x800152DC: nop

    // 0x800152E0: bc1fl       L_800152F4
    if (!c1cs) {
        // 0x800152E4: mov.d       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
            goto L_800152F4;
    }
    goto skip_0;
    // 0x800152E4: mov.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
    skip_0:
    // 0x800152E8: b           L_800152F4
    // 0x800152EC: neg.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = -ctx->f12.d;
        goto L_800152F4;
    // 0x800152EC: neg.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = -ctx->f12.d;
    // 0x800152F0: mov.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
L_800152F4:
    // 0x800152F4: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x800152F8: nop

    // 0x800152FC: bc1fl       L_80015330
    if (!c1cs) {
        // 0x80015300: trunc.w.d   $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_D(ctx->f2.d);
            goto L_80015330;
    }
    goto skip_1;
    // 0x80015300: trunc.w.d   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_D(ctx->f2.d);
    skip_1:
    // 0x80015304: trunc.w.d   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x80015308: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8001530C: nop

    // 0x80015310: negu        $t7, $v0
    ctx->r15 = SUB32(0, ctx->r2);
    // 0x80015314: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80015318: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8001531C: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80015320: cvt.d.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.d = CVT_D_W(ctx->f16.u32l);
    // 0x80015324: b           L_80015348
    // 0x80015328: sdc1        $f10, 0x0($a2)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X0, ctx->r6);
        goto L_80015348;
    // 0x80015328: sdc1        $f10, 0x0($a2)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X0, ctx->r6);
    // 0x8001532C: trunc.w.d   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_D(ctx->f2.d);
L_80015330:
    // 0x80015330: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80015334: nop

    // 0x80015338: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8001533C: nop

    // 0x80015340: cvt.d.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.d = CVT_D_W(ctx->f4.u32l);
    // 0x80015344: sdc1        $f14, 0x0($a2)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, 0X0, ctx->r6);
L_80015348:
    // 0x80015348: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x8001534C: nop

    // 0x80015350: bc1fl       L_80015368
    if (!c1cs) {
        // 0x80015354: sub.d       $f0, $f2, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f0.d = ctx->f2.d - ctx->f14.d;
            goto L_80015368;
    }
    goto skip_2;
    // 0x80015354: sub.d       $f0, $f2, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f0.d = ctx->f2.d - ctx->f14.d;
    skip_2:
    // 0x80015358: sub.d       $f0, $f2, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f0.d = ctx->f2.d - ctx->f14.d;
    // 0x8001535C: jr          $ra
    // 0x80015360: neg.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = -ctx->f0.d;
    return;
    // 0x80015360: neg.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = -ctx->f0.d;
    // 0x80015364: sub.d       $f0, $f2, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f0.d = ctx->f2.d - ctx->f14.d;
L_80015368:
    // 0x80015368: jr          $ra
    // 0x8001536C: nop

    return;
    // 0x8001536C: nop

;}
RECOMP_FUNC void FUN_80015370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015370: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80015374: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80015378: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001537C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015380: c.lt.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d < ctx->f4.d;
    // 0x80015384: mov.d       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.d = ctx->f12.d;
    // 0x80015388: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x8001538C: bc1f        L_800153E0
    if (!c1cs) {
        // 0x80015390: nop
    
            goto L_800153E0;
    }
    // 0x80015390: nop

    // 0x80015394: neg.d       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.d = -ctx->f12.d;
    // 0x80015398: jal         0x800152C8
    // 0x8001539C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800152C8)(rdram, ctx);
        goto after_0;
    // 0x8001539C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800153A0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800153A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800153A8: ldc1        $f8, 0x18($sp)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r29, 0X18);
    // 0x800153AC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800153B0: c.eq.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d == ctx->f6.d;
    // 0x800153B4: nop

    // 0x800153B8: bc1tl       L_800153D8
    if (c1cs) {
        // 0x800153BC: ldc1        $f0, 0x18($sp)
        CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r29, 0X18);
            goto L_800153D8;
    }
    goto skip_0;
    // 0x800153BC: ldc1        $f0, 0x18($sp)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r29, 0X18);
    skip_0:
    // 0x800153C0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800153C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800153C8: nop

    // 0x800153CC: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800153D0: sdc1        $f16, 0x18($sp)
    CHECK_FR(ctx, 16);
    SD(ctx->f16.u64, 0X18, ctx->r29);
    // 0x800153D4: ldc1        $f0, 0x18($sp)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r29, 0X18);
L_800153D8:
    // 0x800153D8: b           L_800153EC
    // 0x800153DC: neg.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = -ctx->f0.d;
        goto L_800153EC;
    // 0x800153DC: neg.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = -ctx->f0.d;
L_800153E0:
    // 0x800153E0: jal         0x800152C8
    // 0x800153E4: neg.d       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = -ctx->f14.d;
    LOOKUP_FUNC(0x800152C8)(rdram, ctx);
        goto after_1;
    // 0x800153E4: neg.d       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = -ctx->f14.d;
    after_1:
    // 0x800153E8: ldc1        $f0, 0x18($sp)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r29, 0X18);
L_800153EC:
    // 0x800153EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800153F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800153F4: jr          $ra
    // 0x800153F8: nop

    return;
    // 0x800153F8: nop

;}
RECOMP_FUNC void FUN_800153fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800153FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80015400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015404: jal         0x80015370
    // 0x80015408: neg.d       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.d = -ctx->f12.d;
    LOOKUP_FUNC(0x80015370)(rdram, ctx);
        goto after_0;
    // 0x80015408: neg.d       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.d = -ctx->f12.d;
    after_0:
    // 0x8001540C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80015414: neg.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = -ctx->f0.d;
    // 0x80015418: jr          $ra
    // 0x8001541C: nop

    return;
    // 0x8001541C: nop

;}
RECOMP_FUNC void FUN_80015420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80015424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015428: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001542C: jal         0x80016CB4
    // 0x80015430: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80016CB4)(rdram, ctx);
        goto after_0;
    // 0x80015430: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80015434: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80015438: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001543C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80015440: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80015444: sw          $t6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r14;
    // 0x80015448: sw          $t7, -0x2370($at)
    MEM_W(-0X2370, ctx->r1) = ctx->r15;
    // 0x8001544C: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x80015450: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80015454: addiu       $v0, $v0, -0x2360
    ctx->r2 = ADD32(ctx->r2, -0X2360);
    // 0x80015458: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001545C: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x80015460: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80015464: jal         0x800163BC
    // 0x80015468: sb          $t0, -0x235C($at)
    MEM_B(-0X235C, ctx->r1) = ctx->r8;
    LOOKUP_FUNC(0x800163BC)(rdram, ctx);
        goto after_1;
    // 0x80015468: sb          $t0, -0x235C($at)
    MEM_B(-0X235C, ctx->r1) = ctx->r8;
    after_1:
    // 0x8001546C: jal         0x80015B50
    // 0x80015470: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x80015B50)(rdram, ctx);
        goto after_2;
    // 0x80015470: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80015474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015478: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001547C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80015480: jr          $ra
    // 0x80015484: nop

    return;
    // 0x80015484: nop

;}
RECOMP_FUNC void FUN_80015488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015488: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001548C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80015490: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80015494: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x80015498: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001549C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800154A0: beq         $v0, $at, L_80015548
    if (ctx->r2 == ctx->r1) {
        // 0x800154A4: lui         $t0, 0x8001
        ctx->r8 = S32(0X8001 << 16);
            goto L_80015548;
    }
    // 0x800154A4: lui         $t0, 0x8001
    ctx->r8 = S32(0X8001 << 16);
    // 0x800154A8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800154AC: beq         $v0, $at, L_8001556C
    if (ctx->r2 == ctx->r1) {
        // 0x800154B0: lui         $t2, 0x8001
        ctx->r10 = S32(0X8001 << 16);
            goto L_8001556C;
    }
    // 0x800154B0: lui         $t2, 0x8001
    ctx->r10 = S32(0X8001 << 16);
    // 0x800154B4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800154B8: beq         $v0, $at, L_800154D0
    if (ctx->r2 == ctx->r1) {
        // 0x800154BC: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800154D0;
    }
    // 0x800154BC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800154C0: beql        $v0, $at, L_80015510
    if (ctx->r2 == ctx->r1) {
        // 0x800154C4: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80015510;
    }
    goto skip_0;
    // 0x800154C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    skip_0:
    // 0x800154C8: b           L_8001558C
    // 0x800154CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001558C;
    // 0x800154CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800154D0:
    // 0x800154D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800154D4: jal         0x800163BC
    // 0x800154D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800163BC)(rdram, ctx);
        goto after_0;
    // 0x800154D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800154DC: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x800154E0: lui         $t7, 0x8001
    ctx->r15 = S32(0X8001 << 16);
    // 0x800154E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800154E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800154EC: addiu       $t6, $t6, 0x6634
    ctx->r14 = ADD32(ctx->r14, 0X6634);
    // 0x800154F0: addiu       $t7, $t7, 0x65CC
    ctx->r15 = ADD32(ctx->r15, 0X65CC);
    // 0x800154F4: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x800154F8: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
    // 0x800154FC: jal         0x8001559C
    // 0x80015500: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001559C)(rdram, ctx);
        goto after_1;
    // 0x80015500: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x80015504: b           L_8001558C
    // 0x80015508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001558C;
    // 0x80015508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001550C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_80015510:
    // 0x80015510: jal         0x800163BC
    // 0x80015514: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800163BC)(rdram, ctx);
        goto after_2;
    // 0x80015514: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x80015518: lui         $t8, 0x8001
    ctx->r24 = S32(0X8001 << 16);
    // 0x8001551C: lui         $t9, 0x8001
    ctx->r25 = S32(0X8001 << 16);
    // 0x80015520: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80015524: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80015528: addiu       $t8, $t8, 0x6730
    ctx->r24 = ADD32(ctx->r24, 0X6730);
    // 0x8001552C: addiu       $t9, $t9, 0x65CC
    ctx->r25 = ADD32(ctx->r25, 0X65CC);
    // 0x80015530: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x80015534: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    // 0x80015538: jal         0x80015680
    // 0x8001553C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80015680)(rdram, ctx);
        goto after_3;
    // 0x8001553C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80015540: b           L_8001558C
    // 0x80015544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001558C;
    // 0x80015544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80015548:
    // 0x80015548: lui         $t1, 0x8001
    ctx->r9 = S32(0X8001 << 16);
    // 0x8001554C: addiu       $t0, $t0, 0x6950
    ctx->r8 = ADD32(ctx->r8, 0X6950);
    // 0x80015550: addiu       $t1, $t1, 0x68C8
    ctx->r9 = ADD32(ctx->r9, 0X68C8);
    // 0x80015554: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
    // 0x80015558: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    // 0x8001555C: jal         0x800158C0
    // 0x80015560: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800158C0)(rdram, ctx);
        goto after_4;
    // 0x80015560: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x80015564: b           L_8001558C
    // 0x80015568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001558C;
    // 0x80015568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001556C:
    // 0x8001556C: lui         $t3, 0x8001
    ctx->r11 = S32(0X8001 << 16);
    // 0x80015570: addiu       $t2, $t2, 0x6828
    ctx->r10 = ADD32(ctx->r10, 0X6828);
    // 0x80015574: addiu       $t3, $t3, 0x67FC
    ctx->r11 = ADD32(ctx->r11, 0X67FC);
    // 0x80015578: sw          $t2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r10;
    // 0x8001557C: sw          $t3, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r11;
    // 0x80015580: jal         0x80015798
    // 0x80015584: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80015798)(rdram, ctx);
        goto after_5;
    // 0x80015584: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80015588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001558C:
    // 0x8001558C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80015590: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80015594: jr          $ra
    // 0x80015598: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80015598: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8001559c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8001559c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001559C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800155A0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800155A4: addiu       $v1, $v1, -0x2054
    ctx->r3 = ADD32(ctx->r3, -0X2054);
    // 0x800155A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800155AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800155B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800155B4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800155B8: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x800155BC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800155C0: sw          $a1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r5;
    // 0x800155C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800155C8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800155CC: mflo        $a3
    ctx->r7 = lo;
    // 0x800155D0: andi        $t0, $a3, 0x3
    ctx->r8 = ctx->r7 & 0X3;
    // 0x800155D4: blezl       $a3, L_80015648
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800155D8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80015648;
    }
    goto skip_0;
    // 0x800155D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x800155DC: beq         $t0, $zero, L_80015604
    if (ctx->r8 == 0) {
        // 0x800155E0: or          $a1, $t0, $zero
        ctx->r5 = ctx->r8 | 0;
            goto L_80015604;
    }
    // 0x800155E0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800155E4: sll         $v0, $zero, 1
    ctx->r2 = S32(0 << 1);
L_800155E8:
    // 0x800155E8: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800155EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800155F0: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800155F4: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x800155F8: bne         $a1, $a0, L_800155E8
    if (ctx->r5 != ctx->r4) {
        // 0x800155FC: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_800155E8;
    }
    // 0x800155FC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80015600: beq         $a0, $a3, L_80015644
    if (ctx->r4 == ctx->r7) {
        // 0x80015604: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_80015644;
    }
L_80015604:
    // 0x80015604: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80015608: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
L_8001560C:
    // 0x8001560C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80015610: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80015614: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
    // 0x80015618: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8001561C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80015620: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
    // 0x80015624: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80015628: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8001562C: sh          $zero, 0x4($t8)
    MEM_H(0X4, ctx->r24) = 0;
    // 0x80015630: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80015634: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x80015638: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8001563C: bne         $v0, $a1, L_8001560C
    if (ctx->r2 != ctx->r5) {
        // 0x80015640: sh          $zero, 0x6($t1)
        MEM_H(0X6, ctx->r9) = 0;
            goto L_8001560C;
    }
    // 0x80015640: sh          $zero, 0x6($t1)
    MEM_H(0X6, ctx->r9) = 0;
L_80015644:
    // 0x80015644: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80015648:
    // 0x80015648: jal         0x80015D9C
    // 0x8001564C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80015D9C)(rdram, ctx);
        goto after_0;
    // 0x8001564C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80015650: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80015654: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80015658: lw          $t2, 0x14($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X14);
    // 0x8001565C: beql        $t2, $at, L_80015670
    if (ctx->r10 == ctx->r1) {
        // 0x80015660: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80015670;
    }
    goto skip_1;
    // 0x80015660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80015664: jal         0x80016A9C
    // 0x80015668: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80016A9C)(rdram, ctx);
        goto after_1;
    // 0x80015668: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8001566C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80015670:
    // 0x80015670: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80015674: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80015678: jr          $ra
    // 0x8001567C: nop

    return;
    // 0x8001567C: nop

;}
RECOMP_FUNC void FUN_80015680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015680: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80015684: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80015688: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8001568C: addiu       $s2, $s2, -0x2054
    ctx->r18 = ADD32(ctx->r18, -0X2054);
    // 0x80015690: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80015694: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80015698: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001569C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800156A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800156A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800156A8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800156AC: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800156B0: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x800156B4: sw          $a1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r5;
    // 0x800156B8: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x800156BC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800156C0: sw          $a1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r5;
    // 0x800156C4: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800156C8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800156CC: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x800156D0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800156D4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800156D8: mflo        $s4
    ctx->r20 = lo;
    // 0x800156DC: bgez        $s4, L_800156EC
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800156E0: sra         $a0, $s4, 3
        ctx->r4 = S32(SIGNED(ctx->r20) >> 3);
            goto L_800156EC;
    }
    // 0x800156E0: sra         $a0, $s4, 3
    ctx->r4 = S32(SIGNED(ctx->r20) >> 3);
    // 0x800156E4: addiu       $at, $s4, 0x7
    ctx->r1 = ADD32(ctx->r20, 0X7);
    // 0x800156E8: sra         $a0, $at, 3
    ctx->r4 = S32(SIGNED(ctx->r1) >> 3);
L_800156EC:
    // 0x800156EC: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800156F0: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    // 0x800156F4: jal         0x80016BA0
    // 0x800156F8: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    LOOKUP_FUNC(0x80016BA0)(rdram, ctx);
        goto after_0;
    // 0x800156F8: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    after_0:
    // 0x800156FC: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x80015700: addiu       $s5, $s5, -0x204C
    ctx->r21 = ADD32(ctx->r21, -0X204C);
    // 0x80015704: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x80015708: jal         0x80016058
    // 0x8001570C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80016058)(rdram, ctx);
        goto after_1;
    // 0x8001570C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80015710: blez        $s4, L_8001575C
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80015714: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8001575C;
    }
    // 0x80015714: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80015718: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001571C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
L_80015720:
    // 0x80015720: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x80015724: jal         0x80016B6C
    // 0x80015728: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80016B6C)(rdram, ctx);
        goto after_2;
    // 0x80015728: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8001572C: beql        $v0, $zero, L_80015744
    if (ctx->r2 == 0) {
        // 0x80015730: lw          $t2, 0x0($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X0);
            goto L_80015744;
    }
    goto skip_0;
    // 0x80015730: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x80015734: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80015738: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x8001573C: lhu         $s3, 0x0($t1)
    ctx->r19 = MEM_HU(ctx->r9, 0X0);
    // 0x80015740: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
L_80015744:
    // 0x80015744: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80015748: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8001574C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80015750: bne         $s1, $s4, L_80015720
    if (ctx->r17 != ctx->r20) {
        // 0x80015754: sh          $s3, 0x0($t3)
        MEM_H(0X0, ctx->r11) = ctx->r19;
            goto L_80015720;
    }
    // 0x80015754: sh          $s3, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r19;
    // 0x80015758: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
L_8001575C:
    // 0x8001575C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80015760: beql        $t4, $zero, L_80015774
    if (ctx->r12 == 0) {
        // 0x80015764: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80015774;
    }
    goto skip_1;
    // 0x80015764: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80015768: jal         0x8001F540
    // 0x8001576C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_3;
    // 0x8001576C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_3:
    // 0x80015770: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80015774:
    // 0x80015774: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80015778: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001577C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80015780: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80015784: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80015788: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001578C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80015790: jr          $ra
    // 0x80015794: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80015794: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80015798(rdram, ctx);
;}
RECOMP_FUNC void FUN_80015798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015798: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001579C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800157A0: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x800157A4: addiu       $s1, $s1, -0x2050
    ctx->r17 = ADD32(ctx->r17, -0X2050);
    // 0x800157A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800157AC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800157B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800157B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800157B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800157BC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800157C0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800157C4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x800157C8: sw          $a1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r5;
    // 0x800157CC: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x800157D0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800157D4: lw          $t0, 0x10($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X10);
    // 0x800157D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800157DC: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800157E0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800157E4: sw          $a1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r5;
    // 0x800157E8: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x800157EC: mflo        $v0
    ctx->r2 = lo;
    // 0x800157F0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800157F4: bne         $t0, $at, L_80015814
    if (ctx->r8 != ctx->r1) {
        // 0x800157F8: addu        $t2, $a1, $v0
        ctx->r10 = ADD32(ctx->r5, ctx->r2);
            goto L_80015814;
    }
    // 0x800157F8: addu        $t2, $a1, $v0
    ctx->r10 = ADD32(ctx->r5, ctx->r2);
    // 0x800157FC: addiu       $t3, $t2, 0x7
    ctx->r11 = ADD32(ctx->r10, 0X7);
    // 0x80015800: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80015804: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80015808: sw          $t4, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r12;
    // 0x8001580C: jal         0x80015A64
    // 0x80015810: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80015A64)(rdram, ctx);
        goto after_0;
    // 0x80015810: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
L_80015814:
    // 0x80015814: bgez        $s3, L_80015824
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80015818: sra         $a0, $s3, 3
        ctx->r4 = S32(SIGNED(ctx->r19) >> 3);
            goto L_80015824;
    }
    // 0x80015818: sra         $a0, $s3, 3
    ctx->r4 = S32(SIGNED(ctx->r19) >> 3);
    // 0x8001581C: addiu       $at, $s3, 0x7
    ctx->r1 = ADD32(ctx->r19, 0X7);
    // 0x80015820: sra         $a0, $at, 3
    ctx->r4 = S32(SIGNED(ctx->r1) >> 3);
L_80015824:
    // 0x80015824: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015828: jal         0x80016BA0
    // 0x8001582C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x80016BA0)(rdram, ctx);
        goto after_1;
    // 0x8001582C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80015830: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x80015834: addiu       $s4, $s4, -0x204C
    ctx->r20 = ADD32(ctx->r20, -0X204C);
    // 0x80015838: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x8001583C: jal         0x80016058
    // 0x80015840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80016058)(rdram, ctx);
        goto after_2;
    // 0x80015840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80015844: blez        $s3, L_80015888
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80015848: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80015888;
    }
    // 0x80015848: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001584C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
L_80015850:
    // 0x80015850: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80015854: jal         0x80016B6C
    // 0x80015858: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80016B6C)(rdram, ctx);
        goto after_3;
    // 0x80015858: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8001585C: beql        $v0, $zero, L_80015874
    if (ctx->r2 == 0) {
        // 0x80015860: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_80015874;
    }
    goto skip_0;
    // 0x80015860: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80015864: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80015868: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x8001586C: lbu         $s2, 0x0($t6)
    ctx->r18 = MEM_BU(ctx->r14, 0X0);
    // 0x80015870: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_80015874:
    // 0x80015874: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80015878: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001587C: bne         $s0, $s3, L_80015850
    if (ctx->r16 != ctx->r19) {
        // 0x80015880: sb          $s2, 0x0($t8)
        MEM_B(0X0, ctx->r24) = ctx->r18;
            goto L_80015850;
    }
    // 0x80015880: sb          $s2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r18;
    // 0x80015884: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
L_80015888:
    // 0x80015888: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8001588C: beql        $t9, $zero, L_800158A0
    if (ctx->r25 == 0) {
        // 0x80015890: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800158A0;
    }
    goto skip_1;
    // 0x80015890: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80015894: jal         0x8001F540
    // 0x80015898: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_4;
    // 0x80015898: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_4:
    // 0x8001589C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800158A0:
    // 0x800158A0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x800158A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800158A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800158AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800158B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800158B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800158B8: jr          $ra
    // 0x800158BC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800158BC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800158c0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800158c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800158C0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800158C4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800158C8: addiu       $v0, $v0, -0x2050
    ctx->r2 = ADD32(ctx->r2, -0X2050);
    // 0x800158CC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800158D0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800158D4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800158D8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800158DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800158E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800158E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800158E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800158EC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800158F0: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800158F4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x800158F8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x800158FC: lw          $s5, 0x0($a2)
    ctx->r21 = MEM_W(ctx->r6, 0X0);
    // 0x80015900: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x80015904: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80015908: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001590C: and         $s5, $s5, $at
    ctx->r21 = ctx->r21 & ctx->r1;
    // 0x80015910: multu       $t8, $s5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80015914: lw          $t9, 0x10($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X10);
    // 0x80015918: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8001591C: sw          $a1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r5;
    // 0x80015920: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80015924: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80015928: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8001592C: mflo        $s0
    ctx->r16 = lo;
    // 0x80015930: andi        $t1, $s0, 0x1
    ctx->r9 = ctx->r16 & 0X1;
    // 0x80015934: bne         $t9, $at, L_8001596C
    if (ctx->r25 != ctx->r1) {
        // 0x80015938: nop
    
            goto L_8001596C;
    }
    // 0x80015938: nop

    // 0x8001593C: lw          $t3, 0x1C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1C);
    // 0x80015940: bgez        $s0, L_80015950
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80015944: sra         $t0, $s0, 1
        ctx->r8 = S32(SIGNED(ctx->r16) >> 1);
            goto L_80015950;
    }
    // 0x80015944: sra         $t0, $s0, 1
    ctx->r8 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80015948: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x8001594C: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_80015950:
    // 0x80015950: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80015954: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x80015958: addiu       $t5, $t4, 0x7
    ctx->r13 = ADD32(ctx->r12, 0X7);
    // 0x8001595C: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80015960: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80015964: jal         0x80015A64
    // 0x80015968: sw          $t6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r14;
    LOOKUP_FUNC(0x80015A64)(rdram, ctx);
        goto after_0;
    // 0x80015968: sw          $t6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r14;
    after_0:
L_8001596C:
    // 0x8001596C: bgez        $s0, L_8001597C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80015970: sra         $a0, $s0, 3
        ctx->r4 = S32(SIGNED(ctx->r16) >> 3);
            goto L_8001597C;
    }
    // 0x80015970: sra         $a0, $s0, 3
    ctx->r4 = S32(SIGNED(ctx->r16) >> 3);
    // 0x80015974: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x80015978: sra         $a0, $at, 3
    ctx->r4 = S32(SIGNED(ctx->r1) >> 3);
L_8001597C:
    // 0x8001597C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015980: jal         0x80016BA0
    // 0x80015984: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    LOOKUP_FUNC(0x80016BA0)(rdram, ctx);
        goto after_1;
    // 0x80015984: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80015988: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x8001598C: addiu       $s6, $s6, -0x204C
    ctx->r22 = ADD32(ctx->r22, -0X204C);
    // 0x80015990: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x80015994: jal         0x80016058
    // 0x80015998: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80016058)(rdram, ctx);
        goto after_2;
    // 0x80015998: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8001599C: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800159A0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800159A4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800159A8: blez        $v0, L_80015A24
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800159AC: lw          $s3, 0x48($sp)
        ctx->r19 = MEM_W(ctx->r29, 0X48);
            goto L_80015A24;
    }
    // 0x800159AC: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
L_800159B0:
    // 0x800159B0: blez        $s5, L_80015A10
    if (SIGNED(ctx->r21) <= 0) {
        // 0x800159B4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80015A10;
    }
    // 0x800159B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800159B8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
L_800159BC:
    // 0x800159BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800159C0: jal         0x80016B6C
    // 0x800159C4: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    LOOKUP_FUNC(0x80016B6C)(rdram, ctx);
        goto after_3;
    // 0x800159C4: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_3:
    // 0x800159C8: beql        $v0, $zero, L_800159EC
    if (ctx->r2 == 0) {
        // 0x800159CC: lw          $t9, 0x24($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X24);
            goto L_800159EC;
    }
    goto skip_0;
    // 0x800159CC: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    skip_0:
    // 0x800159D0: lw          $t9, 0x28($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X28);
    // 0x800159D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800159D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800159DC: jalr        $t9
    // 0x800159E0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800159E0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_4:
    // 0x800159E4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800159E8: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
L_800159EC:
    // 0x800159EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800159F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800159F4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800159F8: jalr        $t9
    // 0x800159FC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x800159FC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_5:
    // 0x80015A00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80015A04: bnel        $s0, $s5, L_800159BC
    if (ctx->r16 != ctx->r21) {
        // 0x80015A08: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_800159BC;
    }
    goto skip_1;
    // 0x80015A08: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    skip_1:
    // 0x80015A0C: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
L_80015A10:
    // 0x80015A10: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80015A14: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015A18: bne         $at, $zero, L_800159B0
    if (ctx->r1 != 0) {
        // 0x80015A1C: nop
    
            goto L_800159B0;
    }
    // 0x80015A1C: nop

    // 0x80015A20: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
L_80015A24:
    // 0x80015A24: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80015A28: beql        $t7, $zero, L_80015A3C
    if (ctx->r15 == 0) {
        // 0x80015A2C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80015A3C;
    }
    goto skip_2;
    // 0x80015A2C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80015A30: jal         0x8001F540
    // 0x80015A34: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_6;
    // 0x80015A34: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_6:
    // 0x80015A38: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80015A3C:
    // 0x80015A3C: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80015A40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80015A44: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80015A48: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80015A4C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80015A50: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80015A54: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80015A58: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80015A5C: jr          $ra
    // 0x80015A60: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80015A60: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80015a64(rdram, ctx);
;}
RECOMP_FUNC void FUN_80015a64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015A64: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80015A68: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80015A6C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80015A70: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80015A74: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80015A78: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80015A7C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80015A80: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80015A84: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80015A88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80015A8C: blez        $a0, L_80015B24
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80015A90: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80015B24;
    }
    // 0x80015A90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80015A94: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80015A98: sll         $s5, $a0, 1
    ctx->r21 = S32(ctx->r4 << 1);
    // 0x80015A9C: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
L_80015AA0:
    // 0x80015AA0: jal         0x80016D50
    // 0x80015AA4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_0;
    // 0x80015AA4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x80015AA8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80015AAC: jal         0x80016D50
    // 0x80015AB0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_1;
    // 0x80015AB0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x80015AB4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80015AB8: jal         0x80016D50
    // 0x80015ABC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_2;
    // 0x80015ABC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x80015AC0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80015AC4: jal         0x80016D50
    // 0x80015AC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_3;
    // 0x80015AC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80015ACC: lw          $t2, 0x20($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X20);
    // 0x80015AD0: sll         $t6, $s2, 11
    ctx->r14 = S32(ctx->r18 << 11);
    // 0x80015AD4: sll         $t7, $s1, 6
    ctx->r15 = S32(ctx->r17 << 6);
    // 0x80015AD8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80015ADC: sll         $t9, $s3, 1
    ctx->r25 = S32(ctx->r19 << 1);
    // 0x80015AE0: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80015AE4: or          $t1, $v0, $t0
    ctx->r9 = ctx->r2 | ctx->r8;
    // 0x80015AE8: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80015AEC: sh          $t1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r9;
    // 0x80015AF0: lw          $v1, 0x14($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X14);
    // 0x80015AF4: beql        $s6, $v1, L_80015B1C
    if (ctx->r22 == ctx->r3) {
        // 0x80015AF8: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80015B1C;
    }
    goto skip_0;
    // 0x80015AF8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_0:
    // 0x80015AFC: lw          $t4, 0x20($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X20);
    // 0x80015B00: addu        $v0, $t4, $s0
    ctx->r2 = ADD32(ctx->r12, ctx->r16);
    // 0x80015B04: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80015B08: andi        $a0, $a0, 0xFFFE
    ctx->r4 = ctx->r4 & 0XFFFE;
    // 0x80015B0C: bnel        $v1, $a0, L_80015B1C
    if (ctx->r3 != ctx->r4) {
        // 0x80015B10: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80015B1C;
    }
    goto skip_1;
    // 0x80015B10: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_1:
    // 0x80015B14: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80015B18: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80015B1C:
    // 0x80015B1C: bne         $s0, $s5, L_80015AA0
    if (ctx->r16 != ctx->r21) {
        // 0x80015B20: nop
    
            goto L_80015AA0;
    }
    // 0x80015B20: nop

L_80015B24:
    // 0x80015B24: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80015B28: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80015B2C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80015B30: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80015B34: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80015B38: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80015B3C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80015B40: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80015B44: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80015B48: jr          $ra
    // 0x80015B4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80015B4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80015b50(rdram, ctx);
;}
RECOMP_FUNC void FUN_80015b50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015B50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80015B54: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80015B58: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80015B5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80015B60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80015B64: jal         0x80016D50
    // 0x80015B68: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_0;
    // 0x80015B68: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80015B6C: jal         0x80016D50
    // 0x80015B70: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_1;
    // 0x80015B70: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x80015B74: jal         0x80016D50
    // 0x80015B78: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_2;
    // 0x80015B78: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_2:
    // 0x80015B7C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80015B80: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80015B84: sw          $t6, -0x2364($at)
    MEM_W(-0X2364, ctx->r1) = ctx->r14;
    // 0x80015B88: jal         0x80016D50
    // 0x80015B8C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_3;
    // 0x80015B8C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_3:
    // 0x80015B90: addiu       $s0, $zero, 0x1A
    ctx->r16 = ADD32(0, 0X1A);
    // 0x80015B94: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80015B98: beq         $s0, $v1, L_80015BF4
    if (ctx->r16 == ctx->r3) {
        // 0x80015B9C: sb          $v1, 0x2C($sp)
        MEM_B(0X2C, ctx->r29) = ctx->r3;
            goto L_80015BF4;
    }
    // 0x80015B9C: sb          $v1, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r3;
    // 0x80015BA0: jal         0x80016D50
    // 0x80015BA4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_4;
    // 0x80015BA4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_4:
    // 0x80015BA8: sb          $v0, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r2;
    // 0x80015BAC: jal         0x80016D50
    // 0x80015BB0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_5;
    // 0x80015BB0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_5:
    // 0x80015BB4: sb          $v0, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r2;
    // 0x80015BB8: jal         0x80016D50
    // 0x80015BBC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_6;
    // 0x80015BBC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_6:
    // 0x80015BC0: sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
    // 0x80015BC4: jal         0x80016A24
    // 0x80015BC8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80016A24)(rdram, ctx);
        goto after_7;
    // 0x80015BC8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_7:
    // 0x80015BCC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80015BD0: sw          $v0, -0x2364($at)
    MEM_W(-0X2364, ctx->r1) = ctx->r2;
    // 0x80015BD4: jal         0x80016D50
    // 0x80015BD8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_8;
    // 0x80015BD8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_8:
    // 0x80015BDC: beq         $v0, $s0, L_80015BF4
    if (ctx->r2 == ctx->r16) {
        // 0x80015BE0: nop
    
            goto L_80015BF4;
    }
    // 0x80015BE0: nop

L_80015BE4:
    // 0x80015BE4: jal         0x80016D50
    // 0x80015BE8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_9;
    // 0x80015BE8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_9:
    // 0x80015BEC: bne         $v0, $s0, L_80015BE4
    if (ctx->r2 != ctx->r16) {
        // 0x80015BF0: nop
    
            goto L_80015BE4;
    }
    // 0x80015BF0: nop

L_80015BF4:
    // 0x80015BF4: jal         0x80016D50
    // 0x80015BF8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_10;
    // 0x80015BF8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_10:
    // 0x80015BFC: beq         $v0, $zero, L_80015C14
    if (ctx->r2 == 0) {
        // 0x80015C00: nop
    
            goto L_80015C14;
    }
    // 0x80015C00: nop

L_80015C04:
    // 0x80015C04: jal         0x80016D50
    // 0x80015C08: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_11;
    // 0x80015C08: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_11:
    // 0x80015C0C: bne         $v0, $zero, L_80015C04
    if (ctx->r2 != 0) {
        // 0x80015C10: nop
    
            goto L_80015C04;
    }
    // 0x80015C10: nop

L_80015C14:
    // 0x80015C14: jal         0x80016D50
    // 0x80015C18: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_12;
    // 0x80015C18: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_12:
    // 0x80015C1C: jal         0x80016D50
    // 0x80015C20: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_13;
    // 0x80015C20: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_13:
    // 0x80015C24: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80015C28: jal         0x80016D50
    // 0x80015C2C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_14;
    // 0x80015C2C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_14:
    // 0x80015C30: jal         0x80016D50
    // 0x80015C34: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_15;
    // 0x80015C34: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_15:
    // 0x80015C38: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x80015C3C: jal         0x80016D50
    // 0x80015C40: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_16;
    // 0x80015C40: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_16:
    // 0x80015C44: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80015C48: addiu       $s0, $s0, -0x236C
    ctx->r16 = ADD32(ctx->r16, -0X236C);
    // 0x80015C4C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80015C50: jal         0x80016D50
    // 0x80015C54: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_17;
    // 0x80015C54: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_17:
    // 0x80015C58: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80015C5C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80015C60: addiu       $a0, $a0, -0x2368
    ctx->r4 = ADD32(ctx->r4, -0X2368);
    // 0x80015C64: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80015C68: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80015C6C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80015C70: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x80015C74: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x80015C78: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80015C7C: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x80015C80: lw          $t9, -0x2364($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2364);
    // 0x80015C84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80015C88: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80015C8C: sw          $t9, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r25;
    // 0x80015C90: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80015C94: bnel        $t0, $a1, L_80015CEC
    if (ctx->r8 != ctx->r5) {
        // 0x80015C98: lw          $v0, 0x8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8);
            goto L_80015CEC;
    }
    goto skip_0;
    // 0x80015C98: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_0:
    // 0x80015C9C: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x80015CA0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80015CA4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80015CA8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80015CAC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80015CB0: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80015CB4: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80015CB8: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x80015CBC: mflo        $t6
    ctx->r14 = lo;
    // 0x80015CC0: nop

    // 0x80015CC4: nop

    // 0x80015CC8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80015CCC: mflo        $t8
    ctx->r24 = lo;
    // 0x80015CD0: bgez        $t8, L_80015CE0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80015CD4: sra         $t9, $t8, 3
        ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
            goto L_80015CE0;
    }
    // 0x80015CD4: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80015CD8: addiu       $at, $t8, 0x7
    ctx->r1 = ADD32(ctx->r24, 0X7);
    // 0x80015CDC: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_80015CE0:
    // 0x80015CE0: b           L_80015D88
    // 0x80015CE4: sw          $t9, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r25;
        goto L_80015D88;
    // 0x80015CE4: sw          $t9, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r25;
    // 0x80015CE8: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_80015CEC:
    // 0x80015CEC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80015CF0: beq         $v0, $at, L_80015D00
    if (ctx->r2 == ctx->r1) {
        // 0x80015CF4: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80015D00;
    }
    // 0x80015CF4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80015CF8: bne         $v0, $at, L_80015D20
    if (ctx->r2 != ctx->r1) {
        // 0x80015CFC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80015D20;
    }
    // 0x80015CFC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_80015D00:
    // 0x80015D00: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x80015D04: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80015D08: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80015D0C: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80015D10: mflo        $t2
    ctx->r10 = lo;
    // 0x80015D14: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80015D18: b           L_80015D88
    // 0x80015D1C: sw          $t3, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r11;
        goto L_80015D88;
    // 0x80015D1C: sw          $t3, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r11;
L_80015D20:
    // 0x80015D20: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
    // 0x80015D24: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80015D28: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80015D2C: xor         $t2, $a1, $v0
    ctx->r10 = ctx->r5 ^ ctx->r2;
    // 0x80015D30: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80015D34: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80015D38: xori        $t5, $v0, 0x8
    ctx->r13 = ctx->r2 ^ 0X8;
    // 0x80015D3C: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x80015D40: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80015D44: sll         $t6, $t5, 9
    ctx->r14 = S32(ctx->r13 << 9);
    // 0x80015D48: mflo        $v1
    ctx->r3 = lo;
    // 0x80015D4C: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x80015D50: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80015D54: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80015D58: mflo        $t7
    ctx->r15 = lo;
    // 0x80015D5C: bgez        $t7, L_80015D6C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80015D60: sra         $t8, $t7, 3
        ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
            goto L_80015D6C;
    }
    // 0x80015D60: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80015D64: addiu       $at, $t7, 0x7
    ctx->r1 = ADD32(ctx->r15, 0X7);
    // 0x80015D68: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_80015D6C:
    // 0x80015D6C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80015D70: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80015D74: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80015D78: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x80015D7C: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80015D80: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x80015D84: sw          $t8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r24;
L_80015D88:
    // 0x80015D88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80015D8C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80015D90: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80015D94: jr          $ra
    // 0x80015D98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80015D98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80015d9c(rdram, ctx);
;}
RECOMP_FUNC void FUN_80015d9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015D9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80015DA0: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80015DA4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80015DA8: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80015DAC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80015DB0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80015DB4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80015DB8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80015DBC: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x80015DC0: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80015DC4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80015DC8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80015DCC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80015DD0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80015DD4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80015DD8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80015DDC: addiu       $s6, $s6, -0x2368
    ctx->r22 = ADD32(ctx->r22, -0X2368);
    // 0x80015DE0: addiu       $s5, $s5, -0x236C
    ctx->r21 = ADD32(ctx->r21, -0X236C);
    // 0x80015DE4: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
L_80015DE8:
    // 0x80015DE8: jal         0x800162EC
    // 0x80015DEC: nop

    LOOKUP_FUNC(0x800162EC)(rdram, ctx);
        goto after_0;
    // 0x80015DEC: nop

    after_0:
    // 0x80015DF0: addiu       $s2, $v0, -0x1
    ctx->r18 = ADD32(ctx->r2, -0X1);
    // 0x80015DF4: beql        $s2, $zero, L_80015E78
    if (ctx->r18 == 0) {
        // 0x80015DF8: lw          $t0, 0x0($s5)
        ctx->r8 = MEM_W(ctx->r21, 0X0);
            goto L_80015E78;
    }
    goto skip_0;
    // 0x80015DF8: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    skip_0:
    // 0x80015DFC: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
L_80015E00:
    // 0x80015E00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80015E04: bnel        $s0, $t6, L_80015E24
    if (ctx->r16 != ctx->r14) {
        // 0x80015E08: lw          $t9, 0x28($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X28);
            goto L_80015E24;
    }
    goto skip_1;
    // 0x80015E08: lw          $t9, 0x28($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X28);
    skip_1:
    // 0x80015E0C: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x80015E10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80015E14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80015E18: beql        $s1, $t7, L_80015EEC
    if (ctx->r17 == ctx->r15) {
        // 0x80015E1C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80015EEC;
    }
    goto skip_2;
    // 0x80015E1C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80015E20: lw          $t9, 0x28($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X28);
L_80015E24:
    // 0x80015E24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80015E28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80015E2C: jalr        $t9
    // 0x80015E30: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80015E30: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x80015E34: beq         $v0, $zero, L_80015E54
    if (ctx->r2 == 0) {
        // 0x80015E38: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80015E54;
    }
    // 0x80015E38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80015E3C: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
    // 0x80015E40: andi        $s4, $v0, 0xFFFE
    ctx->r20 = ctx->r2 & 0XFFFE;
    // 0x80015E44: bne         $s7, $t8, L_80015E54
    if (ctx->r23 != ctx->r24) {
        // 0x80015E48: nop
    
            goto L_80015E54;
    }
    // 0x80015E48: nop

    // 0x80015E4C: b           L_80015E54
    // 0x80015E50: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
        goto L_80015E54;
    // 0x80015E50: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_80015E54:
    // 0x80015E54: lw          $t9, 0x24($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X24);
    // 0x80015E58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80015E5C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80015E60: jalr        $t9
    // 0x80015E64: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80015E64: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_2:
    // 0x80015E68: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80015E6C: bnel        $s2, $zero, L_80015E00
    if (ctx->r18 != 0) {
        // 0x80015E70: lw          $t6, 0x0($s5)
        ctx->r14 = MEM_W(ctx->r21, 0X0);
            goto L_80015E00;
    }
    goto skip_3;
    // 0x80015E70: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    skip_3:
    // 0x80015E74: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
L_80015E78:
    // 0x80015E78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80015E7C: bne         $s0, $t0, L_80015E98
    if (ctx->r16 != ctx->r8) {
        // 0x80015E80: nop
    
            goto L_80015E98;
    }
    // 0x80015E80: nop

    // 0x80015E84: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x80015E88: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80015E8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80015E90: beql        $s1, $t1, L_80015EEC
    if (ctx->r17 == ctx->r9) {
        // 0x80015E94: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80015EEC;
    }
    goto skip_4;
    // 0x80015E94: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_4:
L_80015E98:
    // 0x80015E98: jal         0x80016340
    // 0x80015E9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80016340)(rdram, ctx);
        goto after_3;
    // 0x80015E9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80015EA0: lw          $t9, 0x24($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X24);
    // 0x80015EA4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80015EA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80015EAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80015EB0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80015EB4: jalr        $t9
    // 0x80015EB8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80015EB8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_4:
    // 0x80015EBC: jal         0x80016CE4
    // 0x80015EC0: nop

    LOOKUP_FUNC(0x80016CE4)(rdram, ctx);
        goto after_5;
    // 0x80015EC0: nop

    after_5:
    // 0x80015EC4: beq         $v0, $zero, L_80015DE8
    if (ctx->r2 == 0) {
        // 0x80015EC8: nop
    
            goto L_80015DE8;
    }
    // 0x80015EC8: nop

    // 0x80015ECC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80015ED0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80015ED4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80015ED8: jal         0x80015F14
    // 0x80015EDC: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80015F14)(rdram, ctx);
        goto after_6;
    // 0x80015EDC: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_6:
    // 0x80015EE0: b           L_80015DE8
    // 0x80015EE4: nop

        goto L_80015DE8;
    // 0x80015EE4: nop

    // 0x80015EE8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80015EEC:
    // 0x80015EEC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80015EF0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80015EF4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80015EF8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80015EFC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80015F00: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80015F04: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80015F08: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80015F0C: jr          $ra
    // 0x80015F10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80015F10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80015f14(rdram, ctx);
;}
RECOMP_FUNC void FUN_80015f14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015F14: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80015F18: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80015F1C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80015F20: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80015F24: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80015F28: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80015F2C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80015F30: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80015F34: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80015F38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80015F3C: lui         $fp, 0x8009
    ctx->r30 = S32(0X8009 << 16);
    // 0x80015F40: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80015F44: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80015F48: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80015F4C: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80015F50: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80015F54: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80015F58: addiu       $fp, $fp, -0x236C
    ctx->r30 = ADD32(ctx->r30, -0X236C);
    // 0x80015F5C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80015F60: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80015F64: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
L_80015F68:
    // 0x80015F68: jal         0x80016D50
    // 0x80015F6C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_0;
    // 0x80015F6C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80015F70: beq         $v0, $zero, L_80015F98
    if (ctx->r2 == 0) {
        // 0x80015F74: nop
    
            goto L_80015F98;
    }
    // 0x80015F74: nop

    // 0x80015F78: beq         $v0, $s5, L_80015FC8
    if (ctx->r2 == ctx->r21) {
        // 0x80015F7C: nop
    
            goto L_80015FC8;
    }
    // 0x80015F7C: nop

    // 0x80015F80: beql        $v0, $s6, L_80015FD8
    if (ctx->r2 == ctx->r22) {
        // 0x80015F84: lw          $t6, 0x0($fp)
        ctx->r14 = MEM_W(ctx->r30, 0X0);
            goto L_80015FD8;
    }
    goto skip_0;
    // 0x80015F84: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    skip_0:
    // 0x80015F88: beql        $v0, $s7, L_80015FD4
    if (ctx->r2 == ctx->r23) {
        // 0x80015F8C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80015FD4;
    }
    goto skip_1;
    // 0x80015F8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80015F90: b           L_80015FD8
    // 0x80015F94: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
        goto L_80015FD8;
    // 0x80015F94: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
L_80015F98:
    // 0x80015F98: jal         0x80016CE4
    // 0x80015F9C: nop

    LOOKUP_FUNC(0x80016CE4)(rdram, ctx);
        goto after_1;
    // 0x80015F9C: nop

    after_1:
    // 0x80015FA0: beql        $v0, $zero, L_8001602C
    if (ctx->r2 == 0) {
        // 0x80015FA4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8001602C;
    }
    goto skip_2;
    // 0x80015FA4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x80015FA8: jal         0x80016CE4
    // 0x80015FAC: nop

    LOOKUP_FUNC(0x80016CE4)(rdram, ctx);
        goto after_2;
    // 0x80015FAC: nop

    after_2:
    // 0x80015FB0: bne         $v0, $zero, L_80015FC0
    if (ctx->r2 != 0) {
        // 0x80015FB4: nop
    
            goto L_80015FC0;
    }
    // 0x80015FB4: nop

    // 0x80015FB8: b           L_80015FD4
    // 0x80015FBC: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
        goto L_80015FD4;
    // 0x80015FBC: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
L_80015FC0:
    // 0x80015FC0: b           L_80015FD4
    // 0x80015FC4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
        goto L_80015FD4;
    // 0x80015FC4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80015FC8:
    // 0x80015FC8: b           L_80015FD4
    // 0x80015FCC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_80015FD4;
    // 0x80015FCC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80015FD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80015FD4:
    // 0x80015FD4: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
L_80015FD8:
    // 0x80015FD8: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80015FDC: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80015FE0: beql        $at, $zero, L_8001602C
    if (ctx->r1 == 0) {
        // 0x80015FE4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8001602C;
    }
    goto skip_3;
    // 0x80015FE4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x80015FE8: lw          $t7, -0x2368($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2368);
    // 0x80015FEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80015FF0: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80015FF4: bne         $at, $zero, L_80016000
    if (ctx->r1 != 0) {
        // 0x80015FF8: nop
    
            goto L_80016000;
    }
    // 0x80015FF8: nop

    // 0x80015FFC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80016000:
    // 0x80016000: beq         $s2, $zero, L_80015F68
    if (ctx->r18 == 0) {
        // 0x80016004: nop
    
            goto L_80015F68;
    }
    // 0x80016004: nop

    // 0x80016008: lw          $t9, 0x24($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X24);
    // 0x8001600C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80016010: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80016014: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80016018: jalr        $t9
    // 0x8001601C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8001601C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_3:
    // 0x80016020: b           L_80015F68
    // 0x80016024: nop

        goto L_80015F68;
    // 0x80016024: nop

    // 0x80016028: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8001602C:
    // 0x8001602C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016030: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80016034: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80016038: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001603C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80016040: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80016044: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80016048: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001604C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80016050: jr          $ra
    // 0x80016054: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80016054: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80016058(rdram, ctx);
;}
RECOMP_FUNC void FUN_80016058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016058: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001605C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80016060: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80016064: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80016068: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001606C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80016070: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80016074: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80016078: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001607C: lw          $t9, 0x24($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X24);
    // 0x80016080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80016088: jalr        $t9
    // 0x8001608C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8001608C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80016090: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80016094: lw          $t7, 0x4($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X4);
    // 0x80016098: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8001609C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800160A0: mflo        $s5
    ctx->r21 = lo;
    // 0x800160A4: bltzl       $s5, L_80016180
    if (SIGNED(ctx->r21) < 0) {
        // 0x800160A8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80016180;
    }
    goto skip_0;
    // 0x800160A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_800160AC:
    // 0x800160AC: jal         0x80016CE4
    // 0x800160B0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80016CE4)(rdram, ctx);
        goto after_1;
    // 0x800160B0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_1:
    // 0x800160B4: beq         $v0, $zero, L_800160CC
    if (ctx->r2 == 0) {
        // 0x800160B8: nop
    
            goto L_800160CC;
    }
    // 0x800160B8: nop

L_800160BC:
    // 0x800160BC: jal         0x80016CE4
    // 0x800160C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    LOOKUP_FUNC(0x80016CE4)(rdram, ctx);
        goto after_2;
    // 0x800160C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_2:
    // 0x800160C4: bne         $v0, $zero, L_800160BC
    if (ctx->r2 != 0) {
        // 0x800160C8: nop
    
            goto L_800160BC;
    }
    // 0x800160C8: nop

L_800160CC:
    // 0x800160CC: jal         0x80016D50
    // 0x800160D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_3;
    // 0x800160D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800160D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800160D8: sllv        $t0, $t8, $s0
    ctx->r8 = S32(ctx->r24 << (ctx->r16 & 31));
    // 0x800160DC: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x800160E0: addu        $s2, $s2, $t1
    ctx->r18 = ADD32(ctx->r18, ctx->r9);
    // 0x800160E4: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800160E8: slt         $at, $s2, $s5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800160EC: beql        $at, $zero, L_80016174
    if (ctx->r1 == 0) {
        // 0x800160F0: slt         $at, $s2, $s5
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_80016174;
    }
    goto skip_1;
    // 0x800160F0: slt         $at, $s2, $s5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r21) ? 1 : 0;
    skip_1:
    // 0x800160F4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800160F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800160FC: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80016100: mfhi        $s0
    ctx->r16 = hi;
    // 0x80016104: mflo        $s1
    ctx->r17 = lo;
    // 0x80016108: bne         $v0, $zero, L_80016114
    if (ctx->r2 != 0) {
        // 0x8001610C: nop
    
            goto L_80016114;
    }
    // 0x8001610C: nop

    // 0x80016110: break       7
    do_break(2147574032);
L_80016114:
    // 0x80016114: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80016118: bne         $v0, $at, L_8001612C
    if (ctx->r2 != ctx->r1) {
        // 0x8001611C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001612C;
    }
    // 0x8001611C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80016120: bne         $s2, $at, L_8001612C
    if (ctx->r18 != ctx->r1) {
        // 0x80016124: nop
    
            goto L_8001612C;
    }
    // 0x80016124: nop

    // 0x80016128: break       6
    do_break(2147574056);
L_8001612C:
    // 0x8001612C: jal         0x80016340
    // 0x80016130: nop

    LOOKUP_FUNC(0x80016340)(rdram, ctx);
        goto after_4;
    // 0x80016130: nop

    after_4:
    // 0x80016134: lw          $t9, 0x24($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X24);
    // 0x80016138: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8001613C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80016140: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80016144: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80016148: jalr        $t9
    // 0x8001614C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8001614C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_5:
    // 0x80016150: jal         0x80016CE4
    // 0x80016154: nop

    LOOKUP_FUNC(0x80016CE4)(rdram, ctx);
        goto after_6;
    // 0x80016154: nop

    after_6:
    // 0x80016158: beq         $v0, $zero, L_80016170
    if (ctx->r2 == 0) {
        // 0x8001615C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80016170;
    }
    // 0x8001615C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80016160: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80016164: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80016168: jal         0x800161A0
    // 0x8001616C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800161A0)(rdram, ctx);
        goto after_7;
    // 0x8001616C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_7:
L_80016170:
    // 0x80016170: slt         $at, $s2, $s5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r21) ? 1 : 0;
L_80016174:
    // 0x80016174: bne         $at, $zero, L_800160AC
    if (ctx->r1 != 0) {
        // 0x80016178: nop
    
            goto L_800160AC;
    }
    // 0x80016178: nop

    // 0x8001617C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80016180:
    // 0x80016180: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80016184: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80016188: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001618C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80016190: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80016194: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80016198: jr          $ra
    // 0x8001619C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001619C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800161a0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800161a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800161A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800161A4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800161A8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800161AC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800161B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800161B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800161B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800161BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800161C0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800161C4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800161C8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800161CC: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800161D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800161D4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800161D8: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800161DC: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
L_800161E0:
    // 0x800161E0: jal         0x80016D50
    // 0x800161E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80016D50)(rdram, ctx);
        goto after_0;
    // 0x800161E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x800161E8: beq         $v0, $zero, L_80016278
    if (ctx->r2 == 0) {
        // 0x800161EC: nop
    
            goto L_80016278;
    }
    // 0x800161EC: nop

    // 0x800161F0: beq         $v0, $s4, L_80016210
    if (ctx->r2 == ctx->r20) {
        // 0x800161F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80016210;
    }
    // 0x800161F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800161F8: beq         $v0, $s5, L_80016234
    if (ctx->r2 == ctx->r21) {
        // 0x800161FC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80016234;
    }
    // 0x800161FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80016200: beq         $v0, $s6, L_80016254
    if (ctx->r2 == ctx->r22) {
        // 0x80016204: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80016254;
    }
    // 0x80016204: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80016208: b           L_800161E0
    // 0x8001620C: nop

        goto L_800161E0;
    // 0x8001620C: nop

L_80016210:
    // 0x80016210: lw          $t9, 0x24($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X24);
    // 0x80016214: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80016218: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001621C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80016220: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80016224: jalr        $t9
    // 0x80016228: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80016228: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
    // 0x8001622C: b           L_800161E0
    // 0x80016230: nop

        goto L_800161E0;
    // 0x80016230: nop

L_80016234:
    // 0x80016234: lw          $t9, 0x24($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X24);
    // 0x80016238: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001623C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80016240: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80016244: jalr        $t9
    // 0x80016248: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80016248: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_2:
    // 0x8001624C: b           L_800161E0
    // 0x80016250: nop

        goto L_800161E0;
    // 0x80016250: nop

L_80016254:
    // 0x80016254: lw          $t9, 0x24($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X24);
    // 0x80016258: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001625C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80016260: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80016264: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80016268: jalr        $t9
    // 0x8001626C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8001626C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_3:
    // 0x80016270: b           L_800161E0
    // 0x80016274: nop

        goto L_800161E0;
    // 0x80016274: nop

L_80016278:
    // 0x80016278: jal         0x80016CE4
    // 0x8001627C: nop

    LOOKUP_FUNC(0x80016CE4)(rdram, ctx);
        goto after_4;
    // 0x8001627C: nop

    after_4:
    // 0x80016280: beql        $v0, $zero, L_800162C8
    if (ctx->r2 == 0) {
        // 0x80016284: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800162C8;
    }
    goto skip_0;
    // 0x80016284: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80016288: jal         0x80016CE4
    // 0x8001628C: nop

    LOOKUP_FUNC(0x80016CE4)(rdram, ctx);
        goto after_5;
    // 0x8001628C: nop

    after_5:
    // 0x80016290: beq         $v0, $zero, L_800162A0
    if (ctx->r2 == 0) {
        // 0x80016294: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800162A0;
    }
    // 0x80016294: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80016298: b           L_800162A4
    // 0x8001629C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
        goto L_800162A4;
    // 0x8001629C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800162A0:
    // 0x800162A0: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
L_800162A4:
    // 0x800162A4: lw          $t9, 0x24($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X24);
    // 0x800162A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800162AC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800162B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800162B4: jalr        $t9
    // 0x800162B8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x800162B8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_6:
    // 0x800162BC: b           L_800161E0
    // 0x800162C0: nop

        goto L_800161E0;
    // 0x800162C0: nop

    // 0x800162C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800162C8:
    // 0x800162C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800162CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800162D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800162D4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800162D8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800162DC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800162E0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800162E4: jr          $ra
    // 0x800162E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800162E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800162ec(rdram, ctx);
;}
