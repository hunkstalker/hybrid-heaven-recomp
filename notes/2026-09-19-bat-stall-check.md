# 2026-09-19 — Lanzador de la vía de los stalls (`run_stall_check.bat` + `stall_summary.ps1`)

> Ejecuta el PENDIENTE de `RETOMAR.md`: un lanzador Windows que arranca el port **en vivo**, recoge y
> rotula los logs de la vía de los stalls y produce un **resumen por tick** (`dvi` / `guest_busy`).
> Objetivo: medir por qué el hilo de juego hace ticks de 3 VI (`guest_busy` ~34 ms, presupuesto 2 VI =
> 33,3 ms) y atacar la alineación frame↔VI. Ver §1 de `2026-09-19-veneno-capturado-bug-signo-extension.md`.

## 1. Qué se ha añadido

- **`port/run_stall_check.bat`** (nuevo): pasada en vivo (sin replay), siguiendo el estilo de
  `run_nodisable_live.bat`. Fuerza modo live (limpia `HH_REPLAY*`, `HH_NO_DISABLE`, `HH_VI_EVERY`,
  `HH_DET_CLOCK`, `HH_TIMESCALE`), activa `HH_STATE_SECS=5` y `HH_FRAMELOG=1`, aparta los `hh_*.log`
  previos a `logs_prev\` y al salir mueve todo a **`logs_stall_<fecha_hora>\`** (incluye consola y
  volcados `hh_hang_*`/`hh_crash_*`). Al final llama al resumen y lo imprime.
- **`port/stall_summary.ps1`** (nuevo): genera **`stall_summary.txt`** en la carpeta de la pasada con:
  - `hh_tick.log`: ticks totales y cuantización `d1/d2/d3/d4+` (con % y aviso si hay 3+ VI).
  - `hh_framelog.log`: **por tick** — `dt`, `dvi` y `guest_busy` (si el binario vuelca los 5 campos;
    si es viejo, deriva `dvi` del contador VI y avisa).
  - `hh_slow.log`: desglose de los ticks >36 ms (min/medio/max de `guest_busy`, `send_dl`,
    `update_screen`, `pending_ext`).
  - `hh_slice.log`: nº de muestras de stall y últimas líneas (contexto de hilo culpable).
  - `hh_state.log`: último snapshot; `hh_hang.log`: cuelgues detectados por el watchdog.
- **`src/game/input.cpp`** (`HH_FRAMELOG=1`): el volcado por tick pasa de 3 a **5 campos**:
  `t_s dt_us vi dvi guest_busy_ms`, con `dvi` = delta del contador VI y `guest_busy_ms` = delta de
  `hh_guest_busy_ms()` en el tick. Cambio gated por la variable de entorno (no afecta al juego normal).
  **Requiere rebuild en Windows** (`port\build_windows.local.bat`).

## 2. Cómo se usa (mantenedor, Windows)

1. Recompilar: `port\build_windows.local.bat` (para el framelog de 5 campos).
2. Doble clic en `port\run_stall_check.bat`.
3. Jugar normal hasta el CaC (o hasta el cuelgue). Si se cuelga, dejar que el watchdog vuelque y
   cerrar la ventana; si no, 2-3 minutos y cerrar.
4. Devolver la carpeta `logs_stall_<...>` (basta `stall_summary.txt` + los `.log`; los `.bin` son
   volcados de RDRAM/DMEM del cuelgue, solo si hacen falta).

## 3. Estado

- Compila en Linux (`cmake --build port/HybridHeavenRecomp/build_dbg -j8`) con el cambio de `input.cpp`.
- Los regex del resumen validados contra las líneas exactas que emiten `input.cpp` y `main.cpp`.
- **Smoke headless** (25 s, `HH_FRAMELOG=1`): `hh_framelog.log` sale con las 5 columnas
  (`0.0000 0.2 21 0 0` y después `t dt_us vi dvi busy`). Ejemplo de la pasada (no representa Windows):
  915 ticks, `dvi` d1=416/d2=485/d4+=11, `guest_busy` medio 18,7 ms.
- **No probado en Windows** (no disponible en esta sesión): validar al lanzarlo que aparece
  `stall_summary.txt` y que el framelog tiene 5 columnas.

## 4. Primera pasada en Windows (mantenedor, 2026-09-19 08:55) — RESULTADOS

Artefactos: `build_win/bin/Release/logs_stall_20260919_085554/`. Partida en vivo hasta el CaC:
**congela antes del combate** (hang a VI=18250, polls y audio 15 s parados; 12 venoms; consola en bucle
`Failed to find function at 0xFF7F84CD` del objeto `0x8024AAF8` + `[BADMQ]` con mqs corrompidos).

Cadencia (287,9 s, 8565 ticks, 29,83 ticks/s):

- `d1=165 (1,9%)  d2=8135 (95%)  d3=264 (3,1%)  d4+=1` · max_dt=86,1 ms.
- `hh_framelog`: dt medio **33,53 ms**, dvi d1=164/d2=8159/d3=263/d4+=1; `guest_busy` medio
  **33,2 ms**, y **34,4 ms** en los ticks de 3+ VI (n=264).
- `hh_slow` (>36 ms): n=192, d3=191; `guest_busy` 34,8 medio; `send_dl` 2,81 medio (5,9 máx);
  `update_screen` 0; `pending_ext` máx 1.
- Por minuto: el minuto 0 va a 30,2 ms de busy / 32,0 ms de dt; **desde el minuto 1 el tick queda
  clavado en busy≈33,5 / dt≈33,7** (≈100 % del presupuesto de 2 VI = 33,33 ms).

Control dev (mismo build Linux, replay `cac_rec.txt` con `HH_REPLAY_MODE=poll`, 75 s headless):
29,70 fps, dt med 33,62 ms, busy med 34,00 ms, d2=1853, d3=0, d4=42 ⇒ la ocupación es del bucle de
juego, no de la ventana/audio.

### Lectura

- No son parones puntuales: **cada frame roza/llena el presupuesto de 2 VI** (<1 ms de margen). Los
  ticks de 3 VI (3,1 %) son deslizamiento de fase; acumulan ≈4,4 s de VI perdidos en 288 s, que
  desplazan las esperas por `osGetTime` de la línea temporal M24 frente al emulador → puerta
  `M7_FUN_80126A0C`/`M10_FUN_8021b240` → veneno.
- El callring de los stalls (tid=5) muestra el bucle
  `osGetTime (80031190) → __ll_* (80026F58/80026E58/80034C24/80034AB8)`, que es el **frame limiter del
  juego (`0x80001A88`) busy-waiteando** (mismo lead que el `spin_yield` del otro port). El grueso del
  `guest_busy` es ese *pacing*, no necesariamente cómputo útil: el problema no es "falta CPU" sino
  **dónde cae el cierre del limiter respecto a la rejilla VI**.
- `send_dl` (2,8 ms) y `update_screen` (~0) quedan descartados como causa principal.

### Pasada `det` (`HH_DET_CLOCK=1`, 09:43) — NEGATIVO

Artefactos: `logs_stall_20260919_094327/`. **Congela igual** (12 venoms, `Failed to find 0xFF7F84CD`
en consola; watchdog sin `hh_hang.log` por cierre temprano del mantenedor).

- 440 s, 13290 ticks: `d1=2,2%  d2=94,8%  d3=3,0%  d4+=0,4%`; dt medio 33,48 ms; `guest_busy` medio
  33,1 ms (3+ VI: 34,2, n=405) ⇒ **idéntico a la pasada normal** (`d3≈3%`, busy≈presupuesto).
  `send_dl` medio 3,06 ms (máx 57,1 ms puntual); `update_screen` 0.
- ⇒ El origen del reloj (`osGetTime` VI-anclado) **no** cambia la cuantización ni evita la ruta:
  descartado también en vivo. El desfase no viene de la derivación del tiempo, sino de **dónde cae el
  cierre del frame limiter** (o de la propia espera de escena) respecto al VI.

## 5. Siguiente paso — experimento "ruta del emulador" (`HH_NO_B280`)

1. **`HH_NO_DISABLE`** (ignorar solo la escritura del sentinel) **no basta en vivo** (probado).
   ⇒ Se implementa un paso **aguas arriba**: `HH_NO_B280=1` en el wrapper de `FUN_800058dc`
   (runtime NMR, `librecomp/src/overlays.cpp`, sin commitear): ignora la **publicación del handler
   `0x8021B280`** → `M10_FUN_8021b240` corre pero `b280` **nunca se instala ni se ejecuta**, que es la
   conducta del emulador (contralado: 0 ejecuciones de `b280`/`M55` con el mismo input).
2. **Validación**: `port\run_stall_check.bat nob280` (en vivo, donde el freeze es ~100 %): si **entra
   al combate sin colgar**, la ruta del disable es el bloqueo real y queda además una salida jugable
   provisional; si **sigue colgando**, la divergencia dominante está aguas arriba (espera de escena del
   loader #12, colas `0x8005C4F0/C268`) y el fix es el timing de la transición.
3. En paralelo, pasada headless de control (`HH_REPLAY_MODE=poll` + `HH_NO_B280=1`): confirmar 0 venoms
   y ausencia de hang; artefactos en `work/debug/nob280/`.

### Resultado headless `HH_NO_B280` (run1, mismo replay `cac_rec.txt`) — POSITIVO PRELIMINAR

`work/debug/nob280/run1/` (410 s, se corta por `timeout`, no por hang):

- `[NO_B280] obj=8024C934 handler=8021B280 (publicacion ignorada)` ×20 (cap de log) ⇒ el gate se
  abrió como siempre, pero el handler **no se instaló**.
- **0** `Failed to find function at 0xFF7F84CD`, **sin `hh_venom.log`**, **sin `hh_hang.log`**.
- El juego sigue tras el replay: último snapshot **t=415 s, VI=24919, polls=12205** (`pending_ext=0`,
  audio vivo) — muy por encima de los VI de freeze (20710/20949/26992).
- Cadencia (headless): d1=0,8 % **d2=97,0 %** d3=0,0 % d4+=2,2 % (en headless el d3≈3 % de Windows no
  aparece; no es comparable).
- *Cautela*: el freeze headless ya era intermitente (~1/3). La validación decisiva es **en vivo**
  (`run_stall_check.bat nob280`), donde congelaba ~100 %.

### Primer intento en vivo (10:03) — INVALIDO: el flag no estaba activo

Artefactos: `logs_stall_20260919_100339/`. Congeló (VI≈17425) y **volvieron los 12 venoms** →
se comprobó que **el hook no se ejecutó**:

- `[NO_B280]` no aparece en la consola; `hh_venom.log` con 12 entradas (la publicación sí ocurrió).
- El `.exe` de Windows **sí contiene el hook** (`NO_B280`, "publicacion ignorada"; build 08:03) y el
  `.bat` con el argumento `nob280` estaba en disco desde las 07:54.
- ⇒ La pasada se lanzó **sin el argumento `nob280`** (doble clic = modo normal): el `.bat` no deja
  rastro del modo en los logs, así que no era auditable.

**Corrección para no repetirlo**:
- `port/run_stall_check.bat` ahora escribe una **cabecera en `stall_console_<fecha>.log`** con
  `modo=... HH_DET_CLOCK=... HH_NO_B280=...` (y la consola del exe se añade con `>>`).
- Nuevo `port/run_stall_check_nob280.bat` (doble clic seguro): llama a `run_stall_check.bat nob280`.
- Verificación antes de jugar: banner `modo nob280` / `HH_NO_B280 : 1`, primera línea del log de
  consola con `HH_NO_B280=1`, y en consola `[NO_B280] obj=8024C934 handler=8021B280`.
- **Vía replay automática**: nuevo `port/run_cac_nob280.bat` (doble clic; usa la grabación más
  reciente o la que se le pase): reproduce `cac_rec.txt` con `HH_REPLAY_MODE=poll` + `HH_NO_B280=1`,
  recoge logs en `logs_nob280_<fecha>/` (con cabecera `modo=replay+nob280`) y saca el
  `stall_summary.txt`. El replay en Windows ya reproduce el CaC/freeze de forma fiable (hito 18-09,
  VI≈20710), así que sirve para el go/no-go sin jugar a mano (cautela: el input deriva un poco por los
  ticks de 3 VI; irrelevante para este test).

### Repetición replay con `HH_NO_B280` (10:12) — VALIDADO: sin freeze

`logs_nob280_20260919_101252/` (cabecera `modo=replay+nob280 HH_NO_B280=1`):

- `[NO_B280] obj=8024C934 handler=8021B280 (publicacion ignorada)` ⇒ hook activo (esta vez sí).
- **0** `Failed to find function at 0xFF7F84CD`, **sin `hh_venom.log`**, **sin `hh_hang.log`**,
  **1 sola muestra de stall** (a los 0,25 s del boot); `hh_slow` sin ticks catastróficos.
- Estado vivo hasta **t=345,1 s / VI=20709** (polls=10272, audio=15589, `pending_ext=1`); últimos
  segundos de `hh_tick.log` a **30 ticks/s** (d2 dominante; d3≈3 %, la cuantización de siempre).
- El VI 20709 es **exactamente** donde congelaba el replay normal (≈20710) ⇒ **la ruta del disable es
  el bloqueo real del freeze**. El mantenedor lo describió como "parado justo al entrar en la lucha":
  el replay termina (muestra 9815) justo en el umbral del combate y no quedan muestras de input para
  avanzar; el proceso siguió tickeando (polls/VI/audio subiendo) hasta que se cerró.
- Pendiente de confirmar con control: **entrar al combate** con input vivo
  (`port\run_stall_check_nob280.bat`), ya que el replay no incluye la pelea.

### CORRECCIÓN (mismo día, observación del mantenedor) — el combate NO entra

El mantenedor confirma que, en esa misma pasada, el juego **no entra en la pelea**: los personajes se
quedan quietos justo antes, **sin HUD de pelea** y sin posición de combate, pero **sin envenenamiento**
(0 venoms, 0 `BADMQ`/`MQDROP`). No es "fin del replay": la cinemática de entrada debería continuar sin
input.

- Matiz de la validación: `HH_NO_B280` **elimina el freeze por veneno** (el de VI≈20710), pero **la
  transición sigue rota aguas arriba** → el juego se para un poco más tarde, en la entrada de la pelea.
- Consecuencia: el veneno era el síntoma de la rama/timing equivocados, no el único bloqueo. El
  objetivo sigue siendo el **timing/estado de la transición** (loader #12, colas `0x8005C4F0/C268`,
  frame limiter `0x80001A88`/`__ll_*`).
- Evidencia pendiente: el watchdog **no llegó a volcar** (`hh_hang.log` ausente) porque se cerró antes
  de los 15 s. Repetir con **save avanzado del mantenedor** y dejar el cuelgue **20-30 s** para
  capturar pila/anillos de los hilos en el nuevo punto.

### SOFTLOCK con save avanzado (10:27) — app viva, lógica parada

`logs_stall_20260919_102712/` (live, cabecera `modo=nob280 HH_NO_B280=1`; mantenedor: supera el punto
habitual y se para al final, con **luces de alarma parpadeando** = render/VI vivos):

- `[NO_B280]` ×18; **0 `BADMQ`/`MQDROP`, 0 venoms, 0 `Failed to find`**.
- `polls` y `audio` **siguen subiendo** hasta el cierre (`t=130 s, VI=7807, polls=3943`, 30 ticks/s)
  ⇒ **no es cuelgue de aplicación** (el watchdog por polls/audio no dispara) sino **softlock de la
  lógica/simulación**.
- Los 9 contextos guardados de `hh_state.log` son idénticos en t=115→130 (ra/sp sin cambiar), pero eso
  **no localiza** al hilo atascado: el contexto solo se guarda al cambiar de hilo; el que corre
  mantiene su contexto viejo.

**Instrumentación añadida** (`src/main/main.cpp`, snapshots de `HH_STATE_SECS`): se vuelca el **anillo
de últimas llamadas por hilo** (`hh_get_callring`) en cada snapshot, además de los registros. Así el
`hh_state.log` localiza el softlock **sin depender del watchdog**. Requiere rebuild
(`build_windows.local.bat`) y una repetición con el save avanzado.

### CRASH tras el softlock (10:36) — el AV es en el "frame" del bucle principal

`logs_stall_20260919_103619/` (exit `0xC0000005`, AV):

- `hh_crash.log`: rip host = **`FUN_80001454+0x19B8`**, llamante **`FUN_800011b0`** (bucle principal) →
  `FUN_80001454` es **el "frame"** (llamado por el bucle principal; gestiona el timer
  `0x8008D580`/`0x42D0` y la máquina de estados de render `0x80037730/38/50`, s0=`0x80037748`).
  Guest sp=`8005BE78` = `ctx2 tid=5`; el AV (`r3=0x7AAECCCF`) es coherente con **leer un puntero
  corrupto en el frame tras el softlock**.
- Anillos del snapshot: **tid=5** en bucle `osGetTime (80031190)` + `__ll_*`
  (`80026F58/6E58/34C24/34AB8`); **tid=3** en `osRecvMesg`; el resto en sus bucles normales
  (audio/scheduler/VI).
- **Instrumentación añadida** (misma ronda): en cada snapshot de `hh_state.log` se vuelca la línea
  `[STATE] trans 42D0=... 7730=... 7738=... 7748=... 7750=... g2=... cnt30=... objCB=... q4F0=...
  q268=...` para ver **cuál** de esas variables se queda clavada en la transición (y compararla con el
  emulador).

### `det + nob280` (10:51/10:55) — sigue el crash; el callback se clava

Dos pasadas con save avanzado (`logs_stall_20260919_105156` t=205 s VI=12307 y
`logs_stall_20260919_105554` t=180 s VI=10806; cabecera `modo=det+nob280`): **mismo desenlace**
(0 venoms, y AV `0xC0000005`).

- `hh_crash.log`: rip host = **`FUN_80034c24+0x1F`** (= `__ll_to_d`, una de las rutinas `__ll_*`),
  llamante `FUN_80001454+0x1B4C` (**el "frame"**) ← `FUN_800011b0` (bucle principal). Fault
  = `rdram + 0x5BE78` (el propio `sp` del hilo): AV en un acceso a pila dentro de la conversión de
  tiempo. Guest `sp=8005BE78` = `ctx2/tid=5`.
- La línea **`[STATE] trans`** (nueva) muestra la clave: el callback del objeto
  `0x8024AAF8+0x1C` (`objCB`) **avanza por la state machine M12**
  (`801CB71C` → `M12_FUN_802410f4` → `...` → `M12_FUN_802415d8`) y **se queda clavado en
  `M12_FUN_80242e90` durante 18 snapshots (~90 s) hasta el crash**.
- `M12_FUN_80242e90` copia la posición del objeto (`*1000.0`) a `0x801BBBF0+0x1058/105C/1060` — el
  **mismo `0x801BBBF0`** que era el `a3` de la cadena del veneno. El resto de `trans`
  (`42D0/7730/7738/7748/7750`) está **a cero** todo el rato; `g2=AFB90010`/`cnt30=10410009` estables.
- ⇒ Con `det+nob280` el veneno no aparece, pero **la state machine M12 no completa la transición**:
  se atasca en `M12_FUN_80242e90` y el frame del bucle principal acaba en AV al calcular tiempo.
  `hh_det_clock` tampoco lo arregla.

### El headless NO reproduce el paro (corrección de un falso positivo)

Replay `cac_rec.txt` + `HH_NO_B280=1` (sin det), `timeout 430` (`work/debug/nob280/run2/`):

- El juego llega a **t=425 s / VI=25522** (polls=12495, audio=25489) **sin crash** y sin progresión
  M12: `objCB=801CB71C` (M7 sano) **todo** el tiempo. Bajo gdb también pasó de VI=27023 sin fallar.
- **CORRECCIÓN**: el `hh_crash.log` que sugería un crash a VI=24002 era **stale** (fichero de las
  06:49, de una prueba anterior): el análisis anterior de "reproducible headless" era **erróneo**. El
  replay actual **no** reproduce el softlock/crash del combate.
- **Ojo al grabar**: `run_cac_record.bat` (sin flag) se congela en el sitio de siempre (veneno). Si se
  graba, hacerlo **con `HH_NO_B280=1`**: `port/run_cac_record_nob280.bat` (doble clic) → deja
  `cac_rec.txt` en `logs_pacing_<fecha>/`.

### Aclaración del mantenedor (CLAVE) — no hace falta más input para llegar al softlock

El bloqueo clásico (veneno) ocurre **durante una cinemática** (la cámara rota). Unos segundos después
la cinemática termina y **empieza el combate**; el **softlock ocurre justo ahí** (no se entra a la
pelea). Por tanto **llegar al softlock (y al combate si no se bloqueara) NO requiere grabar más
inputs**: basta con **dejar la run en marcha** hasta que acabe la cinemática.

⇒ **Corrección** de lo dicho antes en esta nota ("la grabación termina en el umbral y el softlock
requiere input posterior"): era **incorrecto**. El **replay completo original**
(`cac_full_20260918_210956.txt`, partida nueva, emulador-compatible) **debe** llegar al softlock en el
emulador sin save ni inputs extra; en el port, con `HH_NO_B280=1`, hay que dejarlo correr **pasado el
final de las muestras** (la cinemática continúa sola). Verificación port↔emu pendiente con ese replay.

### Grabación nueva (save + nob280, 11:29) — el softlock SÍ se reproduce headless

`run_cac_record_nob280.bat` con el save avanzado → `logs_pacing_20260919_112932/cac_rec.txt`
(**4457 muestras**, ~147 s, termina a VI≈8870). El save de `build_win` y `build_dbg` es el mismo
(md5 `157b0c18...`).

- En vivo: crash `0xC0000005` a **VI=8870** en `FUN_80026f58+0x1F` (otra rutina `__ll_*`) ←
  `FUN_80001454` (frame) ← bucle principal; fault `rdram + 0x5BE78` = `sp`; **sin veneno**.
- Headless (`work/debug/nob280/run3/`, replay `poll` + `HH_NO_B280=1`): **reproduce el softlock**:
  el `objCB` avanza por M12 (`802410f4→…→802415d8→801501c0`) y se queda **clavado en
  `M12_FUN_80242e90` durante 32 snapshots (~160 s)**; `42D0/7730/7738/7748/7750=0`, `g2/cnt30`
  estables. En 255 s **no** crashea (solo se atasca).
- Anillos del softlock: **tid=5** en el bucle `osGetTime(80031190)` + `__ll_*`; **tid=3** en
  `osRecvMesg` tras una secuencia `osVirtualToPhysical → FUN_8002D924/D704/DABC → osSendMesg`.
- ⇒ **Reproducción determinista del softlock para depurar dev-side** (sin mantenedor).
- `M12_FUN_80242e90`: copia posición del objeto (`*1000`) a `0x801BBBF0+0x1058/105C/1060` y decrementa
  el contador u16 `[obj+0xA8]`; la state machine M12 debería cambiar el callback después, pero no lo
  hace (candidato: espera/estado de la transición).

### Causa inmediata del softlock: el contador `[obj+0xA8]` no se arma

Muestreo fino (1 s, `work/debug/nob280/run5/`) de la línea `[STATE] trans`:

- Con el callback clavado en `M12_FUN_80242e90` durante 80 s+, **`[obj 0x8024AAF8 +0xA8]=0000` en
  TODOS los snapshots** (nunca se ve `0x1E`). Igual `[0x8024A990+0xA8]=0`.
- `M12_FUN_80242e90` solo llama a `FUN_800208C4(0x63)` (el *trigger*) cuando `[obj+0xA8]` llega a 0
  **desde un valor armado**; con el campo ya a 0, la rama `beq v1,zero` salta el trigger y el callback
  queda de no-op para siempre.
- El estado que **arma** ese contador es **`M12_FUN_80242db4`**: `sh 0x1E,0xA8(obj)` y programa
  `M12_FUN_80242e44` con `FUN_8013B570(obj, 0x58, 2, 4, cb=0x80242E44)`, **tras la puerta
  `M7_FUN_80126CC0(obj, 0x80127014)`** (`beql v0,0` salta tanto el armado como el schedule).
  `M7_FUN_80126CC0` es de la **misma familia M7** que la puerta del veneno (`0x188`/`0x181`/`0x36`…).
- ⇒ El softlock apunta a que esa puerta M7 devuelve 0 (o el estado no se alcanza) y el contador nunca
  se arma; el callback `80242E90` queda como no-op.

### Traza de la puerta `M7_FUN_80126CC0` (hook `HH_M7GATE`) — resultado

Wrapper siempre-activo en `overlays.cpp` para `0x80126CC0` (filtra `a1==0x80127014`, el argumento de
`M12_FUN_80242db4`), ejecutando el replay del save (`work/debug/nob280/m7gate/`):

- Solo **3 llamadas**, todas **al arrancar/cargar (t≈5 s)**: `#1 a0=8024AAF8 ret=0`,
  `#2 a0=8024B7A0 ret=1`, `#3 a0=8024AAF8 ret=1` (con `0x188=0`, `0x181=01`, `[a0+0x36]=0x58`,
  `[a0+0x2C]=0x8000`).
