# 2026-09-28 — Lógica de juego: técnicas, items y estadísticas (reconstrucción)

> Sesión `menu-edicion-partida`. Recopila la **lógica jugable** reconstruida para el editor de partida.
> Complementa `notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md` (formato del `.pak`).
> **Marcas**: `[MEDIDO]` = leído del C recompilado (`build/recomp/RecompiledFuncs/`) y/o cruzado con
> `.pak` reales; `[INFERIDO]` = deducido sin ejecutar; `[PISTA]` = por confirmar con oráculo/emulador.
> No editar notas antiguas; ampliar esta o crear otra fechada.

## 0. Cómo leer esto

El guardado de Hybrid Heaven **no recalcula nada**: al cargar, los valores se copian del `.pak` a
tábuenas de runtime tal cual. Por eso subir el nivel en el fichero **no** sube HP/OFFENSE/etc. hasta que
se ejecuta la lógica de subida (o se escriben los campos a mano). Esta nota documenta dónde vive cada
cosa para poder editar/provocar esa lógica.

## 1. Técnicas / habilidades `[MEDIDO]`

### 1.1 Estructura de cada técnica (runtime)

Tabla **`0x80183CE0`**, **86 entradas × 6 B** (`id*6`):

| Offset | Tipo | Significado |
|---|---|---|
| `+0` | u8 | **estado**: `0` = bloqueada/no usable, `1` = aprendida/usables, `2` = recién aprendida (pendiente de “commit”) |
| `+2` | s16 | **maestría** |
| `+4` | u16 | **usos** |

- Copia espejo **`0x80183EE4` (= 0x80183CE0 + 0x204)** con el mismo formato (el plan la llamó “J2”).
- Bandera por técnica **`0x801840E8 + id`** (86 B) `[INFERIDO]`: se **pone a 0** al cargar la partida
  (`func_80152240`, ver §1.3). Probablemente marca “novedad/pendiente de aviso”; rol exacto por confirmar.

### 1.2 Lo que se guarda en el slot

En el slot del `.pak` (offsets ya documentados en la nota de formato), el serializador
`func_80144C40` guarda **3 B por técnica** en **`0x09E + id*3`**:
`[estado, maestría&0xFF, usos]` (la maestría se recorta a 1 byte).

Origen: `0x80183CE0`. Destino al cargar: `0x80183CE0`. (No hay conversión de nivel; es copia.)

### 1.3 Carga de técnicas/items al CONTINUAR `[MEDIDO]`

`func_80152240` (0x80152240; llamada desde el flujo de CONTINUE `func_801C3CDC`) copia bloques
guardados a las tablas de runtime:
- Copia **86 × 6 B** desde un bloque fuente a **`0x80183CE0`** y a **`0x80183EE4`**, y **pone a 0
  `0x801840E8+i`**.
- Copia **3 × 7 B** a `0x8017DF14` / `0x8017DF2C`.
- Copia **9 palabras** a `0x8017DD7C` y 1 palabra+u16 a `0x8017DDA4`.

### 1.4 “Commit” de técnicas nuevas `[MEDIDO]`

`func_802322E8` (0x802322E8): recorre 86 entradas y copia del área de progresión
**`0x801BBBF0 + 0x4F4`** (`a0 = 0x801BBBF0 + id*6`) a `0x80183CE0`:
- `[0x4F4(id)]` → estado (`+0`); **si estado == 2 → se guarda 1 y maestría = 0**.
- `[0x4F6(id)]` → maestría (`+2`); `[0x4F8(id)]` → usos (`+4`).
- Además copia `struct+2` (HP máx) desde `0x801BBBF0+0x44E` y bytes a `struct+0x62..0x65` desde
  `0x801BBBF0+0x4EE..0x4F1`.

→ **`0x801BBBF0` es el bloque de progresión** (el que se serializa parcialmente en el slot); `+0x4F4`
es su tabla de técnicas (86×6). El paso **2 → 1** es “confirmar” que una técnica recién aprendida ya
es usable.

### 1.5 PROCESO: maestría por uso `[MEDIDO]`

`func_80378CF0` (0x80378CF0, `file_057`, código de batalla):
- Toma el id de la técnica en uso (`lbu` en `entidad+0x2D9`).
- Medidor por técnica en **`0x801840E8 + id`** (u8): `+= 0x32` (**+50**) por uso.
- Si el medidor llega a **`0x64` (100)**: `-= 100` y **maestría `+2` de `0x80183CE0+id*6` sube 1**
  (tope 0xFF).

⇒ **Cada 2 usos de una técnica = +1 de maestría** (50 por uso, umbral 100). El medidor se pone a 0 al
cargar partida (`func_80152240`), pero la maestría (`+2`) persiste en el slot.

