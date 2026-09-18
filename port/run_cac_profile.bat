@echo off
REM =====================================================================
REM  run_cac_profile.bat - PERFILADO de cadencia (doble clic).
REM
REM  Lanza run_pacing.bat profile (LIMPIO, sin HH_DIAG): trazas frame/disp
REM  a fichero + audlog + hh_tick.log (siempre). Juega 1-2 minutos (hasta el
REM  CaC si puedes) y cierra.
REM
REM  Logs utiles en logs_pacing_<fecha>\:
REM    - hh_tick.log  : cuantizacion por tick (d1/d2/d3/d4+ VI) y max_dt  <- clave
REM    - hh_trace.log : entradas de frame/disp con t= (periodos reales)
REM    - hh_audio.log : produccion/cola de audio
REM    - profile_console_*.log : consola completa
REM =====================================================================
setlocal
chcp 65001 >nul
echo === Perfilado de cadencia (modo profile) ...
echo.
call "%~dp0run_pacing.bat" profile
endlocal
