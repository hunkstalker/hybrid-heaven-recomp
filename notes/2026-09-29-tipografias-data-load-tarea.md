# TAREA — Extracción/mapeo de las tipografías del DATA LOAD (menú de carga)

> **Tarea derivada** (desvío de la tarea principal "menú de carga/guardar", rama
> `menu-carga-guardado-partida`). Motivación: el menú propio de carga usa la fuente del **menú de
> título** (`color0`, 8×8) para TODO, pero el DATA LOAD **nativo** usa **3 tipografías distintas**;
> para el 1:1 hay que extraerlas/mapearlas. Documento padre:
> `2026-09-29-menu-cargar-guardar-partida-plan.md`; contexto de la UI:
> `notes/2026-09-29-menu-cargar-guardar-fase2-ui.md`.

## 1. Hallazgo `[MEDIDO]` (2026-09-29)

En una misma pantalla del DATA LOAD nativo conviven **tres tipografías** (medidas sobre el overlay,
escala uniforme k = alto/240; captura `work/gameplay screenshots/menu-carga/`):

| Texto | Alto de tinta (ud) | Observación |
|---|---|---|
| Título `DATA LOAD` | **~11.0** | fuente grande (¿`color4` 8×12 a escala?) |
| Mensaje `Select play data to be loaded.` | **~9.3** | intermedia |
| Cabeceras de slot `AREA`/`LEVEL`/`TIME` | **~7.0** | la del **menú de título** (`color0` 8×8) — **ya la tenemos** |

`Select play data` lo añadió el mantenedor: es **otra** fuente distinta de la del título (no es todo
la misma). Confirmado también que la tipografía del DATA LOAD **no** es la misma que la del menú de
título (salvo las cabeceras de slot).

## 2. Cómo elige el juego la tipografía `[MEDIDO]` (parcial)

- **Compositor de texto**: **`func_8001B204`** (`0x8001B204`, residente). Firma aparente
  `func_8001B204(a0, a1, a2, a3=puntero_a_texto)`.
  - `a0` (0..0x1B, guardado en `s7`) = **índice de ESTILO de fuente**. Si `a0 < 0x1C`, indexa una
    **tabla de estilos** en BSS: **`D_8008EF70`** (`0x8008EF70`). El stride entre entradas es
    `a0*0x1C*2 = a0*0x38` bytes (calculado en el prologue: `sll/subu` con 7,×4,×2).
  - `a1`, `a2` = parámetros (posible **posición/escala/longitud**; a confirmar).
  - `a3` = puntero al texto (con códigos de control `0x25 XX`, p. ej. `%m` = `0x256D`).
- **`D_8008EF70` está en BSS** (`resident_bss`): la **rellena el motor al arrancar** (carga de los
  ficheros de fuente `color0..5` + tamaños). Es el mapa `estilo -> (fuente, escala, …)`.
- **Usos medidos en el file-select** (setup LOAD `func_801426B0` y mensaje `func_80142840`):
  - `DATA LOAD`: `func_8001B204(0x7, 0x7D0, 0x1C, D_8018F16C)`.
  - `CONTROLLER PAK`: `func_8001B204(0xB, 0x26, 0x30, D_8018F184)`.
  - Mensaje `Select play data...`: `func_8001B204(0x7, 0x7D0, 0x1C, D_8018F20C)` **y**
    `(0xB, 0x26, 0x30, D_8018F230)` (dos líneas).
  - Caja: `func_8001A804(0x6, D_8018F194, …)` (dibujo, no texto).
- **⚠️ Incógnita**: `DATA LOAD` y el mensaje usan **el mismo `a0=7`** pero salen con **altos
  distintos** (11 vs 9.3). Luego `a0` no lo explica todo: `a1`/`a2` (0x7D0/0x1C vs 0x26/0x30) deben
  influir (¿escala? ¿posición? ¿longitud de campo?). **Hay que decodificar `func_8001B204`.**

## 3. Pistas / material existente

- **Fuentes ya tratadas** (ver `docs/menu.md` §Idiomas y `notes/2026-09-23-b-fuente-formato-y-gaiji.md`):
  - `color0` (idx107, 8×8, 32 B) — menú/overlay (atlas actual del port).
  - `color4` (idx108, 8×12, 48/56 B) — texto **in-game**; **extraída**:
    `include/hh/game_font_color4.h` (generada por `tools/text/build_font.py`,
    `--style color4`). Puede ser la del título del DATA LOAD.
- **Script**: `tools/text/build_font.py` (US `color4 @0x6E4CD6` 8×12 stride 48; `color0 @0x6E3CD6` 8×8
  stride 32; EU `color4 @0x8C3298` stride 56).
- **Compositor**: `func_8001B204` (residente, `build/recomp/asm/resident.s` ~30968).
- **Tabla de estilos**: `D_8008EF70` (BSS, `build/recomp/asm/.../resident_bss.bss.s`).
- **Textos del file-select**: tablas `D_8018F16C` (DATA LOAD), `D_8018F184` (CONTROLLER PAK),
  `D_8018F20C`/`D_8018F230` (mensaje), `D_8018F6BC`/`D_8018F6DC`/`D_8018F73C` (AREA/LEVEL/TIME) en
  `build/recomp/asm/.../file_008_data.data.s`.

## 4. Plan propuesto (para la sesión nueva)

1. **Decodificar `func_8001B204`**: confirmar qué son `a0`, `a1`, `a2` y cómo se combinan con
   `D_8008EF70` (estilo) para determinar **fuente + escala**. Empezar por el prologue (ya visto) y la
   rama `a0 < 0x1C`.
2. **Volcar `D_8008EF70` en runtime** (es BSS): con la instrumentación del port (o el oráculo
   `r64dump`) leer sus entradas y mapear `a0 → (fichero de fuente, escala)`. Identificar qué `a0`
   corresponde a cada uno de los 3 textos.
3. **Localizar/extraer** las fuentes que falten (probablemente `color4` u otra `colorN`) con
   `tools/text/build_font.py` al estilo adecuado.
4. **Cablear el overlay** para dibujar el DATA LOAD con la fuente/escala correctas por texto.
5. **Afinar el 1:1** con el mantenedor en Windows.

## 5. Criterio de validación
- Saber, `[MEDIDO]`, la correspondencia `texto del DATA LOAD → (fuente, escala)`.
- El overlay dibuja `DATA LOAD`, `Select play data...` y `AREA/LEVEL/TIME` con las fuentes correctas
  (1:1 con tu captura de referencia).
