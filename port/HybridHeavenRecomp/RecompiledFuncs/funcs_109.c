#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M55_FUN_80380e80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380E80: jr          $ra
    // 0x80380E84: nop

    return;
    // 0x80380E84: nop

;}
RECOMP_FUNC void M55_FUN_80380e88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380E88: nop

    // 0x80380E8C: nop

;}
RECOMP_FUNC void M55_FUN_80380e90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80380E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80380E98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80380E9C: jal         0x8001F74C
    // 0x80380EA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_0;
    // 0x80380EA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80380EA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80380EA8: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80380EAC: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x80380EB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80380EB4: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80380EB8: lw          $v0, -0x727C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X727C);
    // 0x80380EBC: beq         $v0, $zero, L_80380ED0
    if (ctx->r2 == 0) {
        // 0x80380EC0: nop
    
            goto L_80380ED0;
    }
    // 0x80380EC0: nop

    // 0x80380EC4: jalr        $v0
    // 0x80380EC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80380EC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80380ECC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80380ED0:
    // 0x80380ED0: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80380ED4: jal         0x800058DC
    // 0x80380ED8: addiu       $a1, $a1, 0xEEC
    ctx->r5 = ADD32(ctx->r5, 0XEEC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80380ED8: addiu       $a1, $a1, 0xEEC
    ctx->r5 = ADD32(ctx->r5, 0XEEC);
    after_2:
    // 0x80380EDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80380EE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80380EE4: jr          $ra
    // 0x80380EE8: nop

    return;
    // 0x80380EE8: nop

;}
RECOMP_FUNC void M55_FUN_80380eec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380EEC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80380EF0: lhu         $t6, -0x3520($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3520);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80380ef4(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80380ef4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380EF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80380EF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80380EFC: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80380F00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380F04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80380F08: beq         $t7, $zero, L_80380F20
    if (ctx->r15 == 0) {
        // 0x80380F0C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80380F20;
    }
    // 0x80380F0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80380F10: jal         0x8001F74C
    // 0x80380F14: nop

    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_0;
    // 0x80380F14: nop

    after_0:
    // 0x80380F18: b           L_80380F2C
    // 0x80380F1C: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
        goto L_80380F2C;
    // 0x80380F1C: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
L_80380F20:
    // 0x80380F20: jal         0x8001F75C
    // 0x80380F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001F75C)(rdram, ctx);
        goto after_1;
    // 0x80380F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80380F28: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
L_80380F2C:
    // 0x80380F2C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80380F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380F34: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80380F38: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80380F3C: lw          $v0, -0x71F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X71F4);
    // 0x80380F40: beql        $v0, $zero, L_80380F54
    if (ctx->r2 == 0) {
        // 0x80380F44: lwc1        $f4, 0x94($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
            goto L_80380F54;
    }
    goto skip_0;
    // 0x80380F44: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    skip_0:
    // 0x80380F48: jalr        $v0
    // 0x80380F4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80380F4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80380F50: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
L_80380F54:
    // 0x80380F54: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80380F58: lwc1        $f10, 0x98($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80380F5C: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80380F60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80380F64: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80380F68: lwc1        $f4, 0x9C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80380F6C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80380F70: swc1        $f8, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
    // 0x80380F74: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80380F78: swc1        $f18, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f18.u32l;
    // 0x80380F7C: swc1        $f8, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f8.u32l;
    // 0x80380F80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80380F84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80380F88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80380F8C: jr          $ra
    // 0x80380F90: nop

    return;
    // 0x80380F90: nop

;}
RECOMP_FUNC void M55_FUN_80380f94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380F94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80380F98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80380F9C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x80380FA0: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80380FA4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80380FA8: jal         0x80005C70
    // 0x80380FAC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80005C70)(rdram, ctx);
        goto after_0;
    // 0x80380FAC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80380FB0: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x80380FB4: beq         $at, $zero, L_80380FC4
    if (ctx->r1 == 0) {
        // 0x80380FB8: lui         $t6, 0x8039
        ctx->r14 = S32(0X8039 << 16);
            goto L_80380FC4;
    }
    // 0x80380FB8: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80380FBC: b           L_80381068
    // 0x80380FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80381068;
    // 0x80380FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80380FC4:
    // 0x80380FC4: addiu       $t6, $t6, -0x7290
    ctx->r14 = ADD32(ctx->r14, -0X7290);
    // 0x80380FC8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80380FCC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80380FD0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80380FD4: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80380FD8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80380FDC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80380FE0: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x80380FE4: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80380FE8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80380FEC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80380FF0: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x80380FF4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80380FF8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80380FFC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80381000: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80381004: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80381008: jal         0x8012C4D0
    // 0x8038100C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_1;
    // 0x8038100C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_1:
    // 0x80381010: beq         $v0, $zero, L_80381064
    if (ctx->r2 == 0) {
        // 0x80381014: lwc1        $f4, 0x28($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80381064;
    }
    // 0x80381014: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80381018: swc1        $f4, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f4.u32l;
    // 0x8038101C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80381020: swc1        $f6, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f6.u32l;
    // 0x80381024: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80381028: swc1        $f8, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f8.u32l;
    // 0x8038102C: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80381030: swc1        $f10, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f10.u32l;
    // 0x80381034: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80381038: swc1        $f16, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f16.u32l;
    // 0x8038103C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80381040: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x80381044: lbu         $t0, 0x43($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X43);
    // 0x80381048: sh          $zero, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = 0;
    // 0x8038104C: sh          $zero, 0xA0($v0)
    MEM_H(0XA0, ctx->r2) = 0;
    // 0x80381050: sh          $zero, 0xA2($v0)
    MEM_H(0XA2, ctx->r2) = 0;
    // 0x80381054: sh          $zero, 0xA4($v0)
    MEM_H(0XA4, ctx->r2) = 0;
    // 0x80381058: sb          $t0, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r8;
    // 0x8038105C: b           L_80381068
    // 0x80381060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80381068;
    // 0x80381060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80381064:
    // 0x80381064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80381068:
    // 0x80381068: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8038106C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80381070: jr          $ra
    // 0x80381074: nop

    return;
    // 0x80381074: nop