- **En la transición no se vuelve a llamar** (no hay más `[M7GATE]`), pero `M12_FUN_80242e44` **sí**
  corre y deja instalado `M12_FUN_80242e90`.
- ⇒ El estado que **arma** el contador (`M12_FUN_80242db4`) se ejecuta solo al principio; su schedule
  de `80242e44` (vía `FUN_8013B570(obj,0x58,2,4,cb=0x80242e44)`) es el que parece disparar **mucho
  después**, ya en la transición, cuando `a8` ya no vale `0x1E`.
- **Siguiente**: ver **quién pone `a8=0`** entre el armado (t≈5 s) y la transición (watchpoint en
  `0x8024ABA0`), y comparar con el emulador (que no debería desincronizar arm/schedule).

### Diferencial mismo-VI con `nob280` (20200-20900) y estado del softlock — PARIDAD

- **Port con `HH_DUMP_VI=20200,20500,20700,20900` + `nob280`** (replay completo) vs dumps del emulador
  del 09-18 (mismo replay): **paridad total** en objeto CaC (`0x8024A990`), callback (`0x80135320`),
  M24 (`g2`/`cnt30`/`epoch`), directorio, etc. Única diferencia (ya conocida): **colas
  `0x8005C4F0`/`0x8005C268` = 0 en port vs `0x80049930` en emu**.
  *(Ojo: con `HH_DUMP_VI` el run no dio el callback `801CB71C` alterado ⇒ pudo no softlockear; la
  instrumentación perturba, como con el freeze.)*
