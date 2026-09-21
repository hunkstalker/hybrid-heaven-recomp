# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` y `notes/` (no duplicar). Histórico: `notes/`, `notes/archive/`.

## Ahora (priorizado)

- [•] **Migrar a la vía de recompilación de la referencia (ELF + splat + residente limpio)**. Decisión
  2026-09-21 (ADR 0011): se abandona Ghidra-per-file (fronteras de imagen incompleta; el build llega
  al título sin fondo 3D). Plan por fases M0–M5 con gates:
  `notes/2026-09-21-migracion-via-referencia-elf.md`. **M0 HECHO** (splat 0.50.0 + spimdisasm 1.42.4
  en `toolchain/splat-venv`; MIPS por LLVM `llvm-mc`/`ld.lld`; `tools/install_splat.sh`,
  `tools/splat_headless.sh`). **M1 HECHO** (`tools/unpack_rom.py`: imagen expandida + `segments.json`
  + `file_table.h`; 91 code files, 0x368070 bytes). **M2 HECHO** (`tools/build_elf.sh` + `gen_link_syms.py`:
  splat → `llvm-mc` → `ld.lld` → `elf/hybrid-heaven.us.elf`; gate: reconstruye la imagen byte a byte).
  **M3 HECHO** (N64Recomp ELF mode, rc=0). **M4/M4b en curso**: libultra de hilos runtime-owned (arregló
  la recursión de `osDestroyThread`); falta que el bucle corra → **M4b.2** `__osDispatchThread`/
  `__osDequeueThread` en el runtime. Sub-paso: libultra del runtime (choca con ADR 0002/0003).
- [ ] **Migración a submódulos (hecho, sin commitear)**: `lib/{N64ModernRuntime,rt64}` como submódulos
  (ADR 0010); `regenerate.py` materializa el C como dir real; falta el push/force-push de los forks
  para que un clon limpio los resuelva.
- [ ] **Audio: sincronizar la tasa** (feedback del error de cola SDL en `osAiGetLength`) para quitar
  los descartes periódicos del watermark. Ver `notes/2026-09-18-suavizado-fase1-y-cache-loader.md` §2.
- [ ] **Menú IN-GAME de opciones PC (ADR 0008)**: reutilizar el menú del `expansionram` (módulo idx 23).
  **Antes: spike go/no-go** (nota 09-18 §6: handler de módulo end-to-end, rótulo con fuentes del juego,
  aplicar/persistir `GraphicsConfig`).
- [ ] **Definir ADR 0009** (estrategia de cobertura nativa / clean-room) **cuando se adopte la visión**
  de `docs/README.md`. Incluye el **manifiesto de reimplementadas** + **métrica de cobertura** (§5).
- [ ] **Teardown SEGV** al cerrar en Windows (`exe +0x12A602`): mapear con el `.map`, reproducir en
  Linux y arreglar el orden de deinit (respuesta a `EXCEPTION_EXECUTE_HANDLER`).
- [ ] **Mando**: identificar el botón N64 que abre el menú de **acciones/lucha en CaC** y asignarlo a
  **X** (`config.ini`). **Bloqueado por el CaC** (el juego se congela antes del combate): revisar cuando
  se resuelva la entrada al combate. Lo normal (pausa/inventario) sale con **Start** y está bien.
  Decidir también `LB` y el atajo de cámara/1ª persona.
- [ ] **Limpieza de instrumentación**: decidir sobre `requeue_pi=true`, los `[MQDROP]`, la sombra
  `hh_sh_*` y el watchpoint (ya está todo gated tras `HH_DIAG`).
