# 2026-09-11 — A3: wiring de render + generalización multi-módulo + jump-tables

> Evidencia de sesión. No editar. Continúa `2026-09-11-b9-integracion-modulo.md`.

## Objetivo

A3: enganchar el sistema de eventos / routing RSP / `loadUCodeGBI` para que el juego envíe
tareas de **display** y RT64 dibuje (primera imagen).

## Hallazgo 1 — el wiring de render YA estaba operativo

Volcado de RDRAM/boot (Linux, `hh.log`): se confirma que `osSetEventMesg` (SP/DP/SI/VI/…) y
`osViSetEvent` se registran, `submit_rsp_task` enruta los `M_GFXTASK` (type 1) a la action queue
del gfx thread, y `RT64Context::send_dl` llama a `loadUCodeGBI` + `processDisplayLists`. **RT64
procesa display lists**. El bloqueante no era el wiring.

Conteo de tasks tras el boot: solo **3 type=1** (gfx) y miles **type=2** (audio, no-op). Las 3 DL
son de **clear/fill** (`G_SETCIMG`/`G_FILLRECT`/`G_ENDDL`, `data_size=0x90`), **sin geometría**.

## Hallazgo 2 — el boot carga 5 assets `trans`; 3 son módulos de código

Instrumentando `FUN_80003824` (descompresor; args: `a0=src`, `a1=dest`, `a2=compressed_size`) con
gdb, el boot carga (bases idénticas en 3 runs):

| Nisitenma idx | ROM src | base RAM | decomp size | CRC32 | ¿código? |
|---|---|---|---|---|---|
| 0  | 0x4E5F40 | 0x800F41C0 | 4096 | 0xB774F2DD | no (ceros) |
| 7  | 0x4E69A8 | 0x80107830 | 564464 | 0xA9213032 | **sí** (ya integrado) |
| 23 | 0x5F1190 | 0x801BF1A0 | 68432 | 0x17AE0EEF | **sí** |
| 54 | 0x68BF26 | 0x803837E0 | 42464 | 0x486A3F0F | **sí** |
| 114| 0x6E82C6 | 0x801FA948 | 864 | 0x59CE4118 | no (paleta/datos) |

Los 3 módulos de código están **disjuntos** en RAM. El salto del boot es al **idx 7**; éste carga
el **idx 54** (callback en base+0x1C0) y el **idx 23** (callback en base+0x1DD0, dirección
`0x801C0F70`). Cómo medir una base nueva: `break FUN_80003824` → `ctx->r4/r5/r6` (src/dest/size), o
el directorio `trans` en `0x8008DFC0`.

## Hallazgo 3 — los switch/jump-tables del módulo 7 quedaban vacíos

`switch_error` en `FUN_8012FEA0` → `exit(1)` → `~std::thread` joinable → `terminate`. Causa: el
generador de syms (heurística `jr $ra`+8 = nueva función) **sobre-parte** las funciones con
`switch` (cada `case` acaba en `jr $ra`). N64Recomp exige que **todas** las entradas de la tabla
caigan dentro de la función que contiene el `jr` (`analysis.cpp`, `jtbl_word < func.vram || >= end`
→ table vacía → `default: switch_error`).

### Fix: `gen_module_syms.py` consciente de jump-tables
- Detecta tablas por el patrón `lui/addu/lw/jr $reg` y lee entradas **acotadas por la siguiente
  tabla** (igual que N64Recomp), no hasta la primera inválida (eso absorbía casos de funciones
  contiguas compartidas, p.ej. las tablas 0x8018D5A8/D5C4/D5E0 del state machine de 0x8012FBCC).
- Fusiona la función de dispatch con las funciones que contienen cada `case` (y con la anterior si
  ramifica hacia el rango). Verificación: **46/46 tablas con todos los targets dentro**. La función
  reaparece (no se absorbe) si es un destino de `jal` real (p.ej. `0x8012FE50`).

## Hallazgo 4 — bug del pipeline: funcs_*.c obsoletos

`recomp.py` copiaba los `funcs_*.c` al port sin borrar los previos. Al bajar el número de ficheros
(36→34), quedaron viejos y hubo **multiple definition**. Fix: borrar `RecompiledFuncs/funcs_*.c`
antes de copiar.

## Completitud de símbolos (evidencia runtime)

Con `HH_SOFT_LOOKUP=1` se añadieron a la syms plana 4 funciones: `0x8001B0B0`, `0x8001DF40`,
`0x8001F6FC` (reales) y `0x801C0F70` (era del módulo idx 23; al integrarlo, `overlaps_module` la
excluye de `.text`).

## Resultado

Con los 3 módulos integrados (secciones `.module7`, `.module23`, `.module54`) + jump-tables
fusionadas:
- **0 funciones faltantes**, **0 `switch_error`**, **0 `do_break`**.
- El juego ejecuta el game loop a ~60 fps de VI (audio no-op cada frame).
- RT64 sigue recibiendo solo las 3 DL iniciales de fill/clear.

## Bloqueante siguiente (nuevo)

El juego ejecuta su game loop (`FUN_80001454` → `FUN_80005270` dispatcher de callbacks) pero **no
envía display lists con geometría**. Las 3 DL son solo `G_SETCIMG`/`G_SETFILLCOLOR`/`G_FILLRECT`/
`G_ENDDL` (bucle de clear), sin `G_VTX`/`G_TRI`/`G_DL`. La causa es de **lógica de estado del
juego** (no de símbolos, módulos ni wiring).

### Crash tardío (SIGSEGV)
A los ~10–40 s el hilo del game loop **cae en `FUN_80001454`** (`funcs_0.c:4267`,
`ctx->r13 = MEM_W(ctx->r13, 0x7764)` → lectura de `0x80037764`). Es **reproducible en ejecución
normal** (2/2) pero **no bajo gdb** (timing). El crash handler da el stack pero sin símbolos
(`dladdr` no resuelve el ejecutable principal; falta `-rdynamic`). Hipótesis: estado de juego
corrupto por una función del módulo mal delimitada, o carrera en el runtime (lock single-CPU).

Hipótesis a explorar (por orden): (a) gate de render no satisfecho (audio real, timing de retrace,
Expansion/Controller Pak, o estado no inicializado); (b) instrumentar/`-rdynamic` el crash handler
para localizar la corrupción; (c) watchpoint sobre `0x80037764`.

## A3b — El juego está atascado en la fase de arranque (no llega a dibujar)

Investigación (2026-09-11, continuación).

### Gfx tasks: quién las envía
Las 3 tareas gfx salen de **thread 3** (`FUN_8001fba8`, scheduler) → `osSendMesg(mq=0x8005C4F0,
msg=<OSTask>)` → **thread 17** (`FUN_80000bf0`) → `osSpTaskLoad` + `osSpTaskStartGo`. Tras 3, el
scheduler no vuelve a encolar ninguna gfx (solo audio).

### El game loop es una máquina de estados gated por una "fase"
`FUN_80001454` (thread 5) es un dispatcher de estados sobre:
- `0x80037730` (estado A), `0x80037738` (estado B), ambos **0**.
- **`0x80037750` (u16) = "fase"/progreso de carga, siempre 0.**
El estado A (L_800014C4) y el estado B (L_80001678) solo arrancan si `0x80037750` vale 1/2, así que
el juego **nunca sale de la fase 0** y nunca crea el objeto de render: la raíz `0x80037350` (leída
por el handler de VI `FUN_80000774`) permanece 0 → sin render.

### Quién debería avanzar la fase
La fase la incrementan funciones del **módulo 23**: `FUN_801c5378` (lee/inc `0x801CFD0E`) y
`FUN_801cbe88`/`FUN_801cbe90` (estado de progreso en `0x801CFE00`/`0x801CFE02`, avanza a 0x97).
**Ninguna de esas funciones se ejecuta**: no se encontraron llamadas `jal`/`branch`/puntero de datos
hacia ellas en módulo 7/23/54 ni en el código plano. El arranque avanza cambiando el callback
`desc+0x1C` que consume `FUN_80005270`: se observó pasar por `0x80107830`, `0x80107864`, …
(funciones de módulo 7), pero **no progresa a las funciones del módulo 23**.

### Conclusión de A3b
El bloqueante no es el renderer: es la **secuencia de arranque/carga**. La fase (`0x80037750`) no se
avanza porque el dispatcher de arranque (`FUN_80005270` vía descriptor, o el scheduler `FUN_8001fba8`)
no invoca los pasos del módulo 23. Sospechas (por orden):
1. **Audio no-op**: el driver de sonido KCEO podría ser requisito de arranque (el juego no registra
   evento AI y las tareas de audio se completan como dummy). 
2. **Carga de assets (PI/`trans`)**: un paso de carga pendiente que no completa, o un puntero de
   callback que debería escribir el módulo 23 y no se ejecuta.
3. **Corrupción**: el campo `desc+0x1C` (`0x801BF1CC`) llegó a leerse como `0x3C01801D` (¡una
   instrucción!) en un run, lo que apunta a que algo escribe código/datos sobre el descriptor.

### Herramientas/diagnóstico disponible
- Enviar input por XTest (libXtst) no cambia nada (no es espera de botón).
- `[RND]` en `ultramodern/src/events.cpp` imprime estado por VI (útil; valorar extender con
  `0x80037750`, `0x801BF1CC`, `0x801CFE00/02`).
- Siguiente paso recomendado: **oráculo con emulador** (mupen64plus instrumentado en `work/`) para
  comparar `0x80037750`/`0x80037350` y el flujo de arranque, o localizar el escritor del callback
  `desc+0x1C` con watchpoint.

## A3b-2 — Oráculo con emulador: divergencia medida

Montado el oráculo (`work/r64dump`, ver `../docs/workflows.md` §6). Convención de lectura RDRAM:
**word-swapped** (`u16` va con `^2`, `u8` con `^3` — ver §6).

Estado del **emulador** (ROM real, dumps a 5/10/20/40 s):

| t | `0x80037730` | `0x80037750` | `0x801CFE00` | `0x801CFE02` | `0x80037350` |
|---|---|---|---|---|---|
| 5 s  | 0 | 0 | 0     | 0 | 0 |
| 10 s | 0 | 0 | 0     | 1 | 0 |
| 20 s | 0 | 0 | 0     | 3 | 0 |
| 40 s | **1** | **1** | 0x1C5 | **4** | 0 |

Estado del **port** (dump RDRAM tras el boot): `0x80037730=0`, `0x80037750=0`, `0x801CFE00=0`,
`0x801CFE02=0`, `0x80037350=0`, `desc+0x1C=0x803839DC` → **idéntico al emulador a t≈5 s, pero no
avanza**.

### Interpretación
- La fase (`0x80037750`) se desbloquea cuando `0x801CFE02==4` (lo comprueba `FUN_801cbe90`, módulo
  23) y `0x801CFE00` (contador de progreso) avanza hasta 0x97.
- `0x801CFE00/02` **no lo escribe la CPU** (el watchpoint en `0x801CFE00` solo capturó un
  `memset`/`bzero` de `FUN_8001f160`, que ambos ejecutan). Por tanto la carga que rellena ese buffer
  es un **DMA** (PI/RSP). En el port ese DMA no ocurre → el buffer queda a 0 → la fase nunca avanza.
