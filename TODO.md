# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas PENDIENTES.** `[ ]` pendiente · `[•]` en curso.
> Las tareas **hechas** viven en `docs/TAREAS-HECHAS.md` (no se borran). Detalle en `PROYECTO.md`,
> `docs/` y `notes/` (no duplicar). Histórico: `notes/`, `notes/archive/`. Handoff: `RETOMAR.md`.

## Ahora (priorizado)

- [•] **Traducción — JUEGO/GAMEPLAY (texto in-game) — SIGUIENTE TAREA**. Alcance: **cadenas del juego**
  vía el motor de texto (loader `trans`). **Hecho (2026-09-23)**: charset USA derivado (ASCII en campos
  de ancho fijo + NUL; el "encoding custom" era LZKN64) y **sustitución en runtime**
  (`src/subsystems/text.cpp`; `HH_LANG=es`); extractor `tools/text/extract_strings.py`; **sistema A1**
  (lista `en/es/ca/fr/de/ja` + mods, **cambio en vivo** F5 con re-aplicación a módulos cargados,
  persistencia `[lang]`).
  **Pendiente**: control de **longitud variable** y validar A1 en Windows; **cablear** la fuente
  in-game **8×12 `color4`** (`tools/text/build_font.py` → `include/hh/game_font_color4.h`, ES/CA/FR/DE)
  en `src/hooks/text_glyphs.cpp` (hoy sirve un set 8×8 propio; `HH_ACCENTS=0` la desactiva);
  **extraer DE/FR** (ROM EU) emparejando por módulo → `assets/lang/*.txt` (el **JA** va con la tarea
  pospuesta de traducción JA), y redactar **ES/CA**; **medir cobertura** (nº de strings/zonas) y decidir
  formato (La PAL FR/DE = referencia).
  Detalle: `notes/2026-09-23-spike-traduccion-charset-y-sustitucion.md`,
  `notes/2026-09-23-a1-sistema-idiomas-y-cambio-en-vivo.md`,
  `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`, `notes/2026-09-23-b-fuente-formato-y-gaiji.md`,
  `notes/2026-09-25-e-fix-reapply-idioma.md`. Ver `PROYECTO.md §4`, `notes/2026-09-05_asset-map.md`.

- [ ] **Subtítulos — pendientes futuros (intro HECHA, 2026-10-06; `docs/TAREAS-HECHAS.md`)**: el
  **final** (misma arquitectura; **diferido**: el mantenedor no puede validar sin llegar al final del
  juego) y los **diálogos del gameplay** (trabajo mayor; validarán visualmente `œ/Œ/Ÿ`). Arquitectura y
  herramientas: `notes/2026-10-06-subtitulos-intro.md`.

