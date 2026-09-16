#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000400: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80000404: lui         $t1, 0x8
    ctx->r9 = S32(0X8 << 16);
    // 0x80000408: addiu       $t0, $t0, -0x2430
    ctx->r8 = ADD32(ctx->r8, -0X2430);
    // 0x8000040C: ori         $t1, $t1, 0xDC0
    ctx->r9 = ctx->r9 | 0XDC0;
L_80000410:
    // 0x80000410: addi        $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80000414: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80000418: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8000041C: bne         $t1, $zero, L_80000410
    if (ctx->r9 != 0) {
        // 0x80000420: addi        $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80000410;
    }
    // 0x80000420: addi        $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80000424: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80000428: lui         $sp, 0x8005
    ctx->r29 = S32(0X8005 << 16);
    // 0x8000042C: addiu       $t2, $t2, 0x1078
    ctx->r10 = ADD32(ctx->r10, 0X1078);
    // 0x80000430: jr          $t2
    // 0x80000434: addiu       $sp, $sp, 0x7BD0
    ctx->r29 = ADD32(ctx->r29, 0X7BD0);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    return;
    // 0x80000434: addiu       $sp, $sp, 0x7BD0
    ctx->r29 = ADD32(ctx->r29, 0X7BD0);
    // 0x80000438: nop

    // 0x8000043C: nop

    // 0x80000440: nop

    // 0x80000444: nop

    // 0x80000448: nop

    // 0x8000044C: nop

    // 0x80000450: nop

    // 0x80000454: nop

    // 0x80000458: nop

    // 0x8000045C: nop

;}
RECOMP_FUNC void FUN_80000460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000460: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80000464: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80000468: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000046C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80000470: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80000474: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000478: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8000047C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80000480: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x80000484: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x80000488: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000048C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80000490: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x80000494: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80000498: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8000049C: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x800004A0: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x800004A4: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x800004A8: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x800004AC: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800004B0: sw          $zero, 0x88C($a0)
    MEM_W(0X88C, ctx->r4) = 0;
    // 0x800004B4: sw          $zero, 0x890($a0)
    MEM_W(0X890, ctx->r4) = 0;
    // 0x800004B8: sw          $zero, 0x894($a0)
    MEM_W(0X894, ctx->r4) = 0;
    // 0x800004BC: sw          $zero, 0x888($a0)
    MEM_W(0X888, ctx->r4) = 0;
    // 0x800004C0: sw          $zero, 0x89C($a0)
    MEM_W(0X89C, ctx->r4) = 0;
    // 0x800004C4: sw          $zero, 0x898($a0)
    MEM_W(0X898, ctx->r4) = 0;
    // 0x800004C8: sw          $v0, 0x8A0($a0)
    MEM_W(0X8A0, ctx->r4) = ctx->r2;
    // 0x800004CC: sw          $v0, 0x8A4($a0)
    MEM_W(0X8A4, ctx->r4) = ctx->r2;
    // 0x800004D0: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
    // 0x800004D4: sw          $t1, 0x8AC($a0)
    MEM_W(0X8AC, ctx->r4) = ctx->r9;
    // 0x800004D8: sw          $t0, 0x8A8($a0)
    MEM_W(0X8A8, ctx->r4) = ctx->r8;
    // 0x800004DC: sw          $t3, 0x8B4($a0)
    MEM_W(0X8B4, ctx->r4) = ctx->r11;
    // 0x800004E0: sw          $t2, 0x8B0($a0)
    MEM_W(0X8B0, ctx->r4) = ctx->r10;
    // 0x800004E4: sw          $t5, 0x8BC($a0)
    MEM_W(0X8BC, ctx->r4) = ctx->r13;
    // 0x800004E8: sw          $t4, 0x8B8($a0)
    MEM_W(0X8B8, ctx->r4) = ctx->r12;
    // 0x800004EC: sw          $t6, 0x8C0($a0)
    MEM_W(0X8C0, ctx->r4) = ctx->r14;
    // 0x800004F0: sw          $t7, 0x8C4($a0)
    MEM_W(0X8C4, ctx->r4) = ctx->r15;
    // 0x800004F4: addiu       $a0, $a0, 0xB0
    ctx->r4 = ADD32(ctx->r4, 0XB0);
    // 0x800004F8: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x800004FC: addiu       $a1, $s0, 0xC8
    ctx->r5 = ADD32(ctx->r16, 0XC8);
    // 0x80000500: jal         0x80030610
    // 0x80000504: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_0;
    // 0x80000504: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80000508: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x8000050C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80000510: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80000514: jal         0x80030610
    // 0x80000518: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_1;
    // 0x80000518: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x8000051C: addiu       $a0, $s0, 0x120
    ctx->r4 = ADD32(ctx->r16, 0X120);
    // 0x80000520: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80000524: addiu       $a1, $s0, 0x138
    ctx->r5 = ADD32(ctx->r16, 0X138);
    // 0x80000528: jal         0x80030610
    // 0x8000052C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_2;
    // 0x8000052C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80000530: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80000534: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    // 0x80000538: jal         0x80030610
    // 0x8000053C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_3;
    // 0x8000053C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x80000540: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80000544: addiu       $a1, $s0, 0x90
    ctx->r5 = ADD32(ctx->r16, 0X90);
    // 0x80000548: jal         0x80030610
    // 0x8000054C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_4;
    // 0x8000054C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x80000550: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80000554: addiu       $a1, $s0, 0x20
    ctx->r5 = ADD32(ctx->r16, 0X20);
    // 0x80000558: jal         0x80030610
    // 0x8000055C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_5;
    // 0x8000055C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x80000560: addiu       $a0, $s0, 0x158
    ctx->r4 = ADD32(ctx->r16, 0X158);
    // 0x80000564: addiu       $a1, $s0, 0x170
    ctx->r5 = ADD32(ctx->r16, 0X170);
    // 0x80000568: jal         0x80030610
    // 0x8000056C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_6;
    // 0x8000056C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_6:
    // 0x80000570: addiu       $a0, $s0, 0x190
    ctx->r4 = ADD32(ctx->r16, 0X190);
    // 0x80000574: addiu       $a1, $s0, 0x1A8
    ctx->r5 = ADD32(ctx->r16, 0X1A8);
    // 0x80000578: jal         0x80030610
    // 0x8000057C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_7;
    // 0x8000057C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_7:
    // 0x80000580: jal         0x800346C0
    // 0x80000584: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    LOOKUP_FUNC(0x800346C0)(rdram, ctx);
        goto after_8;
    // 0x80000584: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_8:
    // 0x80000588: lbu         $t9, 0x3F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000058C: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80000590: addiu       $t0, $t0, -0x6670
    ctx->r8 = ADD32(ctx->r8, -0X6670);
    // 0x80000594: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80000598: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8000059C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800005A0: jal         0x80029FA0
    // 0x800005A4: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    LOOKUP_FUNC(0x80029FA0)(rdram, ctx);
        goto after_9;
    // 0x800005A4: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    after_9:
    // 0x800005A8: jal         0x800295D0
    // 0x800005AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800295D0)(rdram, ctx);
        goto after_10;
    // 0x800005AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x800005B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800005B4: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    // 0x800005B8: jal         0x800329F0
    // 0x800005BC: lbu         $a2, 0x43($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X43);
    LOOKUP_FUNC(0x800329F0)(rdram, ctx);
        goto after_11;
    // 0x800005BC: lbu         $a2, 0x43($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X43);
    after_11:
    // 0x800005C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800005C4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800005C8: jal         0x8002FB60
    // 0x800005CC: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    LOOKUP_FUNC(0x8002FB60)(rdram, ctx);
        goto after_12;
    // 0x800005CC: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    after_12:
    // 0x800005D0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800005D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800005D8: jal         0x8002FB60
    // 0x800005DC: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    LOOKUP_FUNC(0x8002FB60)(rdram, ctx);
        goto after_13;
    // 0x800005DC: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    after_13:
    // 0x800005E0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800005E4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800005E8: jal         0x8002FB60
    // 0x800005EC: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    LOOKUP_FUNC(0x8002FB60)(rdram, ctx);
        goto after_14;
    // 0x800005EC: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    after_14:
    // 0x800005F0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800005F4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800005F8: jal         0x8002FB60
    // 0x800005FC: addiu       $a2, $zero, 0x29E
    ctx->r6 = ADD32(0, 0X29E);
    LOOKUP_FUNC(0x8002FB60)(rdram, ctx);
        goto after_15;
    // 0x800005FC: addiu       $a2, $zero, 0x29E
    ctx->r6 = ADD32(0, 0X29E);
    after_15:
    // 0x80000600: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80000604: addiu       $t1, $t1, -0x430
    ctx->r9 = ADD32(ctx->r9, -0X430);
    // 0x80000608: addiu       $a0, $s0, 0x1C8
    ctx->r4 = ADD32(ctx->r16, 0X1C8);
    // 0x8000060C: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80000610: addiu       $t2, $zero, 0x82
    ctx->r10 = ADD32(0, 0X82);
    // 0x80000614: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80000618: addiu       $a2, $a2, 0x774
    ctx->r6 = ADD32(ctx->r6, 0X774);
    // 0x8000061C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80000620: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80000624: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80000628: jal         0x80028260
    // 0x8000062C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80028260)(rdram, ctx);
        goto after_16;
    // 0x8000062C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_16:
    // 0x80000630: jal         0x80034C90
    // 0x80000634: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80034C90)(rdram, ctx);
        goto after_17;
    // 0x80000634: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_17:
    // 0x80000638: lui         $t3, 0x8005
    ctx->r11 = S32(0X8005 << 16);
    // 0x8000063C: addiu       $t3, $t3, 0x1BD0
    ctx->r11 = ADD32(ctx->r11, 0X1BD0);
    // 0x80000640: addiu       $a0, $s0, 0x378
    ctx->r4 = ADD32(ctx->r16, 0X378);
    // 0x80000644: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80000648: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x8000064C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80000650: addiu       $a2, $a2, 0xA5C
    ctx->r6 = ADD32(ctx->r6, 0XA5C);
    // 0x80000654: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80000658: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8000065C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80000660: jal         0x80028260
    // 0x80000664: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80028260)(rdram, ctx);
        goto after_18;
    // 0x80000664: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_18:
    // 0x80000668: jal         0x80034C90
    // 0x8000066C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80034C90)(rdram, ctx);
        goto after_19;
    // 0x8000066C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_19:
    // 0x80000670: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x80000674: addiu       $t5, $t5, 0x3BD0
    ctx->r13 = ADD32(ctx->r13, 0X3BD0);
    // 0x80000678: addiu       $a0, $s0, 0x528
    ctx->r4 = ADD32(ctx->r16, 0X528);
    // 0x8000067C: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80000680: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80000684: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80000688: addiu       $a2, $a2, 0xBF0
    ctx->r6 = ADD32(ctx->r6, 0XBF0);
    // 0x8000068C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80000690: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80000694: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80000698: jal         0x80028260
    // 0x8000069C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80028260)(rdram, ctx);
        goto after_20;
    // 0x8000069C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_20:
    // 0x800006A0: jal         0x80034C90
    // 0x800006A4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80034C90)(rdram, ctx);
        goto after_21;
    // 0x800006A4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_21:
    // 0x800006A8: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x800006AC: addiu       $t7, $t7, 0x5BD0
    ctx->r15 = ADD32(ctx->r15, 0X5BD0);
    // 0x800006B0: addiu       $a0, $s0, 0x6D8
    ctx->r4 = ADD32(ctx->r16, 0X6D8);
    // 0x800006B4: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800006B8: addiu       $t9, $zero, 0x6E
    ctx->r25 = ADD32(0, 0X6E);
    // 0x800006BC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800006C0: addiu       $a2, $a2, 0xDC8
    ctx->r6 = ADD32(ctx->r6, 0XDC8);
    // 0x800006C4: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x800006C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800006CC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800006D0: jal         0x80028260
    // 0x800006D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80028260)(rdram, ctx);
        goto after_22;
    // 0x800006D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_22:
    // 0x800006D8: jal         0x80034C90
    // 0x800006DC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80034C90)(rdram, ctx);
        goto after_23;
    // 0x800006DC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_23:
    // 0x800006E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800006E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800006E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800006EC: jr          $ra
    // 0x800006F0: nop

    return;
    // 0x800006F0: nop

;}
RECOMP_FUNC void FUN_800006f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800006F4: jr          $ra
    // 0x800006F8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    return;
    // 0x800006F8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800006fc(rdram, ctx);
;}
RECOMP_FUNC void FUN_800006fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800006FC: jr          $ra
    // 0x80000700: addiu       $v0, $a0, 0x40
    ctx->r2 = ADD32(ctx->r4, 0X40);
    return;
    // 0x80000700: addiu       $v0, $a0, 0x40
    ctx->r2 = ADD32(ctx->r4, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80000704(rdram, ctx);
;}
RECOMP_FUNC void FUN_80000704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000704: jr          $ra
    // 0x80000708: lw          $v0, 0x898($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X898);
    return;
    // 0x80000708: lw          $v0, 0x898($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X898);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000070c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000070c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000070C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80000710: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000714: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80000718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000071C: addiu       $a0, $a0, 0x528
    ctx->r4 = ADD32(ctx->r4, 0X528);
    // 0x80000720: jal         0x800265F0
    // 0x80000724: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x800265F0)(rdram, ctx);
        goto after_0;
    // 0x80000724: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80000728: jal         0x80026CE0
    // 0x8000072C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80026CE0)(rdram, ctx);
        goto after_1;
    // 0x8000072C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80000730: sw          $zero, 0x88C($s0)
    MEM_W(0X88C, ctx->r16) = 0;
    // 0x80000734: sw          $zero, 0x894($s0)
    MEM_W(0X894, ctx->r16) = 0;
    // 0x80000738: addiu       $a0, $s0, 0x6D8
    ctx->r4 = ADD32(ctx->r16, 0X6D8);
    // 0x8000073C: jal         0x800265F0
    // 0x80000740: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x800265F0)(rdram, ctx);
        goto after_2;
    // 0x80000740: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x80000744: jal         0x80026CE0
    // 0x80000748: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80026CE0)(rdram, ctx);
        goto after_3;
    // 0x80000748: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x8000074C: addiu       $a0, $s0, 0x378
    ctx->r4 = ADD32(ctx->r16, 0X378);
    // 0x80000750: jal         0x800265F0
    // 0x80000754: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x800265F0)(rdram, ctx);
        goto after_4;
    // 0x80000754: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_4:
    // 0x80000758: jal         0x80026CE0
    // 0x8000075C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x80026CE0)(rdram, ctx);
        goto after_5;
    // 0x8000075C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80000760: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80000764: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000768: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000076C: jr          $ra
    // 0x80000770: nop

    return;
    // 0x80000770: nop

;}
RECOMP_FUNC void FUN_80000774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000774: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80000778: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000077C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80000780: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80000784: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000788: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8000078C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80000790: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80000794: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80000798: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000079C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800007A0: lui         $s3, 0x8003
    ctx->r19 = S32(0X8003 << 16);
    // 0x800007A4: lui         $s4, 0x8003
    ctx->r20 = S32(0X8003 << 16);
    // 0x800007A8: addiu       $a3, $a0, 0xB0
    ctx->r7 = ADD32(ctx->r4, 0XB0);
    // 0x800007AC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800007B0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800007B4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800007B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800007BC: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800007C0: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800007C4: addiu       $s4, $s4, 0x7354
    ctx->r20 = ADD32(ctx->r20, 0X7354);
    // 0x800007C8: addiu       $s3, $s3, 0x7350
    ctx->r19 = ADD32(ctx->r19, 0X7350);
    // 0x800007CC: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x800007D0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800007D4: addiu       $s6, $sp, 0x60
    ctx->r22 = ADD32(ctx->r29, 0X60);
    // 0x800007D8: addiu       $s7, $zero, 0x29A
    ctx->r23 = ADD32(0, 0X29A);
    // 0x800007DC: addiu       $fp, $zero, 0x29D
    ctx->r30 = ADD32(0, 0X29D);
L_800007E0:
    // 0x800007E0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_800007E4:
    // 0x800007E4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800007E8: jal         0x800266B0
    // 0x800007EC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_0;
    // 0x800007EC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
    // 0x800007F0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800007F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800007F8: beq         $t6, $s7, L_8000081C
    if (ctx->r14 == ctx->r23) {
        // 0x800007FC: nop
    
            goto L_8000081C;
    }
    // 0x800007FC: nop

    // 0x80000800: beq         $t6, $fp, L_800008A8
    if (ctx->r14 == ctx->r30) {
        // 0x80000804: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800008A8;
    }
    // 0x80000804: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80000808: addiu       $at, $zero, 0x29E
    ctx->r1 = ADD32(0, 0X29E);
    // 0x8000080C: beq         $t6, $at, L_800008CC
    if (ctx->r14 == ctx->r1) {
        // 0x80000810: nop
    
            goto L_800008CC;
    }
    // 0x80000810: nop

    // 0x80000814: b           L_800007E4
    // 0x80000818: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
        goto L_800007E4;
    // 0x80000818: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_8000081C:
    // 0x8000081C: jal         0x80000A0C
    // 0x80000820: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80000A0C)(rdram, ctx);
        goto after_1;
    // 0x80000820: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80000824: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80000828: beql        $v1, $zero, L_800007E4
    if (ctx->r3 == 0) {
        // 0x8000082C: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_800007E4;
    }
    goto skip_0;
    // 0x8000082C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x80000830: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80000834: bne         $v0, $zero, L_8000086C
    if (ctx->r2 != 0) {
        // 0x80000838: slti        $at, $v0, 0x14
        ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
            goto L_8000086C;
    }
    // 0x80000838: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8000083C: jal         0x80034DE0
    // 0x80000840: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    LOOKUP_FUNC(0x80034DE0)(rdram, ctx);
        goto after_2;
    // 0x80000840: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x80000844: jal         0x800295D0
    // 0x80000848: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800295D0)(rdram, ctx);
        goto after_3;
    // 0x80000848: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8000084C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80000850:
    // 0x80000850: jal         0x80002BAC
    // 0x80000854: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80002BAC)(rdram, ctx);
        goto after_4;
    // 0x80000854: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_4:
    // 0x80000858: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000085C: bne         $s0, $s1, L_80000850
    if (ctx->r16 != ctx->r17) {
        // 0x80000860: nop
    
            goto L_80000850;
    }
    // 0x80000860: nop

    // 0x80000864: b           L_8000089C
    // 0x80000868: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
        goto L_8000089C;
    // 0x80000868: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_8000086C:
    // 0x8000086C: bnel        $at, $zero, L_800008A0
    if (ctx->r1 != 0) {
        // 0x80000870: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_800008A0;
    }
    goto skip_1;
    // 0x80000870: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x80000874: bnel        $s5, $v1, L_800008A0
    if (ctx->r21 != ctx->r3) {
        // 0x80000878: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_800008A0;
    }
    goto skip_2;
    // 0x80000878: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x8000087C: jal         0x8002FC30
    // 0x80000880: nop

    LOOKUP_FUNC(0x8002FC30)(rdram, ctx);
        goto after_5;
    // 0x80000880: nop

    after_5:
    // 0x80000884: bne         $v0, $zero, L_80000898
    if (ctx->r2 != 0) {
        // 0x80000888: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80000898;
    }
    // 0x80000888: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8000088C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80000890: b           L_8000089C
    // 0x80000894: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
        goto L_8000089C;
    // 0x80000894: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_80000898:
    // 0x80000898: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_8000089C:
    // 0x8000089C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
L_800008A0:
    // 0x800008A0: b           L_800007E0
    // 0x800008A4: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
        goto L_800007E0;
    // 0x800008A4: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
