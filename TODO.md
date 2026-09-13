# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** Estado: `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` (arquitectura/ADRs) y `notes/` (histórico). No duplicar.

## Ahora — primera divergencia de ejecución (arranque)

> **A3 (wiring de render) CERRADA**: verificado que eventos + routing RSP + `loadUCodeGBI` llegan a
> RT64 y éste procesa display lists. **A3b–A3h cerradas como fase de diagnóstico**: recompilación y
> carga son correctas (código/datos idénticos al emulador); el bloqueo es **orden/timing de
> ejecución** → apunta al **runtime** (scheduling de hilos/mensajes, lock single-CPU), no al juego.
> Detalle: `notes/2026-09-11-a3-multi-modulo-jumptables.md`.

1. [x] **Traza de mensajería (escalón 1)**: hecha. El port y el emulador divergen en el **orden de
   arranque de hilos / entrega de eventos** (runtime), no en lógica de juego (ver nota §escalón 1).
   Fix del oráculo: `r4300_regs` es `int64_t[32]` (el frontend lo leía mal) → exec-breakpoints ya dan
   args correctos; añadido `HB_TRACE_EXEC`.
2. [x] **Escalón 2 — runtime**: probado que los parches `>=` (prioridad) e idle de
   `run_next_thread_and_wait` **no** son la causa (revertidos y restaurados). **Medición decisiva**: el
   emulador avanza la fase a **VIS≈1857 (60 fps real)**; el port llega a VIS 5400 con fase 0 y **nunca
   escribe el progreso de carga `0x801CFE00/02`/`0x801D1E00`**. Lo avanzan funciones del módulo 23
   (`FUN_801cbdc0`…) referenciadas en un descriptor estático (`0x801CE65C`).
3. [x] **Diff alineado por frame (escalón 4)**: port volcado por VI (`HH_DUMP_VI`) vs emulador por
   tiempo. Primera divergencia de **juego** a **VI≈600**: `0x801CFE00` (progreso de carga) no se
   rellena en el port.
4. [x] **Ruta PI (escalón 5)**: `osCreatePiManager_recomp` es un **stub vacío** (no hay hilo del PI
   manager del juego); las estructuras `0x800CD79x` las copia un `memcpy` genérico. Confirmado:
   recompilación correcta, divergencia de **estado de arranque encadenado** (tarea de boot → objeto →
   índice). El método manual por capas ha llegado a su límite.
5. [x] **Traza de control (port↔emulador)**: construida. Port vía `get_function` (`HH_CALLTRACE`);
   emulador reconstruyendo mupen con trazador `jal`/`jalr` (`HH_JALTRACE`, requiere `binutils-dev` +
   `nasm`, `make all OSD=0 VULKAN=0 DEBUGGER=1`). **Primera divergencia de juego**: tras
   `FUN_80000EC8`, el port ejecuta `FUN_8001FEBC` y el emulador `FUN_800021B4` (función de hilo) →
   **los hilos corren en orden distinto** en el arranque. Raíz confirmada: **scheduler de hilos del
   runtime**.
6. [x] **Ruta SI/controller → DESCARTADA** (verificado): el port llama `osRecvMesg(0x8005CE20)` (cola SI)
   cada frame **sin bloquear**; la divergencia de traza en `FUN_800021B4` era por **orden de hilo**, no
   por la ruta SI. No era la causa raíz.
7. [•] **State machine de la tarea de arranque (`nodo 0x801D03C0`)** — causa real, confirmada por frame:
   la fase `0x80037750` sólo sube si `0x801CFE02==4` y `0x801CFE00>=0x97` (`FUN_801cbe90`); esos contadores
   los avanza `FUN_801cbe88` (callback del nodo, `+0x1C`), invocado por el dispatcher `FUN_80005270`
   (`ra=0x8000535C`) cada frame en el emulador desde t≈8.2 s. En el port el nodo se queda con
   `+0x1C=0x801C1034` (`FUN_801c0f70`) y **nunca** pasa a `0x801CBE88`; `FUN_801cbe88/90` **no se ejecutan**
   (gdb) y `fe00/fe02` quedan a 0 durante 90 s. **Detalle de la cadena**: el callback del nodo lo fija el
   setter `FUN_800058DC` (`sw a1,0x1C(a0)`). El port recorre el sub-chain **auto-terminante**
   `FUN_801c0f70 → FUN_801c0f98 → FUN_801c1034` (no-op); el emulador instala `FUN_801cbdc0`, que fija
   `node+0x1C=0x801CBE88` (`FUN_801cbe88`) y avanza la carga. **Origen**: `0x801D03C0` se instancia
   desde el struct runtime en `0x8005BDB4` (construido dentro de `FUN_8005ba00`); en el port queda sin
   construir (`0xFF00FF00…`). **Hipótesis de materialización de datos DESCARTADA**: región módulo 23
   16384/16384 palabras idénticas, `0x801CE65C` idéntico, el port tiene todos los datos (los grandes
   diffs son su heap en regiones vacías). Es **estado runtime**, no datos.
