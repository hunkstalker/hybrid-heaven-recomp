# ADR 0007 — Cache de assets y loader LZKN64 nativo (la ROM solo la primera vez)

- **Estado**: **Implementado v1** (2026-09-18; validado headless; pendiente validación Windows)
- **Fecha**: 2026-09-18
- **Contexto relacionado**: `../../notes/2026-09-18-suavizado-fase1-y-cache-loader.md`,
  `../../notes/2026-09-18-faseb-cache-trans-implementado.md`,
  `../../notes/2026-09-17-replay-mode-vi-vis-negativo.md` §5i, `../../notes/2026-09-05_asset-map.md`,
  ADR 0002 (des-stub de funciones), `../architecture.md` (loader `trans`).

## Contexto

El port carga los módulos del juego con el loader `trans` (`FUN_80003824`), que lee el asset
comprimido del ROM y lo descomprime **LZKN64** dentro de RDRAM. Coste medido: en cada carga/puerta
hay stalls de **147 ms (headless) a varios segundos (Windows)**, y en ticks lentos el código guest
(`guest_busy`) se come el presupuesto de 2 VI (33,3 ms). Los recomps del ecosistema N64Recomp
suelen "preparar" la ROM en el primer arranque; aquí no existe esa fase y el `.exe` necesita la ROM
siempre. El formato LZKN64 ya está descifrado y validado en Python (`tools/lzkn64/lzkn64.py`:
el asset Nisitenma `off=0x4E69A8 size=0x55DD4` descomprime a 564.464 B de código MIPS).

## Decisión

1. **Reimplementar `FUN_80003824`** (loader + LZKN64) en C++ nativo, declarándola en la lista de
   `reimplemented_funcs` del toolchain (patrón ADR 0002).
2. Añadir un **cache en disco** (`cache/trans.bin` + índice `(rom_src, size) -> offset`):
   - **hit** -> `memcpy` del dato descomprimido al destino (sin leer la ROM, sin descomprimir);
   - **miss** -> descompresión nativa desde la ROM + alta en el cache (auto-construible).
3. **Validación**: byte a byte contra `tools/lzkn64/lzkn64.py` para todas las claves del loader
   (extraíbles de los logs `[LD384] s=`) y modo de comparación con el original (checksum + fallback)
   en las primeras pasadas.
4. Incluir el hash de la ROM en el cache (invalidación si cambia) y el **repoblado** con un
   extractor offline opcional (asset-map existente; total ~14 MB descomprimidos).

## Consecuencias

- Positivas: los hitches de carga/puerta desaparecen (o se reducen al `memcpy`); el tick no pierde
  el deadline por el loader; el `.exe` deja de necesitar la ROM una vez el cache cubre lo jugado
  (con cache completo, no necesita la ROM en absoluto para esos assets). Tamaño ~14 MB.
- Negativas / riesgos: hay que replicar **exactamente** el comportamiento del loader original
  (incluidos sus efectos laterales: p. ej. el byte `0x801CC8C4=0xFF` tras cada carga); implica
  tocar la lista de reimplementadas y **recompilar** (regeneración del C). La variante `LZSS 5/7`
  del `trans` está por caracterizar (`PROYECTO.md` §4): verificar que el loader no usa variantes.
- Alternativa descartada (por ahora): *return-hook* del loader para capturar el output y construir
  el cache; no permite el *fast path* (los hooks no saltan el cuerpo de la función).

## Criterio de salida

- `hh_tick.log` en Windows con `d2=30/30` durante gameplay y sin stalls >40 ms en cargas.
- Cache reproducible (mismo checksum en dos pasadas) y validado contra `lzkn64.py` en todas las
  claves observadas; sin regresiones de contenido (módulos idénticos al original).

## Implementación v1 (2026-09-18)

- **Punto de intercepción**: el wrapper `hh_wrap_FUN_80003824` de `librecomp/src/overlays.cpp`
  (runtime local) cede a `hh_trans_load()` (port, `src/game/trans_cache.cpp`). Esto **sí** permite el
  *fast path* (la alternativa descartada arriba se refería a un hook que no controla el retorno; el
  wrapper de `get_function` puede decidir no invocar el loader original).
- **Firma real del loader**: `FUN_80003824(a0=src_rom_off, a1=dst, a2=size_comp)`, con `a3` sin uso;
  el header de 4 bytes del stream es el **tamaño comprimido** (límite del bucle), no el
  descomprimido. Devuelve `r2 = dst + out_len`.
- **Decoder nativo**: port fiel de `tools/lzkn64/lzkn64.py`; coincide con la ruta LZKN64 del loader
  original (`cmd<=0x7F` backref, `<=0x9F` raw, `<=0xDF` RLE, `<=0xFE` ceros, `0xFF` ceros largos).
- **Layout**: el cache guarda los bytes tal y como quedan en la RDRAM host (word-swapped del port);
  es posición-independiente para destinos alineados a palabra -> `memcpy` directo en hit.
- **Efectos laterales**: `load_module_by_source` se sigue llamando; los contadores internos
  `0x8005D010-0x24` solo los usa el cluster del loader (verificado), no el juego.
- **Knobs**: `HH_TRANS_CACHE` (def on), `HH_TRANS_NATIVE` (def on), `HH_TRANS_VERIFY`, `HH_TRANS_DUMP`.
- **Validación**: comparación nativo vs original (`HH_TRANS_VERIFY`) en 11 cargas de boot (0
  mismatches) y `tools/analysis/validate_trans_cache.py` (cache nativo == cache del original ==
  Python).
- **Pendiente**: validación del mantenedor en Windows (puerta/CaC); decidir default de
  `HH_TRANS_NATIVE`; extractor offline opcional.
