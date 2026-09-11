#!/usr/bin/env python3
"""
triage_screenshots.py — triaje barato de lotes de screenshots ANTES de usar visión.

Reduce cientos de PNG a un subconjunto representativo (cambios de escena), agrupa
duplicados por hash perceptual (dHash) y emite un CSV + una lista de selección para
leer por visión en lotes pequeños (2-3 por turno). No re-adjuntar imágenes ya resumidas.

Dependencias: zlib (stdlib) + numpy. Usa Pillow si está disponible (más rápido).
No requiere ImageMagick.

Uso:
  python3 tools/analysis/triage_screenshots.py "<carpeta>" [opciones]

Opciones:
  --out PREFIX        Prefijo de salida (def. "triage" en el cwd). Genera
                      <out>.csv, <out>.selection.txt, <out>.batches.txt
  --dup-threshold N   Distancia Hamming para considerar duplicado (def. 6; 0-64)
  --bright-threshold N  Delta de brillo medio para forzar selección (def. 32)
  --batch N           Tamaño de lote en batches.txt (def. 3)
  --max N             Máximo de imágenes seleccionadas (submuestreo uniforme)
  --recursive         Buscar PNG recursivamente
  --list              Solo imprimir la selección, no escribir CSV
"""

import argparse
import csv
import os
import re
import struct
import sys
import zlib
from pathlib import Path

try:
    import numpy as np
except ImportError:
    sys.exit("Se requiere numpy (python3 -c 'import numpy').")

try:
    from PIL import Image  # opcional, vía rápida
    _HAS_PIL = True
except Exception:
    _HAS_PIL = False


# ---------------------------------------------------------------------------
# Decodificación PNG (subconjunto suficiente: sin ImageMagick)
# ---------------------------------------------------------------------------

def _unfilter(raw: bytes, height: int, stride: int, bpp: int) -> "np.ndarray":
    out = np.empty((height, stride), dtype=np.uint8)
    prev = np.zeros(stride, dtype=np.int32)
    i = 0
    for y in range(height):
        f = raw[i]
        i += 1
        line = np.frombuffer(raw, dtype=np.uint8, count=stride, offset=i).astype(np.int32)
        i += stride
        if f == 0:                      # None
            cur = line
        elif f == 1:                    # Sub: prefix-sum por cada stream de bpp
            cur = line.copy()
            n = stride // bpp
            base = cur[:n * bpp].reshape(n, bpp)
            cur[:n * bpp] = ((np.cumsum(base, axis=0) & 0xFF).reshape(-1))
            for x in range(n * bpp, stride):
                cur[x] = (cur[x] + cur[x - bpp]) & 0xFF
        elif f == 2:                    # Up
            cur = (line + prev) & 0xFF
        elif f == 3:                    # Average
            cur = line.copy()
            for x in range(stride):
                a = cur[x - bpp] if x >= bpp else 0
                cur[x] = (cur[x] + ((a + prev[x]) >> 1)) & 0xFF
        elif f == 4:                    # Paeth
            cur = line.copy()
            for x in range(stride):
                a = cur[x - bpp] if x >= bpp else 0
                b = prev[x]
                c = prev[x - bpp] if x >= bpp else 0
                p = a + b - c
                pa, pb, pc = abs(p - a), abs(p - b), abs(p - c)
                pr = a if (pa <= pb and pa <= pc) else (b if pb <= pc else c)
                cur[x] = (cur[x] + pr) & 0xFF
        else:
            raise ValueError(f"filtro PNG {f} no soportado")
        out[y] = cur.astype(np.uint8)
        prev = cur
    return out


