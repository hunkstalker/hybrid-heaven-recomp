# 2026-09-11 — B9: integración del módulo idx 7 (resuelto)

> Evidencia de sesión. No editar.

## Enfoque (funcionó): fusionar el módulo como **segunda sección**
- `config/us_combined.syms.toml`: sección `.text` (plana, rom 0x1000, vram 0x80000400) + sección
  `.module7` (rom 0x1000000, vram 0x80107830). Se **excluyen** de `.text` las funciones del rango
  del módulo (data-as-code de Ghidra; 26).
- `work/scratch/us_combined.z64` = ROM retail + blob del módulo (BE) en 0x1000000.
- `config/game_combined.toml` → un único set (`RecompiledFuncs_combined/`), una `funcs.h`,
  una `recomp_overlays.inl` con **2 secciones**. `register_flat_code()` registra `FUN_80107830` en su
  base → **`get_function(0x80107830)` resuelve**. ✅
- Evita las colisiones de ficheros/nombres de compilar dos sets por separado.

## Iteraciones de símbolos (el boot revela huecos al avanzar)
- **Módulo**: el detector prólogo+jal omitía funciones sin prólogo (p. ej. `0x80126744`) → se añadió
  **`tools/analysis/gen_module_syms.py`** (también marca la dirección tras cada `jr $ra`) y
  `validate_syms.py --fix` (fusiona over-splits). Resultado: 1005 funciones de módulo válidas.
- **Planas**: `0x80020078` (size 0x38) y `0x80020460` (size 0x13C, absorbida por `FUN_800203c4`)
  faltaban en la syms de Ghidra → añadidas/split incremental.
- **Nota**: aplicar el detector `post-jr-ra` a **toda** la syms plana (858→1243) + `--fix` produce
  una syms que valida OK, **pero N64Recomp falla** (`Error recompiling FUN_800493b8`). La vía
  segura es incremental o una re-analizada Ghidra más fina.

## Resultado
El boot **supera el bloqueante del módulo** y alcanza la **submission de tareas RSP**:
- `No registered RSP ucode for 2` → **task type 2 = audio** (sin ucode; bloqueante conocido).
- `Failed to find function at 0x80004310` (otra función plana omitida).

## Estado de ficheros
- Activo: `config/game_combined.toml` + `config/us_combined.syms.toml` + `work/scratch/us_combined.z64`.
- `us_module7.syms.toml` (1005 funcs) y `work/scratch/module7_be.bin` (CRC OK).
- El pipeline `tools/recomp.py` por defecto usa `game_unified.toml` (plano) → **pendiente** hacer
  `game_combined.toml` el activo y **reproducible** (script para blob+merge; hoy son artefactos en `work/`).

## A1 — tarea RSP de audio como no-op (2026-09-11)
- `task_thread_func` (`ultramodern/src/events.cpp`) **abortaba** si `rsp::run_task` fallaba (audio,
  `M_AUDTASK` = type 2, sin ucode registrado).
- Cambiado: no aborta; registra el tipo una vez y completa la tarea (`sp_complete`) como **no-op**
  (audio dummy). El boot **supera la submission de audio** y avanza.
- Siguiente bloqueante: símbolos planos omitidos (`0x803839A0`; antes `0x80004310`) → A2.
- Correcciones incrementales al set plano ya aplicadas: `0x80020078`, `0x80020460`, `0x80004310`
  (todas funciones reales absorbidas por la anterior; patrón `jr $ra` + nueva función sin prólogo).
