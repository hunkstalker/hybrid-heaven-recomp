# RETOMAR — handoff RAMA `fps-interpolacion-tagging` (2026-10-04, sesión 3)

> **TAREA (rama): interpolación fiel / desbloquear FPS.** La sesión anterior cerró pasada 2 y #6;
> **esta sesión diagnosticó el SESGADO DE CÁMARA (no resuelto)** y descubrió la causa raíz común:
> el tagging de **pass 1 no materializa** en RT64. Detalle completo y evidencia:
> `notes/2026-10-04-fps-tagging-pass1-materializacion-y-sesgado-camara.md`.
> Reglas: `AGENTS.md` y `docs/documentation.md`. **La vista no valida 1 frame** → usar capturas.

## ⚠️ ESTADO DEL ÁRBOL (2026-10-04) — leer primero

- **`lib/rt64` sucio**: la instrumentación vive en `patches/rt64/hh-interpolation-tagging.patch`.
- **NO se ha commiteado el diagnóstico de esta sesión**: commit pendiente (ver abajo). El árbol de
  trabajo (submódulo + parche + `rt64_render_context.cpp`) **es el estado correcto y estable**;
  compila y el HUD funciona. Antes de seguir, **commitear** (propuesta en §"Commit pendiente").
- **Incidente del HUD (resuelto)**: romperlo y arreglarlo NO se perdió trabajo; ver §"Incidente HUD /
  lección de git".

## Estado — lo que funciona (MEDIDO, run del mantenedor)

- **Arreglados**: huesos del PJ dispersos, **#6** (textura del boss), **#8** (puerta), minas/láseres.
  El mantenedor no percibe fallos (salvo lo de abajo).
- **#6 (regresión) CERRADO con gate de escala**: el rebobinado del efecto es un **reset de escala
  ~100×**; `rt64_rigid_body.cpp` ahora hace `HH_SCALE_GATE` **ON por defecto (2.0)** (`=0` off), con
  log a `hh_scale.log`. Validado en dos runs del jefe (determinista). El cambio especulativo `is_fx`
  9/13 se **revirtió**.
- **Identidad estable**: `stable_slot()` generacional (map<root,{slot,model,last_frame}>, slot nuevo
  si se recicla) → un objeto persistente conserva id (verificado: `root=80252214` slot=31, id
  constante 30 s). Los roots reciclados/efectos reciben slot nuevo (no heredan ids de objetos muertos).
- **Grupos**: pass 1 (`func_800068C0` fija el slot de objeto; `func_800069A8` emite **un grupo por
  NODO**, id=`FNV(slot_objeto, slot_nodo, gen)`). Los tipos 1..4 (sprites/2D) van con `G_EX_ID_IGNORE`
  (no interpolar); el resto `G_EX_ORDER_LINEAR`. Esto arregló el esqueleto del PJ (el grupo por OBJETO
  con LINEAR lo barajaba al cambiar el orden/nº de transforms; la métrica NO lo veía).
- **Generación de cámara**: corte si salto >90u o giro >90° (`D_801BBBF0+0xE8 → +0x2C`, pos +0x30,
  objetivo +0x3C). Se evalúa 1×/frame. Evita el barrido en cortes.
- Sin `gEXSetRDRAMExtended` (rompe widescreen). Sin skip-spawn propio.
- Limpieza: no se emiten grupos para nodos tipo 0 (contenedores no-op).

## TAREA ABIERTA (lo que hay que resolver) — SESGADO DE CÁMARA

**Síntoma (captura real)**: en un **corte de cámara** (p. ej. al entrar en combate / FIGHT) la imagen
sale **sesgada/esquilmada** (paredes y suelo caídos, verticales inclinadas). Es *shearing* de cámara.

**Causa raíz (MEDIDA)**: en este estado el **tagging de pass 1 NO materializa** en RT64:
`explicit_ids=0`, `groups_seen=0` durante todo el gameplay. Sin ids, RT64 **interpola la cámara entre
frames** en el corte → shearing. O sea: **no es un fallo de la lógica de cámara** (esa está bien), es
que los grupos no llegan. El mismo root-cause explicó la reaparición de **#6** (tapado con el gate de
escala) y el estirado del PJ.

**Por qué pass 1 no materializa (MEDIDO con la sonda `[hh-pair]` gbi/matrixid/vcommon)**:
- La sonda en `lib/rt64` cuenta: `gbi_enable` (`gEXEnable` aceptados), `extdisp` (entradas a
  `extendedOp`), `matrixid` (`gEXMatrixGroup` despachados), `vcommon` (`setVertexCommon`).
- Resultado: `gbi_enable`/`extdisp`/`matrixid` suben (los grupos **se despachan**) pero en las
  escenas de menú **`vcommon=0`**; con geometría 3D real (intro, `HH_FORCE_INTRO=1`) `vcommon` sí
  sube, pero `matrixid` y `vcommon` **no se solapan**.
