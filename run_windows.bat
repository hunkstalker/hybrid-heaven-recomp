@echo off
REM =====================================================================
REM  Lanzador del port.
REM  Ajustes: pon 1 en la variable, o pasa argumento:
REM     run_windows.bat noaudio    -> forzar modo sin dispositivo de audio
REM     run_windows.bat audlog     -> log detallado de audio
REM     run_windows.bat release    -> build\windows\bin\Release (GUI, una sola ventana)
REM     run_windows.bat debug      -> build\windows\bin\Debug   (con consola de debug)
REM  (dejar la variable VACIA = desactivado)
REM  Accesos directos: run_windows_release.bat / run_windows_debug.bat (doble clic).
REM =====================================================================
setlocal

REM --- AJUSTES ---
set HH_INPUTLOG=1
set HH_NOAUDIO=
set HH_AUDIOLOG=
set HH_INVERT_Y=
REM set HH_RECORD=%~dp0..\tests\mi_partida.txt
REM set HH_RES=2x

set "HHCFG="
if /i "%~1"=="debug"   set "HHCFG=Debug"
if /i "%~2"=="debug"   set "HHCFG=Debug"
if /i "%~1"=="release" set "HHCFG=Release"
if /i "%~2"=="release" set "HHCFG=Release"
if /i "%~1"=="noaudio" set HH_NOAUDIO=1
if /i "%~2"=="noaudio" set HH_NOAUDIO=1
if /i "%~1"=="audlog"  set HH_AUDIOLOG=1
if /i "%~2"=="audlog"  set HH_AUDIOLOG=1

REM Config explicita con 'debug'/'release'; sin argumento: Release si existe, si no Debug.
set "HHBIN=%~dp0build\windows\bin\Release"
set "HHCFGNAME=Release"
if /i "%HHCFG%"=="Debug" (
  set "HHBIN=%~dp0build\windows\bin\Debug"
  set "HHCFGNAME=Debug"
) else if not defined HHCFG if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" (
  set "HHBIN=%~dp0build\windows\bin\Debug"
  set "HHCFGNAME=Debug"
)

if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" (
  echo ERROR: no existe "%HHBIN%\Hybrid Heaven Recomp.exe".
  echo        Compila antes con build_windows_release.bat o build_windows_debug.bat.
  pause
  exit /b 1
)
cd /d "%HHBIN%"
if not exist "%HHBIN%\rom\baserom.us.z64" if not exist "%HHBIN%\baserom.us.z64" (
  echo AVISO: no veo la ROM. Ponla en "%HHBIN%\rom\baserom.us.z64".
)
echo === Hybrid Heaven Recomp ===
echo Config  : %HHCFGNAME%  (%HHBIN%)
echo HH_INPUTLOG=%HH_INPUTLOG%  HH_NOAUDIO=%HH_NOAUDIO%  HH_AUDIOLOG=%HH_AUDIOLOG%  HH_INVERT_Y=%HH_INVERT_Y%
"Hybrid Heaven Recomp.exe" %2 %3
echo (exit %ERRORLEVEL%)
pause
