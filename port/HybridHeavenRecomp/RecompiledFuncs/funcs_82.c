#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M8_FUN_801d7adc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7AE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7AE8: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7AEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7AF0: bne         $t6, $at, L_801D7B08
    if (ctx->r14 != ctx->r1) {
        // 0x801D7AF4: nop
    
            goto L_801D7B08;
    }
    // 0x801D7AF4: nop

    // 0x801D7AF8: jal         0x801FCBA8
    // 0x801D7AFC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_0;
    // 0x801D7AFC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_0:
    // 0x801D7B00: b           L_801D7B14
    // 0x801D7B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7B14;
    // 0x801D7B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7B08:
    // 0x801D7B08: jal         0x801FCBA8
    // 0x801D7B0C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_1;
    // 0x801D7B0C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_1:
    // 0x801D7B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7B14:
    // 0x801D7B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7B18: jr          $ra
    // 0x801D7B1C: nop

    return;
    // 0x801D7B1C: nop

;}
RECOMP_FUNC void M8_FUN_801d7b20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7B28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7B2C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7B30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7B34: bne         $t6, $at, L_801D7B4C
    if (ctx->r14 != ctx->r1) {
        // 0x801D7B38: nop
    
            goto L_801D7B4C;
    }
    // 0x801D7B38: nop

    // 0x801D7B3C: jal         0x801FCBA8
    // 0x801D7B40: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_0;
    // 0x801D7B40: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    after_0:
    // 0x801D7B44: b           L_801D7B58
    // 0x801D7B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7B58;
    // 0x801D7B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7B4C:
    // 0x801D7B4C: jal         0x801FCBA8
    // 0x801D7B50: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_1;
    // 0x801D7B50: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_1:
    // 0x801D7B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7B58:
    // 0x801D7B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7B5C: jr          $ra
    // 0x801D7B60: nop

    return;
    // 0x801D7B60: nop

;}
RECOMP_FUNC void M8_FUN_801d7b64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7B64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7B6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7B70: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7B74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7B78: bne         $t6, $at, L_801D7B90
    if (ctx->r14 != ctx->r1) {
        // 0x801D7B7C: nop
    
            goto L_801D7B90;
    }
    // 0x801D7B7C: nop

    // 0x801D7B80: jal         0x801FCBA8
    // 0x801D7B84: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_0;
    // 0x801D7B84: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_0:
    // 0x801D7B88: b           L_801D7B9C
    // 0x801D7B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7B9C;
    // 0x801D7B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7B90:
    // 0x801D7B90: jal         0x801FCBA8
    // 0x801D7B94: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_1;
    // 0x801D7B94: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    after_1:
    // 0x801D7B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7B9C:
    // 0x801D7B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7BA0: jr          $ra
    // 0x801D7BA4: nop

    return;
    // 0x801D7BA4: nop

;}
RECOMP_FUNC void M8_FUN_801d7ba8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7BB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7BB4: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7BB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7BBC: bne         $t6, $at, L_801D7BD4
    if (ctx->r14 != ctx->r1) {
        // 0x801D7BC0: nop
    
            goto L_801D7BD4;
    }
    // 0x801D7BC0: nop

    // 0x801D7BC4: jal         0x801FCBA8
    // 0x801D7BC8: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_0;
    // 0x801D7BC8: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_0:
    // 0x801D7BCC: b           L_801D7BE0
    // 0x801D7BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7BE0;
    // 0x801D7BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7BD4:
    // 0x801D7BD4: jal         0x801FCBA8
    // 0x801D7BD8: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_1;
    // 0x801D7BD8: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_1:
    // 0x801D7BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7BE0:
    // 0x801D7BE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7BE4: jr          $ra
    // 0x801D7BE8: nop

    return;
    // 0x801D7BE8: nop

;}
RECOMP_FUNC void M8_FUN_801d7bec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7BEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7BF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7BF8: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7BFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7C00: bne         $t6, $at, L_801D7C18
    if (ctx->r14 != ctx->r1) {
        // 0x801D7C04: nop
    
            goto L_801D7C18;
    }
    // 0x801D7C04: nop

    // 0x801D7C08: jal         0x801FCBA8
    // 0x801D7C0C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_0;
    // 0x801D7C0C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_0:
    // 0x801D7C10: b           L_801D7C24
    // 0x801D7C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7C24;
    // 0x801D7C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7C18:
    // 0x801D7C18: jal         0x801FCBA8
    // 0x801D7C1C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_1;
    // 0x801D7C1C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_1:
    // 0x801D7C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7C24:
    // 0x801D7C24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7C28: jr          $ra
    // 0x801D7C2C: nop

    return;
    // 0x801D7C2C: nop

;}
RECOMP_FUNC void M8_FUN_801d7c30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7C38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7C3C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7C40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7C44: bnel        $t6, $at, L_801D7C58
    if (ctx->r14 != ctx->r1) {
        // 0x801D7C48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D7C58;
    }
    goto skip_0;
    // 0x801D7C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D7C4C: jal         0x800208C4
    // 0x801D7C50: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7C50: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_0:
    // 0x801D7C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7C58:
    // 0x801D7C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7C5C: jr          $ra
    // 0x801D7C60: nop

    return;
    // 0x801D7C60: nop

;}
RECOMP_FUNC void M8_FUN_801d7c64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7C64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7C6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7C70: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7C74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7C78: bne         $t6, $at, L_801D7C90
    if (ctx->r14 != ctx->r1) {
        // 0x801D7C7C: nop
    
            goto L_801D7C90;
    }
    // 0x801D7C7C: nop

    // 0x801D7C80: jal         0x800208C4
    // 0x801D7C84: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7C84: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_0:
    // 0x801D7C88: b           L_801D7C9C
    // 0x801D7C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7C9C;
    // 0x801D7C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7C90:
    // 0x801D7C90: jal         0x800208C4
    // 0x801D7C94: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7C94: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_1:
    // 0x801D7C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7C9C:
    // 0x801D7C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7CA0: jr          $ra
    // 0x801D7CA4: nop

    return;
    // 0x801D7CA4: nop

;}
RECOMP_FUNC void M8_FUN_801d7ca8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7CA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7CAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7CB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7CB4: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7CB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7CBC: bne         $t6, $at, L_801D7CD4
    if (ctx->r14 != ctx->r1) {
        // 0x801D7CC0: nop
    
            goto L_801D7CD4;
    }
    // 0x801D7CC0: nop

    // 0x801D7CC4: jal         0x800208C4
    // 0x801D7CC8: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7CC8: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_0:
    // 0x801D7CCC: b           L_801D7CE0
    // 0x801D7CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7CE0;
    // 0x801D7CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7CD4:
    // 0x801D7CD4: jal         0x800208C4
    // 0x801D7CD8: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7CD8: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    after_1:
    // 0x801D7CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7CE0:
    // 0x801D7CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7CE4: jr          $ra
    // 0x801D7CE8: nop

    return;
    // 0x801D7CE8: nop

;}
RECOMP_FUNC void M8_FUN_801d7cec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7CF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7CF8: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7CFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7D00: bne         $t6, $at, L_801D7D18
    if (ctx->r14 != ctx->r1) {
        // 0x801D7D04: nop
    
            goto L_801D7D18;
    }
    // 0x801D7D04: nop

    // 0x801D7D08: jal         0x800208C4
    // 0x801D7D0C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7D0C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_0:
    // 0x801D7D10: b           L_801D7D24
    // 0x801D7D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7D24;
    // 0x801D7D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7D18:
    // 0x801D7D18: jal         0x800208C4
    // 0x801D7D1C: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7D1C: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    after_1:
    // 0x801D7D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7D24:
    // 0x801D7D24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7D28: jr          $ra
    // 0x801D7D2C: nop

    return;
    // 0x801D7D2C: nop

;}
RECOMP_FUNC void M8_FUN_801d7d30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7D38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7D3C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7D40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7D44: bne         $t6, $at, L_801D7D64
    if (ctx->r14 != ctx->r1) {
        // 0x801D7D48: nop
    
            goto L_801D7D64;
    }
    // 0x801D7D48: nop

    // 0x801D7D4C: jal         0x80020718
    // 0x801D7D50: addiu       $a0, $zero, 0x6B9
    ctx->r4 = ADD32(0, 0X6B9);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D7D50: addiu       $a0, $zero, 0x6B9
    ctx->r4 = ADD32(0, 0X6B9);
    after_0:
    // 0x801D7D54: jal         0x800208C4
    // 0x801D7D58: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7D58: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_1:
    // 0x801D7D5C: b           L_801D7D70
    // 0x801D7D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7D70;
    // 0x801D7D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7D64:
    // 0x801D7D64: jal         0x800208C4
    // 0x801D7D68: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_2;
    // 0x801D7D68: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    after_2:
    // 0x801D7D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7D70:
    // 0x801D7D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7D74: jr          $ra
    // 0x801D7D78: nop

    return;
    // 0x801D7D78: nop

;}
RECOMP_FUNC void M8_FUN_801d7d7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7D84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7D88: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7D8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7D90: beql        $t6, $at, L_801D7DA4
    if (ctx->r14 == ctx->r1) {
        // 0x801D7D94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D7DA4;
    }
    goto skip_0;
    // 0x801D7D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D7D98: jal         0x80020718
    // 0x801D7D9C: addiu       $a0, $zero, 0x6B9
    ctx->r4 = ADD32(0, 0X6B9);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D7D9C: addiu       $a0, $zero, 0x6B9
    ctx->r4 = ADD32(0, 0X6B9);
    after_0:
    // 0x801D7DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7DA4:
    // 0x801D7DA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7DA8: jr          $ra
    // 0x801D7DAC: nop

    return;
    // 0x801D7DAC: nop

;}
RECOMP_FUNC void M8_FUN_801d7db0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7DB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7DB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7DBC: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7DC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7DC4: bnel        $t6, $at, L_801D7DD8
    if (ctx->r14 != ctx->r1) {
        // 0x801D7DC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D7DD8;
    }
    goto skip_0;
    // 0x801D7DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D7DCC: jal         0x80020718
    // 0x801D7DD0: addiu       $a0, $zero, 0x6B9
    ctx->r4 = ADD32(0, 0X6B9);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D7DD0: addiu       $a0, $zero, 0x6B9
    ctx->r4 = ADD32(0, 0X6B9);
    after_0:
    // 0x801D7DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7DD8:
    // 0x801D7DD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7DDC: jr          $ra
    // 0x801D7DE0: nop

    return;
    // 0x801D7DE0: nop

;}
RECOMP_FUNC void M8_FUN_801d7de4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7DE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7DEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7DF0: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7DF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7DF8: bne         $t6, $at, L_801D7E10
    if (ctx->r14 != ctx->r1) {
        // 0x801D7DFC: nop
    
            goto L_801D7E10;
    }
    // 0x801D7DFC: nop

    // 0x801D7E00: jal         0x800208C4
    // 0x801D7E04: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7E04: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    after_0:
    // 0x801D7E08: b           L_801D7E1C
    // 0x801D7E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7E1C;
    // 0x801D7E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7E10:
    // 0x801D7E10: jal         0x800208C4
    // 0x801D7E14: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7E14: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_1:
    // 0x801D7E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7E1C:
    // 0x801D7E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7E20: jr          $ra
    // 0x801D7E24: nop

    return;
    // 0x801D7E24: nop

;}
RECOMP_FUNC void M8_FUN_801d7e28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7E30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7E34: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7E38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7E3C: bne         $t6, $at, L_801D7E54
    if (ctx->r14 != ctx->r1) {
        // 0x801D7E40: nop
    
            goto L_801D7E54;
    }
    // 0x801D7E40: nop

    // 0x801D7E44: jal         0x800208C4
    // 0x801D7E48: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7E48: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_0:
    // 0x801D7E4C: b           L_801D7E60
    // 0x801D7E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7E60;
    // 0x801D7E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7E54:
    // 0x801D7E54: jal         0x800208C4
    // 0x801D7E58: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7E58: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    after_1:
    // 0x801D7E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7E60:
    // 0x801D7E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7E64: jr          $ra
    // 0x801D7E68: nop

    return;
    // 0x801D7E68: nop

;}
RECOMP_FUNC void M8_FUN_801d7e6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7E6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7E70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7E74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7E78: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7E7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7E80: beql        $t6, $at, L_801D7E94
    if (ctx->r14 == ctx->r1) {
        // 0x801D7E84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D7E94;
    }
    goto skip_0;
    // 0x801D7E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D7E88: jal         0x801339D0
    // 0x801D7E8C: addiu       $a0, $zero, 0x287
    ctx->r4 = ADD32(0, 0X287);
    LOOKUP_FUNC(0x801339D0)(rdram, ctx);
        goto after_0;
    // 0x801D7E8C: addiu       $a0, $zero, 0x287
    ctx->r4 = ADD32(0, 0X287);
    after_0:
    // 0x801D7E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7E94:
    // 0x801D7E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7E98: jr          $ra
    // 0x801D7E9C: nop

    return;
    // 0x801D7E9C: nop

;}
RECOMP_FUNC void M8_FUN_801d7ea0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7EA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7EA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7EAC: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7EB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7EB4: bne         $t6, $at, L_801D7ECC
    if (ctx->r14 != ctx->r1) {
        // 0x801D7EB8: nop
    
            goto L_801D7ECC;
    }
    // 0x801D7EB8: nop

    // 0x801D7EBC: jal         0x800208C4
    // 0x801D7EC0: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7EC0: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    after_0:
    // 0x801D7EC4: b           L_801D7ED8
    // 0x801D7EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7ED8;
    // 0x801D7EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7ECC:
    // 0x801D7ECC: jal         0x800208C4
    // 0x801D7ED0: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7ED0: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    after_1:
    // 0x801D7ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7ED8:
    // 0x801D7ED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7EDC: jr          $ra
    // 0x801D7EE0: nop

    return;
    // 0x801D7EE0: nop

;}
RECOMP_FUNC void M8_FUN_801d7ee4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7EE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7EEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7EF0: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7EF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7EF8: bnel        $t6, $at, L_801D7F0C
    if (ctx->r14 != ctx->r1) {
        // 0x801D7EFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D7F0C;
    }
    goto skip_0;
    // 0x801D7EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D7F00: jal         0x800208C4
    // 0x801D7F04: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7F04: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    after_0:
    // 0x801D7F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7F0C:
    // 0x801D7F0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7F10: jr          $ra
    // 0x801D7F14: nop

    return;
    // 0x801D7F14: nop

;}
RECOMP_FUNC void M8_FUN_801d7f18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7F18: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801D7F1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D7F20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D7F24: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801D7F28: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x801D7F2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7F30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D7F34: beq         $v0, $at, L_801D7F54
    if (ctx->r2 == ctx->r1) {
        // 0x801D7F38: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801D7F54;
    }
    // 0x801D7F38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D7F3C: beq         $v0, $at, L_801D8074
    if (ctx->r2 == ctx->r1) {
        // 0x801D7F40: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801D8074;
    }
    // 0x801D7F40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D7F44: beql        $v0, $at, L_801D8114
    if (ctx->r2 == ctx->r1) {
        // 0x801D7F48: lw          $t6, 0x24($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X24);
            goto L_801D8114;
    }
    goto skip_0;
    // 0x801D7F48: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x801D7F4C: b           L_801D823C
    // 0x801D7F50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D823C;
    // 0x801D7F50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D7F54:
    // 0x801D7F54: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801D7F58: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D7F5C: jal         0x8001EB64
    // 0x801D7F60: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801D7F60: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_0:
    // 0x801D7F64: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801D7F68: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D7F6C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D7F70: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D7F74: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D7F78: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801D7F7C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D7F80: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D7F84: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D7F88: mflo        $t0
    ctx->r8 = lo;
    // 0x801D7F8C: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x801D7F90: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801D7F94: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D7F98: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D7F9C: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x801D7FA0: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x801D7FA4: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801D7FA8: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x801D7FAC: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801D7FB0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D7FB4: jal         0x8001EAD0
    // 0x801D7FB8: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D7FB8: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_1:
    // 0x801D7FBC: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x801D7FC0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D7FC4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D7FC8: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D7FCC: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D7FD0: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801D7FD4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D7FD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D7FDC: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801D7FE0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801D7FE4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D7FE8: mflo        $t6
    ctx->r14 = lo;
    // 0x801D7FEC: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x801D7FF0: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801D7FF4: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801D7FF8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D7FFC: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801D8000: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x801D8004: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x801D8008: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x801D800C: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8010: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D8014: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8018: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D801C: mflo        $t9
    ctx->r25 = lo;
    // 0x801D8020: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x801D8024: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D8028: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801D802C: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801D8030: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x801D8034: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D8038: lhu         $t0, 0x6($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X6);
    // 0x801D803C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801D8040: bgez        $t0, L_801D8054
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801D8044: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801D8054;
    }
    // 0x801D8044: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D8048: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D804C: nop

    // 0x801D8050: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_801D8054:
    // 0x801D8054: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x801D8058: nop

    // 0x801D805C: bc1fl       L_801D823C
    if (!c1cs) {
        // 0x801D8060: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D823C;
    }
    goto skip_1;
    // 0x801D8060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x801D8064: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D8068: sb          $t1, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r9;
    // 0x801D806C: b           L_801D8238
    // 0x801D8070: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
        goto L_801D8238;
    // 0x801D8070: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
