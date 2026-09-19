# 2026-09-19 (noche-2) — Inventario de pruebas + nueva evidencia de la fase previa

> Continúa `2026-09-19-clasificacion-adelanto-fase-previa.md`. Antes de ejecutar nada se hizo el
> **inventario de todo lo probado** (para no repetir) y luego una tanda de experimentos nuevos
> (replay en cero, `HH_MASK_START` con traza M24 completa, dumps tempranos por VI y diff RDRAM
> completo). **Corrige** la conclusión de la nota anterior sobre `[0x801BBD56]`.

## 1. Inventario: qué YA está probado (no repetir)

| Línea | Resultado | Evidencia |
|---|---|---|
| Reloj: tasa de `osGetTime` port↔emu | **correcta** (46875 ticks/ms, == reloj de pared == VI) | `notes/2026-09-17-cac-timeline-modulo24-periodo.md` §4 |
| Reloj determinista (`HH_DET_CLOCK`, `quant`, `quant+bias`, `HH_VI_CLOCK`) | **negativo** (20 fps o no quita la carrera) | `2026-09-19-bat-stall-check.md` §A1; `2026-09-19-veneno-*` §5/§8 |
| Replay `mode=vi` / `HH_REPLAY_CLOCK` / `HH_REPLAY_PACE=vi` | **negativo** (misma divergencia) | `2026-09-17-replay-mode-vi-vis-negativo.md`; `pacevi_tl.log` |
| Cadencia del replay (muestra↔tick) | **descartada** (mapeo idéntico ~2,1 muestras/frame) | `2026-09-19-clasificacion-adelanto-fase-previa.md` §1-2 |
| Cadencia del callback de espera `M7_FUN_80124C54` | **idéntica** (30/s) | ídem §2 |
| Cache de assets (`HH_TRANS_CACHE=0`/`NATIVE=0`) | **no es la causa** | `loader_nocache.log` |
| `HH_NO_DISABLE` / `HH_NO_B280` | solo mueven el síntoma | `2026-09-19-veneno-*` §6 |
| Instrumentación pesada (`HH_DUMP_VI`, `HH_MQLOG_ALL`) | **enmascara** la divergencia | `2026-09-19-bat-stall-check.md` |
| Causa del freeze = rama M10/M12 (veneno) | **confirmada**; el emu nunca la toma | `2026-09-18-diferencial-*` §2e |
| A→B causal (máscara de START evita la rama) | **confirmado** | `2026-09-19-bat-stall-check.md` §Test de causalidad |

## 2. Corrección de la nota anterior: `[0x801BBD56]` es SÍNTOMA, no causa

La nota `2026-09-19-clasificacion-adelanto-fase-previa.md` §3b concluía que el byte decisivo era
`[0x801BBD56]`. **Es incorrecto como causa**: la secuencia de callbacks del objeto de transición
`0x801D0474` es **idéntica en orden** port↔emu; lo único que cambia es el **tiempo de permanencia**
en cada callback. El byte es parte del mismo estado aguas abajo.

### Secuencia del objeto de transición `0x801D0474` (misma en ambos)

| # | callback | port (vi) | emu (vi) | hueco port | hueco emu |
|---|---|---|---|---|---|
| 1 | `801C1508` | 200 | 347 | — | — |
| 2 | `801C1A30` | 244 | 959 | **44** | **612** |
| 3 | `801C1A98` | 244 | 961 | 0 | 2 |
| 4 | `801C1BDC` | 244 | 969 | 0 | 8 |
| 5 | `801C1C44` | 251 | 971 | 7 | 2 |
| 6 | `801C1D7C` | 308 | 1031 | 57 | 60 |
| 7 | `801C1DB8` | 314 | 1033 | 6 | 2 |
| 8 | `801C3940` | 351 | 1243 | 37 | **210** |
| 9 | `801C3A40` | 358 | 1245 | 7 | 2 |
| 10 | `801C3BA4` | 364 | 1483 | 6 | **238** |
| 11 | `801C3BD8` | 364 | 1485 | 0 | 2 |
| 12 | `801C3C14` | 370 | 1491 | 6 | 6 |
| 13 | `801C3CD0` | 370 | 1493 | 0 | 2 |

- **Mismo orden exacto** en ambos (evidencia directa: `work/debug/m24/emu_setcb.log` vs
  `work/debug/m24/tl_port.log`). La transición no es distinta, es **~15× más rápida** en el port.