- **State log sin dumps** (replay completo + `nob280`, `HH_STATE_SECS=1`, `full_state/`): en el
  softlock (t≈340-377 s) **todos** los campos van congelados y **coinciden con el emulador**
  pre-combate: `objCB=801CB71C`, `a8=0`, `42D0=0`, `7730/38/48/50=0`, `g2=AFB90010`,
  `cnt30=10410009`, `q4F0=q268=0`, `m188=0`, `m181=0`.
- ⇒ **El estado guest visible es el mismo que el del emulador**; el port simplemente **no avanza al
  combate**. La divergencia apunta a **entrega de mensajes/eventos y scheduling del runtime** en la
  transición (un evento/cola que el emulador entrega al empezar el combate y el port no), no a datos
  guest. Candidato concreto: las colas `0x8005C4F0`/`0x8005C268` (0 vs `0x80049930`).
- **Siguiente**: trazar qué cola/mensaje esperan `tid=5`/`tid=3` en el softlock y **qué `osSendMesg`/
  evento externo debería despertarlos** al empezar el combate; comparar con el emulador.

### El "softlock" del CaC es REAL (no un retraso) — CORRECCIÓN

**Corrección de una conclusión previa errónea.** En el run con traza ligera (`[STATE] mq` cada 2 s)
vi progresión M12 a t=224 (`801CB71C → 80241948 → … → 802425F4`), pero eso era una **escena
anterior** (VI≈13460), **no** el CaC. El punto del CaC (VI≈20000+, t≈330) cae en la fase
`objCB=802425F4` + `m188=0x8024C934` (objeto instalador del disable) y **se queda ahí**.

