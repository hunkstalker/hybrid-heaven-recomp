// Reescritor del HUD 2D para widescreen. Adaptado del port de referencia (MIT; ver CREDITS.md y
// licenses/hybrid-heaven-recomp-MIT.txt), `src/hudrewrite.cpp` (Phase 07). Ver RETOMAR.md y
// include/hh/hudrewrite.h.
//
// Copia la lista de comandos a un scratch de RDRAM (dos buffers alternos por frame, porque el frame
// anterior puede seguir en vuelo) e inserta GBI extendido de RT64 alrededor de cada elemento 2D
// clasificado. El frontend envia la copia en vez de la lista del juego.

#include "hh.h"
#include "hh/hudrewrite.h"
#include "hh/hudid.h"

#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

#define F3DEX_GBI_2
#include "rt64_extended_gbi.h"

namespace hh::hudrewrite {
namespace {

// Dos buffers scratch, alternos por frame, entre el final de las reservas del juego y el limite
// fisico. El juego solo usa los primeros ~4 MB (osGetMemSize con el fix de 4 MB, ADR 0002); el
// volcado de RDRAM confirma que 0x7A0000..0x7F0000 queda a cero. 20.000 comandos por buffer.
constexpr uint32_t kScratch[2] = { 0x007A0000u, 0x007C8000u };
constexpr uint32_t kScratchSize = 0x28000u;

// Compensacion fina (cuartos de pixel) del anclaje a la derecha por rect. 4 = +1 px. 0 = sin nudge.
constexpr int kRightRectNudge = 0;

// Recorte del scissor del mapa en px de juego por lado (0 = desactivado). RT64 coloca el fondo
// (un rect) y el contenido (triangulos) del mapa con un desajuste sub-pixel (<1 px), de modo que uno
// sobresale del otro. El borde VISIBLE tiene que ser el del scissor: si ambos comparten UN mismo
// scissor —el panel canonico, capturado del primer elemento `right`— y ese scissor se recorta por
// sus dos bordes, fondo y contenido terminan exactamente en la misma linea. Un unico valor, no dos
// recortes independientes (dos recortes no coinciden porque RT64 los resuelve por su cuenta).
constexpr int kMapCrop = 1;

// Recorte del mapa en px, ajustable EN CALIENTE con las teclas `+`/`-` del teclado numerico
// (y con `HH_MAP_CROP=<px>` al arrancar; default kMapCrop). Lo lee el hilo de render en cada lista.
std::atomic<int> g_map_crop{ [] {
    const char* v = std::getenv("HH_MAP_CROP");
    return (v != nullptr && *v != '\0') ? std::atoi(v) : kMapCrop;
}() };

int map_crop_q() {
    return g_map_crop.load(std::memory_order_relaxed) * 4;
}

// Ajuste fino del FONDO negro del mapa (independiente del contenido), para cuadrarlo con el mapa
// verde cuando el rect del juego no cubre el panel exacto. Se leen en cada lista, sin recompilar.
//   HH_MAP_BG_CROP=<px>  : recorta el fondo por cada lado (reduce el ancho/alto).
//   HH_MAP_BG_SHIFT=<px> : desplaza el fondo en horizontal (+ = a la derecha) para moverlo.
std::atomic<int> g_map_bg_crop{ [] {
    const char* v = std::getenv("HH_MAP_BG_CROP");
    return (v != nullptr && *v != '\0') ? std::atoi(v) : 0;
}() };
std::atomic<int> g_map_bg_shift{ [] {
    const char* v = std::getenv("HH_MAP_BG_SHIFT");
    return (v != nullptr && *v != '\0') ? std::atoi(v) : 0;
}() };

// F3DEX2.
constexpr uint8_t kMtx = 0xDA, kMoveWord = 0xDB, kMoveMem = 0xDC, kDl = 0xDE, kEndDl = 0xDF;
constexpr uint8_t kTexRect = 0xE4, kTexRectFlip = 0xE5, kRdpHalf1 = 0xE1, kRdpHalf2 = 0xF1;
constexpr uint8_t kSetScissor = 0xED, kSetFillColor = 0xF7, kSetTImg = 0xFD, kSetCImg = 0xFF;
constexpr uint8_t kFillRect = 0xF6, kSetCombine = 0xFC;
constexpr uint8_t kMwSegment = 0x06, kMvViewport = 0x08, kMtxProjection = 0x04;

// Vertex (`G_VTX`): carga `count` vertices desde el segmento `seg`/offset `w1` al slot `v0`.
//   w0 = 0x01 | (count<<12) | (v0<<1). w1 = direccion segmentada de la lista de vertices.
// Quad: 2 triangulos → 2x G_TRI1, opcode F3DEX2 = 0x05 (NO 0xBF: ese es el G_TRI1 de F3D, y en el
// mapa de F3DEX2 de RT64 un opcode sin entrada se DESCARTA en silencio; ver rt64_interpreter.cpp).
//   w0 = 0x05<<24 | (idx0<<17) | (idx1<<9) | (idx2<<1). RT64 lo decodifica exactamente igual:
//   drawIndexedTri(p0(17,7), p0(9,7), p0(1,7)).
constexpr uint8_t kVtx = 0x01, kTri1 = 0x05;

// HH_HUD_SITES_TRACE=1: cada identidad clasificada `right`, una vez, con su sitio exacto de dibujo
// (coordenadas del rect / del scissor), para averiguar si el contenido verde del mapa cae o no
// dentro del panel que se recorta.
void trace_site(const std::string& identity, const char* what, int ulx, int uly, int lrx, int lry) {
    static const bool on = std::getenv("HH_HUD_SITES_TRACE") != nullptr;
    if (!on) return;
    static std::vector<std::string> seen;
    for (const auto& s : seen) {
        if (s == identity) return;
    }
    if (seen.size() > 2000) return;
    seen.push_back(identity);
    hh::log("[hh-site] %s %s @ %d,%d..%d,%d (320x240)\n", what, identity.c_str(), ulx, uly, lrx, lry);
}

// HH_HUD_REWRITE_TRACE=1: cada identidad que ve el reescritor, una vez, con su clase y donde.
void trace_seen(const std::string& identity, const char* where, int cls) {
    static const bool on = std::getenv("HH_HUD_REWRITE_TRACE") != nullptr;
    if (!on) return;
    static std::vector<std::string> seen;
    for (const auto& s : seen) {
        if (s == identity) return;
    }
    if (seen.size() > 4000) return;
    seen.push_back(identity);
    hh::log("[hh-hud] %s %s class %d\n", where, identity.c_str(), cls);
}

struct Writer {
    uint8_t* rdram;
    uint32_t base, size;
    uint32_t used = 0;
    bool overflow = false;

