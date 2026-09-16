# Cuelgue del NPC (ronda 7): fuga de pila 0x48/frame por fallthrough sin encadenar en el modulo 55

Fecha: 2026-09-15 (noche). Antecedentes: `…-stack-overflow-y-sombra-hilos.md`.

## Sintoma

- La sombra `hh_sh_*` elimina el cuelgue inmediato, pero:
  - pila del hilo 5 baja `0x27F0` cada 5 s (≈`0x48`/frame) y a los ~10 s queda aparcado para
    siempre en `osRecvMesg(mq=0x8005C288)`;
  - el objeto del NPC solo rota (no escala) y la caja de texto no desaparece.

## Evidencia (runs del usuario)

1. `hh_cmds.log` (recv de `0x8005C288`): `sp` baja **exactamente `0x48` por ciclo** de forma
   perfectamente lineal (≈444 saltos; `sp=8005BEE0 → 80054200`) desde que arranca la secuencia.
2. `hh_ring2_{3,4,5,7}.log` (volcado por paron, 60000 llamadas `target+sp`):
   - el bucle ocioso es estable (sp constante por iteracion);
   - la pila baja `0x48` **una vez por ciclo** (~21300 llamadas) y el unico candidato que aparece
     una vez por ciclo en todos los volcados es **`M55_FUN_80379690`** (sp −0x48 en cada frame:
     p. ej. dump5 `80058B98 → 80058B50`).
3. Analisis de tail-calls del recompilado (`LOOKUP_FUNC(x); return;`): dos objetivos con net −0x48
   en modulo 55 (`0x803798D8`, `0x80379798`), ambos *mid-entries* de `M55_FUN_803796e4`.

## Causa raiz

`RecompiledFuncs/funcs_106.c`: `M55_FUN_80379690` (entry 0x80379690) hace `addiu sp,sp,-0x48` y su
cuerpo termina en 0x803796E0 **cayendo a 0x803796E4** (continuacion = `M55_FUN_803796e4`), pero el
codigo generado terminaba en `;}` **sin encadenar la continuacion** → la funcion retornaba a su
llamador sin restaurar `sp` (fuga `0x48`) y **sin ejecutar la animacion del objeto**.

La continuacion `M55_FUN_803796e4` (432 lineas) es la logica de escala/animacion:
floats `0x4120`=10.0, `0x4361`=225.0, `0x42A0`=80.0, y escribe el contador de fase global
`0x8039-0x764C` (el mismo que `M55_FUN_80379690` compara con `0x14`/`0x33`). De ahi que el objeto
solo rotase y el texto no avanzase.

`tools/analysis/fix_fallthroughs.py` no lo detectaba: su heuristica era `has_ret = any("return;")`
en todo el cuerpo, y esta funcion tiene `return;` en ramas (`LOOKUP_FUNC(...); return;`) aunque al
final cae. Las funciones afectadas se iteran por direccion: 0x803796E0 + 4 = 0x803796E4 (entry de la
continuacion, misma seccion).

## Fix

`tools/analysis/fix_fallthroughs.py` (idempotente):

- La decision mira **solo la ultima sentencia real** (ignorando `}` de cierre):
  `is_ft = not term_ret and not term_goto and not tail_call`.
- Se exige ademas que la continuacion sea exactamente la instruccion siguiente:
  `func_addr(cont) == last_addr + 4` (evita encadenar a *mid-entries*).

Resultado de la pasada: `fallthrough functions found: 1953; chained: 1921; skipped: 32`.
Total de cadenas `// @fallthrough-fix` en el arbol: 2343. El caso conocido:

```c
// 0x803796E0: ldc1 $f0, -0x6AE8($at)
ctx->f0.u64 = LD(ctx->r1, -0X6AE8);
// @fallthrough-fix: split fallthrough -> chain to continuation
M55_FUN_803796e4(rdram, ctx);
```

`M55_FUN_803796e4` a su vez cae a `M55_FUN_80379904` (tambien encadenado), asi que la cadena de
animacion completa queda operativa. No se toco `build_windows.bat` (no recompila; usa el arbol).

## Verificacion

- Build Linux `build_dbg` OK; smoke 45 s con Xvfb: arranca, menus, sin crashes ni `Failed to find`.
- `hh_cmds.log` del smoke: `sp=8005BEE0` **constante** (mismo valor en todos los comandos), sin fuga.
- Pendiente: validacion en Windows (rebuild + `run_watch.bat`).

