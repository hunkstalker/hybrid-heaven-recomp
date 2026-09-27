# 2026-09-27 — Release limpia: diagnósticos y volcados desactivados por defecto (v0.5.1)

> Sesión `main`. Petición del mantenedor: el `.exe` de release **no debe dejar ficheros de volcado**.
> Todo lo que los genera se **desactiva** (opt-in), no se elimina: puede volver a necesitarse. Se
> deja **solo `hh.log`**, sobrescrito en cada arranque, como salida para diagnóstico/errores.

## 1. Qué se escribía en un arranque normal (medido en `build/windows/bin/Release/`)

Tras un run del `.exe` release aparecían: `hh.log` (deseado), y además **siempre activos**:

| Fichero | Origen | Gate previo |
|---|---|---|
| `hh_audio.log` | `src/platform/support.cpp` (`hh_audio_diag_log`) | **ninguno** |
| `hh_tick.log`, `hh_slow.log` | `src/subsystems/input.cpp` (`get_input`) | **ninguno** |
| `hh_state.log`, `hh_slice.log`, `hh_hang.log`, `hh_hang_ram.log`, `hh_flag.log` | `src/platform/main.cpp` (`hh_hang_watchdog`) | **ninguno** (hilos al arrancar) |
| `hh_crash.log` + `hh_crash_rdram/dmem_*.bin` | handlers de crash (`main.cpp`) | **ninguno** (POSIX `hh_segv_handler` y Windows `SetUnhandledExceptionFilter` se instalaban siempre) |
| `hh_pak.log` | fork NMR (`ultramodern/.../hh_paklog.hpp`) | activo por defecto (`HH_PAKLOG` sin definir ⇒ escribía) |

Los demás (`hh_hud.log`, `hh_menudl.log`, `hh_rdram_dump.bin`, `hh_replay.log`, `hh_pace.log`,
`hh_framelog.log`, `hh_canary/trace/...`) ya eran opt-in.

## 2. Cambios

Port:

- `hh_audio_diag_log`: early-return salvo `HH_DIAG`.
- `input.cpp`: el bloque de `hh_tick.log`/`hh_slow.log` solo con `HH_DIAG`.
- `main.cpp`: el watchdog (`hh_hang_watchdog`) solo se arranca con `HH_DIAG`; los handlers de crash
  (POSIX `hh_segv_handler` y Windows `hh_win_exc_handler`) solo se instalan con `HH_CRASH_LOG`.
- `hh.log` sigue abriéndose en modo `"w"` (se **sobrescribe** cada run).

Fork NMR (`lib/N64ModernRuntime`, commit `39baeeb`):

- `hh_paklog.hpp`: por defecto **no** escribe; se activa con `HH_PAKLOG=1` (o una ruta). Actualizado
  `runtime.lock` (`NMR_COMMIT`).

## 3. Validación

- **Linux headless** (`HH_HEADLESS=1`, ~35 s): borrados los volcados y tras el run **solo** queda
  `hh.log`; no reaparecen `hh_audio/tick/slow/state/slice/hang/flag/pak/crash`.
- **Windows**: pendiente de validar por el mantenedor (`.exe` release: solo debe dejar `hh.log`,
  `config.ini`, `saves/`, `cache/`).

## 4. Cómo reactivar (depuración)

`HH_DIAG=1` (audio/tick/watchdog), `HH_CRASH_LOG=1` (crash + RDRAM/DMEM), `HH_PAKLOG=1` (Controller
Pak). Los diagnósticos que ya eran opt-in no cambian.

## 5. Release

PATCH (`0.5.0` → **`0.5.1`**): limpieza de salida, sin cambios de comportamiento jugable. Título en
`docs/releases/v0.5.1.md`. Requiere **push del fork NMR** (commit `39baeeb`) antes que el de `main`.
