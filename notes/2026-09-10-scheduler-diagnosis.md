# SESIÓN 2026-09-10 — DIAGNÓSTICO DEL SCHEDULER KONAMI (paso previo al fix)

> Complementa `notes/2026-09-10-handoff-fase2.md` y `notes/2026-09-10-scheduler-ghidra.md`.
> Resultado de una sesión de análisis estático con Ghidra (12.1.3) sobre el proyecto HH.
> Estado: **diagnóstico preciso del deadlock**. El fix se decide instrumentando el runtime.

---

## 0. Resumen ejecutivo

El thread de juego (thread 5 = `FUN_800011b0`) bloquea en `osRecvMesg(0x8005be40)` ANTES de
llegar a su bucle principal. La VI vblank SÍ llega al VI manager del juego, pero el reenvío a la
cola del game loop no ocurre porque **el campo `[structVI + 0x10]` (cola destino del reenvío) está
a NULL** en el recompilado. Además el log runtime muestra **0 tareas RSP**. El juego registra el VI
para reenviar a `0x8005c560`, mientras thread 5 espera en `0x8005be40` — colas distintas.

## 1. Arquitectura del scheduler (mapeada con Ghidra)

| Función | VRAM | Rol |
|---|---|---|
| `FUN_8002ac60` | 0x8002ac60 | **Setup del scheduler**: crea la cola principal `0x8005bf30` (osCreateMesgQueue 0x80030610), crea+y arranca el hilo dispatcher (id 0, entry `0x8002aea0`, arg `0x8004ab10`), guarda el puntero a la cola en **`0x8004ab18`**, conecta el evento VI (osSetEventMesg event=8 → `0x800cd4b0`). |
| `FUN_8002aea0` | 0x8002aea0 | **Dispatcher principal**: `osRecvMesg(BLOCK)` sobre `[0x8004ab18]` (=`0x8005bf30`), luego despacha los task structs. **NO es función Ghidra** (no disasembled; lo esconde el análisis). |
| `FUN_8002bfa0` | 0x8002bfa0 | **Emisor de tareas** (tipo 0xb/0xc): lee la cola vía `FUN_800326f0()` y hace `osJamMesg`/`osSendMesg` (0x80030a10/0x80026300). |
| `FUN_800304f0` | 0x800304f0 | **Emisor de tareas 2** (tipo 0xf/0x10), mismo patrón. |
| `FUN_8001ffac` | 0x8001ffac | Wrapper: llama `FUN_8002bfa0` + `FUN_80028a10`. |
| `FUN_80001fb4` | 0x80001fb4 | Wrapper: llama `FUN_800304f0` + `osRecvMesg(0x8005c268)` (espera fin de tarea). |
| `FUN_800011b0` | 0x800011b0 | **Thread 5 (game loop)** — ver §2. |
| `FUN_800346c0` | 0x800346c0 | **Setup del VI manager**: crea cola `0x800ce920` (5), `osSetEventMesg(7/3)→0x800ce920`, crea+arranca hilo VI (`0x80034840`, arg `0x8004aff0`). |
| `FUN_80034840` | 0x80034840 | **Loop del VI manager**: recv en `[0x8004aff0+0xc]`(=0x800ce920); msg==0xd → `osViSetMode` + **`osSendMesg([structVI+0x10], [structVI+0x14])`** (línea 1053) — el reenvío al game loop. |
| `FUN_800349d0` | 0x800349d0 | Devuelve `_LAB_8004aed0` (puntero al struct VI activo). |
| `FUN_800329f0` | 0x800329f0 | **osViSetEvent del juego**: escribe `[nextVI+0x10]=mq`, `[nextVI+0x14]=msg`, `[nextVI+2]=retrace`. |
| `FUN_80000460` | 0x80000460 | **Setup por frame**: crea las 8 colas RSP (count 8) en el struct de `0x8005c4b0`, setup VI manager, `FUN_80029fa0` (submit tarea display), **`osViSetEvent(puVar1,0x29a,retrace)` (línea 1054)** con `puVar1=0x8005c4b0+0xB0=0x8005c560`. |

## 2. Flujo del boot (thread 5 = `FUN_800011b0`)

`FUN_80001e70 → FUN_80007b70 → FUN_80001bc0` (setup de 3 tareas de audio, completion q=0x8005c288)
→ crea colas `0x8005c268`(1) y `0x8005c288`(64) → `FUN_80001060` (NTSC/PAL) →
`FUN_80000460(0x8005c4b0, <modo>, 1)` (crea 8 colas RSP + VI manager + osViSetEvent→0x8005c560 +
submit tarea) → `FUN_800020b0`, `FUN_80016df0`, `FUN_8000469c`×5 (malloc) → `FUN_8001f204`
(audio buf) → `FUN_80005444`, `FUN_80005624`, `FUN_80133aac` → **bucle `osRecvMesg(0x8005c288)`**.

