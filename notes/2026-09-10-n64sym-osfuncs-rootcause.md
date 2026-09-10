# SESIÓN 2026-09-10 — CAUSA RAÍZ del bloqueo de render: os funcs de libultra sin mapear

> **ESTE ES EL HALLAZGO CLAVE.** Documenta cómo se descubrió y cómo se resuelve el bloqueo de
> render (thread 5 colgado en `osRecvMesg(0x8005be40)`). Corrige conclusiones anteriores y establece
> la causa raíz + la solución. Complementa y corrige `notes/2026-09-10-render-investigation.md` §7 y
> `notes/2026-09-10-osfuncs-investigation.md`.

## 0. Resumen ejecutivo

- **CAUSA RAÍZ CONFIRMADA**: la syms (`config/us_unified.syms.toml`) **solo mapea 11 os funcs**, pero
  el juego usa ~147. La gran mayoría de os funcs de libultra están en la syms como **funciones de
  juego** (`FUN_xxx`), por lo que el recompilador las **compila como código de juego** en lugar de usar
  las implementaciones del runtime (N64ModernRuntime).
- **Por qué bloquea**: el juego usa su **propio** `osSetTimer` (compilado como código), que gestiona su
  lista de timers vía `__osInsertTimer`/`__osSetTimerIntr`/`__osTimerInterrupt` y el registro
  **cop0 Compare** — un mecanismo de hardware que el runtime NO emula. El timer nunca dispara →
  thread 5 queda colgado en `osRecvMesg(0x8005be40)`.
- **SOLUCIÓN**: renombrar en la syms los `FUN_xxx` a sus **nombres os reales** (los que el runtime
  proporciona), usando los **vrams correctos** que da `n64sym`. Así el recompilador los marca
  `_recomp`/ignored y usa las implementaciones del runtime. Es el **patrón estándar** de
  Goemon64Recomp/Zelda64Recomp.
- **CORRECCIÓN importante**: la conclusión anterior ("os funcs mal mapeados") era **errónea** — el
  desensamblador usaba un offset de ROM equivocado. Los 11 os funcs mapeados son CORRECTOS.

---

## 1. La herramienta canónica: `n64sym`