- **Mecanismo**: `matrixId` (push) solo marca `modelMatrixIdStackChanged`; el `TransformGroup` se crea
  en el **siguiente `setVertexCommon`** (primer `G_VTX`/`G_EX_VERTEX_V1`). Pero la geometría de un
  nodo de pass 1 va en **sub-DLs (`G_DL`)** que se enlazan y procesan **después del `pop` del grupo**
  → cuando llega el `G_VTX`, el stack de ids ya volvió al grupo base → el grupo del nodo **queda
  huérfano** → `groups_seen=0`.
- **Confirmación**: con `HH_FX_EMIT=1` (tagging del emisor `C768`, que carga su geometría en scope)
  RT64 **sí** materializa (`explicit_ids≈2300/s`). Prueba de que el problema es el **scope del grupo
  vs. el sub-DL**, no el GBI ni la identidad.

## Plan propuesto (Opción 1 vs Opción 2) — análisis ya hecho

- **Opción 1 (robusta, elegida como objetivo)**: materializar el `TransformGroup` en el **propio
  `RSP::matrixId`** (en el push), sin depender de un `G_VTX` posterior, y que `setVertexCommon` lo
  reutilice. Es el fix correcto de RT64 (patrón común que rompe el tagging con sub-DL) y beneficia a
  cualquier port.
  - **INTENTO (revertido, ver incidente)**: se implementó y headless dio `groups_seen 0→4631`, pero
    en la run **rompió el HUD/widescreen**.
  - **Motivo del fallo del intento**: fuerza un `worldTransform` extra por cada grupo y desalinea
    `worldIndices` de TODO lo 2D/HUD → hay que **acotarlo** (p. ej. solo `proj=0` **y** solo si el
    grupo va efectivamente seguido de un `G_MTX` real del modelo), no aplicarlo a ciegas.
- **Opción 2 (parcial, ya validada)**: tagging **por emisor** (como `C768`). Materializa pero solo
  cubre donde el emisor carga geometría; generalizarla **congeló** el render. No resuelve la cámara.

**Siguiente paso concreto de la sesión nueva**: retomar la Opción 1 **acotada**. Antes de tocar,
leer `notes/2026-10-04-...` §Plan y el `RSP::matrixId`/`setVertexCommon` actuales.

## Otros pendientes

3. **LOD** en el hash (id = slot, model, **lod**): no localizado el campo. Solo importa si un objeto
   cambia de malla por distancia; el slot generacional cubre parte. Medir si pasa (probablemente
   "no aplica": sin popping observado; decisión de cerrarlo como no-aplica).
4. **2D "de verdad"** (HUD/menús): `hud_rewrite` ya no interpola su proyección; confirmar que cubre
   todo (el combate 2D puede ir por la pasada 2).

## Instrumentación (reutilizable)

- `HH_MTXGROUP=1` tagging; `HH_MTXGROUP_LOG=1` → `[hh-types]` histograma de tipos de nodo (~2 s) y
  `[hh-interp]` cortes de cámara.
- `HH_PAIRING=1` → `[hh-pair]` (frames, transforms, explicit_ids, groups_seen, gen, groups,
  unpaired, unpaired_tagged, unpaired_moved). **OJO: `unpaired` no mide el fallo visual** (el fallo
  era *mal* emparejado, no "sin pareja").
- **Auto-captura** (clave para 1-frame): `HH_PAIRCAP=<min moved>` (frames con no-emparejados movidos)
  y `HH_GENCAP=1` (cortes de cámara) → `paircap_NNN_*.bmp` / `gencap_NNN_*.bmp` + `[hh-cap] auto` en
  `hh.log`. Tope 80 y 120 ms de separación. **El mantenedor no debe borrar los BMP hasta copiarlos.**
- `HH_FX_AUTO=1` → vuelve a interpolar tipos 1..4 (A/B).
- **Pasada 2**: `HH_FX_PASS2=1` (registra hooks de emisores/traza) + `HH_FX_EMIT=1` (**tagging de
  `C768`**; apagado por defecto).
- `HH_PAIRING_DUMP=<min moved>` → vuelca no-emparejados-movidos a **`hh_pairdump.log`** (la GUI no
  captura stderr).
- **#6**: `HH_SCALE_GATE=<ratio>` (**def. ON 2.0**; `=0` off) + `HH_SCALE_GATE_LOG=1` →
  **`hh_scale.log`** (factor `up/dn`). `HH_ROT_GATE=<deg>` (+`_LOG`) es sonda de rotación (off).
- **Sonda del GBI extendido (NUEVA, esta sesión)**: en `[hh-pair]` añade
  `gbi_enable=<gEXEnable> extdisp=<extendedOp> matrixid=<gEXMatrixGroup> extop=<ultimo opcode>
  vcommon=<setVertexCommon>`. Sirve para ver **dónde se pierde** el tagging (push vs materialización).
  Contadores en `rt64_game_frame.cpp` (`RT64_GetGbiProbeCounters`), instrumentados en
  `rt64_gbi_extended.cpp` y `rt64_rsp.cpp`. Gateada por `HH_PAIRING=1`.
