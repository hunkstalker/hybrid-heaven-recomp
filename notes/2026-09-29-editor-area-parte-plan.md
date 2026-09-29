# 2026-09-29 — Editor de partida: Área-Parte real y arranque desde un punto (plan + mediciones)

> Sesión `menu-edicion-partida`. Punto de partida: `RETOMAR.md` §1 (tarea principal) y
> `notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md` (formato del slot).
> Regla: cada dato marcado `[MEDIDO]` (código generado/`.pak`/runtime) o `[INFERIDO]` (lectura del
> desensamblado, sin ejecutar).

### Resumen de la sesión (2026-09-29)

1. **La lista actual del editor (`1-0..1-9` para el área 1) es incorrecta** (dato del mantenedor:
   el área 1 solo tiene 1-0/1-1/1-2; en total hay **10 áreas**... ver §2bis sobre la numeración).
2. **`PROGRESO` (`0x366`) NO se guarda como `N*10+P`**: medido en 4 slots reales, guarda `P`
   (punto) y **en 1-1 y 2-1 ambos valen 1**; el **área va en OTRO campo** (§2). Por eso el editor
   actual escribe mal el área.
3. El **bloque de estado** que se copia al slot `0x364+` es una **copia de 512 B de `0x801BED38`**
   (no de `0x801BBBF0` directamente), y su **base dentro del slot es fija `0x364`** (el bloque
   variable mide 0 en los `.pak` medidos). `PROGRESO` cae en `0x366`.
4. **La tabla `D_80175490`** es de **escenas** (224 punteros), no la lista curada de "puntos de
   guardado usables". La curada es **`D_801DC930`** (56 valores) — de otro modo (demo/DataEdit).
5. **Validado headless**: `func_801423C8(0, slot)` carga el slot vía PFS + deserializa y devuelve 0;
   la PFS virtual lee el `.pak` copiado a `build/linux/saves/`. Instrumentación nueva:
   `HH_SAVEEDIT_LOADTEST=1` (+ `HH_SAVEEDIT_SLOT`), `HH_SAVEEDIT_DUMP=1`.

## 0. Objetivo

Que `EDICIÓN DE PARTIDA → PROGRESO` liste las **Áreas-Partes reales** y que `CONTINUAR` (o un "JUGAR")
cargue de verdad ese punto. **Pregunta añadida del mantenedor (2026-09-29)**: tras identificar qué
niveles existen, investigar **si el juego permite seleccionar el comienzo de un nivel N-1 o un punto de
guardado x-N** para cargar y arrancar la partida desde ahí.

## 0. Objetivo

Que `EDICIÓN DE PARTIDA → PROGRESO` liste las **Áreas-Partes reales** y que `CONTINUAR` (o un "JUGAR")
cargue de verdad ese punto. **Pregunta añadida del mantenedor (2026-09-29)**: tras identificar qué
niveles existen, investigar **si el juego permite seleccionar el comienzo de un nivel N-1 o un punto de
guardado x-N** para cargar y arrancar la partida desde ahí.

## 1. Lo que YA está medido/inferido (base de partida)

`[MEDIDO]` del desensamblado de la imagen (pipeline ELF; `build/recomp/elf/hybrid-heaven.us.elf`):

- **`D_80175490`** es una tabla de **300 punteros** (30 filas × 10) en `.bss`, **rellenada en runtime**
  (en el ELF son ceros). Acceso genérico: `lui $2,0x8017; addu $2,$2,idx*4; lw $2,0x5490($2)`.
  → **se indexa DIRECTAMENTE por el valor** `idx` (0..299), no por `(fila, columna)` separados.
  Entradas no nulas por fila (contadas del contraste con `kFallback`): `[7,10,9,9,10,8,6,9,6,9,6,
  10,10,10,10,10,10,10,10,7,5,10,1,1,8,10,10,1,1,1]` → **224 puntos válidos**.
