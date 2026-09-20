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

- [ ] **CaC: el port no entra al combate (BLOQUEANTE)**. Estado 2026-09-20; **detalle y plan
  único**: `RETOMAR.md` y **`notes/2026-09-19-causa-raiz-cadencia-frames.md`** (empezar aquí); antes:
  `notes/2026-09-17-replay-mode-vi-vis-negativo.md` (§3/§5),
  `notes/2026-09-19-verificacion-cadencia-y-harness-replay.md` y
  `notes/2026-09-19-bat-stall-check.md`.
  - **CAUSA LOCALIZADA (2026-09-20): el SCHEDULER DE EVENTOS TEMPORIZADOS del juego.** Reproducido
    headless con `HH_GATE_A=1`: la puerta `M7_FUN_80126A0C(a0=0x8024C934, a1=0x39, a2=1)` se llama
    **16 veces**; **#13 devuelve 1** con `42D0=0x2B88` → instala `b280` → veneno (`vi=20012`,
    `sample=9803`). El **emulador nunca la llama con `a1=0x39`** (instalador `0x8021B240`: 0
    ejecuciones). `42D0` (`[0x8008D580]`) es un **acumulador de tiempo del scheduler** (`FUN_80004bb0`);
    `FUN_80001454` lo resetea cada frame; la puerta lo compara con `0x3001`.
  - **El freeze final**: el objeto `0x8024AAF8` recibe `cb=0xFFFF84CD` (que el emulador **nunca**
    instala) → bad lookup → no-op → **deadlock de colas**. `HH_VI_EVERY=2` **no** lo arregla (tick a
    2 VI, `d2=27-30`) ⇒ la cadencia de frames es **ortogonal**; los **fallthroughs** de la cadena
    M7/M10 están bien.
  - **Plan restante** (`RETOMAR.md`): (1) localizar la **entrada del evento `M10_FUN_8021b240`/0x39 en
    la lista del scheduler** (`FUN_80004bb0`: tabla `0x800429B8 + id*4`, lista `0x42F4`, tiempos
    `0x42CC`/`0x42BC`) y comparar su **tiempo/disparo** port↔emu (o con el `state.log` original del
    mantenedor); (2) validar en **Windows en vivo**.
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
