# 2026-09-27 — `EDICIÓN DE PARTIDA`: reconocimiento y diseño (editor de save)

> **OJO (2026-09-27, posterior)**: este documento es el reconocimiento inicial. La **implementación
> final es la v3 (sobre el `.pak`)** y los **offsets reales verificados** están en
> `notes/2026-09-27-f-editor-partida-v3-y-hallazgos.md`; las secciones §7/§7.b (vías v1 fichero y v2
> memoria) quedaron **superadas**. Empieza por la nota `f-…`.

> Sesión `menu-edicion-partida` (rama desde `main`/v0.5.1). Objetivo del mantenedor: un menú para
> **cargar una partida y editarla** (progreso, nivel, habilidades, estadísticas por parte del cuerpo,
> items) y **GUARDAR** en un slot, para poder testear sin jugar. **Fase 2** (no ahora): `JUGAR`/viajar
> directo a un nivel sin pasar por guardar.

## 1. Formato del guardado (MEDIDO contra `.pak` reales)

- `.pak` = contenedor propio `HHPK`: magic(4) + count(4) + por fichero 19 B + **data a `0x1B`**.
  Data = `0x3500` = cabecera `0x100` + **4 slots × `0xD00`**.
- **Checksums** (verificados en los 3 `.pak` reales): cabecera `0xFC = sum(hdr[0..0xFB]) & 0xFF`;
  slot `+0xCFC = sum(slot[0..0xCFB]) & 0xFF`. Bytes `0xFD..0xFF` / `+0xCFD..+0xCFF` a 0.
- **Layout del slot** (MEDIDO en el serializador `func_80141F28`/`func_80144C40`, `file_008.s`):

  | offset | qué | notas |
  |---|---|---|
  | `+0x000..0x09D` | stats del PJ (0x9E) | copia de `0x8017DC40`; ver abajo |
  | `+0x09E` | **técnicas** 86×3 | por entrada: `[flag, mastery_low, uses]` (`D_80183CE0`, stride 6 en RAM) |
  | `+0x1A0` | **items** 45×1 | cantidad u8 (`D_8017E004`, cantidad en `+4` del struct 8 B) |
  | `+0x1CD` | bloque 3×7 | `D_8017DF14` |
  | `+0x1E2` | bitmask 6 | `D_8017DD7C+2` (aprendidas por golpe) |
  | `+0x300..0x363` | **flags de historia** 0x64 | `0x8008DC18+8` |
  | `+0x366` | **PROGRESO** u16 BE | `N*10+P` |
  | `+0x...` | resto de `0x801BBBF0` | `+0x02` estado, `+0x06`, `+0x08`, `+0x0E`... |

  Nota: entre flags (0x364) y `+0x366` el `func_80141F28` llama a `func_8014B8DC/C294/C2A0` que
  añaden datos variables; en los `.pak` reales miden **0**, por eso PROGRESO cae fijo en `+0x366`.

- **Stats del PJ** (`0x8017DC40`, copiadas al slot `+0`): `+0x00` HP, `+0x02` HP máx, `+0x08`
  stamina, **`+0x10` offense 6×u16**, **`+0x1C` defense 6×u16**, **`+0x40` offense global**,
  `+0x42` defense global, `+0x44` reflex, `+0x46` speed, **`+0x48` nivel u8**, **`+0x68` hit count
  6×u16**, **`+0x76` damage count 6×u16**. Orden de partes del juego: **0 Cabeza, 1 Cuerpo, 2 Brazo
  Der, 3 Brazo Izq, 4 Pierna Der, 5 Pierna Izq**.

## 2. Progreso (MEDIDO)

- Campo vivo **`0x801BBBF4`** (u16 BE) = **`valor = N*10 + P`** decimal. Ej. `1-0`→`0x0A`,
  `2-2`→`0x16`. **El primer número es el nivel, el segundo el punto de guardado.**
- Tabla de escenas `D_80175490` (300 = 30 niveles × 10), indexada por `valor`; `valor` inválido
  (entrada 0) = no hay escena. Puntos válidos por nivel: L0:0-6, L1:0-9, L2:0-8, L3:0-8, L4:0-9,
  L5:0-7, L6:0-5, L7:0-8, L8:0-5, L9:0-8, L10:0-5, L11-18:0-9, L19:0-6, L20:0-4, L21:0-9,
  L22/23/27/28/29: solo 0, L24:0-7, L25/26:0-9.
- Los scripts de transición llaman a `func_8012FE50(tipo, N*10+P, …)`.

## 3. Habilidades/técnicas (MEDIDO)

- Tabla `D_80183CE0`: 86 entradas ×6. **`+0` = aprendida/usable** (menú nativo filtra `+0 != 0`);
  `+2` = maestría (s16); `+4` = usos. Copia J2 en `0x80183EE4` (=+0x204).
- **Aprender = `tabla[id].+0 = 1`; desaprender = `0`.** Al recibir golpes se llena un gauge
  (`0x801840E8`) y `func_802322E8` hace commit (`+0` de 2→1) + enciende el bitmask `0x8017DD7C+2`.
- Nombres: array de punteros **`0x80184140`** (86) → strings ASCII (p. ej. `"UPPER...PUNCH"`).

## 4. Items (MEDIDO)

- Cantidad u8 por item en `D_8017E004 + i*8 + 4`, 45 items (tope 99). Nombres: punteros
  **`0x8017DF50`** (45) → strings `0x8018E390…`.

## 5. Guardado nativo (MEDIDO)

- **SAVE** (entrada nativa en `file_024`): `func_801CA45C` (setup) hace
  `func_80142570(); func_8013EA94(); *(u8*)0x801BBBF0=1; func_800058DC(obj, 0x801CA4A4)`. El update
  `func_801CA4A4` corre `func_8013EB2C` (file-select SAVE) y al terminar deja `obj+0x1C` en un stub
  (`func_801CA520`): hay que **enganchar el final** para volver al título/editor.
