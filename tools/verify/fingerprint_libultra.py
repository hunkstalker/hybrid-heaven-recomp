#!/usr/bin/env python3
"""Fingerprint libultra: nombre mnsg -> direccion en HH.

Ambos juegos son IDO y enlazan la misma libultra: el codigo objeto es identico
salvo operandos relocalizados. Enmascaramos destinos de j/jal y pares %hi/%lo y
comparamos la secuencia completa de palabras enmascaradas. PC-relativos (branches)
se conservan (llevan la senal). Asi se recupera nombre y direccion de cada funcion
libultra de HH sin depender de artefactos de terceros.

Solo lectura. Uso: python3 tools/verify/fingerprint_libultra.py
"""
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
HH_ROM = (ROOT / "work/roms/us_retail.z64").read_bytes()
GOEMON_ROM = Path("/app/roms/goemon-baserom.us.z64")
MNSG_SYMS = ROOT / "toolchain/src/mnsg_syms/mnsg.syms.toml"
ELF = ROOT / "build/recomp/elf/hybrid-heaven.us.elf"
V2R = 0x7FFFF400  # rom = vram - V2R (residente; vram 0x80000400 <-> rom 0x1000)


def mask(w):
    op = w >> 26
    if op in (2, 3):            # j / jal: destino relocalizado
        return w & 0xFC000000
    if op == 0x0F:              # lui: %hi relocalizado
        return w & 0xFFFF0000
    if op in (0x00, 0x01, 0x04, 0x05, 0x06, 0x07, 0x10, 0x11, 0x12):
        return w               # special/regimm/branches/cop: sin %lo relocalizable
    if 0x08 <= op <= 0x0E or 0x18 <= op <= 0x1F or 0x20 <= op <= 0x3F:
        return w & 0xFFFF0000  # alu/mem inmediata: %lo relocalizado
    return w


def words_at(rom, vram, size):
    off = vram - V2R
    if off < 0 or off + size > len(rom):
        return None
    n = size // 4
    return list(struct.unpack_from(">%dI" % n, rom, off))


def signature(words):
    return tuple(mask(w) for w in words)


def mnsg_libultra():
    t = MNSG_SYMS.read_text(errors="replace")
    out = {}
    for m in re.finditer(r'\{\s*name\s*=\s*"([^"]+)"\s*,\s*vram\s*=\s*0x([0-9A-Fa-f]+)\s*,\s*size\s*=\s*0x([0-9A-Fa-f]+)\s*\}', t):
        name, vram, size = m.group(1), int(m.group(2), 16), int(m.group(3), 16)
        if not name.startswith("func_"):
            out[name] = (vram, size)
    return out


def hh_funcs():
    txt = subprocess.run(["llvm-readelf", "-sW", str(ELF)], capture_output=True, text=True).stdout
    out = {}
    for line in txt.splitlines():
        p = line.split()
        if len(p) >= 8 and p[3] == "FUNC":
            try:
                v = int(p[1], 16); s = int(p[2])
            except ValueError:
                continue
            if v and s:
                out.setdefault(v, (p[7], s))
    return out


def main():
    lib = mnsg_libultra()
    hhf = hh_funcs()
    goem = GOEMON_ROM.read_bytes()
    # firmas de funciones HH residentes: firma -> lista de candidatos
    hh_sig = {}
    for v, (name, size) in hhf.items():
        if v < 0x80000400 or v >= 0x8005E7D0:
            continue
        w = words_at(HH_ROM, v, size)
        if not w or len(w) * 4 != size:
            continue
        hh_sig.setdefault(signature(w), []).append((v, name, size))
    matched = {}
    ambiguous = 0
    for name, (v, size) in lib.items():
        w = words_at(goem, v, size)
        if not w or len(w) * 4 != size:
            continue
        cands = hh_sig.get(signature(w))
        if not cands:
            continue
        # conservador: match unico y mismo tamano
        if len(cands) == 1 and cands[0][2] == size:
            matched[name] = cands[0][0]
        else:
            ambiguous += 1
    print("match ambiguo/descartado:", ambiguous)
    print("mnsg libultra con nombre:", len(lib))
    print("funciones HH residentes:", len(hh_sig))
    print("emparejadas por fingerprint:", len(matched))
    # calibracion: nuestras 47 conocidas
    ours = {}
    for l in (ROOT / "recomp/symbol_addrs.txt").read_text().splitlines():
        p = l.split("=")
        if len(p) == 2:
            a = p[1].strip().rstrip(";").strip()
            if a.startswith("0x"):
                ours[p[0].strip()] = int(a, 16)
    ok = sum(1 for n, v in ours.items() if matched.get(n) == v)
    print("calibracion: %d/%d de nuestras syms coinciden" % (ok, len(ours)))
    unmatched_by_ours = [n for n, v in ours.items() if matched.get(n) != v]
    if unmatched_by_ours:
        print("  no coinciden:", unmatched_by_ours[:10])
    import json
    out = ROOT / "work/verify_libultra.json"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(matched, indent=1, sort_keys=True))
    print("escrito:", out.relative_to(ROOT), "(%d nombres)" % len(matched))
    return 0


if __name__ == "__main__":
    sys.exit(main())
