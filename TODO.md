# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` y `notes/` (no duplicar). Histórico: `notes/`, `notes/archive/`.

## Ahora (priorizado)

- [x] **BUG resuelto (headless, 2026-09-25): cambiar de idioma aceleraba el juego (30→60)**. Causa:
  `hh_trans_reapply_language` reescribía el módulo entero y pisaba cambios del juego (relocs de código,
  buffers de trabajo). Fix: re-aplicar solo los bytes cuyo contenido coincide con el testigo `written`
  (lo escrito en la carga) + poda de solapes y tope de memoria. Knob A/B `HH_LANG_REAPPLY=0`.
  Validado headless (`vi=30` estable); **falta confirmar en Windows**.
  `notes/2026-09-25-e-fix-reapply-idioma.md`.
- [x] **Bugs del menú overlay A2 (2026-09-24) — VALIDADOS en Windows**: bearing de "MODO COMBATE",
  **tercer set** de etiquetas al volver atrás, y cierre del overlay (instantáneo al cambiar de
  pantalla). Ver `notes/2026-09-24-a2-overlay-alineacion-y-cierre.md` y `...-dos-tablas.md`.
- [x] **Menú IN-GAME de opciones PC (ADR 0008) — HECHO (2026-09-25, headless)**: árbol, navegación
  (A/B, control total), acciones (video → `[video]`; audio → `[audio]`), SFX por eventos, **acentos**
  (letra+marca) e **idiomas** (EN/ES/CA/FR/DE + **idioma del sistema**). Detalle:
  `notes/2026-09-25-d-menu-multilingue-acentos-e-idiomas.md`, ADR 0008/0012.
  **Validado en Windows (2026-09-26, tras el merge con `main`)**; falta el **JA del menú** (kana).
- [ ] **Menú nativo — funcionales y pulido (2026-09-26, orden recomendado)**:
  1. **Bug del submenú `IDIOMA`**: entrar, mover el cursor sobre un idioma **sin aplicarlo** y salir
     con **B** (hoy no pasa nada); al **volver a entrar y salir** se aplica el idioma señalado sin
     confirmar. Debe aplicarse **solo con A/confirmar**.
  2. **Renombrar `AJUSTES` → `CONFIGURACIÓN`** con traducción a todos los idiomas.
  3. **`CONTINUAR`**: enlazar con la función real de continuar (poco esfuerzo).
  4. **`EMPEZAR PARTIDA`**: enlazar con la función real de empezar partida.
  5. **`DIFICULTAD`**: controlar la config para que `EMPEZAR PARTIDA` cree la partida en la dificultad
     elegida (esfuerzo por determinar).
  6. **Código Konami → `TRUCOS`**: en la raíz del menú, encima de `SALIR`; detección por mando o
     teclado, con SFX.
  7. **Demos de inactividad**: recuperar la intro/demos que salían a los segundos sin pulsar (se
     perdieron al crear el menú moderno); analizar.
