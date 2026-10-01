// hh_saveedit — editor de partida. Ver include/hh/save_edit.h y
// notes/2026-09-27-e-editor-partida-plan.md.
//
// Estrategia (v3, 2026-09-27): editar el SLOT del `.pak` (el fichero de guardado que CONTINUE lee),
// no los globals del juego (que se pisan al arrancar/cargar). El layout del slot es el medido
// comparando `.pak` reales (ver nota): cabecera 0x100 + 4 slots 0xD00; checksum en +0xCFC.
//   - PROGRESO  u16 BE en +0x366 (N*10+P)
//   - NIVEL     u8     en +0x04B
//   - TÉCNICAS  86 x 3 en +0x09E (flag aprendida = byte +0 de cada entrada)
//   - ITEMS     45 x u8 en +0x1A0 (cantidad)
//   - STATS del PJ (bloque de 6 partes, u16 BE): offense +0x010, defense +0x01C, hit +0x068,
//     damage +0x076 (mapa del struct 0x8017DC40). El orden de partes es el del juego.
// Tras guardar se fuerza la recarga del `.pak` del runtime (hh_pak_reload_from_disk, fork NMR).

#include "hh.h"
#include "hh/menu.h"       // area_sub_from_value() para la cabecera del guardado
#include "hh/save_edit.h"

#include <algorithm>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <map>
#include <vector>

#include "recomp.h"

// Fork NMR (9b14604): descarta el pak cacheado del runtime y lo relee del disco. Tras escribir el
// `.pak` hay que llamarlo, o el juego (CONTINUAR, previsualizacion de slots) seguira leyendo el
// `g_pak` viejo en RAM (pak.cpp cachea el fichero en `g_pak` la primera vez).
extern "C" void hh_pak_reload_from_disk(void);

// Heap del juego (libultra) y serializador NATIVO del slot: `func_80141F28(buffer_0xD00)` vuelca los
// globals VIVOS (personaje, técnicas, items, progreso/escena) al buffer en el MISMO layout de disco
// que `osPfsReadWriteFile` escribiría. `func_80142450(slot)` = alloc(0xD00) + func_80141F28 + PFS
// write; aquí replicamos solo alloc/serialize/free para que la escritura la siga haciendo hh::save
// (un único dueño del `.pak`, con checksums/cabecera/trailer coherentes).
extern "C" void func_8001F430_20030(uint8_t* rdram, recomp_context* ctx);    // alloc(0xD00) -> v0
extern "C" void func_8001F540_20140(uint8_t* rdram, recomp_context* ctx);    // free(ptr)
extern "C" void func_80141F28_103A6F8(uint8_t* rdram, recomp_context* ctx);  // serializa globals
// Área/sub de la cabecera de guardado: `func_80141268` (flujo GUARDAR nativo) hace
// `d[2] = func_80108280() >> 8`; es la MISMA fuente que usa el juego (los saves nativos salen 1-1).
extern "C" void func_80108280_1000A50(uint8_t* rdram, recomp_context* ctx);

