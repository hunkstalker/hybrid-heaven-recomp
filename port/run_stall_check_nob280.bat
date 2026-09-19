@echo off
REM =====================================================================
REM  run_stall_check_nob280.bat - doble clic seguro: pasada EN VIVO con
REM  HH_NO_B280=1 (experimento "ruta del emulador").
REM
REM  DOBLE CLIC = test completo: HH_NO_B280=1 + HH_DET_CLOCK=1 (nob280 det).
REM  No hace falta pasar flags por consola. (Equivale a
REM  run_stall_check.bat nob280 det.)
REM
REM  Que hace HH_NO_B280: ignora la PUBLICACION del handler 0x8021B280 en
REM  el setter FUN_800058dc -> M10_FUN_8021b240 corre (y su gate), pero
REM  b280 nunca se instala ni se ejecuta, que es lo que hace el emulador
REM  (contralado: 0 ejecuciones de b280/M55 con el mismo input).
REM
REM  VERIFICACION de que los flags han entrado (en consola y en
REM  stall_console_<fecha>.log):
REM    - Banner: "=== run_stall_check (live, modo det+nob280) ===",
REM      "HH_NO_B280 : 1" y "HH_DET_CLOCK : 1"
REM    - Primera linea del log: "... modo=det+nob280 HH_DET_CLOCK=1 HH_NO_B280=1 ==="
REM    - Consola: [NO_B280] obj=8024C934 handler=8021B280
REM
REM  ANTES: recompila con port\build_windows.local.bat (el hook vive en
REM  lib\N64ModernRuntime\librecomp\src\overlays.cpp, sin commitear).
REM =====================================================================
setlocal
chcp 65001 >nul
echo === Lanzando test completo: nob280 + det (HH_NO_B280=1 + HH_DET_CLOCK=1) ...
echo.
call "%~dp0run_stall_check.bat" nob280 det
endlocal
