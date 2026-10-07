// Traduccion — UNICA fuente: assets/lang/<code>.txt (clave = TEXTO ORIGINAL EN INGLES).
//
// El texto del juego (USA) son cadenas ASCII terminadas en NUL, almacenadas en campos de ancho
// fijo (rellenos con espacios). Los modulos con texto se cargan con el loader `trans`
// (LZKN64); se interceptan en `hh_trans_load` (src/subsystems/trans_cache.cpp) y, antes de
// escribirlos a RDRAM, se sustituyen las cadenas conocidas por su traduccion. La MISMA tabla la usa
// la UI del port a traves de `hh::text::translate` (unico punto de traduccion; `menu::localized`
// delega en el). No hay traducciones en codigo: editar `assets/lang/<code>.txt` basta (sin
// recompilar).
//
// `en` = identidad (sin fichero): `translate()` devuelve la clave.
//
// Knobs:
//   HH_LANG=<code>    activa el idioma; sin definir -> el de config.ini [lang] o el del sistema.
//   HH_LANG_FILE=ruta usa un fichero distinto de assets/lang/<lang>.txt.
//   HH_TEXT_TRACE=1   escribe en hh.log cada sustitucion (y las que no caben).
//
// Formato del `.txt` (lineas `CLAVE=VALOR`; vacias o que empiezan por '#' se ignoran):
//   - CLAVE = texto original en ingles; VALOR = traduccion (UTF-8).
//   - `^` al inicio del valor = el motor centra esa cadena (ver translate_segment).
//   - Escapes `\n` y `\t` en clave o valor (via `unescape`), para los mensajes multi-linea.

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

#if defined(_WIN32)
#    ifndef WIN32_LEAN_AND_MEAN
#        define WIN32_LEAN_AND_MEAN
#    endif
#    ifndef NOMINMAX
#        define NOMINMAX
#    endif
#    include <windows.h>
#endif

#include "hh.h"
#include "hh/accent_glyphs.h"      // color0 8x8 (menus ASCII)
#include "hh/game_font_color4.h"   // color4 8x12 (dialogos EUC)