;}
RECOMP_FUNC void M55_FUN_80381078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381078: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8038107C: jr          $ra
    // 0x80381080: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80381080: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80381084(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80381084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381084: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80381088: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8038108C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80381090: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80381094: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80381098: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x8038109C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x803810A0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x803810A4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x803810A8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x803810AC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x803810B0: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x803810B4: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x803810B8: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x803810BC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x803810C0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x803810C4: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x803810C8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x803810CC: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x803810D0: jal         0x80005E44
    // 0x803810D4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x803810D4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x803810D8: jal         0x80006214
    // 0x803810DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x803810DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x803810E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x803810E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803810E8: addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // 0x803810EC: jal         0x8012C89C
    // 0x803810F0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x803810F0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_2:
    // 0x803810F4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x803810F8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803810FC: lwc1        $f0, -0x6538($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6538);
    // 0x80381100: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80381104: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80381108: addiu       $t3, $t3, -0x4A58
    ctx->r11 = ADD32(ctx->r11, -0X4A58);
    // 0x8038110C: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x80381110: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80381114: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80381118: ori         $t2, $t1, 0x100
    ctx->r10 = ctx->r9 | 0X100;
    // 0x8038111C: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x80381120: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80381124: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80381128: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8038112C: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x80381130: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381134: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80381138: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8038113C: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x80381140: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80381144: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80381148: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x8038114C: addiu       $t9, $zero, 0x1800
    ctx->r25 = ADD32(0, 0X1800);
    // 0x80381150: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x80381154: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80381158: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x8038115C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80381160: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x80381164: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80381168: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x8038116C: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80381170: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80381174: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80381178: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x8038117C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381180: lwc1        $f10, -0x6534($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6534);
    // 0x80381184: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80381188: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8038118C: swc1        $f10, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f10.u32l;
    // 0x80381190: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381194: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80381198: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8038119C: sh          $t9, 0x10($t1)
    MEM_H(0X10, ctx->r9) = ctx->r25;
    // 0x803811A0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x803811A4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x803811A8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x803811AC: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x803811B0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x803811B4: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x803811B8: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
    // 0x803811BC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x803811C0: addiu       $t4, $zero, 0xAC
    ctx->r12 = ADD32(0, 0XAC);
    // 0x803811C4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x803811C8: sb          $t6, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r14;
    // 0x803811CC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x803811D0: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x803811D4: sb          $t0, 0x49($t1)
    MEM_B(0X49, ctx->r9) = ctx->r8;
    // 0x803811D8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x803811DC: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x803811E0: sb          $t2, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = ctx->r10;
    // 0x803811E4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x803811E8: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x803811EC: sb          $t4, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = ctx->r12;
    // 0x803811F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803811F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x803811F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x803811FC: jr          $ra
    // 0x80381200: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80381200: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80381204(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80381204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381204: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80381208: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8038120C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80381210: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80381214: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80381218: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x8038121C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80381220: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80381224: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80381228: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8038122C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80381230: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80381234: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x80381238: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8038123C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80381240: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80381244: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80381248: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8038124C: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80381250: jal         0x80005E44
    // 0x80381254: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80381254: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x80381258: jal         0x80006214
    // 0x8038125C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x8038125C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80381260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80381264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80381268: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8038126C: jal         0x8012C89C
    // 0x80381270: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80381270: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80381274: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8038127C: addiu       $a2, $zero, 0x374
    ctx->r6 = ADD32(0, 0X374);
    // 0x80381280: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    // 0x80381284: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80381288: jal         0x8012CF8C
    // 0x8038128C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x8038128C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x80381290: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80381294: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80381298: lui         $t1, 0x6
    ctx->r9 = S32(0X6 << 16);
    // 0x8038129C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x803812A0: lwc1        $f0, -0x6530($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6530);
    // 0x803812A4: ori         $t1, $t1, 0x300
    ctx->r9 = ctx->r9 | 0X300;
    // 0x803812A8: sw          $t1, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r9;
    // 0x803812AC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x803812B0: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x803812B4: addiu       $t4, $t4, -0x7168
    ctx->r12 = ADD32(ctx->r12, -0X7168);
    // 0x803812B8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x803812BC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x803812C0: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x803812C4: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x803812C8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x803812CC: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x803812D0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x803812D4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803812D8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x803812DC: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x803812E0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x803812E4: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x803812E8: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x803812EC: swc1        $f6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f6.u32l;
    // 0x803812F0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x803812F4: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x803812F8: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x803812FC: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x80381300: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80381304: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80381308: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x8038130C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80381310: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80381314: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x80381318: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8038131C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80381320: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
    // 0x80381324: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80381328: lbu         $t0, 0x204($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X204);
    // 0x8038132C: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80381330: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80381334: sb          $t0, 0x48($t1)
    MEM_B(0X48, ctx->r9) = ctx->r8;
    // 0x80381338: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8038133C: lbu         $t3, 0x205($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X205);
    // 0x80381340: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80381344: sb          $t3, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r11;
    // 0x80381348: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8038134C: lbu         $t5, 0x206($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X206);
    // 0x80381350: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80381354: sb          $t5, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r13;
    // 0x80381358: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8038135C: lw          $t0, 0x30($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X30);
    // 0x80381360: sb          $t9, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r25;
    // 0x80381364: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80381368: lbu         $t1, 0x208($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X208);
    // 0x8038136C: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x80381370: sb          $t1, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r9;
    // 0x80381374: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381378: lbu         $t6, 0x209($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X209);
    // 0x8038137C: lw          $t5, 0x30($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X30);
    // 0x80381380: sb          $t6, 0x4D($t5)
    MEM_B(0X4D, ctx->r13) = ctx->r14;
    // 0x80381384: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80381388: lbu         $t8, 0x20A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X20A);
    // 0x8038138C: lw          $t9, 0x30($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X30);
    // 0x80381390: sb          $t8, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r24;
    // 0x80381394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80381398: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8038139C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x803813A0: jr          $ra
    // 0x803813A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x803813A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803813a8(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803813a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803813A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x803813AC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x803813B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803813B4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x803813B8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x803813BC: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x803813C0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x803813C4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x803813C8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x803813CC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x803813D0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x803813D4: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x803813D8: ori         $t9, $t9, 0x300
    ctx->r25 = ctx->r25 | 0X300;
    // 0x803813DC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x803813E0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x803813E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x803813E8: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x803813EC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x803813F0: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x803813F4: jal         0x80005E44
    // 0x803813F8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x803813F8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    after_0:
    // 0x803813FC: jal         0x80006214
    // 0x80381400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80381400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80381404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80381408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8038140C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80381410: jal         0x8012C89C
    // 0x80381414: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80381414: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80381418: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8038141C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80381420: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80381424: addiu       $a1, $zero, 0x4B1
    ctx->r5 = ADD32(0, 0X4B1);
    // 0x80381428: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8038142C: jal         0x8012D814
    // 0x80381430: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    LOOKUP_FUNC(0x8012D814)(rdram, ctx);
        goto after_3;
    // 0x80381430: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80381434: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80381438: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
    // 0x8038143C: ori         $at, $at, 0x300
    ctx->r1 = ctx->r1 | 0X300;
    // 0x80381440: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80381444: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80381448: addiu       $t4, $t4, 0x5C58
    ctx->r12 = ADD32(ctx->r12, 0X5C58);
    // 0x8038144C: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x80381450: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80381454: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80381458: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8038145C: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x80381460: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80381464: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80381468: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8038146C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80381470: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x80381474: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80381478: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x8038147C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80381480: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x80381484: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381488: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x8038148C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80381490: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x80381494: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80381498: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x8038149C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x803814A0: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x803814A4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x803814A8: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x803814AC: addiu       $t4, $zero, 0x1A
    ctx->r12 = ADD32(0, 0X1A);
    // 0x803814B0: sb          $v1, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r3;
    // 0x803814B4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x803814B8: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x803814BC: sb          $v1, 0x49($t7)
    MEM_B(0X49, ctx->r15) = ctx->r3;
    // 0x803814C0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x803814C4: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x803814C8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803814CC: sb          $v1, 0x4A($t9)
    MEM_B(0X4A, ctx->r25) = ctx->r3;
    // 0x803814D0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x803814D4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x803814D8: sb          $zero, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = 0;
    // 0x803814DC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x803814E0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x803814E4: sb          $v1, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r3;
    // 0x803814E8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x803814EC: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x803814F0: sb          $t4, 0x4D($t5)
    MEM_B(0X4D, ctx->r13) = ctx->r12;
    // 0x803814F4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x803814F8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803814FC: jal         0x8012C6B4
    // 0x80381500: sb          $t7, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r15;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80381500: sb          $t7, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r15;
    after_4:
    // 0x80381504: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80381508: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038150C: ldc1        $f4, -0x6528($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X6528);
    // 0x80381510: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80381514: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80381518: ldc1        $f8, -0x6520($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6520);
    // 0x8038151C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381520: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80381524: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80381528: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x8038152C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80381530: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80381534: swc1        $f0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f0.u32l;
    // 0x80381538: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8038153C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80381540: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    // 0x80381544: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80381548: lw          $t4, 0x30($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X30);
    // 0x8038154C: swc1        $f0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f0.u32l;
    // 0x80381550: sb          $zero, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = 0;
    // 0x80381554: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80381558: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8038155C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80381560: jr          $ra
    // 0x80381564: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80381564: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80381568(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80381568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381568: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8038156C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80381570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80381574: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80381578: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8038157C: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80381580: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80381584: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80381588: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8038158C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80381590: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80381594: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80381598: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x8038159C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x803815A0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x803815A4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x803815A8: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x803815AC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x803815B0: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x803815B4: jal         0x80005E44
    // 0x803815B8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x803815B8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x803815BC: jal         0x80006214
    // 0x803815C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x803815C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x803815C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x803815C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803815CC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x803815D0: jal         0x8012C89C
    // 0x803815D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x803815D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x803815D8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x803815DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x803815E0: addiu       $a2, $zero, 0x374
    ctx->r6 = ADD32(0, 0X374);
    // 0x803815E4: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    // 0x803815E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x803815EC: jal         0x8012CF8C
    // 0x803815F0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x803815F0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x803815F4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x803815F8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803815FC: lui         $t1, 0x6
    ctx->r9 = S32(0X6 << 16);
    // 0x80381600: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80381604: lwc1        $f0, -0x6518($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6518);
    // 0x80381608: ori         $t1, $t1, 0x300
    ctx->r9 = ctx->r9 | 0X300;
    // 0x8038160C: sw          $t1, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r9;
    // 0x80381610: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80381614: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x80381618: addiu       $t4, $t4, -0x7168
    ctx->r12 = ADD32(ctx->r12, -0X7168);
    // 0x8038161C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80381620: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80381624: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80381628: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x8038162C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80381630: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80381634: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80381638: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8038163C: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x80381640: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381644: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80381648: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x8038164C: swc1        $f6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f6.u32l;
    // 0x80381650: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80381654: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80381658: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x8038165C: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x80381660: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80381664: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80381668: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x8038166C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80381670: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80381674: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x80381678: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8038167C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80381680: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
    // 0x80381684: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381688: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x8038168C: sb          $v0, 0x48($t2)
    MEM_B(0X48, ctx->r10) = ctx->r2;
    // 0x80381690: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80381694: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80381698: sb          $v0, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r2;
    // 0x8038169C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x803816A0: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x803816A4: sb          $v0, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r2;
    // 0x803816A8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x803816AC: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x803816B0: sb          $v0, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r2;
    // 0x803816B4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x803816B8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803816BC: sb          $v0, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r2;
    // 0x803816C0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x803816C4: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x803816C8: sb          $zero, 0x4D($t2)
    MEM_B(0X4D, ctx->r10) = 0;
    // 0x803816CC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x803816D0: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x803816D4: sb          $zero, 0x4E($t3)
    MEM_B(0X4E, ctx->r11) = 0;
    // 0x803816D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803816DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x803816E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x803816E4: jr          $ra
    // 0x803816E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x803816E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803816ec(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803816ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803816EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x803816F0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x803816F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803816F8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x803816FC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80381700: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80381704: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80381708: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8038170C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80381710: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80381714: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80381718: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8038171C: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x80381720: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80381724: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80381728: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8038172C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80381730: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80381734: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80381738: jal         0x80005E44
    // 0x8038173C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8038173C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80381740: jal         0x80006214
    // 0x80381744: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80381744: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80381748: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8038174C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80381750: addiu       $a2, $zero, 0x4B2
    ctx->r6 = ADD32(0, 0X4B2);
    // 0x80381754: jal         0x8012C89C
    // 0x80381758: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80381758: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8038175C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80381760: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80381764: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80381768: addiu       $a1, $zero, 0x4B2
    ctx->r5 = ADD32(0, 0X4B2);
    // 0x8038176C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80381770: jal         0x8012D814
    // 0x80381774: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    LOOKUP_FUNC(0x8012D814)(rdram, ctx);
        goto after_3;
    // 0x80381774: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80381778: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8038177C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80381780: lui         $t1, 0x6
    ctx->r9 = S32(0X6 << 16);
    // 0x80381784: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80381788: lwc1        $f0, -0x6514($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6514);
    // 0x8038178C: ori         $t1, $t1, 0x300
    ctx->r9 = ctx->r9 | 0X300;
    // 0x80381790: sw          $t1, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r9;
    // 0x80381794: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80381798: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8038179C: addiu       $t4, $t4, -0x7168
    ctx->r12 = ADD32(ctx->r12, -0X7168);
    // 0x803817A0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x803817A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x803817A8: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x803817AC: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x803817B0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x803817B4: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x803817B8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x803817BC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803817C0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x803817C4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x803817C8: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x803817CC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x803817D0: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x803817D4: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x803817D8: swc1        $f6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f6.u32l;
    // 0x803817DC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x803817E0: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x803817E4: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x803817E8: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x803817EC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x803817F0: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x803817F4: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x803817F8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x803817FC: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80381800: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x80381804: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80381808: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8038180C: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
    // 0x80381810: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80381814: lbu         $t0, 0x204($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X204);
    // 0x80381818: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x8038181C: sb          $t0, 0x48($t1)
    MEM_B(0X48, ctx->r9) = ctx->r8;
    // 0x80381820: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80381824: lbu         $t3, 0x205($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X205);
    // 0x80381828: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x8038182C: sb          $t3, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r11;
    // 0x80381830: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381834: lbu         $t5, 0x206($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X206);
    // 0x80381838: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8038183C: sb          $t5, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r13;
    // 0x80381840: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80381844: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x80381848: sb          $zero, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = 0;
    // 0x8038184C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80381850: lbu         $t0, 0x208($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X208);
    // 0x80381854: lw          $t4, 0x30($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X30);
    // 0x80381858: sb          $t0, 0x4C($t4)
    MEM_B(0X4C, ctx->r12) = ctx->r8;
    // 0x8038185C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80381860: lbu         $t3, 0x209($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X209);
    // 0x80381864: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80381868: sb          $t3, 0x4D($t7)
    MEM_B(0X4D, ctx->r15) = ctx->r11;
    // 0x8038186C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80381870: lbu         $t5, 0x20A($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X20A);
    // 0x80381874: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80381878: sb          $t5, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r13;
    // 0x8038187C: jal         0x8012C6B4
    // 0x80381880: sb          $zero, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = 0;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80381880: sb          $zero, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = 0;
    after_4:
    // 0x80381884: addiu       $t2, $v0, 0x4
    ctx->r10 = ADD32(ctx->r2, 0X4);
    // 0x80381888: sh          $t2, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = ctx->r10;
    // 0x8038188C: sh          $zero, 0xA6($s1)
    MEM_H(0XA6, ctx->r17) = 0;
    // 0x80381890: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80381894: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80381898: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8038189C: jr          $ra
    // 0x803818A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x803818A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803818a4(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803818a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803818A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x803818A8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x803818AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803818B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x803818B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x803818B8: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x803818BC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x803818C0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x803818C4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x803818C8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x803818CC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x803818D0: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x803818D4: ori         $t9, $t9, 0x300
    ctx->r25 = ctx->r25 | 0X300;
    // 0x803818D8: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x803818DC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x803818E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x803818E4: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x803818E8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x803818EC: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x803818F0: jal         0x80005E44
    // 0x803818F4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x803818F4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x803818F8: jal         0x80006214
    // 0x803818FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x803818FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80381900: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80381904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80381908: addiu       $a2, $zero, 0x4B4
    ctx->r6 = ADD32(0, 0X4B4);
    // 0x8038190C: jal         0x8012C89C
    // 0x80381910: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80381910: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80381914: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381918: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8038191C: addiu       $a2, $zero, 0x4B4
    ctx->r6 = ADD32(0, 0X4B4);
    // 0x80381920: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    // 0x80381924: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80381928: jal         0x8012CF8C
    // 0x8038192C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x8038192C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x80381930: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80381934: addiu       $t1, $zero, 0x300
    ctx->r9 = ADD32(0, 0X300);
    // 0x80381938: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8038193C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80381940: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80381944: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x80381948: sw          $t1, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r9;
    // 0x8038194C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80381950: addiu       $t4, $t4, -0x7168
    ctx->r12 = ADD32(ctx->r12, -0X7168);
    // 0x80381954: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80381958: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8038195C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80381960: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80381964: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x80381968: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8038196C: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80381970: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80381974: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80381978: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8038197C: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80381980: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x80381984: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381988: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x8038198C: addiu       $v1, $v1, -0x7108
    ctx->r3 = ADD32(ctx->r3, -0X7108);
    // 0x80381990: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80381994: swc1        $f6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f6.u32l;
    // 0x80381998: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8038199C: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x803819A0: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x803819A4: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x803819A8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x803819AC: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x803819B0: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x803819B4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x803819B8: lwc1        $f10, -0x6510($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6510);
    // 0x803819BC: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x803819C0: swc1        $f10, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f10.u32l;
    // 0x803819C4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x803819C8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803819CC: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
    // 0x803819D0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x803819D4: lbu         $t0, 0x204($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X204);
    // 0x803819D8: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x803819DC: sb          $t0, 0x48($t1)
    MEM_B(0X48, ctx->r9) = ctx->r8;
    // 0x803819E0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x803819E4: lbu         $t3, 0x205($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X205);
    // 0x803819E8: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x803819EC: sb          $t3, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r11;
    // 0x803819F0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x803819F4: lbu         $t5, 0x206($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X206);
    // 0x803819F8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x803819FC: sb          $t5, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r13;
    // 0x80381A00: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80381A04: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x80381A08: sb          $zero, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = 0;
    // 0x80381A0C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80381A10: lbu         $t0, 0x208($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X208);
    // 0x80381A14: lw          $t4, 0x30($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X30);
    // 0x80381A18: sb          $t0, 0x4C($t4)
    MEM_B(0X4C, ctx->r12) = ctx->r8;
    // 0x80381A1C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80381A20: lbu         $t3, 0x209($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X209);
    // 0x80381A24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80381A28: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80381A2C: sb          $t3, 0x4D($t7)
    MEM_B(0X4D, ctx->r15) = ctx->r11;
    // 0x80381A30: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80381A34: lbu         $t5, 0x20A($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X20A);
    // 0x80381A38: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80381A3C: sb          $t5, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r13;
    // 0x80381A40: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x80381A44: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x80381A48: sh          $zero, 0xA6($s1)
    MEM_H(0XA6, ctx->r17) = 0;
    // 0x80381A4C: sb          $t2, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = ctx->r10;
    // 0x80381A50: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80381A54: bnel        $t1, $zero, L_80381A68
    if (ctx->r9 != 0) {
        // 0x80381A58: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_80381A68;
    }
    goto skip_0;
    // 0x80381A58: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    skip_0:
    // 0x80381A5C: b           L_80381A68
    // 0x80381A60: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
        goto L_80381A68;
    // 0x80381A60: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x80381A64: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80381A68:
    // 0x80381A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80381A6C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80381A70: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80381A74: jr          $ra
    // 0x80381A78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80381A78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80381a7c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80381a7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381A7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80381A80: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80381A84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80381A88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80381A8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80381A90: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80381A94: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80381A98: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80381A9C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80381AA0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80381AA4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80381AA8: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80381AAC: ori         $t9, $t9, 0x300
    ctx->r25 = ctx->r25 | 0X300;
    // 0x80381AB0: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80381AB4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80381AB8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80381ABC: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80381AC0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80381AC4: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80381AC8: jal         0x80005E44
    // 0x80381ACC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80381ACC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x80381AD0: jal         0x80006214
    // 0x80381AD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80381AD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80381AD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80381ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80381AE0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80381AE4: jal         0x8012C89C
    // 0x80381AE8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80381AE8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80381AEC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80381AF0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80381AF4: lwc1        $f0, -0x650C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X650C);
    // 0x80381AF8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80381AFC: addiu       $t0, $zero, 0x300
    ctx->r8 = ADD32(0, 0X300);
    // 0x80381B00: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80381B04: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x80381B08: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80381B0C: addiu       $t3, $t3, -0x7168
    ctx->r11 = ADD32(ctx->r11, -0X7168);
    // 0x80381B10: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80381B14: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80381B18: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80381B1C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80381B20: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x80381B24: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381B28: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80381B2C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80381B30: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80381B34: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80381B38: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x80381B3C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80381B40: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80381B44: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80381B48: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x80381B4C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381B50: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80381B54: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80381B58: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x80381B5C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80381B60: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80381B64: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80381B68: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80381B6C: lwc1        $f10, -0x6508($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6508);
    // 0x80381B70: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80381B74: swc1        $f10, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f10.u32l;
    // 0x80381B78: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381B7C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80381B80: swc1        $f0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f0.u32l;
    // 0x80381B84: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80381B88: lbu         $t9, 0x204($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X204);
    // 0x80381B8C: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x80381B90: sb          $t9, 0x48($t0)
    MEM_B(0X48, ctx->r8) = ctx->r25;
    // 0x80381B94: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80381B98: lbu         $t2, 0x205($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X205);
    // 0x80381B9C: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80381BA0: sb          $t2, 0x49($t5)
    MEM_B(0X49, ctx->r13) = ctx->r10;
    // 0x80381BA4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80381BA8: lbu         $t4, 0x206($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X206);
    // 0x80381BAC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80381BB0: sb          $t4, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r12;
    // 0x80381BB4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80381BB8: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x80381BBC: sb          $zero, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = 0;
    // 0x80381BC0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381BC4: lbu         $t9, 0x208($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X208);
    // 0x80381BC8: lw          $t3, 0x30($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X30);
    // 0x80381BCC: sb          $t9, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r25;
    // 0x80381BD0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80381BD4: lbu         $t2, 0x209($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X209);
    // 0x80381BD8: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80381BDC: sb          $t2, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = ctx->r10;
    // 0x80381BE0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381BE4: lbu         $t4, 0x20A($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X20A);
    // 0x80381BE8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80381BEC: sb          $t4, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = ctx->r12;
    // 0x80381BF0: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x80381BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80381BF8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80381BFC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80381C00: jr          $ra
    // 0x80381C04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80381C04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80381c08(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80381c08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381C08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80381C0C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80381C10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80381C14: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80381C18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80381C1C: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80381C20: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80381C24: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80381C28: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80381C2C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80381C30: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80381C34: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80381C38: ori         $t9, $t9, 0x300
    ctx->r25 = ctx->r25 | 0X300;
    // 0x80381C3C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80381C40: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80381C44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80381C48: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80381C4C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80381C50: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80381C54: jal         0x80005E44
    // 0x80381C58: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80381C58: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x80381C5C: jal         0x80006214
    // 0x80381C60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80381C60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80381C64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80381C68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80381C6C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80381C70: jal         0x8012C89C
    // 0x80381C74: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80381C74: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80381C78: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80381C7C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80381C80: lwc1        $f0, -0x6504($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6504);
    // 0x80381C84: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80381C88: addiu       $t0, $zero, 0x300
    ctx->r8 = ADD32(0, 0X300);
    // 0x80381C8C: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80381C90: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x80381C94: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80381C98: addiu       $t3, $t3, -0x7168
    ctx->r11 = ADD32(ctx->r11, -0X7168);
    // 0x80381C9C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80381CA0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80381CA4: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80381CA8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80381CAC: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x80381CB0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381CB4: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80381CB8: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x80381CBC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80381CC0: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x80381CC4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80381CC8: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80381CCC: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80381CD0: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x80381CD4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381CD8: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80381CDC: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80381CE0: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x80381CE4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80381CE8: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80381CEC: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80381CF0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80381CF4: lwc1        $f10, -0x6500($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6500);
    // 0x80381CF8: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80381CFC: swc1        $f10, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f10.u32l;
    // 0x80381D00: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381D04: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80381D08: swc1        $f0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f0.u32l;
    // 0x80381D0C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80381D10: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80381D14: sb          $v0, 0x48($t1)
    MEM_B(0X48, ctx->r9) = ctx->r2;
    // 0x80381D18: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381D1C: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80381D20: sb          $v0, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r2;
    // 0x80381D24: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80381D28: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80381D2C: sb          $v0, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = ctx->r2;
    // 0x80381D30: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80381D34: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80381D38: sb          $zero, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = 0;
    // 0x80381D3C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381D40: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80381D44: sb          $zero, 0x4C($t8)
    MEM_B(0X4C, ctx->r24) = 0;
    // 0x80381D48: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80381D4C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80381D50: sb          $zero, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = 0;
    // 0x80381D54: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381D58: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80381D5C: sb          $zero, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = 0;
    // 0x80381D60: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x80381D64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80381D68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80381D6C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80381D70: jr          $ra
    // 0x80381D74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80381D74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80381d78(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80381d78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381D78: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80381D7C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80381D80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80381D84: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80381D88: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80381D8C: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80381D90: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80381D94: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80381D98: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80381D9C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80381DA0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80381DA4: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80381DA8: ori         $t9, $t9, 0x300
    ctx->r25 = ctx->r25 | 0X300;
    // 0x80381DAC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80381DB0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80381DB4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80381DB8: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80381DBC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80381DC0: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80381DC4: jal         0x80005E44
    // 0x80381DC8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80381DC8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80381DCC: jal         0x80006214
    // 0x80381DD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80381DD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80381DD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80381DD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80381DDC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80381DE0: jal         0x8012C89C
    // 0x80381DE4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80381DE4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80381DE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80381DEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80381DF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80381DF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80381DF8: jal         0x8012D918
    // 0x80381DFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D918)(rdram, ctx);
        goto after_3;
    // 0x80381DFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80381E00: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80381E04: addiu       $t0, $zero, 0x300
    ctx->r8 = ADD32(0, 0X300);
    // 0x80381E08: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80381E0C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80381E10: addiu       $t3, $t3, -0x7168
    ctx->r11 = ADD32(ctx->r11, -0X7168);
    // 0x80381E14: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80381E18: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x80381E1C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80381E20: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80381E24: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    // 0x80381E28: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80381E2C: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x80381E30: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381E34: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80381E38: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80381E3C: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x80381E40: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80381E44: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80381E48: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80381E4C: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x80381E50: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381E54: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80381E58: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80381E5C: jal         0x8012C6B4
    // 0x80381E60: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80381E60: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    after_4:
    // 0x80381E64: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80381E68: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    // 0x80381E6C: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80381E70: jal         0x8012C6B4
    // 0x80381E74: sh          $v0, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r2;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80381E74: sh          $v0, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r2;
    after_5:
    // 0x80381E78: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80381E7C: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    // 0x80381E80: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80381E84: jal         0x8012C6B4
    // 0x80381E88: sh          $v0, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r2;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x80381E88: sh          $v0, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r2;
    after_6:
    // 0x80381E8C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381E90: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80381E94: lwc1        $f0, -0x64FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X64FC);
    // 0x80381E98: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80381E9C: sh          $v0, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r2;
    // 0x80381EA0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80381EA4: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80381EA8: swc1        $f0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f0.u32l;
    // 0x80381EAC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381EB0: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80381EB4: swc1        $f0, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f0.u32l;
    // 0x80381EB8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80381EBC: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80381EC0: swc1        $f0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f0.u32l;
    // 0x80381EC4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80381EC8: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80381ECC: sb          $zero, 0x48($t6)
    MEM_B(0X48, ctx->r14) = 0;
    // 0x80381ED0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381ED4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80381ED8: sb          $zero, 0x49($t8)
    MEM_B(0X49, ctx->r24) = 0;
    // 0x80381EDC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80381EE0: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80381EE4: sb          $zero, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = 0;
    // 0x80381EE8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80381EEC: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80381EF0: sb          $zero, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = 0;
    // 0x80381EF4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80381EF8: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80381EFC: sb          $zero, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = 0;
    // 0x80381F00: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80381F04: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80381F08: sb          $zero, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = 0;
    // 0x80381F0C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381F10: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80381F14: sb          $zero, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = 0;
    // 0x80381F18: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x80381F1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80381F20: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80381F24: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80381F28: jr          $ra
    // 0x80381F2C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80381F2C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80381f30(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80381f30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381F30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80381F34: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80381F38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80381F3C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80381F40: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80381F44: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80381F48: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80381F4C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80381F50: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80381F54: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80381F58: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80381F5C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80381F60: ori         $t9, $t9, 0x300
    ctx->r25 = ctx->r25 | 0X300;
    // 0x80381F64: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80381F68: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80381F6C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80381F70: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80381F74: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80381F78: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80381F7C: jal         0x80005E44
    // 0x80381F80: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80381F80: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    after_0:
    // 0x80381F84: jal         0x80006214
    // 0x80381F88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80381F88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80381F8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80381F90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80381F94: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80381F98: jal         0x8012C89C
    // 0x80381F9C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80381F9C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80381FA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80381FA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80381FA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80381FAC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80381FB0: jal         0x8012D814
    // 0x80381FB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D814)(rdram, ctx);
        goto after_3;
    // 0x80381FB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80381FB8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80381FBC: lui         $t0, 0x6
    ctx->r8 = S32(0X6 << 16);
    // 0x80381FC0: ori         $t0, $t0, 0x300
    ctx->r8 = ctx->r8 | 0X300;
    // 0x80381FC4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80381FC8: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80381FCC: addiu       $t3, $t3, -0x7168
    ctx->r11 = ADD32(ctx->r11, -0X7168);
    // 0x80381FD0: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x80381FD4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80381FD8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80381FDC: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80381FE0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80381FE4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80381FE8: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x80381FEC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80381FF0: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80381FF4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80381FF8: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x80381FFC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80382000: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80382004: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80382008: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x8038200C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80382010: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80382014: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80382018: jal         0x8012C6B4
    // 0x8038201C: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x8038201C: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    after_4:
    // 0x80382020: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80382024: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382028: ldc1        $f18, -0x64F8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X64F8);
    // 0x8038202C: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80382030: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382034: ldc1        $f6, -0x64F0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X64F0);
    // 0x80382038: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8038203C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80382040: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80382044: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80382048: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8038204C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80382050: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80382054: swc1        $f0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f0.u32l;
    // 0x80382058: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8038205C: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80382060: addiu       $t4, $zero, 0x8C
    ctx->r12 = ADD32(0, 0X8C);
    // 0x80382064: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x80382068: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8038206C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80382070: swc1        $f0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f0.u32l;
    // 0x80382074: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80382078: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x8038207C: sb          $v1, 0x48($t1)
    MEM_B(0X48, ctx->r9) = ctx->r3;
    // 0x80382080: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80382084: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80382088: sb          $v1, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r3;
    // 0x8038208C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80382090: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80382094: sb          $v1, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = ctx->r3;
    // 0x80382098: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8038209C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x803820A0: sb          $t4, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r12;
    // 0x803820A4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x803820A8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803820AC: sb          $a0, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r4;
    // 0x803820B0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x803820B4: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x803820B8: sb          $a0, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = ctx->r4;
    // 0x803820BC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x803820C0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x803820C4: sb          $a0, 0x4E($t3)
    MEM_B(0X4E, ctx->r11) = ctx->r4;
    // 0x803820C8: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x803820CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x803820D0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x803820D4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x803820D8: jr          $ra
    // 0x803820DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x803820DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803820e0(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803820e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803820E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x803820E4: jr          $ra
    // 0x803820E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x803820E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803820ec(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803820ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803820EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x803820F0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x803820F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803820F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x803820FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80382100: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80382104: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80382108: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8038210C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80382110: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80382114: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80382118: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8038211C: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x80382120: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80382124: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80382128: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8038212C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80382130: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80382134: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80382138: jal         0x80005E44
    // 0x8038213C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8038213C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x80382140: jal         0x80006214
    // 0x80382144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80382144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80382148: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8038214C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80382150: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80382154: jal         0x8012C89C
    // 0x80382158: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80382158: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8038215C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80382160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80382164: addiu       $a2, $zero, 0x374
    ctx->r6 = ADD32(0, 0X374);
    // 0x80382168: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    // 0x8038216C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80382170: jal         0x8012CF8C
    // 0x80382174: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x80382174: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x80382178: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8038217C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382180: lui         $t1, 0x6
    ctx->r9 = S32(0X6 << 16);
    // 0x80382184: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80382188: lwc1        $f0, -0x64E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X64E8);
    // 0x8038218C: ori         $t1, $t1, 0x300
    ctx->r9 = ctx->r9 | 0X300;
    // 0x80382190: sw          $t1, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r9;
    // 0x80382194: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80382198: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8038219C: addiu       $t4, $t4, -0x7168
    ctx->r12 = ADD32(ctx->r12, -0X7168);
    // 0x803821A0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x803821A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x803821A8: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x803821AC: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x803821B0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x803821B4: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x803821B8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x803821BC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803821C0: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    // 0x803821C4: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x803821C8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x803821CC: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x803821D0: swc1        $f0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f0.u32l;
    // 0x803821D4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x803821D8: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x803821DC: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    // 0x803821E0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x803821E4: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x803821E8: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    // 0x803821EC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x803821F0: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x803821F4: sb          $v0, 0x48($t7)
    MEM_B(0X48, ctx->r15) = ctx->r2;
    // 0x803821F8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x803821FC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80382200: sb          $v0, 0x49($t9)
    MEM_B(0X49, ctx->r25) = ctx->r2;
    // 0x80382204: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80382208: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x8038220C: sb          $v0, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = ctx->r2;
    // 0x80382210: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80382214: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80382218: jal         0x8012C6B4
    // 0x8038221C: sb          $zero, 0x4B($t3)
    MEM_B(0X4B, ctx->r11) = 0;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x8038221C: sb          $zero, 0x4B($t3)
    MEM_B(0X4B, ctx->r11) = 0;
    after_4:
    // 0x80382220: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80382224: addiu       $t4, $v0, 0x40
    ctx->r12 = ADD32(ctx->r2, 0X40);
    // 0x80382228: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    // 0x8038222C: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80382230: jal         0x8012C6B4
    // 0x80382234: sb          $t4, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = ctx->r12;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80382234: sb          $t4, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = ctx->r12;
    after_5:
    // 0x80382238: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8038223C: addiu       $t7, $v0, 0x40
    ctx->r15 = ADD32(ctx->r2, 0X40);
    // 0x80382240: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    // 0x80382244: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80382248: jal         0x8012C6B4
    // 0x8038224C: sb          $t7, 0x4D($t9)
    MEM_B(0X4D, ctx->r25) = ctx->r15;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x8038224C: sb          $t7, 0x4D($t9)
    MEM_B(0X4D, ctx->r25) = ctx->r15;
    after_6:
    // 0x80382250: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80382254: addiu       $t0, $v0, 0x40
    ctx->r8 = ADD32(ctx->r2, 0X40);
    // 0x80382258: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    // 0x8038225C: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80382260: jal         0x8012C6B4
    // 0x80382264: sb          $t0, 0x4E($t1)
    MEM_B(0X4E, ctx->r9) = ctx->r8;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x80382264: sb          $t0, 0x4E($t1)
    MEM_B(0X4E, ctx->r9) = ctx->r8;
    after_7:
    // 0x80382268: sh          $v0, 0xA0($s1)
    MEM_H(0XA0, ctx->r17) = ctx->r2;
    // 0x8038226C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80382270: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80382274: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80382278: jr          $ra
    // 0x8038227C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8038227C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80382280(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80382280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382280: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80382284: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80382288: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8038228C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80382290: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80382294: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80382298: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8038229C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x803822A0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x803822A4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x803822A8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x803822AC: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x803822B0: ori         $t9, $t9, 0x300
    ctx->r25 = ctx->r25 | 0X300;
    // 0x803822B4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x803822B8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x803822BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x803822C0: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x803822C4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x803822C8: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x803822CC: jal         0x80005E44
    // 0x803822D0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x803822D0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x803822D4: jal         0x80006214
    // 0x803822D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x803822D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x803822DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x803822E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803822E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x803822E8: jal         0x8012C89C
    // 0x803822EC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x803822EC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x803822F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x803822F4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x803822F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x803822FC: addiu       $a1, $zero, 0x4B1
    ctx->r5 = ADD32(0, 0X4B1);
    // 0x80382300: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80382304: jal         0x8012D814
    // 0x80382308: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    LOOKUP_FUNC(0x8012D814)(rdram, ctx);
        goto after_3;
    // 0x80382308: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x8038230C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80382310: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382314: lwc1        $f0, -0x64E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X64E4);
    // 0x80382318: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x8038231C: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
    // 0x80382320: ori         $at, $at, 0x300
    ctx->r1 = ctx->r1 | 0X300;
    // 0x80382324: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x80382328: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8038232C: addiu       $t4, $t4, -0x7168
    ctx->r12 = ADD32(ctx->r12, -0X7168);
    // 0x80382330: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80382334: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x80382338: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8038233C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80382340: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80382344: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80382348: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8038234C: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    // 0x80382350: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80382354: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80382358: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8038235C: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x80382360: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80382364: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80382368: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8038236C: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x80382370: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80382374: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80382378: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8038237C: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x80382380: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80382384: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80382388: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
    // 0x8038238C: sb          $v1, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r3;
    // 0x80382390: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80382394: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80382398: sb          $v1, 0x49($t7)
    MEM_B(0X49, ctx->r15) = ctx->r3;
    // 0x8038239C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x803823A0: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803823A4: sb          $v1, 0x4A($t9)
    MEM_B(0X4A, ctx->r25) = ctx->r3;
    // 0x803823A8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x803823AC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x803823B0: sb          $zero, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = 0;
    // 0x803823B4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x803823B8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x803823BC: sb          $zero, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = 0;
    // 0x803823C0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x803823C4: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x803823C8: sb          $t4, 0x4D($t5)
    MEM_B(0X4D, ctx->r13) = ctx->r12;
    // 0x803823CC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x803823D0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x803823D4: sb          $v1, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = ctx->r3;
    // 0x803823D8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x803823DC: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x803823E0: swc1        $f0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f0.u32l;
    // 0x803823E4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x803823E8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x803823EC: swc1        $f0, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f0.u32l;
    // 0x803823F0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x803823F4: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x803823F8: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    // 0x803823FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80382400: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80382404: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80382408: jr          $ra
    // 0x8038240C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8038240C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80382410(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80382410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382410: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80382414: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80382418: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8038241C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80382420: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80382424: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80382428: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8038242C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80382430: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80382434: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80382438: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8038243C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80382440: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x80382444: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80382448: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8038244C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80382450: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80382454: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80382458: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x8038245C: jal         0x80005E44
    // 0x80382460: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80382460: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80382464: jal         0x80006214
    // 0x80382468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80382468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8038246C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80382470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80382474: addiu       $a2, $zero, 0x4B5
    ctx->r6 = ADD32(0, 0X4B5);
    // 0x80382478: jal         0x8012C89C
    // 0x8038247C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x8038247C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80382480: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80382484: addiu       $a1, $zero, 0x4B5
    ctx->r5 = ADD32(0, 0X4B5);
    // 0x80382488: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8038248C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80382490: jal         0x8012D918
    // 0x80382494: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D918)(rdram, ctx);
        goto after_3;
    // 0x80382494: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80382498: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8038249C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803824A0: lwc1        $f0, -0x64E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X64E0);
    // 0x803824A4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x803824A8: addiu       $t0, $zero, 0x300
    ctx->r8 = ADD32(0, 0X300);
    // 0x803824AC: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x803824B0: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x803824B4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x803824B8: addiu       $t3, $t3, -0x7168
    ctx->r11 = ADD32(ctx->r11, -0X7168);
    // 0x803824BC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x803824C0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x803824C4: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x803824C8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x803824CC: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x803824D0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x803824D4: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x803824D8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x803824DC: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x803824E0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x803824E4: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x803824E8: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x803824EC: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x803824F0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x803824F4: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x803824F8: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x803824FC: addiu       $t0, $zero, 0xF3
    ctx->r8 = ADD32(0, 0XF3);
    // 0x80382500: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x80382504: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80382508: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x8038250C: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80382510: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80382514: addiu       $t5, $zero, 0x22
    ctx->r13 = ADD32(0, 0X22);
    // 0x80382518: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x8038251C: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x80382520: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80382524: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80382528: addiu       $t7, $zero, 0xC0
    ctx->r15 = ADD32(0, 0XC0);
    // 0x8038252C: swc1        $f0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f0.u32l;
    // 0x80382530: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80382534: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80382538: sb          $v0, 0x48($t1)
    MEM_B(0X48, ctx->r9) = ctx->r2;
    // 0x8038253C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80382540: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80382544: sb          $t0, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r8;
    // 0x80382548: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8038254C: addiu       $t0, $zero, 0x66
    ctx->r8 = ADD32(0, 0X66);
    // 0x80382550: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80382554: sb          $t5, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r13;
    // 0x80382558: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8038255C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80382560: sb          $t7, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r15;
    // 0x80382564: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80382568: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8038256C: sb          $v0, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = ctx->r2;
    // 0x80382570: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80382574: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80382578: sb          $t0, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r8;
    // 0x8038257C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80382580: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80382584: sb          $zero, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = 0;
    // 0x80382588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8038258C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80382590: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80382594: jr          $ra
    // 0x80382598: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80382598: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8038259c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8038259c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038259C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x803825A0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x803825A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803825A8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x803825AC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x803825B0: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x803825B4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x803825B8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x803825BC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x803825C0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x803825C4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x803825C8: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x803825CC: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x803825D0: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x803825D4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x803825D8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x803825DC: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x803825E0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x803825E4: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x803825E8: jal         0x80005E44
    // 0x803825EC: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x803825EC: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x803825F0: jal         0x80006214
    // 0x803825F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x803825F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x803825F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x803825FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80382600: addiu       $a2, $zero, 0x4B5
    ctx->r6 = ADD32(0, 0X4B5);
    // 0x80382604: jal         0x8012C89C
    // 0x80382608: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80382608: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8038260C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80382610: addiu       $a1, $zero, 0x4B5
    ctx->r5 = ADD32(0, 0X4B5);
    // 0x80382614: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80382618: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8038261C: jal         0x8012D918
    // 0x80382620: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D918)(rdram, ctx);
        goto after_3;
    // 0x80382620: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80382624: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80382628: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038262C: lwc1        $f0, -0x64DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X64DC);
    // 0x80382630: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80382634: addiu       $t0, $zero, 0x300
    ctx->r8 = ADD32(0, 0X300);
    // 0x80382638: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x8038263C: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x80382640: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80382644: addiu       $t3, $t3, -0x7168
    ctx->r11 = ADD32(ctx->r11, -0X7168);
    // 0x80382648: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8038264C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80382650: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80382654: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80382658: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x8038265C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80382660: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80382664: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80382668: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x8038266C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80382670: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80382674: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80382678: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x8038267C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80382680: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80382684: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80382688: addiu       $t0, $zero, 0xF3
    ctx->r8 = ADD32(0, 0XF3);
    // 0x8038268C: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x80382690: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80382694: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80382698: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x8038269C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x803826A0: addiu       $t5, $zero, 0x22
    ctx->r13 = ADD32(0, 0X22);
    // 0x803826A4: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x803826A8: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x803826AC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x803826B0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x803826B4: swc1        $f0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f0.u32l;
    // 0x803826B8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x803826BC: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x803826C0: sb          $v0, 0x48($t1)
    MEM_B(0X48, ctx->r9) = ctx->r2;
    // 0x803826C4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x803826C8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x803826CC: addiu       $t2, $zero, 0x66
    ctx->r10 = ADD32(0, 0X66);
    // 0x803826D0: sb          $t0, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r8;
    // 0x803826D4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x803826D8: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x803826DC: sb          $t5, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r13;
    // 0x803826E0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x803826E4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x803826E8: sb          $zero, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = 0;
    // 0x803826EC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x803826F0: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x803826F4: sb          $v0, 0x4C($t1)
    MEM_B(0X4C, ctx->r9) = ctx->r2;
    // 0x803826F8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x803826FC: lw          $t3, 0x30($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X30);
    // 0x80382700: sb          $t2, 0x4D($t3)
    MEM_B(0X4D, ctx->r11) = ctx->r10;
    // 0x80382704: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80382708: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8038270C: sb          $zero, 0x4E($t5)
    MEM_B(0X4E, ctx->r13) = 0;
    // 0x80382710: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80382714: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80382718: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8038271C: jr          $ra
    // 0x80382720: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80382720: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80382724(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80382724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382724: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80382728: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8038272C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80382730: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80382734: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80382738: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x8038273C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80382740: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80382744: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80382748: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8038274C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80382750: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80382754: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x80382758: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8038275C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80382760: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80382764: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80382768: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8038276C: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80382770: jal         0x80005E44
    // 0x80382774: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80382774: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80382778: jal         0x80006214
    // 0x8038277C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x8038277C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80382780: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80382784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80382788: addiu       $a2, $zero, 0x4B4
    ctx->r6 = ADD32(0, 0X4B4);
    // 0x8038278C: jal         0x8012C89C
    // 0x80382790: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80382790: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80382794: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80382798: addiu       $a1, $zero, 0x4B4
    ctx->r5 = ADD32(0, 0X4B4);
    // 0x8038279C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x803827A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x803827A4: jal         0x8012D918
    // 0x803827A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D918)(rdram, ctx);
        goto after_3;
    // 0x803827A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x803827AC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x803827B0: addiu       $t0, $zero, 0x300
    ctx->r8 = ADD32(0, 0X300);
    // 0x803827B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x803827B8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x803827BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x803827C0: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x803827C4: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x803827C8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x803827CC: addiu       $t3, $t3, -0x7168
    ctx->r11 = ADD32(ctx->r11, -0X7168);
    // 0x803827D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x803827D4: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x803827D8: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x803827DC: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x803827E0: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x803827E4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x803827E8: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x803827EC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803827F0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x803827F4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x803827F8: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x803827FC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80382800: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80382804: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80382808: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x8038280C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80382810: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80382814: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80382818: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x8038281C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80382820: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x80382824: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x80382828: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8038282C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80382830: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x80382834: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80382838: lwc1        $f10, -0x64D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X64D8);
    // 0x8038283C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80382840: swc1        $f10, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f10.u32l;
    // 0x80382844: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80382848: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x8038284C: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
    // 0x80382850: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80382854: lw          $t5, 0x30($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X30);
    // 0x80382858: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x8038285C: sb          $v0, 0x48($t5)
    MEM_B(0X48, ctx->r13) = ctx->r2;
    // 0x80382860: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80382864: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80382868: sb          $v0, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r2;
    // 0x8038286C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80382870: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80382874: sb          $v0, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r2;
    // 0x80382878: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8038287C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80382880: sb          $zero, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = 0;
    // 0x80382884: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80382888: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x8038288C: sb          $v0, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = ctx->r2;
    // 0x80382890: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80382894: lw          $t3, 0x30($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X30);
    // 0x80382898: sb          $t2, 0x4D($t3)
    MEM_B(0X4D, ctx->r11) = ctx->r10;
    // 0x8038289C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x803828A0: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x803828A4: sb          $zero, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = 0;
    // 0x803828A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x803828AC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x803828B0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x803828B4: jr          $ra
    // 0x803828B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x803828B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803828bc(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803828bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803828BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x803828C0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x803828C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803828C8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x803828CC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x803828D0: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x803828D4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x803828D8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x803828DC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x803828E0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x803828E4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x803828E8: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x803828EC: ori         $t9, $t9, 0x300
    ctx->r25 = ctx->r25 | 0X300;
    // 0x803828F0: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x803828F4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x803828F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x803828FC: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80382900: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80382904: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80382908: jal         0x80005E44
    // 0x8038290C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8038290C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    after_0:
    // 0x80382910: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80382914: jal         0x80005E44
    // 0x80382918: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x80382918: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x8038291C: jal         0x80006214
    // 0x80382920: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x80382920: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80382924: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80382928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8038292C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80382930: jal         0x8012C89C
    // 0x80382934: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x80382934: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x80382938: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8038293C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80382940: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80382944: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80382948: jal         0x8012D918
    // 0x8038294C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D918)(rdram, ctx);
        goto after_4;
    // 0x8038294C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80382950: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80382954: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382958: lwc1        $f0, -0x64D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X64D4);
    // 0x8038295C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80382960: addiu       $t1, $zero, 0x300
    ctx->r9 = ADD32(0, 0X300);
    // 0x80382964: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80382968: sw          $t1, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r9;
    // 0x8038296C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80382970: addiu       $v0, $v0, -0x7168
    ctx->r2 = ADD32(ctx->r2, -0X7168);
    // 0x80382974: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80382978: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8038297C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x80382980: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x80382984: sw          $v0, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r2;
    // 0x80382988: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8038298C: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80382990: addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
    // 0x80382994: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80382998: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8038299C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x803829A0: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x803829A4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x803829A8: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x803829AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x803829B0: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803829B4: addiu       $a2, $zero, 0x4B5
    ctx->r6 = ADD32(0, 0X4B5);
    // 0x803829B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x803829BC: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x803829C0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x803829C4: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x803829C8: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x803829CC: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x803829D0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x803829D4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x803829D8: sh          $t3, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r11;
    // 0x803829DC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x803829E0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x803829E4: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x803829E8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x803829EC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803829F0: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x803829F4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x803829F8: addiu       $t9, $zero, 0xDC
    ctx->r25 = ADD32(0, 0XDC);
    // 0x803829FC: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80382A00: swc1        $f0, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f0.u32l;
    // 0x80382A04: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80382A08: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x80382A0C: sb          $v1, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r3;
    // 0x80382A10: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80382A14: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80382A18: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x80382A1C: sb          $v1, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r3;
    // 0x80382A20: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80382A24: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80382A28: sb          $t0, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r8;
    // 0x80382A2C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80382A30: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80382A34: sb          $t9, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r25;
    // 0x80382A38: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80382A3C: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x80382A40: sb          $zero, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = 0;
    // 0x80382A44: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80382A48: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80382A4C: sb          $t5, 0x4D($t7)
    MEM_B(0X4D, ctx->r15) = ctx->r13;
    // 0x80382A50: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80382A54: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x80382A58: sb          $t0, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r8;
    // 0x80382A5C: jal         0x8012C89C
    // 0x80382A60: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_5;
    // 0x80382A60: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_5:
    // 0x80382A64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80382A68: addiu       $a1, $zero, 0x4B5
    ctx->r5 = ADD32(0, 0X4B5);
    // 0x80382A6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80382A70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80382A74: jal         0x8012D918
    // 0x80382A78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D918)(rdram, ctx);
        goto after_6;
    // 0x80382A78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80382A7C: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80382A80: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382A84: lwc1        $f0, -0x64D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X64D0);
    // 0x80382A88: lw          $t4, 0x30($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X30);
    // 0x80382A8C: addiu       $t9, $zero, 0x300
    ctx->r25 = ADD32(0, 0X300);
    // 0x80382A90: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // 0x80382A94: sw          $t9, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r25;
    // 0x80382A98: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80382A9C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80382AA0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80382AA4: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80382AA8: addiu       $t6, $zero, 0x1800
    ctx->r14 = ADD32(0, 0X1800);
    // 0x80382AAC: sw          $t3, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r11;
    // 0x80382AB0: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80382AB4: lwc1        $f10, 0x94($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80382AB8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80382ABC: swc1        $f10, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f10.u32l;
    // 0x80382AC0: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80382AC4: lwc1        $f16, 0x98($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80382AC8: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80382ACC: swc1        $f16, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f16.u32l;
    // 0x80382AD0: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80382AD4: lwc1        $f18, 0x9C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80382AD8: lw          $t4, 0x30($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X30);
    // 0x80382ADC: swc1        $f18, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f18.u32l;
    // 0x80382AE0: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80382AE4: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80382AE8: sh          $t6, 0x14($t5)
    MEM_H(0X14, ctx->r13) = ctx->r14;
    // 0x80382AEC: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80382AF0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80382AF4: swc1        $f0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f0.u32l;
    // 0x80382AF8: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80382AFC: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80382B00: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x80382B04: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80382B08: addiu       $t1, $zero, 0xDC
    ctx->r9 = ADD32(0, 0XDC);
    // 0x80382B0C: lw          $t4, 0x30($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X30);
    // 0x80382B10: swc1        $f0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f0.u32l;
    // 0x80382B14: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80382B18: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x80382B1C: sb          $v0, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r2;
    // 0x80382B20: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80382B24: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80382B28: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x80382B2C: sb          $v0, 0x49($t7)
    MEM_B(0X49, ctx->r15) = ctx->r2;
    // 0x80382B30: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80382B34: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x80382B38: sb          $v1, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = ctx->r3;
    // 0x80382B3C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80382B40: lw          $t4, 0x30($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X30);
    // 0x80382B44: sb          $t1, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r9;
    // 0x80382B48: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80382B4C: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x80382B50: sb          $zero, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = 0;
    // 0x80382B54: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80382B58: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80382B5C: sb          $t5, 0x4D($t8)
    MEM_B(0X4D, ctx->r24) = ctx->r13;
    // 0x80382B60: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80382B64: lw          $t9, 0x30($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X30);
    // 0x80382B68: sb          $v1, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r3;
    // 0x80382B6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80382B70: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80382B74: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80382B78: jr          $ra
    // 0x80382B7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80382B7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80382b80(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80382b80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382B80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80382B84: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80382B88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80382B8C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80382B90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80382B94: addiu       $t6, $t6, 0x4F40
    ctx->r14 = ADD32(ctx->r14, 0X4F40);
    // 0x80382B98: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80382B9C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80382BA0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80382BA4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80382BA8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80382BAC: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80382BB0: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x80382BB4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80382BB8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80382BBC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80382BC0: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80382BC4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80382BC8: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80382BCC: jal         0x80005E44
    // 0x80382BD0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80382BD0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x80382BD4: jal         0x80006214
    // 0x80382BD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80382BD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80382BDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80382BE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80382BE4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80382BE8: jal         0x8012C89C
    // 0x80382BEC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x80382BEC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80382BF0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80382BF4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382BF8: lwc1        $f0, -0x64CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X64CC);
    // 0x80382BFC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80382C00: addiu       $t0, $zero, 0x300
    ctx->r8 = ADD32(0, 0X300);
    // 0x80382C04: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80382C08: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x80382C0C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80382C10: addiu       $t3, $t3, -0x7168
    ctx->r11 = ADD32(ctx->r11, -0X7168);
    // 0x80382C14: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80382C18: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80382C1C: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80382C20: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382C24: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x80382C28: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80382C2C: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x80382C30: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80382C34: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80382C38: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x80382C3C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80382C40: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x80382C44: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80382C48: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x80382C4C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80382C50: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x80382C54: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80382C58: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x80382C5C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80382C60: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80382C64: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80382C68: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80382C6C: lwc1        $f10, -0x64C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X64C8);
    // 0x80382C70: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x80382C74: addiu       $t4, $zero, 0xC0
    ctx->r12 = ADD32(0, 0XC0);
    // 0x80382C78: swc1        $f10, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f10.u32l;
    // 0x80382C7C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80382C80: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80382C84: swc1        $f0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f0.u32l;
    // 0x80382C88: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80382C8C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80382C90: sb          $v0, 0x48($t1)
    MEM_B(0X48, ctx->r9) = ctx->r2;
    // 0x80382C94: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80382C98: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80382C9C: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80382CA0: sb          $v0, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r2;
    // 0x80382CA4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80382CA8: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80382CAC: sb          $v0, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = ctx->r2;
    // 0x80382CB0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80382CB4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80382CB8: sb          $t4, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r12;
    // 0x80382CBC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80382CC0: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80382CC4: sb          $zero, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = 0;
    // 0x80382CC8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80382CCC: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80382CD0: sb          $t1, 0x4D($t2)
    MEM_B(0X4D, ctx->r10) = ctx->r9;
    // 0x80382CD4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80382CD8: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80382CDC: sb          $v0, 0x4E($t5)
    MEM_B(0X4E, ctx->r13) = ctx->r2;
    // 0x80382CE0: sh          $zero, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = 0;
    // 0x80382CE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80382CE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80382CEC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80382CF0: jr          $ra
    // 0x80382CF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80382CF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80382cf8(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80382cf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382CF8: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80382CFC: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x80382D00: sw          $s3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r19;
    // 0x80382D04: sw          $s2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r18;
    // 0x80382D08: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    // 0x80382D0C: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
    // 0x80382D10: sdc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X68, ctx->r29);
    // 0x80382D14: sdc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X60, ctx->r29);
    // 0x80382D18: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x80382D1C: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x80382D20: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x80382D24: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80382D28: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80382D2C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80382D30: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80382D34: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80382D38: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x80382D3C: jal         0x8012C6B4
    // 0x80382D40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80382D40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_0:
    // 0x80382D44: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80382D48: jal         0x8012C6B4
    // 0x80382D4C: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80382D4C: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    after_1:
    // 0x80382D50: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80382D54: jal         0x8012C6B4
    // 0x80382D58: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80382D58: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_2:
    // 0x80382D5C: addiu       $t7, $s1, -0x1F4
    ctx->r15 = ADD32(ctx->r17, -0X1F4);
    // 0x80382D60: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80382D64: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80382D68: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80382D6C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80382D70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80382D74: addiu       $t8, $s3, -0x190
    ctx->r24 = ADD32(ctx->r19, -0X190);
    // 0x80382D78: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80382D7C: lwc1        $f10, 0x94($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80382D80: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x80382D84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80382D88: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80382D8C: addiu       $t9, $v0, -0x1F4
    ctx->r25 = ADD32(ctx->r2, -0X1F4);
    // 0x80382D90: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80382D94: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80382D98: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382D9C: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80382DA0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80382DA4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80382DA8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80382DAC: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80382DB0: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x80382DB4: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80382DB8: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x80382DBC: addiu       $t6, $zero, -0x4
    ctx->r14 = ADD32(0, -0X4);
    // 0x80382DC0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80382DC4: div.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x80382DC8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80382DCC: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80382DD0: lwc1        $f8, 0x98($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80382DD4: add.s       $f16, $f8, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x80382DD8: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80382DDC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x80382DE0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80382DE4: div.d       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x80382DE8: lwc1        $f8, -0x64C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X64C4);
    // 0x80382DEC: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x80382DF0: lwc1        $f10, 0x9C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x80382DF4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80382DF8: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80382DFC: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80382E00: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x80382E04: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80382E08: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80382E0C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80382E10: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80382E14: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80382E18: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80382E1C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80382E20: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80382E24: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x80382E28: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x80382E2C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80382E30: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80382E34: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80382E38: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80382E3C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80382E40: jal         0x80129FB8
    // 0x80382E44: nop

    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_3;
    // 0x80382E44: nop

    after_3:
    // 0x80382E48: bne         $s0, $zero, L_80382EEC
    if (ctx->r16 != 0) {
        // 0x80382E4C: addiu       $t8, $zero, 0x14
        ctx->r24 = ADD32(0, 0X14);
            goto L_80382EEC;
    }
    // 0x80382E4C: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80382E50: lwc1        $f12, 0x94($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80382E54: lwc1        $f14, 0x98($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80382E58: lw          $a2, 0x9C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X9C);
    // 0x80382E5C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80382E60: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80382E64: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x80382E68: jal         0x80380F94
    // 0x80382E6C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_4;
    // 0x80382E6C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_4:
    // 0x80382E70: lwc1        $f10, 0x98($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80382E74: lwc1        $f12, 0x94($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80382E78: lw          $a2, 0x9C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X9C);
    // 0x80382E7C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80382E80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80382E84: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382E88: lwc1        $f18, -0x64C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X64C0);
    // 0x80382E8C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80382E90: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80382E94: addiu       $t0, $zero, 0x84
    ctx->r8 = ADD32(0, 0X84);
    // 0x80382E98: addiu       $t1, $zero, 0x94
    ctx->r9 = ADD32(0, 0X94);
    // 0x80382E9C: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x80382EA0: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x80382EA4: addiu       $t4, $zero, -0x5
    ctx->r12 = ADD32(0, -0X5);
    // 0x80382EA8: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
    // 0x80382EAC: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80382EB0: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80382EB4: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80382EB8: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80382EBC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80382EC0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80382EC4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80382EC8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80382ECC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80382ED0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80382ED4: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x80382ED8: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x80382EDC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80382EE0: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80382EE4: jal         0x80129FB8
    // 0x80382EE8: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_5;
    // 0x80382EE8: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_5:
