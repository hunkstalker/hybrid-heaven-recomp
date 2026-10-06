#!/usr/bin/env python3
"""Extractor de DIÁLOGOS in-game de Hybrid Heaven (texto EUC-JP de ancho completo).

A diferencia del texto de menús/ayuda (ASCII plano, ver `extract_strings.py`), los
DIÁLOGOS (NPC/historia) usan el mismo motor de texto que la versión japonesa:
códigos EUC-JP, con el inglés guardado como **ASCII de ancho completo** (`A3xx`,
p. ej. `Ａ` = `A`) y los acentos de la PAL como **gaiji** en el rango `B0xx` (que
EUC-JP decodifica como kanji, pero la fuente PAL remapea a letras latinas).

Formato observado (módulos de diálogo: 27, 26, 20, 14, 17, 29, 18, 21, 12, ...):
  - Una "línea" es una tira de pares EUC que decodifica a texto latino.
  - Tras la línea viene un opcode de 2 bytes `f3 00` / `f0 00` (salto de línea)
    o `fa 00` / `fe 00` (fin de mensaje).
  - Un MENSAJE = 1..N líneas; termina cuando entre el final de una línea y el
    principio de la siguiente aparece un `fa 00` / `fe 00`.

Uso:
    python3 tools/text/extract_dialogues.py --rom work/roms/us_retail.z64 --module 27
    python3 tools/text/extract_dialogues.py --rom .../hh.us.z64 --all --tsv work/dlg_us.tsv
    python3 tools/text/extract_dialogues.py --rom .../hh.us.z64 --all --unique work/dlg_unique.txt
    python3 tools/text/extract_dialogues.py --rom-us .../us.z64 --rom-eu .../eu.z64 --pair --tsv work/dlg_pair.tsv

Salidas a `work/` (gitignored). Ver notes/2026-10-06-dialogos-extraccion-euc.md.
"""
import argparse
import difflib
import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "lzkn64"))
import lzkn64  # noqa: E402

SIGNATURE = b"Nisitenma-Ichigo"

# Gaiji PAL (EUC `B0xx` -> letra latina). PROVISIONAL: extraído del texto DE/FR de la
# ROM EU por contexto (ver notes/2026-09-23-texto-euc-jp-y-glifos-pal.md) y verificado
# con muestras reales. Los no listados se dejan como `<B0xx>` para revisión.
GAIJI = {
    0xB0B2: "ä", 0xB0B3: "â", 0xB0B4: "à", 0xB0B6: "á", 0xB0B7: "ê",
    0xB0B8: "è", 0xB0B9: "é", 0xB0BA: "ü", 0xB0BE: "ñ", 0xB0BF: "ö",
    0xB0C0: "ö", 0xB0C1: "ç", 0xB0C2: "ç", 0xB0CA: "ß",
}

PUNCT = {
    0x3000: " ", 0x3001: ",", 0x3002: ".", 0x2026: "...", 0x00B4: "'",
    0x2018: "'", 0x2019: "'", 0x201C: '"', 0x201D: '"', 0x2212: "-",
}


def load_rom(path):
    with open(path, "rb") as f:
        return f.read()


def nisitenma_table(rom):
    sig = rom.find(SIGNATURE)
    if sig < 0:
        raise SystemExit("no se encontró la firma 'Nisitenma-Ichigo' (¿ROM válida?)")
    return sig + 0x10


def nisitenma_entries(rom):
    table = nisitenma_table(rom)
    entries = []
    i = 0
    while True:
        off = table + 4 * i
        if off + 4 > len(rom):
            break
        v = struct.unpack_from(">I", rom, off)[0]
        if v == 0:
            break
        entries.append((v & 0x7FFFFFFF, bool(v >> 31)))
        i += 1
    return entries