- Consumidores que indexan la tabla (todos `idx` u16):
  - `func_80125968(idx, flags)` → **carga de escena** (recorre el record apuntado).
  - `func_801262D4(idx, ·)`, `func_801266B8(idx, ·)`, `func_80126198(rec, ·)`, `func_80126570`.
  - Record apuntado (16 B; runtime): `+0x0` puntero (a otro bloque), `+0x4` u32 (mask 0xFFFFFF),
    `+0x8` u16 (¿nº?), `+0xC` puntero (array). **Contenido no volcado aún** (BSS).
- `notes/2026-09-27-e-editor-partida-plan.md` §2: los scripts de transición llaman a
  **`func_8012FE50(tipo, N*10+P, …)`**; `func_80125968` carga la escena. → **existe una vía interna
  para arrancar/acceder a un (N,P) por valor** (base para "JUGAR"/warp, Fase 2).

### 2bis. Estructura del área/subnivel y `PROGRESO` `[MEDIDO 2026-09-29]`

- **Datos del mantenedor**: solo hay **10 Áreas**; **cada Área tiene un `N-0`** (el inicio/punto 0);
  el área 1 tiene **1-0, 1-1, 1-2** (3 puntos); los subíndices son **subniveles** dentro del área
  (no un rango de 10). → La lectura del editor ("30 niveles × 10 puntos") es incorrecta; `PROGRESO`
  NO son 224 entradas.
- **`PROGRESO` (`0x366`, u16 BE) = `(área + 1) × 10 + subnivel`**, donde:
  - `subnivel` = 0..2 (área 1: 1-0, 1-1, 1-2). 1-1 → `11`; 1-2 → `12`; 1-0 → `10`.
  - **1-1 se guarda como `11`**, y **2-1 como `21`** (verificado con los slots reales de 1-1/1-2).
  - **NO es `N*10+P` con N mostrado** (=1): es `(N+1)*10 + P`. (Con la fórmula del editor, `1-1`
    daría `11` ✓, pero `2-1` daría `21` ✓ y no `1`.)
- **Medición dura** con el `.pak` del mantenedor (4 slots, cabecera bswapped):
  `slot0` AREA 1-1 `PROG=11`; `slot1` AREA 1-1 `PROG=11`; `slot2` AREA 1-1 `PROG=11`; `slot3`
  AREA 1-2 `PROG=3`**¡!** ese slot está **a medio camino** (guardado in-game en 1-2 pero con
  `PROG=3` en el bloque). ⚠️ El `PROGRESO` del bloque **se actualiza en el siguiente guardado**; el
  campo que **CONTINUAR** lee para el mapa puede no ser este. **Pendiente**: confirmar con un save
  limpio en 2-1.
- **Cabecera** (registro del slot, bswap): `+1` AREA N, `+2` AREA P. `save()` la actualiza; de ahí
  salen el **texto** y la lista `DATA LOAD`.
- **Bloque de estado** (copiado a `0x364`): `func_80141F28` copia 512 B desde **`0x801BED38`**
  (mirror word-swapped; NO de `0x801BBBF0` directamente) y lo escribe **desde `0x364` fijo** (el
  bloque variable mide 0 en los `.pak` medidos). `PROGRESO` cae en `0x366`. El byte `0x57F` = **TIME**
  (segundos) de la cabecera, NO área.

`[MEDIDO]` del deserializador al cargar: `func_801423C8(0, slot)` → `PFS read(slot*0xD00+0x100, 0xD00)`
→ `func_80141D08(buffer)`. Checksum del slot: `func_80141D08` lo valida en `buffer[0xCFF]` =
`sum(0..0xCFE)`; como el bloque del save va word-swapped, en el **fichero** cae en `0xCFC` =
`sum(0..0xCFB)` (lo que ya usa el editor). El buffer volcado confirma la correspondencia.

## 2quater. Validación del mantenedor (2026-09-29) — diagnóstico del fallo

