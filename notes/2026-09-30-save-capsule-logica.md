# DATA SAVE — lógica de guardado en la cápsula (serializa y persiste)

> Sesión 2026-09-30 (5.ª). Rama **`menu-carga-guardado-partida`**. Tarea de `RETOMAR.md`: **cablear la
> lógica de guardado** del `DATA SAVE` (la UI ya estaba hecha en la 4.ª sesión,
> `notes/2026-09-30-save-data-ui-retoques.md`). **VALIDADO en Windows**: guardar, AREA 1-1, TIME, salida
> y reentrada. Todo `[MEDIDO]` del C recompilado salvo lo marcado `[INFERIDO]`. El §9 es el **handoff
> para terminar el ciclo de CARGA (CONTINUAR)**.

## 0. Resumen

Se implementa el flujo completo de guardado de la cápsula con una máquina de fases propia
(`hh::menu::SavePhase`) y, al confirmar, se **serializan los globals vivos** con el serializador
NATIVO (`func_80141F28`) y se persiste con `hh::save` (un único dueño del `.pak`). La salida de la
cápsula dispara la rama de salida de la máquina de estados nativa.

Flujo (decidido por el mantenedor):

```
Entrada ─▶ [Ask] "Save play data?" Yes/No            (slots OCULTOS)
             ├─ No  ─▶ [ConfirmExit] "Exit without saving?" Yes/No   (mensaje NUEVO del port)
             │            ├─ Yes ─▶ salir de la cápsula
             │            └─ No  ─▶ [Select]
             └─ Yes ─▶ [Select] "Select location in which to save play data." + slots
                          └─ A sobre NEW GAME/slot ─▶ [ConfirmHere]
                             "Saving current play data here." Yes/No (slots VISIBLES; slot marcado)
                                ├─ Yes ─▶ guardar ─▶ [Completed] "Save completed." + flecha ↓
                                │            └─ A ─▶ salir de la cápsula
                                └─ No  ─▶ [ConfirmExit]
```

## 1. Modelo (`include/hh/menu.h`, `src/subsystems/menu.cpp`)

- **`enum class SavePhase { Ask, Select, ConfirmHere, ConfirmExit, Completed }`**. Sustituye al
  booleano `g_save_confirm_state` (que solo distinguía Ask vs lista). `save_confirm()` se conserva
  como `phase == Ask`. Nuevas: `save_phase()/set_save_phase()`, `save_target_slot()/set_...` (-1 =
  NEW GAME).
- `save_slots_ready()`: false en `Ask`; en `Select` exige el retardo de ~0.5 s; en las fases
  posteriores los slots ya están listos (visibles).
- **`Action::SaveGamePick`** nuevo. `rebuild_load_game` asigna `SaveGamePick` (index = slot) a las
  filas de `SaveGame` (antes ponía `LoadGamePick`, cuyo handler solo actúa en `LoadGame`: por eso A
  no hacía nada). `NEW GAME` sigue con `SaveGameNew` e `index = -1`.
- Textos en `kMenuTr`: **"Saving current play data here."** y **"Save completed."** (nativos) y
  **"Exit without saving?"** (nuevo, en inglés; por decisión del mantenedor **no** se traduce al
  japonés). El JA de los dos primeros queda en inglés (no hay kanji utilizable; ver backlog JA).

## 2. Serialización + escritura (`src/subsystems/save_edit.cpp`)

`bool hh::save::save_live(int slot, uint8_t* rdram, recomp_context* base_ctx)`:
1. `func_8001F430(0xD00)` → buffer temporal en el heap del juego.
2. `func_80141F28(buffer)` → serializa los globals VIVOS (personaje, técnicas, items, progreso/escena)
   al **mismo layout de disco** que `osPfsReadWriteFile` escribiría.
3. `memcpy(g_bytes + slot_off(slot), rdram + MEM_OFF(buffer), 0xD00)` (bytes CRUDOS, sin swap: igual
   que el PFS; de ahí el word-swap del fichero).
