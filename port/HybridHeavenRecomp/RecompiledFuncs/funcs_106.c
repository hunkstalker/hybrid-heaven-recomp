#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M55_FUN_8037879c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037879C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803787a0(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803787a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803787A0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x803787A4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x803787A8: jr          $ra
    // 0x803787AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x803787AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803787b0(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803787b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803787B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803787B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x803787B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803787BC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x803787C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x803787C4: jal         0x8014C0A8
    // 0x803787C8: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    LOOKUP_FUNC(0x8014C0A8)(rdram, ctx);
        goto after_0;
    // 0x803787C8: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    after_0:
    // 0x803787CC: bne         $v0, $zero, L_803787E0
    if (ctx->r2 != 0) {
        // 0x803787D0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_803787E0;
    }
    // 0x803787D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x803787D4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x803787D8: jal         0x800058DC
    // 0x803787DC: addiu       $a1, $a1, -0x76F4
    ctx->r5 = ADD32(ctx->r5, -0X76F4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x803787DC: addiu       $a1, $a1, -0x76F4
    ctx->r5 = ADD32(ctx->r5, -0X76F4);
    after_1:
L_803787E0:
    // 0x803787E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803787E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803787E8: jr          $ra
    // 0x803787EC: nop

    return;
    // 0x803787EC: nop

;}
RECOMP_FUNC void M55_FUN_803787f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803787F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x803787F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803787F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x803787FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80378800: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80378804: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x80378808: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x8037880C: ori         $at, $at, 0x3C
    ctx->r1 = ctx->r1 | 0X3C;
    // 0x80378810: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x80378814: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80378818: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    // 0x8037881C: beq         $t7, $at, L_80378838
    if (ctx->r15 == ctx->r1) {
        // 0x80378820: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80378838;
    }
    // 0x80378820: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80378824: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80378828: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x8037882C: ori         $at, $at, 0x2D
    ctx->r1 = ctx->r1 | 0X2D;
    // 0x80378830: bne         $t8, $at, L_80378850
    if (ctx->r24 != ctx->r1) {
        // 0x80378834: lui         $t9, 0x8039
        ctx->r25 = S32(0X8039 << 16);
            goto L_80378850;
    }
    // 0x80378834: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
L_80378838:
    // 0x80378838: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    // 0x8037883C: jal         0x80010550
    // 0x80378840: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x80378840: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x80378844: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80378848: b           L_80378890
    // 0x8037884C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
        goto L_80378890;
    // 0x8037884C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
L_80378850:
    // 0x80378850: lw          $t9, -0x56FC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X56FC);
    // 0x80378854: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80378858: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8037885C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80378860: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80378864: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x80378868: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x8037886C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80378870: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80378874: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80378878: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8037887C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80378880: jal         0x80011140
    // 0x80378884: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_1;
    // 0x80378884: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_1:
    // 0x80378888: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8037888C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80378890:
    // 0x80378890: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80378894: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x80378898: ori         $at, $at, 0x3C
    ctx->r1 = ctx->r1 | 0X3C;
    // 0x8037889C: beq         $v0, $at, L_803788B0
    if (ctx->r2 == ctx->r1) {
        // 0x803788A0: lui         $at, 0x168
        ctx->r1 = S32(0X168 << 16);
            goto L_803788B0;
    }
    // 0x803788A0: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x803788A4: ori         $at, $at, 0x2D
    ctx->r1 = ctx->r1 | 0X2D;
    // 0x803788A8: bnel        $v0, $at, L_803788FC
    if (ctx->r2 != ctx->r1) {
        // 0x803788AC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_803788FC;
    }
    goto skip_0;
    // 0x803788AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_803788B0:
    // 0x803788B0: beq         $a0, $zero, L_803788F8
    if (ctx->r4 == 0) {
        // 0x803788B4: lui         $s0, 0x801C
        ctx->r16 = S32(0X801C << 16);
            goto L_803788F8;
    }
    // 0x803788B4: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x803788B8: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x803788BC: jal         0x8014C068
    // 0x803788C0: lhu         $a0, 0x244($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X244);
    LOOKUP_FUNC(0x8014C068)(rdram, ctx);
        goto after_2;
    // 0x803788C0: lhu         $a0, 0x244($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X244);
    after_2:
    // 0x803788C4: beq         $v0, $zero, L_803788EC
    if (ctx->r2 == 0) {
        // 0x803788C8: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_803788EC;
    }
    // 0x803788C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x803788CC: jal         0x8014C138
    // 0x803788D0: lhu         $a0, 0x244($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X244);
    LOOKUP_FUNC(0x8014C138)(rdram, ctx);
        goto after_3;
    // 0x803788D0: lhu         $a0, 0x244($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X244);
    after_3:
    // 0x803788D4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x803788D8: addiu       $a1, $a1, -0x7850
    ctx->r5 = ADD32(ctx->r5, -0X7850);
    // 0x803788DC: jal         0x800058DC
    // 0x803788E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x803788E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x803788E4: b           L_803788FC
    // 0x803788E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_803788FC;
    // 0x803788E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_803788EC:
    // 0x803788EC: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x803788F0: jal         0x800058DC
    // 0x803788F4: addiu       $a1, $a1, -0x76F4
    ctx->r5 = ADD32(ctx->r5, -0X76F4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x803788F4: addiu       $a1, $a1, -0x76F4
    ctx->r5 = ADD32(ctx->r5, -0X76F4);
    after_5:
L_803788F8:
    // 0x803788F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_803788FC:
    // 0x803788FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80378900: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80378904: jr          $ra
    // 0x80378908: nop

    return;
    // 0x80378908: nop

;}
RECOMP_FUNC void M55_FUN_8037890c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037890C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80378910: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80378914: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80378918: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037891C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80378920: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80378924: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x80378928: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8037892C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80378930: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80378934: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    // 0x80378938: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x8037893C: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x80378940: jal         0x8014B3F0
    // 0x80378944: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8014B3F0)(rdram, ctx);
        goto after_0;
    // 0x80378944: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80378948: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8037894C: sb          $v0, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r2;
    // 0x80378950: addiu       $a1, $a1, -0x7698
    ctx->r5 = ADD32(ctx->r5, -0X7698);
    // 0x80378954: jal         0x80005670
    // 0x80378958: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x80378958: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_1:
    // 0x8037895C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378960: sw          $v0, -0x56F4($at)
    MEM_W(-0X56F4, ctx->r1) = ctx->r2;
    // 0x80378964: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378968: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8037896C: sb          $zero, -0x7650($at)
    MEM_B(-0X7650, ctx->r1) = 0;
    // 0x80378970: jal         0x8014C068
    // 0x80378974: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    LOOKUP_FUNC(0x8014C068)(rdram, ctx);
        goto after_2;
    // 0x80378974: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    after_2:
    // 0x80378978: beq         $v0, $zero, L_80378BB0
    if (ctx->r2 == 0) {
            // 0x8037897C: lbu         $a0, 0x67($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X67);
    LOOKUP_FUNC(0x80378BB0)(rdram, ctx);
    return;
    }
    // 0x8037897C: lbu         $a0, 0x67($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X67);
    // 0x80378980: lbu         $a1, 0x67($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X67);
    // 0x80378984: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80378988: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x8037898C: beq         $a1, $zero, L_80378B90
    if (ctx->r5 == 0) {
            // 0x80378990: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    LOOKUP_FUNC(0x80378B90)(rdram, ctx);
    return;
    }
    // 0x80378990: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80378994: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80378998: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8037899C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x803789A0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x803789A4: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    // 0x803789A8: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    // 0x803789AC: jal         0x801494A4
    // 0x803789B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801494A4)(rdram, ctx);
        goto after_3;
    // 0x803789B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x803789B4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803789B8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x803789BC: sw          $v0, -0x5700($at)
    MEM_W(-0X5700, ctx->r1) = ctx->r2;
    // 0x803789C0: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    // 0x803789C4: jal         0x8014B4A0
    // 0x803789C8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    LOOKUP_FUNC(0x8014B4A0)(rdram, ctx);
        goto after_4;
    // 0x803789C8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x803789CC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x803789D0: jal         0x8014C1F0
    // 0x803789D4: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    LOOKUP_FUNC(0x8014C1F0)(rdram, ctx);
        goto after_5;
    // 0x803789D4: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    after_5:
    // 0x803789D8: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x803789DC: bne         $t0, $zero, L_80378A28
    if (ctx->r8 != 0) {
        // 0x803789E0: lui         $t4, 0x801C
        ctx->r12 = S32(0X801C << 16);
            goto L_80378A28;
    }
    // 0x803789E0: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x803789E4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x803789E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x803789EC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x803789F0: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x803789F4: lw          $t1, -0x4328($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4328);
    // 0x803789F8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x803789FC: addiu       $t2, $sp, 0x58
    ctx->r10 = ADD32(ctx->r29, 0X58);
    // 0x80378A00: addiu       $t3, $sp, 0x54
    ctx->r11 = ADD32(ctx->r29, 0X54);
    // 0x80378A04: lw          $a0, 0x2C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X2C);
    // 0x80378A08: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80378A0C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80378A10: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80378A14: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80378A18: jal         0x80130E34
    // 0x80378A1C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x80130E34)(rdram, ctx);
        goto after_6;
    // 0x80378A1C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_6:
    // 0x80378A20: b           L_80378A64
    // 0x80378A24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_80378A64;
    // 0x80378A24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80378A28:
    // 0x80378A28: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80378A2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80378A30: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80378A34: lw          $t4, -0x4328($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4328);
    // 0x80378A38: addiu       $t5, $sp, 0x58
    ctx->r13 = ADD32(ctx->r29, 0X58);
    // 0x80378A3C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80378A40: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x80378A44: lw          $a0, 0x2C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X2C);
    // 0x80378A48: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80378A4C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80378A50: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80378A54: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80378A58: jal         0x80130E34
    // 0x80378A5C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x80130E34)(rdram, ctx);
        goto after_7;
    // 0x80378A5C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_7:
    // 0x80378A60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80378A64:
    // 0x80378A64: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80378A68: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80378A6C: addiu       $v1, $v1, -0x5700
    ctx->r3 = ADD32(ctx->r3, -0X5700);
    // 0x80378A70: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80378A74: nop

    // 0x80378A78: bc1fl       L_80378A88
    if (!c1cs) {
        // 0x80378A7C: lwc1        $f16, 0x54($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
            goto L_80378A88;
    }
    goto skip_0;
    // 0x80378A7C: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x80378A80: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80378A84: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
L_80378A88:
    // 0x80378A88: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80378A8C: nop

    // 0x80378A90: bc1fl       L_80378AA0
    if (!c1cs) {
        // 0x80378A94: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_80378AA0;
    }
    goto skip_1;
    // 0x80378A94: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x80378A98: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80378A9C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_80378AA0:
    // 0x80378AA0: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80378AA4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378AA8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80378AAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80378AB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80378AB4: swc1        $f18, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f18.u32l;
    // 0x80378AB8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80378ABC: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80378AC0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80378AC4: swc1        $f4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f4.u32l;
    // 0x80378AC8: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80378ACC: lwc1        $f6, -0x6B04($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6B04);
    // 0x80378AD0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80378AD4: swc1        $f6, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f6.u32l;
    // 0x80378AD8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80378ADC: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80378AE0: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80378AE4: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80378AE8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80378AEC: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80378AF0: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80378AF4: jal         0x8013D520
    // 0x80378AF8: lbu         $a0, 0x67($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X67);
    LOOKUP_FUNC(0x8013D520)(rdram, ctx);
        goto after_8;
    // 0x80378AF8: lbu         $a0, 0x67($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X67);
    after_8:
    // 0x80378AFC: beq         $v0, $zero, L_80378B34
    if (ctx->r2 == 0) {
        // 0x80378B00: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_80378B34;
    }
    // 0x80378B00: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80378B04: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80378B08: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80378B0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80378B10: addiu       $a3, $a3, -0x6BAC
    ctx->r7 = ADD32(ctx->r7, -0X6BAC);
    // 0x80378B14: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80378B18: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x80378B1C: jal         0x8001B204
    // 0x80378B20: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x80378B20: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x80378B24: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80378B28: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378B2C: b           L_80378B74
    // 0x80378B30: sb          $t7, -0x7650($at)
    MEM_B(-0X7650, ctx->r1) = ctx->r15;
    LOOKUP_FUNC(0x80378B74)(rdram, ctx);
    return;
    // 0x80378B30: sb          $t7, -0x7650($at)
    MEM_B(-0X7650, ctx->r1) = ctx->r15;
L_80378B34:
    // 0x80378B34: jal         0x8013D5F4
    // 0x80378B38: lbu         $a0, 0x67($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X67);
    LOOKUP_FUNC(0x8013D5F4)(rdram, ctx);
        goto after_10;
    // 0x80378B38: lbu         $a0, 0x67($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X67);
    after_10:
    // 0x80378B3C: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80378B40: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80378B44: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80378b48(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80378b48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378B48: addiu       $a3, $a3, -0x6B84
    ctx->r7 = ADD32(ctx->r7, -0X6B84);
    // 0x80378B4C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80378B50: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80378B54: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x80378B58: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80378B5C: jal         0x8001B204
    // 0x80378B60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x80378B60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80378B64: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80378B68: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    // 0x80378B6C: jal         0x8014B3B0
    // 0x80378B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8014B3B0)(rdram, ctx);
        goto after_1;
    // 0x80378B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80378b74(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80378b74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378B74: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80378B78: lw          $a1, -0x5700($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5700);
    // 0x80378B7C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80378B80: jal         0x80149580
    // 0x80378B84: lbu         $a2, 0x67($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X67);
    LOOKUP_FUNC(0x80149580)(rdram, ctx);
        goto after_0;
    // 0x80378B84: lbu         $a2, 0x67($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X67);
    after_0:
    // 0x80378B88: b           L_80378C48
    // 0x80378B8C: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x80378C48)(rdram, ctx);
    return;
    // 0x80378B8C: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80378b90(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80378b90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378B90: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80378B94: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80378B98: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80378B9C: addiu       $a3, $a3, -0x6B7C
    ctx->r7 = ADD32(ctx->r7, -0X6B7C);
    // 0x80378BA0: jal         0x8001B204
    // 0x80378BA4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x80378BA4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x80378BA8: b           L_80378C48
    // 0x80378BAC: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x80378C48)(rdram, ctx);
    return;
    // 0x80378BAC: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80378bb0(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80378bb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378BB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80378BB4: jal         0x8013D520
    // 0x80378BB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8013D520)(rdram, ctx);
        goto after_0;
    // 0x80378BB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80378BBC: beq         $v0, $zero, L_80378BEC
    if (ctx->r2 == 0) {
        // 0x80378BC0: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_80378BEC;
    }
    // 0x80378BC0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80378BC4: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80378BC8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80378BCC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80378BD0: addiu       $a3, $a3, -0x6B60
    ctx->r7 = ADD32(ctx->r7, -0X6B60);
    // 0x80378BD4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80378BD8: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x80378BDC: jal         0x8001B204
    // 0x80378BE0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x80378BE0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x80378BE4: b           L_80378C48
    // 0x80378BE8: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x80378C48)(rdram, ctx);
    return;
    // 0x80378BE8: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
L_80378BEC:
    // 0x80378BEC: jal         0x8013D5F4
    // 0x80378BF0: lbu         $a0, 0x67($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X67);
    LOOKUP_FUNC(0x8013D5F4)(rdram, ctx);
        goto after_2;
    // 0x80378BF0: lbu         $a0, 0x67($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X67);
    after_2:
    // 0x80378BF4: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80378BF8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80378BFC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80378C00: addiu       $a3, $a3, -0x6B38
    ctx->r7 = ADD32(ctx->r7, -0X6B38);
    // 0x80378C04: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80378C08: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80378C0C: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x80378C10: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80378C14: jal         0x8001B204
    // 0x80378C18: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x80378C18: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_3:
    // 0x80378C1C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80378C20: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    // 0x80378C24: jal         0x8014B034
    // 0x80378C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8014B034)(rdram, ctx);
        goto after_4;
    // 0x80378C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80378C2C: lbu         $t2, 0x67($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X67);
    // 0x80378C30: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x80378C34: bnel        $t2, $at, L_80378C48
    if (ctx->r10 != ctx->r1) {
            // 0x80378C38: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x80378C48)(rdram, ctx);
    return;
    }
    goto skip_0;
    // 0x80378C38: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    skip_0:
    // 0x80378C3C: jal         0x80133980
    // 0x80378C40: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_5;
    // 0x80378C40: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    after_5:
    // 0x80378C44: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80378c48(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80378c48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378C48: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x80378C4C: ori         $at, $at, 0x3C
    ctx->r1 = ctx->r1 | 0X3C;
    // 0x80378C50: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x80378C54: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80378C58: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x80378C5C: bne         $t4, $at, L_80378C94
    if (ctx->r12 != ctx->r1) {
        // 0x80378C60: addiu       $t8, $t8, -0x7660
        ctx->r24 = ADD32(ctx->r24, -0X7660);
            goto L_80378C94;
    }
    // 0x80378C60: addiu       $t8, $t8, -0x7660
    ctx->r24 = ADD32(ctx->r24, -0X7660);
    // 0x80378C64: addiu       $t5, $t5, -0x7678
    ctx->r13 = ADD32(ctx->r13, -0X7678);
    // 0x80378C68: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80378C6C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80378C70: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80378C74: lw          $a2, 0x4($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X4);
    // 0x80378C78: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80378C7C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80378C80: lw          $a3, 0x8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X8);
    // 0x80378C84: jal         0x8013A28C
    // 0x80378C88: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_0;
    // 0x80378C88: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x80378C8C: b           L_80378CB8
    // 0x80378C90: nop

        goto L_80378CB8;
    // 0x80378C90: nop

