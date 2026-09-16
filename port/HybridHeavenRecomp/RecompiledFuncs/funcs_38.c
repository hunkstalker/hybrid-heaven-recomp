#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M23_FUN_801c43bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C43BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C43C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C43C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C43C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C43CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C43D0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C43D4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801C43D8: sb          $zero, -0x3738($at)
    MEM_B(-0X3738, ctx->r1) = 0;
    // 0x801C43DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C43E0: addiu       $a3, $a3, -0x11DC
    ctx->r7 = ADD32(ctx->r7, -0X11DC);
    // 0x801C43E4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C43E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C43EC: jal         0x8001B204
    // 0x801C43F0: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C43F0: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_0:
    // 0x801C43F4: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801C43F8: lbu         $a2, -0x3738($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X3738);
    // 0x801C43FC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4400: addiu       $a3, $a3, -0x11C8
    ctx->r7 = ADD32(ctx->r7, -0X11C8);
    // 0x801C4404: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C4408: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C440C: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C4410: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C4414: addiu       $a2, $a2, 0x94
    ctx->r6 = ADD32(ctx->r6, 0X94);
    // 0x801C4418: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C441C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C4420: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C4424: jal         0x8001B204
    // 0x801C4428: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C4428: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    after_1:
    // 0x801C442C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4430: addiu       $a3, $a3, -0x11BC
    ctx->r7 = ADD32(ctx->r7, -0X11BC);
    // 0x801C4434: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C4438: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C443C: jal         0x8001B204
    // 0x801C4440: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C4440: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_2:
    // 0x801C4444: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4448: addiu       $a3, $a3, -0x11B0
    ctx->r7 = ADD32(ctx->r7, -0X11B0);
    // 0x801C444C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C4450: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4454: jal         0x8001B204
    // 0x801C4458: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C4458: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_3:
    // 0x801C445C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4460: addiu       $a3, $a3, -0x11A4
    ctx->r7 = ADD32(ctx->r7, -0X11A4);
    // 0x801C4464: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C4468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C446C: jal         0x8001B204
    // 0x801C4470: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801C4470: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x801C4474: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4478: addiu       $a3, $a3, -0x11A0
    ctx->r7 = ADD32(ctx->r7, -0X11A0);
    // 0x801C447C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C4480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C4484: jal         0x8001B204
    // 0x801C4488: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801C4488: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x801C448C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4490: addiu       $a3, $a3, -0x119C
    ctx->r7 = ADD32(ctx->r7, -0X119C);
    // 0x801C4494: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801C4498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C449C: jal         0x8001B204
    // 0x801C44A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801C44A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x801C44A4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C44A8: addiu       $a1, $a1, 0x44C4
    ctx->r5 = ADD32(ctx->r5, 0X44C4);
    // 0x801C44AC: jal         0x800058DC
    // 0x801C44B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C44B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x801C44B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C44B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C44BC: jr          $ra
    // 0x801C44C0: nop

    return;
    // 0x801C44C0: nop

;}
RECOMP_FUNC void M23_FUN_801c44c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C44C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C44C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C44CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C44D0: jal         0x801C1340
    // 0x801C44D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_0;
    // 0x801C44D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C44D8: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x801C44DC: beq         $t6, $zero, L_801C44F8
    if (ctx->r14 == 0) {
        // 0x801C44E0: lui         $t7, 0x801D
        ctx->r15 = S32(0X801D << 16);
            goto L_801C44F8;
    }
    // 0x801C44E0: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C44E4: lbu         $t7, -0x3738($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3738);
    // 0x801C44E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C44EC: bne         $t7, $at, L_801C44F8
    if (ctx->r15 != ctx->r1) {
        // 0x801C44F0: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801C44F8;
    }
    // 0x801C44F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C44F4: sb          $zero, -0x3738($at)
    MEM_B(-0X3738, ctx->r1) = 0;
L_801C44F8:
    // 0x801C44F8: jal         0x801C1340
    // 0x801C44FC: nop

    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_1;
    // 0x801C44FC: nop

    after_1:
    // 0x801C4500: andi        $t8, $v0, 0x400
    ctx->r24 = ctx->r2 & 0X400;
    // 0x801C4504: beq         $t8, $zero, L_801C4528
    if (ctx->r24 == 0) {
        // 0x801C4508: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801C4528;
    }
    // 0x801C4508: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C450C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C4510: addiu       $v0, $v0, -0x3738
    ctx->r2 = ADD32(ctx->r2, -0X3738);
    // 0x801C4514: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x801C4518: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C451C: bne         $t9, $zero, L_801C4528
    if (ctx->r25 != 0) {
        // 0x801C4520: nop
    
            goto L_801C4528;
    }
    // 0x801C4520: nop

    // 0x801C4524: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_801C4528:
    // 0x801C4528: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C452C: addiu       $v0, $v0, -0x3738
    ctx->r2 = ADD32(ctx->r2, -0X3738);
    // 0x801C4530: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x801C4534: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4538: addiu       $a3, $a3, -0x1198
    ctx->r7 = ADD32(ctx->r7, -0X1198);
    // 0x801C453C: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C4540: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C4544: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C4548: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C454C: addiu       $a2, $a2, 0x94
    ctx->r6 = ADD32(ctx->r6, 0X94);
    // 0x801C4550: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C4554: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C4558: jal         0x8001B204
    // 0x801C455C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C455C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    after_2:
    // 0x801C4560: jal         0x801C1334
    // 0x801C4564: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_3;
    // 0x801C4564: nop

    after_3:
    // 0x801C4568: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x801C456C: beq         $t1, $zero, L_801C4580
    if (ctx->r9 == 0) {
        // 0x801C4570: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801C4580;
    }
    // 0x801C4570: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C4574: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4578: jal         0x800058DC
    // 0x801C457C: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C457C: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    after_4:
L_801C4580:
    // 0x801C4580: jal         0x801C1334
    // 0x801C4584: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_5;
    // 0x801C4584: nop

    after_5:
    // 0x801C4588: andi        $t2, $v0, 0xB000
    ctx->r10 = ctx->r2 & 0XB000;
    // 0x801C458C: beql        $t2, $zero, L_801C45BC
    if (ctx->r10 == 0) {
        // 0x801C4590: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C45BC;
    }
    goto skip_0;
    // 0x801C4590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801C4594: jal         0x80020718
    // 0x801C4598: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_6;
    // 0x801C4598: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_6:
    // 0x801C459C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C45A0: jal         0x80152CF8
    // 0x801C45A4: lbu         $a0, -0x3738($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3738);
    LOOKUP_FUNC(0x80152CF8)(rdram, ctx);
        goto after_7;
    // 0x801C45A4: lbu         $a0, -0x3738($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3738);
    after_7:
    // 0x801C45A8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C45AC: addiu       $a1, $a1, 0x45C8
    ctx->r5 = ADD32(ctx->r5, 0X45C8);
    // 0x801C45B0: jal         0x800058DC
    // 0x801C45B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801C45B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_8:
    // 0x801C45B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C45BC:
    // 0x801C45BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C45C0: jr          $ra
    // 0x801C45C4: nop

    return;
    // 0x801C45C4: nop

;}
RECOMP_FUNC void M23_FUN_801c45c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C45C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C45CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C45D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C45D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C45D8: jal         0x800023A8
    // 0x801C45DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_0;
    // 0x801C45DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801C45E0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C45E4: jal         0x80005700
    // 0x801C45E8: lw          $a0, -0x3758($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3758);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801C45E8: lw          $a0, -0x3758($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3758);
    after_1:
    // 0x801C45EC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C45F0: jal         0x80005700
    // 0x801C45F4: lw          $a0, -0x3748($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3748);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x801C45F4: lw          $a0, -0x3748($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3748);
    after_2:
    // 0x801C45F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C45FC: sw          $zero, -0x3758($at)
    MEM_W(-0X3758, ctx->r1) = 0;
    // 0x801C4600: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C4604: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x801C4608: sw          $zero, -0x3748($at)
    MEM_W(-0X3748, ctx->r1) = 0;
    // 0x801C460C: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    // 0x801C4610: jal         0x80005670
    // 0x801C4614: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x801C4614: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x801C4618: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C461C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4620: sw          $v0, -0x3744($at)
    MEM_W(-0X3744, ctx->r1) = ctx->r2;
    // 0x801C4624: addiu       $a1, $a1, 0x4640
    ctx->r5 = ADD32(ctx->r5, 0X4640);
    // 0x801C4628: jal         0x800058DC
    // 0x801C462C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C462C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x801C4630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C4638: jr          $ra
    // 0x801C463C: nop

    return;
    // 0x801C463C: nop

;}
RECOMP_FUNC void M23_FUN_801c4640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C4644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C4648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C464C: jal         0x80140368
    // 0x801C4650: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80140368)(rdram, ctx);
        goto after_0;
    // 0x801C4650: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C4654: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4658: addiu       $a1, $a1, 0x4674
    ctx->r5 = ADD32(ctx->r5, 0X4674);
    // 0x801C465C: jal         0x800058DC
    // 0x801C4660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C4660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801C4664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C466C: jr          $ra
    // 0x801C4670: nop

    return;
    // 0x801C4670: nop

;}
RECOMP_FUNC void M23_FUN_801c4674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4674: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C4678: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C467C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C4680: jal         0x801403F8
    // 0x801C4684: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801403F8)(rdram, ctx);
        goto after_0;
    // 0x801C4684: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C4688: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x801C468C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C4690: bne         $t6, $at, L_801C4778
    if (ctx->r14 != ctx->r1) {
        // 0x801C4694: sb          $v0, 0x27($sp)
        MEM_B(0X27, ctx->r29) = ctx->r2;
            goto L_801C4778;
    }
    // 0x801C4694: sb          $v0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r2;
    // 0x801C4698: jal         0x80142570
    // 0x801C469C: nop

    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_1;
    // 0x801C469C: nop

    after_1:
    // 0x801C46A0: jal         0x800179B0
    // 0x801C46A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_2;
    // 0x801C46A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801C46A8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C46AC: lw          $a0, -0x3744($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3744);
    // 0x801C46B0: beq         $a0, $zero, L_801C46C8
    if (ctx->r4 == 0) {
        // 0x801C46B4: nop
    
            goto L_801C46C8;
    }
    // 0x801C46B4: nop

    // 0x801C46B8: jal         0x80005700
    // 0x801C46BC: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x801C46BC: nop

    after_3:
    // 0x801C46C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C46C4: sw          $zero, -0x3744($at)
    MEM_W(-0X3744, ctx->r1) = 0;
L_801C46C8:
    // 0x801C46C8: jal         0x8013EA54
    // 0x801C46CC: nop

    LOOKUP_FUNC(0x8013EA54)(rdram, ctx);
        goto after_4;
    // 0x801C46CC: nop

    after_4:
    // 0x801C46D0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801C46D4: beq         $at, $zero, L_801C46EC
    if (ctx->r1 == 0) {
        // 0x801C46D8: nop
    
            goto L_801C46EC;
    }
    // 0x801C46D8: nop

    // 0x801C46DC: jal         0x80152D0C
    // 0x801C46E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80152D0C)(rdram, ctx);
        goto after_5;
    // 0x801C46E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x801C46E4: b           L_801C46F4
    // 0x801C46E8: nop

        goto L_801C46F4;
    // 0x801C46E8: nop

L_801C46EC:
    // 0x801C46EC: jal         0x80152D0C
    // 0x801C46F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80152D0C)(rdram, ctx);
        goto after_6;
    // 0x801C46F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
L_801C46F4:
    // 0x801C46F4: jal         0x8013EA54
    // 0x801C46F8: nop

    LOOKUP_FUNC(0x8013EA54)(rdram, ctx);
        goto after_7;
    // 0x801C46F8: nop

    after_7:
    // 0x801C46FC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801C4700: bne         $v0, $at, L_801C4718
    if (ctx->r2 != ctx->r1) {
        // 0x801C4704: nop
    
            goto L_801C4718;
    }
    // 0x801C4704: nop

    // 0x801C4708: jal         0x80152D3C
    // 0x801C470C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80152D3C)(rdram, ctx);
        goto after_8;
    // 0x801C470C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x801C4710: b           L_801C4720
    // 0x801C4714: nop

        goto L_801C4720;
    // 0x801C4714: nop

L_801C4718:
    // 0x801C4718: jal         0x80152D3C
    // 0x801C471C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80152D3C)(rdram, ctx);
        goto after_9;
    // 0x801C471C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
L_801C4720:
    // 0x801C4720: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C4724: lbu         $t7, -0x3738($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3738);
    // 0x801C4728: bne         $t7, $zero, L_801C4738
    if (ctx->r15 != 0) {
        // 0x801C472C: nop
    
            goto L_801C4738;
    }
    // 0x801C472C: nop

    // 0x801C4730: jal         0x80152D4C
    // 0x801C4734: nop

    LOOKUP_FUNC(0x80152D4C)(rdram, ctx);
        goto after_10;
    // 0x801C4734: nop

    after_10:
L_801C4738:
    // 0x801C4738: jal         0x80152F7C
    // 0x801C473C: nop

    LOOKUP_FUNC(0x80152F7C)(rdram, ctx);
        goto after_11;
    // 0x801C473C: nop

    after_11:
    // 0x801C4740: jal         0x80020718
    // 0x801C4744: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_12;
    // 0x801C4744: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_12:
    // 0x801C4748: jal         0x80153008
    // 0x801C474C: nop

    LOOKUP_FUNC(0x80153008)(rdram, ctx);
        goto after_13;
    // 0x801C474C: nop

    after_13:
    // 0x801C4750: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x801C4754: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x801C4758: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C475C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C4760: jal         0x8012FE50
    // 0x801C4764: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_14;
    // 0x801C4764: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_14:
    // 0x801C4768: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C476C: addiu       $a1, $a1, 0x47C4
    ctx->r5 = ADD32(ctx->r5, 0X47C4);
    // 0x801C4770: jal         0x800058DC
    // 0x801C4774: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_15;
    // 0x801C4774: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_15:
L_801C4778:
    // 0x801C4778: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x801C477C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C4780: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x801C4784: bne         $t8, $at, L_801C47B4
    if (ctx->r24 != ctx->r1) {
        // 0x801C4788: addiu       $a1, $zero, 0x73
        ctx->r5 = ADD32(0, 0X73);
            goto L_801C47B4;
    }
    // 0x801C4788: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C478C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801C4790: addiu       $t9, $t9, 0x47C4
    ctx->r25 = ADD32(ctx->r25, 0X47C4);
    // 0x801C4794: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801C4798: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C479C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C47A0: jal         0x8012FE50
    // 0x801C47A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_16;
    // 0x801C47A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
    // 0x801C47A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801C47AC: jal         0x800058DC
    // 0x801C47B0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_17;
    // 0x801C47B0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_17:
L_801C47B4:
    // 0x801C47B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C47B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C47BC: jr          $ra
    // 0x801C47C0: nop

    return;
    // 0x801C47C0: nop

;}
RECOMP_FUNC void M23_FUN_801c47c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C47C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C47C8: jr          $ra
    // 0x801C47CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C47CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c47d0(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c47d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C47D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C47D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C47D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C47DC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C47E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C47E4: jal         0x80005700
    // 0x801C47E8: lw          $a0, -0x3758($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3758);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801C47E8: lw          $a0, -0x3758($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3758);
    after_0:
    // 0x801C47EC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C47F0: jal         0x80005700
    // 0x801C47F4: lw          $a0, -0x3748($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3748);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801C47F4: lw          $a0, -0x3748($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3748);
    after_1:
    // 0x801C47F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C47FC: sw          $zero, -0x3758($at)
    MEM_W(-0X3758, ctx->r1) = 0;
    // 0x801C4800: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C4804: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x801C4808: sw          $zero, -0x3748($at)
    MEM_W(-0X3748, ctx->r1) = 0;
    // 0x801C480C: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    // 0x801C4810: jal         0x80005670
    // 0x801C4814: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x801C4814: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801C4818: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C481C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4820: sw          $v0, -0x3744($at)
    MEM_W(-0X3744, ctx->r1) = ctx->r2;
    // 0x801C4824: addiu       $a1, $a1, 0x4840
    ctx->r5 = ADD32(ctx->r5, 0X4840);
    // 0x801C4828: jal         0x800058DC
    // 0x801C482C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C482C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x801C4830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C4838: jr          $ra
    // 0x801C483C: nop

    return;
    // 0x801C483C: nop

;}
RECOMP_FUNC void M23_FUN_801c4840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C4844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C4848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C484C: jal         0x80140600
    // 0x801C4850: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80140600)(rdram, ctx);
        goto after_0;
    // 0x801C4850: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C4854: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C4858: addiu       $a1, $a1, -0x35CC
    ctx->r5 = ADD32(ctx->r5, -0X35CC);
    // 0x801C485C: jal         0x80005670
    // 0x801C4860: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x801C4860: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801C4864: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C4868: lui         $a0, 0xC00
    ctx->r4 = S32(0XC00 << 16);
    // 0x801C486C: sw          $v0, -0x3740($at)
    MEM_W(-0X3740, ctx->r1) = ctx->r2;
    // 0x801C4870: ori         $a0, $a0, 0xC0C
    ctx->r4 = ctx->r4 | 0XC0C;
    // 0x801C4874: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801C4878: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801C487C: jal         0x80002364
    // 0x801C4880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_2;
    // 0x801C4880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801C4884: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4888: addiu       $a1, $a1, 0x48A4
    ctx->r5 = ADD32(ctx->r5, 0X48A4);
    // 0x801C488C: jal         0x800058DC
    // 0x801C4890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C4890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x801C4894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C489C: jr          $ra
    // 0x801C48A0: nop

    return;
    // 0x801C48A0: nop

;}
RECOMP_FUNC void M23_FUN_801c48a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C48A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C48A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C48AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C48B0: jal         0x801406A4
    // 0x801C48B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801406A4)(rdram, ctx);
        goto after_0;
    // 0x801C48B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C48B8: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x801C48BC: beql        $t6, $zero, L_801C4948
    if (ctx->r14 == 0) {
        // 0x801C48C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801C4948;
    }
    goto skip_0;
    // 0x801C48C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801C48C4: jal         0x80142570
    // 0x801C48C8: nop

    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_1;
    // 0x801C48C8: nop

    after_1:
    // 0x801C48CC: jal         0x800179B0
    // 0x801C48D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_2;
    // 0x801C48D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801C48D4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C48D8: lw          $a0, -0x3744($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3744);
    // 0x801C48DC: beq         $a0, $zero, L_801C48F4
    if (ctx->r4 == 0) {
        // 0x801C48E0: nop
    
            goto L_801C48F4;
    }
    // 0x801C48E0: nop

    // 0x801C48E4: jal         0x80005700
    // 0x801C48E8: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x801C48E8: nop

    after_3:
    // 0x801C48EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C48F0: sw          $zero, -0x3744($at)
    MEM_W(-0X3744, ctx->r1) = 0;
