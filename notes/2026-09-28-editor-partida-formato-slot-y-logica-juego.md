# 2026-09-28 — Editor de partida: formato real del slot y lógica de juego (stats)

> Sesión `menu-edicion-partida`. Documenta **toda** la lógica de guardado/estadísticas reconstruida
> al depurar el editor v3 (`notes/2026-09-27-f-editor-partida-v3-y-hallazgos.md`). Complementa (no
> sustituye) esa nota. **Regla**: cada dato va marcado como `[MEDIDO]` (verificado contra `.pak` reales
> / código generado) o `[INFERIDO]` (leído del C recompilado, sin ejecutar). No editar notas viejas.

## 1. Por qué esta nota

El editor v3 edita bytes del SLOT del `.pak` con offsets que se midieron comparando ficheros. En
Windows aparecieron fallos: `NIVEL` mostraba `4609` (se escribía en el byte equivocado), los
contadores de parte (`OFENSIVO`/`DEFENSIVO`) mostraban `256` en vez de `1`, la cabecera de la lista de
partidas no se actualizaba y `NUEVA PARTIDA` no creaba slot visible. La causa raíz común es que el
guardado **no está en el orden que parecía** y hay secciones distintas con distinto tratamiento.

## 2. Contenedor `.pak` del port (runtime) `[MEDIDO]`

Lo escribe `lib/N64ModernRuntime/librecomp/src/pak.cpp` (reimplementación del Controller Pak).

- Cabecera del contenedor: `"HHPK"` (4 B) + `uint32 count` (4 B, **little-endian de host**) = `0x08`.
- A continuación, por cada `PakFile`: `used` u8 (1) + `company` u16 (2) + `game` u32 (4) +
  `game_name[4]` + `ext_name[4]` + `size` u32 (4) = 19 B (`0x13`). Primer fichero → **los datos
  empiezan en `0x08 + 0x13 = 0x1B`**.
- El fichero del juego (Hybrid Heaven) mide `0x100 + 4*0xD00 = 0x3500`; el `.pak` total = `0x1B + 0x3500
  = 0x351B = 13595` B. (Verificado en todos los `.pak` reales.)
- `osPfsReadWriteFile` copia bytes **verbatim** (`memcpy`), sin swap.

## 3. Layout del save del juego (los `0x3500`) `[MEDIDO]`

```
offset 0x000 .. 0x0FF : CABECERA de guardado (0x100)  — ver §6
offset 0x100 + i*0xD00 : SLOT i (i=0..3, 0xD00 c/u)   — ver §4/§5
```

Sin slot: los 4 slots van seguidos; el checksum va dentro de cada slot.

## 4. El bloque de PERSONAJE está “byte-swapped” (word-swap / bswap32) `[MEDIDO]`

Prueba dura: el template de personaje del ELF (`build/recomp/elf/hybrid-heaven.us.elf`, offset de
fichero `0x109DC40`) es **byte-idéntico** al slot 0 real (`work/debug/cac/saves_windows/…pak`) **tras
aplicar `bswap32` por palabra** (coinciden los primeros `0x90` bytes). El template del ELF está en
orden normal (big-endian “de struct”), el fichero guardado está intercambiado por palabras.

Consecuencia práctica por sección del slot (así lo lee/escribe hoy el editor, y funciona):

| Sección | Rango (offset dentro del slot) | Orden en el FICHERO |
|---|---|---|
| Struct de personaje | `0x000..0x09D` | `u16` **little-endian** (el struct en RAM es BE; el fichero es bswap) |
| Técnicas | `0x09E + id*3` (86) | bytes (independiente de endianness) |
| Items | `0x1A0 + id` (45) | u8 |
| Bloque “party/otro” | `0x1CD..0x1E6` | ver §5 |
| Copia de 100 B | `0x300..0x363` | de `0x8008DC20` |
| Bloque `u16` de progreso/escena | `0x364..` | **big-endian** en el fichero (ver §5) |

> ⚠️ No es un `bswap32` uniforme de todo el slot: el struct de personaje sale intercambiado, pero el
> bloque de progreso (`0x364+`) va BE normal. Se documenta como observado; el porqué exacto (¿el
> struct en RAM se guarda ya en orden “swap”?) queda **abierto**.