8. [x] **CAUSA RAÍZ del bloqueo original — input/controller + mid-entries**: la ruta SI/controller NO
   era (descartada). El juego ramifica según el estado de mandos: el port reportaba los 4 puertos
   conectados (`get_input` devolvía `true` para todos; `osContGetReadData_recomp` no escribía ausentes;
   `get_connected_device_info(0)` = None), desviando el state machine de boot. **Fix aplicado y
   verificado**: solo el puerto 0 responde, se escriben los 4 `OSContPad`, ctrl0 siempre presente.
   Además **mid-entries sin símbolo** (`0x8000106C`, `0x800165CC`, `0x80016634`) añadidas al syms y
   recompilado. **Resultado: el objeto de boot `0x801D03C0` ahora se instancia idéntico al emulador.**
9. [x] **BLOQUEO DE ARRANQUE RESUELTO (fase 0 → 1)**: causa = registro de recursos incompleto
   (`FUN_80125814` tomaba el camino "ya registrado" por un `v0` inestable → no registraba `0x18`/`0x91`)
   + mid-entry `0x8001769C` sin símbolo. **Fixes**: patch de instrucción
   (`config/game_combined.toml`: nop del `bne` en `0x8012591C` de `FUN_80125814`) y split del símbolo
   `FUN_80017608` (+`FUN_8001769c`). **Verificado**: la fase avanza a 1, `fe00/fe02` progresan y el port
   corre 180 s sin errores. Detalle: nota §bloqueo resuelto.
10. [•] **Siguiente: render/juego tras el arranque**: comprobar geometría/píxeles (RT64) y avanzar la
   fase más allá de 1; validar textos/audio/guardado.
11. [ ] **Validar en Windows (MSVC)** el estado actual (módulos 7/23/54 + audio no-op + apagado).
12. [x] **CAUSA RAÍZ del estancamiento total — Expansion Pak (memsize)**: el port arrancaba como
   máquina de **8 MB** y el juego exige **4 MB** (`osGetMemSize() == 0x400000` en `FUN_80001078`; si no,
   modo 1 = bucle de espera infinito). Fix en `lib/N64ModernRuntime/librecomp/src/recomp.cpp`
   (`osGetMemSize_recomp` y `osMemSize` → 4 MB). **Verificado**: modo 0, sin spin de `osGetTime`, 4
   display lists. Detalle: `notes/2026-09-13-arranque-memsize-y-accesorios.md`.
13. [x] **Loader: NO era el bloqueo**. Comparado el directorio Nisitenma port↔emulador:
    - El directorio es **estático** (magic `Nisitenma-Ichigo` en `0x80038FE0`, entradas u32 desde
      `0x80038FF0`; bit31 = comprimido). Rangos `0x80038F00`/`0x80037C00` y buffer DMA
      **byte-idénticos** port↔emulador (VI60). El chequeo del loader (nibble alto del header en
      `0x80089518`) también.
    - El port **sí carga** el módulo dado por saltado (`id=0x37`→ROM `0x68BF26`, Nisitenma idx54):
      3.ª llamada a `FUN_80003824` disparada por `FUN_801079B0` (init módulo 7, call site `0x80107A0C`),
      igual que el emulador (`ra=0x80107A14`).
    Detalle y trazas: `notes/2026-09-13-directorio-nisitenma-y-gate-rsp.md`.
14. [•] **Gate de tareas RSP + contexto VI — el bloqueo real**. `FUN_80001454` deja de llamar al
    dispatcher `FUN_80005270` cuando `[0x8008D545]==0 && [0x8005C4B0+0x89C]>=2` (gate en
    `0x80001820`). Cadena diagnosticada:
    - **Hecho**: `FUN_80030610` era el `osCreateMesgQueue` del ROM (centinela `&__osThreadTail` =
      `0x80049930`); el runtime de mensajes asumía listas NULL ⇒ sacaba/programaba el centinela como
      hilo (corrompía `__osRunningThread` y las colas). **Fix**: rename `FUN_80030610` →
      `osCreateMesgQueue` en las syms. Verificado: colas NULL, `__osRunningThread` válido.
    - **Resuelto (ADR 0003, opción A)**: el subsistema VI se genera del ROM (`osCreateViManager` y
      la familia `osVi*`); el runtime lee los registros VI MMIO para RT64. `OSViContext` correcto,
      dispatcher 430/45 s, loader 10 módulos, 1359 DLs a RT64, 0 símbolos faltantes (splits de
      mid-entries `0x80002364`, `0x800243F0`, `0x8002487C`…). Detalle:
      `notes/2026-09-13-vi-opcion-a-implementada.md` y ADR 0003.
    - **Frontera actual (deadlock SP)**: el port se congela con `[0x8005CD4C]=2`: **t18** espera la
      completación SP de una task audio (`0x800C89E8`) en `0x8005C598` y **t17** espera el ack de
      t18 por `+0x158` (`+0x890`/`+0x894` set). Las colas SP/DP son compartidas por t17 y t18; el
      runtime despierta a un solo waiter y una completación puede consumirla el hilo equivocado
      (race de timing; en el emulador ambos están idle). Efecto: dispatcher 9,5/s vs 36/s, sin
      transición (`fe00`, id 0x19 → ROM `0x5FBEC6` → `0x801BF1A0` a t≈63,9 s del emulador).
    - Siguiente: **asociar cada task RSP al hilo emisor** y entregar la completación SP a ese hilo
      (mapa task→thread en `submit_rsp_task`, entrega directa en `sp_complete`). Alternativas:
      serializar el SP en el runtime o replicar el timing del emulador. Detalle:
      `notes/2026-09-13-deadlock-sp-race.md`.
