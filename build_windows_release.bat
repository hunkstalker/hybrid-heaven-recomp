@echo off
REM =====================================================================
REM  Compila SOLO la config Release (GUI: una sola ventana, sin consola).
REM  Envoltorio de build_windows.bat. Para el build local del mantenedor
REM  (sin git, commits sin publicar) usa build_windows_release.local.bat.
REM =====================================================================
call "%~dp0build_windows.bat"
