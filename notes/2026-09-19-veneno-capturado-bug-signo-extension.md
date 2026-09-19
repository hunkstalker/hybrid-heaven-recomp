# 2026-09-19 — Veneno capturado: bug de signo-extensión en el wrapper (hh_venom.log) y cadena confirmada

> Ejecuta el paso 1 de `RETOMAR.md` (ronda del `2026-09-18-diferencial-port-emu-vi-cac-paridad.md`):
> capturar `hh_venom.log` con el wrapper del setter para confirmar **quién** dispara
> `M10_FUN_8021b280`. **Resuelto.**

## 1. Causa raíz del `hh_venom.log` vacío: comparación con signo-extensión

El wrapper `hh_wrap_FUN_800058dc` comparaba:

```cpp
if (ctx->r5 == 0xFFFF84CDu || ctx->r5 == 0xFF7F84CDu) { ... }
```

`ctx->r5` es `gpr` = **`uint64_t`** y el valor llega por el trampolín `M55_FUN_80379410`
(`a1 = a1 - 0x7B34`), que usa `ADD32`:

```c
#define ADD32(a, b) ((gpr)(int32_t)((a) + (b)))
```

`ADD32` **firma-extiende** a 64 bits → el valor real es `0xFFFFFFFFFFFF84CD`, que **nunca** es igual a
`0x00000000FFFF84CD`. El wrapper **sí se ejecutaba** (~1400 veces), pero el `if` nunca casaba. De ahí
el log vacío en la ronda anterior.

**Fix** (runtime NMR, `librecomp/src/overlays.cpp`): comparar truncando a 32 bits.
Se factorizó el volcado en `hh_dump_venom(tag, rdram, ctx)` y se añadió además un wrapper para
`FUN_800058f4` (`0x800058F4`, cuerpo general del setter por fallthrough) por si algún módulo lo invoca
vía `LOOKUP_FUNC`. La ruta real del veneno entra por `LOOKUP_FUNC(0x800058DC)` desde
`M55_FUN_80379410`, así que el wrapper del setter es el que captura.

## 2. Captura (`hh_venom.log`) — cadena confirmada

Run headless `HH_REPLAY_MODE=poll` (sin watchpoint, sin `HH_DUMP_VI`/`HH_M24LOG`); el freeze/veneno es
intermitente (~1 de 2 intentos). Artefacto: `work/debug/cac/venom_20260919/hh_venom.log`.

```
=== VENOM #1 [800058dc] obj=8024AAF8 cb=FFFF84CD a2=801BC23A a3=801BBBF0 ra=00000000 sp=8005BDD8 ===
  callring: 8012C9C0 8012CE10 8012B1E4 8012BFA0 80006214 8001F718 801277B0 80006214 8001F718
            8021B280 8022C7A4 8022C5AC 8022C314 8022C478 80379410 800058DC
```

Mapeo (syms): el `callring` (más antiguo → más nuevo) es

`M7_FUN_8012c9c0 → M7_FUN_8012ce10 → M7_FUN_8012b1e4 → M7_FUN_8012bfa0 → FUN_80006214 →
FUN_8001f718 → M7_FUN_801277b0 → FUN_80006214 → FUN_8001f718 →`
**`M10_FUN_8021b280 → M10_FUN_8022c7a4 → M10_FUN_8022c5ac → M10_FUN_8022c314 → M10_FUN_8022c478 →
M55_FUN_80379410 → FUN_800058dc`**.

⇒ **Confirmado**: `M10_FUN_8021b280` es el disparador; `a3=0x801BBBF0` y `a2=0x801BC23A` coinciden con
lo documentado. El `obj=8024AAF8` (callback `0x8024AB14`) y el veneno `0xFFFF84CD` son los esperados.

## 3. Llamante directo de `M10_FUN_8021b280`

`HH_FUNC_OWNER=8021B280` (`[OWNER] get addr=8021B280`) → 12 resoluciones en el run, todas con
**`ra=00000000`**: `b280` se invoca **como callback por puntero**, no por `jal` (coincide con §6a de la
nota del diferencial). El llamante inmediato es un despachador (el anillo muestra `FUN_8001f718` /
`FUN_80006214`, utilidades del scheduler, justo antes). Para el `ra` real haría falta capturar el
contexto en el instante de la llamada (no en `get_function`), o el escritor del puntero `0x8021B280`
en la tabla de estado. Artefacto: `work/debug/cac/venom_20260919/hh_owner.log`.

