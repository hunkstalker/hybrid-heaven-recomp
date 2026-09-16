# Work order — Crash del driver de audio por `ctx+4` corrupto (estado del AI)

> Documento operativo autocontenido para retomar ESTA tarea en una sesión nueva.
> Evidencia completa: `notes/2026-09-13-ucode-audio-gate-transicion.md` (§§5-11).
> Estado al escribir: el audio funciona a velocidad plena pero crashea a los ~9-13 s de audio.

## 0. TL;DR

El port ya recompiló e integró el **ucode de audio (aspMain)** y la cadena gfx/audio corre a
**~60 tasks/s con 0 yields**, alcanzando el hito del emulador (request `0x87` + carga `0x801B6600`,
~t=10,5 s). El blocker actual es un **crash intermitente a los ~9-13 s de audio**: el driver del
juego (`FUN_8001FD14`) lee un descriptor `{ptr,size}` desde `*(ctx+4)` donde `ctx` es uno de los tres
contextos de audio (`0x800C7A50`, `0x800C8A40`, `0x800C9A30`), y ese puntero llega **corrupto**
(basura, p.ej. `0x1D581AD5`, `0xF6EFF864`, `0x000A1868` física). El ucode **no** escribe `ctx+4`
(ventanas `[RSPW]`: solo escribe buffers AI en `ctx+0x10`). ASan no ve violaciones host y `[BADMQ]`
(validación de punteros de mq) da 0. Hipótesis: el driver calcula `ctx+4`/descriptor a partir de
estado del **AI** que el port no modela (registros/counters `AI_*`, `osAiGetLength`).

## 1. Objetivo y criterio de éxito

- **Objetivo**: que el driver de audio no lea descriptores corruptos ⇒ sobrevivir > 70 s de audio y
  alcanzar la transición del emulador (burst id 0x19 → geometría/píxeles).
- **Criterios medibles**:
  1. Sin crash con ≥ 4200 audio tasks (≈70 s de audio) en un run de ≥ 4 min.
  2. `[LD384]` > 11 (aparece `a0=0x005FBEC6 a1=0x801BF1A0 a2=0x000135B0`).
  3. `fe00` (`u16 @0x801CFE00`) > 0 y `node1C` (`0x801D03C0+0x1C`) deja de ser `0x801BF1CC`.
  4. Aparecen tareas de geometría/píxeles (display lists de gameplay, no solo el boot/attract).

## 2. Estado de la cadena de audio (lo que YA funciona)

- Ucode **aspMain** del ROM recompilado con `RSPRecomp` (`config/rsp_hh_aspMain.toml`): texto ROM
  `0x37130` (`0xE18`), base IMEM `0x04001080`, 14 targets indirectos; integrado en
  `port/HybridHeavenRecomp/rsp/hh_aspMain.cpp` y registrado en `hh::get_rsp_microcode` (`M_AUDTASK`).
- Parches de runtime activos (`lib/N64ModernRuntime`, **gitignored**):
  - `events.cpp`: `sp_complete` de las tasks **gfx en `submit_rsp_task`** (no en el hilo de RT64;
    evita el backlog de render y los yields); `HH_SP_SHARED=1` opcional (cola SP compartida);
    watchdog `HH_WATCH59`; logs `[GATE]/[OBJ]/[TBL]/[RND]`.
  - `sp.cpp`: `osSpTaskYield` entrega una completación SP sintética al hilo que hace yield (modo
    dirigido); `osSpTaskYielded` devuelve 0.
  - `mesgqueue.cpp`: completaciones dirigidas con cola de pendientes por `(hilo,mq)`; validación
    `[BADMQ]`; log `[R560]` gateado por `HH_VERBOSE`.
  - `rsp.hpp`: chequeos reales (no `assert`, que está compilado fuera por `-DNDEBUG`) de límites
    DMEM/RDRAM en las DMAs.
  - `ultra_translation.cpp`: `[BADMQ]` en `osRecvMesg/osSendMesg_recomp` con el `ra` del juego.
  - `overlays.cpp` (HH_TBLTRACE): wrappers `[SUBM]`, `[SPT]`, `[TKA]` (entrada de `FUN_8001FD14`),
    `[MDL]/[MDLB]/[MDLE]`, `[SCD]/[VOICE]`, `[BCAST]`, `[TIM]`, `[AI]`, `[YLD]`.
  - `src/main/main.cpp`: handler SIGSEGV con RIP/stack (se auto-desactiva bajo `__SANITIZE_ADDRESS__`).
  - `src/main/support.cpp`: `[AUD]` con timestamp (HH_VERBOSE).
