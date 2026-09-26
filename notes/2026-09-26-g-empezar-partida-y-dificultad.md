# EMPEZAR PARTIDA y DIFICULTAD (disparo nativo de GAME START)

> Sesión 2026-09-26 (g), rama `menu-nativo`. Implementa el **arranque de partida nueva** desde el
> overlay reutilizando el flujo nativo, sin reimplementarlo. Estado/pendientes: `TODO.md`; diseño:
> `docs/menu.md` §Acciones nativas.

## Objetivo

Que `EMPEZAR PARTIDA` (subpantalla `NUEVA PARTIDA`) arranque la partida nueva con la **dificultad
elegida**, y que `DIFICULTAD` alimente esa elección.

## Análisis del menú nativo (C recompilado, `build/recomp/RecompiledFuncs/funcs_68.c`)

- **Raíz** `func_801C1DB8`: `sel` (`0x801CC8C4`) 0..4 = `NEW GAME / CONTINUE / BATTLE MODE / SOUND /
  RESOLUTION`. El caso 0 (NEW GAME) **abre un submenú**: `func_801C3940` → `func_801C3A40`.
- **Submenú `NUEVA PARTIDA`** `func_801C3A40`: 3 opciones con cursor en `0x801CC8C8`:
  - idx 0 **GAME START** → `func_80005670(obj, 0x80044090)` + `func_800058DC(obj, func_801C3BA4)`;
    la cadena `func_801C3BA4 → func_801C3BD8 → func_801C3C14` **crea la partida**.
  - idx 1 **DIFFICULTY** → `func_801C4C7C` (lista `ULTIMATE/HARD/NORMAL/EXIT`).
  - idx 2 **EXIT** → `func_801C56B8` (vuelve a la raíz).
- `func_801C3940` solo hace dos cosas útiles al entrar: **resetea** `0x801CC8C8` y **la dificultad**
  (`0x801BBC0D = 0`), y **registra las 7 etiquetas** del submenú en `0x801CED10`. El overlay ya
  dibuja esas etiquetas, así que **no** conviene pasar por él (resetearía nuestra dificultad).
- **Dificultad**: byte global `0x801BBC0D`, escrito por `func_801C4E90` y leído por el init de
  partida (`func_801CB27C`). Valores: `0=NORMAL`, `1=HARD`, `2=ULTIMATE`.

## Por qué no se pilota el submenú nativo

El overlay **reemplaza** los submenús nativos (SOUND/RESOLUTION/CONFIGURACIÓN) con "control total"
(ver `docs/menu.md` §Input). Pilotar `func_801C3940`/`func_801C3A40` obligaría a mantener un **UI
nativo paralelo y oculto** sincronizado con el nuestro (pantalla↔handler, cursor, volver con B,
timer, supresión de tablas) para una sola acción. En su lugar, la hoja del overlay **dispara la
acción nativa de forma puntual** (mismo patrón que `CONTINUAR`). Si algún día se reutiliza un
submenú nativo entero (`MODO COMBATE`), será un diseño aparte con sus hooks.

## Implementación (`src/hooks/sections.cpp`)

- Nueva rama `Action::StartGame` en `feed_menu_navigation`:
  1. Dificultad = opción marcada de `ScreenId::Difficulty` (orden del overlay inverso al nativo:
     `DEFINITIVO→2`, `DIFÍCIL→1`, `NORMAL→0`); se escribe en `0x801BBC0D`.
  2. `func_80005670(obj, 0x80044090)` y `func_800058DC(obj, 0x801C3BA4)` (réplica de idx 0).
  3. `obj` = `a0` del handler = `ctx->r4`, capturado al principio de `feed_menu_navigation`.
- `include/hh/menu.h` + `src/subsystems/menu.cpp`: nuevo acceso de solo lectura
  `const Screen* screen(ScreenId)` para consultar otra pantalla (la dificultad marcada).

## Estado

- **Compila en Linux** (`cmake --build build/linux`).
- **`EMPEZAR PARTIDA` VALIDADO en Windows (2026-09-26)**: arranca partida nueva.
- **`DIFICULTAD`**: implementada (escribe `0x801BBC0D` con la opción marcada); el mantenedor confía
  en la implementación, pero su **efecto real en el juego** (daño de los enemigos) **queda por
  comprobar jugando** en una sesión posterior.
  Trazas útiles: `HH_MENU_TRACE=1` (línea `EMPEZAR PARTIDA: difficulty=N -> GAME START nativo`),
  `HH_NATIVE=1`, `HH_MENU_SCREEN=1` (NUEVA PARTIDA) / `=2` (DIFICULTAD).

## Archivos

`src/hooks/sections.cpp` · `include/hh/menu.h` · `src/subsystems/menu.cpp` · `docs/menu.md` ·
`TODO.md`.
