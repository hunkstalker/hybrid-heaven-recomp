#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801d6000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6000: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6004: sw          $a0, 0x16F0($at)
    MEM_W(0X16F0, ctx->r1) = ctx->r4;
    // 0x801D6008: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D600C: sw          $zero, -0x4764($at)
    MEM_W(-0X4764, ctx->r1) = 0;
    // 0x801D6010: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6014: sw          $zero, -0x4760($at)
    MEM_W(-0X4760, ctx->r1) = 0;
    // 0x801D6018: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D601C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D6020: sw          $t6, -0x4758($at)
    MEM_W(-0X4758, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6024(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6024: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D6028: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D602C: sw          $zero, -0x4780($at)
    MEM_W(-0X4780, ctx->r1) = 0;
    // 0x801D6030: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D6034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D6038: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D603C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6040: addiu       $t7, $t7, 0x606C
    ctx->r15 = ADD32(ctx->r15, 0X606C);
    // 0x801D6044: sw          $zero, -0x477C($at)
    MEM_W(-0X477C, ctx->r1) = 0;
    // 0x801D6048: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D604C: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x801D6050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D6054: jal         0x8013B570
    // 0x801D6058: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D6058: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D605C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D6060: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D6064: jr          $ra
    // 0x801D6068: nop

    return;
    // 0x801D6068: nop

;}
RECOMP_FUNC void M24_FUN_801d606c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D606C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D6070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D6074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D6078: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D607C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D6080: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D6084: beq         $t6, $zero, L_801D60B0
    if (ctx->r14 == 0) {
        // 0x801D6088: nop
    
            goto L_801D60B0;
    }
    // 0x801D6088: nop

    // 0x801D608C: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x801D6090: jal         0x8012D844
    // 0x801D6094: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D6094: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D6098: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D609C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D60A0: jal         0x800058DC
    // 0x801D60A4: addiu       $a1, $a1, 0x60C8
    ctx->r5 = ADD32(ctx->r5, 0X60C8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D60A4: addiu       $a1, $a1, 0x60C8
    ctx->r5 = ADD32(ctx->r5, 0X60C8);
    after_1:
    // 0x801D60A8: b           L_801D60BC
    // 0x801D60AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D60BC;
    // 0x801D60AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D60B0:
    // 0x801D60B0: jal         0x800058DC
    // 0x801D60B4: addiu       $a1, $a1, 0x606C
    ctx->r5 = ADD32(ctx->r5, 0X606C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D60B4: addiu       $a1, $a1, 0x606C
    ctx->r5 = ADD32(ctx->r5, 0X606C);
    after_2:
    // 0x801D60B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D60BC:
    // 0x801D60BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D60C0: jr          $ra
    // 0x801D60C4: nop

    return;
    // 0x801D60C4: nop

;}
RECOMP_FUNC void M24_FUN_801d60c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D60C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D60CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D60D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801D60D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D60D8: jal         0x801CC540
    // 0x801D60DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D60DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D60E0: beq         $v0, $zero, L_801D6100
    if (ctx->r2 == 0) {
        // 0x801D60E4: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D6100;
    }
    // 0x801D60E4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D60E8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D60EC: addiu       $a1, $a1, 0x60C8
    ctx->r5 = ADD32(ctx->r5, 0X60C8);
    // 0x801D60F0: jal         0x800058DC
    // 0x801D60F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D60F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801D60F8: b           L_801D62B0
    // 0x801D60FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801D62B0;
    // 0x801D60FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D6100:
    // 0x801D6100: lw          $t6, -0x4764($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4764);
    // 0x801D6104: beq         $t6, $zero, L_801D6158
    if (ctx->r14 == 0) {
        // 0x801D6108: nop
    
            goto L_801D6158;
    }
    // 0x801D6108: nop

    // 0x801D610C: jal         0x80006214
    // 0x801D6110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D6110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801D6114: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D6118: lw          $t7, -0x4764($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4764);
    // 0x801D611C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D6120: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D6124: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D6128: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D612C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D6130: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D6134: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D6138: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D613C: jal         0x8013A28C
    // 0x801D6140: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D6140: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D6144: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x801D6148: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D614C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6150: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D6154: sw          $zero, -0x4764($at)
    MEM_W(-0X4764, ctx->r1) = 0;
L_801D6158:
    // 0x801D6158: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D615C: lw          $v0, -0x4760($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4760);
    // 0x801D6160: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D6164: beq         $v0, $zero, L_801D6230
    if (ctx->r2 == 0) {
        // 0x801D6168: nop
    
            goto L_801D6230;
    }
    // 0x801D6168: nop

    // 0x801D616C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D6170: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x801D6174: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D6178: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D617C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D6180: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D6184: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D6188: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D618C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D6190: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D6194: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D6198: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D619C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D61A0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D61A4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D61A8: nop

    // 0x801D61AC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D61B0: beql        $t4, $zero, L_801D6200
    if (ctx->r12 == 0) {
        // 0x801D61B4: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D6200;
    }
    goto skip_0;
    // 0x801D61B4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D61B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D61BC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D61C0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D61C4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D61C8: nop

    // 0x801D61CC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D61D0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D61D4: nop

    // 0x801D61D8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D61DC: bne         $t4, $zero, L_801D61F4
    if (ctx->r12 != 0) {
        // 0x801D61E0: nop
    
            goto L_801D61F4;
    }
    // 0x801D61E0: nop

    // 0x801D61E4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D61E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D61EC: b           L_801D620C
    // 0x801D61F0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D620C;
    // 0x801D61F0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D61F4:
    // 0x801D61F4: b           L_801D620C
    // 0x801D61F8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D620C;
    // 0x801D61F8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D61FC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D6200:
    // 0x801D6200: nop

    // 0x801D6204: bltz        $t4, L_801D61F4
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D6208: nop
    
            goto L_801D61F4;
    }
    // 0x801D6208: nop

L_801D620C:
    // 0x801D620C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D6210: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D6214: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D6218: jal         0x80011140
    // 0x801D621C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D621C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D6220: beq         $v0, $zero, L_801D627C
    if (ctx->r2 == 0) {
        // 0x801D6224: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D627C;
    }
    // 0x801D6224: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6228: b           L_801D627C
    // 0x801D622C: sw          $zero, -0x4760($at)
    MEM_W(-0X4760, ctx->r1) = 0;
        goto L_801D627C;
    // 0x801D622C: sw          $zero, -0x4760($at)
    MEM_W(-0X4760, ctx->r1) = 0;
L_801D6230:
    // 0x801D6230: jal         0x80010550
    // 0x801D6234: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D6234: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_5:
    // 0x801D6238: beq         $v0, $zero, L_801D6250
    if (ctx->r2 == 0) {
        // 0x801D623C: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D6250;
    }
    // 0x801D623C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D6240: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D6244: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6248: b           L_801D6258
    // 0x801D624C: sw          $t5, -0x4758($at)
    MEM_W(-0X4758, ctx->r1) = ctx->r13;
        goto L_801D6258;
    // 0x801D624C: sw          $t5, -0x4758($at)
    MEM_W(-0X4758, ctx->r1) = ctx->r13;
L_801D6250:
    // 0x801D6250: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6254: sw          $zero, -0x4758($at)
    MEM_W(-0X4758, ctx->r1) = 0;
L_801D6258:
    // 0x801D6258: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801D625C: addiu       $t7, $t7, -0x3FD8
    ctx->r15 = ADD32(ctx->r15, -0X3FD8);
    // 0x801D6260: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D6264: addiu       $t6, $t6, 0x16F8
    ctx->r14 = ADD32(ctx->r14, 0X16F8);
    // 0x801D6268: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D626C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801D6270: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801D6274: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801D6278: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
L_801D627C:
    // 0x801D627C: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801D6280: lw          $t0, -0x4780($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4780);
    // 0x801D6284: beq         $t0, $zero, L_801D6294
    if (ctx->r8 == 0) {
        // 0x801D6288: nop
    
            goto L_801D6294;
    }
    // 0x801D6288: nop

    // 0x801D628C: jal         0x801D63E0
    // 0x801D6290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801D63E0)(rdram, ctx);
        goto after_6;
    // 0x801D6290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_801D6294:
    // 0x801D6294: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D6298: lw          $t1, -0x477C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X477C);
    // 0x801D629C: beql        $t1, $zero, L_801D62B0
    if (ctx->r9 == 0) {
        // 0x801D62A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801D62B0;
    }
    goto skip_1;
    // 0x801D62A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801D62A4: jal         0x801D6514
    // 0x801D62A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801D6514)(rdram, ctx);
        goto after_7;
    // 0x801D62A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801D62AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D62B0:
    // 0x801D62B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801D62B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D62B8: jr          $ra
    // 0x801D62BC: nop

    return;
    // 0x801D62BC: nop

;}
RECOMP_FUNC void M24_FUN_801d62c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D62C0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D62C4: lw          $v0, -0x4760($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4760);
    // 0x801D62C8: jr          $ra
    // 0x801D62CC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D62CC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d62d0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d62d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D62D0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D62D4: lw          $t6, -0x4760($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4760);
    // 0x801D62D8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D62DC: beq         $t6, $zero, L_801D62EC
    if (ctx->r14 == 0) {
            // 0x801D62E0: nop

    LOOKUP_FUNC(0x801D62EC)(rdram, ctx);
    return;
    }
    // 0x801D62E0: nop

    // 0x801D62E4: jr          $ra
    // 0x801D62E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D62E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d62ec(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d62ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D62EC: lw          $t7, -0x4764($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4764);
    // 0x801D62F0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D62F4: beq         $t7, $zero, L_801D6304
    if (ctx->r15 == 0) {
            // 0x801D62F8: nop

    LOOKUP_FUNC(0x801D6304)(rdram, ctx);
    return;
    }
    // 0x801D62F8: nop

    // 0x801D62FC: jr          $ra
    // 0x801D6300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D6300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6304(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6304: lw          $v0, -0x4758($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4758);
    // 0x801D6308: jr          $ra
    // 0x801D630C: nop

    return;
    // 0x801D630C: nop

