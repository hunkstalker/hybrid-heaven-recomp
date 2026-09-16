# SESIÓN 2026-09-10 — Investigación del RENDER: hallazgos y dónde se quedó el trabajo

> Complementa `notes/2026-09-10-scheduler-diagnosis.md`, `notes/2026-09-10-windows-build.md` y
> `notes/2026-09-10-render-blocker.md`. Documenta la sesión de investigación del bloqueo de render
> (pantalla negra) usando el **emulador (BizHawk) + dumps de RAM**, y el estado exacto para retomar.
>
> ⚠️ **CORRECCIÓN 2026-09-10 (sesión posterior): la "sospecha principal" de este doc está REFUTADA.**
> `0x8005BE40` NO es un struct de contexto: es una **cola de mensajes stack-local** (`sp+0x28`) de
> `FUN_80027f20` (pila del thread 5), creada con `osCreateMesgQueue`. Ver §7 al final.

## 0. RESUMEN EJECUTIVO — estado para retomar

- El port **compila y hace boot** (Linux y Windows). El juego **no renderiza** (pantalla negra).
- **Diagnóstico CORREGIDO**: la teoría del "gate por `DAT_80037750`" era **incorrecta**.
- El render del juego real va por la **cola principal `0x8005BF30` + dispatcher** (no por la
  máquina de estados `FUN_80001454`).
- **Sospecha principal (a confirmar)**: el runtime recompilado trata `0x8005BE40` como **cola**
  (`osCreateMesgQueue` + `osRecvMesg` → thread 5 bloqueado), pero en el juego real `0x8005BE40` es
  un **struct de contexto/frame**, no una cola. Posible **error de recompilación/mapeo**.
  → **REFUTADA en la sesión posterior (ver §7).** `0x8005BE40` SÍ es una cola (stack-local).
- El punto exacto donde se quedó: thread 5 (game loop) bloqueado en `osRecvMesg(0x8005be40)`.

## 1. Confirmaciones con el emulador (BizHawk) — dumps reales

Se amplió `work/gameplay screenshots/bizhawk_hh_tracker.lua` (y copia **`bizhawk_hh_tracker_v2.lua`**)
para que el F12 vuelque, además del directorio de overlays, estas estructuras:
- `0x800CC300` (struct de tarea / dispatcher)
- `0x8004AED0` (punteros `_LAB_8004aed0/_aed4`)
- `0x8005BE40` + `0x8005BF30` (colas)
- `0x80037720-0x80037770` (estado de render)

**Captura en el menú (frame 897, renderizando):**
```
# 0x8005BF30 (cola principal):
+0x00 blocked_on_recv = 0x800CC300   <- dispatcher (thread 0) bloqueado esperando
+0x08 validCount      = 0x00000000   <- cola vacía (ya consumió la tarea)
+0x10 msgCount        = 0xC8 (200)
# 0x80037730/3738/3750 = 0 (máquina de estados NO activa)
# 0x8005BE40: NO parsea como OSMesgQueue limpia
```

**Lecturas clave:**
1. `DAT_80037750/3730/3738 = 0` incluso renderizando → `FUN_80001454` NO es el camino del render
   del menú. (La teoría del gate era errónea.)
2. El render del menú va por la **cola principal `0x8005BF30` + dispatcher** (idle tras renderizar).
3. **`0x8005BE40` NO es una cola** — sus campos (`0x800892B0`=datos controller,
   `0x8005C4F0`/`0x8005C458`=colas RSP, `0x80037748`=flag battle) sugieren un **struct de
   contexto/frame**.

## 2. Diferencia emulador vs runtime recompilado

| | Emulador (real) | Runtime recompilado |
|---|---|---|
| Thread 5 (game loop) | corre, envía tareas a `0x8005BF30` → render | **clavado en `osRecvMesg(0x8005BE40)`** |
| `0x8005BE40` | struct de contexto (no cola) | tratado como **cola** (`osCreateMesgQueue` + `osRecvMesg`) |
| Render | vía cola principal + dispatcher | no llega (game loop colgado) |

## 3. Búsquedas hechas (resultado negativo, útil para no repetir)

- **Literal `0x8005BE40`**: NO aparece como constante en `funcs_0..6.c` ni `recomp_overlays.inl`
  (es un puntero **calculado en runtime**, p.ej. `0x80060000-0x41C0` o `0x8005xxxx+offset`).
- **`osRecvMesg(0x8005be40)`**: el `osRecvMesg` del recompilado `FUN_800011b0` es sobre
  **`0x8005c288`** (el bucle), NO sobre `0x8005be40`. El `osRecvMesg(0x8005be40)` proviene de una
  **función llamada por el setup de thread 5** (no de `FUN_800011b0` directamente).
- **Setup funcs decompiladas** (`FUN_800020b0`, `FUN_80016df0`, `FUN_80005444`, `FUN_80000460`):
  **ninguna** crea `0x8005be40`.
- **Write-breakpoint del harness (`HB_RES_DIR=0x8005be40`)**: captura writes pero **contaminados**
  porque la región `0x8005be40` se solapa con las **pilas de los threads** del juego (pila de
  osSendMesg en `0x8005BE0C`, otra función en `0x8005BE80`). Los writes son **guardas de pila**, no
  el post a la cola. **No usar write-bp ahí.**

## 4. Herramientas usadas / estado del harness

