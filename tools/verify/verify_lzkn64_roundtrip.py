#!/usr/bin/env python3
"""Verifica el codec LZKN64 propio (tools/lzkn64/lzkn64.py) contra la ROM retail.

Para cada fichero comprimido:
  - decompress(retail) -> D (semantico)
  - compress(D) -> rec
  - round-trip: decompress(rec) == D
  - byte-exacto: rec == retail[:len(rec)] (el resto, si lo hay, es padding)

Uso: python3 tools/verify/verify_lzkn64_roundtrip.py
"""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools/lzkn64"))
import lzkn64  # noqa: E402

ROM = ROOT / "work/roms/us_retail.z64"


def main():
    import yaml
    rom = ROM.read_bytes()
    man = yaml.safe_load((ROOT / "notes/us_manifest.yaml").read_text())["files"]
    comp = [e for e in man if e.get("compressed") and int(e["original_size"]) > 0]
    comp.sort(key=lambda e: int(e["original_size"]))
    semantic_ok = exact = 0
    not_exact = []
    for e in comp:
        off = int(e["original_offset"], 16); osz = int(e["original_size"])
        raw = rom[off:off + osz]
        D = lzkn64.decompress(raw)
        rec = lzkn64.compress(D)
        if lzkn64.decompress(rec) == D:
            semantic_ok += 1
        if rec == raw[:len(rec)]:
            exact += 1
        else:
            not_exact.append((e["index"], len(D)))
    print("ficheros comprimidos : %d" % len(comp))
    print("round-trip semantico : %d / %d" % (semantic_ok, len(comp)))
    print("byte-exacto vs retail: %d / %d" % (exact, len(comp)))
    if not_exact:
        print("no byte-exactos (%d): %s" % (len(not_exact), ", ".join("idx%d(dec%d)" % t for t in not_exact)))
    return 0 if semantic_ok == len(comp) else 1


if __name__ == "__main__":
    raise SystemExit(main())