L_80378C94:
    // 0x80378C94: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80378C98: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80378C9C: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80378CA0: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x80378CA4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80378CA8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80378CAC: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x80378CB0: jal         0x8013A28C
    // 0x80378CB4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_1;
    // 0x80378CB4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
L_80378CB8:
    // 0x80378CB8: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80378CBC: addiu       $a1, $a1, -0x7328
    ctx->r5 = ADD32(ctx->r5, -0X7328);
    // 0x80378CC0: jal         0x800058DC
    // 0x80378CC4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80378CC4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_2:
    // 0x80378CC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80378CCC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80378CD0: jr          $ra
    // 0x80378CD4: nop

    return;
    // 0x80378CD4: nop

;}
RECOMP_FUNC void M55_FUN_80378cd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378CD8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80378CDC: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80378CE0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80378CE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80378CE8: addiu       $t0, $t0, -0x5700
    ctx->r8 = ADD32(ctx->r8, -0X5700);
    // 0x80378CEC: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80378cf0(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80378cf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378CF0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80378CF4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80378CF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80378CFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80378D00: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80378D04: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80378D08: beq         $a1, $zero, L_8037905C
    if (ctx->r5 == 0) {
            // 0x80378D0C: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8037905C)(rdram, ctx);
    return;
    }
    // 0x80378D0C: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80378D10: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x80378D14: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80378D18: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
    // 0x80378D1C: addiu       $t7, $t6, 0x80
    ctx->r15 = ADD32(ctx->r14, 0X80);
    // 0x80378D20: sh          $t7, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r15;
    // 0x80378D24: lh          $v1, -0x7654($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X7654);
    // 0x80378D28: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80378D2C: beql        $at, $zero, L_80378DF4
    if (ctx->r1 == 0) {
        // 0x80378D30: slti        $at, $v1, 0x33
        ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
            goto L_80378DF4;
    }
    goto skip_0;
    // 0x80378D30: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    skip_0:
    // 0x80378D34: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80378D38: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378D3C: ldc1        $f0, -0x6B00($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X6B00);
    // 0x80378D40: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80378D44: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80378D48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80378D4C: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80378D50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80378D54: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80378D58: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80378D5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80378D60: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80378D64: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80378D68: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80378D6C: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80378D70: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80378D74: div.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80378D78: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80378D7C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80378D80: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80378D84: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80378D88: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80378D8C: add.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80378D90: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x80378D94: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80378D98: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80378D9C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80378DA0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80378DA4: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x80378DA8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80378DAC: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x80378DB0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80378DB4: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x80378DB8: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80378DBC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80378DC0: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x80378DC4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80378DC8: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x80378DCC: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80378DD0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80378DD4: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80378DD8: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80378DDC: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x80378DE0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80378DE4: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x80378DE8: b           L_8037907C
    // 0x80378DEC: lh          $v1, -0x7654($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X7654);
    LOOKUP_FUNC(0x8037907C)(rdram, ctx);
    return;
    // 0x80378DEC: lh          $v1, -0x7654($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X7654);
    // 0x80378DF0: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
L_80378DF4:
    // 0x80378DF4: bne         $at, $zero, L_8037907C
    if (ctx->r1 != 0) {
            // 0x80378DF8: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    LOOKUP_FUNC(0x8037907C)(rdram, ctx);
    return;
    }
    // 0x80378DF8: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x80378DFC: lbu         $t4, -0x7650($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X7650);
    // 0x80378E00: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80378E04: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80378E08: beq         $t4, $zero, L_80378EC0
    if (ctx->r12 == 0) {
        // 0x80378E0C: nop
    
            goto L_80378EC0;
    }
    // 0x80378E0C: nop

    // 0x80378E10: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80378E14: jal         0x8014B4A0
    // 0x80378E18: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    LOOKUP_FUNC(0x8014B4A0)(rdram, ctx);
        goto after_0;
    // 0x80378E18: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    after_0:
    // 0x80378E1C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80378E20: jal         0x8014C1F0
    // 0x80378E24: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    LOOKUP_FUNC(0x8014C1F0)(rdram, ctx);
        goto after_1;
    // 0x80378E24: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    after_1:
    // 0x80378E28: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x80378E2C: bne         $t5, $zero, L_80378E7C
    if (ctx->r13 != 0) {
        // 0x80378E30: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_80378E7C;
    }
    // 0x80378E30: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80378E34: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80378E38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80378E3C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80378E40: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80378E44: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x80378E48: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80378E4C: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x80378E50: addiu       $t8, $sp, 0x40
    ctx->r24 = ADD32(ctx->r29, 0X40);
    // 0x80378E54: lw          $a0, 0x2C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X2C);
    // 0x80378E58: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80378E5C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80378E60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80378E64: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80378E68: jal         0x80130E34
    // 0x80378E6C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x80130E34)(rdram, ctx);
        goto after_2;
    // 0x80378E6C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x80378E70: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80378E74: b           L_80378F74
    // 0x80378E78: addiu       $t0, $t0, -0x5700
    ctx->r8 = ADD32(ctx->r8, -0X5700);
    LOOKUP_FUNC(0x80378F74)(rdram, ctx);
    return;
    // 0x80378E78: addiu       $t0, $t0, -0x5700
    ctx->r8 = ADD32(ctx->r8, -0X5700);
L_80378E7C:
    // 0x80378E7C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80378E80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80378E84: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80378E88: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x80378E8C: addiu       $t1, $sp, 0x44
    ctx->r9 = ADD32(ctx->r29, 0X44);
    // 0x80378E90: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80378E94: addiu       $t2, $sp, 0x40
    ctx->r10 = ADD32(ctx->r29, 0X40);
    // 0x80378E98: lw          $a0, 0x2C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X2C);
    // 0x80378E9C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80378EA0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80378EA4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80378EA8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80378EAC: jal         0x80130E34
    // 0x80378EB0: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x80130E34)(rdram, ctx);
        goto after_3;
    // 0x80378EB0: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    after_3:
    // 0x80378EB4: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80378EB8: b           L_80378F74
    // 0x80378EBC: addiu       $t0, $t0, -0x5700
    ctx->r8 = ADD32(ctx->r8, -0X5700);
    LOOKUP_FUNC(0x80378F74)(rdram, ctx);
    return;
    // 0x80378EBC: addiu       $t0, $t0, -0x5700
    ctx->r8 = ADD32(ctx->r8, -0X5700);
L_80378EC0:
    // 0x80378EC0: jal         0x8014C1F0
    // 0x80378EC4: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    LOOKUP_FUNC(0x8014C1F0)(rdram, ctx);
        goto after_4;
    // 0x80378EC4: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    after_4:
    // 0x80378EC8: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x80378ECC: bne         $t3, $zero, L_80378F28
    if (ctx->r11 != 0) {
        // 0x80378ED0: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_80378F28;
    }
    // 0x80378ED0: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80378ED4: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80378ED8: lw          $t5, -0x4330($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4330);
    // 0x80378EDC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80378EE0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80378EE4: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x80378EE8: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80378EEC: lw          $t4, -0x4328($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4328);
    // 0x80378EF0: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80378EF4: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x80378EF8: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x80378EFC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80378F00: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80378F04: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x80378F08: lw          $a0, 0x2C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X2C);
    // 0x80378F0C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80378F10: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80378F14: jal         0x80130E34
    // 0x80378F18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80130E34)(rdram, ctx);
        goto after_5;
    // 0x80378F18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_5:
    // 0x80378F1C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80378F20: b           L_80378F74
    // 0x80378F24: addiu       $t0, $t0, -0x5700
    ctx->r8 = ADD32(ctx->r8, -0X5700);
    LOOKUP_FUNC(0x80378F74)(rdram, ctx);
    return;
    // 0x80378F24: addiu       $t0, $t0, -0x5700
    ctx->r8 = ADD32(ctx->r8, -0X5700);
L_80378F28:
    // 0x80378F28: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80378F2C: lw          $t9, -0x4330($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4330);
    // 0x80378F30: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80378F34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80378F38: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x80378F3C: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x80378F40: addiu       $t1, $sp, 0x44
    ctx->r9 = ADD32(ctx->r29, 0X44);
    // 0x80378F44: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80378F48: addiu       $t2, $sp, 0x40
    ctx->r10 = ADD32(ctx->r29, 0X40);
    // 0x80378F4C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80378F50: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80378F54: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x80378F58: lw          $a0, 0x2C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X2C);
    // 0x80378F5C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80378F60: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80378f64(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80378f64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378F64: jal         0x80130E34
    // 0x80378F68: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80130E34)(rdram, ctx);
        goto after_0;
    // 0x80378F68: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x80378F6C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80378F70: addiu       $t0, $t0, -0x5700
    ctx->r8 = ADD32(ctx->r8, -0X5700);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80378f74(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80378f74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378F74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80378F78: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80378F7C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80378F80: nop

    // 0x80378F84: bc1fl       L_80378F94
    if (!c1cs) {
        // 0x80378F88: lwc1        $f4, 0x40($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
            goto L_80378F94;
    }
    goto skip_0;
    // 0x80378F88: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80378F8C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80378F90: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
L_80378F94:
    // 0x80378F94: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80378F98: nop

    // 0x80378F9C: bc1fl       L_80378FAC
    if (!c1cs) {
        // 0x80378FA0: lw          $t3, 0x0($t0)
        ctx->r11 = MEM_W(ctx->r8, 0X0);
            goto L_80378FAC;
    }
    goto skip_1;
    // 0x80378FA0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    skip_1:
    // 0x80378FA4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80378FA8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
L_80378FAC:
    // 0x80378FAC: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80378FB0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378FB4: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80378FB8: ldc1        $f0, -0x6AF8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X6AF8);
    // 0x80378FBC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80378FC0: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80378FC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80378FC8: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80378FCC: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80378FD0: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80378FD4: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80378FD8: div.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80378FDC: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80378FE0: div.s       $f14, $f4, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80378FE4: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80378FE8: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80378FEC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80378FF0: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x80378FF4: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80378FF8: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x80378FFC: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x80379000: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80379004: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x80379008: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8037900C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80379010: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80379014: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80379018: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x8037901C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80379020: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80379024: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80379028: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8037902C: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80379030: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80379034: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x80379038: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8037903C: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80379040: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80379044: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80379048: mul.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8037904C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80379050: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80379054(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80379054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379054: b           L_8037907C
    // 0x80379058: lh          $v1, -0x7654($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X7654);
    LOOKUP_FUNC(0x8037907C)(rdram, ctx);
    return;
    // 0x80379058: lh          $v1, -0x7654($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X7654);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037905c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037905c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037905C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80379060: addiu       $a1, $a1, -0x6F10
    ctx->r5 = ADD32(ctx->r5, -0X6F10);
    // 0x80379064: jal         0x800058DC
    // 0x80379068: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80379068: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_0:
    // 0x8037906C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80379070: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80379074: lh          $v1, -0x7654($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X7654);
    // 0x80379078: addiu       $t0, $t0, -0x5700
    ctx->r8 = ADD32(ctx->r8, -0X5700);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037907c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037907c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037907C: slti        $v0, $v1, 0x47
    ctx->r2 = SIGNED(ctx->r3) < 0X47 ? 1 : 0;
    // 0x80379080: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80379084: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80379088: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037908C: beq         $v0, $zero, L_803790E0
    if (ctx->r2 == 0) {
        // 0x80379090: sh          $t8, -0x7654($at)
        MEM_H(-0X7654, ctx->r1) = ctx->r24;
            goto L_803790E0;
    }
    // 0x80379090: sh          $t8, -0x7654($at)
    MEM_H(-0X7654, ctx->r1) = ctx->r24;
    // 0x80379094: lui         $t9, 0x8038
    ctx->r25 = S32(0X8038 << 16);
    // 0x80379098: addiu       $t9, $t9, -0x6F10
    ctx->r25 = ADD32(ctx->r25, -0X6F10);
    // 0x8037909C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x803790A0: jal         0x80006088
    // 0x803790A4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_0;
    // 0x803790A4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_0:
    // 0x803790A8: jal         0x80149684
    // 0x803790AC: nop

    LOOKUP_FUNC(0x80149684)(rdram, ctx);
        goto after_1;
    // 0x803790AC: nop

    after_1:
    // 0x803790B0: jal         0x801170DC
    // 0x803790B4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x801170DC)(rdram, ctx);
        goto after_2;
    // 0x803790B4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x803790B8: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x803790BC: lbu         $t1, -0x7650($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X7650);
    // 0x803790C0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x803790C4: beql        $t1, $zero, L_803790D8
    if (ctx->r9 == 0) {
        // 0x803790C8: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_803790D8;
    }
    goto skip_0;
    // 0x803790C8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    skip_0:
    // 0x803790CC: jal         0x8014C194
    // 0x803790D0: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    LOOKUP_FUNC(0x8014C194)(rdram, ctx);
        goto after_3;
    // 0x803790D0: lhu         $a0, -0x41CC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X41CC);
    after_3:
    // 0x803790D4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
L_803790D8:
    // 0x803790D8: jal         0x800058DC
    // 0x803790DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x803790DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
L_803790E0:
    // 0x803790E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803790E4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x803790E8: jr          $ra
    // 0x803790EC: nop

    return;
    // 0x803790EC: nop

;}
RECOMP_FUNC void M55_FUN_803790f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803790F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803790F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803790F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x803790FC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80379100: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x80379104: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80379108: jal         0x80010550
    // 0x8037910C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x8037910C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80379110: beq         $v0, $zero, L_80379180
    if (ctx->r2 == 0) {
        // 0x80379114: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_80379180;
    }
    // 0x80379114: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80379118: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8037911C: addiu       $a3, $a3, -0x6B30
    ctx->r7 = ADD32(ctx->r7, -0X6B30);
    // 0x80379120: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80379124: jal         0x8001B204
    // 0x80379128: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x80379128: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8037912C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80379130: jal         0x80005700
    // 0x80379134: lw          $a0, -0x56F4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X56F4);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x80379134: lw          $a0, -0x56F4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X56F4);
    after_2:
    // 0x80379138: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x8037913C: addiu       $t7, $t7, 0x6B90
    ctx->r15 = ADD32(ctx->r15, 0X6B90);
    // 0x80379140: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80379144: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80379148: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037914C: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80379150: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x80379154: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80379158: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8037915C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80379160: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80379164: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80379168: jal         0x80011140
    // 0x8037916C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_3;
    // 0x8037916C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x80379170: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80379174: addiu       $a1, $a1, -0x6E70
    ctx->r5 = ADD32(ctx->r5, -0X6E70);
    // 0x80379178: jal         0x800058DC
    // 0x8037917C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8037917C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
L_80379180:
    // 0x80379180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80379184: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80379188: jr          $ra
    // 0x8037918C: nop

    return;
    // 0x8037918C: nop

;}
RECOMP_FUNC void M55_FUN_80379190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379190: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80379194: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80379198(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80379198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379198: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037919C: lhu         $t7, 0xEF0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XEF0);
    // 0x803791A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803791A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x803791A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803791AC: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x803791B0: lui         $t9, 0x8021
    ctx->r25 = S32(0X8021 << 16);
    // 0x803791B4: andi        $t8, $t7, 0xFFAF
    ctx->r24 = ctx->r15 & 0XFFAF;
    // 0x803791B8: sh          $t8, 0xEF0($v0)
    MEM_H(0XEF0, ctx->r2) = ctx->r24;
    // 0x803791BC: addiu       $t9, $t9, 0x6B90
    ctx->r25 = ADD32(ctx->r25, 0X6B90);
    // 0x803791C0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x803791C4: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x803791C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x803791CC: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x803791D0: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x803791D4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x803791D8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x803791DC: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x803791E0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x803791E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803791E8: jal         0x80011140
    // 0x803791EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x803791EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x803791F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x803791F4: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x803791F8: ori         $at, $at, 0x41
    ctx->r1 = ctx->r1 | 0X41;
    // 0x803791FC: lw          $t3, 0x1C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X1C);
    // 0x80379200: bnel        $t3, $at, L_80379238
    if (ctx->r11 != ctx->r1) {
        // 0x80379204: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80379238;
    }
    goto skip_0;
    // 0x80379204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80379208: jal         0x8001F6FC
    // 0x8037920C: nop

    LOOKUP_FUNC(0x8001F6FC)(rdram, ctx);
        goto after_1;
    // 0x8037920C: nop

    after_1:
    // 0x80379210: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80379214: jal         0x8001F74C
    // 0x80379218: lw          $a0, -0x4334($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4334);
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_2;
    // 0x80379218: lw          $a0, -0x4334($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4334);
    after_2:
    // 0x8037921C: jal         0x80126E88
    // 0x80379220: addiu       $a0, $zero, 0xC1
    ctx->r4 = ADD32(0, 0XC1);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_3;
    // 0x80379220: addiu       $a0, $zero, 0xC1
    ctx->r4 = ADD32(0, 0XC1);
    after_3:
    // 0x80379224: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x80379228: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x8037922C: jal         0x800058DC
    // 0x80379230: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80379230: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80379234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80379238:
    // 0x80379238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037923C: jr          $ra
    // 0x80379240: nop

    return;
    // 0x80379240: nop

