# 2026-09-11 — A2: completitud de símbolos planos (resuelto por evidencia runtime)

> Evidencia de sesión. No editar.

## (b) Analizador CFG — implementado pero **no seguro como auto-fix**
- `tools/analysis/fix_function_bounds.py`: reachability por función (detecta inicios no alcanzables
  tras un terminador). **Sobre-parte**: p. ej. `0x80000880` (delay-slot de `jal`) se marcaba como
  inicio porque un `b` salta por encima y el CFG simple no sigue **jump-tables** computadas.
- En la syms plana proponía **1706** funciones (falsos positivos). Se deja como **asesor
  `--report-only`**, no como auto-fixer.
- Dato clave: el export crudo de Ghidra (`work/ghidra_funcs.txt`, **1095**) tampoco tenía las
  funciones que faltaban (`0x80020078`, `0x80020460`, `0x80004310`, `0x803839A0`). Es decir, el
  análisis puramente estático no basta en este binario.

## Solución: **evidencia runtime** (determinista y precisa)
- `tools/analysis/add_missing_funcs.py`: parsea `Failed to find function at 0xX` de un log de boot,
  añade la función (divide la contenedora) y reescribe la syms.
- **Modo soft-lookup** (`HH_SOFT_LOOKUP=1`): `get_function` no aborta; loguea y devuelve un stub
  no-op → un solo run revela **varias** funciones faltantes (batch) en vez de una.
- Bucle: run (soft) → `add_missing_funcs` → merge → recomp → build → repetir.

## Resultado
- **0 funciones faltantes** (soft y hard). Convergió.
- El boot **corre 4200–5400 frames** de VI y solo envía tareas RSP de **audio (type 2)** (no-op).
- Nuevo bloqueante: **`terminate called without an active exception`** (~4200 frames) — ciclo de vida
  de hilos del runtime, **no** de símbolos.

## Herramientas añadidas
- `tools/analysis/fix_function_bounds.py` (CFG, `--report-only`).
- `tools/analysis/add_missing_funcs.py` (runtime-driven).
- `get_function`: modo `HH_SOFT_LOOKUP` (depuración de símbolos).
