# SESIÓN — Hybrid Heaven (N64) → PC: mano de obra y contexto completo para retomar

> **Propósito**: este archivo da TODO el contexto para retomar el trabajo desde una sesión de
> chat nueva sin depender del historial. Léelo entero antes de tocar nada. Está vivo: actualízalo
> al final de cada sesión.

---

## 0. Proyecto y objetivo

Portar **Hybrid Heaven (N64, versión us_dec.z64)** a PC vía recompilación estática
(N64Recomp/RT64 en WSL/Windows del usuario). El usuario **no puede jugar dentro del contenedor**:
él guía (conoce el juego a fondo), el agente **conduce el emulador en el contenedor** y le manda
**screenshots GUARDADOS EN ARCHIVO** (los adjuntos del chat no le aparecen).

Objetivo inmediato: **tarea #3 — mapa overlay→RAM base** (qué overlay se carga en qué dirección
RAM, en qué orden, en qué momento del juego). Con el mapa + código recompilado se hace el port.

Fases del port (referencia):
1. ✔ Emulador estable + debugger del core funcionando (write-bp sobre RDRAM).
2. Captura de video fiable (avanzando: rice "presenta" a X; región viva 0x1C0000 en RDRAM).
3. **#3 Mapa overlay→RAM base** (EN CURSO; el write-bp ya registra overlays en vivo).
4. Instrumentar código recompilado (sustituir el harness del emulador; repo N64Recomp fuera del
   alcance de esta sesión).

---

## 1. Cómo está el entorno AHORA (estado transaccional 2026-09-08 13:45)

- **VÍA PRINCIPAL: Windows/BizHawk.** El usuario juega con `work/gameplay screenshots/
  bizhawk_hh_tracker.lua` (**v5**) y el entorno de captura **YA FUNCIONA**: PNG+`.txt`
  emparejados por wall-clock caen solos en esa carpeta compartida; `game.log`/`buttons.log`
  regeneran en la raíz. Dominio de memoria: **System Bus**.
- **Sets CONFIRMADOS con capturas + usuario** (notes §10.7): combate por turnos = `010F` +
  `01AA…01B8` + `0125/0127` (captura 15:19:25); menú de pausa (ITEM/TECH LIST/STATUS/OPTIONS)
  = `0113…0121` (captura 15:20:46). Detalle en notes §10.
- La sesión de prueba (15:10-15:21) está analizada (87 ids nuevos). La **partida larga del
  usuario aún NO está en el contenedor** (a 13:45 la carpeta sigue en 15:21). El usuario tiene
  un **save state** y puede remontar y capturar combates al instante.
- **Script v5**: PNG con `client.screenshot(ruta)` + nombre único `…HH.MM.SS.CCC`; F12 por
  flanco (1 captura); dump de `joypad.get(1)` en cada captura (para arreglar el registro del
  **stick**, que hoy NO registra aunque el usuario dice que SÍ lo usa). Anti-thrash de dominios.
- `session1/` guarda los PNG + logs de la sesión anterior (14:xx).
- **Cambios sin commit**: `tools/analysis/hhinput.c` (stick 4B en `/tmp/hh_keys.bin`), y este
  doc/README de la vía BizHawk cuando se confirme todo.
- Últimos datos clave: `work/scratch/sess42.*` (set gameplay 31 entradas),
  `work/gameplay screenshots/session1/` (logs+PNG sesión 14:xx),
  `work/screenshots/session38/stats_ANOTADO.txt` (ground truth).
- Últimos commits: `41539c7` (sess04 transición attract→juego). Ver §11.

---

## 2. Tipos de archivo críticos y dónde está cada cosa

`/app` es la raíz del repo (no es git repo? SÍ, inicializado local; ver §11).

### ROM y ejecución
- ROM: `/app/work/roms/us_dec.z64` (z64 XOR/plana; offset_code = offset_rom + 0x80000000).
- Harness: `/app/work/r64dump` (+ fuente `/app/tools/analysis/r64dump.cpp`).
  Core con debugger: `/app/work/libmupen64plus-debug.so`. Input: `/app/work/hhinput.so`.
  Plugins del sistema: `/usr/lib/mupen64plus/*.so` (glide64mk2, rice, rsp-hle, audio-sdl).
- Config teclado: `/root/.config/mupen64plus/mupen64plus.cfg` `[Input-SDL-Control1]`.

### Herramientas del agente
- `/app/tools/analysis/r64dump.cpp` — harness (ver §6).
- `/app/tools/analysis/fbdecode.py` — decodifica framebuffer 16bpp desde dumps (pitch=2B/px).
- `/app/tools/analysis/xshot(.c)` — captura root de un display X (Xlib XGetImage→PPM).
- `/app/tools/analysis/ppmascii.py <ppm> [anch]` — preview ASCII (el modelo NO ve imágenes).
- `/app/work/cap_loop.sh` — looper: captura cada 4s, descarta negros/iguales, último frame →
  `/tmp/latest_ascii.txt` + `/tmp/latest_stats.txt` (+/devuelve PPM cambiados).
- `/app/work/play.sh [segundos] [prefijo]` — receta de ejecución normal con glide.

### Notas y screenshots
- Notas técnicas: `/app/notes/2026-09-08-overlay-directory.md` (byte-order, directorio, write-bp,
  captura de video, fix FPE). **Este archivo sesion.md es el índice operativo; las notas el detalle.**
- Screenshots para el usuario: `/app/work/screenshots/sessionNN/` (NUEVA carpeta por sesión).
  Últimas: `session02/viva_t9_640x480.png` (0x1C0000, LIVE), `fb_t9_08000032.png`, `contacto_t1_t9.png`.

---

## 3. Calibración crítica del asistente (¡leer siempre!)

- **NO tengo visión**: no leer imágenes (error `400 At most 4 image(s)...` y cada imagen cuenta
  como prompt). Percepción visual = ASCII (`ppmascii.py`) + estadísticas (ImageMagick `convert`,
  `%k` colores, `mean`, `std`) + métricas (correlación vecinos, AE entre frames).
- **El usuario no ve adjuntos del chat**: los screenshots SIEMPRE se guardan en
  `/app/work/screenshots/...` y él los abre desde su Windows.
- **NO usar `pkill -f <patrón>`** (coincide con la cmdline de la propia shell → mata el tool/shell
  y timeout). Usar `pkill -x r64dump` o PIDs. BusyBox: `ps` no soporta `-o etimes` (usar `etime`);
  `pgrep` no tiene `-c`.
- PPMs generados por mis tools: formato correcto `P6 w h 255`; ImageMagick v7 usa `magick`, el
  alias `convert` sigue funcionando (aviso deprecado es inofensivo).
- Dumps RDRAM vienen **word-swapped** (ver §6.1). SIEMPRE bswap32.

---

## 4. Cómo relanzar un run (receta)

```sh
cd /app
# Xvfb activo: :99 (640x480x24, GLX, llvmpipe Mesa 26.1.6 GL4.6). Si muere, recrearlo:
#   Xvfb :99 -screen 0 640x480x24 +extension GLX +render >/tmp/xvfb.log 2>&1 &
export DISPLAY=:99

# Con GLIDE (default, estable pero NO presenta a X):
SDL_AUDIODRIVER=dummy \
CORE_SO=/app/work/libmupen64plus-debug.so \
RSP_PLUGIN=/usr/lib/mupen64plus/mupen64plus-rsp-hle.so \
INPUT_PLUGIN=/app/work/hhinput.so \
VIDEO_PLUGIN=/usr/lib/mupen64plus/mupen64plus-video-glide64mk2.so \
AUDIO_PLUGIN=/usr/lib/mupen64plus/mupen64plus-audio-sdl.so \
./work/r64dump work/roms/us_dec.z64 work/scratch/sessNN 1200

# Con RICE (presenta a X → capturas directas con xshot):
#   igual pero VIDEO_PLUGIN=...video-rice.so
```

Env vars del harness: `HB_RES_DIR=0x8008DFC0` (directorio), `HH_WP_ARM` (default 8s), `HH_DUMP_TIMES`
(default "2,4,8,16,32,64,128", pasar "15,20,25,...,120"). Log del run: `<prefijo>_log.txt`.