L_801D8074:
    // 0x801D8074: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801D8078: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801D807C: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D8080: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D8084: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x801D8088: nop

    // 0x801D808C: bc1f        L_801D80F0
    if (!c1cs) {
        // 0x801D8090: nop
    
            goto L_801D80F0;
    }
    // 0x801D8090: nop

    // 0x801D8094: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801D8098: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801D809C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D80A0: lui         $t3, 0x410
    ctx->r11 = S32(0X410 << 16);
    // 0x801D80A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D80A8: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x801D80AC: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x801D80B0: ori         $t3, $t3, 0x45
    ctx->r11 = ctx->r11 | 0X45;
    // 0x801D80B4: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x801D80B8: bc1f        L_801D80C4
    if (!c1cs) {
        // 0x801D80BC: add.s       $f8, $f0, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_801D80C4;
    }
    // 0x801D80BC: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x801D80C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D80C4:
    // 0x801D80C4: beq         $v0, $zero, L_801D8238
    if (ctx->r2 == 0) {
        // 0x801D80C8: swc1        $f8, 0x94($s0)
        MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
            goto L_801D8238;
    }
    // 0x801D80C8: swc1        $f8, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
    // 0x801D80CC: sh          $t2, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r10;
    // 0x801D80D0: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x801D80D4: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x801D80D8: sh          $t4, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r12;
    // 0x801D80DC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801D80E0: jal         0x801C2F0C
    // 0x801D80E4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_2;
    // 0x801D80E4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x801D80E8: b           L_801D823C
    // 0x801D80EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D823C;
    // 0x801D80EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D80F0:
    // 0x801D80F0: jal         0x80133A24
    // 0x801D80F4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_3;
    // 0x801D80F4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_3:
    // 0x801D80F8: beq         $v0, $zero, L_801D8238
    if (ctx->r2 == 0) {
        // 0x801D80FC: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_801D8238;
    }
    // 0x801D80FC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x801D8100: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D8104: sb          $t5, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r13;
    // 0x801D8108: b           L_801D8238
    // 0x801D810C: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
        goto L_801D8238;
    // 0x801D810C: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
    // 0x801D8110: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
L_801D8114:
    // 0x801D8114: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D8118: jal         0x8001EB64
    // 0x801D811C: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x801D811C: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_4:
    // 0x801D8120: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8124: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801D8128: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801D812C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801D8130: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801D8134: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801D8138: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801D813C: lwc1        $f6, 0x2954($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x801D8140: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801D8144: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D8148: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D814C: mul.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x801D8150: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D8154: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801D8158: sub.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d - ctx->f16.d;
    // 0x801D815C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x801D8160: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x801D8164: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801D8168: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801D816C: jal         0x8001EAD0
    // 0x801D8170: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_5;
    // 0x801D8170: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_5:
    // 0x801D8174: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8178: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D817C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D8180: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8184: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D8188: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801D818C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801D8190: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D8194: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801D8198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D819C: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D81A0: mflo        $t5
    ctx->r13 = lo;
    // 0x801D81A4: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x801D81A8: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x801D81AC: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x801D81B0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801D81B4: mul.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801D81B8: add.d       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f18.d + ctx->f16.d;
    // 0x801D81BC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801D81C0: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x801D81C4: lbu         $t7, 0x90($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X90);
    // 0x801D81C8: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D81CC: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D81D0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D81D4: mflo        $t8
    ctx->r24 = lo;
    // 0x801D81D8: addu        $v1, $a1, $t8
    ctx->r3 = ADD32(ctx->r5, ctx->r24);
    // 0x801D81DC: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D81E0: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x801D81E4: add.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f6.d + ctx->f16.d;
    // 0x801D81E8: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x801D81EC: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D81F0: lhu         $t9, 0x6($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X6);
    // 0x801D81F4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801D81F8: bgez        $t9, L_801D820C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801D81FC: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801D820C;
    }
    // 0x801D81FC: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D8200: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801D8204: nop

    // 0x801D8208: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_801D820C:
    // 0x801D820C: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x801D8210: nop

    // 0x801D8214: bc1fl       L_801D823C
    if (!c1cs) {
        // 0x801D8218: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D823C;
    }
    goto skip_2;
    // 0x801D8218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x801D821C: jal         0x80150314
    // 0x801D8220: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    LOOKUP_FUNC(0x80150314)(rdram, ctx);
        goto after_6;
    // 0x801D8220: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_6:
    // 0x801D8224: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x801D8228: jal         0x801C3B5C
    // 0x801D822C: sh          $t0, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r8;
    LOOKUP_FUNC(0x801C3B5C)(rdram, ctx);
        goto after_7;
    // 0x801D822C: sh          $t0, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = ctx->r8;
    after_7:
    // 0x801D8230: b           L_801D823C
    // 0x801D8234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801D823C;
    // 0x801D8234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801D8238:
    // 0x801D8238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D823C:
    // 0x801D823C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D8240: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D8244: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801D8248: jr          $ra
    // 0x801D824C: nop

    return;
    // 0x801D824C: nop

;}
RECOMP_FUNC void M8_FUN_801d8250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D8250: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801D8254: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D8258: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801D825C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801D8260: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x801D8264: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D8268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D826C: beq         $v0, $at, L_801D8284
    if (ctx->r2 == ctx->r1) {
        // 0x801D8270: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801D8284;
    }
    // 0x801D8270: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D8274: beql        $v0, $at, L_801D848C
    if (ctx->r2 == ctx->r1) {
        // 0x801D8278: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_801D848C;
    }
    goto skip_0;
    // 0x801D8278: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_0:
    // 0x801D827C: b           L_801D84E4
    // 0x801D8280: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801D84E4;
    // 0x801D8280: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D8284:
    // 0x801D8284: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801D8288: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D828C: jal         0x8001EB64
    // 0x801D8290: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801D8290: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_0:
    // 0x801D8294: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8298: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801D829C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x801D82A0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801D82A4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801D82A8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801D82AC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801D82B0: lwc1        $f6, 0x2954($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x801D82B4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D82B8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D82BC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D82C0: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801D82C4: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x801D82C8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D82CC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D82D0: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x801D82D4: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801D82D8: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x801D82DC: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801D82E0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D82E4: jal         0x8001EAD0
    // 0x801D82E8: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D82E8: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_1:
    // 0x801D82EC: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x801D82F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801D82F4: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x801D82F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D82FC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D8300: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D8304: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801D8308: lwc1        $f16, 0x2954($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x801D830C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801D8310: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D8314: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8318: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x801D831C: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801D8320: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D8324: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801D8328: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x801D832C: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x801D8330: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x801D8334: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801D8338: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801D833C: jal         0x8001EB64
    // 0x801D8340: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801D8340: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_2:
    // 0x801D8344: lbu         $t2, 0x90($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8348: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801D834C: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x801D8350: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801D8354: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801D8358: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801D835C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801D8360: lwc1        $f6, 0x2954($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x801D8364: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x801D8368: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801D836C: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801D8370: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x801D8374: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x801D8378: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801D837C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8380: sub.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d - ctx->f10.d;
    // 0x801D8384: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x801D8388: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x801D838C: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801D8390: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801D8394: jal         0x8001EAD0
    // 0x801D8398: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x801D8398: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_3:
    // 0x801D839C: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801D83A0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801D83A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801D83A8: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D83AC: addiu       $a0, $a0, 0x294C
    ctx->r4 = ADD32(ctx->r4, 0X294C);
    // 0x801D83B0: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x801D83B4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D83B8: lui         $t5, 0x168
    ctx->r13 = S32(0X168 << 16);
    // 0x801D83BC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801D83C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D83C4: addiu       $t4, $zero, 0x1100
    ctx->r12 = ADD32(0, 0X1100);
    // 0x801D83C8: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x801D83CC: ori         $t5, $t5, 0x3E
    ctx->r13 = ctx->r13 | 0X3E;
    // 0x801D83D0: mflo        $t9
    ctx->r25 = lo;
    // 0x801D83D4: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x801D83D8: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801D83DC: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801D83E0: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801D83E4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801D83E8: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x801D83EC: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x801D83F0: add.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f18.d + ctx->f10.d;
    // 0x801D83F4: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x801D83F8: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
    // 0x801D83FC: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8400: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D8404: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8408: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801D840C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x801D8410: mflo        $t2
    ctx->r10 = lo;
    // 0x801D8414: addu        $v0, $a0, $t2
    ctx->r2 = ADD32(ctx->r4, ctx->r10);
    // 0x801D8418: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D841C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801D8420: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x801D8424: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801D8428: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x801D842C: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D8430: lhu         $t3, 0x6($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X6);
    // 0x801D8434: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801D8438: bgez        $t3, L_801D844C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801D843C: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801D844C;
    }
    // 0x801D843C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D8440: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801D8444: nop

    // 0x801D8448: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_801D844C:
    // 0x801D844C: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x801D8450: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D8454: bc1fl       L_801D84E4
    if (!c1cs) {
        // 0x801D8458: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801D84E4;
    }
    goto skip_1;
    // 0x801D8458: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801D845C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D8460: sh          $t4, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r12;
    // 0x801D8464: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x801D8468: sh          $t6, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r14;
    // 0x801D846C: jal         0x801C2F0C
    // 0x801D8470: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_4;
    // 0x801D8470: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801D8474: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801D8478: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801D847C: sb          $t7, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r15;
    // 0x801D8480: b           L_801D84E0
    // 0x801D8484: swc1        $f10, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f10.u32l;
        goto L_801D84E0;
    // 0x801D8484: swc1        $f10, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f10.u32l;
    // 0x801D8488: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
L_801D848C:
    // 0x801D848C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D8490: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D8494: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D8498: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D849C: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x801D84A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D84A4: addiu       $t8, $zero, 0x105
    ctx->r24 = ADD32(0, 0X105);
    // 0x801D84A8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x801D84AC: bc1f        L_801D84B8
    if (!c1cs) {
        // 0x801D84B0: add.s       $f18, $f0, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f4.fl;
            goto L_801D84B8;
    }
    // 0x801D84B0: add.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801D84B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D84B8:
    // 0x801D84B8: beq         $v0, $zero, L_801D84E0
    if (ctx->r2 == 0) {
        // 0x801D84BC: swc1        $f18, 0x94($s0)
        MEM_W(0X94, ctx->r16) = ctx->f18.u32l;
            goto L_801D84E0;
    }
    // 0x801D84BC: swc1        $f18, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f18.u32l;
    // 0x801D84C0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801D84C4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801D84C8: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x801D84CC: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    // 0x801D84D0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801D84D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801D84D8: jal         0x8012FE50
    // 0x801D84DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_5;
    // 0x801D84DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
L_801D84E0:
    // 0x801D84E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D84E4:
    // 0x801D84E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801D84E8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801D84EC: jr          $ra
    // 0x801D84F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801D84F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d84f4(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d84f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D84F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D84F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D84FC: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x801D8500: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801D8504: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D8508: beql        $v0, $v1, L_801D85FC
    if (ctx->r2 == ctx->r3) {
        // 0x801D850C: lbu         $t9, 0x90($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X90);
            goto L_801D85FC;
    }
    goto skip_0;
    // 0x801D850C: lbu         $t9, 0x90($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X90);
    skip_0:
    // 0x801D8510: beq         $v0, $at, L_801D8738
    if (ctx->r2 == ctx->r1) {
        // 0x801D8514: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801D8738;
    }
    // 0x801D8514: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D8518: beq         $v0, $at, L_801D8768
    if (ctx->r2 == ctx->r1) {
        // 0x801D851C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801D8768;
    }
    // 0x801D851C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801D8520: bne         $v0, $at, L_801D8934
    if (ctx->r2 != ctx->r1) {
        // 0x801D8524: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801D8934;
    }
    // 0x801D8524: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801D8528: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801D852C: lbu         $t6, 0x434($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X434);
    // 0x801D8530: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801D8534: bnel        $v1, $t6, L_801D8938
    if (ctx->r3 != ctx->r14) {
        // 0x801D8538: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D8938;
    }
    goto skip_1;
    // 0x801D8538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801D853C: sb          $t7, 0x434($v0)
    MEM_B(0X434, ctx->r2) = ctx->r15;
    // 0x801D8540: lbu         $t2, 0x90($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X90);
    // 0x801D8544: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x801D8548: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D854C: multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8550: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x801D8554: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801D8558: addiu       $t0, $t0, 0x294C
    ctx->r8 = ADD32(ctx->r8, 0X294C);
    // 0x801D855C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801D8560: sb          $t8, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r24;
    // 0x801D8564: sw          $zero, 0x74($a0)
    MEM_W(0X74, ctx->r4) = 0;
    // 0x801D8568: swc1        $f4, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f4.u32l;
    // 0x801D856C: sw          $t9, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->r25;
    // 0x801D8570: mflo        $t3
    ctx->r11 = lo;
    // 0x801D8574: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x801D8578: lhu         $v1, 0x12($t4)
    ctx->r3 = MEM_HU(ctx->r12, 0X12);
    // 0x801D857C: beql        $v1, $zero, L_801D8938
    if (ctx->r3 == 0) {
        // 0x801D8580: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D8938;
    }
    goto skip_2;
    // 0x801D8580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x801D8584: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x801D8588: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D858C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D8590: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x801D8594: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D8598: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x801D859C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x801D85A0: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x801D85A4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x801D85A8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D85AC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x801D85B0: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801D85B4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801D85B8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D85BC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D85C0: div.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x801D85C4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801D85C8: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801D85CC: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    // 0x801D85D0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D85D4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D85D8: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x801D85DC: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x801D85E0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801D85E4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801D85E8: jal         0x801FC830
    // 0x801D85EC: nop

    LOOKUP_FUNC(0x801FC830)(rdram, ctx);
        goto after_0;
    // 0x801D85EC: nop

    after_0:
    // 0x801D85F0: b           L_801D8938
    // 0x801D85F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801D8938;
    // 0x801D85F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D85F8: lbu         $t9, 0x90($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X90);
L_801D85FC:
    // 0x801D85FC: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x801D8600: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801D8604: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8608: addiu       $t0, $t0, 0x294C
    ctx->r8 = ADD32(ctx->r8, 0X294C);
    // 0x801D860C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801D8610: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801D8614: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801D8618: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x801D861C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D8620: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x801D8624: mflo        $t2
    ctx->r10 = lo;
    // 0x801D8628: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x801D862C: lwc1        $f16, 0x8($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X8);
    // 0x801D8630: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D8634: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8638: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D863C: div.d       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f12.d);
    // 0x801D8640: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801D8644: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801D8648: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x801D864C: lbu         $t5, 0x90($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X90);
    // 0x801D8650: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    // 0x801D8654: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8658: lw          $a2, 0x30($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X30);
    // 0x801D865C: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801D8660: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x801D8664: mflo        $t6
    ctx->r14 = lo;
    // 0x801D8668: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x801D866C: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801D8670: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801D8674: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8678: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x801D867C: div.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f12.d);
    // 0x801D8680: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x801D8684: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801D8688: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
    // 0x801D868C: lbu         $t9, 0x90($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X90);
    // 0x801D8690: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x801D8694: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8698: lw          $a3, 0x30($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X30);
    // 0x801D869C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801D86A0: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x801D86A4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801D86A8: mflo        $t2
    ctx->r10 = lo;
    // 0x801D86AC: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x801D86B0: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x801D86B4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801D86B8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801D86BC: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801D86C0: swc1        $f16, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f16.u32l;
    // 0x801D86C4: lbu         $t4, 0x90($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X90);
    // 0x801D86C8: lwc1        $f18, 0x94($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801D86CC: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D86D0: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x801D86D4: mflo        $t5
    ctx->r13 = lo;
    // 0x801D86D8: addu        $v0, $t0, $t5
    ctx->r2 = ADD32(ctx->r8, ctx->r13);
    // 0x801D86DC: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D86E0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D86E4: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x801D86E8: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x801D86EC: swc1        $f2, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f2.u32l;
    // 0x801D86F0: lhu         $t6, 0x6($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X6);
    // 0x801D86F4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801D86F8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801D86FC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x801D8700: bgez        $t6, L_801D8714
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801D8704: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_801D8714;
    }
    // 0x801D8704: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801D8708: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D870C: nop

    // 0x801D8710: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_801D8714:
    // 0x801D8714: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x801D8718: nop

    // 0x801D871C: bc1fl       L_801D8938
    if (!c1cs) {
        // 0x801D8720: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D8938;
    }
    goto skip_3;
    // 0x801D8720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801D8724: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801D8728: sb          $t7, 0x434($v0)
    MEM_B(0X434, ctx->r2) = ctx->r15;
    // 0x801D872C: sb          $t8, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r24;
    // 0x801D8730: b           L_801D8934
    // 0x801D8734: swc1        $f10, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f10.u32l;
        goto L_801D8934;
    // 0x801D8734: swc1        $f10, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f10.u32l;
