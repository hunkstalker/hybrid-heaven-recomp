# CARGAR PARTIDA — UI propia y carga real en CONTINUAR (DATA LOAD)

> Sesión 2026-10-01. Rama **`menu-carga-guardado-partida`**. Tarea de `RETOMAR.md`: la **UI de CARGA**
> en el submenú `CONTINUAR` (`LoadGame`) y que un slot **cargue de verdad**. Plantilla: el ciclo de
> GUARDADO (`notes/2026-09-30-save-capsule-logica.md`). Todo `[MEDIDO]` del C recompilado
> (`build/recomp/asm/file_008.s`, `file_024.s`) salvo lo marcado `[INFERIDO]`.

## 0. Resumen

Se dota a CARGAR del mismo flujo por fases que GUARDAR (`hh::menu::LoadPhase`), con UI 1:1 propia
(título/subtítulo/cajas/mensaje, ya existentes de la Fase 2), **borrado de slots** desde la lista y,
sobre todo, **carga real**: al confirmar un slot se deserializa y se arranca la escena replicando la
rama de ÉXITO nativa. Los controles se leen con nuestro overlay y se anula el input de la UI nativa.
Los mensajes de **Controller/Rumble Pak** quedan ocultos (vaciado del texto nativo cada frame).

## 1. Flujo (decidido con el mantenedor)

Análogo al del guardado, pero **A carga directo** (sin Yes/No; el original también carga al instante):

```
CONTINUAR ─▶ [Browse] lista de partidas; mensaje original modificado con bindings
              ├─ A sobre una partida con datos ─▶ CARGAR (deserializa + transición) ─▶ gameplay
              ├─ X (agacharse) sobre una partida ─▶ [ConfirmDelete] "Remove play data?" Yes/No
              │        ├─ Yes ─▶ borra ─▶ [Removed] "Remove completed." + flecha ↓ ─▶ A vuelve a Browse
              │        └─ No  ─▶ [Browse]
              └─ B ─▶ vuelve al MENÚ DE TÍTULO (rama de CANCELAR nativa; NO a la cápsula del guardado)
```

`Loaded` existe en el enum por simetría con `Completed`, pero la carga arranca la escena directamente
(no se muestra "Partida cargada."); queda reservado por si se quiere mostrar en el futuro.

## 2. Textos (originales + modificación coherente)

- Título `DATA LOAD` y subtítulo `MEMORY SLOTS` (este sustituye al nativo `CONTROLLER PAK`), ya de la
  Fase 2.
- Mensaje de `Browse`: SUSTITUYE al nativo `Select play data to be loaded.` por una frase con los
  bindings REALES (A carga, X borra). Clave en español en `kMenuTr` + traducciones; en **inglés**:
  ```
  Select play data to be loaded
  pressing A/J or X/H
  to remove.
  ```
  (Es la adaptación coherente de la frase del guardado: aquí se **carga**, no se guarda.) Lo construye
  `hh::menu::load_select_message()` (sustituye `%s` tras localizar, igual que `save_select_message`).
- Borrado y fin reutilizan los textos del guardado (`¿Borrar la partida?`/`Partida borrada.`) por
  consistencia; `Partida cargada.`/`Load completed.` queda definido (para el `Loaded` futuro).

## 3. Carga real (transición de escena) `[MEDIDO]`

Al confirmar A, `hh_do_load_game` replica la rama de **ÉXITO** de `func_801C3D84` (ret==1), que en el
juego hace `func_80142570()` + `func_800179B0(0)` + `func_801C11BC(0xA)` + `func_800058DC(obj,
func_801C3E24)`. Además:

1. `func_801423C8(0, slot)` lee el slot (`0x100+slot*0xD00`, `0xD00` B) y deserializa a los globals
   (`func_80141D08`); fija `D_801BBBF4` = índice de escena del slot.
2. `D_801CC8CC = 2` (flag del flujo de carga): `func_801C3E24` solo ejecuta la transición con ese
   valor. La transición real (`func_801C4074`) es **`func_8012FE50(0x18, D_801BBBF4, 6, 1, 0)`** —usa
   el índice de escena DESERIALIZADO, no un valor fijo—.

Es el **inverso** del guardado (`save_live`) y **no** pasa por la cápsula. Al salir (B), se replica la
rama de **CANCELAR** nativa (ret==2): `func_8012FE50(0x17, 0x73, 1, 1, 0)` + callback `func_801C40EC`
→ **menú de título** (coherente: CARGAR no es la cápsula).

## 4. Modelo (`include/hh/menu.h`, `src/subsystems/menu.cpp`)

- `enum class LoadPhase { Browse, ConfirmDelete, Loaded, Removed }` + `load_phase()/set_load_phase()`,
  `load_yes_selected()/set_`, `load_target_slot()/set_`, `load_input_blocked()` (bloqueo ~120 ms al
  entrar en `Browse`/`Removed`), `load_select_message()`, `close_load_game()`.
- `open_load_game()` ahora REINICIA la sesión (`g_load_open`): sin esto se quedaba la última fase y A
  solo salía (mismo bug que en guardar, §7bis de la nota del guardado). `close_load_game()` la cierra;
  lo llama `hh_goto_hook` en cada cambio de pantalla y las salidas de carga.

## 5. Input + render (`src/hooks/sections.cpp`, `src/hooks/menu_overlay.cpp`)

- `feed_load_flow(rdram, ctx, obj)` (análogo a `feed_save_flow`) controla las fases: arriba/abajo con
  repeat; A carga / X borra (bindings en vivo `hh_input_button_down`); B vuelve al título. Si sale
  (carga/volver) devuelve `true` y el hook NO corre el update nativo ni publica el overlay.
- `hh_file_select_hook` ya NO llama a `feed_menu_navigation` (su B habría cerrado la pantalla mal); usa
  `feed_load_flow`. Sigue mutando el input nativo de `0x80089478`.
- Render: la caja inferior ya dibuja el mensaje por fase (SavePhase o LoadPhase); Yes/No en
  `ConfirmDelete`; flecha ↓ en `Removed`.
- **Controller/Rumble Pak**: con el nativo oculto se vacían cada frame las `0x1C` ranuras de texto
  (`func_80142570`), como en el guardado; así el prompt `Please connect Controller Pak…` no se cuela.

## 6. Pendiente de validar en Windows

- `CONTINUAR → elegir slot → carga` (texto **y** mapa correctos) → gameplay.
- `B` en la lista → vuelve al **menú de título** (no a la cápsula).
- `X` sobre una partida → `Remove play data?` → `Remove completed.` → A vuelve a la lista.
- Sin cartel de Controller/Rumble Pak. F8 (nativo visible) sigue mostrando el DATA LOAD nativo.

## 7. Referencias

- Ciclo de guardado (plantilla): `notes/2026-09-30-save-capsule-logica.md`.
- File-select nativo (globals/cursor/estados): `notes/2026-09-29-menu-cargar-guardar-fase0-hallazgos.md`.
- Plan del menú carga/guardado: `notes/2026-09-29-menu-cargar-guardar-partida-plan.md`.