- **Verificación del mantenedor (Windows, en vivo)**: dejó el replay **~10 min en el softblock y no
  avanzó nada**. ⇒ El parón del CaC es **real y persistente**, no "esperar y continúa".
- Además, `m188=0x8024C934` es **el mismo objeto instalador del veneno** (el de la puerta del disable)
  ⇒ con `HH_NO_B280` bloqueamos la escritura, pero el port **ya ha tomado la rama M10/M12 equivocada**
  en el CaC y queda atascado. Es la **misma divergencia** que el freeze, sólo que en vez de acabar en
  el sentinel acaba en un estado colgado.
- **La instrumentación (dumps) enmascara** la divergencia: el run del port con `HH_DUMP_VI` a
  20200-20900 quedó en `801CB71C` (como el emulador); el run sin dumps derivó a `802425F4` y se colgó.

⇒ **El softblock y el freeze son la misma cosa**: el port toma en el CaC la rama M10/M12 que el
emulador no toma. El fix limpio sigue siendo alinear el timing/estado de esa transición (M24/A2) o
corregir la **puerta** que abre esa rama.

### Emulador: NUNCA ejecuta el instalador `M10_FUN_8021b240` (decisivo)

Traza `HB_TRACE_EXEC=0x8021B240,0x80126A0C` en el emulador con el **mismo replay completo**:

- **`M10_FUN_8021b240` (instalador del disable): 0 ejecuciones** (solo la línea del breakpoint). El
  port **sí** lo ejecuta (publica `b280`).
- **`M7_FUN_80126A0C` (la puerta): 18 ejecuciones** en el emulador (t=5.8 … 243.4 s) ⇒ la
  función-puerta en sí **no** es el problema.
- ⇒ **No es un input de puerta**: es que el **estado M7/M12 del port llega a llamar al instalador**
  y el del emulador **nunca**. La divergencia es de **camino/estado (timing)**, aguas arriba de la
  puerta. Consistente con el contralado previo (`M10_FUN_8021b280`/`M55` 0 en emu).
  Herramienta: hook `HH_GATE_A` en el port (wrapper de `0x80126A0C`) para comparar; artefacto emu:
  `work/debug/emu_gate_run.log`.

### Loader #12: confirmado el salto de la espera de escena (~20 s)

Traza del loader (`HH_LDTRACE` en el port; `HB_TRACE_EXEC=0x80003824` en el emu, `emu_run.log`):

| | port | emu |
|---|---|---|
| carga previa (`0005D280→801B6600`) | vi **205** | vi **349** |
| **#12 `005FBEC6→801BF1A0`** | vi **417** (s=217) | vi **1535** |
| espera entre ambas | ~212 VI (~3.5 s) | ~1186 VI (~20 s) |

