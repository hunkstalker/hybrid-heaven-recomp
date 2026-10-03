# FPS/interpolación — estado de la sesión y handoff (2026-10-02, tarde)

> Sesión sobre la épica **desbloquear FPS / arreglar la interpolación**. Estado real, sin inflar:
> lo implementado está **sin validar en Windows** (flags **off** por defecto) y **sin commitear**.
> Plan y catálogo: `notes/2026-10-02-workorder-desbloquear-fps-interpolacion.md`.

## 1. Establecido (medido / inferido)

- `[MEDIDO]` Los **4 issues abiertos** (#6 Procyon, #8 puertas, #10 enemigos al curar, #12 Life Charger)
  están atribuidos a la **interpolación** por el mantenedor; el A/B **F9 ON/OFF** del mantenedor
  confirma al menos el de puertas. Con `RefreshRate=Original` no ocurren.
- `[MEDIDO]` La **lógica de HH es 30 fps** (frame cada 2 VI; `notes/2026-09-17-fase0-...`).
- `[MEDIDO en el código de RT64]` El **present** se interpola de `viOriginalRate` (30) a `targetRate`
  (refresco del monitor, recortado); sin `gEXMatrixGroup` el emparejamiento es **heurístico**
  (`matchScenes`/`computeTransformMatch`), y `updateAngular` **siempre** interpola rotación/escala
  (`// FIXME`), a diferencia de la traslación que sí tiene *auto-gate* (`updateLinear`).
- `[INFERIDO, del mantenedor]` **#6 no es solo un flash de visibilidad**: el aura **se expande y hace
  un "replay" brusco** (parece un **reinicio de animación/escala** interpolado a través del salto). Que
  se vea más o menos dependería de la **tasa** del monitor (múltiplos de 30 vs 144/165).

## 2. Error de proceso (no repetir)

Se pidió al mantenedor jugar y sacar **2 capturas F7** (interpolación ON/OFF) para "ver el flash".
**F7 es la captura pareada del HUD** (`hh_cap_N.log` = traza de identidades **2D** + `hh_cap_N.bmp` =
screenshot), pensada para **widescreen/HUD**, **no** para diagnosticar un artefacto 3D. Además:
**un still no puede mostrar un flash de 1 frame ni una animación que se repite**. Regla: para
discontinuidades transitorias **no** pedir stills; usar A/B visual, el **Inspector (F1)** o, como mucho,
vídeo. `ffmpeg` está en el contenedor si hiciera falta.

## 3. Implementado (flag-gated, **sin validar**)

En el fork `lib/rt64` (`src/hle/rt64_rigid_body.cpp`) — **comportamiento original por defecto**:

- `HH_ROT_GATE=<°>` — *snap* si el giro prev↔cur supera el umbral (candidato #10).
- `HH_SCALE_GATE=<factor>` — *snap* si la escala de un eje cambia más de ese factor (candidato #6,
  "se expande y rebobina"). `HH_*_GATE_LOG=1` traza (tope 50).

En el port (`src/subsystems/input.cpp`): **F9 enlazado** a `hh::video_toggle_interpolation()`
(antes declarado pero **sin mapear**; por eso el A/B "no cambiaba nada").

Compila en Linux. **No** verificado en Windows. `lib/rt64` está **sucio** (submódulo por commitear).

## 4. Qué NO está hecho

- Ninguna prueba en Windows de los gates ni medición con `HH_FPS=1` (no se capturó `swapChain` real).
- **No** hay *transform tagging* real (Zelda64Recomp): eso requiere **inyectar `gEXMatrixGroup`** en
  las DLs del juego (o mejoras equivalentes en `rt64`), que aún no se ha diseñado para HH.
- No se ha tocado el audio ni la Fase B (60 Hz).

## 5. Siguiente paso recomendado

1. **A/B de los gates** en Windows (observación, sin capturas): `HH_ROT_GATE=120` en #10;
   `HH_SCALE_GATE=2` en #6. Ver si desaparece el efecto.
2. Si no basta: **mejorar el emparejamiento** en `rt64` (umbral de distancia en `matchTransform` /
   IDs estables) y/o diseñar la **inyección de tags** en las DLs.
3. Medir la dependencia de **tasa** (menú `FPS LIMIT` = NATIVE/60/120/144/240) **observando**, no capturando.
