@echo off
REM =====================================================================
REM  run_stall_check.bat - Via de los STALLS: pasada EN VIVO + recogida de
REM  logs + resumen de cadencia (dvi / guest_busy por tick).
REM
REM  Objetivo (RETOMAR.md, prioridad unica): medir por que el hilo de juego
REM  hace ticks de 3 VI (guest_busy ~34 ms; presupuesto 2 VI = 33,3 ms) y
REM  atacar la alineacion frame<->VI (cuelgue del CaC).
REM
REM  Por que EN VIVO (sin replay): el freeze es ~100% en Windows en vivo;
REM  el replay con HH_REPLAY_MODE=poll deriva el input con los ticks de 3 VI.
REM
REM  Que hace:
REM    - Fuerza modo live (limpia HH_REPLAY*, HH_NO_DISABLE, HH_VI_EVERY...).
REM    - Activa HH_STATE_SECS=5 (snapshots) y HH_FRAMELOG=1 (1 linea/tick).
REM    - Aparta los hh_*.log previos a logs_prev\ y, al salir, mueve TODO
REM      (hh_slow.log, hh_slice.log, hh_tick.log, hh_state.log,
REM      hh_framelog.log, consola y volcados de cuelgue) a
REM      logs_stall_<fecha_hora>\.
REM    - Genera stall_summary.txt (con stall_summary.ps1): distribucion
REM      d1/d2/d3/d4+ de VI por tick, dt, guest_busy, stalls y ultimo estado.
REM
REM  ANTES: recompila con port\build_windows.local.bat. El resumen por tick
REM  de guest_busy (5 campos en hh_framelog.log) necesita el build actual;
REM  si el .exe es viejo, el resumen avisa y usa solo dt+VI.
REM
REM  Uso: doble clic (pasada normal). Juega normal hasta el CaC (o hasta que
REM  se cuelgue); si no se cuelga en 2-3 min, cierra la ventana. Al terminar,
REM  DEVUELVE la carpeta logs_stall_<...> (o stall_summary.txt + los .log).
REM
REM  run_stall_check.bat det      -> igual pero con HH_DET_CLOCK=1 (reloj de
REM                                  juego determinista anclado al VI). Comparar
REM                                  con la pasada normal: si bajan los ticks
REM                                  de 3 VI y no congela, el desfase es del
REM                                  origen del reloj.
REM  run_stall_check.bat nob280   -> HH_NO_B280=1: ignora la PUBLICACION del
REM                                  handler 0x8021B280 (M10_FUN_8021b240 co-
REM                                  rre, pero b280 ni se instala ni se ejecuta
REM                                  = ruta del emulador, que nunca lo corre).
REM                                  VALIDACION: si entra al combate sin colgar,
REM                                  la ruta del disable es el bloqueo real.
REM  (combinable: run_stall_check.bat det nob280)
REM =====================================================================
setlocal
chcp 65001 >nul

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" goto :nobin
cd /d "%HHBIN%"

REM --- modo live y knobs de la pasada (vacio = valor por defecto/desactivado) ---
REM Limpia tambien diagnosticos pesados que cambian el timing (watchpoint, trazas).
set "HH_REPLAY="
set "HH_REPLAY_MODE="
set "HH_REPLAY_PACE="
set "HH_REPLAY_CLOCK="
set "HH_NO_DISABLE="
set "HH_NO_B280="
set "HH_VI_EVERY="
set "HH_DET_CLOCK="
set "HH_TIMESCALE="
set "HH_WATCH_ADDR="
set "HH_WATCH_VENOM="
set "HH_M24LOG="
set "HH_DUMP_VI="
set "HH_B280TRACE="
set "HH_NOAUDIO="
set "HH_HEADLESS="
set "HH_STATE_SECS=5"
set "HH_FRAMELOG=1"
set "MODE=normal"
if /i "%~1"=="det" set "HH_DET_CLOCK=1"
if /i "%~2"=="det" set "HH_DET_CLOCK=1"
if /i "%~1"=="nob280" set "HH_NO_B280=1"
if /i "%~2"=="nob280" set "HH_NO_B280=1"
if defined HH_DET_CLOCK set "MODE=det"
if defined HH_NO_B280 if /i "%MODE%"=="det" ( set "MODE=det+nob280" ) else ( set "MODE=nob280" )

for /f "usebackq delims=" %%t in (`powershell -NoProfile -Command "Get-Date -Format yyyyMMdd_HHmmss"`) do set "STAMP=%%t"
set "DEST=%HHBIN%\logs_stall_%STAMP%"
mkdir "%DEST%" >nul 2>&1
if not exist "%HHBIN%\logs_prev" mkdir "%HHBIN%\logs_prev" >nul 2>&1
move /y "hh_*.log" "%HHBIN%\logs_prev\" >nul 2>&1
move /y "boot.log" "%HHBIN%\logs_prev\" >nul 2>&1

if not exist "%HHBIN%\rom\baserom.us.z64" if not exist "%HHBIN%\baserom.us.z64" (
  echo AVISO: no veo la ROM. Ponla en "%HHBIN%\rom\baserom.us.z64".
)

echo === run_stall_check (live, modo %MODE%) ===
echo   bin           : %HHBIN%
echo   destino       : %DEST%
echo   HH_STATE_SECS : %HH_STATE_SECS%
echo   HH_FRAMELOG   : %HH_FRAMELOG%
echo   HH_DET_CLOCK  : %HH_DET_CLOCK%
echo   HH_NO_B280    : %HH_NO_B280%
echo.
echo Juega normal (hasta el CaC si puedes). Si se cuelga/para, ESPERA 20-30 s
echo para que el watchdog escriba hh_hang.log (pila/anillos de los hilos) y
echo despues cierra la ventana; si no se cuelga, 2-3 minutos y cierra.
echo.

REM Cabecera en el propio log de consola: deja constancia del modo/knobs de ESTA pasada.
> "%HHBIN%\stall_console_%STAMP%.log" echo === run_stall_check modo=%MODE% HH_DET_CLOCK=%HH_DET_CLOCK% HH_NO_B280=%HH_NO_B280% ===
>> "%HHBIN%\stall_console_%STAMP%.log" echo === (consola del exe; los hh_*.log van aparte) ===
"Hybrid Heaven Recomp.exe" >> "%HHBIN%\stall_console_%STAMP%.log" 2>&1
set "RC=%ERRORLEVEL%"

move /y "hh_*.log" "%DEST%" >nul 2>&1
move /y "boot.log" "%DEST%" >nul 2>&1
move /y "stall_console_%STAMP%.log" "%DEST%" >nul 2>&1
move /y "hh_hang_*.bin" "%DEST%" >nul 2>&1
move /y "hh_crash_*.bin" "%DEST%" >nul 2>&1
move /y "hh_audio_dump.bin" "%DEST%" >nul 2>&1

echo.
echo === Pasada guardada en: %DEST%  (exit %RC%)

if exist "%~dp0stall_summary.ps1" (
  powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0stall_summary.ps1" "%DEST%"
  if exist "%DEST%\stall_summary.txt" (
    echo.
    type "%DEST%\stall_summary.txt"
  )
) else (
  echo AVISO: no encuentro stall_summary.ps1 junto a este .bat; no hay resumen.
)

echo.
echo Devuelve la carpeta completa: %DEST%
pause
goto :eof

:nobin
echo ERROR: no encuentro "Hybrid Heaven Recomp.exe".
echo        Compila antes con port\build_windows.local.bat
pause
exit /b 1
