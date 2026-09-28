# 2026-09-28 — Escalado de stats: corrección de dirección y funciones reales

> Sesión `menu-edicion-partida`, continuación del handoff `RETOMAR.md`. **Corrige un error de las
> notas previas** (`notes/2026-09-28-logica-juego-tecnicas-items-y-stats.md` §3) que invalidaba la
> principal "pista fuerte" del handoff. Marcas: `[MEDIDO]` = leído del C recompilado / asm
> etiquetado (`build/recomp/RecompiledFuncs/`, `build/recomp/asm/`); `[INFERIDO]` = deducción sin
> ejecutar; `[PENDIENTE]` = requiere oráculo.

## 1. CORRECCIÓN CRÍTICA: `0x800D425C`/`0x800D4260` no existen `[MEDIDO]`

En el desensamblado, `lui $X,0x800D` + `addiu $X,$X,-0x425C` es **`0x800D0000 - 0x425C = 0x800CBDA4`**
(no `0x800D425C`: el `addiu` resta, no forma `0x800Dxxxx`). El asm etiquetado lo confirma:

- `build/recomp/asm/resident.s:37218` → `lui $s0, %hi(D_800CBDA4_CC9A4)` / `:37231` `addiu ... %lo(D_800CBDA4_CC9A4)`
- `build/recomp/asm/resident.s:40818` → `lui $s1, %hi(D_800CBDA0_CC9A0)`

Así que:
- **`0x800CBDA4`** = puntero al registro `A` (struct del "efecto/ente").
- **`0x800CBDA0`** = puntero-cursor del "script" de bytes.
- `A` apunta a un registro del array **`0x801B5520`** (stride **`0xD8`**, 20 entradas), **NO** al
  struct del personaje `0x8017DC40` (p. ej. `func_80022874` en `funcs_78.c:19200-19212` calcula
  `A = 0x801B5520 + a0*0xD8`).

⇒ Las funciones `func_80025908/25940` y `func_80025A00/25A38` (reset/acumulación de `+0x40`/`+0x42`
desde el "script") **operan sobre `0x801B5520`**, no sobre el jugador. La hipótesis del handoff de
que ahí se componen OFFENSE/DEFENSE del personaje **queda sin soporte**. Además esas 4 funciones no
tienen llamadores directos (`LOOKUP_FUNC`) en el C recompilado: sólo aparecen como entradas de tablas
de punteros (`resident_data.data.s:22972-22975`).

## 2. El registro del personaje es de 0x9E bytes y se copia entero al cargar `[MEDIDO]`

`func_80144E68` (`funcs_56.c:35411`, deserializador de la partida):
- copia **0x9C bytes** del buffer de save a **`0x8017DC40`**, y luego un `u16` más → total **0x9E**.
- Después escribe la tabla de técnicas `0x80183CE0` (86×6) y otras tablas.
⇒ **offset del slot = offset de runtime** (el editor ya lo asume). `NIVEL` global = media.

`func_80141D08` (`funcs_56.c:35089`, carga de slot `0xD00`) llama a `func_80144E68` y **no** invoca
ninguna recomputación de `+0x40..+0x46`. `func_801C3CDC` (CONTINUE) → `func_80152240`
(`funcs_57.c:20719`) sólo copia técnicas/items. **Confirmado: cargar no recalcula stats.**

## 3. Composición de los stats de combate (dónde SÍ se combinan) `[MEDIDO]`

### 3.1 `func_8022C7A4` (`funcs_60.c:34813`) — copia jugador → ente

Copia `0x8017DC40` (`v1`) a un ente (`a0`). Mapa medido:

| destino ente | origen jugador |
|---|---|
| `+0x00` | `+0x00` HP |
| `+0x02`/`+0x46` | `+0x02` HPmáx (evento 0xA/0xB usa `+0x00`) |
| `+0x08`/`+0x0A` | `+0x08` STAMINA |
| `+0x04` | `+0x0E` × 100 |
| `+0x4E`/`+0x58` | `+0x40` OFFENSE |
| `+0x50`/`+0x5A` | `+0x42` DEFENSE |
| `+0x52` | `+0x44` SPEED |
| `+0x54`/`+0x5C` | `+0x46` REFLEX |
| `+0x2D1` | `+0x48` NIVEL |
| `+0x82..+0x99` | `+0x10..+0x27` = **los 12 contadores de parte** (OFENSIVO `+0x10..0x1A` → `+0x82..0x8C`; DEFENSIVO `+0x1C..0x26` → `+0x8E..0x98`) |
| `+0x40`, `+0x42`, `+0x44`, `+0x48` | 0 |
| `+0x384` | 100 |