    uint32_t segments[16] = {};
    uint32_t fb_width = 320;
    bool have_viewport = false, have_scissor = false, have_projection = false;
    uint32_t viewport_w0 = 0, viewport_w1 = 0, scissor_w0 = 0, scissor_w1 = 0;
    uint32_t projection_w0 = 0, projection_w1 = 0;
    uint32_t image = 0, fill_colour = 0;
    uint32_t combine_w0 = 0, combine_w1 = 0;   // ultimo G_SETCOMBINE visto (para restaurar)
    bool have_combine = false;
    std::string texture_ident;
    int applied = 0;

    // Panel canonico del mapa (`right`): se fija UNA vez por frame (el primer elemento `right` que
    // aparezca) y se reutiliza tal cual (mismo w0/w1) para el fondo y el contenido, de modo que RT64
    // resuelva UN solo scissor. Estados de `panel_done`:
    //   0 = aun no se ha fijado; 1 = fijado por el scissor vigente (contenido); 2 = fijado por un
    //   rect (fallback, si el contenido no aparecio antes con scissor de panel).
    bool have_map_panel = false;
    int panel_done = 0;
    uint32_t map_panel_w0 = 0, map_panel_w1 = 0;
    // Viewport del contenido del mapa, capturado junto al panel. El fondo (que va despues) tiene
    // otro viewport vigente (basura), asi que el quad de fondo debe reemitir ESTE viewport: RT64
    // coloca los triangulos por el viewport, no por el scissor.
    bool have_map_vport = false;
    uint32_t map_vport_w0 = 0, map_vport_w1 = 0;
    uint32_t physical(uint32_t address) const {
        if ((address >> 24) >= 0x80) return address & 0x1FFFFFFF;
        return (segments[(address >> 24) & 0x0F] + (address & 0x00FFFFFF)) & 0x1FFFFFFF;
    }

    static constexpr uint32_t kVtxBytes = 0x200;
    uint32_t limit() const { return size - kVtxBytes; }

    GfxCommand* reserve(uint32_t count) {
        if (used + 8 * count > limit()) {
            overflow = true;
            return nullptr;
        }
        GfxCommand* cmd = reinterpret_cast<GfxCommand*>(rdram + base + used);
        used += 8 * count;
        return cmd;
    }
    void emit(uint32_t w0, uint32_t w1) {
        if (GfxCommand* cmd = reserve(1)) {
            cmd->values.word0 = w0;
            cmd->values.word1 = w1;
        }
    }
    void enable() {
        if (GfxCommand* cmd = reserve(1)) gEXEnable(cmd);
    }

    // RT64 desplaza una coordenada anclada en origin/1024 del ancho del framebuffer, en cuartos de
    // pixel; esto lo cancela, para que los numeros del juego se midan desde el borde elegido.
    int origin_cancel(uint32_t origin) const {
        return -static_cast<int>((origin * fb_width * 4) / G_EX_ORIGIN_RIGHT);
    }

    // Emite G_EX_SETSCISSOR_V1 con coordenadas en CUARTOS de pixel (formato 10.2 crudo, igual que el
    // campo del G_SETSCISSOR del juego). No se usa gEXSetScissor porque multiplica por 4 y solo admite
    // pixeles enteros; aqui hacen falta recortes/desfases sub-pixel.
    void emit_scissor_q(uint8_t mode, uint32_t lo, uint32_t ro, int ulx, int uly, int lrx, int lry) {
        if (GfxCommand* cmd = reserve(2)) {
            cmd[0].values.word0 = (static_cast<uint32_t>(RT64_EXTENDED_OPCODE) << 24) |
                                  static_cast<uint32_t>(G_EX_SETSCISSOR_V1);
            cmd[0].values.word1 = static_cast<uint32_t>(mode) | (lo << 2) | (ro << 14);
            cmd[1].values.word0 = (static_cast<uint32_t>(ulx & 0xFFFF) << 16) |
                                  (static_cast<uint32_t>(uly) & 0xFFFF);
            cmd[1].values.word1 = (static_cast<uint32_t>(lrx & 0xFFFF) << 16) |
                                  (static_cast<uint32_t>(lry) & 0xFFFF);
        }
    }

