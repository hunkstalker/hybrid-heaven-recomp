// Fase A2 (interpolacion fiel): tagging de transforms de modelo para RT64.
//
// Problema medido (nota 2026-10-02-fps-instrumentacion-pairing-y-plan-identidad.md): sin tags, RT64
// empareja los transforms entre frames por heuristica/direccion; HH reutiliza direcciones (arena
// ~0x00268A00) -> empareja objetos distintos -> parpadeo/replay (#6/#8/#10/#12). La solucion (igual
// que Goemon64Recomp) es dar a cada hueso una ID de `gEXMatrixGroup` ESTABLE entre frames, desde el
// propio flujo del juego (hook del port, no reescritura de DL).
//
// Cadena de dibujo de HH (localizada en build/recomp):
//   func_800068C0_74C0 (traversal DOBJ) -> func_800069A8_75A8 (dispatch por tipo de nodo) ->
//   func_8000C768 (malla) | func_80007DE4/800082C4/80008754/... (otros tipos, tambien con G_MTX)
// El hook envuelve `func_800069A8(a0=node DOBJ)`, el DISPATCH unico por el que pasa TODO nodo DOBJ
// (todos los tipos), no solo la malla. Envolver solo `func_8000C768` dejaba sin tag a los otros
// tipos (~1 transform/frame sin taggear: `unpaired_tagged=0` en el log). El pop va DESPUES del draw
// completo; envolver solo la matriz (`func_8000C4A8`) cerraba el grupo antes de materializarse (por
// eso RT64 lo ignoraba: `ignored=0`).
//
// El nodo DOBJ (`a0`) es estable entre frames (a diferencia del gmtx, reciclado): se usa como ID.
//
// Gate: HH_MTXGROUP=1 (por defecto OFF). Con OFF el hook delega sin mas (comportamiento original).
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <unordered_set>

#include "librecomp/overlays.hpp"
#include "recomp.h"
#include "hh.h"

// HH usa F3DEX2: el opcode del hook extendido (gEXEnable) es G_SPNOOP 0xE0, no 0x00. Sin esto,
// `RT64_HOOK_OPCODE` vale 0x00 y el GBI extendido NUNCA se habilita -> RT64 descarta los
// `gEXMatrixGroup` (por eso `ignored=0`). Debe ir ANTES de incluir el header (igual que hud_rewrite).
#define F3DEX_GBI_2
#include "rt64_extended_gbi.h"

extern "C" void func_800069A8_75A8(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_800068C0_74C0(uint8_t* rdram, recomp_context* ctx);

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

// Lee un u32 de RDRAM por direccion KSEG0.
inline uint32_t rd_u32(uint8_t* rdram, uint32_t kseg0) {
    uint32_t v;
    std::memcpy(&v, rdram + (kseg0 & 0x1FFFFFFFu), 4);
    return v;
}

// Identidad ESTABLE del objeto dibujado. Medido (2026-10-03): NINGUNA direccion de la arena de
// dibujo sirve (el PUNTERO DEL NODO y el del MODELO `node->0x2C` se RECICLAN entre frames: el mismo
// id aparecia con posiciones totalmente distintas). Solucion (como Goemon/Zelda): identidad de
// **ACTOR/RAIZ + indice de orden**. El traversal `func_800068C0(a1=root_node)` recorre el arbol DOBJ
// del actor en orden determinista; combinamos el root (estable por actor) con el **indice de nodo**
// dentro del recorrido (estable por hueso). Lo fija `hh_model_root_hook` (ver abajo).
uint32_t g_current_root = 0;   // root del traversal actual (lo fija el hook de func_800068C0)
uint32_t g_node_order = 0;     // indice del nodo dentro del traversal (lo incrementa el hook)

inline uint32_t stable_id() {
    uint32_t h = (g_current_root * 2654435761u) ^ (g_node_order * 2246822519u);
    h ^= h >> 16; h *= 0x7feb352d; h ^= h >> 15;   // avalancha
    return h | 0x80000000u;                        // nunca 0 (IGNORE) ni 0xFFFFFFFF (AUTO)
}

const bool g_enabled = [] {
    const char* v = std::getenv("HH_MTXGROUP");
    return v != nullptr && *v != '\0' && *v != '0';
}();

// Skip de spawn/reaparicion por ID, con FRONTERA DE FRAME FIABLE (`hh_dl_frame_count`, que el port
// incrementa en `send_dl`: una vez por frame de juego). Si un ID no se vio en el frame anterior, este
// frame se "salta" (pose actual, sin interpolar) -> evita el salto/brillo de un objeto que aparece
// (aura del jefe #6). Sin esto, un nodo recreado se interpola desde una pose vieja.
extern "C" uint64_t hh_dl_frame_count(void);
std::unordered_set<uint32_t> g_seen_prev;
std::unordered_set<uint32_t> g_seen_cur;
uint64_t g_last_frame = ~uint64_t(0);
uint64_t g_skip_count = 0;    // diagnosticos (HH_MTXGROUP_LOG)
uint64_t g_total_count = 0;

void roll_frame() {
    const uint64_t f = hh_dl_frame_count();
    if (f != g_last_frame) {
        g_last_frame = f;
        g_seen_prev.swap(g_seen_cur);
        g_seen_cur.clear();
    }
}

// HH_MTXGROUP_NOSKIP=1: desactiva el skip de spawn (A/B).
bool skip_spawn_enabled() {
    static const bool off = [] {
        const char* v = std::getenv("HH_MTXGROUP_NOSKIP");
        return v != nullptr && *v != '\0' && *v != '0';
    }();
    return !off;
}

// HH_MTXGROUP_LOG=1: traza (tope 100) los primeros nodos taggeados, con node/modelo/ID. El campo
// `model` (node->0x2C) es la semilla de la ID; util para comprobar que es >0 y estable.
void trace_once(uint8_t* rdram, uint32_t node, uint32_t id) {
    static const bool on = std::getenv("HH_MTXGROUP_LOG") != nullptr;
    if (!on) return;
    static int n = 0;
    if (n >= 100) return;
    ++n;
    hh::log("[hh-mtxgroup] node=%08X model=%08X id=%08X (%d/100)\n",
            node, rd_u32(rdram, node + 0x2C), id, n);
}

// Autodiagnostico: con HH_MTXGROUP_LOG=1, la PRIMERA llamada al hook (con el flag on u off) deja
// constancia en hh.log de que el hook SI se engancha y en que estado.
void log_hook_seen() {
    static const bool log_on = std::getenv("HH_MTXGROUP_LOG") != nullptr;
    if (!log_on) return;
    static bool seen = false;
    if (seen) return;
    seen = true;
    hh::log("[hh-mtxgroup] hook ACTIVO (0x800069A8); HH_MTXGROUP=%s\n", g_enabled ? "ON" : "OFF");
}

}  // namespace

