@echo off
REM =====================================================================
REM  run_chain_live.bat - CaC EN VIVO con traza de la CADENA del disable.
REM
REM  USO: DOBLE CLIC. Juega hasta el CaC (donde se cuelga). Al cerrar guarda
REM  los logs en logs_chain_<fecha>\ junto al .exe.
REM
REM  Que instrumenta (runtime, gate HH_CHAINTRACE=1):
REM    hh_chain.log : ejecuciones de la cadena de callbacks del disable
REM                   M10_FUN_8021b1A8 -> b200 -> b240 -> b280 (con vi/sample).
REM    hh_sched.log : disparos del scheduler FUN_80004bb0 (id a0, a1,
REM                   tiempos 42CC/42BC/42D0/42C8).
REM  Ademas: HH_GATE_A=1 (puerta 0x39) y HH_B280TRACE=1 (instalador), que
REM  van a stderr (consola) y a hh_b280.log.
REM
REM  ANTES: recompila con port\build_windows.local.bat (la instrumentacion
REM  vive en lib\N64ModernRuntime\librecomp\src\overlays.cpp).
REM
REM  QUE OBSERVAR:
REM    - hh_chain.log: en que sample/vi se ejecuta cada paso. El PRIMER paso
REM      que aparece en el port (p.ej. b200 o b240) y que el emulador no
REM      dispara es el punto de divergencia.
REM    - hh_sched.log: la tarea a0=0x39 (disable) frente a a0=0x113.
REM    - hh_hang.log si se cuelga.
REM
REM  Detalle: notes/2026-09-19-causa-raiz-cadencia-frames.md seccion 9/10.
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
move /y "boot.log" "logs_prev\" >nul 2>&1

for /f "usebackq delims=" %%t in (`powershell -NoProfile -Command "Get-Date -Format yyyyMMdd_HHmmss"`) do set "STAMP=%%t"
set "DEST=%HHBIN%\logs_chain_%STAMP%"
mkdir "%DEST%" >nul 2>&1

echo =====================================================================
echo  CaC EN VIVO - traza de la CADENA del disable (HH_CHAINTRACE)
echo =====================================================================
echo  bin    : %HHBIN%
echo  logs   : %DEST%
echo.
echo  Juega hasta el CaC. Cuando se cuelgue, ESPERA 20-30 s (para que el
echo  watchdog escriba hh_hang.log) y cierra la ventana.
echo.

set "HH_CHAINTRACE=1"
set "HH_GATE_A=1"
set "HH_B280TRACE=1"
set "HH_STATE_SECS=5"

"Hybrid Heaven Recomp.exe"
set "RC=%ERRORLEVEL%"

move /y "hh_*.log" "%DEST%" >nul 2>&1
move /y "boot.log" "%DEST%" >nul 2>&1
move /y "hh_hang_rdram_*.bin" "%DEST%" >nul 2>&1
move /y "hh_crash_rdram.bin" "%DEST%" >nul 2>&1

echo.
echo === Pasada guardada en: %DEST%  (exit %RC%)
echo.
echo Si hh_chain.log existe, pegame sus lineas (o toda la carpeta).
echo Claves: primer paso de la cadena (b1A8/b200/b240/b280) y la tarea 0x39
echo en hh_sched.log.
echo.
pause
goto :eof

:nobin
echo ERROR: no encuentro "Hybrid Heaven Recomp.exe".
echo        Compila antes con port\build_windows.local.bat
pause
exit /b 1