Prueba: `GUARDAR` en el slot 4 tras editar a 2-1. Resultado: la cabecera sale **1-1**, `CONTINUAR`
carga y el cartel del nivel sale **con artefactos** y luego **pantalla negra** (no carga nivel).

Datos medidos del `.pak` resultante (`build/windows/bin/Release/saves/`):

- Log: `GUARDAR destino=4 slot=3 progress=0 level=0` → `set_save_edit_save_target(4)` →
  `save_edit_save_target_slot()` = **3** (el slot destino estaba VACÍO; `progress_of(3)=0`).
- `save()` escribe el **slot 3 vacío** (todo 0), recalcula checksum y **deriva la cabecera del slot**
  (`update_save_header(3)`: prog=0, level=global_level_of=0) → `AREA 0-0`; luego el juego lo muestra
  como **1-1** (el valor 0 se mapea a 1-1). Nada que ver con lo editado (el editor editaba el **slot
  seleccionado**, no el destino).
- `slot0` del `.pak` tiene `PROG=20` en el bloque (`0x366`), pero su **cabecera dice 1-1**: la
  cabecera quedó **desincronizada** (el editor/`save()` no la cuadró con el bloque). `slot1`/`slot2`
  sí están coherentes: cabecera 1-1 y `PROG=11` → **`PROGRESO` (`0x366`) = `area*10+sub`; 1-1 = 11**.
  El `20` de slot0 sería 2-0, pero **no cuadra con su cabecera** → a esclarecer (quizá slot0 es un
  save previo a la prueba). Diff del bloque entre slot0 y slot1: solo cambian `0x366` y unos bytes de
  records internos (`0x387`, `0x477`, `0x487`… = `03`↔`0b`, un campo por-partida), más `0x56E`/`0x572`.

**Causa raíz del fallo**: el editor v3 escribe el slot **a mano** (progreso/nivel/técnicas/items) pero
**NO** los stats del personaje ni el resto del estado. Un slot **existente** conserva sus stats; un
slot **vacío** queda con stats 0 → el juego no puede montar la escena (cartel roto + negro). La
prueba no mide el mapa: mide que el guardado por slot vacío está incompleto.

**Arreglo propuesto (a confirmar con el mantenedor)**: al `GUARDAR`, partir del **estado vivo** del
personaje (globals ya cargados: `0x8017DC40` stats, técnicas, items, `0x801BBBF0`/`0x801BED38`
estado) y **serializar** el slot destino con la lógica del juego (o copiar un slot poblado y editar
encima), en vez de escribir solo unos campos sobre cero. Alternativas: (a) **clonar** el slot de
origen y editar progreso; (b) llamar al **serializador nativo** `func_80141F28` con los globals
vivos (vía v2 de la nota 2026-09-27-e); (c) rellenar stats desde el slot de origen al crear uno
nuevo. El progreso/área ya es correcto (`0x366`).

### 2octies. CAMPO DEL MAPA LOCALIZADO: `0x564` (u16 LE) `[MEDIDO/VALIDADO headless]`

**Hallazgo central**: el campo que decide el mapa NO es `0x366`. Es **`0x564`** dentro del slot,
**u16 LITTLE-ENDIAN**, que el deserializador vuelca a `glob 0x801BBBF0[+4]` (= `valor` de
`func_8012FE50` / `idx` de `func_80125968`).

Prueba (slot 1-1, `[+4]=0`, `0x564=00 00`):
- Escribir `0x564 = 0x0a 00` (LE = 10) → `[+4]=10` ✓ (verificado con `HH_SAVEEDIT_LOADTEST`).
- Escribir BE (`00 0a`) daba `[+4]=0x0A00=2560` → confirma que es **LE**.
- Clonar un slot 1-2 (`0x564=0a 00`) a slot 0 → `[+4]=10` ✓.

Medición previa: slot 1-1 → `0x564=00 00`; slot 1-2 → `0x564=0a 00`. Bytes `0x370`/`0x380` (que también
valían 0/10) NO mueven `[+4]`; solo `0x564`.

