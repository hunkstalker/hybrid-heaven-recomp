# HANDOFF Fase 2 — Boot del núcleo plano + scheduler (2026-09-10)

> Este documento consolida TODO el contexto para retomar el trabajo de **Fase 2 (recompilación/boot)**
> en una sesión nueva, sin depender del historial del chat. Léelo entero antes de tocar nada.

---

## 0. Objetivo de Fase 2 y estado

**Objetivo:** recompilar el núcleo plano de Hybrid Heaven (N64Recomp) y hacer que el juego arranque
y llegue a gameplay en el runtime (RT64/N64ModernRuntime).

**Estado alcanzado (2026-09-10, actualizado al final de la sesión):**
- ✅ El juego **compila** (build Linux `build_dbg` y `build`, `Hybrid Heaven Recomp`).
- ✅ **Boot completo**: `init_heap → init_saving done → Calling entrypoint → Entrypoint returned`,
  y **se crean y ejecutan threads del juego** + RT64 setup OK.
- ✅ De SIGSEGV/crash → **juego estable (sin crash)**.
- ✅ **FIX deadlock VI**: el VI manager (`FUN_80034840`) ya **no se deadlockea**; recibe y procesa
  mensajes VI. Se arregló `osSetEventMesg` (faltaba `OS_EVENT_VI=7`) y la **entrega de mensajes
  externos** (los mensajes VI/AI/SP/DP ahora despiertan a los game threads bloqueados). Verificado
  en run headless real. Detalle en `notes/2026-09-10-session-vi-mesg-fix.md`.
- ❌ **Bloqueante (sigue)**: el thread principal (FUN_8002AEA0) bloquea en `osRecvMesg(BLOCK)` en la
  cola principal **0x8005bf30** esperando la **primera tarea del scheduler del motor Konami** que
  nunca llega (0 mensajes enviados; sin tareas RSP ni de render). → deadlock previo a gameplay.
- ⚠️ Crash secundario (race): `terminate called without an active exception` tras procesar mensajes
  VI. Dependiente de timing; no reproducido bajo gdb.

---

## 1. Cómo reproducir el build y el run

### Build (Linux, contenedor)
```sh
cd /app/hybrid-heaven-recomp/port/HybridHeavenRecomp
cmake --build build_dbg --target HybridHeavenRecomp -j$(nproc)
```

### Regenerar funciones (tras tocar el syms/config)
```sh
# El generador N64Recomp está en port/.../N64Recomp/build3/N64Recomp (target N64RecompCLI)
cd /app/hybrid-heaven-recomp
rm -rf config/RecompiledFuncs_unified          # SIEMPRE borrar antes (evitar stale files)
./port/HybridHeavenRecomp/lib/N64ModernRuntime/N64Recomp/build3/N64Recomp config/game_unified.toml
rm -rf port/HybridHeavenRecomp/RecompiledFuncs
cp -r config/RecompiledFuncs_unified port/HybridHeavenRecomp/RecompiledFuncs
# luego rebuild
```
> **Importante:** los archivos stale (funcs_*.c viejos) inflaban el conteo y daban falsos errores
> (p.ej. `FUN_80034c90` que no existía). Siempre regenerar limpio.

### Run headless (el juego corre pero sin ventana/audio)
```sh
cd /tmp/hh_run
rm -f boot.log /tmp/hh_crash.log
DISPLAY=:99 SDL_AUDIODRIVER=dummy HH_CRASH_LOG=1 timeout 40 \
  "/app/hybrid-heaven-recomp/port/HybridHeavenRecomp/build_dbg/Hybrid Heaven Recomp" >boot.log 2>&1
```
- `boot.log` — salida del juego (init, threads, etc.).
- `/tmp/hh_crash.log` — crash backtrace (si HH_CRASH_LOG=1).
- `~/.local/share/HybridHeavenRecomp/hh.log` — log de setup RT64.
- **exit=124** = timeout = el juego corrió los 40s (vivo). Si el proceso está idle (utime no sube,
  threads en `S`), está en deadlock.

### Script de iteración rápida
`/tmp/hh_iter.sh` — regenera + build + run + reporta "Failed to find function". Útil para el loop
de mapeo de os funcs.

