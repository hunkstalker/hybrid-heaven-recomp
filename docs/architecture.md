# Arquitectura — Hybrid Heaven: Recompiled

> Documento vivo. Modelo técnico canónico del port. Las decisiones se registran en `docs/adr/`.
> El estado y las tareas están en `../PROYECTO.md` y `../TODO.md`. El histórico, en `../notes/`.

## 1. Stack

| Capa | Elección |
|---|---|
| Recompilación | **N64Recomp** (MIPS → C) |
| Runtime libultra | **N64ModernRuntime** (`ultramodern` + `librecomp`) |
| Render | **RT64** (Vulkan/D3D12/Metal), microcode **F3DEX2 fifo 2.06** |
| Input / ventana | SDL2 |
| Plataformas | Windows + Linux + Steam Deck (mismo código) |
| Símbolos / fronteras | **splat + spimdisasm** sobre la **imagen expandida** → ELF (ADR 0011); nombres en `recomp/symbol_addrs.txt` |
| Recompilación (modo) | **N64Recomp ELF mode** (`recomp/hybrid-heaven.us.toml`) |

Sin decompilación de referencia: las fronteras de función salen de la **imagen completa** (splat) +
gates de verificación (byte a byte, `jal` mid-function/nowhere), no de un validador ad-hoc. Ver §6.

## 2. Modelo unificado: **imagen plana + módulos**

El boot es una **imagen de código plana**; el resto del juego (diálogos, combate, escenas, etc.)
llega como **módulos de código que se descomprimen de la ROM a RAM y se ejecutan** vía el cargador
`trans` (`seg_RomDecode_sep`, `trans_to_malloc64_sep`). No es "código plano + overlays de fase":
es **una imagen + N módulos con origen (asset/Nisitenma) y base RAM conocidos**.

Consecuencia: la recompilación estática necesita **pre-recompilar cada módulo** y resolver sus
funciones en runtime por `(origen, base)`. Decisión **aceptada** (ADR 0001): pre-recompilar y
registrar en la base determinista.

### 2.1 Contrato del módulo (medido 2026-09-11)

- El módulo es **MIPS autoligado** en `base+offset` (entry en offset 0), con **direcciones
  absolutas** (llama al código plano por `jal 0x8000xxxx` y se autorreferencia); **sin relocs**.
- El salto sale de un **descriptor** en heap con `+0x1C = base` (lo consume `FUN_80005270`).
- **Módulos de código del boot** (bases idénticas en 3 runs; medir con `break FUN_80003824` →
  `ctx->r4/r5/r6` = src/dest/size, o el dir `trans` en `0x8008DFC0`):

  | Nisitenma idx | ROM offset | base RAM | descomp. | CRC32 |
  |---|---|---|---|---|
  | 7  | `0x4E69A8` | `0x80107830` | 564464 (0x89CF0) | `0xA9213032` |
  | 23 | `0x5F1190` | `0x801BF1A0` | 68432 (0x10B50) | `0x17AE0EEF` |
  | 54 | `0x68BF26` | `0x803837E0` | 42464 (0xA5E0)  | `0x486A3F0F` |

  (idx 0 en `0x800F41C0` y idx 114 en `0x801FA948` se cargan pero son **datos**, no código.)
- Detalle: `../notes/2026-09-11-modelo-modulos-trans.md` y
  `../notes/2026-09-11-a3-multi-modulo-jumptables.md`.

### 2.2 Rol conocido de los módulos (evidencia runtime)

Los módulos se cargan **bajo demanda**; `hh_ovl.log` (port) registra cada carga con su instante, y
`build/recomp/RecompiledFuncs/recomp_overlays.inl` mapea sección → módulo Nisitenma.