**Relación Área-Parte ↔ `0x564` (a completar)**: 1-1=0, 1-2=10. (La traza del flujo CONTINUAR daba
`valor=0` para 1-1 y `valor=10` para 2-1; hay que reconciliar con más puntos, p. ej. 2-1 y 1-3.)
El editor debe escribir **este** campo (y mantener la cabecera coherente). El bloque `0x364` es
`bswap32` en RAM; dentro de él, `0x564` corresponde al final del bloque de 0x200.

### 2septies. ÍNDICE de escena medido (traza `[scene]`) `[MEDIDO]`

Traza `HH_SCENE_TRACE=1`. Al cargar/entrar, el juego llama
`func_8012FE50(tipo, valor)` → `func_80125968(idx=valor)`, y `glob 0x801BBBF0[+4]` = ese `valor`.

Datos medidos (5 casos, todos reales):

| Área-Parte | `tipo` | `idx` (= `[+4]`) |
|---|---|---|
| **1-0** (inicio) | **15** | **0** |
| 1-1 | 24 | 0 |
| 1-2 | 24 | 2 |
| **2-0** (inicio) | **15** | **10** |
| 2-1 | 24 | 10 |

- **Aclaración (mantenedor)**: **1-0 y 2-0 NO se pueden guardar** (son el inicio del nivel); un slot
  de save **nunca** los registra. Los `tipo=15` de 1-0/2-0 son **transiciones de nivel durante el
  gameplay** (al cruzar de área), que **no leen el índice del save** → por eso 1-0 dio el mismo `idx`
  que 1-1, y 2-0 el mismo que 2-1. **No son un caso del editor.**
- Por tanto, para `PROGRESO` de un slot, la lista relevante es **solo los puntos de guardado**
  (los `tipo=24`): 1-1, 1-2, 2-1, … **sin** 1-0/2-0.
- Puntos de guardado (`tipo=24`): 1-1=0, 1-2=2, 2-1=10. `idx = (área-1)*10 + (sub-1)*2` con `sub`
  1-based sobre los guardados del área (1-1→0, 1-2→2) — a confirmar con más puntos.
- `[+4]` (u16) del bloque `0x801BBBF0` es el campo que decide el mapa; `func_80141D08` lo escribe al
  deserializar y `func_8012FE50`/`func_80125968` lo consumen. **Falta**: qué offset del `.pak`
  alimenta `[+4]` (el editor escribía `0x366`/`0x376` = 11/3, que NO es este índice).
- **Función aparte (deseable, Fase 2 "JUGAR")**: arrancar en el **inicio** de un nivel (1-0/2-0/…) no
  se hace editando un slot, sino **forzando una transición de nivel** (`func_8012FE50(tipo=15, …)`)
  tras cargar. Es lo que permitiría "viajar" al inicio de cada área sin guardar.
  - **Receta decidida (mantenedor 2026-09-29)**: si se quiere que un slot "sea" 1-0/2-0, **forzar la
    transición** al cargar. `idx` de inicio medido: **1-0→0, 2-0→10** = `(área-1)*10` (es la misma
    mecánica que usa el juego al cruzar de área, `tipo=15`). NO se puede escribir en el slot (no hay
    punto de guardado válido); hay que inyectarla post-carga como si fuera el cambio de nivel.
  - **DECISIÓN FINAL (mantenedor 2026-09-29)**: para viajar a **cualquier** Área-Parte (incluidos
    1-0/2-0) **NO** hacerlo editando el slot + `CONTINUAR`. La vía es **inyectar la transición**
    `func_8012FE50(tipo=15, idx)` con la partida viva (o tras cargar una). Un botón **`JUGAR EN
    <Área-Parte>`** en el editor: llama a la transición con el `idx` del punto elegido. Así:
    - Inicios: `idx = (área-1)*10` (1-0→0, 2-0→10).
    - Puntos de guardado: `idx = (área-1)*10 + (sub-1)*2` (1-1→0, 1-2→2, 2-1→10).
    El editor de `PROGRESO` del slot queda solo para puntos guardables; el warp es transición directa.