;}
RECOMP_FUNC void M55_FUN_80379244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379244: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80379248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037924C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80379250: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80379254: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x80379258: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8037925C: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x80379260: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80379264: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80379268: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x8037926C: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80379270: lwc1        $f14, 0x8($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80379274: jal         0x8014BC78
    // 0x80379278: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    LOOKUP_FUNC(0x8014BC78)(rdram, ctx);
        goto after_0;
    // 0x80379278: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    after_0:
    // 0x8037927C: beq         $v0, $zero, L_80379464
    if (ctx->r2 == 0) {
            // 0x80379280: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x80379464)(rdram, ctx);
    return;
    }
    // 0x80379280: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80379284: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80379288: sh          $a0, -0x41CC($at)
    MEM_H(-0X41CC, ctx->r1) = ctx->r4;
    // 0x8037928C: jal         0x8014B4A0
    // 0x80379290: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8014B4A0)(rdram, ctx);
        goto after_1;
    // 0x80379290: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x80379294: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80379298: lw          $t9, -0x4330($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4330);
    // 0x8037929C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x803792A0: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x803792A4: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x803792A8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x803792AC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x803792B0: lwc1        $f0, 0x8($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X8);
    // 0x803792B4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x803792B8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x803792BC: nop

    // 0x803792C0: bc1fl       L_803792EC
    if (!c1cs) {
        // 0x803792C4: sub.s       $f18, $f0, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
            goto L_803792EC;
    }
    goto skip_0;
    // 0x803792C4: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    skip_0:
    // 0x803792C8: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x803792CC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x803792D0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x803792D4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x803792D8: nop

    // 0x803792DC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x803792E0: b           L_80379300
    // 0x803792E4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80379300;
    // 0x803792E4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x803792E8: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
L_803792EC:
    // 0x803792EC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x803792F0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x803792F4: nop

    // 0x803792F8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x803792FC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80379300:
    // 0x80379300: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80379304: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80379308: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8037930C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80379310: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80379314: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80379318: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8037931C: nop

    // 0x80379320: bc1f        L_80379444
    if (!c1cs) {
            // 0x80379324: nop

    LOOKUP_FUNC(0x80379444)(rdram, ctx);
    return;
    }
    // 0x80379324: nop

    // 0x80379328: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8037932C: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80379330: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80379334: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80379338: jal         0x8001EF38
    // 0x8037933C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x8037933C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_2:
    // 0x80379340: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80379344: lw          $t4, -0x4330($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4330);
    // 0x80379348: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8037934C: addiu       $t3, $zero, 0x1800
    ctx->r11 = ADD32(0, 0X1800);
    // 0x80379350: lw          $t0, 0x2C($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X2C);
    // 0x80379354: subu        $v1, $t3, $v0
    ctx->r3 = SUB32(ctx->r11, ctx->r2);
    // 0x80379358: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8037935C: lh          $t5, 0x12($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X12);
    // 0x80379360: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80379364: andi        $t1, $v1, 0x1FFF
    ctx->r9 = ctx->r3 & 0X1FFF;
    // 0x80379368: andi        $t6, $t5, 0x1FFF
    ctx->r14 = ctx->r13 & 0X1FFF;
    // 0x8037936C: sh          $t6, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r14;
    // 0x80379370: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x80379374: sll         $a2, $t1, 16
    ctx->r6 = S32(ctx->r9 << 16);
    // 0x80379378: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8037937C: lw          $t0, 0x2C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X2C);
    // 0x80379380: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80379384: lh          $t8, 0x12($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X12);
    // 0x80379388: subu        $a0, $t8, $t1
    ctx->r4 = SUB32(ctx->r24, ctx->r9);
    // 0x8037938C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80379390: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80379394: andi        $a1, $a0, 0x1000
    ctx->r5 = ctx->r4 & 0X1000;
    // 0x80379398: beq         $a1, $zero, L_803793AC
    if (ctx->r5 == 0) {
        // 0x8037939C: andi        $v0, $a0, 0x1FFF
        ctx->r2 = ctx->r4 & 0X1FFF;
            goto L_803793AC;
    }
    // 0x8037939C: andi        $v0, $a0, 0x1FFF
    ctx->r2 = ctx->r4 & 0X1FFF;
    // 0x803793A0: andi        $v0, $a0, 0x1FFF
    ctx->r2 = ctx->r4 & 0X1FFF;
    // 0x803793A4: b           L_803793B0
    // 0x803793A8: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
        goto L_803793B0;
    // 0x803793A8: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
L_803793AC:
    // 0x803793AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_803793B0:
    // 0x803793B0: bgez        $v1, L_803793E4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x803793B4: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_803793E4;
    }
    // 0x803793B4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x803793B8: beq         $a1, $zero, L_803793D4
    if (ctx->r5 == 0) {
        // 0x803793BC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_803793D4;
    }
    // 0x803793BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x803793C0: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
    // 0x803793C4: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x803793C8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x803793CC: b           L_803793FC
    // 0x803793D0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_803793FC;
    // 0x803793D0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_803793D4:
    // 0x803793D4: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x803793D8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x803793DC: b           L_803793FC
    // 0x803793E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_803793FC;
    // 0x803793E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_803793E4:
    // 0x803793E4: beq         $a1, $zero, L_803793F4
    if (ctx->r5 == 0) {
        // 0x803793E8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_803793F4;
    }
    // 0x803793E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x803793EC: b           L_803793F4
    // 0x803793F0: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
        goto L_803793F4;
    // 0x803793F0: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
L_803793F4:
    // 0x803793F4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x803793F8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_803793FC:
    // 0x803793FC: slti        $at, $v0, 0x401
    ctx->r1 = SIGNED(ctx->r2) < 0X401 ? 1 : 0;
    // 0x80379400: beq         $at, $zero, L_80379424
    if (ctx->r1 == 0) {
            // 0x80379404: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    LOOKUP_FUNC(0x80379424)(rdram, ctx);
    return;
    }
    // 0x80379404: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80379408: sh          $a2, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r6;
    // 0x8037940C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80379410(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80379410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379410: addiu       $a1, $a1, -0x7B34
    ctx->r5 = ADD32(ctx->r5, -0X7B34);
    // 0x80379414: jal         0x800058DC
    // 0x80379418: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80379418: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_0:
    // 0x8037941C: b           L_8037948C
    // 0x80379420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    LOOKUP_FUNC(0x8037948C)(rdram, ctx);
    return;
    // 0x80379420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80379424(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80379424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379424: jal         0x801ED72C
    // 0x80379428: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x801ED72C)(rdram, ctx);
        goto after_0;
    // 0x80379428: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x8037942C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x80379430: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x80379434: jal         0x800058DC
    // 0x80379438: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80379438: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8037943C: b           L_8037948C
    // 0x80379440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    LOOKUP_FUNC(0x8037948C)(rdram, ctx);
    return;
    // 0x80379440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80379444(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80379444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379444: jal         0x801ED72C
    // 0x80379448: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801ED72C)(rdram, ctx);
        goto after_0;
    // 0x80379448: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8037944C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x80379450: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x80379454: jal         0x800058DC
    // 0x80379458: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80379458: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8037945C: b           L_8037948C
    // 0x80379460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    LOOKUP_FUNC(0x8037948C)(rdram, ctx);
    return;
    // 0x80379460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80379464(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80379464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379464: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80379468: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8037946C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80379470: jal         0x801ED72C
    // 0x80379474: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801ED72C)(rdram, ctx);
        goto after_0;
    // 0x80379474: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80379478: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x8037947C: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x80379480: jal         0x800058DC
    // 0x80379484: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80379484: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x80379488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037948c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037948c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037948C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80379490: jr          $ra
    // 0x80379494: nop

    return;
    // 0x80379494: nop

;}
RECOMP_FUNC void M55_FUN_80379498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379498: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037949C: addiu       $v0, $v0, -0x56E8
    ctx->r2 = ADD32(ctx->r2, -0X56E8);
    // 0x803794A0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x803794A4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x803794A8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x803794AC: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x803794B0: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x803794B4: lwc1        $f8, 0x14($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14);
    // 0x803794B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x803794BC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x803794C0: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x803794C4: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x803794C8: swc1        $f14, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f14.u32l;
    // 0x803794CC: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x803794D0: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x803794D4: jr          $ra
    // 0x803794D8: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x803794D8: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803794dc(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803794dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803794DC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x803794E0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x803794E4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x803794E8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x803794EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803794F0: addiu       $a1, $zero, 0xC1
    ctx->r5 = ADD32(0, 0XC1);
    // 0x803794F4: jal         0x80126A0C
    // 0x803794F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x803794F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x803794FC: beql        $v0, $zero, L_80379680
    if (ctx->r2 == 0) {
        // 0x80379500: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80379680;
    }
    goto skip_0;
    // 0x80379500: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80379504: jal         0x80116E80
    // 0x80379508: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_1;
    // 0x80379508: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x8037950C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80379510: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379514: addiu       $t0, $t0, -0x56E8
    ctx->r8 = ADD32(ctx->r8, -0X56E8);
    // 0x80379518: sh          $zero, -0x764C($at)
    MEM_H(-0X764C, ctx->r1) = 0;
    // 0x8037951C: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
    // 0x80379520: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80379524: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80379528: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8037952C: sb          $a1, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r5;
    // 0x80379530: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80379534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80379538: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    // 0x8037953C: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    // 0x80379540: jal         0x801494A4
    // 0x80379544: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x801494A4)(rdram, ctx);
        goto after_2;
    // 0x80379544: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80379548: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037954C: addiu       $v1, $v1, -0x56F0
    ctx->r3 = ADD32(ctx->r3, -0X56F0);
    // 0x80379550: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80379554: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80379558: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x8037955C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80379560: addiu       $t0, $t0, -0x56E8
    ctx->r8 = ADD32(ctx->r8, -0X56E8);
    // 0x80379564: addiu       $t8, $sp, 0x44
    ctx->r24 = ADD32(ctx->r29, 0X44);
    // 0x80379568: addiu       $t9, $sp, 0x40
    ctx->r25 = ADD32(ctx->r29, 0X40);
    // 0x8037956C: lw          $a0, 0x2C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X2C);
    // 0x80379570: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80379574: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80379578: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x8037957C: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x80379580: jal         0x80130E34
    // 0x80379584: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    LOOKUP_FUNC(0x80130E34)(rdram, ctx);
        goto after_3;
    // 0x80379584: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    after_3:
    // 0x80379588: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8037958C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80379590: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80379594: addiu       $v1, $v1, -0x56F0
    ctx->r3 = ADD32(ctx->r3, -0X56F0);
    // 0x80379598: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8037959C: nop

    // 0x803795A0: bc1fl       L_803795B0
    if (!c1cs) {
        // 0x803795A4: lwc1        $f6, 0x40($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
            goto L_803795B0;
    }
    goto skip_1;
    // 0x803795A4: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    skip_1:
    // 0x803795A8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x803795AC: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
L_803795B0:
    // 0x803795B0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x803795B4: nop

    // 0x803795B8: bc1fl       L_803795C8
    if (!c1cs) {
        // 0x803795BC: lw          $t1, 0x0($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X0);
            goto L_803795C8;
    }
    goto skip_2;
    // 0x803795BC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x803795C0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x803795C4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
L_803795C8:
    // 0x803795C8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x803795CC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803795D0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x803795D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803795D8: swc1        $f8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f8.u32l;
    // 0x803795DC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x803795E0: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x803795E4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x803795E8: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
    // 0x803795EC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x803795F0: lwc1        $f16, -0x6AF0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6AF0);
    // 0x803795F4: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x803795F8: swc1        $f16, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f16.u32l;
    // 0x803795FC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80379600: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80379604: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80379608: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8037960C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80379610: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80379614: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x80379618: lbu         $a2, 0x3F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3F);
    // 0x8037961C: jal         0x80149580
    // 0x80379620: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    LOOKUP_FUNC(0x80149580)(rdram, ctx);
        goto after_4;
    // 0x80379620: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_4:
    // 0x80379624: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80379628: addiu       $a1, $a1, -0x7698
    ctx->r5 = ADD32(ctx->r5, -0X7698);
    // 0x8037962C: jal         0x80005670
    // 0x80379630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_5;
    // 0x80379630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80379634: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379638: sw          $v0, -0x56F4($at)
    MEM_W(-0X56F4, ctx->r1) = ctx->r2;
    // 0x8037963C: jal         0x8013D5F4
    // 0x80379640: lbu         $a0, 0x3F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3F);
    LOOKUP_FUNC(0x8013D5F4)(rdram, ctx);
        goto after_6;
    // 0x80379640: lbu         $a0, 0x3F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3F);
    after_6:
    // 0x80379644: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80379648: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8037964C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80379650: addiu       $a3, $a3, -0x6B10
    ctx->r7 = ADD32(ctx->r7, -0X6B10);
    // 0x80379654: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80379658: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x8037965C: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x80379660: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80379664: jal         0x8001B204
    // 0x80379668: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x80379668: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_7:
    // 0x8037966C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80379670: addiu       $a1, $a1, -0x6970
    ctx->r5 = ADD32(ctx->r5, -0X6970);
    // 0x80379674: jal         0x800058DC
    // 0x80379678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x80379678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8037967C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80379680:
    // 0x80379680: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80379684: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80379688: jr          $ra
    // 0x8037968C: nop

    return;
    // 0x8037968C: nop

;}
RECOMP_FUNC void M55_FUN_80379690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379690: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80379694: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80379698: addiu       $t0, $t0, -0x56F0
    ctx->r8 = ADD32(ctx->r8, -0X56F0);
    // 0x8037969C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x803796A0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x803796A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803796A8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x803796AC: beq         $a1, $zero, L_803798D8
    if (ctx->r5 == 0) {
            // 0x803796B0: nop

    LOOKUP_FUNC(0x803798D8)(rdram, ctx);
    return;
    }
    // 0x803796B0: nop

    // 0x803796B4: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x803796B8: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x803796BC: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
    // 0x803796C0: addiu       $t7, $t6, 0x80
    ctx->r15 = ADD32(ctx->r14, 0X80);
    // 0x803796C4: sh          $t7, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r15;
    // 0x803796C8: lh          $v1, -0x764C($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X764C);
    // 0x803796CC: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x803796D0: beql        $at, $zero, L_80379798
    if (ctx->r1 == 0) {
            // 0x803796D4: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    LOOKUP_FUNC(0x80379798)(rdram, ctx);
    return;
    }
    goto skip_0;
    // 0x803796D4: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    skip_0:
    // 0x803796D8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x803796DC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803796E0: ldc1        $f0, -0x6AE8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X6AE8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803796e4(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803796e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803796E4: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x803796E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x803796EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x803796F0: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x803796F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x803796F8: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x803796FC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80379700: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80379704: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80379708: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8037970C: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80379710: div.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80379714: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80379718: div.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8037971C: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80379720: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80379724: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80379728: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x8037972C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80379730: add.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x80379734: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80379738: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8037973C: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80379740: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80379744: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80379748: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x8037974C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80379750: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x80379754: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80379758: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x8037975C: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80379760: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80379764: div.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x80379768: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8037976C: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x80379770: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80379774: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80379778: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8037977C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80379780: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x80379784: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80379788: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x8037978C: b           L_803798E8
    // 0x80379790: lh          $v1, -0x764C($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X764C);
    LOOKUP_FUNC(0x803798E8)(rdram, ctx);
    return;
    // 0x80379790: lh          $v1, -0x764C($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X764C);
    // 0x80379794: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80379798(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80379798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379798: bnel        $at, $zero, L_803798EC
    if (ctx->r1 != 0) {
            // 0x8037979C: slti        $v0, $v1, 0x47
    ctx->r2 = SIGNED(ctx->r3) < 0X47 ? 1 : 0;
    LOOKUP_FUNC(0x803798EC)(rdram, ctx);
    return;
    }
    goto skip_0;
    // 0x8037979C: slti        $v0, $v1, 0x47
    ctx->r2 = SIGNED(ctx->r3) < 0X47 ? 1 : 0;
    skip_0:
    // 0x803797A0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x803797A4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x803797A8: lw          $t5, 0xE0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XE0);
    // 0x803797AC: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x803797B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x803797B4: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x803797B8: lw          $t4, 0xE8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XE8);
    // 0x803797BC: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x803797C0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x803797C4: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x803797C8: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x803797CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x803797D0: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x803797D4: lw          $a0, 0x2C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X2C);
    // 0x803797D8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x803797DC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x803797E0: jal         0x80130E34
    // 0x803797E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80130E34)(rdram, ctx);
        goto after_0;
    // 0x803797E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x803797E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x803797EC: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x803797F0: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x803797F4: addiu       $t0, $t0, -0x56F0
    ctx->r8 = ADD32(ctx->r8, -0X56F0);
    // 0x803797F8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x803797FC: nop

    // 0x80379800: bc1fl       L_80379810
    if (!c1cs) {
        // 0x80379804: lwc1        $f18, 0x40($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
            goto L_80379810;
    }
    goto skip_1;
    // 0x80379804: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    skip_1:
    // 0x80379808: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8037980C: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
L_80379810:
    // 0x80379810: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80379814: nop

    // 0x80379818: bc1fl       L_80379828
    if (!c1cs) {
        // 0x8037981C: lw          $t8, 0x0($t0)
        ctx->r24 = MEM_W(ctx->r8, 0X0);
            goto L_80379828;
    }
    goto skip_2;
    // 0x8037981C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    skip_2:
    // 0x80379820: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80379824: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