15. [ ] **Auditar accesorios N64 que alteran las entradas de arranque** (Controller Pak / Rumble Pak /
    device type por puerto): el boot ramifica según el estado SI. Ya nos han mordido input y Expansion
    Pak; comprobar bitpattern/`OSContStatus`/`get_connected_device_info` contra el emulador de
    referencia (sin mempak ni rumble) antes de dar por bueno el arranque. `osGbpakInit` queda
    **stubeado a "no pak"** (`GB_PAK_ERR_NOPAK`) en el runtime; validar que el boot no diverge por
    ello. Detalle: `notes/2026-09-13-arranque-memsize-y-accesorios.md` §5.

## Fundaciones pendientes

4. [•] **Higiene de runtime** (ligado al #2): **hecho 2026-09-12** — toda la traza verbose es opt-in
   (`HH_VERBOSE=1`), `boot_log` opt-in (`HH_BOOTLOG`), mensajes RSP warn-once; divergencias con upstream
   auditadas y documentadas en `docs/architecture.md` §5. Pendiente: decidir si el lock single-CPU se
   elimina (experimento: no cambia el bloqueo) y si se hace la entrega SI asíncrona.
5. [ ] **Interfaces de sub-objetivos** (texto/traducción, audio, guardado): contrato y punto de hook.
6. [ ] **Automatizar el inventario de módulos**: medir bases de forma desatendida (log del loader,
   p.ej. hook en `FUN_80003824`) y proponer las entradas de `MODULES`; hoy se miden con gdb.

## Backlog

- [ ] **Audio**: identificar el microcode custom KCEO (no matchea `aspMain`). **Puede ser el gate del render.**
- [ ] **Textos/traducción**: encoding + extracción + re-inserción (requisito de producto).
- [ ] **Guardado**: Controller Pak → ficheros en disco (+ Rumble).
- [ ] **Builds**: Windows + Linux + Steam Deck; resolución/widescreen; empaquetado sin ROM.
- [ ] **Tarea #3** (mapa overlay→RAM por BizHawk): complementa la medición empírica de bases.
- [ ] Limpiar data-as-code (189 sospechosas) → habilita re-evaluar `use_lookup_for_all_function_calls=false`.

## Hecho (2026-09-11)

- [x] **A3* diagnóstico cerrado**: wiring de render OK; divergencia de arranque identificada como de **orden/timing** (runtime), no de recompilación (código/datos idénticos al emulador).
- [x] **A3 wiring verificado**: eventos + routing RSP + `loadUCodeGBI` → RT64 procesa display lists (no era el bloqueante).
- [x] **Oráculo emulador** (`r64dump`): volcados por tiempo, watchpoints exactos (`HB_WP_SIZE`), volcado one-shot por watchpoint (`HB_DUMP_ON_WP`); diff port↔emulador documentado (`docs/workflows.md` §6/§6.1).
- [x] **Pipeline multi-módulo** (`setup_module.py`): integra idx **7, 23, 54** como secciones, bases deterministas (3 runs), `lzkn64` + CRC.
- [x] **`gen_module_syms.py` consciente de jump-tables**: fusiona dispatch+cases (46/46 tablas OK); elimina `switch_error`.
- [x] **Fix de pipeline**: limpiar `RecompiledFuncs/funcs_*.c` antes de copiar (evita multiple definition).
- [x] **0 faltantes / 0 `switch_error` / 0 `do_break`**; el boot corre indefinidamente.
- [x] Boot **estable** + **apagado limpio** (9d: `ultramodern::quit()` + `return 0`).
- [x] **Audio RSP no-op** (A1): tareas sin ucode se completan como dummy.
- [x] **Pipeline reproducible** `tools/recomp.py` + **validador** `validate_syms.py` (+ `gen_module_syms.py`, `fix_function_bounds.py` report-only).
- [x] **Modelo de módulos `trans`** caracterizado + **ADR 0001** aceptado (base determinista, blob autoligado).
- [x] **Documentación consolidada** (modelo por capas) + protocolo de imágenes.
- [x] (histórico) Toolchain/repos/extracción Nisitenma; port + builds; syms Ghidra; fix DMA; game loop; scheduler VI.

## Documentos de detalle (no duplicar)
`PROYECTO.md` (estado) · `docs/architecture.md` · `docs/adr/` · `docs/workflows.md` ·
`notes/2026-09-11-*.md` (modelo módulos, B9, A1, A2, 9d, pipeline).