def _unpack_bits(row: "np.ndarray", width: int, depth: int) -> "np.ndarray":
    if depth == 8:
        return row[:width].astype(np.uint8)
    per = 8 // depth
    mask = (1 << depth) - 1
    out = np.empty(width, dtype=np.uint8)
    for x in range(width):
        byte = int(row[x // per])
        shift = 8 - depth * (x % per + 1)
        out[x] = (byte >> shift) & mask
    return out


def png_to_gray(path: Path):
    """Devuelve (h, w, gray uint8) o lanza excepcion."""
    if _HAS_PIL:
        img = Image.open(path).convert("L")
        return np.asarray(img, dtype=np.uint8)

    data = path.read_bytes()
    if data[:8] != b"\x89PNG\r\n\x1a\n":
        raise ValueError("no es PNG")
    pos, idat = 8, bytearray()
    w = h = bitdepth = colortype = interlace = None
    palette = None
    while pos + 8 <= len(data):
        (ln,) = struct.unpack(">I", data[pos:pos + 4])
        typ = data[pos + 4:pos + 8]
        chunk = data[pos + 8:pos + 8 + ln]
        pos += 12 + ln
        if typ == b"IHDR":
            w, h, bitdepth, colortype, _, _, interlace = struct.unpack(">IIBBBBB", chunk)
        elif typ == b"PLTE":
            palette = np.frombuffer(chunk, dtype=np.uint8).reshape(-1, 3)
        elif typ == b"IDAT":
            idat += chunk
        elif typ == b"IEND":
            break
    if interlace:
        raise ValueError("PNG entrelazado no soportado")

    channels = {0: 1, 2: 3, 3: 1, 4: 2, 6: 4}[colortype]
    bits_per_pixel = channels * bitdepth
    stride = (w * bits_per_pixel + 7) // 8
    bpp = max(1, bits_per_pixel // 8)
    raw = zlib.decompress(bytes(idat))
    lines = _unfilter(raw, h, stride, bpp)

    if bitdepth == 8:
        arr = lines.reshape(h, w, channels)
    elif bitdepth in (1, 2, 4) and colortype in (0, 3):
        arr = np.stack([_unpack_bits(lines[y], w, bitdepth) for y in range(h)])
        arr = arr.reshape(h, w, 1)
    else:
        raise ValueError(f"bitdepth {bitdepth} no soportado (colortype {colortype})")

    if colortype == 3:
        if palette is None:
            raise ValueError("PNG paleta sin PLTE")
        rgb = palette[arr[:, :, 0].astype(np.int64)]
        gray = (0.299 * rgb[:, :, 0] + 0.587 * rgb[:, :, 1] + 0.114 * rgb[:, :, 2])
        return h, w, gray.astype(np.uint8)
    if colortype in (0, 4):
        return h, w, arr[:, :, 0].astype(np.uint8)
    rgb = arr[:, :, :3].astype(np.float32)
    gray = (0.299 * rgb[:, :, 0] + 0.587 * rgb[:, :, 1] + 0.114 * rgb[:, :, 2])
    return h, w, gray.astype(np.uint8)


# ---------------------------------------------------------------------------
# Hashes / métricas
# ---------------------------------------------------------------------------

def dhash(gray: "np.ndarray", hash_size: int = 8) -> int:
    h, w = gray.shape
    ys = (np.arange(hash_size + 1) * h // (hash_size + 1))
    xs = (np.arange(hash_size) * w // hash_size)
    small = gray[np.ix_(ys, xs)].astype(np.int16)
    diff = small[:, 1:] > small[:, :-1]
    bits = 0
    for b in diff.flatten():
        bits = (bits << 1) | int(b)
    return bits


def hamming(a: int, b: int) -> int:
    return bin(a ^ b).count("1")


_TS_RE = re.compile(r"(\d{4})-(\d{2})-(\d{2})[ T](\d{2})\.(\d{2})\.(\d{2})")


def parse_ts(name: str, fallback: float) -> str:
    m = _TS_RE.search(name)
    if m:
        y, mo, d, hh, mm, ss = m.groups()
        return f"{y}-{mo}-{d} {hh}:{mm}:{ss}"
    import datetime
    return datetime.datetime.fromtimestamp(fallback).strftime("%Y-%m-%d %H:%M:%S")


# ---------------------------------------------------------------------------

def main() -> int:
    ap = argparse.ArgumentParser(description="Triaje de lotes de screenshots")
    ap.add_argument("folder", type=Path)
    ap.add_argument("--out", default="triage")
    ap.add_argument("--dup-threshold", type=int, default=6)
    ap.add_argument("--bright-threshold", type=int, default=32)
    ap.add_argument("--batch", type=int, default=3)
    ap.add_argument("--max", type=int, default=0)
    ap.add_argument("--recursive", action="store_true")
    ap.add_argument("--list", action="store_true")
    args = ap.parse_args()

    pat = "**/*.png" if args.recursive else "*.png"
    files = sorted(args.folder.glob(pat), key=lambda p: parse_ts(p.name, p.stat().st_mtime))

    rows, unreadable = [], []
    last_sel = None  # (idx, hash, bright)

    for idx, p in enumerate(files):
        try:
            h, w, gray = png_to_gray(p)
            hsh = dhash(gray)
            bright = float(gray.mean())
        except Exception as e:
            unreadable.append((p, str(e)))
            continue

        selected = last_sel is None or \
            hamming(hsh, last_sel[1]) > args.dup_threshold or \
            abs(bright - last_sel[2]) > args.bright_threshold

        dup_of = "" if selected else last_sel[0]
        flag = "selected" if selected else "dup"
        if selected:
            last_sel = (idx, hsh, bright)

        txt = p.with_suffix(".txt")
        rows.append({
            "idx": idx, "path": str(p), "ts": parse_ts(p.name, p.stat().st_mtime),
            "w": w, "h": h, "bytes": p.stat().st_size, "bright": round(bright, 1),
            "hash": f"{hsh:016x}", "flag": flag, "dup_of": dup_of,
            "txt": "yes" if txt.exists() else "no",
        })

    selected_idx = [r["idx"] for r in rows if r["flag"] == "selected"]
    if args.max and len(selected_idx) > args.max:
        keep = np.linspace(0, len(selected_idx) - 1, args.max).round().astype(int)
        keep_set = {selected_idx[k] for k in keep}
        for r in rows:
            if r["flag"] == "selected" and r["idx"] not in keep_set:
                r["flag"] = "selected-skipped"

    sel = [r for r in rows if r["flag"] == "selected"]

    print(f"PNG encontradas:      {len(files)}")
    print(f"legibles:             {len(rows)}")
    print(f"seleccionadas:        {len(sel)}  (de {len(selected_idx)} cambios)")
    print(f"duplicados agrupados: {sum(1 for r in rows if r['flag'] == 'dup')}")
    if unreadable:
        print(f"ilegibles:            {len(unreadable)}")
        for p, e in unreadable[:5]:
            print(f"   ! {p.name}: {e}")

    if args.list:
        for r in sel:
            print(r["path"])
        return 0

    out_csv = Path(f"{args.out}.csv")
    out_sel = Path(f"{args.out}.selection.txt")
    out_bat = Path(f"{args.out}.batches.txt")
    with out_csv.open("w", newline="") as f:
        wr = csv.DictWriter(f, fieldnames=["idx", "path", "ts", "w", "h", "bytes",
                                           "bright", "hash", "flag", "dup_of", "txt"])
        wr.writeheader()
        wr.writerows(rows)
    out_sel.write_text("\n".join(r["path"] for r in sel) + "\n")
    lines = []
    for b, i in enumerate(range(0, len(sel), args.batch), 1):
        lines.append(f"# Lote {b}")
        lines.append("\n".join(r["path"] for r in sel[i:i + args.batch]))
    out_bat.write_text("\n".join(lines) + "\n")

    print(f"\nescritos: {out_csv}  {out_sel}  {out_bat}")
    print(f"siguiente paso: leer por visión las de {out_bat} en lotes de {args.batch},")
    print("resumiendo cada imagen a texto en una nota; no re-adjuntar.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