### 2sexies. Evidencia dura de `.pak` (cabecera vs bloque) `[MEDIDO 2026-09-29]`

Comparando 4 slots de 3 `.pak` reales (cac + 2 copias), con cabeceras bswapped:

| fichero | slot | cabecera | `0x366`(BE) | `0x376`(BE) |
|---|---|---|---|---|
| cac | 0 | 1-1 | 11 | 11 |
| cac | 1 | 1-1 | **3** | **3** |
| win | 0 | 1-1 | **20** | 11 |
| win | 1 | 1-1 | 11 | 11 |
| win | 2 | 1-1 | 11 | 11 |

- Hay **dos campos gemelos** (`0x366` y `0x376`, separados 0x10) que suelen valer lo mismo.
- **La cabecera dice 1-1 mientras `0x366` vale 20** (win slot0): **cabecera y bloque divergen**.
  → El `PROGRESO` "real" del mapa puede ser `0x366`, y la cabecera (que el editor ya actualiza) es
  solo el rótulo. **Pero** no se ha confirmado cuál usa `CONTINUAR`.
- `0x366=3` en cac slot1 (cabecera 1-1) es otro valor "raro" → probablemente el **subnivel**
  (punto) 0-based, mientras el área va aparte.
- **Escribir `0x366` (u16 BE) en un `.pak` bueno y cargar con el loadtest NO movió el `PROGRESO`
  runtime** (probado 0x364..0x372; solo `0x368` movió un campo vecino) → el deserializador lee esos
  campos de forma **transformada** (`func_8014B8DC`), no directa. La correspondencia exacta
  archivo→runtime queda **abierta**.

### 2quinquies. Cómo LEE el juego el bloque de estado `[MEDIDO del C + runtime]`

- `func_80141D08` (deserializador) copia **0x200 B desde `file[0x364]`** a **`0x801BED38`**
  (`func_8014C294` devuelve `0x801BED38`; `func_8014C2A0` devuelve `0x200`) — NO a `0x801BBBF0`
  directo. Después construye el bloque visible en `0x801BBBF0` leyendo desde ese mirror.
- La correspondencia **offset-de-archivo → offset-runtime** (`sh[+X]`) es de la forma
  `sh[+X] = (f[a]<<8)|f[b]` (big-endian de dos bytes del archivo), pero **el offset `a` NO es
  simplemente `X`** (hay un desfase y un `func_8014B8DC` de por medio que transforma el bloque de
  100 B). Por eso escribir `PROGRESO` en `0x366` **no** mueve el `PROGRESO` runtime como esperaba.
  **Pendiente**: mapear byte a byte con el volcado (`+360` del buffer vs `0x801BBBF0` runtime) qué
  offset de archivo alimenta `sh[+4]` (`PROGRESO`). Con `.pak` reales de 1-1/1-2 (11/12) y 1-0 (10)
  el diff lo fija de inmediato.
- El editor actual usa `0x366` (u16 **BE**) para `PROGRESO`. En los `.pak` reales 1-1 = `00 0b` = 11
  BE, o sea **escribir BE parece correcto**; lo que falla es que el **deserializador** puede no leer
  ese offset directo. **Confirmar empíricamente** con el loadtest.

## 2ter. El problema actual, acotado

`EDICIÓN DE PARTIDA → PROGRESO` (que escribe `+0x366`) **sí cambia el TEXTO** (cabecera) **pero no el
MAPA**. El campo que decide el mapa sigue sin identificar con certeza; candidatos:

- **A**: el propio `PROGRESO` (`0x366`), pero `CONTINUAR` lo lee de otro sitio (el deserializador
  `func_80141D08` lo escribe en `0x801BBBF0+4`; si CONTINUAR usa **`0x801BED38`** —el mirror que
  `func_80141F28` vuelca al slot— habría que ver cuál es el vivo y cuál el mirror).
