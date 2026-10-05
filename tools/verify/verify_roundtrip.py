#!/usr/bin/env python3
"""Verificador de ida-y-vuelta de la ROM (local, en work/verify; no se versiona).

Comprueba los pasos de verificacion que el pipeline NO daba:

  Fase 1  Gate de segmentacion: ELF -> objcopy -> binario == imagen expandida, byte a byte.
          (Lo hace `recomp/tools/build_elf.sh`; aqui solo se re-comprueba el artefacto ya emitido.)
  Fase 2  Descompresion + tabla: cada code file decompilado por NOSOTROS (lzkn64 + tabla)
          coincide con los CRC32/sizes del manifiesto de referencia (notes/us_manifest.yaml).
  Fase 3  Expansion: los bytes de cada code file en hh.expanded.z64 coinciden con el CRC del
          manifiesto; es decir, el unpacker no altera lo que decompilamos.

NO cubre la recompresion a la ROM retail: `tools/lzkn64/lzkn64.py` solo implementa `decompress`
(`compress` es un stub), asi que el `make COMPRESSED=yes` equivalente queda pendiente de implementar
un compresor LZKN64. Se reporta explicitamente.

Uso:  python3 work/verify/verify_roundtrip.py
"""
import json
import struct
import sys
import zlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "recomp/tools"))
import analyze_code_files as acf  # noqa: E402

ROM = ROOT / "work/roms/us_retail.z64"
IMAGE = ROOT / "work/scratch/expanded/hh.expanded.z64"
SEGMENTS = ROOT / "work/scratch/expanded/segments.json"
REBUILT = ROOT / "build/recomp/build-elf/rebuilt.bin"
MANIFEST = ROOT / "notes/us_manifest.yaml"
CODE_JSON = ROOT / "recomp/code_files.json"

fails = []


def hx(v):
    return int(v, 16) if isinstance(v, str) and v.lower().startswith("0x") else int(v)


def crc(data):
    return zlib.crc32(data) & 0xFFFFFFFF


def phase1_gate():
    img = IMAGE.read_bytes()
    rb = REBUILT.read_bytes()
    if len(img) != len(rb):
        fails.append("Fase1: rebuilt %d != imagen %d" % (len(rb), len(img)))
        return "FALLO (tamano distinto: rebuilt %d, imagen %d)" % (len(rb), len(img))
    n = len(img)
    diff = next((i for i in range(n) if img[i] != rb[i]), None)
    if diff is not None:
        fails.append("Fase1: primer byte distinto en 0x%X" % diff)
        return "FALLO (primer byte distinto en 0x%X)" % diff
    return "OK (%d bytes, ELF reconstruye la imagen expandida)" % n


def load_manifest():
    try:
        import yaml
    except ImportError:
        sys.exit("falta PyYAML para leer %s" % MANIFEST)
    m = yaml.safe_load(MANIFEST.read_text())
    entries = m["files"]
    by_index = {int(e["index"]): e for e in entries}
    return by_index


def phase2_run(rom, code_files, by_index):
    ok = mism = 0
    details = []
    for cf in code_files:
        idx = int(cf["idx"])
        me = by_index.get(idx - 1)
        if me is None:
            mism += 1
            details.append("id %d: sin entrada" % idx)
            continue
        want_size = int(me["decompressed_size"])
        want_crc = int(me["decompressed_crc32"], 16)
        want_off = hx(me["original_offset"])
        # Re-derivamos desde la ROM con NUESTRO decodificador + tabla.
        start = hx(cf["src_rom"])
        end = start + int(cf["src_size"])
        raw = rom[start:end]
        if bool(cf["compressed"]):
            got = acf.decompress(raw)
        else:
            got = raw
        gc, gs = crc(got), len(got)
        if want_off != start:
            mism += 1
            details.append("id %d: offset nuestro 0x%X != manifiesto 0x%X" % (idx, start, want_off))
        elif gs != want_size or gc != want_crc:
            mism += 1
            details.append("id %d: size %d/%d crc %08X/%08X" % (idx, gs, want_size, gc, want_crc))
        else:
            ok += 1
    return ok, mism, details


def phase3_expansion(image, segments, by_index):
    by_id = {int(s["id"]): s for s in segments["files"]}
    ok = mism = 0
    details = []
    for idx, s in sorted(by_id.items()):
        me = by_index.get(idx - 1)
        if me is None:
            mism += 1
            details.append("id %d: sin entrada" % idx)
            continue
        want_size = int(me["decompressed_size"])
        want_crc = int(me["decompressed_crc32"], 16)
        off = int(s["rom"])
        got = image[off:off + want_size]
        if len(got) != want_size or crc(got) != want_crc:
            mism += 1
            details.append("id %d @0x%X: size %d/%d crc %08X/%08X"
                           % (idx, off, len(got), want_size, crc(got), want_crc))
        else:
            ok += 1
    return ok, mism, details


def has_compressor():
    src = (ROOT / "tools/lzkn64/lzkn64.py").read_text()
    return "NotImplementedError" not in src


def main():
    rom = ROM.read_bytes()
    by_index = load_manifest()
    code_files = json.loads(CODE_JSON.read_text())["code_files"]
    segments = json.loads(SEGMENTS.read_text())
    image = IMAGE.read_bytes()

    print("== Fase 1: gate de segmentacion (ELF <-> imagen expandida) ==")
    print("  " + phase1_gate())

    print("== Fase 2: descompresion + tabla vs manifiesto de referencia ==")
    ok2, bad2, det2 = phase2_run(rom, code_files, by_index)
    print("  OK %d / %d code files" % (ok2, ok2 + bad2))
    for d in det2[:10]:
        print("   " + d)
    if bad2:
        fails.append("Fase2: %d discrepancias" % bad2)

    print("== Fase 3: expansion (hh.expanded.z64) vs manifiesto ==")
    ok3, bad3, det3 = phase3_expansion(image, segments, by_index)
    print("  OK %d / %d code files" % (ok3, ok3 + bad3))
    for d in det3[:10]:
        print("   " + d)
    if bad3:
        fails.append("Fase3: %d discrepancias" % bad3)

    print("== Fase 4: recompresion a la ROM retail ==")
    if has_compressor():
        print("  (compresor presente; paso no ejecutado por este verificador)")
    else:
        print("  BLOQUEADO: tools/lzkn64/lzkn64.py no implementa `compress` (stub).")
        print("  => no podemos reproducir su `make COMPRESSED=yes` todavia.")

    print()
    if fails:
        print("RESULTADO: FALLO")
        for f in fails:
            print("  - " + f)
        return 1
    print("RESULTADO: OK (fases 1-3)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
