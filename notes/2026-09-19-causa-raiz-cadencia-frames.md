# 2026-09-19 (noche-3b) — Causa raíz probable: cadencia de frames (1 vs 2 VI/tick)

> Continuación directa de `2026-09-19-verificacion-cadencia-y-harness-replay.md`. Esta nota **corrige
> el foco**: el "port ~20 s adelantado" era un artefacto compuesto; la divergencia real del front-end
> es la **cadencia de frames**. Ahora hay un camino de fix concreto y coincide con lo que ya apuntaba
> `2026-09-17-replay-mode-vi-vis-negativo.md` §3/§5.

## 1. Hechos verificados (re-ejecutados esta sesión)

- El port ejecuta `FUN_80001454` a **~58/s · 1,03 VI/frame**; el emulador a **~30/s · 2,0 VI/frame**.
- El bucle `FUN_800011b0` (funcs_0.c:2569) espera en la cola `0x8005C288` y decide:
  `[0x80037748]==0` → `FUN_80001454` (frame); `!=0` → `FUN_80001BB0` (no-op). `[0x80037748]` lo pone a 1
  el mensaje de **tipo 3** (`L_80001428`).
- **En el port `[0x80037748]` nunca pasa a 1** en 12 s (`hh_flag.log` vacío; **0 `[NOOP]`**) ⇒ el port
  **siempre** ejecuta la rama frame ⇒ 60 frames/s en vez de 30.
- **Nacimiento del objeto de transición `0x801D0474`** (`M23_FUN_801c1508`):
  - Port normal: **vi 218** (gframe 185).
  - Port `HH_VI_EVERY=2`: **vi 328** (gframe 150).
  - Emulador: **vi 347** (gframe ~173; `emu_create.log`: `BP 0x801C144C`, `a0=0x801D0474`,
    `a1=0x801C1508`, `vi_count=347`).
  ⇒ Con la cadencia corregida (2 VI/frame), el objeto nace casi donde el emulador (**328 vs 347**).
- `HH_VI_EVERY` existe en el runtime (`ultramodern/src/events.cpp:371`) y ya estaba identificado el
  2026-09-17 como **candidato a fix** (§3: el port completó el replay sin colgarse con el flag).

## 2. Por qué el "20 s" y el "#12 en vi 1535" eran un artefacto

- La grabación es **0,5 muestras/VI** (9815 muestras / 329 s). El port en `HH_REPLAY_MODE=poll` la
  consume a esa tasa; el emulador consume **1 muestra/poll a ~0,9-1,0 polls/VI** ⇒ **~1,8-2× rápido**
  (verificado: `[in] ctl=0` ~51-58/s; `idx=600` con 599 llamadas).
- Al aplicar el START de menú (vis 209-213) en un VI equivocado, el director de escena del emulador
  se lo pierde/enreda: #12 pasa de `vi 1535` (original) a `vi 2959` (`cac_pad163`) a "no llega"
  (`cac_dup` stride 2). Es una referencia **inestable**.
- **Experimento vis-fiel**: replay de 1 muestra/VI (estado mantenido por `vis`,
  `work/debug/replays/cac_vi1_20260919.txt`). Con él, el emulador **se cuelga y no llega a #12**: su
  START (vis 209) cae **antes** de que exista el objeto (emu vi 347). El port, en cambio, sí
  transiciona (objeto vi 218 y START en ventana) ⇒ la diferencia real es el **adelanto del objeto**,
  no los 20 s.

## 3. Causa raíz probable y camino de fix

1. El runtime entrega los eventos/tick de forma que el bucle principal del port **no toma nunca la
   rama no-op** (`[0x80037748]` no se pone a 1). Resultado: frame a 60/s y todo lo gobernado por
   frames del front-end ocurre en la mitad de VI.
2. `HH_VI_EVERY=2` (entrega del evento VI al guest cada 2 VI) **corrige la cadencia** y acerca el
   objeto al emulador, pero es un **diagnóstico global** (bajaría el frame en todo el juego).
3. El fix correcto (ya descrito en `2026-09-17-replay-mode-vi-vis-negativo.md` §5.2): garantizar la
   cuantización del tick del original (**2 VI/tick**, como el N64, con slips a 3 VI cuando el trabajo
   no quepa) sin alterar la semántica del guest.

