# 2026-09-14 — Run largo de cutscenes, símbolos nuevos y callbacks del menú

Continuación de `2026-09-14-fix-fallthrough-secciones-y-cutscene.md` (tras el commit `9ff2c05`).

## Run largo (420 s) avanzando cutscenes — limpio

- Secuencia: `60:start, 84:start, 105:a, 115:a`, después **A cada 6 s** hasta 405 (sin más START).
- Resultado: **exit=0, 0 SEGV, 0 símbolos faltantes**, capturas `work/debug/port_adv3_*.png`.
- Estado: el juego sigue en la **intro cinemática** (retratos, personajes 3D); los diálogos avanzan
  con A. No se ha confirmado aún gameplay interactivo (control/HUD).

## Símbolos nuevos descubiertos

- El run largo anterior (con soft lookup) destapó dos mid-entries planas:
  - `0x8002442C` (25 llamadas), `0x800252F4` (2).
  - Añadidas con `add_missing_funcs.py` → `us_ghidra.syms.toml`; setup + recomp + build.
- Con soft lookup esas llamadas se convierten en no-ops (no crashean, pero pueden atascar el estado);
  por eso el primer run largo parecía vivo pero estancado.

## Crash del callback del menú (`M24_FUN_801cb71c`) — reproducido

- Pulsar **START durante las cutscenes** devuelve al menú/attract y cae en el callback con
  `$t5 = 0x8008D5D8`, `[0x8008D5D8+0x30] = 0` (global `0x8008D608`, sin inicializar) → SEGV en
  `MEM_B(0x4A, r14)`.
- El dispatcher `FUN_80005270` itera la lista `0x8008D5D4` y llama `nodo+0x1C` (aquí `0x801CB71C`,
  módulo 24) si `(ptr & 0x00800000) == 0`. El callback usa `$t5` sin inicializar dentro de la
  función: es una **continuación** que espera un puntero de contexto; en el port el global está a 0.
- Conclusión provisional: bug latente de estado/inicialización (no del recompilador). Evitar START
  tras entrar en el juego permite seguir. Pendiente: identificar quién debe escribir
  `0x8008D608` (candidato: una ruta de init del menú/attract).

## Evidencia

- `work/debug/run_adv3.log` (run de 420 s limpio), `port_adv3_{250,300,350,400,415}.png`.
- `work/debug/run_adv2.log` (SEGV del callback tras START en cutscene).
- `work/debug/run_long.log` (misses 0x8002442C / 0x800252F4).
