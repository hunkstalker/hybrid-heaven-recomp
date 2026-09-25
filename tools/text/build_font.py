#!/usr/bin/env python3
"""Construye el set de glifos acentuados ES/CA/FR/DE desde la fuente REAL del juego.

Fuentes (formato del motor, 2bpp, 2 glifos por bloque; par=bits 2-3, impar=bits 0-1):
  - color4 US @0x6E4CD6, 8x12, stride 48  (base del texto in-game; se embebe desde US).
  - color0 US @0x6E3CD6, 8x8,  stride 32  (base del menu/overlay).
  - color4 EU @0x8C3298, 8x12, stride 56  (referencia: acentos REALES de la PAL).

Estrategia: glifo acentuado REAL si esta identificado; si no, composicion desde la letra base
+ la marca de acento extraida de un glifo real (mismo estilo). La sombra (nivel>=2) se conserva
o se autogenera.

Salidas:
  --sheet <png>   hoja EDITABLE: tinta=negro, sombra=rojo, fondo blanco, rejilla + etiqueta ASCII.
  --ref <png>     hoja de referencia ampliada (aspecto final).
  --out <h>       header C (bloques 2bpp empaquetados) + tabla codepoint -> valor.
  --report <md>   informe: real / compuesto / a dibujar.

Uso:
  python3 tools/text/build_font.py --style color4 \
      --sheet work/fonts/edit_color4.png --ref work/fonts/ref_color4.png \
      --out include/hh/game_font_color4.h --report work/fonts/coverage_color4.md
"""
import argparse
import os
import struct
import zlib

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
US_ROM = os.path.join(REPO, "build", "linux", "baserom.us.z64")
EU_ROM = os.path.join(REPO, "work", "roms", "eu_dec.z64")

FONTS = {
    "color4": (US_ROM, 0x6E4CD6, 48, 8, 12, 88),
    "color0": (US_ROM, 0x6E3CD6, 32, 8, 8, 256),
}
EU_COLOR4 = (EU_ROM, 0x8C3298, 56, 8, 12, 130)


def base_value(cp):
    if cp == 0x20:
        return 0
    if 0x30 <= cp <= 0x39:
        return 1 + (cp - 0x30)
    if 0x61 <= cp <= 0x7A:
        return 11 + (cp - 0x61)
    if 0x41 <= cp <= 0x5A:
        return 37 + (cp - 0x41)
    return None


# Glifos acentuados REALES identificados en color4 EU (codepoint -> valor EU).
# Se usan solo para extraer la MARCA; el cuerpo se recompone (y la identidad de agudo/grave
# en MAYUSCULAS es provisional, ver informe: el mantenedor la corrige en la hoja).
REAL = {
    0x00E4: 104, 0x00E2: 105, 0x00E0: 106, 0x00E1: 107,
    0x00EB: 108, 0x00EA: 109, 0x00E8: 110, 0x00E9: 111,
    0x00FC: 112, 0x00F6: 117, 0x00E7: 119, 0x00DF: 128,
    0x00C4: 87, 0x00C2: 88, 0x00CB: 91, 0x00CA: 92,
    0x00DC: 95, 0x00D6: 100, 0x00C7: 102,
    0x00D3: 101, 0x00DA: 97, 0x00CE: 99, 0x00CF: 98,
    0x00C1: 90, 0x00C9: 93, 0x00C8: 94,
}

# marca -> glifo real de origen + donde esta la marca
MARKS = {
    "apto": (0x00E9, "top"), "agrv": (0x00E0, "top"), "acir": (0x00E2, "top"),
    "adie": (0x00E4, "top"), "aced": (0x00E7, "cedilla"),
    "Aacu": (0x00C1, "row0"), "Agrv": (0x00C8, "row0"), "Acir": (0x00C2, "row0"),
    "Adie": (0x00C4, "row0"), "Aced": (0x00C7, "cedilla"),
}