L_80382EEC:
    // 0x80382EEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80382EF0: bne         $s0, $at, L_80382F80
    if (ctx->r16 != ctx->r1) {
        // 0x80382EF4: addiu       $t6, $zero, 0x40
        ctx->r14 = ADD32(0, 0X40);
            goto L_80382F80;
    }
    // 0x80382EF4: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80382EF8: lwc1        $f4, 0x98($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80382EFC: lwc1        $f12, 0x94($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80382F00: lw          $a2, 0x9C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X9C);
    // 0x80382F04: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80382F08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80382F0C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382F10: lwc1        $f8, -0x64BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X64BC);
    // 0x80382F14: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382F18: lwc1        $f10, -0x64B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X64B8);
    // 0x80382F1C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80382F20: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80382F24: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80382F28: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80382F2C: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x80382F30: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x80382F34: addiu       $t2, $zero, 0xF0
    ctx->r10 = ADD32(0, 0XF0);
    // 0x80382F38: addiu       $t3, $zero, -0x2
    ctx->r11 = ADD32(0, -0X2);
    // 0x80382F3C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80382F40: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80382F44: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80382F48: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80382F4C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80382F50: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80382F54: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80382F58: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80382F5C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80382F60: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80382F64: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80382F68: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x80382F6C: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x80382F70: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80382F74: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80382F78: jal         0x80129FB8
    // 0x80382F7C: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_6;
    // 0x80382F7C: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_6:
L_80382F80:
    // 0x80382F80: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80382F84: bne         $at, $zero, L_80383068
    if (ctx->r1 != 0) {
        // 0x80382F88: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80383068;
    }
    // 0x80382F88: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80382F8C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80382F90: lwc1        $f26, -0x64B4($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X64B4);
    // 0x80382F94: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80382F98: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80382F9C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80382FA0: addiu       $s3, $zero, 0x22A2
    ctx->r19 = ADD32(0, 0X22A2);
    // 0x80382FA4: sll         $s1, $s0, 16
    ctx->r17 = S32(ctx->r16 << 16);
L_80382FA8:
    // 0x80382FA8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80382FAC: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x80382FB0: jal         0x8001EAD0
    // 0x80382FB4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x80382FB4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_7:
    // 0x80382FB8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x80382FBC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80382FC0: jal         0x8001EB64
    // 0x80382FC4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_8;
    // 0x80382FC4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_8:
    // 0x80382FC8: cvt.d.s     $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f18.d = CVT_D_S(ctx->f22.fl);
    // 0x80382FCC: lwc1        $f16, 0x98($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80382FD0: mul.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f20.d);
    // 0x80382FD4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80382FD8: lwc1        $f12, 0x94($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80382FDC: lw          $a2, 0x9C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X9C);
    // 0x80382FE0: mul.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x80382FE4: addiu       $t5, $zero, 0x4B
    ctx->r13 = ADD32(0, 0X4B);
    // 0x80382FE8: add.s       $f14, $f16, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f28.fl;
    // 0x80382FEC: addiu       $t6, $zero, 0x4B
    ctx->r14 = ADD32(0, 0X4B);
    // 0x80382FF0: addiu       $t7, $zero, 0x4B
    ctx->r15 = ADD32(0, 0X4B);
    // 0x80382FF4: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80382FF8: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x80382FFC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80383000: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x80383004: addiu       $t1, $zero, 0x82
    ctx->r9 = ADD32(0, 0X82);
    // 0x80383008: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8038300C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80383010: addiu       $t2, $zero, -0x3
    ctx->r10 = ADD32(0, -0X3);
    // 0x80383014: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80383018: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8038301C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80383020: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80383024: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80383028: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8038302C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80383030: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80383034: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80383038: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8038303C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80383040: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80383044: swc1        $f26, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f26.u32l;
    // 0x80383048: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x8038304C: jal         0x80129FB8
    // 0x80383050: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_9;
    // 0x80383050: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_9:
    // 0x80383054: addiu       $s0, $s0, 0x2AA
    ctx->r16 = ADD32(ctx->r16, 0X2AA);
    // 0x80383058: bnel        $s0, $s3, L_80382FA8
    if (ctx->r16 != ctx->r19) {
        // 0x8038305C: sll         $s1, $s0, 16
        ctx->r17 = S32(ctx->r16 << 16);
            goto L_80382FA8;
    }
    goto skip_0;
    // 0x8038305C: sll         $s1, $s0, 16
    ctx->r17 = S32(ctx->r16 << 16);
    skip_0:
    // 0x80383060: jal         0x80005700
    // 0x80383064: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_10;
    // 0x80383064: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
L_80383068:
    // 0x80383068: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x8038306C: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x80383070: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x80383074: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x80383078: ldc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X60);
    // 0x8038307C: ldc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X68);
    // 0x80383080: lw          $s0, 0x74($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X74);
    // 0x80383084: lw          $s1, 0x78($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X78);
    // 0x80383088: lw          $s2, 0x7C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X7C);
    // 0x8038308C: lw          $s3, 0x80($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X80);
    // 0x80383090: jr          $ra
    // 0x80383094: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80383094: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80383098(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80383098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383098: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8038309C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x803830A0: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x803830A4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x803830A8: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x803830AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803830B0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x803830B4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x803830B8: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x803830BC: jal         0x8012C6B4
    // 0x803830C0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x803830C0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_0:
    // 0x803830C4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x803830C8: jal         0x8012C6B4
    // 0x803830CC: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x803830CC: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x803830D0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x803830D4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x803830D8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x803830DC: addiu       $t8, $t7, -0x64
    ctx->r24 = ADD32(ctx->r15, -0X64);
    // 0x803830E0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x803830E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x803830E8: addiu       $t9, $v0, -0x64
    ctx->r25 = ADD32(ctx->r2, -0X64);
    // 0x803830EC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x803830F0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x803830F4: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x803830F8: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    // 0x803830FC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383100: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x80383104: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80383108: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8038310C: addiu       $t7, $zero, -0x4
    ctx->r15 = ADD32(0, -0X4);
    // 0x80383110: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80383114: addiu       $t0, $zero, 0x4B
    ctx->r8 = ADD32(0, 0X4B);
    // 0x80383118: addiu       $t1, $zero, 0x4B
    ctx->r9 = ADD32(0, 0X4B);
    // 0x8038311C: addiu       $t2, $zero, 0x4B
    ctx->r10 = ADD32(0, 0X4B);
    // 0x80383120: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80383124: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x80383128: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x8038312C: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x80383130: addiu       $t6, $zero, 0x82
    ctx->r14 = ADD32(0, 0X82);
    // 0x80383134: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80383138: div.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x8038313C: lwc1        $f6, -0x64B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X64B0);
    // 0x80383140: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383144: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80383148: lwc1        $f8, 0x9C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x8038314C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80383150: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80383154: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80383158: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x8038315C: lwc1        $f8, -0x64AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X64AC);
    // 0x80383160: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80383164: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80383168: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x8038316C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80383170: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80383174: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80383178: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8038317C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80383180: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80383184: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80383188: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8038318C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80383190: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80383194: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80383198: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8038319C: jal         0x80129FB8
    // 0x803831A0: nop

    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_2;
    // 0x803831A0: nop

    after_2:
    // 0x803831A4: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x803831A8: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x803831AC: bnel        $at, $zero, L_803831C0
    if (ctx->r1 != 0) {
        // 0x803831B0: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_803831C0;
    }
    goto skip_0;
    // 0x803831B0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x803831B4: jal         0x80005700
    // 0x803831B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x803831B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x803831BC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_803831C0:
    // 0x803831C0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x803831C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x803831C8: jr          $ra
    // 0x803831CC: nop

    return;
    // 0x803831CC: nop

;}
RECOMP_FUNC void M55_FUN_803831d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803831D0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x803831D4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x803831D8: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x803831DC: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x803831E0: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x803831E4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x803831E8: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x803831EC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x803831F0: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x803831F4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x803831F8: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x803831FC: sw          $a1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r5;
    // 0x80383200: jal         0x8012C6B4
    // 0x80383204: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80383204: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    after_0:
    // 0x80383208: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x8038320C: jal         0x8012C6B4
    // 0x80383210: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80383210: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    after_1:
    // 0x80383214: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80383218: jal         0x8012C6B4
    // 0x8038321C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x8038321C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_2:
    // 0x80383220: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80383224: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80383228: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8038322C: addiu       $t9, $t8, -0x12C
    ctx->r25 = ADD32(ctx->r24, -0X12C);
    // 0x80383230: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80383234: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80383238: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8038323C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80383240: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x80383244: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80383248: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8038324C: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x80383250: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80383254: addiu       $t1, $t0, -0x12C
    ctx->r9 = ADD32(ctx->r8, -0X12C);
    // 0x80383258: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8038325C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80383260: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80383264: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80383268: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8038326C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80383270: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383274: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80383278: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8038327C: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80383280: addiu       $t9, $zero, -0x4
    ctx->r25 = ADD32(0, -0X4);
    // 0x80383284: addiu       $t8, $zero, 0x82
    ctx->r24 = ADD32(0, 0X82);
    // 0x80383288: addiu       $t2, $zero, 0x4B
    ctx->r10 = ADD32(0, 0X4B);
    // 0x8038328C: addiu       $t3, $zero, 0x4B
    ctx->r11 = ADD32(0, 0X4B);
    // 0x80383290: addiu       $t4, $zero, 0x4B
    ctx->r12 = ADD32(0, 0X4B);
    // 0x80383294: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x80383298: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x8038329C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x803832A0: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x803832A4: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x803832A8: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x803832AC: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x803832B0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x803832B4: div.d       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x803832B8: lwc1        $f8, -0x64A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X64A8);
    // 0x803832BC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803832C0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x803832C4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x803832C8: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x803832CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x803832D0: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x803832D4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x803832D8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x803832DC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x803832E0: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x803832E4: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x803832E8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x803832EC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x803832F0: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x803832F4: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x803832F8: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x803832FC: ldc1        $f4, -0x64A0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X64A0);
    // 0x80383300: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383304: cvt.d.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.d = CVT_D_W(ctx->f18.u32l);
    // 0x80383308: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8038330C: div.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x80383310: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80383314: ldc1        $f10, -0x6498($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6498);
    // 0x80383318: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x8038331C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x80383320: jal         0x80129FB8
    // 0x80383324: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_3;
    // 0x80383324: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80383328: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8038332C: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x80383330: beql        $at, $zero, L_8038346C
    if (ctx->r1 == 0) {
        // 0x80383334: slti        $at, $v1, 0xF
        ctx->r1 = SIGNED(ctx->r3) < 0XF ? 1 : 0;
            goto L_8038346C;
    }
    goto skip_0;
    // 0x80383334: slti        $at, $v1, 0xF
    ctx->r1 = SIGNED(ctx->r3) < 0XF ? 1 : 0;
    skip_0:
    // 0x80383338: bgez        $v1, L_8038334C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8038333C: andi        $t1, $v1, 0x1
        ctx->r9 = ctx->r3 & 0X1;
            goto L_8038334C;
    }
    // 0x8038333C: andi        $t1, $v1, 0x1
    ctx->r9 = ctx->r3 & 0X1;
    // 0x80383340: beq         $t1, $zero, L_8038334C
    if (ctx->r9 == 0) {
        // 0x80383344: nop
    
            goto L_8038334C;
    }
    // 0x80383344: nop

    // 0x80383348: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
L_8038334C:
    // 0x8038334C: bnel        $t1, $zero, L_8038346C
    if (ctx->r9 != 0) {
        // 0x80383350: slti        $at, $v1, 0xF
        ctx->r1 = SIGNED(ctx->r3) < 0XF ? 1 : 0;
            goto L_8038346C;
    }
    goto skip_1;
    // 0x80383350: slti        $at, $v1, 0xF
    ctx->r1 = SIGNED(ctx->r3) < 0XF ? 1 : 0;
    skip_1:
    // 0x80383354: jal         0x8012C6B4
    // 0x80383358: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80383358: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    after_4:
    // 0x8038335C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80383360: jal         0x8012C6B4
    // 0x80383364: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80383364: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    after_5:
    // 0x80383368: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8038336C: jal         0x8012C6B4
    // 0x80383370: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x80383370: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    after_6:
    // 0x80383374: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80383378: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8038337C: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80383380: addiu       $t4, $t3, -0x190
    ctx->r12 = ADD32(ctx->r11, -0X190);
    // 0x80383384: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80383388: lw          $t2, -0x4330($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4330);
    // 0x8038338C: addiu       $t6, $t5, -0x258
    ctx->r14 = ADD32(ctx->r13, -0X258);
    // 0x80383390: cvt.d.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.d = CVT_D_W(ctx->f16.u32l);
    // 0x80383394: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80383398: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x8038339C: addiu       $t7, $v0, -0x190
    ctx->r15 = ADD32(ctx->r2, -0X190);
    // 0x803833A0: lui         $at, 0x4028
    ctx->r1 = S32(0X4028 << 16);
    // 0x803833A4: div.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x803833A8: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x803833AC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x803833B0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803833B4: cvt.d.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.d = CVT_D_W(ctx->f16.u32l);
    // 0x803833B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x803833BC: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x803833C0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x803833C4: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x803833C8: addiu       $t3, $zero, -0x6
    ctx->r11 = ADD32(0, -0X6);
    // 0x803833CC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x803833D0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x803833D4: addiu       $t9, $zero, 0x7A
    ctx->r25 = ADD32(0, 0X7A);
    // 0x803833D8: addiu       $t0, $zero, 0xB2
    ctx->r8 = ADD32(0, 0XB2);
    // 0x803833DC: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x803833E0: div.d       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x803833E4: add.d       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f6.d + ctx->f8.d;
    // 0x803833E8: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x803833EC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x803833F0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x803833F4: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x803833F8: add.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f10.d + ctx->f8.d;
    // 0x803833FC: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80383400: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x80383404: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80383408: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8038340C: div.d       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x80383410: lwc1        $f10, -0x6490($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6490);
    // 0x80383414: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80383418: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8038341C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80383420: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x80383424: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80383428: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8038342C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80383430: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80383434: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80383438: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8038343C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80383440: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80383444: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80383448: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8038344C: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80383450: add.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f8.d + ctx->f16.d;
    // 0x80383454: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80383458: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8038345C: jal         0x80129FB8
    // 0x80383460: nop

    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_7;
    // 0x80383460: nop

    after_7:
    // 0x80383464: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80383468: slti        $at, $v1, 0xF
    ctx->r1 = SIGNED(ctx->r3) < 0XF ? 1 : 0;
L_8038346C:
    // 0x8038346C: bnel        $at, $zero, L_80383480
    if (ctx->r1 != 0) {
        // 0x80383470: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_80383480;
    }
    goto skip_2;
    // 0x80383470: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x80383474: jal         0x80005700
    // 0x80383478: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_8;
    // 0x80383478: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_8:
    // 0x8038347C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80383480:
    // 0x80383480: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x80383484: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x80383488: jr          $ra
    // 0x8038348C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8038348C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80383490(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80383490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80383494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383498: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8038349C: lwc1        $f4, 0x94($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X94);
    // 0x803834A0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803834A4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x803834A8: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x803834AC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x803834B0: lwc1        $f6, 0x98($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X98);
    // 0x803834B4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x803834B8: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x803834BC: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x803834C0: lwc1        $f8, 0x9C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x803834C4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x803834C8: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x803834CC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x803834D0: ldc1        $f18, -0x6488($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6488);
    // 0x803834D4: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x803834D8: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x803834DC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x803834E0: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x803834E4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x803834E8: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x803834EC: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x803834F0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x803834F4: lbu         $t4, 0x4B($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4B);
    // 0x803834F8: addiu       $t5, $t4, -0x6
    ctx->r13 = ADD32(ctx->r12, -0X6);
    // 0x803834FC: sb          $t5, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r13;
    // 0x80383500: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80383504: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80383508: lbu         $t8, 0x4B($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X4B);
    // 0x8038350C: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x80383510: beql        $at, $zero, L_80383524
    if (ctx->r1 == 0) {
        // 0x80383514: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80383524;
    }
    goto skip_0;
    // 0x80383514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80383518: jal         0x80005700
    // 0x8038351C: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x8038351C: nop

    after_0:
    // 0x80383520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80383524:
    // 0x80383524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80383528: jr          $ra
    // 0x8038352C: nop

    return;
    // 0x8038352C: nop

;}
RECOMP_FUNC void M55_FUN_80383530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383530: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80383534: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80383538: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8038353C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80383540: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80383544: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80383548: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8038354C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80383550: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80383554: jal         0x8012C6B4
    // 0x80383558: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80383558: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_0:
    // 0x8038355C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80383560: jal         0x8012C6B4
    // 0x80383564: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80383564: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_1:
    // 0x80383568: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x8038356C: jal         0x8012C6B4
    // 0x80383570: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80383570: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_2:
    // 0x80383574: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80383578: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8038357C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80383580: addiu       $t8, $t7, -0x2BC
    ctx->r24 = ADD32(ctx->r15, -0X2BC);
    // 0x80383584: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80383588: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8038358C: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80383590: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80383594: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80383598: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8038359C: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
    // 0x803835A0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x803835A4: div.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f2.d);
    // 0x803835A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x803835AC: addiu       $t0, $t9, -0x2BC
    ctx->r8 = ADD32(ctx->r25, -0X2BC);
    // 0x803835B0: addiu       $t1, $v0, -0x2BC
    ctx->r9 = ADD32(ctx->r2, -0X2BC);
    // 0x803835B4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x803835B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x803835BC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803835C0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x803835C4: addiu       $t7, $zero, -0x4
    ctx->r15 = ADD32(0, -0X4);
    // 0x803835C8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x803835CC: addiu       $t3, $zero, 0x84
    ctx->r11 = ADD32(0, 0X84);
    // 0x803835D0: addiu       $t4, $zero, 0x94
    ctx->r12 = ADD32(0, 0X94);
    // 0x803835D4: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x803835D8: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x803835DC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x803835E0: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x803835E4: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x803835E8: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x803835EC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x803835F0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x803835F4: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x803835F8: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x803835FC: div.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f2.d);
    // 0x80383600: div.d       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f2.d);
    // 0x80383604: lwc1        $f16, -0x6480($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6480);
    // 0x80383608: add.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d + ctx->f8.d;
    // 0x8038360C: lwc1        $f4, 0x9C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80383610: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80383614: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80383618: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8038361C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80383620: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80383624: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80383628: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8038362C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80383630: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80383634: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80383638: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8038363C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80383640: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80383644: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80383648: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8038364C: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80383650: add.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f18.d + ctx->f8.d;
    // 0x80383654: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80383658: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8038365C: jal         0x80129FB8
    // 0x80383660: nop

    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_3;
    // 0x80383660: nop

    after_3:
    // 0x80383664: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80383668: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8038366C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80383670: bne         $t9, $zero, L_8038377C
    if (ctx->r25 != 0) {
        // 0x80383674: addiu       $t0, $zero, 0xFF
        ctx->r8 = ADD32(0, 0XFF);
            goto L_8038377C;
    }
    // 0x80383674: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80383678: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8038367C: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80383680: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x80383684: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80383688: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038368C: lwc1        $f8, -0x647C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X647C);
    // 0x80383690: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80383694: addiu       $t1, $zero, 0x84
    ctx->r9 = ADD32(0, 0X84);
    // 0x80383698: addiu       $t2, $zero, 0x94
    ctx->r10 = ADD32(0, 0X94);
    // 0x8038369C: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x803836A0: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x803836A4: addiu       $t5, $zero, -0x4
    ctx->r13 = ADD32(0, -0X4);
    // 0x803836A8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x803836AC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x803836B0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x803836B4: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x803836B8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x803836BC: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x803836C0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x803836C4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x803836C8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x803836CC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x803836D0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x803836D4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x803836D8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x803836DC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x803836E0: add.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x803836E4: jal         0x80129FB8
    // 0x803836E8: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_4;
    // 0x803836E8: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x803836EC: lwc1        $f6, 0x98($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X98);
    // 0x803836F0: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x803836F4: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x803836F8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x803836FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80383700: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383704: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80383708: lwc1        $f16, -0x6478($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6478);
    // 0x8038370C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80383710: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80383714: addiu       $t7, $zero, 0x4B
    ctx->r15 = ADD32(0, 0X4B);
    // 0x80383718: addiu       $t8, $zero, 0x4B
    ctx->r24 = ADD32(0, 0X4B);
    // 0x8038371C: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x80383720: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x80383724: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80383728: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x8038372C: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x80383730: addiu       $t4, $zero, -0x2
    ctx->r12 = ADD32(0, -0X2);
    // 0x80383734: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80383738: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8038373C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80383740: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80383744: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80383748: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8038374C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80383750: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80383754: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80383758: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8038375C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80383760: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80383764: add.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80383768: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8038376C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80383770: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80383774: jal         0x80129FB8
    // 0x80383778: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_5;
    // 0x80383778: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_5:
