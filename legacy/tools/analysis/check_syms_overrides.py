#!/usr/bin/env python3
"""Comprueba que los overrides de tamano de module_extras.json ("0xADDR:0xSIZE") siguen
presentes en las .syms (por modulo y en la combinada).

Contexto (incidente 2026-09-16): una version de add_mid_entry.py recalculaba TODOS los
tamanos por "hueco hasta el siguiente", borrando en silencio estos overrides. Al perderse
M9_FUN_802169AC:0x1C0, el simbolo volvia a 0x4604 (se comia datos), el recompilador lo
dejaba en stub do_break y se regresaba el cuelgue del NPC (commit 45b05b5). Este guardia lo
detecta.

Uso:
    python3 tools/analysis/check_syms_overrides.py          # rc=0 si todo cuadra
    python3 tools/analysis/check_syms_overrides.py --config-dir <dir>
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CONFIG = ROOT / "config"
RE_SYM = re.compile(r'vram = 0x([0-9A-Fa-f]+), size = 0x([0-9A-Fa-f]+)')


def tamanos(cfg: Path, fichero: str, module: str | None = None) -> dict[int, int] | None:
    path = cfg / fichero
    if not path.exists():
        return None
    s = path.read_text()
    if module is not None:
        n = s.find(f'name = ".module{module}"')
        if n < 0:
            return None
        i = s.find("functions = [", n)
        j = s.find("\n]", i)
        s = s[i:j]
    return {int(m.group(1), 16): int(m.group(2), 16) for m in RE_SYM.finditer(s)}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--config-dir", default=str(CONFIG))
    args = ap.parse_args()
    cfg = Path(args.config_dir)

    extras_path = cfg / "module_extras.json"
    if not extras_path.exists():
        print(f"check_syms_overrides: no existe {extras_path}")
        return 1
    extras = json.loads(extras_path.read_text())
    comb = tamanos(cfg, "us_combined.syms.toml")

    fallos = 0
    for idx, toks in extras.items():
        mod = tamanos(cfg, f"us_module{idx}.syms.toml")
        for tok in toks:
            if ":" not in tok:
                continue
            a_str, s_str = tok.split(":", 1)
            a, want = int(a_str, 16), int(s_str, 16)
            for nombre, tabla in ((f"us_module{idx}.syms.toml", mod),
                                  ("us_combined.syms.toml", comb)):
                got = tabla.get(a) if tabla else None
                if got != want:
                    actual = f"0x{got:X}" if got is not None else "AUSENTE"
                    print(f"  ! {nombre}: {a:#x} size={actual} "
                          f"(override module_extras.json[{idx}] = 0x{want:X})")
                    fallos += 1
    if fallos:
        print(f"check_syms_overrides: {fallos} override(s) perdido(s). Esto revierte fixes "
              f"(p. ej. M9_FUN_802169ac -> stub do_break). Restaura el tamano en las .syms "
              f"o corrige el override; NO recompiles asi.")
        return 1
    print("check_syms_overrides: OK")
    return 0


if __name__ == "__main__":
    sys.exit(main())
