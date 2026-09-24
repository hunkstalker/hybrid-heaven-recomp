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
};
constexpr unsigned kNativeBackupSize = 3 * kNativeLabelsLen + 16;

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

constexpr uint32_t kWhite = hh::overlay::rgba(255, 255, 255, 255);
constexpr uint32_t kYellow = hh::overlay::rgba(255, 220, 64, 255);
constexpr uint32_t kGreen = hh::overlay::rgba(96, 255, 96, 255);
// Gris de opción no seleccionada/deshabilitada (el original "sombrea" lo que no está activo).
constexpr uint32_t kGray = hh::overlay::rgba(130, 130, 130, 255);

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

std::string to_ascii(const std::string& s) {
    std::string out;
    out.reserve(s.size());
    size_t i = 0;
    while (i < s.size()) {
        out.push_back(ascii_fold(utf8_next(s, i)));
    }
    return out;
}

// --- Flecha nativa de cursor ---------------------------------------------------------------------
// Medida del menú original (captura 2560x1440): triángulo que apunta a la derecha, 6x5 px virtuales,
// pegado al inicio de la línea (ocupa el espacio inicial de la etiqueta). Se compone con rectángulos
// (la prohibición de "paneles" es para fondos/barras inventados, no para la flecha del juego).
void append_native_cursor(hh::overlay::Frame& frame, float x, float y, uint32_t color) {
    static const uint8_t kWidths[5] = { 2, 4, 6, 4, 2 };
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

// Flecha "<" / ">" (chevron 5x5) de los selectores largos, con rectángulos de 2 px. `left` elige la
// orientación; la punta cae en la fila central.
void append_chevron(hh::overlay::Frame& frame, float x, float y, bool left, uint32_t color) {
    static const uint8_t kOff[5] = { 2, 1, 0, 1, 2 };   // distancia a la punta (fila central)
    for (int row = 0; row < 5; ++row) {
        const float ox = left ? static_cast<float>(kOff[row]) : static_cast<float>(2 - kOff[row]);
        frame.panels.push_back({ x + ox, y + static_cast<float>(row), 2.0f, 1.0f, color });
    }
}

}  // namespace

bool visible() { return g_visible; }

// Menú nativo del juego (F6). Por defecto oculto; al mostrarlo se restauran sus etiquetas.
bool native_visible() { return g_native_visible; }
void native_toggle() { g_native_visible = !g_native_visible; }

// true UNA vez cada vez que F6 cambia la visibilidad (para forzar el re-registro del menú nativo).
bool native_toggle_pending() {
    if (g_native_visible != g_native_last_reported) {
        g_native_last_reported = g_native_visible;
        return true;
    }
    return false;
}

// Oculta (o restaura) el texto del menú nativo en RDRAM: rellena con espacios (o repone el original)
// las etiquetas idx0..5 y la flecha que el handler registra cada frame. El juego compone el texto
// una sola vez por entrada (func_801C18FC), así que además hay que re-ejecutarlo al alternar (F6).
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

