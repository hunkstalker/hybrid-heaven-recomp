// B (backend_game): inyeccion de glifos acentuados en el motor de texto del juego.
//
// La fuente es 2bpp con pares de glifos empaquetados por bloque (ver
// notes/2026-09-23-b-fuente-formato-y-gaiji.md): `func_8001BFE4` carga `stride` bytes en el buffer
// de trabajo 0x801077E0 y `func_8001C0B0` selecciona el glifo por el bit bajo del valor.
//
// Overrides (patron ADR 0002, sin tocar el C generado):
//   - func_8001D394 (color, codigo EUC) -> valor: para nuestros codigos devuelve el `value` de un
//     **donante ASCII** (resuelto con el propio motor), no un valor inventado.
//   - func_8001BFE4 (color, valor) -> carga el bloque: sirve nuestro bitmap SOLO si el `value`
//     procede de nuestro `d394` (marca de origen), nunca por `value` a secas.
//
// Dos estilos, elegidos por el `stride` del color (tabla tblA en 0x80044624):
//   - color0 (8x8, stride 32): menus ASCII; glifos de `include/hh/accent_glyphs.h`.
//   - color4 (8x12, stride 48): **dialogos** (texto EUC); glifos de `include/hh/game_font_color4.h`
//     (misma tipografia que los subtitulos; ver notes/2026-10-06-dialogos-estructura-nodos-y-a-plus.md).
//
// Los codigos de cada estilo son sinteticos (B1xx) y **coinciden en el espacio**, pero el color
// (stride) los desambigua: el menu usa color0, el dialogo color4.
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <vector>

#include "librecomp/overlays.hpp"
#include "recomp.h"
#include "hh.h"
#include "hh/overlay.h"
#include "hh/accent_glyphs.h"      // color0 8x8
#include "hh/game_font_color4.h"   // color4 8x12

