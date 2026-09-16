#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801e6f20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6F24: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801E6F28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6F2C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E6F30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6F34: jal         0x8038BEC8
    // 0x801E6F38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8038BEC8)(rdram, ctx);
        goto after_0;
    // 0x801E6F38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801E6F3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6F40: jal         0x8038BE98
    // 0x801E6F44: lwc1        $f12, -0x3F90($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3F90);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_1;
    // 0x801E6F44: lwc1        $f12, -0x3F90($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3F90);
    after_1:
    // 0x801E6F48: lui         $at, 0xC343
    ctx->r1 = S32(0XC343 << 16);
    // 0x801E6F4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E6F50: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E6F54: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E6F58: jal         0x8038BD50
    // 0x801E6F5C: lui         $a2, 0xC2CC
    ctx->r6 = S32(0XC2CC << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_2;
    // 0x801E6F5C: lui         $a2, 0xC2CC
    ctx->r6 = S32(0XC2CC << 16);
    after_2:
    // 0x801E6F60: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6F64: lwc1        $f12, -0x3F8C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3F8C);
    // 0x801E6F68: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801E6F6C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E6F70: jal         0x8038BD88
    // 0x801E6F74: lui         $a2, 0x427C
    ctx->r6 = S32(0X427C << 16);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_3;
    // 0x801E6F74: lui         $a2, 0x427C
    ctx->r6 = S32(0X427C << 16);
    after_3:
    // 0x801E6F78: lui         $a1, 0x53
    ctx->r5 = S32(0X53 << 16);
    // 0x801E6F7C: ori         $a1, $a1, 0xEC60
    ctx->r5 = ctx->r5 | 0XEC60;
    // 0x801E6F80: jal         0x801C0B8C
    // 0x801E6F84: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_4;
    // 0x801E6F84: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_4:
    // 0x801E6F88: beq         $v0, $zero, L_801E6FC8
    if (ctx->r2 == 0) {
        // 0x801E6F8C: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E6FC8;
    }
    // 0x801E6F8C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6F90: lwc1        $f12, -0x3F88($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3F88);
    // 0x801E6F94: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6F98: lui         $a2, 0xC212
    ctx->r6 = S32(0XC212 << 16);
    // 0x801E6F9C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E6FA0: jal         0x8038BD50
    // 0x801E6FA4: lwc1        $f14, -0x3F84($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3F84);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_5;
    // 0x801E6FA4: lwc1        $f14, -0x3F84($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3F84);
    after_5:
    // 0x801E6FA8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6FAC: lwc1        $f12, -0x3F80($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3F80);
    // 0x801E6FB0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E6FB4: lwc1        $f14, -0x3F7C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3F7C);
    // 0x801E6FB8: jal         0x8038BD88
    // 0x801E6FBC: lui         $a2, 0xC202
    ctx->r6 = S32(0XC202 << 16);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_6;
    // 0x801E6FBC: lui         $a2, 0xC202
    ctx->r6 = S32(0XC202 << 16);
    after_6:
    // 0x801E6FC0: b           L_801E6FCC
    // 0x801E6FC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E6FCC;
    // 0x801E6FC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E6FC8:
    // 0x801E6FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801E6FCC:
    // 0x801E6FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E6FD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E6FD4: jr          $ra
    // 0x801E6FD8: nop

    return;
    // 0x801E6FD8: nop

;}
RECOMP_FUNC void M25_FUN_801e6fdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E6FDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E6FE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E6FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E6FE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E6FEC: lui         $a1, 0xAF
    ctx->r5 = S32(0XAF << 16);
    // 0x801E6FF0: ori         $a1, $a1, 0x79E0
    ctx->r5 = ctx->r5 | 0X79E0;
    // 0x801E6FF4: jal         0x801C0B8C
    // 0x801E6FF8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E6FF8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E6FFC: beq         $v0, $zero, L_801E7044
    if (ctx->r2 == 0) {
        // 0x801E7000: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E7044;
    }
    // 0x801E7000: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E7004: lui         $at, 0x42AE
    ctx->r1 = S32(0X42AE << 16);
    // 0x801E7008: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E700C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7010: lui         $a2, 0xC103
    ctx->r6 = S32(0XC103 << 16);
    // 0x801E7014: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E7018: jal         0x8038BD50
    // 0x801E701C: lwc1        $f14, -0x3F78($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3F78);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E701C: lwc1        $f14, -0x3F78($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3F78);
    after_1:
    // 0x801E7020: lui         $at, 0x4293
    ctx->r1 = S32(0X4293 << 16);
    // 0x801E7024: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E7028: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E702C: lui         $a2, 0xC146
    ctx->r6 = S32(0XC146 << 16);
    // 0x801E7030: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E7034: jal         0x8038BD88
    // 0x801E7038: lwc1        $f14, -0x3F74($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3F74);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E7038: lwc1        $f14, -0x3F74($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3F74);
    after_2:
    // 0x801E703C: b           L_801E70B4
    // 0x801E7040: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E70B4;
    // 0x801E7040: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E7044:
    // 0x801E7044: lui         $a1, 0x81
    ctx->r5 = S32(0X81 << 16);
    // 0x801E7048: jal         0x801C0B8C
    // 0x801E704C: ori         $a1, $a1, 0xB320
    ctx->r5 = ctx->r5 | 0XB320;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801E704C: ori         $a1, $a1, 0xB320
    ctx->r5 = ctx->r5 | 0XB320;
    after_3:
    // 0x801E7050: beq         $v0, $zero, L_801E70B0
    if (ctx->r2 == 0) {
        // 0x801E7054: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_801E70B0;
    }
    // 0x801E7054: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801E7058: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801E705C: lw          $t6, 0xE8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XE8);
    // 0x801E7060: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7064: lwc1        $f6, -0x3F70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3F70);
    // 0x801E7068: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801E706C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7070: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801E7074: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E7078: swc1        $f8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f8.u32l;
    // 0x801E707C: lw          $t7, 0xE8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XE8);
    // 0x801E7080: lwc1        $f16, -0x3F6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3F6C);
    // 0x801E7084: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7088: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801E708C: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801E7090: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E7094: swc1        $f18, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f18.u32l;
    // 0x801E7098: lw          $t8, 0xE8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XE8);
    // 0x801E709C: lwc1        $f6, -0x3F68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3F68);
    // 0x801E70A0: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801E70A4: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801E70A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E70AC: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
L_801E70B0:
    // 0x801E70B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E70B4:
    // 0x801E70B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E70B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E70BC: jr          $ra
    // 0x801E70C0: nop

    return;
    // 0x801E70C0: nop

;}
RECOMP_FUNC void M25_FUN_801e70c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E70C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E70C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E70CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E70D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E70D4: lui         $a1, 0x140
    ctx->r5 = S32(0X140 << 16);
    // 0x801E70D8: ori         $a1, $a1, 0x6F40
    ctx->r5 = ctx->r5 | 0X6F40;
    // 0x801E70DC: jal         0x801C0B8C
    // 0x801E70E0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E70E0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E70E4: beq         $v0, $zero, L_801E712C
    if (ctx->r2 == 0) {
        // 0x801E70E8: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E712C;
    }
    // 0x801E70E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E70EC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E70F0: lwc1        $f12, -0x3F64($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3F64);
    // 0x801E70F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E70F8: lui         $a2, 0xC113
    ctx->r6 = S32(0XC113 << 16);
    // 0x801E70FC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E7100: jal         0x8038BD50
    // 0x801E7104: lwc1        $f14, -0x3F60($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3F60);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E7104: lwc1        $f14, -0x3F60($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3F60);
    after_1:
    // 0x801E7108: lui         $at, 0xC344
    ctx->r1 = S32(0XC344 << 16);
    // 0x801E710C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E7110: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7114: lui         $a2, 0xBFA6
    ctx->r6 = S32(0XBFA6 << 16);
    // 0x801E7118: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E711C: jal         0x8038BD88
    // 0x801E7120: lwc1        $f14, -0x3F5C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3F5C);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E7120: lwc1        $f14, -0x3F5C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3F5C);
    after_2:
    // 0x801E7124: b           L_801E71F0
    // 0x801E7128: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801E71F0;
    // 0x801E7128: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E712C:
    // 0x801E712C: lui         $a1, 0x129
    ctx->r5 = S32(0X129 << 16);
    // 0x801E7130: jal         0x801C0B8C
    // 0x801E7134: ori         $a1, $a1, 0x8BE0
    ctx->r5 = ctx->r5 | 0X8BE0;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801E7134: ori         $a1, $a1, 0x8BE0
    ctx->r5 = ctx->r5 | 0X8BE0;
    after_3:
    // 0x801E7138: beq         $v0, $zero, L_801E7148
    if (ctx->r2 == 0) {
        // 0x801E713C: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801E7148;
    }
    // 0x801E713C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E7140: b           L_801E71F0
    // 0x801E7144: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E71F0;
    // 0x801E7144: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E7148:
    // 0x801E7148: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E714C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7150: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7154: lwc1        $f0, -0x3F58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3F58);
    // 0x801E7158: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801E715C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7160: lwc1        $f6, -0x3F54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3F54);
    // 0x801E7164: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801E7168: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E716C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E7170: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E7174: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801E7178: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801E717C: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801E7180: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801E7184: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x801E7188: swc1        $f16, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f16.u32l;
    // 0x801E718C: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7190: lwc1        $f4, -0x3F50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3F50);
    // 0x801E7194: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7198: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801E719C: lwc1        $f18, 0x38($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801E71A0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801E71A4: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
    // 0x801E71A8: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x801E71AC: lwc1        $f10, -0x3F4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3F4C);
    // 0x801E71B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E71B4: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801E71B8: lwc1        $f8, 0x3C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801E71BC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801E71C0: swc1        $f16, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f16.u32l;
    // 0x801E71C4: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E71C8: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801E71CC: lwc1        $f18, 0x40($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801E71D0: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x801E71D4: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x801E71D8: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x801E71DC: lwc1        $f8, -0x3F48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3F48);
    // 0x801E71E0: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801E71E4: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801E71E8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801E71EC: swc1        $f10, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f10.u32l;
L_801E71F0:
    // 0x801E71F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E71F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E71F8: jr          $ra
    // 0x801E71FC: nop

    return;
    // 0x801E71FC: nop

;}
RECOMP_FUNC void M25_FUN_801e7200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E7200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E7204: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E7208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E720C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E7210: lui         $a1, 0x166
    ctx->r5 = S32(0X166 << 16);
    // 0x801E7214: ori         $a1, $a1, 0x94E0
    ctx->r5 = ctx->r5 | 0X94E0;
    // 0x801E7218: jal         0x801C0B8C
    // 0x801E721C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E721C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E7220: beq         $v0, $zero, L_801E7264
    if (ctx->r2 == 0) {
        // 0x801E7224: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801E7264;
    }
    // 0x801E7224: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E7228: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E722C: lwc1        $f12, -0x3F44($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3F44);
    // 0x801E7230: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x801E7234: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E7238: jal         0x8038BD50
    // 0x801E723C: lui         $a2, 0xC180
    ctx->r6 = S32(0XC180 << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E723C: lui         $a2, 0xC180
    ctx->r6 = S32(0XC180 << 16);
    after_1:
    // 0x801E7240: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x801E7244: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E7248: lui         $at, 0x4178
    ctx->r1 = S32(0X4178 << 16);
    // 0x801E724C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E7250: lui         $a2, 0xC136
    ctx->r6 = S32(0XC136 << 16);
    // 0x801E7254: jal         0x8038BD88
    // 0x801E7258: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E7258: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    after_2:
    // 0x801E725C: b           L_801E7314
    // 0x801E7260: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801E7314;
    // 0x801E7260: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801E7264:
    // 0x801E7264: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E7268: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E726C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7270: lwc1        $f6, -0x3F40($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3F40);
    // 0x801E7274: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801E7278: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E727C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801E7280: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801E7284: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E7288: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801E728C: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7290: lwc1        $f16, -0x3F3C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3F3C);
    // 0x801E7294: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7298: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801E729C: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801E72A0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E72A4: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801E72A8: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E72AC: lwc1        $f6, -0x3F38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3F38);
    // 0x801E72B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E72B4: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801E72B8: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801E72BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E72C0: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    // 0x801E72C4: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x801E72C8: lwc1        $f16, -0x3F34($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3F34);
    // 0x801E72CC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E72D0: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801E72D4: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801E72D8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E72DC: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x801E72E0: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E72E4: lwc1        $f6, -0x3F30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3F30);
    // 0x801E72E8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E72EC: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801E72F0: lwc1        $f4, 0x40($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801E72F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E72F8: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x801E72FC: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7300: lwc1        $f16, -0x3F2C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3F2C);
    // 0x801E7304: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801E7308: lwc1        $f10, 0x44($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801E730C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E7310: swc1        $f18, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f18.u32l;
L_801E7314:
    // 0x801E7314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E7318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E731C: jr          $ra
    // 0x801E7320: nop

    return;
    // 0x801E7320: nop

;}
RECOMP_FUNC void M25_FUN_801e7324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E7324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E7328: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E732C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E7330: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E7334: lui         $a1, 0x1C8
    ctx->r5 = S32(0X1C8 << 16);
    // 0x801E7338: ori         $a1, $a1, 0x3CE0
    ctx->r5 = ctx->r5 | 0X3CE0;
    // 0x801E733C: jal         0x801C0B8C
    // 0x801E7340: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E7340: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E7344: beq         $v0, $zero, L_801E7384
    if (ctx->r2 == 0) {
        // 0x801E7348: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E7384;
    }
    // 0x801E7348: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E734C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7350: lwc1        $f12, -0x3F28($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3F28);
    // 0x801E7354: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x801E7358: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E735C: jal         0x8038BD50
    // 0x801E7360: lui         $a2, 0xC138
    ctx->r6 = S32(0XC138 << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E7360: lui         $a2, 0xC138
    ctx->r6 = S32(0XC138 << 16);
    after_1:
    // 0x801E7364: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x801E7368: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E736C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7370: lwc1        $f14, -0x3F24($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3F24);
    // 0x801E7374: jal         0x8038BD88
    // 0x801E7378: lui         $a2, 0xC138
    ctx->r6 = S32(0XC138 << 16);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E7378: lui         $a2, 0xC138
    ctx->r6 = S32(0XC138 << 16);
    after_2:
    // 0x801E737C: b           L_801E754C
    // 0x801E7380: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801E754C;
    // 0x801E7380: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801E7384:
    // 0x801E7384: lui         $a1, 0x1A9
    ctx->r5 = S32(0X1A9 << 16);
    // 0x801E7388: jal         0x801C0B8C
    // 0x801E738C: ori         $a1, $a1, 0xB860
    ctx->r5 = ctx->r5 | 0XB860;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801E738C: ori         $a1, $a1, 0xB860
    ctx->r5 = ctx->r5 | 0XB860;
    after_3:
    // 0x801E7390: beql        $v0, $zero, L_801E74DC
    if (ctx->r2 == 0) {
        // 0x801E7394: lui         $a1, 0x16C
        ctx->r5 = S32(0X16C << 16);
            goto L_801E74DC;
    }
    goto skip_0;
    // 0x801E7394: lui         $a1, 0x16C
    ctx->r5 = S32(0X16C << 16);
    skip_0:
    // 0x801E7398: jal         0x801C0B2C
    // 0x801E739C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_4;
    // 0x801E739C: nop

    after_4:
    // 0x801E73A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E73A4: jal         0x80034C24
    // 0x801E73A8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_5;
    // 0x801E73A8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_5:
    // 0x801E73AC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E73B0: ldc1        $f12, -0x3F20($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X3F20);
    // 0x801E73B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E73B8: ldc1        $f4, -0x3F18($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3F18);
    // 0x801E73BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E73C0: ldc1        $f8, -0x3F10($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3F10);
    // 0x801E73C4: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E73C8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E73CC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E73D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E73D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E73D8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E73DC: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E73E0: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E73E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801E73E8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E73EC: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E73F0: ldc1        $f6, -0x3F08($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3F08);
    // 0x801E73F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E73F8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E73FC: ldc1        $f10, -0x3F00($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3F00);
    // 0x801E7400: lui         $at, 0xC01C
    ctx->r1 = S32(0XC01C << 16);
    // 0x801E7404: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E7408: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E740C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E7410: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E7414: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7418: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E741C: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E7420: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801E7424: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E7428: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801E742C: ldc1        $f8, -0x3EF8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3EF8);
    // 0x801E7430: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7434: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7438: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E743C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E7440: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E7444: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801E7448: ldc1        $f18, -0x3EF0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3EF0);
    // 0x801E744C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7450: ldc1        $f6, -0x3EE8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3EE8);
    // 0x801E7454: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801E7458: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E745C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7460: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E7464: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801E7468: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E746C: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801E7470: ldc1        $f16, -0x3EE0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3EE0);
    // 0x801E7474: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7478: ldc1        $f4, -0x3ED8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3ED8);
    // 0x801E747C: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801E7480: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7484: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7488: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E748C: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801E7490: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E7494: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801E7498: ldc1        $f10, -0x3ED0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3ED0);
    // 0x801E749C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E74A0: ldc1        $f18, -0x3EC8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3EC8);
    // 0x801E74A4: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801E74A8: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E74AC: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x801E74B0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E74B4: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801E74B8: add.d       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f8.d + ctx->f12.d;
    // 0x801E74BC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E74C0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E74C4: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801E74C8: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E74CC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E74D0: b           L_801E754C
    // 0x801E74D4: swc1        $f16, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f16.u32l;
        goto L_801E754C;
    // 0x801E74D4: swc1        $f16, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f16.u32l;
    // 0x801E74D8: lui         $a1, 0x16C
    ctx->r5 = S32(0X16C << 16);
L_801E74DC:
    // 0x801E74DC: ori         $a1, $a1, 0xAF60
    ctx->r5 = ctx->r5 | 0XAF60;
    // 0x801E74E0: jal         0x801C0B8C
    // 0x801E74E4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_6;
    // 0x801E74E4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_6:
    // 0x801E74E8: beq         $v0, $zero, L_801E7548
    if (ctx->r2 == 0) {
        // 0x801E74EC: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801E7548;
    }
    // 0x801E74EC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E74F0: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E74F4: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E74F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E74FC: lwc1        $f4, -0x3EC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3EC0);
    // 0x801E7500: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801E7504: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7508: lwc1        $f18, 0x30($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801E750C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801E7510: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x801E7514: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7518: lwc1        $f10, -0x3EBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3EBC);
    // 0x801E751C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7520: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801E7524: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801E7528: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801E752C: swc1        $f16, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f16.u32l;
    // 0x801E7530: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7534: lwc1        $f4, -0x3EB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3EB8);
    // 0x801E7538: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801E753C: lwc1        $f18, 0x38($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801E7540: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801E7544: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
L_801E7548:
    // 0x801E7548: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801E754C:
    // 0x801E754C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E7550: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E7554: jr          $ra
    // 0x801E7558: nop

    return;
    // 0x801E7558: nop

;}
RECOMP_FUNC void M25_FUN_801e755c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E755C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E7560: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E7564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E7568: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E756C: lui         $a1, 0x205
    ctx->r5 = S32(0X205 << 16);
    // 0x801E7570: ori         $a1, $a1, 0x45E0
    ctx->r5 = ctx->r5 | 0X45E0;
    // 0x801E7574: jal         0x801C0B8C
    // 0x801E7578: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E7578: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E757C: beq         $v0, $zero, L_801E75C4
    if (ctx->r2 == 0) {
        // 0x801E7580: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801E75C4;
    }
    // 0x801E7580: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E7584: lui         $at, 0xC341
    ctx->r1 = S32(0XC341 << 16);
    // 0x801E7588: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E758C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7590: lui         $a2, 0xC1C1
    ctx->r6 = S32(0XC1C1 << 16);
    // 0x801E7594: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801E7598: jal         0x8038BD50
    // 0x801E759C: lwc1        $f14, -0x3EB4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3EB4);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E759C: lwc1        $f14, -0x3EB4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3EB4);
    after_1:
    // 0x801E75A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E75A4: lwc1        $f12, -0x3EB0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3EB0);
    // 0x801E75A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E75AC: lui         $a2, 0xC0B3
    ctx->r6 = S32(0XC0B3 << 16);
    // 0x801E75B0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E75B4: jal         0x8038BD88
    // 0x801E75B8: lwc1        $f14, -0x3EAC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3EAC);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E75B8: lwc1        $f14, -0x3EAC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3EAC);
    after_2:
    // 0x801E75BC: b           L_801E7620
    // 0x801E75C0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801E7620;
    // 0x801E75C0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801E75C4:
    // 0x801E75C4: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E75C8: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E75CC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E75D0: lwc1        $f6, -0x3EA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3EA8);
    // 0x801E75D4: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801E75D8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E75DC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801E75E0: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801E75E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E75E8: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801E75EC: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801E75F0: lwc1        $f16, -0x3EA4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3EA4);
    // 0x801E75F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E75F8: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801E75FC: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801E7600: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E7604: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801E7608: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E760C: lwc1        $f6, -0x3EA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3EA0);
    // 0x801E7610: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801E7614: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801E7618: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E761C: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
L_801E7620:
    // 0x801E7620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E7624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E7628: jr          $ra
    // 0x801E762C: nop

    return;
    // 0x801E762C: nop

;}
RECOMP_FUNC void M25_FUN_801e7630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E7630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E7634: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E7638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E763C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E7640: lui         $a1, 0x2A5
    ctx->r5 = S32(0X2A5 << 16);
    // 0x801E7644: ori         $a1, $a1, 0x7D80
    ctx->r5 = ctx->r5 | 0X7D80;
    // 0x801E7648: jal         0x801C0B8C
    // 0x801E764C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E764C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E7650: beq         $v0, $zero, L_801E7660
    if (ctx->r2 == 0) {
        // 0x801E7654: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E7660;
    }
    // 0x801E7654: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E7658: b           L_801E7970
    // 0x801E765C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801E7970;
    // 0x801E765C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801E7660:
    // 0x801E7660: lui         $a1, 0x28E
    ctx->r5 = S32(0X28E << 16);
    // 0x801E7664: jal         0x801C0B8C
    // 0x801E7668: ori         $a1, $a1, 0x9A20
    ctx->r5 = ctx->r5 | 0X9A20;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801E7668: ori         $a1, $a1, 0x9A20
    ctx->r5 = ctx->r5 | 0X9A20;
    after_1:
    // 0x801E766C: beql        $v0, $zero, L_801E7784
    if (ctx->r2 == 0) {
        // 0x801E7670: lui         $a1, 0x242
        ctx->r5 = S32(0X242 << 16);
            goto L_801E7784;
    }
    goto skip_0;
    // 0x801E7670: lui         $a1, 0x242
    ctx->r5 = S32(0X242 << 16);
    skip_0:
    // 0x801E7674: jal         0x801C0B2C
    // 0x801E7678: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_2;
    // 0x801E7678: nop

    after_2:
    // 0x801E767C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E7680: jal         0x80034C24
    // 0x801E7684: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801E7684: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801E7688: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E768C: ldc1        $f4, -0x3E98($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3E98);
    // 0x801E7690: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7694: ldc1        $f8, -0x3E90($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3E90);
    // 0x801E7698: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E769C: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x801E76A0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E76A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E76A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E76AC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801E76B0: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x801E76B4: lw          $t6, 0xE8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XE8);
    // 0x801E76B8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801E76BC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E76C0: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E76C4: ldc1        $f6, -0x3E88($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3E88);
    // 0x801E76C8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E76CC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E76D0: ldc1        $f10, -0x3E80($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3E80);
    // 0x801E76D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E76D8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E76DC: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E76E0: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E76E4: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E76E8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E76EC: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801E76F0: ldc1        $f4, -0x3E78($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3E78);
    // 0x801E76F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E76F8: ldc1        $f8, -0x3E70($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3E70);
    // 0x801E76FC: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801E7700: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x801E7704: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801E7708: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801E770C: lw          $t8, 0xE8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XE8);
    // 0x801E7710: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7714: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801E7718: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E771C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E7720: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E7724: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801E7728: ldc1        $f6, -0x3E68($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3E68);
    // 0x801E772C: lw          $t0, 0xE8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XE8);
    // 0x801E7730: lui         $at, 0xC345
    ctx->r1 = S32(0XC345 << 16);
    // 0x801E7734: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801E7738: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E773C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801E7740: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7744: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E7748: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801E774C: lw          $t2, 0xE8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XE8);
    // 0x801E7750: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E7754: swc1        $f16, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f16.u32l;
    // 0x801E7758: lw          $t4, 0xE8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XE8);
    // 0x801E775C: lwc1        $f18, -0x3E60($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3E60);
    // 0x801E7760: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7764: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E7768: swc1        $f18, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f18.u32l;
    // 0x801E776C: lw          $t6, 0xE8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XE8);
    // 0x801E7770: lwc1        $f4, -0x3E5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3E5C);
    // 0x801E7774: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E7778: b           L_801E7970
    // 0x801E777C: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
        goto L_801E7970;
    // 0x801E777C: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
    // 0x801E7780: lui         $a1, 0x242
    ctx->r5 = S32(0X242 << 16);
