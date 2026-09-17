# Validación Windows (RTX 4080): cadencia corregida y el freeze del CaC persiste

> Fase 3 del work order de pacing + arranque de la Parte B del plan del CaC. Fecha: 2026-09-17.
> Pasada del mantenedor con `port\run_pacing.bat` (modo pacing). Continúa
> `notes/2026-09-17-logdiag-y-comparacion-linux-windows.md`.

## 1. Entorno de la pasada

- i7-14700K + **RTX 4080** (RT64 nativo), WASAPI, audio a **43200 Hz** (reapertura desde 48000),
  mando Xbox con `config.ini`. Logs por defecto (sin `HH_DIAG`): solo `hh_state` + `hh_audio` +
  volcados. Carpeta de la pasada: `logs_pacing_20260917_123210\` (junto al `.exe`).
- Partida de ~8,5 min hasta el **mismo freeze al entrar en combate** (el bloqueante conocido).
- Observaciones de consola: `[S0FIX] r16 00000000 -> 80037748` (mitigación s0 actuando) y
  watchdog `[HANG] volcado escrito (polls 15.0s, audio 0.0s, VI=31153)`.

## 2. Cadencia: CUMPLE

`hh_state.log` (104 snapshots, steady t=10..520):

| Métrica | Windows (4080) | Linux (llvmpipe, L3) | Original |
|---|---|---|---|
| VI/s | 60,0 | 60,0 | 60 |
| polls/s | **27,1** (28,4 en t=25..200) | 28,9 | 30 |
| audio/s | **60,0** | 60,0 | 60 |

→ La cadencia queda dentro del ±10% del original y el audio a 60,0/s exactos. La divergencia de
cadencia **no era la causa del CaC** (o no la única): con la cadencia corregida el combate sigue
colgando.

## 3. Freeze del CaC (evidencia nueva)

- `polls` se congela en `14051` a t≈505 s (VI≈30300); `audio` y `VI` siguen a 60/s → **la lógica se
  atasca, el resto sigue vivo** (firma de cuelgue lógico, no de crash).
- Contexto de hilos del watchdog (`hh_state.log`/`hh_hang.log`):
  - **tid 5** (lógica): `r4=8005C288` → bloqueado en su **cola de comandos** esperando un mensaje
    que no llega (misma familia que el cuelgue del NPC; el volcado ring2 no salta porque `sp` no
    está hundido: `8005BF38`).
  - tid 16 → `0x8005C528`, tid 17 → `0x8005C4F0` (gate), tid 18 → `0x8005C4B8`, tid 19 → `0x8005C560`
    (VI), tid 3 → `0x80091DA0` (audio): todos esperando en sus colas, sin completaciones.
- `hh_hang_rdram_*.bin` (8 MB) y `hh_hang.log` quedaron en la carpeta de la pasada.

## 4. Limpieza de ruido (a petición)

- `[PAD] contexto: menu/juego` → **opt-in** con `HH_PADLOG=1` (el flapping menu↔juego en consola era
  ruido; antes se imprimía en cada cambio).
- Dump de audio `hh_audio_dump.bin` (4 MB con `fflush` por buffer al arrancar) → **opt-in** con
  `HH_AUDIODUMP=<f>`; `hh_audio.log` (texto, 1 línea/s) sigue activo.
- `run_pacing.bat`: aparta los `hh_*.log` previos a `logs_prev\` antes de cada pasada (la carpeta de
  la pasada ya no arrastra logs viejos) y recoge también `boot.log` y los dumps
  `hh_hang_rdram_*.bin`/`hh_crash_*.bin`/`hh_audio_dump.bin`.

## 5. Siguiente

Con la cadencia ya corregida, toca la **Parte B** de `notes/2026-09-17-plan-revision-bloqueo-cac.md`:
el `case 2` de `M23_FUN_801c1dc0` (armado del combate) y la cadena de mensajes que deja a **tid 5
esperando en `0x8005C288`**. Evidencia útil: `hh_hang.log` + `hh_hang_rdram_*.bin` de esta pasada y
la nota `2026-09-16-combate-corrupcion-estado-8024a990.md`.
