# 2026-09-13 — Deadlock del gate: race de completaciones SP entre hilos de tareas

> Evidencia de la tarea "emparejar el ritmo del gate `0x8005CD4C`". Continúa
> `2026-09-13-cadena-boot-y-progreso-fe00.md`.

## 1. Estado congelado del port (dump VI7200)

| Medida | Emulador (VI3600/4500, pre-transición) | Port (VI7200/9000/11400) |
|---|---|---|
| `0x8005CD4C` (gate) | 0 | **2** (gate cerrado) |
| t17 (`0x8005C9D8`) cola | `0x8005C4F0` (espera task, idle) | **`0x8005C608` (+0x158)** |
| t18 (`0x8005C828`) cola | `0x8005C4B8` (espera task, idle) | **`0x8005C598` (espera SP)** |
| `+0x890` / `+0x894` (obj `0x8005C4B0`) | 0 / 0 | **`0x800C89E8` / `0x8005C458`** |
| mq `0x8005C4F0` (t17 in) | v=0 | **v=1** (task pendiente) |
| mq `0x8005C598` (SP) | vacía | vacía, con t18 bloqueado |

Cadena: **t18** está procesando una task **type=2 (audio)** en `0x800C89E8` y espera su
completación SP; **t17** entró en el camino `+0x890 != 0` (deja su msg en `+0x894`) y espera el
ack de t18 por `+0x158`. t18 nunca llega a enviarlo ⇒ ninguna task completa ⇒ contador en 2 ⇒
`FUN_80001454` no llama a `FUN_80005270` (dispatcher ~9,5/s vs 36/s) y el juego se congela en el
estado pre-transición (el emulador avanza `fe00` y carga id 0x19 → ROM `0x5FBEC6` → base
`0x801BF1A0` a t≈63,9 s).

## 2. Por qué t18 no recibe su SP

Conteos del run con `[SPC]`/`[SPTHR]` (instrumentación local; ver §4): 689 tasks (SPT), 689
completaciones (SPC), 384 procesadas por el hilo de tareas (type≠1) — es decir, **la completación
se dispara siempre**. Pero las colas SP (`0x8005C598`) y DP (`0x8005C5D0`) son **compartidas y con
varios waiter**: t17 y t18 se bloquean en `0x8005C598` (el protocolo del juego usa el evento SP
global). `do_send` del runtime despierta **a un solo** waiter (el primero de la lista, ordenada por
prioridad: t18 pri=120 > t17 pri=100). El log muestra ambos alternando en `[MQ] BLOCK recv ... c598`
y consumiendo `[SPC]` indistintamente: una completación puede ser consumida por el hilo que no
envió la task ⇒ el otro queda bloqueado para siempre.

En el emulador el mismo código no expone la race porque el orden de scheduling/timing evita que los
dos hilos esperen SP a la vez (t17 y t18 están normalmente idle en sus colas de entrada). En el port,
la combinación de scheduling del runtime + tareas concurrentes la expone.

## 3. Fix propuesto (siguiente tarea)

Opción recomendada: **asociar cada task RSP al hilo que la envía** y entregar la completación SP a
ese hilo concreto (no al primero de la cola):
- En `submit_rsp_task` (o `osSpTaskStartGo`) guardar `this_thread()` por task (mapa task→thread).
- En `sp_complete`, si el hilo emisor está bloqueado en el mq SP, despertarlo directamente
  (`schedule_running_thread` / `resume`) y no encolar el evento genérico para ese caso; si no está
  bloqueado, comportamiento actual.
- Alternativas: serializar el uso del SP en el runtime (no permitir dos tasks en vuelo) o ajustar
  prioridades/orden de arranque para replicar el timing del emulador (frágil).

Validación: `[0x8005CD4C]` oscila 0/1, `FUN_80005270` por frame, el emulador y el port alcanzan la
transición (`fe00`/id 0x19) a VIS comparable.

## 4. Instrumentación local nueva (runtime gitignored)

- `HH_DUMP_VI` admite **lista** separada por comas (`"3000,4500,5400"`).
- `[SPC]` en `sp_complete()` y `[SPTHR] deq/done` en el hilo de tareas (con `HH_VERBOSE=1`).
- Wrappers `HH_TBLTRACE`: `[SETCB]` (FUN_800058DC), `[DISP]` (FUN_80005270), `[M23]`
  (FUN_801CBE88/BDC0/BF1CC), `[LD384]` (FUN_80003824).
- Artefactos: `work/debug/{port_220,port_spc,emu_prog,emu_wfe,emu_ld2}.log`, dumps `*_vi*.bin`.
