# FPS/interpolación — tagging DOBJ, resultados y handoff (2026-10-03)

> Sesión larga. Estado real, sin inflar. Dos ramas de trabajo: **(1)** el tagging de interpolación
> (rama `fps-interpolacion-tagging`, sin mergear, **sin validar en gameplay** todavía) y **(2)** un
> hallazgo de **release rota en GitHub** que `main` (despejada) debe abordar. Distinción medido /
> inferido explícita.

## 0. TL;DR

- **El tagging de transforms llega a RT64** y reduce mucho los picos (`unpaired_moved` de 60–98/s a
  media ~3.4/s; 77% frames limpios). **Pero no está cerrado**: quedan #6 (rebobinado de la textura al
  crecer), parpadeos de cámara y ~27% frames sucios. **Causa de fondo identificada**: nuestra ID no es
  la correcta (ver §3c, el modelo de Pilotwings).
- **Causa raíz** de por qué antes no llegaba: faltaba `#define F3DEX_GBI_2` (opcode del hook). Punto
  de enganche: **dispatch DOBJ `func_800069A8`**. **Widescreen y recuadro negro: resueltos** (ver §3/§3a).
- **#8 puertas**: estable. **#6**: pendiente (necesita el modelo de §3c).
- **Release GitHub rota** (v0.6.2): **resuelta y validada** por la otra sesión en `main` (`8a7e076`,
  `f3de254`); pendiente solo el tag. Nota: `notes/2026-10-03-release-v0.6.2-empaquetado-y-secrets.md`.

## 1. Cómo se construye el tagging (medido)

Cadena de dibujo de modelos de HH (localizada en `build/recomp/RecompiledFuncs/funcs_77.c`):

```
func_80006790_7390 (lista global de modelos)
 └ func_800068C0_74C0   traversal del arbol DOBJ (pila explicita)   [~ Goemon func_80018908]
    └ func_800069A8_75A8  DISPATCH por tipo de nodo (node->0x2A)     <-- HOOK ACTUAL
       ├ func_8000C768  malla (matriz + G_MTX + G_DL)
       ├ func_80007DE4 / 800082C4 / 80008754 / 80008B9C ...  otros tipos (sprites/efectos), TAMBIEN G_MTX
       └ func_8000C4A8  matriz de hueso + G_MTX  [~ Goemon func_800192D0] (solo lo llama C768)
```

- Nodo **DOBJ**: `+0x00` sibling, `+0x08` child, `+0x1C` gmtx (reciclado cada frame), `+0x2A` tipo de
  draw, `+0x2C` modelo. `[MEDIDO]` **NINGUNA dirección es identidad estable** (nodo y modelo se
  reciclan: el mismo id salía con posiciones distintas). Ver §3b.
- El hook (`src/hooks/model_tagging.cpp`, `hh_bone_draw_hook`) envuelve `func_800069A8(a0=node)`:
  emite `gEXEnable` + `gEXMatrixGroupDecomposed(id, G_EX_PUSH, modelview)` antes del draw, y
  `gEXPopMatrixGroup` después. **NO** se emite `gEXSetRDRAMExtended` (ver §3).
- **Estado actual de la ID (provisional, incorrecto)**: `hash(node->0x2C)` (modelo). Probado también
  `hash(nodo)` y `hash(root+orden de recorrido)`: los tres fallan (§3b). El modelo correcto está en §3c.

### Errores corregidos (medidos, no supuestos)

1. **`#define F3DEX_GBI_2`** antes de `rt64_extended_gbi.h`. Sin él, `RT64_HOOK_OPCODE` valía `0x00`
   en vez de `0xE0` → `gEXEnable` no habilitaba el GBI extendido → RT64 **descartaba** los grupos
   (`ignored=0` en todas las runs previas). **Esta era la causa raíz.** Lo tiene `hud_rewrite.cpp`
   desde siempre; `model_tagging.cpp` no lo tenía.