L_8038377C:
    // 0x8038377C: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80383780: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80383784: bnel        $at, $zero, L_80383798
    if (ctx->r1 != 0) {
        // 0x80383788: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80383798;
    }
    goto skip_0;
    // 0x80383788: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x8038378C: jal         0x80005700
    // 0x80383790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_6;
    // 0x80383790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80383794: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80383798:
    // 0x80383798: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8038379C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x803837A0: jr          $ra
    // 0x803837A4: nop

    return;
    // 0x803837A4: nop

;}
RECOMP_FUNC void M55_FUN_803837a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803837A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803837AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803837B0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x803837B4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x803837B8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x803837BC: lbu         $t6, 0x204($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X204);
    // 0x803837C0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x803837C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x803837C8: sb          $t6, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r14;
    // 0x803837CC: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x803837D0: lbu         $t9, 0x205($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X205);
    // 0x803837D4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x803837D8: sb          $t9, 0x49($t1)
    MEM_B(0X49, ctx->r9) = ctx->r25;
    // 0x803837DC: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x803837E0: lbu         $t2, 0x206($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X206);
    // 0x803837E4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x803837E8: sb          $t2, 0x4A($t4)
    MEM_B(0X4A, ctx->r12) = ctx->r10;
    // 0x803837EC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x803837F0: lbu         $t5, 0x208($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X208);
    // 0x803837F4: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x803837F8: sb          $t5, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r13;
    // 0x803837FC: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80383800: lbu         $t8, 0x209($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X209);
    // 0x80383804: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x80383808: sb          $t8, 0x4D($t9)
    MEM_B(0X4D, ctx->r25) = ctx->r24;
    // 0x8038380C: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80383810: lbu         $t1, 0x20A($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X20A);
    // 0x80383814: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x80383818: sb          $t1, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r9;
    // 0x8038381C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80383820: lwc1        $f4, 0x94($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X94);
    // 0x80383824: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80383828: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x8038382C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80383830: lwc1        $f6, 0x98($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X98);
    // 0x80383834: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80383838: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x8038383C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80383840: lwc1        $f8, 0x9C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x80383844: lw          $t8, 0x30($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X30);
    // 0x80383848: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x8038384C: lhu         $v1, 0x3C($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X3C);
    // 0x80383850: beql        $v1, $zero, L_8038386C
    if (ctx->r3 == 0) {
        // 0x80383854: lw          $t9, 0x0($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X0);
            goto L_8038386C;
    }
    goto skip_0;
    // 0x80383854: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80383858: beql        $v1, $at, L_803838AC
    if (ctx->r3 == ctx->r1) {
        // 0x8038385C: lw          $t6, 0x0($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X0);
            goto L_803838AC;
    }
    goto skip_1;
    // 0x8038385C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    skip_1:
    // 0x80383860: b           L_803838E0
    // 0x80383864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_803838E0;
    // 0x80383864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80383868: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
L_8038386C:
    // 0x8038386C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80383870: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80383874: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80383878: lbu         $t3, 0x4B($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4B);
    // 0x8038387C: addiu       $t1, $t3, 0x20
    ctx->r9 = ADD32(ctx->r11, 0X20);
    // 0x80383880: sb          $t1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r9;
    // 0x80383884: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80383888: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x8038388C: lbu         $t4, 0x4B($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4B);
    // 0x80383890: slti        $at, $t4, 0xE0
    ctx->r1 = SIGNED(ctx->r12) < 0XE0 ? 1 : 0;
    // 0x80383894: bnel        $at, $zero, L_803838E0
    if (ctx->r1 != 0) {
        // 0x80383898: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803838E0;
    }
    goto skip_2;
    // 0x80383898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8038389C: sb          $t7, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r15;
    // 0x803838A0: b           L_803838DC
    // 0x803838A4: sh          $t5, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r13;
        goto L_803838DC;
    // 0x803838A4: sh          $t5, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r13;
    // 0x803838A8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
L_803838AC:
    // 0x803838AC: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x803838B0: lbu         $t0, 0x4B($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X4B);
    // 0x803838B4: addiu       $t8, $t0, -0xA
    ctx->r24 = ADD32(ctx->r8, -0XA);
    // 0x803838B8: sb          $t8, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r24;
    // 0x803838BC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x803838C0: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x803838C4: lbu         $t1, 0x4B($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X4B);
    // 0x803838C8: slti        $at, $t1, 0xA
    ctx->r1 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x803838CC: beql        $at, $zero, L_803838E0
    if (ctx->r1 == 0) {
        // 0x803838D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803838E0;
    }
    goto skip_3;
    // 0x803838D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x803838D4: jal         0x80005700
    // 0x803838D8: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x803838D8: nop

    after_0:
L_803838DC:
    // 0x803838DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803838E0:
    // 0x803838E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803838E4: jr          $ra
    // 0x803838E8: nop

    return;
    // 0x803838E8: nop

;}
RECOMP_FUNC void M55_FUN_803838ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803838EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803838F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803838F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x803838F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x803838FC: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80383900: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80383904: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80383908: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8038390C: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80383910: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x80383914: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80383918: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8038391C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80383920: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80383924: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80383928: bgez        $a0, L_8038393C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8038392C: andi        $a0, $a0, 0x1FFF
        ctx->r4 = ctx->r4 & 0X1FFF;
            goto L_8038393C;
    }
    // 0x8038392C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80383930: beq         $a0, $zero, L_8038393C
    if (ctx->r4 == 0) {
        // 0x80383934: nop
    
            goto L_8038393C;
    }
    // 0x80383934: nop

    // 0x80383938: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
L_8038393C:
    // 0x8038393C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80383940: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80383944: jal         0x8001EB64
    // 0x80383948: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x80383948: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8038394C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80383950: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80383954: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80383958: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8038395C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80383960: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80383964: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80383968: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8038396C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80383970: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80383974: nop

    // 0x80383978: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8038397C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80383980: nop

    // 0x80383984: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80383988: beql        $t8, $zero, L_803839D8
    if (ctx->r24 == 0) {
        // 0x8038398C: mfc1        $t8, $f16
        ctx->r24 = (int32_t)ctx->f16.u32l;
            goto L_803839D8;
    }
    goto skip_0;
    // 0x8038398C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x80383990: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80383994: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80383998: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8038399C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x803839A0: nop

    // 0x803839A4: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x803839A8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x803839AC: nop

    // 0x803839B0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x803839B4: bne         $t8, $zero, L_803839CC
    if (ctx->r24 != 0) {
        // 0x803839B8: nop
    
            goto L_803839CC;
    }
    // 0x803839B8: nop

    // 0x803839BC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x803839C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x803839C4: b           L_803839E4
    // 0x803839C8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_803839E4;
    // 0x803839C8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_803839CC:
    // 0x803839CC: b           L_803839E4
    // 0x803839D0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_803839E4;
    // 0x803839D0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x803839D4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
L_803839D8:
    // 0x803839D8: nop

    // 0x803839DC: bltz        $t8, L_803839CC
    if (SIGNED(ctx->r24) < 0) {
        // 0x803839E0: nop
    
            goto L_803839CC;
    }
    // 0x803839E0: nop

L_803839E4:
    // 0x803839E4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x803839E8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x803839EC: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x803839F0: sb          $t8, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = ctx->r24;
    // 0x803839F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x803839F8: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x803839FC: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80383A00: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x80383A04: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80383A08: bgez        $a0, L_80383A1C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80383A0C: andi        $a0, $a0, 0x1FFF
        ctx->r4 = ctx->r4 & 0X1FFF;
            goto L_80383A1C;
    }
    // 0x80383A0C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80383A10: beq         $a0, $zero, L_80383A1C
    if (ctx->r4 == 0) {
        // 0x80383A14: nop
    
            goto L_80383A1C;
    }
    // 0x80383A14: nop

    // 0x80383A18: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
L_80383A1C:
    // 0x80383A1C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80383A20: jal         0x8001EB64
    // 0x80383A24: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x80383A24: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x80383A28: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80383A2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80383A30: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80383A34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80383A38: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80383A3C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80383A40: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80383A44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80383A48: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80383A4C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80383A50: nop

    // 0x80383A54: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80383A58: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80383A5C: nop

    // 0x80383A60: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80383A64: beql        $t2, $zero, L_80383AB4
    if (ctx->r10 == 0) {
        // 0x80383A68: mfc1        $t2, $f10
        ctx->r10 = (int32_t)ctx->f10.u32l;
            goto L_80383AB4;
    }
    goto skip_1;
    // 0x80383A68: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x80383A6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80383A70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80383A74: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80383A78: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80383A7C: nop

    // 0x80383A80: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80383A84: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80383A88: nop

    // 0x80383A8C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80383A90: bne         $t2, $zero, L_80383AA8
    if (ctx->r10 != 0) {
        // 0x80383A94: nop
    
            goto L_80383AA8;
    }
    // 0x80383A94: nop

    // 0x80383A98: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80383A9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80383AA0: b           L_80383AC0
    // 0x80383AA4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80383AC0;
    // 0x80383AA4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80383AA8:
    // 0x80383AA8: b           L_80383AC0
    // 0x80383AAC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80383AC0;
    // 0x80383AAC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80383AB0: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
L_80383AB4:
    // 0x80383AB4: nop

    // 0x80383AB8: bltz        $t2, L_80383AA8
    if (SIGNED(ctx->r10) < 0) {
        // 0x80383ABC: nop
    
            goto L_80383AA8;
    }
    // 0x80383ABC: nop

L_80383AC0:
    // 0x80383AC0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80383AC4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80383AC8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80383ACC: sb          $t2, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r10;
    // 0x80383AD0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80383AD4: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80383AD8: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80383ADC: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x80383AE0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80383AE4: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x80383AE8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80383AEC: bgez        $a0, L_80383B00
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80383AF0: andi        $a0, $a0, 0x1FFF
        ctx->r4 = ctx->r4 & 0X1FFF;
            goto L_80383B00;
    }
    // 0x80383AF0: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x80383AF4: beq         $a0, $zero, L_80383B00
    if (ctx->r4 == 0) {
        // 0x80383AF8: nop
    
            goto L_80383B00;
    }
    // 0x80383AF8: nop

    // 0x80383AFC: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
L_80383B00:
    // 0x80383B00: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80383B04: jal         0x8001EB64
    // 0x80383B08: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x80383B08: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x80383B0C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80383B10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80383B14: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80383B18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80383B1C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80383B20: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80383B24: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80383B28: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80383B2C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80383B30: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80383B34: nop

    // 0x80383B38: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80383B3C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80383B40: nop

    // 0x80383B44: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80383B48: beql        $t6, $zero, L_80383B98
    if (ctx->r14 == 0) {
        // 0x80383B4C: mfc1        $t6, $f8
        ctx->r14 = (int32_t)ctx->f8.u32l;
            goto L_80383B98;
    }
    goto skip_2;
    // 0x80383B4C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x80383B50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80383B54: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80383B58: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80383B5C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80383B60: nop

    // 0x80383B64: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80383B68: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80383B6C: nop

    // 0x80383B70: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80383B74: bne         $t6, $zero, L_80383B8C
    if (ctx->r14 != 0) {
        // 0x80383B78: nop
    
            goto L_80383B8C;
    }
    // 0x80383B78: nop

    // 0x80383B7C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80383B80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80383B84: b           L_80383BA4
    // 0x80383B88: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80383BA4;
    // 0x80383B88: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80383B8C:
    // 0x80383B8C: b           L_80383BA4
    // 0x80383B90: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80383BA4;
    // 0x80383B90: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80383B94: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
L_80383B98:
    // 0x80383B98: nop

    // 0x80383B9C: bltz        $t6, L_80383B8C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80383BA0: nop
    
            goto L_80383B8C;
    }
    // 0x80383BA0: nop

L_80383BA4:
    // 0x80383BA4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80383BA8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80383BAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80383BB0: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80383BB4: sb          $t6, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r14;
    // 0x80383BB8: lbu         $v0, 0xA8($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XA8);
    // 0x80383BBC: beql        $v0, $zero, L_80383BD8
    if (ctx->r2 == 0) {
        // 0x80383BC0: lw          $t8, 0x0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X0);
            goto L_80383BD8;
    }
    goto skip_3;
    // 0x80383BC0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x80383BC4: beq         $v0, $at, L_80383C14
    if (ctx->r2 == ctx->r1) {
        // 0x80383BC8: nop
    
            goto L_80383C14;
    }
    // 0x80383BC8: nop

    // 0x80383BCC: b           L_80383C5C
    // 0x80383BD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80383C5C;
    // 0x80383BD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80383BD4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_80383BD8:
    // 0x80383BD8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80383BDC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80383BE0: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80383BE4: lbu         $t0, 0x4B($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X4B);
    // 0x80383BE8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80383BEC: sb          $t1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r9;
    // 0x80383BF0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80383BF4: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80383BF8: lbu         $t2, 0x4B($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4B);
    // 0x80383BFC: slti        $at, $t2, 0xF8
    ctx->r1 = SIGNED(ctx->r10) < 0XF8 ? 1 : 0;
    // 0x80383C00: bnel        $at, $zero, L_80383C5C
    if (ctx->r1 != 0) {
        // 0x80383C04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80383C5C;
    }
    goto skip_4;
    // 0x80383C04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80383C08: sb          $t4, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r12;
    // 0x80383C0C: b           L_80383C58
    // 0x80383C10: sb          $t5, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = ctx->r13;
        goto L_80383C58;
    // 0x80383C10: sb          $t5, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = ctx->r13;
L_80383C14:
    // 0x80383C14: jal         0x80133A24
    // 0x80383C18: addiu       $a0, $zero, 0x13B
    ctx->r4 = ADD32(0, 0X13B);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_3;
    // 0x80383C18: addiu       $a0, $zero, 0x13B
    ctx->r4 = ADD32(0, 0X13B);
    after_3:
    // 0x80383C1C: beql        $v0, $zero, L_80383C5C
    if (ctx->r2 == 0) {
        // 0x80383C20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80383C5C;
    }
    goto skip_5;
    // 0x80383C20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80383C24: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80383C28: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80383C2C: lbu         $t6, 0x4B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4B);
    // 0x80383C30: addiu       $t9, $t6, -0x2
    ctx->r25 = ADD32(ctx->r14, -0X2);
    // 0x80383C34: sb          $t9, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r25;
    // 0x80383C38: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80383C3C: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x80383C40: lbu         $t1, 0x4B($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4B);
    // 0x80383C44: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x80383C48: beql        $at, $zero, L_80383C5C
    if (ctx->r1 == 0) {
        // 0x80383C4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80383C5C;
    }
    goto skip_6;
    // 0x80383C4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80383C50: jal         0x80005700
    // 0x80383C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x80383C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_80383C58:
    // 0x80383C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80383C5C:
    // 0x80383C5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80383C60: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80383C64: jr          $ra
    // 0x80383C68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80383C68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80383c6c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80383c6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383C6C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80383C70: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x80383C74: sw          $s6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r22;
    // 0x80383C78: sw          $s5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r21;
    // 0x80383C7C: sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // 0x80383C80: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x80383C84: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x80383C88: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x80383C8C: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x80383C90: sdc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X78, ctx->r29);
    // 0x80383C94: sdc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X70, ctx->r29);
    // 0x80383C98: sdc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X68, ctx->r29);
    // 0x80383C9C: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x80383CA0: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x80383CA4: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80383CA8: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x80383CAC: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80383CB0: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80383CB4: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x80383CB8: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x80383CBC: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80383CC0: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80383CC4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383CC8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80383CCC: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80383CD0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80383CD4: ldc1        $f20, -0x6470($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X6470);
    // 0x80383CD8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80383CDC:
    // 0x80383CDC: jal         0x8012C6B4
    // 0x80383CE0: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80383CE0: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_0:
    // 0x80383CE4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80383CE8: jal         0x8012C6B4
    // 0x80383CEC: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80383CEC: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_1:
    // 0x80383CF0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80383CF4: jal         0x8012C6B4
    // 0x80383CF8: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80383CF8: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_2:
    // 0x80383CFC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80383D00: jal         0x8012C6B4
    // 0x80383D04: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x80383D04: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_3:
    // 0x80383D08: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80383D0C: jal         0x8012C6B4
    // 0x80383D10: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80383D10: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_4:
    // 0x80383D14: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80383D18: jal         0x8012C6B4
    // 0x80383D1C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80383D1C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_5:
    // 0x80383D20: addiu       $t7, $s5, -0x320
    ctx->r15 = ADD32(ctx->r21, -0X320);
    // 0x80383D24: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80383D28: addiu       $t8, $s6, -0x320
    ctx->r24 = ADD32(ctx->r22, -0X320);
    // 0x80383D2C: lwc1        $f10, 0x94($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80383D30: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80383D34: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80383D38: addiu       $t9, $s3, -0x320
    ctx->r25 = ADD32(ctx->r19, -0X320);
    // 0x80383D3C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383D40: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80383D44: div.d       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f28.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f28.d);
    // 0x80383D48: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80383D4C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80383D50: addiu       $t1, $s4, 0x8E
    ctx->r9 = ADD32(ctx->r20, 0X8E);
    // 0x80383D54: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80383D58: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80383D5C: addiu       $t2, $zero, 0x94
    ctx->r10 = ADD32(0, 0X94);
    // 0x80383D60: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x80383D64: addiu       $t4, $zero, -0x4
    ctx->r12 = ADD32(0, -0X4);
    // 0x80383D68: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80383D6C: div.d       $f10, $f6, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f28.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f28.d);
    // 0x80383D70: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80383D74: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80383D78: lwc1        $f8, 0x98($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80383D7C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80383D80: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x80383D84: div.d       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f28.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f28.d);
    // 0x80383D88: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80383D8C: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80383D90: lwc1        $f10, 0x9C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x80383D94: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80383D98: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80383D9C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80383DA0: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80383DA4: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80383DA8: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80383DAC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80383DB0: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x80383DB4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80383DB8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80383DBC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80383DC0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80383DC4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80383DC8: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80383DCC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80383DD0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80383DD4: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80383DD8: ldc1        $f8, -0x6468($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6468);
    // 0x80383DDC: div.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x80383DE0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80383DE4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80383DE8: add.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = ctx->f16.d + ctx->f20.d;
    // 0x80383DEC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80383DF0: jal         0x80129FB8
    // 0x80383DF4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_6;
    // 0x80383DF4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80383DF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80383DFC: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80383E00: bne         $at, $zero, L_80383CDC
    if (ctx->r1 != 0) {
        // 0x80383E04: nop
    
            goto L_80383CDC;
    }
    // 0x80383E04: nop

    // 0x80383E08: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x80383E0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80383E10: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80383E14: bne         $t6, $at, L_80383F2C
    if (ctx->r14 != ctx->r1) {
        // 0x80383E18: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_80383F2C;
    }
    // 0x80383E18: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383E1C: lwc1        $f30, -0x6460($at)
    ctx->f30.u32l = MEM_W(ctx->r1, -0X6460);
    // 0x80383E20: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80383E24: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80383E28: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80383E2C: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
L_80383E30:
    // 0x80383E30: jal         0x8012C6B4
    // 0x80383E34: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x80383E34: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_7:
    // 0x80383E38: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80383E3C: nop

    // 0x80383E40: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80383E44: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80383E48: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80383E4C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80383E50: nop

    // 0x80383E54: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80383E58: jal         0x8001EAD0
    // 0x80383E5C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x80383E5C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_8:
    // 0x80383E60: trunc.w.s   $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    ctx->f8.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x80383E64: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80383E68: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80383E6C: nop

    // 0x80383E70: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80383E74: jal         0x8001EB64
    // 0x80383E78: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_9;
    // 0x80383E78: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_9:
    // 0x80383E7C: cvt.d.s     $f16, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f16.d = CVT_D_S(ctx->f26.fl);
    // 0x80383E80: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80383E84: mul.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f20.d);
    // 0x80383E88: lwc1        $f4, 0x94($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80383E8C: lwc1        $f14, 0x98($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80383E90: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383E94: mul.d       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x80383E98: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80383E9C: lwc1        $f4, 0x9C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x80383EA0: lwc1        $f8, -0x645C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X645C);
    // 0x80383EA4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80383EA8: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x80383EAC: add.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f18.d + ctx->f6.d;
    // 0x80383EB0: addiu       $t0, $zero, 0x4B
    ctx->r8 = ADD32(0, 0X4B);
    // 0x80383EB4: addiu       $t1, $zero, 0x4B
    ctx->r9 = ADD32(0, 0X4B);
    // 0x80383EB8: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80383EBC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x80383EC0: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x80383EC4: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x80383EC8: add.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f16.d + ctx->f18.d;
    // 0x80383ECC: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x80383ED0: addiu       $t5, $zero, 0xFA
    ctx->r13 = ADD32(0, 0XFA);
    // 0x80383ED4: addiu       $t6, $zero, -0x2
    ctx->r14 = ADD32(0, -0X2);
    // 0x80383ED8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80383EDC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80383EE0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80383EE4: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80383EE8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80383EEC: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80383EF0: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80383EF4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80383EF8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80383EFC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80383F00: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80383F04: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80383F08: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80383F0C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80383F10: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80383F14: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x80383F18: jal         0x80129FB8
    // 0x80383F1C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_10;
    // 0x80383F1C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x80383F20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80383F24: bne         $s0, $s1, L_80383E30
    if (ctx->r16 != ctx->r17) {
        // 0x80383F28: nop
    
            goto L_80383E30;
    }
    // 0x80383F28: nop

L_80383F2C:
    // 0x80383F2C: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x80383F30: bgez        $t8, L_80383F44
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80383F34: andi        $t9, $t8, 0x1
        ctx->r25 = ctx->r24 & 0X1;
            goto L_80383F44;
    }
    // 0x80383F34: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80383F38: beq         $t9, $zero, L_80383F44
    if (ctx->r25 == 0) {
        // 0x80383F3C: nop
    
            goto L_80383F44;
    }
    // 0x80383F3C: nop

    // 0x80383F40: addiu       $t9, $t9, -0x2
    ctx->r25 = ADD32(ctx->r25, -0X2);
L_80383F44:
    // 0x80383F44: bnel        $t9, $zero, L_8038407C
    if (ctx->r25 != 0) {
        // 0x80383F48: lw          $t9, 0xA4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA4);
            goto L_8038407C;
    }
    goto skip_0;
    // 0x80383F48: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    skip_0:
    // 0x80383F4C: jal         0x8012C6B4
    // 0x80383F50: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x80383F50: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    after_11:
    // 0x80383F54: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80383F58: jal         0x8012C6B4
    // 0x80383F5C: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x80383F5C: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    after_12:
    // 0x80383F60: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80383F64: jal         0x8012C6B4
    // 0x80383F68: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_13;
    // 0x80383F68: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    after_13:
    // 0x80383F6C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80383F70: jal         0x8012C6B4
    // 0x80383F74: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_14;
    // 0x80383F74: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_14:
    // 0x80383F78: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80383F7C: jal         0x8012C6B4
    // 0x80383F80: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_15;
    // 0x80383F80: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_15:
    // 0x80383F84: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80383F88: jal         0x8012C6B4
    // 0x80383F8C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_16;
    // 0x80383F8C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_16:
    // 0x80383F90: addiu       $t0, $s5, -0x258
    ctx->r8 = ADD32(ctx->r21, -0X258);
    // 0x80383F94: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80383F98: addiu       $t1, $s6, -0x258
    ctx->r9 = ADD32(ctx->r22, -0X258);
    // 0x80383F9C: lwc1        $f6, 0x94($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80383FA0: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x80383FA4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80383FA8: addiu       $t2, $s3, -0x258
    ctx->r10 = ADD32(ctx->r19, -0X258);
    // 0x80383FAC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383FB0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80383FB4: div.d       $f18, $f16, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f28.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f28.d);
    // 0x80383FB8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80383FBC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80383FC0: addiu       $t4, $s4, 0x8E
    ctx->r12 = ADD32(ctx->r20, 0X8E);
    // 0x80383FC4: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x80383FC8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80383FCC: addiu       $t5, $zero, 0x94
    ctx->r13 = ADD32(0, 0X94);
    // 0x80383FD0: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x80383FD4: addiu       $t7, $zero, -0x4
    ctx->r15 = ADD32(0, -0X4);
    // 0x80383FD8: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80383FDC: div.d       $f6, $f16, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f28.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f28.d);
    // 0x80383FE0: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x80383FE4: add.d       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f18.d + ctx->f10.d;
    // 0x80383FE8: lwc1        $f18, 0x98($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80383FEC: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80383FF0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80383FF4: div.d       $f18, $f16, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f28.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f28.d);
    // 0x80383FF8: lwc1        $f16, -0x6458($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6458);
    // 0x80383FFC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384000: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80384004: lwc1        $f6, 0x9C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x80384008: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8038400C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80384010: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80384014: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80384018: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x8038401C: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80384020: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80384024: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80384028: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8038402C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80384030: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80384034: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80384038: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8038403C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80384040: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80384044: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80384048: add.d       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f18.d + ctx->f10.d;
    // 0x8038404C: ldc1        $f10, -0x6450($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6450);
    // 0x80384050: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384054: cvt.d.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.d = CVT_D_W(ctx->f6.u32l);
    // 0x80384058: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8038405C: div.d       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f10.d);
    // 0x80384060: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80384064: ldc1        $f4, -0x6448($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X6448);
    // 0x80384068: add.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d + ctx->f4.d;
    // 0x8038406C: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x80384070: jal         0x80129FB8
    // 0x80384074: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_17;
    // 0x80384074: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_17:
    // 0x80384078: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_8038407C:
    // 0x8038407C: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x80384080: bnel        $at, $zero, L_80384094
    if (ctx->r1 != 0) {
        // 0x80384084: lw          $ra, 0x9C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X9C);
            goto L_80384094;
    }
    goto skip_1;
    // 0x80384084: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    skip_1:
    // 0x80384088: jal         0x80005700
    // 0x8038408C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_18;
    // 0x8038408C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_18:
    // 0x80384090: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