**OJO con la discrepancia**: el decompile muestra el bucle en `0x8005c288`, pero el log runtime
(`/tmp/hh_run.log:68`) muestra thread 5 bloqueado en **`0x8005be40`** (cola distinta, count=1,
creada justo antes). La versión runtime es la autoritativa; Ghidra fusionó/limitó la función.

## 3. Trazas runtime de referencia (`/tmp/hh_run.log`, run headless ~30s)

Secuencia (recortada):
```
7  osCreateMesgQueue 0x8005bf30 (200)   ; cola principal
9  osCreateMesgQueue 0x800cd4d8 (1)
10 osSendMesg 0x800cd4d8
11 osSetEventMesg event=8 → 0x800cd4b0
12 osCreateThread id=0 entry=0x8002aea0 (dispatcher)
15 osRecvMesg 0x8005bf30 → BLOCK          ; dispatcher espera
17 osCreateThread id=5 entry=0x800011b0   ; game loop
23-32 osCreateMesgQueue 0x8005c268/0x8005c288/... (8×count8) ; FUN_80000460
33-35 osCreateMesgQueue 0x800ce920 (5); osSetEventMesg 7/3 → 0x800ce920
36-40 osCreateThread VI manager 0x80034840; recv 0x800ce920 → BLOCK
41-44 osSetEventMesg 4/9/14/12 → 0x8005c598/5d0/560/560
45-64 osCreateThread RSP 19/18/17/16 (0x80000774/0x80000a5c/0x80000bf0/0x80000dc8)
65-66 osCreateMesgQueue 0x8005bec8(1); osSetEventMesg event=5 → 0x8005bec8
67   osCreateMesgQueue 0x8005be40 (1)
68   osRecvMesg 0x8005be40 → BLOCK (thread=5)   ; ← AQUÍ SE BLOQUEA
70+  [EV] VI retrace fire but mq=NULLPTR  (repetido)
```
- **Cola principal `0x8005bf30`: 0 mensajes** → el dispatcher nunca recibe la primera tarea.
- **Tareas RSP/gfx: 0** (`submit_rsp_task`/`send_dl` = 0).

## 4. Diagnóstico (cadena del deadlock)

1. Thread 5 crea `0x8005be40` (count=1) y espera el **primer mensaje** en ella, ANTES del bucle.
2. La VI vblank llega al VI manager (fix de la sesión anterior funciona).
3. El VI manager reenvía la vblank con `osSendMesg([structVI+0x10], [structVI+0x14])`. En el
   recompilado **`[structVI+0x10]` (cola destino) es NULL** → no reenvía → thread 5 nunca despierta.
4. El juego registró el reenvío vía **osViSetEvent** (`FUN_800329f0` desde `FUN_80000460:1054`)
   con mq = `0x8005c4b0+0xB0 = 0x8005c560` — **NO coincide** con `0x8005be40`.
5. No hay ninguna tarea RSP enviada (0 RSP tasks) → nada alimenta `0x8005be40` ni `0x8005bf30`.

**Coherencia con el TODO #7 conocido**: integración del modelo de threads (el libultra del juego
compilado como C choca con los os funcs reimplementados del runtime). La causa última apunta a que
el reenvío VI→game-loop no se materializa y/o la primera tarea RSP no se envía.

## 4.5 CAUSA RAÍZ CONFIRMADA (instrumentación runtime + dump)

**`osCreateViManager_recomp` es un stub no-op** (`lib/N64ModernRuntime/librecomp/src/vi.cpp:13`):
```cpp
extern "C" void osCreateViManager_recomp(uint8_t* rdram, recomp_context* ctx) {
    ;
}
```

El juego compila su libultra como código recompilado; su VI manager (`FUN_80034840`) lee los
globals del juego `0x8004aed0`/`0x8004aed4` (punteros cur/next del doble-buffer VI) para reenviar
la vblank a la cola del game loop. Esos globals los inicializa `osCreateViManager` (`FUN_80032220`),
que el recompilador **enlaza al stub no-op del runtime**. Resultado: los dos punteros quedan a `0`.

- Dump runtime confirmado: `[GVI] curVI_ptr=0x00000000 nextVI_ptr=0x00000000`.
- El VI manager del juego no puede reenviar la vblank → thread 5 bloqueado en `0x8005be40`.
- Coincide con el **TODO #7**: el runtime stubea funciones del libultra del juego, rompiendo el
  modelo de threads/estado del juego. La mezcla "VI manager del juego (recompilado) + osCreateViManager
  del runtime (no-op)" es incoherente.

