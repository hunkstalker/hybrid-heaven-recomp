@echo off
REM =====================================================================
REM  Lanzador del port.
REM  Ajustes: pon 1 en la variable, o pasa argumento:
REM     run_windows.bat noaudio    -> forzar modo sin dispositivo de audio
REM     run_windows.bat audlog     -> log detallado de audio
REM  (dejar la variable VACIA = desactivado)
REM =====================================================================
setlocal

REM --- AJUSTES ---
set HH_INPUTLOG=1
set HH_NOAUDIO=
set HH_AUDIOLOG=
set HH_INVERT_Y=
REM set HH_RECORD=%~dp0..\tests\mi_partida.txt
REM set HH_RES=2x

if /i "%~1"=="noaudio" set HH_NOAUDIO=1
if /i "%~1"=="audlog"  set HH_AUDIOLOG=1

set "HHBIN=%~dp0build\windows\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0build\windows\bin\Debug"
cd /d "%HHBIN%"
if not exist "%HHBIN%\rom\baserom.us.z64" if not exist "%HHBIN%\baserom.us.z64" (
  echo AVISO: no veo la ROM. Ponla en "%HHBIN%\rom\baserom.us.z64".
)
echo === Hybrid Heaven Recomp ===
echo HH_INPUTLOG=%HH_INPUTLOG%  HH_NOAUDIO=%HH_NOAUDIO%  HH_AUDIOLOG=%HH_AUDIOLOG%  HH_INVERT_Y=%HH_INVERT_Y%
"Hybrid Heaven Recomp.exe" %2 %3
echo (exit %ERRORLEVEL%)
pause
