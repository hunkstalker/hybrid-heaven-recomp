# Replay preciso: modo poll-exacto (el modo VI derivaba)

> Arreglo del replay que el mantenedor reportó como impreciso (2026-09-17):
> al llegar al primer NPC se pasó de largo y A saltó en vez de hablar.
> Continúa `notes/2026-09-17-cac-replay-windows-y-firma-8024aaf8.md`.

## Causa

- `hh_replay_apply` alineaba por **VI**: en cada poll elegía la última muestra con `vis <= VI actual`.
- La grabación se hizo con instrumentación pesada (`HH_DIAG=1`, `HH_CANARY`, `HH_WATCH`,
  `HH_TRACE_RANGE`) que **estira el timing**, mientras que el replay corre limpio. Con distinto
  patrón de VI por poll, la selección caía en la muestra vecina → deriva del stick/acciones
  (pasarse del NPC, A a destiempo).
- El stick analógico es sensible a un solo frame de desfase: eso explica "pasarse y saltar".

## Arreglo (input.cpp)

- **`HH_REPLAY_MODE=poll` (nuevo DEFECTO)**: aplica **una muestra por poll** (frame de juego
  exacto), sin depender del VI → robusto al jitter de timing y a distinto rendimiento.
- `HH_REPLAY_MODE=vi`: mantiene el comportamiento anterior (útil si se reproduce en otra máquina con
  distinto número de polls de arranque).
- `HH_REPLAY_SYNC=vi` (con modo poll): al primer poll salta al primer sample con `vis >= VI actual`
  (por si el arranque consume distinto número de polls/VI).
- `HH_REPLAYLOG=1` → `hh_replay.log` con las muestras **aplicadas** (`poll VI botones x y`) para
  comparar 1:1 con `hh_replay_fight.txt`.
- `run_replay.bat`: usa modo poll + `HH_REPLAYLOG=1`; acepta `sync` para activar la sincronización VI.

## Validación local (Linux, 60 s)

- 1793 muestras aplicadas; **0 discrepancias** poll-a-poll de botones/x/y contra
  `hh_replay_fight.txt` (comparación directa de `hh_replay.log` vs el replay).
- Primer poll: Linux `VI=30` (Windows grabó el primero en `VI=83`): el modo poll no depende del VI.

## Siguiente

1. Mantenedor: `port\build_windows.local.bat` + `port\run_replay.bat` (modo poll).
   - Si el arranque/menús no cuadran: probar `port\run_replay.bat hh_replay_fight.txt sync`.
   - Si aun así: `set HH_REPLAY_MODE=vi` (comportamiento anterior) para comparar.
2. Con `hh_replay.log` de la pasada se puede diff exacto contra la grabación.
