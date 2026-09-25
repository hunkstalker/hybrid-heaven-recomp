#!/usr/bin/env python3
"""Marks overlay para el MENU (mayusculas).

El menu lo dibuja el overlay: para una letra acentuada pintamos la letra BASE tal cual
(color0, 8x8, sin comprimir) + un sprite de MARCA centrado encima. Asi las mayusculas no se
deforman.

La hoja trae UNA CELDA POR SIMBOLO, con una letra de referencia (A/N/C) dentro para que
dibujes la marca en una capa aparte. Luego exportas SOLO la capa de marcas.

Geometria exacta (la del menu):
  - celda 8 (ancho) x 12 (alto) px de fuente.
  - la letra 8x8 va en las filas 2..9.
  - filas 0..1: tilde.  filas 10..11: cedilla.

Uso:
  python3 tools/text/menu_marks.py --template work/fonts/menu_marks_base.png \
      work/fonts/menu_marks_layer.png
  python3 tools/text/menu_marks.py --from-layer work/fonts/menu_marks_layer.png \
      --out include/hh/menu_marks.h
"""
import argparse
import os
import sys
import unicodedata

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import build_font as bf  # noqa: E402

W, LH, CH = 8, 8, 12
LETTER_TOP = 2
COLS = 9
MAXPIX = W * CH
GRAY = [150, 150, 150, 255]

# (marca, letra de referencia, codepoints que la usan)
ACCENTS = [
    ("acute",   "A", [0x00C1, 0x00C9, 0x00CD, 0x00D3, 0x00DA, 0x00DD]),  # Á É Í Ó Ú Ý
    ("grave",   "A", [0x00C0, 0x00C8, 0x00CC, 0x00D2, 0x00D9]),          # À È Ì Ò Ù
    ("circ",    "A", [0x00C2, 0x00CA, 0x00CE, 0x00D4, 0x00DB]),          # Â Ê Î Ô Û
    ("diaer",   "A", [0x00C4, 0x00CB, 0x00CF, 0x00D6, 0x00DC, 0x0178]),  # Ä Ë Ï Ö Ü Ÿ
    ("tilde",   "N", [0x00D1]),                                          # Ñ
    ("cedilla", "C", [0x00C7]),                                          # Ç
]
MARK_LABEL = {"acute": "ACU", "grave": "GRV", "circ": "CIR",
              "diaer": "DIA", "tilde": "TIL", "cedilla": "CED"}
STANDALONE = [("MID", 0x00B7), ("AE", 0x00C6), ("OE", 0x0152)]   # · Æ Œ
AUTO = [(0x00BF, 75), (0x00A1, 74)]                              # ¿ ¡ = girar ? !

# símbolo exacto que el mantenedor debe dibujar en cada celda
SYMBOL = {
    "acute":   ("´", "U+00B4", "ACUTE ACCENT"),
    "grave":   ("`", "U+0060", "GRAVE ACCENT"),
    "circ":    ("^", "U+02C6", "MODIFIER LETTER CIRCUMFLEX ACCENT"),
    "diaer":   ("¨", "U+00A8", "DIAERESIS"),
    "tilde":   ("~", "U+02DC", "SMALL TILDE"),
    "cedilla": ("¸", "U+00B8", "CEDILLA"),
}
STANDALONE_SYM = {
    0x00B7: ("·", "U+00B7", "MIDDLE DOT"),
    0x00C6: ("Æ", "U+00C6", "LATIN CAPITAL LETTER AE"),
    0x0152: ("Œ", "U+0152", "LATIN CAPITAL LIGATURE OE"),
}


def targets_for(name):
    for n, _ref, cps in ACCENTS:
        if n == name:
            return " ".join(chr(c) for c in cps)
    return ""


def legend_rows():
    rows = []
    for i, c in enumerate(draw_cells()):
        if c["kind"] == "accent":
            sym, u, name = SYMBOL[c["name"]]
            rows.append((i, "tilde sobre " + c["ref"], sym, u, name, targets_for(c["name"])))
        else:
            sym, u, name = STANDALONE_SYM[c["cp"]]
            rows.append((i, "símbolo completo", sym, u, name, "—"))
    return rows


def write_legend(path):
    with open(path, "w", encoding="utf-8") as f:
        f.write("# Leyenda de la hoja de marcas del menú\n\n")
        f.write("Cada celda de `menu_marks_layer.png`, en orden. Dibuja el símbolo indicado ")
        f.write("sobre la letra de referencia (o el símbolo entero en las celdas sueltas).\n\n")
        f.write("| celda | qué dibujar | símbolo | code point | nombre | sirve para |\n")
        f.write("|---|---|---|---|---|---|\n")
        for (i, what, sym, u, name, tgt) in legend_rows():
            f.write("| %d | %s | `%s` | %s | %s | %s |\n" % (i, what, sym, u, name, tgt))
    print("leyenda:", path)


def base_letter(cp):
    """Letra base del carácter acentuado (Í -> I)."""
    d = unicodedata.normalize("NFD", chr(cp))
    return d[0].upper() if d and d[0].isalpha() else None


