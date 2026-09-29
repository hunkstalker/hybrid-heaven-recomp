# PLAN — Menú propio de cargar/guardar partida (slots "infinitos", 1 `.pak` por slot)

> **Documento maestro de la tarea** (para una sesión nueva). Rama `menu-edicion-partida`.
> Sustituir los menús nativos de **CARGAR** (CONTINUAR) y **GUARDAR** (cápsula) por un **menú propio**
> (overlay del port, como el del título), con **N slots** en vez de 4, y un **fichero por slot**.
> Diseño **1:1** con el nativo (fuente/estilo/cajas), pero listando todas las partidas.

## 0. Decisiones (mantenedor, 2026-09-29)

1. **Almacenamiento**: **1 `.pak` por slot**, `hh_savegame_slot<N>.pak` (slot1 = índice 0), en `saves/`
   (identificable desde Linux/Windows). No un `.pak` compartido de 4 slots.
2. **Fases**: primero **CARGAR** (sustituir CONTINUAR); luego **GUARDAR** (cápsula); por último
   **sustituir EDICIÓN DE PARTIDA**. Experiencia más nativa.
3. **Estrategia de sustitución = A** (overlay encima + interceptar input, como el menú de título):
   ocultar el menú nativo y mostrar el nuestro; al elegir, reutilizar el flujo nativo para cargar.
4. **Diseño 1:1**: mismas cajas/cabecera por slot; por fila, **Área-Level, nivel y tiempo**. Sin
   nombre. Metadatos de fecha = los del fichero.
5. Al dar a CONTINUAR **no** debe salir el cartel de Controller/Rumble Pak; solo las cajas.

## 1. Hallazgos `[MEDIDO]` (dónde está el menú nativo y cómo se entra)

- **Flujo CONTINUAR** (módulo título, file_024):
  `func_801C3CDC` -> `func_801C3D50` -> **`func_8013E7C0`** (file-select **DATA LOAD**) ->
  **`func_8013E850`** (máquina de estados por frame) -> `func_80142570` + `func_8012FE50(tipo=0x17,
  valor=0x73…, 1, 1, 0)` (transición de escena).
  - `func_801C3CDC` llama a `func_80152240` (monta tablas de runtime) y encadena `func_8013D50`.
  - `func_8013D50` llama a **`func_8013E7C0`** (único llamador) y encadena `func_8013D84`.
  - `func_8013D84` corre `func_8013E850`; si != 0, `func_80142570` + `func_8012FE50`.
- **El menu nativo de carga es `func_8013E7C0`** (setup) + **`func_8013E850`** (update, con jump table
  en `0x8019…`, estados en globals `0x801C3…`, p.ej. `-0x13fd` = estado, `-0x1434` = cursor).
- **Cargar un slot ya se sabe**: `func_801423C8(canal, slot)` (wrapper actual en el test
  `HH_SAVEEDIT_LOADTEST`, `src/hooks/sections.cpp`). Deserializa a los globals.
- **Ocultar el menú nativo ya se sabe**: `src/hooks/menu_overlay.cpp` tiene backup/restore de las
  etiquetas nativas (`g_native_backup`, `kNativeLabelAddrs`) y muteo de input (`hh_native_ab_input`,
  `hh_native_dir_input`, `g_inject_native_a`).
- **Overlay**: el frame del menú se publica con `hh::overlay::publish` (thread-safe). Hoy **solo** lo
  publican los hooks del título/batalla (`title_update`); desde el file-select no se dibuja. Habrá que
  **publicar desde un hook del file-select** (nuevo hook, p. ej. envolver `func_8013E850`).
- **Fichero de guardado**: `hh::save` (src/subsystems/save_edit.cpp) trabaja hoy sobre el `.pak` de 4
  slots: `kSlots=4`, `kSlotSize=0xD00`, cabecera 0x100, campo de escena `0x564` (u16 LE), checksum
  0xCFC. Runtime PFS: `lib/N64ModernRuntime/librecomp/src/pak.cpp`.

