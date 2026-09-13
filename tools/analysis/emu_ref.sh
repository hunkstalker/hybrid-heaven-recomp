#!/bin/sh
# Referencia de emulador que SÍ progresa (equivalente a BizHawk):
#   4 MB (DisableExtraMem=1 en work/debug/mupencfg/mupen64plus.cfg)
#   + input (hhinput.so)
#   + RSP HLE (mupen64plus-rsp-hle.so)
#   + vídeo real (mupen64plus-video-rice.so) sobre Xvfb :99 con GLX
#
# El vídeo real es imprescindible: sin RDP el juego se queda en la tabla 800F41C0.
# Requiere Xvfb :99 con GLX (ver AGENTS.md: mesa-dri-gallium) y libsamplerate.
#
# Uso: emu_ref.sh <out_prefix> <segundos> [dumps_csv]
#   emu_ref.sh work/debug/emu_ref 60 30,60
set -e
cd /app/hybrid-heaven-recomp

PREFIX="$1"
SECS="${2:-60}"
DUMPS="${3:-30,60}"

DISPLAY=:99 \
LIBGL_ALWAYS_SOFTWARE=1 \
SDL_AUDIODRIVER=dummy \
CORE_SO=work/libmupen64plus-debug.so \
VIDEO_PLUGIN=work/wsl_package/plugins/mupen64plus-video-rice.so \
INPUT_PLUGIN=work/hhinput.so \
RSP_PLUGIN=work/wsl_package/plugins/mupen64plus-rsp-hle.so \
HH_DUMP_TIMES="$DUMPS" \
timeout $((SECS + 5)) ./work/r64dump work/roms/us_retail.z64 "$PREFIX" "$SECS"
