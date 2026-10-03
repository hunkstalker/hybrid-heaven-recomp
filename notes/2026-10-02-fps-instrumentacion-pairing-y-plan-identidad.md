# FPS/interpolación — instrumentación de emparejamiento y plan de identidad (2026-10-02, noche)

> Sesión de continuación del work-order `2026-10-02-workorder-desbloquear-fps-interpolacion.md`.
> Aquí: **métrica objetiva** del fallo (sin depender de la vista), **qué mide**, y el **plan
> concreto** derivado. Distinción medido / inferido explícita. Nada validado en Windows todavía.

## 1. Contexto: por qué medir, no mirar

El mantenedor jugó una run con un `.exe` **viejo** (sin el cambio nuevo) y **le pareció ver
mejoras** → confirma que la observación visual no es un test fiable para fallos intermitentes.
También se descartó el "replay determinista": aun grabando input, la ejecución varía entre runs.
Conclusión de método: el defecto debe ser **trazable por código**, con una métrica en un log.

## 2. Instrumentación añadida (fase 1, compila en Linux; pendiente Windows)

En el fork `lib/rt64/src/hle/rt64_game_frame.cpp` (`GameFrame::match`, tras emparejar escenas) se
añadió un contador del emparejamiento de transforms, expuesto por `RT64_GetTransformPairing`
(`extern "C"`). En el port (`src/platform/rt64_render_context.cpp`) se imprime cada segundo a
`hh.log` bajo **`HH_PAIRING=1`**:

```
[hh-pair] frames=29.0/s transforms=1712.6/s ignored=0.0/s unpaired=29.0/s unpaired_moved=0.0/s
```

- `ignored`: transforms que el juego pidió no interpolar (`G_EX_ID_IGNORE`; 2D/efectos).
- `unpaired`: transforms sin pareja este frame (RT64 los dibuja "donde toca" y **dan el salto** a
  30 Hz en vez de interpolar).
- `unpaired_moved`: de los no emparejados, los que **además se movieron** (matriz ausente en el
  frame anterior) → los que pueden producir pop-in/parpadeo.

Extra (`HH_PAIRING_DUMP=<min>`, por defecto 20; `HH_PAIR_DUMP` a stderr): en picos vuelca la
identidad de cada no-emparejado-movido: `w`/`t` (workload/índice), `grp` (matrix-group),
`seg`/`phys` (dirección de la matriz de modelo), y `pos` (posición en mundo). Tope 2000 líneas.

## 3. Medido (logs en `tests/logs/`, gitignored)

`tests/logs/2026-10-02-pairing-8-puertas.log`, `...-6-procyon.log`, `...-procyon-2.log`,
`...-pairdump-procyon.log`. En Windows, `.exe` con el cambio (Release, `build_windows.local.bat`).

- `[MEDIDO]` **Menús/título**: `unpaired≈50/s`, `unpaired_moved=0` (todo empareja bien).
- `[MEDIDO]` **Gameplay**: `transforms≈1700–3300/s`; `unpaired≈29/s` de base (siempre ≈ el nº de
  frames: hay transforms que nunca casan) y **picos de `unpaired_moved`**.
- `[MEDIDO]` **#6 Procyon**: pico **`unpaired_moved=98.5/s`** (y 67.9, 44.5, 43.8, 39.4…). Firma
  fuerte del "aura que se expande y rebobina".
- `[MEDIDO]` **#8 puertas**: picos menores y dispersos (~30, 24, 12…). Mismo mecanismo, menos
  intenso.
- `[MEDIDO]` `ignored = 0` **siempre** → HH **no** emite ningún transform con id de ignorar: **no
  hay tagging**; RT64 empareja todo con la heurística.
- `[MEDIDO]` En el dump: `seg == phys` siempre (HH no segmenta), `grp=0` siempre, direcciones en una
  **arena compacta `0x00268988–0x00270198`**, **157 direcciones distintas**, **245 posiciones
  únicas** → muchos objetos/huesos distintos, no uno solo.

Lectura `[INFERIDO]`: RT64 identifica transforms por la **dirección** de la matriz; HH **recicla**
esas direcciones cada frame → empareja objetos/poses **no relacionados** → interpola a través de un
salto → parpadeo/replay. Esto explica el mecanismo de #6/#8/#10/#12 y las texturas que se escalan
mal. **No** está probado que explique el "flash a otra vista/primer plano" ni un "cuadro blanco":
podrían ser la **cámara/vista** mal emparejada (mismo mecanismo, `viewProjections`) o un efecto 2D;
queda por medir (contador equivalente para cámaras — solo como validación, no cambia el arreglo).

