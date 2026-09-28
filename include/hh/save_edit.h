#pragma once

// hh_saveedit — editor de partida sobre el `.pak` de guardado (v3).
//
// Edita el slot del fichero de guardado (el que CONTINUE/la cápsula leen), no los globals del juego.
// Layout del slot medido comparando `.pak` reales (ver notes/2026-09-27-e-editor-partida-plan.md):
//   cabecera 0x100 + 4 slots 0xD00; checksum por slot en +0xCFC.
//     PROGRESO u16 BE +0x366 (N*10+P) · TÉCNICAS 86x3 +0x09E (flag +0) · ITEMS 45xu8 +0x1A0.
//   El **bloque de personaje** va **32-bit word-swapped** respecto al runtime: el campo runtime de
//   offset `r` vive en el save en `r^2` (u16) / `r^3` (u8). Confirmado por el mantenedor (OFF/DEF y
//   VEL/REF salían invertidos). Ver notes/2026-09-28-stats-recompute-correccion.md §7.
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
constexpr int kPartLevelMax = 99;   // nivel máximo por atributo (tablas de 99 entradas)

// Kinds de estadistica por parte.
enum BodyStat { kOffense = 0, kDefense = 1, kHitCount = 2, kDamageCount = 3 };

// Abre el `.pak` (idempotente). Los args se mantienen por compatibilidad; no se usan.
bool load(int slot = 0, uint8_t* rdram = nullptr, recomp_context* base_ctx = nullptr);
bool save(int slot, uint8_t* rdram = nullptr, recomp_context* base_ctx = nullptr);
void restore_slot(int slot);   // devuelve el slot al estado del `.pak` al cargarlo (RESTAURAR)
void delete_slot(int slot);    // vacía el slot y marca su registro de cabecera como no presente
bool loaded();
void unload();
int slot_count();
bool slot_used(int slot);

// Campos por slot.
uint16_t progress_of(int slot);
void set_progress_of(int slot, uint16_t v);
uint16_t level_of(int slot);
void set_level_of(int slot, uint16_t v);
bool tech_learned_of(int slot, int id);
void set_tech_learned_of(int slot, int id, bool on);
uint16_t body_stat_of(int slot, int part, int kind);
void set_body_stat_of(int slot, int part, int kind, uint16_t v);

// Nivel / progreso / stat por PARTE (índice 0..5 del juego: 0=HP, 1=STAMINA, 2=OFFENSE,
// 3=DEFENSE, 4=REFLEX, 5=SPEED). "Subir nivel" aplica la tabla real de `docs/stats-partes.md`.
uint8_t part_level_of(int slot, int part);
void set_part_level_of(int slot, int part, uint8_t lvl);
uint16_t part_progress_of(int slot, int part);
void set_part_progress_of(int slot, int part, uint16_t v);
uint16_t part_stat_of(int slot, int part);
void add_part_levels(int slot, int part, int n);   // aplica incremento[nivel] al stat (+HPmax en parte 0)
// Nivel GLOBAL derivado = round((suma de los 6 niveles + 6)/6) (func_8037865C).
int global_level_of(int slot);
// EXP (progreso) de un atributo, umbral acumulado del nivel actual y cuánto falta para el siguiente.
uint16_t part_exp_of(int slot, int part);
uint16_t part_exp_threshold(int slot, int part);
uint16_t part_exp_to_next(int slot, int part);
// Simula `n` combates con la fórmula EXACTA del juego (EXP + subida de nivel/stat).
void simulate_combats(int slot, int n);   // n>0 simula n combates; n<0 deshace |n| simulados
uint8_t item_count_of(int slot, int id);
void set_item_count_of(int slot, int id, uint8_t v);

// Atributos GLOBALES del personaje (u16 LE en el slot). El juego NO los recalcula al cargar: subir
// el nivel no los toca, hay que fijarlos a mano (el fallback mientras no se localice la formula de
// escalado). Ver notes/2026-09-28-logica-juego-tecnicas-items-y-stats.md.
enum GlobalStat { gHp = 0, gHpMax, gStamina, gOffense, gDefense, gSpeed, gReflex, kGlobalStatCount };
uint16_t global_stat_of(int slot, int which);
void set_global_stat_of(int slot, int which, uint16_t v);

// Nombres (RDRAM del juego, módulo 8).
std::string tech_name(int id);
std::string item_name(int id);
// Índice de DISPLAY (orden de nombres S,M,L,X…) -> índice de SLOT del `.pak`. El juego guarda las
// variantes de una familia en orden INVERSO al de la tabla de nombres (S↔X, M↔L), así que el editor
// muestra el nombre en orden natural pero lee/escribe la cantidad en el slot invertido de su familia.
int item_slot_of(int display_index);

// PROGRESO: puntos de guardado válidos por nivel según la tabla de escenas real D_80175490.
void valid_points_by_level(int out_points[30]);

// MODO HEAVEN (runtime, modo GLOBAL): lleva el personaje VIVO `0x8017DC40` al máximo (ATRIBUTOS
// 99 + ESTADO 99 + 86 habilidades). Lo llama el hook de carga de partida cuando
// `hh::menu::heaven_enabled()`. No toca items (esos solo son "no consumibles" por hook).
void apply_heaven_runtime(uint8_t* rdram);

}  // namespace hh::save