def module_bytes(rom, entries, index):
    if not (0 <= index < len(entries)):
        raise SystemExit(f"índice de módulo fuera de rango: {index}")
    start, comp = entries[index]
    end = entries[index + 1][0] if index + 1 < len(entries) else len(rom)
    data = rom[start:end]
    if comp:
        data = lzkn64.decompress(data)
    return data, start


KEEP_UNKNOWN_GAIJI = False


def decode_pair(hi, lo):
    """Par EUC -> carácter latino, o None si no es texto representable."""
    if hi == 0xB0:
        code = (hi << 8) | lo
        if code in GAIJI:
            return GAIJI[code]
        return f"<{hi:02X}{lo:02X}>" if KEEP_UNKNOWN_GAIJI else None
    try:
        c = bytes([hi, lo]).decode("euc_jp")
    except UnicodeDecodeError:
        return None
    o = ord(c)
    if 0xFF01 <= o <= 0xFF5E:   # ASCII de ancho completo
        return chr(o - 0xFEE0)
    if o in PUNCT:
        return PUNCT[o]
    return None                 # kanji/kana (no diál. occidental)


def decode_run(buf):
    """Decodifica una tira de pares EUC; None si algún par no es texto latino."""
    out = []
    for i in range(0, len(buf) - 1, 2):
        t = decode_pair(buf[i], buf[i + 1])
        if t is None:
            return None
        out.append(t)
    return "".join(out)


def text_runs(data, lo=0, hi=None, min_chars=2):
    """Tiras maximales de pares EUC que decodifican a texto latino."""
    hi = len(data) if hi is None else hi
    i = lo
    out = []
    while i + 1 < hi:
        if 0xA1 <= data[i] <= 0xFE and 0xA1 <= data[i + 1] <= 0xFE:
            s = i
            while i + 1 < hi and 0xA1 <= data[i] <= 0xFE and 0xA1 <= data[i + 1] <= 0xFE:
                i += 2
            t = decode_run(data[s:i])
            if t and len(t) >= min_chars and any(ch.isalpha() for ch in t):
                out.append((s, i, t))
        else:
            i += 1
    return out


def _has_msg_end(data, a, b):
    """¿Hay un opcode `fa 00` / `fe 00` en [a,b)? -> fin de mensaje."""
    j = a
    while j + 1 < b:
        if data[j] in (0xFA, 0xFE) and data[j + 1] == 0:
            return True
        j += 1
    return False


def messages(data, lo=0, hi=None, min_chars=2):
    """Agrupa tiras de texto en mensajes. Devuelve [(offset, [lineas]), ...]."""
    hi = len(data) if hi is None else hi
    runs = text_runs(data, lo, hi, min_chars)
    out = []
    cur = []
    start = 0
    for k, (s, e, t) in enumerate(runs):
        if not cur:
            start = s
        cur.append(t)
        nxt = runs[k + 1][0] if k + 1 < len(runs) else hi
        if _has_msg_end(data, e, nxt):
            out.append((start, cur))
            cur = []
    if cur:
        out.append((start, cur))
    return out


# --- Detección de idioma (para emparejar EN/DE/FR de la EU) ---
STOP = {
    "en": {"the", "and", "you", "to", "is", "of", "it", "that", "in", "me", "my",
           "not", "we", "are", "this", "what", "have", "will", "can", "for", "with",
           "i", "be", "he", "she", "they", "do", "but", "on", "your", "us", "at",
           "as", "from", "by", "or", "am", "was", "were"},
    "de": {"der", "die", "das", "und", "ich", "nicht", "sie", "ist", "wir", "du",
           "was", "aber", "auch", "noch", "nur", "mich", "ein", "eine", "mit", "den",
           "dem", "des", "zu", "im", "so", "wie", "werden", "wird", "sind", "haben",
           "kann", "muss", "jetzt", "hier", "dir", "dich", "auf", "von", "ihr", "sich",
           "uns", "euch", "bin", "bist", "sein", "dein", "unser", "unsere", "dies",
           "dieser", "diese", "dieses", "diesem", "einen", "einem", "einer", "daß",
           "dass", "sie", "wir", "ihnen", "ihre", "sehr", "schon", "doch", "man"},
    "fr": {"le", "la", "les", "et", "je", "vous", "est", "des", "un", "une", "pas",
           "que", "qui", "dans", "pour", "avec", "mais", "plus", "sur", "ne", "ce",
           "cette", "il", "elle", "on", "nous", "moi", "toi", "bien", "tout", "comme",
           "au", "aux", "du", "votre", "mon", "sont", "se", "sa", "son", "leur", "y",
           "suis", "veux", "peux", "fait", "très", "être", "d", "qu", "jusqu", "encore",
           "vous", "ils", "elles", "nous", "moi", "lui", "notre", "vos", "mes", "tes"},
}


