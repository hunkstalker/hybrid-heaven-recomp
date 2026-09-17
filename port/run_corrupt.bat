@echo off
REM =====================================================================
REM  run_corrupt.bat - repro del cuelgue de combate + GRABACION del gameplay.
REM
REM  Instrumentacion opt-in (ver recomp.cpp):
REM    HH_DRWATCH : watchpoint de HARDWARE (Windows) sobre palabras concretas
REM                 (ahora desactivado: daba falsos positivos) -> hh_drwatch.log
REM    HH_CANARY  : vigilancia del buffer RDRAM por frame; caza escrituras que
REM                 NO pasan por los MEM_* -> hh_canary.log
REM    HH_WATCH   : traza de accesos de codigo recompilado (MEM_*) -> hh_watch.log
REM
REM  Grabacion: HH_RECORD=hh_replay_fight.txt -> una linea por poll de juego
REM    (<t> <VI> <botones> <x> <y>), desde el primer poll hasta el freeze.
REM    El replay es determinista y se aplica por INDICE DE VI (no por tiempo).
REM
REM  Volcado al freeze: watchdog tras HH_HANG_SECS sin polls (o sin audio):
REM    hh_hang.log + hh_hang_rdram_<pid>_<n>.bin (8 MB) + DMEM + call rings.
REM    ESPERAR ~20 s tras el congelado antes de cerrar la ventana.
REM
REM  La pasada anterior se aparta (sin borrar) a logs_prev_corrupt\.
REM  Todos los ficheros quedan junto al .exe (build_win\bin\Release).
REM =====================================================================
setlocal
chcp 65001 >nul

REM --- Instrumentacion ---
set HH_DRWATCH=
set HH_CANARY=0x8024A98C:0xA0,0x801BBC1C:0x08,0x8017DD90:0x08,0x801CC8C4:0x04
set HH_WATCH_ADDR=0x8024A9AC
set HH_WATCH_SIZE=4

REM Traza: funciones clave + RANGO del modulo 23 + el selector de estado (M23_FUN_801c1dc0).
set HH_TRACE=0x80005270:disp,0x802408F0:armer,0x800058DC:setter,0x80379410:M55,0x8021B280:M10_1b280,0x8022C7AC:M10_2c7ac,0x80223260:M10_32260,0x80152CF8:flagSet,0x801C1DC0:M23_sel
set HH_TRACE_RANGE=0x801BF1A0:0x9000

REM --- Grabacion del gameplay (determinista, por VI) ---
set HH_RECORD=hh_replay_fight.txt
set HH_INPUTLOG=1

REM --- Logs de diagnostico + watchdog ---
set HH_DIAG=1
set HH_STATE_SECS=5
set HH_HANG_SECS=15

if /i "%~1"=="noaudio" set HH_NOAUDIO=1
if /i "%~2"=="noaudio" set HH_NOAUDIO=1

REM --- Modo CLEAN: graba con instrumentacion MINIMA (solo HH_RECORD + watchdog), para que el
REM timing de la grabacion coincida con el del replay y no derive por los logs/canary/traza.
if /i "%~1"=="clean" (
  set "HH_DRWATCH="
  set "HH_CANARY="
  set "HH_WATCH_ADDR="
  set "HH_WATCH_SIZE="
  set "HH_TRACE="
  set "HH_TRACE_RANGE="
  set "HH_DIAG="
  set "HH_INPUTLOG="
  echo [CLEAN] grabacion con instrumentacion minima
)
if /i "%~2"=="clean" (
  set "HH_DRWATCH="
  set "HH_CANARY="
  set "HH_WATCH_ADDR="
  set "HH_WATCH_SIZE="
  set "HH_TRACE="
  set "HH_TRACE_RANGE="
  set "HH_DIAG="
  set "HH_INPUTLOG="
  echo [CLEAN] grabacion con instrumentacion minima
)

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" (
  echo ERROR: no encuentro "Hybrid Heaven Recomp.exe".
  echo        Compila antes con port\build_windows.local.bat
  pause
  exit /b 1
)

cd /d "%HHBIN%"

REM --- Aparta la pasada anterior (sin borrar nada) ---
if not exist "%HHBIN%\logs_prev_corrupt" mkdir "%HHBIN%\logs_prev_corrupt" >nul 2>&1
move /y "hh_*.log" "%HHBIN%\logs_prev_corrupt\" >nul 2>&1
move /y "hh_hang_rdram_*.bin" "%HHBIN%\logs_prev_corrupt\" >nul 2>&1
move /y "hh_crash_*.bin" "%HHBIN%\logs_prev_corrupt\" >nul 2>&1
move /y "hh_audio_dump.bin" "%HHBIN%\logs_prev_corrupt\" >nul 2>&1
move /y "hh_replay_fight.txt" "%HHBIN%\logs_prev_corrupt\" >nul 2>&1

echo === Hybrid Heaven Recomp (CORRUPT WATCH + GRABACION) ===
echo   bin    : %HHBIN%
echo   replay : %HHBIN%\hh_replay_fight.txt
echo   DRWATCH=%HH_DRWATCH%  CANARY=%HH_CANARY%  HANG=%HH_HANG_SECS%s
echo.
echo IMPORTANTE:
echo   - Para un replay CORTO y estable, CARGA PARTIDA (el replay no restaura saves, pero
echo     al grabar desde el guardado el tramo es mas corto y sin cambios de camara largos).
echo     Tambien vale partida nueva; en ambos casos se graba hh_replay_fight.txt por VI.
echo   - Al congelarse el combate, ESPERA ~20 s al volcado automatico (hh_hang*)
echo     antes de cerrar la ventana.
echo.
"Hybrid Heaven Recomp.exe" %3 %4
set "RC=%ERRORLEVEL%"

echo.
echo === (exit %RC%) ===
echo === Ficheros de la pasada (junto al .exe) ===
if exist "hh_replay_fight.txt" echo   replay  : hh_replay_fight.txt
if exist "hh_hang.log"         echo   cuelgue : hh_hang.log + hh_hang_rdram_*.bin
if exist "hh_state.log"        echo   estado  : hh_state.log
if exist "hh_crash.log"        echo   crash   : hh_crash.log
echo.
if exist hh_state.log (
  echo === Ultimas lineas de estado ^(polls/audio^):
  powershell -NoProfile -Command "Get-Content hh_state.log -Tail 8"
)
echo.
pause