4. `func_8001F540(buffer)` → libera.
5. `save(slot)` → checksums de todos los slots + `update_save_header` (cabecera 0..29 + trailer) +
   escritura del `.pak` + `hh_pak_reload_from_disk()`.

Por qué así (y no llamar a `func_80142450`): `func_80142450` = `alloc` + `func_80141F28` + escritura
PFS directa; escribir por el PFS dejaría a `hh::save` (con su modelo de N slots + trailer) desfasado.
Así `hh::save` sigue siendo el **único** escritor y la cabecera/trailer quedan coherentes.

`int hh::save::first_free_game_slot()`: primer slot de partida (0..44) con metadato `presente` a 0.
**No** usa `slot_used` (progreso != 0): una partida en 1-0 tiene progreso 0 y se tomaría por libre.

## 3. Input + salida (`src/hooks/sections.cpp`)

- `feed_save_flow(rdram, ctx)` sustituye a `feed_save_prompt` y controla las 5 fases: arriba/abajo
  alterna Yes/No en los prompts, o mueve el cursor de slots en `Select` (con el mismo *repeat* que
  `feed_menu_navigation`); A actúa según la fase (elegir slot, confirmar guardado, salir…).
- Al guardar: `NEW GAME` → `first_free_game_slot()`; slot con datos → su índice; luego `save_live`.
  Si va bien → `Completed`.
- **Salida de la cápsula** (`hh_leave_capsule`, **VALIDADO en Windows**): se replica la secuencia
  nativa EXACTA del envoltorio `func_803771A4` cuando `func_8013EB2C` devuelve 1:
  `func_80002A94(0)` + `func_800023A8(0)` + `func_80142570()` + `func_800058DC(obj, func_80377478)`.
  `obj` = `a0` del callback (capturado al entrar en `hh_save_menu_hook`). Fijar el estado nativo
  `0x801BEBCC=3` **no** salía (la rama no se alcanzaba en este flujo). Tras salir, `feed_save_flow`
  devuelve `exited` y el hook NO ejecuta el update nativo ni republica el overlay.
- Se deja de usar `feed_menu_navigation` en `SaveGame` (su B habría cerrado la pantalla).

## 4. Render (`src/hooks/menu_overlay.cpp`)

- Slots visibles salvo en `Ask` (sin retardo: aparecen de golpe al pasar `Ask`→`Select`).
- Mensaje por fase: `Save play data?` / `Select location…` (con bindings) / `Saving current play data
  here.` / `Exit without saving?` / `Remove play data?` / `Save completed.` / `Remove completed.`.
- Yes/No en `Ask`/`ConfirmHere`/`ConfirmExit`/`ConfirmDelete` (cursor `▶` nativo). En `Completed` y
  `Removed`, **flecha ↓** (`append_scroll_arrow(..., up=false)`).
- **OJO (bug corregido 2026-10-01)**: `save_select_message()` debe pasar a `localized()` la clave
  EXACTA de `kMenuTr` (con sus `\n`); si no coincide, `localized()` devuelve la canónica (español) y
  sin saltos. Los `%s` se sustituyen DESPUÉS de localizar.

## 5. Estado (VALIDADO en Windows, 2026-09-30 / 2026-10-01)

- **Guardado completo**: `NEW GAME` crea slot; el slot aparece en `CONTINUAR`/DATA LOAD con **AREA
  1-1, LEVEL y TIME** correctos; **sobrescribir** funciona.
- **Salida**: A en `Save completed.` cierra el mensaje y **saca al PJ de la cápsula**.
- **Reentrada**: al volver a entrar sale el prompt inicial (`Save play data?`) y se navega normal.
- **TIME**: correcto (run de ~3 min → `3:0x`; ver §8).
- **Área-Parte**: `1-1` (ver §8bis).
- **Borrado**: X sobre un slot con datos → confirmación → `Remove completed.` + A vuelve a `Select`
  (ver §8ter). **Validado**.
