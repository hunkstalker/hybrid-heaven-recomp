// Interpolacion fiel (#6/#8/#10/#12): tagging de transforms de MODELO para RT64.
//
// Modelo copiado de Pilotwings64Recomp (patches/interpolation.c; ver
// notes/2026-10-03-fps-tagging-dobj-y-handoff.md §3c/§3d). La leccion medida en HH es que NINGUNA
// direccion es identidad estable: el nodo DOBJ, el modelo (`node->0x2C`) y el root del traversal se
// reciclan entre frames (dump6.log). La identidad correcta es LOGICA:
//
//   id = FNV( kind, slot logico del objeto, modelId, lod )  --  y todo ello mezclado con la
//   GENERACION DE CAMARA, que avanza en cada corte de camara.
//
// Ademas, el grupo es por OBJETO (no por nodo): se envuelve el traversal completo de un actor/DOBJ
// raiz (`func_800068C0(a1=root)`), y RT64 empareja los transforms dentro del grupo por ORDEN de
// dibujo (G_EX_ORDER_LINEAR). Un grupo por nodo obligaba a inventar una ID por hueso y no cubria los
// tipos que no pasan por la malla; el grupo por objeto es estable y cubre TODO el arbol.
//
// La camara de HH va HORNEADA en cada matriz de objeto (igual que PW64): un corte mueve todos los
// transforms a la vez. Sin generacion, RT64 barre la imagen del view viejo al nuevo (el parpadeo de
// camara). La generacion se lee de la propia camara del juego: `D_801BBBF0 + 0xE8` apunta a la
// entidad de camara y `->0x2C` a su transform (pos en +0x30, objetivo en +0x3C; confirmado en
// `func_8011A724`/`func_8011A7FC` de file_008). Un salto >60u o un giro >~40 deg en un frame de
// juego es un corte y avanza la generacion: todos los ids cambian y RT64 no interpola a traves.
//
// Regla de RT64: un id sin contraparte en el frame anterior NO se interpola. El skip de spawn/LOD lo
// hace RT64 solo; aqui NO hay logica de spawn propia (se elimino: causaba microdesfases).
//
// Cadena de dibujo de HH:
//   func_80006790_7390 (lista global de roots) -> func_800068C0_74C0 (traversal DOBJ de un objeto)
//     -> func_800069A8_75A8 (DISPATCH por tipo de nodo) -> malla/efectos/... (todos con G_MTX)
//
// Gate: el tagging está **ON por defecto** (promovido 2026-10-04 tras validar en Windows); se apaga
// con `HH_MTXGROUP=0` (objetos/nodos) o `HH_EMIT_TAG=0`/`HH_FX_EMIT=0` (emisores/cámara). La
// instrumentación de diagnóstico (HH_PAIRING, HH_MTXGROUP_LOG, HH_PAIRCAP, HH_GENCAP,
// HH_PAIRING_DUMP, HH_TEXDUMP, HH_FX_PASS2) sigue **OFF** por defecto.
#include <atomic>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unordered_map>

#include "librecomp/overlays.hpp"
#include "recomp.h"
#include "hh.h"

// HH usa F3DEX2: el opcode del hook extendido (gEXEnable) es G_SPNOOP 0xE0, no 0x00. Sin esto,
// `RT64_HOOK_OPCODE` vale 0x00 y el GBI extendido NUNCA se habilita -> RT64 descarta los
// `gEXMatrixGroup` (por eso `ignored=0`). Debe ir ANTES de incluir el header (igual que hud_rewrite).
#define F3DEX_GBI_2
#include "rt64_extended_gbi.h"