2. **Punto de enganche**: envolver `func_8000C4A8` (solo la matriz) cerraba el grupo **antes** de que
   el `G_DL`/`G_VTX` lo materializara. Se movió primero a `func_8000C768` (malla, funciona) y luego a
   `func_800069A8` (dispatch) porque **otros tipos de nodo** no pasan por la malla.

## 2. Resultados medidos (run del mantenedor, Windows, gameplay de 0 a #6)

Log: `tests/logs/2026-10-03-mtxgroup-run4-ok.log` (gitignored).

| métrica | antes (sin tagging) | run con tagging en `func_8000C768` |
|---|---|---|
| `[hh-pair] unpaired_moved` picos | 60–98/s | hasta 70/s, **media 3.4/s** |
| frames limpios (`unpaired_moved=0`) | ~0% | **77%** |
| `explicit_ids` | 0 | ~2300/s (≈ todos los transforms) |
| `ignored` | 0 | 0 (no uso `G_EX_ID_IGNORE`; el tagging es `explicit_ids`) |

- `[MEDIDO]` **`target=swapChain=120, vsync=1`**: el techo del mantenedor son **120 fps** (monitor
  120 Hz + Vsync). Sus 70–110 son caídas bajo el techo, **no falta de GPU** (RTX 4080 / i7-14700K).
- `[MEDIDO]` **`unpaired_tagged=0`** en la run: lo que quedaba sin emparejar **no tenía tag** →
  **~1 transform/frame** de un tipo de nodo que **no pasa por `func_8000C768`** (los otros tipos del
  dispatch). Por eso el hook se movió a `func_800069A8` (cubre **todos** los tipos). **Pendiente de
  validar** en gameplay.
- `[MEDIDO, síntoma del mantenedor]` Con el skip-spawn (ver §3) aparecieron **microdesfases del
  jugador** al correr/subir en elevador. **Ya revertido.**
- `[MEDIDO, síntoma]` #6 pasó de "rebobinado del escalado" a "**brillo de 1 frame mientras crece la
  textura**". El rebobinado ya no está (el tagging empareja bien); el brillo es un cambio de
  **visibilidad/alfa** en una discontinuidad → necesita `skip` bien hecho, no un umbral global.

## 3. Lo que se intentó y se descartó

- **`gEXSetRDRAMExtended(cmd, 1)` en el hook** (copiado de Zelda): **ROMPÍA EL WIDESCREEN**. HH NO usa
  direcciones extendidas: sus direcciones son KSEG0 (bit 31 puesto = `ExtendedMask`), y con
  `extendRDRAM=1` RT64 cambia `fromSegmented`/`maskPhysicalAddress` (`rt64_rsp.cpp:104/114`,
  `rt64_rdp.cpp:242`) → reinterpreta TODAS las direcciones → la escena deja de expandirse. El HUD
  seguía anclado porque se ancla por reescritura de DL. **Quitado** (la vía del port no lo necesita;
  Goemon lo tiene comentado; solo lo usa Zelda). Medido: tagging intacto tras quitarlo
  (`groups_seen` sigue subiendo).

- **Reescritura de display list en submit** (`hud_rewrite.cpp`, flag `HH_MTXGROUP` en esa vía):
  **falló 2 veces** (grupos no materializados + geometría rota). Descartada. La vía correcta es el
  **hook del port** (patrón Goemon/Zelda), que es lo implementado.
- **skip en spawn/reaparición** (`g_seen_prev`/`g_seen_cur` con `hh_get_vi_count`): causó
  microdesfases (el VI avanza a mitad de frame → nodos presentes caían como "reaparición" → snap).
  **Revertido.** Si se reintenta, necesita un **frame boundary fiable**, no el VI.
- **Gates globales** `HH_ROT_GATE`/`HH_SCALE_GATE` (en `lib/rt64`, sesión anterior): sonda, no
  arreglo; off por defecto. Siguen en el fork.

## 3b. #6 (el "brillo de 1 frame"): causa medida y fix en curso (2026-10-03)