Input dinámico: escribir mask de 2B a `/tmp/hh_keys.bin` (0x1000=Start; DPad=WASD en config;
dejar en 0 para soltar). Un "tap" = escribir mask y luego 0.

---

## 5. El harness y el write-bp (núcleo de la tarea #3)

Ver `/app/notes/2026-09-08-overlay-directory.md` §5-6 para el detalle. Resumen:

- El bpx de escritura se añade **DESPUÉS** del resume del boot-halt (`DebugSetRunState(RUNNING)` +
  `DebugStep()`), como **DISABLED** y se arma a `HH_WP_ARM`=8s (el zerofill del directorio al boot
  dura ~6-8s reales; si no, aluvión de falsos hits). Rango = 1KB sobre la paddr del directorio.
- Cada hit real (filtrar `DebugBreakpointTriggeredBy() & M64P_BKP_FLAG_WRITE`) → log
  `loader pc=0x800173AC` (id) / `0x800173D8` (base) + snapshot de 1KB del directorio a
  `<prefijo>.dir.bin` + resume. En dumps `.tN` el directorio se lee aplicando bswap32.
- Resultado: el directorio vive en RDRAM física **0x8DFC0** (vista CPU 0x8008DFC0), 0x100 entradas
  de 8B. Layout por entrada: `+0` id16 (halfword alto tras bswap de la palabra), `+4` base32.
- El acceso es vía **dispatcher indirecto (jalr)**; los setters directos `dir_set_id`/`dir_set_base`
  (0x80017F84/0x80017FB8) tienen llamadores indirectos. `dir_get_*` en 0x80017C14/0x80017C3C.
- La asignación de bases es **única y creciente** = base_prev + size del recurso.

---

## 6. Hallazgos técnicos (correctos y verificados)

### 6.1 Byte-order
Dump word-swapped: `48 A9 1F 80` = valor CPU `0x801FA948`. Aplicar `bswap32` (o leer bytes 2-3,0-1).

### 6.2 Directorio (attract, sin input)
| t | entradas |
|---|---|
| 2-6s | 1 (slot0 id16=0xFFFE base=0x803837E0) — boot |
| ≥8s | 4: ids 0x0018/0x0073/0x00DE/0x0091 → 0x801FA948/0x8020B5C8/0x8020B938/0x802117F8 |
| final sess02 (01:56) | 6 no-nulas: 0x0018→0x801FA948, 0x0073→0x8020B5C8, 0x0075→0x8020B938, 0x007C→0x80225468, **0x012D→0x80235078** (nuevo en vivo), 0x0074→base=0 (**media escritura, captura real**) |

NOTA: el set de ids difiere entre runs (attract 0xDE/0x91 vs sess02 0x75/0x7C/0x12D). No reconciliado:
¿depende del recorrido/random? Pendiente de revisar (§12).

### 6.3 FPE 136 a ~6s → SOLUCIONADO
Audio-sdl falla en headless y deriva en división por cero (SIGFPE). Fix: `SDL_AUDIODRIVER=dummy`.
Verificado: sin audio→0, dummy+audio→0 (60s+), audio→136. Aplica a glide Y rice (rice "crash"
previo era esto, no el plugin).

### 6.4 Captura de video
- **glide64mk2**: crea ventana pero **NUNCA presenta a X** (negra, estática; los "frames" vistos
  eran residuo del backing store del root). No llama al vidext del harness (0 `[vid]`) — usa su
  propio SDL+GL. Con glide la vía visual = decodificar RDRAM.
- **rice**: con dummy-audio, estable y **presenta contenido a X** (crop 320x240: 2861 col,
  transforma entre capturas, ASCII=emblema centrado con reglas). Vía de captura directa.
- **RDRAM debug** (fbdecode.py v2, pitch=2B/px): región 0x000500 (16bpp 640?) y 0x080000 estáticas
  (prerender/backdrop); **0x1C0000 es LIVE** (FMV/backdrop oscuro con bandas y puntos — el
  "título de noche"/logo que cambia con el tiempo). PNG en session02/viva_t9_640x480.png.
- El attract no deja video 3D en RDRAM (glide/rice lo mantienen en su superficie GL); el VI real
  solo aparece cuando el juego usa su ruta "CG/software" (logo, FMVs, menús?, escenas).

### 6.5 Write-bp root cause (debugger del core)
Resumen en §5 + detalle en notas §4. Punto clave compilado a mano: `init_device()` re-memetea los
`bp_checks` y borra el gate del wp añadido en main() → añadir post-resume, DISABLED, armado a 8s.

---

## 7. Sesiones y log de trabajo (qué se hizo)

- Boot del emulador/boot-halt retomado, dumps word-swap resuelto, directorio localizado
  (0x8008DFC0), acceso indirecto determinado, write-bp root-caused + arreglado (causal RM en notas).
- Fix FPE (dummy audio), play.sh, sesión 1200s con write-bp: 4→6 entradas, captura en vivo de la
  última (0x012D @49B→0x80235078) y medio-write de 0x0074.
- fbdecode v1 (ruido: bug stride) → v2 (pitch correcto) → región viva 0x1C0000; PNGs para usuario.
- xshot: cap_loop ascii/stats; pkill pitfall descubierto; rice-crash falsa → afirmación rice OK.

---

## 8. Mapa overlay→RAM (corregido 2026-09-08 02:20)

### 8.0 Evolución temporal del directorio (sess04, t=5..120s — TRANSICIÓN ATTRACT→JUEGO)

| t | entradas | set |
|---|----------|-----|
| 5s | 1 | 0xFFFE@0x803837E0 (boot reserve) |
| 10s | 4 | **attract**: 0x0018, 0x0073, 0x00DE, 0x0091 @ 0x801FA948/0x8020B5C8/0x8020B938/0x802117F8 |
| 20-30s | 0 | directorio **reiniciado** (corte de intro con START) |
| 45s | 5 | **partida**: 0x0018, 0x0073, 0x0075, 0x007C, 0x012D @ 0x801FA948…0x80235078 |
| 60-90s | 6 | + 0x0074@0x80265FF8 |
| 120s | 0 | directorio reiniciado (¿cambio de fase?) |

**Lectura**: el set de partida es distinto del attract (0x75/0x7C/0x12D/0x74 vs 0xDE/0x91).
0x0018 y 0x0073 son comunes. El directorio se re-inicializa por completo al saltar la intro
(t=20-30s) y los overlays del juego se registran después. `sess04.dir.bin` acumuló 26
registraciones (muchas transitorias: el dir.bin captura cada escritura, los snapshots de dump
muestran el conjunto en cada instante).

### 8.1 Sesión sess02 (1200s, attract+menu, 31 entradas)

| # | id | base | gap prev |
|---|-----|------|----------|
| 0 | 0xFFFE | 0x803757E0 | — (boot reserve) |
| 1 | 0x00BF | 0x8026D438 | — |
| 2 | 0x0076 | 0x8026D518 | +0xE0 |
| 3 | 0x01EE | 0x80272BF8 | +0x56E0 |
| 4 | 0x01EF | 0x80272FF8 | +0x400 |
| 5 | 0x0131 | 0x80273268 | +0x270 |
| 6 | 0x00C3 | 0x80274F78 | +0x1D10 |
| 7 | 0x00C4 | 0x80278098 | +0x3120 |
| 8 | 0x010E | 0x8027F398 | +0x7300 |
| 9 | 0x0073 | 0x80280858 | +0x14C0 |
|10 | 0x00E0 | 0x80280BC8 | +0x370 |
|11 | 0x00C0 | 0x80283378 | +0x27B0 |
|12 | 0x007C | 0x80284A88 | +0x1710 |
|13 | 0x0074 | 0x80294698 | +0xFC10 |
|14 | 0x00CC | 0x802969F8 | +0x2360 |
|15 | 0x0126 | 0x802992D8 | +0x28E0 |
|16 | 0x01AE | 0x80299AE8 | +0x810 |
|17 | 0x00F4 | 0x80299B38 | +0x50 |
|18 | 0x00F8 | 0x802A0688 | +0x6B50 |
|19 | 0x00C2 | 0x802AAFD8 | +0xA950 |
|20 | 0x00A4 | 0x802AB0A8 | +0xD0 |
|21 | 0x00B0 | 0x802C4648 | +0x195A0 |
|22 | 0x01E5 | 0x802CDCF8 | +0x96B0 |
|23 | 0x01F1 | 0x802CEF28 | +0x1230 |
|24 | 0x00A8 | 0x802CEF58 | +0x30 |
|25 | 0x00A9 | 0x802CFB38 | +0xBE0 |
|26 | 0x00AA | 0x802D0B18 | +0xFE0 |
|27 | 0x0066 | 0x802D1588 | +0xA70 |
|28 | 0x00D6 | 0x802D5C18 | +0x4690 |
|29 | 0x00D2 | 0x802D6D08 | +0x10F0 |
|30 | 0x00C5 | 0x802D76B8 | +0x9B0 |

