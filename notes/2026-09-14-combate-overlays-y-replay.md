# 2026-09-14 — Combate: overlays de IA + grabación/replay de input

## Crash al entrar en combate (robot detecta/dispara) — RESUELTO

- Faltaban funciones de la IA enemiga, llamadas cada frame:
  - planas: `0x80005C70`, `0x80005CB0`, `0x80022978`, `0x800229FC` y 18 mid-entries
    verificadas contra el emulador (`0x80002B44`, `0x80014798`, `0x80017910/1C`, `0x8001EA74`,
    `0x8001F75C/90/B0`, `0x8002096C`, `0x80020EA0`, `0x8002759C/B4`, `0x80027698`, `0x80029EE8`…).
  - `0x80005CB0` es una subfunción llamada con `jal` desde `FUN_80005c70`; el recompilador la
    emitía como `LOOKUP_FUNC` (miss) al no ser símbolo.
- Verificación headless (solo STARTs + `HH_STICK=0,1`): sin SEGV ni faltantes, gameplay avanza
  (`work/debug/port_combat7_*.png`).

### Herramientas de diagnóstico del pipeline

- `gen_module_syms.py --filter-data` (solo módulos nuevos): descarta entradas que caen en datos
  (constant pools) mediante `_plausible_code_strict` (cuenta skipdata `.byte/.word`). El detector de
  mid-entries auto mantiene la heurística original (no alterar módulos ya validados 23/24/25/99).
- Descartados los **extras de módulo especulativos** obtenidos del escaneo de `LOOKUP_FUNC(0x...)`:
  rompían la fusión de jump-tables (66 ramas cruzadas en módulo 24). Solo se añaden por evidencia
  runtime (`Failed to find function at 0x...`).

## Grabación y reproducción de input (depuración determinista)

- `HH_RECORD=<f>`: escribe `<t> <buttons_hex> <x> <y>` en cada poll del mando 0.
- `HH_REPLAY=<f>`: reproduce la secuencia **por índice de poll** (una muestra por frame).
  Verificado **RMSE = 0** contra la grabación (píxel a píxel).
- Uso: grabar una partida real en Windows hasta el fallo, enviar el `.txt`, y reproducirlo en el
  entorno de desarrollo para depurar con `boot.log`/`hh_missing.log`.

## Frontera

- **Crash cuando los robots dañan al jugador** (nuevo). No reproducido headless en un run de 640 s
  con stick arriba (el personaje no llegó a recibir daño). Se reproducirá con la grabación del
  usuario (`HH_RECORD`).
- Layout del mando pendiente (tabla basada en Goemon/emulador). `HH_INVERT_Y` permite invertir el
  eje Y sin recompilar.
