// hh_saveedit — editor de partida en MEMORIA. Ver include/hh/save_edit.h y
// notes/2026-09-27-e-editor-partida-plan.md.

#include "hh.h"
#include "hh/save_edit.h"

#include "recomp.h"

namespace hh::save {
namespace {

// Funciones nativas del juego (file_008) para cargar/guardar un slot a/desde los globals.
extern "C" void func_801423C8_103AB98(uint8_t* rdram, recomp_context* ctx);  // lee slot + deserializa
extern "C" void func_80142450_103AC20(uint8_t* rdram, recomp_context* ctx);  // serializa + escribe slot

// Direcciones de los campos vivos (módulo 8).
constexpr uint32_t kProgressAddr = 0x801BBBF4;  // u16 BE = N*10+P
constexpr uint32_t kLevelAddr = 0x8017DC88;     // u8
constexpr uint32_t kStatBase = 0x8017DC40;      // struct de stats del PJ
constexpr uint32_t kTechBase = 0x80183CE0;      // 86 x 6 (flag en +0)
constexpr uint32_t kItemBase = 0x8017E004;      // 45 x 8 (cantidad en +4)
constexpr size_t kBodyBase[4] = {0x10, 0x1C, 0x68, 0x76};  // offense, defense, hit, damage

// Arrays de punteros a nombres.
constexpr uint32_t kTechNamePtrs = 0x80184140;
constexpr uint32_t kItemNamePtrs = 0x8017DF50;

uint8_t* g_rdram = nullptr;
bool g_loaded = false;

// La RDRAM guarda los bytes del guest con word-swap: byte en la dirección `a` -> rdram[(a-base)^3].
uint8_t* mem() {
    if (g_rdram == nullptr) g_rdram = hh::get_game_rdram();
    return g_rdram;
}
uint8_t rd8(uint32_t addr) {
    uint8_t* r = mem();
    if (r == nullptr || addr < 0x80000000u) return 0;
    return r[(addr - 0x80000000u) ^ 3u];
}
void wr8(uint32_t addr, uint8_t v) {
    uint8_t* r = mem();
    if (r == nullptr || addr < 0x80000000u) return;
    r[(addr - 0x80000000u) ^ 3u] = v;
}
uint16_t rd16(uint32_t addr) {
    return static_cast<uint16_t>((rd8(addr) << 8) | rd8(addr + 1));
}
void wr16(uint32_t addr, uint16_t v) {
    wr8(addr, static_cast<uint8_t>(v >> 8));
    wr8(addr + 1, static_cast<uint8_t>(v & 0xFF));
}

uint32_t guest_u32(uint32_t addr) {
    return (static_cast<uint32_t>(rd8(addr)) << 24) | (static_cast<uint32_t>(rd8(addr + 1)) << 16) |
           (static_cast<uint32_t>(rd8(addr + 2)) << 8) | static_cast<uint32_t>(rd8(addr + 3));
}
std::string guest_str(uint32_t addr, size_t max_len = 40) {
    std::string out;
    bool hi = false;
    for (size_t i = 0; i < max_len; ++i) {
        const uint8_t c = rd8(addr + static_cast<uint32_t>(i));
        if (c == 0) break;
        if (c >= 0x80) {   // separador EUC (p. ej. A1B8) -> un espacio
            if (!hi) { out.push_back(' '); hi = true; }
        } else {
            out.push_back(static_cast<char>(c));
            hi = false;
        }
    }
    return out;
}

// Llama a una función nativa con a0/a1, heredando la pila (sp/r29) del contexto del handler.
void call_native(void (*fn)(uint8_t*, recomp_context*), recomp_context* base_ctx, uint32_t a0,
                 uint32_t a1) {
    uint8_t* r = mem();
    if (r == nullptr || base_ctx == nullptr) return;
    recomp_context ctx = *base_ctx;   // sp/r29 valido (la funcion nativa usa la pila)
    ctx.r4 = a0;
    ctx.r5 = a1;
    fn(r, &ctx);
}

}  // namespace

bool load(int slot, uint8_t* rdram, recomp_context* base_ctx) {
    (void)rdram;
    if (slot < 0 || slot >= kSlots) return false;
    const uint16_t before = progress();
    call_native(func_801423C8_103AB98, base_ctx, 0, static_cast<uint32_t>(slot));
    g_loaded = true;
    hh::log("[save-edit] cargado slot %d (memoria): progress %u -> %u level=%u\n", slot,
            (unsigned)before, (unsigned)progress(), (unsigned)level());
    return true;
}

bool save(int slot, uint8_t* rdram, recomp_context* base_ctx) {
    (void)rdram;
    if (slot < 0 || slot >= kSlots || !g_loaded) return false;
    call_native(func_80142450_103AC20, base_ctx, 0, static_cast<uint32_t>(slot));
    hh::log("[save-edit] guardado slot %d (memoria)\n", slot);
    return true;
}

bool loaded() { return g_loaded; }
void unload() { g_loaded = false; }
int slot_count() { return kSlots; }

uint16_t progress() { return rd16(kProgressAddr); }
void set_progress(uint16_t v) { wr16(kProgressAddr, v); }

uint8_t level() { return rd8(kLevelAddr); }
void set_level(uint8_t v) { wr8(kLevelAddr, v); }

bool tech_learned(int id) {
    if (id < 0 || id >= kTechCount) return false;
    return rd8(kTechBase + static_cast<uint32_t>(id) * 6) != 0;
}
void set_tech_learned(int id, bool on) {
    if (id < 0 || id >= kTechCount) return;
    wr8(kTechBase + static_cast<uint32_t>(id) * 6, on ? 1 : 0);
}

uint16_t body_stat(int part, int kind) {
    if (part < 0 || part >= kParts || kind < 0 || kind > 3) return 0;
    return rd16(kStatBase + static_cast<uint32_t>(kBodyBase[kind]) +
               static_cast<uint32_t>(part) * 2);
}
void set_body_stat(int part, int kind, uint16_t v) {
    if (part < 0 || part >= kParts || kind < 0 || kind > 3) return;
    wr16(kStatBase + static_cast<uint32_t>(kBodyBase[kind]) + static_cast<uint32_t>(part) * 2, v);
}

uint8_t item_count(int id) {
    if (id < 0 || id >= kItemCount) return 0;
    return rd8(kItemBase + static_cast<uint32_t>(id) * 8 + 4);
}
void set_item_count(int id, uint8_t v) {
    if (id < 0 || id >= kItemCount) return;
    wr8(kItemBase + static_cast<uint32_t>(id) * 8 + 4, v);
}

std::string tech_name(int id) {
    if (id < 0 || id >= kTechCount) return std::string();
    std::string s = guest_str(guest_u32(kTechNamePtrs + static_cast<uint32_t>(id) * 4));
    if (s.empty()) s = "TECH " + std::to_string(id + 1);
    return s;
}

std::string item_name(int id) {
    if (id < 0 || id >= kItemCount) return std::string();
    std::string s = guest_str(guest_u32(kItemNamePtrs + static_cast<uint32_t>(id) * 4));
    if (s.empty()) s = "ITEM " + std::to_string(id + 1);
    return s;
}

}  // namespace hh::save
