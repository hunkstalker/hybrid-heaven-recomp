// hh_saveedit — editor de partida. Ver include/hh/save_edit.h y
// notes/2026-09-27-e-editor-partida-plan.md.
//
// Estrategia (v3, 2026-09-27): editar el SLOT del `.pak` (el fichero de guardado que CONTINUE lee),
// no los globals del juego (que se pisan al arrancar/cargar). El layout del slot es el medido
// comparando `.pak` reales (ver nota): cabecera 0x100 + 4 slots 0xD00; checksum en +0xCFC.
//   - PROGRESO  u16 BE en +0x366 (N*10+P)
//   - NIVEL     u8     en +0x04B
//   - TÉCNICAS  86 x 3 en +0x09E (flag aprendida = byte +0 de cada entrada)
//   - ITEMS     45 x u8 en +0x1A0 (cantidad)
//   - STATS del PJ (bloque de 6 partes, u16 BE): offense +0x010, defense +0x01C, hit +0x068,
//     damage +0x076 (mapa del struct 0x8017DC40). El orden de partes es el del juego.
// Tras guardar se fuerza la recarga del `.pak` del runtime (hh_pak_reload_from_disk, fork NMR).

#include "hh.h"
#include "hh/save_edit.h"

#include <cstring>
#include <filesystem>
#include <fstream>
#include <vector>

#include "recomp.h"

