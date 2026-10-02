@echo off
REM =====================================================================
REM  run_windows_trace.bat - captura de trazas para el bug #14 (veneno/CaC).
REM
REM  El crash ocurre al ENTRAR EN COMBATE: un enemigo ataca a distancia con
REM  veneno. Hay que capturar tres fases: (1) entrada al combate, (2) el
REM  ataque a distancia, (3) el instante del crash.
REM
REM  Uso (doble clic o desde cmd en la raiz del repo):
REM     run_windows_trace.bat           -> perfil COMBATE completo (recomendado)
REM     run_windows_trace.bat light     -> loader + crash (menos pesado)
REM     run_windows_trace.bat crash     -> solo crash/watchdog (comprobar que crashea)
REM     run_windows_trace.bat debug     -> usa build\windows\bin\Debug
REM
REM  Como reproducir (en el juego), en este orden:
REM     1. Ve a un punto donde el siguiente paso sea ENTRAR EN COMBATE
REM        (o EXTRAS > IR A AREA a 3-3).
REM     2. Entra en combate y deja que un enemigo te ataque a distancia con
REM        VENENO (Mira / Alkalurops).
REM     3. Si CRASHEA: el volcado (hh_crash.log + hh_crash_*.bin) se escribe EN
REM        EL INSTANTE; ciérralo cuando quieras, no hay que esperar.
REM        Si NO crashea sino que se CUELGA (pantalla congelada, sin cierre):
REM        espera ~20 s al volcado del watchdog (hh_hang*) y cierra.
REM
REM  Si con la traza completa NO crashea (la instrumentacion cambia el timing),
REM  repite con:  run_windows_trace.bat light   y luego  ... crash
REM
REM  Archivos que quedan junto al .exe (build\windows\bin\Release):
REM     hh_trace_console.log   consola: [LD384] loader, [SETCB], [DISP], [GATE_A], [OVL]...
REM     hh_b280call.log        cadena M10 b280 ([B280CALL]: obj/vi/depth)   (perfil combate)
REM     hh_b280set.log         quien publica el handler 0x8021B280 (contexto+anillo)
REM     hh_venom.log           pila/contexto cuando se escribe 0xFFFF84CD (si llega)
REM     hh_scheddisp.log       dispatcher temporizado ([DISP] handler/target) (perfil combate)
REM     hh_spchk.log           desbalances de pila por funcion                 (perfil combate)
REM     hh_crash.log           motivo + contexto del crash (HH_CRASH_LOG)
REM     hh_crash_*.bin         volcado RDRAM/DMEM en el crash
REM     hh_hang*.log           watchdog si acaba en cuelgue (HH_DIAG)
REM     hh_state.log           estado periodico (HH_DIAG)
REM =====================================================================
setlocal
chcp 65001 >nul

set "PROFILE=combat"
set "CFG=Release"
:parse
if "%~1"=="" goto parsed
if /i "%~1"=="light" set "PROFILE=light"
if /i "%~1"=="crash" set "PROFILE=crash"
if /i "%~1"=="combat" set "PROFILE=combat"
if /i "%~1"=="debug" set "CFG=Debug"
shift
goto parse
:parsed

set "HHBIN=%~dp0build\windows\bin\%CFG%"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0build\windows\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0build\windows\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" (
  echo ERROR: no encuentro "Hybrid Heaven Recomp.exe".
  echo        Compila antes con build_windows_release.bat ^(o _debug^).
  pause
  exit /b 1
)
pushd "%HHBIN%"

REM --- Aparta la pasada anterior (no borra input ni el .pak) ---
if not exist "trace_prev" mkdir "trace_prev" >nul 2>&1
for %%f in (hh_trace_console.log hh_crash*.log hh_crash_*.bin hh_hang*.log hh_state.log hh_b280call.log hh_b280set.log hh_venom.log hh_scheddisp.log hh_spchk.log hh_disp.log) do (
  if exist "%%f" move /y "%%f" "trace_prev\" >nul 2>&1
)

REM --- Comun a todos los perfiles: crash + watchdog ---
set "HH_CRASH_LOG=1"
set "HH_DIAG=1"

REM --- Perfil COMBATE: loader + cadena M10/M55 + puerta M7 + publicacion b280 ---
if /i "%PROFILE%"=="combat" (
  set "HH_TBLTRACE=1"
  set "HH_CHAINTRACE=1"
  set "HH_GATE_A=1"
  set "HH_B280TRACE=1"
  set "HH_FUNC_OWNER=8021B280,8022C7AC,80379410,800058DC"
)
REM --- Perfil LIGHT: solo loader + setter ([SETCB]) ---
if /i "%PROFILE%"=="light" set "HH_TBLTRACE=1"

echo === run_windows_trace (#14 veneno) ===
echo   bin     : %HHBIN%
echo   perfil  : %PROFILE%
echo   HH_CRASH_LOG=1   HH_DIAG=1   HH_TBLTRACE=%HH_TBLTRACE%   HH_CHAINTRACE=%HH_CHAINTRACE%
echo   HH_GATE_A=%HH_GATE_A%   HH_B280TRACE=%HH_B280TRACE%
echo.
echo   Repro: entra en combate y deja que te ataquen a distancia con VENENO.
echo          Si crashea, el volcado se escribe al instante (cierra cuando quieras).
echo          Si se cuelga (sin crash), espera ~20 s al watchdog y cierra.
echo.

"Hybrid Heaven Recomp.exe" > "hh_trace_console.log" 2>&1
echo (exit %ERRORLEVEL%)
echo.
echo Archivos generados:
dir /b hh_trace_console.log hh_crash*.log hh_crash_*.bin hh_hang*.log hh_state.log hh_b280call.log hh_b280set.log hh_venom.log hh_scheddisp.log hh_spchk.log 2>nul
echo.
echo Envia TODOS los anteriores (sobre todo hh_trace_console.log, hh_venom.log y hh_crash*).
popd
pause
