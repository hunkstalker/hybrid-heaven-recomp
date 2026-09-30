// hh_menu_overlay — overlay A2 del menú de título (render hook de RT64).
//
// Paso 2 (dibujo 1:1): publica un frame con las entradas del MODELO `hh::menu` (include/hh/menu.h)
// usando la fuente del juego y las posiciones nativas, y la FLECHA NATIVA como cursor. NO dibuja
// paneles de fondo ni barras inventadas. El menú NATIVO del juego queda OCULTO por defecto (se
// reescribe su texto en RDRAM); F6 lo muestra/oculta para comparar. El overlay del port siempre está
// visible (HH_OVERLAY=0 lo desactiva).
//
// Calibración en vivo (Ctrl+flechas): DELTA sobre la posición nativa del layout. Diagnósticos:
// HH_OVERLAY_X/Y/SX/SY; HH_MENU_SCREEN=<id> dibuja una pantalla concreta del árbol (revisión sin input).
//
// Ver RETOMAR.md (A2) y notes/2026-09-23-a2-render-hook-y-atlas.md.

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>

#include "hh.h"
#include "hh/font.h"
#include "hh/menu.h"
#include "hh/overlay.h"

namespace hh::menu_overlay {
namespace {

// Módulo 23 (título/menú/opciones): ROM de origen y tamaño, y offset de sus etiquetas en el enlace
// (base 0x801BF1A0): idx0 = flecha de cursor; idx1..5 = entradas (16 B cada una).
constexpr uint32_t kMod23Src = 0x5F1190;
constexpr uint32_t kMod23Size = 0xAD36;
// El juego tiene VARIAS tablas de etiquetas IDÉNTICAS para el menú raíz (una por ruta de entrada y
// por función de "atrás"), todas con la misma estructura: idx0 = flecha de cursor (gaiji A1FC);
// idx1..5 = entradas (16 B cada una); idx6 = variante "%p RESOLUTION". Cubrir solo una dejaba ver el
// menú compuesto por las demás (bug 2026-09-24: al volver atrás de un submenú aparecía el nativo).
//   - set A 0x801CEBB4: update func_801C18FC (al pulsar START).
//   - set B 0x801CEC6C: func_801C1C44 (2.ª entrada / desde el propio título).
//   - set C 0x801CF110: func_801C56B8 ("atrás" desde el submenú NUEVA PARTIDA, y similares).
// El handler func_801C1DB8 re-registra además la flecha en 0x801CECFC cada frame.
constexpr uint32_t kNativeLabelAddrs[] = {
    0x801CEBB4u,   // set A
    0x801CEC6Cu,   // set B
    0x801CF110u,   // set C
};
constexpr uint32_t kNativeArrowAddr = 0x801CECFCu;    // flecha del handler
constexpr unsigned kNativeLabelsLen = 7 * 16;         // idx0..6

// MODO COMBATE (submenu de batalla, tambien en file_024): etiquetas y flecha propias. Se ocultan
// cuando el overlay controla el submenu (el port dibuja sus propios rotulos traducidos).
//   - etiquetas idx0..4: 0x801CEDA4 .. 0x801CEDF4, 20 B cada una (cabecera + VS MODE / CREATURE
//     BATTLE / DATA EDIT / EXIT). Rango [0x801CEDA4, 0x801CEE08).
//   - flecha/cursor que registra func_801C4200 cada frame: 0x801CEE10 (16 B).
constexpr uint32_t kBattleLabelAddr = 0x801CEDA4u;
constexpr unsigned kBattleLabelsLen = 5 * 20;         // 0x64
constexpr uint32_t kBattleArrowAddr = 0x801CEE10u;
constexpr unsigned kBattleArrowLen = 16;

// COMBATE DE CRIATURAS (pantalla interna; func_801C43BC / func_801C44C4). Etiquetas y su campo:
//   - 0x801CEE24 "%mCREATURE BATTLE" (cabecera, campo 20 B).
//   - 0x801CEE38 flecha/cursor (campo 12 B); 0x801CEE44 " 5 MATCHES"; 0x801CEE50 " SURVIVAL ".
// Rango [0x801CEE24, 0x801CEE5C) = 0x38.
constexpr uint32_t kCreatureLabelAddr = 0x801CEE24u;
constexpr unsigned kCreatureLabelsLen = 0x38;

// Regiones de texto del menú nativo que se ocultan (espacios). Se guardan/restauran tal cual.
struct NativeRange {
    uint32_t off;
    unsigned len;
};
constexpr NativeRange kNativeRanges[] = {
    { kNativeLabelAddrs[0] - 0x801BF1A0u, kNativeLabelsLen },   // set A (0xFA14)
    { kNativeLabelAddrs[1] - 0x801BF1A0u, kNativeLabelsLen },   // set B (0xFACC)
    { kNativeLabelAddrs[2] - 0x801BF1A0u, kNativeLabelsLen },   // set C (0xFF70)
    { kNativeArrowAddr - 0x801BF1A0u, 16 },                     // flecha del handler (0xFB5C)
    { kBattleLabelAddr - 0x801BF1A0u, kBattleLabelsLen },       // MODO COMBATE: etiquetas (0xFC04)
    { kBattleArrowAddr - 0x801BF1A0u, kBattleArrowLen },        // MODO COMBATE: flecha (0xFC70)
    { kCreatureLabelAddr - 0x801BF1A0u, kCreatureLabelsLen },   // COMBATE DE CRIATURAS (0xFC84)
};
constexpr unsigned kNativeBackupSize = 3 * kNativeLabelsLen + 16 + kBattleLabelsLen +
                                       kBattleArrowLen + kCreatureLabelsLen;

bool g_visible = true;
// Menú nativo del juego: oculto por defecto (F6 lo muestra/oculta para comparar). `HH_NATIVE=1` lo
// muestra ya al arrancar (diagnóstico headless, equivale a F6).
bool g_native_visible = [] {
    const char* e = std::getenv("HH_NATIVE");
    return e != nullptr && *e != '\0' && *e != '0';
}();
bool g_native_last_reported = false;
// Copia del texto nativo para poder restaurarlo al volver a mostrar el menú (el juego lo compone
// una sola vez por entrada; ver suppress_native).
uint8_t g_native_backup[kNativeBackupSize];
bool g_native_backed_up = false;
// Calibración en vivo: DELTA sobre la posición nativa del layout (default 0 = posición nativa).
float g_calib_x = 0.0f;
float g_calib_y = 0.0f;
// Escala del texto: 1.0 = tamaño nativo del glifo (8x8 del juego, sin estirar).
float g_scale_x = 1.0f;
float g_scale_y = 1.0f;
bool g_offsets_loaded = false;

// Y superior del texto = Y del motor (0x76) + 5 px de métrica de la fuente (medido al alinear el
// overlay con el menú real: ver notes/2026-09-23-a2-render-hook-y-atlas.md §6).
constexpr float kTextTopOffset = 5.0f;

// Columna (en caracteres, desde el inicio de la etiqueta) donde empiezan los valores de los
// selectores laterales. Fija para que queden alineados; la etiqueta más larga ("APUNTADO LIBRE",
// con su espacio inicial) ocupa 15, así que 16 deja 1 de margen y, además, deja sitio al valor más
// largo (`3840x2160`, 9) con su chevron derecho.
constexpr float kSelectorValueCol = 16.0f;

// EXTRAS es un menu del PORT (no existe en el original), asi que puede tener su propio layout: usa
// el hueco libre a la IZQUIERDA y una columna de valores calculada a partir de su etiqueta mas larga,
// para que quepan nombres como "MANTENER EXTRAS" / "LOGOS ORIGINALES" sin solaparse con el valor.
constexpr float kExtrasValueGap = 2.0f;    // caracteres de separacion tras la etiqueta mas larga
constexpr float kKeyColGap = 11.0f;        // columnas MANDO/TECLADO (CONTROLES): separacion

constexpr uint32_t kWhite = hh::overlay::rgba(255, 255, 255, 255);
constexpr uint32_t kYellow = hh::overlay::rgba(255, 220, 64, 255);
constexpr uint32_t kGreen = hh::overlay::rgba(96, 255, 96, 255);
// Gris de opción no seleccionada/deshabilitada (el original "sombrea" lo que no está activo).
constexpr uint32_t kGray = hh::overlay::rgba(130, 130, 130, 255);
// Sombra del texto/UI (negra, +1 px derecha/abajo), como la horneada en el atlas de la fuente.
constexpr uint32_t kShadow = hh::overlay::rgba(0, 0, 0, 255);
// Relleno de las cajas del DATA LOAD (oscuro semitransparente, como el nativo).
constexpr uint32_t kBoxFill = hh::overlay::rgba(0, 0, 0, 160);

// El handler del menú de título se ejecuta en el hilo del juego; `tick` en el de render. El contador
// permite ocultar el overlay cuando el menú deja de publicarlo (p. ej. al salir del título).
std::atomic<uint64_t> g_publish_counter{ 0 };

void load_offsets_once() {
    if (g_offsets_loaded) return;
    g_offsets_loaded = true;
    if (const char* x = std::getenv("HH_OVERLAY_X")) g_calib_x = static_cast<float>(std::atof(x));
    if (const char* y = std::getenv("HH_OVERLAY_Y")) g_calib_y = static_cast<float>(std::atof(y));
    if (const char* sx = std::getenv("HH_OVERLAY_SX")) g_scale_x = static_cast<float>(std::atof(sx));
    if (const char* sy = std::getenv("HH_OVERLAY_SY")) g_scale_y = static_cast<float>(std::atof(sy));
}

// --- UTF-8 -> ASCII (TEMPORAL) -------------------------------------------------------------------
// El atlas del overlay todavía solo mapea ASCII (A-Z/a-z/espacio); los acentos reales llegarán en el
// paso 4 (atlas con los gaiji). Hasta entonces, se pliegan a su letra base para poder revisar el
// dibujo (p. ej. ESPAÑOL -> ESPANOL).
unsigned utf8_next(const std::string& s, size_t& i) {
    unsigned c = static_cast<unsigned char>(s[i++]);
    if (c < 0x80) return c;
    const unsigned extra = (c >= 0xF0) ? 3u : (c >= 0xE0) ? 2u : 1u;
    unsigned cp = c & (0x3Fu >> extra);
    for (unsigned k = 0; k < extra && i < s.size(); ++k) {
        cp = (cp << 6) | (static_cast<unsigned char>(s[i++]) & 0x3Fu);
    }
    return cp;
}

char ascii_fold(unsigned cp) {
    if (cp < 0x80) return static_cast<char>(cp);
    switch (cp) {
        case 0xC0: case 0xC1: case 0xC2: case 0xC3: case 0xC4: case 0xC5: return 'A';
        case 0xC7: return 'C';
        case 0xC8: case 0xC9: case 0xCA: case 0xCB: return 'E';
        case 0xCC: case 0xCD: case 0xCE: case 0xCF: return 'I';
        case 0xD1: return 'N';
        case 0xD2: case 0xD3: case 0xD4: case 0xD5: case 0xD6: case 0xD8: return 'O';
        case 0xD9: case 0xDA: case 0xDB: case 0xDC: return 'U';
        case 0xE0: case 0xE1: case 0xE2: case 0xE3: case 0xE4: case 0xE5: return 'a';
        case 0xE7: return 'c';
        case 0xE8: case 0xE9: case 0xEA: case 0xEB: return 'e';
        case 0xEC: case 0xED: case 0xEE: case 0xEF: return 'i';
        case 0xF1: return 'n';
        case 0xF2: case 0xF3: case 0xF4: case 0xF5: case 0xF6: case 0xF8: return 'o';
        case 0xF9: case 0xFA: case 0xFB: case 0xFC: return 'u';
        case 0xBF: return '?';
        case 0xA1: return '!';
        default: return '?';
    }
}

[[maybe_unused]] std::string to_ascii(const std::string& s) {
    std::string out;
    out.reserve(s.size());
    size_t i = 0;
    while (i < s.size()) {
        out.push_back(ascii_fold(utf8_next(s, i)));
    }
    return out;
}

// Numero de CODEPOINTS (no bytes): el avance del texto es monospace por caracter.
size_t cp_count(const std::string& s) {
    size_t i = 0, n = 0;
    while (i < s.size()) {
        utf8_next(s, i);
        ++n;
    }
    return n;
}

// --- Flecha nativa de cursor ---------------------------------------------------------------------
// Medida del menú original (captura 2560x1440): triángulo que apunta a la derecha, 6x5 px virtuales,
// pegado al inicio de la línea (ocupa el espacio inicial de la etiqueta). Se compone con rectángulos
// (la prohibición de "paneles" es para fondos/barras inventados, no para la flecha del juego).
void append_native_cursor(hh::overlay::Frame& frame, float x, float y, uint32_t color) {
    static const uint8_t kWidths[5] = { 2, 4, 6, 4, 2 };
    // Sombra: copia negra desplazada +1 px a la derecha y +1 abajo (como la del texto). Se pinta
    // primero para que la flecha quede encima.
    for (int row = 0; row < 5; ++row) {
        frame.panels.push_back({ x + 1.0f, y + static_cast<float>(row) + 1.0f,
                                 static_cast<float>(kWidths[row]), 1.0f, kShadow });
    }
    for (int row = 0; row < 5; ++row) {
        frame.panels.push_back(
            { x, y + static_cast<float>(row), static_cast<float>(kWidths[row]), 1.0f, color });
    }
}

// Separador "/" de los selectores (5x5) compuesto con rectángulos de 1 px: la fuente del menú
// (color0) no tiene puntuación (solo dígitos, letras y espacio). Se dibuja entre los valores.
void append_slash(hh::overlay::Frame& frame, float x, float y, uint32_t color) {
    for (int row = 0; row < 5; ++row) {
        frame.panels.push_back(
            { x + static_cast<float>(4 - row), y + static_cast<float>(row), 1.0f, 1.0f, color });
    }
}

// Texto con separador "/": la fuente no tiene glifo de barra, asi que se parte por '/' y se dibuja
// `append_slash` entre segmentos (mismo estilo que los selectores NO/SI).
void append_text_with_slashes(hh::overlay::Frame& frame, float x, float y, uint32_t color,
                              const std::string& s) {
    constexpr float kSlashSep = 2.0f;
    constexpr float kSlashW = 5.0f;
    const float step = 8.0f * g_scale_x;
    float ox = x;
    size_t start = 0;
    while (true) {
        const size_t slash = s.find('/', start);
        const std::string seg =
            (slash == std::string::npos) ? s.substr(start) : s.substr(start, slash - start);
        frame.texts.push_back({ ox, y, g_scale_x, g_scale_y, color, seg });
        ox += static_cast<float>(cp_count(seg)) * step;
        if (slash == std::string::npos) break;
        ox += kSlashSep;
        append_slash(frame, ox, y + 1.0f, color);
        ox += kSlashW + kSlashSep;
        start = slash + 1;
    }
}

// Flecha "<" / ">" (chevron 5x5) de los selectores largos, con rectángulos de 2 px. `left` elige la
// orientación; la punta cae en la fila central.
void append_chevron(hh::overlay::Frame& frame, float x, float y, bool left, uint32_t color) {
    static const uint8_t kOff[5] = { 2, 1, 0, 1, 2 };   // distancia a la punta (fila central)
    for (int row = 0; row < 5; ++row) {
        const float ox = left ? static_cast<float>(kOff[row]) : static_cast<float>(2 - kOff[row]);
        frame.panels.push_back({ x + ox, y + static_cast<float>(row), 2.0f, 1.0f, color });
    }
}

// Flecha VERTICAL (indicador de scroll): triangulo de 5 filas, con la sombra +1,+1 del cursor.
// `up` = punta arriba. Se usa para avisar de que hay filas por encima/por debajo.
void append_scroll_arrow(hh::overlay::Frame& frame, float x, float y, bool up, uint32_t color) {
    static const uint8_t kW[5] = { 1, 3, 5, 7, 9 };
    for (int row = 0; row < 5; ++row) {
        const int w = up ? kW[row] : kW[4 - row];
        const float ox = (9.0f - static_cast<float>(w)) * 0.5f;
        frame.panels.push_back(
            { x + ox + 1.0f, y + static_cast<float>(row) + 1.0f, static_cast<float>(w), 1.0f,
              kShadow });
    }
    for (int row = 0; row < 5; ++row) {
        const int w = up ? kW[row] : kW[4 - row];
        const float ox = (9.0f - static_cast<float>(w)) * 0.5f;
        frame.panels.push_back(
            { x + ox, y + static_cast<float>(row), static_cast<float>(w), 1.0f, color });
    }
}

// Caja con BORDE (1 px) y relleno semitransparente, como las del DATA LOAD nativo. Se dibuja con 4
// paneles de borde sobre un relleno. `color` = color del borde; el relleno es oscuro translucido.
void append_box(hh::overlay::Frame& frame, float x, float y, float w, float h, uint32_t color,
                uint32_t fill) {
    frame.panels.push_back({ x, y, w, h, fill });
    frame.panels.push_back({ x, y, w, 1.0f, color });             // borde superior
    frame.panels.push_back({ x, y + h - 1.0f, w, 1.0f, color });  // borde inferior
    frame.panels.push_back({ x, y, 1.0f, h, color });             // borde izquierdo
    frame.panels.push_back({ x + w - 1.0f, y, 1.0f, h, color });  // borde derecho
}

}  // namespace

bool visible() { return g_visible; }

// ============================================================================================
// OCULTADO DE LA UI NATIVA (categorías)
// --------------------------------------------------------------------------------------------
// `g_native_visible` (F8) es la ÚNICA fuente de verdad: false = UI nativa oculta, true = visible.
// Cada categoría de UI nativa tiene su propia función de ocultado, todas consultan `g_native_visible`:
//   - Título/menús del módulo 23: `hide_title_labels` (tablas en RDRAM) + `hidden_title_field_len`
//     (texto compuesto por `func_8001B204`).
//   - File-select DATA LOAD/SAVE (`file_008`): `g_file_select_active` (lo marcan los hooks) +
//     `hide_file_select_text` (blankea TODO el texto compuesto) + `suppress_box_draw` (cajas
//     `func_8001A804`).
// ============================================================================================

// Menú nativo: `native_visible()`/`native_toggle()` (F8). Por defecto oculto.
bool native_visible() { return g_native_visible; }
void native_toggle() { g_native_visible = !g_native_visible; }

// Categoría FILE-SELECT (DATA LOAD/SAVE): activa mientras su pantalla corre (lo marcan los hooks en
// `sections.cpp`). Independiente de la visibilidad: dice QUÉ UI nativa está en pantalla.
bool g_file_select_active = false;
void set_file_select_active(bool on) { g_file_select_active = on; }

// true UNA vez cada vez que F8 cambia la visibilidad (para forzar el re-registro del menú nativo).
bool native_toggle_pending() {
    if (g_native_visible != g_native_last_reported) {
        g_native_last_reported = g_native_visible;
        return true;
    }
    return false;
}

// --- Categoría TÍTULO: etiquetas del módulo 23 (tablas en RDRAM) -------------------------------
// Oculta (o restaura) las etiquetas idx0..5 y la flecha que el handler registra. El juego compone el
// texto una sola vez por entrada (func_801C18FC), así que además hay que re-ejecutarlo al alternar.
void suppress_native(uint8_t* rdram) {
    if (rdram == nullptr) {
        return;
    }
    const uint32_t base = hh_trans_dst_for(kMod23Src, kMod23Size);
    if (base == 0) {
        return;
    }
    if (!g_native_backed_up) {
        unsigned b = 0;
        for (const NativeRange& r : kNativeRanges) {
            for (unsigned i = 0; i < r.len; ++i) {
                g_native_backup[b++] = rdram[((base + r.off + i) - 0x80000000u) ^ 3u];
            }
        }
        g_native_backed_up = true;
        hh::log("[native] backup capturado base=%08X vis=%d\n", base, g_native_visible ? 1 : 0);
    }
    unsigned b = 0;
    for (const NativeRange& r : kNativeRanges) {
        for (unsigned i = 0; i < r.len; ++i) {
            const uint8_t v = g_native_visible
                                  ? g_native_backup[b]
                                  : static_cast<uint8_t>((i % 16u) == 15u ? 0x00u : 0x20u);
            rdram[((base + r.off + i) - 0x80000000u) ^ 3u] = v;
            ++b;
        }
    }
}

// --- Categoría TÍTULO: texto compuesto (`func_8001B204`) ----------------------------------------
// Longitud del campo de texto del título que hay que blankear para `a` (0 = no es campo del título).
// Campos: raíz = 16 B; submenú de batalla = 20 B (5 campos, paso 0x14); COMBATE DE CRIATURAS:
// cabecera 20 B, flecha/opciones 12 B; flechas = 16 B.
unsigned hidden_title_field_len(uint32_t a) {
    for (uint32_t base : kNativeLabelAddrs) {
        if (a >= base && a < base + kNativeLabelsLen) {
            return 16;
        }
    }
    if (a >= kBattleLabelAddr && a < kBattleLabelAddr + kBattleLabelsLen &&
        ((a - kBattleLabelAddr) % 0x14u) == 0) {
        return 20;
    }
    if (a == kCreatureLabelAddr) {
        return 20;
    }
    if (a == 0x801CEE38u || a == 0x801CEE44u || a == 0x801CEE50u) {
        return 12;
    }
    if (a == kNativeArrowAddr || a == kBattleArrowAddr) {
        return 16;
    }
    return 0;
}

// --- Categoría FILE-SELECT: texto compuesto (`func_8001B204`) y cajas (`func_8001A804`) --------
// El DATA LOAD/SAVE compone su texto con `func_8001B204` desde sus tablas (file_008, base REUBICADA
// en runtime). Se blankea el CAMPO COMPUESTO justo antes de leerlo, acotado a las direcciones de sus
// tablas (blankear "cualquier campo" corrompía texto ajeno -> SEGV medido; blankear la tabla por
// vaddr fija NO sirve porque la base está reubicada).
unsigned file_select_field_len(uint32_t a) {
    switch (a) {
        case 0x8018F16Cu: case 0x8018F1BCu: return 20;   // título "DATA LOAD" / "DATA SAVE"
        case 0x8018F184u: case 0x8018F1D4u: return 16;   // "CONTROLLER PAK"
        case 0x8018F6BCu: case 0x8018F6DCu: case 0x8018F73Cu: return 20;   // AREA / LEVEL / TIME
        case 0x8018F20Cu: case 0x8018F230u: return 20;   // mensaje "Select play data..."
        default: return 0;
    }
}

// Las cajas del file-select las dibuja `func_8001A804`: se saltan cuando la pantalla está activa.
bool suppress_box_draw() { return !g_native_visible && g_file_select_active; }


// --- Punto de entrada del ocultado de TEXTO (hook de func_8001B204) -----------------------------
// La COMPOSICIÓN del texto (`func_8001B204`) lee la dirección de enlace y la copia a su estructura.
// Si su categoría está oculta, se meten espacios en el campo justo antes de que lo lea.
void filter_native_text(uint8_t* rdram, uint32_t text_addr) {
    if (rdram == nullptr || g_native_visible) {
        return;
    }
    const unsigned len = g_file_select_active ? file_select_field_len(text_addr)
                                              : hidden_title_field_len(text_addr);
    if (len == 0) {
        return;
    }
    const uint32_t off = text_addr - 0x80000000u;
    if (off >= 0x800000u) {
        return;
    }
    hh::log("[native] filter text=%08X len=%u\n", text_addr, len);
    for (unsigned i = 0; i < len; ++i) {
        if (off + i >= 0x800000u) break;
        rdram[(off + i) ^ 3u] = (i == len - 1) ? 0x00u : 0x20u;
    }
}

// Calibración en vivo (Ctrl+flechas, ver src/subsystems/input.cpp). Escribe los valores en hh.log.
void adjust(float dx, float dy, float dsx, float dsy) {
    load_offsets_once();
    g_calib_x += dx;
    g_calib_y += dy;
    g_scale_x = std::clamp(g_scale_x + dsx, 0.25f, 3.0f);
    g_scale_y = std::clamp(g_scale_y + dsy, 0.25f, 3.0f);
    hh::log("[overlay] calib dx=%.2f dy=%.2f sx=%.3f sy=%.3f\n", g_calib_x, g_calib_y, g_scale_x,
            g_scale_y);
}

// Se llama desde el handler del menú de título (hh_title_menu_hook) DESPUÉS del original.
void title_update(uint8_t* rdram) {
    (void)rdram;
    if (!g_visible) {
        return;
    }
    load_offsets_once();

    static const bool trace = [] {
        const char* e = std::getenv("HH_MENU_TRACE");
        return e != nullptr && *e != '\0' && *e != '0';
    }();
    static bool traced = false;

    // Diagnóstico: fija la pantalla a revisar (HH_MENU_SCREEN=<id de ScreenId>).
    static const int force_screen = [] {
        const char* e = std::getenv("HH_MENU_SCREEN");
        return (e != nullptr && *e != '\0') ? std::atoi(e) : -1;
    }();
    if (force_screen >= 0) {
        hh::menu::debug_show(force_screen);
    }

    const hh::menu::Screen& screen = hh::menu::current_screen();
    const hh::menu::Layout& layout = hh::menu::layout();

    // Menus del PORT (EXTRAS, CONTROLES): layout propio -> contenido a la izquierda y columna de
    // valores calculada por la etiqueta mas larga (sus etiquetas/bindings no caben con la nativa).
    const bool is_controls = (screen.id == hh::menu::ScreenId::Controls);
    const bool is_combat_sim = (screen.id == hh::menu::ScreenId::SaveEditCombatSim);
    const bool is_save_edit = (screen.id == hh::menu::ScreenId::SaveEdit ||
                               screen.id == hh::menu::ScreenId::SaveEditAbilities ||
                               screen.id == hh::menu::ScreenId::SaveEditBody ||
                               screen.id == hh::menu::ScreenId::SaveEditItems ||
                               screen.id == hh::menu::ScreenId::SaveEditStats ||
                               is_combat_sim);
    // GRÁFICOS es una pantalla NATIVA de selectores, pero se CENTRA como los menus del PORT (misma
    // columna de valores: su etiqueta mas larga, "LÍMITE DE FPS", mide lo mismo que kSelectorValueCol).
    const bool is_graphics = (screen.id == hh::menu::ScreenId::Graphics);
    // DEBUG quedó sin entradas (sus opciones se movieron a GRÁFICOS y EXTRAS); se conserva el id por
    // compatibilidad de `HH_MENU_SCREEN`, pero ya no es alcanzable desde el menú.
    const bool is_debug = (screen.id == hh::menu::ScreenId::Debug);
    // Menus del PORT con layout propio y VENTANA de 5 filas (listas largas): EXTRAS, CONTROLES, el
    // editor, GRÁFICOS y CARGAR PARTIDA (45 partidas -> necesita scroll).
    const bool is_load_game = (screen.id == hh::menu::ScreenId::LoadGame);
    const bool scroll_cap5 = is_controls || (screen.id == hh::menu::ScreenId::Extras) || is_save_edit ||
                             is_graphics || is_load_game;
    // Los menus del PORT (EXTRAS, CONTROLES, EDICIÓN DE PARTIDA), GRÁFICOS, SONIDO y CARGAR PARTIDA se
    // CENTRAN; el resto de los nativos conserva su margen original.
    const bool is_sound = (screen.id == hh::menu::ScreenId::Sound);
    const bool is_choose_level = (screen.id == hh::menu::ScreenId::ChooseLevel);
    const bool custom_layout = scroll_cap5 || is_graphics || is_sound || is_choose_level || is_debug;
    float x_shift = 0.0f;
    float selector_col = kSelectorValueCol;   // EXTRAS: columna de valores; CONTROLES: columna MANDO
    float key_col = selector_col + kKeyColGap;  // CONTROLES: columna TECLADO
    if (custom_layout) {
        const float step = 8.0f * g_scale_x;
        size_t max_label = 0, max_gp = 0, max_key = 0;
        for (const hh::menu::Entry& e : screen.entries) {
            max_label = std::max(max_label, cp_count(hh::menu::localized(e.label)));
            if (e.kind == hh::menu::Kind::Binding) {
                max_gp = std::max(max_gp, cp_count(hh::pad_binding_gamepad(e.remap_key)));
                max_key = std::max(max_key, cp_count(hh::pad_binding_key(e.remap_key)));
            }
        }
        float content_px = 0.0f;
        if (is_controls) {
            // Columnas MANDO y TECLADO: etiqueta + 1 espacio + 1 hueco, y luego el binding de mando.
            selector_col = static_cast<float>(max_label + 1) + 1.0f;
            key_col = selector_col + static_cast<float>(max_gp) + 2.0f;
            content_px = (key_col + static_cast<float>(max_key)) * step;
        } else {
            selector_col = static_cast<float>(max_label + 1) + kExtrasValueGap;
            key_col = selector_col + kKeyColGap;
            // Ancho de la columna de valores: el que REALMENTE se dibuja. Un selector con muchas
            // opciones no cabe y sale en forma larga (< valor >); sumar TODAS las opciones (p. ej.
            // PROGRESO con ~228) mandaba el contenido fuera de pantalla (menú "vacío").
            constexpr float kSlashSep2 = 2.0f, kSlashW2 = 5.0f;
            const float value_x = selector_col * step;
            float max_val_px = 0.0f;
            for (const hh::menu::Entry& e : screen.entries) {
                if (e.kind == hh::menu::Kind::Selector && !e.options.empty()) {
                    float sum = 0.0f, single = 0.0f;
                    for (size_t oi = 0; oi < e.options.size(); ++oi) {
                        const float ow =
                            static_cast<float>(cp_count(hh::menu::localized(e.options[oi]))) * step;
                        single = std::max(single, ow);
                        sum += ow;
                        if (oi + 1 < e.options.size()) sum += 2.0f * kSlashSep2 + kSlashW2;
                    }
                    const bool fits = value_x + sum <= hh::overlay::kVirtualWidth - 4.0f;
                    max_val_px = std::max(max_val_px, fits ? sum : (single + 12.0f));
                } else if (e.kind == hh::menu::Kind::Number) {
                    // Grupo `< [prefijo]NNN >`: prefijo + 3 dígitos + chevrons. Si hay valor (suffix),
                    // se dibuja en columna fija (selector_col+12) -> el ancho es 12 + |suffix|.
                    const float group = static_cast<float>(cp_count(e.prefix) + 3) * step +
                                        (4.0f + 2.0f);
                    const float w =
                        e.suffix.empty()
                            ? group
                            : std::max(group, 12.0f * step +
                                                  static_cast<float>(cp_count(e.suffix)) * step);
                    max_val_px = std::max(max_val_px, w);
                } else if (e.kind == hh::menu::Kind::Toggle) {
                    max_val_px = std::max(max_val_px, 4.0f * step);   // "SÍ"/"NO"
                }
            }
            content_px = value_x + max_val_px;
        }
        x_shift = (hh::overlay::kVirtualWidth - content_px) * 0.5f - layout.x;
        // Nunca empujar el contenido fuera del borde IZQUIERDO: si el calculo de ancho se queda corto
        // (p. ej. un binding de CONTROLES muy largo), centrar daria x_shift muy negativo y el texto
        // saldria de pantalla. En ese caso se alinea al margen de 2 px en vez de centrar.
        x_shift = std::max(x_shift, 2.0f - layout.x);
    }

    hh::overlay::Frame frame;
    frame.visible = true;

    // --- CARGAR PARTIDA (menú propio de carga; Fase 2) --------------------------------------------
    // Dibujo 1:1 con el DATA LOAD nativo: título "DATA LOAD", subtítulo "CONTROLLER PAK", una CAJA con
    // borde por partida (3 filas: ÁREA N-P / NIVEL n / TIEMPO M:SS) y una caja de mensaje abajo. Los
    // valores de cada fila salen de los metadatos del trailer del `.pak`. El cursor (flecha nativa) se
    // posa sobre la partida actual. Ver notes/2026-09-29-menu-cargar-guardar-fase2-ui.md.
    if (is_load_game) {
        const float step = 8.0f * g_scale_x;
        const float line = layout.dy;                    // 10 px por línea
        // Título centrado arriba (como "DATA LOAD"). Fuente NATIVA color3 (12x13), medida en
        // headless: valor de glifo 'A'=0x76; ver notes/2026-09-30-tipografias-data-load-hallazgos.md.
        {
            const std::string title = hh::menu::localized("CARGAR PARTIDA");
            const float title_step = 12.0f * g_scale_x;
            const float tw = static_cast<float>(cp_count(title)) * title_step;
            frame.texts.push_back({ (hh::overlay::kVirtualWidth - tw) * 0.5f, 20.0f, g_scale_x,
                                    g_scale_y, kWhite, title, hh::font::game::Face::Color3 });
        }
        const float box_x = 58.0f;
        const float box_w = 200.0f;
        const float box0_y = 34.0f;
        const float box_h = line * 3.0f + 4.0f;          // caja de 3 líneas
        const float box_step = box_h + 2.0f;             // separación entre cajas
        const int n_entries = static_cast<int>(screen.entries.size());
        // Caben cajas hasta y≈150 (deja la caja de mensaje abajo).
        int kMaxBoxes = static_cast<int>((150.0f - box0_y) / box_step);
        if (kMaxBoxes < 1) kMaxBoxes = 1;
        int first = 0;
        if (n_entries > kMaxBoxes) {
            if (screen.cursor >= first + kMaxBoxes) first = screen.cursor - kMaxBoxes + 1;
            if (screen.cursor < first) first = screen.cursor;
            first = std::clamp(first, 0, n_entries - kMaxBoxes);
        }
        const int last = std::min(n_entries, first + kMaxBoxes);
        for (int i = first; i < last; ++i) {
            const hh::menu::Entry& e = screen.entries[static_cast<size_t>(i)];
            const float by = box0_y + static_cast<float>(i - first) * box_step;
            const bool present = e.enabled;
            const bool selected = (i == screen.cursor);
            // Como el nativo: borde de la caja seleccionada en verde; el resto, blanco/gris.
            const uint32_t border = selected ? kGreen : (present ? kWhite : kGray);
            append_box(frame, box_x, by, box_w, box_h, border, kBoxFill);
            // El label trae 3 líneas separadas por '\n'.
            const std::string& lab = e.label;
            float ty = by + 3.0f;
            size_t p0 = 0;
            while (p0 <= lab.size()) {
                size_t p1 = lab.find('\n', p0);
                const std::string ln = (p1 == std::string::npos) ? lab.substr(p0)
                                                                 : lab.substr(p0, p1 - p0);
                frame.texts.push_back({ box_x + 4.0f, ty, g_scale_x, g_scale_y,
                                        present ? kWhite : kGray, " " + ln });
                if (p1 == std::string::npos) break;
                p0 = p1 + 1;
                ty += line;
            }
            if (selected) {
                append_native_cursor(frame, box_x - 9.0f, by + 3.0f, kWhite);
            }
        }
        // Indicadores de scroll.
        if (n_entries > kMaxBoxes) {
            if (first > 0) append_scroll_arrow(frame, box_x - 15.0f, box0_y - 7.0f, true, kWhite);
            if (first + kMaxBoxes < n_entries) {
                const float ay = box0_y + static_cast<float>(kMaxBoxes) * box_step;
                append_scroll_arrow(frame, box_x - 15.0f, ay, false, kWhite);
            }
        }
        // Caja de mensaje inferior (como "Select play data to be loaded."): ancha, casi de borde a
        // borde; el texto va alineado a la IZQUIERDA de su caja (sangría de 1 glifo).
        {
            const float msg_y = 168.0f;
            const float msg_x = 22.0f, msg_w = 276.0f, msg_h = 20.0f;
            append_box(frame, msg_x, msg_y, msg_w, msg_h, kWhite, kBoxFill);
            const std::string msg = hh::menu::localized("ELIGE LA PARTIDA A CARGAR");
            // Fuente NATIVA color4 (8x12) = la del texto in-game (mensaje del DATA LOAD).
            // +4 px de sangría (2 px más que antes): el mantenedor pidió moverlo un par de px a la
            // derecha respecto al borde de la caja. Ver notes/2026-09-30-tipografias-data-load-hallazgos.md.
            frame.texts.push_back({ msg_x + 4.0f, msg_y + 4.0f, g_scale_x, g_scale_y, kWhite,
                                    " " + msg, hh::font::game::Face::Color4 });
        }
        if (trace) {
            static int last_screen2 = -1;
            if (static_cast<int>(screen.id) != last_screen2) {
                last_screen2 = static_cast<int>(screen.id);
                hh::log("[overlay] screen=%d (CARGAR PARTIDA) entries=%zu\n", last_screen2,
                        screen.entries.size());
            }
        }
        g_publish_counter.fetch_add(1, std::memory_order_relaxed);
        hh::overlay::publish(std::move(frame));
        return;
    }

    // Scroll vertical: si no caben todas las entradas (p. ej. CONTROLES), se muestra una VENTANA que
    // sigue al cursor. Para pantallas cortas `first=0` y todo queda igual que el nativo.
    const int n_entries = static_cast<int>(screen.entries.size());
    const float list_y0 = layout.y0 + kTextTopOffset;
    // Filas visibles: hasta el copyright nativo (~y=188). En los menus del PORT (CONTROLES) se
    // limita a 5: las filas se ocultan a partir de la 6ª y el cursor hace scrollear la ventana.
    constexpr float kListBottom = 188.0f;
    int max_visible = std::max(1, static_cast<int>((kListBottom - list_y0) / layout.dy));
    if (scroll_cap5 && !is_combat_sim) max_visible = std::min(max_visible, 5);
    int first = 0;
    if (n_entries > max_visible) {
        if (screen.cursor >= first + max_visible) first = screen.cursor - max_visible + 1;
        if (screen.cursor < first) first = screen.cursor;
        first = std::clamp(first, 0, n_entries - max_visible);
    }
    const int last = std::min(n_entries, first + max_visible);

    for (int i = first; i < last; ++i) {
        const hh::menu::Entry& e = screen.entries[static_cast<size_t>(i)];
        const float x = layout.x + g_calib_x + x_shift;
        const float y = list_y0 + layout.dy * static_cast<float>(i - first) + g_calib_y;
        const bool selected = (i == screen.cursor);
        // Fila-hueco (etiqueta vacía): no dibuja nada (ni flecha); deja un espacio vertical.
        if (e.label.empty()) {
            continue;
        }

        // Las ETIQUETAS del menú van en blanco (amarillo la del cursor + flecha nativa). La regla
        // gris/verde es SOLO para las opciones a configurar: en una lista, la aplicada en verde y el
        // resto en gris; en un selector, el valor activo en verde y el resto en gris (abajo). Las
        // entradas deshabilitadas (p. ej. MODO COMBATE, por definir) van siempre en gris.
        uint32_t color = kWhite;
        if (!e.enabled) {
            color = kGray;
        } else if (screen.kind == hh::menu::ScreenKind::List) {
            color = e.marked ? kGreen : kGray;
        } else if (selected) {
            color = kYellow;
        }
        // Sangría nativa: las etiquetas del motor llevan un espacio inicial (donde va la flecha).
        const std::string text = " " + hh::menu::localized(e.label);
        // Alineación del primer glifo: la fuente no es uniforme (M/O/V/W/X/Z empiezan en la columna 0
        // y el resto en la 1), así que una línea que empiece por 'M' saldría 1 px a la izquierda del
        // resto (p. ej. "MODO COMBATE"). El menú nativo solo usa inicios de columna 1, por eso se ve
        // uniforme; compensamos el primer carácter a esa columna de referencia (1) para igualarlo.
        float x_text = x;
        // Compensación del primer glifo (fuente no uniforme): todas las etiquetas empiezan a la misma
        // columna, sin importar la letra inicial.
        {
            size_t bi = 0;
            while (bi < text.size()) {
                const unsigned cp = utf8_next(text, bi);
                if (cp == ' ') continue;
                if (cp < 0x80) {
                    const int bearing =
                        hh::font::game::glyph_left_bearing(static_cast<unsigned char>(cp));
                    if (bearing >= 0) {
                        x_text += static_cast<float>(1 - bearing);
                    }
                }
                break;
            }
        }
        if (text.find('/') != std::string::npos) {
            append_text_with_slashes(frame, x_text, y, color, text);
        } else {
            frame.texts.push_back({ x_text, y, g_scale_x, g_scale_y, color, text });
        }

        // Selector lateral: el valor ACTIVO en verde y el resto en gris; izq/der lo cambia.
        //   - Pocas opciones (SÍ/NO, ...): todos los valores juntos en columna fija (NO/SI).
        //   - Muchas (RESOLUCIÓN, LÍMITE DE FPS): solo el activo, con flechas < > dibujadas.
        if (e.kind == hh::menu::Kind::Selector && !e.options.empty()) {
            const float step = 8.0f * g_scale_x;
            // Todos los valores empiezan en la MISMA columna (`selector_col`; nativa o de EXTRAS);
            // los chevrons < > quedan a la izquierda/derecha (fuera de la alineación).
            const float value_x = x + selector_col * step;
            constexpr float kSlashSep = 2.0f;   // hueco a cada lado de la barra
            constexpr float kSlashW = 5.0f;
            constexpr float kChevW = 2.0f;
            constexpr float kChevGap = 4.0f;
            float width = 0.0f;
            for (size_t oi = 0; oi < e.options.size(); ++oi) {
                width += static_cast<float>(cp_count(hh::menu::localized(e.options[oi]))) * step;
                if (oi + 1 < e.options.size()) width += 2.0f * kSlashSep + kSlashW;
            }
            // `e.stepper` fuerza el estilo < valor > aunque todas las opciones quepan (ANTIALIASING).
            const bool fits = !e.stepper && value_x + width <= hh::overlay::kVirtualWidth - 4.0f;
            if (fits) {
                float ox = value_x;
                for (size_t oi = 0; oi < e.options.size(); ++oi) {
                    if (oi != 0) {
                        ox += kSlashSep;
                        append_slash(frame, ox, y + 1.0f, kWhite);   // separador entre opciones en blanco
                        ox += kSlashW + kSlashSep;
                    }
                    const std::string opt = hh::menu::localized(e.options[oi]);
                    // Entrada deshabilitada: TODO en gris (no solo la etiqueta); el valor activo
                    // no se resalta en verde.
                    const uint32_t oc = !e.enabled
                                            ? kGray
                                            : ((static_cast<int>(oi) == e.value) ? kGreen : kGray);
                    frame.texts.push_back({ ox, y, g_scale_x, g_scale_y, oc, opt });
                    ox += static_cast<float>(cp_count(opt)) * step;
                }
            } else {
                // Selector largo: solo el activo, alineado en la misma columna; el chevron izquierdo
                // va a su izquierda y el derecho a 4 px del valor.
                // Guarda defensiva: un valor fuera de rango (opcionalmente por un indice mal puesto)
                // leia fuera de `options` y podia colgar; se acota.
                const size_t vi = (e.value >= 0 && e.value < static_cast<int>(e.options.size()))
                                      ? static_cast<size_t>(e.value)
                                      : 0u;
                const std::string opt = hh::menu::localized(e.options[vi]);
                // Entrada deshabilitada: valor y chevrons en gris (consistente con la etiqueta).
                const uint32_t vc = e.enabled ? kGreen : kGray;
                const uint32_t cc = e.enabled ? kWhite : kGray;
                append_chevron(frame, value_x - (kChevW + kChevGap), y + 1.0f, true, cc);
                frame.texts.push_back({ value_x, y, g_scale_x, g_scale_y, vc, opt });
                append_chevron(frame, value_x + static_cast<float>(cp_count(opt)) * step + kChevGap,
                               y + 1.0f, false, cc);
            }
        }

        // Fila numérica (EDICIÓN DE PARTIDA): < valor > en verde, con chevrons dibujados.
        if (e.kind == hh::menu::Kind::Number) {
            const float step = 8.0f * g_scale_x;
            const float value_x = x + selector_col * step;
            constexpr float kChevW = 2.0f;
            constexpr float kChevGap = 4.0f;
            // Número con ancho FIJO (3 cifras, con hueco para el signo): el grupo `< NIVEL n >` no se
            // mueve aunque el nivel tenga 1/2 dígitos, así no descuadra el resto de la fila.
            std::string num = std::to_string(e.value);
            while (num.size() < 3) num.insert(num.begin(), ' ');
            const std::string opt = e.prefix + num;
            const uint32_t vc = e.enabled ? kGreen : kGray;
            const uint32_t cc = e.enabled ? kWhite : kGray;
            append_chevron(frame, value_x - (kChevW + kChevGap), y + 1.0f, true, cc);
            frame.texts.push_back({ value_x, y, g_scale_x, g_scale_y, vc, opt });
            const float chev_r = value_x + static_cast<float>(cp_count(opt)) * step + kChevGap;
            append_chevron(frame, chev_r, y + 1.0f, false, cc);
            // Valor del stat en COLUMNA FIJA (independiente del chevron): los dígitos cuadran aunque
            // el valor tenga 1/2/3/4 cifras. `suffix` ya viene rellenado a la izquierda en menu.cpp.
            if (!e.suffix.empty()) {
                frame.texts.push_back({ x + (selector_col + 12.0f) * step, y, g_scale_x, g_scale_y,
                                        kWhite, e.suffix });
            }
        }
        // Toggle (HABILIDADES): valor NO/SÍ a la derecha (verde si activo), alineado con la columna.
        if (e.kind == hh::menu::Kind::Toggle) {
            const float step = 8.0f * g_scale_x;
            const float value_x = x + selector_col * step;
            frame.texts.push_back({ value_x, y, g_scale_x, g_scale_y, e.marked ? kGreen : kGray,
                                    hh::menu::localized(e.marked ? "SÍ" : "NO") });
        }

        // Fila de mapeado (CONTROLES): el binding actual a la derecha, alineado con los selectores.
        // Si esa fila esta en captura, se muestra el aviso "PULSA..." en amarillo.
        // Fila de mapeado (CONTROLES): DOS columnas, MANDO y TECLADO (un binding cada una).
        if (e.kind == hh::menu::Kind::Binding) {
            const float step = 8.0f * g_scale_x;
            const bool capturing =
                hh::pad_capture_active() && (hh::pad_capture_action() == e.remap_key);
            if (capturing) {
                frame.texts.push_back({ x + selector_col * step, y, g_scale_x, g_scale_y, kYellow,
                                        hh::menu::localized("PULSA...") });
            } else {
                const float gp_x = x + selector_col * step;
                const float kb_x = x + key_col * step;
                frame.texts.push_back({ gp_x, y, g_scale_x, g_scale_y, kWhite,
                                        hh::pad_binding_gamepad(e.remap_key) });
                frame.texts.push_back({ kb_x, y, g_scale_x, g_scale_y, kWhite,
                                        hh::pad_binding_key(e.remap_key) });
            }
        }

        if (selected) {
            append_native_cursor(frame, x + 1.0f, y + 1.0f, kWhite);
        }
    }

    // Indicadores de scroll: arriba si hay filas por encima de la ventana, abajo si quedan por
    // debajo. Desaparecen al llegar al tope (o al final). Solo en pantallas con scroll.
    if (n_entries > max_visible) {
        // Alineadas con el inicio de las palabras (las etiquetas llevan 1 espacio de sangria).
        const float arrow_x = layout.x + g_calib_x + x_shift + 8.0f * g_scale_x;
        if (first > 0) {
            append_scroll_arrow(frame, arrow_x, list_y0 - 7.0f, true, kWhite);
        }
        if (first + max_visible < n_entries) {
            const float ay = list_y0 + layout.dy * static_cast<float>(max_visible) + 1.0f;
            append_scroll_arrow(frame, arrow_x, ay, false, kWhite);
        }
    }

    if (trace) {
        static int last_screen = -1, last_entries = -1, last_xshift = -9999;
        const int xs = static_cast<int>(x_shift);
        if (static_cast<int>(screen.id) != last_screen ||
            static_cast<int>(screen.entries.size()) != last_entries || xs != last_xshift) {
            last_screen = static_cast<int>(screen.id);
            last_entries = static_cast<int>(screen.entries.size());
            last_xshift = xs;
            hh::log("[overlay] screen=%d kind=%d entries=%zu x_shift=%d\n", last_screen,
                    static_cast<int>(screen.kind), screen.entries.size(), xs);
        }
    }

    g_publish_counter.fetch_add(1, std::memory_order_relaxed);
    hh::overlay::publish(std::move(frame));
}

// Hilo del JUEGO: oculta el overlay YA. Se llama desde `hh_goto_hook` (transición de pantalla,
// func_800058DC): al seleccionar una opción el handler nativo cambia de pantalla pero puede seguir
// publicando nuestro frame (el de la raíz) durante la transición; ocultarlo aquí lo hace instantáneo
// en vez de esperar al debounce de `tick`. Si la nueva pantalla sigue siendo la raíz, el handler
// vuelve a publicar en el frame siguiente y el overlay reaparece.
void hide_now() {
    hh::overlay::publish(hh::overlay::Frame{});
}

// Render thread: si el menú de título dejó de publicar (salimos de él), oculta el overlay. El
// umbral es de TIEMPO (no de ticks): `tick` corre a una tasa que no controlamos (ScreenUpdateAction,
// ~30-110 Hz) y contar 30 ticks daba ~1 s de retardo al salir del menú (bug 2026-09-24). Con 150 ms
// desaparece "al momento" sin parpadear. Ajustable: HH_MENU_STALE_MS=<ms>.
void tick() {
    using clock = std::chrono::steady_clock;
    static const int stale_ms = [] {
        const char* e = std::getenv("HH_MENU_STALE_MS");
        return (e != nullptr && *e != '\0') ? std::atoi(e) : 150;
    }();
    static uint64_t last_counter = 0;
    static clock::time_point last_publish = clock::now();
    static bool hidden = false;
    const uint64_t counter = g_publish_counter.load(std::memory_order_relaxed);
    const clock::time_point now = clock::now();
    if (counter != last_counter) {
        last_counter = counter;
        last_publish = now;
        hidden = false;
        return;
    }
    if (hidden) {
        return;
    }
    const long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_publish).count();
    if (elapsed >= stale_ms) {
        hidden = true;
        static const bool trace = [] {
            const char* e = std::getenv("HH_MENU_TRACE");
            return e != nullptr && *e != '\0' && *e != '0';
        }();
        if (trace) {
            hh::log("[overlay] ocultar: %ld ms sin publicar (limite %d)\n", elapsed, stale_ms);
        }
        hh::overlay::publish(hh::overlay::Frame{});
    }
}

}  // namespace hh::menu_overlay