---

## 2. Herramientas instaladas (en el contenedor)

- **capstone** (disassembler MIPS): `pip install --break-system-packages capstone`.
- **Git**: `apk add git`.
- **Java 21 + bash**: `apk add openjdk21 bash` (necesarios para Ghidra).
- **Ghidra 12.1.3**: `toolchain/ghidra/ghidra_12.1.3_PUBLIC`. Proyecto en `work/ghidra/proj` (HH.gpr).

### Scripts de análisis (en `/tmp` y `tools/analysis/`)
- `/tmp/mips_dis.py <rom> <vram> <n>` — disassembler capstone (ROM default = HH us_retail.z64;
  pasar `mnsg.z64` de Goemon como primer arg para Goemon).
- `/tmp/match_os3.py` — empareja os funcs de Goemon→HH por bytes.
- `/tmp/add_func.py <vram>` — añade una FUN_ al syms.
- `/tmp/find_hh_event.py`, `/tmp/find_viset.py`, `/tmp/find_mainq.py` — escaneos de patrones.
- `tools/analysis/ghidra_scripts/*.java` — scripts Ghidra (FindMainQ, FindSender, Decomp*).

---

## 3. Método Goemon para os funcs (EL KEY para mapear os funcs)

El **libultra es byte-idéntico entre Goemon (Mystical Ninja) y Hybrid Heaven** (osCreateThread
coincide exactamente). El motor es el mismo (Konami). Para mapear una os func de HH:

1. `Goemon64RecompSyms/mnsg.syms.toml` (en `/app/goemon-sourcecode`) — lista de 75 os funcs con vram.
2. Desensamblar la os func de Goemon: `python3 /tmp/mips_dis.py /app/goemon-sourcecode/mnsg.z64 <vram> <n>`.
3. Buscar el byte-sequence en el ROM de HH (emparejando; enmascarando el operando del `jal` y la
   dirección de tabla que difieren).

**os funcs ya mapeadas en `config/us_unified.syms.toml`** (NO repetir):
| os func | vram HH | | os func | vram HH |
|---|---|---|---|---|
| osCreateThread | 0x80028260 | | osRecvMesg | 0x800266B0 |
| osStartThread | 0x80034C90 | | osSendMesg | 0x80026300 |
| osSetThreadPri | 0x80030B60 | | osJamMesg | 0x80030A10 |
| osGetThreadId | 0x80030C40 | | osCreateMesgQueue | 0x80030610 |
| osStopThread | 0x80029580 | | osSetEventMesg | 0x8002FB60 |
| osCreateViManager | 0x80032220 | | osViSetMode | 0x80032360 |

> **CORRECCIÓN IMPORTANTE:** osSendMesg = 0x80026300 y osJamMesg = 0x80030A10 (estaban AL REVÉS;
> se corrigió con el método Goemon, que es autoritativo por bytes).

> **NOTA:** el byte-matching NO sirve para funciones de JUEGO (difieren entre Goemon y HH por el
> contenido), solo para os funcs (libultra compartido).

---

## 4. Mapa de os funcs pendientes (candidatas, NO mapeadas aún)
- `osViSetEvent` (conecta vblank VI→cola; no encontrada por patrón — layout difiere de Goemon).
- `osSpTaskStartGo`, `osSpTaskLoad`, `osSpTaskYield`, `osSpTaskYielded`.
- `osContInit`, `osContStartReadData`, `osContGetReadData`.
- `osCreatePiManager`, `osPiStartDma`, `osPiReadIo`, `osCartRomInit`.
- `osSetTimer`, `osGetTime`, `osGetCount`.
- `osDestroyThread`, `osYieldThread`, `osGetThreadPri`.
- `osDpSetNextBuffer`, `osAiSetNextBuffer`, `osViSwapBuffer`, `osViBlack`.

---

## 5. Diagnóstico del deadlock (confirmado)

**Flujo de boot (decompile Ghidra):**
- ramMain (0x80000400) → `FUN_80001078`: `osInitialize` + crea thread 1 (FUN_80001124), lo arranca, retorna.
- **Thread 1 (FUN_80001124)**: crea la **cola principal 0x8005bf30** (count=200), crea thread 5
  (FUN_800011b0), lo arranca, y **gira en loop infinito**.