;}
RECOMP_FUNC void M24_FUN_801d6310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6310: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D6314: jr          $ra
    // 0x801D6318: addiu       $v0, $v0, 0x16F8
    ctx->r2 = ADD32(ctx->r2, 0X16F8);
    return;
    // 0x801D6318: addiu       $v0, $v0, 0x16F8
    ctx->r2 = ADD32(ctx->r2, 0X16F8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d631c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d631c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D631C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D6320: addiu       $v0, $v0, -0x4780
    ctx->r2 = ADD32(ctx->r2, -0X4780);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6324(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D6328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D632C: beq         $a0, $zero, L_801D6358
    if (ctx->r4 == 0) {
        // 0x801D6330: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D6358;
    }
    // 0x801D6330: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D6334: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6338: jal         0x801C0B2C
    // 0x801D633C: sw          $zero, -0x475C($at)
    MEM_W(-0X475C, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D633C: sw          $zero, -0x475C($at)
    MEM_W(-0X475C, ctx->r1) = 0;
    after_0:
    // 0x801D6340: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6344: sw          $v0, 0x1708($at)
    MEM_W(0X1708, ctx->r1) = ctx->r2;
    // 0x801D6348: sw          $v1, 0x170C($at)
    MEM_W(0X170C, ctx->r1) = ctx->r3;
    // 0x801D634C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6350: b           L_801D636C
    // 0x801D6354: sw          $zero, 0x1710($at)
    MEM_W(0X1710, ctx->r1) = 0;
        goto L_801D636C;
    // 0x801D6354: sw          $zero, 0x1710($at)
    MEM_W(0X1710, ctx->r1) = 0;
L_801D6358:
    // 0x801D6358: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D635C: lw          $a0, 0x16F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16F0);
    // 0x801D6360: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x801D6364: jal         0x8012D844
    // 0x801D6368: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801D6368: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_801D636C:
    // 0x801D636C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D6370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D6374: jr          $ra
    // 0x801D6378: nop

    return;
    // 0x801D6378: nop

;}
RECOMP_FUNC void M24_FUN_801d637c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D637C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D6380: addiu       $v0, $v0, -0x477C
    ctx->r2 = ADD32(ctx->r2, -0X477C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6384(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D6388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D638C: beq         $a0, $zero, L_801D63BC
    if (ctx->r4 == 0) {
        // 0x801D6390: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D63BC;
    }
    // 0x801D6390: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D6394: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801D6398: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D639C: jal         0x801C0B2C
    // 0x801D63A0: sw          $t7, -0x475C($at)
    MEM_W(-0X475C, ctx->r1) = ctx->r15;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D63A0: sw          $t7, -0x475C($at)
    MEM_W(-0X475C, ctx->r1) = ctx->r15;
    after_0:
    // 0x801D63A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D63A8: sw          $v0, 0x1718($at)
    MEM_W(0X1718, ctx->r1) = ctx->r2;
    // 0x801D63AC: sw          $v1, 0x171C($at)
    MEM_W(0X171C, ctx->r1) = ctx->r3;
    // 0x801D63B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D63B4: b           L_801D63D0
    // 0x801D63B8: sw          $zero, 0x1720($at)
    MEM_W(0X1720, ctx->r1) = 0;
        goto L_801D63D0;
    // 0x801D63B8: sw          $zero, 0x1720($at)
    MEM_W(0X1720, ctx->r1) = 0;
L_801D63BC:
    // 0x801D63BC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D63C0: lw          $a0, 0x16F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16F0);
    // 0x801D63C4: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x801D63C8: jal         0x8012D844
    // 0x801D63CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801D63CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_801D63D0:
    // 0x801D63D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D63D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D63D8: jr          $ra
    // 0x801D63DC: nop

    return;
    // 0x801D63DC: nop

;}
RECOMP_FUNC void M24_FUN_801d63e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D63E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D63E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D63E8: jal         0x801C0B2C
    // 0x801D63EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D63EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D63F0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D63F4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D63F8: lw          $t7, 0x170C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X170C);
    // 0x801D63FC: lw          $t6, 0x1708($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1708);
    // 0x801D6400: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D6404: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D6408: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D640C: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D6410: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D6414: jal         0x80034C24
    // 0x801D6418: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D6418: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D641C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6420: ldc1        $f4, -0x2A40($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2A40);
    // 0x801D6424: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D6428: addiu       $a3, $a3, 0x1710
    ctx->r7 = ADD32(ctx->r7, 0X1710);
    // 0x801D642C: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D6430: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D6434: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D6438: addiu       $t1, $t1, -0x4754
    ctx->r9 = ADD32(ctx->r9, -0X4754);
    // 0x801D643C: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D6440: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x801D6444: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801D6448: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D644C: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D6450: nop

    // 0x801D6454: bc1fl       L_801D6508
    if (!c1cs) {
        // 0x801D6458: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D6508;
    }
    goto skip_0;
    // 0x801D6458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D645C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x801D6460: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D6464: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x801D6468: beq         $v1, $zero, L_801D6480
    if (ctx->r3 == 0) {
        // 0x801D646C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801D6480;
    }
    // 0x801D646C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D6470: beq         $v1, $at, L_801D649C
    if (ctx->r3 == ctx->r1) {
        // 0x801D6474: addiu       $a1, $zero, 0x36
        ctx->r5 = ADD32(0, 0X36);
            goto L_801D649C;
    }
    // 0x801D6474: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x801D6478: b           L_801D64BC
    // 0x801D647C: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D64BC;
    // 0x801D647C: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D6480:
    // 0x801D6480: jal         0x8012D844
    // 0x801D6484: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801D6484: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D6488: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D648C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D6490: addiu       $a3, $a3, 0x1710
    ctx->r7 = ADD32(ctx->r7, 0X1710);
    // 0x801D6494: b           L_801D64B8
    // 0x801D6498: lw          $a0, 0x1710($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1710);
        goto L_801D64B8;
    // 0x801D6498: lw          $a0, 0x1710($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1710);
L_801D649C:
    // 0x801D649C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D64A0: jal         0x8012D844
    // 0x801D64A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801D64A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801D64A8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D64AC: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D64B0: addiu       $a3, $a3, 0x1710
    ctx->r7 = ADD32(ctx->r7, 0X1710);
    // 0x801D64B4: lw          $a0, 0x1710($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1710);
L_801D64B8:
    // 0x801D64B8: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D64BC:
    // 0x801D64BC: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x801D64C0: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D64C4: bne         $at, $zero, L_801D64F0
    if (ctx->r1 != 0) {
        // 0x801D64C8: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D64F0;
    }
    // 0x801D64C8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D64CC: jal         0x801C0B2C
    // 0x801D64D0: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_4;
    // 0x801D64D0: nop

    after_4:
    // 0x801D64D4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D64D8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D64DC: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D64E0: addiu       $a3, $a3, 0x1710
    ctx->r7 = ADD32(ctx->r7, 0X1710);
    // 0x801D64E4: lw          $a0, 0x1710($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1710);
    // 0x801D64E8: sw          $v0, 0x1708($at)
    MEM_W(0X1708, ctx->r1) = ctx->r2;
    // 0x801D64EC: sw          $v1, 0x170C($at)
    MEM_W(0X170C, ctx->r1) = ctx->r3;
L_801D64F0:
    // 0x801D64F0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801D64F4: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801D64F8: mfhi        $t3
    ctx->r11 = hi;
    // 0x801D64FC: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D6500: nop

    // 0x801D6504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D6508:
    // 0x801D6508: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D650C: jr          $ra
    // 0x801D6510: nop

    return;
    // 0x801D6510: nop

;}
RECOMP_FUNC void M24_FUN_801d6514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6514: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D6518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D651C: jal         0x801C0B2C
    // 0x801D6520: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D6520: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D6524: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D6528: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D652C: lw          $t7, 0x171C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X171C);
    // 0x801D6530: lw          $t6, 0x1718($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1718);
    // 0x801D6534: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D6538: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D653C: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D6540: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D6544: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D6548: jal         0x80034C24
    // 0x801D654C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D654C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D6550: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6554: ldc1        $f4, -0x2A38($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2A38);
    // 0x801D6558: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D655C: addiu       $a3, $a3, 0x1720
    ctx->r7 = ADD32(ctx->r7, 0X1720);
    // 0x801D6560: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D6564: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D6568: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D656C: addiu       $t1, $t1, -0x46DC
    ctx->r9 = ADD32(ctx->r9, -0X46DC);
    // 0x801D6570: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D6574: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x801D6578: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801D657C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D6580: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D6584: nop

    // 0x801D6588: bc1fl       L_801D663C
    if (!c1cs) {
        // 0x801D658C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D663C;
    }
    goto skip_0;
    // 0x801D658C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D6590: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x801D6594: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D6598: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x801D659C: beq         $v1, $zero, L_801D65B4
    if (ctx->r3 == 0) {
        // 0x801D65A0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801D65B4;
    }
    // 0x801D65A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D65A4: beq         $v1, $at, L_801D65D0
    if (ctx->r3 == ctx->r1) {
        // 0x801D65A8: addiu       $a1, $zero, 0x36
        ctx->r5 = ADD32(0, 0X36);
            goto L_801D65D0;
    }
    // 0x801D65A8: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x801D65AC: b           L_801D65F0
    // 0x801D65B0: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D65F0;
    // 0x801D65B0: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D65B4:
    // 0x801D65B4: jal         0x8012D844
    // 0x801D65B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801D65B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D65BC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D65C0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D65C4: addiu       $a3, $a3, 0x1720
    ctx->r7 = ADD32(ctx->r7, 0X1720);
    // 0x801D65C8: b           L_801D65EC
    // 0x801D65CC: lw          $a0, 0x1720($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1720);
        goto L_801D65EC;
    // 0x801D65CC: lw          $a0, 0x1720($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1720);
L_801D65D0:
    // 0x801D65D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D65D4: jal         0x8012D844
    // 0x801D65D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801D65D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801D65DC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D65E0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D65E4: addiu       $a3, $a3, 0x1720
    ctx->r7 = ADD32(ctx->r7, 0X1720);
    // 0x801D65E8: lw          $a0, 0x1720($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1720);
L_801D65EC:
    // 0x801D65EC: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D65F0:
    // 0x801D65F0: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x801D65F4: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D65F8: bne         $at, $zero, L_801D6624
    if (ctx->r1 != 0) {
        // 0x801D65FC: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D6624;
    }
    // 0x801D65FC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D6600: jal         0x801C0B2C
    // 0x801D6604: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_4;
    // 0x801D6604: nop

    after_4:
    // 0x801D6608: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D660C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D6610: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D6614: addiu       $a3, $a3, 0x1720
    ctx->r7 = ADD32(ctx->r7, 0X1720);
    // 0x801D6618: lw          $a0, 0x1720($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1720);
    // 0x801D661C: sw          $v0, 0x1718($at)
    MEM_W(0X1718, ctx->r1) = ctx->r2;
    // 0x801D6620: sw          $v1, 0x171C($at)
    MEM_W(0X171C, ctx->r1) = ctx->r3;
L_801D6624:
    // 0x801D6624: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801D6628: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801D662C: mfhi        $t3
    ctx->r11 = hi;
    // 0x801D6630: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D6634: nop

    // 0x801D6638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D663C:
    // 0x801D663C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D6640: jr          $ra
    // 0x801D6644: nop

    return;
    // 0x801D6644: nop

;}
RECOMP_FUNC void M24_FUN_801d6648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6648: nop

    // 0x801D664C: nop

;}
RECOMP_FUNC void M24_FUN_801d6650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6650: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6654: sw          $a0, 0x1730($at)
    MEM_W(0X1730, ctx->r1) = ctx->r4;
    // 0x801D6658: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D665C: sw          $zero, -0x4698($at)
    MEM_W(-0X4698, ctx->r1) = 0;
    // 0x801D6660: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6664: sw          $zero, -0x4694($at)
    MEM_W(-0X4694, ctx->r1) = 0;
    // 0x801D6668: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D666C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D6670: sw          $t6, -0x4690($at)
    MEM_W(-0X4690, ctx->r1) = ctx->r14;
    // 0x801D6674: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6678: sw          $zero, -0x468C($at)
    MEM_W(-0X468C, ctx->r1) = 0;
    // 0x801D667C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6680: sw          $zero, -0x4688($at)
    MEM_W(-0X4688, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6684(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6684: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D6688: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D668C: sw          $zero, -0x46B0($at)
    MEM_W(-0X46B0, ctx->r1) = 0;
    // 0x801D6690: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D6694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D6698: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D669C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D66A0: addiu       $t7, $t7, 0x66D0
    ctx->r15 = ADD32(ctx->r15, 0X66D0);
    // 0x801D66A4: sw          $zero, -0x4680($at)
    MEM_W(-0X4680, ctx->r1) = 0;
    // 0x801D66A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D66AC: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x801D66B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D66B4: jal         0x8013B570
    // 0x801D66B8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D66B8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D66BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D66C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801D66C4: sh          $zero, -0x3876($at)
    MEM_H(-0X3876, ctx->r1) = 0;
    // 0x801D66C8: jr          $ra
    // 0x801D66CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801D66CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d66d0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d66d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D66D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D66D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D66D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D66DC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D66E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801D66E4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D66E8: beq         $t6, $zero, L_801D6714
    if (ctx->r14 == 0) {
        // 0x801D66EC: nop
    
            goto L_801D6714;
    }
    // 0x801D66EC: nop

    // 0x801D66F0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801D66F4: jal         0x8012D844
    // 0x801D66F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D66F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D66FC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D6700: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D6704: jal         0x800058DC
    // 0x801D6708: addiu       $a1, $a1, 0x672C
    ctx->r5 = ADD32(ctx->r5, 0X672C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D6708: addiu       $a1, $a1, 0x672C
    ctx->r5 = ADD32(ctx->r5, 0X672C);
    after_1:
    // 0x801D670C: b           L_801D6720
    // 0x801D6710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D6720;
    // 0x801D6710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D6714:
    // 0x801D6714: jal         0x800058DC
    // 0x801D6718: addiu       $a1, $a1, 0x66D0
    ctx->r5 = ADD32(ctx->r5, 0X66D0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D6718: addiu       $a1, $a1, 0x66D0
    ctx->r5 = ADD32(ctx->r5, 0X66D0);
    after_2:
    // 0x801D671C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D6720:
    // 0x801D6720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D6724: jr          $ra
    // 0x801D6728: nop

    return;
    // 0x801D6728: nop

;}
RECOMP_FUNC void M24_FUN_801d672c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D672C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D6730: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D6734: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801D6738: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D673C: jal         0x801CC540
    // 0x801D6740: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D6740: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D6744: beq         $v0, $zero, L_801D6764
    if (ctx->r2 == 0) {
        // 0x801D6748: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D6764;
    }
    // 0x801D6748: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D674C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D6750: addiu       $a1, $a1, 0x672C
    ctx->r5 = ADD32(ctx->r5, 0X672C);
    // 0x801D6754: jal         0x800058DC
    // 0x801D6758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D6758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801D675C: b           L_801D696C
    // 0x801D6760: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801D696C;
    // 0x801D6760: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D6764:
    // 0x801D6764: lw          $t6, -0x4698($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4698);
    // 0x801D6768: beq         $t6, $zero, L_801D67BC
    if (ctx->r14 == 0) {
        // 0x801D676C: nop
    
            goto L_801D67BC;
    }
    // 0x801D676C: nop

    // 0x801D6770: jal         0x80006214
    // 0x801D6774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D6774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801D6778: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D677C: lw          $t7, -0x4698($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4698);
    // 0x801D6780: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D6784: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D6788: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D678C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D6790: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D6794: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D6798: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D679C: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D67A0: jal         0x8013A28C
    // 0x801D67A4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D67A4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D67A8: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x801D67AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D67B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D67B4: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D67B8: sw          $zero, -0x4698($at)
    MEM_W(-0X4698, ctx->r1) = 0;
L_801D67BC:
    // 0x801D67BC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D67C0: lw          $v0, -0x4694($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4694);
    // 0x801D67C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D67C8: beq         $v0, $zero, L_801D6894
    if (ctx->r2 == 0) {
        // 0x801D67CC: nop
    
            goto L_801D6894;
    }
    // 0x801D67CC: nop

    // 0x801D67D0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D67D4: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x801D67D8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D67DC: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D67E0: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D67E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D67E8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D67EC: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D67F0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D67F4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D67F8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D67FC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D6800: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D6804: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D6808: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D680C: nop

    // 0x801D6810: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D6814: beql        $t4, $zero, L_801D6864
    if (ctx->r12 == 0) {
        // 0x801D6818: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D6864;
    }
    goto skip_0;
    // 0x801D6818: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D681C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D6820: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D6824: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D6828: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D682C: nop

    // 0x801D6830: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D6834: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D6838: nop

    // 0x801D683C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D6840: bne         $t4, $zero, L_801D6858
    if (ctx->r12 != 0) {
        // 0x801D6844: nop
    
            goto L_801D6858;
    }
    // 0x801D6844: nop

    // 0x801D6848: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D684C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D6850: b           L_801D6870
    // 0x801D6854: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D6870;
    // 0x801D6854: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D6858:
    // 0x801D6858: b           L_801D6870
    // 0x801D685C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D6870;
    // 0x801D685C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D6860: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D6864:
    // 0x801D6864: nop

    // 0x801D6868: bltz        $t4, L_801D6858
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D686C: nop
    
            goto L_801D6858;
    }
    // 0x801D686C: nop

L_801D6870:
    // 0x801D6870: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D6874: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D6878: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D687C: jal         0x80011140
    // 0x801D6880: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D6880: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D6884: beq         $v0, $zero, L_801D690C
    if (ctx->r2 == 0) {
        // 0x801D6888: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D690C;
    }
    // 0x801D6888: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D688C: b           L_801D690C
    // 0x801D6890: sw          $zero, -0x4694($at)
    MEM_W(-0X4694, ctx->r1) = 0;
        goto L_801D690C;
    // 0x801D6890: sw          $zero, -0x4694($at)
    MEM_W(-0X4694, ctx->r1) = 0;
L_801D6894:
    // 0x801D6894: jal         0x80010550
    // 0x801D6898: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D6898: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_5:
    // 0x801D689C: beq         $v0, $zero, L_801D68B4
    if (ctx->r2 == 0) {
        // 0x801D68A0: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D68B4;
    }
    // 0x801D68A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D68A4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D68A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D68AC: b           L_801D68B8
    // 0x801D68B0: sw          $t5, -0x4690($at)
    MEM_W(-0X4690, ctx->r1) = ctx->r13;
        goto L_801D68B8;
    // 0x801D68B0: sw          $t5, -0x4690($at)
    MEM_W(-0X4690, ctx->r1) = ctx->r13;
L_801D68B4:
    // 0x801D68B4: sw          $zero, -0x4690($at)
    MEM_W(-0X4690, ctx->r1) = 0;
L_801D68B8:
    // 0x801D68B8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x801D68BC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D68C0: addiu       $t6, $t6, 0x1748
    ctx->r14 = ADD32(ctx->r14, 0X1748);
    // 0x801D68C4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D68C8: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D68CC: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D68D0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D68D4: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D68D8: addiu       $t2, $t2, 0x1738
    ctx->r10 = ADD32(ctx->r10, 0X1738);
    // 0x801D68DC: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D68E0: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801D68E4: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D68E8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801D68EC: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D68F0: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801D68F4: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D68F8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D68FC: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D6900: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D6904: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D6908: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801D690C:
    // 0x801D690C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D6910: lw          $t7, -0x468C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X468C);
    // 0x801D6914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D6918: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801D691C: beq         $t7, $zero, L_801D6938
    if (ctx->r15 == 0) {
        // 0x801D6920: nop
    
            goto L_801D6938;
    }
    // 0x801D6920: nop

    // 0x801D6924: jal         0x80129554
    // 0x801D6928: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    LOOKUP_FUNC(0x80129554)(rdram, ctx);
        goto after_6;
    // 0x801D6928: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    after_6:
    // 0x801D692C: beq         $v0, $zero, L_801D6938
    if (ctx->r2 == 0) {
        // 0x801D6930: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D6938;
    }
    // 0x801D6930: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6934: sw          $zero, -0x468C($at)
    MEM_W(-0X468C, ctx->r1) = 0;
L_801D6938:
    // 0x801D6938: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D693C: lw          $t8, -0x4688($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4688);
    // 0x801D6940: beq         $t8, $zero, L_801D6950
    if (ctx->r24 == 0) {
        // 0x801D6944: nop
    
            goto L_801D6950;
    }
    // 0x801D6944: nop

    // 0x801D6948: jal         0x801D6B18
    // 0x801D694C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801D6B18)(rdram, ctx);
        goto after_7;
    // 0x801D694C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_801D6950:
    // 0x801D6950: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D6954: lw          $t6, -0x46B0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X46B0);
    // 0x801D6958: beql        $t6, $zero, L_801D696C
    if (ctx->r14 == 0) {
        // 0x801D695C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801D696C;
    }
    goto skip_1;
    // 0x801D695C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801D6960: jal         0x801D6B48
    // 0x801D6964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801D6B48)(rdram, ctx);
        goto after_8;
    // 0x801D6964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801D6968: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D696C:
    // 0x801D696C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801D6970: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D6974: jr          $ra
    // 0x801D6978: nop

    return;
    // 0x801D6978: nop

;}
RECOMP_FUNC void M24_FUN_801d697c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D697C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D6980: lw          $v0, -0x4694($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4694);
    // 0x801D6984: jr          $ra
    // 0x801D6988: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D6988: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d698c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d698c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D698C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D6990: lw          $t6, -0x4694($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4694);
    // 0x801D6994: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D6998: beq         $t6, $zero, L_801D69A8
    if (ctx->r14 == 0) {
            // 0x801D699C: nop

    LOOKUP_FUNC(0x801D69A8)(rdram, ctx);
    return;
    }
    // 0x801D699C: nop

    // 0x801D69A0: jr          $ra
    // 0x801D69A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D69A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d69a8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d69a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D69A8: lw          $t7, -0x4698($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4698);
    // 0x801D69AC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D69B0: beq         $t7, $zero, L_801D69C0
    if (ctx->r15 == 0) {
            // 0x801D69B4: nop

    LOOKUP_FUNC(0x801D69C0)(rdram, ctx);
    return;
    }
    // 0x801D69B4: nop

    // 0x801D69B8: jr          $ra
    // 0x801D69BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D69BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d69c0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d69c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D69C0: lw          $v0, -0x4690($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4690);
    // 0x801D69C4: jr          $ra
    // 0x801D69C8: nop

    return;
    // 0x801D69C8: nop

;}
RECOMP_FUNC void M24_FUN_801d69cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D69CC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D69D0: jr          $ra
    // 0x801D69D4: addiu       $v0, $v0, 0x1738
    ctx->r2 = ADD32(ctx->r2, 0X1738);
    return;
    // 0x801D69D4: addiu       $v0, $v0, 0x1738
    ctx->r2 = ADD32(ctx->r2, 0X1738);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d69d8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d69d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D69D8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D69DC: addiu       $v1, $v1, 0x1748
    ctx->r3 = ADD32(ctx->r3, 0X1748);
    // 0x801D69E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D69E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D69E8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D69EC: beql        $a0, $t6, L_801D6A00
    if (ctx->r4 == ctx->r14) {
        // 0x801D69F0: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D6A00;
    }
    goto skip_0;
    // 0x801D69F0: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D69F4: jr          $ra
    // 0x801D69F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D69F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D69FC: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D6A00:
    // 0x801D6A00: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D6A04: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D6A08: jr          $ra
    // 0x801D6A0C: nop

    return;
    // 0x801D6A0C: nop

