#!/usr/bin/env sh
# Wrapper de `analyzeHeadless` de Ghidra.
#
# Ghidra es una dependencia de DESARROLLO (regenerar símbolos), NO de build/uso del port.
# Quien clona y compila el port no necesita esto. Ver `tools/README.md` §Ghidra.
#
# Uso:
#   tools/ghidra_headless.sh <args de analyzeHeadless>
#   tools/ghidra_headless.sh "$PWD/work/ghidra/proj" HH -process baserom.us.z64 -noanalysis ...
#
# Variables (opcionales):
#   GHIDRA_HOME  ruta a la instalación (por defecto toolchain/ghidra/ghidra_*_PUBLIC)
#   JAVA_HOME    JDK 21 (Ghidra 12 exige Java 21); por defecto /usr/lib/jvm/java-21-openjdk
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)

if [ -z "${GHIDRA_HOME:-}" ]; then
    GHIDRA_HOME=$(ls -d "$ROOT"/toolchain/ghidra/ghidra_*_PUBLIC 2>/dev/null | head -n 1 || true)
fi
if [ -z "${GHIDRA_HOME:-}" ] || [ ! -x "$GHIDRA_HOME/support/analyzeHeadless" ]; then
    echo "ghidra_headless: no encuentro Ghidra." >&2
    echo "  Instálalo con: tools/install_ghidra.sh" >&2
    echo "  o exporta GHIDRA_HOME=<ruta a ghidra_<ver>_PUBLIC>." >&2
    exit 1
fi

if [ -z "${JAVA_HOME:-}" ]; then
    for j in /usr/lib/jvm/java-21-openjdk /usr/lib/jvm/java-21-openjdk-* \
             /usr/lib/jvm/temurin-21-jdk* /usr/lib/jvm/msopenjdk-21*; do
        [ -x "$j/bin/java" ] && JAVA_HOME="$j" && break
    done
fi
if [ -z "${JAVA_HOME:-}" ]; then
    echo "ghidra_headless: falta un JDK 21 (Ghidra 12 exige Java 21)." >&2
    echo "  Instálalo (p. ej. 'apk add openjdk21-jdk' o 'apt install openjdk-21-jdk')" >&2
    echo "  o exporta JAVA_HOME=<ruta al JDK 21>." >&2
    exit 1
fi
export JAVA_HOME

export MAXMEM="${MAXMEM:-4G}"
exec "$GHIDRA_HOME/support/analyzeHeadless" "$@"