- [•] **[ÉPICA] Desbloquear FPS / interpolación fiel (abierta 2026-10-02; **MERGEADA en `main`
  2026-10-04**)**: presentar a alta tasa **sin artefactos**. **Resueltos**: **#6** (aura del jefe, gate
  de escala), **#8** (puertas, tagging). **#10/#12** (curar enemigos / Life Charger S) sin síntoma
  reciente → **cubiertos**. **En `main` ya activo por defecto** (tagging; apagable `HH_MTXGROUP=0`/
  `HH_EMIT_TAG=0`). **SIGUIENTE: A1 (tick lógico) + A3 (validar 120/240)**. Queda: LOD, B/C e higiene.
  Plan/handoff: `RETOMAR.md` §"Rama fps-interpolacion-tagging". Work order:
  **`notes/2026-10-02-workorder-desbloquear-fps-interpolacion.md`**.
  - [x] **A0**: métrica objetiva `HH_PAIRING` (contador en `lib/rt64` + dump); la **vista no valida**.
  - [x] **A0b oráculo de emparejamiento (2026-10-05)**: `HH_PAIRING_LOG`/`HH_CAM_LOG` (+ lectores
    `tools/analysis/pairing_log.py`/`camera_log.py`); cobertura medida (área 1 **99.99% por id**).
    Doc reusable `docs/interpolacion-pairing.md`. Determinó que el **parón restante es A1 (tick)**, no
    el emparejamiento. Detalle: `notes/2026-10-05-fase-b-cobertura-sesiones.md`.
  - [x] **A2.1**: tagging por hook del port (`func_800069A8`); llega a RT64 y baja picos. Resueltos
    de paso **widescreen** y **recuadro negro**; **#8** estable.
  - [x] **A2.2 identidad rehecha y VALIDADA (2026-10-03 s2)**: `stable_slot()` generacional (no
    direcciones) + grupo por **NODO** (`id=FNV(slot_objeto, slot_nodo, gen)`) + generación de cámara.
    Arreglados huesos del PJ, **#6**, **#8**, minas/láseres. Detalle: nota
    `notes/2026-10-03-fps-tagging-identidad-logica-y-generacion-camara.md`.
  - [x] **A2.2a #6 (regresión) — fix por gate de ESCALA (VALIDADO 2026-10-03)**: el rebobinado del
    efecto es un **reset de escala ~100×**; `HH_SCALE_GATE` **ON por defecto (2.0)** (`=0` off) en
    `rt64_rigid_body.cpp`, **commit permanente del fork RT64** (`7c46232`), log a `hh_scale.log`.
    Validado en 2 runs del jefe.
  - [x] **A2.2b pasada 2 (efectos/2D ordenados) — CERRADA (VALIDADO 2026-10-03)**: los wrappers
    `7328/736C/73AC` son **compute-only**; la geometría va en **sub-DLs (`G_DL`)** de los emisores →
    hay que rodear **al emisor** con `gEXMatrixGroup` (no las funciones de cálculo). Envolver todos
    congelaba el render; acotado a **`C768`** (tipo 6) es estable y sin artefactos. Muerte de
    enemigos comparada con emulador: coincide. Los **emisores que taggean** (`C768` + `emitter_wrap`)
    van **ON por defecto** (`HH_EMIT_TAG=0` off); la **traza** de pasada 2 (`HH_FX_PASS2`) sigue OFF.
    Detalle: nota `2026-10-03-...-generacion-camara.md` §Actualización 4.
  - [ ] **Limpieza futura de instrumentación de pasada 2/tagging** (decisión: conservar ahora): los
    `[hh-emit]`/histograma de opcodes, `HH_FX_*`, `HH_PAIRING_DUMP` + los log/trazas asociados se
    dejan a propósito para diagnosticar futuros fallos de interpolación. Retirar cuando la épica FPS
    cierre. Inventario de variables en la nota del 2026-10-03.
  - [x] **A2.2c sesgado de cámara — RESUELTO y validado (2026-10-04, `46b3f0d`)**. *Shearing* en cortes
    (FIGHT): la cámara va horneada en la matriz de **vista/proyección**; fix **port-only**
    (`emitter_wrap()` → `gEXMatrixGroup` de PROYECCIÓN con id de cámara + generación) → snap del
    encuadre. Se **descartó** la vía core (materializar pass 1 a través de la frontera de workload:
    asocia por tiempo → rompe el HUD). Detalle: `notes/2026-10-04-fps-core-frontera-workload-y-pasada2.md`.
  - [x] **A2.2d efectos/2D de pasada 2 — CERRADA (2026-10-04, sesión 5)**: los efectos los dibuja
    **`func_8000C768`** (tipo 6/12) y **materializa** (`id=EE0F…`); `emitter_wrap` (`7DE4/8F30/…`) queda
    **huérfano** por la frontera de workload (`emitmat=[15:…]`). La opción **core (a)** (materializar en
    el `push`) resultó **inerte** (HUD intacto) → revertida. Las capturas de minas/láser/partículas/
    puerta-FIGHT son **transitorios** (id nuevo en 1 frame), **no fallos**; ningún id con racha >3
    frames. Cobertura **98.6%** con id. Detalle:
    `notes/2026-10-04-fps-a2-2d-emisores-y-capturas-transitorias.md`.
  - [x] **A2.3**: **quitado** el skip-spawn propio (RT64 salta solo los IDs sin contraparte).
  - [x] **Partículas de sprites al curarse — CERRADO (no-bug)**: los "quads" son el **asset original**
    del juego (textura cuadrada de glow 8x8 + estrella 16x16); coincide con el emulador (dump del
    emulador y `HH_TEXDUMP`). No es interpolación ni tagging ni RT64. Ver
    `notes/2026-10-04-fps-particulas-heal-asset-no-bug.md`.
  - [ ] **LATENTE: walkers de DL + comandos extendidos** (`src/hooks/dl_snap.cpp`): el salto de `0x64`
    con **longitud fija 16B** desincroniza con `gEXPopMatrixGroup`/`gEXSetRectAspect` (8B) → puede
    perder el scissor de overscan (**4:3 intermitente**) y cortar las trazas 2D. **No observado** en
    HH. Doc + fix: `notes/2026-10-04-fps-walker-dl-comandos-extendidos-latente.md`.
  - [ ] **A2.4 LOD**: incluir el nivel de detalle en el hash si se localiza el campo. **Sin caso
    observado** (sin popping; `unpaired_moved` normal) → localizar el campo o cerrar como "no aplica".
  - [x] **A1 — tick lógico determinista — RESUELTO y VALIDADO (Windows 2026-10-05)**: los slips a 3 VI
    (el limiter del juego cierra en el presupuesto de 2 VI con <1 ms de margen) se eliminan con
    `HH_DET_CLOCK=1` + `HH_DET_CLOCK_BIAS=15625` **por defecto en el port** (`src/platform/main.cpp`,
    vía el entorno del CRT). `hh_tick.log` `d3=0`, `present=120`; sin parones. Nota:
    `notes/2026-10-05-a1-tick-determinista.md`.
  - [•] **A3 — FPS dinámicos (cap del jugador) — tras A1**:
    **Objetivo**: que el jugador **elija el límite de FPS**.
    **Opciones (menú)**:
    - `Límite de FPS`: presets (30/60/120/144/240/…) + `Sin límite` (0).
    - `VSync`: On (techo = panel, sin tearing) / Off (suelta).
    **Reglas**:
    - El cap es del jugador e **INDEPENDIENTE del monitor**; VSync es lo único que limita al panel.
      Efectivo = `VSync On ? panel : cap`. Default: **VSync On + Sin límite** (= refresco del panel).
    - El cap sirve para (1) elegir la tasa y (2) **frametimes estables (pacing)**, también por encima
      del panel (240 estables en 165 con VSync Off, frente a los picos de `Sin límite`). **Sin tocar la
      lógica** (1:1).
    **Trabajo**:
    - Quitar/parametrizar el clamp `targetRate ≤ swapChainRate` (`rt64_workload_queue.cpp:225-226`).
    - Present uncapped (mailbox/immediate) cuando cap > panel.
    - Añadir `Límite de FPS` + `VSync` a config y menú.
    - **MSAA default x2** (el hardware moderno da de sobras).
    **Validación**: a la tasa del panel (120/144 ya estables) y con cap > panel (VSync Off; p. ej. 240 en
    165); medir `present` vs el cap elegido.
  - [ ] **B**: spike 60 Hz real (limitador + reescalado) + ADR. · **C**: desacoplar audio del tick 30 Hz.
  - Aparcado: gates `HH_ROT_GATE`/`HH_SCALE_GATE` y F9 (sonda, no arreglo).