**Siguiente paso concreto**: localizar por qué el port no recibe/procesa el mensaje de tipo 3 de la
cola `0x8005C288` (quién lo publica —probable retrace/VI— y comparar con el patrón que espera el
ROM). El runtime reimplementa `osSendMesg`/`osRecvMesg` (`ultramodern/src/mesgqueue.cpp`), así que es
el primer sospechoso. Log útil: `HH_LOG("[MQ] osSendMesg …")` filtrando la cola `0x8005C288`.

## 4. Advertencia de método

El emulador **no es una referencia válida** para este replay (consumo poll-indexed y sensibilidad
extrema al padding). Para comparar, o se le da un harness vis-fiel de verdad, o se usa el `state.log`
original del mantenedor (como en la nota 09-17) y el propio replay del port en modo `vis`.

## 5. Trazado de la cola `0x8005C288` (2026-09-19 noche-3c)

Con `HH_MQLOG_ALL=1 HH_MQLOG_MQ=0x8005C288` (log `hh_mq_all.log`) y `hh_evt.log`:

- **Consumidor**: el bucle principal, **tid 5** (thread `0x80059D80`), hace `recv-block`/`recv-ok` en
  `mq=0x8005C288`.
- **Productor**: **tid 19** (thread `0x8005C678`) hace `send mq=0x8005C288 msg=0x8005C4B0`
  (siempre el mismo mensaje). En senders: `funcs_0.c` (~0x80001800/0x80001824) llama a
  `FUN_80000EC8(0x8005C4B0)`.
- El bucle lee el "tipo" como **`[0x8005C4B0]`** (`lh v1, 0(t9)`, `t9` = mensaje recibido): 1 →
  frame/no-op; 2 → loop; 3 → pone `[0x80037748]=1` (`L_80001428`). En el port **nunca es 3**.
- El **evento VI del runtime va a OTRA cola** (`vi-deliver-ok … mq=800CE920 msg=800CE950`), no a
  `0x8005C288`; es decir, el bucle de frames **no** espera directamente al evento VI.
- Nota de instrumentación: con `HH_MQLOG_ALL` el juego se frena (I/O); no usar las tasas del log como
  absolutas. El queue `0x8005C288` se ve llenarse (valid sube) en rachas → confirmar con traza ligera.

**Siguiente acción concreta**: instrumentar el **valor y los cambios de `[0x8005C4B0]`** (y quién lo
escribe) con una traza ligera (no `HH_MQLOG_ALL`), y comparar con el emulador el **patrón de tipos** de
ese mensaje. Candidato: el productor (tid 19) debería emitir el tipo 3 con la cadencia del original
(1 de cada 2) y en el port no lo hace. Alternativa: comparar el `state.log` original del mantenedor
(nota 09-17) para el tramo del front-end, que es la referencia que sí es fiel.

## 6. Cadena completa verificada (2026-09-19 noche-3d)

Con `HH_WATCH_ADDR=0x8005C4B0 HH_WATCH_SIZE=4` (`hh_watch.log`) y `addr2line` sobre el binario:

- El "tipo" que decide frame/no-op vive en el halfword de **`0x8005C4B0`** (en el port, por el
  word-swap, se accede al host `0x5C4B2`). **Se escribe siempre 1** (nunca 3) ⇒ el port nunca toma la
  rama no-op.
- Lectores del tipo: el bucle principal (`FUN_800011b0`, 656 accesos) y **`FUN_8001fba8`**
  (686 accesos) — este último es un hilo que recibe de la cola `0x80091DA0` y procesa tipos
  1/3/0x20; es el **productor** que publica en `0x8005C288` (tid 19).
- **La raíz está en la entrega del evento VI del runtime** (`ultramodern/src/events.cpp:364-392`):
  por defecto entrega `OS_EVENT_VI` **cada VI** (60 Hz). El comentario del propio código lo dice: el
  original entrega 60 VI/s y el juego marca tick cada 2 VI; el port, al recibir el VI cada vez,
  publica el frame cada VI. `HH_VI_EVERY=2` (línea 389) lo parchea globalmente.
