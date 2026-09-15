@echo off
REM Prueba CON audio y log detallado [AUD]. Doble clic.
set HH_AUDIOLOG=1
set HH_INPUTLOG=1
cd /d "%~dp0HybridHeavenRecomp\build_win\bin\Debug"
echo === Hybrid Heaven Recomp (HH_AUDIOLOG=1) ===
"Hybrid Heaven Recomp.exe" %*
echo (exit %ERRORLEVEL%)
pause