L_80384094:
    // 0x80384094: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80384098: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x8038409C: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x803840A0: ldc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X68);
    // 0x803840A4: ldc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X70);
    // 0x803840A8: ldc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X78);
    // 0x803840AC: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x803840B0: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x803840B4: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x803840B8: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x803840BC: lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X90);
    // 0x803840C0: lw          $s5, 0x94($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X94);
    // 0x803840C4: lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X98);
    // 0x803840C8: jr          $ra
    // 0x803840CC: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x803840CC: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803840d0(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803840d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803840D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803840D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803840D8: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x803840DC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803840E0: ldc1        $f8, -0x6440($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6440);
    // 0x803840E4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x803840E8: lwc1        $f18, 0x94($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X94);
    // 0x803840EC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x803840F0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803840F4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x803840F8: swc1        $f16, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f16.u32l;
    // 0x803840FC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80384100: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80384104: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x80384108: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8038410C: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x80384110: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80384114: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x80384118: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x8038411C: lwc1        $f6, 0x9C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x80384120: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80384124: swc1        $f6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f6.u32l;
    // 0x80384128: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8038412C: ldc1        $f16, -0x6438($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X6438);
    // 0x80384130: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80384134: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80384138: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8038413C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80384140: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80384144: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80384148: swc1        $f4, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f4.u32l;
    // 0x8038414C: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80384150: beql        $v0, $zero, L_8038416C
    if (ctx->r2 == 0) {
        // 0x80384154: lw          $t4, 0x0($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X0);
            goto L_8038416C;
    }
    goto skip_0;
    // 0x80384154: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80384158: beql        $v0, $at, L_803841AC
    if (ctx->r2 == ctx->r1) {
        // 0x8038415C: lw          $t1, 0x0($a1)
        ctx->r9 = MEM_W(ctx->r5, 0X0);
            goto L_803841AC;
    }
    goto skip_1;
    // 0x8038415C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    skip_1:
    // 0x80384160: b           L_803841E0
    // 0x80384164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_803841E0;
    // 0x80384164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80384168: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
L_8038416C:
    // 0x8038416C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80384170: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80384174: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x80384178: lbu         $t5, 0x4B($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4B);
    // 0x8038417C: addiu       $t6, $t5, 0x20
    ctx->r14 = ADD32(ctx->r13, 0X20);
    // 0x80384180: sb          $t6, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r14;
    // 0x80384184: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80384188: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x8038418C: lbu         $t8, 0x4B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4B);
    // 0x80384190: slti        $at, $t8, 0xE0
    ctx->r1 = SIGNED(ctx->r24) < 0XE0 ? 1 : 0;
    // 0x80384194: bnel        $at, $zero, L_803841E0
    if (ctx->r1 != 0) {
        // 0x80384198: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803841E0;
    }
    goto skip_2;
    // 0x80384198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8038419C: sb          $t9, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r25;
    // 0x803841A0: b           L_803841DC
    // 0x803841A4: sh          $t0, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r8;
        goto L_803841DC;
    // 0x803841A4: sh          $t0, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r8;
    // 0x803841A8: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
L_803841AC:
    // 0x803841AC: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x803841B0: lbu         $t2, 0x4B($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4B);
    // 0x803841B4: addiu       $t3, $t2, -0xA
    ctx->r11 = ADD32(ctx->r10, -0XA);
    // 0x803841B8: sb          $t3, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r11;
    // 0x803841BC: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x803841C0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x803841C4: lbu         $t6, 0x4B($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X4B);
    // 0x803841C8: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x803841CC: beql        $at, $zero, L_803841E0
    if (ctx->r1 == 0) {
        // 0x803841D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803841E0;
    }
    goto skip_3;
    // 0x803841D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x803841D4: jal         0x80005700
    // 0x803841D8: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x803841D8: nop

    after_0:
L_803841DC:
    // 0x803841DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803841E0:
    // 0x803841E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803841E4: jr          $ra
    // 0x803841E8: nop

    return;
    // 0x803841E8: nop

;}
RECOMP_FUNC void M55_FUN_803841ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803841EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x803841F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x803841F4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x803841F8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x803841FC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80384200: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80384204: lbu         $t6, 0x204($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X204);
    // 0x80384208: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8038420C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80384210: sb          $t6, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r14;
    // 0x80384214: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80384218: lbu         $t9, 0x205($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X205);
    // 0x8038421C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80384220: sb          $t9, 0x49($t1)
    MEM_B(0X49, ctx->r9) = ctx->r25;
    // 0x80384224: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80384228: lbu         $t2, 0x206($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X206);
    // 0x8038422C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80384230: sb          $t2, 0x4A($t4)
    MEM_B(0X4A, ctx->r12) = ctx->r10;
    // 0x80384234: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80384238: lbu         $t5, 0x208($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X208);
    // 0x8038423C: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x80384240: sb          $t5, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r13;
    // 0x80384244: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80384248: lbu         $t8, 0x209($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X209);
    // 0x8038424C: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x80384250: sb          $t8, 0x4D($t9)
    MEM_B(0X4D, ctx->r25) = ctx->r24;
    // 0x80384254: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80384258: lbu         $t1, 0x20A($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X20A);
    // 0x8038425C: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x80384260: sb          $t1, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r9;
    // 0x80384264: lhu         $a2, 0xA6($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0XA6);
    // 0x80384268: andi        $v1, $a2, 0xF
    ctx->r3 = ctx->r6 & 0XF;
    // 0x8038426C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80384270: addiu       $t4, $a2, 0x1
    ctx->r12 = ADD32(ctx->r6, 0X1);
    // 0x80384274: beq         $v1, $zero, L_80384338
    if (ctx->r3 == 0) {
        // 0x80384278: sh          $t4, 0xA6($a0)
        MEM_H(0XA6, ctx->r4) = ctx->r12;
            goto L_80384338;
    }
    // 0x80384278: sh          $t4, 0xA6($a0)
    MEM_H(0XA6, ctx->r4) = ctx->r12;
    // 0x8038427C: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    // 0x80384280: jal         0x8012C6B4
    // 0x80384284: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80384284: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80384288: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8038428C: nop

    // 0x80384290: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80384294: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80384298: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8038429C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x803842A0: nop

    // 0x803842A4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x803842A8: jal         0x8001EAD0
    // 0x803842AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x803842AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x803842B0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x803842B4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x803842B8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x803842BC: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x803842C0: nop

    // 0x803842C4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x803842C8: jal         0x8001EB64
    // 0x803842CC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x803842CC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x803842D0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x803842D4: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x803842D8: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x803842DC: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x803842E0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x803842E4: add.d       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f2.d + ctx->f2.d;
    // 0x803842E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x803842EC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803842F0: add.d       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f16.d + ctx->f16.d;
    // 0x803842F4: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    // 0x803842F8: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x803842FC: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x80384300: lwc1        $f6, 0x9C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80384304: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80384308: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8038430C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80384310: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80384314: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80384318: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8038431C: lwc1        $f8, -0x6430($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6430);
    // 0x80384320: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80384324: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80384328: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8038432C: jal         0x80380F94
    // 0x80384330: nop

    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_3;
    // 0x80384330: nop

    after_3:
    // 0x80384334: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
L_80384338:
    // 0x80384338: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    // 0x8038433C: jal         0x80133A24
    // 0x80384340: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_4;
    // 0x80384340: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_4:
    // 0x80384344: bne         $v0, $zero, L_80384380
    if (ctx->r2 != 0) {
        // 0x80384348: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_80384380;
    }
    // 0x80384348: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8038434C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80384350: addiu       $t2, $zero, 0xB4
    ctx->r10 = ADD32(0, 0XB4);
    // 0x80384354: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80384358: lbu         $t8, 0x4B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4B);
    // 0x8038435C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80384360: sb          $t9, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r25;
    // 0x80384364: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80384368: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x8038436C: lbu         $t1, 0x4B($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X4B);
    // 0x80384370: slti        $at, $t1, 0xAD
    ctx->r1 = SIGNED(ctx->r9) < 0XAD ? 1 : 0;
    // 0x80384374: bnel        $at, $zero, L_80384384
    if (ctx->r1 != 0) {
        // 0x80384378: lbu         $v1, 0xA8($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0XA8);
            goto L_80384384;
    }
    goto skip_0;
    // 0x80384378: lbu         $v1, 0xA8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA8);
    skip_0:
    // 0x8038437C: sb          $t2, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r10;
L_80384380:
    // 0x80384380: lbu         $v1, 0xA8($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA8);
L_80384384:
    // 0x80384384: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80384388: beql        $v1, $zero, L_803843AC
    if (ctx->r3 == 0) {
        // 0x8038438C: lw          $t4, 0x0($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X0);
            goto L_803843AC;
    }
    goto skip_1;
    // 0x8038438C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    skip_1:
    // 0x80384390: beq         $v1, $at, L_80384424
    if (ctx->r3 == ctx->r1) {
        // 0x80384394: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80384424;
    }
    // 0x80384394: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80384398: beq         $v1, $at, L_803844C0
    if (ctx->r3 == ctx->r1) {
        // 0x8038439C: addiu       $a0, $zero, 0x131
        ctx->r4 = ADD32(0, 0X131);
            goto L_803844C0;
    }
    // 0x8038439C: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    // 0x803843A0: b           L_80384508
    // 0x803843A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80384508;
    // 0x803843A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x803843A8: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
L_803843AC:
    // 0x803843AC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803843B0: ldc1        $f0, -0x6428($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X6428);
    // 0x803843B4: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x803843B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x803843BC: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x803843C0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x803843C4: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x803843C8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x803843CC: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x803843D0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x803843D4: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x803843D8: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x803843DC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x803843E0: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x803843E4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x803843E8: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x803843EC: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x803843F0: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x803843F4: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x803843F8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x803843FC: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x80384400: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80384404: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x80384408: lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3C);
    // 0x8038440C: sltiu       $v1, $a0, 0x1
    ctx->r3 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x80384410: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80384414: beq         $v1, $zero, L_80384504
    if (ctx->r3 == 0) {
        // 0x80384418: sh          $t6, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r14;
            goto L_80384504;
    }
    // 0x80384418: sh          $t6, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r14;
    // 0x8038441C: b           L_80384504
    // 0x80384420: sb          $t0, 0xA8($s0)
    MEM_B(0XA8, ctx->r16) = ctx->r8;
        goto L_80384504;
    // 0x80384420: sb          $t0, 0xA8($s0)
    MEM_B(0XA8, ctx->r16) = ctx->r8;
L_80384424:
    // 0x80384424: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80384428: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038442C: ldc1        $f0, -0x6420($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X6420);
    // 0x80384430: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80384434: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80384438: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8038443C: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80384440: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80384444: sub.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d - ctx->f0.d;
    // 0x80384448: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8038444C: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x80384450: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80384454: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80384458: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8038445C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80384460: sub.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d - ctx->f0.d;
    // 0x80384464: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80384468: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x8038446C: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80384470: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80384474: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80384478: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8038447C: sub.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d - ctx->f0.d;
    // 0x80384480: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80384484: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x80384488: lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3C);
    // 0x8038448C: slti        $v1, $a0, 0x4
    ctx->r3 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80384490: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80384494: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
    // 0x80384498: beq         $v1, $zero, L_80384504
    if (ctx->r3 == 0) {
        // 0x8038449C: sh          $t1, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r9;
            goto L_80384504;
    }
    // 0x8038449C: sh          $t1, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r9;
    // 0x803844A0: sb          $t2, 0xA8($s0)
    MEM_B(0XA8, ctx->r16) = ctx->r10;
    // 0x803844A4: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x803844A8: addiu       $t4, $t4, 0x5C58
    ctx->r12 = ADD32(ctx->r12, 0X5C58);
    // 0x803844AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x803844B0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x803844B4: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x803844B8: b           L_80384504
    // 0x803844BC: sw          $t7, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r15;
        goto L_80384504;
    // 0x803844BC: sw          $t7, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r15;
L_803844C0:
    // 0x803844C0: jal         0x80133A24
    // 0x803844C4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_5;
    // 0x803844C4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_5:
    // 0x803844C8: beq         $v0, $zero, L_80384504
    if (ctx->r2 == 0) {
        // 0x803844CC: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_80384504;
    }
    // 0x803844CC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x803844D0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x803844D4: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x803844D8: lbu         $t8, 0x4B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4B);
    // 0x803844DC: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x803844E0: sb          $t9, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r25;
    // 0x803844E4: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x803844E8: lw          $t1, 0x30($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X30);
    // 0x803844EC: lbu         $t2, 0x4B($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X4B);
    // 0x803844F0: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x803844F4: beql        $at, $zero, L_80384508
    if (ctx->r1 == 0) {
        // 0x803844F8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80384508;
    }
    goto skip_2;
    // 0x803844F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x803844FC: jal         0x80005700
    // 0x80384500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_6;
    // 0x80384500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80384504:
    // 0x80384504: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80384508:
    // 0x80384508: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8038450C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80384510: jr          $ra
    // 0x80384514: nop

    return;
    // 0x80384514: nop

;}
RECOMP_FUNC void M55_FUN_80384518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038451C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384520: lhu         $a3, 0x3C($a0)
    ctx->r7 = MEM_HU(ctx->r4, 0X3C);
    // 0x80384524: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80384528: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8038452C: addiu       $t0, $a3, 0x1
    ctx->r8 = ADD32(ctx->r7, 0X1);
    // 0x80384530: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80384534: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80384538: addiu       $t6, $a3, 0x1
    ctx->r14 = ADD32(ctx->r7, 0X1);
    // 0x8038453C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80384540: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80384544: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80384548: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8038454C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80384550: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80384554: lbu         $t7, 0x204($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X204);
    // 0x80384558: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8038455C: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80384560: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80384564: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80384568: sb          $t7, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r15;
    // 0x8038456C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80384570: div.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f10.d);
    // 0x80384574: lbu         $t1, 0x205($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X205);
    // 0x80384578: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8038457C: multu       $a3, $a3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80384580: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384584: sb          $t1, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r9;
    // 0x80384588: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8038458C: lbu         $t4, 0x206($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X206);
    // 0x80384590: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80384594: sb          $t4, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r12;
    // 0x80384598: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8038459C: lbu         $t8, 0x208($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X208);
    // 0x803845A0: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x803845A4: sb          $t8, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r24;
    // 0x803845A8: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x803845AC: lbu         $t2, 0x209($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X209);
    // 0x803845B0: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x803845B4: mflo        $t1
    ctx->r9 = lo;
    // 0x803845B8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x803845BC: sb          $t2, 0x4D($t3)
    MEM_B(0X4D, ctx->r11) = ctx->r10;
    // 0x803845C0: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x803845C4: lbu         $t5, 0x20A($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X20A);
    // 0x803845C8: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x803845CC: sb          $t5, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r13;
    // 0x803845D0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x803845D4: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x803845D8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x803845DC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x803845E0: swc1        $f4, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f4.u32l;
    // 0x803845E4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x803845E8: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x803845EC: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x803845F0: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x803845F4: ldc1        $f10, -0x6418($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6418);
    // 0x803845F8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803845FC: ldc1        $f4, -0x6410($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X6410);
    // 0x80384600: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80384604: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80384608: slti        $at, $t0, 0x9
    ctx->r1 = SIGNED(ctx->r8) < 0X9 ? 1 : 0;
    // 0x8038460C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80384610: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80384614: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80384618: swc1        $f8, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f8.u32l;
    // 0x8038461C: lbu         $t4, 0xA8($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0XA8);
    // 0x80384620: bnel        $t4, $zero, L_80384658
    if (ctx->r12 != 0) {
        // 0x80384624: lw          $t4, 0x0($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X0);
            goto L_80384658;
    }
    goto skip_0;
    // 0x80384624: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80384628: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8038462C: lhu         $t6, 0x3C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X3C);
    // 0x80384630: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x80384634: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80384638: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8038463C: lh          $t8, 0x12($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X12);
    // 0x80384640: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80384644: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x80384648: andi        $t3, $t2, 0x1FFF
    ctx->r11 = ctx->r10 & 0X1FFF;
    // 0x8038464C: b           L_8038467C
    // 0x80384650: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
        goto L_8038467C;
    // 0x80384650: sh          $t3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r11;
    // 0x80384654: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
L_80384658:
    // 0x80384658: lhu         $t6, 0x3C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X3C);
    // 0x8038465C: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x80384660: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80384664: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80384668: lh          $t5, 0x12($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X12);
    // 0x8038466C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80384670: subu        $t1, $t5, $t7
    ctx->r9 = SUB32(ctx->r13, ctx->r15);
    // 0x80384674: andi        $t2, $t1, 0x1FFF
    ctx->r10 = ctx->r9 & 0X1FFF;
    // 0x80384678: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
L_8038467C:
    // 0x8038467C: beql        $at, $zero, L_803846A0
    if (ctx->r1 == 0) {
        // 0x80384680: slti        $at, $t0, 0x2F
        ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
            goto L_803846A0;
    }
    goto skip_1;
    // 0x80384680: slti        $at, $t0, 0x2F
    ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
    skip_1:
    // 0x80384684: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80384688: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x8038468C: lbu         $t4, 0x4B($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4B);
    // 0x80384690: addiu       $t6, $t4, 0x10
    ctx->r14 = ADD32(ctx->r12, 0X10);
    // 0x80384694: b           L_803846DC
    // 0x80384698: sb          $t6, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r14;
        goto L_803846DC;
    // 0x80384698: sb          $t6, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r14;
    // 0x8038469C: slti        $at, $t0, 0x2F
    ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
L_803846A0:
    // 0x803846A0: bnel        $at, $zero, L_803846E0
    if (ctx->r1 != 0) {
        // 0x803846A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803846E0;
    }
    goto skip_2;
    // 0x803846A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x803846A8: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x803846AC: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x803846B0: lbu         $t7, 0x4B($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4B);
    // 0x803846B4: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x803846B8: sb          $t8, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r24;
    // 0x803846BC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x803846C0: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x803846C4: lbu         $t2, 0x4B($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X4B);
    // 0x803846C8: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x803846CC: beql        $at, $zero, L_803846E0
    if (ctx->r1 == 0) {
        // 0x803846D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803846E0;
    }
    goto skip_3;
    // 0x803846D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x803846D4: jal         0x80005700
    // 0x803846D8: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x803846D8: nop

    after_0:
L_803846DC:
    // 0x803846DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803846E0:
    // 0x803846E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803846E4: jr          $ra
    // 0x803846E8: nop

    return;
    // 0x803846E8: nop

;}
RECOMP_FUNC void M55_FUN_803846ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803846EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803846F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803846F4: lhu         $a3, 0x3C($a0)
    ctx->r7 = MEM_HU(ctx->r4, 0X3C);
    // 0x803846F8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x803846FC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80384700: addiu       $t6, $a3, 0x1
    ctx->r14 = ADD32(ctx->r7, 0X1);
    // 0x80384704: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80384708: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8038470C: lbu         $t7, 0x204($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X204);
    // 0x80384710: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384714: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80384718: sb          $t7, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r15;
    // 0x8038471C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80384720: lbu         $t0, 0x205($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X205);
    // 0x80384724: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80384728: sb          $t0, 0x49($t2)
    MEM_B(0X49, ctx->r10) = ctx->r8;
    // 0x8038472C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80384730: lbu         $t3, 0x206($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X206);
    // 0x80384734: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80384738: sb          $t3, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = ctx->r11;
    // 0x8038473C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80384740: lbu         $t6, 0x208($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X208);
    // 0x80384744: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x80384748: sb          $t6, 0x4C($t7)
    MEM_B(0X4C, ctx->r15) = ctx->r14;
    // 0x8038474C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80384750: lbu         $t9, 0x209($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X209);
    // 0x80384754: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x80384758: sb          $t9, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = ctx->r25;
    // 0x8038475C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80384760: lbu         $t2, 0x20A($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X20A);
    // 0x80384764: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x80384768: sb          $t2, 0x4E($t3)
    MEM_B(0X4E, ctx->r11) = ctx->r10;
    // 0x8038476C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80384770: ldc1        $f8, -0x6408($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6408);
    // 0x80384774: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x80384778: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x8038477C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80384780: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80384784: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80384788: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8038478C: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x80384790: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80384794: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80384798: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8038479C: beq         $at, $zero, L_803847BC
    if (ctx->r1 == 0) {
        // 0x803847A0: swc1        $f18, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
            goto L_803847BC;
    }
    // 0x803847A0: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x803847A4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x803847A8: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x803847AC: lbu         $t7, 0x4B($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4B);
    // 0x803847B0: addiu       $t1, $t7, 0x3C
    ctx->r9 = ADD32(ctx->r15, 0X3C);
    // 0x803847B4: b           L_803847FC
    // 0x803847B8: sb          $t1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r9;
        goto L_803847FC;
    // 0x803847B8: sb          $t1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r9;
L_803847BC:
    // 0x803847BC: slti        $at, $a3, 0x5
    ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x803847C0: bnel        $at, $zero, L_80384800
    if (ctx->r1 != 0) {
        // 0x803847C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80384800;
    }
    goto skip_0;
    // 0x803847C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x803847C8: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x803847CC: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x803847D0: lbu         $t0, 0x4B($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X4B);
    // 0x803847D4: addiu       $t4, $t0, -0x20
    ctx->r12 = ADD32(ctx->r8, -0X20);
    // 0x803847D8: sb          $t4, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r12;
    // 0x803847DC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x803847E0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x803847E4: lbu         $t5, 0x4B($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X4B);
    // 0x803847E8: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x803847EC: beql        $at, $zero, L_80384800
    if (ctx->r1 == 0) {
        // 0x803847F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80384800;
    }
    goto skip_1;
    // 0x803847F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x803847F4: jal         0x80005700
    // 0x803847F8: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x803847F8: nop

    after_0:
L_803847FC:
    // 0x803847FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80384800:
    // 0x80384800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80384804: jr          $ra
    // 0x80384808: nop

    return;
    // 0x80384808: nop

;}
RECOMP_FUNC void M55_FUN_8038480c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038480C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80384810: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x80384814: sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // 0x80384818: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x8038481C: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x80384820: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x80384824: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x80384828: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x8038482C: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x80384830: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x80384834: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x80384838: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x8038483C: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80384840: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80384844: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80384848: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8038484C: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x80384850: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80384854: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80384858: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8038485C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384860: bnel        $t7, $zero, L_8038496C
    if (ctx->r15 != 0) {
        // 0x80384864: lui         $at, 0x4059
        ctx->r1 = S32(0X4059 << 16);
            goto L_8038496C;
    }
    goto skip_0;
    // 0x80384864: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    skip_0:
    // 0x80384868: lwc1        $f24, -0x6400($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X6400);
    // 0x8038486C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384870: lwc1        $f22, -0x63FC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X63FC);
    // 0x80384874: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80384878: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8038487C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80384880: addiu       $s6, $zero, 0x10
    ctx->r22 = ADD32(0, 0X10);
L_80384884:
    // 0x80384884: jal         0x8012C6B4
    // 0x80384888: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80384888: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_0:
    // 0x8038488C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80384890: jal         0x8012C6B4
    // 0x80384894: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80384894: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_1:
    // 0x80384898: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8038489C: jal         0x8012C6B4
    // 0x803848A0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x803848A0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_2:
    // 0x803848A4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x803848A8: jal         0x8012C6B4
    // 0x803848AC: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x803848AC: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    after_3:
    // 0x803848B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x803848B4: jal         0x8012C6B4
    // 0x803848B8: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x803848B8: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_4:
    // 0x803848BC: addiu       $t8, $s5, -0x96
    ctx->r24 = ADD32(ctx->r21, -0X96);
    // 0x803848C0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x803848C4: addiu       $t0, $s3, 0x1E
    ctx->r8 = ADD32(ctx->r19, 0X1E);
    // 0x803848C8: addiu       $t9, $s2, -0x96
    ctx->r25 = ADD32(ctx->r18, -0X96);
    // 0x803848CC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x803848D0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x803848D4: lwc1        $f12, 0x94($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X94);
    // 0x803848D8: lwc1        $f14, 0x98($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0X98);
    // 0x803848DC: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x803848E0: lw          $a2, 0x9C($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X9C);
    // 0x803848E4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x803848E8: addiu       $t2, $s0, 0x40
    ctx->r10 = ADD32(ctx->r16, 0X40);
    // 0x803848EC: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x803848F0: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x803848F4: addiu       $t4, $zero, -0x12
    ctx->r12 = ADD32(0, -0X12);
    // 0x803848F8: addiu       $t5, $zero, 0x15
    ctx->r13 = ADD32(0, 0X15);
    // 0x803848FC: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80384900: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80384904: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80384908: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8038490C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80384910: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80384914: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80384918: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8038491C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80384920: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80384924: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80384928: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8038492C: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x80384930: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80384934: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80384938: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8038493C: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80384940: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x80384944: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80384948: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8038494C: neg.d       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = -ctx->f16.d;
    // 0x80384950: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80384954: jal         0x80129FB8
    // 0x80384958: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_5;
    // 0x80384958: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8038495C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80384960: bne         $s1, $s6, L_80384884
    if (ctx->r17 != ctx->r22) {
        // 0x80384964: nop
    
            goto L_80384884;
    }
    // 0x80384964: nop

    // 0x80384968: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
L_8038496C:
    // 0x8038496C: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80384970: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80384974: jal         0x8012C6B4
    // 0x80384978: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x80384978: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_6:
    // 0x8038497C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80384980: jal         0x8012C6B4
    // 0x80384984: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x80384984: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_7:
    // 0x80384988: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8038498C: jal         0x8012C6B4
    // 0x80384990: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x80384990: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_8:
    // 0x80384994: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80384998: jal         0x8012C6B4
    // 0x8038499C: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_9;
    // 0x8038499C: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    after_9:
    // 0x803849A0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x803849A4: jal         0x8012C6B4
    // 0x803849A8: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x803849A8: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_10:
    // 0x803849AC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x803849B0: jal         0x8012C6B4
    // 0x803849B4: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x803849B4: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_11:
    // 0x803849B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x803849BC: jal         0x8012C6B4
    // 0x803849C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x803849C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x803849C4: addiu       $t6, $s1, -0x96
    ctx->r14 = ADD32(ctx->r17, -0X96);
    // 0x803849C8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x803849CC: addiu       $t7, $s6, -0x96
    ctx->r15 = ADD32(ctx->r22, -0X96);
    // 0x803849D0: lwc1        $f16, 0x94($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X94);
    // 0x803849D4: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x803849D8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x803849DC: addiu       $t8, $s5, -0x96
    ctx->r24 = ADD32(ctx->r21, -0X96);
    // 0x803849E0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803849E4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x803849E8: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x803849EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x803849F0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x803849F4: addiu       $t0, $s2, 0x40
    ctx->r8 = ADD32(ctx->r18, 0X40);
    // 0x803849F8: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x803849FC: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80384A00: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x80384A04: addiu       $t2, $zero, -0x4
    ctx->r10 = ADD32(0, -0X4);
    // 0x80384A08: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80384A0C: div.d       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80384A10: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80384A14: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x80384A18: lwc1        $f10, 0x98($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X98);
    // 0x80384A1C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80384A20: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80384A24: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80384A28: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80384A2C: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80384A30: lwc1        $f16, 0x9C($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X9C);
    // 0x80384A34: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80384A38: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80384A3C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80384A40: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x80384A44: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80384A48: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80384A4C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80384A50: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x80384A54: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80384A58: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80384A5C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80384A60: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80384A64: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80384A68: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80384A6C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80384A70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80384A74: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x80384A78: ldc1        $f10, -0x63F8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X63F8);
    // 0x80384A7C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384A80: div.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f10.d);
    // 0x80384A84: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80384A88: ldc1        $f4, -0x63F0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X63F0);
    // 0x80384A8C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80384A90: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80384A94: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80384A98: jal         0x80129FB8
    // 0x80384A9C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_13;
    // 0x80384A9C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x80384AA0: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x80384AA4: slti        $at, $t3, 0x6
    ctx->r1 = SIGNED(ctx->r11) < 0X6 ? 1 : 0;
    // 0x80384AA8: bnel        $at, $zero, L_80384ABC
    if (ctx->r1 != 0) {
        // 0x80384AAC: lw          $ra, 0x84($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X84);
            goto L_80384ABC;
    }
    goto skip_1;
    // 0x80384AAC: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    skip_1:
    // 0x80384AB0: jal         0x80005700
    // 0x80384AB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_14;
    // 0x80384AB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_14:
    // 0x80384AB8: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
