@echo off
REM =====================================================================
REM  Ejecuta la build Release (una sola ventana, sin consola de debug).
REM  Envoltorio de run_windows.bat release. Los argumentos extra se reenvian.
REM =====================================================================
call "%~dp0run_windows.bat" release %*
