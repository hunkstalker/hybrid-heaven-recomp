@echo off
REM =====================================================================
REM  TRAZA del menu NATIVO de GUARDADO en capsula (DATA SAVE).
REM
REM  Objetivo: confirmar en runtime que funcion(es) se disparan al
REM  entrar en una capsula de guardado y decir que SI. La maqueta 1:1
REM  se replicara encima; para eso hay que enganchar el update nativo.
REM
REM  Hallazgo [MEDIDO estatico] del C recompilado:
REM    func_80377140  -> setup del menu (llama a func_8013EA94)
REM    func_8013EA94  -> compone DATA SAVE (via func_80142778)
REM    func_803771A4  -> UPDATE/callback del menu de guardado
REM    func_8013EB2C  -> maquina de estado de guardado
REM    func_80142778  -> composer del titulo "DATA SAVE" + CONTROLLER PAK
REM    func_80141268  -> flujo GUARDAR
REM    func_80142450  -> guardar slot
REM    func_80141F28  -> serializar
REM    func_80142350  -> escribir cabecera del save
REM
REM  HH_TRACE (runtime) vuelca cada llamada de esas funciones a hh_trace.log
REM  con a0..a1/ra/sp. HH_MENU_TRACE registra ademas los cambios de pantalla
REM  (func_800058DC) con su target: ahi debe verse el callback 0x803771A4.
REM
REM  PROTOCOLO:
REM    1) Entra en una PARTIDA (gameplay).
REM    2) Ve a una capsula de guardado y pulsa que SI quieres guardar.
REM    3) Deja que salga la UI de DATA SAVE, elige slot y confirma si quieres.
REM    4) Cierra el juego y envia hh_trace.log (y hh.log).
REM =====================================================================
setlocal

set "HHBIN=%~dp0build\windows\bin\Release"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" set "HHBIN=%~dp0build\windows\bin\Debug"
if not exist "%HHBIN%\Hybrid Heaven Recomp.exe" (
  echo ERROR: no existe "Hybrid Heaven Recomp.exe". Compila con build_windows_release.bat.
  pause
  exit /b 1
)

cd /d "%HHBIN%"

REM Funciones candidatas del flujo DATA SAVE (max 16). Etiquetas legibles.
set "HH_TRACE=0x80377140:SAVE_setup,0x803771A4:SAVE_update,0x80377478:SAVE_next,0x8013EA94:SAVE_compose,0x8013EB2C:SAVE_state,0x80142778:SAVE_title,0x80141268:SAVE_flow,0x80142450:SAVE_slot,0x80141F28:SAVE_serialize,0x80142350:SAVE_header"
REM Cambios de pantalla (func_800058DC) con target/obj: debe salir 0x803771A4.
set "HH_MENU_TRACE=1"

del /q hh_trace.log 2>nul

echo === Hybrid Heaven Recomp - TRAZA DATA SAVE (capsula) ===
echo Config : %HHBIN%
echo HH_TRACE        : %HH_TRACE%
echo HH_MENU_TRACE   : %HH_MENU_TRACE%
echo.
echo  1) Entra en partida (gameplay).
echo  2) Ve a una capsula de guardado y di que SI.
echo  3) Deja salir el DATA SAVE nativo.
echo  4) Cierra y envia hh_trace.log (y hh.log).
echo.
"Hybrid Heaven Recomp.exe" 2> hh_save_stderr.log
echo (exit %ERRORLEVEL%)
echo.
echo Log: %HHBIN%\hh_trace.log
pause
