#!/usr/bin/env python3
"""Convierte el replay.log de BizHawk (tracker v3) al formato de replay del port.

Entrada (una linea por frame, de tools/analysis/bizhawk_hh_tracker_v3.lua):
    <frame> <buttons_hex N64 crudo> <stick_x> <stick_y>
Salida (formato del port, ver src/game/input.cpp :: hh_replay_data):
    <t_segundos> <vis> <buttons_hex> <x> <y>     (x,y normalizados a [-1,1])

Uso:
    python3 tools/analysis/bizhawk_to_replay.py replay.log hh_replay_bizhawk.txt \
        [--vis-offset N] [--scale 128] [--invert-y] [--quiet]

Notas:
    - vis = frame + vis-offset (BizHawk cuenta VI desde power-on igual que el port; el offset
      sirve para corregir un desfase de arranque si la muestra corta lo revela).
    - El stick de BizHawk (N64) va en [-128,127]; se divide por --scale y se acota a [-1,1].
      Con --invert-y se niega la Y (misma convencion de signo que HH_INVERT_Y del port).
    - Los frames que falten se rellenan repitiendo el ultimo estado (monotonico).
"""
import argparse
import sys
from collections import Counter


def parse_log(path):
    samples = {}
    with open(path, "r", errors="replace") as fh:
        for raw in fh:
            line = raw.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split()
            if len(parts) < 4:
                continue
            try:
                frame = int(parts[0])
                buttons = int(parts[1], 16)
                x = float(parts[2])
                y = float(parts[3])
            except ValueError:
                continue
            samples[frame] = (buttons, x, y)
    return samples


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("entrada")
    ap.add_argument("salida")
    ap.add_argument("--vis-offset", type=int, default=0)
    ap.add_argument("--scale", type=float, default=128.0)
    ap.add_argument("--invert-y", action="store_true")
    ap.add_argument("--quiet", action="store_true")
    args = ap.parse_args()

    samples = parse_log(args.entrada)
    if not samples:
        print("ERROR: no hay muestras validas en", args.entrada, file=sys.stderr)
        return 1

    frames = sorted(samples)
    if frames[0] != 0:
        # Arranque tardio: replicar el primer estado hacia atras hasta el frame 0.
        for f in range(0, frames[0]):
            samples[f] = samples[frames[0]]
        frames = sorted(samples)

    buttons_count = Counter()
    minx = miny = 10.0
    maxx = maxy = -10.0
    last = samples[frames[0]]
    written = 0
    with open(args.salida, "w") as out:
        for f in range(frames[0], frames[-1] + 1):
            if f in samples:
                last = samples[f]
            buttons, x, y = last
            if args.invert_y:
                y = -y
            nx = max(-1.0, min(1.0, x / args.scale))
            ny = max(-1.0, min(1.0, y / args.scale))
            minx, maxx = min(minx, nx), max(maxx, nx)
            miny, maxy = min(miny, ny), max(maxy, ny)
            buttons_count[buttons] += 1
            vis = f + args.vis_offset
            out.write(f"{vis / 60.0:.4f} {vis} {buttons:04X} {nx:.4f} {ny:.4f}\n")
            written += 1

    if not args.quiet:
        dur = (frames[-1] - frames[0]) / 60.0
        print(f"muestras: {len(samples)} frames: {frames[0]}..{frames[-1]} ({dur:.1f}s) "
              f"-> {written} lineas en {args.salida}")
        print(f"stick x: [{minx:.3f},{maxx:.3f}]  y: [{miny:.3f},{maxy:.3f}]")
        print("botones (top): " + ", ".join(
            f"{m:04X}x{n}" for m, n in buttons_count.most_common(6)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