- [ ] **Acentos in-game POR COLOR (color4/color3) — follow-up del fix del ordenador (2026-10-02)**:
  hoy la inyección sólo sirve el bloque **color0 (8×8, stride 32)**; en **color4 (8×12, stride 48)** o
  **color3 (12×13, stride 78)** `func_8001BFE4` cae al original (sin corromper, pero sin acento).
  Cablear el bloque color4 por `cp` desde `include/hh/game_font_color4.h` (y valorar color3). Evidencia:
  `notes/2026-10-02-fix-glifos-acentos-colision-value-color3.md` §4.

- [•] **Transición del título del Área: fundido y hold (2026-10-02, validar 2.ª vez)**: fade por tiempo
  (`HH_TITLE_FADE_MS` 2000), fade-out real por hilo de render (`HH_TITLE_FADEOUT_MS` 1000), hold
  `HH_TITLE_TRANS_MS` 400; telón opaco. Detalle: `notes/2026-10-02-transicion-titulo-fade.md`.

- [ ] **`EDICIÓN DE PARTIDA`: "mover mi partida a una Área-Parte" (2026-09-29, DISEÑADO)**: cargar la
  partida del jugador en el editor, elegir Área-Parte, y **GUARDAR** = plantilla de esa Área-Parte +
  sobrescribir **atributos/estado/items/habilidades** del jugador (lo demás, de la plantilla). Requiere
  **plantillas por punto de guardado** (`assets/saves/templates/<n-p>.bin`, generadas jugando). Detalle:
  `notes/2026-09-29-editor-area-parte-plan.md` §6bis.
