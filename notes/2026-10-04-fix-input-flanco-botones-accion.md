# Fix de input: "mantener pulsado" disparaba la acción repetidamente + unificación de la lectura

> Sesión 2026-10-04, rama **`main`** (v0.6.2). **VALIDADO en Windows por el mantenedor** (teclado y
> mando). `[MEDIDO]` = comprobado por build/traza; `[INFERIDO]` = deducido del código.

## 1. Síntomas

1. En el menú de título, al pulsar **CONTINUAR** a veces **no se veía el `DATA LOAD`**: se cargaba
   directamente el **primer slot**. El mantenedor lo asoció a un problema de "doble pulsación".
2. **Borrar un slot con el botón X del mando no funcionaba**: solo funcionaba la tecla H (teclado).
   En el juego original ambos son el botón **Z**.

Regla correcta: **una pulsación = una acción** (mantener no repite hasta soltar y volver a pulsar).
El **auto-repeat es propiedad del movimiento** (direcciones), **no** de los botones.

## 2. Causa raíz `[MEDIDO]`

El motor nativo lee **registros de flancos** (`func_801C1334`/`func_801C1340` → `+0x4`/`+0xC`), así que
en el original mantener A no repite. El bug era del port, y además había **inconsistencia de lectura**:
existían **tres vías** mezcladas para leer el mismo input.

- `read_input_button()` (`input.cpp`): **teclado + ratón + inyección**, pero **NO el mando**.
- `get_input()` (`input.cpp`): teclado + ratón + inyección + **mando**; es lo que llena la ranura del SI
  (`0x80089474`, `+0x2` = mantenido, `+0x4` = flancos).
- La ranura del SI (`0x80089476`/`0x8008947E`): mantenido reescrito por el poll del juego.

Los flujos propios leían aceptar/borrar con `hh_input_button_down()` (vía 1) o con la ranura (vía 3):

- `feed_load_flow`: `acc_btn/del_btn = hh_input_button_down("a"/"z")` → **nivel** y **sin mando**.
  `open_load_game()` fijaba `g_load_phase` directo, así que `load_input_blocked()` (~120 ms) no se armaba.
- `feed_save_flow`: mismo patrón (mantener A autoguardaba; mantener X autoborraba).

Cadena del bug de CONTINUAR: al confirmar CONTINUAR la A/START seguía pulsada; al arrancar el
file-select se leía como aceptar (nivel) y cargaba el slot 1 sin mostrar la UI. El bug del mando X:
`hh_input_button_down` **no incluye el mando**, solo teclado → por eso H (teclado) sí y X (mando) no.

## 3. Fix: lectura de acciones UNIFICADA `[MEDIDO]`

Se crea **una sola vía** para las **acciones** del menú, completa y con flanco estricto
(`src/subsystems/input.cpp`):

- `hh_read_gamepad_buttons()`: botones del **mando** (SDL) traducidos a N64 con el mismo mapeo que
  `get_input()`.
- `hh_input_action_edges()`: **máscara de FLANCOS** (0→1) del frame sobre
  `read_input_button() | hh_read_gamepad_buttons()` = **teclado + ratón + mando + inyección**, con
  **rearme** (mantener no repite). Se consume **UNA vez por frame**.
- `hh_input_action_seed()`: siembra el estado previo (la tecla/botón que **abrió** la pantalla no cuenta
  como flanco).

Aplicado de forma **consistente** en `src/hooks/sections.cpp`:

- `feed_menu_navigation` (título): aceptar (A/START) y atrás (B) por `action_edges`; los **selectores**
  (línea del bloque `toggle/selector`) también usan `action_edges` en vez de `pressed`.
- `feed_load_flow` (CARGAR): aceptar y **borrar (X/Z)** por `action_edges`; **B para volver** también.
- `feed_save_flow` (GUARDAR): aceptar y borrar por `action_edges`.
- **Direcciones intactas** (ranura + auto-repeat): scroll de listas y selectores izq/der.

### Por qué NO se OR-ea con `pressed` (ranura)
Primero se probó `action_edges || (pressed & A/START/X)`. Eso **reintroducía el repeat**: la ranura es
estado mantenido reescrito por el poll, su flanco local `prev` puede rearmarse (seed, frames perdidos,
muting del file-select) y disparar la acción **dos veces**. Se retiró: las acciones usan **solo**
`action_edges`; `pressed` queda **reservado a direcciones/auto-repeat**.

### Seed en el hook de apertura
El seed de acciones se llama en el **hook de apertura** (`hh_file_select_hook`/`hh_save_menu_hook`), en
el frame exacto en que `open_load_game()`/`open_save_game()` devuelve "apertura nueva" — **no** dentro
del flujo, para que no se cuele si el flujo no procesa ese frame. El seed de direcciones (`prev`) sigue
en el flujo.

- **Retirados** los bloqueos por tiempo `load_input_blocked()`/`save_input_blocked()` y sus marcas
  temporales (menu.cpp) + declaraciones (menu.h): con el flanco son redundantes.

`hh_input_button_down` queda **sin uso** en el port (era la fuente del bug); se conserva por si algún
test externo lo usa.

## 4. Ficheros

- `src/subsystems/input.cpp`: `hh_read_gamepad_buttons`, `hh_input_action_edges`, `hh_input_action_seed`.
- `src/hooks/sections.cpp`: acciones por `action_edges` en título + CARGAR/GUARDAR; seed en los hooks de
  apertura; B por `action_edges`.
- `src/subsystems/menu.cpp` + `include/hh/menu.h`: `open_load_game`/`open_save_game` devuelven "apertura
  nueva"; retirados los bloqueos por ms.

## 5. Verificación

- **Windows (mantenedor)**: mantener A/START al confirmar CONTINUAR → se ve `DATA LOAD` y **no** carga;
  soltar y volver a pulsar → carga. En GUARDAR: mantener A no autoguarda y mantener X no autoborra.
  **Borrar con X del mando funciona** (además de H de teclado). Teclado y mando a la vez. Direcciones:
  el scroll sigue repitiendo. **VALIDADO.**
- **Linux**: compila y enlaza (`HybridHeavenRecomp`).
- Headless (`HH_LOAD_TRACE=1`/`HH_SAVE_TRACE=1`): una pulsación = una acción.

## 6. Referencias

- Análisis del issue: `../../issue-input-mantener-pulsado-carga-slot.md` (carpeta padre del repo).
- Docs: `docs/menu.md` §Input. Tareas: `docs/TAREAS-HECHAS.md`, `RETOMAR.md`.