L_800008A8:
    // 0x800008A8: sw          $s5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r21;
    // 0x800008AC: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x800008B0: jal         0x8000070C
    // 0x800008B4: addiu       $s0, $s2, 0x2
    ctx->r16 = ADD32(ctx->r18, 0X2);
    LOOKUP_FUNC(0x8000070C)(rdram, ctx);
        goto after_6;
    // 0x800008B4: addiu       $s0, $s2, 0x2
    ctx->r16 = ADD32(ctx->r18, 0X2);
    after_6:
    // 0x800008B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800008BC: jal         0x80000A0C
    // 0x800008C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80000A0C)(rdram, ctx);
        goto after_7;
    // 0x800008C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800008C4: b           L_800007E4
    // 0x800008C8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
        goto L_800007E4;
    // 0x800008C8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_800008CC:
    // 0x800008CC: jal         0x80034A70
    // 0x800008D0: nop

    LOOKUP_FUNC(0x80034A70)(rdram, ctx);
        goto after_8;
    // 0x800008D0: nop

    after_8:
    // 0x800008D4: beq         $v0, $zero, L_800007E0
    if (ctx->r2 == 0) {
        // 0x800008D8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800007E0;
    }
    // 0x800008D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800008DC: jal         0x80000F9C
    // 0x800008E0: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    LOOKUP_FUNC(0x80000F9C)(rdram, ctx);
        goto after_9;
    // 0x800008E0: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    after_9:
    // 0x800008E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800008E8: jal         0x80000A0C
    // 0x800008EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80000A0C)(rdram, ctx);
        goto after_10;
    // 0x800008EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x800008F0: b           L_800007E4
    // 0x800008F4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
        goto L_800007E4;
    // 0x800008F4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800008F8: nop

    // 0x800008FC: nop

    // 0x80000900: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80000904: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80000908: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000090C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80000910: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80000914: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80000918: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000091C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80000920: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80000924: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80000928: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000092C: jr          $ra
    // 0x80000930: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80000930: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80000934(rdram, ctx);
;}
RECOMP_FUNC void FUN_80000934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000093C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000940: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80000944: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000948: jal         0x800267F0
    // 0x8000094C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800267F0)(rdram, ctx);
        goto after_0;
    // 0x8000094C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80000950: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80000954: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80000958: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8000095C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80000960: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80000964: lw          $t7, 0x888($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X888);
    // 0x80000968: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000096C: jal         0x800267F0
    // 0x80000970: sw          $a1, 0x888($v1)
    MEM_W(0X888, ctx->r3) = ctx->r5;
    LOOKUP_FUNC(0x800267F0)(rdram, ctx);
        goto after_1;
    // 0x80000970: sw          $a1, 0x888($v1)
    MEM_W(0X888, ctx->r3) = ctx->r5;
    after_1:
    // 0x80000974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000978: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000097C: jr          $ra
    // 0x80000980: nop

    return;
    // 0x80000980: nop

;}
RECOMP_FUNC void FUN_80000984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000984: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80000988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000098C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80000990: lw          $v1, 0x888($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X888);
    // 0x80000994: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80000998: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000099C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800009A0: jal         0x800267F0
    // 0x800009A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x800267F0)(rdram, ctx);
        goto after_0;
    // 0x800009A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800009A8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800009AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800009B0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800009B4: beq         $v1, $zero, L_800009F4
    if (ctx->r3 == 0) {
        // 0x800009B8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800009F4;
    }
    // 0x800009B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800009BC:
    // 0x800009BC: bnel        $v1, $a1, L_800009E8
    if (ctx->r3 != ctx->r5) {
        // 0x800009C0: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_800009E8;
    }
    goto skip_0;
    // 0x800009C0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    skip_0:
    // 0x800009C4: beq         $a2, $zero, L_800009D8
    if (ctx->r6 == 0) {
        // 0x800009C8: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800009D8;
    }
    // 0x800009C8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800009CC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800009D0: b           L_800009F4
    // 0x800009D4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
        goto L_800009F4;
    // 0x800009D4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_800009D8:
    // 0x800009D8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800009DC: b           L_800009F4
    // 0x800009E0: sw          $t8, 0x888($t9)
    MEM_W(0X888, ctx->r25) = ctx->r24;
        goto L_800009F4;
    // 0x800009E0: sw          $t8, 0x888($t9)
    MEM_W(0X888, ctx->r25) = ctx->r24;
    // 0x800009E4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800009E8:
    // 0x800009E8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800009EC: bne         $v1, $zero, L_800009BC
    if (ctx->r3 != 0) {
        // 0x800009F0: nop
    
            goto L_800009BC;
    }
    // 0x800009F0: nop

L_800009F4:
    // 0x800009F4: jal         0x800267F0
    // 0x800009F8: nop

    LOOKUP_FUNC(0x800267F0)(rdram, ctx);
        goto after_1;
    // 0x800009F8: nop

    after_1:
    // 0x800009FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000A00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80000A04: jr          $ra
    // 0x80000A08: nop

    return;
    // 0x80000A08: nop

;}
RECOMP_FUNC void FUN_80000a0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000A0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80000A10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80000A14: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80000A18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80000A1C: lw          $s0, 0x888($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X888);
    // 0x80000A20: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80000A24: beql        $s0, $zero, L_80000A4C
    if (ctx->r16 == 0) {
        // 0x80000A28: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80000A4C;
    }
    goto skip_0;
    // 0x80000A28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80000A2C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_80000A30:
    // 0x80000A30: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80000A34: jal         0x80026300
    // 0x80000A38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_0;
    // 0x80000A38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80000A3C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80000A40: bnel        $s0, $zero, L_80000A30
    if (ctx->r16 != 0) {
        // 0x80000A44: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_80000A30;
    }
    goto skip_1;
    // 0x80000A44: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x80000A48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80000A4C:
    // 0x80000A4C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80000A50: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80000A54: jr          $ra
    // 0x80000A58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80000A58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80000a5c(rdram, ctx);
;}
RECOMP_FUNC void FUN_80000a5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000A5C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80000A60: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80000A64: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80000A68: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80000A6C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80000A70: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80000A74: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80000A78: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80000A7C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80000A80: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80000A84: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80000A88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000A8C: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80000A90: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80000A94: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80000A98: addiu       $s4, $sp, 0x64
    ctx->r20 = ADD32(ctx->r29, 0X64);
    // 0x80000A9C: addiu       $s5, $a0, 0x8
    ctx->r21 = ADD32(ctx->r4, 0X8);
    // 0x80000AA0: addiu       $s6, $sp, 0x60
    ctx->r22 = ADD32(ctx->r29, 0X60);
    // 0x80000AA4: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80000AA8: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x80000AAC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80000AB0:
    // 0x80000AB0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80000AB4: jal         0x800266B0
    // 0x80000AB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_0;
    // 0x80000AB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80000ABC: jal         0x800349E0
    // 0x80000AC0: nop

    LOOKUP_FUNC(0x800349E0)(rdram, ctx);
        goto after_1;
    // 0x80000AC0: nop

    after_1:
    // 0x80000AC4: lw          $s3, 0x88C($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X88C);
    // 0x80000AC8: beql        $s3, $zero, L_80000B04
    if (ctx->r19 == 0) {
        // 0x80000ACC: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_80000B04;
    }
    goto skip_0;
    // 0x80000ACC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    skip_0:
    // 0x80000AD0: jal         0x80029690
    // 0x80000AD4: addiu       $s0, $s2, 0xE8
    ctx->r16 = ADD32(ctx->r18, 0XE8);
    LOOKUP_FUNC(0x80029690)(rdram, ctx);
        goto after_2;
    // 0x80000AD4: addiu       $s0, $s2, 0xE8
    ctx->r16 = ADD32(ctx->r18, 0XE8);
    after_2:
    // 0x80000AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80000ADC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80000AE0: jal         0x800266B0
    // 0x80000AE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_3;
    // 0x80000AE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80000AE8: jal         0x80030FF0
    // 0x80000AEC: addiu       $a0, $s3, 0x10
    ctx->r4 = ADD32(ctx->r19, 0X10);
    LOOKUP_FUNC(0x80030FF0)(rdram, ctx);
        goto after_4;
    // 0x80000AEC: addiu       $a0, $s3, 0x10
    ctx->r4 = ADD32(ctx->r19, 0X10);
    after_4:
    // 0x80000AF0: beq         $v0, $zero, L_80000B00
    if (ctx->r2 == 0) {
        // 0x80000AF4: or          $s1, $fp, $zero
        ctx->r17 = ctx->r30 | 0;
            goto L_80000B00;
    }
    // 0x80000AF4: or          $s1, $fp, $zero
    ctx->r17 = ctx->r30 | 0;
    // 0x80000AF8: b           L_80000B00
    // 0x80000AFC: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
        goto L_80000B00;
    // 0x80000AFC: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
L_80000B00:
    // 0x80000B00: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
L_80000B04:
    // 0x80000B04: addiu       $s0, $s2, 0xE8
    ctx->r16 = ADD32(ctx->r18, 0XE8);
    // 0x80000B08: sw          $t6, 0x890($s2)
    MEM_W(0X890, ctx->r18) = ctx->r14;
    // 0x80000B0C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80000B10: jal         0x80026B0C
    // 0x80000B14: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    LOOKUP_FUNC(0x80026B0C)(rdram, ctx);
        goto after_5;
    // 0x80000B14: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_5:
    // 0x80000B18: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80000B1C: jal         0x80026C9C
    // 0x80000B20: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    LOOKUP_FUNC(0x80026C9C)(rdram, ctx);
        goto after_6;
    // 0x80000B20: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_6:
    // 0x80000B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80000B28: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80000B2C: jal         0x800266B0
    // 0x80000B30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_7;
    // 0x80000B30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80000B34: lw          $t7, 0x894($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X894);
    // 0x80000B38: sw          $zero, 0x890($s2)
    MEM_W(0X890, ctx->r18) = 0;
    // 0x80000B3C: addiu       $a0, $s2, 0x158
    ctx->r4 = ADD32(ctx->r18, 0X158);
    // 0x80000B40: beq         $t7, $zero, L_80000B50
    if (ctx->r15 == 0) {
        // 0x80000B44: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_80000B50;
    }
    // 0x80000B44: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80000B48: jal         0x80026300
    // 0x80000B4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_8;
    // 0x80000B4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
L_80000B50:
    // 0x80000B50: bne         $s1, $s7, L_80000B74
    if (ctx->r17 != ctx->r23) {
        // 0x80000B54: nop
    
            goto L_80000B74;
    }
    // 0x80000B54: nop

    // 0x80000B58: addiu       $s0, $s3, 0x10
    ctx->r16 = ADD32(ctx->r19, 0X10);
    // 0x80000B5C: jal         0x80026B0C
    // 0x80000B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80026B0C)(rdram, ctx);
        goto after_9;
    // 0x80000B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80000B64: jal         0x80026C9C
    // 0x80000B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80026C9C)(rdram, ctx);
        goto after_10;
    // 0x80000B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80000B6C: b           L_80000B8C
    // 0x80000B70: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_80000B8C;
    // 0x80000B70: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_80000B74:
    // 0x80000B74: bne         $s1, $fp, L_80000B88
    if (ctx->r17 != ctx->r30) {
        // 0x80000B78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80000B88;
    }
    // 0x80000B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80000B7C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80000B80: jal         0x80026300
    // 0x80000B84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_11;
    // 0x80000B84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
L_80000B88:
    // 0x80000B88: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_80000B8C:
    // 0x80000B8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80000B90: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80000B94: lw          $a0, 0x50($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X50);
    // 0x80000B98: jal         0x80026300
    // 0x80000B9C: lw          $a1, 0x54($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X54);
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_12;
    // 0x80000B9C: lw          $a1, 0x54($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X54);
    after_12:
    // 0x80000BA0: b           L_80000AB0
    // 0x80000BA4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80000AB0;
    // 0x80000BA4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80000BA8: nop

    // 0x80000BAC: nop

    // 0x80000BB0: nop

    // 0x80000BB4: nop

    // 0x80000BB8: nop

    // 0x80000BBC: nop

    // 0x80000BC0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80000BC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000BC8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80000BCC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80000BD0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80000BD4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80000BD8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80000BDC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80000BE0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80000BE4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80000BE8: jr          $ra
    // 0x80000BEC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80000BEC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80000bf0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80000bf0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000BF0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80000BF4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80000BF8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80000BFC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80000C00: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80000C04: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80000C08: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80000C0C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80000C10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80000C14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000C18: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80000C1C: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x80000C20: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x80000C24: addiu       $s5, $sp, 0x58
    ctx->r21 = ADD32(ctx->r29, 0X58);
    // 0x80000C28: addiu       $s6, $a0, 0x40
    ctx->r22 = ADD32(ctx->r4, 0X40);
    // 0x80000C2C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80000C30:
    // 0x80000C30: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80000C34: jal         0x800266B0
    // 0x80000C38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_0;
    // 0x80000C38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80000C3C: jal         0x80035050
    // 0x80000C40: nop

    LOOKUP_FUNC(0x80035050)(rdram, ctx);
        goto after_1;
    // 0x80000C40: nop

    after_1:
    // 0x80000C44: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80000C48: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80000C4C: beql        $v0, $t7, L_80000C6C
    if (ctx->r2 == ctx->r15) {
        // 0x80000C50: addiu       $s0, $s1, 0x158
        ctx->r16 = ADD32(ctx->r17, 0X158);
            goto L_80000C6C;
    }
    goto skip_0;
    // 0x80000C50: addiu       $s0, $s1, 0x158
    ctx->r16 = ADD32(ctx->r17, 0X158);
    skip_0:
    // 0x80000C54: jal         0x80028F20
    // 0x80000C58: nop

    LOOKUP_FUNC(0x80028F20)(rdram, ctx);
        goto after_2;
    // 0x80000C58: nop

    after_2:
    // 0x80000C5C: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80000C60: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80000C64: bne         $v0, $t9, L_80000CC8
    if (ctx->r2 != ctx->r25) {
        // 0x80000C68: addiu       $s0, $s1, 0x158
        ctx->r16 = ADD32(ctx->r17, 0X158);
            goto L_80000CC8;
    }
    // 0x80000C68: addiu       $s0, $s1, 0x158
    ctx->r16 = ADD32(ctx->r17, 0X158);
L_80000C6C:
    // 0x80000C6C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80000C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80000C74: jal         0x80000934
    // 0x80000C78: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80000934)(rdram, ctx);
        goto after_3;
    // 0x80000C78: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80000C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80000C80: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80000C84: jal         0x800266B0
    // 0x80000C88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_4;
    // 0x80000C88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80000C8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80000C90: jal         0x80000984
    // 0x80000C94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80000984)(rdram, ctx);
        goto after_5;
    // 0x80000C94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x80000C98: jal         0x80035050
    // 0x80000C9C: nop

    LOOKUP_FUNC(0x80035050)(rdram, ctx);
        goto after_6;
    // 0x80000C9C: nop

    after_6:
    // 0x80000CA0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80000CA4: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80000CA8: beql        $v0, $t1, L_80000C6C
    if (ctx->r2 == ctx->r9) {
        // 0x80000CAC: addiu       $s0, $s1, 0x158
        ctx->r16 = ADD32(ctx->r17, 0X158);
            goto L_80000C6C;
    }
    goto skip_1;
    // 0x80000CAC: addiu       $s0, $s1, 0x158
    ctx->r16 = ADD32(ctx->r17, 0X158);
    skip_1:
    // 0x80000CB0: jal         0x80028F20
    // 0x80000CB4: nop

    LOOKUP_FUNC(0x80028F20)(rdram, ctx);
        goto after_7;
    // 0x80000CB4: nop

    after_7:
    // 0x80000CB8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80000CBC: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80000CC0: beql        $v0, $t3, L_80000C6C
    if (ctx->r2 == ctx->r11) {
        // 0x80000CC4: addiu       $s0, $s1, 0x158
        ctx->r16 = ADD32(ctx->r17, 0X158);
            goto L_80000C6C;
    }
    goto skip_2;
    // 0x80000CC4: addiu       $s0, $s1, 0x158
    ctx->r16 = ADD32(ctx->r17, 0X158);
    skip_2:
L_80000CC8:
    // 0x80000CC8: lw          $t4, 0x890($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X890);
    // 0x80000CCC: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80000CD0: addiu       $a0, $s1, 0x158
    ctx->r4 = ADD32(ctx->r17, 0X158);
    // 0x80000CD4: beq         $t4, $zero, L_80000CEC
    if (ctx->r12 == 0) {
        // 0x80000CD8: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80000CEC;
    }
    // 0x80000CD8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80000CDC: sw          $t5, 0x894($s1)
    MEM_W(0X894, ctx->r17) = ctx->r13;
    // 0x80000CE0: jal         0x800266B0
    // 0x80000CE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_8;
    // 0x80000CE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80000CE8: sw          $zero, 0x894($s1)
    MEM_W(0X894, ctx->r17) = 0;
L_80000CEC:
    // 0x80000CEC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80000CF0: addiu       $s0, $s1, 0xE8
    ctx->r16 = ADD32(ctx->r17, 0XE8);
    // 0x80000CF4: addiu       $s4, $s1, 0x120
    ctx->r20 = ADD32(ctx->r17, 0X120);
    // 0x80000CF8: sw          $t6, 0x88C($s1)
    MEM_W(0X88C, ctx->r17) = ctx->r14;
    // 0x80000CFC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80000D00: jal         0x80026B0C
    // 0x80000D04: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    LOOKUP_FUNC(0x80026B0C)(rdram, ctx);
        goto after_9;
    // 0x80000D04: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_9:
    // 0x80000D08: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80000D0C: jal         0x80026C9C
    // 0x80000D10: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    LOOKUP_FUNC(0x80026C9C)(rdram, ctx);
        goto after_10;
    // 0x80000D10: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_10:
    // 0x80000D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80000D18: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80000D1C: jal         0x800266B0
    // 0x80000D20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_11;
    // 0x80000D20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80000D24: sw          $zero, 0x88C($s1)
    MEM_W(0X88C, ctx->r17) = 0;
    // 0x80000D28: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80000D2C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80000D30: jal         0x800266B0
    // 0x80000D34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_12;
    // 0x80000D34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80000D38: lw          $t7, 0x8A0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8A0);
    // 0x80000D3C: beql        $t7, $zero, L_80000D54
    if (ctx->r15 == 0) {
        // 0x80000D40: lw          $t8, 0x58($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X58);
            goto L_80000D54;
    }
    goto skip_3;
    // 0x80000D40: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    skip_3:
    // 0x80000D44: jal         0x800295D0
    // 0x80000D48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800295D0)(rdram, ctx);
        goto after_13;
    // 0x80000D48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80000D4C: sw          $zero, 0x8A0($s1)
    MEM_W(0X8A0, ctx->r17) = 0;
    // 0x80000D50: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
L_80000D54:
    // 0x80000D54: addiu       $a0, $s1, 0x78
    ctx->r4 = ADD32(ctx->r17, 0X78);
    // 0x80000D58: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80000D5C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80000D60: andi        $t0, $t9, 0x40
    ctx->r8 = ctx->r25 & 0X40;
    // 0x80000D64: beql        $t0, $zero, L_80000D84
    if (ctx->r8 == 0) {
        // 0x80000D68: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_80000D84;
    }
    goto skip_4;
    // 0x80000D68: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_4:
    // 0x80000D6C: jal         0x80026300
    // 0x80000D70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_14;
    // 0x80000D70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x80000D74: lw          $t1, 0x89C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X89C);
    // 0x80000D78: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80000D7C: sw          $t2, 0x89C($s1)
    MEM_W(0X89C, ctx->r17) = ctx->r10;
    // 0x80000D80: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
L_80000D84:
    // 0x80000D84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80000D88: lw          $a0, 0x50($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X50);
    // 0x80000D8C: jal         0x80026300
    // 0x80000D90: lw          $a1, 0x54($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X54);
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_15;
    // 0x80000D90: lw          $a1, 0x54($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X54);
    after_15:
    // 0x80000D94: b           L_80000C30
    // 0x80000D98: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
        goto L_80000C30;
    // 0x80000D98: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80000D9C: nop

    // 0x80000DA0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80000DA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000DA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80000DAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80000DB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80000DB4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80000DB8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80000DBC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80000DC0: jr          $ra
    // 0x80000DC4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80000DC4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80000dc8(rdram, ctx);