def detect_lang(text):
    # Senales fuertes por caracteres (los gaiji ya salen como letra latina).
    if any(c in text for c in "äöüßÄÖÜ"):
        return "de"
    if any(c in text for c in "éèêàçùôîûœÉÈÊÀÇ"):
        return "fr"
    words = set(w.strip(".,!?;:'\"()¿¡-").lower() for w in text.split())
    best, best_n = None, 0
    for lang, keys in STOP.items():
        n = len(words & keys)
        if n > best_n:
            best, best_n = lang, n
    return best if best_n >= 1 else None


def join_msg(lines):
    return " ".join(lines)


def extract_module(rom, entries, index, min_chars=2):
    data, base = module_bytes(rom, entries, index)
    msgs = messages(data, min_chars=min_chars)
    return data, base, msgs


def cmd_extract(args):
    rom = load_rom(args.rom)
    entries = nisitenma_entries(rom)
    targets = list(range(len(entries))) if args.all else [args.module]
    rows = []
    uniq = set()
    nmsg = 0
    for idx in targets:
        try:
            data, base, msgs = extract_module(rom, entries, idx, args.min)
        except SystemExit:
            continue
        for m_i, (off, lines) in enumerate(msgs):
            nmsg += 1
            for ln in lines:
                rows.append((idx, off, m_i, ln))
                uniq.add(ln)
    if args.tsv:
        with open(args.tsv, "w", encoding="utf-8") as f:
            f.write("module\toffset\tmessage\tline\n")
            for idx, off, m_i, ln in rows:
                f.write(f"{idx}\t0x{off:06X}\t{m_i}\t{ln}\n")
        print(f"escrito {args.tsv} ({len(rows)} líneas)")
    if args.unique:
        with open(args.unique, "w", encoding="utf-8") as f:
            for ln in sorted(uniq):
                f.write(ln + "\n")
        print(f"escrito {args.unique} ({len(uniq)} únicas)")
    if not args.tsv:
        for idx, off, m_i, ln in rows:
            print(f"{idx:3d} {off:06X} [{m_i}] {ln}")
    print(f"# módulos={len(targets)} mensajes={nmsg} líneas={len(rows)} únicas={len(uniq)}",
          file=sys.stderr)


def _norm(s):
    return "".join(ch.lower() for ch in s if ch.isalnum())


def _eu_events(rom, entries, idx, min_chars):
    """EU: por evento, bloques EN/DE/FR indexados; devuelve [(en, de, fr), ...]."""
    try:
        data, _ = module_bytes(rom, entries, idx)
    except SystemExit:
        return []
    msgs = messages(data, min_chars=min_chars)
    if not msgs:
        return []
    runs = []   # (lang, [textos])
    for _, lines in msgs:
        lang = detect_lang(join_msg(lines))
        if lang is None:
            lang = runs[-1][0] if runs else "en"   # dentro de un bloque, mismo idioma
        if runs and runs[-1][0] == lang:
            runs[-1][1].append(join_msg(lines))
        else:
            runs.append((lang, [join_msg(lines)]))
    events = []
    ev = {"en": [], "de": [], "fr": []}

    def flush():
        n = max(len(ev["en"]), len(ev["de"]), len(ev["fr"]))
        for k in range(n):
            en = ev["en"][k] if k < len(ev["en"]) else ""
            de = ev["de"][k] if k < len(ev["de"]) else ""
            fr = ev["fr"][k] if k < len(ev["fr"]) else ""
            if en:
                events.append((en, de, fr))
        ev["en"].clear()
        ev["de"].clear()
        ev["fr"].clear()

    for lang, texts in runs:
        if lang == "en" and ev["en"]:
            flush()   # nuevo evento (empieza otro bloque EN)
        ev[lang].extend(texts)
    flush()
    return events


