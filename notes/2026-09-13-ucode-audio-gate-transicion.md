# 2026-09-13 — El gate de la transición es el ucode de audio (RSP)

> Continúa `2026-09-13-audio-ai-y-estructura-pre-transicion.md`. **Causa raíz encontrada** de por
> qué el port no sale del estado pre-transición.

## 1. Evidencia decisiva (emulador)

- Con RSP-HLE (`mupen64plus-rsp-hle.so`): el loader `FUN_80003824` recibe 22 llamadas; tras las 11
  de boot (≤10,5 s) hay un **burst de 12 a t≈63,7 s** (id 0x19 = `0x5FBEC6 → 0x801BF1A0`) = transición.
- **Sin RSP-HLE (plugin dummy)**: solo **2** llamadas al loader (t=0,33/1,15 s) y **nunca** el burst
  (`work/debug/emu_norsp_out.log`). ⇒ La transición depende de tareas RSP de audio.
- La petición la procesa el CPU en `FUN_80020460` (llamado por el mixer `FUN_8002C4D0` vía `jalr`
  `[a0+8]`), que llama a `FUN_80022044` cuando `*(u16*)0x800CBB4C != 0`; `FUN_80022044` dispara la
  carga con `a1=0x801B6600` (`FUN_80003824`), tabla cuyo primer word queda `0x0020004C`.
- En el emulador el mixer invoca el callback **~128/s**; en el port `FUN_80020460` corre pero con
  `req=0` (nadie escribe `0x800CBB4C`) y `0x801B6600=0` (carga nunca hecha).
- Dumps densos (no invasivos) en el emulador: `0x801B6600` pasa de 0 a `0x0020004C` entre t=10,0 y
  t=10,2 s (`cbb21=0x87` = último id de petición consumido); `CBB4C` se consume en el mismo frame.
- Un watchpoint de escritura sobre `0x800CBB4C` (core `debug`) **no captura ningún valor no-cero por
  CPU** en 12 s (solo los `sh $zero` de `FUN_80022694`); el setter probablemente escribe vía **DMA
  del RSP** (el WP del debugger solo ve stores de CPU).

## 2. Estado del port

- `hh::get_rsp_microcode` (support.cpp) devuelve `nullptr` para todo ⇒ `recomp::rsp::run_task`
  no-opera las tasks de audio (`[SPT] type=2`), así que la petición del motor de audio nunca aparece.
- `RSPRecomp` **existe** en el toolchain (`toolchain/src/N64Recomp/build_recomp/RSPRecomp`; fuentes
  en `toolchain/src/N64Recomp/RSPRecomp/`), con configs de referencia para `aspMain` en
  `toolchain/src/Zelda64Recomp/aspMain.us.rev1.toml` y `toolchain/src/goemon64recomp/aspMain.toml`
  (p.ej. `text_address = 0x04001000`/`0x04001080`, `text_offset/text_size` del ROM, `extra_indirect_branch_targets`).
- El ucode de audio del juego: `task->t.ucode = 0x80036530` ⇒ ROM `0x37130` (verificado contra el
  dump; **los dumps de `r64dump` se leen como uint32 LE nativo, sin bswap**: los primeros words N64
  son `20180360 20170F90 8C3C0030 8C3B0034 40055800 30A40001 10800006 30A40100`).
- Primer intento `RSPRecomp` (`work/rsp/hh_aspMain.toml`, `text_size=0x1000`, `text_address=0x04001000`):
  "Unhandled instruction: INVALID" ×31 y abort en "Unhandled mfc0: 0" ⇒ **el texto del ucode no ocupa
  los 0x1000 desde 0x37130** (o el blob mezcla texto+datos / el entry no es ese offset). Hay que
  delimitar el texto (p.ej. probando `text_size` decrecientes y/o localizando el entry real) antes de
  generar.

## 3. Work order propuesto (siguiente tarea)

1. **Delimitar el ucode**: hallar inicio/fin del texto RSP en el blob de `0x37130` (decode con
   rabbitizer/RSPRecomp por tramos; el arranque del blob parece código válido; el abort viene más
   adelante). Contrastar con la firma de `aspMain` (mupen HLE **no** imprimió "unknown RSP code"
   ⇒ reconoce el ucode) o confirmar que es un KCEO custom.
2. **Recompilar** con `RSPRecomp` (`text_address` real: deducirlo del boot RSP/libultra del ROM; los
   configs de referencia usan 0x1000/0x1080), añadiendo `extra_indirect_branch_targets` según los
   errores.
3. **Integrar en el port**: generar `RecompiledFuncs` del ucode en el build, registrar el
   `RspUcodeFunc` en `hh::get_rsp_microcode` para `type==2` (y `M_AUDTASK`), y ejecutar
   `recomp::rsp::run_task`.