- **B**: la cabecera por sí sola (el texto cambió pero el cargador de escena usa el slot).
- **C**: un campo del bloque `0x300..0x363` (flags de historia, `0x8008DC20`).

**Verificación pendiente (necesita save limpio en 2-1)**: comparar `PROGRESO`/campos del slot entre
1-1/1-2 y 2-1 y ver cuál cambia con el área. El `.pak` actual tiene el 4º slot a medias (guardado en
1-2 con `PROG=3`), así que **no cierra** el caso. Se pide un save **limpio** en 2-1 (o 3-x).

Método fiable y barato: **oráculo/diff sobre `.pak` reales** — guardar en dos Áreas-Partes distintas
con el juego real y comparar los slots (qué offsets cambian con la zona). Ese(s) campo(s) es el que hay
que escribir para que cargue donde toca.

## 3. Instrumentación añadida (esta sesión)

- `HH_SAVEEDIT_LOADTEST=1` (+ `HH_SAVEEDIT_SLOT=<n>`, def. 0): en el primer frame de título llama a
  `func_801423C8(0, slot)` (carga nativa de slot) para poblar los globals sin mando. En headless
  funciona (ver más abajo); en Windows sirve igual.
- `HH_SAVEEDIT_DUMP=1`: engancha `func_80141D08` y vuelca a `hh.log` el **buffer 0xD00** entrante
  (layout exacto), la tabla `D_80175490` (records), `0x801BBBF0` y el bloque **`0x801BED38`** (512 B,
  la fuente real que se copia al slot). Solo diagnóstico.
- **Headless validado**: `HH_OVERLAY=1 HH_SAVEEDIT_LOADTEST=1 HH_SAVEEDIT_DUMP=1 HH_SAVEEDIT_SLOT=0`
  con el `.pak` del mantenedor copiado a `build/linux/saves/` y START a ~62 s → `func_801423C8`
  devuelve 0 y el buffer volcado coincide con el slot del `.pak` (mismo layout, byte a byte). La PFS
  virtual lee el fichero de `saves/`. Evidencia: `notes/reference/saveedit/`.

## 4. Plan (pasos numerados)

1. [x] **Volcado runtime** (`HH_SAVEEDIT_DUMP`): tabla + records + bloque `0x801BED38` + buffer.
2. [x] **Codificación de `PROGRESO`**: `(área+1)*10 + subnivel` (§2bis). Reescribir la UI para listar
   **(área, subnivel)** con los subniveles **reales** por área (área 1: 0..2) — ver §5.
3. [ ] **Campo de carga (mapa)**: cerrar con un **save limpio en 2-1** qué campo cambia con el área
   (§2ter). Determinar si `CONTINUAR` usa `0x801BBBF0` (deserializado) o el mirror.
4. [ ] **Cablear**: al fijar `PROGRESO`, escribir el campo de área coherente y la cabecera en `save()`.
5. [ ] **¿Selector de nivel/punto?**: investigar si el juego expone un selector interno (menú nativo /
   `DATA EDIT`) o construirlo llamando a `func_80125968`/`func_8012FE50` tras cargar (Fase 2 "JUGAR").
   Decidir con el mantenedor **antes** de añadir UI (regla: no inventar UI).
6. [ ] **Validación Windows**: editar → `CONTINUAR` → carga en la Área-Parte elegida (texto y mapa).

## 5. Lista real de Áreas-Partes `[DATO DEL MANTENEDOR 2026-09-29]`

Lista completa (39 puntos), ya cableada en `menu.cpp` (`kAreaParts`):

```
1-0, 1-1, 1-2
2-0, 2-1
3-0, 3-1, 3-2, 3-3, 3-4, 3-5, 3-6, 3-7
4-0, 4-1, 4-2, 4-3
5-0, 5-1, 5-2
6-0, 6-1, 6-2, 6-3, 6-4, 6-5, 6-6, 6-7
7-0, 7-1, 7-2, 7-3
8-0, 8-1, 8-2, 8-3
9-0, 9-1
```