    // Scissor de `w0`/`w1` anclado a la clase, con recorte uniforme `crop_q` (cuartos de pixel) por
    // lado. El mapa usa SIEMPRE el mismo panel canonico (`map_panel_w0/w1`) y el mismo recorte, de
    // modo que el fondo y el contenido comparten un unico borde visible. `crop_q = 0` = sin recorte.
    // Se usa para reensanchar en `widen_scissor` (con el scissor vigente) y para anclar los rects y
    // los `G_SETSCISSOR` que aparezcan DENTRO de un grupo clasificado (si no, el contenido `dl` del
    // mapa reinicia el scissor a los valores del juego y se libra del recorte).
    void anchored_scissor(int cls, uint32_t w0, uint32_t w1, int crop_q = 0) {
        const uint8_t mode = static_cast<uint8_t>((w1 >> 24) & 3);
        const int ulx = static_cast<int>((w0 >> 12) & 0xFFF);   // ya en cuartos de pixel
        const int uly = static_cast<int>(w0 & 0xFFF);
        const int lrx = static_cast<int>((w1 >> 12) & 0xFFF);
        const int lry = static_cast<int>(w1 & 0xFFF);
        const int fbq = static_cast<int>(fb_width) * 4;
        uint32_t lo = G_EX_ORIGIN_LEFT, ro = G_EX_ORIGIN_RIGHT;
        int ulx_out = ulx, lrx_out = lrx - fbq;
        int uly_out = uly, lry_out = lry;
        if (cls == kLeft) {
            lo = ro = G_EX_ORIGIN_LEFT;
            ulx_out = ulx + crop_q;
            lrx_out = lrx - crop_q;
        }
        else if (cls == kRight) {
            lo = ro = G_EX_ORIGIN_RIGHT;
            // Recorte hacia dentro por ambos bordes. Con origen derecho, mas positivo = mas a la
            // derecha: sumar al borde izquierdo y restar al derecho los acerca. Vertical: arriba
            // suma y abajo resta (el origen solo afecta al eje horizontal).
            ulx_out = ulx - fbq + crop_q;
            lrx_out = lrx - fbq - crop_q;
        }
        if (cls == kLeft || cls == kRight) {
            uly_out = uly + crop_q;
            lry_out = lry - crop_q;
        }
        // HH_HUD_SCISSOR_TRACE=1: cada recorte distinto, una vez, con su clase y coords en px.
        static const bool trace = std::getenv("HH_HUD_SCISSOR_TRACE") != nullptr;
        if (trace) {
            static std::vector<std::string> seen;
            char key[160];
            std::snprintf(key, sizeof key, "c%d %.2f,%.2f..%.2f,%.2f -> %.2f,%.2f..%.2f,%.2f", cls,
                          ulx / 4.0f, uly / 4.0f, lrx / 4.0f, lry / 4.0f,
                          ulx_out / 4.0f, uly_out / 4.0f, lrx_out / 4.0f, lry_out / 4.0f);
            bool dup = false;
            for (const auto& s : seen) if (s == key) { dup = true; break; }
            if (!dup && seen.size() < 200) {
                seen.push_back(key);
                hh::log("[hh-scissor] %s\n", key);
            }
        }
        emit_scissor_q(mode, lo, ro, ulx_out, uly_out, lrx_out, lry_out);
    }

    // Scissor para un elemento clasificado. Para `left`/`right` se ancla AMBOS bordes al origen del
    // elemento, con los numeros del juego relativos a ese borde: el scissor se MUEVE con el elemento
    // conservando su tamano. Esto es clave para un panel pequeno (el mapa: 197,143..277,223) cuya
    // "mascara" recorta el contenido: si se ensancha (lo que hacia la referencia), el contenido deja
    // de estar recortado y se sale del fondo (issues #2/#4 de la referencia). Para un scissor de
    // overscan (0,0..320,240 tras el snap) sale el frame completo, igual que antes. `spill` si
    // ensancha (bordes LEFT/RIGHT), que es su proposito.
    void widen_scissor(int cls) {
        if (!have_scissor) return;
        anchored_scissor(cls, scissor_w0, scissor_w1);
    }

    // Diagnostico (HH_HUD_SCISSOR_TRACE=1): identidad/clase de cada elemento clasificado y el
    // scissor vigente al empezarlo (una vez por identidad).
    void trace_elem(const std::string& id, int cls) {
        static const bool on = std::getenv("HH_HUD_SCISSOR_TRACE") != nullptr;
        if (!on || cls == kAuto) return;
        static std::vector<std::string> seen;
        if (seen.size() > 200) return;
        for (const auto& s : seen) if (s == id) return;
        seen.push_back(id);
        int ulx = 0, uly = 0, lrx = 0, lry = 0;
        if (have_scissor) {
            ulx = static_cast<int>((scissor_w0 >> 12) & 0xFFF) >> 2;
            uly = static_cast<int>(scissor_w0 & 0xFFF) >> 2;
            lrx = static_cast<int>((scissor_w1 >> 12) & 0xFFF) >> 2;
            lry = static_cast<int>(scissor_w1 & 0xFFF) >> 2;
        }
        hh::log("[hh-map] %s cls=%d have=%d scissor=%d,%d..%d,%d\n", id.c_str(), cls,
                have_scissor ? 1 : 0, ulx, uly, lrx, lry);
    }