L_801D8738:
    // 0x801D8738: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801D873C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801D8740: lbu         $t9, 0x434($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X434);
    // 0x801D8744: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801D8748: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x801D874C: bne         $t9, $at, L_801D8934
    if (ctx->r25 != ctx->r1) {
        // 0x801D8750: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_801D8934;
    }
    // 0x801D8750: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x801D8754: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D8758: sb          $t2, 0x434($v0)
    MEM_B(0X434, ctx->r2) = ctx->r10;
    // 0x801D875C: sb          $t3, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r11;
    // 0x801D8760: b           L_801D8934
    // 0x801D8764: swc1        $f6, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f6.u32l;
        goto L_801D8934;
    // 0x801D8764: swc1        $f6, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f6.u32l;
L_801D8768:
    // 0x801D8768: lbu         $t5, 0x90($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X90);
    // 0x801D876C: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x801D8770: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801D8774: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8778: addiu       $t0, $t0, 0x294C
    ctx->r8 = ADD32(ctx->r8, 0X294C);
    // 0x801D877C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801D8780: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801D8784: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801D8788: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x801D878C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D8790: lw          $v1, 0x30($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X30);
    // 0x801D8794: mflo        $t6
    ctx->r14 = lo;
    // 0x801D8798: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x801D879C: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801D87A0: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D87A4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x801D87A8: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801D87AC: div.d       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = DIV_D(ctx->f18.d, ctx->f12.d);
    // 0x801D87B0: sub.d       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f16.d - ctx->f10.d;
    // 0x801D87B4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801D87B8: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x801D87BC: lbu         $t9, 0x90($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X90);
    // 0x801D87C0: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x801D87C4: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D87C8: lw          $a2, 0x30($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X30);
    // 0x801D87CC: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801D87D0: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x801D87D4: mflo        $t2
    ctx->r10 = lo;
    // 0x801D87D8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x801D87DC: lwc1        $f4, 0x8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X8);
    // 0x801D87E0: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x801D87E4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x801D87E8: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x801D87EC: div.d       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f12.d);
    // 0x801D87F0: sub.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d - ctx->f6.d;
    // 0x801D87F4: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801D87F8: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    // 0x801D87FC: lbu         $t5, 0x90($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X90);
    // 0x801D8800: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
    // 0x801D8804: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8808: lw          $a3, 0x30($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X30);
    // 0x801D880C: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x801D8810: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x801D8814: mflo        $t6
    ctx->r14 = lo;
    // 0x801D8818: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x801D881C: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801D8820: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8824: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x801D8828: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801D882C: swc1        $f4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f4.u32l;
    // 0x801D8830: lbu         $t8, 0x90($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X90);
    // 0x801D8834: lwc1        $f18, 0x94($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801D8838: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D883C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x801D8840: mflo        $t9
    ctx->r25 = lo;
    // 0x801D8844: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x801D8848: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D884C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801D8850: add.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d + ctx->f6.d;
    // 0x801D8854: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x801D8858: swc1        $f2, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f2.u32l;
    // 0x801D885C: lhu         $t2, 0x6($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X6);
    // 0x801D8860: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801D8864: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801D8868: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x801D886C: bgez        $t2, L_801D8880
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801D8870: cvt.s.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801D8880;
    }
    // 0x801D8870: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D8874: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801D8878: nop

    // 0x801D887C: add.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f10.fl;
L_801D8880:
    // 0x801D8880: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x801D8884: nop

    // 0x801D8888: bc1fl       L_801D8938
    if (!c1cs) {
        // 0x801D888C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801D8938;
    }
    goto skip_4;
    // 0x801D888C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x801D8890: sb          $zero, 0x434($v0)
    MEM_B(0X434, ctx->r2) = 0;
    // 0x801D8894: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D8898: lw          $t4, 0x98($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X98);
    // 0x801D889C: lw          $t5, 0x38($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X38);
    // 0x801D88A0: sb          $t3, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r11;
    // 0x801D88A4: swc1        $f16, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f16.u32l;
    // 0x801D88A8: sw          $t4, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r12;
    // 0x801D88AC: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x801D88B0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D88B4: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D88B8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x801D88BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D88C0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801D88C4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D88C8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801D88CC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801D88D0: div.d       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x801D88D4: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x801D88D8: swc1        $f18, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f18.u32l;
    // 0x801D88DC: lw          $t9, 0x38($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X38);
    // 0x801D88E0: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x801D88E4: lh          $t2, 0x8($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X8);
    // 0x801D88E8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801D88EC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x801D88F0: nop

    // 0x801D88F4: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801D88F8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D88FC: div.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x801D8900: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801D8904: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
    // 0x801D8908: lw          $t5, 0x38($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X38);
    // 0x801D890C: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x801D8910: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x801D8914: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801D8918: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x801D891C: nop

    // 0x801D8920: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801D8924: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8928: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801D892C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x801D8930: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
L_801D8934:
    // 0x801D8934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801D8938:
    // 0x801D8938: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D893C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801D8940: jr          $ra
    // 0x801D8944: nop

    return;
    // 0x801D8944: nop

;}
RECOMP_FUNC void M8_FUN_801d8948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D8948: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x801D894C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801D8950: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801D8954: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x801D8958: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x801D895C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D8960: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D8964: beq         $v0, $at, L_801D898C
    if (ctx->r2 == ctx->r1) {
        // 0x801D8968: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801D898C;
    }
    // 0x801D8968: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D896C: beq         $v0, $at, L_801D8AC4
    if (ctx->r2 == ctx->r1) {
        // 0x801D8970: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801D8AC4;
    }
    // 0x801D8970: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D8974: beq         $v0, $at, L_801D8B1C
    if (ctx->r2 == ctx->r1) {
        // 0x801D8978: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801D8B1C;
    }
    // 0x801D8978: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801D897C: beql        $v0, $at, L_801D8C9C
    if (ctx->r2 == ctx->r1) {
        // 0x801D8980: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_801D8C9C;
    }
    goto skip_0;
    // 0x801D8980: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_0:
    // 0x801D8984: b           L_801D8D78
    // 0x801D8988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D8D78;
    // 0x801D8988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D898C:
    // 0x801D898C: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801D8990: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D8994: jal         0x8001EB64
    // 0x801D8998: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801D8998: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_0:
    // 0x801D899C: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801D89A0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D89A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D89A8: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D89AC: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D89B0: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801D89B4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D89B8: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D89BC: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D89C0: mflo        $t0
    ctx->r8 = lo;
    // 0x801D89C4: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x801D89C8: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801D89CC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D89D0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D89D4: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x801D89D8: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x801D89DC: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801D89E0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x801D89E4: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801D89E8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D89EC: jal         0x8001EAD0
    // 0x801D89F0: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D89F0: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_1:
    // 0x801D89F4: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x801D89F8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D89FC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D8A00: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8A04: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D8A08: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801D8A0C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D8A10: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D8A14: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801D8A18: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D8A1C: mflo        $t6
    ctx->r14 = lo;
    // 0x801D8A20: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x801D8A24: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801D8A28: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801D8A2C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8A30: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801D8A34: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x801D8A38: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x801D8A3C: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x801D8A40: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8A44: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D8A48: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8A4C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D8A50: mflo        $t9
    ctx->r25 = lo;
    // 0x801D8A54: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x801D8A58: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D8A5C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801D8A60: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801D8A64: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x801D8A68: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D8A6C: lhu         $t0, 0x6($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X6);
    // 0x801D8A70: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801D8A74: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801D8A78: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801D8A7C: bgez        $t0, L_801D8A90
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801D8A80: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801D8A90;
    }
    // 0x801D8A80: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D8A84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D8A88: nop

    // 0x801D8A8C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_801D8A90:
    // 0x801D8A90: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x801D8A94: nop

    // 0x801D8A98: bc1fl       L_801D8D78
    if (!c1cs) {
        // 0x801D8A9C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D8D78;
    }
    goto skip_1;
    // 0x801D8A9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x801D8AA0: lwc1        $f12, 0x198($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X198);
    // 0x801D8AA4: jal         0x8014F358
    // 0x801D8AA8: lwc1        $f14, 0x1A0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X1A0);
    LOOKUP_FUNC(0x8014F358)(rdram, ctx);
        goto after_2;
    // 0x801D8AA8: lwc1        $f14, 0x1A0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X1A0);
    after_2:
    // 0x801D8AAC: beq         $v0, $zero, L_801D8D74
    if (ctx->r2 == 0) {
        // 0x801D8AB0: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_801D8D74;
    }
    // 0x801D8AB0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801D8AB4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D8AB8: sb          $t1, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r9;
    // 0x801D8ABC: b           L_801D8D74
    // 0x801D8AC0: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
        goto L_801D8D74;
    // 0x801D8AC0: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
L_801D8AC4:
    // 0x801D8AC4: jal         0x801C3B5C
    // 0x801D8AC8: nop

    LOOKUP_FUNC(0x801C3B5C)(rdram, ctx);
        goto after_3;
    // 0x801D8AC8: nop

    after_3:
    // 0x801D8ACC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801D8AD0: bne         $v0, $at, L_801D8D74
    if (ctx->r2 != ctx->r1) {
        // 0x801D8AD4: addiu       $t2, $zero, 0x1000
        ctx->r10 = ADD32(0, 0X1000);
            goto L_801D8D74;
    }
    // 0x801D8AD4: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x801D8AD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D8ADC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D8AE0: lui         $t3, 0x168
    ctx->r11 = S32(0X168 << 16);
    // 0x801D8AE4: ori         $t3, $t3, 0x41
    ctx->r11 = ctx->r11 | 0X41;
    // 0x801D8AE8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x801D8AEC: sh          $t2, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r10;
    // 0x801D8AF0: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x801D8AF4: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x801D8AF8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801D8AFC: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x801D8B00: jal         0x801C2F0C
    // 0x801D8B04: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_4;
    // 0x801D8B04: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801D8B08: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D8B0C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x801D8B10: sb          $t5, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r13;
    // 0x801D8B14: b           L_801D8D74
    // 0x801D8B18: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
        goto L_801D8D74;
    // 0x801D8B18: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
L_801D8B1C:
    // 0x801D8B1C: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801D8B20: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D8B24: jal         0x8001EB64
    // 0x801D8B28: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x801D8B28: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_5:
    // 0x801D8B2C: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8B30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801D8B34: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801D8B38: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801D8B3C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801D8B40: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801D8B44: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801D8B48: lwc1        $f16, 0x2954($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x801D8B4C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801D8B50: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D8B54: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8B58: mul.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x801D8B5C: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D8B60: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D8B64: sub.d       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f6.d - ctx->f4.d;
    // 0x801D8B68: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x801D8B6C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x801D8B70: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801D8B74: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801D8B78: jal         0x8001EAD0
    // 0x801D8B7C: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x801D8B7C: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_6:
    // 0x801D8B80: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8B84: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D8B88: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D8B8C: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8B90: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D8B94: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801D8B98: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D8B9C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D8BA0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801D8BA4: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D8BA8: mflo        $t5
    ctx->r13 = lo;
    // 0x801D8BAC: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x801D8BB0: lwc1        $f18, 0x8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X8);
    // 0x801D8BB4: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8BB8: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D8BBC: mul.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x801D8BC0: add.d       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f10.d + ctx->f4.d;
    // 0x801D8BC4: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x801D8BC8: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x801D8BCC: lbu         $t7, 0x90($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8BD0: lwc1        $f6, 0x94($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D8BD4: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8BD8: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x801D8BDC: mflo        $t8
    ctx->r24 = lo;
    // 0x801D8BE0: addu        $v1, $a1, $t8
    ctx->r3 = ADD32(ctx->r5, ctx->r24);
    // 0x801D8BE4: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D8BE8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801D8BEC: add.d       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f16.d + ctx->f4.d;
    // 0x801D8BF0: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x801D8BF4: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D8BF8: lhu         $t9, 0x6($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X6);
    // 0x801D8BFC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801D8C00: bgez        $t9, L_801D8C14
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801D8C04: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801D8C14;
    }
    // 0x801D8C04: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D8C08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801D8C0C: nop

    // 0x801D8C10: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_801D8C14:
    // 0x801D8C14: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x801D8C18: nop

    // 0x801D8C1C: bc1fl       L_801D8D78
    if (!c1cs) {
        // 0x801D8C20: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D8D78;
    }
    goto skip_2;
    // 0x801D8C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x801D8C24: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x801D8C28: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D8C2C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D8C30: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x801D8C34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D8C38: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801D8C3C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x801D8C40: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D8C44: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D8C48: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801D8C4C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801D8C50: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x801D8C54: div.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x801D8C58: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801D8C5C: swc1        $f10, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f10.u32l;
    // 0x801D8C60: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x801D8C64: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801D8C68: lh          $t5, 0xA($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XA);
    // 0x801D8C6C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D8C70: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x801D8C74: nop

    // 0x801D8C78: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D8C7C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8C80: div.d       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x801D8C84: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x801D8C88: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801D8C8C: sb          $t8, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r24;
    // 0x801D8C90: b           L_801D8D74
    // 0x801D8C94: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
        goto L_801D8D74;
    // 0x801D8C94: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D8C98: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_801D8C9C:
    // 0x801D8C9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801D8CA0: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D8CA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D8CA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D8CAC: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x801D8CB0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801D8CB4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801D8CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D8CBC: bc1f        L_801D8CC8
    if (!c1cs) {
        // 0x801D8CC0: add.s       $f16, $f0, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f6.fl;
            goto L_801D8CC8;
    }
    // 0x801D8CC0: add.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x801D8CC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D8CC8:
    // 0x801D8CC8: beq         $v0, $zero, L_801D8D74
    if (ctx->r2 == 0) {
        // 0x801D8CCC: swc1        $f16, 0x94($s0)
        MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
            goto L_801D8D74;
    }
    // 0x801D8CCC: swc1        $f16, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
    // 0x801D8CD0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D8CD4: lwc1        $f4, 0x328($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X328);
    // 0x801D8CD8: lwc1        $f18, 0x32C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X32C);
    // 0x801D8CDC: lwc1        $f8, 0x330($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X330);
    // 0x801D8CE0: lw          $t0, 0xE0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XE0);
    // 0x801D8CE4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801D8CE8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801D8CEC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801D8CF0: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801D8CF4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801D8CF8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801D8CFC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801D8D00: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801D8D04: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801D8D08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D8D0C: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D8D10: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801D8D14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D8D18: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801D8D1C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D8D20: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D8D24: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801D8D28: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801D8D2C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801D8D30: addiu       $a0, $a0, 0x3994
    ctx->r4 = ADD32(ctx->r4, 0X3994);
    // 0x801D8D34: addiu       $a1, $zero, 0x4B6
    ctx->r5 = ADD32(0, 0X4B6);
    // 0x801D8D38: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801D8D3C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D8D40: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x801D8D44: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x801D8D48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801D8D4C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801D8D50: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x801D8D54: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801D8D58: jal         0x8011AAF4
    // 0x801D8D5C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_7;
    // 0x801D8D5C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x801D8D60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801D8D64: jal         0x801C2F0C
    // 0x801D8D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_8;
    // 0x801D8D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x801D8D6C: b           L_801D8D78
    // 0x801D8D70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801D8D78;
    // 0x801D8D70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801D8D74:
    // 0x801D8D74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D8D78:
    // 0x801D8D78: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801D8D7C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801D8D80: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x801D8D84: jr          $ra
    // 0x801D8D88: nop

    return;
    // 0x801D8D88: nop

