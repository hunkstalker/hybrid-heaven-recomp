@echo off
REM =====================================================================
REM  run_cac_nob280.bat - REPLAY de cac_rec.txt con HH_NO_B280=1 (Windows).
REM
REM  Que hace: reproduce la grabacion (HH_REPLAY_MODE=poll) con el hook
REM  HH_NO_B280=1: ignora la PUBLICACION del handler 0x8021B280 en el setter
REM  FUN_800058dc -> M10_FUN_8021b240 corre (y su gate), pero b280 nunca se
REM  instala ni ejecuta = ruta del emulador (contralado: 0 veces con el
REM  mismo input).
REM
REM  Por que replay y no en vivo: el replay con poll YA reproduce el CaC y
REM  el freeze en Windows de forma fiable (hito 2026-09-18, VI~20710). En
REM  vivo el freeze es ~100%, pero el replay es automatico. (Cautela: en
REM  Windows el replay deriva un poco el input por los ticks de 3 VI; para
REM  este go/no-go del freeze no aplica.)
REM
REM  Uso: doble clic (usa la grabacion mas reciente en logs_pacing_*\cac_rec.txt)
REM       run_cac_nob280.bat RUTA\cac_rec.txt   (o arrastra el .txt sobre el .bat)
REM
REM  ANTES: recompila con port\build_windows.local.bat (el hook vive en
REM  lib\N64ModernRuntime\librecomp\src\overlays.cpp, sin commitear).
REM
REM  Que observar:
REM    - Consola/log: [NO_B280] obj=8024C934 handler=8021B280 (el hook actua).
REM    - NO debe haber "Failed to find function at 0xFF7F84CD" ni hh_venom.log
REM      con entradas ni hh_hang.log.
REM    - Si el replay termina sin cuelgue -> ruta del emulador validada.
REM  Los logs se recogen en logs_nob280_<fecha>\ (cabecera de modo incluida).
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
set "NEWEST="
for /f "delims=" %%d in ('dir /b /ad /o-d "%HHBIN%\logs_pacing_*" 2^>nul') do if not defined NEWEST call :try_rec "%%d"
if not defined NEWEST goto :norec
set "REC=%HHBIN%\%NEWEST%"
:have_rec
if not exist "%REC%" goto :norec

cd /d "%HHBIN%"
for /f "delims=" %%t in ('powershell -NoProfile "Get-Date -Format yyyyMMdd_HHmmss"') do set "STAMP=%%t"
set "DEST=%HHBIN%\logs_nob280_%STAMP%"
mkdir "%DEST%" >nul 2>&1
if exist "%HHBIN%\logs_prev" del /q "%HHBIN%\logs_prev\*" >nul 2>&1
if not exist "%HHBIN%\logs_prev" mkdir "%HHBIN%\logs_prev" >nul 2>&1
move /y "hh_*.log" "%HHBIN%\logs_prev\" >nul 2>&1

echo === run_cac_nob280 (replay + HH_NO_B280=1) ===
echo   grabacion : %REC%
echo   destino   : %DEST%
echo   noaudio   : %HH_NOAUDIO%
echo.
echo Reproduciendo (sin input manual). Deja correr hasta que termine o se
echo cuelgue. Si se para antes de entrar al combate, ESPERA 20-30 s para que
echo el watchdog escriba hh_hang.log y despues cierra. Verifica [NO_B280].
echo.

set "HH_REPLAY=%REC%"
set "HH_REPLAY_MODE=poll"
set "HH_REPLAY_PACE="
set "HH_NO_B280=1"
> "%DEST%\console.log" echo === run_cac_nob280 modo=replay+nob280 HH_REPLAY_MODE=poll HH_NO_B280=1 rec=%REC% ===
"Hybrid Heaven Recomp.exe" >> "%DEST%\console.log" 2>&1
set "RC=%ERRORLEVEL%"

move /y "hh_*.log" "%DEST%" >nul 2>&1
move /y "hh_hang_*.bin" "%DEST%" >nul 2>&1

echo.
echo === Pasada guardada en: %DEST%  (exit %RC%)
if exist "%~dp0stall_summary.ps1" (
  powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0stall_summary.ps1" "%DEST%" >nul 2>&1
  if exist "%DEST%\stall_summary.txt" (
    echo.
    type "%DEST%\stall_summary.txt"
  )
)
echo.
echo Claves: [NO_B280] presente, sin "Failed to find 0xFF7F84CD", sin venoms, sin hh_hang.log.
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
echo        Uso: run_cac_nob280.bat RUTA\cac_rec.txt
echo        (o arrastra el cac_rec.txt sobre este .bat)
pause
exit /b 1
