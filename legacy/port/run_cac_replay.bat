@echo off
REM =====================================================================
REM  run_cac_replay.bat - REPRODUCE una grabacion (cac_rec.txt) en Windows.
REM
REM  Uso:  run_cac_replay.bat RUTA\cac_rec.txt
REM        (la ruta de la grabacion; p.ej.
REM         HybridHeavenRecomp\build_win\bin\Release\logs_pacing_20260918_033912\cac_rec.txt)
REM
REM  Lanza el port con HH_REPLAY=<ruta> y HH_REPLAY_MODE=poll (1 muestra por tick; exacto). Tras el
REM  fix de get_function el port va a 30 ticks/s, asi que poll es fiel; mode=vi introducia un sesgo.
REM  HH_REPLAY_PACE se deja VACIO (el PLL de pace=vi provoca tirones). Sirve para
REM  comparar el replay en Windows (RT64/WASAPI) con el replay headless
REM  (lavapipe/dummy, ya validado canonico):
REM    - si en Windows tambien se cuelga -> el factor es el entorno;
REM    - si no -> el factor es la interaccion en vivo (timing de input).
REM
REM  Los logs se recogen en logs_replay_<fecha>\.
REM =====================================================================
setlocal
chcp 65001 >nul

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" goto :nobin

set "REC=%~1"
if /i "%~1"=="noaudio" ( set "REC=" & set "HH_NOAUDIO=1" )
if /i "%~2"=="noaudio" set "HH_NOAUDIO=1"
if not "%REC%"=="" goto :have_rec
REM Sin argumento: busca la grabacion mas reciente en logs_pacing_*\cac_rec.txt
set "NEWEST="
for /f "delims=" %%d in ('dir /b /ad /o-d "%HHBIN%\logs_pacing_*" 2^>nul') do if not defined NEWEST call :try_rec "%%d"
if not defined NEWEST goto :norec
set "REC=%HHBIN%\%NEWEST%"
:have_rec
if not exist "%REC%" goto :norec

cd /d "%HHBIN%"
for /f "delims=" %%t in ('powershell -NoProfile "Get-Date -Format yyyyMMdd_HHmmss"') do set "STAMP=%%t"
set "DEST=%HHBIN%\logs_replay_%STAMP%"
mkdir "%DEST%" >nul 2>&1
if exist "%HHBIN%\logs_prev" del /q "%HHBIN%\logs_prev\*" >nul 2>&1
if not exist "%HHBIN%\logs_prev" mkdir "%HHBIN%\logs_prev" >nul 2>&1
move /y "hh_*.log" "%HHBIN%\logs_prev\" >nul 2>&1

echo === run_cac_replay ===
echo   grabacion : %REC%
echo   destino   : %DEST%
echo   noaudio   : %HH_NOAUDIO%
echo.
echo Reproduciendo la grabacion (sin input manual). Dejar correr hasta que
echo termine o se cuelgue (el watchdog volcara si se cuelga).
echo.

set "HH_REPLAY=%REC%"
REM Modo poll: 1 muestra por tick (exacto por frame de juego). Se eligio vi cuando el port era
REM work-bound y peridia ticks; tras el fix de get_function el port va a 30 ticks/s estables, y vi
REM introducia un sesgo (input desalineado: el PJ se iba ligeramente a un lado). Medido 2026-09-18:
REM con poll la grabacion nueva reproduce el CaC (freeze + veneno 0xFF7F84CD) en headless; con vi no.
set "HH_REPLAY_MODE=poll"
set "HH_REPLAY_PACE="
"Hybrid Heaven Recomp.exe"
set "RC=%ERRORLEVEL%"

move /y "hh_*.log" "%DEST%" >nul 2>&1
move /y "hh_hang_rdram_*.bin" "%DEST%" >nul 2>&1
echo.
echo === Pasada guardada en: %DEST%  (exit %RC%)
pause
goto :eof

:nobin
echo ERROR: no encuentro "Hybrid Heaven Recomp.exe".
echo        Compila antes con port\build_windows.local.bat
pause
exit /b 1

:try_rec
if exist "%HHBIN%\%~1\cac_rec.txt" set "NEWEST=%~1\cac_rec.txt"
goto :eof

:norec
echo ERROR: no encuentro ninguna grabacion cac_rec.txt.
echo        Uso: run_cac_replay.bat RUTA\cac_rec.txt
echo        (o arrastra el cac_rec.txt sobre este .bat)
pause
exit /b 1
