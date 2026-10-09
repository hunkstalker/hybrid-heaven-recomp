#!/usr/bin/env python3
"""Valida que las traducciones de DIALOGO caben en el presupuesto de cada mensaje (A+).

El motor (src/subsystems/text.cpp) sustituye el texto del mensaje en su mismo tramo: la suma de
caracteres traducidos no puede superar la del mensaje ingles (si no, cae a la ruta A por linea, y
las lineas que no caben se dejan en ingles). Este util replica el criterio, avisa de los mensajes
que NO caben y da la cobertura.

NOTA (2026-10-09): este presupuesto solo afecta a la ruta A+ **nativa** (fallback y
`HH_DLG_KEEP_ORIGINAL=1`). El **overlay propio del dialogo** (lo que se ve) NO tiene limite de
longitud, asi que "no cabe" aqui es INFORMATIVO: no obliga a acortar la traduccion mostrada.

Uso:
    python3 tools/text/check_dialogue_fit.py --lang es
    python3 tools/text/check_dialogue_fit.py --lang ca --rom build/windows/bin/Release/hh.us.z64
    python3 tools/text/check_dialogue_fit.py --lang es --module 27 --verbose

Por defecto usa `work/roms/us_retail.z64`.
"""
import argparse
import importlib.util
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(HERE, "..", "lzkn64"))


def _load(name):
    spec = importlib.util.spec_from_file_location(name, os.path.join(HERE, name + ".py"))
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


ed = _load("extract_dialogues")   # comparte ROM/decodificacion/agrupacion de mensajes


def load_lang(code):
    tr = {}
    p = os.path.join(REPO, "assets", "lang", code + ".txt")
    if not os.path.exists(p):
        raise SystemExit(f"no existe {p}")
    for line in open(p, encoding="utf-8"):
        line = line.rstrip("\n")
        if "=" in line and not line.startswith("#"):
            k, v = line.split("=", 1)
            tr[k.strip()] = v.strip()
    return tr


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rom", default=os.path.join(REPO, "work", "roms", "us_retail.z64"))
    ap.add_argument("--lang", default="es")
    ap.add_argument("--module", type=int)
    ap.add_argument("--verbose", action="store_true")
    args = ap.parse_args()

    rom = ed.load_rom(args.rom)
    entries = ed.nisitenma_entries(rom)
    tr = load_lang(args.lang)
    targets = [args.module] if args.module is not None else range(len(entries))

    n_msg = translated = fits = over = 0
    lines_total = lines_no_tr = 0
    for idx in targets:
        try:
            data, _ = ed.module_bytes(rom, entries, idx)
        except SystemExit:
            continue
        for _off, lines in ed.messages(data):
            n_msg += 1
            # El motor (load_file) recorta los espacios de los extremos de las claves, y
            # translate_euc() hace lo propio con la clave decodificada de la ROM: aqui se
            # replica con strip() para casar lineas con espacio inicial/final. El presupuesto
            # sigue contando los caracteres originales (en).
            key = lambda ln: ln.strip()
            en = sum(len(ln) for ln in lines)          # presupuesto (caracteres del mensaje EN)
            es = sum(len(tr[key(ln)]) if key(ln) in tr else len(ln) for ln in lines)
            any_tr = any(key(ln) in tr for ln in lines)
            lines_total += len(lines)
            lines_no_tr += sum(1 for ln in lines if key(ln) not in tr)
            if not any_tr:
                continue
            translated += 1
            if es <= en and key(lines[-1]) in tr:
                fits += 1
            else:
                over += 1
                print(f"  mod{idx} NO CABE/ultima_sin_trad EN={en} {args.lang.upper()}={es} :: "
                      + " | ".join(lines))
                if args.verbose:
                    for ln in lines:
                        print(f"        [{'>' if ln in tr else ' '}] {ln}")
    print(f"[{args.lang}] mensajes={n_msg} traducidos={translated} caben={fits} problemas={over} "
          f"lineas={lines_total} lineas_sin_traduccion={lines_no_tr}")
    return 1 if over else 0


if __name__ == "__main__":
    raise SystemExit(main())
