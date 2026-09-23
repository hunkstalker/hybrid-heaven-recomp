// Fase B (ADR 0007) - cache de assets del loader `trans` (FUN_80003824).
//
// El juego carga cada modulo con FUN_80003824: lee el asset comprimido de la ROM por PI DMA y lo
// descomprime LZKN64 en RDRAM, de forma SINCRONA dentro del tick (stalls de 0,25 s a varios
// segundos). Este modulo intercepta el loader (wrapper en librecomp/src/overlays.cpp) y:
//
//  - HIT  -> copia los bytes ya descomprimidos desde `cache/trans.bin` (sin ROM, sin descomprimir)
//            y devuelve el mismo valor que el loader original (r2 = dst + len).
//  - MISS -> reimplementacion nativa del decodificador LZKN64 (identica a tools/lzkn64/lzkn64.py)
//            leida directamente de la ROM, y alta en el cache. Si la nativa falla (p. ej. la
//            variante no-LZKN64) se recurre al loader original.
//
// El cache guarda los bytes en ORDEN GUEST (el mismo flujo que produce lzkn64.py). La escritura a
// RDRAM se hace con la permutacion de palabra del port (`store_guest`), exacta para cualquier
// longitud (no solo multiplos de 4).
//
// Knobs:
//   HH_TRANS_CACHE=0   desactiva el cache (siempre loader original; para A/B).
//   HH_TRANS_NATIVE=0  desactiva la descompresion nativa en miss (usa el loader original).
//   HH_TRANS_VERIFY=1  ejecuta el loader original en cada carga y compara cache/nativo (mas lento).
//   HH_TRANS_DUMP=1    log por carga a stderr (src/dst/size/len/hit-miss/verify/us).
//
// Siempre se anota una linea por carga en hh.log (`[trans] load ...`), util para diagnosticar.
//
// Ver docs/adr/0007-cache-assets-y-loader-nativo.md y
// notes/2026-09-18-faseb-cache-trans-implementado.md.

#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <mutex>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

#include "recomp.h"
#include "librecomp/game.hpp"

#include "hh.h"