- ⇒ **El fix correcto** es garantizar la cuantización **2 VI/tick** con fase estable (y slips a 3 VI
  si el trabajo no cabe), como describe `2026-09-17-replay-mode-vi-vis-negativo.md` §5.2 — no el
  `HH_VI_EVERY` global (bajaría el frame en todo el juego).

**Siguiente paso concreto**: auditar la ruta ROM `osCreateViManager`/`viMgrMain` → `retrace_count`
(el ROM está recompilado) y por qué en el port se satisface cada VI; comparar con el N64. El punto a
tocar es la entrega/contabilidad del retrace en `events.cpp` (`load_vi_regs`/`update_vi`) para que el
propio juego marque 2 VI/tick, sin alterar la semántica del guest.

## 7. Validación en Windows (2026-09-20): `HH_VI_EVERY=2` **NO arregla el freeze**

Prueba del mantenedor con `port/run_cac_tick2.bat` (en vivo, RTX 4080, WASAPI), banner
`[VI] HH_VI_EVERY=2 activo` confirmado:

- Jugó hasta la zona del combate y **se congeló** (no softlock) en **VI=20829** (polls 15 s).
- Consola: **veneno** `Failed to find function at 0xFF7F84CD`, caller `r4=8024AAF8`;
  `[S0FIX] r16 00000000 -> 80037748` (fix de `s0` activo); corrupción de colas
  `[BADMQ] fields mq=80000000 valid=54525960`, `[BADMQ] osSendMesg mq=00040000/C0000830`.
- ⇒ **El tick a 2 VI no cura el CaC**. La hipótesis "la cadencia de frames es la causa" queda
  **refutada como fix** (el adelanto del front-end es real pero **ortogonal** al freeze: en vivo el
  jugador marca el ritmo, no el front-end).
- Coincide con `notes/2026-09-19-veneno-capturado-bug-signo-extension.md` §8: el disparador son los
  **stalls/alineación frame↔VI** del hilo de juego (RT64/WASAPI/I/O), no el reloj ni la entrega del
  tick. `HH_VI_EVERY=2` alinea la entrega del evento VI pero **no** evita que un frame abarque 3 VI
  por un stall real.

**Reorientación**: el fix de raíz es **alinear frame↔VI con compensación de stalls** (que cada frame
abarque 2 VI pase lo que pase: limiter que reanude en la rejilla VI, o desacoplar los stalls), como
dice la nota del veneno §8/§9. `HH_VI_EVERY` no es la vía.

**Datos a analizar del run**: `logs_tick2_20260920_012011/` (Windows) — `hh_hang.log` (contextos de
hilo en el cuelgue), `hh_state.log`, `hh_slow.log` (`guest_busy`/`dvi`), `hh_s0fix.log`.

## 8. Análisis de los logs de la validación en vivo (2026-09-20)

Carpeta `port/HybridHeavenRecomp/build_win/bin/Release/logs_tick2_20260920_012011/`:

- **`hh_tick.log`**: con `HH_VI_EVERY=2` el juego corre a **~30 ticks/s con `d2=27-30`** (2 VI/tick) —
  el tick **sí** queda cuantizado — con stalls aislados (`d4+=1`, `max_dt≈66 ms`) cada ~10 s. Aun así
  **se cuelga** ⇒ **el tick no es la causa del freeze** (refuerza §7).
- **`hh_venom.log`**: **12 venenos**. Cadena idéntica a la ya documentada:
  `M10_FUN_8021b280 → M10_FUN_8022c7a4 → … → M55_FUN_80379410 → FUN_800058dc`, con
  `obj=0x8024AAF8`, `cb=0xFFFF84CD` (`a3=0x801BBBF0`, `a2=0x801BC23A`). El objeto queda con callback
  inválido.
- **`hh_badlookup.log`/`hh_missing.log`**: `Failed to find function at 0xFF7F84CD` con
  `r4=8024AAF8` (`s0+0x1C=FF7F84CD`); el port resuelve a **no-op** ⇒ el objeto **no avanza**.
