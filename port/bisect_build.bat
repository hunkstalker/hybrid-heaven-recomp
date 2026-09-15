@echo off
REM =====================================================================
REM  BUILD DE BISECT - regresion del cuelgue del NPC
REM  - Reajusta el runtime a su base y aplica el patch del commit actual.
REM  - Compila Release.
REM  - Lanza el juego.
REM  Uso: doble clic desde cualquier sitio. El commit lo cambia quien
REM  prepara el bisect en el arbol compartido.
REM =====================================================================
setlocal
set "HERE=%~dp0"
for %%I in ("%HERE%..") do set "ROOT=%%~fI"
set "PORT=%ROOT%\port\HybridHeavenRecomp"
set "NMR=%PORT%\lib\N64ModernRuntime"
set "PATCH=%ROOT%\port\windows_runtime_changes.patch"
set "EXTRA=%ROOT%\port\bisect_extra.patch"
set "NMR_BASE=fd6b0d0eedc922700f67bab8b770d3986187f3e9"

echo === BISECT: runtime a la base + patch del commit actual ===
pushd "%NMR%"
git -c safe.directory=* checkout -f %NMR_BASE%
if errorlevel 1 goto :err
git -c safe.directory=* submodule update --init --recursive
git -c safe.directory=* apply "%PATCH%"
if errorlevel 1 echo AVISO: el patch principal no aplica; puede que ya estuviera aplicado.
if exist "%EXTRA%" goto :extra
goto :after_extra

:extra
git -c safe.directory=* apply "%EXTRA%"
if errorlevel 1 echo AVISO: bisect_extra.patch no aplica; puede estar ya aplicado.

:after_extra
popd

echo === BISECT: compilando Release ===
cmake --build "%PORT%\build_win" --target HybridHeavenRecomp --config Release
if errorlevel 1 goto :err

echo === BISECT: lanzando ===
set "HHBIN=%PORT%\build_win\bin\Release"
cd /d "%HHBIN%"
set HH_INPUTLOG=1
"Hybrid Heaven Recomp.exe" %*
echo.
echo FIN. Si el juego se colgo, cierra la ventana del juego y vuelve aqui.
pause
goto :eof

:err
echo.
echo *** ERROR en el build de bisect. Revisa los mensajes de arriba. ***
pause
exit /b 1