L_801C48F4:
    // 0x801C48F4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C48F8: lw          $a0, -0x3740($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3740);
    // 0x801C48FC: beq         $a0, $zero, L_801C4914
    if (ctx->r4 == 0) {
        // 0x801C4900: nop
    
            goto L_801C4914;
    }
    // 0x801C4900: nop

    // 0x801C4904: jal         0x80005700
    // 0x801C4908: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x801C4908: nop

    after_4:
    // 0x801C490C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C4910: sw          $zero, -0x3740($at)
    MEM_W(-0X3740, ctx->r1) = 0;
L_801C4914:
    // 0x801C4914: jal         0x800023A8
    // 0x801C4918: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_5;
    // 0x801C4918: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x801C491C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x801C4920: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C4924: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C4928: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C492C: jal         0x8012FE50
    // 0x801C4930: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_6;
    // 0x801C4930: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x801C4934: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4938: addiu       $a1, $a1, 0x4954
    ctx->r5 = ADD32(ctx->r5, 0X4954);
    // 0x801C493C: jal         0x800058DC
    // 0x801C4940: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C4940: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x801C4944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C4948:
    // 0x801C4948: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C494C: jr          $ra
    // 0x801C4950: nop

    return;
    // 0x801C4950: nop

;}
RECOMP_FUNC void M23_FUN_801c4954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4954: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C4958: jr          $ra
    // 0x801C495C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C495C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c4960(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c4960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4960: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801C4964: lbu         $t6, -0x40C4($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X40C4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c4968(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c4968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4968: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C496C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C4970: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C4974: bne         $t6, $zero, L_801C4994
    if (ctx->r14 != 0) {
        // 0x801C4978: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_801C4994;
    }
    // 0x801C4978: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C497C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801C4980: addiu       $t0, $t0, -0x3738
    ctx->r8 = ADD32(ctx->r8, -0X3738);
    // 0x801C4984: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801C4988: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x801C498C: b           L_801C49AC
    // 0x801C4990: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
        goto L_801C49AC;
    // 0x801C4990: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_801C4994:
    // 0x801C4994: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801C4998: addiu       $t0, $t0, -0x3738
    ctx->r8 = ADD32(ctx->r8, -0X3738);
    // 0x801C499C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C49A0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801C49A4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x801C49A8: sb          $t7, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r15;
L_801C49AC:
    // 0x801C49AC: lbu         $a2, 0x0($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X0);
    // 0x801C49B0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C49B4: addiu       $a3, $a3, -0x118C
    ctx->r7 = ADD32(ctx->r7, -0X118C);
    // 0x801C49B8: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C49BC: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C49C0: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C49C4: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C49C8: addiu       $a2, $a2, 0x8A
    ctx->r6 = ADD32(ctx->r6, 0X8A);
    // 0x801C49CC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C49D0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C49D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C49D8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C49DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801C49E0: jal         0x8001B204
    // 0x801C49E4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C49E4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x801C49E8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801C49EC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C49F0: addiu       $a3, $a3, -0x1180
    ctx->r7 = ADD32(ctx->r7, -0X1180);
    // 0x801C49F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C49F8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C49FC: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    // 0x801C4A00: jal         0x8001B204
    // 0x801C4A04: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C4A04: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x801C4A08: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801C4A0C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4A10: addiu       $a3, $a3, -0x1174
    ctx->r7 = ADD32(ctx->r7, -0X1174);
    // 0x801C4A14: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C4A18: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4A1C: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    // 0x801C4A20: jal         0x8001B204
    // 0x801C4A24: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C4A24: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_2:
    // 0x801C4A28: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4A2C: addiu       $a3, $a3, -0x1168
    ctx->r7 = ADD32(ctx->r7, -0X1168);
    // 0x801C4A30: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C4A34: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4A38: jal         0x8001B204
    // 0x801C4A3C: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C4A3C: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_3:
    // 0x801C4A40: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4A44: addiu       $a3, $a3, -0x115C
    ctx->r7 = ADD32(ctx->r7, -0X115C);
    // 0x801C4A48: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C4A4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C4A50: jal         0x8001B204
    // 0x801C4A54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801C4A54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x801C4A58: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4A5C: addiu       $a3, $a3, -0x1158
    ctx->r7 = ADD32(ctx->r7, -0X1158);
    // 0x801C4A60: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C4A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C4A68: jal         0x8001B204
    // 0x801C4A6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801C4A6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x801C4A70: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4A74: addiu       $a3, $a3, -0x1154
    ctx->r7 = ADD32(ctx->r7, -0X1154);
    // 0x801C4A78: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801C4A7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C4A80: jal         0x8001B204
    // 0x801C4A84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801C4A84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x801C4A88: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4A8C: addiu       $a1, $a1, 0x4AA8
    ctx->r5 = ADD32(ctx->r5, 0X4AA8);
    // 0x801C4A90: jal         0x800058DC
    // 0x801C4A94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C4A94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x801C4A98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C4A9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C4AA0: jr          $ra
    // 0x801C4AA4: nop

    return;
    // 0x801C4AA4: nop

;}
RECOMP_FUNC void M23_FUN_801c4aa8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4AA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C4AAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C4AB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C4AB4: jal         0x801C1340
    // 0x801C4AB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_0;
    // 0x801C4AB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C4ABC: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x801C4AC0: beq         $t6, $zero, L_801C4AE8
    if (ctx->r14 == 0) {
        // 0x801C4AC4: lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
            goto L_801C4AE8;
    }
    // 0x801C4AC4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C4AC8: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C4ACC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801C4AD0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801C4AD4: bne         $v0, $zero, L_801C4AE4
    if (ctx->r2 != 0) {
        // 0x801C4AD8: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_801C4AE4;
    }
    // 0x801C4AD8: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x801C4ADC: b           L_801C4AE8
    // 0x801C4AE0: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
        goto L_801C4AE8;
    // 0x801C4AE0: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_801C4AE4:
    // 0x801C4AE4: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_801C4AE8:
    // 0x801C4AE8: jal         0x801C1340
    // 0x801C4AEC: nop

    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_1;
    // 0x801C4AEC: nop

    after_1:
    // 0x801C4AF0: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x801C4AF4: beq         $t9, $zero, L_801C4B20
    if (ctx->r25 == 0) {
        // 0x801C4AF8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801C4B20;
    }
    // 0x801C4AF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C4AFC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C4B00: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C4B04: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801C4B08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C4B0C: bne         $v0, $at, L_801C4B1C
    if (ctx->r2 != ctx->r1) {
        // 0x801C4B10: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_801C4B1C;
    }
    // 0x801C4B10: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x801C4B14: b           L_801C4B20
    // 0x801C4B18: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801C4B20;
    // 0x801C4B18: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_801C4B1C:
    // 0x801C4B1C: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
L_801C4B20:
    // 0x801C4B20: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C4B24: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C4B28: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x801C4B2C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4B30: addiu       $a3, $a3, -0x1150
    ctx->r7 = ADD32(ctx->r7, -0X1150);
    // 0x801C4B34: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C4B38: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C4B3C: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C4B40: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C4B44: addiu       $a2, $a2, 0x8A
    ctx->r6 = ADD32(ctx->r6, 0X8A);
    // 0x801C4B48: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C4B4C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C4B50: jal         0x8001B204
    // 0x801C4B54: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C4B54: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    after_2:
    // 0x801C4B58: jal         0x801C1334
    // 0x801C4B5C: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_3;
    // 0x801C4B5C: nop

    after_3:
    // 0x801C4B60: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x801C4B64: beq         $t1, $zero, L_801C4B78
    if (ctx->r9 == 0) {
        // 0x801C4B68: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801C4B78;
    }
    // 0x801C4B68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C4B6C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4B70: jal         0x800058DC
    // 0x801C4B74: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C4B74: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    after_4:
L_801C4B78:
    // 0x801C4B78: jal         0x801C1334
    // 0x801C4B7C: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_5;
    // 0x801C4B7C: nop

    after_5:
    // 0x801C4B80: andi        $t2, $v0, 0xB000
    ctx->r10 = ctx->r2 & 0XB000;
    // 0x801C4B84: beq         $t2, $zero, L_801C4C6C
    if (ctx->r10 == 0) {
        // 0x801C4B88: lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
            goto L_801C4C6C;
    }
    // 0x801C4B88: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C4B8C: lbu         $v0, -0x3738($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3738);
    // 0x801C4B90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C4B94: beq         $v0, $zero, L_801C4BB4
    if (ctx->r2 == 0) {
        // 0x801C4B98: nop
    
            goto L_801C4BB4;
    }
    // 0x801C4B98: nop

    // 0x801C4B9C: beq         $v0, $at, L_801C4C08
    if (ctx->r2 == ctx->r1) {
        // 0x801C4BA0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801C4C08;
    }
    // 0x801C4BA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C4BA4: beq         $v0, $at, L_801C4C60
    if (ctx->r2 == ctx->r1) {
        // 0x801C4BA8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801C4C60;
    }
    // 0x801C4BA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C4BAC: b           L_801C4C70
    // 0x801C4BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C4C70;
    // 0x801C4BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C4BB4:
    // 0x801C4BB4: jal         0x80020718
    // 0x801C4BB8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_6;
    // 0x801C4BB8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_6:
    // 0x801C4BBC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4BC0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801C4BC4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801C4BC8: addiu       $a3, $a3, -0x1144
    ctx->r7 = ADD32(ctx->r7, -0X1144);
    // 0x801C4BCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C4BD0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4BD4: jal         0x8001B204
    // 0x801C4BD8: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x801C4BD8: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_7:
    // 0x801C4BDC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4BE0: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x801C4BE4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C4BE8: addiu       $a3, $a3, -0x1138
    ctx->r7 = ADD32(ctx->r7, -0X1138);
    // 0x801C4BEC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C4BF0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4BF4: jal         0x8001B204
    // 0x801C4BF8: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x801C4BF8: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_8:
    // 0x801C4BFC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C4C00: b           L_801C4C6C
    // 0x801C4C04: sb          $zero, -0x40C4($at)
    MEM_B(-0X40C4, ctx->r1) = 0;
        goto L_801C4C6C;
    // 0x801C4C04: sb          $zero, -0x40C4($at)
    MEM_B(-0X40C4, ctx->r1) = 0;
L_801C4C08:
    // 0x801C4C08: jal         0x80020718
    // 0x801C4C0C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_9;
    // 0x801C4C0C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
    // 0x801C4C10: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4C14: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x801C4C18: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801C4C1C: addiu       $a3, $a3, -0x112C
    ctx->r7 = ADD32(ctx->r7, -0X112C);
    // 0x801C4C20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C4C24: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4C28: jal         0x8001B204
    // 0x801C4C2C: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x801C4C2C: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_10:
    // 0x801C4C30: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4C34: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801C4C38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C4C3C: addiu       $a3, $a3, -0x1120
    ctx->r7 = ADD32(ctx->r7, -0X1120);
    // 0x801C4C40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C4C44: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4C48: jal         0x8001B204
    // 0x801C4C4C: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x801C4C4C: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_11:
    // 0x801C4C50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C4C54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C4C58: b           L_801C4C6C
    // 0x801C4C5C: sb          $t7, -0x40C4($at)
    MEM_B(-0X40C4, ctx->r1) = ctx->r15;
        goto L_801C4C6C;
    // 0x801C4C5C: sb          $t7, -0x40C4($at)
    MEM_B(-0X40C4, ctx->r1) = ctx->r15;
L_801C4C60:
    // 0x801C4C60: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4C64: jal         0x800058DC
    // 0x801C4C68: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x801C4C68: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    after_12:
L_801C4C6C:
    // 0x801C4C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C4C70:
    // 0x801C4C70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C4C74: jr          $ra
    // 0x801C4C78: nop

    return;
    // 0x801C4C78: nop

;}
RECOMP_FUNC void M23_FUN_801c4c7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4C7C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801C4C80: lbu         $v0, -0x43F3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X43F3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c4c84(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c4c84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4C84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C4C88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C4C8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C4C90: beq         $v0, $zero, L_801C4D84
    if (ctx->r2 == 0) {
        // 0x801C4C94: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801C4D84;
    }
    // 0x801C4C94: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C4C98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C4C9C: beq         $v0, $at, L_801C4D18
    if (ctx->r2 == ctx->r1) {
        // 0x801C4CA0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801C4D18;
    }
    // 0x801C4CA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C4CA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C4CA8: bne         $v0, $at, L_801C4DF0
    if (ctx->r2 != ctx->r1) {
        // 0x801C4CAC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801C4DF0;
    }
    // 0x801C4CAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C4CB0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4CB4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801C4CB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C4CBC: addiu       $a3, $a3, -0x1114
    ctx->r7 = ADD32(ctx->r7, -0X1114);
    // 0x801C4CC0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4CC4: jal         0x8001B204
    // 0x801C4CC8: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C4CC8: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_0:
    // 0x801C4CCC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4CD0: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x801C4CD4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C4CD8: addiu       $a3, $a3, -0x1108
    ctx->r7 = ADD32(ctx->r7, -0X1108);
    // 0x801C4CDC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C4CE0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4CE4: jal         0x8001B204
    // 0x801C4CE8: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C4CE8: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_1:
    // 0x801C4CEC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4CF0: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x801C4CF4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C4CF8: addiu       $a3, $a3, -0x10FC
    ctx->r7 = ADD32(ctx->r7, -0X10FC);
    // 0x801C4CFC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C4D00: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4D04: jal         0x8001B204
    // 0x801C4D08: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C4D08: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_2:
    // 0x801C4D0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C4D10: b           L_801C4DF0
    // 0x801C4D14: sb          $zero, -0x3738($at)
    MEM_B(-0X3738, ctx->r1) = 0;
        goto L_801C4DF0;
    // 0x801C4D14: sb          $zero, -0x3738($at)
    MEM_B(-0X3738, ctx->r1) = 0;
L_801C4D18:
    // 0x801C4D18: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4D1C: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x801C4D20: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C4D24: addiu       $a3, $a3, -0x10F0
    ctx->r7 = ADD32(ctx->r7, -0X10F0);
    // 0x801C4D28: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4D2C: jal         0x8001B204
    // 0x801C4D30: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C4D30: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_3:
    // 0x801C4D34: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4D38: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801C4D3C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C4D40: addiu       $a3, $a3, -0x10E4
    ctx->r7 = ADD32(ctx->r7, -0X10E4);
    // 0x801C4D44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C4D48: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4D4C: jal         0x8001B204
    // 0x801C4D50: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801C4D50: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_4:
    // 0x801C4D54: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4D58: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x801C4D5C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C4D60: addiu       $a3, $a3, -0x10D8
    ctx->r7 = ADD32(ctx->r7, -0X10D8);
    // 0x801C4D64: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C4D68: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4D6C: jal         0x8001B204
    // 0x801C4D70: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801C4D70: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_5:
    // 0x801C4D74: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C4D78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C4D7C: b           L_801C4DF0
    // 0x801C4D80: sb          $t2, -0x3738($at)
    MEM_B(-0X3738, ctx->r1) = ctx->r10;
        goto L_801C4DF0;
    // 0x801C4D80: sb          $t2, -0x3738($at)
    MEM_B(-0X3738, ctx->r1) = ctx->r10;
L_801C4D84:
    // 0x801C4D84: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4D88: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x801C4D8C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801C4D90: addiu       $a3, $a3, -0x10CC
    ctx->r7 = ADD32(ctx->r7, -0X10CC);
    // 0x801C4D94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C4D98: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4D9C: jal         0x8001B204
    // 0x801C4DA0: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801C4DA0: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_6:
    // 0x801C4DA4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4DA8: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x801C4DAC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C4DB0: addiu       $a3, $a3, -0x10C0
    ctx->r7 = ADD32(ctx->r7, -0X10C0);
    // 0x801C4DB4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C4DB8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4DBC: jal         0x8001B204
    // 0x801C4DC0: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x801C4DC0: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_7:
    // 0x801C4DC4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4DC8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801C4DCC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801C4DD0: addiu       $a3, $a3, -0x10B4
    ctx->r7 = ADD32(ctx->r7, -0X10B4);
    // 0x801C4DD4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C4DD8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4DDC: jal         0x8001B204
    // 0x801C4DE0: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x801C4DE0: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_8:
    // 0x801C4DE4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801C4DE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C4DEC: sb          $t6, -0x3738($at)
    MEM_B(-0X3738, ctx->r1) = ctx->r14;
L_801C4DF0:
    // 0x801C4DF0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801C4DF4: lbu         $a2, -0x3738($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X3738);
    // 0x801C4DF8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4DFC: addiu       $a3, $a3, -0x10A8
    ctx->r7 = ADD32(ctx->r7, -0X10A8);
    // 0x801C4E00: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C4E04: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C4E08: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C4E0C: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C4E10: addiu       $a2, $a2, 0x8A
    ctx->r6 = ADD32(ctx->r6, 0X8A);
    // 0x801C4E14: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C4E18: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C4E1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C4E20: jal         0x8001B204
    // 0x801C4E24: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x801C4E24: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    after_9:
    // 0x801C4E28: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4E2C: addiu       $a3, $a3, -0x109C
    ctx->r7 = ADD32(ctx->r7, -0X109C);
    // 0x801C4E30: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C4E34: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4E38: jal         0x8001B204
    // 0x801C4E3C: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x801C4E3C: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    after_10:
    // 0x801C4E40: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4E44: addiu       $a3, $a3, -0x1090
    ctx->r7 = ADD32(ctx->r7, -0X1090);
    // 0x801C4E48: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C4E4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C4E50: jal         0x8001B204
    // 0x801C4E54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x801C4E54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x801C4E58: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4E5C: addiu       $a3, $a3, -0x108C
    ctx->r7 = ADD32(ctx->r7, -0X108C);
    // 0x801C4E60: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801C4E64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C4E68: jal         0x8001B204
    // 0x801C4E6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x801C4E6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x801C4E70: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4E74: addiu       $a1, $a1, 0x4E90
    ctx->r5 = ADD32(ctx->r5, 0X4E90);
    // 0x801C4E78: jal         0x800058DC
    // 0x801C4E7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_13;
    // 0x801C4E7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_13:
    // 0x801C4E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C4E84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C4E88: jr          $ra
    // 0x801C4E8C: nop

    return;
    // 0x801C4E8C: nop

;}
RECOMP_FUNC void M23_FUN_801c4e90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4E90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C4E94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C4E98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C4E9C: jal         0x801C1340
    // 0x801C4EA0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_0;
    // 0x801C4EA0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C4EA4: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x801C4EA8: beq         $t6, $zero, L_801C4ED0
    if (ctx->r14 == 0) {
        // 0x801C4EAC: lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
            goto L_801C4ED0;
    }
    // 0x801C4EAC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C4EB0: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C4EB4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801C4EB8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801C4EBC: bne         $v0, $zero, L_801C4ECC
    if (ctx->r2 != 0) {
        // 0x801C4EC0: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_801C4ECC;
    }
    // 0x801C4EC0: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x801C4EC4: b           L_801C4ED0
    // 0x801C4EC8: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
        goto L_801C4ED0;
    // 0x801C4EC8: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_801C4ECC:
    // 0x801C4ECC: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_801C4ED0:
    // 0x801C4ED0: jal         0x801C1340
    // 0x801C4ED4: nop

    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_1;
    // 0x801C4ED4: nop

    after_1:
    // 0x801C4ED8: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x801C4EDC: beq         $t9, $zero, L_801C4F08
    if (ctx->r25 == 0) {
        // 0x801C4EE0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801C4F08;
    }
    // 0x801C4EE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C4EE4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C4EE8: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C4EEC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801C4EF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C4EF4: bne         $v0, $at, L_801C4F04
    if (ctx->r2 != ctx->r1) {
        // 0x801C4EF8: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_801C4F04;
    }
    // 0x801C4EF8: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x801C4EFC: b           L_801C4F08
    // 0x801C4F00: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801C4F08;
    // 0x801C4F00: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_801C4F04:
    // 0x801C4F04: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
