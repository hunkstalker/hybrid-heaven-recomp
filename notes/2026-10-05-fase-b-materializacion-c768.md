# 2026-10-05 — Fase B: materialización del tagging (regresión del gate de C768) — RESUELTA

> Continuación de `notes/2026-10-05-fase-b-emparejamiento-metodo.md`. **Validado por el mantenedor
> (Windows, 2026-10-05)**: artefacto (PJ/escala) de gameplay **desaparece**, y con el gate de escena el
> **objeto del menú de título sigue en su sitio**. Distinción medido / inferido explícita.

## Trazas de la run del gate nuevo (`hh_A.log`)

`[MEDIDO]` Fase título (f<240): `[hh-types] 2:109/120` (solo el objeto del título), `explicit_ids=0`,
`emitmat=[-]` → C768 **gated OFF** (flag título true), sin tag. Gameplay (f≈240+): `explicit_ids≈1500/s`,
`groups_seen≈647k`, `emitmat=[5 7 9 10 12 15]` → C768 **ON** y materializa, `unpaired_moved≈0`. Sin
errores. Coincide con `set_native_title_active(false)` en la carga de partida.

## Síntoma y evidencia (`HH_PAIRING` + sondas)

Run A (gate actual) vs run B (`HH_C768_ALL=1`):

| métrica | A (gate `cursor_path`) | B (C768 siempre) |
|---|---|---|
| `explicit_ids` | **0/s** | ~2600/s |
| `groups_seen` | **0** | ~220000 |
| `emitmat` | `[-]` | `[6 9 10 15 materializan]` |
| artefacto | sí | **no** |

`[MEDIDO]` En A los grupos **se parsean** (`matrixid` > 0) pero **no materializan** en ningún vértice:
todo transform queda en `id=AUTO` y RT64 empareja con su heurística, que ante saltos alternantes hace
el barrido (posición + “escala” aparente del lerp de matriz) → artefacto de 1 frame.

## Causa raíz

`[MEDIDO]` `func_8000C768` **solo** lo llama el dispatch `func_800069A8` (2 call sites, `0x80006A2C/3C`);
`a1` (`ctx->r5`) **no es un argumento suyo** (es un registro sobrante). El fix del objeto del título
(2026-10-05) gateaba C768 con `ctx->r5 == kGfxCursor`, es decir comparaba **basura** con un puntero; en
la práctica el gate quedaba OFF en gameplay → C768 (el único emisor que materializa) no emitía su
`gEXMatrixGroup` → sin ids explícitos. Los valores reales de `a1` en gameplay (`FF31AF6E`, `FE53E34C`,
`000CC0A2`, …) lo confirman: nunca `0x8008D5BC`.

`[MEDIDO]` Sonda de materialización (`mat_push`/`mat_orphan`/`mat_clr`, en `rt64_rsp.cpp`): en B
`mat_push≈mat_clr+consumidos`, con ~24% de grupos **huérfanos** (`mat_orphan`: push/pop sin vértice
entre medias) — normal para emisores cuyos sub-DLs van en otro tramo. Lo importante es que el resto
materializa en cuanto C768 emite.

## Fix

- `src/hooks/model_tagging.cpp` (`hh_emit_c768_hook`): sustituido el gate de basura `ctx->r5==kGfxCursor`
  por **escena**: `hh::menu::native_title_active()` (título → no emitir; partida → emitir). El A/B pasa
  a `HH_C768_ALL=1` (emite también en título).
- `include/hh/menu.h` + `src/subsystems/menu.cpp`: flag `native_title_active()` / `set_native_title_active()`.
- `src/hooks/sections.cpp`: `hh_title_menu_hook` lo pone a **true**; `hh_heaven_load_hook` a **false**.

## Logs A/B separables (workflow)

`HH_LOG_FILE=<name>` (p. ej. `hh_A.log`) y `HH_SPIKE_FILE=<name>` evitan pisar el log entre runs A/B
(`src/platform/support.cpp`, `rt64_game_frame.cpp`).

## Pendiente / a vigilar

- `[MEDIDO]` **Objeto del título confirmado** por el mantenedor (no se sale de su sitio).
- `unpaired_moved` sigue habiendo (~18/s) con ids explícitos: puede ser movimiento real o transitorios;
  vigilar de nuevo si reaparece el artefacto.
- Materialización pass-1: los grupos a veces se pierden por frontera de workload (`mat_orphan`); si
  aparece un artefacto de objeto sin efecto C768, es el siguiente frente.