;}
RECOMP_FUNC void M24_FUN_801d6a10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6A10: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6A14: jr          $ra
    // 0x801D6A18: sw          $a0, -0x468C($at)
    MEM_W(-0X468C, ctx->r1) = ctx->r4;
    return;
    // 0x801D6A18: sw          $a0, -0x468C($at)
    MEM_W(-0X468C, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6a1c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6a1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6A1C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D6A20: jr          $ra
    // 0x801D6A24: lw          $v0, -0x468C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X468C);
    return;
    // 0x801D6A24: lw          $v0, -0x468C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X468C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6a28(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6a28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6A28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D6A2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D6A30: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801D6A34: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801D6A38: beq         $a0, $zero, L_801D6A90
    if (ctx->r4 == 0) {
        // 0x801D6A3C: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_801D6A90;
    }
    // 0x801D6A3C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801D6A40: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D6A44: jal         0x80006214
    // 0x801D6A48: lw          $a0, 0x1730($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1730);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D6A48: lw          $a0, 0x1730($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1730);
    after_0:
    // 0x801D6A4C: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x801D6A50: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x801D6A54: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D6A58: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801D6A5C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801D6A60: lw          $a0, 0x1730($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1730);
    // 0x801D6A64: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801D6A68: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801D6A6C: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x801D6A70: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801D6A74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801D6A78: jal         0x801C3370
    // 0x801D6A7C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801C3370)(rdram, ctx);
        goto after_1;
    // 0x801D6A7C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x801D6A80: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801D6A84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6A88: b           L_801D6A98
    // 0x801D6A8C: sw          $t9, -0x4688($at)
    MEM_W(-0X4688, ctx->r1) = ctx->r25;
        goto L_801D6A98;
    // 0x801D6A8C: sw          $t9, -0x4688($at)
    MEM_W(-0X4688, ctx->r1) = ctx->r25;
L_801D6A90:
    // 0x801D6A90: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6A94: sw          $zero, -0x4688($at)
    MEM_W(-0X4688, ctx->r1) = 0;
L_801D6A98:
    // 0x801D6A98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801D6A9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D6AA0: jr          $ra
    // 0x801D6AA4: nop

    return;
    // 0x801D6AA4: nop

;}
RECOMP_FUNC void M24_FUN_801d6aa8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6AA8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D6AAC: lw          $v0, -0x4688($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4688);
    // 0x801D6AB0: jr          $ra
    // 0x801D6AB4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801D6AB4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6ab8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6ab8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6AB8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D6ABC: addiu       $v0, $v0, -0x46B0
    ctx->r2 = ADD32(ctx->r2, -0X46B0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6ac0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6ac0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D6AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D6AC8: beq         $a0, $zero, L_801D6AF4
    if (ctx->r4 == 0) {
        // 0x801D6ACC: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D6AF4;
    }
    // 0x801D6ACC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D6AD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6AD4: jal         0x801C0B2C
    // 0x801D6AD8: sw          $zero, -0x4684($at)
    MEM_W(-0X4684, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D6AD8: sw          $zero, -0x4684($at)
    MEM_W(-0X4684, ctx->r1) = 0;
    after_0:
    // 0x801D6ADC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6AE0: sw          $v0, 0x1758($at)
    MEM_W(0X1758, ctx->r1) = ctx->r2;
    // 0x801D6AE4: sw          $v1, 0x175C($at)
    MEM_W(0X175C, ctx->r1) = ctx->r3;
    // 0x801D6AE8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6AEC: b           L_801D6B08
    // 0x801D6AF0: sw          $zero, 0x1760($at)
    MEM_W(0X1760, ctx->r1) = 0;
        goto L_801D6B08;
    // 0x801D6AF0: sw          $zero, 0x1760($at)
    MEM_W(0X1760, ctx->r1) = 0;
L_801D6AF4:
    // 0x801D6AF4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D6AF8: lw          $a0, 0x1730($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1730);
    // 0x801D6AFC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801D6B00: jal         0x8012D844
    // 0x801D6B04: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801D6B04: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
L_801D6B08:
    // 0x801D6B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D6B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D6B10: jr          $ra
    // 0x801D6B14: nop

    return;
    // 0x801D6B14: nop

;}
RECOMP_FUNC void M24_FUN_801d6b18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6B18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D6B1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D6B20: jal         0x80006214
    // 0x801D6B24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D6B24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D6B28: jal         0x801C354C
    // 0x801D6B2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C354C)(rdram, ctx);
        goto after_1;
    // 0x801D6B2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801D6B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D6B34: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D6B38: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6B3C: sw          $t6, -0x4688($at)
    MEM_W(-0X4688, ctx->r1) = ctx->r14;
    // 0x801D6B40: jr          $ra
    // 0x801D6B44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801D6B44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6b48(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6b48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6B48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D6B4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D6B50: jal         0x801C0B2C
    // 0x801D6B54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D6B54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D6B58: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D6B5C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D6B60: lw          $t7, 0x175C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X175C);
    // 0x801D6B64: lw          $t6, 0x1758($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1758);
    // 0x801D6B68: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D6B6C: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D6B70: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D6B74: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D6B78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D6B7C: jal         0x80034C24
    // 0x801D6B80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D6B80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D6B84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6B88: ldc1        $f4, -0x2A30($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2A30);
    // 0x801D6B8C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D6B90: addiu       $a3, $a3, 0x1760
    ctx->r7 = ADD32(ctx->r7, 0X1760);
    // 0x801D6B94: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D6B98: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D6B9C: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D6BA0: addiu       $t1, $t1, -0x467C
    ctx->r9 = ADD32(ctx->r9, -0X467C);
    // 0x801D6BA4: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D6BA8: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x801D6BAC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801D6BB0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D6BB4: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D6BB8: nop

    // 0x801D6BBC: bc1fl       L_801D6C64
    if (!c1cs) {
        // 0x801D6BC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D6C64;
    }
    goto skip_0;
    // 0x801D6BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D6BC4: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x801D6BC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D6BCC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801D6BD0: beq         $v1, $zero, L_801D6BE8
    if (ctx->r3 == 0) {
        // 0x801D6BD4: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_801D6BE8;
    }
    // 0x801D6BD4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801D6BD8: beq         $v1, $at, L_801D6C04
    if (ctx->r3 == ctx->r1) {
        // 0x801D6BDC: addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
            goto L_801D6C04;
    }
    // 0x801D6BDC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801D6BE0: b           L_801D6C24
    // 0x801D6BE4: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D6C24;
    // 0x801D6BE4: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D6BE8:
    // 0x801D6BE8: jal         0x8012D844
    // 0x801D6BEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801D6BEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D6BF0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D6BF4: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D6BF8: addiu       $a3, $a3, 0x1760
    ctx->r7 = ADD32(ctx->r7, 0X1760);
    // 0x801D6BFC: b           L_801D6C20
    // 0x801D6C00: lw          $a0, 0x1760($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1760);
        goto L_801D6C20;
    // 0x801D6C00: lw          $a0, 0x1760($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1760);
L_801D6C04:
    // 0x801D6C04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D6C08: jal         0x8012D844
    // 0x801D6C0C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801D6C0C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_3:
    // 0x801D6C10: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D6C14: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D6C18: addiu       $a3, $a3, 0x1760
    ctx->r7 = ADD32(ctx->r7, 0X1760);
    // 0x801D6C1C: lw          $a0, 0x1760($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1760);
L_801D6C20:
    // 0x801D6C20: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D6C24:
    // 0x801D6C24: sltiu       $at, $t2, 0x10
    ctx->r1 = ctx->r10 < 0X10 ? 1 : 0;
    // 0x801D6C28: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D6C2C: bne         $at, $zero, L_801D6C58
    if (ctx->r1 != 0) {
        // 0x801D6C30: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D6C58;
    }
    // 0x801D6C30: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D6C34: jal         0x801C0B2C
    // 0x801D6C38: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_4;
    // 0x801D6C38: nop

    after_4:
    // 0x801D6C3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6C40: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D6C44: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D6C48: addiu       $a3, $a3, 0x1760
    ctx->r7 = ADD32(ctx->r7, 0X1760);
    // 0x801D6C4C: lw          $a0, 0x1760($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1760);
    // 0x801D6C50: sw          $v0, 0x1758($at)
    MEM_W(0X1758, ctx->r1) = ctx->r2;
    // 0x801D6C54: sw          $v1, 0x175C($at)
    MEM_W(0X175C, ctx->r1) = ctx->r3;
L_801D6C58:
    // 0x801D6C58: andi        $t3, $a0, 0xF
    ctx->r11 = ctx->r4 & 0XF;
    // 0x801D6C5C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D6C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D6C64:
    // 0x801D6C64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D6C68: jr          $ra
    // 0x801D6C6C: nop

    return;
    // 0x801D6C6C: nop

;}
RECOMP_FUNC void M24_FUN_801d6c70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6C70: nop

    // 0x801D6C74: nop

    // 0x801D6C78: nop

    // 0x801D6C7C: nop

