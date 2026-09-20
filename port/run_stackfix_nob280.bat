@echo off
REM =====================================================================
REM  run_stackfix_nob280.bat - CaC EN VIVO con la PILA YA SANA (HH_M55SPFIX)
REM  y HH_NO_B280=1. Diagnostico: ?el livelock restante es consecuencia del
REM  veneno (callback invalido 0xFFFF84CD que el emulador nunca instala)?
REM
REM  Por que: ya hemos resuelto la fuga de pila (mid-entries M55 + dispatcher
REM  FUN_80005270 -> sp +0x58/frame). Con HH_M55SPFIX el nodo 0x8005BF14 ya no
REM  se corrompe y el juego llega al HUD del CaC. Si al ignorar la publicacion
REM  del handler 0x8021B280 (HH_NO_B280=1) el combate AVANZA, el veneno es el
REM  bloqueador restante (habria que arreglar el upstream: por que el port
REM  despacha el evento temporizado 0x39 y el emulador no).
REM  Si sigue el livelock, es un problema distinto.
REM
REM  USO: doble clic; cargar partida justo antes del CaC; jugar; al colgarse
REM  esperar 20-30 s y cerrar. Logs en logs_stackfix_nob280_<fecha>\.
REM
REM  ANTES: recompila con port\build_windows.local.bat.
REM  Detalle: notes/2026-09-20-nodo-8005bf14-origen-y-captura.md §11.
REM =====================================================================
setlocal enabledelayedexpansion
chcp 65001 >nul

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" goto :nobin

cd /d "%HHBIN%"
if not exist "rom\baserom.us.z64" if not exist "baserom.us.z64" (
  echo AVISO: no veo la ROM. Ponla en "%HHBIN%\rom\baserom.us.z64".
)

if exist "logs_prev" del /q "logs_prev\*" >nul 2>&1
if not exist "logs_prev" mkdir "logs_prev" >nul 2>&1
move /y "hh_*.log" "logs_prev\" >nul 2>&1

for /f "usebackq delims=" %%t in (`powershell -NoProfile -Command "Get-Date -Format yyyyMMdd_HHmmss"`) do set "STAMP=%%t"
set "DEST=%HHBIN%\logs_stackfix_nob280_%STAMP%"
mkdir "%DEST%" >nul 2>&1

echo =====================================================================
echo  CaC EN VIVO - PILA SANA (HH_M55SPFIX) + HH_NO_B280=1
echo =====================================================================
echo  bin    : %HHBIN%
echo  logs   : %DEST%
echo.
echo  Carga partida antes del CaC. Al colgarse, ESPERA 20-30 s y cierra.
echo.

set "HH_CHAINTRACE=1"
set "HH_M55SPFIX=1"
set "HH_NO_B280=1"
set "HH_STATE_SECS=5"
set "HH_HANG_SECS=10"

"Hybrid Heaven Recomp.exe"
set "RC=%ERRORLEVEL%"

move /y "hh_*.log" "%DEST%" >nul 2>&1
move /y "hh_hang_rdram_*.bin" "%DEST%" >nul 2>&1

echo.
echo === Pasada guardada en: %DEST%  (exit %RC%)
echo.
echo Clave: ?el combate AVANZA (no se cuelga) con HH_NO_B280=1?
echo        Si avanza -^> el veneno era el bloqueador. Si no -^> livelock aparte.
echo.
pause
goto :eof

:nobin
echo ERROR: no encuentro "Hybrid Heaven Recomp.exe".
echo        Compila antes con port\build_windows.local.bat
pause
exit /b 1