⇒ El port **se salta ~20 s de espera de escena** antes de la carga #12 (idéntico a 09-18). Enlaza con
el hallazgo 09-17: el **driver de la línea temporal M24 no avanza** en el port (`M24_FUN_801bffac`
nunca corre, `EVQCHECK`=0) y cambia de escena **antes** por la vía alterna
(`M24_FUN_801bf508`/`8021c0254`). Ese adelanto desplaza el estado M7/M24 y, aguas abajo, hace que en
el CaC el port **llame al instalador M10/M12** (freeze/softblock). Artefactos:
`work/debug/loader_port.log`, `work/debug/cac/diff_vi_20260918/emu/emu_run.log`.

### Estado actual del driver M24 y prueba de `HH_REPLAY_CLOCK`

Traza `HH_TBLTRACE=1 HH_LSTTRACE=1` (port, replay completo + `nob280`, escena temprana;
`work/debug/m24/tl_port.log`):

- **`ADVANCE` (`M24_FUN_801bffac`) = 0** → el periodo de la línea temporal **nunca avanza**.
- **`EVQCHECK` (`FUN_801C0B8C`) = 0** salvo el primero (los waits 3 s/11 s/20 s no se cumplen).
- **`P89478`**: el flanco **START (`0x1000`)** aparece en **vi 514 y 548**, y la cadena
  `CHK_0C68`(cnt60)→`CHK_012C`(f00=1)→`CHK_0190` se completa en **vi ~549** → **cambio de escena
  prematuro** (emulador: ~vi 3660). Lo dispara el **START del replay**, no la línea temporal
  (idéntico al hallazgo 09-17).