`func_80378B48` (0x80378B48) es la variante que además incrementa un **contador por técnica en la
entidad** (`entidad + id*6 + 0xAA`, s16, tope 0xFF) si aún no está a tope, y sólo procesa si el evento
`0x801BBBF0+0x2C` no es 0xA/0xB/0xF.

### 1.6 PROCESO: aprendizaje de una técnica `[MEDIDO]`

`func_80378764` (0x80378764, `file_057`): al realizar ciertas acciones, para la técnica usada
(`entidad+0xA`) comprueba (evento no 0xA/0xB, acción no 0x23/0x24, flag `0x801BBBF0+0x1030`!=0,
puntero `0x801BBBF0+0x448`→`+0x74`==3) y que la técnica **no esté ya aprendida** (`0x801BC0E4+id*6 +0 == 0`).
Entonces:
- Calcula un incremento `a0 = (nivel_actual - nivel_requerido) + 1` (si `nivel_actual >= requerido`,
  si no `1`). El nivel actual es `0x801BBBF0+0x4 / 10` (el `N` de `N-P`); **el nivel requerido por
  técnica está en una tabla de la entidad: `entidad + 0x14 + id*28`.**
- Suma `a0` a la **maestría `+2` de `0x801BC0E4+id*6`** (tope 0xFF).
- Si la maestría alcanza el umbral `lbu entidad+0xE`: marca `+0 = 2` (**aprendida/pendiente**) y
  **también `+0 = 2` de la técnica emparejada (`id ^ 1`)**; añade a la cola de novedades
  (`0x80240730+0x20`) y actualiza contadores (`0x801BBBF0+0x7D1`/`+0x7D4`/`+0x7D7`).

⇒ **Aprendes una técnica acumulando maestría con acciones; subir de nivel respecto al nivel requerido
acelera la subida.** Las técnicas van **emparejadas de 2 en 2** (`id ^ 1`), coherente con el par de
item/estilo; aprender una enseña la pareja. Luego `func_802322E8` confirma `2 → 1` (usable).

`func_802322E8` (commit) tiene dos llamadores en `funcs_61.c` (0x8021C9C0 y 0x8021CFE8), dentro de la
máquina de estados `func_8021C934` (evento `0x801BBBF0+0x2C`, contador `+0x9A`, HP `+0x44E`, flags
`+0x47C..0x484/0x818`, y `+0x1030/0x1031`): flujo de **fin de combate → subida/novedad → commit**.

## 2. Items `[MEDIDO]`

- Runtime: cantidad u8 por item en **`0x8017E004 + id*8 + 4`** (45 items, tope 99).
- Slot: **`0x1A0 + id`** (u8, 45 items) — serializado por `func_80144C40` leyendo `+4` de cada registro.
- Tras items, el serializador escribe 3×7 B (`0x8017DF14`) y 6×1 B (`0x8017DD7C+2`).
- **Nombres `[MEDIDO]`**: la tabla `0x8017DF50` (45 punteros) da, en orden:
  `0-3` Life Charger **S/M/L/X**, `4-7` Stamina Charger S/M/L/X, `8-11` Battle Charger S/M/L/X,
  `12` Speed Restorer, `13` Poison Restorer, `14` Super Restorer, `15` Offence Raiser,
  `16` Defence Raiser, `17` Speed Raiser, `18` Ring Eraser, `19` Flame Shot, `20` Flame Shot SP,
  `21` Ice Shot, `22` Ice Shot SP, `23` Poison Shot, `24` Poison Shot SP, `25` Hurricane Shot,
  `26` Hurricane Shot SP, `27` Ion Shot, `28` Ion Shot SP, `29` Offence Enhancer, `30` Defence
  Enhancer, `31` Speed Enhancer, `32` Stamina Booster, `33` Power Booster, `34` Offence Drainer,
  `35` Defence Drainer, `36` Speed Drainer, `37` Memory Card, `38` Code Key, `39` Map Viewer,
  `40` Defuser, `41` Flame Unit, `42` Cold Unit, `43` Invisible Unit, `44` Impulse Unit.
  (Espacio = `0xA1 0xB8`.) La tabla se extrae del ELF en `file 0x109DF50`.
- **Registro por item `0x8017E004 + id*8`**: `+0` = puntero a la entrada de nombre de ESE item
  (`*(u32)ptr` = string), `+4` = cantidad (u8). El editor lee el nombre **desde ese puntero**
  (`item_name()`), robusto ante cualquier reorden que hiciera el juego. La tabla `0x8017DF50` queda
  como fallback estático.