    // Diagnostico (HH_HUD_DRAWS_TRACE=1): cada vez que un grupo `right` se dibuja, imprime su
    // viewport y su scissor en pixeles 320x240, y las dos palabras crudas. Sirve para saber QUE
    // dibuja cada identidad clasificada (mapa verde, flecha roja, marco...) y con que caja sale.
    void trace_draw(const std::string& id, const char* kind) {
        static const bool on = std::getenv("HH_HUD_DRAWS_TRACE") != nullptr;
        if (!on || id.empty()) return;
        static std::vector<std::string> seen;
        if (seen.size() > 400) return;
        std::string key = id + kind;
        for (const auto& s : seen) if (s == key) return;
        seen.push_back(key);
        auto px = [](uint32_t w, int shift) { return static_cast<int>((w >> shift) & 0xFFF) >> 2; };
        hh::log("[hh-draw] %-9s %s vp=%d,%d..%d,%d (%08x %08x) sc=%d,%d..%d,%d\n",
                kind, id.c_str(),
                have_viewport ? px(viewport_w0, 12) : -1, have_viewport ? px(viewport_w0, 0) : -1,
                have_viewport ? px(viewport_w1, 12) : -1, have_viewport ? px(viewport_w1, 0) : -1,
                viewport_w0, viewport_w1,
                have_scissor ? px(scissor_w0, 12) : -1, have_scissor ? px(scissor_w0, 0) : -1,
                have_scissor ? px(scissor_w1, 12) : -1, have_scissor ? px(scissor_w1, 0) : -1);
    }
    void restore_scissor() {
        if (have_scissor) emit(scissor_w0, scissor_w1);
    }

    void projection_group(uint32_t aspect) {
        if (GfxCommand* cmd = reserve(2)) {
            gEXMatrixGroup(cmd, G_EX_ID_AUTO, G_EX_INTERPOLATE_SIMPLE, G_EX_NOPUSH, 1,
                           G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP,
                           G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP,
                           G_EX_COMPONENT_SKIP, G_EX_ORDER_AUTO, G_EX_EDIT_NONE, aspect,
                           G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP);
        }
        if (have_projection) emit(projection_w0, projection_w1);
    }

    void viewport_align(uint32_t origin, int offset) {
        if (GfxCommand* cmd = reserve(2)) gEXSetViewportAlign(cmd, origin, offset, 0);
        if (have_viewport) emit(viewport_w0, viewport_w1);
    }

    // El fondo del mapa (un G_FILLRECT) y su contenido (triangulos) pasan por caminos DISTINTOS de
    // RT64. La proyeccion Orthographic de los triangulos aplica `horizontalMisalignment` a su
    // scissor/viewport; la proyeccion Rectangle del rect NO lo aplica (y ademas cuantiza con
    // truncado en vez de fmod). Resultado: el mismo scissor del panel recorta el fondo y el
    // contenido en lineas distintas, por mucho que compartan los numeros.
    //
    // El fondo se deja como rect (el G_FILLRECT original, anclado al panel canonico). El alineado
    // exacto rect<->triangulos lo hacen los parches de RT64 en `lib/rt64`:
    //   - tools/patch_rt64_2d_misalignment.py: los triangulos ortograficos reciben el mismo
    //     `horizontalMisalignment` que los rects;
    //   - tools/patch_rt64_misalignment.py: redondeo hacia arriba con origen derecho (rt64#82);
    //   - tools/patch_rt64_scissor_quant.py: cuantiza el scissor de triangulos igual que el de rects.
    // (La via de pintar el fondo como quad se descarto: el contenido del mapa no es 2D en pixeles
    //  sino geometria en espacio de mapa, asi que un quad en px del panel no comparte su matriz.)

    // Emite un G_FILLRECT EXTENDIDO (G_EX_FILLRECT_V1) con coordenadas en cuartos de pixel y
    // origen por borde. Necesario para el fondo del mapa: el G_FILLRECT nativo lee sus campos como
    // 12 bits SIN signo (`p1(12,12)`), asi que una coordenada relativa al origen derecho (negativa,
    // p. ej. -488) se interpretaria como 3608 y el rect caeria fuera de pantalla. El comando
    // extendido las lee como `int16_t` (ver `fillrectV1` en rt64_gbi_extended.cpp).
    void emit_fill_rect_ext(uint16_t lorigin, uint16_t rorigin, int ulx, int uly, int lrx, int lry) {
        if (GfxCommand* cmd = reserve(2)) {
            cmd[0].values.word0 = (static_cast<uint32_t>(RT64_EXTENDED_OPCODE) << 24) |
                                  static_cast<uint32_t>(G_EX_FILLRECT_V1);
            cmd[0].values.word1 = static_cast<uint32_t>(lorigin) |
                                  (static_cast<uint32_t>(rorigin) << 12);
            cmd[1].values.word0 = (static_cast<uint32_t>(ulx & 0xFFFF) << 16) |
                                  static_cast<uint32_t>(uly & 0xFFFF);
            cmd[1].values.word1 = (static_cast<uint32_t>(lrx & 0xFFFF) << 16) |
                                  static_cast<uint32_t>(lry & 0xFFFF);
        }
    }