## 4. Hallazgo decisivo sobre el "transform tagging"

`[MEDIDO en el código de RT64]` El tagging de Zelda64Recomp **no se puede inyectar como comandos
sueltos**: las matrices se concatenan en pila (`G_MTX push/load`); el objeto se dibuja bajo la
matriz **resultante**. Además RT64 casa escenas por orden de dibujo de forma lineal
(`matchTransforms` por `multimap` de ids) **fusión** de workloads, y `buildTransformIdMap` sólo
incluye groups con `matrixId != G_EX_ID_AUTO` (si no hay tags, la rama lineal corre vacía y todo cae
en la heurística `matchScenes`→`computeTransformMatch`).

`[MEDIDO]` El port **ya reescribe DLs en submit** y tiene el punto exacto:
`hh::RT64Context::send_dl` (`src/platform/rt64_render_context.cpp:533`) llama a
`hh::hudrewrite::rewrite(rdram, data_ptr)` (`src/hooks/hud_rewrite.cpp:931`), que copia la lista a
un scratch (`Writer::copy_list`), conoce los opcodes `kMtx=0xDA`, `kMvViewport=0x08`,
`kMtxProjection=0x04` y el emisor de `hud_rewrite.cpp:328`.

## 5. Plan concreto (fase 2) — reescritura de DL en submit

El tagging por **dirección de `G_MTX`** es frágil (direcciones recicladas). La clave estable, a
nivel de lista, es el **orden de dibujo dentro del frame** (el juego dibuja los mismos objetos en el
mismo orden cada frame), más un `skip` en cambios de estado. Diseño propuesto (todo en la copia de
la DL, sin editar código generado):

1. **Deduplicar matrices (crucial):** HH emite muchos `G_MTX` de la **misma** dirección por frame
   (el dump dio 157 direcciones y ~2200 transforms por frame). Mapear cada dirección de matriz a un
   **slot de pila normalizado** (1:1) en la copia, para que el mismo objeto comparta matriz entre
   draws y `viewProjections` se empareje bien.
2. **Ordenar los `G_MTX` por dirección** (o no consumir slots por repetición) para que la pila de
   objetos se construya en un orden **consistente entre frames** → la rama lineal de RT64 empareja
   por orden estable.
3. **Inyectar `gEXMatrixGroup`** (`G_EX_ORDER_LINEAR`) con un id **estable por slot de orden** (no
   por dirección), y modo:
   - `G_EX_COMPONENT_INTERPOLATE` normal;
   - `G_EX_COMPONENT_SKIP` en discontinuidades (spawn/teleport/corte) detectables;
   - `G_EX_ID_IGNORE` para 2D/HUD/efectos (esto además sube `ignored>0` en `[hh-pair]`, señal de que
     el tagging entró).
4. **Validación por métrica:** `[hh-pair] unpaired_moved → ~0` en #6/#8 con el tagging; y el
   contador de cámara/vista (añadir) para el "flash".

Riesgo `[INFERIDO]`: el "lazy" de 30 fps exactos (Σ transformGroups = frames cuando todo casó)
sugiere que emparejar por **orden** es viable; la fase 2 lo confirma o lo refuta con el número.

## 6. Referencia externa consultada

`danielgomesvieira2000/hybrid-heaven-recomp` (port paralelo, Claude Code): su release 0.2.0 dice
**"No high frame rate yet"** y su fase 08 está **"next"** (sin hacer). Su enfoque coincide
(interpolación + matrix groups, *"never by changing game logic rate"*) y advierte de la misma
trampa ("las direcciones no son identidades" en el HUD). Trae un contador de pairing de Pilotwings
(`patch_rt64_pairing.py`) que inspiró el de §2. No aporta solución implementada.

## 6c. Vía DECIDIDA: parche de funciones del juego (patrón Goemon), no reescritura de DL

`[MEDIDO, 2026-10-03]` Se intentó la inyección por **reescritura de display list** (§6b) y **falló
dos veces** (grupos no materializados + geometría rota). Se buscó cómo lo hacen goemon
(`/app/goemon-sourcecode`, en la máquina) y Zelda/Wave Race/Pilotwings, y **la vía de Goemon es la
correcta**. Goemon **no** reescribe DLs: **parchea las funciones del juego** (`RECOMP_PATCH`, patrón
ADR 0002) y emite los `gEXMatrixGroup` desde el propio flujo del juego.

Receta medida en `/app/goemon-sourcecode/patches`:

- `gEXEnable` al arranque de lista (`main.c:18`) + `gEXSetRefreshRate`.
- En el dibujo de esqueleto (`anime.c:497-590`, `func_80018908/prof_80018CA0`): por cada hueso,
  `gEXMatrixGroupDecomposedNormal(..., G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW)` **antes** de
  dibujar y `gEXPopMatrixGroup(..., G_MTX_MODELVIEW)` **después** (pila equilibrada).
- **ID estable = puntero del objeto**, hasheado: `TAGGING_GENERATE_ID((u64)root_object << 32 |
  (u32)skeleton->display_list_vram_addr)` (`anime.c:508-512`, `macros.h:43`). El objeto vive en la
  misma dirección entre frames → la ID es constante.
- **`skip` desde la lógica del juego**: `TAGGING_OBJECT_SET_SKIP_INTERPOLATION(object)` cuando el
  objeto se resetea/recoloca (`tagging.c:104`, `func_08002414`); el flag se guarda en
  `object->overlay_info[5].unknown_2[1]` (`macros.h:16-23`). El grupo se omite si el flag está puesto.
- Modos: normal / skip-pos / skip-all / verts, según el caso (`macros.h:46-89`).

`[MEDIDO, 2026-10-03]` **HH usa el mismo motor Konami** (confirmado por cadenas de debug del ROM:
`DOBJ`, `SDOBJ`, `GMTX`, `MESH`, `Error d[%d]->gmtx is NULL!!`). La cadena de dibujo de modelos de
HH, localizada en el C recompilado (`build/recomp/RecompiledFuncs/funcs_77.c`):

```
func_80006790_7390 (lista global de modelos)              funcs_76.c:30910
 └ func_800068C0_74C0  TRAVERSAL del arbol DOBJ (pila expl.)  funcs_77.c:7573   ~ Goemon func_80018908
    └ func_800069A8_75A8  dispatch por tipo (node->0x2A)      funcs_77.c:7751
       └ func_8000C768_D368  draw de malla (seg + G_DL + mask 0x8FFFFFFF)   funcs_77.c:10058
          └ func_8000C4A8_D0A8  matriz de hueso + G_MTX       funcs_77.c:28319  ~ Goemon func_800192D0
```

Estructuras `[INFERIDO del código]`:
- Nodo **DOBJ**: `+0x00` sibling, `+0x08` child, `+0x1C` **gmtx** (re-asignado cada frame), `+0x22`
  visibilidad, `+0x28` máscara de pase, `+0x2A` tipo, `+0x2C` struct de modelo/transform.
- **Transform**: `+0x04/+0x08/+0x0C` traslación (f32), `+0x10/+0x12/+0x14` rotación (Vec3s),
  `+0x18/+0x1C/+0x20` escala (f32), `+0x24` modo, `+0x28`/`+0x34` display lists, `+0x30` segmento.
- **No hay recursión** (pila explícita en `func_800068C0`), mejor para parchear que Goemon.

