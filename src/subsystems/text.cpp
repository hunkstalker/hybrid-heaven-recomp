// Spike de traduccion (primera traduccion al espanol; base del selector de idioma, ADR 0008).
//
// El texto del juego (USA) son cadenas ASCII terminadas en NUL, almacenadas en campos de ancho
// fijo (rellenos con espacios). Los modulos con texto se cargan con el loader `trans`
// (LZKN64); se interceptan en `hh_trans_load` (src/subsystems/trans_cache.cpp) y, antes de
// escribirlos a RDRAM, se sustituyen las cadenas conocidas por su traduccion.
//
// Esto permite traducir SIN localizar aun la rutina de text-emit, y es suficiente para el
// go/no-go del spike. La sustitucion preserva la longitud del segmento (terminado en NUL), asi
// que no altera el layout de las tablas.
//
// Knobs:
//   HH_LANG=es        activa el idioma (por ahora solo "es"); sin definir -> sin traduccion.
//   HH_LANG_FILE=ruta usa un fichero distinto de lang/<lang>.txt.
//   HH_TEXT_TRACE=1   escribe en hh.log cada sustitucion (y las que no caben).
//
// La tabla por defecto esta embebida en `kEsDefaults`. Si existe `lang/es.txt` junto al .exe se
// usa ese fichero (permite editar traducciones sin recompilar). Formato: lineas `ORIGINAL=TRAD`;
// las lineas vacias o que empiezan por '#' se ignoran.

#include <algorithm>
#include <cctype>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "hh.h"
#include "hh/accent_glyphs.h"

