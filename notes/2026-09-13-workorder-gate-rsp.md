# Work order — Bloqueo por gate de tareas RSP (`0x8005CD4C`)

> Documento operativo para retomar ESTA tarea en una sesión nueva. Autocontenido.
> Evidencia completa: `notes/2026-09-13-directorio-nisitenma-y-gate-rsp.md`.
> Estado al escribir: bloqueo funcional abierto. Última actualización: 2026-09-13.

## 0. TL;DR (30 segundos)

El juego queda en `fase=0` porque `FUN_80001454` (hilo 5) **deja de llamar al dispatcher
`FUN_80005270`**: el gate de `0x80001820` salta al epílogo si `[0x8008D545]==0` **y**
`[0x8005C4B0+0x89C] >= 2`. En el port ese contador (`0x8005CD4C`, tareas RSP pendientes) queda
clavado en 2; en el emulador oscila 0/1. Loader, directorio Nisitenma y recompilación descartados.

**ACTUALIZACIÓN (misma fecha):**
1. **Resuelto** el estado corrupto de hilos/colas: `FUN_80030610` era el `osCreateMesgQueue` del ROM
   (inicializa `mtqueue/fullqueue` con `&__osThreadTail` = `0x80049930`) y el runtime de mensajes
   asumía listas NULL. Fix: rename de símbolo `FUN_80030610` → `osCreateMesgQueue` en las syms
   (las llamadas pasan al runtime). Detalle: `notes/2026-09-13-vi-context-y-sentinel.md` §2.
2. **Bloqueo actual**: el **contexto VI del juego** (`0x8004AE70…`, `OSViContext`) nunca se
   inicializa/mantiene: `__osViInit`/`__osViSwapContext` no se ejecutan (0 llamadas) porque
   `osCreateViManager` está reimplementado y el hilo VI del ROM (`FUN_80034840`) no corre. `t17`
   espera un cambio de framebuffer que el juego no puede hacer ⇒ contador clavado ⇒ gate cerrado.
   Siguiente paso en §9.

## 1. Objetivo y criterio de éxito

- **Objetivo**: que `0x8005CD4C` vuelva a 0/1 y el gate reabra ⇒ `FUN_80005270` se llame cada
  frame ⇒ avancen los callbacks del módulo 7/23 y la fase (`u16 @0x80037750`) pase a 1.
- **Criterios medibles**:
  1. `[0x8005CD4C]` deja de estar fijo en 2 y alterna 0/1 como en el emulador.
  2. `FUN_80005270` aparece en la traza de cada frame (no 6 veces y se corta).
  3. `0x80037750 == 1` (leer como **u16** en offset `(0x37750^2)`) y aparecen display lists del
     juego (`0x801C2000`, escritas por módulo 54 en `0x803842C4`).

## 2. Mecanismo exacto (verificado por disasm, `capstone` sobre la ROM)

`FUN_80001454` en `0x800017AC..0x80001854`:

```
v0 = [0x80037758] (u16, FUN_80001060)
[0x8008D544] = (v0 != 0)
t4 = [0x8008D545]                     ; valor del frame anterior
if (t4==1) goto 0x8000181C
t5 = [0x8008D544]
if (t5!=1) goto 0x8000181C
v0 = [0x8005C4B0+0x89C]               ; = 0x8005CD4C, FUN_80000EC8(0x8005C4B0)
if (v0>=2) goto 0x80001820
0x8000181C: [0x8008D545] = ...
0x80001820: v0 = [0x8005C4B0+0x89C]
t7 = [0x8008D545]
if (t7!=0) goto 0x80001854           ; CUERPO PRINCIPAL (llama FUN_80005270 en 0x80001974)
v0 = [0x8005C4B0+0x89C]
if (v0>=2) goto 0x80001B24           ; EPÍLOGO: se salta el dispatcher
```

- En ambos lados `[0x80037758]==0` ⇒ `0x8008D544/545==0`. El gate depende **solo del contador**.
- Incremento: `FUN_80000ed0` (submit de task) si `[msg+8] & 0x40` ⇒ `[a0+0x89C]++` en `0x80000F54`
  (a0=`0x8005C4B0`), y `osSendMesg([0x8005CD78]=0x8005C4F0, msg)`.
