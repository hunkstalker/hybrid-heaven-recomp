# Work order — Desbloquear FPS: desacoplo lógica↔render e interpolación fiel

> Tarea importante abierta 2026-10-02. **Objetivo**: presentar al máximo del hardware (>200 Hz) **sin
> los artefactos de interpolación** (puerta que parpadea, jefe incoherente), de forma **incremental**.
> Este documento es el work-order autocontenido; el estado de tareas vive en `../TODO.md`.
> Distinción **medido** / **inferido** explícita.

## 0. TL;DR

- **La lógica de HH es 30 fps** `[MEDIDO]` (frame cada 2 VI; `notes/2026-09-17-fase0-referencia-cadencia-emulador.md`).
- El port **ya presenta** por encima de 30 (≈109 fps con RTSS) **interpolando con RT64**. Los
  artefactos **no** son "faltan fps": son **fallos de emparejamiento de RT64 entre frames** (con
  `RefreshRate=Original`, interpolación OFF, desaparecen: `notes/2026-09-22-fps-y-present-early.md` §Regresión).
- **Fase A** (recomendada): lógica a 30 Hz + present a refresco, arreglando el emparejamiento con
  **transform tagging** (lo que hace Zelda64Recomp; ver §3). → smooth hasta el refresco del monitor,
  sin artefactos.
- **Fase B** (spike time-boxed): simulación **60 Hz real** (subir el limitador + reescalar constantes
  por-frame). Límite ~60 fps reales; **no** es el camino a 240 (eso sería lógica a 240 = 8×, reescribir
  el juego).

## 1. Modelo de tasas de RT64 (medido en el código)

| Concepto | Valor / fuente |
|---|---|
| Ritmo de la lógica | `viOriginalRate` = 30 (del VI del juego) — `lib/rt64/src/hle/rt64_state.cpp:1616-1619` |
| Ritmo de presentación | `targetRate`; `Display` = `swapChainRate` (refresco del monitor), `Manual` se **recorta** al refresco — `rt64_workload_queue.cpp:216-234` |
| Interpolación | si `targetRate > viOriginalRate`, RT64 genera `displayFrames ≈ targetRate/30` frames por frame lógico — `:988-1005,1021-1085` |
| Coste | barato en CPU; el coste real es **re-renderizar** la escena N veces (`transform_processor.cpp`) |
| Reducción de frames | si el present queue se satura, RT64 reduce frames (`frameReduction`, `:1007,1096`) |

⇒ **La presentación no pasa del refresco del monitor.** A 30 lógicos y 240 Hz de pantalla, RT64
interpola 30→240. Para **240 fps reales** haría falta lógica a 240 (8×): no viable sin reescribir el update.

## 2. Estado y evidencia

- Cadencia lógica: 30 Hz (frame = 2 VI), con **slips a 3 VI** por stalls (hitch de puertas;
  `notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md`).
- Present alto + PresentEarly por defecto: `src/platform/rt64_render_context.cpp:341-382,494-503`;
  `README.md` §Alta tasa de refresco.
- El port **ya inyecta** hints `gEXMatrixGroup` en DL para el HUD (`src/hooks/hud_rewrite.cpp:326-331`):
  existe la infraestructura de reescritura de display lists.
- Audio atado al tick de 30 Hz (`TODO.md`, "Audio (futuro): desacoplar de los fps").

## 2b. Catálogo de fallos por interpolación (issues abiertos)

**Los 4 issues abiertos** están atribuidos a la interpolación de frames (confirmado por el mantenedor
en los comentarios; workaround común `HH_REFRESH_RATE=original` / F9):

