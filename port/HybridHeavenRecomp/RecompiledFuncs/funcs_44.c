#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801c1e2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1E2C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C1E30: lw          $t6, -0x722C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X722C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1e34(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1e34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1E34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1E38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1E3C: beq         $t6, $zero, L_801C1E68
    if (ctx->r14 == 0) {
        // 0x801C1E40: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801C1E68;
    }
    // 0x801C1E40: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801C1E44: jal         0x801C1E94
    // 0x801C1E48: nop

    LOOKUP_FUNC(0x801C1E94)(rdram, ctx);
        goto after_0;
    // 0x801C1E48: nop

    after_0:
    // 0x801C1E4C: beq         $v0, $zero, L_801C1E5C
    if (ctx->r2 == 0) {
        // 0x801C1E50: nop
    
            goto L_801C1E5C;
    }
    // 0x801C1E50: nop

    // 0x801C1E54: b           L_801C1E68
    // 0x801C1E58: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801C1E68;
    // 0x801C1E58: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801C1E5C:
    // 0x801C1E5C: jal         0x801C1F4C
    // 0x801C1E60: nop

    LOOKUP_FUNC(0x801C1F4C)(rdram, ctx);
        goto after_1;
    // 0x801C1E60: nop

    after_1:
    // 0x801C1E64: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801C1E68:
    // 0x801C1E68: beq         $v1, $zero, L_801C1E80
    if (ctx->r3 == 0) {
        // 0x801C1E6C: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801C1E80;
    }
    // 0x801C1E6C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1E70: addiu       $v0, $v0, -0x7230
    ctx->r2 = ADD32(ctx->r2, -0X7230);
    // 0x801C1E74: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C1E78: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801C1E7C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_801C1E80:
    // 0x801C1E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1E84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1E88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801C1E8C: jr          $ra
    // 0x801C1E90: nop

    return;
    // 0x801C1E90: nop

;}
RECOMP_FUNC void M24_FUN_801c1e94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1E94: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C1E98: lw          $t6, -0x722C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X722C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1e9c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1e9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1EA4: beq         $t6, $zero, L_801C1F3C
    if (ctx->r14 == 0) {
        // 0x801C1EA8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C1F3C;
    }
    // 0x801C1EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C1EAC: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x801C1EB0: lhu         $t8, -0x6B8A($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X6B8A);
    // 0x801C1EB4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1EB8: addiu       $v0, $v0, -0x7224
    ctx->r2 = ADD32(ctx->r2, -0X7224);
    // 0x801C1EBC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C1EC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1EC4: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x801C1EC8: beq         $t9, $zero, L_801C1EF8
    if (ctx->r25 == 0) {
        // 0x801C1ECC: sw          $t7, -0x7228($at)
        MEM_W(-0X7228, ctx->r1) = ctx->r15;
            goto L_801C1EF8;
    }
    // 0x801C1ECC: sw          $t7, -0x7228($at)
    MEM_W(-0X7228, ctx->r1) = ctx->r15;
    // 0x801C1ED0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C1ED4: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C1ED8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801C1EDC: addiu       $a3, $a3, -0x30E0
    ctx->r7 = ADD32(ctx->r7, -0X30E0);
    // 0x801C1EE0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801C1EE4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801C1EE8: jal         0x8001B204
    // 0x801C1EEC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C1EEC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_0:
    // 0x801C1EF0: b           L_801C1F14
    // 0x801C1EF4: nop

        goto L_801C1F14;
    // 0x801C1EF4: nop

L_801C1EF8:
    // 0x801C1EF8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C1EFC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801C1F00: addiu       $a3, $a3, -0x30C4
    ctx->r7 = ADD32(ctx->r7, -0X30C4);
    // 0x801C1F04: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801C1F08: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801C1F0C: jal         0x8001B204
    // 0x801C1F10: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C1F10: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_1:
L_801C1F14:
    // 0x801C1F14: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1F18: lw          $v0, -0x7224($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7224);
    // 0x801C1F1C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x801C1F20: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801C1F24: beql        $v0, $zero, L_801C1F40
    if (ctx->r2 == 0) {
        // 0x801C1F28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C1F40;
    }
    goto skip_0;
    // 0x801C1F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801C1F2C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1F30: lw          $v0, -0x7228($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7228);
    // 0x801C1F34: b           L_801C1F3C
    // 0x801C1F38: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_801C1F3C;
    // 0x801C1F38: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_801C1F3C:
    // 0x801C1F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C1F40:
    // 0x801C1F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C1F44: jr          $ra
    // 0x801C1F48: nop

    return;
    // 0x801C1F48: nop

;}
RECOMP_FUNC void M24_FUN_801c1f4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C1F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C1F54: jal         0x801C0C08
    // 0x801C1F58: nop

    LOOKUP_FUNC(0x801C0C08)(rdram, ctx);
        goto after_0;
    // 0x801C1F58: nop

    after_0:
    // 0x801C1F5C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C1F60: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C1F64: lw          $t7, -0x721C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X721C);
    // 0x801C1F68: lw          $t6, -0x7220($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7220);
    // 0x801C1F6C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801C1F70: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801C1F74: subu        $a0, $v0, $t6
    ctx->r4 = SUB32(ctx->r2, ctx->r14);
    // 0x801C1F78: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x801C1F7C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x801C1F80: jal         0x80026F58
    // 0x801C1F84: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    LOOKUP_FUNC(0x80026F58)(rdram, ctx);
        goto after_1;
    // 0x801C1F84: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    after_1:
    // 0x801C1F88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801C1F8C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801C1F90: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801C1F94: jal         0x80026E58
    // 0x801C1F98: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    LOOKUP_FUNC(0x80026E58)(rdram, ctx);
        goto after_2;
    // 0x801C1F98: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_2:
    // 0x801C1F9C: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
    // 0x801C1FA0: bgtz        $a0, L_801C1FB8
    if (SIGNED(ctx->r4) > 0) {
        // 0x801C1FA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C1FB8;
    }
    // 0x801C1FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C1FA8: lui         $at, 0xBEB
    ctx->r1 = S32(0XBEB << 16);
    // 0x801C1FAC: ori         $at, $at, 0xC200
    ctx->r1 = ctx->r1 | 0XC200;
    // 0x801C1FB0: sltu        $a0, $v1, $at
    ctx->r4 = ctx->r3 < ctx->r1 ? 1 : 0;
    // 0x801C1FB4: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
L_801C1FB8:
    // 0x801C1FB8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801C1FBC: jr          $ra
    // 0x801C1FC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801C1FC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1fc4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1fc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1FC4: nop

    // 0x801C1FC8: nop

    // 0x801C1FCC: nop