L_80379828:
    // 0x80379828: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8037982C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379830: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80379834: ldc1        $f0, -0x6AE0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X6AE0);
    // 0x80379838: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8037983C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80379840: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80379844: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80379848: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8037984C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80379850: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80379854: div.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80379858: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8037985C: div.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80379860: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80379864: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80379868: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8037986C: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80379870: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80379874: add.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x80379878: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8037987C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80379880: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80379884: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80379888: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8037988C: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80379890: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80379894: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x80379898: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8037989C: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x803798A0: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x803798A4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x803798A8: mul.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x803798AC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x803798B0: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x803798B4: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x803798B8: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x803798BC: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x803798C0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x803798C4: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x803798C8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x803798CC: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x803798D0: b           L_803798E8
    // 0x803798D4: lh          $v1, -0x764C($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X764C);
    LOOKUP_FUNC(0x803798E8)(rdram, ctx);
    return;
    // 0x803798D4: lh          $v1, -0x764C($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X764C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803798d8(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803798d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803798D8: jal         0x80005700
    // 0x803798DC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x803798DC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x803798E0: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x803798E4: lh          $v1, -0x764C($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X764C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803798e8(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803798e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803798E8: slti        $v0, $v1, 0x47
    ctx->r2 = SIGNED(ctx->r3) < 0X47 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803798ec(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803798ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803798EC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x803798F0: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x803798F4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803798F8: beq         $v0, $zero, L_80379954
    if (ctx->r2 == 0) {
            // 0x803798FC: sh          $t4, -0x764C($at)
    MEM_H(-0X764C, ctx->r1) = ctx->r12;
    LOOKUP_FUNC(0x80379954)(rdram, ctx);
    return;
    }
    // 0x803798FC: sh          $t4, -0x764C($at)
    MEM_H(-0X764C, ctx->r1) = ctx->r12;
    // 0x80379900: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80379904(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80379904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379904: addiu       $a3, $a3, -0x6B08
    ctx->r7 = ADD32(ctx->r7, -0X6B08);
    // 0x80379908: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8037990C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80379910: jal         0x8001B204
    // 0x80379914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x80379914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80379918: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037991C: jal         0x80005700
    // 0x80379920: lw          $a0, -0x56F4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X56F4);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x80379920: lw          $a0, -0x56F4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X56F4);
    after_1:
    // 0x80379924: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80379928: addiu       $t0, $t0, -0x56F0
    ctx->r8 = ADD32(ctx->r8, -0X56F0);
    // 0x8037992C: jal         0x80006088
    // 0x80379930: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_2;
    // 0x80379930: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_2:
    // 0x80379934: jal         0x80149684
    // 0x80379938: nop

    LOOKUP_FUNC(0x80149684)(rdram, ctx);
        goto after_3;
    // 0x80379938: nop

    after_3:
    // 0x8037993C: jal         0x801170DC
    // 0x80379940: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x801170DC)(rdram, ctx);
        goto after_4;
    // 0x80379940: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_4:
    // 0x80379944: jal         0x80126E88
    // 0x80379948: addiu       $a0, $zero, 0xC1
    ctx->r4 = ADD32(0, 0XC1);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_5;
    // 0x80379948: addiu       $a0, $zero, 0xC1
    ctx->r4 = ADD32(0, 0XC1);
    after_5:
    // 0x8037994C: jal         0x80005700
    // 0x80379950: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_6;
    // 0x80379950: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_6:
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80379954(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80379954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80379958: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8037995C: jr          $ra
    // 0x80379960: nop

    return;
    // 0x80379960: nop

;}
RECOMP_FUNC void M55_FUN_80379964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379964: nop

    // 0x80379968: nop

    // 0x8037996C: nop

;}
RECOMP_FUNC void M55_FUN_80379970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379970: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80379974: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80379978(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80379978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379978: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037997C: lbu         $t7, 0x230($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X230);
    // 0x80379980: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80379984: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80379988: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x8037998C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379990: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80379994: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80379998: sb          $t7, -0x56C2($at)
    MEM_B(-0X56C2, ctx->r1) = ctx->r15;
    // 0x8037999C: addiu       $v1, $v1, -0x23C0
    ctx->r3 = ADD32(ctx->r3, -0X23C0);
    // 0x803799A0: sb          $t8, 0x230($a2)
    MEM_B(0X230, ctx->r6) = ctx->r24;
    // 0x803799A4: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x803799A8: lh          $v0, -0x7598($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X7598);
    // 0x803799AC: lhu         $t9, 0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2);
    // 0x803799B0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x803799B4: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x803799B8: bnel        $at, $zero, L_803799CC
    if (ctx->r1 != 0) {
        // 0x803799BC: lhu         $t0, 0x0($v1)
        ctx->r8 = MEM_HU(ctx->r3, 0X0);
            goto L_803799CC;
    }
    goto skip_0;
    // 0x803799BC: lhu         $t0, 0x0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X0);
    skip_0:
    // 0x803799C0: b           L_80379A1C
    // 0x803799C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_80379A1C;
    // 0x803799C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x803799C8: lhu         $t0, 0x0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X0);
L_803799CC:
    // 0x803799CC: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x803799D0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x803799D4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x803799D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x803799DC: bgez        $t0, L_803799F4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x803799E0: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_803799F4;
    }
    // 0x803799E0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x803799E4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x803799E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x803799EC: nop

    // 0x803799F0: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_803799F4:
    // 0x803799F4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803799F8: ldc1        $f10, -0x6848($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6848);
    // 0x803799FC: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80379A00: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80379A04: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x80379A08: nop

    // 0x80379A0C: bc1f        L_80379A1C
    if (!c1cs) {
        // 0x80379A10: nop
    
            goto L_80379A1C;
    }
    // 0x80379A10: nop

    // 0x80379A14: b           L_80379A1C
    // 0x80379A18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_80379A1C;
    // 0x80379A18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80379A1C:
    // 0x80379A1C: jal         0x801DFE50
    // 0x80379A20: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801DFE50)(rdram, ctx);
        goto after_0;
    // 0x80379A20: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80379A24: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80379A28: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x80379A2C: ori         $a0, $a0, 0x17
    ctx->r4 = ctx->r4 | 0X17;
    // 0x80379A30: lw          $v0, 0x1C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1C);
    // 0x80379A34: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x80379A38: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x80379A3C: beq         $a0, $v0, L_80379A4C
    if (ctx->r4 == ctx->r2) {
        // 0x80379A40: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_80379A4C;
    }
    // 0x80379A40: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80379A44: bne         $v0, $at, L_80379B08
    if (ctx->r2 != ctx->r1) {
        // 0x80379A48: addiu       $a1, $v1, 0x6
        ctx->r5 = ADD32(ctx->r3, 0X6);
            goto L_80379B08;
    }
    // 0x80379A48: addiu       $a1, $v1, 0x6
    ctx->r5 = ADD32(ctx->r3, 0X6);
L_80379A4C:
    // 0x80379A4C: bne         $a0, $v0, L_80379A80
    if (ctx->r4 != ctx->r2) {
        // 0x80379A50: addiu       $a1, $v1, 0x6
        ctx->r5 = ADD32(ctx->r3, 0X6);
            goto L_80379A80;
    }
    // 0x80379A50: addiu       $a1, $v1, 0x6
    ctx->r5 = ADD32(ctx->r3, 0X6);
    // 0x80379A54: lhu         $t1, 0x6($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X6);
    // 0x80379A58: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80379A5C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379A60: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x80379A64: beq         $t2, $zero, L_80379A78
    if (ctx->r10 == 0) {
        // 0x80379A68: nop
    
            goto L_80379A78;
    }
    // 0x80379A68: nop

    // 0x80379A6C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379A70: b           L_80379ADC
    // 0x80379A74: sb          $t3, -0x56C3($at)
    MEM_B(-0X56C3, ctx->r1) = ctx->r11;
        goto L_80379ADC;
    // 0x80379A74: sb          $t3, -0x56C3($at)
    MEM_B(-0X56C3, ctx->r1) = ctx->r11;
L_80379A78:
    // 0x80379A78: b           L_80379ADC
    // 0x80379A7C: sb          $zero, -0x56C3($at)
    MEM_B(-0X56C3, ctx->r1) = 0;
        goto L_80379ADC;
    // 0x80379A7C: sb          $zero, -0x56C3($at)
    MEM_B(-0X56C3, ctx->r1) = 0;
L_80379A80:
    // 0x80379A80: lhu         $t4, 0x6($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X6);
    // 0x80379A84: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80379A88: beql        $t5, $zero, L_80379ABC
    if (ctx->r13 == 0) {
        // 0x80379A8C: lhu         $t8, 0x4($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0X4);
            goto L_80379ABC;
    }
    goto skip_1;
    // 0x80379A8C: lhu         $t8, 0x4($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X4);
    skip_1:
    // 0x80379A90: lhu         $t6, 0x4($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X4);
    // 0x80379A94: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80379A98: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x80379A9C: beq         $at, $zero, L_80379AAC
    if (ctx->r1 == 0) {
        // 0x80379AA0: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_80379AAC;
    }
    // 0x80379AA0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379AA4: b           L_80379ADC
    // 0x80379AA8: sb          $t7, -0x56C3($at)
    MEM_B(-0X56C3, ctx->r1) = ctx->r15;
        goto L_80379ADC;
    // 0x80379AA8: sb          $t7, -0x56C3($at)
    MEM_B(-0X56C3, ctx->r1) = ctx->r15;
L_80379AAC:
    // 0x80379AAC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379AB0: b           L_80379ADC
    // 0x80379AB4: sb          $zero, -0x56C3($at)
    MEM_B(-0X56C3, ctx->r1) = 0;
        goto L_80379ADC;
    // 0x80379AB4: sb          $zero, -0x56C3($at)
    MEM_B(-0X56C3, ctx->r1) = 0;
    // 0x80379AB8: lhu         $t8, 0x4($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X4);
L_80379ABC:
    // 0x80379ABC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80379AC0: slti        $at, $t8, 0xF
    ctx->r1 = SIGNED(ctx->r24) < 0XF ? 1 : 0;
    // 0x80379AC4: beq         $at, $zero, L_80379AD4
    if (ctx->r1 == 0) {
        // 0x80379AC8: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_80379AD4;
    }
    // 0x80379AC8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379ACC: b           L_80379ADC
    // 0x80379AD0: sb          $zero, -0x56C3($at)
    MEM_B(-0X56C3, ctx->r1) = 0;
        goto L_80379ADC;
    // 0x80379AD0: sb          $zero, -0x56C3($at)
    MEM_B(-0X56C3, ctx->r1) = 0;
L_80379AD4:
    // 0x80379AD4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379AD8: sb          $t9, -0x56C3($at)
    MEM_B(-0X56C3, ctx->r1) = ctx->r25;
L_80379ADC:
    // 0x80379ADC: jal         0x800113D0
    // 0x80379AE0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x800113D0)(rdram, ctx);
        goto after_1;
    // 0x80379AE0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80379AE4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80379AE8: jal         0x80011198
    // 0x80379AEC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80011198)(rdram, ctx);
        goto after_2;
    // 0x80379AEC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80379AF0: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80379AF4: addiu       $a1, $a1, -0x4DC0
    ctx->r5 = ADD32(ctx->r5, -0X4DC0);
    // 0x80379AF8: jal         0x800058DC
    // 0x80379AFC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80379AFC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80379B00: b           L_80379EF8
    // 0x80379B04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80379EF8;
    // 0x80379B04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80379B08:
    // 0x80379B08: jal         0x800113D0
    // 0x80379B0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x800113D0)(rdram, ctx);
        goto after_4;
    // 0x80379B0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80379B10: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80379B14: lhu         $t0, -0x3520($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X3520);
    // 0x80379B18: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x80379B1C: lbu         $t2, 0x4010($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4010);
    // 0x80379B20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80379B24: andi        $t1, $t0, 0xFEFF
    ctx->r9 = ctx->r8 & 0XFEFF;
    // 0x80379B28: beq         $t2, $zero, L_80379B38
    if (ctx->r10 == 0) {
        // 0x80379B2C: sh          $t1, -0x3520($at)
        MEM_H(-0X3520, ctx->r1) = ctx->r9;
            goto L_80379B38;
    }
    // 0x80379B2C: sh          $t1, -0x3520($at)
    MEM_H(-0X3520, ctx->r1) = ctx->r9;
    // 0x80379B30: jal         0x801BF1A0
    // 0x80379B34: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x801BF1A0)(rdram, ctx);
        goto after_5;
    // 0x80379B34: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_5:
L_80379B38:
    // 0x80379B38: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80379B3C: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80379B40: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80379B44: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x80379B48: addiu       $a1, $a1, -0x56D0
    ctx->r5 = ADD32(ctx->r5, -0X56D0);
    // 0x80379B4C: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x80379B50: ori         $t6, $t4, 0x20
    ctx->r14 = ctx->r12 | 0X20;
    // 0x80379B54: sw          $t4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r12;
    // 0x80379B58: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80379B5C: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x80379B60: sw          $t8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r24;
    // 0x80379B64: lwc1        $f14, 0x8($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80379B68: jal         0x8001EF38
    // 0x80379B6C: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_6;
    // 0x80379B6C: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    after_6:
    // 0x80379B70: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80379B74: lw          $t9, -0x4330($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4330);
    // 0x80379B78: addiu       $t5, $v0, 0x1000
    ctx->r13 = ADD32(ctx->r2, 0X1000);
    // 0x80379B7C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80379B80: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80379B84: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80379B88: addiu       $a1, $a1, -0x56D0
    ctx->r5 = ADD32(ctx->r5, -0X56D0);
    // 0x80379B8C: lh          $t1, 0x12($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X12);
    // 0x80379B90: addiu       $v0, $v0, -0x7594
    ctx->r2 = ADD32(ctx->r2, -0X7594);
    // 0x80379B94: subu        $a0, $t1, $t5
    ctx->r4 = SUB32(ctx->r9, ctx->r13);
    // 0x80379B98: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80379B9C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80379BA0: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80379BA4: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80379BA8: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x80379BAC: beql        $at, $zero, L_80379BC0
    if (ctx->r1 == 0) {
        // 0x80379BB0: slti        $at, $v1, 0xC00
        ctx->r1 = SIGNED(ctx->r3) < 0XC00 ? 1 : 0;
            goto L_80379BC0;
    }
    goto skip_2;
    // 0x80379BB0: slti        $at, $v1, 0xC00
    ctx->r1 = SIGNED(ctx->r3) < 0XC00 ? 1 : 0;
    skip_2:
    // 0x80379BB4: b           L_80379C2C
    // 0x80379BB8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_80379C2C;
    // 0x80379BB8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80379BBC: slti        $at, $v1, 0xC00
    ctx->r1 = SIGNED(ctx->r3) < 0XC00 ? 1 : 0;
L_80379BC0:
    // 0x80379BC0: beq         $at, $zero, L_80379BDC
    if (ctx->r1 == 0) {
        // 0x80379BC4: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_80379BDC;
    }
    // 0x80379BC4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80379BC8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379BCC: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80379BD0: addiu       $v0, $v0, -0x7594
    ctx->r2 = ADD32(ctx->r2, -0X7594);
    // 0x80379BD4: b           L_80379C2C
    // 0x80379BD8: sb          $t6, -0x7594($at)
    MEM_B(-0X7594, ctx->r1) = ctx->r14;
        goto L_80379C2C;
    // 0x80379BD8: sb          $t6, -0x7594($at)
    MEM_B(-0X7594, ctx->r1) = ctx->r14;
L_80379BDC:
    // 0x80379BDC: slti        $at, $v1, 0x1400
    ctx->r1 = SIGNED(ctx->r3) < 0X1400 ? 1 : 0;
    // 0x80379BE0: beq         $at, $zero, L_80379BFC
    if (ctx->r1 == 0) {
        // 0x80379BE4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80379BFC;
    }
    // 0x80379BE4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80379BE8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379BEC: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80379BF0: addiu       $v0, $v0, -0x7594
    ctx->r2 = ADD32(ctx->r2, -0X7594);
    // 0x80379BF4: b           L_80379C2C
    // 0x80379BF8: sb          $t7, -0x7594($at)
    MEM_B(-0X7594, ctx->r1) = ctx->r15;
        goto L_80379C2C;
    // 0x80379BF8: sb          $t7, -0x7594($at)
    MEM_B(-0X7594, ctx->r1) = ctx->r15;
L_80379BFC:
    // 0x80379BFC: slti        $at, $v1, 0x1C00
    ctx->r1 = SIGNED(ctx->r3) < 0X1C00 ? 1 : 0;
    // 0x80379C00: beq         $at, $zero, L_80379C20
    if (ctx->r1 == 0) {
        // 0x80379C04: lui         $v0, 0x8039
        ctx->r2 = S32(0X8039 << 16);
            goto L_80379C20;
    }
    // 0x80379C04: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80379C08: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80379C0C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379C10: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80379C14: addiu       $v0, $v0, -0x7594
    ctx->r2 = ADD32(ctx->r2, -0X7594);
    // 0x80379C18: b           L_80379C2C
    // 0x80379C1C: sb          $t8, -0x7594($at)
    MEM_B(-0X7594, ctx->r1) = ctx->r24;
        goto L_80379C2C;
    // 0x80379C1C: sb          $t8, -0x7594($at)
    MEM_B(-0X7594, ctx->r1) = ctx->r24;
L_80379C20:
    // 0x80379C20: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379C24: sb          $zero, -0x7594($at)
    MEM_B(-0X7594, ctx->r1) = 0;
    // 0x80379C28: addiu       $v0, $v0, -0x7594
    ctx->r2 = ADD32(ctx->r2, -0X7594);
