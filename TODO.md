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

- [ ] **FPS en pantalla (overlay, opcional)**: hoy `HH_FPS=1` solo lo escribe en `hh.log`. El overlay
  real requiere dibujar sobre el swapchain de RT64 → su **Inspector ImGui**. **Vía rápida hecha**:
  `HH_DEVELOPER=1` habilita `developerMode` y **F1** abre el Inspector (FPS/frametimes); con dev-mode
  RT64 consume F1-F4 (el F2/F3/F4 del port no actúa). Pendiente decidir si exponer una tecla propia
  sin dev-mode o un overlay propio. Ver `notes/2026-09-22-fps-y-present-early.md`.
  Nota: **RTSS funciona** una vez configurado (subir *detection level*), así que sirve como overlay
  externo; `HH_DEVELOPER=1` + F1 es la vía interna.
- [ ] **Textos/traducción (requisito de producto) — spike de encoding**: sería la **primera
  traducción al español** del juego. Primeros pasos acotados:
  1. **Localizar** las tablas de texto de la ROM (anclas conocidas: `WASHINGTON D.C.` @`0x061CD7A`,
     `PLEASE SELECT` @`0x05FB543`, `BATTLE` @`0x05FAF4C`, `ITEM...WEAPON` @`0x06C33AF`).
  2. **Derivar el charset** (encoding custom USA) y construir un **extractor** ROM→texto.
  3. **Reinsertar** con control de longitud (comprobar si los textos van en buffers de tamaño fijo y
     si hay que preservar terminadores/control codes).
  4. **Medir cobertura** (nº de strings/zonas) y decidir formato de traducción (tabla ES, glifos
     necesarios tipo `ñ/¿/¡` en la fuente).
  Ver `PROYECTO.md §4` y `notes/2026-09-05_asset-map.md`.
- [x] **Widescreen fase 07b — mapa validado en Windows (2026-09-22)**: anclaje del contenido +
  **fondo negro** del minimapa cuadrados (fill con scissor propio, `invRatioScale=1`). Radar y HUD
  `left` ya estaban. Commits `cleanup(hud)`+`fix(map)`+`docs` (ya en `origin/main`). **Detalle**:
  `notes/2026-09-22-fix-mapa-rect-negro-widescreen.md` ·
  `notes/2026-09-22-anclaje-hud-widescreen-fase07b.md`.
- [ ] **Widescreen: anclaje del HUD/mapa a los bordes (fase 07b, cosmético)**: **radar anclado a la
  izquierda** (2026-09-21; `src/hooks/hud_rewrite.cpp` + `HH_HUD_TRACE`; validado en Linux headless
  por centroide: OFF x=287 → ON x=125, y=const). **Mapa y HUD de combate POWER/STAMINA validados
  en Windows (2026-09-22)** (ver arriba).
  **Falta**: la **barra HP** y elementos de la derecha (`right`/`stretch`) — re-derivar sus
  identidades con `HH_HUD_TRACE=1` en las escenas donde aparecen (combate/diálogos) y añadirlas a
  la tabla fija. `HH_FULL_FRAME=0` desactiva el widescreen; `HH_NO_HUD_REWRITE=1` el anclaje.
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

- [x] **High frame rate por defecto (v0.4.0, 2026-09-23)**: `PresentEarly` + `Refresh Rate = Display`
  → presenta al refresco del monitor (~109 fps validado con RTSS), lógica a 30 Hz. Diagnóstico
  `HH_FPS=1`; FPS en pantalla con `HH_DEVELOPER=1`+F1; `HH_GRAPHICS_API`; atajos **F2** aspecto /
  **F3** ventana / **F4** MSAA (**F1** = Inspector). `notes/2026-09-22-fps-y-present-early.md`.
- [x] **Cursor, release `rom/` y README (2026-09-22)**: cursor oculto sobre la ventana (validado en
  Windows); los artefactos de release incluyen `rom/PON_AQUI_LA_ROM.txt`; README con características
  y punto de control de estado. `notes/2026-09-22-cursor-release-rom-readme.md`.
- [x] **Fork de RT64 publicado (2026-09-22)**: `hunkstalker/rt64` (rama `hybrid-heaven` = `a8f0a70`);
  `.gitmodules` y el submódulo `lib/rt64` apuntan al fork. `main` y forks pusheados.
- [x] **Versión `0.3.0` (2026-09-22)**: bump MINOR por las features (widescreen HUD/mapa, cursor,
  release `rom/`). **Release `v0.3.0` publicado.**
- [x] **Ajustes gráficos `[video]` + widescreen (2026-09-21)**: `config.ini [video]` (wm
  borderless/windowed, res auto/nativa/`<n>`/4k/8k, aspect, msaa); ventana a **resolución nativa
  borderless**; atajos **F3** (ventana), **F2** (aspecto), **F4** (MSAA). **Widescreen** con *snap*
  del *scissor* de overscan a full-frame (`src/hooks/dl_snap.cpp`, adaptado de la referencia Phase 07;
  `HH_FULL_FRAME=0` off) → con `aspect=auto`/`expand` (default) el 3D llena la ventana; el HUD/mapa
  **no se desmonta** (queda en la zona 4:3, sin anclar). Validado en Linux y Windows.
  **Pendiente**: anclaje del HUD a los bordes (fase 07b, cosmético).
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