- **Mensaje `Select` con bindings** (ver §8ter): en inglés, 3 líneas
  `Select location in which to\nsave play data pressing A/J or X/H\nto remove.`; **validado**.

## 6. Cómo reproducir

```sh
cmake --build hybrid-heaven-recomp/build/linux --parallel $(nproc)   # OK (compila y enlaza)
```

## 7. Salida de la cápsula — FIX (2.ª parte de la sesión)

El primer intento (fijar el byte de estado nativo `0x801BEBCC=3` y dejar que `func_803771A4` la
ejecutase) **NO salía**: al pulsar A en `Save completed.` el mensaje no se quitaba. Se sustituye por
la **secuencia nativa explícita**, que es exactamente la que corre en el juego real:
`func_80002A94(0)` + `func_800023A8(0)` (rama de estado 3) + `func_80142570()` +
`func_800058DC(obj, 0x80377478)` (acción del envoltorio `func_803771A4` cuando la máquina devuelve 1).
`obj` = `a0` del callback (capturado al entrar en `hh_save_menu_hook`). Tras salir, el hook retorna sin
ejecutar el update nativo ni republicar el overlay. [`VALIDADO en Windows`]

## 7bis. Reentrada en la cápsula: reinicio del flujo (FIX)

Síntoma: tras salir de la cápsula (guardar/no guardar/salir), al **volver a entrar** salía el ÚLTIMO
mensaje (p. ej. `Save completed.`) y A solo servía para salir sin poder hacer nada. Causa: la pila del
modelo seguía siendo `[Root, SaveGame]` y `open_save_game()` hace *early-return* cuando ya está
abierta, así que **no reiniciaba la fase**. FIX: flag de sesión `g_save_open` (lo limpia
`close_save_game()`, que llama `hh_leave_capsule`); al entrar de nuevo se fuerza `SavePhase::Ask`,
`Yes` y cursor en `NEW GAME`.

## 8. TIME (VALIDADO) + traza (`HH_SAVE_TIME_TRACE=1`)

- `update_save_header` **no escribía TIME** (lo conservaba del trailer): un slot nuevo quedaba a
  `0:00`. Ahora `hh::save::save(slot, …, time)` / `update_save_header(slot, time)` escriben TIME en el
  **trailer** (`+4..5`) y en la **cabecera del juego** (registro `+4..5`).
- **TIME = `[0x801BBBF0+0xA]` (u16 BE), VALIDADO en Windows (2026-09-30)**: `save_live` lo lee y lo
  escribe en el trailer/cabecera. En una run de ~3 min hasta la cápsula, el slot guardado muestra el
  tiempo correcto (`3:0x`). El descriptor nativo de `func_80141268` confirma la fuente.
- **Traza** (se conserva, opt-in): `HH_SAVE_TIME_TRACE=1` vuelca cada ~0,5 s (en
  `hh_battle_frame_hook`) todo el bloque `0x801BBBF0` (`00..3E`), `0x8017DC88` y `0x8017DC40+0x48` con
  el contador VI, y una muestra `save` al guardar.

## 8bis. Área-Parte de la cabecera (FIX; 3 iteraciones)

Síntoma: tras guardar en 1‑1 el slot se veía **`0-0`** (y luego `0-3`). El Área de la cabecera salió
de, en este orden y descartando:

1. **`progress_of` = `0x564`** (índice de ESCENA del slot: **0** en 1‑1) con `prog/10, prog%10` →
   `0-0`. Es el campo del MAPA, no el Área de la cabecera.
2. **`0x366`** (`PROGRESO`, u16 BE del slot) → daba `3` → `0-3`; **no** es `area*10+sub` de forma
   fiable en el slot serializado (pese a que los `.pak` nativos de 1‑1 lo tienen a 11).