namespace {

constexpr uint32_t kGuestBase = 0x80000000u;
constexpr uint32_t kMaxOut = 8u * 1024u * 1024u;  // RDRAM; el modulo mayor real ronda el MB
constexpr char kMagic[8] = {'H', 'H', 'T', 'R', 'A', 'N', 'S', '1'};
constexpr uint32_t kVersion = 2;  // v2: payload en orden guest (v1 era layout host)
constexpr size_t kHeaderSize = 8 + 4 + 4 + 8;  // magic + (version:count) + rom_hash

struct Config {
    bool cache = true;
    bool native = true;
    bool verify = false;
    bool dump = false;
};

bool env_flag(const char* name, bool def) {
    const char* v = std::getenv(name);
    if (v == nullptr || *v == '\0') return def;
    return !(v[0] == '0' && v[1] == '\0');
}

Config& config() {
    static Config c = [] {
        Config r;
        r.cache = env_flag("HH_TRANS_CACHE", true);
        r.native = env_flag("HH_TRANS_NATIVE", true);
        r.verify = env_flag("HH_TRANS_VERIFY", false);
        r.dump = env_flag("HH_TRANS_DUMP", false);
        return r;
    }();
    return c;
}

struct Entry {
    uint64_t off;  // offset del payload (orden guest) dentro de g_data
    uint32_t len;
};

std::recursive_mutex g_mutex;
bool g_init = false;
bool g_enabled = false;
uint64_t g_rom_hash = 0;
std::unordered_map<uint64_t, Entry> g_index;
std::vector<uint8_t> g_data;  // fichero entero en memoria (cabecera + registros)
std::filesystem::path g_path;
uint64_t g_hits = 0, g_native_ok = 0, g_native_fail = 0, g_real = 0, g_verify_bad = 0;

inline uint64_t key_of(uint32_t src, uint32_t size) {
    return (static_cast<uint64_t>(src) << 32) | size;
}

uint32_t be32(const uint8_t* p) {
    return (static_cast<uint32_t>(p[0]) << 24) | (static_cast<uint32_t>(p[1]) << 16) |
           (static_cast<uint32_t>(p[2]) << 8) | static_cast<uint32_t>(p[3]);
}

void put_u32(uint8_t* p, uint32_t v) {
    p[0] = static_cast<uint8_t>(v);
    p[1] = static_cast<uint8_t>(v >> 8);
    p[2] = static_cast<uint8_t>(v >> 16);
    p[3] = static_cast<uint8_t>(v >> 24);
}

void put_u64(uint8_t* p, uint64_t v) {
    for (int i = 0; i < 8; i++) p[i] = static_cast<uint8_t>(v >> (8 * i));
}

uint64_t get_u64(const uint8_t* p) {
    uint64_t v = 0;
    for (int i = 0; i < 8; i++) v |= static_cast<uint64_t>(p[i]) << (8 * i);
    return v;
}

uint64_t rom_hash() {
    std::span<const uint8_t> rom = recomp::get_rom();
    uint64_t h = UINT64_C(1469598103934665603);  // FNV-1a 64
    for (uint8_t b : rom) {
        h ^= b;
        h *= UINT64_C(1099511628211);
    }
    return h;
}

// Escribe `len` bytes en orden guest (big-endian por palabra) al destino guest `dst`. El modelo de
// memoria del port guarda cada palabra guest en little-endian host, por lo que el byte guest `i`
// cae en el indice host `(dst-base+i) ^ 3`.
void store_guest(uint8_t* rdram, uint32_t dst, const uint8_t* src, uint32_t len) {
    uint8_t* p = rdram + (dst - kGuestBase);
    uint32_t i = 0;
    for (; i + 4 <= len; i += 4) {
        p[i + 0] = src[i + 3];
        p[i + 1] = src[i + 2];
        p[i + 2] = src[i + 1];
        p[i + 3] = src[i + 0];
    }
    for (; i < len; i++) p[i ^ 3u] = src[i];
}

// Inversa de store_guest: extrae `len` bytes en orden guest desde RDRAM.
void read_guest(const uint8_t* rdram, uint32_t dst, uint8_t* out, uint32_t len) {
    const uint8_t* p = rdram + (dst - kGuestBase);
    for (uint32_t i = 0; i < len; i++) out[i] = p[i ^ 3u];
}

// Escribe a RDRAM aplicando antes la traduccion de texto (HH_LANG). No muta `src` (el cache
// persistente debe quedar en el idioma original). Ver src/subsystems/text.cpp.
void store_guest_translated(uint8_t* rdram, uint32_t dst, const uint8_t* src, uint32_t len) {
    if (hh::text_enabled() && (dst & 3u) == 0u && len != 0) {
        static std::vector<uint8_t> scratch;
        scratch.assign(src, src + len);
        if (hh_text_translate_guest(scratch.data(), len) > 0) {
            store_guest(rdram, dst, scratch.data(), len);
            return;
        }
    }
    store_guest(rdram, dst, src, len);
}

// Aplica la traduccion a un bloque ya escrito en RDRAM por el loader original (fallback).
void translate_rdram(uint8_t* rdram, uint32_t dst, uint32_t len) {
    if (!hh::text_enabled() || (dst & 3u) != 0u || len == 0) return;
    static std::vector<uint8_t> scratch;
    scratch.resize(len);
    read_guest(rdram, dst, scratch.data(), len);
    if (hh_text_translate_guest(scratch.data(), len) > 0) {
        store_guest(rdram, dst, scratch.data(), len);
    }
}

// Modulos cargados actualmente (para cambiar el idioma en vivo re-aplicando a RDRAM sin recargar).
struct Loaded {
    uint32_t src;
    uint32_t size;
    uint32_t dst;
    uint32_t len;
};
std::vector<Loaded> g_loaded;

void remember_loaded(uint32_t src, uint32_t size, uint32_t dst, uint32_t len) {
    if (len == 0) return;
    for (Loaded& e : g_loaded) {
        if (e.src == src && e.size == size && e.dst == dst) {
            e.len = len;
            return;
        }
    }
    g_loaded.push_back({src, size, dst, len});
}

// Decodificador LZKN64 identico a tools/lzkn64/lzkn64.py. `in_len` = bytes disponibles (a2 del
// loader). El header de 4 bytes es el tamano comprimido (limite del bucle de entrada).
bool lzkn64_decode(const uint8_t* in, size_t in_len, std::vector<uint8_t>& out) {
    out.clear();
    if (in_len < 5) return false;
    uint32_t size = be32(in);
    if (size < 4 || size > in_len) return false;
    if ((size & 0xF0000000u) != 0) return false;  // variante no-LZKN64: dejar al loader original
    out.reserve(static_cast<size_t>(in_len) * 2);
    size_t pos = 4;
    while (pos < size) {
        uint8_t cmd = in[pos++];
        if (cmd <= 0x7F) {
            uint32_t ln = ((cmd & 0x7Cu) >> 2) + 2;
            if (pos >= size) return false;
            uint32_t off = ((static_cast<uint32_t>(cmd & 0x03u) << 8) | in[pos++]) & 0x3FFu;
            if (off == 0 || off > out.size()) return false;
            size_t base = out.size() - off;
            for (uint32_t i = 0; i < ln; i++) out.push_back(out[base + i]);
        } else if (cmd <= 0x9F) {
            uint32_t ln = cmd & 0x1Fu;
            if (pos + ln > size) return false;
            out.insert(out.end(), in + pos, in + pos + ln);
            pos += ln;
        } else if (cmd <= 0xDF) {
            uint32_t ln = (cmd & 0x1Fu) + 2;
            if (pos >= size) return false;
            uint8_t v = in[pos++];
            out.insert(out.end(), ln, v);
        } else if (cmd <= 0xFE) {
            uint32_t ln = (cmd & 0x1Fu) + 2;
            out.insert(out.end(), ln, 0);
        } else {
            if (pos >= size) return false;
            uint32_t ln = static_cast<uint32_t>(in[pos++]) + 2;
            out.insert(out.end(), ln, 0);
        }
        if (out.size() > kMaxOut) return false;
    }
    return true;
}

void load_cache_locked() {
    g_data.clear();
    g_index.clear();
    std::error_code ec;
    std::filesystem::create_directories(g_path.parent_path(), ec);

    std::FILE* f = std::fopen(g_path.string().c_str(), "rb");
    if (f != nullptr) {
        std::fseek(f, 0, SEEK_END);
        long sz = std::ftell(f);
        std::fseek(f, 0, SEEK_SET);
        if (sz > static_cast<long>(kHeaderSize)) {
            g_data.resize(static_cast<size_t>(sz));
            if (std::fread(g_data.data(), 1, g_data.size(), f) != g_data.size()) g_data.clear();
        }
        std::fclose(f);
    }
    bool valid = g_data.size() >= kHeaderSize && std::memcmp(g_data.data(), kMagic, 8) == 0;
    if (valid && static_cast<uint32_t>(get_u64(g_data.data() + 8) >> 32) != kVersion) valid = false;
    if (valid && get_u64(g_data.data() + 16) != g_rom_hash) valid = false;
    if (!valid) {
        g_data.assign(kHeaderSize, 0);
        std::memcpy(g_data.data(), kMagic, 8);
        put_u64(g_data.data() + 8, static_cast<uint64_t>(kVersion) << 32);
        put_u64(g_data.data() + 16, g_rom_hash);
        return;
    }
    size_t pos = kHeaderSize;
    while (pos + 16 <= g_data.size()) {
        uint32_t src = static_cast<uint32_t>(get_u64(g_data.data() + pos));
        uint32_t size = static_cast<uint32_t>(get_u64(g_data.data() + pos) >> 32);
        uint32_t len = static_cast<uint32_t>(get_u64(g_data.data() + pos + 8));
        if (len > kMaxOut || pos + 16 + len > g_data.size()) {
            g_index.clear();
            break;
        }
        g_index[key_of(src, size)] = Entry{pos + 16, len};
        pos += 16 + len;
    }
    hh::log("[trans] cache cargado: %zu entradas, %.1f MB (%s)\n", g_index.size(),
            static_cast<double>(g_data.size()) / (1024.0 * 1024.0), g_path.string().c_str());
}

void persist_record(uint32_t src, uint32_t size, const uint8_t* data, uint32_t len) {
    size_t off = g_data.size();
    g_data.resize(off + 16 + len);
    uint8_t hdr[16];
    put_u32(hdr, src);
    put_u32(hdr + 4, size);
    put_u32(hdr + 8, len);
    put_u32(hdr + 12, 0);
    std::memcpy(g_data.data() + off, hdr, 16);
    std::memcpy(g_data.data() + off + 16, data, len);
    g_index[key_of(src, size)] = Entry{off + 16, len};

    uint64_t combined = get_u64(g_data.data() + 8);
    uint32_t count = static_cast<uint32_t>(combined) + 1;
    put_u64(g_data.data() + 8, (combined & UINT64_C(0xFFFFFFFF00000000)) | count);

    std::FILE* f = std::fopen(g_path.string().c_str(), "r+b");
    if (f == nullptr) {
        f = std::fopen(g_path.string().c_str(), "wb");
        if (f != nullptr) std::fwrite(g_data.data(), 1, g_data.size(), f);
    } else {
        std::fseek(f, 0, SEEK_END);
        std::fwrite(g_data.data() + off, 1, 16 + len, f);
        std::fseek(f, 8, SEEK_SET);
        std::fwrite(g_data.data() + 8, 1, 8, f);
    }
    if (f != nullptr) std::fclose(f);
}

// Da de alta en el cache la salida del loader original (r2 = dst + len).
void capture_real(uint8_t* rdram, uint32_t src, uint32_t size, uint32_t dst, uint32_t len) {
    if (len == 0 || len > kMaxOut) return;
    if (g_index.count(key_of(src, size)) != 0) return;
    static std::vector<uint8_t> guest;
    guest.resize(len);
    read_guest(rdram, dst, guest.data(), len);
    persist_record(src, size, guest.data(), len);
}

}  // namespace

