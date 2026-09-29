# PLAN — Menú propio de cargar/guardar partida (slots "infinitos", un `.pak` con N slots)

> **Documento maestro de la tarea** (para una sesión nueva). Rama `menu-edicion-partida`.
> Sustituir los menús nativos de **CARGAR** (CONTINUAR) y **GUARDAR** (cápsula) por un **menú propio**
> (overlay del port, como el del título), con **N slots** en vez de 4, en un **único `.pak`**.
> Diseño **1:1** con el nativo (fuente/estilo/cajas), pero listando todas las partidas.

## 0. Decisiones (mantenedor, 2026-09-29)

1. **Almacenamiento**: **UN `.pak` con N slots** (contenedor `HHPK` como el del juego, ampliado a N
   slots de 0xD00). Es lo MÁS FÁCIL: el juego ya espera este formato y `hh::save` ya lee/escribe así;
   `func_801423C8(slot)` funciona con cualquier índice sin montar nada. (Se descartó "1 `.pak` por
   slot": obligaba a montar el fichero-slot como pak activo antes de cargar/guardar.) Opcional a
   futuro: exportar/importar un slot suelto para inspección.
2. **Fases**: primero **CARGAR** (sustituir CONTINUAR); luego **GUARDAR** (cápsula); por último
   **sustituir EDICIÓN DE PARTIDA**. Experiencia más nativa.
3. **Estrategia de sustitución = A** (overlay encima + interceptar input, como el menú de título):
   ocultar el menú nativo y mostrar el nuestro; al elegir, reutilizar el flujo nativo para cargar.
4. **Diseño 1:1**: mismas cajas/cabecera por slot; por fila, **Área-Level, nivel y tiempo** (como el
   nativo). **Nombre del slot**: `savegame_slot1`, `savegame_slot2`, … (1-based para el nombre; 0-based
   internamente). Fecha = la del fichero.
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

## 2. Formato: un `.pak` con N slots

- El juego espera **su** `.pak` (`HHPK` + N slots de 0xD00) y lo lee por PFS (`osPfsReadWriteFile`).
  Con un `.pak` único ampliado a N slots, **no hay que montar nada**: `func_801423C8(slot)` ya sirve.
- Puntos a resolver en Fase 0:
  - **Tamaño del fichero**: `0x1B + 0x100 + N*0xD00`. ¿Cuántos slots (N)? Decidir un tope razonable
    (propuesta: 32 o 64; "infinitos" de facto, con scroll en la UI).
  - **El runtime PFS**: `osPfsReadWriteFile(off = slot*0xD00 + 0x100, 0xD00)` lee del `.pak` activo.
    Comprobar que acepta un fichero mayor que el actual (4 slots) sin recortar (el PFS del runtime es
    nuestro, `pak.cpp`); ver si `PAK_MAX_FILES`/tamaños limitan.
  - **Cabecera de la lista** (`0x100`, registros `0x10+slot*8`): ampliar a N registros. Ya la
    gestionamos en `hh::save` (`update_save_header`).
- `hh::save` (src/subsystems/save_edit.cpp) ya trabaja sobre `.pak`+slots (hoy `kSlots=4`): ampliar
  `kSlots` y los recorridos de checksum/cabecera. Base ya validada (cargar/guardar/eliminar/clonar).

## 3. Fases

### Fase 0 — Investigación de cierre
1. Trazar `func_8013E7C0`/`func_8013E850` (oráculo/headless): globals de estado/cursor, qué pinta
   (DLs/`G_FILLRECT`), cómo confirma y sale. Objetivo: saber qué **mutear** y dónde **interceptar**.
2. Capturar el `DATA LOAD` nativo (F7) para el diseño 1:1 (posición/color/orden de las cajas).
3. **Probar el `.pak` ampliado**: generar uno con N slots y verificar que `func_801423C8(slot)` carga
   un slot > 3 y que el PFS del runtime no recorta el fichero.

### Fase 1 — Almacenamiento (un `.pak`, N slots)
4. Ampliar `hh::save`: `kSlots` configurable, recorridos de checksum/cabecera a N, y
   creación/redimensionado del `.pak` (rellenar/truncar a N slots).
5. Metadatos por slot (AREA-LEVEL, nivel, tiempo de la cabecera `0x100` + fecha del fichero) para la UI.

### Fase 2 — UI de carga (overlay 1:1)
6. Nueva pantalla del árbol (`ScreenId::LoadGame`) con lista con scroll (reutiliza layout/scroll del
   menú) y estilo 1:1 con el nativo (cajas verdes, cabecera por slot).

### Fase 3 — Enganche a CONTINUAR (Estrategia A)
7. Hook del file-select (`func_8013E7C0`/`func_8013E850`): ocultar el nativo, **mutear input**,
   **publicar** nuestro overlay.
8. Confirmar slot -> cargar (`func_801423C8(slot)`) -> desmontar el menú + transición de escena (lo que
   hace el flujo nativo: `func_8012FE50`).

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
