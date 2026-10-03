# FPS/interpolación — tagging DOBJ, resultados y handoff (2026-10-03)

> Sesión larga. Estado real, sin inflar. Dos ramas de trabajo: **(1)** el tagging de interpolación
> (rama `fps-interpolacion-tagging`, sin mergear, **sin validar en gameplay** todavía) y **(2)** un
> hallazgo de **release rota en GitHub** que `main` (despejada) debe abordar. Distinción medido /
> inferido explícita.

## 0. TL;DR

- **El tagging de transforms por fin llega a RT64** y reduce mucho los artefactos: de `unpaired_moved`
  picos 60–98/s a **media ~3.4/s**, con **77% de frames limpios**. Falta cerrar el resto.
- **Causa raíz encontrada** de por qué no llegaba antes: faltaba `#define F3DEX_GBI_2` (opcode del
  hook extendido). Y el punto de enganche correcto es el **dispatch DOBJ `func_800069A8`**.
- **Release v0.6.1 de GitHub rota**: el `.zip` no incluye `assets/` y probablemente compila con
  forks viejos → "como una versión anterior a 0.5.0". `main` despejada para una **v0.6.2**.

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

- Nodo **DOBJ**: `+0x00` sibling, `+0x08` child, `+0x1C` gmtx (reciclado cada frame), `+0x1C`… `+0x2A`
  tipo de draw. El **puntero del nodo** es estable entre frames → se usa como **ID**.
- El hook (`src/hooks/model_tagging.cpp`, `hh_bone_draw_hook`) envuelve `func_800069A8(a0=node)`:
  emite `gEXEnable` + `gEXSetRDRAMExtended` + `gEXMatrixGroupDecomposed(id, G_EX_PUSH, modelview)`
  antes del draw, y `gEXPopMatrixGroup` después.
- **ID** = `hash(puntero del nodo)` con bit alto (nunca 0/AUTO).

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

- **Reescritura de display list en submit** (`hud_rewrite.cpp`, flag `HH_MTXGROUP` en esa vía):
  **falló 2 veces** (grupos no materializados + geometría rota). Descartada. La vía correcta es el
  **hook del port** (patrón Goemon/Zelda), que es lo implementado.
- **skip en spawn/reaparición** (`g_seen_prev`/`g_seen_cur` con `hh_get_vi_count`): causó
  microdesfases (el VI avanza a mitad de frame → nodos presentes caían como "reaparición" → snap).
  **Revertido.** Si se reintenta, necesita un **frame boundary fiable**, no el VI.
- **Gates globales** `HH_ROT_GATE`/`HH_SCALE_GATE` (en `lib/rt64`, sesión anterior): sonda, no
  arreglo; off por defecto. Siguen en el fork.

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

- **`main` = `bebd76e` (`v0.6.1`) LIMPIA** (submódulos restaurados). Despejada a propósito para la
  v0.6.2 (§7).
- **Rama `fps-interpolacion-tagging`** (2 commits `wip`, **sin mergear**):
  - `a217319` metric + tagging (hook `func_8000C768`).
  - `b95f3c2` hook movido a `func_800069A8` + revertido el skip-spawn.
  - Incluye `patches/rt64/hh-interpolation-tagging.patch` (cambios del submódulo `lib/rt64`
    versionados como patch; el submódulo se restaura en `main`).
- Sin commitear (working tree de la rama): nada pendiente salvo el propio `lib/rt64` (sucio por el
  patch). Notas y docs sí commiteados en la rama.

## 6. Siguiente paso — TAREA 2 (interpolación, rama `fps-interpolacion-tagging`)

1. **Validar el hook en `func_800069A8`** (aún no probado en gameplay): run Windows con
   `HH_MTXGROUP=1 HH_PAIRING=1`. Criterio: `unpaired` base ~29/s **baja** (ya no debería quedar 1
   transform/frame sin tag), `unpaired_moved` baja, y **sin microdesfases** (skip-spawn ya fuera).
2. **Cerrar el `skip` en discontinuidades** (el "brillo de 1 frame" de #6): necesita un **frame
   boundary fiable** para distinguir spawn/reaparición de movimiento normal. Opciones: usar el
   cambio de estado del objeto desde la lógica (patrón `TAGGING_OBJECT_SET_SKIP_INTERPOLATION` de
   Goemon) o detectar el reset de escala/pose en el propio nodo.
3. **Repaso de fps** (apuntado): techo 120 (Vsync/panel). Medir `[hh-fps]` (`HH_FPS=1`) para
   `present` vs `target` y ver si hay margen/cuello. **Después** de la interpolación.
4. **Validar #8 puertas / #10 / #12** con la métrica (no con la vista).

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
