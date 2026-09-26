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
  **Falta**: **validar en Windows** y el **JA del menú** (kana del `color0` JP).
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
- [•] **Textos/traducción (requisito de producto) — spike de encoding + idiomas (EN CURSO)**: sería la
  **primera traducción al español** del juego. **Hecho (2026-09-23)**: charset USA derivado (ASCII
  en campos de ancho fijo + NUL; el "encoding custom" era en realidad los flujos LZKN64) y
  **sustitución en runtime** vía el loader `trans` (`src/subsystems/text.cpp`; `HH_LANG=es`).
  Extractor `tools/text/extract_strings.py`. Módulo 23 (título/menú/opciones) = 68 cadenas.
  **Sistema de idiomas A1** (base del selector ADR 0008): lista `en/es/ca/fr/de/ja` + mods,
  **cambio en vivo** (F5, re-aplicación a módulos cargados), persistencia en `config.ini [lang]`.
  **Falta**: validar A1 en Windows; **A2** = selector visual; glifos de acento. Detalles:
  `notes/2026-09-23-spike-traduccion-charset-y-sustitucion.md`,
  `notes/2026-09-23-a1-sistema-idiomas-y-cambio-en-vivo.md`,
  `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`.
  Pasos originales:
  1. [x] **Localizar** las tablas de texto de la ROM (anclas: `WASHINGTON D.C.` @`0x061CD7A`,
     `PLEASE SELECT` @`0x05FB543`, `BATTLE` @`0x05FAF4C`, `ITEM...WEAPON` @`0x06C33AF`).
  2. [x] **Derivar el charset** (USA: ASCII + campos de ancho fijo) y **extractor** ROM→texto.
     Encoding real del motor: **EUC-JP**; acentos = gaiji de 2 bytes (ver nota 2026-09-23 de glifos).
     Importante: los bytes no-ASCII alrededor de las anclas eran **LZKN64**, no glifos.
  3. [•] **Reinsertar**: sustitución en runtime preservando longitud (vía loader `trans`); falta
     control de longitud variable y validación en Windows.
  4. [•] **A2 — OVERLAY MODERNO imitando al juego (2026-09-23; vía = RENDER HOOK de RT64)**. Menú
     propio del port, **solo en el menú inicial** (no el de pausa). Arquitectura `hh_menu → hh_font →
     backend_game` (atlas de la **fuente del juego**, hoy) / `backend_modern` (TTF, futuro,
     **seleccionable desde el propio menú**). **El intento por GBI (`hud_rewrite`/`send_dl`) FALLÓ**
     (RT64 compone el framebuffer del juego; los draws GBI no llegan al swapchain presentado) y **se
     retiró del árbol**. Vía nueva: **`RT64::SetRenderHooks(init, draw, deinit)` + plume** (como
     Goemon/recompui) → dibujo directo en el swapchain.
     **(a) shaders + CMake HECHO**; **(b) render hook + atlas RGBA8 HECHO** (validado headless);
     **(c) `hh_menu` del título HECHO (2026-09-24)**: hook `0x801C1DB8`, modelo + dibujo 1:1 +
     navegación, **menú nativo oculto por defecto** (F6 alterna; cubre los **tres** sets) y bugs del
     overlay resueltos. **Paso 5 HECHO (2026-09-24, validado headless)**: navegación propia completa
     (arriba/abajo/izq-der, **A/B sin X**) y **control total** (input del handler nativo muteado).
     **Dibujo HECHO**: listas con la aplicada en verde y el resto en gris; selectores con el activo en
     verde (`NO/SÍ` o `< valor >` con flechas dibujadas); dígitos y `:` dibujados. NUEVA PARTIDA =
     `EMPEZAR PARTIDA / DIFICULTAD / CÁMARA LIBRE / APUNTADO LIBRE`; GRÁFICOS con `RATIO` (filtra
     `RESOLUCIÓN`), `P. COMPLETA`, `VSYNC` (SÍ) y `LÍMITE DE FPS` (`NATIVO`); **`DEBUG`** es submenú
     en AJUSTES (`VENTANA DEBUG`→F1 + `MOSTRAR FPS`). Falta validar en Windows.
     **GRÁFICOS/DEBUG/VENTANA DEBUG HECHOS (2026-09-25)**: `RATIO`, `RESOLUCIÓN`, `P. COMPLETA`,
     `ANTIALIASING`, `VSYNC`, `LÍMITE DE FPS`, `MOSTRAR FPS` y `VENTANA DEBUG` aplican en vivo y
     **persisten en `config.ini` `[video]`** (`aspect`/`res`/`wm`/`msaa`/`vsync`/`fps`/`showfps`/
     `developer`, escritor `hh::config_ini_set`). `res=ANCHOxALTO` usa max(ancho/320, alto/240) para
     que cada opción cambie de escala; el widescreen (`snap_overscan`) se aplica a aspectos > 4:3
     (arregla la "caja pequeña" de `21:9`). Ventana `windowed`: geometría recordada (`win_*`) → `res`
     concreta → nativa, guarda tamaño/posición al cerrar. `MOSTRAR FPS` mide presents reales.
     Validado headless: modelo, arranque, geometría, re-aplicado en vivo (`mult 4→8`) y capturas de
     ratio. Pendiente Windows.
     **AUDIO HECHO (2026-09-25)**: `SONIDO` = `VOLUMEN` (0-100 %, pasos de 10; afecta a todo) +
     `SALIDA` (`MONO`/`ESTÉREO`/`AURICULARES`) + `MENÚ SFX` (`NO/SÍ`). `MONO` = downmix `(L+R)/2`;
     `AURICULARES` = **crossfeed** (canal opuesto filtrado); `MENÚ SFX=NO` silencia los sonidos del
     menú. Procesado en `hh::queue_samples` (`hh_apply_audio_processing`); persiste en `[audio]`. El
     `%` se dibuja (no está en la fuente). Los `.wav` de `sounds/` son personalizables (mismos
     nombres, 48 kHz/S16/estéreo).
     **VENTANA DEBUG/F1**: en Windows RT64 instala su hook solo al arrancar; si se activa en caliente,
     F1 lo maneja el port (`hh::toggle_inspector`). Ver VSYNC con `HH_FPS=1` (log incluye
     `vsync=0|1` real).
     **SFX HECHO (2026-09-25)**: el SFX del menú suena desde los **eventos del modelo**
     (`Move`/`Accept`/`Back`) en `feed_menu_navigation`; **puente retirado** (quedaba en silencio con
     el input muteado y nunca disparaba `back`). Validado: modelo (eventos incl. `Back`). Pendiente
     Windows.
      **ACENTOS + IDIOMAS DEL MENÚ HECHOS (2026-09-25, headless)**: (a) **corregido el formato** de la
      fuente "idioma": es **8×12** (48 B US / 56 B EU, 130 valores EU), no 8×8/32; `extract_eu_font.py`
      arreglado; el menú usa **`color0` 8×8** (engine `fileidx=108` = Nisitenma 107; `stride=32`). (b)
      Acentos del menú = **letra base color0 + marca** (dibujada por el mantenedor;
      `tools/text/menu_marks.py` → `include/hh/menu_marks.h`; atlas 128×44). `¿ ¡` = `? !` girados.
      (c) **`IDIOMA` en `AJUSTES` y funcional** (menú + texto in-game; persiste en `[lang]`);
      etiquetas localizadas **en/es/ca/fr/de** (`hh::menu::localized`, endónimos en la lista);
      **idioma del sistema** si no hay `[lang]` (fallback inglés). (d) Fuente in-game **8×12 `color4`**
      preparada (`tools/text/build_font.py` → `include/hh/game_font_color4.h`, ES/CA/FR/DE) **sin
      cablear**. **Pendiente**: validar en Windows; **JA del menú** (kana del `color0` JP — tiene kana,
      no kanji); cablear la fuente in-game; extraer **DE/FR** (ROM EU) y **JA** (ROM JP) y redactar
      **ES/CA**. Detalle: `notes/2026-09-25-d-menu-multilingue-acentos-e-idiomas.md`, **ADR 0012**.
     **Pendiente (acordado)**: `CÁMARA LIBRE`/`APUNTADO LIBRE` (requieren modificar el juego; por
     ahora NO), `DIFICULTAD`+`EMPEZAR PARTIDA` (arrancar partida nueva con la dificultad interna del
     juego), `CONTINUAR`. Extras de audio (widening/EQ) evaluables más adelante. **Steam Deck**
     (detección + perfil) apuntado abajo. Detalle:
     `notes/2026-09-24-a2-selectores-y-arbol.md`,
     `notes/2026-09-24-a2-ocultar-menu-nativo-dos-tablas.md`, `notes/2026-09-24-a2-overlay-alineacion-y-cierre.md`,
     `notes/2026-09-23-a2-render-hook-y-atlas.md`, `notes/2026-09-23-a2-overlay-primer-paso.md`.
     Contexto (descartado): `notes/2026-09-23-b-motor-texto-localizado.md`, `...-a2-plan-menu-ajustes-idioma.md`.
  5. [x] **B — fuente del juego descodificada + inyección de acentos (2026-09-23)**: **no es una
     textura**, son **6 ficheros de bitmap por glifo** (Nisitenma US 106-111 / EU 115-120), uno por
     color/estilo; **formato 2bpp con DOS glifos empaquetados por bloque** (valor par→bits 2-3,
     impar→bits 0-1). El menú usa **color0 → fichero 107 (8×8)**. **5 de 6 ficheros byte-idénticos
     US↔EU**; la PAL solo añade 32 glifos acentuados al color4. Herramientas
     `tools/text/font_dump.py`, `tools/text/gen_accent_glyphs.py`; traza `HH_FONT_TRACE=1`;
     inyección en `src/hooks/text_glyphs.cpp` (`HH_ACCENTS=0` la desactiva) + `text.cpp` (UTF-8→EUC
     propio). **NO validable hoy** (la cadena con tilde vivía en el menú vanilla, ya oculto): **aparcado**.
     Detalle: `notes/2026-09-23-b-fuente-formato-y-gaiji.md` (sustituye la hipótesis de "transplantar PAL").
  6. [ ] **Medir cobertura** (nº de strings/zonas) y decidir formato de traducción (tabla ES, glifos
     necesarios tipo `ñ/¿/¡` en la fuente). La PAL (FR/DE) sirve de **referencia de estilo**.
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