L_801E7784:
    // 0x801E7784: ori         $a1, $a1, 0x4EE0
    ctx->r5 = ctx->r5 | 0X4EE0;
    // 0x801E7788: jal         0x801C0B8C
    // 0x801E778C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_4;
    // 0x801E778C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_4:
    // 0x801E7790: beq         $v0, $zero, L_801E78D4
    if (ctx->r2 == 0) {
        // 0x801E7794: nop
    
            goto L_801E78D4;
    }
    // 0x801E7794: nop

    // 0x801E7798: jal         0x801C0B2C
    // 0x801E779C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801E779C: nop

    after_5:
    // 0x801E77A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E77A4: jal         0x80034C24
    // 0x801E77A8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_6;
    // 0x801E77A8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_6:
    // 0x801E77AC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E77B0: ldc1        $f12, -0x3E58($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, -0X3E58);
    // 0x801E77B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E77B8: ldc1        $f6, -0x3E50($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3E50);
    // 0x801E77BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E77C0: ldc1        $f10, -0x3E48($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3E48);
    // 0x801E77C4: div.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x801E77C8: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801E77CC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801E77D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801E77D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E77D8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801E77DC: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x801E77E0: lw          $t8, 0xE8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XE8);
    // 0x801E77E4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801E77E8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E77EC: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x801E77F0: ldc1        $f8, -0x3E40($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3E40);
    // 0x801E77F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E77F8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E77FC: ldc1        $f16, -0x3E38($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3E38);
    // 0x801E7800: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7804: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801E7808: div.d       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x801E780C: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801E7810: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801E7814: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E7818: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x801E781C: swc1        $f4, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f4.u32l;
    // 0x801E7820: ldc1        $f6, -0x3E30($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3E30);
    // 0x801E7824: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7828: ldc1        $f10, -0x3E28($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3E28);
    // 0x801E782C: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E7830: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E7834: lw          $t0, 0xE8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XE8);
    // 0x801E7838: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E783C: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801E7840: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E7844: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E7848: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E784C: swc1        $f18, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f18.u32l;
    // 0x801E7850: ldc1        $f8, -0x3E20($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3E20);
    // 0x801E7854: lw          $t2, 0xE8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XE8);
    // 0x801E7858: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E785C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E7860: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E7864: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E7868: swc1        $f16, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f16.u32l;
    // 0x801E786C: ldc1        $f18, -0x3E18($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3E18);
    // 0x801E7870: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7874: ldc1        $f6, -0x3E10($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3E10);
    // 0x801E7878: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801E787C: lw          $t4, 0xE8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XE8);
    // 0x801E7880: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7884: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E7888: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801E788C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E7890: swc1        $f10, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f10.u32l;
    // 0x801E7894: ldc1        $f16, -0x3E08($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3E08);
    // 0x801E7898: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E789C: ldc1        $f4, -0x3E00($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3E00);
    // 0x801E78A0: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801E78A4: lw          $t6, 0xE8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XE8);
    // 0x801E78A8: mul.d       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x801E78AC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E78B0: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801E78B4: add.d       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = ctx->f10.d + ctx->f12.d;
    // 0x801E78B8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E78BC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E78C0: swc1        $f8, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f8.u32l;
    // 0x801E78C4: lw          $t8, 0xE8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XE8);
    // 0x801E78C8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E78CC: b           L_801E7970
    // 0x801E78D0: swc1        $f18, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f18.u32l;
        goto L_801E7970;
    // 0x801E78D0: swc1        $f18, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f18.u32l;
L_801E78D4:
    // 0x801E78D4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801E78D8: addiu       $a1, $a1, -0x4410
    ctx->r5 = ADD32(ctx->r5, -0X4410);
    // 0x801E78DC: lw          $t0, 0xE8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XE8);
    // 0x801E78E0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E78E4: lwc1        $f6, -0x3DF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3DF8);
    // 0x801E78E8: lw          $a0, 0x2C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X2C);
    // 0x801E78EC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E78F0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801E78F4: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x801E78F8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E78FC: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x801E7900: lw          $t1, 0xE8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XE8);
    // 0x801E7904: lwc1        $f16, -0x3DF4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3DF4);
    // 0x801E7908: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E790C: lw          $a0, 0x2C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X2C);
    // 0x801E7910: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x801E7914: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E7918: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x801E791C: lw          $t2, 0xE8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XE8);
    // 0x801E7920: lwc1        $f6, -0x3DF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3DF0);
    // 0x801E7924: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7928: lw          $a0, 0x2C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X2C);
    // 0x801E792C: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x801E7930: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E7934: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x801E7938: lw          $t3, 0xE8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XE8);
    // 0x801E793C: lw          $a0, 0x2C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X2C);
    // 0x801E7940: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x801E7944: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x801E7948: lw          $t4, 0xE8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XE8);
    // 0x801E794C: lw          $a0, 0x2C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X2C);
    // 0x801E7950: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x801E7954: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
    // 0x801E7958: lw          $t5, 0xE8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0XE8);
    // 0x801E795C: lwc1        $f4, -0x3DEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3DEC);
    // 0x801E7960: lw          $a0, 0x2C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X2C);
    // 0x801E7964: lwc1        $f18, 0x44($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X44);
    // 0x801E7968: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801E796C: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
L_801E7970:
    // 0x801E7970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E7974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E7978: jr          $ra
    // 0x801E797C: nop

    return;
    // 0x801E797C: nop

;}
RECOMP_FUNC void M25_FUN_801e7980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E7980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E7984: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E7988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E798C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E7990: lui         $a1, 0x2F1
    ctx->r5 = S32(0X2F1 << 16);
    // 0x801E7994: ori         $a1, $a1, 0xC8C0
    ctx->r5 = ctx->r5 | 0XC8C0;
    // 0x801E7998: jal         0x801C0B8C
    // 0x801E799C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E799C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E79A0: beq         $v0, $zero, L_801E79B8
    if (ctx->r2 == 0) {
        // 0x801E79A4: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E79B8;
    }
    // 0x801E79A4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E79A8: jal         0x8038C158
    // 0x801E79AC: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_1;
    // 0x801E79AC: nop

    after_1:
    // 0x801E79B0: b           L_801E7BA8
    // 0x801E79B4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801E7BA8;
    // 0x801E79B4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801E79B8:
    // 0x801E79B8: lui         $a1, 0x2D3
    ctx->r5 = S32(0X2D3 << 16);
    // 0x801E79BC: jal         0x801C0B8C
    // 0x801E79C0: ori         $a1, $a1, 0x4440
    ctx->r5 = ctx->r5 | 0X4440;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801E79C0: ori         $a1, $a1, 0x4440
    ctx->r5 = ctx->r5 | 0X4440;
    after_2:
    // 0x801E79C4: beq         $v0, $zero, L_801E7A0C
    if (ctx->r2 == 0) {
        // 0x801E79C8: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E7A0C;
    }
    // 0x801E79C8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E79CC: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
    // 0x801E79D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E79D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E79D8: lui         $a2, 0xC229
    ctx->r6 = S32(0XC229 << 16);
    // 0x801E79DC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E79E0: jal         0x8038BD50
    // 0x801E79E4: lwc1        $f14, -0x3DE8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3DE8);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_3;
    // 0x801E79E4: lwc1        $f14, -0x3DE8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3DE8);
    after_3:
    // 0x801E79E8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E79EC: lwc1        $f12, -0x3DE4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3DE4);
    // 0x801E79F0: lui         $at, 0x4168
    ctx->r1 = S32(0X4168 << 16);
    // 0x801E79F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E79F8: lui         $a2, 0xC13B
    ctx->r6 = S32(0XC13B << 16);
    // 0x801E79FC: jal         0x8038BD88
    // 0x801E7A00: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_4;
    // 0x801E7A00: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    after_4:
    // 0x801E7A04: b           L_801E7BA8
    // 0x801E7A08: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801E7BA8;
    // 0x801E7A08: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801E7A0C:
    // 0x801E7A0C: lui         $a1, 0x2C4
    ctx->r5 = S32(0X2C4 << 16);
    // 0x801E7A10: jal         0x801C0B8C
    // 0x801E7A14: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_5;
    // 0x801E7A14: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    after_5:
    // 0x801E7A18: beql        $v0, $zero, L_801E7B70
    if (ctx->r2 == 0) {
        // 0x801E7A1C: lui         $at, 0x429A
        ctx->r1 = S32(0X429A << 16);
            goto L_801E7B70;
    }
    goto skip_0;
    // 0x801E7A1C: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
    skip_0:
    // 0x801E7A20: jal         0x801C0B2C
    // 0x801E7A24: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_6;
    // 0x801E7A24: nop

    after_6:
    // 0x801E7A28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E7A2C: jal         0x80034C24
    // 0x801E7A30: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_7;
    // 0x801E7A30: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_7:
    // 0x801E7A34: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7A38: ldc1        $f4, -0x3DE0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3DE0);
    // 0x801E7A3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7A40: ldc1        $f8, -0x3DD8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3DD8);
    // 0x801E7A44: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E7A48: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801E7A4C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E7A50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E7A54: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7A58: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E7A5C: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E7A60: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7A64: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x801E7A68: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E7A6C: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E7A70: ldc1        $f6, -0x3DD0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3DD0);
    // 0x801E7A74: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7A78: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E7A7C: ldc1        $f10, -0x3DC8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3DC8);
    // 0x801E7A80: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7A84: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E7A88: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E7A8C: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E7A90: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E7A94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E7A98: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E7A9C: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801E7AA0: ldc1        $f4, -0x3DC0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3DC0);
    // 0x801E7AA4: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x801E7AA8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801E7AAC: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801E7AB0: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7AB4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7AB8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E7ABC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E7AC0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E7AC4: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801E7AC8: ldc1        $f18, -0x3DB8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3DB8);
    // 0x801E7ACC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7AD0: ldc1        $f6, -0x3DB0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3DB0);
    // 0x801E7AD4: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801E7AD8: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7ADC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7AE0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E7AE4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801E7AE8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E7AEC: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801E7AF0: ldc1        $f16, -0x3DA8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3DA8);
    // 0x801E7AF4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7AF8: ldc1        $f4, -0x3DA0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3DA0);
    // 0x801E7AFC: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801E7B00: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x801E7B04: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801E7B08: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801E7B0C: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7B10: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7B14: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801E7B18: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E7B1C: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801E7B20: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E7B24: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801E7B28: ldc1        $f18, -0x3D98($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3D98);
    // 0x801E7B2C: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7B30: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7B34: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801E7B38: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E7B3C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E7B40: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801E7B44: ldc1        $f8, -0x3D90($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3D90);
    // 0x801E7B48: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7B4C: ldc1        $f16, -0x3D88($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3D88);
    // 0x801E7B50: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801E7B54: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7B58: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E7B5C: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801E7B60: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E7B64: b           L_801E7BA8
    // 0x801E7B68: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
        goto L_801E7BA8;
    // 0x801E7B68: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
    // 0x801E7B6C: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
L_801E7B70:
    // 0x801E7B70: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E7B74: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7B78: lui         $a2, 0xC229
    ctx->r6 = S32(0XC229 << 16);
    // 0x801E7B7C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E7B80: jal         0x8038BD50
    // 0x801E7B84: lwc1        $f14, -0x3D80($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D80);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_8;
    // 0x801E7B84: lwc1        $f14, -0x3D80($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D80);
    after_8:
    // 0x801E7B88: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7B8C: lwc1        $f12, -0x3D7C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3D7C);
    // 0x801E7B90: lui         $at, 0x4168
    ctx->r1 = S32(0X4168 << 16);
    // 0x801E7B94: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E7B98: lui         $a2, 0xC13B
    ctx->r6 = S32(0XC13B << 16);
    // 0x801E7B9C: jal         0x8038BD88
    // 0x801E7BA0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_9;
    // 0x801E7BA0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    after_9:
    // 0x801E7BA4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801E7BA8:
    // 0x801E7BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E7BAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E7BB0: jr          $ra
    // 0x801E7BB4: nop

    return;
    // 0x801E7BB4: nop

;}
RECOMP_FUNC void M25_FUN_801e7bb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E7BB8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801E7BBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801E7BC0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7BC4: lwc1        $f14, -0x3D78($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D78);
    // 0x801E7BC8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7BCC: lwc1        $f4, -0x3D74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3D74);
    // 0x801E7BD0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7BD4: lwc1        $f6, -0x3D70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3D70);
    // 0x801E7BD8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7BDC: lwc1        $f8, -0x3D6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3D6C);
    // 0x801E7BE0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7BE4: lwc1        $f10, -0x3D68($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3D68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e7be8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e7be8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E7BE8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801E7BEC: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x801E7BF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801E7BF4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7BF8: lwc1        $f18, -0x3D64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3D64);
    // 0x801E7BFC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7C00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E7C04: lwc1        $f4, -0x3D60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3D60);
    // 0x801E7C08: lui         $at, 0x4293
    ctx->r1 = S32(0X4293 << 16);
    // 0x801E7C0C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E7C10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E7C14: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7C18: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801E7C1C: lwc1        $f8, -0x3D5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3D5C);
    // 0x801E7C20: lui         $at, 0xC130
    ctx->r1 = S32(0XC130 << 16);
    // 0x801E7C24: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801E7C28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E7C2C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801E7C30: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E7C34: lui         $a2, 0x4280
    ctx->r6 = S32(0X4280 << 16);
    // 0x801E7C38: lui         $a3, 0x40FC
    ctx->r7 = S32(0X40FC << 16);
    // 0x801E7C3C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801E7C40: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801E7C44: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801E7C48: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E7C4C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801E7C50: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801E7C54: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801E7C58: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x801E7C5C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801E7C60: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801E7C64: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801E7C68: jal         0x8038C17C
    // 0x801E7C6C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_0;
    // 0x801E7C6C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801E7C70: beq         $v0, $zero, L_801E7CBC
    if (ctx->r2 == 0) {
        // 0x801E7C74: lui         $at, 0x42C9
        ctx->r1 = S32(0X42C9 << 16);
            goto L_801E7CBC;
    }
    // 0x801E7C74: lui         $at, 0x42C9
    ctx->r1 = S32(0X42C9 << 16);
    // 0x801E7C78: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E7C7C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7C80: lui         $a2, 0xC184
    ctx->r6 = S32(0XC184 << 16);
    // 0x801E7C84: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801E7C88: jal         0x8038BD50
    // 0x801E7C8C: lwc1        $f14, -0x3D58($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D58);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E7C8C: lwc1        $f14, -0x3D58($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D58);
    after_1:
    // 0x801E7C90: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7C94: lwc1        $f12, -0x3D54($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3D54);
    // 0x801E7C98: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7C9C: lwc1        $f14, -0x3D50($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D50);
    // 0x801E7CA0: jal         0x8038BD88
    // 0x801E7CA4: lui         $a2, 0xC138
    ctx->r6 = S32(0XC138 << 16);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E7CA4: lui         $a2, 0xC138
    ctx->r6 = S32(0XC138 << 16);
    after_2:
    // 0x801E7CA8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7CAC: jal         0x8038BE98
    // 0x801E7CB0: lwc1        $f12, -0x3D4C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3D4C);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_3;
    // 0x801E7CB0: lwc1        $f12, -0x3D4C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3D4C);
    after_3:
    // 0x801E7CB4: b           L_801E7CC0
    // 0x801E7CB8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801E7CC0;
    // 0x801E7CB8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801E7CBC:
    // 0x801E7CBC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801E7CC0:
    // 0x801E7CC0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801E7CC4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801E7CC8: jr          $ra
    // 0x801E7CCC: nop

    return;
    // 0x801E7CCC: nop

;}
RECOMP_FUNC void M25_FUN_801e7cd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E7CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E7CD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E7CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E7CDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E7CE0: lui         $a1, 0x3D0
    ctx->r5 = S32(0X3D0 << 16);
    // 0x801E7CE4: ori         $a1, $a1, 0x9000
    ctx->r5 = ctx->r5 | 0X9000;
    // 0x801E7CE8: jal         0x801C0B8C
    // 0x801E7CEC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E7CEC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E7CF0: beq         $v0, $zero, L_801E7D38
    if (ctx->r2 == 0) {
        // 0x801E7CF4: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801E7D38;
    }
    // 0x801E7CF4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E7CF8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7CFC: lwc1        $f12, -0x3D48($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3D48);
    // 0x801E7D00: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7D04: lui         $a2, 0xC16B
    ctx->r6 = S32(0XC16B << 16);
    // 0x801E7D08: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E7D0C: jal         0x8038BD50
    // 0x801E7D10: lwc1        $f14, -0x3D44($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D44);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E7D10: lwc1        $f14, -0x3D44($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D44);
    after_1:
    // 0x801E7D14: lui         $at, 0xC345
    ctx->r1 = S32(0XC345 << 16);
    // 0x801E7D18: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E7D1C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7D20: lui         $a2, 0xC0B9
    ctx->r6 = S32(0XC0B9 << 16);
    // 0x801E7D24: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801E7D28: jal         0x8038BD88
    // 0x801E7D2C: lwc1        $f14, -0x3D40($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D40);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E7D2C: lwc1        $f14, -0x3D40($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D40);
    after_2:
    // 0x801E7D30: b           L_801E7DE8
    // 0x801E7D34: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801E7DE8;
    // 0x801E7D34: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801E7D38:
    // 0x801E7D38: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E7D3C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7D40: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7D44: lwc1        $f6, -0x3D3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3D3C);
    // 0x801E7D48: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801E7D4C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7D50: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x801E7D54: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801E7D58: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E7D5C: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801E7D60: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7D64: lwc1        $f16, -0x3D38($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3D38);
    // 0x801E7D68: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7D6C: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801E7D70: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801E7D74: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E7D78: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801E7D7C: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7D80: lwc1        $f6, -0x3D34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3D34);
    // 0x801E7D84: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7D88: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801E7D8C: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801E7D90: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E7D94: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    // 0x801E7D98: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7D9C: lwc1        $f16, -0x3D30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3D30);
    // 0x801E7DA0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7DA4: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801E7DA8: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801E7DAC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E7DB0: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x801E7DB4: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7DB8: lwc1        $f6, -0x3D2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3D2C);
    // 0x801E7DBC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7DC0: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801E7DC4: lwc1        $f4, 0x40($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801E7DC8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E7DCC: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x801E7DD0: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7DD4: lwc1        $f16, -0x3D28($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3D28);
    // 0x801E7DD8: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801E7DDC: lwc1        $f10, 0x44($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801E7DE0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E7DE4: swc1        $f18, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f18.u32l;
L_801E7DE8:
    // 0x801E7DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E7DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E7DF0: jr          $ra
    // 0x801E7DF4: nop

    return;
    // 0x801E7DF4: nop

;}
RECOMP_FUNC void M25_FUN_801e7df8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E7DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E7DFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E7E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E7E04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E7E08: lui         $a1, 0x40D
    ctx->r5 = S32(0X40D << 16);
    // 0x801E7E0C: ori         $a1, $a1, 0x9900
    ctx->r5 = ctx->r5 | 0X9900;
    // 0x801E7E10: jal         0x801C0B8C
    // 0x801E7E14: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E7E14: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E7E18: beq         $v0, $zero, L_801E7E60
    if (ctx->r2 == 0) {
        // 0x801E7E1C: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801E7E60;
    }
    // 0x801E7E1C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E7E20: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7E24: lwc1        $f12, -0x3D24($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3D24);
    // 0x801E7E28: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7E2C: lui         $a2, 0xC220
    ctx->r6 = S32(0XC220 << 16);
    // 0x801E7E30: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E7E34: jal         0x8038BD50
    // 0x801E7E38: lwc1        $f14, -0x3D20($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D20);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E7E38: lwc1        $f14, -0x3D20($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D20);
    after_1:
    // 0x801E7E3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7E40: lwc1        $f12, -0x3D1C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3D1C);
    // 0x801E7E44: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7E48: lui         $a2, 0xC0B6
    ctx->r6 = S32(0XC0B6 << 16);
    // 0x801E7E4C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E7E50: jal         0x8038BD88
    // 0x801E7E54: lwc1        $f14, -0x3D18($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D18);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E7E54: lwc1        $f14, -0x3D18($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D18);
    after_2:
    // 0x801E7E58: b           L_801E7EBC
    // 0x801E7E5C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801E7EBC;
    // 0x801E7E5C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801E7E60:
    // 0x801E7E60: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E7E64: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7E68: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7E6C: lwc1        $f6, -0x3D14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3D14);
    // 0x801E7E70: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801E7E74: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7E78: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x801E7E7C: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801E7E80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E7E84: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801E7E88: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7E8C: lwc1        $f16, -0x3D10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3D10);
    // 0x801E7E90: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7E94: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801E7E98: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801E7E9C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E7EA0: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801E7EA4: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7EA8: lwc1        $f6, -0x3D0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3D0C);
    // 0x801E7EAC: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801E7EB0: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801E7EB4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E7EB8: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
L_801E7EBC:
    // 0x801E7EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E7EC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E7EC4: jr          $ra
    // 0x801E7EC8: nop

    return;
    // 0x801E7EC8: nop

;}
RECOMP_FUNC void M25_FUN_801e7ecc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E7ECC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E7ED0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E7ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E7ED8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E7EDC: lui         $a1, 0x44A
    ctx->r5 = S32(0X44A << 16);
    // 0x801E7EE0: ori         $a1, $a1, 0xA200
    ctx->r5 = ctx->r5 | 0XA200;
    // 0x801E7EE4: jal         0x801C0B8C
    // 0x801E7EE8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E7EE8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E7EEC: beq         $v0, $zero, L_801E7F30
    if (ctx->r2 == 0) {
        // 0x801E7EF0: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801E7F30;
    }
    // 0x801E7EF0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E7EF4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7EF8: lwc1        $f12, -0x3D08($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3D08);
    // 0x801E7EFC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7F00: lui         $a2, 0xC1A0
    ctx->r6 = S32(0XC1A0 << 16);
    // 0x801E7F04: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801E7F08: jal         0x8038BD50
    // 0x801E7F0C: lwc1        $f14, -0x3D04($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D04);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E7F0C: lwc1        $f14, -0x3D04($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3D04);
    after_1:
    // 0x801E7F10: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7F14: lwc1        $f12, -0x3D00($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3D00);
    // 0x801E7F18: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7F1C: lwc1        $f14, -0x3CFC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3CFC);
    // 0x801E7F20: jal         0x8038BD88
    // 0x801E7F24: lui         $a2, 0xC0A0
    ctx->r6 = S32(0XC0A0 << 16);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E7F24: lui         $a2, 0xC0A0
    ctx->r6 = S32(0XC0A0 << 16);
    after_2:
    // 0x801E7F28: b           L_801E7F8C
    // 0x801E7F2C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801E7F8C;
    // 0x801E7F2C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801E7F30:
    // 0x801E7F30: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E7F34: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7F38: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7F3C: lwc1        $f6, -0x3CF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3CF8);
    // 0x801E7F40: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801E7F44: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7F48: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x801E7F4C: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801E7F50: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E7F54: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801E7F58: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7F5C: lwc1        $f16, -0x3CF4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3CF4);
    // 0x801E7F60: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7F64: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801E7F68: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801E7F6C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E7F70: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801E7F74: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7F78: lwc1        $f6, -0x3CF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3CF0);
    // 0x801E7F7C: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801E7F80: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801E7F84: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E7F88: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
L_801E7F8C:
    // 0x801E7F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E7F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E7F94: jr          $ra
    // 0x801E7F98: nop

    return;
    // 0x801E7F98: nop

;}
RECOMP_FUNC void M25_FUN_801e7f9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E7F9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E7FA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E7FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E7FA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E7FAC: lui         $a1, 0x473
    ctx->r5 = S32(0X473 << 16);
    // 0x801E7FB0: ori         $a1, $a1, 0x52AA
    ctx->r5 = ctx->r5 | 0X52AA;
    // 0x801E7FB4: jal         0x801C0B8C
    // 0x801E7FB8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E7FB8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E7FBC: beq         $v0, $zero, L_801E7FD8
    if (ctx->r2 == 0) {
        // 0x801E7FC0: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801E7FD8;
    }
    // 0x801E7FC0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E7FC4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7FC8: jal         0x8038C158
    // 0x801E7FCC: sw          $zero, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = 0;
    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_1;
    // 0x801E7FCC: sw          $zero, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = 0;
    after_1:
    // 0x801E7FD0: b           L_801E8034
    // 0x801E7FD4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_801E8034;
    // 0x801E7FD4: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801E7FD8:
    // 0x801E7FD8: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E7FDC: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E7FE0: lui         $at, 0x3DC0
    ctx->r1 = S32(0X3DC0 << 16);
    // 0x801E7FE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E7FE8: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801E7FEC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E7FF0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x801E7FF4: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801E7FF8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E7FFC: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801E8000: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8004: lwc1        $f16, -0x3CEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3CEC);
    // 0x801E8008: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E800C: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801E8010: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801E8014: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E8018: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801E801C: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8020: lwc1        $f6, -0x3CE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3CE8);
    // 0x801E8024: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801E8028: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801E802C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E8030: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