;}
RECOMP_FUNC void FUN_80000dc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000DC8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80000DCC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80000DD0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80000DD4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80000DD8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80000DDC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80000DE0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80000DE4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80000DE8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80000DEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000DF0: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80000DF4: addiu       $s2, $sp, 0x48
    ctx->r18 = ADD32(ctx->r29, 0X48);
    // 0x80000DF8: addiu       $s4, $sp, 0x54
    ctx->r20 = ADD32(ctx->r29, 0X54);
    // 0x80000DFC: addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // 0x80000E00: addiu       $s6, $a0, 0x78
    ctx->r22 = ADD32(ctx->r4, 0X78);
    // 0x80000E04: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80000E08:
    // 0x80000E08: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80000E0C: jal         0x800266B0
    // 0x80000E10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_0;
    // 0x80000E10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80000E14: lw          $t6, 0x8A4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X8A4);
    // 0x80000E18: bnel        $t6, $zero, L_80000E88
    if (ctx->r14 != 0) {
        // 0x80000E1C: sw          $zero, 0x8A4($s3)
        MEM_W(0X8A4, ctx->r19) = 0;
            goto L_80000E88;
    }
    goto skip_0;
    // 0x80000E1C: sw          $zero, 0x8A4($s3)
    MEM_W(0X8A4, ctx->r19) = 0;
    skip_0:
    // 0x80000E20: jal         0x80035050
    // 0x80000E24: nop

    LOOKUP_FUNC(0x80035050)(rdram, ctx);
        goto after_1;
    // 0x80000E24: nop

    after_1:
    // 0x80000E28: jal         0x80028F20
    // 0x80000E2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80028F20)(rdram, ctx);
        goto after_2;
    // 0x80000E2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_2:
    // 0x80000E30: beq         $v0, $s0, L_80000E88
    if (ctx->r2 == ctx->r16) {
        // 0x80000E34: addiu       $s1, $s3, 0x190
        ctx->r17 = ADD32(ctx->r19, 0X190);
            goto L_80000E88;
    }
    // 0x80000E34: addiu       $s1, $s3, 0x190
    ctx->r17 = ADD32(ctx->r19, 0X190);
    // 0x80000E38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80000E3C:
    // 0x80000E3C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80000E40: jal         0x80000934
    // 0x80000E44: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80000934)(rdram, ctx);
        goto after_3;
    // 0x80000E44: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_3:
    // 0x80000E48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80000E4C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80000E50: jal         0x800266B0
    // 0x80000E54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_4;
    // 0x80000E54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80000E58: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80000E5C: jal         0x80000984
    // 0x80000E60: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80000984)(rdram, ctx);
        goto after_5;
    // 0x80000E60: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x80000E64: jal         0x80035050
    // 0x80000E68: nop

    LOOKUP_FUNC(0x80035050)(rdram, ctx);
        goto after_6;
    // 0x80000E68: nop

    after_6:
    // 0x80000E6C: jal         0x80028F20
    // 0x80000E70: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80028F20)(rdram, ctx);
        goto after_7;
    // 0x80000E70: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_7:
    // 0x80000E74: bnel        $v0, $s0, L_80000E3C
    if (ctx->r2 != ctx->r16) {
        // 0x80000E78: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80000E3C;
    }
    goto skip_1;
    // 0x80000E78: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_1:
    // 0x80000E7C: b           L_80000E8C
    // 0x80000E80: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
        goto L_80000E8C;
    // 0x80000E80: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80000E84: sw          $zero, 0x8A4($s3)
    MEM_W(0X8A4, ctx->r19) = 0;
L_80000E88:
    // 0x80000E88: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
L_80000E8C:
    // 0x80000E8C: jal         0x80030DC0
    // 0x80000E90: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    LOOKUP_FUNC(0x80030DC0)(rdram, ctx);
        goto after_8;
    // 0x80000E90: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    after_8:
    // 0x80000E94: b           L_80000E08
    // 0x80000E98: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
        goto L_80000E08;
    // 0x80000E98: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80000E9C: nop

    // 0x80000EA0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80000EA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000EA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80000EAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80000EB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80000EB4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80000EB8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80000EBC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80000EC0: jr          $ra
    // 0x80000EC4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80000EC4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80000ec8(rdram, ctx);
;}
RECOMP_FUNC void FUN_80000ec8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000EC8: jr          $ra
    // 0x80000ECC: lw          $v0, 0x89C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X89C);
    return;
    // 0x80000ECC: lw          $v0, 0x89C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X89C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80000ed0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80000ed0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000ED8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80000EDC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80000EE0: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x80000EE4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80000EE8: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80000EEC: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x80000EF0: beql        $t8, $zero, L_80000F5C
    if (ctx->r24 == 0) {
        // 0x80000EF4: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80000F5C;
    }
    goto skip_0;
    // 0x80000EF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80000EF8: lh          $t9, -0x6CAA($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6CAA);
    // 0x80000EFC: beql        $t9, $zero, L_80000F18
    if (ctx->r25 == 0) {
        // 0x80000F00: lw          $t0, 0x898($a3)
        ctx->r8 = MEM_W(ctx->r7, 0X898);
            goto L_80000F18;
    }
    goto skip_1;
    // 0x80000F00: lw          $t0, 0x898($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X898);
    skip_1:
    // 0x80000F04: lw          $v0, 0x898($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X898);
    // 0x80000F08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80000F0C: bne         $v0, $at, L_80000F30
    if (ctx->r2 != ctx->r1) {
        // 0x80000F10: xori        $t3, $v0, 0x1
        ctx->r11 = ctx->r2 ^ 0X1;
            goto L_80000F30;
    }
    // 0x80000F10: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80000F14: lw          $t0, 0x898($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X898);
L_80000F18:
    // 0x80000F18: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80000F1C: sltiu       $at, $t1, 0x3
    ctx->r1 = ctx->r9 < 0X3 ? 1 : 0;
    // 0x80000F20: bne         $at, $zero, L_80000F34
    if (ctx->r1 != 0) {
        // 0x80000F24: sw          $t1, 0x898($a3)
        MEM_W(0X898, ctx->r7) = ctx->r9;
            goto L_80000F34;
    }
    // 0x80000F24: sw          $t1, 0x898($a3)
    MEM_W(0X898, ctx->r7) = ctx->r9;
    // 0x80000F28: b           L_80000F34
    // 0x80000F2C: sw          $zero, 0x898($a3)
    MEM_W(0X898, ctx->r7) = 0;
        goto L_80000F34;
    // 0x80000F2C: sw          $zero, 0x898($a3)
    MEM_W(0X898, ctx->r7) = 0;
L_80000F30:
    // 0x80000F30: sw          $t3, 0x898($a3)
    MEM_W(0X898, ctx->r7) = ctx->r11;
L_80000F34:
    // 0x80000F34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000F38: jal         0x800267F0
    // 0x80000F3C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x800267F0)(rdram, ctx);
        goto after_0;
    // 0x80000F3C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80000F40: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80000F44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80000F48: lw          $t4, 0x89C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X89C);
    // 0x80000F4C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80000F50: jal         0x800267F0
    // 0x80000F54: sw          $t5, 0x89C($a3)
    MEM_W(0X89C, ctx->r7) = ctx->r13;
    LOOKUP_FUNC(0x800267F0)(rdram, ctx);
        goto after_1;
    // 0x80000F54: sw          $t5, 0x89C($a3)
    MEM_W(0X89C, ctx->r7) = ctx->r13;
    after_1:
    // 0x80000F58: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80000F5C:
    // 0x80000F5C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80000F60: jal         0x80026300
    // 0x80000F64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80026300)(rdram, ctx);
        goto after_2;
    // 0x80000F64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80000F68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000F6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000F70: jr          $ra
    // 0x80000F74: nop

    return;
    // 0x80000F74: nop

    // 0x80000F78: lw          $t6, 0x89C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X89C);
    // 0x80000F7C: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x80000F80: jr          $ra
    // 0x80000F84: sw          $t7, 0x89C($a0)
    MEM_W(0X89C, ctx->r4) = ctx->r15;
    return;
    // 0x80000F84: sw          $t7, 0x89C($a0)
    MEM_W(0X89C, ctx->r4) = ctx->r15;
    // 0x80000F88: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80000F8C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80000F90: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80000F94: jr          $ra
    // 0x80000F98: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x80000F98: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80000f9c(rdram, ctx);
;}
RECOMP_FUNC void FUN_80000f9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000F9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80000FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000FA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80000FA8: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80000FAC: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x80000FB0: addiu       $a2, $a2, 0x7358
    ctx->r6 = ADD32(ctx->r6, 0X7358);
    // 0x80000FB4: addiu       $a1, $a1, -0x4BEC
    ctx->r5 = ADD32(ctx->r5, -0X4BEC);
    // 0x80000FB8: jal         0x80001010
    // 0x80000FBC: lw          $a0, 0x120($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X120);
    LOOKUP_FUNC(0x80001010)(rdram, ctx);
        goto after_0;
    // 0x80000FBC: lw          $a0, 0x120($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X120);
    after_0:
    // 0x80000FC0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80000FC4: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80000FC8: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x80000FCC: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80000FD0: lw          $a0, 0xF8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XF8);
    // 0x80000FD4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80000FD8: addiu       $a2, $a2, 0x74A8
    ctx->r6 = ADD32(ctx->r6, 0X74A8);
    // 0x80000FDC: jal         0x80001010
    // 0x80000FE0: addiu       $a1, $a1, -0x4BE4
    ctx->r5 = ADD32(ctx->r5, -0X4BE4);
    LOOKUP_FUNC(0x80001010)(rdram, ctx);
        goto after_1;
    // 0x80000FE0: addiu       $a1, $a1, -0x4BE4
    ctx->r5 = ADD32(ctx->r5, -0X4BE4);
    after_1:
    // 0x80000FE4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80000FE8: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80000FEC: lui         $a2, 0x8003
    ctx->r6 = S32(0X8003 << 16);
    // 0x80000FF0: addiu       $a2, $a2, 0x761C
    ctx->r6 = ADD32(ctx->r6, 0X761C);
    // 0x80000FF4: addiu       $a1, $a1, -0x4A48
    ctx->r5 = ADD32(ctx->r5, -0X4A48);
    // 0x80000FF8: jal         0x80001010
    // 0x80000FFC: lw          $a0, 0x10C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10C);
    LOOKUP_FUNC(0x80001010)(rdram, ctx);
        goto after_2;
    // 0x80000FFC: lw          $a0, 0x10C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10C);
    after_2:
    // 0x80001000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001004: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80001008: jr          $ra
    // 0x8000100C: nop

    return;
    // 0x8000100C: nop

;}
RECOMP_FUNC void FUN_80001010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001010: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80001014: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80001018: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000101C: beq         $v1, $zero, L_80001050
    if (ctx->r3 == 0) {
        // 0x80001020: nop
    
            goto L_80001050;
    }
    // 0x80001020: nop

    // 0x80001024: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
L_80001028:
    // 0x80001028: and         $t7, $v1, $a0
    ctx->r15 = ctx->r3 & ctx->r4;
    // 0x8000102C: bnel        $t6, $t7, L_80001044
    if (ctx->r14 != ctx->r15) {
        // 0x80001030: lw          $v1, 0xC($a2)
        ctx->r3 = MEM_W(ctx->r6, 0XC);
            goto L_80001044;
    }
    goto skip_0;
    // 0x80001030: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
    skip_0:
    // 0x80001034: beql        $v0, $zero, L_80001044
    if (ctx->r2 == 0) {
        // 0x80001038: lw          $v1, 0xC($a2)
        ctx->r3 = MEM_W(ctx->r6, 0XC);
            goto L_80001044;
    }
    goto skip_1;
    // 0x80001038: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
    skip_1:
    // 0x8000103C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80001040: lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC);
L_80001044:
    // 0x80001044: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80001048: bnel        $v1, $zero, L_80001028
    if (ctx->r3 != 0) {
        // 0x8000104C: lw          $t6, 0x4($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X4);
            goto L_80001028;
    }
    goto skip_2;
    // 0x8000104C: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    skip_2:
L_80001050:
    // 0x80001050: jr          $ra
    // 0x80001054: nop

    return;
    // 0x80001054: nop

    // 0x80001058: nop

    // 0x8000105C: nop

;}
RECOMP_FUNC void FUN_80001060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001060: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x80001064: jr          $ra
    // 0x80001068: lhu         $v0, 0x7758($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7758);
    return;
    // 0x80001068: lhu         $v0, 0x7758($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7758);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000106c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000106c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000106C: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x80001070: jr          $ra
    // 0x80001074: lhu         $v0, 0x7754($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7754);
    return;
    // 0x80001074: lhu         $v0, 0x7754($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7754);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80001078(rdram, ctx);
;}
RECOMP_FUNC void FUN_80001078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001078: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000107C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80001080: jal         0x80028B10
    // 0x80001084: nop

    LOOKUP_FUNC(0x80028B10)(rdram, ctx);
        goto after_0;
    // 0x80001084: nop

    after_0:
    // 0x80001088: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8000108C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80001090: bne         $t6, $zero, L_800010A0
    if (ctx->r14 != 0) {
        // 0x80001094: nop
    
            goto L_800010A0;
    }
    // 0x80001094: nop

L_80001098:
    // 0x80001098: b           L_80001098
    pause_self(rdram);
    // 0x8000109C: nop

L_800010A0:
    // 0x800010A0: jal         0x8002C0B0
    // 0x800010A4: nop

    LOOKUP_FUNC(0x8002C0B0)(rdram, ctx);
        goto after_1;
    // 0x800010A4: nop

    after_1:
    // 0x800010A8: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x800010AC: bne         $v0, $at, L_800010C8
    if (ctx->r2 != ctx->r1) {
        // 0x800010B0: lui         $a0, 0x8005
        ctx->r4 = S32(0X8005 << 16);
            goto L_800010C8;
    }
    // 0x800010B0: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800010B4: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x800010B8: sh          $zero, 0x7754($at)
    MEM_H(0X7754, ctx->r1) = 0;
    // 0x800010BC: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x800010C0: b           L_800010DC
    // 0x800010C4: sh          $zero, 0x7758($at)
    MEM_H(0X7758, ctx->r1) = 0;
        goto L_800010DC;
    // 0x800010C4: sh          $zero, 0x7758($at)
    MEM_H(0X7758, ctx->r1) = 0;
L_800010C8:
    // 0x800010C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800010CC: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x800010D0: sh          $v0, 0x7754($at)
    MEM_H(0X7754, ctx->r1) = ctx->r2;
    // 0x800010D4: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x800010D8: sh          $v0, 0x7758($at)
    MEM_H(0X7758, ctx->r1) = ctx->r2;
L_800010DC:
    // 0x800010DC: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x800010E0: addiu       $t7, $t7, -0x6280
    ctx->r15 = ADD32(ctx->r15, -0X6280);
    // 0x800010E4: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800010E8: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x800010EC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800010F0: addiu       $a2, $a2, 0x1124
    ctx->r6 = ADD32(ctx->r6, 0X1124);
    // 0x800010F4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800010F8: addiu       $a0, $a0, 0x7BD0
    ctx->r4 = ADD32(ctx->r4, 0X7BD0);
    // 0x800010FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80001100: jal         0x80028260
    // 0x80001104: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80028260)(rdram, ctx);
        goto after_2;
    // 0x80001104: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80001108: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8000110C: jal         0x80034C90
    // 0x80001110: addiu       $a0, $a0, 0x7BD0
    ctx->r4 = ADD32(ctx->r4, 0X7BD0);
    LOOKUP_FUNC(0x80034C90)(rdram, ctx);
        goto after_3;
    // 0x80001110: addiu       $a0, $a0, 0x7BD0
    ctx->r4 = ADD32(ctx->r4, 0X7BD0);
    after_3:
    // 0x80001114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80001118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000111C: jr          $ra
    // 0x80001120: nop

    return;
    // 0x80001120: nop

;}
RECOMP_FUNC void FUN_80001124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001124: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000112C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80001130: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80001134: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80001138: addiu       $a2, $a2, -0x40B8
    ctx->r6 = ADD32(ctx->r6, -0X40B8);
    // 0x8000113C: addiu       $a1, $a1, -0x40D0
    ctx->r5 = ADD32(ctx->r5, -0X40D0);
    // 0x80001140: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80001144: jal         0x8002AC60
    // 0x80001148: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x8002AC60)(rdram, ctx);
        goto after_0;
    // 0x80001148: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_0:
    // 0x8000114C: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80001150: addiu       $t6, $t6, -0x40D0
    ctx->r14 = ADD32(ctx->r14, -0X40D0);
    // 0x80001154: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80001158: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x8000115C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80001160: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80001164: addiu       $a2, $a2, 0x11B0
    ctx->r6 = ADD32(ctx->r6, 0X11B0);
    // 0x80001168: addiu       $a0, $a0, -0x6280
    ctx->r4 = ADD32(ctx->r4, -0X6280);
    // 0x8000116C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80001170: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80001174: jal         0x80028260
    // 0x80001178: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x80028260)(rdram, ctx);
        goto after_1;
    // 0x80001178: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8000117C: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80001180: jal         0x80034C90
    // 0x80001184: addiu       $a0, $a0, -0x6280
    ctx->r4 = ADD32(ctx->r4, -0X6280);
    LOOKUP_FUNC(0x80034C90)(rdram, ctx);
        goto after_2;
    // 0x80001184: addiu       $a0, $a0, -0x6280
    ctx->r4 = ADD32(ctx->r4, -0X6280);
    after_2:
    // 0x80001188: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000118C: jal         0x80030B60
    // 0x80001190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80030B60)(rdram, ctx);
        goto after_3;
    // 0x80001190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_80001194:
    // 0x80001194: b           L_80001194
    pause_self(rdram);
    // 0x80001198: nop

    // 0x8000119C: nop

    // 0x800011A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800011A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800011A8: jr          $ra
    // 0x800011AC: nop

    return;
    // 0x800011AC: nop

;}
RECOMP_FUNC void FUN_800011b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800011B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800011B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800011BC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800011C0: jal         0x80001E70
    // 0x800011C4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    LOOKUP_FUNC(0x80001E70)(rdram, ctx);
        goto after_0;
    // 0x800011C4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    after_0:
    // 0x800011C8: jal         0x80007B70
    // 0x800011CC: nop

    LOOKUP_FUNC(0x80007B70)(rdram, ctx);
        goto after_1;
    // 0x800011CC: nop

    after_1:
    // 0x800011D0: jal         0x80001BC0
    // 0x800011D4: nop

    LOOKUP_FUNC(0x80001BC0)(rdram, ctx);
        goto after_2;
    // 0x800011D4: nop

    after_2:
    // 0x800011D8: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x800011DC: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x800011E0: addiu       $a1, $a1, -0x3D80
    ctx->r5 = ADD32(ctx->r5, -0X3D80);
    // 0x800011E4: addiu       $a0, $a0, -0x3D98
    ctx->r4 = ADD32(ctx->r4, -0X3D98);
    // 0x800011E8: jal         0x80030610
    // 0x800011EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_3;
    // 0x800011EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800011F0: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x800011F4: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x800011F8: addiu       $a1, $a1, -0x3D60
    ctx->r5 = ADD32(ctx->r5, -0X3D60);
    // 0x800011FC: addiu       $a0, $a0, -0x3D78
    ctx->r4 = ADD32(ctx->r4, -0X3D78);
    // 0x80001200: jal         0x80030610
    // 0x80001204: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_4;
    // 0x80001204: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_4:
    // 0x80001208: jal         0x80001060
    // 0x8000120C: nop

    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_5;
    // 0x8000120C: nop

    after_5:
    // 0x80001210: jal         0x80001060
    // 0x80001214: nop

    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_6;
    // 0x80001214: nop

    after_6:
    // 0x80001218: beq         $v0, $zero, L_8000126C
    if (ctx->r2 == 0) {
        // 0x8000121C: lui         $t6, 0x8000
        ctx->r14 = S32(0X8000 << 16);
            goto L_8000126C;
    }
    // 0x8000121C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80001220: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80001224: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001228: lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // 0x8000122C: bne         $t6, $at, L_80001254
    if (ctx->r14 != ctx->r1) {
        // 0x80001230: addiu       $s0, $s0, -0x3B50
        ctx->r16 = ADD32(ctx->r16, -0X3B50);
            goto L_80001254;
    }
    // 0x80001230: addiu       $s0, $s0, -0x3B50
    ctx->r16 = ADD32(ctx->r16, -0X3B50);
    // 0x80001234: lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // 0x80001238: addiu       $s0, $s0, -0x3B50
    ctx->r16 = ADD32(ctx->r16, -0X3B50);
    // 0x8000123C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80001240: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    // 0x80001244: jal         0x80000460
    // 0x80001248: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80000460)(rdram, ctx);
        goto after_7;
    // 0x80001248: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x8000124C: b           L_800012B4
    // 0x80001250: nop

        goto L_800012B4;
    // 0x80001250: nop