- El directorio `trans` del emulador a 5 s ya tiene 4 entradas (`0x801FA948`, `0x8020B5C8`,
  `0x8020B938`, `0x802117F8`); el del port tiene menos → **el loader del port va por detrás**.

### Siguiente paso
Localizar el **DMA/paso de carga** que rellena `0x801CFE00` y por qué el port no lo ejecuta. Candidatos:
`osEPiStartDma`/PI manager, o el propio loader `trans` (variantes LZSS 5/7), o una cola de eventos que
no se dispara. El oráculo permite comparar el directorio `trans` y el buffer en cada instante.

**Pista (debug_printf de PI habilitado temporalmente)**: el port solo ejecuta **1 `[pi] DMA`**
(`from 0xB04E69A8 into 0x80089518 size 0x2000`, la carga del módulo 7). Las otras cargas
(idx 0/23/54/114) **no pasan por `osEPiStartDma`/`osPiStartDma`** → el juego lee la ROM por otra vía
(PIO `osEPiReadIo`? otro camino) o esas cargas usan el buffer sin DMA. Comparar con el emulador qué
fuente escribe `0x801CFE00` (watchpoint de CPU no lo captura → DMA/RSP en el emulador).

### Corrección: el loader SÍ lee la ROM (166 DMAs)
El "1 DMA" era un artefacto del **buffering de stdout** (el `debug_printf` no se vacía al matar por
`timeout`). Contando con gdb (`break osEPiStartDma_recomp`): **166 llamadas**, todas con
`dram=0x80089518 size=0x2000 mq=0x8005C268` (lectura en chunks de 0x2000 del ROM). Es decir, el
loader del port **sí hace las lecturas**; el problema está después, en la lógica que avanza la fase.

### Confirmado: las funciones de avance de fase del módulo 23 NO se ejecutan
Con gdb (`break FUN_801c5378`, `FUN_801cbe88`, `FUN_801cbe90`), en 35 s de ejecución: **0 llamadas**.
Son las que incrementan `0x80037750`. El emulador sí las ejecuta (la fase pasa a 1 a ~40 s). El
dispatcher que las invoca (puntero de función en runtime, no hay `jal`/tabla estática) no las alcanza
en el port. `desc+0x1C` (callback que consume `FUN_80005270`) evoluciona por funciones del módulo 7
(`0x80107830`, `0x80107864`, …) y llega a `0x3C01801D` (¡una instrucción `lui $at,0x801D`!) en **ambos**
(emulador y port), así que ese valor es normal, no corrupción.

**Siguiente paso (A3c)**: localizar en el emulador el llamador de `FUN_801c5378`/`FUN_801cbe90`
(puntero de función) y por qué el dispatcher del port no lo invoca. Ojo: las **bases de módulos del
emulador difieren** de las del port (heap distinto: emu `0x801FA948/0x8020B5C8/…` vs port
`0x80107830/0x801BF1A0/0x803837E0`), así que no se puede comparar módulo-a-módulo por dirección; sí el
código plano y el BSS (`0x80037750`, etc.).

### A3d — Divergencia localizada: callback de una tarea de arranque

**Corrección**: las bases de módulo **sí coinciden** (buscando la firma del blob en la RDRAM del
emulador: module7 en `0x80107830`, module23 en `0x801BF1A0`). La discrepancia previa era del
directorio `trans` (que lista otros módulos). Por tanto **sí** se puede comparar módulo a módulo.

Con gdb/oráculo:
- El emulador ejecuta `FUN_801cbe88` **cada frame** desde t≈8 s (`HB_EXEC=0x801CBE88`) y escribe la
  fase en `0x801CBFE4` (dentro de `FUN_801cbe90`) a t≈31 s. El port **nunca** las llama.
- El port y el emulador difieren en la **tarea/descriptor `0x801D03C0`**:
  | campo | emulador | port |
  |---|---|---|
  | `+0x00` | `0x00000000` | `0x8012E584` |
  | `+0x18` | `0x801D67DC` | `0x8012E654` |
  | `+0x1C` (callback) | **`0x801CBE88`** | **`0x801C1034`** |
- El escritor del callback se identificó con watchpoint (`HB_RES_DIR=0x801D03DC HB_WP_SIZE=4`):
  `0x80005BBC` = **`FUN_80005b98`**, que copia `src+0x0C → task+0x1C`. La `src` la devuelve
  **`FUN_800059b0`** (asignador de pool de tareas con cabecera en `0x800892B0+0xAC`, lookup por id en
  `0x80089378`), llamada desde **`FUN_80005624`** (`a1 = [task+4]` = id). La definición de tarea debe
  contener el callback en `+0x0C`.

**Siguiente paso (A3e)**: rastrear de dónde sale la definición (id → callback) y por qué el port
asigna `0x801C1034` (módulo 23, offset `+0x1E94`) en vez de `0x801CBE88` (`+0xCCE8`). Ambos son código
del módulo 23 → apunta a la **tabla de definiciones de tareas** (probablemente datos del módulo) o a
un estado distinto en el arranque.

### A3e — El bootstrap es idéntico hasta el buffer de tarea `0x8005BDB4`

- **El port SÍ ejecuta la secuencia de arranque** (`FUN_800011b0`): carga Nisitenma idx
  `0/1/3/4/6/7/23/54/114` vía `FUN_8000469c(a0 = idx+1, dest)` y llama a `FUN_8001f204` /
  `FUN_80005624` / `FUN_80133aac`. Las **tareas del bootstrap coinciden** con el emulador (mismo `+0xC`
  en `0x80162DD0/FC0/4E30/4E6C/4E58`, `0x8038DC70/84`).
- El descriptor `0x801D03C0` se rellena con `FUN_80005b98` copiando de la **fuente `0x8005BDB4`**
  (`src+0x8=0x8012E584`, `src+0xC=0x801C0F70`, `src+0x10=0x8012E654` en el port). En el emulador el
  mismo descriptor acaba con `+0x1C=0x801CBE88`.
- `0x8005BDB4` es un **buffer scratch compartido** (lo escriben ~30 PCs distintos durante el boot; en
  ROM su contenido es basura). El port y el emulador lo rellenan con contenido distinto justo antes de
  copiarlo → la divergencia es **anterior** (estado de un paso previo).
- `FUN_801c0f70` (callback del port) es un paso de init que fija `+0x1C = 0x801C0F98` vía
  `FUN_800058dc`; `FUN_801cbe88` (emu) es la rutina real de avance de fase → el port se queda en un
  **estado de init anterior**.

**Conclusión y siguiente paso (A3f)**: el bootstrap es correcto hasta cierto punto y luego diverge el
contenido de un buffer scratch. Hace falta un **diff sistemático de RDRAM port vs emulador alineado por
un contador estable** para hallar la **primera** dirección que difiere. Herramientas listas: `r64dump`
(volcados por tiempo + watchpoints exactos) y `dump binary memory` de gdb en el port. **No seguir a mano**
(cada capa retrocede).


### A3f — Diff alineado port↔emulador (herramienta + resultado)

Herramienta: `r64dump` ahora soporta **volcado one-shot disparado por watchpoint** (`HB_DUMP_ON_WP`)
+ `HB_WP_SIZE`; el port vuelca con `dump binary memory` de gdb en el mismo evento. Alineado en la
escritura del callback (`0x801D03DC` / copia a dest `0x801D03C0`) y comparando RDRAM (ver
`../docs/workflows.md` §6.1).

**Resultado**:
- **Módulos 7/23/54: 0 diferencias** (decompresión/carga OK). Tablas que consume el bootstrap
  (`0x80038FE0`, `0x80037C5C`, `0x80089378`) idénticas.
- Diferencias totales: 654k palabras, casi todas en **estado mutado** (BSS/heap/pilas) y en
  `0x80000000-0x80000400` (vectores de excepción: el emulador los carga, el port no — es inocuo).
- Primeros bloques de estado divergentes: `0x80044084`, `0x80047950` (emu=1 / port=0x1AE),
  `0x80049930+` (estructuras de hilo), `0x8005CD80` (OSIoMesg del DMA).
- El callback divergente (`0x801C0F70` port) lo fija `FUN_80126198` (módulo 7) →
  `FUN_8012C4D0`, desde el buffer scratch `0x8005BDB4`. En el emulador ese buffer lo escriben
  decenas de PCs (es compartido), así que no se aísla por escritor.

**Conclusión**: la divergencia no es de recompilación/carga (código idéntico) sino de **estado
mutado durante el arranque**. El diff puntual es ruidoso; el siguiente refinamiento es una
**traza de writes ordenada** (port y emulador) y comparar la primera escritura que difiere. En el
port se puede instrumentar el runtime o usar `record`/watchpoints por fases.

### A3g — El valor divergente sale de una selección de handler por índice de objeto

Watchpoint hardware sobre `0x8005BDB4+0xC` en el port → la escritura del callback la hace
`FUN_80126198` (módulo 7, `+807`): lee `t2 = tabla[0x801760C0][[s0+0x20]-1]` (tabla de punteros a
descriptores) y copia `t2+0xC` (el callback) al buffer. El descriptor seleccionado en el port es
`0x801CC844` (callback `0x801C0F70`); en el emulador es otro descriptor (callback `0x801CBE88`).

Es decir, **la divergencia es el índice de handler del objeto `s0`** (`[s0+0x20]`), fijado por estado
anterior. Patrón confirmado: código/datos idénticos; lo que diverge es **estado de un objeto** en el
arranque. En el emulador este objeto se procesa con otro descriptor.

**Vía para A3h**: (a) traza de writes ordenada para hallar la primera escritura divergente; o
(b) identificar quién fija `[s0+0x20]` y comparar ese valor/estado. Nota: `s0` llega desde
`FUN_801262d4` ← `FUN_801243dc` (módulo 7), y el estado podría depender de una tarea RSP (audio/gfx)
que el port no ejecuta (audio no-op) — sigue viva la hipótesis del audio.

### A3h — Vía al write-trace: la divergencia es de *selección*, no de datos

- El objeto activo del port es `s0 = 0x801734F0` (datos del **módulo 7**); el del emulador es
  `0x80173530`. **Ambos slots existen en ambos y su contenido es idéntico** (comparado en el volcado
  alineado). Es decir, no es un dato corrupto: es **qué objeto/slot está activo**.
- `FUN_80126198` selecciona el descriptor de handler por `[s0+0x20]` desde la tabla de punteros
  `0x801760C0`; el port selecciona el descriptor `0x801CC844` (callback `0x801C0F70`) y el emulador
  otro (callback `0x801CBE88`).
- Conclusión: el estado diverge en **qué objeto del pool se activa**, no en su contenido. Encontrar la
  primera escritura divergente requiere una **traza de writes simétrica** (port y emulador) o
  identificar quién activa el objeto. Herramienta de alineación ya lista (`r64dump` + `HB_DUMP_ON_WP`).

