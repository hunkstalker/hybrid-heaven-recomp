# 2026-09-13 — Resuelta la corrupción de contextos de audio; nueva frontera: evento de módulo 0x7D

> Continúa `2026-09-13-ucode-audio-gate-transicion.md` y el work order
> `2026-09-13-workorder-audio-ai-descriptor.md`. Evidencia de la sesión que cierra el crash del
> driver de audio (`ctx+4` basura) y abre la siguiente frontera de la transición.

## 1. Causa raíz del descriptor corrupto (resuelta)

El crash de `FUN_8001FD14` (`lh a1,4(v1)`, `v1 = *(ctx+4)`) **no era** una escritura suelta: era el
resultado de encadenar:

1. La cola **virtual** de audio (headless, `support.cpp`) puede superar transitoriamente la ventana
   que asume el driver del juego. `FUN_8001FD14` calcula el tamaño del siguiente buffer como
   `(0x2E0 - osAiGetLength()/4 + 0x100) & 0xFFF0` y lo guarda en un **`s16`**
   (`[0x80096340]=0x2E0`, `[0x8009633C]=0x2D0`). Si `osAiGetLength() > 0x3E0` palabras el resultado
   hace wrap y el `s16` queda negativo (p.ej. `0xC6B0`).
2. La siguiente vuelta del driver llama `osAiSetNextBuffer(ptr, (s16)size<<2)` con **~4 GiB**
   (`0xFFFF1AC0`), y `queue_audio_buffer` los suma a `virtual_frames` (≈2³⁰ frames).
3. Desde ahí `osAiGetLength()` devuelve basura gigante; el driver encola tamaños envueltos en bucle y
   el mixer construye **command lists runaway** que se escriben de forma contigua desde el buffer de
   v1 (`0xC7A60`, `C7CE0`, …) **pisando las voces** v2 (`0xC89E0`) y v3 (`0xC99D0`), incluido
   `ctx+4`/`ctx+0x60`.
4. `*(ctx+4)` (back-pointer al descriptor de voz) pasa a valer muestras ADPCM (`F6EFF864`,
   `1D581AD5`, …) y el driver crashea al leer `{ptr,size}`.

Evidencia:
- `[CTXW]` (watch por VI de `voice+0x5C/+0x60/+0x64` y tabla `0x80091BE0`): corrupción a
  `vis=133/404/408/709/710` en `run_ctxwatch.log`/`run_ctxwatch2.log`.
- `[RSPW] PISA v2 dram=0C8960 len=280 dmem=5C0`: el DMA del ucode que pisa la voz (el ucode solo
  obedece las direcciones de `A_SAVEBUFF` que escribió el juego).
- `[UCD]`: secuencia de DMAs de escritura contiguos `0xC7A60, C7CE0, C7F60, …` de una misma task
  (`run_rspdma.log`), con `r25` = dirección objetivo del command list.
- `[AI ] t=1033 set_next ptr=800C8A50 bytes=4294963328` (`run_airate.log`): el byte_count negativo
  que envenena la cola; `rem` pasa de `0..1460` a `~4294965xxx`.
- Emulador (wplog sobre `0xC8A3C-0xC8A50`, `emu_ctxwp_wr.log`): `voice2+0x64` se escribe **una sola
  vez** (`pc=0x8001FAD8`, valor `0x800C89E0`) en 16 s.

## 2. Fixes aplicados (runtime, gitignored)

- `librecomp/src/ai.cpp` (`osAiSetNextBuffer_recomp`): si el `byte_count` es **negativo o absurdo**
  (`>0x200000`) se ignora (warn-once). Es defensa en profundidad: un tamaño envuelto por el juego no
  corresponde a ningún buffer real.
- `src/main/support.cpp` (`hh::queue_samples`, solo sin dispositivo SDL): la cola virtual se **acota
  a ~1 VI** (`sample_rate/60` frames). Evita que un burst de ticks supere la ventana del driver y
  que el cálculo del juego haga wrap. Log opt-in `[AI ] cola virtual acotada`.
- Diagnóstico permanente (gated): `[AI ]` con `t=` ms y `set_freq` (`ai.cpp`), `[CTXW]` por VI
  (`HH_CTXWATCH`, `events.cpp`), `[RSPW] PISA` en `rsp.hpp` (bajo `HH_CTXWATCH`), `[TRC]` pasa a
  `HH_TRCTRACE` (ya no inunda con `HH_TBLTRACE`), `[EVQ]` (productor de eventos de módulo).

## 3. Target indirecto del ucode que faltaba (resuelto)

A partir de t≈13,4 s el ucode abortaba con `Unhandled jump target 0x144C` (`hh_aspMain.cpp:112`):
la tabla de comandos del aspMain mapea **cmd 0x0F → 0x144C** y **cmd 0x0E → 0x170C**, ausentes en
`extra_indirect_branch_targets`. Añadidos en `config/rsp_hh_aspMain.toml` y regenerado
`port/HybridHeavenRecomp/rsp/hh_aspMain.cpp` con `RSPRecomp` (0 errores; incluye `case 0x144C` y
`case 0x170C`). Resultado: **0** `Unhandled jump target` en los runs posteriores.