L_80001254:
    // 0x80001254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80001258: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8000125C: jal         0x80000460
    // 0x80001260: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80000460)(rdram, ctx);
        goto after_8;
    // 0x80001260: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80001264: b           L_800012B4
    // 0x80001268: nop

        goto L_800012B4;
    // 0x80001268: nop

L_8000126C:
    // 0x8000126C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80001270: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80001274: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001278: lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // 0x8000127C: bne         $t7, $at, L_800012A4
    if (ctx->r15 != ctx->r1) {
        // 0x80001280: addiu       $s0, $s0, -0x3B50
        ctx->r16 = ADD32(ctx->r16, -0X3B50);
            goto L_800012A4;
    }
    // 0x80001280: addiu       $s0, $s0, -0x3B50
    ctx->r16 = ADD32(ctx->r16, -0X3B50);
    // 0x80001284: lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // 0x80001288: addiu       $s0, $s0, -0x3B50
    ctx->r16 = ADD32(ctx->r16, -0X3B50);
    // 0x8000128C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80001290: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80001294: jal         0x80000460
    // 0x80001298: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80000460)(rdram, ctx);
        goto after_9;
    // 0x80001298: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x8000129C: b           L_800012B4
    // 0x800012A0: nop

        goto L_800012B4;
    // 0x800012A0: nop

L_800012A4:
    // 0x800012A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800012A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800012AC: jal         0x80000460
    // 0x800012B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80000460)(rdram, ctx);
        goto after_10;
    // 0x800012B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
L_800012B4:
    // 0x800012B4: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x800012B8: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x800012BC: sw          $zero, 0x7730($at)
    MEM_W(0X7730, ctx->r1) = 0;
    // 0x800012C0: addiu       $a2, $a2, -0x3D78
    ctx->r6 = ADD32(ctx->r6, -0X3D78);
    // 0x800012C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800012C8: jal         0x80000934
    // 0x800012CC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80000934)(rdram, ctx);
        goto after_11;
    // 0x800012CC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_11:
    // 0x800012D0: jal         0x800006FC
    // 0x800012D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800006FC)(rdram, ctx);
        goto after_12;
    // 0x800012D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800012D8: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x800012DC: jal         0x80001060
    // 0x800012E0: sw          $v0, -0x3288($at)
    MEM_W(-0X3288, ctx->r1) = ctx->r2;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_13;
    // 0x800012E0: sw          $v0, -0x3288($at)
    MEM_W(-0X3288, ctx->r1) = ctx->r2;
    after_13:
    // 0x800012E4: beq         $v0, $zero, L_800012FC
    if (ctx->r2 == 0) {
        // 0x800012E8: nop
    
            goto L_800012FC;
    }
    // 0x800012E8: nop

    // 0x800012EC: jal         0x80032890
    // 0x800012F0: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    LOOKUP_FUNC(0x80032890)(rdram, ctx);
        goto after_14;
    // 0x800012F0: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    after_14:
    // 0x800012F4: b           L_80001304
    // 0x800012F8: nop

        goto L_80001304;
    // 0x800012F8: nop

L_800012FC:
    // 0x800012FC: jal         0x80032890
    // 0x80001300: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    LOOKUP_FUNC(0x80032890)(rdram, ctx);
        goto after_15;
    // 0x80001300: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_15:
L_80001304:
    // 0x80001304: jal         0x800020B0
    // 0x80001308: nop

    LOOKUP_FUNC(0x800020B0)(rdram, ctx);
        goto after_16;
    // 0x80001308: nop

    after_16:
    // 0x8000130C: jal         0x80016DF0
    // 0x80001310: nop

    LOOKUP_FUNC(0x80016DF0)(rdram, ctx);
        goto after_17;
    // 0x80001310: nop

    after_17:
    // 0x80001314: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80001318: addiu       $a1, $a1, -0x1640
    ctx->r5 = ADD32(ctx->r5, -0X1640);
    // 0x8000131C: jal         0x8000469C
    // 0x80001320: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_18;
    // 0x80001320: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_18:
    // 0x80001324: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x80001328: addiu       $a1, $a1, 0x41C0
    ctx->r5 = ADD32(ctx->r5, 0X41C0);
    // 0x8000132C: jal         0x8000469C
    // 0x80001330: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_19;
    // 0x80001330: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_19:
    // 0x80001334: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x80001338: addiu       $s0, $s0, -0x800
    ctx->r16 = ADD32(ctx->r16, -0X800);
    // 0x8000133C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80001340: jal         0x8000469C
    // 0x80001344: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_20;
    // 0x80001344: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_20:
    // 0x80001348: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8000134C: addiu       $a1, $a1, 0x51C0
    ctx->r5 = ADD32(ctx->r5, 0X51C0);
    // 0x80001350: jal         0x8000469C
    // 0x80001354: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_21;
    // 0x80001354: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_21:
    // 0x80001358: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8000135C: addiu       $a1, $a1, 0x7830
    ctx->r5 = ADD32(ctx->r5, 0X7830);
    // 0x80001360: jal         0x8000469C
    // 0x80001364: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_22;
    // 0x80001364: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_22:
    // 0x80001368: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8000136C: addiu       $a0, $a0, -0xE60
    ctx->r4 = ADD32(ctx->r4, -0XE60);
    // 0x80001370: jal         0x8001F204
    // 0x80001374: subu        $a1, $s0, $a0
    ctx->r5 = SUB32(ctx->r16, ctx->r4);
    LOOKUP_FUNC(0x8001F204)(rdram, ctx);
        goto after_23;
    // 0x80001374: subu        $a1, $s0, $a0
    ctx->r5 = SUB32(ctx->r16, ctx->r4);
    after_23:
    // 0x80001378: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8000137C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80001380: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80001384: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80001388: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8000138C: jal         0x80005444
    // 0x80001390: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x80005444)(rdram, ctx);
        goto after_24;
    // 0x80001390: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_24:
    // 0x80001394: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80001398: jal         0x80005624
    // 0x8000139C: addiu       $a0, $a0, 0x2DD0
    ctx->r4 = ADD32(ctx->r4, 0X2DD0);
    LOOKUP_FUNC(0x80005624)(rdram, ctx);
        goto after_25;
    // 0x8000139C: addiu       $a0, $a0, 0x2DD0
    ctx->r4 = ADD32(ctx->r4, 0X2DD0);
    after_25:
    // 0x800013A0: jal         0x80133AAC
    // 0x800013A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80133AAC)(rdram, ctx);
        goto after_26;
    // 0x800013A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_26:
    // 0x800013A8: lui         $s0, 0x8003
    ctx->r16 = S32(0X8003 << 16);
    // 0x800013AC: addiu       $s0, $s0, 0x7748
    ctx->r16 = ADD32(ctx->r16, 0X7748);
L_800013B0:
    // 0x800013B0: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x800013B4: addiu       $a0, $a0, -0x3D78
    ctx->r4 = ADD32(ctx->r4, -0X3D78);
    // 0x800013B8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800013BC: jal         0x800266B0
    // 0x800013C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_27;
    // 0x800013C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_27:
    // 0x800013C4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800013C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800013CC: lh          $v1, 0x0($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X0);
    // 0x800013D0: beq         $v1, $at, L_800013F4
    if (ctx->r3 == ctx->r1) {
        // 0x800013D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800013F4;
    }
    // 0x800013D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800013D8: beq         $v1, $at, L_800013B0
    if (ctx->r3 == ctx->r1) {
        // 0x800013DC: nop
    
            goto L_800013B0;
    }
    // 0x800013DC: nop

    // 0x800013E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800013E4: beq         $v1, $at, L_80001428
    if (ctx->r3 == ctx->r1) {
        // 0x800013E8: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80001428;
    }
    // 0x800013E8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800013EC: b           L_800013B0
    // 0x800013F0: nop

        goto L_800013B0;
    // 0x800013F0: nop

L_800013F4:
    // 0x800013F4: jal         0x8000290C
    // 0x800013F8: nop

    LOOKUP_FUNC(0x8000290C)(rdram, ctx);
        goto after_28;
    // 0x800013F8: nop

    after_28:
    // 0x800013FC: lhu         $t0, 0x0($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X0);
    // 0x80001400: bne         $t0, $zero, L_80001418
    if (ctx->r8 != 0) {
        // 0x80001404: nop
    
            goto L_80001418;
    }
    // 0x80001404: nop

    // 0x80001408: jal         0x80001454
    // 0x8000140C: nop

    LOOKUP_FUNC(0x80001454)(rdram, ctx);
        goto after_29;
    // 0x8000140C: nop

    after_29:
    // 0x80001410: b           L_800013B0
    // 0x80001414: nop

        goto L_800013B0;
    // 0x80001414: nop

L_80001418:
    // 0x80001418: jal         0x80001BB0
    // 0x8000141C: nop

    LOOKUP_FUNC(0x80001BB0)(rdram, ctx);
        goto after_30;
    // 0x8000141C: nop

    after_30:
    // 0x80001420: b           L_800013B0
    // 0x80001424: nop

        goto L_800013B0;
    // 0x80001424: nop

L_80001428:
    // 0x80001428: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x8000142C: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x80001430: b           L_800013B0
    // 0x80001434: sh          $zero, 0x774C($at)
    MEM_H(0X774C, ctx->r1) = 0;
        goto L_800013B0;
    // 0x80001434: sh          $zero, 0x774C($at)
    MEM_H(0X774C, ctx->r1) = 0;
    // 0x80001438: nop

    // 0x8000143C: nop

    // 0x80001440: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001444: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80001448: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000144C: jr          $ra
    // 0x80001450: nop

    return;
    // 0x80001450: nop

;}
RECOMP_FUNC void FUN_80001454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001454: lui         $t2, 0x8003
    ctx->r10 = S32(0X8003 << 16);
    // 0x80001458: addiu       $t2, $t2, 0x7730
    ctx->r10 = ADD32(ctx->r10, 0X7730);
    // 0x8000145C: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x80001460: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80001464: addiu       $t0, $t0, -0x6D50
    ctx->r8 = ADD32(ctx->r8, -0X6D50);
    // 0x80001468: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000146C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80001470: bne         $v1, $zero, L_8000148C
    if (ctx->r3 != 0) {
        // 0x80001474: sw          $zero, 0x42D0($t0)
        MEM_W(0X42D0, ctx->r8) = 0;
            goto L_8000148C;
    }
    // 0x80001474: sw          $zero, 0x42D0($t0)
    MEM_W(0X42D0, ctx->r8) = 0;
    // 0x80001478: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8000147C: lhu         $t6, 0x7750($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X7750);
    // 0x80001480: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80001484: bne         $t1, $t6, L_8000161C
    if (ctx->r9 != ctx->r14) {
        // 0x80001488: nop
    
            goto L_8000161C;
    }
    // 0x80001488: nop

L_8000148C:
    // 0x8000148C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80001490: beq         $v1, $zero, L_800014C4
    if (ctx->r3 == 0) {
        // 0x80001494: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800014C4;
    }
    // 0x80001494: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80001498: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000149C: beq         $v1, $at, L_80001538
    if (ctx->r3 == ctx->r1) {
        // 0x800014A0: lui         $t4, 0x801C
        ctx->r12 = S32(0X801C << 16);
            goto L_80001538;
    }
    // 0x800014A0: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x800014A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800014A8: beq         $v0, $at, L_80001560
    if (ctx->r2 == ctx->r1) {
        // 0x800014AC: lui         $a0, 0x8003
        ctx->r4 = S32(0X8003 << 16);
            goto L_80001560;
    }
    // 0x800014AC: lui         $a0, 0x8003
    ctx->r4 = S32(0X8003 << 16);
    // 0x800014B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800014B4: beql        $v0, $at, L_800015E8
    if (ctx->r2 == ctx->r1) {
        // 0x800014B8: sh          $t1, 0xA4($t0)
        MEM_H(0XA4, ctx->r8) = ctx->r9;
            goto L_800015E8;
    }
    goto skip_0;
    // 0x800014B8: sh          $t1, 0xA4($t0)
    MEM_H(0XA4, ctx->r8) = ctx->r9;
    skip_0:
    // 0x800014BC: b           L_8000161C
    // 0x800014C0: nop

        goto L_8000161C;
    // 0x800014C0: nop

L_800014C4:
    // 0x800014C4: jal         0x8001EAA4
    // 0x800014C8: nop

    LOOKUP_FUNC(0x8001EAA4)(rdram, ctx);
        goto after_0;
    // 0x800014C8: nop

    after_0:
    // 0x800014CC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800014D0: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x800014D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x800014D8: sb          $zero, -0x42AC($at)
    MEM_B(-0X42AC, ctx->r1) = 0;
    // 0x800014DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x800014E0: sb          $zero, -0x42B3($at)
    MEM_B(-0X42B3, ctx->r1) = 0;
    // 0x800014E4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x800014E8: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x800014EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800014F0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800014F4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800014F8: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x800014FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80001500: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80001504: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80001508: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8000150C: jal         0x8001E978
    // 0x80001510: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001E978)(rdram, ctx);
        goto after_1;
    // 0x80001510: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_1:
    // 0x80001514: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x80001518: lw          $t9, 0x7730($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7730);
    // 0x8000151C: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x80001520: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80001524: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x80001528: sw          $t3, 0x7730($at)
    MEM_W(0X7730, ctx->r1) = ctx->r11;
    // 0x8000152C: addiu       $t0, $t0, -0x6D50
    ctx->r8 = ADD32(ctx->r8, -0X6D50);
    // 0x80001530: b           L_8000161C
    // 0x80001534: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8000161C;
    // 0x80001534: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80001538:
    // 0x80001538: lbu         $t4, -0x42AC($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X42AC);
    // 0x8000153C: lui         $a0, 0x8003
    ctx->r4 = S32(0X8003 << 16);
    // 0x80001540: addiu       $a0, $a0, 0x7734
    ctx->r4 = ADD32(ctx->r4, 0X7734);
    // 0x80001544: bne         $t4, $zero, L_8000161C
    if (ctx->r12 != 0) {
        // 0x80001548: addiu       $t5, $zero, 0x5
        ctx->r13 = ADD32(0, 0X5);
            goto L_8000161C;
    }
    // 0x80001548: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8000154C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80001550: sh          $t1, 0xA4($t0)
    MEM_H(0XA4, ctx->r8) = ctx->r9;
    // 0x80001554: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80001558: b           L_8000161C
    // 0x8000155C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
        goto L_8000161C;
    // 0x8000155C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_80001560:
    // 0x80001560: addiu       $a0, $a0, 0x7734
    ctx->r4 = ADD32(ctx->r4, 0X7734);
    // 0x80001564: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80001568: sh          $t1, 0xA4($t0)
    MEM_H(0XA4, ctx->r8) = ctx->r9;
    // 0x8000156C: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80001570: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80001574: bne         $v1, $zero, L_8000161C
    if (ctx->r3 != 0) {
        // 0x80001578: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8000161C;
    }
    // 0x80001578: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8000157C: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x80001580: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001584: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80001588: bne         $t8, $at, L_800015A4
    if (ctx->r24 != ctx->r1) {
        // 0x8000158C: nop
    
            goto L_800015A4;
    }
    // 0x8000158C: nop

    // 0x80001590: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80001594: jal         0x80029FA0
    // 0x80001598: addiu       $a0, $a0, -0x5D10
    ctx->r4 = ADD32(ctx->r4, -0X5D10);
    LOOKUP_FUNC(0x80029FA0)(rdram, ctx);
        goto after_2;
    // 0x80001598: addiu       $a0, $a0, -0x5D10
    ctx->r4 = ADD32(ctx->r4, -0X5D10);
    after_2:
    // 0x8000159C: b           L_800015AC
    // 0x800015A0: nop

        goto L_800015AC;
    // 0x800015A0: nop

L_800015A4:
    // 0x800015A4: jal         0x80029FA0
    // 0x800015A8: addiu       $a0, $a0, -0x65D0
    ctx->r4 = ADD32(ctx->r4, -0X65D0);
    LOOKUP_FUNC(0x80029FA0)(rdram, ctx);
        goto after_3;
    // 0x800015A8: addiu       $a0, $a0, -0x65D0
    ctx->r4 = ADD32(ctx->r4, -0X65D0);
    after_3:
L_800015AC:
    // 0x800015AC: jal         0x80032890
    // 0x800015B0: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    LOOKUP_FUNC(0x80032890)(rdram, ctx);
        goto after_4;
    // 0x800015B0: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_4:
    // 0x800015B4: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x800015B8: jal         0x80001BC0
    // 0x800015BC: sh          $zero, 0x7758($at)
    MEM_H(0X7758, ctx->r1) = 0;
    LOOKUP_FUNC(0x80001BC0)(rdram, ctx);
        goto after_5;
    // 0x800015BC: sh          $zero, 0x7758($at)
    MEM_H(0X7758, ctx->r1) = 0;
    after_5:
    // 0x800015C0: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x800015C4: addiu       $v0, $v0, 0x7730
    ctx->r2 = ADD32(ctx->r2, 0X7730);
    // 0x800015C8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800015CC: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800015D0: addiu       $t0, $t0, -0x6D50
    ctx->r8 = ADD32(ctx->r8, -0X6D50);
    // 0x800015D4: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x800015D8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800015DC: b           L_8000161C
    // 0x800015E0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8000161C;
    // 0x800015E0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800015E4: sh          $t1, 0xA4($t0)
    MEM_H(0XA4, ctx->r8) = ctx->r9;
L_800015E8:
    // 0x800015E8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x800015EC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x800015F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800015F4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x800015F8: jal         0x8012FE50
    // 0x800015FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_6;
    // 0x800015FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80001600: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x80001604: sw          $zero, 0x7730($at)
    MEM_W(0X7730, ctx->r1) = 0;
    // 0x80001608: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x8000160C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80001610: sh          $zero, 0x7750($at)
    MEM_H(0X7750, ctx->r1) = 0;
    // 0x80001614: addiu       $t0, $t0, -0x6D50
    ctx->r8 = ADD32(ctx->r8, -0X6D50);
    // 0x80001618: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8000161C:
    // 0x8000161C: lui         $t2, 0x8003
    ctx->r10 = S32(0X8003 << 16);
    // 0x80001620: addiu       $t2, $t2, 0x7738
    ctx->r10 = ADD32(ctx->r10, 0X7738);
    // 0x80001624: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x80001628: lui         $t4, 0x8003
    ctx->r12 = S32(0X8003 << 16);
    // 0x8000162C: bne         $v1, $zero, L_80001644
    if (ctx->r3 != 0) {
        // 0x80001630: nop
    
            goto L_80001644;
    }
    // 0x80001630: nop

    // 0x80001634: lhu         $t4, 0x7750($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X7750);
    // 0x80001638: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000163C: bne         $t4, $at, L_800017AC
    if (ctx->r12 != ctx->r1) {
        // 0x80001640: nop
    
            goto L_800017AC;
    }
    // 0x80001640: nop