- `[MEDIDO]` El skip de spawn (por ID, frontera `hh_dl_frame_count`/`send_dl`) **dispara** en #6
  (`skipped` sube justo ahí) pero **el flash persiste** → no era "reaparición interpolada".
- `[MEDIDO, dump de #6]` **El puntero del nodo DOBJ NO es identidad estable**: el mismo `id` (=hash del
  nodo) aparecía con **posiciones totalmente distintas** (`dump6.log`); HH **recicla** los nodos de
  dibujo entre frames. Misma lección que el HUD ("las direcciones no son identidades").
- **Fix en curso** (`8b25b52`): la ID pasa a ser **hash de `node->0x2C`** (puntero del **modelo**), que
  persiste más allá del reciclaje del nodo; fallback al nodo si `0x2C` es 0. `HH_MTXGROUP_LOG` traza
  `node/model/id`. **Pendiente de validar** en #6 (¿baja `unpaired_tagged`/`unpaired_moved`?).

## 3c. CÓMO LO HACEN LOS PORTS QUE FUNCIONAN (fuente: Pilotwings64Recomp)

`[MEDIDO, doc externa]` `danielgomesvieira2000/pilotwings-64-recomp` → `docs/PORTING.md` §Frame
interpolation y `patches/interpolation.c`. Es el modelo correcto y **explica nuestros fallos**:

1. **La ID es LÓGICA, no una dirección**: `interpId(kind, a, b, c)` con `mix()` (FNV). Para objetos,
   `dobjId(obj, lod) = interpId(DOBJ, (obj - D_80263780), obj->modelId, lod)` → **índice de slot en
   un array + modelId + LOD**. NUNCA direcciones (nodos/modelos reciclados: nuestro error).
2. **Todo ID se hashea con la "generación de cámara"** (`sGeneration`), que **avanza en cortes** de
   cámara (salto >60u o giro >~40° en un frame). La cámara va **bakeada** en cada matriz, así que un
   corte mueve todos los transforms: si el ID no cambiara, RT64 "barre" toda la imagen del view viejo
   al nuevo → **ESTE es el parpadeo de cámara que reapareció**.
3. **Un grupo por OBJETO** (no por hueso): `interpModelBegin(dobjId(...)); draw_objeto(); interpModelEnd();`
   con `G_EX_ORDER_LINEAR` (RT64 empareja por orden dentro del id). Un `gEXMatrixGroupDecomposed` con
   `push=G_EX_PUSH, proj=0, pos/rot/scale INTERPOLATE, vert/tc/skew SKIP, order LINEAR, edit NONE`.
4. **La cámara es un grupo de PROYECCIÓN aparte** (`interpCameraBegin`: `G_EXMatrixGroupSimple` con
   `G_MTX_PROJECTION` y el id de cámara).
5. **Efectos → `G_EX_ORDER_AUTO`** (sus piezas aparecen/desaparecen); **2D → `G_EX_ID_IGNORE`**.
6. Un ID sin contraparte en el frame anterior **no se interpola** (corte/spawn/LOD) — el skip es
   automático, sin lógica de "spawn" nuestra.

**Lo que hicimos mal (y por qué):** (a) ID por dirección (nodo/modelo) → reciclada → picos; (b) ID por
root+orden de recorrido → el orden no es estable → picos peores; (c) **sin generación de cámara** →
parpadeo de cámara; (d) grupo por nodo/hueso en vez de por objeto; (e) sin grupo de cámara.

## 3d. Plan de implementación correcto (sesión nueva)

Rehacer el tagging de HH siguiendo el modelo de §3c. **Trabajo de código, sin runs hasta tener algo
coherente.** Piezas:

1. **Identidad lógica de objeto** (no dirección). HH recorre una lista de modelos/actores y luego un
   árbol DOBJ por actor. Necesitamos un **"slot" estable**:
   - Buscar en el código de HH el **índice de objeto/actor** en su lista (análogo a `(obj - D_80263780)`
     de PW64). Candidatos: el recorrido global de modelos (`func_80006790_7390`) itera una lista con
     puntero + índice; el slot en esa lista es la identidad. Confirmar con el dump.
   - ID = `mix(kind, slot, modelId, lod)` + **generación de cámara**.
2. **Generación de cámara** (clave para el parpadeo de cámara): detectar **cortes** (salto grande de la
   matriz de cámara o giro de más de ~40° entre frames) y **avanzar un contador** que entra en TODO id.
   La cámara de HH se hornea en las matrices de objeto (igual que PW64/Goemon). Localizar dónde HH
   calcula/guarda la cámara (matriz de vista/proyección) y engancharlo.
3. **Un grupo por objeto** (no por nodo): envolver el **draw del objeto completo** (el traversal de un
   actor/DOBJ raíz), no cada nodo. `gEXMatrixGroupDecomposed(id, G_EX_PUSH, modelview, pos/rot/scale
   INTERPOLATE, vert/tc/skew SKIP, G_EX_ORDER_LINEAR, G_EX_EDIT_NONE)`. Efectos/partes que aparecen y
   desaparecen → `G_EX_ORDER_AUTO`.
4. **Grupo de cámara aparte** (`G_EXMatrixGroupSimple` en `G_MTX_PROJECTION` con su id).
5. **2D → `G_EX_ID_IGNORE`** (probablemente en la proyección orto/HUD; HH ya tiene `hud_rewrite`).
6. **Quitar** el skip-spawn propio (el skip de spawns/LOD lo hace RT64 solo cuando un id no tiene
   contraparte).

Dónde mirar en HH (medido): traversal `func_800068C0` (root del actor), dispatch `func_800069A8`,
`func_8000C768` (malla), `func_8000C4A8` (G_MTX de hueso). La cámara: buscar la matriz de vista/proj
(el port ya parchea `snap_overscan`/`hud_rewrite`; ver `docs/architecture.md` §5/§7).

## 4. Instrumentación (reutilizable)

En `lib/rt64` (fork) + port:
- `RT64_GetTransformPairing` (contadores por frame) y `[hh-pair]` en `hh.log` con
  `HH_PAIRING=1`: `frames`, `transforms`, `explicit_ids`, `groups_seen`, `ignored`, `unpaired`,
  `unpaired_tagged`, `unpaired_moved`, y `target/vi/swapChain/refresh/vsync`.
- `HH_MTXGROUP=1`: activa el tagging. `HH_MTXGROUP_LOG=1`: traza nodos/ID y estado del hook.
- `HH_PAIRING_DUMP=<n>`: volcado de identidad de transforms no emparejados (a stderr).
- **Banco headless propio**: `Xvfb :99` + `VK_ICD_FILENAMES=.../lvp_icd.x86_64.json` (lavapipe).
  Arranca y renderiza (logos/menús) → sirve para iterar sin el mantenedor. **NO llega a gameplay 3D**
  (se queda en la intro; `HH_REPLAY` no basta). Para gameplay, run del mantenedor.

## 5. Estado del árbol / ramas

- **`main`**: v0.6.1 + v0.6.2 pusheada y validada (queda el tag). Nota
  `notes/2026-10-03-release-v0.6.2-empaquetado-y-secrets.md`. `main` **no** tiene el tagging.
- **Rama `fps-interpolacion-tagging`** (mergeada con main; commits `wip`, **sin mergear a main**):
  - `a217319` métrica + tagging (hook `func_8000C768`) · `b95f3c2` hook a `func_800069A8` + revertir
    skip-spawn · `814b68f` fix widescreen (walker salta `0x64`) · `a47e0e2` skip-spawn con frontera
    `send_dl` · `8b25b52` ID=`node->0x2C` · `666aa86`+`6d2d3ef` root+orden (probado y **revertido**).
  - Incluye `patches/rt64/hh-interpolation-tagging.patch` (cambios del submódulo `lib/rt64`).
  - **Compila** (Linux). ID actual: `hash(node->0x2C)` (provisional, §3b).