L_801E8034:
    // 0x801E8034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E8038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E803C: jr          $ra
    // 0x801E8040: nop

    return;
    // 0x801E8040: nop

;}
RECOMP_FUNC void M25_FUN_801e8044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E8044: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801E8048: lw          $v0, -0x4C6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C6C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e804c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e804c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E804C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801E8050: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801E8054: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801E8058: beq         $v0, $zero, L_801E8080
    if (ctx->r2 == 0) {
        // 0x801E805C: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_801E8080;
    }
    // 0x801E805C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801E8060: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801E8064: beq         $v0, $at, L_801E8138
    if (ctx->r2 == ctx->r1) {
        // 0x801E8068: lui         $a2, 0xC358
        ctx->r6 = S32(0XC358 << 16);
            goto L_801E8138;
    }
    // 0x801E8068: lui         $a2, 0xC358
    ctx->r6 = S32(0XC358 << 16);
    // 0x801E806C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801E8070: beq         $v0, $at, L_801E81E0
    if (ctx->r2 == ctx->r1) {
        // 0x801E8074: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E81E0;
    }
    // 0x801E8074: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E8078: b           L_801E8314
    // 0x801E807C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_801E8314;
    // 0x801E807C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801E8080:
    // 0x801E8080: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8084: lwc1        $f0, -0x3CE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3CE4);
    // 0x801E8088: lui         $at, 0x4226
    ctx->r1 = S32(0X4226 << 16);
    // 0x801E808C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801E8090: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E8094: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E8098: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x801E809C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E80A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E80A4: lwc1        $f6, -0x3CE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3CE0);
    // 0x801E80A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E80AC: lwc1        $f8, -0x3CDC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3CDC);
    // 0x801E80B0: lui         $at, 0xC108
    ctx->r1 = S32(0XC108 << 16);
    // 0x801E80B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E80B8: lui         $at, 0xC325
    ctx->r1 = S32(0XC325 << 16);
    // 0x801E80BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E80C0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E80C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E80C8: lwc1        $f4, -0x3CD8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3CD8);
    // 0x801E80CC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E80D0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E80D4: lwc1        $f6, -0x3CD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3CD4);
    // 0x801E80D8: lui         $at, 0x4158
    ctx->r1 = S32(0X4158 << 16);
    // 0x801E80DC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801E80E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E80E4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E80E8: lui         $a2, 0xC356
    ctx->r6 = S32(0XC356 << 16);
    // 0x801E80EC: lui         $a3, 0x4138
    ctx->r7 = S32(0X4138 << 16);
    // 0x801E80F0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801E80F4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801E80F8: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x801E80FC: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x801E8100: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801E8104: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x801E8108: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x801E810C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801E8110: jal         0x8038C17C
    // 0x801E8114: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_0;
    // 0x801E8114: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801E8118: beql        $v0, $zero, L_801E8314
    if (ctx->r2 == 0) {
        // 0x801E811C: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_801E8314;
    }
    goto skip_0;
    // 0x801E811C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    skip_0:
    // 0x801E8120: jal         0x8038C158
    // 0x801E8124: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_1;
    // 0x801E8124: nop

    after_1:
    // 0x801E8128: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801E812C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8130: b           L_801E8310
    // 0x801E8134: sw          $t6, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r14;
        goto L_801E8310;
    // 0x801E8134: sw          $t6, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r14;
L_801E8138:
    // 0x801E8138: lui         $at, 0xC128
    ctx->r1 = S32(0XC128 << 16);
    // 0x801E813C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801E8140: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8144: lwc1        $f2, -0x3CD0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3CD0);
    // 0x801E8148: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E814C: lwc1        $f16, -0x3CCC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3CCC);
    // 0x801E8150: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E8154: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E8158: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E815C: lwc1        $f10, -0x3CC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3CC8);
    // 0x801E8160: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8164: lwc1        $f18, -0x3CC4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3CC4);
    // 0x801E8168: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E816C: lwc1        $f4, -0x3CC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3CC0);
    // 0x801E8170: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801E8174: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E8178: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E817C: lwc1        $f8, -0x3CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3CBC);
    // 0x801E8180: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8184: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801E8188: lwc1        $f10, -0x3CB8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3CB8);
    // 0x801E818C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E8190: lui         $a3, 0x4184
    ctx->r7 = S32(0X4184 << 16);
    // 0x801E8194: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801E8198: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801E819C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801E81A0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801E81A4: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x801E81A8: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x801E81AC: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x801E81B0: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x801E81B4: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801E81B8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x801E81BC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x801E81C0: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801E81C4: jal         0x8038C17C
    // 0x801E81C8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_2;
    // 0x801E81C8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801E81CC: beq         $v0, $zero, L_801E8310
    if (ctx->r2 == 0) {
        // 0x801E81D0: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_801E8310;
    }
    // 0x801E81D0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801E81D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E81D8: b           L_801E8310
    // 0x801E81DC: sw          $t7, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r15;
        goto L_801E8310;
    // 0x801E81DC: sw          $t7, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r15;
L_801E81E0:
    // 0x801E81E0: lui         $a1, 0x4B0
    ctx->r5 = S32(0X4B0 << 16);
    // 0x801E81E4: jal         0x801C0B8C
    // 0x801E81E8: ori         $a1, $a1, 0x5BAA
    ctx->r5 = ctx->r5 | 0X5BAA;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801E81E8: ori         $a1, $a1, 0x5BAA
    ctx->r5 = ctx->r5 | 0X5BAA;
    after_3:
    // 0x801E81EC: beq         $v0, $zero, L_801E8310
    if (ctx->r2 == 0) {
        // 0x801E81F0: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801E8310;
    }
    // 0x801E81F0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801E81F4: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801E81F8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801E81FC: lui         $at, 0xC345
    ctx->r1 = S32(0XC345 << 16);
    // 0x801E8200: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E8204: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801E8208: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E820C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8210: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801E8214: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E8218: ori         $a1, $a1, 0x1F
    ctx->r5 = ctx->r5 | 0X1F;
    // 0x801E821C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801E8220: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801E8224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E8228: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801E822C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E8230: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801E8234: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801E8238: swc1        $f18, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f18.u32l;
    // 0x801E823C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801E8240: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801E8244: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E8248: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801E824C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801E8250: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801E8254: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x801E8258: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E825C: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x801E8260: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801E8264: lwc1        $f6, -0x3CB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3CB4);
    // 0x801E8268: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801E826C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801E8270: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E8274: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801E8278: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801E827C: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801E8280: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801E8284: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801E8288: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x801E828C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801E8290: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801E8294: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801E8298: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801E829C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801E82A0: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x801E82A4: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801E82A8: sh          $t9, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r25;
    // 0x801E82AC: jal         0x801CC470
    // 0x801E82B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_4;
    // 0x801E82B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x801E82B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E82B8: sw          $zero, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = 0;
    // 0x801E82BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E82C0: jal         0x8038BE98
    // 0x801E82C4: lwc1        $f12, -0x3CB0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3CB0);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_5;
    // 0x801E82C4: lwc1        $f12, -0x3CB0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3CB0);
    after_5:
    // 0x801E82C8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E82CC: lwc1        $f12, -0x3CAC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3CAC);
    // 0x801E82D0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E82D4: lui         $a2, 0xC191
    ctx->r6 = S32(0XC191 << 16);
    // 0x801E82D8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801E82DC: jal         0x8038BD50
    // 0x801E82E0: lwc1        $f14, -0x3CA8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3CA8);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_6;
    // 0x801E82E0: lwc1        $f14, -0x3CA8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3CA8);
    after_6:
    // 0x801E82E4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E82E8: lwc1        $f12, -0x3CA4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3CA4);
    // 0x801E82EC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E82F0: lui         $a2, 0xC0A9
    ctx->r6 = S32(0XC0A9 << 16);
    // 0x801E82F4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801E82F8: jal         0x8038BD88
    // 0x801E82FC: lwc1        $f14, -0x3CA0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3CA0);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_7;
    // 0x801E82FC: lwc1        $f14, -0x3CA0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3CA0);
    after_7:
    // 0x801E8300: jal         0x8038C158
    // 0x801E8304: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_8;
    // 0x801E8304: nop

    after_8:
    // 0x801E8308: b           L_801E8314
    // 0x801E830C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_801E8314;
    // 0x801E830C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_801E8310:
    // 0x801E8310: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801E8314:
    // 0x801E8314: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801E8318: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801E831C: jr          $ra
    // 0x801E8320: nop

    return;
    // 0x801E8320: nop

;}
RECOMP_FUNC void M25_FUN_801e8324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E8324: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801E8328: addiu       $t0, $t0, -0x4C6C
    ctx->r8 = ADD32(ctx->r8, -0X4C6C);
    // 0x801E832C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e8330(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e8330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E8330: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801E8334: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801E8338: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x801E833C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801E8340: beq         $at, $zero, L_801E8704
    if (ctx->r1 == 0) {
        // 0x801E8344: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_801E8704;
    }
    // 0x801E8344: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801E8348: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E834C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8350: addu        $at, $at, $t6
    gpr jr_addend_801E8358 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801E8354: lw          $t6, -0x3C9C($at)
    ctx->r14 = ADD32(ctx->r1, -0X3C9C);
    // 0x801E8358: jr          $t6
    // 0x801E835C: nop

    switch (jr_addend_801E8358 >> 2) {
        case 0: goto L_801E8360; break;
        case 1: goto L_801E8428; break;
        case 2: goto L_801E84E8; break;
        case 3: goto L_801E859C; break;
        case 4: goto L_801E85CC; break;
        case 5: goto L_801E861C; break;
        case 6: goto L_801E8648; break;
        case 7: goto L_801E8698; break;
        case 8: goto L_801E86C4; break;
        default: switch_error(__func__, 0x801E8358, 0x801FC364);
    }
    // 0x801E835C: nop

L_801E8360:
    // 0x801E8360: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8364: lwc1        $f0, -0x3C78($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3C78);
    // 0x801E8368: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x801E836C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801E8370: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8374: lwc1        $f14, -0x3C74($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3C74);
    // 0x801E8378: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E837C: lwc1        $f4, -0x3C70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3C70);
    // 0x801E8380: lui         $at, 0xC33D
    ctx->r1 = S32(0XC33D << 16);
    // 0x801E8384: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E8388: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E838C: lwc1        $f8, -0x3C6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3C6C);
    // 0x801E8390: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8394: lwc1        $f10, -0x3C68($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3C68);
    // 0x801E8398: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E839C: lwc1        $f16, -0x3C64($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3C64);
    // 0x801E83A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E83A4: lwc1        $f18, -0x3C60($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3C60);
    // 0x801E83A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E83AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E83B0: lwc1        $f4, -0x3C5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3C5C);
    // 0x801E83B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E83B8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E83BC: lwc1        $f6, -0x3C58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3C58);
    // 0x801E83C0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E83C4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801E83C8: lwc1        $f8, -0x3C54($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3C54);
    // 0x801E83CC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E83D0: lui         $a2, 0xC33F
    ctx->r6 = S32(0XC33F << 16);
    // 0x801E83D4: lui         $a3, 0x40DC
    ctx->r7 = S32(0X40DC << 16);
    // 0x801E83D8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801E83DC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801E83E0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801E83E4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801E83E8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x801E83EC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801E83F0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801E83F4: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x801E83F8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801E83FC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801E8400: jal         0x8038C17C
    // 0x801E8404: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_0;
    // 0x801E8404: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801E8408: beql        $v0, $zero, L_801E8708
    if (ctx->r2 == 0) {
        // 0x801E840C: addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
            goto L_801E8708;
    }
    goto skip_0;
    // 0x801E840C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    skip_0:
    // 0x801E8410: jal         0x8038C158
    // 0x801E8414: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_1;
    // 0x801E8414: nop

    after_1:
    // 0x801E8418: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801E841C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8420: b           L_801E8704
    // 0x801E8424: sw          $t7, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r15;
        goto L_801E8704;
    // 0x801E8424: sw          $t7, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r15;
L_801E8428:
    // 0x801E8428: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E842C: lwc1        $f0, -0x3C50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3C50);
    // 0x801E8430: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8434: lwc1        $f2, -0x3C4C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3C4C);
    // 0x801E8438: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E843C: lwc1        $f14, -0x3C48($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3C48);
    // 0x801E8440: lui         $at, 0xC130
    ctx->r1 = S32(0XC130 << 16);
    // 0x801E8444: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E8448: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E844C: lwc1        $f16, -0x3C44($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3C44);
    // 0x801E8450: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8454: lwc1        $f18, -0x3C40($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3C40);
    // 0x801E8458: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E845C: lwc1        $f4, -0x3C3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3C3C);
    // 0x801E8460: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8464: lwc1        $f6, -0x3C38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3C38);
    // 0x801E8468: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E846C: lwc1        $f8, -0x3C34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3C34);
    // 0x801E8470: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8474: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801E8478: lwc1        $f10, -0x3C30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3C30);
    // 0x801E847C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8480: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801E8484: lwc1        $f16, -0x3C2C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3C2C);
    // 0x801E8488: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E848C: lui         $a2, 0xC352
    ctx->r6 = S32(0XC352 << 16);
    // 0x801E8490: lui         $a3, 0x4188
    ctx->r7 = S32(0X4188 << 16);
    // 0x801E8494: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801E8498: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E849C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801E84A0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801E84A4: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x801E84A8: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x801E84AC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801E84B0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801E84B4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x801E84B8: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x801E84BC: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x801E84C0: jal         0x8038C17C
    // 0x801E84C4: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_2;
    // 0x801E84C4: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x801E84C8: beql        $v0, $zero, L_801E8708
    if (ctx->r2 == 0) {
        // 0x801E84CC: addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
            goto L_801E8708;
    }
    goto skip_1;
    // 0x801E84CC: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    skip_1:
    // 0x801E84D0: jal         0x8038C158
    // 0x801E84D4: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_3;
    // 0x801E84D4: nop

    after_3:
    // 0x801E84D8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801E84DC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E84E0: b           L_801E8704
    // 0x801E84E4: sw          $t8, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r24;
        goto L_801E8704;
    // 0x801E84E4: sw          $t8, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r24;
L_801E84E8:
    // 0x801E84E8: lui         $at, 0x41CC
    ctx->r1 = S32(0X41CC << 16);
    // 0x801E84EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801E84F0: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x801E84F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801E84F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E84FC: lwc1        $f14, -0x3C28($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3C28);
    // 0x801E8500: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8504: lwc1        $f18, -0x3C24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3C24);
    // 0x801E8508: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E850C: lwc1        $f4, -0x3C20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3C20);
    // 0x801E8510: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8514: lwc1        $f6, -0x3C1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3C1C);
    // 0x801E8518: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E851C: lwc1        $f8, -0x3C18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3C18);
    // 0x801E8520: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8524: lwc1        $f10, -0x3C14($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3C14);
    // 0x801E8528: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E852C: lwc1        $f16, -0x3C10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3C10);
    // 0x801E8530: lui         $at, 0xC33C
    ctx->r1 = S32(0XC33C << 16);
    // 0x801E8534: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801E8538: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E853C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8540: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801E8544: lwc1        $f4, -0x3C0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3C0C);
    // 0x801E8548: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E854C: lui         $a2, 0xC334
    ctx->r6 = S32(0XC334 << 16);
    // 0x801E8550: lui         $a3, 0x418A
    ctx->r7 = S32(0X418A << 16);
    // 0x801E8554: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x801E8558: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E855C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801E8560: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801E8564: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x801E8568: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x801E856C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801E8570: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801E8574: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801E8578: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x801E857C: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x801E8580: jal         0x8038C17C
    // 0x801E8584: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_4;
    // 0x801E8584: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x801E8588: beq         $v0, $zero, L_801E8704
    if (ctx->r2 == 0) {
        // 0x801E858C: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_801E8704;
    }
    // 0x801E858C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801E8590: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8594: b           L_801E8704
    // 0x801E8598: sw          $t9, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r25;
        goto L_801E8704;
    // 0x801E8598: sw          $t9, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r25;
L_801E859C:
    // 0x801E859C: lui         $a1, 0x4FC
    ctx->r5 = S32(0X4FC << 16);
    // 0x801E85A0: ori         $a1, $a1, 0xA6EA
    ctx->r5 = ctx->r5 | 0XA6EA;
    // 0x801E85A4: jal         0x801C0B8C
    // 0x801E85A8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_5;
    // 0x801E85A8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_5:
    // 0x801E85AC: beq         $v0, $zero, L_801E8704
    if (ctx->r2 == 0) {
        // 0x801E85B0: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E8704;
    }
    // 0x801E85B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E85B4: jal         0x8038BE98
    // 0x801E85B8: lwc1        $f12, -0x3C08($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3C08);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_6;
    // 0x801E85B8: lwc1        $f12, -0x3C08($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3C08);
    after_6:
    // 0x801E85BC: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x801E85C0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E85C4: b           L_801E8704
    // 0x801E85C8: sw          $t1, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r9;
        goto L_801E8704;
    // 0x801E85C8: sw          $t1, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r9;
L_801E85CC:
    // 0x801E85CC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E85D0: lwc1        $f12, -0x3C04($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3C04);
    // 0x801E85D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E85D8: lui         $a2, 0xC1A0
    ctx->r6 = S32(0XC1A0 << 16);
    // 0x801E85DC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801E85E0: jal         0x8038BD50
    // 0x801E85E4: lwc1        $f14, -0x3C00($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3C00);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_7;
    // 0x801E85E4: lwc1        $f14, -0x3C00($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3C00);
    after_7:
    // 0x801E85E8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E85EC: lwc1        $f12, -0x3BFC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3BFC);
    // 0x801E85F0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E85F4: lui         $a2, 0xC0AC
    ctx->r6 = S32(0XC0AC << 16);
    // 0x801E85F8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801E85FC: jal         0x8038BD88
    // 0x801E8600: lwc1        $f14, -0x3BF8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BF8);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_8;
    // 0x801E8600: lwc1        $f14, -0x3BF8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BF8);
    after_8:
    // 0x801E8604: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x801E8608: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E860C: sw          $t2, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r10;
    // 0x801E8610: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8614: b           L_801E8704
    // 0x801E8618: sw          $zero, -0x4C68($at)
    MEM_W(-0X4C68, ctx->r1) = 0;
        goto L_801E8704;
    // 0x801E8618: sw          $zero, -0x4C68($at)
    MEM_W(-0X4C68, ctx->r1) = 0;
L_801E861C:
    // 0x801E861C: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801E8620: lw          $v1, -0x4C68($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C68);
    // 0x801E8624: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8628: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x801E862C: slti        $v0, $v1, 0x7
    ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x801E8630: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x801E8634: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801E8638: beq         $v0, $zero, L_801E8704
    if (ctx->r2 == 0) {
        // 0x801E863C: sw          $v1, -0x4C68($at)
        MEM_W(-0X4C68, ctx->r1) = ctx->r3;
            goto L_801E8704;
    }
    // 0x801E863C: sw          $v1, -0x4C68($at)
    MEM_W(-0X4C68, ctx->r1) = ctx->r3;
    // 0x801E8640: b           L_801E8704
    // 0x801E8644: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
        goto L_801E8704;
    // 0x801E8644: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
L_801E8648:
    // 0x801E8648: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E864C: lwc1        $f12, -0x3BF4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3BF4);
    // 0x801E8650: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8654: lui         $a2, 0xC114
    ctx->r6 = S32(0XC114 << 16);
    // 0x801E8658: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801E865C: jal         0x8038BD50
    // 0x801E8660: lwc1        $f14, -0x3BF0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BF0);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_9;
    // 0x801E8660: lwc1        $f14, -0x3BF0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BF0);
    after_9:
    // 0x801E8664: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8668: lwc1        $f12, -0x3BEC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3BEC);
    // 0x801E866C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801E8670: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E8674: lui         $a2, 0xC121
    ctx->r6 = S32(0XC121 << 16);
    // 0x801E8678: jal         0x8038BD88
    // 0x801E867C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_10;
    // 0x801E867C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_10:
    // 0x801E8680: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x801E8684: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8688: sw          $t4, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r12;
    // 0x801E868C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8690: b           L_801E8704
    // 0x801E8694: sw          $zero, -0x4C68($at)
    MEM_W(-0X4C68, ctx->r1) = 0;
        goto L_801E8704;
    // 0x801E8694: sw          $zero, -0x4C68($at)
    MEM_W(-0X4C68, ctx->r1) = 0;
L_801E8698:
    // 0x801E8698: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801E869C: lw          $v1, -0x4C68($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C68);
    // 0x801E86A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E86A4: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x801E86A8: slti        $v0, $v1, 0x7
    ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x801E86AC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x801E86B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801E86B4: beq         $v0, $zero, L_801E8704
    if (ctx->r2 == 0) {
        // 0x801E86B8: sw          $v1, -0x4C68($at)
        MEM_W(-0X4C68, ctx->r1) = ctx->r3;
            goto L_801E8704;
    }
    // 0x801E86B8: sw          $v1, -0x4C68($at)
    MEM_W(-0X4C68, ctx->r1) = ctx->r3;
    // 0x801E86BC: b           L_801E8704
    // 0x801E86C0: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
        goto L_801E8704;
    // 0x801E86C0: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_801E86C4:
    // 0x801E86C4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E86C8: lwc1        $f12, -0x3BE8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3BE8);
    // 0x801E86CC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E86D0: lui         $a2, 0xC2A8
    ctx->r6 = S32(0XC2A8 << 16);
    // 0x801E86D4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801E86D8: jal         0x8038BD50
    // 0x801E86DC: lwc1        $f14, -0x3BE4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BE4);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_11;
    // 0x801E86DC: lwc1        $f14, -0x3BE4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BE4);
    after_11:
    // 0x801E86E0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E86E4: lwc1        $f12, -0x3BE0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3BE0);
    // 0x801E86E8: lui         $at, 0x4184
    ctx->r1 = S32(0X4184 << 16);
    // 0x801E86EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E86F0: lui         $a2, 0xC0A6
    ctx->r6 = S32(0XC0A6 << 16);
    // 0x801E86F4: jal         0x8038BD88
    // 0x801E86F8: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_12;
    // 0x801E86F8: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    after_12:
    // 0x801E86FC: b           L_801E8708
    // 0x801E8700: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_801E8708;
    // 0x801E8700: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_801E8704:
    // 0x801E8704: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_801E8708:
    // 0x801E8708: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801E870C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801E8710: jr          $ra
    // 0x801E8714: nop

    return;
    // 0x801E8714: nop

;}
RECOMP_FUNC void M25_FUN_801e8718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E8718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E871C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E8720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E8724: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E8728: lui         $a1, 0x508
    ctx->r5 = S32(0X508 << 16);
    // 0x801E872C: ori         $a1, $a1, 0x189A
    ctx->r5 = ctx->r5 | 0X189A;
    // 0x801E8730: jal         0x801C0B8C
    // 0x801E8734: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E8734: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E8738: beq         $v0, $zero, L_801E87CC
    if (ctx->r2 == 0) {
        // 0x801E873C: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E87CC;
    }
    // 0x801E873C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8740: lwc1        $f12, -0x3BDC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3BDC);
    // 0x801E8744: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8748: lwc1        $f14, -0x3BD8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BD8);
    // 0x801E874C: jal         0x8038BD50
    // 0x801E8750: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E8750: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    after_1:
    // 0x801E8754: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8758: lwc1        $f12, -0x3BD4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3BD4);
    // 0x801E875C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8760: lui         $a2, 0xC113
    ctx->r6 = S32(0XC113 << 16);
    // 0x801E8764: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E8768: jal         0x8038BD88
    // 0x801E876C: lwc1        $f14, -0x3BD0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BD0);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E876C: lwc1        $f14, -0x3BD0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BD0);
    after_2:
    // 0x801E8770: lui         $a1, 0x517
    ctx->r5 = S32(0X517 << 16);
    // 0x801E8774: ori         $a1, $a1, 0x5ADA
    ctx->r5 = ctx->r5 | 0X5ADA;
    // 0x801E8778: jal         0x801C0B8C
    // 0x801E877C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801E877C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_3:
    // 0x801E8780: beq         $v0, $zero, L_801E87C4
    if (ctx->r2 == 0) {
        // 0x801E8784: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E87C4;
    }
    // 0x801E8784: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8788: lwc1        $f12, -0x3BCC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3BCC);
    // 0x801E878C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8790: lui         $a2, 0xC17B
    ctx->r6 = S32(0XC17B << 16);
    // 0x801E8794: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E8798: jal         0x8038BD50
    // 0x801E879C: lwc1        $f14, -0x3BC8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BC8);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_4;
    // 0x801E879C: lwc1        $f14, -0x3BC8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BC8);
    after_4:
    // 0x801E87A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E87A4: lwc1        $f12, -0x3BC4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3BC4);
    // 0x801E87A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E87AC: lui         $a2, 0xC113
    ctx->r6 = S32(0XC113 << 16);
    // 0x801E87B0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E87B4: jal         0x8038BD88
    // 0x801E87B8: lwc1        $f14, -0x3BC0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BC0);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_5;
    // 0x801E87B8: lwc1        $f14, -0x3BC0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BC0);
    after_5:
    // 0x801E87BC: b           L_801E87D0
    // 0x801E87C0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_801E87D0;
    // 0x801E87C0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_801E87C4:
    // 0x801E87C4: b           L_801E87D0
    // 0x801E87C8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_801E87D0;
    // 0x801E87C8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_801E87CC:
    // 0x801E87CC: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_801E87D0:
    // 0x801E87D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E87D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E87D8: jr          $ra
    // 0x801E87DC: nop

    return;
    // 0x801E87DC: nop