namespace hh::save {
namespace {

constexpr size_t kDataOff = 0x1B;      // en el `.pak`
constexpr size_t kHeaderSize = 0x100;
constexpr size_t kSlotSize = 0xD00;
constexpr size_t kSlot0 = kDataOff + kHeaderSize;

// Metadatos por slot (Fase 1, 2026-09-29): la cabecera del juego (`0x100`) solo tiene sitio para
// 30 registros (`(0x100-0x10)/8`), así que para N=64 añadimos un **trailer** de N registros de 8 B
// DESPUÉS de los slots (dentro del fichero PFS). `func_801423C8` lee offsets fijos `0x100+slot*0xD00`
// -> el trailer no le afecta. Layout del registro idéntico al de la cabecera.
constexpr size_t kMetaRecord = 8;
constexpr size_t kHeaderRecords = (kHeaderSize - 0x10) / 8;   // 30
constexpr size_t kMetaOff = kSlot0 + static_cast<size_t>(kSlots) * kSlotSize;
constexpr size_t kFileDataSize = kHeaderSize + static_cast<size_t>(kSlots) * kSlotSize +
                                 static_cast<size_t>(kSlots) * kMetaRecord;
constexpr size_t kContainerSize = kDataOff + kFileDataSize;
constexpr size_t kPakSizeOff = 0x17;   // u32 LE: size del fichero PFS en el HHPK (tras HHPK+count)

// Offsets DENTRO del slot.
// NIVEL: u16 little-endian en +0x04A (byte bajo en 0x4A, alto en 0x4B). Antes se trataba como u8
// en 0x4B: escribir ahi dejaba el byte bajo intacto (0x01) y el display del juego combinaba
// 0x4A|0x4B<<8 -> p. ej. 0x1201 = 4609. Ver notes/2026-09-28-editor-partida-offsets-reales.md.
constexpr size_t kLevelOff = 0x04A;
constexpr size_t kTechOff = 0x09E;      // 86 x 3
constexpr size_t kItemOff = 0x1A0;      // 45 x u8
// PROGRESO (indice de escena / Area-Parte): `[MEDIDO/VALIDADO 2026-09-29]` vive en **0x564** como
// u16 LITTLE-ENDIAN. El deserializador lo vuelca a `glob 0x801BBBF0[+4]`, que es el valor que el
// cargador de escena usa (`func_8012FE50` -> `func_80125968`). Verificado headless: escribir 0x564
// (LE) en un slot 1-1 y cargar cambia `[+4]`. NO es 0x366 (aquel no mueve el mapa).
// Formula medida (3 puntos reales): `valor = (area-1)*10 + (sub-1)*2` con `sub` 1-based de los puntos
// de guardado (1-1->0, 1-2->2, 2-1->10). 1-0/2-0 son inicios (no guardables).
constexpr size_t kProgressOff = 0x564;  // u16 LE (indice de escena / Area-Parte)
constexpr size_t kProgressOldOff = 0x366;  // u16 BE: campo gemelo legado; se mantiene sincronizado
constexpr size_t kChecksumOff = 0xCFC;
// Stats por parte (contadores de uso, u16): offsets RUNTIME (los de func_8022C7A4 / struct
// 0x8017DC40). El SAVE va **32-bit word-swapped** respecto al runtime (confirmado por el mantenedor:
// OFENSIVO/DEFENSIVO y VELOCIDAD/REFLEJO salen invertidos, y los contadores por parejas de partes
// cabeza<->cuerpo, brazo izq<->der). Regla: el campo runtime de offset `r` vive en el save en
// `swap16(r)` (u16) o `swap8(r)` (u8). Ver notes/2026-09-28-stats-recompute-correccion.md §7.
constexpr size_t swap16(size_t r) { return r ^ 2; }
constexpr size_t swap8(size_t r) { return r ^ 3; }
constexpr size_t kOffenseOff = 0x010;
constexpr size_t kDefenseOff = 0x01C;
constexpr size_t kHitOff = 0x068;
constexpr size_t kDamageOff = 0x076;

// Por parte (índice 0..5 = func_80378D84/80376D48): stat / nivel / progreso (offsets RUNTIME).
//   parte0=HP, 1=STAMINA, 2=OFFENSE, 3=DEFENSE, 4=REFLEX, 5=SPEED.
constexpr size_t kPartStatRuntime[kParts] = {0x00, 0x08, 0x40, 0x42, 0x46, 0x44};
constexpr size_t kPartLevelRuntime[kParts] = {0x04, 0x0A, 0x52, 0x53, 0x55, 0x54};
constexpr size_t kPartProgRuntime[kParts] = {0x06, 0x0C, 0x4A, 0x4C, 0x50, 0x4E};

// Tablas de incremento por nivel (u16, `0x80388410+`) — `incremento[nivel]` al subir a nivel+1.
static const uint16_t kIncHP[99] = {5,10,10,15,15,15,20,20,20,20,25,25,25,25,25,30,30,30,30,30,35,35,35,35,35,40,40,40,40,40,45,45,45,45,45,50,50,50,50,50,55,55,55,55,55,60,60,60,60,60,65,65,65,65,65,70,70,70,70,70,75,75,75,75,75,80,80,80,80,80,85,85,85,85,85,90,90,90,90,90,95,95,95,95,95,100,100,100,100,100,105,105,105,105,105,110,110,110,110};
static const uint16_t kIncStamina[99] = {2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8,10,10,10,10,10,10,10,10,10,10,12,12,12,12,12,12,12,12,12,12,14,14,14,14,14,14,14,14,14,14,16,16,16,16,16,16,16,16,16,16,18,18,18,18,18,18,18,18,18,18,20,20,20,20,20,20,20,20,20,20};
static const uint16_t kIncOffense[99] = {36,8,8,6,7,6,6,5,6,6,5,6,5,5,6,5,6,5,6,5,6,6,6,6,6,6,6,6,7,6,7,6,7,7,7,7,8,7,8,8,8,8,8,9,9,9,9,9,9,10,10,10,11,10,11,11,12,11,12,12,13,1,1,1,2,2,3,5,5,6,7,9,11,12,14,17,19,22,25,29,33,37,42,48,54,61,68,76,87,96,108,121,135,151,169,188,209,233,260};
static const uint16_t kIncDefense[99] = {24,6,6,4,5,4,4,5,4,4,4,4,4,4,4,4,5,4,4,5,4,5,4,5,5,5,5,5,5,6,5,6,6,6,6,6,6,7,7,6,8,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,12,12,12,13,13,13,14,14,15,1,1,2,2,4,5,6,8,10,11,15,17,20,25,28,33,39,46,52,61,70,80,93,106,122,139,159,181,207,235,268,304};
static const uint16_t kIncReflex[99] = {4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,2,1,2,2,1,2,2,2,2,2,2,3,2,2,3,3,2,3,3,3,3,3,4,3,4,4,4,4,4,5,4,5,5,5,6,5,6,6,6,7,7,7,7,7,8,9,8,9,9,10,10,10,11,11,11,12,13,13,13,14,15,15,16,16,17,18,18,19};
static const uint16_t kIncSpeed[99] = {10,5,5,6,6,6,6,7,7,7,7,8,8,8,9,9,9,10,10,11,11,11,12,12,13,13,14,15,15,15,17,16,18,18,19,20,20,22,22,23,24,25,26,27,28,29,31,31,33,34,36,37,38,40,42,43,45,47,49,50,53,54,57,60,61,64,67,69,72,75,78,81,84,88,91,94,99,102,107,111,115,120,125,129,135,141,145,152,158,164,171,177,185,192,199,208,216,224,234};
static const uint16_t* const kIncByPart[kParts] = {kIncHP, kIncStamina, kIncOffense,
                                                   kIncDefense, kIncReflex, kIncSpeed};

// Tablas de UMBRAL (EXP acumulada, u16) por nivel. `progreso >= umbral[nivel]` -> sube de nivel.
static const uint16_t kThrHP[99] = {2,3,5,6,8,10,12,14,16,19,21,24,28,31,35,39,44,49,54,60,67,74,81,90,99,109,120,132,144,159,174,191,209,229,250,274,300,328,358,391,428,467,510,557,609,664,725,792,864,943,1029,1122,1224,1336,1457,1589,1733,1890,2061,2248,2451,2673,2915,3178,3465,3778,4119,4491,4896,5338,5820,6344,6916,7540,8220,8961,9768,10648,11608,12653,13793,15036,16390,17866,19475,21229,23141,25224,27496,29971,32670,35611,38817,42312,46121,50273,54798,59731,65108};
static const uint16_t kThrStamina[99] = {11,17,23,30,38,46,54,63,73,83,95,107,119,133,148,163,180,198,217,237,259,283,308,335,363,394,427,462,500,540,583,629,678,731,788,848,913,982,1056,1135,1220,1311,1408,1512,1623,1742,1869,2005,2151,2306,2473,2652,2842,3047,3265,3499,3749,4017,4304,4610,4938,5289,5665,6066,6496,6956,7449,7975,8539,9142,9787,10477,11216,12006,12852,13757,14725,15762,16870,18056,19326,20684,22137,23692,25355,27136,29040,31078,33259,35593,38089,40761,43620,46678,49951,53453,57200,61209,65499};
static const uint16_t kThrOffense[99] = {51,79,108,139,171,204,240,277,316,357,400,445,492,542,594,649,706,767,830,897,966,1040,1117,1198,1283,1372,1466,1564,1668,1776,1890,2010,2135,2267,2405,2551,2704,2864,3032,3209,3394,3589,3794,4008,4234,4471,4719,4981,5255,5542,5845,6162,6495,6845,7212,7598,8003,8428,8875,9344,9836,10353,10896,11466,12064,12692,13352,14045,14772,15536,16338,17180,18064,18992,19967,20990,22065,23193,24378,25622,26928,28300,29740,31252,32839,34506,36257,38095,40025,42051,44179,46413,48758,51221,53808,56523,59374,62368,65512};
static const uint16_t kThrDefense[99] = {24,37,51,65,81,97,115,133,153,174,196,219,244,270,298,327,359,392,427,464,503,545,589,636,686,739,795,854,917,984,1054,1129,1209,1293,1382,1476,1576,1683,1795,1915,2041,2175,2317,2468,2627,2797,2976,3166,3368,3582,3808,4048,4303,4572,4858,5161,5483,5823,6184,6567,6973,7403,7858,8341,8853,9396,9972,10582,11228,11913,12640,13410,14226,15091,16008,16980,18011,19103,20261,21488,22789,24168,25629,27179,28821,30562,32407,34363,36436,38634,40964,43433,46051,48826,51767,54884,58189,61692,65405};
static const uint16_t kThrReflex[99] = {5,8,11,14,17,21,25,30,34,40,45,51,58,65,72,80,89,99,109,120,132,145,159,174,190,208,227,247,270,294,319,347,378,410,445,483,524,569,617,668,724,784,850,920,996,1078,1167,1262,1366,1477,1598,1728,1869,2020,2184,2362,2553,2760,2983,3224,3484,3765,4069,4396,4751,5133,5546,5992,6474,6994,7556,8163,8818,9526,10291,11116,12008,12971,14011,15134,16347,17657,19072,20601,22251,24033,25959,28038,30283,32708,35327,38156,41210,44510,48073,51921,56077,60566,65413};
static const uint16_t kThrSpeed[99] = {108,165,225,287,351,418,487,560,635,713,795,880,968,1059,1155,1254,1357,1464,1575,1691,1812,1937,2067,2203,2344,2491,2643,2802,2967,3138,3317,3502,3695,3896,4105,4322,4548,4783,5027,5281,5545,5820,6105,6402,6711,7033,7367,7715,8076,8452,8843,9250,9673,10112,10570,11045,11540,12055,12590,13146,13725,14327,14953,15604,16281,16985,17717,18479,19271,20095,20951,21842,22769,23733,24735,25777,26861,27988,29161,30380,31648,32967,34339,35765,37249,38792,40396,42065,43800,45605,47482,49435,51465,53576,55772,58056,60431,62901,65470};
static const uint16_t* const kThrByPart[kParts] = {kThrHP, kThrStamina, kThrOffense,
                                                   kThrDefense, kThrReflex, kThrSpeed};

// Fila 0 de `0x8023C940` (id 81 = jugador): reward de EXP y tope de la referencia por atributo.
// Orden de parte 0..5 = HP, STAMINA, OFFENSE, DEFENSE, REFLEX, SPEED.
static const uint16_t kRewardByPart[kParts] = {1, 2, 20, 14, 1, 10};
// transformada de ref: 0=HP(×120/100),1=STAM(+0),2=OFF(DEF×84/100),3=DEF(OFF×100/100),
//                       4=REF(+0),5=SPD(-15).  tope por parte:
static const int kRefCap[kParts] = {300, 200, 160, 150, 120, 280};

// Nombres (RDRAM, modulo 8).
constexpr uint32_t kTechNamePtrs = 0x80184140;
constexpr uint32_t kItemNamePtrs = 0x8017DF50;
constexpr uint32_t kItemNameRecs = 0x8017E004;   // registros de item (u32 ptr nombre + u32 count)
constexpr uint32_t kSceneTable = 0x80175490;

std::vector<uint8_t> g_bytes;      // contenido completo del `.pak`
std::vector<uint8_t> g_baseline;   // copia del `.pak` al cargar (origen de RESTAURAR)
std::filesystem::path g_path;
bool g_loaded = false;

// Pila de deshacer de SIM. COMBATE: un snapshot por cada combate SIMULADO (estado PRE-combate). Al
// simular en negativo (-N) se restauran los últimos N snapshots, deshaciendo EXACTAMENTE los combates
// simulados (la fórmula depende de la stat, así que no es simétrica sin guardar el estado). Se guarda
// por slot; se pierde al cerrar el port (es una ayuda de edición, no parte del save).
struct SimSnap {
    uint8_t level[kParts];
    uint16_t prog[kParts];
    uint16_t stat[kParts];
    uint16_t hpmax;
};
std::map<int, std::vector<SimSnap>> g_sim_undo;

size_t slot_off(int slot) { return kSlot0 + static_cast<size_t>(slot) * kSlotSize; }
size_t meta_off(int slot) { return kMetaOff + static_cast<size_t>(slot) * kMetaRecord; }
bool in_slot(size_t rel, size_t n) { return rel + n <= kSlotSize; }

// Acceso al trailer de metadatos (independiente de g_loaded: lo usan también los getters de la UI).
uint8_t meta_rd(int slot, size_t rel) {
    if (slot < 0 || slot >= kSlots) return 0;
    const size_t o = meta_off(slot) + rel;
    return o < g_bytes.size() ? g_bytes[o] : 0;
}
void meta_wr(int slot, size_t rel, uint8_t v) {
    if (slot < 0 || slot >= kSlots) return;
    const size_t o = meta_off(slot) + rel;
    if (o < g_bytes.size()) g_bytes[o] = v;
}
// Fija el `size` del fichero PFS en el registro del contenedor HHPK (para que el PFS del runtime lea
// los N slots; si no, `pak_load` corta al size viejo).
void set_pak_file_size() {
    if (g_bytes.size() < kPakSizeOff + 4) return;
    const uint32_t v = static_cast<uint32_t>(kFileDataSize);
    g_bytes[kPakSizeOff + 0] = static_cast<uint8_t>(v & 0xFF);
    g_bytes[kPakSizeOff + 1] = static_cast<uint8_t>((v >> 8) & 0xFF);
    g_bytes[kPakSizeOff + 2] = static_cast<uint8_t>((v >> 16) & 0xFF);
    g_bytes[kPakSizeOff + 3] = static_cast<uint8_t>((v >> 24) & 0xFF);
}

uint8_t rd8(int slot, size_t rel) {
    if (!g_loaded || slot < 0 || slot >= kSlots || !in_slot(rel, 1)) return 0;
    return g_bytes[slot_off(slot) + rel];
}
void wr8(int slot, size_t rel, uint8_t v) {
    if (!g_loaded || slot < 0 || slot >= kSlots || !in_slot(rel, 1)) return;
    g_bytes[slot_off(slot) + rel] = v;
}
uint16_t rd16(int slot, size_t rel) { return static_cast<uint16_t>((rd8(slot, rel) << 8) | rd8(slot, rel + 1)); }
void wr16(int slot, size_t rel, uint16_t v) {
    wr8(slot, rel, static_cast<uint8_t>(v >> 8));
    wr8(slot, rel + 1, static_cast<uint8_t>(v & 0xFF));
}
// El bloque del PERSONAJE del slot es u16 LITTLE-ENDIAN (medido: HP=0x6400 -> bytes 64 00 = 100;
// OFFENSE 32 00 = 50; contadores de parte 01 00 = 1). Leerlo como BE daba 0x0100 = 256. Las secciones
// de progreso/escena SI van BE (ver rd16/wr16); de ahi el uso de helpers separados.
uint16_t rd16le(int slot, size_t rel) { return static_cast<uint16_t>(rd8(slot, rel) | (rd8(slot, rel + 1) << 8)); }
void wr16le(int slot, size_t rel, uint16_t v) {
    wr8(slot, rel, static_cast<uint8_t>(v & 0xFF));
    wr8(slot, rel + 1, static_cast<uint8_t>(v >> 8));
}

// RDRAM del guest (para nombres y tabla de escenas).
uint8_t* g_rdram = nullptr;
uint8_t* mem() {
    if (g_rdram == nullptr) g_rdram = hh::get_game_rdram();
    return g_rdram;
}
uint8_t grd8(uint32_t addr) {
    uint8_t* r = mem();
    if (r == nullptr || addr < 0x80000000u) return 0;
    return r[(addr - 0x80000000u) ^ 3u];
}
uint32_t guest_u32(uint32_t addr) {
    return (static_cast<uint32_t>(grd8(addr)) << 24) | (static_cast<uint32_t>(grd8(addr + 1)) << 16) |
           (static_cast<uint32_t>(grd8(addr + 2)) << 8) | static_cast<uint32_t>(grd8(addr + 3));
}
std::string guest_str(uint32_t addr, size_t max_len = 40) {
    std::string out;
    bool hi = false;
    for (size_t i = 0; i < max_len; ++i) {
        const uint8_t c = grd8(addr + static_cast<uint32_t>(i));
        if (c == 0) break;
        if (c >= 0x80) { if (!hi) { out.push_back(' '); hi = true; } }
        else { out.push_back(static_cast<char>(c)); hi = false; }
    }
    return out;
}

std::filesystem::path find_pak() {
    std::error_code ec;
    const std::filesystem::path dir = hh::get_app_folder_path() / "saves";
    if (!std::filesystem::exists(dir, ec)) return {};
    for (const auto& e : std::filesystem::directory_iterator(dir, ec)) {
        if (e.is_regular_file(ec) && e.path().extension() == ".pak") return e.path();
    }
    return {};
}

// Actualiza la CABECERA de la lista de partidas (AREA/LEVEL) del slot editado. La cabecera va
// bswap32 (el magic "HYBRID HEAVEN" solo aparece al revertir palabras); su checksum es
// `sum[0..0xFE]` en `0xFF`, sobre el buffer ya revertido. Registro del slot i = 0x10 + i*8:
// +0 presente, +1 AREA N, +2 AREA P, +3 LEVEL, +4..5 TIME (se conserva). Ver
// notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md.
void bswap_header_in_place() {
    uint8_t* h = g_bytes.data() + kDataOff;
    for (size_t i = 0; i + 3 < kHeaderSize; i += 4) {
        std::swap(h[i], h[i + 3]);
        std::swap(h[i + 1], h[i + 2]);
    }
}
// El magic se guarda word-swapped ("RBYH…"); hay que revertir para comprobarlo. Se deja el buffer
// como estaba (se vuelve a revertir), para no alterar el orden del fichero en memoria.
bool header_magic_ok() {
    if (g_bytes.size() < kDataOff + kHeaderSize) return false;
    bswap_header_in_place();
    const bool ok = std::memcmp(g_bytes.data() + kDataOff, "HYBRID HEAVEN", 13) == 0;
    bswap_header_in_place();
    return ok;
}

// Migra la cabecera del juego (solo slots 0..29) al trailer de metadatos. La cabecera es la fuente
// más fresca para esos slots (la escribe el propio juego al guardar); el editor escribe ambas.
void sync_meta_from_header() {
    if (!header_magic_ok()) return;
    bswap_header_in_place();
    uint8_t* h = g_bytes.data() + kDataOff;
    if (std::memcmp(h, "HYBRID HEAVEN", 13) != 0) { bswap_header_in_place(); return; }
    for (size_t s = 0; s < kHeaderRecords; ++s) {
        const size_t rec = 0x10 + s * 8;
        for (size_t i = 0; i < kMetaRecord; ++i) meta_wr(static_cast<int>(s), i, h[rec + i]);
    }
    bswap_header_in_place();
}

// Escribe el registro del slot en la cabecera del juego (solo 0..29) y en el trailer (todos).
// `area`/`sub` >= 0 los fija el llamante (cápsula: de `func_80108280`); < 0 se derivan de
// `PROGRESO` (`0x366`, u16 BE) = `area*10+sub`. `time` >= 0 fija TIME (u16, segundos); < 0 lo conserva.
void update_save_header(int slot, int area = -1, int sub = -1, int time = -1, int difficulty = -1) {
    if (!g_loaded || slot < 0 || slot >= kSlots || g_bytes.size() < kContainerSize) return;
    if (area < 0 || sub < 0) {
        const uint16_t prog = rd16(slot, kProgressOldOff);
        area = (prog / 10) & 0xFF;
        sub = (prog % 10) & 0xFF;
    }
    area &= 0xFF;
    sub &= 0xFF;
    const uint16_t lvl = static_cast<uint16_t>(global_level_of(slot));   // DERIVADO de las partes
    // Trailer: presente/AREA/LEVEL (+ TIME si se pasa).
    meta_wr(slot, 0, 1);
    meta_wr(slot, 1, static_cast<uint8_t>(area));
    meta_wr(slot, 2, static_cast<uint8_t>(sub));
    meta_wr(slot, 3, static_cast<uint8_t>(lvl > 255 ? 255 : lvl));
    if (time >= 0) {
        meta_wr(slot, 4, static_cast<uint8_t>((time >> 8) & 0xFF));
        meta_wr(slot, 5, static_cast<uint8_t>(time & 0xFF));
    }
    // Dificultad (0=NORMAL, 1=HARD, 2=ULTIMATE): byte +7. No se toca si `difficulty` < 0.
    if (difficulty >= 0) meta_wr(slot, 7, static_cast<uint8_t>(difficulty & 0xFF));
    // Cabecera del juego (compatibilidad mientras el DATA LOAD nativo siga existiendo).
    if (slot < static_cast<int>(kHeaderRecords) && header_magic_ok()) {
        bswap_header_in_place();
        uint8_t* h = g_bytes.data() + kDataOff;
        const size_t rec = 0x10 + static_cast<size_t>(slot) * 8;
        h[rec + 0] = 1;
        h[rec + 1] = static_cast<uint8_t>(area);
        h[rec + 2] = static_cast<uint8_t>(sub);
        h[rec + 3] = static_cast<uint8_t>(lvl > 255 ? 255 : lvl);
        if (time >= 0) {
            h[rec + 4] = static_cast<uint8_t>((time >> 8) & 0xFF);
            h[rec + 5] = static_cast<uint8_t>(time & 0xFF);
        }
        if (difficulty >= 0) h[rec + 7] = static_cast<uint8_t>(difficulty & 0xFF);
        unsigned sum = 0;
        for (size_t i = 0; i < 0xFF; ++i) sum += h[i];
        h[0xFF] = static_cast<uint8_t>(sum & 0xFF);
        bswap_header_in_place();
    }
    hh::log("[save-edit] cabecera: slot %d -> AREA %d-%d LEVEL %u TIME %d\n", slot, area, sub,
            (unsigned)lvl, time);
}

// Marca el registro del slot como NO presente (para ELIMINAR) en cabecera (0..29) y trailer.
void clear_save_header_record(int slot) {
    if (slot < 0 || slot >= kSlots) return;
    for (size_t i = 0; i < kMetaRecord; ++i) meta_wr(slot, i, 0);
    if (slot < static_cast<int>(kHeaderRecords) && header_magic_ok()) {
        bswap_header_in_place();
        uint8_t* h = g_bytes.data() + kDataOff;
        const size_t rec = 0x10 + static_cast<size_t>(slot) * 8;
        for (size_t i = 0; i < 8; ++i) h[rec + i] = 0;
        unsigned sum = 0;
        for (size_t i = 0; i < 0xFF; ++i) sum += h[i];
        h[0xFF] = static_cast<uint8_t>(sum & 0xFF);
        bswap_header_in_place();
    }
    hh::log("[save-edit] cabecera: slot %d -> NO presente\n", slot);
}

}  // namespace

bool load(int slot, uint8_t* rdram, recomp_context* base_ctx) {
    (void)slot; (void)rdram; (void)base_ctx;
    if (g_loaded) return true;
    g_path = find_pak();
    if (g_path.empty()) { hh::log("[save-edit] no hay .pak en saves/\n"); return false; }
    std::ifstream in(g_path, std::ios::binary);
    if (!in) return false;
    g_bytes.assign((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    if (g_bytes.size() < kDataOff + kHeaderSize || std::memcmp(g_bytes.data(), "HHPK", 4) != 0) {
        hh::log("[save-edit] .pak invalido (%zu B)\n", g_bytes.size());
        g_bytes.clear();
        return false;
    }
    // Normaliza al layout de N slots + trailer: migra `.pak` de 4 slots (rellena a cero) y recorta
    // cualquier exceso. Fija el `size` del fichero PFS en el registro HHPK para que el runtime lea N.
    if (g_bytes.size() < kContainerSize) {
        g_bytes.resize(kContainerSize, 0);
    } else if (g_bytes.size() > kContainerSize) {
        g_bytes.resize(kContainerSize);
    }
    set_pak_file_size();
    g_loaded = true;
    sync_meta_from_header();   // cabecera del juego (0..29) -> trailer
    g_baseline = g_bytes;
    hh::log("[save-edit] .pak cargado (%zu B, %d slots)\n", g_bytes.size(), kSlots);
    return true;
}

// RESTAURAR: devuelve el slot al estado que tenia el `.pak` al abrirlo (in-memory; GUARDAR lo escribe).
void restore_slot(int slot) {
    if (!g_loaded || g_baseline.size() != g_bytes.size() || slot < 0 || slot >= kSlots) return;
    const size_t base = slot_off(slot);
    std::copy(g_baseline.begin() + base, g_baseline.begin() + base + kSlotSize, g_bytes.begin() + base);
    const size_t m = meta_off(slot);
    std::copy(g_baseline.begin() + m, g_baseline.begin() + m + kMetaRecord, g_bytes.begin() + m);
    g_sim_undo.erase(slot);   // el estado cambió: la pila de deshacer de la sim ya no aplica
    hh::log("[save-edit] RESTAURAR slot %d (estado al cargar)\n", slot);
}

// ELIMINAR: vacía el slot entero (todo 0) y marca su registro de cabecera como no presente. Que
// quede efectivo en el fichero requiere GUARDAR (recalcula checksums y escribe el `.pak`).
void delete_slot(int slot) {
    if (!g_loaded || slot < 0 || slot >= kSlots) return;
    const size_t base = slot_off(slot);
    std::fill(g_bytes.begin() + base, g_bytes.begin() + base + kSlotSize, 0);
    g_sim_undo.erase(slot);
    clear_save_header_record(slot);
    hh::log("[save-edit] ELIMINAR slot %d (vaciado)\n", slot);
}

// Escribe el `.pak` en memoria al fichero (recalcula checksums de todos los slots) SIN tocar la
// cabecera de la lista de partidas. La usa ELIMINAR (su registro ya se marca como no presente).
bool flush() {
    if (!g_loaded) return false;
    set_pak_file_size();
    for (int s = 0; s < kSlots; ++s) {
        const size_t base = slot_off(s);
        unsigned sum = 0;
        for (size_t i = 0; i < kChecksumOff; ++i) sum += g_bytes[base + i];
        g_bytes[base + kChecksumOff] = static_cast<uint8_t>(sum & 0xFF);
        g_bytes[base + kChecksumOff + 1] = 0;
        g_bytes[base + kChecksumOff + 2] = 0;
        g_bytes[base + kChecksumOff + 3] = 0;
    }
    const std::filesystem::path tmp = g_path.string() + ".tmp";
    {
        std::ofstream out(tmp, std::ios::binary | std::ios::trunc);
        if (!out) return false;
        out.write(reinterpret_cast<const char*>(g_bytes.data()),
                  static_cast<std::streamsize>(g_bytes.size()));
    }
    std::error_code ec;
    std::filesystem::rename(tmp, g_path, ec);
    if (ec) {
        std::filesystem::remove(tmp, ec);
        hh::log("[save-edit] flush: no se pudo escribir %s: %s\n", g_path.string().c_str(),
                ec.message().c_str());
        return false;
    }
    hh_pak_reload_from_disk();
    hh::log("[save-edit] flush (.pak) + pak del runtime recargado\n");
    return true;
}

bool save(int slot, uint8_t* rdram, recomp_context* base_ctx, int area, int sub, int time,
          int difficulty) {
    (void)rdram; (void)base_ctx;
    if (!g_loaded || slot < 0 || slot >= kSlots) return false;
    set_pak_file_size();
    // Recalcula checksums de todos los slots y escribe el fichero (tmp + rename).
    for (int s = 0; s < kSlots; ++s) {
        const size_t base = slot_off(s);
        unsigned sum = 0;
        for (size_t i = 0; i < kChecksumOff; ++i) sum += g_bytes[base + i];
        g_bytes[base + kChecksumOff] = static_cast<uint8_t>(sum & 0xFF);
        g_bytes[base + kChecksumOff + 1] = 0;
        g_bytes[base + kChecksumOff + 2] = 0;
        g_bytes[base + kChecksumOff + 3] = 0;
    }
    // Y la cabecera de la lista de partidas (AREA/LEVEL/TIME/dificultad del slot) para DATA LOAD.
    update_save_header(slot, area, sub, time, difficulty);
    const std::filesystem::path tmp = g_path.string() + ".tmp";
    {
        std::ofstream out(tmp, std::ios::binary | std::ios::trunc);
        if (!out) return false;
        out.write(reinterpret_cast<const char*>(g_bytes.data()),
                  static_cast<std::streamsize>(g_bytes.size()));
    }
    std::error_code ec;
    std::filesystem::rename(tmp, g_path, ec);
    if (ec) {
        std::filesystem::remove(tmp, ec);
        hh::log("[save-edit] no se pudo escribir %s: %s\n", g_path.string().c_str(),
                ec.message().c_str());
        return false;
    }
    // Resincroniza el pak en RAM del runtime con el fichero que acabamos de escribir; si no, el
    // juego sigue viendo el `g_pak` cacheado (CONTINUAR cargaria el save sin los cambios).
    hh_pak_reload_from_disk();
    hh::log("[save-edit] guardado slot %d (.pak) + pak del runtime recargado\n", slot);
    return true;
}

// GUARDAR desde la cápsula: serializa los globals VIVOS con el serializador NATIVO y escribe el slot
// con `save()`. Es lo que falta frente a `save()` (que solo persiste lo que ya hay en memoria, válido
// para el editor): aquí se captura la partida en curso en el momento de guardar. Ver nota
// notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md §5.
bool save_live(int slot, uint8_t* rdram, recomp_context* base_ctx) {
    if (!g_loaded) load();
    if (!g_loaded || slot < 0 || slot >= kSlots || rdram == nullptr || base_ctx == nullptr) {
        hh::log("[save] save_live: slot %d no válido (loaded=%d)\n", slot, g_loaded ? 1 : 0);
        return false;
    }
    // 1. Buffer temporal de 0xD00 en la RDRAM del juego (heap de libultra).
    recomp_context t = *base_ctx;
    t.r4 = static_cast<uint32_t>(kSlotSize);
    func_8001F430_20030(rdram, &t);
    const uint32_t buf = static_cast<uint32_t>(t.r2);
    if (buf == 0) {
        hh::log("[save] save_live: no se pudo reservar 0x%zX\n", kSlotSize);
        return false;
    }
    // 2. Serializa los globals vivos al buffer (personaje, técnicas, items, progreso/escena…).
    recomp_context s = *base_ctx;
    s.r4 = buf;
    func_80141F28_103A6F8(rdram, &s);
    // 3. Copia VERBATIM al slot de g_bytes: el fichero guarda los bytes CRUDOS del buffer (igual que
    //    osPfsReadWriteFile, que hace memcpy sin swap). Así el slot en disco queda word-swapped como
    //    el original.
    std::memcpy(g_bytes.data() + slot_off(slot), rdram + MEM_OFF(buf), kSlotSize);
    // 4. Libera el buffer.
    recomp_context f = *base_ctx;
    f.r4 = buf;
    func_8001F540_20140(rdram, &f);
    // 5. TIME: de `[0x801BBBF0+0xA]` (u16 BE), la fuente que usa el descriptor nativo. [VALIDADO]
    const uint32_t time_addr = 0x801BBBF0u + 0x0Au;
    const int time = (static_cast<int>(grd8(time_addr)) << 8) | grd8(time_addr + 1u);
    // 6. ÁREA-PARTE: del ÍNDICE DE ESCENA vivo `[0x801BBBF0+4]` (u16 BE; 0 en 1-1, 2 en 1-2,
    //    10 en 2-1), mapeado con la MISMA enumeración que el selector PROGRESO. NO leer el área del
    //    slot (`0x366` daba 0-3). Diagnóstico: se registra también `func_80108280` (fuente del header
    //    nativo) y `0x564`/`0x366` del slot, por si hay que afinarlo.
    const uint16_t scene = static_cast<uint16_t>((grd8(0x801BBBF4u) << 8) | grd8(0x801BBBF5u));
    int area = 1, sub = 1;
    hh::menu::area_sub_from_value(scene, area, sub);
    // 7. DIFICULTAD: del byte global `0x801BBC0D` (0=NORMAL, 1=HARD, 2=ULTIMATE). Se persiste en el
    //    trailer/cabecera (byte +7) para que la UI del slot la muestre también tras reiniciar.
    const int difficulty = grd8(0x801BBC0Du);
    recomp_context g = *base_ctx;
    func_80108280_1000A50(rdram, &g);
    hh::log("[save] save_live slot %d: scene=%u -> AREA %d-%d TIME=%d DIFF=%d | fn8280=%08X 0x564=%u "
            "0x366=%u\n",
            slot, (unsigned)scene, area, sub, time, difficulty, static_cast<uint32_t>(g.r2),
            (unsigned)progress_of(slot), (unsigned)rd16(slot, kProgressOldOff));
    return save(slot, rdram, base_ctx, area, sub, time, difficulty);
}

// Primer slot de PARTIDA libre (metadato `presente` a 0). NO usa `slot_used` (progreso != 0): una
// partida en 1-0 tiene progreso 0 y se consideraría "libre". Si los 45 están ocupados, devuelve el
// último (se sobrescribe).
int first_free_game_slot() {
    if (!g_loaded) load();
    for (int i = 0; i < kGameSlots; ++i) {
        if (!slot_present(i)) return i;
    }
    return kGameSlots - 1;
}

bool loaded() { return g_loaded; }
void unload() { g_bytes.clear(); g_path.clear(); g_loaded = false; }
int slot_count() { return kSlots; }

// PLANTILLA BASE: carga `saves/templates/template_slot.bin` (0xD00) y la escribe en el slot `slot` del `.pak` en
// memoria (no toca el fichero). Se usa desde EXTRAS -> ELEGIR NIVEL -> IR A NIVEL cuando no hay
// partida cargada: da un estado de partida valido (stats base + Map Viewer/Defuser).
bool load_template(int slot) {
    if (slot < 0 || slot >= kSlots) return false;
    const std::filesystem::path p =
        hh::get_app_folder_path() / "saves" / "templates" / "template_slot.bin";
    std::ifstream in(p, std::ios::binary);
    if (!in) {
        hh::log("[save-edit] no encuentro la plantilla %s\n", p.string().c_str());
        return false;
    }
    std::vector<uint8_t> tpl((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    if (tpl.size() != kSlotSize) {
        hh::log("[save-edit] plantilla con tamaño invalido (%zu B)\n", tpl.size());
        return false;
    }
    if (!g_loaded) load(slot, nullptr, nullptr);
    if (!g_loaded || g_bytes.size() < slot_off(slot) + kSlotSize) return false;
    std::copy(tpl.begin(), tpl.end(), g_bytes.begin() + slot_off(slot));
    // Recalcula el checksum del slot por si la plantilla se edito a mano.
    unsigned sum = 0;
    const size_t base = slot_off(slot);
    for (size_t i = 0; i < kChecksumOff; ++i) sum += g_bytes[base + i];
    g_bytes[base + kChecksumOff] = static_cast<uint8_t>(sum & 0xFF);
    g_bytes[base + kChecksumOff + 1] = 0;
    g_bytes[base + kChecksumOff + 2] = 0;
    g_bytes[base + kChecksumOff + 3] = 0;
    hh::log("[save-edit] plantilla base escrita en slot %d (en memoria)\n", slot);
    return true;
}

bool slot_used(int slot) {
    if (!g_loaded) load(slot, nullptr, nullptr);
    return rd16(slot, kProgressOff) != 0;
}

// --- Metadatos por slot (trailer) para la UI -----------------------------------------------
// Registro del trailer: +0 presente, +1 AREA N, +2 AREA P, +3 LEVEL, +4..5 TIME (u16 BE).
bool slot_present(int slot) {
    if (!g_loaded) load(slot, nullptr, nullptr);
    return meta_rd(slot, 0) != 0;
}
uint8_t meta_area_n(int slot) {
    if (!g_loaded) load(slot, nullptr, nullptr);
    return meta_rd(slot, 1);
}
uint8_t meta_area_p(int slot) {
    if (!g_loaded) load(slot, nullptr, nullptr);
    return meta_rd(slot, 2);
}
uint8_t meta_level(int slot) {
    if (!g_loaded) load(slot, nullptr, nullptr);
    return meta_rd(slot, 3);
}
uint16_t meta_time(int slot) {
    if (!g_loaded) load(slot, nullptr, nullptr);
    return static_cast<uint16_t>((meta_rd(slot, 4) << 8) | meta_rd(slot, 5));
}
uint8_t meta_difficulty(int slot) {
    if (!g_loaded) load(slot, nullptr, nullptr);
    return meta_rd(slot, 7);
}
// Nombre para la UI: `savegame_slot<N>` (1-based; el índice interno es 0-based).
std::string slot_name(int slot) { return "savegame_slot" + std::to_string(slot + 1); }
// Nombre de una plantilla por su índice dentro del rango (0-based): `template_<N>` (1-based).
std::string template_name(int index) { return "template_" + std::to_string(index + 1); }

// Campos por slot. PROGRESO: u16 LE en 0x564 (indice de escena). Se mantiene 0x366 (BE) sincronizado
// por compatibilidad con el resto del editor/observaciones, pero el campo que decide el mapa es 0x564.
uint16_t progress_of(int slot) { return rd16le(slot, kProgressOff); }
void set_progress_of(int slot, uint16_t v) {
    wr16le(slot, kProgressOff, v);
    wr16(slot, kProgressOldOff, v);   // espejo legado (BE) para no dejar incoherencias
}
uint16_t level_of(int slot) { return rd16le(slot, kLevelOff); }
void set_level_of(int slot, uint16_t v) { wr16le(slot, kLevelOff, v); }

bool tech_learned_of(int slot, int id) {
    if (id < 0 || id >= kTechCount) return false;
    return rd8(slot, kTechOff + static_cast<size_t>(id) * 3) != 0;
}
void set_tech_learned_of(int slot, int id, bool on) {
    if (id < 0 || id >= kTechCount) return;
    wr8(slot, kTechOff + static_cast<size_t>(id) * 3, on ? 1 : 0);
}

uint16_t body_stat_of(int slot, int part, int kind) {
    if (part < 0 || part >= kParts || kind < 0 || kind > 3) return 0;
    static const size_t kOff[4] = {kOffenseOff, kDefenseOff, kHitOff, kDamageOff};
    return rd16le(slot, swap16(kOff[kind] + static_cast<size_t>(part) * 2));
}
void set_body_stat_of(int slot, int part, int kind, uint16_t v) {
    if (part < 0 || part >= kParts || kind < 0 || kind > 3) return;
    static const size_t kOff[4] = {kOffenseOff, kDefenseOff, kHitOff, kDamageOff};
    wr16le(slot, swap16(kOff[kind] + static_cast<size_t>(part) * 2), v);
}

// Nivel/progreso/stat por PARTE (índice 0..5 del juego). El progreso es el contador de EXP que, al
// cruzar el umbral, sube el nivel y suma `incremento[nivel]` a la stat (func_80376D48).
uint8_t part_level_of(int slot, int part) {
    if (part < 0 || part >= kParts) return 0;
    return rd8(slot, swap8(kPartLevelRuntime[part]));
}
void set_part_level_of(int slot, int part, uint8_t lvl) {
    if (part < 0 || part >= kParts) return;
    wr8(slot, swap8(kPartLevelRuntime[part]), lvl);
}
uint16_t part_progress_of(int slot, int part) {
    if (part < 0 || part >= kParts) return 0;
    return rd16le(slot, swap16(kPartProgRuntime[part]));
}
void set_part_progress_of(int slot, int part, uint16_t v) {
    if (part < 0 || part >= kParts) return;
    wr16le(slot, swap16(kPartProgRuntime[part]), v);
}
uint16_t part_stat_of(int slot, int part) {
    if (part < 0 || part >= kParts) return 0;
    return rd16le(slot, swap16(kPartStatRuntime[part]));
}

// Sube/baja `n` niveles a una parte aplicando la tabla REAL (suma/resta los incrementos al stat y a
// HP máx si es la parte de HP), y recalcula el nivel global del save. `n` puede ser negativo.
void add_part_levels(int slot, int part, int n) {
    if (part < 0 || part >= kParts || n == 0) return;
    const int lvl = part_level_of(slot, part);
    int target = lvl + n;
    if (target < 0) target = 0;
    if (target > kPartLevelMax) target = kPartLevelMax;
    if (target == lvl) return;
    long delta = 0;
    const uint16_t* inc = kIncByPart[part];
    if (target > lvl) {
        for (int l = lvl; l < target; ++l) delta += inc[l];
    } else {
        for (int l = target; l < lvl; ++l) delta -= inc[l];
    }
    int stat = static_cast<int>(part_stat_of(slot, part)) + static_cast<int>(delta);
    if (stat < 0) stat = 0;
    if (stat > 0x270F) stat = 0x270F;
    wr16le(slot, swap16(kPartStatRuntime[part]), static_cast<uint16_t>(stat));
    if (part == 0) {  // HP: la subida también aplica a HP máx (func_80376D48)
        int mx = static_cast<int>(rd16le(slot, swap16(0x02))) + static_cast<int>(delta);
        if (mx < 0) mx = 0;
        if (mx > 0x270F) mx = 0x270F;
        wr16le(slot, swap16(0x02), static_cast<uint16_t>(mx));
    }
    set_part_level_of(slot, part, static_cast<uint8_t>(target));
    set_level_of(slot, static_cast<uint16_t>(global_level_of(slot)));
}

// Nivel global DERIVADO: round((suma de los 6 niveles + 6)/6) = (suma+9)/6 (func_8037865C).
int global_level_of(int slot) {
    int sum = 0;
    for (int p = 0; p < kParts; ++p) sum += part_level_of(slot, p);
    return (sum + 9) / 6;
}

// MODO HEAVEN (runtime, modo GLOBAL independiente de la partida): lleva el personaje VIVO
// (`0x8017DC40`) al máximo. Se llama tras cargar una partida (CONTINUE / nueva) si
// `hh::menu::heaven_enabled()`. El propio save del juego serializa ESTE struct (`func_80144C40`),
// así que el estado queda persistido en la partida al guardar.
//   - ATRIBUTOS: los 6 niveles de parte a 99 aplicando las tablas REALES de incremento a su stat
//     (y a HP máx en la parte 0); recalcula el NIVEL global derivado.
//   - ESTADO: OFENSIVO/DEFENSIVO por parte a 99 (tope del editor).
//   - HABILIDADES: las 86 técnicas marcadas como aprendidas en la tabla viva `0x80183CE0` (+espejo).
// Quita la Code Key (id 38) del inventario vivo (cantidad u8 en `0x8017E004 + id*8 + 4`).
void clear_code_key_runtime(uint8_t* rdram) {
    if (rdram == nullptr) return;
    constexpr int kCodeKey = 38;
    const uint32_t addr = kItemNameRecs + static_cast<uint32_t>(kCodeKey) * 8u + 4u;
    rdram[(addr - 0x80000000u) ^ 3u] = 0;
    hh::log("[elegir-nivel] Code Key (item 38) quitada al cargar 1-0\n");
}

void apply_heaven_runtime(uint8_t* rdram) {
    if (rdram == nullptr) return;
    constexpr uint32_t kChar = 0x8017DC40u;
    auto r8 = [&](uint32_t addr) -> uint8_t { return rdram[(addr - 0x80000000u) ^ 3u]; };
    auto w8 = [&](uint32_t addr, uint8_t v) { rdram[(addr - 0x80000000u) ^ 3u] = v; };
    // u16 BIG-endian del guest (byte alto en `addr`, bajo en `addr+1`).
    auto r16 = [&](uint32_t addr) -> uint16_t {
        return static_cast<uint16_t>((static_cast<uint16_t>(r8(addr)) << 8) | r8(addr + 1u));
    };
    auto w16 = [&](uint32_t addr, uint16_t v) {
        w8(addr, static_cast<uint8_t>(v >> 8));
        w8(addr + 1u, static_cast<uint8_t>(v & 0xFFu));
    };

    // ATRIBUTOS: subir cada parte al 99 aplicando el incremento real (como add_part_levels, en vivo).
    for (int p = 0; p < kParts; ++p) {
        const int lvl = r8(kChar + static_cast<uint32_t>(kPartLevelRuntime[p]));
        if (lvl >= kPartLevelMax) continue;
        long delta = 0;
        for (int l = lvl; l < kPartLevelMax; ++l) delta += kIncByPart[p][l];
        int stat = static_cast<int>(r16(kChar + static_cast<uint32_t>(kPartStatRuntime[p]))) +
                   static_cast<int>(delta);
        if (stat > 0x270F) stat = 0x270F;
        w16(kChar + static_cast<uint32_t>(kPartStatRuntime[p]), static_cast<uint16_t>(stat));
        if (p == 0) {  // HP: la subida también aplica a HP máx (func_80376D48)
            int mx = static_cast<int>(r16(kChar + 0x02u)) + static_cast<int>(delta);
            if (mx > 0x270F) mx = 0x270F;
            w16(kChar + 0x02u, static_cast<uint16_t>(mx));
        }
        w8(kChar + static_cast<uint32_t>(kPartLevelRuntime[p]), static_cast<uint8_t>(kPartLevelMax));
    }
    // ESTADO: niveles OFENSIVO/DEFENSIVO por parte al tope del editor (99), u16 por parte.
    constexpr uint16_t kBodyMax = 99;
    for (int p = 0; p < kParts; ++p) {
        w16(kChar + static_cast<uint32_t>(kOffenseOff) + static_cast<uint32_t>(p) * 2u, kBodyMax);
        w16(kChar + static_cast<uint32_t>(kDefenseOff) + static_cast<uint32_t>(p) * 2u, kBodyMax);
    }
    // NIVEL global derivado (misma fórmula que global_level_of).
    int sum = 0;
    for (int p = 0; p < kParts; ++p) sum += r8(kChar + static_cast<uint32_t>(kPartLevelRuntime[p]));
    w16(kChar + 0x48u, static_cast<uint16_t>((sum + 9) / 6));
    // HABILIDADES: las 86 aprendidas en la tabla viva y su espejo; limpiar la marca de novedad.
    for (int id = 0; id < kTechCount; ++id) {
        w8(0x80183CE0u + static_cast<uint32_t>(id) * 6u, 1);
        w8(0x80183EE4u + static_cast<uint32_t>(id) * 6u, 1);
        w8(0x801840E8u + static_cast<uint32_t>(id), 0);
    }
    hh::log("[heaven] runtime: 0x8017DC40 al max (ATRIBUTOS/ESTADO 99) + 86 habilidades\n");
}

uint16_t part_exp_of(int slot, int part) { return part_progress_of(slot, part); }

// EXP acumulada (umbral) necesaria para pasar del nivel actual al siguiente.
uint16_t part_exp_threshold(int slot, int part) {
    if (part < 0 || part >= kParts) return 0;
    const int lvl = part_level_of(slot, part);
    if (lvl >= kPartLevelMax) return 0;
    return kThrByPart[part][lvl];
}

// EXP que falta para el siguiente nivel (0 si ya está en el tope).
uint16_t part_exp_to_next(int slot, int part) {
    if (part < 0 || part >= kParts) return 0;
    const int lvl = part_level_of(slot, part);
    if (lvl >= kPartLevelMax) return 0;
    const int thr = kThrByPart[part][lvl];
    const int prog = part_progress_of(slot, part);
    return (thr > prog) ? static_cast<uint16_t>(thr - prog) : 0;
}

// Aplica UN combate EXACTAMENTE como el juego (func_80376D48): por cada parte,
//   EXP_i += round( reward_i * ref_i / stat_i )   (ref_i = min(transformada, tope), cruzada OFF<->DEF)
// y luego el bucle de subida (stat += incremento[nivel] mientras EXP >= umbral[nivel]).
static void sim_one_battle(int slot) {
    int exp[kParts];
    for (int p = 0; p < kParts; ++p) {
        const int st = part_stat_of(slot, p);
        int ref = 0;
        switch (p) {
            case 0: ref = st * 120 / 100; break;            // HP   <- HP * 1.20
            case 1: ref = st; break;                        // STAM <- STAM
            case 2: ref = part_stat_of(slot, 3) * 84 / 100; break;   // OFF <- DEF * 0.84
            case 3: ref = part_stat_of(slot, 2) * 100 / 100; break;  // DEF <- OFF * 1.00
            case 4: ref = st; break;                        // REF  <- REF
            default: ref = st - 15; break;                  // SPD  <- SPD - 15
        }
        if (ref > kRefCap[p]) ref = kRefCap[p];
        if (ref < 0) ref = 0;
        const int div = st > 0 ? st : 1;
        long e = static_cast<long>(kRewardByPart[p]) * ref;
        e = (e + div / 2) / div;   // round-to-nearest
        exp[p] = e > 0 ? static_cast<int>(e) : 0;
    }
    for (int p = 0; p < kParts; ++p) {
        int prog = static_cast<int>(part_progress_of(slot, p)) + exp[p];
        if (prog > 0xFFFF) prog = 0xFFFF;
        int lvl = part_level_of(slot, p);
        long delta = 0;
        while (lvl < kPartLevelMax && prog >= kThrByPart[p][lvl]) {
            delta += kIncByPart[p][lvl];
            lvl++;
        }
        if (delta > 0) {
            long st = static_cast<int>(part_stat_of(slot, p)) + delta;
            if (st > 0x270F) st = 0x270F;
            wr16le(slot, swap16(kPartStatRuntime[p]), static_cast<uint16_t>(st));
            if (p == 0) {  // HP: también HP máx
                long mx = static_cast<int>(rd16le(slot, swap16(0x02))) + delta;
                if (mx > 0x270F) mx = 0x270F;
                wr16le(slot, swap16(0x02), static_cast<uint16_t>(mx));
            }
        }
        wr16le(slot, swap16(kPartProgRuntime[p]), static_cast<uint16_t>(prog));
        set_part_level_of(slot, p, static_cast<uint8_t>(lvl));
    }
    set_level_of(slot, static_cast<uint16_t>(global_level_of(slot)));
}

// `n` > 0: simula n combates (guarda un snapshot PRE-combate por cada uno, para poder deshacer).
// `n` < 0: DESHACE |n| combates restaurando los snapshots (no es simétrico: la fórmula depende de la
//          stat, así que la resta se hace revirtiendo el estado, no recalculando).
void simulate_combats(int slot, int n) {
    if (n == 0) return;
    if (n < 0) {
        auto it = g_sim_undo.find(slot);
        if (it == g_sim_undo.end()) return;
        std::vector<SimSnap>& stack = it->second;
        for (int k = 0; k < -n && !stack.empty(); ++k) {
            const SimSnap s = stack.back();
            stack.pop_back();
            for (int p = 0; p < kParts; ++p) {
                set_part_level_of(slot, p, s.level[p]);
                set_part_progress_of(slot, p, s.prog[p]);
                wr16le(slot, swap16(kPartStatRuntime[p]), s.stat[p]);
            }
            wr16le(slot, swap16(0x02), s.hpmax);
        }
        set_level_of(slot, static_cast<uint16_t>(global_level_of(slot)));
        hh::log("[save-edit] SIM COMBATE resta %d (quedan %zu)\n", -n, stack.size());
        return;
    }
    std::vector<SimSnap>& stack = g_sim_undo[slot];
    for (int k = 0; k < n; ++k) {
        SimSnap s;
        for (int p = 0; p < kParts; ++p) {
            s.level[p] = part_level_of(slot, p);
            s.prog[p] = part_progress_of(slot, p);
            s.stat[p] = part_stat_of(slot, p);
        }
        s.hpmax = rd16le(slot, swap16(0x02));
        stack.push_back(s);
        sim_one_battle(slot);
    }
}

uint8_t item_count_of(int slot, int id) {
    if (id < 0 || id >= kItemCount) return 0;
    return rd8(slot, kItemOff + static_cast<size_t>(id));
}
void set_item_count_of(int slot, int id, uint8_t v) {
    if (id < 0 || id >= kItemCount) return;
    wr8(slot, kItemOff + static_cast<size_t>(id), v);
}

// Atributos globales del personaje (offsets RUNTIME; el save va word-swapped -> swap16).
static const size_t kGlobalStatRuntime[kGlobalStatCount] = {
    0x00,  // HP
    0x02,  // HP MAX
    0x08,  // STAMINA
    0x40,  // OFFENSE
    0x42,  // DEFENSE
    0x44,  // SPEED
    0x46,  // REFLEX
};
uint16_t global_stat_of(int slot, int which) {
    if (which < 0 || which >= kGlobalStatCount) return 0;
    return rd16le(slot, swap16(kGlobalStatRuntime[which]));
}
void set_global_stat_of(int slot, int which, uint16_t v) {
    if (which < 0 || which >= kGlobalStatCount) return;
    wr16le(slot, swap16(kGlobalStatRuntime[which]), v);
}

void valid_points_by_level(int out_points[30]) {
    static const int kFallback[30] = {7, 10, 9, 9, 10, 8, 6, 9, 6, 9, 6, 10, 10, 10, 10,
                                      10, 10, 10, 10, 7, 5, 10, 1, 1, 8, 10, 10, 1, 1, 1};
    bool ok = false;
    for (int lvl = 0; lvl < 30; ++lvl) {
        int n = 0;
        for (int p = 0; p < 10; ++p) {
            const uint32_t addr = kSceneTable + static_cast<uint32_t>(lvl * 10 + p) * 4;
            if (guest_u32(addr) != 0) n++;
        }
        out_points[lvl] = n;
        if (n > 0) ok = true;
    }
    if (!ok) for (int i = 0; i < 30; ++i) out_points[i] = kFallback[i];
}

std::string tech_name(int id) {
    if (id < 0 || id >= kTechCount) return std::string();
    std::string s = guest_str(guest_u32(kTechNamePtrs + static_cast<uint32_t>(id) * 4));
    if (s.empty()) s = "TECH " + std::to_string(id + 1);
    return s;
}
std::string item_name(int id) {
    if (id < 0 || id >= kItemCount) return std::string();
    // Cada item tiene su registro en `0x8017E004 + id*8`; el primer campo es un puntero a la entrada
    // de la tabla de nombres de ESE item (nombre en `*(u32)ptr`). Usamos ese puntero en vez de indexar
    // la tabla `0x8017DF50` directamente: si el juego reordena los registros en runtime, el puntero del
    // registro sigue siendo el correcto. Ver notes/2026-09-28-logica-juego-tecnicas-items-y-stats.md §2.
    const uint32_t entry_rec = guest_u32(kItemNameRecs + static_cast<uint32_t>(id) * 8);
    const uint32_t entry = (entry_rec >= 0x80000000u) ? entry_rec
                                                      : kItemNamePtrs + static_cast<uint32_t>(id) * 4;
    std::string s = guest_str(guest_u32(entry));
    if (s.empty()) s = "ITEM " + std::to_string(id + 1);
    return s;
}

// Nombre sin la variante final (" S"," M"," L"," X"," SP"), para agrupar familias.
std::string item_base_name(const std::string& n) {
    static const char* kSuf[] = { " SP", " S", " M", " L", " X" };
    for (const char* suf : kSuf) {
        const size_t sl = std::strlen(suf);
        if (n.size() > sl && n.compare(n.size() - sl, sl, suf) == 0) return n.substr(0, n.size() - sl);
    }
    return n;
}

// DIAGNOSTICO (HH_SAVEEDIT_DUMP=1): vuelca a `hh.log` la tabla de escenas `D_80175490` (30x10, con
// los records apuntados) y el bloque de estado global `0x801BBBF0`. Sirve para identificar que
// Areas-Partes existen de verdad y que campos lleva cada record. No forma parte del editor.
void dump_runtime(uint8_t* rdram, const char* tag) {
    if (rdram == nullptr) return;
    auto r8 = [&](uint32_t addr) -> uint8_t { return rdram[(addr - 0x80000000u) ^ 3u]; };
    auto r16 = [&](uint32_t addr) -> uint16_t {
        return static_cast<uint16_t>((static_cast<uint16_t>(r8(addr)) << 8) | r8(addr + 1u));
    };
    auto r32 = [&](uint32_t addr) -> uint32_t {
        return (static_cast<uint32_t>(r8(addr)) << 24) | (static_cast<uint32_t>(r8(addr + 1u)) << 16) |
               (static_cast<uint32_t>(r8(addr + 2u)) << 8) | static_cast<uint32_t>(r8(addr + 3u));
    };
    auto hex16 = [&](uint32_t base) {
        std::string s;
        char b[4];
        for (int i = 0; i < 16; ++i) {
            std::snprintf(b, sizeof(b), "%02x ", r8(base + static_cast<uint32_t>(i)));
            s += b;
        }
        return s;
    };
    hh::trace_log("[save-dump][%s] === D_80175490 (300 punteros) ===\n", tag);
    for (int i = 0; i < 300; ++i) {
        const uint32_t rec = r32(kSceneTable + static_cast<uint32_t>(i) * 4u);
        if (rec == 0) continue;
        hh::trace_log("[save-dump][%s]  idx=%3d (N=%d P=%d) rec=%08X  bytes=%s\n", tag, i, i / 10, i % 10,
                rec, hex16(rec).c_str());
    }
    hh::trace_log("[save-dump][%s] === 0x801BBBF0 (+0..0x40) ===\n", tag);
    for (int row = 0; row < 0x40; row += 16) {
        hh::trace_log("[save-dump][%s]  +%03X %s\n", tag, row, hex16(0x801BBBF0u + static_cast<uint32_t>(row)).c_str());
    }
    hh::trace_log("[save-dump][%s] === 0x801BBBF0 (+0x180..0x1A0, +0x390..0x3A0) ===\n", tag);
    for (int row = 0x180; row < 0x1A0; row += 16) {
        hh::trace_log("[save-dump][%s]  +%03X %s\n", tag, row, hex16(0x801BBBF0u + static_cast<uint32_t>(row)).c_str());
    }
    for (int row = 0x390; row < 0x3A0; row += 16) {
        hh::trace_log("[save-dump][%s]  +%03X %s\n", tag, row, hex16(0x801BBBF0u + static_cast<uint32_t>(row)).c_str());
    }
    hh::trace_log("[save-dump][%s] progreso global [+4]=%u nivel [+8]=%u [+2]=%u [+6]=%u\n", tag,
            static_cast<unsigned>(r16(0x801BBBF0u + 4u)), static_cast<unsigned>(r16(0x801BBBF0u + 8u)),
            static_cast<unsigned>(r16(0x801BBBF0u + 2u)), static_cast<unsigned>(r16(0x801BBBF0u + 6u)));
    // Bloque de 512 B que el serializador copia a 0x364 (fuente `0x801BED38`, ver func_8014C294/A0).
    hh::trace_log("[save-dump][%s] === 0x801BED38 (512 B, va al slot 0x364) ===\n", tag);
    for (int row = 0; row < 0x200; row += 16) {
        hh::trace_log("[save-dump][%s]  +%03X %s\n", tag, row,
                hex16(0x801BED38u + static_cast<uint32_t>(row)).c_str());
    }
}

// Volcado del buffer de 0xD00 que el juego pasa a `func_80141D08` (lo leido del PFS, verbatim). Es el
// layout EXACTO que interpreta el deserializador. Solo diagnostico.
void dump_slot_buffer(uint8_t* rdram, uint32_t addr, const char* tag) {
    if (rdram == nullptr || addr < 0x80000000u) return;
    auto r8 = [&](uint32_t a) -> uint8_t { return rdram[(a - 0x80000000u) ^ 3u]; };
    hh::trace_log("[save-dump][%s] === buffer 0xD00 en %08X ===\n", tag, addr);
    for (int row = 0; row < 0xD00; row += 16) {
        std::string s;
        char b[4];
        for (int i = 0; i < 16; ++i) {
            std::snprintf(b, sizeof(b), "%02x ", r8(addr + static_cast<uint32_t>(row + i)));
            s += b;
        }
        // Solo filas con algun byte no cero (el buffer mayormente vacio).
        bool any = false;
        for (int i = 0; i < 16; ++i) any = any || (r8(addr + static_cast<uint32_t>(row + i)) != 0);
        if (any) hh::trace_log("[save-dump][%s]  +%03X %s\n", tag, row, s.c_str());
    }
}

int item_slot_of(int display) {
    if (display < 0 || display >= kItemCount) return display;
    const std::string base = item_base_name(item_name(display));
    int start = display;
    int last = display;
    while (start > 0 && item_base_name(item_name(start - 1)) == base) --start;
    while (last + 1 < kItemCount && item_base_name(item_name(last + 1)) == base) ++last;
    return start + (last - display);   // inversion dentro de la familia
}

}  // namespace hh::save