**Fix (decisión B del TODO #7):** que el juego use SU propio `osCreateViManager` (recompilado
`FUN_80032220`), no el stub del runtime. Revisar también los demás os funcs VI que puedan estar
stubeados (`osViSetMode`, `osViSwapBuffer`, etc.) si rompen el estado del juego.

## 4.6 FIX APLICADO Y VERIFICADO (2026-09-10) — DEADLOCK ROTO

Cambios en `config/us_unified.syms.toml`:
- `osCreateViManager` → `FUN_80032220` (0x80032220, size 0x13C).
- `osViSetMode` → `FUN_80032360` (0x80032360, size 0x370).
- Añadido `osVirtualToPhysical` (0x80028A10, size 0x7C) — dependencia de osViSetMode como game code.

Regenerado `config/RecompiledFuncs_unified/` (341 funcs, funcs_0..6) + copiado a
`port/HybridHeavenRecomp/RecompiledFuncs/` + build OK + run headless:

- **DEADLOCK ROTO.** Confirmado en `/tmp/hh_run7.log`:
  - Thread 5 pasó de `0x8005be40` y corre su bucle (`osSendMesg mq=0x8005c288 msg=0x8005c4b0`).
  - VI manager reenvía la vblank a thread 19 (`osSendMesg mq=0x8005c560 msg=0x29a`).
  - Los punteros VI swap por frame (`vis=100/200/300/400` → cur alterna 0x8004AEA0/0x8004AE70).
  - `[GVI] curVI+0x10 mq=0x8005C560` y `nxtVI+0x10 mq=0x8005C560` (VI event registrado).
- **Resto (secundario):** crash `terminate called without an active exception` (race conocido de
  la sesión anterior; no bloqueante). Aún no se ve `submit_rsp_task` (sin tarea RSP/gfx todavía).

Los stubs `osCreateViManager_recomp`/`osViSetMode_recomp` del runtime (vi.cpp) quedan sin uso para
el juego; el recompilador ahora emite los del juego. RT64 usa `set_dummy_vi` cuando el juego no ha
arrancado, así que el render no depende de esos stubs en el boot.

**Trazas añadidas al runtime para el diagnóstico** (en `events.cpp`/`mesgqueue.cpp`):
- `[VIEV] osViSetEvent mq=...` (events.cpp) — nunca se imprime → el juego usa su propio osViSetEvent.
- `[SPT] submit_rsp_task type=...` (events.cpp) — nunca se imprime → 0 tareas RSP.
- `[MQ] osCreateMesgQueue ... caller0=... caller1=...` (mesgqueue.cpp).
- `[GVI] curVI_ptr=... nextVI_ptr=...` (events.cpp, dump 1 vez) — confirmó los punteros a 0.

## 5. Próximo paso (decidido): instrumentar el runtime

Añadir trazas al runtime (repo N64ModernRuntime, `ultramodern/src/`) y re-ejecutar el build de
Linux headless (Xvfb + lavapipe, receta en `notes/2026-09-10-session-vi-mesg-fix.md` §4):

- `osViSetEvent` (events.cpp) → log mq/msg/retrace (¿con qué cola se llama?).
- `osCreateMesgQueue` (mesgqueue.cpp) → log caller para identificar quién crea `0x8005be40`.
- `submit_rsp_task`/emisión de tareas → log si alguna tarea RSP/gfx se envía y a qué cola.

Objetivo: ver en runtime quién debe enviar el primer mensaje a `0x8005be40` y por qué no llega.
Con eso se decide el fix (runtime vs syms vs mapeo os func).

## 6. Notas de método

- **Ghidra cachea la compilación de scripts** → `ClassNotFoundException` intermitente. Solución:
  renombrar la clase/archivo (p.ej. `X` final) o borrar
  `~/.config/ghidra/.../osgi/compiled-bundles/*/` (ver `MainThreadX.class`).
- Los scripts usados en esta sesión: `TraceSched, FindCallersX, MainThreadX, EmisorX, GameLoopX,
  InitX, EventX, ViMgrX, ViEvtX, ViSetX, ViDumpX, ViScanX, FindVSetX, VSet2X, Vi460X`.
- El byte-matching de Goemon **no** encontró osViSetEvent (los offsets del struct VI difieren entre
  juegos; el matcher no enmascara LUI/ADDIU de globals). Se localizó por **escaneo de refs al struct
  VI** (`FUN_800329f0` escribe `0x8004aeb0/0x8004aeb4`).
