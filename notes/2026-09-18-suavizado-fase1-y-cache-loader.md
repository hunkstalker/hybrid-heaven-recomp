# 2026-09-18 — Suavizado (Fase 1): instrumentación de ticks, fixes de AI/audio y plan de cache de assets

> Continúa `notes/2026-09-17-replay-mode-vi-vis-negativo.md` (que recoge, en sus §5b-5i, el detalle
> de esta misma sesión) y `notes/2026-09-17-replay-mode-vi-vis-negativo.md`/`cac-*`. Objetivo de
> la sesión: (a) cerrar la fidelidad del replay; (b) atacar el **fondo**: que el port cumpla el
> presupuesto del original (30,0 ticks/s = 2 VI/tick) sin tirones propios del port; (c) preparar el
> "ROM solo la primera vez" (cache de assets).

## 1. Replay: semántica correcta = `HH_REPLAY_MODE=vi` (pacing cerrado)

- Con `mode=poll` (1 muestra por tick) **cualquier slip del port acumula** desfase: medido en
  Windows `d2=0-4 d3=18-20` (~20 ticks/s) y 15 s de retraso acumulado a t=175 -> ruta distinta y
  **no determinista entre pasadas** (dos replays del mismo input dieron rutas distintas).
- El pacing *por pared* (sub-VI) desplazaba el tick fuera de la ventana de 2 VI (anclaje, no
  trabajo); el pacing *por VI* + PLL (offset con signo) convergía (late 500 ms -> 7 ms headless)
  pero seguía work-bound en Windows. **Innecesario**: `mode=vi` ya resuelve el problema.
- **`mode=vi`** (la muestra se elige por el contador VI: `vis_i <= VI_actual`): el input es función
  del reloj del juego y **se auto-corrige** (los slips saltan/duplican muestras como en la sesión
  original). Headless: `d2=28-29 d3=1-2` = **30 ticks/s** y ruta canónica (43 cargas).
- `port/run_cac_replay.bat` queda con `HH_REPLAY_MODE=vi` y `HH_REPLAY_PACE=` (vacío). No requiere
  rebuild (el binario ya soporta el modo; las grabaciones nativas no tienen vis negativos).

## 2. Fixes de hardware/runtime (afectan al juego, no al replay)

- **AI (Audio Interface) fiel** (`ultramodern/src/audio.cpp`, por defecto ON; `HH_AI_FIFO=0`
  revierte): FIFO de 2 buffers (actual + pendiente), `osAiGetLength` = restante del DMA **actual**,
  evento AI al **completar** el buffer (nuevo `hh_ai_fifo_poll()` desde el hilo VI). El audio
  enviado va **todo** al dispositivo (no solo al arrancar el DMA) y la cola SDL queda acotada a
  `HH_AI_MAX_MS` (150 ms por defecto). Resultado: `frames/s=43,2k` (= consumo), cola estable
  <=150 ms; el retraso creciente y el grueso del petardeo desaparecen. **Pendiente**: sincronizar
  la tasa (feedback del error de cola) para eliminar los descartes periódicos del watermark.
- **ROM read en bloque** (`librecomp/src/pi.cpp`): `do_rom_read` copiaba **byte a byte** con la
  macro de swap (`MEM_B`, XOR por byte) -> copia en bloque con **bswap32 por palabra** + `memcpy`.
  Los módulos del loader son de cientos de KB; el bucle dominaba parte de los hitches de carga.
- **`timeBeginPeriod(1)` en Windows** (`src/main/main.cpp` + `winmm` en CMake): sin esto
  `sleep_for` de 5-10 ms duerme ~15,6 ms (el pacing de pared del replay perdía ~10%).
- **Watchdog RAM mínimo** (`main.cpp`): vuelca RDRAM sin tomar locks (el watchdog principal podía
  bloquearse) y el volcado RDRAM se hace **antes** de recorrer contextos.

## 3. Instrumentación de cadencia (Fase 1 del plan de suavizado) — siempre activa y ligera

- **`hh_tick.log`** (1 línea/s): cuantización por tick `d1/d2/d3/d4+` (VI por tick) y `max_dt`.
- **`hh_slow.log`** (solo ticks >36 ms): `dt dvi send_dl update_screen guest_busy pending_ext`.
- **`guest_busy`**: contabilidad del tiempo guest ejecutando (`threads.cpp`/`mesgqueue.cpp`;
  modelo single-CPU: un hilo a la vez; marcas fin/inicio de slice en los puntos de bloqueo).
