@echo off
REM =====================================================================
REM  Hybrid Heaven Recomp - Build para Windows
REM  Si lib\rt64 y lib\N64ModernRuntime ya existen, NO hace git (evita
REM  cuelgues sobre unidades montadas) y compila directamente.
REM  Runtime: clon del FORK propio (rama hybrid-heaven) en el commit fijado en
REM  runtime.lock. rt64: upstream en su commit fijo. Creditos: CREDITS.md.
REM  Uso:
REM    build_windows.bat                 Release (recomendado: 3-5x mas rapido)
REM    build_windows.bat --debug         -> Debug (solo para diagnosticar crashes)
REM    build_windows.bat --force-libs    -> clonar/actualizar libs antes
REM  Accesos directos: build_windows_release.bat / build_windows_debug.bat (doble clic).
REM =====================================================================
setlocal enabledelayedexpansion
chcp 65001 >nul
set "GIT_TERMINAL_PROMPT=0"

set "FORCE_LIBS=0"
set "BUILDCFG=Release"
if /i "%~1"=="--force-libs" set "FORCE_LIBS=1"
if /i "%~1"=="--debug" set "BUILDCFG=Debug"
if /i "%~2"=="--debug" set "BUILDCFG=Debug"

REM --- Detectar la raiz del repo (busca 'src\platform' hacia arriba) ---
set "ROOT="
for /f "usebackq delims=" %%d in (`powershell -NoProfile -Command "$cur='%~dp0'; while($cur -and -not (Test-Path (Join-Path $cur 'src\platform'))){$cur=Split-Path $cur -Parent}; if($cur){$cur}else{'NONE'}"`) do set "ROOT=%%d"
if "%ROOT%"=="NONE" (
    echo ERROR: no encuentro 'src\platform' hacia arriba desde este .bat.
    goto :err
)
set "PORT=%ROOT%"
set "RT64=%PORT%\lib\rt64"
set "NMR=%PORT%\lib\N64ModernRuntime"
set "RT64_COMMIT=43373749dac9bbc1b653e6a02aed40a9e1783bed"

REM --- URL/SHA del runtime desde runtime.lock ---
set "NMR_URL="
set "NMR_COMMIT="
if exist "%ROOT%\runtime.lock" for /f "usebackq tokens=1,* delims==" %%a in ("%ROOT%\runtime.lock") do (
    if /i "%%a"=="NMR_URL" set "NMR_URL=%%b"
    if /i "%%a"=="NMR_COMMIT" set "NMR_COMMIT=%%b"
)
if not defined NMR_URL (
    echo ERROR: falta NMR_URL en %ROOT%\runtime.lock
    goto :err
)
if not defined NMR_COMMIT (
    echo ERROR: falta NMR_COMMIT en %ROOT%\runtime.lock
    goto :err
)

echo.
echo === Hybrid Heaven Recomp - build Windows ===
echo Repo root : %ROOT%
echo Port      : %PORT%
echo.

set "SKIP_LIBS=0"
REM --- Submodulos (lib/N64ModernRuntime, lib/rt64): forma estandar del ecosistema. Best-effort:
REM     si falta lib/ y aun no estan publicados los commits del fork, se cae al clonado por
REM     runtime.lock de abajo. El build local del mantenedor (build_windows.local.bat) ni entra aqui.
if not exist "%RT64%\CMakeLists.txt" git -c safe.directory=* -C "%ROOT%" submodule update --init --recursive 2>nul
if not exist "%NMR%\CMakeLists.txt" git -c safe.directory=* -C "%ROOT%" submodule update --init --recursive 2>nul
if exist "%RT64%\CMakeLists.txt" if exist "%NMR%\CMakeLists.txt" if "%FORCE_LIBS%"=="0" set "SKIP_LIBS=1"

if "%SKIP_LIBS%"=="1" goto :libs_ok

REM ============ 1) lib/rt64 ============
if exist "%RT64%\CMakeLists.txt" goto :rt64_present
echo [1/4] Clonando lib/rt64 ...
git clone https://github.com/rt64/rt64.git "%RT64%"
if errorlevel 1 goto :err
goto :rt64_checkout