;}
RECOMP_FUNC void M24_FUN_801d6c80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6C80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801D6C84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6C88: sw          $a0, 0x1770($at)
    MEM_W(0X1770, ctx->r1) = ctx->r4;
    // 0x801D6C8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6C90: sw          $zero, -0x45DC($at)
    MEM_W(-0X45DC, ctx->r1) = 0;
    // 0x801D6C94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6C98: sw          $zero, -0x45D8($at)
    MEM_W(-0X45D8, ctx->r1) = 0;
    // 0x801D6C9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6CA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D6CA4: sw          $t6, -0x45D4($at)
    MEM_W(-0X45D4, ctx->r1) = ctx->r14;
    // 0x801D6CA8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801D6CAC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801D6CB0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6CB4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801D6CB8: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x801D6CBC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801D6CC0: addiu       $t0, $zero, 0x140
    ctx->r8 = ADD32(0, 0X140);
    // 0x801D6CC4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801D6CC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801D6CCC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801D6CD0: sw          $zero, 0x1774($at)
    MEM_W(0X1774, ctx->r1) = 0;
    // 0x801D6CD4: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801D6CD8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801D6CDC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801D6CE0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801D6CE4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801D6CE8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801D6CEC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D6CF0: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D6CF4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801D6CF8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801D6CFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D6D00: jal         0x801CC654
    // 0x801D6D04: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    LOOKUP_FUNC(0x801CC654)(rdram, ctx);
        goto after_0;
    // 0x801D6D04: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_0:
    // 0x801D6D08: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801D6D0C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6D10: addiu       $t4, $t4, 0x6D40
    ctx->r12 = ADD32(ctx->r12, 0X6D40);
    // 0x801D6D14: sw          $v0, -0x45CC($at)
    MEM_W(-0X45CC, ctx->r1) = ctx->r2;
    // 0x801D6D18: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801D6D1C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801D6D20: addiu       $a1, $zero, 0x142
    ctx->r5 = ADD32(0, 0X142);
    // 0x801D6D24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D6D28: jal         0x8013B570
    // 0x801D6D2C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_1;
    // 0x801D6D2C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x801D6D30: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801D6D34: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801D6D38: jr          $ra
    // 0x801D6D3C: nop

    return;
    // 0x801D6D3C: nop

