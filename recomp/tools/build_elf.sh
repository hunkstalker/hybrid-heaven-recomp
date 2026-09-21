#!/usr/bin/env sh
# Adaptado del tooling del port de referencia (MIT); ver CREDITS.md y licenses/hybrid-heaven-recomp-MIT.txt.
# build_elf.sh — ensambla la salida de splat y la enlaza en un ELF con símbolos (vía ELF, ADR 0011).
#
# Enlazado SOLO de ensamblador (nombres/direcciones/tamaños; sin C recuperado). El ELF resultante
# (elf/hybrid-heaven.us.elf) es lo que consume N64Recomp. Todo es derivado de la ROM: no se versiona.
#
# Ensamblador/enlazador: LLVM (llvm-mc + ld.lld + llvm-objcopy). Se normaliza el único GNU-ismo que
# llvm-mc no acepta (`.set gp=64` -> `.set gp,64`) y se reetiquetan los `glabel D_` dentro de texto.
#
# Requisitos: tools/install_splat.sh (splat) y `llvm`/`lld`; haber hecho el split
# (tools/splat_headless.sh split recomp/hybrid-heaven.us.yaml).
#
# Uso:  tools/build_elf.sh
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
cd "$ROOT"

AS=llvm-mc
ASFLAGS="-triple=mips -mcpu=mips3 -filetype=obj -I recomp -I build/recomp/include"
LD=ld.lld
OBJCOPY=llvm-objcopy
JOBS=${JOBS:-$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 4)}

[ -d asm ] || { echo "falta asm/ -- corre el split de splat primero" >&2; exit 1; }
[ -f recomp/hybrid-heaven.us.ld ] || { echo "falta recomp/hybrid-heaven.us.ld" >&2; exit 1; }

rm -rf build-elf/asm build-elf/src build-elf/link_syms.ld
mkdir -p build-elf/asm build-elf/src elf

echo "=== normalizando fuentes (.set gp=64; glabel D_ -> dlabel D_) ==="
find asm -name '*.s' | while IFS= read -r s; do
    dst="build-elf/src/$s"
    mkdir -p "$(dirname "$dst")"
    sed -e 's/\.set gp=64/.set gp,64/' -e '/^[[:space:]]*glabel D_/s/glabel D_/dlabel D_/' "$s" > "$dst"
done

echo "=== ensamblando ($JOBS jobs) ==="
export AS ASFLAGS
find build-elf/src/asm -name '*.s' | sort | xargs -P "$JOBS" -I{} sh -c \
    'rel="${1#build-elf/src/}"; o="build-elf/$rel.o"; mkdir -p "$(dirname "$o")"; $AS $ASFLAGS "$1" -o "$o"' _ {}
echo "  objetos: $(find build-elf/asm -name '*.o' | wc -l) de $(find asm -name '*.s' | wc -l) fuentes"

echo "=== envolviendo segmentos bin (ipl3, gap) ==="
# En vez de objcopy (los .bin.o salian con ABI n64, incompatible con o32), se ensambla un stub con
# .incbin, que hereda la ABI/target de llvm-mc (o32).
for f in ipl3 gap; do
    o="build-elf/work/scratch/expanded/assets/$f.bin.o"
    mkdir -p "$(dirname "$o")"
    stub="build-elf/src/_$f.bin.s"
    printf '.section .data\n.incbin "%s"\n' "$ROOT/work/scratch/expanded/assets/$f.bin" > "$stub"
    $AS $ASFLAGS "$stub" -o "$o"
done

echo "=== asignaciones de símbolos ==="
# shellcheck disable=SC2046
python3 recomp/tools/gen_link_syms.py $(find build-elf/asm -name '*.o' | sort)

echo "=== combinando linker scripts ==="
LINK_LD=build-elf/hybrid-heaven.us.link.ld
{
    echo "/* generado por tools/build_elf.sh -- no editar */"
    cat build-elf/link_syms.ld
    cat recomp/hybrid-heaven.us.ld
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
$LD -T "$LINK_LD" $(find build-elf -name '*.o' | sort) \
    -Map build-elf/hybrid-heaven.us.map --no-check-sections \
    -o elf/hybrid-heaven.us.elf

echo "=== resultado ==="
ls -l elf/hybrid-heaven.us.elf
llvm-readelf -S elf/hybrid-heaven.us.elf | grep -cE 'PROGBITS' | xargs echo "  secciones PROGBITS:"

echo "=== gate: ELF reconstruye la imagen byte a byte ==="
$OBJCOPY -O binary elf/hybrid-heaven.us.elf build-elf/rebuilt.bin
python3 - <<'PY'
img = open("work/scratch/expanded/hh.expanded.z64", "rb").read()
rb = open("build-elf/rebuilt.bin", "rb").read()
n = min(len(img), len(rb))
diff = [i for i in range(n) if img[i] != rb[i]]
if diff or len(img) != len(rb):
    print("FALLO: %d bytes difieren (imagen %d, rebuilt %d)" % (len(diff), len(img), len(rb)))
    for i in diff[:10]:
        print("  0x%06X %02X != %02X" % (i, rb[i], img[i]))
    raise SystemExit(1)
print("OK: ELF reconstruye la imagen byte a byte (%d bytes)" % n)
PY
