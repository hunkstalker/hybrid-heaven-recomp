@echo off
REM =====================================================================
REM  TRAZA DE COMBATE para localizar el estado de SORPRESA (MODO HEAVEN).
REM
REM  La sorpresa es un EVENTO puntual de ANTES del combate, asi que no se
REM  captura con fotos: mientras la traza esta activa se registra la PRIMERA
REM  variacion de cada palabra de las zonas de campo/objetos y de estado de
REM  batalla/party en `hh_battle_watch.log` (vi addr old->new). Comparando un
REM  combate NORMAL con uno SORPRENDIENDO al enemigo (por la espalda), la
REM  direccion que cambia en uno y no en el otro es el flag.
REM
REM  Tecla: F12 activa/desactiva la traza (o arranca activa con HH_BATTLE_TRACE=1).
REM
REM  PROTOCOLO (cada F12 ON crea su propio fichero hh_battle_watch_<n>.log):
REM     1) Entra en partida. Pulsa F12 para ACTIVAR la traza.
REM     2) Provoca UN combate NORMAL.
REM     3) Pulsa F12 para DESACTIVAR  -> ese run queda en hh_battle_watch_0.log
REM     4) Pulsa F12 para ACTIVAR. Provoca UN combate SORPRENDIENDO (por la espalda).
REM     5) F12 para DESACTIVAR  -> ese run queda en hh_battle_watch_1.log
REM     6) Cierra. Envia hh_battle_watch_0.log, hh_battle_watch_1.log y hh.log.
REM =====================================================================
setlocal

set "HHBIN=%~dp0build\windows\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0build\windows\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" (
  echo ERROR: no existe "Hybrid Heaven Recomp.exe". Compila con build_windows_release.bat.
  pause
  exit /b 1
)

cd /d "%HHBIN%"
REM No borrar hh_battle_watch.log (run normal ya hecha); solo los por-run hh_battle_watch_<n>.log.
del /q hh_battle_watch_*.log hh_battle_stderr.log 2>nul

echo === Hybrid Heaven Recomp - TRAZA DE COMBATE (sorpresa) ===
echo Config : %HHBIN%
echo Tecla  : F12 activa/desactiva la traza.
echo.
echo  1) Entra en partida. F12 (ON). Combate NORMAL. F12 (OFF).
echo     Copia hh_battle_watch.log a normal.log y borralo.
echo  2) F12 (ON). Combate SORPRENDIENDO (por la espalda). F12 (OFF).
echo     Copia hh_battle_watch.log a sorpresa.log.
echo  3) Cierra y envia normal.log, sorpresa.log y hh.log.
echo.
"Hybrid Heaven Recomp.exe" 2> hh_battle_stderr.log
echo (exit %ERRORLEVEL%)
echo.
echo Log: %HHBIN%\hh_battle_watch.log  y  %HHBIN%\hh.log
pause