;}
RECOMP_FUNC void M24_FUN_801d6d40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6D40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D6D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D6D48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D6D4C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D6D50: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D6D54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D6D58: beql        $t6, $zero, L_801D6D8C
    if (ctx->r14 == 0) {
        // 0x801D6D5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D6D8C;
    }
    goto skip_0;
    // 0x801D6D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D6D60: jal         0x8012D844
    // 0x801D6D64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D6D64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D6D68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D6D6C: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D6D70: jal         0x8012D894
    // 0x801D6D74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_1;
    // 0x801D6D74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x801D6D78: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D6D7C: addiu       $a1, $a1, 0x6D98
    ctx->r5 = ADD32(ctx->r5, 0X6D98);
    // 0x801D6D80: jal         0x800058DC
    // 0x801D6D84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D6D84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801D6D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D6D8C:
    // 0x801D6D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D6D90: jr          $ra
    // 0x801D6D94: nop

    return;
    // 0x801D6D94: nop

;}
RECOMP_FUNC void M24_FUN_801d6d98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6D98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D6D9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D6DA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801D6DA4: jal         0x801CC540
    // 0x801D6DA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D6DA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D6DAC: beq         $v0, $zero, L_801D6DCC
    if (ctx->r2 == 0) {
        // 0x801D6DB0: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D6DCC;
    }
    // 0x801D6DB0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D6DB4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D6DB8: addiu       $a1, $a1, 0x6D98
    ctx->r5 = ADD32(ctx->r5, 0X6D98);
    // 0x801D6DBC: jal         0x800058DC
    // 0x801D6DC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D6DC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801D6DC4: b           L_801D6FA4
    // 0x801D6DC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D6FA4;
    // 0x801D6DC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D6DCC:
    // 0x801D6DCC: lw          $t6, -0x45DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X45DC);
    // 0x801D6DD0: beq         $t6, $zero, L_801D6E28
    if (ctx->r14 == 0) {
        // 0x801D6DD4: nop
    
            goto L_801D6E28;
    }
    // 0x801D6DD4: nop

    // 0x801D6DD8: jal         0x80006214
    // 0x801D6DDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D6DDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D6DE0: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D6DE4: lw          $t7, -0x45DC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X45DC);
    // 0x801D6DE8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D6DEC: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D6DF0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D6DF4: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D6DF8: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D6DFC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D6E00: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D6E04: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D6E08: jal         0x8013A28C
    // 0x801D6E0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D6E0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D6E10: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D6E14: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D6E18: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6E1C: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x801D6E20: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D6E24: sw          $zero, -0x45DC($at)
    MEM_W(-0X45DC, ctx->r1) = 0;
