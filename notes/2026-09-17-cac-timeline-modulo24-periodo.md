# 2026-09-17 — CaC: por qué el port se salta la ráfaga #22 — LÍNEA TEMPORAL del módulo 24 (periodo g2)

> Continúa `2026-09-17-cac-veneno-ffff84cd-y-llamante.md` (§10 = primera divergencia de flujo). Esta
> ronda identifica **quién pide la ráfaga** y **por qué el port no la pide**. Instrumentación nueva en
> `overlays.cpp` (runtime local): `[DT]` (dispatcher por id), `[LST]` (listas y callbacks de escena),
> `[TL]` (driver de la línea temporal de escena). Dumps comparados: port `work/debug/port_vi*.bin` vs
> emulador `work/debug/cac/emu_state/emu.vi*.bin` (+ `emu_lst_trace/emu.vi2196.bin`).

## 1. La ráfaga #22 es un paso de guion de la escena (módulo 25) pedido por la línea temporal (módulo 24)

- Emulador (`HB_TRACE_EXEC=0x800045E8`): la ráfaga (t=36,62..37,44) la piden los callbacks
  `M25_FUN_801e34b4` / `M25_FUN_801e389c` (módulo 25, cargado a `0x801E1BE0`) que llaman a
  `M24_FUN_801c2420(idx)` (módulo 24, cargado a `0x801BF1A0`). `idx` = índice en la tabla
  `0x80171CF0`; cada descriptor `[tabla[idx-1]]` apunta a `{id1,id2}`. La ráfaga corresponde a
  `idx=601` → `{330,348}`, `idx=163` → `{180,189}`, `idx=602/604/605/606/607` → `{331,333,334,335,336,348}`,
  `idx=164/167` → `{181,184,189}`, `idx=42/45/48/87` → `{127,130,133,152}`.
- Los callbacks los invoca el **intérprete de comandos** `M24_FUN_801bf850` (comando 0x10000 →
  sub-guion `M24_FUN_801c0464`), y a este lo llama el **driver de la línea temporal**
  `M24_FUN_801bfaa0` (via `M24_FUN_801bfa60`), que corre ~30/s.

## 2. La línea temporal tiene “periodos” (`g2`) y esperas por tiempo

- Estado del driver (datos del módulo 24):
  - `[0x801D8CE8]` = **periodo actual (g2)**; `[0x801D8CE4]` = línea (tl); `[0x801D8CF0]` = contador de
    entrada; tabla de líneas en `0x801D8C00`; base/epoch `[0x801D8D80:84]`.
  - Avance de periodo = `M24_FUN_801bffac` (`g2++`), llamado desde `0x801BFCA0`/`0x801BFE24` al agotar
    las entradas del periodo.
  - Esperas: `M24_FUN_801c0b8c(a0,a1)` = `(osGetTime - epoch)*64/3000 >= (a0:a1)` (multiplicación y
    división de 64 bits `FUN_80026F58`/`FUN_80026E58`). Las entradas vistas equivalen a **3 s, 11 s y
    20 s** (`0x2DC6C0`, `0xA7D8C0`, `0x1312D00`).
- Comprobado con dumps y trazas:
  - Emulador: `g2=0` en VI 1602/1701/1801; **`g2 0→1` en VI 2187** (`wr 0x801D8CE8=1 pc=0x801BFFC4`,
    watchpoint del core; `HB_TRACE_EXEC=0x801BFFAC` → avance a vi_count=2187 con `ra=0x801BFCA8`).
    Justo después (VI 2196+) corre la ráfaga.
  - Port: el driver corre a la misma cadencia (~30/s desde vi≈669) pero **las comprobaciones
    `[TL] EVQCHECK` dan 0 siempre** (60 logs, todas 0) y **`M24_FUN_801bffac` nunca se ejecuta**
    (ningún `[TL] ADVANCE`). El periodo no avanza → los guiones de `g2=1` (los de la ráfaga) no se
    ejecutan.

## 3. Qué hace el port en su lugar: cambio de escena temprano (VI≈840)