def draw_cells():
    """Celdas que el mantenedor debe dibujar (acentos + símbolos sueltos)."""
    out = []
    for name, ref, cps in ACCENTS:
        out.append({"kind": "accent", "name": name, "ref": ref, "cps": cps,
                    "label": MARK_LABEL[name]})
    for lab, cp in STANDALONE:
        out.append({"kind": "standalone", "cp": cp, "label": lab})
    return out


def setpx(img, Wp, Hp, x, y, rgba):
    if 0 <= x < Wp and 0 <= y < Hp:
        img[y * Wp + x] = list(rgba)


def make_template(base_path, layer_path, scale=12, gap=None, lscale=2):
    font = bf.Font(*bf.FONTS["color0"])
    gap = scale if gap is None else gap
    lst = draw_cells()
    label_h = 5 * lscale + 4
    cw, chh = W * scale, CH * scale + label_h
    rows = (len(lst) + COLS - 1) // COLS
    Wp, Hp = COLS * (cw + gap) + gap, rows * (chh + gap) + gap
    base = [[255, 255, 255, 255] for _ in range(Wp * Hp)]
    layer = [[0, 0, 0, 0] for _ in range(Wp * Hp)]

    for i, c in enumerate(lst):
        gx = (i % COLS) * (cw + gap) + gap
        gy = (i // COLS) * (chh + gap) + gap
        bf.label(base, gx, gy, "%d:%s" % (i, c["label"]), [90, 90, 90, 255], Wp, Hp, lscale)
        oy = gy + label_h
        # GUÍAS (azul claro, no son glifos): techo de mayúscula (fila 2) y base (fila 10)
        # + tick central arriba (centro horizontal).
        guide = [130, 170, 255, 255]
        for x in range(W * scale):
            setpx(base, Wp, Hp, gx + x, oy + LETTER_TOP * scale, guide)
            setpx(base, Wp, Hp, gx + x, oy + (LETTER_TOP + LH) * scale, guide)
        setpx(base, Wp, Hp, gx + W * scale // 2, oy + LETTER_TOP * scale - 4, guide)
        ref = c.get("ref")
        if ref:
            g = font.glyph(bf.base_value(ord(ref)))
            for y in range(LH):
                for x in range(W):
                    v = g[y][x]
                    if v == 0:
                        continue
                    col = [0, 0, 0, 255] if v == 1 else GRAY
                    for dy in range(scale):
                        for dx in range(scale):
                            setpx(base, Wp, Hp, gx + x * scale + dx,
                                  oy + (LETTER_TOP + y) * scale + dy, col)
    png(base_path, base, Wp, Hp)
    png(layer_path, layer, Wp, Hp)
    print("base :", base_path, "%dx%d" % (Wp, Hp))
    print("layer:", layer_path, "%dx%d" % (Wp, Hp))
    print("celdas:", len(lst), "scale", scale)


def png(path, img, w, h):
    rows = []
    for y in range(h):
        row = []
        for x in range(w):
            row += img[y * w + x]
        rows.append(row)
    bf.png_write(path, rows, w, h)


def add_shadow_cell(cell):
    """Copia la tinta (nivel 1) -> sombra (nivel 2) desplazada abajo-derecha, dentro de la celda."""
    out = [row[:] for row in cell]
    for y in range(CH):
        for x in range(W):
            if cell[y][x] == 1 and x + 1 < W and y + 1 < CH and out[y + 1][x + 1] == 0:
                out[y + 1][x + 1] = 2
    return out


def ink_bbox(cell):
    xs = [x for y in range(CH) for x in range(W) if cell[y][x]]
    ys = [y for y in range(CH) for x in range(W) if cell[y][x]]
    if not xs:
        return None
    return min(xs), min(ys), max(xs), max(ys)


def read_cell(img, i, scale, lscale=2, gap=None):
    font = bf.Font(*bf.FONTS["color0"])
    gap = scale if gap is None else gap
    label_h = 5 * lscale + 4
    cw, chh = W * scale, CH * scale + label_h
    gx = (i % COLS) * (cw + gap) + gap
    gy = (i // COLS) * (chh + gap) + gap
    oy = gy + label_h
    cell = [[0] * W for _ in range(CH)]
    thr = 0.20 * scale * scale          # evita engordar el trazo (varios px de mas por bloque)
    for y in range(CH):
        for x in range(W):
            n = sum(1 for dy in range(scale) for dx in range(scale)
                    if img[oy + y * scale + dy][gx + x * scale + dx][3] > 128)
            cell[y][x] = 1 if n > thr else 0
    return cell


def crop_shift(cell):
    xs = [x for y in range(CH) for x in range(W) if cell[y][x]]
    ys = [y for y in range(CH) for x in range(W) if cell[y][x]]
    if not xs:
        return 0, 0, 0, 0, []
    x0, x1, y0, y1 = min(xs), max(xs), min(ys), max(ys)
    w, h = x1 - x0 + 1, y1 - y0 + 1
    pix = [cell[y][x] for y in range(y0, y1 + 1) for x in range(x0, x1 + 1)]
    return w, h, x0, y0 - LETTER_TOP, pix


def shadow(pix, w, h):
    """Genera sombra (nivel 2) abajo-derecha."""
    out = pix[:]
    for y in range(h):
        for x in range(w):
            if pix[y * w + x] == 1 and x + 1 < w and y + 1 < h and out[(y + 1) * w + x + 1] == 0:
                out[(y + 1) * w + x + 1] = 2
    return out


def from_layer(path, out, scale=12):
    """Extrae la FORMA de cada marca. La posicion vertical se fija por TIPO de marca:
    encima (dy = -h) para tildes, debajo (dy = 8) para cedilla; sueltas centradas. dx=0
    (el overlay centra horizontalmente)."""
    font = bf.Font(*bf.FONTS["color0"])
    _, _, img = bf.png_read(path)
    lst = draw_cells()
    marks = []
    for i, c in enumerate(lst):
        ink = read_cell(img, i, scale)
        ib = ink_bbox(ink)
        if ib is None:                    # celda sin dibujar
            marks.append((0, 0, 0, 0, []))
            continue
        w, h, _dx, _dy, pix = crop_shift(ink)   # SOLO tinta (sin sombra): como tu referencia
        dy = ib[1] - LETTER_TOP          # respeta la altura a la que lo dibujaste (la letra va en fila 2)
        marks.append((w, h, 0, dy, pix))
    for cp, v in AUTO:                   # ¿ ¡ (con sombra)
        src = font.glyph(v)
        cell = [[0] * W for _ in range(CH)]
        for y in range(LH):
            for x in range(W):
                cell[LETTER_TOP + LH - 1 - y][W - 1 - x] = 1 if src[y][x] else 0
        w, h, _dx, _dy, pix = crop_shift(add_shadow_cell(cell))
        marks.append((w, h, 0, 0, pix))
    emit(out, marks)


def emit(path, marks):
    chars = []
    for mi, (name, ref, cps) in enumerate(ACCENTS):
        for cp in cps:
            # letra base = la del PROPIO carácter (Í -> I), no la de referencia (A).
            base = base_letter(cp)
            chars.append((cp, bf.base_value(ord(base)), mi))
    base_i = len(ACCENTS)
    for i, (lab, cp) in enumerate(STANDALONE):
        chars.append((cp, 0, base_i + i))
    auto_i = base_i + len(STANDALONE)
    for i, (cp, _v) in enumerate(AUTO):
        chars.append((cp, 0, auto_i + i))

    with open(path, "w") as f:
        f.write("// Generado por tools/text/menu_marks.py -- NO editar a mano.\n")
        f.write("#pragma once\n#include <cstdint>\n\n")
        f.write("namespace hh {\n")
        f.write("inline constexpr unsigned kMenuGlyphW = %d;\n" % W)
        f.write("inline constexpr unsigned kMenuGlyphH = %d;\n" % CH)
        f.write("inline constexpr unsigned kMenuGlyphTop = %d;\n" % LETTER_TOP)
        f.write("struct MenuMark { uint8_t w, h; int8_t dx, dy; uint8_t pix[%d]; };\n" % MAXPIX)
        f.write("inline constexpr MenuMark kMenuMarks[] = {\n")
        for (w, h, dx, dy, pix) in marks:
            pad = list(pix) + [0] * (MAXPIX - len(pix))
            f.write("    {%d, %d, %d, %d, {%s}},\n"
                    % (w, h, dx, dy, ", ".join(str(p) for p in pad)))
        f.write("};\n")
        f.write("inline constexpr unsigned kMenuMarkCount ="
                " sizeof(kMenuMarks)/sizeof(kMenuMarks[0]);\n")
        f.write("struct MenuChar { uint16_t cp; uint16_t base_value; uint8_t mark; };\n")
        f.write("inline constexpr MenuChar kMenuChars[] = {\n")
        for (cp, bv, mi) in chars:
            f.write("    {0x%04X, %d, %d},\n" % (cp, bv, mi))
        f.write("};\n")
        f.write("inline constexpr unsigned kMenuCharCount ="
                " sizeof(kMenuChars)/sizeof(kMenuChars[0]);\n")
        f.write("}  // namespace hh\n")
    print("header:", path, len(chars), "caracteres,", len(marks), "marcas")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--template", nargs=2, metavar=("BASE", "LAYER"))
    ap.add_argument("--from-layer")
    ap.add_argument("--out", default="include/hh/menu_marks.h")
    ap.add_argument("--legend", default="work/fonts/menu_marks_legend.md")
    ap.add_argument("--scale", type=int, default=12)
    args = ap.parse_args()
    if args.template:
        make_template(args.template[0], args.template[1], scale=args.scale)
        write_legend(args.legend)
    elif args.from_layer:
        from_layer(args.from_layer, args.out, scale=args.scale)
    else:
        ap.error("usa --template o --from-layer")


if __name__ == "__main__":
    main()
