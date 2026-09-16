#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801f9d68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9D68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9D6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9D74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9D78: lui         $a1, 0x17E
    ctx->r5 = S32(0X17E << 16);
    // 0x801F9D7C: ori         $a1, $a1, 0xFEDF
    ctx->r5 = ctx->r5 | 0XFEDF;
    // 0x801F9D80: jal         0x801C0B8C
    // 0x801F9D84: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9D84: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9D88: beql        $v0, $zero, L_801F9DA4
    if (ctx->r2 == 0) {
        // 0x801F9D8C: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_801F9DA4;
    }
    goto skip_0;
    // 0x801F9D8C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    skip_0:
    // 0x801F9D90: jal         0x8038D28C
    // 0x801F9D94: addiu       $a0, $zero, 0x1E8
    ctx->r4 = ADD32(0, 0X1E8);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F9D94: addiu       $a0, $zero, 0x1E8
    ctx->r4 = ADD32(0, 0X1E8);
    after_1:
    // 0x801F9D98: b           L_801F9DA4
    // 0x801F9D9C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801F9DA4;
    // 0x801F9D9C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x801F9DA0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801F9DA4:
    // 0x801F9DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9DA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F9DAC: jr          $ra
    // 0x801F9DB0: nop

    return;
    // 0x801F9DB0: nop

;}
RECOMP_FUNC void M25_FUN_801f9db4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9DB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9DB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9DBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9DC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9DC4: lui         $a1, 0x208
    ctx->r5 = S32(0X208 << 16);
    // 0x801F9DC8: ori         $a1, $a1, 0x531F
    ctx->r5 = ctx->r5 | 0X531F;
    // 0x801F9DCC: jal         0x801C0B8C
    // 0x801F9DD0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9DD0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9DD4: beql        $v0, $zero, L_801F9DF0
    if (ctx->r2 == 0) {
        // 0x801F9DD8: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_801F9DF0;
    }
    goto skip_0;
    // 0x801F9DD8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    skip_0:
    // 0x801F9DDC: jal         0x8038D28C
    // 0x801F9DE0: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F9DE0: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    after_1:
    // 0x801F9DE4: b           L_801F9DF0
    // 0x801F9DE8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801F9DF0;
    // 0x801F9DE8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x801F9DEC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801F9DF0:
    // 0x801F9DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9DF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F9DF8: jr          $ra
    // 0x801F9DFC: nop

    return;
    // 0x801F9DFC: nop

;}
RECOMP_FUNC void M25_FUN_801f9e00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9E00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9E04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9E0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9E10: lui         $a1, 0x282
    ctx->r5 = S32(0X282 << 16);
    // 0x801F9E14: ori         $a1, $a1, 0x651F
    ctx->r5 = ctx->r5 | 0X651F;
    // 0x801F9E18: jal         0x801C0B8C
    // 0x801F9E1C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9E1C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9E20: beql        $v0, $zero, L_801F9E4C
    if (ctx->r2 == 0) {
        // 0x801F9E24: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_801F9E4C;
    }
    goto skip_0;
    // 0x801F9E24: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    skip_0:
    // 0x801F9E28: jal         0x8038D28C
    // 0x801F9E2C: addiu       $a0, $zero, 0x699
    ctx->r4 = ADD32(0, 0X699);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F9E2C: addiu       $a0, $zero, 0x699
    ctx->r4 = ADD32(0, 0X699);
    after_1:
    // 0x801F9E30: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F9E34: sw          $zero, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = 0;
    // 0x801F9E38: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F9E3C: sw          $zero, -0x44F4($at)
    MEM_W(-0X44F4, ctx->r1) = 0;
    // 0x801F9E40: b           L_801F9E4C
    // 0x801F9E44: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F9E4C;
    // 0x801F9E44: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x801F9E48: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801F9E4C:
    // 0x801F9E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9E50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F9E54: jr          $ra
    // 0x801F9E58: nop

    return;
    // 0x801F9E58: nop