- **LOAD**: ya resuelto por CONTINUAR (`func_801C3CDC → func_801C3D50 → func_801C3D84`).
- `func_800058DC(obj, cb)` solo escribe `*(u32*)(obj+0x1C)=cb`.
- **Bloqueante**: `VIBRACIÓN=SÍ` (Rumble vs Controller Pak) impide guardar/cargar (TODO item 11).

## 6. Decisión de mecanismo (v1)

Dos vías:
- **(A) Editar el `.pak` en disco** (parsear/escribir con nuestra lógica, checksums conocidos). El
  runtime cachea el pak (`pak_ensure_loaded`), así que tras editar hay que **forzar recarga**
  (función nueva en el fork) o editar antes de que el juego lo toque. Ventaja: autocontenido y
  testeable; no toca el flujo nativo.
- **(B) Editar memoria + guardado nativo** (cargar un save, editar `0x8017DC40`/`0x80183CE0`/…,
  disparar `func_801CA45C`). Coincide con el modelo mental del mantenedor, pero depende de enganchar
  el LOAD/SAVE nativos (frágil, difícil de testear headless).

**Elegida: (A)** por robustez y testeabilidad, con recarga del pak. `GUARDAR` escribe el slot elegido
(checksum recalculado) y `CONTINUAR` carga la partida editada. Fase 2: `JUGAR`/warp por memoria.

## 7.b MEMORIA (v2, commit `6c917b0`) — vía elegida

Decisión del mantenedor: **editar la memoria de la partida cargada** (resultados en caliente), no el
fichero. El hallazgo que lo permite (pista del menú nativo `DATA EDIT`): el juego tiene funciones de
carga/guardado de slot **sin arrancar partida**:
- **`func_801423C8(channel, slot)`** = `func_800031EC(PFS read slot+0x100, 0xD00) → buffer →
  func_80141D08(buffer)` → **deserializa a los globals** (progreso, nivel, técnicas, stats, items). Es
  "cargar partida a memoria" sin arrancar. `func_801415C4` la envuelve.
- **`func_80142450(channel, slot)`** = `func_80141F28(globals) → buffer → func_800032E0(PFS write)` =
  "guardar los globals en el slot". `func_80141628` la envuelve.

Detalle: `channel` = `a1` (0 = jugador 1), `slot` = `(a2-0x100)/0xD00`. **OJO**: hay que llamarlas con
un `recomp_context` con `sp`/`r29` **válido** (se hereda el del handler del menú; con un ctx a cero la
función no puede usar su pila y no hace nada).

Cambios: `hh::save` pasa a leer/escribir los globals (`0x801BBBF4` progreso, `0x8017DC88` nivel,
`0x80183CE0` técnicas flag `+0`, `0x8017DC40` stats, `0x8017E004` items); **ya no toca el `.pak`** ni
necesita el fork (se revirtió `hh_pak_reload_from_disk` → sin cambios de runtime). `GUARDAR` guarda y
lanza `CONTINUE` (guardar y jugar; v2: guardar sin arrancar). **Arreglo del "menú vacío"**: el cálculo
de la columna de valores sumaba TODAS las opciones de los selectores largos (`PROGRESO` ~228, `NIVEL`
100) y `x_shift` se iba a miles → contenido fuera de pantalla; ahora usa el ancho realmente dibujado.

**Validado headless (Linux)**: entrar en el editor llama a la nativa y **carga el slot** (lectura
`PFS read off=256 size=3328`; progreso `115 → 0`, el del slot) sin arrancar partida; el editor dibuja
con `x_shift=-29`. **Pendiente validar en Windows** (edición en el menú + `GUARDAR` + `CONTINUE`).

## 7. UI (v1, commit `14fa002`)

`EXTRAS → EDICIÓN DE PARTIDA`. Pantalla principal: `PARTIDA < 1..4 >` (slot), `PROGRESO < N-P >`,
`NIVEL < n >`, `HABILIDADES ->` (86, toggle), `BODY ->` (selector `ESTADO` + 6 partes), `ITEMS ->`
(45, cantidad), `GUARDAR`. Se sale con B.

- Código: `include/hh/save_edit.h` + `src/subsystems/save_edit.cpp` (parseo/escritura del `.pak`,
  offsets, checksums, nombres), `src/subsystems/menu.cpp` (pantallas + `rebuild_save_edit`),
  `src/hooks/sections.cpp` (acciones), `src/hooks/menu_overlay.cpp` (dibujo `Number`/`Toggle`).
- **Nombres**: se leen de la RDRAM del juego (módulo 8, arrays `0x80184140` / `0x8017DF50`),
  aplicando el **word-swap** de la RDRAM (`byte[A]` vive en `rdram[(A-base)^3]`) y convirtiendo los
  separadores EUC (`A1B8`) a espacio.
- **GUARDAR** escribe el slot elegido con el checksum recalculado y llama a
  `hh_pak_reload_from_disk()` (fork NMR `0ae2585`), que descarta el pak cacheado y lo relee: así
  `CONTINUAR` carga lo editado.
- **Validado en Linux** (headless con `HH_MENU_SCREEN=12` + START): el editor se construye, lee el
  `.pak` (`progress=3 level=0 tech0='UPPER R PUNCH' item0='Life Charger S'`) y no rompe. **Pendiente
  validar en Windows** (escritura real + `CONTINUAR`).
- **Fase 2 (pendiente)**: `JUGAR`/viaje directo al nivel sin pasar por guardar (usar el campo de
  progreso + cargador de escena `func_80125968`/`func_8012FE50`).
