# 2026-09-15 — Cuelgue del NPC (5ª ronda): mid-entry faltante 0x80380010 (módulo 55)

> Nota de sesión. Tras el blindaje del struct de hilo (ronda 4) el juego llega más lejos y aparece
> `hh_missing.log`. Precedente: `notes/2026-09-15-cuelgue-npc-thread-struct-pisado.md`.

## 1. Síntoma

Nueva corrida: `hh_missing.log` con **una** línea:

```
Failed to find function at 0x80380010
```

y el watchdog volvió a disparar (`polls parados 15.0s`, audio sigue). `get_function` (overlays.cpp)
registra el fallo y llama a `std::exit(EXIT_FAILURE)`; el hilo de juego queda en `osRecvMesg` del
loader y el resto sigue (audio/VI), con lo que se ve como cuelgue.

## 2. Causa

En el módulo 55, `M55_FUN_8037fed4` tiene en `0x8037FF6C` una rama a `0x80380010`, que cae **dentro**
de `M55_FUN_8037fff0` (0x8037FFF0..0x803800C4). Es la segunda entrada de la misma función (comparten
epílogo en `0x803800A0`). Al cruzar el límite de símbolo, N64Recomp la compila como tail call
(`LOOKUP_FUNC(0x80380010)`), pero no había ninguna entrada registrada en esa dirección → lookup
fallido.

## 3. Fix aplicado (quirúrgico)

- `config/module_extras.json` (módulo 55): añadidos `0x80380010` y `0x803800A0`.
- `config/us_module55.syms.toml` y `config/us_combined.syms.toml`: partido `M55_FUN_8037fff0`
  (0xD4) en `0x8037FFF0:0x20` + `0x80380010:0x90` + `0x803800A0:0x24`. Se hizo **a mano** sobre la
  syms actual: regenerar el módulo entero con `gen_module_syms.py` producía cambios colaterales en
  la zona data-as-code (0x80388444..0x803899CC), el problema ya documentado del pipeline.
- `python3 tools/recomp.py --config config/game_combined.toml`: regenera `RecompiledFuncs` y
  `fix_fallthroughs`. Verificado con un diff por función: **solo** se añaden
  `M55_FUN_80380010`/`M55_FUN_803800a0` y cambian `M55_FUN_8037fed4` y `M55_FUN_8037fff0`.
- Smoke Linux (`build_dbg`, Xvfb, 30 s): arranca, corre y no hay `Failed to find`/SEGV.

## 4. Pendiente

1. Recompilar en Windows y repetir la entrega del objeto.
2. Si aparece otro `Failed to find function at 0x...` en el mismo flujo: repetir este patrón
   (añadir la dirección a `module_extras.json` + partir el símbolo correspondiente en
   `us_moduleNN.syms.toml` y `us_combined.syms.toml`, recompilar).
3. Si ya no falla esa ruta, seguir con el resto del TODO (mando X, teardown, guardado).