- **Timers gfx** (`events.cpp`): `send_dl` (procesado de display list en el hilo gfx) y
  `update_screen` (present), expuestos por `hh_gfx_last_send_dl_ms()`/`hh_gfx_last_update_ms()`.

### Lo medido (clave)

- **Live limpio (Windows, sin `HH_DIAG`)**: **30 ticks/s con `d2=29 d3=1`** (~5% slips) y sin d4+
  en gameplay. El 27/s con 30% de d3 de una pasada previa era **artefacto de los logs pesados de
  `HH_DIAG`** (hh_sched ~4,8 MB/60 s). => la cadencia live es casi la del original.
- **Ticks lentos (headless/llvmpipe)**: `guest_busy≈38-40 ms` (el código guest se come casi todo
  el tick) + `send_dl=5-8 ms`; el **audio es 0,1 ms** (descartado). El primer tick del boot:
  `send_dl≈843-887 ms` (**warm-up de pipelines de RT64**, coste de arranque una vez).
- **Cargas**: stalls de 147 ms (headless) con `guest_busy=145 ms` -> el loader/descompresión es
  el coste; en Windows se vieron stalls de **2-4 s** en boot/cargas (hitch de puerta amplificado).

## 4. Fase B: cache de assets ("la ROM solo la primera vez")

- El coste de carga es el **LZKN64 del loader `FUN_80003824`** (leído por el juego, byte a byte con
  las macros de memoria) + el warm-up de RT64.
- **Formato validado**: `tools/lzkn64/lzkn64.py` descomprime el asset Nisitenma del ROM
  (`off=0x4E69A8`, `size=0x55DD4`) -> **564.464 B** de código MIPS (`27bdffe8afbf0014`). El
  proyecto ya tiene el formato descifrado (`tools/lzkn64/`, `test_lzkn64.py`, `detect_lzkn64.py`).
- **Diseño** (ver ADR 0007): reimplementar `FUN_80003824` (vía `reimplemented_funcs` del toolchain,
  ADR 0002) en C++ nativo + **cache en disco** (`cache/trans.bin` + índice `(rom_src,size)`):
  - **hit** -> `memcpy` al destino (sin ROM, sin descomprimir);
  - **miss** -> descompresión nativa desde la ROM + alta en el cache (auto-construible);
  - validación byte a byte contra `lzkn64.py` para todas las claves del loader y modo de
    comparación con el original en las primeras pasadas (checksum + fallback).
  - Tamaño total del cache: **~14 MB** (asset-map `notes/2026-09-05_asset-map.md`).
- Alternativa conservadora: **return-hook** del loader que capture el output para construir el
  cache; pero el *fast path* (saltar el cuerpo) exige la reimplementación (los hooks no saltan el
  cuerpo de la función).

### Pregunta de diseño abierta: menú/launcher

- El **overlay común** que piden los recomps (elegir ROM + opciones de gráficos) es parte del
  **ecosistema N64Recomp** (launcher/ImGui del runtime en los proyectos upstream: Zelda64Recomp y
  similares); en **este** repo no hay launcher ni ImGui (el port exige `baserom.us.z64` junto al
  exe y lee `config.ini`). Perfect Dark es un **decomp** (no recomp) con **menú in-game** integrado
  (sensación más nativa).
- Opciones a decidir (TODO): (1) launcher estilo ecosistema (ROM + ajustes gráficos) — coherente
  con otros ports y encaja con "ROM solo la primera vez"; (2) menú in-game integrado (Perfect
  Dark-style) — más nativo, más trabajo (engancha input/render del juego); (3) híbrido.

## 6. Decisión del mantenedor: MENÚ IN-GAME (port nativo) reutilizando el menú del Expansion Pak

- **Objetivo**: que se sienta un **port nativo de PC** (si el juego se hubiera hecho para PC,
  tendría opciones en su propio menú); se acepta una experiencia distinta al original N64.
- **¿Es realista en un recomp?** Sí. Perfect Dark lo integra por ser **decomp** (editan el C del
  juego), pero un recomp tiene mecanismos equivalentes que este proyecto ya usa a fondo:
  - **Funciones reimplementadas** (ADR 0002) y **hooks** de config (`[[patches.hook]]`,
    `before_vram`/`func`): interceptar el handler de la opción y aplicar nuestros ajustes.
  - **Textos**: son datos del ROM (encoding custom) y el proyecto ya trabaja en extraerlos/traducirlos
    (zona `0x0530000-0x06D0000`, anclas en `notes/archive/2026-09-11-proyecto-legacy.md` §4.5).
  - **Ajustes**: el runtime ya expone `GraphicsConfig` (WindowMode, `msaa_option`, `resolution`,
    filtrado, `developer_mode`) + las mejoras de RT64, con `update_config`/`trigger_config_action`
    y persistencia (`config.ini`); aplicarlos es escribir esa config.