## 4. Quién PUBLICA el puntero `0x8021B280` (instalador) — CADENA COMPLETA

Con `HH_B280TRACE=1` (traza en `get_function(0x8021B280)`) + watchpoint de datos sobre el slot
(`HH_WATCH_ADDR`), capturado:

- El handler vive en el slot **`0x8024C950`** del objeto **`0x8024C934`** (`a0+0x1C`); el struct guarda
  `{handler=8021B280, base=8021B150}`. Lo escribe el **mismo setter `FUN_800058dc`** (`sw a1,0x1C(a0)`)
  con `a1=0x8021B280`.
- **Instalador directo = `M10_FUN_8021b240`** (0x8021B240, justo antes de `b280`). Su código:
  `if (M7_FUN_80126A0C(obj, 0x39, 1) != 0) FUN_800058dc(obj, 0x8021B280);`
  (`a1 = 0x8022 - 0x4D80 = 0x8021B280`).
- La **puerta** es `M7_FUN_80126A0C` → `M7_FUN_80126A18` (state machine M7): devuelve 1 solo si
  `[0x8008D580] (timer 0x42D0) < 0x3001` **y** `FUN_801267B8(lhu[sp+0x1E]) == 1`, y la bandera
  `0x801BBBD91 (0x181) == 0`. `FUN_801267B8` llama a la state machine grande `M7_FUN_80125808`.
- El instalado y las ejecuciones de `b280` ocurren al **final del replay** (sample 9803→9814, VI
  20006→20031), tras saturar la última muestra; `b280` corre **una vez por frame** y cada vez ejecuta el
  disable (12 venenos).
- Llamante de `M10_FUN_8021b240` (no capturado aún): viene por el anillo de M7 (`M7_FUN_801257DC` /
  `FUN_80004BB0` / `FUN_80028a90`…). No es imprescindible: la divergencia ya está acotada a la puerta.

Artefactos: `work/debug/cac/venom_20260919/{hh_b280_get.log,hh_b280set.log}`.

## 5. Experimento de timing (por qué el emulador no lo ejecuta)

La causa es de **timing**, no de secuencia (coincide con la nota del diferencial). Experimentos:

- `HH_REPLAY_MODE=poll HH_REPLAY_CLOCK=1` (reloj esclavo de la muestra): **0/4 pasadas** toman la ruta…
  pero es **inestable**: realimenta y el juego corre a ~58 polls/s (no 30) → no es fix válido.
- Prototipo `HH_VI_CLOCK=1` (`osGetTime`/`osGetCount` = `total_vis * 781250`, sin reloj de pared):
  **0/4 pasadas** toman la ruta, pero el limiter cuantiza a 3 VI cuando el target no cae en la rejilla
  → juego a **~20 fps**. Tampoco es fix válido. (Prototipo revertido; el knob se descartó.)
- ⇒ El `osGetTime` de **reloj de pared** (`time_now()`, `high_resolution_clock`) es jittery frente al
  contador emulado del N64; pero la solución **no** es cuantizar por VI sin más, sino un contador
  continuo y determinista con resolución sub-VI que mantenga 30 fps.

## 6. Workaround `HH_NO_DISABLE=1` — PROBADO EN VIVO, NO FUNCIONA

`HH_NO_DISABLE=1` en `hh_wrap_FUN_800058dc`: ignora la escritura del sentinel `0xFFFF84CD`/`0xFF7F84CD`
(el "disable" que el emulador **nunca** aplica), de modo que el objeto conserva su callback sano
(`801CB71C`).

- **Prueba en vivo (mantenedor, Windows, sin replay)**: **sigue el cuelgue antes del CaC**. ⇒ El disable
  **no** es el único bloqueo; el envenenamiento es un *síntoma*, no la causa.
- **Prueba con replay (Windows)**: además el replay con `poll` **desvía el input** desde el principio
  (ticks de 3 VI, ver §8b) → no sirve para validar nada. El lanzador `run_cac_nodisable.bat` solo es
  útil cuando el replay sea fiel.

## 6b. Evidencia Windows: los stalls existen desde el principio

En la pasada en vivo (`logs_nodisable_20260919_081332/hh_slow.log`, solo 57 líneas):