// Diagnosticos del skip de spawn (para [hh-pair]).
extern "C" unsigned long long hh_mtxgroup_skip_count() { return g_skip_count; }
extern "C" unsigned long long hh_mtxgroup_total_count() { return g_total_count; }

// Hook del TRAVERSAL del arbol DOBJ (`func_800068C0(a0=flags, a1=root)`): fija el root actual y
// reinicia el indice de orden. Todos los nodos del mismo root se numeran 0,1,2,... en el recorrido
// (determinista) -> identidad estable por (actor, hueso). Va ANTES del draw de cada nodo.
extern "C" void hh_model_root_hook(uint8_t* rdram, recomp_context* ctx) {
    if (g_enabled) {
        g_current_root = ctx->r5;   // a1 = root node
        g_node_order = 0;
    }
    func_800068C0_74C0(rdram, ctx);
}

// Hook del DRAW de malla (matriz + geometria). Con el flag activo: grupo RT64 (interpolacion normal,
// push/pop balanceados) envolviendo todo el draw; con el flag apagado: solo el original.
extern "C" void hh_bone_draw_hook(uint8_t* rdram, recomp_context* ctx) {
    log_hook_seen();
    if (!g_enabled) {
        func_800069A8_75A8(rdram, ctx);
        return;
    }

    const uint32_t node = ctx->r4;              // a0 = nodo DOBJ
    const uint32_t id = stable_id();            // root del traversal + indice de orden
    ++g_node_order;                             // siguiente nodo del mismo root

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
    //
    // OJO: NO emitir `gEXSetRDRAMExtended`. HH NO usa direcciones extendidas: sus direcciones son
    // KSEG0 (bit 31 puesto), y con `extendRDRAM=1` RT64 cambia `fromSegmented`/`maskPhysicalAddress`
    // (rt64_rsp.cpp:104/114) -> reinterpreта TODAS las direcciones y rompe el widescreen (la escena
    // deja de expandir; el HUD sigue porque se ancla por reescritura de DL). Goemon lo tiene
    // comentado por esto; solo lo necesita Zelda (que si usa direcciones extendidas). Bug 2026-10-03.
    // Spawn/reaparicion: ID no visto en el frame anterior -> este frame no interpola (snap).
    roll_frame();
    const bool reappeared = skip_spawn_enabled() && (g_seen_prev.find(id) == g_seen_prev.end());
    g_seen_cur.insert(id);
    if (reappeared) ++g_skip_count;
    ++g_total_count;

    if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
        gEXEnable(cmd);
    }
    if (GfxCommand* cmd = gfx_emit(rdram, 2)) {
        if (reappeared) {
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

    func_800069A8_75A8(rdram, ctx);             // matriz + G_MTX + G_DL (el G_VTX materializa el grupo)

    // Cierra el grupo (pila equilibrada) DESPUES del draw completo.
    if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
        gEXPopMatrixGroup(cmd, /*proj=*/0);
    }

    trace_once(rdram, node, id);
}
