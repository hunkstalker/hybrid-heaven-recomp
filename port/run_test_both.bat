@echo off
REM =====================================================================
REM  PRUEBA DE REGRESION - input + audio a la vez
REM  Mapeo antiguo + audio anterior. Si NO se cuelga, separa con
REM  run_test_input.bat / run_test_audio.bat para saber cual era.
REM =====================================================================
setlocal
set HH_PAD_CONFIG=%~dp0config_test_oldmap.ini
set HH_AI_QUEUE_REPORT=full
set HH_AI_RATE=48000
set HH_INPUTLOG=1

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
cd /d "%HHBIN%"
echo === REGRESION input+audio ===
"Hybrid Heaven Recomp.exe" %*
echo (exit %ERRORLEVEL%)
pause