- [ ] **Smoke de arranque** (opcional, requiere ROM): con la ROM en `rom\` junto al `.exe`, comprobar
  que la encuentra y que no hay `Failed to find function`. En Docker: `HH_HEADLESS=1` + `rom/`.

## Backlog (priorizado)

- [ ] **CaC: el port no entra al combate (BLOQUEANTE)**. Estado 2026-09-20 (noche-5); **detalle y
  plan único**: `RETOMAR.md` y
  **`notes/2026-09-20-nodo-8005bf14-origen-y-captura.md`** (empezar aquí); antes:
  `notes/2026-09-19-causa-raiz-cadencia-frames.md`, `notes/2026-09-19-bat-stall-check.md`,
  `notes/2026-09-19-verificacion-cadencia-y-harness-replay.md` y
  `notes/2026-09-17-replay-mode-vi-vis-negativo.md` (§3/§5).
  - **MECANISMO INMEDIATO (RESUELTO, noche-5)**: en el CaC la **cadena del disable** tiene
    **mid-entries** (`M55_FUN_80379410/424/444/464`, sin prólogo) **y** el dispatcher `FUN_80005270`
    que devuelven `sp +0x58`; el `sp` del hilo 5 trepaba `~0x58/frame` y pisaba el marco de
    `FUN_800011b0` (nodo de suscriptores `0x8005BF14`) → `[BADMQ]`/deadlock. **Fix `HH_M55SPFIX=1`**
    (restaura `sp`): **validado en Windows** — el nodo ya no se corrompe y **el juego llega al CaC con
    el HUD de combate apareciendo**.
  - **NUEVO BLOQUEO**: el port sigue instalando el veneno y hace un **livelock** de tid 5 en M10/M12
    del CaC (`M10_FUN_80228298`, `ra=000000FE`) con el HUD apareciendo (sin corrupción de pila).
  - **AGUAS ARRIBA**: el port despacha el evento temporizado `0x39` y ejecuta el instalador
    `M10_FUN_8021b240` (puerta `M7_FUN_80126A0C(obj,0x39,1)` devuelve 1 con `42D0=0x2B88`); el
    **emulador nunca** lo hace (0 ejecuciones). `42D0` (`[0x8008D580]`) = acumulador del scheduler
    `FUN_80004bb0` (`FUN_80001454` lo resetea cada frame; la puerta compara con `0x3001`).
  - **Plan restante** (`RETOMAR.md` §5): (1) test `run_stackfix_nob280.bat` (`HH_NO_B280=1` con la pila
    sana): ¿el combate avanza? → el veneno es el bloqueador restante; (2) si no, analizar el livelock
    (`M10_FUN_80228298`); (3) arreglo limpio de la clase de fugas = corregir **fronteras de símbolos**
    (mid-entries internos a su contenedor).
  - **Descartado** (no repetir, ver inventario `RETOMAR.md` §3): cadencia de frames/`HH_VI_EVERY`,
    front-end, reloj, fallthroughs de la cadena, watchpoint de acceso y `HH_DRWATCH` (solo arranque).
  Detalle: `notes/2026-09-20-nodo-8005bf14-origen-y-captura.md`,
  `notes/2026-09-19-causa-raiz-cadencia-frames.md`,
  `notes/2026-09-19-verificacion-cadencia-y-harness-replay.md`,
  `notes/2026-09-19-inventario-y-nueva-evidencia-fase-previa.md`,
  `notes/2026-09-19-clasificacion-adelanto-fase-previa.md`,
  `notes/2026-09-19-bat-stall-check.md` y
  `notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md` (§2d/§2e/§6).
- [ ] **Textos/traducción** (requisito de producto): encoding + extracción + re-inserción.
- [ ] **Guardado**: validar Controller Pak contra el emulador; ficheros en disco + **Rumble**.
- [ ] **Builds/empaquetado**: validar "build once, promote" en GitHub y empaquetado **Steam Deck**.
- [ ] **Tarea #3**: mapa overlay→RAM por BizHawk (complementa la medición empírica de bases).
- [ ] **Cadencia/hitches de puertas** (mejora): precarga/decode y enganche a VI
  (`notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md`).
- [ ] **Símbolos**: fronteras gruesas (`0xADDR:0xSIZE`) y auto-mid del módulo 12 (datos como código).
- [ ] **Data-as-code** (189 sospechosas): limpiar → permite reevaluar `use_lookup_for_all_function_calls`.
- [ ] **Ramas del toolchain**: publicar `hybrid-heaven-tool` (13 ficheros) para reproducir la
  regeneración (el build no la necesita).
- [ ] **Higiene del repo** (`notes/2026-09-16-limpieza-repo-inventario.md`): archivar scripts one-off
  de `tools/analysis/`, variantes obsoletas de `config/`, decidir el `work/` rastreado. **NO borrar**
  `*.syms.toml.keep`, `keep_syms*.txt`, `module_extras.json`, `config/n64recomp_changes/*`.
- [ ] **Sanear menciones a la ROM en docs/notas** (frases cortas del juego en `notes/`).

## Hecho (resumen; detalle en `notes/`)

- [x] Arranque completo, gameplay, menús, combate y cinemáticas en Windows (RTX 4080) con mando Xbox.
- [x] Guardado en cápsula (Controller Pak) validado (`osPfsFindFile`→5).
- [x] Audio `aspMain` del ROM recompilado a 43200 Hz; perfiles de mando por contexto.
- [x] Fase B (ADR 0007): cache de assets + loader LZKN64 nativo.
- [x] Rendimiento: `get_function` sin `getenv` por llamada → stalls de 1-4 s a 0 y 30 ticks/s
  (`notes/2026-09-18-faseb-cache-trans-implementado.md` §8/§8b).
- [x] Replay fiel (`HH_REPLAY_MODE=vi`); build reproducible + CI/Releases (ADR 0005).

## Documentos de detalle (no duplicar)

`PROYECTO.md` · `docs/README.md` (visión) · `docs/architecture.md` · `docs/adr/` · `docs/workflows.md`
· `notes/2026-09-1*.md`.
