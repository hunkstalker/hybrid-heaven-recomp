@echo off
REM =====================================================================
REM  run_nodisable_live.bat - Prueba del workaround HH_NO_DISABLE=1 EN VIVO
REM  (sin replay): juega tu normalmente hasta el CaC.
REM
REM  Por que en vivo y no con replay: el replay en Windows no es fiel al
REM  gameplay original porque el port hace ticks de 3 VI (guest_busy ~34 ms,
REM  presupuesto 33.3 ms) y en modo poll las muestras se aplican en el
REM  instante de juego equivocado (deriva de input). En vivo eso no aplica.
REM
REM  Que hace: lanza el port con HH_NO_DISABLE=1, que IGNORA la escritura del
REM  sentinel 0xFFFF84CD/0xFF7F84CD (el "disable" que el emulador NUNCA aplica).
REM  El objeto del CaC conserva su callback sano (801CB71C).
REM
REM  ANTES: recompila con port\build_windows.local.bat (runtime local con el fix).
REM
REM  Que observar:
REM    - ENTRAR AL COMBATE sin el cuelgue del CaC -> el disable era el unico
REM      bloqueo; salida jugable provisional.
REM    - En consola: [NO_DISABLE] obj=... cb=FFFF84CD (escritura ignorada)
REM    - Si SIGUE colgado -> hay mas de un bloqueo; toca atacar los stalls.
REM
REM  Uso: run_nodisable_live.bat [noaudio]
REM =====================================================================
setlocal
chcp 65001 >nul

set "HH_NOAUDIO="
if /i "%~1"=="noaudio" set "HH_NOAUDIO=1"

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" goto :nobin
cd /d "%HHBIN%"
if not exist "%HHBIN%\rom\baserom.us.z64" if not exist "%HHBIN%\baserom.us.z64" (
  echo AVISO: no veo la ROM. Ponla en "%HHBIN%\rom\baserom.us.z64".
)

echo === run_nodisable_live (HH_NO_DISABLE=1, sin replay) ===
echo   HH_NOAUDIO=%HH_NOAUDIO%
echo.
echo Juega normalmente hasta el CaC. Si entra al combate, exito.
echo.

REM El workaround: ignora el sentinel 0xFFFF84CD/0xFF7F84CD en FUN_800058dc.
set "HH_NO_DISABLE=1"
"Hybrid Heaven Recomp.exe"
echo (exit %ERRORLEVEL%)
pause
goto :eof

:nobin
echo ERROR: no encuentro "Hybrid Heaven Recomp.exe".
echo        Compila antes con port\build_windows.local.bat
pause
exit /b 1