L_801C4F08:
    // 0x801C4F08: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C4F0C: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C4F10: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x801C4F14: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4F18: addiu       $a3, $a3, -0x1088
    ctx->r7 = ADD32(ctx->r7, -0X1088);
    // 0x801C4F1C: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C4F20: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C4F24: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C4F28: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C4F2C: addiu       $a2, $a2, 0x8A
    ctx->r6 = ADD32(ctx->r6, 0X8A);
    // 0x801C4F30: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C4F34: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C4F38: jal         0x8001B204
    // 0x801C4F3C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C4F3C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    after_2:
    // 0x801C4F40: jal         0x801C1334
    // 0x801C4F44: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_3;
    // 0x801C4F44: nop

    after_3:
    // 0x801C4F48: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x801C4F4C: beq         $t1, $zero, L_801C4F60
    if (ctx->r9 == 0) {
        // 0x801C4F50: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801C4F60;
    }
    // 0x801C4F50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C4F54: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4F58: jal         0x800058DC
    // 0x801C4F5C: addiu       $a1, $a1, 0x3940
    ctx->r5 = ADD32(ctx->r5, 0X3940);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C4F5C: addiu       $a1, $a1, 0x3940
    ctx->r5 = ADD32(ctx->r5, 0X3940);
    after_4:
L_801C4F60:
    // 0x801C4F60: jal         0x801C1334
    // 0x801C4F64: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_5;
    // 0x801C4F64: nop

    after_5:
    // 0x801C4F68: andi        $t2, $v0, 0xB000
    ctx->r10 = ctx->r2 & 0XB000;
    // 0x801C4F6C: beq         $t2, $zero, L_801C50F8
    if (ctx->r10 == 0) {
        // 0x801C4F70: lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
            goto L_801C50F8;
    }
    // 0x801C4F70: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C4F74: lbu         $v0, -0x3738($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3738);
    // 0x801C4F78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C4F7C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4F80: beq         $v0, $zero, L_801C4FB4
    if (ctx->r2 == 0) {
        // 0x801C4F84: addiu       $a2, $zero, 0x8A
        ctx->r6 = ADD32(0, 0X8A);
            goto L_801C4FB4;
    }
    // 0x801C4F84: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    // 0x801C4F88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C4F8C: beq         $v0, $at, L_801C5018
    if (ctx->r2 == ctx->r1) {
        // 0x801C4F90: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801C5018;
    }
    // 0x801C4F90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C4F94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C4F98: beq         $v0, $at, L_801C5084
    if (ctx->r2 == ctx->r1) {
        // 0x801C4F9C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_801C5084;
    }
    // 0x801C4F9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C4FA0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C4FA4: beq         $v0, $at, L_801C50EC
    if (ctx->r2 == ctx->r1) {
        // 0x801C4FA8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801C50EC;
    }
    // 0x801C4FA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C4FAC: b           L_801C50FC
    // 0x801C4FB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C50FC;
    // 0x801C4FB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C4FB4:
    // 0x801C4FB4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4FB8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801C4FBC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801C4FC0: jal         0x8001B204
    // 0x801C4FC4: addiu       $a3, $a3, -0x107C
    ctx->r7 = ADD32(ctx->r7, -0X107C);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801C4FC4: addiu       $a3, $a3, -0x107C
    ctx->r7 = ADD32(ctx->r7, -0X107C);
    after_6:
    // 0x801C4FC8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4FCC: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x801C4FD0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C4FD4: addiu       $a3, $a3, -0x1070
    ctx->r7 = ADD32(ctx->r7, -0X1070);
    // 0x801C4FD8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C4FDC: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C4FE0: jal         0x8001B204
    // 0x801C4FE4: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x801C4FE4: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_7:
    // 0x801C4FE8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C4FEC: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x801C4FF0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801C4FF4: addiu       $a3, $a3, -0x1064
    ctx->r7 = ADD32(ctx->r7, -0X1064);
    // 0x801C4FF8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C4FFC: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C5000: jal         0x8001B204
    // 0x801C5004: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x801C5004: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_8:
    // 0x801C5008: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801C500C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C5010: b           L_801C50F8
    // 0x801C5014: sb          $t6, -0x43F3($at)
    MEM_B(-0X43F3, ctx->r1) = ctx->r14;
        goto L_801C50F8;
    // 0x801C5014: sb          $t6, -0x43F3($at)
    MEM_B(-0X43F3, ctx->r1) = ctx->r14;
L_801C5018:
    // 0x801C5018: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C501C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x801C5020: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C5024: addiu       $a3, $a3, -0x1058
    ctx->r7 = ADD32(ctx->r7, -0X1058);
    // 0x801C5028: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C502C: jal         0x8001B204
    // 0x801C5030: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x801C5030: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_9:
    // 0x801C5034: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5038: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801C503C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C5040: addiu       $a3, $a3, -0x104C
    ctx->r7 = ADD32(ctx->r7, -0X104C);
    // 0x801C5044: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C5048: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C504C: jal         0x8001B204
    // 0x801C5050: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x801C5050: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_10:
    // 0x801C5054: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5058: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x801C505C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C5060: addiu       $a3, $a3, -0x1040
    ctx->r7 = ADD32(ctx->r7, -0X1040);
    // 0x801C5064: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C5068: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C506C: jal         0x8001B204
    // 0x801C5070: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x801C5070: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_11:
    // 0x801C5074: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C5078: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C507C: b           L_801C50F8
    // 0x801C5080: sb          $t0, -0x43F3($at)
    MEM_B(-0X43F3, ctx->r1) = ctx->r8;
        goto L_801C50F8;
    // 0x801C5080: sb          $t0, -0x43F3($at)
    MEM_B(-0X43F3, ctx->r1) = ctx->r8;
L_801C5084:
    // 0x801C5084: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5088: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x801C508C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C5090: addiu       $a3, $a3, -0x1034
    ctx->r7 = ADD32(ctx->r7, -0X1034);
    // 0x801C5094: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C5098: jal         0x8001B204
    // 0x801C509C: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x801C509C: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_12:
    // 0x801C50A0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C50A4: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x801C50A8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C50AC: addiu       $a3, $a3, -0x1028
    ctx->r7 = ADD32(ctx->r7, -0X1028);
    // 0x801C50B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C50B4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C50B8: jal         0x8001B204
    // 0x801C50BC: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_13;
    // 0x801C50BC: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_13:
    // 0x801C50C0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C50C4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801C50C8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801C50CC: addiu       $a3, $a3, -0x101C
    ctx->r7 = ADD32(ctx->r7, -0X101C);
    // 0x801C50D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C50D4: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C50D8: jal         0x8001B204
    // 0x801C50DC: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_14;
    // 0x801C50DC: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_14:
    // 0x801C50E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801C50E4: b           L_801C50F8
    // 0x801C50E8: sb          $zero, -0x43F3($at)
    MEM_B(-0X43F3, ctx->r1) = 0;
        goto L_801C50F8;
    // 0x801C50E8: sb          $zero, -0x43F3($at)
    MEM_B(-0X43F3, ctx->r1) = 0;
L_801C50EC:
    // 0x801C50EC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C50F0: jal         0x800058DC
    // 0x801C50F4: addiu       $a1, $a1, 0x3940
    ctx->r5 = ADD32(ctx->r5, 0X3940);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_15;
    // 0x801C50F4: addiu       $a1, $a1, 0x3940
    ctx->r5 = ADD32(ctx->r5, 0X3940);
    after_15:
L_801C50F8:
    // 0x801C50F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C50FC:
    // 0x801C50FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C5100: jr          $ra
    // 0x801C5104: nop

    return;
    // 0x801C5104: nop

;}
RECOMP_FUNC void M23_FUN_801c5108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5108: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C510C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C5110: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C5114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C5118: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C511C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C5120: jal         0x801302CC
    // 0x801C5124: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_0;
    // 0x801C5124: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    after_0:
    // 0x801C5128: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C512C: beq         $v0, $zero, L_801C5140
    if (ctx->r2 == 0) {
        // 0x801C5130: addiu       $v1, $v1, -0x3738
        ctx->r3 = ADD32(ctx->r3, -0X3738);
            goto L_801C5140;
    }
    // 0x801C5130: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C5134: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C5138: b           L_801C5164
    // 0x801C513C: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
        goto L_801C5164;
    // 0x801C513C: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_801C5140:
    // 0x801C5140: jal         0x80130290
    // 0x801C5144: nop

    LOOKUP_FUNC(0x80130290)(rdram, ctx);
        goto after_1;
    // 0x801C5144: nop

    after_1:
    // 0x801C5148: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C514C: beq         $v0, $zero, L_801C515C
    if (ctx->r2 == 0) {
        // 0x801C5150: addiu       $v1, $v1, -0x3738
        ctx->r3 = ADD32(ctx->r3, -0X3738);
            goto L_801C515C;
    }
    // 0x801C5150: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C5154: b           L_801C5164
    // 0x801C5158: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801C5164;
    // 0x801C5158: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_801C515C:
    // 0x801C515C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801C5160: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_801C5164:
    // 0x801C5164: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x801C5168: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C516C: addiu       $a3, $a3, -0x1010
    ctx->r7 = ADD32(ctx->r7, -0X1010);
    // 0x801C5170: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C5174: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C5178: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C517C: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C5180: addiu       $a2, $a2, 0x8A
    ctx->r6 = ADD32(ctx->r6, 0X8A);
    // 0x801C5184: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C5188: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C518C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C5190: jal         0x8001B204
    // 0x801C5194: addiu       $a1, $zero, 0x6B
    ctx->r5 = ADD32(0, 0X6B);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C5194: addiu       $a1, $zero, 0x6B
    ctx->r5 = ADD32(0, 0X6B);
    after_2:
    // 0x801C5198: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C519C: addiu       $a3, $a3, -0x100C
    ctx->r7 = ADD32(ctx->r7, -0X100C);
    // 0x801C51A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C51A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C51A8: jal         0x8001B204
    // 0x801C51AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C51AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x801C51B0: jal         0x80001060
    // 0x801C51B4: nop

    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_4;
    // 0x801C51B4: nop

    after_4:
    // 0x801C51B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C51BC: jal         0x801302CC
    // 0x801C51C0: sh          $v0, -0x2F2($at)
    MEM_H(-0X2F2, ctx->r1) = ctx->r2;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_5;
    // 0x801C51C0: sh          $v0, -0x2F2($at)
    MEM_H(-0X2F2, ctx->r1) = ctx->r2;
    after_5:
    // 0x801C51C4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C51C8: beq         $v0, $zero, L_801C51D8
    if (ctx->r2 == 0) {
        // 0x801C51CC: addiu       $v1, $v1, -0x2F2
        ctx->r3 = ADD32(ctx->r3, -0X2F2);
            goto L_801C51D8;
    }
    // 0x801C51CC: addiu       $v1, $v1, -0x2F2
    ctx->r3 = ADD32(ctx->r3, -0X2F2);
    // 0x801C51D0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801C51D4: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
L_801C51D8:
    // 0x801C51D8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x801C51DC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C51E0: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C51E4: beq         $v0, $zero, L_801C520C
    if (ctx->r2 == 0) {
        // 0x801C51E8: addiu       $a2, $zero, 0x8A
        ctx->r6 = ADD32(0, 0X8A);
            goto L_801C520C;
    }
    // 0x801C51E8: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    // 0x801C51EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C51F0: beq         $v0, $at, L_801C5268
    if (ctx->r2 == ctx->r1) {
        // 0x801C51F4: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801C5268;
    }
    // 0x801C51F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C51F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C51FC: beq         $v0, $at, L_801C52CC
    if (ctx->r2 == ctx->r1) {
        // 0x801C5200: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801C52CC;
    }
    // 0x801C5200: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C5204: b           L_801C5328
    // 0x801C5208: nop

        goto L_801C5328;
    // 0x801C5208: nop

L_801C520C:
    // 0x801C520C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5210: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x801C5214: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C5218: jal         0x8001B204
    // 0x801C521C: addiu       $a3, $a3, -0x1008
    ctx->r7 = ADD32(ctx->r7, -0X1008);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801C521C: addiu       $a3, $a3, -0x1008
    ctx->r7 = ADD32(ctx->r7, -0X1008);
    after_6:
    // 0x801C5220: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5224: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x801C5228: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C522C: addiu       $a3, $a3, -0xFF8
    ctx->r7 = ADD32(ctx->r7, -0XFF8);
    // 0x801C5230: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C5234: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C5238: jal         0x8001B204
    // 0x801C523C: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x801C523C: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_7:
    // 0x801C5240: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5244: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801C5248: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C524C: addiu       $a3, $a3, -0xFE4
    ctx->r7 = ADD32(ctx->r7, -0XFE4);
    // 0x801C5250: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C5254: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C5258: jal         0x8001B204
    // 0x801C525C: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x801C525C: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_8:
    // 0x801C5260: b           L_801C5328
    // 0x801C5264: nop

        goto L_801C5328;
    // 0x801C5264: nop

L_801C5268:
    // 0x801C5268: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C526C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801C5270: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C5274: addiu       $a3, $a3, -0xFDC
    ctx->r7 = ADD32(ctx->r7, -0XFDC);
    // 0x801C5278: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C527C: jal         0x8001B204
    // 0x801C5280: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x801C5280: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_9:
    // 0x801C5284: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5288: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x801C528C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801C5290: addiu       $a3, $a3, -0xFCC
    ctx->r7 = ADD32(ctx->r7, -0XFCC);
    // 0x801C5294: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C5298: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C529C: jal         0x8001B204
    // 0x801C52A0: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x801C52A0: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_10:
    // 0x801C52A4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C52A8: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x801C52AC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C52B0: addiu       $a3, $a3, -0xFB8
    ctx->r7 = ADD32(ctx->r7, -0XFB8);
    // 0x801C52B4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C52B8: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C52BC: jal         0x8001B204
    // 0x801C52C0: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x801C52C0: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_11:
    // 0x801C52C4: b           L_801C5328
    // 0x801C52C8: nop

        goto L_801C5328;
    // 0x801C52C8: nop

L_801C52CC:
    // 0x801C52CC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C52D0: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x801C52D4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801C52D8: addiu       $a3, $a3, -0xFB0
    ctx->r7 = ADD32(ctx->r7, -0XFB0);
    // 0x801C52DC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C52E0: jal         0x8001B204
    // 0x801C52E4: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x801C52E4: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_12:
    // 0x801C52E8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C52EC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801C52F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C52F4: addiu       $a3, $a3, -0xFA0
    ctx->r7 = ADD32(ctx->r7, -0XFA0);
    // 0x801C52F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C52FC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C5300: jal         0x8001B204
    // 0x801C5304: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_13;
    // 0x801C5304: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_13:
    // 0x801C5308: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C530C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x801C5310: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C5314: addiu       $a3, $a3, -0xF8C
    ctx->r7 = ADD32(ctx->r7, -0XF8C);
    // 0x801C5318: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C531C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C5320: jal         0x8001B204
    // 0x801C5324: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_14;
    // 0x801C5324: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_14:
L_801C5328:
    // 0x801C5328: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C532C: addiu       $a3, $a3, -0xF84
    ctx->r7 = ADD32(ctx->r7, -0XF84);
    // 0x801C5330: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C5334: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C5338: jal         0x8001B204
    // 0x801C533C: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_15;
    // 0x801C533C: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    after_15:
    // 0x801C5340: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5344: addiu       $a3, $a3, -0xF7C
    ctx->r7 = ADD32(ctx->r7, -0XF7C);
    // 0x801C5348: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801C534C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C5350: jal         0x8001B204
    // 0x801C5354: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_16;
    // 0x801C5354: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x801C5358: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C535C: addiu       $a1, $a1, 0x5378
    ctx->r5 = ADD32(ctx->r5, 0X5378);
    // 0x801C5360: jal         0x800058DC
    // 0x801C5364: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_17;
    // 0x801C5364: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_17:
    // 0x801C5368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C536C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C5370: jr          $ra
    // 0x801C5374: nop

    return;
    // 0x801C5374: nop

;}
RECOMP_FUNC void M23_FUN_801c5378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5378: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C537C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C5380: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C5384: jal         0x801C1340
    // 0x801C5388: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_0;
    // 0x801C5388: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C538C: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x801C5390: beq         $t6, $zero, L_801C53B8
    if (ctx->r14 == 0) {
        // 0x801C5394: lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
            goto L_801C53B8;
    }
    // 0x801C5394: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C5398: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C539C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801C53A0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801C53A4: bne         $v0, $zero, L_801C53B4
    if (ctx->r2 != 0) {
        // 0x801C53A8: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_801C53B4;
    }
    // 0x801C53A8: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x801C53AC: b           L_801C53B8
    // 0x801C53B0: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
        goto L_801C53B8;
    // 0x801C53B0: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_801C53B4:
    // 0x801C53B4: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_801C53B8:
    // 0x801C53B8: jal         0x801C1340
    // 0x801C53BC: nop

    LOOKUP_FUNC(0x801C1340)(rdram, ctx);
        goto after_1;
    // 0x801C53BC: nop

    after_1:
    // 0x801C53C0: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x801C53C4: beq         $t9, $zero, L_801C53F0
    if (ctx->r25 == 0) {
        // 0x801C53C8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801C53F0;
    }
    // 0x801C53C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C53CC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C53D0: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C53D4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801C53D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C53DC: bne         $v0, $at, L_801C53EC
    if (ctx->r2 != ctx->r1) {
        // 0x801C53E0: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_801C53EC;
    }
    // 0x801C53E0: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x801C53E4: b           L_801C53F0
    // 0x801C53E8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_801C53F0;
    // 0x801C53E8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_801C53EC:
    // 0x801C53EC: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
