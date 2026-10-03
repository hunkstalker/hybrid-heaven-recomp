# FPS/interpolación — identidad lógica + generación de cámara (2026-10-03)

> Rama `fps-interpolacion-tagging`. Rehace el tagging según el modelo de Pilotwings64Recomp
> (`notes/2026-10-03-fps-tagging-dobj-y-handoff.md` §3c/§3d). **Sin validar en gameplay** todavía
> (necesita run del mantenedor). Distinción medido / inferido explícita.

## Qué se cambió

- `src/hooks/model_tagging.cpp`: reescrito.
  - **Grupo por OBJETO**: se envuelve `func_800068C0_74C0(a1=root DOBJ)`, el traversal completo de un
    actor/objeto, no cada nodo (`func_800069A8`, que queda sin hook). Un `gEXMatrixGroupDecomposed`
    con `G_EX_PUSH`, `proj=0`, pos/rot/scale `INTERPOLATE`, skew/persp/vert/tile `SKIP`, `edit NONE`,
    tc `SKIP`, lookat `AUTO`.
  - **ID lógica** = FNV-1a(`kind=DOBJ`, `slot`, `modelId`, `lod=0`) mezclada con `sGeneration`.
    `slot` = índice del root en la lista global de objetos (cabecera `0x8008942C`, nodos enlazados por
    `+0x00`); `modelId` = `root->0x2C`. Nunca `G_EX_ID_IGNORE` ni `G_EX_ID_AUTO`.
  - **Orden**: `G_EX_ORDER_AUTO` para tipos de nodo raíz 1..4 (sprites/efectos, aparecen y
    desaparecen); `G_EX_ORDER_LINEAR` para el resto (mallas/huesos).
  - **Skip de spawn propio ELIMINADO** (RT64 ya no interpola un ID sin contraparte).
- `src/hooks/sections.cpp`: se registra `hh_object_draw_hook` en `0x800068C0` (antes `0x800069A8`).
- `src/platform/rt64_render_context.cpp`: la métrica `[hh-pair]` imprime `gen=` (cortes de cámara) y
  `groups=` (grupos taggeados) en vez de `skipped`.

## Generación de cámara (MEDIDO)

- La cámara del juego: `D_801BBBF0 + 0xE8` → puntero a entidad; `entidad + 0x2C` → puntero a su
  transform. Posición en `+0x30..+0x38`, objetivo en `+0x3C..+0x44`. Confirmado leyendo
  `func_8011A724_1012EF4` y `func_8011A7FC_1012FCC` (`build/recomp/asm/file_008.s`), que operan
  exactamente sobre esa cadena.
- Corte si `|pos - pos_prev| > 60u` o `dot(forward, forward_prev) < 0.75` (~41°), igual que PW64. La
  generación se evalúa **una vez por frame** (frontera `hh_dl_frame_count`), en el primer objeto, de
  modo que todos los grupos del frame comparten generación.
- **Evidencia headless** (Xvfb :99 + lavapipe, logos/menús): el hook se engancha, `slot=0`,
  `model=801BFCE8`, `id=3D741CFB`, y se midió un corte real de cámara
  `[hh-interp] corte de camara: gen=3 dist=53.0 dot=0.000` (giro de ~90° entre pantallas de menú).
  El arranque sigue limpio (`groups_seen` sube, sin crash).

## Actualización — identidad medida y solución por slots (2026-10-03)

- `[hh-ident]` (volcado de todos los campos del nodo cada ~10 s) **mide** que el nodo de render **no
  tiene ningún campo estable de instancia**: para el mismo modelo, todos los campos candidatos
  (`+0x00/+0x10/+0x14/+0x18/+0x34`) cambian entre frames; solo son constantes los compartidos
  (`+0x08/+0x0C=0`, `+0x20=0x100`, `+0x24=0xFFFFFFFE`, `+0x28`=bit de capa, `+0x2C`=modelo, `+0x30=0`).
- PERO 17 roots **se repiten** entre snapshots (los actores persistentes conservan el puntero ≥10 s),
  mientras una clase de objetos (efectos, p. ej. `model=8025A4E0`) reasigna root casi cada frame.
  O sea: la dirección sirve para los persistentes, pero se **recicla** para los efectos.
- Por eso índice de lista (se desplaza con el churn) y root (colisiona al reciclarse) fallan. **No hay
  handle de actor en el nodo**, así que la identidad se deriva del **comportamiento**, no de una
  dirección: **tabla de slots generacional** `map<root, {slot, model, last_frame}>`:
  root visto el frame anterior con el mismo modelo → mismo slot; root nuevo o reusado tras >2 frames
  → **slot nuevo monotónico** (nunca se reutiliza) → el reciclaje no hereda ids. Efectos = id nuevo
  (no se interpolan a través de un salto). Implementado en `stable_slot()`.

