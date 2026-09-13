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