;}
RECOMP_FUNC void M24_FUN_801c1fd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1FD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C1FD4: jr          $ra
    // 0x801C1FD8: sw          $zero, -0x1090($at)
    MEM_W(-0X1090, ctx->r1) = 0;
    return;
    // 0x801C1FD8: sw          $zero, -0x1090($at)
    MEM_W(-0X1090, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1fdc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1fdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1FDC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1FE0: jr          $ra
    // 0x801C1FE4: lw          $v0, -0x1090($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1090);
    return;
    // 0x801C1FE4: lw          $v0, -0x1090($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1090);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c1fe8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c1fe8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C1FE8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C1FEC: addiu       $v0, $v0, -0x1090
    ctx->r2 = ADD32(ctx->r2, -0X1090);
    // 0x801C1FF0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801C1FF4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801C1FF8: jr          $ra
    // 0x801C1FFC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x801C1FFC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c2000(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c2000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2000: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801C2004: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C2008: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801C200C: lw          $t7, -0x7210($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7210);
    // 0x801C2010: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x801C2014: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801C2018: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x801C201C: jr          $ra
    // 0x801C2020: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801C2020: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c2024(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c2024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2024: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801C2028: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C202C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801C2030: lw          $t7, -0x7210($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7210);
    // 0x801C2034: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x801C2038: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801C203C: lw          $t1, -0x1090($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1090);
    // 0x801C2040: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801C2044: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801C2048: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x801C204C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x801C2050: jr          $ra
    // 0x801C2054: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    return;
    // 0x801C2054: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c2058(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c2058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2058: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801C205C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C2060: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801C2064: lw          $t7, -0x7210($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7210);
    // 0x801C2068: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x801C206C: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801C2070: lw          $t1, -0x1090($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1090);
    // 0x801C2074: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801C2078: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801C207C: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x801C2080: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x801C2084: lw          $v0, 0x10($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X10);
    // 0x801C2088: jr          $ra
    // 0x801C208C: lw          $v1, 0x14($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X14);
    return;
    // 0x801C208C: lw          $v1, 0x14($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c2090(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c2090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2090: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801C2094: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C2098: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801C209C: lw          $t7, -0x7210($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7210);
    // 0x801C20A0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x801C20A4: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801C20A8: lw          $t1, -0x1090($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1090);
    // 0x801C20AC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801C20B0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801C20B4: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x801C20B8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x801C20BC: jr          $ra
    // 0x801C20C0: lw          $v0, 0x18($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X18);
    return;
    // 0x801C20C0: lw          $v0, 0x18($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c20c4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c20c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C20C4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801C20C8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C20CC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801C20D0: lw          $t7, -0x7210($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7210);
    // 0x801C20D4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x801C20D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C20DC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801C20E0: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x801C20E4: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C20E8: bne         $v0, $zero, L_801C20F8
    if (ctx->r2 != 0) {
            // 0x801C20EC: nop

    LOOKUP_FUNC(0x801C20F8)(rdram, ctx);
    return;
    }
    // 0x801C20EC: nop

    // 0x801C20F0: jr          $ra
    // 0x801C20F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801C20F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c20f8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c20f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C20F8: lw          $t0, -0x1090($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1090);
    // 0x801C20FC: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x801C2100: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x801C2104: addu        $v1, $v0, $t1
    ctx->r3 = ADD32(ctx->r2, ctx->r9);
    // 0x801C2108: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x801C210C: bne         $a0, $zero, L_801C211C
    if (ctx->r4 != 0) {
            // 0x801C2110: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    LOOKUP_FUNC(0x801C211C)(rdram, ctx);
    return;
    }
    // 0x801C2110: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x801C2114: jr          $ra
    // 0x801C2118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801C2118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c211c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c211c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C211C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801C2120: beql        $v0, $zero, L_801C2184
    if (ctx->r2 == 0) {
        // 0x801C2124: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C2184;
    }
    goto skip_0;
    // 0x801C2124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801C2128: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801C212C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801C2130: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801C2134: beq         $a2, $t4, L_801C2150
    if (ctx->r6 == ctx->r12) {
        // 0x801C2138: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801C2150;
    }
    // 0x801C2138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C213C: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
L_801C2140:
    // 0x801C2140: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801C2144: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801C2148: bnel        $a2, $t5, L_801C2140
    if (ctx->r6 != ctx->r13) {
        // 0x801C214C: lw          $t5, 0x4($a0)
        ctx->r13 = MEM_W(ctx->r4, 0X4);
            goto L_801C2140;
    }
    goto skip_1;
    // 0x801C214C: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    skip_1:
L_801C2150:
    // 0x801C2150: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x801C2154: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x801C2158: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x801C215C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801C2160: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x801C2164: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801C2168: bnel        $t6, $t9, L_801C2184
    if (ctx->r14 != ctx->r25) {
        // 0x801C216C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C2184;
    }
    goto skip_2;
    // 0x801C216C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x801C2170: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x801C2174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C2178: jr          $ra
    // 0x801C217C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    return;
    // 0x801C217C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x801C2180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C2184:
    // 0x801C2184: jr          $ra
    // 0x801C2188: nop

    return;
    // 0x801C2188: nop

;}
RECOMP_FUNC void M24_FUN_801c218c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C218C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801C2190: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C2194: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x801C2198: addiu       $t7, $t7, -0x7210
    ctx->r15 = ADD32(ctx->r15, -0X7210);
    // 0x801C219C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801C21A0: addu        $s7, $t6, $t7
    ctx->r23 = ADD32(ctx->r14, ctx->r15);
    // 0x801C21A4: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x801C21A8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x801C21AC: sll         $fp, $a1, 2
    ctx->r30 = S32(ctx->r5 << 2);
    // 0x801C21B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801C21B4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801C21B8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801C21BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801C21C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801C21C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801C21C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801C21CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C21D0: addu        $t9, $t8, $fp
    ctx->r25 = ADD32(ctx->r24, ctx->r30);
    // 0x801C21D4: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x801C21D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C21DC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801C21E0: bne         $v0, $zero, L_801C21F0
    if (ctx->r2 != 0) {
        // 0x801C21E4: lui         $v1, 0x801E
        ctx->r3 = S32(0X801E << 16);
            goto L_801C21F0;
    }
    // 0x801C21E4: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C21E8: b           L_801C230C
    // 0x801C21EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C230C;
    // 0x801C21EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C21F0:
    // 0x801C21F0: addiu       $v1, $v1, -0x1090
    ctx->r3 = ADD32(ctx->r3, -0X1090);
    // 0x801C21F4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801C21F8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x801C21FC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x801C2200: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x801C2204: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x801C2208: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801C220C: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x801C2210: bne         $t3, $zero, L_801C2220
    if (ctx->r11 != 0) {
        // 0x801C2214: nop
    
            goto L_801C2220;
    }
    // 0x801C2214: nop

    // 0x801C2218: b           L_801C230C
    // 0x801C221C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C230C;
    // 0x801C221C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C2220:
    // 0x801C2220: lw          $t4, 0x0($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X0);
    // 0x801C2224: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801C2228: addu        $t5, $t4, $fp
    ctx->r13 = ADD32(ctx->r12, ctx->r30);
    // 0x801C222C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801C2230: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x801C2234: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x801C2238: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801C223C: lw          $s0, 0x18($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X18);
    // 0x801C2240: addu        $t0, $t9, $s6
    ctx->r8 = ADD32(ctx->r25, ctx->r22);
    // 0x801C2244: lw          $s3, 0x0($t0)
    ctx->r19 = MEM_W(ctx->r8, 0X0);
    // 0x801C2248: beql        $s3, $zero, L_801C22C4
    if (ctx->r19 == 0) {
        // 0x801C224C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_801C22C4;
    }
    goto skip_0;
    // 0x801C224C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_0:
    // 0x801C2250: jal         0x801BF974
    // 0x801C2254: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(0x801BF974)(rdram, ctx);
        goto after_0;
    // 0x801C2254: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x801C2258: and         $t1, $v0, $s0
    ctx->r9 = ctx->r2 & ctx->r16;
    // 0x801C225C: beq         $t1, $zero, L_801C226C
    if (ctx->r9 == 0) {
        // 0x801C2260: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C226C;
    }
    // 0x801C2260: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C2264: b           L_801C226C
    // 0x801C2268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C226C;
    // 0x801C2268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C226C:
    // 0x801C226C: beql        $v0, $zero, L_801C22C4
    if (ctx->r2 == 0) {
        // 0x801C2270: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_801C22C4;
    }
    goto skip_1;
    // 0x801C2270: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_1:
    // 0x801C2274: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x801C2278: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C227C: beq         $s5, $t2, L_801C22C0
    if (ctx->r21 == ctx->r10) {
        // 0x801C2280: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_801C22C0;
    }
    // 0x801C2280: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_801C2284:
    // 0x801C2284: jal         0x801C1780
    // 0x801C2288: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801C1780)(rdram, ctx);
        goto after_1;
    // 0x801C2288: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x801C228C: and         $s1, $s1, $v0
    ctx->r17 = ctx->r17 & ctx->r2;
    // 0x801C2290: beq         $s1, $zero, L_801C22A4
    if (ctx->r17 == 0) {
        // 0x801C2294: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_801C22A4;
    }
    // 0x801C2294: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C2298: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x801C229C: b           L_801C22AC
    // 0x801C22A0: addu        $v0, $s3, $t3
    ctx->r2 = ADD32(ctx->r19, ctx->r11);
        goto L_801C22AC;
    // 0x801C22A0: addu        $v0, $s3, $t3
    ctx->r2 = ADD32(ctx->r19, ctx->r11);
L_801C22A4:
    // 0x801C22A4: b           L_801C230C
    // 0x801C22A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C230C;
    // 0x801C22A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C22AC:
    // 0x801C22AC: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x801C22B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C22B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801C22B8: bnel        $s5, $t4, L_801C2284
    if (ctx->r21 != ctx->r12) {
        // 0x801C22BC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_801C2284;
    }
    goto skip_2;
    // 0x801C22BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_2:
L_801C22C0:
    // 0x801C22C0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_801C22C4:
    // 0x801C22C4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801C22C8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C22CC: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x801C22D0: bne         $s4, $at, L_801C2220
    if (ctx->r20 != ctx->r1) {
        // 0x801C22D4: addiu       $v1, $v1, -0x1090
        ctx->r3 = ADD32(ctx->r3, -0X1090);
            goto L_801C2220;
    }
    // 0x801C22D4: addiu       $v1, $v1, -0x1090
    ctx->r3 = ADD32(ctx->r3, -0X1090);
    // 0x801C22D8: beq         $s1, $zero, L_801C230C
    if (ctx->r17 == 0) {
        // 0x801C22DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C230C;
    }
    // 0x801C22DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C22E0: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x801C22E4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801C22E8: addu        $t7, $t5, $fp
    ctx->r15 = ADD32(ctx->r13, ctx->r30);
    // 0x801C22EC: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x801C22F0: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x801C22F4: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x801C22F8: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801C22FC: bne         $s2, $t1, L_801C230C
    if (ctx->r18 != ctx->r9) {
        // 0x801C2300: nop
    
            goto L_801C230C;
    }
    // 0x801C2300: nop

    // 0x801C2304: b           L_801C230C
    // 0x801C2308: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C230C;
    // 0x801C2308: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C230C:
    // 0x801C230C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801C2310: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C2314: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2318: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801C231C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801C2320: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801C2324: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801C2328: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801C232C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x801C2330: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x801C2334: jr          $ra
    // 0x801C2338: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801C2338: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c233c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c233c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C233C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C2340: addiu       $t7, $t7, -0x7210
    ctx->r15 = ADD32(ctx->r15, -0X7210);
    // 0x801C2344: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801C2348: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801C234C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C2350: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801C2354: addiu       $t3, $t3, -0x1090
    ctx->r11 = ADD32(ctx->r11, -0X1090);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c2358(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c2358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2358: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x801C235C: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x801C2360: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x801C2364: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x801C2368: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x801C236C: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x801C2370: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x801C2374: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801C2378: addu        $a3, $t5, $t7
    ctx->r7 = ADD32(ctx->r13, ctx->r15);
    // 0x801C237C: lw          $t8, 0x4($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X4);
    // 0x801C2380: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x801C2384: beql        $t2, $t8, L_801C2414
    if (ctx->r10 == ctx->r24) {
        // 0x801C2388: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_801C2414;
    }
    goto skip_0;
    // 0x801C2388: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_0:
    // 0x801C238C: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x801C2390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C2394: addiu       $t4, $zero, 0x24
    ctx->r12 = ADD32(0, 0X24);
    // 0x801C2398: beql        $t9, $zero, L_801C2414
    if (ctx->r25 == 0) {
        // 0x801C239C: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_801C2414;
    }
    goto skip_1;
    // 0x801C239C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_1:
    // 0x801C23A0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_801C23A4:
    // 0x801C23A4: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x801C23A8: addu        $t5, $t6, $v1
    ctx->r13 = ADD32(ctx->r14, ctx->r3);
    // 0x801C23AC: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801C23B0: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x801C23B4: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x801C23B8: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x801C23BC: addu        $t8, $t5, $a1
    ctx->r24 = ADD32(ctx->r13, ctx->r5);
    // 0x801C23C0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x801C23C4: beql        $a0, $zero, L_801C2408
    if (ctx->r4 == 0) {
        // 0x801C23C8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_801C2408;
    }
    goto skip_2;
    // 0x801C23C8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    skip_2:
    // 0x801C23CC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x801C23D0: addu        $a2, $s0, $a1
    ctx->r6 = ADD32(ctx->r16, ctx->r5);
    // 0x801C23D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C23D8: beq         $t2, $t7, L_801C2404
    if (ctx->r10 == ctx->r15) {
        // 0x801C23DC: or          $t0, $a0, $zero
        ctx->r8 = ctx->r4 | 0;
            goto L_801C2404;
    }
    // 0x801C23DC: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x801C23E0: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x801C23E4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
L_801C23E8:
    // 0x801C23E8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x801C23EC: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x801C23F0: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x801C23F4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801C23F8: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x801C23FC: bnel        $t2, $t1, L_801C23E8
    if (ctx->r10 != ctx->r9) {
        // 0x801C2400: lw          $t9, 0x0($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X0);
            goto L_801C23E8;
    }
    goto skip_3;
    // 0x801C2400: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    skip_3:
L_801C2404:
    // 0x801C2404: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_801C2408:
    // 0x801C2408: bnel        $a1, $t4, L_801C23A4
    if (ctx->r5 != ctx->r12) {
        // 0x801C240C: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_801C23A4;
    }
    goto skip_4;
    // 0x801C240C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_4:
    // 0x801C2410: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_801C2414:
    // 0x801C2414: jr          $ra
    // 0x801C2418: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x801C2418: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c241c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c241c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C241C: nop

;}
RECOMP_FUNC void M24_FUN_801c2420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2420: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801C2424: addiu       $t7, $t7, 0x1CF0
    ctx->r15 = ADD32(ctx->r15, 0X1CF0);
    // 0x801C2428: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c242c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c242c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C242C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C2430: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801C2434: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x801C2438: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C243C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C2440: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C2444: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801C2448: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x801C244C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801C2450: lhu         $s0, 0x0($t9)
    ctx->r16 = MEM_HU(ctx->r25, 0X0);
    // 0x801C2454: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x801C2458: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
    // 0x801C245C: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x801C2460: jal         0x80017064
    // 0x801C2464: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_0;
    // 0x801C2464: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_0:
    // 0x801C2468: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801C246C: bnel        $v0, $at, L_801C24A0
    if (ctx->r2 != ctx->r1) {
        // 0x801C2470: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_801C24A0;
    }
    goto skip_0;
    // 0x801C2470: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x801C2474: beq         $s0, $zero, L_801C249C
    if (ctx->r16 == 0) {
        // 0x801C2478: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_801C249C;
    }
    // 0x801C2478: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801C247C: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x801C2480: jal         0x800045E8
    // 0x801C2484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800045E8)(rdram, ctx);
        goto after_1;
    // 0x801C2484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801C2488: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x801C248C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x801C2490: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801C2494: jal         0x80004ADC
    // 0x801C2498: sw          $v0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r2;
    LOOKUP_FUNC(0x80004ADC)(rdram, ctx);
        goto after_2;
    // 0x801C2498: sw          $v0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r2;
    after_2:
L_801C249C:
    // 0x801C249C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_801C24A0:
    // 0x801C24A0: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x801C24A4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801C24A8: lw          $t3, -0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X4);
    // 0x801C24AC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801C24B0: lhu         $s0, 0x2($t4)
    ctx->r16 = MEM_HU(ctx->r12, 0X2);
    // 0x801C24B4: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
    // 0x801C24B8: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x801C24BC: jal         0x80017064
    // 0x801C24C0: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_3;
    // 0x801C24C0: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_3:
    // 0x801C24C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801C24C8: bnel        $v0, $at, L_801C24FC
    if (ctx->r2 != ctx->r1) {
        // 0x801C24CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801C24FC;
    }
    goto skip_1;
    // 0x801C24CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801C24D0: beq         $s0, $zero, L_801C24F8
    if (ctx->r16 == 0) {
        // 0x801C24D4: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_801C24F8;
    }
    // 0x801C24D4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x801C24D8: sw          $s0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r16;
    // 0x801C24DC: jal         0x800045E8
    // 0x801C24E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800045E8)(rdram, ctx);
        goto after_4;
    // 0x801C24E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801C24E4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801C24E8: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x801C24EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801C24F0: jal         0x80004ADC
    // 0x801C24F4: sw          $v0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r2;
    LOOKUP_FUNC(0x80004ADC)(rdram, ctx);
        goto after_5;
    // 0x801C24F4: sw          $v0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r2;
    after_5:
L_801C24F8:
    // 0x801C24F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C24FC:
    // 0x801C24FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C2500: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C2504: jr          $ra
    // 0x801C2508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C2508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c250c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c250c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C250C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C2510: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C2514: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C2518: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801C251C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C2520: beql        $t6, $zero, L_801C2540
    if (ctx->r14 == 0) {
        // 0x801C2524: lw          $t7, 0x10($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X10);
            goto L_801C2540;
    }
    goto skip_0;
    // 0x801C2524: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x801C2528: jal         0x801C288C
    // 0x801C252C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    LOOKUP_FUNC(0x801C288C)(rdram, ctx);
        goto after_0;
    // 0x801C252C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x801C2530: jal         0x8001F540
    // 0x801C2534: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_1;
    // 0x801C2534: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_1:
    // 0x801C2538: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x801C253C: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
L_801C2540:
    // 0x801C2540: beql        $t7, $zero, L_801C2560
    if (ctx->r15 == 0) {
        // 0x801C2544: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801C2560;
    }
    goto skip_1;
    // 0x801C2544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801C2548: jal         0x801C288C
    // 0x801C254C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    LOOKUP_FUNC(0x801C288C)(rdram, ctx);
        goto after_2;
    // 0x801C254C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x801C2550: jal         0x8001F540
    // 0x801C2554: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_3;
    // 0x801C2554: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_3:
    // 0x801C2558: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x801C255C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C2560:
    // 0x801C2560: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C2564: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C2568: jr          $ra
    // 0x801C256C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C256C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c2570(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c2570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2578: jal         0x801C27BC
    // 0x801C257C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x801C27BC)(rdram, ctx);
        goto after_0;
    // 0x801C257C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801C2580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C2584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2588: jr          $ra
    // 0x801C258C: nop

    return;
    // 0x801C258C: nop

;}
RECOMP_FUNC void M24_FUN_801c2590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2598: jal         0x801C27BC
    // 0x801C259C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801C27BC)(rdram, ctx);
        goto after_0;
    // 0x801C259C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x801C25A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C25A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C25A8: jr          $ra
    // 0x801C25AC: nop

    return;
    // 0x801C25AC: nop

;}
RECOMP_FUNC void M24_FUN_801c25b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C25B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C25B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C25B8: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x801C25BC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801C25C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C25C4: beq         $t6, $zero, L_801C25F8
    if (ctx->r14 == 0) {
        // 0x801C25C8: nop
    
            goto L_801C25F8;
    }
    // 0x801C25C8: nop

    // 0x801C25CC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x801C25D0: jal         0x801C288C
    // 0x801C25D4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C288C)(rdram, ctx);
        goto after_0;
    // 0x801C25D4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C25D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801C25DC: jal         0x8001F540
    // 0x801C25E0: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_1;
    // 0x801C25E0: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    after_1:
    // 0x801C25E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801C25E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C25EC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x801C25F0: b           L_801C25F8
    // 0x801C25F4: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
        goto L_801C25F8;
    // 0x801C25F4: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
L_801C25F8:
    // 0x801C25F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C25FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2600: jr          $ra
    // 0x801C2604: nop

    return;
    // 0x801C2604: nop

;}
RECOMP_FUNC void M24_FUN_801c2608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2608: blez        $a0, L_801C26BC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x801C260C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C26BC;
    }
    // 0x801C260C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C2610: andi        $a3, $a0, 0x3
    ctx->r7 = ctx->r4 & 0X3;
    // 0x801C2614: beq         $a3, $zero, L_801C2650
    if (ctx->r7 == 0) {
        // 0x801C2618: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_801C2650;
    }
    // 0x801C2618: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x801C261C: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x801C2620: subu        $t6, $t6, $zero
    ctx->r14 = SUB32(ctx->r14, 0);
    // 0x801C2624: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801C2628: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x801C262C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_801C2630:
    // 0x801C2630: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801C2634: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x801C2638: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x801C263C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x801C2640: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x801C2644: bne         $a2, $v0, L_801C2630
    if (ctx->r6 != ctx->r2) {
        // 0x801C2648: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_801C2630;
    }
    // 0x801C2648: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x801C264C: beq         $v0, $a0, L_801C26BC
    if (ctx->r2 == ctx->r4) {
        // 0x801C2650: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_801C26BC;
    }
L_801C2650:
    // 0x801C2650: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801C2654: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x801C2658: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x801C265C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x801C2660: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801C2664: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801C2668: addu        $a2, $t8, $a1
    ctx->r6 = ADD32(ctx->r24, ctx->r5);
    // 0x801C266C: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x801C2670: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_801C2674:
    // 0x801C2674: addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // 0x801C2678: sw          $a3, -0x48($v1)
    MEM_W(-0X48, ctx->r3) = ctx->r7;
    // 0x801C267C: sw          $a3, -0x44($v1)
    MEM_W(-0X44, ctx->r3) = ctx->r7;
    // 0x801C2680: sw          $zero, -0x3C($v1)
    MEM_W(-0X3C, ctx->r3) = 0;
    // 0x801C2684: sw          $zero, -0x38($v1)
    MEM_W(-0X38, ctx->r3) = 0;
    // 0x801C2688: sw          $a3, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = ctx->r7;
    // 0x801C268C: sw          $a3, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->r7;
    // 0x801C2690: sw          $zero, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = 0;
    // 0x801C2694: sw          $zero, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = 0;
    // 0x801C2698: sw          $a3, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r7;
    // 0x801C269C: sw          $a3, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->r7;
    // 0x801C26A0: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x801C26A4: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x801C26A8: sw          $a3, -0x60($v1)
    MEM_W(-0X60, ctx->r3) = ctx->r7;
    // 0x801C26AC: sw          $a3, -0x5C($v1)
    MEM_W(-0X5C, ctx->r3) = ctx->r7;
    // 0x801C26B0: sw          $zero, -0x54($v1)
    MEM_W(-0X54, ctx->r3) = 0;
    // 0x801C26B4: bne         $v1, $a2, L_801C2674
    if (ctx->r3 != ctx->r6) {
        // 0x801C26B8: sw          $zero, -0x50($v1)
        MEM_W(-0X50, ctx->r3) = 0;
            goto L_801C2674;
    }
    // 0x801C26B8: sw          $zero, -0x50($v1)
    MEM_W(-0X50, ctx->r3) = 0;
L_801C26BC:
    // 0x801C26BC: jr          $ra
    // 0x801C26C0: nop

    return;
    // 0x801C26C0: nop

;}
RECOMP_FUNC void M24_FUN_801c26c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C26C4: blez        $a0, L_801C2764
    if (SIGNED(ctx->r4) <= 0) {
        // 0x801C26C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C2764;
    }
    // 0x801C26C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C26CC: andi        $a3, $a0, 0x3
    ctx->r7 = ctx->r4 & 0X3;
    // 0x801C26D0: beq         $a3, $zero, L_801C2708
    if (ctx->r7 == 0) {
        // 0x801C26D4: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_801C2708;
    }
    // 0x801C26D4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x801C26D8: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x801C26DC: subu        $t6, $t6, $zero
    ctx->r14 = SUB32(ctx->r14, 0);
    // 0x801C26E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801C26E4: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x801C26E8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_801C26EC:
    // 0x801C26EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801C26F0: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x801C26F4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C26F8: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x801C26FC: bne         $a2, $v0, L_801C26EC
    if (ctx->r6 != ctx->r2) {
        // 0x801C2700: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_801C26EC;
    }
    // 0x801C2700: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x801C2704: beq         $v0, $a0, L_801C2764
    if (ctx->r2 == ctx->r4) {
        // 0x801C2708: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_801C2764;
    }
