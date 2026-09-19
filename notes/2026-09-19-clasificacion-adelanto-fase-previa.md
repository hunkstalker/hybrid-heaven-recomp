# 2026-09-19 (noche) — CaC: el adelanto NO es cadencia del replay; es espera de escena del motor

> Retoma el **Plan único** de `RETOMAR.md` (paso 1: localizar el primer punto donde el port se
> adelanta en boot→inicio del timeline; paso 2: clasificar cadencia-de-replay vs timing-de-motor).
> Medición **headless determinista** con el replay completo `cac_full_20260918_210956.txt` (9815),
> port `build_dbg` y emulador `emu_ref.sh` (r64dump + hhinput con `HH_KEYS_REPLAY`).
> **Conclusión: es TIMING DEL MOTOR (espera de escena), no la cadencia del replay.** El mapeo
> muestra↔frame es idéntico en ambos (~2,1 muestras/frame) y la cadencia del callback de espera es
> idéntica (30/s); lo que difiere es **cuántas veces se ejecuta la espera antes de cargar el módulo 24**
> (emu ~572; port ~7) → **A2** (tiempo/estado del motor), no un fix de índice de muestra.

## 1. Mapeo muestra↔frame: IDÉNTICO (descarta la hipótesis de cadencia del replay)

| | frames de juego | muestras consumidas | muestras/frame |
|---|---|---|---|
| **emulador** (vi 349→1535) | 592 | 874 GetKeys (índice ~600→~1200) | **2,13** |
| **port** (vi 205→417) | ~105 | 217 | **2,07** |

- Emulador: `GetKeys(ctl0)` = **44,3/s** y el bucle de juego va a **60 VI/s** ⇒ ~1,47 muestras/frame
  (coincide con §2c del diferencial 09-18). En la ventana de espera, 592 frames / 874 GetKeys.
- Port: `hh_framelog` da **30 ticks/s** y el replay `HH_REPLAY_MODE=poll` consume **1 muestra/tick**
  ⇒ ~2,07 muestras/frame (el port consume 1 muestra por tick de 2 VI).
- ⇒ La relación **muestra↔frame es la misma** en ambos lados. El START de menú cae en la misma fase
  relativa; **NO** hay desalineación de índice de muestra. La hipótesis "cadencia del replay"
  (`GetKeys` ~1,47/tick vs port 1/tick, §Síntesis de la nota 09-19) queda **descartada** con estos datos.

## 2. Cadencia del callback de espera: IDÉNTICA (30/s en ambos)

- Port (`work/debug/m24/tl_port.log`): `[M23] FUN_80124C54` corre ~30/s.
- Emulador (`work/debug/m24/emu_wait.log`, `HB_TRACE_EXEC=0x80124C54`): **572 llamadas** en
  vi 349→1535 ⇒ **2,0 VI/llamada = 30/s**. `a0=0x801CFE20`, `a1=0x8008DA88` (mismos args que el port).
- ⇒ El "tick" de la espera es el mismo. Lo que cambia es **cuántas veces se ejecuta**.

## 3. Primer punto de divergencia: la espera de escena se corta a las ~7 iteraciones

Secuencia (idéntica hasta el punto de corte):

| | carga previa `0005D280→801B6600` | `FUN_8012FD1C` (condición de fin de espera) | carga #12 `005FBEC6→801BF1A0` | iteraciones de `80124C54` antes de #12 |
|---|---|---|---|---|
| **port** | vi **205** | vi **~373** (`n=0` → ret **1**) | vi **417** | **~7** (`n=0..7`) |
| **emu** | vi **349** | vi **1495** (`ra=0x80124CB8`, ret 0 → transición) | vi **1535** | **~572** |

- Ambos llaman `FUN_8012FD1C` desde **el mismo call-site** (`ra=0x80124CB8`, dentro de
  `M7_FUN_80124c54`). La condición lee **`lbu [0x801BBBEC]`** (`0x801C0000-0x4410+0x166`).
- Port: en `vi~373` la condición devuelve **1** (seguir esperando) → instala `cb=80124CEC` y **a los
  ~2 VI** el callback del objeto se cambia a `80123934` y se dispara la **carga #12** por la vía
  alterna (evento id=1 / `M24_FUN_801bf508`), **sin** ejecutar el `80124D48` de fin de espera.
- Emu: la misma condición solo se evalúa en `vi 1495` y devuelve 0 → `80124D48` (transición normal)
  → carga #12 en `vi 1535`.
- ⇒ **El primer salto de ~1120 VI es la espera de escena del motor**, que el port se salta. No es
  el índice de muestra: el port llega a la condición ~5,6× antes en frames.

## 3b. El byte que decide la espera: `[0x801BBD56]` diverge (port 1 vs emu 0)

