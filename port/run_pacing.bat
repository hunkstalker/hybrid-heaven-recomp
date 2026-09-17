@echo off
REM =====================================================================
REM  run_pacing.bat - pasada de PACING (Fase 2/3) y recogida de logs.
REM
REM  Uso (desde port\, doble clic o CMD):
REM     run_pacing.bat            -> lanza el port con los defaults de pacing
REM     run_pacing.bat trace      -> ademas traza frame/disp (HH_TRACE)
REM     run_pacing.bat gate       -> ~20-30 s con HH_VERBOSE+HH_GATELOG a fichero
REM                                  (captura [GATE]/[GATE2]/[SUBM] y cd4c)
REM
REM  Que hace:
REM     - Aparta los hh_*.log previos a logs_prev\ (la pasada queda limpia).
REM     - Ejecuta el .exe en su carpeta (respeta config.ini y saves\).
REM     - Crea logs_pacing_<fecha_hora>\ junto al .exe y mueve alli los logs
REM       (incluidos hh_hang/hh_crash dumps si los hubo) y boot.log.
REM     - Imprime las ultimas lineas de estado (polls/audio) para pegar.
REM
REM  Defaults de la pasada: HH_DIAG apagado (solo hh_state + volcados de error),
REM  HH_STATE_SECS=5, HH_PADLOG apagado, sin HH_VERBOSE/HH_MQLOG_ALL/HH_WAITLOG.
REM =====================================================================
setlocal enabledelayedexpansion
chcp 65001 >nul

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" (
  echo ERROR: no encuentro "Hybrid Heaven Recomp.exe".
  echo        Compila antes con port\build_windows.local.bat
  goto :err
)

REM --- Defaults de la pasada (dejar vacio = desactivado) ---
set "HH_STATE_SECS=5"
set "HH_DIAG="
set "HH_TRACE="
set "HH_VERBOSE="
set "HH_GATELOG="
set "HH_MQLOG_ALL="
set "HH_WAITLOG="
set "HH_INPUTLOG="
set "HH_PADLOG="
set "MODE=pacing"
if /i "%~1"=="trace" ( set "MODE=trace" & set "HH_TRACE=0x80001454:frame,0x80005270:disp" )
if /i "%~1"=="gate"  ( set "MODE=gate"  & set "HH_VERBOSE=1" & set "HH_GATELOG=1" )

cd /d "%HHBIN%"
if not exist "rom\baserom.us.z64" if not exist "baserom.us.z64" (
  echo AVISO: no veo la ROM en "%HHBIN%\rom\baserom.us.z64" ^(hace falta para jugar^).
)

for /f "usebackq delims=" %%t in (`powershell -NoProfile -Command "Get-Date -Format yyyyMMdd_HHmmss"`) do set "STAMP=%%t"
set "DEST=%HHBIN%\logs_pacing_%STAMP%"
mkdir "%DEST%" >nul 2>&1

REM --- aparta logs previos (sin borrar nada) ---
if not exist "%HHBIN%\logs_prev" mkdir "%HHBIN%\logs_prev" >nul 2>&1
move /y "hh_*.log" "%HHBIN%\logs_prev\" >nul 2>&1
move /y "boot.log" "%HHBIN%\logs_prev\" >nul 2>&1

echo === run_pacing (modo %MODE%) ===
echo   bin           : %HHBIN%
echo   destino logs  : %DEST%
echo   HH_STATE_SECS : %HH_STATE_SECS%
echo   HH_TRACE      : %HH_TRACE%
echo   HH_VERBOSE    : %HH_VERBOSE%   HH_GATELOG: %HH_GATELOG%
echo.
if /i "%MODE%"=="gate" (
  echo Juega 20-30 s ^(gameplay o menu^) y cierra la ventana. La consola se guarda en un log.
  echo.
  "Hybrid Heaven Recomp.exe" > "%HHBIN%\gate_console_%STAMP%.log" 2>&1
) else (
  echo Juega 2-3 minutos de gameplay y cierra la ventana al terminar.
  echo.
  "Hybrid Heaven Recomp.exe" %2 %3
)
set "RC=%ERRORLEVEL%"

move /y "hh_*.log" "%DEST%" >nul 2>&1
move /y "boot.log" "%DEST%" >nul 2>&1
move /y "hh_hang_rdram_*.bin" "%DEST%" >nul 2>&1
move /y "hh_crash_rdram.bin" "%DEST%" >nul 2>&1
move /y "hh_crash_dmem.bin" "%DEST%" >nul 2>&1
move /y "hh_audio_dump.bin" "%DEST%" >nul 2>&1
move /y "gate_console_%STAMP%.log" "%DEST%" >nul 2>&1

echo.
echo === Pasada guardada en: %DEST%  (exit %RC%)
if exist "%DEST%\hh_state.log" (
  echo === Ultimas lineas de estado ^(pegar esto o el hh_state.log completo^):
  powershell -NoProfile -Command "Get-Content '%DEST%\hh_state.log' -Tail 15"
) else (
  echo AVISO: no se genero hh_state.log en esta pasada.
)
echo.
pause
goto :eof

:err
pause
exit /b 1