L_801C2708:
    // 0x801C2708: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801C270C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x801C2710: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x801C2714: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x801C2718: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801C271C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801C2720: addu        $a2, $t8, $a1
    ctx->r6 = ADD32(ctx->r24, ctx->r5);
    // 0x801C2724: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x801C2728: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_801C272C:
    // 0x801C272C: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x801C2730: sw          $a3, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = ctx->r7;
    // 0x801C2734: sw          $zero, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = 0;
    // 0x801C2738: sw          $zero, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = 0;
    // 0x801C273C: sw          $a3, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r7;
    // 0x801C2740: sw          $zero, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = 0;
    // 0x801C2744: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x801C2748: sw          $a3, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r7;
    // 0x801C274C: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x801C2750: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x801C2754: sw          $a3, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = ctx->r7;
    // 0x801C2758: sw          $zero, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = 0;
    // 0x801C275C: bne         $v1, $a2, L_801C272C
    if (ctx->r3 != ctx->r6) {
        // 0x801C2760: sw          $zero, -0x28($v1)
        MEM_W(-0X28, ctx->r3) = 0;
            goto L_801C272C;
    }
    // 0x801C2760: sw          $zero, -0x28($v1)
    MEM_W(-0X28, ctx->r3) = 0;
L_801C2764:
    // 0x801C2764: jr          $ra
    // 0x801C2768: nop

    return;
    // 0x801C2768: nop

;}
RECOMP_FUNC void M24_FUN_801c276c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C276C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2774: jal         0x80002A04
    // 0x801C2778: nop

    LOOKUP_FUNC(0x80002A04)(rdram, ctx);
        goto after_0;
    // 0x801C2778: nop

    after_0:
    // 0x801C277C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C2780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2784: jr          $ra
    // 0x801C2788: nop

    return;
    // 0x801C2788: nop

;}
RECOMP_FUNC void M24_FUN_801c278c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C278C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C2790: bne         $a0, $zero, L_801C27B4
    if (ctx->r4 != 0) {
        // 0x801C2794: sw          $a2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r6;
            goto L_801C27B4;
    }
    // 0x801C2794: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C2798: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C279C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x801C27A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_801C27A4:
    // 0x801C27A4: bnel        $v0, $v1, L_801C27A4
    if (ctx->r2 != ctx->r3) {
        // 0x801C27A8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_801C27A4;
    }
    goto skip_0;
    // 0x801C27A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
L_801C27AC:
    // 0x801C27AC: b           L_801C27AC
    pause_self(rdram);
    // 0x801C27B0: nop

L_801C27B4:
    // 0x801C27B4: jr          $ra
    // 0x801C27B8: nop

    return;
    // 0x801C27B8: nop

;}
RECOMP_FUNC void M24_FUN_801c27bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C27BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C27C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C27C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C27C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C27CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C27D0: jal         0x80016F90
    // 0x801C27D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80016F90)(rdram, ctx);
        goto after_0;
    // 0x801C27D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x801C27D8: jal         0x80017014
    // 0x801C27DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80017014)(rdram, ctx);
        goto after_1;
    // 0x801C27DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x801C27E0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x801C27E4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801C27E8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x801C27EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C27F0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801C27F4: lw          $t8, 0x1CEC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1CEC);
    // 0x801C27F8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x801C27FC: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x801C2800: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801C2804: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801C2808: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x801C280C: lhu         $s0, 0x0($t2)
    ctx->r16 = MEM_HU(ctx->r10, 0X0);
    // 0x801C2810: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
    // 0x801C2814: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x801C2818: jal         0x80017064
    // 0x801C281C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_2;
    // 0x801C281C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_2:
    // 0x801C2820: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801C2824: bnel        $v0, $at, L_801C2878
    if (ctx->r2 != ctx->r1) {
        // 0x801C2828: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C2878;
    }
    goto skip_0;
    // 0x801C2828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801C282C: beq         $s0, $zero, L_801C2874
    if (ctx->r16 == 0) {
        // 0x801C2830: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_801C2874;
    }
    // 0x801C2830: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801C2834: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801C2838: beq         $v0, $zero, L_801C2874
    if (ctx->r2 == 0) {
        // 0x801C283C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801C2874;
    }
    // 0x801C283C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801C2840: jal         0x8001F290
    // 0x801C2844: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_3;
    // 0x801C2844: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    after_3:
    // 0x801C2848: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x801C284C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x801C2850: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801C2854: jal         0x80016EAC
    // 0x801C2858: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    LOOKUP_FUNC(0x80016EAC)(rdram, ctx);
        goto after_4;
    // 0x801C2858: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    after_4:
    // 0x801C285C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x801C2860: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x801C2864: jal         0x80004ADC
    // 0x801C2868: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    LOOKUP_FUNC(0x80004ADC)(rdram, ctx);
        goto after_5;
    // 0x801C2868: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    after_5:
    // 0x801C286C: b           L_801C2878
    // 0x801C2870: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C2878;
    // 0x801C2870: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C2874:
    // 0x801C2874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C2878:
    // 0x801C2878: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C287C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C2880: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C2884: jr          $ra
    // 0x801C2888: nop

    return;
    // 0x801C2888: nop

;}
RECOMP_FUNC void M24_FUN_801c288c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C288C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2890: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801C2894: beq         $a0, $at, L_801C28DC
    if (ctx->r4 == ctx->r1) {
        // 0x801C2898: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801C28DC;
    }
    // 0x801C2898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C289C: jal         0x80017064
    // 0x801C28A0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_0;
    // 0x801C28A0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x801C28A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801C28A8: bne         $v0, $at, L_801C28C0
    if (ctx->r2 != ctx->r1) {
        // 0x801C28AC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801C28C0;
    }
    // 0x801C28AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801C28B0: jal         0x800177BC
    // 0x801C28B4: nop

    LOOKUP_FUNC(0x800177BC)(rdram, ctx);
        goto after_1;
    // 0x801C28B4: nop

    after_1:
    // 0x801C28B8: b           L_801C28E0
    // 0x801C28BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C28E0;
    // 0x801C28BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C28C0:
    // 0x801C28C0: jal         0x800173E4
    // 0x801C28C4: nop

    LOOKUP_FUNC(0x800173E4)(rdram, ctx);
        goto after_2;
    // 0x801C28C4: nop

    after_2:
    // 0x801C28C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801C28CC: bnel        $v0, $at, L_801C28E0
    if (ctx->r2 != ctx->r1) {
        // 0x801C28D0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801C28E0;
    }
    goto skip_0;
    // 0x801C28D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801C28D4: b           L_801C28E0
    // 0x801C28D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C28E0;
    // 0x801C28D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C28DC:
    // 0x801C28DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C28E0:
    // 0x801C28E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C28E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C28E8: jr          $ra
    // 0x801C28EC: nop

    return;
    // 0x801C28EC: nop

;}
RECOMP_FUNC void M24_FUN_801c28f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C28F0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x801C28F4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C28F8: addiu       $v0, $v0, -0x6028
    ctx->r2 = ADD32(ctx->r2, -0X6028);
    // 0x801C28FC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801C2900: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x801C2904: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C2908: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x801C290C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801C2910: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x801C2914: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x801C2918: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C291C: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x801C2920: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801C2924: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x801C2928: andi        $t3, $t9, 0xFFF
    ctx->r11 = ctx->r25 & 0XFFF;
    // 0x801C292C: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x801C2930: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x801C2934: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801C2938: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801C293C: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x801C2940: andi        $t0, $v1, 0xFFF
    ctx->r8 = ctx->r3 & 0XFFF;
    // 0x801C2944: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C2948: sll         $t1, $t0, 12
    ctx->r9 = S32(ctx->r8 << 12);
    // 0x801C294C: andi        $t3, $v1, 0xFFF
    ctx->r11 = ctx->r3 & 0XFFF;
    // 0x801C2950: addiu       $a1, $a1, -0x60D0
    ctx->r5 = ADD32(ctx->r5, -0X60D0);
    // 0x801C2954: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x801C2958: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x801C295C: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x801C2960: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801C2964: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x801C2968: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x801C296C: sw          $t8, 0x98($a1)
    MEM_W(0X98, ctx->r5) = ctx->r24;
    // 0x801C2970: jr          $ra
    // 0x801C2974: sw          $t4, 0x9C($a1)
    MEM_W(0X9C, ctx->r5) = ctx->r12;
    return;
    // 0x801C2974: sw          $t4, 0x9C($a1)
    MEM_W(0X9C, ctx->r5) = ctx->r12;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c2978(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c2978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2978: nop

    // 0x801C297C: nop

;}
RECOMP_FUNC void M24_FUN_801c2980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C2988: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C298C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2990: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C2994: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C2998: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C299C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C29A0: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801C29A4: jal         0x80005670
    // 0x801C29A8: addiu       $a1, $a1, -0x5DC4
    ctx->r5 = ADD32(ctx->r5, -0X5DC4);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C29A8: addiu       $a1, $a1, -0x5DC4
    ctx->r5 = ADD32(ctx->r5, -0X5DC4);
    after_0:
    // 0x801C29AC: bne         $v0, $zero, L_801C29BC
    if (ctx->r2 != 0) {
        // 0x801C29B0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C29BC;
    }
    // 0x801C29B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C29B4: b           L_801C2A0C
    // 0x801C29B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C2A0C;
    // 0x801C29B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C29BC:
    // 0x801C29BC: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x801C29C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C29C4: sb          $t6, 0x90($v1)
    MEM_B(0X90, ctx->r3) = ctx->r14;
    // 0x801C29C8: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x801C29CC: sb          $t7, 0x91($v1)
    MEM_B(0X91, ctx->r3) = ctx->r15;
    // 0x801C29D0: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x801C29D4: sb          $t8, 0x92($v1)
    MEM_B(0X92, ctx->r3) = ctx->r24;
    // 0x801C29D8: lbu         $t9, 0x27($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X27);
    // 0x801C29DC: sb          $t9, 0x94($v1)
    MEM_B(0X94, ctx->r3) = ctx->r25;
    // 0x801C29E0: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
    // 0x801C29E4: sb          $t0, 0x95($v1)
    MEM_B(0X95, ctx->r3) = ctx->r8;
    // 0x801C29E8: lbu         $t1, 0x2F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2F);
    // 0x801C29EC: sb          $t1, 0x96($v1)
    MEM_B(0X96, ctx->r3) = ctx->r9;
    // 0x801C29F0: lbu         $t2, 0x33($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X33);
    // 0x801C29F4: sb          $t2, 0x97($v1)
    MEM_B(0X97, ctx->r3) = ctx->r10;
    // 0x801C29F8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x801C29FC: sh          $zero, 0x9C($v1)
    MEM_H(0X9C, ctx->r3) = 0;
    // 0x801C2A00: sw          $t3, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r11;
    // 0x801C2A04: lhu         $t4, 0x3A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X3A);
    // 0x801C2A08: sh          $t4, 0xA0($v1)
    MEM_H(0XA0, ctx->r3) = ctx->r12;
