@echo off
REM =====================================================================
REM  PRUEBA DE REGRESION - input
REM  Lanza con el mapeo de mando ANTIGUO (pre-perfiles): A=A, B=B,
REM  Back=Z, X=C-Left, Y=C-Up, sin stick derecho->C.
REM  Si con este bat NO se cuelga en el NPC, el culpable es el mapeo nuevo.
REM =====================================================================
setlocal
set HH_PAD_CONFIG=%~dp0config_test_oldmap.ini
set HH_INPUTLOG=1

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
cd /d "%HHBIN%"
echo === REGRESION INPUT (mapeo antiguo) ===
echo Config: %HH_PAD_CONFIG%
"Hybrid Heaven Recomp.exe" %*
echo (exit %ERRORLEVEL%)
pause