- [ ] **Smoke de arranque** (opcional, requiere ROM): ROM en `rom\` junto al `.exe` (o `HH_HEADLESS=1` +
  `rom/` en Docker): la encuentra y sin `Failed to find function`.
- [ ] **Definir ADR 0009** (cobertura nativa / clean-room) cuando se adopte la visión de
  `docs/README.md`: manifiesto de reimplementadas + métrica de cobertura.

## Backlog (priorizado)

- [x] **FPS en pantalla (2026-09-26)**: `MOSTRAR FPS` en el menú `DEBUG` (menú moderno de
  `menu-nativo`) enciende el **indicador de FPS del overlay** (solo números, arriba-izquierda; mide la
  tasa **real** de presentación) y persiste en `config.ini [video].showfps`. `HH_FPS=1` sigue volcando
  a `hh.log`. Vías alternativas: `HH_DEVELOPER=1` + F1 (Inspector de RT64) y RTSS (overlay externo,
  subir *detection level*). Ver `notes/2026-09-22-fps-y-present-early.md`.
  `src/hooks/sections.cpp` (acción), `src/platform/support.cpp` + `rt64_render_context.cpp`.
- [x] **Menú A2 — overlay moderno (render hook RT64) + opciones PC (2026-09-23/25)** — HISTÓRICO.
  Menú propio del port, **solo en el menú inicial** (no el de pausa). Arquitectura `hh_menu → hh_font →
  backend_game` (atlas de la **fuente del juego**, hoy) / `backend_modern` (TTF, futuro,
  **seleccionable desde el propio menú**). El intento por GBI (`hud_rewrite`/`send_dl`) **falló** (RT64
  compone el framebuffer del juego; los draws GBI no llegan al swapchain) y se retiró; la vía es
  **`RT64::SetRenderHooks(init, draw, deinit)` + plume**. Hitos: shaders+CMake, render hook+atlas RGBA8,
  `hh_menu` del título (hook `0x801C1DB8`, modelo+dibujo 1:1+navegación, **menú nativo oculto**, F6),
  navegación/control total (A/B), **GRÁFICOS** (RATIO/RESOLUCIÓN/P. COMPLETA/ANTIALIASING/VSYNC/LÍMITE
  DE FPS), **DEBUG** (VENTANA DEBUG→F1 + MOSTRAR FPS) y **AUDIO** (VOLUMEN/SALIDA/MENÚ SFX) aplican en
  vivo y **persisten en `config.ini`** (`[video]`/`[audio]`); SFX por eventos del modelo. Todo
  **validado en Windows (2026-09-26)**. Detalle: `notes/2026-09-24-a2-*.md`, `notes/2026-09-23-a2-*.md`,
  `docs/menu.md`, ADR 0008/0012. Contexto descartado: `notes/2026-09-23-b-motor-texto-localizado.md`,
  `...-a2-plan-menu-ajustes-idioma.md`.
- [•] **Traducción — MENÚ (overlay del port)**. Alcance: **etiquetas del menú moderno** (no usa el
  motor de texto del juego). **Hecho (2026-09-25/26)**: localización **en/es/ca/fr/de**
  (`hh::menu::localized`, lista en **endónimos**); acentos = **letra base `color0` + marca**
  (`tools/text/menu_marks.py` → `include/hh/menu_marks.h`; `¿ ¡` = `? !` girados); **`IDIOMA` en
  `AJUSTES`** funcional (menú + texto in-game), con **idioma del sistema** (fallback inglés) y
  persistencia `[lang]`; **validado en Windows (2026-09-26)**.
  **Pendiente**: **JA del menú** (embeber la **kana** del `color0` JP — tiene kana, no kanji);
  renombrar `AJUSTES`→`CONFIGURACIÓN` y el **bug del submenú `IDIOMA`** (ver "Ahora (priorizado)").
  Detalle: `notes/2026-09-25-d-menu-multilingue-acentos-e-idiomas.md`, **ADR 0012**, `docs/menu.md`.
- [•] **Traducción — JUEGO/GAMEPLAY (texto in-game)**. Alcance: **cadenas del juego** vía el motor de
  texto (loader `trans`). **Hecho (2026-09-23)**: charset USA derivado (ASCII en campos de ancho fijo +
  NUL; el "encoding custom" era LZKN64) y **sustitución en runtime** (`src/subsystems/text.cpp`;
  `HH_LANG=es`); extractor `tools/text/extract_strings.py`; **sistema A1** (lista `en/es/ca/fr/de/ja` +
  mods, **cambio en vivo** F5 con re-aplicación a módulos cargados, persistencia `[lang]`).
  **Pendiente**: control de **longitud variable** y validar A1 en Windows; **cablear** la fuente
  in-game **8×12 `color4`** (`tools/text/build_font.py` → `include/hh/game_font_color4.h`, ES/CA/FR/DE)
  en `src/hooks/text_glyphs.cpp` (hoy sirve un set 8×8 propio; `HH_ACCENTS=0` la desactiva);
  **extraer DE/FR** (ROM EU) y **JA** (ROM JP) emparejando por módulo → `assets/lang/*.txt`, y redactar
  **ES/CA**; **medir cobertura** (nº de strings/zonas) y decidir formato (La PAL FR/DE = referencia).
  Detalle: `notes/2026-09-23-spike-traduccion-charset-y-sustitucion.md`,
  `notes/2026-09-23-a1-sistema-idiomas-y-cambio-en-vivo.md`,
  `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`, `notes/2026-09-23-b-fuente-formato-y-gaiji.md`,
  `notes/2026-09-25-e-fix-reapply-idioma.md`. Ver `PROYECTO.md §4`, `notes/2026-09-05_asset-map.md`.
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
  **[x] Issue #3 (2026-09-25) — CERRADO y validado en Windows**: desde el **2º combate** el HUD de
  combate se quedaba en 4:3 (la dirección RDRAM del gráfico cambia por encuentro; no es identidad).
  Arreglos: POWER/STAMINA por **hash de contenido** (`d820d8e`); **disco plateado del radial** por
  **hash + caja `27,19,59,51`**; **barra de combo** = 4 `G_FILLRECT` en la fila `y=28..30`; y
  **stamina gastada** (v0.4.3) = `G_FILLRECT` en `y=34..38`. Los rellenos del HUD de combate
  (POWER/combo/stamina) se clasifican por **posición** (el color no sirve: rojo→azul→naranja apagado;
  y RT64 pinta el relleno con el PRIM color, así que la traza lee `fill_color=0`). Herramienta:
  **F7 = captura pareada** (traza `hh_cap_<n>.log` + imagen `hh_cap_<n>.bmp` del mismo instante).
  Detalle, intentos descartados y errores a no repetir: `notes/2026-09-25-f-hud-combate-contenido.md`.
- [ ] **Artefacto de interpolación de frames (puerta + jefe del nivel 1) — APLAZADO (largo plazo)**:
  con `Refresh Rate = Display` (interpolación ON, v0.4.0) cierta **puerta** parpadea y el **primer
  jefe del nivel 1** muestra geometría incoherente; con `Original` no ocurre (PresentEarly no
  influye). **Depende de desacoplar la lógica del juego del render** (lógica a 60 Hz) → épica aparte.
  Ver `RETOMAR.md` y `notes/2026-09-22-fps-y-present-early.md`.
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
- [ ] **Steam Deck: detección + perfil gráfico por defecto (idea futura, 2026-09-25)**. Al arrancar,
  detectar Deck (`SteamDeck=1`, o DMI Valve + `Jupiter`/`Galileo`; override `HH_DECK=0|1`) y, **si no
  hay perfil marcado**, escribir defaults de `[video]` (`fps=NATIVO` o capado, `msaa=off`, `res=auto`,
  `aspect` 16:10) sin pisar los cambios del usuario. Casi todo reutilizable: `RefreshRate` de RT64 ya
  se **recorta al refresco del panel** (`swapChainRate`), así que `fps=NATIVO` respeta 40/60 Hz de
  SteamOS; `res`/`msaa`/`aspect` ya aplican en vivo y persisten. El **TDP/límites de rendimiento los
  controla SteamOS** (no el port); el perfil solo elige lo nuestro. Futuro: selector `PERFIL GRÁFICO`
  (DECK / CALIDAD / EQUILIBRADO / RENDIMIENTO / BATERÍA) que aplique combinaciones de golpe.
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

- [x] **Input ratón vs panel de RT64 (2026-09-23)**: con el Inspector abierto (`HH_DEVELOPER=1`+F1) el
  clic se colaba al juego (L→A). `hh::dev_panel_open()` (publicado en `update_screen`) desactiva el
  mapeo ratón→A/B **solo mientras el panel está abierto**. Pendiente validar en Windows.
  `notes/2026-09-23-input-raton-y-panel-rt64.md`.
- [x] **[Issue #7](https://github.com/hunkstalker/hybrid-heaven-recomp/issues/7) — minimapa
  desanclado al inicio del nivel 2-1 (2026-09-26)**: la salud ya se arregló con el issue #3; el
  **minimapa** se anclaba por identidad `dl:<dirección>#<hash>` y el overlay cambia de dirección por
  escena/capítulo → no casaba. Fix: emparejar los `dl` del mapa por **hash de contenido** (estable)
  en `class_of`. `notes/2026-09-26-fix-minimapa-contenido.md`.
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