L_80379C2C:
    // 0x80379C2C: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80379C30: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80379C34: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80379C38: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80379C3C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80379C40: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80379C44: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80379C48: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x80379C4C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80379C50: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80379C54: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x80379C58: nop

    // 0x80379C5C: bc1fl       L_80379C74
    if (!c1cs) {
        // 0x80379C60: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80379C74;
    }
    goto skip_3;
    // 0x80379C60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_3:
    // 0x80379C64: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80379C68: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80379C6C: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x80379C70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80379C74:
    // 0x80379C74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80379C78: jal         0x801C4A5C
    // 0x80379C7C: sw          $t2, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r10;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_7;
    // 0x80379C7C: sw          $t2, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r10;
    after_7:
    // 0x80379C80: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80379C84: lbu         $t3, -0x7594($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X7594);
    // 0x80379C88: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80379C8C: beq         $at, $zero, L_80379CA8
    if (ctx->r1 == 0) {
        // 0x80379C90: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80379CA8;
    }
    // 0x80379C90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80379C94: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80379C98: jal         0x801518D4
    // 0x80379C9C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_8;
    // 0x80379C9C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_8:
    // 0x80379CA0: b           L_80379CBC
    // 0x80379CA4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
        goto L_80379CBC;
    // 0x80379CA4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80379CA8:
    // 0x80379CA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80379CAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80379CB0: jal         0x801518D4
    // 0x80379CB4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_9;
    // 0x80379CB4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_9:
    // 0x80379CB8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80379CBC:
    // 0x80379CBC: jal         0x80011198
    // 0x80379CC0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80011198)(rdram, ctx);
        goto after_10;
    // 0x80379CC0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x80379CC4: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x80379CC8: lbu         $t4, -0x7594($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X7594);
    // 0x80379CCC: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x80379CD0: beq         $at, $zero, L_80379EE4
    if (ctx->r1 == 0) {
        // 0x80379CD4: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80379EE4;
    }
    // 0x80379CD4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80379CD8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379CDC: addu        $at, $at, $t4
    gpr jr_addend_80379CE4 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80379CE0: lw          $t4, -0x6840($at)
    ctx->r12 = ADD32(ctx->r1, -0X6840);
    // 0x80379CE4: jr          $t4
    // 0x80379CE8: nop

    switch (jr_addend_80379CE4 >> 2) {
        case 0: goto L_80379CEC; break;
        case 1: goto L_80379D2C; break;
        case 2: goto L_80379D6C; break;
        case 3: goto L_80379DAC; break;
        case 4: goto L_80379DEC; break;
        case 5: goto L_80379E2C; break;
        case 6: goto L_80379E6C; break;
        case 7: goto L_80379EAC; break;
        default: switch_error(__func__, 0x80379CE4, 0x803897C0);
    }
    // 0x80379CE8: nop

L_80379CEC:
    // 0x80379CEC: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80379CF0: addiu       $t1, $t1, -0x7640
    ctx->r9 = ADD32(ctx->r9, -0X7640);
    // 0x80379CF4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80379CF8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80379CFC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80379D00: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x80379D04: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x80379D08: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80379D0C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80379D10: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80379D14: lw          $t6, 0x8($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X8);
    // 0x80379D18: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80379D1C: jal         0x80011140
    // 0x80379D20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_11;
    // 0x80379D20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_11:
    // 0x80379D24: b           L_80379EE4
    // 0x80379D28: nop

        goto L_80379EE4;
    // 0x80379D28: nop

L_80379D2C:
    // 0x80379D2C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80379D30: addiu       $t8, $t8, -0x7634
    ctx->r24 = ADD32(ctx->r24, -0X7634);
    // 0x80379D34: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80379D38: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80379D3C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80379D40: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x80379D44: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x80379D48: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80379D4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80379D50: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80379D54: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80379D58: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80379D5C: jal         0x80011140
    // 0x80379D60: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_12;
    // 0x80379D60: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_12:
    // 0x80379D64: b           L_80379EE4
    // 0x80379D68: nop

        goto L_80379EE4;
    // 0x80379D68: nop

L_80379D6C:
    // 0x80379D6C: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80379D70: addiu       $t3, $t3, -0x7628
    ctx->r11 = ADD32(ctx->r11, -0X7628);
    // 0x80379D74: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x80379D78: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80379D7C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80379D80: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x80379D84: lw          $a3, 0x4($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4);
    // 0x80379D88: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80379D8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80379D90: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80379D94: lw          $t1, 0x8($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X8);
    // 0x80379D98: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80379D9C: jal         0x80011140
    // 0x80379DA0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_13;
    // 0x80379DA0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_13:
    // 0x80379DA4: b           L_80379EE4
    // 0x80379DA8: nop

        goto L_80379EE4;
    // 0x80379DA8: nop

L_80379DAC:
    // 0x80379DAC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80379DB0: addiu       $t6, $t6, -0x761C
    ctx->r14 = ADD32(ctx->r14, -0X761C);
    // 0x80379DB4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80379DB8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80379DBC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80379DC0: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x80379DC4: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x80379DC8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80379DCC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80379DD0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80379DD4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80379DD8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80379DDC: jal         0x80011140
    // 0x80379DE0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_14;
    // 0x80379DE0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_14:
    // 0x80379DE4: b           L_80379EE4
    // 0x80379DE8: nop

        goto L_80379EE4;
    // 0x80379DE8: nop

L_80379DEC:
    // 0x80379DEC: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80379DF0: addiu       $t0, $t0, -0x7610
    ctx->r8 = ADD32(ctx->r8, -0X7610);
    // 0x80379DF4: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80379DF8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80379DFC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80379E00: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x80379E04: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x80379E08: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80379E0C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80379E10: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80379E14: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x80379E18: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80379E1C: jal         0x80011140
    // 0x80379E20: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_15;
    // 0x80379E20: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_15:
    // 0x80379E24: b           L_80379EE4
    // 0x80379E28: nop

        goto L_80379EE4;
    // 0x80379E28: nop

L_80379E2C:
    // 0x80379E2C: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80379E30: addiu       $t1, $t1, -0x7604
    ctx->r9 = ADD32(ctx->r9, -0X7604);
    // 0x80379E34: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80379E38: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80379E3C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80379E40: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x80379E44: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x80379E48: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80379E4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80379E50: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80379E54: lw          $t6, 0x8($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X8);
    // 0x80379E58: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80379E5C: jal         0x80011140
    // 0x80379E60: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_16;
    // 0x80379E60: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_16:
    // 0x80379E64: b           L_80379EE4
    // 0x80379E68: nop

        goto L_80379EE4;
    // 0x80379E68: nop

L_80379E6C:
    // 0x80379E6C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80379E70: addiu       $t8, $t8, -0x75F8
    ctx->r24 = ADD32(ctx->r24, -0X75F8);
    // 0x80379E74: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80379E78: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80379E7C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80379E80: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x80379E84: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x80379E88: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80379E8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80379E90: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80379E94: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80379E98: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80379E9C: jal         0x80011140
    // 0x80379EA0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_17;
    // 0x80379EA0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_17:
    // 0x80379EA4: b           L_80379EE4
    // 0x80379EA8: nop

        goto L_80379EE4;
    // 0x80379EA8: nop

L_80379EAC:
    // 0x80379EAC: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80379EB0: addiu       $t3, $t3, -0x75EC
    ctx->r11 = ADD32(ctx->r11, -0X75EC);
    // 0x80379EB4: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x80379EB8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80379EBC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80379EC0: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x80379EC4: lw          $a3, 0x4($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4);
    // 0x80379EC8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80379ECC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80379ED0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80379ED4: lw          $t1, 0x8($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X8);
    // 0x80379ED8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80379EDC: jal         0x80011140
    // 0x80379EE0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_18;
    // 0x80379EE0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_18:
L_80379EE4:
    // 0x80379EE4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80379EE8: addiu       $a1, $a1, -0x60FC
    ctx->r5 = ADD32(ctx->r5, -0X60FC);
    // 0x80379EEC: jal         0x800058DC
    // 0x80379EF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_19;
    // 0x80379EF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_19:
    // 0x80379EF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80379EF8:
    // 0x80379EF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80379EFC: jr          $ra
    // 0x80379F00: nop

    return;
    // 0x80379F00: nop

;}
RECOMP_FUNC void M55_FUN_80379f04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379F04: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80379F08: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80379F0C: lbu         $t7, -0x7594($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X7594);
    // 0x80379F10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80379F14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80379F18: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80379F1C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80379F20: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80379F24: beq         $at, $zero, L_8037A200
    if (ctx->r1 == 0) {
        // 0x80379F28: lw          $s0, 0x5C($a0)
        ctx->r16 = MEM_W(ctx->r4, 0X5C);
            goto L_8037A200;
    }
    // 0x80379F28: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x80379F2C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80379F30: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379F34: addu        $at, $at, $t7
    gpr jr_addend_80379F3C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80379F38: lw          $t7, -0x6820($at)
    ctx->r15 = ADD32(ctx->r1, -0X6820);
    // 0x80379F3C: jr          $t7
    // 0x80379F40: nop

    switch (jr_addend_80379F3C >> 2) {
        case 0: goto L_80379F44; break;
        case 1: goto L_80379F9C; break;
        case 2: goto L_80379FF4; break;
        case 3: goto L_8037A04C; break;
        case 4: goto L_8037A0A4; break;
        case 5: goto L_8037A0FC; break;
        case 6: goto L_8037A154; break;
        case 7: goto L_8037A1AC; break;
        default: switch_error(__func__, 0x80379F3C, 0x803897E0);
    }
    // 0x80379F40: nop

L_80379F44:
    // 0x80379F44: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80379F48: addiu       $t8, $t8, -0x7640
    ctx->r24 = ADD32(ctx->r24, -0X7640);
    // 0x80379F4C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80379F50: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80379F54: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80379F58: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x80379F5C: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x80379F60: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80379F64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80379F68: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80379F6C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80379F70: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80379F74: jal         0x80011140
    // 0x80379F78: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_0;
    // 0x80379F78: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x80379F7C: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    // 0x80379F80: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80379F84: lui         $a0, 0x190
    ctx->r4 = S32(0X190 << 16);
    // 0x80379F88: ori         $a0, $a0, 0x45
    ctx->r4 = ctx->r4 | 0X45;
    // 0x80379F8C: beql        $a0, $t2, L_8037A204
    if (ctx->r4 == ctx->r10) {
        // 0x80379F90: addiu       $v1, $s0, 0x1C
        ctx->r3 = ADD32(ctx->r16, 0X1C);
            goto L_8037A204;
    }
    goto skip_0;
    // 0x80379F90: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    skip_0:
    // 0x80379F94: b           L_8037A200
    // 0x80379F98: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8037A200;
    // 0x80379F98: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80379F9C:
    // 0x80379F9C: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80379FA0: addiu       $t3, $t3, -0x7634
    ctx->r11 = ADD32(ctx->r11, -0X7634);
    // 0x80379FA4: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80379FA8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80379FAC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80379FB0: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x80379FB4: lw          $a3, 0x4($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4);
    // 0x80379FB8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80379FBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80379FC0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80379FC4: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80379FC8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80379FCC: jal         0x80011140
    // 0x80379FD0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_1;
    // 0x80379FD0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_1:
    // 0x80379FD4: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    // 0x80379FD8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80379FDC: lui         $a0, 0x190
    ctx->r4 = S32(0X190 << 16);
    // 0x80379FE0: ori         $a0, $a0, 0x46
    ctx->r4 = ctx->r4 | 0X46;
    // 0x80379FE4: beql        $a0, $t7, L_8037A204
    if (ctx->r4 == ctx->r15) {
        // 0x80379FE8: addiu       $v1, $s0, 0x1C
        ctx->r3 = ADD32(ctx->r16, 0X1C);
            goto L_8037A204;
    }
    goto skip_1;
    // 0x80379FE8: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    skip_1:
    // 0x80379FEC: b           L_8037A200
    // 0x80379FF0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8037A200;
    // 0x80379FF0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80379FF4:
    // 0x80379FF4: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80379FF8: addiu       $t8, $t8, -0x7628
    ctx->r24 = ADD32(ctx->r24, -0X7628);
    // 0x80379FFC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8037A000: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8037A004: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8037A008: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x8037A00C: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x8037A010: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037A014: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8037A018: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037A01C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8037A020: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8037A024: jal         0x80011140
    // 0x8037A028: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_2;
    // 0x8037A028: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x8037A02C: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    // 0x8037A030: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8037A034: lui         $a0, 0x190
    ctx->r4 = S32(0X190 << 16);
    // 0x8037A038: ori         $a0, $a0, 0x48
    ctx->r4 = ctx->r4 | 0X48;
    // 0x8037A03C: beql        $a0, $t2, L_8037A204
    if (ctx->r4 == ctx->r10) {
        // 0x8037A040: addiu       $v1, $s0, 0x1C
        ctx->r3 = ADD32(ctx->r16, 0X1C);
            goto L_8037A204;
    }
    goto skip_2;
    // 0x8037A040: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    skip_2:
    // 0x8037A044: b           L_8037A200
    // 0x8037A048: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8037A200;
    // 0x8037A048: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8037A04C:
    // 0x8037A04C: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x8037A050: addiu       $t3, $t3, -0x761C
    ctx->r11 = ADD32(ctx->r11, -0X761C);
    // 0x8037A054: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8037A058: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8037A05C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8037A060: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x8037A064: lw          $a3, 0x4($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4);
    // 0x8037A068: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037A06C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8037A070: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037A074: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8037A078: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8037A07C: jal         0x80011140
    // 0x8037A080: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_3;
    // 0x8037A080: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x8037A084: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    // 0x8037A088: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8037A08C: lui         $a0, 0x190
    ctx->r4 = S32(0X190 << 16);
    // 0x8037A090: ori         $a0, $a0, 0x47
    ctx->r4 = ctx->r4 | 0X47;
    // 0x8037A094: beql        $a0, $t7, L_8037A204
    if (ctx->r4 == ctx->r15) {
        // 0x8037A098: addiu       $v1, $s0, 0x1C
        ctx->r3 = ADD32(ctx->r16, 0X1C);
            goto L_8037A204;
    }
    goto skip_3;
    // 0x8037A098: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    skip_3:
    // 0x8037A09C: b           L_8037A200
    // 0x8037A0A0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8037A200;
    // 0x8037A0A0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8037A0A4:
    // 0x8037A0A4: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037A0A8: addiu       $t8, $t8, -0x7610
    ctx->r24 = ADD32(ctx->r24, -0X7610);
    // 0x8037A0AC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8037A0B0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8037A0B4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8037A0B8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x8037A0BC: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x8037A0C0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037A0C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8037A0C8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037A0CC: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8037A0D0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8037A0D4: jal         0x80011140
    // 0x8037A0D8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x8037A0D8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_4:
    // 0x8037A0DC: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    // 0x8037A0E0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8037A0E4: lui         $a0, 0x190
    ctx->r4 = S32(0X190 << 16);
    // 0x8037A0E8: ori         $a0, $a0, 0x49
    ctx->r4 = ctx->r4 | 0X49;
    // 0x8037A0EC: beql        $a0, $t2, L_8037A204
    if (ctx->r4 == ctx->r10) {
        // 0x8037A0F0: addiu       $v1, $s0, 0x1C
        ctx->r3 = ADD32(ctx->r16, 0X1C);
            goto L_8037A204;
    }
    goto skip_4;
    // 0x8037A0F0: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    skip_4:
    // 0x8037A0F4: b           L_8037A200
    // 0x8037A0F8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8037A200;
    // 0x8037A0F8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8037A0FC:
    // 0x8037A0FC: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x8037A100: addiu       $t3, $t3, -0x7604
    ctx->r11 = ADD32(ctx->r11, -0X7604);
    // 0x8037A104: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8037A108: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8037A10C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8037A110: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x8037A114: lw          $a3, 0x4($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4);
    // 0x8037A118: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037A11C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8037A120: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037A124: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8037A128: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8037A12C: jal         0x80011140
    // 0x8037A130: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_5;
    // 0x8037A130: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_5:
    // 0x8037A134: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    // 0x8037A138: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8037A13C: lui         $a0, 0x190
    ctx->r4 = S32(0X190 << 16);
    // 0x8037A140: ori         $a0, $a0, 0x4A
    ctx->r4 = ctx->r4 | 0X4A;
    // 0x8037A144: beql        $a0, $t7, L_8037A204
    if (ctx->r4 == ctx->r15) {
        // 0x8037A148: addiu       $v1, $s0, 0x1C
        ctx->r3 = ADD32(ctx->r16, 0X1C);
            goto L_8037A204;
    }
    goto skip_5;
    // 0x8037A148: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    skip_5:
    // 0x8037A14C: b           L_8037A200
    // 0x8037A150: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8037A200;
    // 0x8037A150: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8037A154:
    // 0x8037A154: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037A158: addiu       $t8, $t8, -0x75F8
    ctx->r24 = ADD32(ctx->r24, -0X75F8);
    // 0x8037A15C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8037A160: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8037A164: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8037A168: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x8037A16C: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x8037A170: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037A174: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8037A178: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037A17C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8037A180: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8037A184: jal         0x80011140
    // 0x8037A188: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_6;
    // 0x8037A188: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_6:
    // 0x8037A18C: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    // 0x8037A190: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8037A194: lui         $a0, 0x190
    ctx->r4 = S32(0X190 << 16);
    // 0x8037A198: ori         $a0, $a0, 0x4C
    ctx->r4 = ctx->r4 | 0X4C;
    // 0x8037A19C: beql        $a0, $t2, L_8037A204
    if (ctx->r4 == ctx->r10) {
        // 0x8037A1A0: addiu       $v1, $s0, 0x1C
        ctx->r3 = ADD32(ctx->r16, 0X1C);
            goto L_8037A204;
    }
    goto skip_6;
    // 0x8037A1A0: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    skip_6:
    // 0x8037A1A4: b           L_8037A200
    // 0x8037A1A8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_8037A200;
    // 0x8037A1A8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8037A1AC:
    // 0x8037A1AC: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x8037A1B0: addiu       $t3, $t3, -0x75EC
    ctx->r11 = ADD32(ctx->r11, -0X75EC);
    // 0x8037A1B4: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8037A1B8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8037A1BC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8037A1C0: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x8037A1C4: lw          $a3, 0x4($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4);
    // 0x8037A1C8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037A1CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8037A1D0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037A1D4: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8037A1D8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8037A1DC: jal         0x80011140
    // 0x8037A1E0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_7;
    // 0x8037A1E0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_7:
    // 0x8037A1E4: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    // 0x8037A1E8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8037A1EC: lui         $a0, 0x190
    ctx->r4 = S32(0X190 << 16);
    // 0x8037A1F0: ori         $a0, $a0, 0x4B
    ctx->r4 = ctx->r4 | 0X4B;
    // 0x8037A1F4: beql        $a0, $t7, L_8037A204
    if (ctx->r4 == ctx->r15) {
        // 0x8037A1F8: addiu       $v1, $s0, 0x1C
        ctx->r3 = ADD32(ctx->r16, 0X1C);
            goto L_8037A204;
    }
    goto skip_7;
    // 0x8037A1F8: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    skip_7:
    // 0x8037A1FC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8037A200:
    // 0x8037A200: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