;}
RECOMP_FUNC void M25_FUN_801e87e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E87E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E87E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E87E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E87EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E87F0: lui         $a1, 0x53D
    ctx->r5 = S32(0X53D << 16);
    // 0x801E87F4: ori         $a1, $a1, 0x807A
    ctx->r5 = ctx->r5 | 0X807A;
    // 0x801E87F8: jal         0x801C0B8C
    // 0x801E87FC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E87FC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E8800: beq         $v0, $zero, L_801E8850
    if (ctx->r2 == 0) {
        // 0x801E8804: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801E8850;
    }
    // 0x801E8804: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E8808: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E880C: lwc1        $f12, -0x3BBC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3BBC);
    // 0x801E8810: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8814: lui         $a2, 0xC119
    ctx->r6 = S32(0XC119 << 16);
    // 0x801E8818: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801E881C: jal         0x8038BD50
    // 0x801E8820: lwc1        $f14, -0x3BB8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BB8);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E8820: lwc1        $f14, -0x3BB8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3BB8);
    after_1:
    // 0x801E8824: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8828: lwc1        $f12, -0x3BB4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3BB4);
    // 0x801E882C: lui         $at, 0x4138
    ctx->r1 = S32(0X4138 << 16);
    // 0x801E8830: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E8834: lui         $a2, 0xC101
    ctx->r6 = S32(0XC101 << 16);
    // 0x801E8838: jal         0x8038BD88
    // 0x801E883C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E883C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_2:
    // 0x801E8840: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8844: sw          $zero, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = 0;
    // 0x801E8848: b           L_801E8900
    // 0x801E884C: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_801E8900;
    // 0x801E884C: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_801E8850:
    // 0x801E8850: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E8854: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8858: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E885C: lwc1        $f6, -0x3BB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3BB0);
    // 0x801E8860: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801E8864: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8868: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x801E886C: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801E8870: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E8874: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x801E8878: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801E887C: lwc1        $f16, -0x3BAC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3BAC);
    // 0x801E8880: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8884: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801E8888: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801E888C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E8890: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x801E8894: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8898: lwc1        $f6, -0x3BA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3BA8);
    // 0x801E889C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E88A0: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801E88A4: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801E88A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E88AC: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    // 0x801E88B0: lw          $t9, 0xE8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE8);
    // 0x801E88B4: lwc1        $f16, -0x3BA4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3BA4);
    // 0x801E88B8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E88BC: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801E88C0: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801E88C4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E88C8: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x801E88CC: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E88D0: lwc1        $f6, -0x3BA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3BA0);
    // 0x801E88D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E88D8: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801E88DC: lwc1        $f4, 0x40($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801E88E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E88E4: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x801E88E8: lw          $t1, 0xE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE8);
    // 0x801E88EC: lwc1        $f16, -0x3B9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3B9C);
    // 0x801E88F0: lw          $v1, 0x2C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X2C);
    // 0x801E88F4: lwc1        $f10, 0x44($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801E88F8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E88FC: swc1        $f18, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f18.u32l;
L_801E8900:
    // 0x801E8900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E8904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E8908: jr          $ra
    // 0x801E890C: nop

    return;
    // 0x801E890C: nop

;}
RECOMP_FUNC void M25_FUN_801e8910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E8910: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801E8914: lw          $v0, -0x4C6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C6C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e8918(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e8918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E8918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E891C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E8920: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E8924: beq         $v0, $zero, L_801E8940
    if (ctx->r2 == 0) {
        // 0x801E8928: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801E8940;
    }
    // 0x801E8928: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E892C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801E8930: beql        $v0, $at, L_801E89D8
    if (ctx->r2 == ctx->r1) {
        // 0x801E8934: lui         $a1, 0x54C
        ctx->r5 = S32(0X54C << 16);
            goto L_801E89D8;
    }
    goto skip_0;
    // 0x801E8934: lui         $a1, 0x54C
    ctx->r5 = S32(0X54C << 16);
    skip_0:
    // 0x801E8938: b           L_801E89F8
    // 0x801E893C: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_801E89F8;
    // 0x801E893C: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_801E8940:
    // 0x801E8940: lui         $a1, 0x548
    ctx->r5 = S32(0X548 << 16);
    // 0x801E8944: ori         $a1, $a1, 0x2EDA
    ctx->r5 = ctx->r5 | 0X2EDA;
    // 0x801E8948: jal         0x801C0B8C
    // 0x801E894C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E894C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E8950: beq         $v0, $zero, L_801E8978
    if (ctx->r2 == 0) {
        // 0x801E8954: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_801E8978;
    }
    // 0x801E8954: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801E8958: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801E895C: jal         0x8038C4D8
    // 0x801E8960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8038C4D8)(rdram, ctx);
        goto after_1;
    // 0x801E8960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x801E8964: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801E8968: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E896C: sw          $t6, -0x4C6C($at)
    MEM_W(-0X4C6C, ctx->r1) = ctx->r14;
    // 0x801E8970: b           L_801E89F8
    // 0x801E8974: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_801E89F8;
    // 0x801E8974: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_801E8978:
    // 0x801E8978: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801E897C: lw          $t7, 0xE8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XE8);
    // 0x801E8980: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8984: lwc1        $f6, -0x3B98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3B98);
    // 0x801E8988: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801E898C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8990: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801E8994: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E8998: swc1        $f8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f8.u32l;
    // 0x801E899C: lw          $t8, 0xE8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XE8);
    // 0x801E89A0: lwc1        $f16, -0x3B94($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3B94);
    // 0x801E89A4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E89A8: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801E89AC: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801E89B0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E89B4: swc1        $f18, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f18.u32l;
    // 0x801E89B8: lw          $t9, 0xE8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE8);
    // 0x801E89BC: lwc1        $f6, -0x3B90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3B90);
    // 0x801E89C0: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801E89C4: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801E89C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E89CC: b           L_801E89F4
    // 0x801E89D0: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
        goto L_801E89F4;
    // 0x801E89D0: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
    // 0x801E89D4: lui         $a1, 0x54C
    ctx->r5 = S32(0X54C << 16);
L_801E89D8:
    // 0x801E89D8: ori         $a1, $a1, 0xC2BA
    ctx->r5 = ctx->r5 | 0XC2BA;
    // 0x801E89DC: jal         0x801C0B8C
    // 0x801E89E0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801E89E0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_2:
    // 0x801E89E4: beql        $v0, $zero, L_801E89F8
    if (ctx->r2 == 0) {
        // 0x801E89E8: addiu       $v0, $zero, 0x11
        ctx->r2 = ADD32(0, 0X11);
            goto L_801E89F8;
    }
    goto skip_1;
    // 0x801E89E8: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    skip_1:
    // 0x801E89EC: b           L_801E89F8
    // 0x801E89F0: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_801E89F8;
    // 0x801E89F0: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_801E89F4:
    // 0x801E89F4: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_801E89F8:
    // 0x801E89F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E89FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E8A00: jr          $ra
    // 0x801E8A04: nop

    return;
    // 0x801E8A04: nop

;}
RECOMP_FUNC void M25_FUN_801e8a08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E8A08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E8A0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E8A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E8A14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E8A18: lui         $a1, 0x57A
    ctx->r5 = S32(0X57A << 16);
    // 0x801E8A1C: ori         $a1, $a1, 0x897A
    ctx->r5 = ctx->r5 | 0X897A;
    // 0x801E8A20: jal         0x801C0B8C
    // 0x801E8A24: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E8A24: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E8A28: beq         $v0, $zero, L_801E8A38
    if (ctx->r2 == 0) {
        // 0x801E8A2C: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E8A38;
    }
    // 0x801E8A2C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8A30: b           L_801E8A6C
    // 0x801E8A34: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_801E8A6C;
    // 0x801E8A34: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_801E8A38:
    // 0x801E8A38: lwc1        $f12, -0x3B8C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3B8C);
    // 0x801E8A3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8A40: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x801E8A44: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E8A48: jal         0x8038BD50
    // 0x801E8A4C: lwc1        $f14, -0x3B88($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3B88);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E8A4C: lwc1        $f14, -0x3B88($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3B88);
    after_1:
    // 0x801E8A50: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8A54: lwc1        $f12, -0x3B84($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3B84);
    // 0x801E8A58: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8A5C: lwc1        $f14, -0x3B80($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3B80);
    // 0x801E8A60: jal         0x8038BD88
    // 0x801E8A64: lui         $a2, 0xC130
    ctx->r6 = S32(0XC130 << 16);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E8A64: lui         $a2, 0xC130
    ctx->r6 = S32(0XC130 << 16);
    after_2:
    // 0x801E8A68: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_801E8A6C:
    // 0x801E8A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E8A70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E8A74: jr          $ra
    // 0x801E8A78: nop

    return;
    // 0x801E8A78: nop

;}
RECOMP_FUNC void M25_FUN_801e8a7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E8A7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E8A80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E8A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E8A88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E8A8C: lui         $a1, 0x599
    ctx->r5 = S32(0X599 << 16);
    // 0x801E8A90: ori         $a1, $a1, 0xDFA
    ctx->r5 = ctx->r5 | 0XDFA;
    // 0x801E8A94: jal         0x801C0B8C
    // 0x801E8A98: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E8A98: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E8A9C: beq         $v0, $zero, L_801E8AAC
    if (ctx->r2 == 0) {
        // 0x801E8AA0: nop
    
            goto L_801E8AAC;
    }
    // 0x801E8AA0: nop

    // 0x801E8AA4: b           L_801E8BD4
    // 0x801E8AA8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_801E8BD4;
    // 0x801E8AA8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_801E8AAC:
    // 0x801E8AAC: jal         0x801C0B2C
    // 0x801E8AB0: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801E8AB0: nop

    after_1:
    // 0x801E8AB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E8AB8: jal         0x80034C24
    // 0x801E8ABC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801E8ABC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801E8AC0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8AC4: ldc1        $f4, -0x3B78($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3B78);
    // 0x801E8AC8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8ACC: ldc1        $f8, -0x3B70($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3B70);
    // 0x801E8AD0: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E8AD4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E8AD8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E8ADC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E8AE0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8AE4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E8AE8: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E8AEC: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8AF0: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x801E8AF4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E8AF8: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E8AFC: ldc1        $f6, -0x3B68($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3B68);
    // 0x801E8B00: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8B04: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E8B08: ldc1        $f10, -0x3B60($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3B60);
    // 0x801E8B0C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8B10: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E8B14: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E8B18: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E8B1C: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E8B20: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E8B24: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801E8B28: ldc1        $f4, -0x3B58($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3B58);
    // 0x801E8B2C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8B30: ldc1        $f8, -0x3B50($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3B50);
    // 0x801E8B34: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801E8B38: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8B3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8B40: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E8B44: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E8B48: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E8B4C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x801E8B50: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801E8B54: ldc1        $f18, -0x3B48($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3B48);
    // 0x801E8B58: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8B5C: ldc1        $f6, -0x3B40($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3B40);
    // 0x801E8B60: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801E8B64: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801E8B68: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8B6C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8B70: mul.d       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801E8B74: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E8B78: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801E8B7C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E8B80: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801E8B84: ldc1        $f18, -0x3B38($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3B38);
    // 0x801E8B88: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8B8C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8B90: add.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f12.d + ctx->f18.d;
    // 0x801E8B94: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E8B98: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E8B9C: swc1        $f6, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f6.u32l;
    // 0x801E8BA0: ldc1        $f8, -0x3B30($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3B30);
    // 0x801E8BA4: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8BA8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8BAC: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x801E8BB0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E8BB4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E8BB8: swc1        $f16, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f16.u32l;
    // 0x801E8BBC: ldc1        $f18, -0x3B28($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3B28);
    // 0x801E8BC0: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8BC4: add.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f12.d + ctx->f18.d;
    // 0x801E8BC8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E8BCC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E8BD0: swc1        $f6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f6.u32l;
L_801E8BD4:
    // 0x801E8BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E8BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E8BDC: jr          $ra
    // 0x801E8BE0: nop

    return;
    // 0x801E8BE0: nop

;}
RECOMP_FUNC void M25_FUN_801e8be4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E8BE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E8BE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E8BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E8BF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E8BF4: lui         $a1, 0x5B7
    ctx->r5 = S32(0X5B7 << 16);
    // 0x801E8BF8: ori         $a1, $a1, 0x927A
    ctx->r5 = ctx->r5 | 0X927A;
    // 0x801E8BFC: jal         0x801C0B8C
    // 0x801E8C00: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E8C00: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E8C04: beq         $v0, $zero, L_801E8C14
    if (ctx->r2 == 0) {
        // 0x801E8C08: nop
    
            goto L_801E8C14;
    }
    // 0x801E8C08: nop

    // 0x801E8C0C: b           L_801E8D5C
    // 0x801E8C10: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_801E8D5C;
    // 0x801E8C10: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_801E8C14:
    // 0x801E8C14: jal         0x801C0B2C
    // 0x801E8C18: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801E8C18: nop

    after_1:
    // 0x801E8C1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E8C20: jal         0x80034C24
    // 0x801E8C24: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801E8C24: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801E8C28: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8C2C: ldc1        $f4, -0x3B20($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3B20);
    // 0x801E8C30: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8C34: ldc1        $f8, -0x3B18($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3B18);
    // 0x801E8C38: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E8C3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E8C40: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E8C44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E8C48: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8C4C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E8C50: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E8C54: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8C58: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x801E8C5C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E8C60: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E8C64: ldc1        $f6, -0x3B10($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3B10);
    // 0x801E8C68: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8C6C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E8C70: ldc1        $f10, -0x3B08($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3B08);
    // 0x801E8C74: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8C78: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E8C7C: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E8C80: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E8C84: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E8C88: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E8C8C: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801E8C90: ldc1        $f4, -0x3B00($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3B00);
    // 0x801E8C94: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8C98: ldc1        $f8, -0x3AF8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3AF8);
    // 0x801E8C9C: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801E8CA0: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8CA4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8CA8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E8CAC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E8CB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801E8CB4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E8CB8: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801E8CBC: ldc1        $f18, -0x3AF0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3AF0);
    // 0x801E8CC0: lui         $at, 0x402C
    ctx->r1 = S32(0X402C << 16);
    // 0x801E8CC4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801E8CC8: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801E8CCC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x801E8CD0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801E8CD4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801E8CD8: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8CDC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8CE0: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801E8CE4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E8CE8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801E8CEC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E8CF0: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801E8CF4: ldc1        $f4, -0x3AE8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3AE8);
    // 0x801E8CF8: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8CFC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8D00: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801E8D04: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E8D08: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E8D0C: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801E8D10: ldc1        $f10, -0x3AE0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3AE0);
    // 0x801E8D14: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8D18: ldc1        $f18, -0x3AD8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3AD8);
    // 0x801E8D1C: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801E8D20: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8D24: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8D28: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E8D2C: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801E8D30: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E8D34: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801E8D38: ldc1        $f8, -0x3AD0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3AD0);
    // 0x801E8D3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8D40: ldc1        $f16, -0x3AC8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3AC8);
    // 0x801E8D44: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801E8D48: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8D4C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E8D50: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801E8D54: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E8D58: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
L_801E8D5C:
    // 0x801E8D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E8D60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E8D64: jr          $ra
    // 0x801E8D68: nop

    return;
    // 0x801E8D68: nop

;}
RECOMP_FUNC void M25_FUN_801e8d6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E8D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E8D70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E8D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E8D78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E8D7C: lui         $a1, 0x5D6
    ctx->r5 = S32(0X5D6 << 16);
    // 0x801E8D80: ori         $a1, $a1, 0x16FA
    ctx->r5 = ctx->r5 | 0X16FA;
    // 0x801E8D84: jal         0x801C0B8C
    // 0x801E8D88: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E8D88: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E8D8C: beq         $v0, $zero, L_801E8D9C
    if (ctx->r2 == 0) {
        // 0x801E8D90: nop
    
            goto L_801E8D9C;
    }
    // 0x801E8D90: nop

    // 0x801E8D94: b           L_801E8ED0
    // 0x801E8D98: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_801E8ED0;
    // 0x801E8D98: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_801E8D9C:
    // 0x801E8D9C: jal         0x801C0B2C
    // 0x801E8DA0: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801E8DA0: nop

    after_1:
    // 0x801E8DA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E8DA8: jal         0x80034C24
    // 0x801E8DAC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801E8DAC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801E8DB0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8DB4: ldc1        $f4, -0x3AC0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3AC0);
    // 0x801E8DB8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8DBC: ldc1        $f8, -0x3AB8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3AB8);
    // 0x801E8DC0: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E8DC4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E8DC8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E8DCC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E8DD0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8DD4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E8DD8: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E8DDC: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8DE0: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // 0x801E8DE4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E8DE8: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E8DEC: ldc1        $f6, -0x3AB0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3AB0);
    // 0x801E8DF0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8DF4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E8DF8: ldc1        $f10, -0x3AA8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3AA8);
    // 0x801E8DFC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801E8E00: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E8E04: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E8E08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E8E0C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E8E10: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801E8E14: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E8E18: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E8E1C: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801E8E20: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E8E24: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801E8E28: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8E2C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E8E30: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E8E34: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801E8E38: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8E3C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E8E40: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E8E44: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x801E8E48: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801E8E4C: ldc1        $f18, -0x3AA0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3AA0);
    // 0x801E8E50: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8E54: ldc1        $f6, -0x3A98($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3A98);
    // 0x801E8E58: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801E8E5C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801E8E60: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8E64: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8E68: mul.d       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801E8E6C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E8E70: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801E8E74: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E8E78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E8E7C: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801E8E80: ldc1        $f18, -0x3A90($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3A90);
    // 0x801E8E84: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8E88: lui         $at, 0x402F
    ctx->r1 = S32(0X402F << 16);
    // 0x801E8E8C: add.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f12.d + ctx->f18.d;
    // 0x801E8E90: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801E8E94: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E8E98: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8E9C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E8EA0: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x801E8EA4: swc1        $f6, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f6.u32l;
    // 0x801E8EA8: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8EAC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E8EB0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E8EB4: swc1        $f16, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f16.u32l;
    // 0x801E8EB8: ldc1        $f18, -0x3A88($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3A88);
    // 0x801E8EBC: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8EC0: add.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f12.d + ctx->f18.d;
    // 0x801E8EC4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E8EC8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E8ECC: swc1        $f6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f6.u32l;
L_801E8ED0:
    // 0x801E8ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E8ED4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E8ED8: jr          $ra
    // 0x801E8EDC: nop

    return;
    // 0x801E8EDC: nop

;}
RECOMP_FUNC void M25_FUN_801e8ee0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E8EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E8EE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E8EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E8EEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E8EF0: lui         $a1, 0x5F4
    ctx->r5 = S32(0X5F4 << 16);
    // 0x801E8EF4: ori         $a1, $a1, 0x9B7A
    ctx->r5 = ctx->r5 | 0X9B7A;
    // 0x801E8EF8: jal         0x801C0B8C
    // 0x801E8EFC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E8EFC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E8F00: beq         $v0, $zero, L_801E8F20
    if (ctx->r2 == 0) {
        // 0x801E8F04: nop
    
            goto L_801E8F20;
    }
    // 0x801E8F04: nop

    // 0x801E8F08: jal         0x801C1424
    // 0x801E8F0C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801C1424)(rdram, ctx);
        goto after_1;
    // 0x801E8F0C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x801E8F10: beq         $v0, $zero, L_801E8F20
    if (ctx->r2 == 0) {
        // 0x801E8F14: nop
    
            goto L_801E8F20;
    }
    // 0x801E8F14: nop

    // 0x801E8F18: b           L_801E9068
    // 0x801E8F1C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_801E9068;
    // 0x801E8F1C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_801E8F20:
    // 0x801E8F20: jal         0x801C0B2C
    // 0x801E8F24: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_2;
    // 0x801E8F24: nop

    after_2:
    // 0x801E8F28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E8F2C: jal         0x80034C24
    // 0x801E8F30: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801E8F30: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801E8F34: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8F38: ldc1        $f4, -0x3A80($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3A80);
    // 0x801E8F3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8F40: ldc1        $f8, -0x3A78($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3A78);
    // 0x801E8F44: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E8F48: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E8F4C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E8F50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E8F54: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8F58: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E8F5C: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E8F60: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8F64: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x801E8F68: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E8F6C: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E8F70: ldc1        $f6, -0x3A70($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3A70);
    // 0x801E8F74: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8F78: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E8F7C: ldc1        $f10, -0x3A68($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3A68);
    // 0x801E8F80: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8F84: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E8F88: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E8F8C: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E8F90: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E8F94: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E8F98: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801E8F9C: ldc1        $f4, -0x3A60($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3A60);
    // 0x801E8FA0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8FA4: ldc1        $f8, -0x3A58($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3A58);
    // 0x801E8FA8: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801E8FAC: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8FB0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8FB4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E8FB8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E8FBC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E8FC0: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801E8FC4: ldc1        $f18, -0x3A50($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3A50);
    // 0x801E8FC8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8FCC: ldc1        $f6, -0x3A48($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3A48);
    // 0x801E8FD0: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801E8FD4: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E8FD8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8FDC: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E8FE0: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801E8FE4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E8FE8: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801E8FEC: ldc1        $f16, -0x3A40($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3A40);
    // 0x801E8FF0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E8FF4: ldc1        $f4, -0x3A38($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3A38);
    // 0x801E8FF8: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801E8FFC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x801E9000: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801E9004: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801E9008: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E900C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801E9010: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801E9014: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E9018: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801E901C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801E9020: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801E9024: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9028: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E902C: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801E9030: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801E9034: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9038: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E903C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E9040: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801E9044: ldc1        $f8, -0x3A30($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3A30);
    // 0x801E9048: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E904C: ldc1        $f16, -0x3A28($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3A28);
    // 0x801E9050: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801E9054: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9058: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E905C: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801E9060: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E9064: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
L_801E9068:
    // 0x801E9068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E906C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E9070: jr          $ra
    // 0x801E9074: nop

    return;
    // 0x801E9074: nop