;}
RECOMP_FUNC void M8_FUN_801d8d8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D8D8C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x801D8D90: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801D8D94: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801D8D98: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x801D8D9C: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x801D8DA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D8DA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D8DA8: beq         $v0, $at, L_801D8DD0
    if (ctx->r2 == ctx->r1) {
        // 0x801D8DAC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801D8DD0;
    }
    // 0x801D8DAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D8DB0: beq         $v0, $at, L_801D8F08
    if (ctx->r2 == ctx->r1) {
        // 0x801D8DB4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801D8F08;
    }
    // 0x801D8DB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D8DB8: beq         $v0, $at, L_801D8F60
    if (ctx->r2 == ctx->r1) {
        // 0x801D8DBC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801D8F60;
    }
    // 0x801D8DBC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801D8DC0: beql        $v0, $at, L_801D90E0
    if (ctx->r2 == ctx->r1) {
        // 0x801D8DC4: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_801D90E0;
    }
    goto skip_0;
    // 0x801D8DC4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_0:
    // 0x801D8DC8: b           L_801D91BC
    // 0x801D8DCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D91BC;
    // 0x801D8DCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D8DD0:
    // 0x801D8DD0: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801D8DD4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D8DD8: jal         0x8001EB64
    // 0x801D8DDC: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801D8DDC: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_0:
    // 0x801D8DE0: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8DE4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D8DE8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D8DEC: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8DF0: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D8DF4: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801D8DF8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D8DFC: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D8E00: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D8E04: mflo        $t0
    ctx->r8 = lo;
    // 0x801D8E08: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x801D8E0C: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801D8E10: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8E14: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D8E18: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x801D8E1C: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x801D8E20: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801D8E24: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x801D8E28: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801D8E2C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D8E30: jal         0x8001EAD0
    // 0x801D8E34: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D8E34: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_1:
    // 0x801D8E38: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8E3C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D8E40: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D8E44: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8E48: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D8E4C: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801D8E50: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D8E54: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D8E58: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801D8E5C: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D8E60: mflo        $t6
    ctx->r14 = lo;
    // 0x801D8E64: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x801D8E68: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801D8E6C: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801D8E70: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8E74: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801D8E78: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x801D8E7C: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x801D8E80: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x801D8E84: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8E88: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D8E8C: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8E90: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D8E94: mflo        $t9
    ctx->r25 = lo;
    // 0x801D8E98: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x801D8E9C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D8EA0: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801D8EA4: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801D8EA8: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x801D8EAC: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D8EB0: lhu         $t0, 0x6($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X6);
    // 0x801D8EB4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801D8EB8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801D8EBC: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801D8EC0: bgez        $t0, L_801D8ED4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801D8EC4: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801D8ED4;
    }
    // 0x801D8EC4: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D8EC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D8ECC: nop

    // 0x801D8ED0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_801D8ED4:
    // 0x801D8ED4: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x801D8ED8: nop

    // 0x801D8EDC: bc1fl       L_801D91BC
    if (!c1cs) {
        // 0x801D8EE0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D91BC;
    }
    goto skip_1;
    // 0x801D8EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x801D8EE4: lwc1        $f12, 0x198($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X198);
    // 0x801D8EE8: jal         0x8014F358
    // 0x801D8EEC: lwc1        $f14, 0x1A0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X1A0);
    LOOKUP_FUNC(0x8014F358)(rdram, ctx);
        goto after_2;
    // 0x801D8EEC: lwc1        $f14, 0x1A0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X1A0);
    after_2:
    // 0x801D8EF0: beq         $v0, $zero, L_801D91B8
    if (ctx->r2 == 0) {
        // 0x801D8EF4: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_801D91B8;
    }
    // 0x801D8EF4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801D8EF8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D8EFC: sb          $t1, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r9;
    // 0x801D8F00: b           L_801D91B8
    // 0x801D8F04: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
        goto L_801D91B8;
    // 0x801D8F04: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
L_801D8F08:
    // 0x801D8F08: jal         0x801C3B5C
    // 0x801D8F0C: nop

    LOOKUP_FUNC(0x801C3B5C)(rdram, ctx);
        goto after_3;
    // 0x801D8F0C: nop

    after_3:
    // 0x801D8F10: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801D8F14: bne         $v0, $at, L_801D91B8
    if (ctx->r2 != ctx->r1) {
        // 0x801D8F18: addiu       $t2, $zero, 0x1000
        ctx->r10 = ADD32(0, 0X1000);
            goto L_801D91B8;
    }
    // 0x801D8F18: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x801D8F1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D8F20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D8F24: lui         $t3, 0x168
    ctx->r11 = S32(0X168 << 16);
    // 0x801D8F28: ori         $t3, $t3, 0x41
    ctx->r11 = ctx->r11 | 0X41;
    // 0x801D8F2C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x801D8F30: sh          $t2, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r10;
    // 0x801D8F34: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x801D8F38: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x801D8F3C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801D8F40: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x801D8F44: jal         0x801C2F0C
    // 0x801D8F48: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_4;
    // 0x801D8F48: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801D8F4C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D8F50: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x801D8F54: sb          $t5, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r13;
    // 0x801D8F58: b           L_801D91B8
    // 0x801D8F5C: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
        goto L_801D91B8;
    // 0x801D8F5C: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
L_801D8F60:
    // 0x801D8F60: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801D8F64: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D8F68: jal         0x8001EB64
    // 0x801D8F6C: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x801D8F6C: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_5:
    // 0x801D8F70: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8F74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801D8F78: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801D8F7C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801D8F80: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801D8F84: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801D8F88: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801D8F8C: lwc1        $f16, 0x2954($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x801D8F90: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801D8F94: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D8F98: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8F9C: mul.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x801D8FA0: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D8FA4: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D8FA8: sub.d       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f6.d - ctx->f4.d;
    // 0x801D8FAC: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x801D8FB0: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x801D8FB4: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801D8FB8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801D8FBC: jal         0x8001EAD0
    // 0x801D8FC0: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x801D8FC0: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_6:
    // 0x801D8FC4: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x801D8FC8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D8FCC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D8FD0: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D8FD4: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D8FD8: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801D8FDC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D8FE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D8FE4: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801D8FE8: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D8FEC: mflo        $t5
    ctx->r13 = lo;
    // 0x801D8FF0: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x801D8FF4: lwc1        $f18, 0x8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X8);
    // 0x801D8FF8: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x801D8FFC: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D9000: mul.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x801D9004: add.d       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f10.d + ctx->f4.d;
    // 0x801D9008: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x801D900C: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x801D9010: lbu         $t7, 0x90($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9014: lwc1        $f6, 0x94($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D9018: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D901C: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x801D9020: mflo        $t8
    ctx->r24 = lo;
    // 0x801D9024: addu        $v1, $a1, $t8
    ctx->r3 = ADD32(ctx->r5, ctx->r24);
    // 0x801D9028: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D902C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801D9030: add.d       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f16.d + ctx->f4.d;
    // 0x801D9034: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x801D9038: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D903C: lhu         $t9, 0x6($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X6);
    // 0x801D9040: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801D9044: bgez        $t9, L_801D9058
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801D9048: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801D9058;
    }
    // 0x801D9048: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D904C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801D9050: nop

    // 0x801D9054: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_801D9058:
    // 0x801D9058: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x801D905C: nop

    // 0x801D9060: bc1fl       L_801D91BC
    if (!c1cs) {
        // 0x801D9064: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D91BC;
    }
    goto skip_2;
    // 0x801D9064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x801D9068: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x801D906C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D9070: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D9074: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x801D9078: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D907C: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801D9080: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x801D9084: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D9088: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D908C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801D9090: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801D9094: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x801D9098: div.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x801D909C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801D90A0: swc1        $f10, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f10.u32l;
    // 0x801D90A4: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x801D90A8: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801D90AC: lh          $t5, 0xA($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XA);
    // 0x801D90B0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D90B4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x801D90B8: nop

    // 0x801D90BC: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D90C0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801D90C4: div.d       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x801D90C8: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x801D90CC: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x801D90D0: sb          $t8, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r24;
    // 0x801D90D4: b           L_801D91B8
    // 0x801D90D8: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
        goto L_801D91B8;
    // 0x801D90D8: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D90DC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_801D90E0:
    // 0x801D90E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801D90E4: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D90E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D90EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D90F0: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x801D90F4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801D90F8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801D90FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D9100: bc1f        L_801D910C
    if (!c1cs) {
        // 0x801D9104: add.s       $f16, $f0, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f6.fl;
            goto L_801D910C;
    }
    // 0x801D9104: add.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x801D9108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D910C:
    // 0x801D910C: beq         $v0, $zero, L_801D91B8
    if (ctx->r2 == 0) {
        // 0x801D9110: swc1        $f16, 0x94($s0)
        MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
            goto L_801D91B8;
    }
    // 0x801D9110: swc1        $f16, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
    // 0x801D9114: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801D9118: lwc1        $f4, 0x328($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X328);
    // 0x801D911C: lwc1        $f18, 0x32C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X32C);
    // 0x801D9120: lwc1        $f8, 0x330($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X330);
    // 0x801D9124: lw          $t0, 0xE0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XE0);
    // 0x801D9128: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801D912C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801D9130: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801D9134: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801D9138: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801D913C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801D9140: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801D9144: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801D9148: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801D914C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D9150: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D9154: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801D9158: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D915C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801D9160: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D9164: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D9168: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801D916C: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801D9170: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801D9174: addiu       $a0, $a0, 0x39D4
    ctx->r4 = ADD32(ctx->r4, 0X39D4);
    // 0x801D9178: addiu       $a1, $zero, 0x50A
    ctx->r5 = ADD32(0, 0X50A);
    // 0x801D917C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801D9180: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D9184: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x801D9188: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x801D918C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801D9190: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801D9194: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x801D9198: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801D919C: jal         0x8011AAF4
    // 0x801D91A0: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_7;
    // 0x801D91A0: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x801D91A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801D91A8: jal         0x801C2F0C
    // 0x801D91AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_8;
    // 0x801D91AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x801D91B0: b           L_801D91BC
    // 0x801D91B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801D91BC;
    // 0x801D91B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801D91B8:
    // 0x801D91B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D91BC:
    // 0x801D91BC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801D91C0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801D91C4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x801D91C8: jr          $ra
    // 0x801D91CC: nop

    return;
    // 0x801D91CC: nop

;}
RECOMP_FUNC void M8_FUN_801d91d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D91D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D91D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D91D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D91DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D91E0: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x801D91E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D91E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D91EC: beq         $v0, $at, L_801D920C
    if (ctx->r2 == ctx->r1) {
        // 0x801D91F0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801D920C;
    }
    // 0x801D91F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D91F4: beq         $v0, $at, L_801D9344
    if (ctx->r2 == ctx->r1) {
        // 0x801D91F8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801D9344;
    }
    // 0x801D91F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D91FC: beql        $v0, $at, L_801D943C
    if (ctx->r2 == ctx->r1) {
        // 0x801D9200: lw          $t3, 0x24($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X24);
            goto L_801D943C;
    }
    goto skip_0;
    // 0x801D9200: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x801D9204: b           L_801D95AC
    // 0x801D9208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D95AC;
    // 0x801D9208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D920C:
    // 0x801D920C: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801D9210: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D9214: jal         0x8001EB64
    // 0x801D9218: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801D9218: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_0:
    // 0x801D921C: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9220: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D9224: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D9228: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D922C: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D9230: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801D9234: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D9238: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D923C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D9240: mflo        $t0
    ctx->r8 = lo;
    // 0x801D9244: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x801D9248: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801D924C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D9250: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D9254: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x801D9258: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x801D925C: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801D9260: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x801D9264: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801D9268: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D926C: jal         0x8001EAD0
    // 0x801D9270: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D9270: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_1:
    // 0x801D9274: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9278: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D927C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D9280: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D9284: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D9288: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801D928C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D9290: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D9294: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801D9298: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D929C: mflo        $t6
    ctx->r14 = lo;
    // 0x801D92A0: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x801D92A4: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801D92A8: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801D92AC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D92B0: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801D92B4: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x801D92B8: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x801D92BC: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x801D92C0: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801D92C4: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D92C8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801D92CC: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D92D0: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D92D4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801D92D8: mflo        $t9
    ctx->r25 = lo;
    // 0x801D92DC: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x801D92E0: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D92E4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801D92E8: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801D92EC: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x801D92F0: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D92F4: lhu         $t0, 0x6($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X6);
    // 0x801D92F8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801D92FC: bgez        $t0, L_801D9310
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801D9300: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801D9310;
    }
    // 0x801D9300: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D9304: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D9308: nop

    // 0x801D930C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_801D9310:
    // 0x801D9310: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x801D9314: nop

    // 0x801D9318: bc1fl       L_801D95AC
    if (!c1cs) {
        // 0x801D931C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D95AC;
    }
    goto skip_1;
    // 0x801D931C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x801D9320: lwc1        $f12, 0x198($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X198);
    // 0x801D9324: jal         0x8014F358
    // 0x801D9328: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    LOOKUP_FUNC(0x8014F358)(rdram, ctx);
        goto after_2;
    // 0x801D9328: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    after_2:
    // 0x801D932C: beq         $v0, $zero, L_801D95A8
    if (ctx->r2 == 0) {
        // 0x801D9330: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_801D95A8;
    }
    // 0x801D9330: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801D9334: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D9338: sb          $t1, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r9;
    // 0x801D933C: b           L_801D95A8
    // 0x801D9340: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
        goto L_801D95A8;
    // 0x801D9340: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
L_801D9344:
    // 0x801D9344: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801D9348: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801D934C: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D9350: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D9354: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D9358: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x801D935C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D9360: add.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801D9364: bc1f        L_801D9370
    if (!c1cs) {
        // 0x801D9368: nop
    
            goto L_801D9370;
    }
    // 0x801D9368: nop

    // 0x801D936C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D9370:
    // 0x801D9370: beq         $v0, $zero, L_801D9390
    if (ctx->r2 == 0) {
        // 0x801D9374: swc1        $f8, 0x94($s0)
        MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
            goto L_801D9390;
    }
    // 0x801D9374: swc1        $f8, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
    // 0x801D9378: jal         0x80133A24
    // 0x801D937C: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_3;
    // 0x801D937C: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_3:
    // 0x801D9380: beq         $v0, $zero, L_801D9390
    if (ctx->r2 == 0) {
        // 0x801D9384: nop
    
            goto L_801D9390;
    }
    // 0x801D9384: nop

    // 0x801D9388: jal         0x8014F940
    // 0x801D938C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8014F940)(rdram, ctx);
        goto after_4;
    // 0x801D938C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_801D9390:
    // 0x801D9390: jal         0x801C3B5C
    // 0x801D9394: nop

    LOOKUP_FUNC(0x801C3B5C)(rdram, ctx);
        goto after_5;
    // 0x801D9394: nop

    after_5:
    // 0x801D9398: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801D939C: bne         $v0, $at, L_801D95A8
    if (ctx->r2 != ctx->r1) {
        // 0x801D93A0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801D95A8;
    }
    // 0x801D93A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801D93A4: jal         0x801C2F0C
    // 0x801D93A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_6;
    // 0x801D93A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x801D93AC: lbu         $t2, 0x91($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X91);
    // 0x801D93B0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801D93B4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x801D93B8: beql        $t3, $zero, L_801D93D4
    if (ctx->r11 == 0) {
        // 0x801D93BC: lw          $t5, 0x38($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X38);
            goto L_801D93D4;
    }
    goto skip_2;
    // 0x801D93BC: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    skip_2:
    // 0x801D93C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D93C4: sb          $t4, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r12;
    // 0x801D93C8: b           L_801D95A8
    // 0x801D93CC: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
        goto L_801D95A8;
    // 0x801D93CC: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
    // 0x801D93D0: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
L_801D93D4:
    // 0x801D93D4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D93D8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D93DC: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x801D93E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D93E4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801D93E8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x801D93EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D93F0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801D93F4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801D93F8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D93FC: div.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x801D9400: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x801D9404: swc1        $f8, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f8.u32l;
    // 0x801D9408: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x801D940C: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801D9410: lh          $t0, 0xA($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XA);
    // 0x801D9414: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801D9418: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801D941C: nop

    // 0x801D9420: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D9424: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D9428: div.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801D942C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801D9430: b           L_801D95AC
    // 0x801D9434: swc1        $f16, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f16.u32l;
        goto L_801D95AC;
    // 0x801D9434: swc1        $f16, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f16.u32l;
    // 0x801D9438: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