- El hueco grande `cb1→cb2` (44 vs 612) lo decide `M23_FUN_801c1508`: lee `M23_FUN_801c1334` y si
  `v0 & 0xB000` (A/Z/START) cambia el callback a `801C1A30`. El port lo ve en `vi 200`; el emu en
  `vi 347` — pero el input de la grabación (muestras 64-135, `vis` 108-209) llega **antes** en el
  emu (`vi 70-142`) que en el port (`vi 143-244`). ⇒ El port **aplica el input más tarde en VI** y
  aun así termina la escena **~1100 VI antes**: la compresión es **intrínseca al director de
  escena**, no al mapeo de input.

## 3. Experimentos nuevos de esta ronda

### 3a. Replay con input en cero (`cac_zero_20260919.txt`)

Regrabado el replay completo con todos los botones/stick a 0. Resultado: **el port no pasa del
menú** (no hay carga #12, no hay callbacks de `0x801D0474`; la carga previa `0005D280` se retrasa a
`vi 518`/`s=431`). ⇒ La fase temprana es **input-dependiente** (el START de menú es necesario para
avanzar), consistente con el test de causalidad. **No** permite aislar el timing del motor por sí
solo.

### 3b. `HH_MASK_START=400:700` + traza M24 completa

- `ADVANCE` (`M24_FUN_801bffac`) **SÍ ocurre** con la máscara: `g2: 0→1` en `vi 1077` (el baseline
  no lo ejecutaba antes del cambio de escena). ⇒ El mecanismo de avance de periodo **funciona**; lo
  que lo cortocircuitaba era el cambio de escena prematuro disparado por el START.
- Pero la carga #12 **sigue** en `vi 409` (igual que sin máscara): la máscara **no** retrasa el
  loader #12, solo evita la cadena `CHK_012C` (que sin máscara completa en `vi 549`). ⇒ Son **dos
  efectos distintos** del mismo START: (a) loader #12 temprano (independiente del START) y
  (b) cambio de escena por flanco START (dependiente).

### 3c. Dumps tempranos por VI y diff RDRAM completo

- `port_vi{200,300,349,400}.bin` vs `emu_early.vi{200,300,349,400}.bin` (`tools/analysis/diff_state_at_vi.py`):
  - **VI 349: estado clave IDÉNTICO** (`obj trans 0x801FDA70=00039140`, `+0x1C=24E70018`, objeto CaC
    `0x8024A990`, M24 a cero). Única diferencia consistente: colas `0x8005C4F0`/`0x8005C268`
    (port 0 vs emu `8005C9D8`/`80049930`).
  - VI 200/300: diferencias de **estado transitorio** (directorio, objeto CaC aún sin inicializar).
- `diff_rdram.py` @VI 349: 8,06 % de palabras distintas, concentradas en framebuffer/heap
  (`0x8009-0x800F`, `0x8039-0x803F`) — el ruido ya caracterizado. En la región de objetos
  (`0x801B-0x801F`) apenas 6-519 palabras.
- ⇒ A igual VI el estado guest es prácticamente el mismo; **el port simplemente llega antes**.

### 3d. Las colas `0x8005C4F0`/`0x8005C268` (pendiente de 09-18) — reexaminadas

En `vi 349` el port tiene esas colas a 0 y el emu inicializadas (`8005C9D8`/`80049930`). Pero el
contenido de `0x80049930` en el emu es **0** (solo se usan como puntero de cola), y en el freeze del
port `0x8005C4F0` coincide con el emu (`8005C9D8`). ⇒ Sigue siendo una divergencia real, pero **de
inicialización de una cola que en el port aún no se ha tocado**, coherente con que el port va en un
punto anterior de la línea temporal, no una causa independiente.

## 3d-bis. El front-end avanza en botones DISTINTOS (causa concreta)

Instrumentado el callback del objeto de transición `0x801D0474` = `M23_FUN_801c1508` (hook
`[CB1508]` en el port, opt-in `HH_LSTTRACE`; emu `HB_TRACE_EXEC=0x801C1508`):

- **Dwell en `801C1508`** (corre cada 2 VI en ambos):
  - **port**: vi 200 → 244 = **22 invocaciones** (44 VI).
  - **emu**: vi 347 → 959 = **306 invocaciones** (612 VI).
- `801C1508` llama a `801C1334` (lee `lhu [0x80089478]`, el registro de **flancos** de input) y si
  `& 0xB000 != 0` (A=0x8000, Z=0x2000, START=0x1000) cambia el callback a `801C1A30`.
- **El port sale en vi 242 con un flanco START** (`[CB1508] f89478=1000`), que viene de la **muestra
  135** (grabación: `vis 209`, btn `1000`), aplicada en el port en vi 244.
