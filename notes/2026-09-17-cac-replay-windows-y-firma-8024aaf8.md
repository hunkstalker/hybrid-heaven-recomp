# CaC — Pasada Windows con replay (partida nueva) y firma del objeto `0x8024AAF8`

> Evidencia de la grabación del repro del CaC (2026-09-17) y del flujo de validación por replay.
> Sigue a `notes/2026-09-17-cac-b1-solape-modulos-23-8.md`.

## 1. Pasada

- `port\run_corrupt.bat`, **partida nueva** (sin cargar), ~5,3 min hasta el freeze al entrar en combate.
- **Replay grabado**: `hh_replay_fight.txt` — **8846 muestras**, `VI 83..19167`, ~318 s. Formato
  `<t> <VI> <botones> <x> <y>`; el replay se aplica por **índice de VI** (determinista, no depende
  de la velocidad de arranque de la máquina).
- Evidencia copiada a `work/debug/cac/20260917_1146_windows_replay/` (133 MB: replay, hang log +
  RDRAM/DMEM, state, trace, sched, mq, canary, watch, pi, cmds, missing, s0fix, badlookup, audio, rsp, ovl).

## 2. Firma confirmada

- Consola: `Failed to find function at 0xFF7F84CD` repetido, con
  `caller ... r4=8024AAF8 r5=8008DA88 r6=00000004 ... host_ret=exe+0x503BF`, seguido de cascada
  `[BADMQ]` (mq corruptas: `00040000`, `C0000830`, `8025xxxx`…). Watchdog:
  `[HANG] polls 15.0s, audio 15.0s, VI=20109`.
- Volcado (`hh_hang_rdram_24916_0.bin`):
  - **objeto `0x8024AAF8` +0x1C = `0xFFFF84CD`** (el valor también aparece en `0x8024AB14`);
  - `0x80135320` (el que tiene el emulador) está en `0x8024B000`/`0x8024B0B4` (otros objetos);
  - `cd4c=0`, `M23 (0x801CC8C4)=0xAF`, `gate (0x8017DD92)=0`; colas vacías.
  - `hh_missing.log`: 11 entradas del mismo target → el dispatcher reintenta el callback corrupto en
    bucle (livelock) hasta el watchdog.
  - `hh_s0fix.log`: 11 correcciones `s0` (mitigación `HH_S0FIX` actuando).

## 3. Validación del replay en Windows (nueva)

- **`port\run_replay.bat`** (nuevo): reproduce el replay sin grabar y sin tocarlo; aparta logs
  previos a `logs_prev_replay\`. Uso:
  - `run_replay.bat` (usa `hh_replay_fight.txt` junto al `.exe`),
  - `run_replay.bat <fichero.txt>` (otra ruta),
  - `run_replay.bat <fichero> diag` (añade `HH_DIAG=1`).
- Objetivo: comprobar que el mismo replay reproduce el freeze en Windows **antes** de usarlo en Linux.

## 4. Siguiente

1. Validar el replay con `run_replay.bat` (¿reproduce el freeze en el mismo punto?).
2. Reproducir en Linux con instrumentación: dueño en `func_map` de `0x801C1EE0`/`0x801C1DC0` y
   quién llama a `0x801C1EE0` (hipótesis B1), y estado de la cadena
   `0x801C40F8/0x801C43BC/0x801C44C4/0x801C45C8` al entrar en combate.
3. Si se confirma B1: fix candidato v3 (borrar `[ram, ram+size)` al cargar sección) y validar con el
   replay; después, pasada del mantenedor en Windows.
