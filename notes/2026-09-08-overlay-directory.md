# Overlay resource directory (trans loader) — ground truth + debugger plumbing

Date: 2026-09-08. ROM: `work/roms/us_dec.z64` (z64, plana; código RAM = offset_rom + 0x80000000).

## 0. Byte-order rule (RESUELTO)

Los dumps RDRAM de `r64dump` empiezan **word-swapped**: el fragmento de 4 bytes `48 A9 1F 80`
corresponde al valor big-endian `0x801FA948`. **Siempre aplicar `bswap32` a cada palabra del dump**
para obtener el valor que lee `lw` la CPU. Verificado contra bases conocidas del attract:

| raw dump word        | bswap32 (valor CPU) |
|----------------------|---------------------|
| 0x48A91F80           | 0x801FA948          |
| 0xC8B52080           | 0x8020B5C8          |
| 0x38B92080           | 0x8020B938          |
| 0xF8172180           | 0x802117F8          |

## 1. Directorio de recursos

- RDRAM física **0x8DFC0** (vista CPU 0x8008DFC0), 0x100 entradas de **8 B**.
- Layout por entrada: `+0` = **id16** (halfword alto de la palabra BE = bytes 0-1), `+4` = **base32** (palabra completa).
  - `dir_set_id`: `sh a1,-0x2040($at)`  @0x80017F84  (id 16-bit)
  - `dir_set_base`: `sw a1,-0x203C($at)` @0x80017FB8  (base 32-bit)
  - `dir_get_id`: `lhu -0x2040`  @0x80017C14
  - `dir_get_base`: `lw -0x203C`  @0x80017C3C
- Sin llamadores directos (jal/j) de estas 4 funciones en toda la zona de código ⇒ acceso vía
  **tablas de punteros (jalr)**. El dispatcher interno de Konami no permite rastreo estático directo.
- Accesorios de slots "trans": tabla slot 0x18B en **0x8DCA8**; contador/índice actual **0x8FDA8**;
  counts en **0x8DC94/0x8DC98**; bitmap busy base en **0x8DFAC** y **0x8DFB4** (funcs 0x80017064/0x800170C8/0x80016b40...).

## 2. Asignación de bases (modelo observado)

Bases **únicas, crecientes = base_prev + size**: en attract `0x801FA948 → +0x10C80 → 0x8020B5C8 →
+0x3770 → 0x8020B938 → +0x5EC0 → 0x802117F8`. El asignador acumula; no encontrado estáticamente
(dispatcher indirecto).

## 3. Estado del directorio en runtime (attract, sin input, boots 22s)

| t (s) | entries |
|-------|---------|
| 2-6   | 1 (slot0 id16=0xFFFE, base=0x803837E0) — transitorio de boot |
| ≥8    | 4: ids 0x0018/0x0073/0x00DE/0x0091 → bases 0x801FA948/0x8020B5C8/0x8020B938/0x802117F8 |

Atract NO registra más overlays al avanzar (loop cerrado). El mapa completo requiere pasar de
titular→menús→gameplay (necesita input + visibilidad de video, ambos pendientes).

## 4. Debugger del core — diagnóstico ROOT CAUSE del write-bp

- `EnableDebugger`=true (config Core) activa `init_debugger()` (main.c:~1961) solo si la variable
  DBG compilada; `init_debugger` deja runstate PAUSED → el R4300 se bloquea en
  `SDL_SemWait(sem_pending_steps)` dentro de `update_debugger`. Retomar = `DebugSetRunState(RUNNING)`
  **+ `DebugStep()`** (posts el semáforo).
- **`ADD_STRUCT` write-bp antes del thread NO dispara**: `main_run()` (hilo EXEC) llama
  `init_device()` (main.c:1899) que re-ejecuta `init_memory()` → `memset(bp_checks)=0` DESPUÉS de
  nuestro ADD. El bpx queda en la lista (`numbp=1`) pero su gate `bp_checks[region]` se borra
  (`chk8=0x00` en `update_debugger` activado). Confirmado con print en dbg_debugger.c.
- **Solución**: añadir el write-bp DESPUÉS del resume del boot-halt (mem inicializada, máquina
  pausada). Verificado: con `HB_RES_DIR=0x8008DFC0` (rango 1KB) los hits reales disparan
  `DebugBreakpointTriggeredBy → flags&WRITE`.
- El bucle de **zerofill del directorio** (boot) produce aludes de hits; salto: en el primer hit
  del clear (pc 0x80000414/0x80000418) → `DISABLE(g_bp_idx)` + resume + re-armado `el+2.0`.
- **El zerofill tarda ~6-8s reales** (256 writes a 4B, densidad): armado del wp a 8.0s
  (`HH_WP_ARM`, default) con wp añadido DISABLED evita el churn. Verificado: sin haltes espurios,
  máquina libre, dir final con las 4 entradas.
- **Registro vivo del registrador**: con el wp activo se capturan `loader pc=0x800173AC`
  (escribe campo id) y `pc=0x800173D8` (escribe campo base) en 0x8DFC0+4k — es el wrapper
  setter/freelist 0x80017330-0x800173F8 (bitmap 0x8008DFAC/0x8008DFB4). Confirmación runtime del
  dispatcher indirecto.
- Los hits reales se distinguen con `DebugBreakpointTriggeredBy()`: solo `flags&WRITE`.
- El break del dump periódico (pause→ui_update) produce `valid=no`; no es un registro.

## 5. Harness (`tools/analysis/r64dump.cpp`)

- `HB_RES_DIR` = dir virtual; convierte a físico (`DebugVirtualToPhysical`), bpx sobre
  `paddr..paddr+0x3FF` (todo el directorio), añadido post-resume, añadido DISABLED y armado a
  `HH_WP_ARM` (default 8.0s) para saltar el zerofill tardío.
