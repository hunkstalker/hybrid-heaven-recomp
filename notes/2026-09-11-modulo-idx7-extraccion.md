# 2026-09-11 — Módulo de código Nisitenma idx 7: extracción + syms (Fase A #4)

> Evidencia de sesión. No editar.

## Extracción del blob (A4.1)
- Se volcó la RDRAM del port en el `jalr` fallido (`get_function(0x80107830)`) con gdb:
  `dump binary memory` desde `rdram + 0x107830`.
- El dump viene **word-swapped** (little-endian por palabra): hay que **bswap32** (pitfall clásico).
- Tras bswap: **564464 bytes (0x89CF0)**, **CRC32 `0xA9213032`** = `decompressed_crc32` del
  manifest. ✅ Blob exacto.
- Artefactos (gitignored, derivados de ROM): `work/scratch/module7.bin` (crudo),
  `work/scratch/module7_be.bin` (BE correcto), `work/scratch/module7_rom.bin` (BE con padding).

## Syms del módulo (A4.2)
- Detección de funciones con capstone: **prólogos `addiu sp,sp,-N`** + **destinos `jal` internos**
  → **752 funciones** (612 prólogos + 353 jal; 16.6% datos).
- `config/us_module7.syms.toml` (sección `.module7`, vram `0x80107830`, size `0x89CF0`).
- Validada con `validate_syms.py`: **OK** (sin delay-slot cortado ni ramas cruzadas).

## Recompilación del módulo (A4.3)
- `config/game_module7.toml` → `RecompiledFuncs_module7/` (16 `funcs_*.c`).
- N64Recomp exige que el entrypoint tenga **`rom == 0x1000`**; se resolvió con un "ROM" = 16 KB de
  padding + blob (sección `rom = 0x1000`). Genera C **sin errores duros** (exit 0).

## Hallazgo para B9 (integración)
- En el rango del módulo (`0x80107830..0x80191520`) la syms **plana** tiene **26 funciones** (Ghidra
  data-as-code) y **14 colisiones de nombre** con las del módulo.
- Al cargar el módulo en runtime, sus funciones deben **prevalecer** en esa base. Plan B9:
  1. Excluir del set plano las 26 funciones del rango (son datos en reposo; el módulo las ocupa).
  2. Compilar los `funcs_*.c` del módulo en un directorio aparte (`funcs.h`/`lookup.cpp`/`recomp_overlays.inl`
     colisionan → no compilar los del módulo).
  3. Registrar las funciones del módulo en `func_map` por `(origen, base)` (extender
     `register_flat_code`/`recomp_overlays.inl`), con la base determinista `0x80107830`.
  4. Verificar que `get_function(0x80107830)` resuelve y que el boot avanza.
- `docs/adr/0001` actualizado con este matiz.

## CORRECCIÓN (2026-09-11): extracción determinista con `lzkn64`
- Se probó `lzkn64` (shim del repo) sobre la entrada Nisitenma **idx 7** (ROM `0x4E69A8`, tamaño
  `0x55DD4`): descomprime a **564464 bytes, CRC32 `0xA9213032`** = exactamente el blob prístino.
- Por tanto, la afirmación previa de que "`lzkn64` da basura para este asset" era **ERRÓNEA**.
- **Nuevo `tools/setup_module.py`**: extrae el blob de la ROM con `lzkn64` (sin ejecutar el juego ni
  gdb), genera la syms del módulo (`gen_module_syms` + `validate_syms --fix`), el ROM combinado y la
  syms combinada, todo **determinista**. Luego `recomp.py --config game_combined.toml --build`.
- Nota: un dump desde RDRAM daría la sección de datos **modificada** en runtime (no determinista);
  la vía `lzkn64` evita eso.
