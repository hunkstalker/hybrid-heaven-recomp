#!/usr/bin/env python3
"""analyze_mqa.py — resume hh_mq_all.log (traza de colas con HH_MQLOG_ALL=1).

Uso:
    python3 tools/analysis/analyze_mqa.py hh_mq_all.log [--tail N] [--focus 8005C288]

Salida:
  - conteo de eventos por cola/operacion y por tid;
  - los ultimos N eventos de cada cola (por defecto 8);
  - para la cola de interes (por defecto la principal 0x8005C288): ultimos envios y recepciones;
  - eventos [EVT] (osSetEventMesg) para ver re-registros de VI/AI/DP;
  - deteccion del silencio: ultimo evento global y por tid (para localizar quien dejo de postear).
"""
import argparse
import re
from collections import Counter, defaultdict

MQA = re.compile(r'\[MQA\] t=([\d.]+) (\S+) tid=(-?\d+) mq=(\w+) msg=(\w+) valid=(\d+) recvHead=(\w+) sendHead=(\w+)')
EVT = re.compile(r'\[EVT\] event=(\d+) mq=(\w+) msg=(\w+)')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("log")
    ap.add_argument("--tail", type=int, default=8)
    ap.add_argument("--focus", default="8005C288")
    args = ap.parse_args()

    por_cola = Counter()
    por_tid = Counter()
    ultimos = defaultdict(list)
    evts = []
    ultimo_global = None
    ultimo_tid = {}
    n = 0
    focus = args.focus.lower()
    ult_send_focus = []
    for ln in open(args.log, errors="ignore"):
        m = MQA.search(ln)
        if m:
            t = float(m.group(1)); op = m.group(2); tid = int(m.group(3))
            mq = m.group(4).lower(); msg = m.group(5)
            por_cola[(mq, op)] += 1
            por_tid[tid] += 1
            ultimo_global = (t, op, tid, mq, msg)
            ultimo_tid[tid] = (t, op, mq, msg)
            ultimos[mq] = (ultimos[mq] + [(t, op, tid, msg)])[-args.tail:]
            if mq == focus and op == "send":
                ult_send_focus = (ult_send_focus + [(t, tid, msg, m.group(6))])[-args.tail:]
            n += 1
            continue
        e = EVT.search(ln)
        if e:
            evts.append(ln.strip())
            ultimo_global = ("evt", "EVT", -1, e.group(2), e.group(3))

    print(f"eventos MQA: {n}   [EVT]: {len(evts)}")
    print("\n=== por cola/op (top 15) ===")
    for (mq, op), k in por_cola.most_common(15):
        print(f"  {mq} {op}: {k}")
    print("\n=== por tid ===")
    for tid, k in por_tid.most_common():
        print(f"  tid {tid}: {k}   (ultimo: {ultimo_tid.get(tid)})")
    print(f"\n=== ultimos eventos de la cola {focus} (send) ===")
    for t, tid, msg, valid in ult_send_focus:
        print(f"  t={t:.3f} tid={tid} msg={msg} valid={valid}")
    print(f"\n=== ultimos eventos por cola ===")
    for mq, evs in sorted(ultimos.items()):
        print(f"  {mq}:")
        for t, op, tid, msg in evs:
            print(f"     t={t:.3f} {op} tid={tid} msg={msg}")
    print(f"\n=== [EVT] ({len(evts)}): primeros y ultimos ===")
    for ln in evts[:6]:
        print("  " + ln)
    if len(evts) > 12:
        print("  ...")
    for ln in evts[-6:]:
        print("  " + ln)
    print(f"\nultimo evento global: {ultimo_global}")


if __name__ == "__main__":
    main()