- **`hh_hang.log`**: en el cuelgue `VI=20829`, **9 hilos bloqueados en `osRecvMesg`**; el bucle
  principal (**tid 5**, `ctx2`) espera en `0x8005C288` (`r20=8005C4B0`, `r21=80037748`), y la cadena
  de productores (tid 19 → `8005C560`) está también bloqueada ⇒ **deadlock de colas** causado por el
  objeto de transición atascado (callback inválido).
- `[S0FIX] r16 00000000 -> 80037748` ×3 (se vuelve a corromper `s0`); `[BADMQ]` con punteros basura
  (`mq=80000000`, `valid=54525960`), coherente con el `s0` corrupto.

**Conclusión**: el bloqueo final es el **disable (veneno)** — el objeto `0x8024AAF8` recibe
`cb=0xFFFF84CD` (que el emulador **nunca** instala) y el port no puede ejecutarlo, atascando el
scheduler. El tick y la cadencia del front-end son ortogonales.

**Siguiente paso (recomendado)**: (1) comparar las **variables de la puerta** del disable
(`0x188`/`0x181`/timer `0x42D0`/`0x42FF`) port↔emu en el mismo instante con `HH_B280TRACE`;
(2) revisar la **cadena M7/M10 recompilada** por si la puerta abre por un **fallthrough perdido**
(`fix_fallthroughs.py`, ADR 0002) y no por timing; (3) usar como referencia fiel el `state.log`
original del mantenedor (nota 09-17).

## 9. Causa del disable: el SCHEDULER DE EVENTOS TEMPORIZADOS del juego (2026-09-20)

**Punto 2 (fallthroughs): descartado.** La cadena M7/M10/M55 del veneno está **correctamente
encadenada** (verificado en `port/.../RecompiledFuncs`: `M7_FUN_80126a0c→80126a18`,
`M7_FUN_801267b8→801267c0`). Los 31 "fallthroughs sin encadenar" que reporta el script son de
libultra y en su mayoría falsos positivos; ninguno en la cadena del veneno.

**Punto 1 (la puerta), reproducido headless** con `HH_GATE_A=1 HH_B280TRACE=1` (replay completo):

- La puerta `M7_FUN_80126A0C(a0=0x8024C934, a1=0x39, a2=1)` se llama **16 veces**; #1–#12 → `ret=0`;
  **#13 → `ret=1`** con `42D0=0x2B88`, `181=01`, `188=0`; y en `vi=20012`/`sample=9803` corre el
  instalador y se captura el veneno. Artefacto: `build_dbg/hh_b280.log`, traza en
  `/tmp/opencode/port_gate_full.log`.
- **El emulador NUNCA llama la puerta con `a1=0x39`**: en `work/debug/emu_gate_run.log` solo aparece
  con `a1=0x113`/`0x74`, y el instalador `0x8021B240` tiene **0 ejecuciones**.
- ⇒ **La divergencia está aguas arriba**: no es el valor de la puerta, es que el emulador **no dispara
  el evento que llama a la puerta con 0x39** (el instalador `M10_FUN_8021b240`).

**Qué es `42D0`** (`[0x8008D580]`): un **acumulador de tiempo del scheduler de eventos temporizados**
del juego, no un contador por frame simple:

- `FUN_80001454` (frame) lo **resetea a 0** (`sw zero, 0x42D0`) al inicio de cada frame.
- `FUN_80004bb0` (scheduler) lo **acumula** recorriendo las entradas temporizadas:
  `[0x42D0] = [0x42D0] + v1 + s3 - s2 + [0x42BC]` (tiempos lógicos de las entradas).
- La nota §4 ya sospechaba que el llamante de `M10_FUN_8021b240` viene por `FUN_80004BB0`; encaja:
  **el evento que instala el disable es un evento temporizado del scheduler**, y el port lo dispara
  cuando el emulador no.

**Siguiente paso concreto**: localizar la **entrada del evento `M10_FUN_8021b240`/0x39 en la lista del
scheduler** (`FUN_80004bb0`: tabla `0x800429B8 + id*4`, lista `0x42F4`, tiempos `0x42CC`/`0x42BC`) y
comparar su **tiempo/disparo** port↔emu (o con el `state.log` original del mantenedor). Ahí está el
origen del timer que cruza el umbral.

