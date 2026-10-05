#!/usr/bin/env python3
"""Lee un log de camara escrito por el port bajo HH_CAM_LOG.

Una linea por frame (formato escrito en src/hooks/model_tagging.cpp):

    C frame=<n> ok=<0|1> eye=x,y,z at=x,y,z fwd=x,y,z v=x,y,z |v|=u a=x,y,z |a|=u dot=d cut=0|1 gen=g

Sirve para disenar/validar la deteccion de cortes de camara por DATOS. Un corte real es una
DISCONTINUIDAD del movimiento (|v| grande, o |a| = cambio de velocidad grande, o giro: dot bajo);
un paneo/elevador rapido pero sostenido tiene |v| alto pero |a| bajo (y dot alto) y NO deberia cortar.

    python3 tools/analysis/camera_log.py hh_cam.log
    python3 tools/analysis/camera_log.py hh_cam.log --cuts
"""

import argparse
import re
import sys

C = re.compile(
    r"^C frame=(\d+) ok=(\d+) eye=([-\d.]+),([-\d.]+),([-\d.]+) at=([-\d.]+),([-\d.]+),([-\d.]+) "
    r"fwd=([-\d.]+),([-\d.]+),([-\d.]+) v=([-\d.]+),([-\d.]+),([-\d.]+) \|v\|=([-\d.]+) "
    r"a=([-\d.]+),([-\d.]+),([-\d.]+) \|a\|=([-\d.]+) dot=([-\d.]+) cut=(\d) gen=(\d+)$")


def pct(v, p):
    if not v:
        return 0.0
    v = sorted(v)
    return v[min(len(v) - 1, max(0, int(round(p / 100.0 * (len(v) - 1)))))]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("log")
    ap.add_argument("--cuts", action="store_true", help="listar los frames con corte y sus magnitudes")
    args = ap.parse_args()

    frames = cuts = 0
    vs, accs, dots = [], [], []
    cut_rows = []
    with open(args.log, encoding="utf-8", errors="replace") as f:
        for ln in f:
            m = C.match(ln.rstrip())
            if not m:
                continue
            frames += 1
            fr = int(m.group(1))
            v = float(m.group(15))
            a = float(m.group(19))
            dot = float(m.group(20))
            cut = m.group(21) == "1"
            gen = int(m.group(22))
            vs.append(v)
            accs.append(a)
            dots.append(dot)
            if cut:
                cuts += 1
                cut_rows.append((fr, v, a, dot, gen))
    if frames == 0:
        sys.exit("no camera frames")

    print(f"{frames} frames con camara; {cuts} cortes ({100.0*cuts/frames:.2f}%)")
    print(f"|v| (velocidad/frame):  p50 {pct(vs,50):.1f}  p90 {pct(vs,90):.1f}  p99 {pct(vs,99):.1f}  max {max(vs):.1f}")
    print(f"|a| (cambio de vel):    p50 {pct(accs,50):.1f}  p90 {pct(accs,90):.1f}  p99 {pct(accs,99):.1f}  max {max(accs):.1f}")
    print(f"dot (fwd vs fwd prev):  p1  {pct(dots,1):.3f}  p10 {pct(dots,10):.3f}  p50 {pct(dots,50):.3f}")
    if cuts:
        print("\ncortes (frame, |v|, |a|, dot, gen):")
        shown = cut_rows if args.cuts else cut_rows[:30]
        for fr, v, a, dot, gen in shown:
            print(f"  f{fr:<7} |v|={v:8.1f}  |a|={a:8.1f}  dot={dot:6.3f}  gen={gen}")
        if not args.cuts and len(cut_rows) > 30:
            print(f"  ... ({len(cut_rows)} en total)")
        # Desglose: cortes por |v| (umbral distancia) vs por dot (giro) vs por |a| (discontinuidad).
        by_v = sum(1 for r in cut_rows if r[1] > 90.0)
        by_dot = sum(1 for r in cut_rows if r[3] < 0.0)
        print(f"\n  de los cortes: {by_v} con |v|>90 (por distancia), {by_dot} con dot<0 (por giro)")


if __name__ == "__main__":
    main()
