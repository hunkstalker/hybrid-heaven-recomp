#pragma once

// hh_saveedit — editor del fichero de guardado (Controller Pak) del port.
//
// Lee/escribe el `.pak` (`saves/*.pak`) directamente, con el layout medido del slot (ver
// notes/2026-09-27-e-editor-partida-plan.md): cabecera 0x100 + 4 slots 0xD00; checksum por slot en
// +0xCFC = sum(bytes[0..0xCFB])&0xFF. No depende del estado del juego (solo de la ROM para los
// nombres). Tras escribir, se recarga el pak del runtime para que `CONTINUAR` lea lo editado.
//
// Los campos viven a offsets fijos dentro del slot (ver la nota). "part" usa el orden del juego:
// 0 Cabeza, 1 Cuerpo, 2 Brazo Der, 3 Brazo Izq, 4 Pierna Der, 5 Pierna Izq.

#include <cstdint>
#include <string>

namespace hh::save {

constexpr int kSlots = 4;
constexpr int kTechCount = 86;
constexpr int kItemCount = 45;
constexpr int kParts = 6;

// Kinds de estadistica por parte (indice del array en el struct de stats).
enum BodyStat { kOffense = 0, kDefense = 1, kHitCount = 2, kDamageCount = 3 };

// Carga el `.pak` encontrado en `saves/` (una vez; idempotente). false si no hay fichero/valido.
bool load();
bool loaded();
void unload();

int slot_count();          // 4 (fijo)
bool slot_used(int slot);  // heuristica: progreso != 0 o checksum != 0

// Campos del slot.
uint16_t progress(int slot);                 // N*10+P
void set_progress(int slot, uint16_t v);
uint8_t level(int slot);                     // nivel de personaje (u8)
void set_level(int slot, uint8_t v);

bool tech_learned(int slot, int id);
void set_tech_learned(int slot, int id, bool on);

uint16_t body_stat(int slot, int part, int kind);
void set_body_stat(int slot, int part, int kind, uint16_t v);

uint8_t item_count(int slot, int id);
void set_item_count(int slot, int id, uint8_t v);

// Escribe el `.pak` con los cambios (recalcula checksums de los slots) y fuerza la recarga del
// runtime para que el juego lea lo editado. false si no habia pak cargado o falla la escritura.
bool save();
// Descarta los cambios en memoria y relee del disco.
void revert();

// Nombres (leidos de la RDRAM del juego, modulo 8: arrays de punteros 0x80184140 / 0x8017DF50).
// Fallback "TECH n"/"ITEM n" si no estan disponibles.
std::string tech_name(int id);
std::string item_name(int id);

}  // namespace hh::save
