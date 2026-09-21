@echo off
REM =====================================================================
REM  run_cac_tick2.bat - VALIDACION del CaC con tick a 2 VI (HH_VI_EVERY=2).
REM
REM  USO: DOBLE CLIC. No necesita flags ni argumentos.
REM
REM  Que hace:
REM    - Lanza el port EN VIVO (sin replay) con HH_VI_EVERY=2: el runtime
REM      entrega el evento VI al guest 1 de cada 2 VI -> el bucle de juego
REM      queda a 2 VI/tick (30 Hz) como el N64, en vez de 1 VI/tick.
REM    - Juega tu normalmente hasta el CaC.
REM    - Al cerrar, guarda los logs en logs_tick2_<fecha>\ junto al .exe.
REM
REM  ANTES (una sola vez): compila con port\build_windows.local.bat
REM  (o build_windows.bat). El runtime debe incluir HH_VI_EVERY (commit 15f920d).
REM
REM  QUE OBSERVAR:
REM    - Consola: banner "[VI] HH_VI_EVERY=2 activo (entrega ... cada 2 VI)".
REM      Si NO aparece, el runtime compilado no tiene el knob.
REM    - ENTRAR AL COMBATE en el CaC sin freeze/softlock -> exito.
REM    - Debe ir a 30 fps y el audio bien (sin tirones nuevos).
REM
REM  Detalle: notes/2026-09-19-causa-raiz-cadencia-frames.md y
REM           notes/2026-09-17-replay-mode-vi-vis-negativo.md (seccion 5.1).
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

REM --- aparta los logs de la pasada anterior (sin borrar nada) ---
if exist "logs_prev" del /q "logs_prev\*" >nul 2>&1
if not exist "logs_prev" mkdir "logs_prev" >nul 2>&1
move /y "hh_*.log" "logs_prev\" >nul 2>&1
move /y "boot.log" "logs_prev\" >nul 2>&1

for /f "usebackq delims=" %%t in (`powershell -NoProfile -Command "Get-Date -Format yyyyMMdd_HHmmss"`) do set "STAMP=%%t"
set "DEST=%HHBIN%\logs_tick2_%STAMP%"
mkdir "%DEST%" >nul 2>&1

echo =====================================================================
echo  VALIDACION CaC - tick a 2 VI (HH_VI_EVERY=2)   [EN VIVO, sin replay]
echo =====================================================================
echo  bin         : %HHBIN%
echo  logs        : %DEST%
echo  HH_VI_EVERY : 2
echo.
echo  Juega hasta el CaC. Objetivo: entrar al combate SIN freeze/softlock.
echo  Mira en la consola el banner:  [VI] HH_VI_EVERY=2 activo ...
echo  Cuando termines, cierra la ventana del juego.
echo.

REM --- el knob que valida la hipotesis de cadencia de tick ---
set "HH_VI_EVERY=2"
set "HH_STATE_SECS=5"

"Hybrid Heaven Recomp.exe"
set "RC=%ERRORLEVEL%"

move /y "hh_*.log" "%DEST%" >nul 2>&1
move /y "boot.log" "%DEST%" >nul 2>&1
move /y "hh_hang_rdram_*.bin" "%DEST%" >nul 2>&1
move /y "hh_crash_rdram.bin" "%DEST%" >nul 2>&1
move /y "hh_crash_dmem.bin" "%DEST%" >nul 2>&1

echo.
echo === Pasada guardada en: %DEST%  (exit %RC%)
if exist "%DEST%\hh_hang.log" (
  echo ATENCION: se genero hh_hang.log ^(posible cuelgue^). Revisalo.
) else (
  echo Sin hh_hang.log: no se detecto cuelgue.
)
echo.
echo Claves: banner "[VI] HH_VI_EVERY=2 activo"; entraste al combate; sin hh_hang.log.
echo Pega aqui el resultado o mandame la carpeta de logs.
echo.
pause
goto :eof

:nobin
echo ERROR: no encuentro "Hybrid Heaven Recomp.exe".
echo        Compila antes con port\build_windows.local.bat
pause
exit /b 1