- **El emulador sale en vi 959 con un flanco A**, porque su objeto **no existía** cuando pasaron los
  STARTs de las muestras 64-283 (`vis` 108-517): su objeto nace en vi 347 y todos esos pulsos ya se
  habían aplicado (GetKeys#64-283 en vi 70-285).
- ⇒ **El port y el emulador no divergen por el input, sino por la alineación pantalla↔input del
  front-end**: el port llega antes a la pantalla que consume START; el emulador, más lento, se la
  pierde y avanza con un A posterior. Firma de "front-end más rápido", no de un fallo de input ni de
  la línea temporal M24 (aún no cargada).

## 3e. El adelanto nace en el FRONT-END (antes de M24) — hallazgo clave

**Hecho robusto (mismo VI, dumps):** en `vi 349` el port ya ha completado **toda** la secuencia de 13
callbacks del objeto `0x801D0474` (está en `0x801C3CD0`), mientras el emulador **sigue en el primero**
(`0x801C1508`). En `vi 400` igual (port en `0x801C3CD0`; emu en `0x801C1508`). El objeto de transición
y la carga #11 **preceden** a la carga de M24 (#12), así que la divergencia existe **antes de que M24
esté cargado**: `ADVANCE=0`/`EVQCHECK=0` y la transición prematura son **síntomas aguas abajo**.

**Medición del dwell (VI, inequívoca):**

| hito | port | emu |
|---|---|---|
| objeto `0x801D0474` creado (cb `801C1508`) | vi **200** | vi **347** |
| sale de cb#1 → cb#2 (`801C1A30`) | vi **244** (START) | vi **959** (A) |
| carga #11 `0005D280` | vi **205** | vi **349** |
| carga #12 `005FBEC6` (M24) | vi **417** | vi **1535** |

- La **causa concreta** (§3d-bis): el port crea el objeto 144 VI **antes** del START de la muestra
  135 (vi 244) y lo captura; el emulador lo crea 205 VI **después** de ese mismo START (vi 142) y lo
  pierde. El emulador avanza con un A 700 VI más tarde. ⇒ **Velocidad del front-end**, no input ni M24.
- **Cautela de método**: comparar por *índice de muestra* es engañoso, porque el emulador consume el
  replay a ~1 muestra/GetKeys (≈44/s) y el port a 1 muestra/tick (30/s); el `vis` grabado pertenece
  al port. Las comparaciones válidas son **por VI** (dumps) y por **frames de juego**.

## 4. Conclusión: la raíz está en el FRONT-END (timing), no en M24

- No es reloj, ni cadencia de replay, ni cadencia de callback, ni input mapping, ni cache, ni el
  runtime genérico (Goemon no aporta: sus parches son TLB/PAK/ROM comprimida, y ya tenemos #123/#125/
  #128 del upstream).
- Es la **velocidad del front-end (logos/título/menús)**: el port crea el objeto de transición
  `0x801D0474` en `vi 200` y el emulador en `vi 347`. M24 ni está cargado en ese tramo.
- El siguiente eslabón concreto: **medir la cadencia del front-end** port↔emu. Qué pantallas hay y
  cuántos VI dura cada una; el candidato clásico es una **espera por `osGetTime`** o un contador de
  frames del front-end que el port satisface antes. Instrumento propuesto: trazar las funciones que
  corren antes de `0005D280` y comparar VI por pantalla.
- **Observación a verificar** (no concluyente): en el port `hh_tick.log` muestra la primera fase a
  ~60 llamadas de `get_input`/s (`d1=60`, t=2-7) y luego ~30/s (`d2`); conviene comprobar si el
  front-end del original también entrega el evento VI/frame a 60 Hz y el port lo está marcando a 30,
  o al revés. No usar como causa sin medirlo.

## 5. Artefactos de esta ronda

- `work/debug/replays/cac_zero_20260919.txt` (replay en cero, 9815).
- `port/HybridHeavenRecomp/build_dbg/work/debug/port_vi{200,300,349,400}.bin`.
- `work/debug/m24/emu_early.vi{200,300,349,400}.bin` + `emu_early.log`.
- `work/debug/m24/emu_setcb.log` (setters `FUN_800058DC`), `emu_frame.log`, `emu_wait.log`,
  `emu_bf1cc.log`, `emu_3c.log`, `emu_fe50.log`.
- Logs de pasadas: `/tmp/opencode/port_mask2.log` (máscara + M24), `port_zero.log`.
- Nota previa corregida: `2026-09-19-clasificacion-adelanto-fase-previa.md` (§3b).