### 4.1 Mapa del struct de personaje (offset dentro del slot; leer `u16` LE) `[MEDIDO]`

Valores de un save de capítulo 1-1 (cac) que coinciden con el STATUS del juego (HP 100/100, OFFENSE
50, DEFENSE 50, SPEED 100, REFLEX 100; contadores por parte 1; nivel 1):

| Offset slot | Tipo | Campo | Valor medido |
|---|---|---|---|
| `0x00` | u16 | **HP** actual | 100 |
| `0x02` | u16 | **HP máximo** | 100 |
| `0x0A` | u16 | **STAMINA** | 100 |
| `0x0C` | u16 | (1) | 1 |
| `0x10` + parte*2 | u16 | **contador OFENSIVO por parte** (6) | 1 |
| `0x1C` + parte*2 | u16 | **contador DEFENSIVO por parte** (6) | 1 |
| `0x40` | u16 | **OFFENSE** (potencia, no contador) | 50 |
| `0x42` | u16 | **DEFENSE** | 50 |
| `0x44` | u16 | **SPEED** | 100 |
| `0x46` | u16 | **REFLEX** | 100 |
| `0x48` | u16 | **NIVEL** | 1 |
| `0x54` | u16 | (30) | 30 |
| `0x58`..`0x5E` | u16×4 | (40,40,40,40) | 40 |
| `0x68` + parte*2 | — | HIT COUNT por parte (en cac = 0) | 0 |
| `0x76` + parte*2 | — | DAMAGE COUNT por parte (en cac = 0) | 0 |

> Los contadores `OFENSIVO`/`DEFENSIVO` son `u16 LE`; leerlos como **BE daba `0x0100 = 256`** (el bug
> reportado). Orden de partes = el del juego (Cabeza, Cuerpo, Brazo Der/Izq, Pierna Der/Izq), a
> confirmar contra la UI nativa.

## 5. Serializer del slot: `func_80141F28` (lo que el juego escribe) `[MEDIDO del C]`

`func_80142450(slot)` → `func_80141F28(buffer_0xD00)` → `osPfsReadWriteFile(WRITE, off=slot*0xD00+0x100, 0xD00)`.

`func_80141F28` vacía el buffer y lo compone (esto da el **layout lógico/estructura**):
1. `func_80144C40(&ptr)` escribe, en este orden:
   - `0x000..0x09D` (0x9E B): copia del struct global **`0x8017DC40`** (+ un `u16` de `0x80181580`).
   - `0x09E..0x19F`: **86 técnicas × 3 B** desde `0x80183CE0 + id*6` (`+0`=aprendida, `+2` (s16)=maestría, `+4`=usos).
   - `0x1A0..0x1CC`: **45 items × 1 B** desde `0x8017E004 + id*8 + 4` (cantidad, tope 99).
   - `0x1CD..0x1E0`: 3 × 7 B desde `0x8017DF14`.
   - `0x1E1..0x1E6`: 6 × 1 B desde `0x8017DD7C + 2`.
2. Copia de **100 B** a `0x300..0x363` desde el global **`0x8008DC20`**.
3. Bloque de `u16` a partir de `0x364` desde el global **`0x801BBBF0`**:
   - `0x364` = `[0x801BBBF0+2]`, **`0x366` = `[0x801BBBF0+4]` = PROGRESO** (`valor = N*10+P`, BE),
     `0x368` = `+6`, `0x36A` = `+0xE`, `0x36C` = `+0x10`, `0x36E` = `+0x12`, `0x370` = `+0x14`…

`func_801423C8(slot)` es el inverso: lee `0xD00` y llama a `func_80141D08(buffer)` (que copia a los globals).
**El deserializador NO recalcula stats desde el nivel**: los valores se copian tal cual. → subir el
nivel en el fichero **no cambia** HP/OFFENSE/etc.; hay que escribirlos (o ejecutar la lógica de subida).

## 6. Cabecera de guardado (`0x100`) y lista de partidas `[MEDIDO + INFERIDO]`

