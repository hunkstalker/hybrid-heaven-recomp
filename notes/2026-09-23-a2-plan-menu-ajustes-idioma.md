# A2 — Plan: sección "Idioma" en el menú de AJUSTES in-game

> Sesión 2026-09-23. Continuación de A1. Objetivo (del mantenedor): el selector de idioma debe ser un
> **menú in-game**, reutilizando el menú de **AJUSTES** del juego, con una **sección Idioma** (como
> hizo la PAL).

## 1. Hallazgos del menú (módulo 23, base `0x801BF1A0`)

- El menú de opciones se construye en módulo 23 en `func_801C18FC` (recompilado en
  `funcs_68.c`). Registra cada entrada llamando a **`0x8001B204`** con
  `(a0=índice, a1=0x7D0, a2=Y, a3=puntero al texto)`:
  - idx 0 → `0x801CEBB4`; idx 1 → `0x801CEBC4` (`" NEW GAME   "`); idx 2 → `0x801CEBD4`
    (`" CONTINUE   "`); idx 3 → `0x801CEBE4` (`" BATTLE MODE"`); idx 4 → `0x801CEBF4`
    (`" SOUND      "`); idx 5 condicional (flag `0x80037754 == 1`).
- Las etiquetas son **campos de 16 bytes** (texto ASCII + relleno de espacios + NUL), contiguos:
  `vram = 0x801CEBB4 + 16*idx`.
- El **menú de pausa/ajustes** es otra tabla: `" GAME START"`, `" DIFFICULTY"`, `" EXIT      "`
  (módulo 23, ~`0xFB80`). La **PAL insertó `" LANGUAGE  "` entre DIFFICULTY y EXIT**
  (`eu_dec` @`0x6E2EA0`), más los rótulos del selector `%p ENGLISH`, `%p GERMAN `, `%p FRENCH `.
- El API de mensajes `0x8001B204` rellena un struct (a0 = objeto/pantalla, a1 = ?, a3 = texto). El
  **dispatch de selección** (qué hace cada entrada) está en otra función, pendiente de localizar.

## 2. Referencia PAL

La PAL es el "cómo se hizo": añade una entrada `LANGUAGE` a la misma tabla y su lógica de selección.
Comparar US↔EU del módulo del menú da la plantilla exacta (qué inserción de datos + qué rama de
código). El texto EU se codifica en **EUC-JP** (`LANGUAGE` es ASCII; los nombres de idioma llevan
gaiji de acento, ver `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`).

## 2b. Código localizado (módulo 23; `funcs_68.c`, `section_39_file_024`)

- `func_801C184C` — input del título: lee botones (`0x801C1334`), y al pulsar programa
  `func_801C27DC` y `func_801C18FC` (transición a la pantalla de opciones).
- `func_801C18FC` — **constructor del menú**: registra las entradas (índices 0..N) con
  `0x8001B204(a0=idx, a1=0x7D0, a2=Y, a3=texto)`; textos en `0x801CEBB4 + 16*idx`.
- `func_801C1DB8` (0x298 B) — **candidato a dispatch/update** de la pantalla de opciones
  (bifurca por estado/índice; llama `0x801C1340` y `0x8001B204`). Es el punto a desentrañar.
- `0x8001B204` — API de mensajes (rellena un struct del objeto/pantalla).
- `func_801C11BC`/`func_801C125C` — crean el objeto de la pantalla de opciones.

## 3. Vías de implementación (a decidir en la ejecución)

- **R1 — Hook/override del menú**: reimplementar (ADR 0002) o enganchar el dispatch; para la entrada
  "Idioma", llamar a `hh::text_cycle_language()` / `text_set_language()`.
- **R2 — Inserción de datos + parche de conteo**: añadir un registro `" IDIOMA"` a la tabla (en RDRAM
  al cargar el módulo 23) e incrementar el conteo del bucle de selección; enganchar el dispatch.
- **R3 — Sustituir una entrada existente** (p. ej. `DEBUG MODE`) por `IDIOMA` y redirigir su acción.
  Lo más barato, pero quita una opción.

Recomendación: **R3** como MVP (sustituir `DEBUG MODE`), empezando por mapear el menú.