;}
RECOMP_FUNC void M25_FUN_801f9e5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9E5C: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801F9E60: lw          $v0, -0x44F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X44F8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f9e64(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f9e64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9E6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9E70: beq         $v0, $zero, L_801F9E98
    if (ctx->r2 == 0) {
        // 0x801F9E74: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801F9E98;
    }
    // 0x801F9E74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F9E78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F9E7C: beq         $v0, $at, L_801F9EC8
    if (ctx->r2 == ctx->r1) {
        // 0x801F9E80: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F9EC8;
    }
    // 0x801F9E80: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F9E84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801F9E88: beq         $v0, $at, L_801F9EF4
    if (ctx->r2 == ctx->r1) {
        // 0x801F9E8C: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801F9EF4;
    }
    // 0x801F9E8C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801F9E90: b           L_801F9F20
    // 0x801F9E94: nop

        goto L_801F9F20;
    // 0x801F9E94: nop

L_801F9E98:
    // 0x801F9E98: lui         $a1, 0x31A
    ctx->r5 = S32(0X31A << 16);
    // 0x801F9E9C: ori         $a1, $a1, 0xFB9F
    ctx->r5 = ctx->r5 | 0XFB9F;
    // 0x801F9EA0: jal         0x801C0B8C
    // 0x801F9EA4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F9EA4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F9EA8: beq         $v0, $zero, L_801F9F20
    if (ctx->r2 == 0) {
        // 0x801F9EAC: nop
    
            goto L_801F9F20;
    }
    // 0x801F9EAC: nop

    // 0x801F9EB0: jal         0x8038D28C
    // 0x801F9EB4: addiu       $a0, $zero, 0x1F0
    ctx->r4 = ADD32(0, 0X1F0);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F9EB4: addiu       $a0, $zero, 0x1F0
    ctx->r4 = ADD32(0, 0X1F0);
    after_1:
    // 0x801F9EB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F9EBC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F9EC0: b           L_801F9F20
    // 0x801F9EC4: sw          $t6, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r14;
        goto L_801F9F20;
    // 0x801F9EC4: sw          $t6, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r14;
L_801F9EC8:
    // 0x801F9EC8: lui         $a1, 0x339
    ctx->r5 = S32(0X339 << 16);
    // 0x801F9ECC: jal         0x801C0B8C
    // 0x801F9ED0: ori         $a1, $a1, 0x801F
    ctx->r5 = ctx->r5 | 0X801F;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801F9ED0: ori         $a1, $a1, 0x801F
    ctx->r5 = ctx->r5 | 0X801F;
    after_2:
    // 0x801F9ED4: beq         $v0, $zero, L_801F9F20
    if (ctx->r2 == 0) {
        // 0x801F9ED8: nop
    
            goto L_801F9F20;
    }
    // 0x801F9ED8: nop

    // 0x801F9EDC: jal         0x8038D28C
    // 0x801F9EE0: addiu       $a0, $zero, 0x1E7
    ctx->r4 = ADD32(0, 0X1E7);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_3;
    // 0x801F9EE0: addiu       $a0, $zero, 0x1E7
    ctx->r4 = ADD32(0, 0X1E7);
    after_3:
    // 0x801F9EE4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801F9EE8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F9EEC: b           L_801F9F20
    // 0x801F9EF0: sw          $t7, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r15;
        goto L_801F9F20;
    // 0x801F9EF0: sw          $t7, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r15;
L_801F9EF4:
    // 0x801F9EF4: lui         $a1, 0x367
    ctx->r5 = S32(0X367 << 16);
    // 0x801F9EF8: jal         0x801C0B8C
    // 0x801F9EFC: ori         $a1, $a1, 0x46DF
    ctx->r5 = ctx->r5 | 0X46DF;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_4;
    // 0x801F9EFC: ori         $a1, $a1, 0x46DF
    ctx->r5 = ctx->r5 | 0X46DF;
    after_4:
    // 0x801F9F00: beq         $v0, $zero, L_801F9F20
    if (ctx->r2 == 0) {
        // 0x801F9F04: nop
    
            goto L_801F9F20;
    }
    // 0x801F9F04: nop

    // 0x801F9F08: jal         0x8038D28C
    // 0x801F9F0C: addiu       $a0, $zero, 0x1F2
    ctx->r4 = ADD32(0, 0X1F2);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_5;
    // 0x801F9F0C: addiu       $a0, $zero, 0x1F2
    ctx->r4 = ADD32(0, 0X1F2);
    after_5:
    // 0x801F9F10: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801F9F14: sw          $zero, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = 0;
    // 0x801F9F18: b           L_801F9FF8
    // 0x801F9F1C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801F9FF8;
    // 0x801F9F1C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801F9F20:
    // 0x801F9F20: lui         $a0, 0x8020
    ctx->r4 = S32(0X8020 << 16);
    // 0x801F9F24: addiu       $a0, $a0, -0x44F4
    ctx->r4 = ADD32(ctx->r4, -0X44F4);
    // 0x801F9F28: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801F9F2C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x801F9F30: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x801F9F34: beq         $v1, $zero, L_801F9F7C
    if (ctx->r3 == 0) {
        // 0x801F9F38: sw          $t8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r24;
            goto L_801F9F7C;
    }
    // 0x801F9F38: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801F9F3C: beq         $v1, $at, L_801F9F8C
    if (ctx->r3 == ctx->r1) {
        // 0x801F9F40: addiu       $at, $zero, 0x36
        ctx->r1 = ADD32(0, 0X36);
            goto L_801F9F8C;
    }
    // 0x801F9F40: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x801F9F44: beq         $v1, $at, L_801F9F9C
    if (ctx->r3 == ctx->r1) {
        // 0x801F9F48: addiu       $at, $zero, 0x54
        ctx->r1 = ADD32(0, 0X54);
            goto L_801F9F9C;
    }
    // 0x801F9F48: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x801F9F4C: beq         $v1, $at, L_801F9FAC
    if (ctx->r3 == ctx->r1) {
        // 0x801F9F50: addiu       $at, $zero, 0x72
        ctx->r1 = ADD32(0, 0X72);
            goto L_801F9FAC;
    }
    // 0x801F9F50: addiu       $at, $zero, 0x72
    ctx->r1 = ADD32(0, 0X72);
    // 0x801F9F54: beq         $v1, $at, L_801F9FBC
    if (ctx->r3 == ctx->r1) {
        // 0x801F9F58: addiu       $at, $zero, 0xAE
        ctx->r1 = ADD32(0, 0XAE);
            goto L_801F9FBC;
    }
    // 0x801F9F58: addiu       $at, $zero, 0xAE
    ctx->r1 = ADD32(0, 0XAE);
    // 0x801F9F5C: beq         $v1, $at, L_801F9FCC
    if (ctx->r3 == ctx->r1) {
        // 0x801F9F60: addiu       $at, $zero, 0xD5
        ctx->r1 = ADD32(0, 0XD5);
            goto L_801F9FCC;
    }
    // 0x801F9F60: addiu       $at, $zero, 0xD5
    ctx->r1 = ADD32(0, 0XD5);
    // 0x801F9F64: beq         $v1, $at, L_801F9FDC
    if (ctx->r3 == ctx->r1) {
        // 0x801F9F68: addiu       $at, $zero, 0x192
        ctx->r1 = ADD32(0, 0X192);
            goto L_801F9FDC;
    }
    // 0x801F9F68: addiu       $at, $zero, 0x192
    ctx->r1 = ADD32(0, 0X192);
    // 0x801F9F6C: beq         $v1, $at, L_801F9FEC
    if (ctx->r3 == ctx->r1) {
        // 0x801F9F70: nop
    
            goto L_801F9FEC;
    }
    // 0x801F9F70: nop

    // 0x801F9F74: b           L_801F9FF8
    // 0x801F9F78: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F9FF8;
    // 0x801F9F78: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F9F7C:
    // 0x801F9F7C: jal         0x8038D28C
    // 0x801F9F80: addiu       $a0, $zero, 0x1E9
    ctx->r4 = ADD32(0, 0X1E9);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_6;
    // 0x801F9F80: addiu       $a0, $zero, 0x1E9
    ctx->r4 = ADD32(0, 0X1E9);
    after_6:
    // 0x801F9F84: b           L_801F9FF8
    // 0x801F9F88: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F9FF8;
    // 0x801F9F88: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F9F8C:
    // 0x801F9F8C: jal         0x8038D28C
    // 0x801F9F90: addiu       $a0, $zero, 0x1EA
    ctx->r4 = ADD32(0, 0X1EA);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_7;
    // 0x801F9F90: addiu       $a0, $zero, 0x1EA
    ctx->r4 = ADD32(0, 0X1EA);
    after_7:
    // 0x801F9F94: b           L_801F9FF8
    // 0x801F9F98: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F9FF8;
    // 0x801F9F98: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F9F9C:
    // 0x801F9F9C: jal         0x8038D28C
    // 0x801F9FA0: addiu       $a0, $zero, 0x1EB
    ctx->r4 = ADD32(0, 0X1EB);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_8;
    // 0x801F9FA0: addiu       $a0, $zero, 0x1EB
    ctx->r4 = ADD32(0, 0X1EB);
    after_8:
    // 0x801F9FA4: b           L_801F9FF8
    // 0x801F9FA8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F9FF8;
    // 0x801F9FA8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F9FAC:
    // 0x801F9FAC: jal         0x8038D28C
    // 0x801F9FB0: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_9;
    // 0x801F9FB0: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    after_9:
    // 0x801F9FB4: b           L_801F9FF8
    // 0x801F9FB8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F9FF8;
    // 0x801F9FB8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F9FBC:
    // 0x801F9FBC: jal         0x8038D28C
    // 0x801F9FC0: addiu       $a0, $zero, 0x1ED
    ctx->r4 = ADD32(0, 0X1ED);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_10;
    // 0x801F9FC0: addiu       $a0, $zero, 0x1ED
    ctx->r4 = ADD32(0, 0X1ED);
    after_10:
    // 0x801F9FC4: b           L_801F9FF8
    // 0x801F9FC8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F9FF8;
    // 0x801F9FC8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F9FCC:
    // 0x801F9FCC: jal         0x8038D28C
    // 0x801F9FD0: addiu       $a0, $zero, 0x1EE
    ctx->r4 = ADD32(0, 0X1EE);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_11;
    // 0x801F9FD0: addiu       $a0, $zero, 0x1EE
    ctx->r4 = ADD32(0, 0X1EE);
    after_11:
    // 0x801F9FD4: b           L_801F9FF8
    // 0x801F9FD8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F9FF8;
    // 0x801F9FD8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F9FDC:
    // 0x801F9FDC: jal         0x8038D28C
    // 0x801F9FE0: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_12;
    // 0x801F9FE0: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    after_12:
    // 0x801F9FE4: b           L_801F9FF8
    // 0x801F9FE8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F9FF8;
    // 0x801F9FE8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F9FEC:
    // 0x801F9FEC: jal         0x8038D28C
    // 0x801F9FF0: addiu       $a0, $zero, 0x1F1
    ctx->r4 = ADD32(0, 0X1F1);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_13;
    // 0x801F9FF0: addiu       $a0, $zero, 0x1F1
    ctx->r4 = ADD32(0, 0X1F1);
    after_13:
    // 0x801F9FF4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F9FF8:
    // 0x801F9FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F9FFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FA000: jr          $ra
    // 0x801FA004: nop

    return;
    // 0x801FA004: nop

;}
RECOMP_FUNC void M25_FUN_801fa008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FA00C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FA010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FA014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FA018: lui         $a1, 0x40F
    ctx->r5 = S32(0X40F << 16);
    // 0x801FA01C: ori         $a1, $a1, 0x1FA0
    ctx->r5 = ctx->r5 | 0X1FA0;
    // 0x801FA020: jal         0x801C0B8C
    // 0x801FA024: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801FA024: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801FA028: beql        $v0, $zero, L_801FA044
    if (ctx->r2 == 0) {
        // 0x801FA02C: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_801FA044;
    }
    goto skip_0;
    // 0x801FA02C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    skip_0:
    // 0x801FA030: jal         0x8038D28C
    // 0x801FA034: addiu       $a0, $zero, 0x698
    ctx->r4 = ADD32(0, 0X698);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801FA034: addiu       $a0, $zero, 0x698
    ctx->r4 = ADD32(0, 0X698);
    after_1:
    // 0x801FA038: b           L_801FA044
    // 0x801FA03C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801FA044;
    // 0x801FA03C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x801FA040: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801FA044:
    // 0x801FA044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FA048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FA04C: jr          $ra
    // 0x801FA050: nop

    return;
    // 0x801FA050: nop