L_801D943C:
    // 0x801D943C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801D9440: jal         0x8001EB64
    // 0x801D9444: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_7;
    // 0x801D9444: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_7:
    // 0x801D9448: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x801D944C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801D9450: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x801D9454: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D9458: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D945C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D9460: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801D9464: lwc1        $f4, 0x2954($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x801D9468: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D946C: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x801D9470: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x801D9474: mul.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801D9478: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D947C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D9480: sub.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f16.d - ctx->f6.d;
    // 0x801D9484: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x801D9488: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x801D948C: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801D9490: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801D9494: jal         0x8001EAD0
    // 0x801D9498: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x801D9498: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_8:
    // 0x801D949C: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    // 0x801D94A0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D94A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D94A8: multu       $t1, $a2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D94AC: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D94B0: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801D94B4: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801D94B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D94BC: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801D94C0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D94C4: mflo        $t2
    ctx->r10 = lo;
    // 0x801D94C8: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x801D94CC: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x801D94D0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801D94D4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D94D8: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x801D94DC: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x801D94E0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x801D94E4: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x801D94E8: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x801D94EC: lwc1        $f16, 0x94($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D94F0: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D94F4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801D94F8: mflo        $t5
    ctx->r13 = lo;
    // 0x801D94FC: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
    // 0x801D9500: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D9504: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801D9508: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x801D950C: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x801D9510: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D9514: lhu         $t6, 0x6($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X6);
    // 0x801D9518: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x801D951C: bgez        $t6, L_801D9530
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801D9520: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801D9530;
    }
    // 0x801D9520: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801D9524: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D9528: nop

    // 0x801D952C: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_801D9530:
    // 0x801D9530: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x801D9534: nop

    // 0x801D9538: bc1fl       L_801D95AC
    if (!c1cs) {
        // 0x801D953C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D95AC;
    }
    goto skip_3;
    // 0x801D953C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x801D9540: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x801D9544: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D9548: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D954C: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x801D9550: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D9554: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801D9558: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801D955C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D9560: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801D9564: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D9568: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D956C: div.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x801D9570: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x801D9574: swc1        $f8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f8.u32l;
    // 0x801D9578: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x801D957C: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801D9580: lh          $t2, 0xA($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XA);
    // 0x801D9584: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801D9588: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x801D958C: nop

    // 0x801D9590: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801D9594: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801D9598: div.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801D959C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x801D95A0: b           L_801D95AC
    // 0x801D95A4: swc1        $f18, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f18.u32l;
        goto L_801D95AC;
    // 0x801D95A4: swc1        $f18, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f18.u32l;
L_801D95A8:
    // 0x801D95A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D95AC:
    // 0x801D95AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D95B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D95B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D95B8: jr          $ra
    // 0x801D95BC: nop

    return;
    // 0x801D95BC: nop

;}
RECOMP_FUNC void M8_FUN_801d95c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D95C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D95C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D95C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D95CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D95D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D95D4: jal         0x80133A24
    // 0x801D95D8: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801D95D8: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_0:
    // 0x801D95DC: beq         $v0, $zero, L_801D9620
    if (ctx->r2 == 0) {
        // 0x801D95E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801D9620;
    }
    // 0x801D95E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D95E4: jal         0x80150314
    // 0x801D95E8: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    LOOKUP_FUNC(0x80150314)(rdram, ctx);
        goto after_1;
    // 0x801D95E8: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_1:
    // 0x801D95EC: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x801D95F0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D95F4: sb          $zero, 0x91($s0)
    MEM_B(0X91, ctx->r16) = 0;
    // 0x801D95F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D95FC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D9600: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D9604: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x801D9608: lhu         $a1, 0x295A($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X295A);
    // 0x801D960C: jal         0x8012C97C
    // 0x801D9610: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_2;
    // 0x801D9610: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    after_2:
    // 0x801D9614: sw          $v0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r2;
    // 0x801D9618: b           L_801D9958
    // 0x801D961C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801D9958;
    // 0x801D961C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801D9620:
    // 0x801D9620: lbu         $v0, 0x93($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X93);
    // 0x801D9624: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D9628: beq         $v0, $zero, L_801D9650
    if (ctx->r2 == 0) {
        // 0x801D962C: nop
    
            goto L_801D9650;
    }
    // 0x801D962C: nop

    // 0x801D9630: beq         $v0, $at, L_801D9688
    if (ctx->r2 == ctx->r1) {
        // 0x801D9634: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801D9688;
    }
    // 0x801D9634: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D9638: beq         $v0, $at, L_801D97A8
    if (ctx->r2 == ctx->r1) {
        // 0x801D963C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801D97A8;
    }
    // 0x801D963C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D9640: beql        $v0, $at, L_801D97E4
    if (ctx->r2 == ctx->r1) {
        // 0x801D9644: lw          $t6, 0x24($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X24);
            goto L_801D97E4;
    }
    goto skip_0;
    // 0x801D9644: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x801D9648: b           L_801D9958
    // 0x801D964C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D9958;
    // 0x801D964C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D9650:
    // 0x801D9650: jal         0x8014F330
    // 0x801D9654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8014F330)(rdram, ctx);
        goto after_3;
    // 0x801D9654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801D9658: beql        $v0, $zero, L_801D9958
    if (ctx->r2 == 0) {
        // 0x801D965C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D9958;
    }
    goto skip_1;
    // 0x801D965C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x801D9660: jal         0x801C3B7C
    // 0x801D9664: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_4;
    // 0x801D9664: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x801D9668: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D966C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801D9670: sb          $t8, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r24;
    // 0x801D9674: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    // 0x801D9678: jal         0x80020718
    // 0x801D967C: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_5;
    // 0x801D967C: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x801D9680: b           L_801D9958
    // 0x801D9684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D9958;
    // 0x801D9684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D9688:
    // 0x801D9688: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801D968C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801D9690: jal         0x8001EB64
    // 0x801D9694: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_6;
    // 0x801D9694: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_6:
    // 0x801D9698: lbu         $t2, 0x90($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X90);
    // 0x801D969C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D96A0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D96A4: multu       $t2, $a2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D96A8: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D96AC: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801D96B0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801D96B4: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x801D96B8: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D96BC: mflo        $t3
    ctx->r11 = lo;
    // 0x801D96C0: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x801D96C4: lwc1        $f8, 0x8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X8);
    // 0x801D96C8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801D96CC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D96D0: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801D96D4: add.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f4.d + ctx->f16.d;
    // 0x801D96D8: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801D96DC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x801D96E0: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x801D96E4: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801D96E8: jal         0x8001EAD0
    // 0x801D96EC: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x801D96EC: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_7:
    // 0x801D96F0: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801D96F4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D96F8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D96FC: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D9700: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D9704: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801D9708: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801D970C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D9710: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801D9714: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801D9718: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D971C: mflo        $t9
    ctx->r25 = lo;
    // 0x801D9720: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x801D9724: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801D9728: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801D972C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801D9730: mul.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801D9734: sub.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d - ctx->f16.d;
    // 0x801D9738: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x801D973C: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x801D9740: lbu         $t1, 0x90($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9744: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D9748: multu       $t1, $a2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D974C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801D9750: mflo        $t2
    ctx->r10 = lo;
    // 0x801D9754: addu        $v1, $a1, $t2
    ctx->r3 = ADD32(ctx->r5, ctx->r10);
    // 0x801D9758: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D975C: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x801D9760: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x801D9764: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x801D9768: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D976C: lhu         $t3, 0x6($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X6);
    // 0x801D9770: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x801D9774: bgez        $t3, L_801D9788
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801D9778: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801D9788;
    }
    // 0x801D9778: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D977C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D9780: nop

    // 0x801D9784: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801D9788:
    // 0x801D9788: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x801D978C: nop

    // 0x801D9790: bc1fl       L_801D9958
    if (!c1cs) {
        // 0x801D9794: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D9958;
    }
    goto skip_2;
    // 0x801D9794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x801D9798: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D979C: sb          $t4, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r12;
    // 0x801D97A0: b           L_801D9954
    // 0x801D97A4: swc1        $f8, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
        goto L_801D9954;
    // 0x801D97A4: swc1        $f8, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
L_801D97A8:
    // 0x801D97A8: jal         0x8014F330
    // 0x801D97AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8014F330)(rdram, ctx);
        goto after_8;
    // 0x801D97AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801D97B0: beql        $v0, $zero, L_801D9958
    if (ctx->r2 == 0) {
        // 0x801D97B4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D9958;
    }
    goto skip_3;
    // 0x801D97B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x801D97B8: jal         0x801C3B7C
    // 0x801D97BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_9;
    // 0x801D97BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x801D97C0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D97C4: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x801D97C8: sb          $t5, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r13;
    // 0x801D97CC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    // 0x801D97D0: jal         0x80020718
    // 0x801D97D4: swc1        $f16, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_10;
    // 0x801D97D4: swc1        $f16, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
    after_10:
    // 0x801D97D8: b           L_801D9958
    // 0x801D97DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D9958;
    // 0x801D97DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801D97E0: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
L_801D97E4:
    // 0x801D97E4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D97E8: jal         0x8001EB64
    // 0x801D97EC: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_11;
    // 0x801D97EC: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_11:
    // 0x801D97F0: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801D97F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801D97F8: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801D97FC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801D9800: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801D9804: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801D9808: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801D980C: lwc1        $f10, 0x2954($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x801D9810: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801D9814: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D9818: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801D981C: mul.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x801D9820: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D9824: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801D9828: sub.d       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f16.d - ctx->f4.d;
    // 0x801D982C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x801D9830: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x801D9834: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801D9838: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801D983C: jal         0x8001EAD0
    // 0x801D9840: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_12;
    // 0x801D9840: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_12:
    // 0x801D9844: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9848: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D984C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D9850: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D9854: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D9858: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801D985C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801D9860: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D9864: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801D9868: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D986C: mflo        $t5
    ctx->r13 = lo;
    // 0x801D9870: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x801D9874: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x801D9878: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x801D987C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801D9880: mul.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x801D9884: add.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d + ctx->f4.d;
    // 0x801D9888: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801D988C: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x801D9890: lbu         $t7, 0x90($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9894: lwc1        $f16, 0x94($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D9898: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D989C: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x801D98A0: mflo        $t8
    ctx->r24 = lo;
    // 0x801D98A4: addu        $v1, $a1, $t8
    ctx->r3 = ADD32(ctx->r5, ctx->r24);
    // 0x801D98A8: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D98AC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801D98B0: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x801D98B4: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x801D98B8: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801D98BC: lhu         $t9, 0x6($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X6);
    // 0x801D98C0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801D98C4: bgez        $t9, L_801D98D8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801D98C8: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801D98D8;
    }
    // 0x801D98C8: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D98CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801D98D0: nop

    // 0x801D98D4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801D98D8:
    // 0x801D98D8: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x801D98DC: nop

    // 0x801D98E0: bc1fl       L_801D9958
    if (!c1cs) {
        // 0x801D98E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D9958;
    }
    goto skip_4;
    // 0x801D98E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x801D98E8: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x801D98EC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D98F0: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D98F4: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x801D98F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D98FC: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801D9900: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801D9904: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D9908: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D990C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x801D9910: div.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x801D9914: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x801D9918: swc1        $f18, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f18.u32l;
    // 0x801D991C: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x801D9920: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801D9924: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D9928: lh          $t5, 0xA($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XA);
    // 0x801D992C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D9930: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x801D9934: nop

    // 0x801D9938: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801D993C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801D9940: div.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x801D9944: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x801D9948: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x801D994C: sb          $zero, 0x93($s0)
    MEM_B(0X93, ctx->r16) = 0;
    // 0x801D9950: swc1        $f18, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f18.u32l;
L_801D9954:
    // 0x801D9954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D9958:
    // 0x801D9958: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D995C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D9960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D9964: jr          $ra
    // 0x801D9968: nop

    return;
    // 0x801D9968: nop

;}
RECOMP_FUNC void M8_FUN_801d996c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D996C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D9970: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D9974: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801D9978: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801D997C: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x801D9980: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D9984: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D9988: beq         $v0, $at, L_801D99A8
    if (ctx->r2 == ctx->r1) {
        // 0x801D998C: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_801D99A8;
    }
    // 0x801D998C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x801D9990: beq         $v0, $v1, L_801D9AE0
    if (ctx->r2 == ctx->r3) {
        // 0x801D9994: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801D9AE0;
    }
    // 0x801D9994: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D9998: beql        $v0, $at, L_801D9D70
    if (ctx->r2 == ctx->r1) {
        // 0x801D999C: lw          $t7, 0x24($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X24);
            goto L_801D9D70;
    }
    goto skip_0;
    // 0x801D999C: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x801D99A0: b           L_801D9EEC
    // 0x801D99A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D9EEC;
    // 0x801D99A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D99A8:
    // 0x801D99A8: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801D99AC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801D99B0: jal         0x8001EB64
    // 0x801D99B4: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801D99B4: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_0:
    // 0x801D99B8: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801D99BC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D99C0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D99C4: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D99C8: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D99CC: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801D99D0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801D99D4: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801D99D8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D99DC: mflo        $t0
    ctx->r8 = lo;
    // 0x801D99E0: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x801D99E4: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801D99E8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D99EC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D99F0: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x801D99F4: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x801D99F8: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x801D99FC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x801D9A00: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801D9A04: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D9A08: jal         0x8001EAD0
    // 0x801D9A0C: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x801D9A0C: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_1:
    // 0x801D9A10: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9A14: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D9A18: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D9A1C: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D9A20: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D9A24: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801D9A28: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801D9A2C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D9A30: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801D9A34: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D9A38: mflo        $t6
    ctx->r14 = lo;
    // 0x801D9A3C: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x801D9A40: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801D9A44: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801D9A48: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801D9A4C: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x801D9A50: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x801D9A54: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x801D9A58: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x801D9A5C: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9A60: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D9A64: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801D9A68: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D9A6C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D9A70: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801D9A74: mflo        $t9
    ctx->r25 = lo;
    // 0x801D9A78: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x801D9A7C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D9A80: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801D9A84: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x801D9A88: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    // 0x801D9A8C: swc1        $f14, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f14.u32l;
    // 0x801D9A90: lhu         $t0, 0x6($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X6);
    // 0x801D9A94: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801D9A98: bgez        $t0, L_801D9AAC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801D9A9C: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801D9AAC;
    }
    // 0x801D9A9C: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D9AA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D9AA4: nop

    // 0x801D9AA8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_801D9AAC:
    // 0x801D9AAC: c.le.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl <= ctx->f14.fl;
    // 0x801D9AB0: nop

    // 0x801D9AB4: bc1fl       L_801D9EEC
    if (!c1cs) {
        // 0x801D9AB8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D9EEC;
    }
    goto skip_1;
    // 0x801D9AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x801D9ABC: lwc1        $f12, 0x198($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X198);
    // 0x801D9AC0: jal         0x8014F358
    // 0x801D9AC4: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    LOOKUP_FUNC(0x8014F358)(rdram, ctx);
        goto after_2;
    // 0x801D9AC4: lwc1        $f14, 0x1A0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1A0);
    after_2:
    // 0x801D9AC8: beq         $v0, $zero, L_801D9EE8
    if (ctx->r2 == 0) {
        // 0x801D9ACC: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_801D9EE8;
    }
    // 0x801D9ACC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801D9AD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D9AD4: sb          $t1, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r9;
    // 0x801D9AD8: b           L_801D9EE8
    // 0x801D9ADC: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
        goto L_801D9EE8;
    // 0x801D9ADC: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