L_80384ABC:
    // 0x80384ABC: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80384AC0: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x80384AC4: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x80384AC8: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x80384ACC: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x80384AD0: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80384AD4: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x80384AD8: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x80384ADC: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x80384AE0: lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X80);
    // 0x80384AE4: jr          $ra
    // 0x80384AE8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80384AE8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80384aec(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80384aec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384AEC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80384AF0: sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // 0x80384AF4: sw          $s6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r22;
    // 0x80384AF8: sw          $s5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r21;
    // 0x80384AFC: sw          $s4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r20;
    // 0x80384B00: sw          $s3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r19;
    // 0x80384B04: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // 0x80384B08: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // 0x80384B0C: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x80384B10: sdc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X70, ctx->r29);
    // 0x80384B14: sdc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X68, ctx->r29);
    // 0x80384B18: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x80384B1C: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x80384B20: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80384B24: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80384B28: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80384B2C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80384B30: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80384B34: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80384B38: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80384B3C: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80384B40: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80384B44: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80384B48: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80384B4C: bne         $t7, $zero, L_80384CD0
    if (ctx->r15 != 0) {
        // 0x80384B50: addiu       $t0, $zero, 0xFF
        ctx->r8 = ADD32(0, 0XFF);
            goto L_80384CD0;
    }
    // 0x80384B50: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80384B54: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x80384B58: lwc1        $f12, 0x94($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X94);
    // 0x80384B5C: lw          $a2, 0x9C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X9C);
    // 0x80384B60: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80384B64: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80384B68: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384B6C: lwc1        $f6, -0x63E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X63E8);
    // 0x80384B70: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x80384B74: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x80384B78: addiu       $t3, $zero, -0x6
    ctx->r11 = ADD32(0, -0X6);
    // 0x80384B7C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80384B80: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80384B84: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80384B88: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80384B8C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80384B90: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80384B94: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80384B98: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80384B9C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80384BA0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80384BA4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80384BA8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80384BAC: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    // 0x80384BB0: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x80384BB4: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    // 0x80384BB8: add.s       $f14, $f4, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80384BBC: jal         0x80129FB8
    // 0x80384BC0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_0;
    // 0x80384BC0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80384BC4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384BC8: lwc1        $f26, -0x63E4($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X63E4);
    // 0x80384BCC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384BD0: lwc1        $f24, -0x63E0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X63E0);
    // 0x80384BD4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80384BD8: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80384BDC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80384BE0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80384BE4: addiu       $s6, $zero, 0x20
    ctx->r22 = ADD32(0, 0X20);
L_80384BE8:
    // 0x80384BE8: jal         0x8012C6B4
    // 0x80384BEC: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80384BEC: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    after_1:
    // 0x80384BF0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80384BF4: jal         0x8012C6B4
    // 0x80384BF8: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80384BF8: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    after_2:
    // 0x80384BFC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80384C00: jal         0x8012C6B4
    // 0x80384C04: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x80384C04: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_3:
    // 0x80384C08: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80384C0C: jal         0x8012C6B4
    // 0x80384C10: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80384C10: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    after_4:
    // 0x80384C14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80384C18: jal         0x8012C6B4
    // 0x80384C1C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80384C1C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_5:
    // 0x80384C20: addiu       $t5, $s5, -0xAA
    ctx->r13 = ADD32(ctx->r21, -0XAA);
    // 0x80384C24: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80384C28: addiu       $t7, $s3, 0x1E
    ctx->r15 = ADD32(ctx->r19, 0X1E);
    // 0x80384C2C: lwc1        $f8, 0x98($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X98);
    // 0x80384C30: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80384C34: addiu       $t6, $s2, -0xAA
    ctx->r14 = ADD32(ctx->r18, -0XAA);
    // 0x80384C38: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80384C3C: lwc1        $f12, 0x94($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X94);
    // 0x80384C40: add.s       $f14, $f8, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80384C44: lw          $a2, 0x9C($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X9C);
    // 0x80384C48: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80384C4C: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x80384C50: addiu       $t9, $s0, 0x40
    ctx->r25 = ADD32(ctx->r16, 0X40);
    // 0x80384C54: addiu       $t0, $zero, 0xB4
    ctx->r8 = ADD32(0, 0XB4);
    // 0x80384C58: addiu       $t1, $zero, -0xC
    ctx->r9 = ADD32(0, -0XC);
    // 0x80384C5C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80384C60: addiu       $t2, $zero, 0x15
    ctx->r10 = ADD32(0, 0X15);
    // 0x80384C64: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80384C68: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80384C6C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80384C70: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80384C74: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80384C78: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80384C7C: swc1        $f26, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f26.u32l;
    // 0x80384C80: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80384C84: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80384C88: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80384C8C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80384C90: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x80384C94: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80384C98: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80384C9C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80384CA0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80384CA4: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80384CA8: div.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x80384CAC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80384CB0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80384CB4: neg.d       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = -ctx->f6.d;
    // 0x80384CB8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80384CBC: jal         0x80129FB8
    // 0x80384CC0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_6;
    // 0x80384CC0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80384CC4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80384CC8: bne         $s1, $s6, L_80384BE8
    if (ctx->r17 != ctx->r22) {
        // 0x80384CCC: nop
    
            goto L_80384BE8;
    }
    // 0x80384CCC: nop

L_80384CD0:
    // 0x80384CD0: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80384CD4: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80384CD8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80384CDC: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80384CE0: jal         0x8012C6B4
    // 0x80384CE4: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x80384CE4: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    after_7:
    // 0x80384CE8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80384CEC: jal         0x8012C6B4
    // 0x80384CF0: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x80384CF0: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    after_8:
    // 0x80384CF4: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80384CF8: jal         0x8012C6B4
    // 0x80384CFC: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_9;
    // 0x80384CFC: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    after_9:
    // 0x80384D00: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80384D04: jal         0x8012C6B4
    // 0x80384D08: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x80384D08: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    after_10:
    // 0x80384D0C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80384D10: jal         0x8012C6B4
    // 0x80384D14: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x80384D14: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_11:
    // 0x80384D18: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80384D1C: jal         0x8012C6B4
    // 0x80384D20: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x80384D20: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    after_12:
    // 0x80384D24: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80384D28: jal         0x8012C6B4
    // 0x80384D2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_13;
    // 0x80384D2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x80384D30: addiu       $t3, $s1, -0x3E8
    ctx->r11 = ADD32(ctx->r17, -0X3E8);
    // 0x80384D34: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80384D38: addiu       $t4, $s6, -0x1F4
    ctx->r12 = ADD32(ctx->r22, -0X1F4);
    // 0x80384D3C: lwc1        $f6, 0x94($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X94);
    // 0x80384D40: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80384D44: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80384D48: addiu       $t5, $s5, -0x3E8
    ctx->r13 = ADD32(ctx->r21, -0X3E8);
    // 0x80384D4C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384D50: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80384D54: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x80384D58: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80384D5C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80384D60: addiu       $t7, $s2, 0x40
    ctx->r15 = ADD32(ctx->r18, 0X40);
    // 0x80384D64: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80384D68: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80384D6C: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x80384D70: addiu       $t9, $zero, -0x6
    ctx->r25 = ADD32(0, -0X6);
    // 0x80384D74: div.d       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x80384D78: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80384D7C: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80384D80: lwc1        $f4, 0x98($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X98);
    // 0x80384D84: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80384D88: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x80384D8C: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x80384D90: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x80384D94: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80384D98: lwc1        $f6, 0x9C($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X9C);
    // 0x80384D9C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80384DA0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80384DA4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80384DA8: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x80384DAC: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80384DB0: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80384DB4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80384DB8: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x80384DBC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80384DC0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80384DC4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80384DC8: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80384DCC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80384DD0: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    // 0x80384DD4: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x80384DD8: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    // 0x80384DDC: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80384DE0: ldc1        $f4, -0x63D8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X63D8);
    // 0x80384DE4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384DE8: div.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f4.d);
    // 0x80384DEC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80384DF0: ldc1        $f10, -0x63D0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X63D0);
    // 0x80384DF4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80384DF8: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80384DFC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80384E00: jal         0x80129FB8
    // 0x80384E04: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_14;
    // 0x80384E04: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x80384E08: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x80384E0C: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x80384E10: bnel        $at, $zero, L_80384E24
    if (ctx->r1 != 0) {
        // 0x80384E14: lw          $ra, 0x94($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X94);
            goto L_80384E24;
    }
    goto skip_0;
    // 0x80384E14: lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X94);
    skip_0:
    // 0x80384E18: jal         0x80005700
    // 0x80384E1C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_15;
    // 0x80384E1C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_15:
    // 0x80384E20: lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X94);
L_80384E24:
    // 0x80384E24: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80384E28: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x80384E2C: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x80384E30: ldc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X68);
    // 0x80384E34: ldc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X70);
    // 0x80384E38: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x80384E3C: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x80384E40: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x80384E44: lw          $s3, 0x84($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X84);
    // 0x80384E48: lw          $s4, 0x88($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X88);
    // 0x80384E4C: lw          $s5, 0x8C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X8C);
    // 0x80384E50: lw          $s6, 0x90($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X90);
    // 0x80384E54: jr          $ra
    // 0x80384E58: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80384E58: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80384e5c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80384e5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384E5C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80384E60: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80384E64: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x80384E68: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x80384E6C: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80384E70: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80384E74: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80384E78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80384E7C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80384E80: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80384E84: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80384E88: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80384E8C: bnel        $t7, $zero, L_80384FB4
    if (ctx->r15 != 0) {
        // 0x80384E90: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_80384FB4;
    }
    goto skip_0;
    // 0x80384E90: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    skip_0:
    // 0x80384E94: jal         0x8012C6B4
    // 0x80384E98: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80384E98: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_0:
    // 0x80384E9C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80384EA0: jal         0x8012C6B4
    // 0x80384EA4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80384EA4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x80384EA8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80384EAC: jal         0x8012C6B4
    // 0x80384EB0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80384EB0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_2:
    // 0x80384EB4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80384EB8: jal         0x8012C6B4
    // 0x80384EBC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x80384EBC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_3:
    // 0x80384EC0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80384EC4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80384EC8: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80384ECC: addiu       $t9, $t8, -0x64
    ctx->r25 = ADD32(ctx->r24, -0X64);
    // 0x80384ED0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80384ED4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80384ED8: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80384EDC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80384EE0: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80384EE4: addiu       $t1, $t0, -0x64
    ctx->r9 = ADD32(ctx->r8, -0X64);
    // 0x80384EE8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80384EEC: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80384EF0: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80384EF4: addiu       $t3, $t2, -0x64
    ctx->r11 = ADD32(ctx->r10, -0X64);
    // 0x80384EF8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384EFC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80384F00: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80384F04: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80384F08: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x80384F0C: addiu       $t5, $zero, -0x6
    ctx->r13 = ADD32(0, -0X6);
    // 0x80384F10: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80384F14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80384F18: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80384F1C: div.d       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80384F20: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80384F24: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80384F28: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80384F2C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80384F30: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x80384F34: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80384F38: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80384F3C: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80384F40: lwc1        $f10, 0x9C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80384F44: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80384F48: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80384F4C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80384F50: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80384F54: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80384F58: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80384F5C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80384F60: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x80384F64: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80384F68: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80384F6C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80384F70: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80384F74: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80384F78: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80384F7C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80384F80: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80384F84: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80384F88: ldc1        $f8, -0x63C8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X63C8);
    // 0x80384F8C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80384F90: div.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x80384F94: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80384F98: ldc1        $f18, -0x63C0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X63C0);
    // 0x80384F9C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80384FA0: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80384FA4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80384FA8: jal         0x80129FB8
    // 0x80384FAC: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_4;
    // 0x80384FAC: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80384FB0: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_80384FB4:
    // 0x80384FB4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80384FB8: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80384FBC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80384FC0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80384FC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80384FC8: bnel        $t7, $at, L_80385100
    if (ctx->r15 != ctx->r1) {
        // 0x80384FCC: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80385100;
    }
    goto skip_1;
    // 0x80384FCC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_1:
    // 0x80384FD0: jal         0x8012C6B4
    // 0x80384FD4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80384FD4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_5:
    // 0x80384FD8: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80384FDC: jal         0x8012C6B4
    // 0x80384FE0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x80384FE0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_6:
    // 0x80384FE4: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80384FE8: jal         0x8012C6B4
    // 0x80384FEC: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x80384FEC: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_7:
    // 0x80384FF0: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80384FF4: jal         0x8012C6B4
    // 0x80384FF8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x80384FF8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_8:
    // 0x80384FFC: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80385000: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80385004: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80385008: addiu       $t9, $t8, -0x64
    ctx->r25 = ADD32(ctx->r24, -0X64);
    // 0x8038500C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80385010: addiu       $t1, $t0, -0x64
    ctx->r9 = ADD32(ctx->r8, -0X64);
    // 0x80385014: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80385018: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x8038501C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80385020: addiu       $t3, $t2, -0x64
    ctx->r11 = ADD32(ctx->r10, -0X64);
    // 0x80385024: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385028: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8038502C: div.d       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80385030: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80385034: addiu       $t1, $zero, -0x6
    ctx->r9 = ADD32(0, -0X6);
    // 0x80385038: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x8038503C: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x80385040: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80385044: addiu       $t9, $zero, 0x60
    ctx->r25 = ADD32(0, 0X60);
    // 0x80385048: addiu       $t8, $zero, 0x60
    ctx->r24 = ADD32(0, 0X60);
    // 0x8038504C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80385050: addiu       $t4, $zero, 0x60
    ctx->r12 = ADD32(0, 0X60);
    // 0x80385054: addiu       $t5, $zero, 0x60
    ctx->r13 = ADD32(0, 0X60);
    // 0x80385058: addiu       $t6, $zero, 0x60
    ctx->r14 = ADD32(0, 0X60);
    // 0x8038505C: addiu       $t7, $zero, 0x60
    ctx->r15 = ADD32(0, 0X60);
    // 0x80385060: div.d       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80385064: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x80385068: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x8038506C: lwc1        $f16, 0x98($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80385070: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80385074: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80385078: div.d       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x8038507C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80385080: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80385084: lwc1        $f18, 0x9C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80385088: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8038508C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80385090: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80385094: cvt.d.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.d = CVT_D_W(ctx->f8.u32l);
    // 0x80385098: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8038509C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x803850A0: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x803850A4: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x803850A8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x803850AC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x803850B0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x803850B4: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x803850B8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x803850BC: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x803850C0: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x803850C4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x803850C8: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x803850CC: ldc1        $f16, -0x63B8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X63B8);
    // 0x803850D0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803850D4: div.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f16.d);
    // 0x803850D8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x803850DC: ldc1        $f6, -0x63B0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X63B0);
    // 0x803850E0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x803850E4: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x803850E8: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x803850EC: jal         0x80129FB8
    // 0x803850F0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_9;
    // 0x803850F0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x803850F4: jal         0x80005700
    // 0x803850F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_10;
    // 0x803850F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x803850FC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80385100:
    // 0x80385100: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80385104: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x80385108: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8038510C: jr          $ra
    // 0x80385110: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80385110: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80385114(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80385114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385114: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80385118: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x8038511C: sw          $s6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r22;
    // 0x80385120: sw          $s5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r21;
    // 0x80385124: sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // 0x80385128: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x8038512C: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x80385130: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x80385134: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x80385138: sdc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X78, ctx->r29);
    // 0x8038513C: sdc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X70, ctx->r29);
    // 0x80385140: sdc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X68, ctx->r29);
    // 0x80385144: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x80385148: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x8038514C: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80385150: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x80385154: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80385158: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8038515C: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x80385160: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x80385164: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80385168: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x8038516C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385170: ldc1        $f24, -0x63A8($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, -0X63A8);
    // 0x80385174: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385178: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8038517C: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80385180: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80385184: ldc1        $f20, -0x63A0($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X63A0);
    // 0x80385188: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8038518C:
    // 0x8038518C: jal         0x8012C6B4
    // 0x80385190: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80385190: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    after_0:
    // 0x80385194: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80385198: jal         0x8012C6B4
    // 0x8038519C: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x8038519C: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    after_1:
    // 0x803851A0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x803851A4: jal         0x8012C6B4
    // 0x803851A8: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x803851A8: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    after_2:
    // 0x803851AC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x803851B0: jal         0x8012C6B4
    // 0x803851B4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x803851B4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_3:
    // 0x803851B8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x803851BC: jal         0x8012C6B4
    // 0x803851C0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x803851C0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_4:
    // 0x803851C4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x803851C8: jal         0x8012C6B4
    // 0x803851CC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x803851CC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_5:
    // 0x803851D0: addiu       $t7, $s5, -0x258
    ctx->r15 = ADD32(ctx->r21, -0X258);
    // 0x803851D4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x803851D8: addiu       $t8, $s6, -0x258
    ctx->r24 = ADD32(ctx->r22, -0X258);
    // 0x803851DC: lwc1        $f10, 0x94($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X94);
    // 0x803851E0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x803851E4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x803851E8: addiu       $t9, $s3, -0x258
    ctx->r25 = ADD32(ctx->r19, -0X258);
    // 0x803851EC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x803851F0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x803851F4: div.d       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f28.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f28.d);
    // 0x803851F8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x803851FC: addiu       $t1, $s4, 0x8E
    ctx->r9 = ADD32(ctx->r20, 0X8E);
    // 0x80385200: addiu       $t2, $zero, 0x94
    ctx->r10 = ADD32(0, 0X94);
    // 0x80385204: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80385208: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8038520C: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x80385210: addiu       $t4, $zero, -0x4
    ctx->r12 = ADD32(0, -0X4);
    // 0x80385214: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80385218: div.d       $f10, $f6, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f28.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f28.d);
    // 0x8038521C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80385220: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80385224: lwc1        $f8, 0x98($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80385228: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8038522C: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x80385230: div.d       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f28.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f28.d);
    // 0x80385234: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80385238: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8038523C: lwc1        $f10, 0x9C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x80385240: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80385244: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80385248: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8038524C: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80385250: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80385254: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80385258: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8038525C: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x80385260: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80385264: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80385268: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8038526C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80385270: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80385274: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80385278: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8038527C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80385280: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80385284: div.d       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x80385288: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8038528C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80385290: add.d       $f16, $f8, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f24.d); 
    ctx->f16.d = ctx->f8.d + ctx->f24.d;
    // 0x80385294: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80385298: jal         0x80129FB8
    // 0x8038529C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_6;
    // 0x8038529C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x803852A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x803852A4: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x803852A8: bne         $at, $zero, L_8038518C
    if (ctx->r1 != 0) {
        // 0x803852AC: nop
    
            goto L_8038518C;
    }
    // 0x803852AC: nop

    // 0x803852B0: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x803852B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x803852B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x803852BC: bne         $t6, $at, L_803853D4
    if (ctx->r14 != ctx->r1) {
        // 0x803852C0: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_803853D4;
    }
    // 0x803852C0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803852C4: lwc1        $f30, -0x6398($at)
    ctx->f30.u32l = MEM_W(ctx->r1, -0X6398);
    // 0x803852C8: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x803852CC: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x803852D0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x803852D4: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
L_803852D8:
    // 0x803852D8: jal         0x8012C6B4
    // 0x803852DC: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x803852DC: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_7:
    // 0x803852E0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x803852E4: nop

    // 0x803852E8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x803852EC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x803852F0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x803852F4: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x803852F8: nop

    // 0x803852FC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80385300: jal         0x8001EAD0
    // 0x80385304: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x80385304: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_8:
    // 0x80385308: trunc.w.s   $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    ctx->f10.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x8038530C: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80385310: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80385314: nop

    // 0x80385318: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8038531C: jal         0x8001EB64
    // 0x80385320: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_9;
    // 0x80385320: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_9:
    // 0x80385324: cvt.d.s     $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f8.d = CVT_D_S(ctx->f26.fl);
    // 0x80385328: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8038532C: mul.d       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x80385330: lwc1        $f18, 0x94($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80385334: lwc1        $f14, 0x98($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80385338: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8038533C: mul.d       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x80385340: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80385344: lwc1        $f18, 0x9C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x80385348: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8038534C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80385350: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x80385354: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x80385358: addiu       $t0, $zero, 0x4B
    ctx->r8 = ADD32(0, 0X4B);
    // 0x8038535C: addiu       $t1, $zero, 0x4B
    ctx->r9 = ADD32(0, 0X4B);
    // 0x80385360: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80385364: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80385368: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x8038536C: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x80385370: add.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f8.d + ctx->f16.d;
    // 0x80385374: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x80385378: addiu       $t5, $zero, 0xFA
    ctx->r13 = ADD32(0, 0XFA);
    // 0x8038537C: addiu       $t6, $zero, -0x2
    ctx->r14 = ADD32(0, -0X2);
    // 0x80385380: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80385384: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80385388: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8038538C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80385390: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80385394: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80385398: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8038539C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x803853A0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x803853A4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x803853A8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x803853AC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x803853B0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x803853B4: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x803853B8: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x803853BC: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x803853C0: jal         0x80129FB8
    // 0x803853C4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_10;
    // 0x803853C4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x803853C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x803853CC: bne         $s0, $s1, L_803852D8
    if (ctx->r16 != ctx->r17) {
        // 0x803853D0: nop
    
            goto L_803852D8;
    }
    // 0x803853D0: nop

L_803853D4:
    // 0x803853D4: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x803853D8: bgez        $t8, L_803853EC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x803853DC: andi        $t9, $t8, 0x1
        ctx->r25 = ctx->r24 & 0X1;
            goto L_803853EC;
    }
    // 0x803853DC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x803853E0: beq         $t9, $zero, L_803853EC
    if (ctx->r25 == 0) {
        // 0x803853E4: nop
    
            goto L_803853EC;
    }
    // 0x803853E4: nop

    // 0x803853E8: addiu       $t9, $t9, -0x2
    ctx->r25 = ADD32(ctx->r25, -0X2);
L_803853EC:
    // 0x803853EC: bnel        $t9, $zero, L_80385530
    if (ctx->r25 != 0) {
        // 0x803853F0: lw          $t9, 0xA4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA4);
            goto L_80385530;
    }
    goto skip_0;
    // 0x803853F0: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    skip_0:
    // 0x803853F4: jal         0x8012C6B4
    // 0x803853F8: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x803853F8: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_11:
    // 0x803853FC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80385400: jal         0x8012C6B4
    // 0x80385404: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x80385404: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_12:
    // 0x80385408: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8038540C: jal         0x8012C6B4
    // 0x80385410: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_13;
    // 0x80385410: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_13:
    // 0x80385414: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80385418: jal         0x8012C6B4
    // 0x8038541C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_14;
    // 0x8038541C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_14:
    // 0x80385420: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80385424: jal         0x8012C6B4
    // 0x80385428: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_15;
    // 0x80385428: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_15:
    // 0x8038542C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80385430: jal         0x8012C6B4
    // 0x80385434: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_16;
    // 0x80385434: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_16:
    // 0x80385438: addiu       $t0, $s5, -0x1F4
    ctx->r8 = ADD32(ctx->r21, -0X1F4);
    // 0x8038543C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80385440: addiu       $t1, $s6, -0x1F4
    ctx->r9 = ADD32(ctx->r22, -0X1F4);
    // 0x80385444: lwc1        $f4, 0x94($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80385448: cvt.d.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.d = CVT_D_W(ctx->f18.u32l);
    // 0x8038544C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80385450: addiu       $t2, $s3, -0x1F4
    ctx->r10 = ADD32(ctx->r19, -0X1F4);
    // 0x80385454: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385458: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8038545C: div.d       $f16, $f8, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f28.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f28.d);
    // 0x80385460: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80385464: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80385468: addiu       $t4, $s4, 0x8E
    ctx->r12 = ADD32(ctx->r20, 0X8E);
    // 0x8038546C: cvt.d.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.d = CVT_D_W(ctx->f18.u32l);
    // 0x80385470: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80385474: addiu       $t5, $zero, 0x94
    ctx->r13 = ADD32(0, 0X94);
    // 0x80385478: addiu       $t6, $zero, 0x8C
    ctx->r14 = ADD32(0, 0X8C);
    // 0x8038547C: addiu       $t7, $zero, -0x4
    ctx->r15 = ADD32(0, -0X4);
    // 0x80385480: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80385484: div.d       $f4, $f8, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f28.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f28.d);
    // 0x80385488: cvt.d.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.d = CVT_D_W(ctx->f18.u32l);
    // 0x8038548C: add.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f16.d + ctx->f6.d;
    // 0x80385490: lwc1        $f16, 0x98($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80385494: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80385498: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x8038549C: div.d       $f16, $f8, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f28.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f28.d);
    // 0x803854A0: lwc1        $f8, -0x6394($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6394);
    // 0x803854A4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x803854A8: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x803854AC: lwc1        $f4, 0x9C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x803854B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x803854B4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x803854B8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x803854BC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x803854C0: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x803854C4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x803854C8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x803854CC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x803854D0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x803854D4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x803854D8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x803854DC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x803854E0: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x803854E4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x803854E8: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x803854EC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x803854F0: add.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f16.d + ctx->f6.d;
    // 0x803854F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x803854F8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x803854FC: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x80385500: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80385504: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80385508: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8038550C: div.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f6.d);
    // 0x80385510: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80385514: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80385518: nop

    // 0x8038551C: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x80385520: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80385524: jal         0x80129FB8
    // 0x80385528: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_17;
    // 0x80385528: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_17:
    // 0x8038552C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80385530:
    // 0x80385530: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x80385534: bnel        $at, $zero, L_80385548
    if (ctx->r1 != 0) {
        // 0x80385538: lw          $ra, 0x9C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X9C);
            goto L_80385548;
    }
    goto skip_1;
    // 0x80385538: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    skip_1:
    // 0x8038553C: jal         0x80005700
    // 0x80385540: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_18;
    // 0x80385540: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_18:
    // 0x80385544: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
L_80385548:
    // 0x80385548: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x8038554C: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x80385550: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x80385554: ldc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X68);
    // 0x80385558: ldc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X70);
    // 0x8038555C: ldc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X78);
    // 0x80385560: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x80385564: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x80385568: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x8038556C: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x80385570: lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X90);
    // 0x80385574: lw          $s5, 0x94($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X94);
    // 0x80385578: lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X98);
    // 0x8038557C: jr          $ra
    // 0x80385580: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80385580: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80385584(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80385584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385584: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80385588: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8038558C: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x80385590: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x80385594: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x80385598: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x8038559C: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x803855A0: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x803855A4: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x803855A8: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x803855AC: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x803855B0: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x803855B4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x803855B8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x803855BC: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x803855C0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x803855C4: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x803855C8: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x803855CC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803855D0: bnel        $t7, $zero, L_80385794
    if (ctx->r15 != 0) {
        // 0x803855D4: lw          $t8, 0x84($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X84);
            goto L_80385794;
    }
    goto skip_0;
    // 0x803855D4: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    skip_0:
    // 0x803855D8: lwc1        $f24, -0x6390($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X6390);
    // 0x803855DC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803855E0: lwc1        $f22, -0x638C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X638C);
    // 0x803855E4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x803855E8: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x803855EC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x803855F0: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_803855F4:
    // 0x803855F4: jal         0x8012C6B4
    // 0x803855F8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x803855F8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_0:
    // 0x803855FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80385600: jal         0x8012C6B4
    // 0x80385604: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80385604: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x80385608: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8038560C: jal         0x8012C6B4
    // 0x80385610: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80385610: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_2:
    // 0x80385614: addiu       $t8, $s0, -0x64
    ctx->r24 = ADD32(ctx->r16, -0X64);
    // 0x80385618: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8038561C: addiu       $t0, $v0, -0x64
    ctx->r8 = ADD32(ctx->r2, -0X64);
    // 0x80385620: addiu       $t9, $s1, -0x32
    ctx->r25 = ADD32(ctx->r17, -0X32);
    // 0x80385624: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80385628: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8038562C: lwc1        $f12, 0x94($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80385630: lwc1        $f14, 0x98($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80385634: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80385638: lw          $a2, 0x9C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X9C);
    // 0x8038563C: addiu       $t9, $zero, 0x15
    ctx->r25 = ADD32(0, 0X15);
    // 0x80385640: addiu       $t8, $zero, -0xE
    ctx->r24 = ADD32(0, -0XE);
    // 0x80385644: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80385648: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8038564C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80385650: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80385654: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80385658: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8038565C: addiu       $t6, $zero, 0x76
    ctx->r14 = ADD32(0, 0X76);
    // 0x80385660: addiu       $t7, $zero, 0xDC
    ctx->r15 = ADD32(0, 0XDC);
    // 0x80385664: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80385668: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x8038566C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80385670: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80385674: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80385678: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8038567C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80385680: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80385684: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80385688: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8038568C: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80385690: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80385694: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x80385698: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8038569C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x803856A0: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x803856A4: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x803856A8: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x803856AC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x803856B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x803856B4: neg.d       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = -ctx->f16.d;
    // 0x803856B8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x803856BC: jal         0x80129FB8
    // 0x803856C0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_3;
    // 0x803856C0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x803856C4: jal         0x8012C6B4
    // 0x803856C8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x803856C8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_4:
    // 0x803856CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x803856D0: jal         0x8012C6B4
    // 0x803856D4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x803856D4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_5:
    // 0x803856D8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x803856DC: jal         0x8012C6B4
    // 0x803856E0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x803856E0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_6:
    // 0x803856E4: addiu       $t0, $s0, -0x64
    ctx->r8 = ADD32(ctx->r16, -0X64);
    // 0x803856E8: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x803856EC: addiu       $t2, $v0, -0x64
    ctx->r10 = ADD32(ctx->r2, -0X64);
    // 0x803856F0: addiu       $t1, $s1, -0x32
    ctx->r9 = ADD32(ctx->r17, -0X32);
    // 0x803856F4: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x803856F8: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x803856FC: lwc1        $f12, 0x94($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80385700: lwc1        $f14, 0x98($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80385704: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80385708: lw          $a2, 0x9C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X9C);
    // 0x8038570C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80385710: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80385714: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80385718: addiu       $t5, $zero, 0xDC
    ctx->r13 = ADD32(0, 0XDC);
    // 0x8038571C: addiu       $t6, $zero, -0xE
    ctx->r14 = ADD32(0, -0XE);
    // 0x80385720: addiu       $t7, $zero, 0x15
    ctx->r15 = ADD32(0, 0X15);
    // 0x80385724: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80385728: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8038572C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80385730: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80385734: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80385738: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8038573C: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80385740: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80385744: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80385748: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8038574C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80385750: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80385754: div.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x80385758: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8038575C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80385760: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80385764: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80385768: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x8038576C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80385770: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80385774: neg.d       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = -ctx->f18.d;
    // 0x80385778: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8038577C: jal         0x80129FB8
    // 0x80385780: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_7;
    // 0x80385780: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x80385784: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80385788: bne         $s3, $s4, L_803855F4
    if (ctx->r19 != ctx->r20) {
        // 0x8038578C: nop
    
            goto L_803855F4;
    }
    // 0x8038578C: nop

    // 0x80385790: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