- **Elección**: **reutilizar el menú del Expansion Pak** (módulo `expansionram`, `/game/source/
  expansionram.c`; 3 resoluciones Low/High Normal/High Letterbox) — mismo UI/fuentes/navegación del
  juego, sustituyendo las opciones y sus acciones. La ROM siempre trae 8 MB (el port ya arranca con
  8 MB), así que ese menú "sobra" y es el sitio natural.
- **Opciones propuestas** (a concretar): resolución/escala, antialiasing (off/2x/4x/8x), filtrado de
  texturas, vsync, límite de presentación (60/pantalla; la lógica es 30 Hz por diseño), modo de
  pantalla (ventana/borderless/fullscreen) y, más adelante, **idioma** (traducción) y mando.
- **Módulo localizado** (barrido del manifest con `lzkn64`): `expansionram.c` está en el manifest
  **idx 23** (`notes/us_manifest.yaml`), ROM **`0x5F1190`** (44.342 B comp -> 68.432 B), que se carga
  en **`0x801BF1A0`** = el módulo que el port ya traza y analizó a fondo en el CaC (funciones
  `0x801BF***`/`0x801C0***`: `M24_FUN_801bfaa0` driver de la línea temporal, `M24_FUN_801bffac`
  avance, `M24_FUN_801bf850` intérprete de comandos...). Eso reduce mucho la incertidumbre del spike.
- **Fases**: A) localizar el `expansionram` (módulo + opciones + handler) y el formato de su lista;
  B) reimplementar el handler (aplicar a `GraphicsConfig` + persistir); C) textos/rótulos; D) UI de
  acción (aplicación en vivo sin reiniciar si RT64 lo permite). Encaja después del cache de assets.
- **Calibración honesta (importante)**: la viabilidad es una **evaluación de mecanismos**, NO del
  código del menú: SÍ están probados en este repo las funciones reimplementadas (ADR 0002), los
  patches de instrucción (`config/game_combined.toml` `[[patches.instruction]]`), los hooks de
  toolchain (`[[patches.hook]]` soportado en `config.cpp`) y la config del runtime
  (`GraphicsConfig`/`trigger_config_action`); NO se ha leído todavía la lógica del `expansionram`
  (tabla de opciones, handler, cómo aplica la resolución) ni se ha validado el sistema de textos
  para rótulos nuevos. => **Antes de comprometer la Fase C, hacer un spike de reconocimiento**
  (dev, sin dependencia del mantenedor):
  1. localizar el `expansionram` (carga + símbolos por el ancla `expansionram.c`) y leer su menú;
  2. probar el reemplazo del handler de una función de MÓDULO (no libultra) end-to-end (un no-op con
     log basta) — vía reimplementada o patch de instrucción/trampoline;
  3. probar pintar un rótulo propio con las fuentes del juego (test mínimo);
  4. probar aplicar+persistir un valor de `GraphicsConfig` en caliente.
  Go si 1-4 salen; si no, adaptar el plan (p. ej. overlay propio en vez de reutilizar el menú).

## 5. Evidencia

- `work/debug/cac/win_rec{,2,3}/` (grabaciones del mantenedor + dumps), `work/debug/cac/win_profile1/`
  (perfil de ticks), `work/debug/cac/corrupt_dumps/` (volcados citados por notas).
- Passes Windows: `logs_pacing_20260918_093603` (perfil limpio: live 30/s), `logs_replay_20260918_*`
  (replay con pacing de pared/VI), `logs_pacing_20260918_105205` (perfil con stalls de carga).
- Herramientas: `tools/lzkn64/lzkn64.py`, `tools/analysis/{test,detect}_lzkn64.py`,
  `tools/analysis/bizhawk_to_replay.py`, `tools/analysis/diff_state_at_vi.py`.
- Lanzadores nuevos: `port/run_cac_replay.bat` (mode=vi), `port/run_cac_replay_noaudio.bat`,
  `port/run_cac_profile.bat`, `port/run_cac_tick2.bat`, `port/run_cac_record.bat`.