L_80001644:
    // 0x80001644: beq         $v1, $zero, L_80001678
    if (ctx->r3 == 0) {
        // 0x80001648: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80001678;
    }
    // 0x80001648: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000164C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001650: beq         $v1, $at, L_800016DC
    if (ctx->r3 == ctx->r1) {
        // 0x80001654: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_800016DC;
    }
    // 0x80001654: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80001658: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000165C: beq         $v0, $at, L_80001704
    if (ctx->r2 == ctx->r1) {
        // 0x80001660: lui         $a0, 0x8003
        ctx->r4 = S32(0X8003 << 16);
            goto L_80001704;
    }
    // 0x80001660: lui         $a0, 0x8003
    ctx->r4 = S32(0X8003 << 16);
    // 0x80001664: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80001668: beql        $v0, $at, L_80001784
    if (ctx->r2 == ctx->r1) {
        // 0x8000166C: sh          $t1, 0xA4($t0)
        MEM_H(0XA4, ctx->r8) = ctx->r9;
            goto L_80001784;
    }
    goto skip_1;
    // 0x8000166C: sh          $t1, 0xA4($t0)
    MEM_H(0XA4, ctx->r8) = ctx->r9;
    skip_1:
    // 0x80001670: b           L_800017AC
    // 0x80001674: nop

        goto L_800017AC;
    // 0x80001674: nop

L_80001678:
    // 0x80001678: jal         0x8001EAA4
    // 0x8000167C: nop

    LOOKUP_FUNC(0x8001EAA4)(rdram, ctx);
        goto after_7;
    // 0x8000167C: nop

    after_7:
    // 0x80001680: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80001684: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80001688: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8000168C: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x80001690: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80001694: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80001698: sb          $zero, 0x164($v0)
    MEM_B(0X164, ctx->r2) = 0;
    // 0x8000169C: sb          $zero, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = 0;
    // 0x800016A0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800016A4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800016A8: lw          $a0, 0x3C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3C);
    // 0x800016AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800016B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800016B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800016B8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800016BC: jal         0x8001E978
    // 0x800016C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x8001E978)(rdram, ctx);
        goto after_8;
    // 0x800016C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_8:
    // 0x800016C4: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x800016C8: lw          $t7, 0x7738($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7738);
    // 0x800016CC: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x800016D0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800016D4: b           L_800017AC
    // 0x800016D8: sw          $t8, 0x7738($at)
    MEM_W(0X7738, ctx->r1) = ctx->r24;
        goto L_800017AC;
    // 0x800016D8: sw          $t8, 0x7738($at)
    MEM_W(0X7738, ctx->r1) = ctx->r24;
L_800016DC:
    // 0x800016DC: lbu         $t9, -0x42AC($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X42AC);
    // 0x800016E0: lui         $a0, 0x8003
    ctx->r4 = S32(0X8003 << 16);
    // 0x800016E4: addiu       $a0, $a0, 0x773C
    ctx->r4 = ADD32(ctx->r4, 0X773C);
    // 0x800016E8: bne         $t9, $zero, L_800017AC
    if (ctx->r25 != 0) {
        // 0x800016EC: addiu       $t3, $zero, 0x5
        ctx->r11 = ADD32(0, 0X5);
            goto L_800017AC;
    }
    // 0x800016EC: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x800016F0: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x800016F4: sh          $t1, 0xA4($t0)
    MEM_H(0XA4, ctx->r8) = ctx->r9;
    // 0x800016F8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800016FC: b           L_800017AC
    // 0x80001700: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
        goto L_800017AC;
    // 0x80001700: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_80001704:
    // 0x80001704: addiu       $a0, $a0, 0x773C
    ctx->r4 = ADD32(ctx->r4, 0X773C);
    // 0x80001708: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000170C: sh          $t1, 0xA4($t0)
    MEM_H(0XA4, ctx->r8) = ctx->r9;
    // 0x80001710: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80001714: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80001718: bne         $v1, $zero, L_800017AC
    if (ctx->r3 != 0) {
        // 0x8000171C: sw          $t5, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r13;
            goto L_800017AC;
    }
    // 0x8000171C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80001720: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80001724: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001728: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8000172C: bne         $t6, $at, L_80001748
    if (ctx->r14 != ctx->r1) {
        // 0x80001730: nop
    
            goto L_80001748;
    }
    // 0x80001730: nop

    // 0x80001734: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80001738: jal         0x80029FA0
    // 0x8000173C: addiu       $a0, $a0, -0x5AE0
    ctx->r4 = ADD32(ctx->r4, -0X5AE0);
    LOOKUP_FUNC(0x80029FA0)(rdram, ctx);
        goto after_9;
    // 0x8000173C: addiu       $a0, $a0, -0x5AE0
    ctx->r4 = ADD32(ctx->r4, -0X5AE0);
    after_9:
    // 0x80001740: b           L_80001750
    // 0x80001744: nop

        goto L_80001750;
    // 0x80001744: nop

L_80001748:
    // 0x80001748: jal         0x80029FA0
    // 0x8000174C: addiu       $a0, $a0, -0x63A0
    ctx->r4 = ADD32(ctx->r4, -0X63A0);
    LOOKUP_FUNC(0x80029FA0)(rdram, ctx);
        goto after_10;
    // 0x8000174C: addiu       $a0, $a0, -0x63A0
    ctx->r4 = ADD32(ctx->r4, -0X63A0);
    after_10:
L_80001750:
    // 0x80001750: jal         0x80032890
    // 0x80001754: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    LOOKUP_FUNC(0x80032890)(rdram, ctx);
        goto after_11;
    // 0x80001754: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    after_11:
    // 0x80001758: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000175C: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x80001760: jal         0x80001BC0
    // 0x80001764: sh          $t7, 0x7758($at)
    MEM_H(0X7758, ctx->r1) = ctx->r15;
    LOOKUP_FUNC(0x80001BC0)(rdram, ctx);
        goto after_12;
    // 0x80001764: sh          $t7, 0x7758($at)
    MEM_H(0X7758, ctx->r1) = ctx->r15;
    after_12:
    // 0x80001768: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8000176C: addiu       $v0, $v0, 0x7738
    ctx->r2 = ADD32(ctx->r2, 0X7738);
    // 0x80001770: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80001774: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80001778: b           L_800017AC
    // 0x8000177C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_800017AC;
    // 0x8000177C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80001780: sh          $t1, 0xA4($t0)
    MEM_H(0XA4, ctx->r8) = ctx->r9;
L_80001784:
    // 0x80001784: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80001788: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x8000178C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80001790: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80001794: jal         0x8012FE50
    // 0x80001798: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_13;
    // 0x80001798: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x8000179C: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x800017A0: sw          $zero, 0x7738($at)
    MEM_W(0X7738, ctx->r1) = 0;
    // 0x800017A4: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x800017A8: sh          $zero, 0x7750($at)
    MEM_H(0X7750, ctx->r1) = 0;
L_800017AC:
    // 0x800017AC: jal         0x80001060
    // 0x800017B0: nop

    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_14;
    // 0x800017B0: nop

    after_14:
    // 0x800017B4: beq         $v0, $zero, L_800017CC
    if (ctx->r2 == 0) {
        // 0x800017B8: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800017CC;
    }
    // 0x800017B8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800017BC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800017C0: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x800017C4: b           L_800017DC
    // 0x800017C8: sb          $t3, 0x4294($v0)
    MEM_B(0X4294, ctx->r2) = ctx->r11;
        goto L_800017DC;
    // 0x800017C8: sb          $t3, 0x4294($v0)
    MEM_B(0X4294, ctx->r2) = ctx->r11;
L_800017CC:
    // 0x800017CC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800017D0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800017D4: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x800017D8: sb          $zero, -0x2ABC($at)
    MEM_B(-0X2ABC, ctx->r1) = 0;
L_800017DC:
    // 0x800017DC: lbu         $t4, 0x4295($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4295);
    // 0x800017E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800017E4: beql        $t4, $at, L_8000181C
    if (ctx->r12 == ctx->r1) {
        // 0x800017E8: lbu         $t6, 0x4294($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X4294);
            goto L_8000181C;
    }
    goto skip_2;
    // 0x800017E8: lbu         $t6, 0x4294($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4294);
    skip_2:
    // 0x800017EC: lbu         $t5, 0x4294($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4294);
    // 0x800017F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800017F4: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x800017F8: bnel        $t5, $at, L_8000181C
    if (ctx->r13 != ctx->r1) {
        // 0x800017FC: lbu         $t6, 0x4294($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X4294);
            goto L_8000181C;
    }
    goto skip_3;
    // 0x800017FC: lbu         $t6, 0x4294($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4294);
    skip_3:
    // 0x80001800: jal         0x80000EC8
    // 0x80001804: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    LOOKUP_FUNC(0x80000EC8)(rdram, ctx);
        goto after_15;
    // 0x80001804: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    after_15:
    // 0x80001808: sltiu       $at, $v0, 0x2
    ctx->r1 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8000180C: beq         $at, $zero, L_80001820
    if (ctx->r1 == 0) {
        // 0x80001810: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_80001820;
    }
    // 0x80001810: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80001814: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x80001818: lbu         $t6, 0x4294($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4294);
L_8000181C:
    // 0x8000181C: sb          $t6, 0x4295($v0)
    MEM_B(0X4295, ctx->r2) = ctx->r14;
L_80001820:
    // 0x80001820: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80001824: jal         0x80000EC8
    // 0x80001828: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    LOOKUP_FUNC(0x80000EC8)(rdram, ctx);
        goto after_16;
    // 0x80001828: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    after_16:
    // 0x8000182C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80001830: lbu         $t7, -0x2ABB($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2ABB);
    // 0x80001834: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80001838: bne         $t7, $zero, L_80001854
    if (ctx->r15 != 0) {
        // 0x8000183C: nop
    
            goto L_80001854;
    }
    // 0x8000183C: nop

    // 0x80001840: jal         0x80000EC8
    // 0x80001844: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    LOOKUP_FUNC(0x80000EC8)(rdram, ctx);
        goto after_17;
    // 0x80001844: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    after_17:
    // 0x80001848: sltiu       $at, $v0, 0x2
    ctx->r1 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8000184C: beql        $at, $zero, L_80001B24
    if (ctx->r1 == 0) {
        // 0x80001850: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80001B24;
    }
    goto skip_4;
    // 0x80001850: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
L_80001854:
    // 0x80001854: jal         0x80031190
    // 0x80001858: nop

    LOOKUP_FUNC(0x80031190)(rdram, ctx);
        goto after_18;
    // 0x80001858: nop

    after_18:
    // 0x8000185C: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x80001860: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x80001864: lw          $t9, 0x7764($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7764);
    // 0x80001868: lw          $t8, 0x7760($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7760);
    // 0x8000186C: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x80001870: sw          $v0, 0x7768($at)
    MEM_W(0X7768, ctx->r1) = ctx->r2;
    // 0x80001874: sw          $v1, 0x776C($at)
    MEM_W(0X776C, ctx->r1) = ctx->r3;
    // 0x80001878: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x8000187C: subu        $a0, $v0, $t8
    ctx->r4 = SUB32(ctx->r2, ctx->r24);
    // 0x80001880: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x80001884: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80001888: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x8000188C: jal         0x80026F58
    // 0x80001890: subu        $a1, $v1, $t9
    ctx->r5 = SUB32(ctx->r3, ctx->r25);
    LOOKUP_FUNC(0x80026F58)(rdram, ctx);
        goto after_19;
    // 0x80001890: subu        $a1, $v1, $t9
    ctx->r5 = SUB32(ctx->r3, ctx->r25);
    after_19:
    // 0x80001894: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80001898: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8000189C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800018A0: jal         0x80026E58
    // 0x800018A4: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    LOOKUP_FUNC(0x80026E58)(rdram, ctx);
        goto after_20;
    // 0x800018A4: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_20:
    // 0x800018A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800018AC: jal         0x80034C24
    // 0x800018B0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_21;
    // 0x800018B0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_21:
    // 0x800018B4: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800018B8: ldc1        $f4, -0x4700($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X4700);
    // 0x800018BC: jal         0x80034AB8
    // 0x800018C0: div.d       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f12.d = DIV_D(ctx->f0.d, ctx->f4.d);
    LOOKUP_FUNC(0x80034AB8)(rdram, ctx);
        goto after_22;
    // 0x800018C0: div.d       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f12.d = DIV_D(ctx->f0.d, ctx->f4.d);
    after_22:
    // 0x800018C4: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x800018C8: lhu         $t3, -0x4404($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4404);
    // 0x800018CC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x800018D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x800018D4: addu        $t7, $v1, $t3
    ctx->r15 = ADD32(ctx->r3, ctx->r11);
    // 0x800018D8: sh          $t7, -0x4404($at)
    MEM_H(-0X4404, ctx->r1) = ctx->r15;
    // 0x800018DC: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x800018E0: lhu         $t9, 0xC($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0XC);
    // 0x800018E4: slti        $at, $t9, 0xE10
    ctx->r1 = SIGNED(ctx->r25) < 0XE10 ? 1 : 0;
    // 0x800018E8: bne         $at, $zero, L_80001938
    if (ctx->r1 != 0) {
        // 0x800018EC: nop
    
            goto L_80001938;
    }
    // 0x800018EC: nop

    // 0x800018F0: lhu         $t3, 0xA($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0XA);
    // 0x800018F4: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x800018F8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800018FC: andi        $v0, $t4, 0xFFFF
    ctx->r2 = ctx->r12 & 0XFFFF;
    // 0x80001900: andi        $t5, $v0, 0x3F
    ctx->r13 = ctx->r2 & 0X3F;
    // 0x80001904: slti        $at, $t5, 0x3C
    ctx->r1 = SIGNED(ctx->r13) < 0X3C ? 1 : 0;
    // 0x80001908: bne         $at, $zero, L_80001938
    if (ctx->r1 != 0) {
        // 0x8000190C: sh          $t4, 0xA($a0)
        MEM_H(0XA, ctx->r4) = ctx->r12;
            goto L_80001938;
    }
    // 0x8000190C: sh          $t4, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r12;
    // 0x80001910: andi        $t7, $v0, 0xFFC0
    ctx->r15 = ctx->r2 & 0XFFC0;
    // 0x80001914: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x80001918: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8000191C: ori         $at, $zero, 0xF9C1
    ctx->r1 = 0 | 0XF9C1;
    // 0x80001920: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
    // 0x80001924: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80001928: bne         $at, $zero, L_80001938
    if (ctx->r1 != 0) {
        // 0x8000192C: sh          $t8, 0xA($a0)
        MEM_H(0XA, ctx->r4) = ctx->r24;
            goto L_80001938;
    }
    // 0x8000192C: sh          $t8, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r24;
    // 0x80001930: ori         $t3, $zero, 0xF9C0
    ctx->r11 = 0 | 0XF9C0;
    // 0x80001934: sh          $t3, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r11;
L_80001938:
    // 0x80001938: jal         0x80031190
    // 0x8000193C: nop

    LOOKUP_FUNC(0x80031190)(rdram, ctx);
        goto after_23;
    // 0x8000193C: nop

    after_23:
    // 0x80001940: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x80001944: sw          $v0, 0x7760($at)
    MEM_W(0X7760, ctx->r1) = ctx->r2;
    // 0x80001948: jal         0x800021B4
    // 0x8000194C: sw          $v1, 0x7764($at)
    MEM_W(0X7764, ctx->r1) = ctx->r3;
    LOOKUP_FUNC(0x800021B4)(rdram, ctx);
        goto after_24;
    // 0x8000194C: sw          $v1, 0x7764($at)
    MEM_W(0X7764, ctx->r1) = ctx->r3;
    after_24:
    // 0x80001950: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80001954: lbu         $t4, -0x2ABB($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2ABB);
    // 0x80001958: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000195C: bne         $t4, $at, L_8000196C
    if (ctx->r12 != ctx->r1) {
        // 0x80001960: nop
    
            goto L_8000196C;
    }
    // 0x80001960: nop

    // 0x80001964: jal         0x80001B30
    // 0x80001968: nop

    LOOKUP_FUNC(0x80001B30)(rdram, ctx);
        goto after_25;
    // 0x80001968: nop

    after_25:
L_8000196C:
    // 0x8000196C: jal         0x80126744
    // 0x80001970: nop

    LOOKUP_FUNC(0x80126744)(rdram, ctx);
        goto after_26;
    // 0x80001970: nop

    after_26:
    // 0x80001974: jal         0x80005270
    // 0x80001978: nop

    LOOKUP_FUNC(0x80005270)(rdram, ctx);
        goto after_27;
    // 0x80001978: nop

    after_27:
    // 0x8000197C: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80001980: lh          $t5, -0x6CAC($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X6CAC);
    // 0x80001984: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001988: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8000198C: beq         $t5, $at, L_80001A58
    if (ctx->r13 == ctx->r1) {
        // 0x80001990: nop
    
            goto L_80001A58;
    }
    // 0x80001990: nop

    // 0x80001994: lbu         $v0, -0x2ABB($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2ABB);
    // 0x80001998: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000199C: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x800019A0: bnel        $v0, $at, L_800019C4
    if (ctx->r2 != ctx->r1) {
        // 0x800019A4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800019C4;
    }
    goto skip_5;
    // 0x800019A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_5:
    // 0x800019A8: jal         0x80000EC8
    // 0x800019AC: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    LOOKUP_FUNC(0x80000EC8)(rdram, ctx);
        goto after_28;
    // 0x800019AC: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    after_28:
    // 0x800019B0: sltiu       $at, $v0, 0x2
    ctx->r1 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800019B4: beq         $at, $zero, L_80001A58
    if (ctx->r1 == 0) {
        // 0x800019B8: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_80001A58;
    }
    // 0x800019B8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800019BC: lbu         $v0, -0x2ABB($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2ABB);
    // 0x800019C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800019C4:
    // 0x800019C4: beq         $v0, $at, L_800019D4
    if (ctx->r2 == ctx->r1) {
        // 0x800019C8: nop
    
            goto L_800019D4;
    }
    // 0x800019C8: nop

    // 0x800019CC: jal         0x80001B30
    // 0x800019D0: nop

    LOOKUP_FUNC(0x80001B30)(rdram, ctx);
        goto after_29;
    // 0x800019D0: nop

    after_29:
L_800019D4:
    // 0x800019D4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800019D8: lh          $t7, -0x6CB4($t6)
    ctx->r15 = MEM_H(ctx->r14, -0X6CB4);
    // 0x800019DC: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800019E0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800019E4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800019E8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800019EC: lw          $t9, -0x2AD0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AD0);
    // 0x800019F0: jal         0x80006790
    // 0x800019F4: sw          $t9, -0x2AC0($at)
    MEM_W(-0X2AC0, ctx->r1) = ctx->r25;
    LOOKUP_FUNC(0x80006790)(rdram, ctx);
        goto after_30;
    // 0x800019F4: sw          $t9, -0x2AC0($at)
    MEM_W(-0X2AC0, ctx->r1) = ctx->r25;
    after_30:
    // 0x800019F8: jal         0x80126944
    // 0x800019FC: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_31;
    // 0x800019FC: nop

    after_31:
    // 0x80001A00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001A04: bne         $v0, $at, L_80001A14
    if (ctx->r2 != ctx->r1) {
        // 0x80001A08: nop
    
            goto L_80001A14;
    }
    // 0x80001A08: nop

    // 0x80001A0C: jal         0x80006AF0
    // 0x80001A10: nop

    LOOKUP_FUNC(0x80006AF0)(rdram, ctx);
        goto after_32;
    // 0x80001A10: nop

    after_32:
L_80001A14:
    // 0x80001A14: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80001A18: lbu         $t3, -0x2ABB($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X2ABB);
    // 0x80001A1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001A20: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80001A24: bne         $t3, $at, L_80001A3C
    if (ctx->r11 != ctx->r1) {
        // 0x80001A28: nop
    
            goto L_80001A3C;
    }
    // 0x80001A28: nop

    // 0x80001A2C: jal         0x80000EC8
    // 0x80001A30: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    LOOKUP_FUNC(0x80000EC8)(rdram, ctx);
        goto after_33;
    // 0x80001A30: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    after_33:
    // 0x80001A34: bne         $v0, $zero, L_80001A58
    if (ctx->r2 != 0) {
        // 0x80001A38: nop
    
            goto L_80001A58;
    }
    // 0x80001A38: nop

