# 2026-10-02 — #14 veneno/ataque a distancia: causa raíz = jump table mal recompilada (fix en N64Recomp)

> El crash del veneno **no** era (esta vez) el callback `0xFFFF84CD`: es un **abort del runtime** al
> caer la `switch` de una función recompilada en un caso **fuera de rango**. Causa: N64Recomp
> **truncaba la jump table** al primer destino que no cae dentro de la propia función. Arreglado **de
> base** en el recompilador. Distinción **medido** / **inferido** explícita.

## Evidencia (medido, `run_windows_trace.bat` perfil combate)

Consola (`hh_trace_console.log`), punto final antes del cierre:

```
Switch-case out of bounds in func_8035A3D8_13150A8 at 0x8035A3F8 for jump table at 0x8038A000
```

`switch_error` (`lib/N64ModernRuntime/librecomp/src/recomp.cpp:542`) hace `assert(false); exit(...)`
→ **crash fatal**. Se llega ahí justo tras las `[SETCB]` de callbacks M12 sobre `obj=8025A80C`, en la
escena de combate (`hh_ovl.log`: a t≈113 s cargan `section=49 ram=80358820` = `file_057` combate y
`section=54 ram=8038CFC0`).

## Causa (medido)

`func_8035A3D8(a0)` = `a0 & 0xFF`, que indexa una **jump table de 8 entradas** (`0x8038A000`):

| idx | destino ROM | devuelve |
|---|---|---|
| 0 | 0x8035A400 | 1 |
| 1 | 0x8035A408 | 2 |
| 2 | **0x8035A428** (`func_8035A428`, **otra función**, hoja `move v0,0; jr ra`) | 0 |
| 3 | 0x8035A410 | 3 |
| 4 | 0x8035A418 | 4 |
| 5/6/7 | 0x8035A400 / 0x8035A408 / 0x8035A428 | 1 / 2 / 0 |

El C recompilado **solo** traía `case 0` y `case 1`:

```c
switch (jr_addend_8035A3F8 >> 2) {
    case 0: goto L_8035A400; break;
    case 1: goto L_8035A408; break;
    default: switch_error(__func__, 0x8035A3F8, 0x8038A000);
}
```

Motivo (`lib/N64ModernRuntime/N64Recomp/src/analysis.cpp:334`):

```cpp
// Check if the entry is a valid address in the current function
if (jtbl_word < func.vram || jtbl_word >= func.vram + func.words.size()*sizeof(...)) {
    break;   // <-- corta la tabla en la entrada 2 (apunta a func_8035A428)
}
```

Al cortar en la entrada 2 se pierden también las 3,4 (que **sí** están dentro de la función). Cualquier
índice 2..7 (ataques a distancia de varios tipos) → `switch_error` → abort **antes de empezar el
ataque**. **Inferido**: el índice lo pone `lbu 0x2D9(obj)` (tipo de ataque); la tabla cubre 8 valores
legítimos, así que es un fallo de recompilación, no un índice basura.

## Fix (de base, en el recompilador)

Se editó `toolchain/src/N64Recomp` (es lo que construye el binario de `regenerate.py`):

1. `src/analysis.cpp` — la entrada es válida si cae **dentro de la función** **o** es el **inicio exacto
   de otra función de la misma sección** (se consulta `context.functions_by_vram`). Además, cap de 1024
   entradas para no sobre-leer si no hay tabla siguiente.
2. `src/recompilation.cpp` — al emitir los `case`, si la entrada cae en otra función no hay etiqueta
   local: se emite un **tail-call** (`LOOKUP_FUNC(0xTARGET)(rdram, ctx); return;`), igual que el
   tratamiento ya existente de saltos fuera de función.

Regenerado (`tools/regenerate.py --skip-splat --skip-elf`) y compilado. `func_8035A3D8` ahora tiene los
8 casos; 2 y 7 hacen tail-call a `func_8035A428`.

## Alcance (medido tras regenerar)

- **11 funciones** afectadas, **73 entradas** con tail-call (no solo el mapa del veneno). El fix es
  general: cualquier tabla con destino en otra función (patrón "hoja compartida") deja de abortar.
- Sin regresión en el replay de gameplay (`hh_replay_map.txt`): panel del minimapa y clases del HUD
  idénticos, 0 `switch_error`.
- Sobre-lectura benigna: en `func_8035A3D8` aparece un `case 8` extra (siguiente tabla) que **nunca** se
  alcanza por el `sltiu a0,8` original; el resto de casos usados son los valores reales de la tabla.

## Validación y alcance del C (medido)

- **Validado en Windows** (mantenedor, 2026-10-02): el crash del ataque a distancia/veneno **ya no
  ocurre**. Fix aceptado.
- Se comparó el C generado **sin** el fix con el de referencia del repo de secretos
  (`hh-recomp-secrets/RecompiledFuncs`): **idénticos**. El diff con el fix son **solo** las tail-calls
  añadidas → el fix no altera nada más.
- De las 11 funciones, **9** tienen las entradas nuevas **inalcanzables** (primer índice nuevo ≥ bound;
  p. ej. `func_802208B0`: `a0=lbu 0x2D8`, bound `0x15`, nuevas 21-34). Solo `func_8035A3D8` y
  `func_8035A938` tienen entradas alcanzables, con destinos reales (`func_8035A428`/`A9E0`/`AA14`).

## Nota: otra incidencia NO relacionada

Tras esta validación apareció una **desaparición de textos tras GUARDAR partida** (sistema de guardado
nuevo). El mantenedor confirmó que es un **bug distinto**, no causado por este fix. Se investiga aparte
(¿solo con MODO HEAVEN o siempre?). No confundir con este cambio.

## Versionado (PENDIENTE del mantenedor)

- `toolchain/` está **gitignored**; el snapshot versionado es `recomp/n64recomp_changes/`, donde ya está
  el parche `2026-10-02-jump-table-cross-function.patch` (reverse-apply check OK).
- **Aviso**: el snapshot `recomp/n64recomp_changes/` **ya estaba desincronizado** con
  `toolchain/src/N64Recomp` antes de este cambio. Hay que **reconciliar** el snapshot e incluir este
  parche; si se adopta también en el fork `hunkstalker/N64Recomp`, requiere commit/push del fork.
- El C recompilado **no** se versiona (ADR 0009); CMake lo toma de `build/recomp/RecompiledFuncs`.
  **Ojo (build)**: el volumen compartido puede provocar builds incrementales con objetos obsoletos
  (clock skew); ante resultados raros, **rebuild limpio** (`borrar build/windows`).