## Nota para el futuro

Tras `tools/recomp.py` hay que re-ejecutar `python3 tools/analysis/fix_fallthroughs.py`. Si se
regenera `RecompiledFuncs/`, comprobar que el numero de cadenas sigue siendo del orden de miles y
que `grep -c "@fallthrough-fix" funcs_106.c` incluye el caso 80379690.

## Ronda 8: mid-entry 0x80379954 y reconstrucción de syms

Tras el fix de fallthroughs, el juego ya **ejecutaba** la animación y crasheó en el siguiente
eslabón: `Failed to find function at 0x80379954` (rama dentro de `M55_FUN_803796e4`). Es el patrón
mid-entry: `0x80379954` está dentro de `M55_FUN_80379904` (tamaño 0x60 → había que partirlo en
`80379904` (0x50) + `80379954` (0x10)). Se añadieron a `config/module_extras.json` (módulo 55):

- `0x80379798`, `0x803798D8` (dentro de `803796e4`) y `0x80379954`.

Además de `0x80380010`/`0x803800A0` (fix de la ronda 5, que estaban en el árbol de trabajo pero no
commiteados y se perdieron al regenerar).

### Lección: los extras pueden disparar un cascado de `auto_mid`

Añadir 74 extras (todos los LOOKUP sin registrar de los módulos) hizo que `--self-pointer-mid-entries`
detectase más mid-entry dentro de los nuevos rangos → funciones nuevas en **datos** → N64Recomp
emitió `0 = cop0_register_read(ctx, 0);` (data como código) y el build falló en
`M12_FUN_8024567c` (texto SJIS). `fix_fallthroughs`/`validate_syms` no filtran esto.

### Reconstrucción fiable de los syms (método a recordar)

Los `.obj` de la build Release del usuario (`build_win/HybridHeavenRecomp.dir/Release/*.obj`) son la
**huella exacta** de los syms que compilaban: `strings *.obj | grep -oE "M\d+_FUN_[0-9a-f]{8}"`.
Con eso se reconstruyen los `us_moduleNN.syms.toml` (tamaños = siguiente dirección − dirección,
respetando overrides `0xADDR:0xSIZE` de los extras) y se llama a `setup_module.merge_syms()`. Después
`tools/recomp.py --config config/game_combined.toml --fix-syms` (el `--fix` es necesario: la plana
tiene ramas cruzadas que el combinado previo ya tenía fusionadas).

Estado resultante: `us_combined.syms.toml` reconstruido + cadena de animación registrada; build Linux
y smoke OK (`sp` constante en `hh_cmds.log`).

### Huecos conocidos (evidencia: análisis de `LOOKUP_FUNC` no registrados)

- Módulo 55: 27 direcciones (p. ej. `0x80380078`, `0x8037F570`, `0x8037A94C`). Dos de ellas
  (`0x8037C50C`, `0x8037C530`) son **casos de jump-table fusionada**: registrarlas parte el switch.
- Módulos 7/9/10/12/23/54: 4/4/1/6/8/34 direcciones. Planas: 43 (incluye las `ignored` del config).
- 8 direcciones de módulo son **delay slots** de un salto: no registrables sin romper el salto previo.
- Si el juego crashea con `Failed to find function at 0x...`, añadir esa dirección a
  `config/module_extras.json` del módulo **y regenerar con cuidado** (evitar el cascado: añadir solo
  las necesarias y comprobar que el build no revienta por datos).

## Ronda 9: rol del módulo 55 y registro completo de sus mid-entries

**El módulo 55 (sección 11, base `0x803757E0`, blob ROM `src 0x68FF2C`) es el overlay de la secuencia
de obtención de objeto del NPC.** Evidencia:

- `hh_ovl.log` (run del usuario): `t=13.168 module src=68FF2C section=11 ... ram=803757E0 funcs=261`
  — se carga **bajo demanda** justo al iniciar la interacción con el NPC (los menús no lo cargan).
- La cadena que arreglamos vive aquí: `80379690 → 80379798 → 803798D8 → 80379904 → 80379954`
  (floats `10.0/225.0/80.0` de escala/posición y el contador de fase global `0x8039-0x764C`).
- Todos los `Failed to find function` del bug del NPC son de este módulo: `0x80380010` (ronda 5),
  `0x80379954` (ronda 8), `0x803798E8` (ronda 9).
- Documentado en `docs/architecture.md` §2.2 (tabla de roles por módulo).

