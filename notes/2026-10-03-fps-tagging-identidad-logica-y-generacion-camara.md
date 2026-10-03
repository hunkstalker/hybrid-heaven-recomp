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