namespace {

// Traducciones por defecto (espanol). Solo ASCII para no depender aun de glifos nuevos
// (acentos/eñe) en la fuente. ORIGINAL coincide con la cadena del campo (sin el prefijo de
// formato ni los espacios de relleno).
struct Pair {
    const char* en;
    const char* es;
};

constexpr Pair kEsDefaults[] = {
    // Titulo / arranque
    {"PLEASE SELECT", "SELECCIONA"},
    {"GAME START", "INICIAR"},
    {"PRESS START BUTTON", "PULSA START"},
    // Menu principal
    {"NEW GAME", "NUEVA PARTIDA"},
    {"CONTINUE", "CONTINUAR"},
    {"BATTLE MODE", "MODO LUCHA"},
    {"SOUND", "AJUSTES"},
    {"RESOLUTION", "RESOLUCIÓN"},
    {"DEBUG MODE", "MODO DEBUG"},
    {"OPTION", "AJUSTES"},
    {"DIFFICULTY", "DIFICULTAD"},
    {"EXIT", "SALIR"},
    // Batalla de criaturas / demo
    {"VS MODE", "MODO VS"},
    {"CREATURE BATTLE", "COMBATE BESTIA"},
    {"DATA EDIT", "EDITAR DATOS"},
    {"5 MATCHES", "5 LUCHAS"},
    // Opciones de sonido / resolucion / dificultad
    {"STEREO", "ESTEREO"},
    {"MONAURAL", "MONO"},
    {"HIGH NORMAL", "ALTA NORMAL"},
    {"ULTIMATE", "SUPREMO"},
    {"HARD", "DIFICIL"},
    {"LOW", "MIN"},
};

bool env_flag(const char* name, bool def) {
    const char* v = std::getenv(name);
    if (v == nullptr || *v == '\0') return def;
    return !(v[0] == '0' && v[1] == '\0');
}

struct Key {
    std::string text;
    std::string repl;
};

struct State {
    bool enabled = false;
    size_t longest = 0;
    std::vector<Key> keys;  // ordenados por longitud descendente
    bool trace = false;
    bool loaded = false;
    std::string current = "en";  // codigo de idioma activo
};

// Idiomas incluidos "de serie" (el resto se aportan como mods: mods/*/lang/<code>.txt).
constexpr const char* kBuiltins[] = {"en", "es", "ca", "fr", "de", "ja"};

bool is_builtin(const std::string& code) {
    for (const char* b : kBuiltins) {
        if (code == b) return true;
    }
    return false;
}

State& state() {
    static State s;
    return s;
}

void add_key(State& s, const std::string& text, const std::string& repl) {
    if (text.empty() || repl.empty()) return;
    for (const Key& k : s.keys) {
        if (k.text == text) return;  // el fichero gana sobre el default
    }
    s.keys.push_back({text, repl});
    s.longest = std::max(s.longest, text.size());
}

bool load_file(State& s, const std::filesystem::path& path) {
    std::ifstream f(path);
    if (!f) return false;
    std::string line;
    size_t n = 0;
    while (std::getline(f, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty() || line[0] == '#') continue;
        size_t eq = line.find('=');
        if (eq == std::string::npos) continue;
        std::string key = line.substr(0, eq);
        std::string val = line.substr(eq + 1);
        // recorta espacios de los extremos de key/val (no de dentro)
        auto trim = [](std::string& str) {
            size_t a = str.find_first_not_of(" \t");
            size_t b = str.find_last_not_of(" \t");
            if (a == std::string::npos) {
                str.clear();
            } else {
                str = str.substr(a, b - a + 1);
            }
        };
        trim(key);
        trim(val);
        if (key.empty() || val.empty()) continue;
        add_key(s, key, val);
        n++;
    }
    hh::log("[text] lang '%s': %zu entradas de %s\n", path.stem().string().c_str(), n,
            path.string().c_str());
    return true;  // el fichero existe (aunque no tenga entradas)
}

// Directorios donde buscar tablas de idioma: lang/ junto al .exe + lang/ de cada mod.
std::vector<std::filesystem::path> lang_dirs() {
    std::vector<std::filesystem::path> dirs;
    std::filesystem::path base = hh::get_app_folder_path();
    dirs.push_back(base / "lang");

    std::error_code ec;
    std::filesystem::path mods = base / "mods";
    if (std::filesystem::is_directory(mods, ec)) {
        for (const auto& e : std::filesystem::directory_iterator(mods, ec)) {
            if (e.is_directory()) dirs.push_back(e.path() / "lang");
        }
    }
    return dirs;
}

// --- Persistencia del idioma en config.ini [lang] language = <code> ---------------------------
std::filesystem::path config_path() {
    const char* env = std::getenv("HH_PAD_CONFIG");
    if (env != nullptr && *env != '\0') return env;
    return hh::get_app_folder_path() / "config.ini";
}

std::string read_config_language() {
    std::ifstream f(config_path());
    if (!f) return {};
    std::string line;
    bool in_lang = false;
    while (std::getline(f, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        size_t b = line.find_first_not_of(" \t");
        if (b == std::string::npos) continue;
        if (line[b] == '#' || line[b] == ';') continue;
        if (line[b] == '[') {
            in_lang = (line.compare(b, 6, "[lang]") == 0);
            continue;
        }
        if (!in_lang) continue;
        size_t eq = line.find('=');
        if (eq == std::string::npos) continue;
        std::string k = line.substr(b, eq - b);
        size_t ke = k.find_last_not_of(" \t");
        if (ke != std::string::npos) k = k.substr(0, ke + 1);
        if (k != "language") continue;
        std::string v = line.substr(eq + 1);
        size_t a = v.find_first_not_of(" \t");
        size_t z = v.find_last_not_of(" \t");
        if (a == std::string::npos) return {};
        return v.substr(a, z - a + 1);
    }
    return {};
}

void write_config_language(const std::string& code) {
    std::filesystem::path p = config_path();
    std::vector<std::string> lines;
    bool found_section = false, wrote = false;
    {
        std::ifstream f(p);
        std::string line;
        while (std::getline(f, line)) {
            if (!line.empty() && line.back() == '\r') line.pop_back();
            lines.push_back(line);
        }
    }
    for (size_t i = 0; i < lines.size(); i++) {
        std::string t = lines[i];
        size_t b = t.find_first_not_of(" \t");
        if (b != std::string::npos && t[b] == '[') {
            if (found_section) break;  // fin de la seccion [lang]
            found_section = (t.compare(b, 6, "[lang]") == 0);
            continue;
        }
        if (!found_section || wrote) continue;
        size_t eq = t.find('=');
        if (eq == std::string::npos) continue;
        std::string k = t.substr(b == std::string::npos ? 0 : b, eq - (b == std::string::npos ? 0 : b));
        size_t ke = k.find_last_not_of(" \t");
        if (ke != std::string::npos) k = k.substr(0, ke + 1);
        if (k == "language") {
            lines[i] = "language = " + code;
            wrote = true;
        }
    }
    if (!found_section) {
        lines.push_back("");
        lines.push_back("[lang]");
        lines.push_back("language = " + code);
        wrote = true;
    } else if (!wrote) {
        // insertar tras la cabecera [lang]
        for (size_t i = 0; i < lines.size(); i++) {
            std::string t = lines[i];
            size_t b = t.find_first_not_of(" \t");
            if (b != std::string::npos && t.compare(b, 6, "[lang]") == 0) {
                lines.insert(lines.begin() + i + 1, "language = " + code);
                break;
            }
        }
    }
    std::ofstream out(p, std::ios::trunc);
    if (!out) return;
    for (const std::string& l : lines) out << l << "\n";
    hh::log("[text] idioma persistido en config.ini: %s\n", code.c_str());
}

// Carga la tabla del idioma `code` (fichero lang/ + mods). Devuelve false si no hay fichero.
bool load_language_table(State& s, const std::string& code) {
    const char* override_path = std::getenv("HH_LANG_FILE");
    if (override_path != nullptr && *override_path != '\0') {
        return load_file(s, override_path);
    }
    for (const std::filesystem::path& d : lang_dirs()) {
        std::filesystem::path f = d / (code + ".txt");
        std::error_code ec;
        if (std::filesystem::exists(f, ec)) return load_file(s, f);
    }
    return false;
}

// Fija el idioma activo (recarga la tabla). No re-aplica a modulos ya cargados: eso lo decide el
// llamante (set_language llama a hh_trans_reapply_language).
void apply_language(const std::string& code) {
    State& s = state();
    s.current = code;
    s.keys.clear();
    s.longest = 0;
    s.enabled = false;

    if (code == "en") {
        hh::log("[text] idioma 'en' (texto original)\n");
        return;
    }

    if (!load_language_table(s, code)) {
        if (code == "es") {
            for (const Pair& p : kEsDefaults) add_key(s, p.en, p.es);
            hh::log("[text] idioma 'es' (tabla embebida, %zu entradas)\n", s.keys.size());
        } else {
            hh::log("[text] idioma '%s' sin tabla -> se muestra el original (en)\n", code.c_str());
            return;  // enabled=false
        }
    }
    s.enabled = true;

    // Claves mas largas primero: evita que "MODE" gane a "BATTLE MODE".
    std::stable_sort(s.keys.begin(), s.keys.end(),
                     [](const Key& a, const Key& b) { return a.text.size() > b.text.size(); });
}

void init() {
    State& s = state();
    if (s.loaded) return;
    s.loaded = true;
    s.trace = env_flag("HH_TEXT_TRACE", false);

    std::string code;
    const char* env = std::getenv("HH_LANG");
    if (env != nullptr && *env != '\0') {
        code = env;
    } else {
        code = read_config_language();
    }
    if (code.empty()) code = "en";
    apply_language(code);
}

// Extrae el "core" de un segmento: quita el prefijo de control/formato (`%p`, `%m%p`, `@`, ...)
// y los espacios de relleno iniciales. No toca mayusculas/minusculas ni espacios internos.
// Devuelve false si el segmento no es texto ASCII imprimible (p. ej. datos binarios o SJIS).
bool core_of(const uint8_t* seg, size_t len, std::string& prefix, std::string& core) {
    for (size_t i = 0; i < len; i++) {
        uint8_t b = seg[i];
        if (b < 0x20 || b > 0x7E) return false;
    }
    size_t end = len;
    while (end > 0 && seg[end - 1] == ' ') end--;
    size_t i = 0;
    while (i < end) {
        uint8_t b = seg[i];
        if (b == ' ' || b == '@') {
            i++;
        } else if (b == '%' && i + 1 < end &&
                   ((seg[i + 1] >= 'A' && seg[i + 1] <= 'Z') ||
                    (seg[i + 1] >= 'a' && seg[i + 1] <= 'z'))) {
            i += 2;
        } else {
            break;
        }
    }
    prefix.assign(reinterpret_cast<const char*>(seg), i);
    core.assign(reinterpret_cast<const char*>(seg) + i, end - i);
    return true;
}

// Traduce un segmento (bytes entre NUL) preservando la longitud de su REGISTRO. Solo sustituye si
// el core (texto sin prefijo de formato) coincide EXACTAMENTE con una clave.
//
// `content_len` = bytes de texto sin NUL; `slot` = bytes reservados para el registro (texto + NUL de
// relleno). Los datos USA usan registros de tamano fijo con relleno de NUL (evidencia: tablas de
// 12/16 bytes; la version PAL guardaba 3 idiomas) -> el relleno es holgura deliberada. Se reserva
// 1 byte para el NUL terminador.
// Convierte UTF-8 a los codigos EUC propios de 2 bytes de los glifos acentuados (B); el ASCII pasa
// tal cual. Ver include/hh/accent_glyphs.h (generado) y notes/2026-09-23-b-fuente-formato-y-gaiji.md.
std::string utf8_to_game(const std::string& in) {
    std::string out;
    for (size_t i = 0; i < in.size();) {
        const unsigned char c = static_cast<unsigned char>(in[i]);
        if (c < 0x80) {
            out.push_back(static_cast<char>(c));
            ++i;
            continue;
        }
        uint32_t cp = 0;
        size_t n = 0;
        if ((c & 0xE0) == 0xC0) { cp = c & 0x1F; n = 1; }
        else if ((c & 0xF0) == 0xE0) { cp = c & 0x0F; n = 2; }
        else if ((c & 0xF8) == 0xF0) { cp = c & 0x07; n = 3; }
        if (n == 0 || i + n >= in.size()) { out.push_back(static_cast<char>(c)); ++i; continue; }
        for (size_t k = 1; k <= n; ++k) cp = (cp << 6) | (static_cast<unsigned char>(in[i + k]) & 0x3F);
        i += n + 1;
        uint16_t code = 0;
        for (unsigned g = 0; g < hh::kAccentGlyphCount; ++g) {
            if (hh::kAccentGlyphs[g].cp == cp) { code = hh::kAccentGlyphs[g].code; break; }
        }
        if (code != 0) {
            out.push_back(static_cast<char>(code >> 8));
            out.push_back(static_cast<char>(code & 0xFF));
        } else {
            out.push_back('?');
        }
    }
    return out;
}

bool translate_segment(uint8_t* seg, size_t content_len, size_t slot, const State& s) {
    std::string prefix, core;
    if (!core_of(seg, content_len, prefix, core) || core.empty()) return false;

    for (const Key& k : s.keys) {
        if (k.text != core) continue;
        std::string out = prefix + utf8_to_game(k.repl);
        if (out.size() + 1 > slot) {
            if (s.trace) {
                hh::log("[text] no cabe: |%s| -> |%s| (registro %zu, resultado %zu + NUL)\n",
                        core.c_str(), k.repl.c_str(), slot, out.size());
            }
            return false;
        }
        std::memset(seg, ' ', slot);
        std::memcpy(seg, out.data(), out.size());
        seg[slot - 1] = 0;  // terminador
        return true;
    }
    return false;
}

}  // namespace

// Traduce in-place un buffer en ORDEN GUEST (el mismo flujo que produce el decodificador antes de
// `store_guest`). Recorre segmentos terminados en NUL. Devuelve el numero de sustituciones.
extern "C" int hh_text_translate_guest(uint8_t* buf, size_t len) {
    init();
    const State& s = state();
    if (!s.enabled || len == 0) return 0;

    int replaced = 0;
    size_t i = 0;
    while (i < len) {
        // salta el relleno de NUL entre registros
        while (i < len && buf[i] == 0) i++;
        if (i >= len) break;
        const size_t start = i;
        while (i < len && buf[i] != 0) i++;
        const size_t content_len = i - start;

        // relleno de NUL hasta el siguiente registro = holgura del registro (acotada).
        size_t gap = 0;
        while (i + gap < len && buf[i + gap] == 0) gap++;
        size_t slot = content_len + (gap < 16 ? gap : 16);
        if (slot <= content_len) slot = content_len + 1;  // deja sitio al terminador

        // salta registros puramente binarios (sin ninguna letra)
        bool has_alpha = false;
        for (size_t j = start; j < start + content_len; j++) {
            if (std::isalpha(buf[j])) {
                has_alpha = true;
                break;
            }
        }
        if (has_alpha && translate_segment(buf + start, content_len, slot, s)) {
            replaced++;
            i = start + slot;  // ya consumimos el registro completo
        } else {
            i = start + content_len;
        }
    }
    if (replaced > 0 && s.trace) {
        hh::log("[text] %d cadenas traducidas (bloque de %zu bytes)\n", replaced, len);
    }
    return replaced;
}

namespace hh {
bool text_enabled() {
    init();
    return state().enabled;
}

std::vector<std::string> text_available_languages() {
    init();
    std::vector<std::string> out;
    for (const char* b : kBuiltins) out.push_back(b);
    for (const std::filesystem::path& d : lang_dirs()) {
        std::error_code ec;
        if (!std::filesystem::is_directory(d, ec)) continue;
        for (const auto& e : std::filesystem::directory_iterator(d, ec)) {
            if (!e.is_regular_file()) continue;
            if (e.path().extension() != ".txt") continue;
            std::string code = e.path().stem().string();
            if (std::find(out.begin(), out.end(), code) == out.end()) out.push_back(code);
        }
    }
    return out;
}

const std::string& text_current_language() {
    init();
    return state().current;
}

void text_set_language(const std::string& code) {
    init();
    if (code == state().current) return;
    apply_language(code);
    write_config_language(code);
    hh_trans_reapply_language();  // cambia el texto ya cargado (menus) sin recargar el juego
    hh::log("[text] idioma activo: '%s' (traduciendo=%d)\n", code.c_str(),
            state().enabled ? 1 : 0);
}

void text_cycle_language() {
    init();
    std::vector<std::string> list = text_available_languages();
    if (list.empty()) return;
    size_t idx = 0;
    for (size_t i = 0; i < list.size(); i++) {
        if (list[i] == state().current) {
            idx = i;
            break;
        }
    }
    text_set_language(list[(idx + 1) % list.size()]);
}

void text_debug_tick() {
    static const double at = [] {
        const char* e = std::getenv("HH_LANG_CYCLE_AT");
        return (e != nullptr && *e != '\0') ? std::atof(e) : -1.0;
    }();
    if (at < 0.0) return;
    static bool done = false;
    if (done) return;
    static const auto t0 = std::chrono::steady_clock::now();
    const double secs =
        std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
    if (secs >= at) {
        done = true;
        hh::log("[text] HH_LANG_CYCLE_AT=%.1f -> cicla idioma\n", at);
        text_cycle_language();
    }
}
}  // namespace hh