## Pendiente / no hecho

- `lod` va a 0: no se ha localizado un campo de LOD por objeto en HH (si un objeto cambia de LOD sin
  cambiar de modelo, la ID no cambiaría). Inferido que es poco frecuente; a confirmar con la métrica.
- **2D `G_EX_ID_IGNORE`** y **grupo de proyección de cámara aparte** (apartados de §3d) NO
  implementados: en HH la cámara va horneada en cada matriz (no hay transform de cámara separado que
  taggear) y la vía 2D/orto no se ha tocado para no arriesgar el widescreen recién estabilizado.
- Falta la run de gameplay del mantenedor para validar `unpaired_moved`/`unpaired` en #6/#8/#10/#12 y
  el parpadeo de cámara.

## Cómo validar (run del mantenedor)

`HH_MTXGROUP=1 HH_PAIRING=1 HH_MTXGROUP_LOG=1`. En `[hh-pair]`: `unpaired_moved` bajo, `unpaired`
bajo, `gen` pequeño (cortes raros), `groups` ≈ nº de objetos. Visual: sin parpadeo de cámara ni
artefactos de #6.

## Actualización 2 — validación en gameplay, per-nodo y pasada 2

- **Medido (capturas)**: con un grupo por OBJETO + `G_EX_ORDER_LINEAR`, el PJ salía **descuartizado**
  en frames con `unpaired=3` (p. ej. `paircap_008`/`021` de la run previa). No era "sin pareja" sino
  **mal emparejado** (RT64 casaba el hueso N con el N del frame anterior al cambiar orden/nº de
  transforms). La métrica `unpaired` es **ciega** a esto; solo lo cazaron las capturas automáticas.
- **Fix**: grupo por **NODO** (`func_800069A8`) con id=`FNV(slot_objeto, slot_nodo, gen)`. Validado en
  la run siguiente: el **mismo** `paircap_008` sale con el PJ entero. También #6 y #8 bien.
- **Histograma `[hh-types]`**: durante el gameplay lo dibujable en pass 1 es **tipo 8** (tipo 0 =
  contenedores no-op, descartados). Los tipos 1–4 casi no se usan (el 4 ocasional) → la rama
  `G_EX_ID_IGNORE` de 1–4 apenas aplica.
- **Pass 2 (efectos/2D ordenados)**: `func_80006AF0 → func_80006F8C` (colector de nodos **tipo 6**) →
  wrappers `func_80007328/736C/73AC` → draw `func_80007114`. **Sin taggear**; ahí viven los efectos 2D
  estirados. Hooks escritos y **gateados** por `HH_FX_PASS2` (off). Al activarlos, `groups_seen` caía a
  0 en headless, pero puede ser solo por el logo de menú (tipo 2 → `ID_IGNORE`), no por la DL; a
  depurar con run.
- **Cámara**: `HH_GENCAP` capturó los cortes; el mantenedor ve un **sesgado/posición rara** 2 veces
  (probable *shearing* de cámara horneada a 30 fps).
- Añadida **auto-captura por condición** (`HH_PAIRCAP`/`HH_GENCAP`) — imprescindible para artefactos
  de 1 frame que no se ven a ojo.

## Actualización 3 — pasada 2 (traza) y #6 (regresión) — VALIDADO

