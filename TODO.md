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
  - **CAUSA RAÍZ DEL FREEZE (vigente, 2026-09-20)**: **stalls/alineación frame↔VI** del hilo de juego:
    con stalls reales (RT64/WASAPI/IO) un frame abarca **3 VI** y desplaza el estado respecto a la
    rejilla VI (`notes/2026-09-19-veneno-capturado-bug-signo-extension.md` §8). **`HH_VI_EVERY=2` NO
    arregla el freeze** (validado en vivo 2026-09-20: CaC congelado en `VI=20829`, veneno `0xFF7F84CD`).
    El adelanto del front-end (frame 1,03 vs 2,0 VI/frame; objeto `vi 218` vs emu `347`) es real pero
    **ortogonal** al freeze.
  - **Plan restante** (`RETOMAR.md`): (1) **alinear frame↔VI con compensación de stalls** (que cada
    frame abarque 2 VI pase lo que pase: limiter que reanude en la rejilla VI, o desacoplar
    render/audio); (2) analizar `logs_tick2_20260920_012011/` (`hh_hang.log`/`hh_slow.log`); (3)
    comparar la puerta del disable port↔emu con `HH_B280TRACE`; (4) validar en **Windows en vivo**.
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