### 3.2 `func_80378F64` (`funcs_74.c:48389`) — contadores OFENSIVOS → bonos

Para cada uno de los 6 `u16` del ente `+0x82,+0x84,+0x86,+0x88,+0x8A,+0x8C` (contadores OFENSIVOS),
calcula `(val==1 ? 0 : tabla[val])` y guarda en `ente+0x6A,+0x6C,+0x6E,+0x70,+0x72,+0x74`.
Tablas en `0x80388410` (= `lui 0x8039; addiu -0x7BF0`) + `{0x944, 0xA0A, 0xAD0, 0xB96, 0xC5C, 0xD22}`.
La primera (`0x80388D54`) empieza `20,20,8,13,18,28,38,48,63,78,98,118,138,163,...`.

### 3.3 `func_8022CAFC` (`funcs_60.c:36306`) — stats de un miembro de party

Destino `a3` = structs `0x801BBBF0-0x3FC4` / `-0x3C28`. Tabla de partes **`0x8023C940`** (stride
`0xA0`); elige la fila cuyo `+0x4E == jugador+0x36`. Sobre `t3 = 0x8017DC40` y `t1 = fila`:

- `a3+0x00/+0x02/+0x46` = `HP × lh(t1+0x1E) / 100`, mínimo `lhu(t1+0x1C)`.
- `a3+0x08/+0x0A` = `STAMINA + lh(t1+0x22)`, mínimo `lhu(t1+0x20)`.
- `a3+0x04` = `(jugador+0x0E + lb(t1+0x25)) × 100`, mínimo `lbu(t1+0x24)`.
- `a3+0x4E/+0x58` = **`DEFENSE(jugador+0x42) × lbu(t1+0x0E) / 100`**, mínimo `lhu(t1+0x0C)`.
- `a3+0x50/+0x5A` = **`OFFENSE(jugador+0x40) × lbu(t1+0x12) / 100`**, mínimo `lhu(t1+0x10)`.
- `a3+0x54/+0x5C` = **`REFLEX(jugador+0x46) + lh(t1+0x16)`**, mínimo `lhu(t1+0x14)`.
- `a3+0x52` = **`SPEED(jugador+0x44) + lh(t1+0x1A)`**, mínimo `lhu(t1+0x18)`.
- `a3+0x82..+0x8C`: 6 valores construidos a partir de **los contadores DEFENSIVOS del jugador**
  (`0x8017DC40+0x1E..0x26` promediados /5) más un valor base, con topes.

⇒ Los `+0x40..+0x46` guardados por el editor **sí** influyen en combate (×factor/100), pero el
resultado va a otro struct, no de vuelta a `0x8017DC40`.

### 3.4 `func_80376D48` (`funcs_74.c:42045`) — subida de nivel (HP)

Nivel del personaje en `0x8017DC40+0x04`; progreso en `+0x06`. Reparte HP/HPmáx con la tabla
`0x80388410+0x6F6` (umbral `+0x630`), sumando también a `0x801BBBF0+0x44C/+0x44E`.

### 3.5 `func_80378EBC` (`funcs_74.c:48271`) y `func_80244174` (`funcs_63.c:5`)

- `func_80378EBC`: lee `lhu a0+0x52` y suma `0x80388410+0x3DE` hasta alcanzar ese valor (conversión
  nivel→acumulado).
- `func_80244174(a0=atributo 0..5, a1=índice, a2=delta)`: subida de un atributo con animación; usa
  las 6 tablas `0x80388410+{0x6F6,0x882,0xC6,0x252,0x56A,0x3DE}` y lee los 6 "niveles" en
  `0x8017DC44 + a1*0x9E + {0x44,0x4A,0x52,0x53,0x55,0x54}` (stride 0x9E).

## 4. El +24 de DEFENSE del handoff queda sin explicar `[PENDIENTE]`

- **No existe** en el C recompilado una función que lea los contadores DEFENSIVOS
  (`0x8017DC40+0x1C..0x26`, o ente `+0x8E..0x98`) y escriba `0x8017DC40+0x42` (barrido automático:
  0 coincidencias). Tampoco hay una tabla de defensa análoga a `func_80378F64` (base
  `0x80388410` sólo aparece en `funcs_63/72/74`; usos de tabla: `func_80244174`, `func_80376D48`,
  `func_80378EBC/F64`).