L_801C53F0:
    // 0x801C53F0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C53F4: addiu       $v1, $v1, -0x3738
    ctx->r3 = ADD32(ctx->r3, -0X3738);
    // 0x801C53F8: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x801C53FC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5400: addiu       $a3, $a3, -0xF78
    ctx->r7 = ADD32(ctx->r7, -0XF78);
    // 0x801C5404: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C5408: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C540C: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C5410: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C5414: addiu       $a2, $a2, 0x8A
    ctx->r6 = ADD32(ctx->r6, 0X8A);
    // 0x801C5418: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C541C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C5420: jal         0x8001B204
    // 0x801C5424: addiu       $a1, $zero, 0x6B
    ctx->r5 = ADD32(0, 0X6B);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C5424: addiu       $a1, $zero, 0x6B
    ctx->r5 = ADD32(0, 0X6B);
    after_2:
    // 0x801C5428: jal         0x801C1334
    // 0x801C542C: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_3;
    // 0x801C542C: nop

    after_3:
    // 0x801C5430: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x801C5434: beq         $t1, $zero, L_801C5448
    if (ctx->r9 == 0) {
        // 0x801C5438: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801C5448;
    }
    // 0x801C5438: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801C543C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C5440: jal         0x800058DC
    // 0x801C5444: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C5444: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    after_4:
L_801C5448:
    // 0x801C5448: jal         0x801C1334
    // 0x801C544C: nop

    LOOKUP_FUNC(0x801C1334)(rdram, ctx);
        goto after_5;
    // 0x801C544C: nop

    after_5:
    // 0x801C5450: andi        $t2, $v0, 0xB000
    ctx->r10 = ctx->r2 & 0XB000;
    // 0x801C5454: beq         $t2, $zero, L_801C569C
    if (ctx->r10 == 0) {
        // 0x801C5458: lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
            goto L_801C569C;
    }
    // 0x801C5458: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C545C: lbu         $v0, -0x3738($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3738);
    // 0x801C5460: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C5464: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C5468: beq         $v0, $zero, L_801C549C
    if (ctx->r2 == 0) {
        // 0x801C546C: addiu       $a2, $zero, 0x8A
        ctx->r6 = ADD32(0, 0X8A);
            goto L_801C549C;
    }
    // 0x801C546C: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    // 0x801C5470: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801C5474: beq         $v0, $v1, L_801C5500
    if (ctx->r2 == ctx->r3) {
        // 0x801C5478: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801C5500;
    }
    // 0x801C5478: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C547C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C5480: beq         $v0, $at, L_801C556C
    if (ctx->r2 == ctx->r1) {
        // 0x801C5484: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801C556C;
    }
    // 0x801C5484: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C5488: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C548C: beq         $v0, $at, L_801C55D4
    if (ctx->r2 == ctx->r1) {
        // 0x801C5490: nop
    
            goto L_801C55D4;
    }
    // 0x801C5490: nop

    // 0x801C5494: b           L_801C56A0
    // 0x801C5498: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C56A0;
    // 0x801C5498: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C549C:
    // 0x801C549C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C54A0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801C54A4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801C54A8: jal         0x8001B204
    // 0x801C54AC: addiu       $a3, $a3, -0xF74
    ctx->r7 = ADD32(ctx->r7, -0XF74);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801C54AC: addiu       $a3, $a3, -0xF74
    ctx->r7 = ADD32(ctx->r7, -0XF74);
    after_6:
    // 0x801C54B0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C54B4: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x801C54B8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C54BC: addiu       $a3, $a3, -0xF64
    ctx->r7 = ADD32(ctx->r7, -0XF64);
    // 0x801C54C0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C54C4: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C54C8: jal         0x8001B204
    // 0x801C54CC: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_7;
    // 0x801C54CC: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_7:
    // 0x801C54D0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C54D4: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x801C54D8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801C54DC: addiu       $a3, $a3, -0xF50
    ctx->r7 = ADD32(ctx->r7, -0XF50);
    // 0x801C54E0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C54E4: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C54E8: jal         0x8001B204
    // 0x801C54EC: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x801C54EC: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_8:
    // 0x801C54F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C54F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C54F8: b           L_801C569C
    // 0x801C54FC: sh          $t6, -0x2F2($at)
    MEM_H(-0X2F2, ctx->r1) = ctx->r14;
        goto L_801C569C;
    // 0x801C54FC: sh          $t6, -0x2F2($at)
    MEM_H(-0X2F2, ctx->r1) = ctx->r14;
L_801C5500:
    // 0x801C5500: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5504: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x801C5508: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C550C: addiu       $a3, $a3, -0xF48
    ctx->r7 = ADD32(ctx->r7, -0XF48);
    // 0x801C5510: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C5514: jal         0x8001B204
    // 0x801C5518: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x801C5518: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_9:
    // 0x801C551C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5520: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801C5524: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C5528: addiu       $a3, $a3, -0xF38
    ctx->r7 = ADD32(ctx->r7, -0XF38);
    // 0x801C552C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C5530: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C5534: jal         0x8001B204
    // 0x801C5538: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x801C5538: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_10:
    // 0x801C553C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5540: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x801C5544: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C5548: addiu       $a3, $a3, -0xF24
    ctx->r7 = ADD32(ctx->r7, -0XF24);
    // 0x801C554C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C5550: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C5554: jal         0x8001B204
    // 0x801C5558: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_11;
    // 0x801C5558: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_11:
    // 0x801C555C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801C5560: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C5564: b           L_801C569C
    // 0x801C5568: sh          $t0, -0x2F2($at)
    MEM_H(-0X2F2, ctx->r1) = ctx->r8;
        goto L_801C569C;
    // 0x801C5568: sh          $t0, -0x2F2($at)
    MEM_H(-0X2F2, ctx->r1) = ctx->r8;
L_801C556C:
    // 0x801C556C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5570: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x801C5574: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C5578: addiu       $a3, $a3, -0xF1C
    ctx->r7 = ADD32(ctx->r7, -0XF1C);
    // 0x801C557C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C5580: jal         0x8001B204
    // 0x801C5584: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x801C5584: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_12:
    // 0x801C5588: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C558C: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x801C5590: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C5594: addiu       $a3, $a3, -0xF0C
    ctx->r7 = ADD32(ctx->r7, -0XF0C);
    // 0x801C5598: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C559C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C55A0: jal         0x8001B204
    // 0x801C55A4: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_13;
    // 0x801C55A4: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_13:
    // 0x801C55A8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C55AC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801C55B0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801C55B4: addiu       $a3, $a3, -0xEF8
    ctx->r7 = ADD32(ctx->r7, -0XEF8);
    // 0x801C55B8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C55BC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C55C0: jal         0x8001B204
    // 0x801C55C4: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_14;
    // 0x801C55C4: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_14:
    // 0x801C55C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C55CC: b           L_801C569C
    // 0x801C55D0: sh          $zero, -0x2F2($at)
    MEM_H(-0X2F2, ctx->r1) = 0;
        goto L_801C569C;
    // 0x801C55D0: sh          $zero, -0x2F2($at)
    MEM_H(-0X2F2, ctx->r1) = 0;
L_801C55D4:
    // 0x801C55D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C55D8: lhu         $v0, -0x2F2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2F2);
    // 0x801C55DC: bnel        $v1, $v0, L_801C55FC
    if (ctx->r3 != ctx->r2) {
        // 0x801C55E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801C55FC;
    }
    goto skip_0;
    // 0x801C55E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x801C55E4: jal         0x80130290
    // 0x801C55E8: nop

    LOOKUP_FUNC(0x80130290)(rdram, ctx);
        goto after_15;
    // 0x801C55E8: nop

    after_15:
    // 0x801C55EC: bne         $v0, $zero, L_801C562C
    if (ctx->r2 != 0) {
        // 0x801C55F0: lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
            goto L_801C562C;
    }
    // 0x801C55F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C55F4: lhu         $v0, -0x2F2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2F2);
    // 0x801C55F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_801C55FC:
    // 0x801C55FC: bne         $v0, $at, L_801C5618
    if (ctx->r2 != ctx->r1) {
        // 0x801C5600: nop
    
            goto L_801C5618;
    }
    // 0x801C5600: nop

    // 0x801C5604: jal         0x801302CC
    // 0x801C5608: nop

    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_16;
    // 0x801C5608: nop

    after_16:
    // 0x801C560C: bne         $v0, $zero, L_801C562C
    if (ctx->r2 != 0) {
        // 0x801C5610: lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
            goto L_801C562C;
    }
    // 0x801C5610: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C5614: lhu         $v0, -0x2F2($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2F2);
L_801C5618:
    // 0x801C5618: bne         $v0, $zero, L_801C5644
    if (ctx->r2 != 0) {
        // 0x801C561C: nop
    
            goto L_801C5644;
    }
    // 0x801C561C: nop

    // 0x801C5620: jal         0x80130264
    // 0x801C5624: nop

    LOOKUP_FUNC(0x80130264)(rdram, ctx);
        goto after_17;
    // 0x801C5624: nop

    after_17:
    // 0x801C5628: bne         $v0, $zero, L_801C5644
    if (ctx->r2 != 0) {
        // 0x801C562C: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_801C5644;
    }
L_801C562C:
    // 0x801C562C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C5630: addiu       $a1, $a1, 0x56B8
    ctx->r5 = ADD32(ctx->r5, 0X56B8);
    // 0x801C5634: jal         0x800058DC
    // 0x801C5638: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_18;
    // 0x801C5638: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_18:
    // 0x801C563C: b           L_801C56A0
    // 0x801C5640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801C56A0;
    // 0x801C5640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C5644:
    // 0x801C5644: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801C5648: lhu         $t4, -0x2F2($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X2F2);
    // 0x801C564C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C5650: bne         $t4, $at, L_801C5670
    if (ctx->r12 != ctx->r1) {
        // 0x801C5654: nop
    
            goto L_801C5670;
    }
    // 0x801C5654: nop

    // 0x801C5658: jal         0x80130254
    // 0x801C565C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80130254)(rdram, ctx);
        goto after_19;
    // 0x801C565C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x801C5660: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801C5664: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C5668: b           L_801C5678
    // 0x801C566C: sh          $t5, -0x2F2($at)
    MEM_H(-0X2F2, ctx->r1) = ctx->r13;
        goto L_801C5678;
    // 0x801C566C: sh          $t5, -0x2F2($at)
    MEM_H(-0X2F2, ctx->r1) = ctx->r13;
L_801C5670:
    // 0x801C5670: jal         0x80130254
    // 0x801C5674: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80130254)(rdram, ctx);
        goto after_20;
    // 0x801C5674: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
L_801C5678:
    // 0x801C5678: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C567C: lhu         $t6, -0x2F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2F2);
    // 0x801C5680: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x801C5684: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C5688: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801C568C: sh          $t7, 0x7750($at)
    MEM_H(0X7750, ctx->r1) = ctx->r15;
    // 0x801C5690: addiu       $a1, $a1, 0x56AC
    ctx->r5 = ADD32(ctx->r5, 0X56AC);
    // 0x801C5694: jal         0x800058DC
    // 0x801C5698: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_21;
    // 0x801C5698: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_21:
L_801C569C:
    // 0x801C569C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C56A0:
    // 0x801C56A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C56A4: jr          $ra
    // 0x801C56A8: nop

    return;
    // 0x801C56A8: nop

;}
RECOMP_FUNC void M23_FUN_801c56ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C56AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C56B0: jr          $ra
    // 0x801C56B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C56B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c56b8(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c56b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C56B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C56BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C56C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801C56C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C56C8: addiu       $t6, $zero, 0x384
    ctx->r14 = ADD32(0, 0X384);
    // 0x801C56CC: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x801C56D0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801C56D4: lbu         $a2, -0x373C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X373C);
    // 0x801C56D8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C56DC: addiu       $a3, $a3, -0xEF0
    ctx->r7 = ADD32(ctx->r7, -0XEF0);
    // 0x801C56E0: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x801C56E4: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x801C56E8: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x801C56EC: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x801C56F0: addiu       $a2, $a2, 0x76
    ctx->r6 = ADD32(ctx->r6, 0X76);
    // 0x801C56F4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801C56F8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801C56FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C5700: jal         0x8001B204
    // 0x801C5704: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C5704: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    after_0:
    // 0x801C5708: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C570C: addiu       $a3, $a3, -0xEE0
    ctx->r7 = ADD32(ctx->r7, -0XEE0);
    // 0x801C5710: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C5714: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C5718: jal         0x8001B204
    // 0x801C571C: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C571C: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    after_1:
    // 0x801C5720: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5724: addiu       $a3, $a3, -0xED0
    ctx->r7 = ADD32(ctx->r7, -0XED0);
    // 0x801C5728: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C572C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C5730: jal         0x8001B204
    // 0x801C5734: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801C5734: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_2:
    // 0x801C5738: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C573C: addiu       $a3, $a3, -0xEC0
    ctx->r7 = ADD32(ctx->r7, -0XEC0);
    // 0x801C5740: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801C5744: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C5748: jal         0x8001B204
    // 0x801C574C: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x801C574C: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_3:
    // 0x801C5750: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5754: addiu       $a3, $a3, -0xEB0
    ctx->r7 = ADD32(ctx->r7, -0XEB0);
    // 0x801C5758: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801C575C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C5760: jal         0x8001B204
    // 0x801C5764: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801C5764: addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    after_4:
    // 0x801C5768: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x801C576C: lhu         $t8, 0x7754($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X7754);
    // 0x801C5770: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C5774: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C5778: bne         $t8, $at, L_801C57A0
    if (ctx->r24 != ctx->r1) {
        // 0x801C577C: addiu       $a1, $zero, 0x7D0
        ctx->r5 = ADD32(0, 0X7D0);
            goto L_801C57A0;
    }
    // 0x801C577C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C5780: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5784: addiu       $a3, $a3, -0xEA0
    ctx->r7 = ADD32(ctx->r7, -0XEA0);
    // 0x801C5788: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801C578C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C5790: jal         0x8001B204
    // 0x801C5794: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x801C5794: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_5:
    // 0x801C5798: b           L_801C57B8
    // 0x801C579C: nop

        goto L_801C57B8;
    // 0x801C579C: nop

L_801C57A0:
    // 0x801C57A0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C57A4: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x801C57A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C57AC: addiu       $a3, $a3, -0xE90
    ctx->r7 = ADD32(ctx->r7, -0XE90);
    // 0x801C57B0: jal         0x8001B204
    // 0x801C57B4: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801C57B4: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    after_6:
L_801C57B8:
    // 0x801C57B8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C57BC: addiu       $a1, $a1, 0x1DB8
    ctx->r5 = ADD32(ctx->r5, 0X1DB8);
    // 0x801C57C0: jal         0x800058DC
    // 0x801C57C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C57C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x801C57C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C57CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C57D0: jr          $ra
    // 0x801C57D4: nop

    return;
    // 0x801C57D4: nop

;}
RECOMP_FUNC void M23_FUN_801c57d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C57D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C57DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C57E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C57E4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x801C57E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C57EC: jal         0x80005670
    // 0x801C57F0: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C57F0: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    after_0:
    // 0x801C57F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C57F8: sw          $v0, -0x3744($at)
    MEM_W(-0X3744, ctx->r1) = ctx->r2;
    // 0x801C57FC: jal         0x801C11BC
    // 0x801C5800: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801C11BC)(rdram, ctx);
        goto after_1;
    // 0x801C5800: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_1:
    // 0x801C5804: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C5808: addiu       $a1, $a1, 0x5824
    ctx->r5 = ADD32(ctx->r5, 0X5824);
    // 0x801C580C: jal         0x800058DC
    // 0x801C5810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C5810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801C5814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C5818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C581C: jr          $ra
    // 0x801C5820: nop

    return;
    // 0x801C5820: nop

;}
RECOMP_FUNC void M23_FUN_801c5824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5824: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C5828: lbu         $t6, -0x3734($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3734);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c582c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c582c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C582C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801C5830: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C5834: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801C5838: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801C583C: bne         $t6, $at, L_801C5900
    if (ctx->r14 != ctx->r1) {
        // 0x801C5840: sw          $a1, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r5;
            goto L_801C5900;
    }
    // 0x801C5840: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801C5844: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801C5848: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C584C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801C5850: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C5854: lui         $at, 0xC1B0
    ctx->r1 = S32(0XC1B0 << 16);
    // 0x801C5858: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C585C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C5860: lui         $at, 0x422A
    ctx->r1 = S32(0X422A << 16);
    // 0x801C5864: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C5868: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801C586C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C5870: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801C5874: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C5878: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801C587C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C5880: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801C5884: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801C5888: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C588C: addiu       $a0, $a0, -0xE70
    ctx->r4 = ADD32(ctx->r4, -0XE70);
    // 0x801C5890: addiu       $a1, $zero, 0x833
    ctx->r5 = ADD32(0, 0X833);
    // 0x801C5894: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x801C5898: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C589C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801C58A0: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801C58A4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801C58A8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801C58AC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801C58B0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801C58B4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801C58B8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801C58BC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801C58C0: jal         0x8011AAF4
    // 0x801C58C4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x801C58C4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801C58C8: jal         0x8013EF54
    // 0x801C58CC: nop

    LOOKUP_FUNC(0x8013EF54)(rdram, ctx);
        goto after_1;
    // 0x801C58CC: nop

    after_1:
    // 0x801C58D0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C58D4: addiu       $a1, $a1, -0x3608
    ctx->r5 = ADD32(ctx->r5, -0X3608);
    // 0x801C58D8: jal         0x80005670
    // 0x801C58DC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x801C58DC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x801C58E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C58E4: sw          $v0, -0x374C($at)
    MEM_W(-0X374C, ctx->r1) = ctx->r2;
    // 0x801C58E8: jal         0x801C125C
    // 0x801C58EC: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    LOOKUP_FUNC(0x801C125C)(rdram, ctx);
        goto after_3;
    // 0x801C58EC: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    after_3:
    // 0x801C58F0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C58F4: addiu       $a1, $a1, 0x5910
    ctx->r5 = ADD32(ctx->r5, 0X5910);
    // 0x801C58F8: jal         0x800058DC
    // 0x801C58FC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C58FC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_4:
L_801C5900:
    // 0x801C5900: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801C5904: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801C5908: jr          $ra
    // 0x801C590C: nop

    return;
    // 0x801C590C: nop

;}
RECOMP_FUNC void M23_FUN_801c5910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5910: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C5914: lbu         $t6, -0x3734($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3734);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c5918(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c5918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C591C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C5920: bne         $t6, $zero, L_801C5934
    if (ctx->r14 != 0) {
        // 0x801C5924: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801C5934;
    }
    // 0x801C5924: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C5928: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C592C: jal         0x800058DC
    // 0x801C5930: addiu       $a1, $a1, 0x5944
    ctx->r5 = ADD32(ctx->r5, 0X5944);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C5930: addiu       $a1, $a1, 0x5944
    ctx->r5 = ADD32(ctx->r5, 0X5944);
    after_0:
L_801C5934:
    // 0x801C5934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C5938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C593C: jr          $ra
    // 0x801C5940: nop

    return;
    // 0x801C5940: nop

;}
RECOMP_FUNC void M23_FUN_801c5944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5944: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C5948: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C594C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C5950: jal         0x8013EFF0
    // 0x801C5954: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8013EFF0)(rdram, ctx);
        goto after_0;
    // 0x801C5954: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C5958: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C595C: bne         $v0, $at, L_801C599C
    if (ctx->r2 != ctx->r1) {
        // 0x801C5960: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_801C599C;
    }
    // 0x801C5960: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801C5964: jal         0x80142570
    // 0x801C5968: nop

    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_1;
    // 0x801C5968: nop

    after_1:
    // 0x801C596C: jal         0x800179B0
    // 0x801C5970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_2;
    // 0x801C5970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801C5974: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x801C5978: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x801C597C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C5980: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C5984: jal         0x8012FE50
    // 0x801C5988: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_3;
    // 0x801C5988: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x801C598C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C5990: addiu       $a1, $a1, 0x59F4
    ctx->r5 = ADD32(ctx->r5, 0X59F4);
    // 0x801C5994: jal         0x800058DC
    // 0x801C5998: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C5998: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
