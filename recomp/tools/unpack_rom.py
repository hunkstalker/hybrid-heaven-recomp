#!/usr/bin/env python3
# Adaptado del tooling del port de referencia (MIT); ver CREDITS.md y licenses/hybrid-heaven-recomp-MIT.txt.
"""unpack_rom.py — construye la imagen expandida que leen splat y N64Recomp (vía ELF, ADR 0011).

El 94% del código de Hybrid Heaven está comprimido (LZKN64, tabla Nisitenma-Ichigo). splat necesita
los bytes y `load_overlays(rom, ram, size)` necesita una dirección ROM por sección. La imagen da a
cada code file un offset sintético **estable** por encima de los 16 MB; así la dirección ROM de una
sección identifica su file id.

Layout de `work/scratch/expanded/hh.expanded.z64` (derivado de la ROM: gitignored, no se versiona):

    0x0000000 - 0x004E7D0   primeros 0x4E7D0 bytes de la ROM (header, IPL3, imagen residente)
    0x004E7D0 - 0x1000000   ceros
    0x1000000 - ...         code files en orden de id, cada uno alineado a 16

Salidas (derivadas; en `work/scratch/expanded/`):
  hh.expanded.z64   imagen
  segments.json     resident + files {id, rom, vram, vram_end, size, text_size, bss_size}
  file_table.h      tabla id->{rom, vram, size} para el port

Uso:  python3 tools/unpack_rom.py [ROM]
"""
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import analyze_code_files as acf  # noqa: E402

OUT_DIR = ROOT / "work/scratch/expanded"
IMAGE = OUT_DIR / "hh.expanded.z64"
SEGMENTS = OUT_DIR / "segments.json"
FILE_TABLE_H = OUT_DIR / "file_table.h"

# Hechos medidos de la imagen residente (docs/workflows.md; verificar con la ROM del usuario).
RESIDENT_ROM = 0x1000
RESIDENT_VRAM = 0x80000400
RESIDENT_END_ROM = 0x4E7D0            # el stub de entrada limpia bss desde 0x8004DBD0
RESIDENT_CPU_TEXT_END_ROM = 0x35CC0   # rspboot arranca en 0x800350C0; microcódigo+datos después
RESIDENT_BSS_SIZE = 0x80DC0
EXPANDED_BASE = 0x1000000
ALIGN = 0x10


def text_end(data: bytes) -> int:
    """Offset justo tras el último `jr $ra` y su delay slot (alineado a 16)."""
    n = len(data) & ~3
    words = struct.unpack_from(">%dI" % (n // 4), data, 0) if n else ()
    last = max((i for i, w in enumerate(words) if w == 0x03E00008), default=-1)
    if last < 0:
        return 0
    if any((w & 0xFFFF8000) == 0x27BD8000 for w in words[last + 2:]):
        sys.exit("prólogo de función tras el último jr $ra: la regla de frontera no se cumple")
    end = (last + 2) * 4
    aligned = (end + 15) & ~15
    if any(data[end:aligned]):
        sys.exit("bytes no-cero entre fin de texto 0x%X y 0x%X" % (end, aligned))
    return aligned


def main() -> int:
    rom_path = Path(sys.argv[1]) if len(sys.argv) > 1 else acf.DEFAULT_ROM
    if not rom_path.exists():
        sys.exit("falta la ROM: %s" % rom_path)
    rom = rom_path.read_bytes()
    if len(rom) != 0x1000000:
        sys.exit("ROM inesperada: %d bytes (se espera 0x1000000)" % len(rom))

    files = acf.read_files(rom)
    code = [f for f in files if f["code"] and f["data"]]

    image = bytearray(EXPANDED_BASE)
    image[:RESIDENT_END_ROM] = rom[:RESIDENT_END_ROM]

    segments = {
        "resident": {
            "rom": RESIDENT_ROM, "vram": RESIDENT_VRAM,
            "size": RESIDENT_END_ROM - RESIDENT_ROM,
            "text_size": RESIDENT_CPU_TEXT_END_ROM - RESIDENT_ROM,
            "bss_size": RESIDENT_BSS_SIZE,
        },
        "files": [],
    }
    for f in code:
        data = f["data"]
        size = (len(data) + 3) & ~3
        span = f["vram_end"] - f["vram"]
        if size > span:
            sys.exit("id %d: %d bytes no caben en su span de vram 0x%X" % (f["id"], size, span))
        offset = len(image)
        image += data + bytes(size - len(data))
        image += bytes((-len(image)) % ALIGN)
        segments["files"].append({
            "id": f["id"], "rom": offset, "vram": f["vram"], "vram_end": f["vram_end"],
            "size": size, "text_size": text_end(data), "bss_size": span - size,
        })

    OUT_DIR.mkdir(parents=True, exist_ok=True)
    IMAGE.write_bytes(bytes(image))
    SEGMENTS.write_text(json.dumps(segments, indent=1) + "\n")

    lines = [
        "// Generado por tools/unpack_rom.py -- no editar.",
        "// Offset sintético de cada code file en la imagen expandida (work/scratch/expanded).",
        "#pragma once",
        "",
        "#include <cstdint>",
        "",
        "namespace hh {",
        "",
        "struct CodeFile {",
        "    uint16_t id;",
        "    uint32_t rom;    // offset sintético en hh.expanded.z64",
        "    uint32_t vram;",
        "    uint32_t size;   // bytes cargados (sin bss)",
        "};",
        "",
        "inline constexpr CodeFile kCodeFiles[] = {",
    ]
    for s in segments["files"]:
        lines.append("    { %3d, 0x%08X, 0x%08X, 0x%06X }," % (s["id"], s["rom"], s["vram"], s["size"]))
    lines += ["};", "", "}  // namespace hh", ""]
    FILE_TABLE_H.write_text("\n".join(lines) + "\n")

    total = sum(s["size"] for s in segments["files"])
    print("resident   ROM 0x%X-0x%X  CPU text 0x%X bytes" % (
        RESIDENT_ROM, RESIDENT_END_ROM, segments["resident"]["text_size"]))
    print("code files %d, 0x%X bytes, imagen %d bytes" % (len(segments["files"]), total, len(image)))
    print("wrote %s, %s, %s" % (IMAGE.relative_to(ROOT), SEGMENTS.relative_to(ROOT),
                                FILE_TABLE_H.relative_to(ROOT)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
