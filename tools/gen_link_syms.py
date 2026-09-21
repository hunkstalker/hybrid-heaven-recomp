#!/usr/bin/env python3
"""gen_link_syms.py — fragmento de linker script con símbolos que ningún objeto define.

Dos fuentes de asignaciones `NAME = 0xADDR;` alimentan el enlazado:
  * `recomp/undefined_syms_auto.txt` / `recomp/undefined_funcs_auto.txt` (splat), y
  * referencias cuyo nombre codifica su dirección y que splat no etiqueta.

Ambas son peligrosas igual: una asignación define el símbolo como ABSOLUTE; si además está definido
de verdad en un objeto (lo normal en una llamada entre segmentos), la definición absoluta ensombrece
a la real (ligada a sección) y N64Recomp deja de verla ("No function found for jal target"). Por eso
solo se emite la asignación para símbolos que **ningún objeto define**.

Uso:  python3 tools/gen_link_syms.py <objetos...>   (escribe build-elf/link_syms.ld)
"""
import pathlib
import re
import subprocess
import sys

NM = "llvm-nm"
OUT = pathlib.Path("build-elf/link_syms.ld")
FRAGMENTS = [pathlib.Path("recomp/undefined_syms_auto.txt"),
             pathlib.Path("recomp/undefined_funcs_auto.txt")]

ASSIGN = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(0x[0-9A-Fa-f]+|\d+)\s*;")
ADDR_NAME = re.compile(r"^(?:D|func|jtbl|jpt|L)_([0-9A-Fa-f]{8})(?:_[0-9A-Za-z_]+)?$")


def symbols(objs):
    out = subprocess.run([NM, *objs], capture_output=True, text=True, check=True).stdout
    undef, defined = set(), set()
    for line in out.splitlines():
        parts = line.split()
        if len(parts) == 2 and parts[0] == "U":
            undef.add(parts[1])
        elif len(parts) == 3 and parts[1] != "U":
            defined.add(parts[2])
    return undef, defined


def main() -> int:
    objs = sys.argv[1:]
    if not objs:
        raise SystemExit("usage: %s <object files>" % sys.argv[0])

    undef, defined = symbols(objs)
    emitted, shadowed = {}, 0
    for frag in FRAGMENTS:
        if not frag.exists():
            continue
        for line in frag.read_text().splitlines():
            m = ASSIGN.match(line)
            if not m:
                continue
            name, value = m.group(1), m.group(2)
            if name in defined:
                shadowed += 1
                continue
            emitted.setdefault(name, value)

    unresolved = []
    for name in sorted(undef - defined - set(emitted)):
        m = ADDR_NAME.match(name)
        if m:
            emitted[name] = "0x%s" % m.group(1).upper()
        else:
            unresolved.append(name)

    OUT.parent.mkdir(parents=True, exist_ok=True)
    with OUT.open("w", newline="\n") as f:
        f.write("/* Generado por tools/gen_link_syms.py -- no editar. */\n")
        for name, value in sorted(emitted.items()):
            f.write("%s = %s;\n" % (name, value))

    print("asignaciones emitidas : %d  -> %s" % (len(emitted), OUT))
    print("suprimidas (definidas): %d  <- habrian ensombrecido un simbolo real" % shadowed)
    if unresolved:
        print("SIN RESOLVER          : %d  (sin direccion en el nombre)" % len(unresolved))
        for n in unresolved[:20]:
            print("    %s" % n)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