- **Thread 5 (FUN_800011b0)**: crea colas 0x8005c268/0x8005c288, hace `osRecvMesg(BLOCK)` en 0x8005c288.
- **Main thread (FUN_8002AEA0)**: loop de despacho de tareas. `osRecvMesg(BLOCK)` en la cola
  principal 0x8005bf30 como primera acción. Bloqueado.

**Causa raíz:** el thread principal espera la primera tarea en 0x8005bf30; **nadie la envía**. La VI
vblank dispara (RT64) pero con `mq=NULLPTR` (el juego conecta el evento VI a 0x800cd4b0 vía
`osSetEventMesg event=8`, NO a la cola principal). El emisor de la cola principal es el **scheduler
del motor Konami** (lógica de juego), no un os function.

**Lo que se probó y NO funcionó:**
- Mapear osCreateViManager/osViSetMode → el deadlock no cambió.
- Mapear osSetEventMesg → ahora se llama (event=8→0x800cd4b0) pero el VI no alimenta la cola principal.
- Mapear osSendMesg/osJamMesg/osRecvMesg/osStopThread → threads corren pero el deadlock persiste.
- Buscar el emisor por patrón (capstone) y por Ghidra (referencias a 0x8005bf30) → solo FUN_80001124
  (que la crea) la referencia; el emisor usa **puntero** (no referencia directa).

**Trazas runtime activas (temporales, en el código):**
- `[TH]` en osCreateThread/osStartThread (threads.cpp) — id, entry, arg.
- `[MQ]` en osCreateMesgQueue/osSendMesg/osRecvMesg/do_recv (mesgqueue.cpp) — mq, flags, caller.
- `[EV]` en osSetEventMesg y disparo VI (events.cpp) — event, mq, msg / "fire but mq=NULLPTR".
- `[RT]` en run_thread_function (recomp.cpp) — thread addr/sp/arg.
- Estas trazas son útiles para seguir debuggeando.

---

## 6. Cómo atacar el scheduler (plan Ghidra — lo más prometedor)

El emisor de la cola principal usa un **puntero** (el main thread lo lee de `[arg+8]`, arg=0x8004ab10,
así que el puntero a la cola está en `0x8004ab18`). Plan:

1. **Encontrar quién escribe el puntero a la cola principal** (a 0x8004ab18 o a un global): es el
   "scheduler" o el que reparte el puntero. Con Ghidra: referencias a `0x8004ab18`.
2. **Encontrar quién lee ese puntero y hace osSendMesg** → ese es el emisor de la primera tarea.
3. **Entender por qué no corre**: ¿está bloqueado en otro osRecvMesg? ¿No se crea su thread?
4. Decompilar el emisor con `ghidra_loader.java`/Decomp scripts.

**Comandos Ghidra headless:**
```sh
export JAVA_HOME=/usr/lib/jvm/openjdk21
export PATH=$JAVA_HOME/bin:$PATH
toolchain/ghidra/ghidra_12.1.3_PUBLIC/support/analyzeHeadless work/ghidra/proj HH \
  -process -scriptPath <dir> -postScript <Script.java>
```
> **Ojo:** Ghidra cachea la compilación de scripts → "ClassNotFoundException" intermitente. Solución:
> renombrar el archivo/clase (RefAEA0v2) o recompilar. Los scripts .java deben tener la clase pública
> con el MISMO nombre que el archivo.

**Ghidra interactivo** es más robusto que headless para análisis profundo (escribir un script,
reabrir, inspeccionar). Si se retoma, usar la GUI de Ghidra con el proyecto HH.

---

## 7. Archivos clave y estados

- `config/us_unified.syms.toml` — syms con os funcs + mid-funciones añadidas (el trabajo de mapeo).
- `config/game_unified.toml` — `use_lookup_for_all_function_calls = true`, `ignored=["FUN_800493c4"]`.
- `config/RecompiledFuncs_unified/` — funciones generadas (fuente de la generación).
- `port/HybridHeavenRecomp/RecompiledFuncs/` — copia que usa el build (sincronizar tras regen).
- `port/HybridHeavenRecomp/CMakeLists.txt` — `file(GLOB RecompiledFuncs/funcs_*.c)`.
- `port/HybridHeavenRecomp/lib/N64ModernRuntime/ultramodern/src/threads.cpp` — `_thread_func`
  mantiene `__osRunningThread` (0x80049940) + trazas `[TH]`.
