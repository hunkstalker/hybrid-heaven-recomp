# Fix raíz: discontinuidad de posición en la interpolación (objeto del título)

> Sesión **2026-10-08**. En `main` + fix permanente en el fork **`lib/rt64`** (commit `db300ca`).
> Estado: **HECHO y validado en Windows** (mantenedor). Continúa
> `notes/2026-10-05-fase-b-camara-y-titulo.md` y `notes/2026-10-05-fase-b-materializacion-c768.md`.

## 1. Síntoma

En el **menú de título**, el **objeto 3D** se desplazaba "por coordenadas" (barrido) al **aumentar la
tasa de frames** (interpolación). Con el menú abierto se ocultaba (por el gate `native_title_active`,
que apagaba C768), pero en la pantalla **PRESS START** (sin input) no: allí `native_title_active` es
`false` → C768 emite → aparece el barrido. En el original (30 fps) no se veía: el objeto sí se
**teletransporta** (comportamiento real), pero al no interpolar no se percibía.

## 2. Diagnóstico (oráculo de pairing)

Instrumentación: `HH_C768_TRACE` (traza temporal en el hook de C768) + el **oráculo de RT64**
(`patches/rt64/hh-pairing-log.patch`: `HH_PAIRING_LOG`, con `HH_REFRESH_RATE=manual:60` para forzar
`targetRate>0` en headless).

- El artefacto es un **efecto C768** (`slot=28`, `iid=013F7B2B`) que da un salto de **479 u** de
  posición (`y:169 → -310`) en **1 frame**, cada **~256 frames** (~8,5 s).
- RT64 lo empareja por su **id estable** y **lo interpola** (`lerp=1`) → barrido:
  `T ... jump 479.4 lerp 1 cur (0,-310,0) prev (0,169,0)`.
- Los otros dos transforms del título (slots 26/27) no saltan.

Conclusión: el objeto **sí se teletransporta**; el problema no era el teletransporte, sino que la
**interpolación lo hacía visible** durante el salto.

## 3. Fix (raíz)

**Límite de distancia de pareja** en RT64 `GameFrame::computeTransformMatch` (`lib/rt64`,
`src/hle/rt64_game_frame.cpp`): si la diferencia de traslación entre el transform de este frame y el
del anterior supera `HH_PAIR_MAX` unidades (def. **150**; `0` lo apaga), el par se **rechaza** →
RT64 **no lo interpola** (snap) y no se ve el barrido. Es el método estándar
(`docs/interpolacion-pairing.md` §6).

Evidencia (oráculo):

| | max jump | pares >100 u |
|---|---|---|
| antes | 479.4 | 4 (todos `lerp=1`) |
| después | **0.6** | **0** (el salto sale como `U`, sin pareja) |

Commit del fork: **`db300ca`** (`fix(interp): gate de discontinuidad de posicion (limite de pareja) en
computeTransformMatch`). Gitlink + `runtime.lock` bumpeados en `main`.

## 4. Consecuencia pendiente

Con este gate, el **caso especial** del título (`native_title_active` apagando C768) queda
**redundante**: el efecto se maneja en cualquier escena. **Follow-up**: retirar el gate
(`src/hooks/model_tagging.cpp` + `include/hh/menu.h` + `src/subsystems/menu.cpp`) y validar menú.
De momento se **conserva** (lo validado es: PRESS START con el fix; menú con el gate).

## 5. Ficheros

- `lib/rt64/src/hle/rt64_game_frame.cpp` (fix; commit `db300ca` del fork).
- `runtime.lock` (pin RT64), gitlink `lib/rt64`.
- Instrumentación temporal (no versionada): traza `HH_C768_TRACE` (retirada), patch de pairing
  (solo diagnóstico).