- [ ] **Editor `PROGRESO` del slot**: ahora escribe **`0x564` (u16 LE)** con
  `(area-1)*10+(sub-1)*2` y lista solo puntos de guardado (sin `N-0`). **Pendiente validar en Windows**
  que `CONTINUAR` carga donde toca.
- [ ] **Combo: no se rellena en el 1.er combate (a afinar en el futuro, 2026-09-28)**: la barra de
  combo se alimenta del PODER (100 % → +1 segmento) y con `PODER ∞` queda llena, pero **arranca a 0 en
  el 1.er combate** y solo se rellena desde el 2.º (parece un gateo de estado al terminar/vaciar el
  PODER en el 1.er combate). **No** localizado el contador (0..4) en las zonas vigiladas. Plan: traza
  que cruce el fin del 1.er combate con el 2.º para hallar el flag y forzarlo. Detalle: `RETOMAR.md`.
- [•] **`EDICIÓN DE PARTIDA` (editor de save) — v3 sobre el `.pak`, rama `menu-edicion-partida`,
  commit `77d2ad6` (2026-09-27)**: menú en `EXTRAS` con `CARGAR PARTIDA < PARTIDA N >`,
  `GUARDAR PARTIDA < NUEVA PARTIDA / PARTIDA N >`, `PROGRESO < N-P >`, `NIVEL`, `HABILIDADES`
  (`< SIN CAMBIOS / TODO SÍ / TODO NO >`), `ESTADO` (CUERPO bajo CABEZA), `ITEMS`. `GUARDAR` escribe
  el `.pak` con offsets/checksum correctos (verificado headless). **ABIERTO (bloqueante)**: `CONTINUAR`
  no refleja lo editado. También: repeat up/down/izq/der y cierre F11 rápido. Detalle:
  `notes/2026-09-27-f-editor-partida-v3-y-hallazgos.md`. Ideas de sistema de guardado:
  `docs/ideas-edicion-partida.md`.
  - **Sesión 2026-09-28** (`notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md`):
    **formato real del slot documentado** (struct de personaje bswap32 / `u16 LE`; técnicas/items/progreso)
    y **función del juego que escribe la cabecera** (`func_80142350`/`func_80141268`). Corregido:
    `CONTINUAR` (recarga `g_pak` tras GUARDAR), `NIVEL` (u16 LE en `0x4A`), contadores `ESTADO`
    (u16 LE, ya no 256), **items** (nombre real del registro `0x8017E004+id*8`; la **cantidad** va en
    el slot de su familia invertido, S↔X/M↔L: `item_slot_of`), **cabecera de la lista de partidas**
    (`update_save_header`: AREA/LEVEL/checksum del registro del slot → DATA LOAD refleja los cambios y
    `NUEVA PARTIDA` crea entrada) y **pantalla `ATRIBUTOS`** (edición manual de
    HP/HP MAX/STAMINA/OFENSIVO/DEFENSIVO/VELOCIDAD/REFLEJO). **Lógica de juego documentada**
    (maestría, aprendizaje, partes) en `notes/2026-09-28-logica-juego-tecnicas-items-y-stats.md`.
    **Escalado parte→stats: RESUELTO (2026-09-28)**. Lo hace **`func_80376D48`** al acabar el combate
    (`func_803840A4`): 6 atributos con nivel+progreso+tablas independientes; HP sube con su parte
    (`+0x04`) por `incremento_HP` 5,10,10,15…, DEFENSE con `+0x53` por 24,6,6…, OFFENSE `+0x52` por
    36,8,8…, etc. El nivel global (`+0x48`) es la media de las 6 partes (`func_8037865C`) y **no**
    entra en las fórmulas. **Modelo del progreso (traza `[STATEXP]`+`HH_CANARY`)**: `progreso_i +=
     round(reward_i × ref_i / stat_i)`, divisor la **propia stat** → **rendimientos decrecientes** (con
     OFFENSE=410 a mano, OFFENSE deja de subir). **CORRECCIÓN (2ª sesión 2026-09-28)**: la reward **NO
     es fija** — es la **fila del ENEMIGO derrotado** (`func_8022CAFC` la elige en `0x8023C940` por
     `a0+0x36`; `func_80376D48` 1 vez/combate); confirmado con `[STATEXP]`/`[ROW]` en 5 combates. Y el
     **tope de nivel** por atributo depende de la dificultad (`func_80376D10`: 79/89/99). Detalle:
     `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`. Corregida además la pista previa
    (`0x800D425C`/`0x800D4260` era error de complemento a dos → `0x800CBDA4`/`0x800CBDA0`).
    Detalle y tablas: `notes/2026-09-28-stats-recompute-correccion.md` §6 y referencia
    `docs/stats-partes.md`. **Hecho en el editor (2026-09-28)**: (1) confirmado y corregido el
    **word-swap 32-bit** del save (`swap16=r^2`, `swap8=r^3`): OFF/DEF y VEL/REF ya no salen
    invertidos; (2) NIVEL global **solo lectura** (derivado); (3) **nivel y progreso por parte
    editables** (`add_part_levels` aplica `incremento[nivel]`). **Lead** "dificultad dinámica":
    `func_8022CAFC` cruza OFFENSE_ente←DEFENSE jugador (§8); confirmar identidad con oráculo.
    **Pendiente**: **validar en Windows** (build + editar nivel de parte → ver stat/STATUS).
    **Hecho (2026-09-28)**: pantalla **`SIM. COMBATE`** (selector COMBATES 1/2/5/10/25/50; A simula)
    que aplica la fórmula EXACTA del juego (`save::simulate_combats`: `EXP_i += round(reward_i×ref_i/
    stat_i)` con `ref_i=min(transformada, tope)` cruzada OFF↔DEF, + bucle de subida). Verificado: vanilla
    2 combates → HP 100→105 y DEFENSE 50→74 (idéntico al juego). Abajo, filas de solo lectura
    `NIVEL n  valor  EXP`. **ATRIBUTOS** sigue editable (raw). **Futuro**: barras de progreso.
    **Corrección (2026-09-28, mantenedor)**: en ESTADO, **OFENSIVO/DEFENSIVO son NIVELES de la parte**
    (suben al atacar / al **GUARDAR**, `+0x10`/`+0x1C`), y **HIT/DAMAGE COUNT son contadores**
    (`+0x68`/`+0x76`). Alimentan la **potencia de combate** (`func_8022DB40`/`func_8022F0E0`);
    `func_80232A80` incrementa el nivel defensivo de una parte (`entidad+0x8E+part*2`). **Pendiente**:
    fórmula exacta del incremento de nivel de parte y si afecta al nº de golpes/combo; y el
    **nivel de maestría** de técnicas (¿desbloquea niveles superiores?).