- Ninguna de las 6 tablas de parte tiene saltos de 24 (sus deltas son 5,5,10,10,15...) ⇒ el `+24`
  **no** sale directamente de `func_80378F64`.
- `[INFERIDO]` El `+24` pudo venir de: (a) que el editor antiguo (ya retirado) auto-escalara algo;
  (b) que el valor mostrado en STATUS use `func_8022CAFC` (stat almacenada × factor de la fila de
  partes) y el contador editado cambiara de fila/atributo; (c) que el "contador DEFENSIVO" del
  editor escriba en un offset que en runtime es otra cosa.

## 5. Captura planificada: quién escribe las stats (port, jugando) `[PENDIENTE]`

**No** se puede "fabricar" una partida que sólo suba un contador (la evolución depende de muchas
variables); la medida del handoff es una inferencia y no se usa como base. Lo que sí vale: **jugar y
capturar el instante en que el juego escribe las stats**. En el port hay instrumentación lista:

- `HH_DRWATCH=0xADDR[,...]` (hasta 4 watchpoints de hardware de 4 B, **solo Windows**) →
  `hh_drwatch.log` **solo al cambiar el valor**, con `old->new`, `rip`, `ra`/`sp`/`a0..a3` guest y
  **call rings guest**; más `hh_drwatch_rdram.bin` one-shot. `recomp.cpp:1305-1354`.
- Bat: **`run_stats_capture.bat [stats|counters|levels]`** (creado). Set `stats` vigila
  `0x8017DC40` HP/HPMAX, `0x8017DC80` OFF/DEF, `0x8017DC84` SPD/REF, `0x8017DC88` NIVEL.
- Analizador: **`tools/analysis/stats_watch_summary.py <hh_drwatch.log>`** (agrupa por campo y por
  función escritora; decodifica el word-swap).
- Referencia en `docs/workflows.md` §6.3.
- La página STATUS (`func_80387A20`, `funcs_73.c:9875`; llamador `func_8014A234`,
  `funcs_57.c:6667`) y los candidatos `func_8022CAFC`/`func_80378F64`/`func_80376D48` se contrastan
  con el escritor real.
- Para el editor: los `+0x40..+0x46` (ATRIBUTOS) y los contadores (ESTADO) ya son editables; la
  recomputación automática **no** debe implementarse hasta tener la fórmula confirmada
  (regla `AGENTS.md`: no inventar fórmulas).

### 5.1 Primera captura (2026-09-28): NEGATIVA — `0x8017DC40` no es el struct vivo

Prueba corta jugada (10 min) con el set `stats` (`HH_DRWATCH=0x8017DC40,0x8017DC80,0x8017DC84,
0x8017DC88`). `hh_capture_stderr.log` confirma `[DRWATCH] 4 watchpoint(s) de hardware armados`, pero
**no se creó `hh_drwatch.log`**: ninguna de esas 4 palabras cambió en toda la sesión. Conclusión
`[MEDIDO]`: **el struct del jugador en partida NO está en `0x8017DC40`**; ése es el template/registro
del save (lo que copia `func_80144E68` al cargar). El HP de combate no vive ahí.

Indicios de dónde vive el struct vivo:
- `func_80387A20` (subida de stat) recibe su base como `a0 = *(0x801C0000-0x4334) = *(0x801BBCCC)`
  (puntero en el bloque de progresión `+0xDC`), y escribe `a0+0x40/+0x42/+0x46` (`func_8014A234`,
  `funcs_57.c:7401-7404`).
- `func_8022CAFC` (composición de party) escribe stats compuestas en `a3`, que es `0x801BC03C`
  (`= 0x801BBBF0+0x44C`, la misma dirección donde `func_80376D48` reparte HP) o `0x801BC3D8`
  (`= 0x801C0000-0x3C28`). [MEDIDO]
- ⇒ La captura incluye ahora **`HH_TRACE`** sobre esas funciones (`hh_trace.log` dará los `a0`
  reales de cada llamada) y un set `live` que vigila el HP de las dos party (`0x801BC03C`,
  `0x801BC3D8`) y su `+0x4C/+0x4E` (DEFENSE compuesta).