`M7_FUN_8012fd1c` = `lbu t6, [0x801BBBF0 + 0x166]` = **`[0x801BBD56]`**, que `M7_FUN_8012fd28` usa en
`sltiu t6,7` + jump table. El retorno de `8012FD1C` decide en `80124C54`: `!=0` → instala el callback
de continuación `80124CEC` (seguir esperando); `==0` → llama `80124D48` (transición).

| VI | port `t6` / ret | emu `[0x801BBD56]` |
|---|---|---|
| 349 | (no evalúa) | **0x00** |
| 370 | **1** → ret 1 (instala `80124CEC`) | — |
| 500 / 1000 / 1495 | — | **0x00** |

- Emu (`emu_bbec.vi{349,500,1000,1495}.bin`): el byte vale **0** todo el tiempo; solo evalúa
  `8012FD1C` una vez, en `vi 1495`, y da 0 → transición normal en `vi 1535`.
- Port: en `vi 370` el byte ya vale **1** → sigue esperando (instala `80124CEC`) y **a los ~42 VI**
  (vi 412) la carga #12 entra por la vía alterna, sin que la espera termine.
- ⇒ Hay un **estado guest que diverge** (`[0x801BBD56]`) antes de la espera. Encaja con lo ya
  documentado: `M24_FUN_801bffac` (ADVANCE) = 0, `FUN_801C0B8C` (EVQCHECK) = 0, epoch M24 fijada
  ~20 s antes ⇒ la línea temporal M24 no avanza y la escena cambia por la vía alterna.

## 4. Clasificación (paso 2 del plan)

**Timing del motor (A2)**, no cadencia del replay. La espera la gobierna el **estado guest**
`[0x801BBD56]`; el port lo tiene a 1 cuando el emulador lo tiene a 0. El fix no es el mapeo
muestra↔tick (idéntico), sino el estado/tiempo del motor que arma la escena.

## 5. Siguiente paso exacto (nuevo plan acotado)

1. **Trazar quién escribe `[0x801BBD56]`** (`0x801BBBF0+0x166`) en ambos lados y cuándo. En el port
   ya vale 1 en `vi 370`; en el emulador vale 0 hasta al menos `vi 1495`. Watchpoint ligero sobre
   `0x801BBD56` (port `HH_WATCH_ADDR`; emu `HB_RES_DIR`/`HB_WP_SIZE=1`) o wrapper de la función que
   lo escribe, y comparar la primera escritura.
2. **Comparar el estado de la escena M24** port↔emu en VI iguales bajos (349/370/500): `g2`, `cnt30`,
   epoch, `[0x801D8CF8]` (gate de la vía alterna) y las tablas de guion. Debe mostrar qué estado falta
   en el port (probable: el mismo que impide `ADVANCE`/`EVQCHECK`, los waits por `osGetTime-epoch`).
3. Con la primera escritura divergente identificada, atacar **A2** (lockstep VI↔`osGetTime` acotado a
   ese punto) **o** corregir el estado/tabla que no se inicializa.

## 5b. Bug de generación detectado en `M7_FUN_8012fd1c` (¿inocuo?)

En `config/RecompiledFuncs_combined/funcs_23.c` la función **no** termina en `jr $ra`: el recompilador
la cortó en `lbu` (`0x8012FD24`) porque la siguiente instrucción (`0x8012FD28`) es frontera de símbolo.
`fix_fallthroughs.py` añade `M7_FUN_8012fd28(rdram, ctx)` al final (marca `@fallthrough-fix`), que
mimetiza el fallthrough de hardware. **En el port recompilado (`RecompiledFuncs/funcs_23.c`) el fix
está aplicado** y `8012FD1C` sí retorna el valor del jump table. Verificado: no es la causa (el `t6=1`
del port es un valor guest real, no basura). Se deja constancia por si reaparece al regenerar.

## 6. Artefactos de esta ronda

- `work/debug/m24/emu_ld_ref.log` (`HB_TRACE_EXEC=0x80003824,0x801C0A30`): secuencia de cargas + epoch.
- `work/debug/m24/emu_frame.log` (`0x80001454,0x80003824`): 881 frames de juego; ratio GetKeys/frame.
- `work/debug/m24/emu_wait.log` (`0x80124C54,0x8012FD1C,0x801C0B8C,0x80003824`): espera de escena.
- `work/debug/m24/emu_bf1cc.log` (`0x801BF1CC`): 591 llamadas en la ventana de espera.
- Port: `work/debug/m24/tl_port.log`, y reproducción local con `HH_REPLAYLOG=1 HH_FRAMELOG=1
  HH_LDTRACE=1 HH_EPOCHTRACE=1`.
