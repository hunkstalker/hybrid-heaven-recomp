@echo off
REM =====================================================================
REM  Captura de SUBIDAS DE STATS EN COMBATE.
REM  El struct 0x8017DC40 es el buffer del save (solo se vuelca al guardar);
REM  el estado vivo y las subidas estan en el modulo de batalla file_057
REM  (0x80358820..0x8038CFC0). Aqui trazamos esas funciones y detectamos
REM  cambios en el registro del personaje y en los structs de party.
REM
REM  Instrumentacion (solo Windows): lib/N64ModernRuntime/librecomp/src/recomp.cpp
REM    HH_TRACE    -> hh_trace.log    (llamadas a funciones clave + a0 = struct vivo)
REM    HH_CANARY   -> hh_canary.log   (cambio de CUALQUIER palabra de un rango, por VI)
REM    HH_DRWATCH  -> hh_drwatch.log  (watchpoints de hardware: PC/call ring exactos)
REM
REM  USO (sesion CORTA: entrar en partida y hacer 1-2 combates, luego cerrar):
REM     run_stats_capture.bat [set] [release|debug]
REM        set = combat (por defecto) | live | stats | counters
REM =====================================================================
setlocal

REM --- Argumentos en cualquier orden: set y/o config ---
set "SETNAME="
set "HHCFG="
for %%A in (%*) do (
  if /i "%%A"=="combat"   set "SETNAME=combat"
  if /i "%%A"=="live"     set "SETNAME=live"
  if /i "%%A"=="stats"    set "SETNAME=stats"
  if /i "%%A"=="counters" set "SETNAME=counters"
  if /i "%%A"=="release"  set "HHCFG=Release"
  if /i "%%A"=="debug"    set "HHCFG=Debug"
)
if not defined SETNAME set "SETNAME=combat"

REM --- Funciones de combate a trazar (16 max). El a0 que sale en el log = struct vivo. ---
set "HH_TRACE=0x803840A4:battle_end,0x80376D48:hpdist,0x80376D10:hpdist_h,0x80376F84:st_76F84,0x8037865C:level,0x80378F64:cnt2stat,0x80378D84:partlv8,0x80378E3C:partval16,0x80387A20:statgain,0x8022CAFC:compose,0x80232820:composed,0x80379970:hp_79970,0x80379F04:hp_79F04,0x8037A6F4:hp_A6F4,0x8037AEA8:hp_AEA8,0x8037B118:hp_B118"

if /i "%SETNAME%"=="combat" (
  REM Registro del personaje entero (0x9E B): HP, nivel/progreso, contadores y stats.
  set "HH_CANARY=0x8017DC40:9E,0x801BC03C:9E,0x801BC3D8:9E"
  set "HH_DRWATCH=0x8017DC40,0x8017DC44,0x8017DC50,0x8017DC5C"
)
if /i "%SETNAME%"=="live" (
  set "HH_CANARY=0x801BC03C:9E,0x801BC3D8:9E,0x8017DC40:9E"
  set "HH_DRWATCH=0x801BC03C,0x801BC3D8,0x801BC088,0x801BC424"
)
if /i "%SETNAME%"=="stats" (
  set "HH_CANARY=0x8017DC40:9E"
  set "HH_DRWATCH=0x8017DC40,0x8017DC80,0x8017DC84,0x8017DC88"
)
if /i "%SETNAME%"=="counters" (
  set "HH_CANARY=0x8017DC40:9E"
  set "HH_DRWATCH=0x8017DC50,0x8017DC5C,0x8017DC60,0x8017DC64"
)
if not defined HH_CANARY (
  echo ERROR: set desconocido "%SETNAME%" ^(usa: combat ^| live ^| stats ^| counters^)
  pause
  exit /b 1
)

REM --- Build: Release si existe, si no Debug (igual que run_windows.bat) ---
set "HHBIN=%~dp0build\windows\bin\Release"
set "HHCFGNAME=Release"
if /i "%HHCFG%"=="Debug" (
  set "HHBIN=%~dp0build\windows\bin\Debug"
  set "HHCFGNAME=Debug"
) else if not defined HHCFG if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" (
  set "HHBIN=%~dp0build\windows\bin\Debug"
  set "HHCFGNAME=Debug"
)

if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" (
  echo ERROR: no existe "%HHBIN%\Hybrid Heaven Recomp.exe".
  echo        Compila con build_windows_release.bat o build_windows_debug.bat.
  pause
  exit /b 1
)

cd /d "%HHBIN%"
del /q hh_drwatch.log hh_drwatch_rdram.bin hh_trace.log hh_canary.log hh_capture_stderr.log 2>nul

echo === Hybrid Heaven Recomp - CAPTURA DE STATS EN COMBATE ===
echo Config   : %HHCFGNAME%  (%HHBIN%)
echo Set      : %SETNAME%
echo HH_CANARY=%HH_CANARY%
echo HH_DRWATCH=%HH_DRWATCH%
echo HH_TRACE =%HH_TRACE%
echo.
echo Entra en partida y haz 1-2 COMBATES (que suban stats). Cierra al terminar.
echo.
"Hybrid Heaven Recomp.exe" 2> hh_capture_stderr.log
echo (exit %ERRORLEVEL%)
echo.
echo TRACE   : %HHBIN%\hh_trace.log
echo CANARY  : %HHBIN%\hh_canary.log
echo DRWATCH : %HHBIN%\hh_drwatch.log
echo RDRAM   : %HHBIN%\hh_drwatch_rdram.bin
echo Consola : %HHBIN%\hh_capture_stderr.log
pause
