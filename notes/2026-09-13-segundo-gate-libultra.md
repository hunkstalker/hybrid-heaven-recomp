# 2026-09-13 — Segundo gate: des-stubbing de libultra y bloqueo del loader

> Nota de evidencia (continuación de `2026-09-13-arranque-memsize-y-accesorios.md`). No operativa.

## 1. Contexto

Tras corregir el tamaño de RDRAM (4 MB), el port avanzaba pero quedaba en `fase=0` con la tabla de
recursos en `0001:800F41C0`. Esta nota documenta la cadena de hallazgos y fixes hasta el bloqueo actual.

## 2. Referencia de emulador que progresa (ya en la nota anterior)

`tools/analysis/emu_ref.sh`: 4 MB + input (`hhinput.so`) + RSP-HLE + **vídeo real rice/GLX** sobre
Xvfb. Reproduce exactamente a BizHawk (tabla de 6 entradas a t≈10 s). El vídeo real es imprescindible.

## 3. Trazadores y su comparabilidad (IMPORTANTE)

- **Port** (`HH_CALLTRACE`): registra solo **llamadas indirectas** (`get_function`). No registra
  llamadas directas ni dispatches de hilos.
- **Emulador** (`HH_JALTRACE`, en `work/mupen-src/.../pure_interp.c`): registra **todos los saltos**
  (incluye IPL3 `0xA400xxxx`), pero **no** los dispatches de entry de hilo (p. ej. `0x80001124`).
- Por eso la alineación por posición es inválida; comparar **ventanas** de secuencia o alinear por
  subsecuencia permitiendo saltos. El boot entra en el emulador por `0x80028b10` (osInitialize),
  no por `0x80001078` (entry del port).

## 4. CAUSA RAÍZ del boot: `osInitialize` (y cadena) stubeada

Comparando ventanas de arranque:

- **EMU**: `osInitialize` (0x80028B10) → `__osGetSR` → `0x80028EC0` → `0x80032DC0` →
  `__osSpRawReadIo` → `0x800309E0` → `__osSpRawWriteIo` → `0x80028DB8` → `0x800304A0` →
  `0x80033C70` → `0x80026F58/6E58` → `0x800279F0` → `__osGetCause` → `osGetMemSize`.
- **PORT**: iba directo de `osInitialize` a `osGetMemSize` (¡toda la init saltada!) porque
  `osInitialize_recomp` era un no-op y las funciones de la cadena estaban en la lista ignorada del
  recompilador.

**Fix**: en `toolchain/src/N64Recomp/src/symbol_lists.cpp` se des-bloquearon
`osInitialize`, `__osInitialize_common`, `__osGetSR/SetSR/GetCause/SetCause`, `__osSpRawReadIo/WriteIo`.
Además se renombró el stub C++ del runtime `osInitialize` → **`osInitialize_stub`** en
`ultradmodern/src/ultrainit.cpp` + `ultra64.h` + `ultra_translation.cpp` (conflicto de firma con la
versión generada). **Verificado**: la secuencia de arranque del port ya es idéntica a la del emulador.

## 5. Estados de libultra del juego que faltaban (ya replicados)

- **PI manager**: `osCreatePiManager` (escribe `0x8004AB10…`), `__osDevMgrMain` (thread entry
  `0x8002AEA0`, que era mid-entry de `FUN_8002ae64`: se partió el símbolo en
  `config/us_ghidra.syms.toml`). Antes: stub vacío + `Failed to find function at 0x8002AEA0`.
- **VI**: `__osViInit` / `__osViSwapContext` (escriben `0x8004AE70…`), des-bloqueadas.
- **`__osEventStateTab`** (0x800CD5F0 + e·8): el `osSetEventMesg` del ROM la escribe; el runtime del
  port no. **Fix**: el `osSetEventMesg` del runtime (`events.cpp`) ahora también escribe la tabla.
  Verificado: coincide en todos los eventos del juego (e4/SP, e5/SI, e8/PI, e9/DP, e12, e14).
- **`__osEventStateTab` de `osSetEventMesg`** se descifró generando temporalmente la función del ROM en
  la config `game_unified` y leyendo el C generado (método reutilizable).

Todos los fixes van en la lista `N64Recomp::reimplemented_funcs` del toolchain (ver ADR 0002).

## 6. Estado tras los fixes

- El port **no aborta**; la cadena de boot coincide; los diffs de RDRAM (fuera de módulos recompilados
  y del framebuffer de RT64) bajaron **10.659 → 3.854** palabras.
- El juego sigue en `fase=0` (`0001:800F41C0`) pero ya en su **bucle principal** (`FUN_80001454` +
  `osAiGetLength` + `osRecvMesg`).
- El framebuffer `0xFFFC` que RT64 vuelca en `0x800D0000` es esperado (`Framebuffer::copyNativeToRAM`
  en `fullSync`); el emulador no escribe ahí porque sincroniza de otra forma.
- Las display lists del juego (`0x801C2000`) las construye el **módulo 54** (`0x803842C4`); el port
  **no las escribe** (watchpoint gdb = 0 disparos) → síntoma de que el juego no llega a la fase de render.

## 7. BLOQUEO ACTUAL: el loader sale antes de iterar todos los módulos

- El loader es `FUN_80003824` (descompresor Nisitenma/LZKN64). Su bucle usa:
  `0x8005D014` (cursor ROM), `0x8005D018` (bytes restantes), `0x8005D01C`/`0x8005D020` (bloque 0x2000).
- En el port los contadores quedan **congelados** (`ld18=0`, `ld1C=-9`, `ld20=-8`) desde VIS≈60 — **no
  es lentitud, está terminado**.
- El loader recibe tamaños correctos (gdb: `a0=0x4E69A8 a1=0x80107830 a2=0x55DD4 a3=0x801BF1A0` para
  el módulo idx 7; luego `a0=0x4E5F40 a1=0x800F41C0 a2=0xA68`), y `FUN_80003DB4` maneja bien el
  último bloque parcial (underflow transitorio corregido a 0).
- El port registra **772 `SETID`** (0x80017384) y el emulador **1302**; el emulador sigue iterando.
- La decisión de qué módulo cargar está en el caller `0x80004700-0x80004774`:
  `a2 = (entry[+0x14] & mask) - entry[+0x0C]`, leyendo el **directorio Nisitenma** en RDRAM
  (base del DMA buffer `0x80089518`).

**Siguiente paso**: comparar las entradas del directorio Nisitenma (campos `+0xC`/`+0x14`) port vs
emulador para el módulo que el port se salta, y el chequeo previo del directorio en `FUN_80003824`.

## 8. Herramientas y artefactos de esta sesión

- `tools/analysis/emu_ref.sh` — referencia que progresa.
- `tools/analysis/diff_rdram.py` — diff de RDRAM por rangos.
- `work/libmupen64plus-wplog.so` — mupen con log de escrituras configurable:
  `HH_WPLOG=1 HH_WPLO=<hex> HH_WPHI=<hex>` (PC incluido).
- Port: `[RND]` ampliado con `ld14/ld18/ld1C/ld20`; `HH_PILOG`, `HH_QLOG`, `HH_INLOG`, `HH_TBLTRACE`.
- GDB watchpoints vivos en `work/debug/*.gdb`.
- ⚠️ El ejecutable del recompilador es `toolchain/src/N64Recomp/build_recomp/N64Recomp` (OUTPUT_NAME de
  `N64RecompCLI`): hay que reconstruir con **`--target N64RecompCLI`**; `--target N64Recomp` no relinkea.
