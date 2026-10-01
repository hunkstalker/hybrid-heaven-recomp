@echo off
REM =====================================================================
REM  TRAZA de la UI de CARGA propia en CONTINUAR (DATA LOAD).
REM
REM  Objetivo: diagnosticar dos sintomas reportados (2026-10-01):
REM    (a) el CURSOR de slots "se mueve abajo pero vuelve arriba";
REM    (b) se cuela/parpadea UI NATIVA (mensaje/Controller Pak).
REM
REM  HH_LOAD_TRACE=1 registra en hh_trace.log, POR FRAME, dos lineas
REM  (tag=pre / post del update nativo):
REM    - phase    : fase de nuestro flujo (0 Browse,1 ConfirmDelete,2 Loaded,3 Removed)
REM    - cursor   : cursor de NUESTRO modelo (LoadGame)
REM    - native cur/top/st/page : cursor/top/estado/pagina NATIVOS del file-select
REM                               (D_801BEC05 / D_801BEC04 / D_801BEBCC / D_801BEC02)
REM    - fs_active / native_visible : banderas de ocultado (F8)
REM
REM  COMO LEERLO:
REM    * Si `cursor` avanza y al frame siguiente vuelve a 0 -> rebuild_load_game
REM      reescribe el cursor (BUG corregido: open_load_game ya no reconstruye si
REM      esta abierta). Debe mantenerse estable.
REM    * Si `native cur/st` cambia aunque el nativo este oculto -> el nativo sigue
REM      moviendo su estado (posible origen del parpadeo). Comparar con `fs_active`.
REM    * Si `fs_active=0` o `native_visible=1` -> el ocultado no esta activo ese frame.
REM
REM  HH_MENU_TRACE=1 anade los cambios de pantalla (func_800058DC) con su target.
REM
REM  PROTOCOLO:
REM    1) En el menu de titulo, elige CONTINUAR.
REM    2) Mueve el cursor por los slots (arriba/abajo varias veces).
REM    3) Prueba A (cargar), X (borrar) y B (volver).
REM    4) Cierra el juego y envia hh_trace.log (y hh.log).
REM =====================================================================
setlocal

set "HHBIN=%~dp0build\windows\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0build\windows\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" (
  echo ERROR: no existe "Hybrid Heaven Recomp.exe". Compila con build_windows_release.bat.
  pause
  exit /b 1
)

cd /d "%HHBIN%"

set "HH_LOAD_TRACE=1"
set "HH_MENU_TRACE=1"

del /q hh_trace.log 2>nul

echo === Hybrid Heaven Recomp - TRAZA UI de CARGA (CONTINUAR) ===
echo Config : %HHBIN%
echo HH_LOAD_TRACE : %HH_LOAD_TRACE%
echo HH_MENU_TRACE : %HH_MENU_TRACE%
echo.
echo  1) Menu de titulo -^> CONTINUAR.
echo  2) Mueve el cursor por los slots (arriba/abajo).
echo  3) Prueba A (cargar), X (borrar), B (volver).
echo  4) Cierra y envia hh_trace.log (y hh.log).
echo.
"Hybrid Heaven Recomp.exe" 2> hh_load_stderr.log
echo (exit %ERRORLEVEL%)
echo.
echo Log: %HHBIN%\hh_trace.log
pause