Codificación guardada `[INFERIDO]`: `valor = area*10 + sub` (area 1-based) → 1-1 = `11`, 2-1 = `21`.
Cuadra con la verificación parcial en `.pak` (1-1 = 11, 1-2 = 12), pero **la lista y su codificación
NO están confirmadas**: el `.pak` recibido tenía el 4º slot (2-1) con `PROG=3` (a medias), así que el
caso 2-x **no** está medido. **Es una hipótesis de trabajo** hasta probar `CONTINUAR` en un 2-x.
⚠️ El campo que decide el **mapa** sigue sin identificar con certeza (¿`PROGRESO` u otro?).

`D_80175490` (224 punteros) es la tabla de **escenas** y `D_801DC930` (56) la curada de **otro modo**
(demo/DataEdit); ninguna es la lista de Áreas-Partes de arriba.

## 6. Criterio de validación (Windows)

- El selector `PROGRESO` ofrece **solo** Áreas-Partes existentes (área 1: 1-0/1-1/1-2), sin huecos.
- Tras editar `PROGRESO` y `GUARDAR`, `CONTINUAR` arranca en **esa** Área-Parte: el texto **y** el mapa.
- No se corrompe el `.pak` (checksum 0xCFC correcto) ni se altera el resto del slot.

## 6bis. Implementación (2026-09-29, rama `menu-edicion-partida`)

- **`EXTRAS > ELEGIR NIVEL`** (nuevo submenú, `ScreenId::ChooseLevel`): `CARGAR` / `GUARDAR` /
  `ELIMINAR` (reutilizan las acciones del editor) + separación + **`IR A NIVEL < N-N >`** (lista
  completa, con inicios `N-0`).
- **`IR A NIVEL`** (`Action::WarpToLevel`): inyecta `func_8012FE50(tipo=15, idx)` (la transición del
  juego). `idx` del selector = `warp_value_at()` = `(area-1)*10` (inicio) o `(area-1)*10+(sub-1)*2`
  (guardado). **Siempre habilitado**.
  - Con partida viva → warp directo.
  - Sin partida → escribe la **plantilla** en el primer slot libre, `save()` (recarga el pak) y
    dispara el **CONTINUAR nativo**; el `hh_heaven_load_hook` consume el warp pendiente
    (`request_warp`/`take_pending_warp`) al terminar de cargar.
- **Plantilla base**: `assets/save/template_slot.bin` (0xD00 B), copiada junto al ejecutable en
  `save/` (CMake, como `logos/`). Contenido: clon del slot0 (stats de inicio) con **items = solo
  Map Viewer (39=1) y Defuser (40=1)**. `hh::save::load_template(slot)` la escribe en memoria.
- **`PROGRESO`** (editor): ahora lee/escribe **`0x564` (u16 LE)** = índice de escena
  (`(area-1)*10+(sub-1)*2`), y mantiene `0x366` (BE) sincronizado por compatibilidad. La lista del
  selector son solo puntos de guardado (sin `N-0`).

## 6ter. CICLO DE PUNTOS (mapeo manual) `[IMPLEMENTADO]`

Para mapear a mano qué escena es cada índice de `D_80175490` (checkpoints intermedios además de las
estaciones de guardado):

- **F6** = siguiente índice (0..299, wrap); **F5** = anterior; **Inicio (Home)** = reset a 0. En
  `src/subsystems/input.cpp` -> `hh::menu::cycle_step(±1)` / `cycle_reset()`. (Se retiraron los
  atajos de test F5 idioma / F6 menú nativo / F8 present-early / F9 interpolación / F10 HUD rewrite.)