Siguiente: `run_stats_capture.bat combat`. Como `0x8017DC40` es el buffer del save (solo se vuelca al
guardar), la captura ahora **traza las funciones de combate** (`file_057`, `0x80358820..0x8038CFC0`):
`HH_TRACE` sobre `func_803840A4` (battle_end), `func_80376D48` (hpdist), `func_8037865C` (level),
`func_80378F64` (cnt2stat), `func_80378D84/80378E3C` (part), `func_80387A20` (statgain),
`func_8022CAFC/8022C7A4` y varias `func_8037Ax` de HP; `HH_CANARY` sobre `0x8017DC40:9E` y los party
`0x801BC03C:9E`/`0x801BC3D8:9E` (detecta cambios de cualquier palabra); y `HH_DRWATCH` sobre
`0x8017DC40/+0x04/+0x10/+0x1C`.
`func_803840A4` (`funcs_52.c:33540`) es la clave de fin de combate: copia stats del jugador al ente
(`a0+0x90..+0x9A`) y llama a `func_80376D48`, que reparte HP y **escribe `0x8017DC40+0x06`** en cada
llamada (y `+0x00/+0x02/+0x04` al subir). Por eso el watch anterior (`+0x40..`) no veía nada: hay que
mirar `+0x04/+0x06` y los contadores.

### 5.2 Segunda captura (2026-09-28): **CONFIRMA la fórmula** `[MEDIDO]`

`HH_CANARY` capturó, en una partida real, exactamente los cambios del handoff. Ejemplos:

| evento | cambio en `0x8017DC40` | nivel de parte que subió |
|---|---|---|
| vi=22343 | HP `100→105` (+5) y DEFENSE `50→74` (+24) | `+0x04` HP `0→1` y `+0x53` DEF `0→1` |
| vi=29923 | HP `105→115` (+10), OFFENSE `50→86` (+36), DEFENSE `74→80` (+6) | `+0x04` `1→2`, `+0x52` `0→1`, `+0x53` `1→2` |

El escritor es **`func_80376D48`** (`funcs_74.c:42045-44396`), llamado al acabar el combate desde
`func_803840A4`. `HH_DRWATCH` **no disparó** ni una vez en las dos sesiones (los watchpoints de
hardware no son fiables aquí); `HH_CANARY` sí. Ver §6 para la fórmula.

## 6. FÓRMULA CONFIRMADA: subida de stats por partes `[MEDIDO]`

`func_80376D48` recorre **6 atributos independientes**. Cada uno tiene su propio **nivel**, su
**progreso/EXP** y su par de tablas (umbral, incremento) en `0x80388410` (separadas `0xC6`):

| atributo | stat | nivel | progreso | umbral | incremento (`0x80388410+`) |
|---|---|---|---|---|---|
| HP | `+0x00`,`+0x02` | `+0x04` | `+0x06` | `0x630`→`80388A40` | `0x6F6`→`80388B06` |
| STAMINA | `+0x08` | `+0x0A` | `+0x0C` | `0x7BC`→`80388BCC` | `0x882`→`80388C92` |
| OFFENSE | `+0x40` | `+0x52` | `+0x4A` | `0x0`→`80388410` | `0xC6`→`803884D6` |
| DEFENSE | `+0x42` | `+0x53` | `+0x4C` | `0x18C`→`8038859C` | `0x252`→`80388662` |
| REFLEX | `+0x46` | `+0x55` | `+0x50` | `0x4A4`→`803888B4` | `0x56A`→`8038897A` |
| SPEED | `+0x44` | `+0x54` | `+0x4E` | `0x318`→`80388728` | `0x3DE`→`803887EE` |

Tablas de **incremento** (u16 BE, primeras 14 entradas):

```
HP      80388B06: 5,10,10,15,15,15,20,20,20,20,25,25,25,25,...
STAMINA 80388C92: 2,2,2,2,2,2,2,2,2,4,4,4,4,4,...
OFFENSE 803884D6: 36,8,8,6,7,6,6,5,6,6,5,6,5,5,...
DEFENSE 80388662: 24,6,6,4,5,4,4,5,4,4,4,4,4,4,...
REFLEX  8038897A: 4,1,1,1,1,1,1,1,1,1,1,1,1,1,...
SPEED   803887EE: 10,5,5,6,6,6,6,7,7,7,7,8,8,8,...
```

Umbrales (primeras 14 de cada, en `0x80388410+`):

```
HP      @80388A40: 2,3,5,6,8,10,12,14,16,19,21,24,28,31,...
STAMINA @80388BCC: 11,17,23,30,38,46,54,63,73,83,95,107,119,133,...
OFFENSE @80388410: 51,79,108,139,171,204,240,277,316,357,400,445,492,542,...
DEFENSE @8038859C: 24,37,51,65,81,97,115,133,153,174,196,219,244,270,...
REFLEX  @803888B4: 5,8,11,14,17,21,25,30,34,40,45,51,58,65,...
SPEED   @80388728: 108,165,225,287,351,418,487,560,635,713,795,880,968,1059,...
```