## 10. Cadena de instalación de callbacks del CaC (análisis estático, 2026-09-20)

La cadena del disable es una **secuencia de callbacks encadenada** por el propio setter
`FUN_800058dc(obj, handler)` (escribe en `obj+0x1C`/`+0x18`/`+0x20`):

1. **`M10_FUN_8021b1A8(obj)`** (0x8021B1A8): hace `FUN_800058dc(obj, 0x8021B200)` →
   **instala `M10_FUN_8021b200`** como callback del objeto.
2. **`M10_FUN_8021b200(obj)`** (0x8021B200): `FUN_80016E40(0x36FC0)` (crea/temporiza una tarea del
   scheduler) y `FUN_800058dc(obj, 0x8021B240)` → **instala `M10_FUN_8021b240`**.
3. **`M10_FUN_8021b240(obj)`** (0x8021B240): `M7_FUN_80126A0C(obj, 0x39, 1)` (**la puerta**); si
   devuelve 1 → `FUN_800058dc(obj, 0x8021B280)` → **instala el disable** (veneno).
4. **`M10_FUN_8021b280(obj)`** (0x8021B280): `FUN_800058dc(obj, 0xFFFF84CD)` → callback inválido →
   bad lookup → no-op → deadlock.

- Es una **sequencia temporal**: cada paso se dispara cuando el **scheduler
  `FUN_80004bb0`** tickea el objeto/callback. `FUN_80016E40(a0)` crea la tarea temporizada.
- `M7_FUN_80125808` (state machine M7, la que ejecuta la puerta) llama a `FUN_80004BB0` con
  `a0=lhu[sp+0x1A]` y `a1=[0x42C4]` (indexa la tabla `0x800429B8 + id*4`).
- En el **emulador** el paso 3 no se dispara (`M10_FUN_8021b240`: 0 ejecuciones); en el **port** sí.
  La causa dinámica está en los **tiempos del scheduler** (`0x42CC`/`0x42BC`/`0x42D0`).

**Siguiente paso concreto**: instrumentar **`FUN_80004bb0`** (scheduler) en el port —log ligero de
`{a0 (id), a1, entrada/handler, 0x42CC, 0x42BC, 0x42D0}` por disparo— y comparar el **orden/tiempo** de
los callbacks de la cadena (`M10_FUN_8021b1A8 → b200 → b240 → b280`) port↔emu (o con el `state.log`
original del mantenedor). El primer callback de la cadena que se dispara en el port y no en el emulador
(o con tiempo distinto) es el punto de divergencia.

## 11. CAPTURA EN VIVO (Windows) de la cadena: la tarea `0x39` del scheduler (2026-09-20)

Instrumentación `HH_CHAINTRACE=1` (wrappers de `b1A8`/`b200`/`b240` + scheduler `FUN_80004bb0`),
pasada en vivo del mantenedor. Artefactos:
`build_win/.../logs_chain_20260920_025147/{hh_chain.log,hh_sched.log,hh_b280set.log,hh_b280.log}`.

**Secuencia exacta en el port (objeto `0x8024D690`):**

| vi | evento |
|---|---|
| 19123 | `M10_FUN_8021b1A8(obj)` → instala `b200` |
| 19124 | `M10_FUN_8021b200(obj)` → `FUN_80016E40(0x36FC0)` + instala `b240` |
| 19127…19150 | el objeto tickea `b240` cada ~2 VI; la puerta `0x39` → **ret=0** |
| **19152** | **el scheduler despacha la tarea `a0=0x39`** (`FUN_80004bb0(a0=0x39, a1=0x80358820)`) |
| 19152 | `b240` → puerta `0x39` → **ret=1** → `FUN_800058dc(obj, 0x8021B280)` (**disable**) |
| 19154+ | `M10_FUN_8021b280` → `cb=0xFF7F84CD` → bad lookup → no-op → deadlock (VI 20109) |

