#!/usr/bin/env python3
"""Genera las entradas de DIÁLOGO a nivel de MENSAJE para `assets/lang/<lang>.txt`.

Contexto (mantenedor, 2026-10-07): el overlay del diálogo elimina el límite de caracteres, así que
las frases corregidas que antes no cabían pueden entrar completas. La unidad correcta es el
**mensaje** (lo que compone el juego hasta `FA00/FE00`), no la línea: una misma línea inglesa puede
aparecer en mensajes distintos con traducciones distintas (p.ej. "control system of this shelter,").

Diseño:
  - Se extrae de la ROM la lista ordenada de mensajes por módulo (mismo algoritmo que
    `extract_dialogues.py`). Se verificó que los bloques `[mNN]` de `assets/dialogos.txt` alinean
    1:1 y en orden con esos mensajes (216/216 en mod 12,13,14,16,17).
  - Para cada mensaje se toma el valor: si hay corrección LARGA (`ES (tú)`/`CA (tú)`, que antes no
    cabía) se usa esa; si no, se usa la **traducción por línea ya presente en la tabla de runtime**
    (`<lang>.txt`), que es la fuente correcta (p. ej. `[m9]` = "cambiadores es secreta", no el
    "changers are top secret" mezclado de `dialogos.txt`). Así no se empeora ningún mensaje.
  - Los saltos de línea van "baked" en el valor: si la corrección larga trae ` / `, se respetan;
    si no, se infieren tantos saltos como líneas tiene el mensaje original, repartiéndolo
    proporcionalmente al ancho de cada línea original.
  - Clave = texto inglés del mensaje (líneas unidas con un espacio; normalizado).
  - El runtime las lee por mensaje (ver `hh::text::dialogue_message_choice`).

Uso:
    python3 tools/text/build_dialogue_messages.py --lang es --dry-run
    python3 tools/text/build_dialogue_messages.py --lang es
"""
import argparse
import importlib.util
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))

# módulos con correcciones del mantenedor en assets/dialogos.txt (verificados 1:1 con la ROM)
COVERED = (12, 13, 14, 16, 17, 18)


def load_extractor():
    path = os.path.join(HERE, "extract_dialogues.py")
    spec = importlib.util.spec_from_file_location("ed", path)
    ed = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(ed)
    return ed


def parse_dialogos(path):
    """{modulo: [ {id, en:[...], es:str, es_tu:str, es_apl:str, ca, ca_tu, ca_apl}, ... ]}"""
    mods = {}
    cur = None
    curmod = None

    def flush():
        nonlocal cur
        if cur is not None:
            mods.setdefault(curmod, []).append(cur)
            cur = None

    with open(path, encoding="utf-8") as f:
        for raw in f:
            ln = raw.rstrip()
            m = re.match(r"^#\s*M[ÓO]DULO\s+(\d+)", ln)
            if m:
                flush()
                curmod = int(m.group(1))
                continue
            if re.match(r"^\[m\d+\]", ln):
                flush()
                cur = {"id": ln}
                continue
            if cur is None:
                continue
            for tag, key in (
                ("EN:", "en"),
                ("ES (tú):", "es_tu"),
                ("ES aplicado:", "es_apl"),
                ("ES:", "es"),
                ("CA (tú):", "ca_tu"),
                ("CA aplicado:", "ca_apl"),
                ("CA:", "ca"),
            ):
                if ln.startswith(tag):
                    cur[key] = ln[len(tag):].strip()
                    break
    flush()
    return mods


MAX_CHARS = 32   # ancho aproximado de la caja del diálogo (entra en 256 px internos a ~8 px/glifo)


def infer_breaks(text, ref_lines, max_chars=MAX_CHARS):
    """Reparte `text` en líneas usando las originales como referencia (proporcional) y capando el
    ancho a `max_chars` (si la frase es más larga, salen más líneas)."""
    words = text.split()
    if not words:
        return [text]
    total = sum(len(r) for r in ref_lines) or 1
    targets = [min(max_chars, max(1, round(len(r) * len(text) / total))) for r in ref_lines]
    out = []
    k = 0
    for t in targets:
        if k >= len(words):
            break
        cap = min(t, max_chars)
        cur = words[k]
        k += 1
        while k < len(words) and len(cur) + 1 + len(words[k]) <= cap:
            cur += " " + words[k]
            k += 1
        out.append(cur)
    while k < len(words):
        cur = words[k]
        k += 1
        while k < len(words) and len(cur) + 1 + len(words[k]) <= max_chars:
            cur += " " + words[k]
            k += 1
        out.append(cur)
    return out or [text]


def correction(block, lang):
    """Devuelve (texto, tipo) o (None, None). Prioriza la versión larga (tú)."""
    long_key = f"{lang}_tu"
    apl_key = f"{lang}_apl"
    if long_key in block and not block[long_key].startswith("("):
        return block[long_key], "tu"
    if lang in block:
        return block[lang], "fit"
    if apl_key in block:
        return block[apl_key], "apl"
    return None, None


def load_perline(path):
    """Traducciones por-línea ya presentes en la tabla (se salta la sección de MENSAJES)."""
    out = {}
    try:
        with open(path, encoding="utf-8") as f:
            for ln in f:
                ln = ln.rstrip("\n")
                if ln.startswith("# --- MENSAJES de diálogo"):
                    break  # el resto es la sección de mensajes (no per-línea)
                if not ln or ln.startswith("#") or "=" not in ln:
                    continue
                k, v = ln.split("=", 1)
                out[k.strip()] = v.strip()
    except FileNotFoundError:
        pass
    return out


