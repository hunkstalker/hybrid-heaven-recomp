# 2026-10-02 — Fix: el título del Área al cargar partida mostraba el Área equivocada

> Bug reportado por el mantenedor. **Corregido y VALIDADO en Windows (2026-10-02)**. Afecta al
> **nombre del Área** que publica el overlay propio al **cargar partida** (`publish_area_title`), no a la
> UI de carga. Distinción **medido** / **inferido** explícita.

## Síntoma (medido)

Al cargar una partida, la pantalla de transición muestra `AREA N` y el nombre del Área. El número
salía **equivocado según la parte de área**:

- cargar un slot de **1-1** → título del **Área 1** (correcto);
- cargar un slot de **1-2** → título del **Área 2** (incorrecto; debería ser Área 1);
- cargar un slot de **6-1** → salía el título del **Área 1** (incorrecto; debería ser Área 6).

Las áreas del juego son `Nx0` (número de área) + partes `N-P`; **todas las partes de un área comparten
el título del área** (2-1, 2-2, 2-3… → título del Área 2).

## Causa (medido)

`hh_area_title_hook` (`src/hooks/sections.cpp`) tomaba el número de Área así:

```cpp
const uint32_t idx = g_area_last_scene_idx;   // retorno de func_8013EA54
if (idx < 12u) t0 = rdram[0x801CCAE0 + idx];  // tabla D_801CCAE0
```

Pero **`func_8013EA54` no devuelve el número de área-1**: devuelve el campo `+6` del registro de fila
del file-select (`D_801BEB80[cursor]+6`), y ese campo es **`func_80108280() >> 8`** — un valor que
**avanza por PARTE** (índice de escena: 0, 2, 10, 20, 50…). Ver `func_80141268` (compositor de la fila,
`0x801412E8: sra $t6,$v0,8; ... 0x80141300: sb $t6,0x6($v1)`) y `func_8013EA54` (`RecompiledFuncs`).

La tabla `D_801CCAE0` (en `file_024`) es `[0..9] = 0,1,2,3,4,5,6,0,7,8,9` — 12 entradas que mapean
**índice de escena del `N-0` → área**. Indexarla con un valor de parte da un resultado sin sentido:
- 1-2 → `idx=2` → `D_801CCAE0[2]=2` → Área 2 (mal);
- 6-1 → `idx=50` → fuera de tabla (>12) → `t0=0` → no publica / cae a otro (Área 1).

## Fix (medido)

Derivar el área del **valor de escena vivo `[0x801BBBF0+4]`** (u16 BE), que es la fuente que ya usa
`save_live` para la cabecera del guardado y que **sí representa Área-Parte**:

```cpp
const uint16_t scene = (rdram[0x801BBBF4]<<8) | rdram[0x801BBBF5];
int area = 1, sub = 1;
hh::menu::area_sub_from_value(scene, area, sub);
const uint8_t t0 = area;
```

`area_sub_from_value` (`src/subsystems/menu.cpp`) reconoce cada punto de guardado
(`valor = (area-1)*10 + (sub-1)*2`) y, para valores no listados, usa `value/10 + 1` (que da el área
correcta para los `N-0`). `[0x801BBBF4]` está poblado antes del callback del título: lo escribe el
deserializador `func_80141D08` (llamado por `func_801423C8` en `hh_do_load_game`).

## Validación

- Compila (Linux) y **validado en Windows (2026-10-02)**: slots de distintas partes del mismo área
  muestran el mismo título de Área, y un área alta muestra su Área correcta.

## Referencias

- `notes/2026-10-01-titulo-area-carga.md` (título del Área; mecanismo y overlay).
- `notes/2026-10-01-titulo-area-calibracion.md` (calibración del texto).
- `src/hooks/sections.cpp` (`hh_area_title_hook`), `src/subsystems/menu.cpp` (`area_sub_from_value`).
- C recompilado: `func_8013EA54`, `func_80141268` (`RecompiledFuncs/funcs_56.c`).