L_801C2A0C:
    // 0x801C2A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C2A10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2A14: jr          $ra
    // 0x801C2A18: nop

    return;
    // 0x801C2A18: nop

;}
RECOMP_FUNC void M24_FUN_801c2a1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2A1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C2A20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C2A24: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C2A28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C2A2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C2A30: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801C2A34: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C2A38: jal         0x80005E44
    // 0x801C2A3C: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C2A3C: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    after_0:
    // 0x801C2A40: jal         0x80006214
    // 0x801C2A44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C2A44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C2A48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2A4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C2A50: addiu       $a2, $zero, 0xA7
    ctx->r6 = ADD32(0, 0XA7);
    // 0x801C2A54: jal         0x8012C89C
    // 0x801C2A58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C2A58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801C2A5C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C2A60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2A64: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    // 0x801C2A68: lw          $a1, 0x30($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X30);
    // 0x801C2A6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C2A70: jal         0x8012CF8C
    // 0x801C2A74: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x801C2A74: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x801C2A78: lbu         $t7, 0x90($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X90);
    // 0x801C2A7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C2A80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C2A84: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801C2A88: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C2A8C: bgez        $t7, L_801C2AA0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C2A90: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C2AA0;
    }
    // 0x801C2A90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C2A94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C2A98: nop

    // 0x801C2A9C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C2AA0:
    // 0x801C2AA0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C2AA4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C2AA8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C2AAC: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x801C2AB0: lbu         $t0, 0x91($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X91);
    // 0x801C2AB4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801C2AB8: bgez        $t0, L_801C2ACC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801C2ABC: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C2ACC;
    }
    // 0x801C2ABC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C2AC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C2AC4: nop

    // 0x801C2AC8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C2ACC:
    // 0x801C2ACC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C2AD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C2AD4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C2AD8: swc1        $f16, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f16.u32l;
    // 0x801C2ADC: lbu         $t3, 0x92($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X92);
    // 0x801C2AE0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801C2AE4: bgez        $t3, L_801C2AF8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801C2AE8: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C2AF8;
    }
    // 0x801C2AE8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C2AEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C2AF0: nop

    // 0x801C2AF4: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_801C2AF8:
    // 0x801C2AF8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C2AFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C2B00: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2B04: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C2B08: addiu       $a1, $a1, 0x2BC4
    ctx->r5 = ADD32(ctx->r5, 0X2BC4);
    // 0x801C2B0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2B10: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x801C2B14: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B18: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C2B1C: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x801C2B20: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B24: lbu         $t8, 0x94($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X94);
    // 0x801C2B28: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C2B2C: sb          $t8, 0x48($t0)
    MEM_B(0X48, ctx->r8) = ctx->r24;
    // 0x801C2B30: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B34: lbu         $t1, 0x95($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X95);
    // 0x801C2B38: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C2B3C: sb          $t1, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r9;
    // 0x801C2B40: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B44: lbu         $t4, 0x96($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X96);
    // 0x801C2B48: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C2B4C: sb          $t4, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r12;
    // 0x801C2B50: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B54: lbu         $t7, 0x97($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X97);
    // 0x801C2B58: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801C2B5C: sb          $t7, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = ctx->r15;
    // 0x801C2B60: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B64: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801C2B68: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x801C2B6C: ori         $t1, $t2, 0x100
    ctx->r9 = ctx->r10 | 0X100;
    // 0x801C2B70: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    // 0x801C2B74: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B78: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801C2B7C: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x801C2B80: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B84: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801C2B88: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x801C2B8C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B90: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x801C2B94: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x801C2B98: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C2B9C: lw          $t8, 0x98($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X98);
    // 0x801C2BA0: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x801C2BA4: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x801C2BA8: jal         0x800058DC
    // 0x801C2BAC: sw          $t0, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r8;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C2BAC: sw          $t0, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r8;
    after_4:
    // 0x801C2BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2BB4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C2BB8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C2BBC: jr          $ra
    // 0x801C2BC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C2BC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c2bc4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c2bc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2BCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C2BD0: lhu         $t6, 0x9C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X9C);
    // 0x801C2BD4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C2BD8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C2BDC: bgez        $t6, L_801C2BF0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C2BE0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C2BF0;
    }
    // 0x801C2BE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C2BE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C2BE8: nop

    // 0x801C2BEC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C2BF0:
    // 0x801C2BF0: lhu         $t7, 0xA0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XA0);
    // 0x801C2BF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C2BF8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801C2BFC: bgez        $t7, L_801C2C10
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C2C00: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C2C10;
    }
    // 0x801C2C00: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C2C04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C2C08: nop

    // 0x801C2C0C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C2C10:
    // 0x801C2C10: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801C2C14: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2C18: lwc1        $f8, -0x2DEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2DEC);
    // 0x801C2C1C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2C20: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C2C24: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    // 0x801C2C28: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801C2C2C: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    // 0x801C2C30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C2C34: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x801C2C38: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801C2C3C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801C2C40: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x801C2C44: nop

    // 0x801C2C48: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x801C2C4C: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x801C2C50: jal         0x8012CF8C
    // 0x801C2C54: lw          $a3, -0x5DB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5DB0);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801C2C54: lw          $a3, -0x5DB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5DB0);
    after_0:
    // 0x801C2C58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C2C5C: lhu         $t2, 0x9C($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X9C);
    // 0x801C2C60: lhu         $t4, 0xA0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0XA0);
    // 0x801C2C64: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801C2C68: andi        $t5, $t3, 0xFFFF
    ctx->r13 = ctx->r11 & 0XFFFF;
    // 0x801C2C6C: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801C2C70: beq         $at, $zero, L_801C2C80
    if (ctx->r1 == 0) {
        // 0x801C2C74: sh          $t3, 0x9C($a0)
        MEM_H(0X9C, ctx->r4) = ctx->r11;
            goto L_801C2C80;
    }
    // 0x801C2C74: sh          $t3, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r11;
    // 0x801C2C78: jal         0x80005700
    // 0x801C2C7C: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801C2C7C: nop

    after_1:
L_801C2C80:
    // 0x801C2C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C2C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2C88: jr          $ra
    // 0x801C2C8C: nop

    return;
    // 0x801C2C8C: nop

;}
RECOMP_FUNC void M24_FUN_801c2c90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2C98: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C2C9C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C2CA0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C2CA4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C2CA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C2CAC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C2CB0: addiu       $a1, $a1, -0x5D90
    ctx->r5 = ADD32(ctx->r5, -0X5D90);
    // 0x801C2CB4: jal         0x80005670
    // 0x801C2CB8: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C2CB8: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C2CBC: bne         $v0, $zero, L_801C2CCC
    if (ctx->r2 != 0) {
        // 0x801C2CC0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C2CCC;
    }
    // 0x801C2CC0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C2CC4: b           L_801C2D28
    // 0x801C2CC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C2D28;
    // 0x801C2CC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C2CCC:
    // 0x801C2CCC: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C2CD0: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C2CD4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2CD8: swc1        $f4, -0x1080($at)
    MEM_W(-0X1080, ctx->r1) = ctx->f4.u32l;
    // 0x801C2CDC: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C2CE0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2CE4: lbu         $t6, 0x27($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X27);
    // 0x801C2CE8: swc1        $f6, -0x107C($at)
    MEM_W(-0X107C, ctx->r1) = ctx->f6.u32l;
    // 0x801C2CEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2CF0: swc1        $f8, -0x1078($at)
    MEM_W(-0X1078, ctx->r1) = ctx->f8.u32l;
    // 0x801C2CF4: sb          $t6, 0x94($v1)
    MEM_B(0X94, ctx->r3) = ctx->r14;
    // 0x801C2CF8: lbu         $t7, 0x2B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2B);
    // 0x801C2CFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C2D00: sb          $t7, 0x95($v1)
    MEM_B(0X95, ctx->r3) = ctx->r15;
    // 0x801C2D04: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x801C2D08: sb          $t8, 0x96($v1)
    MEM_B(0X96, ctx->r3) = ctx->r24;
    // 0x801C2D0C: lbu         $t9, 0x33($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X33);
    // 0x801C2D10: sb          $t9, 0x97($v1)
    MEM_B(0X97, ctx->r3) = ctx->r25;
    // 0x801C2D14: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801C2D18: sh          $zero, 0x9C($v1)
    MEM_H(0X9C, ctx->r3) = 0;
    // 0x801C2D1C: sw          $t0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r8;
    // 0x801C2D20: lhu         $t1, 0x3A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X3A);
    // 0x801C2D24: sh          $t1, 0xA0($v1)
    MEM_H(0XA0, ctx->r3) = ctx->r9;
L_801C2D28:
    // 0x801C2D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C2D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2D30: jr          $ra
    // 0x801C2D34: nop

    return;
    // 0x801C2D34: nop

