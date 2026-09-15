@echo off
REM =====================================================================
REM  PRUEBA DE REGRESION - build Debug
REM  Las primeras versiones que funcionaban con el NPC eran Debug (30 fps).
REM  Requiere haber compilado antes con:  build_windows.bat --debug
REM =====================================================================
setlocal
set HH_INPUTLOG=1

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" (
    echo ERROR: no existe el exe Debug.
    echo Compila primero con:  build_windows.bat --debug
    pause
    exit /b 1
)
cd /d "%HHBIN%"
echo === REGRESION DEBUG (exe Debug) ===
"Hybrid Heaven Recomp.exe" %*
echo (exit %ERRORLEVEL%)
pause