namespace {

bool env_flag(const char* name, bool def) {
    const char* v = std::getenv(name);
    if (v == nullptr || *v == '\0') return def;
    return !(v[0] == '0' && v[1] == '\0');
}

struct Key {
    std::string text;
    std::string repl;
    bool center = false;   // texto centrado por el motor: terminar justo tras el texto
};

struct State {
    bool enabled = false;
    size_t longest = 0;
    std::vector<Key> keys;  // ordenados por longitud descendente
    std::unordered_map<std::string, const Key*> index;  // clave -> Key (busqueda O(1))
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

void add_key(State& s, const std::string& text, const std::string& repl, bool center = false) {
    if (text.empty() || repl.empty()) return;
    for (const Key& k : s.keys) {
        if (k.text == text) return;  // el fichero gana sobre el default
    }
    s.keys.push_back({text, repl, center});
    s.longest = std::max(s.longest, text.size());
}

// Decodifica escapes de una linea de traduccion: `\n` -> salto de linea, `\t` -> tabulador y `\\`
// -> barra invertida. Hace falta para las CLAVES/VALORES multi-linea de la UI (p. ej. los mensajes
// con saltos), que en el `.txt` no pueden contener un salto real. El texto nativo no usa escapes.
std::string unescape(const std::string& in) {
    std::string out;
    out.reserve(in.size());
    for (size_t i = 0; i < in.size(); ++i) {
        if (in[i] == '\\' && i + 1 < in.size()) {
            const char n = in[i + 1];
            if (n == 'n') { out.push_back('\n'); ++i; continue; }
            if (n == 't') { out.push_back('\t'); ++i; continue; }
            if (n == '\\') { out.push_back('\\'); ++i; continue; }
        }
        out.push_back(in[i]);
    }
    return out;
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
        key = unescape(key);
        val = unescape(val);
        if (key.empty() || val.empty()) continue;
        // Marcador `^` al inicio del valor: el motor centra esa cadena (ver translate_segment).
        bool center = false;
        if (val[0] == '^') {
            center = true;
            val.erase(0, 1);
            if (val.empty()) continue;
        }
        add_key(s, key, val, center);
        n++;
    }
    hh::log("[text] lang '%s': %zu entradas de %s\n", path.stem().string().c_str(), n,
            path.string().c_str());
    return true;  // el fichero existe (aunque no tenga entradas)
}

// Directorios donde buscar tablas de idioma: assets/lang/ junto al .exe + lang/ de cada mod.
std::vector<std::filesystem::path> lang_dirs() {
    std::vector<std::filesystem::path> dirs;
    std::filesystem::path base = hh::get_app_folder_path();
    dirs.push_back(base / "assets" / "lang");

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

// Carga la tabla del idioma `code` (fichero assets/lang/ + mods). Devuelve false si no hay fichero.
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

    // Unica fuente = el fichero del idioma. Sin fichero no hay traduccion (se muestra el original).
    if (!load_language_table(s, code)) {
        hh::log("[text] idioma '%s' sin tabla -> se muestra el original (en)\n", code.c_str());
        return;  // enabled=false
    }
    s.enabled = true;

    // Claves mas largas primero: evita que "MODE" gane a "BATTLE MODE".
    std::stable_sort(s.keys.begin(), s.keys.end(),
                     [](const Key& a, const Key& b) { return a.text.size() > b.text.size(); });
    s.index.clear();
    for (const Key& k : s.keys) s.index.emplace(k.text, &k);
}

// --- Deteccion del idioma del sistema ----------------------------------------------------------
// Locale del SO como cadena (p. ej. "es-ES", "ca_ES.UTF-8", "fr_FR", "de-AT", "ja-JP").
std::string os_locale() {
#if defined(_WIN32)
    wchar_t buf[LOCALE_NAME_MAX_LENGTH] = {};
    if (GetUserDefaultLocaleName(buf, LOCALE_NAME_MAX_LENGTH) > 0) {
        char n[LOCALE_NAME_MAX_LENGTH * 2] = {};
        if (WideCharToMultiByte(CP_UTF8, 0, buf, -1, n, sizeof(n), nullptr, nullptr) > 0) {
            return n;
        }
    }
    return {};
#else
    for (const char* var : { "LANGUAGE", "LC_ALL", "LC_MESSAGES", "LANG" }) {
        const char* e = std::getenv(var);
        if (e == nullptr || *e == '\0') continue;
        std::string v = e;
        if (v == "C" || v == "POSIX") continue;
        return v;
    }
    return {};
#endif
}

// Idioma del SO si es uno de los incluidos; si no, "en" (p. ej. "pt-BR" -> "en").
std::string detect_system_language() {
    const std::string loc = os_locale();
    std::string base;
    for (char c : loc) {
        if (c == '-' || c == '_' || c == '.' || c == ':' || c == '@') break;
        base.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(c))));
    }
    if (is_builtin(base)) return base;
    return "en";
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
        if (code.empty()) {
            code = detect_system_language();   // sin preferencia guardada: la del sistema
            hh::log("[text] idioma del sistema: %s\n", code.c_str());
        }
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
// relleno). Los datos USA usan registros de tamaño fijo con relleno de NUL (evidencia: tablas de
// 12/16 bytes; la version PAL guardaba 3 idiomas) -> el relleno es holgura deliberada. Se reserva
// 1 byte para el NUL terminador.
// Convierte UTF-8 a los codigos EUC propios de 2 bytes de los glifos acentuados (B); el ASCII pasa
// tal cual. Ver include/hh/accent_glyphs.h (generado) y notes/2026-09-23-b-fuente-formato-y-gaiji.md.
// Devuelve false si algun caracter no tiene glifo representable en la fuente NATIVA (p. ej. kana de
// `ja`, que solo dibuja el overlay): en ese caso NO se sustituye (mejor el original que "????").
bool utf8_to_game(const std::string& in, std::string& out) {
    out.clear();
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
            return false;   // glifo no representable en la fuente nativa
        }
    }
    return true;
}

