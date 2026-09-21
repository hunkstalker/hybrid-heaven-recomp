#!/usr/bin/env sh
# Instala Ghidra + N64LoaderWV en `toolchain/ghidra/` (dependencia de DESARROLLO).
#
# No es necesario para compilar/ejecutar el port; solo para regenerar símbolos con
# `tools/ghidra_headless.sh`. Requiere: JDK 21, red, unzip, wget.
#
# Uso:
#   tools/install_ghidra.sh [GHIDRA_VERSION]   # por defecto 12.1.3
#
# Deja: toolchain/ghidra/ghidra_<ver>_PUBLIC  (+ extension N64LoaderWV en Extensions/)
set -eu

VERSION="${1:-12.1.3}"
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
DEST="$ROOT/toolchain/ghidra"
TMP="$ROOT/toolchain/ghidra/.download"
GHIDRA_DIR="$DEST/ghidra_${VERSION}_PUBLIC"

mkdir -p "$DEST" "$TMP"

# --- JDK 21 -----------------------------------------------------------------
if ! command -v java >/dev/null 2>&1 || ! java -version 2>&1 | grep -q '"21'; then
    echo "[ghidra] instalando JDK 21..."
    if command -v apk >/dev/null 2>&1; then
        apk add --no-cache openjdk21-jdk
    elif command -v apt-get >/dev/null 2>&1; then
        apt-get update && apt-get install -y openjdk-21-jdk-headless
    elif command -v dnf >/dev/null 2>&1; then
        dnf install -y java-21-openjdk-devel
    else
        echo "[ghidra] instala un JDK 21 manualmente y re-ejecuta." >&2
        exit 1
    fi
fi

# --- Ghidra -----------------------------------------------------------------
if [ -x "$GHIDRA_DIR/support/analyzeHeadless" ]; then
    echo "[ghidra] ya instalado: $GHIDRA_DIR"
else
    ZIP="$TMP/ghidra_${VERSION}_PUBLIC.zip"
    if [ ! -f "$ZIP" ]; then
        echo "[ghidra] descargando Ghidra $VERSION..."
        URL="https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_${VERSION}_build/ghidra_${VERSION}_PUBLIC_20260817.zip"
        wget -q --show-progress -O "$ZIP" "$URL" || {
            echo "[ghidra] no pude descargar $URL" >&2
            echo "[ghidra] busca el asset correcto en https://github.com/NationalSecurityAgency/ghidra/releases" >&2
            exit 1
        }
    fi
    echo "[ghidra] descomprimiendo..."
    unzip -q -o "$ZIP" -d "$DEST"
fi

# --- N64LoaderWV ------------------------------------------------------------
EXT="$GHIDRA_DIR/Extensions/N64LoaderWV"
if [ ! -f "$EXT/lib/N64LoaderWV.jar" ]; then
    echo "[ghidra] descargando N64LoaderWV $VERSION..."
    WZIP="$TMP/N64LoaderWV_${VERSION}.zip"
    WURL="https://github.com/zeroKilo/N64LoaderWV/releases/download/${VERSION}/ghidra_${VERSION}_PUBLIC_20260920_N64LoaderWV.zip"
    wget -q --show-progress -O "$WZIP" "$WURL" || {
        echo "[ghidra] no pude descargar $WURL" >&2
        echo "[ghidra] busca el asset correcto en https://github.com/zeroKilo/N64LoaderWV/releases" >&2
        exit 1
    }
    unzip -q -o "$WZIP" -d "$TMP/n64loaderwv"
    mkdir -p "$GHIDRA_DIR/Extensions"
    rm -rf "$EXT"
    cp -r "$TMP/n64loaderwv/N64LoaderWV" "$EXT"
fi

echo "[ghidra] listo. Comprueba con: tools/ghidra_headless.sh -help"
