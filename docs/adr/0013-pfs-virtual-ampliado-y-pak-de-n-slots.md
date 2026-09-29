# 0013 — PFS virtual ampliado y `.pak` de N slots (con trailer de metadatos)

- **Estado:** Aceptado (2026-09-29). Rama `menu-carga-guardado-partida`.
- **Contexto:**
  - El guardado del juego va por el **Controller Pak** vía **PFS** (libultra). El recompilado **no
    tiene** Controller Pak físico: **N64ModernRuntime implementa el PFS en software** ("PFS virtual",
    `lib/N64ModernRuntime/librecomp/src/pak.cpp`), con la misma API (`osPfsInitPak`, `osPfsAllocateFile`,
    `osPfsFindFile`, `osPfsReadWriteFile`, `osPfsDeleteFile`, `osPfsFileState`, `osPfsFreeBlocks`,
    `osPfsNumFiles`…). Persiste en un contenedor propio **`HHPK`** (`count` + registros de 19 B por
    fichero). El juego cree que hay un Controller Pak conectado según lo que responda esa capa.
  - **Antecedente 1 (`hh_pak_reload_from_disk`, fork NMR `9b14604`)**: el PFS **cachea el `.pak` en
    RAM** (`g_pak`, `pak_load()` una vez por sesión). El editor de partida escribe el fichero por fuera,
    así que `CONTINUAR` seguía sirviendo el estado **cacheado viejo** → la edición no surtía efecto. Se
    añadió una función que **descarta la caché y relee del disco**, llamada por `hh::save::save()`.
  - **Antecedente 2**: el file-select DATA LOAD (`func_8013E850`) lee los slots por offsets fijos
    `0x100 + slot*0xD00` del fichero PFS; con un fichero mayor, `func_801423C8(slot)` carga cualquier
    índice. Pero el PFS **recortaba a `PAK_SIZE = 0x8000`** (tamaño físico de un Controller Pak de
    32 KB) → **máximo 9 slots**.
  - La tarea "menú propio de cargar/guardar" pide **N slots** en un **único `.pak`** (el juego ya
    espera ese formato) y, además, alojar las **plantillas por punto de guardado** que ya ofrece
    `EDICIÓN DE PARTIDA` (29), de forma **segura ante borrados** (no en una carpeta suelta).
- **Decisión:**
  1. **PFS virtual redimensionable:** subir `PAK_SIZE` en el fork NMR a **`0x40000`** (de `0x8000`).
     El PFS es virtual, así que el "tamaño de tarjeta" es un parámetro nuestro, no una restricción de
     hardware. Capacidad resultante: **74 slots** de `0xD00`.
  2. **Formato del `.pak` (contrato del layout):**
     ```
     HHPK (4) + count u32 + registro 19 B      -> datos a 0x1B
       fichero PFS = cabecera 0x100
                   + 74 * 0xD00  (slots; offset slot s = 0x100 + s*0xD00)
                   + 74 * 8      (trailer de metadatos; offset = 0x100 + 74*0xD00 + s*8)
       size del fichero PFS en el registro HHPK (+0x17) = 0x100 + 74*0xD00 + 74*8 = 0x3C550
       contenedor total = 0x1B + 0x3C550 = 0x3C56B
     ```
     La cabecera del juego (`0x100`) solo da para **30 registros** (`(0x100-0x10)/8`); por eso los
     metadatos de los 74 slots viven en un **trailer** al final del fichero PFS, con el **mismo layout
     de registro** (`+0 presente · +1 AREA N · +2 AREA P · +3 LEVEL · +4..5 TIME u16 BE`). El trailer no
     afecta a `func_801423C8` (lee por offset fijo).
  3. **Reparto de los 74 slots:** **0..44 = partidas** del jugador (45); **45..73 = plantillas** (29,
     los puntos de guardado de `EDICIÓN DE PARTIDA`). Las plantillas **se excluyen de la lista de carga**
     (la UI recorre solo 0..44); el editor accede a ambos rangos. Viven dentro del `.pak` para que el
     estado de guardado sea **autocontenido** (borrar una carpeta externa no rompe la edición).
  4. **Migración:** `hh::save::load()` normaliza cualquier `.pak` (el de 4 slots se rellena a cero,
     recorta si sobra), fija el `size` del registro HHPK y migra la cabecera del juego (0..29) al
     trailer.
- **Consecuencias:**
  - El `.pak` del usuario crece de ~13 KB a ~247 KB (`0x3C56B`). Trivial en PC.
  - `osPfsAllocateFile`/`osPfsFreeBlocks`/`osPfsNumFiles` reportan ahora ~74 slots (antes ~9): el juego
    puede crear el fichero grande por sí mismo.
  - El port queda **atado a un 2.º commit del fork NMR** (además de `hh_pak_reload_from_disk`); el
    gitlink de `lib/N64ModernRuntime` solo vale tras pushear el fork (`AGENTS.md`).
  - La frontera 45|29 es un **contrato** que la UI (Fase 2) y el editor deben respetar.
- **Alternativas descartadas:**
  - **N ≤ 9 sin tocar NMR**: funciona hoy, pero no cabe el diseño (ni plantillas).
  - **1 `.pak` por slot**: obliga a montar el fichero-slot como pak activo antes de cargar/guardar
    (descartada ya en el plan).
  - **Plantillas en carpeta junto al `.exe`**: frágil (un usuario puede borrarla y romper la edición).
  - **Escribir el `.pak` solo desde el port sin el PFS** (para el tamaño): rompe el criterio de que el
    juego cargue por PFS (`CONTINUAR` tropezaría con el recorte).
  - **Que el editor escriba por la API del PFS** (en vez del `reload`): más fiel, pero acopla el editor
    al estado vivo del PFS y complica checksums/cabecera que hoy se hacen sobre bytes del fichero.
- **Criterio de salida:** `func_801423C8(slot)` carga un slot del rango alto (validado headless: slot
  con escena correcta); migración de un `.pak` de 4 slots verificada; **validar en Windows** un `.pak`
  de 74 slots (partidas + plantillas) creado/editado/cargado por `CONTINUAR`.
