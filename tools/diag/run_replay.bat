@echo off
REM =====================================================================
REM  run_replay.bat - reproduce un replay de input para validarlo.
REM
REM  Uso:
REM     run_replay.bat                       -> hh_replay_fight.txt (junto al .exe), modo poll
REM     run_replay.bat <fichero.txt>         -> otro replay
REM     run_replay.bat <fichero> diag        -> ademas HH_DIAG=1 (logs de diagnostico)
REM     run_replay.bat <fichero> sync        -> alinea por VI en el primer poll (HH_REPLAY_SYNC=vi)
REM     run_replay.bat <fichero> nomodt      -> desactiva la traza base-aware ([MODT], por defecto ON)
REM   Por defecto: modo poll + HH_REPLAYLOG + HH_MODTRACE; la consola se guarda en modt_console.log.
REM
REM  Modos de reproduccion (input.cpp):
REM     HH_REPLAY_MODE=poll (defecto) -> una muestra por poll/frame (exacto, robusto al jitter)
REM     HH_REPLAY_MODE=vi             -> ultima muestra con VI <= actual (sensible al jitter)
REM   hh_replay.log (siempre aqui) = muestras aplicadas (poll, VI, botones, x, y) para comparar 1:1
REM   con hh_replay_fight.txt.
REM
REM  Si se congela, espera ~20 s al volcado (hh_hang*) antes de cerrar. No graba ni toca el replay.
REM =====================================================================
setlocal
chcp 65001 >nul

set "REPLAY="
set "DIAG="
set "SYNC="
set "MODT=1"
:parse
if "%~1"=="" goto parsed
if /i "%~1"=="diag" goto setdiag
if /i "%~1"=="sync" goto setsync
if /i "%~1"=="modt" goto setmodt
if /i "%~1"=="nomodt" goto clrmodt
if "%REPLAY%"=="" set "REPLAY=%~1"
goto nextarg
:setdiag
set "DIAG=1"
goto nextarg
:setsync
set "SYNC=1"
goto nextarg
:setmodt
set "MODT=1"
goto nextarg
:clrmodt
set "MODT="
goto nextarg
:nextarg
shift
goto parse
:parsed
if "%REPLAY%"=="" set "REPLAY=hh_replay_fight.txt"

set "HH_REPLAY=%REPLAY%"
set "HH_REPLAY_MODE=poll"
set "HH_REPLAYLOG=1"
if defined SYNC set "HH_REPLAY_SYNC=vi"
REM 'modt': traza base-aware por offset de modulo (independiente de la base de reubicacion).
if defined MODT set "HH_MODTRACE=03000000:21A0:M23_mask,03000000:2C20:M23_1dc0,03000000:2D40:M23_sel,03000000:4F4C:M23_40EC,03000000:4F58:M23_40F8,03000000:521C:M23_43BC,03000000:5324:M23_44C4,03000000:5428:M23_45C8,07000000:2D40:M8_e0"
set "HH_RECORD="
set "HH_INPUTLOG="
set "HH_STATE_SECS=5"
set "HH_HANG_SECS=15"
set "HH_DIAG=%DIAG%"

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" (
  echo ERROR: no encuentro "Hybrid Heaven Recomp.exe".
  echo        Compila antes con port\build_windows.local.bat
  pause
  exit /b 1
)

cd /d "%HHBIN%"
if not exist "%REPLAY%" (
  echo ERROR: no encuentro el replay "%REPLAY%".
  echo        Copia el .txt junto al .exe o pasa la ruta como argumento.
  pause
  exit /b 1
)

REM --- Aparta la pasada anterior de logs/volcados (sin tocar el replay) ---
if not exist "%HHBIN%\logs_prev_replay" mkdir "%HHBIN%\logs_prev_replay" >nul 2>&1
move /y "hh_*.log" "%HHBIN%\logs_prev_replay\" >nul 2>&1
move /y "hh_hang_rdram_*.bin" "%HHBIN%\logs_prev_replay\" >nul 2>&1
move /y "hh_crash_*.bin" "%HHBIN%\logs_prev_replay\" >nul 2>&1

echo === run_replay ===
echo   bin           : %HHBIN%
echo   replay        : %REPLAY%
echo   modo          : %HH_REPLAY_MODE%   sync: %HH_REPLAY_SYNC%   diag: %HH_DIAG%   modt: %MODT%
echo   ultima muestra del replay:
powershell -NoProfile -Command "Get-Content '%REPLAY%' -Tail 1"
echo.
echo VALIDACION: si el combate se congela, espera ~20 s al volcado (hh_hang*) antes de cerrar.
echo             al terminar, hh_replay.log tiene las muestras aplicadas para comparar con el replay.
echo.
if defined MODT (
  "Hybrid Heaven Recomp.exe" > "modt_console.log" 2>&1
) else (
  "Hybrid Heaven Recomp.exe"
)
set "RC=%ERRORLEVEL%"

echo.
echo === (exit %RC%) ===
if exist "hh_hang.log"    echo   cuelgue : hh_hang.log + hh_hang_rdram_*.bin
if exist "hh_replay.log"  echo   replay aplicado: hh_replay.log
if defined MODT echo   consola modt: modt_console.log  ^(aqui van las lineas [MODT]^)
if exist "hh_state.log" (
  echo === Ultimas lineas de estado ^(polls/audio/VI^):
  powershell -NoProfile -Command "Get-Content hh_state.log -Tail 8"
)
echo.
pause
