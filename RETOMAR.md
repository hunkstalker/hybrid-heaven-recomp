# RETOMAR — handoff (2026-10-05)

> Handoff corto. **`main`** = **`v0.7.2` publicada** + **`v0.7.3`** (commit de release `0a3bd9f` ya
> **pusheado**; en local 1 por delante, `baa6187`, con la **regla de release**). **Falta**: tu push/tag de
> `v0.7.3` (los tags los pones a mano desde GitHub). **Fase A/B/A1 CERRADAS** (abajo). **TAREA SIGUIENTE
> (candidata principal): estabilidad en transiciones/carga/arranque** (stalls de carga al cruzar puerta).
> Histórico detallado: `notes/archive/2026-10-05-retomar-legacy.md`. Reglas: `AGENTS.md`,
> `docs/documentation.md`.

## Estado (2026-10-05)

- **v0.7.2** publicada: cámara al apuntar + objeto del título.
- **v0.7.3**: **A1 tick determinista** (2 VI/frame; 120 fps sin parones), **fix (0b)** del tagging de
  `C768` en gameplay (regresión de v0.7.2), **2D `ID_IGNORE`** tipos 9/13, **oráculo de emparejamiento**
  (`docs/interpolacion-pairing.md`). Notas: `notes/2026-10-05-a1-tick-determinista.md`,
  `notes/2026-10-05-fase-b-materializacion-c768.md`.
- **Fase A** (libultra) → v0.7.1. **Fase B** (emparejamiento) cerrada y medida (área 1 99.99% por id).

## TAREA SIGUIENTE — estabilidad en transiciones/carga/arranque

A1 quitó los slips del tick; las **bajadas restantes** de fps son **stalls de carga** (`guest_busy`
200-500 ms) al descomprimir módulos `trans` al **cruzar puertas / cargar áreas / arrancar**
(`hh_slow.log`; coinciden con los segundos de `present<115`). Objetivo: mantener el refresco también ahí.
- Mitigación: **precarga/caché de módulos** (cargar el área siguiente antes de la puerta; cachear lo ya
  decodificado) + audio/DMA. Es la mitad "compensación de stalls" del work order A1.
- Criterio: sin picos `guest_busy` grandes en puertas; `present` estable en transiciones.
- Contexto: `notes/2026-10-05-a1-tick-determinista.md` (residual) y
  `notes/2026-10-02-workorder-desbloquear-fps-interpolacion.md`.

## Otras pendientes (épica FPS)

- **A3**: validar 120/240 + Steam Deck (regresión). · **B**: spike 60 Hz real + ADR. · **C**: desacoplar
  audio del tick 30 Hz. · **Higiene**: retirar instrumentación de pasada 2/tagging al cerrar la épica.

## Instrumentación (reutilizable)

- **Cadencia**: `HH_FPS=1` → `[hh-fps]` + `[hh-fps-sum]` (mean/min/max/at_target%); `HH_DIAG=1` →
  `hh_tick.log` (`d1..d4+`) y `hh_slow.log` (>36 ms: `guest_busy`…); `HH_STATE_SECS`.
- **Present/video**: `HH_REFRESH_RATE=original|display|manual:<hz>`; F9 toggle interpolación; F8 menú.
- **Runtime**: `HH_DET_CLOCK` (+ `HH_DET_CLOCK_BIAS`), `HH_VI_EVERY`.
- **Tagging/interpolación**: `HH_MTXGROUP`, `HH_EMIT_TAG`, `HH_PAIRING`, `HH_PAIRING_LOG`/`HH_CAM_LOG`,
  `HH_PAIRCAP`/`HH_GENCAP`, `HH_SCALE_GATE`.

## Run (mantenedor)

```powershell
hybrid-heaven-recomp\build_windows.local.bat
$env:HH_FPS='1'; $env:HH_DIAG='1'
hybrid-heaven-recomp\run_windows.bat release
```
Logs en `build\windows\bin\Release\`. Borrar `hh_*.log` antes de cada run.

## Árbol y pistas

- `main`: `lib/rt64` = `234151a`, `lib/N64ModernRuntime` = `a11fbf2`, N64Recomp `cab94d9` (forks
  publicados; coinciden con `runtime.lock`). Tagging **ON por defecto**.
- Tick/lógica: `src/subsystems/input.cpp`, `src/platform/main.cpp`, runtime (`events.cpp`, `timer.cpp`).
- Present: `src/platform/rt64_render_context.cpp`; RT64 `lib/rt64`.
- **Carga/módulos `trans`** (tarea siguiente): loader del runtime (`lib/N64ModernRuntime`).

## Pitfalls (NO repetir)

- No confundir fps **presentados** con lógica; "240 reales" **no** es objetivo.
- La **vista no valida**; validar por métrica. No concluir freeze solo desde headless.
- Botones de acción por **flanco**; auto-repeat solo direcciones.
- **NO** `git reset --hard`; no editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
- Release: se **pushea el commit de release** para CI; el **tag lo pone el mantenedor a mano** en GitHub.
