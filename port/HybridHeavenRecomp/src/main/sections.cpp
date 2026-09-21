// Seccion de registro del recomp per-file: el port envuelve los DOS loaders del juego para decirle
// a librecomp que fichero de codigo ocupa que direccion AHORA (las llamadas van por direccion con
// use_lookup_for_all_function_calls y los overlays comparten/se intercambian bases de VRAM).
//
// Modelo (estilo del port de referencia, docs/adr/0009): `include/hh/file_table.h` lista los 91
// code files {id, vram, size} en el MISMO orden que `code_files.overlays.txt`
// (= overlay_sections_by_index de N64Recomp). `announce_load(id, dest)`:
//   1) evita lo que solape la base cargada (unload_overlay_by_id),
//   2) registra la seccion vigente (load_overlay_by_id).
// Los loaders del juego se envuelven por direccion con `add_loaded_function` (no se toca el C
// generado): FUN_8000469C (file_load) y FUN_80004838 (streamed, un trozo por llamada; el fichero
// 57 de combate solo carga por este).
//
// Sustituye a `module_sources.inc` / `load_module_by_source` (registro por offset de ROM retail).

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <vector>

#include "../../RecompiledFuncs/recomp_overlays.inl"
#include "../../RecompiledFuncs/runtime_funcs.inl"

#include "librecomp/overlays.hpp"
#include "hh.h"
#include "hh/file_table.h"

extern "C" void func_8000469C_529C(uint8_t* rdram, recomp_context* ctx);
extern "C" void func_80004838_5438(uint8_t* rdram, recomp_context* ctx);
extern "C" void load_overlay_by_id(uint32_t id, uint32_t ram_addr);
extern "C" void unload_overlay_by_id(uint32_t id);

namespace {

constexpr uint32_t kFileLoadAddress = 0x8000469C;          // file_load(id, dest)
constexpr uint32_t kFileLoadStreamedAddress = 0x80004838;  // streamed(id, dest), pieza a pieza
constexpr size_t kFileCount = sizeof(hh::kCodeFiles) / sizeof(hh::kCodeFiles[0]);

bool env_set(const char* name) {
    const char* v = std::getenv(name);
    return v != nullptr && *v != '\0' && *v != '0';
}

std::mutex g_load_mutex;
// Indice en kCodeFiles (= indice de seccion) -> direccion cargada, o 0.
std::vector<uint32_t> g_loaded_at(kFileCount, 0);

int code_file_index(uint32_t id) {
    for (size_t i = 0; i < kFileCount; ++i) {
        if (hh::kCodeFiles[i].id == id) {
            return static_cast<int>(i);
        }
    }
    return -1;  // fichero de datos; no hay seccion que registrar
}

void announce_load(uint32_t id, uint32_t dest) {
    const int index = code_file_index(id);
    if (index < 0) {
        return;
    }
    const hh::CodeFile& file = hh::kCodeFiles[index];
    if (dest != file.vram) {
        // El codigo recompilado lleva su direccion de enlace en cada puntero que construye: cargado
        // en otra base seria incorrecto en sitios lejanos. Avisar y registrar en la base de enlace.
        std::fprintf(stderr, "[hh] file %u cargado en 0x%08X, pero su codigo enlaza en 0x%08X"
                             " -- se registra en la base de enlace\n", id, dest, file.vram);
        std::fflush(stderr);
    }

    std::lock_guard<std::mutex> lock(g_load_mutex);
    const uint32_t lo = file.vram;
    const uint32_t hi = file.vram + file.size;
    size_t evicted = 0;
    for (size_t i = 0; i < kFileCount; ++i) {
        if (g_loaded_at[i] == 0) {
            continue;
        }
        const uint32_t olo = g_loaded_at[i];
        const uint32_t ohi = olo + hh::kCodeFiles[i].size;
        if (olo < hi && lo < ohi) {
            unload_overlay_by_id(static_cast<uint32_t>(i));
            g_loaded_at[i] = 0;
            ++evicted;
        }
    }
    load_overlay_by_id(static_cast<uint32_t>(index), file.vram);
    g_loaded_at[index] = file.vram;

    if (env_set("HH_DEBUG_LOADS") || dest != file.vram) {
        std::fprintf(stderr, "[hh-load] file %3u (idx %d) -> 0x%08X (0x%06X bytes, %zu evicted)\n",
                     id, index, dest, file.size, evicted);
        std::fflush(stderr);
    }
}

// Loader normal: registra el fichero y luego ejecuta el original (que descomprime en RDRAM).
void file_load_hook(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t id = static_cast<uint32_t>(ctx->r4);
    const uint32_t dest = static_cast<uint32_t>(ctx->r5);
    announce_load(id, dest);
    func_8000469C_529C(rdram, ctx);
}

// Loader streamed: el fichero no esta completo hasta que r2 != 0; se anuncia en esa llamada.
void file_load_streamed_hook(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t id = static_cast<uint32_t>(ctx->r4);
    const uint32_t dest = static_cast<uint32_t>(ctx->r5);
    func_80004838_5438(rdram, ctx);
    if (ctx->r2 != 0) {
        announce_load(id, dest);
    }
}

}  // namespace

void hh::register_overlays() {
    recomp::overlays::overlay_section_table_data_t sections{
        section_table,
        ARRLEN(section_table),
        num_sections,
    };
    recomp::overlays::overlays_by_index_t overlays{
        overlay_sections_by_index,
        ARRLEN(overlay_sections_by_index),
    };
    recomp::overlays::register_overlays(sections, overlays);

    // Coherencia tabla generada <-> file_table.h.
    if (ARRLEN(overlay_sections_by_index) != hh::kCodeFileCount) {
        std::fprintf(stderr, "[hh] overlay_sections_by_index=%zu entradas, kCodeFiles=%zu:"
                             " regenera el C y file_table.h (tools/regenerate.py)\n",
                     ARRLEN(overlay_sections_by_index), hh::kCodeFileCount);
        std::fflush(stderr);
        std::abort();
    }
}

// Debe correr en on_init, DESPUES de init_overlays(): init_overlays hace func_map.clear() y
// borraria los hooks si se registraran antes (register_overlays() si va antes, para las tablas).
void hh::register_runtime_functions() {
    // libultra que provee el runtime, en su direccion de cartucho: con use_lookup_for_all_function_calls
    // cada llamada es un lookup, y estas funciones no viven en ninguna tabla de seccion.
    for (const auto& entry : runtime_provided_funcs) {
        recomp::overlays::add_loaded_function(static_cast<int32_t>(entry.ram_addr), entry.func);
    }
    recomp::overlays::add_loaded_function(static_cast<int32_t>(kFileLoadAddress), file_load_hook);
    if (!env_set("HH_NO_STREAMED_LOADS")) {
        recomp::overlays::add_loaded_function(static_cast<int32_t>(kFileLoadStreamedAddress),
                                              file_load_streamed_hook);
    }
    std::fprintf(stderr, "[hh] %zu code files; loaders envueltos en 0x%08X y 0x%08X\n",
                 kFileCount, kFileLoadAddress, kFileLoadStreamedAddress);
    std::fflush(stderr);
}
