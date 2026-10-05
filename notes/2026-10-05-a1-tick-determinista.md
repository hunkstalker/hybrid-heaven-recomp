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

Reloj determinista del runtime **continuo + bias**:
`HH_DET_CLOCK=1` + `HH_DET_CLOCK_BIAS=15625` (el bias hace que 2 VI = 34,0 ms → cruza el objetivo en
2 VI de forma determinista). Se deja **por defecto en el port** (`src/platform/main.cpp`), sin tocar el
fork: se fijan con el entorno del **CRT** (`_putenv_s`/`setenv`), **no** con `SDL_setenv` (en Windows SDL
usa la API de entorno, que el `getenv` del runtime no ve). Overrideables: `HH_DET_CLOCK=0`/`quant`,
`HH_DET_CLOCK_BIAS=<v>`. Traza `[hh-env]` al arrancar.

## Validación (Windows, 2026-10-05, mantenedor)

- `[hh-env] tick: HH_DET_CLOCK=1 HH_DET_CLOCK_BIAS=15625` (default aplicado).
- `hh_tick.log`: `ticks=30-31`, `d1=0`, **`d2` dominante**, **`d3=0`** (63/63 líneas estables).
- `[hh-fps]`: `present=119.9` con `target=120`, `vi=30`.
- Visual: **120 fps estables, sin parones** (validado por el mantenedor).

## Residual a vigilar

- `[INFERIDO]` El bias hace que `osGetTime` avance ~2% más rápido (necesario para cruzar el objetivo
  de ~34 ms en 2 VI). La lógica de HH es por tick (30 Hz), así que no debería acelerar nada; **conviene
  confirmar velocidad/audio en una sesión larga** (el mantenedor no notó anomalía en la run corta).