L_8037A204:
    // 0x8037A204: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x8037A208: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x8037A20C: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x8037A210: addiu       $a1, $a1, 0x76F0
    ctx->r5 = ADD32(ctx->r5, 0X76F0);
    // 0x8037A214: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8037A218: jal         0x80005670
    // 0x8037A21C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_8;
    // 0x8037A21C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x8037A220: beq         $v0, $zero, L_8037A240
    if (ctx->r2 == 0) {
        // 0x8037A224: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_8037A240;
    }
    // 0x8037A224: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8037A228: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8037A22C: addiu       $a1, $a1, -0x7598
    ctx->r5 = ADD32(ctx->r5, -0X7598);
    // 0x8037A230: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x8037A234: sb          $zero, 0x96($v0)
    MEM_B(0X96, ctx->r2) = 0;
    // 0x8037A238: sb          $zero, 0x97($v0)
    MEM_B(0X97, ctx->r2) = 0;
    // 0x8037A23C: sh          $t8, 0x94($v0)
    MEM_H(0X94, ctx->r2) = ctx->r24;
L_8037A240:
    // 0x8037A240: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8037A244: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8037A248: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037A24C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8037A250: addiu       $v0, $v0, -0x56D0
    ctx->r2 = ADD32(ctx->r2, -0X56D0);
    // 0x8037A254: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8037A258: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8037A25C: sw          $t1, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->r9;
    // 0x8037A260: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8037A264: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8037A268: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8037A26C: addiu       $a1, $a1, -0x7598
    ctx->r5 = ADD32(ctx->r5, -0X7598);
    // 0x8037A270: swc1        $f4, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f4.u32l;
    // 0x8037A274: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8037A278: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8037A27C: addiu       $a0, $a0, -0x23C0
    ctx->r4 = ADD32(ctx->r4, -0X23C0);
    // 0x8037A280: swc1        $f6, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f6.u32l;
    // 0x8037A284: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8037A288: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8037A28C: swc1        $f8, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f8.u32l;
    // 0x8037A290: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x8037A294: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x8037A298: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8037A29C: beq         $at, $zero, L_8037A2C4
    if (ctx->r1 == 0) {
        // 0x8037A2A0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8037A2C4;
    }
    // 0x8037A2A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8037A2A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8037A2A8: nop

    // 0x8037A2AC: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x8037A2B0: lhu         $t7, 0x2($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X2);
    // 0x8037A2B4: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x8037A2B8: subu        $t0, $t7, $t8
    ctx->r8 = SUB32(ctx->r15, ctx->r24);
    // 0x8037A2BC: b           L_8037A2D8
    // 0x8037A2C0: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
        goto L_8037A2D8;
    // 0x8037A2C0: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
L_8037A2C4:
    // 0x8037A2C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8037A2C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8037A2CC: nop

    // 0x8037A2D0: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x8037A2D4: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
L_8037A2D8:
    // 0x8037A2D8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8037A2DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8037A2E0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8037A2E4: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x8037A2E8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8037A2EC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037A2F0: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x8037A2F4: jal         0x8013A28C
    // 0x8037A2F8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_9;
    // 0x8037A2F8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_9:
    // 0x8037A2FC: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037A300: addiu       $a1, $a1, -0x5CE0
    ctx->r5 = ADD32(ctx->r5, -0X5CE0);
    // 0x8037A304: jal         0x800058DC
    // 0x8037A308: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x8037A308: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_10:
    // 0x8037A30C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037A310: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8037A314: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8037A318: jr          $ra
    // 0x8037A31C: nop

    return;
    // 0x8037A31C: nop

;}
RECOMP_FUNC void M55_FUN_8037a320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A320: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8037A324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037A328: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8037A32C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8037A330: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x8037A334: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8037A338: jal         0x80010550
    // 0x8037A33C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x8037A33C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8037A340: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8037A344: jal         0x8037B9F0
    // 0x8037A348: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x8037B9F0)(rdram, ctx);
        goto after_1;
    // 0x8037A348: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8037A34C: bne         $v0, $zero, L_8037A6E4
    if (ctx->r2 != 0) {
        // 0x8037A350: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_8037A6E4;
    }
    // 0x8037A350: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8037A354: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8037A358: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8037A35C: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8037A360: beql        $t9, $zero, L_8037A4E0
    if (ctx->r25 == 0) {
        // 0x8037A364: lhu         $t0, 0x26($sp)
        ctx->r8 = MEM_HU(ctx->r29, 0X26);
            goto L_8037A4E0;
    }
    goto skip_0;
    // 0x8037A364: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    skip_0:
    // 0x8037A368: lw          $t0, -0x4330($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4330);
    // 0x8037A36C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8037A370: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8037A374: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x8037A378: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8037A37C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8037A380: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8037A384: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8037A388: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8037A38C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8037A390: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8037A394: sub.d       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f0.d - ctx->f10.d;
    // 0x8037A398: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8037A39C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8037A3A0: add.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d + ctx->f6.d;
    // 0x8037A3A4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8037A3A8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8037A3AC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8037A3B0: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x8037A3B4: jal         0x801C5A1C
    // 0x8037A3B8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_2;
    // 0x8037A3B8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8037A3BC: bne         $v0, $zero, L_8037A4C8
    if (ctx->r2 != 0) {
        // 0x8037A3C0: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_8037A4C8;
    }
    // 0x8037A3C0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8037A3C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8037A3C8: jal         0x801DFAA4
    // 0x8037A3CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801DFAA4)(rdram, ctx);
        goto after_3;
    // 0x8037A3CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8037A3D0: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037A3D4: lbu         $t1, -0x7594($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X7594);
    // 0x8037A3D8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8037A3DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8037A3E0: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8037A3E4: beq         $at, $zero, L_8037A400
    if (ctx->r1 == 0) {
        // 0x8037A3E8: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8037A400;
    }
    // 0x8037A3E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8037A3EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8037A3F0: jal         0x801518D4
    // 0x8037A3F4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_4;
    // 0x8037A3F4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_4:
    // 0x8037A3F8: b           L_8037A408
    // 0x8037A3FC: nop

        goto L_8037A408;
    // 0x8037A3FC: nop

L_8037A400:
    // 0x8037A400: jal         0x801518D4
    // 0x8037A404: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_5;
    // 0x8037A404: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_5:
L_8037A408:
    // 0x8037A408: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037A40C: lbu         $v0, -0x7594($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7594);
    // 0x8037A410: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037A414: beq         $v0, $at, L_8037A434
    if (ctx->r2 == ctx->r1) {
        // 0x8037A418: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8037A434;
    }
    // 0x8037A418: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037A41C: beq         $v0, $at, L_8037A434
    if (ctx->r2 == ctx->r1) {
        // 0x8037A420: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8037A434;
    }
    // 0x8037A420: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8037A424: beq         $v0, $at, L_8037A434
    if (ctx->r2 == ctx->r1) {
        // 0x8037A428: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8037A434;
    }
    // 0x8037A428: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8037A42C: bnel        $v0, $at, L_8037A450
    if (ctx->r2 != ctx->r1) {
        // 0x8037A430: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_8037A450;
    }
    goto skip_1;
    // 0x8037A430: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_1:
L_8037A434:
    // 0x8037A434: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8037A438: lui         $t2, 0x190
    ctx->r10 = S32(0X190 << 16);
    // 0x8037A43C: ori         $t2, $t2, 0x6D
    ctx->r10 = ctx->r10 | 0X6D;
    // 0x8037A440: sw          $t2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r10;
    // 0x8037A444: b           L_8037A460
    // 0x8037A448: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
        goto L_8037A460;
    // 0x8037A448: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8037A44C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_8037A450:
    // 0x8037A450: lui         $t3, 0x190
    ctx->r11 = S32(0X190 << 16);
    // 0x8037A454: ori         $t3, $t3, 0x6A
    ctx->r11 = ctx->r11 | 0X6A;
    // 0x8037A458: sw          $t3, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r11;
    // 0x8037A45C: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
L_8037A460:
    // 0x8037A460: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8037A464: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8037A468: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x8037A46C: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8037A470: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8037A474: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8037A478: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8037A47C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037A480: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8037A484: jal         0x8013A28C
    // 0x8037A488: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_6;
    // 0x8037A488: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_6:
    // 0x8037A48C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037A490: addiu       $v0, $v0, -0x7594
    ctx->r2 = ADD32(ctx->r2, -0X7594);
    // 0x8037A494: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8037A498: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037A49C: addiu       $a1, $a1, -0x53F8
    ctx->r5 = ADD32(ctx->r5, -0X53F8);
    // 0x8037A4A0: bgez        $t6, L_8037A4B4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8037A4A4: andi        $t7, $t6, 0x3
        ctx->r15 = ctx->r14 & 0X3;
            goto L_8037A4B4;
    }
    // 0x8037A4A4: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x8037A4A8: beq         $t7, $zero, L_8037A4B4
    if (ctx->r15 == 0) {
        // 0x8037A4AC: nop
    
            goto L_8037A4B4;
    }
    // 0x8037A4AC: nop

    // 0x8037A4B0: addiu       $t7, $t7, -0x4
    ctx->r15 = ADD32(ctx->r15, -0X4);
L_8037A4B4:
    // 0x8037A4B4: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8037A4B8: jal         0x800058DC
    // 0x8037A4BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x8037A4BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x8037A4C0: b           L_8037A6E8
    // 0x8037A4C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8037A6E8;
    // 0x8037A4C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037A4C8:
    // 0x8037A4C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8037A4CC: nop

    // 0x8037A4D0: swc1        $f0, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f0.u32l;
    // 0x8037A4D4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8037A4D8: swc1        $f0, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f0.u32l;
    // 0x8037A4DC: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
L_8037A4E0:
    // 0x8037A4E0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8037A4E4: beql        $t0, $zero, L_8037A6E8
    if (ctx->r8 == 0) {
        // 0x8037A4E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037A6E8;
    }
    goto skip_2;
    // 0x8037A4E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8037A4EC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8037A4F0: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8037A4F4: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x8037A4F8: beql        $t3, $zero, L_8037A6E8
    if (ctx->r11 == 0) {
        // 0x8037A4FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037A6E8;
    }
    goto skip_3;
    // 0x8037A4FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8037A500: lbu         $t4, -0x7594($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X7594);
    // 0x8037A504: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8037A508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8037A50C: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x8037A510: beq         $at, $zero, L_8037A52C
    if (ctx->r1 == 0) {
        // 0x8037A514: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8037A52C;
    }
    // 0x8037A514: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8037A518: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8037A51C: jal         0x801518D4
    // 0x8037A520: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_8;
    // 0x8037A520: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_8:
    // 0x8037A524: b           L_8037A534
    // 0x8037A528: nop

        goto L_8037A534;
    // 0x8037A528: nop

L_8037A52C:
    // 0x8037A52C: jal         0x801518D4
    // 0x8037A530: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_9;
    // 0x8037A530: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_9:
L_8037A534:
    // 0x8037A534: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037A538: lbu         $v0, -0x7594($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7594);
    // 0x8037A53C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037A540: beq         $v0, $at, L_8037A550
    if (ctx->r2 == ctx->r1) {
        // 0x8037A544: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8037A550;
    }
    // 0x8037A544: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037A548: bnel        $v0, $at, L_8037A56C
    if (ctx->r2 != ctx->r1) {
        // 0x8037A54C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8037A56C;
    }
    goto skip_4;
    // 0x8037A54C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_4:
L_8037A550:
    // 0x8037A550: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8037A554: lui         $t5, 0x190
    ctx->r13 = S32(0X190 << 16);
    // 0x8037A558: ori         $t5, $t5, 0x70
    ctx->r13 = ctx->r13 | 0X70;
    // 0x8037A55C: sw          $t5, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r13;
    // 0x8037A560: b           L_8037A5D4
    // 0x8037A564: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
        goto L_8037A5D4;
    // 0x8037A564: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8037A568: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8037A56C:
    // 0x8037A56C: beq         $v0, $at, L_8037A57C
    if (ctx->r2 == ctx->r1) {
        // 0x8037A570: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8037A57C;
    }
    // 0x8037A570: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8037A574: bnel        $v0, $at, L_8037A598
    if (ctx->r2 != ctx->r1) {
        // 0x8037A578: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8037A598;
    }
    goto skip_5;
    // 0x8037A578: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_5:
L_8037A57C:
    // 0x8037A57C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8037A580: lui         $t6, 0x190
    ctx->r14 = S32(0X190 << 16);
    // 0x8037A584: ori         $t6, $t6, 0x72
    ctx->r14 = ctx->r14 | 0X72;
    // 0x8037A588: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    // 0x8037A58C: b           L_8037A5D4
    // 0x8037A590: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
        goto L_8037A5D4;
    // 0x8037A590: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8037A594: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8037A598:
    // 0x8037A598: beq         $v0, $at, L_8037A5A8
    if (ctx->r2 == ctx->r1) {
        // 0x8037A59C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8037A5A8;
    }
    // 0x8037A59C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8037A5A0: bnel        $v0, $at, L_8037A5C4
    if (ctx->r2 != ctx->r1) {
        // 0x8037A5A4: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_8037A5C4;
    }
    goto skip_6;
    // 0x8037A5A4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_6:
L_8037A5A8:
    // 0x8037A5A8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8037A5AC: lui         $t7, 0x190
    ctx->r15 = S32(0X190 << 16);
    // 0x8037A5B0: ori         $t7, $t7, 0x71
    ctx->r15 = ctx->r15 | 0X71;
    // 0x8037A5B4: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x8037A5B8: b           L_8037A5D4
    // 0x8037A5BC: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
        goto L_8037A5D4;
    // 0x8037A5BC: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8037A5C0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_8037A5C4:
    // 0x8037A5C4: lui         $t8, 0x190
    ctx->r24 = S32(0X190 << 16);
    // 0x8037A5C8: ori         $t8, $t8, 0x6F
    ctx->r24 = ctx->r24 | 0X6F;
    // 0x8037A5CC: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x8037A5D0: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
L_8037A5D4:
    // 0x8037A5D4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8037A5D8: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8037A5DC: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x8037A5E0: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8037A5E4: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8037A5E8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8037A5EC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8037A5F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037A5F4: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8037A5F8: jal         0x8013A28C
    // 0x8037A5FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_10;
    // 0x8037A5FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_10:
    // 0x8037A600: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8037A604: lw          $t1, -0x4330($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4330);
    // 0x8037A608: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8037A60C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8037A610: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x8037A614: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8037A618: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8037A61C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8037A620: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8037A624: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8037A628: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8037A62C: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8037A630: sub.d       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f0.d - ctx->f10.d;
    // 0x8037A634: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8037A638: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8037A63C: add.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d + ctx->f6.d;
    // 0x8037A640: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8037A644: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8037A648: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8037A64C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x8037A650: jal         0x801C5A1C
    // 0x8037A654: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_11;
    // 0x8037A654: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x8037A658: beq         $v0, $zero, L_8037A6A8
    if (ctx->r2 == 0) {
        // 0x8037A65C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8037A6A8;
    }
    // 0x8037A65C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8037A660: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8037A664: lhu         $v0, -0x440C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X440C);
    // 0x8037A668: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x8037A66C: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8037A670: beq         $v0, $at, L_8037A680
    if (ctx->r2 == ctx->r1) {
        // 0x8037A674: addiu       $at, $zero, 0x50
        ctx->r1 = ADD32(0, 0X50);
            goto L_8037A680;
    }
    // 0x8037A674: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x8037A678: bnel        $v0, $at, L_8037A690
    if (ctx->r2 != ctx->r1) {
        // 0x8037A67C: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_8037A690;
    }
    goto skip_7;
    // 0x8037A67C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    skip_7:
L_8037A680:
    // 0x8037A680: lbu         $t2, -0x40B5($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X40B5);
    // 0x8037A684: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x8037A688: beq         $at, $zero, L_8037A6B0
    if (ctx->r1 == 0) {
        // 0x8037A68C: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_8037A6B0;
    }
    // 0x8037A68C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
L_8037A690:
    // 0x8037A690: bne         $v0, $at, L_8037A6A8
    if (ctx->r2 != ctx->r1) {
        // 0x8037A694: lui         $t3, 0x801C
        ctx->r11 = S32(0X801C << 16);
            goto L_8037A6A8;
    }
    // 0x8037A694: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8037A698: lbu         $t3, -0x40B5($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X40B5);
    // 0x8037A69C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037A6A0: beq         $t3, $at, L_8037A6B0
    if (ctx->r11 == ctx->r1) {
        // 0x8037A6A4: nop
    
            goto L_8037A6B0;
    }
    // 0x8037A6A4: nop

L_8037A6A8:
    // 0x8037A6A8: jal         0x801CD228
    // 0x8037A6AC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x801CD228)(rdram, ctx);
        goto after_12;
    // 0x8037A6AC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_12:
L_8037A6B0:
    // 0x8037A6B0: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8037A6B4: lbu         $t4, -0x7594($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X7594);
    // 0x8037A6B8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037A6BC: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037A6C0: bgez        $t4, L_8037A6D4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8037A6C4: andi        $t5, $t4, 0x3
        ctx->r13 = ctx->r12 & 0X3;
            goto L_8037A6D4;
    }
    // 0x8037A6C4: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x8037A6C8: beq         $t5, $zero, L_8037A6D4
    if (ctx->r13 == 0) {
        // 0x8037A6CC: nop
    
            goto L_8037A6D4;
    }
    // 0x8037A6CC: nop

    // 0x8037A6D0: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
