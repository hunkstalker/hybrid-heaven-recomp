# 2026-09-21 — Audio: petardeo ligero — causa probable y plan (con la referencia)

> Nota de tarea para sesión fresca. El resto del port está **validado en Windows** y **publicado**
> (Release `v0.1.1`); queda cerrar el **petardeo ligero** de audio. Ver `../RETOMAR.md`.

## 1. Síntoma y datos (Windows)

- El audio petardea **ligeramente**; **igual antes y después** del PLL (no cambió).
- `hh_audio.log` (build con PLL): `frames/s ≈ 44–46k` frente a `rate=43200` → el juego produce
  **~3–6% de más**; `queued ≈ 6000–6900` (pegado al watermark de **150 ms** = 6480 frames) y
  `drops/s ≈ 2–6` → **la salvaguarda dura está descartando buffers** (un descarte = un clic).

## 2. Intentos hechos (sin resolver)

- **PLL lineal** en `src/platform/support.cpp` (`HH_AI_SYNC` on, `HH_AI_TARGET_MS`=50,
  `HH_AI_MAXC`=0.03): no drena; el desajuste (~3–6%) **satura** el tope. Con `HH_AI_MAXC=0.06`
  sigue habiendo `drops/s≈2–5`.
- **Offset del reporte** `HH_AI_LEN_OFFSET` (fork NMR `cae028e`, `ultramodern/src/audio.cpp`):
  añadido pero **sin probar** (default 0=fiel). Debería hacer que el juego produzca menos si es
  positivo.

## 3. Lo que hace la REFERENCIA (MIT) — solución probada

`danielgomesvieira2000/hybrid-heaven-recomp`: `src/resample.cpp`, `include/hh/resample.h`,
`src/callbacks.cpp` (sección audio), `src/audiodiag.cpp`.

1. **Resampler propio en el port** (windowed-sinc, 64 taps, Kaiser β=8.6, **continuo entre
   buffers**) y **abre el dispositivo a la tasa real del hardware** → SDL no resamplea.
   Motivo medido: el resampler de SDL **pierde continuidad en cada bloque** (SINAD 14.4 dB frente a
   43.4 dB de una conversión continua) → **crackle**. `HH_AUDIO_NO_RESAMPLE=1` revierte.
2. **Profundidad de cola por *headroom***: `get_frames_remaining()` responde al juego
   `cola_en_su_tasa − headroom` (`kQueueHeadroomMs`=30, `HH_AUDIO_HEADROOM_MS`). El juego
   **dimensiona cada buffer con ese valor**, así que la cola se asienta **más profunda** y **nunca
   toca cero**. Clave: SDL, al drenar, pide un **periodo entero** y **rellena con ceros sin
   esperar**; si la cola toca cero → hueco = crackle.
3. **Periodo del dispositivo 512 frames** (`HH_AUDIO_PERIOD`).
4. **Canales**: la referencia **des-swapea L/R** porque librecomp guarda RDRAM byte-swapped y un
   puntero crudo invierte los dos int16 de cada palabra. **Verificar si nuestro port tiene el
   estéreo invertido** (nosotros **no** lo hacemos en `queue_samples`).
5. Diagnóstico `HH_AUDIO_STATS` (cola real, subidas por periodo).

## 4. Diferencia de modelo (importante)

- **Nosotros**: con `HH_AI_FIFO` on, `get_remaining_audio_bytes` devuelve el **restante del DMA del
  FIFO** (modelo hardware). La cola SDL **no se controla** → crece (sobreproducción) → descartes.
- **Referencia**: el juego ve la **cola SDL** (en frames del juego) **menos headroom** → la cola se
  controla directamente (sin underrun ni sobrecrecimiento).
- Nuestro FIFO se introdujo para el **CaC** (hoy resuelto por la migración ELF; ver
  `2026-09-17-replay-mode-vi-vis-negativo.md` §5b–5d). **Hipótesis**: se puede sustituir/combinar
  por el modelo de la referencia.

## 5. Plan propuesto (sesión fresca)

1. **Probar `HH_AI_LEN_OFFSET` > 0** (reconstruir Windows): objetivo `frames/s → 43200`,
   `drops/s → 0`. Es la palanca rápida (conceptual al headroom). Probar 50/100/150/200 y anotar.
1b. **Experimento ya montado** (opt-in, fork NMR `21af731`): `HH_AI_REPORT_SDL=1` hace que
   `get_remaining_audio_bytes` reporte la **cola SDL real − headroom** (`HH_AI_HEADROOM_MS`=30) en
   vez del FIFO; el FIFO sigue llevando el **evento AI** (`hh_ai_fifo_poll`). Es el modelo de la
   referencia. Objetivo: `queued` asentada en ~headroom (~1300 frames) y `drops/s=0`.
2. **Adoptar el enfoque de la referencia** si (1) no basta o el audio sigue sucio:
   resampler propio (adaptar `resample.{h,cpp}`, crédito MIT) + dispositivo a tasa de hardware +
   **headroom** en el reporte + periodo 512. Decidir cómo convive con `HH_AI_FIFO`.
3. **Verificar el swap L/R** (§3.4).
4. **Re-validar el CaC** tras cambiar `osAiGetLength` (el AI estuvo implicado en su timing).
5. **Gate**: sin petardeo, `drops/s≈0`, cola estable; CaC y gameplay OK en Windows.

## 6. Punteros

- Referencia (local en la sesión): `/tmp/opencode/ref-hh/`.
- Nuestro código: `src/platform/support.cpp` (queue/`get_frames_remaining`/PLL),
  `lib/N64ModernRuntime/ultramodern/src/audio.cpp` (FIFO + `HH_AI_LEN_OFFSET`).
- Notas: `2026-09-18-suavizado-fase1-y-cache-loader.md` §2,
  `2026-09-17-replay-mode-vi-vis-negativo.md` §5b–5d.
- `docs/architecture.md` §5 (audio).