namespace hh::save {
namespace {

constexpr size_t kDataOff = 0x1B;      // en el `.pak`
constexpr size_t kHeaderSize = 0x100;
constexpr size_t kSlotSize = 0xD00;
constexpr size_t kSlot0 = kDataOff + kHeaderSize;

// Offsets DENTRO del slot.
constexpr size_t kLevelOff = 0x04B;
constexpr size_t kTechOff = 0x09E;      // 86 x 3
constexpr size_t kItemOff = 0x1A0;      // 45 x u8
constexpr size_t kProgressOff = 0x366;  // u16 BE
constexpr size_t kChecksumOff = 0xCFC;
// Stats por parte (u16 BE, 6 partes).
constexpr size_t kOffenseOff = 0x010;
constexpr size_t kDefenseOff = 0x01C;
constexpr size_t kHitOff = 0x068;
constexpr size_t kDamageOff = 0x076;

// Nombres (RDRAM, modulo 8).
constexpr uint32_t kTechNamePtrs = 0x80184140;
constexpr uint32_t kItemNamePtrs = 0x8017DF50;
constexpr uint32_t kSceneTable = 0x80175490;

std::vector<uint8_t> g_bytes;   // contenido completo del `.pak`
std::filesystem::path g_path;
bool g_loaded = false;

size_t slot_off(int slot) { return kSlot0 + static_cast<size_t>(slot) * kSlotSize; }
bool in_slot(size_t rel, size_t n) { return rel + n <= kSlotSize; }

uint8_t rd8(int slot, size_t rel) {
    if (!g_loaded || slot < 0 || slot >= kSlots || !in_slot(rel, 1)) return 0;
    return g_bytes[slot_off(slot) + rel];
}
void wr8(int slot, size_t rel, uint8_t v) {
    if (!g_loaded || slot < 0 || slot >= kSlots || !in_slot(rel, 1)) return;
    g_bytes[slot_off(slot) + rel] = v;
}
uint16_t rd16(int slot, size_t rel) { return static_cast<uint16_t>((rd8(slot, rel) << 8) | rd8(slot, rel + 1)); }
void wr16(int slot, size_t rel, uint16_t v) {
    wr8(slot, rel, static_cast<uint8_t>(v >> 8));
    wr8(slot, rel + 1, static_cast<uint8_t>(v & 0xFF));
}

// RDRAM del guest (para nombres y tabla de escenas).
uint8_t* g_rdram = nullptr;
uint8_t* mem() {
    if (g_rdram == nullptr) g_rdram = hh::get_game_rdram();
    return g_rdram;
}
uint8_t grd8(uint32_t addr) {
    uint8_t* r = mem();
    if (r == nullptr || addr < 0x80000000u) return 0;
    return r[(addr - 0x80000000u) ^ 3u];
}
uint32_t guest_u32(uint32_t addr) {
    return (static_cast<uint32_t>(grd8(addr)) << 24) | (static_cast<uint32_t>(grd8(addr + 1)) << 16) |
           (static_cast<uint32_t>(grd8(addr + 2)) << 8) | static_cast<uint32_t>(grd8(addr + 3));
}
std::string guest_str(uint32_t addr, size_t max_len = 40) {
    std::string out;
    bool hi = false;
    for (size_t i = 0; i < max_len; ++i) {
        const uint8_t c = grd8(addr + static_cast<uint32_t>(i));
        if (c == 0) break;
        if (c >= 0x80) { if (!hi) { out.push_back(' '); hi = true; } }
        else { out.push_back(static_cast<char>(c)); hi = false; }
    }
    return out;
}

std::filesystem::path find_pak() {
    std::error_code ec;
    const std::filesystem::path dir = hh::get_app_folder_path() / "saves";
    if (!std::filesystem::exists(dir, ec)) return {};
    for (const auto& e : std::filesystem::directory_iterator(dir, ec)) {
        if (e.is_regular_file(ec) && e.path().extension() == ".pak") return e.path();
    }
    return {};
}

}  // namespace

bool load(int slot, uint8_t* rdram, recomp_context* base_ctx) {
    (void)slot; (void)rdram; (void)base_ctx;
    if (g_loaded) return true;
    g_path = find_pak();
    if (g_path.empty()) { hh::log("[save-edit] no hay .pak en saves/\n"); return false; }
    std::ifstream in(g_path, std::ios::binary);
    if (!in) return false;
    g_bytes.assign((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    if (g_bytes.size() < kSlot0 + kSlots * kSlotSize || std::memcmp(g_bytes.data(), "HHPK", 4) != 0) {
        hh::log("[save-edit] .pak invalido (%zu B)\n", g_bytes.size());
        g_bytes.clear();
        return false;
    }
    g_loaded = true;
    hh::log("[save-edit] .pak cargado (%zu B)\n", g_bytes.size());
    return true;
}

bool save(int slot, uint8_t* rdram, recomp_context* base_ctx) {
    (void)rdram; (void)base_ctx;
    if (!g_loaded || slot < 0 || slot >= kSlots) return false;
    // Recalcula checksums de todos los slots y escribe el fichero (tmp + rename).
    for (int s = 0; s < kSlots; ++s) {
        const size_t base = slot_off(s);
        unsigned sum = 0;
        for (size_t i = 0; i < kChecksumOff; ++i) sum += g_bytes[base + i];
        g_bytes[base + kChecksumOff] = static_cast<uint8_t>(sum & 0xFF);
        g_bytes[base + kChecksumOff + 1] = 0;
        g_bytes[base + kChecksumOff + 2] = 0;
        g_bytes[base + kChecksumOff + 3] = 0;
    }
    const std::filesystem::path tmp = g_path.string() + ".tmp";
    {
        std::ofstream out(tmp, std::ios::binary | std::ios::trunc);
        if (!out) return false;
        out.write(reinterpret_cast<const char*>(g_bytes.data()),
                  static_cast<std::streamsize>(g_bytes.size()));
    }
    std::error_code ec;
    std::filesystem::rename(tmp, g_path, ec);
    if (ec) {
        std::filesystem::remove(tmp, ec);
        hh::log("[save-edit] no se pudo escribir %s: %s\n", g_path.string().c_str(),
                ec.message().c_str());
        return false;
    }
    hh::log("[save-edit] guardado slot %d (.pak)\n", slot);
    return true;
}

bool loaded() { return g_loaded; }
void unload() { g_bytes.clear(); g_path.clear(); g_loaded = false; }
int slot_count() { return kSlots; }

bool slot_used(int slot) {
    if (!g_loaded) load(slot, nullptr, nullptr);
    return rd16(slot, kProgressOff) != 0;
}

// Campos por slot.
uint16_t progress_of(int slot) { return rd16(slot, kProgressOff); }
void set_progress_of(int slot, uint16_t v) { wr16(slot, kProgressOff, v); }
uint8_t level_of(int slot) { return rd8(slot, kLevelOff); }
void set_level_of(int slot, uint8_t v) { wr8(slot, kLevelOff, v); }

bool tech_learned_of(int slot, int id) {
    if (id < 0 || id >= kTechCount) return false;
    return rd8(slot, kTechOff + static_cast<size_t>(id) * 3) != 0;
}
void set_tech_learned_of(int slot, int id, bool on) {
    if (id < 0 || id >= kTechCount) return;
    wr8(slot, kTechOff + static_cast<size_t>(id) * 3, on ? 1 : 0);
}

uint16_t body_stat_of(int slot, int part, int kind) {
    if (part < 0 || part >= kParts || kind < 0 || kind > 3) return 0;
    static const size_t kOff[4] = {kOffenseOff, kDefenseOff, kHitOff, kDamageOff};
    return rd16(slot, kOff[kind] + static_cast<size_t>(part) * 2);
}
void set_body_stat_of(int slot, int part, int kind, uint16_t v) {
    if (part < 0 || part >= kParts || kind < 0 || kind > 3) return;
    static const size_t kOff[4] = {kOffenseOff, kDefenseOff, kHitOff, kDamageOff};
    wr16(slot, kOff[kind] + static_cast<size_t>(part) * 2, v);
}

uint8_t item_count_of(int slot, int id) {
    if (id < 0 || id >= kItemCount) return 0;
    return rd8(slot, kItemOff + static_cast<size_t>(id));
}
void set_item_count_of(int slot, int id, uint8_t v) {
    if (id < 0 || id >= kItemCount) return;
    wr8(slot, kItemOff + static_cast<size_t>(id), v);
}

void valid_points_by_level(int out_points[30]) {
    static const int kFallback[30] = {7, 10, 9, 9, 10, 8, 6, 9, 6, 9, 6, 10, 10, 10, 10,
                                      10, 10, 10, 10, 7, 5, 10, 1, 1, 8, 10, 10, 1, 1, 1};
    bool ok = false;
    for (int lvl = 0; lvl < 30; ++lvl) {
        int n = 0;
        for (int p = 0; p < 10; ++p) {
            const uint32_t addr = kSceneTable + static_cast<uint32_t>(lvl * 10 + p) * 4;
            if (guest_u32(addr) != 0) n++;
        }
        out_points[lvl] = n;
        if (n > 0) ok = true;
    }
    if (!ok) for (int i = 0; i < 30; ++i) out_points[i] = kFallback[i];
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
