@echo off
REM =====================================================================
REM  Lanzador con traza COMPLETA de colas de mensajes (diagnostico del cuelgue de dano).
REM  Escribe hh_mq_all.log: cada osSendMesg/osRecvMesg (tid guest, cola, mensaje) y cada
REM  osSetEventMesg (registro de eventos VI/AI/DP/SP).
REM  Tambien graba los inputs (hh_replay_dmg.txt) por si hay que reproducirlo localmente.
REM =====================================================================
setlocal

set HH_MQLOG_ALL=1
set HH_RECORD=hh_replay_dmg.txt

if /i "%~1"=="noaudio" set HH_NOAUDIO=1

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
cd /d "%HHBIN%"
echo === Hybrid Heaven Recomp (MQLOG_ALL) ===
"Hybrid Heaven Recomp.exe" %2 %3
echo (exit %ERRORLEVEL%)
pause
