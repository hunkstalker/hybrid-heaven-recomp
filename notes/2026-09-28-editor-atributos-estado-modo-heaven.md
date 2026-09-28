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

## 6. MODO HEAVEN (EXTRAS) — modo GLOBAL persistente, pendiente de validar

> **Rediseño (misma sesión, a petición del mantenedor)**: MODO HEAVEN deja de estar atado al slot del
> editor y pasa a ser un **modo global de juego**, **independiente de la partida** y **persistente**
> (`config.ini [extras].heaven`). `EDICIÓN DE PARTIDA` vuelve a ser solo editor.

Selector `MODO HEAVEN NO/SÍ` en **EXTRAS**. `ToggleHeavenMode` solo persiste el flag
(`hh::extras_set_heaven`); **no toca el `.pak`**. Los efectos, gateados por `hh::menu::heaven_enabled()`
(config), los aplican cuatro hooks en `src/hooks/sections.cpp` (re-registrados con
`register_title_menu_hook`):

1. **Máximo al cargar/empezar partida** `[MEDIDO direcciones]`: post-original de `func_80144E68`
   (deserializa el personaje) y `func_80152240` (monta las tablas de runtime; CONTINUE y partida
   nueva) → `hh::save::apply_heaven_runtime(rdram)` lleva el **personaje vivo `0x8017DC40`**:
   **ATRIBUTOS** (6 niveles) a 99 aplicando `kIncByPart` (stat + HP máx/NIVEL global), **ESTADO**
   OFENSIVO/DEFENSIVO por parte a 99, y las **86 técnicas** aprendidas (`0x80183CE0` + espejo).
   El save del juego serializa el mismo struct (`func_80144C40`), así que **se persiste al guardar**.
2. **Invulnerabilidad** `[INFERIDO]`: `func_80232D08` es la **única** función que resta el daño ya
   resuelto de las partes del cuerpo (`a0+0x2B8+part*2`); su único llamador es la resolución de golpe
   `func_80232E94`. `hh_heaven_damage_hook` fuerza `a1=0` cuando el ente dañado (`a0`) es la partida
   del jugador (`0x801BC03C`). No toca a los enemigos.
3. **Items que no se gastan** `[INFERIDO]`: `func_8013D520(a0=item, a1=delta con signo, a2=party/enemy)`
   suma/resta la cantidad de un item (u8, tope 99). Delta negativo = consumo. `hh_heaven_item_hook`
   pone `a1=0` cuando el delta es negativo. **No** se fuerzan a 99: acumulan y se guardan normal.

**Semántica acordada con el mantenedor**:
- Guardar con HEAVEN ON deja en el `.pak` ATRIBUTOS/ESTADO máx y el inventario que se tenga.
- Apagar HEAVEN y cargar ese save → conserva niveles/items (están en el fichero) pero **vuelve a
  perder vida** y **los items se gastan**.
- `extras_unlocked()` incluye `heaven=="si"` para poder apagarlo aunque MANTENER EXTRAS sea NO.

### 6.1 SORPRESA/ventaja de combate ("back attack") — HECHO y validado funcionalmente

Instrumenté una traza event-driven (`run_battle_trace.bat` + **F12**; ver `src/hooks/sections.cpp`
`hh_battle_frame_hook`/`hh::battle_trace_toggle`) que registra cambios de campo/party/sheet. La traza
**diferencial** normal vs por la espalda dio el flag: el byte **`0x801BBBF0+0x1034`** (dirección
`0x801BCC24`) pasa a **2** solo en el combate con ventaja (`vi≈8315`, antes del setup); el `+0x1032=1`
del setup normal sale en ambos. Nombre interno del juego: `gw.back_attack` (cadena de debug en
`file_011`). Lo escriben `func_8021D8D0`/`func_801F5F5C`, así que se **fuerza por-frame** (0/1 → 2) bajo
`heaven_enabled()`. **Validado por el mantenedor**: la pelea empieza con el **POWER al máximo** (no hace
falta que aparezca la palabra "ADVANTAGE").

> **Bug corregido**: la 1.ª versión forzaba `+0x1037` por un `bswap` de más al decodificar la traza. El
> byte correcto es `+0x1034`; el watcher ya no hace `bswap` (la palabra guest se lee directa, `MEM_W`).

### 6.2 Daño FUERA de combate (robots) — implementado y VALIDADO en Windows

En combate el daño es 0, pero **un robot en el campo sí baja la vida**. Medido:

- La vida de campo es el **sheet `0x8017DC40+0x02`** (misma que STATUS/combate); cada disparo resta 5
  (`0x1847→0x1842→…`). El `live_ptr` `*(0x801BBCCC)=0x8024AD14` **no** lleva la vida (solo posición/
  estado). Reescribir HP a 9999 por-frame no bloquea el daño real (se retiró).
- **Escritor** (`HH_WATCH` sobre `0x8017DC40`, `run_field_watch.bat`): **`func_80379F04`** aplica
  `a0+0x2 (HP) = HP − *(s16*)0x80388A68`; el llamador pasa `a0` = objetivo (jugador `0x8017DC40`) y fija
  el daño en el scratch `0x80388A68`.
- **Fix**: `hh_heaven_field_damage_hook` (hook de `func_80379F04`): con `heaven_enabled()` pone el
  scratch a 0 durante la llamada y lo restaura → daño de campo 0. **Una** función común a todos los
  enemigos. **Validado por el mantenedor**: con HEAVEN ON el robot no baja la vida. Ojo: el `a0` de
  ENTRADA es el atacante; la función fija `a0=0x8017DC40` para el store del HP (no comprobar `a0`).
- Nota: `HH_DRWATCH` (hardware) no disparó; se usó `HH_WATCH` (software, con `ra`/`val`/`ret`).

> **[A VALIDAR en Windows]**: que los hooks cubran CONTINUE y partida nueva (si no, hook puntual); el
> daño 0 en combate y el no-consumo de items; la ventaja (ya validada); y el daño de campo pendiente.

## 7. Otros pendientes

- **Centrar los submenús `GRÁFICOS` y `CONTROLES`** — HECHO (`menu_overlay.cpp`): `ScreenId::Graphics`
  añadido a `custom_layout`; `scroll_cap5` (ventana de 5 filas) solo para EXTRAS/CONTROLES/editor, así
  GRÁFICOS no pierde su 6.ª fila. Tope de `x_shift` para que un binding largo de CONTROLES no saque el
  contenido de `kVirtualWidth`.
- **Validar en Windows** todo el rediseño (ATRIBUTOS/ESTADO, repeat, ELIMINAR, ITEMS mayúsculas,
  HABILIDADES RESET, MODO HEAVEN).

## Ficheros tocados esta sesión (sin commitear)

`src/subsystems/menu.cpp`, `include/hh/menu.h`, `src/hooks/sections.cpp`, `src/hooks/menu_overlay.cpp`,
`src/subsystems/save_edit.cpp`, `include/hh/save_edit.h`, `include/hh.h`, `src/platform/support.cpp`,
`lib/N64ModernRuntime/librecomp/src/recomp.cpp` (traza `[STATEXP]`/`[ROW]`).