    // ---- rectangulos ----
    // `w0`/`w1` van ya en ORDEN DE SCISSOR (w0 = ulx/uly, w1 = lrx/lry): el llamante intercambia
    // las palabras de G_FILLRECT (ul en w1, lr en w0) y deja las de G_TEXRECT tal cual.
    void rect_begin(int cls, uint32_t w0, uint32_t w1) {
        switch (cls) {
            case kLeft:
                widen_scissor(cls);
                if (GfxCommand* cmd = reserve(2)) gEXSetRectAlign(cmd, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_LEFT, 0, 0, 0, 0);
                break;
            case kRight:
                // El fondo del mapa: se ancla al borde derecho con el mismo align que el contenido
                // y se recorta con el mismo scissor de panel (lo emite `group_begin`, llamado por
                // el llamante antes del rect). Los offsets ajustan ancho/posicion del fondo.
                if (GfxCommand* cmd = reserve(2)) {
                    gEXSetRectAlign(cmd, G_EX_ORIGIN_NONE, G_EX_ORIGIN_RIGHT, 0, 0,
                                    g_map_bg_shift.load(std::memory_order_relaxed),
                                    -g_map_bg_crop.load(std::memory_order_relaxed));
                }
                break;
            case kStretch:
                if (GfxCommand* cmd = reserve(1)) gEXSetRectAspect(cmd, G_EX_ASPECT_STRETCH);
                break;
            case kSpill:
                widen_scissor(cls);
                break;
            default:
                break;
        }
    }
    void rect_end(int cls) {
        switch (cls) {
            case kLeft:
                if (GfxCommand* cmd = reserve(2)) gEXSetRectAlign(cmd, G_EX_ORIGIN_NONE, G_EX_ORIGIN_NONE, 0, 0, 0, 0);
                restore_scissor();
                break;
            case kRight:
                break;
            case kStretch:
                if (GfxCommand* cmd = reserve(1)) gEXSetRectAspect(cmd, G_EX_ASPECT_AUTO);
                break;
            case kSpill:
                restore_scissor();
                break;
            default:
                break;
        }
    }

    // ---- grupos de triangulos (una lista llamada) ----
    void group_begin(int cls) {
        switch (cls) {
            case kLeft:
                widen_scissor(cls);
                viewport_align(G_EX_ORIGIN_LEFT, origin_cancel(G_EX_ORIGIN_LEFT));
                break;
            case kRight:
                // El panel canonico se captura del scissor VIGENTE al empezar el primer elemento
                // `right` (el contenido del mapa ya viene dibujado bajo su G_SETSCISSOR de panel; el
                // fondo, en cambio, bajo uno a pantalla completa). Da igual el orden: el primer
                // elemento `right` fija `map_panel_w0/w1` y el resto reutiliza ESE mismo scissor.
                // El panel se fija del scissor vigente (es el del panel). Si ya lo fijo un rect
                // (panel_done == 2) se respeta ese, y si el scissor no es de panel se cae a las
                // coords del propio rect.
                if (panel_done != 2 && have_scissor) {
                    // Solo un scissor mas estrecho que el framebuffer es un panel; uno a pantalla
                    // completa (el fondo) no lo es.
                    const int fbq = static_cast<int>(fb_width) * 4;
                    const int s_ulx = static_cast<int>((scissor_w0 >> 12) & 0xFFF);
                    const int s_lrx = static_cast<int>((scissor_w1 >> 12) & 0xFFF);
                    if (!((s_ulx <= 0) && (s_lrx - fbq >= 0))) {
                        have_map_panel = true;
                        panel_done = 1;
                        map_panel_w0 = scissor_w0;
                        map_panel_w1 = scissor_w1;
                        if (have_viewport) {
                            have_map_vport = true;
                            map_vport_w0 = viewport_w0;
                            map_vport_w1 = viewport_w1;
                        }
                    }
                }
                if (have_map_panel) anchored_scissor(kRight, map_panel_w0, map_panel_w1, map_crop_q());
                else widen_scissor(cls);
                viewport_align(G_EX_ORIGIN_RIGHT, origin_cancel(G_EX_ORIGIN_RIGHT));
                break;
            case kStretch:
                projection_group(G_EX_ASPECT_STRETCH);
                break;
            case kSpill:
                widen_scissor(cls);
                break;
            default:
                break;
        }
    }
    void group_end(int cls) {
        switch (cls) {
            case kLeft:
            case kRight:
                viewport_align(G_EX_ORIGIN_NONE, 0);
                restore_scissor();
                break;
            case kStretch:
                projection_group(G_EX_ASPECT_AUTO);
                break;
            case kSpill:
                restore_scissor();
                break;
            default:
                break;
        }
    }