L_801D9AE0:
    // 0x801D9AE0: lbu         $t2, 0x92($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X92);
    // 0x801D9AE4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801D9AE8: bne         $v1, $t2, L_801D9B28
    if (ctx->r3 != ctx->r10) {
        // 0x801D9AEC: nop
    
            goto L_801D9B28;
    }
    // 0x801D9AEC: nop

    // 0x801D9AF0: lwc1        $f0, 0x94($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D9AF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801D9AF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D9AFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D9B00: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x801D9B04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D9B08: add.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801D9B0C: bc1f        L_801D9B18
    if (!c1cs) {
        // 0x801D9B10: nop
    
            goto L_801D9B18;
    }
    // 0x801D9B10: nop

    // 0x801D9B14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D9B18:
    // 0x801D9B18: beq         $v0, $zero, L_801D9B28
    if (ctx->r2 == 0) {
        // 0x801D9B1C: swc1        $f8, 0x94($s0)
        MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
            goto L_801D9B28;
    }
    // 0x801D9B1C: swc1        $f8, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f8.u32l;
    // 0x801D9B20: jal         0x8014F940
    // 0x801D9B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8014F940)(rdram, ctx);
        goto after_3;
    // 0x801D9B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_801D9B28:
    // 0x801D9B28: jal         0x801C3044
    // 0x801D9B2C: nop

    LOOKUP_FUNC(0x801C3044)(rdram, ctx);
        goto after_4;
    // 0x801D9B2C: nop

    after_4:
    // 0x801D9B30: bne         $v0, $zero, L_801D9EE8
    if (ctx->r2 != 0) {
        // 0x801D9B34: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801D9EE8;
    }
    // 0x801D9B34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801D9B38: jal         0x801C2F0C
    // 0x801D9B3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801C2F0C)(rdram, ctx);
        goto after_5;
    // 0x801D9B3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x801D9B40: lbu         $t3, 0x92($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X92);
    // 0x801D9B44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D9B48: bnel        $t3, $at, L_801D9D08
    if (ctx->r11 != ctx->r1) {
        // 0x801D9B4C: lw          $t9, 0x38($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X38);
            goto L_801D9D08;
    }
    goto skip_2;
    // 0x801D9B4C: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    skip_2:
    // 0x801D9B50: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9B54: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D9B58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D9B5C: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D9B60: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D9B64: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D9B68: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801D9B6C: sb          $t4, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r12;
    // 0x801D9B70: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
    // 0x801D9B74: addiu       $at, $zero, 0x127
    ctx->r1 = ADD32(0, 0X127);
    // 0x801D9B78: mflo        $t6
    ctx->r14 = lo;
    // 0x801D9B7C: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x801D9B80: lhu         $v1, 0x12($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X12);
    // 0x801D9B84: beql        $v1, $zero, L_801D9EEC
    if (ctx->r3 == 0) {
        // 0x801D9B88: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D9EEC;
    }
    goto skip_3;
    // 0x801D9B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x801D9B8C: bne         $v1, $at, L_801D9C0C
    if (ctx->r3 != ctx->r1) {
        // 0x801D9B90: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801D9C0C;
    }
    // 0x801D9B90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801D9B94: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x801D9B98: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D9B9C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D9BA0: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x801D9BA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D9BA8: lh          $t0, 0xA($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XA);
    // 0x801D9BAC: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x801D9BB0: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x801D9BB4: addiu       $t1, $zero, 0x21D
    ctx->r9 = ADD32(0, 0X21D);
    // 0x801D9BB8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801D9BBC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801D9BC0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801D9BC4: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801D9BC8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D9BCC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D9BD0: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x801D9BD4: div.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x801D9BD8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801D9BDC: div.d       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x801D9BE0: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    // 0x801D9BE4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D9BE8: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801D9BEC: div.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x801D9BF0: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801D9BF4: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x801D9BF8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801D9BFC: jal         0x801FC830
    // 0x801D9C00: nop

    LOOKUP_FUNC(0x801FC830)(rdram, ctx);
        goto after_6;
    // 0x801D9C00: nop

    after_6:
    // 0x801D9C04: b           L_801D9EEC
    // 0x801D9C08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D9EEC;
    // 0x801D9C08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D9C0C:
    // 0x801D9C0C: addiu       $at, $zero, 0x128
    ctx->r1 = ADD32(0, 0X128);
    // 0x801D9C10: bnel        $v0, $at, L_801D9C94
    if (ctx->r2 != ctx->r1) {
        // 0x801D9C14: lw          $v0, 0x38($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X38);
            goto L_801D9C94;
    }
    goto skip_4;
    // 0x801D9C14: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    skip_4:
    // 0x801D9C18: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x801D9C1C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D9C20: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D9C24: lh          $t2, 0x6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6);
    // 0x801D9C28: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D9C2C: lh          $t4, 0xA($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XA);
    // 0x801D9C30: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x801D9C34: lh          $t3, 0x8($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X8);
    // 0x801D9C38: addiu       $t5, $zero, 0x21E
    ctx->r13 = ADD32(0, 0X21E);
    // 0x801D9C3C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D9C40: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801D9C44: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801D9C48: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801D9C4C: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D9C50: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D9C54: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801D9C58: div.d       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x801D9C5C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x801D9C60: div.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801D9C64: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801D9C68: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801D9C6C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801D9C70: div.d       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x801D9C74: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x801D9C78: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x801D9C7C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801D9C80: jal         0x801FC830
    // 0x801D9C84: nop

    LOOKUP_FUNC(0x801FC830)(rdram, ctx);
        goto after_7;
    // 0x801D9C84: nop

    after_7:
    // 0x801D9C88: b           L_801D9EEC
    // 0x801D9C8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D9EEC;
    // 0x801D9C8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801D9C90: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_801D9C94:
    // 0x801D9C94: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D9C98: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D9C9C: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x801D9CA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D9CA4: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x801D9CA8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801D9CAC: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x801D9CB0: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x801D9CB4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D9CB8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x801D9CBC: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801D9CC0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801D9CC4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801D9CC8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801D9CCC: div.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x801D9CD0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801D9CD4: div.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x801D9CD8: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x801D9CDC: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D9CE0: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x801D9CE4: div.d       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x801D9CE8: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    // 0x801D9CEC: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801D9CF0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801D9CF4: jal         0x801FC830
    // 0x801D9CF8: nop

    LOOKUP_FUNC(0x801FC830)(rdram, ctx);
        goto after_8;
    // 0x801D9CF8: nop

    after_8:
    // 0x801D9CFC: b           L_801D9EEC
    // 0x801D9D00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D9EEC;
    // 0x801D9D00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801D9D04: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
L_801D9D08:
    // 0x801D9D08: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D9D0C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D9D10: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x801D9D14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D9D18: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801D9D1C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x801D9D20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D9D24: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801D9D28: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801D9D2C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801D9D30: div.d       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x801D9D34: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x801D9D38: swc1        $f6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f6.u32l;
    // 0x801D9D3C: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x801D9D40: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x801D9D44: lh          $t4, 0xA($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XA);
    // 0x801D9D48: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801D9D4C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x801D9D50: nop

    // 0x801D9D54: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D9D58: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801D9D5C: div.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x801D9D60: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x801D9D64: b           L_801D9EEC
    // 0x801D9D68: swc1        $f18, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f18.u32l;
        goto L_801D9EEC;
    // 0x801D9D68: swc1        $f18, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f18.u32l;
    // 0x801D9D6C: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
L_801D9D70:
    // 0x801D9D70: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801D9D74: jal         0x8001EB64
    // 0x801D9D78: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_9;
    // 0x801D9D78: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_9:
    // 0x801D9D7C: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9D80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801D9D84: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801D9D88: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801D9D8C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801D9D90: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801D9D94: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801D9D98: lwc1        $f10, 0x2954($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2954);
    // 0x801D9D9C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801D9DA0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801D9DA4: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801D9DA8: mul.d       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x801D9DAC: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D9DB0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801D9DB4: add.d       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = ctx->f12.d + ctx->f12.d;
    // 0x801D9DB8: sub.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f4.d - ctx->f18.d;
    // 0x801D9DBC: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x801D9DC0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x801D9DC4: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801D9DC8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801D9DCC: jal         0x8001EAD0
    // 0x801D9DD0: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_10;
    // 0x801D9DD0: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_10:
    // 0x801D9DD4: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9DD8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D9DDC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801D9DE0: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D9DE4: addiu       $a1, $a1, 0x294C
    ctx->r5 = ADD32(ctx->r5, 0X294C);
    // 0x801D9DE8: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x801D9DEC: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801D9DF0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801D9DF4: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801D9DF8: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801D9DFC: mflo        $t6
    ctx->r14 = lo;
    // 0x801D9E00: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x801D9E04: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801D9E08: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x801D9E0C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801D9E10: mul.d       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f12.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x801D9E14: add.d       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f12.d + ctx->f12.d;
    // 0x801D9E18: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x801D9E1C: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801D9E20: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x801D9E24: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9E28: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801D9E2C: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D9E30: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x801D9E34: mflo        $t9
    ctx->r25 = lo;
    // 0x801D9E38: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x801D9E3C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801D9E40: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x801D9E44: add.d       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f2.d + ctx->f2.d;
    // 0x801D9E48: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x801D9E4C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x801D9E50: swc1        $f14, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f14.u32l;
    // 0x801D9E54: lhu         $t0, 0x6($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X6);
    // 0x801D9E58: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x801D9E5C: bgez        $t0, L_801D9E70
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801D9E60: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_801D9E70;
    }
    // 0x801D9E60: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801D9E64: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801D9E68: nop

    // 0x801D9E6C: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_801D9E70:
    // 0x801D9E70: c.le.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl <= ctx->f14.fl;
    // 0x801D9E74: nop

    // 0x801D9E78: bc1fl       L_801D9EEC
    if (!c1cs) {
        // 0x801D9E7C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801D9EEC;
    }
    goto skip_5;
    // 0x801D9E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_5:
    // 0x801D9E80: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x801D9E84: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D9E88: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801D9E8C: lh          $t2, 0x6($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X6);
    // 0x801D9E90: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D9E94: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801D9E98: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x801D9E9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D9EA0: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801D9EA4: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D9EA8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801D9EAC: div.d       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x801D9EB0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801D9EB4: swc1        $f18, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f18.u32l;
    // 0x801D9EB8: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x801D9EBC: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801D9EC0: lh          $t6, 0xA($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XA);
    // 0x801D9EC4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801D9EC8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801D9ECC: nop

    // 0x801D9ED0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D9ED4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801D9ED8: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801D9EDC: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801D9EE0: b           L_801D9EEC
    // 0x801D9EE4: swc1        $f16, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f16.u32l;
        goto L_801D9EEC;
    // 0x801D9EE4: swc1        $f16, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f16.u32l;
L_801D9EE8:
    // 0x801D9EE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D9EEC:
    // 0x801D9EEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801D9EF0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801D9EF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D9EF8: jr          $ra
    // 0x801D9EFC: nop

    return;
    // 0x801D9EFC: nop

;}
RECOMP_FUNC void M8_FUN_801d9f00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D9F00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D9F04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D9F08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801D9F0C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801D9F10: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801D9F14: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801D9F18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D9F1C: bnel        $t6, $at, L_801D9F78
    if (ctx->r14 != ctx->r1) {
        // 0x801D9F20: lbu         $v0, 0x93($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X93);
            goto L_801D9F78;
    }
    goto skip_0;
    // 0x801D9F20: lbu         $v0, 0x93($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X93);
    skip_0:
    // 0x801D9F24: jal         0x80133A24
    // 0x801D9F28: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801D9F28: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    after_0:
    // 0x801D9F2C: beq         $v0, $zero, L_801D9F74
    if (ctx->r2 == 0) {
        // 0x801D9F30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801D9F74;
    }
    // 0x801D9F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801D9F34: jal         0x80150314
    // 0x801D9F38: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    LOOKUP_FUNC(0x80150314)(rdram, ctx);
        goto after_1;
    // 0x801D9F38: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    after_1:
    // 0x801D9F3C: lbu         $t7, 0x90($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9F40: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x801D9F44: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801D9F48: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D9F4C: addiu       $a2, $a2, 0x294C
    ctx->r6 = ADD32(ctx->r6, 0X294C);
    // 0x801D9F50: sb          $zero, 0x91($s0)
    MEM_B(0X91, ctx->r16) = 0;
    // 0x801D9F54: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    // 0x801D9F58: mflo        $t8
    ctx->r24 = lo;
    // 0x801D9F5C: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x801D9F60: jal         0x8012C97C
    // 0x801D9F64: lhu         $a1, 0xE($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0XE);
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_2;
    // 0x801D9F64: lhu         $a1, 0xE($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0XE);
    after_2:
    // 0x801D9F68: sw          $v0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r2;
    // 0x801D9F6C: b           L_801DA2F0
    // 0x801D9F70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801DA2F0;
    // 0x801D9F70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801D9F74:
    // 0x801D9F74: lbu         $v0, 0x93($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X93);
L_801D9F78:
    // 0x801D9F78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D9F7C: beq         $v0, $zero, L_801D9FA4
    if (ctx->r2 == 0) {
        // 0x801D9F80: nop
    
            goto L_801D9FA4;
    }
    // 0x801D9F80: nop

    // 0x801D9F84: beq         $v0, $at, L_801DA088
    if (ctx->r2 == ctx->r1) {
        // 0x801D9F88: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801DA088;
    }
    // 0x801D9F88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D9F8C: beq         $v0, $at, L_801DA144
    if (ctx->r2 == ctx->r1) {
        // 0x801D9F90: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801DA144;
    }
    // 0x801D9F90: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D9F94: beql        $v0, $at, L_801DA20C
    if (ctx->r2 == ctx->r1) {
        // 0x801D9F98: lbu         $t2, 0x90($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X90);
            goto L_801DA20C;
    }
    goto skip_1;
    // 0x801D9F98: lbu         $t2, 0x90($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X90);
    skip_1:
    // 0x801D9F9C: b           L_801DA2F0
    // 0x801D9FA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801DA2F0;
    // 0x801D9FA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D9FA4:
    // 0x801D9FA4: jal         0x8014F330
    // 0x801D9FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8014F330)(rdram, ctx);
        goto after_3;
    // 0x801D9FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801D9FAC: beql        $v0, $zero, L_801DA2F0
    if (ctx->r2 == 0) {
        // 0x801D9FB0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801DA2F0;
    }
    goto skip_2;
    // 0x801D9FB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x801D9FB4: jal         0x801C3B7C
    // 0x801D9FB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_4;
    // 0x801D9FB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x801D9FBC: lbu         $v0, 0x90($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X90);
    // 0x801D9FC0: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x801D9FC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D9FC8: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D9FCC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801D9FD0: addiu       $a2, $a2, 0x294C
    ctx->r6 = ADD32(ctx->r6, 0X294C);
    // 0x801D9FD4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D9FD8: sb          $t0, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r8;
    // 0x801D9FDC: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
    // 0x801D9FE0: mflo        $t1
    ctx->r9 = lo;
    // 0x801D9FE4: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x801D9FE8: lhu         $v1, 0x12($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X12);
    // 0x801D9FEC: beql        $v1, $zero, L_801DA068
    if (ctx->r3 == 0) {
        // 0x801D9FF0: addiu       $at, $zero, 0x65
        ctx->r1 = ADD32(0, 0X65);
            goto L_801DA068;
    }
    goto skip_3;
    // 0x801D9FF0: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    skip_3:
    // 0x801D9FF4: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x801D9FF8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801D9FFC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801DA000: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x801DA004: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801DA008: lh          $t5, 0xA($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XA);
    // 0x801DA00C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x801DA010: lh          $t4, 0x8($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X8);
    // 0x801DA014: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x801DA018: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801DA01C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x801DA020: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801DA024: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801DA028: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801DA02C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801DA030: div.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x801DA034: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801DA038: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801DA03C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    // 0x801DA040: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801DA044: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801DA048: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x801DA04C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x801DA050: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801DA054: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801DA058: jal         0x801FC830
    // 0x801DA05C: nop

    LOOKUP_FUNC(0x801FC830)(rdram, ctx);
        goto after_5;
    // 0x801DA05C: nop

    after_5:
    // 0x801DA060: lbu         $v0, 0x90($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA064: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
