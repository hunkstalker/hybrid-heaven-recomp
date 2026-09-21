#!/bin/sh
# build_linux.sh — receta canonica de build del port en Linux (espejo de port/build_windows.bat).
# Reproduce las dependencias que no viven en este repo (gitignored):
#
#   1) lib/rt64: clon de upstream en un commit fijo (sin modificar)
#   2) lib/N64ModernRuntime: clon del FORK propio (rama hybrid-heaven) en un commit fijo,
#      con sus submodulos recursivos (N64Recomp sale del fork propio; thirdparty de upstream)
#   3) configura y compila con CMake
#
# URL/SHA del runtime: port/runtime.lock (env NMR_URL / NMR_COMMIT los sobreescriben).
# Antes de compilar hay que regenerar el C recompilado desde TU ROM (no se versiona; ADR 0009):
#   python3 tools/regenerate.py        (una vez; requiere JDK 21 + Ghidra + N64Recomp)
# La ROM tambien hace falta para EJECUTAR: ponla en la carpeta rom/ junto al binario
# (rom/baserom.us.z64); tambien se acepta baserom.us.z64 junto al binario como salvaguarda.
#
# Uso:
#   tools/build_linux.sh [--force-libs] [--debug] [--build-dir DIR]
#                        [--jobs N] [--configure-only] [--libs-only]
#
# Dependencias (Debian/Ubuntu):
#   build-essential cmake ninja-build git pkg-config
#   libsdl2-dev libvulkan-dev libx11-dev libxext-dev libxrandr-dev libxtst-dev libgtk-3-dev
set -eu

RT64_URL="${RT64_URL:-https://github.com/rt64/rt64.git}"
RT64_COMMIT="${RT64_COMMIT:-43373749dac9bbc1b653e6a02aed40a9e1783bed}"

FORCE_LIBS=0
BUILD_TYPE=Release
BUILD_DIR=build_linux
JOBS=""
CONFIGURE_ONLY=0
LIBS_ONLY=0

usage() {
    awk 'NR>1 && /^set -eu/{exit} NR>1{sub(/^# ?/,""); print}' "$0"
}

while [ "$#" -gt 0 ]; do
    case "$1" in
        --force-libs)     FORCE_LIBS=1 ;;
        --debug)          BUILD_TYPE=Debug ;;
        --build-dir)      shift; BUILD_DIR="${1:?--build-dir necesita un valor}" ;;
        --jobs)           shift; JOBS="${1:?--jobs necesita un valor}" ;;
        --configure-only) CONFIGURE_ONLY=1 ;;
        --libs-only)      LIBS_ONLY=1 ;;
        -h|--help)        usage; exit 0 ;;
        *) echo "ERROR: opcion desconocida: $1" >&2; usage >&2; exit 2 ;;
    esac
    shift
done

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
PORT="$ROOT/port/HybridHeavenRecomp"
RT64="$PORT/lib/rt64"
NMR="$PORT/lib/N64ModernRuntime"
LOCK="$ROOT/port/runtime.lock"

if [ "$LIBS_ONLY" = 0 ] && [ ! -d "$PORT" ]; then
    echo "ERROR: no encuentro $PORT" >&2; exit 1
fi
mkdir -p "$PORT/lib"

# --- URL/SHA del runtime: env > port/runtime.lock ---
NMR_URL="${NMR_URL:-}"
NMR_COMMIT="${NMR_COMMIT:-}"
if [ -f "$LOCK" ]; then
    [ -n "$NMR_URL" ]    || NMR_URL=$(grep -E '^NMR_URL=' "$LOCK" | head -1 | cut -d= -f2-)
    [ -n "$NMR_COMMIT" ] || NMR_COMMIT=$(grep -E '^NMR_COMMIT=' "$LOCK" | head -1 | cut -d= -f2-)
fi
[ -n "$NMR_URL" ] || { echo "ERROR: falta NMR_URL (en $LOCK o por entorno)." >&2; exit 1; }
[ -n "$NMR_COMMIT" ] || { echo "ERROR: falta NMR_COMMIT (en $LOCK o por entorno)." >&2; exit 1; }

# git sobre unidades montadas: evitar 'dubious ownership'
gitc() { _d="$1"; shift; git -c "safe.directory=*" -C "$_d" "$@"; }

