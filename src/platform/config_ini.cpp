// hh_config_ini — lectura/escritura puntual de config.ini (ver include/hh/config_ini.h).
//
// El escritor lee el fichero línea a línea, sustituye las claves pedidas dentro de su sección e
// inserta las que falten tras la cabecera; el resto (comentarios y otras secciones) se conserva
// tal cual. Así el menú puede persistir una preferencia sin regenerar el fichero del usuario.

#include "hh/config_ini.h"

#include <cctype>
#include <cstdlib>
#include <fstream>

namespace hh {
namespace {

std::string trim(const std::string& s) {
    size_t b = s.find_first_not_of(" \t\r\n");
    if (b == std::string::npos) return {};
    size_t e = s.find_last_not_of(" \t\r\n");
    return s.substr(b, e - b + 1);
}

std::string lower(std::string s) {
    for (char& c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return s;
}

bool is_section(const std::string& line, const std::string& section) {
    const std::string t = trim(line);
    if (t.size() < 2 || t.front() != '[' || t.back() != ']') return false;
    return lower(trim(t.substr(1, t.size() - 2))) == lower(section);
}

}  // namespace

std::string config_ini_path() {
    const char* env = std::getenv("HH_PAD_CONFIG");
    if (env != nullptr && *env != '\0') return env;
    return "config.ini";
}

std::string config_ini_get(const std::string& section, const std::string& key) {
    std::ifstream f(config_ini_path());
    if (!f) return {};
    const std::string want = lower(key);
    std::string line;
    bool in = false;
    while (std::getline(f, line)) {
        const std::string t = trim(line);
        if (t.empty() || t[0] == '#' || t[0] == ';') continue;
        if (t[0] == '[') {
            in = is_section(t, section);
            continue;
        }
        if (!in) continue;
        const size_t eq = t.find('=');
        if (eq == std::string::npos) continue;
        if (lower(trim(t.substr(0, eq))) == want) return trim(t.substr(eq + 1));
    }
    return {};
}

void config_ini_set(const std::string& section,
                    const std::vector<std::pair<std::string, std::string>>& keys) {
    std::vector<std::string> lines;
    {
        std::ifstream f(config_ini_path());
        std::string line;
        while (std::getline(f, line)) {
            if (!line.empty() && line.back() == '\r') line.pop_back();
            lines.push_back(line);
        }
    }

    int header = -1;
    int section_end = -1;
    for (size_t i = 0; i < lines.size(); ++i) {
        const std::string t = trim(lines[i]);
        if (!t.empty() && t[0] == '[') {
            if (header < 0 && is_section(t, section)) {
                header = static_cast<int>(i);
            } else if (header >= 0) {
                section_end = static_cast<int>(i);
                break;
            }
        }
    }

    if (header < 0) {
        if (!lines.empty() && !lines.back().empty()) lines.push_back("");
        lines.push_back("[" + section + "]");
        for (const auto& kv : keys) lines.push_back(kv.first + " = " + kv.second);
    } else {
        std::vector<bool> written(keys.size(), false);
        const int end = (section_end < 0) ? static_cast<int>(lines.size()) : section_end;
        for (int i = header + 1; i < end; ++i) {
            const std::string t = trim(lines[i]);
            if (t.empty() || t[0] == '#' || t[0] == ';') continue;
            const size_t eq = t.find('=');
            if (eq == std::string::npos) continue;
            const std::string k = lower(trim(t.substr(0, eq)));
            for (size_t j = 0; j < keys.size(); ++j) {
                if (k == lower(keys[j].first)) {
                    lines[i] = keys[j].first + " = " + keys[j].second;
                    written[j] = true;
                }
            }
        }
        // Inserta tras la cabecera las claves que falten (en orden inverso para conservar el orden).
        for (size_t j = keys.size(); j-- > 0;) {
            if (!written[j]) {
                lines.insert(lines.begin() + header + 1, keys[j].first + " = " + keys[j].second);
            }
        }
    }

    std::ofstream out(config_ini_path(), std::ios::trunc);
    if (!out) return;
    for (const std::string& l : lines) out << l << "\n";
}

}  // namespace hh
