#pragma once

// hh_saveedit — editor de partida sobre el `.pak` de guardado (v3).
//
// Edita el slot del fichero de guardado (el que CONTINUE/la cápsula leen), no los globals del juego.
// Layout del slot medido comparando `.pak` reales (ver notes/2026-09-27-e-editor-partida-plan.md):
//   cabecera 0x100 + 4 slots 0xD00; checksum por slot en +0xCFC.
//     PROGRESO u16 BE +0x366 (N*10+P) · NIVEL u8 +0x04B · TÉCNICAS 86x3 +0x09E (flag +0)
//     ITEMS 45xu8 +0x1A0 · STATS por parte (u16 BE): offense +0x010, defense +0x01C, hit +0x068,
//     damage +0x076. Orden de partes = el del juego (Cabeza, Cuerpo, Brazo Der, Izq, Pierna Der, Izq).
//
// `load()` abre el `.pak`; los `*_of(slot, …)` leen/escriben el slot en memoria; `save(slot)` escribe
// el fichero (checksums recalculados). No requiere RDRAM salvo para nombres y la tabla de escenas.

#include <cstdint>
#include <string>

#include "recomp.h"

namespace hh::save {

constexpr int kSlots = 4;
constexpr int kTechCount = 86;
constexpr int kItemCount = 45;
constexpr int kParts = 6;

// Kinds de estadistica por parte.
enum BodyStat { kOffense = 0, kDefense = 1, kHitCount = 2, kDamageCount = 3 };

// Abre el `.pak` (idempotente). Los args se mantienen por compatibilidad; no se usan.
bool load(int slot = 0, uint8_t* rdram = nullptr, recomp_context* base_ctx = nullptr);
bool save(int slot, uint8_t* rdram = nullptr, recomp_context* base_ctx = nullptr);
bool loaded();
void unload();
int slot_count();
bool slot_used(int slot);

// Campos por slot.
uint16_t progress_of(int slot);
void set_progress_of(int slot, uint16_t v);
uint8_t level_of(int slot);
void set_level_of(int slot, uint8_t v);
bool tech_learned_of(int slot, int id);
void set_tech_learned_of(int slot, int id, bool on);
uint16_t body_stat_of(int slot, int part, int kind);
void set_body_stat_of(int slot, int part, int kind, uint16_t v);
uint8_t item_count_of(int slot, int id);
void set_item_count_of(int slot, int id, uint8_t v);

// Nombres (RDRAM del juego, módulo 8).
std::string tech_name(int id);
std::string item_name(int id);

// PROGRESO: puntos de guardado válidos por nivel según la tabla de escenas real D_80175490.
void valid_points_by_level(int out_points[30]);

}  // namespace hh::save
