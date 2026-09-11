---
name: research-blocker
description: Use when hitting a technical blocker (recompilation, function boundaries, os funcs, overlays, runtime crashes, build/regeneration errors, N64 port issues). Before guessing or giving up, perform a DEEP internet search to find the known solution in N64Recomp/N64ModernRuntime/RT64 docs, GitHub issues, and other recomp projects.
---

# Investigar bloqueos con búsqueda profunda en internet

Ante cualquier **bloqueo técnico**, NO adivines ni te des por vencido. Antes, haz una
**búsqueda profunda en internet** para encontrar la solución documentada/ya resuelta.

## Cuándo disparar (triggers)
- Crash / segfault / deadlock / `terminate` en el runtime o el juego recompilado.
- `Error recompiling`, `Unhandled instruction`, `Failed to find function`, `Failed to analyze`.
- Límites de función incorrectos, funciones mal detectadas, `static_` mal acotado.
- Os funcs / libultra sin mapear o mal nombradas.
- Overlays que el código plano llama, segmentos cargados en runtime.
- Errores de build/regeneración (C inválido, `implicit declaration`, TOML).
- Cualquier duda de "cómo se hace esto" en el pipeline N64Recomp.

## Cómo buscar (proceso)
1. **websearch** con varios términos a la vez (mínimo 2-3 queries en paralelo). Usa el
   vocabulario del dominio: `N64Recomp`, `N64ModernRuntime`, `librecomp`, `ultramodern`,
   `RT64`, `libultra`, `os funcs`, `function_sizes`, `ignored`, `overlays`, `sym_match`.
2. **Repos/issue de referencia** (fetchea el contenido cuando websearch dé un resultado
   relevante):
   - `github.com/N64Recomp/N64Recomp` y sus issues (#53, #58, #90, #108 son ejemplos ya
     útiles para límites de función / instrucciones no soportadas / funciones a ignorar).
   - `github.com/N64Recomp/N64ModernRuntime` (runtime: threads, mesgqueue, timers, VI, RSP).
   - `github.com/klorfmorf/Goemon64Recomp` y `Goemon64RecompSyms` (mismo motor Konami).
   - `github.com/Mr-Wiseguy/Zelda64Recomp` (port de referencia).
   - `github.com/shygoo/n64sym` (identificar símbolos/libultra), `decompals/flib`,
     `ethteck/splat` (generar ELF).
   - `github.com/DohmBoy64Bit/n64recomp-companion` (workflow; ojo: archivado y ELF-only).
   - Proyectos recomp: drmario64_recomp_plus, smash64r, HarvestMoon64Recomp, GoldenRecomp.
3. **Filtra por causa raíz**: los problemas de N64Recomp suelen ser por:
   - funciones con símbolo `ABS`/`size=0` en el ELF (el recompilador solo usa `FUNC` con
     `size>0`), **→ añadir a `ignored` o arreglar el límite**.
   - datos mal detectados como funciones **→ añadir a `ignored`**.
   - libultra sin nombre (reimplementada en el runtime) **→ añadir a `ignored`**.
   - límites de función incorrectos **→ corregir `size` (o `[[function_sizes]]` si usas ELF)**.
   - overlays/segmentos cargados en runtime **→ registrar overlays (`register_overlays`) o
     `recomp_load_overlays` en el boot patch** (solo se ve el segmento boot en estática).
4. **Aplica la solución encontrada**, regenera y prueba. Si no converge, repite la búsqueda
   con términos más específicos (pega el error literal).

## Reglas
- La búsqueda es OBLIGATORIA antes de asumir que algo es imposible o de inventar un fix.
- Cita la fuente (repo/issue) en el reporte y, si aplica, guarda el hallazgo en `notes/`.
- Herramientas locales ya útiles: `n64sym` (en `/tmp/n64sym/bin/`), Ghidra
  (`toolchain/ghidra/ghidra_12.1.3_PUBLIC`), el recompilador
  (`toolchain/src/N64Recomp/build_recomp/N64Recomp`), y `notes/reference/n64sym_osfuncs_us_retail.txt`.
