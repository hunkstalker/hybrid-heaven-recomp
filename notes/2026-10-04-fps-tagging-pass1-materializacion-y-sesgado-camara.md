# FPS/interpolación — pass 1 no materializa y sesgado de cámara (2026-10-04)

> Rama `fps-interpolacion-tagging`. Sesión de **diagnóstico**: se atacó el **sesgado de cámara** y se
> encontró el **root-cause común** (el tagging de pass 1 no materializa). **Sin resolver** todavía.
> Distinción medido / inferido explícita. Reglas: `AGENTS.md`, `docs/documentation.md`.

## 1. Síntoma y causa raíz (MEDIDO)

- **Síntoma**: en un **corte de cámara** (p. ej. entrar en combate / FIGHT) la imagen sale
  **sesgada/esquilmada** (paredes y suelo caídos, verticales inclinadas) → *shearing*. Captura:
  `gencap_006_gen8.bmp` (`gen=8`, corte detectado `dist=156.5`).
- **Causa raíz**: en este estado el tagging de **pass 1 no materializa** en RT64 →
  `explicit_ids=0`, `groups_seen=0` en todo el gameplay. Sin ids RT64 no puede saltar la interpolación
  en el corte → interpola la cámara a media transición → shearing.
- **NO es la lógica de cámara**: la generación de cámara (corte por salto/giro) funciona; el problema
  es que los grupos no llegan a RT64. El mismo root-cause explicaba **(a)** la reaparición de **#6**
  (tapada con `HH_SCALE_GATE`) y **(b)** el estirado del esqueleto.

## 2. Sonda del GBI extendido (NUEVA) — dónde se pierde (MEDIDO)

Contadores en `lib/rt64/src/hle/rt64_game_frame.cpp` (`RT64_GetGbiProbeCounters`), instrumentados en
`rt64_gbi_extended.cpp` (`noOpHook`/`extendedOp`) y `rt64_rsp.cpp` (`setVertexCommon`); impresos en
`[hh-pair]` bajo `HH_PAIRING=1`:

| Contador | Qué mide |
|---|---|
| `gbi_enable` | `gEXEnable` (RT64_HOOK_OP_ENABLE) recibidos y aceptados |
| `extdisp` | entradas a `extendedOp` con el GBI extendido activo |
| `matrixid` | `gEXMatrixGroup` (push) despachados |
| `extop` | último opcode extendido visto (`0C`=MatrixGroup, `0D`=Pop) |
| `vcommon` | llamadas a `setVertexCommon` (primer `G_VTX`/`G_EX_VERTEX_V1`) |

Resultados:
- Logos/menús (`[hh-types]` tipo 2): `gbi_enable`/`extdisp`/`matrixid` suben, **`vcommon=0`**.
- Intro/3D (`HH_FORCE_INTRO=1`, tipo 8): `vcommon` sube (~17k) pero **no se solapa** con `matrixid`.
- Con `HH_FX_EMIT=1` (emisor `C768`): **sí** materializa (`explicit_ids≈2300/s`).
- **NO** hay bug de opcode/magic/cursor: el port emite bien (`HOOK_OPCODE=E0`, `EXT_OPCODE=64`,
  `MAGIC=525464`); los `gEXMatrixGroup` **se despachan**.

## 3. Mecanismo exacto (leído en el código de RT64)

Cadena de materialización en RT64:
1. `gEXMatrixGroup` → `RSP::matrixId(id, push, ...)`: empuja el id en `modelMatrixIdStack` y marca
   `modelMatrixIdStackChanged=true`. **No crea el `TransformGroup`.**
2. El `TransformGroup` se crea en el **siguiente `setVertexCommon`**: si `modelMatrixIdStackChanged`,
   hace `transformGroups.emplace_back(...)` y lo asocia.
3. `worldTransformGroups[i]` liga un transform con su `TransformGroup` **solo si**
   `modelViewProjChanged || modelViewProjInserted` en ese `setVertexCommon`.
4. El emparejamiento entre frames (`doTransformMatching`/`buildTransformIdMap`) exige
   `worldTransformGroups` con `matrixId` explícito.

