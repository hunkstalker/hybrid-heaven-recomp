#pragma once

// hh_saveedit — editor de partida en MEMORIA (v2).
//
// En vez de tocar el `.pak` en disco, carga un slot en los globals del juego, edita ahí (en caliente)
// y guarda serializando los globals. Usa funciones NATIVAS del juego:
//   - `func_801423C8(channel=0, slot)` lee el slot del PFS + deserializa a los globals (sin arrancar
//     partida; es el mismo camino que usa el file-select).
//   - `func_80142450(channel=0, slot)` serializa los globals + escribe el slot (vía PFS: actualiza el
//     `.pak`), sin la UI nativa de guardado.
// Ver notes/2026-09-27-e-editor-partida-plan.md.
//
// Direcciones (módulo 8): progreso `0x801BBBF4` (u16 BE = N*10+P); nivel `0x8017DC88` (u8); técnicas
// `0x80183CE0` (86×6; flag `+0` = aprendida); stats del PJ `0x8017DC40` (offense `+0x10`, defense
// `+0x1C`, hit `+0x68`, damage `+0x76`; 6 partes × u16); items `0x8017E004` (45×8; cantidad `+4`).

#include <cstdint>
#include <string>

#include "recomp.h"   // recomp_context (para llamar a las funciones nativas de carga/guardado)

namespace hh::save {

constexpr int kSlots = 4;
constexpr int kTechCount = 86;
constexpr int kItemCount = 45;
constexpr int kParts = 6;

// Kinds de estadistica por parte (indice del array en el struct de stats).
enum BodyStat { kOffense = 0, kDefense = 1, kHitCount = 2, kDamageCount = 3 };

// Carga el slot `slot` (0..3) en los globals. Usa `base_ctx` (del handler del menú) para tomar una
// pila válida (la función nativa usa sp). true si la operación tuvo éxito.
bool load(int slot, uint8_t* rdram, recomp_context* base_ctx);
// Serializa los globals y los escribe en el slot `slot`.
bool save(int slot, uint8_t* rdram, recomp_context* base_ctx);
bool loaded();
void unload();

int slot_count();  // 4

// Campos (leen/escriben los globals vivos).
uint16_t progress();                    // N*10+P
void set_progress(uint16_t v);
uint8_t level();                        // nivel de personaje (u8)
void set_level(uint8_t v);

bool tech_learned(int id);
void set_tech_learned(int id, bool on);

uint16_t body_stat(int part, int kind);
void set_body_stat(int part, int kind, uint16_t v);

uint8_t item_count(int id);
void set_item_count(int id, uint8_t v);

// Nombres (RDRAM del juego, módulo 8: arrays de punteros 0x80184140 / 0x8017DF50).
std::string tech_name(int id);
std::string item_name(int id);

}  // namespace hh::save