### 8.2 Sesión sess03 (menu cortado START, 23 entradas)

| # | id | base | gap prev |
|---|-----|------|----------|
| 0 | 0xFFFE | 0x8038B7E0 | — (boot reserve) |
| 1 | 0x008F | 0x80227FF8 | — |
| 2 | 0x007E | 0x80233C78 | +0xBC80 |
| 3 | 0x0076 | 0x8023D808 | +0x9B90 |
| 4 | 0x0073 | 0x80242EE8 | +0x56E0 |
| 5 | 0x007C | 0x80243258 | +0x370 |
| 6 | 0x00A0 | 0x80252E68 | +0xFC10 |
| 7 | 0x00B0 | 0x80253AB8 | +0xC50 |
| 8 | 0x0151 | 0x8025D168 | +0x96B0 |
| 9 | 0x015C | 0x80263318 | +0x61B0 |
|10 | 0x00B7 | 0x802689A8 | +0x5690 |
|11 | 0x00BD | 0x8026A318 | +0x1970 |
|12 | 0x0152 | 0x8026B328 | +0x1010 |
|13 | 0x0153 | 0x8026CCF8 | +0x19D0 |
|14 | 0x00BA | 0x8026D758 | +0xA60 |
|15 | 0x0074 | 0x8026D938 | +0x1E0 |
|16 | 0x00BB | 0x8026FC98 | +0x2360 |
|17 | 0x0080 | 0x80273CA8 | +0x4010 |
|18 | 0x00FA | 0x8027B398 | +0x76F0 |
|19 | 0x0104 | 0x8027FAC8 | +0x4730 |
|20 | 0x00F4 | 0x802884D8 | +0x8A10 |
|21 | 0x00F8 | 0x8028F028 | +0x6B50 |
|22 | 0x0098 | 0x00000000 | (mid-write) |

**Ids comunes a ambos runs (8):** 0x0073, 0x0074, 0x0076, 0x007C, 0x00B0, 0x00F4, 0x00F8, 0xFFFE

**Lectura:** el gap = tamaño del overlay PREVIO en la lista. El 0xFFFE es un
reserve de boot (base alta). La secuencia de carga cambia entre runs (attract vs menu
cortado) pero los ids base se repiten. Para completar el mapa falta progresar a
juego real (los overlays de fase/partida uniquement se cargan al iniciar una partida).

## 9. Parseo de dir.bin (corregido 2026-09-08 02:20)

Los dumps RDRAM son word-swapped (bswap32). Para `dir.bin` (snapshot del directorio):
- **id16**: bytes [2:4] de la palabra leídos como **little-endian** 16-bit → `struct.unpack('<H', raw[2:4])`
- **base32**: bytes [4:8] leídos como big-endian 16-bit then bswap32 → `bswap(int.from_bytes(raw[4:8],'big'))`
- El id16 ocupa la mitad ALTA de la primera palabra CPU; tras el word-swap, aparece en bytes [2:3]
  del raw.
- La **única fuente fiable** de los dumps `.tN` es bswap32 completo; el `dir.bin` snapshot
  requiere el parseo especial de id (little) + base (bswap de big).

## 10. Visión del modelo (actualización 2026-09-08 02:25)

El modelo **no soporta imágenes** (`"this model does not support image input"`). Las descripciones
de frames anteriores (menú, character) fueron **inferencias de conocimiento del juego, no lectura
visual**. Las imágenes adjuntas se acumulan en el prompt y acaban con el error 400
(`At most 4 images per prompt`). **No leer imágenes.** Percepción exclusiva vía:
- `ppmascii.py` (ASCII), ImageMagick (`%k`, `mean`, `std`, `AE`), correlación vecinos.
- El usuario ve los PNGs directamente desde su filesystem.

## 11. Git, seguridad y backup

- Repo git inicializado en `/app` (branch `main`); git installado vía `apk add git` (2.54.0);
  user local `opencode-hh <opencode@local>`, no remoto. `.backup/` en .gitignore.
- Commits: `bb7bb96` (harness wp+workflow), `78b8d1f` (fix dummy audio), `cd41ccd` (fbdecode v1),
  `002b1e5` (sesión operativa, notas 7b/7c). **PENDIENTE de commit**: fbdecode.py v2 + este
  sesion.md (hacerlo al cerrar esta sesión).
- Backup tarball: `/app/.backup/hh-wip-20260908-0139.tgz` (core parcheado + .so + tools + notas;
  sin ROM ni dumps). Regla: ante algo operativo nuevo, commit o backup inmediato.
- **Solo commitear cuando el usuario lo pida** (ha pedido "haz commit" cuando está operativo).

---

## 12. Tareas pendientes (priorizado, actualizado 2026-09-08 — VISIÓN DESACOPLADA)

> **NUEVA VISIÓN (ver PROYECTO.md §3.1):** la tarea #3 está **desacoplada** de la Fase 2. El port del
> **núcleo plano** se puede y debe empezar YA (no espera al mapa de overlays). La tarea #3 avanza en
> paralelo por la vía BizHawk (el usuario juega en el contenedor; es trabajo del usuario, no del
> agente). Los **bloqueantes** (ucode de audio + LZSS) son independientes del mapa y deben resolver
> de forma temprana. **Criterio de corte de la tarea #3:** ~6 sets de fase, no exhaustividad total.

### A. Fase 2 / recompilación (PROPULSOR — arrancar YA)
> **HANDOFF COMPLETO DE FASE 2:** leer **`notes/2026-09-10-handoff-fase2.md`** (todo el contexto:
> estado, comandos, herramientas, método Goemon, mapa de os funcs, diagnóstico del deadlock,
> plan Ghidra y próximo paso). La tarea #3 va aparte (vía BizHawk).

1. **[CÓDIGO] Arrancar la Fase 2 del NÚCLEO PLANO** — **AVANZADO (2026-09-10)**: generación completa
   + build Linux + boot: `init_heap → init_saving done → Calling entrypoint → Entrypoint returned`,
   y se crean/ejecutan threads del juego (juego **estable**, sin crash). Ver
   `notes/2026-09-10-recomp-fase2-boot.md`. **Bloqueante actual**: el thread principal (FUN_8002AEA0)
   bloquea en osRecvMesg en la cola principal 0x8005bf30 esperando la primera tarea del **scheduler
   del motor Konami** (no es un os function). Atacable con Ghidra (ver handoff).
2. **[CÓDIGO] Bloqueante — identificar el microcode de audio** (ucode custom KCEO vs asp). NO bloquea
   el render (dummy); sondear con Ghidra/runtime durante la Fase 2.
3. **[CÓDIGO] Bloqueante — mapear las variantes LZSS del `trans`** (`LZSS 5`/`LZSS 7`) usando las
   copias descomprimidas en RAM (0x801BB000, 0x801FA000, ...) como oráculo.
4. **[CÓDIGO] Mapa de símbolos del núcleo plano** (anclas `/game/source/*.c`, RZ011). Para overlays
   sí requiere el mapa de la tarea #3.
4b. **[CÓDIGO] Integrar modelo de threads (DECISIÓN A/B pendiente)**: el libultra del juego compilado
   como C usa los globals `__osRunQueue`/`__osRunningThread` + `__osEnqueueThread` (0x800276CC), que
   chocan con los os funcs reimplementados del runtime. Resolver con la opción A (reimplementar todas
   las os) o B (mantener globals del juego). Detalle en la nota de Fase 2.