L_80001A3C:
    // 0x80001A3C: jal         0x80001D5C
    // 0x80001A40: nop

    LOOKUP_FUNC(0x80001D5C)(rdram, ctx);
        goto after_34;
    // 0x80001A40: nop

    after_34:
    // 0x80001A44: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80001A48: lh          $t4, -0x6CB4($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X6CB4);
    // 0x80001A4C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80001A50: xori        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 ^ 0X1;
    // 0x80001A54: sh          $t5, -0x6CB4($at)
    MEM_H(-0X6CB4, ctx->r1) = ctx->r13;
L_80001A58:
    // 0x80001A58: jal         0x8000433C
    // 0x80001A5C: nop

    LOOKUP_FUNC(0x8000433C)(rdram, ctx);
        goto after_35;
    // 0x80001A5C: nop

    after_35:
    // 0x80001A60: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80001A64: lhu         $t6, -0x6CA8($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6CA8);
    // 0x80001A68: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80001A6C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80001A70: jal         0x80133AA0
    // 0x80001A74: sh          $t7, -0x6CA8($at)
    MEM_H(-0X6CA8, ctx->r1) = ctx->r15;
    LOOKUP_FUNC(0x80133AA0)(rdram, ctx);
        goto after_36;
    // 0x80001A74: sh          $t7, -0x6CA8($at)
    MEM_H(-0X6CA8, ctx->r1) = ctx->r15;
    after_36:
    // 0x80001A78: blez        $v0, L_80001B20
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80001A7C: sra         $t8, $v0, 31
        ctx->r24 = S32(SIGNED(ctx->r2) >> 31);
            goto L_80001B20;
    }
    // 0x80001A7C: sra         $t8, $v0, 31
    ctx->r24 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80001A80: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80001A84: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80001A88:
    // 0x80001A88: jal         0x80031190
    // 0x80001A8C: nop

    LOOKUP_FUNC(0x80031190)(rdram, ctx);
        goto after_37;
    // 0x80001A8C: nop

    after_37:
    // 0x80001A90: lui         $t4, 0x8003
    ctx->r12 = S32(0X8003 << 16);
    // 0x80001A94: lui         $t5, 0x8003
    ctx->r13 = S32(0X8003 << 16);
    // 0x80001A98: lw          $t5, 0x7764($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7764);
    // 0x80001A9C: lw          $t4, 0x7760($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7760);
    // 0x80001AA0: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x80001AA4: sw          $v0, 0x7768($at)
    MEM_W(0X7768, ctx->r1) = ctx->r2;
    // 0x80001AA8: sw          $v1, 0x776C($at)
    MEM_W(0X776C, ctx->r1) = ctx->r3;
    // 0x80001AAC: sltu        $at, $v1, $t5
    ctx->r1 = ctx->r3 < ctx->r13 ? 1 : 0;
    // 0x80001AB0: subu        $a0, $v0, $t4
    ctx->r4 = SUB32(ctx->r2, ctx->r12);
    // 0x80001AB4: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x80001AB8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80001ABC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x80001AC0: jal         0x80026F58
    // 0x80001AC4: subu        $a1, $v1, $t5
    ctx->r5 = SUB32(ctx->r3, ctx->r13);
    LOOKUP_FUNC(0x80026F58)(rdram, ctx);
        goto after_38;
    // 0x80001AC4: subu        $a1, $v1, $t5
    ctx->r5 = SUB32(ctx->r3, ctx->r13);
    after_38:
    // 0x80001AC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80001ACC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80001AD0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80001AD4: jal         0x80026E58
    // 0x80001AD8: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    LOOKUP_FUNC(0x80026E58)(rdram, ctx);
        goto after_39;
    // 0x80001AD8: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_39:
    // 0x80001ADC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80001AE0: jal         0x80034C24
    // 0x80001AE4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_40;
    // 0x80001AE4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_40:
    // 0x80001AE8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80001AEC: ldc1        $f6, -0x46F8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X46F8);
    // 0x80001AF0: jal         0x80034AB8
    // 0x80001AF4: div.d       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = DIV_D(ctx->f0.d, ctx->f6.d);
    LOOKUP_FUNC(0x80034AB8)(rdram, ctx);
        goto after_41;
    // 0x80001AF4: div.d       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = DIV_D(ctx->f0.d, ctx->f6.d);
    after_41:
    // 0x80001AF8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80001AFC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80001B00: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x80001B04: bne         $at, $zero, L_80001A88
    if (ctx->r1 != 0) {
        // 0x80001B08: nop
    
            goto L_80001A88;
    }
    // 0x80001B08: nop

    // 0x80001B0C: sltu        $at, $t6, $v0
    ctx->r1 = ctx->r14 < ctx->r2 ? 1 : 0;
    // 0x80001B10: bne         $at, $zero, L_80001B20
    if (ctx->r1 != 0) {
        // 0x80001B14: sltu        $at, $v1, $t7
        ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
            goto L_80001B20;
    }
    // 0x80001B14: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x80001B18: bne         $at, $zero, L_80001A88
    if (ctx->r1 != 0) {
        // 0x80001B1C: nop
    
            goto L_80001A88;
    }
    // 0x80001B1C: nop

L_80001B20:
    // 0x80001B20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80001B24:
    // 0x80001B24: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80001B28: jr          $ra
    // 0x80001B2C: nop

    return;
    // 0x80001B2C: nop

;}
RECOMP_FUNC void FUN_80001b30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001B30: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80001B34: addiu       $a0, $a0, -0x6D50
    ctx->r4 = ADD32(ctx->r4, -0X6D50);
    // 0x80001B38: lh          $t6, 0x9C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X9C);
    // 0x80001B3C: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80001B40: addiu       $t8, $t8, -0x6D50
    ctx->r24 = ADD32(ctx->r24, -0X6D50);
    // 0x80001B44: sll         $t7, $t6, 10
    ctx->r15 = S32(ctx->r14 << 10);
    // 0x80001B48: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80001B4C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80001B50: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80001B54: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80001B58: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80001B5C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80001B60: sw          $v0, -0x2A44($at)
    MEM_W(-0X2A44, ctx->r1) = ctx->r2;
    // 0x80001B64: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80001B68: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80001B6C: lw          $t9, 0x40($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X40);
    // 0x80001B70: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80001B74: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80001B78: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x80001B7C: addiu       $a1, $a1, -0x2A40
    ctx->r5 = ADD32(ctx->r5, -0X2A40);
    // 0x80001B80: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80001B84: addiu       $t1, $v1, 0x40
    ctx->r9 = ADD32(ctx->r3, 0X40);
    // 0x80001B88: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80001B8C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80001B90: sw          $t1, -0x2A3C($at)
    MEM_W(-0X2A3C, ctx->r1) = ctx->r9;
    // 0x80001B94: lhu         $t2, 0x90($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X90);
    // 0x80001B98: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80001B9C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80001BA0: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x80001BA4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80001BA8: jr          $ra
    // 0x80001BAC: sw          $t5, -0x2A34($at)
    MEM_W(-0X2A34, ctx->r1) = ctx->r13;
    return;
    // 0x80001BAC: sw          $t5, -0x2A34($at)
    MEM_W(-0X2A34, ctx->r1) = ctx->r13;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80001bb0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80001bb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001BB0: jr          $ra
    // 0x80001BB4: nop

    return;
    // 0x80001BB4: nop

    // 0x80001BB8: nop

    // 0x80001BBC: nop

;}
RECOMP_FUNC void FUN_80001bc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001BC0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80001BC4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80001BC8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80001BCC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80001BD0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80001BD4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80001BD8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80001BDC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80001BE0: lui         $s3, 0x8006
    ctx->r19 = S32(0X8006 << 16);
    // 0x80001BE4: lui         $s5, 0x8006
    ctx->r21 = S32(0X8006 << 16);
    // 0x80001BE8: lui         $fp, 0x8040
    ctx->r30 = S32(0X8040 << 16);
    // 0x80001BEC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80001BF0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001BF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001BF8: addiu       $fp, $fp, 0x0
    ctx->r30 = ADD32(ctx->r30, 0X0);
    // 0x80001BFC: addiu       $s5, $s5, -0x3C58
    ctx->r21 = ADD32(ctx->r21, -0X3C58);
    // 0x80001C00: addiu       $s3, $s3, -0x3C60
    ctx->r19 = ADD32(ctx->r19, -0X3C60);
    // 0x80001C04: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80001C08: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x80001C0C: addiu       $s6, $zero, 0x58
    ctx->r22 = ADD32(0, 0X58);
    // 0x80001C10: addiu       $s7, $zero, 0x40
    ctx->r23 = ADD32(0, 0X40);
L_80001C14:
    // 0x80001C14: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001C18: sll         $t6, $s2, 1
    ctx->r14 = S32(ctx->r18 << 1);
    // 0x80001C1C: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x80001C20: sh          $s4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r20;
    // 0x80001C24: mflo        $t8
    ctx->r24 = lo;
    // 0x80001C28: addu        $s1, $s5, $t8
    ctx->r17 = ADD32(ctx->r21, ctx->r24);
    // 0x80001C2C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80001C30: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80001C34: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x80001C38: jal         0x80001060
    // 0x80001C3C: sw          $s7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r23;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x80001C3C: sw          $s7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r23;
    after_0:
    // 0x80001C40: beq         $v0, $zero, L_80001C58
    if (ctx->r2 == 0) {
        // 0x80001C44: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80001C58;
    }
    // 0x80001C44: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80001C48: sll         $t9, $s2, 20
    ctx->r25 = S32(ctx->r18 << 20);
    // 0x80001C4C: addu        $t0, $fp, $t9
    ctx->r8 = ADD32(ctx->r30, ctx->r25);
    // 0x80001C50: b           L_80001C84
    // 0x80001C54: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
        goto L_80001C84;
    // 0x80001C54: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
L_80001C58:
    // 0x80001C58: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x80001C5C: addu        $t1, $t1, $s2
    ctx->r9 = ADD32(ctx->r9, ctx->r18);
    // 0x80001C60: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80001C64: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x80001C68: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80001C6C: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x80001C70: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80001C74: addiu       $t2, $t2, -0x800
    ctx->r10 = ADD32(ctx->r10, -0X800);
    // 0x80001C78: sll         $t1, $t1, 11
    ctx->r9 = S32(ctx->r9 << 11);
    // 0x80001C7C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80001C80: sw          $t3, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r11;
L_80001C84:
    // 0x80001C84: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x80001C88: addiu       $t6, $t6, 0x51A0
    ctx->r14 = ADD32(ctx->r14, 0X51A0);
    // 0x80001C8C: lui         $t5, 0x8003
    ctx->r13 = S32(0X8003 << 16);
    // 0x80001C90: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
    // 0x80001C94: addiu       $t5, $t5, 0x50D0
    ctx->r13 = ADD32(ctx->r13, 0X50D0);
    // 0x80001C98: sll         $t6, $s2, 1
    ctx->r14 = S32(ctx->r18 << 1);
    // 0x80001C9C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80001CA0: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
    // 0x80001CA4: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x80001CA8: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80001CAC: sw          $t4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r12;
    // 0x80001CB0: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x80001CB4: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80001CB8: lui         $t0, 0x8006
    ctx->r8 = S32(0X8006 << 16);
    // 0x80001CBC: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x80001CC0: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x80001CC4: lui         $t5, 0x8006
    ctx->r13 = S32(0X8006 << 16);
    // 0x80001CC8: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x80001CCC: addiu       $t8, $t8, -0x2B10
    ctx->r24 = ADD32(ctx->r24, -0X2B10);
    // 0x80001CD0: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x80001CD4: addiu       $t0, $t0, 0x3EB0
    ctx->r8 = ADD32(ctx->r8, 0X3EB0);
    // 0x80001CD8: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x80001CDC: addiu       $t2, $t2, 0x42B0
    ctx->r10 = ADD32(ctx->r10, 0X42B0);
    // 0x80001CE0: addiu       $t3, $t3, -0x7D50
    ctx->r11 = ADD32(ctx->r11, -0X7D50);
    // 0x80001CE4: addiu       $t4, $zero, 0xC00
    ctx->r12 = ADD32(0, 0XC00);
    // 0x80001CE8: addiu       $t5, $t5, -0x3D78
    ctx->r13 = ADD32(ctx->r13, -0X3D78);
    // 0x80001CEC: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x80001CF0: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80001CF4: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80001CF8: sw          $t8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r24;
    // 0x80001CFC: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x80001D00: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x80001D04: sw          $t1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r9;
    // 0x80001D08: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    // 0x80001D0C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80001D10: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x80001D14: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x80001D18: sw          $t3, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r11;
    // 0x80001D1C: sw          $t4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r12;
    // 0x80001D20: sw          $t5, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r13;
    // 0x80001D24: bne         $at, $zero, L_80001C14
    if (ctx->r1 != 0) {
        // 0x80001D28: sw          $t7, 0x54($s0)
        MEM_W(0X54, ctx->r16) = ctx->r15;
            goto L_80001C14;
    }
    // 0x80001D28: sw          $t7, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r15;
    // 0x80001D2C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80001D30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001D34: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80001D38: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80001D3C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80001D40: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80001D44: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80001D48: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80001D4C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80001D50: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80001D54: jr          $ra
    // 0x80001D58: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80001D58: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80001d5c(rdram, ctx);
;}
RECOMP_FUNC void FUN_80001d5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001D5C: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x80001D60: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x80001D64: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80001D68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001D6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001D70: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80001D74: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80001D78: lui         $t7, 0xE900
    ctx->r15 = S32(0XE900 << 16);
    // 0x80001D7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80001D80: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80001D84: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80001D88: lui         $t9, 0xDF00
    ctx->r25 = S32(0XDF00 << 16);
    // 0x80001D8C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80001D90: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80001D94: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80001D98: jal         0x800349E0
    // 0x80001D9C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x800349E0)(rdram, ctx);
        goto after_0;
    // 0x80001D9C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x80001DA0: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80001DA4: jal         0x80000704
    // 0x80001DA8: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    LOOKUP_FUNC(0x80000704)(rdram, ctx);
        goto after_1;
    // 0x80001DA8: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    after_1:
    // 0x80001DAC: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80001DB0: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80001DB4: lh          $t3, -0x6CB4($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X6CB4);
    // 0x80001DB8: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80001DBC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80001DC0: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80001DC4: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x80001DC8: addiu       $t2, $t2, -0x3C58
    ctx->r10 = ADD32(ctx->r10, -0X3C58);
    // 0x80001DCC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80001DD0: sll         $t4, $t3, 10
    ctx->r12 = S32(ctx->r11 << 10);
    // 0x80001DD4: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x80001DD8: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    // 0x80001DDC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80001DE0: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x80001DE4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80001DE8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80001DEC: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80001DF0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80001DF4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80001DF8: addiu       $t5, $t5, -0x6D50
    ctx->r13 = ADD32(ctx->r13, -0X6D50);
    // 0x80001DFC: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x80001E00: lui         $t0, 0x8006
    ctx->r8 = S32(0X8006 << 16);
    // 0x80001E04: lui         $t2, 0x8003
    ctx->r10 = S32(0X8003 << 16);
    // 0x80001E08: lui         $t1, 0x8003
    ctx->r9 = S32(0X8003 << 16);
    // 0x80001E0C: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x80001E10: addiu       $t0, $t0, 0x42B0
    ctx->r8 = ADD32(ctx->r8, 0X42B0);
    // 0x80001E14: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80001E18: addiu       $t1, $t1, 0x51A0
    ctx->r9 = ADD32(ctx->r9, 0X51A0);
    // 0x80001E1C: addiu       $t2, $t2, 0x50D0
    ctx->r10 = ADD32(ctx->r10, 0X50D0);
    // 0x80001E20: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80001E24: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80001E28: addiu       $t4, $t0, 0x4000
    ctx->r12 = ADD32(ctx->r8, 0X4000);
    // 0x80001E2C: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x80001E30: sw          $v1, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r3;
    // 0x80001E34: sw          $t9, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r25;
    // 0x80001E38: sw          $t3, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r11;
    // 0x80001E3C: sw          $t0, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->r8;
    // 0x80001E40: sw          $t4, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r12;
    // 0x80001E44: sw          $t5, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r13;
    // 0x80001E48: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80001E4C: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80001E50: lw          $a1, -0x3288($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3288);
    // 0x80001E54: jal         0x80000ED0
    // 0x80001E58: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    LOOKUP_FUNC(0x80000ED0)(rdram, ctx);
        goto after_2;
    // 0x80001E58: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    after_2:
    // 0x80001E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001E64: jr          $ra
    // 0x80001E68: nop

    return;
    // 0x80001E68: nop

    // 0x80001E6C: nop

;}
RECOMP_FUNC void FUN_80001e70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001E70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001E78: jal         0x80032BE0
    // 0x80001E7C: nop

    LOOKUP_FUNC(0x80032BE0)(rdram, ctx);
        goto after_0;
    // 0x80001E7C: nop

    after_0:
    // 0x80001E80: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80001E84: jal         0x80001EA0
    // 0x80001E88: sw          $v0, -0x3268($at)
    MEM_W(-0X3268, ctx->r1) = ctx->r2;
    LOOKUP_FUNC(0x80001EA0)(rdram, ctx);
        goto after_1;
    // 0x80001E88: sw          $v0, -0x3268($at)
    MEM_W(-0X3268, ctx->r1) = ctx->r2;
    after_1:
    // 0x80001E8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001E90: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80001E94: sw          $v0, -0x3264($at)
    MEM_W(-0X3264, ctx->r1) = ctx->r2;
    // 0x80001E98: jr          $ra
    // 0x80001E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80001E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80001ea0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80001ea0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001EA0: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80001EA4: addiu       $a2, $a2, -0x3260
    ctx->r6 = ADD32(ctx->r6, -0X3260);
    // 0x80001EA8: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x80001EAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001EB0: lui         $v0, 0xA800
    ctx->r2 = S32(0XA800 << 16);
    // 0x80001EB4: bne         $v0, $t6, L_80001EC4
    if (ctx->r2 != ctx->r14) {
        // 0x80001EB8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80001EC4;
    }
    // 0x80001EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001EBC: b           L_80001F20
    // 0x80001EC0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_80001F20;
    // 0x80001EC0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80001EC4:
    // 0x80001EC4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80001EC8: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80001ECC: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80001ED0: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x80001ED4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80001ED8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80001EDC: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80001EE0: sb          $t7, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r15;
    // 0x80001EE4: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x80001EE8: sb          $t8, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r24;
    // 0x80001EEC: sb          $t9, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r25;
    // 0x80001EF0: sb          $t0, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r8;
    // 0x80001EF4: sb          $t1, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r9;
    // 0x80001EF8: sb          $t2, 0x9($a2)
    MEM_B(0X9, ctx->r6) = ctx->r10;
    // 0x80001EFC: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80001F00: addiu       $a0, $a0, -0x324C
    ctx->r4 = ADD32(ctx->r4, -0X324C);
    // 0x80001F04: jal         0x800279F0
    // 0x80001F08: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_0;
    // 0x80001F08: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_0:
    // 0x80001F0C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80001F10: jal         0x80029580
    // 0x80001F14: addiu       $a0, $a2, -0x3260
    ctx->r4 = ADD32(ctx->r6, -0X3260);
    LOOKUP_FUNC(0x80029580)(rdram, ctx);
        goto after_1;
    // 0x80001F14: addiu       $a0, $a2, -0x3260
    ctx->r4 = ADD32(ctx->r6, -0X3260);
    after_1:
    // 0x80001F18: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80001F1C: addiu       $v0, $a2, -0x3260
    ctx->r2 = ADD32(ctx->r6, -0X3260);
L_80001F20:
    // 0x80001F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001F28: jr          $ra
    // 0x80001F2C: nop

    return;
    // 0x80001F2C: nop

