// Fase A2 (interpolacion fiel): tagging de transforms de modelo para RT64.
//
// Problema medido (nota 2026-10-02-fps-instrumentacion-pairing-y-plan-identidad.md): sin tags, RT64
// empareja los transforms entre frames por heuristica/direccion; HH reutiliza direcciones (arena
// ~0x00268A00) -> empareja objetos distintos -> parpadeo/replay (#6/#8/#10/#12). La solucion (igual
// que Goemon64Recomp) es dar a cada hueso una ID de `gEXMatrixGroup` ESTABLE entre frames, desde el
// propio flujo del juego (hook del port, no reescritura de DL).
//
// Cadena de dibujo de HH (localizada en build/recomp):
//   func_800068C0_74C0 (traversal DOBJ) -> func_800069A8_75A8 (dispatch) ->
//   func_8000C768_D368 (DRAW de malla: matriz + G_MTX + G_DL) -> func_8000C4A8_D0A8 (matriz + G_MTX)
// El hook envuelve `func_8000C768(a0=node DOBJ)`, que es lo que emite la matriz Y la geometria (el
// `G_VTX` que materializa el `gEXMatrixGroup` va dentro del `G_DL` que emite `func_8000C768`). El pop
// debe ir DESPUES de este draw completo; envolver solo la matriz (`func_8000C4A8`) cerraba el grupo
// antes de materializarse (por eso RT64 lo ignoraba: `ignored=0`).
//
// El nodo DOBJ (`a0`) es estable entre frames (a diferencia del gmtx, reciclado): se usa como ID.
//
// Gate: HH_MTXGROUP=1 (por defecto OFF). Con OFF el hook delega sin mas (comportamiento original).
#include <cstdint>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>

#include "librecomp/overlays.hpp"
#include "recomp.h"
#include "hh.h"

// HH usa F3DEX2: el opcode del hook extendido (gEXEnable) es G_SPNOOP 0xE0, no 0x00. Sin esto,
// `RT64_HOOK_OPCODE` vale 0x00 y el GBI extendido NUNCA se habilita -> RT64 descarta los
// `gEXMatrixGroup` (por eso `ignored=0`). Debe ir ANTES de incluir el header (igual que hud_rewrite).
#define F3DEX_GBI_2
#include "rt64_extended_gbi.h"

extern "C" void func_8000C768_D368(uint8_t* rdram, recomp_context* ctx);

namespace {

// Cursor de la display list de gfx del juego (puntero KSEG0). Global D_8008D5BC_8E1BC.
constexpr uint32_t kGfxCursor = 0x8008D5BCu;

inline uint32_t* rdram_u32(uint8_t* rdram, uint32_t kseg0) {
    return reinterpret_cast<uint32_t*>(rdram + (kseg0 & 0x1FFFFFFFu));
}

// Emite `count` comandos de 8 bytes en el cursor de gfx del juego y lo avanza. Mismo protocolo que
// usan las funciones del juego (leer el puntero, escribir, sumar 8*count, guardar).
GfxCommand* gfx_emit(uint8_t* rdram, uint32_t count) {
    uint32_t* cursor = rdram_u32(rdram, kGfxCursor);
    GfxCommand* cmd = reinterpret_cast<GfxCommand*>(rdram + (*cursor & 0x1FFFFFFFu));
    *cursor += 8u * count;
    return cmd;
}

// ID estable del hueso: puntero del nodo DOBJ (a0). El juego lo mantiene entre frames. Se mezcla con
// un hash para repartir y evitar 0/auto.
inline uint32_t stable_id(uint32_t node_ptr) {
    uint32_t h = node_ptr * 2654435761u;   // Knuth multiplicative
    return h | 0x80000000u;                // nunca 0 (== G_EX_ID_IGNORE) ni 0xFFFFFFFF (== AUTO)
}

const bool g_enabled = [] {
    const char* v = std::getenv("HH_MTXGROUP");
    return v != nullptr && *v != '\0' && *v != '0';
}();

// Nodos vistos en el frame logico actual y en el anterior. Un nodo que aparece por PRIMERA vez
// (o tras ausentarse) es un spawn/reaparicion: ese frame NO se interpola (pose "skip"), para no
// interpolar desde una pose vieja/inexistente -> evita el salto en spawns (#6 aura, #10 curar).
// Los nodos se reciclan; el set se limpia cada frame logico (contador de VI).
std::unordered_set<uint32_t> g_seen_prev;
std::unordered_set<uint32_t> g_seen_cur;
uint64_t g_frame_mark = 0;

// Avanza el "frame" del tagging si cambio el contador de VI (una vez por frame logico).
extern "C" uint64_t hh_get_vi_count(void);
void roll_frame() {
    const uint64_t vi = hh_get_vi_count();
    if (vi != g_frame_mark) {
        g_frame_mark = vi;
        g_seen_prev.swap(g_seen_cur);
        g_seen_cur.clear();
    }
}

// HH_MTXGROUP_LOG=1: traza (tope 100) la primera vez que se taggea cada nodo, con su ID.
void trace_once(uint32_t node, uint32_t id) {
    static const bool on = std::getenv("HH_MTXGROUP_LOG") != nullptr;
    if (!on) return;
    static int n = 0;
    if (n >= 100) return;
    ++n;
    hh::log("[hh-mtxgroup] node=%08X id=%08X (%d/100)\n", node, id, n);
}

// Autodiagnostico: con HH_MTXGROUP_LOG=1, la PRIMERA llamada al hook (con el flag on u off) deja
// constancia en hh.log de que el hook SI se engancha y en que estado.
void log_hook_seen() {
    static const bool log_on = std::getenv("HH_MTXGROUP_LOG") != nullptr;
    if (!log_on) return;
    static bool seen = false;
    if (seen) return;
    seen = true;
    hh::log("[hh-mtxgroup] hook ACTIVO (0x8000C768); HH_MTXGROUP=%s\n", g_enabled ? "ON" : "OFF");
}

}  // namespace