- [ ] **Smoke de arranque** (opcional, requiere ROM): ROM en `rom\` junto al `.exe` (o `HH_HEADLESS=1` +
  `rom/` en Docker): la encuentra y sin `Failed to find function`.
- [ ] **Definir ADR 0009** (cobertura nativa / clean-room) cuando se adopte la visión de
  `docs/README.md`: manifiesto de reimplementadas + métrica de cobertura.

## Backlog (priorizado)

- [ ] **Traducción JA (juego + intro + final) — POSPUESTA (2026-09-27)**: requiere **procesar la ROM
  japonesa** (extracción/mapping de cadenas y glifos), tarea mayor. El **menú de título JA ya está
  traducido** (kana; `include/hh/jp_kana.h` + entradas JA de `assets/lang/ja.txt`), pero hoy está
  **deshabilitado**; al habilitarlo, cotejar los rótulos con los originales de la ROM JP (EUC-JP).
  La infraestructura kana ya existe. Ideas de extracción en
  `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`; `docs/menu.md`.
- [ ] **Fallos visuales detectados por el mantenedor (2026-09-26; capturas en
  `work/gameplay screenshots/CONTINUAR/`)**: `work/` está gitignored; si hace falta conservar las
  capturas, copiar las relevantes al repo.
  1. **`DATA LOAD` (slots de partida)** — al mover el cuadro de selección entre slots, su **borde
     verde** aparece pegado al **borde superior de la pantalla** (línea verde a `y≈0`), descolgado del
     cuadro. Captura `Captura de pantalla 2026-09-26 033740.png`. Es un menú **nativo** (no overlay).
     Probable artefacto de widescreen (`snap_overscan`)/rect 2D; investigar con **F7** (captura pareada)
     y `HH_FULL_FRAME=0` para acotar.
  2. **Combate (golpes)**: los ataques salen como **cajas verdes/rojas con recuadro negro (solo el
     borde)**; en el original **no** llevan ese borde. El mantenedor irá añadiendo capturas a esa carpeta.
- [ ] **2.º mando / 2.º Controller Pak — `MODO VS` no validable (2026-09-27)**: `MODO COMBATE →
  MODO VS` no se pudo validar; el port **solo reporta el puerto 0** de mando
  (`src/subsystems/input.cpp`: `return controller_num == 0` por el arranque del juego), así que no se
  detecta un **2.º mando** (¿o un 2.º **Controller Pak**?). Tarea: reportar un 2.º puerto conectado
  (y el Controller Pak que corresponda) **sin** romper la detección de arranque (que dependía de
  reportar `CONT_NO_RESPONSE_ERROR` en los puertos ausentes). Relacionado: item 11 (Rumble vs
  Controller Pak) y el SEGV del menú multijugador (abajo).
- [ ] **Menú multijugador: SEGV al entrar** (aparcado 2026-09-16): crash host ≈ `FUN_80026f58`;
  rama multijugador **fuera de alcance** (`notes/2026-09-16-fix-menu-b-fisico-atras.md` §Aparcado).
  **No reproducido** en la build Linux actual (2026-09-27, ninguna rama del submenú de batalla);
  confirmar en Windows si reaparece al conectar un 2.º mando.
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

## Documentos de detalle (no duplicar)

`PROYECTO.md` · `docs/TAREAS-HECHAS.md` (tareas completadas) · `docs/README.md` (visión) ·
`docs/architecture.md` · `docs/adr/` · `docs/workflows.md` · `docs/menu.md` · `notes/`.
