#!/usr/bin/env python3
"""
gen_module_extras.py — deriva `config/module_extras.json` de una traza `HH_JALTRACE` del emulador.

La traza (uint32 nativo, un target por salto `jal`/`jalr`) contiene los destinos indirectos reales
que el juego ejecuta. Los que caen dentro de un módulo y **no** son entradas estáticas de su syms
son mid-entries que el port necesita recompilar (si no, `get_function` aborta con
`Failed to find function`). setup_module.py los añade como `--extra` y los protege del validador
(`keep_syms.txt`).

Uso:
  # Con dos trazas (fase de boot y fase post-burst) se desambigua module23 vs module24
  # (comparten base de VRAM): los targets vistos en boot van a los módulos de boot y los
  # vistos solo después van a los del burst.
  python3 tools/analysis/gen_module_extras.py work/debug/emu_jal130.bin \
      --boot-trace work/debug/emu_jal60.bin [--out config/module_extras.json]
"""

import argparse
import json
import struct
import sys
from pathlib import Path

try:
    import tomllib
except ImportError:
    sys.exit("Se requiere Python 3.11+ (tomllib).")

ROOT = Path(__file__).resolve().parents[2]
CONFIG = ROOT / "config"
MODULE_INDEXES = (7, 23, 54, 24, 25, 99)
MODULE_PHASE = {7: "boot", 23: "boot", 54: "boot", 24: "late", 25: "late", 99: "late"}


BRANCH_OPS = {0x01, 0x04, 0x05, 0x06, 0x07, 0x11, 0x14, 0x15, 0x16, 0x17}


def is_delay_slot(blob: bytes, base: int, addr: int) -> bool:
    """¿`addr` es el delay-slot de la instrucción anterior (no una entrada válida)?"""
    off = addr - base - 4
    if off < 0 or off + 4 > len(blob):
        return False
    v = struct.unpack_from(">I", blob, off)[0]
    op = v >> 26
    if op in (0x02, 0x03):
        return True
    if op == 0x00 and (v & 0x3F) in (0x08, 0x09):
        return True
    return op in BRANCH_OPS


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("trace", type=Path, help="fichero HH_JALTRACE del emulador (uint32 nativo)")
    ap.add_argument("--boot-trace", type=Path,
                    help="traza temprana (pre-burst): sus targets se atribuyen a los módulos de boot")
    ap.add_argument("--out", type=Path, default=CONFIG / "module_extras.json")
    args = ap.parse_args()

    if not args.trace.exists():
        print(f"[extras] falta la traza: {args.trace}")
        return 1

    ranges = []
    for idx in MODULE_INDEXES:
        syms = CONFIG / f"us_module{idx}.syms.toml"
        blob = ROOT / f"work/scratch/module{idx}_be.bin"
        if not syms.exists() or not blob.exists():
            continue
        sec = tomllib.loads(syms.read_text())["section"][0]
        starts = {f["vram"] for f in sec["functions"]}
        ranges.append((idx, sec["vram"], sec["size"], starts, blob.read_bytes()))

    def read_targets(path: Path):
        out = set()
        with open(path, "rb") as f:
            while True:
                chunk = f.read(1 << 22)
                if not chunk:
                    break
                for (v,) in struct.iter_unpack("<I", chunk):
                    out.add(v)
        return out

    targets = read_targets(args.trace)
    boot_targets = read_targets(args.boot_trace) if args.boot_trace else None
    if boot_targets is not None:
        late_targets = targets - boot_targets
        print(f"[extras] traza: {len(targets)} targets únicos "
              f"(boot {len(boot_targets)}, solo post-burst {len(late_targets)})")
    else:
        late_targets = None
        print(f"[extras] traza: {len(targets)} targets únicos")

    out = {}
    for idx, base, size, starts, blob in ranges:
        pool = targets
        if late_targets is not None:
            pool = boot_targets if MODULE_PHASE.get(idx) == "boot" else late_targets
        cand = {t for t in pool
                if base <= t < base + size and (t - base) % 4 == 0 and t not in starts
                and not is_delay_slot(blob, base, t)}
        if cand:
            out[str(idx)] = sorted(f"0x{t:08X}" for t in cand)
        print(f"[extras] idx {idx:3d} ({MODULE_PHASE.get(idx,'?')}): {len(cand)} mid-entries nuevos "
              f"(de {sum(1 for t in pool if base <= t < base + size)} targets en rango)")

    args.out.write_text(json.dumps(out, indent=2) + "\n")
    print(f"[extras] escrito {args.out.relative_to(ROOT)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