// Hook del DRAW de malla (matriz + geometria). Con el flag activo: grupo RT64 (interpolacion normal,
// push/pop balanceados) envolviendo todo el draw; con el flag apagado: solo el original.
extern "C" void hh_bone_draw_hook(uint8_t* rdram, recomp_context* ctx) {
    log_hook_seen();
    if (!g_enabled) {
        func_8000C768_D368(rdram, ctx);
        return;
    }

    const uint32_t node = ctx->r4;              // a0 = nodo DOBJ (ID estable)
    const uint32_t id = stable_id(node);

    // Diagnostico: valor del cursor de gfx (donde cae nuestra escritura) la primera vez.
    {
        static const bool on = std::getenv("HH_MTXGROUP_LOG") != nullptr;
        if (on) {
            static bool once = false;
            if (!once) {
                once = true;
                const uint32_t cur = *rdram_u32(rdram, kGfxCursor);
                hh::log("[hh-mtxgroup] gfx_cursor=%08X (a KSEG0->phys=%08X)\n", cur, cur & 0x1FFFFFFF);
            }
        }
    }

    // GBI extendido (RT64 lo olvida al inicio de cada lista) + grupo del hueso. El grupo se
    // materializa en el `G_VTX` que emite el draw completo (dentro de su G_DL). `proj` = 0
    // (modelview); componentes = preset "Normal" de Goemon.
    if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
        gEXEnable(cmd);
    }
    if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
        gEXSetRDRAMExtended(cmd, 1);
    }
    // Spawn/reaparicion: si el nodo no estaba en el frame anterior, este frame se "salta" (pose
    // actual, sin interpolar) para no interpolar desde una pose vieja.
    roll_frame();
    const bool reappeared = (g_seen_prev.find(node) == g_seen_prev.end());
    g_seen_cur.insert(node);

    if (GfxCommand* cmd = gfx_emit(rdram, 2)) {
        if (reappeared) {
            // Todos los componentes SKIP: RT64 usa la pose actual sin interpolar.
            gEXMatrixGroupDecomposed(cmd, id, G_EX_PUSH, /*proj=*/0,
                                     G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP,
                                     G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP,
                                     G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP,
                                     G_EX_COMPONENT_SKIP, G_EX_ORDER_LINEAR,
                                     G_EX_EDIT_ALLOW, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_AUTO);
        }
        else {
            gEXMatrixGroupDecomposed(cmd, id, G_EX_PUSH, /*proj=*/0,
                                     G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                     G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                     G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP,
                                     G_EX_COMPONENT_INTERPOLATE, G_EX_ORDER_LINEAR,
                                     G_EX_EDIT_ALLOW, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_AUTO);
        }
    }

    func_8000C768_D368(rdram, ctx);             // matriz + G_MTX + G_DL (el G_VTX materializa el grupo)

    // Cierra el grupo (pila equilibrada) DESPUES del draw completo.
    if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
        gEXPopMatrixGroup(cmd, /*proj=*/0);
    }

    trace_once(node, id);
}