`[MEDIDO]` sobre `.pak` reales (aplicando `bswap32` a la cabecera):
- `0x00..0x0C`: magic **`"HYBRID HEAVEN"`** (13 B). En el fichero se ve `52 42 59 48 …` (“RBYH…”).
- Checksum en **`0xFF`** = `sum(cabecera[0x00..0xFE]) & 0xFF`.
- **4 registros de 8 B en `0x10 + i*8`**. En cac: `[0x10]=01 01 01 01 00 00 05 00`, `[0x18]=01 01 01 01 00 00 03 00`.

`[INFERIDO del C]`:
- `func_801422E4(file_no, out)` lee `0x100` desde offset 0 y llama a `func_80141A74(out, buf)`: valida
  magic + checksum y **desempaqueta 4 registros de 8 B** a una estructura de descriptors.
- `func_80142350(file_no, src)` es el inverso: `func_80141BD0(&buf, src)` monta la cabecera desde
  **4 registros de 8 B** en `src` y la escribe en offset 0.
- En el guardado (`func_80141268`, modo 1 = slot 0; gemelo para modo 2 = slot 1):
  1. `func_80141628(mode, ·)` → `func_80142450(slot)` (escribe el slot).
  2. Rellena el descriptor del slot en **`0x801C3B80 + slot*8`**, campos `+4=1`, `+5=1`, `+6`, `+7`,
     `+8..+9` (u16), `+A`, `+B` (valores de `0x8017DC88`, `0x801BBBF0+8/0xA/0x1D`).
  3. `func_80141568(mode)` → `func_80142350(slot, src=0x801C3B84)` (escribe la **cabecera**).
- Por tanto: **la cabecera es la que marca qué slots existen** y la lista los lista desde ahí; el
  editor v3 sólo escribe el slot (`0xD00`) y **nunca la cabecera** → `NUEVA PARTIDA` escribe datos en un
  slot libre pero la cabecera no lo marca, y la lista nativa no lo muestra. **Esto explica el punto
  “no se creó partida nueva” y que la “cabecera” no refleje progreso/nivel.**

### 6.1 Mapa del registro de cabecera (MEDIDO + validado headless)

Cada registro de slot (8 B, en la cabecera ya revertida/bswapped) es:

| Byte | Campo |
|---|---|
| `+0` | presente (`1`) |
| `+1` | **AREA N** (`progreso/10`) |
| `+2` | **AREA P** (`progreso%10`) |
| `+3` | **LEVEL** |
| `+4..+5` | **TIME** (u16, se conserva) |
| `+6..+7` | sin uso (0) |

Comprobado con los `.pak` reales: `01 01 01 01 00 05 00 00` = AREA 1-1 / LEVEL 1 / TIME 5. **Fix**:
`hh::save::save()` llama a `update_save_header(slot)` (`src/subsystems/save_edit.cpp`), que revierte
la cabecera, escribe esos campos desde el progreso/nivel del slot, recalcula el checksum (`0xFF =
sum(0..0xFE)`) y vuelve a revertir. Así DATA LOAD refleja el slot y `NUEVA PARTIDA` crea una entrada
visible. (Nota: el intento previo de reconstruirla con las funciones nativas `func_801423C8`→
`func_80141268` se descartó: la carga fallaba y reescribía el slot; no usar sin resolver el checksum
del deserializador.)

## 7. Funciones del juego relevantes (módulo de título/save, `file_024`) `[MEDIDO del C]`

| Dirección | Qué hace |
|---|---|
| `0x801423C8` | lee slot `a0` del PFS (`0xD00`) + deserializa (`func_80141D08`) |
| `0x80142450` | serializa (`func_80141F28`) + escribe slot `a0` al PFS |
| `0x801422E4` | lee cabecera (`0x100`) + `func_80141A74` |
| `0x80142350` | `func_80141BD0` + escribe cabecera (`0x100`) |
| `0x80141628` | `mode 1→func_80142450(0)`, `mode 2→func_80142450(1)` |
| `0x80141568` | `mode→func_80142350(slot, src=0x801C3B84)` |
| `0x80141268` | **flujo GUARDAR** (slot): slot + descriptor + cabecera |
| `0x801411D0` | flujo CARGAR slot |
| `0x80141F28` / `0x80141D08` | serializar / deserializar buffer `0xD00` ↔ globals |
| `0x80144C40` / `0x80144E68` | cabecera de bloque (magic + struct + técnicas + items) |