## Escalón 1 (A3h→ mensajería): confirmado el runtime/scheduling

**Fix del oráculo (importante)**: `r4300_regs()` devuelve `int64_t[32]`; el frontend leía
`DebugGetCPUDataPtr(M64P_CPU_REG_REG)` como `uint32_t*` → **leía registros equivocados** (a0=0 casi
siempre). Corregido a `int64_t*`: ahora los exec-breakpoints dan a0/a1/a2 correctos. Añadido
`HB_TRACE_EXEC=a,b,c` (varios exec-breakpoints) y bajado el `usleep` de sondeo (100 ms→100 µs) para
que el emulador no se arrastre.

**Traza de mensajería port↔emulador** (port: `[SEND]` en `do_send` + `[MQ]` recv; emulador:
`osSendMesg`/`osRecvMesg` a `0x80026300`/`0x800266B0`):
- Las secuencias **divergen en el primer evento**. Pero la diferencia es **mensajería interna del
  runtime**: el emulador arranca con un handshake de gestor (`S/R` en `0x800CD4D8`, `0x800CE920`,
  `0x8005BF30`) que el port implementa por otra vía (crea hilos/eventos con su propio mecanismo).
- **Orden de arranque de hilos distinto**: el port hace que el **hilo VI (thread 19) espere primero**
  (`R 8005C560`); el emulador hace **mensajería de gestor antes** de que el hilo VI espere.
- Es decir: código de juego idéntico, pero el **runtime entrega/ordena eventos y arranca hilos de
  forma distinta** al original.

**Conclusión**: raíz en el **runtime** (scheduling/arranque de hilos y entrega de eventos), no en la
lógica del juego ni en la recompilación. Siguiente: alinear el arranque/entrega del port con el orden
del emulador (comparar con upstream N64ModernRuntime y con los parches del port: `run_next_thread_and_wait`,
lock single-CPU, `wait_for_external_message`).

## Escalón 2: el port nunca avanza el progreso de carga (medido)

Pruebas de parches del runtime (escalón 2):
- Revertir `check_running_queue` de `>=` a `>` (upstream): **sin cambio** (fase 0).
- Quitar el idle `run_next_thread_and_wait` (procesar mensajes externos si no hay hilos): **sin
  cambio** (fase 0, sin abortar). Se restauran ambos parches (el `>=` era deliberado, commit `2b118e5`).

**Medición decisiva** (contador VI añadido al oráculo):
- El emulador avanza la fase (`0x80037750`→1) a **VIS≈1857, t≈31 s** → corre a **60 fps reales**.
- El port llega a **VIS 5400 (90 s) con fase 0** → **divergencia real**, no lentitud.
- El port **nunca** escribe `0x801CFE00/02` (progreso de carga) ni `0x801D1E00` (contador): todo 0;
  el emulador los lleva a `CFE00=0x1C5`, `CFE02=4`, `1D1E00=0x97`. La fase exige `CFE02==4` y
  `1D1E00>=0x97` (en `FUN_801cbe90`, módulo 23).

**Quién avanza `CFE00/02`**: `FUN_8000469c` (sí se ejecuta) + `FUN_801cbdc0`/`FUN_801cbe90`/
`FUN_801cc574`/`FUN_801cc748` (módulo 23, **no** se ejecutan en el port). `FUN_801cbdc0` está
referenciado como puntero en un **descriptor estático del módulo 23** (`0x801CE65C`, callback en
`+0x08`), procesado por el bucle de objetos/descriptores del juego. El port arranca ese bucle con el
**objeto/estado equivocado** (ya visto en A3d–A3h) → no invoca esos callbacks.

**Conclusión**: código/datos idénticos; el fallo es que el **bucle de objetos del juego no procesa el
descriptor del módulo 23** (estado de arranque divergente). Siguiente: rastrear la **activación del
descriptor de módulo 23** (`0x801CE65C`) y por qué no entra en el bucle.

## Escalón 3: el state machine de arranque del port toma otro camino

Con los registros ya correctos en el oráculo (`ra` fiable), el caller de `FUN_801cbdc0` en el
**emulador** es **`FUN_80005270`** (dispatcher de descriptores) desde `ra=0x8000535C` (campo `+0x1C`),
con `a0 = 0x801D03C0` (la tarea de arranque). Es un **paso del state machine**; en el emulador evoluciona
`... → 0x801CBDC0 (VIS≈491) → 0x801CBE88 (VIS≈600) → ...` y va avanzando el progreso de carga.

En el **port**:
- `FUN_801c0f70` (callback de su tarea) se llama **1 vez**; `FUN_801c0f98` (el siguiente paso que
  él fija) también **1 vez**; y después **no** se invocan los pasos que avanzan `CFE00/02`
  (`FUN_801cbdc0`…, 0 veces).
- Es decir, el state machine de la tarea de arranque **arranca pero se detiene** tras sus primeros
  pasos y no llega a los pasos de progreso de carga.

**Conclusión**: mismo patrón confirmado con `ra`: código/datos idénticos, pero el **state machine de
tareas de arranque del port toma/queda en un camino distinto** al del emulador. Para cerrar la causa
hace falta la **traza de control completa desde el arranque** (primera función/bloque divergente), que
con el oráculo ya corregido es factible. Es una herramienta dedicada (instrumentación de llamadas en
el port + exec-breakpoints selectivos en el emulador).

## Escalón 4: diff de RDRAM alineado por frame (VI) — primera divergencia de juego

Herramienta: volcado de RDRAM del port en VIs concretos (`HH_DUMP_VI`, temporal) y del emulador por
tiempo (`HH_DUMP_TIMES`, 60 fps → VI=N ⇒ t=N/60). Diff de la región plana (excluyendo pilas/colas).

Resultado (VI 60..720):
- Diferencias "base" ~4300 palabras hasta **VI 360** (mayormente pilas/estructuras de hilo del
  runtime, que difieren por implementación).
- Salto a ~12250 entre **VI 360 y 420**: de nuevo pilas/colas del runtime (`0x80059D80`,
  `0x8005BCxx`, `0x8005C288`…), no lógica de juego.
- **Primera divergencia de estado de juego a VI≈600**, excluyendo pilas:
  - **`0x801CFE00` = 0x100 (emu) vs 0 (port)** y `0x801CFE04 = 0xB4CE6666` (magic del loader) vs 0:
    el **progreso de carga no se rellena** en el port.
  - **`0x800CD790..0x800CD7E0`** (estructuras del **PI manager**, cola `0x800CD4D8`) pobladas en el
    emulador y a 0 en el port.
  - `0x800CE878` (módulo cargado), varias en `0x801BCxxx`/`0x801E0xxx` (BSS del juego).

**Interpretación**: el emulador ejecuta el **PI manager del juego** (`osCreatePiManager` +
`FUN_8002add0`/`FUN_8002ae64`, cola `0x800CD4D8`) que rellena esas estructuras y alimenta la carga;
el port **sustituye el PI manager por el runtime** (`osCreatePiManager_recomp`), así que esas
estructuras del juego quedan a 0 y el progreso de carga (`0x801CFE00`) no avanza → la fase de
arranque nunca se desbloquea. El código/datos siguen siendo idénticos; el hueco es de **emulación de
la ruta PI del juego**.

**Siguiente sugerencia**: revisar cómo el runtime implementa `osCreatePiManager`/`osEPiStartDma` vs lo
que el juego espera (estructuras `0x800CD7xx`, OSIoMesg/cola `0x800CD4D8`), y si el port debe ejecutar
el PI manager del juego o replicar sus efectos. Nota histórica relacionada: `2026-09-10-*` (DMA/PI).

## Escalón 5 — Ruta PI: hallazgos y límite del método manual

- `osCreatePiManager_recomp` (runtime) es un **stub vacío** → en el port **no existe el hilo del PI
  manager del juego**; el runtime hace los DMA de forma síncrona en `osEPiStartDma`/`osPiStartDma`.
- Las estructuras `0x800CD790..` las rellena en el emulador `FUN_80026fe8`, que resulta ser un
  **`memcpy` genérico** (`ld/sd` en bucle), llamado 720 veces: NO es el PI manager, es una copia (la
  fuente difiere). La búsqueda estática de `0x800CD790`/cola no da referencias directas (direcciones
  computadas), así que no se aísla por autor.
- Se confirma el patrón: **código/datos idénticos**, divergencia de **estado** que arranca en el
  **state machine de la tarea de boot** (callback de `0x801D03C0`) y se propaga al progreso de carga
  `0x801CFE00` (que llace el avance de fase). Cada capa remite a una anterior (objeto → handler →
  índice → estado), señal de que el problema es de **estado de arranque encadenado**, no de una
  función concreta mal recompilada.

**Conclusión de A3*:**
- El **renderer está integrado** (A3); la recompilación es **correcta** (código/datos idénticos al
  emulador, 0 faltantes).
- El bloqueo es de **estado de arranque dependiente del runtime** (PI/thread/eventos). La vía para
  cerrarlo no es más análisis manual sino una **traza de control desde el arranque** (primera
  función/bloque divergente) o **alinear la emulación PI/threading** con el original.
- El oráculo está afinado (regs int64, `HB_TRACE_EXEC`, `HB_DUMP_ON_WP`, `HB_DUMP_VI`) y documentado;
  es la herramienta para la siguiente fase.

## Fase herramienta: traza de control (port vs emulador) — hilos

Se construyó la traza de **llamadas** en ambos lados:
- **Port**: `get_function(addr)` es el punto único de toda llamada (`use_lookup_for_all_function_calls`);
  se instrumentó con `HH_CALLTRACE=<file>` (23M llamadas en 8 s).
- **Emulador**: se reconstruyó **mupen64plus-core** (`work/mupen-src`) con trazador de `jal`/`jalr`
  (`HH_JALTRACE=<file>`, `pure_interp.c`). Para compilar hizo falta `binutils-dev` + `nasm` y
  `make all OSD=0 VULKAN=0 DEBUGGER=1`; el core se copió a `work/libmupen64plus-debug.so`.

Comparación (filtrando libultra y alineando en la subsecuencia `FUN_80007b70…`, y filtrando las
entradas de hilo del port, que el emulador no registra):
- **Primera divergencia de juego**: tras `FUN_80000EC8`, el **port ejecuta `FUN_8001FEBC`** y el
  **emulador ejecuta `FUN_800021B4`** (función de hilo: crea cola y bloquea). Es decir, **los
  hilos se ejecutan en orden distinto** durante el arranque → confirma la raíz en el **scheduler de
  hilos del runtime** (no en lógica de juego ni recompilación).

**Conclusión de la fase**: con evidencia de ejecución (traza de control), el único punto que diverge
primero es **qué hilo corre cuándo**. El siguiente trabajo es **alinear el scheduler de hilos del
runtime** (con el lock single-CPU / `check_running_queue` / arranque de hilos) con el del N64.
Herramientas listas y documentadas.

## Scheduler: hallazgo de los hilos gestores (evidencia)

Comparando el orden de **creación/arranque de hilos** (exec-breakpoints en `osCreateThread`/`osStartThread`,
ahora con registros fiables):