def build_messages(ed, rom, entries, modules, dialogos, lang, perline):
    """Lista de (modulo, indice, clave_EN, valor_con_\\n, tipo).

    Regla de valor: si el mensaje tiene corrección LARGA (`<lang> (tú)`) se usa esa (con los saltos
    inferidos del original); si no, se usa la traducción **por línea** de la tabla de runtime
    (`es.txt`, la fuente correcta: p. ej. `[m9]` -> "cambiadores es secreta"), con los saltos del
    original. Así nunca se empeora con valores mezclados de `dialogos.txt`.
    """
    out = []
    for m in modules:
        data, _ = ed.module_bytes(rom, entries, m)
        rom_msgs = ed.messages(data)
        blocks = dialogos.get(m, [])
        if len(rom_msgs) != len(blocks):
            print(f"  ! mod{m}: ROM={len(rom_msgs)} dialogos={len(blocks)} (se salta)", file=sys.stderr)
            continue
        for i, ((_off, lines), blk) in enumerate(zip(rom_msgs, blocks)):
            en = [x.strip() for x in lines]
            long_txt = blk.get(f"{lang}_tu")
            if long_txt and not long_txt.startswith("("):
                segs = [x.strip() for x in long_txt.split(" / ")] if " / " in long_txt else []
                if len(segs) != len(en) or any(len(s) > MAX_CHARS for s in segs):
                    segs = infer_breaks(long_txt.replace(" / ", " "), en)
                val, kind = "\n".join(segs), "tu"
            else:
                segs = [perline.get(e, e) for e in en]
                val, kind = "\n".join(segs), "perline"
            out.append((m, i, " ".join(en).strip(), val, kind))
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--lang", default="es", choices=["es", "ca"])
    ap.add_argument("--rom", default=os.path.join(REPO, "work", "roms", "us_retail.z64"))
    ap.add_argument("--dialogos", default=os.path.join(REPO, "assets", "dialogos.txt"))
    ap.add_argument("--out", help="fichero a editar (def. assets/lang/<lang>.txt)")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--show", type=int, default=0, help="muestra N mensajes de ejemplo")
    args = ap.parse_args()

    out_path = args.out or os.path.join(REPO, "assets", "lang", f"{args.lang}.txt")
    ed = load_extractor()
    rom = ed.load_rom(args.rom)
    entries = ed.nisitenma_entries(rom)
    dialogos = parse_dialogos(args.dialogos)
    perline = load_perline(out_path)
    msgs = build_messages(ed, rom, entries, COVERED, dialogos, args.lang, perline)

    # Deduplica por clave (mensajes idénticos). Si el valor difiere, avisa (colisión real).
    dedup = {}
    collisions = []
    for m, i, key, val, kind in msgs:
        if key in dedup:
            if dedup[key][3] != val:
                collisions.append((key, dedup[key][:2], (m, i), dedup[key][3], val))
            continue
        dedup[key] = (m, i, key, val, kind)
    msgs = list(dedup.values())

    kinds = {}
    for _m, _i, _k, _v, kind in msgs:
        kinds[kind] = kinds.get(kind, 0) + 1
    print(f"{args.lang}: {len(msgs)} mensajes ({kinds})")
    for key, s1, s2, v1, v2 in collisions:
        print(f"  ! MISMA CLAVE, VALOR DISTINTO: {key!r} {s1} vs {s2}\n      {v1!r}\n      {v2!r}",
              file=sys.stderr)

    if args.show:
        for m, i, key, val, kind in msgs[: args.show]:
            print(f"\n[mod{m} msg{i}] ({kind})")
            print(f"  EN : {key}")
            print(f"  {args.lang.upper()} : {val}")

    if args.dry_run:
        return

    # Escribe/actualiza. Los mensajes de UNA línea coinciden con su entrada por-línea (misma clave):
    # en vez de duplicarla, se ACTUALIZA esa entrada con el valor del mensaje (si difiere); el resto
    # se añade en una sección al final. Los menús y el resto del archivo no se tocan.
    MARK = f"# --- MENSAJES de diálogo ({args.lang}): clave = mensaje inglés completo; saltos con \\n ---"
    with open(out_path, encoding="utf-8") as f:
        raw = f.read().split("\n")
    body = []
    for ln in raw:
        if ln.startswith("# --- MENSAJES de diálogo"):   # descarta la sección previa (idempotente)
            break
        body.append(ln)
    pos = {}
    for i, ln in enumerate(body):
        if not ln or ln.startswith("#") or "=" not in ln:
            continue
        pos.setdefault(ln.split("=", 1)[0].strip(), i)

    new_entries = []
    updated = skipped = 0
    for _m, _i, key, val, _kind in msgs:
        esc = val.replace("\\", "\\\\").replace("\n", "\\n")
        i = pos.get(key)
        if i is not None:
            cur = body[i].split("=", 1)[1]
            if cur == esc:
                skipped += 1
            else:
                body[i] = key + "=" + esc
                updated += 1
        else:
            new_entries.append(f"{key}={esc}")

    text = "\n".join(body).rstrip("\n") + "\n\n" + MARK + "\n" + "\n".join(new_entries) + "\n"
    with open(out_path, "w", encoding="utf-8") as f:
        f.write(text)
    print(f"escrito {out_path}: {len(msgs)} mensajes ({len(new_entries)} nuevos, "
          f"{updated} actualizados, {skipped} ya correctos)")


if __name__ == "__main__":
    main()