// --- Dialogos: texto EUC-JP de ancho completo (ruta A) ---------------------------------------
//
// El texto de menus/ayuda es ASCII plano; los DIALOGOS usan el motor EUC-JP del original:
// ingles en ASCII de ancho completo (`A3xx`), espacio `A1A1`, puntuacion JIS `A1xx` y acentos
// como gaiji (`B0xx` en la PAL; nosotros emitimos `B1xx`). Ver
// notes/2026-10-06-dialogos-extraccion-euc.md. Ruta A: se sustituye **en el sitio** conservando
// el numero de caracteres (2 B cada uno), rellenando con espacio de ancho completo (`A1A1`).

inline bool is_euc_pair(uint8_t a, uint8_t b) {
    return a >= 0xA1 && a <= 0xFE && b >= 0xA1 && b <= 0xFE;
}

// Puntuacion ASCII -> codigo JIS (A1xx). 0 si no aplica (se probara el bloque A3xx).
uint16_t euc_for_punct(unsigned char c) {
    switch (c) {
        case ' ': return 0xA1A1; case '.': return 0xA1A5; case ',': return 0xA1A4;
        case '?': return 0xA1A9; case '!': return 0xA1AA; case ':': return 0xA1A7;
        case ';': return 0xA1A8; case '-': return 0xA1BD; case '\'': return 0xA1AD;
        case '"': return 0xA1C8; case '(': return 0xA1CA; case ')': return 0xA1CB;
        case '/': return 0xA1BF; case '%': return 0xA1F3; case '&': return 0xA1F5;
        case '+': return 0xA1DC; case '=': return 0xA1E1; case '<': return 0xA1E3;
        case '>': return 0xA1E4; case '[': return 0xA1CE; case ']': return 0xA1CF;
        case '{': return 0xA1D0; case '}': return 0xA1D1; case '\\': return 0xA1C0;
        case '^': return 0xA1B0; case '_': return 0xA1B2; case '`': return 0xA1AE;
        case '@': return 0xA1F7; case '#': return 0xA1F4; case '$': return 0xA1F0;
        case '*': return 0xA1F6; case '|': return 0xA1C3;
        default: return 0;
    }
}

// Codigo JIS (A1xx) -> ASCII. 0 si no es puntuacion conocida.
unsigned char punct_for_euc(uint16_t code) {
    switch (code) {
        case 0xA1A1: return ' ';  case 0xA1A5: return '.';  case 0xA1A4: return ',';
        case 0xA1A9: return '?';  case 0xA1AA: return '!';  case 0xA1A7: return ':';
        case 0xA1A8: return ';';  case 0xA1BD: return '-';  case 0xA1AD: return '\'';
        case 0xA1C8: return '"';  case 0xA1CA: return '(';  case 0xA1CB: return ')';
        case 0xA1BF: return '/';  case 0xA1F3: return '%';  case 0xA1F5: return '&';
        case 0xA1DC: return '+';  case 0xA1E1: return '=';  case 0xA1E3: return '<';
        case 0xA1E4: return '>';  case 0xA1CE: return '[';  case 0xA1CF: return ']';
        case 0xA1D0: return '{';  case 0xA1D1: return '}';  case 0xA1C0: return '\\';
        case 0xA1B0: return '^';  case 0xA1B2: return '_';  case 0xA1AE: return '`';
        case 0xA1F7: return '@';  case 0xA1F4: return '#';  case 0xA1F0: return '$';
        case 0xA1F6: return '*';  case 0xA1C3: return '|';
        default: return 0;
    }
}

// Decodifica una tira de pares EUC a texto latino (la CLAVE inglesa). false si no es texto
// latino (kanji/kana/gaiji) o si la longitud es impar.
bool euc_decode(const uint8_t* seg, size_t len, std::string& out) {
    out.clear();
    if (len == 0 || (len & 1u) != 0) return false;
    for (size_t j = 0; j < len; j += 2) {
        const uint16_t code = static_cast<uint16_t>((seg[j] << 8) | seg[j + 1]);
        if ((code >> 8) == 0xA3) {                 // ASCII de ancho completo
            const unsigned lo = code & 0xFFu;
            if (lo < 0xA1 || lo > 0xFE) return false;
            out.push_back(static_cast<char>(lo - 0x80));
        } else if ((code >> 8) == 0xA1) {          // puntuacion JIS
            const unsigned char ch = punct_for_euc(code);
            if (ch == 0) return false;
            out.push_back(static_cast<char>(ch));
        } else {
            return false;                          // B0xx gaiji / kanji / kana
        }
    }
    return true;
}