- `HH_DUMP_TIMES="2,4,..."` dumps RDRAM a `%s.t%d.bin` (recuerda bswap32).
- Por cada hit real: log pc/regs (`M64P_CPU_PC/M64P_CPU_REG_REG`), snapshot de 1KB del directorio
  a `%s.dir.bin`, y continua (deja el bpx armado) → permite capturar registraciones progresivas.
  `dir.bin` se sobrescribe en cada hit; para estado asentado usar los dumps `.tN` o el dump final.
- `g_bp_idx` (retorno de ADD_STRUCT) para ENABLE/DISABLE del bpx (CHECK exige flag EXEC; no sirve
  para wp).

## 6. Entrega al usuario (`work/play.sh`)

- Core limpio CON debugger: `work/libmupen64plus-debug.so` (sin prints ruidosos; solo `[dbgcore]
  BP HIT` en breaks).
- `work/play.sh [segundos] [prefijo]`: ventana GLX + input-sdl (teclado; DPad=WASD, Start=Enter,
  C=IJKL, R=c, L=x, Z=z; A/B en `/root/.config/mupen64plus/mupen64plus.cfg->[Input-SDL-Control1]`),
  `HB_RES_DIR=0x8008DFC0`, dumps a 5/10/20/40/80s. Log en `<prefijo>.session.log`.
- El usuario juega/avanza por menús; cada registro de overlay nuevo → `[dbg] stop ... valid=YES`
  con `loader pc` + actualización de `<prefijo>.dir.bin`. Enviar logs+dumps para derivar el mapa.

## 7b. CAPTURA DE VIDEO HEADLESS — RESUELTO (tele-op)

- Puerto: el harness capturaba con su propio vidext GLX (`vxg_*` → PPMs) pero **glide64mk2 usa su
  propio SDL window y nunca llama el vidext override** (0 líneas `[vid]` en el log; sí spamea
  `UpdateScreen`). Por eso `frames/` quedó vacío.
- Solución: captura **a nivel de X** de la raíz del Xvfb con un helper Xlib
  (`tools/analysis/xshot.c`, `XGetImage` + PPM; compilado `tools/analysis/xshot`).
- Verificación (Xvfb vivo único: **`:99`** 640x480x24 con GLX; el :7 del test murió): 3 captures
  `s1/s2/s3.ppm` con 3k–26k colores y mean/σ > 0 ⇒ **contenido real** (titular/attract), frames
  cambiantes ⇒ video OK. Frames en `/tmp/opencode/shot/`, muestra en `/app/work/frames/attract_01.ppm`.
- Nivel de confianza revisado el 08-09 01:50: la captura **X a nivel de root** de glide es **NO
  fiable**: glide64mk2 crea ventana (320x240) pero **NO presenta nunca** a X (venía de los
  `UpdateScreen` "Origin:"); los "frames" vistos antes eran contenido residual del root.
  La vía visual fiable = **decodificar el framebuffer 16bpp desde los dumps RDRAM**
  (`tools/analysis/fbdecode.py`): región 0x000500 parece el frame/backdrop del attract
  (16bpp 320x240; 9068 colores; estático en dumps t1..t9 ⇒ preg. prerendered); @0x080000
  32bpp 640x480 otro asset estático (53k col). Se salvan como PNG por sesión en
  `work/screenshots/sessionNN/` (el usuario los ve desde su lado; adjuntos de imagen NO
  aparecen en su chat).
- La previa del frame para el humano se hace con `tools/analysis/ppmascii.py` (88x~40 luminancia)
  porque **el modelo no puede ver imágenes**.
- Flujo tele-op: lanzar emulador (glide) en :99 → telemando input; directorio capturado por el
  write-bp; frames decodificados de RDRAM por sesión. Nota: `pkill -f` NO usar (mata la propia
  shell); usar `pkill -x r64dump` o el pid.

## 7c. FIX FPE (SIGFPE 136 a ~6s) — SDL_AUDIODRIVER=dummy (commit 78b8d1f)

- Síntoma: tras recrear el Xvfb, el emulador moría con exit=136 (~6s) con glide64mk2; rice también.
  Causa real: **el plugin audio-sdl falla** ("Failed to initialize SDL audio subsystem") y ese fallo
  acaba en división por cero en el path de audio.
- Fix: `SDL_AUDIODRIVER=dummy` → `Initializing SDL audio subsystem...` OK y **emulador estable**
  (verificado: con audio→136; sin audio→0; dummy+audio→0, 60s+). Receta en `work/play.sh`.
- Confirmado operativo sesión `sess02` (pid 11593, 1200s): write-bp 3329 stops; `dir.bin` con 4
  entradas: id 0x0018 base 0x801FA948; 0x0073→0x8020B5C8; 0x0075→0x8020B938; 0x007C→0x80225468.
  NOTA: ids/bases difieren del attract previo (0xDE/0x91) → el set depende del recorrido; revisar.
- Persistencia de seguridad: `/app/.backup/hh-wip-<ts>.tgz` (mupen-src parcheado + .so + tools +
  notes; sin ROM ni dumps).

## 7. Pendiente para #3 (mapa overlay→RAM completo)

1. Visibilidad de video o input guiado para pasar de attract a jugo (los trans de juego se cargan
   por menú/fase).
2. Con el harness armado, capturar registraciones reales; volcar dir en cada hit.
3. Alternativa estática: la tabla slot 0x8DCA8 + el "init trans" 0x80018420 (copia de plantilla
   ROM 0x8004413C → 0x8008EBD4) y 0x800185B0 (bucle de 7 cards llamando 0x8001A804) siguen en
   análisis marginal.