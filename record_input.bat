@echo off
REM =====================================================================
REM  record_input.bat - graba el input de una partida a un replay de texto.
REM
REM  Uso:
REM     record_input.bat                    -> graba en tests\replays\hud_combat.txt
REM     record_input.bat hud_map.txt        -> graba en tests\replays\hud_map.txt
REM     record_input.bat hud_combat.txt debug -> usa la build Debug (consola)
REM
REM  Graba TODA la sesion desde el arranque (menus incluidos). Al cerrar el juego
REM  el .txt queda en: hybrid-heaven-recomp\tests\replays\  (versionado: fixture de input)
REM  Formato: <t> <vis> <botones_hex> <x> <y>   (lo reproduce HH_REPLAY / run_replay.bat)
REM =====================================================================
setlocal
set "NAME=%~1"
if "%NAME%"=="" set "NAME=hud_combat.txt"
set "REPLAYDIR=%~dp0tests\replays"
if not exist "%REPLAYDIR%" mkdir "%REPLAYDIR%" >nul 2>&1
set "HH_RECORD=%REPLAYDIR%\%NAME%"

echo === Grabar input ===
echo   salida : %HH_RECORD%
echo.
echo   Juega hasta el punto deseado y luego cierra el juego (Alt+F4 / cerrar ventana).
echo   (carga la partida guardada y llega al HUD de combate, o abre el mapa con B)
echo.

call "%~dp0run_windows.bat" release %2

echo.
if exist "%HH_RECORD%" (
  echo === Replay guardado: %HH_RECORD% ===
  for %%A in ("%HH_RECORD%") do echo   tamano: %%~zA bytes
) else (
  echo ERROR: no se creo el replay. Revisa que HH_RECORD llego al juego.
)
pause
