# 2026-10-05 — Fase B: emparejamiento de ids (método estándar) — análisis y cierre de código

> El gate de posición de (0b) se **descartó** (ver §(0b)). Referencia del método:
> `danielgomesvieira2000/pilotwings-64-recomp` (`patches/interpolation.c`, `docs/PORTING.md`), resumido
> en `notes/2026-10-03-fps-tagging-dobj-y-handoff.md` §3c. **Pendiente de un run de validación en
> Windows** (paso 5). Distinción **medido / inferido** explícita.

## El método (checklist) vs lo implementado

| # | Método PW64 | En HH (`src/hooks/model_tagging.cpp`) | Estado |
|---|---|---|---|
| 1 | `id = FNV(kind, objeto, modelo, LOD)` (índice lógico, nunca dirección) | `interp_id(kind, g_obj_slot, node_slot, lod)`; `g_obj_slot`/`node_slot` de `stable_slot(root,model)` (identidad derivada del comportamiento: mismo root+modelo en el frame previo → mismo slot; reuso tras hueco → slot nuevo) | ✅ (LOD=0, ver §2) |
| 2 | Id mezclado con **generación de cámara** (avanza en cortes) | `sGeneration` en `interp_id`; corte si salto de cámara >90 u o giro >90° en un frame de 30 Hz | ✅ (validado 2026-10-04) |
| 3 | **Un grupo por objeto**, `G_EX_ORDER_LINEAR` | grupo por **nodo** (`func_800069A8`) con orden LINEAR; se desvió de “por objeto” porque fragmentaba al PJ (medido) | ✅ (adaptado y validado) |
| 4 | **Cámara = grupo de PROYECCIÓN** aparte | implementado pero **OFF** por defecto: en HH la cámara va **horneada** en el modelview → un grupo de proyección la duplica (validado 2026-10-05) | ✅ (desviación deliberada) |
| 5 | **Efectos → `ORDER_AUTO`**; **2D → `G_EX_ID_IGNORE`** | efectos tipos 1–4 y emisores/C768 → AUTO; **2D reales (tipos 9/13) → `gEXMatrixGroupNoInterpolate`** (fix de hoy) | ✅ |
| 6 | Un id sin pareja en el frame previo **no se interpola** (skip automático) | delegado a RT64 (sin lógica de spawn propia) | ✅ |

`[MEDIDO, código]` Con esto, **los 6 puntos del método están cubiertos** (3 con desviación
deliberada validada). No hay caminos de dibujo 3D fuera de estos hooks (ver §1).

## (1) Enumeración de sitios de dibujo 3D

`[MEDIDO]` En el C recompilado, **solo `build/recomp/RecompiledFuncs/funcs_77.c`** construye `G_MTX`
(`0xDA`, en F3DEX2). Las funciones que lo emiten **directamente** son 6: `func_80007DE4/82C4/8754/8B9C`,
`func_8000C4A8` (hueso) y, en overlay `file_053`, `func_801E4294` (solo **pasa** `0xDA3360` a
`func_801C0B8C`; no dibuja). El resto de emisores (`8F30`, `C768`, `A828`, `919C`, `11958`, …) usan
**G_MOVEWORD (0xDB) / G_MOVEMEM (0xDC) / G_DL (0xDE)** y delegan la matriz en helpers/sub-DLs; por eso
la cobertura se hace en el **traversal** (`func_800068C0`) y el **dispatch** (`func_800069A8`), no
función a función. **No aparece ningún camino de dibujo 3D fuera del traversal DOBJ.**

## (2) LOD — cerrado como “ya capturado” (no se añade campo)

`[MEDIDO]` `model+0x40/0x44/0x58` (los candidatos que volcaba `[hh-mtxgroup]`) son **display list /
puntero / count**, no un índice de LOD. `[INFERIDO]` En este motor el “modelo” (`node+0x2C`) es la
referencia de malla del nodo; si el juego cambia de malla por distancia, **cambia ese puntero** → ya va
en el id (`stable_slot` + `interp_id`) → no se interpola a través del cambio. Se mantiene `lod=0` hasta
un caso medido con popping.

