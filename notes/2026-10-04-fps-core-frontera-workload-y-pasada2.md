# FPS/interpolación — frontera de workload del tagging, fix de cámara y estado de pasada 2 (2026-10-04, sesión 4)

> Rama `fps-interpolacion-tagging`. Sesión larga de diagnóstico + un **hito**: **el sesgado de cámara
> queda resuelto** (grupo de proyección con generación). Se exploró el **core** (materialización en
> `RSP::matrixId`, "grupo activo" cross-workload) y se **descartó**. Este documento conserva lo
> **medido/reutilizable** para no repetir el trabajo. Distinción medido/inferido explícita.

## 0. TL;DR

- **RESUELTO: sesgado de cámara** (shearing en los cortes, p. ej. FIGHT). Fix **port-only** en
  `src/hooks/model_tagging.cpp`: `emitter_wrap()` emite un **`gEXMatrixGroup` de PROYECCIÓN** (`proj=1`)
  con un **id de cámara ligado a la generación**. Commit `46b3f0d`. Validado con `gencap` de FIGHT
  (`unpaired=0`, encuadre coherente).
- **Descartado: la vía "core"** (materializar el grupo de pass 1 a través de la frontera de workload).
  Funciona a nivel de métrica (`explicit_ids` 0→~2700/s) pero asocia **por tiempo, no por nodo** →
  ensucia el HUD (el radial azul se movía) y no garantiza el `IGNORE` de los efectos. No se conserva.
- **Pendiente**: efectos/2D/partículas (minas, láser, impactos) y transiciones de puerta siguen
  disparando capturas. **La geometría la dibujan los emisores de pasada 2** (`7DE4/8F30/8754/…`), no el
  dispatch de pass 1 (`A828` solo pinta fillrects/estado). El tagging **por emisor** es la vía correcta;
  el fallo es de **identidad/granularidad**, no de frontera.

## 1. Fix de cámara (MEDIDO, VALIDADO) — `46b3f0d`

- La cámara de HH va horneada en la matriz de **vista/proyección** que los emisores cargan con `G_MTX`
  proyección (`0xDA38...`). RT64 empareja el viewProj por **igualdad de id**:
  `viewProjMap.mapped = (curProjGroup.matrixId == prevProjGroup.matrixId)` (`rt64_game_frame.cpp`).
- Fix: rodear cada **emisor de geometría 3D** con un `gEXMatrixGroupDecomposed(camId, PUSH, proj=1, …)`
  donde `camId = interp_id(KIND_CAM, …)` **incluye la generación**. En un corte el id cambia → RT64 no
  empareja el viewProj → **snap del encuadre**, sin tocar los modelview de objeto (huesos/2D intactos).
- Gate: `HH_EMIT_TAG=1` (alias `HH_FX_EMIT`). Solo emisores que dibujan; **los 2D de menú
  (`7750/78AC/79B0`) y `919C/11958` NO se envuelven** (envolverlos congela menú/LOAD DATA).
- Medición: `vpExp` (grupos de proyección con id explícito) sube; `gencap` de corte con `unpaired=0`.

## 2. La frontera de workload (MEDIDO) — por qué el tagging de pass 1 no llegaba

- El port llama `app->state->rsp->reset()` en **cada `send_dl`** (`rt64_render_context.cpp`), y RT64
  llama `State::clearExtended()` en `fullSync`/`advanceWorkload`. Ambos **borran el estado extendido**
  (stacks de matrix-id).
- Sonda (`diag[...]` en `[hh-pair]`): con el tagging de pass 1, `mid` (pushes de `gEXMatrixGroup`)
  sube pero **`vcFlag=0`** (`setVertexCommon` nunca ve el flag) y **`both=0`** (ningún workload tiene a
  la vez un push de grupo y un `setVertexCommon`). → grupos y geometría viven en **workloads/tareas
  distintas**; el grupo se pierde en la frontera. Es una versión más fuerte del "huérfano tras el pop".
- Conteo: `send_dl≈1/frame`, `clearExtended≈2/frame` (uno del `send_dl` + uno del `fullSync`).

## 3. La vía core explorada y por qué se descarta (MEDIDO)

- **Preservar el stack de matrix-id a través de `send_dl`** (resetearlo solo en el constructor) hace
  que el grupo **sí** llegue: `vcFlag>0`, `both>0`.
- Lo que llegaba era el grupo **base** (el push del nodo ya se había *pop*). Se probó recordar el
  **grupo activo por DATOS** (no por índice, que es por-workload) y materializarlo en el workload de la
  geometría: `pend>0`, `base=0`, **`wtExp = wtTot`** (100% tageado).
