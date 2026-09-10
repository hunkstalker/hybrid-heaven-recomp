# Fase 2 — Boot del núcleo plano (sesión 2026-09-10)

Registro técnico de la sesión que hizo arrancar el recompilado del núcleo plano (Fase 2)
hasta que **el entrypoint retorna y se crean threads del juego** (antes: SIGSEGV al crear el
primer thread). Estado: en progreso — falta integrar el modelo de threads de libultra.

## Resumen del estado

- **Antes de la sesión**: el boot colgaba en el loop SI (fix previo: `SI_STATUS=0`, `PI_STATUS=0`)
  y luego moría con SIGSEGV en `osStartThread` del juego (libultra compilado como C).
- **Ahora**: `init_heap → init_saving done → Calling entrypoint → Entrypoint returned` y se crean
  y ejecutan threads del juego. Queda un crash en un thread (puntero basura por incoherencia del
  modelo de threads).

## Cambios en config

- `config/game_unified.toml`:
  - `use_lookup_for_all_function_calls = true` (igual que el config retail original).
  - `[patches] ignored = ["FUN_800493c4"]` (era una blob de datos 0x434/0x435/... tratada como código).
- `config/us_unified.syms.toml` (entradas os + mid-función añadidas):
  - Reimplementadas (por nombre → hook del runtime): `osCreateThread` (0x80028260),
    `osStartThread` (0x80034C90), `osGetThreadId` (0x80030C40), `osSetThreadPri` (0x80030B60).
  - Funciones mid-función que el juego llama (no eran límites de símbolo) añadidas como `FUN_*`:
    `FUN_80032dc0` (0x1F0), `FUN_80029640` (0x50), `FUN_80034640` (0x60), `FUN_80030640` (0x130),
    `FUN_800304A0` (0x1A0), `FUN_80033C70` (0x790), `FUN_80026F58` (0x68C), `FUN_80033E00` (0x600),
    `FUN_80030610` (0x30), `FUN_80032660` (0x70 = `__osSetThreadPri`), `FUN_8002FB60` (0xC0),
    `FUN_8002AEA0` (0x410), `FUN_800266B0` (0x140).
  - El proceso de descubrimiento: run → "Failed to find function at 0xX" → añadir al syms → regenerar.

## Cambios en N64Recomp (`port/HybridHeavenRecomp/lib/N64ModernRuntime/N64Recomp`)

- `src/operations.cpp`: añadidas `cpu_trunc_l_s` y `cpu_trunc_l_d`
  (`TruncateLFromS`/`TruncateLFromD`, `Operand::FdU64`) — necesarias para `FUN_80034a10`.
- `src/recompilation.cpp` (hacer el generador tolerante a regiones data/overlay para que
  la generación COMPLETE; todas como no-op con warning):
  - Traps: `teq/tge/tgeu/tlt/tltu/tne/teqi/tgei/tgeiu/tlti/tltiu/tnei`.
  - `INVALID` (bytes que no decodifican → data).
  - COP2: `lwc2/ldc2/swc2/sdc2/mfc2/mtc2/cfc2/ctc2`; `movz/movn`; `cfc0/ctc0`;
    `sync/pref`; `jalr` con reg de retorno != `ra`.
  - `resolve_jal` caso Match: si la función destino es `reimplemented`/`ignored` → `LOOKUP_FUNC`
    (no llamada directa a un símbolo sin cuerpo).
  - "Unhandled link branch at end": emite el label `after_N` en vez de abortar (mal split en overlays).

## Cambios en el runtime (`librecomp` / `ultramodern`)

- `ultramodern/src/threads.cpp`: `_thread_func` ahora mantiene el global del juego
  `__osRunningThread` (0x80049940 → `rdram + 0x49940`) = TCB del thread actual, para que el código
  del juego que lee el thread actual directo vea el valor correcto.
- `librecomp/src/recomp.cpp`: log `[RT] thread addr/sp/arg/rdram` (debug temporal).
- `src/main/main.cpp` (port): crash handler ahora captura `si_addr` y `rip` (SA_SIGINFO) para
  diagnosticar segfaults con más detalle.

## Cambios en build del port

- `port/HybridHeavenRecomp/CMakeLists.txt`: `file(GLOB RecompiledFuncs/funcs_*.c)` en lugar de
  listar funcs_0..12 hardcodeados (el nº de archivos cambia con la generación).

## Cómo se regeneró / reconstruyó

- Generador: `build3/N64Recomp` (reconfigurado con "Unix Makefiles"; `build2/CMakeCache` estaba
  apuntando a una ruta movida). Target = `N64RecompCLI` (OUTPUT_NAME N64Recomp).
- Regeneración limpia (borrar `config/RecompiledFuncs_unified` antes):
  `N64Recomp config/game_unified.toml`.
- Copiar a `port/HybridHeavenRecomp/RecompiledFuncs` (el build usa esa copia).
- Build: `cmake --build port/HybridHeavenRecomp/build_dbg --target HybridHeavenRecomp -j$(nproc)`.
- Run headless:
  `DISPLAY=:99 SDL_AUDIODRIVER=dummy HH_CRASH_LOG=1 timeout 40 "Hybrid Heaven Recomp"`.

## Hallazgos clave

- La generación anterior a la sesión dejaba archivos stale (`funcs_9.c`, etc.) que inflaban el
  conteo y daban falsos errores (p.ej. `FUN_80034c90` que no existía). SIEMPRE regenerar limpio.
- Con `use_lookup=true` no se crean static funcs para targets mid-función → el runtime no los
  resuelve ("Failed to find function"). Solución: añadirlos al syms.