- Comando típico (build_dbg):
  ```sh
  cd port/HybridHeavenRecomp/build_dbg
  DISPLAY=:99 SDL_VIDEODRIVER=x11 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
    HH_VERBOSE=1 HH_TBLTRACE=1 HH_SP_SHARED=1 HH_DUMP_VI=6000,12000 timeout 200 "./Hybrid Heaven Recomp" \
    > work/debug/run.log 2>&1
  ```
  (sin `HH_SP_SHARED` = reparto dirigido; ambos modos crashean igual).

## 3. Mecanismo exacto del crash (verificado con instrumentación temporal)

- Hilo del driver: `FUN_8001FBA8` (0x8001FBA8). Bucle:
  `osRecvMesg(mq 0x80091DA0)` → dispatch por `*(s16*)msg`:
  - comando 1 → `L_8001FC70`: `a1 = s0` y llama `FUN_8001FD14(*(tabla+idx*4+8), s0)`.
  - `s0` se actualiza en la ruta por defecto: `t2 = msg recibido (sp+0x54)`;
    `s0 = *(t2+4)` (0x8001FCC8).
- Los mensajes vistos en `0x80091DA0` incluyen los **tres contextos de audio**
  `0x800C7A50/0x800C8A40/0x800C9A30` (además del objeto RSP `0x8005C4B0` de la BCAST).
- `FUN_8001FD14(a0=voice, a1=descriptor)` hace: `v1 = a1`; si `v1 != 0`:
  `a0 = *(v1)` (ptr), `a1 = (s16)*(v1+4)` (size<<2) y `osAiSetNextBuffer(a0,a1)` (`0x80034F70`).
- Instrumentación `[FD14]`/`[FBA8]` mostró el paso a basura en vivo:
  `call FD14: a0=800C89E0 a1=800C79F0` … `a1=000A1868` (física) / `a1=1D581AD5` / `F6EFF864`.
- **Escritores descartados**:
  - Ucode: ventanas `[RSPW]` sobre `0xC7A40-C9A50` solo ven `dram=0C7A60/0C8A50/0C9A40 len=0x280`
    (los buffers AI en `ctx+0x10`), nunca `ctx+4` (`0xC7A54/0xC8A44/0xC9A34`).
  - Host: ASan limpio; sin overflows de DMEM (chequeos reales).
  - APIs de mensajes: `[BADMQ]` = 0 (no pasan punteros corruptos por `osSend/RecvMesg`).
- Descriptor de los contextos cuando están sanos: `ctx1+4=0x800C79F0`, `ctx2+4=0x800C89E0`,
  `ctx3+4=0x800C99D0` (los command lists de cada voz; `{ptr,size}` en `+0/+4`).

## 4. Hipótesis y próximos pasos (en orden)

1. **Vigilar `ctx+4` y correlacionar**: extender `HH_WATCH59` para vigilar
   `0x800C7A54/0x800C8A44/0x800C9A34` (valor en cada VI; log de cambios). Ejecutar hasta el primer
   valor basura y mirar qué ocurrió justo antes (`[AUD]`, `[SPC]`, `[TKA]`, `[AI ]`, `[YLD]`).
2. **Comparar con el emulador al mismo punto lógico** (pocos segundos de audio):
   `HB_DUMP_VI=<n>` o `HH_DUMP_TIMES` en `tools/analysis/emu_ref.sh` y comparar:
   `*(ctx+4)`, buffers AI (`0xC7A60…`), task buffers (`0x800B79F0…`), y si el emulador también
   rota `ctx+4` entre los tres valores sanos. Si el emulador mantiene valores sanos y el port no,
   la diferencia está en el estado previo.