**Por qué pass 1 falla**: la geometría de un nodo va en **sub-DLs (`G_DL`)** que se enlazan y procesan
**después del `pop` del grupo**; cuando llega el `G_VTX`, el stack ya volvió al grupo base → el grupo
del nodo **queda huérfano**. Por eso `matrixid` sube pero `groups_seen=0`.

Punto exacto: `RSP::matrixId` (push) y `RSP::setVertexCommon` en `lib/rt64/src/hle/rt64_rsp.cpp`;
`popMatrixId` vuelve a marcar `stackChanged=true` apuntando al grupo base.

## 4. Plan 1 (elegido) vs Opción 2 — análisis técnico

**Opción 1 (robusta, elegida)**: materializar el `TransformGroup` en el **propio `matrixId` (push)**,
creando el `worldTransform` con la matriz actual, y que `setVertexCommon` lo reutilice. Es el fix
correcto de RT64 (los sub-DL rompen el tagging; patrón común) y beneficia a cualquier port.

- **Intento A (revertido)**: `addWorldTransform` con `idGroupChanged` + creación del transform en el
  push. Headless: `groups_seen 0→4631`, sin crash. **En la run: rompió HUD/widescreen.**
  Motivo: crea un `worldTransform` extra por grupo y **desalinea `worldIndices` de TODO lo 2D/HUD**.
- **Conclusión**: la Opción 1 hay que **acotarla**, no aplicarla a ciegas. Candidatos a filtro:
  - solo `proj=0` (modelview) y **solo** si el grupo va seguido de un `G_MTX` real del modelo (no de
    estados 2D);
  - o detectar si el grupo acaba con vértices dentro de su scope (y solo entonces materializar en el
    push; si no, dejar el comportamiento actual).
- **Nota clave**: el tagging de pass 1 hoy **está inactivo de facto** (no materializa), así que es
  seguro experimentar con él, pero cualquier fix del core afecta a TODO el render (incluido 2D).

**Opción 2 (parcial, ya validada)**: tagging **por emisor** (como `C768`). Materializa solo donde el
emisor carga geometría propia; generalizarla **congeló** el render. **No** resuelve la cámara.

## 5. Incidente del HUD y lección de git (IMPORTANTE)

- Implementando el plan 1 se metió un **fix de longitud** de comandos extendidos en
  `processDisplayLists` (`dl += extLen` **además** del avance interno de los handlers → saltaba un
  comando de más → **desalineaba toda la DL**, HUD/widescreen incluidos). Estaba **sin commitear**.
- **Arreglo**: quitar ese cambio puntual. El avance debe quedar como estaba (los handlers ya avanzan
  `*dl`; el `dl++` del bucle cierra).
- **Error de método**: se hizo `git reset --hard` a un commit antiguo, arrastrando commits no
  relacionados. **No se perdió trabajo** (reflog + `git show <sha>` lo conservan; `aab0667` reincorporó
  sonda + `HH_CAPMAX`), pero fue innecesario.
- **REGLA**: causa puntual → revertir **ese cambio** (o `git revert` del commit), **nunca `reset
  --hard`**.

Commits resultantes de la rama (esta sesión): `aab0667` (sonda GBI + `HH_CAPMAX`, sin el fix de
longitud). Los experimentos fallidos (`8c97dc4`, `d973307`, `4600895`) quedan fuera de la rama pero
recuperables por reflog.

## 6. Instrumentación añadida (todo gateado)

- Sonda GBI en `[hh-pair]` (`gbi_enable`/`extdisp`/`matrixid`/`extop`/`vcommon`) — ver §2.
- `HH_CAPMAX=<n>`: tope de capturas auto (def. 80).
- `HH_PAIRING_DUMP=<n>` → `hh_pairdump.log` (ya existía, útil para identificar transforms).
- Inventario completo de variables: `RETOMAR.md` §Instrumentación.

## 7. Siguiente paso (sesión nueva)

Retomar la **Opción 1 acotada** (materializar el grupo en el push **solo** para el caso de modelo 3D,
sin tocar 2D/HUD). Validar por:
1. Headless con `HH_FORCE_INTRO=1`: `groups_seen>0` y **sin asserts**.
2. **Run del mantenedor**: (a) HUD/widescreen intactos (regresión del intento A), (b) PJ entero,
   (c) **sin sesgado de cámara**, (d) #6/#8.
Antes: commitear el estado actual (ver `RETOMAR.md` §Commit pendiente).