extern "C" void func_8001D394_1DF94(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8001BFE4_1CBE4(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8001B204_1BE04(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80018E9C_19A9C(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80019038_19C38(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8001A01C_1AC1C(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8001A0A4_1ACA4(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8001800C_18C0C(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80017BB8_187B8(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_800179B0_185B0(uint8_t* rdram, recomp_context* ctx);

namespace {

// Buffer de trabajo del motor (verificado por traza HH_FONT_TRACE en Windows/Linux).
constexpr uint32_t kGlyphScratch = 0x801077E0u;
// tblA (0x80044624): bytes por glifo por color (32,50,60,78,48,78).
constexpr uint32_t kTblA = 0x80044624u;

// Donante ASCII: codigo EUC de '@' (tabla ASCII->EUC del motor). Se elige '@' porque es poco
// frecuente y da un `value` no nulo (con value 0 el motor no llamaria a `func_8001BFE4`).
constexpr unsigned kDonorCode = 0xA1F7u;

unsigned color_stride(uint8_t* rdram, unsigned color) {
    return rdram[(kTblA + color - 0x80000000u) ^ 3u];
}

int accent_by_code(unsigned code) {
    for (unsigned i = 0; i < hh::kAccentGlyphCount; ++i) {
        if (hh::kAccentGlyphs[i].code == code) return static_cast<int>(i);
    }
    return -1;
}

int game_by_code(unsigned code) {
    for (unsigned i = 0; i < hh::kGameGlyphCount; ++i) {
        if (hh::kGameGlyphs[i].code == code) return static_cast<int>(i);
    }
    return -1;
}

enum class Which { Color0, Color4 };

// Ultimo `d394` visto. Solo servimos el glifo en `bfe4` si procede de uno de los nuestros.
struct Pending {
    bool active = false;
    uint8_t color = 0;
    uint16_t value = 0;
    int index = -1;
    Which which = Which::Color0;
};
Pending g_pending;

// `value` del donante para este color, resuelto por el MISMO motor (d394 original). Cacheado.
uint16_t donor_value(uint8_t* rdram, const recomp_context* ctx, unsigned color) {
    static uint16_t cache[256] = {};
    static bool have[256] = {};
    if (!have[color]) {
        recomp_context tmp = *ctx;
        tmp.r4 = color;
        tmp.r5 = kDonorCode;
        func_8001D394_1DF94(rdram, &tmp);
        cache[color] = static_cast<uint16_t>(tmp.r2 & 0xFFFFu);
        have[color] = true;
    }
    return cache[color];
}

// Escribe el bloque (intercalado par) en el scratch; si el `value` es impar, traslada el glifo al
// plano impar (0x33) para que el compositor (`func_8001C0B0`) lo lea.
void store_block(uint8_t* rdram, const uint8_t* block, unsigned stride, bool odd) {
    for (unsigned i = 0; i < stride; ++i) {
        uint8_t b = block[i];
        if (odd) b = static_cast<uint8_t>((b >> 2) & 0x33u);
        rdram[(kGlyphScratch + i - 0x80000000u) ^ 3u] = b;
    }
}

}  // namespace

// codigo EUC propio -> value del donante (si no es nuestro, comportamiento original). El estilo lo
// fija el `stride` del color (color0 8x8 menus, color4 8x12 dialogos).
extern "C" void hh_accent_d394(uint8_t* rdram, recomp_context* ctx) {
    const unsigned color = static_cast<uint32_t>(ctx->r4) & 0xFFu;
    const unsigned code = static_cast<uint32_t>(ctx->r5) & 0xFFFFu;
    const unsigned stride = color_stride(rdram, color);

    int idx = -1;
    Which which = Which::Color0;
    if (stride == hh::kGameGlyphStride) {
        idx = game_by_code(code);
        which = Which::Color4;
    } else if (stride == hh::kAccentStride) {
        idx = accent_by_code(code);
        which = Which::Color0;
    }
    if (idx >= 0) {
        const uint16_t value = donor_value(rdram, ctx, color);
        ctx->r2 = value;
        g_pending = {true, static_cast<uint8_t>(color), value, idx, which};
        return;
    }
    func_8001D394_1DF94(rdram, ctx);
    g_pending.active = false;   // cualquier glifo nativo invalida la marca de origen
}

// value del donante Y con marca de origen -> escribir nuestro bloque del estilo correspondiente.
extern "C" void hh_accent_bfe4(uint8_t* rdram, recomp_context* ctx) {
    const unsigned color = static_cast<uint32_t>(ctx->r4) & 0xFFu;
    const unsigned value = static_cast<uint32_t>(ctx->r5) & 0xFFFFu;
    if (g_pending.active && g_pending.color == color && g_pending.value == value) {
        const int idx = g_pending.index;
        const Which which = g_pending.which;
        g_pending.active = false;   // consumido
        const unsigned stride = color_stride(rdram, color);
        const bool odd = (value & 1u) != 0;
        if (which == Which::Color4 && stride == hh::kGameGlyphStride) {
            store_block(rdram, hh::kGameGlyphs[idx].block, hh::kGameGlyphStride, odd);
            return;
        }
        if (which == Which::Color0 && stride == hh::kAccentStride) {
            store_block(rdram, hh::kAccentGlyphs[idx].block, hh::kAccentStride, odd);
            return;
        }
        // Otro color: no servimos un bloque de tamano distinto (evita corromper).
    }
    func_8001BFE4_1CBE4(rdram, ctx);
}

// --- Probe del overlay de diálogo (HH_DLG_PROBE=1) --------------------------------------------
// `func_8001B204` es la única que coloca caracteres (texto de menú Y de diálogo). El de diálogo va
// en EUC (bytes >= 0x80); el de menú en ASCII. Logueamos las llamadas con texto EUC para localizar
// la del diálogo (args + puntero de texto). Solo loguea; delega siempre. Ver
// notes/2026-10-07-experimento-overlay-dialogo.md.
namespace {
std::string dlg_read_euc(uint8_t* rdram, uint32_t addr, bool& is_euc, size_t maxpairs = 64) {
    std::string out;
    is_euc = false;
    if (addr < 0x80000000u || addr >= 0x80800000u) return out;
    for (size_t i = 0; i < maxpairs; ++i) {
        const uint32_t a = addr + static_cast<uint32_t>(i) * 2u;
        if (a < 0x80000000u || a + 1u >= 0x80800000u) break;
        const uint8_t hi = rdram[(a - 0x80000000u) ^ 3u];
        const uint8_t lo = rdram[((a + 1u) - 0x80000000u) ^ 3u];
        if (hi == 0 && lo == 0) break;
        if (hi >= 0x80) is_euc = true;
        if (hi == 0xA3 && lo >= 0xA1 && lo <= 0xFE) out.push_back(static_cast<char>(lo - 0x80));
        else if (hi >= 0x80) out.push_back('#');
        else out.push_back(static_cast<char>(hi));
    }
    return out;
}
}  // namespace

extern "C" void hh_dlg_b204_probe(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t a0 = static_cast<uint32_t>(ctx->r4);
    const uint32_t a1 = static_cast<uint32_t>(ctx->r5);
    const uint32_t a2 = static_cast<uint32_t>(ctx->r6);
    const uint32_t a3 = static_cast<uint32_t>(ctx->r7);
    static int logged = 0;
    static std::unordered_map<uint64_t, int> seen;
    const uint64_t key = (static_cast<uint64_t>(a0 & 0xFFu) << 48) ^
                         (static_cast<uint64_t>(a2 & 0xFFFFu) << 32) ^ (a3 & 0xFFFFFFFFu);
    if (logged < 80 && seen[key]++ == 0) {
        logged++;
        char hex[96] = {0};
        int k = 0;
        for (int i = 0; i < 10; i++) {
            const uint32_t a = a3 + static_cast<uint32_t>(i) * 2u;
            if (a < 0x80000000u || a + 1u >= 0x80800000u) break;
            const uint8_t hi = rdram[(a - 0x80000000u) ^ 3u];
            const uint8_t lo = rdram[((a + 1u) - 0x80000000u) ^ 3u];
            k += std::snprintf(hex + k, sizeof(hex) - k, "%02X%02X ", hi, lo);
        }
        bool is_euc = false;
        const std::string s = dlg_read_euc(rdram, a3, is_euc);
        hh::log("[dlgprobe] B204 a0=%u a1=%u a2=%u a3=%08X euc=%d hex=%s '%s'\n", a0 & 0xFFu, a1,
                a2, a3, is_euc ? 1 : 0, hex, s.c_str());
    }
    func_8001B204_1BE04(rdram, ctx);
}

// Probe genérico: loguea a0..a3 y el hex (EUC) de cada argumento que sea puntero RAM.
namespace {
void dlg_probe_args(uint8_t* rdram, recomp_context* ctx, const char* name) {
    const uint32_t a[4] = {static_cast<uint32_t>(ctx->r4), static_cast<uint32_t>(ctx->r5),
                           static_cast<uint32_t>(ctx->r6), static_cast<uint32_t>(ctx->r7)};
    const uint64_t key = (static_cast<uint64_t>(a[0]) << 32) ^ a[1] ^ (static_cast<uint64_t>(a[2]) << 16) ^ (a[3] >> 8);
    static std::unordered_map<uint64_t, int> all;
    if (all[key]++ != 0) return;
    if (all.size() > 200) return;
    char buf[320] = {0};
    int k = 0;
    for (int i = 0; i < 4; i++) {
        const uint32_t p = a[i];
        if (p >= 0x80000000u && p + 16u < 0x80800000u) {
            char hex[80] = {0};
            int h = 0;
            for (int j = 0; j < 8; j++) {
                const uint32_t q = p + static_cast<uint32_t>(j) * 2u;
                const uint8_t hi = rdram[(q - 0x80000000u) ^ 3u];
                const uint8_t lo = rdram[((q + 1u) - 0x80000000u) ^ 3u];
                h += std::snprintf(hex + h, sizeof(hex) - h, "%02X%02X ", hi, lo);
            }
            k += std::snprintf(buf + k, sizeof(buf) - k, " a%d=%08X[%s]", i, p, hex);
        } else {
            k += std::snprintf(buf + k, sizeof(buf) - k, " a%d=%08X", i, p);
        }
    }
    hh::log("[dlgprobe] %s%s\n", name, buf);
}
}  // namespace

// `func_80018E9C` compone UN carácter del diálogo (es exclusivo de la ruta 1800C, no lo usa el
// menú). Con el overlay de diálogo activo (la caja 'wa fa' está viva) se SALTA el original para no
// dibujar el texto del juego bajo el nuestro; en cualquier otro caso se delega. Con HH_DLG_PROBE=1
// además loguea los argumentos.
extern "C" void hh_dlg_18e9c(uint8_t* r, recomp_context* c) {
    static const bool probe = [] {
        const char* e = std::getenv("HH_DLG_PROBE");
        return e != nullptr && *e != '\0' && *e != '0';
    }();
    if (probe) dlg_probe_args(r, c, "18E9C");
    // HH_DLG_KEEP_ORIGINAL=1: NO ocultar el texto del juego (para comparar con el overlay).
    static const bool keep_original = [] {
        const char* e = std::getenv("HH_DLG_KEEP_ORIGINAL");
        return e != nullptr && *e != '\0' && *e != '0';
    }();
    const bool suppress =
        !keep_original && hh::overlay::enabled() && hh::overlay::dialogue_active();
    if (probe) {
        static uint64_t n = 0;
        if (n < 80) {
            hh::log("[dlgsup] 18E9C #%llu frame=%llu %s\n", static_cast<unsigned long long>(n),
                    static_cast<unsigned long long>(hh::overlay::presented_frames()),
                    suppress ? "SUPPRESS" : "draw");
            n++;
        }
    }
    if (suppress) return;
    func_80018E9C_19A9C(r, c);
}
extern "C" void hh_p19038(uint8_t* r, recomp_context* c) { dlg_probe_args(r, c, "19038"); func_80019038_19C38(r, c); }
extern "C" void hh_p1a01c(uint8_t* r, recomp_context* c) { dlg_probe_args(r, c, "1A01C"); func_8001A01C_1AC1C(r, c); }

static void dlg_log_arrow(uint8_t* r);   // definido más abajo
extern "C" void hh_p1a0a4(uint8_t* r, recomp_context* c) {
    dlg_probe_args(r, c, "1A0A4");
    func_8001A0A4_1ACA4(r, c);
    dlg_log_arrow(r);   // updater por frame del motor 2D (aquí vive el blink de la flecha)
}
namespace {
std::string hexdump(uint8_t* rdram, uint32_t addr, size_t n) {
    std::string out;
    if (addr < 0x80000000u || addr + n >= 0x80800000u) return out;
    char b[8];
    for (size_t i = 0; i < n; i += 4) {
        uint32_t v = 0;
        for (size_t j = 0; j < 4; j++) {
            const uint32_t a = addr + static_cast<uint32_t>(i + j);
            v = (v << 8) | rdram[(a - 0x80000000u) ^ 3u];
        }
        std::snprintf(b, sizeof(b), "%08X ", v);
        out += b;
    }
    return out;
}
}  // namespace
namespace {
const char* punct_char(uint16_t h) {
    switch (h) {
        case 0xA1A1: return " ";
        case 0xA1A4: return ",";
        case 0xA1A5: return ".";
        case 0xA1A9: return "?";
        case 0xA1AA: return "!";
        case 0xA1AD: return "'";
        case 0xA1A3: return "-";
        default: return "";
    }
}
void utf8_append(uint32_t cp, std::string& out) {
    if (cp < 0x80) {
        out.push_back(static_cast<char>(cp));
    } else if (cp < 0x800) {
        out.push_back(static_cast<char>(0xC0 | (cp >> 6)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    } else {
        out.push_back(static_cast<char>(0xE0 | (cp >> 12)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    }
}
void decode_half(uint16_t h, std::string& out) {
    if ((h >> 8) == 0xA3 && (h & 0xFF) >= 0xA1 && (h & 0xFF) <= 0xFE) {
        out.push_back(static_cast<char>((h & 0xFF) - 0x80));
        return;
    }
    if ((h >> 8) == 0xA1) {
        const char* p = punct_char(h);
        out += (p[0] != '\0') ? p : "_";
        return;
    }
    for (unsigned i = 0; i < hh::kGameGlyphCount; ++i) {
        if (hh::kGameGlyphs[i].code == h) {
            utf8_append(hh::kGameGlyphs[i].cp, out);
            return;
        }
    }
}
}  // namespace
extern "C" void hh_p1800c(uint8_t* r, recomp_context* c) {
    const uint32_t a0 = static_cast<uint32_t>(c->r4);
    const uint32_t a1 = static_cast<uint32_t>(c->r5);
    const uint32_t a2 = static_cast<uint32_t>(c->r6);
    const uint32_t a3 = static_cast<uint32_t>(c->r7);
    static std::string g_acc;
    static std::string g_raw;   // bytes EUC crudos del mensaje (para buscar el texto extendido)
    static uint32_t g_a1 = 0;
    // PAGINA acumulada: el juego encadena varios "mensajes" (FA/FE) en la misma caja hasta un corte
    // de pagina (opcode F800). Acumulamos sus lineas para mostrarlas juntas (p. ej. "Disculpe." +
    // la frase siguiente). Se limpia al inicio de nodo (F000FC00) y en cada corte (F800).
    static std::vector<std::string> g_page;
    {
        const uint16_t h0 = static_cast<uint16_t>(a0 >> 16);
        const uint16_t h1 = static_cast<uint16_t>(a0 & 0xFFFF);
        const bool start = (a0 == 0xF000FC00u);                    // inicio de nodo/conversacion
        const bool end0 = (h0 == 0xFA00u || h0 == 0xFE00u);        // fin de mensaje (espera A)
        const bool end1 = (h1 == 0xFA00u || h1 == 0xFE00u);
        const bool page0 = (h0 == 0xF800u);                        // corte de pagina (limpia caja)
        const bool page1 = (h1 == 0xF800u);
        // Emite una mitad: texto a `g_acc` y sus 2 bytes crudos a `g_raw` (los opcodes quedan como
        // separadores no-EUC, igual que el escaneo de `translate_euc`).
        const auto emit_half = [&](uint16_t hh) {
            if (hh == 0xF300u || hh == 0xF000u) g_acc += " / ";
            else decode_half(hh, g_acc);
            g_raw.push_back(static_cast<char>(hh >> 8));
            g_raw.push_back(static_cast<char>(hh & 0xFF));
        };
        const auto utf8_chars = [](const std::string& s) {
            size_t n = 0;
            for (size_t i = 0; i < s.size();) {
                const unsigned char ch = static_cast<unsigned char>(s[i]);
                i += ((ch & 0xE0) == 0xC0) ? 2 : ((ch & 0xF0) == 0xE0) ? 3
                                                                       : ((ch & 0xF8) == 0xF0) ? 4 : 1;
                n++;
            }
            return n;
        };
        if (start) {
            g_acc.clear();
            g_raw.clear();
            g_a1 = a1;
            g_page.clear();
        } else if (end0 || end1) {
            // El opcode de fin puede compartir la palabra `a0` con el ULTIMO carácter (p. ej.
            // `A1A9FA00` = `?` + fin): emite la mitad de texto antes de cerrar el mensaje.
            if (!end0) emit_half(h0);
            if (!end1) emit_half(h1);
            if (!g_acc.empty()) {
                // Líneas reconstruidas del juego (respetan sus saltos de línea originales).
                std::vector<std::string> lines;
                size_t p = 0;
                while (p < g_acc.size()) {
                    const size_t q = g_acc.find(" / ", p);
                    std::string seg = (q == std::string::npos) ? g_acc.substr(p)
                                                               : g_acc.substr(p, q - p);
                    while (!seg.empty() && seg.front() == ' ') seg.erase(seg.begin());
                    while (!seg.empty() && seg.back() == ' ') seg.pop_back();
                    if (!seg.empty()) lines.push_back(seg);
                    if (q == std::string::npos) break;
                    p = q + 3;
                }
                if (!lines.empty()) {
                    std::string concise;
                    for (size_t k = 0; k < lines.size(); ++k) {
                        if (k) concise += ' ';
                        concise += lines[k];
                    }
                    // Decisión: el valor del mensaje (con los saltos ya "baked" en `es.txt`) manda;
                    // si no hay entrada, se conservan los saltos originales del juego.
                    std::string chosen;
                    const bool use_ext = hh::text::dialogue_message_choice(
                        concise, reinterpret_cast<const uint8_t*>(g_raw.data()), g_raw.size(),
                        chosen);
                    std::vector<std::string> msg_lines;
                    if (use_ext) {
                        std::string cur;
                        for (char ch : chosen) {
                            if (ch == '\n') {
                                if (!cur.empty()) msg_lines.push_back(cur);
                                cur.clear();
                            } else {
                                cur.push_back(ch);
                            }
                        }
                        if (!cur.empty()) msg_lines.push_back(cur);
                    } else {
                        msg_lines = lines;   // saltos originales del juego
                    }
                    if (!msg_lines.empty()) {
                        size_t already = 0;   // caracteres ya visibles (página previa al mensaje)
                        for (const std::string& l : g_page) already += utf8_chars(l);
                        for (const std::string& l : msg_lines) g_page.push_back(l);
                        hh::log("[dlgprobe] MSG frame=%llu a1=%08X: '%s'\n",
                                static_cast<unsigned long long>(hh::overlay::presented_frames()),
                                g_a1, concise.c_str());
                        hh::log("[dlgprobe]   EXT %s len=%zu -> %zu lineas page=%zu\n",
                                use_ext ? "si" : "no", chosen.size(), msg_lines.size(), g_page.size());
                        hh::overlay::set_dialogue(true, g_page, already);
                    }
                }
            }
            g_acc.clear();
            g_raw.clear();
        } else if (page0 || page1) {
            // Corte de página: el juego limpia la caja y la frase siguiente empieza en blanco.
            if (!page0) emit_half(h0);
            if (!page1) emit_half(h1);
            g_page.clear();
            g_acc.clear();
            g_raw.clear();
            hh::overlay::clear_dialogue_text();
        } else {
            emit_half(h0);
            emit_half(h1);
        }
    }
    if (a0 == 0xF000FC00u) {
        hh::log("[dlgprobe] 1800C START frame=%llu a1=%08X a2=%08X a3=%08X\n",
                static_cast<unsigned long long>(hh::overlay::presented_frames()), a1, a2, a3);
        hh::log("[dlgprobe]   a1[0..0x30]: %s\n", hexdump(r, a1, 0x30).c_str());
        for (int k = 0; k < 4; k++) {
            const uint32_t p = a1 + static_cast<uint32_t>(k) * 4u;
            uint32_t v = 0;
            for (int j = 0; j < 4; j++) {
                const uint32_t a = p + static_cast<uint32_t>(j);
                v = (v << 8) | r[(a - 0x80000000u) ^ 3u];
            }
            if (v >= 0x80000000u && v < 0x80800000u) {
                hh::log("[dlgprobe]   a1[%d]=%08X -> %s\n", k, v, hexdump(r, v, 0x20).c_str());
            }
        }
    }
    func_8001800C_18C0C(r, c);
}
// Traza del estado de la flecha: variable 20 (D_8008EBE8 = duración/flag del fade), alpha acumulado
// (D_8008EE9C) y los campos del sprite actual (*D_8008EE8C): a2 (alfa), a6/a8 (ramp) y a7 (paso).
// Solo loguea cuando cambia la tupla. Sirve para clavar el fade real. Ver func_80018C9C/19038.
static void dlg_log_arrow(uint8_t* r) {
    auto u16 = [&](uint32_t a) -> uint16_t {
        return static_cast<uint16_t>((r[(a - 0x80000000u) ^ 3u] << 8) |
                                     r[((a + 1u) - 0x80000000u) ^ 3u]);
    };
    auto u32 = [&](uint32_t a) -> uint32_t {
        return (static_cast<uint32_t>(r[(a - 0x80000000u) ^ 3u]) << 24) |
               (static_cast<uint32_t>(r[((a + 1u) - 0x80000000u) ^ 3u]) << 16) |
               (static_cast<uint32_t>(r[((a + 2u) - 0x80000000u) ^ 3u]) << 8) |
               static_cast<uint32_t>(r[((a + 3u) - 0x80000000u) ^ 3u]);
    };
    const uint16_t ebe8 = u16(0x8008EBE8u);
    const uint16_t ee9c = u16(0x8008EE9Cu);
    const uint32_t spr = u32(0x8008EE8Cu);
    int a2 = -1, a6 = -1, a7 = -1, a8 = -1;
    if (spr >= 0x80000000u && spr < 0x80800000u) {
        a2 = r[((spr + 2u) - 0x80000000u) ^ 3u];
        a6 = r[((spr + 6u) - 0x80000000u) ^ 3u];
        a7 = r[((spr + 7u) - 0x80000000u) ^ 3u];
        a8 = (r[((spr + 8u) - 0x80000000u) ^ 3u] << 8) | r[((spr + 9u) - 0x80000000u) ^ 3u];
    }
    static uint64_t last = ~static_cast<uint64_t>(0);
    const uint64_t key = (static_cast<uint64_t>(ebe8) << 48) | (static_cast<uint64_t>(ee9c) << 32) |
                         (static_cast<uint64_t>(spr) << 8) |
                         (static_cast<uint64_t>(a2 & 0xFF));
    if (key != last) {
        last = key;
        hh::log("[dlgarr] frame=%llu ebe8=%u ee9c=%u spr=%08X a2=%d a6=%d a7=%d a8=%d\n",
                static_cast<unsigned long long>(hh::overlay::presented_frames()), ebe8, ee9c, spr,
                a2, a6, a7, a8);
    }
}

extern "C" void hh_p17bb8(uint8_t* r, recomp_context* c) {
    dlg_probe_args(r, c, "17BB8");
    func_80017BB8_187B8(r, c);
    dlg_log_arrow(r);   // tras procesar la cola (aquí se fijan los globals del fade)
}
// `func_800179B0`: inicializa/resetea el motor 2D (limpia 7 cajas por A804 y 0x1C campos por B204,
// luego prepara los globals de texto). Es el candidato a "abrir/cerrar" el sistema de texto del
// diálogo; la traza lo correlaciona con la caja 'wa fa' y los mensajes.
extern "C" void hh_p179b0(uint8_t* r, recomp_context* c) {
    static int n = 0;
    if (n < 60) {
        hh::log("[dlgprobe] 179B0 #%d frame=%llu a0=%u\n", n,
                static_cast<unsigned long long>(hh::overlay::presented_frames()),
                static_cast<uint32_t>(c->r4));
        n++;
    }
    func_800179B0_185B0(r, c);
}

// Registro (llamado desde hh::register_runtime_functions).
extern "C" void hh_accent_register() {
    recomp::overlays::add_loaded_function(0x8001D394, hh_accent_d394);
    recomp::overlays::add_loaded_function(0x8001BFE4, hh_accent_bfe4);
    std::fprintf(stderr, "[hh] acentos: color0 %u + color4 %u glifos (donante+origen)\n",
                 hh::kAccentGlyphCount, hh::kGameGlyphCount);
    const char* probe = std::getenv("HH_DLG_PROBE");
    if (probe != nullptr && *probe != '\0' && *probe != '0') {
        recomp::overlays::add_loaded_function(0x8001B204, hh_dlg_b204_probe);
        recomp::overlays::add_loaded_function(0x80018E9C, hh_dlg_18e9c);
        recomp::overlays::add_loaded_function(0x80019038, hh_p19038);
        recomp::overlays::add_loaded_function(0x8001A01C, hh_p1a01c);
        recomp::overlays::add_loaded_function(0x8001A0A4, hh_p1a0a4);
        recomp::overlays::add_loaded_function(0x8001800C, hh_p1800c);
        recomp::overlays::add_loaded_function(0x80017BB8, hh_p17bb8);
        recomp::overlays::add_loaded_function(0x800179B0, hh_p179b0);
        hh::log("[dlgprobe] probes B204/18E9C/19038/1A01C/1A0A4/1800C/17BB8 activos\n");
        std::fprintf(stderr, "[hh] probes de diálogo activos\n");
    }
}