L_80385794:
    // 0x80385794: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80385798: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8038579C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x803857A0: bgez        $t8, L_803857B4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x803857A4: andi        $t9, $t8, 0x1
        ctx->r25 = ctx->r24 & 0X1;
            goto L_803857B4;
    }
    // 0x803857A4: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x803857A8: beq         $t9, $zero, L_803857B4
    if (ctx->r25 == 0) {
        // 0x803857AC: nop
    
            goto L_803857B4;
    }
    // 0x803857AC: nop

    // 0x803857B0: addiu       $t9, $t9, -0x2
    ctx->r25 = ADD32(ctx->r25, -0X2);
L_803857B4:
    // 0x803857B4: bnel        $t9, $zero, L_803858D8
    if (ctx->r25 != 0) {
        // 0x803857B8: lw          $t1, 0x84($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X84);
            goto L_803858D8;
    }
    goto skip_1;
    // 0x803857B8: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    skip_1:
    // 0x803857BC: jal         0x8012C6B4
    // 0x803857C0: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x803857C0: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_8:
    // 0x803857C4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x803857C8: jal         0x8012C6B4
    // 0x803857CC: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_9;
    // 0x803857CC: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_9:
    // 0x803857D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x803857D4: jal         0x8012C6B4
    // 0x803857D8: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x803857D8: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_10:
    // 0x803857DC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x803857E0: jal         0x8012C6B4
    // 0x803857E4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x803857E4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_11:
    // 0x803857E8: addiu       $t0, $s3, -0xC8
    ctx->r8 = ADD32(ctx->r19, -0XC8);
    // 0x803857EC: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x803857F0: addiu       $t1, $s0, -0xC8
    ctx->r9 = ADD32(ctx->r16, -0XC8);
    // 0x803857F4: lwc1        $f18, 0x94($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X94);
    // 0x803857F8: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x803857FC: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80385800: addiu       $t2, $s1, -0xC8
    ctx->r10 = ADD32(ctx->r17, -0XC8);
    // 0x80385804: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385808: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8038580C: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x80385810: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80385814: addiu       $t0, $zero, -0x4
    ctx->r8 = ADD32(0, -0X4);
    // 0x80385818: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8038581C: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80385820: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80385824: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80385828: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8038582C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80385830: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80385834: addiu       $t8, $zero, 0x76
    ctx->r24 = ADD32(0, 0X76);
    // 0x80385838: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x8038583C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80385840: div.d       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x80385844: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80385848: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x8038584C: lwc1        $f16, 0x98($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80385850: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80385854: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80385858: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x8038585C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80385860: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80385864: lwc1        $f18, 0x9C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x80385868: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8038586C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80385870: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80385874: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x80385878: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8038587C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80385880: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80385884: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80385888: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8038588C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80385890: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80385894: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80385898: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8038589C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x803858A0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x803858A4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x803858A8: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x803858AC: ldc1        $f16, -0x6388($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X6388);
    // 0x803858B0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803858B4: div.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f16.d);
    // 0x803858B8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x803858BC: ldc1        $f6, -0x6380($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6380);
    // 0x803858C0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x803858C4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x803858C8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x803858CC: jal         0x80129FB8
    // 0x803858D0: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_12;
    // 0x803858D0: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x803858D4: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
L_803858D8:
    // 0x803858D8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x803858DC: bnel        $t1, $at, L_803858F0
    if (ctx->r9 != ctx->r1) {
        // 0x803858E0: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_803858F0;
    }
    goto skip_2;
    // 0x803858E0: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_2:
    // 0x803858E4: jal         0x80005700
    // 0x803858E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_13;
    // 0x803858E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x803858EC: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_803858F0:
    // 0x803858F0: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x803858F4: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x803858F8: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x803858FC: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x80385900: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x80385904: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80385908: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x8038590C: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x80385910: jr          $ra
    // 0x80385914: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80385914: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80385918(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80385918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385918: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8038591C: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x80385920: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x80385924: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x80385928: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x8038592C: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x80385930: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x80385934: sdc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X68, ctx->r29);
    // 0x80385938: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x8038593C: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x80385940: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80385944: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80385948: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x8038594C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80385950: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80385954: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x80385958: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8038595C: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80385960: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x80385964: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80385968: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8038596C: bne         $t7, $zero, L_80385B9C
    if (ctx->r15 != 0) {
        // 0x80385970: addiu       $t1, $zero, 0xFF
        ctx->r9 = ADD32(0, 0XFF);
            goto L_80385B9C;
    }
    // 0x80385970: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80385974: lwc1        $f12, 0x94($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X94);
    // 0x80385978: lwc1        $f14, 0x98($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X98);
    // 0x8038597C: lw          $a2, 0x9C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X9C);
    // 0x80385980: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80385984: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385988: lwc1        $f4, -0x6378($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6378);
    // 0x8038598C: addiu       $t2, $zero, 0x9A
    ctx->r10 = ADD32(0, 0X9A);
    // 0x80385990: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x80385994: addiu       $t4, $zero, -0x4
    ctx->r12 = ADD32(0, -0X4);
    // 0x80385998: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8038599C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x803859A0: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x803859A4: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x803859A8: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x803859AC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x803859B0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x803859B4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x803859B8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x803859BC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x803859C0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x803859C4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x803859C8: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x803859CC: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x803859D0: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x803859D4: jal         0x80129FB8
    // 0x803859D8: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_0;
    // 0x803859D8: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x803859DC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803859E0: lwc1        $f24, -0x6374($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X6374);
    // 0x803859E4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803859E8: lwc1        $f22, -0x6370($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X6370);
    // 0x803859EC: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x803859F0: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x803859F4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x803859F8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x803859FC: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_80385A00:
    // 0x80385A00: jal         0x8012C6B4
    // 0x80385A04: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80385A04: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_1:
    // 0x80385A08: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80385A0C: jal         0x8012C6B4
    // 0x80385A10: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80385A10: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_2:
    // 0x80385A14: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80385A18: jal         0x8012C6B4
    // 0x80385A1C: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x80385A1C: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_3:
    // 0x80385A20: addiu       $t6, $s0, -0xC8
    ctx->r14 = ADD32(ctx->r16, -0XC8);
    // 0x80385A24: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80385A28: addiu       $t8, $v0, -0xC8
    ctx->r24 = ADD32(ctx->r2, -0XC8);
    // 0x80385A2C: addiu       $t7, $s1, -0x96
    ctx->r15 = ADD32(ctx->r17, -0X96);
    // 0x80385A30: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80385A34: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80385A38: lwc1        $f12, 0x94($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80385A3C: lwc1        $f14, 0x98($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80385A40: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80385A44: lw          $a2, 0x9C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X9C);
    // 0x80385A48: addiu       $t7, $zero, 0x15
    ctx->r15 = ADD32(0, 0X15);
    // 0x80385A4C: addiu       $t6, $zero, -0xE
    ctx->r14 = ADD32(0, -0XE);
    // 0x80385A50: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80385A54: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80385A58: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80385A5C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80385A60: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x80385A64: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80385A68: addiu       $t4, $zero, 0x76
    ctx->r12 = ADD32(0, 0X76);
    // 0x80385A6C: addiu       $t5, $zero, 0xDC
    ctx->r13 = ADD32(0, 0XDC);
    // 0x80385A70: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80385A74: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80385A78: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80385A7C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80385A80: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80385A84: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80385A88: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80385A8C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80385A90: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80385A94: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80385A98: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80385A9C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80385AA0: div.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x80385AA4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80385AA8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80385AAC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80385AB0: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80385AB4: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x80385AB8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80385ABC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80385AC0: neg.d       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = -ctx->f18.d;
    // 0x80385AC4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80385AC8: jal         0x80129FB8
    // 0x80385ACC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_4;
    // 0x80385ACC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80385AD0: jal         0x8012C6B4
    // 0x80385AD4: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80385AD4: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_5:
    // 0x80385AD8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80385ADC: jal         0x8012C6B4
    // 0x80385AE0: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x80385AE0: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_6:
    // 0x80385AE4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80385AE8: jal         0x8012C6B4
    // 0x80385AEC: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x80385AEC: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_7:
    // 0x80385AF0: addiu       $t8, $s0, -0xC8
    ctx->r24 = ADD32(ctx->r16, -0XC8);
    // 0x80385AF4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80385AF8: addiu       $t0, $v0, -0xC8
    ctx->r8 = ADD32(ctx->r2, -0XC8);
    // 0x80385AFC: addiu       $t9, $s1, -0x96
    ctx->r25 = ADD32(ctx->r17, -0X96);
    // 0x80385B00: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80385B04: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80385B08: lwc1        $f12, 0x94($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80385B0C: lwc1        $f14, 0x98($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80385B10: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80385B14: lw          $a2, 0x9C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X9C);
    // 0x80385B18: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80385B1C: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x80385B20: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x80385B24: addiu       $t3, $zero, 0xDC
    ctx->r11 = ADD32(0, 0XDC);
    // 0x80385B28: addiu       $t4, $zero, -0xE
    ctx->r12 = ADD32(0, -0XE);
    // 0x80385B2C: addiu       $t5, $zero, 0x15
    ctx->r13 = ADD32(0, 0X15);
    // 0x80385B30: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80385B34: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80385B38: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80385B3C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80385B40: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80385B44: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80385B48: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80385B4C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80385B50: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80385B54: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80385B58: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80385B5C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80385B60: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80385B64: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80385B68: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80385B6C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80385B70: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80385B74: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x80385B78: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80385B7C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80385B80: neg.d       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = -ctx->f4.d;
    // 0x80385B84: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80385B88: jal         0x80129FB8
    // 0x80385B8C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_8;
    // 0x80385B8C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80385B90: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80385B94: bne         $s3, $s4, L_80385A00
    if (ctx->r19 != ctx->r20) {
        // 0x80385B98: nop
    
            goto L_80385A00;
    }
    // 0x80385B98: nop

L_80385B9C:
    // 0x80385B9C: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80385BA0: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80385BA4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80385BA8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80385BAC: jal         0x8012C6B4
    // 0x80385BB0: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_9;
    // 0x80385BB0: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_9:
    // 0x80385BB4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80385BB8: jal         0x8012C6B4
    // 0x80385BBC: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x80385BBC: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_10:
    // 0x80385BC0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80385BC4: jal         0x8012C6B4
    // 0x80385BC8: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x80385BC8: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_11:
    // 0x80385BCC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80385BD0: jal         0x8012C6B4
    // 0x80385BD4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x80385BD4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_12:
    // 0x80385BD8: addiu       $t6, $s3, -0x1F4
    ctx->r14 = ADD32(ctx->r19, -0X1F4);
    // 0x80385BDC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80385BE0: addiu       $t7, $s0, -0x1F4
    ctx->r15 = ADD32(ctx->r16, -0X1F4);
    // 0x80385BE4: lwc1        $f4, 0x94($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X94);
    // 0x80385BE8: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80385BEC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80385BF0: addiu       $t8, $s1, -0x1F4
    ctx->r24 = ADD32(ctx->r17, -0X1F4);
    // 0x80385BF4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385BF8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80385BFC: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x80385C00: addiu       $t6, $zero, -0x4
    ctx->r14 = ADD32(0, -0X4);
    // 0x80385C04: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80385C08: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80385C0C: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80385C10: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80385C14: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80385C18: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80385C1C: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x80385C20: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80385C24: addiu       $t4, $zero, 0x76
    ctx->r12 = ADD32(0, 0X76);
    // 0x80385C28: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x80385C2C: div.d       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x80385C30: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80385C34: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x80385C38: lwc1        $f18, 0x98($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X98);
    // 0x80385C3C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80385C40: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80385C44: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x80385C48: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80385C4C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80385C50: lwc1        $f4, 0x9C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X9C);
    // 0x80385C54: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80385C58: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80385C5C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80385C60: cvt.d.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.d = CVT_D_W(ctx->f16.u32l);
    // 0x80385C64: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80385C68: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80385C6C: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80385C70: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80385C74: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80385C78: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80385C7C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80385C80: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80385C84: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80385C88: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x80385C8C: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x80385C90: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x80385C94: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x80385C98: ldc1        $f18, -0x6368($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6368);
    // 0x80385C9C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385CA0: div.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f18.d);
    // 0x80385CA4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80385CA8: ldc1        $f8, -0x6360($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6360);
    // 0x80385CAC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80385CB0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80385CB4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80385CB8: jal         0x80129FB8
    // 0x80385CBC: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_13;
    // 0x80385CBC: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x80385CC0: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x80385CC4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80385CC8: bnel        $t7, $at, L_80385CDC
    if (ctx->r15 != ctx->r1) {
        // 0x80385CCC: lw          $ra, 0x84($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X84);
            goto L_80385CDC;
    }
    goto skip_0;
    // 0x80385CCC: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    skip_0:
    // 0x80385CD0: jal         0x80005700
    // 0x80385CD4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_14;
    // 0x80385CD4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x80385CD8: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
L_80385CDC:
    // 0x80385CDC: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80385CE0: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x80385CE4: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x80385CE8: ldc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X68);
    // 0x80385CEC: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80385CF0: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x80385CF4: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x80385CF8: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x80385CFC: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x80385D00: jr          $ra
    // 0x80385D04: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80385D04: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80385d08(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80385d08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385D08: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80385D0C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80385D10: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x80385D14: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x80385D18: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80385D1C: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80385D20: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80385D24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80385D28: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x80385D2C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80385D30: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80385D34: jal         0x8012C6B4
    // 0x80385D38: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80385D38: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_0:
    // 0x80385D3C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80385D40: jal         0x8012C6B4
    // 0x80385D44: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80385D44: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_1:
    // 0x80385D48: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80385D4C: jal         0x8012C6B4
    // 0x80385D50: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80385D50: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_2:
    // 0x80385D54: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80385D58: jal         0x8012C6B4
    // 0x80385D5C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x80385D5C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_3:
    // 0x80385D60: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80385D64: jal         0x8012C6B4
    // 0x80385D68: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80385D68: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_4:
    // 0x80385D6C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80385D70: jal         0x8012C6B4
    // 0x80385D74: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80385D74: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_5:
    // 0x80385D78: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x80385D7C: jal         0x8012C6B4
    // 0x80385D80: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x80385D80: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_6:
    // 0x80385D84: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80385D88: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80385D8C: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80385D90: addiu       $t8, $t7, -0x1F4
    ctx->r24 = ADD32(ctx->r15, -0X1F4);
    // 0x80385D94: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80385D98: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80385D9C: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80385DA0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80385DA4: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x80385DA8: addiu       $t0, $t9, -0x1F4
    ctx->r8 = ADD32(ctx->r25, -0X1F4);
    // 0x80385DAC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80385DB0: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80385DB4: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80385DB8: addiu       $t2, $t1, -0x1F4
    ctx->r10 = ADD32(ctx->r9, -0X1F4);
    // 0x80385DBC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385DC0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80385DC4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80385DC8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80385DCC: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80385DD0: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80385DD4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80385DD8: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80385DDC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80385DE0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80385DE4: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x80385DE8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80385DEC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80385DF0: addiu       $t1, $t0, 0x76
    ctx->r9 = ADD32(ctx->r8, 0X76);
    // 0x80385DF4: addiu       $t9, $t8, 0xD7
    ctx->r25 = ADD32(ctx->r24, 0XD7);
    // 0x80385DF8: addiu       $t7, $t6, 0x14
    ctx->r15 = ADD32(ctx->r14, 0X14);
    // 0x80385DFC: div.d       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80385E00: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80385E04: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80385E08: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80385E0C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80385E10: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x80385E14: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80385E18: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80385E1C: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80385E20: lwc1        $f10, 0x9C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80385E24: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80385E28: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80385E2C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80385E30: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80385E34: addiu       $t3, $zero, -0x4
    ctx->r11 = ADD32(0, -0X4);
    // 0x80385E38: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80385E3C: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80385E40: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x80385E44: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80385E48: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80385E4C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80385E50: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80385E54: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80385E58: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80385E5C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80385E60: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80385E64: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80385E68: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80385E6C: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80385E70: ldc1        $f8, -0x6358($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6358);
    // 0x80385E74: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385E78: div.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x80385E7C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80385E80: ldc1        $f18, -0x6350($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6350);
    // 0x80385E84: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80385E88: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80385E8C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80385E90: jal         0x80129FB8
    // 0x80385E94: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_7;
    // 0x80385E94: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x80385E98: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80385E9C: bgez        $t5, L_80385EB0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80385EA0: andi        $t6, $t5, 0x1
        ctx->r14 = ctx->r13 & 0X1;
            goto L_80385EB0;
    }
    // 0x80385EA0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80385EA4: beq         $t6, $zero, L_80385EB0
    if (ctx->r14 == 0) {
        // 0x80385EA8: nop
    
            goto L_80385EB0;
    }
    // 0x80385EA8: nop

    // 0x80385EAC: addiu       $t6, $t6, -0x2
    ctx->r14 = ADD32(ctx->r14, -0X2);
L_80385EB0:
    // 0x80385EB0: bnel        $t6, $zero, L_80385FF4
    if (ctx->r14 != 0) {
        // 0x80385EB4: lw          $t1, 0x8C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X8C);
            goto L_80385FF4;
    }
    goto skip_0;
    // 0x80385EB4: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    skip_0:
    // 0x80385EB8: jal         0x8012C6B4
    // 0x80385EBC: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x80385EBC: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_8:
    // 0x80385EC0: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80385EC4: jal         0x8012C6B4
    // 0x80385EC8: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_9;
    // 0x80385EC8: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_9:
    // 0x80385ECC: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80385ED0: jal         0x8012C6B4
    // 0x80385ED4: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x80385ED4: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_10:
    // 0x80385ED8: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80385EDC: jal         0x8012C6B4
    // 0x80385EE0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x80385EE0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_11:
    // 0x80385EE4: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80385EE8: jal         0x8012C6B4
    // 0x80385EEC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x80385EEC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_12:
    // 0x80385EF0: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x80385EF4: jal         0x8012C6B4
    // 0x80385EF8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_13;
    // 0x80385EF8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_13:
    // 0x80385EFC: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80385F00: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80385F04: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80385F08: addiu       $t8, $t7, -0x1F4
    ctx->r24 = ADD32(ctx->r15, -0X1F4);
    // 0x80385F0C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80385F10: addiu       $t0, $t9, -0x1F4
    ctx->r8 = ADD32(ctx->r25, -0X1F4);
    // 0x80385F14: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80385F18: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x80385F1C: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80385F20: addiu       $t2, $t1, -0x1F4
    ctx->r10 = ADD32(ctx->r9, -0X1F4);
    // 0x80385F24: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385F28: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80385F2C: div.d       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80385F30: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80385F34: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80385F38: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80385F3C: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x80385F40: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80385F44: addiu       $t9, $zero, -0x4
    ctx->r25 = ADD32(0, -0X4);
    // 0x80385F48: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x80385F4C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80385F50: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80385F54: addiu       $t6, $zero, 0x94
    ctx->r14 = ADD32(0, 0X94);
    // 0x80385F58: addiu       $t5, $t4, 0x8E
    ctx->r13 = ADD32(ctx->r12, 0X8E);
    // 0x80385F5C: div.d       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80385F60: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x80385F64: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x80385F68: lwc1        $f16, 0x98($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80385F6C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80385F70: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80385F74: div.d       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80385F78: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80385F7C: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80385F80: lwc1        $f18, 0x9C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80385F84: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80385F88: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80385F8C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80385F90: cvt.d.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.d = CVT_D_W(ctx->f8.u32l);
    // 0x80385F94: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80385F98: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80385F9C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80385FA0: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80385FA4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80385FA8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80385FAC: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80385FB0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80385FB4: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80385FB8: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80385FBC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80385FC0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80385FC4: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x80385FC8: ldc1        $f16, -0x6348($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X6348);
    // 0x80385FCC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385FD0: div.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f16.d);
    // 0x80385FD4: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80385FD8: ldc1        $f6, -0x6340($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6340);
    // 0x80385FDC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80385FE0: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x80385FE4: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80385FE8: jal         0x80129FB8
    // 0x80385FEC: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_14;
    // 0x80385FEC: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x80385FF0: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
L_80385FF4:
    // 0x80385FF4: addiu       $t3, $zero, 0x15
    ctx->r11 = ADD32(0, 0X15);
    // 0x80385FF8: bgez        $t1, L_8038600C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80385FFC: andi        $t2, $t1, 0x3
        ctx->r10 = ctx->r9 & 0X3;
            goto L_8038600C;
    }
    // 0x80385FFC: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x80386000: beq         $t2, $zero, L_8038600C
    if (ctx->r10 == 0) {
        // 0x80386004: nop
    
            goto L_8038600C;
    }
    // 0x80386004: nop

    // 0x80386008: addiu       $t2, $t2, -0x4
    ctx->r10 = ADD32(ctx->r10, -0X4);
L_8038600C:
    // 0x8038600C: bnel        $t2, $zero, L_80386038
    if (ctx->r10 != 0) {
        // 0x80386010: lw          $t4, 0x8C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X8C);
            goto L_80386038;
    }
    goto skip_1;
    // 0x80386010: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    skip_1:
    // 0x80386014: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80386018: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8038601C: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x80386020: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80386024: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80386028: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8038602C: jal         0x80380F94
    // 0x80386030: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_15;
    // 0x80386030: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_15:
    // 0x80386034: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
L_80386038:
    // 0x80386038: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x8038603C: bnel        $t4, $zero, L_80386068
    if (ctx->r12 != 0) {
        // 0x80386040: lw          $t6, 0x8C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X8C);
            goto L_80386068;
    }
    goto skip_2;
    // 0x80386040: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    skip_2:
    // 0x80386044: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80386048: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8038604C: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x80386050: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80386054: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80386058: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8038605C: jal         0x80380F94
    // 0x80386060: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_16;
    // 0x80386060: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_16:
    // 0x80386064: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
L_80386068:
    // 0x80386068: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8038606C: bnel        $t6, $at, L_80386080
    if (ctx->r14 != ctx->r1) {
        // 0x80386070: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80386080;
    }
    goto skip_3;
    // 0x80386070: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_3:
    // 0x80386074: jal         0x80005700
    // 0x80386078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_17;
    // 0x80386078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8038607C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80386080:
    // 0x80386080: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80386084: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x80386088: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8038608C: jr          $ra
    // 0x80386090: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80386090: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80386094(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80386094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386094: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80386098: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8038609C: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x803860A0: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x803860A4: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x803860A8: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x803860AC: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x803860B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803860B4: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x803860B8: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x803860BC: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x803860C0: jal         0x8012C6B4
    // 0x803860C4: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x803860C4: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_0:
    // 0x803860C8: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x803860CC: jal         0x8012C6B4
    // 0x803860D0: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x803860D0: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_1:
    // 0x803860D4: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x803860D8: jal         0x8012C6B4
    // 0x803860DC: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x803860DC: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_2:
    // 0x803860E0: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x803860E4: jal         0x8012C6B4
    // 0x803860E8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x803860E8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_3:
    // 0x803860EC: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x803860F0: jal         0x8012C6B4
    // 0x803860F4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x803860F4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_4:
    // 0x803860F8: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x803860FC: jal         0x8012C6B4
    // 0x80386100: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80386100: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_5:
    // 0x80386104: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x80386108: jal         0x8012C6B4
    // 0x8038610C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x8038610C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_6:
    // 0x80386110: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80386114: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80386118: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8038611C: addiu       $t8, $t7, -0x2BC
    ctx->r24 = ADD32(ctx->r15, -0X2BC);
    // 0x80386120: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80386124: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80386128: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8038612C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80386130: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x80386134: addiu       $t0, $t9, -0x2BC
    ctx->r8 = ADD32(ctx->r25, -0X2BC);
    // 0x80386138: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8038613C: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80386140: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80386144: addiu       $t2, $t1, -0x2BC
    ctx->r10 = ADD32(ctx->r9, -0X2BC);
    // 0x80386148: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038614C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80386150: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80386154: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80386158: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8038615C: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80386160: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80386164: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80386168: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8038616C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80386170: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x80386174: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80386178: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8038617C: addiu       $t1, $t0, 0x76
    ctx->r9 = ADD32(ctx->r8, 0X76);
    // 0x80386180: addiu       $t9, $t8, 0xD7
    ctx->r25 = ADD32(ctx->r24, 0XD7);
    // 0x80386184: addiu       $t7, $t6, 0x14
    ctx->r15 = ADD32(ctx->r14, 0X14);
    // 0x80386188: div.d       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x8038618C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80386190: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x80386194: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80386198: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8038619C: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x803861A0: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x803861A4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x803861A8: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x803861AC: lwc1        $f10, 0x9C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x803861B0: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x803861B4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x803861B8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x803861BC: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x803861C0: addiu       $t3, $zero, -0x4
    ctx->r11 = ADD32(0, -0X4);
    // 0x803861C4: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x803861C8: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x803861CC: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x803861D0: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x803861D4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x803861D8: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x803861DC: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x803861E0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x803861E4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x803861E8: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x803861EC: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x803861F0: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x803861F4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x803861F8: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x803861FC: ldc1        $f8, -0x6338($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6338);
    // 0x80386200: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386204: div.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x80386208: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8038620C: ldc1        $f18, -0x6330($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6330);
    // 0x80386210: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80386214: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80386218: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8038621C: jal         0x80129FB8
    // 0x80386220: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_7;
    // 0x80386220: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x80386224: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80386228: bgez        $t5, L_8038623C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8038622C: andi        $t6, $t5, 0x1
        ctx->r14 = ctx->r13 & 0X1;
            goto L_8038623C;
    }
    // 0x8038622C: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80386230: beq         $t6, $zero, L_8038623C
    if (ctx->r14 == 0) {
        // 0x80386234: nop
    
            goto L_8038623C;
    }
    // 0x80386234: nop

    // 0x80386238: addiu       $t6, $t6, -0x2
    ctx->r14 = ADD32(ctx->r14, -0X2);
L_8038623C:
    // 0x8038623C: bnel        $t6, $zero, L_80386380
    if (ctx->r14 != 0) {
        // 0x80386240: lw          $t1, 0x8C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X8C);
            goto L_80386380;
    }
    goto skip_0;
    // 0x80386240: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    skip_0:
    // 0x80386244: jal         0x8012C6B4
    // 0x80386248: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x80386248: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_8:
    // 0x8038624C: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80386250: jal         0x8012C6B4
    // 0x80386254: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_9;
    // 0x80386254: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_9:
    // 0x80386258: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8038625C: jal         0x8012C6B4
    // 0x80386260: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x80386260: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_10:
    // 0x80386264: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80386268: jal         0x8012C6B4
    // 0x8038626C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x8038626C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_11:
    // 0x80386270: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80386274: jal         0x8012C6B4
    // 0x80386278: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x80386278: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_12:
    // 0x8038627C: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x80386280: jal         0x8012C6B4
    // 0x80386284: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_13;
    // 0x80386284: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_13:
    // 0x80386288: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8038628C: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80386290: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80386294: addiu       $t8, $t7, -0x2BC
    ctx->r24 = ADD32(ctx->r15, -0X2BC);
    // 0x80386298: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8038629C: addiu       $t0, $t9, -0x2BC
    ctx->r8 = ADD32(ctx->r25, -0X2BC);
    // 0x803862A0: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x803862A4: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x803862A8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x803862AC: addiu       $t2, $t1, -0x2BC
    ctx->r10 = ADD32(ctx->r9, -0X2BC);
    // 0x803862B0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803862B4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x803862B8: div.d       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x803862BC: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x803862C0: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x803862C4: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x803862C8: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x803862CC: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x803862D0: addiu       $t9, $zero, -0x4
    ctx->r25 = ADD32(0, -0X4);
    // 0x803862D4: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x803862D8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x803862DC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x803862E0: addiu       $t6, $zero, 0x94
    ctx->r14 = ADD32(0, 0X94);
    // 0x803862E4: addiu       $t5, $t4, 0x8E
    ctx->r13 = ADD32(ctx->r12, 0X8E);
    // 0x803862E8: div.d       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x803862EC: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x803862F0: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x803862F4: lwc1        $f16, 0x98($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X98);
    // 0x803862F8: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x803862FC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80386300: div.d       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80386304: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80386308: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x8038630C: lwc1        $f18, 0x9C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80386310: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80386314: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80386318: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8038631C: cvt.d.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.d = CVT_D_W(ctx->f8.u32l);
    // 0x80386320: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80386324: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80386328: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8038632C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80386330: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80386334: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80386338: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8038633C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80386340: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80386344: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80386348: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8038634C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80386350: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x80386354: ldc1        $f16, -0x6328($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X6328);
    // 0x80386358: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038635C: div.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f16.d);
    // 0x80386360: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80386364: ldc1        $f6, -0x6320($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6320);
    // 0x80386368: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8038636C: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x80386370: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80386374: jal         0x80129FB8
    // 0x80386378: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_14;
    // 0x80386378: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x8038637C: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