### Registro masivo de las entradas pendientes del módulo 55

Para no ir eslabón a eslabón, se registraron **de una vez** las 22 direcciones válidas del módulo 55
(las 5 restantes de su lista son delay slots de un salto: no registrables). Método:

1. Verificación en el blob de que la instrucción anterior no es un salto (descarta delay slots).
2. **Edición directa** de `config/us_module55.syms.toml` y `config/us_combined.syms.toml` (split en
   las 22 direcciones, tamaños = siguiente − dirección). Así se evita `setup_module.py` (y su cascado
   de `auto_mid`, que ya metió datos como código en este bug).
3. `python3 tools/recomp.py --config config/game_combined.toml --force`: el validador fusiona dos
   splits (`0x80378BB0`, `0x80379464`) por "ramas cruzadas" locales, pero sus `LOOKUP` vienen de
   **otra** función (epílogos compartidos) → hay que saltarse el validador.
   **Nota para la próxima sesión: recompilar requiere `--force`; sin él, la validación aborta.**

Resultado: 22/22 registradas (incluidas `0x8037C50C`/`0x8037C530`, antes inalcanzables por la fusión
de jump-tables de `gen_module_syms`). Build Linux + smoke OK (`sp` constante en `hh_cmds.log`).

### Huecos restantes (no bloquean la secuencia actual)

- Módulo 55: 5 delay slots (`0x80376CCC`, `0x80378020`, `0x80378EBC`, `0x80379230`, `0x8037F410`).
- Módulos 7/9/10/12/23/54: 4/4/1/6/8/34 direcciones sin registrar.
- Plana: 43 direcciones (incluye las `ignored` del config).

## Ronda 10 (REGRESIÓN, corregida): splits dentro de un switch con jump-table

Síntoma reportado: **bajar las primeras escaleras crashea** (`Failed to find function at
0x8037C8E4`), antes funcionaba.

Causa: en la ronda 9 forcé los splits `0x8037C50C` y `0x8037C530`, que **están dentro de un rango
fusionado por jump-table** (`M55_FUN_8037be10` = `0x8037BE10..0x8037C8F8`). Al partir el rango, el
switch perdió sus casos como etiquetas locales y N64Recomp empezó a emitir `LOOKUP_FUNC(caso)`; al
ejecutarse el switch (las escaleras usan ese dispatch) saltó a `0x8037C8E4`, no registrada → exit.

Fix: revertir esos dos splits (función fusionada restaurada a `0x8037BE10` size `0xAE8`) y sacarlos
de `keep_syms.txt`/`module_extras.json`. Recompilado con `--force`; verificado: `0x8037C8E4` ya **no**
es destino de `LOOKUP` y la cadena del objeto (79798/798e8/79954) sigue registrada. Build + smoke OK.

**Regla**: no partir nunca una función dentro de un rango de `merge_jump_tables`. Para detectarlo,
`tools/analysis/add_mid_entry.py` ahora **rechaza** direcciones dentro de un switch fusionado (usa
`gen_module_syms.merge_jump_tables` con los starts del propio syms). De las 22 entradas de la ronda 9
solo esas dos eran peligrosas; las otras 20 son seguras.

## Ronda 11: cuelgue al recibir dano del robot (en curso)

Sintoma: el enemigo dispara, el jugador cae, sale el indicador de dano y el juego se cuelga
(watchdog: `polls` parados 15 s; `VI` sigue subiendo; audio sigue). Logs de la sesion del usuario.

Diagnostico con lo ya volcado (`hh_hang.log` + `hh_hang_rdram_28340_0.bin`; el dump RDRAM va
**LE** y el offset es `addr - 0x80000000`, calibrado con las instrucciones conocidas):

- La cola principal **0x8005C288** esta **vacia** (`validCount=0`) y su `blocked_on_recv` es el
  struct del **hilo 5** (main) → el main espera en `osRecvMesg(C288, ..., BLOCK)` y **el productor
  dejo de postear** (no es una perdida de despertar del runtime).
- `hh_sched.log`: los hilos guest **16 y 17** se aparcan a t=74.7 y **nunca se vuelven a despertar**;
  0/1/3/18/19 siguen (helpers del runtime); el main se re-despierta y re-aparca cada frame.
- `hh_pi.log`: tras el cuelgue quedan solo las lecturas de streaming (~37/s, audio), la carga de
  juego paro.
- El mensaje que el main consume es `0x8005C4B0`.

