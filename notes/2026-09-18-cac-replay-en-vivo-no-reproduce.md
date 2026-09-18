# 2026-09-18 — CaC: el replay en vivo no reproduce el freeze (resultados negativos) y plan de determinismo

> Continúa `2026-09-17-bizhawk-replay-freeze-con-rafaga.md` y `2026-09-17-replay-mode-vi-vis-negativo.md`
> (§3-§5: freeze intermitente en headless, ~100% en vivo; `HH_VI_EVERY=2` lo evitaba en headless).
> Objetivo de la ronda: validar `HH_VI_EVERY=2` en vivo y reproducir la ruta real con una grabación nueva.

## 1. `HH_VI_EVERY=2` NO arregla el cuelgue en vivo

- `port\run_cac_tick2.bat` (mantenedor, Windows): **freeze en el CaC**, igual que sin el flag.
  VI≈19269 / polls≈9052; firma idéntica (ver §2).
- `port\run_cac_record.bat` (sin flag): freeze en VI≈19568 / polls≈9243.
- ⇒ Descartado `HH_VI_EVERY=2` como fix en el entorno real (sí evitaba el cuelgue en headless, así que
  la fidelidad de cuantización **no** es el disparador en vivo).

Firma del cuelgue (idéntica en ambas): `tid=5` parado en `osRecvMesg` sobre su cola `0x8005C288`;
objeto con callback envenenado `0x8024AAF8 + 0x1C = FFFF84CD` (el emulador mantiene `80135320`).
Evidencia: `logs_pacing_20260918_155825/` (record), `logs_pacing_20260918_160416/` (tick2).

## 2. `HH_REPLAY_PACE=vi` es contraproducente

- Probado en Windows (`run_cac_replay.bat`): **tirones y spam de consola** (busy-wait + logs del PLL).
- Revertido: `run_cac_replay.bat` vuelve a `HH_REPLAY_MODE=vi`, `HH_REPLAY_PACE=` (vacío), con
  comentario explicando por qué.

## 3. La grabación en vivo NO se reproduce

Grabación nueva del mantenedor: `logs_pacing_20260918_155825/cac_rec.txt` (9243 muestras, vis 33→18611,
que es la ruta real hasta el CaC).

- **Windows** (`run_cac_replay.bat`): no pasa de la **2ª puerta**, acaba andando contra una pared.
- **Headless** (mi repro, `HH_REPLAY_MODE=vi`): consume las 9243 muestras y **no se cuelga**; sigue
  andando (la última muestra se repite).
- **Headless con `HH_REPLAY_CLOCK=1`** (reloj esclavo de la muestra): **tampoco** se cuelga.
- `[PACE] primer ciclo: cur_vi=34 vis0=33 off=1` ⇒ el **offset de arranque del VI es ~1**, no es un
  problema de alineación.

⇒ El cuelgue es **solo en vivo** ahora mismo, y la **fidelidad del replay** para grabaciones en vivo
está rota. Hipótesis (a confirmar): (a) **no-determinismo** del port dependiente del tiempo real
(`osGetTime`, waits/contadores de 30 Hz del módulo 24, RNG); o (b) desajuste en la semántica
grabar/reproducir. La intuición del mantenedor (golpes de enemigos no reproducibles) apunta a (a).

## 4. Plan A (recomendado): recuperar la fidelidad del replay

1. **Test de determinismo**: reproducir el mismo replay (o un tramo corto) dos veces y comparar RDRAM
   en una muestra fija (`HH_DUMP_SAMPLE`). Si las dos pasadas **coinciden**, el replay es determinista
   y el problema está en la relación **vivo↔replay** (tiempo/RNG/orden de input); si **no** coinciden,
   hay no-determinismo en el propio port.
2. Según lo anterior: aislar la fuente de tiempo (`osGetTime`/timers) y/o el punto exacto donde el
   input deja de corresponder al tick.
3. Solo con repro fiable tiene sentido el diferencial port↔original por tick.

## 4b. FUENTE DE TIEMPO NO DETERMINISTA (encontrada) y cambio aplicado

`ultramodern/src/timer.cpp`: con el reloj de replay activo (`HH_REPLAY_CLOCK=1`), `osGetTime`/`osGetCount`
interpolaban con **tiempo de pared real**:

```cpp
uint64_t wall = time_now();  // high_resolution_clock
int64_t extra = (int64_t)((double)(wall - hh_replay_wall) * hh_replay_rate);
return hh_replay_time + extra;
```

