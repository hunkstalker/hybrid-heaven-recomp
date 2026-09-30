# DATA SAVE — retoques de la UI propia (copia de CARGAR) + ocultado del nativo

> Sesión 2026-09-30 (4.ª). Rama **`menu-carga-guardado-partida`** (nada pusheado). Tarea de
> `RETOMAR.md`: retoques de la UI del `DATA SAVE` (cápsula). **No** se implementa la lógica de
> guardado (queda para la próxima sesión, ver `../RETOMAR.md`). Todo `[MEDIDO]` sobre el port (log /
> capturas pareadas) y el emulador salvo lo marcado `[INFERIDO]`.

## 0. Resumen

La vía de guardado en la cápsula es **distinta** a la de cargar: callback **`0x803771A4`** →
`func_8013EB2C` (NO pasa por `0x801C3D84`, el del DATA LOAD). Setup **`0x80377140`** → `func_8013EA94`
→ `func_80142778` (compone `ＤＡＴＡ　ＳＡＶＥ`). Con esos hooks publicamos la UI propia (copia de la de
cargar) **encima** del `DATA SAVE` nativo y **ocultamos** el nativo por la categoría FILE-SELECT (F8).
Añadimos prompt `Save play data?` con `Yes/No`, la lista de GUARDAR (`NEW GAME` + slots con datos),
puntuación real de la ROM y sonidos.

## 1. Enganche del DATA SAVE (nuevo)

- `add_loaded_function(0x803771A4, hh_save_menu_hook)` y `(0x80377140, hh_save_setup_hook)` (en
  `register_title_menu_hook`, `src/hooks/sections.cpp`).
- `hh_save_setup_hook`: activa la categoría FILE-SELECT **antes** de que `func_80377140` componga el
  título (para que el skip lo cubra, igual que en CARGAR).
- `hh_save_menu_hook`: publica `SaveGame`; **F8** (`g_native_visible`) oculta/muestra el nativo;
  anula el input nativo (`0x80089478`, A/B/Start) durante **todo** el frame mientras controlamos.

## 2. Estado del prompt `Save play data?` (Yes/No)

- La UI propia arranca con el prompt: título `DATA SAVE`, subtítulo `MEMORY SLOTS`, y en la caja
  inferior `Save play data?` + `▶Yes` / `No` (cursor `kLoadCursor`).
- **Posiciones `[MEDIDO]`** (captura emulador del prompt, caja en `y=171`): `Yes` y = **caja+15**,
  `No` y = **caja+27,5**; texto de opción x = **caja+31**; cursor `▶` x = **caja+22** (+3 al alto de
  línea). Verificado Δ<0,5 px.
- **Navegación**: arriba/abajo alterna `Yes/No` (`set_save_yes_selected`); **A** confirma la opción
  resaltada. Mientras se pregunta, los slots están **ocultos**.
- **SFX**: mover = `Sfx::Move`; A = `Sfx::Accept` (los mismos que al navegar los slots).
- `hh_file_select_hook`-style: el control del prompt lee el input mantenido (`0x80089476/0x8008947E`).

## 3. Slots de GUARDAR (lista y render)

- Al pulsar **A sobre Yes** → `set_save_confirm(false)`: el mensaje pasa a
  `Select location in which to\nsave play data.` (salto de línea tras *to*) y `Yes/No` desaparecen.
- Los slots aparecen **~0,5 s** después (`save_slots_ready()`, retardo del nativo).
- **Lista** (`rebuild_load_game`): para `SaveGame` = **`NEW GAME`** (primera, `Action::SaveGameNew`,
  `index=-1`) + **solo los slots con datos** (`slot_present`). Todos seleccionables (el cursor no
  salta ninguno). `LoadGame` sigue igual (45 slots, vacíos `NO DATA`).
- **Render**: `NEW GAME`/`NO DATA` **centrados** (h y v); filas con etiqueta a la izquierda y
  **valor alineado a la derecha** (`box_x+box_w-7`); `ETIQUETA\tVALOR` en el modelo.
- **Caja de slot**: alto **40 px** (par, para centrar en px enteros); **marco exterior** `h=98`
  (6 px de aire arriba y abajo).

## 4. Puntuación real de la ROM (nada a mano)

`func_8001D394` da el valor de glifo de cada carácter; **`color0` y `color4` comparten** la tabla.
Medido: `?`→75, `!`→74, `.`→64, `:`→66, `,`→63, `-`→70, `/`→73, `%`→78… Con eso el overlay ya no
dibuja `:`/`.`/`-`/`%` a mano (`glyph_value`), y el `¿` español es el `?` **girado 180°** (UVs
invertidas) en `Color4`.

## 5. Ocultado del nativo y F8 (causa raíz encontrada)

- **`func_80142570`** (lo llama el compositor) **vacía las 0x1C ranuras** de texto componiendo cadenas
  **vacías** vía `0x8001B204` con `a3=0x8018F0F0`. Nuestro skip del compositor **también** saltaba esas
  llamadas → al pulsar **F8-off** el texto ya compuesto **no se borraba** y quedaba pegado.
  **Fix**: dejar pasar las llamadas de vaciado (`a3==0x8018F0F0`) aunque el nativo esté oculto
  (`hh_entry_register_hook`).
- El prompt `Save play data?` se **compone por otra vía** distinta al compositor que saltamos; como
  mitigación, con el nativo oculto se llama cada frame a `func_80142570` para limpiar sus ranuras.
- Los a3 del file-select medidos (log `HH_MENU_TRACE`): `0x8018F0F0` (vaciado), `0x8018F1BC`
  (título `DATA SAVE`), `0x8018F1D4` (`CONTROLLER PAK`), `0x8018F49C`/`0x8018F4A0`.

## 6. Japonés (aparcado)

La única fuente del juego con **kana usable** es `color0` (8×8) y `color1` (10×10) (idénticas US↔JP, y
el motor mapea kana en ambas). `color4` **no tiene kana** y `color3` (12×13) tiene kana/kanji pero el
motor **no** la mapea (`func_8001D394(color=3, kana)=0`). El `color3` **JP** es un fichero distinto
(fuente japonesa con kanji) que **no** tenemos (requeriría la ROM JP). Conclusión: el japonés de estos
textos solo se puede hacer en kana con `color0`/`color1`; queda **aparcado**. Hay trabajo sin
consolidar: `Face::Color1` en el atlas y traducciones JA en `kMenuTr` (inocuos con idioma ≠ ja).

## 7. Pendiente (para la próxima sesión — ver `../RETOMAR.md`)

**Todo la lógica de guardado.** La UI nueva ya expone el estado (`save_confirm`, `save_yes_selected`,
`save_slots_ready`, `Action::SaveGameNew`); falta:
1. Al confirmar (A) `NEW GAME` o un slot con datos → mensaje **`Saving current play data here.`** +
   `Yes`/`No`. **Yes** = guardar (NEW GAME → siguiente slot libre; slot con datos → sobrescribir).
2. **No** → mensaje nuevo (NO del juego original, en inglés) preguntando si quiere **salir** (`Yes/No`):
   **Yes** = el PJ sale de la cápsula; **No** → volver al estado
   `Select location in which to save play data.`

## 8. Cómo reproducir

```sh
# Build
cmake --build hybrid-heaven-recomp/build/linux --parallel $(nproc)
```
Captura headless (forzando pantalla): `HH_MENU_SCREEN=20 HH_LANG=es` (o `=19` para CARGAR). El estado
post-Yes solo se ve en la cápsula real (Windows/emulador).