| idx | sección port | base RAM | rol conocido | evidencia |
|---|---|---|---|---|
| 55 | 11 | `0x803757E0` | **Secuencia de obtención de objeto del NPC**: animación de escala/posición del objeto, contador de fase global `0x8039764C` y caja de texto asociada. La zona contigua `0x80379970` pertenece a la IA de combate/interacciones. | `hh_ovl.log`: carga bajo demanda (`src ROM 0x68FF2C`) a `t≈13 s` en la repro, justo al iniciar la interacción con el NPC. Cadena `M55_FUN_80379690 → 80379798 → 803798D8 → 80379904 → 80379954` con floats `10.0/225.0/80.0` y `lh -0x764C($8039)` (contador de fase). Todos los `Failed to find function` del bug del NPC cayeron aquí: `0x80380010`, `0x80379954`, `0x803798E8`. Ver `../notes/2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md`. |


## 3. Mapa de memoria (a confirmar en runtime cuando aplique)

| Región | Detalle |
|---|---|
| Código principal plano | vram `0x80000400`, tamaño sección `0x4E5B40`; entry `0x80000400` |
| Mapeo vram↔ROM | ROM retail (header `0xC00`): `rom_off = vram - 0x7FFFF400` |
| Directorio `trans` | RDRAM física `0x8DFC0` (vista CPU `0x8008DFC0`), 0x100 entradas × 8 B (`id16`, `base32`) |
| Stack principal (entry) | `SP = 0x80057BD0` |
| Thread 5 (game loop) | pila con tope `0x8005BF30` |
| Threads RSP 16-19 | pilas: 16→`0x80055BD0`, 17→`0x80053BD0`, 18→`0x80051BD0`, 19→`0x8004FBD0` |
| Buffer de chunk `trans` | `0x80089518` (chunks de `0x2000`) |
| Salida de descompresión | p. ej. `0x80107830` (base de módulo; ver ADR 0001) |
| Globales del descompresor | `0x8005D010..0x8005D026` (fuente, base, restante, fin, contador, stride) |

> Nota: los globales del descompresor están en **`0x8005D0xx`** (no `0x8006D0xx`). En el código
> recompilado, `MEM_W(0, 0x8005D0xx)` con literal NO sign-extended lee fuera de RDRAM; usar
> `MEM_W(0, 0xFFFFFFFF8005D0xx)`.

## 4. Compresión y carga (`trans`)

- Tabla de ficheros **Nisitenma-Ichigo** (común a los N64 de Konami; la usa `tools/rommy.py`).
  Entradas de 4 B BE: bits [0-30] = offset ROM, bit 31 = comprimido (LZKN64). Termina en `0x00000000`.
- **LZKN64** resuelto y reutilizable (`tools/lzkn64`, `rommy.py`). El descompresor del juego
  (`FUN_80003824`) es de la misma familia pero con offset de 10 bits.
- **Confirmado (2026-09-11)**: `lzkn64` descomprime **correctamente** el módulo idx 7 (CRC32
  `0xA9213032`, 564464 B) → (histórico) `legacy/tools/setup_module.py` lo extraía de la ROM **sin
  ejecutar el juego** (determinista). Una nota histórica que decía que `lzkn64` daba "basura" era **errónea**.
- Variantes **`LZSS 5`/`LZSS 7`** del `trans`: por caracterizar (otros módulos podrían usarlas).
- El código plano NO está comprimido; se comprimen assets y módulos de código.

## 5. Contrato de runtime (N64ModernRuntime) y parches del port

- **Modelo single-CPU**: el N64 tiene una CPU; el runtime debe serializar los hilos de juego.
- Hilos, message queues, eventos (VI/AI/SP/DP/SI/PI) y VI timing vienen del runtime.
- **Base**: `lib/N64ModernRuntime` es un fork del upstream (`toolchain/src/N64ModernRuntime`). Toda
  divergencia debe estar aquí documentada y justificada; el objetivo es mantenerla **mínima**.
