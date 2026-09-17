# 2026-09-17 — Replay: reloj esclavo (`HH_REPLAY_CLOCK`) y desfase de frames — **WIP**

> Continúa `2026-09-17-cac-timeline-modulo24-periodo.md` (§4b-5). **Trabajo a medias, parado a
> propósito**: el test de juego del port nativo lo hace **el mantenedor (usuario)**; el entorno de
> desarrollo solo hace pasadas headless (replay + emulador). No dar por bueno ningún diferencial
> nuevo hasta cerrar esto.

## 1. Objetivo y por qué

- El diferencial port↔emulador con el replay de Windows mostró que el input cae en otra fase de juego
  en el port: el START de los samples 412-431 (en la grabación: navegación de menú, `vis` 1092-1135)
  cae dentro de la transición → `[0x80089478]&0x1000` → cadena de cambio de escena → se pierde la
  ráfaga #22.
- Causa de fondo: la grabación está indexada por frame (1 muestra/poll, ~23,3 muestras/s, `vis`≈2,65
  VI/frame en la máquina que grabó) y el port aplica 1 muestra por poll, pero su relación frame↔VI es
  distinta (~1,86-2,04). Los waits dependientes de tiempo consumen otros frame counts.

## 2. Implementado (a medias)

- **Runtime** (`ultramodern/src/timer.cpp`):
  - `hh_replay_clock_set(double t)` / `hh_replay_clock_on()`: con el modo activo, `osGetTime()` y
    `osGetCount()` devuelven el valor fijado por la muestra + **interpolación intra-frame** a la tasa
    local (`rate = Δt_grabación / Δt_pared`, acotada a [0,05, 2,0]); `osSetTime()` reajusta la base.
  - `hh_replay_set_sample(u64)` / `hh_replay_get_sample()`: índice de la muestra aplicada.
- **Port** (`src/game/input.cpp`): `HH_REPLAY_CLOCK=1` llama a `hh_replay_clock_set(sample.t)` al
  aplicar cada muestra (modos `poll` y `vi`) y publica el índice de muestra.
- **Instrumentación**: `[LD384]` (TBLTRACE) imprime `s=<muestra>` para correlacionar cada carga del
  loader con la grabación.

## 3. Resultados de esta ronda (Linux, replay largo)

- **Sin interpolación**: **deadlock** a las 158 muestras (VI 231). El reloj se congela y el juego
  espera algo que depende de él (el reloj solo avanzaba al aplicar muestra) → watchdog a los 15 s
  (`hh_hang.log`). La interpolación intra-frame lo resuelve.
- **Con interpolación**: el juego corre (8573 muestras, VI 9520) pero **la transición sigue
  adelantada**: `[LST] SCRIPT` en la muestra ~341 (original/emulador ~582) y los START de 412-431
  caen dentro → `[DT] id=9` (cambio de escena) en la muestra ~522. **El reloj esclavo no ha movido
  el frame de la transición** → el desfase de frames no es (solo) de waits por tiempo.
- **Efecto lateral**: el reloj esclavo **rompe el limitador de frames del juego** (que usa
  `osGetTime`): el juego pasa de ~29 fps a ~57 fps (~1,1 VI/frame). Pendiente decidir si limitar el
  frame loop por la muestra o desacoplar el limitador.

## 4. Pendiente (siguiente ronda)

1. Localizar **dónde** se pierden ~240 frames antes de la transición: comparar el índice de muestra
   por carga (`[LD384] … s=`) con el emulador (sus cargas ≈ `t`·23,3 muestras).
2. Decidir entre:
   - (a) **gatear el frame loop por la columna `vis`** de la muestra (reproducir el frame-rate
     grabado) — toca scheduler/pacing (la zona que estaba cerrada);
   - (b) o arreglar la causa de que el port consuma menos frames (menús/carga/VI-waits).
3. Re-diferencial completo tras el arreglo (criterio: transición en muestra ≈580, `[TL] ADVANCE`
   g2 0→1, ráfaga `0x00B7BAF0…`, cargas de módulos como el emulador, y ver si el veneno
   `0xFFFF84CD`/`[BADMQ]` persiste).

## 5. Estado y reparto de tareas (IMPORTANTE)

- **El replay todavía NO es fiel** (transición adelantada). No cerrar conclusiones del CaC con el
  diferencial actual.
- **El test de juego del port nativo lo hace el mantenedor (usuario)**: el entorno de desarrollo
  (Linux headless) solo reproduce con replay/emulador. Cualquier validación "en vivo" (mando,
  pantalla, rendimiento) es del usuario.
- Validación en paralelo acordada: el usuario probará en **Windows** (build con esta instrumentación)
  si la ráfaga #22 se salta en vivo/replay fiel → decide si el hallazgo del §4b de la nota de la
  línea temporal es **real** o **artefacto del replay**. El resultado manda sobre este WIP.

## Evidencia

- Linux: `work/debug/cac/linux_replayclock/` → `consola.log` (deadlock sin interpolación),
  `consola2.log` (con interpolación; `[TL] P89478` en VI 506/515/522, `[DT] id=9`),
  `hh_replay_clock.log` (poll/vi/botones), `hh_hang.log` + dumps del deadlock.
- Emulador (ronda anterior, referencia): `work/debug/cac/emu_wp89478/`, `emu_flag/`, `emu_comb/`,
  `emu_scenefn.log`, `emu_setter.log`, `emu_cmds.log`.
- Código (local, en este commit): `ultramodern/src/timer.cpp`, `librecomp/src/overlays.cpp` (`s=`),
  `port/.../src/game/input.cpp`.