### Hallazgo que condiciona la vía

El dispatch de selección de `func_801C1DB8` es un **`switch` compilado** (N64Recomp convirtió el
`jr` de la jump table en `switch (jr_addend>>2)` con `goto` a etiquetas internas), así que **no se
puede inyectar una acción nueva parcheando la tabla de datos** (un destino desconocido cae en
`switch_error`). Por tanto R3 requiere **interceptar** (input o reimplementar/override del handler).

### Instrumentación (hecha)

Gateada por **`HH_MENU_TRACE=1`**: el port envuelve `func_801C1DB8` con `hh_menu_trace`
(`src/hooks/sections.cpp`), que **delega en el original** y escribe en `hh.log`:
`[menu] a0=… a1=… sel=<0x801CC8C4> g1=<0x801BBD54> g2=<0x801CC8A8>`.
El índice seleccionado parece estar en **`0x801CC8C4`**. Sirve para mapear índice→acción jugando
(sin input no se llega a ejecutar el handler).

## 4. Dependencia de B (fuente) para acentos

Los nombres de idioma con acento (`ESPAÑOL`, `CATALÀ`, `FRANÇAIS`) necesitan glifos (B). Si A2 va
antes que B, usar rótulos ASCII (`ESPANOL`, `CATALA`, `FRANCAIS`, `DEUTSCH`, `ENGLISH`, `JAPONES`) y
cambiar a acentuados al transplantar la fuente.

## 6. A2 implementado (vía R3, pantalla propia)

Decisión del mantenedor: **SOUND (inútil en PC) → "AJUSTES"**; dentro de AJUSTES: **IDIOMA** y
**SONIDO** (el sonido original, movido de sitio). IDIOMA muestra una **lista de idiomas** estilo
STEREO/MONAURAL.

Implementado en `src/hooks/hh_menu.cpp` con **overrides** de funciones del módulo 23
(`add_loaded_function`), sin tocar el C generado:

| original | override | rol |
|---|---|---|
| `0x801C4960` (setup submenú sonido) | `hh_pc_ajustes` | pantalla AJUSTES (IDIOMA + SONIDO) |
| `0x801C4AA8` (input submenú sonido) | `hh_pc_ajustes_input` | navegación/goto AJUSTES |
| `0x801C5108` (setup submenú resolución) | `hh_pc_idioma` | lista de idiomas |
| `0x801C5378` (input submenú resolución) | `hh_pc_idioma_input` | navegación/confirmar idioma |

- Etiquetas inyectadas en RDRAM en **slots de texto reutilizados** del módulo 23 (los de RESOLUTION
  y del submenú de sonido), capacidad suficiente → ASCII: `%pIDIOMA`, `%pENGLISH`, `%pESPANOL`,
  `%pCATALA`, `%pFRANCAIS`, `%pDEUTSCH`, `%pJAPONES`. La base del módulo se obtiene con
  `hh_trans_dst_for(src,size)`.
- Al confirmar un idioma: `hh::text_set_language(code)` (recarga + re-aplica en vivo) y recompone la
  lista con el activo resaltado.
- Botones: UP `0x800`, DOWN `0x400`, A/START `0xB000`, B `0x4000` (`func_801C1340`).
- Rótulo del menú principal: `SOUND` → `AJUSTES` vía la tabla de traducción.

Pendiente: **validar en Windows** (entrar a AJUSTES, IDIOMA, cambiar idioma; B para volver).
RESOLUTION queda pendiente de decisión (ocultar o reusar para futuros ajustes de vídeo).



1. En **Windows**, correr con `HH_MENU_TRACE=1` (y `HH_LANG=es`), entrar al menú de AJUSTES y mover
   la selección por todas las entradas; `hh.log` anotará `sel=` por cada una → **mapear índice→acción**
   (qué `sel` corresponde a `DEBUG MODE`).
2. Con el índice identificado, implementar R3: sustituir el rótulo (tabla de traducción:
   `DEBUG MODE` → `IDIOMA`) e **interceptar** el confirm de ese índice para llamar a
   `hh::text_cycle_language()` (input-hook o override del handler).
A1 (sistema de idiomas + cambio en vivo, F5) ya está operativo y es lo que consumirá esta sección.
