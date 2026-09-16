#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_80260c44(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80260C44u);
    return;
}
RECOMP_FUNC void FUN_80260e40(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80260E40u);
    return;
}
RECOMP_FUNC void FUN_8026221c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8026221Cu);
    return;
}
RECOMP_FUNC void FUN_80264e28(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80264E28u);
    return;
}
RECOMP_FUNC void FUN_80284018(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80284018u);
    return;
}
RECOMP_FUNC void FUN_802850ac(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x802850ACu);
    return;
}
RECOMP_FUNC void FUN_80289498(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80289498u);
    return;
}
RECOMP_FUNC void FUN_802a0bbc(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x802A0BBCu);
    return;
}
RECOMP_FUNC void FUN_802a3354(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x802A3354u);
    return;
}
RECOMP_FUNC void FUN_802a3838(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x802A3838u);
    return;
}
RECOMP_FUNC void FUN_802d2290(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x802D2290u);
    return;
}
RECOMP_FUNC void FUN_802dea0c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x802DEA0Cu);
    return;
}
RECOMP_FUNC void FUN_802e0fcc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_802D2290:
    // 0x802E0FCC: addi        $v0, $s2, -0x6E00
    ctx->r2 = ADD32(ctx->r18, -0X6E00);
    // 0x802E0FD0: sltiu       $at, $t8, -0x2021
    ctx->r1 = ctx->r24 < -0X2021 ? 1 : 0;
    // 0x802E0FD4: andi        $at, $t2, 0x2081
    ctx->r1 = ctx->r10 & 0X2081;
    // 0x802E0FD8: cache       0x1B, 0x7D83($a2)

    // 0x802E0FDC: beql        $fp, $s5, L_802ECBE4
    if (ctx->r30 == ctx->r21) {
        // 0x802E0FE0: lb          $sp, -0x4F0E($s7)
        ctx->r29 = MEM_B(ctx->r23, -0X4F0E);
        LOOKUP_FUNC(0x802ECBE4)(rdram, ctx);
        return;
    }
    goto skip_0;
    // 0x802E0FE0: lb          $sp, -0x4F0E($s7)
    ctx->r29 = MEM_B(ctx->r23, -0X4F0E);
    skip_0:
    // 0x802E0FE4: sd          $t7, 0x3F0($s1)
    SD(ctx->r15, 0X3F0, ctx->r17);
    // 0x802E0FE8: andi        $v1, $a0, 0xB165
    ctx->r3 = ctx->r4 & 0XB165;
    // 0x802E0FEC: bltzall     $s0, L_802D2290
    if (SIGNED(ctx->r16) < 0) {
        // 0x802E0FF0: ldr         $t7, -0x7CB5($ra)
    ctx->r15 = do_ldr(rdram, ctx->r15, ctx->r31, -0X7CB5);
    LOOKUP_FUNC(0x802D2290)(rdram, ctx);
        goto after_0;
    }
    goto skip_1;
    // 0x802E0FF0: ldr         $t7, -0x7CB5($ra)
    ctx->r15 = do_ldr(rdram, ctx->r15, ctx->r31, -0X7CB5);
    after_0:
    skip_1:
    // 0x802E0FF4: jal         0x8B07BCC0
    // 0x802E0FF8: addi        $zero, $at, -0x187D
    // write to $zero
    LOOKUP_FUNC(0x8B07BCC0)(rdram, ctx);
        goto after_1;
    // 0x802E0FF8: addi        $zero, $at, -0x187D
    // write to $zero
    after_1:
;}
RECOMP_FUNC void FUN_802e0fe0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x802E0FE0u);
    return;
}
RECOMP_FUNC void FUN_802e127c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x802E127Cu);
    return;
}
RECOMP_FUNC void FUN_802e2340(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x802E2340u);
    return;
}
RECOMP_FUNC void FUN_80300000(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80300000u);
    return;
}
RECOMP_FUNC void FUN_80301608(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80301608u);
    return;
}
RECOMP_FUNC void FUN_80303a0c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80303A0Cu);
    return;
}
RECOMP_FUNC void FUN_80304018(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80304018u);
    return;
}
RECOMP_FUNC void FUN_8030520c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8030520Cu);
    return;
}
RECOMP_FUNC void FUN_8030a018(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8030A018u);
    return;
}
RECOMP_FUNC void FUN_8030de50(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8030DE50u);
    return;
}
RECOMP_FUNC void FUN_80314a0c(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80314A0Cu);
    return;
}
RECOMP_FUNC void FUN_803211e4(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x803211E4u);
    return;
}
RECOMP_FUNC void FUN_803234c0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x803234C0u);
    return;
}
RECOMP_FUNC void FUN_803341d0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x803341D0u);
    return;
}
RECOMP_FUNC void FUN_8033b9d0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8033B9D0u);
    return;
}
RECOMP_FUNC void FUN_8035ba60(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8035BA60u);
    return;
}
RECOMP_FUNC void FUN_8035e098(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8035E098u);
    return;
}
RECOMP_FUNC void FUN_80361580(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80361580u);
    return;
}
RECOMP_FUNC void FUN_803a0cc0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x803A0CC0u);
    return;
}
RECOMP_FUNC void FUN_803a2744(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x803A2744u);
    return;
}
RECOMP_FUNC void FUN_803c20c0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x803C20C0u);
    return;
}
RECOMP_FUNC void FUN_803e0e68(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x803E0E68u);
    return;
}
RECOMP_FUNC void FUN_80402000(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80402000u);
    return;
}
RECOMP_FUNC void FUN_8040a1dc(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x8040A1DCu);
    return;
}
RECOMP_FUNC void FUN_804204a0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x804204A0u);
    return;
}
RECOMP_FUNC void FUN_804209dc(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x804209DCu);
    return;
}
RECOMP_FUNC void FUN_80421450(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80421450u);
    return;
}
RECOMP_FUNC void FUN_804430c0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x804430C0u);
    return;
}
RECOMP_FUNC void FUN_80446028(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80446028u);
    return;
}
RECOMP_FUNC void FUN_804614c0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x804614C0u);
    return;
}
RECOMP_FUNC void FUN_80461bcc(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80461BCCu);
    return;
}
RECOMP_FUNC void FUN_80480000(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80480000u);
    return;
}
RECOMP_FUNC void thunk_FUN_80482658(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80482040u);
    return;
}
RECOMP_FUNC void FUN_80482658(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80482658u);
    return;
}
RECOMP_FUNC void FUN_80483014(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80483014u);
    return;
}
RECOMP_FUNC void FUN_804a3d08(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x804A3D08u);
    return;
}
RECOMP_FUNC void FUN_804bb9d0(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x804BB9D0u);
    return;
}