## 2. Matiz del "1 `.pak` por slot"

- El juego espera **su** `.pak` (contenedor `HHPK` con 4 slots) y lo lee por PFS
  (`osPfsReadWriteFile`) al cargar/guardar.
- Con 1 `.pak` por slot, hay que **materializar el slot elegido como el pak activo del juego** antes de
  cargar/guardar: opciones (a decidir en Fase 0): (i) copiar el fichero-slot al `.pak` del juego y
  recargar (`hh_pak_reload_from_disk`), (ii) construir en memoria un `HHPK` de 1 slot y montarlo,
  (iii) escribir el slot del fichero en el `.pak` activo en el offset que el juego lee.
- **Fase 0 debe decidir esto con una prueba** (no asumir). Puede ser más simple de lo que parece:
  basta con que el slot 0 del `.pak` activo contenga el fichero-slot elegido.

## 3. Fases

### Fase 0 — Investigación de cierre
1. Trazar `func_8013E7C0`/`func_8013E850` (oráculo/headless): globals de estado/cursor, qué pinta
   (DLs/`G_FILLRECT`), cómo confirma y sale. Objetivo: saber qué **mutear** y dónde **interceptar**.
2. Capturar el `DATA LOAD` nativo (F7) para el diseño 1:1 (posición/color/orden de las cajas).
3. Probar el "montaje" del `.pak`-por-slot (elegir 1 fichero-slot → que `func_801423C8(0)` cargue).
4. **Decidir formato** del fichero-slot: ¿`HHPK` de 1 slot (0x1B + 0xD00) o un `.pak` de 4 con solo el
   slot 0 usado? (recomendado: contenedor `HHPK` con **1** slot para que `hh::save` lo lea fácil).

### Fase 1 — Almacenamiento (1 fichero/slot)
5. Nuevo módulo (p. ej. `hh::slots`): listar `saves/hh_savegame_slot*.pak`, leer metadatos (AREA-LEVEL,
   nivel, tiempo de la cabecera 0x100 + fecha del fichero), ordenar.
6. Reutilizar la lógica de lectura/escritura de slot de `hh::save` sobre el contenedor de 1 slot.

### Fase 2 — UI de carga (overlay 1:1)
7. Nueva pantalla del árbol (`ScreenId::LoadGame`) con lista con scroll (reutiliza layout/scroll del
   menú) y estilo 1:1 con el nativo (cajas verdes, cabecera por slot).

### Fase 3 — Enganche a CONTINUAR (Estrategia A)
8. Hook del file-select (`func_8013E7C0`/`func_8013E850`): ocultar el nativo, **mutear input**,
   **publicar** nuestro overlay.
9. Confirmar slot -> montar el fichero-slot como pak activo -> cargar (`func_801423C8`) -> desmontar el
   menú + transición de escena (lo que hace el flujo nativo: `func_8012FE50`).

### Fase 4 (después) — GUARDAR en cápsula y sustituir EDICIÓN DE PARTIDA (mismo patrón).

## 4. Criterio de validación (Windows)
- CONTINUAR -> aparece **nuestro** menú (sin cartel Controller/Rumble Pak), con **todas** las partidas
  de `saves/hh_savegame_slot*.pak` (más de 4), diseño 1:1.
- Elegir una -> carga esa partida (texto **y** mapa/nivel correctos).
- (Fases siguientes) guardar en cápsula escribe un fichero-slot nuevo; editar partida usa estos slots.

## 5. Referencias
- Mecánica de slots/escena/campo `0x564`: `notes/2026-09-29-editor-area-parte-plan.md`.
- CONTINUAR nativo (dispatch): `notes/2026-09-26-d-continuar-y-bugs-visuales.md`.
- Funciones del módulo del save: `notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md`.
- Menú de pausa/ADR 0008 y menú in-game: `docs/adr/0008-menu-ingame-opciones-pc.md`.
- Plantillas/slots aportados: `notes/reference/saveedit/PUNTOS_DE_GUARDADO.md`.