### Algoritmo (por atributo)

Al final de cada combate, `func_803840A4` → `func_80376D48`:

```
para cada atributo A:
    # 1) gana progreso/EXP (normalizado por el stat actual: rendimientos decrecientes)
    gano = round( rewardA * referenciaA / stat_actual(A) )        # aprox. (ver nota)
    progresoA = min(progresoA + gano, 0xFFFF)
    # 2) sube de nivel mientras el progreso alcance el umbral
    tope = 0x4F/0x59/0x63 (func_80376D10 según dificultad)
    mientras (nivelA < tope) y (progresoA >= umbralA[nivelA]):
        stat(A)      += incrementoA[nivelA]
        nivelA       += 1
        copia_runtime(A) ... (HP tambien suma a 0x801BBBF0+0x44C/+0x44E)
```

- `rewardA` = u16 en `*(0x801BBBF0+0xB1C) + {0x08,0x0A,…}`; `referenciaA` = stat correspondiente
  del **otro miembro de party** (`0x801BC3D8+{0x00,0x08,…}`). `[MEDIDO el acceso; significado INFERIDO]`
- El stat se topea en `0x270F` (9999); el progreso en `0xFFFF`.
- Los `level`+`progress` por atributo son justo los 6 campos del **nivel global** (`+0x04,+0x0A,
  +0x52,+0x53,+0x54,+0x55`).

### Respuesta a "por qué sube HP al subir DEFENSE/nivel global"

**No hay dependencia: es correlación.** `func_80376D48` **no lee `+0x48` (nivel global) ni suma HP
desde el bloque de DEFENSE**. El HP sube **solo** cuando sube **su propia parte** (nivel `+0x04`),
sumando `incremento_HP[nivel]` (5,10,10,…) a HP y HPmáx. Lo que ocurre es que en un mismo combate
**varias partes ganan progreso a la vez**, así que es frecuente que suban HP y DEFENSE juntas; y como
el **nivel global es la media de las 6 partes** (`func_8037865C`), también sube como **consecuencia**,
no como causa.

Barrido de TODAS las lecturas de `+0x48` (`0x8018-0x2378`) en el C recompilado: solo
`func_80141268` (cabecera de la lista de partidas, `funcs_56.c:24775/24948`), una copia de campos en
`func_8022CAFC` (`funcs_60.c:37052`, `lwl t8+0x48`) y cargas float con base `0x801F`/`0x8026`
(no relacionadas). **Ninguna fórmula de stat lee el nivel global.** ⇒ subir el nivel a mano sin tocar
las partes (lo que hacía la auto-escala retirada) **no sube ninguna stat**; la causalidad es
`parte sube → su stat sube → y por eso la media (nivel) sube`.

Verificación con la captura: DEFENSE `+24` = `incremento_DEF[0]` (`0x80388662[0]=24`); HP `+5` =
`incremento_HP[0]` (`0x80388B06[0]=5`); siguiente HP `+10` = `[1]`; OFFENSE `+36` = `[0]`; etc.
Todo cuadra.

## 7. Offsets del SAVE vs RUNTIME: discrepancia por resolver `[PENDIENTE]`

El editor opera sobre el **`.pak`** (slot) y hasta ahora asumía **save[o] = runtime[o]** (el
deserializador `func_80144E68` copia en crudo 0x9C B del buffer a `0x8017DC40`). Pero al volcar el
`.pak` real (`build/windows/bin/Release/saves/hh.us.bin.pak`, base de slot 0 = file `0x11B` =
`kDataOff(0x1B)+kHeaderSize(0x100)`, u16 LE) aparece una **posible discrepancia de +2 B**:

| campo | runtime | `.pak` | coincide? |
|---|---|---|---|
| HP / HPmax | `+0x00`/`+0x02` | `0x00`/`0x02` (100/100) | sí |
| STAMINA | `+0x08` | `0x0A` (100) | **no (+2)** |
| contadores off/def | `+0x10..+0x25` | `0x10..0x25` (=1) | sí (valores ambiguos, todos 1) |
| OFFENSE/DEFENSE | `+0x40`/`+0x42` | `0x40`/`0x42` (50/50) | ambiguo (ambos 50) |
| SPEED/REFLEX | `+0x44`/`+0x46` | `0x44`/`0x46` (100/100) | ambiguo (ambos 100) |
| NIVEL (runtime `+0x48`) | `+0x48` | editor lee `0x4A` (1) | **+2** |
| `+0x54` / `+0x58..0x5E` | ? | 30 / 40×4 | — |

