@echo off
REM =====================================================================
REM  Lanzador con WATCHPOINT de RDRAM (diagnostico).
REM  Loguea en hh_watch.log todo acceso de codigo recompilado (y DMA PI) al rango vigilado.
REM  Por defecto vigila el struct del hilo 5 (loader): 0x80059D80 (mira 'create tid=5' en hh_sched.log).
REM  Cambia HH_WATCH_ADDR si hiciera falta.
REM =====================================================================
setlocal

set HH_WATCH_ADDR=0x8024A9A8
set HH_WATCH_SIZE=0x80
REM set HH_WATCH_ADDR=0x80059D80

REM HH_DIAG=1 reactiva los logs always-on (hh_sched/hh_pi/hh_mq/hh_cmds/hh_ovl/hh_rsp).
set HH_DIAG=1

REM Graba los inputs de la sesion (para poder reproducir localmente la secuencia del NPC).
set HH_RECORD=hh_replay_npc.txt

if /i "%~1"=="noaudio" set HH_NOAUDIO=1
if /i "%~2"=="noaudio" set HH_NOAUDIO=1

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
cd /d "%HHBIN%"
echo === Hybrid Heaven Recomp (WATCH %HH_WATCH_ADDR%) ===
"Hybrid Heaven Recomp.exe" %3 %4
echo (exit %ERRORLEVEL%)
pause