// Codifica un valor UTF-8 a EUC (bloque A3xx + puntuacion A1xx + acentos `B1xx`). false si algun
// caracter no es representable.
bool utf8_to_euc(const std::string& in, std::string& out) {
    out.clear();
    for (size_t i = 0; i < in.size();) {
        const unsigned char c = static_cast<unsigned char>(in[i]);
        if (c < 0x80) {
            uint16_t code = 0;
            if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                code = static_cast<uint16_t>(0xA300u | (0x80u + c));  // 'A'->A3C1
            } else {
                code = euc_for_punct(c);
            }
            if (code == 0) return false;
            out.push_back(static_cast<char>(code >> 8));
            out.push_back(static_cast<char>(code & 0xFF));
            ++i;
            continue;
        }
        uint32_t cp = 0;
        size_t n = 0;
        if ((c & 0xE0) == 0xC0) { cp = c & 0x1F; n = 1; }
        else if ((c & 0xF0) == 0xE0) { cp = c & 0x0F; n = 2; }
        else if ((c & 0xF8) == 0xF0) { cp = c & 0x07; n = 3; }
        if (n == 0 || i + n >= in.size()) return false;
        for (size_t k = 1; k <= n; ++k) cp = (cp << 6) | (static_cast<unsigned char>(in[i + k]) & 0x3F);
        i += n + 1;
        // Los dialogos se dibujan con color4 (8x12): el codigo debe corresponder al set color4.
        uint16_t code = 0;
        for (unsigned g = 0; g < hh::kGameGlyphCount; ++g) {
            if (hh::kGameGlyphs[g].cp == cp) { code = hh::kGameGlyphs[g].code; break; }
        }
        if (code == 0) return false;
        out.push_back(static_cast<char>(code >> 8));
        out.push_back(static_cast<char>(code & 0xFF));
    }
    return !out.empty();
}

// Sustituye el texto de los mensajes EUC. A+ (reparto por mensaje): se agrupan las lineas (tiras
// EUC) hasta el fin de mensaje (un `fa 00`/`fe 00` en el hueco hacia la siguiente linea). Si el
// TOTAL traducido cabe en el tramo del mensaje, se reescribe repartiendo las lineas (solo cambian
// los saltos de linea; la suma de bytes no crece). Si no, se aplica la ruta A por linea. Devuelve el
// numero de sustituciones.
int translate_euc(uint8_t* buf, size_t len, const State& s) {
    int replaced = 0;
    struct Line { size_t start, end; bool ok; std::string repl; };
    std::vector<Line> lines;
    size_t i = 0;

    auto flush = [&]() {
        if (lines.empty()) return;
        bool any = false;
        for (const Line& l : lines) {
            if (l.ok) { any = true; break; }
        }
        if (any) {
            size_t orig = 0, trans = 0;
            for (const Line& l : lines) {
                orig += l.end - l.start;
                trans += l.ok ? l.repl.size() : (l.end - l.start);
            }
            // A+ solo si cabe el total y la ULTIMA linea es de texto (el relleno cae en su cola).
            if (trans <= orig && lines.back().ok) {
                const size_t base = lines.front().start;
                const size_t cap = lines.back().end - base;
                std::string out;
                out.reserve(cap);
                for (size_t k = 0; k < lines.size(); ++k) {
                    if (k > 0) {
                        out.append(reinterpret_cast<const char*>(buf) + lines[k - 1].end,
                                   lines[k].start - lines[k - 1].end);  // separadores verbatim
                    }
                    if (lines[k].ok) {
                        out += lines[k].repl;
                    } else {
                        out.append(reinterpret_cast<const char*>(buf) + lines[k].start,
                                   lines[k].end - lines[k].start);
                    }
                }
                if (out.size() <= cap) {
                    std::memcpy(buf + base, out.data(), out.size());
                    for (size_t j = out.size(); j < cap; j += 2) {   // relleno de ancho completo
                        buf[base + j] = 0xA1;
                        buf[base + j + 1] = 0xA1;
                    }
                    replaced++;
                    lines.clear();
                    return;
                }
            }
            // Fallback ruta A: por linea, si cabe en su propio tramo.
            for (const Line& l : lines) {
                if (!l.ok) continue;
                const size_t nb = l.end - l.start;
                if (l.repl.size() > nb) {
                    if (s.trace) {
                        hh::log("[text] euc no cabe (linea): %zu B, original %zu B\n", l.repl.size(), nb);
                    }
                    continue;
                }
                std::memcpy(buf + l.start, l.repl.data(), l.repl.size());
                for (size_t j = l.repl.size(); j < nb; j += 2) {
                    buf[l.start + j] = 0xA1;
                    buf[l.start + j + 1] = 0xA1;
                }
                replaced++;
            }
        }
        lines.clear();
    };

    while (i + 1 < len) {
        if (!is_euc_pair(buf[i], buf[i + 1])) { i++; continue; }
        const size_t start = i;
        while (i + 1 < len && is_euc_pair(buf[i], buf[i + 1])) i += 2;
        Line l;
        l.start = start;
        l.end = i;
        l.ok = false;
        std::string key;
        if (euc_decode(buf + start, i - start, key) && !key.empty()) {
            // Recorta espacios de los extremos igual que load_file(): el texto EUC de la ROM a
            // veces trae un espacio final (p.ej. "changers are top secret, ") que, si no se
            // recortase, impediria casar la clave (los espacios interiores se conservan).
            size_t a = key.find_first_not_of(" \t");
            size_t b = key.find_last_not_of(" \t");
            if (a == std::string::npos) key.clear();
            else if (a != 0 || b + 1 != key.size()) key = key.substr(a, b - a + 1);
        }
        if (!key.empty()) {
            auto it = s.index.find(key);
            if (it != s.index.end()) {
                std::string enc;
                if (utf8_to_euc(it->second->repl, enc)) { l.ok = true; l.repl = std::move(enc); }
            }
        }
        lines.push_back(std::move(l));
        // ¿fin de mensaje en el hueco hacia la siguiente tira?
        size_t j = i;
        bool end_msg = false;
        while (j + 1 < len && !is_euc_pair(buf[j], buf[j + 1])) {
            if ((buf[j] == 0xFA || buf[j] == 0xFE) && buf[j + 1] == 0x00) end_msg = true;
            j++;
        }
        if (end_msg) flush();
        i = j;
    }
    flush();
    return replaced;
}

