# RETOMAR — handoff (2026-09-28)

> Handoff para la próxima sesión. Rama de trabajo: **`menu-edicion-partida`** (nada pusheado; `main` =
> v0.5.0). Reglas: `AGENTS.md`.
>
> **Detalle de la sesión de hoy**: `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`.
> Modelo de stats (histórico, ya resuelto): `docs/stats-partes.md`.

## `MODO HEAVEN` — modo GLOBAL (validado en Windows)

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
    - **PODER/RESISTENCIA infinitos** `[VALIDADO en Windows]`: `hh_battle_frame_hook` pinnea ambos
      gauges a su max cada frame → no se gastan. Ver sección propia. **NO incluye VENTAJA**: con el
      PODER infinito la ventaja es redundante, así que HEAVEN no la fuerza (solo su propio toggle).
    - **Daño fuera de combate (robots)** `[VALIDADO en Windows]`: `hh_heaven_field_damage_hook`
      anula el daño de campo. Ver sección propia.

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

## `VENTAJA` — toggle propio en EXTRAS (independiente de MODO HEAVEN) `[VALIDADO]`

En **EXTRAS → `VENTAJA NO/SÍ`**. Da la **ventaja de combate ("back attack")**: `hh_battle_frame_hook`
fuerza el byte `0x801BCC24` (`0x801BBBF0+0x1034`) a 2 → los combates empiezan con el POWER al máximo.

- **Independiente de HEAVEN**: se aplica **solo** si `advantage_enabled()` (`hh_battle_frame_hook`).
  Antes HEAVEN también la forzaba, pero se **retiró**: con PODER ∞ (que HEAVEN incluye) la ventaja es
  redundante, así no se pisan.
- **Validado por el mantenedor (2026-09-28)**: contra un enemigo que **no** sale sorprendido, con
  VENTAJA ON el POWER empieza al máximo; con OFF, no. (La validación previa estaba confundida porque
  cierto enemigo entraba siempre por sorpresa.)
- **Persistencia**: `config.ini [extras].advantage = si/no`. `extras_unlocked()` también da EXTRAS
  visible si VENTAJA está en SÍ (aunque MANTENER EXTRAS sea NO), para poder apagarla.
- **Código**: `Action::ToggleAdvantage`, `advantage_enabled()/set_advantage_enabled()` (caché atómica),
  `extras_set_advantage` + `[extras].advantage`, handler y forzado en `src/hooks/sections.cpp`.
- **Traducción** (tabla `kMenuTr`): `VENTAJA / ADVANTAGE / AVANTATGE / AVANTAGE / VORTEIL / アドバンテージ`.

## `PODER ∞` / `RESISTENCIA ∞` — gauges de combate que no se gastan `[VALIDADO en Windows]`

En **EXTRAS**, debajo de `VENTAJA`: **`PODER ∞ NO/SÍ`** y **`RESISTENCIA ∞ NO/SÍ`** (el `∞` es un
símbolo vectorial: la fuente no lo trae). Persistentes en `config.ini [extras].infinite_power` /
`[extras].infinite_stamina`. **MODO HEAVEN los incluye** (condición superior a la ventaja); sus
toggles siguen siendo independientes. Validados por el mantenedor: los gauges no se gastan.

**Direcciones MEDIDAS con la traza F12** (bloque de batalla base `0x801BBBF0`, entidad del jugador
`0x801BC03C`; palabra = [mitad alta][mitad baja], la alta es el **max** y la baja el **actual**):

| dirección | qué es | arranque normal |
|---|---|---|
| `0x801BC03C` | HP (max/actual) | `0073 0073` → no se toca |
| `0x801BC040` (alta) / `0x801BC042` (baja) | **PODER** max / actual | `0064 0000` (0 → sube al atacar) |
| `0x801BC044` (alta) / `0x801BC046` (baja) | **RESISTENCIA** max / actual | `0064 0064` (llena; baja al atacar y regenera) |

