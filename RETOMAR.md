# RETOMAR — handoff (2026-09-28)

> Handoff para la próxima sesión. Rama de trabajo: **`menu-edicion-partida`** (nada pusheado; `main` =
> v0.5.0). Reglas: `AGENTS.md`.
>
> **Detalle de la sesión de hoy**: `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`.
> Modelo de stats (histórico, ya resuelto): `docs/stats-partes.md`.

## TAREA PENDIENTE PRINCIPAL — `MODO HEAVEN` (punto 6, a medias)

En **EXTRAS → `MODO HEAVEN NO/SÍ`** (ya colocado). Al poner **SÍ** aplica vía `hh::save` sobre el slot
del editor: **nivel de los 6 atributos = 99**, **todas las habilidades a SÍ**, **todos los items a 99**
(log `[heaven]`). **Falta:**

1. **Invulnerabilidad** — que el PJ reciba **daño 0 siempre**. Investigar dónde se aplica el daño al
   jugador (resolución de golpe; `func_8022F0E0` es la defensa/GUARD) y forzarlo a 0.
2. **Items que NO se gasten** — localizar la resta de cantidad al usar un item y anularla.
3. **Runtime vs save** — decidir si además debe escribir la struct viva `0x8017DC40` (efecto inmediato)
   y/o auto-GUARDAR.

El resto de la tarea 6 (niveles/habilidades/items) ya está implementado en `src/hooks/sections.cpp`
(handler `Action::ToggleHeavenMode`).

## PENDIENTE SECUNDARIO

- **Centrar los submenús `GRÁFICOS` y `CONTROLES`** (hoy no están centrados). Añadir sus `ScreenId` al
  grupo `custom_layout`/`is_save_edit` de `src/hooks/menu_overlay.cpp`.
- **Validar en Windows** todo el rediseño de esta sesión (sin validar): ATRIBUTOS/ESTADO, repeat de
  izq/der, ELIMINAR, ITEMS en mayúsculas, HABILIDADES `RESET`, MODO HEAVEN.
- **"Release limpio" (trazas fuera del release)**. El runtime tiene la macro `HH_DEBUG_TOOLS` (default 1,
  `lib/N64ModernRuntime/librecomp/src/recomp.cpp:26`) que envuelve toda la instrumentación; la idea es
  compilar el release con `-DHH_DEBUG_TOOLS=0`. **PERO hoy está ROTO**: con `=0` no compila — los
  símbolos `hh_diag_enabled` (`recomp.cpp:1149`) y `hh_guest_ra` (`recomp.cpp:1155`) se definen *dentro*
  del `#if HH_DEBUG_TOOLS` y los usan **siempre** `pi.cpp`, `overlays.cpp`, `ultramodern/src/threads.cpp`,
  `mesgqueue.cpp`, `scheduling.cpp` → *undefined reference*. **Arreglo**: mover esos símbolos (y el
  `hh_schedlog`/otros usados fuera) FUERA del `#if`, o dar stubs. Hecho eso: cablear
  `target_compile_definitions(librecomp PRIVATE "$<$<CONFIG:Release>:HH_DEBUG_TOOLS=0>")` en
  `CMakeLists.txt` y dejar las trazas en Debug/RelWithDebInfo (y que `run_stats_capture.bat` use Debug).
  Estado actual: la instrumentación se compila siempre pero está **env-gated** (`HH_TRACE`/`HH_CANARY`),
  así que el release está "limpio" en **comportamiento** (no escribe nada sin las env).

### Trazas en git (estado de esta sesión)

- El fork NMR **ya está pusheado** (`fork/hybrid-heaven` = `8e99cc4`, con la traza `[STATEXP]`/`[ROW]`).
- El repo principal **pinea `9b14604`** (sin trazas) en el gitlink + `runtime.lock`; el árbol local está
  limpio. Para trazar en desarrollo: `git -C lib/N64ModernRuntime checkout 8e99cc4`.
- Si se quiere el fork sin trazas: `git -C lib/N64ModernRuntime push --force-with-lease fork
  9b14604:hybrid-heaven` (y opcionalmente guardar `8e99cc4` como rama `trace-combate`).

