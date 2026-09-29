# FASE 1 — Almacenamiento: un `.pak` con N=74 slots (45 partidas + 29 plantillas)

> Evidencia de la **Fase 1** del plan `notes/2026-09-29-menu-cargar-guardar-partida-plan.md`, elegida
> como **opción "b"** (N grande, exige subir el PFS y rediseñar los metadatos). Rama
> `menu-carga-guardado-partida`. `[MEDIDO]` salvo lo indicado. Decisión estructural:
> **`docs/adr/0013-pfs-virtual-ampliado-y-pak-de-n-slots.md`**. Fase 0:
> `notes/2026-09-29-menu-cargar-guardar-fase0-hallazgos.md`.

## 0. Qué es el "PFS virtual" y qué resolvieron los dos cambios en NMR

El guardado del juego va por el **Controller Pak** vía **PFS** (libultra). Un recompilado no tiene
tarjeta física: **N64ModernRuntime la simula por software** (el "PFS virtual") en
`lib/N64ModernRuntime/librecomp/src/pak.cpp`, con la misma API (`osPfsInitPak`, `osPfsAllocateFile`,
`osPfsFindFile`, `osPfsReadWriteFile`, `osPfsDeleteFile`, `osPfsFileState`, `osPfsFreeBlocks`,
`osPfsNumFiles`, `osPfsIsPlug`…). Mantiene los ficheros en RAM (`g_pak`) y los persiste al contenedor
propio **`HHPK`**. El juego cree que hay un Controller Pak según lo que responda esa capa.

Dos cambios en el fork, en la **misma frontera** (el `.pak`/PFS es donde se tocan el editor del port y
el guardado del juego), pero resolviendo cosas distintas:

1. **`hh_pak_reload_from_disk()` (commit `9b14604`) — coherencia caché↔disco.** El PFS **cachea el
   `.pak` en RAM** (`g_pak`, `pak_load()` una vez por sesión). El editor (`hh::save`) escribe el
   fichero por fuera, así que el juego seguía leyendo el estado **cacheado viejo** y `CONTINUAR` no
   reflejaba la edición. La función **descarta la caché y relee del disco**; la llama
   `hh::save::save()` tras escribir. *(No es "editar en memoria": el editor siempre escribió el
   fichero; lo que faltaba era que el PFS dejara de creer el estado viejo.)*
2. **`PAK_SIZE 0x8000 → 0x40000` — dimensionamiento.** El PFS **recortaba** el fichero a 32 KB
   (tamaño físico de un Controller Pak) y `osPfsAllocateFile` usaba ese cupo → **máximo 9 slots**.
   Subirlo da **74 slots** de `0xD00`, que es lo que pide el diseño (más plantillas). *(El PFS es
   virtual: el "tamaño de tarjeta" es un parámetro nuestro, no una restricción de hardware.)*

## 1. Decisión de formato

- **N = 74 slots** (tope real de `PAK_SIZE=0x40000`; `(0x40000-0x100)/0xD00 ≈ 74`), eran 4.
- **Reparto (contrato del layout):** **0..44 = partidas** del jugador (45); **45..73 = plantillas** (29,
  los puntos de guardado que ofrece `EDICIÓN DE PARTIDA`). Las plantillas **NO se listan** en el menú de
  carga (la UI recorre solo 0..44) y viven **dentro del `.pak`** para que el estado sea autocontenido
  (borrar una carpeta externa no rompe la edición).
- Nombres: `savegame_slot<N>` (partidas, 1-based) y `template_<N>` (plantillas, 1-based dentro del
  rango) — `hh::save::slot_name`/`template_name`.
- **Metadatos por slot**: la cabecera del juego (`0x100`) solo da para **30 registros**
  (`(0x100-0x10)/8`). Para 74 se añade un **trailer** de **74 registros de 8 B** al FINAL del fichero
  PFS, con el **mismo layout** de registro: `+0 presente · +1 AREA N · +2 AREA P · +3 LEVEL ·
  +4..5 TIME (u16 BE)`.
- **`func_801423C8` no se ve afectado**: lee offsets fijos `0x100 + slot*0xD00`; el trailer va después.