**Sitio elegido para el tagging**: envolver `func_8000C4A8_D0A8` (emisión de `G_MTX` por hueso) o el
draw del nodo en `func_800069A8`, con ID = **puntero del nodo DOBJ o de `node->0x2C`** (estable entre
frames), **no** el `gmtx` (`node->0x1C`, reciclado cada frame). `skip` en reset/recolocación (#6/#10).

`[MEDIDO, 2026-10-03]` **El encaje ya existe en el port; no hay que montar un `patches.elf`**.
`recomp::overlays::add_loaded_function(vram, hook)` sustituye una función del juego por una del port
en runtime (el `RECOMP_PATCH` de Goemon). El port **ya usa ~20** de estos (`hh_box_draw_hook`,
`hh_pak_detect_hook`…, `src/hooks/sections.cpp:645-699`). Patrón:
- El hook tiene firma `void hook(uint8_t* rdram, recomp_context* ctx)` y **llama al original** por su
  nombre (`func_8000C4A8_D0A8(rdram, ctx)`), envolviéndolo.
- Se registra con `add_loaded_function(0x8000C4A8, hh_bone_draw_hook)` y **se re-registra tras cada
  carga de módulo** (el loader reescribe `func_map`; ver `register_title_menu_hook`).

Regla de oro (ADR 0009/AGENTS): **no se edita el C generado**; el hook va en `src/hooks/` (como los
demás), se compila con el port y no requiere tocar el pipeline de recompilación.

## 6b. (DESCARTADO) Implementación por reescritura de DL, `HH_MTXGROUP`

`[MEDIDO en el código]` Mecánica de RT64 confirmada: al procesar `gEXMatrixGroup` se fija
`extended.modelMatrixIdStack[...]`; el **primer `G_VTX`** tras él materializa un `TransformGroup` con
esa ID (`rt64_rsp.cpp:509-514`). Un `G_MTX` de modelo provoca un `G_VTX` implícito
(`setVertexCommon`), así que **emite el group**. El contador de transforms lazy (= nº de frames cuando
todo casa) sugiere que el **primer** materializado por frame es el objeto "de abajo" y los siguientes
son huesos que van encima.

Implementado en `src/hooks/hud_rewrite.cpp` (gated por **`HH_MTXGROUP=1`**, off por defecto), en la
copia de la lista, solo `depth==0` (las sublistas se copian inline → una sola pila por frame):
1. Primera matriz de modelo: se emite tal cual y **después** `gEXMatrixGroup(id=1)` (priming; es la
   del orden más bajo). Antes del priming **no** se taggea.
2. Matrices de modelo siguientes: `gEXMatrixGroup(id=base+slot)` (2,3,4…) cada una.
3. Todas con `G_EX_ORDER_LINEAR`, `G_EX_NOPUSH` sobre el stack-1 y componentes `AUTO`, para que las
   IDs hijas caigan en el mismo nivel y el priming no cambie de nivel. Las matrices de **proyección**
   no se taggean. El `G_MTX` real se conserva (aspecto/widescreen intactos).

`[MEDIDO en Windows, 2026-10-03]` **DESCARTADO tras fallar dos veces.** Síntomas: `ignored=0`
(grupos no llegan a RT64) y geometría rota (objetos desplazados/agigantados, huesos deformados).
Causas identificadas:

1. La pila de IDs de RT64 es **push/pop real**; con `G_EX_NOPUSH` y sin `gEXPopMatrixGroup`, las IDs
   se pisan y no casan entre frames.
2. **Desde la DL no hay identidad de objeto**: sólo un orden frágil. Goemon obtiene la ID del
   **puntero del objeto**, que la DL no expone.
3. `gEXMatrixGroup` es de 2 palabras y debe **reservarse** espacio (nunca desplazar/sobrescribir);
   meterlo "antes de cada `G_MTX`" es proclive a romper la lista.

Conclusión: **la reescritura de DL no es la vía para HH**. Se revirtió (`git checkout --
src/hooks/hud_rewrite.cpp`). La vía es §6c.

## 6b. (DESCARTADO) Implementación por reescritura de DL, `HH_MTXGROUP` (histórico)

## 7. Estado del árbol (sin commitear)

- `lib/rt64` (sucio): gates `HH_ROT_GATE`/`HH_SCALE_GATE` (sesión anterior, off por defecto) **+
  contadores de pairing y dump** de esta sesión. **Esto SÍ merece conservarse** (la métrica).
- Port: `src/subsystems/input.cpp` (F9) y `src/platform/rt64_render_context.cpp` (`HH_PAIRING`).
  El tagging por DL (`hud_rewrite.cpp`) fue **revertido**.
- Docs: esta nota + work-order; `RETOMAR.md`/`TODO.md` actualizados. Logs en `tests/logs/`
  (gitignored). `main` en `bebd76e` (`v0.6.1`). **No** pushear/commitear sin pedirlo.

## 8. Siguiente paso (vía Goemon, §6c)

1. **[HECHO] Localizar las funciones de dibujo de HH** (ver §6c): `func_8000C4A8_D0A8` (G_MTX de
   hueso) dentro de `func_800069A8_75A8`/`func_800068C0_74C0`; nodo DOBJ con `+0x1C` gmtx, `+0x2C`
   modelo; transform en `+0x04`(t)/`+0x10`(r)/`+0x18`(s).
2. **Hook del port** (NO `patches.elf`; el encaje ya existe, ver §6c): en `src/hooks/` (p. ej.
   `src/hooks/model_tagging.cpp`) definir `hh_bone_draw_hook(rdram, ctx)` que emita
   `gEXMatrixGroupDecomposedNormal(id, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW)` antes de
   `func_8000C4A8_D0A8(rdram, ctx)` y `gEXPopMatrixGroup` después, con ID = puntero del nodo DOBJ
   (o `node->0x2C`); `gEXEnable` al arranque de lista. Registrar con
   `add_loaded_function(0x8000C4A8, hh_bone_draw_hook)` y re-registrar tras cada carga de módulo.
3. **`skip` desde la lógica**: marcar reset/recolocación (aura #6, curar #10) como hace Goemon.
4. **Validar** con `HH_PAIRING` (una run): `unpaired_moved` de #6/#8 a ~0, sin romper la imagen.

Mientras se implementa, el árbol queda sin el tagging por DL (ya revertido) y solo con la
instrumentación `HH_PAIRING`.