;}
RECOMP_FUNC void M24_FUN_801c2d38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2D38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C2D3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C2D40: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C2D44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C2D48: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C2D4C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801C2D50: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C2D54: jal         0x80005E44
    // 0x801C2D58: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C2D58: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    after_0:
    // 0x801C2D5C: jal         0x80006214
    // 0x801C2D60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C2D60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C2D64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C2D6C: addiu       $a2, $zero, 0xA9
    ctx->r6 = ADD32(0, 0XA9);
    // 0x801C2D70: jal         0x8012C89C
    // 0x801C2D74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C2D74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801C2D78: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C2D7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2D80: addiu       $a2, $zero, 0xAA
    ctx->r6 = ADD32(0, 0XAA);
    // 0x801C2D84: lw          $a1, 0x30($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X30);
    // 0x801C2D88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C2D8C: jal         0x8012CF8C
    // 0x801C2D90: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x801C2D90: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x801C2D94: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C2D98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C2D9C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C2DA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2DA4: lwc1        $f4, -0x1080($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1080);
    // 0x801C2DA8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C2DAC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2DB0: addiu       $t3, $zero, 0x1000
    ctx->r11 = ADD32(0, 0X1000);
    // 0x801C2DB4: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x801C2DB8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C2DBC: lwc1        $f6, -0x107C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X107C);
    // 0x801C2DC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2DC4: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C2DC8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C2DCC: addiu       $a1, $a1, 0x2E9C
    ctx->r5 = ADD32(ctx->r5, 0X2E9C);
    // 0x801C2DD0: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x801C2DD4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C2DD8: lwc1        $f8, -0x1078($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1078);
    // 0x801C2DDC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C2DE0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C2DE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C2DE8: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x801C2DEC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C2DF0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C2DF4: sh          $t3, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r11;
    // 0x801C2DF8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C2DFC: lbu         $t6, 0x94($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X94);
    // 0x801C2E00: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C2E04: sb          $t6, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r14;
    // 0x801C2E08: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C2E0C: lbu         $t9, 0x95($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X95);
    // 0x801C2E10: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C2E14: sb          $t9, 0x49($t1)
    MEM_B(0X49, ctx->r9) = ctx->r25;
    // 0x801C2E18: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C2E1C: lbu         $t2, 0x96($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X96);
    // 0x801C2E20: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x801C2E24: sb          $t2, 0x4A($t3)
    MEM_B(0X4A, ctx->r11) = ctx->r10;
    // 0x801C2E28: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C2E2C: lbu         $t5, 0x97($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X97);
    // 0x801C2E30: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x801C2E34: sb          $t5, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = ctx->r13;
    // 0x801C2E38: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C2E3C: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801C2E40: lw          $t0, 0x24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X24);
    // 0x801C2E44: ori         $t9, $t0, 0x100
    ctx->r25 = ctx->r8 | 0X100;
    // 0x801C2E48: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x801C2E4C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C2E50: lw          $t4, 0x30($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X30);
    // 0x801C2E54: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
    // 0x801C2E58: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C2E5C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C2E60: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    // 0x801C2E64: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C2E68: lw          $t5, 0x30($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X30);
    // 0x801C2E6C: swc1        $f0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f0.u32l;
    // 0x801C2E70: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C2E74: lw          $t6, 0x98($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X98);
    // 0x801C2E78: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x801C2E7C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x801C2E80: jal         0x800058DC
    // 0x801C2E84: sw          $t8, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C2E84: sw          $t8, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r24;
    after_4:
    // 0x801C2E88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C2E8C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C2E90: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C2E94: jr          $ra
    // 0x801C2E98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C2E98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c2e9c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c2e9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2EA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C2EA8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801C2EAC: addiu       $a2, $zero, 0xAA
    ctx->r6 = ADD32(0, 0XAA);
    // 0x801C2EB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C2EB4: lw          $a1, 0x30($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X30);
    // 0x801C2EB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C2EBC: jal         0x8012CF8C
    // 0x801C2EC0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801C2EC0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801C2EC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C2EC8: lhu         $t8, 0x9C($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X9C);
    // 0x801C2ECC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801C2ED0: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x801C2ED4: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x801C2ED8: bne         $at, $zero, L_801C2EE8
    if (ctx->r1 != 0) {
        // 0x801C2EDC: sh          $t9, 0x9C($a0)
        MEM_H(0X9C, ctx->r4) = ctx->r25;
            goto L_801C2EE8;
    }
    // 0x801C2EDC: sh          $t9, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r25;
    // 0x801C2EE0: jal         0x80005700
    // 0x801C2EE4: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801C2EE4: nop

    after_1:
L_801C2EE8:
    // 0x801C2EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C2EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2EF0: jr          $ra
    // 0x801C2EF4: nop

    return;
    // 0x801C2EF4: nop

;}
RECOMP_FUNC void M24_FUN_801c2ef8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2F00: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C2F04: jal         0x801C0D04
    // 0x801C2F08: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0D04)(rdram, ctx);
        goto after_0;
    // 0x801C2F08: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_0:
    // 0x801C2F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C2F10: ori         $t6, $zero, 0xFC84
    ctx->r14 = 0 | 0XFC84;
    // 0x801C2F14: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2F18: sw          $t6, -0x5D78($at)
    MEM_W(-0X5D78, ctx->r1) = ctx->r14;
    // 0x801C2F1C: jr          $ra
    // 0x801C2F20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801C2F20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c2f24(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c2f24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2F28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2F2C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C2F30: jal         0x801C0EB0
    // 0x801C2F34: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0EB0)(rdram, ctx);
        goto after_0;
    // 0x801C2F34: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_0:
    // 0x801C2F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C2F3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2F40: sw          $zero, -0x5D78($at)
    MEM_W(-0X5D78, ctx->r1) = 0;
    // 0x801C2F44: jr          $ra
    // 0x801C2F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801C2F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c2f4c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c2f4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2F4C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C2F50: lw          $v0, -0x5D78($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5D78);
    // 0x801C2F54: xori        $v0, $v0, 0xFC84
    ctx->r2 = ctx->r2 ^ 0XFC84;
    // 0x801C2F58: jr          $ra
    // 0x801C2F5C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801C2F5C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c2f60(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c2f60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2F60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C2F6C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C2F70: jal         0x801C0F18
    // 0x801C2F74: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    LOOKUP_FUNC(0x801C0F18)(rdram, ctx);
        goto after_0;
    // 0x801C2F74: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_0:
    // 0x801C2F78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801C2F7C: jal         0x80034C24
    // 0x801C2F80: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801C2F80: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_1:
    // 0x801C2F84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2F88: ldc1        $f4, -0x2DE8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2DE8);
    // 0x801C2F8C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C2F90: addiu       $v0, $v0, -0x5D7C
    ctx->r2 = ADD32(ctx->r2, -0X5D7C);
    // 0x801C2F94: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801C2F98: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C2F9C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801C2FA0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C2FA4: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    // 0x801C2FA8: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x801C2FAC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C2FB0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x801C2FB4: lwc1        $f10, -0x2DE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2DE0);
    // 0x801C2FB8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801C2FBC: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x801C2FC0: nop

    // 0x801C2FC4: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801C2FC8: jal         0x801C0DE4
    // 0x801C2FCC: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_2;
    // 0x801C2FCC: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    after_2:
    // 0x801C2FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C2FD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C2FD8: jr          $ra
    // 0x801C2FDC: nop

    return;
    // 0x801C2FDC: nop

;}
RECOMP_FUNC void M24_FUN_801c2fe0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C2FE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C2FE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C2FE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C2FEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C2FF0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C2FF4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C2FF8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C2FFC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C3000: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801C3004: jal         0x80005670
    // 0x801C3008: addiu       $a1, $a1, -0x5D74
    ctx->r5 = ADD32(ctx->r5, -0X5D74);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C3008: addiu       $a1, $a1, -0x5D74
    ctx->r5 = ADD32(ctx->r5, -0X5D74);
    after_0:
    // 0x801C300C: bne         $v0, $zero, L_801C301C
    if (ctx->r2 != 0) {
        // 0x801C3010: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C301C;
    }
    // 0x801C3010: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C3014: b           L_801C3094
    // 0x801C3018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C3094;
    // 0x801C3018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C301C:
    // 0x801C301C: lb          $t6, 0x1F($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X1F);
    // 0x801C3020: sb          $t6, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r14;
    // 0x801C3024: lb          $t7, 0x23($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X23);
    // 0x801C3028: sb          $t7, 0x91($v0)
    MEM_B(0X91, ctx->r2) = ctx->r15;
    // 0x801C302C: lb          $t8, 0x27($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X27);
    // 0x801C3030: sb          $t8, 0x92($v0)
    MEM_B(0X92, ctx->r2) = ctx->r24;
    // 0x801C3034: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x801C3038: sb          $t9, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r25;
    // 0x801C303C: lbu         $t0, 0x2F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2F);
    // 0x801C3040: sb          $t0, 0x95($v0)
    MEM_B(0X95, ctx->r2) = ctx->r8;
    // 0x801C3044: lbu         $t1, 0x33($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X33);
    // 0x801C3048: sb          $t1, 0x96($v0)
    MEM_B(0X96, ctx->r2) = ctx->r9;
    // 0x801C304C: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x801C3050: sb          $t2, 0x97($v0)
    MEM_B(0X97, ctx->r2) = ctx->r10;
    // 0x801C3054: lbu         $t3, 0x3B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3B);
    // 0x801C3058: sb          $t3, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = ctx->r11;
    // 0x801C305C: lbu         $t4, 0x3F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3F);
    // 0x801C3060: sb          $t4, 0xA5($v0)
    MEM_B(0XA5, ctx->r2) = ctx->r12;
    // 0x801C3064: lbu         $t5, 0x43($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X43);
    // 0x801C3068: sb          $t5, 0xA6($v0)
    MEM_B(0XA6, ctx->r2) = ctx->r13;
    // 0x801C306C: lbu         $t6, 0x47($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X47);
    // 0x801C3070: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C3074: sb          $t6, 0xA7($v1)
    MEM_B(0XA7, ctx->r3) = ctx->r14;
    // 0x801C3078: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x801C307C: sh          $zero, 0x9C($v1)
    MEM_H(0X9C, ctx->r3) = 0;
    // 0x801C3080: sw          $t7, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r15;
    // 0x801C3084: lhu         $t8, 0x4E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X4E);
    // 0x801C3088: sh          $t8, 0xA0($v1)
    MEM_H(0XA0, ctx->r3) = ctx->r24;
    // 0x801C308C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x801C3090: sw          $t9, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r25;
L_801C3094:
    // 0x801C3094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C309C: jr          $ra
    // 0x801C30A0: nop

    return;
    // 0x801C30A0: nop