L_8037A6D4:
    // 0x8037A6D4: sb          $t5, -0x7594($at)
    MEM_B(-0X7594, ctx->r1) = ctx->r13;
    // 0x8037A6D8: addiu       $a1, $a1, -0x590C
    ctx->r5 = ADD32(ctx->r5, -0X590C);
    // 0x8037A6DC: jal         0x800058DC
    // 0x8037A6E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_13;
    // 0x8037A6E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_13:
L_8037A6E4:
    // 0x8037A6E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037A6E8:
    // 0x8037A6E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8037A6EC: jr          $ra
    // 0x8037A6F0: nop

    return;
    // 0x8037A6F0: nop

;}
RECOMP_FUNC void M55_FUN_8037a6f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A6F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037A6F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037A6FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8037A700: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8037A704: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x8037A708: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037A70C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037A710: lhu         $t6, 0x20($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X20);
    // 0x8037A714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037A718: bne         $t6, $zero, L_8037A774
    if (ctx->r14 != 0) {
        // 0x8037A71C: nop
    
            goto L_8037A774;
    }
    // 0x8037A71C: nop

    // 0x8037A720: lbu         $v0, -0x7594($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7594);
    // 0x8037A724: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037A728: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8037A72C: bnel        $v0, $at, L_8037A754
    if (ctx->r2 != ctx->r1) {
        // 0x8037A730: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8037A754;
    }
    goto skip_0;
    // 0x8037A730: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_0:
    // 0x8037A734: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x8037A738: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8037A73C: lh          $t8, 0x12($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X12);
    // 0x8037A740: addiu       $t1, $t8, -0x800
    ctx->r9 = ADD32(ctx->r24, -0X800);
    // 0x8037A744: andi        $t2, $t1, 0x1FFF
    ctx->r10 = ctx->r9 & 0X1FFF;
    // 0x8037A748: b           L_8037A774
    // 0x8037A74C: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
        goto L_8037A774;
    // 0x8037A74C: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x8037A750: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8037A754:
    // 0x8037A754: bne         $v0, $at, L_8037A774
    if (ctx->r2 != ctx->r1) {
        // 0x8037A758: lui         $t3, 0x801C
        ctx->r11 = S32(0X801C << 16);
            goto L_8037A774;
    }
    // 0x8037A758: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8037A75C: lw          $t3, -0x4330($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4330);
    // 0x8037A760: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x8037A764: lh          $t4, 0x12($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X12);
    // 0x8037A768: addiu       $t7, $t4, -0x800
    ctx->r15 = ADD32(ctx->r12, -0X800);
    // 0x8037A76C: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x8037A770: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
L_8037A774:
    // 0x8037A774: jal         0x8037B9F0
    // 0x8037A778: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8037B9F0)(rdram, ctx);
        goto after_0;
    // 0x8037A778: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x8037A77C: bne         $v0, $zero, L_8037A94C
    if (ctx->r2 != 0) {
            // 0x8037A780: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x8037A94C)(rdram, ctx);
    return;
    }
    // 0x8037A780: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8037A784: jal         0x80010550
    // 0x8037A788: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x8037A788: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8037A78C: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x8037A790: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8037A794: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8037A798: beql        $t0, $zero, L_8037A820
    if (ctx->r8 == 0) {
        // 0x8037A79C: lhu         $t1, 0x2E($sp)
        ctx->r9 = MEM_HU(ctx->r29, 0X2E);
            goto L_8037A820;
    }
    goto skip_1;
    // 0x8037A79C: lhu         $t1, 0x2E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2E);
    skip_1:
    // 0x8037A7A0: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8037A7A4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037A7A8: ldc1        $f0, -0x6800($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X6800);
    // 0x8037A7AC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8037A7B0: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8037A7B4: mul.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8037A7B8: addiu       $a0, $zero, 0x308
    ctx->r4 = ADD32(0, 0X308);
    // 0x8037A7BC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8037A7C0: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8037A7C4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8037A7C8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8037A7CC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8037A7D0: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x8037A7D4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8037A7D8: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x8037A7DC: mul.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8037A7E0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8037A7E4: jal         0x80020DAC
    // 0x8037A7E8: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x80020DAC)(rdram, ctx);
        goto after_2;
    // 0x8037A7E8: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    after_2:
    // 0x8037A7EC: bnel        $v0, $zero, L_8037A820
    if (ctx->r2 != 0) {
        // 0x8037A7F0: lhu         $t1, 0x2E($sp)
        ctx->r9 = MEM_HU(ctx->r29, 0X2E);
            goto L_8037A820;
    }
    goto skip_2;
    // 0x8037A7F0: lhu         $t1, 0x2E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2E);
    skip_2:
    // 0x8037A7F4: jal         0x80020DAC
    // 0x8037A7F8: addiu       $a0, $zero, 0x309
    ctx->r4 = ADD32(0, 0X309);
    LOOKUP_FUNC(0x80020DAC)(rdram, ctx);
        goto after_3;
    // 0x8037A7F8: addiu       $a0, $zero, 0x309
    ctx->r4 = ADD32(0, 0X309);
    after_3:
    // 0x8037A7FC: bnel        $v0, $zero, L_8037A820
    if (ctx->r2 != 0) {
        // 0x8037A800: lhu         $t1, 0x2E($sp)
        ctx->r9 = MEM_HU(ctx->r29, 0X2E);
            goto L_8037A820;
    }
    goto skip_3;
    // 0x8037A800: lhu         $t1, 0x2E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2E);
    skip_3:
    // 0x8037A804: jal         0x80020DAC
    // 0x8037A808: addiu       $a0, $zero, 0x30A
    ctx->r4 = ADD32(0, 0X30A);
    LOOKUP_FUNC(0x80020DAC)(rdram, ctx);
        goto after_4;
    // 0x8037A808: addiu       $a0, $zero, 0x30A
    ctx->r4 = ADD32(0, 0X30A);
    after_4:
    // 0x8037A80C: bne         $v0, $zero, L_8037A81C
    if (ctx->r2 != 0) {
        // 0x8037A810: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8037A81C;
    }
    // 0x8037A810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037A814: jal         0x801DFAA4
    // 0x8037A818: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801DFAA4)(rdram, ctx);
        goto after_5;
    // 0x8037A818: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_8037A81C:
    // 0x8037A81C: lhu         $t1, 0x2E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2E);
L_8037A820:
    // 0x8037A820: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8037A824: beql        $t1, $zero, L_8037A950
    if (ctx->r9 == 0) {
            // 0x8037A828: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8037A950)(rdram, ctx);
    return;
    }
    goto skip_4;
    // 0x8037A828: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x8037A82C: lw          $t2, -0x4330($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4330);
    // 0x8037A830: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8037A834: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8037A838: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x8037A83C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8037A840: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8037A844: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8037A848: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8037A84C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8037A850: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8037A854: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8037A858: sub.d       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f0.d - ctx->f10.d;
    // 0x8037A85C: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8037A860: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8037A864: add.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d + ctx->f6.d;
    // 0x8037A868: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8037A86C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8037A870: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8037A874: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x8037A878: jal         0x801C5A1C
    // 0x8037A87C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_6;
    // 0x8037A87C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x8037A880: beq         $v0, $zero, L_8037A94C
    if (ctx->r2 == 0) {
            LOOKUP_FUNC(0x8037A94C)(rdram, ctx);
    return;
    }
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037a884(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037a884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A884: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8037A888: lhu         $t3, -0x23BE($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X23BE);
    // 0x8037A88C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037A890: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8037A894: bgtz        $t3, L_8037A8BC
    if (SIGNED(ctx->r11) > 0) {
        // 0x8037A898: lui         $v0, 0x8039
        ctx->r2 = S32(0X8039 << 16);
            goto L_8037A8BC;
    }
    // 0x8037A898: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037A89C: jal         0x80020744
    // 0x8037A8A0: sb          $zero, -0x56C4($at)
    MEM_B(-0X56C4, ctx->r1) = 0;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x8037A8A0: sb          $zero, -0x56C4($at)
    MEM_B(-0X56C4, ctx->r1) = 0;
    after_0:
    // 0x8037A8A4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037A8A8: addiu       $a1, $a1, -0x4794
    ctx->r5 = ADD32(ctx->r5, -0X4794);
    // 0x8037A8AC: jal         0x800058DC
    // 0x8037A8B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8037A8B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8037A8B4: b           L_8037A950
    // 0x8037A8B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8037A950)(rdram, ctx);
    return;
    // 0x8037A8B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8037A8BC:
    // 0x8037A8BC: lbu         $v0, -0x7594($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7594);
    // 0x8037A8C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037A8C4: beq         $v0, $at, L_8037A8D4
    if (ctx->r2 == ctx->r1) {
        // 0x8037A8C8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8037A8D4;
    }
    // 0x8037A8C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037A8CC: bnel        $v0, $at, L_8037A8F0
    if (ctx->r2 != ctx->r1) {
        // 0x8037A8D0: lw          $v0, 0x34($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X34);
            goto L_8037A8F0;
    }
    goto skip_0;
    // 0x8037A8D0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    skip_0:
L_8037A8D4:
    // 0x8037A8D4: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8037A8D8: lui         $t4, 0x190
    ctx->r12 = S32(0X190 << 16);
    // 0x8037A8DC: ori         $t4, $t4, 0x74
    ctx->r12 = ctx->r12 | 0X74;
    // 0x8037A8E0: sw          $t4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r12;
    // 0x8037A8E4: b           L_8037A900
    // 0x8037A8E8: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
        goto L_8037A900;
    // 0x8037A8E8: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8037A8EC: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_8037A8F0:
    // 0x8037A8F0: lui         $t5, 0x190
    ctx->r13 = S32(0X190 << 16);
    // 0x8037A8F4: ori         $t5, $t5, 0x76
    ctx->r13 = ctx->r13 | 0X76;
    // 0x8037A8F8: sw          $t5, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r13;
    // 0x8037A8FC: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
L_8037A900:
    // 0x8037A900: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8037A904: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8037A908: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x8037A90C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8037A910: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8037A914: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8037A918: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8037A91C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037A920: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8037A924: jal         0x8013A28C
    // 0x8037A928: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_2;
    // 0x8037A928: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x8037A92C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8037A930: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037A934: addiu       $a1, $a1, -0x56A0
    ctx->r5 = ADD32(ctx->r5, -0X56A0);
    // 0x8037A938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037A93C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x8037A940: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x8037A944: jal         0x800058DC
    // 0x8037A948: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8037A948: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    after_3:
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037a94c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037a94c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A94C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037a950(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037a950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A950: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8037A954: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8037A958: jr          $ra
    // 0x8037A95C: nop

    return;
    // 0x8037A95C: nop

;}
RECOMP_FUNC void M55_FUN_8037a960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A960: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037A964: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037A968: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037A96C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x8037A970: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037A974: jal         0x8037B9F0
    // 0x8037A978: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8037B9F0)(rdram, ctx);
        goto after_0;
    // 0x8037A978: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8037A97C: bne         $v0, $zero, L_8037AA70
    if (ctx->r2 != 0) {
        // 0x8037A980: lui         $t7, 0x801C
        ctx->r15 = S32(0X801C << 16);
            goto L_8037AA70;
    }
    // 0x8037A980: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8037A984: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x8037A988: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8037A98C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8037A990: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8037A994: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x8037A998: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8037A99C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8037A9A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8037A9A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8037A9A8: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8037A9AC: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8037A9B0: sub.d       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f0.d - ctx->f10.d;
    // 0x8037A9B4: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8037A9B8: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8037A9BC: add.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d + ctx->f6.d;
    // 0x8037A9C0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8037A9C4: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8037A9C8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8037A9CC: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x8037A9D0: jal         0x801C5A1C
    // 0x8037A9D4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_1;
    // 0x8037A9D4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8037A9D8: beq         $v0, $zero, L_8037AA70
    if (ctx->r2 == 0) {
        // 0x8037A9DC: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_8037AA70;
    }
    // 0x8037A9DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037A9E0: jal         0x80010550
    // 0x8037A9E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x8037A9E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8037A9E8: beq         $v0, $zero, L_8037AA70
    if (ctx->r2 == 0) {
        // 0x8037A9EC: lui         $v0, 0x8039
        ctx->r2 = S32(0X8039 << 16);
            goto L_8037AA70;
    }
    // 0x8037A9EC: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037A9F0: lbu         $v0, -0x7594($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7594);
    // 0x8037A9F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037A9F8: beq         $v0, $at, L_8037AA08
    if (ctx->r2 == ctx->r1) {
        // 0x8037A9FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8037AA08;
    }
    // 0x8037A9FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037AA00: bnel        $v0, $at, L_8037AA24
    if (ctx->r2 != ctx->r1) {
        // 0x8037AA04: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_8037AA24;
    }
    goto skip_0;
    // 0x8037AA04: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_8037AA08:
    // 0x8037AA08: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8037AA0C: lui         $t8, 0x190
    ctx->r24 = S32(0X190 << 16);
    // 0x8037AA10: ori         $t8, $t8, 0x75
    ctx->r24 = ctx->r24 | 0X75;
    // 0x8037AA14: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x8037AA18: b           L_8037AA34
    // 0x8037AA1C: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
        goto L_8037AA34;
    // 0x8037AA1C: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8037AA20: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8037AA24:
    // 0x8037AA24: lui         $t9, 0x190
    ctx->r25 = S32(0X190 << 16);
    // 0x8037AA28: ori         $t9, $t9, 0x77
    ctx->r25 = ctx->r25 | 0X77;
    // 0x8037AA2C: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x8037AA30: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
L_8037AA34:
    // 0x8037AA34: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8037AA38: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8037AA3C: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x8037AA40: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8037AA44: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8037AA48: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8037AA4C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037AA50: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037AA54: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8037AA58: jal         0x8013A28C
    // 0x8037AA5C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x8037AA5C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x8037AA60: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037AA64: addiu       $a1, $a1, -0x5580
    ctx->r5 = ADD32(ctx->r5, -0X5580);
    // 0x8037AA68: jal         0x800058DC
    // 0x8037AA6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8037AA6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
L_8037AA70:
    // 0x8037AA70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037AA74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037AA78: jr          $ra
    // 0x8037AA7C: nop

    return;
    // 0x8037AA7C: nop

;}
RECOMP_FUNC void M55_FUN_8037aa80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037AA80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037AA84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037AA88: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037AA8C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x8037AA90: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037AA94: jal         0x8037B9F0
    // 0x8037AA98: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8037B9F0)(rdram, ctx);
        goto after_0;
    // 0x8037AA98: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8037AA9C: bne         $v0, $zero, L_8037AAF8
    if (ctx->r2 != 0) {
        // 0x8037AAA0: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_8037AAF8;
    }
    // 0x8037AAA0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037AAA4: jal         0x80010550
    // 0x8037AAA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_1;
    // 0x8037AAA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8037AAAC: beq         $v0, $zero, L_8037AAF8
    if (ctx->r2 == 0) {
        // 0x8037AAB0: lui         $t7, 0x8021
        ctx->r15 = S32(0X8021 << 16);
            goto L_8037AAF8;
    }
    // 0x8037AAB0: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x8037AAB4: addiu       $t7, $t7, 0x6B90
    ctx->r15 = ADD32(ctx->r15, 0X6B90);
    // 0x8037AAB8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8037AABC: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8037AAC0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037AAC4: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8037AAC8: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x8037AACC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037AAD0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8037AAD4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037AAD8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8037AADC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8037AAE0: jal         0x80011140
    // 0x8037AAE4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_2;
    // 0x8037AAE4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_2:
    // 0x8037AAE8: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037AAEC: addiu       $a1, $a1, -0x54F8
    ctx->r5 = ADD32(ctx->r5, -0X54F8);
    // 0x8037AAF0: jal         0x800058DC
    // 0x8037AAF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8037AAF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
L_8037AAF8:
    // 0x8037AAF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037AAFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037AB00: jr          $ra
    // 0x8037AB04: nop

    return;
    // 0x8037AB04: nop