L_801C599C:
    // 0x801C599C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801C59A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C59A4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801C59A8: bne         $t6, $at, L_801C59E4
    if (ctx->r14 != ctx->r1) {
        // 0x801C59AC: addiu       $t7, $t7, 0x59F4
        ctx->r15 = ADD32(ctx->r15, 0X59F4);
            goto L_801C59E4;
    }
    // 0x801C59AC: addiu       $t7, $t7, 0x59F4
    ctx->r15 = ADD32(ctx->r15, 0X59F4);
    // 0x801C59B0: jal         0x80142570
    // 0x801C59B4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_5;
    // 0x801C59B4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_5:
    // 0x801C59B8: jal         0x800179B0
    // 0x801C59BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_6;
    // 0x801C59BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x801C59C0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x801C59C4: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x801C59C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801C59CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C59D0: jal         0x8012FE50
    // 0x801C59D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_7;
    // 0x801C59D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x801C59D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801C59DC: jal         0x800058DC
    // 0x801C59E0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801C59E0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_8:
L_801C59E4:
    // 0x801C59E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C59E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C59EC: jr          $ra
    // 0x801C59F0: nop

    return;
    // 0x801C59F0: nop

;}
RECOMP_FUNC void M23_FUN_801c59f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C59F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C59F8: jr          $ra
    // 0x801C59FC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801C59FC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c5a00(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c5a00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5A00: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C5A04: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C5A08: lhu         $t0, 0x178($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X178);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c5a0c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c5a0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5A0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C5A10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C5A14: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x801C5A18: bne         $at, $zero, L_801C5A28
    if (ctx->r1 != 0) {
        // 0x801C5A1C: lui         $t7, 0x801D
        ctx->r15 = S32(0X801D << 16);
            goto L_801C5A28;
    }
    // 0x801C5A1C: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C5A20: sh          $zero, 0x178($v1)
    MEM_H(0X178, ctx->r3) = 0;
    // 0x801C5A24: andi        $t0, $zero, 0xFFFF
    ctx->r8 = 0 & 0XFFFF;
L_801C5A28:
    // 0x801C5A28: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x801C5A2C: addiu       $t7, $t7, -0x3678
    ctx->r15 = ADD32(ctx->r15, -0X3678);
    // 0x801C5A30: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801C5A34: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x801C5A38: lhu         $t9, 0x6($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X6);
    // 0x801C5A3C: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x801C5A40: lbu         $a2, 0x5($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X5);
    // 0x801C5A44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801C5A48: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x801C5A4C: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    // 0x801C5A50: jal         0x8012FE50
    // 0x801C5A54: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x801C5A54: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x801C5A58: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801C5A5C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801C5A60: lhu         $t1, 0x178($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X178);
    // 0x801C5A64: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801C5A68: jal         0x80133830
    // 0x801C5A6C: sh          $t2, 0x178($v1)
    MEM_H(0X178, ctx->r3) = ctx->r10;
    LOOKUP_FUNC(0x80133830)(rdram, ctx);
        goto after_1;
    // 0x801C5A6C: sh          $t2, 0x178($v1)
    MEM_H(0X178, ctx->r3) = ctx->r10;
    after_1:
    // 0x801C5A70: jal         0x80133950
    // 0x801C5A74: nop

    LOOKUP_FUNC(0x80133950)(rdram, ctx);
        goto after_2;
    // 0x801C5A74: nop

    after_2:
    // 0x801C5A78: jal         0x80133A70
    // 0x801C5A7C: nop

    LOOKUP_FUNC(0x80133A70)(rdram, ctx);
        goto after_3;
    // 0x801C5A7C: nop

    after_3:
    // 0x801C5A80: jal         0x801C1308
    // 0x801C5A84: nop

    LOOKUP_FUNC(0x801C1308)(rdram, ctx);
        goto after_4;
    // 0x801C5A84: nop

    after_4:
    // 0x801C5A88: jal         0x80152240
    // 0x801C5A8C: nop

    LOOKUP_FUNC(0x80152240)(rdram, ctx);
        goto after_5;
    // 0x801C5A8C: nop

    after_5:
    // 0x801C5A90: jal         0x800023EC
    // 0x801C5A94: nop

    LOOKUP_FUNC(0x800023EC)(rdram, ctx);
        goto after_6;
    // 0x801C5A94: nop

    after_6:
    // 0x801C5A98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C5A9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C5AA0: jr          $ra
    // 0x801C5AA4: nop

    return;
    // 0x801C5AA4: nop

;}
RECOMP_FUNC void M23_FUN_801c5aa8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5AA8: nop

    // 0x801C5AAC: nop

;}
RECOMP_FUNC void M23_FUN_801c5ab0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5AB0: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C5AB4: lw          $t6, -0x2F34($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2F34);
    // 0x801C5AB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C5ABC: beq         $t6, $zero, L_801C5ACC
    if (ctx->r14 == 0) {
            // 0x801C5AC0: nop

    LOOKUP_FUNC(0x801C5ACC)(rdram, ctx);
    return;
    }
    // 0x801C5AC0: nop

    // 0x801C5AC4: jr          $ra
    // 0x801C5AC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C5AC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c5acc(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c5acc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5ACC: jr          $ra
    // 0x801C5AD0: nop

    return;
    // 0x801C5AD0: nop

;}
RECOMP_FUNC void M23_FUN_801c5ad4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5AD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C5AD8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801C5ADC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801C5AE0: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x801C5AE4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801C5AE8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801C5AEC: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C5AF0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801C5AF4: lw          $t7, -0x248($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X248);
    // 0x801C5AF8: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x801C5AFC: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x801C5B00: bne         $v1, $t7, L_801C5B30
    if (ctx->r3 != ctx->r15) {
            // 0x801C5B04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x801C5B30)(rdram, ctx);
    return;
    }
    // 0x801C5B04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C5B08: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C5B0C: addiu       $v1, $v1, -0x254
    ctx->r3 = ADD32(ctx->r3, -0X254);
    // 0x801C5B10: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x801C5B14: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x801C5B18: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x801C5B1C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x801C5B20: bne         $t0, $t3, L_801C5B30
    if (ctx->r8 != ctx->r11) {
            // 0x801C5B24: nop

    LOOKUP_FUNC(0x801C5B30)(rdram, ctx);
    return;
    }
    // 0x801C5B24: nop

    // 0x801C5B28: jr          $ra
    // 0x801C5B2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C5B2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c5b30(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c5b30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5B30: jr          $ra
    // 0x801C5B34: nop

    return;
    // 0x801C5B34: nop

;}
RECOMP_FUNC void M23_FUN_801c5b38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5B38: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C5B3C: addiu       $v1, $v1, -0x248
    ctx->r3 = ADD32(ctx->r3, -0X248);
    // 0x801C5B40: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801C5B44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C5B48: bnel        $v0, $t6, L_801C5B68
    if (ctx->r2 != ctx->r14) {
        // 0x801C5B4C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C5B68;
    }
    goto skip_0;
    // 0x801C5B4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801C5B50: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801C5B54: bnel        $v0, $t7, L_801C5B68
    if (ctx->r2 != ctx->r15) {
        // 0x801C5B58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C5B68;
    }
    goto skip_1;
    // 0x801C5B58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801C5B5C: jr          $ra
    // 0x801C5B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C5B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C5B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C5B68:
    // 0x801C5B68: jr          $ra
    // 0x801C5B6C: nop

    return;
    // 0x801C5B6C: nop

;}
RECOMP_FUNC void M23_FUN_801c5b70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5B70: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C5B74: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801C5B78: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801C5B7C: addiu       $t7, $t7, 0x1CF0
    ctx->r15 = ADD32(ctx->r15, 0X1CF0);
    // 0x801C5B80: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801C5B84: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801C5B88: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x801C5B8C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C5B90: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x801C5B94: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801C5B98: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x801C5B9C: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x801C5BA0: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x801C5BA4: sh          $t0, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r8;
    // 0x801C5BA8: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
    // 0x801C5BAC: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x801C5BB0: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801C5BB4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x801C5BB8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801C5BBC: jr          $ra
    // 0x801C5BC0: sw          $t6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r14;
    return;
    // 0x801C5BC0: sw          $t6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c5bc4(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c5bc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5BC4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C5BC8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801C5BCC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801C5BD0: addiu       $t7, $t7, 0x1CF0
    ctx->r15 = ADD32(ctx->r15, 0X1CF0);
    // 0x801C5BD4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801C5BD8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801C5BDC: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x801C5BE0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C5BE4: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x801C5BE8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801C5BEC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x801C5BF0: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x801C5BF4: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x801C5BF8: sh          $t0, 0x20($t1)
    MEM_H(0X20, ctx->r9) = ctx->r8;
    // 0x801C5BFC: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
    // 0x801C5C00: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x801C5C04: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801C5C08: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x801C5C0C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801C5C10: jr          $ra
    // 0x801C5C14: sw          $t6, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r14;
    return;
    // 0x801C5C14: sw          $t6, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c5c18(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c5c18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5C18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C5C1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C5C20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C5C24: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801C5C28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C5C2C: addiu       $s1, $s1, -0xD60
    ctx->r17 = ADD32(ctx->r17, -0XD60);
    // 0x801C5C30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C5C34: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_801C5C38:
    // 0x801C5C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C5C3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C5C40: jal         0x8001B204
    // 0x801C5C44: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801C5C44: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
    // 0x801C5C48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C5C4C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801C5C50: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x801C5C54: bnel        $at, $zero, L_801C5C38
    if (ctx->r1 != 0) {
        // 0x801C5C58: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_801C5C38;
    }
    goto skip_0;
    // 0x801C5C58: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    skip_0:
    // 0x801C5C5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C5C60: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C5C64: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C5C68: jr          $ra
    // 0x801C5C6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C5C6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c5c70(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c5c70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5C70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C5C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C5C78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C5C7C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C5C80: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801C5C84: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x801C5C88: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x801C5C8C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801C5C90: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x801C5C94: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x801C5C98: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x801C5C9C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801C5CA0: jal         0x801477C4
    // 0x801C5CA4: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    LOOKUP_FUNC(0x801477C4)(rdram, ctx);
        goto after_0;
    // 0x801C5CA4: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    after_0:
    // 0x801C5CA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801C5CAC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x801C5CB0: jal         0x80147734
    // 0x801C5CB4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    LOOKUP_FUNC(0x80147734)(rdram, ctx);
        goto after_1;
    // 0x801C5CB4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_1:
    // 0x801C5CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C5CBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C5CC0: jr          $ra
    // 0x801C5CC4: nop

    return;
    // 0x801C5CC4: nop

;}
RECOMP_FUNC void M23_FUN_801c5cc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5CC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C5CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C5CD0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801C5CD4: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801C5CD8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801C5CDC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C5CE0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801C5CE4: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801C5CE8: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801C5CEC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C5CF0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x801C5CF4: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801C5CF8: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x801C5CFC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801C5D00: lui         $a1, 0x42FA
    ctx->r5 = S32(0X42FA << 16);
    // 0x801C5D04: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C5D08: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x801C5D0C: jal         0x80147768
    // 0x801C5D10: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80147768)(rdram, ctx);
        goto after_0;
    // 0x801C5D10: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801C5D14: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C5D18: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801C5D1C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801C5D20: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x801C5D24: nop

    // 0x801C5D28: sb          $t8, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r24;
    // 0x801C5D2C: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C5D30: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801C5D34: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x801C5D38: nop

    // 0x801C5D3C: sb          $t0, 0x9($a2)
    MEM_B(0X9, ctx->r6) = ctx->r8;
    // 0x801C5D40: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C5D44: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C5D48: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x801C5D4C: nop

    // 0x801C5D50: sb          $t2, 0xA($a2)
    MEM_B(0XA, ctx->r6) = ctx->r10;
    // 0x801C5D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C5D58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C5D5C: jr          $ra
    // 0x801C5D60: nop

    return;
    // 0x801C5D60: nop

;}
RECOMP_FUNC void M23_FUN_801c5d64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5D64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C5D68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C5D6C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801C5D70: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801C5D74: lbu         $a2, 0x27($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X27);
    // 0x801C5D78: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C5D7C: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x801C5D80: lbu         $a3, -0x25C($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X25C);
    // 0x801C5D84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801C5D88: addiu       $a1, $zero, 0x229
    ctx->r5 = ADD32(0, 0X229);
    // 0x801C5D8C: jal         0x8012D918
    // 0x801C5D90: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    LOOKUP_FUNC(0x8012D918)(rdram, ctx);
        goto after_0;
    // 0x801C5D90: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    after_0:
    // 0x801C5D94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C5D98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C5D9C: jr          $ra
    // 0x801C5DA0: nop

    return;
    // 0x801C5DA0: nop

;}
RECOMP_FUNC void M23_FUN_801c5da4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5DA4: jr          $ra
    // 0x801C5DA8: nop

    return;
    // 0x801C5DA8: nop

;}
RECOMP_FUNC void M23_FUN_801c5dac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5DAC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801C5DB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801C5DB4: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x801C5DB8: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x801C5DBC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x801C5DC0: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x801C5DC4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x801C5DC8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x801C5DCC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801C5DD0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801C5DD4: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801C5DD8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801C5DDC: lui         $s5, 0x801D
    ctx->r21 = S32(0X801D << 16);
    // 0x801C5DE0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C5DE4: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x801C5DE8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801C5DEC: lw          $s0, -0x270($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X270);
    // 0x801C5DF0: addiu       $s5, $s5, -0x25A
    ctx->r21 = ADD32(ctx->r21, -0X25A);
    // 0x801C5DF4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C5DF8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x801C5DFC: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x801C5E00: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_801C5E04:
    // 0x801C5E04: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801C5E08:
    // 0x801C5E08: bne         $s2, $zero, L_801C5E24
    if (ctx->r18 != 0) {
        // 0x801C5E0C: nop
    
            goto L_801C5E24;
    }
    // 0x801C5E0C: nop

    // 0x801C5E10: lbu         $t8, 0x90($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X90);
    // 0x801C5E14: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x801C5E18: lb          $t0, 0x0($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X0);
    // 0x801C5E1C: beql        $s4, $t0, L_801C5E40
    if (ctx->r20 == ctx->r8) {
        // 0x801C5E20: addiu       $t4, $zero, 0xFF
        ctx->r12 = ADD32(0, 0XFF);
            goto L_801C5E40;
    }
    goto skip_0;
    // 0x801C5E20: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    skip_0:
L_801C5E24:
    // 0x801C5E24: bne         $s4, $s2, L_801C5E7C
    if (ctx->r20 != ctx->r18) {
        // 0x801C5E28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801C5E7C;
    }
    // 0x801C5E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C5E2C: lbu         $t1, 0x90($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X90);
    // 0x801C5E30: addu        $t2, $s5, $t1
    ctx->r10 = ADD32(ctx->r21, ctx->r9);
    // 0x801C5E34: lb          $t3, 0x0($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X0);
    // 0x801C5E38: bne         $s6, $t3, L_801C5E7C
    if (ctx->r22 != ctx->r11) {
        // 0x801C5E3C: addiu       $t4, $zero, 0xFF
        ctx->r12 = ADD32(0, 0XFF);
            goto L_801C5E7C;
    }
    // 0x801C5E3C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
L_801C5E40:
    // 0x801C5E40: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C5E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C5E48: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801C5E4C: addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // 0x801C5E50: jal         0x80147250
    // 0x801C5E54: addiu       $a3, $zero, 0xCF
    ctx->r7 = ADD32(0, 0XCF);
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_0;
    // 0x801C5E54: addiu       $a3, $zero, 0xCF
    ctx->r7 = ADD32(0, 0XCF);
    after_0:
    // 0x801C5E58: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801C5E5C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801C5E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C5E64: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801C5E68: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x801C5E6C: jal         0x801472C0
    // 0x801C5E70: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_1;
    // 0x801C5E70: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_1:
    // 0x801C5E74: b           L_801C5EB4
    // 0x801C5E78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_801C5EB4;
    // 0x801C5E78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801C5E7C:
    // 0x801C5E7C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801C5E80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C5E84: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x801C5E88: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x801C5E8C: jal         0x80147250
    // 0x801C5E90: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_2;
    // 0x801C5E90: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_2:
    // 0x801C5E94: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801C5E98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C5E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C5EA0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x801C5EA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C5EA8: jal         0x801472C0
    // 0x801C5EAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_3;
    // 0x801C5EAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801C5EB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801C5EB4:
    // 0x801C5EB4: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C5EB8: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x801C5EBC: bne         $at, $zero, L_801C5E08
    if (ctx->r1 != 0) {
        // 0x801C5EC0: lw          $s0, 0x10($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X10);
            goto L_801C5E08;
    }
    // 0x801C5EC0: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x801C5EC4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x801C5EC8: andi        $s7, $s7, 0xFF
    ctx->r23 = ctx->r23 & 0XFF;
    // 0x801C5ECC: slti        $at, $s7, 0x2
    ctx->r1 = SIGNED(ctx->r23) < 0X2 ? 1 : 0;
    // 0x801C5ED0: bne         $at, $zero, L_801C5E04
    if (ctx->r1 != 0) {
        // 0x801C5ED4: or          $s2, $s7, $zero
        ctx->r18 = ctx->r23 | 0;
            goto L_801C5E04;
    }
    // 0x801C5ED4: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x801C5ED8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801C5EDC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801C5EE0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801C5EE4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x801C5EE8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x801C5EEC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x801C5EF0: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x801C5EF4: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x801C5EF8: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x801C5EFC: jr          $ra
    // 0x801C5F00: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801C5F00: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c5f04(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c5f04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5F04: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801C5F08: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801C5F0C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x801C5F10: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x801C5F14: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x801C5F18: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x801C5F1C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x801C5F20: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x801C5F24: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801C5F28: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801C5F2C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801C5F30: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x801C5F34: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801C5F38: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x801C5F3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801C5F40: addu        $s1, $s1, $t7
    ctx->r17 = ADD32(ctx->r17, ctx->r15);
    // 0x801C5F44: lw          $s1, -0x278($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X278);
    // 0x801C5F48: addiu       $t8, $zero, 0x70
    ctx->r24 = ADD32(0, 0X70);
    // 0x801C5F4C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C5F50: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801C5F54: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x801C5F58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C5F5C: jal         0x80147250
    // 0x801C5F60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_0;
    // 0x801C5F60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x801C5F64: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801C5F68: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C5F6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C5F70: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801C5F74: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x801C5F78: jal         0x801472C0
    // 0x801C5F7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_1;
    // 0x801C5F7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x801C5F80: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
    // 0x801C5F84: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801C5F88: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C5F8C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x801C5F90: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x801C5F94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C5F98: jal         0x80147250
    // 0x801C5F9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_2;
    // 0x801C5F9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801C5FA0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801C5FA4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C5FA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C5FAC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x801C5FB0: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x801C5FB4: jal         0x801472C0
    // 0x801C5FB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_3;
    // 0x801C5FB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801C5FBC: lui         $s7, 0x801D
    ctx->r23 = S32(0X801D << 16);
    // 0x801C5FC0: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x801C5FC4: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
    // 0x801C5FC8: addiu       $s3, $s3, -0x2FC4
    ctx->r19 = ADD32(ctx->r19, -0X2FC4);
    // 0x801C5FCC: addiu       $s7, $s7, -0x248
    ctx->r23 = ADD32(ctx->r23, -0X248);
    // 0x801C5FD0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x801C5FD4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x801C5FD8: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x801C5FDC: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