- El crash actual (thread) es un **modelo de threads en conflicto**: runtime (colas host) vs
  libultra del juego compilado como C (globals `__osRunQueue`/`__osRunningThread` + `__osEnqueueThread`).

## Bloqueante actual (decisión pendiente)

El juego llama a `0x800276CC` = `__osEnqueueThread` (helper de cola de libultra). Los os funcs
reimplementados (runtime) no mantienen la cola del juego; las funciones libultra compiladas como C
(`osStopThread`/`osDestroyThread`/`__osDispatchThread` en 0x80026300, 0x80026450, 0x800266B0,
0x80030A10) sí la usan → cola inconsistente → punteros basura → crash.

**Dos caminos (ver sesion.md §12-A):**
- **A)** Reimplementar TODAS las funciones libultra de threads del juego (mapear cada dirección a
  su nombre `os*` en el syms). Correcto pero requiere identificar cada dirección en el ROM.
- **B)** Que el runtime mantenga los globals del juego (`__osRunQueue`, `__osRunningThread`, TCBs)
  para que el libultra compilado como C funcione. Menos mapeos, más riesgo de bugs sutiles.

Los syms originales (`us_retail`/`us_dec`) no tenían NINGÚN nombre `os*`, así que el port original
tampoco reimplementaba os funcs (era un work-in-progress con fallos de boot).

---

## ACTUALIZACIÓN — se eligió la opción A y ya avanzó (2026-09-10, 2ª tanda)

**Resultado:** el juego pasó de crash a **estable (sin crash)** — arranca, crea threads y RT64
hace setup OK. Ahora se queda en **deadlock** (todos los threads en `S`/sleeping, ninguno en `R`;
utime no sube): el thread principal espera un mesg/evento que no llega.

### Herramienta nueva
- `pip install capstone` → disassembler MIPS big-endian fiable para identificar funciones os:
  `/tmp/mips_dis.py <vram> <nbytes>`. ROM big-endian (CS_MODE_BIG_ENDIAN).
- El proceso de identificación: desensamblar la función → reconocer su comportamiento (firma de
  args, qué globals/helpers libultra usa: `__osRunningThread` 0x8005-66C0, `__osSetThreadPri`
  0x80032660, `__osDispatchThread` 0x800326D0) → mapear al nombre `os*` en el syms.

### Mappings os añadidos (identificados por desensamblado)
- `osSendMesg` (0x80030A10, bloq. en fullqueue mq+4), `osJamMesg` (0x80026300, bloq. en mtqueue),
  `osRecvMesg` (0x800266B0, vacío→bloquea/error, si no dequeue) — cola de mensajes.
- `osStopThread` (0x80029580, enlaza thread y despacha).
- Funciones de juego (mid-funciones) añadidas: `FUN_80001E70`, `FUN_80001EA0`, `FUN_8001F160`
  (memset/bzero), y de la tanda previa `FUN_8002AEA0`, `FUN_800266B0`, etc.
- El mapeo osSendMesg/osJamMesg/osRecvMesg eliminó el "Failed to find 0x800276CC" (la cola de
  mensajes ya no corre como C → no llama a `__osEnqueueThread`).

### Notas / riesgos
- `osStopThread` del runtime hace `assert` si el thread no es el actual (threads.cpp) — el juego
  puede parar threads arbitrarios → revisar si esto provoca el deadlock o un assert.
- El deadlock actual: identificar **qué mesg/evento espera el thread principal** y por qué no
  llega (otro os que sigue como C, o señal VI/timer/audio no entregada).
- Los cambios en N64Recomp (operations.cpp, recompilation.cpp) siguen en `config/n64recomp_changes/`
  (submódulo sin .git).

---

## ACTUALIZACIÓN 2 — diagnóstico del deadlock (2026-09-10, 3ª tanda)

Se instrumentó el runtime con trazas (`[TH]` en threads.cpp, `[MQ]` en mesgqueue.cpp) para trazar
os funcs de threads/mesg. Resultado:

**Mapa de threads (tras arranque):**
- Thread 1 (entrypoint, FUN_80001124): corre y retorna OK ("Entrypoint returned").
- Thread 0 (thread principal del juego, FUN_8002AEA0): bloquea en `osRecvMesg(BLOCK)` en la cola
  principal **0x8005bf30** (count=200, vacía).
- Thread 5 (FUN_800011b0): bloquea en `osRecvMesg(BLOCK)` en **0x800cd4d8**.

**Nadie envía a la cola principal**: no hay `osSendMesg`/`osJamMesg` de threads del juego ni
mensajes externos (`enqueue_external_message`). Los threads crean colas y todos se quedan
esperando. → El loop principal espera el **primer evento** que no llega.

**Interpretación:** el juego N64 espera un evento de hardware/emulación (VI vblank, controller,
timer, o tarea del scheduler/RDP) que la capa de emulación debería entregar a la cola principal
vía `osSetEventMesg`/`osSendMesg`. Probablemente faltan por reimplementar los os funcs de
eventos/scheduler/VI: `osSetEventMesg`, `osCreateViManager`, `osCreatePiManager`, `osSpTaskStart`,
`osContInit`.

**Mappings añadidos esta tanda:** `osCreateMesgQueue` (0x80030610).

**Trazas de debug (temporales, en el código):** `[TH]` en osCreateThread/osStartThread/osStopThread
(threads.cpp) y `[MQ]` en osCreateMesgQueue/osSendMesg/osRecvMesg/do_recv (mesgqueue.cpp).