- `lib/rt64` sucio en la rama (por el patch); `main` restaurado.

## 6. Siguiente paso — TAREA 2 (interpolación, rama `fps-interpolacion-tagging`)

**Rehacer la identidad siguiendo §3c/§3d** (no seguir iterando IDs de dirección, ya probadas y
fallidas). Resumen:

1. **ID lógica** = hash(`slot` de objeto/actor, `modelId`, `lod`) + **generación de cámara** (buscar el
   slot en la lista de modelos/actores de HH; §3d.1).
2. **Generación de cámara** con detección de **cortes** (§3d.2) → arregla el parpadeo de cámara.
3. **Un grupo por objeto** (no por nodo), `G_EX_ORDER_LINEAR`; **efectos** `G_EX_ORDER_AUTO`; **2D**
   `G_EX_ID_IGNORE`; **cámara** un grupo de proyección aparte.
4. **Quitar** el skip-spawn propio (RT64 lo hace solo).
5. **Validar** con `HH_PAIRING` en #6/#8/#10/#12. Y **después**, repaso de fps (`HH_FPS=1`; techo 120).

## 7. Siguiente paso — TAREA 1 (release GitHub rota → v0.6.2, `main`)

`[MEDIDO, del código de CI]` La release **v0.6.1** que sirve GitHub está incompleta:

- **Faltan assets**: `.github/workflows/ci.yml` (job `windows`, paso "Empaquetar") copia al `.zip`
  **solo** `Hybrid Heaven Recomp.exe`, `*.dll`, LEEME/CRÉDITOS/LICENCIA y `rom/`. **No copia
  `assets/`** (logos, `lang/*.txt`, `sounds/*.wav`, `saves/templates`). El ejecutable los busca junto
  a sí → sin ellos: sin traducciones, sin logos HD, sin SFX de menú, sin plantillas de guardado.
  `[INFERIDO]` Esto explica "no se compila con assets".
- **Forks viejos / guardado / veneno**: `[INFERIDO, fuerte]` si el build de GitHub no resuelve los
  commits de los forks (`.gitmodules` → `hunkstalker/*`; `runtime.lock` pinea `RT64=a8f0a70`,
  `NMR=a11fbf2`), el clon cae en un runtime **anterior** → faltan los parches del fork NMR
  (PFS 74 slots, vibración↔pak, jump-table #14, server teardown) **y** del fork rt64. Encaja con
  "como una versión anterior a 0.5.0" y con que guardado y crashes de veneno no funcionen.
- `[MEDIDO]` El ZIP de CI **no incluye** `assets/` en ningún punto; el build local
  (`build_windows.local.bat`) usa `lib/` en disco y CMake copia `assets/` junto al exe (`CMakeLists`
  líneas ~214–255). Por eso **local va y GitHub no**.

**Qué hacer en la sesión nueva (v0.6.2):**

1. **Reproducir**: descargar el `.zip` de la release v0.6.1 de GitHub y comparar con un build local
   (¿faltan `assets/`? ¿qué commit de runtime trae? ¿guardado/veneno fallan?).
2. **Arreglar el empaquetado**: copiar `assets/` (y `saves/templates`) al `.zip` de CI; revisar
   `package_release.ps1/.py` vs el paso de `ci.yml` (hay divergencia: el CI empaqueta a mano).
3. **Garantizar los forks**: verificar que `a8f0a70` (rt64) y `a11fbf2` (NMR) **existen en el remoto**
   y que el checkout del clon los resuelve; si no, **pushear los forks** (orden AGENTS: N64Recomp →
   NMR → rt64 → main) antes de publicar.
4. Revalidar en Windows las funciones que faltaban (guardado `.pak`, veneno, #14) y **publicar
   v0.6.2** (`include/hh.h`, `docs/releases/v0.6.2.md`, `release.yml`).
