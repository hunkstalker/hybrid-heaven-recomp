#!/usr/bin/env python3
"""stats_watch_summary.py [hh_drwatch.log]

Resume el log de HH_DRWATCH (watchpoints de hardware del port, solo Windows)
centrado en las stats del personaje (struct 0x8017DC40). Para cada escritura
(cambio de valor) muestra que campo cambio (old -> new), el `ra` guest y el call
ring guest, y los agrupa por funcion escritora.

El buffer RDRAM va word-swapped: en cada palabra de 4 B vigilada, los 16 bits
altos son el u16 guest en la direccion base y los 16 bajos el u16 en base+2
(ambos big-endian, como los escribe la CPU MIPS). Ver docs/workflows.md 6.

Uso:
    python3 tools/analysis/stats_watch_summary.py build/windows/bin/Release/hh_drwatch.log
"""
import re
import sys
from collections import Counter, defaultdict

DR_RE = re.compile(
    r"^\[DR\] slot=(\d+) guest=([0-9A-Fa-f]+) old=([0-9A-Fa-f]+) new=([0-9A-Fa-f]+) "
    r"tid=(\d+) rip=exe\+0x([0-9A-Fa-f]+)"
)
CANARY_RE = re.compile(
    r"^\[CANARY\] vi=(\d+) guest=([0-9A-Fa-f]+) old=([0-9A-Fa-f]+) new=([0-9A-Fa-f]+)"
)
RA_RE = re.compile(r"guest ra=([0-9A-Fa-f]+) sp=([0-9A-Fa-f]+) s0=([0-9A-Fa-f]+)")
RING_RE = re.compile(r"tid=(-?\d+) sp=([0-9A-Fa-f]+) last:(.*)")
ADDR_RE = re.compile(r"func_([0-9A-Fa-f]{8})_")

# Palabras vigiladas conocidas (direccion guest base de 4 B -> nombres de sus 2 u16).
WORDS = {
    0x8017DC40: ("HP(+0x00)", "HPMAX(+0x02)"),
    0x8017DC44: ("+0x04", "+0x06"),
    0x8017DC48: ("STAMINA(+0x08)", "+0x0A"),
    0x8017DC50: ("OFF p0(+0x10)", "OFF p1(+0x12)"),
    0x8017DC54: ("OFF p2(+0x14)", "OFF p3(+0x16)"),
    0x8017DC58: ("OFF p4(+0x18)", "OFF p5(+0x1A)"),
    0x8017DC5C: ("DEF p0(+0x1C)", "DEF p1(+0x1E)"),
    0x8017DC60: ("DEF p2(+0x20)", "DEF p3(+0x22)"),
    0x8017DC64: ("DEF p4(+0x24)", "DEF p5(+0x26)"),
    0x8017DC80: ("OFFENSE(+0x40)", "DEFENSE(+0x42)"),
    0x8017DC84: ("SPEED(+0x44)", "REFLEX(+0x46)"),
    0x8017DC88: ("NIVEL(+0x48)", "+0x4A"),
    0x8017DC90: ("+0x50", "+0x52"),
    0x8017DC94: ("+0x54", "+0x56"),
    0x8017DC98: ("+0x58", "+0x5A"),
}


def load_funcs(path="build/recomp/RecompiledFuncs/funcs.h"):
    addrs = []
    try:
        with open(path, "r", errors="ignore") as f:
            for line in f:
                m = ADDR_RE.search(line)
                if m:
                    addrs.append((int(m.group(1), 16), "func_" + m.group(1) + "_"))
    except OSError:
        return []
    addrs.sort()
    return addrs


def func_at(addrs, guest):
    """Funcion que contiene `guest` (mayor inicio <= guest)."""
    if not addrs:
        return None
    lo, hi = 0, len(addrs) - 1
    best = None
    while lo <= hi:
        mid = (lo + hi) // 2
        if addrs[mid][0] <= guest:
            best = addrs[mid]
            lo = mid + 1
        else:
            hi = mid - 1
    # margen prudente (no forzar si esta en el hueco de otra funcion)
    if best and guest - best[0] <= 0x2000:
        return best
    return best


def u16_pair(v):
    return (v >> 16) & 0xFFFF, v & 0xFFFF


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else "hh_drwatch.log"
    try:
        lines = open(path, "r", errors="ignore").read().splitlines()
    except OSError as e:
        print(f"no puedo abrir {path}: {e}")
        return 1

    funcs = load_funcs()
    events = []
    i = 0
    while i < len(lines):
        m = DR_RE.match(lines[i]) or CANARY_RE.match(lines[i])
        if not m:
            i += 1
            continue
        # DR: slot guest old new tid rip / CANARY: vi guest old new -> group 2 = guest
        guest = int(m.group(2), 16)
        old = int(m.group(3), 16)
        new = int(m.group(4), 16)
        ra = sp = None
        ring = []
        j = i + 1
        while j < len(lines) and not (DR_RE.match(lines[j]) or CANARY_RE.match(lines[j])):
            r = RA_RE.search(lines[j])
            if r and ra is None:
                ra = int(r.group(1), 16)
                sp = int(r.group(2), 16)
            g = RING_RE.search(lines[j])
            if g:
                ring = [int(x, 16) for x in g.group(3).split()]
            j += 1
        events.append((guest, old, new, ra, sp, ring))
        i = j

    print(f"eventos (cambios de valor): {len(events)}")
    if not events:
        return 0

    per_field = Counter()
    per_writer = Counter()
    examples = defaultdict(list)

    for guest, old, new, ra, sp, ring in events:
        names = WORDS.get(guest)
        ol, oh = u16_pair(old)
        nl, nh = u16_pair(new)
        changed = []
        if ol != nl:
            changed.append((names[0] if names else f"+0x00", ol, nl))
        if oh != nh:
            changed.append((names[1] if names else f"+0x02", oh, nh))
        writer = func_at(funcs, ring[-1]) if ring else (func_at(funcs, ra) if ra else None)
        wname = writer[1].rstrip("_") if writer else (f"0x{ra:08X}" if ra else "?")
        for name, a, b in changed:
            per_field[name] += 1
            per_writer[wname] += 1
            if len(examples[(name, wname)]) < 3:
                examples[(name, wname)].append((guest, a, b, ra, sp, ring[-6:]))

    print("\n# cambios por campo")
    for name, n in per_field.most_common():
        print(f"  {name:20s} {n}")

    print("\n# escritores probable (ultimo target del call ring)")
    for name, n in per_writer.most_common():
        print(f"  {name:28s} {n}")

    print("\n# ejemplos por (campo, escritor)")
    for (name, wname), exs in sorted(examples.items()):
        print(f"\n== {name} <- {wname}")
        for guest, a, b, ra, sp, ring in exs:
            ring_s = " ".join(f"{x:08X}" for x in ring)
            ra_s = f"{ra:08X}" if ra is not None else "--------"
            sp_s = f"{sp:08X}" if sp is not None else "--------"
            print(f"   guest={guest:08X} {a} -> {b}  ra={ra_s} sp={sp_s}")
            print(f"      ring(last): {ring_s}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