=> el valor que lee el juego depende de *cuándo* lo lee (jitter real) → **no determinista**.

**Cambio aplicado**: interpolación **determinista por VI** (`extra = (VI_actual - VI0) * 781250`), que
es como avanza el tiempo en el N64. `hh_replay_vi0` se fija al aplicar cada muestra.

**Resultado (headless, `mode=vi + clock=1`)**: el replay **sigue sin colgarse** (llegó a VI 22601 con
el objeto aún sano). Pendiente:
- **Validar determinismo** (dos pasadas → mismo RDRAM en una muestra): la 2ª pasada se quedó atascada
  en el arranque (probable residuo de un `kill -9` previo) → repetir en limpio.
- **`osSetTimer` sigue usando `time_now()` real** (y el hilo de timers): si el juego usa timers, queda
  otra fuente de no-determinismo. Extender el reloj determinista a los timers.
- Confirmar si el freeze requiere el entorno vivo (RT64/WASAPI) y no se da en el replay determinista.

## 4c. Test de determinismo (hecho) — la lógica es determinista; el freeze no depende de ella

Dos pasadas idénticas del mismo replay (`mode=vi + clock=1`), volcado en la muestra **3000** (VI 5984)
y **9000** (VI 18126). El volcado cae en el **mismo VI** en ambas pasadas (comparación válida).

- **Estado lógico IGUAL**: `0x80037748` (bucle), `M24.g2`/`cnt30`, `0x8024A990`, `0x8024AAF8+0x1C`,
  directorio `0x8008DFC4` — idénticos.
- Diferencias globales ~8-9%: **casi todo en framebuffer** (RT64) y **heap alto** (asignaciones/render),
  no en lógica. `stack` y `objetos`: diferencias mínimas.
- **Ninguna de las dos pasadas se cuelga.**

⇒ (1) El replay es **determinista en la lógica**; el ruido es de render/asignaciones. (2) El freeze
**no depende de la lógica del replay**: no se reproduce ni con reloj determinista. Refuerza que el
freeze es **sensible al entorno/tiempo real** (RT64/WASAPI, jitter) y no un camino puramente lógico.

**`osSetTimer` no es la fuente**: el juego no lo usa (no aparece en `RecompiledFuncs/`; `osGetTime` sí).

## 4d. Implicación y siguiente

- **Aclaración del mantenedor (importante)**: el "entorno vivo" **no** es un obstáculo inevitable; se
  puede jugar esquivando a los enemigos de forma que no entorpezcan la ruta. Es decir, la divergencia
  **no** es por RNG de IA (los golpes son evitables), sino por **timing/jitter** del entorno (RT64/
  WASAPI, cuantización de tick). El objetivo de un replay fiel sigue siendo alcanzable.
- Grabar otra pasada desde cero **sí tiene sentido** con los arreglos actuales: una partida **limpia
  (sin golpes), con el reloj determinista** ya aplicado. La grabación antigua se hizo con el port
  work-bound (pre-fix `get_function`), así que su input pudo quedar desalineado.
- Alternativa de diagnóstico en paralelo: instrumentar el vivo (`HH_WATCH_ADDR=0x8024A9AC` +
  `HH_MQLOG_ALL`) para cazar quién escribe `FFFF84CD` y **por qué** el vivo toma ese camino.

## 5. Plan B (si A se atasca): atacar el cuelgue en vivo

- Con los volcados del cuelgue real (`hh_hang_rdram_*`) y la cadena del setter ya documentada
  (`notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md`), usar en vivo `HH_WATCH_ADDR=0x8024A9AC`
  (+`HH_MQLOG_ALL`) para cazar **quién escribe `FFFF84CD`** en la sesión real y **por qué** el vivo
  toma ese camino.

## 6. Evidencia de la ronda

- `logs_pacing_20260918_155825/` (record; `cac_rec.txt`, `hh_hang*`), `logs_pacing_20260918_160416/` (tick2).
- `logs_replay_20260918_163714/` (replay Windows que divergió en la 2ª puerta).
- Headless: `/tmp/opencode/repro_cac.log` (`mode=vi`, sin cuelgue), `repro_clock.log` (`clock=1`, sin
  cuelgue); dumps `build_dbg/work/debug/port_vi2040 0..20800.bin` (diferencial previo, port ~9600 VI
  por delante del emulador para el mismo estado M24).
- Cambio de repo: `port/run_cac_replay.bat` (documentado; vuelto a `PACE=`).