```
dvi=3  send_dl≈3.0ms  update_screen=0.0ms  guest_busy=34..35ms   (presupuesto 2 VI = 33.3 ms)
```

- Ticks que abarcan **3 VI**: el limiter del juego apunta a ~33.3 ms pero cierra a ~34 ms; según la
  fase respecto a la rejilla VI, el frame abarca 2 o 3 VI.
- En modo `poll` cada tick consume 1 muestra → si el tick cae a 3 VI la muestra se aplica en el instante
  de juego equivocado = **deriva de input**.
- El emulador no lo sufre: su frame va en **lockstep con el VI**.

## 7. Ficheros tocados

- Runtime NMR (`port/HybridHeavenRecomp/lib/N64ModernRuntime/librecomp/src/overlays.cpp`, sin commitear):
  fix del cast a `uint32_t`, `hh_dump_venom`, wrapper de `FUN_800058f4`, traza `HH_B280TRACE`
  (`hh_b280.log` + variables de puerta, `hh_b280set.log`), workaround `HH_NO_DISABLE`, diag
  `HH_CLOCKDIAG`, y `HH_RETURN_ADDR()` (portabilidad MSVC).
- Runtime NMR `ultramodern/src/timer.cpp` + `events.cpp` (sin commitear): reloj determinista
  `HH_DET_CLOCK` (da 30 fps; **no** arregla la carrera) y `hh_get_vi_wall_us`.
- Port: `run_cac_nodisable.bat`, `run_nodisable_live.bat` (sin commitear).
- Evidencia: `work/debug/cac/venom_20260919/{hh_venom.log,hh_owner.log,hh_b280_get.log,hh_b280set.log}`;
  Windows `build_win/.../logs_nodisable_20260919_081332/`.

## 8. Fix propuesto: reloj determinista `HH_DET_CLOCK` (implementado y PROBADO — no basta)

**Implementación** (runtime NMR `ultramodern/src/{timer.cpp,events.cpp}`): `osGetTime`/`osGetCount`
devuelven `total_vis * 781250 + sub`, con `sub` = residuo sub-VI desde la marca de tiempo del último VI
(la actualiza el hilo de VI; `hh_get_vi_wall_us`), acotado a <1 VI. La parte entera es VI-locked (60
VI/s exactos) y el sub-VI es continuo; `HH_DET_CLOCK_BIAS` añade ticks por VI (para compensar el
truncado a ms del limiter).

**Resultado positivo**: `HH_DET_CLOCK=1` mantiene **30 fps** (medido: polls 30.06/s, VI 60.2/s), a
diferencia del VI-clock seco (~20 fps). Resuelve el problema de cuantización.

**Resultado NEGATIVO (decisivo)**: **no elimina la carrera**. Con `HH_DET_CLOCK=1` **sin** watchpoint,
0/5 pasadas toman la ruta; pero con `HH_DET_CLOCK=1` **+ watchpoint** (que hace que el hilo de juego
haga I/O en `hh_watch.log` → parones), **3/4** la toman. ⇒ El disparador no es el reloj sino los
**parones/jitter del hilo de juego** (RT64/WASAPI/IO), que desplazan los frames respecto a los VI.
Un reloj determinista no arregla un *stall* real (el frame se alarga en tiempo de pared igualmente).

**Conclusión**: el fix de raíz debe atacar la **alineación frame↔VI** (que el hilo de juego no acumule
parones: desacoplar render/audio, o un limiter con compensación que reanude el frame en la rejilla VI),
no el origen del reloj.

## 9. Siguiente paso (recomendado)

1. **Alinear frame↔VI (PRIORIDAD ÚNICA)**: que cada frame abarque 1 tick / 2 VI pase lo que pase con los
   stalls. Opciones: limiter que reanude sobre la rejilla VI; desacoplar los stalls (`send_dl` ~3 ms +
   `guest_busy` ~34 ms; RT64/WASAPI/I/O de logs). Ver §1 del handoff 2026-09-18 (`0x80001A88`, `__ll_*`).
   Validar en **Windows en vivo** (freeze ~100 %); afinar headless.
2. Comparar las variables de la puerta (`0x188`/`0x181`/timer `0x42D0`/`0x42FF`) port↔emu en el mismo
   VI para localizar la primera divergencia exacta (el trazado ya las vuelca con `HH_B280TRACE`).
