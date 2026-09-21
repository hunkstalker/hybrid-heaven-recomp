#!/usr/bin/env sh
# Adaptado del tooling del port de referencia (MIT); ver CREDITS.md y licenses/hybrid-heaven-recomp-MIT.txt.
# build_elf.sh — ensambla la salida de splat y la enlaza en un ELF con símbolos (vía ELF, ADR 0011).
#
# Enlazado SOLO de ensamblador (nombres/direcciones/tamaños; sin C recuperado). El ELF resultante
# (build/recomp/elf/hybrid-heaven.us.elf) es lo que consume N64Recomp. Todo es derivado de la ROM:
# no se versiona (vive bajo build/, gitignored).
#
# Ensamblador/enlazador: LLVM (llvm-mc + ld.lld + llvm-objcopy). Se normaliza el único GNU-ismo que
# llvm-mc no acepta (`.set gp=64` -> `.set gp,64`) y se reetiquetan los `glabel D_` dentro de texto.
#
# Requisitos: recomp/tools/install_splat.sh y `llvm`/`lld`; haber hecho el split
# (recomp/tools/splat_headless.sh split recomp/hybrid-heaven.us.yaml).
#
# Uso:  recomp/tools/build_elf.sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
cd "$ROOT"

ASM=build/recomp/asm
BUILD=build/recomp/build-elf
OUT_ELF=build/recomp/elf
LDSCRIPT=build/recomp/hybrid-heaven.us.ld

AS=llvm-mc
ASFLAGS="-triple=mips -mcpu=mips3 -filetype=obj -I recomp -I build/recomp/include"
LD=ld.lld
OBJCOPY=llvm-objcopy
JOBS=${JOBS:-$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 4)}

[ -d "$ASM" ] || { echo "falta $ASM -- corre el split de splat primero" >&2; exit 1; }
[ -f "$LDSCRIPT" ] || { echo "falta $LDSCRIPT" >&2; exit 1; }

rm -rf "$BUILD/asm" "$BUILD/src" "$BUILD/link_syms.ld"
mkdir -p "$BUILD/asm" "$BUILD/src" "$OUT_ELF"

echo "=== normalizando fuentes (.set gp=64; glabel D_ -> dlabel D_) ==="
find "$ASM" -name '*.s' | while IFS= read -r s; do
    dst="$BUILD/src/$s"
    mkdir -p "$(dirname "$dst")"
    sed -e 's/\.set gp=64/.set gp,64/' -e '/^[[:space:]]*glabel D_/s/glabel D_/dlabel D_/' "$s" > "$dst"
done

echo "=== ensamblando ($JOBS jobs) ==="
export AS ASFLAGS
find "$BUILD/src/$ASM" -name '*.s' | sort | xargs -P "$JOBS" -I{} sh -c \
    'rel="${1#'"$BUILD"'/src/}"; o="'"$BUILD"'/$rel.o"; mkdir -p "$(dirname "$o")"; $AS $ASFLAGS "$1" -o "$o"' _ {}
echo "  objetos: $(find "$BUILD/$ASM" -name '*.o' | wc -l) de $(find "$ASM" -name '*.s' | wc -l) fuentes"

echo "=== envolviendo segmentos bin (ipl3, gap) ==="
# En vez de objcopy (los .bin.o salian con ABI n64, incompatible con o32), se ensambla un stub con
# .incbin, que hereda la ABI/target de llvm-mc (o32). Los .bin viven en work/scratch/expanded/assets.
for f in ipl3 gap; do
    o="$BUILD/work/scratch/expanded/assets/$f.bin.o"
    mkdir -p "$(dirname "$o")"
    stub="$BUILD/src/_$f.bin.s"
    printf '.section .data\n.incbin "%s"\n' "$ROOT/work/scratch/expanded/assets/$f.bin" > "$stub"
    $AS $ASFLAGS "$stub" -o "$o"
done

echo "=== asignaciones de símbolos ==="
# shellcheck disable=SC2046
python3 recomp/tools/gen_link_syms.py $(find "$BUILD" -name '*.o' | sort)

echo "=== combinando linker scripts ==="
LINK_LD="$BUILD/hybrid-heaven.us.link.ld"
{
    echo "/* generado por recomp/tools/build_elf.sh -- no editar */"
    cat "$BUILD/link_syms.ld"
    cat "$LDSCRIPT"
} > "$LINK_LD"

# lld rechaza `/DISCARD/ { *(*) }` (intenta descartar .shstrtab). Se descartan solo las secciones de
# metadatos MIPS (abiflags/reginfo/comment/note/pdr), que si no lld coloca encima del residente.
python3 - "$LINK_LD" <<'PY'
import re, sys
p = sys.argv[1]
t = open(p).read()
t2 = re.sub(r"/DISCARD/\s*:\s*\{\s*\*\(\*\);\s*\}",
            "/DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.comment) *(.note*) *(.pdr) }",
            t, count=1)
open(p, "w").write(t2)
PY

echo "=== enlazando ==="
$LD -T "$LINK_LD" $(find "$BUILD" -name '*.o' | sort) \
    -Map "$BUILD/hybrid-heaven.us.map" --no-check-sections \
    -o "$OUT_ELF/hybrid-heaven.us.elf"

echo "=== resultado ==="
ls -l "$OUT_ELF/hybrid-heaven.us.elf"
llvm-readelf -S "$OUT_ELF/hybrid-heaven.us.elf" | grep -cE 'PROGBITS' | xargs echo "  secciones PROGBITS:"

echo "=== gate: ELF reconstruye la imagen byte a byte ==="
$OBJCOPY -O binary "$OUT_ELF/hybrid-heaven.us.elf" "$BUILD/rebuilt.bin"
python3 - <<'PY'
img = open("work/scratch/expanded/hh.expanded.z64", "rb").read()
rb = open("build/recomp/build-elf/rebuilt.bin", "rb").read()
n = min(len(img), len(rb))
diff = [i for i in range(n) if img[i] != rb[i]]
if diff or len(img) != len(rb):
    print("FALLO: %d bytes difieren (imagen %d, rebuilt %d)" % (len(diff), len(img), len(rb)))
    for i in diff[:10]:
        print("  0x%06X %02X != %02X" % (i, rb[i], img[i]))
    raise SystemExit(1)
print("OK: ELF reconstruye la imagen byte a byte (%d bytes)" % n)
PY
