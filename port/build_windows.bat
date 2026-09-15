@echo off
REM =====================================================================
REM  Hybrid Heaven Recomp - Build para Windows
REM  Si lib\rt64 y lib\N64ModernRuntime ya existen, NO hace git (evita
REM  cuelgues sobre unidades montadas) y compila directamente.
REM  Uso:
REM    build_windows.bat                 -> Release (recomendado: 3-5x mas rapido)
REM    build_windows.bat --debug         -> Debug (solo para diagnosticar crashes)
REM    build_windows.bat --force-libs    -> clonar/actualizar libs antes
REM =====================================================================
setlocal enabledelayedexpansion
chcp 65001 >nul
set "GIT_TERMINAL_PROMPT=0"

set "FORCE_LIBS=0"
set "BUILDCFG=Release"
if /i "%~1"=="--force-libs" set "FORCE_LIBS=1"
if /i "%~1"=="--debug" set "BUILDCFG=Debug"
if /i "%~2"=="--debug" set "BUILDCFG=Debug"

REM --- Detectar la raiz del repo (busca 'port\HybridHeavenRecomp' hacia arriba) ---
set "ROOT="
for /f "usebackq delims=" %%d in (`powershell -NoProfile -Command "$cur='%~dp0'; while($cur -and -not (Test-Path (Join-Path $cur 'port\HybridHeavenRecomp'))){$cur=Split-Path $cur -Parent}; if($cur){$cur}else{'NONE'}"`) do set "ROOT=%%d"
if "%ROOT%"=="NONE" (
    echo ERROR: no encuentro 'port\HybridHeavenRecomp' hacia arriba desde este .bat.
    goto :err
)
set "PORT=%ROOT%\port\HybridHeavenRecomp"
set "RT64=%PORT%\lib\rt64"
set "NMR=%PORT%\lib\N64ModernRuntime"
set "PATCH=%ROOT%\port\windows_runtime_changes.patch"

set "RT64_COMMIT=43373749dac9bbc1b653e6a02aed40a9e1783bed"
set "NMR_BASE=fd6b0d0eedc922700f67bab8b770d3986187f3e9"

echo.
echo === Hybrid Heaven Recomp - build Windows ===
echo Repo root : %ROOT%
echo Port      : %PORT%
echo.

set "SKIP_LIBS=0"
if exist "%RT64%\CMakeLists.txt" if exist "%NMR%\CMakeLists.txt" if "%FORCE_LIBS%"=="0" set "SKIP_LIBS=1"

if "%SKIP_LIBS%"=="1" goto :libs_ok

REM ============ 1) lib/rt64 ============
if exist "%RT64%\CMakeLists.txt" goto :rt64_present
echo [1/4] Clonando lib/rt64 ...
git clone https://github.com/rt64/rt64.git "%RT64%"
if errorlevel 1 goto :err
goto :step2

:rt64_present
echo [1/4] lib/rt64 ya existe. Comprobando repo git ...
if not exist "%RT64%\.git" (
    echo ERROR: %RT64% existe pero NO es un repositorio git.
    echo        Borra la carpeta lib\rt64 y vuelve a ejecutar.
    goto :err
)
pushd "%RT64%"
git -c safe.directory=* checkout %RT64_COMMIT%
if errorlevel 1 echo AVISO: no se pudo hacer checkout de %RT64_COMMIT% en rt64
popd

:step2
REM ============ 2) lib/N64ModernRuntime ============
if exist "%NMR%\CMakeLists.txt" goto :nmr_present
echo [2/4] Clonando lib/N64ModernRuntime (recursivo) ...
git clone --recursive https://github.com/N64Recomp/N64ModernRuntime.git "%NMR%"
if errorlevel 1 goto :err
goto :patch

:nmr_present
echo [2/4] lib/N64ModernRuntime ya existe. Comprobando repo git ...
if not exist "%NMR%\.git" (
    echo ERROR: %NMR% existe pero NO es un repositorio git.
    echo        Borra la carpeta lib\N64ModernRuntime y vuelve a ejecutar.
    goto :err
)
pushd "%NMR%"
git -c safe.directory=* checkout %NMR_BASE% >nul 2>&1
git -c safe.directory=* submodule update --init --recursive
popd
goto :patch

:libs_ok
echo [1-2/4] lib\rt64 y lib\N64ModernRuntime ya existen: se OMITE git.
echo          Usa --force-libs si quieres clonar/actualizar.

:patch
REM ============ Patch de runtime (solo si no esta aplicado) ============
echo.
echo [2b/4] Comprobando patch de runtime ...
if not exist "%PATCH%" (
    echo ERROR: no encuentro el patch: %PATCH%
    goto :err
)
pushd "%NMR%"
git -c safe.directory=* apply --check "%PATCH%" >nul 2>&1
if errorlevel 1 goto :patch_maybe_applied
git -c safe.directory=* apply "%PATCH%"
if errorlevel 1 goto :patch_failed
echo        Patch aplicado.
popd
goto :cmake

:patch_maybe_applied
git -c safe.directory=* apply --reverse --check "%PATCH%" >nul 2>&1
if errorlevel 1 goto :patch_unknown
echo        Patch YA aplicado (se omite).
popd
goto :cmake

:patch_unknown
echo AVISO: el patch no aplica ni revierte. Si el port ya compila, ignorar;
echo        si no, aplica a mano los ficheros que lista el patch.
popd
goto :cmake

:patch_failed
echo ERROR aplicando el patch.
popd
goto :err

:cmake
REM ============ 3) CMake configure ============
set "VSGEN="
cmake -G "Visual Studio 18 2026" --help >nul 2>&1 && set "VSGEN=Visual Studio 18 2026"
if not defined VSGEN cmake -G "Visual Studio 17 2022" --help >nul 2>&1 && set "VSGEN=Visual Studio 17 2022"
if not defined VSGEN (
    echo ERROR: no encuentro Visual Studio 2026 ni 2022 con C++ instalado.
    goto :err
)
echo.
echo [3/4] Configurando con CMake (%VSGEN% x64) ...
pushd "%PORT%"
cmake -B build_win -G "%VSGEN%" -A x64
if errorlevel 1 goto :err
popd

REM ============ 4) Build ============
echo.
echo [4/4] Compilando HybridHeavenRecomp (%BUILDCFG%) ...
echo       (Release es 3-5x mas rapido que Debug: sin optimizar el juego cae a 30fps
echo        y el hilo de audio solo produce la mitad de buffers -> petardeo)
pushd "%PORT%"
cmake --build build_win --target HybridHeavenRecomp --config %BUILDCFG%
if errorlevel 1 goto :err
popd

echo.
echo === LISTO ===
echo Exe: %PORT%\build_win\bin\%BUILDCFG%\Hybrid Heaven Recomp.exe
echo Copia baserom.us.z64 junto al .exe y ejecutalo.
echo.
pause
goto :eof

:err
echo.
echo *** Se detuvo con errores. Revisa los mensajes de arriba. ***
pause
exit /b 1
