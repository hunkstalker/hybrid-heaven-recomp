# RETOMAR — handoff (2026-09-28)

> Handoff para la próxima sesión. Rama de trabajo: **`menu-edicion-partida`** (nada pusheado; `main` =
> v0.5.0). Reglas: `AGENTS.md`.
>
> **Detalle de la sesión de hoy**: `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`.
> Modelo de stats (histórico, ya resuelto): `docs/stats-partes.md`.

## `MODO HEAVEN` — modo GLOBAL, implementado, PENDIENTE DE VALIDAR (Windows)

En **EXTRAS → `MODO HEAVEN NO/SÍ`**. Es un **modo global de juego, independiente de la partida** y del
editor de saves; **persiste** en `config.ini [extras].heaven` (como MANTENER EXTRAS). Al poner **SÍ**:

1. **Al cargar/empezar cualquier partida** (hooks post-original de `func_80144E68`, que deserializa el
   personaje, y de `func_80152240`, que monta las tablas de runtime) se llama a
   `hh::save::apply_heaven_runtime(rdram)`, que lleva el **personaje vivo `0x8017DC40`** al máximo:
   - **ATRIBUTOS**: los 6 niveles de parte a **99**, aplicando las tablas REALES de incremento a su
     stat (y a HP máx en la parte 0) y recalculando el NIVEL global.
   - **ESTADO**: OFENSIVO/DEFENSIVO por parte a **99**.
   - **HABILIDADES**: las 86 técnicas marcadas como aprendidas (`0x80183CE0` + espejo).
   El save del juego serializa ese mismo struct (`func_80144C40`), así que el estado **se persiste** al
   guardar (y un save hecho con HEAVEN ON conserva niveles/items aunque luego se apague).
2. **En runtime** (gated por `hh::menu::heaven_enabled()`):
   - **Invulnerabilidad**: `func_80232D08` es la **única** función que resta el daño resuelto de las
     partes del cuerpo (`a0+0x2B8+part*2`). `hh_heaven_damage_hook` pone `a1=0` cuando el ente dañado
     (`a0`) es la **partida del jugador** (`0x801BC03C`).
   - **Items que no se gastan**: `func_8013D520` suma/resta la cantidad de un item (u8, tope 99); con
     delta negativo = consumo. `hh_heaven_item_hook` pone `a1=0` si el delta es negativo. (Los items
     **no** se fuerzan a 99: acumulan con normalidad y se guardan; simplemente no bajan al usarlos.)
   - **Ventaja/back attack** `[VALIDADO funcionalmente]`: `hh_battle_frame_hook` fuerza `0x801BCC24`
     (`0x801BBBF0+0x1034`) a 2 → los combates empiezan con el POWER al máximo. Ver sección propia.
   - **Daño fuera de combate (robots)** `[PENDIENTE]`: ver sección propia; el daño de combate ya es 0.

**Decisiones**:
- **Independiente del editor**: `ToggleHeavenMode` ya **no toca el `.pak`/slot**; `EDICIÓN DE PARTIDA`
  vuelve a ser solo editor.
- **Persistencia**: `[extras].heaven = si/no`. Con HEAVEN ON, `extras_unlocked()` también da EXTRAS
  visible (aunque MANTENER EXTRAS sea NO) para poder apagarlo.
- **Auto-GUARDAR**: no; sigue siendo explícito.

> **[MEDIDO del C recompilado]**: `0x8017DC40` es el struct del personaje (lo deserializa
> `func_80144E68`, lo serializa `func_80144C40` y lo leen `func_80378D84/E3C`). **[A VALIDAR]**: que el
> orden de hooks cubra CONTINUE y partida nueva, y los efectos en ejecución (máx + daño 0 + items que
> no bajan). Si en partida nueva no pasara por esos hooks, añadir su hook puntual.

## HECHO (validado funcionalmente): SORPRESA/ventaja de combate ("back attack")

Objetivo del mantenedor: que **todos los combates empiecen sorprendiendo al enemigo** (como entrar por
la espalda), siempre, y dentro de MODO HEAVEN. La sorpresa es un **evento puntual de ANTES del combate**,
así que no vale con fotos periódicas: la instrumentación registra **cambios** (event-driven) con **F12**
(`run_battle_trace.bat` + `hh::battle_trace_toggle` en `src/subsystems/input.cpp`).