def cmd_pair(args):
    us = load_rom(args.rom_us)
    eu = load_rom(args.rom_eu)
    us_e, eu_e = nisitenma_entries(us), nisitenma_entries(eu)
    # Los índices US y EU NO coinciden: el emparejado es GLOBAL por el texto EN. Se construye un mapa
    # normalizado EN->(DE,FR) con TODA la EU y se busca cada mensaje US.
    eu_map = {}
    for idx in range(len(eu_e)):
        for en, de, fr in _eu_events(eu, eu_e, idx, args.min):
            eu_map.setdefault(_norm(en), (de, fr))
    keys = list(eu_map.keys())
    rows = []
    misses = 0
    for idx in range(len(us_e)):
        try:
            _, _, us_msgs = extract_module(us, us_e, idx, args.min)
        except SystemExit:
            continue
        for _, lines in us_msgs:
            en = join_msg(lines)
            hit = eu_map.get(_norm(en))
            if hit is None:
                cand = difflib.get_close_matches(_norm(en), keys, n=1, cutoff=0.8)
                hit = eu_map[cand[0]] if cand else None
            if hit is None:
                misses += 1
                de, fr = "", ""
            else:
                de, fr = hit
            rows.append((idx, en, de, fr))
    print(f"# sin par DE/FR: {misses}/{len(rows)}", file=sys.stderr)
    if args.tsv:
        with open(args.tsv, "w", encoding="utf-8") as f:
            f.write("module\ten\tde\tfr\n")
            for idx, en, de, fr in rows:
                f.write(f"{idx}\t{en}\t{de}\t{fr}\n")
        print(f"escrito {args.tsv} ({len(rows)} pares)")
    else:
        for idx, en, de, fr in rows:
            print(f"{idx:3d} EN={en}")
            print(f"      DE={de}")
            print(f"      FR={fr}")
    print(f"# pares={len(rows)}", file=sys.stderr)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rom", help="ROM para extraer (US/EU/JP)")
    ap.add_argument("--rom-us", help="ROM USA (modo --pair)")
    ap.add_argument("--rom-eu", help="ROM europea (modo --pair)")
    ap.add_argument("--module", type=int, help="índice Nisitenma del módulo")
    ap.add_argument("--all", action="store_true", help="todos los módulos")
    ap.add_argument("--pair", action="store_true", help="emparejar US<->EU (EN/DE/FR)")
    ap.add_argument("--min", type=int, default=2, help="longitud mínima de línea (def. 2)")
    ap.add_argument("--tsv", help="escribir TSV")
    ap.add_argument("--unique", help="escribir lista de líneas únicas")
    ap.add_argument("--unknown-gaiji", action="store_true",
                    help="mostrar gaiji desconocidos como <B0xx> (por defecto se descartan)")
    args = ap.parse_args()

    global KEEP_UNKNOWN_GAIJI
    KEEP_UNKNOWN_GAIJI = args.unknown_gaiji

    if args.pair:
        if not args.rom_us or not args.rom_eu:
            ap.error("--pair requiere --rom-us y --rom-eu")
        cmd_pair(args)
        return
    if not args.rom:
        ap.error("indica --rom (o --pair con --rom-us/--rom-eu)")
    if args.module is None and not args.all:
        ap.error("indica --module N o --all")
    cmd_extract(args)


if __name__ == "__main__":
    main()
