# CaC B1 confirmado — el callback del objeto es `0x801C1EE0` (función de módulo 23) y lo resuelve el módulo equivocado

> Evidencia directa del bug de propiedad de `func_map`. Fecha: 2026-09-17.
> Traza: `work/debug/cac/20260917_1146_windows_replay/hh_trace.log` (pasada de grabación con
> `HH_TRACE_RANGE=0x801BF1A0:0x9000`, que alcanza el combate y congela).

## 1. Secuencia en combate (t=254.867, `mode=0004`, tid=5)

```
disp         0x80005270
RANGE+58BC   0x801C4A5C  a0=8024BB24 a1=0
RANGE+2D40   0x801C1EE0  a0=8024BB24 a1=8008DA88      <-- ¡get_function(0x801C1EE0)!
setter       0x800058DC  a0=8024BB24 a1=801C1F40      <-- escribe +0x1C = 0x801C1F40
RANGE+58BC   0x801C4A5C  a0=8024BB24 a1=1
RANGE+86DC   0x801C787C ...   (sigue la cadena de módulo 23)
```

- El objeto **`0x8024BB24`** tiene **`+0x1C = 0x801C1EE0`** (puntero a código de módulo 23,
  `base 0x801BF1A0 + 0x2D40`). El `disp` lo llama como callback (`host_ret=exe+0x503BF`, el mismo
  sitio que reporta `Failed to find function at 0xFF7F84CD`).
- Después, el `setter` (`FUN_800058DC`) escribe `+0x1C = 0x801C1F40` (otra función de módulo 23).
  Es decir, **módulo 23 arma la cadena de callbacks con sus propias direcciones**.
- Las 4 llamadas a `0x801C1EE0` en la traza son este mismo patrón (objeto en `a0`, `mode=0004`).

## 2. Quién posee `0x801C1EE0` en el port

- `0x801C1EE0` = `0x801BF1A0 + 0x2D40` es **interior a `M23_FUN_801c1dc0`** (offset 0x2C20,
  tamaño 0x290): Ghidra **fusionó** la función real que empieza en `0x801C1EE0`. → La sección de
  módulo 23 **NO tiene símbolo** en esa dirección, así que al cargarse no registra nada allí.
- En cambio `M8_FUN_801c1ee0` (sección con `rom=0x07000000`, **índice de tabla 7**) sí tiene una
  entrada en offset `0x2D40` y se carga en la **misma base `0x801BF1A0`**.
- Verificado en ejecución (Linux, instrumentación `HH_FUNC_OWNER`):
  ```
  [OWNER] load section=3 addr=801C1DC0 func=...   (módulo 23)
  [OWNER] load section=3 addr=801C40F8 func=...   (módulo 23)
  [OWNER] load section=7 addr=801C1EE0 func=...   (¡la sección de M8!)
  ```
  → Cuando el `disp` resuelve el callback `0x801C1EE0`, ejecuta **código del módulo equivocado**
  (sección 7) en vez de la función de módulo 23 → cadena de callbacks divergente → corrupción
  (`0xFFFF84CD` → `0xFF7F84CD`) y cuelgue.

## 3. Fix propuesto (B1)

1. **Añadir el símbolo real de módulo 23 en `0x801C1EE0`** (partir `M23_FUN_801c1dc0` en 0x2D40):
   `python3 tools/analysis/add_mid_entry.py 0x801C1EE0` + `tools/recomp.py --config
   config/game_combined.toml --force` (¡ojo con los overrides existentes, ver guardián!).
2. **Limpiar el rango al cargar sección**: al cargar una sección en `ram`, borrar `func_map` en
   `[ram, ram+size)` antes de registrar (y registrar la base activa). Así el módulo residente posee
   *todo* su rango y no hay entradas rancias de otro módulo que comparta base. (La v2 del plan §3
   solo hizo esto y no cambió nada porque, sin el símbolo del punto 1, `0x801C1EE0` quedaba sin
   resolver → no-op; con 1+2 debe resolver a código de módulo 23.)
3. Validar con el **replay de Windows** (`run_replay.bat`, ya fiel: 0 discrepancias, reproduce el
   freeze) y, si va bien, re-test en el juego real.

## 4. Nota sobre el replay en Linux

- El replay es **fiel en la misma plataforma** (Windows: 8843 muestras aplicadas, 0 discrepancias,
  reproduce el CaC). En Linux **diverge**: el arranque/ritmo hace que el input (por poll/VI) caiga en
  estados distintos y la partida no llega al combate. Para B1 **no hace falta**: la traza de Windows
  da la evidencia directa. (Si se quisiera fidelidad cross-platform habría que re-grabar con una
  clave de estado/tick de lógica, no por VI/poll.)
