# Editor v3 — rediseño ATRIBUTOS/ESTADO, repeat de input y MODO HEAVEN (2026-09-28)

Sesión sobre la rama **`menu-edicion-partida`** (submenú **EDICIÓN DE PARTIDA** del overlay + EXTRAS).
Todo el trabajo está **sin commitear** y **sin validar en Windows** salvo lo que reportó el mantenedor.
Handoff corto: `RETOMAR.md`.

## 1. Recompensa de EXP depende del ENEMIGO (corrige el modelo anterior) `[MEDIDO con traza]`

Traza `run_stats_capture.bat combat` (5 combates contra enemigos distintos; `HH_TRACE` incluye
`0x80376D48` y `0x8022CAFC`; bloques `[STATEXP]` y `[ROW]` en
`lib/N64ModernRuntime/librecomp/src/recomp.cpp`):

- La fila de recompensa aplicada **NO es fija**: `func_8022CAFC` compone al **enemigo** (`a0+0x36` =
  id) y elige en `0x8023C940` (stride `0xA0`) la fila cuyo `+0x4E` coincide con ese id. `[STATEXP] id`
  == `[ROW] a0.36` en los 5 combates (81, 82, 83, 88, 80).
- `func_80376D48` se llama **1 vez por combate** (`call`=1..5). Aplica `EXP_i += round(
  reward_enemigo[i] * ref_i / stat_i )` con `reward` = la fila del enemigo.
- Tabla leída del ELF (`build/recomp/elf/hybrid-heaven.us.elf`, `.file_011`): filas por id. Ejemplos:
  id 81/82/83/80/88 → HP reward **1**; id 46/49/50 → HP 22-24; id 283/286/328 → HP 23-28, OFF hasta 140.
- Consecuencia: "N combates" no es una unidad objetiva (depende del enemigo). Por eso el editor
  **abandona el simulador de combates** y edita directamente el **nivel del atributo**.

> Nota: la afirmación previa "id 81 = jugador / recompensa estática" era **incorrecta**; 81 es un id de
> enemigo y la recompensa escala con el rival derrotado.

## 2. Tope de nivel por atributo según DIFICULTAD `[MEDIDO código]`

`func_80376D10` (`funcs_74.c:41995`) devuelve el tope según `*(0x801BBC0D)` (dificultad de GAME START):
**0 → 79 (`0x4F`), 1 → 89 (`0x59`), ≥2 → 99 (`0x63`)**. Se lee en **cada** bloque de atributo de
`func_80376D48` (HP `lbu 0x4($s0)`, STAMINA `lbu 0xA($s0)`, …), así que **es un tope por atributo** (y,
como el nivel global es la media, también lo acota). El **valor** de la stat va aparte y topa en 9999
(`sltiu ...,0x2710`). El editor capa a **99** (`kPartLevelMax`); por encima de 99 no hay datos en las
tablas (99 entradas).

## 3. Niveles de PARTE del cuerpo (OFENSIVO/DEFENSIVO)

- Son **niveles** por parte (`+0x10+part*2` ofensivo, `+0x1C+part*2` defensivo; u16 word-swapped en el
  save), **no** contadores. Suben atacar / guardar.
- `func_80232A80` (`funcs_62.c:12744`) incrementa el DEFENSIVO de una parte **+1** con tope **`0xFFFF`
  (65535)**: `ori $at,0xFFFF; slt; beq (saltar); addiu +1; sh`.
- Alimentan la **potencia de combate** de forma **multiplicativa** (`MUL_D`): `func_8022DB40` (daño,
  `+0x82..0x8C`) y `func_8022F0E0` (defensa/GUARD, `+0x8E..`). No he visto clamp del nivel dentro de
  esas fórmulas.
- **Decisión del editor**: cap a **99** "por cordura" (el real es 65535). En ESTADO solo `OFENSIVO` y
  `DEFENSIVO`; fuera HIT COUNT/DAMAGE COUNT (contadores sin efecto útil).

## 4. Repeat de input (izq/der) — causa raíz y arreglo

El repeat usaba direcciones derivadas de `btn`, que se obtenía de `func_801C1340`/`func_801C1334`. Esas
funciones devuelven **registros de FLANCOS**, no el estado mantenido:

- `0x80089478` (+0x4 de `0x80089474`) = flancos de la muestra cruda; lo lee `func_801C1334`.
- `0x80089480` (+0xC) = flancos del procesado (stick→D-pad); lo lee `func_801C1340`.
- **Mantenido**: `0x80089476` (+0x2) = muestra cruda (A/B/START + D-pad); `0x8008947E` (+0xA) =
  procesado (solo stick→D-pad, arranca de 0). Los escribe el poll de input `func_800021B4`
  (`funcs_76.c:30144`).

