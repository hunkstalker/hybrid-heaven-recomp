# 2026-09-11 — Modelo de módulos `trans` (Fase A #1)

> Evidencia de sesión. No editar. Resultado: **base determinista + contrato**; ADR 0001 aceptado.

## Objetivo
Caracterizar cómo el juego carga/ejecuta código no plano (`trans`): determinismo de bases,
contrato del módulo, origen del asset. (Plan: `TODO.md` Fase A #1.)

## Método
3 runs headless con gdb (breakpoints en `FUN_80003824` = descompresor/carga, y en `get_function`
= resoluciones indirectas). Script `/tmp/mod.gdb`; logs en `/tmp/opencode/mod_run{1,2,3}.log`.

## Resultados

1. **Una sola carga de módulo antes del bloqueante**, idéntica en 3 runs:
   - `src=0x004e69a8 base=0x80107830 size=0x55dd4`
   - Corresponde a **Nisitenma índice 7**: ROM `0x4E69A8`, comprimido `0x55DD4`, **descomprimido
     `0x89DB0` = 564464 bytes de MIPS**, CRC32 `0xA9213032` (`notes/us_manifest.yaml`).
2. **Base determinista**: `0x80107830` en los 3 runs (aunque sea una reserva de heap).
3. **Grafo de llamadas determinista**: el conjunto de **54 direcciones** resueltas por
   `get_function` es idéntico en los 3 runs (los conteos varían ~30–31k por timing de VI/hilos).
4. **Coste**: dominado por `FUN_80003D3C` (29 919 llamadas) porque
   `use_lookup_for_all_function_calls = true` hace que **toda** llamada pase por lookup.

## Contrato del módulo

- El blob en `0x80107830` es **MIPS crudo autoligado**: funciones en `base+offset` (entry en
  offset 0); usa **direcciones absolutas** (p. ej. `jal 0x800058dc` hacia el código plano, y
  punteros a sí mismo como `0x80107864`). **No requiere relocs** → recompilar a vram `0x80107830`
  es coherente.
- El salto procede de un **descriptor** en heap `0x801bf1b0`:
  `+0x04 = 0x80089378`, `+0x14 = 0x80000000`, **`+0x1C = 0x80107830`** (puntero de función = base).
  Lo consume `FUN_80005270` (`jalr *(s0+0x1C)`).

## Conclusión

- **ADR 0001 → Opción A** (pre-recompilar módulos y registrarlos en su base) es viable: la base del
  módulo de boot es determinista y el blob es autoligado.
- **Caveat**: solo se pudo medir el módulo de boot (los siguientes quedan tras el bloqueante). Si
  alguna base posterior resultara no determinista, se aplica **B** (fijar el asignador) como seguro.
- Hallazgo colateral: evaluar `use_lookup_for_all_function_calls = false` con las syms Ghidra
  (evitaría ~30k lookups/arranque y simplifica el pipeline).