    // Copia la lista en `address` (y, recursivamente, las que llama) al scratch y devuelve la
    // direccion KSEG0 de la copia. `enclosing_cls` es la clase del grupo que la contiene: se hereda
    // a los rects internos que no tengan clase propia (si no, un grupo `right` mueve su marco por
    // viewport pero deja sus rects quietos -> fondo y contenido se desfasan; el mapa de la
    // referencia era justo eso: el commit 9aaef58 promovio los tags pero no toco esto).
    uint32_t copy_list(uint32_t address, int depth, int enclosing_cls) {
        const uint32_t start = used;
        int branch_cls = kAuto;   // clase del branch que se esta inlinando
        enable();   // RT64 olvida el GBI extendido al terminar cada lista
        uint32_t pc = physical(address);
        for (int guard = 0; guard < 40000 && !overflow; ++guard) {
            if (pc >= 0x800000) break;
            const uint32_t w0 = hh::hudid::read_word(rdram, pc);
            const uint32_t w1 = hh::hudid::read_word(rdram, pc + 4);
            const uint8_t op = static_cast<uint8_t>(w0 >> 24);
            pc += 8;
            // Clase heredada por los draws de esta iteracion (el branch inlinado manda).
            const int elem_cls = (branch_cls != kAuto) ? branch_cls : enclosing_cls;
            switch (op) {
                case kEndDl:
                    if (branch_cls != kAuto) group_end(branch_cls);
                    emit(w0, w1);
                    return 0x80000000u | (base + start);
                case kDl: {
                    const bool branch = ((w0 >> 16) & 0xFF) != 0;
                    if (branch) {
                        // Un branch no retorna: el final de su lista es el final de esta lista. Un
                        // branch clasificado (el dial del radar) se envuelve desde aqui hasta ese
                        // G_ENDDL.
                        const std::string id = hh::hudid::list(rdram, w1, physical(w1));
                        const int cls = class_of(id.c_str());
                        trace_seen(id, "branch", cls);
                        if (branch_cls != kAuto) group_end(branch_cls);
                        branch_cls = cls;
                        if (cls != kAuto) {
                            trace_elem(id, cls);
                            group_begin(cls);
                            trace_draw(id, "dl-branch");
                            ++applied;
                        }
                        pc = physical(w1);   // seguirlo inline
                        break;
                    }
                    const std::string id = hh::hudid::list(rdram, w1, physical(w1));
                    const int cls = depth < 10 ? class_of(id.c_str()) : kAuto;
                    trace_seen(id, "call", cls);
                    // La llamada se copia primero, tras los comandos ya emitidos, asi que se
                    // escribe el placeholder, luego la copia y se parchea.
                    uint32_t callee = w1;
                    if (depth < 10) {
                        const uint32_t jump_at = used;
                        emit(0, 0);
                        uint32_t copied = copy_list(w1, depth + 1, cls != kAuto ? cls : enclosing_cls);
                        if (overflow) return 0;
                        const uint32_t after = used;
                        const uint32_t jw0 = (static_cast<uint32_t>(kDl) << 24) | (1u << 16);
                        const uint32_t jw1 = 0x80000000u | (base + after);
                        std::memcpy(rdram + base + jump_at, &jw0, 4);
                        std::memcpy(rdram + base + jump_at + 4, &jw1, 4);
                        callee = copied;
                    }
                    if (cls != kAuto) trace_elem(id, cls);
                    group_begin(cls);
                    if (cls != kAuto) trace_draw(id, "dl-call");
                    emit(w0, callee);
                    enable();
                    group_end(cls);
                    if (cls != kAuto) ++applied;
                    break;
                }
                case kMoveWord:
                    if (((w0 >> 16) & 0xFF) == kMwSegment) {
                        segments[((w0 & 0xFFFF) / 4) & 0x0F] = w1 & 0x1FFFFFFF;
                    }
                    emit(w0, w1);
                    break;
                case kMoveMem:
                    if ((w0 & 0xFF) == kMvViewport) {
                        have_viewport = true;
                        viewport_w0 = w0;
                        viewport_w1 = w1;
                    }
                    emit(w0, w1);
                    break;
                case kMtx:
                    if ((((w0 & 0xFF) ^ 0x01) & kMtxProjection) != 0) {
                        have_projection = true;
                        projection_w0 = w0;
                        projection_w1 = w1;
                    }
                    emit(w0, w1);
                    break;
                case kSetScissor:
                    have_scissor = true;
                    scissor_w0 = w0;
                    scissor_w1 = w1;
                    // Dentro de un grupo clasificado, el scissor del juego se sustituye por el
                    // canonico de la clase: para el mapa, el MISMO panel capturado del fondo, de modo
                    // que fondo y contenido no puedan acabar en dos bordes distintos.
                    if (elem_cls == kRight) {
                        // Solo un scissor que NO cubra todo el ancho del framebuffer es un panel:
                        // el fondo del mapa trae su propio G_SETSCISSOR a PANTALLA COMPLETA dentro
                        // del bloque y no debe capturarse como panel (daria un recorte fuera de
                        // pantalla). El panel real lo fija el scissor del contenido
                        // (197,143..277,223).
                        const int fbq = static_cast<int>(fb_width) * 4;
                        const int s_ulx = static_cast<int>((w0 >> 12) & 0xFFF);
                        const int s_lrx = static_cast<int>((w1 >> 12) & 0xFFF);
                        const bool full_width = (s_ulx <= 0) && (s_lrx - fbq >= 0);
                        if (!have_map_panel && !full_width) {
                            have_map_panel = true;
                            panel_done = 1;
                            map_panel_w0 = w0;
                            map_panel_w1 = w1;
                            }
                        if (have_map_panel) {
                            anchored_scissor(kRight, map_panel_w0, map_panel_w1, map_crop_q());
                        } else {
                            // Todavia sin panel (scissor a pantalla completa): dejar el scissor del
                            // juego tal cual y esperar el del contenido.
                            emit(w0, w1);
                        }
                    } else if (elem_cls == kLeft) {
                        anchored_scissor(kLeft, w0, w1);
                    } else {
                        emit(w0, w1);
                    }
                    break;
                case kSetCombine:
                    have_combine = true;
                    combine_w0 = w0;
                    combine_w1 = w1;
                    emit(w0, w1);
                    break;
                case kSetCImg:
                    fb_width = ((w1 & 0x00FFFFFF) == 0x00400000) ? 640 : 320;
                    emit(w0, w1);
                    break;
                case kSetTImg:
                    image = w1;
                    texture_ident = hh::hudid::texture(rdram, w1, physical(w1));
                    emit(w0, w1);
                    break;
                case kSetFillColor:
                    fill_colour = w1;
                    emit(w0, w1);
                    break;
                case kFillRect: {
                    // Mismas coordenadas que el trace: 320x240, clears excluidos.
                    const float to_320 = 320.0f / static_cast<float>(fb_width);
                    const std::string id = hh::hudid::fill(
                        fill_colour, int((((w1 >> 12) & 0xFFF) / 4.0f) * to_320), int(((w1 & 0xFFF) / 4.0f) * to_320),
                        int((((w0 >> 12) & 0xFFF) / 4.0f) * to_320), int(((w0 & 0xFFF) / 4.0f) * to_320));
                    int cls = id.empty() ? kAuto : class_of(id.c_str());
                    if (cls == kAuto) cls = elem_cls;   // heredada del grupo que lo contiene
                    if (!id.empty()) trace_seen(id, "fill rect", cls);
                    if (cls != kAuto) trace_elem(id, cls);
                    if (cls == kRight) {
                        // Fondo negro del mapa. NO se usa el G_FILLRECT del juego: se RECONSTRUYE a
                        // partir del panel canonico para que sus cuatro coordenadas sean EXACTAMENTE
                        // las del scissor recortado que emite `anchored_scissor` (mismos numeros y
                        // MISMOS origenes RIGHT/RIGHT). Con esto:
                        //   - el rect es CUADRADO (el panel es 80x80 y el recorte es uniforme);
                        //   - RT64 lo detecta como "cubre el ancho del scissor" -> invRatioScale = 1 y
                        //     no lo estira por aspecto (que era lo que lo dejaba AALARGADO);
                        //   - su borde coincide con el scissor que recorta el contenido (mapa verde y
                        //     flecha roja).
                        // El rect del juego no sirve: va con origen izquierdo NONE y derecho RIGHT, y
                        // con RIGHT RT64 suma el ancho del framebuffer a `lrx` (197..597 px = 400 px de
                        // ancho). El resto del alineado sub-pixel lo hacen los parches de RT64
                        // (`tools/patch_rt64_*.py`). La via del quad se descarto: el contenido del mapa
                        // es geometria en espacio de mapa, no 2D en pixeles.
                        // Si el fondo llega antes que el contenido y aun no hay panel, se toma el
                        // propio rect del fondo como panel (solo si NO cubre todo el ancho; el id de
                        // esta clase es precisamente el fill del mapa @197,143,277,223).
                        if (!have_map_panel) {
                            const int fbq = static_cast<int>(fb_width) * 4;
                            const int f_ulx = static_cast<int>((w1 >> 12) & 0xFFF);
                            const int f_lrx = static_cast<int>((w0 >> 12) & 0xFFF);
                            if (!((f_ulx <= 0) && (f_lrx - fbq >= 0))) {
                                have_map_panel = true;
                                map_panel_w0 = w1 & 0x00FFFFFF;
                                map_panel_w1 = w0 & 0x00FFFFFF;
                            }
                        }
                        if (have_map_panel) {
                            const int fbq = static_cast<int>(fb_width) * 4;
                            const int crop_q = map_crop_q();
                            // Mismas cuentas que `anchored_scissor(kRight, ...)`: se resta el ancho del
                            // framebuffer (coordenada relativa al origen derecho) y se recorta por lado.
                            const int b_ulx = static_cast<int>((map_panel_w0 >> 12) & 0xFFF) - fbq + crop_q;
                            const int b_uly = static_cast<int>(map_panel_w0 & 0xFFF) + crop_q;
                            const int b_lrx = static_cast<int>((map_panel_w1 >> 12) & 0xFFF) - fbq - crop_q;
                            const int b_lry = static_cast<int>(map_panel_w1 & 0xFFF) - crop_q;
                            static bool bg_traced = false;
                            if (!bg_traced) {
                                bg_traced = true;
                                hh::log("[hh-bg] panel=%d,%d..%d,%d crop=%d -> bg=%d,%d..%d,%d\n",
                                        static_cast<int>((map_panel_w0 >> 12) & 0xFFF) >> 2,
                                        static_cast<int>(map_panel_w0 & 0xFFF) >> 2,
                                        static_cast<int>((map_panel_w1 >> 12) & 0xFFF) >> 2,
                                        static_cast<int>(map_panel_w1 & 0xFFF) >> 2,
                                        map_crop(),
                                        (b_ulx + fbq) >> 2, b_uly >> 2, (b_lrx + fbq) >> 2, b_lry >> 2);
                            }
                            // Fondo y scissor comparten numeros y origenes: el rect "cubre" el
                            // scissor (invRatioScale = 1, sin estiramiento) y encaja con el crop.
                            trace_draw(id, "fill");
                            emit_fill_rect_ext(G_EX_ORIGIN_RIGHT, G_EX_ORIGIN_RIGHT,
                                               b_ulx, b_uly, b_lrx, b_lry);
                            ++applied;
                            break;
                        }
                        // Fallback (sin panel capturado todavia): rect del juego tal cual.
                        rect_begin(cls, w1, w0);   // G_FILLRECT: ul va en w1, lr en w0
                        trace_draw(id, "fill");
                        emit(w0, w1);
                        rect_end(cls);
                        ++applied;
                        break;
                    }
                    rect_begin(cls, w1, w0);   // G_FILLRECT: ul va en w1, lr en w0
                    trace_draw(id, "fill");
                    emit(w0, w1);
                    rect_end(cls);
                    if (cls != kAuto) ++applied;
                    break;
                }
                case kTexRect:
                case kTexRectFlip: {
                    int cls = class_of(texture_ident.c_str());
                    if (cls == kAuto) cls = elem_cls;   // heredada del grupo que lo contiene
                    trace_seen(texture_ident, "tex rect", cls);
                    if (cls != kAuto) trace_elem(texture_ident, cls);
                    rect_begin(cls, w0, w1);
                    trace_draw(texture_ident, "texrect");
                    emit(w0, w1);
                    for (uint8_t half : { kRdpHalf1, kRdpHalf2 }) {
                        const uint32_t h0 = hh::hudid::read_word(rdram, pc);
                        if (static_cast<uint8_t>(h0 >> 24) == half) {
                            emit(h0, hh::hudid::read_word(rdram, pc + 4));
                            pc += 8;
                        }
                    }
                    rect_end(cls);
                    if (cls != kAuto) ++applied;
                    break;
                }
                default:
                    emit(w0, w1);
                    break;
            }
        }
        // Se salio de la lista o del espacio: no es seguro enviarla.
        overflow = true;
        return 0;
    }
};

int g_turn = 0;

}  // namespace

int map_crop() {
    return g_map_crop.load(std::memory_order_relaxed);
}

void map_crop_add(int delta) {
    int v = g_map_crop.load(std::memory_order_relaxed) + delta;
    if (v < 0) v = 0;
    g_map_crop.store(v, std::memory_order_relaxed);
    std::fprintf(stderr, "[hh] recorte del mapa = %d px\n", v);
    std::fflush(stderr);
}

int map_bg_crop() {
    return g_map_bg_crop.load(std::memory_order_relaxed);
}

int map_bg_shift() {
    return g_map_bg_shift.load(std::memory_order_relaxed);
}

void map_bg_crop_add(int delta) {
    int v = g_map_bg_crop.load(std::memory_order_relaxed) + delta;
    if (v < 0) v = 0;
    g_map_bg_crop.store(v, std::memory_order_relaxed);
    std::fprintf(stderr, "[hh] recorte del fondo del mapa = %d px\n", v);
    std::fflush(stderr);
}

void map_bg_shift_add(int delta) {
    int v = g_map_bg_shift.load(std::memory_order_relaxed) + delta;
    g_map_bg_shift.store(v, std::memory_order_relaxed);
    std::fprintf(stderr, "[hh] desplazamiento del fondo del mapa = %d px\n", v);
    std::fflush(stderr);
}

int class_of(const char* identity) {
    if (identity == nullptr) return kAuto;
    struct Entry { const char* id; int cls; };
    static const Entry kTable[] = {
        // Radar (barra de salud radial), borde izquierdo.
        { "tex:0x802866f8#a3036828", kLeft },
        { "tex:0x80286af8#dfde6ac5", kLeft },
        { "dl:0x80181860#e59a0172", kLeft },
        // HUD de combate POWER/STAMINA (al lado del radial, misma altura): barras + decoracion +
        // numeros HP. Todo se desplaza lo mismo que el radial (`left`).
        { "tex:0x802875b8#dde74e45", kLeft },   // barra fina
        { "tex:0x80301ea8#49f54bfa", kLeft },   // decoracion/etiqueta POWER/STAMINA
        { "tex:0x802872f8#18bafa7e", kLeft },   // marco
        { "tex:0x802ec298#2d78f1b6", kLeft },   // decoracion
        { "tex:0x802eca98#37a5c505", kLeft },   // decoracion
        { "tex:0x802ed298#26092cb3", kLeft },   // decoracion
        // Mapa (abajo-derecha): fondo + capas. Identidades de la referencia, hashes coincidentes.
        { "fill:0x00000000@197,143,277,223", kRight },
        { "dl:0x030002e0#bbb8c0ba", kRight },
        { "dl:0x03000f10#1427da33", kRight },
    };
    for (const Entry& e : kTable) {
        if (std::strcmp(identity, e.id) == 0) return e.cls;
    }
    // Prefijos: barras de valor animadas (el ancho del fill cambia cada frame -> identidad distinta).
    struct Prefix { const char* p; int cls; };
    static const Prefix kPrefix[] = {
        { "fill:0x00000000@64,24,", kLeft },   // relleno de POWER/STAMINA (y 24..27)
    };
    for (const Prefix& p : kPrefix) {
        if (std::strncmp(identity, p.p, std::strlen(p.p)) == 0) return p.cls;
    }
    return kAuto;
}

bool any_classes() {
    return true;
}

uint32_t rewrite(uint8_t* rdram, uint32_t list_address) {
    static const bool off = [] {
        const char* v = std::getenv("HH_NO_HUD_REWRITE");
        return v != nullptr && *v != '\0' && *v != '0';
    }();
    if (off || !any_classes() || rdram == nullptr) return 0;

    g_turn ^= 1;
    Writer w{ rdram, kScratch[g_turn], kScratchSize };
    const uint32_t copy = w.copy_list(list_address, 0, kAuto);
    static bool reported_overflow = false;
    if (w.overflow || copy == 0) {
        if (!reported_overflow) {
            reported_overflow = true;
            hh::log("[hh] HUD rewrite: una lista no cupo o no termino (%u bytes usados); se envia sin cambios\n", w.used);
        }
        return 0;
    }
    // Informa del maximo observado (no solo de las 3 primeras listas) para diagnostico.
    static int max_applied = 0;
    if (w.applied > max_applied) {
        max_applied = w.applied;
        hh::log("[hh] HUD rewrite: max %d elemento(s) clasificado(s) en una copia de %u bytes\n",
                w.applied, w.used);
    }
    return copy;
}

}  // namespace hh::hudrewrite
