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