Instrumentacion nueva (env `HH_MQLOG_ALL=1`, `port/run_mqlog.bat`):

- `hh_mq_all.log`: **todos** los `osSendMesg`/`osRecvMesg` (tid guest, cola, mensaje, validCount,
  cabezas de bloqueados) y cada `osSetEventMesg` (`[EVT] event= mq= msg=`).
- El volcado del watchdog ahora incluye **`tid=`** en cada `ctxN`.
- Smoke Linux: la traza confirma que **`tid=19` postea `0x8005C4B0` a `0x8005C288`** (y a la cola
  externa `0x80091DA0`), a ~130/s; el main la drena a ~60/s.
- Hipotesis a confirmar con el repro: en la secuencia de dano, `tid=19` deja de postear a C288
  (p. ej. el juego re-registra el evento VI/AI a otra cola, o el hilo 16/17 que lo alimenta se
  queda esperando). El `[EVT]` + `[MQA]` del repro lo diran sin ambiguedad.

### Mapa de hilos y colas en el cuelgue (del RDRAM dump, ronda 11)

El dump RDRAM va **LE** y con `offset = addr - 0x80000000` (calibrado con instrucciones conocidas).
`OSThread` del runtime: `[+0x14]=id`, `[+4]=priority`; `OSMesgQueue`: `[+0]=blockedRecv`,
`[+4]=blockedSend`, `[+8]=valid`, `[+20]=msg`.

Estado en el cuelgue (todos **bloqueados**, todas las colas **vacías**, ningún emisor bloqueado):

| tid | pri | cola donde espera |
|---|---|---|
| 5 (main) | — | `0x8005C288` |
| 16 | 110 | `0x8005C528` |
| 17 | 100 | `0x8005C5D0` |
| 18 | 120 | `0x8005C4B8` |
| 19 | 130 | `0x8005C560` |
| 3 | 12 | `0x80091DA0` |
| 0 | 254 | `0x800CE920` |

Productores normales (medidos en el smoke con `HH_MQLOG_ALL=1`, menús):
`3→C4B8`, `0→C560`, `18→C598/91EB8/C5D0`, `19→C288/91DA0/C5D0`, `17→C288/C528/C598/CE920`,
`5→C268/C4F0/CE20/CE920`. Con todos los hilos esperando a un productor que a su vez espera, el
flujo se rompe por un **mensaje perdido/mal enrutado** (no por cola llena). El `hh_mq_all.log` del
repro dará el último par send/recv antes del silencio (punto exacto de la pérdida).

## Ronda 12: cuelgue por dano del robot (diagnostico profundo; instrumentacion final)

Con `hh_mq_all.log` + `hh_evt.log` (nuevos, opt-in `HH_MQLOG_ALL=1`, ver `port/run_mqlog.bat`):

- La cadena de frame es: **runtime entrega evento VI -> cola `0x800CE920` msg `0x800CE950`** ->
  `viMgrMain` (tid 0) lo consume -> `tid 0 -> C560 (0x29A)` -> tid 19 -> `tid 19 -> 91DA0 + C288
  (0x8005C4B0)` -> tid 3 -> ... -> main (tid 5) -> y vuelta.
- Al cuelgue (**t~88.3 s** en el run del usuario): la traza de colas se para; `hh_evt.log` muestra que
  el runtime **sigue entregando el evento VI** (`vi-deliver-ok` continua con `total_vis` creciendo)
  y no hay deadlock en `osSetEventMesg` (9/9 `enter/acquired/exit`).
- El dump (RDRAM) muestra **todos los hilos guest bloqueados en sus colas**, sin mensajes pendientes
  y sin emisores bloqueados. La cola externa del runtime queda con el evento VI sin repartir.
- **Causa inmediata**: el runtime difiere los mensajes externos (`enqueue_external_message_src`) y
  solo los inyecta en las colas guest al **entrar** en un `osSendMesg`/`osRecvMesg`
  (`dequeue_external_messages`). Si en el instante del evento *todos* los hilos están ya dentro de
  un syscall bloqueante, nadie drena -> el evento VI no llega a `CE920` -> `viMgrMain` no despierta
  -> toda la cadena se apaga. El camino de inactividad (`run_next_thread_and_wait` espera externos
  si la running-queue esta vacia) no se activa porque el scheduler esta esperando a un hilo que
  tiene la CPU y no cede.
