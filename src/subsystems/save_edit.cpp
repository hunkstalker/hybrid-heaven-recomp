// hh_saveedit — editor del `.pak` de guardado. Ver include/hh/save_edit.h y
// notes/2026-09-27-e-editor-partida-plan.md.

#include "hh.h"
#include "hh/save_edit.h"

#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <vector>

// Del fork del runtime (lib/N64ModernRuntime, pak.cpp): descarta el pak cacheado y lo relee del
// disco. Necesario para que el juego vea los cambios escritos por el editor.
extern "C" void hh_pak_reload_from_disk(void);

namespace hh::save {
namespace {

// Layout del `.pak` (medido): magic(4) + count(4) + 1 fichero (19) + data.
constexpr size_t kDataOff = 0x1B;
constexpr size_t kHeaderSize = 0x100;
constexpr size_t kSlotSize = 0xD00;
constexpr size_t kSlot0 = kDataOff + kHeaderSize;

// Offsets dentro del slot.
constexpr size_t kStatOff = 0x000;     // copia del struct 0x8017DC40 (0x9E)
constexpr size_t kTechOff = 0x09E;     // 86 x 3: [flag, mastery_low, uses]
constexpr size_t kItemOff = 0x1A0;     // 45 x u8
constexpr size_t kFlagsOff = 0x300;    // 0x64
constexpr size_t kProgressOff = 0x366; // u16 BE = N*10+P
constexpr size_t kChecksumOff = 0xCFC;

// Offsets dentro del struct de stats (copiado a kStatOff).
constexpr size_t kLevelOff = 0x48;
constexpr size_t kBodyBase[4] = {0x10, 0x1C, 0x68, 0x76};  // offense, defense, hit, damage

// Direcciones RDRAM (modulo 8) de los arrays de punteros a nombres.
constexpr uint32_t kTechNamePtrs = 0x80184140;
constexpr uint32_t kItemNamePtrs = 0x8017DF50;

std::vector<uint8_t> g_bytes;
std::filesystem::path g_path;
bool g_loaded = false;
bool g_tried = false;

size_t slot_off(int slot) { return kSlot0 + static_cast<size_t>(slot) * kSlotSize; }

bool in_slot(int slot, size_t rel, size_t n) {
    return slot >= 0 && slot < kSlots && rel + n <= kSlotSize;
}
uint8_t rd8(int slot, size_t rel) {
    if (!in_slot(slot, rel, 1)) return 0;
    return g_bytes[slot_off(slot) + rel];
}
void wr8(int slot, size_t rel, uint8_t v) {
    if (in_slot(slot, rel, 1)) g_bytes[slot_off(slot) + rel] = v;
}
uint16_t rd16(int slot, size_t rel) {
    return static_cast<uint16_t>((rd8(slot, rel) << 8) | rd8(slot, rel + 1));
}
void wr16(int slot, size_t rel, uint16_t v) {
    wr8(slot, rel, static_cast<uint8_t>(v >> 8));
    wr8(slot, rel + 1, static_cast<uint8_t>(v & 0xFF));
}

std::filesystem::path find_pak() {
    std::error_code ec;
    const std::filesystem::path dir = hh::get_app_folder_path() / "saves";
    if (!std::filesystem::exists(dir, ec)) return {};
    for (const auto& e : std::filesystem::directory_iterator(dir, ec)) {
        if (e.is_regular_file(ec) && e.path().extension() == ".pak") {
            return e.path();
        }
    }
    return {};
}

// La RDRAM del runtime guarda los bytes del guest con word-swap: el byte del guest en la direccion
// `a` vive en `rdram[(a - base) ^ 3]` (mismo convenio que el resto del port).
uint8_t guest_u8(const uint8_t* rdram, uint32_t addr) {
    return rdram[(addr - 0x80000000u) ^ 3u];
}

// Lee un u32 big-endian del guest (0 si no esta disponible).
uint32_t guest_u32(uint32_t addr) {
    const uint8_t* rdram = hh::get_game_rdram();
    if (rdram == nullptr || addr < 0x80000000u) return 0;
    const uint32_t o = addr - 0x80000000u;
    if (o + 4 > 8u * 1024u * 1024u) return 0;
    return (static_cast<uint32_t>(guest_u8(rdram, addr)) << 24) |
           (static_cast<uint32_t>(guest_u8(rdram, addr + 1)) << 16) |
           (static_cast<uint32_t>(guest_u8(rdram, addr + 2)) << 8) |
           static_cast<uint32_t>(guest_u8(rdram, addr + 3));
}

// Nombre del guest: bytes ASCII; los separadores EUC (>= 0x80, p. ej. A1B8) se muestran como un
// espacio. La fuente del overlay no pinta EUC crudo.
std::string guest_str(uint32_t addr, size_t max_len = 40) {
    const uint8_t* rdram = hh::get_game_rdram();
    std::string out;
    if (rdram == nullptr || addr < 0x80000000u) return out;
    bool hi = false;
    for (size_t i = 0; i < max_len; ++i) {
        const uint32_t a = addr + static_cast<uint32_t>(i);
        if (a - 0x80000000u + 3 >= 8u * 1024u * 1024u) break;
        const uint8_t c = guest_u8(rdram, a);
        if (c == 0) break;
        if (c >= 0x80) {
            if (!hi) {
                out.push_back(' ');
                hi = true;
            }
        } else {
            out.push_back(static_cast<char>(c));
            hi = false;
        }
    }
    return out;
}

}  // namespace

bool load() {
    if (g_loaded) return true;
    if (g_tried) return false;
    g_tried = true;
    g_path = find_pak();
    if (g_path.empty()) {
        hh::log("[save-edit] no se encontro ningun .pak en saves/\n");
        return false;
    }
    std::ifstream in(g_path, std::ios::binary);
    if (!in) return false;
    std::vector<uint8_t> data((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    if (data.size() < kSlot0 + kSlots * kSlotSize) {
        hh::log("[save-edit] %s demasiado corto (%zu B)\n", g_path.string().c_str(), data.size());
        return false;
    }
    if (std::memcmp(data.data(), "HHPK", 4) != 0) {
        hh::log("[save-edit] %s no es un .pak HHPK\n", g_path.string().c_str());
        return false;
    }
    g_bytes = std::move(data);
    g_loaded = true;
    hh::log("[save-edit] cargado %s (%zu B)\n", g_path.string().c_str(), g_bytes.size());
    return true;
}

bool loaded() { return g_loaded; }

void unload() {
    g_bytes.clear();
    g_path.clear();
    g_loaded = false;
    g_tried = false;
}

int slot_count() { return kSlots; }

bool slot_used(int slot) {
    if (!g_loaded) return false;
    return rd16(slot, kProgressOff) != 0 || rd8(slot, kChecksumOff) != 0;
}

uint16_t progress(int slot) { return rd16(slot, kProgressOff); }
void set_progress(int slot, uint16_t v) { wr16(slot, kProgressOff, v); }

uint8_t level(int slot) { return rd8(slot, kStatOff + kLevelOff); }
void set_level(int slot, uint8_t v) { wr8(slot, kStatOff + kLevelOff, v); }

bool tech_learned(int slot, int id) {
    if (id < 0 || id >= kTechCount) return false;
    return rd8(slot, kTechOff + static_cast<size_t>(id) * 3) != 0;
}
void set_tech_learned(int slot, int id, bool on) {
    if (id < 0 || id >= kTechCount) return;
    wr8(slot, kTechOff + static_cast<size_t>(id) * 3, on ? 1 : 0);
}

uint16_t body_stat(int slot, int part, int kind) {
    if (part < 0 || part >= kParts || kind < 0 || kind > 3) return 0;
    return rd16(slot, kStatOff + kBodyBase[kind] + static_cast<size_t>(part) * 2);
}
void set_body_stat(int slot, int part, int kind, uint16_t v) {
    if (part < 0 || part >= kParts || kind < 0 || kind > 3) return;
    wr16(slot, kStatOff + kBodyBase[kind] + static_cast<size_t>(part) * 2, v);
}

uint8_t item_count(int slot, int id) {
    if (id < 0 || id >= kItemCount) return 0;
    return rd8(slot, kItemOff + static_cast<size_t>(id));
}
void set_item_count(int slot, int id, uint8_t v) {
    if (id < 0 || id >= kItemCount) return;
    wr8(slot, kItemOff + static_cast<size_t>(id), v);
}

bool save() {
    if (!g_loaded) return false;
    // Recalcula el checksum de cada slot (incluye el propio slot; los bytes +0xCFD..+0xCFF quedan 0).
    for (int s = 0; s < kSlots; ++s) {
        const size_t base = slot_off(s);
        unsigned sum = 0;
        for (size_t i = 0; i < kChecksumOff; ++i) sum += g_bytes[base + i];
        g_bytes[base + kChecksumOff] = static_cast<uint8_t>(sum & 0xFF);
        g_bytes[base + kChecksumOff + 1] = 0;
        g_bytes[base + kChecksumOff + 2] = 0;
        g_bytes[base + kChecksumOff + 3] = 0;
    }
    // Escritura atomica: escribe un temporal y renombra.
    const std::filesystem::path tmp = g_path.string() + ".tmp";
    {
        std::ofstream out(tmp, std::ios::binary | std::ios::trunc);
        if (!out) return false;
        out.write(reinterpret_cast<const char*>(g_bytes.data()),
                  static_cast<std::streamsize>(g_bytes.size()));
        if (!out) return false;
    }
    std::error_code ec;
    std::filesystem::rename(tmp, g_path, ec);
    if (ec) {
        std::filesystem::remove(tmp, ec);
        hh::log("[save-edit] no se pudo renombrar %s: %s\n", tmp.string().c_str(), ec.message().c_str());
        return false;
    }
    hh::log("[save-edit] guardado %s\n", g_path.string().c_str());
    // El runtime cachea el pak: forzar recarga para que CONTINUAR lea lo editado.
    hh_pak_reload_from_disk();
    return true;
}

void revert() {
    if (g_path.empty()) return;
    g_loaded = false;
    g_tried = false;
    load();
}

std::string tech_name(int id) {
    if (id < 0 || id >= kTechCount) return std::string();
    const uint32_t ptr = guest_u32(kTechNamePtrs + static_cast<uint32_t>(id) * 4);
    std::string s = guest_str(ptr);
    if (s.empty()) s = "TECH " + std::to_string(id + 1);
    return s;
}

std::string item_name(int id) {
    if (id < 0 || id >= kItemCount) return std::string();
    const uint32_t ptr = guest_u32(kItemNamePtrs + static_cast<uint32_t>(id) * 4);
    std::string s = guest_str(ptr);
    if (s.empty()) s = "ITEM " + std::to_string(id + 1);
    return s;
}

}  // namespace hh::save