- El hook por-frame `hh_battle_frame_hook` (0x800021B4) consume la petición -> `run_cycle_step`:
  - Con partida viva: warp directo (`func_8012FE50(tipo=15, idx)`).
  - Sin partida: plantilla -> slot libre -> `save()` -> CONTINUAR nativo + warp pendiente.
- Log: `[ciclo] punto idx=N (fila=F col=C)` en `hh.log`.
- **F10** = **volver al menú** desde gameplay: transición al **idx 7** ("Intro antes del menú",
  `[MEDIDO]`). Es la vía para "salir al menú" (funciona con partida viva).
- **Saltos del ciclo**: `{6, 8}` (cuelgan / negro). Ampliar según se descubra.
- **Mapeo manual `[MEDIDO 2026-09-29]`**:
  - Ciclo 1-en-1 (idx 0..8): `0`=1-1a · `1`=desconocido · `2`=1-2a · `3`=1-2b · `4`=1-1b ·
    `5`=cuelga · `6`=cuelga/negro · `7`=**Intro antes del menú** (volver al menú) · `8`=cuelga.
  - Ciclo de 10 en 10 (F6 desde 0): **`10`=2-0 · `20`=3-0 · `30`=4-0 · `40`=5-0 · `50`=6-0**
    (`60`=3-5a checkpoint · `70`=habitación con puerta (¿7-0?) · **`80`=8-0 · `90`=9-0** ·
    `100`=Demo Play #1 · `110`=negro · `120`/`130`=fases de test/crash).
  - **`0` = 1-0** (confirmado por el mantenedor). **`10`=2-0, `20`=3-0, `30`=4-0, `40`=5-0,
    `50`=6-0, `75`=7-0** (64 y 75 dan el mismo sitio; se usa **75**). **`80`=8-0, `90`=9-0**.
    `100`=Demo Play #1 (fin del juego normal). Rango útil = 0..99; >=100 son extras/demos/test.
  - **Fórmula `N-0 = (N-1)*10`** para N=2..6,8,9; **7-0 = 75** (no 70: el bloque 7 empieza antes).
  - Sub-puntos (`1-1a/b/...`, `3-5a`, ...) frágiles por estado (puertas/cinemáticas): priorizar `N-0`.
  - **`skip_indices.txt`** (junto al ejecutable, editable sin recompilar): `[MEDIDO]` cuelgan
    `5,6,7,8,9, 28,29, 38,39, 57,58,59, 65,66,67,68,69, 73,74, 78,79, 85,86,87,88,89, 98,99`.
- **Uso**: pulsar `[`/`]` y anotar fila/col + a dónde sale el jugador; así se etiqueta cada índice
  (estación `N-N` vs intermedio `N-Na/b/...`). Con eso se puede construir la lista ordenada real.

## 6quater. Slots de punto de guardado aportados por el mantenedor

Registro vivo y cobertura por área: **`reference/saveedit/PUNTOS_DE_GUARDADO.md`**. El mantenedor
aporta `.pak` guardados jugando; sirven para (1) validar el mapeo de `idx`/carga con `CONTINUAR` y
(2) ser las **plantillas** de "mover mi partida a una Área-Parte" (§6bis). Área 1 completa (1-1, 1-2).

## 7. Pendiente / siguiente prueba

- [x] Lista completa de Áreas-Partes (dato del mantenedor): 39 puntos (arriba).
- [x] UI del editor ya lista **esa** lista (no `1-0..1-9`).
- [ ] **Probar en Windows**: editar `PROGRESO` a un `N-P` de la lista, `GUARDAR`, `CONTINUAR` y ver
      si arranca ahí (texto **y** mapa). Con eso se confirma/refuta la codificación `area*10+sub`.
- [ ] Si `CONTINUAR` **no** arranca donde toca, el problema es el **campo de mapa** (§2ter): probar a
      escribir a mano `+0x00`..`+0x1C` del bloque `0x364` con los valores de un save real del área
      objetivo hasta que cargue (método ensayo-error dirigido por el diff).