# (codepoint, letra base, marca)
COMPOSE = [
    (0x00E1, "a", "apto"), (0x00ED, "i", "apto"), (0x00F3, "o", "apto"), (0x00FA, "u", "apto"),
    (0x00FD, "y", "apto"), (0x0107, "c", "apto"), (0x0144, "n", "apto"), (0x015B, "s", "apto"),
    (0x00E0, "a", "agrv"), (0x00EC, "i", "agrv"), (0x00F2, "o", "agrv"), (0x00F9, "u", "agrv"),
    (0x00E2, "a", "acir"), (0x00EE, "i", "acir"), (0x00F4, "o", "acir"), (0x00FB, "u", "acir"),
    (0x00E4, "a", "adie"), (0x00EF, "i", "adie"), (0x00F6, "o", "adie"), (0x00FC, "u", "adie"),
    (0x00FF, "y", "adie"),
    (0x00C1, "A", "Aacu"), (0x00CD, "I", "Aacu"), (0x00D3, "O", "Aacu"), (0x00DA, "U", "Aacu"),
    (0x00DD, "Y", "Aacu"), (0x0106, "C", "Aacu"), (0x0143, "N", "Aacu"), (0x015A, "S", "Aacu"),
    (0x00C0, "A", "Agrv"), (0x00CC, "I", "Agrv"), (0x00D2, "O", "Agrv"), (0x00D9, "U", "Agrv"),
    (0x00C2, "A", "Acir"), (0x00CE, "I", "Acir"), (0x00D4, "O", "Acir"), (0x00DB, "U", "Acir"),
    (0x00C4, "A", "Adie"), (0x00CF, "I", "Adie"), (0x00D6, "O", "Adie"), (0x00DC, "U", "Adie"),
    (0x0178, "Y", "Adie"),
]

DOTTED = {0x69, 0x6A, 0xED, 0xEC, 0xEE, 0xEF}

# Dibujados a mano (no existen en la fuente): tilde ~ y punto medio ·
TILDE = [(1, 0), (2, 0), (3, 1), (4, 1), (5, 2), (6, 2)]
MIDDOT = [(3, 5), (4, 5), (3, 6), (4, 6)]
SPECIAL = {0x00F1: "lower", 0x00D1: "upper", 0x00B7: "mid"}
# Extras: ¿ ¡ (rotados 180 de ? !) y ligaduras œ æ Œ Æ.
EXTRA_ROT = {0x00BF: 75, 0x00A1: 74}                    # color4: ? = v75, ! = v74
EXTRA_LIG = {0x0153: "oe", 0x0152: "OE", 0x00E6: "ae", 0x00C6: "AE"}


def ink(g):
    return [[1 if v == 1 else 0 for v in row] for row in g]


def rotate180(g):
    h, w = len(g), len(g[0])
    return [[g[h - 1 - y][w - 1 - x] for x in range(w)] for y in range(h)]


def hshrink(g, neww):
    h, w = len(g), len(g[0])
    out = [[0] * neww for _ in range(h)]
    for x in range(neww):
        sx = round(x * (w - 1) / max(1, neww - 1))
        for y in range(h):
            out[y][x] = g[y][sx]
    return out


def compose_extra(font_fc, w, h):
    """¿ ¡ œ æ Œ Æ desde la fuente US (color4/color0)."""
    out = {}
    for cp, v in EXTRA_ROT.items():
        if h == 8:
            continue                                    # el menu no usa ¿¡
        g = auto_shadow(rotate180(ink(font_fc.glyph(v))), w, h)
        out[cp] = (g, "comp")
    half = w // 2
    for cp, pair in EXTRA_LIG.items():
        l1, l2 = pair[0], pair[1]
        lg = hshrink(ink(font_fc.glyph(base_value(ord(l1)))), half)
        rg = hshrink(ink(font_fc.glyph(base_value(ord(l2)))), w - half)
        g = [[0] * w for _ in range(h)]
        for y in range(h):
            for x in range(half):
                g[y][x] = lg[y][x]
            for x in range(w - half):
                g[y][half + x] = rg[y][x]
        out[cp] = (auto_shadow(g, w, h), "comp")
    return out