## (3) 2D `G_EX_ID_IGNORE` — IMPLEMENTADO (hueco real)

`[MEDIDO]` El hook de nodo trataba los tipos **9 (`919C`) y 13 (`11958`)** —los **2D/texrect** reales
del jtbl (nota A2.2d)— como **3D `LINEAR`**, y en cambio aplicaba `NoInterpolate` a los tipos 1–4 (que
casi no se usan). Fix: `is_2d = (ntype==9 || ntype==13)` → `gEXMatrixGroupNoInterpolate`
(`G_EX_ID_IGNORE`), **ON por defecto**, `HH_FX_2D_IGNORE=0` lo apaga para A/B. Los tipos 1–4 siguen como
estaban (AUTO/no-interp). Compila en Linux. `[MEDIDO en código]`; sin validar.

## (4) `ORDER_AUTO` por efecto

`[MEDIDO]` Efectos de dispatch (1–4) y pasada 2 (`emitter_wrap`, `C768`) ya emiten `G_EX_ORDER_AUTO`;
las mallas/huesos, `LINEAR`. Sin cambios.

## (0b) Discontinuidad de POSICIÓN — intentado y DESCARTADO

`[MEDIDO]` Un enemigo en movimiento daba un salto de posición+escala de **1 frame**. Se probó un **gate
de posición en RT64** (`RigidBody::updateLinear`, `HH_POS_GATE` 150, snap) → **no lo arregló**.
`[INFERIDO]` El objeto se mueve de forma continua, así que no es un teletransporte; el gate (solo
traslación, umbral absoluto) no cubre el caso. Se **revirtió** el cambio del fork (árbol limpio). Si
tras validar la fase (5) persiste, se aborda con datos (captura del frame + matrices), no a ciegas.

## Instrumentación numérica nueva (diagnóstico del artefacto de 1 frame)

Sin depender de capturas (una imagen no sirve: no se conoce el juego):
- **`HH_SPIKE_LOG=1`** → `lib/rt64/src/hle/rt64_game_frame.cpp` (`matchTransform`): por cada transform
  emparejado, escribe `[HH_SPIKE] n id dpos dr pos prev->cur s prev->cur` **solo** si
  `dpos>30` o `dr>1.3` (ratio de escala). Tope 4000 líneas. Da la `matrixId` y las magnitudes exactas
  del frame del artefacto (no requiere el patch de instrumentación).
- **`HH_MTXGROUP_LOG=1`** → el port añade `[hh-id] <tag> id=… a=… b=… c=… d=… gen=…` (dedup, tope
  3000): traduce cada `matrixId` a su objeto (`node`/`emit`/`c768`/`cam`).
- **`HH_PAIRING=1`** (requiere el patch `patches/rt64/hh-interpolation-tagging.patch` para los
  contadores): `[hh-pair]` con `unpaired_moved`, `gen`, `ignored`, `explicit_ids`.

Con `hh_spike.log` (últimas líneas al cerrar) + `hh.log` (`[hh-id]`, `[hh-pair]`) se identifica el
objeto del salto y su magnitud sin interpretar imágenes.

## (5) Validación pendiente (Windows)

```
hybrid-heaven-recomp\build_windows.local.bat
$env:HH_PAIRING='1'; $env:HH_MTXGROUP_LOG='1'; $env:HH_PAIRCAP='3'
hybrid-heaven-recomp\run_windows.bat release
```
Criterio (work order): `unpaired_moved` bajo y estable, `gen` pequeño (cortes raros), `groups`≈nº de
objetos, sin parpadeos ni geometría incoherente. Los 2D de tipos 9/13 deben dejar de “estirarse”.
