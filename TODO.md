# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` y `notes/` (no duplicar). Histórico: `notes/`, `notes/archive/`.

## Ahora (priorizado)

- [ ] **Menú IN-GAME de opciones PC (ADR 0008)**: reutilizar el menú del `expansionram` (idx 23).
  **Antes: spike go/no-go** (nota 09-18 §6).
- [ ] **Smoke de arranque** (opcional, requiere ROM): ROM en `rom\` junto al `.exe` (o `HH_HEADLESS=1` +
  `rom/` en Docker): la encuentra y sin `Failed to find function`.
- [ ] **Definir ADR 0009** (cobertura nativa / clean-room) cuando se adopte la visión de
  `docs/README.md`: manifiesto de reimplementadas + métrica de cobertura.

## Backlog (priorizado)

- [ ] **Textos/traducción** (requisito de producto): encoding + extracción + re-inserción.
- [ ] **Menú multijugador: SEGV al entrar** (aparcado 2026-09-16): crash host ≈ `FUN_80026f58`;
  rama multijugador **fuera de alcance** (`notes/2026-09-16-fix-menu-b-fisico-atras.md` §Aparcado).
- [ ] **Docker smoke headless** (`HH_HEADLESS=1` + `rom/`): validar `docker compose` de punta a punta
  (`notes/2026-09-16-limpieza-rutas-referencias-y-pipeline-build.md` §104).
- [ ] **Audio (futuro): desacoplar de los fps** — hoy el audio va atado al tick de 30 Hz, así que un
  hitch puede afectarlo. `PROYECTO.md §7`, `notes/2026-09-15-fix-modulo9-cuelgue-npc-y-handoff.md:68`.
- [ ] **Audio: `osAiGetStatus` real** (hoy devuelve 0 fijo, `librecomp/src/ai.cpp`); completar con el
  estado del DMA **solo si se observa algún síntoma** (`notes/2026-09-17-replay-mode-vi-vis-negativo.md` §5b).
- [ ] **Guardado**: validar Controller Pak contra el emulador; ficheros en disco + **Rumble**.
- [ ] **Builds/empaquetado**: **Steam Deck**; validar `release.yml` end-to-end.
- [ ] **Tarea #3**: mapa overlay→RAM por BizHawk (complementa la medición empírica de bases).
- [ ] **Cadencia/hitches de puertas** (mejora): precarga/decode y enganche a VI
  (`notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md`).
- [ ] **Símbolos**: fronteras gruesas (`0xADDR:0xSIZE`) y auto-mid del módulo 12 (datos como código).
- [ ] **Data-as-code**: limpiar sospechosas → permite reevaluar `use_lookup_for_all_function_calls`.
- [ ] **Ramas del toolchain**: publicar `hybrid-heaven-tool` (13 ficheros) para reproducir la
  regeneración (el build no la necesita).
- [ ] **Higiene**: archivar scripts one-off de `tools/analysis/`. **NO borrar** los `*.keep`,
  `keep_syms*.txt`, `module_extras.json`, `recomp/n64recomp_changes/*`.
- [ ] **Sanear menciones a la ROM en docs/notas** (frases cortas del juego en `notes/`).

## Hecho (resumen; detalle en `notes/`)

- [x] **Estéreo L/R corregido (2026-09-21)**: los samples llegaban con L/R invertidos (librecomp
  byte-swapped + puntero crudo); `queue_samples` ahora los des-swapea (`HH_AUDIO_NO_SWAP=1` off).
  Pendiente validar de oído en Windows. `notes/2026-09-21-audio-petardeo-ref-y-plan.md` §8.
- [x] **Limpieza de instrumentación (2026-09-21)**: `[BADMQ]`/`[MQDROP]` gateados tras `HH_DIAG`
  (consola limpia por defecto; fork NMR); `HH_NO_STREAMED_LOADS` eliminado (el hook streamed se
  registra siempre). Se **quedan** (funcionales/opt-in): `requeue_pi=true` (evita cuelgue de PI DMA),
  la sombra `hh_sh_*` (el scheduler lee/escribe ahí los enlaces de hilo) y el watchpoint
  (`HH_WATCH_ADDR`, opt-in).
- [x] **Mando/teclado (2026-09-21)**: mapeo **fijo** (sin remapeo por contexto) — B físico = N64 B
  (atrás/mapa), **X = agacharse**, A=A, Y=C-Down, LB/RB=L/R. **D-pad → stick** por defecto
  (`HH_DPAD_TO_STICK=0` off) → el D-pad navega menús; stick→D-pad también. **Teclado**: WASD=stick,
  H/J/K/L = X/A/B/Y, U/I=L/R, O/P=Z/R, Enter=Start. Validado en Windows.
- [x] **Audio sin petardeo (2026-09-21)**: el juego sobreproducía ~5–6% (modelo FIFO) → cola hasta el
  watermark → descartes. Fix (modelo de la referencia): reportar la **cola SDL real − headroom**
  (`HH_AI_HEADROOM_MS`=30); el FIFO sigue con el evento AI. `frames/s≈43.2k`, `drops/s=0`. Validado en
  Windows y Linux. `notes/2026-09-21-audio-petardeo-ref-y-plan.md`.
- [x] **Publicación hecha (2026-09-21)**: CI verde (Linux/Windows) + **Release `v0.1.1`** publicado,
  con el repo público sin datos del juego y el `RecompiledFuncs` traído del repo privado de secretos
  (ADR 0009). Etapa ELF/splat y M4c validados en Windows.
- [x] **Vía de recompilación ELF/splat (ADR 0011), M0–M5** + **entrada al CaC validada en Windows
  (2026-09-21)**: START → menú → GAME START → gameplay, primer NPC, cajas, **primer CaC**, ~30 min
  hasta el **6º combate** sin cuelgues; **mando** y **guardado/carga** correctos.
- [x] **Estructura/higiene (M5)**: port en la raíz (`src/{platform,hooks,subsystems}`), `recomp/tools/`,
  intermedios → `build/recomp/`, vía Ghidra → `legacy/`, `config/`→`recomp/`, `work/` fuera del repo
  (scratch gitignored), purga `HH_*`, docs vivas + créditos.
- [x] **Teardown SEGV (M4c) RESUELTO** (Linux + Windows): el runtime liberaba RDRAM y el planificador
  seguía despachando hilos al salir; fix en el fork NMR (no liberar RDRAM + parar el planificador).
  `notes/2026-09-21-m4c-teardown-segv.md`.
- [x] **CI con el C recompilado (ADR 0009)**: repo privado de secretos + PAT
  (`notes/2026-09-21-ci-recompilado-desde-repo-privado.md`).
- [x] **Submódulos** `lib/{N64ModernRuntime,rt64}` publicados (forks propios; ADR 0010).
- [x] Arranque completo, gameplay, menús, combate y cinemáticas en Windows con mando Xbox.
- [x] Guardado en cápsula (Controller Pak) validado (`osPfsFindFile`→5).
- [x] Audio `aspMain` del ROM recompilado a 43200 Hz; perfiles de mando por contexto.
- [x] Fase B (ADR 0007): cache de assets + loader LZKN64 nativo.
- [x] Rendimiento: `get_function` sin `getenv` por llamada → stalls de 1-4 s a 0 y 30 ticks/s.
- [x] Replay fiel (`HH_REPLAY_MODE=vi`); build reproducible + CI/Releases (ADR 0005).

## Documentos de detalle (no duplicar)

`PROYECTO.md` · `docs/README.md` (visión) · `docs/architecture.md` · `docs/adr/` · `docs/workflows.md`
· `notes/2026-09-1*.md`.