Secuencia real del port (log `linux_tl.log`, vi=840):

```
[TL] PFF20                                   <- FUN_801BFF20 desde M24_FUN_801c0254 (no desde el driver)
[SETCB] obj=801FDA70 cb=801BF54C / 801BF598 / 801BF604
[EVQ] n=7 id=0001 ... [EVQC] n=2625 cnt0=1 cnt1=0 id=0001
[SETCB] obj=801FD4D0 cb=80123934
[DT] id=9 ... (cadena de módulos: 0x0053C77C->0x801BF1A0 = módulo 8, etc.)
```

- Esto es la vía alterna de cambio de escena (`M24_FUN_801bf508`, gate `[0x801D8CF8]==0`, →
  `M24_FUN_801c0254`), disparada por el evento id=1. En el emulador la misma cadena ocurre en
  **VI≈3660** (t≈60 s), después de que la línea temporal agotase su periodo 0 (incluida la ráfaga).
- Consecuencia mecánica: el port carga el módulo 8 en `0x801BF1A0` **antes** de que la línea temporal
  del módulo 24 pudiera procesar su periodo 1; los datos del módulo 24 (tablas de guion, epoch) se
  sobrescriben (dumps `port_vi850.bin` ya muestran código del módulo nuevo en `0x801D8CE8`).
- Diferencia de base de tiempo observada: epoch `[0x801D8D80:84]` = `0x1F014BEF` (~11,1 s) en el port
  vs `0x4BB6C427` (~27,1 s) en el emulador (unidades `osGetTime`: 46875 ticks/ms).

## 4. Ronda 2: base de tiempo REFUTADA; el disparo real es un flag transitorio de `[0x80089478]`

1. **`osGetTime`/epoch NO son el problema (medido)**:
   - Port (`HH_LSTTRACE` sobre `osGetTime`, 0x80031190): a VI 802, `osGetTime` = 13.363 ms ≈ 802/60 s →
     reloj de pared == tiempo VI, ritmo 46875 ticks/ms.
   - Emulador: `osGetTime` = contador de CPU (mismo ritmo); epoch `[0x801D8D80:84]` = 27,09 s a VI 1602
     (offset de arranque ~0.4-1.5 s, irrelevante: la partida usa diferencias).
   - **Decisión: el fix NO va en la base de tiempo del runtime (`timer.cpp`/`osGetTime`).**
2. **Emisor del evento id=1** (watchpoint físico `0xCBB20-0xCBB30`, core `libmupen64plus-wplog.so`):
   `FUN_800207d0` escribe el id pendiente en `0x800CBB28` (`pc=0x80020894`) y el contador en
   `0x800CBB21` (`pc=0x800208A4`); el consumidor es `FUN_80020f60` (`pc=0x80020FC8`). Id=1 es un evento
   *recurrente* (5 en 90 s) y **no** es el disparador del cambio de escena (hubo cambio de escena sin
   ningún `[EVQ]` cerca en `linux_chain/consola2.log`).
3. **La vía de cambio de escena se ejecuta en ambos lados, a la misma cadencia**: las funciones del
   módulo 99 (`0x8038BCE0/8038C914/8038CA8C/8038D224`, `ra=0x801BF3D4`) corren por poll (port:
   VI 668→841; emulador: VI 1551→3660) y despachan los **mismos 9 comandos por ciclo** (structs y
   `cmd` idénticos en los dumps: idx 0/1/3/6/7/8 → `0x10000` = runner de guion; idx 2/4/5 → `0x40000`).
   Ritmo de llamadas por VI casi idéntico (port 3,94/VI; emulador 4,51/VI) → **no es un problema de
   cadencia de polling**.