L_801D6E28:
    // 0x801D6E28: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D6E2C: lw          $v0, -0x45D8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X45D8);
    // 0x801D6E30: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801D6E34: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D6E38: beq         $v0, $zero, L_801D6F04
    if (ctx->r2 == 0) {
        // 0x801D6E3C: nop
    
            goto L_801D6F04;
    }
    // 0x801D6E3C: nop

    // 0x801D6E40: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D6E44: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    // 0x801D6E48: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D6E4C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D6E50: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D6E54: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D6E58: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D6E5C: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D6E60: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D6E64: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D6E68: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D6E6C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D6E70: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D6E74: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D6E78: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D6E7C: nop

    // 0x801D6E80: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D6E84: beql        $t4, $zero, L_801D6ED4
    if (ctx->r12 == 0) {
        // 0x801D6E88: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D6ED4;
    }
    goto skip_0;
    // 0x801D6E88: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D6E8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D6E90: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D6E94: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D6E98: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D6E9C: nop

    // 0x801D6EA0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D6EA4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D6EA8: nop

    // 0x801D6EAC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D6EB0: bne         $t4, $zero, L_801D6EC8
    if (ctx->r12 != 0) {
        // 0x801D6EB4: nop
    
            goto L_801D6EC8;
    }
    // 0x801D6EB4: nop

    // 0x801D6EB8: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D6EBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D6EC0: b           L_801D6EE0
    // 0x801D6EC4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D6EE0;
    // 0x801D6EC4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D6EC8:
    // 0x801D6EC8: b           L_801D6EE0
    // 0x801D6ECC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D6EE0;
    // 0x801D6ECC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D6ED0: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D6ED4:
    // 0x801D6ED4: nop

    // 0x801D6ED8: bltz        $t4, L_801D6EC8
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D6EDC: nop
    
            goto L_801D6EC8;
    }
    // 0x801D6EDC: nop

