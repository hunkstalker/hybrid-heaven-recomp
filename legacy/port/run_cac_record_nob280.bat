@echo off
REM =====================================================================
REM  run_cac_record_nob280.bat - GRABA el input con HH_NO_B280=1.
REM  DOBLE CLIC, sin flags.
REM
REM  Por que: con el save avanzado, grabar SIN nob280 se congela en el
REM  sitio de siempre (veneno). Para capturar el paron NUEVO (se para la
REM  logica al entrar en la pelea) hay que grabar con HH_NO_B280=1.
REM
REM  Que hacer:
REM    1) Carga el save avanzado.
REM    2) Avanza hasta la pelea hasta que se pare/crashee.
REM    3) Cierra la ventana.
REM
REM  Resultado en port\...\build_win\bin\Release\logs_pacing_<fecha>\:
REM    - cac_rec.txt   (input por tick, para reproducir headless con nob280)
REM    - hh_state.log (con anillos y [STATE] trans), hh_crash.log si lo hay
REM
REM  Ese cac_rec.txt se reproduce en dev con:
REM    HH_REPLAY=cac_rec.txt HH_REPLAY_MODE=poll HH_NO_B280=1
REM
REM  ANTES: recompila con port\build_windows.local.bat.
REM =====================================================================
setlocal
chcp 65001 >nul
set "HH_NO_B280=1"
echo === Grabando input con HH_NO_B280=1 (via run_pacing record) ...
echo.
call "%~dp0run_pacing.bat" record
endlocal
