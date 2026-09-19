@echo off
REM =====================================================================
REM  run_cac_nodisable.bat - Prueba del workaround HH_NO_DISABLE=1 en Windows.
REM
REM  Que hace: reproduce una grabacion (cac_rec.txt) con HH_REPLAY_MODE=poll y
REM  HH_NO_DISABLE=1. Ese flag IGNORA la escritura del sentinel 0xFFFF84CD /
REM  0xFF7F84CD (el "disable" que el emulador NUNCA aplica), de modo que el objeto
REM  del CaC conserva su callback sano (801CB71C). Si el disable era el unico
REM  bloqueo, el combate debe entrar sin el cuelgue del CaC.
REM
REM  Uso:  run_cac_nodisable.bat RUTA\cac_rec.txt [noaudio]
REM        (sin ruta: usa la grabacion mas reciente en logs_pacing_*\cac_rec.txt;
REM         tambien vale arrastrar el cac_rec.txt sobre este .bat)
REM
REM  ANTES (obligatorio): recompila con el runtime local, que ya trae el fix:
REM        port\build_windows.local.bat
REM        (el arbol lib\N64ModernRuntime debe tener overlays.cpp con
REM         hh_dump_venom/HH_NO_DISABLE; si sincronizas por git, NO estan pusheados)
REM
REM  Que observar:
REM    - ENTRAR AL COMBATE sin quedarse colgado -> el disable era el unico bloqueo;
REM      el workaround da salida jugable provisional.
REM    - En consola aparecen lineas:  [NO_DISABLE] obj=... cb=FFFF84CD (escritura ignorada)
REM    - Si SIGUE colgado -> hay mas de un bloqueo; toca atacar los stalls.
REM  Los logs se recogen en logs_nodisable_<fecha>\.
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
set "DEST=%HHBIN%\logs_nodisable_%STAMP%"
mkdir "%DEST%" >nul 2>&1
if not exist "%HHBIN%\logs_prev" mkdir "%HHBIN%\logs_prev" >nul 2>&1
move /y "hh_*.log" "%HHBIN%\logs_prev\" >nul 2>&1

echo === run_cac_nodisable  (HH_NO_DISABLE=1) ===
echo   grabacion : %REC%
echo   destino   : %DEST%
echo   noaudio   : %HH_NOAUDIO%
echo.
echo Reproduciendo con HH_NO_DISABLE=1 (sin input manual). Deja correr.
echo Si entra al combate, exito; si se cuelga, el watchdog volcara.
echo.

set "HH_REPLAY=%REC%"
REM poll: 1 muestra por tick (exacto). No usar HH_REPLAY_PACE=vi (tirones).
set "HH_REPLAY_MODE=poll"
set "HH_REPLAY_PACE="
REM El workaround: ignora el sentinel 0xFFFF84CD/0xFF7F84CD en FUN_800058dc.
set "HH_NO_DISABLE=1"
"Hybrid Heaven Recomp.exe"
set "RC=%ERRORLEVEL%"

move /y "hh_*.log" "%DEST%" >nul 2>&1
move /y "hh_hang_rdram_*.bin" "%DEST%" >nul 2>&1
echo.
echo === Pasada guardada en: %DEST%  (exit %RC%)
echo     Busca en la consola: [NO_DISABLE] obj=... cb=FFFF84CD
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
echo        Uso: run_cac_nodisable.bat RUTA\cac_rec.txt
echo        (o arrastra el cac_rec.txt sobre este .bat)
pause
exit /b 1
