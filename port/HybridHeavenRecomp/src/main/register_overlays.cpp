#include "../../RecompiledFuncs/recomp_overlays.inl"

#include "librecomp/overlays.hpp"

#include "hh.h"

// Mapa src_rom (offset de ROM retail que el juego pasa al loader) -> indice de seccion.
// Generado por tools/setup_module.py (module_sources.inc). Permite registrar el modulo
// recompilado en la base de RAM real que pide el juego (bases reutilizadas).
static const recomp::overlays::ModuleSource hh_module_sources[] = {
#include "module_sources.inc"
};

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
    recomp::overlays::register_module_sources(hh_module_sources, ARRLEN(hh_module_sources));
}