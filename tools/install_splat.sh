#!/usr/bin/env sh
# Instala el toolchain de recompilacion por ELF (splat + spimdisasm + ensamblador/enlazador MIPS)
# en `toolchain/splat-venv/` (dependencia de DESARROLLO).
#
# No es necesario para compilar/ejecutar el port; solo para regenerar el C con la via ELF
# (imagen expandida -> splat -> ELF -> N64Recomp). Ver docs/adr/0011 y
# notes/2026-09-21-migracion-via-referencia-elf.md.
#
# Ensamblador/enlazador MIPS: se usa el backend MIPS de LLVM (llvm-mc + ld.lld + llvm-objcopy),
# disponible como paquete; no hace falta compilar binutils GNU.
#
# Uso:  tools/install_splat.sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
VENV="$ROOT/toolchain/splat-venv"

# --- Python venv + splat/spimdisasm ----------------------------------------
if [ ! -x "$VENV/bin/python" ]; then
    echo "[splat] creando venv en $VENV ..."
    python3 -m venv "$VENV"
fi
"$VENV/bin/python" -m pip install -q --upgrade pip wheel
echo "[splat] instalando splat64 + spimdisasm + dependencias ..."
"$VENV/bin/pip" install -q splat64 spimdisasm n64img pygfxd crunch64 pypng

# --- Herramientas MIPS (LLVM) ----------------------------------------------
have_mips() {
    command -v llvm-mc >/dev/null 2>&1 && command -v ld.lld >/dev/null 2>&1 && \
    command -v llvm-objcopy >/dev/null 2>&1 && command -v llvm-readelf >/dev/null 2>&1
}
if have_mips; then
    echo "[splat] LLVM MIPS ya disponible (llvm-mc/ld.lld/llvm-objcopy/llvm-readelf)."
else
    echo "[splat] instalando LLVM + lld (ensamblador/enlazador MIPS)..."
    if command -v apk >/dev/null 2>&1; then
        apk add --no-cache llvm lld
    elif command -v apt-get >/dev/null 2>&1; then
        apt-get update && apt-get install -y llvm lld
    elif command -v dnf >/dev/null 2>&1; then
        dnf install -y llvm lld
    else
        echo "[splat] instala llvm + lld manualmente (se necesitan llvm-mc y ld.lld)." >&2
    fi
fi

echo "[splat] versiones:"
"$VENV/bin/pip" freeze 2>/dev/null | grep -iE "^(splat64|spimdisasm|n64img|pygfxd|crunch64)=" || true
echo "[splat] listo. Prueba: tools/splat_headless.sh -h"