L_801D6EE0:
    // 0x801D6EE0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D6EE4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D6EE8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D6EEC: jal         0x80011140
    // 0x801D6EF0: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D6EF0: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D6EF4: beq         $v0, $zero, L_801D6F7C
    if (ctx->r2 == 0) {
        // 0x801D6EF8: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D6F7C;
    }
    // 0x801D6EF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6EFC: b           L_801D6F7C
    // 0x801D6F00: sw          $zero, -0x45D8($at)
    MEM_W(-0X45D8, ctx->r1) = 0;
        goto L_801D6F7C;
    // 0x801D6F00: sw          $zero, -0x45D8($at)
    MEM_W(-0X45D8, ctx->r1) = 0;
L_801D6F04:
    // 0x801D6F04: jal         0x80010550
    // 0x801D6F08: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D6F08: lw          $a1, 0x5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X5C);
    after_5:
    // 0x801D6F0C: beq         $v0, $zero, L_801D6F24
    if (ctx->r2 == 0) {
        // 0x801D6F10: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D6F24;
    }
    // 0x801D6F10: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6F14: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D6F18: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D6F1C: b           L_801D6F28
    // 0x801D6F20: sw          $t5, -0x45D4($at)
    MEM_W(-0X45D4, ctx->r1) = ctx->r13;
        goto L_801D6F28;
    // 0x801D6F20: sw          $t5, -0x45D4($at)
    MEM_W(-0X45D4, ctx->r1) = ctx->r13;
L_801D6F24:
    // 0x801D6F24: sw          $zero, -0x45D4($at)
    MEM_W(-0X45D4, ctx->r1) = 0;
L_801D6F28:
    // 0x801D6F28: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801D6F2C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D6F30: addiu       $t6, $t6, 0x1788
    ctx->r14 = ADD32(ctx->r14, 0X1788);
    // 0x801D6F34: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D6F38: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D6F3C: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D6F40: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D6F44: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D6F48: addiu       $t2, $t2, 0x1778
    ctx->r10 = ADD32(ctx->r10, 0X1778);
    // 0x801D6F4C: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D6F50: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801D6F54: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D6F58: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801D6F5C: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D6F60: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x801D6F64: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D6F68: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D6F6C: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D6F70: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D6F74: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D6F78: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_801D6F7C:
    // 0x801D6F7C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D6F80: lw          $t7, 0x1774($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1774);
    // 0x801D6F84: beq         $t7, $zero, L_801D6F94
    if (ctx->r15 == 0) {
        // 0x801D6F88: nop
    
            goto L_801D6F94;
    }
    // 0x801D6F88: nop

    // 0x801D6F8C: jal         0x801D70FC
    // 0x801D6F90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x801D70FC)(rdram, ctx);
        goto after_6;
    // 0x801D6F90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
L_801D6F94:
    // 0x801D6F94: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D6F98: jal         0x801CC6F4
    // 0x801D6F9C: lw          $a0, -0x45CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X45CC);
    LOOKUP_FUNC(0x801CC6F4)(rdram, ctx);
        goto after_7;
    // 0x801D6F9C: lw          $a0, -0x45CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X45CC);
    after_7:
    // 0x801D6FA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D6FA4:
    // 0x801D6FA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D6FA8: jr          $ra
    // 0x801D6FAC: nop

    return;
    // 0x801D6FAC: nop

;}
RECOMP_FUNC void M24_FUN_801d6fb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6FB0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D6FB4: lw          $v0, -0x45D8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X45D8);
    // 0x801D6FB8: jr          $ra
    // 0x801D6FBC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D6FBC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6fc0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6fc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6FC0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D6FC4: lw          $t6, -0x45D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X45D8);
    // 0x801D6FC8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D6FCC: beq         $t6, $zero, L_801D6FDC
    if (ctx->r14 == 0) {
            // 0x801D6FD0: nop

    LOOKUP_FUNC(0x801D6FDC)(rdram, ctx);
    return;
    }
    // 0x801D6FD0: nop

    // 0x801D6FD4: jr          $ra
    // 0x801D6FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D6FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6fdc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6fdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6FDC: lw          $t7, -0x45DC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X45DC);
    // 0x801D6FE0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D6FE4: beq         $t7, $zero, L_801D6FF4
    if (ctx->r15 == 0) {
            // 0x801D6FE8: nop

    LOOKUP_FUNC(0x801D6FF4)(rdram, ctx);
    return;
    }
    // 0x801D6FE8: nop

    // 0x801D6FEC: jr          $ra
    // 0x801D6FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D6FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d6ff4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d6ff4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6FF4: lw          $v0, -0x45D4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X45D4);
    // 0x801D6FF8: jr          $ra
    // 0x801D6FFC: nop

    return;
    // 0x801D6FFC: nop

;}
RECOMP_FUNC void M24_FUN_801d7000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7000: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D7004: jr          $ra
    // 0x801D7008: addiu       $v0, $v0, 0x1778
    ctx->r2 = ADD32(ctx->r2, 0X1778);
    return;
    // 0x801D7008: addiu       $v0, $v0, 0x1778
    ctx->r2 = ADD32(ctx->r2, 0X1778);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d700c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d700c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D700C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D7010: addiu       $v1, $v1, 0x1788
    ctx->r3 = ADD32(ctx->r3, 0X1788);
    // 0x801D7014: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D7018: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D701C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D7020: beql        $a0, $t6, L_801D7034
    if (ctx->r4 == ctx->r14) {
        // 0x801D7024: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D7034;
    }
    goto skip_0;
    // 0x801D7024: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D7028: jr          $ra
    // 0x801D702C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D702C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D7030: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D7034:
    // 0x801D7034: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D7038: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D703C: jr          $ra
    // 0x801D7040: nop

    return;
    // 0x801D7040: nop

