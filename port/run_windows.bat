@echo off
REM =====================================================================
REM  Lanzador del port (doble clic). Graba tu partida automaticamente en
REM  hybrid-heaven-recomp\tests\mi_partida.txt para poder reproducir el
REM  crash. No hace falta configurar nada.
REM =====================================================================
setlocal

REM Log de entrada (botones + ejes):
set HH_INPUTLOG=1

REM Grabar la partida (descomenta SOLO si te pido una grabacion; el fichero crece mucho):
REM set HH_RECORD=%~dp0..\tests\mi_partida.txt

REM Eje Y: el default ya es correcto. Descomenta solo si lo notases invertido:
REM set HH_INVERT_Y=1

REM Audio: descomenta para forzar modo sin dispositivo (aislar crashes de audio):
REM set HH_NOAUDIO=1

REM Resolucion (default auto = escalado entero a la ventana):
REM set HH_RES=2x

cd /d "%~dp0HybridHeavenRecomp\build_win\bin\Debug"
echo === Hybrid Heaven Recomp ===
echo Grabando input en: %HH_RECORD%
"Hybrid Heaven Recomp.exe" %*
echo (exit %ERRORLEVEL%)
pause
