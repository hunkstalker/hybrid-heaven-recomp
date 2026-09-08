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

## 1. Cómo está el entorno AHORA (estado transaccional 2026-09-08 ~02:10)

- **Emulador**: la sesión `sess02` (pid 11593, 1200s) **ya terminó** (exit 0, duró 20 min). Ahora
  NO hay emulador vivo. Relanzar cuando se vaya a trabajar (ver §4).
- **LO NUEVO desde la última parada**:
  - `fbdecode.py v2`: arreglado el **bug de stride** (16bpp = 2 B/pixel, no 4) que producía
    "ruido/artefactos" en los PNG que vio el usuario.
  - Región **VIVA** encontrada: scan de diferencias t1-vs-t9 → bloques que cambian en RDRAM.
    Mejor candidata de framebuffer FMV/backdrop: **0x1C0000** (640x480×16bpp: 5781 col, mean=25,
    AE(t1,t9)=21301 → LIVE; ASCII muestra bandas + puntos dispersos = película/backdrop oscuro).
  - **rice (video-rice v2.6.0) YA NO CRASHEA** con `SDL_AUDIODRIVER=dummy` (antes moría exit 136;
    era el mismo FPE de audio, NO del plugin). Su ventana **presenta contenido a X**:
    crop 320x240→2861 col, AE=10072 entre dos capturas a 3s (≠ glide, negro estático). ASCII de
    la ventana muestra un **emblema centrado con líneas/reglas** ⇒ frame real. VIAs prometedora.
  - **write-bp capturó un registro REAL en vivo** al final de sess02 (`sess02.dir.bin`, 01:56):
    id 0x012D → base 0x80235078, y un slot 0x0074 **congelado a mitad de escritura** (base=0),
    lo que demuestra la captura mecánica del instante `dir_set_id`/`dir_set_base`.
- Dumps de RDRAM (8 MB) y logs de la sesión: `work/scratch/sess02.*`.
- Últimos commits (branch main, git local): ver §11.

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

## 12. Tareas pendientes (priorizado)

1. **Confirmar con el usuario** qué se ve en `session02/viva_t9_640x480.png` (¿ciudad de noche?
   ¿logo con reglas? ¿artefacto?) y en el ASCII del crop de rice — cierra cuál es la vía visual
   definitiva (rice-xshot vs fbdecode-RDRAM).
2. **Explotar rice**: relanzar run con rice + dummy audio, capturar xshot del crop en loop
   (`cap_loop.sh`), verificar que NO es residuo (2 disparos a 3s → AE alto), y mandar PNG reales
   por sesión al usuario (tele-op).
3. **Progresar gameplay**: con visibilidad real, el usuario guía (Start interrumpe intro → menú →
   opciones); el write-bp va registrando cada trans en `dir.bin` en vivo. Recolectar el mapa
   overlay→RAM del flujo completo.
4. **Reconciliar ids**: por qué en attract el set es 0xDE/0x91 y en sess02 0x75/0x7C/0x12D (¿depende
   del orden de carga? ¿misma tabla 0x18B en 0x8DCA8? revisar dumps del directorio en cada t).
5. **Extra: audio** (opcional/más adelante): el audio dummy silencia; no bloquea la tarea #3.
6. ¿Seguir con el emulador o pivotar a N64Recomp? Combentries: la instrumentación definitiva será
   sobre el código recompilado; el emulador sirve para obtener el mapa (tarea #3).

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