| orden | emulador | port |
|---|---|---|
| 1 | Create id=1 entry=`0x80001124` | idem |
| 2 | Start id=1 | idem |
| 3 | **Create id=0 entry=`0x8002AEA0`** | **NO** |
| 4 | Start id=0 | **NO** |
| 5 | **Create id=0 entry=`0x80034840`** | **NO** |
| 6 | Create id=5 entry=`0x800011b0` | idem |
| | … 19,18,17,16,3 | idem |

- `0x8002AEA0` cae **dentro** de `FUN_8002ae64` (device manager, `__osDevMgrMain`-like) y `0x80034840`
  es otro gestor. Son los hilos de **`osCreateViManager`/`osCreatePiManager`**, que el runtime
  **stubea a vacío** (`vi.cpp:13`, `pi.cpp:60`). Con gdb se confirma que el port **no ejecuta**
  `FUN_8002ae64`/`FUN_80034840`/`FUN_8002add0`.
- Es decir: el port reemplaza los gestores VI/PI de libultra por el runtime, pero **el juego creó
  hilos gestores cuya lógica (device-manager) no corre en el port**. El primer punto de ejecución que
  diverge (control trace) es coherente con esto.

**Experimento propuesto (decisivo)**: dejar que el juego ejecute sus propias
`osCreateViManager`/`osCreatePiManager` (quitar de la symbol-list del recompilador) y ver si arranca
el device-manager del juego. Riesgo: interacción con el VI/PI del runtime; hay que aislar/ajustar.
Alternativa: comparar cómo Goemon64Recomp/Zelda64Recomp resuelven los gestores VI/PI (port de
referencia en `toolchain/src/`).

## (b) Comparación con upstream/Zelda/Goemon — gestores VI/PI

- Se comprobó que `toolchain/src/N64ModernRuntime` (upstream, la base de Zelda64Recomp/Goemon64Recomp)
  **también stubea** `osCreatePiManager_recomp` (`pi.cpp:60`) y `osCreateViManager_recomp`
  (`vi.cpp:13`) — de hecho los `pi.cpp`/`vi.cpp` del port son **idénticos** a upstream.
- **Conclusión**: que el port no cree los hilos gestores VI/PI (0x8002AEA0/0x80034840) es **normal**,
  no el bug. Se descarta el experimento (a) de un-stubear los gestores.
- Matiz: los submodules `lib/N64ModernRuntime` de Zelda64Recomp y Goemon64Recomp están **vacíos** en
  este entorno, así que no se pudo comparar su código exacto; sí la base upstream.
- Lo que **sí** es específico del port: parches de concurrencia/scheduling propios
  (`ultramodern/src/{threads,scheduling,mesgqueue,events}.cpp`, `ultramodern.hpp`, `overlays.cpp`) que
  upstream no tiene (lock single-CPU, `>=`, idle-on-external, sync `__osRunningThread`). Los dos que se
  probaron aislados (`>=` y el idle) no cambiaron el bloqueo, pero el **lock global** y el **sync de
  `__osRunningThread`** siguen sin comparar con un port funcional.

**Siguiente (retomar aquí)**: bisecar los parches de runtime del port contra upstream/Goemon (o
conseguir el `lib/N64ModernRuntime` de Goemon como referencia directa), probando si alguno altera el
orden de hilos. Herramientas listas (oráculo + traza de control).

## Bisecado de los parches de runtime (negativo) + estado

Se probaron, uno a uno, los parches de concurrencia del port (revirtiendo/neutralizando y midiendo
la fase `0x80037750`):
- `check_running_queue` `>=`→`>`: **sin cambio**.
- idle en `run_next_thread_and_wait` (upstream): **sin cambio**.
- sync de `__osRunningThread` (0x80049940) desactivado: **sin cambio**.
- lock global single-CPU desactivado (`HH_NOLOCK`): **sin cambio**.

→ **La raíz no son los parches de scheduling del runtime** (al menos no individualmente). El bloqueo
de arranque (fase 0 / `CFE02` sin avanzar) persiste igual.

### Conclusión de sesión
Tras A3 + escalones 1–5 + fase herramienta + (b) + bisecado:
- **Renderer integrado** y **recompilación correcta** (código/datos idénticos al emulador; 0
  faltantes; 0 `switch_error`; 0 `do_break`).
- El bloqueo es **estado de arranque**: la carga (`0x801CFE00/02`) no avanza porque el **state machine
  de tareas del juego** no procesa el descriptor del módulo 23 (`0x801CE65C` → `FUN_801cbdc0`).
- La traza de control muestra una divergencia **en un cambio de hilo** (`FUN_800021B4` en el emulador),
  pero está **confundida por artefactos** (el port registra entradas de hilo, el emulador no) y los
  parches de runtime no la explican.

### Siguiente paso recomendado (definitivo)
**Traza de control consciente de hilos**: registrar también las **entradas de hilo** en el emulador
(osStartThread → siguiente PC) para poder alinear 1:1 con el port, y hallar la **primera** diferencia
real (no un cambio de hilo). Herramientas listas: oráculo (`docs/workflows.md` §6/§6.1), trazador
`jal`/`jalr` en mupen (`HH_JALTRACE`) y `get_function` (`HH_CALLTRACE`) en el port.
Alternativa: obtener el `lib/N64ModernRuntime` de Goemon64Recomp como referencia directa.

## Traza consciente de hilos: WEAK POINT del boss encontrado

Se instrumentó el emulador para registrar también las **entradas de hilo** (`HH_THREAD_ENTRIES` en
`pure_interp.c`: cuando el PC entra en una entry de `osCreateThread`) y se re-comparó con el port.

Ahora **ambos registran la misma entrada** y la primera divergencia es real:

```
… 0x80001454 (game loop), 0x80001060, 0x80000ec8, 0x800021b4
   port: 0x8001febc
   emu : 0x80151bc4   (jal en FUN_800021B4 @0x80002260)
```

- `FUN_800021B4` lo llama el **game loop** (`FUN_80001454` @`0x80001948`) y **bloquea en
  `osRecvMesg` sobre `0x8005CE20`**, que es la **cola del evento SI (controller)**
  (`osSetEventMesg event=5` = `OS_EVENT_SI`). Es el **handler de controller/SI**.
- La rama que difiere (`bne $s1,$s2` en `0x80002258`, con `s1=s2=0x8005CE50`) y las llamadas
  (`0x80151BC4` módulo 7 vs `0x8001FEBC`) indican que el **flujo de mensajes/estado del SI**
  diverge entre port y emulador.

**Conclusión del boss**: la cadena arranca en el **manejo del evento SI (controller)** — el port
genera/entrega el mensaje SI de forma distinta al original — y de ahí se propaga el estado de
arranque hasta la fase. Siguiente: comparar la ruta **SI/controller** del port (eventos + callbacks de
input) con el emulador.

## Verificación posterior: la ruta SI NO es el bloqueo; el nodo de boot queda clavado

Se re-verificó el "weak point SI" y el state machine con el log `[RND]` ampliado
(`fe00/fe02` + nodo `0x801D03C0` + `0x80089478`) y el oráculo.

**1) La ruta SI/controller del port funciona** (la hipótesis anterior era prematura):
- El port llama `osRecvMesg(0x8005CE20)` (cola SI, `OS_EVENT_SI`) **cada frame y NO bloquea**
  (`[MQ] osRecvMesg mq=...8005ce20 flags=1` sin `BLOCK recv` a continuación).
- La divergencia de traza en `FUN_800021B4` (`0x8001FEBC` port vs `0x80151BC4` emu) es por **orden de
  hilo**, no por la ruta SI en sí. Se descarta como causa raíz.

**2) El gate de fase, confirmado en el emulador** (`HB_RES_DIR=0x80037750 HB_WP_SIZE=2`):
- La fase `0x80037750` la escribe `pc=0x801CBFE4` (`FUN_801cbe90`) a **t≈31 s**, sólo si
  **`0x801CFE02==4` y `0x801CFE00(u16)>=0x97`** (loop `L_801CC174`).
- Los contadores `0x801CFE00/02` los avanza `FUN_801cbe90` (+`FUN_801cc574`/`FUN_801cc748`) tras
  `FUN_801cbe88`, invocado por el dispatcher `FUN_80005270` con `a0=0x801D03C0`
  (`ra=0x8000535C`, campo callback `nodo+0x1C`), cada frame desde t≈8.2 s.

**3) En el port el nodo de boot queda clavado** (nuevo, evidencia por frame):
- `[RND] vis=60..2400 fe00=0x0000 fe02=0x00` (90 s) → el progreso de carga **nunca** arranca.
- Nodo `0x801D03C0`: en el port `+0x18=0x8012E584`, `+0x1C=0x801C1034` y ahí se queda
  (vis 540→2400); en el emulador `+0x18=0x0`, `+0x1C=0x801CBE88`. Con gdb, `FUN_801cbe88` y
  `FUN_801cbe90` **no se ejecutan nunca** en el port.

**Conclusión corregida**: el bloqueo NO es el SI ni los gestores VI/PI, sino el **state machine de la
tarea de arranque** (`nodo 0x801D03C0`): el port se queda con el callback `0x801C1034`
(`FUN_801c0f70`) y nunca pasa a `0x801CBE88`, así que `0x801CFE00/02` quedan a 0 y la fase no sube.
Siguiente: por qué el state machine que fija `nodo+0x1C` se detiene tras sus primeros pasos
(qué hace `FUN_801c0f70`/`FUN_801c0f98` y por qué no agenda el siguiente callback).

## Cadena de callbacks del nodo de boot (detalle)

El callback se fija con el setter `FUN_800058DC` (`sw a1,0x1C(a0)`); `FUN_801cbdc0` lo usa en
`0x801CBE38` (`lui 0x801D; addiu -0x4178` = `0x801CBE88`) + `jal 0x800058DC` en `0x801CBE6C`.

- **Emulador**: `node+0x1C` se escribe a t=7.35 (`0x8001F1A8`), y a t=8.20 por `FUN_801cbdc0`
  (`0x800058E0`, setter) y `FUN_80005b98` (`0x80005BBC`, copia) → queda `0x801CBE88`.
- **Port**: `node+0x1C = 0x801C1034`. `FUN_801c0f70` (size 0x28) hace `0x800058DC(a0, 0x801C0F98)`;
  `FUN_801c0f98` (size 0x9C) crea 4 objetos (`0x8001B204` con `0x801CE978/94/B0/CC`) y luego
  `0x800058DC(a0, 0x801C1034)`; y `FUN_801c1034` (size 0xC) es un **no-op** (`sw a0,0(sp); jr ra`).
  → el sub-chain se **auto-termina** y nunca llega a `FUN_801cbdc0`.

**Conclusión**: el nodo de boot del port recorre un sub-chain distinto (`FUN_801c0f70→…→FUN_801c1034`,
auto-terminante) en vez de `FUN_801cbdc0→FUN_801cbe88`. El punto de bifurcación está en **qué callback
se instala primero** en el nodo (dato/estado de arranque previo). Siguiente: rastrear el origen del
callback inicial del nodo (fuente `0x8005BDB4+0x0C` / primer escritor de `node+0x1C`) en port vs
emulador.

