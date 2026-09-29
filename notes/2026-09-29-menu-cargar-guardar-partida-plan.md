# PLAN — Menú propio de cargar/guardar partida (slots "infinitos", un `.pak` con N slots)

> **Documento maestro de la tarea** (para una sesión nueva). Rama `menu-edicion-partida`.
> Sustituir los menús nativos de **CARGAR** (CONTINUAR) y **GUARDAR** (cápsula) por un **menú propio**
> (overlay del port, como el del título), con **N slots** en vez de 4, en un **único `.pak`**.
> Diseño **1:1** con el nativo (fuente/estilo/cajas), pero listando **todas** las partidas.
>
> **La sesión nueva empieza por la Fase 0** (§3). Aquí está todo lo necesario; no hay que re-investigar.

## 0. Decisiones (mantenedor, 2026-09-29)

1. **Almacenamiento**: **UN `.pak` con N slots** (contenedor `HHPK` como el del juego, ampliado a N
   slots de 0xD00). Es lo MÁS FÁCIL: el juego ya espera este formato y `hh::save` ya lee/escribe así;
   `func_801423C8(slot)` funciona con cualquier índice sin montar nada. (Se descartó "1 `.pak` por
   slot": obligaba a montar el fichero-slot como pak activo antes de cargar/guardar.)
2. **Fases**: primero **CARGAR** (sustituir CONTINUAR); luego **GUARDAR** (cápsula); por último
   **sustituir EDICIÓN DE PARTIDA**. Experiencia cada vez más nativa.
3. **Estrategia de sustitución = A** (overlay encima + interceptar input, como el menú de título):
   ocultar el menú nativo y mostrar el nuestro; al elegir, reutilizar el flujo nativo para cargar.
4. **Diseño 1:1**: mismas cajas/cabecera por slot; por fila, **Área-Level, nivel y tiempo** (lo mismo
   que muestra el `DATA LOAD` nativo). **Nombre del slot**: `savegame_slot1`, `savegame_slot2`, … (el
   nombre es 1-based; el índice interno es 0-based). Fecha = la del fichero.
5. Al dar a CONTINUAR **no** debe salir el cartel de Controller/Rumble Pak; solo las cajas.
6. **Metadatos dentro del `.pak`** (clave): cada slot se identifica por su **registro de cabecera**
   (ver §2); de ahí salen la lista y los datos mostrados. Es autodescriptivo y coherente con el juego.

## 1. Hallazgos `[MEDIDO]` (dónde está el menú nativo y cómo se entra)

- **Flujo CONTINUAR** (módulo título, file_024):
  `func_801C3CDC` -> `func_801C3D50` -> **`func_8013E7C0`** (file-select **DATA LOAD**, setup) ->
  `func_801C3D84` -> **`func_8013E850`** (update, máquina de estados por frame) -> si devuelve != 0,
  `func_80142570` (setup de carga) + `func_8012FE50(tipo=0x17, valor=0x73…, 1, 1, 0)` (transición).
  - `func_801C3CDC` llama a `func_80152240` (monta tablas de runtime) y encadena `func_8013D50`.
  - `func_8013D50` llama a **`func_8013E7C0`** (único llamador) y encadena `func_8013D84`.
  - `func_8013D84` corre `func_8013E850`; si != 0, `func_80142570` + `func_8012FE50`.
- **El menú nativo de carga = `func_8013E7C0`** (setup) + **`func_8013E850`** (update con jump table
  en `0x8019…`; estado en globals `0x801C3…`, p.ej. `-0x13fd` = estado, `-0x1434` = cursor/índice).
- **Cargar un slot ya se sabe**: `func_801423C8(canal, slot)` (wrapper actual en el test
  `HH_SAVEEDIT_LOADTEST`, `src/hooks/sections.cpp`). Deserializa a los globals (`func_80141D08`).
  `a0 = canal (0)`, `a1 = slot`; offset PFS = `slot*0xD00 + 0x100`.
- **Ocultar el menú nativo ya se sabe**: `src/hooks/menu_overlay.cpp` tiene backup/restore de las
  etiquetas nativas (`g_native_backup`, `kNativeLabelAddrs`) y muteo de input (`hh_native_ab_input`,
  `hh_native_dir_input`, `g_inject_native_a`). Mismo patrón que el menú de título.
- **Overlay**: el frame del menú se publica con `hh::overlay::publish` (thread-safe). Hoy **solo** lo
  publican los hooks del título/batalla (`title_update`); desde el file-select no se dibuja. Habrá que
  **publicar desde un hook del file-select** (nuevo hook, p. ej. envolver `func_8013E850`).
- **Guardado en cápsula**: `func_801CA45C` (setup) -> `func_801CA4A4` (update) -> `func_8013EB2C`
  (file-select SAVE) -> stub `func_801CA520`. El guardado real serializa los globals con
  `func_80142450`/`func_80141F28`. (Fase 4.)

## 2. Formato: un `.pak` con N slots

- El juego espera **su** `.pak` (`HHPK` + slots de 0xD00) y lo lee por PFS (`osPfsReadWriteFile`).
  Con un `.pak` único ampliado a N slots, **no hay que montar nada**: `func_801423C8(slot)` ya sirve.
- **Layout del `.pak` actual** (`[MEDIDO]`): `"HHPK"` (4 B) + `count` u32 + por fichero 19 B
  (`used/company/game/game_name/ext_name/size`) -> **datos a `0x1B`**. Dentro: **cabecera `0x100`** +
  **4 slots × `0xD00`**. Fichero total hoy = `0x1B + 0x100 + 4*0xD00 = 0x351B`.
- **Cabecera de la lista (`0x100`)** = **los metadatos por slot**: magic `"HYBRID HEAVEN"` @`0x00`,
  checksum @`0xFF` = `sum(0..0xFE)`, y **registros de 8 B en `0x10 + slot*8`**:
  `+0` presente · `+1` AREA N · `+2` AREA P · `+3` LEVEL · `+4..5` TIME (u16). (Bswapped.)
  **De aquí salen la lista y los datos que muestra cada fila de la UI.** Ya lo gestiona
  `hh::save::update_save_header`.
- **Slot (`0xD00`)**: `0x000..0x09D` personaje (u16 LE, word-swapped) · `0x09E..0x19F` técnicas (86×3)
  · `0x1A0..0x1CC` items (45×1) · `0x300..0x363` flags de historia · `0x364..` bloque de estado ·
  **`0x564` (u16 LE) = índice de escena** (el campo que decide el mapa) · checksum del slot @`0xCFC`
  = `sum(0..0xCFB)`.
- **Ampliar a N slots**:
  - Tamaño: `0x1B + 0x100 + N*0xD00`. **¿N?** decirlo en Fase 0 (propuesta: 32 o 64; "infinitos" de
    facto, con scroll en la UI). `kSlots` pasa de 4 a N.
  - **Runtime PFS**: `osPfsReadWriteFile(off = slot*0xD00 + 0x100, 0xD00)` del `.pak` activo.
    Comprobar que el PFS del runtime (`lib/N64ModernRuntime/librecomp/src/pak.cpp`) acepta un fichero
    mayor sin recortar (`PAK_SIZE`/`PAK_MAX_FILES`).
  - Recorridos de checksum/cabecera en `hh::save` a N. Base de cargar/guardar/eliminar/clonar ya
    validada; solo hay que generalizar el número de slots.
- `hh::save` (src/subsystems/save_edit.cpp) hoy: `kSlots=4`, `kSlotSize=0xD00`, `kProgressOff=0x564`,
  `kChecksumOff=0xCFC`; `load/save/flush/delete_slot/restore_slot/load_template`. `find_pak()` busca el
  primer `*.pak` en `<app_folder>/saves/`.

## 3. Fases

### Fase 0 — Investigación de cierre (empezar aquí)
1. Trazar `func_8013E7C0`/`func_8013E850` (oráculo/headless): globals de estado/cursor, qué pinta
   (DLs/`G_FILLRECT`), cómo confirma y sale. Objetivo: saber qué **mutear** y dónde **interceptar**.
2. Capturar el `DATA LOAD` nativo (F7) para el diseño 1:1 (posición/color/orden de las cajas).
3. **Probar el `.pak` ampliado**: generar uno con N slots y verificar que `func_801423C8(slot)` carga
   un slot > 3 y que el PFS del runtime no recorta el fichero. Fijar N.

### Fase 1 — Almacenamiento (un `.pak`, N slots)
4. Ampliar `hh::save`: `kSlots` configurable, recorridos de checksum/cabecera a N, y
   creación/redimensionado del `.pak` (rellenar/truncar a N slots).
5. Metadatos por slot desde la **cabecera `0x100`** (AREA-LEVEL/nivel/tiempo) + fecha del fichero, para
   la UI. Nombre de slot `savegame_slot<N>` (1-based).

### Fase 2 — UI de carga (overlay 1:1)
6. Nueva pantalla del árbol (`ScreenId::LoadGame`) con lista con scroll (reutiliza layout/scroll del
   menú) y estilo 1:1 con el nativo (cajas verdes, cabecera por slot con Área-Level/nivel/tiempo).

### Fase 3 — Enganche a CONTINUAR (Estrategia A)
7. Hook del file-select (`func_8013E7C0`/`func_8013E850`): ocultar el nativo, **mutear input**,
   **publicar** nuestro overlay.
8. Confirmar slot -> cargar (`func_801423C8(slot)`) -> desmontar el menú + transición de escena (lo que
   hace el flujo nativo: `func_8012FE50`).

### Fase 4 (después) — GUARDAR en cápsula y sustituir EDICIÓN DE PARTIDA (mismo patrón).

## 4. Criterio de validación (Windows)
- CONTINUAR -> aparece **nuestro** menú (sin cartel Controller/Rumble Pak), con **todas** las partidas
  (más de 4), diseño 1:1 (cajas con Área-Level/nivel/tiempo).
- Elegir una -> carga esa partida (texto **y** mapa/nivel correctos).
- (Fases siguientes) guardar en cápsula escribe en un slot nuevo; editar partida usa estos slots.

## 5. Riesgos / incógnitas a resolver en Fase 0
- El PFS del runtime puede tener tope de tamaño (`PAK_SIZE`) -> verificar N.
- La máquina de estados de `func_8013E850` (jump table, globals `0x801C3…`): hay que interceptarla sin
  romperla (mutear input + ocultar dibujo, no sustituir la función).
- El guardado real (Fase 4) serializa los **globals vivos** (`func_80141F28`/`func_80142450`); no es
  solo copiar slots.

## 6. Referencias
- Mecánica de slots/escena/campo `0x564`: `notes/2026-09-29-editor-area-parte-plan.md`.
- CONTINUAR nativo (dispatch): `notes/2026-09-26-d-continuar-y-bugs-visuales.md`.
- Funciones del módulo del save: `notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md`.
- Menú de pausa/ADR 0008 y menú in-game: `docs/adr/0008-menu-ingame-opciones-pc.md`.
- Slots/plantillas aportados: `notes/reference/saveedit/PUNTOS_DE_GUARDADO.md`.
- Formato del `.pak`: `lib/N64ModernRuntime/librecomp/src/pak.cpp`.
