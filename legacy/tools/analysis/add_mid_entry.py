#!/usr/bin/env python3
"""add_mid_entry.py — registra una direccion de `Failed to find function at 0x...` como entrada.

Uso:
    python3 tools/analysis/add_mid_entry.py 0x80379954 [--dry-run]

Hace SOLO lo minimo y seguro (sin `setup_module.py`: su cascado de `auto_mid` puede meter datos
como codigo; ver notes/2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md, "Ronda 8"):

  1. Localiza el modulo (seccion de `recomp_overlays.inl`) cuyo blob contiene la direccion.
  2. Comprueba que la instruccion anterior NO es un salto (delay slot -> no registrable).
  3. Parte el simbolo contenedor en `config/us_moduleNN.syms.toml` y `config/us_combined.syms.toml`
     (tamanos = siguiente direccion - direccion).
  4. Anade la direccion a `config/keep_syms.txt` (el validador no debe fusionarla) y a
     `config/module_extras.json` del modulo (documentacion).

Despues hay que recompilar con `python3 tools/recomp.py --config config/game_combined.toml --force`
(el `--force` es necesario: el validador fusiona splits legitimos de epilogos compartidos).
"""
import argparse
import json
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import gen_module_syms as gms

ROOT = Path(__file__).resolve().parents[2]
CONFIG = ROOT / "config"
RECOMP = ROOT / "port/HybridHeavenRecomp/RecompiledFuncs"
SCRATCH = ROOT / "work/scratch"

SALTO_OPS = {1, 2, 3, 4, 5, 6, 7, 0x11, 0x14, 0x15, 0x16, 0x17}


def es_delay_slot(blob, base, addr):
    off = addr - base - 4
    if off < 0 or off + 4 > len(blob):
        return False
    w = struct.unpack(">I", blob[off:off + 4])[0]
    op = w >> 26
    if op in SALTO_OPS:
        return True
    return op == 0 and (w & 0x3F) in (8, 9)  # jr / jalr


def secciones():
    txt = (RECOMP / "recomp_overlays.inl").read_text()
    out = []
    for _full, _sidx, midx, _s0, body in re.findall(
            r'static FuncEntry (section_(\d+)_module(\d+)_funcs|section_(\d+)_text_funcs)\[\] = \{(.*?)\n\};',
            txt, re.S):
        ents = re.findall(r'\.func = (\w+), \.offset = (0x[0-9A-Fa-f]+), \.rom_size = (0x[0-9A-Fa-f]+)', body)
        base = None
        for fname, off, _size in ents:
            m = re.search(r'([0-9A-Fa-f]{8})$', fname)
            if m:
                base = int(m.group(1), 16) - int(off, 16)
                break
        if base is None:
            continue
        out.append({"idx": int(midx) if midx else 0, "base": base})
    return out


def rango_seccion(path, idx):
    s = path.read_text()
    if path.name.startswith("us_module"):
        cab = s[:600]
    else:
        i = s.find(f'name = ".module{idx}"')
        if i < 0:
            return None
        cab = s[s.rfind("[[section]]", 0, i): i + 400]
    m_vram = re.search(r'vram = 0x([0-9A-Fa-f]+)', cab)
    m_size = re.search(r'size = 0x([0-9A-Fa-f]+)', cab)
    if not (m_vram and m_size):
        return None
    vram = int(m_vram.group(1), 16)
    return vram, vram + int(m_size.group(1), 16)


