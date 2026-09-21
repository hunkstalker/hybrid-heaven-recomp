@echo off
REM =====================================================================
REM  run_cac_replay_noaudio.bat - Prueba de aislamiento.
REM
REM  Reproduce la ultima grabacion (cac_rec.txt) SIN dispositivo de audio
REM  (HH_NOAUDIO=1), para ver si la divergencia de ruta en Windows viene
REM  del camino de audio (WASAPI) o del resto del entorno (RT64/ventana).
REM
REM  Uso: doble clic.
REM =====================================================================
setlocal
chcp 65001 >nul
echo === Replay SIN audio (aislamiento del factor WASAPI) ...
echo.
call "%~dp0run_cac_replay.bat" noaudio
endlocal