extern "C" void func_800068C0_74C0(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_800069A8_75A8(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80007328_7F28(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8000736C_7F6C(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_800073AC_7FAC(uint8_t* rdram, recomp_context* ctx);
extern "C" uint64_t hh_dl_frame_count(void);

namespace {

// Cursor de la display list de gfx del juego (puntero KSEG0). Global D_8008D5BC_8E1BC.
constexpr uint32_t kGfxCursor = 0x8008D5BCu;

// Camara del juego (file_008 / global plana): D_801BBBF0 + 0xE8 -> entidad; ->0x2C -> transform;
// pos en +0x30..+0x38, objetivo en +0x3C..+0x44. Confirmado en func_8011A724 y func_8011A7FC.
constexpr uint32_t kCamBase = 0x801BBBF0u;
constexpr uint32_t kCamEntityOff = 0xE8u;
constexpr uint32_t kCamTransformOff = 0x2Cu;
constexpr uint32_t kCamPosOff = 0x30u;
constexpr uint32_t kCamTargetOff = 0x3Cu;

// HH corre a ~30 VI/s (PW64 a 60): un giro de 40 deg en UN frame de 30 Hz es un giro rapido normal,
// no un corte. Umbral mas conservador que PW64 para no trocear la interpolacion en cada pan (que se
// veia como tirones de camara). Un corte duro suele ser un salto grande de posicion.
constexpr float kCutDistance = 90.0f;      // u: salto de posicion de camara en un frame -> corte
constexpr float kCutMinForwardDot = 0.0f;  // giro > 90 deg en un frame -> corte

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

// Direccion dentro de la RDRAM asignada al port (8 MB). Evita lecturas fuera de rango si un campo
// (p.ej. el puntero de camara en un frame de menu) no es un puntero valido.
inline bool valid_ram(uint32_t kseg0) {
    return (kseg0 & 0x1FFFFFFFu) < 0x00800000u;
}

inline uint32_t rd_u32(uint8_t* rdram, uint32_t kseg0) {
    uint32_t v;
    std::memcpy(&v, rdram + (kseg0 & 0x1FFFFFFFu), 4);
    return v;
}

inline uint16_t rd_u16(uint8_t* rdram, uint32_t kseg0) {
    uint16_t v;
    std::memcpy(&v, rdram + (kseg0 & 0x1FFFFFFFu), 2);
    return v;
}

inline float rd_f32(uint8_t* rdram, uint32_t kseg0) {
    uint32_t v = rd_u32(rdram, kseg0);
    float f;
    std::memcpy(&f, &v, 4);
    return f;
}

// Gate del tagging de transforms por objeto/nodo (cámara, identidad lógica, huesos, #8). **ON por
// defecto** (promovido 2026-10-04 tras validar en Windows): sin tagging, la interpolación de alta
// tasa deja artefactos (sesgado de cámara, huesos, puertas). `HH_MTXGROUP=0` lo apaga (A/B y
// diagnóstico; deja el comportamiento previo a la épica).
const bool g_enabled = [] {
    const char* v = std::getenv("HH_MTXGROUP");
    return !(v != nullptr && *v != '\0' && *v == '0');   // por defecto ON; `0` lo apaga
}();

const bool g_trace = std::getenv("HH_MTXGROUP_LOG") != nullptr;

// Sprites/efectos 2D (tipos de nodo 1..4): por defecto NO se interpolan (G_EX_ID_IGNORE), que es lo
// que pide §3d.5 para 2D. `HH_FX_AUTO=1` los vuelve a interpolar (G_EX_ORDER_AUTO) para A/B.
const bool g_fx_auto = [] {
    const char* v = std::getenv("HH_FX_AUTO");
    return v != nullptr && *v != '\0' && *v != '0';
}();

// [Opción 2] Tagging en el EMISOR de geometría (no en el traversal de pass 1). Medido 2026-10-04:
// los grupos de pass 1 y la geometría viven en workloads RSP distintos (un `G_RDPFULLSYNC` los
// separa) y `rsp->reset()` borra el estado extendido en la frontera, así que materializar en
// `RSP::matrixId` no alcanza a la geometría (`explicit_ids=0`). El tag tiene que emitirse donde está
// la geometría: envolviendo el emisor que dibuja (patrón ya validado con `C768`).
// `HH_EMIT_TAG=0` (o `HH_FX_EMIT=0`) lo apaga. **ON por defecto** (promovido 2026-10-04 tras validar
// en Windows): el fix de cámara vive en `emitter_wrap()` y su gate es `g_emit_tag && g_enabled`, así
// que sin este gate la cámara (y los emisores de pasada 2) quedaría fuera. Solo emisores que DIBUJAN
// 3D (`can_tag && !is2d`); los setup de menú (7750/78AC/79B0) y los 2D (919C/11958) quedan fuera (el
// "congeló el render" medido venía de envolverlos todos).
const bool g_emit_tag = [] {
    const char* v = std::getenv("HH_EMIT_TAG");
    const bool off = (v != nullptr && *v != '\0' && *v == '0');
    const char* f = std::getenv("HH_FX_EMIT");
    const bool off_alias = (f != nullptr && *f != '\0' && *f == '0');
    return !(off || off_alias);   // por defecto ON; `0` (cualquiera de los dos) lo apaga
}();

// A/B del tagging de emisores. El grupo de PROYECCION (camara) queda **OFF por defecto**: en HH la
// camara va HORNEADA en cada modelview, asi que un grupo de proyeccion la DUPLICA y RT64 la empareja
// mal (camara al apuntar rota). El modelview (con generacion) ya hace snap en los cortes.
// `HH_EMIT_PROJ=1` lo reactiva (A/B). El MODELVIEW va en los emisores 3D (`HH_EMIT_MV=0` lo apaga;
// `HH_EMIT_MV_SKIP=<ids>` salta emisores concretos, p. ej. `8` para `8F30`).
const bool g_emit_proj = [] {
    const char* v = std::getenv("HH_EMIT_PROJ");
    return v != nullptr && *v != '\0' && *v != '0';   // por defecto OFF; `1` la enciende
}();
const bool g_emit_mv = [] {
    const char* v = std::getenv("HH_EMIT_MV");
    return !(v != nullptr && *v != '\0' && *v == '0');
}();
// `HH_EMIT_MV_SKIP=<ids>` (coma): salta el grupo de modelview en esos emisores (A/B para aislar).
const uint32_t g_emit_mv_skip = [] {
    const char* v = std::getenv("HH_EMIT_MV_SKIP");
    uint32_t m = 0;
    if (v != nullptr) {
        for (const char* p = v; *p != '\0';) {
            char* end = nullptr;
            long id = std::strtol(p, &end, 10);
            if (end == p) break;
            if (id >= 0 && id < 32) m |= (1u << id);
            p = end;
            while (*p == ',' || *p == ' ') ++p;
        }
    }
    return m;
}();
inline bool emit_mv_skip(int id) { return id >= 0 && id < 32 && (g_emit_mv_skip & (1u << id)) != 0; }

// ---- identidad logica (FNV-1a + generacion de camara) ---------------------------------------

uint32_t sGeneration = 1;

inline uint32_t mix(uint32_t h, uint32_t v) {
    h ^= v;
    h *= 0x01000193u;
    h ^= h >> 15;
    return h;
}

inline uint32_t interp_id(uint32_t kind, uint32_t a, uint32_t b, uint32_t c) {
    uint32_t h = 0x811C9DC5u;
    h = mix(h, kind);
    h = mix(h, a);
    h = mix(h, b);
    h = mix(h, c);
    h = mix(h, sGeneration);
    if (h == G_EX_ID_IGNORE || h == G_EX_ID_AUTO) {
        h = 0x5057u;
    }
    return h;
}

// Tabla de slots GENERACIONAL. Medido (nota 2026-10-03): el nodo de render no tiene ningun campo
// estable de instancia, pero los actores persistentes conservan su puntero de root durante >=10 s
// (17 roots repetidos entre snapshots), mientras una clase de objetos (efectos, p.ej. model
// 8025A4E0) reasigna root casi cada frame. Estrategia:
//   - root visto en el frame anterior con el MISMO modelo -> mismo slot (objeto persistente).
//   - root nuevo, o reusado tras un hueco -> slot NUEVO (monotonico, nunca se reutiliza).
// Asi el reciclaje de direcciones NO colisiona (un root reusado no hereda el id de un objeto muerto)
// y los efectos reciben ids nuevos (RT64 no los interpola a traves de un salto). No necesita el
// actor: la identidad se deriva del comportamiento observado, no de una direccion.
struct SlotEntry {
    uint32_t slot;
    uint32_t model;
    uint64_t last_frame;
};
std::unordered_map<uint32_t, SlotEntry> g_slot_by_root;
uint32_t g_next_slot = 1;
uint64_t g_slot_frame = ~uint64_t(0);

uint32_t stable_slot(uint32_t root, uint32_t model) {
    const uint64_t f = hh_dl_frame_count();
    if (f != g_slot_frame) {
        g_slot_frame = f;
        if ((f & 127u) == 0) {   // poda periodica de roots muertos
            for (auto it = g_slot_by_root.begin(); it != g_slot_by_root.end();) {
                if ((f - it->second.last_frame) > 8) {
                    it = g_slot_by_root.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }
    auto it = g_slot_by_root.find(root);
    if (it != g_slot_by_root.end() && it->second.model == model &&
        (f - it->second.last_frame) <= 2) {
        it->second.last_frame = f;
        return it->second.slot;
    }
    const uint32_t s = g_next_slot++;
    if (g_next_slot == 0) g_next_slot = 2;
    g_slot_by_root[root] = SlotEntry{ s, model, f };
    return s;
}

// Slot del OBJETO en curso (lo fija el hook del traversal `func_800068C0`). Los grupos se emiten
// por NODO (hook `func_800069A8`, que solo se llama desde ese traversal) y combinan este slot con
// el del nodo: cada hueso empareja por su propia identidad, inmune al orden/numero de transforms.
uint32_t g_obj_slot = 0;

// ---- generacion de camara ---------------------------------------------------------------------

bool camera_read(uint8_t* rdram, float pos[3], float fwd[3]) {
    const uint32_t entity = rd_u32(rdram, kCamBase + kCamEntityOff);
    if (!valid_ram(entity) || entity == 0) {
        return false;
    }
    const uint32_t xform = rd_u32(rdram, entity + kCamTransformOff);
    if (!valid_ram(xform) || xform == 0) {
        return false;
    }
    pos[0] = rd_f32(rdram, xform + kCamPosOff + 0u);
    pos[1] = rd_f32(rdram, xform + kCamPosOff + 4u);
    pos[2] = rd_f32(rdram, xform + kCamPosOff + 8u);
    const float tx = rd_f32(rdram, xform + kCamTargetOff + 0u);
    const float ty = rd_f32(rdram, xform + kCamTargetOff + 4u);
    const float tz = rd_f32(rdram, xform + kCamTargetOff + 8u);

    float dx = tx - pos[0];
    float dy = ty - pos[1];
    float dz = tz - pos[2];
    const float len2 = dx * dx + dy * dy + dz * dz;
    if (!std::isfinite(len2) || len2 < 1e-6f) {
        return false;
    }
    const float inv = 1.0f / std::sqrt(len2);
    fwd[0] = dx * inv;
    fwd[1] = dy * inv;
    fwd[2] = dz * inv;
    return std::isfinite(pos[0]) && std::isfinite(pos[1]) && std::isfinite(pos[2]);
}

bool g_cam_prev_valid = false;
float g_cam_prev_pos[3] = {0.0f, 0.0f, 0.0f};
float g_cam_prev_fwd[3] = {0.0f, 0.0f, 0.0f};
uint64_t g_gen_count = 0;
uint64_t g_object_group_count = 0;

// Pasada 2 (efectos/2D ordenados): cuantas veces se invocan los wrappers. Sirve para saber si esa
// pasada corre en gameplay (en menus no se llama) y si sus `gEXMatrixGroup` materializan en RT64
// (comparar `explicit_ids`/`groups_seen` A/B con HH_FX_PASS2=0/1). Ver `hh_fx_group_count()`.
uint64_t g_fx_group_count = 0;

// Auto-captura: pide guardar el frame cuando hay un corte de camara (1 frame sin interpolar =
// hitch). `update_screen` la consume.
std::atomic<int> g_gen_capture_requested{ 0 };
std::atomic<unsigned long long> g_gen_capture_value{ 0 };

void request_gen_capture() {
    g_gen_capture_value = sGeneration;
    g_gen_capture_requested = 1;
}

void camera_generation_step(uint8_t* rdram) {
    float pos[3], fwd[3];
    const bool ok = camera_read(rdram, pos, fwd);

    if (ok && g_cam_prev_valid) {
        const float dx = pos[0] - g_cam_prev_pos[0];
        const float dy = pos[1] - g_cam_prev_pos[1];
        const float dz = pos[2] - g_cam_prev_pos[2];
        const float dist2 = dx * dx + dy * dy + dz * dz;
        const float dot = fwd[0] * g_cam_prev_fwd[0] + fwd[1] * g_cam_prev_fwd[1] +
                          fwd[2] * g_cam_prev_fwd[2];
        if (dist2 > (kCutDistance * kCutDistance) || dot < kCutMinForwardDot) {
            ++sGeneration;
            ++g_gen_count;
            if (g_trace) {
                hh::log("[hh-interp] corte de camara: gen=%u dist=%.1f dot=%.3f\n", sGeneration,
                        std::sqrt(dist2), dot);
            }
            request_gen_capture();
        }
    } else if (ok && !g_cam_prev_valid) {
        // Primer frame con camara tras uno sin camara (menu/carga): cadena nueva.
        ++sGeneration;
        ++g_gen_count;
        request_gen_capture();
    }

    if (ok) {
        std::memcpy(g_cam_prev_pos, pos, sizeof(pos));
        std::memcpy(g_cam_prev_fwd, fwd, sizeof(fwd));
    }
    g_cam_prev_valid = ok;
    if (sGeneration == 0) {
        sGeneration = 1;
    }
}

// HH_MTXGROUP_LOG=1: inventario de objetos UNICOS taggeados (root, slot, tipo, modelo y los campos
// candidatos a LOD del modelo: +0x40/+0x44/+0x58 y root+0x30). Dedup por root, tope 240. Sirve para
// (a) ver que roots/objetos aparecen durante el gameplay y (b) localizar el campo de LOD.
void trace_object(uint8_t* rdram, uint32_t root, uint32_t slot, uint32_t id, uint16_t type) {
    if (!g_trace) return;
    static uint32_t seen_root[240];
    static uint32_t seen_model[240];
    static int n = 0;
    const uint32_t model0 = rd_u32(rdram, root + 0x2C);
    for (int i = 0; i < n; ++i) {
        if (seen_root[i] != root) continue;
        if (seen_model[i] != model0) {
            // El MISMO puntero de root reaparece con OTRO modelo -> root reciclado. Prueba directa de
            // que la identidad por root no basta (habria que añadir el modelo, que ya va en el hash).
            static int rc = 0;
            if (rc < 40) {
                ++rc;
                hh::log("[hh-mtxgroup] root RECICLADO root=%08X model %08X -> %08X (log %d/40)\n", root,
                        seen_model[i], model0, rc);
                seen_model[i] = model0;
            }
        }
        return;
    }
    if (n >= 240) return;
    seen_root[n] = root;
    seen_model[n] = model0;
    ++n;
    const uint32_t model = model0;
    const uint32_t m40 = valid_ram(model) ? rd_u32(rdram, model + 0x40) : 0;
    const uint32_t m44 = valid_ram(model) ? rd_u32(rdram, model + 0x44) : 0;
    const uint32_t m58 = valid_ram(model) ? rd_u32(rdram, model + 0x58) : 0;
    const uint32_t n30 = rd_u32(rdram, root + 0x30);
    hh::log("[hh-mtxgroup] root=%08X slot=%u type=%u model=%08X m40=%08X m44=%08X m58=%08X n30=%08X id=%08X gen=%u (%d/240)\n",
            root, slot, type, model, m40, m44, m58, n30, id, sGeneration, n);
}

void log_hook_seen() {
    if (!g_trace) return;
    static bool seen = false;
    if (seen) return;
    seen = true;
    hh::log("[hh-mtxgroup] hook OBJETO activo (0x800068C0); HH_MTXGROUP=%s"
            " HOOK_OPCODE=%02X EXT_OPCODE=%02X MAGIC=%06X\n",
            g_enabled ? "ON" : "OFF", (unsigned)RT64_HOOK_OPCODE, (unsigned)RT64_EXTENDED_OPCODE,
            (unsigned)RT64_HOOK_MAGIC_NUMBER);
}

// Frame de juego actual (lo incrementa el port en `send_dl`). Durante el dibujo del frame N vale
// N-1; cambia entre frames, no a mitad. La generacion se evalua UNA vez por frame, en el primer
// objeto: asi todos los grupos del frame comparten la misma generacion.
uint64_t g_cam_last_frame = ~uint64_t(0);

void maybe_update_camera(uint8_t* rdram) {
    const uint64_t f = hh_dl_frame_count();
    if (f == g_cam_last_frame) return;
    g_cam_last_frame = f;
    camera_generation_step(rdram);
}

}  // namespace

// Diagnosticos para [hh-pair]. `total` = grupos de objeto taggeados; `skip` = cortes de camara
// (generaciones avanzadas). Se imprime como `gen=` en rt64_render_context.cpp.
extern "C" unsigned long long hh_mtxgroup_skip_count() { return g_gen_count; }
extern "C" unsigned long long hh_mtxgroup_total_count() { return g_object_group_count; }
// Pasada 2: invocaciones de los wrappers de efectos (0 si HH_FX_PASS2 esta off o no se usan).
extern "C" unsigned long long hh_fx_group_count() { return g_fx_group_count; }

// Consume la peticion de auto-captura por corte de camara (la usa update_screen).
extern "C" int hh_interp_take_capture(unsigned long long* gen) {
    if (g_gen_capture_requested.exchange(0) == 0) {
        return 0;
    }
    if (gen != nullptr) {
        *gen = g_gen_capture_value.load();
    }
    return 1;
}

// Hook del TRAVERSAL de un objeto (`func_800068C0(a0=flags, a1=root DOBJ)`). NO emite grupo: solo
// fija el slot del objeto en curso (identidad) y evalua la camara una vez por frame. Los grupos los
// emite el hook de NODO, que se ejecuta dentro de este traversal.
extern "C" void hh_object_draw_hook(uint8_t* rdram, recomp_context* ctx) {
    log_hook_seen();
    if (!g_enabled) {
        func_800068C0_74C0(rdram, ctx);
        return;
    }

    maybe_update_camera(rdram);

    const uint32_t root = ctx->r5;   // a1 = root DOBJ del objeto
    if (!valid_ram(root) || root == 0) {
        g_obj_slot = 0;
        func_800068C0_74C0(rdram, ctx);
        return;
    }
    const uint32_t model = rd_u32(rdram, root + 0x2C);
    g_obj_slot = stable_slot(root, model);
    trace_object(rdram, root, g_obj_slot, 0, rd_u16(rdram, root + 0x2A));
    func_800068C0_74C0(rdram, ctx);
}

// Hook del DISPATCH de nodo (`func_800069A8(a0=node DOBJ)`, llamado SOLO desde el traversal). UN
// grupo RT64 por NODO: cada hueso/parte empareja por su propia identidad (`slot_objeto`, `slot_nodo`),
// asi el orden y el numero de transforms pueden cambiar sin barajar el esqueleto (lo que hacia el
// grupo por objeto con G_EX_ORDER_LINEAR: huesos del PJ dispersos). Aqui SI se conoce el tipo real
// del nodo (+0x2A): 1..4 son sprites/efectos -> G_EX_ORDER_AUTO (sus piezas aparecen/desaparecen);
// el resto (mallas, huesos) -> LINEAAL.
extern "C" void hh_node_draw_hook(uint8_t* rdram, recomp_context* ctx) {
    if (!g_enabled) {
        func_800069A8_75A8(rdram, ctx);
        return;
    }

    const uint32_t node = ctx->r4;
    if (!valid_ram(node) || node == 0 || g_obj_slot == 0) {
        func_800069A8_75A8(rdram, ctx);
        return;
    }
    const uint16_t ntype = rd_u16(rdram, node + 0x2A);
    // El dispatch solo dibuja tipos 1..13; el 0 (y >13) son contenedores NO-OP: no generan geometria,
    // asi que no tiene sentido envolverlos (solo crean grupos vacios y ruido en la metrica).
    if (ntype < 1 || ntype > 13) {
        func_800069A8_75A8(rdram, ctx);
        return;
    }
    const bool is_fx = (ntype >= 1 && ntype <= 4);   // sprites/efectos (2D/flat) del dispatch

    // Diagnostico: histograma de tipos de nodo dibujados (cada ~2 s). Para identificar que tipo es
    // el efecto 2D que se estira (los tipos 1..4 resultaron NO usarse: `ignored=0`).
    if (g_trace) {
        static uint32_t hist[16] = {};
        static uint64_t hist_frame = 0;
        ++hist[ntype < 16 ? ntype : 0];
        const uint64_t hf = hh_dl_frame_count();
        if ((hf - hist_frame) >= 60) {
            char buf[200];
            int off = 0;
            for (int i = 0; i < 16 && off < 190; ++i) {
                if (hist[i] != 0) {
                    off += std::snprintf(buf + off, sizeof(buf) - off, "%d:%u ", i, hist[i]);
                }
            }
            hh::log("[hh-types] f=%llu %s\n", (unsigned long long)hf, buf);
            for (int i = 0; i < 16; ++i) hist[i] = 0;
            hist_frame = hf;
        }
    }

    // NO se emite `gEXSetRDRAMExtended`: HH usa direcciones KSEG0 y `extendRDRAM=1` rompe el
    // widescreen (rt64_rsp.cpp). El grupo se materializa en el primer G_MTX/G_VTX del draw.
    if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
        gEXEnable(cmd);
    }
    if (is_fx && !g_fx_auto) {
        // 2D/sprite: nunca interpolar (evita el "estirado" al nacer/renacer). §3d.5.
        if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
            gEXMatrixGroupNoInterpolate(cmd, G_EX_PUSH, /*proj=*/0, G_EX_EDIT_NONE);
        }
    } else {
        const uint32_t nmodel = rd_u32(rdram, node + 0x2C);
        const uint32_t node_slot = stable_slot(node, nmodel);
        const uint32_t id = interp_id(/*INTERP_KIND_DOBJ=*/2u, g_obj_slot, node_slot, /*lod=*/0u);
        const uint32_t order = is_fx ? G_EX_ORDER_AUTO : G_EX_ORDER_LINEAR;
        if (GfxCommand* cmd = gfx_emit(rdram, 2)) {
            gEXMatrixGroupDecomposed(cmd, id, G_EX_PUSH, /*proj=*/0,
                                     G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                     G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP,
                                     G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP,
                                     order, G_EX_EDIT_NONE, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_AUTO);
        }
    }

    ++g_object_group_count;
    func_800069A8_75A8(rdram, ctx);

    if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
        gEXPopMatrixGroup(cmd, /*proj=*/0);
    }
}

// ---- pasada 2: objetos ordenados/transparentes (func_80007114 via wrappers) -------------------
//
// La escena se dibuja DOS veces sobre la misma lista: pass 1 (`func_800068C0`) y pass 2 ordenada
// (`func_80006AF0` -> colector `func_80006F8C` de nodos tipo 6 -> wrappers `func_80007328/736C/73AC`
// -> `func_80007114`). El pass 2 estaba SIN taggear: ahi viven los efectos/2D que se estiraban.
namespace {
void fx_wrap(uint8_t* rdram, const char* name, uint32_t node, void (*orig)(uint8_t*, recomp_context*),
             recomp_context* ctx) {
    if (!g_enabled || !valid_ram(node) || node == 0) {
        orig(rdram, ctx);
        return;
    }
    const uint32_t model = rd_u32(rdram, node + 0x2C);
    const uint32_t slot = stable_slot(node, model);
    const uint32_t id = interp_id(/*INTERP_KIND_FX=*/3u, 0u, slot, /*lod=*/0u);
    // Diagnostico del cursor de gfx: la pasada 2 NO emite gfx por si misma (7328/736C/73AC solo
    // calculan la cinta en func_80007114); estos `gEXMatrixGroup` se insertan en el cursor global
    // D_8008D5BC del port. Si `cursor` no avanza (o cae fuera de la DL activa) no materializan.
    const uint32_t cursor_before = rd_u32(rdram, kGfxCursor);
    if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
        gEXEnable(cmd);
    }
    if (GfxCommand* cmd = gfx_emit(rdram, 2)) {
        // Efectos/particulas: orden AUTO (sus piezas aparecen/desaparecen), componentes interpolados
        // salvo skew/persp/vert/tile.
        gEXMatrixGroupDecomposed(cmd, id, G_EX_PUSH, /*proj=*/0,
                                 G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                 G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP,
                                 G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP,
                                 G_EX_ORDER_AUTO, G_EX_EDIT_NONE, G_EX_COMPONENT_SKIP,
                                 G_EX_COMPONENT_AUTO);
    }
    const uint32_t cursor_after = rd_u32(rdram, kGfxCursor);
    ++g_fx_group_count;
    if (g_trace) {
        static int logged = 0;
        if (logged < 60) {
            ++logged;
            hh::log("[hh-fx] %s node=%08X model=%08X slot=%u id=%08X cur=%08X->%08X gen=%u (%d/60)\n",
                    name, node, model, slot, id, cursor_before, cursor_after, sGeneration, logged);
        }
    }
    orig(rdram, ctx);
    if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
        gEXPopMatrixGroup(cmd, /*proj=*/0);
    }
}
}  // namespace

// Wrappers: el nodo va apuntado por a1 (7328) o a0 (736C/73AC).
extern "C" void hh_fx_7328_hook(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t node = valid_ram(ctx->r5) ? rd_u32(rdram, ctx->r5) : 0;
    fx_wrap(rdram, "7328", node, func_80007328_7F28, ctx);
}
extern "C" void hh_fx_736c_hook(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t node = valid_ram(ctx->r4) ? rd_u32(rdram, ctx->r4) : 0;
    fx_wrap(rdram, "736C", node, func_8000736C_7F6C, ctx);
}
extern "C" void hh_fx_73ac_hook(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t node = valid_ram(ctx->r4) ? rd_u32(rdram, ctx->r4) : 0;
    fx_wrap(rdram, "73AC", node, func_800073AC_7FAC, ctx);
}

// ---- [hh-cleanup] EMISORES reales de pasada 2 (traza + tagging de C768) --------------------------
//
// `7328/736C/73AC` solo calculan la cinta: no emiten gfx, asi que un `gEXMatrixGroup` ahi queda sin
// geometria entre push/pop y no taggea. Estos son los candidatos que SI emiten al cursor
// `D_8008D5BC`. Con HH_FX_PASS2=1 se envuelven SOLO para trazar (delta de cursor + a0/a1); no
// modifican nada. El que emita (d>0) en la run es el punto donde hay que enganchar el tagging.
extern "C" void func_8000C768_D368(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80007750_8350(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_800078AC_84AC(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_800079B0_85B0(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80007DE4_89E4(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_800082C4_8EC4(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80008754_9354(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80008B9C_979C(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80008F30_9B30(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8000D1CC_DDCC(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80011958_12558(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8000A828_B428(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8000919C_9D9C(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_8000A06C_AC6C(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80013828_14428(uint8_t* rdram, recomp_context* ctx);

namespace {
// Tope por candidato (no global): los helpers de setup de menú (7750/78AC/79B0) se llaman cada
// frame y si compartieran tope lo consumirían todo antes de llegar al gameplay. `d` = bytes
// emitidos; `vtx/tri/tex` = G_VTX(0x01)/G_TRI(0x05,0x06)/G_TEXRECT(0xE4,0xE5) en F3DEX2.
void emitter_trace(uint8_t* rdram, const char* name, int id, uint32_t node, bool can_tag, bool is2d,
                   void (*orig)(uint8_t*, recomp_context*), recomp_context* ctx) {
    // El tagging dentro de los emisores (rodear con gEXMatrixGroup para cubrir la geometria de sus
    // sub-DL `G_DL`) CONGELABA el render; retirado. Aqui solo se traza.
    (void)node;
    (void)can_tag;
    (void)is2d;
    const uint32_t a0 = ctx->r4, a1 = ctx->r5;
    const uint32_t before = rd_u32(rdram, kGfxCursor);
    orig(rdram, ctx);
    const uint32_t after = rd_u32(rdram, kGfxCursor);
    if (!g_trace || after <= before) {
        return;
    }
    // Rate-limit por funcion (~1 linea/s), no tope global: asi hay muestras tanto en menus como en
    // gameplay y ninguna funcion se agota antes de tiempo.
    static uint64_t last_frame[24] = {};
    const uint64_t f = hh_dl_frame_count();
    if (id < 0 || id >= 24 || (f - last_frame[id]) < 30) {
        return;
    }
    uint32_t hist[256] = {};
    for (uint32_t a = before; a + 8u <= after; a += 8u) {
        ++hist[rd_u32(rdram, a) >> 24];
    }
    const uint32_t vtx = hist[0x01];
    const uint32_t tri = hist[0x05] + hist[0x06] + hist[0xBF];
    const uint32_t tex = hist[0xE4] + hist[0xE5] + hist[0xF6];
    char ops[160];
    int oo = 0;
    for (int i = 0; i < 256; ++i) {
        if (hist[i] == 0) continue;
        const int rem = static_cast<int>(sizeof(ops)) - oo;
        if (rem <= 1) break;
        const int w = std::snprintf(ops + oo, static_cast<size_t>(rem), "%02X:%u ", i, hist[i]);
        if (w < 0) break;
        oo += w;
        if (oo >= static_cast<int>(sizeof(ops))) { oo = static_cast<int>(sizeof(ops)) - 1; break; }
    }
    ops[sizeof(ops) - 1] = '\0';
    last_frame[id] = f;
    hh::log("[hh-emit] %s f=%llu cur=%08X->%08X d=%u vtx=%u tri=%u tex=%u ops=%s a0=%08X a1=%08X\n",
            name, (unsigned long long)f, before, after, after - before, vtx, tri, tex, ops, a0, a1);
}

// [Opción 2] Tagging de la CÁMARA como grupo de PROYECCIÓN. Medido: taggear el modelview del nodo
// (Opción 2a) no quitó el skew y rompió huesos/2D. La cámara va horneada en la matriz de
// vista/proyección que estos emisores cargan con `G_MTX` proyección (`0xDA38...`); lo correcto es
// rodear al emisor con un `gEXMatrixGroup` de PROYECCIÓN (`proj=1`) con un id de CÁMARA ligado a la
// generación (cambia en cada corte). Así RT64 no empareja el viewProj a través del corte
// (`viewProjMap.mapped = matrixId == prev matrixId`) → snap del encuadre, sin tocar los modelview de
// objeto (huesos/efectos intactos). `emitter_trace` (que llama a `orig`) va en medio.
//
// A2.2d: ADEMAS del grupo de PROYECCION, se emite un grupo de MODELVIEW por emisor (el emisor conoce
// su nodo `ctx->r4`), en el MISMO workload que su geometria. Fase de diagnostico (RETOMAR §Plan A2.2d
// paso 2): el id es reconocible por EMISOR y nodo (`0xEE000000 | (id_emisor << 16) | (slot & 0xFFFF)`)
// para localizar en `hh_pairdump.log` que emisor produce los no-emparejados de minas/laser/particulas/
// puertas. Orden AUTO (nunca LINEAR con N transforms). Tras identificar el efecto se cambia a id por
// nodo (`interp_id(2, 0, slot, 0)`) y `G_EX_ID_IGNORE` para los efectos (§A2.2d.3).
void emitter_wrap(uint8_t* rdram, const char* name, int id, uint32_t node, bool can_tag, bool is2d,
                  void (*orig)(uint8_t*, recomp_context*), recomp_context* ctx) {
    const bool base = g_emit_tag && g_enabled && can_tag && valid_ram(node) && node != 0;
    // `7DE4` (id 4) es el emisor de CAMARA (`func_80007DE4_89E4`: guPerspective+guLookAt): recibe el
    // grupo de PROYECCION (una vez por frame, id de camara con generacion). El resto de emisores 3D
    // reciben el de MODELVIEW. Envolver el emisor de camara como modelview hacia que el objeto del
    // menu de titulo "se moviera en coordenadas".
    const bool is_camera = (id == 4);
    const bool tag_proj = base && is_camera && g_emit_proj;       // grupo de PROYECCION (camara)
    const bool tag_mv = base && !is_camera && g_emit_mv && !is2d && !emit_mv_skip(id); // MODELVIEW
    if (tag_proj || tag_mv) {
        if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
            gEXEnable(cmd);
        }
    }
    if (tag_proj) {
        // Id de CÁMARA: misma generacion para todos los nodos del frame; cambia en cada corte.
        const uint32_t camId = interp_id(/*INTERP_KIND_CAM=*/4u, 0u, 0u, 0u);
        if (GfxCommand* cmd = gfx_emit(rdram, 2)) {
            gEXMatrixGroupDecomposed(cmd, camId, G_EX_PUSH, /*proj=*/1,
                                     G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                     G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP,
                                     G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP,
                                     G_EX_ORDER_AUTO, G_EX_EDIT_NONE,
                                     G_EX_COMPONENT_SKIP, G_EX_COMPONENT_AUTO);
        }
    }
    if (tag_mv) {
        // Grupo de MODELVIEW de la geometria que dibuja este emisor. Solo 3D (nunca 2D de menu).
        const uint32_t model = rd_u32(rdram, node + 0x2C);
        const uint32_t slot = stable_slot(node, model);
        // FIX: id por EMISOR+NODO **con generacion de camara**. Antes era `0xEE000000|(id<<16)|
        // (slot&0xFFFF)` (id de diagnostico, SIN generacion): como la camara de HH va horneada en
        // estas matrices, en un corte el id no cambiaba -> RT64 interpolaba la geometria del emisor
        // a traves del corte -> la escena barria. Con `interp_id` (que mezcla `sGeneration`) el id
        // cambia en cada corte y RT64 no empareja (snap), igual que los grupos por nodo.
        const uint32_t mvId = interp_id(/*INTERP_KIND_FX=*/3u, (uint32_t)id, slot, 0u);
        if (GfxCommand* cmd = gfx_emit(rdram, 2)) {
            gEXMatrixGroupDecomposed(cmd, mvId, G_EX_PUSH, /*proj=*/0,
                                     G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                     G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP,
                                     G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP,
                                     G_EX_ORDER_AUTO, G_EX_EDIT_NONE, G_EX_COMPONENT_SKIP,
                                     G_EX_COMPONENT_AUTO);
        }
    }
    emitter_trace(rdram, name, id, node, can_tag, is2d, orig, ctx);
    if (tag_mv) {
        if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
            gEXPopMatrixGroup(cmd, /*proj=*/0);
        }
    }
    if (tag_proj) {
        if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
            gEXPopMatrixGroup(cmd, /*proj=*/1);
        }
    }
}
}  // namespace

// Emisor de tipo 6 `func_8000C768` (draw de la cinta/efecto); enlaza su geometria en sub-DLs
// (`G_DL`). Medido (nota 2026-10-04 §2): es el UNICO emisor que MATERIALIZA su `gEXMatrixGroup`
// (su geometria va en el mismo workload). Gate unificado `HH_EMIT_TAG=1` (o `HH_FX_EMIT=1`). Para el
// diagnostico A2.2d usa el id reconocible por emisor (codigo 15 -> `EEF0xxxx`).
extern "C" void hh_emit_c768_hook(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t node = ctx->r4;
    // Solo la ruta del EMISOR de efectos real: recibe el cursor de gfx `kGfxCursor` en a1. En el menu
    // de titulo, C768 se llama con otro `a1` (p. ej. `FF868DA5`) y envolverlo como modelview hacia
    // que el objeto 3D del titulo "se moviera en coordenadas" (medido 2026-10-05). Gatear por cursor
    // arregla el titulo sin perder el tagging de efectos en gameplay.
    const bool cursor_path = (static_cast<uint32_t>(ctx->r5) == kGfxCursor);
    const bool emit = g_emit_tag && g_emit_mv && g_enabled && valid_ram(node) && node != 0 &&
                      !emit_mv_skip(15) && cursor_path;
    if (emit) {
        if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
            gEXEnable(cmd);
        }
        const uint32_t model = rd_u32(rdram, node + 0x2C);
        const uint32_t slot = stable_slot(node, model);
        // FIX: id con generacion de camara (antes `0xEEF0xxxx`, diagnostico sin `sGeneration` -> la
        // geometria del emisor se interpolaba a traves de los cortes de camara).
        const uint32_t iid = interp_id(/*INTERP_KIND_FX=*/3u, 15u, slot, 0u);
        if (GfxCommand* cmd = gfx_emit(rdram, 2)) {
            gEXMatrixGroupDecomposed(cmd, iid, G_EX_PUSH, /*proj=*/0,
                                     G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_INTERPOLATE,
                                     G_EX_COMPONENT_INTERPOLATE, G_EX_COMPONENT_SKIP,
                                     G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP, G_EX_COMPONENT_SKIP,
                                     G_EX_ORDER_AUTO, G_EX_EDIT_NONE, G_EX_COMPONENT_SKIP,
                                     G_EX_COMPONENT_AUTO);
        }
    }
    emitter_trace(rdram, "C768", 0, node, /*can_tag=*/true, /*is2d=*/false, func_8000C768_D368, ctx);
    if (emit) {
        if (GfxCommand* cmd = gfx_emit(rdram, 1)) {
            gEXPopMatrixGroup(cmd, /*proj=*/0);
        }
    }
}
extern "C" void hh_emit_7750_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_trace(rdram, "7750", 1, 0, /*can_tag=*/false, false, func_80007750_8350, ctx);
}
extern "C" void hh_emit_78ac_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_trace(rdram, "78AC", 2, 0, /*can_tag=*/false, false, func_800078AC_84AC, ctx);
}
extern "C" void hh_emit_79b0_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_trace(rdram, "79B0", 3, 0, /*can_tag=*/false, false, func_800079B0_85B0, ctx);
}
extern "C" void hh_emit_7de4_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_wrap(rdram, "7DE4", 4, ctx->r4, /*can_tag=*/true, /*is2d=*/false, func_80007DE4_89E4, ctx);
}
extern "C" void hh_emit_82c4_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_wrap(rdram, "82C4", 5, ctx->r4, /*can_tag=*/true, /*is2d=*/false, func_800082C4_8EC4, ctx);
}
extern "C" void hh_emit_8754_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_wrap(rdram, "8754", 6, ctx->r4, /*can_tag=*/true, /*is2d=*/false, func_80008754_9354, ctx);
}
extern "C" void hh_emit_8b9c_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_wrap(rdram, "8B9C", 7, ctx->r4, /*can_tag=*/true, /*is2d=*/false, func_80008B9C_979C, ctx);
}
extern "C" void hh_emit_8f30_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_wrap(rdram, "8F30", 8, ctx->r4, /*can_tag=*/true, /*is2d=*/false, func_80008F30_9B30, ctx);
}
extern "C" void hh_emit_d1cc_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_wrap(rdram, "D1CC", 9, ctx->r4, /*can_tag=*/true, /*is2d=*/false, func_8000D1CC_DDCC, ctx);
}
extern "C" void hh_emit_11958_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_trace(rdram, "11958", 10, ctx->r4, /*can_tag=*/true, /*is2d=*/true, func_80011958_12558, ctx);
}
extern "C" void hh_emit_a828_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_trace(rdram, "A828", 11, ctx->r4, /*can_tag=*/true, /*is2d=*/false, func_8000A828_B428, ctx);
}
extern "C" void hh_emit_919c_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_trace(rdram, "919C", 12, ctx->r4, /*can_tag=*/true, /*is2d=*/true, func_8000919C_9D9C, ctx);
}
extern "C" void hh_emit_a06c_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_wrap(rdram, "A06C", 13, ctx->r4, /*can_tag=*/true, /*is2d=*/false, func_8000A06C_AC6C, ctx);
}
extern "C" void hh_emit_13828_hook(uint8_t* rdram, recomp_context* ctx) {
    emitter_wrap(rdram, "13828", 14, ctx->r4, /*can_tag=*/true, /*is2d=*/false, func_80013828_14428, ctx);
}