| # | Título | Síntoma | Repro |
|---|---|---|---|
| [#6](https://github.com/hunkstalker/hybrid-heaven-recomp/issues/6) | **Primer Jefe (Procyon) / Frame Molesto** | flash/parpadeo de **1 frame** mientras está activa el **aura azul** del jefe (1-2) | **siempre** → **repro de A0** |
| [#8](https://github.com/hunkstalker/hybrid-heaven-recomp/issues/8) | Puertas que parpadean haciéndose invisibles | la puerta se vuelve invisible algunos frames | **no** siempre (según punto de vista) |
| [#10](https://github.com/hunkstalker/hybrid-heaven-recomp/issues/10) | Animaciones erráticas en enemigos | animaciones rotas al **restaurar vida** en mitad de combate | interpolación ON |
| [#12](https://github.com/hunkstalker/hybrid-heaven-recomp/issues/12) | Area 2-1 / Life Charger S | gráficos erróneos al usar el ítem | interpolación ON |

Patrón común: **cambios discontinuos de visibilidad/transform** (aura que aparece, puerta que
desaparece, enemigo que “salta” al curarse, efecto del ítem) → RT64 no puede interpolar bien el par de
frames. Es exactamente lo que el *transform tagging* de §3 resuelve con `skip` en discontinuidades y
**dibujando siempre** lo que si no hace pop-in.

## 2c. Hipótesis a verificar: el fallo depende de la **tasa** (targetRate)

`[INFERIDO del código]` El frame interpolado que se muestra (y su peso) depende de `targetRate`, así que
**el mismo desajuste de emparejamiento se ve distinto —o no se muestra— a otro refresco**:

- Nº de frames por frame lógico = `targetRate / viOriginalRate` (`rt64_workload_queue.cpp:1004`).
- Peso del frame interpolado = `(targetRate + displayTicks - logicalTicks) / targetRate` (`:1083-1085`).
- Presentación al ritmo objetivo: `Timer::preciseSleepUntil(presentTimestamp + 1e9/targetRate)`
  (`rt64_present_queue.cpp:395-397`).
- En tasas **múltiplo de 30** (30/60/120/240) los pesos son **estacionarios** → el "frame malo" cae
  siempre en una fase concreta (p. ej. w≈0.5). En tasas **no múltiplo** (144/165) la fase **deriva**
  cada frame → el frame malo se muestra de forma intermitente.
- Esto encaja con [#6](https://github.com/hunkstalker/hybrid-heaven-recomp/issues/6) "**siempre**"
  (flash del aura) vs [#8](https://github.com/hunkstalker/hybrid-heaven-recomp/issues/8) "**no**
  siempre" (puertas).

**Confounds a controlar** antes de atribuirlo a la tasa: **versión** (el reportero usó v0.4.1/v0.4.4;
`#12` lo dice explícitamente), GPU/API (D3D12 vs Vulkan), MSAA, aspecto, VSync y monitor. El A/B debe
hacerse **misma build v0.6.1 + mismo hardware**, variando **solo** la tasa.

**Experimento A0-tasa** (misma escena #6 Procyon con el aura):
1. Control sin interpolación: `HH_REFRESH_RATE=original` (o F9) → no debe fallar.
2. Barrer `FPS LIMIT` del menú GRÁFICOS (`NATIVE/30/40/60/75/90/120/144/165/240`; se **recorta** al
   refresco del monitor) o `HH_REFRESH_RATE=manual:<hz>`, con F7 en cada tasa.
3. Anotar en qué tasas aparece el flash de 1 frame; mirar `[hh-fps]` de `hh.log` (target/vi/swapChain).
4. Hipótesis a confirmar: falla en múltiplos de 30 y desaparece/es intermitente en 144/165.

## 2d. Animaciones erráticas (#10): mecanismo y arreglo candidato

`[MEDIDO en el código de RT64]`

- **Emparejamiento por ID**: RT64 casa transforms por ID (`buildTransformIdMap`), y si el juego no envía
  tags usa un **ID automático heurístico** (`GameFrame::match:299-316`). El par se acepta **aunque los
  transforms estén lejos**: `matchTransform` sólo ordena candidatos por diferencia, **sin umbral máximo**
  (`rt64_game_frame.cpp:577-607`). Un ID auto que cambie (p. ej. al aparecer un objeto/efecto) empareja
  transforms **no relacionados** → interpolación “loca”.
- **La rotación SIEMPRE se interpola**: `RigidBody::updateAngular` (`rt64_rigid_body.cpp:47-66`) tiene
  `// FIXME: Defaults to always interpolate.`; en cambio la traslación sí tiene *auto-gate* por
  velocidad (`updateLinear:19-34`). ⇒ un **cambio discontinuo de pose** (reinicio de animación al
  curarse, spawn de un hueso) se interpola entre las dos poses → miembro/articulación “vuelta loca”.
- Si la descomposición falla o está off → `lerpMatrixComponents` (interpolación **lineal de matriz**),
  que produce shear/skew.

**Hipótesis #10**: al restaurar vida, el enemigo cambia de estado/reinicia animación (o aparecen
huesos/efecto) → nuevos transforms/IDs → mal emparejamiento + rotación interpolada a lo bruto.

**Arreglos candidatos** (fork `rt64`, por orden de menor a mayor alcance):
1. **Gate de rotación** análogo al de traslación: si `Δangular` supera un umbral, **no interpolar** y
   usar la pose actual (*snap*). **IMPLEMENTADO (2026-10-02, flag)**: `HH_ROT_GATE=<deg>` (vacío/0 =
   **off**, comportamiento original; si se pasa sin número → 120°) y `HH_ROT_GATE_LOG=1` (traza de
   snaps, tope 50). En `lib/rt64/src/hle/rt64_rigid_body.cpp` (`updateAngular`); compila en Linux.
   **Pendiente: A/B en Windows (#10) con y sin el flag.**
2. **Umbral máximo en `matchTransform`**: si el mejor candidato está lejos, no emparejar (snap).
3. **Tags estables / `skip`** desde el port (transform tagging de §3), cuando se pueda identificar el objeto.

**Experimento**: A/B F9 en #10 (si desaparece → interpolación confirmada) e Inspector F1 para ver si los
draws del enemigo quedan `mapped` o no.

## 3. Qué hacen Zelda64Recomp / RT64 (modelo a seguir para Fase A)

Referencia: `Zelda64Recomp` (DeepWiki: *Transform Tagging and Interpolation*; `rt64_extended_gbi.h`).

- La lógica del juego **sigue a 20/30 fps**; RT64 genera frames intermedios.
- El juego **etiqueta cada transform** en el display list con un **ID estable** y un **modo**:
  - `gEXMatrixGroupDecomposedNormal` — objetos 3D (rotación por **quaternions**, escala descompuesta).
  - `gEXMatrixGroupDecomposedSkip` — movimiento discontinuo (teleports/spawns/warps): **no interpolar**.
  - `gEXMatrixGroupSimple` — control por componente (`G_EX_COMPONENT_INTERPOLATE`/`SKIP`).
  - `gEXMatrixGroupDecomposedVerts` — UI/pantalla (interpola vértices).
  - `gEXPopMatrixGroup` — cierra el scope (push/pop equilibrados).
- **Evitar el pop-in**: objetos que solo se dibujan al activarse (p. ej. páginas de menú) se **dibujan
  siempre** para que RT64 tenga estado previo.
- **Saltar interpolación en eventos** (warp/teleport) con flags por objeto.
- Framerate expuesto: Original / Display / **Manual (20–360)**; `Display`/`Manual` recortados al refresco.
- RT64 hace *draw call matching* automático (heurístico) **pero es experimental**; por eso el tagging explícito.
- Para HH **sin decompilación** el equivalente es **inyectar tags por reescritura de DL** (patrón
  `hud_rewrite`) donde podamos identificar el objeto, y/o **mejorar el matching en el fork `rt64`**.

## 4. Plan

### Fase A — Lógica 30 Hz + present a refresco, sin artefactos

**A0 — Repro determinista (prerequisito).**
- Escena reproducible principal: **#6 primer jefe (Procyon, 1-2)** con el aura azul (falla **siempre**);
  secundarias: **#8** puertas (intermitente), **#10** enemigos al curarse, **#12** Life Charger S.
- **OJO con F7**: `hh_cap` es para el **HUD/widescreen** (traza de identidades **2D** —texturas/DLs/
  rects— pareada con un screenshot). **No** sirve para un flash de **1 frame en 3D**: un still puntual
  casi nunca lo pilla y el `.log` solo tiene 2D. Para localizar el frame malo: **vídeo** a 60/120 fps
  mientras ocurre y extraer el frame con `ffmpeg`, o A/B visual.
- A/B de interpolación con **F9** (ON `Display` / OFF `Original`) **por observación**; el barrido de
  tasa (`FPS LIMIT`, §2c) también se observa (no necesita captura).
- **Inspector de RT64 (F1)** con `HH_DEVELOPER=1` / `[video] developer=si`: ver el *matching* real.
- Métricas: frame/VI, histograma de stalls (`hh_slow`), `viOriginalRate` vs `targetRate`, fps present
  (`HH_FPS=1`).

**A1 — Estabilizar el tick lógico (desacoplo del render).**
- Garantizar **2 VI/frame estables** (sin slips a 3 VI): `HH_DET_CLOCK` + compensación de stalls
  (precarga/caché de módulos `trans`, audio/DMA). Un tick irregular dispara los fallos de matching.
- Verificar que render/present **no** realimentan el tick.
- Criterio: cadencia estable ±0; desaparecen los artefactos dependientes de jitter.

**A2 — Fidelidad de emparejamiento (el núcleo).**
- Identificar los draws que fallan (Inspector RT64 / logs de matching).
- **Tagging de DL**: inyectar `gEXMatrixGroup` con **ID estable** (y modo `skip` en eventos
  discontinuos) vía reescritor de DL (patrón `hud_rewrite.cpp:326`).
- Si el matching automático no basta: **parche en el fork `rt64`** (emparejamiento de visibilidad/pop-in).
- Criterio: `RefreshRate=Display` a 120/240 Hz **sin** parpadeo ni geometría incoherente; A/B F9.

**A3 — Validación.**
- Windows (RTX 4080) a 120 y 240 Hz; Steam Deck. Regresión: menús, guardado, combate, cinemáticas.

### Fase B — Spike de viabilidad "60 Hz real" (time-boxed)

- Analizar `FUN_80001454` (limitador en `0x80001A60..0x80001B20`) y consumidores por-frame; medir qué
  rompe al subir el limitador a 1/60 (velocidad, animación).
- **Entregable: ADR** con decisión (viable / parcial / no viable) y estrategia. **No** persigue 240 reales.

### Fase C — Audio (paralelizable)

- Desacoplar la cadencia de audio del tick de 30 Hz (tareas AI/RSP por VI con buffering correcto).

## 5. Instrumentación existente (reusar)

| Qué | Knob / dónde |
|---|---|
| fps present + display lists | `HH_FPS=1` (`src/platform/rt64_render_context.cpp:657`) |
| Refresh rate forzado | `HH_REFRESH_RATE=original|display|manual:<hz>` |
| Interpolación ON/OFF en caliente | **F9** (`rt64_render_context.cpp:767`) |
| PresentEarly ON/OFF | **F8** / `HH_PRESENT_EARLY=0` |
| Reloj determinista | `HH_DET_CLOCK=1|quant`, `HH_DET_CLOCK_BIAS` (`timer.cpp:38-85`) |
| Cadencia/stalls | `HH_STATE_SECS`, `hh_slow.log`, `hh_sched.log` |
| Captura pareada | **F7** (`docs/workflows.md` §3) |

## 6. Riesgos / trampas

1. **Confundir metas**: >30 visual ya existe; 240 "real" ≠ 240 presentado.
2. **Reescribir DLs** puede romper microcódigo/estado → validar regresión completa.
3. **Fork `rt64`**: ya tocado, pero el matching es complejo; cambios con A/B y sin regresión.
4. **Fase A puede no cubrir todo** si hay draws sin información suficiente para taggear (sin fuente).
5. **Determinismo/saves** si se toca el reloj.

## 7. Referencias

- `notes/2026-09-17-fase0-referencia-cadencia-emulador.md` (HH = 30 fps).
- `notes/2026-09-22-fps-y-present-early.md` (PresentEarly + regresión de interpolación).
- `notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md` (slips a 3 VI).
- `docs/architecture.md` §5 (runtime) y §7 (texto/render).
- Zelda64Recomp — *Transform Tagging and Interpolation* (DeepWiki) y `lib/rt64/include/rt64_extended_gbi.h`.
- `src/hooks/hud_rewrite.cpp` (reescritura de DL), `lib/rt64/src/hle/rt64_workload_queue.cpp`,
  `lib/rt64/src/render/rt64_transform_processor.cpp`.
