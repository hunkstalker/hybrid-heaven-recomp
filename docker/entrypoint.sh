#!/bin/sh
# Entrypoint del contenedor de ejecucion.
#
#   - CWD = /work (monta ahi baserom.us.z64; el port busca la ROM junto al
#     binario o en el working directory).
#   - HH_HEADLESS=1 -> Xvfb + lavapipe (sin GPU ni display; para CI/smoke).
#   - En host Linux con GPU: --device /dev/dri -e DISPLAY -v /tmp/.X11-unix.
set -eu

cd /work

BIN="/usr/local/bin/hybrid-heaven-recomp"

if [ "${HH_HEADLESS:-0}" = "1" ]; then
    export SDL_VIDEODRIVER="${SDL_VIDEODRIVER:-x11}"
    if [ -z "${VK_ICD_FILENAMES:-}" ] && [ -f /usr/share/vulkan/icd.d/lvp_icd.x86_64.json ]; then
        export VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json
    fi
    exec xvfb-run -a -s "-screen 0 1280x720x24" "$BIN" "$@"
fi

exec "$BIN" "$@"