## 4. Verificación (criterios del work order de audio)

- Run de **300 s** (`work/debug/run_ucodefix.log`): **17.981 audio tasks** (~60/s), `exit=0`,
  **0** SEGV, **0** `[RSPW] PISA`, **0** `Unhandled jump target`, **0** `IGNORADO`; `[CTXW]` sin
  cambios tras el init (voces intactas); `rem` entre 0 y 1460 bytes (ventana sana).
- Run largo de 420 s (`work/debug/run_trans300.log`): estable igualmente.
- Criterio del work order: “sin crash con ≥4200 tasks en ≥4 min” → **cumplido**.

## 5. Nueva frontera: el burst de la transición no se dispara (evento 0x7D)

Timeline de eventos del motor de audio (cola de módulos en `0x800CBB28`, productor
`FUN_800207D0`, consumidor `FUN_80020F60` → `FUN_80021EB8`), medido en el emulador con
`HB_TRACE_EXEC` (`emu_evp70_wr.log`):

| t (emu) | evento | observación |
|---|---|---|
| 10,49 s | `0x87` | carga `0x801B6600` (hito ya alcanzado por el port) |
| 62,94 s | `0x08` | preludio |
| 65,21 s | `0x7D` | dispara el burst del loader (12 cargas, id Nisitenma 0x19) |
| 68,2 s+ | `0x1C9` | eventos periódicos |

En el port (`run_trans300.log`, 420 s):

- `[EVQ] id=0x087` a t≈10,5 s (igual que el emulador) y `[EVQ] id=0x08` a t≈108 s (el emulador a
  62,9 s) → los scripts **sí** avanzan, pero con retraso.
- Tras el `0x08` el setter instala `[SETCB] obj=801D0474 cb=801C2050`, y **ese callback nunca se
  despacha** (`[M23]` sigue llamando solo a `FUN_801BF1CC`; el nodo `0x801D03C0+0x1C` sigue en
  `0x801BF1CC`).
- No aparece el evento `0x7D`, no hay burst del loader (`[LD384]` = 11), `fe00=0`.

Estado del consumidor: en el emulador `0x800CBAF0` (máquina de estados de `FUN_80020460`) solo se
escribe una vez (memset de boot) en 70 s; el port también lo mantiene 0. `FUN_80020F60` es
alcanzable solo vía `FUN_8002059C` (rama `estado==8` de `FUN_80020460`), y `FUN_800203C4` (que fija
`estado=8`) no tiene caller estático en el código recompilado ni puntero almacenado en RDRAM
(buscar el caller indirecto). **Nuevo (`run_evqc.log`)**: `FUN_80020F60` **sí** corre y consume
eventos individuales (`[EVQC] cnt0=1 cnt1=0`, n=20769), así que el atasco está aguas abajo: en el
handler del id consumido (tabla `0x80047E0C`) o en la cadena del callback `801C2050`. Hipótesis
operativas:
1. La rama que procesa `0x800CBB28` no se ejecuta y el evento `0x08` queda sin consumir; el
   siguiente script no avanza. Instrumentar `FUN_80020F60`/`FUN_8002059C` y la transición de estado
   de `FUN_80020460`.
2. El callback `801C2050` (nodo `0x801D0474`) lo debe llamar el dispatcher del padre; comparar con
   el emulador quién lo invoca y con qué argumentos (mismo patrón que el setter-chain del arranque).
3. La cadencia de script del port es más lenta que el emulador (0x08 a 108 s vs 62,9 s): medir si el
   avance depende de samples de audio o de VIs.

## 6. Artefactos (gitignored, `work/debug/`)

Port: `run_ctxwatch.log`, `run_ctxwatch2.log`, `run_rspdma.log`, `run_airate.log`, `run_aifix.log`,
`run_ucodefix.log`, `run_evq.log`, `run_evq2.log`, `run_trans300.log`, `run_evqc.log`.
Emulador: `emu_ctxwp*` (+`emu_ctxwp_wr.log`), `emu_aiwp*` (falla al vigilar MMIO del AI),
`emu_evp70_wr.log`, `emu_req_wr.log`, `emu_st8_wr.log`, `emu_ai19_parsed.txt`.

## 7. Comandos reproducibles

```sh
# Regenerar el ucode de audio (tras tocar config/rsp_hh_aspMain.toml)
toolchain/src/N64Recomp/build_recomp/RSPRecomp config/rsp_hh_aspMain.toml
cp work/rsp/hh_aspMain.cpp port/HybridHeavenRecomp/rsp/hh_aspMain.cpp

# Watch de contextos + DMAs del ucode
HH_VERBOSE=1 HH_TBLTRACE=1 HH_SP_SHARED=1 HH_CTXWATCH=1 timeout 300 "./Hybrid Heaven Recomp"

# Eventos de módulo del emulador (productor) y del port ([EVQ] con HH_TBLTRACE)
HB_TRACE_EXEC=0x800207D0 ... ./work/r64dump work/roms/us_retail.z64 <prefix> 70
```
