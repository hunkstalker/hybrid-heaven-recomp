@echo off
REM =====================================================================
REM  run_node_drwatch.bat - Caza QUIEN PISA el nodo de la lista de
REM  suscriptores del event-dispatch (CaC). Watchpoint de HARDWARE.
REM
REM  USO: DOBLE CLIC. Juega hasta el CaC (donde se cuelga). Al cerrar
REM  guarda los logs en logs_nodewatch_<fecha>\ junto al .exe.
REM
REM  Que hace (runtime, en lib\N64ModernRuntime):
REM    HH_DRWATCH=...   watchpoint de HARDWARE de Windows (registros DR0-3)
REM                     sobre los campos del nodo persistente del bucle
REM                     principal. Para en la instruccion EXACTA que escribe
REM                     y loguea RIP + pila host -> hh_drwatch.log. Tambien
REM                     vuelca hh_drwatch_rdram.bin al primer impacto.
REM    HH_CHAINTRACE=1  instala los wrappers [PUSH]/[BCAST] y registra la
REM                     vigilancia del nodo ([NODEWATCH]); ademas traza la
REM                     cadena del disable en hh_chain.log.
REM
REM  Nodos vigilados (por defecto, los 4 registros DR):
REM    0x8005BF14 next / 0x8005BF18 q    (nodo del bucle principal FUN_800011b0)
REM    0x80095FF8 next / 0x80095FFC q    (nodo del hilo 3)
REM  El nodo 0x8005BF14 = sp+0x34 de FUN_800011b0 (hilo 5); el hilo principal
REM  nunca retorna, asi que cualquier escritura ahi es el pisado.
REM
REM  ANTES: recompila con port\build_windows.local.bat (la instrumentacion
REM  vive en lib\N64ModernRuntime\librecomp\src\recomp.cpp / overlays.cpp).
REM
REM  QUE OBSERVAR:
REM    - hh_drwatch.log: linea "[DR] slot=.. guest=8005BF14 old=.. new=..
REM      rip=exe+0x... + bt:". El RIP/backtrace es quien pisa. old->new dice
REM      con que valor.
REM    - Si NO aparece ningun [DR] pero si hh_nodewatch.log/[BCORRUPT], el
REM      nodo no se corrompio en esta pasada (o cambio de direccion: mira el
REM      primer [PUSH] node=... en la consola y ajusta HH_DRWATCH).
REM    - hh_nodewatch.log: cambios de next/q con la ventana de llamadas de
REM      TODOS los hilos (mini-canary, se dispara aunque el DR no pise).
REM    - hh_bcorrupt.log: primer nodo/q no-cola detectado en [BCAST].
REM
REM  Detalle: notes/2026-09-20-nodo-8005bf14-origen-y-captura.md
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
set "DEST=%HHBIN%\logs_nodewatch_%STAMP%"
mkdir "%DEST%" >nul 2>&1

echo =====================================================================
echo  CaC EN VIVO - watchpoint de HARDWARE sobre el nodo de suscriptores
echo =====================================================================
echo  bin    : %HHBIN%
echo  logs   : %DEST%
echo.
echo  Juega hasta el CaC. Cuando se cuelgue, ESPERA 20-30 s (para que el
echo  watchdog escriba hh_hang.log) y cierra la ventana.
echo.

set "HH_DRWATCH=0x8005BF14,0x8005BF18,0x80095FF8,0x80095FFC"
set "HH_CHAINTRACE=1"
set "HH_STATE_SECS=5"
set "HH_HANG_SECS=10"
REM HH_M55SPFIX=1: restaura sp tras M55_FUN_80379410 (mid-entry 0x80379410 con epilogo +0x58 sin
REM prologo). Debe eliminar la fuga de pila (hh_spchk.log delta=0) y el cuelgue del CaC.
REM Ponlo a 0/borralo para la pasada de diagnostico sin fix.
set "HH_M55SPFIX=1"

"Hybrid Heaven Recomp.exe"
set "RC=%ERRORLEVEL%"

move /y "hh_*.log" "%DEST%" >nul 2>&1
move /y "boot.log" "%DEST%" >nul 2>&1
move /y "hh_drwatch*.log" "%DEST%" >nul 2>&1
move /y "hh_drwatch_rdram.bin" "%DEST%" >nul 2>&1
move /y "hh_hang_rdram_*.bin" "%DEST%" >nul 2>&1
move /y "hh_crash_rdram.bin" "%DEST%" >nul 2>&1

echo.
echo === Pasada guardada en: %DEST%  (exit %RC%)
echo.
echo Mira hh_drwatch.log: la linea [DR] guest=8005BF14 da RIP + backtrace
echo (exe+0x...) del escritor. Pega esa linea (y su "bt:") en el chat.
echo.
pause
goto :eof

:nobin
echo ERROR: no encuentro "Hybrid Heaven Recomp.exe".
echo        Compila antes con port\build_windows.local.bat
pause
exit /b 1
