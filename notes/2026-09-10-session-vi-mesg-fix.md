# SESIÓN 2026-09-10 — FIX deadlock VI + entrega de mensajes externos (verificado en run headless)

> Complemento de `notes/2026-09-10-handoff-fase2.md`. Documenta los dos fixes de runtime aplicados
> en esta sesión y su **verificación real ejecutando el build de Linux en el contenedor**
> (Xvfb + Vulkan swrast/lavapipe). La sesión anterior dejó el juego deadlockeado en el VI/timer;
> esta sesión lo destrabó y demostró que **el scheduler sigue sin postear la primera tarea**.

---

## 0. Resumen de lo conseguido (verificado, no teórico)

- **Configurado un run headless REAL del build de Linux** en el contenedor (antes no se podía
  observar por falta de GPU/Vulkan). Comandos en §4.
- **FIX A — osSetEventMesg: faltaba el caso `OS_EVENT_VI = 7`.** El juego registra el VI retrace vía
  `osSetEventMesg(OS_EVENT_VI=7, mq=0x800ce920, msg=0x800ce950)` (también `OS_EVENT_COUNTER=3`).
  El switch de `osSetEventMesg` solo manejaba SP/DP/AI/SI, así que el VI quedaba descartado.
- **FIX B — los mensajes externos (VI/AI/SP/DP/timer) no despertaban a un game thread bloqueado.**
  Los mensajes iban a una cola separada `external_messages` y solo se flusheaban al inicio de
  `osSendMesg`/`osRecvMesg`. Cuando un game thread se bloqueaba en `do_recv`, quedaba parkeado en
  `run_next_thread_and_wait` y **nunca** volvía a flushear → el mensaje VI nunca llegaba.
- **Resultado verificado:** el VI manager (`FUN_80034840`) **ya no se deadlockea**; recibe y
  procesa mensajes VI (el nº de `BLOCK recv` en `0x800ce920` cayó de ~1488 → ~298 en 30s).
  Todos los threads de boot se crean (dispatcher, game loop thread 5, VI manager, RSP 16-19).
- **Sigue bloqueado (confirmado):** el scheduler **nunca postea la primera tarea** a la cola
  principal `0x8005bf30` (0 mensajes enviados). Thread 0 dispatcher y thread 5 siguen en espera.
  No hay tareas RSP ni de render. → el juego NO llega a gameplay todavía.
- **Crash secundario (race):** `terminate called without an active exception` tras procesar
  mensajes VI. Dependiente de timing; **no se reproduce bajo gdb** (el gdb lo enlentece).

---

## 1. FIX A — osSetEventMesg debe manejar `OS_EVENT_VI` (evento 7)

**Archivo:** `port/HybridHeavenRecomp/lib/N64ModernRuntime/ultramodern/src/events.cpp`

Contexto: en la struct `events_context` existían `sp/dp/ai/si` con `{mq, msg}`, pero **no** un
`vi_event`. El switch de `osSetEventMesg` (línea ~153) solo tenía `case OS_EVENT_SP/DP/AI/SI`.

```cpp
// Añadido miembro a events_context:
struct { PTR(OSMesgQueue) mq = NULLPTR; OSMesg msg = (OSMesg)0; } vi_event;

// Añadido case al switch de osSetEventMesg:
case OS_EVENT_VI:
    events_context.vi_event.msg = msg;
    events_context.vi_event.mq = mq_;
    break;
```

Además, en `vi_thread_func` se añadió el disparo del evento VI cuando `cur_state->mq` (vía
`osViSetEvent`) es NULL — el juego usa `osSetEventMesg` y no `osViSetEvent`:

```cpp
// Tras "VI retrace fire but mq=NULLPTR":
if (events_context.vi_event.mq != NULLPTR) {
    ultramodern::enqueue_external_message_src(events_context.vi_event.mq,
        events_context.vi_event.msg, false, ultramodern::EventMessageSource::Vi);
}
```

> Nota: el `osViSetEvent` original (evento 7 por la vía del estado VI) no se usa; el juego registra
> el VI por `osSetEventMesg`. Por eso se añadió la vía `vi_event`.

---

## 2. FIX B — los mensajes externos deben despertar a los game threads bloqueados

**Archivo:** `port/HybridHeavenRecomp/lib/N64ModernRuntime/ultramodern/src/mesgqueue.cpp`

### 2.1 Causa raíz (diagnóstico verificado en el log)