;}
RECOMP_FUNC void M25_FUN_801fa054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA054: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801FA058: lw          $v0, -0x44F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X44F8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fa05c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fa05c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA05C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FA060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FA064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FA068: beq         $v0, $zero, L_801FA084
    if (ctx->r2 == 0) {
        // 0x801FA06C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801FA084;
    }
    // 0x801FA06C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FA070: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801FA074: beq         $v0, $at, L_801FA0B4
    if (ctx->r2 == ctx->r1) {
        // 0x801FA078: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801FA0B4;
    }
    // 0x801FA078: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801FA07C: b           L_801FA0DC
    // 0x801FA080: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801FA0DC;
    // 0x801FA080: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801FA084:
    // 0x801FA084: lui         $a1, 0x434
    ctx->r5 = S32(0X434 << 16);
    // 0x801FA088: ori         $a1, $a1, 0x40D5
    ctx->r5 = ctx->r5 | 0X40D5;
    // 0x801FA08C: jal         0x801C0B8C
    // 0x801FA090: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801FA090: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801FA094: beql        $v0, $zero, L_801FA0DC
    if (ctx->r2 == 0) {
        // 0x801FA098: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_801FA0DC;
    }
    goto skip_0;
    // 0x801FA098: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    skip_0:
    // 0x801FA09C: jal         0x8038D28C
    // 0x801FA0A0: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801FA0A0: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    after_1:
    // 0x801FA0A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801FA0A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801FA0AC: b           L_801FA0D8
    // 0x801FA0B0: sw          $t6, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r14;
        goto L_801FA0D8;
    // 0x801FA0B0: sw          $t6, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r14;