L_801C5FE0:
    // 0x801C5FE0: lbu         $t2, 0x90($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X90);
    // 0x801C5FE4: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801C5FE8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C5FEC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801C5FF0: lb          $t3, -0x25A($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X25A);
    // 0x801C5FF4: bnel        $s2, $t3, L_801C6100
    if (ctx->r18 != ctx->r11) {
        // 0x801C5FF8: sb          $zero, 0x22($s1)
        MEM_B(0X22, ctx->r17) = 0;
            goto L_801C6100;
    }
    goto skip_0;
    // 0x801C5FF8: sb          $zero, 0x22($s1)
    MEM_B(0X22, ctx->r17) = 0;
    skip_0:
    // 0x801C5FFC: bne         $s5, $s2, L_801C605C
    if (ctx->r21 != ctx->r18) {
        // 0x801C6000: sb          $t4, 0x22($s1)
        MEM_B(0X22, ctx->r17) = ctx->r12;
            goto L_801C605C;
    }
    // 0x801C6000: sb          $t4, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r12;
    // 0x801C6004: lbu         $t5, 0x90($s6)
    ctx->r13 = MEM_BU(ctx->r22, 0X90);
    // 0x801C6008: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C600C: addiu       $t9, $zero, 0x70
    ctx->r25 = ADD32(0, 0X70);
    // 0x801C6010: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801C6014: addu        $t7, $s7, $t6
    ctx->r15 = ADD32(ctx->r23, ctx->r14);
    // 0x801C6018: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801C601C: beq         $t8, $zero, L_801C605C
    if (ctx->r24 == 0) {
        // 0x801C6020: nop
    
            goto L_801C605C;
    }
    // 0x801C6020: nop

    // 0x801C6024: lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0XF);
    // 0x801C6028: lbu         $a2, 0x10($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X10);
    // 0x801C602C: lbu         $a3, 0x11($s3)
    ctx->r7 = MEM_BU(ctx->r19, 0X11);
    // 0x801C6030: jal         0x80147250
    // 0x801C6034: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_4;
    // 0x801C6034: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_4:
    // 0x801C6038: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801C603C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801C6040: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C6044: lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0XF);
    // 0x801C6048: lbu         $a2, 0x10($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X10);
    // 0x801C604C: jal         0x801472C0
    // 0x801C6050: lbu         $a3, 0x11($s3)
    ctx->r7 = MEM_BU(ctx->r19, 0X11);
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_5;
    // 0x801C6050: lbu         $a3, 0x11($s3)
    ctx->r7 = MEM_BU(ctx->r19, 0X11);
    after_5:
    // 0x801C6054: b           L_801C6104
    // 0x801C6058: lbu         $s0, 0x90($s6)
    ctx->r16 = MEM_BU(ctx->r22, 0X90);
        goto L_801C6104;
    // 0x801C6058: lbu         $s0, 0x90($s6)
    ctx->r16 = MEM_BU(ctx->r22, 0X90);
L_801C605C:
    // 0x801C605C: bne         $s5, $s2, L_801C60B0
    if (ctx->r21 != ctx->r18) {
        // 0x801C6060: nop
    
            goto L_801C60B0;
    }
    // 0x801C6060: nop

    // 0x801C6064: jal         0x801C5AD4
    // 0x801C6068: lbu         $a0, 0x90($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X90);
    LOOKUP_FUNC(0x801C5AD4)(rdram, ctx);
        goto after_6;
    // 0x801C6068: lbu         $a0, 0x90($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X90);
    after_6:
    // 0x801C606C: beq         $v0, $zero, L_801C60B0
    if (ctx->r2 == 0) {
        // 0x801C6070: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801C60B0;
    }
    // 0x801C6070: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C6074: addiu       $t1, $zero, 0xC0
    ctx->r9 = ADD32(0, 0XC0);
    // 0x801C6078: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C607C: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x801C6080: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x801C6084: jal         0x80147250
    // 0x801C6088: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_7;
    // 0x801C6088: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_7:
    // 0x801C608C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801C6090: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C6094: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C6098: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x801C609C: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x801C60A0: jal         0x801472C0
    // 0x801C60A4: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_8;
    // 0x801C60A4: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_8:
    // 0x801C60A8: b           L_801C6104
    // 0x801C60AC: lbu         $s0, 0x90($s6)
    ctx->r16 = MEM_BU(ctx->r22, 0X90);
        goto L_801C6104;
    // 0x801C60AC: lbu         $s0, 0x90($s6)
    ctx->r16 = MEM_BU(ctx->r22, 0X90);
L_801C60B0:
    // 0x801C60B0: multu       $s4, $fp
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C60B4: addiu       $t4, $zero, 0x70
    ctx->r12 = ADD32(0, 0X70);
    // 0x801C60B8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C60BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C60C0: mflo        $t3
    ctx->r11 = lo;
    // 0x801C60C4: addu        $s0, $s3, $t3
    ctx->r16 = ADD32(ctx->r19, ctx->r11);
    // 0x801C60C8: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x801C60CC: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x801C60D0: jal         0x80147250
    // 0x801C60D4: lbu         $a3, 0x2($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X2);
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_9;
    // 0x801C60D4: lbu         $a3, 0x2($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X2);
    after_9:
    // 0x801C60D8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801C60DC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801C60E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C60E4: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x801C60E8: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x801C60EC: jal         0x801472C0
    // 0x801C60F0: lbu         $a3, 0x2($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X2);
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_10;
    // 0x801C60F0: lbu         $a3, 0x2($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X2);
    after_10:
    // 0x801C60F4: b           L_801C6104
    // 0x801C60F8: lbu         $s0, 0x90($s6)
    ctx->r16 = MEM_BU(ctx->r22, 0X90);
        goto L_801C6104;
    // 0x801C60F8: lbu         $s0, 0x90($s6)
    ctx->r16 = MEM_BU(ctx->r22, 0X90);
    // 0x801C60FC: sb          $zero, 0x22($s1)
    MEM_B(0X22, ctx->r17) = 0;
L_801C6100:
    // 0x801C6100: lbu         $s0, 0x90($s6)
    ctx->r16 = MEM_BU(ctx->r22, 0X90);
L_801C6104:
    // 0x801C6104: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C6108: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
    // 0x801C610C: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x801C6110: lb          $t6, -0x25A($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X25A);
    // 0x801C6114: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801C6118: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x801C611C: bne         $s2, $t6, L_801C6228
    if (ctx->r18 != ctx->r14) {
        // 0x801C6120: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801C6228;
    }
    // 0x801C6120: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C6124: bne         $s5, $s2, L_801C617C
    if (ctx->r21 != ctx->r18) {
        // 0x801C6128: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_801C617C;
    }
    // 0x801C6128: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x801C612C: addu        $t8, $s7, $t7
    ctx->r24 = ADD32(ctx->r23, ctx->r15);
    // 0x801C6130: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801C6134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C6138: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801C613C: beq         $t9, $zero, L_801C617C
    if (ctx->r25 == 0) {
        // 0x801C6140: nop
    
            goto L_801C617C;
    }
    // 0x801C6140: nop

    // 0x801C6144: lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0XF);
    // 0x801C6148: lbu         $a2, 0x10($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X10);
    // 0x801C614C: lbu         $a3, 0x11($s3)
    ctx->r7 = MEM_BU(ctx->r19, 0X11);
    // 0x801C6150: jal         0x80147250
    // 0x801C6154: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_11;
    // 0x801C6154: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_11:
    // 0x801C6158: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801C615C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C6160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C6164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C6168: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C616C: jal         0x801472C0
    // 0x801C6170: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_12;
    // 0x801C6170: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x801C6174: b           L_801C6258
    // 0x801C6178: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_801C6258;
    // 0x801C6178: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_801C617C:
    // 0x801C617C: bne         $s5, $s2, L_801C61D0
    if (ctx->r21 != ctx->r18) {
        // 0x801C6180: nop
    
            goto L_801C61D0;
    }
    // 0x801C6180: nop

    // 0x801C6184: jal         0x801C5AD4
    // 0x801C6188: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x801C5AD4)(rdram, ctx);
        goto after_13;
    // 0x801C6188: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_13:
    // 0x801C618C: beq         $v0, $zero, L_801C61D0
    if (ctx->r2 == 0) {
        // 0x801C6190: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801C61D0;
    }
    // 0x801C6190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C6194: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801C6198: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C619C: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801C61A0: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x801C61A4: jal         0x80147250
    // 0x801C61A8: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_14;
    // 0x801C61A8: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    after_14:
    // 0x801C61AC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801C61B0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801C61B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C61B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C61BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C61C0: jal         0x801472C0
    // 0x801C61C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_15;
    // 0x801C61C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x801C61C8: b           L_801C6258
    // 0x801C61CC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_801C6258;
    // 0x801C61CC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_801C61D0:
    // 0x801C61D0: multu       $s4, $fp
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C61D4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801C61D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C61DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C61E0: mflo        $s2
    ctx->r18 = lo;
    // 0x801C61E4: addu        $s0, $s3, $s2
    ctx->r16 = ADD32(ctx->r19, ctx->r18);
    // 0x801C61E8: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x801C61EC: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x801C61F0: jal         0x80147250
    // 0x801C61F4: lbu         $a3, 0x2($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X2);
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_16;
    // 0x801C61F4: lbu         $a3, 0x2($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X2);
    after_16:
    // 0x801C61F8: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801C61FC: addiu       $t5, $t5, -0x2FB0
    ctx->r13 = ADD32(ctx->r13, -0X2FB0);
    // 0x801C6200: addu        $v0, $s2, $t5
    ctx->r2 = ADD32(ctx->r18, ctx->r13);
    // 0x801C6204: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801C6208: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C620C: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x801C6210: lbu         $a2, 0x1($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1);
    // 0x801C6214: lbu         $a3, 0x2($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X2);
    // 0x801C6218: jal         0x801472C0
    // 0x801C621C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_17;
    // 0x801C621C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x801C6220: b           L_801C6258
    // 0x801C6224: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_801C6258;
    // 0x801C6224: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_801C6228:
    // 0x801C6228: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801C622C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C6230: jal         0x80147250
    // 0x801C6234: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_18;
    // 0x801C6234: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    after_18:
    // 0x801C6238: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801C623C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801C6240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C6244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C6248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C624C: jal         0x801472C0
    // 0x801C6250: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_19;
    // 0x801C6250: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_19:
    // 0x801C6254: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_801C6258:
    // 0x801C6258: andi        $s4, $s4, 0xFF
    ctx->r20 = ctx->r20 & 0XFF;
    // 0x801C625C: slti        $at, $s4, 0x5
    ctx->r1 = SIGNED(ctx->r20) < 0X5 ? 1 : 0;
    // 0x801C6260: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x801C6264: bne         $at, $zero, L_801C5FE0
    if (ctx->r1 != 0) {
        // 0x801C6268: lw          $s1, 0x10($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X10);
            goto L_801C5FE0;
    }
    // 0x801C6268: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
    // 0x801C626C: jal         0x801C5AD4
    // 0x801C6270: lbu         $a0, 0x90($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X90);
    LOOKUP_FUNC(0x801C5AD4)(rdram, ctx);
        goto after_20;
    // 0x801C6270: lbu         $a0, 0x90($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X90);
    after_20:
    // 0x801C6274: beq         $v0, $zero, L_801C6348
    if (ctx->r2 == 0) {
        // 0x801C6278: lui         $s1, 0x801D
        ctx->r17 = S32(0X801D << 16);
            goto L_801C6348;
    }
    // 0x801C6278: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801C627C: lbu         $s0, 0x90($s6)
    ctx->r16 = MEM_BU(ctx->r22, 0X90);
    // 0x801C6280: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801C6284: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801C6288: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x801C628C: lb          $t9, -0x25A($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X25A);
    // 0x801C6290: addiu       $s1, $s1, -0x268
    ctx->r17 = ADD32(ctx->r17, -0X268);
    // 0x801C6294: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x801C6298: bne         $s5, $t9, L_801C62FC
    if (ctx->r21 != ctx->r25) {
        // 0x801C629C: addu        $t8, $s1, $t7
        ctx->r24 = ADD32(ctx->r17, ctx->r15);
            goto L_801C62FC;
    }
    // 0x801C629C: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x801C62A0: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801C62A4: addiu       $s1, $s1, -0x268
    ctx->r17 = ADD32(ctx->r17, -0X268);
    // 0x801C62A8: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x801C62AC: addu        $t1, $s1, $t0
    ctx->r9 = ADD32(ctx->r17, ctx->r8);
    // 0x801C62B0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x801C62B4: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x801C62B8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C62BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C62C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C62C4: jal         0x80147250
    // 0x801C62C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_21;
    // 0x801C62C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_21:
    // 0x801C62CC: lbu         $t3, 0x90($s6)
    ctx->r11 = MEM_BU(ctx->r22, 0X90);
    // 0x801C62D0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801C62D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C62D8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801C62DC: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x801C62E0: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x801C62E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C62E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C62EC: jal         0x801472C0
    // 0x801C62F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_22;
    // 0x801C62F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_22:
    // 0x801C62F4: b           L_801C63A0
    // 0x801C62F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_801C63A0;
    // 0x801C62F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801C62FC:
    // 0x801C62FC: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x801C6300: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801C6304: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801C6308: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801C630C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x801C6310: jal         0x80147250
    // 0x801C6314: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_23;
    // 0x801C6314: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    after_23:
    // 0x801C6318: lbu         $t0, 0x90($s6)
    ctx->r8 = MEM_BU(ctx->r22, 0X90);
    // 0x801C631C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801C6320: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x801C6324: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801C6328: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x801C632C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x801C6330: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801C6334: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x801C6338: jal         0x801472C0
    // 0x801C633C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_24;
    // 0x801C633C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_24:
    // 0x801C6340: b           L_801C63A0
    // 0x801C6344: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_801C63A0;
    // 0x801C6344: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801C6348:
    // 0x801C6348: lbu         $t4, 0x90($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X90);
    // 0x801C634C: addiu       $s1, $s1, -0x268
    ctx->r17 = ADD32(ctx->r17, -0X268);
    // 0x801C6350: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801C6354: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801C6358: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x801C635C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x801C6360: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801C6364: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801C6368: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801C636C: jal         0x80147250
    // 0x801C6370: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_25;
    // 0x801C6370: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_25:
    // 0x801C6374: lbu         $t8, 0x90($s6)
    ctx->r24 = MEM_BU(ctx->r22, 0X90);
    // 0x801C6378: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801C637C: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    // 0x801C6380: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801C6384: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x801C6388: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x801C638C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C6390: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x801C6394: jal         0x801472C0
    // 0x801C6398: addiu       $a3, $zero, 0xB0
    ctx->r7 = ADD32(0, 0XB0);
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_26;
    // 0x801C6398: addiu       $a3, $zero, 0xB0
    ctx->r7 = ADD32(0, 0XB0);
    after_26:
    // 0x801C639C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801C63A0:
    // 0x801C63A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801C63A4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801C63A8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801C63AC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x801C63B0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x801C63B4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x801C63B8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x801C63BC: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x801C63C0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x801C63C4: jr          $ra
    // 0x801C63C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801C63C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c63cc(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c63cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C63CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C63D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801C63D4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801C63D8: sll         $a2, $a0, 2
    ctx->r6 = S32(ctx->r4 << 2);
    // 0x801C63DC: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801C63E0: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x801C63E4: lw          $t6, -0x280($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X280);
    // 0x801C63E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C63EC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C63F0: lh          $a1, 0x10($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X10);
    // 0x801C63F4: andi        $t8, $a1, 0x1000
    ctx->r24 = ctx->r5 & 0X1000;
    // 0x801C63F8: beql        $t8, $zero, L_801C6418
    if (ctx->r24 == 0) {
        // 0x801C63FC: andi        $a1, $a1, 0x1FFF
        ctx->r5 = ctx->r5 & 0X1FFF;
            goto L_801C6418;
    }
    goto skip_0;
    // 0x801C63FC: andi        $a1, $a1, 0x1FFF
    ctx->r5 = ctx->r5 & 0X1FFF;
    skip_0:
    // 0x801C6400: andi        $a1, $a1, 0x1FFF
    ctx->r5 = ctx->r5 & 0X1FFF;
    // 0x801C6404: addiu       $a1, $a1, -0x2000
    ctx->r5 = ADD32(ctx->r5, -0X2000);
    // 0x801C6408: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C640C: b           L_801C6420
    // 0x801C6410: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
        goto L_801C6420;
    // 0x801C6410: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801C6414: andi        $a1, $a1, 0x1FFF
    ctx->r5 = ctx->r5 & 0X1FFF;
L_801C6418:
    // 0x801C6418: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801C641C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_801C6420:
    // 0x801C6420: bgez        $a1, L_801C6430
    if (SIGNED(ctx->r5) >= 0) {
        // 0x801C6424: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_801C6430;
    }
    // 0x801C6424: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x801C6428: b           L_801C6430
    // 0x801C642C: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
        goto L_801C6430;
    // 0x801C642C: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
