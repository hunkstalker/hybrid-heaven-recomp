@echo off
REM =====================================================================
REM  run_cac_record.bat - GRABA la partida hasta el cuelgue del CaC.
REM
REM  Uso: doble clic (o desde CMD en port\). NO necesita argumentos: llama
REM  a run_pacing.bat con el modo record (HH_RECORD=cac_rec.txt).
REM
REM  Juega como siempre hasta que se cuelgue (entrada del CaC). Al cerrar
REM  la ventana, en la carpeta logs_pacing_<fecha>\ quedan:
REM    - cac_rec.txt   (input por tick, para reproducir headless)
REM    - hh_state.log / hh_hang.log / hh_hang_rdram_*.bin
REM
REM  Con eso se reproduce en dev: HH_REPLAY=cac_rec.txt HH_REPLAY_MODE=poll
REM  (y el emulador consume el mismo fichero: 1 muestra por poll).
REM
REM  Detalle: notes/2026-09-17-replay-mode-vi-vis-negativo.md
REM =====================================================================
setlocal
chcp 65001 >nul
echo === Lanzando la pasada record (grabando input) via run_pacing.bat ...
echo.
call "%~dp0run_pacing.bat" record
endlocal