- **Por qué se descarta**: ese "grupo activo" asocia **por tiempo** (el último push antes de la
  geometría), no por nodo. Resultado **visible**: el **radial azul de salud del HUD se movía** (heredaba
  un grupo de modelo 3D) y aparecían parpadeos. La métrica **no lo caza** (no es "no-emparejado", es
  **mal emparejado**). Proteger el HUD en el push de proyección AUTO no bastó (la geometría del HUD no
  re-entra al bloque y usa el `cur` viejo).
- El mapa **dirección física de matriz → grupo** (validación) dio **`addrHit=0`**: las matrices de nodo
  no se cargan por `matrixCommon` (van por `FORCEMTX` + escritura directa), así que la clave por
  dirección **no aplica**.

## 4. Pasada 2 — quién dibuja qué (MEDIDO)

- `[hh-types]` en gameplay: **tipo 8 (`A828`) dominante**, y `A828` emite **solo estados + fillrects**
  (`D9 E2 E3 E7 FC`), **sin `G_VTX`**. O sea: el dispatch de pass 1 (`func_800069A8`) **no dibuja la
  geometría** de mallas/efectos.
- La geometría la dibujan los **emisores** (`7DE4/8F30/8754/C768/…`), que emiten `G_DL` a sub-DLs con
  el `G_VTX`/`G_TRI`. En la traza `[hh-emit]`, sus `a0` **varían mucho** entre llamadas (son nodos
  distintos) → el emisor es **por nodo**.
- `func_80007114` (el "draw" de pasada 2) es **compute-only** (no emite opcodes); los wrappers
  `7328/736C/73AC` también. El draw real es el emisor.

## 5. Estado de los no-emparejados restantes (MEDIDO)

- Con el tagging por emisor (Opción 2a, `wtExp=wtTot`) los no-emparejados ya no eran `AUTO`: pasaron a
  ser **con tag** (`tagN`), pero **muchos transforms comparten un único id** (un cúmulo de partículas
  entero con el mismo `id=…`, `grp=1`). Como el grupo es **por nodo** y el efecto tiene **N transforms**,
  RT64 empareja **por orden (`LINEAR`)** → al cambiar el nº/orden de piezas, se descuadran.
- Es el **mismo problema de granularidad** que los huesos (la nota del 2026-10-03 decía que "grupo por
  NODO + LINEAR" arreglaba huesos; en realidad aquel fix no materializaba, así que se validó con el
  *fallback* por similitud de matriz, no con LINEAR explícito).
- `ignored=0` al intentar marcar efectos como `IGNORE` desde el emisor: el `IGNORE` no llegaba (el
  grupo activo explícito ganaba) → los efectos seguían explícitos.

## 6. Siguiente vía (NO descartada) — tagging por emisor, granularidad correcta

1. **Mecanismo**: emitir el `gEXMatrixGroup` **en el emisor** (que conoce su nodo `ctx->r4`), en el
   **mismo workload que la geometría**. Esto ya se demostró (`wtExp=wtTot`); no necesita el core.
2. **Identidad**: id **por nodo** estable (`stable_slot(node, model)` + generación), **sin** `g_obj_slot`
   (que en pass 2 es obsoleto).
3. **Granularidad**: para nodos con **N transforms** (partículas/efectos) usar **`G_EX_ORDER_AUTO`** o
   **`G_EX_ID_IGNORE`** (no interpolar), nunca `LINEAR` (baraja). Para mallas de 1 transform, `LINEAR`.
4. **Clasificación**: identificar qué nodos/emisores son efecto vs malla. `A828` (tipo 8) es fillrect
   (2D); los efectos 3D van por los emisores. Marcar efectos → `IGNORE`.
5. **HUD**: no tocar (no lo dibujan los emisores); su proyección es AUTO.

## 7. Instrumentación usada (temporal; se retiró del árbol)

- Sonda `diag[...]` en `[hh-pair]`: `pend/base/wtExp/wtTot/mid/vcFlag/reset/both/vpExp` + `addrHit/
  addrMiss/addrEntries`. Se añadió al parche de RT64 para el diagnóstico y **no se conserva**.
- Se conserva la instrumentación ya existente (`HH_PAIRING`, `HH_PAIRING_DUMP`, `HH_PAIRCAP`,
  `HH_GENCAP`, `HH_FX_PASS2`, `HH_EMIT_TAG`).

## 8. Pitfalls (NO repetir)

- **No** taggear el modelview de objeto con `LINEAR` cuando el grupo puede tener N transforms
  (huesos/partículas): baraja.
- **No** intentar "recordar el grupo activo" a través de la frontera: asocia por tiempo → HUD roto.
- **No** envolver los emisores 2D de menú (`7750/78AC/79B0`, `919C/11958`, `A828`): **congela**.
- **No** confiar solo en `unpaired`/capturas para validar: el **mal-emparejamiento** (tagged) no se ve
  en la métrica. Validar visual (HUD, huesos) además.
- La cámara es **proyección**, no modelview (taggear modelview no arreglaba la cámara).