4. **Validar**: la petición `0x800CBB4C` aparece, `0x801B6600` se llena (`0x0020004C`), el burst de
   cargas del loader ocurre y `fase` avanza; después, las tareas de geometría/píxeles (objetivo del
   usuario).

## 4. Instrumentación añadida (opt-in, runtime gitignored)

`[MDL]`/`[MDLB]` (`FUN_80022044`/`FUN_80020460`), `[SCD]` (`FUN_8002C4D0`), `[VOICE]`
(`FUN_8002C7F4`), `[TIM]` (`osSetTimer`), `[AI ]` (`osAiSetNextBuffer`/`osAiGetLength`) — todas bajo
`HH_TBLTRACE`/`HH_VERBOSE`. Artefactos: `work/debug/{emu_rate_stdout.log,emu_m23_stdout.log,
emu_norsp_out.log,emu_dense.t*.bin,emu_wpcbb_stdout.log,port_mdl*.log,port_scd.log,port_voice.log,
port_tim.log}`.

## 5. IMPLEMENTADO (2026-09-13): aspMain del ROM recompilado y corriendo

- **Delimitado**: texto RSP en ROM `0x37130`, tamaño `0xE18` (los words siguientes son tabla de
  datos), base IMEM **`0x04001080`** (como Goemon: con `0x1000` los `jal` caían en mitad de rutinas
  y se hacían DMAs basura `dram=0x1118`).
- **Targets indirectos** (14, tabla de comandos en DMEM): `0x1118 0x12D0 0x11DC 0x1294 0x12EC
  0x1214 0x1E24 0x1254 0x1470 0x140C 0x187C 0x1328 0x138C 0x1B38`. Coinciden con la lista de
  `aspMain` de Goemon ⇒ el ucode del juego **es el aspMain estándar** (SGI audio).
- **Integrado**: `port/HybridHeavenRecomp/rsp/hh_aspMain.cpp` (generado; no editar),
  `CMakeLists.txt` (+`-msse4.1` por `rsp_vu_impl.hpp`) y `hh::get_rsp_microcode` devuelve
  `hh_aspMain` para `M_AUDTASK`. Config reproducible: `config/rsp_hh_aspMain.toml`.
- **Validado**: la task `boot=800350D0 ucode=80036530 udata=8004D910/800` procesa los comandos
  reales (`07000000`, `02000440` A_ADPCM…) y hace DMA writes; **0 exits** (antes: 66/72 por
  `UnhandledJumpTarget`), 53 tasks/30 s.
- **Gap restante (siguiente tarea)**: el emulador envía **55 audio tasks/s** (`osSpTaskStartGo`
  0x80026C9C, caller `ra=0x80000B24` = `FUN_80000a5c`/t18) y el mixer `FUN_8002C4D0` invoca
  `FUN_80020460` ~128-160/s; el port hace ~1,8 tasks/s y ~3,3 mixer/s ⇒ ~30-40x lento. La petición
  la escribe `FUN_80021EB8` (PCs `0x80021FB4/0x80021FC0`, valor `0x87`) llamada por `FUN_80020F60`
  (2417 llamadas/15 s desde `FUN_80020460`); en el port `FUN_80021EB8` **nunca** se llama porque la
  cadencia del driver de audio es demasiado baja. Instrumentar el productor (thread 3 → mq
  `0x8005C4B8` de t18) para hallar el gate de la cadencia (VI/AI/contador).

## 6. Análisis del atasco del driver de audio (2026-09-13)

Cadena (emulador y port):
- Ticks: mq `0x80091DA0` (msg `0x8005C4B0`) desde `FUN_80000A0C` (BCAST del handler VI), ~57/s.
- Driver: thread 3 (`FUN_8001FBA8`) recibe tick → `FUN_8001FD14` (mixer `FUN_8002C4D0` + submit)
  → envía task a t18 (mq `0x8005C4B8`, `osSendMesg` flags=1) → espera ack en `0x80091EB8`.
- t18 (`FUN_80000a5c`): recibe task de `c4b8` → si `*(obj+0x88C)!=0` espera SP (cola de la task
  anterior) → `osSpTaskStartGo` → espera SP (`obj+0xE8` = `0x8005C598`) → ack a `0x80091EB8`
  (y ack a `+0x158`/t17 si `+0x894!=0`; `+0x890=0`).

Estado del port tras el arranque (runs `port_hang`/`port_noexp`, 100-170 s):
- El driver corre bien al principio (**930 tasks/25 s = 37/s** con `HH_QLOG=1`), pero se atasca tras
  **~62-70 tasks**: t18 bloqueado en SP con `+0x88C=0` y sin task en vuelo; t3 bloqueado en
  `0x80091EB8`; el mq `0x80091DA0` acumula **64 ticks** (lleno) y deja de consumirse.
