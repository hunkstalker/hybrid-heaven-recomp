# HH_DIAG (logs de diagnóstico opcionales) y protocolo de comparación Linux ↔ Windows

> Cierre de la Fase 2 (limpieza de instrumentación) y preparación de la Fase 3 en la máquina real.
> Continúa `notes/2026-09-17-fase2-ablacion-yield-y-descubrimiento-io.md`. Fecha: 2026-09-17.

## 1. Qué cambia: `HH_DIAG=1`

Los logs **always-on** que degradaban el pacing (sobre todo en 9p) pasan a estar **desactivados por
defecto** y se activan con `HH_DIAG=1`:

| Log | Antes | Ahora |
|---|---|---|
| `hh_sched.log` (scheduler) | siempre | `HH_DIAG=1` |
| `hh_pi.log` (DMA PI) | siempre | `HH_DIAG=1` (tras el reinicio de Windows que liberó el handle) |
| `hh_mq.log` (cola del loader) | siempre | `HH_DIAG=1` |
| `hh_cmds.log` (cola de comandos) | siempre | `HH_DIAG=1` |
| `hh_ovl.log` (overlays/módulos) | siempre | `HH_DIAG=1` |
| `hh_rsp.log` (tiempos task audio) | siempre | `HH_DIAG=1` |

Siempre activos (sin cambios): `hh_state.log` (`HH_STATE_SECS`), `hh_crash.log` + dumps
(RDRAM/DMEM), `hh_hang.log`, `hh_missing.log`, `hh_badlookup.log`, `hh_pak.log`, `hh_audio.log`.
Los logs **opt-in** no cambian: `HH_TRACE`, `HH_WAITLOG`, `HH_MQLOG_ALL`, `HH_WATCH/HH_CANARY/
HH_DRWATCH`, `HH_AUDIOLOG`.

Bats de diagnóstico actualizados para conservar el comportamiento previo: `run_mqlog.bat`,
`run_watch.bat`, `run_corrupt.bat` ahora ponen `HH_DIAG=1`.

## 2. Resultado en Linux (CWD en el 9p del proyecto, sin tmpfs)

| Pasada | frame/s | disp/s | polls/s | audio/s | VI/s |
|---|---|---|---|---|---|
| Antes (logs always-on, disco) | 24 | 17,5 | ~16 | ~59 | 60 |
| **Después (defaults, 120 s)** | — | — | **29,0** | 52,3 | 60,0 |
| **Después (`trace`, 45 s)** | 55,3 | **32,9** | ~30 | **60,0** | 60 |

- Objetivo del work order (disp ≈30/s, 0,5/VI): **cumplido** (32,9-33,2/s con traza; 29/s sin).
- El audio (virtual en contenedor) queda entre 52 y 60/s según pasada (60,0/s en L2 y L3).
- Pasada final **L3** (45 s, `trace`, ya con `pi.cpp` gateado): frame 56,1/s, disp 33,2/s, gaps med
  17 ms, **polls 28,9/s y audio 60,0/s** (steady t=10..40). Por defecto solo se escriben
  `hh_state.log` (+`hh_pak.log`); `HH_DIAG=1` verificado: reaparecen `hh_pi/hh_sched/hh_mq/hh_cmds/
  hh_ovl/hh_rsp`.
- Artefactos: `work/debug/pacing_linux/logs_pacing_L1/`, `logs_pacing_L2/`, `logs_pacing_L3/` y
  `smoke_diag_off/` + `smoke_diag_on/` (verificación del gating).

## 3. Protocolo Windows (Fase 3) — lo ejecuta el mantenedor

Requisitos: ROM en `build_win\bin\Release\rom\baserom.us.z64`, mando conectado (no hace falta).

1. **Build** (runtime local con los cambios de instrumentación):
   ```bat
   port\build_windows.local.bat
   ```
2. **T2 — pacing** (2-3 min de gameplay):
   ```bat
   port\run_pacing.bat
   ```
   Al cerrar, guarda `logs_pacing_<fecha>\` e imprime las últimas líneas de `hh_state.log`.
   **Pegar aquí** las líneas `=== HH estado t=… VI=… polls=… audio=…` (o pasar el fichero).
3. **T3 — gate `cd4c`** (~20-30 s, gameplay o menú):
   ```bat
   port\run_pacing.bat gate
   ```
   Adjunta `gate_console_*.log` (contiene `[GATE]`, `[GATE2]`, `[SUBM]`) o al menos el conteo de
   líneas por nivel `cd4c` (0/1/2), si te es más cómodo contar con `findstr /C:"[GATE] vis="`.
4. **T4 — repro del CaC**: `port\run_corrupt.bat` (ya lleva `HH_DIAG=1`): ¿se corrompe/atasca igual?
5. **T5 — guardado en cápsula**: re-test rápido de la UI de slots + `.pak` en `saves\`.

### Plantilla de comparación (rellenar con T2/T3)

| Métrica | Linux (contenedor, llvmpipe) | Windows (RTX 4080) |
|---|---|---|
| VI/s | 60,0 | |
| polls/s (steady) | 29-30 | |
| frame/s (si `trace`) | 55,3 | |
| disp/s (si `trace`) | 32,9 | |
| audio/s | 52-60 (virtual) | |
| `cd4c` 0/1/2 (si `gate`) | pendiente (re-medir) | |
| `[GATE2]` `fl8=40` send=recv | sí (1:1) | |

Interpretación esperada: en Windows el coste gfx (llvmpipe ≈250% CPU aquí) desaparece con la 4080;
si `polls` ≈30/s y `audio` ≈60/s, la cadencia queda 1:1 con el original y se pasa al re-test del CaC
con la cadencia corregida.

## 4. Pendientes/avisos

- **`pi.cpp` gateado** (2026-09-17, tras reiniciar Windows y liberarse el handle). Gating completo.
- Los cambios del runtime local siguen **sin commitear** (árbol del fork); no se hace push sin pedirlo.
- `run_pacing.bat` es nuevo (versionado); `build_windows.local.bat` sigue sin versionar (ADR 0005).