:rt64_present
echo [1/4] lib/rt64 ya existe. Comprobando repo git ...
if not exist "%RT64%\.git" (
    echo ERROR: %RT64% existe pero NO es un repositorio git.
    echo        Borra la carpeta lib\rt64 y vuelve a ejecutar.
    goto :err
)

:rt64_checkout
pushd "%RT64%"
git -c safe.directory=* checkout %RT64_COMMIT%
if errorlevel 1 echo AVISO: no se pudo hacer checkout de %RT64_COMMIT% en rt64
REM rt64 trae submodulos propios (plume, re-spirv, nativefiledialog-extended, zstd...)
git -c safe.directory=* submodule sync --recursive
git -c safe.directory=* submodule update --init --recursive
popd

:step2
REM ============ 2) lib/N64ModernRuntime (fork propio, commit fijado) ============
if exist "%NMR%\CMakeLists.txt" goto :nmr_present
echo [2/4] Clonando lib/N64ModernRuntime (fork) ...
git clone "%NMR_URL%" "%NMR%"
if errorlevel 1 goto :err
pushd "%NMR%"
git -c safe.directory=* checkout %NMR_COMMIT%
if errorlevel 1 goto :err_nmr_commit
git -c safe.directory=* submodule sync --recursive
git -c safe.directory=* submodule update --init --recursive
popd
goto :cmake

:err_nmr_commit
echo.
echo ERROR: no se pudo hacer checkout de %NMR_COMMIT% en N64ModernRuntime.
echo        Ese commit no esta en el clon: publica el fork ^(git push fork hybrid-heaven^)
echo        o corrige NMR_COMMIT en runtime.lock. Se aborta para no compilar un runtime
echo        distinto al fijado.
popd
goto :err

:nmr_present
echo [2/4] lib/N64ModernRuntime ya existe. Comprobando repo git ...
if not exist "%NMR%\.git" (
    echo ERROR: %NMR% existe pero NO es un repositorio git.
    echo        Borra la carpeta lib\N64ModernRuntime y vuelve a ejecutar.
    goto :err
)
pushd "%NMR%"
git -c safe.directory=* fetch --all --quiet
git -c safe.directory=* checkout %NMR_COMMIT%
if errorlevel 1 goto :err_nmr_commit
git -c safe.directory=* submodule sync --recursive
git -c safe.directory=* submodule update --init --recursive
popd
goto :cmake

:libs_ok
echo [1-2/4] lib\rt64 y lib\N64ModernRuntime ya existen: se OMITE git.
echo          Usa --force-libs si quieres clonar/actualizar.

:cmake
REM --- Traza del runtime que se va a compilar (siempre) ---
set "NMR_USED=desconocido (no es repo git)"
if exist "%NMR%\.git" (
    for /f "usebackq delims=" %%s in (`git -c safe.directory=* -C "%NMR%" rev-parse --short HEAD 2^>nul`) do set "NMR_USED=%%s"
)
if "%SKIP_LIBS%"=="1" (set "GIT_NOTE=arbol local, git OMITIDO") else (set "GIT_NOTE=git revisado/clonado")
echo Runtime   : %NMR%  @ %NMR_USED%
echo             pin    : %NMR_URL% @ %NMR_COMMIT%
echo             modo   : %GIT_NOTE%
echo.

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
cmake -B build\windows -G "%VSGEN%" -A x64
if errorlevel 1 goto :err
popd

REM ============ 4) Build ============
echo.
echo [4/4] Compilando HybridHeavenRecomp (%BUILDCFG%) ...
echo       (Release es 3-5x mas rapido que Debug: sin optimizar el juego cae a 30fps
echo        y el hilo de audio solo produce la mitad de buffers: petardeo)
pushd "%PORT%"
cmake --build build\windows --target HybridHeavenRecomp --config %BUILDCFG%
if errorlevel 1 goto :err
popd

echo.
echo === LISTO ===
echo Exe: %PORT%\build\windows\bin\%BUILDCFG%\Hybrid Heaven Recomp.exe
echo Pon la ROM en la carpeta rom junto al .exe: build\windows\bin\%BUILDCFG%\rom\baserom.us.z64
echo (tambien se acepta baserom.us.z64 junto al .exe como salvaguarda).
echo.
if not defined CI pause
goto :eof

:err
echo.
echo *** Se detuvo con errores. Revisa los mensajes de arriba. ***
if not defined CI pause
exit /b 1