3. **`0x801BBBF0+4` (u16 BE), ÍNDICE DE ESCENA VIVO** → mapeado con la MISMA tabla que el selector
   PROGRESO (`hh::menu::area_sub_from_value`, `kAreaPartsSave`): 1‑1 = `0` → `1-1`, 1‑2 = `2` →
   `1-2`, 2‑1 = `10` → `2-1`. **ELEGIDO** (`save_live`). Coincide con el header nativo de los `.pak`
   reales (`[1,1,1,1,…]` = 1‑1).

Además, **`header_magic_ok()` estaba roto**: comparaba `"HYBRID HEAVEN"` en orden natural, pero el
fichero va **word-swapped** → siempre `false` → `sync_meta_from_header` y la escritura de la cabecera
del juego **nunca ocurrían** (de ahí que el trailer y la cabecera divergieran). FIX: revertir,
comprobar y volver a revertir.

`save_live` registra en `hh.log`: `scene`, `func_80108280()` (fuente del header nativo), `0x564` y
`0x366`, para diagnosticar cualquier caso raro.

**Lección**: para metadatos del save, preferir la **fuente VIVA** (globals del juego) y mapearla con
las tablas del port, antes que campos del slot cuya semántica depende del `word-swap`.

## 8ter. Mensaje `Select` con bindings + borrado de slots

**Mensaje**: en `Select` se SUSTITUYE el nativo `Select location in which to save play data.` por una
frase que informa de **ambas** acciones con sus bindings REALES (en vivo, remapeables). Clave en
español en `kMenuTr` + traducciones; en **inglés**:
```
Select location in which to
save play data pressing A/J or X/H
to remove.
```
(3 líneas; el `\n` va tras `to`, como el nativo. `A/J` y `X/H` = botón/tecla de ACEPTAR y AGACHARSE.)
Lo construye `hh::menu::save_select_message()` (sustituye `%s` tras localizar; ver §4).

**Borrado**:
- **A** (aceptar) → `ConfirmHere` (guardar).
- **X** (agacharse, `z`) sobre un slot **con datos** → `ConfirmDelete` (`Remove play data?` Yes/No);
  Yes → `hh::save::delete_slot()` + `flush()` → `Removed` (`Remove completed.` + flecha ↓).
- **Removed** + A → **vuelve a `Select`** (NO sale de la cápsula). `Completed` + A sí sale.
- El input se lee con `hh_input_button_down("a"/"z")` (nuevo `extern "C"` en `input.cpp`: binding de
  mando+teclado en el frame actual). Así A/J guarda y X/H borra aunque el jugador haya remapeado.
  `NEW GAME` no se puede borrar (no es un slot con datos). Para que la A del prompt `Ask` no
  seleccione el slot en el acto, al entrar en `Select`/`Removed` se ignora el input ~120 ms
  (`save_input_blocked()`). **Validado**.

## 9. Handoff: UI de carga en `CONTINUAR` (siguiente tarea)

Objetivo: que un slot del menú `LoadGame` (CONTINUAR) **cargue de verdad** el estado y arranque la
escena. El ciclo de GUARDAR (§2–§8ter) es la plantilla; CARGAR reutiliza casi todo.

**Lo que YA hay** (`src/hooks/sections.cpp`, `src/hooks/menu_overlay.cpp`):
- **Enganche a CONTINUAR**: al confirmar `CONTINUAR` en la raíz se llama a la rama nativa
  `func_801C3CDC` (ver `feed_menu_navigation`); el update del file-select `func_801C3D84` está
  envuelto por `hh_file_select_hook`, que hace `open_load_game()`, mutea el input nativo
  (`0x80089478`), oculta el DATA LOAD nativo (categoría FILE-SELECT) y publica el overlay.
- **UI 1:1**: `LoadGame` dibuja título color3, subtítulo, cajas por slot y `NO DATA`, leyendo
  metadatos del **trailer** (`hh::save::slot_present/meta_*`). Ya está validada como maqueta.