- Decremento: hilo 17 `FUN_80000bf0` (`t=0x8005C9D8`), al consumir un msg con `[msg+8]&0x40` ⇒
  `[a0+0x89C]--` en `0x80000D7C` y `osSendMesg(a0+0x78,msg)`. Después espera completions en
  `SP:0x8005C598` (evento 4, msg 0x29B) y `DP:0x8005C5D0` (evento 9, msg 0x29C).
- Dispatcher: `FUN_80005270` (lista de tareas en `0x80089378`); pump de recursos `FUN_8000433C`
  justo después (`0x80001A58`). Los callbacks del módulo 7 se instalan con `FUN_800058DC`
  (`0x80107830 → 7864 → 78A4 → 78E0 → 7968 → 79B0`).

## 3. Evidencia port vs emulador (para no repetirla)

| Medida | Emulador | Port |
|---|---|---|
| `FUN_80005270` (dispatcher) | 544 llamadas / 15 s (HH_JALTRACE) | 6 en total (HH_CALLTRACE); última en la ronda de `FUN_801079B0` |
| `[0x8005CD4C]` | oscila 0/1 (wplog: wr=1 pc=0x80000F58, wr=0 pc=0x80000D80) | 2 fijo en VI60/VI1200 |
| mq `0x8005C4F0` | `mtqueue=0x8005C9D8` (hilo 17), `fullqueue=0x80049930`, `valid=0` | `blocked_on_recv=blocked_on_send=0x80049930`, `valid=1` |
| hilo 17 (`0x8005C9D8`) | `queue=0x8005C4F0` (bloqueado en recv) | `queue=0xFFFFFFFF` (=`running_queue` sentinel: encolado, no bloqueado) |
| `__osRunningThread` (`0x80049940`) | `0x80059D80` (hilo 5) | `0x00011BF0` (basura) |
| `0x80049930` | OSThread en layout ROM (contexto guardado) | no es un thread del runtime; memoria inconsistente |

- `0x80049930` **no** está entre los 8 `[TH] osCreateThread` del runtime:
  `1:0x80057BD0, 0:0x800CC300, 5:0x80059D80, 19:0x8005C678, 18:0x8005C828, 17:0x8005C9D8,
  16:0x8005CB88, 3:0x80091BF0`.
- El hilo 17 **sí procesa tasks** (HH_QLOG: recv de `0x8005C4F0`, `osSpTaskLoad/StartGo`,
  recv SP/DP; `sp_complete`/`dp_complete` llegan). El fallo no es "no corre nunca", es que en el
  run normal el contador no termina de drenar (posible carrera/bloqueo en la ronda que deja 2
  pendientes).
- Bajo gdb el contador va 0/1 y el boot avanza más ⇒ es **sensible a timing**; usar trazas no
  invasivas y snapshots alineados, no gdb a pelo.

## 4. Hipótesis (por orden de probabilidad)

1. **Ronda atascada del hilo 17**: 2 tasks con `0x40` enviadas; el hilo 17 consume una y se queda
   esperando una completion (SP/DP) que no llega o llega a la cola equivocada; la otra queda en
   `0x8005C4F0` (`valid=1`). Comprobar a qué espera el hilo 17 en el instante del cuelgue.
2. **Corrupción de las listas del mq**: `blocked_on_recv/send = 0x80049930` (no-thread) ⇒ alguien
   escribe ese puntero. Localizar quién (wplog en emulador + watchpoint en port).
3. **Scheduler**: en el port el hilo 17 queda `QUEUED` en la running queue (`queue=0xFFFFFFFF`) y
   no vuelve a recibir CPU; revisar `check_running_queue` (parche `>=`) y prioridades
   (hilo 17 pri=0x64; hilo 5 pri=0x0A) en `ultramodern/src/scheduling.cpp`.
4. **Sync de `__osRunningThread`** (`threads.cpp:_thread_func`, `0x80049940`): el runtime solo lo
   escribe al arrancar el hilo; el juego lo espera actualizado por contexto.