## Origen del callback: objeto de boot instanciado desde una estructura en 0x8005BDB4

Con breakpoint en `FUN_80005b98` (spawner/copier: `template+0x0C → object+0x1C`) en el port, el objeto
de boot `0x801D03C0` se instancia desde **`0x8005BDB4`**:

```
B98 r4=0x801D03C0 r5=0x8005BDB4
```

Contenido de `0x8005BDB4` en el volcado alineado (port VI540 vs emulador t=9.0):

| +off | port | emulador |
|---|---|---|
| 0x04 | `0xFF00FF00` | `0x4182FE3C` (float 16.37) |
| 0x08 | `0x00000000` | `0xC296B9B4` (float -75.36) |
| 0x0C | `0x00000000` | `0xC3373FDA` (float -183.25) |
| 0x10 | `0x00000000` | `0x3F800000` (float 1.0) |
| 0x14 | `0x0000E168` | `0x801F4578` (ptr) |

Parece un **descriptor de spawn de entidad** (posición/escala + puntero) construido en la pila/buffers
(`0x8005BDB4` cae en la zona de pilas que el diff histórico excluía). En el port está **a 0/basura** →
`FUN_80005b98` no rellena bien el objeto de boot y su `+0x1C` acaba en el sub-chain auto-terminante
`FUN_801c0f70→FUN_801c0f98→FUN_801c1034`, en vez de `FUN_801cbdc0→FUN_801cbe88`.

Nota: el port **no copia el código ROM a RDRAM** (`[0x80000000]=0`), a diferencia del emulador
(`0x3C1A8002`); el diff byte a byte de RDRAM completo no es válido (hay que excluir el código).

**Siguiente**: identificar el **llamante de `FUN_80005624`/`FUN_80005670`** que construye el descriptor
de `0x8005BDB4` (o el origen del dato) y por qué en el port queda a 0/basura.

## Posible causa raíz: datos estáticos del juego a 0 en el port (materialización)

Comparando volcados (port VI60/VI540 vs emulador t=9):

- `0x801CE65C` (descriptor estático del módulo 23, dentro de `FUN_801cc7dc`): emulador `+0x08=0x80000000`;
  **port todo 0**.
- `0x8005BDB4` (struct de spawn): emulador datos reales (`0x4182FE3C…`, ptr `0x801F4578`); port, a VI60,
  punteros runtime (`0x801BF1B0`, `0x8008D5D4`), no el mismo contenido.
- El port **no copia el código ROM a RDRAM** (`[0x80000000]=0` vs `0x3C1A8002`); el código está
  recompilado en un heap aparte, pero los **datos referenciados por puntero** deben materializarse en
  RDRAM (mecanismo `trans`/data de N64Recomp).

**Hipótesis**: el recompilador no está materializando ciertas **tablas de datos del módulo 23**
(p.ej. `0x801CE65C`) ni el struct en `0x8005BDB4`; el juego lee 0 y su state machine de boot toma el
camino equivocado (sub-chain auto-terminante). Hay que verificar la materialización de datos
(`trans`) del módulo 23 y del binario principal.

**Siguiente decisivo**: (a) revisar cómo N64Recomp emite `trans`/datos para direcciones referenciadas
por puntero (`lea`) y si faltan en `config/*.syms.toml`/data sections; (b) comparar RDRAM del port y
emulador en la zona de datos del juego **excluyendo el código** para localizar la primera tabla faltante.

## Verificación de la hipótesis de materialización → REFUTADA

Chequeo empírico (port VI540 vs emulador t=9s, volcado fresco):

- **No faltan datos**: la región del módulo 23 (`0x801BF1A0`, 64 KB) es **16384/16384 palabras
  idénticas** port↔emulador; `0x801CE65C` y `0x8005BDB4` inicialmente parecían distintos por leer
  direcciones desplazadas. La región del módulo 7 también 100%.
- `0x8005BDB4` está **dentro de `FUN_8005ba00`** (código); `rom[0x5BDB4]=1c8298ff…` (código), no floats
  → los floats (`0x4182FE3C…`) son un **struct escrito en runtime** por el juego, no un dato estático.
  En el port queda `0xFF00FF00…` (buffer sin construir).
- El port **sí** tiene los datos del binario/overlays; las diferencias grandes de página (`0x80401000`,
  `0x80501000`…) son el **heap del port** en regiones vacías del emulador, no datos faltantes.

**Conclusión**: NO es un problema de materialización de datos (`trans`/data). La recompilación y los
datos son correctos. La divergencia es de **estado runtime**: el juego construye un struct en
`0x8005BDB4` y lo pasa a `FUN_80005b98` para instanciar `0x801D03C0`; en el port ese struct no se
construye (camino de código anterior divergente), y el objeto acaba con los callbacks equivocados.
Queda el problema de **estado de arranque encadenado** (ya conocido), no de datos/recompilación.

## Cadena de spawn del objeto de boot (callers)

Con breakpoints en los spawners (port):

```
FUN_80005670(a0=0x801CFF88, a1=0x8005BDB4)   # instancia el objeto de boot
  <- FUN_800057dc (0x80005804, si manager+0xC!=0)
  <- FUN_80107968 / FUN_80108264 / FUN_8010E544... (módulo 7)
```

- `FUN_80005b98` copia `template+0x0C → objeto+0x1C`; `FUN_800057dc(manager, template)` decide pool
  (`manager+0xC`) o alloc (`FUN_80005624`).
- El float de la plantilla (`0x4182FE3C`) **no está en la ROM** → se **computa en runtime** (no es
  tabla estática). El objeto de boot vive en BSS del módulo 23 (`0x801CFF88`/`0x801D03C0`).
- Los callers de nivel superior están en el **módulo 7** (arranque), pero `ra` aparece a 0 en los
  breakpoints (llamadas vía puntero/`get_function`), así que la cadena no se cierra por `ra`.

**Balance**: confirmado que NO es datos/recompilación; es **estado runtime encadenado**. El método
manual por capas (objeto → callback → plantilla → spawner → caller) no converge rápido. La vía
adecuada para cerrar la causa raíz es la **traza de control completa desde el arranque** (port
`HH_CALLTRACE` + emulador `HH_JALTRACE`/`HH_THREAD_ENTRIES`, ya construidos y documentados en
`docs/workflows.md` §6) para localizar la **primera** función/bloque divergente y arreglarla en origen.

## Traza de control completa (reconstruida) — PRIMERA divergencia real localizada

Se re-añadió `HH_CALLTRACE` en `get_function` (overlays.cpp) y se comparó con `HH_JALTRACE` +
`HH_THREAD_ENTRIES` del emulador (filtro libultra `0x80024000-0x80037000` + boot ROM `0xA4xxxxxx`;
el port tiene una entrada extra inicial `FUN_80001078`).

Las trazas **coinciden 1:1** hasta `FUN_800020b0` (init de controller/SI en arranque). Secuencia sin
filtrar desde ahí:

```
port: FUN_800020b0, FUN_80030610, osSetEventMesg, osContInit, FUN_80030610, osSetEventMesg,
      FUN_800023a8 x4, FUN_80016df0, ...
emu : FUN_800020b0, FUN_80030610, osSetEventMesg, FUN_80032660, FUN_800326d0, osContInit,
      0x80031190, FUN_80032660, 0x8002bf90, FUN_800326d0, ... 0x80031498, 0x80031424, 0x800317c0,
      0x800266b0 (osRecvMesg), ...
```

- En el **port**, `osContInit` (`0x80027F20`, runtime) **retorna de inmediato** (rellena datos de los
  callbacks, sin tráfico SI ni bloqueo) y el bucle sigue.
- En el **emulador**, `osContInit` de libultra ejecuta la **query SI** (varias funciones libultra) y
  **bloquea en `osRecvMesg`**; durante el bloqueo corre(n) otro(s) hilo(s).
- → **Primera divergencia = init de controller/SI**: el runtime no bloquea en `osContInit`.
- Experimento naive (añadir `send_si_message()` en `osContInit`): **rompe** con SIGFPE al procesar el
  mensaje SI → el fix correcto exige replicar el **ciclo de query SI bloqueante** de libultra, no solo
  encolar.

**Conclusión**: la causa raíz arranca en el **ciclo de init SI/controller** del runtime (no bloquea
como libultra), que desordena los hilos desde el arranque y se propaga al state machine de boot y a la
fase. Es un hueco de emulación del runtime (SI), no del juego/datos/recompilación.

## Intento de fix del SI en `osContInit` → no desbloquea (y por qué)

Se implementó en el runtime un `osContInit` fiel a libultra (enviar SI + esperar en la cola + yield):
```c
if (mq != NULLPTR) {
    ultramodern::send_si_message();
    osRecvMesg(PASS_RDRAM mq, NULLPTR, OS_MESG_BLOCK);
    yield_self(PASS_RDRAM1);
}
```
Resultado: el juego sigue **en fase 0** (`3750=0`, `fe00/fe02=0`, nodo `0x801D03C0` sin cambiar) tras 45 s.
El mensaje SI se entrega **síncronamente** en `osRecvMesg`, así que el round-trip no reproduce el
bloqueo real de libultra. Cambio **revertido** (no aporta y altera comportamiento).

**Interpretación**: la primera divergencia de control (`osContInit`) es **real pero no es suficiente**;
puede ser un efecto colateral del scheduling o haber **más divergencias** después. Fijar solo la
primera no desbloquea el arranque. La vía correcta es **iterativa**: arreglar divergencia → re-trazar
→ siguiente divergencia, hasta que la fase avance (o comparar el punto de spawn del objeto de boot,
~t=8 s, que es donde el state machine se tuerce).

**Herramientas listas**: `HH_CALLTRACE` (port, re-añadido en `get_function`) + `HH_JALTRACE`/
`HH_THREAD_ENTRIES` (emulador), y el script de alineación (port empieza una entrada antes:
`FUN_80001078`).

## Investigación a fondo (modelo Max): runtime, web y sistema de objetos

### Web
- No existe decomp/port de **Hybrid Heaven** (buscado). Referencia: N64Recomp (Mr-Wiseguy), N64ModernRuntime,
  Zelda64Recomp, Goemon64Recomp, HarvestMoon64Recomp, MegaMan64Recomp.
- `N64ModernRuntime` issue **#32** ("Fix handling of NULL message queues"): `enqueue_external_message`
  con `mq==0` hacía segfault al idle thread → fix `if (mq != 0)`. **No aplica** (no hay crash así).
- MegaMan64Recompiled commit "Fix startup input deadlock": era un **doble `lock_guard`** en `poll_inputs`
  (mutex re-lock). El port HH **no** tiene ese patrón (su `src/game/input.cpp` no usa `poll_inputs`).
- Zelda64Recomp migró a "nuevo thread scheduling **sin hilo scheduler central**"; el runtime del port es
  más antiguo y lleva parches propios.

