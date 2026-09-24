# Hybrid Heaven Recomp — Build para Windows

Guía para compilar el port en Windows (MSVC / Visual Studio). La recompilación de funciones se hace
en el entorno Linux; en Windows solo se compila y se prueba (`boot.log` / `hh.log`).

## Requisitos previos

- **Visual Studio 2022 o 2026** con el componente **Desktop development with C++** (MSVC + CMake).
- **Git** (para clonar/actualizar).
- La ROM retail: **`baserom.us.z64`** (Hybrid Heaven USA, 16 MB, hash `0x0F6A72F2C36A216DULL`).
  El `.exe` la busca al arrancar en la carpeta `rom\` junto al `.exe` (`rom\baserom.us.z64`); como
  salvaguarda también acepta `baserom.us.z64` junto al `.exe`. **Compilar no necesita la ROM.**

## Estructura (port en la raíz del repo)

```
./
├── CMakeLists.txt              ← raíz (GLOB build/recomp/RecompiledFuncs, SDL2 win32, icono, DLLs)
├── build/recomp/RecompiledFuncs/  ← C recompilado (generado; NO versionado, ADR 0009)
├── build/recomp/rsp/hh_aspMain.cpp ← ucode de audio recompilado (generado; NO versionado)
├── assets/                     ← HybridHeaven.ico, app.rc.in, HybridHeaven.png, icon_bmp.inc
├── src/platform/*              ← harness (main, support, rt64_render_context, icon, spin_yield)
├── src/hooks/sections.cpp      ← capa de hooks (loaders + registro por dirección)
├── src/subsystems/*            ← input.cpp, trans_cache.cpp, firmware.c
├── lib/rt64/                   ← repo rt64 (upstream, commit fijo, sin cambios)
└── lib/N64ModernRuntime/       ← runtime del FORK propio (rama hybrid-heaven, commit fijado)
```

> **IMPORTANTE:** `lib/rt64` y `lib/N64ModernRuntime` son **submódulos git** (`.gitmodules`,
> ADR 0010): `git clone --recursive` (o `git submodule update --init --recursive`) los trae. `rt64`
> es upstream en el commit `43373749dac9bbc1b653e6a02aed40a9e1783bed`; el runtime es
> **`hunkstalker/N64ModernRuntime`** (rama `hybrid-heaven`) con submódulos recursivos (`N64Recomp`
> sale del fork `hunkstalker/N64Recomp`; `thirdparty`, de upstream). `runtime.lock` queda como
> referencia/fallback. Créditos y licencias: `CREDITS.md`.

## 1. Runtime: forks propios (sin patch)

Los cambios de runtime (VI, threads, mesgqueue, registro dinámico de módulos, **Controller Pak
(PFS)**, `MEM_*` para direcciones no mapeadas, fix `s0`, instrumentación…) viven en el fork
`hunkstalker/N64ModernRuntime`, rama `hybrid-heaven` (con `main` = upstream, para el crédito y para
sincronizar). El cambio de `N64Recomp` que se **compila** dentro del port está en el fork
`hunkstalker/N64Recomp`. **No hay patch.**

Para cambiar el runtime (mantenedor): editar el árbol local (`lib\N64ModernRuntime` o la copia
`N64ModernRuntime` junto al proyecto) → commit en `hybrid-heaven` → `git push fork hybrid-heaven` →
**bump** del gitlink en el port (`git -C lib\N64ModernRuntime checkout <sha>` + `git add` en la raíz)
y, si aplica, actualizar `NMR_COMMIT` en `runtime.lock` (referencia/fallback).

Reparar/forzar el runtime a lo que fija el submódulo:

```bat
cd <raiz del repo>
git -c safe.directory=* submodule update --init --recursive
```
(o simplemente borra `lib\N64ModernRuntime` y vuelve a ejecutar `build_windows.bat`.)

## 2. Configurar y compilar

Recomendado: ejecutar `build_windows.bat`. Por defecto **omite git** si `lib\rt64` y
`lib\N64ModernRuntime` ya existen (evita cuelgues de git sobre unidades montadas) y compila en
**Release** (la build Debug sin optimizar hace que el juego caiga a 30 fps y que el hilo de audio
solo produzca la mitad de buffers -> petardeo). Usa `build_windows.bat --force-libs` si quieres
clonar/actualizar las libs, o `--debug` solo para diagnosticar crashes.

`build_windows.bat` imprime **siempre** la ruta y el commit del runtime que va a compilar (y si
omitió git). El submódulo fija un commit **publicado** en el fork (y `runtime.lock` como
fallback): si necesitas probar commits locales del runtime sin publicarlos, usa
**`build_windows.local.bat`**, que compila `lib\` tal cual (sin fetch/checkout) e imprime el
commit local que usa.

### 2a. Accesos directos por config (doble clic)

| Build | Compilar | Ejecutar |
|---|---|---|
| **Release** (GUI: 1 ventana, sin consola) | `build_windows_release.bat` | `run_windows_release.bat` |
| **Debug** (con consola) | `build_windows_debug.bat` | `run_windows_debug.bat` |
| **Release local** ¹ | `build_windows_release.local.bat` | `run_windows_release.bat` |
| **Debug local** ¹ | `build_windows_debug.local.bat` | `run_windows_debug.bat` |

¹ *Build local del mantenedor*: compila el árbol `lib\` tal cual (sin git, con commits sin
publicar). Los `.local` **no se versionan** (`.gitignore`) y son envoltorios de
`build_windows.local.bat`. **Ejecutar no tiene variante local**: el `.exe` sale en el mismo sitio
(`build\windows\bin\<config>`), así que `run_windows_release/debug.bat` sirve para ambas builds.

Todos son **envoltorios** de `build_windows[.local].bat [--debug]` / `run_windows.bat [release|debug]`
(no duplican lógica). **Consola:** en **Debug** el `.exe` es de subsistema consola (verás la
terminal); en **Release** es **GUI -> una sola ventana**, sin consola de fondo (por eso la build que
se distribuye es Release). `run_windows.bat` sin argumento usa Release si existe y, si no, Debug.

Manual:

```bat
cd <raiz del repo>
cmake -B build\windows -G "Visual Studio 18 2026" -A x64   REM o "Visual Studio 17 2022"
cmake --build build\windows --target HybridHeavenRecomp --config Release
```

- Exe: `build\windows\bin\Release\Hybrid Heaven Recomp.exe` (con `--debug`: `build\windows\bin\Debug\...`).
- El build copia automáticamente `SDL2.dll`, `dxcompiler.dll`, `dxil.dll` junto al `.exe`.
- ROM: al ejecutar, el `.exe` busca `rom\baserom.us.z64` (o `baserom.us.z64` junto al `.exe`).

### 2b. Build local del mantenedor (`build_windows.local.bat`, no versionado)

`build_windows.local.bat` está en `.gitignore` (es una comodidad local, no forma parte del
proyecto reproducible). Compila `lib\` **tal cual** está en disco (sin git), avisa si falta `lib\` e
imprime la ruta y el commit del runtime local. Atajos por config (también gitignored):
`build_windows_release.local.bat` y `build_windows_debug.local.bat`. Contenido de referencia para
recrearlo:

```bat
@echo off
setlocal enabledelayedexpansion
chcp 65001 >nul

set "BUILDCFG=Release"
if /i "%~1"=="--debug" set "BUILDCFG=Debug"

REM Detectar la raiz del repo (busca 'src\platform' hacia arriba)
set "ROOT="
for /f "usebackq delims=" %%d in (`powershell -NoProfile -Command "$cur='%~dp0'; while($cur -and -not (Test-Path (Join-Path $cur 'src\platform'))){$cur=Split-Path $cur -Parent}; if($cur){$cur}else{'NONE'}"`) do set "ROOT=%%d"
if "%ROOT%"=="NONE" ( echo ERROR: no encuentro 'src\platform' hacia arriba. & goto :err )
set "PORT=%ROOT%"
set "RT64=%PORT%\lib\rt64"
set "NMR=%PORT%\lib\N64ModernRuntime"

if not exist "%RT64%\CMakeLists.txt" ( echo ERROR: falta lib\rt64 ^(usa build_windows.bat --force-libs^). & goto :err )
if not exist "%NMR%\CMakeLists.txt" ( echo ERROR: falta lib\N64ModernRuntime ^(usa build_windows.bat --force-libs^). & goto :err )

set "NMR_SHA=desconocido (no es repo git)"
if exist "%NMR%\.git" for /f "usebackq delims=" %%s in (`git -c safe.directory=* -C "%NMR%" rev-parse --short HEAD 2^>nul`) do set "NMR_SHA=%%s"
echo Runtime: %NMR% @ %NMR_SHA%  (arbol local, sin git)

set "VSGEN="
cmake -G "Visual Studio 18 2026" --help >nul 2>&1 && set "VSGEN=Visual Studio 18 2026"
if not defined VSGEN cmake -G "Visual Studio 17 2022" --help >nul 2>&1 && set "VSGEN=Visual Studio 17 2022"
if not defined VSGEN ( echo ERROR: no encuentro VS 2026/2022 con C++. & goto :err )

pushd "%PORT%"
cmake -B build\windows -G "%VSGEN%" -A x64 || goto :err
cmake --build build\windows --target HybridHeavenRecomp --config %BUILDCFG% || goto :err
popd
echo Exe: %PORT%\build\windows\bin\%BUILDCFG%\Hybrid Heaven Recomp.exe
echo Runtime usado: %NMR% @ %NMR_SHA%
if not defined CI pause
goto :eof

:err
popd 2>nul
if not defined CI pause
exit /b 1
```

## 3. Ejecutar y capturar logs

- **`hh.log`** → `%APPDATA%\HybridHeavenRecomp\hh.log` (setup RT64, validación de ROM, overlays).
- **`boot.log`** → junto al `.exe` — arranque y cualquier `Failed to find function at 0x...`.
- Capturas: `PrtScr` o cualquier grabador; RT64 también admite `RT64_*` envs si hace falta.

## 3b. Grabar una partida (para reproducir el crash)

Doble clic a **`run_windows.bat`**: graba tu partida automáticamente en
`hybrid-heaven-recomp\tests\mi_partida.txt` (no hay que configurar nada; hoy va comentado en
`run_windows.bat`, descomenta la línea `HH_RECORD` si la quieres). Juega hasta que crashee y
envía ese `.txt`. El replay en el entorno de desarrollo es determinista (RMSE=0).

## 3c. Diagnóstico de audio (si suena a tirones)

El port escribe solo en su carpeta de trabajo (junto al .exe):

- **`hh_audio.log`** — una línea por segundo: `calls/s`, `frames/s`, cola pendiente, tasa del juego y
  del dispositivo. Lo correcto es ~60 calls/s y ~43.2k frames/s (720 frames por VI a 60 Hz).
- **`hh_rsp.log`** — duración media/máxima de la task de audio del RSP (debe ser < 16.7 ms).

Si el juego cae a 30 fps (habitación con mucha carga), el driver produce 720 frames por frame de
juego: a 30 fps solo son 21.6k frames/s y el dispositivo (43.2k) se queda sin datos. Ese es el motivo
de compilar en **Release**: con optimizaciones el juego mantiene 60 fps y el audio no se corta.

## 3c-2. Bats de diagnóstico (los que quedan)

- **`run_windows.bat`** — ejecución normal. Admite `noaudio` y/o `audlog`, y `release`/`debug` para
  elegir la build (sin argumento: Release si existe, si no Debug). Accesos directos:
  **`run_windows_release.bat`** / **`run_windows_debug.bat`**.
- **`run_pacing.bat`** — pasada de pacing: lanza el port y guarda los logs de la sesión en
  `logs_pacing_<fecha_hora>\` junto al `.exe`, e imprime las últimas líneas de `hh_state.log`.
  Modos: `run_pacing.bat trace` (traza frame/disp) y `run_pacing.bat gate` (~20-30 s con
  `HH_VERBOSE`+`HH_GATELOG` para `[GATE]`/`cd4c`). Protocolo:
  `notes/2026-09-17-logdiag-y-comparacion-linux-windows.md`.
- **`run_corrupt.bat`** — repro del cuelgue de combate **con grabación del gameplay**
  (`hh_replay_fight.txt`, determinista por VI) y volcado al freeze (`hh_hang.log` +
  `hh_hang_rdram_*.bin`). Empezar **partida nueva** y, al congelarse, **esperar ~20 s** antes de
  cerrar. La pasada anterior se aparta a `logs_prev_corrupt\`.
- **`run_replay.bat`** — reproduce un replay de input (`hh_replay_fight.txt` por defecto, o
  `run_replay.bat <fichero.txt> [diag]`) para validar que llega hasta el final/freeze. No graba y no
  toca el replay; aparta logs previos a `logs_prev_replay\`.
- **`run_mqlog.bat`** — traza de colas/eventos + `HH_S0FIX` + grabación de replay (`hh_mq_all.log`...).
- **`run_watch.bat`** — watchpoint (`HH_WATCH_ADDR`) + volcados `hh_ring`/`hh_ring2` + replay.

> **Logs de diagnóstico (2026-09-17)**: los logs always-on (`hh_sched`, `hh_pi`, `hh_mq`, `hh_cmds`,
> `hh_ovl`, `hh_rsp`) ahora requieren **`HH_DIAG=1`** (su I/O con `fflush` degradaba el pacing).
> Por defecto solo se escriben `hh_state.log` (`HH_STATE_SECS`), crash/hang y `hh_audio.log`.
> `run_pacing.bat` usa los defaults (sin `HH_DIAG`); los bats de diagnóstico lo activan.
> Otros ruidos opt-in (2026-09-17): `[PAD] contexto:` → **`HH_PADLOG=1`**; dump PCM
> `hh_audio_dump.bin` (4 MB) → **`HH_AUDIODUMP=<f>`** (ya no se escribe por defecto).
> `run_pacing.bat` aparta los logs previos a `logs_prev\` y recoge `boot.log` + dumps de hang/crash.

> Política: los bats **puntuales** (una regresión concreta) se eliminan tras usarse; solo se quedan
> los que sirven de forma recurrente (build, run, diagnóstico). Los que probaban configs antiguas
> (mapeo viejo, 48 kHz) se retiraron al resolverse el cuelgue del NPC.

## 3d. Si el port crashea (para depurar)

En el CWD (junto al `.exe`) se escriben solos, en cada crash:

- **`hh_crash.log`** — excepción, dirección, módulo+offset, registros y contador de VI.
- **`hh_crash_rdram.bin`** — los 8 MB de RDRAM en el momento del crash (estado exacto del juego).
- **`hh_crash_dmem.bin`** — 4 KB de DMEM del RSP.

Con eso puedo inspeccionar el estado del juego en el crash sin reproducirlo. Si el fallo fue por un
símbolo ausente, `hh_missing.log` (también junto al `.exe`) lista las `Failed to find function at 0x...`.

**Cuelgues (ventana congelada)**: si el juego deja de pedir input durante 15 s (`HH_HANG_SECS` para
cambiarlo), un watchdog escribe `hh_hang.log` (contexto MIPS de cada hilo: argumentos y SP = dónde
está bloqueado cada uno) y `hh_hang_rdram_<pid>_<n>.bin` (8 MB). Deja la ventana congelada ~20 s
antes de cerrarla para que dé tiempo al volcado.

## 4. Estado actual esperado (2026-09-14, tarde)

- **GAME START funciona**: al pulsar START → GAME START el juego carga los overlays de código
  (idx8/9/10/12/55) y entra en la primera escena jugable con HUD (`work/debug/port_v3_*.png`).
- **Resolución**: por defecto Auto (escalado entero a la ventana). Override `HH_RES=original|2x|<n>`
  (p. ej. `set HH_RES=2x`).
- **Mando Xbox** (mapeo FIJO, 2026-09-21): cada botón físico = un botón del N64, **sin remapeo por
  contexto** (antes B cambiaba de función con el mapa/menú abierto → variabilidad en la misma
  partida). Por defecto: **A = acción/confirmar**; **B = N64 B (atrás/mapa/cancelar)**;
  **X = N64 Z (agacharse)**; **Back = B** (alias de atrás); **Y = C-Down** (vista en 1ª persona,
  verificado); Start = START; LB = L; RB = apuntar (R); **stick derecho = botones C** (digital,
  umbral 0.5; no emite C-Down, que va en Y); cruceta = D-pad; stick izquierdo = analógico
  (`HH_INVERT_Y=1` lo invierte). La detección de contexto (`0x802690D0`/front-end) queda **inerte**
  (ambos perfiles son idénticos). Referencia/Goemon (`recompinput`) usan **B del N64 en X** y **Z en
  el gatillo izquierdo**; aquí se prefirió **B físico = atrás** y **Z en X**. Libres: L3 y R3.

### config.ini (mapeo configurable)

Junto al `.exe` (se crea solo en el primer arranque, editable con cualquier editor):

```ini
[game]            ; exploración/combate
b = B             ; B físico = atrás/mapa/cancelar
x = Z             ; X = agacharse
back = B          ; Back = alias de atrás/mapa
y = CDOWN         ; vista en 1ª persona (verificado)
cstick = on       ; stick derecho -> botones C
[menu]            ; idéntico a [game] (formato por compatibilidad)
b = B
x = Z
```

Valores válidos: `A B Z START L R CUP CDOWN CLEFT CRIGHT DUP DDOWN DLEFT DRIGHT NONE`. El port relee
`config.ini` en cada arranque (ruta alternativa: `HH_PAD_CONFIG=<fichero>`).

### Teclado (además del mando)

Mapeo fijo, espejo del mando (misma semántica N64):

| Tecla | Botón N64 | Físico equivalente |
|---|---|---|
| **W A S D** | **stick izquierdo** (movimiento) | stick izq. |
| **H** | Z (agacharse) | X |
| **J** | A (acción) | A |
| **K** | B (atrás/mapa) | B |
| **L** | **C-Down** (1ª persona) | Y |
| U / I | L / R | LB / RB |
| O / P | Z / R (alias) | LT / RT |
| Enter | Start | Start |
| flechas | D-pad | D-pad |

**Stick ↔ D-Pad (menús/UI)**: el **D-pad físico mueve el stick** (`HH_DPAD_TO_STICK`, por defecto
on; `=0` lo desactiva) → el D-pad navega menús que esperan el stick. Además, al empujar el stick
>0.5 se emite también la cruceta (`HH_STICK_TO_DPAD`, por defecto on; `=0` lo desactiva).

### [video] (gráficos)

Sección en `config.ini` (defaults: borderless, resolución nativa, aspecto auto, MSAA 8x):

```ini
[video]
wm     = borderless   ; borderless | windowed
res    = auto         ; auto (nativa) | original | 2x | <n> | 4k | 8k
aspect = auto         ; auto|original|expand|4:3|16:9|<float>
msaa   = 8x           ; off | 2x | 4x | 8x
vsync   = si          ; si | no
fps     = nativo      ; nativo (refresco del monitor) | 30 | 60 | 120 | 144 | 160
showfps = no          ; si | no (indicador de FPS, solo números, arriba-izquierda)
```

- **Ventana**: por defecto **borderless a la resolución nativa del monitor**; `wm=windowed` la abre en ventana.
- **VSYNC / LÍMITE DE FPS / MOSTRAR FPS**: `vsync` (por defecto `si`) y `fps` (`nativo` = refresco del
  monitor); `showfps` dibuja el indicador de FPS. El menú **GRÁFICOS/DEBUG** los aplica en vivo y
  **los persiste aquí** (junto con `wm`).
- **Atajos en caliente**: **F2** = cicla aspecto (widescreen/4:3); **F3** = borderless ↔ windowed;
  **F4** = cicla MSAA; **F11** = cierra la aplicación (cómodo a pantalla completa, sin Alt+F4) (consola:
  líneas `[VIDEO] ...`). **F1** = Inspector de RT64, solo con `HH_DEVELOPER=1`.
- **Resolución interna**: `auto` = alto del monitor / 240 (4K→9×, 8K→18×; `res=8k`/`4k`).
- **MSAA**: `hh.log` imprime `RT64: sampleLocations=`; si es 0, el dispositivo no soporta el MSAA de RT64.
- **Widescreen (por defecto)**: el juego dibuja la escena con un *scissor* 4:3; el port lo reescribe a
  full-frame (*snap* de overscan, adaptado de la referencia Phase 07; `HH_FULL_FRAME=0` lo desactiva).
  Con `aspect=auto`/`expand` (default) el 3D **llena la ventana**. El **radar/mapa** se **ancla al
  borde izquierdo** (`src/hooks/hud_rewrite.cpp`, GBI extendido `gEXSetRectAlign`/`gEXSetViewportAlign`;
  `HH_NO_HUD_REWRITE=1` lo desactiva para A/B). Barras POWER/STAMINA/HP y diálogos quedan en la zona
  4:3 (sin clasificar) pero **no se desmontan**. `aspect=original` = 4:3.
  - Dev: `HH_HUD_TRACE=1` lista una vez las identidades 2D (`tex:`/`dl:`/`fill:`) con su extensión
    (re-derivar la tabla fija); `HH_HUD_REWRITE_TRACE=1` traza lo que ve el reescritor.

- **Si vuelve a crashear** (abort/assert): junto al `.exe` se escribe **`hh_missing.log`** con las
  direcciones `Failed to find function at 0x...`; pásalas y se añaden.
- Env útiles: `HH_RES=original|2x|<n>` (resolución), `HH_INVERT_Y=1` (eje), `HH_INPUTLOG`/`HH_PRESS*`
  y `HH_STICK=x,y` (input sintético para pruebas). `HH_FPS=1`: registra en `hh.log` la tasa real de
  present (`[hh-fps] N fps | M display lists`) una vez por segundo. **High frame rate (default ON)**:
  presenta al refresco del monitor; `HH_REFRESH_RATE=original|display|manual:<hz>` y `HH_PRESENT_EARLY=0`
  lo ajustan/revienen (ver `notes/2026-09-22-fps-y-present-early.md`). API gráfica:
  `HH_GRAPHICS_API=d3d12|vulkan|metal|auto` (útil para probar overlays tipo RTSS o fallos por API).
  FPS en pantalla: `HH_DEVELOPER=1` habilita el Inspector de RT64 (abrir/cerrar con **F1**; ojo: con
  dev-mode RT64 consume F1-F4 y el F2/F3/F4 del port deja de actuar).

### Grabar y reproducir una partida (depuración determinista)

```bat
REM 1) Grabar tu partida (botones+stick) hasta justo antes del crash.
REM    Ruta absoluta = fiable; una relativa cae en el CWD (con run_windows.bat, en build\windows\bin\Release).
set HH_RECORD=mi_partida.txt
Hybrid Heaven Recomp.exe

REM 2) Reproducirla después (sin mando): el port mete exactamente el input grabado
set HH_RECORD=
set HH_REPLAY=mi_partida.txt
Hybrid Heaven Recomp.exe
```

El replay es **por índice de poll** (una muestra por frame), así que reproduce la sesión píxel a píxel
(verificado RMSE=0). Envía el `.txt` grabado y se puede reproducir el fallo en el entorno Linux.

## 4b. Estado anterior (2026-09-10)

- Boot completo, transición y burst de módulos; **renderiza** logo, pantalla de título, menú y
  **cutscenes 3D in-engine**.
- **Menú**: `START` → menú principal → `START` → GAME START/DIFFICULTY/EXIT → `A` entra en la intro
  (exige **Controller Pak**, ya emulado con PFS en RAM + `saves\*.bin.pak` **junto al .exe**; si esa
  carpeta no es escribible se usa `%APPDATA%\HybridHeavenRecomp`; `HH_DATA_DIR=<ruta>` lo fuerza).
- **Mando Xbox compatible** (SDL2 GameController):
  - `A`=A, `B`=B (y C-derecha), `X`=C-izq, `Y`=C-arriba, `LB`=L, `RB`=R, `Back`=Z, `Start`=Start,
    D-Pad, stick izquierdo (botón = C-abajo) y eje analógico.
  - Hot-plug soportado (`SDL_CONTROLLERDEVICEADDED/REMOVED`).
  - Rumble no implementado (no-op).
- Si sale `Failed to find function at 0xXXXX`: revisar las fronteras/nombres del pipeline ELF/splat
  (en `recomp/`) y regenerar con `python3 tools/regenerate.py`.

## 4c. Audio

El port inicializa el subsistema de audio de SDL (y `hh::init_audio()` corre antes de
`reset_audio()`). En Windows debe salir en consola
`SDL Audio Driver: wasapi` (o `directsound`) y oirse. Si no hay dispositivo, avisa y sigue sin sonido
(cola virtual). Para forzar driver: `set SDL_AUDIODRIVER=directsound` (o `wasapi`).
Nota: `queue_samples` recibe `sample_count` en muestras int16; el byte_len se calcula como
`sample_count * sizeof(int16_t)` (antes usaba bytes por frame y corrompia el heap al abrir dispositivo).

## 5. Problemas conocidos

- Frontera actual: cola del módulo 25 (`0x801FF260`, fuera del blob/syms actuales) y confirmación de
  gameplay interactivo (control/HUD).
- En Linux headless el input se prueba también con los envs `HH_PRESS*` (útil para automatizar).