- El harness del entorno de desarrollo (`work/r64dump`, fuente `tools/analysis/r64dump.cpp`) **se recompiló** para
  loguear `ra` (return address) en los hits:
  ```
  g++ -o work/r64dump tools/analysis/r64dump.cpp -Iwork/debug/mupinc -ldl -lX11 -lXext -lGL -l:libGLU.so.1
  ```
  - `work/debug/mupinc/mupen64plus -> $MUP/src/api` (symlink para el include `<mupen64plus/...>`).
  - Se instalaron deps: `apk add glu libsamplerate`.
  - Config/plugins: `M64P_CONFIG_DIR=work/wsl_package M64P_PLUGINDIR=.../plugins`, y el ini
    `Glide64mk2.ini` en `work/wsl_package/plugins/` (necesario para que glide inicialice headless).
  - `HB_RES_DIR=<vaddr>` = write-bp; `HB_EXEC=<vaddr>` = exec-bp; `HH_WP_ARM` = tiempo de armado.
- **Los write-bps son útiles PERO la región `0x8005be40` está contaminada por las pilas** → usar con
  cautela o en otra región.

## 5. Estado de los repos

- `RecompiledFuncs/` unificado (341 funcs) + assets + src versionados. Fixes MSVC documentados.
- N64ModernRuntime con fixes en el working tree (committed). Traza `[RND]` en events.cpp.
- `tools/analysis/r64dump.cpp` modificado (log de `ra`) — **commit pendiente** si se quiere
  conservar. Script BizHawk ampliado (`bizhawk_hh_tracker.lua` + `bizhawk_hh_tracker_v2.lua`).

## 6. PRÓXIMO PASO (para la nueva sesión)

1. **Confirmar la sospecha**: rastrear el **caller real** del `osCreateMesgQueue(0x8005be40)` en
   runtime (qué función recompilada lo origina) y comparar con el emulador.
   - Método sugerido: exec-bp sobre `osCreateMesgQueue`/`osRecvMesg` del runtime con captura de
     caller, o Ghidra sobre la función del setup que calcula `0x8005be40` en runtime.
2. **Si se confirma que `0x8005be40` es un struct de contexto (no cola)** → el bug está en el
   recompilador/runtime: no debe tratarlo como cola. Revisar el `osRecvMesg`/`osCreateMesgQueue`
   recompilados que apuntan ahí.
3. **Alternativa**: volcar desde BizHawk el **caller** o un rango más amplio alrededor de
   `0x8005BE40` para entender el struct completo (contexto/frame) y su rol.

## 7. CORRECCIÓN 2026-09-10 — la sospecha está REFUTADA (investigación de la sesión posterior)

Se instrumentó el runtime para capturar el **caller real** de `osCreateMesgQueue(0x8005be40)` y
`osRecvMesg(0x8005be40)` (shims en `ultra_translation.cpp` + `dladdr`/`addr2line` sobre el binario
Linux headless). Resultado:

- **`0x8005be40` NO es un struct de contexto. Es una COLA de mensajes stack-local.**
- Caller resuelto: **`FUN_80027f20`** (funcs_6.c:1252), que corre en la pila del **thread 5**
  (`sp≈0x8005be18`). La cola es un local `sp+0x28` = `0x8005be40`.
- `FUN_80027f20` hace: chequea flag global `0x80049960` → computa un **deadline** (`FUN_80031190`→
  `osGetCount`) → crea la cola local → configura un **timer** (`FUN_80034560`→`FUN_80031498`) →
  `osRecvMesg(0x8005be40, BLOCK)`. Es una espera por **timer/timeout**.
- `FUN_80027f20` es llamada por `FUN_800020b0` (0x80002100), que a su vez la llama `FUN_800011b0`
  (thread 5, 0x80001304).

**Causa raíz (patrón del TODO #7, osCreateViManager):** el juego usa su **propio** libultra
`osSetTimer` (dividido en `FUN_80034560`+`FUN_80031498`), compilado como código de juego y **NO**
mapeado al runtime `osSetTimer_recomp`. Ese osSetTimer del juego gestiona su lista de timers en el
global `0x8004ae60`, cuyo **sentinel nunca se inicializa (=0)** → el juego no llega a registrar
timers, y además el `timer_thread` del runtime **solo dispara** timers registrados vía
`osSetTimer_recomp` (que el juego no llama). Resultado: ningún timer dispara → nunca postea a
`0x8005be40` → thread 5 colgado. (Coincide con la hipótesis de `render-blocker.md`: mecanismo
custom del motor Konami no interceptado por el runtime.)

**Fixes intentados y resultado (TODOS revertidos a baseline conocido-bueno):**
1. Mapear `FUN_80031498`→`osSetTimer` en la syms: el timer **empezó a disparar** (countdown=500ms,
   progreso real), pero el shim leyó `mq=0`/`msg=0` (ABI incompatible: `FUN_80031498` es el
   insertador que lee el struct pre-rellenado, no args de pila) → SIGSEGV. **Revertido**.
2. Hacer que `timer_thread` del runtime haga **polling** de la lista de timers del juego (0x8004ae60)
   y dispare los vencidos (timestamps relativos estilo libultra): no dispara porque la lista está
   **vacía** (0x8004ae60=0, el sentinel no se inicializó). **Revertido**.

**Estado actual:** de vuelta al baseline conocido-bueno (boot OK, thread 5 bloqueado en
`0x8005be40`). Siguiente paso: investigar con Ghidra el sistema de timers del juego (dónde se
inicializa el sentinel de `__osTimerList`/0x8004ae60, mapear `osGetCount`/`osSetTimer` para que el
juego use el mecanismo del runtime), y **confirmar** si la espera de thread 5 es por timer o por
completado de tarea RSP (teoría de render-blocker).