**Publicación del disable** (`hh_b280set.log`):
```
SET b280 #1 obj=8024D690 a3=00000039
  callring: … 800306C0 80004BB0 801257DC 80125774 800058DC
```
⇒ El **scheduler `FUN_80004bb0`** despacha la tarea `0x39`, que instala el disable. `FUN_80004bb0`
despacha por `0x39` exactamente en `vi=19152`; hasta ese momento la tarea `0x39` no había entrado.

**El emulador no despacha `0x39`** (llama la puerta solo con `a1=0x113`, `0x74`; `b240`/`b280`: 0
ejecuciones). ⇒ **Divergencia = el scheduler del port despacha la tarea `0x39` en el CaC y el del
emulador no.** Es un **evento temporizado/activado por gameplay**, no la cadencia de frames.

**Siguiente paso concreto**: quién **activa/registra** la tarea `0x39` (id 0x39 → `a1=0x80358820`) —
probablemente un evento concreto del CaC (daño/golpe). El único call-site del scheduler es
`M7_FUN_80125808`; rastrear el `lhu[sp+0x1A]` que llega con `0x39` y comparar con el emulador (que no
lo activa). Ahí está el origen del bug.

**Instrumentación ampliada (noche-4)**: wrappers de `FUN_80004d20` (dispatcher de entrada:
`handler`=a0, `target`=a1) y `FUN_80004adc` ("add" del scheduler) → `hh_scheddisp.log`. Capturan
**qué handler** se añade/dispara en cada vi, para ver en el CaC el `add`/`run` del handler de la serie
`0x8021Bxxx` (el que instala el disable). Filtro de arranque verificado headless (677 líneas/20 s).
Pendiente de una pasada en Windows con `port/run_chain_live.bat` (recoge `hh_scheddisp.log`).

## 12. Segunda captura en vivo: el evento `0x39` es un temporizado con deadline `0x3000` (2026-09-20)

Pasada Windows `logs_chain_20260920_030610` (objeto `0x8024C7CC`). Reproduce la cadena (`b1A8` vi
17752 → `b200` 17754 → `b240` tickeando cada ~2 VI → **ret=1 en vi=17781** → disable; `hh_b280set.log`
con el mismo anillo `80004BB0 801257DC 80125774 800058DC`).

**Dato clave** (`hh_sched.log`):
```
[SCHED] vi=17781 a0=00000039 a1=80358820 42CC=00003000 42BC=00002B88 42D0=00000000 42C8=00
```

- La **puerta** compara `[0x42D0] < 0x3001`. Y aquí **`42CC = 0x3000`** ⇒ el umbral de la puerta es
  **el "target" del evento temporizado `0x39` + 1**.
- `42BC = 0x2B88` (11144) es el **tiempo acumulado** del evento; su deadline es `0x3000` (12288).
- Es un **evento temporizado con deadline** (id de lista `0x39`, target `0x3000`, contexto
  `a1=0x80358820`). El port lo despacha en `vi=17781` y la puerta lo acepta (`42D0=0x2B88 < 0x3001`);
  el emulador no llega a despacharlo (nunca llama la puerta con `0x39`).
- `FUN_80004d20`/`FUN_80004adc` no se llaman tras `vi=11421` ⇒ el disable **no** pasa por el
  dispatcher genérico; el anillo real es `FUN_80004BB0 → M7_FUN_801257DC → M7_FUN_80125774 →
  FUN_800058DC`.

**Nota del mantenedor (sin prueba, a verificar)**: el **audio petardea sobre todo en el
menú/intro**; el gameplay lo nota "fino". Anotado por si el evento/estado del CaC está relacionado.

**Siguiente paso**: entender el **registro/deadline del evento `0x39`** (target `0x3000`, id de lista
`0x39`) — quién lo añade a la tabla `0x800429B8 + 0x39*4` y con qué `42BC`/`42CC` — y por qué el
emulador no lo despacha. El fix probable es que el port respete el **deadline** del evento (no
instalar el disable si el `42D0`/target no corresponde), o corregir el registro del temporizado.

## 13. La corrupción de colas es INDEPENDIENTE del disable (2026-09-20, noche-4)

**Verificado (no fiarse del orden de líneas del log: el buffering por hilo desordena la salida):**

