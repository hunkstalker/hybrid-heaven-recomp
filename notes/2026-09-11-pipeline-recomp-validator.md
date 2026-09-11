# 2026-09-11 — Pipeline reproducible + validador de símbolos (Fase A #3)

> Evidencia de sesión. No editar.

## Qué se hizo
- **`tools/recomp.py`**: pipeline de un comando → validar syms → N64Recomp → copiar al port →
  `fix_fallthroughs` → asegurar declaraciones `*_recomp` → build opcional.
- **`tools/analysis/validate_syms.py`**: valida límites de función contra la ROM con capstone:
  - **delay-slot cortado** (un `jr $ra` cuyo delay-slot queda fuera del rango),
  - **rama cruzada** (rama a un punto *interior* de otra función → split incorrecto),
  - **data-as-code** (muchos bytes no decodificables) y tamaños inválidos.
  - `--fix` genera una syms corregida (extiende sizes y fusiona splits seguros; no elimina funciones
    que sean destino de `jal`/`j`).

## Hallazgos del validador (y correcciones aplicadas)
Sobre `config/us_ghidra.syms.toml` detectó, además de lo ya arreglado a mano:
- **`FUN_8001fefc`** `size 0x178 → 0x17C`: el delay-slot `addiu sp,sp,0x48` (¡restauración de pila!)
  quedaba fuera → **bug latente real** (mismo patrón que `FUN_80003db4`).
- **`FUN_80003D3C`** `size 0x74 → 0x78`: delay-slot `nop` (inofensivo, corregido por consistencia).
- **`FUN_80004838` + `FUN_80004998`** fusionadas (`FUN_80004838 size 0x2A4`): la rama
  `b 0x80004ACC` apuntaba a un epílogo compartido dentro de `FUN_80004998` (split incorrecto;
  `0x80004998` no era destino de `jal`).
- `--fix` re-valida **OK**; tras regenerar y rebuild, el boot **no regresiona** (alcanza el mismo
  bloqueante de módulo `0x80107830`).

## Nota de diseño
- El validador excluye funciones-dato del análisis de ramas/delay (evita falsos positivos). Quedan
  **189 "funciones" con aspecto de datos** (muchas con >50% de bytes no decodificables); solo 4
  están en `ignored`. Es deuda pendiente de limpieza, no bloqueante.
- `use_lookup_for_all_function_calls = true` sigue generando ~30k lookups/arranque (ver nota del
  modelo de módulos); pendiente evaluar `false` (TODO A3b).

## Artefactos
- `tools/recomp.py`, `tools/analysis/validate_syms.py`.
- `config/us_ghidra.syms.toml` actualizado (+ `.bak` de seguridad al aplicar `--fix-syms`).
- `docs/workflows.md` §1 actualizado con el pipeline.

## A3b — `use_lookup_for_all_function_calls = false` (evaluado, no adoptado)

- Con `false`, N64Recomp emite **llamadas directas** en vez de lookups. Resultado:
  - el pipeline **auto-declara 15 `*_recomp`** en `funcs.h` (mejora general del quirk);
  - **pero** emite llamadas directas a funciones en `ignored` (data-as-code): `FUN_800493c4`,
    `FUN_800495ec` → `implicit declaration` → build roto.
- No es drop-in: requiere resolver el data-as-code (189 "funciones" sospechosas). **Revertido a `true`**.
- El coste actual (~30k lookups/arranque, dominado por `FUN_80003D3C`) es aceptable y no bloquea.
- Reintentar cuando se limpie el data-as-code.
