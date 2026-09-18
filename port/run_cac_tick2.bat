@echo off
REM =====================================================================
REM  run_cac_tick2.bat - PRUEBA del CaC en Windows: tick a 2 VI exactos.
REM
REM  Uso: doble clic (o desde CMD en port\). NO necesita argumentos: llama
REM  a run_pacing.bat con el modo tick2, que activa HH_VI_EVERY=2 (entrega
REM  del evento VI al guest 1 de cada 2 VI -> el bucle de juego queda en
REM  2 VI/tick como el original).
REM
REM  Verificacion ANTES de jugar:
REM    - Banner: "=== run_pacing (modo tick2) ===" y "HH_VI_EVERY   : 2"
REM    - Consola: "[VI] HH_VI_EVERY=2 activo (entrega del evento VI al guest cada 2 VI)"
REM
REM  Detalle: notes/2026-09-17-replay-mode-vi-vis-negativo.md §6.
REM =====================================================================
setlocal
chcp 65001 >nul
echo === Lanzando la pasada tick2 (HH_VI_EVERY=2) via run_pacing.bat ...
echo.
call "%~dp0run_pacing.bat" tick2
endlocal