- En **headless sin veneno** (0 `FF7F84CD`, p.ej. `port_chain2.log`/`port_badmq.log`) el port **también
  se cuelga** (softlock) con `[BADMQ]` y deadlock. ⇒ La corrupción de colas **no** la causa el veneno.
- En **vivo con `HH_NO_DISABLE=1`** (pasada del mantenedor) aparece `[NO_DISABLE] obj=8024AAF8
  cb=FFFF84CD (escritura ignorada)` y **aun así** hay `[BADMQ]` + deadlock (VI 20109). ⇒ El disable
  **no** es el único ni el verdadero bloqueo (reconfirma la nota 09-17 §6).

**Síntoma medido** (`[BADMQ]` ampliado con `ra`/`sp`): un **mismo hilo** (`sp=8004FB38`, tid 19 en
`hh_hang.log`) llama `osSendMesg(mq=<basura>, msg=0x8005C4B0)` con punteros de cola corruptos
(`mq=80037748`, `00040000`, `C0000830`, `C2C80000`, `3F3851EC`, `80000000`…) y `ra=0` (invocado por
puntero). El mensaje `0x8005C4B0` es el del bucle principal (cola buena `0x8005C288`) ⇒ **el campo
"queue pointer" de una estructura se corrompe**.

**Interpretación**: alrededor del CaC, una estructura del juego se corrompe y el hilo 19 empieza a
mandar el mensaje del frame a punteros basura; el port **descarta** esos envíos (mitigación `[BADMQ]`
en `mesgqueue.cpp do_send`) → hilos bloqueados en `osRecvMesg` → deadlock. Es un problema de
**corrupción de memoria**, anterior y más profundo que el disable.

**Nota del mantenedor (a verificar)**: el **audio petardea sobre todo en el menú/intro**; en gameplay
casi fino. Encaja con que el área del CaC/audio/AI y el scheduler comparten estado.

**Siguiente paso propuesto**: cazar la **escritura que corrompe** el campo de cola de esa estructura:
(1) localizar la estructura del hilo 19 / del mensaje `0x8005C4B0` y su campo "mq"; (2) `HH_WATCH_ADDR`
sobre ese campo para ver el RA que lo pisa; (3) comparar con el emulador (que no se cuelga). Alternativa
más directa: revisar el **módulo M10** (el del CaC) por **data-as-code**/símbolos mal acotados (el
evento `0x39` es de M10).

## 14. Los punteros corruptos son FLOATS y M10 tiene funciones ausentes (2026-09-20)

**Los `mq` corruptos son valores de punto flotante** (`3F3851EC`≈0.72, `40500000`≈3.25,
`C2C80000`≈-100.0, `C0000830`≈-2.0) ⇒ un campo "queue pointer" está siendo **pisado por datos de
física** (coordenadas/velocidades). Es **solapamiento de memoria** apuntando a una **escritura de
float fuera de rango** en una estructura recompilada con offset/tamaño equivocado.

**M10 (módulo del CaC) con funciones stubbeadas / ausentes**: el log de recompilación
(`work/debug/recomp*.log`) marca `Stubbing FUN_…: analysis failed (data absorbed by coarse
boundary?)`. **14 de ellas son de M10** (`FUN_80201a04`, `80202020`, `802032ac`, `80205a04`,
`8020da54`, `80214a50`, `802205e8`, `80220e24`, `80221a40`, `8022397c`, `80223bcc`, `80226368`,
`80242308`, `80245008`). En el árbol del port, **7 están AUSENTES** (`FUN_802205e8`, `80220e24`,
`80221a40`, `80223bcc`, `80226368`, `80242308`, `80245008`) y `FUN_8022397c` solo aparece en
`funcs.h` (declarada sin cuerpo). Total de stubbed en todo el binario: 146.

**Hipótesis de trabajo**: el CaC corre código de M10 mal recompilado (símbolos con fronteras mal
acotadas → datos absorbidos como código → offsets/escrituras erróneas) y pisa la estructura de cola
con floats → deadlock. Encaja con que el problema aparezca **solo en el CaC** (M10) y con que el
disable sea un síntoma más.

