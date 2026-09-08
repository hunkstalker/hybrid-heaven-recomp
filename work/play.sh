#!/bin/sh
# Hybrid Heaven - session de captura con ventana. Usted juega con el teclado;
# el write-breakpoint captura automaticamente el directorio de overlays (ids+base)
# cada vez que el juego registra un recurso nuevo.
#
# Controles (mupen64plus-input-sdl, ya configurado):
#   DPad:  WASD          C buttons: IJKL
#   Start: Enter         R: c   L: x   Z: z
#   B:     (mouse izq, key 306)   A: (mouse der, key 304)  <- ajustar en
#   /root/.config/mupen64plus/mupen64plus.cfg -> [Input-SDL-Control1] si no responde
#
# Uso:
#   work/play.sh [segundos] [prefijo_salida]
#   (necesita $DISPLAY con GLX; la ventana es de 640x480 ampliable)
#
# Salidas (dir. = prefijo):
#   <prefijo>.dir.bin   ultima foto de 1KB del directorio (0x8DFC0, word-swapped)
#   <prefijo>.tN.bin    dumps RDRAM completos en los tiempos configurados
#   <prefijo>           dump final
#   stderr: lineas "[dbg] stop pc=... valid=YES ... loader pc=..." por cada carga

export CORE_SO=/app/work/libmupen64plus-debug.so
export RSP_PLUGIN=/usr/lib/mupen64plus/mupen64plus-rsp-hle.so
export INPUT_PLUGIN=/usr/lib/mupen64plus/mupen64plus-input-sdl.so
export VIDEO_PLUGIN=/usr/lib/mupen64plus/mupen64plus-video-glide64mk2.so
export AUDIO_PLUGIN=/usr/lib/mupen64plus/mupen64plus-audio-sdl.so
export HB_RES_DIR=0x8008DFC0
export HH_DUMP_TIMES=5,10,20,40,80

SECS="${1:-120}"
OUT="${2:-/app/work/scratch/live}"
echo "> Hybrid Heaven session: ${SECS}s -> ${OUT}  (Ctrl-C para salir antes)"
mkdir -p /app/work/scratch
exec /app/work/r64dump /app/work/roms/us_dec.z64 "$OUT" "$SECS" 2>&1 | tee "${OUT}.session.log"