- **`HH_REPLAY_CLOCK=1`** no lo arregla: la carga #12 sigue en el mismo sample `s=217`, ahora en
  **vi=302** (poll: 417; emu: 1535) → incluso **adelanta**. ⇒ No es el índice de muestra sino la
  **cadencia/fase frame↔VI**.

### Síntesis (por qué los parches no bastan) + experimentos negativos

Todos los síntomas (cambio de escena prematuro, `ADVANCE=0`/`EVQCHECK=0`, y en el CaC la llamada al
instalador M10/M12 → freeze/softblock) son consecuencia de que **el dominio de tiempo del port
(VI por reloj de pared + limiter por `osGetTime`) no va en lockstep con la ejecución guest**. Los
arreglos acotados probados (`HH_DET_CLOCK`, `quant`, `HH_REPLAY_CLOCK`, `HH_NO_B280`) **no** lo
resuelven.

**Opción B (`HH_REPLAY_PACE=vi`) y cache — NEGATIVOS** (medido):
- `HH_REPLAY_PACE=vi` (ya existía; espera a que el VI alcance el `vis` de la muestra) **no cambia
  nada**: carga #12 en **vi=412** (poll: 417); `P89478` (START) en vi 511/545; `CHK_012C`→1 en vi
  546; `ADVANCE=0`. (Evidencia: `work/debug/m24/pacevi_tl.log`.)