;}
RECOMP_FUNC void M25_FUN_801e9078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E9078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E907C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E9080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E9084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E9088: lui         $a1, 0x613
    ctx->r5 = S32(0X613 << 16);
    // 0x801E908C: ori         $a1, $a1, 0x1FFA
    ctx->r5 = ctx->r5 | 0X1FFA;
    // 0x801E9090: jal         0x801C0B8C
    // 0x801E9094: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E9094: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E9098: beq         $v0, $zero, L_801E90A8
    if (ctx->r2 == 0) {
        // 0x801E909C: nop
    
            goto L_801E90A8;
    }
    // 0x801E909C: nop

    // 0x801E90A0: b           L_801E91B8
    // 0x801E90A4: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_801E91B8;
    // 0x801E90A4: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_801E90A8:
    // 0x801E90A8: jal         0x801C0B2C
    // 0x801E90AC: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801E90AC: nop

    after_1:
    // 0x801E90B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E90B4: jal         0x80034C24
    // 0x801E90B8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801E90B8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801E90BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E90C0: ldc1        $f4, -0x3A20($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3A20);
    // 0x801E90C4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E90C8: ldc1        $f8, -0x3A18($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3A18);
    // 0x801E90CC: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E90D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E90D4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E90D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E90DC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E90E0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E90E4: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E90E8: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E90EC: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    // 0x801E90F0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E90F4: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E90F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801E90FC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801E9100: ldc1        $f8, -0x3A10($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3A10);
    // 0x801E9104: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E9108: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E910C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E9110: div.d       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f12.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E9114: mul.d       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x801E9118: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801E911C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E9120: swc1        $f16, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f16.u32l;
    // 0x801E9124: ldc1        $f18, -0x3A08($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3A08);
    // 0x801E9128: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E912C: ldc1        $f6, -0x3A00($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3A00);
    // 0x801E9130: mul.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f12.d, ctx->f18.d);
    // 0x801E9134: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9138: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E913C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E9140: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801E9144: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E9148: swc1        $f10, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f10.u32l;
    // 0x801E914C: ldc1        $f16, -0x39F8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X39F8);
    // 0x801E9150: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9154: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9158: add.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f2.d + ctx->f16.d;
    // 0x801E915C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E9160: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E9164: swc1        $f4, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f4.u32l;
    // 0x801E9168: ldc1        $f6, -0x39F0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X39F0);
    // 0x801E916C: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9170: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9174: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x801E9178: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E917C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E9180: swc1        $f10, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f10.u32l;
    // 0x801E9184: ldc1        $f16, -0x39E8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X39E8);
    // 0x801E9188: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E918C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9190: add.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f2.d + ctx->f16.d;
    // 0x801E9194: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E9198: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E919C: swc1        $f4, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f4.u32l;
    // 0x801E91A0: ldc1        $f6, -0x39E0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X39E0);
    // 0x801E91A4: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E91A8: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x801E91AC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E91B0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E91B4: swc1        $f10, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f10.u32l;
L_801E91B8:
    // 0x801E91B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E91BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E91C0: jr          $ra
    // 0x801E91C4: nop

    return;
    // 0x801E91C4: nop

;}
RECOMP_FUNC void M25_FUN_801e91c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E91C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E91CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E91D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E91D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E91D8: lui         $a1, 0x631
    ctx->r5 = S32(0X631 << 16);
    // 0x801E91DC: ori         $a1, $a1, 0xA47A
    ctx->r5 = ctx->r5 | 0XA47A;
    // 0x801E91E0: jal         0x801C0B8C
    // 0x801E91E4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E91E4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E91E8: beq         $v0, $zero, L_801E91F8
    if (ctx->r2 == 0) {
        // 0x801E91EC: nop
    
            goto L_801E91F8;
    }
    // 0x801E91EC: nop

    // 0x801E91F0: b           L_801E930C
    // 0x801E91F4: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
        goto L_801E930C;
    // 0x801E91F4: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_801E91F8:
    // 0x801E91F8: jal         0x801C0B2C
    // 0x801E91FC: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801E91FC: nop

    after_1:
    // 0x801E9200: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E9204: jal         0x80034C24
    // 0x801E9208: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801E9208: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801E920C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9210: ldc1        $f4, -0x39D8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X39D8);
    // 0x801E9214: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9218: ldc1        $f8, -0x39D0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X39D0);
    // 0x801E921C: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E9220: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E9224: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E9228: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E922C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9230: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E9234: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E9238: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E923C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x801E9240: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E9244: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E9248: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801E924C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801E9250: ldc1        $f8, -0x39C8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X39C8);
    // 0x801E9254: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E9258: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E925C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E9260: div.d       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f12.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E9264: mul.d       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x801E9268: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801E926C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E9270: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E9274: swc1        $f16, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f16.u32l;
    // 0x801E9278: ldc1        $f18, -0x39C0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X39C0);
    // 0x801E927C: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9280: lui         $at, 0xC018
    ctx->r1 = S32(0XC018 << 16);
    // 0x801E9284: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801E9288: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801E928C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E9290: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9294: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E9298: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801E929C: swc1        $f6, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f6.u32l;
    // 0x801E92A0: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E92A4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E92A8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E92AC: swc1        $f16, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f16.u32l;
    // 0x801E92B0: ldc1        $f18, -0x39B8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X39B8);
    // 0x801E92B4: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E92B8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E92BC: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x801E92C0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E92C4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E92C8: swc1        $f6, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f6.u32l;
    // 0x801E92CC: ldc1        $f8, -0x39B0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X39B0);
    // 0x801E92D0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E92D4: ldc1        $f16, -0x39A8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X39A8);
    // 0x801E92D8: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x801E92DC: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E92E0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E92E4: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E92E8: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801E92EC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E92F0: swc1        $f4, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f4.u32l;
    // 0x801E92F4: ldc1        $f6, -0x39A0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X39A0);
    // 0x801E92F8: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E92FC: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x801E9300: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E9304: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E9308: swc1        $f10, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f10.u32l;
L_801E930C:
    // 0x801E930C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E9310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E9314: jr          $ra
    // 0x801E9318: nop

    return;
    // 0x801E9318: nop

;}
RECOMP_FUNC void M25_FUN_801e931c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E931C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E9320: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E9324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E9328: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E932C: lui         $a1, 0x650
    ctx->r5 = S32(0X650 << 16);
    // 0x801E9330: ori         $a1, $a1, 0x28FA
    ctx->r5 = ctx->r5 | 0X28FA;
    // 0x801E9334: jal         0x801C0B8C
    // 0x801E9338: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E9338: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E933C: beq         $v0, $zero, L_801E934C
    if (ctx->r2 == 0) {
        // 0x801E9340: nop
    
            goto L_801E934C;
    }
    // 0x801E9340: nop

    // 0x801E9344: b           L_801E9460
    // 0x801E9348: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
        goto L_801E9460;
    // 0x801E9348: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_801E934C:
    // 0x801E934C: jal         0x801C0B2C
    // 0x801E9350: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801E9350: nop

    after_1:
    // 0x801E9354: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E9358: jal         0x80034C24
    // 0x801E935C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801E935C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801E9360: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9364: ldc1        $f4, -0x3998($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3998);
    // 0x801E9368: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E936C: ldc1        $f8, -0x3990($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3990);
    // 0x801E9370: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E9374: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E9378: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E937C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E9380: lui         $at, 0xC061
    ctx->r1 = S32(0XC061 << 16);
    // 0x801E9384: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E9388: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E938C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9390: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // 0x801E9394: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E9398: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E939C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801E93A0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801E93A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E93A8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E93AC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801E93B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E93B4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E93B8: div.d       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f12.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E93BC: mul.d       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x801E93C0: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801E93C4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E93C8: swc1        $f16, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f16.u32l;
    // 0x801E93CC: ldc1        $f18, -0x3988($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3988);
    // 0x801E93D0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E93D4: ldc1        $f4, -0x3980($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3980);
    // 0x801E93D8: mul.d       $f14, $f12, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = MUL_D(ctx->f12.d, ctx->f18.d);
    // 0x801E93DC: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E93E0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E93E4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E93E8: add.d       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f14.d + ctx->f4.d;
    // 0x801E93EC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E93F0: swc1        $f8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f8.u32l;
    // 0x801E93F4: ldc1        $f10, -0x3978($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3978);
    // 0x801E93F8: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E93FC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9400: add.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f2.d + ctx->f10.d;
    // 0x801E9404: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E9408: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E940C: swc1        $f18, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f18.u32l;
    // 0x801E9410: ldc1        $f4, -0x3970($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3970);
    // 0x801E9414: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9418: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E941C: add.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d + ctx->f4.d;
    // 0x801E9420: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E9424: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E9428: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801E942C: ldc1        $f10, -0x3968($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3968);
    // 0x801E9430: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9434: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9438: add.d       $f16, $f14, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f14.d + ctx->f10.d;
    // 0x801E943C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E9440: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E9444: swc1        $f18, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f18.u32l;
    // 0x801E9448: ldc1        $f4, -0x3960($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3960);
    // 0x801E944C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9450: add.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d + ctx->f4.d;
    // 0x801E9454: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E9458: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E945C: swc1        $f8, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f8.u32l;
L_801E9460:
    // 0x801E9460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E9464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E9468: jr          $ra
    // 0x801E946C: nop

    return;
    // 0x801E946C: nop

;}
RECOMP_FUNC void M25_FUN_801e9470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E9470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E9474: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E9478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E947C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E9480: lui         $a1, 0x67D
    ctx->r5 = S32(0X67D << 16);
    // 0x801E9484: ori         $a1, $a1, 0xEFBA
    ctx->r5 = ctx->r5 | 0XEFBA;
    // 0x801E9488: jal         0x801C0B8C
    // 0x801E948C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E948C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E9490: beq         $v0, $zero, L_801E94A0
    if (ctx->r2 == 0) {
        // 0x801E9494: nop
    
            goto L_801E94A0;
    }
    // 0x801E9494: nop

    // 0x801E9498: b           L_801E95E8
    // 0x801E949C: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
        goto L_801E95E8;
    // 0x801E949C: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_801E94A0:
    // 0x801E94A0: jal         0x801C0B2C
    // 0x801E94A4: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801E94A4: nop

    after_1:
    // 0x801E94A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E94AC: jal         0x80034C24
    // 0x801E94B0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801E94B0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801E94B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E94B8: ldc1        $f4, -0x3958($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3958);
    // 0x801E94BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E94C0: ldc1        $f8, -0x3950($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3950);
    // 0x801E94C4: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E94C8: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801E94CC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E94D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E94D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E94D8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E94DC: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E94E0: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E94E4: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    // 0x801E94E8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E94EC: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E94F0: ldc1        $f6, -0x3948($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3948);
    // 0x801E94F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E94F8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E94FC: ldc1        $f10, -0x3940($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3940);
    // 0x801E9500: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9504: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E9508: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E950C: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E9510: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E9514: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E9518: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x801E951C: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801E9520: ldc1        $f4, -0x3938($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3938);
    // 0x801E9524: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9528: ldc1        $f8, -0x3930($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3930);
    // 0x801E952C: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801E9530: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801E9534: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9538: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E953C: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801E9540: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E9544: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E9548: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E954C: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801E9550: ldc1        $f6, -0x3928($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3928);
    // 0x801E9554: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9558: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E955C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801E9560: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E9564: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E9568: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801E956C: ldc1        $f16, -0x3920($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3920);
    // 0x801E9570: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9574: ldc1        $f4, -0x3918($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3918);
    // 0x801E9578: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801E957C: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9580: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9584: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E9588: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801E958C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801E9590: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E9594: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x801E9598: ldc1        $f10, -0x3910($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3910);
    // 0x801E959C: lui         $at, 0x4029
    ctx->r1 = S32(0X4029 << 16);
    // 0x801E95A0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801E95A4: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801E95A8: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E95AC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E95B0: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E95B4: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801E95B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801E95BC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E95C0: swc1        $f6, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f6.u32l;
    // 0x801E95C4: ldc1        $f8, -0x3908($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3908);
    // 0x801E95C8: lui         $at, 0xC018
    ctx->r1 = S32(0XC018 << 16);
    // 0x801E95CC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801E95D0: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801E95D4: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E95D8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E95DC: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801E95E0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E95E4: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
L_801E95E8:
    // 0x801E95E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E95EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E95F0: jr          $ra
    // 0x801E95F4: nop

    return;
    // 0x801E95F4: nop

;}
RECOMP_FUNC void M25_FUN_801e95f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E95F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E95FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E9600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E9604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E9608: lui         $a1, 0x6D9
    ctx->r5 = S32(0X6D9 << 16);
    // 0x801E960C: ori         $a1, $a1, 0x7D3A
    ctx->r5 = ctx->r5 | 0X7D3A;
    // 0x801E9610: jal         0x801C0B8C
    // 0x801E9614: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E9614: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E9618: beq         $v0, $zero, L_801E9628
    if (ctx->r2 == 0) {
        // 0x801E961C: nop
    
            goto L_801E9628;
    }
    // 0x801E961C: nop

    // 0x801E9620: b           L_801E974C
    // 0x801E9624: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
        goto L_801E974C;
    // 0x801E9624: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_801E9628:
    // 0x801E9628: jal         0x801C0B2C
    // 0x801E962C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801E962C: nop

    after_1:
    // 0x801E9630: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E9634: jal         0x80034C24
    // 0x801E9638: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801E9638: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801E963C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9640: ldc1        $f4, -0x3900($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3900);
    // 0x801E9644: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9648: ldc1        $f8, -0x38F8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X38F8);
    // 0x801E964C: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E9650: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x801E9654: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E9658: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E965C: lui         $at, 0xC062
    ctx->r1 = S32(0XC062 << 16);
    // 0x801E9660: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E9664: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E9668: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E966C: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    // 0x801E9670: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E9674: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E9678: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801E967C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801E9680: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E9684: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E9688: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801E968C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9690: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E9694: div.d       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f12.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E9698: mul.d       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f2.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x801E969C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801E96A0: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801E96A4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E96A8: swc1        $f16, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f16.u32l;
    // 0x801E96AC: ldc1        $f18, -0x38F0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X38F0);
    // 0x801E96B0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801E96B4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801E96B8: mul.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f12.d, ctx->f18.d);
    // 0x801E96BC: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E96C0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E96C4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E96C8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801E96CC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E96D0: swc1        $f10, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f10.u32l;
    // 0x801E96D4: ldc1        $f16, -0x38E8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X38E8);
    // 0x801E96D8: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E96DC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E96E0: add.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f2.d + ctx->f16.d;
    // 0x801E96E4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E96E8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E96EC: swc1        $f4, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f4.u32l;
    // 0x801E96F0: ldc1        $f6, -0x38E0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X38E0);
    // 0x801E96F4: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E96F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E96FC: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x801E9700: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E9704: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E9708: swc1        $f10, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f10.u32l;
    // 0x801E970C: ldc1        $f16, -0x38D8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X38D8);
    // 0x801E9710: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9714: ldc1        $f4, -0x38D0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X38D0);
    // 0x801E9718: mul.d       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f12.d, ctx->f16.d);
    // 0x801E971C: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9720: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9724: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E9728: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801E972C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E9730: swc1        $f8, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f8.u32l;
    // 0x801E9734: ldc1        $f10, -0x38C8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X38C8);
    // 0x801E9738: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E973C: add.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f2.d + ctx->f10.d;
    // 0x801E9740: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E9744: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E9748: swc1        $f18, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f18.u32l;
L_801E974C:
    // 0x801E974C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E9750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E9754: jr          $ra
    // 0x801E9758: nop

    return;
    // 0x801E9758: nop

;}
RECOMP_FUNC void M25_FUN_801e975c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E975C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E9760: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E9764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E9768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E976C: lui         $a1, 0x6FF
    ctx->r5 = S32(0X6FF << 16);
    // 0x801E9770: ori         $a1, $a1, 0xA2DA
    ctx->r5 = ctx->r5 | 0XA2DA;
    // 0x801E9774: jal         0x801C0B8C
    // 0x801E9778: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E9778: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E977C: beq         $v0, $zero, L_801E978C
    if (ctx->r2 == 0) {
        // 0x801E9780: nop
    
            goto L_801E978C;
    }
    // 0x801E9780: nop

    // 0x801E9784: b           L_801E97DC
    // 0x801E9788: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
        goto L_801E97DC;
    // 0x801E9788: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_801E978C:
    // 0x801E978C: jal         0x801C0B2C
    // 0x801E9790: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801E9790: nop

    after_1:
    // 0x801E9794: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E9798: jal         0x80034C24
    // 0x801E979C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801E979C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801E97A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E97A4: lwc1        $f12, -0x38C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X38C0);
    // 0x801E97A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E97AC: lui         $a2, 0xC266
    ctx->r6 = S32(0XC266 << 16);
    // 0x801E97B0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801E97B4: jal         0x8038BD50
    // 0x801E97B8: lwc1        $f14, -0x38BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X38BC);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_3;
    // 0x801E97B8: lwc1        $f14, -0x38BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X38BC);
    after_3:
    // 0x801E97BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E97C0: lwc1        $f12, -0x38B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X38B8);
    // 0x801E97C4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E97C8: lui         $a2, 0xC249
    ctx->r6 = S32(0XC249 << 16);
    // 0x801E97CC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801E97D0: jal         0x8038BD88
    // 0x801E97D4: lwc1        $f14, -0x38B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X38B4);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_4;
    // 0x801E97D4: lwc1        $f14, -0x38B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X38B4);
    after_4:
    // 0x801E97D8: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_801E97DC:
    // 0x801E97DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E97E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E97E4: jr          $ra
    // 0x801E97E8: nop

    return;
    // 0x801E97E8: nop

;}
RECOMP_FUNC void M25_FUN_801e97ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E97EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E97F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E97F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E97F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E97FC: lui         $a1, 0x71E
    ctx->r5 = S32(0X71E << 16);
    // 0x801E9800: ori         $a1, $a1, 0x275A
    ctx->r5 = ctx->r5 | 0X275A;
    // 0x801E9804: jal         0x801C0B8C
    // 0x801E9808: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E9808: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E980C: beq         $v0, $zero, L_801E981C
    if (ctx->r2 == 0) {
        // 0x801E9810: nop
    
            goto L_801E981C;
    }
    // 0x801E9810: nop

    // 0x801E9814: b           L_801E9948
    // 0x801E9818: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
        goto L_801E9948;
    // 0x801E9818: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_801E981C:
    // 0x801E981C: jal         0x801C0B2C
    // 0x801E9820: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801E9820: nop

    after_1:
    // 0x801E9824: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E9828: jal         0x80034C24
    // 0x801E982C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801E982C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801E9830: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9834: ldc1        $f4, -0x38B0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X38B0);
    // 0x801E9838: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E983C: ldc1        $f8, -0x38A8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X38A8);
    // 0x801E9840: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E9844: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E9848: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E984C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E9850: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9854: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E9858: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E985C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9860: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    // 0x801E9864: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E9868: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E986C: ldc1        $f6, -0x38A0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X38A0);
    // 0x801E9870: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9874: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E9878: ldc1        $f10, -0x3898($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3898);
    // 0x801E987C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9880: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E9884: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E9888: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E988C: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E9890: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E9894: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801E9898: ldc1        $f4, -0x3890($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3890);
    // 0x801E989C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E98A0: ldc1        $f8, -0x3888($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3888);
    // 0x801E98A4: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801E98A8: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E98AC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E98B0: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E98B4: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E98B8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E98BC: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x801E98C0: swc1        $f16, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f16.u32l;
    // 0x801E98C4: ldc1        $f18, -0x3880($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3880);
    // 0x801E98C8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E98CC: ldc1        $f6, -0x3878($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X3878);
    // 0x801E98D0: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801E98D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801E98D8: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E98DC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E98E0: mul.d       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801E98E4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E98E8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801E98EC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E98F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E98F4: swc1        $f10, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f10.u32l;
    // 0x801E98F8: ldc1        $f18, -0x3870($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3870);
    // 0x801E98FC: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9900: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x801E9904: add.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f12.d + ctx->f18.d;
    // 0x801E9908: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801E990C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E9910: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9914: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E9918: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x801E991C: swc1        $f6, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f6.u32l;
    // 0x801E9920: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9924: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E9928: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E992C: swc1        $f16, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f16.u32l;
    // 0x801E9930: ldc1        $f18, -0x3868($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3868);
    // 0x801E9934: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9938: add.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f12.d + ctx->f18.d;
    // 0x801E993C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E9940: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E9944: swc1        $f6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f6.u32l;
L_801E9948:
    // 0x801E9948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E994C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E9950: jr          $ra
    // 0x801E9954: nop

    return;
    // 0x801E9954: nop

;}
RECOMP_FUNC void M25_FUN_801e9958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E9958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E995C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E9960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E9964: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E9968: lui         $a1, 0x736
    ctx->r5 = S32(0X736 << 16);
    // 0x801E996C: ori         $a1, $a1, 0x915A
    ctx->r5 = ctx->r5 | 0X915A;
    // 0x801E9970: jal         0x801C0B8C
    // 0x801E9974: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E9974: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E9978: beq         $v0, $zero, L_801E9988
    if (ctx->r2 == 0) {
        // 0x801E997C: lui         $at, 0xC2A3
        ctx->r1 = S32(0XC2A3 << 16);
            goto L_801E9988;
    }
    // 0x801E997C: lui         $at, 0xC2A3
    ctx->r1 = S32(0XC2A3 << 16);
    // 0x801E9980: b           L_801E99BC
    // 0x801E9984: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
        goto L_801E99BC;
    // 0x801E9984: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_801E9988:
    // 0x801E9988: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E998C: lui         $at, 0x4138
    ctx->r1 = S32(0X4138 << 16);
    // 0x801E9990: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E9994: lui         $a2, 0xC253
    ctx->r6 = S32(0XC253 << 16);
    // 0x801E9998: jal         0x8038BD50
    // 0x801E999C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E999C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    after_1:
    // 0x801E99A0: lui         $at, 0xC328
    ctx->r1 = S32(0XC328 << 16);
    // 0x801E99A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E99A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E99AC: lwc1        $f14, -0x3860($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3860);
    // 0x801E99B0: jal         0x8038BD88
    // 0x801E99B4: lui         $a2, 0xC200
    ctx->r6 = S32(0XC200 << 16);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E99B4: lui         $a2, 0xC200
    ctx->r6 = S32(0XC200 << 16);
    after_2:
    // 0x801E99B8: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_801E99BC:
    // 0x801E99BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E99C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E99C4: jr          $ra
    // 0x801E99C8: nop

    return;
    // 0x801E99C8: nop

;}
RECOMP_FUNC void M25_FUN_801e99cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E99CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E99D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E99D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E99D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E99DC: lui         $a1, 0x767
    ctx->r5 = S32(0X767 << 16);
    // 0x801E99E0: ori         $a1, $a1, 0x655A
    ctx->r5 = ctx->r5 | 0X655A;
    // 0x801E99E4: jal         0x801C0B8C
    // 0x801E99E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E99E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E99EC: beq         $v0, $zero, L_801E99FC
    if (ctx->r2 == 0) {
        // 0x801E99F0: nop
    
            goto L_801E99FC;
    }
    // 0x801E99F0: nop

    // 0x801E99F4: b           L_801E9B30
    // 0x801E99F8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
        goto L_801E9B30;
    // 0x801E99F8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_801E99FC:
    // 0x801E99FC: jal         0x801C0B2C
    // 0x801E9A00: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_1;
    // 0x801E9A00: nop

    after_1:
    // 0x801E9A04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E9A08: jal         0x80034C24
    // 0x801E9A0C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801E9A0C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801E9A10: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9A14: ldc1        $f4, -0x3858($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3858);
    // 0x801E9A18: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9A1C: ldc1        $f8, -0x3850($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3850);
    // 0x801E9A20: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E9A24: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801E9A28: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E9A2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E9A30: lui         $at, 0xC026
    ctx->r1 = S32(0XC026 << 16);
    // 0x801E9A34: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E9A38: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E9A3C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9A40: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x801E9A44: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E9A48: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E9A4C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801E9A50: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801E9A54: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9A58: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E9A5C: ldc1        $f10, -0x3848($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3848);
    // 0x801E9A60: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9A64: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E9A68: div.d       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E9A6C: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E9A70: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E9A74: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E9A78: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E9A7C: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801E9A80: ldc1        $f4, -0x3840($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3840);
    // 0x801E9A84: lui         $at, 0x402D
    ctx->r1 = S32(0X402D << 16);
    // 0x801E9A88: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801E9A8C: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801E9A90: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9A94: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9A98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E9A9C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E9AA0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E9AA4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x801E9AA8: swc1        $f12, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f12.u32l;
    // 0x801E9AAC: ldc1        $f16, -0x3838($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X3838);
    // 0x801E9AB0: lui         $at, 0xC027
    ctx->r1 = S32(0XC027 << 16);
    // 0x801E9AB4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E9AB8: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801E9ABC: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9AC0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9AC4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E9AC8: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801E9ACC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E9AD0: swc1        $f8, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f8.u32l;
    // 0x801E9AD4: ldc1        $f10, -0x3830($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X3830);
    // 0x801E9AD8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9ADC: ldc1        $f18, -0x3828($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X3828);
    // 0x801E9AE0: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801E9AE4: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9AE8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9AEC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E9AF0: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801E9AF4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801E9AF8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E9AFC: swc1        $f6, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f6.u32l;
    // 0x801E9B00: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9B04: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E9B08: swc1        $f12, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f12.u32l;
    // 0x801E9B0C: ldc1        $f8, -0x3820($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3820);
    // 0x801E9B10: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x801E9B14: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801E9B18: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801E9B1C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E9B20: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E9B24: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801E9B28: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E9B2C: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
L_801E9B30:
    // 0x801E9B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E9B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E9B38: jr          $ra
    // 0x801E9B3C: nop

    return;
    // 0x801E9B3C: nop

