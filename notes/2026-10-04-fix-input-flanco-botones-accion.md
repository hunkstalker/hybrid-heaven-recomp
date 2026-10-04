# Fix de input: "mantener pulsado" disparaba la acción repetidamente (CARGAR/GUARDAR)

> Sesión 2026-10-04, rama **`main`** (v0.6.2). **VALIDADO en Windows por el mantenedor.**
> `[MEDIDO]` = comprobado por build/traza; `[INFERIDO]` = deducido del código.

## 1. Síntoma

En el menú de título, al pulsar **CONTINUAR** a veces **no se veía el menú `DATA LOAD`**: se cargaba
directamente el **primer slot**. El mantenedor lo asoció a un problema de "doble pulsación" ya
comentado en sesiones anteriores.

Regla correcta: **una pulsación = una acción**. Con el botón mantenido no debe haber otra pulsación
hasta soltar y volver a pulsar. El auto-repeat es propiedad del **movimiento** (direcciones), no de
los botones.

## 2. Causa raíz `[MEDIDO]`

El motor nativo lee **registros de flancos** (`func_801C1334`/`func_801C1340` → registros `+0x4`/`+0xC`),
así que en el original mantener A **no** repite. El bug era del port: los flujos propios leían el
**estado mantenido** con `hh_input_button_down()` (nivel, `read_input_button()`), no el flanco.

- `feed_load_flow`: `acc_btn = hh_input_button_down("a")` y `del_btn = hh_input_button_down("z")`
  usados como "aceptar/borrar". `open_load_game()` fijaba `g_load_phase` directo, así que el bloqueo
  `load_input_blocked()` (~120 ms) **no se armaba** en la entrada.
- `feed_save_flow`: mismo patrón (`acc_btn`/`del_btn` de nivel) → mantener A **autoguardaba** en el
  primer hueco y mantener X **autoborraba**.

Cadena del bug de CONTINUAR: al confirmar CONTINUAR la A/START seguía pulsada; al arrancar el
file-select, `feed_load_flow` la veía como aceptar (nivel) y cargaba el slot 1 sin mostrar la UI.

## 3. Fix `[MEDIDO]`

Comportamiento normal de videojuego: **flanco (0→1) para los botones de acción**, auto-repeat solo
para las direcciones.

- `feed_load_flow`/`feed_save_flow`: A/START/X pasan a leerse con el **flanco** ya existente
  `pressed = btn & ~prev`, donde `btn = rh16(0x80089476) | rh16(0x8008947E)` es el estado **mantenido
  completo** (teclado **y** mando). Mantener no repite; soltar y volver a pulsar sí.
  - Carga: `pressed & (0x8000|0x1000)` (A/START); borrado: `pressed & 0x2000` (X/Z).
  - Guardado: ídem (`ConfirmHere` / `ConfirmDelete`).
- **Anti-rebote de entrada** por *seed* de `prev` en la apertura de cada pantalla:
  - `open_load_game()` / `open_save_game()` ahora devuelven `true` si fue **apertura nueva**; el hook
    correspondiente marca `g_load_seed_input` / `g_save_seed_input`; el flujo traga el estado
    mantenido **un frame** (mismo patrón que `g_menu_seed_input` del título). Así la A/START que abrió
    CONTINUAR/la cápsula no cuenta como flanco.
- **Retirados** los bloqueos por tiempo `load_input_blocked()` / `save_input_blocked()` y sus marcas
  temporales `g_*_ignore_input_tp` (menu.cpp) + declaraciones (menu.h): con el flanco son redundantes.
- **Direcciones intactas**: el auto-repeat de scroll en CARGAR/GUARDAR (y selectores izq/der del
  título) no se toca.

`hh_input_button_down` queda **sin uso** en el port (era la fuente del bug); se conserva definido en
`input.cpp` por si algún test lo usa.

## 4. Ficheros

- `src/hooks/sections.cpp`: `feed_load_flow`/`feed_save_flow` (flanco + seed), hooks
  `hh_file_select_hook`/`hh_save_menu_hook` (marcan seed), `g_load_seed_input`/`g_save_seed_input`.
- `src/subsystems/menu.cpp`: `open_load_game`/`open_save_game` devuelven "apertura nueva"; retirados
  los bloqueos por ms.
- `include/hh/menu.h`: firmas `bool` + retiradas `*_input_blocked`.

## 5. Verificación

- **Windows (mantenedor)**: mantener A/START al confirmar CONTINUAR → se ve `DATA LOAD` y **no** carga;
  soltar y volver a pulsar → carga. En GUARDAR: mantener A **no** autoguarda y mantener X **no**
  autoborra. Direcciones: el scroll sigue repitiendo. **VALIDADO.**
- **Linux**: compila y enlaza (`HybridHeavenRecomp`).
- Headless (`HH_LOAD_TRACE=1`/`HH_SAVE_TRACE=1`): una pulsación = una acción.

## 6. Referencias

- Análisis del issue: `../../issue-input-mantener-pulsado-carga-slot.md` (carpeta padre del repo).
- Docs: `docs/menu.md` §Input. Tareas: `docs/TAREAS-HECHAS.md`, `RETOMAR.md`.