### B. Tarea #3 (desacoplada, vía BizHawk — el usuario juega)
5. **[OPCIONAL/AMPLIAR COBERTURA]** Pasar la partida larga al contenedor: añade fases nuevas al
   mapa y permite etiquetar más sets con el usuario. **NO bloquea** la Fase 2: el mecanismo `trans`
   está confirmado y el mapa por orden temporal+tamaño es derivable de los dumps que ya hay (87 ids +
   set 31 entradas gameplay + sesión1).
6. **[AGENTE] Procesar los datos nuevos**: emparejar PNG↔`.txt` por wall-clock, listar ráfagas
   de overlays por fase, y pedir al usuario las horas de las capturas que son combates/menús.
7. **[AGENTE] Etiquetar pending sets**: diálogo NPC (`0092/00A2/00AD/00A7/0231`), submenús
   `0122-0124`, pares `00D2/00D1`, `00D6/0231`, `01AB/00A6/00E5/00FE`, `012B/012C/0112`, `0093/0094`.
8. **[ENTREGA] Mapa overlay→RAM por fase** (combate/menú/gameplay/diálogo) consolidado en notes
   §10 → entregable de la tarea #3 para el port. Aplicar **criterio de corte** (~6 sets de fase) y
   no bloquear la Fase 2 con exhaustividad.

### C. Indirectos / menor prioridad
9. **[AGENTE] Registrar el stick** (baja prioridad, 1 min): tras un F12 con la v5, leer el dump de
   `joypad.get(1)` del `.txt` → ajustar `update_stick()` con las claves reales del N64. Solo cuando
   se necesite para separar menú de combate en los sets.
10. ~~**[LIMPIAR]** Borrar el `bizhawk_hh_tracker.lua` viejo de `work/` (raíz).~~ ✅ **(hecho por el
    usuario, 2026-09-08 15:0x)**.

**Backlog técnico (no bloquea, no perderlo)**:
11. **Reconciliar ids** attract (`0xDE/0x91`) vs partida (`0x75/0x7C/0x12D`): ¿orden de carga
    distinto o tabla 0x18B diferente? (notas §6.2).