def split_fichero(path, addr, idx, dry):
    rango = rango_seccion(path, idx)
    if rango is None:
        print(f"  ! {path.name}: no se pudo leer la seccion .module{idx}")
        return False
    start, end = rango
    s = path.read_text()
    if path.name.startswith("us_module"):
        i = s.find("functions = [")
    else:
        n = s.find(f'name = ".module{idx}"')
        i = s.find("functions = [", n)
    j = s.find("\n]", i)
    bloque = s[i:j]
    addrs = set(int(m.group(1), 16) for m in re.finditer(r'vram = 0x([0-9A-Fa-f]+), size', bloque))
    if addr in addrs:
        print(f"  = {path.name}: ya presente")
        return True
    # Edicion MINIMA: solo se reescribe la entrada contenedora y se inserta la nueva. Recalcular
    # TODOS los tamanos por "hueco hasta el siguiente" borraba overrides manuales
    # (p. ej. M9_FUN_802169ac:0x1C0 de module_extras.json, que evita el stub do_break) y estados
    # deliberados del .syms (fronteras gruesas, simbolos fusionados con comentario de validate_syms).
    lineas = bloque.splitlines()
    rx = re.compile(r'vram = 0x([0-9A-Fa-f]+), size = 0x([0-9A-Fa-f]+)')
    ents = [(k, int(m.group(1), 16), int(m.group(2), 16), ln)
            for k, ln in enumerate(lineas) for m in [rx.search(ln)] if m]
    cont = None
    for e in ents:
        if e[1] <= addr:
            cont = e
        else:
            break
    sig = next((e[1] for e in ents if e[1] > addr), end)
    if cont is not None and cont[1] <= addr < cont[1] + cont[2]:
        indent = cont[3][:len(cont[3]) - len(cont[3].lstrip())]
        lineas[cont[0]] = f'{indent}{{ name = "M{idx}_FUN_{cont[1]:08x}", vram = 0x{cont[1]:08X}, size = 0x{addr - cont[1]:X} }},'
        pos = cont[0] + 1
    else:
        pos = (cont[0] + 1) if cont is not None else 0
        indent = cont[3][:len(cont[3]) - len(cont[3].lstrip())] if cont is not None else "    "
        print(f"  ! {path.name}: {addr:#x} no cae dentro de ningun simbolo; se inserta sin recortar")
    lineas.insert(pos, f'{indent}{{ name = "M{idx}_FUN_{addr:08x}", vram = 0x{addr:08X}, size = 0x{sig - addr:X} }},')

    # Overrides de tamano declarados en module_extras.json ("0xADDR:0xSIZE").
    overrides = {}
    for tok in json.loads((CONFIG / "module_extras.json").read_text()).get(str(idx), []):
        if ":" in tok:
            a_str, s_str = tok.split(":", 1)
            overrides[int(a_str, 16)] = int(s_str, 16)
    if overrides:
        rx_size = re.compile(r'(size = 0x)[0-9A-Fa-f]+')
        for k2, ln in enumerate(lineas):
            m = rx.search(ln)
            if m and int(m.group(1), 16) in overrides:
                lineas[k2] = rx_size.sub(rf'\g<1>{overrides[int(m.group(1), 16)]:X}', ln)

    nuevo = s[:i] + "\n".join(lineas) + s[j:]
    if not dry:
        path.write_text(nuevo)
    print(f"  + {path.name}: {addr:#x} insertado ({len(ents) + 1} funciones)")
    return True


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("addr", help="direccion del Failed to find function (hex)")
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()
    addr = int(args.addr, 16)

    candidatos = []
    for sec in secciones():
        if sec["idx"] == 0:
            continue
        blob_path = SCRATCH / f"module{sec['idx']}_be.bin"
        if not blob_path.exists():
            continue
        tam = blob_path.stat().st_size
        if sec["base"] <= addr < sec["base"] + tam:
            candidatos.append((tam, sec, blob_path))
    if not candidatos:
        sys.exit("direccion fuera de los blobs de modulo conocidos (plano?)")
    candidatos.sort(key=lambda c: c[0])  # el modulo mas especifico (rango menor)
    tam, sec, blob_path = candidatos[0]
    idx = sec["idx"]
    blob = blob_path.read_bytes()
    if es_delay_slot(blob, sec["base"], addr):
        sys.exit(f"{addr:#x} es delay slot de un salto: NO registrable (ver nota, 'Ronda 9')")

    # Prohibido partir dentro de un rango fusionado por jump-table: el switch perderia sus casos
    # como etiquetas locales y pasaria a LOOKUP (regresion del 2026-09-15 en las escaleras:
    # splits 0x8037C50C/0x8037C530 -> crash en 0x8037C8E4).
    ents = sorted(int(m.group(1), 16) for m in re.finditer(r'vram = 0x([0-9A-Fa-f]+), size',
                  (CONFIG / f"us_module{idx}.syms.toml").read_text()))
    _ents, override = gms.merge_jump_tables(ents, blob, sec["base"])
    for f, tam in override.items():
        if f < addr < f + tam:
            sys.exit(f"{addr:#x} cae dentro de un switch fusionado (0x{f:X}..0x{f+tam:X}): "
                     f"NO registrable (romperia la jump-table; ver nota, 'Ronda 9')")

    print(f"modulo idx {idx} (base {sec['base']:#x}, blob {tam:#x}); {addr:#x} no es delay slot")
    ok = split_fichero(CONFIG / f"us_module{idx}.syms.toml", addr, idx, args.dry_run)
    ok &= split_fichero(CONFIG / "us_combined.syms.toml", addr, idx, args.dry_run)

    keep = CONFIG / "keep_syms.txt"
    lineas = [l.strip() for l in keep.read_text().splitlines() if l.strip()]
    tok = f"0x{addr:X}"
    if tok not in lineas:
        lineas.append(tok)
        lineas.sort(key=lambda x: int(x, 16))
        if not args.dry_run:
            keep.write_text("\n".join(lineas) + "\n")
        print(f"  + keep_syms.txt: {tok}")

    extras = json.loads((CONFIG / "module_extras.json").read_text())
    lst = extras.setdefault(str(idx), [])
    if tok not in lst:
        lst.append(tok)
        lst.sort(key=lambda x: int(x.split(":")[0], 16))
        if not args.dry_run:
            (CONFIG / "module_extras.json").write_text(json.dumps(extras, indent=2) + "\n")
        print(f"  + module_extras.json[{idx}]: {tok}")

    print("\nSiguiente paso:")
    print("  python3 tools/recomp.py --config config/game_combined.toml --force")
    if args.dry_run:
        print("(dry-run: nada escrito)")


if __name__ == "__main__":
    main()