# Marcas para la fuente 8x8 (color0, menu): la ROM no trae acentos, se dibujan a mano.
# (dy, dx) relativos a la marca; se colocan centradas encima del cuerpo.
HAND = {
    "acute": [(0, 4), (1, 3)], "grave": [(0, 3), (1, 4)],
    "circ": [(0, 3), (0, 4), (1, 2), (1, 5)], "diaer": [(0, 3), (0, 5)],
    "tilde": [(0, 3), (0, 4), (1, 4), (1, 5)],
}
CED = [(6, 3), (7, 3)]
MARK_KEY = {"apto": "acute", "agrv": "grave", "acir": "circ", "adie": "diaer",
            "Aacu": "acute", "Agrv": "grave", "Acir": "circ", "Adie": "diaer"}


def compose_color0(font_fc, w, h):
    """Compone acentos para 8x8 desde la letra base + marcas dibujadas a mano."""
    acc = {}
    for cp, letter, mark_name in COMPOSE:
        base = font_fc.glyph(base_value(ord(letter)))
        if ord(letter) in DOTTED:
            base = strip_dot(base, 2)
        if letter.isupper():
            base = compress(base, 2, h - 1, w, h)
        bb = bbox(base)
        if bb is None:
            continue
        out = [row[:] for row in base]
        if mark_name.endswith("ced"):
            pts = CED
            dx = (bb[0] + bb[2]) // 2 - 3
            dy = bb[3] - 6
        else:
            pts = HAND[MARK_KEY[mark_name]]
            mcx = (min(p[1] for p in pts) + max(p[1] for p in pts)) // 2
            dx = (bb[0] + bb[2]) // 2 - mcx
            dy = bb[1] - 2
        for (py, px) in pts:
            nx, ny = px + dx, py + dy
            if 0 <= nx < w and 0 <= ny < h:
                out[ny][nx] = 1
        acc[cp] = (auto_shadow(out, w, h), "comp")
    for cp, kind in SPECIAL.items():
        if kind == "mid":
            g = [[0] * w for _ in range(h)]
            for (x, y) in MIDDOT:
                if y < h and x < w:
                    g[y][x] = 1
            acc[cp] = (g, "comp")
        else:
            up = kind == "upper"
            letter = "N" if up else "n"
            base = font_fc.glyph(base_value(ord(letter)))
            if up:
                base = compress(base, 2, h - 1, w, h)
                top = 0
            else:
                bb = bbox(base)
                top = max(0, bb[1] - 3)
            g = [row[:] for row in base]
            for (x, y) in [(1, 0), (2, 0), (3, 1), (4, 1)]:
                yy = top + y
                if 0 <= yy < h and x < w:
                    g[yy][x] = 1
            acc[cp] = (auto_shadow(g, w, h), "comp")
    acc.update(compose_extra(font_fc, w, h))
    return acc

OUR_BASE = 200
CODE_BASE = 0xB1A1


def load(path):
    with open(path, "rb") as f:
        return f.read()


