# 2026-09-19 (noche-3) — Verificación independiente de la cadencia y del harness de replay

> Reanudación tras el cuelgue de la sesión anterior (que quedó en bucle). **No se da por buena**
> ninguna conclusión de `2026-09-19-inventario-y-nueva-evidencia-fase-previa.md` sin re-medirla.
> Se re-ejecutaron las medidas clave del tramo 17:03–18:00 (que quedó sin documentar) y se
> **corrigen** dos puntos: (1) el harness de replay del emulador consume el input ~2× más rápido
> que el port y contamina los hitos del front-end; (2) arreglar la cadencia de frames
> (`HH_VI_EVERY=2`) **no** corrige el adelanto.

## 0. Cómo se midió (reproducible)

- **Port** (`build_dbg/work/debug/port_*.log` propios; ejecutado 2026-09-19 noche-3):
  ```
  cd port/HybridHeavenRecomp/build_dbg
  DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy \
  VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_NOAUDIO=1 HH_NO_B280=1 \
  HH_REPLAY=<repo>/work/debug/replays/cac_full_20260918_210956.txt \
  HH_REPLAY_MODE=poll|vi HH_FRAMERATE=1 HH_LDTRACE=1 ./"Hybrid Heaven Recomp"
  ```
  (`HH_FRAMERATE` cuenta `FUN_80001454` y los polls en `[FRM] … frame= vi= in=`.)
- **Emulador**: `tools/analysis/emu_ref.sh` con `HH_KEYS_REPLAY=<replay> HB_TRACE_EXEC=…`
  (logs en `work/debug/m24/emu_*.log`). **Ojo**: emparejar cada bloque de parada
  (`[dbgcore] BP HIT` → `stop pc=` → `vi_count=` → `a0=`) leyendo los campos **posteriores** a
  `stop pc=`; un parser que lea hacia atrás da un desfase de una parada (causa de confusión).

## 1. Cadencia de frames verificada (port vs emulador)

`FUN_80001454` es el **frame real** del bucle principal `FUN_800011b0` (espera mensajes de la cola
`0x80063D78`; si `[0x80037748]==0` llama a `FUN_80001454`, si no al no-op `FUN_80001BB0`).

| Medida | Port | Emulador |
|---|---|---|
| `FUN_80001454` | **~58/s · 1,03 VI/frame** | **~30/s · 2,0 VI/frame** |
| polls de input (`get_input`/`GetKeys`) | **~30-33/s · 0,51-0,55/VI** | **~51-58/s · 0,86-1,0/VI** |
| polls por frame | ~0,52 | ~1,8 |

- La grabación (`cac_full_20260918_210956.txt`) es de **9815 muestras / 329 s = 0,5 muestras/VI**
  (`vis` 37→19812). El port **poll** consume 1 muestra/poll a ~0,5 polls/VI ⇒ consume a la tasa
  grabada. El emulador consume 1 muestra/poll a ~1 poll/VI ⇒ consume el replay **~2× rápido**.
- Ambos harnesses son **poll-indexed**: el port en `HH_REPLAY_MODE=poll` avanza `idx++` por poll
  (`src/game/input.cpp:745`); el plugin del emulador avanza 1 por `GetKeys(ctl0)`.

## 2. El hito del emulador NO es robusto (depende del padding del replay)

Carga #12 M24 = loader `005FBEC6→801BF1A0`. Mismo replay, distinto padding:

| Replay del emulador | M23 `005F1190` | #11 `0005D280` | **#12 M24** | M8 `0053C77C` |
|---|---|---|---|---|
| original (0,5×) | vi 226 | vi 349 | **vi 1535** | vi 1869 |
| `cac_pad163` (1,63×) | vi 174 | vi 297 | **vi 2959** | vi 4113 |
| `cac_dup` (stride 2) | vi 204 | vi 327 | **>70 s (no llega)** | — |

⇒ El `vi 1535` del emulador **no** es una referencia estable: es el resultado de aplicar el input
demasiado pronto en VI (el START de menú cae fuera de la ventana del director de escena y se
pierde, alargando la espera). El alargar el replay lo aleja aún más.

## 3. El port (poll/vi) y la inestabilidad del hito

| Replay port | #11 `0005D280` | **#12 M24** | M8 |
|---|---|---|---|
| `poll` (original) | vi 224 · gframe 173 · s=113 | **vi 436 · gframe 367 · s=217** | vi 618 |
| `vi` (original) | vi 248 · gframe 214 · s=152 | **vi 558 · gframe 510 · s=306** | — |
| `poll` + `HH_VI_EVERY=2` | vi 306 · gframe 141 · s=113 | **vi 516 · gframe 246 · s=217** | — |

- **`HH_VI_EVERY=2` sí corrige la cadencia** (`ultramodern/src/events.cpp:371`: entrega el evento VI
  cada 2 VI) y deja el frame a **2,0 VI/frame**, pero #12 solo pasa de **vi 436 → 516**: **la
  cadencia de frames NO es la causa del adelanto** (el director del front-end no avanza por frame).
- `poll` y `vi` difieren en ~120 VI en #12 ⇒ la elección poll/vis mueve el hito, pero no ~1100 VI.

## 4. Qué queda en pie y qué no

**En pie (verificado):**
- El port ejecuta el frame a 1 VI/frame y el emulador a 2 VI/frame. Diferencia real y medida.
- El port consume el input a la tasa de la grabación; el emulador ~2× rápido.
- Los hitos del emulador son muy sensibles al mapeo muestra↔VI.

**NO verificado / a rehacer:**
- El "port ~20 s (~1200 VI) adelantado" y el "emu nunca toma la rama M10/M12" **dependen del
  harness del emulador**; con el input mal temporizado, la comparación no es válida tal cual.
- El `HH_VI_EVERY=2` no cierra la brecha, pero tampoco se probó con el input alineado.

## 5. Siguiente paso limpio (propuesto)

1. **Alinear el input del emulador al `vis` grabado** (harness vis-fiel): construir un replay
   re-muestreado a la tasa de poll medida (empezar por duplicar/estirar cada muestra para que su
   índice de aplicación ≈ su `vis`) y **re-verificar con la misma métrica** de §2/#12, M23 y M8.
   Solo si con input alineado el emulador sigue entrando al CaC sano y el port no, la referencia
   del emulador es válida.
2. **Reproducir el CaC con `HH_REPLAY_MODE=vi`** (no solo `poll`) para confirmar que el replay es
   válido independientemente de la elección poll/vis.
3. Decidir si el port (que sí reproduce la sesión original en `vis`) se depura contra **su propio**
   criterio (la cadena causal A→B ya está establecida) en vez de contra un emulador mal
   temporizado.

## 6. Instrumentación dejada en el runtime (sin commitear)

`port/HybridHeavenRecomp/lib/N64ModernRuntime` tiene un **diff sin commitear** en
`librecomp/src/overlays.cpp`: wrappers opt-in `HH_FRAMERATE` (`[FRM]`/`[NOOP]`), contador
`hh_get_game_frame_count`, `gframe=` en `[LD384]` y `bd56=`/`vi=` en trazas M23. Son de
diagnóstico; decidir si se commitean o se revierten. `HH_VI_EVERY` ya está en
`ultramodern/src/events.cpp` (rama del fork).
