#!/usr/bin/env sh
# Wrapper de splat usando el venv de desarrollo (toolchain/splat-venv).
# Requiere haber ejecutado tools/install_splat.sh una vez.
#
# Uso:  tools/splat_headless.sh split recomp/hybrid-heaven.us.yaml
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
VENV="$ROOT/toolchain/splat-venv"

if [ ! -x "$VENV/bin/python" ]; then
    echo "[splat] falta $VENV. Ejecuta tools/install_splat.sh." >&2
    exit 1
fi

exec "$VENV/bin/python" -m splat "$@"