class Font:
    def __init__(self, rom, off, stride, w, h, n):
        self.data = load(rom)
        self.off, self.stride, self.w, self.h, self.n = off, stride, w, h, n

    def glyph(self, v):
        blk = self.data[self.off + (v >> 1) * self.stride:
                        self.off + ((v >> 1) + 1) * self.stride]
        par = v & 1
        pix = [[0] * self.w for _ in range(self.h)]
        for i in range(self.w * self.h):
            b = blk[i >> 1]
            nb = i & 1
            val = (b >> 4) & 0xF if nb == 0 else b & 0xF
            pix[i // self.w][i % self.w] = (val >> 2) & 3 if par == 0 else val & 3
        return pix


def bbox(g, y0=0, y1=None):
    y1 = len(g) if y1 is None else y1
    xs, ys = [], []
    for y in range(y0, y1):
        for x in range(len(g[0])):
            if g[y][x]:
                xs.append(x)
                ys.append(y)
    return (min(xs), min(ys), max(xs), max(ys)) if xs else None


def extract_mark(font_eu, mark_name, base_glyph, w, h):
    src_cp, mode = MARKS[mark_name]
    g = font_eu.glyph(REAL[src_cp])
    if mode == "row0":
        return [(x, 0, g[0][x]) for x in range(w) if g[0][x]]
    if mode == "cedilla":
        bb = bbox(base_glyph)
        y0 = (bb[3] - 2) if bb else h - 4
        return [(x, y, g[y][x]) for y in range(y0 + 1, h) for x in range(w) if g[y][x]]
    bb = bbox(base_glyph)
    top = bb[1] if bb else h // 2
    return [(x, y, g[y][x]) for y in range(0, top) for x in range(w) if g[y][x]]


def strip_dot(g, rows):
    out = [row[:] for row in g]
    for y in range(min(rows, len(out))):
        out[y] = [0] * len(out[0])
    return out


def paste(base, mark, dx, dy, w, h):
    out = [row[:] for row in base]
    for (x, y, v) in mark:
        nx, ny = x + dx, y + dy
        if 0 <= nx < w and 0 <= ny < h:
            if v == 1 or out[ny][nx] == 0:
                out[ny][nx] = v
    return out


def place_top(base, mark, w, h):
    bb = bbox(base)
    if bb is None or not mark:
        return base
    mcx = (min(m[0] for m in mark) + max(m[0] for m in mark)) // 2
    my1 = max(m[1] for m in mark)
    dx = (bb[0] + bb[2]) // 2 - mcx
    dy = bb[1] - 1 - my1
    return paste(base, mark, dx, dy, w, h)


def place_cedilla(base, mark, w, h):
    bb = bbox(base)
    if bb is None or not mark:
        return base
    mcx = (min(m[0] for m in mark) + max(m[0] for m in mark)) // 2
    my0 = min(m[1] for m in mark)
    dx = (bb[0] + bb[2]) // 2 - mcx
    dy = bb[3] - my0
    return paste(base, mark, dx, dy, w, h)


def compress(g, top_t, bot_t, w, h):
    """Comprime verticalmente el glifo a las filas [top_t, bot_t]."""
    bb = bbox(g)
    out = [[0] * w for _ in range(h)]
    if bb is None:
        return out
    sy0, sy1 = bb[1], bb[3]
    for ty in range(top_t, bot_t + 1):
        sy = sy0 + round((ty - top_t) * (sy1 - sy0) / max(1, bot_t - top_t))
        out[ty] = g[sy][:]
    return out


def calv(w, h):
    """Altura de mayusculas en la fuente (fila 0..9 en color4)."""
    return 9


def auto_shadow(g, w, h):
    out = [row[:] for row in g]
    for y in range(h):
        for x in range(w):
            if g[y][x] == 1 and x + 1 < w and y + 1 < h and out[y + 1][x + 1] == 0:
                out[y + 1][x + 1] = 2
    return out


def real_for_letter(font_eu, letter, w, h):
    for cp, v in REAL.items():
        if cp < 0x80 or chr(cp).upper() != letter.upper():
            continue
        g = font_eu.glyph(v)
        if letter.isupper():
            g[0] = [0] * w
        return g
    return None


def compose_all(font_fc, font_eu, w, h):
    if h == 8:                                  # color0 (menu); color4 es 8x12 (w tambien 8)
        return compose_color0(font_fc, w, h)
    acc = {}
    for cp, v in REAL.items():
        acc[cp] = (font_eu.glyph(v), "real")            # minusculas reales directas
    for cp, letter, mark_name in COMPOSE:
        if cp in acc:
            continue
        if letter.isupper():
            base = real_for_letter(font_eu, letter, w, h)
            if base is None:
                base = compress(font_fc.glyph(base_value(ord(letter))), 2, calv(w, h), w, h)
        else:
            base = font_fc.glyph(base_value(ord(letter)))
            if ord(letter) in DOTTED:
                base = strip_dot(base, 4)
        mark = extract_mark(font_eu, mark_name, base, w, h)
        g = place_cedilla(base, mark, w, h) if mark_name.endswith("ced") else place_top(base, mark, w, h)
        acc[cp] = (auto_shadow(g, w, h), "comp")
    # especiales
    for cp, kind in SPECIAL.items():
        if kind == "mid":
            g = [[0] * w for _ in range(h)]
            for (x, y) in MIDDOT:
                g[y][x] = 1
            acc[cp] = (g, "comp")
        else:
            up = kind == "upper"
            letter = "N" if up else "n"
            if up:
                base = real_for_letter(font_eu, "N", w, h)
                if base is None:
                    base = compress(font_fc.glyph(base_value(ord("N"))), 2, calv(w, h), w, h)
                top = 0
            else:
                base = font_fc.glyph(base_value(ord(letter)))
                top = bbox(base)[1] - 3
            g = [row[:] for row in base]
            for (x, y) in TILDE:
                yy = top + y
                if 0 <= yy < h and 0 <= x < w:
                    g[yy][x] = 1
            acc[cp] = (auto_shadow(g, w, h), "comp")
    acc.update(compose_extra(font_fc, w, h))
    return acc


# ---------- PNG ----------
def png_read(path):
    """Lector PNG minimo (8 bits, RGBA o RGB, filtros 0-4). Devuelve (w,h,filas RGBA)."""
    data = load(path)
    assert data[:8] == b"\x89PNG\r\n\x1a\n", "no es PNG"
    i = 8
    w = h = ct = None
    idat = b""
    while i < len(data):
        ln = struct.unpack(">I", data[i:i + 4])[0]
        typ = data[i + 4:i + 8]
        body = data[i + 8:i + 8 + ln]
        if typ == b"IHDR":
            w, h, bd, ct = struct.unpack(">IIBB", body[:10])
            assert bd == 8, "solo 8 bpp"
        elif typ == b"IDAT":
            idat += body
        elif typ == b"IEND":
            break
        i += 12 + ln
    bpp = 4 if ct == 6 else 3
    raw = zlib.decompress(idat)
    stride = w * bpp
    out = []
    prev = bytearray(stride)
    pos = 0
    for _ in range(h):
        f = raw[pos]
        pos += 1
        line = bytearray(raw[pos:pos + stride])
        pos += stride
        for x in range(stride):
            a = line[x - bpp] if x >= bpp else 0
            b = prev[x]
            c = prev[x - bpp] if x >= bpp else 0
            if f == 1:
                line[x] = (line[x] + a) & 0xFF
            elif f == 2:
                line[x] = (line[x] + b) & 0xFF
            elif f == 3:
                line[x] = (line[x] + (a + b) // 2) & 0xFF
            elif f == 4:
                p = a + b - c
                pa, pb, pc = abs(p - a), abs(p - b), abs(p - c)
                pr = a if (pa <= pb and pa <= pc) else (b if pb <= pc else c)
                line[x] = (line[x] + pr) & 0xFF
        row = []
        for x in range(w):
            if bpp == 4:
                row.append(tuple(line[x * 4:x * 4 + 4]))
            else:
                r, g, b = line[x * 3:x * 3 + 3]
                row.append((r, g, b, 255))
        out.append(row)
        prev = line
    return w, h, out


def import_from_sheet(path, cps, cellw, cellh, scale, gap, cols, lscale=2):
    Wp, Hp, img = png_read(path)
    label_h = 5 * lscale + 3
    chh = cellh * scale + label_h
    cw = cellw * scale
    acc = {}
    for i, cp in enumerate(cps):
        gx = (i % cols) * (cw + gap) + gap
        gy = (i // cols) * (chh + gap) + gap
        oy = gy + label_h
        g = [[0] * cellw for _ in range(cellh)]
        for y in range(cellh):
            for x in range(cellw):
                votes = {0: 0, 1: 0, 2: 0}
                for dy in range(scale):
                    for dx in range(scale):
                        r, gg, b, a = img[oy + y * scale + dy][gx + x * scale + dx]
                        if a < 128 or (r > 235 and gg > 235 and b > 235):
                            votes[0] += 1
                        elif r - max(gg, b) > 60:
                            votes[2] += 1
                        else:
                            votes[1] += 1
                g[y][x] = max(votes, key=votes.get)
        acc[cp] = (g, "sheet")
    return acc


def png_write(path, img, w, h):
    raw = b"".join(b"\x00" + bytes(row) for row in img)

    def chunk(t, d):
        return struct.pack(">I", len(d)) + t + d + struct.pack(">I", zlib.crc32(t + d) & 0xFFFFFFFF)
    with open(path, "wb") as f:
        f.write(b"\x89PNG\r\n\x1a\n"
                + chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 6, 0, 0, 0))
                + chunk(b"IDAT", zlib.compress(raw, 9)) + chunk(b"IEND", b""))


# glifos de 3x5 para etiquetas (solo ASCII mayusculas/digitos/simbolos)
G = {
    "0": ["111", "101", "101", "101", "111"], "1": ["010", "110", "010", "010", "111"],
    "2": ["111", "001", "111", "100", "111"], "3": ["111", "001", "111", "001", "111"],
    "4": ["101", "101", "111", "001", "001"], "5": ["111", "100", "111", "001", "111"],
    "6": ["111", "100", "111", "101", "111"], "7": ["111", "001", "001", "001", "001"],
    "8": ["111", "101", "111", "101", "111"], "9": ["111", "101", "111", "001", "111"],
    "A": ["010", "101", "111", "101", "101"], "B": ["110", "101", "110", "101", "110"],
    "C": ["011", "100", "100", "100", "011"], "D": ["110", "101", "101", "101", "110"],
    "E": ["111", "100", "110", "100", "111"], "F": ["111", "100", "110", "100", "100"],
    "G": ["011", "100", "101", "101", "011"], "H": ["101", "101", "111", "101", "101"],
    "I": ["111", "010", "010", "010", "111"], "J": ["001", "001", "001", "101", "010"],
    "K": ["101", "101", "110", "101", "101"], "L": ["100", "100", "100", "100", "111"],
    "M": ["101", "111", "111", "101", "101"], "N": ["101", "111", "111", "111", "101"],
    "O": ["010", "101", "101", "101", "010"], "P": ["110", "101", "110", "100", "100"],
    "Q": ["010", "101", "101", "111", "011"], "R": ["110", "101", "110", "101", "101"],
    "S": ["011", "100", "010", "001", "110"], "T": ["111", "010", "010", "010", "010"],
    "U": ["101", "101", "101", "101", "111"], "V": ["101", "101", "101", "101", "010"],
    "W": ["101", "101", "111", "111", "101"], "X": ["101", "101", "010", "101", "101"],
    "Y": ["101", "101", "010", "010", "010"], "Z": ["111", "001", "010", "100", "111"],
    "'": ["010", "010", "000", "000", "000"], "`": ["100", "010", "000", "000", "000"],
    "^": ["010", "101", "000", "000", "000"], ":": ["000", "010", "000", "010", "000"],
    "~": ["000", "011", "100", "000", "000"], ",": ["000", "000", "000", "010", "100"],
    ".": ["000", "000", "000", "000", "010"], "/": ["001", "001", "010", "100", "100"],
    "?": ["110", "001", "010", "000", "010"], " ": ["000", "000", "000", "000", "000"],
    "-": ["000", "000", "111", "000", "000"],
}


def label(img, x0, y0, text, color, Wp, Hp, ls=1):
    cx = x0
    for ch in text.upper():
        pat = G.get(ch, G["?"])
        for ry, row in enumerate(pat):
            for rx, b in enumerate(row):
                if b == "1":
                    for sy in range(ls):
                        for sx in range(ls):
                            x, y = cx + rx * ls + sx, y0 + ry * ls + sy
                            if 0 <= x < Wp and 0 <= y < Hp:
                                img[y * Wp + x] = list(color)
        cx += 4 * ls


def make_sheet(path, entries, cellw, cellh, scale, gap, cols, editable, lscale=1):
    """entries: lista de (label, glyph). editable: True -> tinta negro/sombra rojo; False -> gris."""
    cw = cellw * scale
    label_h = 5 * lscale + 3
    chh = cellh * scale + label_h
    rows = (len(entries) + cols - 1) // cols
    Wp = cols * (cw + gap) + gap
    Hp = rows * (chh + gap) + gap
    img = [[255, 255, 255, 255] for _ in range(Wp * Hp)] if editable else \
          [[24, 24, 28, 255] for _ in range(Wp * Hp)]

    def put(x, y, rgba):
        if 0 <= x < Wp and 0 <= y < Hp:
            img[y * Wp + x] = list(rgba)
    for i, (lab, g) in enumerate(entries):
        gx = (i % cols) * (cw + gap) + gap
        gy = (i // cols) * (chh + gap) + gap
        label(img, gx, gy, lab, [90, 90, 90, 255], Wp, Hp, lscale)
        oy = gy + label_h
        for y in range(cellh):
            for x in range(cellw):
                v = g[y][x]
                if v == 0:
                    continue
                if editable:
                    col = [0, 0, 0, 255] if v == 1 else [220, 40, 40, 255]
                else:
                    col = [235, 235, 235, 255] if v == 1 else [120, 120, 120, 255]
                for dy in range(scale):
                    for dx in range(scale):
                        put(gx + x * scale + dx, oy + y * scale + dy, col)
    out = []
    for y in range(Hp):
        row = []
        for x in range(Wp):
            row += img[y * Wp + x]
        out.append(row)
    png_write(path, out, Wp, Hp)


def pack_even(g, stride):
    blk = bytearray(stride)
    for i in range(len(g) * len(g[0])):
        v = g[i // len(g[0])][i % len(g[0])] & 3
        if v:
            blk[i >> 1] |= (v << (4 if (i & 1) == 0 else 0)) << 2
    return bytes(blk)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--style", default="color4", choices=list(FONTS))
    ap.add_argument("--sheet")
    ap.add_argument("--ref")
    ap.add_argument("--from-sheet", help="PNG editado que se importa (en vez de componer)")
    ap.add_argument("--out")
    ap.add_argument("--report")
    ap.add_argument("--preview", action="store_true")
    ap.add_argument("--ref-scale", type=int, default=16)
    ap.add_argument("--sheet-scale", type=int, default=8)
    ap.add_argument("--sheet-lscale", type=int, default=2)
    args = ap.parse_args()

    rom, off, stride, w, h, n = FONTS[args.style]
    font_fc = Font(rom, off, stride, w, h, n)
    font_eu = Font(*EU_COLOR4)
    acc = compose_all(font_fc, font_eu, w, h)

    if args.from_sheet:
        cps = sorted(acc)
        acc = import_from_sheet(args.from_sheet, cps, w, h, args.sheet_scale,
                                args.sheet_scale, 8 if w >= 12 else 12, args.sheet_lscale)
        print("importado:", args.from_sheet, len(acc), "glifos")

    # Normaliza nivel 3 -> 2 (el motor pinta nivel>=2 igual): hace la ida/vuelta exacta.
    acc = {cp: ([[2 if v == 3 else v for v in row] for row in g], src)
           for cp, (g, src) in acc.items()}

    if args.preview:
        for cp in sorted(acc):
            print("U+%04X %s" % (cp, acc[cp][1]))
            for row in acc[cp][0]:
                print("   " + "".join(".#+@"[v] for v in row))
            print()

    # etiquetas ASCII
    MNEM = {"real": "", "comp": ""}
    entries = []
    for cp in sorted(acc):
        g, src = acc[cp]
        entries.append((mnemonic(cp), g))

    if args.sheet:
        make_sheet(args.sheet, entries, w, h, args.sheet_scale, args.sheet_scale,
                   8 if w >= 12 else 12, editable=True, lscale=args.sheet_lscale)
        print("sheet:", args.sheet)
    if args.ref:
        make_sheet(args.ref, entries, w, h, args.ref_scale, args.ref_scale,
                   8 if w >= 12 else 12, editable=False, lscale=2)
        print("ref:", args.ref)

    if args.out:
        emit_header(args.out, acc, w, h, stride)
        print("header:", args.out)
    if args.report:
        emit_report(args.report, acc, args.style, w, h)
        print("report:", args.report)


def mnemonic(cp):
    ch = chr(cp)
    import unicodedata
    d = unicodedata.normalize("NFD", ch)
    base = d[0].upper()
    marks = "".join(c for c in d[1:])
    sym = {"\u0301": "'", "\u0300": "`", "\u0302": "^", "\u0308": ":", "\u0303": "~",
           "\u0327": ",", "\u030a": "o"}
    return base + "".join(sym.get(m, "?") for m in marks)


def emit_header(path, acc, w, h, stride):
    cps = sorted(acc)
    with open(path, "w") as f:
        f.write("// Generado por tools/text/build_font.py -- NO editar a mano.\n")
        f.write("#pragma once\n#include <cstdint>\n\n")
        f.write("namespace hh {\n")
        f.write("inline constexpr unsigned kGameGlyphW = %d;\n" % w)
        f.write("inline constexpr unsigned kGameGlyphH = %d;\n" % h)
        f.write("inline constexpr unsigned kGameGlyphStride = %d;\n" % stride)
        f.write("struct GameGlyph { uint16_t cp; uint16_t code; uint16_t value;"
                " uint8_t block[%d]; };\n" % stride)
        f.write("inline constexpr GameGlyph kGameGlyphs[] = {\n")
        for i, cp in enumerate(cps):
            g, _ = acc[cp]
            blk = pack_even(g, stride)
            code = CODE_BASE + i
            value = OUR_BASE + 2 * i
            f.write("    {0x%04X, 0x%04X, %d, {%s}},\n"
                    % (cp, code, value, ", ".join("0x%02X" % b for b in blk)))
        f.write("};\n")
        f.write("inline constexpr unsigned kGameGlyphCount = sizeof(kGameGlyphs)/sizeof(kGameGlyphs[0]);\n")
        f.write("}  // namespace hh\n")


def emit_report(path, acc, style, w, h):
    with open(path, "w") as f:
        f.write("# Cobertura de acentos (%s, %dx%d)\n\n" % (style, w, h))
        f.write("| codepoint | char | mnemonic | origen | valor | code |\n|---|---|---|---|---|---|\n")
        for i, cp in enumerate(sorted(acc)):
            g, src = acc[cp]
            f.write("| U+%04X | %s | %s | %s | %d | 0x%04X |\n"
                    % (cp, chr(cp), mnemonic(cp), src, OUR_BASE + 2 * i, CODE_BASE + i))
        f.write("\n- real = glifo acentuado real de la ROM EU.\n")
        f.write("- comp = compuesto desde letra base + marca real (revisar en la hoja).\n")


if __name__ == "__main__":
    main()