- `HH_TRANS_CACHE=0 HH_TRANS_NATIVE=0` (loader original, sin cache): carga #12 en **vi=410**
  (idéntico). ⇒ La cache de assets **no** es la causa. (`loader_nocache.log`.)

**Dato cuantitativo (frames de juego)**: entre las dos cargas idénticas (`0005D280→801B6600` y
`005FBEC6→801BF1A0`), el **port consume ~105 frames** (~3,5 s) y el **emulador ~594 frames (~20 s)**
⇒ el port **se salta ~16 s de espera de escena**. Encaja con el hallazgo 09-17: la **epoch M24**
(`[0x801D8D80:84]`) del port era ~`0x1F014BEF` (~11 s) vs emu `0x4BB6C427` (~27 s): delta ~16 s
justifica exactamente que los waits (`osGetTime - epoch`) se cumplan ~16 s antes.
**Candidato raíz: la epoch/arranque de la línea temporal M24** (se pone al iniciar la escena; el port
la fija ~16 s antes).

### Epoch M24 medida: port `vi 421` vs emu `vi 1625` (~20 s antes) — CONFIRMADO

La epoch la fija **`M24_FUN_801c0a30`** = retorno (64 bits) de **`M24_FUN_801C0C08`** (osGetTime
escalado), escrito en `[0x801D8D80:84]`. Instrumentado (`HH_EPOCHTRACE` en el port;
`HB_TRACE_EXEC=0x801C0A30` en el emu):

| | 1ª fijación | 2ª fijación |
|---|---|---|
| **port** | **vi 421** (~7,0 s; epoch `0x13935E28`) | vi 587 (~9,7 s; `0x1B4D53A3`) |
| **emu** | **vi 1625** (t=27,11 s; caller `ra=0x801BF360`) | vi 1861 (t=31,04 s) |

⇒ El port arranca la línea temporal **~20 s antes** (1204 VI). Eso reduce la epoch ~20 s y hace que
los waits se cumplan ~20 s antes ⇒ cambio de escena prematuro ⇒ rama M10/M12 (freeze/softblock).
Artefactos: `work/debug/m24/epoch_port.log`, `work/debug/emu_epoch_run.log`.

**Siguiente**: por qué el port llega a `M24_FUN_801c0a30` ~20 s antes (fase pre-línea temporal:
intro/menús/carga). Candidato: la **cadencia de consumo del replay** (el original llamaba `GetKeys`
~1,47/tick — 44,3/s frente a 30 ticks/s — y el port 1/tick), de modo que las muestras de input
(START de menú) caen en fases de juego distintas; y/o un arranque/carga más rápido del port.

### Test de causalidad A→B (enmascarar START): **A ES CAUSAL de B**

Diagnóstico `HH_MASK_START=lo:hi` (en `input.cpp`): enmascara el bit START (0x1000) dentro de una
ventana de VI, para quitar el input espurio que dispara la cadena en la transición.

- **Con máscara** (`HH_MASK_START=400:700`, replay completo + `nob280`, `work/debug/m24/mask_full.log`):
  el port hace más cargas y llega a **t=378 s / VI=22709 / polls=11119** con
  **`objCB=801CB71C`, `m188=0`** (como el emulador), **sin rama del instalador M10/M12 y sin crash**.
- **Sin máscara**: en el CaC `objCB=802425F4`, `m188=0x8024C934` (instalador) y **softlock**.

⇒ **El cambio de escena prematuro (A), disparado por el START del replay cayendo en la transición,
es causal de la rama del CaC (B)**. **Comparten raíz**: la **fase/cadencia input↔VI** (no son desfases
independientes). El enmascarado es **diagnóstico**, no fix (el START era espurio en esa fase; el juego
progresa sin él).

### A1 (`osGetTime` cuantizado a VI) — NEGATIVO

Implementado como opt-in (`HH_DET_CLOCK=quant`, `timer.cpp`: `vi*781250` sin sub-VI de host):

- `quant` puro: **d3=91,5 %** (≈20 fps) → el limiter necesita la resolución sub-VI para clavar los 2 VI.
- `quant` + `HH_DET_CLOCK_BIAS=15625`: d2≈90 %, d3≈2 % (equivalente a `det`), pero **el softlock
  persiste** (`objCB=80242E90`, `a8=0`, 93 snapshots).
- ⇒ **El softlock NO lo causa el deslizamiento de 3 VI del limiter**: es estado/lógica de la
  state machine. A1 descartado como fix; el `quant` queda como knob de diagnóstico (off por defecto).
- Consecuencia: A2 (contador determinista completo) tampoco es la solución del softlock por sí solo;
  hace falta la **referencia del emulador** para localizar la primera divergencia de estado.