L_801DA068:
    // 0x801DA068: bnel        $v0, $at, L_801DA2F0
    if (ctx->r2 != ctx->r1) {
        // 0x801DA06C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801DA2F0;
    }
    goto skip_4;
    // 0x801DA06C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x801DA070: jal         0x80133980
    // 0x801DA074: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_6;
    // 0x801DA074: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    after_6:
    // 0x801DA078: jal         0x80020718
    // 0x801DA07C: addiu       $a0, $zero, 0x6B9
    ctx->r4 = ADD32(0, 0X6B9);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_7;
    // 0x801DA07C: addiu       $a0, $zero, 0x6B9
    ctx->r4 = ADD32(0, 0X6B9);
    after_7:
    // 0x801DA080: b           L_801DA2F0
    // 0x801DA084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801DA2F0;
    // 0x801DA084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801DA088:
    // 0x801DA088: lbu         $t7, 0x90($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA08C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x801DA090: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801DA094: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA098: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801DA09C: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x801DA0A0: addiu       $a2, $a2, 0x294C
    ctx->r6 = ADD32(ctx->r6, 0X294C);
    // 0x801DA0A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DA0A8: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801DA0AC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801DA0B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801DA0B4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801DA0B8: mflo        $t8
    ctx->r24 = lo;
    // 0x801DA0BC: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x801DA0C0: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801DA0C4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801DA0C8: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x801DA0CC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801DA0D0: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x801DA0D4: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA0D8: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801DA0DC: multu       $t0, $a3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA0E0: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801DA0E4: mflo        $t1
    ctx->r9 = lo;
    // 0x801DA0E8: addu        $v0, $a2, $t1
    ctx->r2 = ADD32(ctx->r6, ctx->r9);
    // 0x801DA0EC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801DA0F0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x801DA0F4: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801DA0F8: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x801DA0FC: swc1        $f0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f0.u32l;
    // 0x801DA100: lhu         $t2, 0x6($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X6);
    // 0x801DA104: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x801DA108: bgez        $t2, L_801DA11C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801DA10C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801DA11C;
    }
    // 0x801DA10C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801DA110: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DA114: nop

    // 0x801DA118: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801DA11C:
    // 0x801DA11C: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x801DA120: nop

    // 0x801DA124: bc1fl       L_801DA2F0
    if (!c1cs) {
        // 0x801DA128: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801DA2F0;
    }
    goto skip_5;
    // 0x801DA128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_5:
    // 0x801DA12C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801DA130: sb          $t3, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r11;
    // 0x801DA134: jal         0x801C3B7C
    // 0x801DA138: swc1        $f16, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_8;
    // 0x801DA138: swc1        $f16, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
    after_8:
    // 0x801DA13C: b           L_801DA2F0
    // 0x801DA140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801DA2F0;
    // 0x801DA140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801DA144:
    // 0x801DA144: jal         0x8014F330
    // 0x801DA148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8014F330)(rdram, ctx);
        goto after_9;
    // 0x801DA148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x801DA14C: beql        $v0, $zero, L_801DA2F0
    if (ctx->r2 == 0) {
        // 0x801DA150: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801DA2F0;
    }
    goto skip_6;
    // 0x801DA150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_6:
    // 0x801DA154: jal         0x801C3B7C
    // 0x801DA158: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_10;
    // 0x801DA158: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x801DA15C: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA160: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x801DA164: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801DA168: multu       $t5, $a3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA16C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801DA170: addiu       $a2, $a2, 0x294C
    ctx->r6 = ADD32(ctx->r6, 0X294C);
    // 0x801DA174: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801DA178: sb          $t4, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r12;
    // 0x801DA17C: swc1        $f18, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f18.u32l;
    // 0x801DA180: mflo        $t6
    ctx->r14 = lo;
    // 0x801DA184: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x801DA188: lhu         $v1, 0x12($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X12);
    // 0x801DA18C: beql        $v1, $zero, L_801DA2F0
    if (ctx->r3 == 0) {
        // 0x801DA190: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801DA2F0;
    }
    goto skip_7;
    // 0x801DA190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_7:
    // 0x801DA194: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x801DA198: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801DA19C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801DA1A0: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x801DA1A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801DA1A8: lh          $t0, 0xA($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XA);
    // 0x801DA1AC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801DA1B0: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x801DA1B4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x801DA1B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801DA1BC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x801DA1C0: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801DA1C4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801DA1C8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801DA1CC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801DA1D0: div.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x801DA1D4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801DA1D8: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x801DA1DC: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801DA1E0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801DA1E4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801DA1E8: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x801DA1EC: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801DA1F0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801DA1F4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801DA1F8: jal         0x801FC830
    // 0x801DA1FC: nop

    LOOKUP_FUNC(0x801FC830)(rdram, ctx);
        goto after_11;
    // 0x801DA1FC: nop

    after_11:
    // 0x801DA200: b           L_801DA2F0
    // 0x801DA204: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801DA2F0;
    // 0x801DA204: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801DA208: lbu         $t2, 0x90($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X90);
L_801DA20C:
    // 0x801DA20C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x801DA210: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801DA214: multu       $t2, $a3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA218: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801DA21C: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x801DA220: addiu       $a2, $a2, 0x294C
    ctx->r6 = ADD32(ctx->r6, 0X294C);
    // 0x801DA224: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DA228: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801DA22C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801DA230: mflo        $t3
    ctx->r11 = lo;
    // 0x801DA234: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x801DA238: lwc1        $f8, 0x8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X8);
    // 0x801DA23C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801DA240: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x801DA244: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801DA248: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x801DA24C: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA250: lwc1        $f6, 0x94($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801DA254: multu       $t5, $a3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA258: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801DA25C: mflo        $t6
    ctx->r14 = lo;
    // 0x801DA260: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x801DA264: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801DA268: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801DA26C: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x801DA270: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x801DA274: swc1        $f0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f0.u32l;
    // 0x801DA278: lhu         $t7, 0x6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X6);
    // 0x801DA27C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801DA280: bgez        $t7, L_801DA294
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801DA284: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801DA294;
    }
    // 0x801DA284: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801DA288: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DA28C: nop

    // 0x801DA290: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_801DA294:
    // 0x801DA294: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x801DA298: nop

    // 0x801DA29C: bc1fl       L_801DA2F0
    if (!c1cs) {
        // 0x801DA2A0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801DA2F0;
    }
    goto skip_8;
    // 0x801DA2A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_8:
    // 0x801DA2A4: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x801DA2A8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801DA2AC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801DA2B0: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x801DA2B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801DA2B8: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801DA2BC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801DA2C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DA2C4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801DA2C8: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801DA2CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801DA2D0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801DA2D4: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x801DA2D8: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x801DA2DC: swc1        $f10, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f10.u32l;
    // 0x801DA2E0: sb          $zero, 0x93($s0)
    MEM_B(0X93, ctx->r16) = 0;
    // 0x801DA2E4: jal         0x801C3B7C
    // 0x801DA2E8: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C3B7C)(rdram, ctx);
        goto after_12;
    // 0x801DA2E8: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
    after_12:
    // 0x801DA2EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801DA2F0:
    // 0x801DA2F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801DA2F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801DA2F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801DA2FC: jr          $ra
    // 0x801DA300: nop

    return;
    // 0x801DA300: nop

;}
RECOMP_FUNC void M8_FUN_801da304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA304: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801DA308: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801DA30C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801DA310: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801DA314: lbu         $v0, 0x93($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X93);
    // 0x801DA318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801DA31C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801DA320: beq         $v0, $zero, L_801DA340
    if (ctx->r2 == 0) {
        // 0x801DA324: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801DA340;
    }
    // 0x801DA324: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DA328: beq         $v0, $at, L_801DA568
    if (ctx->r2 == ctx->r1) {
        // 0x801DA32C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801DA568;
    }
    // 0x801DA32C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DA330: beql        $v0, $at, L_801DA744
    if (ctx->r2 == ctx->r1) {
        // 0x801DA334: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801DA744;
    }
    goto skip_0;
    // 0x801DA334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801DA338: b           L_801DA744
    // 0x801DA33C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801DA744;
    // 0x801DA33C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801DA340:
    // 0x801DA340: lbu         $t6, 0x9C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X9C);
    // 0x801DA344: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801DA348: bne         $t6, $at, L_801DA45C
    if (ctx->r14 != ctx->r1) {
        // 0x801DA34C: nop
    
            goto L_801DA45C;
    }
    // 0x801DA34C: nop

    // 0x801DA350: jal         0x80133A24
    // 0x801DA354: addiu       $a0, $zero, 0x171
    ctx->r4 = ADD32(0, 0X171);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801DA354: addiu       $a0, $zero, 0x171
    ctx->r4 = ADD32(0, 0X171);
    after_0:
    // 0x801DA358: beql        $v0, $zero, L_801DA744
    if (ctx->r2 == 0) {
        // 0x801DA35C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801DA744;
    }
    goto skip_1;
    // 0x801DA35C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801DA360: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA364: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x801DA368: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DA36C: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA370: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801DA374: addiu       $t0, $t0, 0x294C
    ctx->r8 = ADD32(ctx->r8, 0X294C);
    // 0x801DA378: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801DA37C: sb          $t7, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r15;
    // 0x801DA380: swc1        $f4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f4.u32l;
    // 0x801DA384: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801DA388: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801DA38C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801DA390: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DA394: mflo        $t9
    ctx->r25 = lo;
    // 0x801DA398: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x801DA39C: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x801DA3A0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x801DA3A4: bgez        $t3, L_801DA3B8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801DA3A8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801DA3B8;
    }
    // 0x801DA3A8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801DA3AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DA3B0: nop

    // 0x801DA3B4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801DA3B8:
    // 0x801DA3B8: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801DA3BC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801DA3C0: div.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f12.d);
    // 0x801DA3C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DA3C8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801DA3CC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801DA3D0: swc1        $f4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f4.u32l;
    // 0x801DA3D4: lbu         $t6, 0x90($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA3D8: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA3DC: mflo        $t7
    ctx->r15 = lo;
    // 0x801DA3E0: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x801DA3E4: lhu         $t9, 0x6($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6);
    // 0x801DA3E8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801DA3EC: bgez        $t9, L_801DA400
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801DA3F0: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801DA400;
    }
    // 0x801DA3F0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801DA3F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DA3F8: nop

    // 0x801DA3FC: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_801DA400:
    // 0x801DA400: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x801DA404: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x801DA408: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x801DA40C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DA410: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801DA414: div.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f12.d);
    // 0x801DA418: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801DA41C: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x801DA420: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA424: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA428: mflo        $t5
    ctx->r13 = lo;
    // 0x801DA42C: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x801DA430: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x801DA434: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801DA438: bgez        $t7, L_801DA44C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801DA43C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801DA44C;
    }
    // 0x801DA43C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801DA440: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DA444: nop

    // 0x801DA448: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801DA44C:
    // 0x801DA44C: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x801DA450: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801DA454: b           L_801DA740
    // 0x801DA458: swc1        $f8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f8.u32l;
        goto L_801DA740;
    // 0x801DA458: swc1        $f8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f8.u32l;
L_801DA45C:
    // 0x801DA45C: jal         0x80133A24
    // 0x801DA460: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_1;
    // 0x801DA460: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    after_1:
    // 0x801DA464: beql        $v0, $zero, L_801DA744
    if (ctx->r2 == 0) {
        // 0x801DA468: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801DA744;
    }
    goto skip_2;
    // 0x801DA468: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x801DA46C: lbu         $t3, 0x90($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA470: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x801DA474: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801DA478: multu       $t3, $t1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA47C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801DA480: addiu       $t0, $t0, 0x294C
    ctx->r8 = ADD32(ctx->r8, 0X294C);
    // 0x801DA484: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801DA488: sb          $t2, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r10;
    // 0x801DA48C: swc1        $f16, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
    // 0x801DA490: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801DA494: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801DA498: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801DA49C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DA4A0: mflo        $t4
    ctx->r12 = lo;
    // 0x801DA4A4: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x801DA4A8: lhu         $t6, 0x6($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X6);
    // 0x801DA4AC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x801DA4B0: bgez        $t6, L_801DA4C4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801DA4B4: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801DA4C4;
    }
    // 0x801DA4B4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801DA4B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DA4BC: nop

    // 0x801DA4C0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801DA4C4:
    // 0x801DA4C4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801DA4C8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801DA4CC: div.d       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f12.d);
    // 0x801DA4D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DA4D4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801DA4D8: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801DA4DC: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x801DA4E0: lbu         $t9, 0x90($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA4E4: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA4E8: mflo        $t2
    ctx->r10 = lo;
    // 0x801DA4EC: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x801DA4F0: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x801DA4F4: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x801DA4F8: bgez        $t4, L_801DA50C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801DA4FC: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801DA50C;
    }
    // 0x801DA4FC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801DA500: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DA504: nop

    // 0x801DA508: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_801DA50C:
    // 0x801DA50C: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x801DA510: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x801DA514: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x801DA518: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DA51C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801DA520: div.d       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f12.d);
    // 0x801DA524: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801DA528: swc1        $f16, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f16.u32l;
    // 0x801DA52C: lbu         $t7, 0x90($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA530: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA534: mflo        $t8
    ctx->r24 = lo;
    // 0x801DA538: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x801DA53C: lhu         $t2, 0x6($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X6);
    // 0x801DA540: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x801DA544: bgez        $t2, L_801DA558
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801DA548: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801DA558;
    }
    // 0x801DA548: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801DA54C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DA550: nop

    // 0x801DA554: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801DA558:
    // 0x801DA558: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x801DA55C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801DA560: b           L_801DA740
    // 0x801DA564: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
        goto L_801DA740;
    // 0x801DA564: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
L_801DA568:
    // 0x801DA568: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801DA56C: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801DA570: c.eq.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl == ctx->f8.fl;
    // 0x801DA574: nop

    // 0x801DA578: bc1fl       L_801DA618
    if (!c1cs) {
        // 0x801DA57C: lbu         $t4, 0x90($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X90);
            goto L_801DA618;
    }
    goto skip_3;
    // 0x801DA57C: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    skip_3:
    // 0x801DA580: lbu         $t5, 0x90($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA584: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x801DA588: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801DA58C: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA590: addiu       $t0, $t0, 0x294C
    ctx->r8 = ADD32(ctx->r8, 0X294C);
    // 0x801DA594: mflo        $t6
    ctx->r14 = lo;
    // 0x801DA598: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x801DA59C: lhu         $v1, 0x12($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X12);
    // 0x801DA5A0: beql        $v1, $zero, L_801DA618
    if (ctx->r3 == 0) {
        // 0x801DA5A4: lbu         $t4, 0x90($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X90);
            goto L_801DA618;
    }
    goto skip_4;
    // 0x801DA5A4: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    skip_4:
    // 0x801DA5A8: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x801DA5AC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801DA5B0: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801DA5B4: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x801DA5B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801DA5BC: lh          $t2, 0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA);
    // 0x801DA5C0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x801DA5C4: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x801DA5C8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x801DA5CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801DA5D0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801DA5D4: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801DA5D8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801DA5DC: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801DA5E0: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801DA5E4: div.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801DA5E8: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x801DA5EC: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x801DA5F0: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x801DA5F4: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801DA5F8: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801DA5FC: div.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x801DA600: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x801DA604: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x801DA608: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801DA60C: jal         0x801FC830
    // 0x801DA610: nop

    LOOKUP_FUNC(0x801FC830)(rdram, ctx);
        goto after_2;
    // 0x801DA610: nop

    after_2:
    // 0x801DA614: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
L_801DA618:
    // 0x801DA618: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x801DA61C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801DA620: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA624: addiu       $t0, $t0, 0x294C
    ctx->r8 = ADD32(ctx->r8, 0X294C);
    // 0x801DA628: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801DA62C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801DA630: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801DA634: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801DA638: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DA63C: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801DA640: mflo        $t5
    ctx->r13 = lo;
    // 0x801DA644: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x801DA648: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x801DA64C: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801DA650: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x801DA654: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801DA658: div.d       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f12.d);
    // 0x801DA65C: add.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d + ctx->f8.d;
    // 0x801DA660: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801DA664: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x801DA668: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA66C: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x801DA670: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA674: lw          $a0, 0x30($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X30);
    // 0x801DA678: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801DA67C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801DA680: mflo        $t9
    ctx->r25 = lo;
    // 0x801DA684: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x801DA688: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x801DA68C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x801DA690: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x801DA694: div.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f12.d);
    // 0x801DA698: add.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d + ctx->f16.d;
    // 0x801DA69C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801DA6A0: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x801DA6A4: lbu         $t4, 0x90($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA6A8: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x801DA6AC: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA6B0: lw          $a1, 0x30($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X30);
    // 0x801DA6B4: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x801DA6B8: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801DA6BC: mflo        $t5
    ctx->r13 = lo;
    // 0x801DA6C0: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x801DA6C4: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x801DA6C8: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x801DA6CC: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x801DA6D0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801DA6D4: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x801DA6D8: lbu         $t7, 0x90($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X90);
    // 0x801DA6DC: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801DA6E0: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801DA6E4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801DA6E8: mflo        $t8
    ctx->r24 = lo;
    // 0x801DA6EC: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x801DA6F0: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801DA6F4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801DA6F8: add.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d + ctx->f16.d;
    // 0x801DA6FC: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x801DA700: swc1        $f2, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f2.u32l;
    // 0x801DA704: lhu         $t9, 0x6($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X6);
    // 0x801DA708: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801DA70C: bgez        $t9, L_801DA720
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801DA710: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801DA720;
    }
    // 0x801DA710: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801DA714: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DA718: nop

    // 0x801DA71C: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_801DA720:
    // 0x801DA720: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x801DA724: nop

    // 0x801DA728: bc1fl       L_801DA744
    if (!c1cs) {
        // 0x801DA72C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801DA744;
    }
    goto skip_5;
    // 0x801DA72C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x801DA730: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DA734: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801DA738: sb          $t2, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r10;
    // 0x801DA73C: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