La documentación de N64Recomp dice explícitamente que el recompilador **espera que todas las
funciones libultra estén correctamente identificadas y nombradas**, y que **hay herramientas que
ayudan a identificarlas**. La herramienta es [`n64sym`](https://github.com/shygoo/n64sym):

- Identifica símbolos en ROMs N64 por **firma con doble-CRC + enmascarado de relocations**
  (enmascara los bits de `.hi16`/`.lo16`/`.targ26` que cambian entre binarios), **no** por offset.
- Tiene una **base de datos integrada de libultra** (versiones 2.0c–2.0l, incluidas `libgultra`,
  `libultra`, `libleo`, `libnos`).
- Uso: `n64sym <rom>.z64 -s -f default -o out.txt`.

**Construcción en el contenedor:**
```sh
git clone --depth 1 https://github.com/shygoo/n64sym.git
apk add --no-cache make g++    # + limites.h fix en n64sym.cpp / n64sig.cpp (PATH_MAX)
cd n64sym && make
./bin/n64sym /app/hybrid-heaven-recomp/work/roms/us_retail.z64 -s -f default -o /tmp/hh_syms.txt
```

> **Fix de build (Linux/musl):** `PATH_MAX` no estaba declarado → añadir `#include <limits.h>` en
> `src/n64sym.cpp` y `src/n64sig.cpp`.

## 2. Resultado: lista de os funcs (147)

Salida guardada como referencia en `notes/reference/n64sym_osfuncs_us_retail.txt`. Los os funcs
tienen sus **vrams correctos** (confirmados por firma, no por offset). Los críticos:

| os func | vram (n64sym) |
|---|---|
| osSendMesg | 0x80026300 |
| osRecvMesg | 0x800266B0 |
| osCreateMesgQueue | 0x80030610 |
| osJamMesg | 0x80030A10 |
| osSetEventMesg | 0x8002FB60 |
| osGetCount | 0x8002BF90 |
| **osGetTime** | **0x80031190** |
| **osSetTimer** | **0x80034560** |
| __osInsertTimer | 0x80031498 |
| __osSetTimerIntr | 0x80031424 |
| __osTimerInterrupt | 0x800312AC |
| osCreateViManager | 0x800346C0 |
| osViSetMode | 0x80029FA0 |
| osViSwapBuffer | 0x80030DC0 |
| osViSetEvent | 0x800329F0 |
| osViBlack | 0x800295D0 |
| osViSetYScale | 0x80034DE0 |
| __osViInit | 0x80032220 |
| __osViSwapContext | 0x80032360 |
| osSpTaskLoad | 0x80026B0C |
| osSpTaskStartGo | 0x80026C9C |
| osSpTaskYield | 0x80029690 |
| osSpTaskYielded | 0x80030FF0 |
| osCreateThread | 0x80028260 |
| osStartThread | 0x80034C90 |
| osStopThread | 0x800265F0 |
| osDestroyThread | 0x80026CE0 |
| osGetThreadPri | 0x80030C40 |
| osSetThreadPri | 0x80030B60 |
| osInitialize | 0x80028B10 |
| osCreatePiManager | 0x8002AC60 |
| osPiStartDma | 0x8002BFA0 |
| osContInit | 0x80027F20 |
| osContStartReadData | 0x800283B0 |
| osContGetReadData | 0x80028434 |
| osCartRomInit | 0x80032BE0 |
| osGetMemSize | 0x8002C0B0 |
| osAiGetLength | 0x80033C60 |
| osAiSetNextBuffer | 0x80034F70 |
| osYieldThread | 0x80033CD0 |
| osVirtualToPhysical | 0x80028A10 |
| __osTimerList (datos) | 0x8004AE60 |
| __osViCurr / __osViNext (datos) | 0x8004AED0 / 0x8004AED4 |

## 3. CORRECCIÓN: por qué la conclusión anterior era errónea

En la sesión previa se concluyó que "los os funcs están mal mapeados" porque los vram disasemblaban
a funciones de juego. **FALSO**: el desensamblador usaba el offset de ROM equivocado.

- **Offset correcto para z64**: `rom_off = vram - 0x7FFFF400` (porque vram `0x80000400` = ROM offset
  `0x1000`, hay un header de `0xC00`).
- El script anterior usaba `vram - 0x80000000` → leía `0xC00` bytes antes → código incorrecto.
- Con el offset correcto: `0x80000400` = boot real, `0x80026300` = osSendMesg real
  (`addiu sp,-0x38; sw ra; sw a0...; jal __osDisableInt`).

**Verificación**: `n64sym` confirma que los 11 os funcs ya mapeados están en los vrams CORRECTOS.
`0x800266B0` (osRecvMesg), `0x80026300` (osSendMesg), `0x80030610` (osCreateMesgQueue), etc.

## 4. Por qué la syms solo mapea 11 os funcs

La syms se construyó por **byte-matching con Goemon** (método del handoff §3), que resultó poco
fiable (la ROM `mnsg.z64` de Goemon tiene otra base de offset, y el matching por bytes dio vrams
que no son los os funcs en todos los casos — de hecho el matching dejó la mayoría de os funcs sin
nombre, quedando como `FUN_xxx`).

- Goemon64RecompSyms se generó desde el **decomp** de Goemon (mnsg), donde los os funcs YA tienen
  su nombre correcto. Por eso Goemon funciona.
- HH no tiene decomp → la syms quedó con los os funcs como `FUN_xxx` → el recompilador los compila
  como código de juego.

## 5. LA SOLUCIÓN (patrón estándar N64Recomp)

Renombrar en `config/us_unified.syms.toml` los `FUN_xxx` a sus **nombres os reales** (los que el
runtime N64ModernRuntime proporciona), usando los vrams de `n64sym`. El recompilador entonces:
1. Detecta el nombre en `reimplemented_funcs` (symbol_lists.cpp) → `rename_function(name + "_recomp")`,
   `func.reimplemented = true`, `func.ignored = true` (ver `toolchain/src/N64Recomp/src/main.cpp:482`).
2. NO compila la función → usa la implementación del runtime (`osSetTimer_recomp`, etc.).

**Os funcs críticos a mapear primero** (cadena de timers, la causa del bloqueo):
`osSetTimer`(0x80034560), `osGetTime`(0x80031190), `osGetCount`(0x8002BF90),
`__osInsertTimer`(0x80031498), `__osSetTimerIntr`(0x80031424), `__osTimerInterrupt`(0x800312AC).
Y para el mecanismo de tareas/VI: `osSpTaskLoad`, `osSpTaskStartGo`, `osCreateViManager`,
`osViSetMode`, `osViSwapBuffer`, `osViSetEvent`, `osViBlack`, `osViSetYScale`.

> **IMPORTANTE (validación previa):** antes de mapear un os func, verificar que el runtime
> (N64ModernRuntime) proporciona su `_recomp` (si no, habrá **error de link**). Revisar
> `librecomp/src/ultra_translation.cpp` y `ultramodern/src/*.cpp`. Los internos `__osInsertTimer`/
> `__osSetTimerIntr`/`__osTimerInterrupt` quizá NO tengan `_recomp` en el runtime → mapear solo los
> que el runtime implementa (el runtime usa su propia lista/timer thread, no la de `__osTimerList`).

### Proceso
1. Usar `n64sym` para obtener los vrams correctos (ya hecho → `notes/reference/n64sym_osfuncs_us_retail.txt`).
2. Renombrar en `us_unified.syms.toml` los `FUN_xxx` → os funcs (verificar `_recomp` existente).
3. Regenerar: `toolchain/src/N64Recomp/build_recomp/N64Recomp config/game_unified.toml`.
4. Copiar `RecompiledFuncs_unified` → `port/HybridHeavenRecomp/RecompiledFuncs`.
5. Build + run headless (Xvfb + lavapipe) → comprobar si thread 5 desbloquea y aparece render.

## 6. Método de validación runtime (recuerda)

- Instrumentar los shims de `ultra_translation.cpp` con `dladdr`/`addr2line` para capturar el
  **caller recompilado** (el `ctx->r31` es 0, usar `__builtin_return_address` + `dladdr`).
- Run headless: `DISPLAY=:99 SDL_AUDIODRIVER=dummy VK_ICD_FILENAMES=.../lvp_icd.x86_64.json
  timeout N ./"Hybrid Heaven Recomp"`. `exit=124` = vivo (timeout); `139` = SIGSEGV.
- **Offset de disasm z64**: `rom_off = vram - 0x7FFFF400` (header 0xC00).

## 7. Estado / archivos

- `notes/reference/n64sym_osfuncs_us_retail.txt` — lista de 147 os funcs (salida de n64sym).
- `n64sym` compilado en `/tmp/n64sym` (bin `bin/n64sym`); firmas integradas OK.
- La syms **NO se ha modificado aún** — el mapeo de os funcs es la siguiente acción.
- El repo sigue en baseline conocido-bueno (boot OK, thread 5 bloqueado). `funcs_6.c` modificado
  (preexistente, diff NAN_CHECK, no de esta sesión).