// La COMPOSICIÓN del menú nativo (0x8001B204) lee el texto de las direcciones de enlace y lo copia
// a su estructura interna. Si el menú está oculto, se meten espacios en el campo justo antes de que
// lo lea: así el texto compuesto ya sale en blanco desde el primer frame (sin depender de cuándo se
// ejecute el registro). Se llama desde el hook de 0x8001B204.
void filter_native_text(uint8_t* rdram, uint32_t text_addr) {
    if (rdram == nullptr || g_native_visible) {
        return;
    }
    bool in_labels = false;
    for (uint32_t base : kNativeLabelAddrs) {
        if (text_addr >= base && text_addr < base + kNativeLabelsLen) {
            in_labels = true;
            break;
        }
    }
    const bool is_arrow = text_addr == kNativeArrowAddr;
    if (!in_labels && !is_arrow) {
        return;
    }
    static bool logged = false;
    if (!logged) {
        logged = true;
        hh::log("[native] filter first text=%08X\n", text_addr);
    }
    for (unsigned i = 0; i < 16; ++i) {
        rdram[((text_addr + i) - 0x80000000u) ^ 3u] = (i == 15u) ? 0x00u : 0x20u;
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

    hh::overlay::Frame frame;
    frame.visible = true;

    for (size_t i = 0; i < screen.entries.size(); ++i) {
        const hh::menu::Entry& e = screen.entries[i];
        const float x = layout.x + g_calib_x;
        const float y = layout.y0 + kTextTopOffset + layout.dy * static_cast<float>(i) + g_calib_y;
        const bool selected = (static_cast<int>(i) == screen.cursor);

        // Las ETIQUETAS del menú van en blanco (amarillo la del cursor + flecha nativa). La regla
        // gris/verde es SOLO para las opciones a configurar: en una lista, la aplicada en verde y el
        // resto en gris; en un selector, el valor activo en verde y el resto en gris (abajo).
        uint32_t color = kWhite;
        if (screen.kind == hh::menu::ScreenKind::List) {
            color = e.marked ? kGreen : kGray;
        } else if (selected) {
            color = kYellow;
        }
        // Sangría nativa: las etiquetas del motor llevan un espacio inicial (donde va la flecha).
        const std::string text = " " + to_ascii(e.label);
        // Alineación del primer glifo: la fuente no es uniforme (M/O/V/W/X/Z empiezan en la columna 0
        // y el resto en la 1), así que una línea que empiece por 'M' saldría 1 px a la izquierda del
        // resto (p. ej. "MODO COMBATE"). El menú nativo solo usa inicios de columna 1, por eso se ve
        // uniforme; compensamos el primer carácter a esa columna de referencia (1) para igualarlo.
        float x_text = x;
        for (char c : text) {
            if (c == ' ') continue;
            const int bearing = hh::font::game::glyph_left_bearing(static_cast<unsigned char>(c));
            if (bearing >= 0) {
                x_text += static_cast<float>(1 - bearing);
            }
            break;
        }
        frame.texts.push_back({ x_text, y, g_scale_x, g_scale_y, color, text });

        // Selector lateral: el valor ACTIVO en verde y el resto en gris; izq/der lo cambia.
        //   - Pocas opciones (SÍ/NO, ...): todos los valores juntos en columna fija (NO/SI).
        //   - Muchas (RESOLUCIÓN, LÍMITE DE FPS): solo el activo, con flechas < > dibujadas.
        if (e.kind == hh::menu::Kind::Selector && !e.options.empty()) {
            const float step = 8.0f * g_scale_x;
            // Todos los valores empiezan en la MISMA columna (`kSelectorValueCol`); los chevrons < >
            // quedan a la izquierda/derecha (fuera de la alineación).
            const float value_x = x + kSelectorValueCol * step;
            constexpr float kSlashSep = 2.0f;   // hueco a cada lado de la barra
            constexpr float kSlashW = 5.0f;
            constexpr float kChevW = 2.0f;
            constexpr float kChevGap = 4.0f;
            float width = 0.0f;
            for (size_t oi = 0; oi < e.options.size(); ++oi) {
                width += static_cast<float>(to_ascii(e.options[oi]).size()) * step;
                if (oi + 1 < e.options.size()) width += 2.0f * kSlashSep + kSlashW;
            }
            const bool fits = value_x + width <= hh::overlay::kVirtualWidth - 4.0f;
            if (fits) {
                float ox = value_x;
                for (size_t oi = 0; oi < e.options.size(); ++oi) {
                    if (oi != 0) {
                        ox += kSlashSep;
                        append_slash(frame, ox, y + 1.0f, kGray);
                        ox += kSlashW + kSlashSep;
                    }
                    const std::string opt = to_ascii(e.options[oi]);
                    const uint32_t oc = (static_cast<int>(oi) == e.value) ? kGreen : kGray;
                    frame.texts.push_back({ ox, y, g_scale_x, g_scale_y, oc, opt });
                    ox += static_cast<float>(opt.size()) * step;
                }
            } else {
                // Selector largo: solo el activo, alineado en la misma columna; el chevron izquierdo
                // va a su izquierda y el derecho a 4 px del valor.
                const std::string opt = to_ascii(e.options[static_cast<size_t>(e.value)]);
                append_chevron(frame, value_x - (kChevW + kChevGap), y + 1.0f, true, kWhite);
                frame.texts.push_back({ value_x, y, g_scale_x, g_scale_y, kGreen, opt });
                append_chevron(frame, value_x + static_cast<float>(opt.size()) * step + kChevGap,
                               y + 1.0f, false, kWhite);
            }
        }

        if (selected) {
            append_native_cursor(frame, x + 1.0f, y + 1.0f, kWhite);
        }
    }

    if (trace && !traced) {
        hh::log("[overlay] screen=%d kind=%d entries=%zu\n", static_cast<int>(screen.id),
                static_cast<int>(screen.kind), screen.entries.size());
        traced = true;
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
