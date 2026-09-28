@echo off
REM =====================================================================
REM  WATCH del dano FUERA de combate (robots).
REM
REM  HH_DRWATCH (Windows, watchpoints de hardware) vigila la vida del
REM  personaje (sheet 0x8017DC40, palabras 0x8017DC40 y 0x8017DC44) y, al
REM  cambiar, escribe en hh_drwatch.log el valor, el RIP (exe+off), el guest
REM  ra/sp/a0..a3, el backtrace host y los call rings guest. Eso identifica
REM  la funcion que baja la vida.
REM
REM  PROTOCOLO:
REM     1) Entra en partida (campo, sin combate).
REM     2) Deja que un robot te dispare varias veces (hasta que baje la vida).
REM     3) Cierra el juego y envia hh_drwatch.log (y hh_drwatch_rdram.bin).
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
REM DRWATCH (hardware) puede no disparar; HH_WATCH (software) loguea ra+val de cada acceso.
set "HH_DRWATCH=0x8017DC40,0x8017DC44"
set "HH_WATCH_ADDR=0x8017DC40"
set "HH_WATCH_SIZE=4"
del /q hh_drwatch.log hh_drwatch_rdram.bin hh_watch.log hh_ring.log hh_field_stderr.log 2>nul

echo === Hybrid Heaven Recomp - WATCH dano de campo (robots) ===
echo Config : %HHBIN%
echo HH_DRWATCH=%HH_DRWATCH%   HH_WATCH_ADDR=%HH_WATCH_ADDR%:%HH_WATCH_SIZE%
echo.
echo  1) Entra en partida (campo).
echo  2) Deja que un robot te dispare varias veces.
echo  3) Cierra y envia hh_watch.log (y hh_drwatch.log si existe)
echo.
"Hybrid Heaven Recomp.exe" 2> hh_field_stderr.log
echo (exit %ERRORLEVEL%)
echo.
echo Log: %HHBIN%\hh_watch.log
pause