**Siguiente paso**: (1) corregir/acotar los símbolos de esas funciones de M10 (ADR 0002,
`config/*.syms.toml`, `0xADDR:0xSIZE`) para que se recompilen; (2) o cazar la escritura con
`HH_WATCH_ADDR` sobre el campo de cola; (3) comparar con el emulador. Nota: el TODO ya tiene
"Data-as-code (189 sospechosas)". **Nota del mantenedor**: audio petardea sobre todo en el
menú/intro (gameplay casi fino).

## 15. Mecanismo del `[BADMQ]`: lista de SUSCRIPTORES `{next, mq}` del event-dispatch (2026-09-20)

El `[BADMQ]` (osSendMesg con `mq` basura) viene del **event-dispatch del juego**:

- **`FUN_80000934(obj, mq, ...)`**: registra un suscriptor — crea un nodo `{next, mq}` (nodo de
  `FUN_800267F0(1)`), hace `[nodo+0] = [obj+0x888]` (next) y `[obj+0x888] = nodo` (nueva cabeza).
- **`FUN_80000A0C(obj, msg)`**: **broadcast** — recorre `s0 = [obj+0x888]`; para cada nodo llama
  `osSendMesg([nodo+4], msg, 0)` (vía `FUN_80026300`); sigue con `s0 = [nodo+0]`.
- ⇒ La **lista enlazada de suscriptores `{next, mq}` en `[obj+0x888]`** se **corrompe**: un nodo recibe
  **floats** en su campo `mq`/`next`, y el broadcast manda el mensaje `0x8005C4B0` a punteros basura
  (`3F3851EC`, `40500000`… = física). El port los descarta (`[BADMQ]`) → el suscriptor real no recibe
  el evento → deadlock.
- Callers del broadcast: `FUN_8000081C`/`FUN_800008BC`/`FUN_800008E8` (funcs_0.c). Objeto del dispatch:
  el del CaC (`0x8024AAF8`/`0x8024D690`), `+0x888`.

**Siguiente paso (fix)**: cazar la **escritura de float** sobre el nodo de la lista (`FUN_800267F0` /
`[obj+0x888]` y `[nodo+4]`) con `HH_WATCH_ADDR`, o revisar el **allocator de nodos** `FUN_800267F0` y
por qué el nodo cae en una zona que se pisa con física (¿estructura mal dimensionada en M10?). Comparar
con el emulador (que no se cuelga).

## 16. Nodo corrupto identificado: `0x8005BF14` (2026-09-20, noche-4)

Con `HH_CHAINTRACE=1` (que ahora activa `[BCAST]`/`[PUSH]`/`[POP]`), reproducción headless del
softlock. El dispatch (`obj=0x8005C4B0`, `msg=0x8005C4B0`, head en `[obj+0x888]=[0x8005CD38]`):

- Normal: `head=0x80095FF8 [node=80095FF8 q=80091DA0] [node=8005BF14 q=8005C288]` (2 suscriptores
  válidos; `0x8005BF14` apunta a la **cola del bucle principal `0x8005C288`**).
- Al final (CaC): `[node=8005BF14 q=80063DF0] [node=8008DA88 q=802521AC] [node=802521E0 …] …` —
  **el nodo `0x8005BF14` se corrompe**: su `q` pasa de `8005C288` a `80063DF0` y su `next` de `0` a
  `8008DA88`; la lista salta a **nodos basura** (`0x8008DA88`, `0x8025xxxx`). Todos los `[PUSH]`
  observados tienen `q` válido (`8005C640`/`8005C608`/`80091DA0`/`8005C288`) ⇒ **el nodo se corrompe
  DESPUÉS de empujarse**, no se empuja mal.
- `0x8005BF14` está en la **pila/estructura del hilo principal** (`sp≈8005BEC8`).
- Intento de watchpoint sobre `0x8005BF14` → **SEGV** (`exit=139`): vigilar un nodo en pila no es
  viable.

**Siguiente paso**: cazar quién pisa `0x8005BF14` sin watchpoint (p.ej. comprobar en `hh_hang_rdram`
el patrón de los nodos basura `0x8025xxxx`; o instrumentar el `[POP]`/`[PUSH]` para volcar `next`/`q`
del nodo recién insertado; o revisar M10 por estructura mal dimensionada). Comparar con el emulador.
