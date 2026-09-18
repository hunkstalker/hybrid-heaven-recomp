# 2026-09-18 (ter) — Diferencial port↔emulador por VI en el CaC: paridad cuando el port no congela

> Ejecuta el plan de `RETOMAR.md` (diferencial en el MISMO VI alrededor del envenenamiento) con el
> `cac_rec.txt` del hito (`logs_pacing_20260918_210956`, 9815 muestras, t 0→329.59 s, vis 37→19812).
> Continúa `2026-09-18-hito-replay-reproduce-cac-port-vs-emu.md`.
>
> **TL;DR**: en los VI coordinados (20200/20500/20700/20900) el port y el emulador son **idénticos**
> en todo el estado del CaC (objeto sano `0x80135320`, M24, directorio). **El port no congeló** en dos
> pasadas con la instrumentación puesta (el freeze headless es intermitente y la instrumentación lo
> perturba), de modo que **el diferencial NO captura el veneno**. La única divergencia aguas arriba
> reproducible es de **timing** en el loader (carga #12), no de secuencia de cargas.

## 1. Qué se ejecutó (y método)

| Paso | Comando (resumen) | Salida |
|---|---|---|
| 1. Port | desde `port/HybridHeavenRecomp/build_dbg`: `HH_REPLAY=<cac_rec> HH_REPLAY_MODE=poll HH_DUMP_VI=20200,20500,20700,20900[,20940] HH_M24LOG=1 "Hybrid Heaven Recomp"` | `work/debug/port_vi<VI>.bin` |
| 2. Emu | desde raíz: `HH_KEYS_REPLAY=<cac_rec> HB_DUMP_VI=20200,20500,20700,20900 HB_TRACE_EXEC=0x80003824 tools/analysis/emu_ref.sh work/debug/cac/emu_diff3 420 9999` | `work/debug/cac/emu_diff3.vi<VI>.bin` |
| 3. Comparación | `python3 tools/analysis/diff_state_at_vi.py <port> <emu>` y `diff_rdram.py` | §2 |

Se corrieron **dos pasadas del port**: `run1` (con `HH_TBLTRACE=1`, añadido; log
`diff_port_20900.log`) y `run3` (comando exacto de RETOMAR, sin TBLTRACE; log `diff_port_run3.log`).

### Correcciones de método (para no repetir)

- **`HH_DUMP_VI` (emulador) requiere además un breakpoint** (aquí `HB_TRACE_EXEC=0x80003824`): el
  debugger de mupen arranca **pausado** y `r64dump` solo lo reanuda si `have_bp`/`want_wp` es cierto
  (`tools/analysis/r64dump.cpp:498`). Sin él, el core no corre y no hay `[HHR]` ni dumps (el primer
  intento quedó parado en el arranque).
- **El knob real es `HB_DUMP_VI`**, no `HH_REPLAY_VI`/`HH_REPLAY_VI_OFF` (que no existen en `r64dump`).
- `HB_TRACE_EXEC` **no** impide que el VI del emulador vaya a tiempo real (~60 VI/s); los `[dbg] stop`
  son baratos. Ver §4 para la correlación de muestras.

## 2. Resultado del diferencial: paridad

`diff_state_at_vi.py` en los 4 VI (idéntico en `run1` y `run3`):

- Objeto CaC `0x8024A990`: `+0x00=8024AAF8`, **`+0x1C=0x80135320` (M7, SANO)** en port y emu.
  **No aparece `0xFFFF84CD`/`0xFF7F84CD`.**
- `mod24` (`0x801D8CE8` g2, `0x801D8DA8` cnt30, `0x801D8D00`, `0x801D8CFC`, epoch) idéntico.
- Directorio `0x8008DFC0` **idéntico** (256 slots).
- Objeto de transición `0x801FDA70/8C` idéntico.
- **Única diferencia consistente**: `0x8005C4F0` y `0x8005C268` → port `00000000` vs emu `80049930`.
  Son punteros de cola; **NO despacharla como "estructural" sin más** (ver §2b: merece investigación
  propia; el port no tiene esas colas inicializadas en el tramo post-transición y el emu sí).

`diff_rdram.py` @VI 20900: **8.51 %** de palabras distintas, concentradas en **framebuffer/heap**
(`0x8008..0x800F`, `0x8039..0x803F`) — el ruido ya caracterizado en el test de determinismo
(`2026-09-18-cac-replay-en-vivo-no-reproduce.md` §4c). En la región de objetos `0x80240000` solo
**1.09 %** (mayoría `0x8025xxxx`/`0x8026xxxx`, ventana de recursos), no en los campos del CaC.

⇒ **Cuando el port no toma la ruta del veneno, su estado coincide exactamente con el emulador en el
mismo VI.** La firma del freeze (objeto "anulado" + colas `[BADMQ]`) **no está** en estos dumps.

### 2b. Auditoría posterior de la diferencia de colas (verificada con los volcados)

Comparando `0x8005C4F0`/`0x8005C268` en **todos** los artefactos disponibles (incluidos los del hito,
que sí congeló):

| volcado | `0x8005C4F0` | `0x8005C268` | objeto `+0x1C` |
|---|---|---|---|
| PORT run3 @20200/@20900 | `00000000` | `00000000` | `80135320` (sano) |
| **PORT freeze** (hito Linux y Windows) | **`8005C9D8`** | **`00000000`** | `80129040` (anulado) |
| EMU diff3 @20200/@20900 | `80049930` | `80049930` | `80135320` (sano) |
| EMU final (hito) | `8005C9D8` | `80049930` | `80135320` (sano) |

- En la pasada del port **sin freeze**, esas dos direcciones están **a cero**; en el emulador **no**.
  Es una divergencia **real y consistente** (aparece en los 4 VI), no ruido: apunta a una **cola del
  port sin inicializar** en ese tramo (loader/PI o cola del hilo 5), aguas arriba del CaC.
- En el **freeze**, `C4F0` coincide con el emu final (`8005C9D8`) y `C268` sigue a cero. El estado 15 s
  posterior está reasignado, así que el dump del hang no sirve para comparar en VI iguales (confirmado).
- **Acción**: comprobar qué escribe esas dos direcciones en el port (watchpoint) y si su valor nulo
  explica la espera/desfase de §4.

### 2c. Precisión del acoplamiento input↔VI (medido)

- **Emulador**: entre t=5.84 s y t=25.61 s, `GetKeys(ctl0)` = **875 en 19,77 s = 44,3/s**; el VI pasó
  de 349 a 1535 = **60,0 VI/s**. El emulador consume ~1 muestra por tick de juego (su bucle va a 60 Hz).
- **Port**: en ese tramo consume **~49 muestras por 100 VI (≈29,4/s)** — no exactamente 30/s.
- ⇒ El mapeo muestra↔VI **no es idéntico** entre port y emulador (aunque la conclusión "timing, no
  secuencia" se mantiene). Fijar este acoplamiento antes de sacar más conclusiones del diferencial.

## 2d. CAPTURA DEL VENENO EN VIVO (ronda posterior, watchpoint) — CADENA CONFIRMADA

Con el watchpoint puesto en la dirección correcta (**`0x8024AB14`** = callback del objeto
`0x8024AAF8` +0x1C, no `0x8024A9AC`) el port **sí congeló** y el `hh_watch.log` capturó la secuencia
exacta del envenenamiento (t=333,09-333,20 s, VI≈20170):

```
t=333.099  FUN_800058dc+0x75  escribe  a1=FFFF84CD -> 0x8024AB14
           a0=0x8024AAF8 (objeto), a2=0x801BC23A, a3=0x801BBBF0
t=333.132  M7_FUN_8012e774+0x6CE  LEE/llama el callback ya envenenado
t=333.138  FUN_800058dc+0x75  escribe  a1=FF7F84CD -> 0x8024AB14  (lo que ve hh_missing)
```

- **Confirmada con evidencia directa** la cadena ya documentada en
  `2026-09-17-cac-veneno-ffff84cd-y-llamante.md`: el setter es **`FUN_800058dc`**, invocado con
  `a1=0xFFFF84CD` y `a0=0x8024AAF8`. `a2=0x801BC23A`/`a3=0x801BBBF0` identifican al llamante.
- El callback **sano** del objeto es `801CB71C`; durante la transición también se ven escrituras de
  `M12_FUN_802425F4`, `M12_FUN_80241948`, `M12_FUN_80241B88` (state machine M12), coherente con las
  notas previas.
- **Bug de instrumentación encontrado y corregido**: `hh_ring2_n`/`hh_ring_n` eran `int` y
  `get_function` va a ~43 M llamadas/s → desbordaban a los ~50 s y el `%` negativo indexaba fuera del
  array (**SEGV en `hh_ring2_record+0x51`**). Pasados a `uint64_t` (runtime NMR). Sin esto, las pasadas
  con watchpoint morían antes del CaC.
- **La instrumentación mueve el freeze**: con watchpoint congeló a VI≈20170 (antes que sin él,
  VI≈20949) — otra evidencia de que es una carrera sensible al timing.

## 3. El freeze no se reprodujo (dos pasadas)

| run | TBLTRACE | resultado | último VI visto |
|---|---|---|---|
| `run1` | sí | sin veneno, sin `[HANG]` | sisó 22277 (s=9814) |
| `run3` | no | sin veneno, sin `[HANG]` | ~22767 (s=9814) |

El freeze del hito (VI≈20949, objeto `FFFF84CD`, `tid5` en `osRecvMesg` de `0x8005C288`) es
**intermitente en headless** (ya anotado en `2026-09-18-cac-replay-en-vivo-no-reproduce.md` §1:
`HH_VI_EVERY=2` lo evitaba en headless y no en vivo). Estas dos pasadas cayeron del lado "no freeze".
**No existe todavía un juego de dumps por VI de una pasada que sí congele.**

### El dump del hang no sirve para el diferencial directo (confirmado)

`hh_hang_rdram_47781_*` (15 s posterior al cuelgue) comparado con el emu @20900: `dir[0]` port
`802746A8` vs emu `803757E0`, con el directorio **desplazado** (el emu tiene el slot `FFFE` que el
port ya no tiene). El objeto pudo recrearse/reasignarse. Confirma la advertencia del hito: comparar
en VI iguales, no el dump del hang.

## 4. Primera divergencia aguas arriba: **timing** del loader (no la secuencia)

Con la traza del loader (port `[LD384]`, emu `HB_TRACE_EXEC=0x80003824`) las **secuencias coinciden
1:1** (mismo `a0` src, `a1` dst, `a2` size), **incluida** la carga `0x007F1252 → 0x8025D168` que la
nota previa (`2026-09-17-cac-veneno-ffff84cd-y-llamante.md` §10) decía que el port se saltaba. No se
reproduce el "salto de la ráfaga #22".

Lo que **sí** diverge es **cuándo** ocurre cada carga:

| carga | port (`s` → vis) | emu (`vi` @ t) |
|---|---|---|
| #1 `004E69A8→80107830` | s=0 → vis 19 | vi 19 @ 0.34 s |
| #5 `005F1190→801BF1A0` | s=106 → vis 185 | vi 226 @ 3.79 s |
| #12 `005FBEC6→801BF1A0` | s=217 → **vis 413** | vi **1535** @ 25.61 s |
| #21 `007F1252→8025D168` | s=223 → vis 425 | vi 1629 @ 27.18 s |
| #23 `0053C77C→801BF1A0` | s=306 → vis 595 | vi 1869 @ 31.17 s |

- El port llega a la carga #12 en **vis 413**; el emulador en **vi 1535** (~**18 s** de espera de
  escena que el port no consume en ese tramo). Luego **reconvergen**: ambos saturan el replay
  (`s=9814`) hacia **vis/vi ~20000** y los dumps de §2 coinciden.
- Mapeo `s→vis` del port (run1): `0→19`, `105→183`, `217→413`, `223→425`, `306→595`,
  `9814→20034` (saturación).
- ⇒ El desfase es de **cadencia/espera**, no de orden de cargas. Es la semilla plausible del freeze
  (sensible a timing) que ya apuntaban las notas de `2026-09-18-cac-*`.

## 5. Implicación y siguiente paso (handoff)

0. **HECHO en esta ronda**: capturado el veneno en vivo con watchpoint (§2d): `FUN_800058dc` escribe
   `0xFFFF84CD` en `0x8024AB14` con `a0=0x8024AAF8`; `M7_FUN_8012e774` lo consume. El llamante de
   `FUN_800058dc` viene con `a2=0x801BC23A`, `a3=0x801BBBF0` (identificarlo: quién invoca el setter).
1. **Capturar en una pasada que sí congele.** Orden recomendado (la instrumentación es lo que
   perturba: en la ronda del hito, `poll` **sin** `HH_DUMP_VI`/`HH_M24LOG` congeló a la primera,
   VI≈20949; con instrumentación por VI, 0 de 2; con watchpoint, VI≈20170):
   - **In-vivo (Windows, mantenedor)** con `HH_WATCH_ADDR=0x8024A9AC`/`HH_MQLOG_ALL` (Plan B de la nota
     `2026-09-18-cac-replay-en-vivo-no-reproduce.md` §5), que es donde el freeze es ~100 %.
   - Headless **sin** `HH_DUMP_VI` y **sin** `HH_M24LOG` para confirmar el freeze; y luego reducir la
     instrumentación al mínimo (p. ej. volcar solo el objeto por VI) para no perturbarlo.
   - Alternativa no intrusiva: que el **watchdog de hang** guarde también el objeto/colas y la
     secuencia de cargas, no solo RDRAM 15 s después.
2. **Atacar el desfase de timing del loader #12** (§4): identificar qué espera/tarea (AI/SP/DP,
   cutscene) el port resuelve en ~3.5 s y el emulador en ~18 s, y por qué se pierde/reordena.
3. **Investigar `0x8005C4F0`/`0x8005C268`** (§2b): en el port sin freeze están a cero y en el emu no;
   watchpoint para ver quién las escribe (o debería) y si su valor nulo explica la espera de §4.
4. Fijar el acoplamiento input↔VI (§2c) para que las comparaciones por VI sean exactas.

### Artefactos

- `work/debug/cac/diff_vi_20260918/port/` (`run1`: dumps + `port_run.log`).
- `work/debug/cac/diff_vi_20260918/port_run3/` (`run3`, comando exacto RETOMAR: dumps 20200..20940 + log).
- `work/debug/cac/diff_vi_20260918/emu/` (`emu_diff3.vi*.bin` + `emu_run.log`).
- Herramientas: `tools/analysis/diff_state_at_vi.py`, `tools/analysis/diff_rdram.py`,
  `tools/analysis/emu_ref.sh` (`r64dump`).