;}
RECOMP_FUNC void M24_FUN_801c30a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C30A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C30A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C30AC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C30B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C30B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C30B8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801C30BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C30C0: jal         0x80005E44
    // 0x801C30C4: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C30C4: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    after_0:
    // 0x801C30C8: jal         0x80006214
    // 0x801C30CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C30CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C30D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C30D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C30D8: addiu       $a2, $zero, 0xA7
    ctx->r6 = ADD32(0, 0XA7);
    // 0x801C30DC: jal         0x8012C89C
    // 0x801C30E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C30E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801C30E4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C30E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C30EC: addiu       $a2, $zero, 0x2DC
    ctx->r6 = ADD32(0, 0X2DC);
    // 0x801C30F0: lw          $a1, 0x30($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X30);
    // 0x801C30F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C30F8: jal         0x8012CF8C
    // 0x801C30FC: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x801C30FC: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x801C3100: lb          $t7, 0x90($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X90);
    // 0x801C3104: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C3108: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801C310C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801C3110: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C3114: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3118: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C311C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C3120: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C3124: addiu       $a1, $a1, 0x3260
    ctx->r5 = ADD32(ctx->r5, 0X3260);
    // 0x801C3128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C312C: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x801C3130: lb          $t0, 0x91($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X91);
    // 0x801C3134: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C3138: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C313C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801C3140: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C3144: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C3148: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C314C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C3150: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C3154: swc1        $f10, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f10.u32l;
    // 0x801C3158: lb          $t3, 0x92($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X92);
    // 0x801C315C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C3160: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x801C3164: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C3168: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801C316C: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
    // 0x801C3170: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C3174: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C3178: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x801C317C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C3180: lbu         $t8, 0x94($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X94);
    // 0x801C3184: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C3188: sb          $t8, 0x48($t0)
    MEM_B(0X48, ctx->r8) = ctx->r24;
    // 0x801C318C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C3190: lbu         $t1, 0x95($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X95);
    // 0x801C3194: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C3198: sb          $t1, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r9;
    // 0x801C319C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C31A0: lbu         $t4, 0x96($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X96);
    // 0x801C31A4: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C31A8: sb          $t4, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r12;
    // 0x801C31AC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C31B0: lbu         $t7, 0x97($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X97);
    // 0x801C31B4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801C31B8: sb          $t7, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = ctx->r15;
    // 0x801C31BC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C31C0: lbu         $t0, 0xA4($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XA4);
    // 0x801C31C4: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x801C31C8: sb          $t0, 0x4C($t1)
    MEM_B(0X4C, ctx->r9) = ctx->r8;
    // 0x801C31CC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C31D0: lbu         $t3, 0xA5($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XA5);
    // 0x801C31D4: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x801C31D8: sb          $t3, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r11;
    // 0x801C31DC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C31E0: lbu         $t6, 0xA6($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XA6);
    // 0x801C31E4: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x801C31E8: sb          $t6, 0x4E($t7)
    MEM_B(0X4E, ctx->r15) = ctx->r14;
    // 0x801C31EC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C31F0: lbu         $t8, 0xA7($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0XA7);
    // 0x801C31F4: lw          $t0, 0x30($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X30);
    // 0x801C31F8: sb          $t8, 0x4F($t0)
    MEM_B(0X4F, ctx->r8) = ctx->r24;
    // 0x801C31FC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C3200: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x801C3204: lw          $t5, 0x24($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X24);
    // 0x801C3208: ori         $t3, $t5, 0x300
    ctx->r11 = ctx->r13 | 0X300;
    // 0x801C320C: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x801C3210: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C3214: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x801C3218: swc1        $f4, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f4.u32l;
    // 0x801C321C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C3220: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C3224: swc1        $f6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f6.u32l;
    // 0x801C3228: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C322C: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    // 0x801C3230: swc1        $f8, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f8.u32l;
    // 0x801C3234: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C3238: lw          $t0, 0x98($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X98);
    // 0x801C323C: lw          $t3, 0x30($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X30);
    // 0x801C3240: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x801C3244: jal         0x800058DC
    // 0x801C3248: sw          $t1, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r9;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C3248: sw          $t1, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r9;
    after_4:
    // 0x801C324C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C3250: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C3254: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C3258: jr          $ra
    // 0x801C325C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C325C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c3260(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c3260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C3264: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C3268: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C326C: lhu         $v0, 0x9C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X9C);
    // 0x801C3270: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C3274: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801C3278: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x801C327C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C3280: mfhi        $v0
    ctx->r2 = hi;
    // 0x801C3284: lw          $a1, 0x30($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X30);
    // 0x801C3288: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801C328C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C3290: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x801C3294: lw          $a3, -0x5D60($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5D60);
    // 0x801C3298: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C329C: addiu       $a2, $zero, 0x2DC
    ctx->r6 = ADD32(0, 0X2DC);
    // 0x801C32A0: jal         0x8012CF8C
    // 0x801C32A4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801C32A4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801C32A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C32AC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C32B0: lb          $v1, 0x90($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X90);
    // 0x801C32B4: lw          $v0, 0xA8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA8);
    // 0x801C32B8: lb          $a1, 0x91($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X91);
    // 0x801C32BC: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x801C32C0: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x801C32C4: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C32C8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C32CC: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801C32D0: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x801C32D4: lb          $a2, 0x92($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X92);
    // 0x801C32D8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801C32DC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801C32E0: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
    // 0x801C32E4: lw          $t1, 0x30($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X30);
    // 0x801C32E8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C32EC: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x801C32F0: lwc1        $f16, 0x8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801C32F4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C32F8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C32FC: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x801C3300: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x801C3304: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x801C3308: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C330C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801C3310: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x801C3314: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C3318: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x801C331C: swc1        $f16, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f16.u32l;
    // 0x801C3320: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C3324: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C3328: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801C332C: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x801C3330: nop

    // 0x801C3334: bc1fl       L_801C334C
    if (!c1cs) {
        // 0x801C3338: lhu         $t9, 0x9C($a0)
        ctx->r25 = MEM_HU(ctx->r4, 0X9C);
            goto L_801C334C;
    }
    goto skip_0;
    // 0x801C3338: lhu         $t9, 0x9C($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X9C);
    skip_0:
    // 0x801C333C: jal         0x80005700
    // 0x801C3340: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801C3340: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x801C3344: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C3348: lhu         $t9, 0x9C($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X9C);
L_801C334C:
    // 0x801C334C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x801C3350: sh          $t1, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r9;
    // 0x801C3354: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x801C3358: sh          $t2, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r10;
    // 0x801C335C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C3360: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C3364: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C3368: jr          $ra
    // 0x801C336C: nop

    return;
    // 0x801C336C: nop

;}
RECOMP_FUNC void M24_FUN_801c3370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3370: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C3374: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801C3378: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801C337C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801C3380: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801C3384: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801C3388: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C338C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C3390: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x801C3394: lw          $t1, 0x5C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X5C);
    // 0x801C3398: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x801C339C: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x801C33A0: lhu         $v1, 0xC($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0XC);
    // 0x801C33A4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C33A8: andi        $s4, $a3, 0xFF
    ctx->r20 = ctx->r7 & 0XFF;
    // 0x801C33AC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x801C33B0: bne         $at, $zero, L_801C34C8
    if (ctx->r1 != 0) {
        // 0x801C33B4: lw          $v0, 0x4($t1)
        ctx->r2 = MEM_W(ctx->r9, 0X4);
            goto L_801C34C8;
    }
    // 0x801C33B4: lw          $v0, 0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X4);
    // 0x801C33B8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x801C33BC: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801C33C0: lui         $s3, 0x801E
    ctx->r19 = S32(0X801E << 16);
    // 0x801C33C4: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x801C33C8: lui         $ra, 0x801E
    ctx->r31 = S32(0X801E << 16);
    // 0x801C33CC: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801C33D0: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801C33D4: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x801C33D8: addiu       $t2, $t2, -0x2578
    ctx->r10 = ADD32(ctx->r10, -0X2578);
    // 0x801C33DC: addiu       $t4, $t4, -0x6DF0
    ctx->r12 = ADD32(ctx->r12, -0X6DF0);
    // 0x801C33E0: addiu       $t5, $t5, -0x6E48
    ctx->r13 = ADD32(ctx->r13, -0X6E48);
    // 0x801C33E4: addiu       $ra, $ra, -0x6EA0
    ctx->r31 = ADD32(ctx->r31, -0X6EA0);
    // 0x801C33E8: addiu       $s2, $s2, -0x6D40
    ctx->r18 = ADD32(ctx->r18, -0X6D40);
    // 0x801C33EC: addiu       $s3, $s3, -0x6D98
    ctx->r19 = ADD32(ctx->r19, -0X6D98);
    // 0x801C33F0: addiu       $s1, $s1, -0x6CF0
    ctx->r17 = ADD32(ctx->r17, -0X6CF0);
    // 0x801C33F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801C33F8: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    // 0x801C33FC: addiu       $t3, $zero, 0x15
    ctx->r11 = ADD32(0, 0X15);
    // 0x801C3400: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x801C3404: lui         $a0, 0x4000
    ctx->r4 = S32(0X4000 << 16);
L_801C3408:
    // 0x801C3408: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x801C340C: addu        $a1, $t2, $a2
    ctx->r5 = ADD32(ctx->r10, ctx->r6);
    // 0x801C3410: bgezl       $t6, L_801C3424
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C3414: lw          $t7, 0x0($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X0);
            goto L_801C3424;
    }
    goto skip_0;
    // 0x801C3414: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x801C3418: b           L_801C34B4
    // 0x801C341C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
        goto L_801C34B4;
    // 0x801C341C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x801C3420: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
L_801C3424:
    // 0x801C3424: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801C3428: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x801C342C: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x801C3430: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x801C3434: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801C3438: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C343C: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x801C3440: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801C3444: bne         $t3, $t8, L_801C3478
    if (ctx->r11 != ctx->r24) {
        // 0x801C3448: nop
    
            goto L_801C3478;
    }
    // 0x801C3448: nop

    // 0x801C344C: beq         $t0, $zero, L_801C3470
    if (ctx->r8 == 0) {
        // 0x801C3450: or          $t7, $ra, $a0
        ctx->r15 = ctx->r31 | ctx->r4;
            goto L_801C3470;
    }
    // 0x801C3450: or          $t7, $ra, $a0
    ctx->r15 = ctx->r31 | ctx->r4;
    // 0x801C3454: beq         $s0, $zero, L_801C3468
    if (ctx->r16 == 0) {
        // 0x801C3458: or          $t6, $t5, $a0
        ctx->r14 = ctx->r13 | ctx->r4;
            goto L_801C3468;
    }
    // 0x801C3458: or          $t6, $t5, $a0
    ctx->r14 = ctx->r13 | ctx->r4;
    // 0x801C345C: or          $t9, $t4, $a0
    ctx->r25 = ctx->r12 | ctx->r4;
    // 0x801C3460: b           L_801C34A0
    // 0x801C3464: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_801C34A0;
    // 0x801C3464: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_801C3468:
    // 0x801C3468: b           L_801C34A0
    // 0x801C346C: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
        goto L_801C34A0;
    // 0x801C346C: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
L_801C3470:
    // 0x801C3470: b           L_801C34A0
    // 0x801C3474: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
        goto L_801C34A0;
    // 0x801C3474: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
L_801C3478:
    // 0x801C3478: beq         $t0, $zero, L_801C349C
    if (ctx->r8 == 0) {
        // 0x801C347C: or          $t6, $s3, $a0
        ctx->r14 = ctx->r19 | ctx->r4;
            goto L_801C349C;
    }
    // 0x801C347C: or          $t6, $s3, $a0
    ctx->r14 = ctx->r19 | ctx->r4;
    // 0x801C3480: beq         $s0, $zero, L_801C3494
    if (ctx->r16 == 0) {
        // 0x801C3484: or          $t9, $s2, $a0
        ctx->r25 = ctx->r18 | ctx->r4;
            goto L_801C3494;
    }
    // 0x801C3484: or          $t9, $s2, $a0
    ctx->r25 = ctx->r18 | ctx->r4;
    // 0x801C3488: or          $t8, $s1, $a0
    ctx->r24 = ctx->r17 | ctx->r4;
    // 0x801C348C: b           L_801C34A0
    // 0x801C3490: sw          $t8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r24;
        goto L_801C34A0;
    // 0x801C3490: sw          $t8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r24;