4. **El disparo real (diferencial fino en VI≈799)**: la cadena de cambio de escena del port
   (`M24_FUN_801bf398` → `FUN_801C0C68`(cnt≥60) → `M24_FUN_801c012c` → `M24_FUN_801c0190`) se completa
   porque en `port_vi799.bin` se cumple **`[0x80089478] & 0x1000 != 0`** (ventana transitoria de ~1
   frame; en `port_vi790/801/803` está a 0). En los dumps del emulador (VI 1701/1801) ese bit está a 0
   y la cadena no se completa hasta VI≈3660. Con `HH_WATCH_ADDR=0x80089478`, el bit lo escribe el
   código recompilado de **`FUN_800021b4`** (`ret=exe+0x878FA`, `work/debug/cac/linux_chain/hh_watch_89478.log`), de forma intermitente
   (~1 de cada ~7 frames).
   - Resto de la cadena en el port: cnt30 `[0x801D8DA8]`≥60 desde VI 794; `[0x801D8D00]`=1 desde VI
     ~799; `byte 0x801BBD4D` bit7 a 0 desde VI ~760.

## 4b. Ronda 3: CAUSA RAÍZ — el replay aplica el input en la fase de juego equivocada (START pulsado durante la transición)

Evidencia dura (watchpoint del emulador + `work/debug/cac/linux_chain/hh_replay_poll.log` + `HH_WATCH_ADDR=0x80089478`):

- `[0x80089478]` **no es un flag de escena**: es el registro de **flancos de subida del estado de
  entrada** que escribe `FUN_800021b4` (`sh t8, 0x4(s0)` con `s0=0x80089474`, `t8=(prev^nuevo)&nuevo`;
  la muestra está en `[0x8005CE50]`). El bit `0x1000` = **START recién pulsado** (mapeo del recorder:
  `START=0x1000`).
- Emulador (watchpoint físico `0x89474-0x8947C`, 70 s, sin breakpoints que perturben): el bit `0x1000`
  **solo** se pone en VI 117/145 (boot) y **a partir de VI ~3400** (tras el cambio de escena). En toda
  la transición (VI 1533-3400) vale 0 → la cadena `CHK_012C` no puede completarse.
- Port (`[TL] P89478`): el bit se pone en **VI 765, 783 y 798**, y con `d00=1`/`cnt30≥60` completa la
  cadena → cambio de escena prematuro.
- `work/debug/cac/linux_chain/hh_replay_poll.log` del port: en los polls 412-415, 421-423, 428-430 (VI 766-803) la muestra aplicada es
  `buttons=0x1000` (**START**). Esos samples de la grabación son los índices 412-431, con
  `t=16.8-17.5 s` y **`vis=1092-1135`** (¡el START original iba con VI del original 1092-1135, no 766!).
- Con `HH_REPLAY_MODE=vi` (aplica la muestra cuya `vis` ≤ VI actual) el START cae en VI 1092 — como en
  la grabación — pero **sigue dentro de la transición del port** (el port llega a la transición en
  VI≈872 y a los 330 frames, mientras la grabación/emulador llegan en VI≈1533 / ~576 frames): el
  port consume la fase previa (menús/carga) en ~57% de los frames del original.

**Interpretación**: la grabación está indexada por frame (un sample por poll) con marca `vis` (VI del
original, ≈2.65 VI/frame en esa partida). El port aplica el replay por frame (mode=poll) pero su
relación frame↔VI es ~1.86 (corre a ~32 fps en esta fase), así que los eventos de input (y los waits
dependientes de tiempo de la lógica del juego) caen en **fases de juego distintas**: en el original el
START de samples 412-431 era navegación de menú; en el port cae durante la transición y dispara el
cambio de escena. Es la causa de que no se ejecute la ráfaga #22.

## 5. Conclusión y siguiente paso

- **Causa raíz (ronda 3)**: la divergencia es de **alineación del replay**: el port consume la
  grabación por frame (`HH_REPLAY_MODE=poll`) y su relación frame↔VI (~1.86 en la transición) no es la
  de la grabación (~2.65), de modo que los eventos de input caen en otra fase de juego. Concretamente,
  el START de los samples 412-431 (en el original: navegación de menú, `vis` 1092-1135) cae en el port
  dentro de la transición → `[0x80089478]&0x1000` → `CHK_012C` → cambio de escena prematuro → la
  ráfaga #22 no se ejecuta. También con `HH_REPLAY_MODE=vi` el START cae en el VI correcto (1092),
  pero el port ya está en la transición porque llegó a ella en ~330 frames (original ~576).
