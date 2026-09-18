#!/usr/bin/env python3
"""Valida `cache/trans.bin` (Fase B, ADR 0007) contra la referencia LZKN64 en Python.

Para cada registro (src, size, len, bytes) del cache:
  - descomprime ROM[src:src+size] con tools/lzkn64/lzkn64.py;
  - compara longitud y bytes contra el cache (el cache guarda el layout "word-swapped" del port,
    asi que el byte guest i es cache[i ^ 3]).

Uso:
  python3 tools/analysis/validate_trans_cache.py --rom baserom.us.z64 \
      --cache port/HybridHeavenRecomp/build_dbg/cache/trans.bin

Salida: una linea por registro y un resumen. Codigo de salida != 0 si hay cualquier discrepancia.
"""
import argparse
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "lzkn64"))
import lzkn64  # noqa: E402

MAGIC = b"HHTRANS1"
HEADER = 8 + 4 + 4 + 8


def parse_cache(data):
    if len(data) < HEADER or data[:8] != MAGIC:
        raise SystemExit("cache: cabecera invalida")
    combined = struct.unpack_from("<Q", data, 8)[0]
    version = combined >> 32
    count = combined & 0xFFFFFFFF
    rom_hash = struct.unpack_from("<Q", data, 16)[0]
    if version != 2:
        raise SystemExit(f"cache: version {version} no soportada (esperada 2)")
    entries = []
    pos = HEADER
    while pos + 16 <= len(data):
        src, size, ln, _pad = struct.unpack_from("<IIII", data, pos)
        payload = data[pos + 16:pos + 16 + ln]
        if len(payload) != ln:
            raise SystemExit(f"cache: registro truncado en 0x{pos:X}")
        entries.append((src, size, ln, payload))
        pos += 16 + ln
    return version, count, rom_hash, entries


def find_rom(explicit):
    if explicit:
        return Path(explicit)
    for cand in (
        "work/roms/us_retail.z64",
        "port/HybridHeavenRecomp/build_dbg/baserom.us.z64",
        "port/HybridHeavenRecomp/build_win/bin/Release/baserom.us.z64",
        "baserom.us.z64",
        "rom/baserom.us.z64",
    ):
        p = Path(cand)
        if p.exists():
            return p
    raise SystemExit("no encuentro la ROM; pasa --rom")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--rom", default=None)
    ap.add_argument("--cache", default="cache/trans.bin")
    args = ap.parse_args()

    rom = find_rom(args.rom).read_bytes()
    cache = Path(args.cache).read_bytes()
    version, count, rom_hash, entries = parse_cache(cache)
    print(f"ROM  {len(rom)} bytes")
    print(f"cache {args.cache}: version={version} count={count} entradas={len(entries)} "
          f"rom_hash={rom_hash:016X}")

    ok = 0
    bad = 0
    total_out = 0
    for i, (src, size, ln, payload) in enumerate(entries):
        blob = rom[src:src + size]
        if len(blob) != size:
            print(f"  [{i}] src={src:08X} size={size:06X} -> FUERA DE ROM")
            bad += 1
            continue
        try:
            ref = lzkn64.decompress(blob)
        except Exception as e:  # noqa: BLE001
            print(f"  [{i}] src={src:08X} size={size:06X} -> LZKN64 ERROR {e}")
            bad += 1
            continue
        # El cache guarda el flujo en ORDEN GUEST (v2): comparacion directa con la referencia.
        if len(ref) != ln or payload != ref:
            print(f"  [{i}] src={src:08X} size={size:06X} -> MISMATCH ref={len(ref)} cache={ln}")
            bad += 1
        else:
            ok += 1
            total_out += ln
    print(f"OK={ok} BAD={bad} salida_total={total_out} bytes")
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