L_801DA740:
    // 0x801DA740: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801DA744:
    // 0x801DA744: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801DA748: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801DA74C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801DA750: jr          $ra
    // 0x801DA754: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801DA754: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801da758(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801da758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA75C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA760: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA764: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DA768: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DA76C: addiu       $a0, $zero, 0x69D
    ctx->r4 = ADD32(0, 0X69D);
    // 0x801DA770: bne         $t6, $at, L_801DA780
    if (ctx->r14 != ctx->r1) {
        // 0x801DA774: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_801DA780;
    }
    // 0x801DA774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801DA778: jal         0x801FC720
    // 0x801DA77C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x801FC720)(rdram, ctx);
        goto after_0;
    // 0x801DA77C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_801DA780:
    // 0x801DA780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DA784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DA788: jr          $ra
    // 0x801DA78C: nop

    return;
    // 0x801DA78C: nop

;}
RECOMP_FUNC void M8_FUN_801da790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA798: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA79C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DA7A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DA7A4: addiu       $a0, $zero, 0x6B3
    ctx->r4 = ADD32(0, 0X6B3);
    // 0x801DA7A8: bne         $t6, $at, L_801DA7B8
    if (ctx->r14 != ctx->r1) {
        // 0x801DA7AC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_801DA7B8;
    }
    // 0x801DA7AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801DA7B0: jal         0x801FC720
    // 0x801DA7B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x801FC720)(rdram, ctx);
        goto after_0;
    // 0x801DA7B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_801DA7B8:
    // 0x801DA7B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DA7BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DA7C0: jr          $ra
    // 0x801DA7C4: nop

    return;
    // 0x801DA7C4: nop

;}
RECOMP_FUNC void M8_FUN_801da7c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA7C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA7CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA7D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA7D4: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DA7D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DA7DC: addiu       $a0, $zero, 0x69D
    ctx->r4 = ADD32(0, 0X69D);
    // 0x801DA7E0: bne         $t6, $at, L_801DA7F0
    if (ctx->r14 != ctx->r1) {
        // 0x801DA7E4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_801DA7F0;
    }
    // 0x801DA7E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801DA7E8: jal         0x801FC720
    // 0x801DA7EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x801FC720)(rdram, ctx);
        goto after_0;
    // 0x801DA7EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_801DA7F0:
    // 0x801DA7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DA7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DA7F8: jr          $ra
    // 0x801DA7FC: nop

    return;
    // 0x801DA7FC: nop

;}
RECOMP_FUNC void M8_FUN_801da800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA808: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801DA80C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA810: jal         0x80133A24
    // 0x801DA814: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801DA814: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x801DA818: bne         $v0, $zero, L_801DA830
    if (ctx->r2 != 0) {
        // 0x801DA81C: nop
    
            goto L_801DA830;
    }
    // 0x801DA81C: nop

    // 0x801DA820: jal         0x80133980
    // 0x801DA824: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_1;
    // 0x801DA824: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x801DA828: b           L_801DA84C
    // 0x801DA82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801DA84C;
    // 0x801DA82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DA830:
    // 0x801DA830: jal         0x80133A24
    // 0x801DA834: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_2;
    // 0x801DA834: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_2:
    // 0x801DA838: bnel        $v0, $zero, L_801DA84C
    if (ctx->r2 != 0) {
        // 0x801DA83C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801DA84C;
    }
    goto skip_0;
    // 0x801DA83C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801DA840: jal         0x80133980
    // 0x801DA844: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_3;
    // 0x801DA844: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_3:
    // 0x801DA848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DA84C:
    // 0x801DA84C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DA850: jr          $ra
    // 0x801DA854: nop

    return;
    // 0x801DA854: nop

;}
RECOMP_FUNC void M8_FUN_801da858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA85C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA860: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA864: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DA868: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DA86C: addiu       $a0, $zero, 0x6B4
    ctx->r4 = ADD32(0, 0X6B4);
    // 0x801DA870: bne         $t6, $at, L_801DA880
    if (ctx->r14 != ctx->r1) {
        // 0x801DA874: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_801DA880;
    }
    // 0x801DA874: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801DA878: jal         0x801FC720
    // 0x801DA87C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x801FC720)(rdram, ctx);
        goto after_0;
    // 0x801DA87C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_801DA880:
    // 0x801DA880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DA884: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DA888: jr          $ra
    // 0x801DA88C: nop

    return;
    // 0x801DA88C: nop

;}
RECOMP_FUNC void M8_FUN_801da890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA898: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA89C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DA8A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DA8A4: bnel        $t6, $at, L_801DA8B8
    if (ctx->r14 != ctx->r1) {
        // 0x801DA8A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801DA8B8;
    }
    goto skip_0;
    // 0x801DA8A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801DA8AC: jal         0x80020718
    // 0x801DA8B0: addiu       $a0, $zero, 0x6AB
    ctx->r4 = ADD32(0, 0X6AB);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801DA8B0: addiu       $a0, $zero, 0x6AB
    ctx->r4 = ADD32(0, 0X6AB);
    after_0:
    // 0x801DA8B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DA8B8:
    // 0x801DA8B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DA8BC: jr          $ra
    // 0x801DA8C0: nop

    return;
    // 0x801DA8C0: nop

;}
RECOMP_FUNC void M8_FUN_801da8c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA8C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA8C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA8CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA8D0: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DA8D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DA8D8: bnel        $t6, $at, L_801DA8EC
    if (ctx->r14 != ctx->r1) {
        // 0x801DA8DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801DA8EC;
    }
    goto skip_0;
    // 0x801DA8DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801DA8E0: jal         0x80020718
    // 0x801DA8E4: addiu       $a0, $zero, 0x6AB
    ctx->r4 = ADD32(0, 0X6AB);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801DA8E4: addiu       $a0, $zero, 0x6AB
    ctx->r4 = ADD32(0, 0X6AB);
    after_0:
    // 0x801DA8E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DA8EC:
    // 0x801DA8EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DA8F0: jr          $ra
    // 0x801DA8F4: nop

    return;
    // 0x801DA8F4: nop

;}
RECOMP_FUNC void M8_FUN_801da8f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA8F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA8FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA900: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA904: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DA908: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DA90C: bnel        $t6, $at, L_801DA920
    if (ctx->r14 != ctx->r1) {
        // 0x801DA910: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801DA920;
    }
    goto skip_0;
    // 0x801DA910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801DA914: jal         0x80020718
    // 0x801DA918: addiu       $a0, $zero, 0x6AB
    ctx->r4 = ADD32(0, 0X6AB);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801DA918: addiu       $a0, $zero, 0x6AB
    ctx->r4 = ADD32(0, 0X6AB);
    after_0:
    // 0x801DA91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DA920:
    // 0x801DA920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DA924: jr          $ra
    // 0x801DA928: nop

    return;
    // 0x801DA928: nop

;}
RECOMP_FUNC void M8_FUN_801da92c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA92C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801DA938: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA93C: jal         0x80133980
    // 0x801DA940: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801DA940: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    after_0:
    // 0x801DA944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DA948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DA94C: jr          $ra
    // 0x801DA950: nop

    return;
    // 0x801DA950: nop

;}
RECOMP_FUNC void M8_FUN_801da954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA954: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA95C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA960: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DA964: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DA968: bnel        $t6, $at, L_801DA97C
    if (ctx->r14 != ctx->r1) {
        // 0x801DA96C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801DA97C;
    }
    goto skip_0;
    // 0x801DA96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801DA970: jal         0x80020718
    // 0x801DA974: addiu       $a0, $zero, 0x6AB
    ctx->r4 = ADD32(0, 0X6AB);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801DA974: addiu       $a0, $zero, 0x6AB
    ctx->r4 = ADD32(0, 0X6AB);
    after_0:
    // 0x801DA978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DA97C:
    // 0x801DA97C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DA980: jr          $ra
    // 0x801DA984: nop

    return;
    // 0x801DA984: nop

;}
RECOMP_FUNC void M8_FUN_801da988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA98C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA990: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801DA994: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA998: jal         0x80133A24
    // 0x801DA99C: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801DA99C: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    after_0:
    // 0x801DA9A0: bnel        $v0, $zero, L_801DA9B4
    if (ctx->r2 != 0) {
        // 0x801DA9A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801DA9B4;
    }
    goto skip_0;
    // 0x801DA9A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801DA9A8: jal         0x80133980
    // 0x801DA9AC: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_1;
    // 0x801DA9AC: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    after_1:
    // 0x801DA9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DA9B4:
    // 0x801DA9B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DA9B8: jr          $ra
    // 0x801DA9BC: nop

    return;
    // 0x801DA9BC: nop

;}
RECOMP_FUNC void M8_FUN_801da9c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA9C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA9C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA9C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801DA9CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA9D0: jal         0x80133980
    // 0x801DA9D4: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801DA9D4: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_0:
    // 0x801DA9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DA9DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DA9E0: jr          $ra
    // 0x801DA9E4: nop

    return;
    // 0x801DA9E4: nop

;}
RECOMP_FUNC void M8_FUN_801da9e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DA9E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DA9EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DA9F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801DA9F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DA9F8: jal         0x80133980
    // 0x801DA9FC: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801DA9FC: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    after_0:
    // 0x801DAA00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DAA04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DAA08: jr          $ra
    // 0x801DAA0C: nop

    return;
    // 0x801DAA0C: nop

;}
RECOMP_FUNC void M8_FUN_801daa10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAA10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DAA14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DAA18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DAA1C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DAA20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DAA24: bnel        $t6, $at, L_801DAA38
    if (ctx->r14 != ctx->r1) {
        // 0x801DAA28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801DAA38;
    }
    goto skip_0;
    // 0x801DAA28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801DAA2C: jal         0x80020718
    // 0x801DAA30: addiu       $a0, $zero, 0x65B
    ctx->r4 = ADD32(0, 0X65B);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801DAA30: addiu       $a0, $zero, 0x65B
    ctx->r4 = ADD32(0, 0X65B);
    after_0:
    // 0x801DAA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DAA38:
    // 0x801DAA38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DAA3C: jr          $ra
    // 0x801DAA40: nop

    return;
    // 0x801DAA40: nop

;}
RECOMP_FUNC void M8_FUN_801daa44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAA44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DAA48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DAA4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DAA50: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DAA54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DAA58: bnel        $t6, $at, L_801DAA6C
    if (ctx->r14 != ctx->r1) {
        // 0x801DAA5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801DAA6C;
    }
    goto skip_0;
    // 0x801DAA5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801DAA60: jal         0x80020718
    // 0x801DAA64: addiu       $a0, $zero, 0x65B
    ctx->r4 = ADD32(0, 0X65B);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801DAA64: addiu       $a0, $zero, 0x65B
    ctx->r4 = ADD32(0, 0X65B);
    after_0:
    // 0x801DAA68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DAA6C:
    // 0x801DAA6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DAA70: jr          $ra
    // 0x801DAA74: nop

    return;
    // 0x801DAA74: nop

;}
RECOMP_FUNC void M8_FUN_801daa78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAA78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DAA7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DAA80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801DAA84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DAA88: jal         0x80133980
    // 0x801DAA8C: addiu       $a0, $zero, 0x12D
    ctx->r4 = ADD32(0, 0X12D);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801DAA8C: addiu       $a0, $zero, 0x12D
    ctx->r4 = ADD32(0, 0X12D);
    after_0:
    // 0x801DAA90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DAA94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DAA98: jr          $ra
    // 0x801DAA9C: nop

    return;
    // 0x801DAA9C: nop

;}
RECOMP_FUNC void M8_FUN_801daaa0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAAA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DAAA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DAAA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801DAAAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DAAB0: jal         0x80133980
    // 0x801DAAB4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801DAAB4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x801DAAB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DAABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DAAC0: jr          $ra
    // 0x801DAAC4: nop

    return;
    // 0x801DAAC4: nop

;}
RECOMP_FUNC void M8_FUN_801daac8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAAC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DAACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DAAD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801DAAD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DAAD8: jal         0x80133980
    // 0x801DAADC: addiu       $a0, $zero, 0x12F
    ctx->r4 = ADD32(0, 0X12F);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801DAADC: addiu       $a0, $zero, 0x12F
    ctx->r4 = ADD32(0, 0X12F);
    after_0:
    // 0x801DAAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DAAE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DAAE8: jr          $ra
    // 0x801DAAEC: nop

    return;
    // 0x801DAAEC: nop

;}
RECOMP_FUNC void M8_FUN_801daaf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAAF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DAAF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DAAF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801DAAFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DAB00: jal         0x80133980
    // 0x801DAB04: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801DAB04: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    after_0:
    // 0x801DAB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DAB0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DAB10: jr          $ra
    // 0x801DAB14: nop

    return;
    // 0x801DAB14: nop

;}
RECOMP_FUNC void M8_FUN_801dab18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAB18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DAB1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DAB20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DAB24: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DAB28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DAB2C: bnel        $t6, $at, L_801DAB40
    if (ctx->r14 != ctx->r1) {
        // 0x801DAB30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801DAB40;
    }
    goto skip_0;
    // 0x801DAB30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801DAB34: jal         0x80020718
    // 0x801DAB38: addiu       $a0, $zero, 0x64E
    ctx->r4 = ADD32(0, 0X64E);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801DAB38: addiu       $a0, $zero, 0x64E
    ctx->r4 = ADD32(0, 0X64E);
    after_0:
    // 0x801DAB3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DAB40:
    // 0x801DAB40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DAB44: jr          $ra
    // 0x801DAB48: nop

    return;
    // 0x801DAB48: nop

;}
RECOMP_FUNC void M8_FUN_801dab4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAB4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DAB50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DAB54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DAB58: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DAB5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DAB60: bnel        $t6, $at, L_801DAB74
    if (ctx->r14 != ctx->r1) {
        // 0x801DAB64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801DAB74;
    }
    goto skip_0;
    // 0x801DAB64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801DAB68: jal         0x80020718
    // 0x801DAB6C: addiu       $a0, $zero, 0x64E
    ctx->r4 = ADD32(0, 0X64E);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801DAB6C: addiu       $a0, $zero, 0x64E
    ctx->r4 = ADD32(0, 0X64E);
    after_0:
    // 0x801DAB70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DAB74:
    // 0x801DAB74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DAB78: jr          $ra
    // 0x801DAB7C: nop

    return;
    // 0x801DAB7C: nop

;}
RECOMP_FUNC void M8_FUN_801dab80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAB80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DAB84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DAB88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DAB8C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DAB90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DAB94: bnel        $t6, $at, L_801DABA8
    if (ctx->r14 != ctx->r1) {
        // 0x801DAB98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801DABA8;
    }
    goto skip_0;
    // 0x801DAB98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801DAB9C: jal         0x80020718
    // 0x801DABA0: addiu       $a0, $zero, 0x64E
    ctx->r4 = ADD32(0, 0X64E);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801DABA0: addiu       $a0, $zero, 0x64E
    ctx->r4 = ADD32(0, 0X64E);
    after_0:
    // 0x801DABA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DABA8:
    // 0x801DABA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DABAC: jr          $ra
    // 0x801DABB0: nop

    return;
    // 0x801DABB0: nop

;}
RECOMP_FUNC void M8_FUN_801dabb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DABB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DABB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DABBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801DABC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DABC4: jal         0x80020718
    // 0x801DABC8: addiu       $a0, $zero, 0x1A0
    ctx->r4 = ADD32(0, 0X1A0);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801DABC8: addiu       $a0, $zero, 0x1A0
    ctx->r4 = ADD32(0, 0X1A0);
    after_0:
    // 0x801DABCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DABD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DABD4: jr          $ra
    // 0x801DABD8: nop

    return;
    // 0x801DABD8: nop

;}