L_801C3494:
    // 0x801C3494: b           L_801C34A0
    // 0x801C3498: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_801C34A0;
    // 0x801C3498: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_801C349C:
    // 0x801C349C: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
L_801C34A0:
    // 0x801C34A0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801C34A4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801C34A8: sb          $s4, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = ctx->r20;
    // 0x801C34AC: lhu         $v1, 0xC($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0XC);
    // 0x801C34B0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_801C34B4:
    // 0x801C34B4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x801C34B8: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801C34BC: bne         $at, $zero, L_801C3408
    if (ctx->r1 != 0) {
        // 0x801C34C0: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_801C3408;
    }
    // 0x801C34C0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x801C34C4: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
L_801C34C8:
    // 0x801C34C8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801C34CC: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x801C34D0: swc1        $f12, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->f12.u32l;
    // 0x801C34D4: sw          $t9, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r25;
    // 0x801C34D8: bgez        $s4, L_801C34F0
    if (SIGNED(ctx->r20) >= 0) {
        // 0x801C34DC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C34F0;
    }
    // 0x801C34DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C34E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C34E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C34E8: nop

    // 0x801C34EC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C34F0:
    // 0x801C34F0: swc1        $f6, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f6.u32l;
    // 0x801C34F4: lbu         $t6, 0x43($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X43);
    // 0x801C34F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C34FC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801C3500: bgez        $t6, L_801C3514
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C3504: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C3514;
    }
    // 0x801C3504: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C3508: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C350C: nop

    // 0x801C3510: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C3514:
    // 0x801C3514: swc1        $f16, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f16.u32l;
    // 0x801C3518: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x801C351C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C3520: sw          $t7, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->r15;
    // 0x801C3524: jal         0x801C0D04
    // 0x801C3528: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x801C0D04)(rdram, ctx);
        goto after_0;
    // 0x801C3528: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x801C352C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801C3530: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C3534: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801C3538: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801C353C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801C3540: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801C3544: jr          $ra
    // 0x801C3548: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C3548: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c354c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c354c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C354C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C3550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3554: lwc1        $f14, 0x94($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801C3558: lw          $a1, 0x90($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X90);
    // 0x801C355C: lwc1        $f12, 0x98($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X98);
    // 0x801C3560: lwc1        $f16, 0x9C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x801C3564: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x801C3568: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801C356C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801C3570: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x801C3574: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C3578: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x801C357C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C3580: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x801C3584: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801C3588: jal         0x801C0DE4
    // 0x801C358C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801C0DE4)(rdram, ctx);
        goto after_0;
    // 0x801C358C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801C3590: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801C3594: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801C3598: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C359C: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C35A0: beq         $v0, $zero, L_801C35B8
    if (ctx->r2 == 0) {
        // 0x801C35A4: lwc1        $f16, 0x20($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
            goto L_801C35B8;
    }
    // 0x801C35A4: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C35A8: jal         0x801C0EB0
    // 0x801C35AC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801C0EB0)(rdram, ctx);
        goto after_1;
    // 0x801C35AC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x801C35B0: b           L_801C3708
    // 0x801C35B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C3708;
    // 0x801C35B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C35B8:
    // 0x801C35B8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C35BC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x801C35C0: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x801C35C4: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x801C35C8: jal         0x801C0F18
    // 0x801C35CC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801C0F18)(rdram, ctx);
        goto after_2;
    // 0x801C35CC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x801C35D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801C35D4: jal         0x80034C24
    // 0x801C35D8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801C35D8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801C35DC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801C35E0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C35E4: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C35E8: lw          $a2, 0x5C($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X5C);
    // 0x801C35EC: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C35F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C35F4: lhu         $a1, 0xC($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0XC);
    // 0x801C35F8: lw          $t0, 0x4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X4);
    // 0x801C35FC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x801C3600: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x801C3604: bne         $at, $zero, L_801C36E8
    if (ctx->r1 != 0) {
        // 0x801C3608: addiu       $a0, $t0, 0x4
        ctx->r4 = ADD32(ctx->r8, 0X4);
            goto L_801C36E8;
    }
    // 0x801C3608: addiu       $a0, $t0, 0x4
    ctx->r4 = ADD32(ctx->r8, 0X4);
    // 0x801C360C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3610: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x801C3614: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x801C3618: ldc1        $f2, -0x2DD8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2DD8);
L_801C361C:
    // 0x801C361C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x801C3620: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801C3624: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801C3628: bltz        $t7, L_801C36DC
    if (SIGNED(ctx->r15) < 0) {
        // 0x801C362C: addu        $t1, $a3, $v1
        ctx->r9 = ADD32(ctx->r7, ctx->r3);
            goto L_801C36DC;
    }
    // 0x801C362C: addu        $t1, $a3, $v1
    ctx->r9 = ADD32(ctx->r7, ctx->r3);
    // 0x801C3630: div.d       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x801C3634: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C3638: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C363C: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x801C3640: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801C3644: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x801C3648: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801C364C: add.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x801C3650: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C3654: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C3658: nop

    // 0x801C365C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C3660: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C3664: nop

    // 0x801C3668: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801C366C: beql        $t9, $zero, L_801C36BC
    if (ctx->r25 == 0) {
        // 0x801C3670: mfc1        $t9, $f8
        ctx->r25 = (int32_t)ctx->f8.u32l;
            goto L_801C36BC;
    }
    goto skip_0;
    // 0x801C3670: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x801C3674: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C3678: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C367C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C3680: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C3684: nop

    // 0x801C3688: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C368C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C3690: nop

    // 0x801C3694: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801C3698: bne         $t9, $zero, L_801C36B0
    if (ctx->r25 != 0) {
        // 0x801C369C: nop
    
            goto L_801C36B0;
    }
    // 0x801C369C: nop

    // 0x801C36A0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x801C36A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C36A8: b           L_801C36C8
    // 0x801C36AC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801C36C8;
    // 0x801C36AC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801C36B0:
    // 0x801C36B0: b           L_801C36C8
    // 0x801C36B4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801C36C8;
    // 0x801C36B4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C36B8: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
L_801C36BC:
    // 0x801C36BC: nop

    // 0x801C36C0: bltz        $t9, L_801C36B0
    if (SIGNED(ctx->r25) < 0) {
        // 0x801C36C4: nop
    
            goto L_801C36B0;
    }
    // 0x801C36C4: nop

L_801C36C8:
    // 0x801C36C8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801C36CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C36D0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801C36D4: sb          $t9, 0x4B($t3)
    MEM_B(0X4B, ctx->r11) = ctx->r25;
    // 0x801C36D8: lhu         $a1, 0xC($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0XC);
L_801C36DC:
    // 0x801C36DC: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801C36E0: bne         $at, $zero, L_801C361C
    if (ctx->r1 != 0) {
        // 0x801C36E4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_801C361C;
    }
    // 0x801C36E4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_801C36E8:
    // 0x801C36E8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x801C36EC: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x801C36F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C36F4: beq         $t4, $zero, L_801C3708
    if (ctx->r12 == 0) {
        // 0x801C36F8: nop
    
            goto L_801C3708;
    }
    // 0x801C36F8: nop

    // 0x801C36FC: lw          $t5, -0x2570($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2570);
    // 0x801C3700: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801C3704: sb          $zero, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = 0;
L_801C3708:
    // 0x801C3708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C370C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C3710: jr          $ra
    // 0x801C3714: nop

    return;
    // 0x801C3714: nop

;}
RECOMP_FUNC void M24_FUN_801c3718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C371C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C3720: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C3724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3728: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C372C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C3730: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C3734: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C3738: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801C373C: jal         0x80005670
    // 0x801C3740: addiu       $a1, $a1, -0x5D44
    ctx->r5 = ADD32(ctx->r5, -0X5D44);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C3740: addiu       $a1, $a1, -0x5D44
    ctx->r5 = ADD32(ctx->r5, -0X5D44);
    after_0:
    // 0x801C3744: bne         $v0, $zero, L_801C3754
    if (ctx->r2 != 0) {
        // 0x801C3748: lbu         $t6, 0x1B($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1B);
            goto L_801C3754;
    }
    // 0x801C3748: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x801C374C: b           L_801C37E0
    // 0x801C3750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C37E0;
    // 0x801C3750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C3754:
    // 0x801C3754: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x801C3758: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C375C: sb          $t6, -0x870($at)
    MEM_B(-0X870, ctx->r1) = ctx->r14;
    // 0x801C3760: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x801C3764: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3768: sb          $t7, -0x86F($at)
    MEM_B(-0X86F, ctx->r1) = ctx->r15;
    // 0x801C376C: lbu         $t9, 0x27($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X27);
    // 0x801C3770: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3774: sb          $t8, -0x86E($at)
    MEM_B(-0X86E, ctx->r1) = ctx->r24;
    // 0x801C3778: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
    // 0x801C377C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3780: sb          $t9, -0x86D($at)
    MEM_B(-0X86D, ctx->r1) = ctx->r25;
    // 0x801C3784: lbu         $t1, 0x2F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2F);
    // 0x801C3788: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C378C: sb          $t0, -0x86C($at)
    MEM_B(-0X86C, ctx->r1) = ctx->r8;
    // 0x801C3790: lbu         $t2, 0x33($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X33);
    // 0x801C3794: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3798: sb          $t1, -0x86B($at)
    MEM_B(-0X86B, ctx->r1) = ctx->r9;
    // 0x801C379C: lbu         $t3, 0x37($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X37);
    // 0x801C37A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C37A4: sb          $t2, -0x86A($at)
    MEM_B(-0X86A, ctx->r1) = ctx->r10;
    // 0x801C37A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C37AC: sb          $t3, -0x869($at)
    MEM_B(-0X869, ctx->r1) = ctx->r11;
    // 0x801C37B0: lhu         $t4, 0x3A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X3A);
    // 0x801C37B4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C37B8: sh          $zero, -0x868($at)
    MEM_H(-0X868, ctx->r1) = 0;
    // 0x801C37BC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C37C0: sh          $t4, -0x866($at)
    MEM_H(-0X866, ctx->r1) = ctx->r12;
    // 0x801C37C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C37C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C37CC: sw          $v0, -0x5D50($at)
    MEM_W(-0X5D50, ctx->r1) = ctx->r2;
    // 0x801C37D0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C37D4: sw          $v0, -0x5D4C($at)
    MEM_W(-0X5D4C, ctx->r1) = ctx->r2;
    // 0x801C37D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C37DC: sw          $zero, -0x5D48($at)
    MEM_W(-0X5D48, ctx->r1) = 0;
L_801C37E0:
    // 0x801C37E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C37E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C37E8: jr          $ra
    // 0x801C37EC: nop

    return;
    // 0x801C37EC: nop

;}