// Llamada desde el wrapper de FUN_80003824 (librecomp/src/overlays.cpp). Ejecuta el loader
// (cache, nativo o el original) y deja el resultado en ctx->r2.
extern "C" void hh_trans_load(uint8_t* rdram, recomp_context* ctx, recomp_func_t* real_loader) {
    const uint32_t src = static_cast<uint32_t>(ctx->r4);
    const uint32_t dst = static_cast<uint32_t>(ctx->r5);
    const uint32_t size = static_cast<uint32_t>(ctx->r6);
    const Config& cfg = config();
    const auto t0 = std::chrono::steady_clock::now();
    auto us_since = [&t0] {
        return std::chrono::duration<double, std::micro>(std::chrono::steady_clock::now() - t0).count();
    };

    std::lock_guard<std::recursive_mutex> lock(g_mutex);
    if (!g_init) {
        g_init = true;
        g_enabled = cfg.cache;
        if (g_enabled) {
            g_rom_hash = rom_hash();
            g_path = hh::get_app_folder_path() / "cache" / "trans.bin";
            load_cache_locked();
            hh::log("[trans] cache activo (%s, nativo=%d, verify=%d) hash=%016llX\n",
                    g_path.string().c_str(), cfg.native ? 1 : 0, cfg.verify ? 1 : 0,
                    static_cast<unsigned long long>(g_rom_hash));
        } else {
            hh::log("[trans] cache desactivado (HH_TRANS_CACHE=0)\n");
        }
    }

    if (!g_enabled) {
        real_loader(rdram, ctx);
        return;
    }

    const bool aligned = (dst & 3u) == 0u;
    auto it = g_index.find(key_of(src, size));
    const bool hit = it != g_index.end() && aligned;

    auto try_native = [&](std::vector<uint8_t>& out, uint32_t& len) -> bool {
        if (!cfg.native || !aligned) return false;
        std::span<const uint8_t> rom = recomp::get_rom();
        if (static_cast<uint64_t>(src) + size > rom.size()) return false;
        if (!lzkn64_decode(rom.data() + src, size, out) || out.empty() || out.size() > kMaxOut) {
            return false;
        }
        len = static_cast<uint32_t>(out.size());
        return true;
    };

    const char* kind = "real";
    uint32_t out_len = 0;

    // Modo verificacion: el loader original manda. Se compara cache y nativo contra su salida.
    if (cfg.verify) {
        std::vector<uint8_t> native_out;
        uint32_t native_len = 0;
        bool native_ok = try_native(native_out, native_len);
        uint32_t cached_off = hit ? static_cast<uint32_t>(it->second.off) : 0;
        uint32_t cached_len = hit ? it->second.len : 0;
        real_loader(rdram, ctx);
        uint32_t real_len = (static_cast<uint32_t>(ctx->r2) > dst) ? (static_cast<uint32_t>(ctx->r2) - dst) : 0;
        if (real_len > kMaxOut) real_len = 0;
        static std::vector<uint8_t> real_guest;
        real_guest.resize(real_len);
        read_guest(rdram, dst, real_guest.data(), real_len);
        if (hit) {
            bool equal = (cached_len == real_len) &&
                         (std::memcmp(real_guest.data(), g_data.data() + cached_off, real_len) == 0);
            if (!equal) {
                g_verify_bad++;
                std::fprintf(stderr, "[TRANS] VERIFY cache MISMATCH src=%08X size=%06X dst=%08X "
                                     "cache=%u real=%u\n", src, size, dst, cached_len, real_len);
            }
        }
        if (native_ok) {
            bool equal = (native_len == real_len) &&
                         (std::memcmp(native_out.data(), real_guest.data(), real_len) == 0);
            if (!equal) {
                g_verify_bad++;
                std::fprintf(stderr, "[TRANS] VERIFY native MISMATCH src=%08X size=%06X dst=%08X "
                                     "native=%u real=%u\n", src, size, dst, native_len, real_len);
            }
        }
        if (real_len != 0 && !hit) capture_real(rdram, src, size, dst, real_len);
        if (cfg.dump) {
            std::fprintf(stderr, "[TRANS] VERIFY src=%08X dst=%08X hit=%d native=%d real=%u bad=%llu us=%.0f\n",
                         src, dst, hit ? 1 : 0, native_ok ? 1 : 0, real_len,
                         static_cast<unsigned long long>(g_verify_bad), us_since());
        }
        return;
    }

    if (hit) {
        out_len = it->second.len;
        store_guest_translated(rdram, dst, g_data.data() + it->second.off, out_len);
        ctx->r2 = static_cast<uint64_t>(dst) + out_len;
        g_hits++;
        kind = "hit";
    } else {
        std::vector<uint8_t> native_out;
        uint32_t native_len = 0;
        if (try_native(native_out, native_len)) {
            store_guest_translated(rdram, dst, native_out.data(), native_len);
            ctx->r2 = static_cast<uint64_t>(dst) + native_len;
            persist_record(src, size, native_out.data(), native_len);
            g_native_ok++;
            out_len = native_len;
            kind = "native";
        } else {
            g_native_fail++;
            real_loader(rdram, ctx);
            uint32_t real_len = (static_cast<uint32_t>(ctx->r2) > dst) ? (static_cast<uint32_t>(ctx->r2) - dst) : 0;
            if (real_len > kMaxOut) real_len = 0;
            translate_rdram(rdram, dst, real_len);
            capture_real(rdram, src, size, dst, real_len);
            g_real++;
            out_len = real_len;
            std::fprintf(stderr, "[TRANS] nativo NO aplica src=%08X size=%06X -> loader original\n",
                         src, size);
        }
    }

    const double us = us_since();
    hh::log("[trans] load src=%08X size=%06X dst=%08X kind=%s len=%u us=%.0f\n", src, size, dst,
            kind, out_len, us);
    if (cfg.dump) {
        std::fprintf(stderr, "[TRANS] %s src=%08X size=%06X dst=%08X len=%u us=%.0f\n", kind, src,
                     size, dst, out_len, us);
    }
    if (out_len != 0) remember_loaded(src, size, dst, out_len);
}