- **Fix**: `hh_battle_frame_hook` pone `[actual] = [max]` cada frame (misma operación que hacía la
  ventaja con PODER: `[0x801BC042] = [0x801BC040]`). Se activa con **HEAVEN o** el toggle propio. O(1):
  dos lecturas + dos escrituras con chequeo de rango (`1..9999`); **no-op fuera de combate** (max = 0).
  Se accede con `guest_h16()` (mismo criterio que `MEM_H`: `(dir^2)`); ver `src/hooks/sections.cpp`.
- **Código**: `Action::ToggleInfinitePower/ToggleInfiniteStamina`, `infinite_power_enabled()` /
  `infinite_stamina_enabled()` (caché atómica), selectores en EXTRAS, `extras_set_infinite_*` +
  `[extras].*` (`src/platform/support.cpp`), handler + pinning (`src/hooks/sections.cpp`), `∞` en
  `src/platform/overlay.cpp` (`cp == 0x221E`, 13x5 px con sombra +1,+1).
- **Traducción** (`kMenuTr`): `PODER ∞ / POWER ∞ / PODER ∞ / PUISSANCE ∞ / KRAFT ∞ / パワー∞` y
  `RESISTENCIA ∞ / STAMINA ∞ / RESISTÈNCIA ∞ / ENDURANCE ∞ / AUSDAUER ∞ / スタミナ∞`.

## Combo — quirk conocido (a afinar en el futuro)

La **barra de combo** (4 segmentos, y24..y30 del HUD) se alimenta del **PODER**: al llegar a 100 %
reinicia y suma un segmento. Como `PODER ∞` mantiene el PODER al máximo, la barra **no se gasta** y se
queda llena. **PERO en el 1.er combate arranca a 0** y solo se rellena a partir del **2.º** (parece un
gateo de estado: al terminar/vaciar el PODER en el 1.er combate se habilita). No hemos localizado el
contador (0..4) en las zonas vigiladas, así que de momento se deja como está: es del juego y se
autocorrige desde el 2.º combate.

- **A afinar en el futuro**: hallar el flag que habilita el combo (probable en el bloque de batalla
  `0x801BBBF0..`) capturando una traza `run_battle_trace` que cruce el fin del 1.er combate y el 2.º, y
  forzarlo al empezar (o pinear el contador 0..4 = `COMBO ∞`).

## HECHO (validado en Windows): daño FUERA de combate (robots)

Dentro de combate el daño al PJ ya es 0 (hook `func_80232D08`). **Fuera de combate** un robot baja la
vida; ya está anulado (validado por el mantenedor: con HEAVEN ON el robot no baja la vida):

- **MEDIDO**: la vida de campo es el **sheet `0x8017DC40+0x02`** (misma que STATUS/combate); cada
  disparo resta 5 (`0x1847→0x1842→…`). No es la party (`0x801BC03C`) ni el struct vivo
  (`*(0x801BBCCC)=0x8024AD14`, ahí solo hay posición/estado).
- **Escritor localizado** con `HH_WATCH` (`run_field_watch.bat`, HH_WATCH_ADDR=0x8017DC40): la función
  **`func_80379F04`** aplica `a0+0x2 (HP) = HP − *(s16*)0x80388A68`; el llamador le pasa `a0` = objetivo
  (jugador `0x8017DC40`) y deja el daño en el scratch `0x80388A68`.
- **Fix**: hook `hh_heaven_field_damage_hook` sobre `func_80379F04`. Con `heaven_enabled()` pone el
  scratch de daño a **0** durante la llamada (y lo restaura) → el jugador no pierde vida. Es **una**
  función común para todos los robots (no por enemigo). **Validado en Windows**. El `a0` de ENTRADA es
  el atacante; la función fija `a0=0x8017DC40` para el store del HP (no hay que comprobar `a0`).

> Notas de la investigación: `HH_DRWATCH` (watchpoints de hardware) **no dispara** en esta máquina;
> `HH_WATCH` (software) sí, con `ra`/`val`/`ret`. El `ret` del exe no se pudo mapear a la función guest
> por el `.map`, pero la firma de la escritura (`a0=sheet`, `a1=0x80388A68`, resta a HP) la identifica.

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
