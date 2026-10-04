# FPS/interpolación — bug LATENTE de los walkers de display list con comandos extendidos (2026-10-04)

> Hallazgo **lateral** de la sesión de las partículas del heal (que cerró como **no-bug**). Aquí se
> documenta un **defecto real pero latente**: puede que **nunca** se manifieste en HH, pero si algún día
> aparece un **scissor/widescreen raro o una traza 2D que se corta**, empezar por aquí.
>
> **PALABRAS CLAVE (búsqueda):** `dl_snap`, `snap_overscan`, `walker`, `display list`, `comando
> extendido`, `0x64`, `RT64_EXTENDED_OPCODE`, `gEXPopMatrixGroup`, `G_EX_POPMATRIXGROUP_V1`,
> `gEXSetRectAspect`, `longitud fija 16`, `desincronización`, `scissor de overscan`, `4:3`,
> `pillarbox`, `widescreen`, `HH_RECT_TRACE`, `hud_trace`, `menu_trace`.

## Qué pasa

`src/hooks/dl_snap.cpp` recorre la display list (DL) de cada frame para **reescribir el `G_SETSCISSOR`
de overscan** del juego (p.ej. `16,8..304,232`, 4:3) a pantalla completa (`0,0..320,240`) → así el 3D
**expande a widescreen** en vez de quedar con barras.

El tagging de la interpolación inserta comandos del GBI extendido de RT64 (`opcode 0x64`). Los walkers
tuvieron que aprender a **saltarlos**:

- `Snap::Walker` (`snap_overscan`, commit `814b68f`): los salta con **longitud fija 16 bytes**.
- **PERO** la longitud es **variable**: `G_EX_COMMAND1` = 8 bytes, `G_EX_COMMAND2` = 16.
  En concreto son de **8 bytes**: `gEXPopMatrixGroup` (`G_EX_POPMATRIXGROUP_V1`) y `gEXSetRectAspect`
  (`G_EX_SETRECTASPECT_V1`).
- Consecuencia: **tras cada pop el walker avanza 8 bytes de más** → **salta el comando siguiente**.

## Síntoma observable (si se dispara)

- Si el comando que salta es el `G_SETSCISSOR` de overscan → ese frame/DL **no se reescribe** → la
  escena sale **4:3 con barras laterales** (pillarbox) de forma **intermitente** (depende del orden
  `[pop][scissor]` en la DL).
- Peor caso: al desincronizarse puede interpretar mal un comando (p.ej. leer un `G_DL 0xDE` falso) y
  recorrer/reescribir memoria equivocada → **corrupción puntual**.
- En las trazas (`HudWalker`, `menu_trace`) el efecto es que **abortan al primer `0x64`** (no llegan a
  los draws 2D posteriores) → **traza incompleta** (solo diagnóstico).

## Estado

- **Corregido en esta rama** (misma sesión): `src/hooks/dl_snap.cpp` calcula la longitud por
  sub-opcode (ver §Arreglo) en los 3 walkers.
- El defecto era **LATENTE / NO OBSERVADO** en las runs de HH: no vimos ni 4:3 intermitente ni
  corrupción. Puede que el patrón `[pop][scissor]` no ocurra en las DLs de HH.
- El arreglo **no está validado en juego** (no hay síntoma que demuestre cambio visible); se conserva
  como **correctitud**. Diagnóstico disponible por si aparece el síntoma (ver §Cómo diagnosticarlo).

## Arreglo (aplicado)

En `src/hooks/dl_snap.cpp`, calcular la longitud por **sub-opcode** (`w0 & 0x00FFFFFF`):

```cpp
constexpr uint32_t kExtPopMatrixGroup = 0x00000Du;   // G_EX_POPMATRIXGROUP_V1  (1 palabra)
constexpr uint32_t kExtSetRectAspect  = 0x000033u;   // G_EX_SETRECTASPECT_V1   (1 palabra)
inline uint32_t extended_command_words(uint32_t w0) {
    switch (w0 & 0x00FFFFFFu) {
        case kExtPopMatrixGroup:
        case kExtSetRectAspect: return 1;
        default:                return 2;   // MATRIXGROUP, SETSCISSOR, SETRECTALIGN, ...
    }
}
// en cada walker:
if (op == kExtended) { pc += 8u * extended_command_words(w0); continue; }
```
Y añadir el salto también a `HudWalker`/`menu_trace` (que ahora abortan en `0x64`).

## Cómo validar (determinista, sin juego)

Construir una DL sintética con el patrón real y pasar el walker:
`[0xE0 enable][0x64 grupo (4 palabras)][0x64 pop (2 palabras)][0xED scissor de overscan]`.
- regla vieja (16 fijo) → tras el pop salta el scissor → **no lo reescribe**.
- regla nueva (8 para pop) → **sí lo reescribe**.

## Cómo diagnosticarlo en vivo

- `HH_RECT_TRACE=1` → `hh-rect.log` (`src/render/rt64_framebuffer_renderer.cpp`, `hhRectLog`).
- `HH_HUD_TRACE=1`/`HH_MENUTRACE=1` → trazas 2D (`src/hooks/dl_snap.cpp`); si se cortan al primer tag,
  es este bug.
- Comparar: escena que debería expandir a widescreen y sale 4:3.