- **Pasada 2, diagnóstico `[hh-emit]`**: los wrappers `7328/736C/73AC` son **compute-only** (calculan
  la cinta vía `func_80007114`/`func_800075B4`; **no emiten gfx**). Sus `gEXMatrixGroup` quedan sin
  geometría entre push/pop → no materializan. El cursor es el global único `D_8008D5BC` (no es "otro
  cursor"); en menús `groups_seen=0` era el logo (tipo 2 → `ID_IGNORE`), falso positivo.
  Emisores que sí emiten (con `HH_FX_PASS2=1`): `7DE4/8754/8F30/A828/C768/11958/919C`; los 2D/texrect
  son **`919C` (tipo 9)** y **`11958` (tipo 13)**. Mapeo del jtbl: 8→`A828`, 9→`919C`, 13→`11958`.
- **#6 (regresión) = reset de ESCALA del efecto**, no la identidad: en A/B (sin gate) rebobinaba; con
  `HH_SCALE_GATE` no. **Fix**: gate ON por defecto (`HH_SCALE_GATE` def. 2.0; `=0` off) en
  `rt64_rigid_body.cpp` (`patches/rt64/hh-interpolation-tagging.patch`). Medido en `hh_scale.log`
  (`HH_SCALE_GATE_LOG=1`): el reset es **~100×** (`up/dn` alternando), sin falsos de ~2× de causa
  ajena; validado en dos runs (jefe, determinista).
- **Port**: `HOOK_OPCODE=E0 EXT_OPCODE=64 MAGIC=525464` → el GBI extendido se emite bien. El
  `explicit_ids=0` del contador RT64 es **instrumentación** (la interpolación no depende de él); a
  revisar aparte.
- Cambio especulativo `is_fx` tipos 9/13 **revertido**.

## Actualización 4 — pasada 2 cerrada (C768) + instrumentación (2026-10-03) — VALIDADO

**Clave medida**: la geometría de un emisor no está en su tramo lineal, sino en **sub-DLs que enlaza
con `G_DL` (opcode `0xDE`)**. Por eso hay que rodear **al emisor** con `gEXMatrixGroup` (el contexto
del grupo persiste en el sub-DL), no las funciones de cálculo.

- **`[hh-emit]` (histograma de opcodes)** descartó definitivamente `7328/736C/73AC` (compute-only) y
  sirvió para mapear el `jtbl` real de `func_800069A8`: `1→7DE4, 2→82C4, 3→8754, 4→8B9C, 5→8F30,
  6/12→C768, 7→D1CC, 8→A828, 9→919C, 10→A06C, 11→13828, 13→11958`. En `[hh-types]` dominaba el
  **8** (`A828`); los 2D/texrect son `919C` (9) y `11958` (13).
- **Experimento de tagging de emisores**: envolver **TODOS** los emisores **congelaba el render**
  (`[hh-pair] frames=0/s`, aunque `send_dl` seguía y `groups_seen` subía). Acotado a **solo `C768`**
  (draw de tipo 6, el de la cinta/efecto de pasada 2) → **estable** (`frames≈29.7/s`),
  `explicit_ids≈2300/s`, `groups_seen` sube; sin artefactos visibles.
- **Muerte de enemigos**: con `HH_PAIRING_DUMP=1` (vuelca a `hh_pairdump.log`) los 1446 no-emparejados
  -movidos salen **todos con id explícita** (taggeados); los saltos grandes son **spawns desde
  `(0,0,0)`** (snap, correcto), y para un mismo id en frames consecutivos el delta es ~2–27 u. El
  mantenedor **comparó la misma muerte en emulador** y coincide → **no hay fallo** de interpolación.
- **Las capturas automáticas NO son fallos**: se disparan con efectos que aparecen (minas/láseres/
  FIGHT) y son `unp3_tag2 moved=2` (transform nuevo sin pareja) o coinciden con `gencap` de corte de
  cámara. Recordatorio: `unpaired` **no** mide fallo visual.

### Inventario de instrumentación (todo apagado por defecto; se conserva a propósito)

Se deja en el árbol **por decisión del mantenedor**: sirve para diagnosticar futuros fallos de
interpolación y está documentado aquí. *Limpieza pendiente en el futuro cuando ya no haga falta*
(ver `TODO.md`). Los ficheros de salida viven en el cwd del exe (`build\windows\bin\Release`).

| Variable | Qué hace |
|---|---|
| `HH_MTXGROUP=1` | Activa el tagging (sin esto, hooks delegados). |
| `HH_MTXGROUP_LOG=1` | Diagnóstico: `[hh-types]` (histograma), `[hh-mtxgroup]`, `HOOK_OPCODE`. |
| `HH_FX_AUTO=1` | A/B: vuelve a interpolar los tipos 2D (1–4). |
| `HH_FX_PASS2=1` | Registra los hooks de **emisores** de pasada 2 (traza; + `C768` con `HH_FX_EMIT`). |
| `HH_FX_EMIT=1` | **Tagging de `C768`** (el fix de pasada 2, apagado por defecto). |
| `HH_PAIRING=1` | `[hh-pair]`: frames, transforms, `explicit_ids`, `groups_seen`, `fx`, `gen`, `unpaired*`. |
| `HH_PAIRING_DUMP=<n>` | Vuelca no-emparejados-movidos (`≥n`) a `hh_pairdump.log` (con `f=`). |
| `HH_PAIRCAP=<n>` / `HH_GENCAP=1` | Auto-captura BMP (no-emparejados movidos / cortes de cámara). |
| `HH_SCALE_GATE=<r>` | Gate de escala (#6): **def. ON 2.0**; `=0` off. |
| `HH_SCALE_GATE_LOG=1` | Vuelca el factor real a `hh_scale.log` (la GUI no captura stderr). |
| `HH_ROT_GATE=<deg>` / `_LOG` | Gate de rotación (sonda, off por defecto). |

Nota de vocabulario: "gateado" = el código está compilado pero **solo actúa si se define la
variable**; por defecto no cambia el comportamiento (doble clic = sin variables).
