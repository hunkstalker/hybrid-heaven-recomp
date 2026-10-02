# 2026-10-02 — Fix: los textos (nombres de habilidades) desaparecían al GUARDAR partida

> Bug reportado por el mantenedor. **Corregido y VALIDADO en Windows (2026-10-02)**. No tiene relación
> con el fix del recompilador (jump tables) ni con MODO HEAVEN. Distinción **medido** / **inferido**
> explícita.

## Síntoma (medido)

Al **guardar partida** en la cápsula, **desaparecen los nombres de las habilidades en todas partes**
(menú y combate). **No** es que se corrompa el guardado: al **cerrar el juego y cargar la misma
partida, los textos vuelven**. Ocurre **siempre** al guardar (no solo con MODO HEAVEN).

## Diagnóstico (medido)

1. **No hay corrupción de datos.** Traza `HH_SAVE_DUMP` (dump de la tabla de punteros de nombres
   `0x80184140`, la tabla de técnicas `0x80183CE0` + espejo, el índice de nombre y firmas de RDRAM)
   antes/después de cada paso del guardado (`pre-save_live`, `post-alloc`, `post-serialize`,
   `post-save`): **idénticos**. El nombre de la técnica 0 (`UPPER·R·PUNCH`) y su puntero siguen bien en
   RAM. La firma por bloques de RDRAM solo cambió en bloques de **módulos dinámicos** (`trans`), por el
   propio avance del juego entre volcados, no en la zona de nombres (`0x8018xxxx`).
2. **El `.pak` está bien**: al recargar partida, el juego reconstruye los textos.

## Causa (medido)

El compositor de texto nativo es `func_8001B204` y lo intercepta `hh_entry_register_hook`
(`src/hooks/sections.cpp`). Cuando la categoría **FILE-SELECT** está activa con el nativo oculto:

```cpp
hh::menu_overlay::file_select_text_skip()   // == !g_native_visible && g_file_select_active
```

el hook **salta la composición de TODO texto** salvo el de "clear" (el file-select se dibuja con
nuestra UI propia, así que el nativo se oculta saltando su compositor).

`hh_leave_capsule` (salida de la cápsula tras guardar) **no** desactivaba `g_file_select_active`. Al
guardar, esa categoría quedaba **colgada a `true`** con el nativo oculto → a partir de ahí el hook
saltaba la composición de **cualquier** texto (nombres de habilidades incluidos) → **desaparecen en
todas partes**.

Por qué volvían al recargar: las otras salidas **sí** resetean la categoría
(`hh_do_load_game:2049`, `hh_close_load_game:2001`, `hh_title_menu_hook:1846`), pero el reset de
`hh_title_menu_hook` **no corre en gameplay** (el guardado ocurre dentro de la partida, no en el menú
de título). Al recargar partida se pasa por `hh_do_load_game`/título → se resetea → textos de vuelta.

## Fix

En `hh_leave_capsule` (`src/hooks/sections.cpp`), tras la secuencia nativa de salida:

```cpp
hh::menu_overlay::set_file_select_active(false);
```

Igual que ya hacían `hh_do_load_game` y `hh_close_load_game`.

## Validación

- Compila (Linux) y **validado en Windows (2026-10-02)**: tras GUARDAR, los nombres de habilidades
  siguen visibles (menú y combate) sin recargar.

## Nota de diseño (para evitar reapariciones)

El ocultado del file-select es **global** (una sola bandera `g_file_select_active` + `g_native_visible`),
no por pantalla: el hook de composición no distingue de qué texto se trata. **Cualquier ruta que ponga
`g_file_select_active = true` debe garantizar que lo apaga al salir**. Las salidas que lo hacen hoy:
`hh_leave_capsule` (guardar), `hh_do_load_game` y `hh_close_load_game` (cargar), y `hh_title_menu_hook`
(al volver al título). Si en el futuro se añade otra ruta de entrada al file-select, revisar esto.

## Instrumentación usada (no versionada)

- `HH_SAVE_DUMP=1` en `save_live`: volcaba a `hh_savedump.log` las tablas de nombres/técnicas + firmas
  de RDRAM en cada paso del guardado. Se **retiró** tras el diagnóstico (era temporal).
- `run_windows_savedump.bat` + `tools/analysis/diff_savedump.py`: lanzador y comparador temporales.
- Medición: `notes/2026-09-28-logica-juego-tecnicas-items-y-stats.md` §1 (tablas de técnicas/nombres).
