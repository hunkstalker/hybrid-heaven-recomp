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