## 5. Plan de ataque (experimentos concretos)

**Paso 1 — localizar al escritor de `0x8005C4F0+0/+4` y de `0x80049930/40`.**
- Emulador (no invasivo): `HH_WPLOG=1 HH_WPLO=<phys> HH_WPHI=<phys>` con el core wplog y mirar el
  `pc=`. Ej.: rango `0x5C4E8-0x5C510` (mq) y `0x49928-0x49948`.
- Port: watchpoint hardware gdb sobre `0x8005C4F0`/`0x8005C4F4` y `0x80049940` (modelo:
  `work/debug/gdb_stuck.gdb`), logueando `$pc`/backtrace y siguiendo.

**Paso 2 — alinear el instante del cuelgue.**
- Emulador: `HB_TRACE_EXEC=0x80000ed0` (raro, no perturba) + `HB_DUMP_VI`; volcar RDRAM justo tras
  la 6.ª llamada. Port: mismo evento con gdb (`work/debug/gdb_ed0.gdb`) o `HH_QLOG`.
- Comparar: `0x8005C4B0..+0x8A4`, `0x8005C4F0..+0x18`, `0x8005C9D8..+0x30`, `0x80049930..+0x40`.

**Paso 3 — fix candidato + validación.**
- Según el escritor: si es estado del runtime (hilos/colas), parchear en
  `port/HybridHeavenRecomp/lib/N64ModernRuntime/ultramodern/src/` (mesgqueue.cpp, threads.cpp,
  scheduling.cpp, threadqueue.cpp) **documentando en `docs/architecture.md` §5**.
- Si es lógica de juego/syms: `config/*.syms.toml` + `python3 tools/recomp.py --config
  config/game_combined.toml --build`. **Nunca** tocar `RecompiledFuncs/`.
- Validar con los 3 criterios de §1.

## 6. Comandos base

```sh
# Build y run del port (Xvfb :99 con GLX debe estar vivo)
cd port/HybridHeavenRecomp/build_dbg
DISPLAY=:99 SDL_VIDEODRIVER=x11 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  HH_CALLTRACE=/app/hybrid-heaven-recomp/work/debug/port_ct.bin timeout 20 "./Hybrid Heaven Recomp"
# Trazas: HH_VERBOSE=1 ([RND] cada 60 VIS), HH_QLOG=1 (envíos/recvs), HH_DUMP_VI=N (una sola VI),
# gdb -x work/debug/gdb_*.gdb (ojo: cambia timing).

# Referencia emulador (Xvfb :99; input+RSP-HLE+vídeo rice)
HB_TRACE_EXEC=0x80000ed0 tools/analysis/emu_ref.sh work/debug/emu_x 15 10
python3 tools/analysis/parse_exec_trace.py work/debug/emu_x.log
HH_WPLOG=1 HH_WPLO=0x5CD40 HH_WPHI=0x5CD60 CORE_SO=work/libmupen64plus-wplog.so ... ./work/r64dump ...

# Recompilar tras tocar syms/tool
python3 tools/recomp.py --config config/game_combined.toml --build
# (Si se toca symbol_lists.cpp: rebuild con --target N64RecompCLI.)
```

## 7. Trampas y reglas

- **GDB cambia el comportamiento** (el cuelgue es timing): priorizar HH_CALLTRACE/HH_QLOG/wplog.
- `HB_TRACE_EXEC` **detiene** la emulación en cada hit: no ponerlo en funciones calientes
  (`FUN_80001454`, `FUN_8000433c`, `FUN_80005270`).
- Port `HH_DUMP_VI` solo acepta **un** valor (no lista); el emulador sí acepta lista (`HB_DUMP_VI`).
- RDRAM volcada word-swapped: `u32` = LE en `offset=a&0x1FFFFFFF`; `u16` en `offset=(a^2)`.
- Los contadores del **loader** (`0x8005D010/18/1C/20`) ya no son el bloqueo; no perseguirlos.
- Todo artefacto persistente en `/app/hybrid-heaven-recomp/work/debug/` (nunca `/tmp`).