;}
RECOMP_FUNC void M55_FUN_8037ab08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037AB08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8037AB0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037AB10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8037AB14: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8037AB18: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x8037AB1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037AB20: jal         0x8037B9F0
    // 0x8037AB24: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8037B9F0)(rdram, ctx);
        goto after_0;
    // 0x8037AB24: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8037AB28: bne         $v0, $zero, L_8037ABF4
    if (ctx->r2 != 0) {
        // 0x8037AB2C: lui         $t7, 0x8021
        ctx->r15 = S32(0X8021 << 16);
            goto L_8037ABF4;
    }
    // 0x8037AB2C: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x8037AB30: addiu       $t7, $t7, 0x6B90
    ctx->r15 = ADD32(ctx->r15, 0X6B90);
    // 0x8037AB34: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8037AB38: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8037AB3C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8037AB40: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8037AB44: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x8037AB48: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8037AB4C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8037AB50: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037AB54: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8037AB58: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8037AB5C: jal         0x80011140
    // 0x8037AB60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_1;
    // 0x8037AB60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x8037AB64: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8037AB68: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x8037AB6C: ori         $at, $at, 0x41
    ctx->r1 = ctx->r1 | 0X41;
    // 0x8037AB70: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x8037AB74: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8037AB78: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8037AB7C: bne         $t2, $at, L_8037ABF4
    if (ctx->r10 != ctx->r1) {
        // 0x8037AB80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8037ABF4;
    }
    // 0x8037AB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037AB84: lw          $t3, 0xEFC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XEFC);
    // 0x8037AB88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037AB8C: jal         0x801C4A5C
    // 0x8037AB90: sw          $t3, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r11;
    LOOKUP_FUNC(0x801C4A5C)(rdram, ctx);
        goto after_2;
    // 0x8037AB90: sw          $t3, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r11;
    after_2:
    // 0x8037AB94: lw          $t4, 0x2C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2C);
    // 0x8037AB98: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8037AB9C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8037ABA0: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x8037ABA4: ori         $t7, $t5, 0x20
    ctx->r15 = ctx->r13 | 0X20;
    // 0x8037ABA8: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
    // 0x8037ABAC: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x8037ABB0: ori         $t9, $t7, 0x80
    ctx->r25 = ctx->r15 | 0X80;
    // 0x8037ABB4: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x8037ABB8: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8037ABBC: sh          $t0, 0xEF0($v0)
    MEM_H(0XEF0, ctx->r2) = ctx->r8;
    // 0x8037ABC0: addiu       $t1, $zero, 0x2D
    ctx->r9 = ADD32(0, 0X2D);
    // 0x8037ABC4: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x8037ABC8: sh          $t1, 0x6BF8($at)
    MEM_H(0X6BF8, ctx->r1) = ctx->r9;
    // 0x8037ABCC: lhu         $t2, 0xEF0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XEF0);
    // 0x8037ABD0: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8037ABD4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x8037ABD8: ori         $t3, $t2, 0x2000
    ctx->r11 = ctx->r10 | 0X2000;
    // 0x8037ABDC: sh          $t3, 0xEF0($v0)
    MEM_H(0XEF0, ctx->r2) = ctx->r11;
    // 0x8037ABE0: lbu         $t4, -0x56C2($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X56C2);
    // 0x8037ABE4: addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // 0x8037ABE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037ABEC: jal         0x800058DC
    // 0x8037ABF0: sb          $t4, 0x230($v0)
    MEM_B(0X230, ctx->r2) = ctx->r12;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8037ABF0: sb          $t4, 0x230($v0)
    MEM_B(0X230, ctx->r2) = ctx->r12;
    after_3:
L_8037ABF4:
    // 0x8037ABF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037ABF8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8037ABFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8037AC00: jr          $ra
    // 0x8037AC04: nop

    return;
    // 0x8037AC04: nop

;}
RECOMP_FUNC void M55_FUN_8037ac08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037AC08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8037AC0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037AC10: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8037AC14: lw          $a3, 0x5C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X5C);
    // 0x8037AC18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037AC1C: lhu         $t6, 0x20($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X20);
    // 0x8037AC20: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8037AC24: bnel        $t6, $zero, L_8037ACC4
    if (ctx->r14 != 0) {
        // 0x8037AC28: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_8037ACC4;
    }
    goto skip_0;
    // 0x8037AC28: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8037AC2C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8037AC30: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8037AC34: addiu       $t0, $t0, -0x4410
    ctx->r8 = ADD32(ctx->r8, -0X4410);
    // 0x8037AC38: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x8037AC3C: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x8037AC40: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x8037AC44: lw          $t7, 0xE0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0XE0);
    // 0x8037AC48: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8037AC4C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8037AC50: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8037AC54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8037AC58: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037AC5C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8037AC60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037AC64: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8037AC68: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8037AC6C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8037AC70: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x8037AC74: lbu         $v1, -0x7594($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7594);
    // 0x8037AC78: bnel        $v1, $at, L_8037ACA0
    if (ctx->r3 != ctx->r1) {
        // 0x8037AC7C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8037ACA0;
    }
    goto skip_1;
    // 0x8037AC7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x8037AC80: lw          $t8, 0xE0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XE0);
    // 0x8037AC84: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x8037AC88: lh          $t9, 0x12($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X12);
    // 0x8037AC8C: addiu       $t3, $t9, -0x800
    ctx->r11 = ADD32(ctx->r25, -0X800);
    // 0x8037AC90: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x8037AC94: b           L_8037ACC0
    // 0x8037AC98: sh          $t4, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r12;
        goto L_8037ACC0;
    // 0x8037AC98: sh          $t4, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r12;
    // 0x8037AC9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8037ACA0:
    // 0x8037ACA0: bnel        $v1, $at, L_8037ACC4
    if (ctx->r3 != ctx->r1) {
        // 0x8037ACA4: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_8037ACC4;
    }
    goto skip_2;
    // 0x8037ACA4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x8037ACA8: lw          $t5, 0xE0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XE0);
    // 0x8037ACAC: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x8037ACB0: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
    // 0x8037ACB4: addiu       $t9, $t6, -0x800
    ctx->r25 = ADD32(ctx->r14, -0X800);
    // 0x8037ACB8: andi        $t1, $t9, 0x1FFF
    ctx->r9 = ctx->r25 & 0X1FFF;
    // 0x8037ACBC: sh          $t1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r9;
L_8037ACC0:
    // 0x8037ACC0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_8037ACC4:
    // 0x8037ACC4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8037ACC8: jal         0x80010550
    // 0x8037ACCC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x8037ACCC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8037ACD0: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8037ACD4: jal         0x8037B9F0
    // 0x8037ACD8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x8037B9F0)(rdram, ctx);
        goto after_1;
    // 0x8037ACD8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8037ACDC: bne         $v0, $zero, L_8037AE98
    if (ctx->r2 != 0) {
        // 0x8037ACE0: lhu         $t2, 0x26($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X26);
            goto L_8037AE98;
    }
    // 0x8037ACE0: lhu         $t2, 0x26($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X26);
    // 0x8037ACE4: beq         $t2, $zero, L_8037AE98
    if (ctx->r10 == 0) {
        // 0x8037ACE8: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_8037AE98;
    }
    // 0x8037ACE8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8037ACEC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8037ACF0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037ACF4: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x8037ACF8: beql        $t5, $zero, L_8037AE9C
    if (ctx->r13 == 0) {
        // 0x8037ACFC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037AE9C;
    }
    goto skip_3;
    // 0x8037ACFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8037AD00: lbu         $t6, -0x7594($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7594);
    // 0x8037AD04: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8037AD08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8037AD0C: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x8037AD10: beq         $at, $zero, L_8037AD2C
    if (ctx->r1 == 0) {
        // 0x8037AD14: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8037AD2C;
    }
    // 0x8037AD14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8037AD18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8037AD1C: jal         0x801518D4
    // 0x8037AD20: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_2;
    // 0x8037AD20: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x8037AD24: b           L_8037AD34
    // 0x8037AD28: nop

        goto L_8037AD34;
    // 0x8037AD28: nop

L_8037AD2C:
    // 0x8037AD2C: jal         0x801518D4
    // 0x8037AD30: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_3;
    // 0x8037AD30: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_3:
L_8037AD34:
    // 0x8037AD34: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037AD38: lbu         $v1, -0x7594($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7594);
    // 0x8037AD3C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8037AD40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037AD44: beq         $v1, $at, L_8037AD54
    if (ctx->r3 == ctx->r1) {
        // 0x8037AD48: addiu       $v0, $v0, 0x1C
        ctx->r2 = ADD32(ctx->r2, 0X1C);
            goto L_8037AD54;
    }
    // 0x8037AD48: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8037AD4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037AD50: bne         $v1, $at, L_8037AD64
    if (ctx->r3 != ctx->r1) {
        // 0x8037AD54: lui         $t7, 0x190
        ctx->r15 = S32(0X190 << 16);
            goto L_8037AD64;
    }
L_8037AD54:
    // 0x8037AD54: lui         $t7, 0x190
    ctx->r15 = S32(0X190 << 16);
    // 0x8037AD58: ori         $t7, $t7, 0x6E
    ctx->r15 = ctx->r15 | 0X6E;
    // 0x8037AD5C: b           L_8037AD78
    // 0x8037AD60: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_8037AD78;
    // 0x8037AD60: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8037AD64:
    // 0x8037AD64: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8037AD68: lui         $t8, 0x190
    ctx->r24 = S32(0X190 << 16);
    // 0x8037AD6C: ori         $t8, $t8, 0x6B
    ctx->r24 = ctx->r24 | 0X6B;
    // 0x8037AD70: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x8037AD74: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
L_8037AD78:
    // 0x8037AD78: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8037AD7C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8037AD80: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x8037AD84: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8037AD88: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8037AD8C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8037AD90: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8037AD94: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037AD98: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8037AD9C: jal         0x8013A28C
    // 0x8037ADA0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_4;
    // 0x8037ADA0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_4:
    // 0x8037ADA4: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8037ADA8: lw          $t2, -0x4330($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4330);
    // 0x8037ADAC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8037ADB0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8037ADB4: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x8037ADB8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8037ADBC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8037ADC0: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8037ADC4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8037ADC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037ADCC: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8037ADD0: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8037ADD4: sub.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d - ctx->f8.d;
    // 0x8037ADD8: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8037ADDC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8037ADE0: add.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d + ctx->f4.d;
    // 0x8037ADE4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8037ADE8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8037ADEC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8037ADF0: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x8037ADF4: jal         0x801C5A1C
    // 0x8037ADF8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_5;
    // 0x8037ADF8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x8037ADFC: beq         $v0, $zero, L_8037AE48
    if (ctx->r2 == 0) {
        // 0x8037AE00: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_8037AE48;
    }
    // 0x8037AE00: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8037AE04: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8037AE08: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8037AE0C: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x8037AE10: beq         $v0, $at, L_8037AE20
    if (ctx->r2 == ctx->r1) {
        // 0x8037AE14: addiu       $at, $zero, 0x50
        ctx->r1 = ADD32(0, 0X50);
            goto L_8037AE20;
    }
    // 0x8037AE14: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x8037AE18: bnel        $v0, $at, L_8037AE30
    if (ctx->r2 != ctx->r1) {
        // 0x8037AE1C: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_8037AE30;
    }
    goto skip_4;
    // 0x8037AE1C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    skip_4:
L_8037AE20:
    // 0x8037AE20: lbu         $t3, 0x35B($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X35B);
    // 0x8037AE24: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8037AE28: beq         $at, $zero, L_8037AE54
    if (ctx->r1 == 0) {
        // 0x8037AE2C: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_8037AE54;
    }
    // 0x8037AE2C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
L_8037AE30:
    // 0x8037AE30: bnel        $v0, $at, L_8037AE4C
    if (ctx->r2 != ctx->r1) {
        // 0x8037AE34: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8037AE4C;
    }
    goto skip_5;
    // 0x8037AE34: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_5:
    // 0x8037AE38: lbu         $t4, 0x35B($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X35B);
    // 0x8037AE3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037AE40: beq         $t4, $at, L_8037AE54
    if (ctx->r12 == ctx->r1) {
        // 0x8037AE44: nop
    
            goto L_8037AE54;
    }
    // 0x8037AE44: nop

L_8037AE48:
    // 0x8037AE48: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_8037AE4C:
    // 0x8037AE4C: jal         0x801CD228
    // 0x8037AE50: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x801CD228)(rdram, ctx);
        goto after_6;
    // 0x8037AE50: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_6:
L_8037AE54:
    // 0x8037AE54: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037AE58: lbu         $v1, -0x7594($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7594);
    // 0x8037AE5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037AE60: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8037AE64: beq         $v1, $at, L_8037AE78
    if (ctx->r3 == ctx->r1) {
        // 0x8037AE68: lui         $a1, 0x8038
        ctx->r5 = S32(0X8038 << 16);
            goto L_8037AE78;
    }
    // 0x8037AE68: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037AE6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037AE70: bne         $v1, $at, L_8037AE88
    if (ctx->r3 != ctx->r1) {
        // 0x8037AE74: nop
    
            goto L_8037AE88;
    }
    // 0x8037AE74: nop

L_8037AE78:
    // 0x8037AE78: jal         0x800058DC
    // 0x8037AE7C: addiu       $a1, $a1, -0x5158
    ctx->r5 = ADD32(ctx->r5, -0X5158);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x8037AE7C: addiu       $a1, $a1, -0x5158
    ctx->r5 = ADD32(ctx->r5, -0X5158);
    after_7:
    // 0x8037AE80: b           L_8037AE9C
    // 0x8037AE84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8037AE9C;
    // 0x8037AE84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037AE88:
    // 0x8037AE88: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037AE8C: addiu       $a1, $a1, -0x4EE8
    ctx->r5 = ADD32(ctx->r5, -0X4EE8);
    // 0x8037AE90: jal         0x800058DC
    // 0x8037AE94: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x8037AE94: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_8:
L_8037AE98:
    // 0x8037AE98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037AE9C:
    // 0x8037AE9C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8037AEA0: jr          $ra
    // 0x8037AEA4: nop

    return;
    // 0x8037AEA4: nop

;}
RECOMP_FUNC void M55_FUN_8037aea8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037AEA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037AEAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037AEB0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037AEB4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037AEB8: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x8037AEBC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037AEC0: jal         0x80010550
    // 0x8037AEC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x8037AEC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8037AEC8: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x8037AECC: jal         0x8037B9F0
    // 0x8037AED0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x8037B9F0)(rdram, ctx);
        goto after_1;
    // 0x8037AED0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8037AED4: bne         $v0, $zero, L_8037AFC0
    if (ctx->r2 != 0) {
        // 0x8037AED8: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8037AFC0;
    }
    // 0x8037AED8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8037AEDC: lhu         $t7, 0x20($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X20);
    // 0x8037AEE0: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8037AEE4: addiu       $a0, $zero, 0x308
    ctx->r4 = ADD32(0, 0X308);
    // 0x8037AEE8: slti        $at, $t7, 0x15
    ctx->r1 = SIGNED(ctx->r15) < 0X15 ? 1 : 0;
    // 0x8037AEEC: bnel        $at, $zero, L_8037AF44
    if (ctx->r1 != 0) {
        // 0x8037AEF0: lhu         $t8, 0x1E($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X1E);
            goto L_8037AF44;
    }
    goto skip_0;
    // 0x8037AEF0: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
    skip_0:
    // 0x8037AEF4: jal         0x80020DAC
    // 0x8037AEF8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80020DAC)(rdram, ctx);
        goto after_2;
    // 0x8037AEF8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_2:
    // 0x8037AEFC: bne         $v0, $zero, L_8037AF40
    if (ctx->r2 != 0) {
        // 0x8037AF00: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_8037AF40;
    }
    // 0x8037AF00: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8037AF04: addiu       $a0, $zero, 0x309
    ctx->r4 = ADD32(0, 0X309);
    // 0x8037AF08: jal         0x80020DAC
    // 0x8037AF0C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80020DAC)(rdram, ctx);
        goto after_3;
    // 0x8037AF0C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_3:
    // 0x8037AF10: bne         $v0, $zero, L_8037AF40
    if (ctx->r2 != 0) {
        // 0x8037AF14: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_8037AF40;
    }
    // 0x8037AF14: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8037AF18: addiu       $a0, $zero, 0x30A
    ctx->r4 = ADD32(0, 0X30A);
    // 0x8037AF1C: jal         0x80020DAC
    // 0x8037AF20: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80020DAC)(rdram, ctx);
        goto after_4;
    // 0x8037AF20: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_4:
    // 0x8037AF24: bne         $v0, $zero, L_8037AF40
    if (ctx->r2 != 0) {
        // 0x8037AF28: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_8037AF40;
    }
    // 0x8037AF28: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8037AF2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8037AF30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037AF34: jal         0x801DFAA4
    // 0x8037AF38: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x801DFAA4)(rdram, ctx);
        goto after_5;
    // 0x8037AF38: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_5:
    // 0x8037AF3C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_8037AF40:
    // 0x8037AF40: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
L_8037AF44:
    // 0x8037AF44: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8037AF48: beql        $t8, $zero, L_8037AFC4
    if (ctx->r24 == 0) {
        // 0x8037AF4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037AFC4;
    }
    goto skip_1;
    // 0x8037AF4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8037AF50: lhu         $t9, -0x23BE($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X23BE);
    // 0x8037AF54: lui         $t0, 0x190
    ctx->r8 = S32(0X190 << 16);
    // 0x8037AF58: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037AF5C: blez        $t9, L_8037AFA8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8037AF60: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_8037AFA8;
    }
    // 0x8037AF60: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8037AF64: ori         $a1, $t0, 0x1A
    ctx->r5 = ctx->r8 | 0X1A;
    // 0x8037AF68: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8037AF6C: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x8037AF70: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x8037AF74: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8037AF78: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x8037AF7C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037AF80: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037AF84: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x8037AF88: jal         0x8013A28C
    // 0x8037AF8C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_6;
    // 0x8037AF8C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_6:
    // 0x8037AF90: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037AF94: addiu       $a1, $a1, -0x5030
    ctx->r5 = ADD32(ctx->r5, -0X5030);
    // 0x8037AF98: jal         0x800058DC
    // 0x8037AF9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x8037AF9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x8037AFA0: b           L_8037AFC4
    // 0x8037AFA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8037AFC4;
    // 0x8037AFA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037AFA8:
    // 0x8037AFA8: jal         0x80020744
    // 0x8037AFAC: sb          $zero, -0x56C4($at)
    MEM_B(-0X56C4, ctx->r1) = 0;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_8;
    // 0x8037AFAC: sb          $zero, -0x56C4($at)
    MEM_B(-0X56C4, ctx->r1) = 0;
    after_8:
    // 0x8037AFB0: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037AFB4: addiu       $a1, $a1, -0x4794
    ctx->r5 = ADD32(ctx->r5, -0X4794);
    // 0x8037AFB8: jal         0x800058DC
    // 0x8037AFBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x8037AFBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_9:
L_8037AFC0:
    // 0x8037AFC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037AFC4:
    // 0x8037AFC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037AFC8: jr          $ra
    // 0x8037AFCC: nop

    return;
    // 0x8037AFCC: nop

;}