;}
RECOMP_FUNC void FUN_80001f30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001F30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001F34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001F38: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80001F3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80001F40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80001F44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80001F48: bne         $a1, $zero, L_80001F7C
    if (ctx->r5 != 0) {
        // 0x80001F4C: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_80001F7C;
    }
    // 0x80001F4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80001F50: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80001F54: jal         0x80028A90
    // 0x80001F58: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80028A90)(rdram, ctx);
        goto after_0;
    // 0x80001F58: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80001F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80001F60: jal         0x800306C0
    // 0x80001F64: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x800306C0)(rdram, ctx);
        goto after_1;
    // 0x80001F64: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80001F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80001F6C: jal         0x80030640
    // 0x80001F70: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80030640)(rdram, ctx);
        goto after_2;
    // 0x80001F70: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80001F74: b           L_80001F88
    // 0x80001F78: nop

        goto L_80001F88;
    // 0x80001F78: nop

L_80001F7C:
    // 0x80001F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80001F80: jal         0x80028A90
    // 0x80001F84: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80028A90)(rdram, ctx);
        goto after_3;
    // 0x80001F84: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
L_80001F88:
    // 0x80001F88: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80001F8C: addiu       $a1, $a1, -0x3280
    ctx->r5 = ADD32(ctx->r5, -0X3280);
    // 0x80001F90: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80001F94: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80001F98: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80001F9C: addiu       $t7, $t7, -0x3D98
    ctx->r15 = ADD32(ctx->r15, -0X3D98);
    // 0x80001FA0: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x80001FA4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80001FA8: sw          $s0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r16;
    // 0x80001FAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80001FB0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80001FB4: sw          $t8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r24;
    // 0x80001FB8: jal         0x800304F0
    // 0x80001FBC: sw          $t9, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r25;
    LOOKUP_FUNC(0x800304F0)(rdram, ctx);
        goto after_4;
    // 0x80001FBC: sw          $t9, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r25;
    after_4:
    // 0x80001FC0: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80001FC4: addiu       $a0, $a0, -0x3D98
    ctx->r4 = ADD32(ctx->r4, -0X3D98);
    // 0x80001FC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80001FCC: jal         0x800266B0
    // 0x80001FD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_5;
    // 0x80001FD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80001FD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80001FD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001FDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80001FE0: jr          $ra
    // 0x80001FE4: nop

    return;
    // 0x80001FE4: nop

;}
RECOMP_FUNC void FUN_80001fe8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001FE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001FEC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80001FF0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80001FF4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80001FF8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80001FFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002000: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80002004: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80002008: lw          $a0, -0x3268($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3268);
    // 0x8000200C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002010: jal         0x80001F30
    // 0x80002014: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80001F30)(rdram, ctx);
        goto after_0;
    // 0x80002014: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80002018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000201C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002020: jr          $ra
    // 0x80002024: nop

    return;
    // 0x80002024: nop

;}
RECOMP_FUNC void FUN_80002028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002028: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000202C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80002030: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80002034: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80002038: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000203C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002040: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80002044: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80002048: lw          $a0, -0x3264($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3264);
    // 0x8000204C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002050: jal         0x80001F30
    // 0x80002054: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80001F30)(rdram, ctx);
        goto after_0;
    // 0x80002054: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80002058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000205C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002060: jr          $ra
    // 0x80002064: nop

    return;
    // 0x80002064: nop

;}
RECOMP_FUNC void FUN_80002068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000206C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80002070: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80002074: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80002078: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000207C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002080: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80002084: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80002088: lw          $a0, -0x3264($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3264);
    // 0x8000208C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80002090: jal         0x80001F30
    // 0x80002094: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80001F30)(rdram, ctx);
        goto after_0;
    // 0x80002094: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80002098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000209C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800020A0: jr          $ra
    // 0x800020A4: nop

    return;
    // 0x800020A4: nop

    // 0x800020A8: nop

    // 0x800020AC: nop

;}
RECOMP_FUNC void FUN_800020b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800020B0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800020B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800020B8: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x800020BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800020C0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800020C4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800020C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800020CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800020D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800020D4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800020D8: jal         0x80030610
    // 0x800020DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_0;
    // 0x800020DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800020E0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800020E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800020E8: jal         0x8002FB60
    // 0x800020EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8002FB60)(rdram, ctx);
        goto after_1;
    // 0x800020EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800020F0: lui         $s4, 0x8006
    ctx->r20 = S32(0X8006 << 16);
    // 0x800020F4: addiu       $s4, $s4, -0x31C0
    ctx->r20 = ADD32(ctx->r20, -0X31C0);
    // 0x800020F8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800020FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80002100: jal         0x80027F20
    // 0x80002104: addiu       $a1, $sp, 0x37
    ctx->r5 = ADD32(ctx->r29, 0X37);
    LOOKUP_FUNC(0x80027F20)(rdram, ctx);
        goto after_2;
    // 0x80002104: addiu       $a1, $sp, 0x37
    ctx->r5 = ADD32(ctx->r29, 0X37);
    after_2:
    // 0x80002108: lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // 0x8000210C: addiu       $s0, $s0, -0x31E0
    ctx->r16 = ADD32(ctx->r16, -0X31E0);
    // 0x80002110: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80002114: addiu       $a1, $a1, -0x31C8
    ctx->r5 = ADD32(ctx->r5, -0X31C8);
    // 0x80002118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000211C: jal         0x80030610
    // 0x80002120: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80030610)(rdram, ctx);
        goto after_3;
    // 0x80002120: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80002124: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80002128: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000212C: jal         0x8002FB60
    // 0x80002130: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8002FB60)(rdram, ctx);
        goto after_4;
    // 0x80002130: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80002134: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80002138: addiu       $s1, $s1, -0x6D50
    ctx->r17 = ADD32(ctx->r17, -0X6D50);
    // 0x8000213C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80002140: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80002144: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80002148:
    // 0x80002148: jal         0x800023A8
    // 0x8000214C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_5;
    // 0x8000214C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_5:
    // 0x80002150: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x80002154: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80002158: sllv        $t8, $t7, $s0
    ctx->r24 = S32(ctx->r15 << (ctx->r16 & 31));
    // 0x8000215C: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x80002160: beq         $t9, $zero, L_80002184
    if (ctx->r25 == 0) {
        // 0x80002164: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_80002184;
    }
    // 0x80002164: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80002168: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x8000216C: lbu         $t2, 0x3($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X3);
    // 0x80002170: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x80002174: bnel        $t3, $zero, L_80002188
    if (ctx->r11 != 0) {
        // 0x80002178: sh          $zero, 0x1C4($s1)
        MEM_H(0X1C4, ctx->r17) = 0;
            goto L_80002188;
    }
    goto skip_0;
    // 0x80002178: sh          $zero, 0x1C4($s1)
    MEM_H(0X1C4, ctx->r17) = 0;
    skip_0:
    // 0x8000217C: b           L_80002188
    // 0x80002180: sh          $s2, 0x1C4($s1)
    MEM_H(0X1C4, ctx->r17) = ctx->r18;
        goto L_80002188;
    // 0x80002180: sh          $s2, 0x1C4($s1)
    MEM_H(0X1C4, ctx->r17) = ctx->r18;
L_80002184:
    // 0x80002184: sh          $zero, 0x1C4($s1)
    MEM_H(0X1C4, ctx->r17) = 0;
L_80002188:
    // 0x80002188: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000218C: bne         $s0, $s3, L_80002148
    if (ctx->r16 != ctx->r19) {
        // 0x80002190: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_80002148;
    }
    // 0x80002190: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x80002194: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80002198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000219C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800021A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800021A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800021A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800021AC: jr          $ra
    // 0x800021B0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800021B0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800021b4(rdram, ctx);
;}
RECOMP_FUNC void FUN_800021b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800021B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800021B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800021BC: lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // 0x800021C0: addiu       $s0, $s0, -0x31E0
    ctx->r16 = ADD32(ctx->r16, -0X31E0);
    // 0x800021C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800021C8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800021CC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800021D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800021D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800021D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800021DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800021E0: jal         0x800283B0
    // 0x800021E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800283B0)(rdram, ctx);
        goto after_0;
    // 0x800021E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800021E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800021EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800021F0: jal         0x800266B0
    // 0x800021F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x800266B0)(rdram, ctx);
        goto after_1;
    // 0x800021F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800021F8: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x800021FC: jal         0x80028434
    // 0x80002200: addiu       $a0, $a0, -0x31B0
    ctx->r4 = ADD32(ctx->r4, -0X31B0);
    LOOKUP_FUNC(0x80028434)(rdram, ctx);
        goto after_2;
    // 0x80002200: addiu       $a0, $a0, -0x31B0
    ctx->r4 = ADD32(ctx->r4, -0X31B0);
    after_2:
    // 0x80002204: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80002208: lui         $s1, 0x8006
    ctx->r17 = S32(0X8006 << 16);
    // 0x8000220C: lui         $s6, 0x8006
    ctx->r22 = S32(0X8006 << 16);
    // 0x80002210: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80002214: lui         $s2, 0x8006
    ctx->r18 = S32(0X8006 << 16);
    // 0x80002218: addiu       $s0, $s0, -0x6B8C
    ctx->r16 = ADD32(ctx->r16, -0X6B8C);
    // 0x8000221C: addiu       $s2, $s2, -0x31B0
    ctx->r18 = ADD32(ctx->r18, -0X31B0);
    // 0x80002220: addiu       $s5, $s5, -0x4410
    ctx->r21 = ADD32(ctx->r21, -0X4410);
    // 0x80002224: addiu       $s6, $s6, -0x3198
    ctx->r22 = ADD32(ctx->r22, -0X3198);
    // 0x80002228: addiu       $s1, $s1, -0x31B0
    ctx->r17 = ADD32(ctx->r17, -0X31B0);
    // 0x8000222C: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
    // 0x80002230: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_80002234:
    // 0x80002234: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80002238: lhu         $t6, 0x2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2);
    // 0x8000223C: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x80002240: xor         $t7, $t6, $v0
    ctx->r15 = ctx->r14 ^ ctx->r2;
    // 0x80002244: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x80002248: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    // 0x8000224C: lb          $t9, 0x2($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X2);
    // 0x80002250: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x80002254: lb          $t0, 0x3($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X3);
    // 0x80002258: bne         $s1, $s2, L_800022B4
    if (ctx->r17 != ctx->r18) {
        // 0x8000225C: sh          $t0, 0x8($s0)
        MEM_H(0X8, ctx->r16) = ctx->r8;
            goto L_800022B4;
    }
    // 0x8000225C: sh          $t0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r8;
    // 0x80002260: jal         0x80151BC4
    // 0x80002264: nop

    LOOKUP_FUNC(0x80151BC4)(rdram, ctx);
        goto after_3;
    // 0x80002264: nop

    after_3:
    // 0x80002268: bnel        $s3, $v0, L_800022B8
    if (ctx->r19 != ctx->r2) {
        // 0x8000226C: lh          $v1, 0x6($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X6);
            goto L_800022B8;
    }
    goto skip_0;
    // 0x8000226C: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    skip_0:
    // 0x80002270: lhu         $t1, 0x2C($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X2C);
    // 0x80002274: bnel        $s4, $t1, L_800022B8
    if (ctx->r20 != ctx->r9) {
        // 0x80002278: lh          $v1, 0x6($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X6);
            goto L_800022B8;
    }
    goto skip_1;
    // 0x80002278: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    skip_1:
    // 0x8000227C: jal         0x80151BFC
    // 0x80002280: nop

    LOOKUP_FUNC(0x80151BFC)(rdram, ctx);
        goto after_4;
    // 0x80002280: nop

    after_4:
    // 0x80002284: bne         $v0, $zero, L_800022AC
    if (ctx->r2 != 0) {
        // 0x80002288: nop
    
            goto L_800022AC;
    }
    // 0x80002288: nop

    // 0x8000228C: jal         0x80151DA4
    // 0x80002290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80151DA4)(rdram, ctx);
        goto after_5;
    // 0x80002290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80002294: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x80002298: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8000229C: beql        $t2, $zero, L_800022B8
    if (ctx->r10 == 0) {
        // 0x800022A0: lh          $v1, 0x6($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X6);
            goto L_800022B8;
    }
    goto skip_2;
    // 0x800022A0: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    skip_2:
    // 0x800022A4: b           L_800022B8
    // 0x800022A8: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
        goto L_800022B8;
    // 0x800022A8: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
L_800022AC:
    // 0x800022AC: jal         0x801521C8
    // 0x800022B0: nop

    LOOKUP_FUNC(0x801521C8)(rdram, ctx);
        goto after_6;
    // 0x800022B0: nop

    after_6:
L_800022B4:
    // 0x800022B4: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
L_800022B8:
    // 0x800022B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800022BC: slti        $at, $v1, -0x28
    ctx->r1 = SIGNED(ctx->r3) < -0X28 ? 1 : 0;
    // 0x800022C0: beql        $at, $zero, L_800022D0
    if (ctx->r1 == 0) {
        // 0x800022C4: slti        $at, $v1, 0x29
        ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
            goto L_800022D0;
    }
    goto skip_3;
    // 0x800022C4: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    skip_3:
    // 0x800022C8: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x800022CC: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
L_800022D0:
    // 0x800022D0: bnel        $at, $zero, L_800022E4
    if (ctx->r1 != 0) {
        // 0x800022D4: lh          $v1, 0x8($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X8);
            goto L_800022E4;
    }
    goto skip_4;
    // 0x800022D4: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
    skip_4:
    // 0x800022D8: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x800022DC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800022E0: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
L_800022E4:
    // 0x800022E4: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x800022E8: bnel        $at, $zero, L_800022FC
    if (ctx->r1 != 0) {
        // 0x800022EC: slti        $at, $v1, -0x28
        ctx->r1 = SIGNED(ctx->r3) < -0X28 ? 1 : 0;
            goto L_800022FC;
    }
    goto skip_5;
    // 0x800022EC: slti        $at, $v1, -0x28
    ctx->r1 = SIGNED(ctx->r3) < -0X28 ? 1 : 0;
    skip_5:
    // 0x800022F0: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // 0x800022F4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800022F8: slti        $at, $v1, -0x28
    ctx->r1 = SIGNED(ctx->r3) < -0X28 ? 1 : 0;
L_800022FC:
    // 0x800022FC: beql        $at, $zero, L_80002310
    if (ctx->r1 == 0) {
        // 0x80002300: lhu         $t3, 0xA($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0XA);
            goto L_80002310;
    }
    goto skip_6;
    // 0x80002300: lhu         $t3, 0xA($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XA);
    skip_6:
    // 0x80002304: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x80002308: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000230C: lhu         $t3, 0xA($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XA);
L_80002310:
    // 0x80002310: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x80002314: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80002318: xor         $t4, $t3, $v0
    ctx->r12 = ctx->r11 ^ ctx->r2;
    // 0x8000231C: and         $t5, $t4, $v0
    ctx->r13 = ctx->r12 & ctx->r2;
    // 0x80002320: beq         $t6, $zero, L_80002330
    if (ctx->r14 == 0) {
        // 0x80002324: sh          $t5, 0xC($s0)
        MEM_H(0XC, ctx->r16) = ctx->r13;
            goto L_80002330;
    }
    // 0x80002324: sh          $t5, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r13;
    // 0x80002328: jal         0x8000242C
    // 0x8000232C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8000242C)(rdram, ctx);
        goto after_7;
    // 0x8000232C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80002330:
    // 0x80002330: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x80002334: bne         $s1, $s6, L_80002234
    if (ctx->r17 != ctx->r22) {
        // 0x80002338: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_80002234;
    }
    // 0x80002338: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8000233C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80002340: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002344: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80002348: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000234C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80002350: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80002354: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80002358: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000235C: jr          $ra
    // 0x80002360: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80002360: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80002364(rdram, ctx);
;}
RECOMP_FUNC void FUN_80002364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002364: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80002368: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8000236C: sll         $t6, $a3, 5
    ctx->r14 = S32(ctx->r7 << 5);
    // 0x80002370: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80002374: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80002378: addiu       $t8, $t8, -0x6D50
    ctx->r24 = ADD32(ctx->r24, -0X6D50);
    // 0x8000237C: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80002380: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80002384: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80002388: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000238C: sw          $zero, 0x1D8($v0)
    MEM_W(0X1D8, ctx->r2) = 0;
    // 0x80002390: sw          $a0, 0x1D4($v0)
    MEM_W(0X1D4, ctx->r2) = ctx->r4;
    // 0x80002394: sh          $a1, 0x1DC($v0)
    MEM_H(0X1DC, ctx->r2) = ctx->r5;
    // 0x80002398: sh          $a2, 0x1DE($v0)
    MEM_H(0X1DE, ctx->r2) = ctx->r6;
    // 0x8000239C: sh          $zero, 0x1D2($v0)
    MEM_H(0X1D2, ctx->r2) = 0;
    // 0x800023A0: jr          $ra
    // 0x800023A4: sb          $zero, 0x1E0($v0)
    MEM_B(0X1E0, ctx->r2) = 0;
    return;
    // 0x800023A4: sb          $zero, 0x1E0($v0)
    MEM_B(0X1E0, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800023a8(rdram, ctx);
;}
RECOMP_FUNC void FUN_800023a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800023A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800023AC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800023B0: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800023B4: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800023B8: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x800023BC: addiu       $t8, $t8, -0x6D50
    ctx->r24 = ADD32(ctx->r24, -0X6D50);
    // 0x800023C0: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800023C4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800023C8: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x800023CC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800023D0: sw          $zero, 0x1D8($v0)
    MEM_W(0X1D8, ctx->r2) = 0;
    // 0x800023D4: sw          $zero, 0x1D4($v0)
    MEM_W(0X1D4, ctx->r2) = 0;
    // 0x800023D8: sh          $t9, 0x1DC($v0)
    MEM_H(0X1DC, ctx->r2) = ctx->r25;
    // 0x800023DC: sh          $t0, 0x1DE($v0)
    MEM_H(0X1DE, ctx->r2) = ctx->r8;
    // 0x800023E0: sh          $zero, 0x1D2($v0)
    MEM_H(0X1D2, ctx->r2) = 0;
    // 0x800023E4: jr          $ra
    // 0x800023E8: sb          $zero, 0x1E0($v0)
    MEM_B(0X1E0, ctx->r2) = 0;
    return;
    // 0x800023E8: sb          $zero, 0x1E0($v0)
    MEM_B(0X1E0, ctx->r2) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800023ec(rdram, ctx);
;}
RECOMP_FUNC void FUN_800023ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800023EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800023F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800023F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800023F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800023FC:
    // 0x800023FC: jal         0x800023A8
    // 0x80002400: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_0;
    // 0x80002400: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x80002404: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80002408: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8000240C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80002410: bne         $at, $zero, L_800023FC
    if (ctx->r1 != 0) {
        // 0x80002414: nop
    
            goto L_800023FC;
    }
    // 0x80002414: nop

    // 0x80002418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000241C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002420: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002424: jr          $ra
    // 0x80002428: nop

    return;
    // 0x80002428: nop

;}
RECOMP_FUNC void FUN_8000242c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000242C: lbu         $t6, 0x1C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1C);
    // 0x80002430: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002434: bnel        $t6, $at, L_80002448
    if (ctx->r14 != ctx->r1) {
        // 0x80002438: lhu         $v0, 0x18($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0X18);
            goto L_80002448;
    }
    goto skip_0;
    // 0x80002438: lhu         $v0, 0x18($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X18);
    skip_0:
    // 0x8000243C: b           L_80002448
    // 0x80002440: lhu         $v0, 0x1A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1A);
        goto L_80002448;
    // 0x80002440: lhu         $v0, 0x1A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1A);
    // 0x80002444: lhu         $v0, 0x18($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X18);
L_80002448:
    // 0x80002448: lhu         $t7, 0xA($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XA);
    // 0x8000244C: lhu         $t9, 0x2($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X2);
    // 0x80002450: lw          $t1, 0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X10);
    // 0x80002454: lw          $t2, 0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X14);
    // 0x80002458: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8000245C: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80002460: and         $v1, $t0, $t1
    ctx->r3 = ctx->r8 & ctx->r9;
    // 0x80002464: and         $t3, $t2, $v1
    ctx->r11 = ctx->r10 & ctx->r3;
    // 0x80002468: beq         $t3, $zero, L_80002480
    if (ctx->r11 == 0) {
        // 0x8000246C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80002480;
    }
    // 0x8000246C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80002470: lhu         $t4, 0xE($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0XE);
    // 0x80002474: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80002478: b           L_80002488
    // 0x8000247C: sh          $t5, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r13;
        goto L_80002488;
    // 0x8000247C: sh          $t5, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r13;
