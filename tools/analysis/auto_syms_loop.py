#!/usr/bin/env python3
"""auto_syms_loop.py — itera el ciclo descubrir→añadir→recompilar sin intervención.

Ejecuta el port headless con input inyectado (HH_PRESS_SEQ, pulsos de START) y
HH_SOFT_LOOKUP=1; recoge las direcciones de `Failed to find function at 0x...`,
las añade a la syms plana (add_missing_funcs), regenera el set combinado
(setup_module.py) y recompila (recomp.py --build). Repite hasta que un run no
encuentre direcciones nuevas (o hasta el máximo de iteraciones).

Uso: python3 tools/analysis/auto_syms_loop.py [max_iter]
Logs: work/debug/autosyms/iter_<n>.log
"""
import os
import re
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
BUILD = ROOT / "port/HybridHeavenRecomp/build_dbg"
BIN = BUILD / "Hybrid Heaven Recomp"
LOGDIR = ROOT / "work/debug/autosyms"
MISS_RE = re.compile(r"Failed to find function at 0x([0-9A-Fa-f]+)")
FLAT_LO, FLAT_HI = 0x80000400, 0x80000400 + 0x4E5B40
MODULE_EXTRAS_JSON = ROOT / "config/module_extras.json"


def module_ranges():
    """{indice: (lo, hi)} de los módulos, según el tamaño de su syms."""
    import importlib.util, tomllib
    spec = importlib.util.spec_from_file_location("setup_module", ROOT / "tools/setup_module.py")
    sm = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(sm)
    out = {}
    for mod in sm.MODULES:
        p = ROOT / f"config/us_module{mod['index']}.syms.toml"
        size = tomllib.loads(p.read_text())["section"][0]["size"]
        out[mod["index"]] = (mod["vram"], mod["vram"] + size)
    return out


def module_extras():
    import json
    if not MODULE_EXTRAS_JSON.exists():
        return {}
    return {int(k): {int(a, 16) for a in v} for k, v in json.loads(MODULE_EXTRAS_JSON.read_text()).items()}


def save_module_extras(d):
    import json
    MODULE_EXTRAS_JSON.write_text(
        json.dumps({str(k): [f"0x{a:08X}" for a in sorted(v)] for k, v in sorted(d.items())},
                   indent=2) + "\n")

RUN_SECS = 140
POLL_S = 1.5
HOLD_S = 0.4


def make_press_seq(end_s=135.0):
    items = []
    t = 55.0
    while t < end_s:
        items.append(f"{t:.1f}:start,{t + HOLD_S:.1f}:-")
        t += POLL_S
    return ",".join(items)


def run_port(log_path: Path) -> int:
    env = dict(os.environ)
    env.update({
        "DISPLAY": ":99",
        "SDL_VIDEODRIVER": "x11",
        "VK_ICD_FILENAMES": "/usr/share/vulkan/icd.d/lvp_icd.x86_64.json",
        "HH_SOFT_LOOKUP": "1",
        "HH_PRESS_SEQ": make_press_seq(),
    })
    with log_path.open("wb") as log:
        proc = subprocess.run(["timeout", str(RUN_SECS), str(BIN)], env=env,
                              stdout=log, stderr=subprocess.STDOUT, cwd=BUILD)
    return proc.returncode


def flat_starts():
    import tomllib
    d = tomllib.loads((ROOT / "config/us_ghidra.syms.toml").read_text())
    return {f["vram"] for s in d["section"] for f in s["functions"]}


def classify(new, ranges):
    """Separa direcciones planas de las de módulos. Devuelve (flat, {idx: set})."""
    flat = set()
    mods = {}
    for a in new:
        for idx, (lo, hi) in ranges.items():
            if lo <= a < hi:
                mods.setdefault(idx, set()).add(a)
                break
        else:
            flat.add(a)
    return flat, mods


def main() -> int:
    max_iter = int(sys.argv[1]) if len(sys.argv) > 1 else 12
    LOGDIR.mkdir(parents=True, exist_ok=True)
    added_total = set()

    for it in range(1, max_iter + 1):
        log_path = LOGDIR / f"iter_{it}.log"
        print(f"[auto] iter {it}: run ({RUN_SECS}s)...", flush=True)
        rc = run_port(log_path)
        text = log_path.read_text(errors="replace")

        if "Switch-case out of bounds" in text:
            print(f"[auto] STOP: switch roto en {log_path}", flush=True)
            return 2

        misses = {int(m, 16) for m in MISS_RE.findall(text)}
        known = flat_starts()
        ranges = module_ranges()
        extras = module_extras()
        for idx, addrs in extras.items():
            known |= addrs
        new = {a for a in misses if a not in known}

        print(f"[auto] rc={rc} misses={len(misses)} nuevas={len(new)}"
              + (" " + ", ".join(f"0x{a:08X}" for a in sorted(new)) if new else ""),
              flush=True)
        if not new:
            print("[auto] sin direcciones nuevas: fin", flush=True)
            return 0
        if new <= added_total:
            print("[auto] STOP: sin progreso (mismas direcciones que la iteración previa)",
                  flush=True)
            return 4
        added_total |= new

        flat, mods = classify(new, ranges)
        if flat:
            synth = LOGDIR / f"miss_{it}.log"
            synth.write_text("".join(f"Failed to find function at 0x{a:08X}\n"
                                     for a in sorted(flat)))
            print(f"[auto] $ add_missing_funcs ({len(flat)})", flush=True)
            r = subprocess.run([sys.executable, "tools/analysis/add_missing_funcs.py",
                                "--syms", "config/us_ghidra.syms.toml", "--log", str(synth)],
                               cwd=ROOT)
            if r.returncode != 0:
                print("[auto] STOP: falló add_missing_funcs", flush=True)
                return 5
        if mods:
            for idx, addrs in mods.items():
                extras.setdefault(idx, set()).update(addrs)
            save_module_extras(extras)
            print("[auto] extras de módulo -> config/module_extras.json: "
                  + ", ".join(f"idx{k}={len(v)}" for k, v in sorted(extras.items())), flush=True)

        for cmd in ([sys.executable, "tools/setup_module.py"],
                    [sys.executable, "tools/recomp.py",
                     "--config", "config/game_combined.toml", "--build"]):
            print(f"[auto] $ {' '.join(cmd)}", flush=True)
            r = subprocess.run(cmd, cwd=ROOT)
            if r.returncode != 0:
                print(f"[auto] STOP: falló {' '.join(cmd)} (rc={r.returncode})", flush=True)
                return 5
        time.sleep(1.0)

    print("[auto] máximo de iteraciones alcanzado", flush=True)
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