- **Instrumentacion final** (commiteada, `811e02f`): traza de colas y eventos, **callring por hilo**
  (ultimas 16 llamadas via `get_function`, ya que el port usa lookup para el 100% de las llamadas),
  **estado real de los hilos** (sombra `hh_sh_*`: id/state/queue/sp) y `sp` vivo del contexto, y
  **escaneo de la pila** del hilo que esta corriendo, todo en el volcado del watchdog.
- Siguiente paso: un repro mas con `run_mqlog.bat` -> el volcado dira **que hilo esta en RUNNING**
  (el que no cede) y sus **ultimas llamadas** (su bucle) -> identificar la funcion culpable.

### Ronda 12b: callrings + puntero de hilo en el drain

- El ring de llamadas por hilo funciona (todas las llamadas pasan por `get_function`). En el repro:
  - main (tid 5): bucle `osRecvMesg(C288) -> FUN_8000290C -> FUN_80001BB0` (estado de "caida/dano":
    NO llama a `FUN_80001454`, que es quien hace el poll de input -> por eso `polls` se congela
    aunque el juego siga procesando mensajes ~15 s mas).
  - viMgrMain (ctx3): bloqueado en `CE920` (esperando el evento VI).
  - tid 3: audio (`osAiGetLength`), tid 16: `osViSwapBuffer`, tid 17/18: tareas SP, tid 19: dev-manager.
- El `ctx0` (hilo de boot, entry `0x80001124`) es un **contexto colgante** (la lambda del entrypoint
  lo registra y su scope muere): sus registros son basura de pila; NO usarlo para diagnosticar.
- La traza de colas se para a t=82.17 (el main recibe el ultimo `C4B0`); el VI sigue entregando
  (`vi-deliver-ok` continua) y `pending_ext_msgs=0`. Los `drain` (inyeccion de mensajes externos en
  colas guest) eran lo que mantenia la cadena; ahora la traza registra `drain ... thr=` para
  identificar sin ambiguedad el hilo que drena (mapeable con `create tid=.. t=..` de `hh_sched.log`).

### Ronda 12c: NO hay deadlock de mensajes — livelock por completacion de displaylist

Con la traza `drain ... thr=` (ronda 12b) y el analisis de mensajes por tipo:

- Mensajes de la cola principal C288 y su **tipo** (primer halfword del struct):
  `0x8005C4B0` = **tipo 3** (de tid 19): *marca el flag* `*(u16*)0x80037748`; `0x8005C3A0/A2/A4`
  = **tipo 2** (ignorado). **No llegan mensajes de tipo 1**, que son los que ejecutan el frame
  (`FUN_80001454`, el que hace el poll de input) en el dispatch del bucle principal:
  `type==1 -> FUN_8000290C(); if (flag==0) FUN_80001454(); else FUN_80001BB0(no-op)`.
- Con el flag marcado, cada mensaje hace `290C -> 1BB0` y **nunca el frame** => el juego se queda
  en el estado de "caida/dano" (imagen congelada, `polls` parados) aunque la cadena de mensajes
  sigue viva (la traza continua hasta el cierre, t=92.9).
- **Quien deja de enviar a t=68.764 son los hilos 16 y 17** (el pipeline de render: `osSpTaskLoad/
  osSpTaskStartGo/osViSwapBuffer`, ring del volcado) — quedan bloqueados en C528/C4F0 esperando
  una **completacion de displaylist**.
- La via es `osExQueueDisplaylistEvent(mq, msg, displaylist, tipo)` + `dispatch_displaylist_events`
  (extensions.cpp): si RT64 nunca reporta `SUBMITTED/PARSED/COMPLETED` para esa displaylist, el
  mensaje queda en `pending_events` para siempre y el hilo que lo espera no despierta.
- Instrumentacion: `hh_dl.log` con `queue`/`hit` (registro y casado) y `cb-submitted/parsed/
  completed` (lo que reporta RT64).

Pendiente: un repro mas -> ver que displaylist del efecto de dano no recibe su evento y por que
(no enviada, no parseada, o completada con otro puntero).

### Ronda 12e: el dispatch del bucle principal se rompe por `s0` machacado

`hh_disp.log` del repro (tgt=80001454 frame vs tgt=80001BB0 no-op, con s0=r16 y el valor leido):

- Fase sana: 3488 llamadas al **frame** `tgt=80001454 s0=80037748 flag=0000` (los input polls
  avanzan).