- **Cargar/deserializar**: `Action::LoadGamePick` (en `feed_menu_navigation`) ya llama a
  `func_801423C8(0, slot)` (lee el slot `0xD00` y deserializa a globals con `func_80141D08`).

**Lo que FALTA** (con recetas):

1. **UI de carga propia (esta tarea)**: definir el flujo del `LoadGame` igual que el `SaveGame`:
   - preguntar/confirmar con **A** sobre un slot (y **B** para volver al título), con el mensaje y
     Yes/No reutilizando el estilo del guardado;
   - mensaje de confirmación y, si aplica, mensaje de fin (`Load completed.`?) — **decidir con el
     mantenedor** antes de dibujar (regla AGENTS: no inventar UI).
   - Reutilizar: `kMenuTr` (clave española + traducciones), el constructor de mensaje con bindings
     (`save_select_message()` es el patrón), `append_box`/`append_native_cursor`/`append_scroll_arrow`.
   - Opcional: **X** (agacharse) para borrar un slot desde CARGAR (mismo patrón que §8ter).
2. **Arrancar la escena tras `func_801423C8(0, slot)`** (es el "inverso" de `save_live`):
   - El flujo nativo de CONTINUE hace, al devolver `!=0` el update del file-select:
     **`func_80142570()` + `func_8012FE50(tipo=?, valor=?)`** (transición). **Medir los args** con
     `HH_TRACE`/`HH_MENU_TRACE` (el plan `notes/2026-09-29-menu-cargar-guardar-partida-plan.md` §1 cita
     `tipo=0x17, valor=0x73…`; **no fiarse sin trazar**).
   - Alternativa más simple y ya probada: dejar que la **rama CONTINUE nativa** haga setup+transición
     (la vía que usó el port antes de tener UI; ver `notes/2026-09-26-d-continuar-y-bugs-visuales.md`).
3. **Cerrar la sesión al salir** (mismo bug que en guardar, §7bis): `open_load_game()` hace
   *early-return* si la pila ya es `[Root, LoadGame]`; añadir `close_load_game()`/flag `g_load_open`
   análogos (o generalizar el de guardar) y llamarlo en `hh_goto_hook`/salida.
4. **No republicar el overlay** tras la transición (patrón `exited`/`goto_before/after` de
   `hh_save_menu_hook`) y `hh::menu_overlay::hide_now()`.
5. **Ocultado pendiente (Fase 3)**: con F8 (nativo visible) se cuela el prompt
   `Please connect Controller Pak…`. El flujo propio no debe depender del Controller Pak (PFS virtual).
6. **Validar en Windows**: `CONTINUAR → elegir slot → carga` (texto **y** mapa correctos) → `F8` → `A`.

**Reutilizable del ciclo de guardado**: máquina de fases (`SavePhase` como plantilla de fases de
carga), reset de sesión (`g_save_open`/`close_save_game`), salida/transición nativa explícita
(`func_80002A94`+`func_800023A8`+`func_80142570`+`func_800058DC`), `memcpy` crudo del slot,
`first_free_game_slot`, `area_sub_from_value` y `save_select_message()` (patrón de mensaje con
bindings).

**Reutilizable del ciclo de guardado**: la máquina de fases (`SavePhase`), el reset de sesión
(`g_save_open`/`close_save_game`), el patrón de salida nativa explícita (`func_80002A94`+`func_800023A8`
+`func_80142570`+`func_800058DC`), el `memcpy` crudo del slot, `first_free_game_slot`, y `area_sub_from_value`
(para mostrar/validar el Área del slot).

## 10. Referencias

- UI previa del `DATA SAVE`: `notes/2026-09-30-save-data-ui-retoques.md`.
- Formato del slot y serializador: `notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md`.
- Plan del menú de carga/guardado: `notes/2026-09-29-menu-cargar-guardar-partida-plan.md`.
