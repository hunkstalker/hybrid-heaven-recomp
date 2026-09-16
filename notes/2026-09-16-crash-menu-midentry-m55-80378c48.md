# 2026-09-16 — Crash en menú: mid-entry `M55_FUN_80378c48` (módulo 55)

## Síntoma

En una partida avanzada, al entrar en un **menú**:

```
[PAD] contexto: menu
Failed to find function at 0x80378C48
(exit -1073740791)
```

`exit -1073740791` = `0xC0000409` (abort): el runtime sale al no encontrar la función en su tabla
(`get_function` → `hh_missing.log`). Es el flujo conocido: el juego llama por puntero a un
**punto intermedio** de un símbolo mal acotado.

## Diagnóstico

`0x80378C48` cae dentro de `M55_FUN_80378bb0` (vram `0x80378BB0`, size `0x128`), pero el hueco hasta
el símbolo siguiente (`M55_FUN_80378cd8`, `0x80378CD8`) es **exactamente `0x90`** →
`0x80378C48` era una **frontera real de función** (callback/descriptor) que el símbolo contenedor
se tragaba. Módulo 55 = overlay de la secuencia de objeto/NPC (ADR/architecture §2.2).

## Fix

```sh
python3 tools/analysis/add_mid_entry.py 0x80378C48          # verifica: no delay slot, no switch
python3 tools/recomp.py --config config/game_combined.toml --force
sh tools/build_linux.sh --build-dir build_dbg              # validacion
```

- Split resultante: `M55_FUN_80378bb0` → `0x98` + `M55_FUN_80378c48` (`0x90`), encajando con
  `0x80378CD8`. Registrado en `funcs.h`, `funcs_106.c` y `recomp_overlays.inl`
  (`offset 0x3468`, `rom_size 0x90`).
- Recomp: 111 `funcs_*.c` copiados, `fix_fallthroughs` (2364 cadenas) OK; **11 ficheros** cambiados
  (M55: `funcs_106..110`, `funcs.h`, `recomp_overlays.inl`, `us_module55/us_combined.syms.toml`,
  `keep_syms.txt`, `module_extras.json`) — el resto del C generado salió idéntico.
- `[Warn] Stubbing M55_FUN_803899c8/cc (INVALID)` es **preexistente** (no afecta).

## Validación

- Build Linux OK (enlace correcto).
- **Usuario en Windows: "éxito rotundo"**, sigue avanzando en la partida.

## Extra: residuo `port/petardeo)`

Reaparecía un fichero `port/petardeo)` de 62 B. Causa: en `build_windows.bat` había
`echo ... buffers -> petardeo)`, y en batch el `>` es **redirección** → creaba el fichero con el
texto del `echo`. Corregido el `echo` (y un `->` en un `REM` por si acaso); residuo borrado.

## Pendiente

- Siguiente hito del usuario: **primer combate cuerpo a cuerpo (CaC)**; si sale
  `Failed to find function at 0x...`, misma vía (`add_mid_entry.py` + `recomp --force`).