;}
RECOMP_FUNC void M25_FUN_801e9b40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E9B40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E9B44: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E9B48: jr          $ra
    // 0x801E9B4C: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x801E9B4C: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e9b50(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e9b50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E9B50: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E9B54: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E9B58: jr          $ra
    // 0x801E9B5C: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    return;
    // 0x801E9B5C: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e9b60(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e9b60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E9B60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E9B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E9B68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E9B6C: jal         0x801CD044
    // 0x801E9B70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CD044)(rdram, ctx);
        goto after_0;
    // 0x801E9B70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801E9B74: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E9B78: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E9B7C: lw          $a1, -0x5444($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5444);
    // 0x801E9B80: jal         0x801CCF48
    // 0x801E9B84: lw          $a0, -0x5448($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5448);
    LOOKUP_FUNC(0x801CCF48)(rdram, ctx);
        goto after_1;
    // 0x801E9B84: lw          $a0, -0x5448($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5448);
    after_1:
    // 0x801E9B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E9B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E9B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801E9B94: jr          $ra
    // 0x801E9B98: nop

    return;
    // 0x801E9B98: nop

;}
RECOMP_FUNC void M25_FUN_801e9b9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E9B9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E9BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E9BA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E9BA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E9BAC: jal         0x801CCE0C
    // 0x801E9BB0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_0;
    // 0x801E9BB0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x801E9BB4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801E9BB8: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801E9BBC: jal         0x801CCE50
    // 0x801E9BC0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_1;
    // 0x801E9BC0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x801E9BC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801E9BC8: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801E9BCC: addiu       $v0, $v0, -0x2B68
    ctx->r2 = ADD32(ctx->r2, -0X2B68);
    // 0x801E9BD0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801E9BD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801E9BD8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801E9BDC: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801E9BE0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801E9BE4: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801E9BE8: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801E9BEC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801E9BF0: addiu       $t0, $t0, -0x2B60
    ctx->r8 = ADD32(ctx->r8, -0X2B60);
    // 0x801E9BF4: addiu       $v1, $v1, -0x2B64
    ctx->r3 = ADD32(ctx->r3, -0X2B64);
    // 0x801E9BF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E9BFC: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801E9C00: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801E9C04: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x801E9C08: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801E9C0C: beq         $a1, $zero, L_801E9C58
    if (ctx->r5 == 0) {
        // 0x801E9C10: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_801E9C58;
    }
    // 0x801E9C10: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801E9C14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E9C18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801E9C1C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801E9C20: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801E9C24: nop

    // 0x801E9C28: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801E9C2C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801E9C30: nop

    // 0x801E9C34: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801E9C38: bne         $a1, $zero, L_801E9C50
    if (ctx->r5 != 0) {
        // 0x801E9C3C: nop
    
            goto L_801E9C50;
    }
    // 0x801E9C3C: nop

    // 0x801E9C40: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801E9C44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801E9C48: b           L_801E9C68
    // 0x801E9C4C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801E9C68;
    // 0x801E9C4C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801E9C50:
    // 0x801E9C50: b           L_801E9C68
    // 0x801E9C54: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801E9C68;
    // 0x801E9C54: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_801E9C58:
    // 0x801E9C58: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801E9C5C: nop

    // 0x801E9C60: bltz        $a1, L_801E9C50
    if (SIGNED(ctx->r5) < 0) {
        // 0x801E9C64: nop
    
            goto L_801E9C50;
    }
    // 0x801E9C64: nop

L_801E9C68:
    // 0x801E9C68: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801E9C6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801E9C70: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801E9C74: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801E9C78: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801E9C7C: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801E9C80: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801E9C84: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801E9C88: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801E9C8C: nop

    // 0x801E9C90: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801E9C94: beql        $a2, $zero, L_801E9CE4
    if (ctx->r6 == 0) {
        // 0x801E9C98: mfc1        $a2, $f10
        ctx->r6 = (int32_t)ctx->f10.u32l;
            goto L_801E9CE4;
    }
    goto skip_0;
    // 0x801E9C98: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x801E9C9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E9CA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801E9CA4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801E9CA8: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801E9CAC: nop

    // 0x801E9CB0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801E9CB4: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801E9CB8: nop

    // 0x801E9CBC: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801E9CC0: bne         $a2, $zero, L_801E9CD8
    if (ctx->r6 != 0) {
        // 0x801E9CC4: nop
    
            goto L_801E9CD8;
    }
    // 0x801E9CC4: nop

    // 0x801E9CC8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801E9CCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801E9CD0: b           L_801E9CF0
    // 0x801E9CD4: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801E9CF0;
    // 0x801E9CD4: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801E9CD8:
    // 0x801E9CD8: b           L_801E9CF0
    // 0x801E9CDC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801E9CF0;
    // 0x801E9CDC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801E9CE0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
L_801E9CE4:
    // 0x801E9CE4: nop

    // 0x801E9CE8: bltz        $a2, L_801E9CD8
    if (SIGNED(ctx->r6) < 0) {
        // 0x801E9CEC: nop
    
            goto L_801E9CD8;
    }
    // 0x801E9CEC: nop

L_801E9CF0:
    // 0x801E9CF0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801E9CF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801E9CF8: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801E9CFC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801E9D00: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801E9D04: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801E9D08: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801E9D0C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801E9D10: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801E9D14: nop

    // 0x801E9D18: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801E9D1C: beql        $a3, $zero, L_801E9D6C
    if (ctx->r7 == 0) {
        // 0x801E9D20: mfc1        $a3, $f18
        ctx->r7 = (int32_t)ctx->f18.u32l;
            goto L_801E9D6C;
    }
    goto skip_1;
    // 0x801E9D20: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x801E9D24: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E9D28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801E9D2C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801E9D30: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801E9D34: nop

    // 0x801E9D38: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801E9D3C: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801E9D40: nop

    // 0x801E9D44: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801E9D48: bne         $a3, $zero, L_801E9D60
    if (ctx->r7 != 0) {
        // 0x801E9D4C: nop
    
            goto L_801E9D60;
    }
    // 0x801E9D4C: nop

    // 0x801E9D50: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801E9D54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801E9D58: b           L_801E9D78
    // 0x801E9D5C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801E9D78;
    // 0x801E9D5C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801E9D60:
    // 0x801E9D60: b           L_801E9D78
    // 0x801E9D64: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801E9D78;
    // 0x801E9D64: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801E9D68: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
L_801E9D6C:
    // 0x801E9D6C: nop

    // 0x801E9D70: bltz        $a3, L_801E9D60
    if (SIGNED(ctx->r7) < 0) {
        // 0x801E9D74: nop
    
            goto L_801E9D60;
    }
    // 0x801E9D74: nop

L_801E9D78:
    // 0x801E9D78: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801E9D7C: jal         0x801CCE88
    // 0x801E9D80: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_2;
    // 0x801E9D80: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_2:
    // 0x801E9D84: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9D88: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801E9D8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801E9D90: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801E9D94: lwc1        $f4, -0x2B68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B68);
    // 0x801E9D98: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801E9D9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801E9DA0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801E9DA4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801E9DA8: nop

    // 0x801E9DAC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801E9DB0: beql        $a1, $zero, L_801E9E00
    if (ctx->r5 == 0) {
        // 0x801E9DB4: mfc1        $a1, $f6
        ctx->r5 = (int32_t)ctx->f6.u32l;
            goto L_801E9E00;
    }
    goto skip_2;
    // 0x801E9DB4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x801E9DB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E9DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801E9DC0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801E9DC4: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801E9DC8: nop

    // 0x801E9DCC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801E9DD0: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801E9DD4: nop

    // 0x801E9DD8: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801E9DDC: bne         $a1, $zero, L_801E9DF4
    if (ctx->r5 != 0) {
        // 0x801E9DE0: nop
    
            goto L_801E9DF4;
    }
    // 0x801E9DE0: nop

    // 0x801E9DE4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801E9DE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801E9DEC: b           L_801E9E0C
    // 0x801E9DF0: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801E9E0C;
    // 0x801E9DF0: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801E9DF4:
    // 0x801E9DF4: b           L_801E9E0C
    // 0x801E9DF8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801E9E0C;
    // 0x801E9DF8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801E9DFC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
L_801E9E00:
    // 0x801E9E00: nop

    // 0x801E9E04: bltz        $a1, L_801E9DF4
    if (SIGNED(ctx->r5) < 0) {
        // 0x801E9E08: nop
    
            goto L_801E9DF4;
    }
    // 0x801E9E08: nop

L_801E9E0C:
    // 0x801E9E0C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801E9E10: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9E14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801E9E18: lwc1        $f8, -0x2B64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B64);
    // 0x801E9E1C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801E9E20: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801E9E24: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801E9E28: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801E9E2C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801E9E30: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801E9E34: nop

    // 0x801E9E38: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801E9E3C: beql        $a2, $zero, L_801E9E8C
    if (ctx->r6 == 0) {
        // 0x801E9E40: mfc1        $a2, $f10
        ctx->r6 = (int32_t)ctx->f10.u32l;
            goto L_801E9E8C;
    }
    goto skip_3;
    // 0x801E9E40: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    skip_3:
    // 0x801E9E44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E9E48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801E9E4C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801E9E50: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801E9E54: nop

    // 0x801E9E58: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801E9E5C: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801E9E60: nop

    // 0x801E9E64: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801E9E68: bne         $a2, $zero, L_801E9E80
    if (ctx->r6 != 0) {
        // 0x801E9E6C: nop
    
            goto L_801E9E80;
    }
    // 0x801E9E6C: nop

    // 0x801E9E70: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801E9E74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801E9E78: b           L_801E9E98
    // 0x801E9E7C: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801E9E98;
    // 0x801E9E7C: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801E9E80:
    // 0x801E9E80: b           L_801E9E98
    // 0x801E9E84: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801E9E98;
    // 0x801E9E84: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801E9E88: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
L_801E9E8C:
    // 0x801E9E8C: nop

    // 0x801E9E90: bltz        $a2, L_801E9E80
    if (SIGNED(ctx->r6) < 0) {
        // 0x801E9E94: nop
    
            goto L_801E9E80;
    }
    // 0x801E9E94: nop

L_801E9E98:
    // 0x801E9E98: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801E9E9C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9EA0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801E9EA4: lwc1        $f16, -0x2B60($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B60);
    // 0x801E9EA8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801E9EAC: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801E9EB0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801E9EB4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801E9EB8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801E9EBC: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801E9EC0: nop

    // 0x801E9EC4: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801E9EC8: beql        $a3, $zero, L_801E9F18
    if (ctx->r7 == 0) {
        // 0x801E9ECC: mfc1        $a3, $f18
        ctx->r7 = (int32_t)ctx->f18.u32l;
            goto L_801E9F18;
    }
    goto skip_4;
    // 0x801E9ECC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    skip_4:
    // 0x801E9ED0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E9ED4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801E9ED8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801E9EDC: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801E9EE0: nop

    // 0x801E9EE4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801E9EE8: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801E9EEC: nop

    // 0x801E9EF0: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801E9EF4: bne         $a3, $zero, L_801E9F0C
    if (ctx->r7 != 0) {
        // 0x801E9EF8: nop
    
            goto L_801E9F0C;
    }
    // 0x801E9EF8: nop

    // 0x801E9EFC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801E9F00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801E9F04: b           L_801E9F24
    // 0x801E9F08: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801E9F24;
    // 0x801E9F08: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801E9F0C:
    // 0x801E9F0C: b           L_801E9F24
    // 0x801E9F10: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801E9F24;
    // 0x801E9F10: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801E9F14: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
L_801E9F18:
    // 0x801E9F18: nop

    // 0x801E9F1C: bltz        $a3, L_801E9F0C
    if (SIGNED(ctx->r7) < 0) {
        // 0x801E9F20: nop
    
            goto L_801E9F0C;
    }
    // 0x801E9F20: nop

L_801E9F24:
    // 0x801E9F24: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801E9F28: jal         0x801CCE88
    // 0x801E9F2C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_3;
    // 0x801E9F2C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_3:
    // 0x801E9F30: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801E9F34: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801E9F38: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801E9F3C: addiu       $v0, $v0, -0x2B5C
    ctx->r2 = ADD32(ctx->r2, -0X2B5C);
    // 0x801E9F40: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801E9F44: addiu       $v1, $v1, -0x2B58
    ctx->r3 = ADD32(ctx->r3, -0X2B58);
    // 0x801E9F48: addiu       $t0, $t0, -0x2B54
    ctx->r8 = ADD32(ctx->r8, -0X2B54);
    // 0x801E9F4C: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x801E9F50: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801E9F54: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x801E9F58: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801E9F5C: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801E9F60: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x801E9F64: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801E9F68: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x801E9F6C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801E9F70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E9F74: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801E9F78: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801E9F7C: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x801E9F80: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801E9F84: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801E9F88: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x801E9F8C: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x801E9F90: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x801E9F94: jal         0x801CCEC8
    // 0x801E9F98: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_4;
    // 0x801E9F98: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_4:
    // 0x801E9F9C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9FA0: lwc1        $f4, -0x2B5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B5C);
    // 0x801E9FA4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9FA8: lwc1        $f10, -0x2B58($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B58);
    // 0x801E9FAC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E9FB0: lwc1        $f18, -0x2B54($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B54);
    // 0x801E9FB4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x801E9FB8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801E9FBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801E9FC0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801E9FC4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801E9FC8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801E9FCC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801E9FD0: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x801E9FD4: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x801E9FD8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801E9FDC: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x801E9FE0: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801E9FE4: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x801E9FE8: jal         0x801CCEC8
    // 0x801E9FEC: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_5;
    // 0x801E9FEC: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_5:
    // 0x801E9FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E9FF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E9FF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E9FFC: jr          $ra
    // 0x801EA000: nop

    return;
    // 0x801EA000: nop

;}
RECOMP_FUNC void M25_FUN_801ea004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EA004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EA008: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EA00C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EA010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EA014: lui         $a1, 0x81
    ctx->r5 = S32(0X81 << 16);
    // 0x801EA018: ori         $a1, $a1, 0xB320
    ctx->r5 = ctx->r5 | 0XB320;
    // 0x801EA01C: jal         0x801C0B8C
    // 0x801EA020: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EA020: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EA024: beq         $v0, $zero, L_801EA034
    if (ctx->r2 == 0) {
        // 0x801EA028: lui         $v1, 0x8020
        ctx->r3 = S32(0X8020 << 16);
            goto L_801EA034;
    }
    // 0x801EA028: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801EA02C: b           L_801EA4AC
    // 0x801EA030: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801EA4AC;
    // 0x801EA030: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801EA034:
    // 0x801EA034: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801EA038: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA03C: lwc1        $f0, -0x3818($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3818);
    // 0x801EA040: addiu       $v0, $v0, -0x2B68
    ctx->r2 = ADD32(ctx->r2, -0X2B68);
    // 0x801EA044: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801EA048: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801EA04C: addiu       $t0, $t0, -0x2B60
    ctx->r8 = ADD32(ctx->r8, -0X2B60);
    // 0x801EA050: addiu       $v1, $v1, -0x2B64
    ctx->r3 = ADD32(ctx->r3, -0X2B64);
    // 0x801EA054: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801EA058: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801EA05C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x801EA060: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x801EA064: addiu       $t1, $t1, -0x2B5C
    ctx->r9 = ADD32(ctx->r9, -0X2B5C);
    // 0x801EA068: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801EA06C: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801EA070: lui         $t2, 0x8020
    ctx->r10 = S32(0X8020 << 16);
    // 0x801EA074: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801EA078: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x801EA07C: addiu       $t2, $t2, -0x2B58
    ctx->r10 = ADD32(ctx->r10, -0X2B58);
    // 0x801EA080: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x801EA084: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x801EA088: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA08C: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x801EA090: lwc1        $f8, -0x3814($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3814);
    // 0x801EA094: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801EA098: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x801EA09C: addiu       $t3, $t3, -0x2B54
    ctx->r11 = ADD32(ctx->r11, -0X2B54);
    // 0x801EA0A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801EA0A4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA0A8: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801EA0AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EA0B0: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x801EA0B4: lwc1        $f18, -0x3810($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3810);
    // 0x801EA0B8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801EA0BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EA0C0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801EA0C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801EA0C8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801EA0CC: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x801EA0D0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801EA0D4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801EA0D8: nop

    // 0x801EA0DC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801EA0E0: beq         $a1, $zero, L_801EA12C
    if (ctx->r5 == 0) {
        // 0x801EA0E4: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_801EA12C;
    }
    // 0x801EA0E4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EA0E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801EA0EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EA0F0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801EA0F4: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801EA0F8: nop

    // 0x801EA0FC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801EA100: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801EA104: nop

    // 0x801EA108: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801EA10C: bne         $a1, $zero, L_801EA124
    if (ctx->r5 != 0) {
        // 0x801EA110: nop
    
            goto L_801EA124;
    }
    // 0x801EA110: nop

    // 0x801EA114: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801EA118: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EA11C: b           L_801EA13C
    // 0x801EA120: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801EA13C;
    // 0x801EA120: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801EA124:
    // 0x801EA124: b           L_801EA13C
    // 0x801EA128: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801EA13C;
    // 0x801EA128: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_801EA12C:
    // 0x801EA12C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801EA130: nop

    // 0x801EA134: bltz        $a1, L_801EA124
    if (SIGNED(ctx->r5) < 0) {
        // 0x801EA138: nop
    
            goto L_801EA124;
    }
    // 0x801EA138: nop

L_801EA13C:
    // 0x801EA13C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801EA140: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EA144: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801EA148: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801EA14C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801EA150: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801EA154: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EA158: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801EA15C: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801EA160: nop

    // 0x801EA164: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801EA168: beql        $a2, $zero, L_801EA1B8
    if (ctx->r6 == 0) {
        // 0x801EA16C: mfc1        $a2, $f16
        ctx->r6 = (int32_t)ctx->f16.u32l;
            goto L_801EA1B8;
    }
    goto skip_0;
    // 0x801EA16C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801EA170: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801EA174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EA178: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801EA17C: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801EA180: nop

    // 0x801EA184: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801EA188: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801EA18C: nop

    // 0x801EA190: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801EA194: bne         $a2, $zero, L_801EA1AC
    if (ctx->r6 != 0) {
        // 0x801EA198: nop
    
            goto L_801EA1AC;
    }
    // 0x801EA198: nop

    // 0x801EA19C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801EA1A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EA1A4: b           L_801EA1C4
    // 0x801EA1A8: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801EA1C4;
    // 0x801EA1A8: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801EA1AC:
    // 0x801EA1AC: b           L_801EA1C4
    // 0x801EA1B0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801EA1C4;
    // 0x801EA1B0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801EA1B4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
L_801EA1B8:
    // 0x801EA1B8: nop

    // 0x801EA1BC: bltz        $a2, L_801EA1AC
    if (SIGNED(ctx->r6) < 0) {
        // 0x801EA1C0: nop
    
            goto L_801EA1AC;
    }
    // 0x801EA1C0: nop

L_801EA1C4:
    // 0x801EA1C4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801EA1C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EA1CC: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801EA1D0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801EA1D4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801EA1D8: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EA1DC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EA1E0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801EA1E4: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EA1E8: nop

    // 0x801EA1EC: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EA1F0: beql        $a3, $zero, L_801EA240
    if (ctx->r7 == 0) {
        // 0x801EA1F4: mfc1        $a3, $f4
        ctx->r7 = (int32_t)ctx->f4.u32l;
            goto L_801EA240;
    }
    goto skip_1;
    // 0x801EA1F4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x801EA1F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EA1FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EA200: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801EA204: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EA208: nop

    // 0x801EA20C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801EA210: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EA214: nop

    // 0x801EA218: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EA21C: bne         $a3, $zero, L_801EA234
    if (ctx->r7 != 0) {
        // 0x801EA220: nop
    
            goto L_801EA234;
    }
    // 0x801EA220: nop

    // 0x801EA224: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801EA228: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EA22C: b           L_801EA24C
    // 0x801EA230: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801EA24C;
    // 0x801EA230: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801EA234:
    // 0x801EA234: b           L_801EA24C
    // 0x801EA238: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801EA24C;
    // 0x801EA238: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801EA23C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
L_801EA240:
    // 0x801EA240: nop

    // 0x801EA244: bltz        $a3, L_801EA234
    if (SIGNED(ctx->r7) < 0) {
        // 0x801EA248: nop
    
            goto L_801EA234;
    }
    // 0x801EA248: nop

L_801EA24C:
    // 0x801EA24C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801EA250: jal         0x801CCE88
    // 0x801EA254: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_1;
    // 0x801EA254: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_1:
    // 0x801EA258: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA25C: lwc1        $f18, -0x2B5C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B5C);
    // 0x801EA260: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA264: lwc1        $f16, -0x2B58($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B58);
    // 0x801EA268: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801EA26C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA270: lwc1        $f14, -0x2B54($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2B54);
    // 0x801EA274: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801EA278: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801EA27C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EA280: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x801EA284: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801EA288: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x801EA28C: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801EA290: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x801EA294: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x801EA298: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x801EA29C: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x801EA2A0: jal         0x801CCEC8
    // 0x801EA2A4: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_2;
    // 0x801EA2A4: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_2:
    // 0x801EA2A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA2AC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801EA2B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EA2B4: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801EA2B8: lwc1        $f6, -0x2B68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B68);
    // 0x801EA2BC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EA2C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EA2C4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801EA2C8: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801EA2CC: nop

    // 0x801EA2D0: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801EA2D4: beql        $a1, $zero, L_801EA324
    if (ctx->r5 == 0) {
        // 0x801EA2D8: mfc1        $a1, $f8
        ctx->r5 = (int32_t)ctx->f8.u32l;
            goto L_801EA324;
    }
    goto skip_2;
    // 0x801EA2D8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x801EA2DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801EA2E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EA2E4: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801EA2E8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801EA2EC: nop

    // 0x801EA2F0: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801EA2F4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801EA2F8: nop

    // 0x801EA2FC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801EA300: bne         $a1, $zero, L_801EA318
    if (ctx->r5 != 0) {
        // 0x801EA304: nop
    
            goto L_801EA318;
    }
    // 0x801EA304: nop

    // 0x801EA308: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801EA30C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EA310: b           L_801EA330
    // 0x801EA314: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801EA330;
    // 0x801EA314: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801EA318:
    // 0x801EA318: b           L_801EA330
    // 0x801EA31C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801EA330;
    // 0x801EA31C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801EA320: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
L_801EA324:
    // 0x801EA324: nop

    // 0x801EA328: bltz        $a1, L_801EA318
    if (SIGNED(ctx->r5) < 0) {
        // 0x801EA32C: nop
    
            goto L_801EA318;
    }
    // 0x801EA32C: nop

L_801EA330:
    // 0x801EA330: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801EA334: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA338: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EA33C: lwc1        $f10, -0x2B64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B64);
    // 0x801EA340: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801EA344: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801EA348: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EA34C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801EA350: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801EA354: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801EA358: nop

    // 0x801EA35C: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801EA360: beql        $a2, $zero, L_801EA3B0
    if (ctx->r6 == 0) {
        // 0x801EA364: mfc1        $a2, $f16
        ctx->r6 = (int32_t)ctx->f16.u32l;
            goto L_801EA3B0;
    }
    goto skip_3;
    // 0x801EA364: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x801EA368: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801EA36C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EA370: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801EA374: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801EA378: nop

    // 0x801EA37C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801EA380: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801EA384: nop

    // 0x801EA388: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801EA38C: bne         $a2, $zero, L_801EA3A4
    if (ctx->r6 != 0) {
        // 0x801EA390: nop
    
            goto L_801EA3A4;
    }
    // 0x801EA390: nop

    // 0x801EA394: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801EA398: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EA39C: b           L_801EA3BC
    // 0x801EA3A0: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801EA3BC;
    // 0x801EA3A0: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801EA3A4:
    // 0x801EA3A4: b           L_801EA3BC
    // 0x801EA3A8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801EA3BC;
    // 0x801EA3A8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801EA3AC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
L_801EA3B0:
    // 0x801EA3B0: nop

    // 0x801EA3B4: bltz        $a2, L_801EA3A4
    if (SIGNED(ctx->r6) < 0) {
        // 0x801EA3B8: nop
    
            goto L_801EA3A4;
    }
    // 0x801EA3B8: nop

