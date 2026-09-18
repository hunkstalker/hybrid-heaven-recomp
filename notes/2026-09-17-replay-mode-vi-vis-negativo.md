# 2026-09-17 — Replay: bug de `mode=vi` (vis negativos), ruta real con `mode=poll`+stride 2, freeze reproducido y sensibilidad a la cuantización de tick

> Corrección de método sobre `2026-09-17-bizhawk-replay-freeze-con-rafaga.md` y continuación del
> diferencial. Detectado al revisar por qué el par port↔emulador "divergía" en sitios imposibles.

## 1. BUG del replay en modo `vi`: los `vis` negativos del relleno dejaban la muestra 0 fijada

`bizhawk_to_replay.py --vis-offset -100` escribía `vis = frame - 100`; el relleno inicial
(frames 0..10573) producía **vis negativos**. El port lee el campo como `uint64_t` y en `mode=vi`
avanza la muestra con `<= VI`: un vis negativo vale ~2^64 ⇒ el bucle **nunca avanza** ⇒ `idx=0`
para siempre. Es decir: **las pasadas `mode=vi` iban sin input** (attract/demo con input neutro).

- Confirmación: arranque del port con `primer_vis=18446744073709551516` (= -100 como u64).
- Consecuencia: el "freeze con el replay de BizHawk" de la pasada `bizhawk1` (VI=32122) era un
  **freeze del attract sin input**, no del CaC; las cargas #1-48 "1:1" con el emulador eran el
  attract (independiente del input).
- Arreglo: el conversor clampa `vis = max(0, vis)` (los samples del relleno son neutros).
  Regenerado `hh_replay_off100.txt`. Para el diferencial, usar **`HH_REPLAY_MODE=poll` + stride 2**
  (indexado por tick; no depende de los `vis`).

## 2. La ruta REAL del mantenedor = `mode=poll` + `--stride 2`

`hh_replay_stride2.txt` = 1 muestra por tick (19274; sample i ↔ frame BizHawk 2i). El port reacciona
al START (frame 10659) con las cargas #36-42 (s≈5354), hace la transición #43-53 (s≈5596-5603 ↔
frames 11192-11206, encaja con el VI 11309 del `state.log` original) y la cadena #54-74 (s=5713-5718).
El `[M24]` (nuevo, `HH_M24LOG=1`: cnt30/g2/d00/cfc/ce4 + muestra por VI) reproduce la secuencia del
original: cnt30 `0..63` y después el módulo recargado sobre `0x801D8xxx` (código `10410009…`) en
s=5714 (frame 11428) — el original lo tiene en frame 11474 (**transición del port ~50-100 frames
antes**; es su deriva de tick).

## 3. Freeze reproducido (ruta real) y sensibilidad a la cuantización de tick

- Pasada base #1 (`mode=poll`+stride 2, sin gates, **con el emulador stride2 corriendo en paralelo**
  = contención de CPU): **polls congelados en 15266** (VI≈30923, frame ≈30532 = entrada del CaC,
  como el freeze del mantenedor en Windows: polls 14051/VI≈30300). tid5 sigue enviando tasks
  (`[SUBM]`) pero no pide input; el watchdog principal no volcó (se bloquea al recorrer contextos) →
  añadido **watchdog mínimo RAM** (`hh_hang_ram.log`, vuelca RDRAM sin locks) y el volcado RDRAM
  pasa a hacerse *antes* de los contextos. Evidencia: `bizhawk3/consola_freeze_15266.log`
  (el snapshot `hh_state.log` t=515.3 se perdió al truncarlo la pasada siguiente: copiar SIEMPRE al
  detectar el cuelgue).
- Pasada **`HH_VI_EVERY=2`** (entrega del evento VI al guest 1 de cada 2 VI → el bucle de juego en
  2 VI/tick): **completó todo el replay (s=19273) sin colgarse**.