## 8. Sistema de estadísticas y subida de nivel — **líneas de investigación** `[INFERIDO]`

> ⚠️ Aún **no** se ha localizado la lógica de escalado por nivel. Lo de abajo es lo hallado en el
> desensamblado; hay que confirmarlo ejecutando/oráculo. **Hipótesis del mantenedor**: `OFFENSE` es
> una estadística de potencia que sube con el nivel (no es el contador por parte).

En la **imagen plana** (boot, `funcs_0/53/54`, direcciones `0x80024xxx`):
- Puntero(s) al struct del jugador: `0x800D4260` (doble) / `0x800D425C`.
- `func_80025908`: `+0x40 (OFFENSE)=0` y copia a `+0x32`; `func_80025A00`: ídem `+0x42 (DEFENSE)`→`+0x34`.
- `func_80025940` / `func_80025A38`: **acumulan** OFFENSE/DEFENSE sumando bytes de un array
  (`lb` con signo) — pinta a contribución por parte/equipo, no a base por nivel.
- Tablas referenciadas: `0x80057E02`, `0x80057E86`, `0x80057E06` (leer `lhu`); y campo `+0x5E` como
  contador, `+0x60` puntero.
- El struct guardado (`0x8017DC40`) tiene los stats base (`+0x40..+0x46`) y el nivel (`+0x48`).

**Cómo seguir**: (a) oráculo con emulador (BizHawk/mupen) en dos niveles distintos + `diff` del
`.pak`; (b) trazar quién escribe `struct+0x40..0x46` y `+0x00/+0x02` al subir de nivel; (c) probar a
llamar a la rutina de subida de nivel del propio juego. Objetivo: que el editor, al fijar el nivel,
recalcule stats **con la lógica del juego** (o los fije a mano con la tabla resultante).

## 9. Estado del editor v3 tras esta sesión `[MEDIDO]`

- `hh::save::save()` ahora llama a `hh_pak_reload_from_disk()` (fork NMR `9b14604`) tras escribir el
  `.pak`: arregla que `CONTINUAR` leyera el `g_pak` cacheado (la causa del bloqueante v3).
- `NIVEL`: se acabó de leer/escribir como **u16 LE en `0x4A`** (`rd16le`/`wr16le`). Antes se escribía
  un `u8` en `0x4B` → `0x4A|0x4B<<8` daba `4609`.
- `ESTADO` (`body_stat_of`/`set_body_stat_of`): ahora **u16 LE** → los contadores muestran `1` y no `256`.
- `PROGRESO` (`0x366`, u16 **BE**) y técnicas (`0x9E+id*3`, bytes) ya eran correctos.
- Compila en Linux (`cmake --build build/linux`). **Sin commitear** (pendiente validar en Windows).

**Pendiente inmediato del editor**:
1. Escribir la **cabecera** al guardar (descriptor del slot) → que `NUEVA PARTIDA` cree slot visible y
   que la lista muestre progreso/nivel. Usar `func_80141BD0`/`func_80142350` o replicar el descriptor
   `0x801C3B80+slot*8` con los campos `+4..+B`.
2. Nombres de items: `Life Charger X`/`S` salen invertidos (criterio de la tabla `0x8017DF50` /
   orden de ids) — **verificar contra la lista real** (extraer de la ROM/módulo).
3. `ESTADO`: confirmar los offsets `HIT/DAMAGE` (`0x68`/`0x76`) y el orden de partes.
4. Escalado de stats por nivel (§8).

## 10. Cómo verificar `[MEDIDO]`

- Centinela en un `.pak` de prueba + `HH_SAVEEDIT_TEST=1` (escribe y relee) →
  `[save-edit][test] antes/despues` en `hh.log`; el `.pak` va a `saves/`.
- Comparar siempre con un `.pak` real copiado aparte (`work/debug/cac/saves_windows/hh.us.bin.pak` es
  un save de capítulo 1-1 de referencia).