// Re-aplica el idioma activo a los modulos cargados (cambio en vivo). Mantiene longitudes, asi que
// los punteros del juego siguen validos. Ver src/subsystems/text.cpp.
extern "C" void hh_trans_reapply_language(void) {    std::lock_guard<std::recursive_mutex> lock(g_mutex);
    if (g_loaded.empty()) return;

    uint8_t* rdram = hh::get_game_rdram();
    if (rdram == nullptr) return;

    int count = 0;
    static std::vector<uint8_t> tmp;
    for (const Loaded& e : g_loaded) {
        if ((e.dst & 3u) != 0u) continue;
        tmp.clear();
        auto it = g_index.find(key_of(e.src, e.size));
        if (it != g_index.end()) {
            tmp.assign(g_data.begin() + it->second.off,
                       g_data.begin() + it->second.off + it->second.len);
        } else {
            std::span<const uint8_t> rom = recomp::get_rom();
            if (static_cast<uint64_t>(e.src) + e.size > rom.size()) continue;
            if (!lzkn64_decode(rom.data() + e.src, e.size, tmp)) continue;
        }
        if (tmp.size() != e.len) continue;
        store_guest_translated(rdram, e.dst, tmp.data(), e.len);
        count++;
    }
    hh::log("[text] idioma re-aplicado a %d modulos cargados\n", count);
}

// Base RAM cargada de un modulo (por su offset/tamano de ROM). 0 si no esta cargado. Util para
// calcular direcciones guest de datos inyectados (p. ej. etiquetas del menu PC).
extern "C" uint32_t hh_trans_dst_for(uint32_t src, uint32_t size) {
    std::lock_guard<std::recursive_mutex> lock(g_mutex);
    for (const Loaded& e : g_loaded) {
        if (e.src == src && e.size == size) return e.dst;
    }
    return 0;
}
