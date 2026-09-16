# 2026-09-16 — Crash pocos segundos después de iniciar combate: `M55_FUN_8037948C`

Segundo bug de gameplay de la ronda: tras arreglar el arranque del combate, a los pocos segundos cae
con:

```
Failed to find function at 0x8037948C
```

## Diagnóstico

- `add_mid_entry.py 0x8037948C` → **módulo idx 55** (base `0x803757E0`); no delay slot; no switch
  fusionado.
- `0x8037948C` cae dentro de `M55_FUN_80379464` (vram `0x80379464`, size `0x34`). Desensamblando el
  blob (`work/scratch/module55_be.bin`):

  ```
  0x80379480: jal  ...
  0x80379484: lw   a0, 0x58(sp)   (delay)
  0x80379488: lw   ra, 0x14(sp)
  0x8037948C: addiu sp, sp, 0x58   <- epílogo compartido
  0x80379490: jr   ra
  0x80379494: nop
  0x80379498: ...                  (M55_FUN_80379498)
  ```

  Es decir, `0x8037948C` es el **epílogo compartido** (`sp += 0x58; jr ra`).
- Tres funciones previas terminan con `b 0x8037948C` (`0x8037941C`, `0x8037943C`, `0x8037945C`). En
  el C recompilado esas ramas cruzaban frontera de función y se emitían como
  `LOOKUP_FUNC(0x8037948C)`; al no haber símbolo en esa dirección, el runtime abortaba.

## Fix

`python3 tools/analysis/add_mid_entry.py 0x8037948C` (edición mínima + overrides):

- `us_module55.syms.toml` y `us_combined.syms.toml`: `M55_FUN_80379464` `0x34` → `0x28` y nuevo
  `M55_FUN_8037948c` (`0x8037948C`, size `0xC`).
- `keep_syms.txt` y `module_extras.json[55]` actualizados.
- `python3 tools/recomp.py --config config/game_combined.toml --force` (validador + `N64Recomp` +
  `fix_fallthroughs`): la nueva entrada aparece en `recomp_overlays.inl` y `funcs.h`.
- Build Linux (`build_dbg`): OK.

Detalle de la vía (por qué mid-entry y no `setup_module.py`): ver
`notes/2026-09-16-crash-cinematica-midentry-m9-80203830.md`.

## Pendiente

- Validar en Windows: iniciar combate y aguantar; no debe repetirse el `Failed to find function`.
