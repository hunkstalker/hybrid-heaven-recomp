#!/usr/bin/env python3
"""Extrae la tabla kana (EUC-JP) -> valor de glifo del motor y genera include/hh/jp_kana.h.

Contexto (ver notes/2026-09-23-b-fuente-formato-y-gaiji.md y docs/menu.md §Japones): la fuente
`color0` (Nisitenma idx 107) del juego es un bitmap 8x8 2bpp con DOS glifos por bloque; los valores
0..63 son el alfabeto latino y los valores 64..255 son simbolos, kana y kanji. El ROM JP tiene el
MISMO `color0` que el US (byte-identico), asi que la kana ya esta en la ROM que carga el port.

El motor mapea un codigo EUC-JP a un "slot" (= valor de glifo) con `func_8001D394`, que despacha por
fila JIS. Las tablas de mapeo viven en el segmento `.resident` del ELF recompilado:

    fila A1 (simbolos)  0x80044648   indexado por (byte_bajo - 0xA1)
    fila A3 (ASCII)     0x800446AC   indexado por (byte_bajo - 0xB0)
    fila A4 (hiragana)  0x800446F8   indexado por (byte_bajo - 0xA1)
    fila A5 (katakana)  0x8004474C   indexado por (byte_bajo - 0xA1)

Verificado: A4AF (ku) -> 92 y el glifo 92 dibuja "ku"; A4B7 (shi) -> 96. `slot == valor` porque
`func_8001BFE4` carga `file_base + stride*(slot>>1)`.

Uso:
    python3 tools/text/extract_jp_kana.py
    python3 tools/text/extract_jp_kana.py --elf build/recomp/elf/hybrid-heaven.us.elf \
        --out include/hh/jp_kana.h
"""
import argparse
import os
import struct

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
DEFAULT_ELF = os.path.join(REPO, "build", "recomp", "elf", "hybrid-heaven.us.elf")
DEFAULT_OUT = os.path.join(REPO, "include", "hh", "jp_kana.h")

# Direcciones virtuales (segmento .resident) de las tablas EUC -> slot.
TBL_SYMBOLS = 0x80044648   # fila A1 (simbolos); nos interesa A1BC = 'ー' (choonpu)
TBL_HIRAGANA = 0x800446F8  # fila A4
TBL_KATAKANA = 0x8004474C  # fila A5


def load_resident(elf_path):
    """Devuelve (datos, vaddr_base, off_base, size) del segmento .resident del ELF (MIPS)."""
    data = open(elf_path, "rb").read()
    if data[:4] != b"\x7fELF":
        raise SystemExit("no es un ELF: " + elf_path)
    is64 = data[4] == 2
    endian = ">" if data[5] == 2 else "<"
    if is64:
        e_shoff = struct.unpack_from(endian + "Q", data, 0x28)[0]
        e_shentsize = struct.unpack_from(endian + "H", data, 0x3A)[0]
        e_shnum = struct.unpack_from(endian + "H", data, 0x3C)[0]
        e_shstrndx = struct.unpack_from(endian + "H", data, 0x3E)[0]
        # SHT: name u32, type u32, flags u64, addr u64, offset u64, size u64; strtab offset @0x18
        addrfmt, offoff, sizeoff, strtab_off = endian + "Q", 0x18, 0x20, 0x18
    else:
        e_shoff = struct.unpack_from(endian + "I", data, 0x20)[0]
        e_shentsize = struct.unpack_from(endian + "H", data, 0x2E)[0]
        e_shnum = struct.unpack_from(endian + "H", data, 0x30)[0]
        e_shstrndx = struct.unpack_from(endian + "H", data, 0x32)[0]
        # SHT: name u32, type u32, flags u32, addr u32, offset u32, size u32; strtab offset @0x10
        addrfmt, offoff, sizeoff, strtab_off = endian + "I", 0x10, 0x14, 0x10

    shstr_off = struct.unpack_from(addrfmt, data, e_shoff + e_shstrndx * e_shentsize + strtab_off)[0]

    for i in range(e_shnum):
        base = e_shoff + i * e_shentsize
        name_off = struct.unpack_from(endian + "I", data, base)[0]
        addr = struct.unpack_from(addrfmt, data, base + 0x0C)[0]
        off = struct.unpack_from(addrfmt, data, base + offoff)[0]
        size = struct.unpack_from(addrfmt, data, base + sizeoff)[0]
        end = data.index(b"\x00", shstr_off + name_off)
        name = data[shstr_off + name_off:end].decode()
        if name == ".resident":
            return data, addr, off, size
    raise SystemExit("no encuentro .resident en " + elf_path)


