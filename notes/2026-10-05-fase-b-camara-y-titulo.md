# 2026-10-05 — Fase B (0): regresión de cámara + objeto del título — RESUELTA

> Rama `fase-b-interpolacion`. Diagnóstico por A/B + fix quirúrgico; **validado por el mantenedor
> (Windows, 2026-10-05)**: cámara al apuntar y objeto 3D del menú de título **correctos**, sin
> regresión. Continúa el plan de Fase B (emparejamiento) de
> `notes/2026-10-05-fase-a-libultra-cobertura.md` §Fase B.

## Síntomas

Dos artefactos de **emparejamiento** de la interpolación (que se hicieron visibles al quedar el tagging
ON por defecto):
1. **Cámara al apuntar**: barrido/desalineación del encuadre.
2. **Objeto 3D del menú de título**: se movía "en coordenadas" (mal emparejado).

## Diagnóstico (A/B medido, `HH_EMIT_TAG` / `HH_EMIT_PROJ` / `HH_EMIT_MV` / `HH_EMIT_MV_SKIP`)

| Prueba | Cámara | Objeto título |
|---|---|---|
| ambas ON (por defecto) | mal | mal |
| proyección OFF, modelview ON | **bien** | mal |
| modelview OFF, proyección ON | mal | **bien** |
| `HH_EMIT_MV_SKIP=15` (salta C768) | bien | **bien** |
| `HH_EMIT_MV_SKIP=8` (salta 8F30) | bien | mal (8F30 **no** era el culpable) |

Conclusiones:
- **Cámara**: la rompe **cualquier** grupo de **PROYECCIÓN**. En HH la cámara va **horneada** en cada
  modelview; un grupo de proyección la **duplica** y RT64 empareja mal el `viewProj`. → **proyección
  OFF por defecto** (el modelview con generación ya hace snap en los cortes).
- **Objeto del título**: lo rompía **C768** (id 15, emisor de efectos). En el título se llama con un
  `a1` distinto (`FF868DA5`) que en el emisor de efectos real (recibe `kGfxCursor = 0x8008D5BC`);
  envolver esa llamada como modelview movía el objeto.

## Fix

`src/hooks/model_tagging.cpp`:
- Ids de los emisores con **generación de cámara** (`interp_id`), antes `0xEE…` sin generación.
- **Proyección OFF** por defecto (`HH_EMIT_PROJ=1` la reactiva, A/B); el grupo de proyección ya no se
  emite para todos.
- **C768**: el modelview solo se emite en la **ruta del cursor de gfx** (`ctx->r5 == kGfxCursor`) →
  arregla el título sin perder el tagging de efectos en gameplay.
- Flags de diagnóstico: `HH_EMIT_PROJ`, `HH_EMIT_MV`, `HH_EMIT_MV_SKIP`.

Commits: `5d1c7f0`, `32d1058`, `d2521a4`, `b8bd635`, `61c0af5`, `1b36e08`.

## Pendiente de Fase B

- **[NUEVO/CLÁSICO] Enemigo que cambia de coordenadas y aparece "en primer plano"** al inicio del
  juego: discontinuidad de **posición** de un objeto con el **mismo id** → RT64 interpola el salto
  (el objeto cruza el encuadre). El `stable_slot` ya evita pairings de spawns/reapariciones, pero un
  **teletransporte con el mismo root/modelo** conserva el id. Candidato: detectar el salto de posición
  por objeto y **bumpear su id** (como la generación de cámara), o gate de discontinuidad en RT64.
- Resto: enumeración de sitios de dibujo, **LOD** en el id (A2.4), 2D `G_EX_ID_IGNORE`, `ORDER AUTO`.