- **Display ↔ slot INVERSO por familia `[MEDIDO en partida]`**: el juego guarda las variantes de una
  familia en orden **contrario** al de la tabla de nombres (S↔X, M↔L). El editor muestra el nombre en
  orden natural (S,M,L,X) pero lee/escribe la cantidad en el slot invertido de su familia mediante
  `item_slot_of(display)` (`src/subsystems/save_edit.cpp`): agrupa items contiguos con el mismo
  **nombre base** (sin sufijo ` S/M/L/X`/` SP`) y devuelve `inicio + (fin - display)`. (Si el juego
  además invierte las parejas `X`/`X SP`, este criterio ya las cubre; validar en Windows.)

## 3. Estadísticas del personaje `[MEDIDO]`

Struct **`0x8017DC40`** (¡el template del ELF está EN esa dirección! `file 0x109DC40` → vaddr
`0x8017DC40`). En el slot se guarda byte-swapped (§ nota de formato); leer como `u16 LE`.

| Offset slot | Campo | Notas |
|---|---|---|
| `0x00` | HP | |
| `0x02` | HP máximo | escrito por `func_802322E8` desde `0x801BBBF0+0x44E` |
| `0x0A` | STAMINA | |
| `0x10..0x1A` | contador OFENSIVO por parte (6) | “veces que atacas/impactas” |
| `0x1C..0x26` | contador DEFENSIVO por parte (6) | “veces que te atacan/defiendes” |
| `0x40` | OFFENSE (potencia) | estadística, **no** contador |
| `0x42` | DEFENSE | |
| `0x44` | SPEED | |
| `0x46` | REFLEX | |
| `0x48` | NIVEL | |
| `0x54` | (30) / `0x58..0x5E` (40×4) | por identificar |
| `0x68` / `0x76` (+parte*2) | HIT/DAMAGE COUNT por parte | en save 1-1 = 0 `[INFERIDO]` |

### PROCESO: subida por partes del cuerpo y stats `[INFERIDO]/[PISTA]`

Diseño del juego (confirmado por el mantenedor): **cada parte sube de nivel por separado** según su uso
ofensivo y defensivo. Los campos del save lo reflejan:
- `0x10 + parte*2` = contador **OFENSIVO** por parte (6).
- `0x1C + parte*2` = contador **DEFENSIVO** por parte (6).
- `0x40/0x42/0x44/0x46` = OFFENSE/DEFENSE/SPEED/REFLEX **globales** (potencia), que dependen de las partes.

Código de batalla (`file_057`) que toca valores por parte:
- `func_80378D84(part)` (0x80378D84): switch de 6 casos; devuelve `lbu` de `0x8017DC40 + {0x44,0x4A,0x52,0x53,0x55,0x54}` **+1**.
- `func_80378E3C(part)` (0x80378E3C): switch de 6 casos; devuelve `lhu` de `0x8017DC40 + {0x00,0x08,0x40,0x42,0x46,…}`.
  El mapeo exacto parte→offset queda por confirmar (los offsets no son un array contiguo).

Recomputación de los stats globales (imagen plana `0x80024xxx`, struct del jugador apuntado por
`0x800D425C`/`0x800D4260`):
- `func_80025908`/`func_80025A00`: **reset** de `+0x40` (OFFENSE) / `+0x42` (DEFENSE) y copia a `+0x32`/`+0x34`.
- `func_80025940`/`func_80025A38`: **acumulan** `+stat` desde un “script” de bytes (con signo); el mismo
  byte `<<3` se suma a la copia `+0x32`/`+0x34`. Parece la **composición del stat a partir de las
  partes/equipo** (¿y del nivel?), no un simple `base + k*nivel`.
- **Cómo cerrar la fórmula**: (a) oráculo (BizHawk/`r64dump`) con dos partidas a niveles/partes
  distintas y `diff` de `0x8017DC40` + `0x801BBBF0`; (b) trazar quién alimenta el “script” y quién
  escribe `0x801BBBF0+0x44E` (HP máx, que `func_802322E8` copia a `struct+2`).

### HP y stats derivan de las PARTES (no del nivel) `[MEDIDO en partida, 2026-09-28]`

Descubrimiento del mantenedor (captura STATUS): **subir el contador DEFENSIVO de una parte sube la
stat global DEFENSE y también el HP**. Ejemplo: +1 a la defensa del **brazo derecho** → DEFENSE 50→74
y HP máx 100→105 (con LEVEL 1 sin cambios). → **el nivel NO es el lever**; el HP/DEFENSE se
**recomponen desde los contadores por parte**.

- Contadores por parte en el slot: OFENSIVO `0x10 + parte*2`, DEFENSIVO `0x1C + parte*2` (u16 LE).
- El HP ganado (+5) coincide con `tabla 0x80388B06[0] = 5` que usa `func_80376D48` → refuerza que
  `func_80376D48` **reparte HP a partir del nivel de una parte** (`lbu 0x8017DC40+4`), no del nivel global.