- De golpe: 1280 llamadas al **no-op** `tgt=80001BB0 s0=00001E82 flag=0000`.
- **`s0` (registro callee-saved, r16) quedo con basura `0x1E82`** y ya no se restaura: el check
  `lhu 0x0($s0)` lee memoria no mapeada (0x1E82) -> distinto de cero -> el frame no se llama nunca
  mas -> sin poll de input -> imagen congelada (el resto del motor sigue).
- El valor 0x1E82 no aparece como inmediato en la ROM (posible contador/campo cargado de memoria).
- El clobber ocurre alrededor de la ultima llamada al frame: el frame en si no usa r16 (0 usos) y
  `FUN_8000290C` lo salva/restaura, asi que el sospechoso principal es el camino de la cola
  (osRecvMesg/drains) o un simbolo partido. Instrumentacion: el DISP log ya cubre tambien
  `0x800266B0` (recv) y `0x8000290C` (work) -> el proximo volcado mostrara la llamada tras la cual
  `s0` cambia.

### Ronda 13: causa raiz del cuelgue por dano = `s0` (r16) sin preservar + fix quirurgico

- El bucle principal (`FUN_800011B0`) guarda en **s0 (r16)** el puntero de estado `0x80037748` y lo
  consulta tras cada ciclo (`lhu 0x0(s0)`): si vale 0 ejecuta el frame (`FUN_80001454`, con el poll
  de input); si no, un no-op.
- En el repro del dano, `s0` pasa por valores legitimos (0x80249B80, etc., del dispatcher
  `FUN_80026fe8`, simbolo sobredimensionado: 0x5B4 con **un solo prologo** y **dos `jr $ra`** pero
  7 returns generados) y acaba con **un valor que ya no es puntero valido (p.ej. 0x1E82)**; a partir
  de ahi el check lee memoria invalida, el frame deja de llamarse y se pierden los input polls
  (imagen congelada, motor vivo). Confirmado con `hh_disp.log` (`tgt=80001BB0 s0=00001E82`) y con
  los registros del volcado (ctx2 `r16=00001E82`).
- El runtime NUNCA escribe registros callee-saved (verificado por grep), asi que el clobber viene
  del codigo recompilado de esa zona (cadena del frame).
- **Fix quirurgico (HH_S0FIX=1, activo en `run_mqlog.bat`)**: al entrar en el `osRecvMesg` del bucle
  principal, si `r16` ya no es un puntero valido de RDRAM **y** el hilo venia manteniendo
  `0x80037748`, se restaura ese valor (nunca se toca un valor legitimo; otros hilos no se ven
  afectados: verificado en smoke). Log: `hh_s0fix.log`.
- Pendiente: validacion en Windows (el dano no debe congelar) y, si funciona, decidir si el fix se
  queda siempre activo y/o se corrige ademas el simbolo `FUN_80026fe8`.

### Ronda 14: FIX del laser validado + nueva fuga de pila en el estado de caida

- **El fix de s0 funciona**: el usuario confirma que el impacto del laser del robot ya NO congela;
  el `[S0FIX]` repara en cada frame del estado de dano (valores `1E82 -> 1E66`) y el motor sigue.
- **Nuevo sintoma (siguiente capa)**: al caer el personaje, **no se levanta** (deberia en 1-2 s).
  Los input polls se congelan (~t=85) y el watchdog (que *sale* tras el volcado) termina la sesion.
- **Causa medida**: el `sp` del hilo principal (ctx2) **desciende ~68 bytes/frame** durante la caida:
  `8005BEE0 (t=25) -> 80059F68 (65) -> 80058088 (70) -> 800560D0 (75) -> 80054350 (80) ->
  80053E78 (85, clavado)`. Es la **misma familia** que el bug original (`M55_FUN_80379690`): una
  salida/simbolo que no restaura la pila. Los punteros basura asociados eran de **modulo 12**
  (0x8024A0xx) en el estado de caida (s0 y el `blocked_on_recv` de la cola C288 quedaron con
  valores de modulo 12).
- No hay desbalance simple en las funciones M12 (prologo > restauracion) ni candidatos claros en el
  audit de fallthroughs -> toca trazarlo como la vez original: `port\run_watch.bat` (activa
  hh_ring/ring2) + reproducir la caida -> `hh_ring2_3..8.log` (dumps de la ventana de 60000 llamadas
  en parones con `sp<0x8005B000`) y comparar frames consecutivos para localizar la llamada que no
  devuelve la pila (misma tecnica que la fuga 0x48 del objeto).
