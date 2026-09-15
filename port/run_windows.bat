@echo off
REM =====================================================================
REM  Lanzador del port con variables de entorno (edita esta zona).
REM  Ejecuta este .bat: las variables se definen en ESTA consola y por
REM  tanto el .exe las hereda (no vale setearlas en otra ventana).
REM =====================================================================
setlocal

REM Eje Y del mando: por DEFECTO ya es correcto (arriba=arriba). Solo si lo notases
REM invertido, descomenta la siguiente linea para flipearlo.
REM set HH_INVERT_Y=1

REM Resolucion de render: auto (default) | original | 2x | 3x | 4x ...
REM set HH_RES=2x

REM Log de entrada (botones + ejes del mando) para diagnosticar el mapeo:
set HH_INPUTLOG=1

REM Grabar la partida a un fichero (para depurar el crash reproducible). Ruta absoluta
REM junto a la raiz del repo: <repo>\mi_partida.txt. Descomenta para grabar.
REM set HH_RECORD=%~dp0mi_partida.txt

cd /d "%~dp0HybridHeavenRecomp\build_win\bin\Debug"
echo === Hybrid Heaven Recomp (HH_INVERT_Y=%HH_INVERT_Y% HH_RES=%HH_RES% HH_INPUTLOG=%HH_INPUTLOG%) ===
if defined HH_RECORD echo Grabando input en: %HH_RECORD%
"Hybrid Heaven Recomp.exe" %*
echo (exit %ERRORLEVEL%)
pause
