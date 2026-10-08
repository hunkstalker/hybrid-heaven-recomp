#!/usr/bin/env python3
"""Etapa 1 (offline) del experimento de extensión de límites del diálogo.

Analiza la estructura de los nodos de diálogo de un módulo (US):
  - bloque de texto y opcodes (f0/f3 salto, f8 espera, fa/fe fin de mensaje, fc inicio de
    pantalla/nodo, fd fin, f9);
  - candidatos a inicio de nodo (precedidos de `f0 00 fc 00 00 00 00 00`);
  - punteros absolutos (0x80xxxxxx) dentro del módulo y su relación con el bloque de texto;
  - con --base, comprueba la cadena y busca referencias (tabla externa) en TODOS los módulos.

Uso:
    python3 tools/text/analyze_dialogue_nodes.py --module 12 --base 0x802408F0
    python3 tools/text/analyze_dialogue_nodes.py --all
"""
import argparse
import importlib.util
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(HERE, "..", "lzkn64"))
spec = importlib.util.spec_from_file_location("ed", os.path.join(HERE, "extract_dialogues.py"))
ed = importlib.util.module_from_spec(spec)
spec.loader.exec_module(ed)

OPCODES = {0xF0: "salto", 0xF3: "salto", 0xF8: "espera", 0xFA: "fin_msg", 0xFE: "fin_msg",
           0xFC: "inicio_nodo", 0xFD: "fin", 0xF9: "f9"}


def opcodes_count(data, lo, hi):
    c = {}
    j = lo
    while j + 1 < hi:
        if 0xA1 <= data[j] <= 0xFE and 0xA1 <= data[j + 1] <= 0xFE:
            j += 2
            continue
        if data[j] in OPCODES and data[j + 1] == 0:
            c[data[j]] = c.get(data[j], 0) + 1
            j += 2
            continue
        j += 1
    return c


def node_starts(data):
    """Offsets de inicio de TEXTO de nodo: justo tras `f0 00 fc 00 00 00 00 00`."""
    pat = bytes([0xF0, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00])
    out = []
    i = data.find(pat)
    while i >= 0:
        out.append(i + 8)
        i = data.find(pat, i + 1)
    return out


def pointers(data):
    out = []
    for i in range(0, len(data) - 3, 2):
        v = struct.unpack_from(">I", data, i)[0]
        if 0x80000000 <= v < 0x80800000:
            out.append((i, v))
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--rom", default=os.path.join(REPO, "work", "roms", "us_retail.z64"))
    ap.add_argument("--module", type=int)
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--base", help="base RAM conocida del módulo (0x...)")
    args = ap.parse_args()

    rom = ed.load_rom(args.rom)
    entries = ed.nisitenma_entries(rom)
    mods = list(range(len(entries))) if args.all else [args.module]

    for m in mods:
        try:
            data, _ = ed.module_bytes(rom, entries, m)
        except SystemExit:
            continue
        runs = ed.text_runs(data)
        if len(runs) < 2:
            continue
        first, last = runs[0][0], runs[-1][1]
        oc = opcodes_count(data, first, last)
        ns = node_starts(data)
        ptrs = pointers(data)
        in_block = [p for p in ptrs if first <= (p[1] & 0xFFFFFF) or True]  # placeholder
        print(f"\n===== módulo {m} =====")
        print(f"  decomp={len(data)}B  bloque texto=[{first:#06x}..{last:#06x}] ({last-first}B)")
        print(f"  opcodes: " + " ".join(f"{OPCODES[k]}({k:02X})={v}" for k, v in sorted(oc.items())))
        print(f"  inicios de nodo (`f0 00 fc 00..`): {len(ns)} -> {[hex(x) for x in ns[:8]]}")
        print(f"  punteros 0x80xxxxxx en el módulo: {len(ptrs)}")
        if args.base:
            base = int(args.base, 0)
            lo, hi = base, base + len(data)
            # cabeceras de nodo: texto-0x1C (1º, header de 28B) o texto-0x10 (16B)
            headers = {}
            for k, x in enumerate(ns):
                for h in (x - 0x1C, x - 0x10):
                    if h >= 0:
                        headers.setdefault(h, k)
            print(f"  base={base:#010x}: cabeceras de nodo detectadas: {len(headers)}")
            # referencias EXACTAS a cabeceras de nodo (criterio robusto; evita falsos positivos
            # de rango). Internas (cadena +08) y externas (tabla de entrada en otro módulo).
            import collections
            by = collections.Counter()
            ex = collections.defaultdict(list)
            for m2 in range(len(entries)):
                try:
                    d2, _ = ed.module_bytes(rom, entries, m2)
                except SystemExit:
                    continue
                for i in range(0, len(d2) - 3, 2):
                    v = struct.unpack_from(">I", d2, i)[0]
                    off = v - base
                    if off in headers:
                        tag = "interno" if m2 == m else "externo"
                        by[tag] += 1
                        if len(ex[tag]) < 12:
                            ex[tag].append(f"mod{m2}@{i:#06x}->off{off:#06x}")
            print(f"  referencias exactas a cabeceras de nodo: internas={by['interno']} "
                  f"externas={by['externo']}")
            for t in ("interno", "externo"):
                if ex[t]:
                    print(f"     {t}: " + ", ".join(ex[t]))


if __name__ == "__main__":
    main()