- **Parches funcionales del port (deliberados):**
  - `CMakeLists.txt`: **`-fno-strict-aliasing`** en el build no-MSVC. Los macros `MEM_W/H/B` del C
    recompilado acceden al mismo `rdram` con tipos distintos; sin el flag GCC (`-O2`) reordena
    `sw`/`lhu` del mismo slot (verificado en `FUN_80125814`: leía un id basura). Los ports de
    referencia (Zelda64Recomp/Goemon64Recomp) ya lo compilan así.
  - **Registro dinámico de módulos (bases de VRAM reutilizadas)**: el juego decodifica módulos
    distintos en la misma base (idx 24 sobre idx 23, idx 99 sobre idx 54). `overlays.hpp/.cpp` añaden
    `ModuleSource { src_rom, rom_addr }`, `register_module_sources()` y `load_module_by_source()`;
    `register_flat_code()` omite las secciones de módulos y el loader (`FUN_80003824`, wrapper
    siempre activo en `get_function`) registra la sección recompilada en la base real que pide el
    juego. (Histórico, vía Ghidra per-file → `legacy/`): la tabla `src_rom → rom_addr` la generaba
    `legacy/tools/setup_module.py`; los mid-entries salían de `HH_JALTRACE` +
    `tools/analysis/gen_module_extras.py`/`add_missing_funcs.py`, protegidos por
    `legacy/config/keep_syms.txt`. En la vía vigente (ELF/splat) las fronteras vienen de la imagen
    completa (splat) y los loaders registran las secciones relocalizables por dirección
    (`src/hooks/sections.cpp`).
  - `addresses.hpp`: `mem_size` 512 MB → 1 GB para cubrir accesos a registros de hardware vía `0xA0000000+`.
  - `overlays`: `register_flat_code()` (modelo de imagen plana, ADR 0001) + `init_mmio()`.
  - `recomp.cpp`: `boot_log` (**opt-in** `HH_BOOTLOG=<ruta>`), `do_break` no aborta, `cop0_register_read/write`
    con `uint32_t`, y `ctx->r4` del entrypoint fijado a scratch de boot (HH-specific; **revisar**).
    Además: **`osGetMemSize` y `osMemSize` (`0x80000318`) reportan 4 MB** — el juego exige la máquina
    base (`osGetMemSize() == 0x400000`; si no, bucle de espera). El runtime asigna 8 MB igualmente.
  - `events.cpp`: evento VI también por `osSetEventMesg(OS_EVENT_VI)`; tareas RSP sin ucode → no-op.
    Además: **`osSetEventMesg` replica la escritura de `__osEventStateTab`** (`0x800CD5F0 + e*8` →
    `{mq,msg}`), que el ROM hacía y el runtime C++ no. El juego lee esa tabla.
  - `ultrainit.cpp`/`ultra64.h`/`ultra_translation.cpp`: el stub C++ de `osInitialize` se renombró a
    **`osInitialize_stub`** porque ahora se recompila la **versión del ROM** (des-stubbing; ADR 0002).
  - `cont.cpp`: `osContGetReadData` escribe los 4 `OSContPad` (libultra escribe también los ausentes
    con `CONT_NO_RESPONSE_ERROR`; el juego ramifica según eso).
  - `pak.cpp`: **Controller Pak (PFS) mínimo en RAM** con persistencia (`saves/<nombre>.bin.pak`,
    magic `HHPK`) **junto al ejecutable** (portada portable; si esa carpeta no es escribible se usa el
    directorio de datos del usuario y `HH_DATA_DIR` lo fuerza): `osPfsInitPak`, `osPfsInit` (formato),
    `osPfsFreeBlocks`, `osPfsAllocateFile`,
    `osPfsFindFile`, `osPfsDeleteFile`, `osPfsReadWriteFile`, `osPfsFileState`, `osPfsNumFiles`,
    `osPfsIsPlug`, `osPfsChecker`, `osPfsRepairId`, `osPfsGetLabel`. El juego exige pak para GAME
    START y el upstream devolvía `PFS_ERR_NOPACK` en todo (TODO #15). Esas 13 entradas se movieron de
    `ignored_funcs` a `reimplemented_funcs` en `N64Recomp/src/symbol_lists.cpp` (tool reconstruido con
    `--target N64RecompCLI`). No se emula el formato PFS real de libultra: la semántica de ficheros es
    propia. `osGbpakInit` sigue devolviendo "no pak".
  - `recomp.cpp`: `switch_error` imprime a **stderr** (con `printf`/stdout se perdía al abortar).
  - `recomp.h` (macros `MEM_*`) y `ultra64.h` (`TO_PTR`): **traducción de direcciones no mapeadas**.
    El juego escribe/lee con punteros nulos (p.ej. `M24_FUN_801cb71c` con `[$t5+0x30]==0`;
    `osSendMesg` con cola 0) y el emulador de referencia lo tolera (la escritura cae en RDRAM física
    o se ignora). El port calculaba `rdram + (v - 0xFFFFFFFF80000000)`: para direcciones bajas eso da
    un offset >1 GB → SEGV. Ahora: direcciones mapeadas (KSEG0/KSEG1, incluida la ventana MMIO en
    `0x20000000+`) usan la fórmula original; las bajas (<8 MB físicos) caen en RDRAM como en mupen;
    el resto va a un scratch en `0x0FFFFF0` (justo bajo el heap, que ocupa `[16 MB, 1 GB)`).
  - `input.cpp`: `osContInit` fiel a libultra (query SI + espera en `mq` + one-shot). Upstream lo
    simplifica (no bloquea); para HH el orden de arranque depende de ese wait. **Nota**: el mensaje SI
    se entrega síncrono en el runtime, así que el wait no siempre cede; un `osContInit` 100% fiel
    requeriría entrega SI asíncrona (worker), pendiente de decidir.
  - `run_next_thread_and_wait` hace *idle* en mensajes externos si la `running_queue` está vacía
    (evita el abort "No threads left to run").
  - Lock global single-CPU (`acquire_game_lock`/`release_game_lock`) — **candidato a eliminar**
    (experimento 2026-09-12: con upstream no cambia el bloqueo; ver `../TODO.md` #9).
- **Instrumentación de debug**: toda traza verbose del runtime es **opt-in** (`HH_VERBOSE=1`) mediante
  `ultramodern::debug::verbose()` / `HH_LOG(...)` (`ultramodern.hpp`). Normal runs quedan en silencio.
  Hooks de diagnóstico dedicados: `HH_CALLTRACE` (traza de llamadas), `HH_SOFT_LOOKUP`, `HH_DUMP_VI`.
- **Wiring de render**: ✅ verificado — eventos (`osSetEventMesg` IDs estándar) + routing RSP
  (`submit_rsp_task` → action queue) + `loadUCodeGBI` llegan a RT64, que **procesa display lists**.
  **Loader/directorio Nisitenma descartados**: el directorio es estático (`0x80038FF0`, magic
  `Nisitenma-Ichigo`), idéntico al emulador, y el port carga idx7/idx0/idx54.
  **Fix aplicado (syms)**: `FUN_80030610` era el `osCreateMesgQueue` del ROM e inicializaba
  `mtqueue/fullqueue` con `&__osThreadTail` (`0x80049930`), incompatible con las listas
  NULL-terminated del runtime de mensajes (el centinela se programaba como hilo y corrompía
  `__osRunningThread`). Se renombró a `osCreateMesgQueue` (entonces en `legacy/config/*.syms.toml`) para que las
  llamadas usen la versión del runtime (`reimplemented_funcs`).
  **Resuelto (ADR 0003)**: el subsistema VI se genera del ROM (`osCreateViManager`, `osViSetMode/
  Event/SwapBuffer`, `osViBlack`, `osViSetSpecialFeatures`, `osViGetCurrent/NextFramebuffer`); el
  runtime solo emula hardware (temporización del interrupt y `ViRegs` leídos de los **registros VI
  MMIO** que escribe `__osViSwapContext`). `OSViContext` (`0x8004AE70…`) queda como en el emulador
  (`00190001 8038F800 80049990 00013006 8005C560…`) y el gate de tareas RSP reabre (dispatcher 430
  llamadas/45 s, loader 10 módulos, 1359 DLs a RT64, sin símbolos faltantes).
  **Resuelto (deadlock SP, 2026-09-13)**: las completaciones SP/DP se asocian a la task
  (`sp_task_submitters`) y se entregan **al hilo emisor** mediante una cola de pendientes por
  (hilo, mq) en `mesgqueue.cpp` (`do_send` dirigido sin insertar en el ring + consumo en `do_recv`,
  también si el emisor aún no se había bloqueado). Antes, las colas SP/DP compartidas por t17/t18
  dejaban la completación en el waiter equivocado y el gate quedaba cerrado (dispatcher 9,5/s vs
  36/s). Evidencia (300 s): dispatcher **3723**, `[0x8005CD4C]` oscila 1/2, sin hilos congelados con
  task en vuelo (detalle: `../notes/2026-09-13-deadlock-sp-race.md` §5).
  **Resuelto (ucode de audio, 2026-09-13)**: la transición la dispara el ucode de audio (sin
  RSP-HLE el emulador no hace el burst). El ucode resultó ser el **aspMain estándar** y se recompiló
  con `RSPRecomp`: texto en ROM `0x37130` (`0xE18`), base IMEM `0x04001080`, **16 targets indirectos**
  (los 14 iniciales + `0x144C`/`0x170C` para los comandos `0x0F`/`0x0E`, que abortaban las tasks
  desde t≈13,4 s);
  integrado en `rsp/hh_aspMain.cpp` (config reproducible
  `recomp/rsp_hh_aspMain.toml`, build con `-msse4.1` por `rsp_vu_impl.hpp`) y registrado en
  `hh::get_rsp_microcode` para `M_AUDTASK`. Parches de runtime asociados: `sp_complete` de las tasks
  gfx en `submit_rsp_task` (el RSP real completa sin esperar al RDP/render), completación sintética
  en `osSpTaskYield` (modo dirigido) y opción **`HH_SP_SHARED`** (cola SP compartida estilo
  libultra); `dma_rdram_to_dmem`/`dma_dmem_to_rdram` pasan de `assert` (desactivado por `NDEBUG`) a
  chequeo real. Con esto el audio corre a **~60 tasks/s con 0 yields** y la petición `0x87` +
  carga `0x801B6600` (hito del emulador a t≈10,5 s) se repiten.
  **Resuelto (corrupción de contextos de audio, 2026-09-13)**: el crash del driver (`FUN_8001FD14`
  leía `{ptr,size}` basura de `ctx+4`) era una cadena: un burst de ticks hacía superar a la **cola
  virtual** de audio (headless, `support.cpp`) la ventana que asume el driver
  (`(0x2E0 - osAiGetLength()/4 + 0x100) & 0xFFF0` guardado en un `s16`), el tamaño hacía wrap a
  **negativo (~4 GiB)** y `osAiSetNextBuffer` lo encolaba; `osAiGetLength` quedaba envenenado
  (~2³⁰ frames) y el juego construía **command lists runaway** cuyos DMAs de `A_SAVEBUFF` pisaban
  las voces. **Fixes runtime**: `librecomp/src/ai.cpp` ignora byte_counts negativos/absurdos
  (`>0x200000`) y `src/platform/support.cpp` acota la cola virtual a ~1 VI (`sample_rate/60`). Resultado:
  300-420 s sin crash, ~18k audio tasks, iteraciones del mixer estables, 0 `[RSPW] PISA`, voces
  intactas. Instrumentación permanente (gated): `[CTXW]` (`HH_CTXWATCH`), `[AI ]` con timestamps,
  `[EVQ]`, `HH_TRCTRACE` (separa el flood `[TRC]` de `HH_TBLTRACE`).
  **Suavizado (2026-09-21)**: la cola SDL se mantiene centrada con un **resampler adaptativo (PLL)**
  guiado por el error de cola (`src/platform/support.cpp`): ajusta la tasa de salida ±`HH_AI_MAXC`
  (1%) hacia un objetivo `HH_AI_TARGET_MS` (50 ms) en vez de **descartar buffers** (el watermark
  `HH_AI_MAX_MS`, 150 ms, queda solo como salvaguarda dura). `hh_audio.log` incluye `queued` y
  `drops/s`; `HH_AI_SYNC=0` vuelve al comportamiento anterior. *Pendiente: validar de oído en
  Windows y ajustar `HH_AI_MAXC` si el desajuste real supera 1%.*
  **Frontera actual (2026-09-14)**: con el registro dinámico de módulos el port **cruza la
  transición y el burst**, y **renderiza geometría/píxeles reales en RT64** (logo, pantalla de
  título "PRESS START BUTTON" y attract 3D; capturas en `work/debug/port_shot_*.png`, nota
  `../notes/2026-09-14-geometria-pixeles.md`). Bloqueo siguiente: **entrar en gameplay** (input para
  "PRESS START"; `0x80037750` sigue 0 = título/attract) y robustez de cierre (SEGV al teardown en
  código de módulo, p.ej. `M25_FUN_801e2d94`). Ver `../notes/2026-09-14-registro-dinamico-modulos.md`
  y `../TODO.md` #10/#14.
  **Ojo con los wplog de MMIO**: vigilar el rango de registros AI (`0x04500000`) con el core wplog
  hace segfault al emulador en el boot (usar RDRAM).
  **Ojo**: los dumps de `r64dump` se leen como **uint32 LE nativo (sin `bswap32`)**; el `bswap32` los
  corrompe (`801BF1CC` → `CCF11B80`).

## 6. Toolchain de recompilación (ELF/splat, ADR 0011)

- **Entrada**: la **imagen expandida** `work/scratch/expanded/hh.expanded.z64` (ROM + cada code file
  descomprimido en offset sintético >16 MB). La config es **versionada**: `recomp/hybrid-heaven.us.yaml`
  (splat) y `recomp/hybrid-heaven.us.toml` (N64Recomp ELF mode). Se regenera con `tools/regenerate.py`:
  `gen_splat_yaml` → `splat_headless.sh split` → `build/recomp/asm/` → `build_elf.sh` (`llvm-mc`+`ld.lld`)
  → `build/recomp/elf/hybrid-heaven.us.elf` (**gate**: reconstruye la imagen byte a byte) → N64Recomp
  (`use_lookup_for_all_function_calls`) → `work/recomp_elf/RecompiledFuncs/` → materializado en
  `build/recomp/RecompiledFuncs/`. El set es el residente + 91 secciones `file_NN`
  (`relocatable_sections_path = overlays.txt`). Configs antiguas (Ghidra per-file: `game_combined.toml`,
  `setup_module.py`, `module_sources.inc`, syms por módulo) → `legacy/`.
- **El C recompilado no se versiona** (obra derivada; ADR 0009): vive bajo `build/` (gitignored), con la
  salida intermedia de N64Recomp en `work/recomp_elf/`.
- Recompilador: `toolchain/src/N64Recomp/build_recomp/N64Recomp` (OUTPUT_NAME de `N64RecompCLI`:
  rebuild con **`--target N64RecompCLI`**, no `--target N64Recomp`).
- **Parches del toolchain**: versionados como snapshot en `recomp/n64recomp_changes/` (p.ej. propagar
  `use_lookup_for_all_function_calls` en ELF mode —causa raíz del bloqueo del CaC— y los ajustes de
  libultra de ADR 0002). `toolchain/` está gitignored: el snapshot es la fuente de verdad.
- Registro de secciones: `src/hooks/sections.cpp` (`file_table.h` + hooks
  `add_loaded_function` / `load_overlay_by_id` / `unload_overlay_by_id`).
- `fix_fallthroughs.py` ya **no** lo invoca `regenerate.py`: es un post-paso manual si aparecen
  fallthroughs.
- Regla: **nunca editar a mano el C generado**; se regenera desde la config de splat/símbolos.

## 7. Preguntas abiertas

1. ✅ Bases RAM de los módulos de boot **deterministas** (idx 7/23/54, 3 runs). Pendiente: inventario
   automático de módulos posteriores (fuera del boot).
2. ✅ **Contrato del módulo**: MIPS autoligado en `base+offset`, direcciones absolutas, sin relocs
   (§2.1); la vía ELF/splat lo cubre con **secciones relocalizables** + lookups por dirección.
3. ¿Qué assets de la tabla Nisitenma son **código ejecutable** vs datos? (los 91 code files ya se
   tratan como código; quedan casos de datos-como-código a limpiar).
4. ¿El lock single-CPU es necesario con el modelo upstream + parches? (candidato a eliminar, §5).

Detalle y evidencia: `../notes/2026-09-21-migracion-via-referencia-elf.md`, `../notes/2026-09-11-*.md`
y `../notes/2026-09-08-overlay-directory.md`.