**Flag medido** (traza diferencial normal vs por la espalda; nombre interno del juego `gw.back_attack`):
- El byte **`0x801BBBF0+0x1034`** (dirección `0x801BCC24`) pasa a **2** solo en el combate con ventaja,
  a `vi≈8315` (antes del setup). El `+0x1032=1` del setup normal sale en ambos combates.
- Lo escriben `func_8021D8D0` (transición de batalla) y `func_801F5F5C` (copia `a0+0xAF`), así que se
  **fuerza por-frame** en `hh_battle_frame_hook` bajo `heaven_enabled()` (si el byte está en 0/1 → 2).
- **Validado por el mantenedor (2026-09-28)**: con HEAVEN ON la pelea empieza con el **POWER al máximo
  desde el inicio** (no hace falta que salga la palabra "ADVANTAGE" en pantalla).

> **OJO (bug corregido)**: la primera versión forzaba `+0x1037` por un `bswap` de más en la
> decodificación de la traza; el byte correcto es `+0x1034`. El `bswap` ya está quitado del watcher
> (`hh_battle_frame_hook`).

## PENDIENTE: daño FUERA de combate (robots)

Dentro de combate el daño al PJ ya es 0 (hook `func_80232D08`). **Fuera de combate**, si un robot
dispara, la vida **sí baja**; falta anularlo. Estado de la investigación:

- **MEDIDO por traza F12**: al recibir el disparo cambia el **sheet `0x8017DC40+0x02`** (la misma vida
  que STATUS/combate), p. ej. `0x1847→0x183D` (daño 10). No es la party de combate (`0x801BC03C`) ni el
  "struct vivo" `*(0x801BBCCC)` (en la traza `live_ptr=0x8024AD14`, cuyos cambios son punteros de
  actualización, no vida).
- **Falló**: reescribir HP/HPmax a 9999 por-frame (solo maquilla el display; el juego pisa el valor y
  el daño real sigue). **Se retiró** ese top-up.
- **Siguiente paso**: localizar la **función que escribe** esa vida en el campo. El escritor no aparece
  como `sb`/`sh` directo con base `0x8017DC40` (puede ser copia de bloque o vía puntero). Opciones:
  1. `run_stats_capture.bat stats` (`HH_CANARY=0x8017DC40:9E`) mientras te dispara un robot →
     `hh_canary.log` da el cambio + la ventana de llamadas.
  2. Hook al proyectil/impacto del robot (buscarlo en el módulo de campo `file_008`).
- **Valor esperado**: dejar el daño de campo a **0** con `heaven_enabled()` (mismo patrón que el combate),
  no maquillar el display.

## Traza de combate (herramienta, ya usada)

`run_battle_trace.bat` + F12 registran cambios de las zonas vigiladas en `hh_battle_watch_<n>.log`
(`vi addr old->new`, valores guest **sin bswap**): objetos de campo `0x801B5520` (16×0xD8), bloque de
batalla `0x801BBBF0` (0x2000), sheet `0x8017DC40`, party `0x801BC03C`/`0x801BC3D8`, bytes de estado
`0x801BCC20` (todas las transiciones) y el struct vivo `*(0x801BBCCC)`. `hh.log` anota los cambios de
pantalla (`func_800058DC`) y el `live_ptr`. Análisis: `tools/analysis/diff_battle_watch.py`.

## PENDIENTE SECUNDARIO

- **Centrar los submenús `GRÁFICOS` y `CONTROLES`** — HECHO: `ScreenId::Graphics` añadido a
  `custom_layout` (`src/hooks/menu_overlay.cpp`); CONTROLES y GRÁFICOS se centran y `scroll_cap5`
  (ventana de 5 filas) solo aplica a EXTRAS/CONTROLES/editor, así GRÁFICOS conserva sus 6 filas.
  Añadido un tope de `x_shift` para que bindings largos no saquen el contenido de `kVirtualWidth`.
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
6. **MODO HEAVEN (segunda pasada)**: modo **global persistente** (`config.ini [extras].heaven`):
   máxima el personaje vivo al cargar (`func_80144E68`/`func_80152240` → `apply_heaven_runtime`) +
   invulnerabilidad (`func_80232D08`) + items no consumibles (`func_8013D520`); el editor deja de
   tocarlo. **GRÁFICOS** centrado. Compila en Linux; **sin validar en Windows**.

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