L_801C6430:
    // 0x801C6430: slti        $at, $v0, 0x800
    ctx->r1 = SIGNED(ctx->r2) < 0X800 ? 1 : 0;
    // 0x801C6434: beq         $at, $zero, L_801C6444
    if (ctx->r1 == 0) {
        // 0x801C6438: sll         $a0, $a1, 16
        ctx->r4 = S32(ctx->r5 << 16);
            goto L_801C6444;
    }
    // 0x801C6438: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x801C643C: b           L_801C64F0
    // 0x801C6440: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_801C64F0;
    // 0x801C6440: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_801C6444:
    // 0x801C6444: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801C6448: jal         0x8001EB64
    // 0x801C644C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801C644C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801C6450: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801C6454: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C6458: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x801C645C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C6460: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801C6464: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C6468: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x801C646C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C6470: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801C6474: nop

    // 0x801C6478: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C647C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801C6480: nop

    // 0x801C6484: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801C6488: beql        $a0, $zero, L_801C64D8
    if (ctx->r4 == 0) {
        // 0x801C648C: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_801C64D8;
    }
    goto skip_1;
    // 0x801C648C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x801C6490: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C6494: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801C6498: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C649C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801C64A0: nop

    // 0x801C64A4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C64A8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801C64AC: nop

    // 0x801C64B0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801C64B4: bne         $a0, $zero, L_801C64CC
    if (ctx->r4 != 0) {
        // 0x801C64B8: nop
    
            goto L_801C64CC;
    }
    // 0x801C64B8: nop

    // 0x801C64BC: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x801C64C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C64C4: b           L_801C64E4
    // 0x801C64C8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801C64E4;
    // 0x801C64C8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801C64CC:
    // 0x801C64CC: b           L_801C64E4
    // 0x801C64D0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801C64E4;
    // 0x801C64D0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801C64D4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_801C64D8:
    // 0x801C64D8: nop

    // 0x801C64DC: bltz        $a0, L_801C64CC
    if (SIGNED(ctx->r4) < 0) {
        // 0x801C64E0: nop
    
            goto L_801C64CC;
    }
    // 0x801C64E0: nop

L_801C64E4:
    // 0x801C64E4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C64E8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801C64EC: nop

L_801C64F0:
    // 0x801C64F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C64F4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x801C64F8: lw          $v0, -0x278($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X278);
    // 0x801C64FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801C6500:
    // 0x801C6500: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x801C6504: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801C6508: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801C650C: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x801C6510: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x801C6514: sb          $a0, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r4;
    // 0x801C6518: bne         $at, $zero, L_801C6500
    if (ctx->r1 != 0) {
        // 0x801C651C: lw          $v0, 0x10($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X10);
            goto L_801C6500;
    }
    // 0x801C651C: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x801C6520: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C6524: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x801C6528: lw          $v0, -0x270($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X270);
    // 0x801C652C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801C6530:
    // 0x801C6530: lw          $t1, 0x30($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X30);
    // 0x801C6534: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801C6538: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801C653C: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x801C6540: sb          $a0, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r4;
    // 0x801C6544: bne         $at, $zero, L_801C6530
    if (ctx->r1 != 0) {
        // 0x801C6548: lw          $v0, 0x10($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X10);
            goto L_801C6530;
    }
    // 0x801C6548: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x801C654C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C6550: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C6554: jr          $ra
    // 0x801C6558: nop

    return;
    // 0x801C6558: nop

;}
RECOMP_FUNC void M23_FUN_801c655c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C655C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C6560: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C6564: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C6568: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801C656C:
    // 0x801C656C: jal         0x801C63CC
    // 0x801C6570: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x801C63CC)(rdram, ctx);
        goto after_0;
    // 0x801C6570: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x801C6574: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C6578: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801C657C: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x801C6580: bne         $at, $zero, L_801C656C
    if (ctx->r1 != 0) {
        // 0x801C6584: nop
    
            goto L_801C656C;
    }
    // 0x801C6584: nop

    // 0x801C6588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C658C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C6590: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C6594: jr          $ra
    // 0x801C6598: nop

    return;
    // 0x801C6598: nop

;}
RECOMP_FUNC void M23_FUN_801c659c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C659C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x801C65A0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801C65A4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801C65A8: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x801C65AC: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x801C65B0: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x801C65B4: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x801C65B8: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x801C65BC: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x801C65C0: addiu       $t7, $t7, 0x4F30
    ctx->r15 = ADD32(ctx->r15, 0X4F30);
    // 0x801C65C4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C65C8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801C65CC: addiu       $t6, $sp, 0x7C
    ctx->r14 = ADD32(ctx->r29, 0X7C);
    // 0x801C65D0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801C65D4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801C65D8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801C65DC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801C65E0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x801C65E4: addiu       $t1, $t1, 0x4F40
    ctx->r9 = ADD32(ctx->r9, 0X4F40);
    // 0x801C65E8: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801C65EC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801C65F0: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801C65F4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801C65F8: addiu       $t0, $sp, 0x6C
    ctx->r8 = ADD32(ctx->r29, 0X6C);
    // 0x801C65FC: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x801C6600: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x801C6604: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801C6608: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x801C660C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801C6610: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x801C6614: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x801C6618: jal         0x800208C4
    // 0x801C661C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801C661C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    after_0:
    // 0x801C6620: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801C6624: addiu       $s0, $s0, -0x250
    ctx->r16 = ADD32(ctx->r16, -0X250);
    // 0x801C6628: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801C662C:
    // 0x801C662C: jal         0x80152890
    // 0x801C6630: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    LOOKUP_FUNC(0x80152890)(rdram, ctx);
        goto after_1;
    // 0x801C6630: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_1:
    // 0x801C6634: addu        $t4, $s0, $s1
    ctx->r12 = ADD32(ctx->r16, ctx->r17);
    // 0x801C6638: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C663C: sb          $v0, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r2;
    // 0x801C6640: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x801C6644: sb          $zero, -0x258($at)
    MEM_B(-0X258, ctx->r1) = 0;
    // 0x801C6648: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x801C664C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C6650: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C6654: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801C6658: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C665C: sw          $zero, -0x248($at)
    MEM_W(-0X248, ctx->r1) = 0;
    // 0x801C6660: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x801C6664: bne         $at, $zero, L_801C662C
    if (ctx->r1 != 0) {
        // 0x801C6668: nop
    
            goto L_801C662C;
    }
    // 0x801C6668: nop

    // 0x801C666C: jal         0x80116E80
    // 0x801C6670: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_2;
    // 0x801C6670: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x801C6674: jal         0x80116E80
    // 0x801C6678: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_3;
    // 0x801C6678: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_3:
    // 0x801C667C: jal         0x80116E80
    // 0x801C6680: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_4;
    // 0x801C6680: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_4:
    // 0x801C6684: jal         0x80116E80
    // 0x801C6688: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_5;
    // 0x801C6688: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_5:
    // 0x801C668C: addiu       $t6, $zero, -0x3
    ctx->r14 = ADD32(0, -0X3);
    // 0x801C6690: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x801C6694: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x801C6698: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    // 0x801C669C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C66A0: jal         0x80005E44
    // 0x801C66A4: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_6;
    // 0x801C66A4: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_6:
    // 0x801C66A8: jal         0x80006214
    // 0x801C66AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_7;
    // 0x801C66AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x801C66B0: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x801C66B4: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801C66B8: addiu       $t8, $t8, -0x3450
    ctx->r24 = ADD32(ctx->r24, -0X3450);
    // 0x801C66BC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801C66C0: addiu       $t2, $zero, -0x3
    ctx->r10 = ADD32(0, -0X3);
    // 0x801C66C4: addiu       $t3, $zero, 0x4000
    ctx->r11 = ADD32(0, 0X4000);
    // 0x801C66C8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C66CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C66D0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x801C66D4: sw          $t8, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r24;
    // 0x801C66D8: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x801C66DC: jal         0x80005E44
    // 0x801C66E0: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_8;
    // 0x801C66E0: sh          $t3, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r11;
    after_8:
    // 0x801C66E4: jal         0x80006214
    // 0x801C66E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_9;
    // 0x801C66E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x801C66EC: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x801C66F0: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801C66F4: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x801C66F8: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801C66FC: addiu       $t4, $t4, -0x3408
    ctx->r12 = ADD32(ctx->r12, -0X3408);
    // 0x801C6700: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x801C6704: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C6708: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801C670C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801C6710: addiu       $s2, $s2, -0x4410
    ctx->r18 = ADD32(ctx->r18, -0X4410);
    // 0x801C6714: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C6718: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C671C: sw          $t4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r12;
L_801C6720:
    // 0x801C6720: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x801C6724: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x801C6728: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x801C672C: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x801C6730: sll         $t0, $v1, 3
    ctx->r8 = S32(ctx->r3 << 3);
    // 0x801C6734: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x801C6738: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801C673C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x801C6740: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x801C6744: addiu       $t8, $t0, 0xA0
    ctx->r24 = ADD32(ctx->r8, 0XA0);
    // 0x801C6748: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801C674C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x801C6750: addu        $s0, $s2, $t9
    ctx->r16 = ADD32(ctx->r18, ctx->r25);
    // 0x801C6754: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801C6758: lw          $t3, 0x28C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28C);
    // 0x801C675C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x801C6760: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801C6764: lw          $t5, 0x2C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X2C);
    // 0x801C6768: sub.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = ctx->f6.d - ctx->f20.d;
    // 0x801C676C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C6770: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801C6774: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C6778: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x801C677C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801C6780: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C6784: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801C6788: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x801C678C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C6790: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801C6794: sh          $t2, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r10;
    // 0x801C6798: lw          $t4, 0x28C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28C);
    // 0x801C679C: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x801C67A0: subu        $t5, $t5, $v1
    ctx->r13 = SUB32(ctx->r13, ctx->r3);
    // 0x801C67A4: lw          $t7, 0x2C($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X2C);
    // 0x801C67A8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x801C67AC: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x801C67B0: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    // 0x801C67B4: lw          $t9, 0x28C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28C);
    // 0x801C67B8: addiu       $t4, $t5, 0x64
    ctx->r12 = ADD32(ctx->r13, 0X64);
    // 0x801C67BC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x801C67C0: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801C67C4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801C67C8: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x801C67CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801C67D0: addiu       $t8, $t0, 0x78
    ctx->r24 = ADD32(ctx->r8, 0X78);
    // 0x801C67D4: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x801C67D8: lw          $t1, 0x28C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28C);
    // 0x801C67DC: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x801C67E0: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x801C67E4: addiu       $t2, $t3, 0x64
    ctx->r10 = ADD32(ctx->r11, 0X64);
    // 0x801C67E8: sh          $t2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r10;
    // 0x801C67EC: lw          $t6, 0x28C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28C);
    // 0x801C67F0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C67F4: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x801C67F8: lw          $t9, 0x28C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28C);
    // 0x801C67FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C6800: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801C6804: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801C6808: swc1        $f4, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f4.u32l;
    // 0x801C680C: lw          $t8, 0x28C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28C);
    // 0x801C6810: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C6814: lw          $t1, 0x2C($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X2C);
    // 0x801C6818: swc1        $f6, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f6.u32l;
    // 0x801C681C: lw          $t3, 0x28C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28C);
    // 0x801C6820: lw          $t2, 0x2C($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X2C);
    // 0x801C6824: swc1        $f8, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f8.u32l;
    // 0x801C6828: lw          $t5, 0x28C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28C);
    // 0x801C682C: lw          $t4, 0x2C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X2C);
    // 0x801C6830: swc1        $f10, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f10.u32l;
    // 0x801C6834: lw          $t6, 0x28C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28C);
    // 0x801C6838: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801C683C: swc1        $f16, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f16.u32l;
    // 0x801C6840: lw          $t9, 0x28C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28C);
    // 0x801C6844: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801C6848: swc1        $f18, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f18.u32l;
    // 0x801C684C: lw          $t8, 0x28C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28C);
    // 0x801C6850: lw          $t1, 0x2C($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X2C);
    // 0x801C6854: jal         0x80001060
    // 0x801C6858: swc1        $f4, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_10;
    // 0x801C6858: swc1        $f4, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f4.u32l;
    after_10:
    // 0x801C685C: beq         $v0, $zero, L_801C68F0
    if (ctx->r2 == 0) {
        // 0x801C6860: sll         $t2, $s1, 4
        ctx->r10 = S32(ctx->r17 << 4);
            goto L_801C68F0;
    }
    // 0x801C6860: sll         $t2, $s1, 4
    ctx->r10 = S32(ctx->r17 << 4);
    // 0x801C6864: lw          $t3, 0x28C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28C);
    // 0x801C6868: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801C686C: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x801C6870: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x801C6874: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x801C6878: lw          $t4, 0x28C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28C);
    // 0x801C687C: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x801C6880: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x801C6884: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x801C6888: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x801C688C: lw          $t9, 0x28C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28C);
    // 0x801C6890: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C6894: addiu       $t7, $t7, -0x30B8
    ctx->r15 = ADD32(ctx->r15, -0X30B8);
    // 0x801C6898: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801C689C: sll         $t6, $s1, 4
    ctx->r14 = S32(ctx->r17 << 4);
    // 0x801C68A0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x801C68A4: lh          $t0, 0x4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4);
    // 0x801C68A8: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x801C68AC: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x801C68B0: lw          $t1, 0x28C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28C);
    // 0x801C68B4: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x801C68B8: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x801C68BC: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x801C68C0: sh          $t2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r10;
    // 0x801C68C4: lw          $t5, 0x28C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28C);
    // 0x801C68C8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x801C68CC: lw          $t4, 0x2C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X2C);
    // 0x801C68D0: sw          $t8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r24;
    // 0x801C68D4: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801C68D8: sw          $t0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r8;
    // 0x801C68DC: lw          $t8, 0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X8);
    // 0x801C68E0: sw          $t8, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r24;
    // 0x801C68E4: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x801C68E8: b           L_801C6924
    // 0x801C68EC: sw          $t0, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r8;
        goto L_801C6924;
    // 0x801C68EC: sw          $t0, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r8;
L_801C68F0:
    // 0x801C68F0: lw          $t1, 0x28C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28C);
    // 0x801C68F4: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801C68F8: addiu       $t5, $t5, -0x30D8
    ctx->r13 = ADD32(ctx->r13, -0X30D8);
    // 0x801C68FC: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x801C6900: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x801C6904: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x801C6908: sw          $t4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r12;
    // 0x801C690C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801C6910: sw          $t7, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r15;
    // 0x801C6914: lw          $t4, 0x8($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X8);
    // 0x801C6918: sw          $t4, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r12;
    // 0x801C691C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801C6920: sw          $t7, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r15;
L_801C6924:
    // 0x801C6924: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C6928: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C692C: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x801C6930: bne         $at, $zero, L_801C6720
    if (ctx->r1 != 0) {
        // 0x801C6934: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801C6720;
    }
    // 0x801C6934: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C6938: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801C693C: addiu       $s0, $s0, -0x2F00
    ctx->r16 = ADD32(ctx->r16, -0X2F00);
    // 0x801C6940: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C6944: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_801C6948:
    // 0x801C6948: jal         0x80005670
    // 0x801C694C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_11;
    // 0x801C694C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x801C6950: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801C6954: addiu       $t0, $t0, -0x288
    ctx->r8 = ADD32(ctx->r8, -0X288);
    // 0x801C6958: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x801C695C: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x801C6960: beq         $v0, $zero, L_801C696C
    if (ctx->r2 == 0) {
        // 0x801C6964: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_801C696C;
    }
    // 0x801C6964: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801C6968: sb          $s1, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r17;
