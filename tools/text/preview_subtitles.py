#!/usr/bin/env python3
"""Preview de subtítulos: imprime los bloques y su paginación (3 líneas/pantalla).

Reutiliza el parseo de `build_subtitles.py` y el troceo del runtime (tipografía color4: avance 8,
espacio 4, f i j l r t 6) para que el preview coincida con lo que se ve en el juego.

Uso:
    python3 tools/text/preview_subtitles.py notes/reference/Hybrid-Heaven-Intro-Dialogues.txt
    python3 tools/text/preview_subtitles.py --lang es assets/subtitles/intro_prologue.timing.txt
"""
import argparse
import os
import re
import sys

sys.path.insert(0, os.path.dirname(__file__))
import build_subtitles as bs  # noqa: E402

MAX_LINES = 3
MAX_W = 296.0            # visible_width (320) - 24
NARROW = set("fijlt")    # avance 6 en color4


def advance(ch):
    if ch == " ":
        return 4
    if ch in NARROW:
        return 6
    return 8


def text_width(s):
    return sum(advance(c) for c in s)


def wrap(text, max_w=MAX_W):
    out = []
    for para in text.split("\\n"):
        line = ""
        for word in para.split(" "):
            if word == "":
                continue
            cand = word if not line else line + " " + word
            if line and text_width(cand) > max_w:
                out.append(line)
                line = word
            else:
                line = cand
        if line:
            out.append(line)
    return out


def paginate(lines, per=MAX_LINES):
    """Reparto balanceado por ancho (mismo algoritmo que el runtime)."""
    n = len(lines)
    if n == 0:
        return [[]]
    npages = (n + per - 1) // per
    if npages <= 1:
        return [lines]
    w = [text_width(l) for l in lines]
    target = sum(w) / npages
    INF = float("inf")
    pre = [0] * (n + 1)
    for i in range(n):
        pre[i + 1] = pre[i] + w[i]
    dp = [[INF] * (n + 1) for _ in range(npages + 1)]
    brk = [[-1] * (n + 1) for _ in range(npages + 1)]
    dp[0][0] = 0
    for p in range(1, npages + 1):
        for i in range(p, n + 1):
            for k in range(1, per + 1):
                if k > i:
                    break
                j = i - k
                if dp[p - 1][j] >= INF:
                    continue
                pw = pre[i] - pre[j]
                val = dp[p - 1][j] + (pw - target) ** 2
                if val < dp[p][i]:
                    dp[p][i] = val
                    brk[p][i] = k
    rev = []
    i = n
    for p in range(npages, 0, -1):
        k = brk[p][i]
        if k < 0:
            k = 1
        j = i - k
        rev.append(lines[j:i])
        i = j
    rev.reverse()
    return rev


def fmt_ms(ms):
    m, s = divmod(int(round(ms / 1000.0)), 60)
    return f"{m:02d}:{s:02d}"


def load_lang(path):
    out = {}
    if os.path.exists(path):
        with open(path, encoding="utf-8") as f:
            for line in f:
                line = line.rstrip("\n")
                if not line.strip() or line.lstrip().startswith("#"):
                    continue
                if "=" in line:
                    k, v = line.split("=", 1)
                    out[k.strip()] = v.strip()
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", help="guion (formato de referencia) o timing.txt")
    ap.add_argument("--lang", default="en", help="idioma de los textos (def. en)")
    args = ap.parse_args()

    if args.source.endswith(".timing.txt"):
        name = os.path.basename(args.source)[:-len(".timing.txt")]
        blocks = []
        with open(args.source, encoding="utf-8") as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                parts = line.split()
                in_ms, out_ms = int(parts[1]), int(parts[2])
                ln = int(parts[3]) if len(parts) > 3 else 0
                blocks.append((in_ms, out_ms, ln, None))
    else:
        name, parsed = bs.parse_source(args.source)
        blocks = [(i, o, ln, t) for (i, o, ln, t) in parsed]

    lang = load_lang(os.path.join(bs.ROOT, "assets", "lang", f"subtitles_{args.lang}.txt"))
    print(f"# Secuencia: {name}  ·  idioma: {args.lang}  ·  {len(blocks)} bloques\n")
    for idx, (in_ms, out_ms, ln, src_text) in enumerate(blocks):
        key = f"{name}.{idx}"
        text = lang.get(key, src_text if src_text is not None else f"<falta {key}>")
        text = text.replace("\\p", "\f")   # corte de página manual
        if "\f" in text:
            pages = [(wrap(s) or [""]) for s in text.split("\f")]
        else:
            pages = paginate(wrap(text))
        dur = max(1, out_ms - in_ms)
        tag = "" if ln == 0 else f"  [línea {ln}]"
        print(f"[{idx}] IN {fmt_ms(in_ms)}  OUT {fmt_ms(out_ms)}  ({dur/1000:.1f}s, {len(pages)} pantallas){tag}")
        for p, page in enumerate(pages):
            p_in = in_ms + dur * p // len(pages)
            p_out = in_ms + dur * (p + 1) // len(pages)
            print(f"    pag {p+1}/{len(pages)}  {fmt_ms(p_in)}-{fmt_ms(p_out)}")
            for l in page:
                print(f"        {l}")
        print()
    return 0


if __name__ == "__main__":
    sys.exit(main())