bool translate_segment(uint8_t* seg, size_t content_len, size_t slot, const State& s) {
    std::string prefix, core;
    if (!core_of(seg, content_len, prefix, core) || core.empty()) return false;

    for (const Key& k : s.keys) {
        if (k.text != core) continue;
        std::string repl;
        if (!utf8_to_game(k.repl, repl)) return false;   // no representable: dejar el original
        std::string out = prefix + repl;
        if (out.size() + 1 > slot) {
            if (s.trace) {
                hh::log("[text] no cabe: |%s| -> |%s| (registro %zu, resultado %zu + NUL)\n",
                        core.c_str(), k.repl.c_str(), slot, out.size());
            }
            return false;
        }
        if (k.center) {
            // Texto CENTRADO por el motor: se termina JUSTO tras el texto (relleno NUL), para que el
            // motor lo centre por su longitud real. Rellenar con espacios alarga el bloque y deja el
            // texto visible a la izquierda (bug del "PRESS START" traducido mas corto).
            std::memset(seg, 0, slot);
            std::memcpy(seg, out.data(), out.size());
        } else {
            std::memset(seg, ' ', slot);
            std::memcpy(seg, out.data(), out.size());
            seg[slot - 1] = 0;  // terminador
        }
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
    // Dialogos (texto EUC-JP de ancho completo): no lleva NUL entre lineas, se escanea aparte.
    replaced += translate_euc(buf, len, s);
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
    if (env_flag("HH_LANG_REAPPLY", true)) {
        hh_trans_reapply_language();  // cambia el texto ya cargado (menus) sin recargar el juego
    }
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

std::string text::translate(const std::string& key) {
    init();
    const State& s = state();
    // `en` (y cualquier idioma sin tabla) es identidad: la clave ya es el texto original.
    if (key.empty() || !s.enabled) return key;
    for (const Key& k : s.keys) {
        if (k.text == key) return k.repl;
    }
    return key;
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