Arreglo (`src/hooks/sections.cpp`): `btn = rh16(0x80089476) | rh16(0x8008947E)` (OR de crudo y
procesado), de ahí salen flanco (`btn & ~prev`) y mantenido (`dir`). `rh16(a) =
*(u16*)&rdram[(a^2)&0x7FFFFF]`.

## 5. Rediseño de menús (EDICIÓN DE PARTIDA)

- **Raíz**: `CARGAR / GUARDAR / ELIMINAR / RESTAURAR` (selector de partida los 3 primeros; **ELIMINAR**
  nuevo: A borra el slot en memoria) + hueco + `PROGRESO / NIVEL` + `ATRIBUTOS / ESTADO / HABILIDADES /
  ITEMS`.
- **ATRIBUTOS** (antes `SIM. COMBATE`): cabecera `NIVEL` global (solo lectura), `TODOS < NIVEL n >`
  (fija los 6 atributos al nivel elegido, 0..99), y filas `HP / RESISTENCIA / OFENSA / DEFENSA /
  REFLEJOS / VELOCIDAD` con `< NIVEL n >` editable + valor del stat. **Sin MAX HP** (comparte nivel con
  HP) y **sin columna EXP/PROGRESO**.
- **Alineación** (`menu_overlay.cpp`, rama `Kind::Number`): número con **ancho fijo** (3 cifras) para
  que el grupo `< NIVEL n >` no baile, y valor del stat en **columna fija** con relleno a la izquierda
  (`  105`, `   86`).
- **ESTADO**: selector interno `TIPO` = `OFENSIVO / DEFENSIVO` (la barra `/` se dibuja en blanco),
  `TODOS < NIVEL n >` (fija las 6 partes del eje a 0..99) + 6 filas de parte (`CABEZA`, `CUERPO`,
  `BRAZO IZQ/DER`, `PIERNA IZQ/DER`) con `< NIVEL n >`.
- **ITEMS**: nombres en **MAYÚSCULAS** (el juego los guarda "Mayús Inicial").
- **HABILIDADES**: opción `SIN CAMBIOS` → **`RESET`**.
- **ELIMINAR**: `hh::save::delete_slot(slot)` vacía el slot y marca su registro de cabecera como no
  presente (`clear_save_header_record`). Queda efectivo al **GUARDAR**.

## 6. MODO HEAVEN (EXTRAS) — PARCIAL, PENDIENTE

Añadido en la raíz de **EXTRAS** un selector `MODO HEAVEN NO/SÍ`. Al poner **SÍ** aplica, sobre el slot
del editor, vía `hh::save`: **nivel de los 6 atributos = 99** (ESTADO+ATRIBUTOS), **todas las
habilidades a SÍ**, **todos los items a 99**. Log `[heaven]`.

**PENDIENTE (tarea para la próxima sesión)**:
1. **Invulnerabilidad**: que el PJ reciba **daño 0 siempre**. Hay que localizar dónde se aplica el daño
   al jugador (`func_8022F0E0` defensa / resolución de golpe) y parchear/forzar 0.
2. **Items que NO se gasten**: localizar el consumo de item (resta de cantidad) y anularlo.
3. **Aplicar en runtime** (no solo al save): decidir si MODO HEAVEN debe escribir la struct viva
   `0x8017DC40` (efecto inmediato) además del slot, y si debe auto-GUARDAR.

## 7. Otros pendientes

- **Centrar los submenús `GRÁFICOS` y `CONTROLES`** (hoy no están en el grupo `custom_layout` del
  overlay). Añadir sus `ScreenId` a `is_save_edit`/`custom_layout` en `src/hooks/menu_overlay.cpp`.
- **Validar en Windows** todo el rediseño (ATRIBUTOS/ESTADO, repeat, ELIMINAR, ITEMS mayúsculas,
  HABILIDADES RESET, MODO HEAVEN).

## Ficheros tocados esta sesión (sin commitear)

`src/subsystems/menu.cpp`, `include/hh/menu.h`, `src/hooks/sections.cpp`,
`src/hooks/menu_overlay.cpp`, `src/subsystems/save_edit.cpp`, `include/hh/save_edit.h`,
`lib/N64ModernRuntime/librecomp/src/recomp.cpp` (traza `[STATEXP]`/`[ROW]`).