### Parches de runtime: descartados como causa
Se probó el port con **scheduling.cpp/threads.cpp/mesgqueue.cpp upstream** (del toolchain) + lock global
neutralizado: **mismo bloqueo** (fase 0, `fe00/fe02=0`). Los parches custom (lock single-CPU, `>=`,
flush externo en recv) **no son la causa**. Restaurado el runtime del port.

### El juego ejecuta lo mismo (conteo de llamadas)
Filtradas ambas trazas (`HH_CALLTRACE` port vs `HH_JALTRACE`+`HH_THREAD_ENTRIES` emu):
`FUN_80000a0c` 768 vs 765, spawner 18 vs 19, dispatcher 596 vs 571, `osGetTime` es el hot-loop (busy-wait
del juego, idéntico en upstream). **No falta lógica**; el estado diverge.

### Diferencia concreta del sistema de objetos
- El objeto de boot `0x801D03C0` en el port: `+0x18=0x8012E584`, `+0x1C=0x801C1034`, `+0x20=0x8012E654`,
  **`+0x24=0`**; en el emulador: `+0x18=0`, `+0x1C=0x801CBE88`, `+0x20=0`, **`+0x24=0x801D67DC`**.
- `+0x24` es un **nodo componente** que asigna `FUN_80005E44(obj,arg)`:
  `nodo = FUN_800063BC(pool 0x800892B0+0xB0=0x80089360, [arg+4])` (pop de free list) y, si OK,
  `FUN_80006370(obj,nodo)` → `sw a1,0x24(a0)`.
- En el port **`FUN_80006370` nunca recibe `0x801D03C0`** (0 hits con gdb). El nodo `0x801D67DC` va a
  `0x801D003C`; el free list del port está **~20 nodos por delante** (`0x801D7884` vs `0x801D7C94`).
  → La **lista/orden de objetos** diverge: el objeto de boot se queda sin su componente y su state machine
  (`FUN_8000c3b0` → tabla de callbacks) toma otro camino (`FUN_801c0f70…` en vez de `FUN_801cbdc0…`).

**Conclusión**: la cadena es: orden de hilos/mensajes al arranque (1ª divergencia en `osContInit`) →
orden de procesado de objetos → nodo componente sin asignar en el objeto de boot → callback equivocado →
la carga (`0x801CFE00/02`) no avanza. Siguiente: fijar el **orden de arranque de hilos/mensajes** (el
`osContInit` no bloqueante es el primer punto) o el orden de la lista de objetos.

## Higiene de runtime + verificación de la 1ª divergencia (2026-09-12)

**Calidad de código (hecho):**
- Toda la traza verbose del runtime es **opt-in** (`HH_VERBOSE=1`) vía `HH_LOG`/`ultramodern::debug::verbose()`;
  `boot_log` opt-in (`HH_BOOTLOG`); mensajes RSP warn-once. Run normal: **6 líneas** (solo init de SDL/Vulkan/heap).
- Divergencias port↔upstream auditadas y documentadas en `docs/architecture.md` §5.
- `osContInit` del runtime hecho **fiel a libultra** (query SI + espera en `mq` + one-shot). No desbloquea
  (el mensaje SI se entrega síncrono, así que el wait no cede); un fix 100% fiel requiere SI asíncrono.

**Verificación de la 1ª divergencia de control:** es **timing de VI**, no un bug de orden. El bucle de
comandos (`FUN_80000774`, hilo id 19) espera en la cola VI (`0x8005C560`, msg `0x29A`) y llama a
`FUN_80000a0c` por cada retrace; el emulador procesa ~6 retraces entre `FUN_800020b0` y `FUN_800023a8`,
el port 0 (race de wall-clock). No es determinista ni accionable como "orden".

**Estado del bloqueo (sigue):** el objeto de boot `0x801D03C0` no recibe su nodo `+0x24`
(`FUN_80006370` nunca lo recibe; free list ~20 nodos por delante; nodo `0x801D67DC` → `0x801D003C`).
El port no ejecuta `FUN_801cbdc0`/`FUN_801cbe88`/`FUN_801cc574`/`FUN_801cc748` (carga), sí
`FUN_8000469c` (11 vs 14). La plantilla de spawn (`0x8005BDB4`) se construye con otro callback
(`FUN_801c0f70` vs `FUN_801cbdc0`).

## Diff dirigido en el spawn: un solo argumento diverge (a3)

Backtrace del host en el spawn del objeto de boot (port, gdb `bt`):

```
FUN_80005b98 (obj 0x801D03C0, template 0x8005BDB4)
 ← FUN_80005670 ← FUN_8012c4d0 (mód7) ← FUN_80126198 ← FUN_801262d4
 ← FUN_801243dc ← FUN_80005270 (dispatcher) ← FUN_80001454 (game loop) ← FUN_800011b0
```

Comparación de argumentos de `FUN_8012C4D0` (port vs emulador, mismo `ra=0x8012626C`):

| arg | port | emulador |
|---|---|---|
| a0 | 0x801CFE20 | 0x801CFE20 |
| a1 | 0 | 0 |
| a2 | 0x80000000 | 0x80000000 |
| **a3** | **0x8012E584** | **0** |

- En `FUN_80126198` (0x80126220), `a3 = [t2+8]` con `t2 = [0x801760C0 + (index-1)*4]` e
  `index = lhu[padre+0x20]`; el resto de args vienen de `[t2+0..+0x14]`.
- La tabla `0x801760C0` y sus entradas (`0x8017604C/74/60`, `+8=0x8012E584`) son **idénticas** en ambos
  dumps → el emulador no leyó `+8` de ahí (o el índice/padre difiere; el padre capturado en el port,
  `0x801734F0`, tiene `lhu[+0]=0`, que haría saltar la función — pendiente afinar qué invocación exacta
  spawna). `a3` acaba en `obj+0x18`.

**Resultado**: la divergencia del spawn se reduce a **un único dato de entrada** (`a3` → `obj+0x18`),
proveniente de una **tabla indexada por estado del padre**. Es la localización más fina hasta ahora.

### Intento de cerrar el índice del padre (sin cerrar)

- En el port, en la llamada a `FUN_8012C4D0`, el frame llamante (`FUN_80126198`) tiene:
  `s0=0x801734F0`, `v0(r2)=0x51`, `t0(r8)=0x144`, `t2(r10)=0x801CC844` (módulo 23), `s3=1`.
- `a3 = [t2+8] = [0x801CC84C] = 0x8012E584` (coincide con el port).
- **Pero** la lectura en vivo de `lhu[s0+0x20]` (`0x80173510`) da **0**, no `0x51`; y los volcados
  at-spawn (port y emulador) también dan 0 ahí. El dato estático `[0x801CC84C]=0x8012E584` es igual en
  ambos, luego el **emulador usó otro índice/entrada** (con `+8=0`) — pero no se pudo pinchar cuál.
- Inconsistencia pendiente: el bucle `L_801261EC`/`L_801262A4` probablemente **cambia `s0`** por iteración,
  o `v0` es un contador previo y no el índice; el frame `up` de gdb da `ctx->r16` (s0) del estado actual,
  no necesariamente el del cálculo.

**Conclusión**: la cadena se estrechó al argumento `a3` del spawn, pero **no se cierra** por esta vía sin
más instrumentación (traza por iteración del bucle). Recomendación: cambiar a la vía **sistemática**
(volcados RDRAM a VIs tempranos 5/10/30/60 en port y emulador, diff y primera divergencia de estado).

## Vía sistemática: diff de RDRAM a VIs tempranos

Volcados: port `HH_DUMP_VI` (20/30/60/120) y emulador `HH_DUMP_TIMES` (0.2/0.5/1.0/2.0 s).
**Alineación corregida**: el port VI60 coincide con emulador t=1.0 s (varios punteros idénticos:
0x800792F0, 0x80079378, 0x80089338, 0x8008942C). El VI del port va 1:1 con el tiempo.

Diff del par alineado (port VI60 vs emu t=1.0, excluyendo pilas): ~3755 palabras.
Clusters: `0x80037764` (estado por-frame), `0x80049930` (hilo), `0x80089358`/`0x80089474` (pool),
`0x80091BFC..` y `0x80095AE4..` (heap), y un **array de structs en `0x8009C9F8`** (stride 0x15C).

**Primera divergencia estable de estado de juego** (idéntica dentro de cada lado, distinta entre lados):
struct en `0x8009C9F8` (dentro de `FUN_80088088`, tabla con punteros libultra):
- `+0x00`: port=0 vs emu=0x3E0
- `+0x08`: port=1 vs emu=0
- `+0x0C`: port=0x75520 vs emu=0x7574E
- `+0x10/+0x14/+0x18` (punteros `0x8009C9C0`/`0x8002EC2C`/`0x8002EB40`) **coinciden**.
Parecen acumuladores/timers (posible diferencia de timing), no necesariamente causales.

**Conclusión**: la vía sistemática confirma que el estado temprano está mayormente alineado; la
divergencia causal sigue siendo el state machine de objetos (`a3` del spawn → callback del objeto de
boot), ya localizada. No aparece un "dato/init" raíz distinto por esta vía.

## Instrumentación por-frame del objeto de boot (evolución)

Añadido log `[OBJ]` por-frame en el runtime (gated `HH_VERBOSE`). Port: el objeto `0x801D03C0` está a 0
hasta **vis 492** y se puebla de golpe en vis 492 (el spawn), sin cambios posteriores.

Estado justo tras el spawn (port vis 492-540 vs emu t=8.3 s):

| campo | port | emulador |
|---|---|---|
| `+0x00` | 0 | `0x801D0474` (next) |
| `+0x0C` | `0x801CFF88` | `0x801CFF88` |
| `+0x14` | `0x80000000` | `0x80000000` |
| `+0x18` | **`0x8012E584`** | **0** |
| `+0x1C` | **`0x801C1034`** | **`0x801CBE88`** |
| `+0x20` | **`0x8012E654`** | **0** |
| `+0x24` | **0** | **`0x801D67DC`** |
| `+0x34` | `0x03010000` | `0x030100E8` |
| `+0x38` (padre) | **`0x801734F0`** | **`0x80173530`** |
| `+0x3C` | `0x00001900` | `0x00001900` |

**Hallazgo**: el objeto de boot se instancia desde un **padre distinto** (slots adyacentes `+0x40`),
y sus campos de estado/callbacks difieren en consecuencia. La divergencia está, por tanto, en **qué
objeto de la tabla actúa como padre** (selección de índice/slot), no en un único argumento.

## BREAKTHROUGH: causa raíz = estado de mandos + mid-entries faltantes

Cadena completa trazada con instrumentación (log `[OBJ]` por-frame + gdb + oráculo):

```
estado de mandos (OSContPad err_no) → flag lhu[0x80089474]
  → rama de FUN_801235d0 (0x80123614 vs 0x80123630)
  → índice del gestor 0x801BBBF0+0x4 (0x76 vs 0x77)
  → padre del objeto de boot (0x801734F0 vs 0x80173530)
  → callbacks del objeto (FUN_801c1034 vs FUN_801cbe88)
```