L_801FA0B4:
    // 0x801FA0B4: lui         $a1, 0x49F
    ctx->r5 = S32(0X49F << 16);
    // 0x801FA0B8: jal         0x801C0B8C
    // 0x801FA0BC: ori         $a1, $a1, 0x1095
    ctx->r5 = ctx->r5 | 0X1095;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801FA0BC: ori         $a1, $a1, 0x1095
    ctx->r5 = ctx->r5 | 0X1095;
    after_2:
    // 0x801FA0C0: beql        $v0, $zero, L_801FA0DC
    if (ctx->r2 == 0) {
        // 0x801FA0C4: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_801FA0DC;
    }
    goto skip_1;
    // 0x801FA0C4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    skip_1:
    // 0x801FA0C8: jal         0x8038D28C
    // 0x801FA0CC: addiu       $a0, $zero, 0x1F5
    ctx->r4 = ADD32(0, 0X1F5);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_3;
    // 0x801FA0CC: addiu       $a0, $zero, 0x1F5
    ctx->r4 = ADD32(0, 0X1F5);
    after_3:
    // 0x801FA0D0: b           L_801FA0DC
    // 0x801FA0D4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_801FA0DC;
    // 0x801FA0D4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801FA0D8:
    // 0x801FA0D8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801FA0DC:
    // 0x801FA0DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FA0E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FA0E4: jr          $ra
    // 0x801FA0E8: nop

    return;
    // 0x801FA0E8: nop

;}
RECOMP_FUNC void M25_FUN_801fa0ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA0EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FA0F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FA0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FA0F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FA0FC: lui         $a1, 0x616
    ctx->r5 = S32(0X616 << 16);
    // 0x801FA100: ori         $a1, $a1, 0x6E55
    ctx->r5 = ctx->r5 | 0X6E55;
    // 0x801FA104: jal         0x801C0B8C
    // 0x801FA108: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801FA108: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801FA10C: beql        $v0, $zero, L_801FA128
    if (ctx->r2 == 0) {
        // 0x801FA110: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_801FA128;
    }
    goto skip_0;
    // 0x801FA110: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    skip_0:
    // 0x801FA114: jal         0x8038D28C
    // 0x801FA118: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801FA118: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x801FA11C: b           L_801FA128
    // 0x801FA120: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_801FA128;
    // 0x801FA120: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x801FA124: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801FA128:
    // 0x801FA128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FA12C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FA130: jr          $ra
    // 0x801FA134: nop

    return;
    // 0x801FA134: nop

;}
RECOMP_FUNC void M25_FUN_801fa138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FA13C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FA140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FA144: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FA148: lui         $a1, 0x62D
    ctx->r5 = S32(0X62D << 16);
    // 0x801FA14C: ori         $a1, $a1, 0x51B5
    ctx->r5 = ctx->r5 | 0X51B5;
    // 0x801FA150: jal         0x801C0B8C
    // 0x801FA154: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801FA154: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801FA158: beql        $v0, $zero, L_801FA174
    if (ctx->r2 == 0) {
        // 0x801FA15C: addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
            goto L_801FA174;
    }
    goto skip_0;
    // 0x801FA15C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    skip_0:
    // 0x801FA160: jal         0x8038D28C
    // 0x801FA164: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801FA164: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    after_1:
    // 0x801FA168: b           L_801FA174
    // 0x801FA16C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_801FA174;
    // 0x801FA16C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x801FA170: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_801FA174:
    // 0x801FA174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FA178: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FA17C: jr          $ra
    // 0x801FA180: nop

    return;
    // 0x801FA180: nop

