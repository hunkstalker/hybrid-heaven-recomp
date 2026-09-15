@echo off
REM Prueba SIN dispositivo de audio (aislar el crash). Doble clic.
set HH_NOAUDIO=1
set HH_INPUTLOG=1
set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
cd /d "%HHBIN%"
echo === Hybrid Heaven Recomp (HH_NOAUDIO=1) ===
"Hybrid Heaven Recomp.exe" %*
echo (exit %ERRORLEVEL%)
pause