3. **Modelado del AI**: revisar `librecomp/src/ai.cpp` (`osAiSetNextBuffer`, `osAiGetLength`,
   `osAiSetFrequency`, `osAiGetStatus`) y `support.cpp` (`queue_samples`, `get_frames_remaining`,
   drenaje virtual `HH_AI_SPEED`). Buscar en `config/RecompiledFuncs_combined/*.c` lecturas directas
   de registros AI MMIO (`0xA4500000+`/`0x04500000+`) y ver si el port los mantiene:
   - El driver calcula el tamaño del siguiente buffer con `(algo - osAiGetLength()/4 + 0x100) &
     0xFFF0` (visto en `FUN_8001FD14`); si el "algo" proviene de una lectura MMIO que el port no
     actualiza, el estado se desincroniza y puede derivar en punteros/descriptores inválidos.
   - Candidato: `AI_LEN`/`AI_STATUS`/`AI_DRAM_ADDR` (registros) y/o `osAiGetStatus` devolviendo 0.
4. Si aparece un escritor de `ctx+4` en el juego: identificarlo con un watch acotado y comparar su
   secuencia con el emulador (p.ej. cuándo publica un descriptor nuevo).

## 5. Direcciones y símbolos clave

| Qué | Dirección |
|---|---|
| Driver tick | `FUN_8001FD14` (0x8001FD14); crash en 0x8001FD44 (`lh a1,4(v1)`) |
| Driver loop (hilo) | `FUN_8001FBA8` (0x8001FBA8); `s0 = *(t2+4)` en 0x8001FCC8 |
| Contextos de audio | `0x800C7A50`, `0x800C8A40`, `0x800C9A30`; descriptores en `ctx+4` |
| Buffers AI (ucode escribe) | `0x800C7A60`, `0x800C8A50`, `0x800C9A40` (`ctx+0x10`) |
| Command lists por voz | `0x800C79F0`, `0x800C89E0`, `0x800C99D0` |
| mq ticks driver | `0x80091DA0` (sender: BCAST `FUN_80000A0C` en t19/VI) |
| mq ack driver | `0x80091EB8` (ack de t18) |
| Objeto RSP | `0x8005C4B0` (+0x888 lista BCAST; +0xE8 mq SP; +0x158 ack t17) |
| Mq SP / DP | `0x8005C598` / `0x8005C5D0` |
| Submits RSP | `osSpTaskStartGo` 0x80026C9C; `osSpTaskYield` 0x80029690; `osSpTaskYielded` 0x80030FF0 |
| AI | `osAiSetNextBuffer` 0x80034F70; `osAiGetLength`? (buscar en syms) |
| Request de progreso | `FUN_80021EB8` (id 0x87) → `FUN_80022044` → carga `0x801B6600` (`FUN_80003824`) |

## 6. Entorno y utilidades

- Builds: `build_dbg` (principal) y `build_asan` (AddressSanitizer):
  ```sh
  # ASan (ya configurado): requiere gcompat (loader glibc para el dxc de RT64) y symlink del ROM
  apk add gcompat
  ln -sf ../build_dbg/baserom.us.z64 build_asan/baserom.us.z64
  cd port/HybridHeavenRecomp/build_asan && cmake --build . -j
  ```
- Sin ptrace ni core dumps (`core_pattern` ro): usar el handler SIGSEGV propio (imprime RIP y pila
  cruda) y resolver con `addr2line -e "port/HybridHeavenRecomp/build_dbg/Hybrid Heaven Recomp" -f -C <off>`
  (offset = RIP - base que imprime el handler).
- Dumps `r64dump`/port: **uint32 LE nativo (sin `bswap32`)**.
- Reglas: no editar `RecompiledFuncs/` de forma permanente (instrumentar copia temporal y restaurar
  desde `config/RecompiledFuncs_combined/`); los cambios de runtime viven en `lib/N64ModernRuntime`
  (gitignored) y se documentan en `docs/architecture.md` §5 + notas.
- Artefactos relevantes en `work/debug/`: `port_final.log`, `port_ovf.log`, `port_w59*.log`,
  `port_fd14*.log`, `port_fba8.log`, `port_ctx.log`, `asan_run3.log`, `gdb_spin.txt`.