## 8. Artefactos ya en disco (gitignored, `work/debug/`)

`port_ct.bin` (HH_CALLTRACE), `port_qlog.log`, `port_vi1200.bin`, `emu_h.log`, `emu_jal3.bin`,
`emu_wq`, `emu_wc.log`, `gdb_ed0.gdb/log`, `gdb_t17.gdb/log`, `gdb_t17arg.gdb/log`,
`gdb_stuck.gdb`, `parse_exec_trace.py` (también en `tools/analysis/`).
Nota de evidencia: `notes/2026-09-13-directorio-nisitenma-y-gate-rsp.md`.

## 9. ACTUALIZACIÓN — sentinel resuelto y bloqueo actual (contexto VI)

### 9.1 Hecho
- `config/us_ghidra.syms.toml` + `config/us_combined.syms.toml`: `FUN_80030610` → `osCreateMesgQueue`
  (vram 0x80030610, size 0x30). Recompilado y construido con
  `python3 tools/recomp.py --config config/game_combined.toml --build`.
- Efecto verificado: `0x8005C4F0`/`0x8005C4F4` = 0 (NULL runtime), `__osRunningThread` (0x80049940)
  válido, sin auto-referencias en `0x80049930`. El contador ya no está «siempre en 2»: oscila en las
  ventanas de submit.

### 9.2 Bloqueo actual (evidencia)
- `[0x8005CD4C]` constante en 2 desde VIS 85 (`work/debug/port_gate.log`).
- `FUN_80005270` 6 llamadas en 25 s (emulador ~544/15 s).
- `FUN_80035050` (framebuffer del `OSViContext` del juego, `[[0x8004AED0]+4]`) devuelve **0** en el
  port y `0x8038F800` en el emulador; `0x8004AE70` está a cero en el port.
- Port: `__osViInit`=0, `__osViSwapContext`=0, `osViSwapBuffer`=2.
  Emulador: `__osViInit`=1, `__osViSwapContext`=541/10 s (1/retrace), `osViSwapBuffer`=427,
  desde `FUN_80034840` (hilo VI manager del ROM; `osCreateViManager` 0x800346C0 está reimplementado
  ⇒ ese hilo no existe en el port).
- Efecto: `t17` gira en el sync de `+0x158` (`[PUSH]/[POP]/[BCAST]` ~1/VI) esperando que cambie el
  framebuffer; no completa las 2 tasks pendientes ⇒ gate cerrado ⇒ el boot no avanza ⇒ no hay swap.

### 9.3 Plan propuesto (implementar y elegir)
- **A (fiel)**: quitar `osCreateViManager` de `reimplemented_funcs`
  (`toolchain/src/N64Recomp/src/symbol_lists.cpp`, estilo ADR 0002) para que corra el hilo VI del ROM
  (`FUN_80034840` → `__osViInit`/`__osViSwapContext`). Auditar duplicidad de eventos VI
  (t19 espera en `0x8005C560`, igual que el hilo VI del ROM) y MMIO VI.
- **B (quirúrgico)**: mantener el `OSViContext` (0x8004AE70…) desde el runtime; p. ej. invocar el
  `__osViSwapContext` recompilado (`0x80032360`) tras cada retrace (`get_function(0x80032360)`), o
  replicar sus escrituras (framebuffer, mq/msg, modo) en `osViSetMode`/`osViSetEvent`/`osViSwapBuffer`.

### 9.4 Herramientas nuevas (opt-in, runtime local gitignored)
- `HH_VERBOSE=1`: `[GATE]` (cambio de `0x8005CD4C` con VIS) y `[RND]` ampliado (cd4c, t17q/t16q,
  mq0x8005C4F0, req +0x888, q158, t19q).
- `HH_TBLTRACE=1`: `[SUBM]`, `[PUSH]/[POP]/[BCAST]` (con tid) y `[FB]` (`FUN_80035050`).
- `HH_GATELOG=1`: `[GATE2]` recv/send de `0x8005C4F0` y `0x8005C528` con `[msg+8]` y contador.
- Evidencia: `notes/2026-09-13-vi-context-y-sentinel.md`.