- Pasada base #2 (misma config que #1, **sin contención**): **también completó el replay**.
- ⇒ El freeze es **intermitente** (1 de 3 pasadas idénticas; la #1 con el emulador en paralelo).
  No es un deadlock determinista: es una **carrera sensible al timing** (cuantización de tick y
  jitter de carga). La tasa media apenas cambia entre pasadas (29,5-29,6 polls/s; VI/poll ≈ 2,03);
  lo que cambia es el **patrón** (2 VI/tick vs 1,88-2,09). Coherente con que el original marque
  2 VI/tick por carga y con que el entorno real del mantenedor (RT64 nativo + WASAPI + carga del
  sistema) tenga más jitter (freeze allí ~100%).
- Hipótesis de trabajo: el cuelgue lo dispara un camino del juego cuyo resultado depende del
  *instante de tick* (los waits por `osGetTime` y los contadores de 30 Hz del módulo 24); con el
  tick a 2 VI exactos (como el N64) el camino no se toma.

## 4. Estado del diferencial (corregido)

- El emulador con `hhinput.so` consume ~1 muestra por poll (~29-30/s) ⇒ con la grabación original a
  60 muestras/s hay que darle el **stride 2** (frame-indexado), no la de 60.
- Con stride 2 el emulador reproduce el `state.log` original **bit-exacto** en VI 28000/30000/32000
  (`10410009 AFB90010 8D02002C E7A80020 24190001`), pero **diverge en la transición**: hace la
  ráfaga `00B7BAF0…` (#54-66, VI 12188-12233) que el original no pudo hacer (su región M24 ya es
  código desde 11474) y recarga el módulo en VI 13306 (port/original: ~11426-11473).
- El **port sí coincide con el original** en la muerte de la región M24 y en la secuencia de cargas
  de la transición. Para el tramo post-transición la referencia válida es el `state.log` original.

## 5. Siguiente

1. **Validar `HH_VI_EVERY=2` en Windows (mantenedor)**: es el candidato a fix (fidelidad de tick,
   no de tasa). El port headless ya completó la ruta del CaC con el flag; falta ver si en el
   entorno real (RT64/WASAPI, donde el freeze es ~100%) desaparece. Requiere arrancar el port con
   `HH_VI_EVERY=2` (env) en una partida hasta el CaC.
2. Si funciona, convertir el gate en fix de verdad: el original entrega 60 VI/s y el juego marca
   tick cada 2 VI *por carga*; hay que garantizar la misma cuantización (2 VI) con fase estable y
   slips a 3 VI sólo cuando el trabajo no quepa (como el N64), sin alterar la semántica del guest
   más de lo necesario.
3. Si no funciona, inducir el cuelgue de forma estable en headless (carga/afinidad de CPU para
   reproducir el jitter del entorno real) y capturar el volcado RAM en el instante (ahora hay
   watchdog mínimo que sí vuelca) para localizar el camino del juego implicado.
4. Seguir comparando port↔original por tick con la traza `[M24]` (ya disponible) y con dumps
   disparados por **muestra** (`HH_DUMP_CNT30` ya existe; añadir `HH_DUMP_SAMPLE` si hace falta).

## 5b. CAUSA RAIZ LOCALIZADA Y FIX: el FIFO del AI (Audio Interface) no era fiel

Con la ruta del mantenedor grabada (`work/debug/cac/win_rec/cac_rec.txt`, 9317 ticks, 356 s) y
pacing fiel (`HH_REPLAY_PACE=1`, espera al `t` de cada muestra):

- **Control del cuelgue**: con **dispositivo de audio** (WASAPI en Windows; `SDL_AUDIODRIVER=dummy`
  headless) el port se cuelga en **polls=9317** con volcado **98,5% identico** al de Windows (solo
  difieren buffers de audio `0x800Axxxx`/scratch). Con **cola virtual** (`HH_NOAUDIO=1`) NO se cuelga
  y en los mismos ticks su estado es **identico al emulador** (canonico): `0x8024AAF8+0x1C=801CB71C`,
  `dir[0]=803757E0`, sin veneno.
- **Primer desvio**: en `0x800CBB28` (cola de eventos del motor, productor `FUN_800207D0`) el camino
  con audio tiene un evento pendiente (`0x3DB`) y ejecuta **6 cargas extra** de scripts
  (`0004EC80@801B8600`, `0004ED20`, `0004EE10`, `0004EF20`, `00054860`, `00054910` en s=2121/2998/
  4689/6246/8261/8621) que el camino canonico no pide. Es la **progresion de modulo disparada por el
  motor de audio** (nota 2026-09-13-ucode-audio-gate-transicion) que el HLE del emulador no hace
  igual. A partir de ahi: estados M12 (`...0x802425F4`) → puerta M10 (`0x8022CA90`, flag
  `0x8017DD92=0`) → `M55_FUN_80379410(a1=1)` → `FUN_800058dc` escribe `0xFFFF84CD` en
  `0x8024AAF8+0x1C` (watch `HH_WATCH_ADDR=0x8024AB14`: entre s=9300 y s=9310) → el juego recorre el
  objeto con callback centinela (no-op) → tid5 esperando en `0x8005C288` → **[HANG]**.
- **Causa**: el subsistema AI del runtime no emulaba el hardware. `osAiGetStatus` devolvia 0 fijo
  ("los DMA terminan al instante"), el evento AI se encolaba **cada VI incondicionalmente**
  (`events.cpp`) y `osAiGetLength`/`get_frames_remaining` reportaba `min(cola SDL, 1 VI)` (cap) en
  vez del **DMA actual**. La cola SDL real podia crecer (retraso audible, el mantenedor lo noto) y al
  pasar de 1 s se **descartaban buffers** (petardeo). Ese "length" falso + eventos ficticios son lo
  que hacia que el driver de audio del juego y su motor de eventos progresaran distinto que en
  hardware.
- **Fix** (`HH_AI_FIFO`, por defecto ON; `=0` revierte): emulacion del AI como hardware en
  `ultramodern/src/audio.cpp` — FIFO de 2 buffers (actual + pendiente), `osAiGetLength` = restante
  del DMA actual (`frames = dur - (now-start)`), y el evento AI se entrega solo al **completar** el
  buffer (nuevo `hh_ai_fifo_poll()` llamado desde el hilo VI). Los samples se encolan a SDL al
  **arrancar** cada DMA (no al submitirse) -> la cola del dispositivo queda <=2 buffers (~33 ms), sin
  deriva ni descartes.
- **Resultado headless**: con `HH_AI_FIFO=1` + dispositivo, la ruta queda **canonica** (0 cargas
  extra, estado identico al emulador en s=9300/9310) y **no se cuelga** (polls 11168 > 9317 sin
  centinela ni [HANG]). Pendiente: validacion en Windows (audio sin petardeo/retraso + CaC sin
  cuelgue) y, si hiciera falta, completar `osAiGetStatus` con el estado real del DMA.
- **Control del cap** (`HH_AI_FIFO=0 HH_AI_QUEUE_REPORT=full`, dispositivo): 43 cargas, **0 cargas
  extra** en s>=2100 y sin centinela en el tramo medido -> sin el cap, la emulacion antigua **no**
  tomaba la ruta divergente en este replay (su sintoma era el frenado con huecos). El cap era el
  *disparador practico* de la ruta mala, no el defecto de raiz.

### 5c. Validacion Windows (2026-09-18, build con FIFO por defecto) — el cuelgue PERSISTE en vivo

- Sesion del mantenedor jugada a mano con la build que **si** incluye el FIFO (verificado por
  strings `HH_AI_FIFO`/"FIFO lleno" en el exe, 00:53:41 > ultima edicion de audio.cpp 00:47:49):
  **audio petardeando y freeze en el CaC** (`[HANG]`, polls congelados ~9620, firma `[BADMQ]` +
  centinela `FF7F84CD`, `r4=8024A990`).
- `hh_audio.log` de esa sesion: la cola SDL se mantiene **estable y pequena** (`queued=720-992`)
  -> el **retraso creciente esta arreglado**; pero el juego produce **~26k frames/s** frente a los
  43,2k del dispositivo -> **underrun** (el petardeo). El mismo deficit aparece en el run headless
  con FIFO (26k) que **no se cuelga** -> el deficit de produccion **no** es el disparador del
  cuelgue; es un problema de timing del audio pendiente (siguiente: ajustar lo que se le reporta al
  driver para que vuelva a producir 60 x 720 frames/s, p.ej. un offset en `osAiGetLength`, y dejar
  una cola de seguridad de ~2 buffers en el dispositivo).
- **Conclusion**: el FIFO corrige el camino identificado (ruta canonica en el replay grabado) pero
  la sesion EN VIVO sigue divergiendo -> queda un factor dependiente del tiempo real/dispositivo
  que el replay headless no captura.
- **Sesion en vivo #2 grabada con el FIFO** (`win_rec2/cac_rec.txt`, 9342 ticks, 360 s; el log
  imprime `[AI ] FIFO del AI activo`): se cuelga (mismo veneno en `0x8024AAF8+0x1C`, `r4=8024AAF8`,
  `dir[0]=802746A8` -> misma ruta divergente). Su **replay headless con FIFO** (mismo input, mismo
  pacing) queda **canonico** (0 centinelas, `0x801CB71C`/`803757E0` en s=9300/9340). Es decir: el
  desvio en vivo necesita algo mas que el replay no captura (jitter real/juego en vivo).

