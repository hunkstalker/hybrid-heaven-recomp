# menu.cpp — higiene y correcciones en el flujo de guardado/editor (pre-tarea de CARGAR)

> Sesión 2026-10-01. Rama **`menu-carga-guardado-partida`**. Revisión de
> `src/subsystems/menu.cpp` (§ guardado y editor) a raíz de la preparación de la siguiente tarea
> (**UI de CARGA en `CONTINUAR`**, `RETOMAR.md` §🎯). **VALIDADO en Windows** por el mantenedor
> ("todo funciona perfecto"). Todo `[MEDIDO]` del código; sin cambio de comportamiento visible.

## 0. Resumen

Cuatro correcciones de coherencia/higiene en el modelo del menú. Ninguna altera la UI ni la 1:1;
arreglan un olfato de bug (estado paralelo), una definición duplicada de "slot libre" (riesgo de
pisar un save), código muerto y un comentario huérfano.

## 1. Unificación de `g_save_target_slot` / `g_save_delete_slot`

Había **dos variables paralelas** con idéntico ciclo de vida (ambas `-1` en `open_save_game()`) que
guardaban lo mismo (el `index` de la fila resaltada en `Select`):

- `g_save_target_slot`: la fija **A** (`sections.cpp:1944`), la lee `ConfirmHere` (`:1845`).
- `g_save_delete_slot`: la fija **X** (`:1954`), la lee `ConfirmDelete` (`:1858`).

Como la **fase** (`SavePhase`) ya distingue guardar de borrar, la segunda es redundante: se elimina.
`g_save_target_slot` pasa a ser "el slot de la fila resaltada", y la fase decide su uso
(`ConfirmHere` = guardar; `ConfirmDelete` = borrar).

- `menu.cpp`: fuera `g_save_delete_slot` (var, reset en `open_save_game`, getter/setter).
- `menu.h`: fuera `save_delete_slot()`/`set_save_delete_slot()`.
- `sections.cpp`: la rama X usa `set_save_target_slot(cur.index)`; `ConfirmDelete` lee
  `save_target_slot()`.

### Análisis para la próxima tarea (UI de CARGAR): NO afecta

`LoadGame` será copia estructural de `SaveGame`, pero la cápsula de carga tendrá **su propio**
estado de fase (confirmar carga + borrado opcional §8ter). No comparte `g_save_target_slot`; la
unificación no acopla ni complica esa tarea.

## 2. "Slot libre" con una sola definición (`slot_present`)

`menu.cpp:save_edit_save_target_slot()` (NUEVA PARTIDA del editor) usaba `slot_used(i)`
(**progreso ≠ 0**), mientras la cápsula usa `first_free_game_slot()` (**metadato `presente` a 0`**,
`save_edit.cpp:505` — que además advierte explícitamente de **no** usar `slot_used`). Un save en
1-0 tiene progreso 0 y se consideraba "libre" → se podía pisar. Ahora el editor reusa
`hh::save::first_free_game_slot()`: una sola definición.

## 3. Código muerto y comentario huérfano

- `load_game_row_present()` (declarada en `menu.h:252`) tenía **0 llamadas**: la presencia la
  resuelve `Entry::enabled` desde `slot_present()` (`menu_overlay.cpp:639`). Eliminada.
- Comentario huérfano sobre `refresh_load_game` que precedía a `load_game_row_text` (resto de una
  refactorización). Eliminado.

## 4. Verificación

- Sin referencias colgantes (`rg save_delete_slot|load_game_row_present|g_save_delete_slot` → vacío).
- **Compila** Linux (`cmake --build build/linux` → `Built target HybridHeavenRecomp`).
- **Validado en Windows** por el mantenedor: A-guarda / X-borra / cancelar en la cápsula y NUEVA
  PARTIDA desde el editor. "Todo funciona perfecto."