Secuencia real del deadlock (run headless):

```
[MQ] osRecvMesg mq=0x800ce920 ... flags=1        <- game thread (VI manager) entra a recv
[MQ] BLOCK recv thread=0 mq=0x800ce920 validCount=0 msgCount=5   <- cola vacía → bloquea
[EV] VI retrace fire but mq=NULLPTR
[MQ] EXT send mq=0x800ce920 msg=0x800ce950 src=4  <- VI thread ENCOLA (vía osSetEventMesg event=7)
[MQ] BLOCK recv thread=0 mq=0x800ce920 validCount=0 msgCount=5   <- ¡sigue bloqueado! nunca ve el msg
```

El mensaje se encola en `external_messages`, pero el game thread ya está parkeado en
`run_next_thread_and_wait` (bucle `while (MQ_IS_EMPTY)`), y **nunca** vuelve a llamar
`dequeue_external_messages` (que solo se invoca al inicio de `osSendMesg`/`osRecvMesg`).

### 2.2 Solución (entrega directa)

1. Se añadió un puntero global `external_rdram` (+ setter `set_external_rdram`), seteado en
   `init_events`.
2. `enqueue_external_message_src` / `enqueue_external_message` ahora hacen `do_send` **directo**
   desde el thread externo (escribe en la cola del juego y despierta al thread bloqueado vía
   `schedule_running_thread` en `do_send`). `external_messages` queda solo como fallback si la
   cola está llena.

```cpp
static uint8_t* external_rdram = nullptr;
bool do_send(RDRAM_ARG PTR(OSMesgQueue) mq_, OSMesg msg, bool jam, bool block);

void ultramodern::set_external_rdram(uint8_t* rdram) { external_rdram = rdram; }

void ultramodern::enqueue_external_message_src(PTR(OSMesgQueue) mq, OSMesg msg, bool jam, EventMessageSource src) {
    if (external_rdram != nullptr && do_send(external_rdram, mq, msg, jam, false)) {
        return;
    }
    external_messages.enqueue({mq, msg, jam, requeue_enabled[static_cast<int>(src)]});
}
```

3. **Refuerzo:** el bucle de `do_recv` (bloqueo) ahora también flushea `dequeue_external_messages`
   en cada iteración, por si un mensaje llega mientras el thread gira (antes de parkearse).

### 2.3 Declaración de `set_external_rdram`

`port/.../ultramodern/include/ultramodern/ultramodern.hpp`: añadido
`void set_external_rdram(uint8_t* rdram);`. Llamado en `init_events` tras `events_context.rdram = rdram;`.

---

## 3. Verificación real (run headless)

### 3.1 Qué muestra el log (game_out.txt, run de ~30s)

- `osSetEventMesg event=7 mq=0x800ce920 msg=0x800ce950` → VI registrado.
- `osSetEventMesg event=3 mq=0x800ce920 msg=0x800ce968` → COUNTER registrado.
- `osSetEventMesg event=4/9/14/12` → SP/DP/PRENMI/FAULT registrados.
- Threads creados: `id=1 (0x80001124)`, `id=0 (0x8002AEA0)`, `id=5 (0x800011b0)`,
  `id=0 (0x80034840 VI manager)`, `id=16..19 (0x80000774/0x80000a5c/0x80000bf0/0x80000dc8 RSP)`.
- Colas creadas: 0x8005bf30 (main, count=200), 0x8005c288 (RSP, 64), 0x8005c560/598/5d0/4f0/528/4b8/608/640 (8),
  0x800ce920 (VI, 5), 0x8005bec8/0x8005be40.
- VI manager: recibe y procesa (varios `osRecvMesg` OK entre bloques). Bloques en `0x800ce920`
  bajaron de 1488 → 298 (el resto del tiempo procesa).

### 3.2 Bloqueos restantes (confirmado)

- Cola principal `0x8005bf30`: **0 mensajes** enviados (`osSendMesg`/`EXT send` = 0). Thread 0
  dispatcher bloquea para siempre → el scheduler no postea la primera tarea.
- Thread 5 (`0x800011b0`) bloqueado en `0x8005be40` (count=1).
- Tareas RSP/gfx: **0** (`submit_rsp_task`/`send_dl` = 0). No hay render.
- Crash: `terminate called without an active exception` (race; no reproducido bajo gdb).

---

## 4. Cómo reproducir el run headless (NUEVO — GPU por software)

