# 2026-09-18 (bis) — HITO: el replay reproduce el CaC en port (Win+Linux); el emulador lo pasa con el mismo input

> Continúa `2026-09-18-cac-replay-en-vivo-no-reproduce.md`. Grabación nueva del mantenedor:
> `port/HybridHeavenRecomp/build_win/bin/Release/logs_pacing_20260918_210956/cac_rec.txt`
> (9815 muestras, vis 37→19812). Partida **limpia** (esquivando enemigos).

## 1. La clave: `HH_REPLAY_MODE=poll` (no `vi`)

`mode=vi` se adoptó cuando el port era **work-bound** y perdía ticks. Tras el fix de `get_function`
(el port va a 30 ticks/s estables) `vi` **introduce un sesgo** de muestra: el input se desalinea poco a
poco (síntoma observado por el mantenedor: "el PJ se inclina ligeramente a la izquierda y no cruza la
puerta"). Con **`poll`** (1 muestra por tick) el replay es **fiel**.

- Cambiado `port/run_cac_replay.bat` a `HH_REPLAY_MODE=poll` (comentario actualizado).
- `HH_REPLAY_PACE` sigue **vacío** (`pace=vi` provoca tirones; ya descartado).

## 2. El replay reproduce el freeze en el port (Windows y Linux headless)

Misma grabación, `HH_REPLAY_MODE=poll`:

| | Windows (mantenedor) | Linux headless (dev) |
|---|---|---|
| cuelgue | `polls parados 15 s`, **VI=20710** | `polls parados 15 s`, **VI=20949** |
| veneno | `Failed to find 0xFF7F84CD` | `Failed to find 0xFF7F84CD` |
| volcado | `logs_replay_20260918_213043/hh_hang_rdram_11704_*` | `build_dbg/hh_hang_rdram_47781_*` |

⇒ Por primera vez, el CaC es **reproducible de forma fiable** (con el mismo input) en ambos entornos.

## 3. El emulador pasa el CaC con el MISMO input (oráculo confirmado)

`work/r64dump` con `HH_KEYS_REPLAY=<cac_rec.txt>`: consume las 9815 muestras **sin congelarse**.
Corriendo **solo** va a **tiempo real** (~30 muestras/s); la lentitud aparente era **contención de CPU**
(port + emulador a la vez) y los dumps. `r64dump` usa `pure-interpreter` a propósito porque los dumps
usan el **debugger de mupen** (que exige el intérprete).

### Comparación de estado (mismo input, al final)

| dirección | EMU (final) | PORT (freeze, Win y Linux) |
|---|---|---|
| `0x8024A990` | `8024AAF8` | `8024B854` |
| `0x8024AAF8` | `8024ABAC` | **`00000000`** |
| `0x8024AB14` (obj `0x8024AAF8` +0x1C) | **`801CB71C`** (sano) | **`FFFF84CD`** (veneno) |
| `M24.g2` (`0x801D8CE8`) | `AFB90010` | `AFB90010` |
| `M24.cnt30` (`0x801D8DA8`) | `10410009` | `10410009` |

- La **línea temporal M24 coincide**; diverge el **objeto**: en el port queda **anulado**
  (`0x8024AAF8=0`, callback `FFFF84CD`) y en el emulador **vivo** (`8024ABAC`, callback `801CB71C`).
- Nota: el puntero de `0x8024A990` difiere (`8024AAF8` vs `8024B854`); el volcado del port es 15 s
  después del cuelgue, así que el objeto pudo recrearse/reasignarse. Interpretar con cuidado.

## 4. Siguiente paso (handoff)

**Diferencial port↔emulador en el MISMO VI, alrededor del envenenamiento**, con el mismo `cac_rec.txt`:

1. Localizar el VI exacto del envenenamiento en el port (primer `Failed to find 0xFF7F84CD`, ~VI 20.7-21.0k).
2. Volcar ambos lados en VI coordinados (p. ej. **20200 / 20500 / 20700 / 20900**) y comparar el objeto
   `0x8024A990`/`0x8024AAF8`, el directorio de módulos (`0x8008DFC0/DFC4`), M24 y colas.
3. Seguir aguas arriba en el VI donde aparezca la primera diferencia.

- Port: `HH_DUMP_VI=20200,20500,20700,20900` (formato `port_vi<VI>.bin` en `build_dbg/work/debug/`).
- Emu: `HH_DUMP_TIMES` (segundos) o `HH_REPLAY_VI`/`HH_REPLAY_VI_OFF` en `r64dump`; dumps `emu.vi<VI>.bin`.
- Reproducir **solo uno a la vez** (evitar contención de CPU). Ver `RETOMAR.md` para los comandos.

## 5. Evidencia

- Grabación: `logs_pacing_20260918_210956/cac_rec.txt` (+ `hh_hang*`, `hh_missing.log`, `hh_badlookup.log`).
- Port Windows replay: `logs_replay_20260918_213043/`.
- Port Linux headless: `build_dbg/hh_hang_rdram_47781_*.bin`; log `/tmp/opencode/repro_poll.log` (temporal).
- Emulador: `work/debug/cac/emu_nodump` (volcado final); log `/tmp/opencode/emu_nodump.log` (temporal).
- Cambio de repo: `port/run_cac_replay.bat` (`mode=poll`).