## HECHO en esta sesión (resumen)

1. **Recompensa de EXP = fila del ENEMIGO** (no fija). `func_8022CAFC` elige en `0x8023C940` por
   `a0+0x36`; `func_80376D48` 1 vez/combate. Confirmado con `[STATEXP]`/`[ROW]` en 5 combates contra
   enemigos distintos. → el editor deja el **simulador de combates** y edita el **nivel del atributo**.
2. **Tope de nivel por dificultad**: `func_80376D10` → **79/89/99** (`*(0x801BBC0D)` = 0/1/≥2). Tope por
   atributo; el valor topa en 9999. Editor capa a 99.
3. **OFENSIVO/DEFENSIVO** (niveles de parte): suben +1 (guardar → `func_80232A80`, tope **65535**);
   efecto **multiplicativo** en daño (`func_8022DB40`) y defensa (`func_8022F0E0`). Editor cap 99.
4. **Repeat de izq/der arreglado**: el input mantenido está en `0x80089476 | 0x8008947E`
   (funciones `0x801C1340`/`1334` devolvían **flancos**, no el mantenido).
5. **Rediseño de menús**: raíz `CARGAR/GUARDAR/ELIMINAR/RESTAURAR` + `PROGRESO/NIVEL` + `ATRIBUTOS/
   ESTADO/HABILIDADES/ITEMS`; **ATRIBUTOS** = niveles de atributo editables (`< NIVEL n >`) + `TODOS` +
   valor (sin MAX HP ni EXP) con columnas alineadas; **ESTADO** = `TIPO` OFENSIVO/DEFENSIVO + `TODOS` +
   6 partes; **ELIMINAR** = `hh::save::delete_slot()`; **ITEMS** en MAYÚSCULAS; **HABILIDADES** `RESET`.

## Estado del editor (acumulado)

- Editor sobre el **slot del `.pak`** (cabecera `0x100` + 4 slots `0xD00`; checksum `+0xCFC`). Bloque
  de personaje **32-bit word-swapped** (`swap16=r^2`, `swap8=r^3`). `save()` recalcula checksums,
  actualiza la cabecera de la lista de partidas y llama a `hh_pak_reload_from_disk()` (fork NMR local).
- **NIVEL global** = media+1 de los 6 niveles de atributo (`func_8037865C`); **derivado**, solo lectura.
- Sub-niveles de atributo (6) en `+0x04/+0x0A/+0x52/+0x53/+0x55/+0x54`; progreso en
  `+0x06/+0x0C/+0x4A/+0x4C/+0x4E/+0x50`; tablas incremento/umbral en `0x80388410+…` (99 entradas).
  `add_part_levels()` aplica `incremento[nivel]` (+HPmáx en la parte 0).
- Niveles de **parte del cuerpo** en `+0x10` (ofensivo) / `+0x1C` (defensivo), u16.

## Cómo trabajar (rápido)

- Build Linux: `cmake --build build/linux --parallel $(nproc)`.
- Build Windows: `rmdir /s /q hybrid-heaven-recomp\build\windows` + `hybrid-heaven-recomp\build_windows_release.bat`.
- Capturas de combate: `hybrid-heaven-recomp\run_stats_capture.bat combat` (`hh_trace.log`).
- Regenerar C recompilado: `python3 tools/regenerate.py` (no se versiona; ADR 0009/0011). Tras regenerar:
  `python3 tools/analysis/fix_fallthroughs.py`.
- Docs: `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`; `--check` valida).

## Git / forks

- Rama **`menu-edicion-partida`**; **nada pusheado**. Commitear **solo lo validado o docs, y con
  permiso**. El editor usa `hh_pak_reload_from_disk` del fork NMR local. El mantenedor pidió **no
  pushear** de momento.

> **Calibración (AGENTS)**: distinguir "medido" de "inferido"; no concluir comportamiento de ejecución
> sin evidencia (oráculo/Windows); no inventar fórmulas.
