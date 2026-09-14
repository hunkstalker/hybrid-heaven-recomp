# ADR 0004 — Registro dinámico de módulos de código en bases reutilizadas

- **Estado**: Aceptado (2026-09-14).
- **Fecha**: 2026-09-14
- **Contexto relacionado**: ADR 0001, `../architecture.md` §2/§4/§5, `../../TODO.md` #3/#10/#14,
  `../../notes/2026-09-14-registro-dinamico-modulos.md`.

## Contexto

ADR 0001 pre-enlaza cada módulo (`trans`) como sección con `ram_addr` fijo y lo registra
estáticamente (`register_flat_code`). Con la transición desbloqueada se comprobó que el juego
**reutiliza bases de VRAM**: idx 24 se decodifica en la base de idx 23 (`0x801BF1A0`), idx 99 en la
de idx 54, idx 25 en `0x801E1BE0`. El registro estático no puede representar dos módulos en la
misma dirección (gana el último), y el recompilador/resolución global de llamadas mezcla secciones
(ramas/fallthroughs al módulo equivocado).

## Decisión

Registrar los módulos **dinámicamente al cargarse**, por sección y en la base real:

1. El loader del ROM (`FUN_80003824`) se envuelve siempre en `get_function`; tras descomprimir el
   blob (a0=ROM retail, a1=base destino) llama a `recomp::overlays::load_module_by_source(a0, a1)`.
2. `setup_module.py` genera la tabla `src_rom → rom_addr` (ROM combinado) en
   `port/HybridHeavenRecomp/src/main/module_sources.inc`; el runtime la registra al arrancar.
3. `register_flat_code()` **omite** las secciones de módulos (solo registra la imagen plana).
4. Los mid-entries que el juego llama por puntero se añaden por módulo:
   `gen_module_extras.py` (traza `HH_JALTRACE` del emulador, con desambiguación por fase
   boot/post-burst y filtro de delay-slots) + `add_missing_funcs.py` (imagen plana, iterativo).
5. `validate_syms.py` y `fix_fallthroughs.py` pasan a ser **conscientes de sección**: validación por
   sección, protección de entradas indirectas (`config/keep_syms.txt`) y continuación de fallthrough
   por prefijo de módulo (`M<n>_`).

## Consecuencias

- El port ejecuta los módulos del burst y la transición (`fe00=0x3C01`), con 0 símbolos faltantes en
  runs largos.
- La recompilación usa prefijos de símbolo por módulo (`M24_FUN_...`) para evitar colisiones C.
- El registro estático de módulos queda obsoleto; cualquier módulo futuro necesita solo su entrada
  en `MODULES` (+ extras si el juego lo llama por puntero).
- Riesgo residual: si el juego llama código en una base **relocalizada** (blobs con relocs
  aplicadas por `trans`), el recompilado (autoligado) no lo reproduce; hoy no se ha observado
  ejecución de copias relocalizadas (p.ej. idx 23 @`0x801FA948` se registra pero no se ejecuta).

## Alternativas descartadas

- Mantener registro estático + elegir "el módulo correcto" a mano: no escala y rompe el boot.
- Forzar bases deterministas desde el asignador `trans` (opción B de ADR 0001): más invasivo que
  registrar en la base real.

## Criterio de salida

1. ✅ Módulos del burst cargados y ejecutados (`[LD384]=20`, `[OVL]` 1..6, `fe00=0x3C01`).
2. ✅ 0 `Failed to find function` en un run de 220 s.
3. ◻ Fase `0x80037750` > 0 y geometría/píxeles de gameplay verificados.