setup_rt64() {
    # Forma estandar: submódulo del superproyecto. Best-effort; si falla (p.ej. commit aun sin
    # publicar) se cae al clonado por runtime.lock de abajo.
    if [ ! -e "$RT64/CMakeLists.txt" ]; then
        gitc "$ROOT" submodule update --init --recursive -- port/HybridHeavenRecomp/lib/rt64 2>/dev/null || true
    fi
    if [ ! -e "$RT64/CMakeLists.txt" ]; then
        echo "[1/4] clonando lib/rt64 (fallback runtime.lock) ..."
        git clone --quiet "$RT64_URL" "$RT64"
    fi
    [ -d "$RT64/.git" ] || {
        echo "ERROR: $RT64 existe pero NO es un repositorio git. Borralo y reintenta." >&2; exit 1; }
    if gitc "$RT64" checkout --quiet "$RT64_COMMIT" 2>/dev/null; then
        echo "      rt64 en $RT64_COMMIT"
    else
        echo "AVISO: no se pudo hacer checkout de $RT64_COMMIT en rt64 (se usa el actual)" >&2
    fi
    # rt64 tiene submodulos propios (plume, re-spirv, nativefiledialog-extended, zstd...).
    gitc "$RT64" submodule sync --recursive --quiet
    gitc "$RT64" submodule update --init --recursive --quiet
}

setup_nmr() {
    # Forma estandar: submódulo del superproyecto. Best-effort; si falla (p.ej. commit del fork aun
    # sin publicar) se cae al clonado por runtime.lock de abajo.
    if [ ! -e "$NMR/CMakeLists.txt" ]; then
        gitc "$ROOT" submodule update --init --recursive -- port/HybridHeavenRecomp/lib/N64ModernRuntime 2>/dev/null || true
    fi
    if [ ! -e "$NMR/CMakeLists.txt" ]; then
        echo "[2/4] clonando lib/N64ModernRuntime (fork, fallback runtime.lock) desde $NMR_URL ..."
        git clone --quiet "$NMR_URL" "$NMR"
    fi
    [ -d "$NMR/.git" ] || {
        echo "ERROR: $NMR existe pero NO es un repositorio git. Borralo y reintenta." >&2; exit 1; }
    gitc "$NMR" fetch --quiet --all 2>/dev/null || true
    if gitc "$NMR" checkout --quiet "$NMR_COMMIT" 2>/dev/null; then
        echo "      N64ModernRuntime (fork) en $NMR_COMMIT"
    else
        echo "ERROR: no se pudo hacer checkout de $NMR_COMMIT en N64ModernRuntime." >&2
        echo "       El commit fijado no esta en el clon: publica el fork (git push fork hybrid-heaven)" >&2
        echo "       o corrige NMR_COMMIT en port/runtime.lock. Se aborta para no compilar otro runtime." >&2
        exit 1
    fi
    # Al cambiar de rama cambia .gitmodules: sincronizar URLs antes de bajar los submodulos
    # (N64Recomp sale del fork propio; thirdparty de upstream).
    gitc "$NMR" submodule sync --recursive --quiet
    gitc "$NMR" submodule update --init --recursive --quiet
}

if [ -e "$RT64/CMakeLists.txt" ] && [ -e "$NMR/CMakeLists.txt" ] && [ "$FORCE_LIBS" = 0 ]; then
    echo "[1-2/4] lib/rt64 y lib/N64ModernRuntime ya existen: se OMITE git."
    echo "        Usa --force-libs para clonar/actualizar."
else
    setup_rt64
    setup_nmr
fi

if [ "$LIBS_ONLY" = 1 ]; then
    echo "=== libs listas (--libs-only) ==="
    exit 0
fi

# --- CMake ---
# Si el build dir ya existe, respetar su generador (evita 'generator mismatch').
GEN=""
if [ ! -f "$PORT/$BUILD_DIR/CMakeCache.txt" ] && command -v ninja >/dev/null 2>&1; then
    GEN="-G Ninja"
fi

echo "[3/4] configurando CMake ($BUILD_TYPE) en $BUILD_DIR ..."
# shellcheck disable=SC2086
cmake -S "$PORT" -B "$PORT/$BUILD_DIR" -DCMAKE_BUILD_TYPE="$BUILD_TYPE" $GEN

if [ "$CONFIGURE_ONLY" = 1 ]; then
    echo "=== configurado (--configure-only) ==="
    exit 0
fi

[ -n "$JOBS" ] || JOBS=$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 4)
echo "[4/4] compilando HybridHeavenRecomp ($JOBS jobs) ..."
cmake --build "$PORT/$BUILD_DIR" --target HybridHeavenRecomp -j "$JOBS"

echo
echo "=== LISTO ==="
echo "Binario: $PORT/$BUILD_DIR/Hybrid Heaven Recomp"
echo "Para jugar: pon la ROM en la carpeta rom/ junto al binario ($PORT/$BUILD_DIR/rom/baserom.us.z64)."
