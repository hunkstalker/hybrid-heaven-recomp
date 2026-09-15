@echo off
REM Prueba SIN dispositivo de audio (aislar el crash). Doble clic.
set HH_NOAUDIO=1
set HH_INPUTLOG=1
cd /d "%~dp0HybridHeavenRecomp\build_win\bin\Debug"
echo === Hybrid Heaven Recomp (HH_NOAUDIO=1) ===
"Hybrid Heaven Recomp.exe" %*
echo (exit %ERRORLEVEL%)
pause