def vaddr_slice(data, base, off, size, vaddr, n):
    if not (base <= vaddr and vaddr + n <= base + size):
        raise SystemExit("fuera de .resident: 0x%08X" % vaddr)
    o = off + (vaddr - base)
    return data[o:o + n]


def euc_cp(row, low):
    """EUC-JP (2 bytes) -> codepoint Unicode, o None si no decodifica."""
    try:
        return ord(bytes([row, low]).decode("euc-jp"))
    except UnicodeDecodeError:
        return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--elf", default=DEFAULT_ELF)
    ap.add_argument("--out", default=DEFAULT_OUT)
    args = ap.parse_args()

    data, base, off, size = load_resident(args.elf)
    sym = vaddr_slice(data, base, off, size, TBL_SYMBOLS, 0x60)
    hira = vaddr_slice(data, base, off, size, TBL_HIRAGANA, 0x54)
    kata = vaddr_slice(data, base, off, size, TBL_KATAKANA, 0x56)

    rows = []
    # Hiragana: EUC A4A1..A4F3 (index = low - 0xA1).
    for low in range(0xA1, 0xF4):
        v = hira[low - 0xA1]
        cp = euc_cp(0xA4, low)
        if cp is not None and v != 0:
            rows.append((cp, v, "hiragana"))
    # Katakana: EUC A5A1..A5F6.
    for low in range(0xA1, 0xF7):
        v = kata[low - 0xA1]
        cp = euc_cp(0xA5, low)
        if cp is not None and v != 0:
            rows.append((cp, v, "katakana"))
    # Simbolos utiles: ー (A1BC, choonpu) y 、。 (A1A2/A1A3) por si se usan.
    for row_low, label in ((0xBC, "ー"), (0xA2, "、"), (0xA3, "。")):
        v = sym[row_low - 0xA1]
        cp = euc_cp(0xA1, row_low)
        if cp is not None and v != 0:
            rows.append((cp, v, label))

    rows.sort()
    with open(args.out, "w", encoding="utf-8") as f:
        f.write("// Generado por tools/text/extract_jp_kana.py -- NO editar a mano.\n")
        f.write("// Tabla kana (codepoint Unicode) -> valor de glifo de la fuente del juego (color0,\n")
        f.write("// Nisitenma idx 107), extraida de las tablas EUC->slot del .resident del ELF.\n")
        f.write("// El ROM JP y el US comparten color0 (byte-identicos): la kana ya esta en la ROM.\n")
        f.write("#pragma once\n\n#include <cstdint>\n\n")
        f.write("namespace hh {\n\n")
        f.write("struct JpKana { uint32_t cp; uint8_t value; const char* note; };\n")
        f.write("inline constexpr JpKana kJpKana[] = {\n")
        for cp, v, label in rows:
            f.write('    { 0x%04X, %3d, "%s" },\n' % (cp, v, label))
        f.write("};\n")
        f.write("inline constexpr unsigned kJpKanaCount = sizeof(kJpKana) / sizeof(kJpKana[0]);\n\n")
        f.write("}  // namespace hh\n")
    print("jp_kana.h: %d entradas -> %s" % (len(rows), args.out))


if __name__ == "__main__":
    main()
