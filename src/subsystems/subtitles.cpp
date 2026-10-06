// Subtítulos de las secuencias sin texto (intro/prólogo; futuro: final). Ver include/hh/subtitles.h.
//
// Flujo: `begin(name)` (al pulsar EMPEZAR PARTIDA) ancla el reloj al VI actual y carga
// `assets/subtitles/<name>.timing.txt` + `assets/lang/subtitles_<lang>.txt`; `tick()` (cada frame,
// hilo del juego) calcula la línea activa, la trocea y la publica en la capa del overlay; el skip
// (A/START) cancela. El reloj usa el contador de VI del juego (~60 Hz) para no depender del
// wall-clock. Más adelante se re-ancla al inicio real de escena con `anchor_now()`.

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "hh.h"
#include "hh/font.h"
#include "hh/overlay.h"
#include "hh/subtitles.h"

extern "C" uint64_t hh_get_vi_count(void);
extern "C" uint16_t hh_input_buttons_now(void);   // máscara N64 actual (sin consumir flancos)

namespace hh::subtitles {
namespace {

using Face = hh::font::game::Face;
constexpr Face kFace = Face::Color4;

// --- config / traza ----------------------------------------------------------------------------
bool env_flag(const char* name, bool def) {
    const char* v = std::getenv(name);
    if (v == nullptr || *v == '\0') return def;
    return !(v[0] == '0' && v[1] == '\0');
}

struct State {
    bool loaded = false;
    bool enabled = true;
    bool trace = false;
    long offset_ms = 0;   // HH_SUB_OFFSET_MS: adelanto global (>0 = los subtítulos salen antes)
};

State& state() {
    static State s;
    return s;
}

// --- utilidades de texto -----------------------------------------------------------------------
unsigned utf8_next_cp(const std::string& s, size_t& i) {
    unsigned c = static_cast<unsigned char>(s[i++]);
    if (c < 0x80) return c;
    const unsigned extra = (c >= 0xF0) ? 3u : (c >= 0xE0) ? 2u : 1u;
    unsigned cp = c & (0x3Fu >> extra);
    for (unsigned k = 0; k < extra && i < s.size(); ++k) {
        cp = (cp << 6) | (static_cast<unsigned char>(s[i++]) & 0x3Fu);
    }
    return cp;
}

std::string unescape(const std::string& in) {
    std::string out;
    out.reserve(in.size());
    for (size_t i = 0; i < in.size(); ++i) {
        if (in[i] == '\\' && i + 1 < in.size()) {
            const char n = in[i + 1];
            if (n == 'n') { out.push_back('\n'); ++i; continue; }
            if (n == 't') { out.push_back('\t'); ++i; continue; }
            if (n == 'p') { out.push_back('\f'); ++i; continue; }   // corte de página manual
            if (n == '\\') { out.push_back('\\'); ++i; continue; }
        }
        out.push_back(in[i]);
    }
    return out;
}

// Normaliza caracteres que la fuente del juego no trae a equivalentes representables:
//   … (U+2026) -> "..."   ’ ‘ (U+2019/2018) -> '   “ ” (U+201C/201D) -> "
std::string normalize(const std::string& in) {
    std::string out;
    out.reserve(in.size());
    for (size_t i = 0; i < in.size();) {
        if (in.compare(i, 3, "\xE2\x80\xA6") == 0) { out += "..."; i += 3; continue; }   // …
        if (in.compare(i, 3, "\xE2\x80\x99") == 0) { out += '\''; i += 3; continue; }    // ’
        if (in.compare(i, 3, "\xE2\x80\x98") == 0) { out += '\''; i += 3; continue; }    // ‘
        if (in.compare(i, 3, "\xE2\x80\x9C") == 0) { out += '"'; i += 3; continue; }     // “
        if (in.compare(i, 3, "\xE2\x80\x9D") == 0) { out += '"'; i += 3; continue; }     // ”
        out.push_back(in[i++]);
    }
    return out;
}

void trim(std::string& s) {
    size_t a = s.find_first_not_of(" \t");
    size_t b = s.find_last_not_of(" \t");
    if (a == std::string::npos) { s.clear(); return; }
    s = s.substr(a, b - a + 1);
}

// Ancho (unidades virtuales) con la tipografía del diálogo (Face::Color4).
float text_width(const std::string& s) {
    float w = 0.0f;
    size_t i = 0;
    while (i < s.size()) {
        const unsigned cp = utf8_next_cp(s, i);
        w += (cp < 0x80) ? static_cast<float>(hh::font::game::face_glyph_advance(kFace, static_cast<unsigned char>(cp)))
                         : static_cast<float>(hh::font::game::face_cell_w(kFace));
    }
    return w;
}

// Trocea el texto a `max_w` unidades, respetando `\n` como corte duro.
std::vector<std::string> wrap(const std::string& text, float max_w);

// Pagina un texto en grupos de como mucho `max_lines` líneas (cada grupo = una pantalla). Un texto
// corto (una línea de guion) da una sola página. Así un bloque largo no cubre la pantalla entera.
std::vector<std::vector<std::string>> paginate(const std::string& text, float max_w, int max_lines);

std::vector<std::string> wrap(const std::string& text, float max_w) {
    std::vector<std::string> out;
    size_t start = 0;
    while (start <= text.size()) {
        const size_t nl = text.find('\n', start);
        const std::string para = text.substr(start, nl == std::string::npos ? std::string::npos : nl - start);
        std::string line;
        size_t i = 0;
        while (i < para.size()) {
            while (i < para.size() && para[i] == ' ') ++i;
            size_t j = i;
            while (j < para.size() && para[j] != ' ') ++j;
            if (j == i) break;
            const std::string word = para.substr(i, j - i);
            const std::string cand = line.empty() ? word : line + " " + word;
            if (!line.empty() && text_width(cand) > max_w) {
                out.push_back(line);
                line = word;
            } else {
                line = cand;
            }
            i = j;
        }
        if (!line.empty()) out.push_back(line);
        if (nl == std::string::npos) break;
        start = nl + 1;
    }
    return out;
}

std::vector<std::vector<std::string>> paginate(const std::string& text, float max_w, int max_lines) {
    std::vector<std::vector<std::string>> pages;
    // Cortes de página MANUALES: `\f` (de un `---` en la referencia) parte el texto en páginas
    // fijas, sin reparto automático.
    std::vector<std::string> segments;
    size_t start = 0;
    while (start <= text.size()) {
        const size_t f = text.find('\f', start);
        segments.push_back(text.substr(start, f == std::string::npos ? std::string::npos : f - start));
        if (f == std::string::npos) break;
        start = f + 1;
    }
    if (segments.size() > 1) {
        for (const std::string& seg : segments) {
            std::vector<std::string> lines = wrap(seg, max_w);
            if (lines.empty()) lines.push_back(std::string());
            pages.push_back(std::move(lines));
        }
        return pages;
    }
    // Reparto AUTOMÁTICO BALANCEADO por ANCHO de texto (≈ palabras): n líneas en ceil(n/per)
    // páginas contiguas, minimizando la desviación del ancho objetivo de cada página. Evita que la
    // última quede con una sola frase "huérfana". Programación dinámica (n pequeño).
    const std::vector<std::string> lines = wrap(text, max_w);
    const int per = max_lines > 0 ? max_lines : 1;
    const size_t n = lines.size();
    if (n == 0) {
        pages.push_back({});
        return pages;
    }
    const size_t npages = (n + static_cast<size_t>(per) - 1) / static_cast<size_t>(per);
    if (npages <= 1) {
        pages.push_back(lines);
        return pages;
    }
    std::vector<float> w(n);
    float total = 0.0f;
    for (size_t i = 0; i < n; ++i) {
        w[i] = text_width(lines[i]);
        total += w[i];
    }
    const float target = total / static_cast<float>(npages);
    std::vector<float> pre(n + 1, 0.0f);
    for (size_t i = 0; i < n; ++i) pre[i + 1] = pre[i] + w[i];
    const float kInf = 1e30f;
    std::vector<std::vector<float>> dp(npages + 1, std::vector<float>(n + 1, kInf));
    std::vector<std::vector<int>> brk(npages + 1, std::vector<int>(n + 1, -1));
    dp[0][0] = 0.0f;
    for (size_t p = 1; p <= npages; ++p) {
        for (size_t i = p; i <= n; ++i) {   // hacen falta >= p líneas para p páginas
            for (int k = 1; k <= per && static_cast<size_t>(k) <= i; ++k) {
                const size_t j = i - static_cast<size_t>(k);
                if (dp[p - 1][j] >= kInf) continue;
                const float pw = pre[i] - pre[j];
                const float val = dp[p - 1][j] + (pw - target) * (pw - target);
                if (val < dp[p][i]) {
                    dp[p][i] = val;
                    brk[p][i] = k;
                }
            }
        }
    }
    std::vector<std::vector<std::string>> rev;
    size_t i = n;
    for (size_t p = npages; p >= 1; --p) {
        int k = brk[p][i];
        if (k < 0) k = 1;
        const size_t j = i - static_cast<size_t>(k);
        rev.emplace_back(lines.begin() + static_cast<std::ptrdiff_t>(j),
                         lines.begin() + static_cast<std::ptrdiff_t>(i));
        i = j;
    }
    std::reverse(rev.begin(), rev.end());
    return rev;
}

// --- datos -------------------------------------------------------------------------------------
struct Line {
    int id = 0;
    long in_ms = 0;
    long out_ms = 0;
    int line = 0;          // 0 = normal (paginado); 1/2 = línea fija (arriba/abajo)
    std::string text;
};

struct Data {
    std::string name;
    std::vector<Line> lines;
    long last_out_ms = 0;
    bool ok = false;
};

Data g_data;

std::filesystem::path assets_dir() { return hh::get_app_folder_path() / "assets"; }

// Textos del idioma activo: `<name>.<id> = texto`.
std::unordered_map<std::string, std::string> load_texts(const std::string& name, const std::string& lang) {
    std::unordered_map<std::string, std::string> out;
    std::filesystem::path p = assets_dir() / "lang" / ("subtitles_" + lang + ".txt");
    std::ifstream f(p);
    if (!f) {
        hh::log("[subs] sin textos para '%s' (%s)\n", lang.c_str(), p.string().c_str());
        return out;
    }
    const std::string prefix = name + ".";
    std::string line;
    size_t n = 0;
    while (std::getline(f, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty() || line[0] == '#') continue;
        const size_t eq = line.find('=');
        if (eq == std::string::npos) continue;
        std::string key = line.substr(0, eq);
        std::string val = line.substr(eq + 1);
        trim(key);
        trim(val);
        if (key.rfind(prefix, 0) != 0 || val.empty()) continue;
        out.emplace(key, unescape(val));
        ++n;
    }
    hh::log("[subs] textos '%s': %zu entradas (%s)\n", lang.c_str(), n, p.string().c_str());
    return out;
}

bool load(const std::string& name) {
    Data d;
    d.name = name;
    std::filesystem::path tp = assets_dir() / "subtitles" / (name + ".timing.txt");
    std::ifstream f(tp);
    if (!f) {
        hh::log("[subs] sin timing: %s\n", tp.string().c_str());
        return false;
    }
    std::string line;
    while (std::getline(f, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty() || line[0] == '#') continue;
        int id = 0, ln = 0;
        long in_ms = 0, out_ms = 0;
        if (std::sscanf(line.c_str(), "%d %ld %ld %d", &id, &in_ms, &out_ms, &ln) < 3) continue;
        if (out_ms <= in_ms) continue;
        Line nl;
        nl.id = id;
        nl.in_ms = in_ms;
        nl.out_ms = out_ms;
        nl.line = ln;
        d.lines.push_back(std::move(nl));
    }
    if (d.lines.empty()) {
        hh::log("[subs] timing vacío: %s\n", tp.string().c_str());
        return false;
    }
    std::sort(d.lines.begin(), d.lines.end(), [](const Line& a, const Line& b) { return a.in_ms < b.in_ms; });
    d.last_out_ms = d.lines.back().out_ms;

    const std::string lang = hh::text_current_language();
    auto texts = load_texts(name, lang);
    // Fallback a inglés para claves que el idioma activo no tenga (traducción incompleta).
    std::unordered_map<std::string, std::string> en;
    if (lang != "en") en = load_texts(name, "en");
    size_t with_text = 0;
    for (Line& l : d.lines) {
        const std::string key = name + "." + std::to_string(l.id);
        const std::string* val = nullptr;
        auto it = texts.find(key);
        if (it != texts.end() && !it->second.empty()) {
            val = &it->second;
        } else {
            auto jt = en.find(key);
            if (jt != en.end() && !jt->second.empty()) val = &jt->second;
        }
        if (val != nullptr) {
            l.text = normalize(*val);
            ++with_text;
        }
    }
    d.ok = with_text > 0;
    g_data = std::move(d);
    hh::log("[subs] '%s': %zu líneas (%zu con texto, idioma '%s'), fin=%ld ms\n", name.c_str(),
            g_data.lines.size(), with_text, lang.c_str(), g_data.last_out_ms);
    return g_data.ok;
}

// --- estado de reproducción --------------------------------------------------------------------
bool g_active = false;
bool g_pending = false;                 // armado: esperando la escena objetivo para anclar
bool g_scene_seen = false;              // la escena objetivo ya está activa
bool g_content_wave = false;            // ha empezado la 2.ª oleada de cargas (escena de contenido)
uint16_t g_target_scene = 0x0104u;      // escena del prólogo (medida: 260 = 0x104)
uint64_t g_press_vi = 0;                // VI en EMPEZAR PARTIDA (solo para traza/offset)
uint64_t g_anchor_vi = 0;
uint64_t g_load_vi = 0;                 // VI de la última carga de módulo
unsigned g_load_count = 0;              // cargas de módulo vistas tras activarse la escena
constexpr unsigned kAnchorQuietFrames = 15;   // frames sin cargas => oleada terminada (~0.25 s)
constexpr uint64_t kContentWaveGapFrames = 120;  // hueco entre oleadas (>2 s) => nueva oleada = contenido
std::string g_published;       // "id/página" publicada (para no repintar)
uint16_t g_prev_btn = 0;
bool g_seed_skip = true;

// Páginas de la línea activa (cache). Se recalculan al cambiar de línea o de ancho visible.
int g_page_line_id = -1;
float g_page_w = -1.0f;
std::vector<std::vector<std::string>> g_pages;

constexpr int kMaxSubtitleLines = 3;   // líneas por pantalla antes de paginar
constexpr uint16_t kSkipMask = 0x8000u /*A*/ | 0x1000u /*START*/;

void hide() {
    if (!g_published.empty()) {
        g_published.clear();
        hh::overlay::set_subtitle(false, {});
    }
}

}  // namespace

void init() {
    State& s = state();
    if (s.loaded) return;
    s.loaded = true;
    s.enabled = env_flag("HH_SUBTITLES", true);
    s.trace = env_flag("HH_SUB_TRACE", false);
    if (const char* off = std::getenv("HH_SUB_OFFSET_MS"); off != nullptr && *off != '\0') {
        s.offset_ms = std::atol(off);
    }
    hh::log("[subs] init (activados=%d, offset=%ld ms)\n", s.enabled ? 1 : 0, s.offset_ms);
}

bool enabled() {
    init();
    return state().enabled;
}

void begin(const std::string& name) {
    init();
    State& s = state();
    if (!s.enabled) return;
    if (g_data.name != name || !g_data.ok) {
        if (!load(name)) return;
    }
    g_press_vi = hh_get_vi_count();
    g_pending = true;         // armado: se ancla al terminar la 2.ª oleada de cargas
    g_scene_seen = false;
    g_content_wave = false;
    g_load_count = 0;
    g_load_vi = 0;
    g_active = false;
    g_published.clear();
    if (s.trace) {
        hh::log("[subs] begin '%s' ARMADO (press vi=%llu, escena objetivo=0x%04X)\n", name.c_str(),
                static_cast<unsigned long long>(g_press_vi), static_cast<unsigned>(g_target_scene));
    }
}

void notify_scene(uint16_t scene) {
    if (!g_pending || g_scene_seen || scene != g_target_scene) return;
    g_scene_seen = true;
    if (state().trace) {
        hh::log("[subs] escena objetivo 0x%04X activa (esperando 2.ª oleada de cargas)\n",
                static_cast<unsigned>(scene));
    }
}

void notify_load() {
    if (!g_pending || !g_scene_seen) return;
    const uint64_t vi = hh_get_vi_count();
    // Primera carga tras un hueco largo sin cargas = 2.ª oleada (escena de contenido, con la
    // campanada). La 1.ª oleada (setup de la escena) va seguida y NO cuenta.
    if (g_load_count > 0 && vi > g_load_vi && (vi - g_load_vi) > kContentWaveGapFrames) {
        g_content_wave = true;
    }
    g_load_vi = vi;
    ++g_load_count;
}

void anchor_now() {
    if (!g_active) return;
    g_anchor_vi = hh_get_vi_count();
    g_published.clear();
    if (state().trace) {
        hh::log("[subs] re-ancla vi=%llu\n", static_cast<unsigned long long>(g_anchor_vi));
    }
}

void stop() {
    if (!g_active && !g_pending && g_published.empty()) return;
    g_active = false;
    g_pending = false;
    hide();
    if (state().trace) hh::log("[subs] stop\n");
}

bool active() { return g_active; }

void tick() {
    State& s = state();
    if (!s.enabled) return;

    // Ancla diferida: al terminar la 2.ª oleada de cargas (escena de contenido ~ campanada).
    if (g_pending && g_scene_seen && g_content_wave) {
        const uint64_t vi = hh_get_vi_count();
        if (vi - g_load_vi >= kAnchorQuietFrames) {
            g_anchor_vi = vi;
            g_active = true;
            g_pending = false;
            g_seed_skip = true;
            g_published.clear();
            if (s.trace) {
                const long off_ms = (g_press_vi != 0 && g_anchor_vi > g_press_vi)
                                        ? static_cast<long>((g_anchor_vi - g_press_vi) * 1000ull / 60ull)
                                        : 0;
                hh::log("[subs] ANCLA (fin 2.ª oleada de cargas) vi=%llu (offset desde EMPEZAR = %ld ms)\n",
                        static_cast<unsigned long long>(g_anchor_vi), off_ms);
            }
        }
    }
    if (!g_active) return;

    // Skip: flanco de A/START durante la secuencia -> cancelar (la cinemática se salta).
    const uint16_t now = hh_input_buttons_now();
    if (g_seed_skip) {
        g_prev_btn = now;
        g_seed_skip = false;
    } else {
        const uint16_t edges = static_cast<uint16_t>(now & ~g_prev_btn);
        g_prev_btn = now;
        if (edges & kSkipMask) {
            if (s.trace) hh::log("[subs] skip (btn=0x%04X)\n", static_cast<unsigned>(edges));
            stop();
            return;
        }
    }

    const uint64_t vi = hh_get_vi_count();
    long elapsed_ms =
        (vi > g_anchor_vi) ? static_cast<long>((vi - g_anchor_vi) * 1000ull / 60ull) : 0;
    elapsed_ms += s.offset_ms;   // adelanto global (HH_SUB_OFFSET_MS; positivo = antes)

    // Recolecta las entradas activas: las de línea fija (1/2) pueden SOLAPARSE en el tiempo y se
    // muestran a la vez en su línea; las normales (line=0) se paginan.
    const Line* normal = nullptr;
    std::vector<const Line*> act1, act2;
    for (const Line& l : g_data.lines) {
        if (elapsed_ms < l.in_ms || elapsed_ms >= l.out_ms) continue;
        if (l.line == 1) {
            act1.push_back(&l);
        } else if (l.line == 2) {
            act2.push_back(&l);
        } else if (normal == nullptr) {
            normal = &l;
        }
    }
    // Varias frases pueden solaparse en la MISMA línea (p. ej. comparten ventana): se secuencian por
    // orden dentro de la ventana común (fracción del tiempo). Así se "intercalan" por línea.
    auto pick_slot = [&](std::vector<const Line*>& act) -> const Line* {
        if (act.empty()) return nullptr;
        if (act.size() == 1) return act[0];
        std::sort(act.begin(), act.end(), [](const Line* a, const Line* b) {
            if (a->in_ms != b->in_ms) return a->in_ms < b->in_ms;
            return a->id < b->id;
        });
        long lo = act.front()->in_ms, hi = act.front()->out_ms;
        for (const Line* p : act) {
            lo = std::min(lo, p->in_ms);
            hi = std::max(hi, p->out_ms);
        }
        const long dur = std::max(1L, hi - lo);
        const long rel = std::min(std::max(0L, elapsed_ms - lo), dur - 1);
        const size_t idx =
            std::min(act.size() - 1, static_cast<size_t>(rel * static_cast<long>(act.size()) / dur));
        return act[idx];
    };
    const Line* slot1 = pick_slot(act1);
    const Line* slot2 = pick_slot(act2);
    const float max_w = std::max(80.0f, hh::overlay::visible_width() - 24.0f);

    if (slot1 != nullptr || slot2 != nullptr) {
        const std::string key = "S:" + std::to_string(slot1 ? slot1->id : -1) + ":" +
                                std::to_string(slot2 ? slot2->id : -1);
        if (key != g_published) {
            g_published = key;
            std::vector<std::string> lines;
            auto add = [&](const std::string& str) {
                if (str.empty()) {
                    lines.push_back(std::string());   // línea vacía: reserva la posición
                    return;
                }
                for (const std::string& w : wrap(str, max_w)) lines.push_back(w);
            };
            add(slot1 ? slot1->text : std::string());
            add(slot2 ? slot2->text : std::string());
            hh::overlay::set_subtitle(true, lines);
            if (s.trace) {
                hh::log("[subs] lineas fijas 1=%d 2=%d (t=%ld ms)\n", slot1 ? slot1->id : -1,
                        slot2 ? slot2->id : -1, elapsed_ms);
            }
        }
        g_page_line_id = -1;   // invalida la caché de paginado normal
    } else if (normal != nullptr && !normal->text.empty()) {
        if (normal->id != g_page_line_id || max_w != g_page_w) {
            g_pages = paginate(normal->text, max_w, kMaxSubtitleLines);
            g_page_line_id = normal->id;
            g_page_w = max_w;
        }
        const size_t npages = g_pages.empty() ? 1 : g_pages.size();
        const long dur = std::max(1L, normal->out_ms - normal->in_ms);
        const long rel = std::min(std::max(0L, elapsed_ms - normal->in_ms), dur - 1);
        const size_t page =
            std::min(npages - 1, static_cast<size_t>(rel * static_cast<long>(npages) / dur));
        const std::string key = std::to_string(normal->id) + "/" + std::to_string(page);
        if (key != g_published) {
            g_published = key;
            hh::overlay::set_subtitle(true, g_pages[page]);
            if (s.trace) {
                hh::log("[subs] linea %d pag %zu/%zu (t=%ld ms)\n", normal->id, page + 1, npages,
                        elapsed_ms);
            }
        }
    } else {
        hide();
        if (elapsed_ms >= g_data.last_out_ms) {
            stop();
        }
    }
}

}  // namespace hh::subtitles
