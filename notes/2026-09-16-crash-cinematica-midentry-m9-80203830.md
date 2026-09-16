# 2026-09-16 — Crash al cruzar una puerta (cinemática): mid-entry `M9_FUN_80203830` (módulo 9)

## Síntoma

Al cruzar una **puerta que lanza una cinemática** (transición juego → menú):

```
[PAD] contexto: juego
[PAD] contexto: menu
Failed to find function at 0x80203830
(exit -1073740791)
```

`0xC0000409` (abort) = el runtime sale al no encontrar la función en su tabla
(`get_function` → `hh_missing.log`): el juego la llamó **por puntero**.

## Diagnóstico

- `add_mid_entry.py 0x80203830` → **módulo idx 9** (base `0x801E4AA0`); no es delay slot; no cae en
  switch fusionado.
- Contenedor: `M9_FUN_8020382c` (vram `0x8020382C`, size `0x120`). El destino está **+4** de su inicio.
- En el C generado, `0x8020382C` es un **`nop`**: es el **delay slot** del `jr $ra` de la función
  anterior (`0x80203824`/`0x80203828`) mal asignado como inicio de símbolo. La función real empieza en
  `0x80203830` (`sw $a1, 0x94($a0)`), que es lo que el juego llama.
- La cadena `@fallthrough-fix` que la función anterior tiene hacia `M9_FUN_8020382c` queda **después de
  su `return;`** = código muerto (inofensivo).

## Fix

```sh
python3 tools/analysis/add_mid_entry.py 0x80203830
python3 tools/recomp.py --config config/game_combined.toml --force
sh tools/build_linux.sh --build-dir build_dbg
```

Split: `M9_FUN_8020382c` → `0x4` (nop) + `M9_FUN_80203830` (`0x11C`, encaja con `M9_FUN_8020394c`).
Registrado en `funcs.h`, `funcs_92.c` y `recomp_overlays.inl` (`offset 0x1ED90`, `rom_size 0x11C`).

## INCIDENTE: la primera regeneración revirtió el fix del cuelgue del NPC

`add_mid_entry.py` recalculaba **todos** los tamaños del módulo como "hueco hasta el siguiente
símbolo" (`split_fichero`). Eso borró estados deliberados en silencio:

- `M9_FUN_802169ac`: `0x1C0` → **`0x4604`** (arrastraba datos) → el recompilador lo dejó en **stub
  `do_break`** = regresión exacta del cuelgue del NPC (commit `45b05b5`). El override vivía en
  `module_extras.json[9]` (`"0x802169AC:0x1C0"`) pero el recálculo lo **ignoraba**.
- En `us_combined.syms.toml` (el que usa el recompilador): `M9_FUN_801fd4f4` `0xC8`→`0x68`,
  `M9_FUN_801fd574` `0x24`→`0x48`, y desaparecía el comentario
  `# [validate_syms] M9_FUN_801fd598 fusionada (split incorrecto)`.
- Detectado comparando **función por función** HEAD vs árbol de trabajo: `M9_FUN_802169ac`
  11061→113 líneas (`do_break`), `M9_FUN_801fd4f4` 5351→2905, `M9_FUN_801fd574` 1256→2059.

### Corrección

- `tools/analysis/add_mid_entry.py::split_fichero` → **edición mínima**: solo reescribe la entrada
  contenedora e inserta la nueva; conserva el resto de líneas/comentarios y **aplica los overrides
  `0xADDR:0xSIZE`** de `module_extras.json`.
- Nuevo guardián **`tools/analysis/check_syms_overrides.py`**: verifica que cada override sigue
  presente (con su tamaño) en `us_moduleN.syms.toml` y `us_combined.syms.toml`. **Conectado en
  `tools/recomp.py` (paso 1b)**: si se pierde un override, **aborta** la regeneración.
- Se revirtió todo (`git checkout -- config/... RecompiledFuncs`) y se reaplicó el mid-entry con la
  herramienta corregida.

## Validación

- Diff de syms **quirúrgico**: solo el split; `0x802169AC` sigue en `0x1C0` (override respetado).
- `M9_FUN_802169ac` recompila **código real** (`addiu $sp, $sp, -0x68`), no `do_break` ✓.
- Comparación función por función vs HEAD: solo **+`M9_FUN_80203830`** y `M9_FUN_8020382c` (157→6
  líneas); todo lo demás idéntico.
- `recomp --force` **idempotente** (mismo md5 del conjunto de `funcs_*.c`); build Linux OK.
- Guardián probado en positivo y **negativo** (rc=1 con el override roto).

## Pendiente

- **Usuario en Windows**: cruzar la puerta/cinemática y seguir la partida (próximo hito probable:
  primer combate cuerpo a cuerpo). Si sale `Failed to find function at 0x...`, misma vía.
