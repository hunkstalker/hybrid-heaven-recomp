# SESIÓN 2026-09-10 — Bloqueante de RENDER: análisis del mecanismo de tareas custom del motor Konami

> Complementa `notes/2026-09-10-scheduler-diagnosis.md` y `notes/2026-09-10-windows-build.md`.
> Resultado de una sesión de análisis (Ghidra + runtime) sobre por qué el juego no renderiza
> (pantalla negra) pese a que el boot funciona y los threads corren.

## 0. Resumen ejecutivo

- El **boot funciona** (`Entrypoint returned`, threads creados, RT64 OK) y los threads VI/RSP corren.
- **PERO el game loop (thread 5) está clavado en `osRecvMesg(0x8005be40)`** y **nunca llega a su
  bucle de render** (`osRecvMesg mq=0x8005c288` = **0 ocurrencias** en el log; solo se *envían*
  mensajes ahí, nadie los recibe). Esa es la causa de la pantalla negra.
- El "frames avanzando" que se veía en runs anteriores era de los threads **VI/RSP**, no del game loop.
- `DAT_80037750` (modo de render) = 0 — es **consecuencia**, no causa: el state machine de render
  (`FUN_80001454`, que llama a `FUN_80029fa0`) vive DENTRO del bucle del game loop, que nunca arranca.

## 1. Confirmación runtime (traza `[RND]`)

Añadida una traza que lee los globals de estado de render del juego (`rdram[0x...]`):
```
[RND] vis=60  3750=0x00000000 3730=0x00000000 3738=0x00000000 3734=0x00000000 373c=0x00000000
[RND] vis=600 3750=0x00000000 ... (todo 0, nunca cambia)
```
- `DAT_80037750` (gate del state machine de render), `DAT_80037730`/`DAT_80037738` (estados),
  `DAT_80037734`/`DAT_8003773c` (contadores) → **todos 0 durante todo el run**.
- `osRecvMesg mq=0x8005C288` = 0 (el game loop jamás recibe en su bucle).
- `osSendMesg mq=0x8005C288` = 985 (alguien envía, nadie consume).

## 2. Diferencia clave vs Goemon (pista del usuario — MÁS IMPORTANTE)

- **Goemon** (mismo runtime Konami) envía las tareas de display vía **`osSpTaskLoad`/`osSpTaskStartGo`**
  (`func_8000769C_829C` en `RecompiledFuncs/funcs_13.c`) → el runtime las intercepta → `submit_rsp_task`. Por eso Goemon renderiza.
- **Hybrid Heaven NO llama NUNCA a `osSpTaskLoad`/`osSpTaskStartGo`** (grep en HH = **0**).
  Usa un mecanismo **custom Konami**:
  - `FUN_80029fa0(param_1)` escribe la tarea en un struct (`_LAB_8004aed4`, que apunta a
    `0x800cc300`) y hace señal vía `FUN_800326d0` (bit de cop0 Status): `*t=1`, `t[+4]=param_1`,
    `t[+6]=*(*param_1+4)`.
  - El dispatch escribe los registros del SP **directamente** (`0xa4040010` = SP_STATUS, en
    `FUN_80034690`/`FUN_800346a0`), en vez de `osSpTaskStartGo`.
  - **El runtime no intercepta ese camino** → la primera tarea nunca se envía al RSP → su finalización
    nunca postea a `0x8005be40` → thread 5 queda colgado → no hay render.

## 3. Detalle del mecanismo (mapeado parcial)

- **Scheduler setup** (`FUN_8002ac60`): crea la cola principal `0x8005bf30` + el dispatcher
  (thread 0, `FUN_8002aea0`, struct de thread en `0x800cc300`) y guarda el puntero a la cola en
  `0x8004ab18`.
- **Dispatchers/emisores**: `FUN_8002bfa0` (tipo 0xb/0xc) y `FUN_800304f0` (0xf/0x10) construyen un
  `OSScTask` y hacen `osSendMesg`/`osJamMesg` a la cola principal (vía `FUN_800326f0`). Sus wrappers
  `FUN_8001ffac`/`FUN_80001fb4` **no son llamados por el código plano** (solo desde overlays o vía
  puntero indirecto — no encontrados por Ghidra).
- **El game loop** (`FUN_800011b0`) hace el setup (`FUN_80000460` → crea colas + VI + llama a
  `FUN_80029fa0`) y **luego bloquea en `osRecvMesg(0x8005be40)`** antes de su bucle. Ese es el punto
  donde se queda.
- **`0x8005be40`** (count=1): cola de sincronización "arranque del game loop". Creada justo antes del
  recv. **NO está event-wired** (event=5 va a `0x8005bec8`, no a `0x8005be40`). El sender no está en
  el código plano (búsquedas de offset `0xbe40`/`-0x41c0` = 0).

## 4. Funciones stubbed con `do_break` (posibles dependencias futuras)

En la región de boot hay funciones que fueron **stubbeadas** (absorbieron datos) y emiten `do_break`
si se las llama: `FUN_8000919c`, `FUN_8000bc78`, `FUN_8000c768` (y más en `funcs_1.c`). No se han
llamado aún en el boot (no aparece `do_break` en el log), pero pueden ser necesarias al avanzar.

## 5. Conclusión / decisión

- El render está bloqueado porque la **primera tarea RSP usa el mecanismo custom Konami que el runtime
  no intercepta** (y, además, el game loop queda esperando la finalización de esa tarea en
  `0x8005be40`).
- **Opción elegida (la técnicamente correcta, sin atajos): A** — mapear a fondo el mecanismo custom
  (struct `0x800cc300`, señal cop0 Status, dispatch SP) y hacer que el runtime lo soporte
  (llegando a `submit_rsp_task`), en vez de disparar a mano `0x8005be40` (que sería una chapuza:
  mentiría al juego sobre una tarea que no se procesó).
- **Nota honesta**: la tarea de display se envía vía emisores a la cola principal, y esa vía se alcanza
  DESPUÉS de que el game loop arranque. Por tanto, desbloquear el envío custom es necesario para que
  la primera tarea (audio o display) complete y postee a `0x8005be40`, arrancando el game loop → render.

## 6. Trazas de diagnóstico añadidas al runtime (eventos/mesgqueue)

- `[RND]` (events.cpp, periódico cada 60 VI): estado de render del juego (3750/3730/3738/3734/373c).
  **Dejar o quitar** — es ruidosa pero útil para iterar el render.

## 7. Estado de los repos

- `RecompiledFuncs/` unificado (341 funcs) + assets + src versionados. Fixes MSVC (recomp.h cop0,
  mesgqueue, osStopThread) documentados. N64ModernRuntime con fixes en el working tree (committed).
- Sin cambios de código de runtime en ESTA sesión de render (solo la traza `[RND]` y análisis).