### 5d. Arreglo del pipeline de audio (produccion y latencia) — `[AIF]`

Traza nueva `[AIF]` (con `HH_AUDIOLOG=1`) en el FIFO: los submits muestran que el driver envia
**3 buffers de 720 frames por ciclo de ~53 ms** (43,2k frames/s, correcto) pero el FIFO solo
mandaba a SDL **1 buffer por arranque de DMA** -> el dispositivo recibia ~14-26k (underrun,
petardeo), y ademas la longitud reportada hacia que el driver produjese de menos. Dos arreglos:

1. **Al dispositivo va todo lo enviado**: `queue_samples` se llama en cada submit
   (`queue_audio_buffer`), no al arrancar el DMA. El modelo FIFO (longitud DMA actual + evento al
   completar) queda solo como lo que ve el juego.
2. **Cola acotada (watermark)**: `support.cpp` descarta el buffer entrante si la cola SDL supera
   `HH_AI_MAX_MS` (150 ms por defecto) en vez de 1 s -> el desajuste de reloj juego<->dispositivo
   (~0,8% medido) ya no acumula retraso.

Resultado headless (120-140 s, replay en vivo #2): `frames/s=43.3-45k` (coincide con 43.2k),
`queued` entre 720 y ~6300 frames (<=150 ms) sin quedarse a cero. Pendiente: validacion de oido en
Windows + idealmente sincronizar la tasa para eliminar los descartes periodicos del watermark.

### 5e. Replay en Windows: el pacing perdia por granularidad de `sleep_for`

Primera prueba del replay de la sesion en vivo EN WINDOWS (`run_cac_replay.bat`, grabacion #3,
misma build): el personaje acaba "contra una pared" y no reproduce la sesion. Comparando los
`hh_state.log` (replay vs sesion viva, mismo input y misma grabacion): a t=350 s la viva iba por
**polls=9109** y el replay por **7796** -> el replay corria a **22,3 ticks/s** cuando la grabacion
iba a **26/s**.

Causa: `std::this_thread::sleep_for` en Windows tiene granularidad ~15,6 ms; el pacing
(`HH_REPLAY_PACE=1`, input.cpp) pedia sleeps de 5-10 ms que dormian ~15 ms -> el tick se estiraba
~5-10 ms cada vez -> el input caia en otro instante real -> ruta distinta. En Linux (nanosleep) el
pacing es exacto y por eso el replay headless si sigue la grabacion.

Fix: espera hibrida en el pacing (dormir el grueso y **girar** el tramo final ~3 ms) +, sobre todo,
**`timeBeginPeriod(1)`** al arrancar en Windows (`main.cpp`, enlaza `winmm`): sin subir la
resolucion del timer, `sleep_for` pide 5-10 ms y duerme ~15,6 -> el tick se estira ~11 ms y el
replay corre a ~20,5 ticks/s en vez de ~24-26 (medido: a t=100, poll 2052 vs 2389 muestras de la
grabacion). Verificado headless (1304 polls a t=60 vs 1312 de la grabacion).
**Pendiente: recompilar en Windows y repetir el replay** -> si ahora sigue la sesion y se cuelga
al final, el entorno Windows es reproducible con el replay y el factor que queda se aisla
comparando con headless; si sigue sin cuelgue, el factor es la interaccion en vivo.
(El `hh_crash.log` de las pasadas de replay es el SEGV de cierre al cerrar la ventana, no un crash
de juego.)

Nota aparte: el replay corrio 800 s (sobrevivio al punto de cuelgue de la grabacion); tras
acabarse las muestras el ultimo input se repite -> "contra la pared". A t~800 s crasheo
(`hh_crash.log`, C0000005, VI=48133) en esa fase sin input (a investigar por separado).

### 5f. El replay en Windows va WORK-BOUND (no era el sleep): falta margen de 30/s

Con `hh_pace.log` (nuevo, 1 linea/s) en el replay de Windows: a partir de t~9 s
`llegadas_tarde=100%` y el retraso **acumula sin limite** (0,7 s a t=10 -> **13,9 s a t=170**),
mientras los ticks corren a 21-27/s. Es decir: el port **no puede seguir la cadencia de la
grabacion** (el trabajo por tick en Windows es ~40 ms frente al presupuesto de 2 VI = 33,3 ms del
original). El `sleep` no es el problema (los `late_max` por tick son del orden del retraso
acumulado, no spikes de 15 ms); el problema es que el port va por debajo de 30,0 ticks/s.

Evidencia cruzada: en Linux headless (llvmpipe) el mismo binario hace ~29-30 ticks/s con solo
1-2 ticks de 3 VI por segundo (medido con el nuevo `hh_tick.log`); en Windows live ~24,9/s (con
logging) y en replay ~22,5/s -> hay ~4-7 ms/tick de trabajo de mas respecto al presupuesto.

Herramientas nuevas para perfilarlo en la maquina del mantenedor:
- `hh_tick.log` (siempre, 1 linea/s): cuantizacion de tick `d1/d2/d3/d4+` y `max_dt`.
- `run_pacing.bat profile` / `run_cac_profile.bat`: `HH_DIAG=1` + `HH_TRACE=0x80001454:frame,0x80005270:disp`
  + `HH_AUDIOLOG=1`, consola a fichero. Deja `hh_trace.log` (t= de frame/disp -> periodos reales),
  `hh_rsp.log` (tiempo de las tasks de audio) y `profile_console_*.log`.

Siguiente: perfilado en Windows con `run_cac_profile.bat` y atacar el mayor coste por tick
(objetivo: 0,50 ticks/VI = 30,0/s con audio a 60/s), sin parches de replay. Con el margen
recuperado el replay deberia seguir la ruta por si solo.

### 5g. Pacing del replay: por VI (reloj del juego) + PLL de fase; el de pared rompia la rejilla

Perfilado limpio en Windows (`run_cac_profile.bat`, sin `HH_DIAG`):
- **Live**: 30 ticks/s con `d2=29 d3=1` (~5% slips) -> la cadencia live esta practicamente bien;
  el 27/s con 30% de d3 de la pasada anterior era artefacto de los logs pesados de `HH_DIAG`.
- **Replay** (misma grabacion, pacing por pared): `d2=0-4 d3=18-20` -> **todos los ticks a 3 VI
  (50 ms)** -> 20 ticks/s y desfase acumulando (7,6 s a t=93). Causa: el pacing de pared espera la
  marca `t` en el poll (punto intermedio del tick); ese plus empuja el tick (que ya va justo de
  margen) fuera de la ventana de 2 VI -> 3 VI -> y en bucle. Es un problema de *anclaje*, no de
  trabajo: el live hace 30/s con la misma build.

Fix: **`HH_REPLAY_PACE=vi`** (nuevo, por defecto en `run_cac_replay.bat`): espera a que el contador
VI alcance el `vis` grabado -> el tick queda alineado con la MISMA rejilla VI que la sesion
original. Detalles:
- **Offset con signo** `vi_off = cur_vi_0 - vis_0`: el boot del replay puede terminar en MENOS VI
  que el de la sesion original (28-118 vs 111 en las pasadas); con offset 0 el primer tick
  esperaba de golpe ~1,3 s (visto en `[PACE]` y `hh_pace.log`).
- **PLL suave**: ajusta `vi_off` +-5 VI/s segun el desfase de pared (`late_avg`) hasta converger
  (~500 ms -> 7 ms en headless; `adj=0` estable).
- Headless: ruta canonica (44 cargas), `d2=22 d3=5-6` (~28 ticks/s) y `hh_pace.log` convergido.

Pendiente: validar en Windows (rebuild + `run_cac_replay.bat`): `hh_tick.log` debe pasar de
`d3=18-20` a `d2` dominante y la ruta debe seguir la grabacion (y el veneno, si procede).

### 5h. CONCLUSION del pacing: la solucion correcta es `HH_REPLAY_MODE=vi` (input como funcion del VI)

Datos que cierran el asunto (2026-09-18):
- `hh_pace.log` con desglose: en headless el tick es **dominado por esperas** (`wait_avg~32ms`,
  `work_avg~4ms`): el port marca su compas por VI y el trabajo real es minimo. Los problemas de
  cadencia del replay eran de *anclaje* del pacing, no de trabajo.
- Con `mode=poll` (1 muestra por tick) CUALQUIER slip del port **acumula** desfase: el input deja
  de corresponder al instante del juego (medido: 65% de ticks a 3 VI -> 15 s de retraso -> ruta
  distinta y no determinista entre pasadas).
- Con **`HH_REPLAY_MODE=vi`** (la muestra se elige por el contador VI: `vis_i <= VI_actual`) el
  input es funcion del reloj del juego y **se auto-corrige**: los slips saltan/duplican muestras
  como en la sesion original. Headless: `d2=28-29 d3=1-2` (**30 ticks/s**, igual que el live
  limpio) y ruta canonica (43 cargas). Sin pacing ni PLL (innecesarios).
- `run_cac_replay.bat` queda con `HH_REPLAY_MODE=vi` y `HH_REPLAY_PACE=` (vacio). **No requiere
  rebuild** (el binario ya soporta el modo); con las grabaciones nativas no hay vis negativos.

Pendiente: validar en Windows (replay completo hasta el CaC): `hh_tick.log` debe mostrar `d2`
dominante (como el live) y la ruta debe seguir la grabacion.

### 5i. Fase 1 del suavizado: instrumento de ticks lentos (`hh_slow.log`)

Objetivo del plan (aprobado 2026-09-18): que el port cumpla el presupuesto del original (30,0
ticks/s = 2 VI/tick, 60 Hz de refresco) eliminando los tirones *del port*; los hitches autenticos
del juego (descompresion de modulos) se mantienen.

Instrumentacion (always-on, ligera; solo se escribe cuando el tick pasa de 36 ms):
- `events.cpp`: timer de `send_dl` (procesado de la display list en el hilo de gfx) y de
  `update_screen` (present), expuestos por `hh_gfx_last_send_dl_ms()`/`hh_gfx_last_update_ms()`.
- `input.cpp` (hh_tick.log): al detectar `dt > 36 ms` escribe a `hh_slow.log`:
  `t dt dvi send_dl update_screen pending_ext`.
- Headless (attract): primer tick con `send_dl=876 ms` (warm-up de pipelines de RT64; hitch de
  arranque esperado), siguientes `dt=44-54ms` con `send_dl=5-8ms` y `update_screen=0.0ms` -> en
  llvmpipe el coste gfx es modesto; el resto del dt es juego/esperas.

Siguiente: pasada del mantenedor con `run_cac_profile.bat` (rebuild) para ver en Windows de que
esta hecho cada tick lento (send_dl vs update vs resto) y atacar el mayor. Objetivo medible:
`hh_tick.log` con `d2=30/30` y `max_dt<=35 ms` en gameplay.

Contabilidad de tiempo guest anadida (`threads.cpp`/`mesgqueue.cpp`): `hh_busy_end/start` marcan
fin/inicio de slice en los puntos de bloqueo (modelo single-CPU: un hilo guest a la vez) y
`hh_guest_busy_ms()` acumula el tiempo ejecutando. `hh_slow.log` incluye `guest_busy=<ms de este
tick>`.

Primeras medidas (headless, llvmpipe): los ticks lentos (~45-50 ms) tienen **`guest_busy≈38-40 ms`**
(el codigo guest se come casi todo el tick; incluye TODOS los hilos guest: logica, audio, etc.) +
`send_dl=5-8 ms` (display list en el hilo gfx, que la logica espera). El primer tick del boot:
`send_dl≈880 ms` (warm-up de pipelines RT64). El trabajo de la task de audio es 0.1 ms (descartado).
=> El cuello restante es **trabajo guest** (logica + auxiliares del runtime) y, en menor medida, el
`send_dl`. Siguiente: medir el reparto en Windows y, si es guest-bound, muestrear el PC guest
(histograma) para localizar las funciones calientes.

## 6. Prueba en Windows (protocolo, 2026-09-17)

Preparada para el mantenedor. El runtime local (rama `hybrid-heaven`, HEAD 948279f + cambios sin
commitear) ya trae `HH_VI_EVERY`; `build_windows.local.bat` compila el árbol local, así que **hay
que recompilar** antes de la prueba.

1. Build: `port\build_windows.local.bat` (Release).
2. Pasada PRUEBA: `port\run_pacing.bat tick2` (añade `HH_VI_EVERY=2`; recoge logs a
   `logs_pacing_<fecha>\`). Jugar normal hasta entrar en combate cuerpo a cuerpo (los cuelgues
   previos: ~8,5 min de partida, al entrar al CaC).
3. Si se cuelga: esperar ~20 s (watchdog) y cerrar la ventana; enviar la carpeta de logs
   (`hh_state.log`, `hh_hang.log`, `hh_hang_ram.log` y `hh_hang_rdram_*.bin` si aparecen).
4. Si NO se cuelga: seguir un rato en el CaC y valorar si algo va raro (tirones a 15 fps, audio,
   swaps de framebuffer) — el flag cambia la entrega del evento VI al guest (30 Hz), no la tasa de
   refresco de pantalla.
5. Control opcional: una pasada con `port\run_pacing.bat` (sin flag) para comparar el mismo día.
