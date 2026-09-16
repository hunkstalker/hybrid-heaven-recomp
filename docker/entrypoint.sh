#!/bin/sh
# Entrypoint del contenedor de ejecucion.
#
#   - CWD = /work; ahi vive el binario y la carpeta rom/ (el port busca la ROM en
#     rom/ junto al binario).
#   - HH_HEADLESS=1 -> Xvfb + lavapipe (sin GPU ni display; para CI/smoke).
#   - En host Linux con GPU: pasa el dispositivo /dev/dri, DISPLAY y monta el socket
#     X11 del sistema (consulta la documentacion de Docker para tu SO).
set -eu

cd /work

BIN="/work/hybrid-heaven-recomp"

if [ "${HH_HEADLESS:-0}" = "1" ]; then
    export SDL_VIDEODRIVER="${SDL_VIDEODRIVER:-x11}"
    if [ -z "${VK_ICD_FILENAMES:-}" ] && [ -f /usr/share/vulkan/icd.d/lvp_icd.x86_64.json ]; then
        export VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json
    fi
    exec xvfb-run -a -s "-screen 0 1280x720x24" "$BIN" "$@"
fi

exec "$BIN" "$@"