;}
RECOMP_FUNC void M25_FUN_801fa184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA184: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FA188: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801FA18C: jr          $ra
    // 0x801FA190: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    return;
    // 0x801FA190: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fa194(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fa194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA194: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FA198: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801FA19C: jr          $ra
    // 0x801FA1A0: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    return;
    // 0x801FA1A0: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fa1a4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fa1a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA1A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FA1A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801FA1AC: jr          $ra
    // 0x801FA1B0: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x801FA1B0: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fa1b4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fa1b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA1B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FA1B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801FA1BC: jr          $ra
    // 0x801FA1C0: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    return;
    // 0x801FA1C0: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fa1c4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fa1c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA1C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FA1C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801FA1CC: jr          $ra
    // 0x801FA1D0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x801FA1D0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fa1d4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fa1d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA1D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801FA1D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801FA1DC: jr          $ra
    // 0x801FA1E0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x801FA1E0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fa1e4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fa1e4(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA1E4u);
    return;
}
RECOMP_FUNC void M25_FUN_801fa428(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA428u);
    return;
}
RECOMP_FUNC void M25_FUN_801fa48c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA48Cu);
    return;
}
RECOMP_FUNC void M25_FUN_801fa4fc(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA4FCu);
    return;
}
RECOMP_FUNC void M25_FUN_801fa54c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA54Cu);
    return;
}
RECOMP_FUNC void M25_FUN_801fa5b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA5B0: nop

    // 0x801FA5B4: sh          $fp, -0x5B41($a2)
    MEM_H(-0X5B41, ctx->r6) = ctx->r30;
    // 0x801FA5B8: sb          $v0, -0x450E($t5)
    MEM_B(-0X450E, ctx->r13) = ctx->r2;
    // 0x801FA5BC: lwc1        $f28, -0x5B32($s7)
    ctx->f28.u32l = MEM_W(ctx->r23, -0X5B32);
    // 0x801FA5C0: sdr         $t5, -0x432C($t5)
    do_sdr(rdram, -0X432C, ctx->r13, ctx->r13);
    // 0x801FA5C4: sdl         $s1, -0x4755($s7)
    do_sdl(rdram, -0X4755, ctx->r23, ctx->r17);
    // 0x801FA5C8: sh          $a3, -0x5A5A($a2)
    MEM_H(-0X5A5A, ctx->r6) = ctx->r7;
    // 0x801FA5CC: sh          $a3, -0x5A17($t5)
    MEM_H(-0X5A17, ctx->r13) = ctx->r7;
    // 0x801FA5D0: sb          $gp, -0x3D19($t5)
    MEM_B(-0X3D19, ctx->r13) = ctx->r28;
    // 0x801FA5D4: lwc1        $f29, -0x3132($t7)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r15, -0X3132);
    // 0x801FA5D8: sh          $t7, -0x5E5E($a2)
    MEM_H(-0X5E5E, ctx->r6) = ctx->r15;
    // 0x801FA5DC: scd         $zero, -0x5C4E($t8)
    SD(0, -0X5C4E, ctx->r24);
    // 0x801FA5E0: sb          $s4, -0x3904($sp)
    MEM_B(-0X3904, ctx->r29) = ctx->r20;
    // 0x801FA5E4: sh          $t3, -0x5B31($a2)
    MEM_H(-0X5B31, ctx->r6) = ctx->r11;
    // 0x801FA5E8: sb          $v0, -0x353A($t5)
    MEM_B(-0X353A, ctx->r13) = ctx->r2;
    // 0x801FA5EC: swr         $s1, -0x5E5E($t7)
    do_swr(rdram, -0X5E5E, ctx->r15, ctx->r17);
    // 0x801FA5F0: sh          $t5, -0x5A49($t7)
    MEM_H(-0X5A49, ctx->r15) = ctx->r13;
    // 0x801FA5F4: sh          $v0, -0x5B55($t5)
    MEM_H(-0X5B55, ctx->r13) = ctx->r2;
    // 0x801FA5F8: sh          $t1, -0x5E5E($a3)
    MEM_H(-0X5E5E, ctx->r7) = ctx->r9;
    // 0x801FA5FC: scd         $zero, -0x3E4C($t8)
    SD(0, -0X3E4C, ctx->r24);
    // 0x801FA600: ll          $a0, -0x4C5A($a1)
    ctx->r4 = MEM_W(ctx->r5, -0X4C5A);
    // 0x801FA604: sh          $t8, -0x3E39($a2)
    MEM_H(-0X3E39, ctx->r6) = ctx->r24;
    // 0x801FA608: lwc1        $f8, -0x5B36($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, -0X5B36);
    // 0x801FA60C: sh          $t7, -0x5A16($t5)
    MEM_H(-0X5A16, ctx->r13) = ctx->r15;
    // 0x801FA610: sh          $t9, -0x5A22($t5)
    MEM_H(-0X5A22, ctx->r13) = ctx->r25;
    // 0x801FA614: sh          $t9, -0x5E5A($t5)
    MEM_H(-0X5E5A, ctx->r13) = ctx->r25;
    // 0x801FA618: sh          $s7, -0x5A14($t6)
    MEM_H(-0X5A14, ctx->r14) = ctx->r23;
    // 0x801FA61C: sh          $gp, -0x5A0D($t5)
    MEM_H(-0X5A0D, ctx->r13) = ctx->r28;
    // 0x801FA620: sh          $t0, -0x5B0E($t6)
    MEM_H(-0X5B0E, ctx->r14) = ctx->r8;
    // 0x801FA624: scd         $zero, -0x100($zero)
    SD(0, -0X100, 0);
    // 0x801FA628: tltu        $zero, $t8, 100

    // 0x801FA62C: srav        $zero, $zero, $zero
    // write to $zero
    // 0x801FA630: lb          $ra, -0x5DE0($zero)
    ctx->r31 = MEM_B(0, -0X5DE0);
    // 0x801FA634: sd          $ra, -0x1($ra)
    SD(ctx->r31, -0X1, ctx->r31);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fa638(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fa638(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA638u);
    return;
}
RECOMP_FUNC void M25_FUN_801fa708(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA708u);
    return;
}
RECOMP_FUNC void M25_FUN_801fa778(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA778u);
    return;
}
RECOMP_FUNC void M25_FUN_801fa7ec(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA7ECu);
    return;
}
RECOMP_FUNC void M25_FUN_801fa840(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA840u);
    return;
}
RECOMP_FUNC void M25_FUN_801fa8a8(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA8A8u);
    return;
}
RECOMP_FUNC void M25_FUN_801fa940(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA940u);
    return;
}
RECOMP_FUNC void M25_FUN_801fa9f0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FA9F0u);
    return;
}
RECOMP_FUNC void M25_FUN_801faa5c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FAA5Cu);
    return;
}
RECOMP_FUNC void M25_FUN_801faaa8(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FAAA8u);
    return;
}
RECOMP_FUNC void M25_FUN_801fab08(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FAB08u);
    return;
}
RECOMP_FUNC void M25_FUN_801fabd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FABD4: nop

    // 0x801FABD8: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FABDC: sh          $t1, -0x5B5A($a2)
    MEM_H(-0X5B5A, ctx->r6) = ctx->r9;
    // 0x801FABE0: sh          $s7, -0x5B3A($a1)
    MEM_H(-0X5B3A, ctx->r5) = ctx->r23;
    // 0x801FABE4: sb          $v0, -0x5B11($t5)
    MEM_B(-0X5B11, ctx->r13) = ctx->r2;
    // 0x801FABE8: sh          $ra, -0x5B49($a1)
    MEM_H(-0X5B49, ctx->r5) = ctx->r31;
    // 0x801FABEC: sh          $t3, -0x4A5C($a2)
    MEM_H(-0X4A5C, ctx->r6) = ctx->r11;
    // 0x801FABF0: sh          $a1, -0x5B55($a2)
    MEM_H(-0X5B55, ctx->r6) = ctx->r5;
    // 0x801FABF4: sh          $t2, -0x5B5C($a2)
    MEM_H(-0X5B5C, ctx->r6) = ctx->r10;
    // 0x801FABF8: sh          $t6, -0x5E57($a2)
    MEM_H(-0X5E57, ctx->r6) = ctx->r14;
    // 0x801FABFC: scd         $zero, -0x5E5F($t8)
    SD(0, -0X5E5F, ctx->r24);
    // 0x801FAC00: sb          $at, -0x4033($t5)
    MEM_B(-0X4033, ctx->r13) = ctx->r1;
    // 0x801FAC04: sdl         $v1, -0x5B5C($a3)
    do_sdl(rdram, -0X5B5C, ctx->r7, ctx->r3);
    // 0x801FAC08: sh          $t2, -0x5B32($a2)
    MEM_H(-0X5B32, ctx->r6) = ctx->r10;
    // 0x801FAC0C: sh          $t3, -0x5B49($a1)
    MEM_H(-0X5B49, ctx->r5) = ctx->r11;
    // 0x801FAC10: sh          $t1, -0x5E5A($a3)
    MEM_H(-0X5E5A, ctx->r7) = ctx->r9;
    // 0x801FAC14: sb          $a2, -0x5E5A($t5)
    MEM_B(-0X5E5A, ctx->r13) = ctx->r6;
    // 0x801FAC18: scd         $zero, -0x100($zero)
    SD(0, -0X100, 0);
    // 0x801FAC1C: tltu        $zero, $t8, 100

    // 0x801FAC20: srav        $zero, $zero, $zero
    // write to $zero
    // 0x801FAC24: lb          $ra, -0x5DE0($zero)
    ctx->r31 = MEM_B(0, -0X5DE0);
    // 0x801FAC28: sd          $ra, -0x1($ra)
    SD(ctx->r31, -0X1, ctx->r31);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fac2c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fac2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FAC2C: nop

    // 0x801FAC30: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FAC34: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FAC38: sb          $at, -0x5A21($t5)
    MEM_B(-0X5A21, ctx->r13) = ctx->r1;
    // 0x801FAC3C: sh          $t9, -0x5A41($t5)
    MEM_H(-0X5A41, ctx->r13) = ctx->r25;
    // 0x801FAC40: sb          $gp, -0x5E5A($t5)
    MEM_B(-0X5E5A, ctx->r13) = ctx->r28;
    // 0x801FAC44: sh          $a3, -0x5A5D($t6)
    MEM_H(-0X5A5D, ctx->r14) = ctx->r7;
    // 0x801FAC48: sh          $v0, -0x5A47($t5)
    MEM_H(-0X5A47, ctx->r13) = ctx->r2;
    // 0x801FAC4C: sb          $v1, -0xD00($t5)
    MEM_B(-0XD00, ctx->r13) = ctx->r3;
    // 0x801FAC50: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FAC54: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FAC58: sb          $at, -0x3218($t5)
    MEM_B(-0X3218, ctx->r13) = ctx->r1;
    // 0x801FAC5C: sh          $fp, -0x5B49($a2)
    MEM_H(-0X5B49, ctx->r6) = ctx->r30;
    // 0x801FAC60: sh          $ra, -0x5E5D($a1)
    MEM_H(-0X5E5D, ctx->r5) = ctx->r31;
    // 0x801FAC64: scd         $zero, -0x100($zero)
    SD(0, -0X100, 0);
    // 0x801FAC68: tltu        $zero, $t8, 100

    // 0x801FAC6C: srav        $zero, $zero, $zero
    // write to $zero
    // 0x801FAC70: lb          $ra, -0x5DE0($zero)
    ctx->r31 = MEM_B(0, -0X5DE0);
    // 0x801FAC74: sd          $ra, -0x1($ra)
    SD(ctx->r31, -0X1, ctx->r31);
    // 0x801FAC78: nop

    // 0x801FAC7C: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FAC80: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FAC84: sh          $sp, -0x5B32($a1)
    MEM_H(-0X5B32, ctx->r5) = ctx->r29;
    // 0x801FAC88: ll          $t3, -0x5B0E($fp)
    ctx->r11 = MEM_W(ctx->r30, -0X5B0E);
    // 0x801FAC8C: sdr         $v0, -0x5B3A($ra)
    do_sdr(rdram, -0X5B3A, ctx->r31, ctx->r2);
    // 0x801FAC90: sb          $t2, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r10;
    // 0x801FAC94: swr         $a2, -0x5B45($sp)
    do_swr(rdram, -0X5B45, ctx->r29, ctx->r6);
    // 0x801FAC98: sb          $t2, -0x100($t5)
    MEM_B(-0X100, ctx->r13) = ctx->r10;
    // 0x801FAC9C: tltu        $zero, $t8, 100

    // 0x801FACA0: srav        $zero, $zero, $zero
    // write to $zero
    // 0x801FACA4: lb          $ra, -0x5DE0($zero)
    ctx->r31 = MEM_B(0, -0X5DE0);
    // 0x801FACA8: sd          $ra, -0x1($ra)
    SD(ctx->r31, -0X1, ctx->r31);
    // 0x801FACAC: nop

    // 0x801FACB0: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FACB4: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FACB8: sb          $at, -0x5B22($t5)
    MEM_B(-0X5B22, ctx->r13) = ctx->r1;
    // 0x801FACBC: sh          $s5, -0x5B55($a1)
    MEM_H(-0X5B55, ctx->r5) = ctx->r21;
    // 0x801FACC0: sb          $v0, -0x5A48($t5)
    MEM_B(-0X5A48, ctx->r13) = ctx->r2;
    // 0x801FACC4: sh          $a3, -0x5A35($t7)
    MEM_H(-0X5A35, ctx->r15) = ctx->r7;
    // 0x801FACC8: sb          $gp, -0x5E57($t5)
    MEM_B(-0X5E57, ctx->r13) = ctx->r28;
    // 0x801FACCC: scd         $zero, -0x100($zero)
    SD(0, -0X100, 0);
    // 0x801FACD0: tltu        $zero, $t8, 100

    // 0x801FACD4: srav        $zero, $zero, $zero
    // write to $zero
    // 0x801FACD8: lb          $ra, -0x5DE0($zero)
    ctx->r31 = MEM_B(0, -0X5DE0);
    // 0x801FACDC: sd          $ra, -0x1($ra)
    SD(ctx->r31, -0X1, ctx->r31);
    // 0x801FACE0: nop

    // 0x801FACE4: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FACE8: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FACEC: sh          $fp, -0x5B4B($a2)
    MEM_H(-0X5B4B, ctx->r6) = ctx->r30;
    // 0x801FACF0: sh          $t3, -0x5E5A($a1)
    MEM_H(-0X5E5A, ctx->r5) = ctx->r11;
    // 0x801FACF4: sb          $a2, -0x5E5A($t5)
    MEM_B(-0X5E5A, ctx->r13) = ctx->r6;
    // 0x801FACF8: sb          $at, -0x4E4D($t5)
    MEM_B(-0X4E4D, ctx->r13) = ctx->r1;
    // 0x801FACFC: sh          $t0, -0x5E5A($a3)
    MEM_H(-0X5E5A, ctx->r7) = ctx->r8;
    // 0x801FAD00: sb          $a2, -0x5E5A($t5)
    MEM_B(-0X5E5A, ctx->r13) = ctx->r6;
    // 0x801FAD04: scd         $zero, -0x100($zero)
    SD(0, -0X100, 0);
    // 0x801FAD08: tltu        $zero, $t8, 100

    // 0x801FAD0C: srav        $zero, $zero, $zero
    // write to $zero
    // 0x801FAD10: lb          $ra, -0x5DE0($zero)
    ctx->r31 = MEM_B(0, -0X5DE0);
    // 0x801FAD14: sd          $ra, -0x1($ra)
    SD(ctx->r31, -0X1, ctx->r31);
    // 0x801FAD18: nop

    // 0x801FAD1C: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FAD20: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FAD24: sh          $t2, -0x5B44($a2)
    MEM_H(-0X5B44, ctx->r6) = ctx->r10;
    // 0x801FAD28: sdr         $v0, -0x5B3D($ra)
    do_sdr(rdram, -0X5B3D, ctx->r31, ctx->r2);
    // 0x801FAD2C: sh          $ra, -0x5B0D($a1)
    MEM_H(-0X5B0D, ctx->r5) = ctx->r31;
    // 0x801FAD30: sh          $a3, -0x5B47($a2)
    MEM_H(-0X5B47, ctx->r6) = ctx->r7;
    // 0x801FAD34: sh          $t3, -0x5E56($a1)
    MEM_H(-0X5E56, ctx->r5) = ctx->r11;
    // 0x801FAD38: sb          $t1, -0x100($t5)
    MEM_B(-0X100, ctx->r13) = ctx->r9;
    // 0x801FAD3C: tltu        $zero, $t8, 100

    // 0x801FAD40: srav        $zero, $zero, $zero
    // write to $zero
    // 0x801FAD44: lb          $ra, -0x5DE0($zero)
    ctx->r31 = MEM_B(0, -0X5DE0);
    // 0x801FAD48: sd          $ra, -0x1($ra)
    SD(ctx->r31, -0X1, ctx->r31);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fad4c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fad4c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FAD4Cu);
    return;
}
RECOMP_FUNC void M25_FUN_801fadec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FADEC: nop

    // 0x801FADF0: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FADF4: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FADF8: cache       0x1A, -0x4A0E($s6)

    // 0x801FADFC: sh          $t7, -0x413D($a2)
    MEM_H(-0X413D, ctx->r6) = ctx->r15;
    // 0x801FAE00: sh          $t0, -0x5B41($a1)
    MEM_H(-0X5B41, ctx->r5) = ctx->r8;
    // 0x801FAE04: sb          $t2, -0xD00($t5)
    MEM_B(-0XD00, ctx->r13) = ctx->r10;
    // 0x801FAE08: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FAE0C: sb          $at, -0x5E5F($t5)
    MEM_B(-0X5E5F, ctx->r13) = ctx->r1;
    // 0x801FAE10: swr         $t7, -0x3F29($s5)
    do_swr(rdram, -0X3F29, ctx->r21, ctx->r15);
    // 0x801FAE14: sh          $t7, -0x443C($a2)
    MEM_H(-0X443C, ctx->r6) = ctx->r15;
    // 0x801FAE18: sh          $v1, -0x5B3A($a2)
    MEM_H(-0X5B3A, ctx->r6) = ctx->r3;
    // 0x801FAE1C: sh          $a0, -0x5B36($a1)
    MEM_H(-0X5B36, ctx->r5) = ctx->r4;
    // 0x801FAE20: sh          $a0, -0x5E56($a1)
    MEM_H(-0X5E56, ctx->r5) = ctx->r4;
    // 0x801FAE24: sb          $t2, -0x100($t5)
    MEM_B(-0X100, ctx->r13) = ctx->r10;
    // 0x801FAE28: tltu        $zero, $t8, 100

    // 0x801FAE2C: srav        $zero, $zero, $zero
    // write to $zero
    // 0x801FAE30: lb          $ra, -0x5DE0($zero)
    ctx->r31 = MEM_B(0, -0X5DE0);
    // 0x801FAE34: sd          $ra, -0x1($ra)
    SD(ctx->r31, -0X1, ctx->r31);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fae38(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fae38(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FAE38u);
    return;
}
RECOMP_FUNC void M25_FUN_801fae68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FAE68: nop

    // 0x801FAE6C: nop

    // 0x801FAE70: dsra32      $zero, $zero, 7
    // write to $zero
    // 0x801FAE74: lb          $at, 0x0($zero)
    ctx->r1 = MEM_B(0, 0X0);
    // 0x801FAE78: nop

    // 0x801FAE7C: nop

    // 0x801FAE80: nop

    // 0x801FAE84: lwl         $s2, -0x3861($t2)
    ctx->r18 = do_lwl(rdram, ctx->r18, ctx->r10, -0X3861);
    // 0x801FAE88: dsra32      $zero, $zero, 7
    // write to $zero
    // 0x801FAE8C: sll         $zero, $a0, 0
    // write to $zero
    // 0x801FAE90: nop

    // 0x801FAE94: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fae98(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fae98(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FAE98u);
    return;
}
RECOMP_FUNC void M25_FUN_801fbb3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FBB3C: lb          $ra, -0x5FF8($zero)
    ctx->r31 = MEM_B(0, -0X5FF8);
    // 0x801FBB40: lb          $ra, -0x5FAC($zero)
    ctx->r31 = MEM_B(0, -0X5FAC);
    // 0x801FBB44: lb          $ra, -0x5F14($zero)
    ctx->r31 = MEM_B(0, -0X5F14);
    // 0x801FBB48: lb          $ra, -0x5EC8($zero)
    ctx->r31 = MEM_B(0, -0X5EC8);
    // 0x801FBB4C: lb          $ra, -0x5E7C($zero)
    ctx->r31 = MEM_B(0, -0X5E7C);
    // 0x801FBB50: lb          $ra, -0x5E6C($zero)
    ctx->r31 = MEM_B(0, -0X5E6C);
    // 0x801FBB54: lb          $ra, -0x5E5C($zero)
    ctx->r31 = MEM_B(0, -0X5E5C);
    // 0x801FBB58: lb          $ra, -0x5E4C($zero)
    ctx->r31 = MEM_B(0, -0X5E4C);
    // 0x801FBB5C: lb          $ra, -0x5E3C($zero)
    ctx->r31 = MEM_B(0, -0X5E3C);
    // 0x801FBB60: lb          $ra, -0x5E2C($zero)
    ctx->r31 = MEM_B(0, -0X5E2C);
    // 0x801FBB64: lb          $ra, -0x44F0($zero)
    ctx->r31 = MEM_B(0, -0X44F0);
    // 0x801FBB68: nop

    // 0x801FBB6C: lb          $ra, -0x4798($zero)
    ctx->r31 = MEM_B(0, -0X4798);
    // 0x801FBB70: lb          $ra, -0x474C($zero)
    ctx->r31 = MEM_B(0, -0X474C);
    // 0x801FBB74: nop

    // 0x801FBB78: lb          $ra, -0x4660($zero)
    ctx->r31 = MEM_B(0, -0X4660);
    // 0x801FBB7C: lb          $ra, -0x4534($zero)
    ctx->r31 = MEM_B(0, -0X4534);
    // 0x801FBB80: nop

    // 0x801FBB84: lb          $ra, -0x4500($zero)
    ctx->r31 = MEM_B(0, -0X4500);
    // 0x801FBB88: nop

    // 0x801FBB8C: lb          $ra, -0x449C($zero)
    ctx->r31 = MEM_B(0, -0X449C);
    // 0x801FBB90: lb          $ra, -0x504C($zero)
    ctx->r31 = MEM_B(0, -0X504C);
    // 0x801FBB94: lb          $ra, -0x4C90($zero)
    ctx->r31 = MEM_B(0, -0X4C90);
    // 0x801FBB98: lb          $ra, -0x482C($zero)
    ctx->r31 = MEM_B(0, -0X482C);
    // 0x801FBB9C: lb          $ra, -0x4494($zero)
    ctx->r31 = MEM_B(0, -0X4494);
    // 0x801FBBA0: nop

    // 0x801FBBA4: nop

    // 0x801FBBA8: nop

    // 0x801FBBAC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801fbbb0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801fbbb0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FBBB0u);
    return;
}
RECOMP_FUNC void M25_FUN_801fbbc0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FBBC0u);
    return;
}
RECOMP_FUNC void M25_FUN_801fbc28(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FBC28u);
    return;
}
RECOMP_FUNC void M25_FUN_801fc490(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FC490u);
    return;
}
RECOMP_FUNC void M25_FUN_801fc720(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FC720u);
    return;
}
RECOMP_FUNC void M25_FUN_801fcbe0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801FCBE0u);
    return;
}
RECOMP_FUNC void M99_FUN_8038b7e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B7E0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038B7E4: sw          $zero, -0x22A0($at)
    MEM_W(-0X22A0, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M99_FUN_8038b7e8(rdram, ctx);
;}
RECOMP_FUNC void M99_FUN_8038b7e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B7E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038B7EC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038B7F0: sw          $zero, -0x27B0($at)
    MEM_W(-0X27B0, ctx->r1) = 0;
    // 0x8038B7F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038B7F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8038B7FC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038B800: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8038B804: sw          $zero, -0x27AC($at)
    MEM_W(-0X27AC, ctx->r1) = 0;
    // 0x8038B808: jal         0x801BF6C4
    // 0x8038B80C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801BF6C4)(rdram, ctx);
        goto after_0;
    // 0x8038B80C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8038B810: jal         0x8038B8FC
    // 0x8038B814: nop

    LOOKUP_FUNC(0x8038B8FC)(rdram, ctx);
        goto after_1;
    // 0x8038B814: nop

    after_1:
    // 0x8038B818: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038B81C: addiu       $a1, $a1, -0x47C8
    ctx->r5 = ADD32(ctx->r5, -0X47C8);
    // 0x8038B820: jal         0x800058DC
    // 0x8038B824: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8038B824: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8038B828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038B82C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038B830: jr          $ra
    // 0x8038B834: nop

    return;
    // 0x8038B834: nop

;}
RECOMP_FUNC void M99_FUN_8038b838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038B838: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038B83C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038B840: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8038B844: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038B848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8038B84C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8038B850: jal         0x801BF968
    // 0x8038B854: sw          $t6, -0x22A0($at)
    MEM_W(-0X22A0, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x801BF968)(rdram, ctx);
        goto after_0;
    // 0x8038B854: sw          $t6, -0x22A0($at)
    MEM_W(-0X22A0, ctx->r1) = ctx->r14;
    after_0:
    // 0x8038B858: beq         $v0, $zero, L_8038B86C
    if (ctx->r2 == 0) {
        // 0x8038B85C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8038B86C;
    }
    // 0x8038B85C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8038B860: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038B864: jal         0x800058DC
    // 0x8038B868: addiu       $a1, $a1, -0x4784
    ctx->r5 = ADD32(ctx->r5, -0X4784);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8038B868: addiu       $a1, $a1, -0x4784
    ctx->r5 = ADD32(ctx->r5, -0X4784);
    after_1:
L_8038B86C:
    // 0x8038B86C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038B870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038B874: jr          $ra
    // 0x8038B878: nop

    return;
    // 0x8038B878: nop

;}