- Conteos: sends a `c4b8`=**63**, `[SPT] type=2`=**62**, acks a `EB8`=**62**, `[AUD]`=**62** ⇒ una
  task fue consumida por t18 pero **no se envió al SP ni se ackó** (evento perdido en el
  handshake `+0x88C`/`+0x894`).
- Experimentos: (a) desactivar el reparto dirigido para audio **no** cambia el atasco (no es la
  causa); (b) con `HH_QLOG=1` el arranque va a 37/s (el timing lo enmascara, pero no se ha probado
  >60 s).
- Los pendientes dirigidos sin consumir son todos de **t17** (gfx); ninguno de audio.

Siguiente: instrumentar el handshake `+0x88C`/`+0x890`/`+0x894`/`+0x158` (escritores en
`FUN_80000bf0` PCs `0x80000CF8`/`0x80000D24`; lecturas en `FUN_80000a5c`) y `FUN_800349E0`/
`FUN_80030FF0` (manejo SP) para localizar el evento perdido que deja a t18 esperando SP.

## 7. Fix de yield y hito alcanzado (2026-09-13)

- El runtime stubeaba `osSpTaskYield`/`osSpTaskYielded` (`sp.cpp`). El juego usa el protocolo de
  yield para alternar gfx/audio en el RSP: t18 llama `osSpTaskYield` mientras t17 tiene una task en
  vuelo (`+0x88C != 0`) y luego espera la completación SP. Con el reparto dirigido, esa completación
  va a t17 y el que hace yield se quedaba esperando para siempre (observado: `osSpTaskYield` 1 vez
  y `osSpTaskYielded` 0 veces justo antes del atasco de la task 63).
- **Fix**: `osSpTaskYield` entrega una **completación SP sintética al hilo que hace yield**
  (`sp_complete(this_thread())`); la task real completa por su lado. `osSpTaskYielded` sigue
  devolviendo 0 (la task no se interrumpe realmente).
- **Resultado** (run 170 s): `AUD=743` (vs 62), yields=2, **request 0x87 procesada**
  (`[MDLE]` id 0x87, `[MDL] v1=0087`), **carga #11** (`0x5D280 → 0x801B6600`, `0x0020004C`) = el
  hito del emulador a t≈10,5 s. `fe00` sigue 0 (la transición del emulador es a t≈63,7 s).
- **Nuevo gap**: a las ~743 tasks el pipeline se desincroniza: t18 consume una completación extra
  (las 2 sintéticas del yield) en el wait post-submit y luego queda bloqueado en `c4b8`/SP con la
  última completación pendiente; t3 queda esperando ack en `EB8` y los ticks se acumulan en `DA0`.
  Siguiente: cuadrar el yield con el protocolo (p.ej. devolver `OS_TASK_YIELDED` y marcar la task
  para que el juego tome la rama de resubmit, o entregar la sintética solo si no hay completación
  real en vuelo).

## 8. Ajuste del yield: completación SP del gfx independiente del render (2026-09-13)

El emulador **nunca** llama `osSpTaskYield`/`Yielded` (0 en 15 s), pero el port lo hacía cientos de
veces: el `sp_complete` de los gfx se emitía en el hilo de RT64 **después del backlog de render**
(~80 ms en software), así que `+0x88C` (task en vuelo) permanecía activo y el driver de audio
yieldaba constantemente.

**Fix** (runtime, `events.cpp`): el `sp_complete` de las tasks gfx se emite en `submit_rsp_task`
(el RSP real completa al parsear la DL, independiente del RDP); el hilo gfx solo hace `send_dl` +
`dp_complete`. Se probó además `HH_SP_SHARED` (cola SP compartida estilo libultra, sin reparto
dirigido; el yield sin completación sintética).

Resultados (run 60 s, `HH_SP_SHARED=1`):
- **0 yields** (como el emulador), **813 audio tasks en 13,8 s = 59 tasks/s** (velocidad del
  emulador; antes ~5/s).
- Hito repetido: request `0x87` (`[MDLE]`/`[MDL]`) y carga #11 (`0x5D280 → 0x801B6600`).
- **Nuevo tope**: a los ~813 tasks (13,8 s de audio) se detiene el **emisor de ticks** (mq
  `0x80091DA0` vacío, t3 esperando en él, t18 en `c4b8`, colas vacías, `+0x89C=2`, `cd4c=2`). El
  juego sigue renderizando (llega a VI3600) pero sin audio ni progresión (`fe00=0`).

Siguiente: instrumentar el emisor de ticks (`FUN_80000A0C`/BCAST a `0x80091DA0`) y la contabilidad
de `+0x89C` (incremento en `FUN_80000ed0`, decremento en `FUN_80000bf0`/`FUN_80000dc8` @0x80000D7C)
para ver por qué deja de emitir con el contador en 2.