;}
RECOMP_FUNC void M24_FUN_801d7044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7044: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D7048: addiu       $v0, $v0, 0x1774
    ctx->r2 = ADD32(ctx->r2, 0X1774);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d704c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d704c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D704C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7054: beq         $a0, $zero, L_801D7080
    if (ctx->r4 == 0) {
        // 0x801D7058: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D7080;
    }
    // 0x801D7058: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D705C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7060: jal         0x801C0B2C
    // 0x801D7064: sw          $zero, -0x45D0($at)
    MEM_W(-0X45D0, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D7064: sw          $zero, -0x45D0($at)
    MEM_W(-0X45D0, ctx->r1) = 0;
    after_0:
    // 0x801D7068: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D706C: sw          $v0, 0x1798($at)
    MEM_W(0X1798, ctx->r1) = ctx->r2;
    // 0x801D7070: sw          $v1, 0x179C($at)
    MEM_W(0X179C, ctx->r1) = ctx->r3;
    // 0x801D7074: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7078: b           L_801D7094
    // 0x801D707C: sw          $zero, 0x17A0($at)
    MEM_W(0X17A0, ctx->r1) = 0;
        goto L_801D7094;
    // 0x801D707C: sw          $zero, 0x17A0($at)
    MEM_W(0X17A0, ctx->r1) = 0;
L_801D7080:
    // 0x801D7080: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D7084: lw          $a0, 0x1770($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1770);
    // 0x801D7088: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D708C: jal         0x8012D894
    // 0x801D7090: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_1;
    // 0x801D7090: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
L_801D7094:
    // 0x801D7094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D7098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D709C: jr          $ra
    // 0x801D70A0: nop

    return;
    // 0x801D70A0: nop

;}
RECOMP_FUNC void M24_FUN_801d70a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D70A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D70A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D70AC: beq         $a0, $zero, L_801D70DC
    if (ctx->r4 == 0) {
        // 0x801D70B0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801D70DC;
    }
    // 0x801D70B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D70B4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D70B8: lw          $a0, 0x1770($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1770);
    // 0x801D70BC: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D70C0: jal         0x8012D844
    // 0x801D70C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D70C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x801D70C8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D70CC: lw          $a0, 0x1770($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1770);
    // 0x801D70D0: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D70D4: jal         0x8012D894
    // 0x801D70D8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_1;
    // 0x801D70D8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
L_801D70DC:
    // 0x801D70DC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D70E0: lw          $a0, -0x45CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X45CC);
    // 0x801D70E4: jal         0x801CC948
    // 0x801D70E8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801CC948)(rdram, ctx);
        goto after_2;
    // 0x801D70E8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801D70EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D70F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D70F4: jr          $ra
    // 0x801D70F8: nop

    return;
    // 0x801D70F8: nop

;}
RECOMP_FUNC void M24_FUN_801d70fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D70FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D7100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7104: jal         0x801C0B2C
    // 0x801D7108: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D7108: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D710C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D7110: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D7114: lw          $t7, 0x179C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X179C);
    // 0x801D7118: lw          $t6, 0x1798($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1798);
    // 0x801D711C: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D7120: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D7124: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D7128: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D712C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7130: jal         0x80034C24
    // 0x801D7134: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D7134: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D7138: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D713C: ldc1        $f4, -0x2A20($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2A20);
    // 0x801D7140: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D7144: addiu       $a3, $a3, 0x17A0
    ctx->r7 = ADD32(ctx->r7, 0X17A0);
    // 0x801D7148: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D714C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D7150: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D7154: addiu       $t1, $t1, -0x45C8
    ctx->r9 = ADD32(ctx->r9, -0X45C8);
    // 0x801D7158: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D715C: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801D7160: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D7164: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D7168: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D716C: nop

    // 0x801D7170: bc1fl       L_801D7244
    if (!c1cs) {
        // 0x801D7174: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D7244;
    }
    goto skip_0;
    // 0x801D7174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D7178: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801D717C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7180: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D7184: beq         $v0, $zero, L_801D71A8
    if (ctx->r2 == 0) {
        // 0x801D7188: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_801D71A8;
    }
    // 0x801D7188: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801D718C: beq         $v0, $at, L_801D71C4
    if (ctx->r2 == ctx->r1) {
        // 0x801D7190: addiu       $a1, $zero, 0x140
        ctx->r5 = ADD32(0, 0X140);
            goto L_801D71C4;
    }
    // 0x801D7190: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D7194: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D7198: beq         $v0, $at, L_801D71E4
    if (ctx->r2 == ctx->r1) {
        // 0x801D719C: addiu       $a1, $zero, 0x140
        ctx->r5 = ADD32(0, 0X140);
            goto L_801D71E4;
    }
    // 0x801D719C: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x801D71A0: b           L_801D7204
    // 0x801D71A4: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D7204;
    // 0x801D71A4: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D71A8:
    // 0x801D71A8: jal         0x8012D894
    // 0x801D71AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_2;
    // 0x801D71AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D71B0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D71B4: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D71B8: addiu       $a3, $a3, 0x17A0
    ctx->r7 = ADD32(ctx->r7, 0X17A0);
    // 0x801D71BC: b           L_801D7200
    // 0x801D71C0: lw          $a0, 0x17A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17A0);
        goto L_801D7200;
    // 0x801D71C0: lw          $a0, 0x17A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17A0);
L_801D71C4:
    // 0x801D71C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D71C8: jal         0x8012D894
    // 0x801D71CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_3;
    // 0x801D71CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x801D71D0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D71D4: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D71D8: addiu       $a3, $a3, 0x17A0
    ctx->r7 = ADD32(ctx->r7, 0X17A0);
    // 0x801D71DC: b           L_801D7200
    // 0x801D71E0: lw          $a0, 0x17A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17A0);
        goto L_801D7200;
    // 0x801D71E0: lw          $a0, 0x17A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17A0);
L_801D71E4:
    // 0x801D71E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D71E8: jal         0x8012D894
    // 0x801D71EC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x8012D894)(rdram, ctx);
        goto after_4;
    // 0x801D71EC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_4:
    // 0x801D71F0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D71F4: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D71F8: addiu       $a3, $a3, 0x17A0
    ctx->r7 = ADD32(ctx->r7, 0X17A0);
    // 0x801D71FC: lw          $a0, 0x17A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17A0);
L_801D7200:
    // 0x801D7200: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D7204:
    // 0x801D7204: sltiu       $at, $t2, 0x10
    ctx->r1 = ctx->r10 < 0X10 ? 1 : 0;
    // 0x801D7208: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D720C: bne         $at, $zero, L_801D7238
    if (ctx->r1 != 0) {
        // 0x801D7210: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D7238;
    }
    // 0x801D7210: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D7214: jal         0x801C0B2C
    // 0x801D7218: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801D7218: nop

    after_5:
    // 0x801D721C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7220: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D7224: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D7228: addiu       $a3, $a3, 0x17A0
    ctx->r7 = ADD32(ctx->r7, 0X17A0);
    // 0x801D722C: lw          $a0, 0x17A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X17A0);
    // 0x801D7230: sw          $v0, 0x1798($at)
    MEM_W(0X1798, ctx->r1) = ctx->r2;
    // 0x801D7234: sw          $v1, 0x179C($at)
    MEM_W(0X179C, ctx->r1) = ctx->r3;
L_801D7238:
    // 0x801D7238: andi        $t3, $a0, 0xF
    ctx->r11 = ctx->r4 & 0XF;
    // 0x801D723C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D7240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7244:
    // 0x801D7244: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D7248: jr          $ra
    // 0x801D724C: nop

    return;
    // 0x801D724C: nop

;}
RECOMP_FUNC void M24_FUN_801d7250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7250: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7254: sw          $a0, 0x17B0($at)
    MEM_W(0X17B0, ctx->r1) = ctx->r4;
    // 0x801D7258: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D725C: sw          $zero, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = 0;
    // 0x801D7260: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7264: sw          $zero, -0x4528($at)
    MEM_W(-0X4528, ctx->r1) = 0;
    // 0x801D7268: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D726C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D7270: sw          $t6, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = ctx->r14;
    // 0x801D7274: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7278: sw          $zero, -0x4520($at)
    MEM_W(-0X4520, ctx->r1) = 0;
    // 0x801D727C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D7280: sw          $zero, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d7284(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d7284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7284: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D7288: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D728C: sw          $zero, -0x4518($at)
    MEM_W(-0X4518, ctx->r1) = 0;
    // 0x801D7290: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D7294: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D7298: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D729C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D72A0: addiu       $t7, $t7, 0x72CC
    ctx->r15 = ADD32(ctx->r15, 0X72CC);
    // 0x801D72A4: sw          $zero, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = 0;
    // 0x801D72A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D72AC: addiu       $a1, $zero, 0x11D
    ctx->r5 = ADD32(0, 0X11D);
    // 0x801D72B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D72B4: jal         0x8013B570
    // 0x801D72B8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D72B8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D72BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D72C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D72C4: jr          $ra
    // 0x801D72C8: nop

    return;
    // 0x801D72C8: nop

;}