**Causa**: el port reportaba **todos** los mandos como conectados/respondiendo:
- `hh::get_input` devolvía `true` para todos los puertos (src/game/input.cpp).
- `osContGetReadData_recomp` (cont.cpp) sólo escribía los mandos con `err==0`, dejando
  valores viejos en el buffer del juego.
- `get_connected_device_info(0)` devolvía `None` sin SDL, pero el emulador tiene el puerto 0 presente.

**Fixes aplicados**:
1. `hh::get_input` → solo el puerto 0 responde.
2. `osContGetReadData_recomp` → escribe un `OSContPad` para **todos** los mandos (como libultra).
3. `hh::get_connected_device_info(0)` → controlador estándar siempre presente en el puerto 0.
4. **Mid-entries faltantes** (la ruta correcta las invoca y el port crasheaba con
   "Failed to find function"): `0x8000106C`, `0x800165CC`, `0x80016634`. Añadidas dividiendo los
   símbolos en `config/us_combined.syms.toml`/`us_ghidra.syms.toml` (`FUN_80001060` y
   `FUN_80016500`) y recompilado. De la traza del emulador: sólo faltaban esos targets
   (`+0x80000180` vector y `0x8002AEA0` gestor VI, esperados).

**Resultado**: el objeto de boot `0x801D03C0` ahora se crea en vis≈447 con los **mismos** valores que
el emulador (`+0x00=0x801D0474`, `+0x1C=0x801CBE88`, `+0x24=0x801D67DC`). ¡Estado alineado!

**Nuevo bloqueo**: SIGSEGV en `FUN_80139894` (funcs_25.c:4950): `FUN_8000522C` (lookup
`FUN_80017064`/`FUN_8001703C` + offset) devuelve `0x2910` (base 0 → el índice no se encuentra).
Es una ruta nueva que antes no se alcanzaba.

## Paso 1 (en curso): tabla de recursos incompleta — flag 0x8008D550

El crash de `FUN_80139894` viene de `FUN_8000522C` (lookup por id): `FUN_80017064(id)` busca en la
tabla `0x8008DFC0` (256 pares id/ptr) y devuelve `-1` si no está → `FUN_8001703C(-1)` indexa con -1 y
lee basura (de ahí `0x2910`).

**Tabla incompleta en el port**: el emulador registra ids `0x18,0x73,0xDE,0x91`; el port solo `0x73,0xDE`.

Cadena del registro:
- `FUN_800045E8(id)` → `FUN_80016EAC(id, ptr)` (insert con desplazamiento) → `FUN_80017384/173B8`.
- El bucle que registra es `FUN_80125814`, pero **su primer check es `if (t6 == 0) skip`**, con
  `t6 = lbu[0x8008D550]` fijado por `FUN_80125808` (fallthrough).
- `0x8008D550` lo **pone** `FUN_80125774` (y `FUN_801257dc`) y lo **limpia** `FUN_801235d0` (+0xD0).

**Orden divergente** (traza, índices):
- PORT: STATEMACH(7.83M) → READ(10.31M ×2) → **SET(11.56M)** ⇒ el SET llega **después** de las lecturas →
  `t6=0` → registros saltados.
- EMU: STATEMACH(0.84M) → READ(0.93M..) → SET(1.22M) ⇒ orden distinto; registra correctamente.

`FUN_80125808` corre 2× (port) vs 6× (emu). Es la misma clase de problema: **orden de arranque** del
state machine, ahora en la ruta de registro de recursos.

## Paso 1 — intento de cierre del registro de recursos (sin fix fundado aún)

- El "SET" de `0x8008D550` viene de `FUN_801257dc` (`[flag]=0; FUN_80125774(0); [flag]=0`) en **ambos**,
  con `a0=0` y `ra=0x801257F4` (emulador). La comprobación de `manager+0x180` (para las ramas
  `FUN_80125774(0x3000/-1)` de `FUN_801243dc`) da **0 en ambos**.
- El guard `FUN_80125808`→`FUN_80125814` salta si `lbu[0x8008D550]==0`; las lecturas del port (2) y del
  emulador (6) no se corresponden con los SET/CLEAR observados, así que **la secuencia exacta set/read
  no queda cerrada** con la instrumentación actual.
- Conclusión: **no hay fix fundado** para aplicar aquí todavía; haría falta trazar el orden real
  (watchpoint de `0x8008D550` con PC+tiempo en ambos + captura de `lbu[manager+0x180]` en el momento
  del registro). Se deja documentado para no adivinar.

## Traza fina del registro de recursos (paso 1)

Secuencia del port (gdb, setters `FUN_80017384`/`FUN_800173b8`), sin ceros:
```
idx0 id=0x01   ptr=0x800F41C0
idx0 id=0xFFFE ptr=0x803837E0  (×3)
idx0 id=0x73   ptr=0x801FA948
idx1 id=0xDE   ptr=0x801FACB8
```

Ramas en `FUN_80125814` (lookup `FUN_80017064(id)`; si `!= -1` **no registra**):
| id | lookup | acción |
|---|---|---|
| `0x18` | `0` (encontrado) | no registra |
| `0x73` | `-1` | **registra** |
| `0xDE` | `-1` | **registra** |
| `0x91` | `2` (encontrado) | no registra |

**Crash**: `FUN_8000522C(0x91)` → `FUN_8001703C(2)` = **0** (slot de puntero vacío) → base 0 →
`ptr + 0x2910` = `0x2910` → SIGSEGV. Es una **desincronización id/ptr**: el id `0x91` aparece en la
tabla de ids (índice 2) pero el puntero de ese índice no está escrito.

El emulador registra `0x18,0x73,0xDE,0x91` (4 entradas coherentes). El port acaba con 2 y el lookup de
`0x91` "cree encontrarlo" → puntero nulo. **Siguiente**: localizar qué escritura deja `id` sin `ptr`
(el insert con desplazamiento `FUN_80016EAC` mueve id y ptr en pasos separados; si se interrumpe/ordena
mal, quedan desparejados) — o el origen del id `0x91` en la tabla de ids.

## Origen de la desincronización id/ptr — hallazgos

Log `[TBL]` por-frame del port (tabla `0x8008DFC0`):
- vis 14: vacía. · vis 34–443: `idx0=(0xFFFE,0x803837E0)`. · vis 444–445: vacía.
- vis 446: `idx0=(0x73,0x801FA948)`. · vis 448: `idx1=(0xDE,0x801FACB8)`. · vis 449: crash.
- **Nunca aparecen `0x18` ni `0x91`.**

Ramas en el registro (`FUN_80125814`, línea 35687) con la tabla en ese instante:
| id | resultado | tabla | acción |
|---|---|---|---|
| `0x18` | `0` | vacía | no registra |
| `0x73` | `-1` | vacía | registra |
| `0xDE` | `-1` | `(0x73)` | registra |
| `0x91` | `2` | `(0x73,0xDE)` | no registra |

Los resultados `0x18→0` (tabla vacía) y `0x91→2` (solo 2 entradas) son **anómalos**: un lookup correcto
daría `-1`. Eso sugiere que el valor capturado en `ctx->r2` en el breakpoint puede ser **stale/desplazado**
(mapeo gdb), o que `FUN_80017064` no se está comportando como el original en este punto (candidato a
revisar: la fusión/optimización del bucle `L_80017088`).

**Estado**: desincronización confirmada (ids `0x18`/`0x91` nunca se registran → el lookup de `0x91`
falla → `FUN_8001703C(-1)` indexa con -1 y lee basura → SIGSEGV). Falta determinar si es un artefacto
de captura o un comportamiento real de `FUN_80017064`.

## Origen de la desincronización: estado TRANSITORIO de la tabla

Traza fiable en runtime (wrappers en `get_function`, `HH_TBLTRACE=1`):

```
READ5808 id=0x18 flag=0 → FIND(0x18) → el bne da r2=0  ⇒ "presente" ⇒ NO registra
READ5808 id=0x73 flag=0 → FIND(0x73) = -1            ⇒ registra 0x73
READ5808 id=0xDE flag=0 → FIND(0xDE) = -1            ⇒ registra 0xDE
READ5808 id=0x00 flag=0 → id==0 ⇒ return 2
READ5808 id=0x91 flag=0 → FIND(0x91) → el bne da r2=2 ⇒ "presente" ⇒ NO registra
FIND(0x91) desde FUN_8000522c/FUN_80139894 → -1 ⇒ FUN_8001703C(-1) → SIGSEGV
```

- **Test directo** de `FUN_80017064(0x18)` y `(0x91)` en el crash: **`-1`** (correcto). La tabla final
  solo tiene `(0x73,0x801FA948)` y `(0xDE,0x801FACB8)`.
- Por tanto, **en el momento del registro la tabla contiene `0x18` (índice 0) y `0x91` (índice 2) de
  forma transitoria**; el port los considera presentes y no los registra; luego esos slots desaparecen y
  el lookup del game loop falla.
- Los pares id/ptr escritos por el port son coherentes; el problema es **cuándo** están presentes.
  El emulador no ve esas entradas transitorias y registra las 4.

**Siguiente**: localizar la escritura que introduce `0x18`/`0x91` transitoriamente (probablemente un
insert/clear del state machine antes del registro) y por qué en el port persiste hasta el lookup de
`FUN_80125814` (en el emulador no). Candidato: orden entre `FUN_80124ed8`/`FUN_80125968` y el
clear del asset/EDL (la tabla arranca con `0xFFFE:803837E0` y se vacía en vis 444).

## Bug del slot de pila en FUN_80125814 (fallthrough split)

Traza fiable (wrappers `HH_TBLTRACE`):
```
FIND(0x18) -> -1  tbl=0000...        paso 1
REG(0x73)                            ← registra 0x73 (el llamante pasó 0x18!)
FIND(0xA5E0) -> -1 tbl=0073...       ← ID BASURA (el llamante pasó 0x73)
REG(0xDE)
FIND(0xDE) -> 1
FIND(0x91) -> -1 tbl=0073 00DE
```

- Dentro de un mismo paso, el **lookup (`lhu[sp+0x1A]`) y el registro (`lhu[sp+0x1A]`) usan ids
  distintos**, y a veces basura (`0xA5E0`).
- Las macros son coherentes: `MEM_W` = store nativo sin swap; `MEM_HU` = read con `^2`. El round-trip
  `sw a0,0x18(sp)` → `lhu 0x1A(sp)` debería dar el mismo valor.
- Sospechoso principal: **`FUN_80125808` cae (fallthrough) en `FUN_80125814`**; el recompilador lo
  dividió ("@fallthrough-fix: split fallthrough -> chain to continuation"). Si el frame/stack del
  split no es continuo, `lhu[sp+0x1A]` de `FUN_80125814` lee de una posición equivocada (de ahí los ids
  basura y el registro con el id del llamante equivocado).

**Siguiente**: comparar el código MIPS real de `0x80125808..0x80125820` con el C generado del split; si
el problema es el frame, revisar `fix_fallthroughs.py`/la política de fallthrough, o añadir el símbolo
`0x80125814` como función propia (en vez de cadena) para que el recompilador genere el frame correcto.

## No-determinismo en el registro de recursos

