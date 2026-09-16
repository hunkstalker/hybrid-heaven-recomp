# Hybrid Heaven Recomp — Build para Windows

Guía para compilar el port en Windows (MSVC / Visual Studio). La recompilación de funciones se hace
en el entorno Linux; en Windows solo se compila y se prueba (`boot.log` / `hh.log`).

## Requisitos previos

- **Visual Studio 2022 o 2026** con el componente **Desktop development with C++** (MSVC + CMake).
- **Git** (para clonar/actualizar).
- La ROM retail: **`baserom.us.z64`** (Hybrid Heaven USA, 16 MB, hash `0x0F6A72F2C36A216DULL`).
  El `.exe` la busca al arrancar en la carpeta `rom\` junto al `.exe` (`rom\baserom.us.z64`); como
  salvaguarda también acepta `baserom.us.z64` junto al `.exe`. **Compilar no necesita la ROM.**

## Estructura que debe existir en `port/HybridHeavenRecomp/`

```
port/HybridHeavenRecomp/
├── CMakeLists.txt          ← ya preparado (GLOB funcs_*.c, rsp/hh_aspMain.cpp, SDL2 win32, icono, DLLs)
├── RecompiledFuncs/        ← SET UNIFICADO ACTUAL (funcs_0..N + funcs.h + recomp_overlays.inl + lookup.cpp)
├── rsp/hh_aspMain.cpp      ← ucode de audio recompilado
├── assets/                 ← HybridHeaven.ico, app.rc.in, HybridHeaven.png, icon_bmp.inc
├── src/main/*.cpp          ← port (main, support, rt64_render_context, register_overlays, module_sources.inc)
├── lib/rt64/               ← repo rt64 (upstream, commit fijo, sin cambios)
└── lib/N64ModernRuntime/   ← runtime del FORK propio (rama hybrid-heaven, commit fijado)
```

> **IMPORTANTE:** los dos `lib/` están en `.gitignore` y los reproduce `build_windows.bat`:
> `rt64` se clona de upstream en el commit `43373749dac9bbc1b653e6a02aed40a9e1783bed`; el runtime se
> clona de **`hunkstalker/N64ModernRuntime`** (rama `hybrid-heaven`) en el commit que fija
> **`port\runtime.lock`**, con submódulos recursivos (`N64Recomp` sale del fork
> `hunkstalker/N64Recomp`; `thirdparty`, de upstream). Si los directorios ya existen, se respetan.
> Créditos y licencias: `CREDITS.md`.

## 1. Runtime: forks propios (sin patch)

Los cambios de runtime (VI, threads, mesgqueue, registro dinámico de módulos, **Controller Pak
(PFS)**, `MEM_*` para direcciones no mapeadas, fix `s0`, instrumentación…) viven en el fork
`hunkstalker/N64ModernRuntime`, rama `hybrid-heaven` (con `main` = upstream, para el crédito y para
sincronizar). El cambio de `N64Recomp` que se **compila** dentro del port está en el fork
`hunkstalker/N64Recomp`. **No hay patch.**

Para cambiar el runtime (mantenedor): editar el árbol local (`lib\N64ModernRuntime` o la copia
`N64ModernRuntime` junto al proyecto) → commit en `hybrid-heaven` → `git push fork hybrid-heaven` →
actualizar `NMR_COMMIT` en `port\runtime.lock`.

Reparar/forzar el runtime a lo que dice el lock:

```bat
cd port\HybridHeavenRecomp\lib\N64ModernRuntime
git -c safe.directory=* fetch
git -c safe.directory=* checkout <NMR_COMMIT de port\runtime.lock>
git -c safe.directory=* submodule update --init --recursive
```
(o simplemente borra `lib\N64ModernRuntime` y vuelve a ejecutar `build_windows.bat`.)

## 2. Configurar y compilar

Recomendado: ejecutar `port\build_windows.bat`. Por defecto **omite git** si `lib\rt64` y
`lib\N64ModernRuntime` ya existen (evita cuelgues de git sobre unidades montadas) y compila en
**Release** (la build Debug sin optimizar hace que el juego caiga a 30 fps y que el hilo de audio
solo produzca la mitad de buffers -> petardeo). Usa `build_windows.bat --force-libs` si quieres
clonar/actualizar las libs, o `--debug` solo para diagnosticar crashes.

`build_windows.bat` imprime **siempre** la ruta y el commit del runtime que va a compilar (y si
omitió git). El pin de `port\runtime.lock` solo apunta a commits **publicados** en el fork: si
necesitas probar commits locales del runtime sin publicarlos, usa **`port\build_windows.local.bat`**,
que compila `lib\` tal cual (sin fetch/checkout) e imprime el commit local que usa.

Manual:

```bat
cd port\HybridHeavenRecomp
cmake -B build_win -G "Visual Studio 18 2026" -A x64   REM o "Visual Studio 17 2022"
cmake --build build_win --target HybridHeavenRecomp --config Release
```

- Exe: `build_win\bin\Release\Hybrid Heaven Recomp.exe` (con `--debug`: `build_win\bin\Debug\...`).
- El build copia automáticamente `SDL2.dll`, `dxcompiler.dll`, `dxil.dll` junto al `.exe`.
- ROM: al ejecutar, el `.exe` busca `rom\baserom.us.z64` (o `baserom.us.z64` junto al `.exe`).

### 2b. Build local del mantenedor (`build_windows.local.bat`, no versionado)

`port\build_windows.local.bat` está en `.gitignore` (es una comodidad local, no forma parte del
proyecto reproducible). Compila `lib\` **tal cual** está en disco (sin git), avisa si falta `lib\` e
imprime la ruta y el commit del runtime local. Contenido de referencia para recrearlo:

```bat
@echo off
setlocal enabledelayedexpansion
chcp 65001 >nul

set "BUILDCFG=Release"
if /i "%~1"=="--debug" set "BUILDCFG=Debug"

REM Detectar la raiz del repo (busca 'port\HybridHeavenRecomp' hacia arriba)
set "ROOT="
for /f "usebackq delims=" %%d in (`powershell -NoProfile -Command "$cur='%~dp0'; while($cur -and -not (Test-Path (Join-Path $cur 'port\HybridHeavenRecomp'))){$cur=Split-Path $cur -Parent}; if($cur){$cur}else{'NONE'}"`) do set "ROOT=%%d"
if "%ROOT%"=="NONE" ( echo ERROR: no encuentro 'port\HybridHeavenRecomp' hacia arriba. & goto :err )
set "PORT=%ROOT%\port\HybridHeavenRecomp"
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
cmake -B build_win -G "%VSGEN%" -A x64 || goto :err
cmake --build build_win --target HybridHeavenRecomp --config %BUILDCFG% || goto :err
popd
echo Exe: %PORT%\build_win\bin\%BUILDCFG%\Hybrid Heaven Recomp.exe
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

Doble clic a **`port\run_windows.bat`**: graba tu partida automáticamente en
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

- **`run_windows.bat`** — ejecución normal. Admite `noaudio` y/o `audlog` como argumentos.
- **`run_mqlog.bat`** — traza de colas/eventos + `HH_S0FIX` + grabación de replay (`hh_mq_all.log`...).
- **`run_watch.bat`** — watchpoint (`HH_WATCH_ADDR`) + volcados `hh_ring`/`hh_ring2` + replay.

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
- **Mando Xbox** (perfiles por contexto, 2026-09-15): en juego A = salto/acción; **B = agacharse**
  (Z); **Back/Select = mapa** (B); **X = libre por ahora** (el B contextual abría también el mapa; cuando
  identifiquemos el botón del menú de combate se asigna en `config.ini`); **Y = C-Down** (vista en 1ª
  persona, verificado con capturas); Start = START; LB = L; RB = apuntar (R); **stick derecho = botones C**
  (digital, umbral 0.5; no emite C-Down, que va en Y); cruceta = D-pad; stick izquierdo = analógico (eje Y por defecto correcto; `HH_INVERT_Y=1` lo invierte). En
  **menús** (pausa/mapa) el B físico pasa a ser **B del N64 (atrás/cancelar)** automáticamente.
  Libres: L3 y R3. El port imprime `[PAD]` al arrancar y `[PAD] contexto:` al entrar/salir de menús.

### config.ini (mapeo configurable)

Junto al `.exe` (se crea solo en el primer arranque, editable con cualquier editor):

```ini
[game]            ; exploración/combate
b = Z             ; B físico = agacharse
back = B          ; Select = mapa
x = NONE          ; X libre (pendiente botón real del menú de combate)
y = CDOWN         ; vista en 1ª persona (verificado)
cstick = on       ; stick derecho -> botones C
[menu]            ; menús del juego (detección automática por el flag de UI 0x802690D0)
b = B             ; B físico = atrás/cancelar
```

Valores válidos: `A B Z START L R CUP CDOWN CLEFT CRIGHT DUP DDOWN DLEFT DRIGHT NONE`. El port relee
`config.ini` en cada arranque (ruta alternativa: `HH_PAD_CONFIG=<fichero>`).
- **Si vuelve a crashear** (abort/assert): junto al `.exe` se escribe **`hh_missing.log`** con las
  direcciones `Failed to find function at 0x...`; pásalas y se añaden.
- Env útiles: `HH_RES=original|2x|<n>` (resolución), `HH_INVERT_Y=1` (eje), `HH_INPUTLOG`/`HH_PRESS*`
  y `HH_STICK=x,y` (input sintético para pruebas).

### Grabar y reproducir una partida (depuración determinista)

```bat
REM 1) Grabar tu partida (botones+stick) hasta justo antes del crash.
REM    Ruta absoluta = fiable; una relativa cae en el CWD (con run_windows.bat, en build_win\bin\Release).
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
- Si sale `Failed to find function at 0xXXXX`: apuntar el vram, añadirlo en el entorno Linux
  (`add_missing_funcs.py` / `config/module_extras.json`), regenerar el set y volver a copiar
  `RecompiledFuncs/` a Windows.

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
