#!/usr/bin/env python3
"""Extractor ROM -> texto para Hybrid Heaven (US).

El texto del juego vive en modulos cargados por el loader `trans` (tabla Konami
Nisitenma-Ichigo), comprimidos con LZKN64. Este util descomprime un modulo (por indice
Nisitenma o por offset de ROM) y lista las cadenas ASCII terminadas en NUL.

Formato observado (USA): cada cadena es un campo de ancho fijo, relleno con espacios
(0x20) y terminado en NUL (0x00). Prefijos de formato tipo printf (`%p`, `%m`, `%a`,
`%s`, `%d`) marcan estilo/argumentos, no son glifos.

Uso:
    python3 tools/text/extract_strings.py --module 23
    python3 tools/text/extract_strings.py --off 0x5FB543
    python3 tools/text/extract_strings.py --module 23 --min 3 --tsv out.tsv
    python3 tools/text/extract_strings.py --all --tsv work/text_strings.tsv

La ROM por defecto es `build/windows/bin/Release/hh.us.z64`; usar --rom para otra.
"""
import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "lzkn64"))
import lzkn64  # noqa: E402

DEFAULT_ROM = "build/windows/bin/Release/hh.us.z64"
NISITENMA_TABLE_ROM = 0x39BF0  # US: "Nisitenma-Ichigo" @ 0x39BE0 -> tabla @ 0x39BF0


def load_rom(path):
    with open(path, "rb") as f:
        return f.read()


def nisitenma_entries(rom, table_off=NISITENMA_TABLE_ROM):
    """Devuelve [(rom_off, compressed), ...] de la tabla Nisitenma-Ichigo."""
    entries = []
    i = 0
    while True:
        off = table_off + 4 * i
        if off + 4 > len(rom):
            break
        v = struct.unpack_from(">I", rom, off)[0]
        if v == 0:
            break
        entries.append((v & 0x7FFFFFFF, bool(v >> 31)))
        i += 1
    return entries


def module_range(rom, entries, index):
    if not (0 <= index < len(entries)):
        raise SystemExit(f"indice de modulo fuera de rango: {index}")
    start = entries[index][0]
    end = entries[index + 1][0] if index + 1 < len(entries) else len(rom)
    return start, end, entries[index][1]


def find_module_by_off(entries, target):
    for i, (off, comp) in enumerate(entries):
        end = entries[i + 1][0] if i + 1 < len(entries) else 0xFFFFFFFF
        if off <= target < end:
            return i
    return None


def module_bytes(rom, entries, index):
    start, end, comp = module_range(rom, entries, index)
    data = rom[start:end]
    if comp:
        try:
            data = lzkn64.decompress(data)
        except ValueError as e:
            raise SystemExit(f"modulo {index}: fallo LZKN64: {e}")
    return data, start


def iter_strings(data, min_len=3):
    """Genera (offset, texto) de cada tira ASCII >= min_len terminada en NUL o fin."""
    n = len(data)
    i = 0
    while i < n:
        if 0x20 <= data[i] < 0x7F:
            j = i
            while j < n and 0x20 <= data[j] < 0x7F:
                j += 1
            if j - i >= min_len:
                yield i, data[i:j].decode("ascii")
            i = j
        else:
            i += 1


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rom", default=DEFAULT_ROM)
    ap.add_argument("--module", type=int, help="indice Nisitenma del modulo")
    ap.add_argument("--off", type=lambda s: int(s, 0), help="offset de ROM; localiza su modulo")
    ap.add_argument("--all", action="store_true", help="todos los modulos")
    ap.add_argument("--min", type=int, default=3, help="longitud minima (def. 3)")
    ap.add_argument("--tsv", help="escribir TSV (module, off, text) en vez de imprimir")
    args = ap.parse_args()

    rom = load_rom(args.rom)
    entries = nisitenma_entries(rom)

    targets = []
    if args.module is not None:
        targets = [args.module]
    elif args.off is not None:
        idx = find_module_by_off(entries, args.off)
        if idx is None:
            raise SystemExit(f"0x{args.off:X} no cae en ningun modulo")
        targets = [idx]
    elif args.all:
        targets = list(range(len(entries)))
    else:
        ap.error("indica --module, --off o --all")

    out = sys.stdout
    if args.tsv:
        out = open(args.tsv, "w", encoding="utf-8")
        out.write("module\toff\ttext\n")

    for idx in targets:
        try:
            data, rom_start = module_bytes(rom, entries, idx)
        except SystemExit as e:
            print(str(e), file=sys.stderr)
            continue
        if args.tsv:
            for off, s in iter_strings(data, args.min):
                out.write(f"{idx}\t0x{rom_start + off:06X}\t{s}\n")
        else:
            print(f"=== modulo {idx} (ROM 0x{rom_start:X}, {len(data)} bytes) ===")
            for off, s in iter_strings(data, args.min):
                print(f"{off:06X}  {s}")

    if args.tsv:
        out.close()
        print(f"escrito {args.tsv}", file=sys.stderr)


if __name__ == "__main__":
    main()
