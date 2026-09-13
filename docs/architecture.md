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
| Símbolos | **Ghidra** (N64LoaderWV) → `config/us_ghidra.syms.toml` |

Sin decompilación de referencia: los límites de función dependen de Ghidra y de un
validador propio (ver `../TODO.md`, fundación 3).

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
  `0xA9213032`, 564464 B) → `tools/setup_module.py` lo extrae de la ROM **sin ejecutar el juego**
  (determinista). Una nota histórica que decía que `lzkn64` daba "basura" era **errónea**.
- Variantes **`LZSS 5`/`LZSS 7`** del `trans`: por caracterizar (otros módulos podrían usarlas).
- El código plano NO está comprimido; se comprimen assets y módulos de código.

## 5. Contrato de runtime (N64ModernRuntime) y parches del port

- **Modelo single-CPU**: el N64 tiene una CPU; el runtime debe serializar los hilos de juego.
- Hilos, message queues, eventos (VI/AI/SP/DP/SI/PI) y VI timing vienen del runtime.
- **Base**: `lib/N64ModernRuntime` es un fork del upstream (`toolchain/src/N64ModernRuntime`). Toda
  divergencia debe estar aquí documentada y justificada; el objetivo es mantenerla **mínima**.
- **Parches funcionales del port (deliberados):**
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
  `__osRunningThread`). Se renombró a `osCreateMesgQueue` en `config/*.syms.toml` para que las
  llamadas usen la versión del runtime (`reimplemented_funcs`).
  **Resuelto (ADR 0003)**: el subsistema VI se genera del ROM (`osCreateViManager`, `osViSetMode/
  Event/SwapBuffer`, `osViBlack`, `osViSetSpecialFeatures`, `osViGetCurrent/NextFramebuffer`); el
  runtime solo emula hardware (temporización del interrupt y `ViRegs` leídos de los **registros VI
  MMIO** que escribe `__osViSwapContext`). `OSViContext` (`0x8004AE70…`) queda como en el emulador
  (`00190001 8038F800 80049990 00013006 8005C560…`) y el gate de tareas RSP reabre (dispatcher 430
  llamadas/45 s, loader 10 módulos, 1359 DLs a RT64, sin símbolos faltantes).
  **Frontera actual**: `fase` sigue en 0 porque los callbacks de progreso del módulo 23
  (`FUN_801CBDC0`/`FUN_801CBE88`/`FUN_801CBE90`, que avanzan `0x801CFE00/02`) no se ejecutan; el nodo
  de boot apunta a `+0x1C=0x801BF1CC` (ver `../TODO.md` #14 y
  `../notes/2026-09-13-vi-opcion-a-implementada.md`).

## 6. Toolchain de recompilación

- Config activa: `config/game_combined.toml` → `us_combined.syms.toml` → `RecompiledFuncs_combined/`
  (imagen plana + módulos idx 7/23/54). La `game_unified.toml` es auxiliar.
- Recompilador: `toolchain/src/N64Recomp/build_recomp/N64Recomp` (OUTPUT_NAME de `N64RecompCLI`:
  rebuild con **`--target N64RecompCLI`**, no `--target N64Recomp`).
- **Parche del toolchain** (`symbol_lists.cpp`, ver ADR 0002): se quitó de `reimplemented_funcs`/
  `ignored_funcs` la init de libultra que el juego usa como fuente de verdad (`osInitialize`,
  `__osInitialize_common`, `osCreatePiManager`, `__osDevMgrMain`, `__osViInit`, `__osViSwapContext`,
  `__osGetSR/SetSR/GetCause/SetCause`, `__osSpRawReadIo/WriteIo`) para que se recompile la versión del
  ROM. `toolchain/` está gitignored: el parche se documenta aquí (y en ADR 0002), no se versiona.
- Port: `port/HybridHeavenRecomp/` (CMake globs `RecompiledFuncs/funcs_*.c`).
- Post-paso obligatorio: `tools/analysis/fix_fallthroughs.py`.
- Quirk conocido: añadir la declaración `osYieldThread_recomp` a `funcs.h` tras cada regen.
- Regla: **nunca editar a mano el C generado**; todo fix va a la syms/config (ADR 0002).

## 7. Preguntas abiertas (bloquean el diseño)

1. ✅ Bases RAM de los módulos de boot **deterministas** (idx 7/23/54, 3 runs). Pendiente: inventario
   automático de módulos posteriores (fuera del boot).
2. ¿Cuál es el **contrato del módulo** (cómo se referencian sus funciones: `base+offset`? tabla?
   relocs internas?).
3. ¿Qué assets de la tabla Nisitenma son **código ejecutable** vs datos?
4. ¿El lock single-CPU es necesario con el modelo upstream + parches de racer?

Detalle y evidencia: `../notes/2026-09-10-*.md` y `../notes/2026-09-08-overlay-directory.md`.
