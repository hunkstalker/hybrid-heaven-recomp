@echo off
REM =====================================================================
REM  PRUEBA DE REGRESION - audio
REM  Lanza con el comportamiento de audio ANTERIOR a los cambios:
REM    HH_AI_QUEUE_REPORT=full  -> osAiGetLength sin cap (cola real)
REM    HH_AI_RATE=48000         -> tasa por defecto original (no 43200)
REM  Si con este bat NO se cuelga en el NPC, el culpable es el audio.
REM =====================================================================
setlocal
set HH_AI_QUEUE_REPORT=full
set HH_AI_RATE=48000
set HH_INPUTLOG=1

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
cd /d "%HHBIN%"
echo === REGRESION AUDIO (sin cap de feedback, 48000 Hz) ===
"Hybrid Heaven Recomp.exe" %*
echo (exit %ERRORLEVEL%)
pause