L_80386380:
    // 0x80386380: addiu       $t3, $zero, 0x15
    ctx->r11 = ADD32(0, 0X15);
    // 0x80386384: bgez        $t1, L_80386398
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80386388: andi        $t2, $t1, 0x3
        ctx->r10 = ctx->r9 & 0X3;
            goto L_80386398;
    }
    // 0x80386388: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x8038638C: beq         $t2, $zero, L_80386398
    if (ctx->r10 == 0) {
        // 0x80386390: nop
    
            goto L_80386398;
    }
    // 0x80386390: nop

    // 0x80386394: addiu       $t2, $t2, -0x4
    ctx->r10 = ADD32(ctx->r10, -0X4);
L_80386398:
    // 0x80386398: bnel        $t2, $zero, L_803863C4
    if (ctx->r10 != 0) {
        // 0x8038639C: lw          $t4, 0x8C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X8C);
            goto L_803863C4;
    }
    goto skip_1;
    // 0x8038639C: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    skip_1:
    // 0x803863A0: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x803863A4: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    // 0x803863A8: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x803863AC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x803863B0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x803863B4: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x803863B8: jal         0x80380F94
    // 0x803863BC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_15;
    // 0x803863BC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_15:
    // 0x803863C0: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
L_803863C4:
    // 0x803863C4: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x803863C8: bnel        $t4, $zero, L_803863F4
    if (ctx->r12 != 0) {
        // 0x803863CC: lw          $t6, 0x8C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X8C);
            goto L_803863F4;
    }
    goto skip_2;
    // 0x803863CC: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    skip_2:
    // 0x803863D0: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x803863D4: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    // 0x803863D8: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x803863DC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x803863E0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x803863E4: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x803863E8: jal         0x80380F94
    // 0x803863EC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_16;
    // 0x803863EC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_16:
    // 0x803863F0: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
L_803863F4:
    // 0x803863F4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x803863F8: bnel        $t6, $at, L_8038640C
    if (ctx->r14 != ctx->r1) {
        // 0x803863FC: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_8038640C;
    }
    goto skip_3;
    // 0x803863FC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_3:
    // 0x80386400: jal         0x80005700
    // 0x80386404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_17;
    // 0x80386404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80386408: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8038640C:
    // 0x8038640C: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80386410: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x80386414: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x80386418: jr          $ra
    // 0x8038641C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8038641C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80386420(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80386420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80386424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80386428: lhu         $a2, 0x3C($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X3C);
    // 0x8038642C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386430: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x80386434: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80386438: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8038643C: ldc1        $f8, -0x6318($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6318);
    // 0x80386440: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80386444: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80386448: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8038644C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80386450: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80386454: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80386458: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x8038645C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80386460: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80386464: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80386468: beq         $at, $zero, L_80386488
    if (ctx->r1 == 0) {
        // 0x8038646C: swc1        $f18, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
            goto L_80386488;
    }
    // 0x8038646C: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x80386470: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80386474: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80386478: lbu         $t0, 0x4B($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X4B);
    // 0x8038647C: addiu       $t1, $t0, 0x3C
    ctx->r9 = ADD32(ctx->r8, 0X3C);
    // 0x80386480: b           L_803864C8
    // 0x80386484: sb          $t1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r9;
        goto L_803864C8;
    // 0x80386484: sb          $t1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r9;
L_80386488:
    // 0x80386488: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x8038648C: bnel        $at, $zero, L_803864CC
    if (ctx->r1 != 0) {
        // 0x80386490: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803864CC;
    }
    goto skip_0;
    // 0x80386490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80386494: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80386498: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x8038649C: lbu         $t3, 0x4B($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4B);
    // 0x803864A0: addiu       $t4, $t3, -0x20
    ctx->r12 = ADD32(ctx->r11, -0X20);
    // 0x803864A4: sb          $t4, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r12;
    // 0x803864A8: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x803864AC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x803864B0: lbu         $t7, 0x4B($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4B);
    // 0x803864B4: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x803864B8: beql        $at, $zero, L_803864CC
    if (ctx->r1 == 0) {
        // 0x803864BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803864CC;
    }
    goto skip_1;
    // 0x803864BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x803864C0: jal         0x80005700
    // 0x803864C4: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x803864C4: nop

    after_0:
L_803864C8:
    // 0x803864C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803864CC:
    // 0x803864CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803864D0: jr          $ra
    // 0x803864D4: nop

    return;
    // 0x803864D4: nop

;}
RECOMP_FUNC void M55_FUN_803864d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803864D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803864DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803864E0: lhu         $a2, 0x3C($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X3C);
    // 0x803864E4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803864E8: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x803864EC: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x803864F0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x803864F4: ldc1        $f8, -0x6310($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6310);
    // 0x803864F8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803864FC: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80386500: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80386504: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80386508: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8038650C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80386510: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x80386514: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80386518: ldc1        $f6, -0x6308($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6308);
    // 0x8038651C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80386520: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80386524: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80386528: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8038652C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80386530: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80386534: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
    // 0x80386538: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8038653C: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80386540: lh          $t0, 0x10($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X10);
    // 0x80386544: addiu       $t3, $t0, 0x155
    ctx->r11 = ADD32(ctx->r8, 0X155);
    // 0x80386548: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x8038654C: sh          $t4, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r12;
    // 0x80386550: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80386554: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x80386558: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x8038655C: addiu       $t9, $t6, 0x155
    ctx->r25 = ADD32(ctx->r14, 0X155);
    // 0x80386560: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x80386564: beq         $at, $zero, L_80386584
    if (ctx->r1 == 0) {
        // 0x80386568: sh          $t0, 0x14($v0)
        MEM_H(0X14, ctx->r2) = ctx->r8;
            goto L_80386584;
    }
    // 0x80386568: sh          $t0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r8;
    // 0x8038656C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80386570: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80386574: lbu         $t2, 0x4B($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4B);
    // 0x80386578: addiu       $t3, $t2, 0x32
    ctx->r11 = ADD32(ctx->r10, 0X32);
    // 0x8038657C: b           L_803865C4
    // 0x80386580: sb          $t3, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r11;
        goto L_803865C4;
    // 0x80386580: sb          $t3, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r11;
L_80386584:
    // 0x80386584: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x80386588: bnel        $at, $zero, L_803865C8
    if (ctx->r1 != 0) {
        // 0x8038658C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803865C8;
    }
    goto skip_0;
    // 0x8038658C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80386590: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80386594: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x80386598: lbu         $t5, 0x4B($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4B);
    // 0x8038659C: addiu       $t6, $t5, -0x18
    ctx->r14 = ADD32(ctx->r13, -0X18);
    // 0x803865A0: sb          $t6, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r14;
    // 0x803865A4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x803865A8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x803865AC: lbu         $t9, 0x4B($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4B);
    // 0x803865B0: slti        $at, $t9, 0x18
    ctx->r1 = SIGNED(ctx->r25) < 0X18 ? 1 : 0;
    // 0x803865B4: beql        $at, $zero, L_803865C8
    if (ctx->r1 == 0) {
        // 0x803865B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803865C8;
    }
    goto skip_1;
    // 0x803865B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x803865BC: jal         0x80005700
    // 0x803865C0: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x803865C0: nop

    after_0:
L_803865C4:
    // 0x803865C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803865C8:
    // 0x803865C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803865CC: jr          $ra
    // 0x803865D0: nop

    return;
    // 0x803865D0: nop

;}
RECOMP_FUNC void M55_FUN_803865d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803865D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803865D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803865DC: lhu         $a2, 0x3C($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X3C);
    // 0x803865E0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803865E4: ldc1        $f0, -0x6300($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X6300);
    // 0x803865E8: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x803865EC: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x803865F0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x803865F4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x803865F8: subu        $t3, $t2, $a2
    ctx->r11 = SUB32(ctx->r10, ctx->r6);
    // 0x803865FC: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80386600: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80386604: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80386608: add.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d + ctx->f0.d;
    // 0x8038660C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80386610: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x80386614: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80386618: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x8038661C: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80386620: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80386624: add.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f18.d + ctx->f0.d;
    // 0x80386628: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8038662C: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x80386630: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80386634: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80386638: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8038663C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80386640: add.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d + ctx->f0.d;
    // 0x80386644: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80386648: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x8038664C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80386650: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80386654: lbu         $a3, 0x4B($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X4B);
    // 0x80386658: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x8038665C: beq         $at, $zero, L_8038666C
    if (ctx->r1 == 0) {
        // 0x80386660: addiu       $t1, $a3, -0x10
        ctx->r9 = ADD32(ctx->r7, -0X10);
            goto L_8038666C;
    }
    // 0x80386660: addiu       $t1, $a3, -0x10
    ctx->r9 = ADD32(ctx->r7, -0X10);
    // 0x80386664: b           L_80386670
    // 0x80386668: sb          $zero, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = 0;
        goto L_80386670;
    // 0x80386668: sb          $zero, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = 0;
L_8038666C:
    // 0x8038666C: sb          $t1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r9;
L_80386670:
    // 0x80386670: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80386674: beql        $at, $zero, L_803867D8
    if (ctx->r1 == 0) {
        // 0x80386678: slti        $at, $a2, 0x8
        ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
            goto L_803867D8;
    }
    goto skip_0;
    // 0x80386678: slti        $at, $a2, 0x8
    ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    skip_0:
    // 0x8038667C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80386680: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386684: ldc1        $f6, -0x62F8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X62F8);
    // 0x80386688: cvt.d.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.d = CVT_D_W(ctx->f4.u32l);
    // 0x8038668C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386690: ldc1        $f10, -0x62F0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X62F0);
    // 0x80386694: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80386698: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8038669C: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x803866A0: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x803866A4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x803866A8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x803866AC: nop

    // 0x803866B0: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x803866B4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x803866B8: nop

    // 0x803866BC: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x803866C0: beql        $t5, $zero, L_80386714
    if (ctx->r13 == 0) {
        // 0x803866C4: mfc1        $t5, $f18
        ctx->r13 = (int32_t)ctx->f18.u32l;
            goto L_80386714;
    }
    goto skip_1;
    // 0x803866C4: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x803866C8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x803866CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x803866D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x803866D4: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x803866D8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x803866DC: nop

    // 0x803866E0: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x803866E4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x803866E8: nop

    // 0x803866EC: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x803866F0: bne         $t5, $zero, L_80386708
    if (ctx->r13 != 0) {
        // 0x803866F4: nop
    
            goto L_80386708;
    }
    // 0x803866F4: nop

    // 0x803866F8: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x803866FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80386700: b           L_80386720
    // 0x80386704: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80386720;
    // 0x80386704: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80386708:
    // 0x80386708: b           L_80386720
    // 0x8038670C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80386720;
    // 0x8038670C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80386710: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
L_80386714:
    // 0x80386714: nop

    // 0x80386718: bltz        $t5, L_80386708
    if (SIGNED(ctx->r13) < 0) {
        // 0x8038671C: nop
    
            goto L_80386708;
    }
    // 0x8038671C: nop

L_80386720:
    // 0x80386720: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80386724: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386728: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8038672C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80386730: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80386734: sb          $t5, 0x49($t7)
    MEM_B(0X49, ctx->r15) = ctx->r13;
    // 0x80386738: ldc1        $f4, -0x62E8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X62E8);
    // 0x8038673C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80386740: mul.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x80386744: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80386748: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8038674C: nop

    // 0x80386750: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x80386754: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80386758: nop

    // 0x8038675C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80386760: beql        $t9, $zero, L_803867B4
    if (ctx->r25 == 0) {
        // 0x80386764: mfc1        $t9, $f8
        ctx->r25 = (int32_t)ctx->f8.u32l;
            goto L_803867B4;
    }
    goto skip_2;
    // 0x80386764: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x80386768: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8038676C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80386770: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80386774: sub.d       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f6.d - ctx->f8.d;
    // 0x80386778: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8038677C: nop

    // 0x80386780: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x80386784: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80386788: nop

    // 0x8038678C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80386790: bne         $t9, $zero, L_803867A8
    if (ctx->r25 != 0) {
        // 0x80386794: nop
    
            goto L_803867A8;
    }
    // 0x80386794: nop

    // 0x80386798: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8038679C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x803867A0: b           L_803867C0
    // 0x803867A4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_803867C0;
    // 0x803867A4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_803867A8:
    // 0x803867A8: b           L_803867C0
    // 0x803867AC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_803867C0;
    // 0x803867AC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x803867B0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
L_803867B4:
    // 0x803867B4: nop

    // 0x803867B8: bltz        $t9, L_803867A8
    if (SIGNED(ctx->r25) < 0) {
        // 0x803867BC: nop
    
            goto L_803867A8;
    }
    // 0x803867BC: nop

L_803867C0:
    // 0x803867C0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x803867C4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x803867C8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x803867CC: b           L_8038692C
    // 0x803867D0: sb          $t9, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = ctx->r25;
        goto L_8038692C;
    // 0x803867D0: sb          $t9, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = ctx->r25;
    // 0x803867D4: slti        $at, $a2, 0x8
    ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
L_803867D8:
    // 0x803867D8: beq         $at, $zero, L_8038692C
    if (ctx->r1 == 0) {
        // 0x803867DC: addiu       $t2, $zero, 0x8
        ctx->r10 = ADD32(0, 0X8);
            goto L_8038692C;
    }
    // 0x803867DC: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x803867E0: subu        $t3, $t2, $a2
    ctx->r11 = SUB32(ctx->r10, ctx->r6);
    // 0x803867E4: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x803867E8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803867EC: ldc1        $f16, -0x62E0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X62E0);
    // 0x803867F0: cvt.d.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.d = CVT_D_W(ctx->f10.u32l);
    // 0x803867F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x803867F8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x803867FC: mul.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x80386800: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80386804: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80386808: nop

    // 0x8038680C: cvt.w.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_D(ctx->f18.d);
    // 0x80386810: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80386814: nop

    // 0x80386818: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8038681C: beql        $t6, $zero, L_80386870
    if (ctx->r14 == 0) {
        // 0x80386820: mfc1        $t6, $f4
        ctx->r14 = (int32_t)ctx->f4.u32l;
            goto L_80386870;
    }
    goto skip_3;
    // 0x80386820: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    skip_3:
    // 0x80386824: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80386828: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8038682C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80386830: sub.d       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f18.d - ctx->f4.d;
    // 0x80386834: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80386838: nop

    // 0x8038683C: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x80386840: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80386844: nop

    // 0x80386848: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8038684C: bne         $t6, $zero, L_80386864
    if (ctx->r14 != 0) {
        // 0x80386850: nop
    
            goto L_80386864;
    }
    // 0x80386850: nop

    // 0x80386854: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80386858: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8038685C: b           L_8038687C
    // 0x80386860: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8038687C;
    // 0x80386860: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80386864:
    // 0x80386864: b           L_8038687C
    // 0x80386868: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8038687C;
    // 0x80386868: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8038686C: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
L_80386870:
    // 0x80386870: nop

    // 0x80386874: bltz        $t6, L_80386864
    if (SIGNED(ctx->r14) < 0) {
        // 0x80386878: nop
    
            goto L_80386864;
    }
    // 0x80386878: nop

L_8038687C:
    // 0x8038687C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80386880: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386884: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80386888: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x8038688C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80386890: sb          $t6, 0x48($t7)
    MEM_B(0X48, ctx->r15) = ctx->r14;
    // 0x80386894: ldc1        $f6, -0x62D8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X62D8);
    // 0x80386898: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8038689C: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x803868A0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x803868A4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x803868A8: nop

    // 0x803868AC: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x803868B0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x803868B4: nop

    // 0x803868B8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x803868BC: beql        $t0, $zero, L_80386910
    if (ctx->r8 == 0) {
        // 0x803868C0: mfc1        $t0, $f10
        ctx->r8 = (int32_t)ctx->f10.u32l;
            goto L_80386910;
    }
    goto skip_4;
    // 0x803868C0: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x803868C4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x803868C8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x803868CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x803868D0: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x803868D4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x803868D8: nop

    // 0x803868DC: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x803868E0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x803868E4: nop

    // 0x803868E8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x803868EC: bne         $t0, $zero, L_80386904
    if (ctx->r8 != 0) {
        // 0x803868F0: nop
    
            goto L_80386904;
    }
    // 0x803868F0: nop

    // 0x803868F4: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x803868F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x803868FC: b           L_8038691C
    // 0x80386900: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8038691C;
    // 0x80386900: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80386904:
    // 0x80386904: b           L_8038691C
    // 0x80386908: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8038691C;
    // 0x80386908: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8038690C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
L_80386910:
    // 0x80386910: nop

    // 0x80386914: bltz        $t0, L_80386904
    if (SIGNED(ctx->r8) < 0) {
        // 0x80386918: nop
    
            goto L_80386904;
    }
    // 0x80386918: nop

L_8038691C:
    // 0x8038691C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80386920: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80386924: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80386928: sb          $t0, 0x49($t1)
    MEM_B(0X49, ctx->r9) = ctx->r8;
L_8038692C:
    // 0x8038692C: lw          $t2, 0x30($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X30);
    // 0x80386930: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x80386934: bne         $t3, $zero, L_80386950
    if (ctx->r11 != 0) {
        // 0x80386938: nop
    
            goto L_80386950;
    }
    // 0x80386938: nop

    // 0x8038693C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80386940: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80386944: lbu         $t6, 0x4B($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X4B);
    // 0x80386948: bnel        $t6, $zero, L_8038695C
    if (ctx->r14 != 0) {
        // 0x8038694C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8038695C;
    }
    goto skip_5;
    // 0x8038694C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
L_80386950:
    // 0x80386950: jal         0x80005700
    // 0x80386954: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80386954: nop

    after_0:
    // 0x80386958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8038695C:
    // 0x8038695C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80386960: jr          $ra
    // 0x80386964: nop

    return;
    // 0x80386964: nop

;}
RECOMP_FUNC void M55_FUN_80386968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386968: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8038696C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80386970: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80386974: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80386978: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8038697C: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80386980: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80386984: addiu       $t8, $zero, 0x1A
    ctx->r24 = ADD32(0, 0X1A);
    // 0x80386988: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x8038698C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80386990: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80386994: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80386998: bnel        $t7, $zero, L_80386A6C
    if (ctx->r15 != 0) {
        // 0x8038699C: lw          $t8, 0x7C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X7C);
            goto L_80386A6C;
    }
    goto skip_0;
    // 0x8038699C: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    skip_0:
    // 0x803869A0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x803869A4: lwc1        $f12, 0x94($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X94);
    // 0x803869A8: lwc1        $f14, 0x98($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X98);
    // 0x803869AC: lw          $a2, 0x9C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X9C);
    // 0x803869B0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x803869B4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x803869B8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x803869BC: jal         0x80380F94
    // 0x803869C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_0;
    // 0x803869C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x803869C4: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x803869C8: lwc1        $f14, 0x98($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X98);
    // 0x803869CC: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x803869D0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x803869D4: addiu       $t9, $zero, 0x1B
    ctx->r25 = ADD32(0, 0X1B);
    // 0x803869D8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x803869DC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x803869E0: jal         0x80380F94
    // 0x803869E4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_1;
    // 0x803869E4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x803869E8: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
    // 0x803869EC: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x803869F0: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x803869F4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x803869F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x803869FC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386A00: lwc1        $f8, -0x62D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X62D0);
    // 0x80386A04: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80386A08: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80386A0C: addiu       $t1, $zero, 0xF3
    ctx->r9 = ADD32(0, 0XF3);
    // 0x80386A10: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x80386A14: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80386A18: addiu       $t4, $zero, 0x66
    ctx->r12 = ADD32(0, 0X66);
    // 0x80386A1C: addiu       $t5, $zero, 0xF0
    ctx->r13 = ADD32(0, 0XF0);
    // 0x80386A20: addiu       $t6, $zero, -0x4
    ctx->r14 = ADD32(0, -0X4);
    // 0x80386A24: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80386A28: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80386A2C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80386A30: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80386A34: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80386A38: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80386A3C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80386A40: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80386A44: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80386A48: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80386A4C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80386A50: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80386A54: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80386A58: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80386A5C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80386A60: jal         0x80129FB8
    // 0x80386A64: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_2;
    // 0x80386A64: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80386A68: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
L_80386A6C:
    // 0x80386A6C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80386A70: bgez        $t8, L_80386A84
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80386A74: andi        $t9, $t8, 0x1
        ctx->r25 = ctx->r24 & 0X1;
            goto L_80386A84;
    }
    // 0x80386A74: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80386A78: beq         $t9, $zero, L_80386A84
    if (ctx->r25 == 0) {
        // 0x80386A7C: nop
    
            goto L_80386A84;
    }
    // 0x80386A7C: nop

    // 0x80386A80: addiu       $t9, $t9, -0x2
    ctx->r25 = ADD32(ctx->r25, -0X2);
L_80386A84:
    // 0x80386A84: bnel        $t9, $zero, L_80386BE4
    if (ctx->r25 != 0) {
        // 0x80386A88: lw          $t5, 0x7C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X7C);
            goto L_80386BE4;
    }
    goto skip_1;
    // 0x80386A88: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    skip_1:
    // 0x80386A8C: jal         0x8012C6B4
    // 0x80386A90: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x80386A90: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_3:
    // 0x80386A94: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80386A98: jal         0x8012C6B4
    // 0x80386A9C: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80386A9C: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    after_4:
    // 0x80386AA0: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80386AA4: jal         0x8012C6B4
    // 0x80386AA8: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80386AA8: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_5:
    // 0x80386AAC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80386AB0: jal         0x8012C6B4
    // 0x80386AB4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x80386AB4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_6:
    // 0x80386AB8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80386ABC: jal         0x8012C6B4
    // 0x80386AC0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x80386AC0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_7:
    // 0x80386AC4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80386AC8: jal         0x8012C6B4
    // 0x80386ACC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x80386ACC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_8:
    // 0x80386AD0: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80386AD4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80386AD8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80386ADC: addiu       $t1, $t0, -0x320
    ctx->r9 = ADD32(ctx->r8, -0X320);
    // 0x80386AE0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80386AE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80386AE8: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80386AEC: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80386AF0: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80386AF4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80386AF8: lwc1        $f10, 0x98($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80386AFC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80386B00: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x80386B04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80386B08: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80386B0C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386B10: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80386B14: addiu       $t4, $t3, -0x320
    ctx->r12 = ADD32(ctx->r11, -0X320);
    // 0x80386B18: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80386B1C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80386B20: addiu       $t3, $zero, -0x4
    ctx->r11 = ADD32(0, -0X4);
    // 0x80386B24: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80386B28: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80386B2C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80386B30: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80386B34: addiu       $t1, $t0, 0x3C
    ctx->r9 = ADD32(ctx->r8, 0X3C);
    // 0x80386B38: addiu       $t7, $t6, 0xC8
    ctx->r15 = ADD32(ctx->r14, 0XC8);
    // 0x80386B3C: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x80386B40: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80386B44: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x80386B48: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80386B4C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80386B50: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80386B54: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x80386B58: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80386B5C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80386B60: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x80386B64: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x80386B68: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80386B6C: add.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f10.d + ctx->f18.d;
    // 0x80386B70: lwc1        $f10, 0x9C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80386B74: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80386B78: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80386B7C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80386B80: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80386B84: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80386B88: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80386B8C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80386B90: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    // 0x80386B94: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80386B98: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80386B9C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80386BA0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80386BA4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80386BA8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80386BAC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80386BB0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80386BB4: add.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d + ctx->f18.d;
    // 0x80386BB8: ldc1        $f8, -0x62C8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X62C8);
    // 0x80386BBC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386BC0: div.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x80386BC4: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80386BC8: ldc1        $f16, -0x62C0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X62C0);
    // 0x80386BCC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80386BD0: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x80386BD4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80386BD8: jal         0x80129FB8
    // 0x80386BDC: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_9;
    // 0x80386BDC: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x80386BE0: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
L_80386BE4:
    // 0x80386BE4: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x80386BE8: bnel        $at, $zero, L_80386BFC
    if (ctx->r1 != 0) {
        // 0x80386BEC: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_80386BFC;
    }
    goto skip_2;
    // 0x80386BEC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x80386BF0: jal         0x80005700
    // 0x80386BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_10;
    // 0x80386BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80386BF8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80386BFC:
    // 0x80386BFC: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80386C00: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80386C04: jr          $ra
    // 0x80386C08: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80386C08: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80386c0c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80386c0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386C0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80386C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80386C14: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x80386C18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80386C1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80386C20: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80386C24: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x80386C28: lh          $a0, 0xA0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0XA0);
    // 0x80386C2C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80386C30: jal         0x8001EB64
    // 0x80386C34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x80386C34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80386C38: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80386C3C: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x80386C40: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80386C44: subu        $v0, $t8, $t7
    ctx->r2 = SUB32(ctx->r24, ctx->r15);
    // 0x80386C48: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80386C4C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80386C50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80386C54: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80386C58: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80386C5C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80386C60: lwc1        $f18, 0x98($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X98);
    // 0x80386C64: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80386C68: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80386C6C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80386C70: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80386C74: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80386C78: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80386C7C: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x80386C80: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80386C84: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x80386C88: lh          $a0, 0xA0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0XA0);
    // 0x80386C8C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80386C90: jal         0x8001EAD0
    // 0x80386C94: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x80386C94: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80386C98: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80386C9C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80386CA0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80386CA4: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80386CA8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80386CAC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80386CB0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80386CB4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80386CB8: lwc1        $f6, 0x9C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X9C);
    // 0x80386CBC: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80386CC0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80386CC4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80386CC8: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x80386CCC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80386CD0: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80386CD4: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80386CD8: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    // 0x80386CDC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80386CE0: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80386CE4: beql        $at, $zero, L_80386D08
    if (ctx->r1 == 0) {
        // 0x80386CE8: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_80386D08;
    }
    goto skip_0;
    // 0x80386CE8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    skip_0:
    // 0x80386CEC: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80386CF0: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x80386CF4: lbu         $t5, 0x4B($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4B);
    // 0x80386CF8: addiu       $t6, $t5, 0x3C
    ctx->r14 = ADD32(ctx->r13, 0X3C);
    // 0x80386CFC: b           L_80386D44
    // 0x80386D00: sb          $t6, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r14;
        goto L_80386D44;
    // 0x80386D00: sb          $t6, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r14;
    // 0x80386D04: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
L_80386D08:
    // 0x80386D08: beql        $at, $zero, L_80386D48
    if (ctx->r1 == 0) {
        // 0x80386D0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80386D48;
    }
    goto skip_1;
    // 0x80386D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80386D10: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80386D14: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80386D18: lbu         $t7, 0x4B($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4B);
    // 0x80386D1C: addiu       $t9, $t7, -0x18
    ctx->r25 = ADD32(ctx->r15, -0X18);
    // 0x80386D20: sb          $t9, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r25;
    // 0x80386D24: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80386D28: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80386D2C: lbu         $t2, 0x4B($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X4B);
    // 0x80386D30: slti        $at, $t2, 0x18
    ctx->r1 = SIGNED(ctx->r10) < 0X18 ? 1 : 0;
    // 0x80386D34: beql        $at, $zero, L_80386D48
    if (ctx->r1 == 0) {
        // 0x80386D38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80386D48;
    }
    goto skip_2;
    // 0x80386D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80386D3C: jal         0x80005700
    // 0x80386D40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x80386D40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_80386D44:
    // 0x80386D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80386D48:
    // 0x80386D48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80386D4C: jr          $ra
    // 0x80386D50: nop

    return;
    // 0x80386D50: nop

;}