Comparando el `.pak` con los valores runtime de la captura **de la MISMA partida** (`HH_CANARY`,
vi=40) sale la explicación: **el save va 32-bit word-swapped** respecto al runtime. En cada palabra de
4 B, las dos mitades de 16 B están **intercambiadas**:

- runtime `+0x54`=0 / `+0x56`=30 ↔ `.pak` `0x54`=**30** / `0x56`=**0** (intercambio claro)
- runtime `+0x08`=100 (STAMINA) ↔ `.pak` `0x0A`=100; runtime `+0x48`=1 (NIVEL) ↔ `.pak` `0x4A`=1

Regla: leer el u16 runtime de offset `r` con `rd16le` en el offset de save **`r ^ 2`** (bytes: `r ^ 3`).

### CORREGIDO en el editor (2026-09-28) `[CONFIRMADO por el mantenedor]`

El mantenedor hizo el test (OFENSIVO=77/DEFENSIVO=11): el juego mostró **DEFENSE=77/OFFENSE=11**, y
confirmó además que **CABEZA↔CUERPO** y **BRAZO IZQ↔DER** (y probablemente HIT/DAMAGE) salían
invertidos. Es decir: los offsets del editor leían la mitad de 16 B contigua de cada palabra. Regla
aplicada en `save_edit.cpp`: `swap16(r)=r^2` (u16), `swap8(r)=r^3` (u8). Offsets **runtime**:
- HP `+0x00`→save `0x02`; HPmax `+0x02`→save `0x00`; STAMINA `+0x08`→save `0x0A`.
- OFFENSE `+0x40`→save `0x42`; DEFENSE `+0x42`→save `0x40`; SPEED `+0x44`→save `0x46`; REFLEX `+0x46`→save `0x44`.
- Contadores `+0x10+part*2` / `+0x1C+part*2` / `+0x68` / `+0x76` → `swap16`.
- NIVEL `+0x48`→save `0x4A` (ya coincidía).

### Editar nivel/progreso por parte (implementado)

Con los offsets ya correctos se puede editar **nivel** (`swap8` de `+0x04,+0x0A,+0x52,+0x53,+0x55,+0x54`)
y **progreso** (`swap16` de `+0x06,+0x0C,+0x4A,+0x4C,+0x50,+0x4E`). `add_part_levels()` aplica la tabla
real (`stat += incremento[nivel]`, y a HP máx si es la parte 0) y recalcula el nivel global del save.
En el editor: pantalla **ESTADO → NIVEL / PROGRESO**. El **NIVEL global** es de solo lectura
(derivado).

## 8. Penalización de DEFENSE (dificultad dinámica) — lead `[MEDIDO / INFERIDO]`

La comunidad (GameFAQs) dice: *"cuanta más DEFENSE, más OFFENSE tienen los enemigos; la OFFENSE escala
más rápido que la DEFENSE en la fórmula de daño → subir defensa es contraproducente"*.

MEDIDO en `func_8022CAFC` (`funcs_60.c:36306`): compone un combatiente con los campos **cruzados**:
- `a3+0x4E` (OFFENSE del ente) = `DEFENSE_jugador(+0x42) × u8(tabla[+0x0E]) / 100` (`funcs_60.c:36588-36639`)
- `a3+0x50` (DEFENSE del ente) = `OFFENSE_jugador(+0x40) × u8(tabla[+0x12]) / 100` (`funcs_60.c:36663-36716`)
Tabla de partes `0x8023C940` (stride `0xA0`, `funcs_60.c:36375`). La fórmula de daño `func_80230DD4`
(`funcs_62.c:9366`) es una **resta** `max(0, Of(atacante) − Def(defensor)) · modificadores` (`Of` de
`func_8022DB40` usa `+0x4E`; `Def` de `func_8022F0E0` usa `+0x50`), no una razón.

INFERIDO: si el ente compuesto es el RIVAL, subir DEFENSE sube su OFFENSE (rubber-banding). **No
confirmado**: la identidad del ente y los coeficientes `u8(tabla+0x0E/+0x12)` de cada fila. Pendiente
de oráculo antes de documentarlo como mecánica.