L_801C696C:
    // 0x801C696C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C6970: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C6974: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x801C6978: bnel        $at, $zero, L_801C6948
    if (ctx->r1 != 0) {
        // 0x801C697C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801C6948;
    }
    goto skip_0;
    // 0x801C697C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x801C6980: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801C6984: addiu       $s0, $s0, -0x2EEC
    ctx->r16 = ADD32(ctx->r16, -0X2EEC);
    // 0x801C6988: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C698C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_801C6990:
    // 0x801C6990: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x801C6994: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    // 0x801C6998: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x801C699C: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x801C69A0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801C69A4: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x801C69A8: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x801C69AC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801C69B0: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x801C69B4: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x801C69B8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801C69BC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C69C0: lw          $t2, 0x10($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10);
    // 0x801C69C4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x801C69C8: jal         0x8012C4D0
    // 0x801C69CC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_12;
    // 0x801C69CC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_12:
    // 0x801C69D0: beql        $v0, $zero, L_801C69E0
    if (ctx->r2 == 0) {
        // 0x801C69D4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801C69E0;
    }
    goto skip_1;
    // 0x801C69D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x801C69D8: sb          $s1, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r17;
    // 0x801C69DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801C69E0:
    // 0x801C69E0: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C69E4: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x801C69E8: bnel        $at, $zero, L_801C6990
    if (ctx->r1 != 0) {
        // 0x801C69EC: lw          $t2, 0x0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X0);
            goto L_801C6990;
    }
    goto skip_2;
    // 0x801C69EC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x801C69F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801C69F4: addiu       $v0, $v0, -0x290
    ctx->r2 = ADD32(ctx->r2, -0X290);
    // 0x801C69F8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801C69FC:
    // 0x801C69FC: addu        $t3, $v0, $s1
    ctx->r11 = ADD32(ctx->r2, ctx->r17);
    // 0x801C6A00: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C6A04: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801C6A08: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x801C6A0C: bne         $at, $zero, L_801C69FC
    if (ctx->r1 != 0) {
        // 0x801C6A10: sb          $zero, 0x0($t3)
        MEM_B(0X0, ctx->r11) = 0;
            goto L_801C69FC;
    }
    // 0x801C6A10: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
    // 0x801C6A14: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C6A18: addiu       $a1, $a1, -0x2EB0
    ctx->r5 = ADD32(ctx->r5, -0X2EB0);
    // 0x801C6A1C: jal         0x80005670
    // 0x801C6A20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_13;
    // 0x801C6A20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x801C6A24: addiu       $s0, $sp, 0x6A
    ctx->r16 = ADD32(ctx->r29, 0X6A);
    // 0x801C6A28: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x801C6A2C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x801C6A30: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x801C6A34: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801C6A38: addiu       $t0, $zero, 0x229
    ctx->r8 = ADD32(0, 0X229);
    // 0x801C6A3C: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x801C6A40: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x801C6A44: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801C6A48: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801C6A4C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801C6A50: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801C6A54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801C6A58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801C6A5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C6A60: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C6A64: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    // 0x801C6A68: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C6A6C: jal         0x80146208
    // 0x801C6A70: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_14;
    // 0x801C6A70: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_14:
    // 0x801C6A74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C6A78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C6A7C: jal         0x80145348
    // 0x801C6A80: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_15;
    // 0x801C6A80: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    after_15:
    // 0x801C6A84: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x801C6A88: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x801C6A8C: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x801C6A90: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801C6A94: addiu       $t6, $zero, 0x229
    ctx->r14 = ADD32(0, 0X229);
    // 0x801C6A98: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x801C6A9C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801C6AA0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801C6AA4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x801C6AA8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x801C6AAC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801C6AB0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C6AB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C6AB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801C6ABC: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C6AC0: addiu       $a3, $zero, 0x7A
    ctx->r7 = ADD32(0, 0X7A);
    // 0x801C6AC4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C6AC8: jal         0x80146208
    // 0x801C6ACC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_16;
    // 0x801C6ACC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_16:
    // 0x801C6AD0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C6AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C6AD8: jal         0x80145348
    // 0x801C6ADC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_17;
    // 0x801C6ADC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_17:
    // 0x801C6AE0: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x801C6AE4: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x801C6AE8: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x801C6AEC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801C6AF0: addiu       $t1, $zero, 0x229
    ctx->r9 = ADD32(0, 0X229);
    // 0x801C6AF4: addiu       $t2, $zero, 0xB
    ctx->r10 = ADD32(0, 0XB);
    // 0x801C6AF8: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801C6AFC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801C6B00: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x801C6B04: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801C6B08: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801C6B0C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801C6B10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C6B14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801C6B18: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801C6B1C: addiu       $a3, $zero, 0xB6
    ctx->r7 = ADD32(0, 0XB6);
    // 0x801C6B20: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801C6B24: jal         0x80146208
    // 0x801C6B28: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_18;
    // 0x801C6B28: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_18:
    // 0x801C6B2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C6B30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C6B34: jal         0x80145348
    // 0x801C6B38: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_19;
    // 0x801C6B38: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_19:
    // 0x801C6B3C: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x801C6B40: sh          $t5, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r13;
    // 0x801C6B44: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C6B48: jal         0x80005E44
    // 0x801C6B4C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_20;
    // 0x801C6B4C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_20:
    // 0x801C6B50: jal         0x80006214
    // 0x801C6B54: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_21;
    // 0x801C6B54: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_21:
    // 0x801C6B58: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x801C6B5C: andi        $s0, $v1, 0xFF
    ctx->r16 = ctx->r3 & 0XFF;
    // 0x801C6B60: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x801C6B64: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C6B68: addiu       $a2, $zero, 0x229
    ctx->r6 = ADD32(0, 0X229);
    // 0x801C6B6C: jal         0x8012C89C
    // 0x801C6B70: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_22;
    // 0x801C6B70: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_22:
    // 0x801C6B74: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x801C6B78: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x801C6B7C: addiu       $t7, $zero, 0x101
    ctx->r15 = ADD32(0, 0X101);
    // 0x801C6B80: addu        $v0, $t3, $t6
    ctx->r2 = ADD32(ctx->r11, ctx->r14);
    // 0x801C6B84: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801C6B88: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801C6B8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C6B90: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x801C6B94: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801C6B98: addiu       $t0, $t0, -0x32F0
    ctx->r8 = ADD32(ctx->r8, -0X32F0);
    // 0x801C6B9C: sw          $t7, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r15;
    // 0x801C6BA0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801C6BA4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C6BA8: or          $t8, $t0, $at
    ctx->r24 = ctx->r8 | ctx->r1;
    // 0x801C6BAC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C6BB0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x801C6BB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C6BB8: sw          $t8, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r24;
    // 0x801C6BBC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801C6BC0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801C6BC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C6BC8: lw          $t3, 0x30($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X30);
    // 0x801C6BCC: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x801C6BD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C6BD4: swc1        $f6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f6.u32l;
    // 0x801C6BD8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801C6BDC: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x801C6BE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C6BE4: lw          $t4, 0x30($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X30);
    // 0x801C6BE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801C6BEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C6BF0: swc1        $f8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f8.u32l;
    // 0x801C6BF4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C6BF8: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C6BFC: swc1        $f10, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f10.u32l;
    // 0x801C6C00: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801C6C04: lw          $t8, 0x30($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X30);
    // 0x801C6C08: sh          $t0, 0x10($t8)
    MEM_H(0X10, ctx->r24) = ctx->r8;
    // 0x801C6C0C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801C6C10: lw          $t5, 0x30($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X30);
    // 0x801C6C14: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x801C6C18: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801C6C1C: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x801C6C20: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x801C6C24: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801C6C28: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x801C6C2C: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x801C6C30: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x801C6C34: jal         0x80147250
    // 0x801C6C38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_23;
    // 0x801C6C38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_23:
    // 0x801C6C3C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C6C40: addiu       $a1, $a1, 0x6C6C
    ctx->r5 = ADD32(ctx->r5, 0X6C6C);
    // 0x801C6C44: jal         0x800058DC
    // 0x801C6C48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_24;
    // 0x801C6C48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_24:
    // 0x801C6C4C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801C6C50: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x801C6C54: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x801C6C58: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x801C6C5C: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x801C6C60: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x801C6C64: jr          $ra
    // 0x801C6C68: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x801C6C68: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c6c6c(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c6c6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C6C6C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801C6C70: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801C6C74: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801C6C78: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x801C6C7C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801C6C80: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801C6C84: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801C6C88: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801C6C8C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801C6C90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C6C94: jal         0x801C5B38
    // 0x801C6C98: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C5B38)(rdram, ctx);
        goto after_0;
    // 0x801C6C98: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C6C9C: beq         $v0, $zero, L_801C6D6C
    if (ctx->r2 == 0) {
        // 0x801C6CA0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801C6D6C;
    }
    // 0x801C6CA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C6CA4: lui         $s4, 0x801D
    ctx->r20 = S32(0X801D << 16);
    // 0x801C6CA8: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x801C6CAC: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801C6CB0: addiu       $s1, $s1, -0x254
    ctx->r17 = ADD32(ctx->r17, -0X254);
    // 0x801C6CB4: addiu       $s2, $s2, -0x2F38
    ctx->r18 = ADD32(ctx->r18, -0X2F38);
    // 0x801C6CB8: addiu       $s4, $s4, -0x280
    ctx->r20 = ADD32(ctx->r20, -0X280);
    // 0x801C6CBC: addiu       $s5, $zero, 0x2000
    ctx->r21 = ADD32(0, 0X2000);
    // 0x801C6CC0: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
L_801C6CC4:
    // 0x801C6CC4: addu        $v0, $s4, $t6
    ctx->r2 = ADD32(ctx->r20, ctx->r14);
    // 0x801C6CC8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C6CCC: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x801C6CD0: addiu       $s3, $s3, 0x6D94
    ctx->r19 = ADD32(ctx->r19, 0X6D94);
    // 0x801C6CD4: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x801C6CD8: lh          $t8, 0x10($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X10);
    // 0x801C6CDC: addiu       $t9, $t8, 0x155
    ctx->r25 = ADD32(ctx->r24, 0X155);
    // 0x801C6CE0: sh          $t9, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r25;
    // 0x801C6CE4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801C6CE8: lw          $v1, 0x30($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X30);
    // 0x801C6CEC: lh          $a0, 0x10($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X10);
    // 0x801C6CF0: slti        $at, $a0, 0x2001
    ctx->r1 = SIGNED(ctx->r4) < 0X2001 ? 1 : 0;
    // 0x801C6CF4: bnel        $at, $zero, L_801C6D4C
    if (ctx->r1 != 0) {
        // 0x801C6CF8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801C6D4C;
    }
    goto skip_0;
    // 0x801C6CF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x801C6CFC: sh          $s5, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r21;
    // 0x801C6D00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C6D04: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
L_801C6D08:
    // 0x801C6D08: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x801C6D0C: lhu         $a1, 0x0($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X0);
    // 0x801C6D10: jal         0x80152CC8
    // 0x801C6D14: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80152CC8)(rdram, ctx);
        goto after_1;
    // 0x801C6D14: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_1:
    // 0x801C6D18: addu        $t3, $s2, $s0
    ctx->r11 = ADD32(ctx->r18, ctx->r16);
    // 0x801C6D1C: lb          $a1, 0x0($t3)
    ctx->r5 = MEM_B(ctx->r11, 0X0);
    // 0x801C6D20: jal         0x80152BC8
    // 0x801C6D24: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80152BC8)(rdram, ctx);
        goto after_2;
    // 0x801C6D24: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_2:
    // 0x801C6D28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C6D2C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801C6D30: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x801C6D34: bnel        $at, $zero, L_801C6D08
    if (ctx->r1 != 0) {
        // 0x801C6D38: sll         $t1, $s0, 1
        ctx->r9 = S32(ctx->r16 << 1);
            goto L_801C6D08;
    }
    goto skip_1;
    // 0x801C6D38: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    skip_1:
    // 0x801C6D3C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x801C6D40: jal         0x800058DC
    // 0x801C6D44: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C6D44: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x801C6D48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801C6D4C:
    // 0x801C6D4C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801C6D50: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x801C6D54: bnel        $at, $zero, L_801C6CC4
    if (ctx->r1 != 0) {
        // 0x801C6D58: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_801C6CC4;
    }
    goto skip_2;
    // 0x801C6D58: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    skip_2:
    // 0x801C6D5C: jal         0x801C655C
    // 0x801C6D60: nop

    LOOKUP_FUNC(0x801C655C)(rdram, ctx);
        goto after_4;
    // 0x801C6D60: nop

    after_4:
    // 0x801C6D64: jal         0x801C5C18
    // 0x801C6D68: nop

    LOOKUP_FUNC(0x801C5C18)(rdram, ctx);
        goto after_5;
    // 0x801C6D68: nop

    after_5:
L_801C6D6C:
    // 0x801C6D6C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801C6D70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C6D74: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801C6D78: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801C6D7C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801C6D80: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801C6D84: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801C6D88: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801C6D8C: jr          $ra
    // 0x801C6D90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801C6D90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c6d94(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c6d94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C6D94: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x801C6D98: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801C6D9C: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x801C6DA0: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x801C6DA4: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x801C6DA8: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x801C6DAC: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x801C6DB0: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x801C6DB4: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x801C6DB8: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x801C6DBC: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x801C6DC0: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x801C6DC4: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x801C6DC8: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x801C6DCC: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x801C6DD0: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x801C6DD4: addiu       $t7, $t7, 0x4F40
    ctx->r15 = ADD32(ctx->r15, 0X4F40);
    // 0x801C6DD8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801C6DDC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801C6DE0: addiu       $t6, $sp, 0xA0
    ctx->r14 = ADD32(ctx->r29, 0XA0);
    // 0x801C6DE4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801C6DE8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801C6DEC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801C6DF0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801C6DF4: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801C6DF8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801C6DFC: addiu       $s0, $s0, -0x288
    ctx->r16 = ADD32(ctx->r16, -0X288);
    // 0x801C6E00: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C6E04: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801C6E08: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801C6E0C: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
L_801C6E10:
    // 0x801C6E10: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x801C6E14: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x801C6E18: beql        $a0, $zero, L_801C6E2C
    if (ctx->r4 == 0) {
        // 0x801C6E1C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_801C6E2C;
    }
    goto skip_0;
    // 0x801C6E1C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x801C6E20: jal         0x80005700
    // 0x801C6E24: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801C6E24: nop

    after_0:
    // 0x801C6E28: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_801C6E2C:
    // 0x801C6E2C: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801C6E30: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x801C6E34: bnel        $at, $zero, L_801C6E10
    if (ctx->r1 != 0) {
        // 0x801C6E38: sll         $t0, $s2, 2
        ctx->r8 = S32(ctx->r18 << 2);
            goto L_801C6E10;
    }
    goto skip_1;
    // 0x801C6E38: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    skip_1:
    // 0x801C6E3C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801C6E40: addiu       $a3, $a3, -0xD1C
    ctx->r7 = ADD32(ctx->r7, -0XD1C);
    // 0x801C6E44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801C6E48: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801C6E4C: jal         0x8001B204
    // 0x801C6E50: addiu       $a2, $zero, 0x7C
    ctx->r6 = ADD32(0, 0X7C);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801C6E50: addiu       $a2, $zero, 0x7C
    ctx->r6 = ADD32(0, 0X7C);
    after_1:
    // 0x801C6E54: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x801C6E58: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x801C6E5C: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x801C6E60: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x801C6E64: addiu       $t6, $zero, 0x229
    ctx->r14 = ADD32(0, 0X229);
    // 0x801C6E68: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x801C6E6C: addiu       $t8, $zero, 0x229
    ctx->r24 = ADD32(0, 0X229);
    // 0x801C6E70: addiu       $t9, $zero, 0xE
    ctx->r25 = ADD32(0, 0XE);
    // 0x801C6E74: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x801C6E78: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x801C6E7C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x801C6E80: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801C6E84: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x801C6E88: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801C6E8C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801C6E90: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801C6E94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C6E98: addiu       $a1, $zero, 0x2004
    ctx->r5 = ADD32(0, 0X2004);
    // 0x801C6E9C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x801C6EA0: addiu       $a3, $zero, 0x8D
    ctx->r7 = ADD32(0, 0X8D);
    // 0x801C6EA4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801C6EA8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801C6EAC: jal         0x8014646C
    // 0x801C6EB0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    LOOKUP_FUNC(0x8014646C)(rdram, ctx);
        goto after_2;
    // 0x801C6EB0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_2:
    // 0x801C6EB4: jal         0x80006214
    // 0x801C6EB8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801C6EB8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x801C6EBC: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x801C6EC0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x801C6EC4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801C6EC8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x801C6ECC: lw          $t3, -0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X4);
    // 0x801C6ED0: addiu       $v1, $v1, -0x260
    ctx->r3 = ADD32(ctx->r3, -0X260);
    // 0x801C6ED4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C6ED8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801C6EDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C6EE0: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801C6EE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C6EE8: swc1        $f0, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f0.u32l;
    // 0x801C6EEC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801C6EF0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C6EF4: jal         0x80006214
    // 0x801C6EF8: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x801C6EF8: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
    after_4:
    // 0x801C6EFC: lui         $s6, 0x801D
    ctx->r22 = S32(0X801D << 16);
    // 0x801C6F00: addiu       $s6, $s6, -0x3200
    ctx->r22 = ADD32(ctx->r22, -0X3200);
    // 0x801C6F04: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C6F08: or          $s6, $s6, $at
    ctx->r22 = ctx->r22 | ctx->r1;
    // 0x801C6F0C: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x801C6F10: lui         $at, 0x432D
    ctx->r1 = S32(0X432D << 16);
    // 0x801C6F14: andi        $s4, $v0, 0xFF
    ctx->r20 = ctx->r2 & 0XFF;
    // 0x801C6F18: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801C6F1C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C6F20: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x801C6F24: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801C6F28: lwc1        $f20, -0xC64($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0XC64);
    // 0x801C6F2C: sb          $s4, 0x9E($sp)
    MEM_B(0X9E, ctx->r29) = ctx->r20;
    // 0x801C6F30: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C6F34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C6F38: addiu       $fp, $zero, 0x2A
    ctx->r30 = ADD32(0, 0X2A);
    // 0x801C6F3C: addiu       $s7, $zero, 0xCA
    ctx->r23 = ADD32(0, 0XCA);
    // 0x801C6F40: addu        $s5, $t8, $t9
    ctx->r21 = ADD32(ctx->r24, ctx->r25);
L_801C6F44:
    // 0x801C6F44: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x801C6F48: sh          $t0, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r8;
    // 0x801C6F4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C6F50: jal         0x80005E44
    // 0x801C6F54: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_5;
    // 0x801C6F54: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    after_5:
    // 0x801C6F58: jal         0x80006214
    // 0x801C6F5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_6;
    // 0x801C6F5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x801C6F60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801C6F64: addu        $a1, $s4, $s1
    ctx->r5 = ADD32(ctx->r20, ctx->r17);
    // 0x801C6F68: addiu       $a2, $zero, 0x229
    ctx->r6 = ADD32(0, 0X229);
    // 0x801C6F6C: jal         0x8012C89C
    // 0x801C6F70: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_7;
    // 0x801C6F70: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x801C6F74: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x801C6F78: addu        $s0, $s5, $t1
    ctx->r16 = ADD32(ctx->r21, ctx->r9);
    // 0x801C6F7C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C6F80: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x801C6F84: multu       $t7, $fp
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801C6F88: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x801C6F8C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801C6F90: addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // 0x801C6F94: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x801C6F98: addiu       $a3, $zero, 0xCF
    ctx->r7 = ADD32(0, 0XCF);
    // 0x801C6F9C: ori         $t4, $t3, 0x300
    ctx->r12 = ctx->r11 | 0X300;
    // 0x801C6FA0: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
    // 0x801C6FA4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C6FA8: mflo        $t8
    ctx->r24 = lo;
    // 0x801C6FAC: subu        $t9, $s7, $t8
    ctx->r25 = SUB32(ctx->r23, ctx->r24);
    // 0x801C6FB0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C6FB4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801C6FB8: sll         $t9, $s1, 12
    ctx->r25 = S32(ctx->r17 << 12);
    // 0x801C6FBC: sw          $s6, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r22;
    // 0x801C6FC0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C6FC4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C6FC8: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x801C6FCC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C6FD0: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x801C6FD4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801C6FD8: swc1        $f6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f6.u32l;
    // 0x801C6FDC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C6FE0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C6FE4: swc1        $f22, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f22.u32l;
    // 0x801C6FE8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C6FEC: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C6FF0: swc1        $f24, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f24.u32l;
    // 0x801C6FF4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C6FF8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C6FFC: sh          $t6, 0x10($t8)
    MEM_H(0X10, ctx->r24) = ctx->r14;
    // 0x801C7000: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C7004: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C7008: sh          $t0, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r8;
    // 0x801C700C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C7010: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C7014: swc1        $f20, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f20.u32l;
    // 0x801C7018: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C701C: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801C7020: swc1        $f20, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f20.u32l;
    // 0x801C7024: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C7028: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801C702C: swc1        $f20, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f20.u32l;
    // 0x801C7030: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801C7034: jal         0x80147250
    // 0x801C7038: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80147250)(rdram, ctx);
        goto after_8;
    // 0x801C7038: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_8:
    // 0x801C703C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801C7040: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801C7044: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801C7048: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801C704C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x801C7050: jal         0x801472C0
    // 0x801C7054: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    LOOKUP_FUNC(0x801472C0)(rdram, ctx);
        goto after_9;
    // 0x801C7054: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_9:
    // 0x801C7058: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C705C: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801C7060: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x801C7064: bne         $at, $zero, L_801C6F44
    if (ctx->r1 != 0) {
        // 0x801C7068: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_801C6F44;
    }
    // 0x801C7068: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x801C706C: lbu         $t2, 0x9E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X9E);
    // 0x801C7070: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x801C7074: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801C7078: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801C707C: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x801C7080: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801C7084: lbu         $t7, -0x2F30($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2F30);
    // 0x801C7088: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801C708C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C7090: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C7094: sw          $t5, -0x270($at)
    MEM_W(-0X270, ctx->r1) = ctx->r13;
    // 0x801C7098: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x801C709C: sb          $t8, 0x90($s3)
    MEM_B(0X90, ctx->r19) = ctx->r24;
    // 0x801C70A0: addiu       $a1, $a1, 0x70E8
    ctx->r5 = ADD32(ctx->r5, 0X70E8);
    // 0x801C70A4: jal         0x800058DC
    // 0x801C70A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x801C70A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x801C70AC: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x801C70B0: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x801C70B4: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x801C70B8: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x801C70BC: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x801C70C0: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x801C70C4: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x801C70C8: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x801C70CC: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x801C70D0: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x801C70D4: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x801C70D8: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x801C70DC: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x801C70E0: jr          $ra
    // 0x801C70E4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x801C70E4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c70e8(rdram, ctx);
;}
RECOMP_FUNC void M23_FUN_801c70e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C70E8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801C70EC: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x801C70F0: lhu         $t6, 0x1F0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1F0);
    // 0x801C70F4: lhu         $t7, 0x1D0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1D0);
    // 0x801C70F8: lhu         $t8, 0x1E8($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E8);
    // 0x801C70FC: lhu         $t9, 0x1C8($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X1C8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M23_FUN_801c7100(rdram, ctx);
;}