- El LEVEL global es la **media de 6 bytes** (`func_8037865C`: `(b04+b0A+b52+b53+b54+b55+6)/6`), así que
  subir el nivel a mano sin tocar las partes no cambia nada.
- **Pendiente de decodificar**: la fórmula exacta parte→DEFENSE/OFFENSE/SPEED/REFLEX/HP (parece la
  composición de las funciones planas `func_80025908/25940` (OFFENSE) y `func_80025A00/25A38` (DEFENSE),
  que acumulan desde un “script” de bytes). **Datos para ajustar**: con +1 def brazo derecho →
  DEFENSE +24, HP +5. Faltan más puntos (varias partes, varios niveles) o el oráculo.
- **En el editor**: el lever es la pantalla `ESTADO` (contadores OFENSIVO/DEFENSIVO por parte); el juego
  recomputa las stats al cargar. La auto-escala por nivel que se probó **se retiró** (lever erróneo).
  La edición manual de stats sigue en `ATRIBUTOS`.

## 4. Falsos positivos a evitar `[MEDIDO]`

- Un barrido “heurístico” del ELF buscando tablas monótonas (p. ej. en `file 0x1508410` → vaddr
  `0x80388410`) **cae dentro del código** de `file_057` y da secuencias crecientes que **no** son
  tablas. No documentar esos hallazgos sin confirmar la referencia desde el código.
- Las tablas de datos de un módulo se localizan mejor sabiendo su **vaddr** (program headers del ELF;
  ojo: el ELF tiene segmentos solapados/sintéticos) y buscando el `lui/addiu` que las referencia.

## 5. Funciones de referencia rápida `[MEDIDO]`

| Dirección | Rol |
|---|---|
| `0x80183CE0` | tabla de técnicas (86×6) |
| `0x80183EE4` | copia espejo de técnicas |
| `0x801840E8` | bytes por técnica (¿novedad?) |
| `0x8017DC40` | struct del personaje (HP/stats/nivel) |
| `0x801BBBF0` | bloque de progresión (progreso, técnicas `+0x4F4`, HP máx `+0x44E`, …) |
| `0x8017E004 + id*8 + 4` | cantidad de item `id` |
| `0x80144C40` / `0x80144E68` | serializar / deserializar bloque (magic + personaje + técnicas + items) |
| `0x80141F28` / `0x80141D08` | serializar / deserializar slot `0xD00` |
| `0x80152240` | cargar técnicas/items a runtime (CONTINUE) |
| `0x802322E8` | commit técnicas `2→1` + copia bloque progresión |
| `0x8021C934` | máquina de estados de fin de combate → subida/novedad/commit |
| `0x80378CF0` | **maestría por uso** (`0x801840E8[id] += 50`; a 100 → maestría +1) |
| `0x80378B48` | contador por técnica en la entidad (`+0xAA+id*6`) + medidor |
| `0x80378764` | **aprendizaje**: acumula maestría; al umbral marca estado 2 y el par (`id^1`) |
| `0x80378D84` / `0x80378E3C` | valor de atributo por “parte” (0..5) desde `0x8017DC40` |
| `0x80025908`/`0x80025940`/`0x80025A00`/`0x80025A38` | recompute de OFFENSE/DEFENSE (imagen plana) |

### Glosario de campos del bloque de progresión `0x801BBBF0` `[MEDIDO]`

| Offset | Uso |
|---|---|
| `+0x00` | flag (si !=0, la cabecera usa `0xFF` en vez de `func_80108280`) |
| `+0x02` | campo escrito a `struct+0x364` |
| `+0x04` | **PROGRESO** u16 = `N*10+P` (a `struct+0x366`); `N` = `+0x04 / 10` |
| `+0x08` | campo (bajo) a la cabecera, `desc+A` |
| `+0x0A` | campo u16 a la cabecera, `desc+8..9` |
| `+0x1D` | byte a la cabecera, `desc+B` |
| `+0x2C` | evento/estado de batalla (0xA/0xB, 0xF…); `func_8021C934` |
| `+0x9A` | contador (se incrementa, tope 0xFFFF) |
| `+0x44E` | HP máximo (a `struct+2` vía `func_802322E8`) |
| `+0x4F4 + id*6` | **técnicas de progresión** (86×6): `+0` estado, `+2` maestría, `+4` usos |
| `+0x7D1`/`+0x7D4`/`+0x7D7` | contadores de novedades por rango de técnica |
| `+0x1030`/`+0x1031` | estado de la máquina de combate/novedad |
