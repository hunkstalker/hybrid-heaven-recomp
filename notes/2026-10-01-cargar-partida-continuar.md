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
→ **menú de título** (coherente: CARGAR no es la cápsula). Esa transición recarga el módulo de título y
reproduce la **cinemática de arranque** (logos KONAMI/KCEO) antes del menú: es la ruta NATIVA de
vuelta, no un bug del port.

**FIX vuelta (2026-10-01)**: `close_load_game()` ahora **RETIRA `LoadGame` de la pila del modelo**
(`pop`). Sin el pop, la pila seguía siendo `[Root, LoadGame]`: al volver al TÍTULO, `title_update`
publicaba `current_screen()` = LoadGame y se veía **la pantalla de carga en vez del menú** (bug
reportado por el mantenedor). Además se resetea `sel` (`0x801CC8C4`) a 0 al salir. `close_load_game`
lo llama `hh_goto_hook` en cada cambio de pantalla (no-op si el tope no es LoadGame). Evidencia:
`hh.log` 2026-10-01 — tras `salir de CARGAR`, las publicaciones pasan a `screen=0` (Root) y `screen=19`
**no vuelve a aparecer**; queda en el menú de título.

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

## 6. Estado (VALIDADO en Windows, 2026-10-01)

- **Entrada** `CONTINUAR`: se ve el título y, al arrancar el file-select, la UI de carga limpia (sin
  superposición del título/logo, sin parpadeo, sin retardo). **VALIDADO**.
- **Vuelta** con `B`: cinemática nativa → **menú de título** (ya no reaparece la pantalla de carga).
  **VALIDADO**.
- `X` sobre una partida → `Remove play data?` → `Remove completed.` → A vuelve a la lista.
- Sin cartel de Controller/Rumble Pak. F8 (nativo visible) sigue mostrando el DATA LOAD nativo.

## 6bis. Traza HH_LOAD_TRACE y bugs encontrados en el run de Windows (2026-10-01)

Traza `HH_LOAD_TRACE=1` (en `hh_file_select_hook`, tags `pre`/`post` del update nativo) → `hh_trace.log`
con: fase, cursor del modelo, cursor/top/estado/página NATIVOS del file-select
(`D_801BEC05/D_801BEC04/D_801BEBCC/D_801BEC02`) y `fs_active`/`native_visible`. Launcher:
`run_load_trace.bat`.

**Hallazgos [MEDIDO]:**
1. **Cursor que "volvía arriba"** (corregido en `6a916c7`): `open_load_game()` rehacía
   `rebuild_load_game()` cada frame y este fuerza el cursor al primer slot con datos. Ahora
   `open_load_game` hace early-return si ya está abierta.
2. **`g_file_select_active` no se reseteaba al salir** (corregido en `3c5ca37`): tras `B`/cargar,
   `file_select_text_skip()`/`suppress_box_draw()` seguían a true hasta que corría
   `hh_title_menu_hook` (varios frames después). Efecto: el compositor de texto **blanqueaba las
   etiquetas del MENÚ DE TÍTULO** (comparte el hook `func_8001B204`) → título vacío/texto fantasma y,
   al agotar el idle, attract. Prueba en la traza: `native cur/st=0` siempre y `fs_active=1`
   persistente tras salir; `[native] filter text=801CECFC` (etiqueta del TÍTULO) blanqueada 914 veces.
   Fix: `set_file_select_active(false)` en `hh_leave_load_game`/`hh_do_load_game`.
3. **Vuelta con `B` acababa en la pantalla de carga** (corregido): `close_load_game()` no quitaba
   `LoadGame` de la pila del modelo, así que al volver al título `title_update` publicaba LoadGame.
   La traza nueva `HH_LOAD_TRACE` cuenta cada publicación (`publica CARGAR/GUARDAR #n … depth=N`) y
   cada entrada al file-select (`file-select ENTRADA #n … sel=…`): tras `salir de CARGAR` no hay más
   entradas y las publicaciones pasan a `screen=0` (Root) → **VALIDADO** por el mantenedor.

**Nota de comportamiento (a confirmar en Windows):** el flujo nativo de CONTINUE/CANCELAR usa
`func_80005670(obj, 0x80044090)` (mismo descriptor de transición que GAME START), y la rama de
cancelar `func_801C3E24`/`func_801C40EC`. La secuencia replica la del juego; si al volver se reproduce
parte de la intro, es la ruta nativa de esta pantalla, no un bug del port.

## 6ter. Secuencia de entrada a CARGAR, frame a frame (capturas 2026-10-01)

Capturas del mantenedor (`work/gameplay screenshots/CONTINUAR/Captura … 03:01:58 … 03:07:28`), al
pulsar CONTINUAR:

1. **Instante 1**: nuestra UI de carga se dibuja **encima del menú de título** (logo `HYBRID HEAVEN`,
   KONAMI, copyright aún pintados por la escena de título).
2. **Instante 2**: perfecto (título ya limpio).
3. **Instante 3**: **desaparecía TODO** (nuestro overlay incluido).
4. **Instante 4**: se colaba el mensaje del **Controller Pak** suelto (sin caja):
   `…to Controller 1 now.Do not remove Controller Pak.▼`.
5. **Instante 5**: perfecto.

**Causas y fixes:**
- **Instante 3** = `hh_goto_hook` hacía `hide_now()` en los `goto` internos del setup/update
  (`0x801C3D50`/`0x801C3D84`) durante la transición → ocultaba nuestra UI un frame. Fix `00083cd`:
  con `g_load_enter` activo, `hh_goto_hook` NO hace `hide_now()` ni `close_load_game()`.
- **Instante 4** = `func_800179B0` (residente) compone/dibuja el aviso del Controller Pak
  (`D_8004CC90`) con `func_8001A804` (cajas, ya saltadas) y `func_8001B204` (texto). Fix `36be126`:
  hook nuevo `hh_pak_message_hook` (registrado en `0x800179B0`) que **salta la función entera** cuando
  `suppress_box_draw()` (file-select activo + nativo oculto), como las cajas.
- **Instante 1** (título/copyright debajo 1 frame) = la **escena de título** aún renderiza su logo/
  copyright mientras arranca el file-select; son draws de escena (no etiquetas `func_8001B204`), así
  que no los cubre el blanking. **NO se usa telón negro** (el original no lo tiene; además el telón
  del overlay se dibuja el último y taparía también nuestra UI). Fix: **no publicar** nuestra UI
  durante `g_load_enter` — se conserva el frame del TÍTULO (como el original) hasta que el file-select
  publica la UI de carga en su primer frame. Así no se ve la UI de carga superpuesta al logo/copyright.

Relación de `func_800179B0` con el flujo: lo llama `func_8013E7C0` (setup LOAD) y la rama de salida
`func_801C3D84`; compone 7 cajas + 0x1C cadenas del mensaje (`resident.s:27022`).

## 7. Referencias

- Ciclo de guardado (plantilla): `notes/2026-09-30-save-capsule-logica.md`.
- File-select nativo (globals/cursor/estados): `notes/2026-09-29-menu-cargar-guardar-fase0-hallazgos.md`.
- Plan del menú carga/guardado: `notes/2026-09-29-menu-cargar-guardar-partida-plan.md`.
