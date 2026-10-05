# 2026-10-05 — A1: tick lógico determinista (2 VI/frame) — RESUELTO y VALIDADO

> Cierra A1 de la épica FPS (`notes/2026-10-02-workorder-desbloquear-fps-interpolacion.md` §A1).
> Diagnóstico con datos del oráculo (`hh_tick.log`/`hh_framelog.log`) y validación en Windows por el
> mantenedor: **120 fps estables, sin parones**. Distinción medido / inferido explícita.

## Síntoma

Micro-parones de ~1 frame **solo con interpolación** a alta tasa. A 30 nativos no se percibían.
`hh_tick.log` (con `HH_DIAG=1`) los localizó: en estado estable `ticks=30`, `d2≈28-29` y **`d3=1-2`
slips/s a 3 VI**. Ese tick largo (50 ms en vez de 33) rompe la interpolación de frames.

## Causa (medida)

El **frame limiter del juego** (`func_80001454`, bucle en `0x80001A88`) espera a que
`elapsed_ms >= objetivo` (~34 ms), con el tiempo **truncado a ms enteros**. La rejilla de VI es 16,67 ms:
a 2 VI el reloj da 33,33 ms → `< 34` → espera al 3.º VI (50 ms). No es falta de CPU: `hh_framelog`
muestra cómputo real ~6 ms; el resto es el spin del limiter. Los `send_dl`/`update_screen` quedaron
descartados (nota 2026-09-19).

- `[MEDIDO]` `HH_DET_CLOCK=quant` (reloj exacto en la rejilla VI): **peor** — 2 VI = 33,33 < 34 → todos
  los ticks a 3 VI → **20 Hz**.
- `[MEDIDO]` `HH_DET_CLOCK=1` (continuo) solo: no bastaba (slips ~3%).

## Fix

Reloj determinista del runtime **continuo + bias**: `HH_DET_CLOCK=1` + `HH_DET_CLOCK_BIAS=15625`. Se
deja **por defecto en el port** (`src/platform/main.cpp`), sin tocar el fork: se fijan con el entorno del
**CRT** (`_putenv_s`/`setenv`), **no** con `SDL_setenv` (en Windows SDL usa la API de entorno, que el
`getenv` del runtime no ve). Overrideables: `HH_DET_CLOCK=0`/`quant`, `HH_DET_CLOCK_BIAS=<v>`. Traza
`[hh-env]` al arrancar.

### Cómo funciona el limiter (por qué hay que biasear)

`func_80001454` lee el objetivo de `D_8017AA90` (`func_80133AA0`), fijado a **2** en el arranque
(`func_80133AAC(2)` en `0x800013A0`). El bucle de `0x80001A88`:

```
µs = (delta_ticks * 64) / 3000      # división ENTERA -> trunca a µs
n  = trunc(µs / 16666.666)          # 16666.666 = µs por VI (constante D_8004B908)
espera hasta n >= 2
```

`last` (`D_80037760`) se fija con `osGetTime` a mitad de frame (`0x80001944`). A 2 VI exactos,
delta = 1.562.500 ticks → µs = **33.333** (truncado) → 33.333/16666.666 = 1,99998 → `n=1` → pide un
**3.º VI**. El bias empuja el reloj para que ese truncado cruce.

### Mínimo teórico vs medido (INCÓGNITA ABIERTA)

`[INFERIDO]` Para cruzar: `µs ≥ 33.334` → `delta ≥ 1.562.531` → `2·(781.250+b) ≥ 1.562.532` → **b ≥ 16
ticks/VI** (deriva ~0,002%). `[MEDIDO]` **NO se cumple**: `BIAS=256` → vuelven slips (`d3=1-3/s`,
`present~100`); `BIAS=8192` → el mantenedor ve **más picos por debajo de 120 y escapes a 122**;
`BIAS=15625` → `d3=0` y 120 clavado. El mínimo real es **mucho mayor** que el teórico; el modelo simple
no lo explica (sospecha: sub-VI no fiable en Windows y/o el redondeo del limiter). **Pendiente** (abajo).

## Validación (Windows, 2026-10-05, mantenedor)

- `[hh-env] tick: HH_DET_CLOCK=1 HH_DET_CLOCK_BIAS=15625` (default aplicado).
- `hh_tick.log`: `ticks=30-31`, `d1=0`, **`d2` dominante**, **`d3=0`**.
- `[hh-fps]`: `present=119.9` con `target=120`, `vi=30`.
- Visual: **120 fps estables, sin parones** (validado por el mantenedor).

## Medición objetiva de fps (para comparar configuraciones)

`HH_FPS=1` → `[hh-fps]` por segundo; **`[hh-fps-sum]` cada 10 s** (o `HH_FPS_SUM=<n>`) con
`mean/min/max/at_target%` acumulados. Permite comparar `HH_DET_CLOCK_BIAS` (15625 vs 8192…) **por
números**, no por sensación. `HH_DET_CLOCK_BIAS` es override por entorno (no requiere rebuild).

## Residual a vigilar (documentado a propósito)

- **Deriva del reloj (~2%)**: `bias/781.250` por segundo → `15625` = **2%** (~72 s/hora).
  `[INFERIDO]` La lógica es por tick (30 Hz), así que no debería acelerar el juego; el efecto temido es
  que la **música** (secuenciada por `osGetTime`) se **adelante** respecto a la imagen en sesiones
  largas. **Confirmar en una sesión larga.** (El retraso de audio visto históricamente era *buffering*,
  ya resuelto, no relacionado con el reloj.)
- **Incógnita del mínimo**: por qué `256` no basta (ver arriba). Si se resuelve, se baja el bias a ~16
  y la deriva pasa a ~0.

## Investigación abierta (para retomar)

- `hh_get_vi_count()`/`hh_get_vi_wall_us()` los actualiza el **hilo de VI** (`events.cpp`):
  `total_vis = floor(t·60)+1`, `hh_vi_wall_us = t del wake`. El sub-VI de `timer.cpp`
  (`sub_ticks = (now_us - hh_vi_wall_us)·46.875`) debería hacer el reloj **continuo y 1:1**, y entonces
  el limiter cruzaría a ~2 VI + 0,7 µs **sin bias**. Comprobar si el sub-VI es fiable en Windows (que
  `hh_vi_wall_us` se refresque; que `sub_us` no quede pegado) y/o si el limiter **redondea** en vez de
  truncar. Si se arregla, A1 quedaría **sin deriva**.