- `port/HybridHeavenRecomp/lib/N64ModernRuntime/ultramodern/src/mesgqueue.cpp` — trazas `[MQ]`.
- `port/HybridHeavenRecomp/lib/N64ModernRuntime/ultramodern/src/events.cpp` — trazas `[EV]`.
- `port/HybridHeavenRecomp/lib/N64ModernRuntime/librecomp/src/recomp.cpp` — traza `[RT]`.
- `port/HybridHeavenRecomp/src/main/main.cpp` — crash handler (si_addr/rip) + set_terminate.
- `port/HybridHeavenRecomp/lib/N64ModernRuntime/N64Recomp/src/{operations,recompilation}.cpp` —
  cambios en el submódulo N64Recomp (trunc.l.s/d + no-ops + Match→lookup). **Respaldados en
  `config/n64recomp_changes/`** (N64Recomp es submódulo sin .git inicializado → NO versionados por git).
- Notas: `notes/2026-09-10-recomp-fase2-boot.md` (todo el detalle), `notes/2026-09-10-scheduler-ghidra.md`.

---

## 8. Repos git y estado

- **Main repo** (`/app/hybrid-heaven-recomp`, branch main): limpiar al cerrar. Commits recientes:
  `3ed3570` (Ghidra operativo), `665bacb` (plan Ghidra), `fd01984` (checkpoint), `d884768` (Goemon),
  `1587288` (juego estable).
- **N64ModernRuntime** (`port/.../lib/N64ModernRuntime`): repo separado; commits de traces/threads.
- **N64Recomp**: submódulo SIN .git → cambios respaldados en `config/n64recomp_changes/`.
- **rt64**: submódulo (no tocado).
- El `.gitignore` excluye builds, ROMs (work/), toolchain, repos anidados y generaciones viejas.

---

## 9. Próximo paso concreto (para la sesión nueva)

> **DIAGNÓSTICO del scheduler (2026-09-10, post-Ghidra):** thread 5 (FUN_800011b0) bloquea en
> osRecvMesg(0x8005be40) antes de su main loop; el VI manager reenvía la vblank via osSendMesg a
> [structVI+0x10] (NULL en recompilado); el juego registra el VI (osViSetEvent FUN_800329f0 via
> FUN_80000460:1054) hacia 0x8005c560, NO a 0x8005be40; 0 tareas RSP. Arquitectura completa y
> cadena del deadlock en **`notes/2026-09-10-scheduler-diagnosis.md`**. Siguiente: instrumentar
> runtime (osViSetEvent, osCreateMesgQueue caller, submit_rsp_task) y re-run headless.

1. Abrir Ghidra (GUI o headless) con el proyecto HH.
2. Referencias a `0x8004ab18` (donde el main thread lee el puntero a la cola principal) → encontrar
   el scheduler que reparte/usa ese puntero.
3. Identificar al emisor de la primera tarea (osSendMesg con ese puntero) y por qué no corre.
   OJO: en el run headless real, thread 5 (`FUN_800011b0`) queda bloqueado en `osRecvMesg` de la
   cola **0x8005be40** (count=1) ANTES de poder postear la tarea — investigar qué envía a 0x8005be40.
4. Si depende de un os func sin mapear → mapearlo con el método Goemon (§3).
5. Regenerar + build + run headless → ver si el deadlock se desbloquea.

> **Para el run headless del build de Linux** (requiere GPU por software): ver
> `notes/2026-09-10-session-vi-mesg-fix.md` §4 (Xvfb + `mesa-vulkan-swrast`/lavapipe +
> `VK_ICD_FILENAMES`). La ROM retail (16MB) debe estar como `baserom.us.z64` junto al ejecutable.

**Repos clave para el contexto:**
- `/app/goemon-sourcecode` — ROM + syms + N64Recomp de referencia (mismo motor Konami).
- `/app/hybrid-heaven-recomp` — el proyecto HH.
