# 2026-09-13 — ADR 0003 implementado: subsistema VI del ROM (opción A)

> Evidencia de la implementación de la decisión A (ver `../docs/adr/0003-vi-libultra-del-rom.md`).
> Continúa `2026-09-13-vi-context-y-sentinel.md`.

## 1. Cambios aplicados

**Toolchain** (`toolchain/src/N64Recomp/src/symbol_lists.cpp`, gitignored; documentado en ADR 0003):
- Fuera de `reimplemented_funcs` e `ignored_funcs`: `osCreateViManager`, `osViSetMode`,
  `osViSetEvent`, `osViSwapBuffer`, `osViBlack`, `osViSetSpecialFeatures`,
  `osViGetCurrentFramebuffer`, `osViGetNextFramebuffer` (se generan del ROM).
- Añadido `osGbpakInit` a `reimplemented_funcs` (stub de host: GB_PAK_ERR_NOPAK).
- Se mantienen `osViSetXScale/YScale` (runtime) y `osSetEventMesg` (entrega del interrupt).

**Runtime** (gitignored; documentado en ADR 0003 / `docs/architecture.md` §5):
- `events.cpp`: `vi_thread_func` lee los **registros VI MMIO** (`0x04400000+`, escritos por
  `__osViSwapContext`) para alimentar `ViRegs`/RT64 (`load_vi_regs`); el modo dummy previo al
  arranque se conserva. Se entrega el evento VI al mq registrado (`viMgrMain` lo consume).
- Eliminados los stubs/wrappers que ya no aplican (`osViSetEvent` runtime, `osViSwapBuffer`,
  `osViSetMode`, `osViSetSpecialFeatures`, `osViBlack`, `osViGetCurrent/NextFramebuffer`,
  `osCreateViManager_recomp`) de `events.cpp`, `vi.cpp`, `ultra_translation.cpp` y `ultra64.h`.
- `pak.cpp`: `osGbpakInit_recomp` devuelve `GB_PAK_ERR_NOPAK` (0xB) y rellena `OSPfs::status`.

**Syms** (`config/us_ghidra.syms.toml` + `us_combined.syms.toml`, tracked):
- `FUN_80030610` → `osCreateMesgQueue` (sesión anterior).
- Splits de funciones sobre-dimensionadas por Ghidra (mid-entries reales llamados por el juego):
  `FUN_800021b4`→+`FUN_80002364`; `FUN_80024358`→+`FUN_800243f0`; `FUN_80024820`→+`FUN_8002487c`;
  `FUN_80024998`→+`FUN_80024a1c`/`FUN_80024adc`; `FUN_80024e0c`→+`FUN_80024ee8`;
  `FUN_80025834`→+`FUN_80025908`/`FUN_80025940`;
  `FUN_80025cdc`→+`FUN_80025d78`/`FUN_80026058`/`FUN_80026098`.

## 2. Validación (run normal, 65 s, sin gdb)

| Medida | Antes (bloqueo VI) | Ahora |
|---|---|---|
| `__osViInit` | 0 | 1 |
| `__osViSwapContext` | 0 | 843 (1/retrace; emulador 541/10 s) |
| `OSViContext` (`0x8004AE70`) | todo 0 | `00190001 8038F800 80049990 00013006 8005C560…` = **emulador** |
| `[[0x8004AED0]+4]` (framebuffer) | 0 | `0x8038F800` |
| `FUN_80005270` (dispatcher) | 6 / 20 s | **430 / 45 s** |
| `FUN_80003824` (loader) | 2–3 | **10** |
| Tareas gfx tipo 1 a RT64 | 3 | **1359** (con texturas; `G_TEXRECT`/`LOADBLOCK`) |
| Símbolos faltantes | abort | **0** (65 s sin abort) |
| `fase` (`u16 0x80037750`) | 0 | 0 (siguiente frontera) |

- Objetos de boot instanciados: `0x801D0474` (`+0x14=80000000`, `+0x18=8012E584`,
  `+0x1C=801BF1CC`). Se ejecuta código del módulo 23 (`FUN_801BF1CC`, `FUN_801C11BC`,
  `FUN_801C134C`…).
- Contador `0x8005CD4C` oscila (0/1/2) con el hilo 17 activo entre sus colas.

## 3. Siguiente frontera

`fase` sigue en 0 y `0x801CFE00/02` en 0: los callbacks de progreso del módulo 23
(`FUN_801CBDC0`, `FUN_801CBE88`, `FUN_801CBE90`) **no se ejecutan** (0 llamadas en la traza de
45 s). El nodo de boot apunta a `+0x1C=0x801BF1CC` (módulo 23). Tarea siguiente: rastrear la
cadena de descriptores/objetos que debe instalar `0x801CBE88` (comparar con el emulador la
selección de descriptor y el estado del nodo), ahora que el gate y el contexto VI ya no bloquean.
