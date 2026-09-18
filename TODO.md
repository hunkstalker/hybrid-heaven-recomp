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
- [ ] **Mando**: identificar el botón N64 que abre los menús de combate y asignarlo a **X**
  (`config.ini`); decidir `LB` y el atajo de cámara/1ª persona.
- [ ] **Limpieza de instrumentación**: decidir sobre `requeue_pi=true`, los `[MQDROP]`, la sombra
  `hh_sh_*` y el watchpoint (ya está todo gated tras `HH_DIAG`).
- [ ] **Smoke de arranque** (opcional, requiere ROM): con la ROM en `rom\` junto al `.exe`, comprobar
  que la encuentra y que no hay `Failed to find function`. En Docker: `HH_HEADLESS=1` + `rom/`.

## Backlog (priorizado)

- [ ] **CaC: corrupción de estado (BLOQUEANTE, en espera)**. Al entrar en combate el objeto
  `0x8024A990` acaba con callback `+0x1C=0xFFFF84CD` y se corrompen colas (`[BADMQ]`). Reproducido en
  Linux con replay; **no es rendimiento**. Próximo paso: localizar la **primera divergencia de flujo**
  port↔emulador (el replay de BizHawk ya la ejercita). Detalle:
  `notes/2026-09-17-cac-ownership-resuelto.md`, `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md`,
  `notes/2026-09-17-bizhawk-replay-freeze-con-rafaga.md`.
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
