@echo off
REM =====================================================================
REM  Compila SOLO la config Debug (con consola, para diagnosticar crashes).
REM  Envoltorio de build_windows.bat --debug. Para el build local del
REM  mantenedor (sin git) usa build_windows_debug.local.bat.
REM =====================================================================
call "%~dp0build_windows.bat" --debug
