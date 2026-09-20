@echo off
REM =====================================================================
REM  run_fix57.bat - CaC en vivo CON el fichero 57 (combate) recompilado.
REM
REM  Contexto: la extraccion inicial solo tomaba 11 modulos de la tabla
REM  Nisitenma (625 entradas); faltaba el indice 56 = FICHERO 57 (combate),
REM  que se carga con el loader STREAMED FUN_80004838. Sin el, 0x80379410
REM  resolvia a M55_FUN_80379410 (mid-funcion del fichero 56, exploracion)
REM  -> fuga de pila -> corrupcion del nodo 0x8005BF14 -> deadlock.
REM
REM  Este bat prueba el arreglo DE RAIZ: NO usa HH_M55SPFIX (parche runtime).
REM  Activa HH_TBLTRACE para ver [STREAM] (registro del fichero 57).
REM
REM  USO: doble clic; cargar partida justo antes del CaC; jugar. Logs en
REM  logs_fix57_<fecha>\.
REM
REM  ANTES: port\build_windows.local.bat (runtime + RecompiledFuncs nuevos).
REM  Detalle: notes/2026-09-20-nodo-8005bf14-origen-y-captura.md.
REM =====================================================================
setlocal enabledelayedexpansion
chcp 65001 >nul

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" goto :nobin

cd /d "%HHBIN%"
if not exist "rom\baserom.us.z64" if not exist "baserom.us.z64" (
  echo AVISO: no veo la ROM. Ponla en "%HHBIN%\rom\baserom.us.z64".
)

if exist "logs_prev" del /q "logs_prev\*" >nul 2>&1
if not exist "logs_prev" mkdir "logs_prev" >nul 2>&1
move /y "hh_*.log" "logs_prev\" >nul 2>&1

for /f "usebackq delims=" %%t in (`powershell -NoProfile -Command "Get-Date -Format yyyyMMdd_HHmmss"`) do set "STAMP=%%t"
set "DEST=%HHBIN%\logs_fix57_%STAMP%"
mkdir "%DEST%" >nul 2>&1

echo =====================================================================
echo  CaC en vivo - fichero 57 recompilado (arreglo de raiz, SIN HH_M55SPFIX)
echo =====================================================================
echo  bin    : %HHBIN%
echo  logs   : %DEST%
echo.
echo  Carga partida antes del CaC. Al colgarse, espera 20-30 s y cierra.
echo.

set "HH_CHAINTRACE=1"
set "HH_TBLTRACE=1"
set "HH_STATE_SECS=5"
set "HH_HANG_SECS=10"
REM Sin HH_M55SPFIX a proposito: queremos ver si el fichero 57 lo resuelve solo.

"Hybrid Heaven Recomp.exe"
set "RC=%ERRORLEVEL%"

move /y "hh_*.log" "%DEST%" >nul 2>&1
move /y "hh_hang_rdram_*.bin" "%DEST%" >nul 2>&1

echo.
echo === Pasada guardada en: %DEST%  (exit %RC%)
echo.
echo Clave: [STREAM] id=57 -> registrar src=69E416 en la consola; sin [BADMQ];
echo        el nodo 0x8005BF14 no debe corromperse; deberia avanzar el combate.
echo.
pause
goto :eof

:nobin
echo ERROR: no encuentro "Hybrid Heaven Recomp.exe".
echo        Compila antes con port\build_windows.local.bat
pause
exit /b 1
