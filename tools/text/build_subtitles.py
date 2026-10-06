#!/usr/bin/env python3
"""Convierte un guion de subtítulos (formato de referencia) a los datos del port.

Entrada (assets de trabajo, editable a mano): un `.txt` con:
    # name: <nombre-de-secuencia>
    [IN mm:ss] [OUT mm:ss]
    texto del bloque (varias líneas se unen con espacio; una línea en blanco = salto de párrafo)

Salidas:
    assets/subtitles/<name>.timing.txt   -> `id in_ms out_ms` (única fuente de tiempos)
    assets/lang/subtitles_en.txt         -> `<name>.<id>=texto` (texto inglés; se conservan
                                            las entradas de otras secuencias)

Las traducciones (assets/lang/subtitles_<code>.txt) se mantienen aparte a mano.

Uso:
    python3 tools/text/build_subtitles.py notes/reference/Hybrid-Heaven-Intro-Dialogues.txt
"""
import argparse
import os
import re
import sys

# Header: `[N]` de línea (opcional, prefijo) + `[IN ...] [OUT ...]` (+ `[N]` opcional como sufijo).
HEADER = re.compile(
    r"(?:\[([0-9]+)\]\s*)?\[IN\s+([0-9:.]+)\]\s*\[OUT\s+([0-9:.]+)\](?:\s*\[([0-9]+)\])?",
    re.IGNORECASE)
NAME = re.compile(r"^\s*#\s*name\s*:\s*(\S+)\s*$", re.IGNORECASE)

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))


def parse_time(s):
    """mm:ss | hh:mm:ss | segundos -> milisegundos."""
    parts = s.strip().split(":")
    if len(parts) == 3:
        h, m, sec = parts
    elif len(parts) == 2:
        h, m, sec = "0", parts[0], parts[1]
    else:
        h, m, sec = "0", "0", parts[0]
    total = int(h) * 3600 + int(m) * 60 + float(sec)
    return int(round(total * 1000))


def parse_source(path):
    name = os.path.splitext(os.path.basename(path))[0]
    blocks = []          # dict(in,out,line,raw[])
    cur = None
    with open(path, encoding="utf-8") as f:
        for raw in f:
            line = raw.rstrip("\n")
            m = NAME.match(line)
            if m:
                name = m.group(1)
                continue
            h = HEADER.search(line)
            if h:
                if cur is not None:
                    blocks.append(cur)
                line_no = h.group(1) or h.group(4) or "0"
                cur = {"in": parse_time(h.group(2)), "out": parse_time(h.group(3)),
                       "line": int(line_no), "raw": []}
                continue
            if line.lstrip().startswith("#"):
                continue
            if cur is None:
                continue
            cur["raw"].append(line.strip())

    if cur is not None:
        blocks.append(cur)

    out = []
    for b in blocks:
        if b["out"] <= b["in"]:
            continue
        # Texto: líneas no vacías se unen; línea en blanco = párrafo; línea `---`/`===` = CORTE DE
        # PÁGINA manual (se guarda como `\p`, el loader lo convierte en salto de página).
        items = []          # str = párrafo; None = corte de página
        curp = ""
        for l in b["raw"]:
            if l in ("---", "==="):
                if curp:
                    items.append(curp)
                    curp = ""
                items.append(None)
            elif l == "":
                if curp:
                    items.append(curp)
                    curp = ""
            else:
                curp = (curp + " " + l).strip() if curp else l
        if curp:
            items.append(curp)
        if not items:
            continue
        text = ""
        for it in items:
            if it is None:
                if text and not text.endswith("\\p"):
                    text += "\\p"
            else:
                if text and not text.endswith("\\p"):
                    text += "\\n"
                text += it
        if not text:
            continue
        out.append((b["in"], b["out"], b["line"], text))
    return name, out


def write_timing(path, name, blocks):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8") as f:
        f.write(f"# Generado por tools/text/build_subtitles.py — NO editar a mano.\n")
        f.write(f"# Secuencia: {name}. Tiempos en ms: id in_ms out_ms.\n")
        f.write(f"# IN = aparición; OUT = margen de salida (tiempo máximo visible).\n")
        f.write(f"# line: 0 = normal (bloque paginado); 1/2 = línea fija (arriba/abajo).\n#\n")
        for i, (in_ms, out_ms, line, _) in enumerate(blocks):
            f.write(f"{i} {in_ms} {out_ms} {line}\n")


LANGS = ["en", "es", "ca", "fr", "de"]   # idiomas con subtítulos


def read_values(path):
    vals = {}
    if os.path.exists(path):
        with open(path, encoding="utf-8") as f:
            for line in f:
                line = line.rstrip("\n")
                if not line.strip() or line.lstrip().startswith("#") or "=" not in line:
                    continue
                k, v = line.split("=", 1)
                vals[k.strip()] = v.strip()
    return vals


def write_lang(path, name, blocks, lang):
    """Escribe/actualiza el .txt de un idioma. Preserva los valores ya traducidos (correcciones) y
    las claves de otras secuencias; rellena lo que falte con el inglés. Añade `# EN:` como contexto."""
    os.makedirs(os.path.dirname(path), exist_ok=True)
    existing = read_values(path) if lang != "en" else {}

    # Conserva las líneas de OTRAS secuencias (claves que no empiezan por `<name>.`).
    keep = []
    if os.path.exists(path):
        with open(path, encoding="utf-8") as f:
            for line in f:
                line = line.rstrip("\n")
                if not line.strip() or line.lstrip().startswith("#") or "=" not in line:
                    continue
                if not line.split("=", 1)[0].strip().startswith(name + "."):
                    keep.append(line)

    with open(path, "w", encoding="utf-8") as f:
        f.write("# Subtítulos — idioma '%s'. Editable: corrige el texto a la derecha de `=`.\n" % lang)
        f.write("# Clave = <secuencia>.<id>. `\\n` = salto de párrafo. La línea `# EN:` es el original\n")
        f.write("# inglés (contexto); los tiempos viven en assets/subtitles/<secuencia>.timing.txt.\n")
        for line in keep:
            f.write(line + "\n")
        if keep:
            f.write("\n")
        f.write(f"# --- {name} ---\n")
        for i, (_, _, _, text) in enumerate(blocks):
            key = f"{name}.{i}"
            val = text if lang == "en" else existing.get(key, text)
            if lang != "en":
                f.write(f"# EN: {text}\n")
            f.write(f"{key}={val}\n")


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", help="guion de subtítulos (formato de referencia)")
    args = ap.parse_args()

    name, blocks = parse_source(args.source)
    if not blocks:
        print(f"ERROR: sin bloques [IN ...] [OUT ...] en {args.source}", file=sys.stderr)
        return 1
    timing = os.path.join(ROOT, "assets", "subtitles", f"{name}.timing.txt")
    write_timing(timing, name, blocks)
    print(f"{name}: {len(blocks)} bloques -> {timing}")
    for lang in LANGS:
        path = os.path.join(ROOT, "assets", "lang", f"subtitles_{lang}.txt")
        write_lang(path, name, blocks, lang)
        print(f"  + {path}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
