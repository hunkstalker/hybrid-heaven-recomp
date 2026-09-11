# ADR 0001 — Modelo de ejecución de módulos de código (`trans`)

- **Estado**: Aceptado (2026-09-11). Decisión: **A** (con **B** como seguro).
- **Fecha**: 2026-09-11
- **Contexto relacionado**: `../architecture.md` §2-4, `../../TODO.md` Fase A,
  `../../notes/2026-09-11-modelo-modulos-trans.md`.

## Contexto

El juego carga código no plano (módulos) desde la ROM mediante `trans` (`seg_RomDecode_sep` /
`trans_to_malloc64_sep`), lo descomprime en RAM y lo ejecuta por puntero (`jalr`). El boot se
bloquea en `get_function(0x80107830)` (base de salida del descompresor). La recompilación estática
solo ejecuta funciones pre-recompiladas y registradas → es una **capacidad ausente**, no un bug de
símbolos.

Caracterización (2026-09-11): el módulo de boot es **Nisitenma índice 7** (`ROM 0x4E69A8`,
comprimido `0x55DD4`, descomprimido `0x89DB0` ≈564 KB de MIPS, CRC32 `0xA9213032`); se carga en
**base `0x80107830`, idéntica en 3 runs**; el blob es MIPS **autoligado** (direcciones absolutas,
sin relocs).

## Decisión

**A. Pre-recompilar los módulos de código y registrarlos en su base.** Cada asset de código se
recompila como sección con `ram_addr` = su base determinista; el runtime resuelve `get_function`
para ese rango. Extiende el soporte de overlays de N64ModernRuntime (`register_flat_code`).

**B** (fijar el asignador `trans` a bases deterministas) se aplica **solo si** algún módulo
posterior resulta no determinista; es un seguro, no la vía principal.

**C** (JIT/interpretación dinámica del blob): descartado.

## Consecuencias

- Pipeline de recompilación **multi-módulo** (imagen plana + secciones de módulos), no monolítico.
- La tarea #3 (mapa `id → base`) pasa a **camino crítico** (provee las bases de los módulos).
- `get_function` debe resolver funciones de módulos por base; el loader registra `(origen, base)`.
- Recompilar el índice 7 añade ~564 KB de código; requiere syms propia del blob (Ghidra sobre el
  asset descomprimido).
- **Conflicto de registro**: el rango del módulo (`0x80107830..0x80191520`) solapa **26 funciones
  "planas" de Ghidra** (data-as-code) y 14 colisiones de nombre → al integrar hay que excluir esas
  26 del set plano y dar **precedencia** a las funciones del módulo.

## Alternativas descartadas

- Ignorar módulos y solo renderizar el núcleo plano: inviable, el boot ejecuta módulos.
- Reescribir el cargador `trans` en el port: acopla a una reimplementación; posponer.

## Criterio de salida

1. ✅ Bases medidas (3 runs, deterministas para el módulo de boot).
2. ✅ Contrato capturado (MIPS autoligado; descriptor `+0x1C = base`).
3. ◻ Inventario asset→código/datos (parcial: índice 7 confirmado como código).
4. ✅ ADR aceptado + `../architecture.md` y `../../TODO.md` actualizados.
