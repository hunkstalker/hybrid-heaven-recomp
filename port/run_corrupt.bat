@echo off
REM =====================================================================
REM  Capa de debug "quien corrompe" (instrumentacion opt-in; ver recomp.cpp).
REM    HH_DRWATCH : watchpoint de HARDWARE (Windows) sobre palabras concretas:
REM                 para en la instruccion exacta que las escribe (host RIP,
REM                 backtrace, registros guest) -> hh_drwatch.log
REM    HH_CANARY  : vigilancia del buffer RDRAM por frame; caza escrituras que
REM                 NO pasan por los MEM_* (do_send/DMA/...) -> hh_canary.log
REM    HH_WATCH   : traza de accesos de codigo recompilado (MEM_*) a +0x1C -> hh_watch.log
REM  En el primer golpe del DR se vuelca RDRAM a hh_drwatch_rdram.bin.
REM  Todos los ficheros quedan junto al .exe.
REM =====================================================================
setlocal

REM Objeto state-machine (direccion varia por partida) + globales. DR = palabras exactas;
REM CANARY = objeto (por si es 0x8024A990), cola, modo y flag 0x8017DD92 (guarda del disable).
REM DR desactivado (daba falsos positivos: disparaba en lecturas). CANARY = objeto (por si es
REM 0x8024A990), cola, modo y flag 0x8017DD90/0x8017DD92 (guarda del disable).
set HH_DRWATCH=
set HH_CANARY=0x8024A98C:0xA0,0x801BBC1C:0x08,0x8017DD90:0x08,0x801CC8C4:0x04
set HH_WATCH_ADDR=0x8024A9AC
set HH_WATCH_SIZE=4

REM Traza: funciones clave + RANGO del modulo 23 + el selector de estado (M23_FUN_801c1dc0).
set HH_TRACE=0x80005270:disp,0x802408F0:armer,0x800058DC:setter,0x80379410:M55,0x8021B280:M10_1b280,0x8022C7AC:M10_2c7ac,0x80223260:M10_32260,0x80152CF8:flagSet,0x801C1DC0:M23_sel
set HH_TRACE_RANGE=0x801BF1A0:0x9000

REM Graba los inputs por si hay que reproducir el tramo.
set HH_RECORD=hh_replay_fight.txt
set HH_INPUTLOG=1

if /i "%~1"=="noaudio" set HH_NOAUDIO=1
if /i "%~2"=="noaudio" set HH_NOAUDIO=1

set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0HybridHeavenRecomp\build_win\bin\Debug"
cd /d "%HHBIN%"
echo === Hybrid Heaven Recomp (CORRUPT WATCH) ===
echo DRWATCH=%HH_DRWATCH%  CANARY=%HH_CANARY%
"Hybrid Heaven Recomp.exe" %3 %4
echo (exit %ERRORLEVEL%)
pause