L_801EA3BC:
    // 0x801EA3BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801EA3C0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA3C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EA3C8: lwc1        $f18, -0x2B60($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B60);
    // 0x801EA3CC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801EA3D0: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EA3D4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EA3D8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801EA3DC: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801EA3E0: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EA3E4: nop

    // 0x801EA3E8: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EA3EC: beql        $a3, $zero, L_801EA43C
    if (ctx->r7 == 0) {
        // 0x801EA3F0: mfc1        $a3, $f4
        ctx->r7 = (int32_t)ctx->f4.u32l;
            goto L_801EA43C;
    }
    goto skip_4;
    // 0x801EA3F0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x801EA3F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EA3F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EA3FC: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801EA400: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EA404: nop

    // 0x801EA408: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801EA40C: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EA410: nop

    // 0x801EA414: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EA418: bne         $a3, $zero, L_801EA430
    if (ctx->r7 != 0) {
        // 0x801EA41C: nop
    
            goto L_801EA430;
    }
    // 0x801EA41C: nop

    // 0x801EA420: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801EA424: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EA428: b           L_801EA448
    // 0x801EA42C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801EA448;
    // 0x801EA42C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801EA430:
    // 0x801EA430: b           L_801EA448
    // 0x801EA434: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801EA448;
    // 0x801EA434: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801EA438: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
L_801EA43C:
    // 0x801EA43C: nop

    // 0x801EA440: bltz        $a3, L_801EA430
    if (SIGNED(ctx->r7) < 0) {
        // 0x801EA444: nop
    
            goto L_801EA430;
    }
    // 0x801EA444: nop

L_801EA448:
    // 0x801EA448: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801EA44C: jal         0x801CCE88
    // 0x801EA450: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_3;
    // 0x801EA450: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_3:
    // 0x801EA454: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA458: lwc1        $f6, -0x2B5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B5C);
    // 0x801EA45C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA460: lwc1        $f10, -0x2B58($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B58);
    // 0x801EA464: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA468: lwc1        $f18, -0x2B54($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B54);
    // 0x801EA46C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801EA470: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EA474: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x801EA478: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801EA47C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801EA480: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801EA484: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801EA488: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x801EA48C: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801EA490: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801EA494: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x801EA498: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x801EA49C: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x801EA4A0: jal         0x801CCEC8
    // 0x801EA4A4: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_4;
    // 0x801EA4A4: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_4:
    // 0x801EA4A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EA4AC:
    // 0x801EA4AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EA4B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EA4B4: jr          $ra
    // 0x801EA4B8: nop

    return;
    // 0x801EA4B8: nop

;}
RECOMP_FUNC void M25_FUN_801ea4bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EA4BC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA4C0: lwc1        $f4, -0x380C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X380C);
    // 0x801EA4C4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA4C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EA4CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EA4D0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801EA4D4: jr          $ra
    // 0x801EA4D8: swc1        $f4, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x801EA4D8: swc1        $f4, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ea4dc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ea4dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EA4DC: addiu       $sp, $sp, -0x220
    ctx->r29 = ADD32(ctx->r29, -0X220);
    // 0x801EA4E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EA4E4: sw          $a0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r4;
    // 0x801EA4E8: sw          $a1, 0x224($sp)
    MEM_W(0X224, ctx->r29) = ctx->r5;
    // 0x801EA4EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801EA4F0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801EA4F4: jal         0x801BF628
    // 0x801EA4F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801BF628)(rdram, ctx);
        goto after_0;
    // 0x801EA4F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801EA4FC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x801EA500: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801EA504: lui         $a1, 0x81
    ctx->r5 = S32(0X81 << 16);
    // 0x801EA508: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x801EA50C: bne         $at, $zero, L_801EA584
    if (ctx->r1 != 0) {
        // 0x801EA510: nop
    
            goto L_801EA584;
    }
    // 0x801EA510: nop

    // 0x801EA514: jal         0x801CCE0C
    // 0x801EA518: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_1;
    // 0x801EA518: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x801EA51C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801EA520: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801EA524: jal         0x801CCE50
    // 0x801EA528: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_2;
    // 0x801EA528: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_2:
    // 0x801EA52C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EA530: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801EA534: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801EA538: jal         0x801CCE88
    // 0x801EA53C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_3;
    // 0x801EA53C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_3:
    // 0x801EA540: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EA544: addiu       $a1, $zero, -0x64
    ctx->r5 = ADD32(0, -0X64);
    // 0x801EA548: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EA54C: jal         0x801CCEC8
    // 0x801EA550: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_4;
    // 0x801EA550: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x801EA554: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EA558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801EA55C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EA560: jal         0x801CCE88
    // 0x801EA564: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_5;
    // 0x801EA564: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x801EA568: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EA56C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801EA570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EA574: jal         0x801CCE88
    // 0x801EA578: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_6;
    // 0x801EA578: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x801EA57C: b           L_801EA6DC
    // 0x801EA580: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801EA6DC;
    // 0x801EA580: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801EA584:
    // 0x801EA584: jal         0x801C0B8C
    // 0x801EA588: ori         $a1, $a1, 0xB320
    ctx->r5 = ctx->r5 | 0XB320;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_7;
    // 0x801EA588: ori         $a1, $a1, 0xB320
    ctx->r5 = ctx->r5 | 0XB320;
    after_7:
    // 0x801EA58C: beq         $v0, $zero, L_801EA6D8
    if (ctx->r2 == 0) {
        // 0x801EA590: lui         $s0, 0x8020
        ctx->r16 = S32(0X8020 << 16);
            goto L_801EA6D8;
    }
    // 0x801EA590: lui         $s0, 0x8020
    ctx->r16 = S32(0X8020 << 16);
    // 0x801EA594: addiu       $s0, $s0, -0x2B50
    ctx->r16 = ADD32(ctx->r16, -0X2B50);
    // 0x801EA598: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA59C: lwc1        $f6, -0x3808($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3808);
    // 0x801EA5A0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801EA5A4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA5A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801EA5AC: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x801EA5B0: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801EA5B4: lwc1        $f10, -0x3804($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3804);
    // 0x801EA5B8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x801EA5BC: nop

    // 0x801EA5C0: bc1f        L_801EA5D4
    if (!c1cs) {
        // 0x801EA5C4: nop
    
            goto L_801EA5D4;
    }
    // 0x801EA5C4: nop

    // 0x801EA5C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801EA5CC: nop

    // 0x801EA5D0: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_801EA5D4:
    // 0x801EA5D4: jal         0x801CCE0C
    // 0x801EA5D8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_8;
    // 0x801EA5D8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x801EA5DC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801EA5E0: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801EA5E4: jal         0x801CCE50
    // 0x801EA5E8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_9;
    // 0x801EA5E8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_9:
    // 0x801EA5EC: jal         0x80032720
    // 0x801EA5F0: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80032720)(rdram, ctx);
        goto after_10;
    // 0x801EA5F0: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x801EA5F4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801EA5F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EA5FC: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801EA600: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801EA604: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801EA608: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x801EA60C: jal         0x80029280
    // 0x801EA610: sb          $t8, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_11;
    // 0x801EA610: sb          $t8, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r24;
    after_11:
    // 0x801EA614: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801EA618: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EA61C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EA620: addiu       $a1, $zero, 0xBC
    ctx->r5 = ADD32(0, 0XBC);
    // 0x801EA624: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801EA628: addiu       $a2, $zero, 0xBC
    ctx->r6 = ADD32(0, 0XBC);
    // 0x801EA62C: addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    // 0x801EA630: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801EA634: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x801EA638: jal         0x801CCE88
    // 0x801EA63C: sb          $t0, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_12;
    // 0x801EA63C: sb          $t0, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r8;
    after_12:
    // 0x801EA640: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EA644: lb          $a1, 0x27($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X27);
    // 0x801EA648: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801EA64C: jal         0x801CCEC8
    // 0x801EA650: lb          $a3, 0x25($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X25);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_13;
    // 0x801EA650: lb          $a3, 0x25($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X25);
    after_13:
    // 0x801EA654: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EA658: addiu       $a1, $zero, 0xBC
    ctx->r5 = ADD32(0, 0XBC);
    // 0x801EA65C: addiu       $a2, $zero, 0xBC
    ctx->r6 = ADD32(0, 0XBC);
    // 0x801EA660: jal         0x801CCE88
    // 0x801EA664: addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_14;
    // 0x801EA664: addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    after_14:
    // 0x801EA668: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA66C: lwc1        $f6, -0x3800($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3800);
    // 0x801EA670: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801EA674: jal         0x80032720
    // 0x801EA678: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x80032720)(rdram, ctx);
        goto after_15;
    // 0x801EA678: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_15:
    // 0x801EA67C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801EA680: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801EA684: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA688: lwc1        $f4, -0x37FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X37FC);
    // 0x801EA68C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801EA690: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801EA694: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801EA698: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801EA69C: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x801EA6A0: jal         0x80029280
    // 0x801EA6A4: sb          $t2, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_16;
    // 0x801EA6A4: sb          $t2, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r10;
    after_16:
    // 0x801EA6A8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801EA6AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801EA6B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EA6B4: lb          $a1, 0x27($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X27);
    // 0x801EA6B8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801EA6BC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801EA6C0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801EA6C4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801EA6C8: nop

    // 0x801EA6CC: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x801EA6D0: jal         0x801CCEC8
    // 0x801EA6D4: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_17;
    // 0x801EA6D4: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_17:
L_801EA6D8:
    // 0x801EA6D8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801EA6DC:
    // 0x801EA6DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EA6E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801EA6E4: addiu       $sp, $sp, 0x220
    ctx->r29 = ADD32(ctx->r29, 0X220);
    // 0x801EA6E8: jr          $ra
    // 0x801EA6EC: nop

    return;
    // 0x801EA6EC: nop

;}
RECOMP_FUNC void M25_FUN_801ea6f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EA6F0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801EA6F4: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x801EA6F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EA6FC: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x801EA700: lui         $a1, 0x57A
    ctx->r5 = S32(0X57A << 16);
    // 0x801EA704: ori         $a1, $a1, 0x897A
    ctx->r5 = ctx->r5 | 0X897A;
    // 0x801EA708: jal         0x801C0B8C
    // 0x801EA70C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EA70C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EA710: beq         $v0, $zero, L_801EA958
    if (ctx->r2 == 0) {
        // 0x801EA714: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801EA958;
    }
    // 0x801EA714: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EA718: lui         $t7, 0x8020
    ctx->r15 = S32(0X8020 << 16);
    // 0x801EA71C: addiu       $t7, $t7, -0x4428
    ctx->r15 = ADD32(ctx->r15, -0X4428);
    // 0x801EA720: addiu       $t1, $t7, 0x24
    ctx->r9 = ADD32(ctx->r15, 0X24);
    // 0x801EA724: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
L_801EA728:
    // 0x801EA728: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801EA72C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801EA730: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801EA734: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x801EA738: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801EA73C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x801EA740: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801EA744: bne         $t7, $t1, L_801EA728
    if (ctx->r15 != ctx->r9) {
        // 0x801EA748: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_801EA728;
    }
    // 0x801EA748: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x801EA74C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801EA750: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x801EA754: addiu       $t3, $t3, -0x4400
    ctx->r11 = ADD32(ctx->r11, -0X4400);
    // 0x801EA758: addiu       $t1, $t3, 0x24
    ctx->r9 = ADD32(ctx->r11, 0X24);
    // 0x801EA75C: addiu       $t2, $sp, 0x30
    ctx->r10 = ADD32(ctx->r29, 0X30);
    // 0x801EA760: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
L_801EA764:
    // 0x801EA764: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801EA768: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x801EA76C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x801EA770: sw          $t5, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r13;
    // 0x801EA774: lw          $t4, -0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, -0X8);
    // 0x801EA778: sw          $t4, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r12;
    // 0x801EA77C: lw          $t5, -0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, -0X4);
    // 0x801EA780: bne         $t3, $t1, L_801EA764
    if (ctx->r11 != ctx->r9) {
        // 0x801EA784: sw          $t5, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r13;
            goto L_801EA764;
    }
    // 0x801EA784: sw          $t5, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r13;
    // 0x801EA788: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801EA78C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EA790: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801EA794: jal         0x801C0F18
    // 0x801EA798: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    LOOKUP_FUNC(0x801C0F18)(rdram, ctx);
        goto after_1;
    // 0x801EA798: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    after_1:
    // 0x801EA79C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801EA7A0: jal         0x80034C24
    // 0x801EA7A4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_2;
    // 0x801EA7A4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x801EA7A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA7AC: lwc1        $f2, -0x4BD0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4BD0);
    // 0x801EA7B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA7B4: ldc1        $f4, -0x37F8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X37F8);
    // 0x801EA7B8: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801EA7BC: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801EA7C0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801EA7C4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x801EA7C8: nop

    // 0x801EA7CC: bc1f        L_801EA808
    if (!c1cs) {
        // 0x801EA7D0: nop
    
            goto L_801EA808;
    }
    // 0x801EA7D0: nop

    // 0x801EA7D4: lw          $t0, -0x4BD4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4BD4);
    // 0x801EA7D8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801EA7DC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x801EA7E0: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x801EA7E4: mfhi        $t0
    ctx->r8 = hi;
    // 0x801EA7E8: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x801EA7EC: addu        $t6, $sp, $t7
    ctx->r14 = ADD32(ctx->r29, ctx->r15);
    // 0x801EA7F0: lwc1        $f10, 0x58($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X58);
    // 0x801EA7F4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA7F8: sw          $t0, -0x4BD4($at)
    MEM_W(-0X4BD4, ctx->r1) = ctx->r8;
    // 0x801EA7FC: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x801EA800: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA804: swc1        $f2, -0x4BD0($at)
    MEM_W(-0X4BD0, ctx->r1) = ctx->f2.u32l;
L_801EA808:
    // 0x801EA808: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801EA80C: lw          $t0, -0x4BD4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4BD4);
    // 0x801EA810: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801EA814: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801EA818: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x801EA81C: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x801EA820: lwc1        $f16, 0x30($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X30);
    // 0x801EA824: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EA828: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EA82C: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801EA830: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EA834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801EA838: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EA83C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801EA840: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EA844: nop

    // 0x801EA848: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x801EA84C: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EA850: nop

    // 0x801EA854: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EA858: beql        $a3, $zero, L_801EA8A8
    if (ctx->r7 == 0) {
        // 0x801EA85C: mfc1        $a3, $f4
        ctx->r7 = (int32_t)ctx->f4.u32l;
            goto L_801EA8A8;
    }
    goto skip_0;
    // 0x801EA85C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x801EA860: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EA864: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EA868: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801EA86C: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EA870: nop

    // 0x801EA874: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801EA878: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EA87C: nop

    // 0x801EA880: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EA884: bne         $a3, $zero, L_801EA89C
    if (ctx->r7 != 0) {
        // 0x801EA888: nop
    
            goto L_801EA89C;
    }
    // 0x801EA888: nop

    // 0x801EA88C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801EA890: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EA894: b           L_801EA8B4
    // 0x801EA898: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801EA8B4;
    // 0x801EA898: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801EA89C:
    // 0x801EA89C: b           L_801EA8B4
    // 0x801EA8A0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801EA8B4;
    // 0x801EA8A0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801EA8A4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
L_801EA8A8:
    // 0x801EA8A8: nop

    // 0x801EA8AC: bltz        $a3, L_801EA89C
    if (SIGNED(ctx->r7) < 0) {
        // 0x801EA8B0: nop
    
            goto L_801EA89C;
    }
    // 0x801EA8B0: nop

L_801EA8B4:
    // 0x801EA8B4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801EA8B8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x801EA8BC: jal         0x801CCE88
    // 0x801EA8C0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_3;
    // 0x801EA8C0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_3:
    // 0x801EA8C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EA8C8: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801EA8CC: addiu       $a2, $zero, -0x14
    ctx->r6 = ADD32(0, -0X14);
    // 0x801EA8D0: jal         0x801CCEC8
    // 0x801EA8D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_4;
    // 0x801EA8D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x801EA8D8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EA8DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801EA8E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EA8E4: jal         0x801CCE88
    // 0x801EA8E8: lbu         $a3, 0x1B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1B);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_5;
    // 0x801EA8E8: lbu         $a3, 0x1B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1B);
    after_5:
    // 0x801EA8EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EA8F0: addiu       $a1, $zero, -0x50
    ctx->r5 = ADD32(0, -0X50);
    // 0x801EA8F4: addiu       $a2, $zero, -0x14
    ctx->r6 = ADD32(0, -0X14);
    // 0x801EA8F8: jal         0x801CCEC8
    // 0x801EA8FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_6;
    // 0x801EA8FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x801EA900: lui         $a1, 0x5F4
    ctx->r5 = S32(0X5F4 << 16);
    // 0x801EA904: ori         $a1, $a1, 0x9B7A
    ctx->r5 = ctx->r5 | 0X9B7A;
    // 0x801EA908: jal         0x801C0B8C
    // 0x801EA90C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_7;
    // 0x801EA90C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_7:
    // 0x801EA910: beq         $v0, $zero, L_801EA950
    if (ctx->r2 == 0) {
        // 0x801EA914: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801EA950;
    }
    // 0x801EA914: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EA918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801EA91C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EA920: jal         0x801CCE88
    // 0x801EA924: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_8;
    // 0x801EA924: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x801EA928: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801EA92C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801EA930: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801EA934: jal         0x801CCE88
    // 0x801EA938: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_9;
    // 0x801EA938: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x801EA93C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EA940: jal         0x801C0EB0
    // 0x801EA944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C0EB0)(rdram, ctx);
        goto after_10;
    // 0x801EA944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x801EA948: b           L_801EA978
    // 0x801EA94C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801EA978;
    // 0x801EA94C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801EA950:
    // 0x801EA950: b           L_801EA978
    // 0x801EA954: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801EA978;
    // 0x801EA954: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801EA958:
    // 0x801EA958: jal         0x801C0D04
    // 0x801EA95C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C0D04)(rdram, ctx);
        goto after_11;
    // 0x801EA95C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x801EA960: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801EA964: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA968: sw          $zero, -0x4BD4($at)
    MEM_W(-0X4BD4, ctx->r1) = 0;
    // 0x801EA96C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EA970: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801EA974: swc1        $f2, -0x4BD0($at)
    MEM_W(-0X4BD0, ctx->r1) = ctx->f2.u32l;
L_801EA978:
    // 0x801EA978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EA97C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x801EA980: jr          $ra
    // 0x801EA984: nop

    return;
    // 0x801EA984: nop

;}
RECOMP_FUNC void M25_FUN_801ea988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EA988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EA98C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EA990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EA994: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EA998: lui         $a1, 0x6FF
    ctx->r5 = S32(0X6FF << 16);
    // 0x801EA99C: ori         $a1, $a1, 0xA2DA
    ctx->r5 = ctx->r5 | 0XA2DA;
    // 0x801EA9A0: jal         0x801C0B8C
    // 0x801EA9A4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EA9A4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EA9A8: beql        $v0, $zero, L_801EAE00
    if (ctx->r2 == 0) {
        // 0x801EA9AC: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_801EAE00;
    }
    goto skip_0;
    // 0x801EA9AC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    skip_0:
    // 0x801EA9B0: jal         0x801CCE0C
    // 0x801EA9B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_1;
    // 0x801EA9B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x801EA9B8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801EA9BC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801EA9C0: jal         0x801CCE50
    // 0x801EA9C4: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_2;
    // 0x801EA9C4: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_2:
    // 0x801EA9C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801EA9CC: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801EA9D0: addiu       $v0, $v0, -0x2B68
    ctx->r2 = ADD32(ctx->r2, -0X2B68);
    // 0x801EA9D4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801EA9D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EA9DC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801EA9E0: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801EA9E4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801EA9E8: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801EA9EC: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801EA9F0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801EA9F4: addiu       $t0, $t0, -0x2B60
    ctx->r8 = ADD32(ctx->r8, -0X2B60);
    // 0x801EA9F8: addiu       $v1, $v1, -0x2B64
    ctx->r3 = ADD32(ctx->r3, -0X2B64);
    // 0x801EA9FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EAA00: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801EAA04: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801EAA08: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x801EAA0C: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801EAA10: beq         $a1, $zero, L_801EAA5C
    if (ctx->r5 == 0) {
        // 0x801EAA14: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_801EAA5C;
    }
    // 0x801EAA14: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EAA18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801EAA1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EAA20: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801EAA24: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801EAA28: nop

    // 0x801EAA2C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801EAA30: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801EAA34: nop

    // 0x801EAA38: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801EAA3C: bne         $a1, $zero, L_801EAA54
    if (ctx->r5 != 0) {
        // 0x801EAA40: nop
    
            goto L_801EAA54;
    }
    // 0x801EAA40: nop

    // 0x801EAA44: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801EAA48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EAA4C: b           L_801EAA6C
    // 0x801EAA50: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801EAA6C;
    // 0x801EAA50: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801EAA54:
    // 0x801EAA54: b           L_801EAA6C
    // 0x801EAA58: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801EAA6C;
    // 0x801EAA58: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_801EAA5C:
    // 0x801EAA5C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801EAA60: nop

    // 0x801EAA64: bltz        $a1, L_801EAA54
    if (SIGNED(ctx->r5) < 0) {
        // 0x801EAA68: nop
    
            goto L_801EAA54;
    }
    // 0x801EAA68: nop

L_801EAA6C:
    // 0x801EAA6C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801EAA70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EAA74: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801EAA78: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801EAA7C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801EAA80: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801EAA84: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EAA88: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801EAA8C: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801EAA90: nop

    // 0x801EAA94: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801EAA98: beql        $a2, $zero, L_801EAAE8
    if (ctx->r6 == 0) {
        // 0x801EAA9C: mfc1        $a2, $f10
        ctx->r6 = (int32_t)ctx->f10.u32l;
            goto L_801EAAE8;
    }
    goto skip_1;
    // 0x801EAA9C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x801EAAA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EAAA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EAAA8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801EAAAC: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801EAAB0: nop

    // 0x801EAAB4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801EAAB8: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801EAABC: nop

    // 0x801EAAC0: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801EAAC4: bne         $a2, $zero, L_801EAADC
    if (ctx->r6 != 0) {
        // 0x801EAAC8: nop
    
            goto L_801EAADC;
    }
    // 0x801EAAC8: nop

    // 0x801EAACC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801EAAD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EAAD4: b           L_801EAAF4
    // 0x801EAAD8: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801EAAF4;
    // 0x801EAAD8: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801EAADC:
    // 0x801EAADC: b           L_801EAAF4
    // 0x801EAAE0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801EAAF4;
    // 0x801EAAE0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801EAAE4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
L_801EAAE8:
    // 0x801EAAE8: nop

    // 0x801EAAEC: bltz        $a2, L_801EAADC
    if (SIGNED(ctx->r6) < 0) {
        // 0x801EAAF0: nop
    
            goto L_801EAADC;
    }
    // 0x801EAAF0: nop

L_801EAAF4:
    // 0x801EAAF4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801EAAF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EAAFC: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801EAB00: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801EAB04: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801EAB08: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EAB0C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EAB10: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801EAB14: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EAB18: nop

    // 0x801EAB1C: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EAB20: beql        $a3, $zero, L_801EAB70
    if (ctx->r7 == 0) {
        // 0x801EAB24: mfc1        $a3, $f18
        ctx->r7 = (int32_t)ctx->f18.u32l;
            goto L_801EAB70;
    }
    goto skip_2;
    // 0x801EAB24: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x801EAB28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801EAB2C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EAB30: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801EAB34: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EAB38: nop

    // 0x801EAB3C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801EAB40: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EAB44: nop

    // 0x801EAB48: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EAB4C: bne         $a3, $zero, L_801EAB64
    if (ctx->r7 != 0) {
        // 0x801EAB50: nop
    
            goto L_801EAB64;
    }
    // 0x801EAB50: nop

    // 0x801EAB54: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801EAB58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EAB5C: b           L_801EAB7C
    // 0x801EAB60: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801EAB7C;
    // 0x801EAB60: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801EAB64:
    // 0x801EAB64: b           L_801EAB7C
    // 0x801EAB68: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801EAB7C;
    // 0x801EAB68: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801EAB6C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
L_801EAB70:
    // 0x801EAB70: nop

    // 0x801EAB74: bltz        $a3, L_801EAB64
    if (SIGNED(ctx->r7) < 0) {
        // 0x801EAB78: nop
    
            goto L_801EAB64;
    }
    // 0x801EAB78: nop

L_801EAB7C:
    // 0x801EAB7C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801EAB80: jal         0x801CCE88
    // 0x801EAB84: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_3;
    // 0x801EAB84: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_3:
    // 0x801EAB88: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EAB8C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801EAB90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EAB94: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801EAB98: lwc1        $f4, -0x2B68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B68);
    // 0x801EAB9C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EABA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EABA4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801EABA8: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801EABAC: nop

    // 0x801EABB0: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801EABB4: beql        $a1, $zero, L_801EAC04
    if (ctx->r5 == 0) {
        // 0x801EABB8: mfc1        $a1, $f6
        ctx->r5 = (int32_t)ctx->f6.u32l;
            goto L_801EAC04;
    }
    goto skip_3;
    // 0x801EABB8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x801EABBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801EABC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EABC4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801EABC8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801EABCC: nop

    // 0x801EABD0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801EABD4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801EABD8: nop

    // 0x801EABDC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801EABE0: bne         $a1, $zero, L_801EABF8
    if (ctx->r5 != 0) {
        // 0x801EABE4: nop
    
            goto L_801EABF8;
    }
    // 0x801EABE4: nop

    // 0x801EABE8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801EABEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EABF0: b           L_801EAC10
    // 0x801EABF4: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801EAC10;
    // 0x801EABF4: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801EABF8:
    // 0x801EABF8: b           L_801EAC10
    // 0x801EABFC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801EAC10;
    // 0x801EABFC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801EAC00: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