- gdb en el `lhu` del lookup (`funcs_18.c:35679`), captura fiable del slot: `r4=slot` correctos en todas
  (`0x18→0x18, 0x73→0x73, 0xDE→0xDE, 0→0, 0x91→0x91, 0→0`).
- La ejecución con wrappers (`HH_TBLTRACE`) mostró un lookup con id **basura `0xA5E0`** y registros
  desfasados (`FIND(0x18)`→`REG(0x73)`).
- Test directo de `FUN_80017064` en el crash: `-1` para `0x18`/`0x91`; la tabla final solo tiene 2 pares.
- **Conclusión**: el contenido de la tabla en el momento del registro **varía entre ejecuciones**
  (transitorio/race), de modo que a veces `0x18`/`0x91` "aparecen" presentes y el port se salta
  registrarlos; luego desaparecen → crash. No es un único write determinista.

**Siguiente**: identificar la fuente de no-determinismo (¿escritura desde otro hilo/VI? ¿orden entre el
asset/EDL y el state machine?). Concretamente: repetir `HH_TBLTRACE` varias veces y comparar; y ver si
el vaciado de la tabla (`0xFFFE:803837E0` → vacía) ocurre en un punto distinto por ejecución.

### Contradicción wrapper↔gdb (determinista)

3 ejecuciones idénticas: `FIND: 0x18, 0xA5E0, 0xDE, 0x91, 0x91` + `REG: 0x73, 0xDE`.
gdb en el `lhu` del lookup: ids correctos `0x18, 0x73, 0xDE, 0, 0x91, 0`.

→ El wrapper del runtime ve un `FUN_80017064(0xA5E0)` que gdb no ve en `FUN_80125814`:
hay **otro llamante** de `FUN_80017064` (o el `ctx` compartido se modifica entre llamada y comprobación).
El registro sigue saltándose `0x18`/`0x91` (el `T1-CHECK` solo se alcanza para `0x73`, `0xDE`, `0`).

**Estado del paso 1**: crash localizado en el registro de recursos; causa próxima: los registros de
`0x18`/`0x91` no se ejecutan. Instrumentación runtime ya disponible (`HH_TBLTRACE`). Siguiente: mapear
**todos** los llamantes de `FUN_80017064` (bt en cada uno con gdb) y separar el flujo de
`FUN_80125814` del resto; o registrar `a0`+`sp` en el wrapper para atribuir cada `FIND` a su llamante.

### Mapa de llamantes de FUN_80017064

| id | llamante | registra |
|---|---|---|
| `0x01` | `FUN_80125814` ← `FUN_8000433c` ← game loop | (otro flujo) |
| `0x18` | `FUN_80125814` ← `FUN_80124ed8` | **NO** |
| `0xA5E0` | `FUN_80125814` ← `FUN_80125968` | NO (id basura) |
| `0xDE` | `FUN_80125814` ← `FUN_80125968` | **SÍ** |
| `0x91` | `FUN_80125814` ← `FUN_80125968` | **NO** |
| `0x91` | `FUN_8000522c` ← `FUN_80139894` (crash) | — |

- El id `0xA5E0` (basura) llega vía `FUN_80125968` a `FUN_80125814` → **el argumento se corrompe/deriva**
  en ese flujo (el llamante debería pasar `0x73`).
- Los `T1-CHECK` (`id==0`) solo se alcanzan para `0x73`/`0xDE`/`0`; para `0x18`/`0x91`/`0xA5E0` el flujo
  toma el camino "encontrado" (aunque el wrapper reporta `-1`) → **inconsistencia entre el valor de
  retorno real y el que ve la comprobación** (posible problema del `ctx` compartido o del mapa de línea).

## CAUSA RAÍZ del salto de registros: el retorno de FUN_80017064 no se conserva

Mismo run (wrapper runtime + gdb):

```
TRC wrapper: FIND(0x18) -> -1   |  gdb BNE id=0x18 r2=0x00000000   ← discrepancia
TRC wrapper: FIND(0x91) -> -1   |  gdb BNE id=0x91 r2=0x00000002   ← discrepancia
```

- El `ctx->r2` tras `FUN_80017064` (wrapper) es `-1`, pero en el `bne` (`FUN_80125814`, `if v0 != -1`)
  vale `0` (id 0x18) y `2` (id 0x91) → el juego toma el camino "encontrado" y **no registra**.
- Slot del lookup correcto, ids correctos, llamantes correctos (`FUN_80124ed8` → `0x18`/`0x73`;
  `FUN_80125968` → `0xDE`/`0x91`). Todo bien salvo el **valor de retorno entre llamada y comprobación**.
- Posible causa: el `ctx` compartido en el port (todas las funciones recompiladas usan el mismo
  `ctx`), y algo (el epílogo de `FUN_80017064` o su uso interno de `r2` como temporal) deja `r2` con el
  valor del **bucle interno** (`FUN_80017014`) en vez del retorno final.

**Siguiente**: inspeccionar el C generado de `FUN_80017064` (bucle `L_80017088`) y comparar con el MIPS:
si el `return v0` final no escribe `ctx->r2` en el camino correcto (p.ej. el `goto L_800170B0` desde el
bucle), es un bug de recompilación del bucle de búsqueda.

## Prueba de re-llamada: FUN_80017064 funciona

En el punto `after_4` de `FUN_80125814` (donde el runtime ve `r2=0` para id `0x18`), re-llamando
`FUN_80017064` con el **mismo `ctx`** y la misma tabla:
```
runtime r2=0x00000000 id=0x0018
recall(0x18) -> 0xFFFFFFFF   ← correcto
recall(0x91) -> 0xFFFFFFFF   ← correcto
```

→ `FUN_80017064` es correcto; el `r2` que ve `FUN_80125814` (`0` para `0x18`, `2` para `0x91`) **no es el
retorno de su llamada**. Notas:
- El wrapper del runtime ve `FIND(0x18)=-1`, pero `after_4` ve `0`.
- Los `id` del wrapper (`0x18,0x73,0xA5E0,…`) y los de `after_4` (`0x18,0x73,0xDE,0,0x91,0`) no
  coinciden 1:1 → parece haber **dos flujos de lookup** distintos (o el `ctx->r2` se sobrescribe por la
  re-ejecución del delay slot / por `ctx` compartido).
- La re-ejecución del delay slot en el C generado (`after_4` reescribe `ctx->r4`) no toca `r2`; el
  sospechoso es el **manejo del slot/`ctx` compartido** y la atribución de cada `FIND` a su llamada.

**Estado**: bloqueo actual localizado con precisión (registro de `0x91` no se ejecuta por un `r2`
espurio; `FUN_80017064` es correcto). La instrumentación `HH_TBLTRACE` permite seguir.

## Resultado del paso 1 (estado consolidado)

- **`FUN_80017064` es correcto**: re-llamada con el mismo `ctx` → `-1` para `0x18`/`0x91`.
- **No es la instrumentación**: sin `HH_TBLTRACE` el resultado es idéntico.
- **El `r2` que ve `FUN_80125814`** en `after_4`: `0x18→0`, `0x73→-1`, `0xDE→-1`, `0→1`, `0x91→2`, `0→-1`
  (valores imposibles para la tabla real: vacía/2 entradas). El flujo toma el camino "encontrado" para
  `0x18`/`0x91` y **no los registra** → después el lookup del game loop falla → SIGSEGV en
  `FUN_80139894`.
- Conclusión: el escalón pendiente es el **manejo del valor de retorno/`ctx` compartido** en el par
  `LOOKUP_FUNC(0x80017064)` + `bne` de `FUN_80125814` (o la re-ejecución del delay slot), no la lógica
  de la tabla ni `FUN_80017064`.

Trabajo del bloqueo original (input + mid-entries) aplicado y verificado; la instrumentación
`HH_CALLTRACE`/`HH_TBLTRACE` y los fixes quedan en el repo. `TODO.md` #9 actualizado con el estado.

## Causa raíz del crash: ids desplazados dentro de FUN_80125814

Traza fiable (wrappers `HH_TBLTRACE` en `FUN_80125808`/`FUN_80017064`/`FUN_800045E8`):

```
STEP5808 id=0x18 → r=2 ;  dentro: FIND(0x18)->-1  y  REG(0x73)   ← id de registro equivocado
STEP5808 id=0x73 → r=1 ;  dentro: FIND(0xA5E0)->-1 y REG(0xDE)   ← lookup con basura
STEP5808 id=0xDE → r=1 ;  dentro: FIND(0xDE)->1
STEP5808 id=0x91 → r=2 ;  dentro: FIND(0x91)->-1  (sin registro)
```

- **Los lookups (`FUN_80017064`) son correctos** (`-1` para `0x18`/`0x91`); la tabla es coherente.
- El problema: **el `lhu[sp+0x1A]` que usa el camino de registro NO es el `a0` que se guardó**
  (`sw a0, 0x18(sp)`), sino otro valor (el del llamante siguiente/previo, o basura `0xA5E0`). Por eso
  se registran ids equivocados (`0x73`/`0xDE`) y se saltan `0x18`/`0x91`.
- Consecuencia: la tabla final no tiene `0x91`; el lookup del game loop (`FUN_80139894` →
  `FUN_8000522c`) falla y `FUN_8001703C(-1)` indexa con -1 → SIGSEGV.

**Siguiente/fix**: revisar el C generado de `FUN_80125814` (guardado y lectura del slot `sp+0x18`/`sp+0x1A`)
y su interacción con el `ctx` compartido / delay slot; puede requerir un patch de la función o revisar
la política de `fix_fallthroughs.py` para `FUN_80125808`→`FUN_80125814`.

## ✅ BLOQUEO DE ARRANQUE RESUELTO (fase 0 → 1)

Con la instrumentación se cerraron **dos** causas encadenadas:

1. **Registro de recursos (`FUN_80125814`)**: el `bne $v0,$at,L_80125954` (`0x8012591C`) tomaba el camino
   "ya registrado" con un `v0` inestable → `0x18`/`0x91` no se registraban → `FUN_80139894` crasheaba.
   **Fix**: patch de instrucción en `config/game_combined.toml`
   (`[[patches.instruction]] vram=0x8012591C func="FUN_80125814" value=0` → nop la rama, siempre registra;
   el juego re-chequea id 0 y la tabla queda estable).
2. **Mid-entry `0x8001769C`** (dentro de `FUN_80017608`): reventaba en cuanto el registro avanzaba.
   **Fix**: dividir el símbolo (`FUN_80017608` size 0x1C4 → 0x94 + `FUN_8001769c` size 0x120) y recompilar.

**Resultado** (run de 180 s, `HH_VERBOSE`):
```
vis=960   fe00=0x0000 fe02=0x02
vis=1860  fe00=0x008B fe02=0x04
vis=2760  fase(3750)=1, estadoA(3730)=1, fe00=0x0247
vis=10800 fase=1, fe00=0x11C9, 0 errores
```
La **fase de arranque avanza (1)**, el progreso de carga (`fe00/fe02`) corre y el port se mantiene
estable. **El bloqueo histórico de fase 0 está resuelto.**
