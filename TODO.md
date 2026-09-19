# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` y `notes/` (no duplicar). Histórico: `notes/`, `notes/archive/`.

## Ahora (priorizado)

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

- [ ] **CaC: el port no entra al combate (BLOQUEANTE)**. Estado 2026-09-19 (noche-3b); **detalle y plan
  único**: `RETOMAR.md` y **`notes/2026-09-19-causa-raiz-cadencia-frames.md`** (empezar aquí); antes:
  `notes/2026-09-17-replay-mode-vi-vis-negativo.md` (§3/§5),
  `notes/2026-09-19-verificacion-cadencia-y-harness-replay.md` y
  `notes/2026-09-19-bat-stall-check.md`.
  - **CAUSA RAÍZ PROBABLE (noche-3b)**: el port ejecuta el frame `FUN_80001454` a **1,03 VI/frame** y
    el emulador a **2,0**. El bucle `FUN_800011b0` decide con `[0x80037748]` (cola `0x8005C288`); el
    port **nunca lo pone a 1** (no toma la rama no-op) ⇒ frame cada VI. Objeto de transición `0x801D0474`:
    port `vi 218`; con `HH_VI_EVERY=2` → `vi 328`; emu `vi 347`. El "port ~20 s adelantado" era un
    artefacto compuesto (el emulador consume el replay ~2× rápido y es inestable al padding).
  - **AVISO (noche-3)**: el emulador **no** es referencia válida con este replay; hay que usar un
    harness vis-fiel real o el `state.log` original del mantenedor.
  - **CAUSA ACOTADA (2026-09-19 noche-2; sigue en pie dentro del port)**: el adelanto nace en el
    **front-end** (logos/título/menús), antes de que M24 se cargue. `ADVANCE=0`/`EVQCHECK=0`/transición
    prematura/veneno son **síntomas aguas abajo**.
  - ⇒ La transición es **prematura** y en el CaC el port llama al **instalador M10/M12 del disable**
    (`m188=0x8024C934`, callback `802425F4`) → freeze/softlock. El emulador **NUNCA** ejecuta
    `M10_FUN_8021b240` (0 veces) con el mismo replay.
  - **Test de causalidad A→B**: enmascarar el START (`HH_MASK_START=400:700`) lleva el CaC a
    `objCB=801CB71C`/`m188=0` (como el emu), **sin instalador ni crash** ⇒ el cambio de escena prematuro
    (A) **causa** la rama M10/M12 (B).
  - **Descartado como causa** (probado): reloj (`HH_DET_CLOCK`/`quant`/`quant+bias`), deslizamiento del
    limiter (3 % de ticks de 3 VI), fase del replay (`HH_REPLAY_PACE=vi`), cache (`HH_TRANS_CACHE=0`),
    y los parches `HH_NO_DISABLE`/`HH_NO_B280`.
  - **Plan restante** (`RETOMAR.md`): (1) localizar por qué el port no procesa el mensaje de tipo 3 de
    la cola `0x8005C288` (el que pone `[0x80037748]=1`); (2) fix correcto de cuantización de tick
    (2 VI/tick; nota 09-17 §5.2), no `HH_VI_EVERY`; (3) reproducir el CaC con `HH_REPLAY_MODE=vi`;
    (4) validar: objeto `0x801D0474` y #12 en su `vi`, `CHAIN` sin completar antes, CaC sin rama M10/M12
    y entra al combate.
  Detalle: `notes/2026-09-19-causa-raiz-cadencia-frames.md`,
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