- `HH_CAPMAX=<n>`: tope de capturas auto (def. 80); subirlo para muestrear más (p. ej. runs de LOD).
- **Se conserva a propósito** (decisión del mantenedor) para futuros fallos de interpolación; hay
  tarea de **limpieza futura** en `TODO.md`.

### Banco headless (logos/menús; NO llega a gameplay)
```
Xvfb :99 & ; DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy \
  VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_MTXGROUP=1 HH_MTXGROUP_LOG=1 \
  timeout 20 "./Hybrid Heaven Recomp"   # cwd build/linux
```
**En headless `[hh-pair]` sale 0** (no presenta frames); `groups_seen=0` en menús es normal (logo
tipo 2 → `ID_IGNORE`). Para gameplay: run del mantenedor.

## Run del mantenedor (validación)
```powershell
hybrid-heaven-recomp\build_windows.local.bat; $env:HH_MTXGROUP='1'; $env:HH_PAIRING='1'; $env:HH_MTXGROUP_LOG='1'; $env:HH_PAIRCAP='2'; $env:HH_GENCAP='1'; hybrid-heaven-recomp\run_windows.bat release
```
Log: `build\windows\bin\Release\hh.log`. Reproducir: combate con partículas 2D (los "churros"),
minas, y el punto donde fallaba el sesgado de cámara.

## Árbol
- `src/hooks/model_tagging.cpp` (tagging + instrumentación `[hh-emit]`), `sections.cpp` (hooks),
  `rt64_render_context.cpp` (auto-captura + log), `patches/rt64/hh-interpolation-tagging.patch`.
- `lib/rt64` SUCIO (fork): la instrumentación está en el patch; no commitear el submódulo.
- Nota detallada (incluye el **inventario de variables** y el mapeo jtbl):
  `notes/2026-10-03-fps-tagging-identidad-logica-y-generacion-camara.md`.

## Incidente HUD / lección de git (2026-10-04)

- Intentando el plan 1 se metió un **fix de longitud de comandos extendidos** en el intérprete LLE
  (`processDisplayLists` hacía `dl += extLen` **además** del avance interno de los handlers → saltaba
  un comando de más → **desalineaba TODA la DL**, incluido el **HUD/widescreen**). Sin commitear.
- **Arreglo**: quitar ese cambio puntual (el avance debe quedar como estaba; ver el comentario en
  `rt64_interpreter.cpp`).
- **Error de método**: para arreglarlo se hizo `reset --hard` a un commit antiguo, **arrastrando 2
  commits más que no eran la causa** (`d973307` plan1, `4600895` su revert, más `8c97dc4` con el fix
  de longitud + sonda + `HH_CAPMAX`). **No se perdió nada** (reflog y `git show <sha>` los conserva) y
  `aab0667` reincorporó lo bueno (sonda + `HH_CAPMAX`). Pero fue innecesario.
- **REGLA**: cuando la causa es **un cambio puntual**, revertir **ese cambio** (o `git revert` de ese
  commit), **NUNCA `git reset --hard`** que se lleva commits/cambios no relacionados.

## Commit pendiente (hacer al empezar la sesión nueva)

El árbol de trabajo es el estado bueno, pero **el diagnóstico de esta sesión no está commiteado**.
Antes de nada, commitear (un tema = un commit):
- `patches/rt64/hh-interpolation-tagging.patch` (sonda GBI + `HH_CAPMAX`, **sin** el fix de longitud).
- `src/platform/rt64_render_context.cpp` (`gbi_*`/`vcommon` en `[hh-pair]`, `HH_CAPMAX`).
- (Opcional, ya en el árbol) `notes/2026-10-04-...` y estos `RETOMAR.md`/`TODO.md`.
- **NO** commitear el submódulo `lib/rt64` (va en el patch). Mensaje sugerido:
  `diag(fps): sonda GBI extendido + HH_CAPMAX (sin tocar el avance de la DL)`.

## Pitfalls (NO repetir)
- **NO `git reset --hard` para un cambio puntual** (ver §Incidente HUD): revierte el cambio, no la rama.
- **NO añadir longitud al avance de comandos extendidos** en `processDisplayLists` (rompe el HUD).
- **NO materializar TransformGroups en el core sin acotar**: afecta a TODO (2D/HUD) y desalinea
  `worldIndices`. El plan 1 debe acotarse (solo `proj=0` + `G_MTX` real).
- La identidad por dirección (nodo/modelo/root/índice de lista) **falla** (se recicla/desplaza).
- El nodo de render no tiene campo estable de instancia; la identidad se deriva del **comportamiento**
  (slots generacionales), no de una dirección.
- Un grupo por OBJETO con LINEAR **baraja huesos**; hace falta grupo por NODO.
- Parchear la pasada 2 sin validar puede romper la DL (usa otra vía de gfx).
- No editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
