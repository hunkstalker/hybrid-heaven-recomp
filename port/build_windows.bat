@echo off
REM =====================================================================
REM  Hybrid Heaven Recomp - Build para Windows (paso a paso, automático)
REM  Ejecuta este .bat desde cualquier carpeta; se ancla al directorio del repo.
REM =====================================================================
setlocal enabledelayedexpansion
chcp 65001 >nul

REM --- Detectar la raiz del repo (busca 'port\HybridHeavenRecomp' hacia arriba desde el .bat) ---
set "ROOT="
for /f "usebackq delims=" %%d in (`powershell -NoProfile -Command "$cur='%~dp0'; while($cur -and -not (Test-Path (Join-Path $cur 'port\HybridHeavenRecomp'))){$cur=Split-Path $cur -Parent}; if($cur){$cur}else{'NONE'}"`) do set "ROOT=%%d"
if "%ROOT%"=="NONE" (
    echo ERROR: no encuentro la carpeta 'port\HybridHeavenRecomp' hacia arriba desde este .bat.
    echo        Ejecuta el .bat desde cualquier subcarpeta DEL REPO, o ponlo en la raiz del repo.
    goto :err
)
set "PORT=%ROOT%\port\HybridHeavenRecomp"
set "LIB=%PORT%\lib"
set "RT64=%LIB%\rt64"
set "NMR=%LIB%\N64ModernRuntime"
set "PATCH=%ROOT%\port\windows_runtime_changes.patch"

REM --- Commits exactos ---
set "RT64_COMMIT=43373749dac9bbc1b653e6a02aed40a9e1783bed"
set "NMR_BASE=cdf5abb"

echo.
echo === Hybrid Heaven Recomp - build Windows ===
echo Repo root : %ROOT%
echo Port      : %PORT%
echo.

REM ============ 1) lib/rt64 ============
if not exist "%RT64%\CMakeLists.txt" (
    echo [1/4] Clonando lib/rt64 ...
    git clone https://github.com/rt64/rt64.git "%RT64%"
    if errorlevel 1 ( echo ERROR clonando rt64 & goto :err )
) else (
    echo [1/4] lib/rt64 ya existe.
)
pushd "%RT64%"
git checkout %RT64_COMMIT% >nul 2>&1
if errorlevel 1 echo AVISO: no se pudo hacer checkout de %RT64_COMMIT% en rt64
popd

REM ============ 2) lib/N64ModernRuntime ============
if not exist "%NMR%\CMakeLists.txt" (
    echo [2/4] Clonando lib/N64ModernRuntime (recursivo) ...
    git clone --recursive https://github.com/N64Recomp/N64ModernRuntime.git "%NMR%"
    if errorlevel 1 ( echo ERROR clonando N64ModernRuntime & goto :err )
) else (
    echo [2/4] lib/N64ModernRuntime ya existe.
)
pushd "%NMR%"
git checkout %NMR_BASE% >nul 2>&1
git submodule update --init --recursive
echo.
echo [2/4] Aplicando patch de runtime/librecomp ...
if not exist "%PATCH%" (
    echo ERROR: no encuentro el patch: %PATCH%
    echo        (debes tener el repo principal con port/windows_runtime_changes.patch)
    popd & goto :err
)
git apply "%PATCH%"
if errorlevel 1 (
    echo AVISO: git apply fallo (base distinta). Copia a mano los 11 archivos que lista
    echo        el patch en librecomp/ y ultramodern/.
)
popd

REM ============ 3) CMake configure ============
echo.
echo [3/4] Configurando con CMake (Visual Studio 2022 x64) ...
pushd "%PORT%"
cmake -B build -G "Visual Studio 17 2022" -A x64
if errorlevel 1 ( echo ERROR en cmake configure & popd & goto :err )
popd

REM ============ 4) Build ============
echo.
echo [4/4] Compilando HybridHeavenRecomp (Debug) ...
pushd "%PORT%"
cmake --build build --target HybridHeavenRecomp --config Debug
if errorlevel 1 ( echo ERROR en el build & popd & goto :err )
popd

echo.
echo === LISTO ===
echo Exe: %PORT%\build\bin\Debug\Hybrid Heaven Recomp.exe
echo.
echo Falta: copia baserom.us.z64 (16MB USA) junto al .exe y ejecutalo.
echo Logs: boot.log (junto al exe) y %%APPDATA%%\HybridHeavenRecomp\hh.log
echo.
goto :eof

:err
echo.
echo *** Se detuvo con errores. Revisa los mensajes de arriba. ***
exit /b 1