12. **Audio** (opcional, más adelante): con dummy-audio todo es silencioso; no afecta a la Fase 2.
13. **Pivot N64Recomp**: el emulador sirve para obtener el mapa (tarea #3) y validar el runtime;
    la instrumentación definitiva irá sobre el código recompilado (repo fuera de alcance de esta carpeta).

**Objetivos del TODO interno/histórico (persistidos para no perderlos; 3 superados)**:
- ✅ **SUPERADO** "Dump RDRAM en runtime headless (core + RSP-hle real)" y "Detectar overlays por
  diffs" y "Inyección de input para avanzar menús": reemplazados por el **directorio `trans`
  0x8008DFC0** + write-bp (§5) + la vía **BizHawk/Windows** (§15). El mapa overlay→RAM de todo el
  juego es hoy la tarea #3 en curso (orden temporal = ráfagas; tamaño = gap entre bases).
- ✅ **AVANZADO/SUFICIENTE** "Derivar mapa completo overlay→RAM base por orden temporal + tamaño":
  con el mecanismo confirmado y los dumps presentes (87 ids + set gameplay 31 + sesión1) el mapa
  es derivable ya; ampliar cobertura con la partida larga = opcional (§12 #5).
- ⏳ **PENDIENTE** **Descompresor LZ del `trans` loader**: mapear las variantes LZSS/LZKN64 usando
  las copias DESCOMPRIMIDAS ya visibles en RAM (0x801BB000, 0x801FA000, ...) como **oráculo**
  (notes/2026-09-06_emulator-rdram.md + PROYECTO.md §7.1.3). → **ahora BLOQUEANTE marcado (§12 #3)**.
- ⏳ **PENDIENTE** **Microcode de audio + tabla `seginfo` en runtime**: el ucode de audio no
  matchea aspMain (posible KCEO custom); localizar la tabla `seginfo` en RAM en runtime
  (PROYECTO.md §9 #6, §7.1.2). → **ahora BLOQUEANTE marcado (§12 #2)**.

---

## 14. ESTADO ACTUAL / LO NUEVO (2026-09-08 12:50) — ¡GAMEPLAY ALCANZADO + VÍA WINDOWS!

Resumen de todo lo hecho hoy (después del handoff anterior). Detalle técnico completo en
`notes/2026-09-08-overlay-directory.md` §8-9.

### 14.1 Tele-operación: se llegó a GAMEPLAY con el harness Linux
- Secuencia de teclas que llega a gameplay (frames): Start f004/f005/f008/f010/f046 (logos/ExpPack),
  A f050 (New Game), A f055 (Game Start), +60s de intro, **Start f115 = skip intro → gameplay ~t=158s**.
  - Los diálogos controller/rumble NO siempre aparecen (el juego recuerda config previa); si salen, A
    en f060/f065/f070.
  - Sesiones OK: sess38 (EMU0=1788864571), sess41, sess42 (EMU0=1788867028). Confirmado por el usuario:
    "Hemos llegado al gameplay".
- `stats.txt` tiene la media DESFASADA de la imagen real; el usuario anotó la verdad en
  `work/screenshots/session38/stats_ANOTADO.txt` (168 líneas). Usar SIEMPRE las anotaciones, NO stats.

### 14.2 Input: stick añadido al plugin `hhinput.c` (SIN commit aún — git diff pendiente)
- `/tmp/hh_keys.bin` ahora 4 bytes BE: mask(2B) + Y_AXIS + X_AXIS (firmados). Recompilado a
  `work/hhinput.so`. Stick: arriba=Y-127, derecha=X+127, abajo=Y+100.
- D-pad OK para menús, pero el PJ se mueve con STICK (no D-pad). A salta, B acción/abrir. La cámara
  sigue al PJ → caminar recto con stick es inestable (cruzar puertas a ciegas: difícil).

### 14.3 Parse del directorio VALIDADO por doble vía (importante)
- BizHawk (CPU BE nativa: `id=bytes[0..1]`, `base=bytes[4..7]`) y harness Linux (dumps word-swapped,
  bswap32 primero) convergen al MISMO set par a par. Ej: `00180000801FA948 → id=0x0018 base=0x801FA948`.
- Leer como CPU BE siempre; en dumps del harness aplicar bswap32 antes.

### 14.4 Set de gameplay capturado (31 entradas, `scratch/sess42.dir.bin`)
Set ESTABLE mientras el PJ deambula/cruza escenarios; NO crece con el movimiento. Mapa completo en
notes §8.5 (0x00BF→0x802746A8, 0x0076→0x80274788, 0x0073→0x80287AC8, ..., 0xFFFE→0x803757E0).
Los overlays de fase/combate/menú probablemente añaden más; las bases las asigna en runtime un
asignador (init_trans 0x80018420, tabla 0x8009EBD4, plantilla ROM 0x8004413C) ⇒ vía estática
insuficiente ⇒ hay que capturar dinámico (Write).

### 14.5 VÍA WINDOWS/BizHawk (ACTUAL — el usuario juega y captura)
- Decisión: el usuario juega la versión real en BizHawk (Windows) con `work/bizhawk_hh_tracker.lua`
  que vuelca directorio (0x100 entradas) + pulsaciones + screenshot por F12. Output en la carpeta
  `work/gameplay screenshots/` (game.log, buttons.log, scr_*.png).
- README de uso: `work/gameplay screenshots/README_bizhawk.md`. Script: `work/bizhawk_hh_tracker.lua`.
- **Último estado (12:10): EL LOG FUNCIONA** — buttons.log registra PRESS/RELEASE (Start/A/Z) y
  game.log volcó attract→menú→gameplay con los mismos ids que el harness Linux. Falta que F12
  saque las capturas (en prueba por el usuario; ver `ok=` en game.log para diagnóstico).
- Teclas: F12 = screenshot+volcado; F11 = reset (borra logs y captures). El script es resiliente a
  NullHawk (avisa y sigue esperando a que se cargue la ROM).

### 14.6 Pendientes inmediatos (ordenados)
1. [BizHawk] Que F12 genere las capturas (usuario probando). Si falla: comprobar el `ok=` del
   game.log y la ruta; alternativa `mainmemory.read_u8` si el core no expone el dominio por defecto.
2. [BizHawk] Usuario juega combates/puertas/menús del juego entero pulsando F12 y manda la carpeta
   `gameplay screenshots/` → correlacionamos overlay↔botón↔pantalla.
3. [Linux] Commit de `tools/analysis/hhinput.c` (stick 4B) cuando se confirme.
4. Entregar al usuario el mapa de 31 entradas (notes §8.5) junto con la tabla de ids por fase.

---

## 13. Índice rápido de archivos

- `/app/sesion.md` — ESTE documento (handoff).
- `/app/notes/2026-09-08-overlay-directory.md` — notas técnicas detalladas.
- `/app/tools/analysis/r64dump.cpp` → `/app/work/r64dump` — harness.
- `/app/tools/analysis/fbdecode.py`, `xshot(.c)`, `ppmascii.py` — análisis.
- `/app/work/play.sh`, `/app/work/cap_loop.sh` — recetas.
- `/app/work/libmupen64plus-debug.so`, `/app/work/hhinput.so` — core+input.
- `/app/work/scratch/sess02.*` — dumps/logs/dir.bin de la sesión reciente.
- `/app/work/screenshots/session02/` — PNGs entregados al usuario.
- `/app/work/roms/us_dec.z64` — ROM.
- `/app/work/mupen-src/` — fuente del core parcheado (respaldo en tarball).
- `/app/work/wsl_package/` — (a medio hacer; el plan acordado es conducir desde el contenedor,
  no usar WSL para el harness).

---

## 15. LO ÚLTIMO (13:45) — PIPELINE BizHawk FUNCIONAL + 2 SETS CONFIRMADOS

Actualización que sustituye el estado de §14. Detalle técnico en `notes/2026-09-08-overlay-directory.md` §10.

### 15.1 Dónde estamos

- El flujo Windows/BizHawk es la vía principal para la tarea #3 (mapa overlay→RAM de todo el juego):
  el usuario juega, el script vuelca el directorio 0x8008DFC0 + botones + capturas, el agente
  correlaciona. **Todo funciona** desde el script **v5**.
- Sesión de prueba (15:10-15:21) analizada al completo: **87 ids nuevos** sobre el set de 31 de
  gameplay; 671 volcados; 60 capturas.
- `session1/` = archivo de la sesión vieja (PNG 14:xx + game.log/buttons.log).

### 15.2 Lo último conseguido (oro puro + correcciones)

- **Combate por turnos (pelea de lucha libre) = set confirmado.** Captura 15:19:25 (se carga SOLA,
  sin botones). ids: `010F` (sustituye a `00C5` en el slot 28, mismo base 0x802EC298) + `01AA…01B8`
  (slots 29-42, bases 0x802EDAA8→0x802F39F8) + `0125` (s43 0x802F5ED8) + `0127` (s44 0x802FEDA8).
  En la sesión 1 el mismo combate salió con menos ids (varía con el momento/enemigo).
- **Menú de pausa (Start: ITEM / TECH LIST / STATUS / OPTIONS) = set confirmado.** Captura
  15:20:46/48. ids: `0113` (s29, el primero en cargar) + `0114…0121` (s30-s43). `0122/0123/0124`
  llegan ~1s después (submenús, por etiquetar).
- **Corrección**: lo que antes llamábamos "pistola/robots" (t≈476, ids `010F`+`01AA…01B4`) ERA el
  combate por turnos. La pistola (R+A) NO tiene HUD (verdad del usuario).
- **Detectado**: el stick se usó de verdad pero NO se registró (fallo de claves joypad) → v5 vuelca
  `joypad.get(1)` en cada F12 para descubrir las claves reales. SOLO queda pendiente de confirmar con
  un F12 de la próxima sesión.

### 15.3 Reglas de etiquetado del usuario (ground truth)

- A rápidas seguidas (20-30/s) = pasar **diálogos con NPCs**.
- R = saca pistola, A = disparo (derribar robots); **la pistola NO tiene HUD**.
- Combate contra mutantes = **por turnos** (lucha libre) con **menú para elegir golpes** (sí HUD).
- El usuario tiene un **save state** y puede remontar la partida desde ahí.

### 15.4 Qué queda (tareas en §12 — VISIÓN DESACOPLADA)
- **Propulsor: arrancar la Fase 2 del núcleo plano** (ELF → build Linux → RT64) — no espera a la
  tarea #3; arranca con audio dummy. (§12 #1)
- **Bloqueantes a resolver de forma temprana**: microcode de audio custom KCEO y variantes LZSS del
  `trans`. (§12 #2 y #3)
- La **tarea #3** avanza en paralelo por la vía BizHawk (el usuario juega): pasar la partida larga,
  procesar/etiquetar sets, y consolidar el mapa con criterio de corte (~6 sets de fase).

### 15.5 Visión operativa desacoplada (2026-09-08)
- El port del **código principal plano** es independiente del mapa de overlays → se arranca **ya**
  (Fase 2). Estilo Zelda64/Goemon: base primero, overlays de fase después.
- La **tarea #3** (mapa overlay→RAM) es necesaria para los ~462 overlays de código, pero NO bloquea
  el arranque/render del núcleo. Avanza en paralelo (trabajo del usuario en BizHawk).
- **Criterio de corte de la tarea #3:** cubrir los ~6 sets de fase y consolidar el entregable, no
  perseguir exhaustividad que retrase la Fase 2.
- Detalle técnico/estrategia: `PROYECTO.md` §3.1 + §9, `docs/README.md` §0/§2/§4.

---

# 16. FASE 2 — RECOMPILACIÓN / BOOT (actualizado 2026-09-10)

> Esta sección documenta el trabajo de **portado/recompilación del núcleo plano** (Fase 2 del §12)
> hecho en esta tanda de sesiones. Es LA documentación de handoff para retomar desde el estado
> actual. La tarea #3 (BizHawk/overlays, §§1-15) sigue desacoplada y avanzando en paralelo.

## 16.0 ESTADO ACTUAL (2026-09-10) — RESUMEN EJECUTIVO

- **El port SÍ compila y genera exe** con el set de funciones **retail** (301 funcs, 10 archivos)
  restaurado en `port/HybridHeavenRecomp/RecompiledFuncs/`. Este es el **estado conocido-bueno**
  sobre el que construimos.
- **El boot NO llega a gameplay todavía.** El impedimento real NO es "nombrar os-functions" (como
  decía el plan §12), sino la **syms con límites de función sueltos/fusionados**:
  - `merge_loop.py` fusionó funciones al tropezarse con errores de branch → **contenedores enormes**.
  - ~74 de 130 objetivos `LOOKUP_FUNC` del boot quedaron **dentro de contenedores** y no están
    registrados como función → en runtime: `Failed to find function at 0x80030610` (etc.).
  - Además, algunas entradas de la syms apuntan a **bloques de DATOS** (datos comprimidos/asset en
    la región plana de la ROM) → al regenerar chocaban con `Unhandled instruction: INVALID`
    (`0xef1ed4aa` tiene opcode 59 = no existe), o instrucciones sin soporte (`trunc.l.d`, `teq`).
- **Enfoque nuevo (difiere del plan §12)**: usar `use_lookup_for_all_function_calls = false` con UNA
  sección única (`.entry`+`.main` fusionadas). Así el **recompilador descubre automáticamente los
  límites finos de función desde el código** (`static_*`, una por dirección jal/llamada) y el problema
  de los contenedores desaparece sin tocar a mano las 300+ entradas de la syms. Nombrar os-functions
  queda como tarea posterior (solo cuando una syscall/ruta falla), NO es el bloqueante del boot.
- **BLOQUEANTE activo del enfoque nuevo**: la regeneración unificada todavía **no emite C válido**
  en 2 archivos (`funcs_5.c` y `funcs_12.c`): al hacer stub de una función con datos, se corta una
  cadena de `if (cond) {` anidados (branch en delay-slot de branch) sin cerrar las llaves. Ver
  §16.4 para el fix pendiente. Hasta resolverlo, `config/RecompiledFuncs_unified/` NO se debe copiar
  al port.

## 16.0b INVESTIGACIÓN 2026-09-10 (emulador harness + mapeo os funcs) — hallazgos

> Complementa `notes/2026-09-10-n64sym-osfuncs-rootcause.md` y `notes/2026-09-10-osfuncs-investigation.md`.
>
> ⚠️ **ESTADO ACTUAL (2026-09-10, tras TODO el trabajo):** la causa raíz está RESUELTA (os funcs
> mapeadas) y se avanzó con la **solución de fondo (Ghidra)** → **el game loop CORRE**. El bloqueante
> actual es un **crash NO-DETERMINISTA del allocator de heap** (`FUN_80003824`, race/heap init) y aún
> **0 tareas RSP**. Para el estado EXACTO y el TODO actualizado, ver **§16.6/§16.7** y
> `notes/2026-09-10-ghidra-syms-solucion-fondo.md` §7.5.

- **Harness Linux puesto a funcionar** (faltaban deps: xvfb, libx11, glu, libSDL2, libopcodes,
  python3+capstone, git — reinstaladas). Write-bp (`HB_RES_DIR`) y exec-bp (`HB_EXEC`) operativos.
- **write-bp en `0x8005be40` contaminado** (pila del thread 5) y **`ra` del harness lee 0** → no se
  aisló el emisor. El juego SÍ inicializa `0x8005be40` como cola y thread 5 recibe de ella.
- **CORRECCIÓN**: la conclusión "os funcs mal mapeados" era ERRÓNEA (desensamblador con offset de ROM
  equivocado: falta el header 0xC00 → `rom_off = vram - 0x7FFFF400`). Los 11 os funcs mapeados son
  CORRECTOS (confirmado por `n64sym`).
- **CAUSA RAÍZ CONFIRMADA (herramienta `n64sym`)**: la syms solo mapea 11 os funcs; la mayoría de los
  os funcs libultra (~147) están como `FUN_xxx` → el recompilador los compila como código de juego →
  el juego usa su propio `osSetTimer` (0x80034560) que gestiona su lista de timers vía
  `__osInsertTimer`/`__osSetTimerIntr`/`__osTimerInterrupt` y el registro **cop0 Compare** (no emulado
  por el runtime) → el timer no dispara → thread 5 colgado en `osRecvMesg(0x8005be40)`.
- **SOLUCIÓN**: renombrar en la syms los `FUN_xxx` → os funcs con los vrams de `n64sym` (verificar
  `_recomp` en el runtime antes). Lista de referencia:
  `notes/reference/n64sym_osfuncs_us_retail.txt` (147 os funcs).
- **FIX APLICADO (misma sesión) — thread 5 DESBLOQUEADO**: se mapearon 46 os funcs en la syms +
  `use_lookup_for_all_function_calls=false` (auto-detección). Resultado: thread 5 ya NO se queda en
  `osRecvMesg(0x8005be40)` (0 ocurrencias), 0 "Failed to find function" (cubre las 293 faltantes),
  pero el boot **crashea (SIGSEGV)** en el allocator de heap (`FUN_80003824`/`static_0_80003D3C`)
  por **límites de función** del auto-detector. Detalle: `notes/2026-09-10-n64sym-osfuncs-rootcause.md` §8.
- **Próximo paso**: corregir los límites de las funciones mal acotadas (iterativo) o regenerar una
  syms completa con límites correctos.

## 16.1 QUÉ SE HIZO EN ESTA TANDA (cronología)

### 16.1.1 Arreglos del build (Windows)
- N64Recomp en Windows compila como `.lib`, NO genera `.exe`: la regeneración de `RecompiledFuncs`
  se hace en el contenedor con el binario ELF y luego se copia al port. (Decisión clave.)
- `config/RecompiledFuncs/` original estaba roto (faltaba `funcs.h` y `funcs_0.c`); `RecompiledFuncs_retail`
  tenía una mezcla inconsistente. Se regeneró un set retail limpio desde `us_retail.syms.toml`
  (salida estable: `config/RecompiledFuncs_retail/`, 301 funcs, exit 0) y se copiaron los 10 archivos
  al port → **`Hybrid Heaven Recomp.exe` se genera.**

### 16.1.2 Orden de arranque (main.cpp)
- **`recomp::start` NUNCA retorna** (bloquea en `while (!exited)`), así que `start_game()` se debe
  llamar **ANTES** de `recomp::start`. Corregido en `src/main/main.cpp`.
- `game_entry.entrypoint` = `hh::recomp_entrypoint`; `entrypoint_address = get_entrypoint_address()`
  (`0x80000400`).

### 16.1.3 Registro de funciones planas (overlays.cpp / overlays.hpp)
- **`register_flat_code()`**: añadido a `librecomp/src/overlays.cpp` (+decl en `overlays.hpp`).
  `load_overlays(rom, ram, size)` calcula el RAM relativo al entrypoint, INCORRECTO para secciones
  planas con `ram_addr` absoluto. `register_flat_code()` registra las funciones de TODAS las
  secciones en su `ram_addr` absoluto; se llama en `init()`.
- Antes de esto: `Failed to find function at 0x80001078`.

### 16.1.4 Crash de arranque ($a0) + SEH + logging
- Crash initial (window se abría y cerraba): ACCESS VIOLATION. Handler SEH `run_entrypoint_seh` en
  `librecomp/src/recomp.cpp` loguea `Crash host IP` (usar `ExceptionAddress`, no `ExceptionInformation[0]`),
  `Crash host addr` y `Crash N64 addr`.
- Root cause: el main del boot usa **`$a0` como puntero base de un struct** pero el recompilador sólo
  inicializa `$sp` (en Goemon el main lo setea él; en HH no). Fix en `init()`:
  `ctx->r4 = (gpr)(int32_t)0x800E5F40;` — **las macros `MEM_*` esperan direcciones sign-extendidas**
  (0x800E5F40 = fin de `.main` = RAM válida). Antes de esto: crash N64 addr `0x2`.
- Logging instrumentado: `hh::log()` → `hh.log` en `%APPDATA%\HybridHeavenRecomp` (truncado con
  timestamp `[HH:MM:SS.mmm]`); `boot_log()` → `boot.log` en CWD (= junto al exe), también truncado
  y con timestamp. Instrumentados: init_heap, entrypoint, create_gfx/create_window, RT64 setup,
  `send_dl`, validación de ROM, overlays registered.

### 16.1.5 Prioridad "no fatales" en el recompilador (toolchain/src/N64Recomp)
Dificultan la regeneración estas cosas que ahora se resuelven (ver §16.2 para el estado exacto):
- `Unhandled instruction: trunc.l.d` (FUN_80034a10) → añadidas `cpu_trunc_l_s`/`cpu_trunc_l_d`
  (`TruncateLFromS/D`, `FdU64`) al mapa de unarias en `src/operations.cpp`.
- `teq` y trampas similares (`tne`, `tge`, `tgeu`, `tlt`, `tltu`) → tratadas como **no-op** en
  `src/recompilation.cpp` (patrón de `cpu_cache`/`cpu_eret`). OJO: `cpu_tgt`/`cpu_tle`/`cpu_tleu`
  NO existen en rabbitizer — no usarlos.
- Objetivo de jal **desconocido en runtime** (`0x8400103C`: puntero a memoria no plana/overlay):
  el caso `NoMatch` en `src/recompilation.cpp` ahora **cae a `call_by_lookup` (LOOKUP_FUNC en
  runtime)** en vez de `return false` (que abortaba toda la generación).
- **Stubbing no-fatal**: ante `Unhandled instruction: INVALID` o fallo de análisis `analyze_function`:
  se emite una función trampa `do_break(0x…); return;` (existe en `librecomp/src/recomp.cpp`, imprime
  el vram y hace `assert(false)`) y la generación CONTINÚA en vez de matar el build completo. Se
  emiten también las etiquetas pendientes antes del `do_break` para que los `goto` previos queden definidos.
  - Mensaje de error con dirección: `Unhandled instruction: {} @ 0x{:08X}`.

### 16.1.6 Icono de ventana
- `HybridHeavenV2.ico` ≙ icono del exe. `assets/icon_bmp.inc` regenerado (96×96) con **altura
  negativa** (`0xA0 0xFF 0xFF 0xFF` = -96) porque los datos van top-down y `set_window_icon` no
  invierte → icono derecho (antes invertido).

## 16.2 ARCHIVOS MODIFICADOS / ESTADO EXACTO

| Archivo | Cambio / estado |
|---|---|
| `port/HybridHeavenRecomp/RecompiledFuncs/` | **RESTAURADO al set retail** (10 archivos, 301 funcs). Buildable. NO tocar hasta completar §16.4. |
| `port/HybridHeavenRecomp/CMakeLists.txt` | Lista `funcs_0..6.c + lookup.cpp` (restaurado). Al copiar el set unificado habrá que añadir `funcs_7..12.c`. |
| `config/game_retail.toml` | Config estable: `use_lookup_for_all_function_calls=true`, `us_retail.syms.toml`, out `RecompiledFuncs_retail`. |
| `config/game_unified.toml` | Config unificada: `false`, `us_unified.syms.toml`, out `RecompiledFuncs_unified`. **WIP.** |
| `config/us_unified.syms.toml` | Sección única `.text` vram `0x80000400` size `0x4E5B40`, ~301 funcs. **WIP.** |
| `config/RecompiledFuncs_unified/` | **Salida WIP — C inválido en `funcs_5.c` y `funcs_12.c`** (llaves sin cerrar). NO copiar al port. |
| `toolchain/src/N64Recomp/build_recomp/N64Recomp` | Binario recompilador con todos los fixes de §16.1.5. El `N64Recomp` válido es SOLO el de `build_recomp/` (los de `build2/` están desfasados). |
| `toolchain/src/N64Recomp/src/operations.cpp` | Añadidos `cpu_trunc_l_s/cpu_trunc_l_d`. |
| `toolchain/src/N64Recomp/src/recompilation.cpp` | NoMatch→lookup; trampas→noop; stubbing no-fatal; dirección en error. **Falta el fix de §16.4.** |
| `port/HybridHeavenRecomp/src/main/main.cpp` | Orden `start_game` antes de `recomp::start`; logging. |
| `port/HybridHeavenRecomp/src/main/support.cpp` | `hh::log` (truncado+timestamp), logging create_gfx/window. |
| `port/HybridHeavenRecomp/src/main/rt64_render_context.cpp` | Logs RT64 setup + `send_dl`. |
| `port/HybridHeavenRecomp/lib/.../librecomp/src/overlays.cpp` +`overlays.hpp` | `register_flat_code()`. |
| `port/HybridHeavenRecomp/lib/.../librecomp/src/recomp.cpp` | `boot_log`, SEH, `$a0=0x800E5F40`, entrypoint logs, `do_break` (ya existía). |
| `port/HybridHeavenRecomp/assets/icon_bmp.inc` | Icono regenerado (altura -96). |

Todo esto SIN git (el repo no es git): los cambios están solo en el árbol. No commitear sin pedirlo.

## 16.3 RECETA DE REGENERACIÓN (contenedor)

```sh
# 1) Construir el recompilador (tras tocar toolchain):
cd /app/hybrid-heaven-recomp/toolchain/src/N64Recomp
cmake --build build_recomp --target N64RecompCLI        # binario → build_recomp/N64Recomp

# 2) Regenerar el set unificado:
cd /app/hybrid-heaven-recomp/config
rm -rf RecompiledFuncs_unified
/app/hybrid-heaven-recomp/toolchain/src/N64Recomp/build_recomp/N64Recomp game_unified.toml 2>&1 | tee /tmp/regen_unified.log
# Esperado: "Function count: 301", exit 0, 13 archivos funcs_0..12.c + funcs.h + lookup.cpp + recomp_overlays.inl
# Varios "[Warn] Stubbing X ..." = funciones con datos absorbidos (trampa do_break). Normal.

# 3) CUIDADO: verificaciones ANTES de copiar al port:
gcc -fsyntax-only -I port/HybridHeavenRecomp/RecompiledFuncs \
    -I port/HybridHeavenRecomp/lib/N64ModernRuntime/N64Recomp/include -x c <cad a funcs_*.c>
# (todas deben pasar; hoy fallan funcs_5.c y funcs_12.c por llaves sin cerrar)

# 4) Copiar al port (SOLO tras fases limpias):
cp config/RecompiledFuncs_unified/funcs.h config/RecompiledFuncs_unified/funcs_*.c \
   config/RecompiledFuncs_unified/lookup.cpp config/RecompiledFuncs_unified/recomp_overlays.inl \
   port/HybridHeavenRecomp/RecompiledFuncs/
# + añadir en CMakeLists las líneas RecompiledFuncs/funcs_7.c .. funcs_12.c
```

Windows (usuario): `cmake --build build --target HybridHeavenRecomp --config Debug` desde
`port/HybridHeavenRecomp`. Exe: `build\bin\Debug\Hybrid Heaven Recomp.exe`. Logs junto al exe:
`boot.log` (CWD) y `hh.log` (`%APPDATA%\HybridHeavenRecomp`). Copiar ambos al pegar en el chat.

## 16.4 BLOQUEANTE ACTIVO + CÓMO RESOLVERLO

**Qué pasa**: al stubbear una función cortada en un `INVALID`, el cuerpo parcial dejó **cadenas de
`if (cond) {` anidadas sin cerrar** (branch cuyo delay-slot es otro branch → el generador anida
`if { if {` y cierra recién al final de la cadena; al cortar antes, no cierra). Concretamente en
`funcs_12.c`: `static_0_80151DA4` (+4), `static_0_80133AA0` (+1), `static_0_80151BC4` (+1); total +6.
En `funcs_5.c`: +2.

**Fix propuesto (NO implementado — no tocar más código esta tanda)**:
1. En `toolchain/src/N64Recomp/src/recompilation.cpp` pasar `bool* stubbed_out` por
   `recompile_function`/`recompile_function_impl` (default `nullptr`) y fijarlo al stubbar.
2. En `toolchain/src/N64Recomp/src/main.cpp` (sitios ~775 y ~865): bufferizar cada función en un
   `std::ostringstream`, llamar `recompile_function(..., &stubbed)`; si `stubbed`, DESCARTAR el
   buffer y emitir limpio `RECOMP_FUNC void <name>(uint8_t* rdram, recomp_context* ctx){ do_break(<vram>u); return; }`
   en `current_output_file`; si no, escribir el buffer al archivo. Mantener `functions_per_output_file`.
   (Alternativa 2: cerrar las llaves pendientes contando los `if` de rama abiertos; más frágil.)
3. Regenerar + `gcc -fsyntax-only` en TODOS los `funcs_*.c` = OK → §16.3 paso 4.
   - La función está declarada en `funcs.h` de todos modos (export_function_indices), por eso el
     stub debe existir sí o sí para no romper el link.

**Riesgo deliberado**: las funciones stubbed son bloques de datos; si alguna se llama en runtime
`do_break` la detecta al instante en `boot.log` (vram impreso) → iterar como hasta ahora.

## 16.5 PROBLEMAS CONOCIDOS / NOTAS PARA LA SIGUIENTE SESIÓN

- **Set unificado WIP**: NO copiar al port todavía (C inválido). El port queda en retail (buildable)
  para poder probar cualquier otro cambio.
- `0x8400103C` = target jalr calculado en runtime apuntando a memoria **no plana** (0x84…). Con el
  fix NoMatch ya no aborta la generación; en runtime si el boot lo ejecuta dará lookup fallido.
  No bloquear por esto: puede que esa ruta no se ejecute temprano.
- Los auto-detected `static_0_80035090`, `static_*` etc. registrados por `register_flat_code()` se
  espera que resuelvan el "Failed to find function at 0x80030610" (ese target está dentro de un
  contenedor; con la sección única + `false` se convierte en `static_0_...`).
- Popup "Failed to write to the save file…" al arrancar: **no fatal** (save folder/permisos), tratar
  aparte.
- `0x800E5F40` = `$a0` inicial (end of `.main`, RAM válida). Recordar el sign-extend
  `(gpr)(int32_t)`.
- Shell en el contenedor es **dash**: no usar `${PIPESTATUS[0]}` (da syntax error). Usar `echo $?`
  o capturar a archivo.
- No hay python en el contenedor: para leer bytes de la ROM usar `xxd -g4 -s <off> -l <len>`.
- `sesion.md` real: `/app/hybrid-heaven-recomp/sesion.md` (AGENTS.md dice `/app/sesion.md`; corregir
  esa ruta si se toca AGENTS.md).

## 16.6 TODO RESTRUCTURADO (2026-09-10, ACTUALIZADO tras sesión de boot) — NUEVO ENFOQUE

1. [hecho] Port sources / CMake / submodules / Linux validation / headless sanity.
2. [hecho] Baseline Windows: port en retail → `Hybrid Heaven Recomp.exe` (confirmar rebuild).
3. [hecho] Terminar regeneración unificada con C válido (generación limpia, exit 0, set completo).
4. [hecho] Regenerar limpio + `gcc -fsyntax-only` en todos los funcs_*.c + exit 0 + set completo
   (us_unified + N64Recomp tolerante a data/overlay; ver nota Fase 2).
5. [hecho] Copiar unificado al port + CMakeLists (GLOB funcs_*.c) + compile check Linux (build_dbg OK).
   PENDIENTE: rebuild Windows del usuario.
6. [hecho] Run headless Linux → iterar fallos runtime: boot llega a `Entrypoint returned` y crea
   threads. Se añadieron ~13 funciones mid-función + 4 os funcs al syms (lookups 0x84… resueltos).
   PENDIENTE: run Windows del usuario → pegar boot.log/hh.log.
7. [BLOQUEANTE ACTUAL] Integrar modelo de threads libultra: los os funcs reimplementados (runtime)
   chocan con el libultra del juego compilado como C (globals `__osRunQueue`/`__osRunningThread` +
   `__osEnqueueThread` 0x800276CC) → crash en thread. DECISIÓN A/B pendiente (ver §12-A 4b):
   A) reimplementar TODAS las os de threads, o B) mantener globals del juego en runtime.
8. RSP audio ucode (aspMain) — follow-up tras boot.

## 16.7 LISTA DE TAREAS (copiar tal cual para recrear el TODO con el tool de todos)

> La siguiente sesión debe **recrear estas mismas tareas** con el sistema de todos, con el MISMO
> contenido y en este MISMO orden (los `[✓]`/`[•]`/`[ ]` delante indican el estado al cierre de esta
> tanda). Reconocer pegado-estado: `BLOCKER/boF` en la tarea activa.

```
[✓] Write port sources (main, renderer, overlays, support, input) + CMake + submodules + Linux validation + headless sanity
[✓] Restore Windows-build baseline: port on retail RecompiledFuncs (known-good, builds Hybrid Heaven Recomp.exe)
[✓] BLOCKER: finish unified funcs generation so it emits VALID C (clean regen, exit=0, complete set)
[✓] Regenerate unified set cleanly (game_unified.toml), gcc -fsyntax-only all funcs_*.c, exit=0, complete file set (funcs_0..6, 341 funcs)
[✓] Copy unified set to port/RecompiledFuncs + CMakeLists GLOB funcs_*.c + Linux compile check
[✓] Run headless Linux -> boot reaches Entrypoint returned + game threads start
[✓] BLOCKER: scheduler del motor Konami (deadlock) — CAUSA RAÍZ: osCreateViManager_recomp stub no-op (vi.cpp:13) dejaba los globals VI del juego (0x8004aed0/0x8004aed4) a 0. FIX B: el juego usa su propio osCreateViManager/osViSetMode (renombrados FUN_80032220/FUN_80032360 en us_unified.syms.toml) + osVirtualToPhysical (0x80028A10). DEADLOCK ROTO (thread 5 corre bucle, VI manager reenvía vblank, frames avanzan). Detalle: notes/2026-09-10-scheduler-diagnosis.md
[✓] Crash 'terminate called without an active exception' (mid-run) — endurecer ciclo de vida de threads (CleanupGuard + catch(...) + guard doble-enqueue + joinable-guard); juego estable 30s+
[✓] Build Windows: port compila (MSVC 2026) y hace BOOT (Entrypoint returned, threads, RT64 OK). Fixes de portabilidad MSVC: recomp.h cop0 (cause_reg/cop0_regs/declaraciones), mesgqueue __builtin_return_address, osStopThread assert. Pantalla NEGRA = aún no renderiza. Detalle: notes/2026-09-10-windows-build.md
[✓] CAUSA RAÍZ RENDER (2026-09-10, n64sym): la syms solo mapeaba 11 os funcs; la mayoría estaban como FUN_xxx → recompilados como código de juego → el juego usaba su propio osSetTimer (cop0 Compare no emulado) → thread 5 colgado en osRecvMesg(0x8005be40). FIX: mapear 46 os funcs (vrams n64sym) + use_lookup_for_all_function_calls=false → THREAD 5 DESBLOQUEADO (0 be40), 0 funciones faltantes. Detalle: notes/2026-09-10-n64sym-osfuncs-rootcause.md §8
[✓] SOLUCIÓN DE FONDO (2026-09-10, Ghidra): Ghidra exporta 1095 funciones → config/us_ghidra.syms.toml (867 funcs rango .text, 94 os funcs n64sym); config usa use_lookup=true (límites de Ghidra); ignored list con blobs de datos (FUN_800493c4/FUN_80049430/FUN_80049538/FUN_800495ec). Regeneración limpia (864 funcs, sin errores duros). Splat NO instalable (tables/HDF5 falla Py3.14/Alpine). Detalle: notes/2026-09-10-ghidra-syms-solucion-fondo.md
[✓] GAME LOOP CORRE (2026-09-10): Ghidra había dividido el game loop (FUN_800011b0+FUN_8000121c+FUN_80001254) rompiendo el control de flujo (beq→LOOKUP_FUNC+return; r2!=0 cae al final → thread 5 RETORNABA). FIX: fusionar en una (size 0x2A4) → thread 5 ya no exitea, corre su bucle (8 trazas MQ). Referencia: sp00nznet/racer (fix_fallthroughs.py, fix_statics, RSP routing, loadUCodeGBI, thread scheduling). fix_fallthroughs.py adaptado (6 funcs encadenadas). Detalle: notes/2026-09-10-ghidra-syms-solucion-fondo.md §7
[•] BLOQUEANTE: RENDER (pantalla negra). El game loop corre pero el boot CRASHEA en el allocator de heap FUN_80003824 — CRASH NO-DETERMINISTA (en gdb camina el heap válidamente, s2=0x80089524+0x10; en runs rápidos s2 se corrompe, offset 0x8000000f>RDRAM) → RACE / heap no inicializado a tiempo. Corregido FUN_80003D3C (0x74), FUN_80003db4 (0x88). Fix scheduling (ceder a prioridad igual, swap_to_thread) NO resolvió el race. 0 tareas RSP aún. Detalle: notes/2026-09-10-ghidra-syms-solucion-fondo.md §7.5
[ ] FIX RENDER: investigar el RACE del allocator (¿heap se inicializa tarde? ¿serialización de threads del runtime? — ver swap_to_thread/resume_thread_and_wait en threads.cpp). Luego wiring del sistema de eventos (osSetEventMesg con IDs estándar→ultramodern) y RSP task routing + loadUCodeGBI para que aparezcan las tareas de display (submit_rsp_task/send_dl) y el render. Recordar: añadir declaración osYieldThread_recomp a funcs.h tras cada regeneración (quirk); ejecutar tools/analysis/fix_fallthroughs.py tras cada regeneración.
[ ] RSP audio ucode (aspMain) - follow-up DESPUÉS de conseguir render
```

**Mapa estado → status del tool de todos**: `[✓]` → `completed`; `[•]` → `in_progress` (la única en
progreso); `[ ]` → `pending`. Prioridades: las 8 primeras `high`, la tarea 9 (render, bloqueante)
`high`, tarea 10 (audio) `low`. **Aclaración de orden:** el renderizado (tarea 9) va ANTES que el
audio RSP (tarea 10).