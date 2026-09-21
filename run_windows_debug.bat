@echo off
REM =====================================================================
REM  Ejecuta la build Debug (con consola de debug).
REM  Envoltorio de run_windows.bat debug. Los argumentos extra se reenvian.
REM =====================================================================
call "%~dp0run_windows.bat" debug %*