- **Dónde va el fix (propuesta concreta)**: hacer que **el tiempo de juego siga a la grabación**
  mientras se reproduce, para que los waits dependientes de tiempo consuman los mismos frames que en
  la grabación:
  1. Opción A (preferida): al reproducir, esclavizar el reloj de juego al replay — p. ej. env
     `HH_REPLAY_CLOCK=1`: `osGetTime` (runtime `ultramodern/src/timer.cpp`, offset `ostime_offset`) se
     actualiza por frame con la columna `vis`/`t` de la muestra aplicada (1 frame = Δvis ticks de VI)
     en vez del reloj de pared. Así 1 s de juego = los mismos frames que en la grabación.
  2. Opción B: gatear el bucle de juego por la columna `vis` de la muestra (no emitir frame nuevo
     hasta que el VI actual alcance `vis` de la siguiente muestra) — equivale a fijar el frame-rate al
     de la grabación; más invasivo (scheduler).
  3. Validar con la misma instrumentación: `[TL] ADVANCE` (g2 0→1), `M24C@2420 idx=601` y la ráfaga
     completa (56 cargas como el emulador) sin cambio de escena prematuro.
- **Instrumentación añadida (runtime local, sin commit)**: `[TL] P89478` (flancos del registro de
  entrada en `M99_FUN_8038bce0`), `[TL] F89478` (en `M24_FUN_801bf398`), `[TL] CMD`/`SCENEFN`/
  `BFA58`/checks de la cadena, `[TL] OSGETTIME`.

## Evidencia

- Port: `work/debug/cac/linux_tl.log`, `linux_script_trace.log`, `linux_chain/consola{2,3,4}.log`,
  `linux_chain/watch89478.log`, `work/debug/cac/linux_chain/hh_watch_89478.log`, `work/debug/port_vi{700,760,780,790,799,800,801,803,805,830,841}.bin`.
- Emulador: `work/debug/cac/emu_tl.log` (`HB_TRACE_EXEC=0x801BFFAC,0x801C0B8C`),
  `work/debug/cac/emu_setter.log` (`HB_TRACE_EXEC=0x801BF61C,0x801BF610`; script fija `f28=1`, `tl=0`
  en VI 1533 = igual que el port en VI 663), `work/debug/cac/emu_cmds.log`
  (`HB_TRACE_EXEC=0x801BF850`; 9 comandos/ciclo, idénticos),
  `work/debug/cac/emu_scenefn.log` (`HB_TRACE_EXEC=0x8038BCE0`; por poll hasta t=59,35 s),
  `work/debug/cac/emu_state/emu.vi{1600,1700,1800}.bin`, `emu_lst_trace/emu.vi2196.bin`,
  `work/debug/cac/emu_wp_g2.log`, `emu_evq_wp/stdout.log` (watchpoint cola de eventos).
- Instrumentación del runtime (local, no commit): wrappers `[DT]`, `[LST]`, `[TL]` (driver, avance,
  `FUN_801C0B8C`, checks `02FC/0C68/012C/0190`, setters `801BF610/61C`, `osGetTime`, comandos
  `M24_FUN_801bf850`, funciones de escena 0x8038BCE0/C914/CA8C/D224, flancos `P89478`/`F89478`).
- Ronda 3: `work/debug/cac/emu_wp89478/stdout.log` (watchpoint `0x89474-0x8947C`), `emu_flag/`
  (dumps VI 1761-3701 + watchpoint; sets de 0x1000 solo en boot y VI≥3401), `emu_comb/`,
  `linux_chain/hh_replay_poll.log`, `linux_flag/consola3.log` (`[TL] P89478` con VI), `linux_replayvi/`
  (prueba con `HH_REPLAY_MODE=vi`).
