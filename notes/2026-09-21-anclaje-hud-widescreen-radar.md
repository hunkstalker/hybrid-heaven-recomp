# 2026-09-21 — Widescreen fase 07b: anclaje del radar a la izquierda

> Evidencia de la sesión. Fuente de verdad del estado: `TODO.md` / `PROYECTO.md` / `RETOMAR.md`.
> Referencia MIT: `danielgomesvieira2000/hybrid-heaven-recomp` (Phase 07; clon en `/tmp/opencode/ref-hh`).

## Qué se hizo

Adaptar el reescritor de listas de la referencia para **anclar el HUD 2D** con el widescreen activo.
El *snap* de overscan (`src/hooks/dl_snap.cpp`) ya hacía que el 3D llenara la ventana; faltaba
re-anclar la 2D. Se empezó **solo por el radar (izquierda)** y se validó.

### Ficheros

- `include/hh/hudid.h` (nuevo): identidades `tex:<addr>#<hash64B>`, `dl:<addr>#<hash16cmds>`,
  `fill:<color>@ulx,uly,lrx,lry` (fills a pantalla completa = clears, sin identidad).
- `src/hooks/dl_snap.cpp`: se añadió el trace `HH_HUD_TRACE=1` (`HudWalker`) — recorre las listas,
  reconstruye segmentos/imagen/color de relleno/ancho de framebuffer y lista **una vez por identidad**
  los elementos con su extensión en 320x240.
- `include/hh/hudrewrite.h` + `src/hooks/hud_rewrite.cpp` (nuevos): copia la lista a un scratch de
  RDRAM (2 buffers alternos) e inserta GBI extendido (`gEXEnable`, `gEXSetRectAlign`,
  `gEXSetViewportAlign`, `gEXSetScissor`, `gEXMatrixGroup`) según clase. Tabla fija por ahora.
- `src/platform/rt64_render_context.cpp` (`send_dl`): tras el snap y el trace, si
  `hudrewrite::rewrite` devuelve != 0, se envía la copia (`data_ptr` reescrito).
- `CMakeLists.txt`: fuente nueva + `lib/rt64/include` en los includes.

## Identidades re-derivadas con NUESTRA build

`HH_HUD_TRACE=1` sobre el replay `work/debug/hh_replay_npc.txt` (llega a exploración). Los hashes son
de contenido y **coinciden exactos con la referencia**:

| Identidad | Extensión 320x240 | Clase |
|---|---|---|
| `tex:0x802866f8#a3036828` | x 27..59 y 19..51 (rect) | left |
| `tex:0x80286af8#dfde6ac5` | x 27..59 y 19..51 (rect) | left |
| `dl:0x80181860#e59a0172` | (dial, alcanzado por **G_DL branch**) | left |

> La referencia promueve además `dl:0x03000f10#1427da33`, `dl:0x030002e0#bbb8c0ba` y
> `fill:0x00000000@197,143,277,223` como `right`; en nuestro run esas direcciones tienen **otro
> hash** (escena distinta) → no se clasifican hasta re-derivarlas en su escena.

## RDRAM scratch

Se usó `0x7A0000` / `0x7C8000` (0x28000 cada uno), como la referencia. En **nuestra** build está
libre: el port informa al juego **4 MB** (`osGetMemSize` con fix, ADR 0002) y los volcados de RDRAM
(`work/debug/dump_gameplay.bin`, `port_vi*.bin`) muestran el byte no nulo más alto en `0x3FEBDF`;
`0x780000..0x800000` está **a cero**.

## Validación (Linux headless, Xvfb :99 + lavapipe)

Run con `HH_REPLAY=work/debug/hh_replay_npc.txt` (≈46 s, exploración con radar). Centroide de los
píxeles azules del radar en capturas 640x480 (ventana 1280x720 → la zona 4:3 ocupa x≈160..1120):

| | centro x | centro y |
|---|---|---|
| `HH_NO_HUD_REWRITE=1` (OFF) | 287.0 | 107.58 |
| rewrite ON (default) | 125.0 | 107.58 |

Diferencia = 162 px ≈ el *pillarbox* (160 px): el radar pasa de la zona 4:3 al **borde izquierdo**;
la Y no cambia. En el log: `HUD rewrite: 3 elemento(s) clasificado(s)`, sin *overflow* y sin errores.
El trace solo marca `class 1` en esas 3 identidades (ninguna otra escena se clasifica → sin la
regresión del Expansion Pak que tuvo la referencia por promover por dirección).

## Pendiente

- **Validar visualmente en Windows** (build/run del mantenedor).
- Barras POWER/STAMINA/HP y elementos de la derecha (`right`/`stretch`): re-derivar con
  `HH_HUD_TRACE=1` en combate/diálogos y añadir a la tabla fija de `hud_rewrite.cpp`.
- Decidir si el reescritor sustituye al *snap* global o convive con él (hoy convive).