El contenedor no tiene GPU/Vulkan. Se instaló `mesa-vulkan-swrast` (lavapipe) + `xvfb`:

```sh
# Una sola vez:
apk add mesa-vulkan-swrast xvfb

# Arrancar display virtual (si no está activo):
rm -f /tmp/.X99-lock
Xvfb :99 -screen 0 1280x720x24 -nolisten tcp >/tmp/xvfb.log 2>&1 &

# Correr el build de Linux con Vulkan por software:
cd /app/hybrid-heaven-recomp/port/HybridHeavenRecomp/build
DISPLAY=:99 SDL_VIDEODRIVER=x11 \
  VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  ./"Hybrid Heaven Recomp" >/tmp/hh_run.log 2>&1
```

- La ROM retail debe estar como `baserom.us.z64` junto al ejecutable (16MB). Copiarla:
  `cp /app/baserom.us.z64 <builddir>/baserom.us.z64`.
  > Ojo: NO usar la ROM *dec* (us_dec.z64, 19782944 bytes). El juego valida hash
  > `0x0F6A72F2C36A216DULL` (retail 16MB). La retail es `/app/baserom.us.z64` (o
  > `work/roms/us_retail.z64`).
- **gdb** para backtrace: instalar `apk add gdb`. Usar `set pagination off`,
  `handle SIGABRT stop print nopass`, y `break std::terminate()`.
- El run NO usa la vía `build_dbg` del handoff; usa `build/` (Release). Puede usar `build_dbg` también.

---

## 5. Archivos modificados en esta sesión (runtime = repo N64ModernRuntime)

| Archivo | Cambio |
|---|---|
| `ultramodern/src/events.cpp` | `vi_event` en `events_context` + `case OS_EVENT_VI` en `osSetEventMesg` + disparo VI en `vi_thread_func` + `set_external_rdram(rdram)` en `init_events` |
| `ultramodern/src/mesgqueue.cpp` | `external_rdram` global + `set_external_rdram` + entrega directa en `enqueue_external_message_src/_message` + flush en bucle de `do_recv` |
| `ultramodern/include/ultramodern/ultramodern.hpp` | declaración `set_external_rdram` |

> Además, en sesiones previas sin commitear hay cambios de mapeo de funciones en
> `config/us_unified.syms.toml` y `config/RecompiledFuncs_unified/` (y su copia en
> `port/HybridHeavenRecomp/RecompiledFuncs/`), más scripts Ghidra sin trackear en
> `tools/analysis/ghidra_scripts/`.

---

## 6. TODO actualizado (Fase 2 / boot)

- [x] Build/run headless real del build de Linux (Xvfb + lavapipe).
- [x] Ghidra: mapear el scheduler completo.
- [x] FIX 1: fusionar `FUN_800011b0` truncado (thread-5 setup).
- [x] Resolver funciones faltantes (auto-loop): FUN_800326f0, 800349d0, 800295d0, 800329f0,
      800020b0, 8002bf90, 80034560, 800317c0.
- [x] FIX A: `osSetEventMesg` maneja `OS_EVENT_VI=7` (VI retrace).
- [x] FIX B: mensajes externos despiertan a game threads bloqueados (entrega directa + flush en do_recv).
- [x] Verificar que el VI manager ya no bloquea en `osRecvMesg(0x800ce920)` — CONFIRMADO en run.
- [ ] **Siguiente (bloqueante):** el scheduler sigue sin postear la primera tarea a la cola
      principal `0x8005bf30`. Thread 5 (`0x800011b0`) espera en `0x8005be40`. → atacar en Ghidra
      quién escribe el puntero a la cola (0x8004ab18) y quién hace el `osSendMesg` de la primera tarea.
- [ ] Race `terminate called without an active exception` (std::thread joinable) — menor, no
      bloqueante aún.

---

## 7. Próximo paso concreto

1. Ghidra (GUI o headless) → referencias a `0x8004ab18` (puntero a cola principal) → encontrar el
   scheduler que reparte el puntero y quién hace el `osSendMesg` de la primera tarea.
2. Entender por qué thread 5 (`0x800011b0`) se bloquea en `0x8005be40` antes de postear la tarea.
3. Si el emisor depende de un os func sin mapear → mapearlo con el método Goemon (handoff §3).
4. Regenerar + build + run headless (mando de §4) → ver si la primera tarea llega a `0x8005bf30`.