### Layout del `.pak`
```
HHPK (4) + count u32 + registro 19 B  -> datos a 0x1B
  datos (fichero PFS) = cabecera 0x100
                      + 74 * 0xD00 (slots; offset slot s = 0x100 + s*0xD00)
                      + 74 * 8     (trailer metadatos; offset = 0x100 + 74*0xD00 + s*8)
  size del fichero PFS en el registro HHPK (+0x17) = 0x100 + 74*0xD00 + 74*8 = 0x3C550
  total contenedor = 0x1B + 0x3C550 = 0x3C56B  (~247 KB; PAK_SIZE=0x40000 deja ~4 slots de margen)
```

## 2. Cambios `[MEDIDO]`

- **Fork NMR `pak.cpp`**: `PAK_SIZE` de `0x8000` → **`0x40000`**. Commit local en el fork (rama
  `hybrid-heaven`); **sin push**.
- **`hh::save` (`include/hh/save_edit.h`, `src/subsystems/save_edit.cpp`)**:
  - `kSlots = 74` con **reparto**: `kGameSlots = 45`, `kTemplateSlots = 29`, `kTemplateBase = 45` y
    helpers (`game_slot_count`, `template_slot_count`, `template_slot_base`, `is_game_slot`,
    `is_template_slot`). Nuevas constantes `kMetaOff`/`kFileDataSize`/`kContainerSize`/`kPakSizeOff`.
  - `load()`: normaliza el `.pak` al layout de 74 (pad a cero si es de 4 slots, recorta si sobra),
    fija el `size` del registro HHPK (`set_pak_file_size`) y **migra** cabecera→trailer
    (`sync_meta_from_header`, slots 0..29).
  - `update_save_header`/`clear_save_header_record`: escriben **trailer (todos)** y **cabecera
    (0..29)**.
  - `flush`/`save`: fijan el `size` y recalculan checksums de los N slots. `restore_slot` también
    restaura el registro de metadatos.
  - Getters de UI: `slot_present`, `meta_area_n`, `meta_area_p`, `meta_level`, `meta_time`,
    `slot_name`, `template_name`.

## 3. Validación

- **Build** Linux OK (`pak.cpp` del fork + port).
- **Slot alto carga su escena `[MEDIDO]`**: `.pak` con la escena `0x564` etiquetada por slot; el hook
  temporal (retirado) llamó a `func_801423C8(0, s)` y volcó `glob 0x801BBBF4` (`[+4]`): p. ej. con 64
  slots, slot 0 → `ret=0`/`glob=0x100`, **slot 63 → `ret=0`/`glob=0x13F`**, slot 64 → `ret=9`. Con 74:
  los 74 cargan y el 75 fuera falla (coherente). **`PAK_SIZE=0x40000` no recorta** (`0x3C550`).
- **Migración de un `.pak` de 4 slots `[MEDIDO offline]`**: verificada replicando la lógica de `load()`:
  el contenedor pasa a `0x3C56B`, el `size` del registro a `0x3C550`, la cabecera se copia al trailer
  (slots 0/1 presentes, `AREA 1-1 LEVEL 1`) y la escena del slot 1 (`0x222`) se conserva.
  **Pendiente validar en Windows.**

## 4. Riesgos / notas

- El `count` del contenedor HHPK = 1 (un único fichero PFS "savegame"); el `size` es lo que limita.
- El juego, al **crear** el fichero por primera vez, usa `osPfsAllocateFile` (tope = `PAK_SIZE`) →
  con `0x40000` puede alojar los 74 slots. Sin subir `PAK_SIZE` no crearía el fichero grande.
- `PAK_MAX_FILES` sigue en 16 (no afecta: un solo fichero).
- El port queda **atado a un 2.º commit del fork NMR**; el gitlink de `lib/N64ModernRuntime` solo vale
  tras pushear el fork (`AGENTS.md`).

## 5. Referencias
- Decisión estructural: `docs/adr/0013-pfs-virtual-ampliado-y-pak-de-n-slots.md`.
- Plan: `notes/2026-09-29-menu-cargar-guardar-partida-plan.md`.
- Fase 0: `notes/2026-09-29-menu-cargar-guardar-fase0-hallazgos.md`.
- PFS: `lib/N64ModernRuntime/librecomp/src/pak.cpp`.