L_80002480:
    // 0x80002480: sb          $zero, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = 0;
    // 0x80002484: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
L_80002488:
    // 0x80002488: lhu         $t6, 0xE($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XE);
    // 0x8000248C: srl         $t4, $v1, 16
    ctx->r12 = S32(U32(ctx->r3) >> 16);
    // 0x80002490: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80002494: beq         $at, $zero, L_800024BC
    if (ctx->r1 == 0) {
        // 0x80002498: nop
    
            goto L_800024BC;
    }
    // 0x80002498: nop

    // 0x8000249C: lhu         $t8, 0x4($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X4);
    // 0x800024A0: lhu         $t2, 0xC($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0XC);
    // 0x800024A4: sb          $t7, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r15;
    // 0x800024A8: or          $t1, $t8, $v1
    ctx->r9 = ctx->r24 | ctx->r3;
    // 0x800024AC: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800024B0: sh          $t1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r9;
    // 0x800024B4: sh          $t5, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r13;
    // 0x800024B8: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
L_800024BC:
    // 0x800024BC: jr          $ra
    // 0x800024C0: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    return;
    // 0x800024C0: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    // 0x800024C4: nop

    // 0x800024C8: nop

    // 0x800024CC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800024d0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800024d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800024D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800024D4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800024D8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800024DC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800024E0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800024E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800024E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800024EC: lui         $s3, 0x8006
    ctx->r19 = S32(0X8006 << 16);
    // 0x800024F0: lui         $s4, 0x8006
    ctx->r20 = S32(0X8006 << 16);
    // 0x800024F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800024F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800024FC: addiu       $s4, $s4, -0x3190
    ctx->r20 = ADD32(ctx->r20, -0X3190);
    // 0x80002500: addiu       $s3, $s3, -0x31E0
    ctx->r19 = ADD32(ctx->r19, -0X31E0);
    // 0x80002504: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80002508: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000250C: addiu       $s5, $zero, 0x68
    ctx->r21 = ADD32(0, 0X68);
L_80002510:
    // 0x80002510: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002514: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80002518: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000251C: mflo        $t6
    ctx->r14 = lo;
    // 0x80002520: addu        $a1, $s4, $t6
    ctx->r5 = ADD32(ctx->r20, ctx->r14);
    // 0x80002524: jal         0x80032FB0
    // 0x80002528: nop

    LOOKUP_FUNC(0x80032FB0)(rdram, ctx);
        goto after_0;
    // 0x80002528: nop

    after_0:
    // 0x8000252C: beq         $v0, $zero, L_80002544
    if (ctx->r2 == 0) {
        // 0x80002530: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80002544;
    }
    // 0x80002530: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80002534: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80002538: sllv        $t8, $t7, $s1
    ctx->r24 = S32(ctx->r15 << (ctx->r17 & 31));
    // 0x8000253C: or          $s2, $s2, $t8
    ctx->r18 = ctx->r18 | ctx->r24;
    // 0x80002540: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
L_80002544:
    // 0x80002544: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80002548: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8000254C: bne         $at, $zero, L_80002510
    if (ctx->r1 != 0) {
        // 0x80002550: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80002510;
    }
    // 0x80002550: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80002554: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80002558: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8000255C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80002560: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80002564: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80002568: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000256C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80002570: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80002574: jr          $ra
    // 0x80002578: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80002578: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000257C: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80002580: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80002584: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80002588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000258C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80002590: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80002594: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80002598: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8000259C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800025A0: addiu       $t7, $t7, -0x3190
    ctx->r15 = ADD32(ctx->r15, -0X3190);
    // 0x800025A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800025A8: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x800025AC: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    // 0x800025B0: jal         0x80032FB0
    // 0x800025B4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    LOOKUP_FUNC(0x80032FB0)(rdram, ctx);
        goto after_1;
    // 0x800025B4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x800025B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800025BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800025C0: jr          $ra
    // 0x800025C4: nop

    return;
    // 0x800025C4: nop

    // 0x800025C8: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800025CC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800025D0: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800025D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800025D8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800025DC: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x800025E0: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x800025E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800025E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800025EC: addiu       $t7, $t7, -0x3190
    ctx->r15 = ADD32(ctx->r15, -0X3190);
    // 0x800025F0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800025F4: jal         0x800308D0
    // 0x800025F8: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    LOOKUP_FUNC(0x800308D0)(rdram, ctx);
        goto after_2;
    // 0x800025F8: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x800025FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002604: jr          $ra
    // 0x80002608: nop

    return;
    // 0x80002608: nop

;}
RECOMP_FUNC void FUN_8000260c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000260C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002610: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80002614: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x80002618: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8000261C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80002620: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80002624: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80002628: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000262C: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x80002630: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80002634: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80002638: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8000263C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80002640: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x80002644: lhu         $a1, 0x8($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X8);
    // 0x80002648: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x8000264C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80002650: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80002654: addiu       $t8, $t8, -0x3190
    ctx->r24 = ADD32(ctx->r24, -0X3190);
    // 0x80002658: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x8000265C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80002660: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80002664: addiu       $a3, $t9, 0xE
    ctx->r7 = ADD32(ctx->r25, 0XE);
    // 0x80002668: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8000266C: jal         0x8002A350
    // 0x80002670: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8002A350)(rdram, ctx);
        goto after_0;
    // 0x80002670: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_0:
    // 0x80002674: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80002678: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000267C: jr          $ra
    // 0x80002680: nop

    return;
    // 0x80002680: nop

;}
RECOMP_FUNC void FUN_80002684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002684: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002688: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000268C: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80002690: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x80002694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002698: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000269C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800026A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800026A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800026A8: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x800026AC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800026B0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800026B4: addiu       $t8, $t8, -0x3190
    ctx->r24 = ADD32(ctx->r24, -0X3190);
    // 0x800026B8: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x800026BC: lhu         $a1, 0x8($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X8);
    // 0x800026C0: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x800026C4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800026C8: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800026CC: jal         0x80031BC0
    // 0x800026D0: addiu       $a3, $t9, 0xE
    ctx->r7 = ADD32(ctx->r25, 0XE);
    LOOKUP_FUNC(0x80031BC0)(rdram, ctx);
        goto after_0;
    // 0x800026D0: addiu       $a3, $t9, 0xE
    ctx->r7 = ADD32(ctx->r25, 0XE);
    after_0:
    // 0x800026D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800026D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800026DC: jr          $ra
    // 0x800026E0: nop

    return;
    // 0x800026E0: nop

;}
RECOMP_FUNC void FUN_800026e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800026E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800026E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800026EC: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800026F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800026F4: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x800026F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800026FC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80002700: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002704: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80002708: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000270C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80002710: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80002714: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80002718: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000271C: addiu       $t8, $t8, -0x3190
    ctx->r24 = ADD32(ctx->r24, -0X3190);
    // 0x80002720: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x80002724: lhu         $a1, 0x8($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X8);
    // 0x80002728: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x8000272C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80002730: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80002734: addiu       $a3, $t9, 0xE
    ctx->r7 = ADD32(ctx->r25, 0XE);
    // 0x80002738: jal         0x8002EE40
    // 0x8000273C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8002EE40)(rdram, ctx);
        goto after_0;
    // 0x8000273C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_0:
    // 0x80002740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002744: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002748: jr          $ra
    // 0x8000274C: nop

    return;
    // 0x8000274C: nop

    // 0x80002750: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80002754: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80002758: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x8000275C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002760: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80002764: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x80002768: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8000276C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80002774: addiu       $t7, $t7, -0x3190
    ctx->r15 = ADD32(ctx->r15, -0X3190);
    // 0x80002778: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8000277C: jal         0x80032DD0
    // 0x80002780: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    LOOKUP_FUNC(0x80032DD0)(rdram, ctx);
        goto after_1;
    // 0x80002780: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80002784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000278C: jr          $ra
    // 0x80002790: nop

    return;
    // 0x80002790: nop

    // 0x80002794: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80002798: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8000279C: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x800027A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800027A4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800027A8: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x800027AC: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x800027B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800027B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800027B8: addiu       $t7, $t7, -0x3190
    ctx->r15 = ADD32(ctx->r15, -0X3190);
    // 0x800027BC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800027C0: jal         0x80032AB0
    // 0x800027C4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    LOOKUP_FUNC(0x80032AB0)(rdram, ctx);
        goto after_2;
    // 0x800027C4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x800027C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800027CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800027D0: jr          $ra
    // 0x800027D4: nop

    return;
    // 0x800027D4: nop

    // 0x800027D8: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x800027DC: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800027E0: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x800027E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800027E8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800027EC: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x800027F0: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x800027F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800027F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800027FC: addiu       $t7, $t7, -0x3190
    ctx->r15 = ADD32(ctx->r15, -0X3190);
    // 0x80002800: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80002804: jal         0x80026450
    // 0x80002808: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    LOOKUP_FUNC(0x80026450)(rdram, ctx);
        goto after_3;
    // 0x80002808: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_3:
    // 0x8000280C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002814: jr          $ra
    // 0x80002818: nop

    return;
    // 0x80002818: nop

;}
RECOMP_FUNC void FUN_8000281c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000281C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002820: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80002824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002828: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8000282C: jal         0x8002A7D0
    // 0x80002830: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    LOOKUP_FUNC(0x8002A7D0)(rdram, ctx);
        goto after_0;
    // 0x80002830: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    after_0:
    // 0x80002834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000283C: jr          $ra
    // 0x80002840: nop

    return;
    // 0x80002840: nop

;}
RECOMP_FUNC void FUN_80002844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002844: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002848: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000284C: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80002850: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80002854: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80002858: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000285C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80002860: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80002864: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80002868: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x8000286C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80002870: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80002874: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002878: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000287C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80002880: addiu       $t8, $t8, -0x3190
    ctx->r24 = ADD32(ctx->r24, -0X3190);
    // 0x80002884: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80002888: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000288C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80002890: jal         0x80029784
    // 0x80002894: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80029784)(rdram, ctx);
        goto after_0;
    // 0x80002894: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_0:
    // 0x80002898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000289C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800028A0: jr          $ra
    // 0x800028A4: nop

    return;
    // 0x800028A4: nop

;}
RECOMP_FUNC void FUN_800028a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800028A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800028AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800028B0: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800028B4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800028B8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800028BC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800028C0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800028C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800028C8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800028CC: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x800028D0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800028D4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800028D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800028DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800028E0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800028E4: addiu       $t8, $t8, -0x3190
    ctx->r24 = ADD32(ctx->r24, -0X3190);
    // 0x800028E8: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800028EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800028F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800028F4: jal         0x80029784
    // 0x800028F8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80029784)(rdram, ctx);
        goto after_0;
    // 0x800028F8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_0:
    // 0x800028FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002904: jr          $ra
    // 0x80002908: nop

    return;
    // 0x80002908: nop

;}
RECOMP_FUNC void FUN_8000290c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000290C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80002910: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80002914: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80002918: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000291C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80002920: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80002924: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80002928: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000292C: lui         $s0, 0x8003
    ctx->r16 = S32(0X8003 << 16);
    // 0x80002930: lui         $s4, 0x8003
    ctx->r20 = S32(0X8003 << 16);
    // 0x80002934: lui         $s6, 0x8006
    ctx->r22 = S32(0X8006 << 16);
    // 0x80002938: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000293C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80002940: addiu       $s6, $s6, -0x3190
    ctx->r22 = ADD32(ctx->r22, -0X3190);
    // 0x80002944: addiu       $s4, $s4, 0x7780
    ctx->r20 = ADD32(ctx->r20, 0X7780);
    // 0x80002948: addiu       $s0, $s0, 0x7770
    ctx->r16 = ADD32(ctx->r16, 0X7770);
    // 0x8000294C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80002950: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80002954: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80002958: addiu       $s7, $zero, 0x68
    ctx->r23 = ADD32(0, 0X68);
L_8000295C:
    // 0x8000295C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80002960: addu        $s1, $s4, $s3
    ctx->r17 = ADD32(ctx->r20, ctx->r19);
    // 0x80002964: beql        $t6, $zero, L_800029CC
    if (ctx->r14 == 0) {
        // 0x80002968: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800029CC;
    }
    goto skip_0;
    // 0x80002968: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x8000296C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80002970: beql        $t7, $zero, L_800029CC
    if (ctx->r15 == 0) {
        // 0x80002974: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800029CC;
    }
    goto skip_1;
    // 0x80002974: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x80002978: jal         0x80002A94
    // 0x8000297C: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    LOOKUP_FUNC(0x80002A94)(rdram, ctx);
        goto after_0;
    // 0x8000297C: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_0:
    // 0x80002980: beq         $v0, $zero, L_80002994
    if (ctx->r2 == 0) {
        // 0x80002984: nop
    
            goto L_80002994;
    }
    // 0x80002984: nop

    // 0x80002988: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8000298C: b           L_800029BC
    // 0x80002990: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
        goto L_800029BC;
    // 0x80002990: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80002994:
    // 0x80002994: multu       $s2, $s7
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000299C: mflo        $t8
    ctx->r24 = lo;
    // 0x800029A0: addu        $a0, $s6, $t8
    ctx->r4 = ADD32(ctx->r22, ctx->r24);
    // 0x800029A4: jal         0x80027A90
    // 0x800029A8: nop

    LOOKUP_FUNC(0x80027A90)(rdram, ctx);
        goto after_1;
    // 0x800029A8: nop

    after_1:
    // 0x800029AC: beql        $v0, $zero, L_800029C0
    if (ctx->r2 == 0) {
        // 0x800029B0: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_800029C0;
    }
    goto skip_2;
    // 0x800029B0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x800029B4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800029B8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800029BC:
    // 0x800029BC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_800029C0:
    // 0x800029C0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800029C4: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800029C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800029CC:
    // 0x800029CC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800029D0: bne         $s2, $s5, L_8000295C
    if (ctx->r18 != ctx->r21) {
        // 0x800029D4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000295C;
    }
    // 0x800029D4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800029D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800029DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800029E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800029E4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800029E8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800029EC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800029F0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800029F4: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800029F8: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800029FC: jr          $ra
    // 0x80002A00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80002A00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80002a04(rdram, ctx);
;}
RECOMP_FUNC void FUN_80002a04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80002A08: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80002A0C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80002A10: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80002A14: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80002A18: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80002A1C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80002A20: lui         $s1, 0x8003
    ctx->r17 = S32(0X8003 << 16);
    // 0x80002A24: lui         $s3, 0x8003
    ctx->r19 = S32(0X8003 << 16);
    // 0x80002A28: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80002A2C: addiu       $s3, $s3, 0x7770
    ctx->r19 = ADD32(ctx->r19, 0X7770);
    // 0x80002A30: addiu       $s1, $s1, 0x7780
    ctx->r17 = ADD32(ctx->r17, 0X7780);
    // 0x80002A34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80002A38: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80002A3C: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x80002A40: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
L_80002A44:
    // 0x80002A44: jal         0x80002A94
    // 0x80002A48: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80002A94)(rdram, ctx);
        goto after_0;
    // 0x80002A48: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x80002A4C: bne         $v0, $zero, L_80002A64
    if (ctx->r2 != 0) {
        // 0x80002A50: sll         $v0, $s0, 2
        ctx->r2 = S32(ctx->r16 << 2);
            goto L_80002A64;
    }
    // 0x80002A50: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x80002A54: addu        $t6, $s1, $v0
    ctx->r14 = ADD32(ctx->r17, ctx->r2);
    // 0x80002A58: sw          $s2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r18;
    // 0x80002A5C: addu        $t7, $s3, $v0
    ctx->r15 = ADD32(ctx->r19, ctx->r2);
    // 0x80002A60: sw          $s4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r20;
L_80002A64:
    // 0x80002A64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80002A68: bne         $s0, $s5, L_80002A44
    if (ctx->r16 != ctx->r21) {
        // 0x80002A6C: nop
    
            goto L_80002A44;
    }
    // 0x80002A6C: nop

    // 0x80002A70: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80002A74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80002A78: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80002A7C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80002A80: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80002A84: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80002A88: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80002A8C: jr          $ra
    // 0x80002A90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80002A90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80002a94(rdram, ctx);
;}
RECOMP_FUNC void FUN_80002a94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A94: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80002A98: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80002A9C: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80002AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002AA4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80002AA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80002AAC: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80002AB0: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80002AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002AB8: addiu       $t7, $t7, -0x3190
    ctx->r15 = ADD32(ctx->r15, -0X3190);
    // 0x80002ABC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80002AC0: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80002AC4: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    // 0x80002AC8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80002ACC: jal         0x80027D04
    // 0x80002AD0: sb          $a2, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80027D04)(rdram, ctx);
        goto after_0;
    // 0x80002AD0: sb          $a2, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r6;
    after_0:
    // 0x80002AD4: beq         $v0, $zero, L_80002B04
    if (ctx->r2 == 0) {
        // 0x80002AD8: lbu         $a3, 0x1B($sp)
        ctx->r7 = MEM_BU(ctx->r29, 0X1B);
            goto L_80002B04;
    }
    // 0x80002AD8: lbu         $a3, 0x1B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1B);
    // 0x80002ADC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002AE0: beq         $v0, $at, L_80002B20
    if (ctx->r2 == ctx->r1) {
        // 0x80002AE4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80002B20;
    }
    // 0x80002AE4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80002AE8: beq         $v0, $at, L_80002B30
    if (ctx->r2 == ctx->r1) {
        // 0x80002AEC: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_80002B30;
    }
    // 0x80002AEC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80002AF0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80002AF4: beq         $v0, $at, L_80002B28
    if (ctx->r2 == ctx->r1) {
        // 0x80002AF8: nop
    
            goto L_80002B28;
    }
    // 0x80002AF8: nop

    // 0x80002AFC: b           L_80002B30
    // 0x80002B00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80002B30;
    // 0x80002B00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80002B04:
    // 0x80002B04: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80002B08: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x80002B0C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80002B10: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80002B14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80002B18: b           L_80002B30
    // 0x80002B1C: sw          $t8, 0x7780($at)
    MEM_W(0X7780, ctx->r1) = ctx->r24;
        goto L_80002B30;
    // 0x80002B1C: sw          $t8, 0x7780($at)
    MEM_W(0X7780, ctx->r1) = ctx->r24;
L_80002B20:
    // 0x80002B20: b           L_80002B30
    // 0x80002B24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80002B30;
    // 0x80002B24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80002B28:
    // 0x80002B28: b           L_80002B30
    // 0x80002B2C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80002B30;
    // 0x80002B2C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80002B30:
    // 0x80002B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002B38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80002B3C: jr          $ra
    // 0x80002B40: nop

    return;
    // 0x80002B40: nop

;}
RECOMP_FUNC void FUN_80002b44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002B44: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80002B48: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80002B4C: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x80002B50: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80002B54: lw          $t7, 0x7780($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7780);
    // 0x80002B58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002B5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002B60: beq         $t7, $zero, L_80002B98
    if (ctx->r15 == 0) {
        // 0x80002B64: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80002B98;
    }
    // 0x80002B64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80002B68: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80002B6C: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80002B70: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80002B74: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x80002B78: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x80002B7C: addiu       $t9, $t9, -0x3190
    ctx->r25 = ADD32(ctx->r25, -0X3190);
    // 0x80002B80: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80002B84: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80002B88: jal         0x80027A90
    // 0x80002B8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80027A90)(rdram, ctx);
        goto after_0;
    // 0x80002B8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80002B90: b           L_80002B9C
    // 0x80002B94: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_80002B9C;
    // 0x80002B94: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80002B98:
    // 0x80002B98: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80002B9C:
    // 0x80002B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002BA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002BA4: jr          $ra
    // 0x80002BA8: nop

    return;
    // 0x80002BA8: nop

;}
