# 2026-10-05 — Verificación de base: jump tables cross-function (clase #14/veneno)

> Sesión de verificación (rama `verificacion-byte-match`). Herramientas nuevas en `tools/verify/`.
> Distinción medido/inferido explícita. Continúa el análisis iniciado al estudiar la obra de
> `ogdanimal/HybridHeaven-Decomp` + `HybridHeaven-Recomp` (solo como referencia de aprendizaje).

## Qué se verificó

1. **Ida y vuelta de la ROM**: `tools/verify/verify_roundtrip.py`.
   - Fase 1 (ya existía): gate ELF↔imagen expandida byte a byte (`recomp/tools/build_elf.sh`) → OK.
   - Fase 2: descompresión+tabla propias vs manifiesto de referencia → **91/91 OK**.
   - Fase 3: expansión (`hh.expanded.z64`) vs manifiesto → **91/91 OK**.
   - Fase 4 **BLOQUEADA**: `tools/lzkn64/lzkn64.py` solo implementa `decompress`; falta compresor
     LZKN64 para recomprimir y comparar con el SHA1 retail (equivalente a su `make COMPRESSED=yes`).

2. **`size` legacy (Ghidra) vs extents del ELF**: `cross_legacy_sizes.py` / `triage_legacy_sizes.py`.
   - 1.007 discrepancias: 37 "split" y 970 otros. **Ghidra NO es oráculo**: mezcla merges erróneos
     (p.ej. `0x80026E58` = `__ull_div`+`__lshift`+…, que splat separa bien) con la clase real.
   - Conclusión: no se aplica en bloque.

3. **Detección autoritativa de la clase veneno**: `find_cross_jumptables.py` +
   `find_latent_jumptable_crashes.py`. Marca los `case` del C generado que hacen
   `LOOKUP_FUNC(0x…)(rdram,ctx); return;` (tail call del parche) y los clasifica:
   - **73 casos cross-function en 11 funciones.**
   - **0 crashes latentes**: los 69 casos cuyo índice está **fuera del bound** del switch
     (`sltiu`) son **over-read inalcanzable**.
   - Los 4 alcanzables son exactamente las dos funciones del veneno, y sus targets **sí** son
     funciones registradas → el parche (tail call) es correcto:
     - `func_8035A3D8` cases 2/7 → `0x8035A428`
     - `func_8035A938` cases 3/4 → `0x8035A9E0` / `0x8035AA14`

## Consecuencia / decisión

- **No hay deuda funcional** en esta clase: no hay caso alcanzable que aborte. El parche de N64Recomp
  cubre la clase (los únicos 4 casos vivos funcionan).
- **No se toca la base** (restaurar `size:` en `symbol_addrs`) por ahora: solo sería limpieza
  cosmética (convertir los 4 tail calls en `goto` locales) a cambio de regenerar C y revalidar un
  port validado a mitad de juego. Se documenta como candidato, no como necesidad.
- El over-read (69 cases muertos) es inocuo por el bound del propio juego, pero convendría que el
  parche deje de leer más allá de la tabla real si algún día se puede derivar su longitud.

## Herramientas (rama `verificacion-byte-match`)

- `tools/verify/verify_roundtrip.py` (fases 1–3; fase 4 bloqueada).
- `tools/verify/cross_legacy_sizes.py`, `triage_legacy_sizes.py` (Ghidra vs ELF).
- `tools/verify/find_cross_jumptables.py`, `find_latent_jumptable_crashes.py` (autoritativo).
