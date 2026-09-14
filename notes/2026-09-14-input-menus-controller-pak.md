# 2026-09-14 — Gameplay: input inyectado, menús y Controller Pak

**Objetivo**: entrar en gameplay desde el título (el menú ya renderizaba; el bloqueo era input).

## Resumen

Se implementó **inyección de input headless** y se atravesaron título → menú principal →
submenú → GAME START. Para arrancar partida hubo que implementar un **Controller Pak (PFS)**
mínimo en el runtime. El puerto renderiza ya **escenas 3D in-game**. Frontera: un crash de
estado ~1 min después de GAME START en código del módulo 25 (`M25_FUN_801e2cac`).

## 1. Inyección de input por env (`src/game/input.cpp`)

Sin SDL ni ventana con foco (Xvfb no recibe teclas sin `xdotool`, no instalado):

- `HH_PRESS=<nombres|0xMASK>`, `HH_PRESS_AT=<s>`, `HH_PRESS_FOR=<s>`
- `HH_PRESS_SEQ="t1:start,t2:-,t3:a"` (cambios de estado; `-` suelta; tiempos en s)
- Botones: `a,b,z,start,dup,ddown,dleft,dright,l,r,cup,cdown,cleft,cright`.
- Sin env no cambia nada. Se apoya en `hh_injected_buttons()` dentro de `read_input_button()`.

## 2. Cadena de menús (evidencia: capturas)

| tiempo | acción | pantalla |
|---|---|---|
| ~60 s | START | menú principal: NEW GAME / CONTINUE / BATTLE MODE / SOUND / RESOLUTION (`port_one_90.png`) |
| ~84 s | START | GAME START / DIFFICULTY / EXIT (`port_two_150.png`) |
| ~105 s | A | "Controller Pak is not connected to 1P controller" |

- El primer START entra en la máquina de estados `FUN_80019898` (attr `0x8008EBD0`, tabla
  `0x8004CDD4`, `jr $t7` en `0x800198F0`).
- **No pulsar** en el menú desemboca en un callback con puntero nulo `[0x8008D608]`
  (`M24_FUN_801cb71c`, vía `FUN_80005270`) → SEGV. Navegar (2º START) lo evita; es un bug latente.

## 3. Símbolos: casos de switch vs funciones

- Los 7 casos de la tabla `0x8004CDD4` (0x800198F8..0x80019AB8) **NO son funciones**: N64Recomp
  genera `switch` con casos inline; partirlos deja el switch vacío → `switch_error` → abort.
  Se revirtieron y se documentó la regla.
- `add_missing_funcs` sí valida mid-entries reales; se añadieron:
  - planas: `0x800192F4, 0x80019E0C, 0x80019E7C, 0x8001922C, 0x8001A0A4, 0x80017594, 0x8001F74C, 0x8001F7D4`
  - módulo 24: `0x801C3D20, 0x801C3D90, 0x801C4A5C, 0x801C83C0, 0x801C8C28, 0x801CB71C`
  - módulo 25: `0x801E4AA0, 0x801F19A0, 0x801FBB3C, 0x801FC490, 0x801FC720, 0x801FCBE0, 0x801FF260`
- Herramientas nuevas/ajustadas:
  - `tools/analysis/auto_syms_loop.py`: run (soft lookup + input) → recolecta
    `Failed to find function` → añade planas (`add_missing_funcs`) o extras de módulo
    (`config/module_extras.json`) → `setup_module` + `recomp --build`; para ante `switch_error`.
  - `config/keep_syms_flat.txt` + soporte en `setup_module.py`: protege funciones planas de la
    fusión del validador (entradas de tablas de dispatch).
  - `switch_error` ahora imprime a stderr (se perdía por el abort).

## 4. Controller Pak (PFS) mínimo — `runtime librecomp/src/pak.cpp`

El runtime devolvía `PFS_ERR_NOPACK` en todo (el juego exige pak para GAME START). Se implementó:

- Pak de 32 KB en RAM con ficheros (empresa/código/nombre/ext/tamaño/datos), persistido a
  `saves/<nombre>.bin.pak` (magic `HHPK`).
- APIs: `osPfsInitPak`, `osPfsInit` (formato), `osPfsFreeBlocks`, `osPfsAllocateFile`,
  `osPfsFindFile`, `osPfsDeleteFile`, `osPfsReadWriteFile`, `osPfsFileState`, `osPfsNumFiles`,
  `osPfsIsPlug`, `osPfsChecker`, `osPfsRepairId`, `osPfsGetLabel`.
- `symbol_lists.cpp`: las 13 entradas movidas de `ignored_funcs` a `reimplemented_funcs`;
  `N64RecompCLI` reconstruido y recompilado el set.
- Resultado: GAME START deja de bloquear y se ven escenas 3D in-game
  (`port_pak_130.png`, `port_pak_150.png`, `port_pak2_190..230.png`).

## 5. Frontera actual

- Crash ~1 min tras GAME START: `M25_FUN_801e2cac` (funcs_59.c:2410, `lw $t7,0x8($t6)`), con
  `$t6 = [0x801DAB14] = 0x80000000` → lectura fuera de RDRAM. Mismo patrón de puntero inválido
  que el conocido `M25_FUN_801e2d94` (TODO #14). No aparecen símbolos faltantes.
- Falta confirmar **gameplay interactivo** (HUD/movimiento); las capturas son escenas de la
  intro/primer escenario.
- Bug latente: menú sin input → callback `M24_FUN_801cb71c` con `[0x8008D608]=0` (SEGV).

## Evidencia en `work/debug/`

- `port_one_90.png`, `port_two_150.png` — menús.
- `port_pak_130.png`, `port_pak_150.png`, `port_pak2_{190,210,230}.png` — escenas 3D in-game.
- `run_pak2.log` — SEGV en `M25_FUN_801e2cac`.
- `autosyms_loop.log`, `autosyms/iter_*.log` — ciclo de símbolos (16 direcciones).