L_801EAC04:
    // 0x801EAC04: nop

    // 0x801EAC08: bltz        $a1, L_801EABF8
    if (SIGNED(ctx->r5) < 0) {
        // 0x801EAC0C: nop
    
            goto L_801EABF8;
    }
    // 0x801EAC0C: nop

L_801EAC10:
    // 0x801EAC10: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801EAC14: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EAC18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EAC1C: lwc1        $f8, -0x2B64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B64);
    // 0x801EAC20: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801EAC24: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801EAC28: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EAC2C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801EAC30: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801EAC34: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801EAC38: nop

    // 0x801EAC3C: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801EAC40: beql        $a2, $zero, L_801EAC90
    if (ctx->r6 == 0) {
        // 0x801EAC44: mfc1        $a2, $f10
        ctx->r6 = (int32_t)ctx->f10.u32l;
            goto L_801EAC90;
    }
    goto skip_4;
    // 0x801EAC44: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x801EAC48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EAC4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EAC50: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801EAC54: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801EAC58: nop

    // 0x801EAC5C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801EAC60: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801EAC64: nop

    // 0x801EAC68: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801EAC6C: bne         $a2, $zero, L_801EAC84
    if (ctx->r6 != 0) {
        // 0x801EAC70: nop
    
            goto L_801EAC84;
    }
    // 0x801EAC70: nop

    // 0x801EAC74: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801EAC78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EAC7C: b           L_801EAC9C
    // 0x801EAC80: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801EAC9C;
    // 0x801EAC80: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801EAC84:
    // 0x801EAC84: b           L_801EAC9C
    // 0x801EAC88: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801EAC9C;
    // 0x801EAC88: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801EAC8C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
L_801EAC90:
    // 0x801EAC90: nop

    // 0x801EAC94: bltz        $a2, L_801EAC84
    if (SIGNED(ctx->r6) < 0) {
        // 0x801EAC98: nop
    
            goto L_801EAC84;
    }
    // 0x801EAC98: nop

L_801EAC9C:
    // 0x801EAC9C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801EACA0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EACA4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EACA8: lwc1        $f16, -0x2B60($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B60);
    // 0x801EACAC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801EACB0: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EACB4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EACB8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801EACBC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801EACC0: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EACC4: nop

    // 0x801EACC8: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EACCC: beql        $a3, $zero, L_801EAD1C
    if (ctx->r7 == 0) {
        // 0x801EACD0: mfc1        $a3, $f18
        ctx->r7 = (int32_t)ctx->f18.u32l;
            goto L_801EAD1C;
    }
    goto skip_5;
    // 0x801EACD0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    skip_5:
    // 0x801EACD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801EACD8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EACDC: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801EACE0: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EACE4: nop

    // 0x801EACE8: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801EACEC: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EACF0: nop

    // 0x801EACF4: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EACF8: bne         $a3, $zero, L_801EAD10
    if (ctx->r7 != 0) {
        // 0x801EACFC: nop
    
            goto L_801EAD10;
    }
    // 0x801EACFC: nop

    // 0x801EAD00: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801EAD04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EAD08: b           L_801EAD28
    // 0x801EAD0C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801EAD28;
    // 0x801EAD0C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801EAD10:
    // 0x801EAD10: b           L_801EAD28
    // 0x801EAD14: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801EAD28;
    // 0x801EAD14: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801EAD18: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
L_801EAD1C:
    // 0x801EAD1C: nop

    // 0x801EAD20: bltz        $a3, L_801EAD10
    if (SIGNED(ctx->r7) < 0) {
        // 0x801EAD24: nop
    
            goto L_801EAD10;
    }
    // 0x801EAD24: nop

L_801EAD28:
    // 0x801EAD28: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801EAD2C: jal         0x801CCE88
    // 0x801EAD30: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_4;
    // 0x801EAD30: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_4:
    // 0x801EAD34: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801EAD38: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801EAD3C: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801EAD40: addiu       $v0, $v0, -0x2B5C
    ctx->r2 = ADD32(ctx->r2, -0X2B5C);
    // 0x801EAD44: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801EAD48: addiu       $v1, $v1, -0x2B58
    ctx->r3 = ADD32(ctx->r3, -0X2B58);
    // 0x801EAD4C: addiu       $t0, $t0, -0x2B54
    ctx->r8 = ADD32(ctx->r8, -0X2B54);
    // 0x801EAD50: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x801EAD54: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801EAD58: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x801EAD5C: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801EAD60: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801EAD64: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x801EAD68: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801EAD6C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x801EAD70: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801EAD74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EAD78: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801EAD7C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801EAD80: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x801EAD84: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801EAD88: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801EAD8C: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x801EAD90: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x801EAD94: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x801EAD98: jal         0x801CCEC8
    // 0x801EAD9C: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_5;
    // 0x801EAD9C: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_5:
    // 0x801EADA0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EADA4: lwc1        $f4, -0x2B5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B5C);
    // 0x801EADA8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EADAC: lwc1        $f10, -0x2B58($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B58);
    // 0x801EADB0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EADB4: lwc1        $f18, -0x2B54($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B54);
    // 0x801EADB8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x801EADBC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801EADC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EADC4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801EADC8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801EADCC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801EADD0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801EADD4: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x801EADD8: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x801EADDC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801EADE0: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x801EADE4: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801EADE8: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x801EADEC: jal         0x801CCEC8
    // 0x801EADF0: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_6;
    // 0x801EADF0: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_6:
    // 0x801EADF4: b           L_801EAE00
    // 0x801EADF8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801EAE00;
    // 0x801EADF8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x801EADFC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801EAE00:
    // 0x801EAE00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EAE04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EAE08: jr          $ra
    // 0x801EAE0C: nop

    return;
    // 0x801EAE0C: nop

;}
RECOMP_FUNC void M25_FUN_801eae10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EAE10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EAE14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EAE18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EAE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EAE20: lui         $a1, 0x739
    ctx->r5 = S32(0X739 << 16);
    // 0x801EAE24: ori         $a1, $a1, 0x9E9A
    ctx->r5 = ctx->r5 | 0X9E9A;
    // 0x801EAE28: jal         0x801C0B8C
    // 0x801EAE2C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EAE2C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EAE30: beq         $v0, $zero, L_801EAE40
    if (ctx->r2 == 0) {
        // 0x801EAE34: lui         $v1, 0x8020
        ctx->r3 = S32(0X8020 << 16);
            goto L_801EAE40;
    }
    // 0x801EAE34: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801EAE38: b           L_801EB2B8
    // 0x801EAE3C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801EB2B8;
    // 0x801EAE3C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801EAE40:
    // 0x801EAE40: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801EAE44: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EAE48: lwc1        $f0, -0x37F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X37F0);
    // 0x801EAE4C: addiu       $v0, $v0, -0x2B68
    ctx->r2 = ADD32(ctx->r2, -0X2B68);
    // 0x801EAE50: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801EAE54: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801EAE58: addiu       $t0, $t0, -0x2B60
    ctx->r8 = ADD32(ctx->r8, -0X2B60);
    // 0x801EAE5C: addiu       $v1, $v1, -0x2B64
    ctx->r3 = ADD32(ctx->r3, -0X2B64);
    // 0x801EAE60: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801EAE64: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801EAE68: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x801EAE6C: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x801EAE70: addiu       $t1, $t1, -0x2B5C
    ctx->r9 = ADD32(ctx->r9, -0X2B5C);
    // 0x801EAE74: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801EAE78: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801EAE7C: lui         $t2, 0x8020
    ctx->r10 = S32(0X8020 << 16);
    // 0x801EAE80: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801EAE84: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x801EAE88: addiu       $t2, $t2, -0x2B58
    ctx->r10 = ADD32(ctx->r10, -0X2B58);
    // 0x801EAE8C: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x801EAE90: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x801EAE94: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EAE98: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x801EAE9C: lwc1        $f8, -0x37EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X37EC);
    // 0x801EAEA0: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801EAEA4: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x801EAEA8: addiu       $t3, $t3, -0x2B54
    ctx->r11 = ADD32(ctx->r11, -0X2B54);
    // 0x801EAEAC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801EAEB0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EAEB4: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801EAEB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EAEBC: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x801EAEC0: lwc1        $f18, -0x37E8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X37E8);
    // 0x801EAEC4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801EAEC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EAECC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801EAED0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801EAED4: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801EAED8: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x801EAEDC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801EAEE0: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801EAEE4: nop

    // 0x801EAEE8: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801EAEEC: beq         $a1, $zero, L_801EAF38
    if (ctx->r5 == 0) {
        // 0x801EAEF0: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_801EAF38;
    }
    // 0x801EAEF0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EAEF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801EAEF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EAEFC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801EAF00: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801EAF04: nop

    // 0x801EAF08: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801EAF0C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801EAF10: nop

    // 0x801EAF14: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801EAF18: bne         $a1, $zero, L_801EAF30
    if (ctx->r5 != 0) {
        // 0x801EAF1C: nop
    
            goto L_801EAF30;
    }
    // 0x801EAF1C: nop

    // 0x801EAF20: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801EAF24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EAF28: b           L_801EAF48
    // 0x801EAF2C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801EAF48;
    // 0x801EAF2C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801EAF30:
    // 0x801EAF30: b           L_801EAF48
    // 0x801EAF34: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801EAF48;
    // 0x801EAF34: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_801EAF38:
    // 0x801EAF38: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801EAF3C: nop

    // 0x801EAF40: bltz        $a1, L_801EAF30
    if (SIGNED(ctx->r5) < 0) {
        // 0x801EAF44: nop
    
            goto L_801EAF30;
    }
    // 0x801EAF44: nop

L_801EAF48:
    // 0x801EAF48: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801EAF4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EAF50: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801EAF54: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801EAF58: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801EAF5C: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801EAF60: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EAF64: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801EAF68: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801EAF6C: nop

    // 0x801EAF70: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801EAF74: beql        $a2, $zero, L_801EAFC4
    if (ctx->r6 == 0) {
        // 0x801EAF78: mfc1        $a2, $f16
        ctx->r6 = (int32_t)ctx->f16.u32l;
            goto L_801EAFC4;
    }
    goto skip_0;
    // 0x801EAF78: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801EAF7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801EAF80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EAF84: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801EAF88: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801EAF8C: nop

    // 0x801EAF90: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801EAF94: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801EAF98: nop

    // 0x801EAF9C: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801EAFA0: bne         $a2, $zero, L_801EAFB8
    if (ctx->r6 != 0) {
        // 0x801EAFA4: nop
    
            goto L_801EAFB8;
    }
    // 0x801EAFA4: nop

    // 0x801EAFA8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801EAFAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EAFB0: b           L_801EAFD0
    // 0x801EAFB4: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801EAFD0;
    // 0x801EAFB4: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801EAFB8:
    // 0x801EAFB8: b           L_801EAFD0
    // 0x801EAFBC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801EAFD0;
    // 0x801EAFBC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801EAFC0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
L_801EAFC4:
    // 0x801EAFC4: nop

    // 0x801EAFC8: bltz        $a2, L_801EAFB8
    if (SIGNED(ctx->r6) < 0) {
        // 0x801EAFCC: nop
    
            goto L_801EAFB8;
    }
    // 0x801EAFCC: nop

L_801EAFD0:
    // 0x801EAFD0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801EAFD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EAFD8: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801EAFDC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801EAFE0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801EAFE4: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EAFE8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EAFEC: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801EAFF0: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EAFF4: nop

    // 0x801EAFF8: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EAFFC: beql        $a3, $zero, L_801EB04C
    if (ctx->r7 == 0) {
        // 0x801EB000: mfc1        $a3, $f4
        ctx->r7 = (int32_t)ctx->f4.u32l;
            goto L_801EB04C;
    }
    goto skip_1;
    // 0x801EB000: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x801EB004: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EB008: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EB00C: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801EB010: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EB014: nop

    // 0x801EB018: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801EB01C: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EB020: nop

    // 0x801EB024: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EB028: bne         $a3, $zero, L_801EB040
    if (ctx->r7 != 0) {
        // 0x801EB02C: nop
    
            goto L_801EB040;
    }
    // 0x801EB02C: nop

    // 0x801EB030: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801EB034: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EB038: b           L_801EB058
    // 0x801EB03C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801EB058;
    // 0x801EB03C: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801EB040:
    // 0x801EB040: b           L_801EB058
    // 0x801EB044: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801EB058;
    // 0x801EB044: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801EB048: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
L_801EB04C:
    // 0x801EB04C: nop

    // 0x801EB050: bltz        $a3, L_801EB040
    if (SIGNED(ctx->r7) < 0) {
        // 0x801EB054: nop
    
            goto L_801EB040;
    }
    // 0x801EB054: nop

L_801EB058:
    // 0x801EB058: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801EB05C: jal         0x801CCE88
    // 0x801EB060: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_1;
    // 0x801EB060: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_1:
    // 0x801EB064: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB068: lwc1        $f18, -0x2B5C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B5C);
    // 0x801EB06C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB070: lwc1        $f16, -0x2B58($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B58);
    // 0x801EB074: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801EB078: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB07C: lwc1        $f14, -0x2B54($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2B54);
    // 0x801EB080: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801EB084: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801EB088: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EB08C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x801EB090: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801EB094: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x801EB098: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801EB09C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x801EB0A0: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x801EB0A4: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x801EB0A8: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x801EB0AC: jal         0x801CCEC8
    // 0x801EB0B0: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_2;
    // 0x801EB0B0: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_2:
    // 0x801EB0B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB0B8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801EB0BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EB0C0: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801EB0C4: lwc1        $f6, -0x2B68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B68);
    // 0x801EB0C8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EB0CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EB0D0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801EB0D4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801EB0D8: nop

    // 0x801EB0DC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801EB0E0: beql        $a1, $zero, L_801EB130
    if (ctx->r5 == 0) {
        // 0x801EB0E4: mfc1        $a1, $f8
        ctx->r5 = (int32_t)ctx->f8.u32l;
            goto L_801EB130;
    }
    goto skip_2;
    // 0x801EB0E4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x801EB0E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801EB0EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801EB0F0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801EB0F4: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801EB0F8: nop

    // 0x801EB0FC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801EB100: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801EB104: nop

    // 0x801EB108: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801EB10C: bne         $a1, $zero, L_801EB124
    if (ctx->r5 != 0) {
        // 0x801EB110: nop
    
            goto L_801EB124;
    }
    // 0x801EB110: nop

    // 0x801EB114: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801EB118: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EB11C: b           L_801EB13C
    // 0x801EB120: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801EB13C;
    // 0x801EB120: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801EB124:
    // 0x801EB124: b           L_801EB13C
    // 0x801EB128: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801EB13C;
    // 0x801EB128: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801EB12C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
L_801EB130:
    // 0x801EB130: nop

    // 0x801EB134: bltz        $a1, L_801EB124
    if (SIGNED(ctx->r5) < 0) {
        // 0x801EB138: nop
    
            goto L_801EB124;
    }
    // 0x801EB138: nop

L_801EB13C:
    // 0x801EB13C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801EB140: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB144: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EB148: lwc1        $f10, -0x2B64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B64);
    // 0x801EB14C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801EB150: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801EB154: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EB158: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801EB15C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801EB160: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801EB164: nop

    // 0x801EB168: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801EB16C: beql        $a2, $zero, L_801EB1BC
    if (ctx->r6 == 0) {
        // 0x801EB170: mfc1        $a2, $f16
        ctx->r6 = (int32_t)ctx->f16.u32l;
            goto L_801EB1BC;
    }
    goto skip_3;
    // 0x801EB170: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x801EB174: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801EB178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801EB17C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801EB180: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x801EB184: nop

    // 0x801EB188: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801EB18C: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x801EB190: nop

    // 0x801EB194: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x801EB198: bne         $a2, $zero, L_801EB1B0
    if (ctx->r6 != 0) {
        // 0x801EB19C: nop
    
            goto L_801EB1B0;
    }
    // 0x801EB19C: nop

    // 0x801EB1A0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801EB1A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EB1A8: b           L_801EB1C8
    // 0x801EB1AC: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_801EB1C8;
    // 0x801EB1AC: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_801EB1B0:
    // 0x801EB1B0: b           L_801EB1C8
    // 0x801EB1B4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_801EB1C8;
    // 0x801EB1B4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801EB1B8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
L_801EB1BC:
    // 0x801EB1BC: nop

    // 0x801EB1C0: bltz        $a2, L_801EB1B0
    if (SIGNED(ctx->r6) < 0) {
        // 0x801EB1C4: nop
    
            goto L_801EB1B0;
    }
    // 0x801EB1C4: nop

L_801EB1C8:
    // 0x801EB1C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801EB1CC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB1D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EB1D4: lwc1        $f18, -0x2B60($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B60);
    // 0x801EB1D8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801EB1DC: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EB1E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801EB1E4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801EB1E8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801EB1EC: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EB1F0: nop

    // 0x801EB1F4: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EB1F8: beql        $a3, $zero, L_801EB248
    if (ctx->r7 == 0) {
        // 0x801EB1FC: mfc1        $a3, $f4
        ctx->r7 = (int32_t)ctx->f4.u32l;
            goto L_801EB248;
    }
    goto skip_4;
    // 0x801EB1FC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x801EB200: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EB204: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801EB208: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801EB20C: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x801EB210: nop

    // 0x801EB214: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801EB218: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x801EB21C: nop

    // 0x801EB220: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x801EB224: bne         $a3, $zero, L_801EB23C
    if (ctx->r7 != 0) {
        // 0x801EB228: nop
    
            goto L_801EB23C;
    }
    // 0x801EB228: nop

    // 0x801EB22C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801EB230: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801EB234: b           L_801EB254
    // 0x801EB238: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_801EB254;
    // 0x801EB238: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_801EB23C:
    // 0x801EB23C: b           L_801EB254
    // 0x801EB240: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_801EB254;
    // 0x801EB240: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x801EB244: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
L_801EB248:
    // 0x801EB248: nop

    // 0x801EB24C: bltz        $a3, L_801EB23C
    if (SIGNED(ctx->r7) < 0) {
        // 0x801EB250: nop
    
            goto L_801EB23C;
    }
    // 0x801EB250: nop

L_801EB254:
    // 0x801EB254: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801EB258: jal         0x801CCE88
    // 0x801EB25C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_3;
    // 0x801EB25C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_3:
    // 0x801EB260: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB264: lwc1        $f6, -0x2B5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B5C);
    // 0x801EB268: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB26C: lwc1        $f10, -0x2B58($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B58);
    // 0x801EB270: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB274: lwc1        $f18, -0x2B54($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B54);
    // 0x801EB278: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801EB27C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EB280: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x801EB284: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801EB288: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801EB28C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801EB290: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801EB294: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x801EB298: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x801EB29C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801EB2A0: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x801EB2A4: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x801EB2A8: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x801EB2AC: jal         0x801CCEC8
    // 0x801EB2B0: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_4;
    // 0x801EB2B0: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_4:
    // 0x801EB2B4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801EB2B8:
    // 0x801EB2B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EB2BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EB2C0: jr          $ra
    // 0x801EB2C4: nop

    return;
    // 0x801EB2C4: nop

;}
RECOMP_FUNC void M25_FUN_801eb2c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EB2C8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB2CC: lwc1        $f4, -0x37E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X37E4);
    // 0x801EB2D0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB2D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EB2D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EB2DC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x801EB2E0: jr          $ra
    // 0x801EB2E4: swc1        $f4, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x801EB2E4: swc1        $f4, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eb2e8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eb2e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EB2E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801EB2EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801EB2F0: lui         $s0, 0x8020
    ctx->r16 = S32(0X8020 << 16);
    // 0x801EB2F4: addiu       $s0, $s0, -0x2B50
    ctx->r16 = ADD32(ctx->r16, -0X2B50);
    // 0x801EB2F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB2FC: lwc1        $f6, -0x37E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X37E0);
    // 0x801EB300: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801EB304: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB308: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801EB30C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801EB310: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801EB314: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801EB318: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x801EB31C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801EB320: lwc1        $f10, -0x37DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X37DC);
    // 0x801EB324: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x801EB328: nop

    // 0x801EB32C: bc1f        L_801EB340
    if (!c1cs) {
        // 0x801EB330: nop
    
            goto L_801EB340;
    }
    // 0x801EB330: nop

    // 0x801EB334: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801EB338: nop

    // 0x801EB33C: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_801EB340:
    // 0x801EB340: jal         0x801CCE0C
    // 0x801EB344: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_0;
    // 0x801EB344: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x801EB348: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801EB34C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801EB350: jal         0x801CCE50
    // 0x801EB354: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_1;
    // 0x801EB354: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x801EB358: jal         0x80032720
    // 0x801EB35C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80032720)(rdram, ctx);
        goto after_2;
    // 0x801EB35C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x801EB360: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801EB364: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801EB368: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801EB36C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801EB370: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801EB374: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x801EB378: jal         0x80029280
    // 0x801EB37C: sb          $t7, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_3;
    // 0x801EB37C: sb          $t7, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r15;
    after_3:
    // 0x801EB380: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801EB384: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801EB388: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EB38C: addiu       $a1, $zero, 0xBC
    ctx->r5 = ADD32(0, 0XBC);
    // 0x801EB390: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801EB394: addiu       $a2, $zero, 0xBC
    ctx->r6 = ADD32(0, 0XBC);
    // 0x801EB398: addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    // 0x801EB39C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801EB3A0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x801EB3A4: jal         0x801CCE88
    // 0x801EB3A8: sb          $t9, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_4;
    // 0x801EB3A8: sb          $t9, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r25;
    after_4:
    // 0x801EB3AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EB3B0: lb          $a1, 0x27($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X27);
    // 0x801EB3B4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801EB3B8: jal         0x801CCEC8
    // 0x801EB3BC: lb          $a3, 0x25($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X25);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_5;
    // 0x801EB3BC: lb          $a3, 0x25($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X25);
    after_5:
    // 0x801EB3C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EB3C4: addiu       $a1, $zero, 0xBC
    ctx->r5 = ADD32(0, 0XBC);
    // 0x801EB3C8: addiu       $a2, $zero, 0xBC
    ctx->r6 = ADD32(0, 0XBC);
    // 0x801EB3CC: jal         0x801CCE88
    // 0x801EB3D0: addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_6;
    // 0x801EB3D0: addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    after_6:
    // 0x801EB3D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB3D8: lwc1        $f6, -0x37D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X37D8);
    // 0x801EB3DC: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801EB3E0: jal         0x80032720
    // 0x801EB3E4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x80032720)(rdram, ctx);
        goto after_7;
    // 0x801EB3E4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_7:
    // 0x801EB3E8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801EB3EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801EB3F0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EB3F4: lwc1        $f4, -0x37D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X37D4);
    // 0x801EB3F8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801EB3FC: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801EB400: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801EB404: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801EB408: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x801EB40C: jal         0x80029280
    // 0x801EB410: sb          $t1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_8;
    // 0x801EB410: sb          $t1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r9;
    after_8:
    // 0x801EB414: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801EB418: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801EB41C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EB420: lb          $a1, 0x27($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X27);
    // 0x801EB424: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801EB428: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801EB42C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801EB430: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801EB434: nop

    // 0x801EB438: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x801EB43C: jal         0x801CCEC8
    // 0x801EB440: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_9;
    // 0x801EB440: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_9:
    // 0x801EB444: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801EB448: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801EB44C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801EB450: jr          $ra
    // 0x801EB454: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x801EB454: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eb458(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eb458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EB458: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EB45C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EB460: jr          $ra
    // 0x801EB464: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x801EB464: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801eb468(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801eb468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EB468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EB46C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EB470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EB474: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EB478: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801EB47C: addiu       $a1, $a1, -0x2298
    ctx->r5 = ADD32(ctx->r5, -0X2298);
    // 0x801EB480: jal         0x801C2420
    // 0x801EB484: addiu       $a0, $zero, 0x260
    ctx->r4 = ADD32(0, 0X260);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_0;
    // 0x801EB484: addiu       $a0, $zero, 0x260
    ctx->r4 = ADD32(0, 0X260);
    after_0:
    // 0x801EB488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EB48C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EB490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801EB494: jr          $ra
    // 0x801EB498: nop

    return;
    // 0x801EB498: nop

;}
