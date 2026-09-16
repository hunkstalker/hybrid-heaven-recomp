# 2026-09-14 — Fix de fallthroughs entre módulos con base compartida y avance de cutscenes

**Objetivo**: resolver el crash tras GAME START (`M25_FUN_801e2cac`) y seguir hacia gameplay.

## Causa raíz: `fix_fallthroughs.py` mezclaba secciones con la misma base

- Los módulos **23 y 24 comparten base de VRAM** (`0x801BF1A0`): la misma dirección existe en
  ambos con funciones distintas (`M23_FUN_801cc2cc` y `M24_FUN_801cc2cc`).
- `fix_fallthroughs.py` construía `addr -> nombre` con `setdefault`: al colisionar, se quedaba con
  una sola entrada. Resultado: `M24_FUN_801cc2c8` (1 instrucción: `lui $at,0x801E`) encadenaba su
  fallthrough a **`M24_FUN_801cc30c`** en vez de `M24_FUN_801cc2cc`, **saltándose el cuerpo real**
  (que escribe `[0x801DAB14]=$a0`, `[0x801DAB18]=$a1` y registra el objeto).
- Consecuencia: el global `0x801DAB14` quedaba con valor inválido (`0x80000000`) y
  `M25_FUN_801e2cac` (`lw $t7,0x8($t6)`) leía fuera de RDRAM → SEGV.

**Fix** (`tools/analysis/fix_fallthroughs.py`): `build_addr_map()` devuelve **pares (vram, nombre)
sin deduplicar**; la resolución se hace por prefijo de sección (`M23_`/`M24_`/plana). Se elimina el
mapa desde `recomp_overlays.inl` (sus offsets son relativos a la sección de cada módulo, no
absolutos). Cadena correcta verificada: `M24_FUN_801cc2c8 → M24_FUN_801cc2cc`.

## Miss de cola por split de módulo: `0x801E4AA4`

- Añadido `0x801E4AA0` como extra de módulo 25 dividió el entorno de desarrollo; su `b 0x801E4AA4` (epílogo
  compartido: `lw $ra,0x1C($sp); addiu $sp; jr $ra`) pasó a ser un `LOOKUP_FUNC(0x801E4AA4)` →
  miss. Con `HH_SOFT_LOOKUP=1` el stub no restauraba `$ra`/`$sp` → corrupción de pila → SEGV en
  `M24_FUN_801c0464`.
- Fix: `0x801E4AA4` añadido a `config/module_extras.json` (módulo 25) y recompilado.

## Resultado

- Runs de **250-300 s sin SEGV, 0 símbolos faltantes** (antes: SEGV ~1 min tras GAME START).
- El juego encadena **cutscenes 3D in-engine con retratos y personajes**:
  `work/debug/port_ftfix2_*.png` (consola con retrato) y `work/debug/port_dial_*.png`
  (dos hombres de negro + personaje rubio en una sala).
- Evidencia: `run_ftfix2.log`, `run_dial.log`.

## Frontera

- Confirmar **gameplay interactivo** (control del personaje/HUD): en curso un run largo avanzando
  diálogos (`work/debug/run_long_advance.sh` → `port_long_*.png`).
- El crash de teardown (apagado) y el callback `M24_FUN_801cb71c` con menú sin input siguen
  pendientes (ver `TODO.md` #10/#14).
